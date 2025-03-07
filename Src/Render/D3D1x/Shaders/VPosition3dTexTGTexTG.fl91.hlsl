float4x4 mvp : register(c0);
float4 texgen[4] : register(c4);
void main( half4 afactor : COLOR0,
           float4 pos : POSITION0,
           out half4 factor : COLOR0,
           out half2 tc0 : TEXCOORD0,
           out half2 tc1 : TEXCOORD1,
           out float4 vpos : POSITION0)
{
    vpos = mul(pos, mvp);
    

    tc0.x = dot(pos, texgen[0]);
    tc0.y = dot(pos, texgen[1]);
    tc1.x = dot(pos, texgen[2]);
    tc1.y = dot(pos, texgen[3]);
    

      factor = afactor;
    
}
