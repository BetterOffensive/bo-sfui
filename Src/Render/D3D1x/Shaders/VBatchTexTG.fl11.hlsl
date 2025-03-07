cbuffer Constants { 
float4 vfuniforms[96] : packoffset(c0);
};

void main( float4 pos : SV_Position,
           uint vbatch : COLOR1,
           out half2 tc : TEXCOORD0,
           out float4 vpos : SV_Position)
{
    vpos = float4(0,0,0,1);
    vpos.x = dot(pos, vfuniforms[vbatch * 4 + 0+ 0.1f + 0]);
    vpos.y = dot(pos, vfuniforms[vbatch * 4 + 0+ 0.1f + 1]);
    

    tc.x = dot(pos, vfuniforms[vbatch * 4 + 2+ 0.1f + 0]);
    tc.y = dot(pos, vfuniforms[vbatch * 4 + 2+ 0.1f + 1]);
    
}
