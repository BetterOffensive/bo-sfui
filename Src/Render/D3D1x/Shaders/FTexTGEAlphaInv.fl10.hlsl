SamplerState sampler_tex : register(s0);
Texture2D tex : register(t0);
void main( float4 factor : COLOR0,
           half2 tc : TEXCOORD0,
           out float4 fcolor : SV_Target0)
{
    fcolor = tex.Sample(sampler_tex,tc);
    

    fcolor.a *= factor.a;
    

    fcolor.rgb = float3(fcolor.a, fcolor.a, fcolor.a);
    
}
