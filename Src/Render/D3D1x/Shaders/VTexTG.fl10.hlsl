cbuffer Constants { 
float4 mvp[2] : packoffset(c0);
float4 texgen[2] : packoffset(c2);
};

void main( float4 pos : SV_Position,
           out half2 tc : TEXCOORD0,
           out float4 vpos : SV_Position)
{
    vpos = float4(0,0,0,1);
    vpos.x = dot(pos, mvp[0]);
    vpos.y = dot(pos, mvp[1]);
    

    tc.x = dot(pos, texgen[0]);
    tc.y = dot(pos, texgen[1]);
    
}
