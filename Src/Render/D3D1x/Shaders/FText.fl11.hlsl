SamplerState sampler_tex : register(s0);
Texture2D tex : register(t0);
void main( half2 tc : TEXCOORD0,
           float4 vcolor : COLOR0,
           out float4 fcolor : SV_Target0)
{
    float4 c = vcolor;
    c.a = c.a * tex.Sample(sampler_tex, tc).r;
    fcolor = c;
    
}
