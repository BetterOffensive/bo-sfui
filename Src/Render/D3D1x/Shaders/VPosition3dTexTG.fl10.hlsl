cbuffer Constants { 
float4x4 mvp : packoffset(c0);
float4 texgen[2] : packoffset(c4);
};

void main( float4 pos : SV_Position,
           out half2 tc : TEXCOORD0,
           out float4 vpos : SV_Position)
{
    vpos = mul(pos, mvp);
    

    tc.x = dot(pos, texgen[0]);
    tc.y = dot(pos, texgen[1]);
    
}
