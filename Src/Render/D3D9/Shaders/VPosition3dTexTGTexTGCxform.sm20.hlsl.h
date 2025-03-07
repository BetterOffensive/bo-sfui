#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.30.9200.16384
//
///
// Parameters:
//
//   float4 cxadd;
//   float4 cxmul;
//   float4x4 mvp;
//   float4 texgen[4];
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   cxadd        c0       1
//   cxmul        c1       1
//   mvp          c2       4
//   texgen       c6       4
//

    vs_2_0
    dcl_color v0
    dcl_position v1
    dp4 oPos.x, v1, c2
    dp4 oPos.y, v1, c3
    dp4 oPos.z, v1, c4
    dp4 oPos.w, v1, c5
    dp4 oT2.x, v1, c6
    dp4 oT2.y, v1, c7
    dp4 oT3.x, v1, c8
    dp4 oT3.y, v1, c9
    mov oD0, v0
    mov oT0, c0
    mov oT1, c1

// approximately 11 instruction slots used
#endif

const BYTE pBinary_D3D9SM20_VPosition3dTexTGTexTGCxform[] =
{
      0,   2, 254, 255, 254, 255, 
     62,   0,  67,  84,  65,  66, 
     28,   0,   0,   0, 191,   0, 
      0,   0,   0,   2, 254, 255, 
      4,   0,   0,   0,  28,   0, 
      0,   0,   0, 129,   0,   0, 
    184,   0,   0,   0, 108,   0, 
      0,   0,   2,   0,   0,   0, 
      1,   0,   2,   0, 116,   0, 
      0,   0,   0,   0,   0,   0, 
    132,   0,   0,   0,   2,   0, 
      1,   0,   1,   0,   6,   0, 
    116,   0,   0,   0,   0,   0, 
      0,   0, 138,   0,   0,   0, 
      2,   0,   2,   0,   4,   0, 
     10,   0, 144,   0,   0,   0, 
      0,   0,   0,   0, 160,   0, 
      0,   0,   2,   0,   6,   0, 
      4,   0,  26,   0, 168,   0, 
      0,   0,   0,   0,   0,   0, 
     99, 120,  97, 100, 100,   0, 
    171, 171,   1,   0,   3,   0, 
      1,   0,   4,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     99, 120, 109, 117, 108,   0, 
    109, 118, 112,   0, 171, 171, 
      3,   0,   3,   0,   4,   0, 
      4,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 116, 101, 
    120, 103, 101, 110,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,   4,   0,   0,   0, 
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
     52,   0, 171, 171,  31,   0, 
      0,   2,  10,   0,   0, 128, 
      0,   0,  15, 144,  31,   0, 
      0,   2,   0,   0,   0, 128, 
      1,   0,  15, 144,   9,   0, 
      0,   3,   0,   0,   1, 192, 
      1,   0, 228, 144,   2,   0, 
    228, 160,   9,   0,   0,   3, 
      0,   0,   2, 192,   1,   0, 
    228, 144,   3,   0, 228, 160, 
      9,   0,   0,   3,   0,   0, 
      4, 192,   1,   0, 228, 144, 
      4,   0, 228, 160,   9,   0, 
      0,   3,   0,   0,   8, 192, 
      1,   0, 228, 144,   5,   0, 
    228, 160,   9,   0,   0,   3, 
      2,   0,   1, 224,   1,   0, 
    228, 144,   6,   0, 228, 160, 
      9,   0,   0,   3,   2,   0, 
      2, 224,   1,   0, 228, 144, 
      7,   0, 228, 160,   9,   0, 
      0,   3,   3,   0,   1, 224, 
      1,   0, 228, 144,   8,   0, 
    228, 160,   9,   0,   0,   3, 
      3,   0,   2, 224,   1,   0, 
    228, 144,   9,   0, 228, 160, 
      1,   0,   0,   2,   0,   0, 
     15, 208,   0,   0, 228, 144, 
      1,   0,   0,   2,   0,   0, 
     15, 224,   0,   0, 228, 160, 
      1,   0,   0,   2,   1,   0, 
     15, 224,   1,   0, 228, 160, 
    255, 255,   0,   0
};
