/*
 *    Stack-less Just-In-Time compiler
 *
 *    Copyright 2009-2010 Zoltan Herczeg (hzmester@freemail.hu). All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are
 * permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice, this list of
 *      conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright notice, this list
 *      of conditions and the following disclaimer in the documentation and/or other materials
 *      provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER(S) AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDER(S) OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

SLJIT_API_FUNC_ATTRIBUTE SLJIT_CONST char* sljit_get_platform_name()
{
	return "arm-thumb2";
}

/* Last register + 1. */
#define TMP_REG1	(SLJIT_NO_REGISTERS + 1)
#define TMP_REG2	(SLJIT_NO_REGISTERS + 2)
#define TMP_REG3	(SLJIT_NO_REGISTERS + 3)
#define TMP_PC		(SLJIT_NO_REGISTERS + 4)

#define TMP_FREG1	(SLJIT_FLOAT_REG4 + 1)
#define TMP_FREG2	(SLJIT_FLOAT_REG4 + 2)

/* See sljit_emit_enter if you want to change them. */
static SLJIT_CONST sljit_ub reg_map[SLJIT_NO_REGISTERS + 5] = {
  0, 0, 1, 2, 12, 5, 6, 7, 8, 10, 11, 13, 3, 4, 14, 15
};

#define COPY_BITS(src, from, to, bits) \
	((from >= to ? (src >> (from - to)) : (src << (to - from))) & (((1 << bits) - 1) << to))

/* Thumb16 encodings. */
#define RD3(rd) (reg_map[rd])
#define RN3(rn) (reg_map[rn] << 3)
#define RM3(rm) (reg_map[rm] << 6)
#define RDN3(rdn) (reg_map[rdn] << 8)
#define IMM3(imm) (imm << 6)
#define IMM8(imm) (imm)

/* Thumb16 helpers. */
#define SET_REGS44(rd, rn) \
	((reg_map[rn] << 3) | (reg_map[rd] & 0x7) | ((reg_map[rd] & 0x8) << 4))
#define IS_2_LO_REGS(reg1, reg2) \
	(reg_map[reg1] <= 7 && reg_map[reg2] <= 7)
#define IS_3_LO_REGS(reg1, reg2, reg3) \
	(reg_map[reg1] <= 7 && reg_map[reg2] <= 7 && reg_map[reg3] <= 7)

/* Thumb32 encodings. */
#define RD4(rd) (reg_map[rd] << 8)
#define RN4(rn) (reg_map[rn] << 16)
#define RM4(rm) (reg_map[rm])
#define RT4(rt) (reg_map[rt] << 12)
#define DD4(dd) ((dd) << 12)
#define DN4(dn) ((dn) << 16)
#define DM4(dm) (dm)
#define IMM5(imm) \
	(COPY_BITS(imm, 2, 12, 3) | ((imm & 0x3) << 6))
#define IMM12(imm) \
	(COPY_BITS(imm, 11, 26, 1) | COPY_BITS(imm, 8, 12, 3) | (imm & 0xff))

typedef sljit_ui sljit_ins;

/* --------------------------------------------------------------------- */
/*  Instrucion forms                                                     */
/* --------------------------------------------------------------------- */

/* dot '.' changed to _
   I immediate form (possibly followed by number of immediate bits). */
#define ADCI		0xf1400000
#define ADCS		0x4140
#define ADC_W		0xeb400000
#define ADD		0x4400
#define ADDS		0x1800
#define ADDSI3		0x1c00
#define ADDSI8		0x3000
#define ADD_W		0xeb000000
#define ADDWI		0xf2000000
#define ADD_SP		0xb000
#define ADD_W		0xeb000000
#define ADD_WI		0xf1000000
#define ANDI		0xf0000000
#define ANDS		0x4000
#define AND_W		0xea000000
#define ASRS		0x4100
#define ASRSI		0x1000
#define ASR_W		0xfa40f000
#define ASR_WI		0xea4f0020
#define BICI		0xf0200000
#define BKPT		0xbe00
#define BLX		0x4780
#define BX		0x4700
#define CLZ		0xfab0f080
#define CMPI		0x2800
#define CMP_W		0xebb00f00
#define EORI		0xf0800000
#define EORS		0x4040
#define EOR_W		0xea800000
#define IT		0xbf00
#define LSLS		0x4080
#define LSLSI		0x0000
#define LSL_W		0xfa00f000
#define LSL_WI		0xea4f0000
#define LSRS		0x40c0
#define LSRSI		0x0800
#define LSR_W		0xfa20f000
#define LSR_WI		0xea4f0010
#define MOV		0x4600
#define MOVSI		0x2000
#define MOVT		0xf2c00000
#define MOVW		0xf2400000
#define MOV_WI		0xf04f0000
#define MUL		0xfb00f000
#define MVNS		0x43c0
#define MVN_W		0xea6f0000
#define MVN_WI		0xf06f0000
#define NOP		0xbf00
#define ORNI		0xf0600000
#define ORRI		0xf0400000
#define ORRS		0x4300
#define ORR_W		0xea400000
#define POP		0xbd00
#define POP_W		0xe8bd0000
#define PUSH		0xb500
#define PUSH_W		0xe92d0000
#define RSB_WI		0xf1c00000
#define RSBSI		0x4240
#define SBCI		0xf1600000
#define SBCS		0x4180
#define SBC_W		0xeb600000
#define SMULL		0xfb800000
#define STR_SP		0x9000
#define SUBS		0x1a00
#define SUBSI3		0x1e00
#define SUBSI8		0x3800
#define SUB_W		0xeba00000
#define SUBWI		0xf2a00000
#define SUB_SP		0xb080
#define SUB_WI		0xf1a00000
#define SXTB		0xb240
#define SXTB_W		0xfa4ff080
#define SXTH		0xb200
#define SXTH_W		0xfa0ff080
#define TST		0x4200
#define UXTB		0xb2c0
#define UXTB_W		0xfa5ff080
#define UXTH		0xb280
#define UXTH_W		0xfa1ff080
#define VABS_F64	0xeeb00bc0
#define VADD_F64	0xee300b00
#define VCMP_F64	0xeeb40b40
#define VDIV_F64	0xee800b00
#define VMOV_F64	0xeeb00b40
#define VMRS		0xeef1fa10
#define VMUL_F64	0xee200b00
#define VNEG_F64	0xeeb10b40
#define VSTR		0xed000b00
#define VSUB_F64	0xee300b40

static int push_inst16(struct sljit_compiler *compiler, sljit_ins inst)
{
	sljit_uh *ptr;
	SLJIT_ASSERT(!(inst & 0xffff0000));

	ptr = (sljit_uh*)ensure_buf(compiler, sizeof(sljit_uh));
	FAIL_IF(!ptr);
	*ptr = inst;
	compiler->size++;
	return SLJIT_SUCCESS;
}

static int push_inst32(struct sljit_compiler *compiler, sljit_ins inst)
{
	sljit_uh *ptr = (sljit_uh*)ensure_buf(compiler, sizeof(sljit_ins));
	FAIL_IF(!ptr);
	*ptr++ = inst >> 16;
	*ptr = inst;
	compiler->size += 2;
	return SLJIT_SUCCESS;
}

static SLJIT_INLINE int emit_imm32_const(struct sljit_compiler *compiler, int dst, sljit_uw imm)
{
	FAIL_IF(push_inst32(compiler, MOVW | RD4(dst) |
		COPY_BITS(imm, 12, 16, 4) | COPY_BITS(imm, 11, 26, 1) | COPY_BITS(imm, 8, 12, 3) | (imm & 0xff)));
	return push_inst32(compiler, MOVT | RD4(dst) |
		COPY_BITS(imm, 12 + 16, 16, 4) | COPY_BITS(imm, 11 + 16, 26, 1) | COPY_BITS(imm, 8 + 16, 12, 3) | ((imm & 0xff0000) >> 16));
}

static SLJIT_INLINE void modify_imm32_const(sljit_uh* inst, sljit_uw new_imm)
{
	int dst = inst[1] & 0x0f00;
	SLJIT_ASSERT(((inst[0] & 0xfbf0) == (MOVW >> 16)) && ((inst[2] & 0xfbf0) == (MOVT >> 16)) && dst == (inst[3] & 0x0f00));
	inst[0] = (MOVW >> 16) | COPY_BITS(new_imm, 12, 0, 4) | COPY_BITS(new_imm, 11, 10, 1);
	inst[1] = dst | COPY_BITS(new_imm, 8, 12, 3) | (new_imm & 0xff);
	inst[2] = (MOVT >> 16) | COPY_BITS(new_imm, 12 + 16, 0, 4) | COPY_BITS(new_imm, 11 + 16, 10, 1);
	inst[3] = dst | COPY_BITS(new_imm, 8 + 16, 12, 3) | ((new_imm & 0xff0000) >> 16);
}

static SLJIT_INLINE int detect_jump_type(struct sljit_jump *jump, sljit_uh *code_ptr, sljit_uh *code)
{
	sljit_w diff;

	if (jump->flags & SLJIT_REWRITABLE_JUMP)
		return 0;

	if (jump->flags & JUMP_ADDR) {
		/* Branch to ARM code is not optimized yet. */
		if (!(jump->u.target & 0x1))
			return 0;
		diff = ((sljit_w)jump->u.target - (sljit_w)(code_ptr + 2)) >> 1;
	}
	else {
		SLJIT_ASSERT(jump->flags & JUMP_LABEL);
		diff = ((sljit_w)(code + jump->u.label->size) - (sljit_w)(code_ptr + 2)) >> 1;
	}

	if (jump->flags & IS_CONDITIONAL) {
		SLJIT_ASSERT(!(jump->flags & IS_BL));
		if (diff <= 127 && diff >= -128) {
			jump->flags |= B_TYPE1;
			return 5;
		}
		if (diff <= 524287 && diff >= -524288) {
			jump->flags |= B_TYPE2;
			return 4;
		}
		/* +1 comes from the prefix IT instruction. */
		diff--;
		if (diff <= 8388607 && diff >= -8388608) {
			jump->flags |= B_TYPE3;
			return 3;
		}
	}
	else if (jump->flags & IS_BL) {
		if (diff <= 8388607 && diff >= -8388608) {
			jump->flags |= BL_TYPE6;
			return 3;
		}
	}
	else {
		if (diff <= 1023 && diff >= -1024) {
			jump->flags |= B_TYPE4;
			return 4;
		}
		if (diff <= 8388607 && diff >= -8388608) {
			jump->flags |= B_TYPE5;
			return 3;
		}
	}

	return 0;
}

static SLJIT_INLINE void inline_set_jump_addr(sljit_uw addr, sljit_uw new_addr, int flush)
{
	sljit_uh* inst = (sljit_uh*)addr;
	modify_imm32_const(inst, new_addr);
	if (flush) {
		SLJIT_CACHE_FLUSH(inst, inst + 3);
	}
}

static SLJIT_INLINE void set_jump_instruction(struct sljit_jump *jump)
{
	int type = (jump->flags >> 4) & 0xf;
	sljit_w diff;
	sljit_uh *jump_inst;
	int s, j1, j2;

	if (SLJIT_UNLIKELY(type == 0)) {
		inline_set_jump_addr(jump->addr, (jump->flags & JUMP_LABEL) ? jump->u.label->addr : jump->u.target, 0);
		return;
	}

	if (jump->flags & JUMP_ADDR) {
		SLJIT_ASSERT(jump->u.target & 0x1);
		diff = ((sljit_w)jump->u.target - (sljit_w)(jump->addr + 4)) >> 1;
	}
	else
		diff = ((sljit_w)(jump->u.label->addr) - (sljit_w)(jump->addr + 4)) >> 1;
	jump_inst = (sljit_uh*)jump->addr;

	switch (type) {
	case 1:
		/* Encoding T1 of 'B' instruction */
		SLJIT_ASSERT(diff <= 127 && diff >= -128 && (jump->flags & IS_CONDITIONAL));
		jump_inst[0] = 0xd000 | (jump->flags & 0xf00) | (diff & 0xff);
		return;
	case 2:
		/* Encoding T3 of 'B' instruction */
		SLJIT_ASSERT(diff <= 524287 && diff >= -524288 && (jump->flags & IS_CONDITIONAL));
		jump_inst[0] = 0xf000 | COPY_BITS(jump->flags, 8, 6, 4) | COPY_BITS(diff, 11, 0, 6) | COPY_BITS(diff, 19, 10, 1);
		jump_inst[1] = 0x8000 | COPY_BITS(diff, 17, 13, 1) | COPY_BITS(diff, 18, 11, 1) | (diff & 0x7ff);
		return;
	case 3:
		SLJIT_ASSERT(jump->flags & IS_CONDITIONAL);
		*jump_inst++ = IT | ((jump->flags >> 4) & 0xf0) | 0x8;
		diff--;
		type = 5;
		break;
	case 4:
		/* Encoding T2 of 'B' instruction */
		SLJIT_ASSERT(diff <= 1023 && diff >= -1024 && !(jump->flags & IS_CONDITIONAL));
		jump_inst[0] = 0xe000 | (diff & 0x7ff);
		return;
	}

	SLJIT_ASSERT(diff <= 8388607 && diff >= -8388608);

	/* Really complex instruction form for branches. */
	s = (diff >> 23) & 0x1;
	j1 = (~(diff >> 21) ^ s) & 0x1;
	j2 = (~(diff >> 22) ^ s) & 0x1;
	jump_inst[0] = 0xf000 | (s << 10) | COPY_BITS(diff, 11, 0, 10);
	jump_inst[1] = (j1 << 13) | (j2 << 11) | (diff & 0x7ff);

	/* The others have a common form. */
	if (type == 5) /* Encoding T4 of 'B' instruction */
		jump_inst[1] |= 0x9000;
	else if (type == 6) /* Encoding T1 of 'BL' instruction */
		jump_inst[1] |= 0xd000;
	else
		SLJIT_ASSERT_STOP();
}

SLJIT_API_FUNC_ATTRIBUTE void* sljit_generate_code(struct sljit_compiler *compiler)
{
	struct sljit_memory_fragment *buf;
	sljit_uh *code;
	sljit_uh *code_ptr;
	sljit_uh *buf_ptr;
	sljit_uh *buf_end;
	sljit_uw half_count;

	struct sljit_label *label;
	struct sljit_jump *jump;
	struct sljit_const *const_;

	CHECK_ERROR_PTR();
	check_sljit_generate_code(compiler);
	reverse_buf(compiler);

	code = (sljit_uh*)SLJIT_MALLOC_EXEC(compiler->size * sizeof(sljit_uh));
	PTR_FAIL_WITH_EXEC_IF(code);
	buf = compiler->buf;

	code_ptr = code;
	half_count = 0;
	label = compiler->labels;
	jump = compiler->jumps;
	const_ = compiler->consts;

	do {
		buf_ptr = (sljit_uh*)buf->memory;
		buf_end = buf_ptr + (buf->used_size >> 1);
		do {
			*code_ptr = *buf_ptr++;
			/* These structures are ordered by their address. */
			SLJIT_ASSERT(!label || label->size >= half_count);
			SLJIT_ASSERT(!jump || jump->addr >= half_count);
			SLJIT_ASSERT(!const_ || const_->addr >= half_count);
			if (label && label->size == half_count) {
				label->addr = ((sljit_uw)code_ptr) | 0x1;
				label->size = code_ptr - code;
				label = label->next;
			}
			if (jump && jump->addr == half_count) {
					jump->addr = (sljit_uw)code_ptr - ((jump->flags & IS_CONDITIONAL) ? 10 : 8);
					code_ptr -= detect_jump_type(jump, code_ptr, code);
					jump = jump->next;
			}
			if (const_ && const_->addr == half_count) {
				const_->addr = (sljit_uw)code_ptr;
				const_ = const_->next;
			}
			code_ptr ++;
			half_count ++;
		} while (buf_ptr < buf_end);

		buf = buf->next;
	} while (buf);

	if (label && label->size == half_count) {
		label->addr = ((sljit_uw)code_ptr) | 0x1;
		label->size = code_ptr - code;
		label = label->next;
	}

	SLJIT_ASSERT(!label);
	SLJIT_ASSERT(!jump);
	SLJIT_ASSERT(!const_);
	SLJIT_ASSERT(code_ptr - code <= (int)compiler->size);

	jump = compiler->jumps;
	while (jump) {
		set_jump_instruction(jump);
		jump = jump->next;
	}

	SLJIT_CACHE_FLUSH(code, code_ptr);
	compiler->error = SLJIT_ERR_COMPILED;
	compiler->executable_size = compiler->size * sizeof(sljit_uh);
	/* Set thumb mode flag. */
	return (void*)((sljit_uw)code | 0x1);
}

#define INVALID_IMM	0x80000000
static sljit_uw get_imm(sljit_uw imm)
{
	/* Thumb immediate form. */
	int counter;

	if (imm <= 0xff)
		return imm;

	if ((imm & 0xffff) == (imm >> 16)) {
		/* Some special cases. */
		if (!(imm & 0xff00))
			return (1 << 12) | (imm & 0xff);
		if (!(imm & 0xff))
			return (2 << 12) | ((imm >> 8) & 0xff);
		if ((imm & 0xff00) == ((imm & 0xff) << 8))
			return (3 << 12) | (imm & 0xff);
	}

	/* Assembly optimization: count leading zeroes? */
	counter = 8;
	if (!(imm & 0xffff0000)) {
		counter += 16;
		imm <<= 16;
	}
	if (!(imm & 0xff000000)) {
		counter += 8;
		imm <<= 8;
	}
	if (!(imm & 0xf0000000)) {
		counter += 4;
		imm <<= 4;
	}
	if (!(imm & 0xc0000000)) {
		counter += 2;
		imm <<= 2;
	}
	if (!(imm & 0x80000000)) {
		counter += 1;
		imm <<= 1;
	}
	/* Since imm >= 128, this must be true. */
	SLJIT_ASSERT(counter <= 31);

	if (imm & 0x00ffffff)
		return INVALID_IMM; /* Cannot be encoded. */

	return ((imm >> 24) & 0x7f) | COPY_BITS(counter, 4, 26, 1) | COPY_BITS(counter, 1, 12, 3) | COPY_BITS(counter, 0, 7, 1);
}

static int load_immediate(struct sljit_compiler *compiler, int dst, sljit_uw imm)
{
	sljit_uw tmp;

	if (imm >= 0x10000) {
		tmp = get_imm(imm);
		if (tmp != INVALID_IMM)
			return push_inst32(compiler, MOV_WI | RD4(dst) | tmp);
		tmp = get_imm(~imm);
		if (tmp != INVALID_IMM)
			return push_inst32(compiler, MVN_WI | RD4(dst) | tmp);
	}

	/* set low 16 bits, set hi 16 bits to 0. */
	FAIL_IF(push_inst32(compiler, MOVW | RD4(dst) |
		COPY_BITS(imm, 12, 16, 4) | COPY_BITS(imm, 11, 26, 1) | COPY_BITS(imm, 8, 12, 3) | (imm & 0xff)));

	/* set hi 16 bit if needed. */
	if (imm >= 0x10000)
		return push_inst32(compiler, MOVT | RD4(dst) |
			COPY_BITS(imm, 12 + 16, 16, 4) | COPY_BITS(imm, 11 + 16, 26, 1) | COPY_BITS(imm, 8 + 16, 12, 3) | ((imm & 0xff0000) >> 16));
	return SLJIT_SUCCESS;
}

#define ARG1_IMM	0x0010000
#define ARG2_IMM	0x0020000
#define KEEP_FLAGS	0x0040000
#define SET_MULOV	0x0080000
/* SET_FLAGS must be 0x100000 as it is also the value of S bit (can be used for optimization). */
#define SET_FLAGS	0x0100000
#define UNUSED_RETURN	0x0200000
#define SLOW_DEST	0x0400000
#define SLOW_SRC1	0x0800000
#define SLOW_SRC2	0x1000000

static int emit_op_imm(struct sljit_compiler *compiler, int flags, int dst, sljit_uw arg1, sljit_uw arg2)
{
	/* dst must be register, TMP_REG1
	   arg1 must be register, TMP_REG1, imm
	   arg2 must be register, TMP_REG2, imm */
	int reg;
	sljit_uw imm;

	if (SLJIT_UNLIKELY((flags & (ARG1_IMM | ARG2_IMM)) == (ARG1_IMM | ARG2_IMM))) {
		/* Both are immediates. */
		flags &= ~ARG1_IMM;
		FAIL_IF(load_immediate(compiler, TMP_REG1, arg1));
		arg1 = TMP_REG1;
	}

	if (flags & (ARG1_IMM | ARG2_IMM)) {
		reg = (flags & ARG2_IMM) ? arg1 : arg2;
		imm = (flags & ARG2_IMM) ? arg2 : arg1;

		switch (flags & 0xffff) {
		case SLJIT_MOV:
			SLJIT_ASSERT(!(flags & SET_FLAGS) && (flags & ARG2_IMM) && arg1 == TMP_REG1);
			return load_immediate(compiler, dst, imm);
		case SLJIT_NOT:
			if (!(flags & SET_FLAGS))
				return load_immediate(compiler, dst, ~imm);
			/* Since the flags should be set, we just fallback to the register mode.
			   Although I could do some clever things here, "NOT IMM" does not worth the efforts. */
			break;
		case SLJIT_CLZ:
			/* No form with immediate operand. */
			break;
		case SLJIT_ADD:
			if (!(flags & KEEP_FLAGS) && IS_2_LO_REGS(reg, dst)) {
				if (imm <= 0x7)
					return push_inst16(compiler, ADDSI3 | IMM3(imm) | RD3(dst) | RN3(reg));
				if (reg == dst && imm <= 0xff)
					return push_inst16(compiler, ADDSI8 | IMM8(imm) | RDN3(dst));
			}
			if (imm <= 0xfff && !(flags & SET_FLAGS))
				return push_inst32(compiler, ADDWI | RD4(dst) | RN4(reg) | IMM12(imm));
			imm = get_imm(imm);
			if (imm != INVALID_IMM)
				return push_inst32(compiler, ADD_WI | (flags & SET_FLAGS) | RD4(dst) | RN4(reg) | imm);
			break;
		case SLJIT_ADDC:
			imm = get_imm(imm);
			if (imm != INVALID_IMM)
				return push_inst32(compiler, ADCI | (flags & SET_FLAGS) | RD4(dst) | RN4(reg) | imm);
			break;
		case SLJIT_SUB:
			if (flags & ARG2_IMM) {
				if (!(flags & KEEP_FLAGS) && IS_2_LO_REGS(reg, dst)) {
					if (imm <= 0x7)
						return push_inst16(compiler, SUBSI3 | IMM3(imm) | RD3(dst) | RN3(reg));
					if (imm <= 0xff) {
						if (reg == dst)
							return push_inst16(compiler, SUBSI8 | IMM8(imm) | RDN3(dst));
						if (flags & UNUSED_RETURN)
							return push_inst16(compiler, CMPI | IMM8(imm) | RDN3(reg));
					}
				}
				if (imm <= 0xfff && !(flags & SET_FLAGS))
					return push_inst32(compiler, SUBWI | RD4(dst) | RN4(reg) | IMM12(imm));
				imm = get_imm(imm);
				if (imm != INVALID_IMM)
					return push_inst32(compiler, SUB_WI | (flags & SET_FLAGS) | RD4(dst) | RN4(reg) | imm);
			}
			else {
				if (!(flags & KEEP_FLAGS) && imm == 0 && IS_2_LO_REGS(reg, dst))
					return push_inst16(compiler, RSBSI | RD3(dst) | RN3(reg));
				imm = get_imm(imm);
				if (imm != INVALID_IMM)
					return push_inst32(compiler, RSB_WI | (flags & SET_FLAGS) | RD4(dst) | RN4(reg) | imm);
			}
			break;
		case SLJIT_SUBC:
			if (flags & ARG2_IMM) {
				imm = get_imm(imm);
				if (imm != INVALID_IMM)
					return push_inst32(compiler, SBCI | (flags & SET_FLAGS) | RD4(dst) | RN4(reg) | imm);
			}
			break;
		case SLJIT_MUL:
			/* No form with immediate operand. */
			break;
		case SLJIT_AND:
			imm = get_imm(imm);
			if (imm != INVALID_IMM)
				return push_inst32(compiler, ANDI | (flags & SET_FLAGS) | RD4(dst) | RN4(reg) | imm);
			imm = get_imm(~((flags & ARG2_IMM) ? arg2 : arg1));
			if (imm != INVALID_IMM)
				return push_inst32(compiler, BICI | (flags & SET_FLAGS) | RD4(dst) | RN4(reg) | imm);
			break;
		case SLJIT_OR:
			imm = get_imm(imm);
			if (imm != INVALID_IMM)
				return push_inst32(compiler, ORRI | (flags & SET_FLAGS) | RD4(dst) | RN4(reg) | imm);
			imm = get_imm(~((flags & ARG2_IMM) ? arg2 : arg1));
			if (imm != INVALID_IMM)
				return push_inst32(compiler, ORNI | (flags & SET_FLAGS) | RD4(dst) | RN4(reg) | imm);
			break;
		case SLJIT_XOR:
			imm = get_imm(imm);
			if (imm != INVALID_IMM)
				return push_inst32(compiler, EORI | (flags & SET_FLAGS) | RD4(dst) | RN4(reg) | imm);
			break;
		case SLJIT_SHL:
			if (flags & ARG2_IMM) {
				imm &= 0x1f;
				if (!(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, reg))
					return push_inst16(compiler, LSLSI | RD3(dst) | RN3(reg) | (imm << 6));
				return push_inst32(compiler, LSL_WI | (flags & SET_FLAGS) | RD4(dst) | RM4(reg) | IMM5(imm));
			}
			break;
		case SLJIT_LSHR:
			if (flags & ARG2_IMM) {
				imm &= 0x1f;
				if (!(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, reg))
					return push_inst16(compiler, LSRSI | RD3(dst) | RN3(reg) | (imm << 6));
				return push_inst32(compiler, LSR_WI | (flags & SET_FLAGS) | RD4(dst) | RM4(reg) | IMM5(imm));
			}
			break;
		case SLJIT_ASHR:
			if (flags & ARG2_IMM) {
				imm &= 0x1f;
				if (!(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, reg))
					return push_inst16(compiler, ASRSI | RD3(dst) | RN3(reg) | (imm << 6));
				return push_inst32(compiler, ASR_WI | (flags & SET_FLAGS) | RD4(dst) | RM4(reg) | IMM5(imm));
			}
			break;
		default:
			SLJIT_ASSERT_STOP();
			break;
		}

		if (flags & ARG2_IMM) {
			FAIL_IF(load_immediate(compiler, TMP_REG2, arg2));
			arg2 = TMP_REG2;
		}
		else {
			FAIL_IF(load_immediate(compiler, TMP_REG1, arg1));
			arg1 = TMP_REG1;
		}
	}

	/* Both arguments are registers. */
	switch (flags & 0xffff) {
	case SLJIT_MOV:
	case SLJIT_MOV_UI:
	case SLJIT_MOV_SI:
	case SLJIT_MOVU:
	case SLJIT_MOVU_UI:
	case SLJIT_MOVU_SI:
		SLJIT_ASSERT(!(flags & SET_FLAGS) && arg1 == TMP_REG1);
		return push_inst16(compiler, MOV | SET_REGS44(dst, arg2));
	case SLJIT_MOV_UB:
	case SLJIT_MOVU_UB:
		SLJIT_ASSERT(!(flags & SET_FLAGS) && arg1 == TMP_REG1);
		if (IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, UXTB | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, UXTB_W | RD4(dst) | RM4(arg2));
	case SLJIT_MOV_SB:
	case SLJIT_MOVU_SB:
		SLJIT_ASSERT(!(flags & SET_FLAGS) && arg1 == TMP_REG1);
		if (IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, SXTB | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, SXTB_W | RD4(dst) | RM4(arg2));
	case SLJIT_MOV_UH:
	case SLJIT_MOVU_UH:
		SLJIT_ASSERT(!(flags & SET_FLAGS) && arg1 == TMP_REG1);
		if (IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, UXTH | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, UXTH_W | RD4(dst) | RM4(arg2));
	case SLJIT_MOV_SH:
	case SLJIT_MOVU_SH:
		SLJIT_ASSERT(!(flags & SET_FLAGS) && arg1 == TMP_REG1);
		if (IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, SXTH | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, SXTH_W | RD4(dst) | RM4(arg2));
	case SLJIT_NOT:
		SLJIT_ASSERT(arg1 == TMP_REG1);
		if (!(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, MVNS | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, MVN_W | (flags & SET_FLAGS) | RD4(dst) | RM4(arg2));
	case SLJIT_CLZ:
		SLJIT_ASSERT(arg1 == TMP_REG1);
		FAIL_IF(push_inst32(compiler, CLZ | RN4(arg2) | RD4(dst) | RM4(arg2)));
		if (flags & SET_FLAGS) {
			if (reg_map[dst] <= 7)
				return push_inst16(compiler, CMPI | RDN3(dst));
			return push_inst32(compiler, ADD_WI | SET_FLAGS | RN4(dst) | RD4(dst));
		}
		return SLJIT_SUCCESS;
	case SLJIT_ADD:
		if (!(flags & KEEP_FLAGS) && IS_3_LO_REGS(dst, arg1, arg2))
			return push_inst16(compiler, ADDS | RD3(dst) | RN3(arg1) | RM3(arg2));
		if (dst == arg1 && !(flags & SET_FLAGS))
			return push_inst16(compiler, ADD | SET_REGS44(dst, arg2));
		return push_inst32(compiler, ADD_W | (flags & SET_FLAGS) | RD4(dst) | RN4(arg1) | RM4(arg2));
	case SLJIT_ADDC:
		if (dst == arg1 && !(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, ADCS | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, ADC_W | (flags & SET_FLAGS) | RD4(dst) | RN4(arg1) | RM4(arg2));
	case SLJIT_SUB:
		if (!(flags & KEEP_FLAGS) && IS_3_LO_REGS(dst, arg1, arg2))
			return push_inst16(compiler, SUBS | RD3(dst) | RN3(arg1) | RM3(arg2));
		return push_inst32(compiler, SUB_W | (flags & SET_FLAGS) | RD4(dst) | RN4(arg1) | RM4(arg2));
	case SLJIT_SUBC:
		if (dst == arg1 && !(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, SBCS | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, SBC_W | (flags & SET_FLAGS) | RD4(dst) | RN4(arg1) | RM4(arg2));
	case SLJIT_MUL:
		if (!(flags & SET_FLAGS))
			return push_inst32(compiler, MUL | RD4(dst) | RN4(arg1) | RM4(arg2));
		SLJIT_ASSERT(reg_map[TMP_REG2] <= 7 && dst != TMP_REG2);
		FAIL_IF(push_inst32(compiler, SMULL | RT4(dst) | RD4(TMP_REG2) | RN4(arg1) | RM4(arg2)));
		/* cmp TMP_REG2, dst asr #31. */
		return push_inst32(compiler, CMP_W | RN4(TMP_REG2) | 0x70e0 | RM4(dst));
	case SLJIT_AND:
		if (!(flags & KEEP_FLAGS)) {
			if (dst == arg1 && IS_2_LO_REGS(dst, arg2))
				return push_inst16(compiler, ANDS | RD3(dst) | RN3(arg2));
			if ((flags & UNUSED_RETURN) && IS_2_LO_REGS(arg1, arg2))
				return push_inst16(compiler, TST | RD3(arg1) | RN3(arg2));
		}
		return push_inst32(compiler, AND_W | (flags & SET_FLAGS) | RD4(dst) | RN4(arg1) | RM4(arg2));
	case SLJIT_OR:
		if (dst == arg1 && !(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, ORRS | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, ORR_W | (flags & SET_FLAGS) | RD4(dst) | RN4(arg1) | RM4(arg2));
	case SLJIT_XOR:
		if (dst == arg1 && !(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, EORS | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, EOR_W | (flags & SET_FLAGS) | RD4(dst) | RN4(arg1) | RM4(arg2));
	case SLJIT_SHL:
		if (dst == arg1 && !(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, LSLS | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, LSL_W | (flags & SET_FLAGS) | RD4(dst) | RN4(arg1) | RM4(arg2));
	case SLJIT_LSHR:
		if (dst == arg1 && !(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, LSRS | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, LSR_W | (flags & SET_FLAGS) | RD4(dst) | RN4(arg1) | RM4(arg2));
	case SLJIT_ASHR:
		if (dst == arg1 && !(flags & KEEP_FLAGS) && IS_2_LO_REGS(dst, arg2))
			return push_inst16(compiler, ASRS | RD3(dst) | RN3(arg2));
		return push_inst32(compiler, ASR_W | (flags & SET_FLAGS) | RD4(dst) | RN4(arg1) | RM4(arg2));
	}

	SLJIT_ASSERT_STOP();
	return SLJIT_SUCCESS;
}

#define STORE		0x01
#define SIGNED		0x02

#define WORD_SIZE	0x00
#define BYTE_SIZE	0x04
#define HALF_SIZE	0x08

#define UPDATE		0x10
#define ARG_TEST	0x20

#define IS_WORD_SIZE(flags)		(!(flags & (BYTE_SIZE | HALF_SIZE)))
#define OFFSET_CHECK(imm, shift)	(!(argw & ~(imm << shift)))

/*
  1st letter:
  w = word
  b = byte
  h = half

  2nd letter:
  s = signed
  u = unsigned

  3rd letter:
  l = load
  s = store
*/

static SLJIT_CONST sljit_uw sljit_mem16[12] = {
/* w u l */ 0x5800 /* ldr */,
/* w u s */ 0x5000 /* str */,
/* w s l */ 0x5800 /* ldr */,
/* w s s */ 0x5000 /* str */,

/* b u l */ 0x5c00 /* ldrb */,
/* b u s */ 0x5400 /* strb */,
/* b s l */ 0x5600 /* ldrsb */,
/* b s s */ 0x5400 /* strb */,

/* h u l */ 0x5a00 /* ldrh */,
/* h u s */ 0x5200 /* strh */,
/* h s l */ 0x5e00 /* ldrsh */,
/* h s s */ 0x5200 /* strh */,
};

static SLJIT_CONST sljit_uw sljit_mem16_imm5[12] = {
/* w u l */ 0x6800 /* ldr imm5 */,
/* w u s */ 0x6000 /* str imm5 */,
/* w s l */ 0x6800 /* ldr imm5 */,
/* w s s */ 0x6000 /* str imm5 */,

/* b u l */ 0x7800 /* ldrb imm5 */,
/* b u s */ 0x7000 /* strb imm5 */,
/* b s l */ 0x0000 /* not allowed */,
/* b s s */ 0x7000 /* strb imm5 */,

/* h u l */ 0x8800 /* ldrh imm5 */,
/* h u s */ 0x8000 /* strh imm5 */,
/* h s l */ 0x0000 /* not allowed */,
/* h s s */ 0x8000 /* strh imm5 */,
};

#define MEM_IMM8	0xc00
#define MEM_IMM12	0x800000
static SLJIT_CONST sljit_uw sljit_mem32[12] = {
/* w u l */ 0xf8500000 /* ldr.w */,
/* w u s */ 0xf8400000 /* str.w */,
/* w s l */ 0xf8500000 /* ldr.w */,
/* w s s */ 0xf8400000 /* str.w */,

/* b u l */ 0xf8100000 /* ldrb.w */,
/* b u s */ 0xf8000000 /* strb.w */,
/* b s l */ 0xf9100000 /* ldrsb.w */,
/* b s s */ 0xf8000000 /* strb.w */,

/* h u l */ 0xf8300000 /* ldrh.w */,
/* h u s */ 0xf8200000 /* strsh.w */,
/* h s l */ 0xf9300000 /* ldrsh.w */,
/* h s s */ 0xf8200000 /* strsh.w */,
};

/* Helper function. Dst should be reg + value, using at most 1 instruction, flags does not set. */
static int emit_set_delta(struct sljit_compiler *compiler, int dst, int reg, sljit_w value)
{
	if (value >= 0) {
		if (value <= 0xfff)
			return push_inst32(compiler, ADDWI | RD4(dst) | RN4(reg) | IMM12(value));
		value = get_imm(value);
		if (value != INVALID_IMM)
			return push_inst32(compiler, ADD_WI | RD4(dst) | RN4(reg) | value);
	}
	else {
		value = -value;
		if (value <= 0xfff)
			return push_inst32(compiler, SUBWI | RD4(dst) | RN4(reg) | IMM12(value));
		value = get_imm(value);
		if (value != INVALID_IMM)
			return push_inst32(compiler, SUB_WI | RD4(dst) | RN4(reg) | value);
	}
	return SLJIT_ERR_UNSUPPORTED;
}

/* Can perform an operation using at most 1 instruction. */
static int getput_arg_fast(struct sljit_compiler *compiler, int flags, int reg, int arg, sljit_w argw)
{
	int tmp;

	SLJIT_ASSERT(arg & SLJIT_MEM);

	if (SLJIT_UNLIKELY(flags & UPDATE)) {
		if ((arg & 0xf) && !(arg & 0xf0) && argw <= 0xff && argw >= -0xff) {
			flags &= ~UPDATE;
			arg &= 0xf;
			if (SLJIT_UNLIKELY(flags & ARG_TEST))
				return 1;

			if (argw >= 0)
				argw |= 0x200;
			else {
				argw = -argw;
			}
			SLJIT_ASSERT(argw >= 0 && (argw & 0xff) <= 0xff);
			FAIL_IF(push_inst32(compiler, sljit_mem32[flags] | MEM_IMM8 | RT4(reg) | RN4(arg) | 0x100 | argw));
			return -1;
		}
		return (flags & ARG_TEST) ? SLJIT_SUCCESS : 0;
	}

	if (SLJIT_UNLIKELY(arg & 0xf0)) {
		argw &= 0x3;
		tmp = (arg >> 4) & 0xf;
		arg &= 0xf;
		if (SLJIT_UNLIKELY(flags & ARG_TEST))
			return 1;

		if (!argw && IS_3_LO_REGS(reg, arg, tmp))
			FAIL_IF(push_inst16(compiler, sljit_mem16[flags] | RD3(reg) | RN3(arg) | RM3(tmp)));
		else
			FAIL_IF(push_inst32(compiler, sljit_mem32[flags] | RT4(reg) | RN4(arg) | RM4(tmp) | (argw << 4)));
		return -1;
	}

	if (!(arg & 0xf) || argw > 0xfff || argw < -0xff)
		return (flags & ARG_TEST) ? SLJIT_SUCCESS : 0;

	if (SLJIT_UNLIKELY(flags & ARG_TEST))
		return 1;

	arg &= 0xf;
	if (IS_2_LO_REGS(reg, arg) && sljit_mem16_imm5[flags]) {
		tmp = 3;
		if (IS_WORD_SIZE(flags)) {
			if (OFFSET_CHECK(0x1f, 2))
				tmp = 2;
		}
		else if (flags & BYTE_SIZE)
		{
			if (OFFSET_CHECK(0x1f, 0))
				tmp = 0;
		}
		else {
			SLJIT_ASSERT(flags & HALF_SIZE);
			if (OFFSET_CHECK(0x1f, 1))
				tmp = 1;
		}

		if (tmp != 3) {
			FAIL_IF(push_inst16(compiler, sljit_mem16_imm5[flags] | RD3(reg) | RN3(arg) | (argw << (6 - tmp))));
			return -1;
		}
	}

	/* SP based immediate. */
	if (SLJIT_UNLIKELY(arg == SLJIT_LOCALS_REG) && OFFSET_CHECK(0xff, 2) && IS_WORD_SIZE(flags) && reg_map[reg] <= 7) {
		FAIL_IF(push_inst16(compiler, STR_SP | ((flags & STORE) ? 0 : 0x800) | RDN3(reg) | (argw >> 2)));
		return -1;
	}

	if (argw >= 0)
		FAIL_IF(push_inst32(compiler, sljit_mem32[flags] | MEM_IMM12 | RT4(reg) | RN4(arg) | argw));
	else
		FAIL_IF(push_inst32(compiler, sljit_mem32[flags] | MEM_IMM8 | RT4(reg) | RN4(arg) | -argw));
	return -1;
}

/* see getput_arg below.
   Note: can_cache is called only for binary operators. Those
   operators always uses word arguments without write back. */
static int can_cache(int arg, sljit_w argw, int next_arg, sljit_w next_argw)
{
	/* Simple operation except for updates. */
	if ((arg & 0xf0) || !(next_arg & SLJIT_MEM))
		return 0;

	if (!(arg & 0xf)) {
		if ((sljit_uw)(argw - next_argw) <= 0xfff || (sljit_uw)(next_argw - argw) <= 0xfff)
			return 1;
		return 0;
	}

	if (argw == next_argw)
		return 1;

	if (arg == next_arg && ((sljit_uw)(argw - next_argw) <= 0xfff || (sljit_uw)(next_argw - argw) <= 0xfff))
		return 1;

	return 0;
}

/* Emit the necessary instructions. See can_cache above. */
static int getput_arg(struct sljit_compiler *compiler, int flags, int reg, int arg, sljit_w argw, int next_arg, sljit_w next_argw)
{
	int tmp_r;
	sljit_w tmp;

	SLJIT_ASSERT(arg & SLJIT_MEM);
	if (!(next_arg & SLJIT_MEM)) {
		next_arg = 0;
		next_argw = 0;
	}

	tmp_r = (flags & STORE) ? TMP_REG3 : reg;

	if (SLJIT_UNLIKELY(flags & UPDATE)) {
		flags &= ~UPDATE;
		/* Update only applies if a base register exists. */
		if (arg & 0xf) {
			/* There is no caching here. */
			tmp = (arg & 0xf0) >> 4;
			arg &= 0xf;

			if (!tmp) {
				if (!(argw & ~0xfff)) {
					FAIL_IF(push_inst32(compiler, sljit_mem32[flags] | MEM_IMM12 | RT4(reg) | RN4(arg) | argw));
					return push_inst32(compiler, ADDWI | RD4(arg) | RN4(arg) | IMM12(argw));
				}

				if (compiler->cache_arg == SLJIT_MEM) {
					if (argw == compiler->cache_argw) {
						tmp = TMP_REG3;
						argw = 0;
					}
					else if (emit_set_delta(compiler, TMP_REG3, TMP_REG3, argw - compiler->cache_argw) != SLJIT_ERR_UNSUPPORTED) {
						FAIL_IF(compiler->error);
						compiler->cache_argw = argw;
						tmp = TMP_REG3;
						argw = 0;
					}
				}

				if (argw) {
					FAIL_IF(load_immediate(compiler, TMP_REG3, argw));
					compiler->cache_arg = SLJIT_MEM;
					compiler->cache_argw = argw;
					tmp = TMP_REG3;
					argw = 0;
				}
			}

			argw &= 0x3;
			if (!argw && IS_3_LO_REGS(reg, arg, tmp)) {
				FAIL_IF(push_inst16(compiler, sljit_mem16[flags] | RD3(reg) | RN3(arg) | RM3(tmp)));
				return push_inst16(compiler, ADD | SET_REGS44(arg, tmp));
			}
			FAIL_IF(push_inst32(compiler, sljit_mem32[flags] | RT4(reg) | RN4(arg) | RM4(tmp) | (argw << 4)));
			return push_inst32(compiler, ADD_W | RD4(arg) | RN4(arg) | RM4(tmp) | (argw << 6));
		}
	}

	SLJIT_ASSERT(!(arg & 0xf0));

	if (compiler->cache_arg == arg) {
		if (!((argw - compiler->cache_argw) & ~0xfff))
			return push_inst32(compiler, sljit_mem32[flags] | MEM_IMM12 | RT4(reg) | RN4(TMP_REG3) | (argw - compiler->cache_argw));
		if (!((compiler->cache_argw - argw) & ~0xff))
			return push_inst32(compiler, sljit_mem32[flags] | MEM_IMM8 | RT4(reg) | RN4(TMP_REG3) | (compiler->cache_argw - argw));
		if (emit_set_delta(compiler, TMP_REG3, TMP_REG3, argw - compiler->cache_argw) != SLJIT_ERR_UNSUPPORTED) {
			FAIL_IF(compiler->error);
			return push_inst32(compiler, sljit_mem32[flags] | MEM_IMM12 | RT4(reg) | RN4(TMP_REG3) | 0);
		}
	}

	next_arg = (arg & 0xf) && (arg == next_arg);
	arg &= 0xf;
	if (arg && compiler->cache_arg == SLJIT_MEM && compiler->cache_argw == argw)
		return push_inst32(compiler, sljit_mem32[flags] | RT4(reg) | RN4(arg) | RM4(TMP_REG3));

	compiler->cache_argw = argw;
	if (next_arg && emit_set_delta(compiler, TMP_REG3, arg, argw) != SLJIT_ERR_UNSUPPORTED) {
		FAIL_IF(compiler->error);
		compiler->cache_arg = SLJIT_MEM | arg;
		arg = 0;
	}
	else {
		FAIL_IF(load_immediate(compiler, TMP_REG3, argw));
		compiler->cache_arg = SLJIT_MEM;

		if (next_arg) {
			FAIL_IF(push_inst16(compiler, ADD | SET_REGS44(TMP_REG3, arg)));
			compiler->cache_arg = SLJIT_MEM | arg;
			arg = 0;
		}
	}

	if (arg)
		return push_inst32(compiler, sljit_mem32[flags] | RT4(reg) | RN4(arg) | RM4(TMP_REG3));
	return push_inst32(compiler, sljit_mem32[flags] | MEM_IMM12 | RT4(reg) | RN4(TMP_REG3) | 0);
}

static SLJIT_INLINE int emit_op_mem(struct sljit_compiler *compiler, int flags, int reg, int arg, sljit_w argw)
{
	if (getput_arg_fast(compiler, flags, reg, arg, argw))
		return compiler->error;
	compiler->cache_arg = 0;
	compiler->cache_argw = 0;
	return getput_arg(compiler, flags, reg, arg, argw, 0, 0);
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_enter(struct sljit_compiler *compiler, int args, int temporaries, int generals, int local_size)
{
	int size;
	sljit_ins push;

	CHECK_ERROR();
	check_sljit_emit_enter(compiler, args, temporaries, generals, local_size);

	compiler->temporaries = temporaries;
	compiler->generals = generals;

	push = (1 << 4);
	if (generals >= 5)
		push |= 1 << 11;
	if (generals >= 4)
		push |= 1 << 10;
	if (generals >= 3)
		push |= 1 << 8;
	if (generals >= 2)
		push |= 1 << 7;
	if (generals >= 1)
		push |= 1 << 6;
        if (temporaries >= 5)
		push |= 1 << 5;
	FAIL_IF(generals >= 3
		? push_inst32(compiler, PUSH_W | (1 << 14) | push)
		: push_inst16(compiler, PUSH | push));

	/* Stack must be aligned to 8 bytes: */
	size = (3 + generals) * sizeof(sljit_uw);
	local_size += size;
	local_size = (local_size + 7) & ~7;
	local_size -= size;
	compiler->local_size = local_size;
	if (local_size > 0) {
		if (local_size <= (127 << 2))
			FAIL_IF(push_inst16(compiler, SUB_SP | (local_size >> 2)));
		else
			FAIL_IF(emit_op_imm(compiler, SLJIT_SUB | ARG2_IMM, SLJIT_LOCALS_REG, SLJIT_LOCALS_REG, local_size));
	}

	if (args >= 1)
		FAIL_IF(push_inst16(compiler, MOV | SET_REGS44(SLJIT_GENERAL_REG1, SLJIT_TEMPORARY_REG1)));
	if (args >= 2)
		FAIL_IF(push_inst16(compiler, MOV | SET_REGS44(SLJIT_GENERAL_REG2, SLJIT_TEMPORARY_REG2)));
	if (args >= 3)
		FAIL_IF(push_inst16(compiler, MOV | SET_REGS44(SLJIT_GENERAL_REG3, SLJIT_TEMPORARY_REG3)));

	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE void sljit_fake_enter(struct sljit_compiler *compiler, int args, int temporaries, int generals, int local_size)
{
	int size;

	CHECK_ERROR_VOID();
	check_sljit_fake_enter(compiler, args, temporaries, generals, local_size);

	compiler->temporaries = temporaries;
	compiler->generals = generals;

	size = (3 + generals) * sizeof(sljit_uw);
	local_size += size;
	local_size = (local_size + 7) & ~7;
	local_size -= size;
	compiler->local_size = local_size;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_return(struct sljit_compiler *compiler, int src, sljit_w srcw)
{
	sljit_ins pop;

	CHECK_ERROR();
	check_sljit_emit_return(compiler, src, srcw);

	if (src != SLJIT_UNUSED && src != SLJIT_RETURN_REG) {
		if (src >= SLJIT_TEMPORARY_REG1 && src <= TMP_REG3)
			FAIL_IF(push_inst16(compiler, MOV | SET_REGS44(SLJIT_RETURN_REG, src)));
		else
			FAIL_IF(emit_op_mem(compiler, WORD_SIZE, SLJIT_RETURN_REG, src, srcw));
	}

	if (compiler->local_size > 0) {
		if (compiler->local_size <= (127 << 2))
			FAIL_IF(push_inst16(compiler, ADD_SP | (compiler->local_size >> 2)));
		else
			FAIL_IF(emit_op_imm(compiler, SLJIT_ADD | ARG2_IMM, SLJIT_LOCALS_REG, SLJIT_LOCALS_REG, compiler->local_size));
	}

	pop = (1 << 4);
	if (compiler->generals >= 5)
		pop |= 1 << 11;
	if (compiler->generals >= 4)
		pop |= 1 << 10;
	if (compiler->generals >= 3)
		pop |= 1 << 8;
	if (compiler->generals >= 2)
		pop |= 1 << 7;
	if (compiler->generals >= 1)
		pop |= 1 << 6;
        if (compiler->temporaries >= 5)
		pop |= 1 << 5;
	return compiler->generals >= 3
		? push_inst32(compiler, POP_W | (1 << 15) | pop)
		: push_inst16(compiler, POP | pop);
}

/* --------------------------------------------------------------------- */
/*  Operators                                                            */
/* --------------------------------------------------------------------- */

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_op0(struct sljit_compiler *compiler, int op)
{
	CHECK_ERROR();
	check_sljit_emit_op0(compiler, op);

	op = GET_OPCODE(op);
	switch (op) {
	case SLJIT_BREAKPOINT:
		push_inst16(compiler, BKPT);
		break;
	case SLJIT_NOP:
		push_inst16(compiler, NOP);
		break;
	}

	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_op1(struct sljit_compiler *compiler, int op,
	int dst, sljit_w dstw,
	int src, sljit_w srcw)
{
	int op_type, dst_r, flags;

	CHECK_ERROR();
	check_sljit_emit_op1(compiler, op, dst, dstw, src, srcw);

	compiler->cache_arg = 0;
	compiler->cache_argw = 0;

	op_type = GET_OPCODE(op);
	dst_r = (dst >= SLJIT_TEMPORARY_REG1 && dst <= SLJIT_NO_REGISTERS) ? dst : TMP_REG1;

	if (op_type >= SLJIT_MOV && op_type <= SLJIT_MOVU_SI) {
		switch (op_type) {
		case SLJIT_MOV:
		case SLJIT_MOV_UI:
		case SLJIT_MOV_SI:
			flags = WORD_SIZE;
			break;
		case SLJIT_MOV_UB:
			flags = BYTE_SIZE;
			if (src & SLJIT_IMM)
				srcw = (unsigned char)srcw;
			break;
		case SLJIT_MOV_SB:
			flags = BYTE_SIZE | SIGNED;
			if (src & SLJIT_IMM)
				srcw = (signed char)srcw;
			break;
		case SLJIT_MOV_UH:
			flags = HALF_SIZE;
			if (src & SLJIT_IMM)
				srcw = (unsigned short)srcw;
			break;
		case SLJIT_MOV_SH:
			flags = HALF_SIZE | SIGNED;
			if (src & SLJIT_IMM)
				srcw = (signed short)srcw;
			break;
		case SLJIT_MOVU:
		case SLJIT_MOVU_UI:
		case SLJIT_MOVU_SI:
			flags = WORD_SIZE | UPDATE;
			break;
		case SLJIT_MOVU_UB:
			flags = BYTE_SIZE | UPDATE;
			if (src & SLJIT_IMM)
				srcw = (unsigned char)srcw;
			break;
		case SLJIT_MOVU_SB:
			flags = BYTE_SIZE | SIGNED | UPDATE;
			if (src & SLJIT_IMM)
				srcw = (signed char)srcw;
			break;
		case SLJIT_MOVU_UH:
			flags = HALF_SIZE | UPDATE;
			if (src & SLJIT_IMM)
				srcw = (unsigned short)srcw;
			break;
		case SLJIT_MOVU_SH:
			flags = HALF_SIZE | SIGNED | UPDATE;
			if (src & SLJIT_IMM)
				srcw = (signed short)srcw;
			break;
		default:
			SLJIT_ASSERT_STOP();
			flags = 0;
			break;
		}

		if (src & SLJIT_IMM)
			FAIL_IF(emit_op_imm(compiler, SLJIT_MOV | ARG2_IMM, dst_r, TMP_REG1, srcw));
		else if (src & SLJIT_MEM) {
			if (getput_arg_fast(compiler, flags, dst_r, src, srcw))
				FAIL_IF(compiler->error);
			else
				FAIL_IF(getput_arg(compiler, flags, dst_r, src, srcw, dst, dstw));
		} else {
			if (dst_r != TMP_REG1)
				return emit_op_imm(compiler, op_type, dst_r, TMP_REG1, src);
			dst_r = src;
		}

		if (dst & SLJIT_MEM) {
			if (getput_arg_fast(compiler, flags | STORE, dst_r, dst, dstw))
				return compiler->error;
			else
				return getput_arg(compiler, flags | STORE, dst_r, dst, dstw, 0, 0);
		}
		return SLJIT_SUCCESS;
	}

	if (op_type == SLJIT_NEG) {
#if (defined SLJIT_VERBOSE && SLJIT_VERBOSE) || (defined SLJIT_DEBUG && SLJIT_DEBUG)
		compiler->skip_checks = 1;
#endif
		return sljit_emit_op2(compiler, GET_FLAGS(op) | SLJIT_SUB, dst, dstw, SLJIT_IMM, 0, src, srcw);
	}

	flags = (GET_FLAGS(op) ? SET_FLAGS : 0) | ((op & SLJIT_KEEP_FLAGS) ? KEEP_FLAGS : 0);
	if (src & SLJIT_MEM) {
		if (getput_arg_fast(compiler, WORD_SIZE, TMP_REG2, src, srcw))
			FAIL_IF(compiler->error);
		else
			FAIL_IF(getput_arg(compiler, WORD_SIZE, TMP_REG2, src, srcw, dst, dstw));
		src = TMP_REG2;
	}

	if (src & SLJIT_IMM)
		flags |= ARG2_IMM;
	else
		srcw = src;

	emit_op_imm(compiler, flags | op_type, dst_r, TMP_REG1, srcw);

	if (dst & SLJIT_MEM) {
		if (getput_arg_fast(compiler, flags | STORE, dst_r, dst, dstw))
			return compiler->error;
		else
			return getput_arg(compiler, flags | STORE, dst_r, dst, dstw, 0, 0);
	}
	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_op2(struct sljit_compiler *compiler, int op,
	int dst, sljit_w dstw,
	int src1, sljit_w src1w,
	int src2, sljit_w src2w)
{
	int dst_r, flags;

	CHECK_ERROR();
	check_sljit_emit_op2(compiler, op, dst, dstw, src1, src1w, src2, src2w);

	compiler->cache_arg = 0;
	compiler->cache_argw = 0;

	dst_r = (dst >= SLJIT_TEMPORARY_REG1 && dst <= SLJIT_NO_REGISTERS) ? dst : TMP_REG1;
	flags = (GET_FLAGS(op) ? SET_FLAGS : 0) | ((op & SLJIT_KEEP_FLAGS) ? KEEP_FLAGS : 0);

	if ((dst & SLJIT_MEM) && !getput_arg_fast(compiler, WORD_SIZE | STORE | ARG_TEST, TMP_REG1, dst, dstw))
		flags |= SLOW_DEST;

	if (src1 & SLJIT_MEM) {
		if (getput_arg_fast(compiler, WORD_SIZE, TMP_REG1, src1, src1w))
			FAIL_IF(compiler->error);
		else
			flags |= SLOW_SRC1;
	}
	if (src2 & SLJIT_MEM) {
		if (getput_arg_fast(compiler, WORD_SIZE, TMP_REG2, src2, src2w))
			FAIL_IF(compiler->error);
		else
			flags |= SLOW_SRC2;
	}

	if ((flags & (SLOW_SRC1 | SLOW_SRC2)) == (SLOW_SRC1 | SLOW_SRC2)) {
		if (!can_cache(src1, src1w, src2, src2w) && can_cache(src1, src1w, dst, dstw)) {
			FAIL_IF(getput_arg(compiler, WORD_SIZE, TMP_REG2, src2, src2w, src1, src1w));
			FAIL_IF(getput_arg(compiler, WORD_SIZE, TMP_REG1, src1, src1w, dst, dstw));
		}
		else {
			FAIL_IF(getput_arg(compiler, WORD_SIZE, TMP_REG1, src1, src1w, src2, src2w));
			FAIL_IF(getput_arg(compiler, WORD_SIZE, TMP_REG2, src2, src2w, dst, dstw));
		}
	}
	else if (flags & SLOW_SRC1)
		FAIL_IF(getput_arg(compiler, WORD_SIZE, TMP_REG1, src1, src1w, dst, dstw));
	else if (flags & SLOW_SRC2)
		FAIL_IF(getput_arg(compiler, WORD_SIZE, TMP_REG2, src2, src2w, dst, dstw));

	if (src1 & SLJIT_MEM)
		src1 = TMP_REG1;
	if (src2 & SLJIT_MEM)
		src2 = TMP_REG2;

	if (src1 & SLJIT_IMM)
		flags |= ARG1_IMM;
	else
		src1w = src1;
	if (src2 & SLJIT_IMM)
		flags |= ARG2_IMM;
	else
		src2w = src2;

	if (dst == SLJIT_UNUSED)
		flags |= UNUSED_RETURN;

	if (GET_OPCODE(op) == SLJIT_MUL && (op & SLJIT_SET_O))
		flags |= SET_MULOV;

	emit_op_imm(compiler, flags | GET_OPCODE(op), dst_r, src1w, src2w);

	if (dst & SLJIT_MEM) {
		if (!(flags & SLOW_DEST)) {
			getput_arg_fast(compiler, WORD_SIZE | STORE, dst_r, dst, dstw);
			return compiler->error;
		}
		return getput_arg(compiler, WORD_SIZE | STORE, TMP_REG1, dst, dstw, 0, 0);
	}
	return SLJIT_SUCCESS;
}

/* --------------------------------------------------------------------- */
/*  Floating point operators                                             */
/* --------------------------------------------------------------------- */

SLJIT_API_FUNC_ATTRIBUTE int sljit_is_fpu_available(void)
{
	return 1;
}

static int emit_fop_mem(struct sljit_compiler *compiler, int flags, int reg, int arg, sljit_w argw)
{
	sljit_w tmp;
	sljit_w inst = VSTR | ((flags & STORE) ? 0 : 0x00100000);

	SLJIT_ASSERT(arg & SLJIT_MEM);

	/* Fast loads and stores. */
	if (SLJIT_UNLIKELY(arg & 0xf0)) {
		FAIL_IF(push_inst32(compiler, ADD_W | RD4(TMP_REG2) | RN4(arg & 0xf) | RM4((arg & 0xf0) >> 4) | ((argw & 0x3) << 6)));
		arg = SLJIT_MEM | TMP_REG2;
		argw = 0;
	}

	if (arg & 0xf) {
		if (!(argw & ~0x3fc))
			return push_inst32(compiler, inst | 0x800000 | RN4(arg & 0xf) | DD4(reg) | (argw >> 2));
		if (!(-argw & ~0x3fc))
			return push_inst32(compiler, inst | RN4(arg & 0xf) | DD4(reg) | (-argw >> 2));
	}

	SLJIT_ASSERT(!(arg & 0xf0));
	if (compiler->cache_arg == arg) {
		tmp = argw - compiler->cache_argw;
		if (!(tmp & ~0x3fc))
			return push_inst32(compiler, inst | 0x800000 | RN4(TMP_REG3) | DD4(reg) | (tmp >> 2));
		if (!(-tmp & ~0x3fc))
			return push_inst32(compiler, inst | RN4(TMP_REG3) | DD4(reg) | (-tmp >> 2));
		if (emit_set_delta(compiler, TMP_REG3, TMP_REG3, tmp) != SLJIT_ERR_UNSUPPORTED) {
			FAIL_IF(compiler->error);
			compiler->cache_argw = argw;
			return push_inst32(compiler, inst | 0x800000 | RN4(TMP_REG3) | DD4(reg));
		}
	}

	compiler->cache_arg = arg;
	compiler->cache_argw = argw;

	if (SLJIT_UNLIKELY(!(arg & 0xf)))
		FAIL_IF(load_immediate(compiler, TMP_REG3, argw));
	else if (emit_set_delta(compiler, TMP_REG3, arg & 0xf, argw) != SLJIT_ERR_UNSUPPORTED)
		FAIL_IF(compiler->error);
	else {
		FAIL_IF(load_immediate(compiler, TMP_REG3, argw));
		if (arg & 0xf)
			FAIL_IF(push_inst16(compiler, ADD | SET_REGS44(TMP_REG3, (arg & 0xf))));
	}
	return push_inst32(compiler, inst | 0x800000 | RN4(TMP_REG3) | DD4(reg));
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_fop1(struct sljit_compiler *compiler, int op,
	int dst, sljit_w dstw,
	int src, sljit_w srcw)
{
	int dst_r;

	CHECK_ERROR();
	check_sljit_emit_fop1(compiler, op, dst, dstw, src, srcw);

	compiler->cache_arg = 0;
	compiler->cache_argw = 0;

	if (GET_OPCODE(op) == SLJIT_FCMP) {
		if (dst & SLJIT_MEM) {
			emit_fop_mem(compiler, 0, TMP_FREG1, dst, dstw);
			dst = TMP_FREG1;
		}
		if (src & SLJIT_MEM) {
			emit_fop_mem(compiler, 0, TMP_FREG2, src, srcw);
			src = TMP_FREG2;
		}
		FAIL_IF(push_inst32(compiler, VCMP_F64 | DD4(dst) | DM4(src)));
		return push_inst32(compiler, VMRS);
	}

	dst_r = (dst >= SLJIT_FLOAT_REG1 && dst <= SLJIT_FLOAT_REG4) ? dst : TMP_FREG1;
	if (src & SLJIT_MEM) {
		emit_fop_mem(compiler, 0, dst_r, src, srcw);
		src = dst_r;
	}

	switch (GET_OPCODE(op)) {
	case SLJIT_FMOV:
		if (src != dst_r)
			FAIL_IF(push_inst32(compiler, VMOV_F64 | DD4(dst_r) | DM4(src)));
		break;
	case SLJIT_FNEG:
		FAIL_IF(push_inst32(compiler, VNEG_F64 | DD4(dst_r) | DM4(src)));
		break;
	case SLJIT_FABS:
		FAIL_IF(push_inst32(compiler, VABS_F64 | DD4(dst_r) | DM4(src)));
		break;
	}

	if (dst & SLJIT_MEM)
		return emit_fop_mem(compiler, STORE, TMP_FREG1, dst, dstw);
	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_fop2(struct sljit_compiler *compiler, int op,
	int dst, sljit_w dstw,
	int src1, sljit_w src1w,
	int src2, sljit_w src2w)
{
	int dst_r;

	CHECK_ERROR();
	check_sljit_emit_fop2(compiler, op, dst, dstw, src1, src1w, src2, src2w);

	compiler->cache_arg = 0;
	compiler->cache_argw = 0;

	dst_r = (dst >= SLJIT_FLOAT_REG1 && dst <= SLJIT_FLOAT_REG4) ? dst : TMP_FREG1;
	if (src1 & SLJIT_MEM) {
		emit_fop_mem(compiler, 0, TMP_FREG1, src1, src1w);
		src1 = TMP_FREG1;
	}
	if (src2 & SLJIT_MEM) {
		emit_fop_mem(compiler, 0, TMP_FREG2, src2, src2w);
		src2 = TMP_FREG2;
	}

	switch (GET_OPCODE(op)) {
	case SLJIT_FADD:
		FAIL_IF(push_inst32(compiler, VADD_F64 | DD4(dst_r) | DN4(src1) | DM4(src2)));
		break;
	case SLJIT_FSUB:
		FAIL_IF(push_inst32(compiler, VSUB_F64 | DD4(dst_r) | DN4(src1) | DM4(src2)));
		break;
	case SLJIT_FMUL:
		FAIL_IF(push_inst32(compiler, VMUL_F64 | DD4(dst_r) | DN4(src1) | DM4(src2)));
		break;
	case SLJIT_FDIV:
		FAIL_IF(push_inst32(compiler, VDIV_F64 | DD4(dst_r) | DN4(src1) | DM4(src2)));
		break;
	}

	if (dst & SLJIT_MEM)
		return emit_fop_mem(compiler, STORE, TMP_FREG1, dst, dstw);
	return SLJIT_SUCCESS;
}

/* --------------------------------------------------------------------- */
/*  Other instructions                                                   */
/* --------------------------------------------------------------------- */

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_fast_enter(struct sljit_compiler *compiler, int dst, sljit_w dstw, int args, int temporaries, int generals, int local_size)
{
	int size;

	CHECK_ERROR();
	check_sljit_emit_fast_enter(compiler, dst, dstw, args, temporaries, generals, local_size);

	compiler->temporaries = temporaries;
	compiler->generals = generals;

	size = (3 + generals) * sizeof(sljit_uw);
	local_size += size;
	local_size = (local_size + 7) & ~7;
	local_size -= size;
	compiler->local_size = local_size;

	if (dst >= SLJIT_TEMPORARY_REG1 && dst <= SLJIT_NO_REGISTERS)
		return push_inst16(compiler, MOV | SET_REGS44(dst, TMP_REG3));
	else if (dst & SLJIT_MEM) {
		if (getput_arg_fast(compiler, WORD_SIZE | STORE, TMP_REG3, dst, dstw))
			return compiler->error;
		FAIL_IF(push_inst16(compiler, MOV | SET_REGS44(TMP_REG2, TMP_REG3)));
		compiler->cache_arg = 0;
		compiler->cache_argw = 0;
		return getput_arg(compiler, WORD_SIZE | STORE, TMP_REG2, dst, dstw, 0, 0);
	}

	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_fast_return(struct sljit_compiler *compiler, int src, sljit_w srcw)
{
	CHECK_ERROR();
	check_sljit_emit_fast_return(compiler, src, srcw);

	if (src >= SLJIT_TEMPORARY_REG1 && src <= SLJIT_NO_REGISTERS)
		FAIL_IF(push_inst16(compiler, MOV | SET_REGS44(TMP_REG3, src)));
	else if (src & SLJIT_MEM) {
		if (getput_arg_fast(compiler, WORD_SIZE, TMP_REG3, src, srcw))
			FAIL_IF(compiler->error);
		else {
			compiler->cache_arg = 0;
			compiler->cache_argw = 0;
			FAIL_IF(getput_arg(compiler, WORD_SIZE, TMP_REG2, src, srcw, 0, 0));
			FAIL_IF(push_inst16(compiler, MOV | SET_REGS44(TMP_REG3, TMP_REG2)));
		}
	}
	else if (src & SLJIT_IMM)
		FAIL_IF(load_immediate(compiler, TMP_REG3, srcw));
	return push_inst16(compiler, BLX | RN3(TMP_REG3));
}

/* --------------------------------------------------------------------- */
/*  Conditional instructions                                             */
/* --------------------------------------------------------------------- */

static sljit_uw get_cc(int type)
{
	switch (type) {
	case SLJIT_C_EQUAL:
	case SLJIT_C_MUL_NOT_OVERFLOW:
	case SLJIT_C_FLOAT_EQUAL:
		return 0x0;

	case SLJIT_C_NOT_EQUAL:
	case SLJIT_C_MUL_OVERFLOW:
	case SLJIT_C_FLOAT_NOT_EQUAL:
		return 0x1;

	case SLJIT_C_LESS:
	case SLJIT_C_FLOAT_LESS:
		return 0x3;

	case SLJIT_C_GREATER_EQUAL:
	case SLJIT_C_FLOAT_GREATER_EQUAL:
		return 0x2;

	case SLJIT_C_GREATER:
	case SLJIT_C_FLOAT_GREATER:
		return 0x8;

	case SLJIT_C_LESS_EQUAL:
	case SLJIT_C_FLOAT_LESS_EQUAL:
		return 0x9;

	case SLJIT_C_SIG_LESS:
		return 0xb;

	case SLJIT_C_SIG_GREATER_EQUAL:
		return 0xa;

	case SLJIT_C_SIG_GREATER:
		return 0xc;

	case SLJIT_C_SIG_LESS_EQUAL:
		return 0xd;

	case SLJIT_C_OVERFLOW:
	case SLJIT_C_FLOAT_NAN:
		return 0x6;

	case SLJIT_C_NOT_OVERFLOW:
	case SLJIT_C_FLOAT_NOT_NAN:
		return 0x7;

	default: /* SLJIT_JUMP */
		return 0xe;
	}
}

SLJIT_API_FUNC_ATTRIBUTE struct sljit_label* sljit_emit_label(struct sljit_compiler *compiler)
{
	struct sljit_label *label;

	CHECK_ERROR_PTR();
	check_sljit_emit_label(compiler);

	if (compiler->last_label && compiler->last_label->size == compiler->size)
		return compiler->last_label;

	label = (struct sljit_label*)ensure_abuf(compiler, sizeof(struct sljit_label));
	PTR_FAIL_IF(!label);
	set_label(label, compiler);
	return label;
}

SLJIT_API_FUNC_ATTRIBUTE struct sljit_jump* sljit_emit_jump(struct sljit_compiler *compiler, int type)
{
	struct sljit_jump *jump;
	int cc;

	CHECK_ERROR_PTR();
	check_sljit_emit_jump(compiler, type);

	jump = (struct sljit_jump*)ensure_abuf(compiler, sizeof(struct sljit_jump));
	PTR_FAIL_IF(!jump);
	set_jump(jump, compiler, type & SLJIT_REWRITABLE_JUMP);
	type &= 0xff;

	/* In ARM, we don't need to touch the arguments. */
	PTR_FAIL_IF(emit_imm32_const(compiler, TMP_REG1, 0));
	if (type < SLJIT_JUMP) {
		jump->flags |= IS_CONDITIONAL;
		cc = get_cc(type);
		jump->flags |= cc << 8;
		PTR_FAIL_IF(push_inst16(compiler, IT | (cc << 4) | 0x8));
	}

	jump->addr = compiler->size;
	if (type <= SLJIT_JUMP)
		PTR_FAIL_IF(push_inst16(compiler, BX | RN3(TMP_REG1)));
	else {
		jump->flags |= IS_BL;
		PTR_FAIL_IF(push_inst16(compiler, BLX | RN3(TMP_REG1)));
	}

	return jump;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_ijump(struct sljit_compiler *compiler, int type, int src, sljit_w srcw)
{
	struct sljit_jump *jump;

	CHECK_ERROR();
	check_sljit_emit_ijump(compiler, type, src, srcw);

	/* In ARM, we don't need to touch the arguments. */
	if (src & SLJIT_IMM) {
		jump = (struct sljit_jump*)ensure_abuf(compiler, sizeof(struct sljit_jump));
		FAIL_IF(!jump);
		set_jump(jump, compiler, JUMP_ADDR | ((type >= SLJIT_FAST_CALL) ? IS_BL : 0));
		jump->u.target = srcw;

		FAIL_IF(emit_imm32_const(compiler, TMP_REG1, 0));
		jump->addr = compiler->size;
		FAIL_IF(push_inst16(compiler, (type <= SLJIT_JUMP ? BX : BLX) | RN3(TMP_REG1)));
	}
	else {
		if (src >= SLJIT_TEMPORARY_REG1 && src <= SLJIT_NO_REGISTERS)
			return push_inst16(compiler, (type <= SLJIT_JUMP ? BX : BLX) | RN3(src));

		FAIL_IF(emit_op_mem(compiler, WORD_SIZE, type <= SLJIT_JUMP ? TMP_PC : TMP_REG1, src, srcw));
		if (type >= SLJIT_FAST_CALL)
			return push_inst16(compiler, BLX | RN3(TMP_REG1));
	}
	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_cond_value(struct sljit_compiler *compiler, int op, int dst, sljit_w dstw, int type)
{
	int dst_r;
	sljit_uw cc;

	CHECK_ERROR();
	check_sljit_emit_cond_value(compiler, op, dst, dstw, type);

	if (dst == SLJIT_UNUSED)
		return SLJIT_SUCCESS;

	cc = get_cc(type);
	if (GET_OPCODE(op) == SLJIT_OR && dst >= SLJIT_TEMPORARY_REG1 && dst <= SLJIT_NO_REGISTERS) {
		FAIL_IF(push_inst16(compiler, IT | (cc << 4) | 0x8));
		FAIL_IF(push_inst32(compiler, ORRI | RN4(dst) | RD4(dst) | 0x1));
		if (op & SLJIT_SET_E) {
			if (reg_map[dst] <= 7)
				return push_inst16(compiler, ORRS | RD3(dst) | RN3(dst));
			return push_inst32(compiler, ORR_W | SET_FLAGS | RD4(TMP_REG1) | RN4(dst) | RM4(dst));
		}
		return SLJIT_SUCCESS;
	}

	dst_r = TMP_REG2;
	if (op == SLJIT_MOV && dst >= SLJIT_TEMPORARY_REG1 && dst <= SLJIT_NO_REGISTERS && reg_map[dst] <= 7)
		dst_r = dst;

	FAIL_IF(push_inst16(compiler, IT | (cc << 4) | (((cc & 0x1) ^ 0x1) << 3) | 0x4));
	FAIL_IF(push_inst16(compiler, MOVSI | 0x1 | RDN3(dst_r)));
	FAIL_IF(push_inst16(compiler, MOVSI | 0x0 | RDN3(dst_r)));

	if (dst_r == TMP_REG2) {
		if (GET_OPCODE(op) == SLJIT_OR) {
#if (defined SLJIT_VERBOSE && SLJIT_VERBOSE) || (defined SLJIT_DEBUG && SLJIT_DEBUG)
			compiler->skip_checks = 1;
#endif
			return sljit_emit_op2(compiler, op, dst, dstw, dst, dstw, TMP_REG2, 0);
		}
		if (dst & SLJIT_MEM)
			return emit_op_mem(compiler, WORD_SIZE | STORE, TMP_REG2, dst, dstw);
		else
			return push_inst16(compiler, MOV | SET_REGS44(dst, TMP_REG2));
	}

	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE struct sljit_const* sljit_emit_const(struct sljit_compiler *compiler, int dst, sljit_w dstw, sljit_w init_value)
{
	struct sljit_const *const_;
	int dst_r;

	CHECK_ERROR_PTR();
	check_sljit_emit_const(compiler, dst, dstw, init_value);

	const_ = (struct sljit_const*)ensure_abuf(compiler, sizeof(struct sljit_const));
	PTR_FAIL_IF(!const_);
	set_const(const_, compiler);

	dst_r = (dst >= SLJIT_TEMPORARY_REG1 && dst <= SLJIT_NO_REGISTERS) ? dst : TMP_REG1;
	PTR_FAIL_IF(emit_imm32_const(compiler, dst_r, init_value));

	if (dst & SLJIT_MEM)
		PTR_FAIL_IF(emit_op_mem(compiler, WORD_SIZE | STORE, dst_r, dst, dstw));
	return const_;
}

SLJIT_API_FUNC_ATTRIBUTE void sljit_set_jump_addr(sljit_uw addr, sljit_uw new_addr)
{
	inline_set_jump_addr(addr, new_addr, 1);
}

SLJIT_API_FUNC_ATTRIBUTE void sljit_set_const(sljit_uw addr, sljit_w new_constant)
{
	sljit_uh* inst = (sljit_uh*)addr;
	modify_imm32_const(inst, new_constant);
	SLJIT_CACHE_FLUSH(inst, inst + 3);
}
