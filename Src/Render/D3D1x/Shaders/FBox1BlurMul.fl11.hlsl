cbuffer Constants { 
float4 fsize : packoffset(c0);
float4 texscale : packoffset(c1);
};

SamplerState sampler_tex : register(s0);
Texture2D tex : register(t0);
void main( float4 fucxadd : TEXCOORD0,
           float4 fucxmul : TEXCOORD1,
           float2 tc : TEXCOORD2,
           out float4 fcolor : SV_Target0)
{
      fcolor       = float4(0, 0, 0, 0);
      float4 color = float4(0, 0, 0, 0);
      float  i = 0;
      for (i = -fsize.x; i <= fsize.x; i++)
      {{
    

    color += tex.SampleLevel(sampler_tex, tc + i * texscale.xy, 0.0f);
    }} // EndBox1/2.
    fcolor = color * fsize.w;
    

      fcolor = (fcolor * float4(fucxmul.rgb,1)) * fucxmul.a;
      fcolor += fucxadd * fcolor.a;
    

    fcolor.rgb = fcolor.rgb * fcolor.a;
    
}
