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
#if (defined SLJIT_CONFIG_ARM_V7 && SLJIT_CONFIG_ARM_V7)
	return "arm-v7";
#elif (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	return "arm-v5";
#else
#error "Internal error: Unknown ARM architecture"
#endif
}

/* Last register + 1. */
#define TMP_REG1	(SLJIT_NO_REGISTERS + 1)
#define TMP_REG2	(SLJIT_NO_REGISTERS + 2)
#define TMP_REG3	(SLJIT_NO_REGISTERS + 3)
#define TMP_PC		(SLJIT_NO_REGISTERS + 4)

#define TMP_FREG1	(SLJIT_FLOAT_REG4 + 1)
#define TMP_FREG2	(SLJIT_FLOAT_REG4 + 2)

/* In ARM instruction words.
   Cache lines are usually 32 byte aligned. */
#define CONST_POOL_ALIGNMENT	8
#define CONST_POOL_EMPTY	0xffffffff

#define ALIGN_INSTRUCTION(ptr) \
	(sljit_uw*)(((sljit_uw)(ptr) + (CONST_POOL_ALIGNMENT * sizeof(sljit_uw)) - 1) & ~((CONST_POOL_ALIGNMENT * sizeof(sljit_uw)) - 1))
#define MAX_DIFFERENCE(max_diff) \
	(((max_diff) / (int)sizeof(sljit_uw)) - (CONST_POOL_ALIGNMENT - 1))

/* See sljit_emit_enter if you want to change them. */
static SLJIT_CONST sljit_ub reg_map[SLJIT_NO_REGISTERS + 5] = {
  0, 0, 1, 2, 10, 11, 4, 5, 6, 7, 8, 13, 3, 12, 14, 15
};

#define RM(rm) (reg_map[rm])
#define RD(rd) (reg_map[rd] << 12)
#define RN(rn) (reg_map[rn] << 16)

/* --------------------------------------------------------------------- */
/*  Instrucion forms                                                     */
/* --------------------------------------------------------------------- */

/* The instruction includes the AL condition.
   INST_NAME - CONDITIONAL remove this flag. */
#define COND_MASK	0xf0000000
#define CONDITIONAL	0xe0000000
#define PUSH_POOL	0xff000000

/* DP - Data Processing instruction (use with EMIT_DATA_PROCESS_INS). */
#define ADC_DP		0x5
#define ADD_DP		0x4
#define AND_DP		0x0
#define B		0xea000000
#define BIC_DP		0xe
#define BL		0xeb000000
#define BLX		0xe12fff30
#define BX		0xe12fff10
#define CLZ		0xe16f0f10
#define CMP_DP		0xa
#define DEBUGGER	0xe1200070
#define EOR_DP		0x1
#define MOV_DP		0xd
#define MUL		0xe0000090
#define MVN_DP		0xf
#define NOP		0xe1a00000
#define ORR_DP		0xc
#define PUSH		0xe92d0000
#define POP		0xe8bd0000
#define RSB_DP		0x3
#define RSC_DP		0x7
#define SBC_DP		0x6
#define SMULL		0xe0c00090
#define SUB_DP		0x2
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

#if (defined SLJIT_CONFIG_ARM_V7 && SLJIT_CONFIG_ARM_V7)
/* Arm v7 specific instructions. */
#define MOVW		0xe3000000
#define MOVT		0xe3400000
#define SXTB		0xe6af0070
#define SXTH		0xe6bf0070
#define UXTB		0xe6ef0070
#define UXTH		0xe6ff0070
#endif

#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)

static int push_cpool(struct sljit_compiler *compiler)
{
	/* Pushing the constant pool into the instruction stream. */
	sljit_uw* inst;
	sljit_uw* cpool_ptr;
	sljit_uw* cpool_end;
	int i;

	/* The label could point the address after the constant pool. */
	if (compiler->last_label && compiler->last_label->size == compiler->size)
		compiler->last_label->size += compiler->cpool_fill + (CONST_POOL_ALIGNMENT - 1) + 1;

	SLJIT_ASSERT(compiler->cpool_fill > 0 && compiler->cpool_fill <= CPOOL_SIZE);
	inst = (sljit_uw*)ensure_buf(compiler, sizeof(sljit_uw));
	FAIL_IF(!inst);
	compiler->size++;
	*inst = 0xff000000 | compiler->cpool_fill;

	for (i = 0; i < CONST_POOL_ALIGNMENT - 1; i++) {
		inst = (sljit_uw*)ensure_buf(compiler, sizeof(sljit_uw));
		FAIL_IF(!inst);
		compiler->size++;
		*inst = 0;
	}

	cpool_ptr = compiler->cpool;
	cpool_end = cpool_ptr + compiler->cpool_fill;
	while (cpool_ptr < cpool_end) {
		inst = (sljit_uw*)ensure_buf(compiler, sizeof(sljit_uw));
		FAIL_IF(!inst);
		compiler->size++;
		*inst = *cpool_ptr++;
	}
	compiler->cpool_diff = CONST_POOL_EMPTY;
	compiler->cpool_fill = 0;
	return SLJIT_SUCCESS;
}

static int push_inst(struct sljit_compiler *compiler, sljit_uw inst)
{
	sljit_uw* ptr;

	if (SLJIT_UNLIKELY(compiler->cpool_diff != CONST_POOL_EMPTY && compiler->size - compiler->cpool_diff >= MAX_DIFFERENCE(4092)))
		FAIL_IF(push_cpool(compiler));

	ptr = (sljit_uw*)ensure_buf(compiler, sizeof(sljit_uw));
	FAIL_IF(!ptr);
	compiler->size++;
	*ptr = inst;
	return SLJIT_SUCCESS;
}

static int push_inst_with_literal(struct sljit_compiler *compiler, sljit_uw inst, sljit_uw literal)
{
	sljit_uw* ptr;
	sljit_uw cpool_index = CPOOL_SIZE;
	sljit_uw* cpool_ptr;
	sljit_uw* cpool_end;
	sljit_ub* cpool_unique_ptr;

	if (SLJIT_UNLIKELY(compiler->cpool_diff != CONST_POOL_EMPTY && compiler->size - compiler->cpool_diff >= MAX_DIFFERENCE(4092)))
		FAIL_IF(push_cpool(compiler));
	else if (compiler->cpool_fill > 0) {
		cpool_ptr = compiler->cpool;
		cpool_end = cpool_ptr + compiler->cpool_fill;
		cpool_unique_ptr = compiler->cpool_unique;
		do {
			if ((*cpool_ptr == literal) && !(*cpool_unique_ptr)) {
				cpool_index = cpool_ptr - compiler->cpool;
				break;
			}
			cpool_ptr++;
			cpool_unique_ptr++;
		} while (cpool_ptr < cpool_end);
	}

	if (cpool_index == CPOOL_SIZE) {
		/* Must allocate a new entry in the literal pool. */
		if (compiler->cpool_fill < CPOOL_SIZE) {
			cpool_index = compiler->cpool_fill;
			compiler->cpool_fill++;
		}
		else {
			FAIL_IF(push_cpool(compiler));
			cpool_index = 0;
			compiler->cpool_fill = 1;
		}
	}

	SLJIT_ASSERT((inst & 0xfff) == 0);
	ptr = (sljit_uw*)ensure_buf(compiler, sizeof(sljit_uw));
	FAIL_IF(!ptr);
	compiler->size++;
	*ptr = inst | cpool_index;

	compiler->cpool[cpool_index] = literal;
	compiler->cpool_unique[cpool_index] = 0;
	if (compiler->cpool_diff == CONST_POOL_EMPTY)
		compiler->cpool_diff = compiler->size;
	return SLJIT_SUCCESS;
}

static int push_inst_with_unique_literal(struct sljit_compiler *compiler, sljit_uw inst, sljit_uw literal)
{
	sljit_uw* ptr;
	if (SLJIT_UNLIKELY((compiler->cpool_diff != CONST_POOL_EMPTY && compiler->size - compiler->cpool_diff >= MAX_DIFFERENCE(4092)) || compiler->cpool_fill >= CPOOL_SIZE))
		FAIL_IF(push_cpool(compiler));

	SLJIT_ASSERT(compiler->cpool_fill < CPOOL_SIZE && (inst & 0xfff) == 0);
	ptr = (sljit_uw*)ensure_buf(compiler, sizeof(sljit_uw));
	FAIL_IF(!ptr);
	compiler->size++;
	*ptr = inst | compiler->cpool_fill;

	compiler->cpool[compiler->cpool_fill] = literal;
	compiler->cpool_unique[compiler->cpool_fill] = 1;
	compiler->cpool_fill++;
	if (compiler->cpool_diff == CONST_POOL_EMPTY)
		compiler->cpool_diff = compiler->size;
	return SLJIT_SUCCESS;
}

static SLJIT_INLINE int prepare_blx(struct sljit_compiler *compiler)
{
	/* Place for at least two instruction (doesn't matter whether the first has a literal). */
	if (SLJIT_UNLIKELY(compiler->cpool_diff != CONST_POOL_EMPTY && compiler->size - compiler->cpool_diff >= MAX_DIFFERENCE(4088)))
		return push_cpool(compiler);
	return SLJIT_SUCCESS;
}

static SLJIT_INLINE int emit_blx(struct sljit_compiler *compiler)
{
	/* Must follow tightly the previous instruction (to be able to convert it to bl instruction). */
	SLJIT_ASSERT(compiler->cpool_diff == CONST_POOL_EMPTY || compiler->size - compiler->cpool_diff < MAX_DIFFERENCE(4092));
	return push_inst(compiler, BLX | RM(TMP_REG1));
}

static sljit_uw patch_pc_relative_loads(sljit_uw *last_pc_patch, sljit_uw *code_ptr, sljit_uw* const_pool, sljit_uw cpool_size)
{
	sljit_uw diff;
	sljit_uw ind;
	sljit_uw counter = 0;
	sljit_uw* clear_const_pool = const_pool;
	sljit_uw* clear_const_pool_end = const_pool + cpool_size;

	SLJIT_ASSERT(const_pool - code_ptr <= CONST_POOL_ALIGNMENT);
	/* Set unused flag for all literals in the constant pool.
	   I.e.: unused literals can belong to branches, which can be encoded as B or BL.
	   We can "compress" the constant pool by discarding these literals. */
	while (clear_const_pool < clear_const_pool_end)
		*clear_const_pool++ = (sljit_uw)(-1);

	while (last_pc_patch < code_ptr) {
		/* Data transfer instruction with Rn == r15. */
		if ((*last_pc_patch & 0x0c0f0000) == 0x040f0000) {
			diff = const_pool - last_pc_patch;
			ind = (*last_pc_patch) & 0xfff;

			/* Must be a load instruction with immediate offset. */
			SLJIT_ASSERT(ind < cpool_size && !(*last_pc_patch & (1 << 25)) && (*last_pc_patch & (1 << 20)));
			if ((int)const_pool[ind] < 0) {
				const_pool[ind] = counter;
				ind = counter;
				counter++;
			}
			else
				ind = const_pool[ind];

			SLJIT_ASSERT(diff >= 1);
			if (diff >= 2 || ind > 0) {
				diff = (diff + ind - 2) << 2;
				SLJIT_ASSERT(diff <= 0xfff);
				*last_pc_patch = (*last_pc_patch & ~0xfff) | diff;
			}
			else
				*last_pc_patch = (*last_pc_patch & ~(0xfff | (1 << 23))) | 0x004;
		}
		last_pc_patch++;
	}
	return counter;
}

/* In some rare ocasions we may need future patches. The probability is close to 0 in practice. */
struct future_patch {
	struct future_patch* next;
	int index;
	int value;
};

static SLJIT_INLINE int resolve_const_pool_index(struct future_patch **first_patch, sljit_uw cpool_current_index, sljit_uw *cpool_start_address, sljit_uw *buf_ptr)
{
	int value;
	struct future_patch *curr_patch, *prev_patch;

	/* Using the values generated by patch_pc_relative_loads. */
	if (!*first_patch)
		value = (int)cpool_start_address[cpool_current_index];
	else {
		curr_patch = *first_patch;
		prev_patch = 0;
		while (1) {
			if (!curr_patch) {
				value = (int)cpool_start_address[cpool_current_index];
				break;
			}
			if ((sljit_uw)curr_patch->index == cpool_current_index) {
				value = curr_patch->value;
				if (prev_patch)
					prev_patch->next = curr_patch->next;
				else
					*first_patch = curr_patch->next;
				SLJIT_FREE(curr_patch);
				break;
			}
			prev_patch = curr_patch;
			curr_patch = curr_patch->next;
		}
	}

	if (value >= 0) {
		if ((sljit_uw)value > cpool_current_index) {
			curr_patch = (struct future_patch*)SLJIT_MALLOC(sizeof(struct future_patch));
			if (!curr_patch) {
				while (*first_patch) {
					curr_patch = *first_patch;
					*first_patch = (*first_patch)->next;
					SLJIT_FREE(curr_patch);
				}
				return SLJIT_ERR_ALLOC_FAILED;
			}
			curr_patch->next = *first_patch;
			curr_patch->index = value;
			curr_patch->value = cpool_start_address[value];
			*first_patch = curr_patch;
		}
		cpool_start_address[value] = *buf_ptr;
	}
	return SLJIT_SUCCESS;
}

#else

static int push_inst(struct sljit_compiler *compiler, sljit_uw inst)
{
	sljit_uw* ptr;

	ptr = (sljit_uw*)ensure_buf(compiler, sizeof(sljit_uw));
	FAIL_IF(!ptr);
	compiler->size++;
	*ptr = inst;
	return SLJIT_SUCCESS;
}

static SLJIT_INLINE int emit_imm(struct sljit_compiler *compiler, int reg, sljit_w imm)
{
	FAIL_IF(push_inst(compiler, MOVW | RD(reg) | ((imm << 4) & 0xf0000) | (imm & 0xfff)));
	return push_inst(compiler, MOVT | RD(reg) | ((imm >> 12) & 0xf0000) | ((imm >> 16) & 0xfff));
}

#endif

static SLJIT_INLINE int detect_jump_type(struct sljit_jump *jump, sljit_uw *code_ptr, sljit_uw *code)
{
	sljit_w diff;

	if (jump->flags & SLJIT_REWRITABLE_JUMP)
		return 0;

#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	if (jump->flags & IS_BL)
		code_ptr--;

	if (jump->flags & JUMP_ADDR)
		diff = ((sljit_w)jump->u.target - (sljit_w)(code_ptr + 2));
	else {
		SLJIT_ASSERT(jump->flags & JUMP_LABEL);
		diff = ((sljit_w)(code + jump->u.label->size) - (sljit_w)(code_ptr + 2));
	}

	/* Branch to Thumb code has not been optimized yet. */
	if (diff & 0x3)
		return 0;

	diff >>= 2;
	if (jump->flags & IS_BL) {
		if (diff <= 0x01ffffff && diff >= -0x02000000) {
			*code_ptr = (BL - CONDITIONAL) | (*(code_ptr + 1) & COND_MASK);
			jump->flags |= PATCH_B;
			return 1;
		}
	}
	else {
		if (diff <= 0x01ffffff && diff >= -0x02000000) {
			*code_ptr = (B - CONDITIONAL) | (*code_ptr & COND_MASK);
			jump->flags |= PATCH_B;
		}
	}
#else
	if (jump->flags & JUMP_ADDR)
		diff = ((sljit_w)jump->u.target - (sljit_w)code_ptr);
	else {
		SLJIT_ASSERT(jump->flags & JUMP_LABEL);
		diff = ((sljit_w)(code + jump->u.label->size) - (sljit_w)code_ptr);
	}

	/* Branch to Thumb code has not been optimized yet. */
	if (diff & 0x3)
		return 0;

	diff >>= 2;
	if (diff <= 0x01ffffff && diff >= -0x02000000) {
		code_ptr -= 2;
		*code_ptr = ((jump->flags & IS_BL) ? (BL - CONDITIONAL) : (B - CONDITIONAL)) | (code_ptr[2] & COND_MASK);
		jump->flags |= PATCH_B;
		return 1;
	}
#endif
	return 0;
}

static SLJIT_INLINE void inline_set_jump_addr(sljit_uw addr, sljit_uw new_addr, int flush)
{
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	sljit_uw *ptr = (sljit_uw*)addr;
	sljit_uw *inst = (sljit_uw*)ptr[0];
	sljit_uw mov_pc = ptr[1];
	int bl = (mov_pc & 0x0000f000) != RD(TMP_PC);
	sljit_w diff = (sljit_w)(((sljit_w)new_addr - (sljit_w)(inst + 2)) >> 2);

	if (diff <= 0x7fffff && diff >= -0x800000) {
		/* Turn to branch. */
		if (!bl) {
			inst[0] = (mov_pc & COND_MASK) | (B - CONDITIONAL) | (diff & 0xffffff);
			if (flush) {
				SLJIT_CACHE_FLUSH(inst, inst + 1);
			}
		} else {
			inst[0] = (mov_pc & COND_MASK) | (BL - CONDITIONAL) | (diff & 0xffffff);
			inst[1] = NOP;
			if (flush) {
				SLJIT_CACHE_FLUSH(inst, inst + 2);
			}
		}
	} else {
		/* Get the position of the constant. */
		if (mov_pc & (1 << 23))
			ptr = inst + ((mov_pc & 0xfff) >> 2) + 2;
		else
			ptr = inst + 1;

		if (*inst != mov_pc) {
			inst[0] = mov_pc;
			if (!bl) {
				if (flush) {
					SLJIT_CACHE_FLUSH(inst, inst + 1);
				}
			} else {
				inst[1] = BLX | RM(TMP_REG1);
				if (flush) {
					SLJIT_CACHE_FLUSH(inst, inst + 2);
				}
			}
		}
		*ptr = new_addr;
	}
#else
	sljit_uw *inst = (sljit_uw*)addr;
	SLJIT_ASSERT((inst[0] & 0xfff00000) == MOVW && (inst[1] & 0xfff00000) == MOVT);
	inst[0] = MOVW | (inst[0] & 0xf000) | ((new_addr << 4) & 0xf0000) | (new_addr & 0xfff);
	inst[1] = MOVT | (inst[1] & 0xf000) | ((new_addr >> 12) & 0xf0000) | ((new_addr >> 16) & 0xfff);
	if (flush) {
		SLJIT_CACHE_FLUSH(inst, inst + 2);
	}
#endif
}

static sljit_uw get_immediate(sljit_uw imm);

static SLJIT_INLINE void inline_set_const(sljit_uw addr, sljit_w new_constant, int flush)
{
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	sljit_uw *ptr = (sljit_uw*)addr;
	sljit_uw *inst = (sljit_uw*)ptr[0];
	sljit_uw ldr_literal = ptr[1];
	sljit_uw src2;

	src2 = get_immediate(new_constant);
	if (src2) {
		*inst = 0xe3a00000 | (ldr_literal & 0xf000) | src2;
		if (flush) {
			SLJIT_CACHE_FLUSH(inst, inst + 1);
		}
		return;
	}

	src2 = get_immediate(~new_constant);
	if (src2) {
		*inst = 0xe3e00000 | (ldr_literal & 0xf000) | src2;
		if (flush) {
			SLJIT_CACHE_FLUSH(inst, inst + 1);
		}
		return;
	}

	if (ldr_literal & (1 << 23))
		ptr = inst + ((ldr_literal & 0xfff) >> 2) + 2;
	else
		ptr = inst + 1;

	if (*inst != ldr_literal) {
		*inst = ldr_literal;
		if (flush) {
			SLJIT_CACHE_FLUSH(inst, inst + 1);
		}
	}
	*ptr = new_constant;
#else
	sljit_uw *inst = (sljit_uw*)addr;
	SLJIT_ASSERT((inst[0] & 0xfff00000) == MOVW && (inst[1] & 0xfff00000) == MOVT);
	inst[0] = MOVW | (inst[0] & 0xf000) | ((new_constant << 4) & 0xf0000) | (new_constant & 0xfff);
	inst[1] = MOVT | (inst[1] & 0xf000) | ((new_constant >> 12) & 0xf0000) | ((new_constant >> 16) & 0xfff);
	if (flush) {
		SLJIT_CACHE_FLUSH(inst, inst + 2);
	}
#endif
}

SLJIT_API_FUNC_ATTRIBUTE void* sljit_generate_code(struct sljit_compiler *compiler)
{
	struct sljit_memory_fragment *buf;
	sljit_uw *code;
	sljit_uw *code_ptr;
	sljit_uw *buf_ptr;
	sljit_uw *buf_end;
	sljit_uw size;
	sljit_uw word_count;
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	sljit_uw cpool_size;
	sljit_uw cpool_skip_alignment;
	sljit_uw cpool_current_index;
	sljit_uw *cpool_start_address;
	sljit_uw *last_pc_patch;
	struct future_patch *first_patch;
#endif

	struct sljit_label *label;
	struct sljit_jump *jump;
	struct sljit_const *const_;

	CHECK_ERROR_PTR();
	check_sljit_generate_code(compiler);
	reverse_buf(compiler);

	/* Second code generation pass. */
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	size = compiler->size + (compiler->patches << 1);
	if (compiler->cpool_fill > 0)
		size += compiler->cpool_fill + CONST_POOL_ALIGNMENT - 1;
#else
	size = compiler->size;
#endif
	code = (sljit_uw*)SLJIT_MALLOC_EXEC(size * sizeof(sljit_uw));
	PTR_FAIL_WITH_EXEC_IF(code);
	buf = compiler->buf;

#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	cpool_size = 0;
	cpool_skip_alignment = 0;
	cpool_current_index = 0;
	cpool_start_address = NULL;
	first_patch = NULL;
	last_pc_patch = code;
#endif

	code_ptr = code;
	word_count = 0;

	label = compiler->labels;
	jump = compiler->jumps;
	const_ = compiler->consts;

	if (label && label->size == 0) {
		label->addr = (sljit_uw)code;
		label->size = 0;
		label = label->next;
	}

	do {
		buf_ptr = (sljit_uw*)buf->memory;
		buf_end = buf_ptr + (buf->used_size >> 2);
		do {
			word_count++;
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
			if (cpool_size > 0) {
				if (cpool_skip_alignment > 0) {
					buf_ptr++;
					cpool_skip_alignment--;
				}
				else {
					if (SLJIT_UNLIKELY(resolve_const_pool_index(&first_patch, cpool_current_index, cpool_start_address, buf_ptr))) {
						SLJIT_FREE_EXEC(code);
						compiler->error = SLJIT_ERR_ALLOC_FAILED;
						return NULL;
					}
					buf_ptr++;
					if (++cpool_current_index >= cpool_size) {
						SLJIT_ASSERT(!first_patch);
						cpool_size = 0;
						if (label && label->size == word_count) {
							/* Points after the current instruction. */
							label->addr = (sljit_uw)code_ptr;
							label->size = code_ptr - code;
							label = label->next;
						}
					}
				}
			}
			else if ((*buf_ptr & 0xff000000) != PUSH_POOL) {
#endif
				*code_ptr = *buf_ptr++;
				/* These structures are ordered by their address. */
				SLJIT_ASSERT(!label || label->size >= word_count);
				SLJIT_ASSERT(!jump || jump->addr >= word_count);
				SLJIT_ASSERT(!const_ || const_->addr >= word_count);
				if (jump && jump->addr == word_count) {
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
					if (detect_jump_type(jump, code_ptr, code))
						code_ptr--;
					jump->addr = (sljit_uw)code_ptr;
#else
					jump->addr = (sljit_uw)(code_ptr - 2);
					if (detect_jump_type(jump, code_ptr, code))
						code_ptr -= 2;
#endif
					jump = jump->next;
				}
				if (label && label->size == word_count) {
					/* code_ptr can be affected above. */
					label->addr = (sljit_uw)(code_ptr + 1);
					label->size = (code_ptr + 1) - code;
					label = label->next;
				}
				if (const_ && const_->addr == word_count) {
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
					const_->addr = (sljit_uw)code_ptr;
#else
					const_->addr = (sljit_uw)(code_ptr - 1);
#endif
					const_ = const_->next;
				}
				code_ptr++;
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
			}
			else {
				/* Fortunately, no need to shift. */
				cpool_size = *buf_ptr++ & ~PUSH_POOL;
				SLJIT_ASSERT(cpool_size > 0);
				cpool_start_address = ALIGN_INSTRUCTION(code_ptr + 1);
				cpool_current_index = patch_pc_relative_loads(last_pc_patch, code_ptr, cpool_start_address, cpool_size);
				if (cpool_current_index > 0) {
					/* Unconditional branch. */
					*code_ptr = B | (((cpool_start_address - code_ptr) + cpool_current_index - 2) & ~PUSH_POOL);
					code_ptr = cpool_start_address + cpool_current_index;
				}
				cpool_skip_alignment = CONST_POOL_ALIGNMENT - 1;
				cpool_current_index = 0;
				last_pc_patch = code_ptr;
			}
#endif
		} while (buf_ptr < buf_end);
		buf = buf->next;
	} while (buf);

	SLJIT_ASSERT(!label);
	SLJIT_ASSERT(!jump);
	SLJIT_ASSERT(!const_);

#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	SLJIT_ASSERT(cpool_size == 0);
	if (compiler->cpool_fill > 0) {
		cpool_start_address = ALIGN_INSTRUCTION(code_ptr);
		cpool_current_index = patch_pc_relative_loads(last_pc_patch, code_ptr, cpool_start_address, compiler->cpool_fill);
		if (cpool_current_index > 0)
			code_ptr = cpool_start_address + cpool_current_index;

		buf_ptr = compiler->cpool;
		buf_end = buf_ptr + compiler->cpool_fill;
		cpool_current_index = 0;
		while (buf_ptr < buf_end) {
			if (SLJIT_UNLIKELY(resolve_const_pool_index(&first_patch, cpool_current_index, cpool_start_address, buf_ptr))) {
				SLJIT_FREE_EXEC(code);
				compiler->error = SLJIT_ERR_ALLOC_FAILED;
				return NULL;
			}
			buf_ptr++;
			cpool_current_index++;
		}
		SLJIT_ASSERT(!first_patch);
	}
#endif

	jump = compiler->jumps;
	while (jump) {
		buf_ptr = (sljit_uw*)jump->addr;

		if (jump->flags & PATCH_B) {
			if (!(jump->flags & JUMP_ADDR)) {
				SLJIT_ASSERT(jump->flags & JUMP_LABEL);
				SLJIT_ASSERT(((sljit_w)jump->u.label->addr - (sljit_w)(buf_ptr + 2)) <= 0x01ffffff && ((sljit_w)jump->u.label->addr - (sljit_w)(buf_ptr + 2)) >= -0x02000000);
				*buf_ptr |= (((sljit_w)jump->u.label->addr - (sljit_w)(buf_ptr + 2)) >> 2) & 0x00ffffff;
			}
			else {
				SLJIT_ASSERT(((sljit_w)jump->u.target - (sljit_w)(buf_ptr + 2)) <= 0x01ffffff && ((sljit_w)jump->u.target - (sljit_w)(buf_ptr + 2)) >= -0x02000000);
				*buf_ptr |= (((sljit_w)jump->u.target - (sljit_w)(buf_ptr + 2)) >> 2) & 0x00ffffff;
			}
		}
		else if (jump->flags & SLJIT_REWRITABLE_JUMP) {
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
			jump->addr = (sljit_uw)code_ptr;
			code_ptr[0] = (sljit_uw)buf_ptr;
			code_ptr[1] = *buf_ptr;
			inline_set_jump_addr((sljit_uw)code_ptr, (jump->flags & JUMP_LABEL) ? jump->u.label->addr : jump->u.target, 0);
			code_ptr += 2;
#else
			inline_set_jump_addr((sljit_uw)buf_ptr, (jump->flags & JUMP_LABEL) ? jump->u.label->addr : jump->u.target, 0);
#endif
		}
		else {
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
			if (jump->flags & IS_BL)
				buf_ptr--;
			if (*buf_ptr & (1 << 23))
				buf_ptr += ((*buf_ptr & 0xfff) >> 2) + 2;
			else
				buf_ptr += 1;
			*buf_ptr = (jump->flags & JUMP_LABEL) ? jump->u.label->addr : jump->u.target;
#else
			inline_set_jump_addr((sljit_uw)buf_ptr, (jump->flags & JUMP_LABEL) ? jump->u.label->addr : jump->u.target, 0);
#endif
		}
		jump = jump->next;
	}

#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	const_ = compiler->consts;
	while (const_) {
		buf_ptr = (sljit_uw*)const_->addr;
		const_->addr = (sljit_uw)code_ptr;

		code_ptr[0] = (sljit_uw)buf_ptr;
		code_ptr[1] = *buf_ptr;
		if (*buf_ptr & (1 << 23))
			buf_ptr += ((*buf_ptr & 0xfff) >> 2) + 2;
		else
			buf_ptr += 1;
		/* Set the value again (can be a simple constant). */
		inline_set_const((sljit_uw)code_ptr, *buf_ptr, 0);
		code_ptr += 2;

		const_ = const_->next;
	}
#endif

	SLJIT_ASSERT(code_ptr - code <= (int)size);

	SLJIT_CACHE_FLUSH(code, code_ptr);
	compiler->error = SLJIT_ERR_COMPILED;
	compiler->executable_size = size * sizeof(sljit_uw);
	return code;
}

/* emit_op inp_flags.
   WRITE_BACK must be the first, since it is a flag. */
#define WRITE_BACK	0x01
#define ALLOW_IMM	0x02
#define ALLOW_INV_IMM	0x04
#define ALLOW_ANY_IMM	(ALLOW_IMM | ALLOW_INV_IMM)
#define ARG_TEST	0x08

/* Creates an index in data_transfer_insts array. */
#define WORD_DATA	0x00
#define BYTE_DATA	0x10
#define HALF_DATA	0x20
#define SIGNED_DATA	0x40
#define LOAD_DATA	0x80

#define EMIT_INSTRUCTION(inst) \
	FAIL_IF(push_inst(compiler, (inst)))

/* Condition: AL. */
#define EMIT_DATA_PROCESS_INS(opcode, set_flags, dst, src1, src2) \
	(0xe0000000 | ((opcode) << 21) | (set_flags) | RD(dst) | RN(src1) | (src2))

static int emit_op(struct sljit_compiler *compiler, int op, int inp_flags,
	int dst, sljit_w dstw,
	int src1, sljit_w src1w,
	int src2, sljit_w src2w);

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_enter(struct sljit_compiler *compiler, int args, int temporaries, int generals, int local_size)
{
	int size;
	sljit_uw push;

	CHECK_ERROR();
	check_sljit_emit_enter(compiler, args, temporaries, generals, local_size);

	compiler->temporaries = temporaries;
	compiler->generals = generals;

	/* Push general registers, temporary registers
	   stmdb sp!, {..., lr} */
	push = PUSH | (1 << 14);
	if (temporaries >= 5)
		push |= 1 << 11;
	if (temporaries >= 4)
		push |= 1 << 10;
	if (generals >= 5)
		push |= 1 << 8;
	if (generals >= 4)
		push |= 1 << 7;
	if (generals >= 3)
		push |= 1 << 6;
	if (generals >= 2)
		push |= 1 << 5;
	if (generals >= 1)
		push |= 1 << 4;
	EMIT_INSTRUCTION(push);

	/* Stack must be aligned to 8 bytes: */
	size = (1 + generals) * sizeof(sljit_uw);
	if (temporaries >= 4)
		size += (temporaries - 3) * sizeof(sljit_uw);
	local_size += size;
	local_size = (local_size + 7) & ~7;
	local_size -= size;
	compiler->local_size = local_size;
	if (local_size > 0)
		FAIL_IF(emit_op(compiler, SLJIT_SUB, ALLOW_IMM, SLJIT_LOCALS_REG, 0, SLJIT_LOCALS_REG, 0, SLJIT_IMM, local_size));

	if (args >= 1)
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, SLJIT_GENERAL_REG1, SLJIT_UNUSED, RM(SLJIT_TEMPORARY_REG1)));
	if (args >= 2)
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, SLJIT_GENERAL_REG2, SLJIT_UNUSED, RM(SLJIT_TEMPORARY_REG2)));
	if (args >= 3)
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, SLJIT_GENERAL_REG3, SLJIT_UNUSED, RM(SLJIT_TEMPORARY_REG3)));

	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE void sljit_fake_enter(struct sljit_compiler *compiler, int args, int temporaries, int generals, int local_size)
{
	int size;

	CHECK_ERROR_VOID();
	check_sljit_fake_enter(compiler, args, temporaries, generals, local_size);

	compiler->temporaries = temporaries;
	compiler->generals = generals;

	size = (1 + generals) * sizeof(sljit_uw);
	if (temporaries >= 4)
		size += (temporaries - 3) * sizeof(sljit_uw);
	local_size += size;
	local_size = (local_size + 7) & ~7;
	local_size -= size;
	compiler->local_size = local_size;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_return(struct sljit_compiler *compiler, int src, sljit_w srcw)
{
	sljit_uw pop;

	CHECK_ERROR();
	check_sljit_emit_return(compiler, src, srcw);

	if (src != SLJIT_UNUSED && src != SLJIT_RETURN_REG)
		FAIL_IF(emit_op(compiler, SLJIT_MOV, ALLOW_ANY_IMM, SLJIT_RETURN_REG, 0, TMP_REG1, 0, src, srcw));

	if (compiler->local_size > 0)
		FAIL_IF(emit_op(compiler, SLJIT_ADD, ALLOW_IMM, SLJIT_LOCALS_REG, 0, SLJIT_LOCALS_REG, 0, SLJIT_IMM, compiler->local_size));

	pop = POP | (1 << 15);
	/* Push general registers, temporary registers
	   ldmia sp!, {..., pc} */
	if (compiler->temporaries >= 5)
		pop |= 1 << 11;
	if (compiler->temporaries >= 4)
		pop |= 1 << 10;
	if (compiler->generals >= 5)
		pop |= 1 << 8;
	if (compiler->generals >= 4)
		pop |= 1 << 7;
	if (compiler->generals >= 3)
		pop |= 1 << 6;
	if (compiler->generals >= 2)
		pop |= 1 << 5;
	if (compiler->generals >= 1)
		pop |= 1 << 4;

	return push_inst(compiler, pop);
}

/* --------------------------------------------------------------------- */
/*  Operators                                                            */
/* --------------------------------------------------------------------- */

/* s/l - store/load (1 bit)
   u/s - signed/unsigned (1 bit)
   w/b/h/N - word/byte/half/NOT allowed (2 bit)
   It contans 16 items, but not all are different. */

static sljit_w data_transfer_insts[16] = {
/* s u w */ 0xe5000000 /* str */,
/* s u b */ 0xe5400000 /* strb */,
/* s u h */ 0xe10000b0 /* strh */,
/* s u N */ 0x00000000 /* not allowed */,
/* s s w */ 0xe5000000 /* str */,
/* s s b */ 0xe5400000 /* strb */,
/* s s h */ 0xe10000b0 /* strh */,
/* s s N */ 0x00000000 /* not allowed */,

/* l u w */ 0xe5100000 /* ldr */,
/* l u b */ 0xe5500000 /* ldrb */,
/* l u h */ 0xe11000b0 /* ldrh */,
/* l u N */ 0x00000000 /* not allowed */,
/* l s w */ 0xe5100000 /* ldr */,
/* l s b */ 0xe11000d0 /* ldrsb */,
/* l s h */ 0xe11000f0 /* ldrsh */,
/* l s N */ 0x00000000 /* not allowed */,
};

#define EMIT_DATA_TRANSFER(type, add, wb, target, base1, base2) \
	(data_transfer_insts[(type) >> 4] | ((add) << 23) | ((wb) << 21) | (reg_map[target] << 12) | (reg_map[base1] << 16) | (base2))
/* Normal ldr/str instruction.
   Type2: ldrsb, ldrh, ldrsh */
#define IS_TYPE1_TRANSFER(type) \
	(data_transfer_insts[(type) >> 4] & 0x04000000)
#define TYPE2_TRANSFER_IMM(imm) \
	(((imm) & 0xf) | (((imm) & 0xf0) << 4) | (1 << 22))

/* flags: */
  /* Arguments are swapped. */
#define ARGS_SWAPPED	0x01
  /* Inverted immediate. */
#define INV_IMM		0x02
  /* Source and destination is register. */
#define REG_DEST	0x04
#define REG_SOURCE	0x08
  /* One instruction is enough. */
#define FAST_DEST	0x10
  /* Multiple instructions are required. */
#define SLOW_DEST	0x20
/* SET_FLAGS must be (1 << 20) as it is also the value of S bit (can be used for optimization). */
#define SET_FLAGS	(1 << 20)
/* dst: reg
   src1: reg
   src2: reg or imm (if allowed)
   SRC2_IMM must be (1 << 25) as it is also the value of I bit (can be used for optimization). */
#define SRC2_IMM	(1 << 25)

#define EMIT_DATA_PROCESS_INS_AND_RETURN(opcode) \
	return push_inst(compiler, EMIT_DATA_PROCESS_INS(opcode, flags & SET_FLAGS, dst, src1, (src2 & SRC2_IMM) ? src2 : RM(src2)))

#define EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(opcode, dst, src1, src2) \
	return push_inst(compiler, EMIT_DATA_PROCESS_INS(opcode, flags & SET_FLAGS, dst, src1, src2))

#define EMIT_SHIFT_INS_AND_RETURN(opcode) \
	SLJIT_ASSERT(!(flags & INV_IMM) && !(src2 & SRC2_IMM)); \
	if (compiler->shift_imm != 0x20) { \
		SLJIT_ASSERT(src1 == TMP_REG1); \
		SLJIT_ASSERT(!(flags & ARGS_SWAPPED)); \
		return push_inst(compiler, EMIT_DATA_PROCESS_INS(MOV_DP, flags & SET_FLAGS, dst, SLJIT_UNUSED, (compiler->shift_imm << 7) | (opcode << 5) | reg_map[src2])); \
	} \
	return push_inst(compiler, EMIT_DATA_PROCESS_INS(MOV_DP, flags & SET_FLAGS, dst, SLJIT_UNUSED, (reg_map[(flags & ARGS_SWAPPED) ? src1 : src2] << 8) | (opcode << 5) | 0x10 | ((flags & ARGS_SWAPPED) ? reg_map[src2] : reg_map[src1])));

static SLJIT_INLINE int emit_single_op(struct sljit_compiler *compiler, int op, int flags,
	int dst, int src1, int src2)
{
	sljit_w mul_inst;

	switch (GET_OPCODE(op)) {
	case SLJIT_ADD:
		SLJIT_ASSERT(!(flags & INV_IMM));
		EMIT_DATA_PROCESS_INS_AND_RETURN(ADD_DP);

	case SLJIT_ADDC:
		SLJIT_ASSERT(!(flags & INV_IMM));
		EMIT_DATA_PROCESS_INS_AND_RETURN(ADC_DP);

	case SLJIT_SUB:
		SLJIT_ASSERT(!(flags & INV_IMM));
		if (!(flags & ARGS_SWAPPED))
			EMIT_DATA_PROCESS_INS_AND_RETURN(SUB_DP);
		EMIT_DATA_PROCESS_INS_AND_RETURN(RSB_DP);

	case SLJIT_SUBC:
		SLJIT_ASSERT(!(flags & INV_IMM));
		if (!(flags & ARGS_SWAPPED))
			EMIT_DATA_PROCESS_INS_AND_RETURN(SBC_DP);
		EMIT_DATA_PROCESS_INS_AND_RETURN(RSC_DP);

	case SLJIT_MUL:
		SLJIT_ASSERT(!(flags & INV_IMM));
		SLJIT_ASSERT(!(src2 & SRC2_IMM));
		if (SLJIT_UNLIKELY(op & SLJIT_SET_O))
			mul_inst = SMULL | (reg_map[TMP_REG3] << 16) | (reg_map[dst] << 12);
		else
			mul_inst = MUL | (reg_map[dst] << 16);

		if (dst != src2)
			FAIL_IF(push_inst(compiler, mul_inst | (reg_map[src1] << 8) | reg_map[src2]));
		else if (dst != src1)
			FAIL_IF(push_inst(compiler, mul_inst | (reg_map[src2] << 8) | reg_map[src1]));
		else {
			/* Rm and Rd must not be the same register. */
			SLJIT_ASSERT(dst != TMP_REG1);
			FAIL_IF(push_inst(compiler, EMIT_DATA_PROCESS_INS(MOV_DP, 0, TMP_REG1, SLJIT_UNUSED, reg_map[src2])));
			FAIL_IF(push_inst(compiler, mul_inst | (reg_map[src2] << 8) | reg_map[TMP_REG1]));
		}

		if (!(op & SLJIT_SET_O))
			return SLJIT_SUCCESS;

		/* We need to use TMP_REG3. */
		compiler->cache_arg = 0;
		compiler->cache_argw = 0;
		/* cmp TMP_REG2, dst asr #31. */
		return push_inst(compiler, EMIT_DATA_PROCESS_INS(CMP_DP, SET_FLAGS, SLJIT_UNUSED, TMP_REG3, RM(dst) | 0xfc0));

	case SLJIT_AND:
		if (!(flags & INV_IMM))
			EMIT_DATA_PROCESS_INS_AND_RETURN(AND_DP);
		EMIT_DATA_PROCESS_INS_AND_RETURN(BIC_DP);

	case SLJIT_OR:
		SLJIT_ASSERT(!(flags & INV_IMM));
		EMIT_DATA_PROCESS_INS_AND_RETURN(ORR_DP);

	case SLJIT_XOR:
		SLJIT_ASSERT(!(flags & INV_IMM));
		EMIT_DATA_PROCESS_INS_AND_RETURN(EOR_DP);

	case SLJIT_SHL:
		EMIT_SHIFT_INS_AND_RETURN(0);

	case SLJIT_LSHR:
		EMIT_SHIFT_INS_AND_RETURN(1);

	case SLJIT_ASHR:
		EMIT_SHIFT_INS_AND_RETURN(2);

	case SLJIT_MOV:
		SLJIT_ASSERT(src1 == TMP_REG1 && !(flags & ARGS_SWAPPED));
		if (dst != src2) {
			if (src2 & SRC2_IMM) {
				if (flags & INV_IMM)
					EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(MVN_DP, dst, SLJIT_UNUSED, src2);
				EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(MOV_DP, dst, SLJIT_UNUSED, src2);
			}
			EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(MOV_DP, dst, SLJIT_UNUSED, reg_map[src2]);
		}
		return SLJIT_SUCCESS;

	case SLJIT_MOV_UB:
	case SLJIT_MOV_SB:
		SLJIT_ASSERT(src1 == TMP_REG1 && !(flags & ARGS_SWAPPED));
		if ((flags & (REG_DEST | REG_SOURCE)) == (REG_DEST | REG_SOURCE)) {
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
			if (op == SLJIT_MOV_UB)
				return push_inst(compiler, EMIT_DATA_PROCESS_INS(AND_DP, 0, dst, src2, SRC2_IMM | 0xff));
			EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, dst, SLJIT_UNUSED, (24 << 7) | reg_map[src2]));
			return push_inst(compiler, EMIT_DATA_PROCESS_INS(MOV_DP, 0, dst, SLJIT_UNUSED, (24 << 7) | (op == SLJIT_MOV_UB ? 0x20 : 0x40) | reg_map[dst]));
#else
			return push_inst(compiler, (op == SLJIT_MOV_UB ? UXTB : SXTB) | RD(dst) | RM(src2));
#endif
		}
		else if (dst != src2) {
			SLJIT_ASSERT(src2 & SRC2_IMM);
			if (flags & INV_IMM)
				EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(MVN_DP, dst, SLJIT_UNUSED, src2);
			EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(MOV_DP, dst, SLJIT_UNUSED, src2);
		}
		return SLJIT_SUCCESS;

	case SLJIT_MOV_UH:
	case SLJIT_MOV_SH:
		SLJIT_ASSERT(src1 == TMP_REG1 && !(flags & ARGS_SWAPPED));
		if ((flags & (REG_DEST | REG_SOURCE)) == (REG_DEST | REG_SOURCE)) {
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
			EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, dst, SLJIT_UNUSED, (16 << 7) | reg_map[src2]));
			return push_inst(compiler, EMIT_DATA_PROCESS_INS(MOV_DP, 0, dst, SLJIT_UNUSED, (16 << 7) | (op == SLJIT_MOV_UH ? 0x20 : 0x40) | reg_map[dst]));
#else
			return push_inst(compiler, (op == SLJIT_MOV_UH ? UXTH : SXTH) | RD(dst) | RM(src2));
#endif
		}
		else if (dst != src2) {
			SLJIT_ASSERT(src2 & SRC2_IMM);
			if (flags & INV_IMM)
				EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(MVN_DP, dst, SLJIT_UNUSED, src2);
			EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(MOV_DP, dst, SLJIT_UNUSED, src2);
		}
		return SLJIT_SUCCESS;

	case SLJIT_NOT:
		if (src2 & SRC2_IMM) {
			if (flags & INV_IMM)
				EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(MOV_DP, dst, SLJIT_UNUSED, src2);
			EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(MVN_DP, dst, SLJIT_UNUSED, src2);
		}
		EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(MVN_DP, dst, SLJIT_UNUSED, RM(src2));

	case SLJIT_CLZ:
		SLJIT_ASSERT(!(flags & INV_IMM));
		SLJIT_ASSERT(!(src2 & SRC2_IMM));
		FAIL_IF(push_inst(compiler, CLZ | RD(dst) | RM(src2)));
		if (flags & SET_FLAGS)
			EMIT_FULL_DATA_PROCESS_INS_AND_RETURN(CMP_DP, SLJIT_UNUSED, dst, SRC2_IMM);
		return SLJIT_SUCCESS;
	}
	SLJIT_ASSERT_STOP();
	return SLJIT_SUCCESS;
}

#undef EMIT_DATA_PROCESS_INS_AND_RETURN
#undef EMIT_FULL_DATA_PROCESS_INS_AND_RETURN
#undef EMIT_SHIFT_INS_AND_RETURN

/* Tests whether the immediate can be stored in the 12 bit imm field.
   Returns with 0 if not possible. */
static sljit_uw get_immediate(sljit_uw imm)
{
	int rol;

	if (imm <= 0xff)
		return SRC2_IMM | imm;

	if (!(imm & 0xff000000)) {
		imm <<= 8;
		rol = 8;
	}
	else {
		imm = (imm << 24) | (imm >> 8);
		rol = 0;
	}

	if (!(imm & 0xff000000)) {
		imm <<= 8;
		rol += 4;
	}

	if (!(imm & 0xf0000000)) {
		imm <<= 4;
		rol += 2;
	}

	if (!(imm & 0xc0000000)) {
		imm <<= 2;
		rol += 1;
	}

	if (!(imm & 0x00ffffff))
		return SRC2_IMM | (imm >> 24) | (rol << 8);
	else
		return 0;
}

#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
static int generate_int(struct sljit_compiler *compiler, int reg, sljit_uw imm, int positive)
{
	sljit_uw mask;
	sljit_uw imm1;
	sljit_uw imm2;
	int rol;

	/* Step1: Search a zero byte (8 continous zero bit). */
	mask = 0xff000000;
	rol = 8;
	while(1) {
		if (!(imm & mask)) {
			/* Rol imm by rol. */
			imm = (imm << rol) | (imm >> (32 - rol));
			/* Calculate arm rol. */
			rol = 4 + (rol >> 1);
			break;
		}
		rol += 2;
		mask >>= 2;
		if (mask & 0x3) {
			/* rol by 8. */
			imm = (imm << 8) | (imm >> 24);
			mask = 0xff00;
			rol = 24;
			while (1) {
				if (!(imm & mask)) {
					/* Rol imm by rol. */
					imm = (imm << rol) | (imm >> (32 - rol));
					/* Calculate arm rol. */
					rol = (rol >> 1) - 8;
					break;
				}
				rol += 2;
				mask >>= 2;
				if (mask & 0x3)
					return 0;
			}
			break;
		}
	}

	/* The low 8 bit must be zero. */
	SLJIT_ASSERT(!(imm & 0xff));

	if (!(imm & 0xff000000)) {
		imm1 = SRC2_IMM | ((imm >> 16) & 0xff) | (((rol + 4) & 0xf) << 8);
		imm2 = SRC2_IMM | ((imm >> 8) & 0xff) | (((rol + 8) & 0xf) << 8);
	}
	else if (imm & 0xc0000000) {
		imm1 = SRC2_IMM | ((imm >> 24) & 0xff) | ((rol & 0xf) << 8);
		imm <<= 8;
		rol += 4;

		if (!(imm & 0xff000000)) {
			imm <<= 8;
			rol += 4;
		}

		if (!(imm & 0xf0000000)) {
			imm <<= 4;
			rol += 2;
		}

		if (!(imm & 0xc0000000)) {
			imm <<= 2;
			rol += 1;
		}

		if (!(imm & 0x00ffffff))
			imm2 = SRC2_IMM | (imm >> 24) | ((rol & 0xf) << 8);
		else
			return 0;
	}
	else {
		if (!(imm & 0xf0000000)) {
			imm <<= 4;
			rol += 2;
		}

		if (!(imm & 0xc0000000)) {
			imm <<= 2;
			rol += 1;
		}

		imm1 = SRC2_IMM | ((imm >> 24) & 0xff) | ((rol & 0xf) << 8);
		imm <<= 8;
		rol += 4;

		if (!(imm & 0xf0000000)) {
			imm <<= 4;
			rol += 2;
		}

		if (!(imm & 0xc0000000)) {
			imm <<= 2;
			rol += 1;
		}

		if (!(imm & 0x00ffffff))
			imm2 = SRC2_IMM | (imm >> 24) | ((rol & 0xf) << 8);
		else
			return 0;
	}

	EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(positive ? MOV_DP : MVN_DP, 0, reg, SLJIT_UNUSED, imm1));
	EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(positive ? ORR_DP : BIC_DP, 0, reg, reg, imm2));
	return 1;
}
#endif

static int load_immediate(struct sljit_compiler *compiler, int reg, sljit_uw imm)
{
	sljit_uw tmp;

#if (defined SLJIT_CONFIG_ARM_V7 && SLJIT_CONFIG_ARM_V7)
	if (!(imm & ~0xffff))
		return push_inst(compiler, MOVW | RD(reg) | ((imm << 4) & 0xf0000) | (imm & 0xfff));
#endif

	/* Create imm by 1 inst. */
	tmp = get_immediate(imm);
	if (tmp) {
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, reg, SLJIT_UNUSED, tmp));
		return SLJIT_SUCCESS;
	}

	tmp = get_immediate(~imm);
	if (tmp) {
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MVN_DP, 0, reg, SLJIT_UNUSED, tmp));
		return SLJIT_SUCCESS;
	}

#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	/* Create imm by 2 inst. */
	FAIL_IF(generate_int(compiler, reg, imm, 1));
	FAIL_IF(generate_int(compiler, reg, ~imm, 0));

	/* Load integer. */
	return push_inst_with_literal(compiler, EMIT_DATA_TRANSFER(WORD_DATA | LOAD_DATA, 1, 0, reg, TMP_PC, 0), imm);
#else
	return emit_imm(compiler, reg, imm);
#endif
}

/* Can perform an operation using at most 1 instruction. */
static int getput_arg_fast(struct sljit_compiler *compiler, int inp_flags, int reg, int arg, sljit_w argw)
{
	sljit_uw imm;

	if (arg & SLJIT_IMM) {
		imm = get_immediate(argw);
		if (imm) {
			if (inp_flags & ARG_TEST)
				return 1;
			EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, reg, SLJIT_UNUSED, imm));
			return -1;
		}
		imm = get_immediate(~argw);
		if (imm) {
			if (inp_flags & ARG_TEST)
				return 1;
			EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MVN_DP, 0, reg, SLJIT_UNUSED, imm));
			return -1;
		}
		return (inp_flags & ARG_TEST) ? SLJIT_SUCCESS : 0;
	}

	SLJIT_ASSERT(arg & SLJIT_MEM);

	/* Fast loads/stores. */
	if (arg & 0xf) {
		if (!(arg & 0xf0)) {
			if (IS_TYPE1_TRANSFER(inp_flags)) {
				if (argw >= 0 && argw <= 0xfff) {
					if (inp_flags & ARG_TEST)
						return 1;
					EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, 1, inp_flags & WRITE_BACK, reg, arg & 0xf, argw));
					return -1;
				}
				if (argw < 0 && argw >= -0xfff) {
					if (inp_flags & ARG_TEST)
						return 1;
					EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, 0, inp_flags & WRITE_BACK, reg, arg & 0xf, -argw));
					return -1;
				}
			}
			else {
				if (argw >= 0 && argw <= 0xff) {
					if (inp_flags & ARG_TEST)
						return 1;
					EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, 1, inp_flags & WRITE_BACK, reg, arg & 0xf, TYPE2_TRANSFER_IMM(argw)));
					return -1;
				}
				if (argw < 0 && argw >= -0xff) {
					if (inp_flags & ARG_TEST)
						return 1;
					argw = -argw;
					EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, 0, inp_flags & WRITE_BACK, reg, arg & 0xf, TYPE2_TRANSFER_IMM(argw)));
					return -1;
				}
			}
		}
		else if ((argw & 0x3) == 0 || IS_TYPE1_TRANSFER(inp_flags)) {
			if (inp_flags & ARG_TEST)
				return 1;
			EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, 1, inp_flags & WRITE_BACK, reg, arg & 0xf,
				RM((arg >> 4) & 0xf) | (IS_TYPE1_TRANSFER(inp_flags) ? SRC2_IMM : 0) | ((argw & 0x3) << 7)));
			return -1;
		}
	}

	return (inp_flags & ARG_TEST) ? SLJIT_SUCCESS : 0;
}

/* See getput_arg below.
   Note: can_cache is called only for binary operators. Those
   operators always uses word arguments without write back. */
static int can_cache(int arg, sljit_w argw, int next_arg, sljit_w next_argw)
{
	/* Immediate caching is not supported as it would be an operation on constant arguments. */
	if (arg & SLJIT_IMM)
		return 0;

	/* Always a simple operation. */
	if (arg & 0xf0)
		return 0;

	if (!(arg & 0xf)) {
		/* Immediate access. */
		if ((next_arg & SLJIT_MEM) && ((sljit_uw)argw - (sljit_uw)next_argw <= 0xfff || (sljit_uw)next_argw - (sljit_uw)argw <= 0xfff))
			return 1;
		return 0;
	}

	if (argw <= 0xfffff && argw >= -0xfffff)
		return 0;

	if (argw == next_argw && (next_arg & SLJIT_MEM))
		return 1;

	if (arg == next_arg && ((sljit_uw)argw - (sljit_uw)next_argw <= 0xfff || (sljit_uw)next_argw - (sljit_uw)argw <= 0xfff))
		return 1;

	return 0;
}

#define GETPUT_ARG_DATA_TRANSFER(add, wb, target, base, imm) \
	if (max_delta & 0xf00) \
		FAIL_IF(push_inst(compiler, EMIT_DATA_TRANSFER(inp_flags, add, wb, target, base, imm))); \
	else \
		FAIL_IF(push_inst(compiler, EMIT_DATA_TRANSFER(inp_flags, add, wb, target, base, TYPE2_TRANSFER_IMM(imm))));

#define TEST_WRITE_BACK() \
	if (inp_flags & WRITE_BACK) { \
		tmp_r = arg & 0xf; \
		if (reg == tmp_r) { \
			/* This can only happen for stores */ \
			/* since ldr reg, [reg, ...]! has no meaning */ \
			SLJIT_ASSERT(!(inp_flags & LOAD_DATA)); \
			EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, TMP_REG3, SLJIT_UNUSED, RM(reg))); \
			reg = TMP_REG3; \
		} \
	}

/* Emit the necessary instructions. See can_cache above. */
static int getput_arg(struct sljit_compiler *compiler, int inp_flags, int reg, int arg, sljit_w argw, int next_arg, sljit_w next_argw)
{
	int tmp_r;
	sljit_w max_delta;
	sljit_w sign;

	if (arg & SLJIT_IMM) {
		SLJIT_ASSERT(inp_flags & LOAD_DATA);
		return load_immediate(compiler, reg, argw);
	}

	SLJIT_ASSERT(arg & SLJIT_MEM);

	tmp_r = (inp_flags & LOAD_DATA) ? reg : TMP_REG3;
	max_delta = IS_TYPE1_TRANSFER(inp_flags) ? 0xfff : 0xff;

	if ((arg & 0xf) == SLJIT_UNUSED) {
		/* Write back is not used. */
		if ((compiler->cache_arg & SLJIT_IMM) && (((sljit_uw)argw - (sljit_uw)compiler->cache_argw) <= (sljit_uw)max_delta || ((sljit_uw)compiler->cache_argw - (sljit_uw)argw) <= (sljit_uw)max_delta)) {
			if (((sljit_uw)argw - (sljit_uw)compiler->cache_argw) <= (sljit_uw)max_delta) {
				sign = 1;
				argw = argw - compiler->cache_argw;
			}
			else {
				sign = 0;
				argw = compiler->cache_argw - argw;
			}

			if (max_delta & 0xf00) {
				EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, sign, 0, reg, TMP_REG3, argw));
			}
			else {
				EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, sign, 0, reg, TMP_REG3, TYPE2_TRANSFER_IMM(argw)));
			}
			return SLJIT_SUCCESS;
		}

		/* With write back, we can create some sophisticated loads, but
		   it is hard to decide whether we should convert downward (0s) or upward (1s). */
		if ((next_arg & SLJIT_MEM) && ((sljit_uw)argw - (sljit_uw)next_argw <= (sljit_uw)max_delta || (sljit_uw)next_argw - (sljit_uw)argw <= (sljit_uw)max_delta)) {
			SLJIT_ASSERT(inp_flags & LOAD_DATA);

			compiler->cache_arg = SLJIT_IMM;
			compiler->cache_argw = argw;
			tmp_r = TMP_REG3;
		}

		FAIL_IF(load_immediate(compiler, tmp_r, argw));
		GETPUT_ARG_DATA_TRANSFER(1, 0, reg, tmp_r, 0);
		return SLJIT_SUCCESS;
	}

	/* Extended imm addressing for [reg+imm] format. */
	sign = (max_delta << 8) | 0xff;
	if (!(arg & 0xf0) && argw <= sign && argw >= -sign) {
		TEST_WRITE_BACK();
		if (argw >= 0) {
			sign = 1;
		}
		else {
			sign = 0;
			argw = -argw;
		}

		/* Optimization: add is 0x4, sub is 0x2. Sign is 1 for add and 0 for sub. */
		if (max_delta & 0xf00)
			EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(SUB_DP << sign, 0, tmp_r, arg & 0xf, SRC2_IMM | (argw >> 12) | 0xa00));
		else
			EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(SUB_DP << sign, 0, tmp_r, arg & 0xf, SRC2_IMM | (argw >> 8) | 0xc00));

		argw &= max_delta;
		GETPUT_ARG_DATA_TRANSFER(sign, inp_flags & WRITE_BACK, reg, tmp_r, argw);
		return SLJIT_SUCCESS;
	}

	if (arg & 0xf0) {
		SLJIT_ASSERT((argw & 0x3) && !(max_delta & 0xf00));
		if (inp_flags & WRITE_BACK)
			tmp_r = arg & 0xf;
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(ADD_DP, 0, tmp_r, arg & 0xf, RM((arg >> 4) & 0xf) | ((argw & 0x3) << 7)));
		EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, 1, 0, reg, tmp_r, TYPE2_TRANSFER_IMM(0)));
		return SLJIT_SUCCESS;
	}

	if (compiler->cache_arg == arg && ((sljit_uw)argw - (sljit_uw)compiler->cache_argw) <= (sljit_uw)max_delta) {
		SLJIT_ASSERT(!(inp_flags & WRITE_BACK));
		argw = argw - compiler->cache_argw;
		GETPUT_ARG_DATA_TRANSFER(1, 0, reg, TMP_REG3, argw);
		return SLJIT_SUCCESS;
	}

	if (compiler->cache_arg == arg && ((sljit_uw)compiler->cache_argw - (sljit_uw)argw) <= (sljit_uw)max_delta) {
		SLJIT_ASSERT(!(inp_flags & WRITE_BACK));
		argw = compiler->cache_argw - argw;
		GETPUT_ARG_DATA_TRANSFER(0, 0, reg, TMP_REG3, argw);
		return SLJIT_SUCCESS;
	}

	if ((compiler->cache_arg & SLJIT_IMM) && compiler->cache_argw == argw) {
		TEST_WRITE_BACK();
		EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, 1, inp_flags & WRITE_BACK, reg, arg & 0xf, RM(TMP_REG3) | (max_delta & 0xf00 ? SRC2_IMM : 0)));
		return SLJIT_SUCCESS;
	}

	if (argw == next_argw && (next_arg & SLJIT_MEM)) {
		SLJIT_ASSERT(inp_flags & LOAD_DATA);
		FAIL_IF(load_immediate(compiler, TMP_REG3, argw));

		compiler->cache_arg = SLJIT_IMM;
		compiler->cache_argw = argw;

		TEST_WRITE_BACK();
		EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, 1, inp_flags & WRITE_BACK, reg, arg & 0xf, RM(TMP_REG3) | (max_delta & 0xf00 ? SRC2_IMM : 0)));
		return SLJIT_SUCCESS;
	}

	if (arg == next_arg && !(inp_flags & WRITE_BACK) && ((sljit_uw)argw - (sljit_uw)next_argw <= (sljit_uw)max_delta || (sljit_uw)next_argw - (sljit_uw)argw <= (sljit_uw)max_delta)) {
		SLJIT_ASSERT(inp_flags & LOAD_DATA);
		FAIL_IF(load_immediate(compiler, TMP_REG3, argw));
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(ADD_DP, 0, TMP_REG3, TMP_REG3, reg_map[arg & 0xf]));

		compiler->cache_arg = arg;
		compiler->cache_argw = argw;

		GETPUT_ARG_DATA_TRANSFER(1, 0, reg, TMP_REG3, 0);
		return SLJIT_SUCCESS;
	}

	if ((arg & 0xf) == tmp_r) {
		compiler->cache_arg = SLJIT_IMM;
		compiler->cache_argw = argw;
		tmp_r = TMP_REG3;
	}

	FAIL_IF(load_immediate(compiler, tmp_r, argw));
	EMIT_INSTRUCTION(EMIT_DATA_TRANSFER(inp_flags, 1, inp_flags & WRITE_BACK, reg, arg & 0xf, reg_map[tmp_r] | (max_delta & 0xf00 ? SRC2_IMM : 0)));
	return SLJIT_SUCCESS;
}

static int emit_op(struct sljit_compiler *compiler, int op, int inp_flags,
	int dst, sljit_w dstw,
	int src1, sljit_w src1w,
	int src2, sljit_w src2w)
{
	/* arg1 goes to TMP_REG1 or src reg
	   arg2 goes to TMP_REG2, imm or src reg
	   TMP_REG3 can be used for caching
	   result goes to TMP_REG2, so put result can use TMP_REG1 and TMP_REG3. */

	/* We prefers register and simple consts. */
	int dst_r;
	int src1_r;
	int src2_r = 0;
	int sugg_src2_r = TMP_REG2;
	int flags = GET_FLAGS(op) ? SET_FLAGS : 0;

	compiler->cache_arg = 0;
	compiler->cache_argw = 0;

	/* Destination check. */
	if (dst >= SLJIT_TEMPORARY_REG1 && dst <= TMP_REG3) {
		dst_r = dst;
		flags |= REG_DEST;
		if (op >= SLJIT_MOV && op <= SLJIT_MOVU_SI)
			sugg_src2_r = dst_r;
	}
	else if (dst == SLJIT_UNUSED) {
		if (op >= SLJIT_MOV && op <= SLJIT_MOVU_SI && !(src2 & SLJIT_MEM))
			return SLJIT_SUCCESS;
		dst_r = TMP_REG2;
	}
	else {
		SLJIT_ASSERT(dst & SLJIT_MEM);
		if (getput_arg_fast(compiler, inp_flags | ARG_TEST, TMP_REG2, dst, dstw)) {
			flags |= FAST_DEST;
			dst_r = TMP_REG2;
		}
		else {
			flags |= SLOW_DEST;
			dst_r = 0;
		}
	}

	/* Source 1. */
	if (src1 >= SLJIT_TEMPORARY_REG1 && src1 <= TMP_REG3)
		src1_r = src1;
	else if (src2 >= SLJIT_TEMPORARY_REG1 && src2 <= TMP_REG3) {
		flags |= ARGS_SWAPPED;
		src1_r = src2;
		src2 = src1;
		src2w = src1w;
	}
	else {
		if ((inp_flags & ALLOW_ANY_IMM) && (src1 & SLJIT_IMM)) {
			/* The second check will generate a hit. */
			src2_r = get_immediate(src1w);
			if (src2_r) {
				flags |= ARGS_SWAPPED;
				src1 = src2;
				src1w = src2w;
			}
			if (inp_flags & ALLOW_INV_IMM) {
				src2_r = get_immediate(~src1w);
				if (src2_r) {
					flags |= ARGS_SWAPPED | INV_IMM;
					src1 = src2;
					src1w = src2w;
				}
			}
		}

		src1_r = 0;
		if (getput_arg_fast(compiler, inp_flags | LOAD_DATA, TMP_REG1, src1, src1w)) {
			FAIL_IF(compiler->error);
			src1_r = TMP_REG1;
		}
	}

	/* Source 2. */
	if (src2_r == 0) {
		if (src2 >= SLJIT_TEMPORARY_REG1 && src2 <= TMP_REG3) {
			src2_r = src2;
			flags |= REG_SOURCE;
			if (!(flags & REG_DEST) && op >= SLJIT_MOV && op <= SLJIT_MOVU_SI)
				dst_r = src2_r;
		}
		else do { /* do { } while(0) is used because of breaks. */
			if ((inp_flags & ALLOW_ANY_IMM) && (src2 & SLJIT_IMM)) {
				src2_r = get_immediate(src2w);
				if (src2_r)
					break;
				if (inp_flags & ALLOW_INV_IMM) {
					src2_r = get_immediate(~src2w);
					if (src2_r) {
						flags |= INV_IMM;
						break;
					}
				}
			}

			/* src2_r is 0. */
			if (getput_arg_fast(compiler, inp_flags | LOAD_DATA, sugg_src2_r, src2, src2w)) {
				FAIL_IF(compiler->error);
				src2_r = sugg_src2_r;
			}
		} while (0);
	}

	/* src1_r, src2_r and dst_r can be zero (=unprocessed) or non-zero.
	   If they are zero, they must not be registers. */
	if (src1_r == 0 && src2_r == 0 && dst_r == 0) {
		if (!can_cache(src1, src1w, src2, src2w) && can_cache(src1, src1w, dst, dstw)) {
			SLJIT_ASSERT(!(flags & ARGS_SWAPPED));
			flags |= ARGS_SWAPPED;
			FAIL_IF(getput_arg(compiler, inp_flags | LOAD_DATA, TMP_REG1, src2, src2w, src1, src1w));
			FAIL_IF(getput_arg(compiler, inp_flags | LOAD_DATA, TMP_REG2, src1, src1w, dst, dstw));
		}
		else {
			FAIL_IF(getput_arg(compiler, inp_flags | LOAD_DATA, TMP_REG1, src1, src1w, src2, src2w));
			FAIL_IF(getput_arg(compiler, inp_flags | LOAD_DATA, TMP_REG2, src2, src2w, dst, dstw));
		}
		src1_r = TMP_REG1;
		src2_r = TMP_REG2;
	}
	else if (src1_r == 0 && src2_r == 0) {
		FAIL_IF(getput_arg(compiler, inp_flags | LOAD_DATA, TMP_REG1, src1, src1w, src2, src2w));
		src1_r = TMP_REG1;
	}
	else if (src1_r == 0 && dst_r == 0) {
		FAIL_IF(getput_arg(compiler, inp_flags | LOAD_DATA, TMP_REG1, src1, src1w, dst, dstw));
		src1_r = TMP_REG1;
	}
	else if (src2_r == 0 && dst_r == 0) {
		FAIL_IF(getput_arg(compiler, inp_flags | LOAD_DATA, sugg_src2_r, src2, src2w, dst, dstw));
		src2_r = sugg_src2_r;
	}

	if (dst_r == 0)
		dst_r = TMP_REG2;

	if (src1_r == 0) {
		FAIL_IF(getput_arg(compiler, inp_flags | LOAD_DATA, TMP_REG1, src1, src1w, 0, 0));
		src1_r = TMP_REG1;
	}

	if (src2_r == 0) {
		FAIL_IF(getput_arg(compiler, inp_flags | LOAD_DATA, sugg_src2_r, src2, src2w, 0, 0));
		src2_r = sugg_src2_r;
	}

	FAIL_IF(emit_single_op(compiler, op, flags, dst_r, src1_r, src2_r));

	if (flags & (FAST_DEST | SLOW_DEST)) {
		if (flags & FAST_DEST)
			FAIL_IF(getput_arg_fast(compiler, inp_flags, dst_r, dst, dstw));
		else
			FAIL_IF(getput_arg(compiler, inp_flags, dst_r, dst, dstw, 0, 0));
	}
	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_op0(struct sljit_compiler *compiler, int op)
{
	CHECK_ERROR();
	check_sljit_emit_op0(compiler, op);

	op = GET_OPCODE(op);
	switch (op) {
	case SLJIT_BREAKPOINT:
		EMIT_INSTRUCTION(DEBUGGER);
		break;
	case SLJIT_NOP:
		EMIT_INSTRUCTION(NOP);
		break;
	}

	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_op1(struct sljit_compiler *compiler, int op,
	int dst, sljit_w dstw,
	int src, sljit_w srcw)
{
	CHECK_ERROR();
	check_sljit_emit_op1(compiler, op, dst, dstw, src, srcw);

	switch (GET_OPCODE(op)) {
	case SLJIT_MOV:
	case SLJIT_MOV_UI:
	case SLJIT_MOV_SI:
		return emit_op(compiler, SLJIT_MOV, ALLOW_ANY_IMM, dst, dstw, TMP_REG1, 0, src, srcw);

	case SLJIT_MOV_UB:
		return emit_op(compiler, SLJIT_MOV_UB, ALLOW_ANY_IMM | BYTE_DATA, dst, dstw, TMP_REG1, 0, src, (src & SLJIT_IMM) ? (unsigned char)srcw : srcw);

	case SLJIT_MOV_SB:
		return emit_op(compiler, SLJIT_MOV_SB, ALLOW_ANY_IMM | SIGNED_DATA | BYTE_DATA, dst, dstw, TMP_REG1, 0, src, (src & SLJIT_IMM) ? (signed char)srcw : srcw);

	case SLJIT_MOV_UH:
		return emit_op(compiler, SLJIT_MOV_UH, ALLOW_ANY_IMM | HALF_DATA, dst, dstw, TMP_REG1, 0, src, (src & SLJIT_IMM) ? (unsigned short)srcw : srcw);

	case SLJIT_MOV_SH:
		return emit_op(compiler, SLJIT_MOV_SH, ALLOW_ANY_IMM | SIGNED_DATA | HALF_DATA, dst, dstw, TMP_REG1, 0, src, (src & SLJIT_IMM) ? (signed short)srcw : srcw);

	case SLJIT_MOVU:
	case SLJIT_MOVU_UI:
	case SLJIT_MOVU_SI:
		return emit_op(compiler, SLJIT_MOV, ALLOW_ANY_IMM | WRITE_BACK, dst, dstw, TMP_REG1, 0, src, srcw);

	case SLJIT_MOVU_UB:
		return emit_op(compiler, SLJIT_MOV_UB, ALLOW_ANY_IMM | BYTE_DATA | WRITE_BACK, dst, dstw, TMP_REG1, 0, src, (src & SLJIT_IMM) ? (unsigned char)srcw : srcw);

	case SLJIT_MOVU_SB:
		return emit_op(compiler, SLJIT_MOV_SB, ALLOW_ANY_IMM | SIGNED_DATA | BYTE_DATA | WRITE_BACK, dst, dstw, TMP_REG1, 0, src, (src & SLJIT_IMM) ? (signed char)srcw : srcw);

	case SLJIT_MOVU_UH:
		return emit_op(compiler, SLJIT_MOV_UH, ALLOW_ANY_IMM | HALF_DATA | WRITE_BACK, dst, dstw, TMP_REG1, 0, src, (src & SLJIT_IMM) ? (unsigned short)srcw : srcw);

	case SLJIT_MOVU_SH:
		return emit_op(compiler, SLJIT_MOV_SH, ALLOW_ANY_IMM | SIGNED_DATA | HALF_DATA | WRITE_BACK, dst, dstw, TMP_REG1, 0, src, (src & SLJIT_IMM) ? (signed short)srcw : srcw);

	case SLJIT_NOT:
		return emit_op(compiler, op, ALLOW_ANY_IMM, dst, dstw, TMP_REG1, 0, src, srcw);

	case SLJIT_NEG:
#if (defined SLJIT_VERBOSE && SLJIT_VERBOSE) || (defined SLJIT_DEBUG && SLJIT_DEBUG)
		compiler->skip_checks = 1;
#endif
		return sljit_emit_op2(compiler, SLJIT_SUB | GET_FLAGS(op), dst, dstw, SLJIT_IMM, 0, src, srcw);

	case SLJIT_CLZ:
		return emit_op(compiler, op, 0, dst, dstw, TMP_REG1, 0, src, srcw);
	}

	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_op2(struct sljit_compiler *compiler, int op,
	int dst, sljit_w dstw,
	int src1, sljit_w src1w,
	int src2, sljit_w src2w)
{
	CHECK_ERROR();
	check_sljit_emit_op2(compiler, op, dst, dstw, src1, src1w, src2, src2w);

	switch (GET_OPCODE(op)) {
	case SLJIT_ADD:
	case SLJIT_ADDC:
	case SLJIT_SUB:
	case SLJIT_SUBC:
	case SLJIT_OR:
	case SLJIT_XOR:
		return emit_op(compiler, op, ALLOW_IMM, dst, dstw, src1, src1w, src2, src2w);

	case SLJIT_MUL:
		return emit_op(compiler, op, 0, dst, dstw, src1, src1w, src2, src2w);

	case SLJIT_AND:
		return emit_op(compiler, op, ALLOW_ANY_IMM, dst, dstw, src1, src1w, src2, src2w);

	case SLJIT_SHL:
	case SLJIT_LSHR:
	case SLJIT_ASHR:
		if (src2 & SLJIT_IMM) {
			compiler->shift_imm = src2w & 0x1f;
			return emit_op(compiler, op, 0, dst, dstw, TMP_REG1, 0, src1, src1w);
		}
		else {
			compiler->shift_imm = 0x20;
			return emit_op(compiler, op, 0, dst, dstw, src1, src1w, src2, src2w);
		}
	}

	return SLJIT_SUCCESS;
}

/* --------------------------------------------------------------------- */
/*  Floating point operators                                             */
/* --------------------------------------------------------------------- */

#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)

/* 0 - no fpu
   1 - vfp */
static int arm_fpu_type = -1;

static void init_compiler()
{
	if (arm_fpu_type != -1)
		return;

	/* TODO: Only the OS can help to determine the correct fpu type. */
	arm_fpu_type = 1;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_is_fpu_available(void)
{
	if (arm_fpu_type == -1)
		init_compiler();
	return arm_fpu_type;
}

#else

#define arm_fpu_type 1

SLJIT_API_FUNC_ATTRIBUTE int sljit_is_fpu_available(void)
{
	/* Always available. */
	return 1;
}

#endif

#define EMIT_FPU_DATA_TRANSFER(add, load, base, freg, offs) \
	(VSTR | ((add) << 23) | ((load) << 20) | (reg_map[base] << 16) | (freg << 12) | (offs))
#define EMIT_FPU_OPERATION(opcode, dst, src1, src2) \
	((opcode) | ((dst) << 12) | (src1) | ((src2) << 16))

static int emit_fpu_data_transfer(struct sljit_compiler *compiler, int fpu_reg, int load, int arg, sljit_w argw)
{
	SLJIT_ASSERT(arg & SLJIT_MEM);

	/* Fast loads and stores. */
	if ((arg & 0xf) && !(arg & 0xf0) && (argw & 0x3) == 0) {
		if (argw >= 0 && argw <= 0x3ff) {
			EMIT_INSTRUCTION(EMIT_FPU_DATA_TRANSFER(1, load, arg & 0xf, fpu_reg, argw >> 2));
			return SLJIT_SUCCESS;
		}
		if (argw < 0 && argw >= -0x3ff) {
			EMIT_INSTRUCTION(EMIT_FPU_DATA_TRANSFER(0, load, arg & 0xf, fpu_reg, (-argw) >> 2));
			return SLJIT_SUCCESS;
		}
		if (argw >= 0 && argw <= 0x3ffff) {
			SLJIT_ASSERT(get_immediate(argw & 0x3fc00));
			EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(ADD_DP, 0, TMP_REG1, arg & 0xf, get_immediate(argw & 0x3fc00)));
			argw &= 0x3ff;
			EMIT_INSTRUCTION(EMIT_FPU_DATA_TRANSFER(1, load, TMP_REG1, fpu_reg, argw >> 2));
			return SLJIT_SUCCESS;
		}
		if (argw < 0 && argw >= -0x3ffff) {
			argw = -argw;
			SLJIT_ASSERT(get_immediate(argw & 0x3fc00));
			EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(SUB_DP, 0, TMP_REG1, arg & 0xf, get_immediate(argw & 0x3fc00)));
			argw &= 0x3ff;
			EMIT_INSTRUCTION(EMIT_FPU_DATA_TRANSFER(0, load, TMP_REG1, fpu_reg, argw >> 2));
			return SLJIT_SUCCESS;
		}
	}

	if (arg & 0xf0) {
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(ADD_DP, 0, TMP_REG1, arg & 0xf, RM((arg >> 4) & 0xf) | ((argw & 0x3) << 7)));
		EMIT_INSTRUCTION(EMIT_FPU_DATA_TRANSFER(1, load, TMP_REG1, fpu_reg, 0));
		return SLJIT_SUCCESS;
	}

	if (compiler->cache_arg == arg && ((argw - compiler->cache_argw) & 0x3) == 0) {
		if (((sljit_uw)argw - (sljit_uw)compiler->cache_argw) <= 0x3ff) {
			EMIT_INSTRUCTION(EMIT_FPU_DATA_TRANSFER(1, load, TMP_REG3, fpu_reg, (argw - compiler->cache_argw) >> 2));
			return SLJIT_SUCCESS;
		}
		if (((sljit_uw)compiler->cache_argw - (sljit_uw)argw) <= 0x3ff) {
			EMIT_INSTRUCTION(EMIT_FPU_DATA_TRANSFER(0, load, TMP_REG3, fpu_reg, (compiler->cache_argw - argw) >> 2));
			return SLJIT_SUCCESS;
		}
	}

	compiler->cache_arg = arg;
	compiler->cache_argw = argw;
	if (arg & 0xf) {
		FAIL_IF(load_immediate(compiler, TMP_REG1, argw));
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(ADD_DP, 0, TMP_REG3, arg & 0xf, reg_map[TMP_REG1]));
	}
	else
		FAIL_IF(load_immediate(compiler, TMP_REG3, argw));

	EMIT_INSTRUCTION(EMIT_FPU_DATA_TRANSFER(1, load, TMP_REG3, fpu_reg, 0));
	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_fop1(struct sljit_compiler *compiler, int op,
	int dst, sljit_w dstw,
	int src, sljit_w srcw)
{
	int dst_freg;

	CHECK_ERROR();
	check_sljit_emit_fop1(compiler, op, dst, dstw, src, srcw);

	compiler->cache_arg = 0;
	compiler->cache_argw = 0;

	if (GET_OPCODE(op) == SLJIT_FCMP) {
		if (dst > SLJIT_FLOAT_REG4) {
			FAIL_IF(emit_fpu_data_transfer(compiler, TMP_FREG1, 1, dst, dstw));
			dst = TMP_FREG1;
		}
		if (src > SLJIT_FLOAT_REG4) {
			FAIL_IF(emit_fpu_data_transfer(compiler, TMP_FREG2, 1, src, srcw));
			src = TMP_FREG2;
		}
		EMIT_INSTRUCTION(VCMP_F64 | (dst << 12) | src);
		EMIT_INSTRUCTION(VMRS);
		return SLJIT_SUCCESS;
	}

	dst_freg = (dst > SLJIT_FLOAT_REG4) ? TMP_FREG1 : dst;

	if (src > SLJIT_FLOAT_REG4) {
		FAIL_IF(emit_fpu_data_transfer(compiler, dst_freg, 1, src, srcw));
		src = dst_freg;
	}

	switch (op) {
		case SLJIT_FMOV:
			if (src != dst_freg && dst_freg != TMP_FREG1)
				EMIT_INSTRUCTION(EMIT_FPU_OPERATION(VMOV_F64, dst_freg, src, 0));
			break;
		case SLJIT_FNEG:
			EMIT_INSTRUCTION(EMIT_FPU_OPERATION(VNEG_F64, dst_freg, src, 0));
			break;
		case SLJIT_FABS:
			EMIT_INSTRUCTION(EMIT_FPU_OPERATION(VABS_F64, dst_freg, src, 0));
			break;
	}

	if (dst_freg == TMP_FREG1)
		FAIL_IF(emit_fpu_data_transfer(compiler, src, 0, dst, dstw));

	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_fop2(struct sljit_compiler *compiler, int op,
	int dst, sljit_w dstw,
	int src1, sljit_w src1w,
	int src2, sljit_w src2w)
{
	int dst_freg;

	CHECK_ERROR();
	check_sljit_emit_fop2(compiler, op, dst, dstw, src1, src1w, src2, src2w);

	compiler->cache_arg = 0;
	compiler->cache_argw = 0;

	dst_freg = (dst > SLJIT_FLOAT_REG4) ? TMP_FREG1 : dst;

	if (src2 > SLJIT_FLOAT_REG4) {
		FAIL_IF(emit_fpu_data_transfer(compiler, TMP_FREG2, 1, src2, src2w));
		src2 = TMP_FREG2;
	}

	if (src1 > SLJIT_FLOAT_REG4) {
		FAIL_IF(emit_fpu_data_transfer(compiler, TMP_FREG1, 1, src1, src1w));
		src1 = TMP_FREG1;
	}

	switch (op) {
	case SLJIT_FADD:
		EMIT_INSTRUCTION(EMIT_FPU_OPERATION(VADD_F64, dst_freg, src2, src1));
		break;

	case SLJIT_FSUB:
		EMIT_INSTRUCTION(EMIT_FPU_OPERATION(VSUB_F64, dst_freg, src2, src1));
		break;

	case SLJIT_FMUL:
		EMIT_INSTRUCTION(EMIT_FPU_OPERATION(VMUL_F64, dst_freg, src2, src1));
		break;

	case SLJIT_FDIV:
		EMIT_INSTRUCTION(EMIT_FPU_OPERATION(VDIV_F64, dst_freg, src2, src1));
		break;
	}

	if (dst_freg == TMP_FREG1)
		FAIL_IF(emit_fpu_data_transfer(compiler, TMP_FREG1, 0, dst, dstw));

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

	size = (1 + generals) * sizeof(sljit_uw);
	if (temporaries >= 4)
		size += (temporaries - 3) * sizeof(sljit_uw);
	local_size += size;
	local_size = (local_size + 7) & ~7;
	local_size -= size;
	compiler->local_size = local_size;

	if (dst >= SLJIT_TEMPORARY_REG1 && dst <= SLJIT_NO_REGISTERS)
		return push_inst(compiler, EMIT_DATA_PROCESS_INS(MOV_DP, 0, dst, SLJIT_UNUSED, RM(TMP_REG3)));
	else if (dst & SLJIT_MEM) {
		if (getput_arg_fast(compiler, WORD_DATA, TMP_REG3, dst, dstw))
			return compiler->error;
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, TMP_REG2, SLJIT_UNUSED, RM(TMP_REG3)));
		compiler->cache_arg = 0;
		compiler->cache_argw = 0;
		return getput_arg(compiler, WORD_DATA, TMP_REG2, dst, dstw, 0, 0);
	}

	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_fast_return(struct sljit_compiler *compiler, int src, sljit_w srcw)
{
	CHECK_ERROR();
	check_sljit_emit_fast_return(compiler, src, srcw);

	if (src >= SLJIT_TEMPORARY_REG1 && src <= SLJIT_NO_REGISTERS)
		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, TMP_REG3, SLJIT_UNUSED, RM(src)));
	else if (src & SLJIT_MEM) {
		if (getput_arg_fast(compiler, WORD_DATA | LOAD_DATA, TMP_REG3, src, srcw))
			FAIL_IF(compiler->error);
		else {
			compiler->cache_arg = 0;
			compiler->cache_argw = 0;
			FAIL_IF(getput_arg(compiler, WORD_DATA | LOAD_DATA, TMP_REG2, src, srcw, 0, 0));
			EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, TMP_REG3, SLJIT_UNUSED, RM(TMP_REG2)));
		}
	}
	else if (src & SLJIT_IMM)
		FAIL_IF(load_immediate(compiler, TMP_REG3, srcw));
	return push_inst(compiler, BLX | RM(TMP_REG3));
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
		return 0x00000000;

	case SLJIT_C_NOT_EQUAL:
	case SLJIT_C_MUL_OVERFLOW:
	case SLJIT_C_FLOAT_NOT_EQUAL:
		return 0x10000000;

	case SLJIT_C_LESS:
	case SLJIT_C_FLOAT_LESS:
		return 0x30000000;

	case SLJIT_C_GREATER_EQUAL:
	case SLJIT_C_FLOAT_GREATER_EQUAL:
		return 0x20000000;

	case SLJIT_C_GREATER:
	case SLJIT_C_FLOAT_GREATER:
		return 0x80000000;

	case SLJIT_C_LESS_EQUAL:
	case SLJIT_C_FLOAT_LESS_EQUAL:
		return 0x90000000;

	case SLJIT_C_SIG_LESS:
		return 0xb0000000;

	case SLJIT_C_SIG_GREATER_EQUAL:
		return 0xa0000000;

	case SLJIT_C_SIG_GREATER:
		return 0xc0000000;

	case SLJIT_C_SIG_LESS_EQUAL:
		return 0xd0000000;

	case SLJIT_C_OVERFLOW:
	case SLJIT_C_FLOAT_NAN:
		return 0x60000000;

	case SLJIT_C_NOT_OVERFLOW:
	case SLJIT_C_FLOAT_NOT_NAN:
		return 0x70000000;

	default: /* SLJIT_JUMP */
		return 0xe0000000;
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

	CHECK_ERROR_PTR();
	check_sljit_emit_jump(compiler, type);

	jump = (struct sljit_jump*)ensure_abuf(compiler, sizeof(struct sljit_jump));
	PTR_FAIL_IF(!jump);
	set_jump(jump, compiler, type & SLJIT_REWRITABLE_JUMP);
	type &= 0xff;

	/* In ARM, we don't need to touch the arguments. */
#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	if (type >= SLJIT_FAST_CALL)
		PTR_FAIL_IF(prepare_blx(compiler));
	PTR_FAIL_IF(push_inst_with_unique_literal(compiler, ((EMIT_DATA_TRANSFER(WORD_DATA | LOAD_DATA, 1, 0,
		type <= SLJIT_JUMP ? TMP_PC : TMP_REG1, TMP_PC, 0)) & ~COND_MASK) | get_cc(type), 0));

	if (jump->flags & SLJIT_REWRITABLE_JUMP) {
		jump->addr = compiler->size;
		compiler->patches++;
	}

	if (type >= SLJIT_FAST_CALL) {
		jump->flags |= IS_BL;
		PTR_FAIL_IF(emit_blx(compiler));
	}

	if (!(jump->flags & SLJIT_REWRITABLE_JUMP))
		jump->addr = compiler->size;
#else
	if (type >= SLJIT_FAST_CALL)
		jump->flags |= IS_BL;
	PTR_FAIL_IF(emit_imm(compiler, TMP_REG1, 0));
	PTR_FAIL_IF(push_inst(compiler, (((type <= SLJIT_JUMP ? BX : BLX) | RM(TMP_REG1)) & ~COND_MASK) | get_cc(type)));
	jump->addr = compiler->size;
#endif
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

#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
		if (type >= SLJIT_FAST_CALL)
			FAIL_IF(prepare_blx(compiler));
		FAIL_IF(push_inst_with_unique_literal(compiler, EMIT_DATA_TRANSFER(WORD_DATA | LOAD_DATA, 1, 0, type <= SLJIT_JUMP ? TMP_PC : TMP_REG1, TMP_PC, 0), 0));
		if (type >= SLJIT_FAST_CALL)
			FAIL_IF(emit_blx(compiler));
#else
		FAIL_IF(emit_imm(compiler, TMP_REG1, 0));
		FAIL_IF(push_inst(compiler, (type <= SLJIT_JUMP ? BX : BLX) | RM(TMP_REG1)));
#endif
		jump->addr = compiler->size;
	}
	else {
		if (src >= SLJIT_TEMPORARY_REG1 && src <= SLJIT_NO_REGISTERS)
			return push_inst(compiler, (type <= SLJIT_JUMP ? BX : BLX) | RM(src));

		SLJIT_ASSERT(src & SLJIT_MEM);
		FAIL_IF(emit_op(compiler, SLJIT_MOV, ALLOW_ANY_IMM, TMP_REG2, 0, TMP_REG1, 0, src, srcw));
		return push_inst(compiler, (type <= SLJIT_JUMP ? BX : BLX) | RM(TMP_REG2));
	}

	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE int sljit_emit_cond_value(struct sljit_compiler *compiler, int op, int dst, sljit_w dstw, int type)
{
	int reg;
	sljit_uw cc;

	CHECK_ERROR();
	check_sljit_emit_cond_value(compiler, op, dst, dstw, type);

	if (dst == SLJIT_UNUSED)
		return SLJIT_SUCCESS;

	cc = get_cc(type);
	if (GET_OPCODE(op) == SLJIT_OR) {
		if (dst >= SLJIT_TEMPORARY_REG1 && dst <= SLJIT_NO_REGISTERS) {
			EMIT_INSTRUCTION((EMIT_DATA_PROCESS_INS(ORR_DP, 0, dst, dst, SRC2_IMM | 1) & ~COND_MASK) | cc);
			if (op & SLJIT_SET_E)
				return push_inst(compiler, EMIT_DATA_PROCESS_INS(MOV_DP, SET_FLAGS, TMP_REG1, SLJIT_UNUSED, RM(dst)));
			return SLJIT_SUCCESS;
		}

		EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, TMP_REG1, SLJIT_UNUSED, SRC2_IMM | 0));
		EMIT_INSTRUCTION((EMIT_DATA_PROCESS_INS(MOV_DP, 0, TMP_REG1, SLJIT_UNUSED, SRC2_IMM | 1) & ~COND_MASK) | cc);
#if (defined SLJIT_VERBOSE && SLJIT_VERBOSE) || (defined SLJIT_DEBUG && SLJIT_DEBUG)
		compiler->skip_checks = 1;
#endif
		return emit_op(compiler, op, ALLOW_IMM, dst, dstw, TMP_REG1, 0, dst, dstw);
	}

	reg = (dst >= SLJIT_TEMPORARY_REG1 && dst <= SLJIT_NO_REGISTERS) ? dst : TMP_REG2;

	EMIT_INSTRUCTION(EMIT_DATA_PROCESS_INS(MOV_DP, 0, reg, SLJIT_UNUSED, SRC2_IMM | 0));
	EMIT_INSTRUCTION((EMIT_DATA_PROCESS_INS(MOV_DP, 0, reg, SLJIT_UNUSED, SRC2_IMM | 1) & ~COND_MASK) | cc);

	if (reg == TMP_REG2)
		return emit_op(compiler, SLJIT_MOV, ALLOW_ANY_IMM, dst, dstw, TMP_REG1, 0, TMP_REG2, 0);
	return SLJIT_SUCCESS;
}

SLJIT_API_FUNC_ATTRIBUTE struct sljit_const* sljit_emit_const(struct sljit_compiler *compiler, int dst, sljit_w dstw, sljit_w init_value)
{
	struct sljit_const *const_;
	int reg;

	CHECK_ERROR_PTR();
	check_sljit_emit_const(compiler, dst, dstw, init_value);

	const_ = (struct sljit_const*)ensure_abuf(compiler, sizeof(struct sljit_const));
	PTR_FAIL_IF(!const_);

	reg = (dst >= SLJIT_TEMPORARY_REG1 && dst <= SLJIT_NO_REGISTERS) ? dst : TMP_REG2;

#if (defined SLJIT_CONFIG_ARM_V5 && SLJIT_CONFIG_ARM_V5)
	PTR_FAIL_IF(push_inst_with_unique_literal(compiler, EMIT_DATA_TRANSFER(WORD_DATA | LOAD_DATA, 1, 0, reg, TMP_PC, 0), init_value));
	compiler->patches++;
#else
	PTR_FAIL_IF(emit_imm(compiler, reg, init_value));
#endif
	set_const(const_, compiler);

	if (reg == TMP_REG2 && dst != SLJIT_UNUSED)
		if (emit_op(compiler, SLJIT_MOV, ALLOW_ANY_IMM, dst, dstw, TMP_REG1, 0, TMP_REG2, 0))
			return NULL;
	return const_;
}

SLJIT_API_FUNC_ATTRIBUTE void sljit_set_jump_addr(sljit_uw addr, sljit_uw new_addr)
{
	inline_set_jump_addr(addr, new_addr, 1);
}

SLJIT_API_FUNC_ATTRIBUTE void sljit_set_const(sljit_uw addr, sljit_w new_constant)
{
	inline_set_const(addr, new_constant, 1);
}
