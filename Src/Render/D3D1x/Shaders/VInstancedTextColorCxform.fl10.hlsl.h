#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.30.9200.16384
//
//
///
// Buffer Definitions: 
//
// cbuffer Constants
// {
//
//   float4 vfuniforms[96];             // Offset:    0 Size:  1536
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// Constants                         cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xy          0     NONE   float   xy  
// SV_Position              0   xyzw        1     NONE   float   xyzw
// SV_InstanceID            0   x           2   INSTID    uint   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xyzw        0     NONE   float   xyzw
// TEXCOORD                 1   xyzw        1     NONE   float   xyzw
// TEXCOORD                 2   xy          2     NONE   float   xy  
// SV_Position              0   xyzw        3      POS   float   xyzw
//
vs_4_0
dcl_constantbuffer cb0[96], dynamicIndexed
dcl_input v0.xy
dcl_input v1.xyzw
dcl_input_sgv v2.x, instance_id
dcl_output o0.xyzw
dcl_output o1.xyzw
dcl_output o2.xy
dcl_output_siv o3.xyzw, position
dcl_temps 1
ishl r0.x, v2.x, l(2)
utof r0.y, r0.x
iadd r0.xzw, r0.xxxx, l(2, 0, 2, 1)
utof r0.xzw, r0.xxzw
add r0.xyzw, r0.xyzw, l(0.100000, 0.100000, 1.100000, 0.100000)
ftou r0.xyzw, r0.xyzw
mov o0.xyzw, cb0[r0.y + 0].xyzw
mov o1.xyzw, cb0[r0.w + 0].xyzw
mov o2.xy, v0.xyxx
dp4 o3.x, v1.xyzw, cb0[r0.x + 0].xyzw
dp4 o3.y, v1.xyzw, cb0[r0.z + 0].xyzw
mov o3.zw, l(0,0,0,1.000000)
ret 
// Approximately 13 instruction slots used
#endif

const BYTE pBinary_D3D1xFL10X_VInstancedTextColorCxform[] =
{
     68,  88,  66,  67,  61,  11, 
    214,  54,  64, 147,   4, 144, 
    152,  77,  53,  54,  79, 174, 
    235,  40,   1,   0,   0,   0, 
    104,   4,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
      4,   1,   0,   0, 128,   1, 
      0,   0,   8,   2,   0,   0, 
    236,   3,   0,   0,  82,  68, 
     69,  70, 200,   0,   0,   0, 
      1,   0,   0,   0,  72,   0, 
      0,   0,   1,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    254, 255,   0, 129,   0,   0, 
    148,   0,   0,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     67, 111, 110, 115, 116,  97, 
    110, 116, 115,   0, 171, 171, 
     60,   0,   0,   0,   1,   0, 
      0,   0,  96,   0,   0,   0, 
      0,   6,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    120,   0,   0,   0,   0,   0, 
      0,   0,   0,   6,   0,   0, 
      2,   0,   0,   0, 132,   0, 
      0,   0,   0,   0,   0,   0, 
    118, 102, 117, 110, 105, 102, 
    111, 114, 109, 115,   0, 171, 
      1,   0,   3,   0,   1,   0, 
      4,   0,  96,   0,   0,   0, 
      0,   0,   0,   0,  77, 105, 
     99, 114, 111, 115, 111, 102, 
    116,  32,  40,  82,  41,  32, 
     72,  76,  83,  76,  32,  83, 
    104,  97, 100, 101, 114,  32, 
     67, 111, 109, 112, 105, 108, 
    101, 114,  32,  57,  46,  51, 
     48,  46,  57,  50,  48,  48, 
     46,  49,  54,  51,  56,  52, 
      0, 171,  73,  83,  71,  78, 
    116,   0,   0,   0,   3,   0, 
      0,   0,   8,   0,   0,   0, 
     80,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,   3,   0,   0, 
     89,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0,  15,  15,   0,   0, 
    101,   0,   0,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
      1,   0,   0,   0,   2,   0, 
      0,   0,   1,   1,   0,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0,  83,  86,  95, 
     80, 111, 115, 105, 116, 105, 
    111, 110,   0,  83,  86,  95, 
     73, 110, 115, 116,  97, 110, 
     99, 101,  73,  68,   0, 171, 
     79,  83,  71,  78, 128,   0, 
      0,   0,   4,   0,   0,   0, 
      8,   0,   0,   0, 104,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0, 104,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,   0,   0,   0, 104,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      3,  12,   0,   0, 113,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
     15,   0,   0,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0,  83,  86,  95,  80, 111, 
    115, 105, 116, 105, 111, 110, 
      0, 171, 171, 171,  83,  72, 
     68,  82, 220,   1,   0,   0, 
     64,   0,   1,   0, 119,   0, 
      0,   0,  89,   8,   0,   4, 
     70, 142,  32,   0,   0,   0, 
      0,   0,  96,   0,   0,   0, 
     95,   0,   0,   3,  50,  16, 
     16,   0,   0,   0,   0,   0, 
     95,   0,   0,   3, 242,  16, 
     16,   0,   1,   0,   0,   0, 
     96,   0,   0,   4,  18,  16, 
     16,   0,   2,   0,   0,   0, 
      8,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      1,   0,   0,   0, 101,   0, 
      0,   3,  50,  32,  16,   0, 
      2,   0,   0,   0, 103,   0, 
      0,   4, 242,  32,  16,   0, 
      3,   0,   0,   0,   1,   0, 
      0,   0, 104,   0,   0,   2, 
      1,   0,   0,   0,  41,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  10,  16, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   2,   0, 
      0,   0,  86,   0,   0,   5, 
     34,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  30,   0, 
      0,  10, 210,   0,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   1,   0, 
      0,   0,  86,   0,   0,   5, 
    210,   0,  16,   0,   0,   0, 
      0,   0,   6,  14,  16,   0, 
      0,   0,   0,   0,   0,   0, 
      0,  10, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0, 205, 204, 
    204,  61, 205, 204, 204,  61, 
    205, 204, 140,  63, 205, 204, 
    204,  61,  28,   0,   0,   5, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   7, 242,  32,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   4,   0,   0,   0,   0, 
     26,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   7, 
    242,  32,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   4, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     54,   0,   0,   5,  50,  32, 
     16,   0,   2,   0,   0,   0, 
     70,  16,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,   9, 
     18,  32,  16,   0,   3,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   4,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,   9, 
     34,  32,  16,   0,   3,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   4,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   8, 
    194,  32,  16,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 128,  63,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    116,   0,   0,   0,  13,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};
