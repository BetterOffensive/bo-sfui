sampler2D tex : register(s0);
void main( float4 color : COLOR0,
           float4 factor : COLOR1,
           float4 fucxadd : TEXCOORD0,
           float4 fucxmul : TEXCOORD1,
           half2 tc : TEXCOORD2,
           out float4 fcolor : COLOR0)
{
    float4 fcolor0 = tex2D(tex,tc);
    float4 fcolor1 = color;
    fcolor = lerp(fcolor1, fcolor0, factor.r);
    

    fcolor = fcolor * fucxmul + fucxadd;
    

    fcolor.a *= factor.a;
    
}
