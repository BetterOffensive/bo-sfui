cbuffer Constants { 
float4x4 vfmuniforms[24] : packoffset(c0);
float4 vfuniforms[96] : packoffset(c96);
};

void main( float4 acolor : COLOR0,
           half4 afactor : COLOR1,
           float4 pos : SV_Position,
           out float4 color : COLOR0,
           out half4 factor : COLOR1,
           out float4 fucxadd : TEXCOORD0,
           out float4 fucxmul : TEXCOORD1,
           out half2 tc : TEXCOORD2,
           out float4 vpos : SV_Position)
{
    vpos = mul(pos, vfmuniforms[afactor.b*255.01f * 1 + 0+ 0.1f]);
    

    color = acolor;
    tc.x = dot(pos, vfuniforms[afactor.b*255.01f * 4 + 2+ 0.1f + 0]);
    tc.y = dot(pos, vfuniforms[afactor.b*255.01f * 4 + 2+ 0.1f + 1]);
    

    fucxadd = vfuniforms[afactor.b*255.01f * 4 + 0+ 0.1f];
    fucxmul = vfuniforms[afactor.b*255.01f * 4 + 1+ 0.1f];
    

      factor = afactor;
    
}
