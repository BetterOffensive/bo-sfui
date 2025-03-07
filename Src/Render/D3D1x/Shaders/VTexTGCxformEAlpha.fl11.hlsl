cbuffer Constants { 
float4 cxadd : packoffset(c0);
float4 cxmul : packoffset(c1);
float4 mvp[2] : packoffset(c2);
float4 texgen[2] : packoffset(c4);
};

void main( half4 afactor : COLOR0,
           float4 pos : SV_Position,
           out half4 factor : COLOR0,
           out float4 fucxadd : TEXCOORD0,
           out float4 fucxmul : TEXCOORD1,
           out half2 tc : TEXCOORD2,
           out float4 vpos : SV_Position)
{
    vpos = float4(0,0,0,1);
    vpos.x = dot(pos, mvp[0]);
    vpos.y = dot(pos, mvp[1]);
    

    tc.x = dot(pos, texgen[0]);
    tc.y = dot(pos, texgen[1]);
    

    fucxadd = cxadd;
    fucxmul = cxmul;
    

      factor = afactor;
    
}
