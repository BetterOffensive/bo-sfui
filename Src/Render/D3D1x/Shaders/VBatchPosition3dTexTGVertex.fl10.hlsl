cbuffer Constants { 
float4x4 vfmuniforms[24] : packoffset(c0);
float4 vfuniforms[48] : packoffset(c96);
};

void main( float4 acolor : COLOR0,
           half4 afactor : COLOR1,
           float4 pos : SV_Position,
           out float4 color : COLOR0,
           out half4 factor : COLOR1,
           out half2 tc : TEXCOORD0,
           out float4 vpos : SV_Position)
{
    vpos = mul(pos, vfmuniforms[afactor.b*255.01f * 1 + 0+ 0.1f]);
    

    color = acolor;
    tc.x = dot(pos, vfuniforms[afactor.b*255.01f * 2 + 0+ 0.1f + 0]);
    tc.y = dot(pos, vfuniforms[afactor.b*255.01f * 2 + 0+ 0.1f + 1]);
    

      factor = afactor;
    
}
