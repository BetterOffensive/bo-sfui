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
//   float4x4 vfmuniforms[24];          // Offset:    0 Size:  1536
//   float4 vfuniforms[144];            // Offset: 1536 Size:  2304
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
// COLOR                    0   xyzw        0     NONE   float   xyzw
// SV_Position              0   xyzw        1     NONE   float   xyzw
// SV_InstanceID            0   x           2   INSTID    uint   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// COLOR                    0   xyzw        0     NONE   float   xyzw
// TEXCOORD                 0   xyzw        1     NONE   float   xyzw
// TEXCOORD                 1   xyzw        2     NONE   float   xyzw
// TEXCOORD                 2   xy          3     NONE   float   xy  
// TEXCOORD                 3     zw        3     NONE   float     zw
// SV_Position              0   xyzw        4      POS   float   xyzw
//
vs_4_0
dcl_constantbuffer cb0[240], dynamicIndexed
dcl_input v0.xyzw
dcl_input v1.xyzw
dcl_input_sgv v2.x, instance_id
dcl_output o0.xyzw
dcl_output o1.xyzw
dcl_output o2.xyzw
dcl_output o3.xy
dcl_output o3.zw
dcl_output_siv o4.xyzw, position
dcl_temps 1
mov o0.xyzw, v0.xyzw
imul null, r0.x, v2.x, l(6)
imad r0.y, v2.x, l(6), l(1)
utof r0.xy, r0.xyxx
add r0.xy, r0.xyxx, l(0.100000, 0.100000, 0.000000, 0.000000)
ftou r0.xy, r0.xyxx
mov o2.xyzw, cb0[r0.y + 96].xyzw
mov o1.xyzw, cb0[r0.x + 96].xyzw
imad r0.x, v2.x, l(6), l(2)
utof r0.x, r0.x
add r0.xyzw, r0.xxxx, l(0.100000, 1.100000, 2.100000, 3.100000)
ftou r0.xyzw, r0.xyzw
dp4 o3.x, v1.xyzw, cb0[r0.x + 96].xyzw
dp4 o3.y, v1.xyzw, cb0[r0.y + 96].xyzw
dp4 o3.z, v1.xyzw, cb0[r0.z + 96].xyzw
dp4 o3.w, v1.xyzw, cb0[r0.w + 96].xyzw
utof r0.x, v2.x
add r0.x, r0.x, l(0.100000)
ftou r0.x, r0.x
ishl r0.x, r0.x, l(2)
dp4 o4.x, v1.xyzw, cb0[r0.x + 0].xyzw
dp4 o4.y, v1.xyzw, cb0[r0.x + 1].xyzw
dp4 o4.z, v1.xyzw, cb0[r0.x + 2].xyzw
dp4 o4.w, v1.xyzw, cb0[r0.x + 3].xyzw
ret 
// Approximately 25 instruction slots used
#endif

const BYTE pBinary_D3D1xFL10X_VInstancedPosition3dTexTGTexTGCxform[] =
{
     68,  88,  66,  67,  89, 219, 
    126,  30,  89, 160, 105, 159, 
     61, 109,  35, 201,   5,  47, 
     78, 224,   1,   0,   0,   0, 
    128,   6,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     56,   1,   0,   0, 176,   1, 
      0,   0, 108,   2,   0,   0, 
      4,   6,   0,   0,  82,  68, 
     69,  70, 252,   0,   0,   0, 
      1,   0,   0,   0,  72,   0, 
      0,   0,   1,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    254, 255,   0, 129,   0,   0, 
    200,   0,   0,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
     67, 111, 110, 115, 116,  97, 
    110, 116, 115,   0, 171, 171, 
     60,   0,   0,   0,   2,   0, 
      0,   0,  96,   0,   0,   0, 
      0,  15,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    144,   0,   0,   0,   0,   0, 
      0,   0,   0,   6,   0,   0, 
      2,   0,   0,   0, 156,   0, 
      0,   0,   0,   0,   0,   0, 
    172,   0,   0,   0,   0,   6, 
      0,   0,   0,   9,   0,   0, 
      2,   0,   0,   0, 184,   0, 
      0,   0,   0,   0,   0,   0, 
    118, 102, 109, 117, 110, 105, 
    102, 111, 114, 109, 115,   0, 
      3,   0,   3,   0,   4,   0, 
      4,   0,  24,   0,   0,   0, 
      0,   0,   0,   0, 118, 102, 
    117, 110, 105, 102, 111, 114, 
    109, 115,   0, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
    144,   0,   0,   0,   0,   0, 
      0,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  57,  46,  51,  48,  46, 
     57,  50,  48,  48,  46,  49, 
     54,  51,  56,  52,   0, 171, 
     73,  83,  71,  78, 112,   0, 
      0,   0,   3,   0,   0,   0, 
      8,   0,   0,   0,  80,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,  15,   0,   0,  86,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,  15,   0,   0,  98,   0, 
      0,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,   1,   0, 
      0,   0,   2,   0,   0,   0, 
      1,   1,   0,   0,  67,  79, 
     76,  79,  82,   0,  83,  86, 
     95,  80, 111, 115, 105, 116, 
    105, 111, 110,   0,  83,  86, 
     95,  73, 110, 115, 116,  97, 
    110,  99, 101,  73,  68,   0, 
     79,  83,  71,  78, 180,   0, 
      0,   0,   6,   0,   0,   0, 
      8,   0,   0,   0, 152,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0, 158,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,   0,   0,   0, 158,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
     15,   0,   0,   0, 158,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
      3,  12,   0,   0, 158,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
     12,   3,   0,   0, 167,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
     15,   0,   0,   0,  67,  79, 
     76,  79,  82,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0,  83,  86,  95,  80, 111, 
    115, 105, 116, 105, 111, 110, 
      0, 171,  83,  72,  68,  82, 
    144,   3,   0,   0,  64,   0, 
      1,   0, 228,   0,   0,   0, 
     89,   8,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
    240,   0,   0,   0,  95,   0, 
      0,   3, 242,  16,  16,   0, 
      0,   0,   0,   0,  95,   0, 
      0,   3, 242,  16,  16,   0, 
      1,   0,   0,   0,  96,   0, 
      0,   4,  18,  16,  16,   0, 
      2,   0,   0,   0,   8,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   2,   0, 
      0,   0, 101,   0,   0,   3, 
     50,  32,  16,   0,   3,   0, 
      0,   0, 101,   0,   0,   3, 
    194,  32,  16,   0,   3,   0, 
      0,   0, 103,   0,   0,   4, 
    242,  32,  16,   0,   4,   0, 
      0,   0,   1,   0,   0,   0, 
    104,   0,   0,   2,   1,   0, 
      0,   0,  54,   0,   0,   5, 
    242,  32,  16,   0,   0,   0, 
      0,   0,  70,  30,  16,   0, 
      0,   0,   0,   0,  38,   0, 
      0,   8,   0, 208,   0,   0, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,  16,  16,   0, 
      2,   0,   0,   0,   1,  64, 
      0,   0,   6,   0,   0,   0, 
     35,   0,   0,   9,  34,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      6,   0,   0,   0,   1,  64, 
      0,   0,   1,   0,   0,   0, 
     86,   0,   0,   5,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,  10, 
     50,   0,  16,   0,   0,   0, 
      0,   0,  70,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0, 205, 204, 204,  61, 
    205, 204, 204,  61,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     28,   0,   0,   5,  50,   0, 
     16,   0,   0,   0,   0,   0, 
     70,   0,  16,   0,   0,   0, 
      0,   0,  54,   0,   0,   8, 
    242,  32,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,  96,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   8, 242,  32,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   6,   0,   0,   0,   0, 
     96,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     35,   0,   0,   9,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   2,   0, 
      0,   0,   1,  64,   0,   0, 
      6,   0,   0,   0,   1,  64, 
      0,   0,   2,   0,   0,   0, 
     86,   0,   0,   5,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,  10, 
    242,   0,  16,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0, 205, 204, 204,  61, 
    205, 204, 140,  63, 102, 102, 
      6,  64, 102, 102,  70,  64, 
     28,   0,   0,   5, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,  10, 
     18,  32,  16,   0,   3,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   6,   0,   0,   0,   0, 
     96,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     17,   0,   0,  10,  34,  32, 
     16,   0,   3,   0,   0,   0, 
     70,  30,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,  96,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  17,   0, 
      0,  10,  66,  32,  16,   0, 
      3,   0,   0,   0,  70,  30, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   6,   0,   0, 
      0,   0,  96,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,  10, 
    130,  32,  16,   0,   3,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   6,   0,   0,   0,   0, 
     96,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     86,   0,   0,   5,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,  16,  16,   0,   2,   0, 
      0,   0,   0,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0, 205, 204, 204,  61, 
     28,   0,   0,   5,  18,   0, 
     16,   0,   0,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  41,   0,   0,   7, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,   1,  64, 
      0,   0,   2,   0,   0,   0, 
     17,   0,   0,   9,  18,  32, 
     16,   0,   4,   0,   0,   0, 
     70,  30,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   4, 
      0,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     17,   0,   0,  10,  34,  32, 
     16,   0,   4,   0,   0,   0, 
     70,  30,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   6, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  10,   0,  16,   0, 
      0,   0,   0,   0,  17,   0, 
      0,  10,  66,  32,  16,   0, 
      4,   0,   0,   0,  70,  30, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   6,   0,   0, 
      0,   0,   2,   0,   0,   0, 
     10,   0,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,  10, 
    130,  32,  16,   0,   4,   0, 
      0,   0,  70,  30,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   6,   0,   0,   0,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   0,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
     25,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  11,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      6,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0
};
