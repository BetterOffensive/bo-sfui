cbuffer Constants { 
float4 mvp[2] : packoffset(c0);
float4 texgen[6] : packoffset(c2);
};

void main( float4 pos : SV_Position,
           out half2 tc0 : TEXCOORD0,
           out half2 tc1 : TEXCOORD1,
           out half2 tc2 : TEXCOORD2,
           out float4 vpos : SV_Position)
{
    vpos = float4(0,0,0,1);
    vpos.x = dot(pos, mvp[0]);
    vpos.y = dot(pos, mvp[1]);
    

    tc0.x = dot(pos, texgen[0]);
    tc0.y = dot(pos, texgen[1]);
    tc1.x = dot(pos, texgen[2]);
    tc1.y = dot(pos, texgen[3]);
    tc2.x = dot(pos, texgen[4]);
    tc2.y = dot(pos, texgen[5]);
    
}
