#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.30.9200.16384
//
///
// Parameters:
//
//   float4 vfuniforms[192];
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   vfuniforms   c0     192
//

    vs_2_0
    def c192, 2.0999999, 4.0999999, 0.100000001, 1.10000002
    def c193, 2040.07996, 0, 1, 0
    def c194, 3.0999999, 5.0999999, 6.0999999, 7.0999999
    dcl_color v0
    dcl_position v1
    mov r0.x, c193.x
    mad r0, v0.z, r0.x, c192
    frc r1, r0
    add r0, r0, -r1
    mad r1, v0.z, c193.x, -r1.xyyy
    add r1, r1, c194
    mova a0.x, r0.x
    dp4 oPos.x, v1, c0[a0.x]
    mova a0.x, r1.x
    dp4 oPos.y, v1, c0[a0.x]
    mova a0.x, r0.y
    dp4 oT2.x, v1, c0[a0.x]
    mova a0.x, r1.y
    dp4 oT2.y, v1, c0[a0.x]
    mova a0.xy, r1.zwzw
    dp4 oT3.y, v1, c0[a0.y]
    dp4 oT3.x, v1, c0[a0.x]
    mov oD0, v0
    mova a0.xy, r0.zwzw
    mov oT1, c0[a0.y]
    mov oT0, c0[a0.x]
    mov oPos.zw, c193.xyyz

// approximately 22 instruction slots used
#endif

const BYTE pBinary_D3D9SM20_VBatchTexTGTexTGCxform[] =
{
      0,   2, 254, 255, 254, 255, 
     35,   0,  67,  84,  65,  66, 
     28,   0,   0,   0,  83,   0, 
      0,   0,   0,   2, 254, 255, 
      1,   0,   0,   0,  28,   0, 
      0,   0,   0, 129,   0,   0, 
     76,   0,   0,   0,  48,   0, 
      0,   0,   2,   0,   0,   0, 
    192,   0,   2,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
    118, 102, 117, 110, 105, 102, 
    111, 114, 109, 115,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0, 192,   0,   0,   0, 
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
      0,   5, 192,   0,  15, 160, 
    102, 102,   6,  64,  51,  51, 
    131,  64, 205, 204, 204,  61, 
    205, 204, 140,  63,  81,   0, 
      0,   5, 193,   0,  15, 160, 
    143,   2, 255,  68,   0,   0, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,   0,  81,   0, 
      0,   5, 194,   0,  15, 160, 
    102, 102,  70,  64,  51,  51, 
    163,  64,  51,  51, 195,  64, 
     51,  51, 227,  64,  31,   0, 
      0,   2,  10,   0,   0, 128, 
      0,   0,  15, 144,  31,   0, 
      0,   2,   0,   0,   0, 128, 
      1,   0,  15, 144,   1,   0, 
      0,   2,   0,   0,   1, 128, 
    193,   0,   0, 160,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      0,   0, 170, 144,   0,   0, 
      0, 128, 192,   0, 228, 160, 
     19,   0,   0,   2,   1,   0, 
     15, 128,   0,   0, 228, 128, 
      2,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 128, 
      1,   0, 228, 129,   4,   0, 
      0,   4,   1,   0,  15, 128, 
      0,   0, 170, 144, 193,   0, 
      0, 160,   1,   0,  84, 129, 
      2,   0,   0,   3,   1,   0, 
     15, 128,   1,   0, 228, 128, 
    194,   0, 228, 160,  46,   0, 
      0,   2,   0,   0,   1, 176, 
      0,   0,   0, 128,   9,   0, 
      0,   4,   0,   0,   1, 192, 
      1,   0, 228, 144,   0,  32, 
    228, 160,   0,   0,   0, 176, 
     46,   0,   0,   2,   0,   0, 
      1, 176,   1,   0,   0, 128, 
      9,   0,   0,   4,   0,   0, 
      2, 192,   1,   0, 228, 144, 
      0,  32, 228, 160,   0,   0, 
      0, 176,  46,   0,   0,   2, 
      0,   0,   1, 176,   0,   0, 
     85, 128,   9,   0,   0,   4, 
      2,   0,   1, 224,   1,   0, 
    228, 144,   0,  32, 228, 160, 
      0,   0,   0, 176,  46,   0, 
      0,   2,   0,   0,   1, 176, 
      1,   0,  85, 128,   9,   0, 
      0,   4,   2,   0,   2, 224, 
      1,   0, 228, 144,   0,  32, 
    228, 160,   0,   0,   0, 176, 
     46,   0,   0,   2,   0,   0, 
      3, 176,   1,   0, 238, 128, 
      9,   0,   0,   4,   3,   0, 
      2, 224,   1,   0, 228, 144, 
      0,  32, 228, 160,   0,   0, 
     85, 176,   9,   0,   0,   4, 
      3,   0,   1, 224,   1,   0, 
    228, 144,   0,  32, 228, 160, 
      0,   0,   0, 176,   1,   0, 
      0,   2,   0,   0,  15, 208, 
      0,   0, 228, 144,  46,   0, 
      0,   2,   0,   0,   3, 176, 
      0,   0, 238, 128,   1,   0, 
      0,   3,   1,   0,  15, 224, 
      0,  32, 228, 160,   0,   0, 
     85, 176,   1,   0,   0,   3, 
      0,   0,  15, 224,   0,  32, 
    228, 160,   0,   0,   0, 176, 
      1,   0,   0,   2,   0,   0, 
     12, 192, 193,   0, 148, 160, 
    255, 255,   0,   0
};
