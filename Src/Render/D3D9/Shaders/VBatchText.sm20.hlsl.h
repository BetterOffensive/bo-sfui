#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.30.9200.16384
//
///
// Parameters:
//
//   float4 vfuniforms[96];
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   vfuniforms   c0      96
//

    vs_2_0
    def c96, 3.0999999, 0, 1, 0
    def c97, 4, 2.0999999, 1.10000002, 0.100000001
    dcl_color v0
    dcl_texcoord v1
    dcl_position v2
    dcl_color2 v3
    mad r0.xyz, v3.x, c97.x, c97.yzww
    frc r1.xyz, r0
    add r0.xyz, r0, -r1
    mad r0.w, v3.x, c97.x, -r1.x
    add r0.w, r0.w, c96.x
    mova a0.x, r0.w
    dp4 oPos.y, v2, c0[a0.x]
    mova a0.x, r0.x
    dp4 oPos.x, v2, c0[a0.x]
    mova a0.xy, r0.yzzw
    mov r0, c0[a0.x]
    mad oD0, v0, r0, c0[a0.y]
    mov oT0.xy, v1
    mov oPos.zw, c96.xyyz

// approximately 14 instruction slots used
#endif

const BYTE pBinary_D3D9SM20_VBatchText[] =
{
      0,   2, 254, 255, 254, 255, 
     35,   0,  67,  84,  65,  66, 
     28,   0,   0,   0,  83,   0, 
      0,   0,   0,   2, 254, 255, 
      1,   0,   0,   0,  28,   0, 
      0,   0,   0, 129,   0,   0, 
     76,   0,   0,   0,  48,   0, 
      0,   0,   2,   0,   0,   0, 
     96,   0,   2,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
    118, 102, 117, 110, 105, 102, 
    111, 114, 109, 115,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,  96,   0,   0,   0, 
      0,   0,   0,   0, 118, 115, 
     95,  50,  95,  48,   0,  77, 
    105,  99, 114, 111, 115, 111, 
    102, 116,  32,  40,  82,  41, 
     32,  72,  76,  83,  76,  32, 
     83, 104,  97, 100, 101, 114, 
     32,  67, 111, 109, 112, 105, 
    108, 101, 114,  32,  57,  46, 
     51,  48,  46,  57,  50,  48, 
     48,  46,  49,  54,  51,  56, 
     52,   0, 171, 171,  81,   0, 
      0,   5,  96,   0,  15, 160, 
    102, 102,  70,  64,   0,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,   0,  81,   0, 
      0,   5,  97,   0,  15, 160, 
      0,   0, 128,  64, 102, 102, 
      6,  64, 205, 204, 140,  63, 
    205, 204, 204,  61,  31,   0, 
      0,   2,  10,   0,   0, 128, 
      0,   0,  15, 144,  31,   0, 
      0,   2,   5,   0,   0, 128, 
      1,   0,  15, 144,  31,   0, 
      0,   2,   0,   0,   0, 128, 
      2,   0,  15, 144,  31,   0, 
      0,   2,  10,   0,   2, 128, 
      3,   0,  15, 144,   4,   0, 
      0,   4,   0,   0,   7, 128, 
      3,   0,   0, 144,  97,   0, 
      0, 160,  97,   0, 249, 160, 
     19,   0,   0,   2,   1,   0, 
      7, 128,   0,   0, 228, 128, 
      2,   0,   0,   3,   0,   0, 
      7, 128,   0,   0, 228, 128, 
      1,   0, 228, 129,   4,   0, 
      0,   4,   0,   0,   8, 128, 
      3,   0,   0, 144,  97,   0, 
      0, 160,   1,   0,   0, 129, 
      2,   0,   0,   3,   0,   0, 
      8, 128,   0,   0, 255, 128, 
     96,   0,   0, 160,  46,   0, 
      0,   2,   0,   0,   1, 176, 
      0,   0, 255, 128,   9,   0, 
      0,   4,   0,   0,   2, 192, 
      2,   0, 228, 144,   0,  32, 
    228, 160,   0,   0,   0, 176, 
     46,   0,   0,   2,   0,   0, 
      1, 176,   0,   0,   0, 128, 
      9,   0,   0,   4,   0,   0, 
      1, 192,   2,   0, 228, 144, 
      0,  32, 228, 160,   0,   0, 
      0, 176,  46,   0,   0,   2, 
      0,   0,   3, 176,   0,   0, 
    233, 128,   1,   0,   0,   3, 
      0,   0,  15, 128,   0,  32, 
    228, 160,   0,   0,   0, 176, 
      4,   0,   0,   5,   0,   0, 
     15, 208,   0,   0, 228, 144, 
      0,   0, 228, 128,   0,  32, 
    228, 160,   0,   0,  85, 176, 
      1,   0,   0,   2,   0,   0, 
      3, 224,   1,   0, 228, 144, 
      1,   0,   0,   2,   0,   0, 
     12, 192,  96,   0, 148, 160, 
    255, 255,   0,   0
};
