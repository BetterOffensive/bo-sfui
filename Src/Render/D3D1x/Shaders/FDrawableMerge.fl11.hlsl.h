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
//   float4x4 cxmul;                    // Offset:    0 Size:    64
//   float4x4 cxmul1;                   // Offset:   64 Size:    64
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// sampler_tex[0]                    sampler      NA          NA    0        1
// sampler_tex[1]                    sampler      NA          NA    1        1
// tex[0]                            texture  float4          2d    0        1
// tex[1]                            texture  float4          2d    1        1
// Constants                         cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// TEXCOORD                 0   xy          0     NONE   float   xy  
// TEXCOORD                 1     zw        0     NONE   float     zw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue  Format   Used
// -------------------- ----- ------ -------- -------- ------- ------
// SV_Target                0   xyzw        0   TARGET   float   xyzw
//
ps_5_0
dcl_globalFlags refactoringAllowed
dcl_constantbuffer cb0[8], immediateIndexed
dcl_sampler s0, mode_default
dcl_sampler s1, mode_default
dcl_resource_texture2d (float,float,float,float) t0
dcl_resource_texture2d (float,float,float,float) t1
dcl_input_ps linear v0.xy
dcl_input_ps linear v0.zw
dcl_output o0.xyzw
dcl_temps 3
sample_indexable(texture2d)(float,float,float,float) r0.xyzw, v0.xyxx, t0.xyzw, s0
dp4 r1.x, r0.xyzw, cb0[0].xyzw
dp4 r1.y, r0.xyzw, cb0[1].xyzw
dp4 r1.z, r0.xyzw, cb0[2].xyzw
dp4 r1.w, r0.xyzw, cb0[3].xyzw
sample_indexable(texture2d)(float,float,float,float) r0.xyzw, v0.zwzz, t1.xyzw, s1
dp4 r2.x, r0.xyzw, cb0[4].xyzw
dp4 r2.y, r0.xyzw, cb0[5].xyzw
dp4 r2.z, r0.xyzw, cb0[6].xyzw
dp4 r2.w, r0.xyzw, cb0[7].xyzw
add o0.xyzw, r1.xyzw, r2.xyzw
ret 
// Approximately 12 instruction slots used
#endif

const BYTE pBinary_D3D1xFL11X_FDrawableMerge[] =
{
     68,  88,  66,  67, 100, 204, 
    246,   7,  99, 190, 219, 239, 
     37,  69,  91, 207,  41, 223, 
    167, 148,   1,   0,   0,   0, 
     68,   5,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
     40,   2,   0,   0, 116,   2, 
      0,   0, 168,   2,   0,   0, 
    168,   4,   0,   0,  82,  68, 
     69,  70, 236,   1,   0,   0, 
      1,   0,   0,   0,  20,   1, 
      0,   0,   5,   0,   0,   0, 
     60,   0,   0,   0,   0,   5, 
    255, 255,   0, 129,   0,   0, 
    183,   1,   0,   0,  82,  68, 
     49,  49,  60,   0,   0,   0, 
     24,   0,   0,   0,  32,   0, 
      0,   0,  40,   0,   0,   0, 
     36,   0,   0,   0,  12,   0, 
      0,   0,   0,   0,   0,   0, 
    220,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   1,   0, 
      0,   0, 235,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
      1,   0,   0,   0, 250,   0, 
      0,   0,   2,   0,   0,   0, 
      5,   0,   0,   0,   4,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  13,   0,   0,   0, 
      1,   1,   0,   0,   2,   0, 
      0,   0,   5,   0,   0,   0, 
      4,   0,   0,   0, 255, 255, 
    255, 255,   1,   0,   0,   0, 
      1,   0,   0,   0,  13,   0, 
      0,   0,   8,   1,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0, 115,  97, 
    109, 112, 108, 101, 114,  95, 
    116, 101, 120,  91,  48,  93, 
      0, 115,  97, 109, 112, 108, 
    101, 114,  95, 116, 101, 120, 
     91,  49,  93,   0, 116, 101, 
    120,  91,  48,  93,   0, 116, 
    101, 120,  91,  49,  93,   0, 
     67, 111, 110, 115, 116,  97, 
    110, 116, 115,   0, 171, 171, 
      8,   1,   0,   0,   2,   0, 
      0,   0,  44,   1,   0,   0, 
    128,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    124,   1,   0,   0,   0,   0, 
      0,   0,  64,   0,   0,   0, 
      2,   0,   0,   0, 140,   1, 
      0,   0,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0, 255, 255, 255, 255, 
      0,   0,   0,   0, 176,   1, 
      0,   0,  64,   0,   0,   0, 
     64,   0,   0,   0,   2,   0, 
      0,   0, 140,   1,   0,   0, 
      0,   0,   0,   0, 255, 255, 
    255, 255,   0,   0,   0,   0, 
    255, 255, 255, 255,   0,   0, 
      0,   0,  99, 120, 109, 117, 
    108,   0, 102, 108, 111,  97, 
    116,  52, 120,  52,   0, 171, 
      3,   0,   3,   0,   4,   0, 
      4,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 130,   1,   0,   0, 
     99, 120, 109, 117, 108,  49, 
      0,  77, 105,  99, 114, 111, 
    115, 111, 102, 116,  32,  40, 
     82,  41,  32,  72,  76,  83, 
     76,  32,  83, 104,  97, 100, 
    101, 114,  32,  67, 111, 109, 
    112, 105, 108, 101, 114,  32, 
     57,  46,  51,  48,  46,  57, 
     50,  48,  48,  46,  49,  54, 
     51,  56,  52,   0, 171, 171, 
     73,  83,  71,  78,  68,   0, 
      0,   0,   2,   0,   0,   0, 
      8,   0,   0,   0,  56,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   3,   0,   0,  56,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     12,  12,   0,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171, 171, 171,  79,  83, 
     71,  78,  44,   0,   0,   0, 
      1,   0,   0,   0,   8,   0, 
      0,   0,  32,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  83,  86,  95,  84, 
     97, 114, 103, 101, 116,   0, 
    171, 171,  83,  72,  69,  88, 
    248,   1,   0,   0,  80,   0, 
      0,   0, 126,   0,   0,   0, 
    106,   8,   0,   1,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  90,   0,   0,   3, 
      0,  96,  16,   0,   1,   0, 
      0,   0,  88,  24,   0,   4, 
      0, 112,  16,   0,   0,   0, 
      0,   0,  85,  85,   0,   0, 
     88,  24,   0,   4,   0, 112, 
     16,   0,   1,   0,   0,   0, 
     85,  85,   0,   0,  98,  16, 
      0,   3,  50,  16,  16,   0, 
      0,   0,   0,   0,  98,  16, 
      0,   3, 194,  16,  16,   0, 
      0,   0,   0,   0, 101,   0, 
      0,   3, 242,  32,  16,   0, 
      0,   0,   0,   0, 104,   0, 
      0,   2,   3,   0,   0,   0, 
     69,   0,   0, 139, 194,   0, 
      0, 128,  67,  85,  21,   0, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  16,  16,   0, 
      0,   0,   0,   0,  70, 126, 
     16,   0,   0,   0,   0,   0, 
      0,  96,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,   8, 
     18,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  17,   0, 
      0,   8,  34,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
     17,   0,   0,   8,  66,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,  17,   0,   0,   8, 
    130,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,  69,   0, 
      0, 139, 194,   0,   0, 128, 
     67,  85,  21,   0, 242,   0, 
     16,   0,   0,   0,   0,   0, 
    230,  26,  16,   0,   0,   0, 
      0,   0,  70, 126,  16,   0, 
      1,   0,   0,   0,   0,  96, 
     16,   0,   1,   0,   0,   0, 
     17,   0,   0,   8,  18,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,  17,   0,   0,   8, 
     34,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,  17,   0, 
      0,   8,  66,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
     17,   0,   0,   8, 130,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0,   0,   0,   0,   7, 
    242,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 148,   0,   0,   0, 
     12,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
      3,   0,   0,   0,   9,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0
};
