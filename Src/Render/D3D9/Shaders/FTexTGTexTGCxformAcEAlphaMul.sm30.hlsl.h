#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.30.9200.16384
//
///
// Parameters:
//
//   sampler2D tex[2];
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   tex          s0       2
//

    ps_3_0
    def c0, 1, 0, 0, 0
    dcl_color v0.xw
    dcl_texcoord v1
    dcl_texcoord1 v2
    dcl_texcoord2_pp v3.xy
    dcl_texcoord3_pp v4.xy
    dcl_2d s0
    dcl_2d s1
    texld r0, v3, s0
    texld r1, v4, s1
    lrp r2, v0.x, r0, r1
    mad r0, v2.xyzx, c0.xxxy, c0.yyyx
    mul r0, r0, r2
    mul r0, r0, v2.w
    mad r0, v1, r0.w, r0
    mul r0.w, r0.w, v0.w
    mul oC0.xyz, r0.w, r0
    mov oC0.w, r0.w

// approximately 10 instruction slots used (2 texture, 8 arithmetic)
#endif

const BYTE pBinary_D3D9SM30_FTexTGTexTGCxformAcEAlphaMul[] =
{
      0,   3, 255, 255, 254, 255, 
     33,   0,  67,  84,  65,  66, 
     28,   0,   0,   0,  75,   0, 
      0,   0,   0,   3, 255, 255, 
      1,   0,   0,   0,  28,   0, 
      0,   0,   0, 129,   0,   0, 
     68,   0,   0,   0,  48,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   2,   0,  52,   0, 
      0,   0,   0,   0,   0,   0, 
    116, 101, 120,   0,   4,   0, 
     12,   0,   1,   0,   1,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0, 112, 115,  95,  51, 
     95,  48,   0,  77, 105,  99, 
    114, 111, 115, 111, 102, 116, 
     32,  40,  82,  41,  32,  72, 
     76,  83,  76,  32,  83, 104, 
     97, 100, 101, 114,  32,  67, 
    111, 109, 112, 105, 108, 101, 
    114,  32,  57,  46,  51,  48, 
     46,  57,  50,  48,  48,  46, 
     49,  54,  51,  56,  52,   0, 
    171, 171,  81,   0,   0,   5, 
      0,   0,  15, 160,   0,   0, 
    128,  63,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  31,   0,   0,   2, 
     10,   0,   0, 128,   0,   0, 
      9, 144,  31,   0,   0,   2, 
      5,   0,   0, 128,   1,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   1, 128,   2,   0, 
     15, 144,  31,   0,   0,   2, 
      5,   0,   2, 128,   3,   0, 
     35, 144,  31,   0,   0,   2, 
      5,   0,   3, 128,   4,   0, 
     35, 144,  31,   0,   0,   2, 
      0,   0,   0, 144,   0,   8, 
     15, 160,  31,   0,   0,   2, 
      0,   0,   0, 144,   1,   8, 
     15, 160,  66,   0,   0,   3, 
      0,   0,  15, 128,   3,   0, 
    228, 144,   0,   8, 228, 160, 
     66,   0,   0,   3,   1,   0, 
     15, 128,   4,   0, 228, 144, 
      1,   8, 228, 160,  18,   0, 
      0,   4,   2,   0,  15, 128, 
      0,   0,   0, 144,   0,   0, 
    228, 128,   1,   0, 228, 128, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   2,   0,  36, 144, 
      0,   0,  64, 160,   0,   0, 
     21, 160,   5,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 128,   2,   0, 228, 128, 
      5,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 128, 
      2,   0, 255, 144,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      1,   0, 228, 144,   0,   0, 
    255, 128,   0,   0, 228, 128, 
      5,   0,   0,   3,   0,   0, 
      8, 128,   0,   0, 255, 128, 
      0,   0, 255, 144,   5,   0, 
      0,   3,   0,   8,   7, 128, 
      0,   0, 255, 128,   0,   0, 
    228, 128,   1,   0,   0,   2, 
      0,   8,   8, 128,   0,   0, 
    255, 128, 255, 255,   0,   0
};
