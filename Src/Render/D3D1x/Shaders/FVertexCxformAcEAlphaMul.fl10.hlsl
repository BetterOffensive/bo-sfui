void main( float4 color : COLOR0,
           float4 factor : COLOR1,
           float4 fucxadd : TEXCOORD0,
           float4 fucxmul : TEXCOORD1,
           out float4 fcolor : SV_Target0)
{
  fcolor = color;
  

      fcolor = (fcolor * float4(fucxmul.rgb,1)) * fucxmul.a;
      fcolor += fucxadd * fcolor.a;
    

    fcolor.a *= factor.a;
    

    fcolor.rgb = fcolor.rgb * fcolor.a;
    
}
