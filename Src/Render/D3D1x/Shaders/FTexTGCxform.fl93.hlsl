sampler2D tex : register(s0);
void main( float4 fucxadd : TEXCOORD0,
           float4 fucxmul : TEXCOORD1,
           half2 tc : TEXCOORD2,
           out float4 fcolor : COLOR0)
{
    fcolor = tex2D(tex,tc);
    

    fcolor = fcolor * fucxmul + fucxadd;
    
}
