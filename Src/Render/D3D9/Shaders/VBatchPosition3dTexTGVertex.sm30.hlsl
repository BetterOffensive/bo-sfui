float4x4 vfmuniforms[24] : register(c0);
float4 vfuniforms[48] : register(c96);
void main( float4 acolor : COLOR0,
           half4 afactor : COLOR1,
           float4 pos : POSITION0,
           out float4 color : COLOR0,
           out half4 factor : COLOR1,
           out half2 tc : TEXCOORD0,
           out float4 vpos : POSITION0)
{
    vpos = mul(pos, vfmuniforms[afactor.b*255.01f * 1 + 0+ 0.1f]);
    

    color = acolor;
    tc.x = dot(pos, vfuniforms[afactor.b*255.01f * 2 + 0+ 0.1f + 0]);
    tc.y = dot(pos, vfuniforms[afactor.b*255.01f * 2 + 0+ 0.1f + 1]);
    

      factor = afactor;
    
}
