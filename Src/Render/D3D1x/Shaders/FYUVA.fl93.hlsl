sampler2D tex[4] : register(s0);
void main( float2 tc : TEXCOORD0,
           out float4 fcolor : COLOR0)
{
    float c0 = float((tex2D(tex[0], tc).r - 16./255.) * 1.164);
    float U0 = float(tex2D(tex[1], tc).r - 128./255.);
    float V0 = float(tex2D(tex[2], tc).r - 128./255.);
    float4 c = float4(c0,c0,c0,c0);
    float4 U = float4(U0,U0,U0,U0);
    float4 V = float4(V0,V0,V0,V0);
    c += V * float4(1.596, -0.813, 0, 0);
    c += U * float4(0, -0.392, 2.017, 0);
    c.a = tex2D(tex[3], tc).r;
    fcolor = c;
    
}
