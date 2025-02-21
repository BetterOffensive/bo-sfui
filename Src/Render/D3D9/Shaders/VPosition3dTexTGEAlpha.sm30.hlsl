float4x4 mvp : register(c0);
float4 texgen[2] : register(c4);
void main( half4 afactor : COLOR0,
           float4 pos : POSITION0,
           out half4 factor : COLOR0,
           out half2 tc : TEXCOORD0,
           out float4 vpos : POSITION0)
{
    vpos = mul(pos, mvp);
    

    tc.x = dot(pos, texgen[0]);
    tc.y = dot(pos, texgen[1]);
    

      factor = afactor;
    
}
