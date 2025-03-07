/**************************************************************************

    PublicHeader:   Render
    Filename    :   GL_ShaderSource.cpp
    Content     :   GL Shader descriptors
    Created     :   12/11/2012
    Authors     :   Automatically generated.

    Copyright   :   Copyright 2012 Autodesk, Inc. All Rights reserved.

    Use of this software is subject to the terms of the Autodesk license
    agreement provided at the time of installation or download, or which
    otherwise accompanies this software in either electronic or hard copy form.

**************************************************************************/


namespace Scaleform { namespace Render { namespace GL {


extern const char* pSource_GLSL110_VTexTG;
const char* pSource_GLSL110_VTexTG = 
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTG;
const char* pSource_GLSL110_FTexTG = 
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGMul;
const char* pSource_GLSL110_FTexTGMul = 
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGInv;
const char* pSource_GLSL110_FTexTGInv = 
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VTexTGEAlpha;
const char* pSource_GLSL110_VTexTGEAlpha = 
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGEAlpha;
const char* pSource_GLSL110_FTexTGEAlpha = 
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGEAlphaMul;
const char* pSource_GLSL110_FTexTGEAlphaMul = 
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGEAlphaInv;
const char* pSource_GLSL110_FTexTGEAlphaInv = 
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VTexTGCxform;
const char* pSource_GLSL110_VTexTGCxform = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 pos;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxform;
const char* pSource_GLSL110_FTexTGCxform = 
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformMul;
const char* pSource_GLSL110_FTexTGCxformMul = 
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformInv;
const char* pSource_GLSL110_FTexTGCxformInv = 
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VTexTGCxformEAlpha;
const char* pSource_GLSL110_VTexTGCxformEAlpha = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformEAlpha;
const char* pSource_GLSL110_FTexTGCxformEAlpha = 
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformEAlphaMul;
const char* pSource_GLSL110_FTexTGCxformEAlphaMul = 
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformEAlphaInv;
const char* pSource_GLSL110_FTexTGCxformEAlphaInv = 
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformAc;
const char* pSource_GLSL110_FTexTGCxformAc = 
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformAcMul;
const char* pSource_GLSL110_FTexTGCxformAcMul = 
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformAcInv;
const char* pSource_GLSL110_FTexTGCxformAcInv = 
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformAcEAlpha;
const char* pSource_GLSL110_FTexTGCxformAcEAlpha = 
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformAcEAlphaMul;
const char* pSource_GLSL110_FTexTGCxformAcEAlphaMul = 
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCxformAcEAlphaInv;
const char* pSource_GLSL110_FTexTGCxformAcEAlphaInv = 
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VVertex;
const char* pSource_GLSL110_VVertex = 
"uniform vec4 mvp[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL110_FVertex;
const char* pSource_GLSL110_FVertex = 
"varying vec4 color;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexMul;
const char* pSource_GLSL110_FVertexMul = 
"varying vec4 color;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexInv;
const char* pSource_GLSL110_FVertexInv = 
"varying vec4 color;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VVertexEAlpha;
const char* pSource_GLSL110_VVertexEAlpha = 
"uniform vec4 mvp[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexEAlpha;
const char* pSource_GLSL110_FVertexEAlpha = 
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexEAlphaMul;
const char* pSource_GLSL110_FVertexEAlphaMul = 
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexEAlphaInv;
const char* pSource_GLSL110_FVertexEAlphaInv = 
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VVertexCxform;
const char* pSource_GLSL110_VVertexCxform = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxform;
const char* pSource_GLSL110_FVertexCxform = 
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformMul;
const char* pSource_GLSL110_FVertexCxformMul = 
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformInv;
const char* pSource_GLSL110_FVertexCxformInv = 
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VVertexCxformEAlpha;
const char* pSource_GLSL110_VVertexCxformEAlpha = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformEAlpha;
const char* pSource_GLSL110_FVertexCxformEAlpha = 
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformEAlphaMul;
const char* pSource_GLSL110_FVertexCxformEAlphaMul = 
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformEAlphaInv;
const char* pSource_GLSL110_FVertexCxformEAlphaInv = 
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformAc;
const char* pSource_GLSL110_FVertexCxformAc = 
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformAcMul;
const char* pSource_GLSL110_FVertexCxformAcMul = 
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformAcInv;
const char* pSource_GLSL110_FVertexCxformAcInv = 
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformAcEAlpha;
const char* pSource_GLSL110_FVertexCxformAcEAlpha = 
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformAcEAlphaMul;
const char* pSource_GLSL110_FVertexCxformAcEAlphaMul = 
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FVertexCxformAcEAlphaInv;
const char* pSource_GLSL110_FVertexCxformAcEAlphaInv = 
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VTexTGTexTG;
const char* pSource_GLSL110_VTexTGTexTG = 
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[4];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTG;
const char* pSource_GLSL110_FTexTGTexTG = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGMul;
const char* pSource_GLSL110_FTexTGTexTGMul = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGInv;
const char* pSource_GLSL110_FTexTGTexTGInv = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGEAlpha;
const char* pSource_GLSL110_FTexTGTexTGEAlpha = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGEAlphaMul;
const char* pSource_GLSL110_FTexTGTexTGEAlphaMul = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGEAlphaInv;
const char* pSource_GLSL110_FTexTGTexTGEAlphaInv = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VTexTGTexTGCxform;
const char* pSource_GLSL110_VTexTGTexTGCxform = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[4];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxform;
const char* pSource_GLSL110_FTexTGTexTGCxform = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformMul;
const char* pSource_GLSL110_FTexTGTexTGCxformMul = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformInv;
const char* pSource_GLSL110_FTexTGTexTGCxformInv = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformEAlpha;
const char* pSource_GLSL110_FTexTGTexTGCxformEAlpha = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformEAlphaMul;
const char* pSource_GLSL110_FTexTGTexTGCxformEAlphaMul = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformEAlphaInv;
const char* pSource_GLSL110_FTexTGTexTGCxformEAlphaInv = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformAc;
const char* pSource_GLSL110_FTexTGTexTGCxformAc = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformAcMul;
const char* pSource_GLSL110_FTexTGTexTGCxformAcMul = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformAcInv;
const char* pSource_GLSL110_FTexTGTexTGCxformAcInv = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformAcEAlpha;
const char* pSource_GLSL110_FTexTGTexTGCxformAcEAlpha = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformAcEAlphaMul;
const char* pSource_GLSL110_FTexTGTexTGCxformAcEAlphaMul = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGTexTGCxformAcEAlphaInv;
const char* pSource_GLSL110_FTexTGTexTGCxformAcEAlphaInv = 
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VTexTGVertex;
const char* pSource_GLSL110_VTexTGVertex = 
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertex;
const char* pSource_GLSL110_FTexTGVertex = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexMul;
const char* pSource_GLSL110_FTexTGVertexMul = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexInv;
const char* pSource_GLSL110_FTexTGVertexInv = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexEAlpha;
const char* pSource_GLSL110_FTexTGVertexEAlpha = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexEAlphaMul;
const char* pSource_GLSL110_FTexTGVertexEAlphaMul = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexEAlphaInv;
const char* pSource_GLSL110_FTexTGVertexEAlphaInv = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VTexTGVertexCxform;
const char* pSource_GLSL110_VTexTGVertexCxform = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxform;
const char* pSource_GLSL110_FTexTGVertexCxform = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformMul;
const char* pSource_GLSL110_FTexTGVertexCxformMul = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformInv;
const char* pSource_GLSL110_FTexTGVertexCxformInv = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformEAlpha;
const char* pSource_GLSL110_FTexTGVertexCxformEAlpha = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformEAlphaMul;
const char* pSource_GLSL110_FTexTGVertexCxformEAlphaMul = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformEAlphaInv;
const char* pSource_GLSL110_FTexTGVertexCxformEAlphaInv = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformAc;
const char* pSource_GLSL110_FTexTGVertexCxformAc = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformAcMul;
const char* pSource_GLSL110_FTexTGVertexCxformAcMul = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformAcInv;
const char* pSource_GLSL110_FTexTGVertexCxformAcInv = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformAcEAlpha;
const char* pSource_GLSL110_FTexTGVertexCxformAcEAlpha = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformAcEAlphaMul;
const char* pSource_GLSL110_FTexTGVertexCxformAcEAlphaMul = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGVertexCxformAcEAlphaInv;
const char* pSource_GLSL110_FTexTGVertexCxformAcEAlphaInv = 
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dTexTG;
const char* pSource_GLSL110_VPosition3dTexTG = 
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dTexTGEAlpha;
const char* pSource_GLSL110_VPosition3dTexTGEAlpha = 
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dTexTGCxform;
const char* pSource_GLSL110_VPosition3dTexTGCxform = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 pos;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dTexTGCxformEAlpha;
const char* pSource_GLSL110_VPosition3dTexTGCxformEAlpha = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dVertex;
const char* pSource_GLSL110_VPosition3dVertex = 
"uniform mat4 mvp;\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dVertexEAlpha;
const char* pSource_GLSL110_VPosition3dVertexEAlpha = 
"uniform mat4 mvp;\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dVertexCxform;
const char* pSource_GLSL110_VPosition3dVertexCxform = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dVertexCxformEAlpha;
const char* pSource_GLSL110_VPosition3dVertexCxformEAlpha = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dTexTGTexTG;
const char* pSource_GLSL110_VPosition3dTexTGTexTG = 
"uniform mat4 mvp;\n"
"uniform vec4 texgen[4];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dTexTGTexTGCxform;
const char* pSource_GLSL110_VPosition3dTexTGTexTGCxform = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[4];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dTexTGVertex;
const char* pSource_GLSL110_VPosition3dTexTGVertex = 
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dTexTGVertexCxform;
const char* pSource_GLSL110_VPosition3dTexTGVertexCxform = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchTexTG;
const char* pSource_GLSL110_VBatchTexTG = 
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL110_VBatchTexTGEAlpha;
const char* pSource_GLSL110_VBatchTexTGEAlpha = 
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchTexTGCxform;
const char* pSource_GLSL110_VBatchTexTGCxform = 
"uniform vec4 vfuniforms[144];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(vbatch * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 6.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL110_VBatchTexTGCxformEAlpha;
const char* pSource_GLSL110_VBatchTexTGCxformEAlpha = 
"uniform vec4 vfuniforms[144];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchVertex;
const char* pSource_GLSL110_VBatchVertex = 
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchVertexEAlpha;
const char* pSource_GLSL110_VBatchVertexEAlpha = 
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchVertexCxform;
const char* pSource_GLSL110_VBatchVertexCxform = 
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL110_VBatchVertexCxformEAlpha;
const char* pSource_GLSL110_VBatchVertexCxformEAlpha = 
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchTexTGTexTG;
const char* pSource_GLSL110_VBatchTexTGTexTG = 
"uniform vec4 vfuniforms[144];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchTexTGTexTGCxform;
const char* pSource_GLSL110_VBatchTexTGTexTGCxform = 
"uniform vec4 vfuniforms[192];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 3.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 8.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 8.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchTexTGVertex;
const char* pSource_GLSL110_VBatchTexTGVertex = 
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchTexTGVertexCxform;
const char* pSource_GLSL110_VBatchTexTGVertexCxform = 
"uniform vec4 vfuniforms[144];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dTexTG;
const char* pSource_GLSL110_VBatchPosition3dTexTG = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dTexTGEAlpha;
const char* pSource_GLSL110_VBatchPosition3dTexTGEAlpha = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dTexTGCxform;
const char* pSource_GLSL110_VBatchPosition3dTexTGCxform = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dTexTGCxformEAlpha;
const char* pSource_GLSL110_VBatchPosition3dTexTGCxformEAlpha = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dVertex;
const char* pSource_GLSL110_VBatchPosition3dVertex = 
"uniform mat4 vfmuniforms[24];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dVertexEAlpha;
const char* pSource_GLSL110_VBatchPosition3dVertexEAlpha = 
"uniform mat4 vfmuniforms[24];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dVertexCxform;
const char* pSource_GLSL110_VBatchPosition3dVertexCxform = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 2.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dVertexCxformEAlpha;
const char* pSource_GLSL110_VBatchPosition3dVertexCxformEAlpha = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 2.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dTexTGTexTG;
const char* pSource_GLSL110_VBatchPosition3dTexTGTexTG = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dTexTGTexTGCxform;
const char* pSource_GLSL110_VBatchPosition3dTexTGTexTGCxform = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[144];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 3.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dTexTGVertex;
const char* pSource_GLSL110_VBatchPosition3dTexTGVertex = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dTexTGVertexCxform;
const char* pSource_GLSL110_VBatchPosition3dTexTGVertexCxform = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL110_VSolid;
const char* pSource_GLSL110_VSolid = 
"uniform vec4 mvp[2];\n"
"attribute vec4 pos;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"}\n";

extern const char* pSource_GLSL110_FSolid;
const char* pSource_GLSL110_FSolid = 
"uniform vec4 cxmul;\n"
"void main() {\n"
"gl_FragColor = cxmul;\n"
"}\n";

extern const char* pSource_GLSL110_FSolidMul;
const char* pSource_GLSL110_FSolidMul = 
"uniform vec4 cxmul;\n"
"void main() {\n"
"gl_FragColor = cxmul;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FSolidInv;
const char* pSource_GLSL110_FSolidInv = 
"uniform vec4 cxmul;\n"
"void main() {\n"
"gl_FragColor = cxmul;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VText;
const char* pSource_GLSL110_VText = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"attribute vec4 acolor;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"vcolor = acolor * cxmul + cxadd;\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL110_FText;
const char* pSource_GLSL110_FText = 
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture2D(tex, tc).a;\n"
"gl_FragColor = c;\n"
"}\n";

extern const char* pSource_GLSL110_FTextMul;
const char* pSource_GLSL110_FTextMul = 
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture2D(tex, tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTextInv;
const char* pSource_GLSL110_FTextInv = 
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture2D(tex, tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VTextColor;
const char* pSource_GLSL110_VTextColor = 
"uniform vec4 mvp[2];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL110_VTextColorCxform;
const char* pSource_GLSL110_VTextColorCxform = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc = atc;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dSolid;
const char* pSource_GLSL110_VPosition3dSolid = 
"uniform mat4 mvp;\n"
"attribute vec4 pos;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dText;
const char* pSource_GLSL110_VPosition3dText = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"attribute vec4 acolor;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"vcolor = acolor * cxmul + cxadd;\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dTextColor;
const char* pSource_GLSL110_VPosition3dTextColor = 
"uniform mat4 mvp;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL110_VPosition3dTextColorCxform;
const char* pSource_GLSL110_VPosition3dTextColorCxform = 
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc = atc;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchSolid;
const char* pSource_GLSL110_VBatchSolid = 
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL110_VBatchText;
const char* pSource_GLSL110_VBatchText = 
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 acolor;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"vcolor = acolor * vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)] + vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchTextColor;
const char* pSource_GLSL110_VBatchTextColor = 
"uniform vec4 vfuniforms[48];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchTextColorCxform;
const char* pSource_GLSL110_VBatchTextColorCxform = 
"uniform vec4 vfuniforms[96];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc = atc;\n"
"fucxadd = vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dSolid;
const char* pSource_GLSL110_VBatchPosition3dSolid = 
"uniform mat4 vfmuniforms[24];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dText;
const char* pSource_GLSL110_VBatchPosition3dText = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"vcolor = acolor * vfuniforms[int(vbatch * 2.0 + 1.0+ 0.1)] + vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1)];\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dTextColor;
const char* pSource_GLSL110_VBatchPosition3dTextColor = 
"uniform mat4 vfmuniforms[24];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL110_VBatchPosition3dTextColorCxform;
const char* pSource_GLSL110_VBatchPosition3dTextColorCxform = 
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc = atc;\n"
"fucxadd = vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 2.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL110_FYUV;
const char* pSource_GLSL110_FYUV = 
"uniform sampler2D tex[3];\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVMul;
const char* pSource_GLSL110_FYUVMul = 
"uniform sampler2D tex[3];\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVEAlpha;
const char* pSource_GLSL110_FYUVEAlpha = 
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVEAlphaMul;
const char* pSource_GLSL110_FYUVEAlphaMul = 
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVCxform;
const char* pSource_GLSL110_FYUVCxform = 
"uniform sampler2D tex[3];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVCxformMul;
const char* pSource_GLSL110_FYUVCxformMul = 
"uniform sampler2D tex[3];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVCxformEAlpha;
const char* pSource_GLSL110_FYUVCxformEAlpha = 
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVCxformEAlphaMul;
const char* pSource_GLSL110_FYUVCxformEAlphaMul = 
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVCxformAc;
const char* pSource_GLSL110_FYUVCxformAc = 
"uniform sampler2D tex[3];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVCxformAcMul;
const char* pSource_GLSL110_FYUVCxformAcMul = 
"uniform sampler2D tex[3];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVCxformAcEAlpha;
const char* pSource_GLSL110_FYUVCxformAcEAlpha = 
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVCxformAcEAlphaMul;
const char* pSource_GLSL110_FYUVCxformAcEAlphaMul = 
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVA;
const char* pSource_GLSL110_FYUVA = 
"uniform sampler2D tex[4];\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVAMul;
const char* pSource_GLSL110_FYUVAMul = 
"uniform sampler2D tex[4];\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVAInv;
const char* pSource_GLSL110_FYUVAInv = 
"uniform sampler2D tex[4];\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FYUVAEAlpha;
const char* pSource_GLSL110_FYUVAEAlpha = 
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVAEAlphaMul;
const char* pSource_GLSL110_FYUVAEAlphaMul = 
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVAEAlphaInv;
const char* pSource_GLSL110_FYUVAEAlphaInv = 
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxform;
const char* pSource_GLSL110_FYUVACxform = 
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformMul;
const char* pSource_GLSL110_FYUVACxformMul = 
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformInv;
const char* pSource_GLSL110_FYUVACxformInv = 
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformEAlpha;
const char* pSource_GLSL110_FYUVACxformEAlpha = 
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformEAlphaMul;
const char* pSource_GLSL110_FYUVACxformEAlphaMul = 
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformEAlphaInv;
const char* pSource_GLSL110_FYUVACxformEAlphaInv = 
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformAc;
const char* pSource_GLSL110_FYUVACxformAc = 
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformAcMul;
const char* pSource_GLSL110_FYUVACxformAcMul = 
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformAcInv;
const char* pSource_GLSL110_FYUVACxformAcInv = 
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformAcEAlpha;
const char* pSource_GLSL110_FYUVACxformAcEAlpha = 
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformAcEAlphaMul;
const char* pSource_GLSL110_FYUVACxformAcEAlphaMul = 
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FYUVACxformAcEAlphaInv;
const char* pSource_GLSL110_FYUVACxformAcEAlphaInv = 
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCMatrixAc;
const char* pSource_GLSL110_FTexTGCMatrixAc = 
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor) * (cxmul) + cxadd * (gl_FragColor.a + cxadd.a);\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCMatrixAcMul;
const char* pSource_GLSL110_FTexTGCMatrixAcMul = 
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor) * (cxmul) + cxadd * (gl_FragColor.a + cxadd.a);\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCMatrixAcEAlpha;
const char* pSource_GLSL110_FTexTGCMatrixAcEAlpha = 
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor) * (cxmul) + cxadd * (gl_FragColor.a + cxadd.a);\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FTexTGCMatrixAcEAlphaMul;
const char* pSource_GLSL110_FTexTGCMatrixAcEAlphaMul = 
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor) * (cxmul) + cxadd * (gl_FragColor.a + cxadd.a);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox1Blur;
const char* pSource_GLSL110_FBox1Blur = 
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"float  i = 0.0;\n"
"for (i = -fsize.x; i <= fsize.x; i++)\n"
"{{\n"
"color += texture2DLod(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox1BlurMul;
const char* pSource_GLSL110_FBox1BlurMul = 
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"float  i = 0.0;\n"
"for (i = -fsize.x; i <= fsize.x; i++)\n"
"{{\n"
"color += texture2DLod(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2Blur;
const char* pSource_GLSL110_FBox2Blur = 
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2BlurMul;
const char* pSource_GLSL110_FBox2BlurMul = 
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2Shadow;
const char* pSource_GLSL110_FBox2Shadow = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2ShadowMul;
const char* pSource_GLSL110_FBox2ShadowMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2ShadowKnockout;
const char* pSource_GLSL110_FBox2ShadowKnockout = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2ShadowKnockoutMul;
const char* pSource_GLSL110_FBox2ShadowKnockoutMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2InnerShadow;
const char* pSource_GLSL110_FBox2InnerShadow = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - gl_FragColor.a) * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2InnerShadowMul;
const char* pSource_GLSL110_FBox2InnerShadowMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - gl_FragColor.a) * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2InnerShadowKnockout;
const char* pSource_GLSL110_FBox2InnerShadowKnockout = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - gl_FragColor.a) * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2InnerShadowKnockoutMul;
const char* pSource_GLSL110_FBox2InnerShadowKnockoutMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - gl_FragColor.a) * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2Shadowonly;
const char* pSource_GLSL110_FBox2Shadowonly = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2ShadowonlyMul;
const char* pSource_GLSL110_FBox2ShadowonlyMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2ShadowHighlight;
const char* pSource_GLSL110_FBox2ShadowHighlight = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"gl_FragColor = ((scolor * gl_FragColor.a + scolor2 * gl_FragColor.r)*(1.0-base.a) + base);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2ShadowHighlightMul;
const char* pSource_GLSL110_FBox2ShadowHighlightMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"gl_FragColor = ((scolor * gl_FragColor.a + scolor2 * gl_FragColor.r)*(1.0-base.a) + base);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2ShadowHighlightKnockout;
const char* pSource_GLSL110_FBox2ShadowHighlightKnockout = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"gl_FragColor = ((scolor * gl_FragColor.a + scolor2 * gl_FragColor.r)*(1.0-base.a) + base);\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2ShadowHighlightKnockoutMul;
const char* pSource_GLSL110_FBox2ShadowHighlightKnockoutMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"gl_FragColor = ((scolor * gl_FragColor.a + scolor2 * gl_FragColor.r)*(1.0-base.a) + base);\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2InnerShadowHighlight;
const char* pSource_GLSL110_FBox2InnerShadowHighlight = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r) * base.a;\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r)) * base.a;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2InnerShadowHighlightMul;
const char* pSource_GLSL110_FBox2InnerShadowHighlightMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r) * base.a;\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r)) * base.a;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2InnerShadowHighlightKnockout;
const char* pSource_GLSL110_FBox2InnerShadowHighlightKnockout = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r) * base.a;\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r)) * base.a;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2InnerShadowHighlightKnockoutMul;
const char* pSource_GLSL110_FBox2InnerShadowHighlightKnockoutMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r) * base.a;\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r)) * base.a;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2FullShadowHighlight;
const char* pSource_GLSL110_FBox2FullShadowHighlight = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r);\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r));\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2FullShadowHighlightMul;
const char* pSource_GLSL110_FBox2FullShadowHighlightMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2DLod(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r);\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r));\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2ShadowonlyHighlight;
const char* pSource_GLSL110_FBox2ShadowonlyHighlight = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_FBox2ShadowonlyHighlightMul;
const char* pSource_GLSL110_FBox2ShadowonlyHighlightMul = 
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2DLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2DLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL110_VDrawableCopyPixels;
const char* pSource_GLSL110_VDrawableCopyPixels = 
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[4];\n"
"attribute vec4 pos;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"}\n";

extern const char* pSource_GLSL110_FDrawableCopyPixels;
const char* pSource_GLSL110_FDrawableCopyPixels = 
"uniform sampler2D tex[2];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"float inAlpha = fcolor_src.a;\n"
"gl_FragColor.a = inAlpha;\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FDrawableCopyPixelsMergeAlpha;
const char* pSource_GLSL110_FDrawableCopyPixelsMergeAlpha = 
"uniform sampler2D tex[2];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"float inAlpha = fcolor_src.a;\n"
"gl_FragColor.a = mix(inAlpha, 1.0, fcolor_org.a);\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FDrawableCopyPixelsNoDestAlpha;
const char* pSource_GLSL110_FDrawableCopyPixelsNoDestAlpha = 
"uniform sampler2D tex[2];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"float inAlpha = fcolor_src.a;\n"
"gl_FragColor.a = 1.0;\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_VDrawableCopyPixelsAlpha;
const char* pSource_GLSL110_VDrawableCopyPixelsAlpha = 
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[6];\n"
"attribute vec4 pos;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"varying vec2 tc2;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"tc2.x = dot(pos, texgen[int(4.0)]);\n"
"tc2.y = dot(pos, texgen[int(5.0)]);\n"
"}\n";

extern const char* pSource_GLSL110_FDrawableCopyPixelsAlpha;
const char* pSource_GLSL110_FDrawableCopyPixelsAlpha = 
"uniform sampler2D tex[3];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"varying vec2 tc2;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"vec4 fcolor_alp = texture2D(tex[int(2.0)], tc2);\n"
"float inAlpha = fcolor_src.a * fcolor_alp.a;\n"
"gl_FragColor.a = inAlpha;\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FDrawableCopyPixelsAlphaMergeAlpha;
const char* pSource_GLSL110_FDrawableCopyPixelsAlphaMergeAlpha = 
"uniform sampler2D tex[3];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"varying vec2 tc2;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"vec4 fcolor_alp = texture2D(tex[int(2.0)], tc2);\n"
"float inAlpha = fcolor_src.a * fcolor_alp.a;\n"
"gl_FragColor.a = mix(inAlpha, 1.0, fcolor_org.a);\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FDrawableCopyPixelsAlphaNoDestAlpha;
const char* pSource_GLSL110_FDrawableCopyPixelsAlphaNoDestAlpha = 
"uniform sampler2D tex[3];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"varying vec2 tc2;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"vec4 fcolor_alp = texture2D(tex[int(2.0)], tc2);\n"
"float inAlpha = fcolor_src.a * fcolor_alp.a;\n"
"gl_FragColor.a = 1.0;\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL110_FDrawableMerge;
const char* pSource_GLSL110_FDrawableMerge = 
"uniform mat4 cxmul;\n"
"uniform mat4 cxmul1;\n"
"uniform sampler2D tex[2];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor_original = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_source   = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = (fcolor_original) * ( cxmul) + (fcolor_source) * ( cxmul1);\n"
"}\n";

extern const char* pSource_GLSL110_FDrawableCompare;
const char* pSource_GLSL110_FDrawableCompare = 
"uniform sampler2D tex[2];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"vec4 diff = fcolor0 - fcolor1;\n"
"vec4 oneValue = vec4(1.0/255.0, 1.0/255.0, 1.0/255.0, 1.0/255.0 );\n"
"vec4 ltZero = (sign(diff)+vec4(1.0,1,1.0,1))*-0.25;\n"
"vec4 partDiff = oneValue * (sign(ltZero)+vec4(1.0,1,1.0,1));\n"
"vec4 wrapDiff = fract(diff + vec4(1.0,1,1.0,1)) + partDiff;\n"
"float rgbdiff = sign(dot(wrapDiff.rgb, vec3(1.0,1,1.0)));\n"
"gl_FragColor = mix( vec4(1.0,1,1.0, wrapDiff.a), vec4(wrapDiff.rgb, 1.0), rgbdiff );\n"
"}\n";

extern const char* pSource_GLSL110_FDrawablePaletteMap;
const char* pSource_GLSL110_FDrawablePaletteMap = 
"uniform sampler2D srctex;\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fchannels = texture2D(tex, tc);\n"
"gl_FragColor  = texture2D(srctex, vec2(fchannels.r, 0.125));\n"
"gl_FragColor += texture2D(srctex, vec2(fchannels.g, 0.375));\n"
"gl_FragColor += texture2D(srctex, vec2(fchannels.b, 0.625));\n"
"gl_FragColor += texture2D(srctex, vec2(fchannels.a, 0.875));\n"
"}\n";

extern const char* pSource_GLSL120_VTexTG;
const char* pSource_GLSL120_VTexTG = 
"#version 120\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTG;
const char* pSource_GLSL120_FTexTG = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGMul;
const char* pSource_GLSL120_FTexTGMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGInv;
const char* pSource_GLSL120_FTexTGInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VTexTGEAlpha;
const char* pSource_GLSL120_VTexTGEAlpha = 
"#version 120\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGEAlpha;
const char* pSource_GLSL120_FTexTGEAlpha = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGEAlphaMul;
const char* pSource_GLSL120_FTexTGEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGEAlphaInv;
const char* pSource_GLSL120_FTexTGEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VTexTGCxform;
const char* pSource_GLSL120_VTexTGCxform = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 pos;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxform;
const char* pSource_GLSL120_FTexTGCxform = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformMul;
const char* pSource_GLSL120_FTexTGCxformMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformInv;
const char* pSource_GLSL120_FTexTGCxformInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VTexTGCxformEAlpha;
const char* pSource_GLSL120_VTexTGCxformEAlpha = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformEAlpha;
const char* pSource_GLSL120_FTexTGCxformEAlpha = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformEAlphaMul;
const char* pSource_GLSL120_FTexTGCxformEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformEAlphaInv;
const char* pSource_GLSL120_FTexTGCxformEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformAc;
const char* pSource_GLSL120_FTexTGCxformAc = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformAcMul;
const char* pSource_GLSL120_FTexTGCxformAcMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformAcInv;
const char* pSource_GLSL120_FTexTGCxformAcInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformAcEAlpha;
const char* pSource_GLSL120_FTexTGCxformAcEAlpha = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformAcEAlphaMul;
const char* pSource_GLSL120_FTexTGCxformAcEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCxformAcEAlphaInv;
const char* pSource_GLSL120_FTexTGCxformAcEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VVertex;
const char* pSource_GLSL120_VVertex = 
"#version 120\n"
"uniform vec4 mvp[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL120_FVertex;
const char* pSource_GLSL120_FVertex = 
"#version 120\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexMul;
const char* pSource_GLSL120_FVertexMul = 
"#version 120\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexInv;
const char* pSource_GLSL120_FVertexInv = 
"#version 120\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VVertexEAlpha;
const char* pSource_GLSL120_VVertexEAlpha = 
"#version 120\n"
"uniform vec4 mvp[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexEAlpha;
const char* pSource_GLSL120_FVertexEAlpha = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexEAlphaMul;
const char* pSource_GLSL120_FVertexEAlphaMul = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexEAlphaInv;
const char* pSource_GLSL120_FVertexEAlphaInv = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VVertexCxform;
const char* pSource_GLSL120_VVertexCxform = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxform;
const char* pSource_GLSL120_FVertexCxform = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformMul;
const char* pSource_GLSL120_FVertexCxformMul = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformInv;
const char* pSource_GLSL120_FVertexCxformInv = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VVertexCxformEAlpha;
const char* pSource_GLSL120_VVertexCxformEAlpha = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformEAlpha;
const char* pSource_GLSL120_FVertexCxformEAlpha = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformEAlphaMul;
const char* pSource_GLSL120_FVertexCxformEAlphaMul = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformEAlphaInv;
const char* pSource_GLSL120_FVertexCxformEAlphaInv = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformAc;
const char* pSource_GLSL120_FVertexCxformAc = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformAcMul;
const char* pSource_GLSL120_FVertexCxformAcMul = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformAcInv;
const char* pSource_GLSL120_FVertexCxformAcInv = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformAcEAlpha;
const char* pSource_GLSL120_FVertexCxformAcEAlpha = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformAcEAlphaMul;
const char* pSource_GLSL120_FVertexCxformAcEAlphaMul = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FVertexCxformAcEAlphaInv;
const char* pSource_GLSL120_FVertexCxformAcEAlphaInv = 
"#version 120\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_FragColor = color;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VTexTGTexTG;
const char* pSource_GLSL120_VTexTGTexTG = 
"#version 120\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[4];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTG;
const char* pSource_GLSL120_FTexTGTexTG = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGMul;
const char* pSource_GLSL120_FTexTGTexTGMul = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGInv;
const char* pSource_GLSL120_FTexTGTexTGInv = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGEAlpha;
const char* pSource_GLSL120_FTexTGTexTGEAlpha = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGEAlphaMul;
const char* pSource_GLSL120_FTexTGTexTGEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGEAlphaInv;
const char* pSource_GLSL120_FTexTGTexTGEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VTexTGTexTGCxform;
const char* pSource_GLSL120_VTexTGTexTGCxform = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[4];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxform;
const char* pSource_GLSL120_FTexTGTexTGCxform = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformMul;
const char* pSource_GLSL120_FTexTGTexTGCxformMul = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformInv;
const char* pSource_GLSL120_FTexTGTexTGCxformInv = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformEAlpha;
const char* pSource_GLSL120_FTexTGTexTGCxformEAlpha = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformEAlphaMul;
const char* pSource_GLSL120_FTexTGTexTGCxformEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformEAlphaInv;
const char* pSource_GLSL120_FTexTGTexTGCxformEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformAc;
const char* pSource_GLSL120_FTexTGTexTGCxformAc = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformAcMul;
const char* pSource_GLSL120_FTexTGTexTGCxformAcMul = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformAcInv;
const char* pSource_GLSL120_FTexTGTexTGCxformAcInv = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformAcEAlpha;
const char* pSource_GLSL120_FTexTGTexTGCxformAcEAlpha = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformAcEAlphaMul;
const char* pSource_GLSL120_FTexTGTexTGCxformAcEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGTexTGCxformAcEAlphaInv;
const char* pSource_GLSL120_FTexTGTexTGCxformAcEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VTexTGVertex;
const char* pSource_GLSL120_VTexTGVertex = 
"#version 120\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertex;
const char* pSource_GLSL120_FTexTGVertex = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexMul;
const char* pSource_GLSL120_FTexTGVertexMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexInv;
const char* pSource_GLSL120_FTexTGVertexInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexEAlpha;
const char* pSource_GLSL120_FTexTGVertexEAlpha = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexEAlphaMul;
const char* pSource_GLSL120_FTexTGVertexEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexEAlphaInv;
const char* pSource_GLSL120_FTexTGVertexEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VTexTGVertexCxform;
const char* pSource_GLSL120_VTexTGVertexCxform = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxform;
const char* pSource_GLSL120_FTexTGVertexCxform = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformMul;
const char* pSource_GLSL120_FTexTGVertexCxformMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformInv;
const char* pSource_GLSL120_FTexTGVertexCxformInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformEAlpha;
const char* pSource_GLSL120_FTexTGVertexCxformEAlpha = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformEAlphaMul;
const char* pSource_GLSL120_FTexTGVertexCxformEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformEAlphaInv;
const char* pSource_GLSL120_FTexTGVertexCxformEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformAc;
const char* pSource_GLSL120_FTexTGVertexCxformAc = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformAcMul;
const char* pSource_GLSL120_FTexTGVertexCxformAcMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformAcInv;
const char* pSource_GLSL120_FTexTGVertexCxformAcInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformAcEAlpha;
const char* pSource_GLSL120_FTexTGVertexCxformAcEAlpha = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformAcEAlphaMul;
const char* pSource_GLSL120_FTexTGVertexCxformAcEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGVertexCxformAcEAlphaInv;
const char* pSource_GLSL120_FTexTGVertexCxformAcEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"gl_FragColor = mix(fcolor1, fcolor0, factor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dTexTG;
const char* pSource_GLSL120_VPosition3dTexTG = 
"#version 120\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dTexTGEAlpha;
const char* pSource_GLSL120_VPosition3dTexTGEAlpha = 
"#version 120\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dTexTGCxform;
const char* pSource_GLSL120_VPosition3dTexTGCxform = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 pos;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dTexTGCxformEAlpha;
const char* pSource_GLSL120_VPosition3dTexTGCxformEAlpha = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dVertex;
const char* pSource_GLSL120_VPosition3dVertex = 
"#version 120\n"
"uniform mat4 mvp;\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dVertexEAlpha;
const char* pSource_GLSL120_VPosition3dVertexEAlpha = 
"#version 120\n"
"uniform mat4 mvp;\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dVertexCxform;
const char* pSource_GLSL120_VPosition3dVertexCxform = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dVertexCxformEAlpha;
const char* pSource_GLSL120_VPosition3dVertexCxformEAlpha = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dTexTGTexTG;
const char* pSource_GLSL120_VPosition3dTexTGTexTG = 
"#version 120\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[4];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dTexTGTexTGCxform;
const char* pSource_GLSL120_VPosition3dTexTGTexTGCxform = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[4];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dTexTGVertex;
const char* pSource_GLSL120_VPosition3dTexTGVertex = 
"#version 120\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dTexTGVertexCxform;
const char* pSource_GLSL120_VPosition3dTexTGVertexCxform = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchTexTG;
const char* pSource_GLSL120_VBatchTexTG = 
"#version 120\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL120_VBatchTexTGEAlpha;
const char* pSource_GLSL120_VBatchTexTGEAlpha = 
"#version 120\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchTexTGCxform;
const char* pSource_GLSL120_VBatchTexTGCxform = 
"#version 120\n"
"uniform vec4 vfuniforms[144];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(vbatch * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 6.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL120_VBatchTexTGCxformEAlpha;
const char* pSource_GLSL120_VBatchTexTGCxformEAlpha = 
"#version 120\n"
"uniform vec4 vfuniforms[144];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchVertex;
const char* pSource_GLSL120_VBatchVertex = 
"#version 120\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchVertexEAlpha;
const char* pSource_GLSL120_VBatchVertexEAlpha = 
"#version 120\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchVertexCxform;
const char* pSource_GLSL120_VBatchVertexCxform = 
"#version 120\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL120_VBatchVertexCxformEAlpha;
const char* pSource_GLSL120_VBatchVertexCxformEAlpha = 
"#version 120\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchTexTGTexTG;
const char* pSource_GLSL120_VBatchTexTGTexTG = 
"#version 120\n"
"uniform vec4 vfuniforms[144];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchTexTGTexTGCxform;
const char* pSource_GLSL120_VBatchTexTGTexTGCxform = 
"#version 120\n"
"uniform vec4 vfuniforms[192];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 3.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 8.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 8.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchTexTGVertex;
const char* pSource_GLSL120_VBatchTexTGVertex = 
"#version 120\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchTexTGVertexCxform;
const char* pSource_GLSL120_VBatchTexTGVertexCxform = 
"#version 120\n"
"uniform vec4 vfuniforms[144];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dTexTG;
const char* pSource_GLSL120_VBatchPosition3dTexTG = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dTexTGEAlpha;
const char* pSource_GLSL120_VBatchPosition3dTexTGEAlpha = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dTexTGCxform;
const char* pSource_GLSL120_VBatchPosition3dTexTGCxform = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dTexTGCxformEAlpha;
const char* pSource_GLSL120_VBatchPosition3dTexTGCxformEAlpha = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dVertex;
const char* pSource_GLSL120_VBatchPosition3dVertex = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 color;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dVertexEAlpha;
const char* pSource_GLSL120_VBatchPosition3dVertexEAlpha = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dVertexCxform;
const char* pSource_GLSL120_VBatchPosition3dVertexCxform = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 color;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 2.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dVertexCxformEAlpha;
const char* pSource_GLSL120_VBatchPosition3dVertexCxformEAlpha = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 2.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dTexTGTexTG;
const char* pSource_GLSL120_VBatchPosition3dTexTGTexTG = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dTexTGTexTGCxform;
const char* pSource_GLSL120_VBatchPosition3dTexTGTexTGCxform = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[144];\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 3.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dTexTGVertex;
const char* pSource_GLSL120_VBatchPosition3dTexTGVertex = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dTexTGVertexCxform;
const char* pSource_GLSL120_VBatchPosition3dTexTGVertexCxform = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 acolor;\n"
"attribute vec4 afactor;\n"
"attribute vec4 pos;\n"
"varying vec4 color;\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL120_VSolid;
const char* pSource_GLSL120_VSolid = 
"#version 120\n"
"uniform vec4 mvp[2];\n"
"attribute vec4 pos;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"}\n";

extern const char* pSource_GLSL120_FSolid;
const char* pSource_GLSL120_FSolid = 
"#version 120\n"
"uniform vec4 cxmul;\n"
"void main() {\n"
"gl_FragColor = cxmul;\n"
"}\n";

extern const char* pSource_GLSL120_FSolidMul;
const char* pSource_GLSL120_FSolidMul = 
"#version 120\n"
"uniform vec4 cxmul;\n"
"void main() {\n"
"gl_FragColor = cxmul;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FSolidInv;
const char* pSource_GLSL120_FSolidInv = 
"#version 120\n"
"uniform vec4 cxmul;\n"
"void main() {\n"
"gl_FragColor = cxmul;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VText;
const char* pSource_GLSL120_VText = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"attribute vec4 acolor;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"vcolor = acolor * cxmul + cxadd;\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL120_FText;
const char* pSource_GLSL120_FText = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture2D(tex, tc).a;\n"
"gl_FragColor = c;\n"
"}\n";

extern const char* pSource_GLSL120_FTextMul;
const char* pSource_GLSL120_FTextMul = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture2D(tex, tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTextInv;
const char* pSource_GLSL120_FTextInv = 
"#version 120\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture2D(tex, tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VTextColor;
const char* pSource_GLSL120_VTextColor = 
"#version 120\n"
"uniform vec4 mvp[2];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL120_VTextColorCxform;
const char* pSource_GLSL120_VTextColorCxform = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc = atc;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dSolid;
const char* pSource_GLSL120_VPosition3dSolid = 
"#version 120\n"
"uniform mat4 mvp;\n"
"attribute vec4 pos;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dText;
const char* pSource_GLSL120_VPosition3dText = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"attribute vec4 acolor;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"vcolor = acolor * cxmul + cxadd;\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dTextColor;
const char* pSource_GLSL120_VPosition3dTextColor = 
"#version 120\n"
"uniform mat4 mvp;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL120_VPosition3dTextColorCxform;
const char* pSource_GLSL120_VPosition3dTextColorCxform = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc = atc;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchSolid;
const char* pSource_GLSL120_VBatchSolid = 
"#version 120\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL120_VBatchText;
const char* pSource_GLSL120_VBatchText = 
"#version 120\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec4 acolor;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"vcolor = acolor * vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)] + vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchTextColor;
const char* pSource_GLSL120_VBatchTextColor = 
"#version 120\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchTextColorCxform;
const char* pSource_GLSL120_VBatchTextColorCxform = 
"#version 120\n"
"uniform vec4 vfuniforms[96];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc = atc;\n"
"fucxadd = vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dSolid;
const char* pSource_GLSL120_VBatchPosition3dSolid = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dText;
const char* pSource_GLSL120_VBatchPosition3dText = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec4 acolor;\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"varying vec4 vcolor;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"vcolor = acolor * vfuniforms[int(vbatch * 2.0 + 1.0+ 0.1)] + vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1)];\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dTextColor;
const char* pSource_GLSL120_VBatchPosition3dTextColor = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL120_VBatchPosition3dTextColorCxform;
const char* pSource_GLSL120_VBatchPosition3dTextColorCxform = 
"#version 120\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"attribute vec2 atc;\n"
"attribute vec4 pos;\n"
"attribute float vbatch;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc = atc;\n"
"fucxadd = vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 2.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL120_FYUV;
const char* pSource_GLSL120_FYUV = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVMul;
const char* pSource_GLSL120_FYUVMul = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVEAlpha;
const char* pSource_GLSL120_FYUVEAlpha = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVEAlphaMul;
const char* pSource_GLSL120_FYUVEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVCxform;
const char* pSource_GLSL120_FYUVCxform = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVCxformMul;
const char* pSource_GLSL120_FYUVCxformMul = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVCxformEAlpha;
const char* pSource_GLSL120_FYUVCxformEAlpha = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVCxformEAlphaMul;
const char* pSource_GLSL120_FYUVCxformEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVCxformAc;
const char* pSource_GLSL120_FYUVCxformAc = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVCxformAcMul;
const char* pSource_GLSL120_FYUVCxformAcMul = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVCxformAcEAlpha;
const char* pSource_GLSL120_FYUVCxformAcEAlpha = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVCxformAcEAlphaMul;
const char* pSource_GLSL120_FYUVCxformAcEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVA;
const char* pSource_GLSL120_FYUVA = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVAMul;
const char* pSource_GLSL120_FYUVAMul = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVAInv;
const char* pSource_GLSL120_FYUVAInv = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FYUVAEAlpha;
const char* pSource_GLSL120_FYUVAEAlpha = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVAEAlphaMul;
const char* pSource_GLSL120_FYUVAEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVAEAlphaInv;
const char* pSource_GLSL120_FYUVAEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxform;
const char* pSource_GLSL120_FYUVACxform = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformMul;
const char* pSource_GLSL120_FYUVACxformMul = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformInv;
const char* pSource_GLSL120_FYUVACxformInv = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformEAlpha;
const char* pSource_GLSL120_FYUVACxformEAlpha = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformEAlphaMul;
const char* pSource_GLSL120_FYUVACxformEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformEAlphaInv;
const char* pSource_GLSL120_FYUVACxformEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = gl_FragColor * fucxmul + fucxadd;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformAc;
const char* pSource_GLSL120_FYUVACxformAc = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformAcMul;
const char* pSource_GLSL120_FYUVACxformAcMul = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformAcInv;
const char* pSource_GLSL120_FYUVACxformAcInv = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformAcEAlpha;
const char* pSource_GLSL120_FYUVACxformAcEAlpha = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformAcEAlphaMul;
const char* pSource_GLSL120_FYUVACxformAcEAlphaMul = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FYUVACxformAcEAlphaInv;
const char* pSource_GLSL120_FYUVACxformAcEAlphaInv = 
"#version 120\n"
"uniform sampler2D tex[4];\n"
"varying vec4 factor;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"float c0 = float((texture2D(tex[int(0.0)], tc).a - 16./255.) * 1.164);\n"
"float U0 = float(texture2D(tex[int(1.0)], tc).a - 128./255.);\n"
"float V0 = float(texture2D(tex[int(2.0)], tc).a - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture2D(tex[int(3.0)], tc).a;\n"
"gl_FragColor = c;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = vec3(gl_FragColor.a, gl_FragColor.a, gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCMatrixAc;
const char* pSource_GLSL120_FTexTGCMatrixAc = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor) * (cxmul) + cxadd * (gl_FragColor.a + cxadd.a);\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCMatrixAcMul;
const char* pSource_GLSL120_FTexTGCMatrixAcMul = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor) * (cxmul) + cxadd * (gl_FragColor.a + cxadd.a);\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCMatrixAcEAlpha;
const char* pSource_GLSL120_FTexTGCMatrixAcEAlpha = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor) * (cxmul) + cxadd * (gl_FragColor.a + cxadd.a);\n"
"gl_FragColor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FTexTGCMatrixAcEAlphaMul;
const char* pSource_GLSL120_FTexTGCMatrixAcEAlphaMul = 
"#version 120\n"
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"varying vec4 factor;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor = texture2D(tex,tc);\n"
"gl_FragColor = (gl_FragColor) * (cxmul) + cxadd * (gl_FragColor.a + cxadd.a);\n"
"gl_FragColor.a *= factor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox1Blur;
const char* pSource_GLSL120_FBox1Blur = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"float  i = 0.0;\n"
"for (i = -fsize.x; i <= fsize.x; i++)\n"
"{{\n"
"color += texture2D(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox1BlurMul;
const char* pSource_GLSL120_FBox1BlurMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"float  i = 0.0;\n"
"for (i = -fsize.x; i <= fsize.x; i++)\n"
"{{\n"
"color += texture2D(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2Blur;
const char* pSource_GLSL120_FBox2Blur = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2BlurMul;
const char* pSource_GLSL120_FBox2BlurMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2Shadow;
const char* pSource_GLSL120_FBox2Shadow = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2ShadowMul;
const char* pSource_GLSL120_FBox2ShadowMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2ShadowKnockout;
const char* pSource_GLSL120_FBox2ShadowKnockout = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2ShadowKnockoutMul;
const char* pSource_GLSL120_FBox2ShadowKnockoutMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2InnerShadow;
const char* pSource_GLSL120_FBox2InnerShadow = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - gl_FragColor.a) * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2InnerShadowMul;
const char* pSource_GLSL120_FBox2InnerShadowMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - gl_FragColor.a) * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2InnerShadowKnockout;
const char* pSource_GLSL120_FBox2InnerShadowKnockout = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - gl_FragColor.a) * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2InnerShadowKnockoutMul;
const char* pSource_GLSL120_FBox2InnerShadowKnockoutMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - gl_FragColor.a) * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2Shadowonly;
const char* pSource_GLSL120_FBox2Shadowonly = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2ShadowonlyMul;
const char* pSource_GLSL120_FBox2ShadowonlyMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor = scolor * clamp(gl_FragColor.a * fsize.z, 0.0, 1.0);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2ShadowHighlight;
const char* pSource_GLSL120_FBox2ShadowHighlight = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"gl_FragColor = ((scolor * gl_FragColor.a + scolor2 * gl_FragColor.r)*(1.0-base.a) + base);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2ShadowHighlightMul;
const char* pSource_GLSL120_FBox2ShadowHighlightMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"gl_FragColor = ((scolor * gl_FragColor.a + scolor2 * gl_FragColor.r)*(1.0-base.a) + base);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2ShadowHighlightKnockout;
const char* pSource_GLSL120_FBox2ShadowHighlightKnockout = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"gl_FragColor = ((scolor * gl_FragColor.a + scolor2 * gl_FragColor.r)*(1.0-base.a) + base);\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2ShadowHighlightKnockoutMul;
const char* pSource_GLSL120_FBox2ShadowHighlightKnockoutMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"gl_FragColor = ((scolor * gl_FragColor.a + scolor2 * gl_FragColor.r)*(1.0-base.a) + base);\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2InnerShadowHighlight;
const char* pSource_GLSL120_FBox2InnerShadowHighlight = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r) * base.a;\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r)) * base.a;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2InnerShadowHighlightMul;
const char* pSource_GLSL120_FBox2InnerShadowHighlightMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r) * base.a;\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r)) * base.a;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2InnerShadowHighlightKnockout;
const char* pSource_GLSL120_FBox2InnerShadowHighlightKnockout = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r) * base.a;\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r)) * base.a;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2InnerShadowHighlightKnockoutMul;
const char* pSource_GLSL120_FBox2InnerShadowHighlightKnockoutMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r) * base.a;\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r)) * base.a;\n"
"gl_FragColor -= knockout;\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2FullShadowHighlight;
const char* pSource_GLSL120_FBox2FullShadowHighlight = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r);\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r));\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2FullShadowHighlightMul;
const char* pSource_GLSL120_FBox2FullShadowHighlightMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"vec4 base = texture2D(srctex, tc * srctexscale.xy, 0.0);\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - gl_FragColor.a - gl_FragColor.r);\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r + base* (1.0 - gl_FragColor.a - gl_FragColor.r));\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2ShadowonlyHighlight;
const char* pSource_GLSL120_FBox2ShadowonlyHighlight = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_FBox2ShadowonlyHighlightMul;
const char* pSource_GLSL120_FBox2ShadowonlyHighlightMul = 
"#version 120\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"varying vec4 fucxadd;\n"
"varying vec4 fucxmul;\n"
"varying vec2 tc;\n"
"void main() {\n"
"gl_FragColor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += texture2D(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += texture2D(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"gl_FragColor = color * fsize.w;\n"
"gl_FragColor.ar = clamp((1.0 - gl_FragColor.ar * fsize.z) - (1.0 - gl_FragColor.ra * fsize.z), 0.0, 1.0);\n"
"gl_FragColor = (scolor * gl_FragColor.a + scolor2 * gl_FragColor.r);\n"
"gl_FragColor = (gl_FragColor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"gl_FragColor += fucxadd * gl_FragColor.a;\n"
"gl_FragColor.rgb = gl_FragColor.rgb * gl_FragColor.a;\n"
"}\n";

extern const char* pSource_GLSL120_VDrawableCopyPixels;
const char* pSource_GLSL120_VDrawableCopyPixels = 
"#version 120\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[4];\n"
"attribute vec4 pos;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"}\n";

extern const char* pSource_GLSL120_FDrawableCopyPixels;
const char* pSource_GLSL120_FDrawableCopyPixels = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"float inAlpha = fcolor_src.a;\n"
"gl_FragColor.a = inAlpha;\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FDrawableCopyPixelsMergeAlpha;
const char* pSource_GLSL120_FDrawableCopyPixelsMergeAlpha = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"float inAlpha = fcolor_src.a;\n"
"gl_FragColor.a = mix(inAlpha, 1.0, fcolor_org.a);\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FDrawableCopyPixelsNoDestAlpha;
const char* pSource_GLSL120_FDrawableCopyPixelsNoDestAlpha = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"float inAlpha = fcolor_src.a;\n"
"gl_FragColor.a = 1.0;\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_VDrawableCopyPixelsAlpha;
const char* pSource_GLSL120_VDrawableCopyPixelsAlpha = 
"#version 120\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[6];\n"
"attribute vec4 pos;\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"varying vec2 tc2;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"tc2.x = dot(pos, texgen[int(4.0)]);\n"
"tc2.y = dot(pos, texgen[int(5.0)]);\n"
"}\n";

extern const char* pSource_GLSL120_FDrawableCopyPixelsAlpha;
const char* pSource_GLSL120_FDrawableCopyPixelsAlpha = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"varying vec2 tc2;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"vec4 fcolor_alp = texture2D(tex[int(2.0)], tc2);\n"
"float inAlpha = fcolor_src.a * fcolor_alp.a;\n"
"gl_FragColor.a = inAlpha;\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FDrawableCopyPixelsAlphaMergeAlpha;
const char* pSource_GLSL120_FDrawableCopyPixelsAlphaMergeAlpha = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"varying vec2 tc2;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"vec4 fcolor_alp = texture2D(tex[int(2.0)], tc2);\n"
"float inAlpha = fcolor_src.a * fcolor_alp.a;\n"
"gl_FragColor.a = mix(inAlpha, 1.0, fcolor_org.a);\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FDrawableCopyPixelsAlphaNoDestAlpha;
const char* pSource_GLSL120_FDrawableCopyPixelsAlphaNoDestAlpha = 
"#version 120\n"
"uniform sampler2D tex[3];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"varying vec2 tc2;\n"
"void main() {\n"
"vec4 fcolor_org = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture2D(tex[int(1.0)], tc1);\n"
"vec4 fcolor_alp = texture2D(tex[int(2.0)], tc2);\n"
"float inAlpha = fcolor_src.a * fcolor_alp.a;\n"
"gl_FragColor.a = 1.0;\n"
"gl_FragColor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / gl_FragColor.a);\n"
"}\n";

extern const char* pSource_GLSL120_FDrawableMerge;
const char* pSource_GLSL120_FDrawableMerge = 
"#version 120\n"
"uniform mat4 cxmul;\n"
"uniform mat4 cxmul1;\n"
"uniform sampler2D tex[2];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor_original = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor_source   = texture2D(tex[int(1.0)], tc1);\n"
"gl_FragColor = (fcolor_original) * ( cxmul) + (fcolor_source) * ( cxmul1);\n"
"}\n";

extern const char* pSource_GLSL120_FDrawableCompare;
const char* pSource_GLSL120_FDrawableCompare = 
"#version 120\n"
"uniform sampler2D tex[2];\n"
"varying vec2 tc0;\n"
"varying vec2 tc1;\n"
"void main() {\n"
"vec4 fcolor0 = texture2D(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture2D(tex[int(1.0)], tc1);\n"
"vec4 diff = fcolor0 - fcolor1;\n"
"vec4 oneValue = vec4(1.0/255.0, 1.0/255.0, 1.0/255.0, 1.0/255.0 );\n"
"vec4 ltZero = (sign(diff)+vec4(1.0,1,1.0,1))*-0.25;\n"
"vec4 partDiff = oneValue * (sign(ltZero)+vec4(1.0,1,1.0,1));\n"
"vec4 wrapDiff = fract(diff + vec4(1.0,1,1.0,1)) + partDiff;\n"
"float rgbdiff = sign(dot(wrapDiff.rgb, vec3(1.0,1,1.0)));\n"
"gl_FragColor = mix( vec4(1.0,1,1.0, wrapDiff.a), vec4(wrapDiff.rgb, 1.0), rgbdiff );\n"
"}\n";

extern const char* pSource_GLSL120_FDrawablePaletteMap;
const char* pSource_GLSL120_FDrawablePaletteMap = 
"#version 120\n"
"uniform sampler2D srctex;\n"
"uniform sampler2D tex;\n"
"varying vec2 tc;\n"
"void main() {\n"
"vec4 fchannels = texture2D(tex, tc);\n"
"gl_FragColor  = texture2D(srctex, vec2(fchannels.r, 0.125));\n"
"gl_FragColor += texture2D(srctex, vec2(fchannels.g, 0.375));\n"
"gl_FragColor += texture2D(srctex, vec2(fchannels.b, 0.625));\n"
"gl_FragColor += texture2D(srctex, vec2(fchannels.a, 0.875));\n"
"}\n";

extern const char* pSource_GLSL150_VTexTG;
const char* pSource_GLSL150_VTexTG = 
"#version 150\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTG;
const char* pSource_GLSL150_FTexTG = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGMul;
const char* pSource_GLSL150_FTexTGMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGInv;
const char* pSource_GLSL150_FTexTGInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VTexTGEAlpha;
const char* pSource_GLSL150_VTexTGEAlpha = 
"#version 150\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGEAlpha;
const char* pSource_GLSL150_FTexTGEAlpha = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGEAlphaMul;
const char* pSource_GLSL150_FTexTGEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGEAlphaInv;
const char* pSource_GLSL150_FTexTGEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VTexTGCxform;
const char* pSource_GLSL150_VTexTGCxform = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"in vec4 pos;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxform;
const char* pSource_GLSL150_FTexTGCxform = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformMul;
const char* pSource_GLSL150_FTexTGCxformMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformInv;
const char* pSource_GLSL150_FTexTGCxformInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VTexTGCxformEAlpha;
const char* pSource_GLSL150_VTexTGCxformEAlpha = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformEAlpha;
const char* pSource_GLSL150_FTexTGCxformEAlpha = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformEAlphaMul;
const char* pSource_GLSL150_FTexTGCxformEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformEAlphaInv;
const char* pSource_GLSL150_FTexTGCxformEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformAc;
const char* pSource_GLSL150_FTexTGCxformAc = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformAcMul;
const char* pSource_GLSL150_FTexTGCxformAcMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformAcInv;
const char* pSource_GLSL150_FTexTGCxformAcInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformAcEAlpha;
const char* pSource_GLSL150_FTexTGCxformAcEAlpha = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformAcEAlphaMul;
const char* pSource_GLSL150_FTexTGCxformAcEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCxformAcEAlphaInv;
const char* pSource_GLSL150_FTexTGCxformAcEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VVertex;
const char* pSource_GLSL150_VVertex = 
"#version 150\n"
"uniform vec4 mvp[2];\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL150_FVertex;
const char* pSource_GLSL150_FVertex = 
"#version 150\n"
"in vec4 color;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexMul;
const char* pSource_GLSL150_FVertexMul = 
"#version 150\n"
"in vec4 color;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexInv;
const char* pSource_GLSL150_FVertexInv = 
"#version 150\n"
"in vec4 color;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VVertexEAlpha;
const char* pSource_GLSL150_VVertexEAlpha = 
"#version 150\n"
"uniform vec4 mvp[2];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexEAlpha;
const char* pSource_GLSL150_FVertexEAlpha = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexEAlphaMul;
const char* pSource_GLSL150_FVertexEAlphaMul = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexEAlphaInv;
const char* pSource_GLSL150_FVertexEAlphaInv = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VVertexCxform;
const char* pSource_GLSL150_VVertexCxform = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxform;
const char* pSource_GLSL150_FVertexCxform = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformMul;
const char* pSource_GLSL150_FVertexCxformMul = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformInv;
const char* pSource_GLSL150_FVertexCxformInv = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VVertexCxformEAlpha;
const char* pSource_GLSL150_VVertexCxformEAlpha = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformEAlpha;
const char* pSource_GLSL150_FVertexCxformEAlpha = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformEAlphaMul;
const char* pSource_GLSL150_FVertexCxformEAlphaMul = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformEAlphaInv;
const char* pSource_GLSL150_FVertexCxformEAlphaInv = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformAc;
const char* pSource_GLSL150_FVertexCxformAc = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformAcMul;
const char* pSource_GLSL150_FVertexCxformAcMul = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformAcInv;
const char* pSource_GLSL150_FVertexCxformAcInv = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformAcEAlpha;
const char* pSource_GLSL150_FVertexCxformAcEAlpha = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformAcEAlphaMul;
const char* pSource_GLSL150_FVertexCxformAcEAlphaMul = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FVertexCxformAcEAlphaInv;
const char* pSource_GLSL150_FVertexCxformAcEAlphaInv = 
"#version 150\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VTexTGTexTG;
const char* pSource_GLSL150_VTexTGTexTG = 
"#version 150\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[4];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTG;
const char* pSource_GLSL150_FTexTGTexTG = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGMul;
const char* pSource_GLSL150_FTexTGTexTGMul = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGInv;
const char* pSource_GLSL150_FTexTGTexTGInv = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGEAlpha;
const char* pSource_GLSL150_FTexTGTexTGEAlpha = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGEAlphaMul;
const char* pSource_GLSL150_FTexTGTexTGEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGEAlphaInv;
const char* pSource_GLSL150_FTexTGTexTGEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VTexTGTexTGCxform;
const char* pSource_GLSL150_VTexTGTexTGCxform = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[4];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxform;
const char* pSource_GLSL150_FTexTGTexTGCxform = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformMul;
const char* pSource_GLSL150_FTexTGTexTGCxformMul = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformInv;
const char* pSource_GLSL150_FTexTGTexTGCxformInv = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformEAlpha;
const char* pSource_GLSL150_FTexTGTexTGCxformEAlpha = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformEAlphaMul;
const char* pSource_GLSL150_FTexTGTexTGCxformEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformEAlphaInv;
const char* pSource_GLSL150_FTexTGTexTGCxformEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformAc;
const char* pSource_GLSL150_FTexTGTexTGCxformAc = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformAcMul;
const char* pSource_GLSL150_FTexTGTexTGCxformAcMul = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformAcInv;
const char* pSource_GLSL150_FTexTGTexTGCxformAcInv = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformAcEAlpha;
const char* pSource_GLSL150_FTexTGTexTGCxformAcEAlpha = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformAcEAlphaMul;
const char* pSource_GLSL150_FTexTGTexTGCxformAcEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGTexTGCxformAcEAlphaInv;
const char* pSource_GLSL150_FTexTGTexTGCxformAcEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VTexTGVertex;
const char* pSource_GLSL150_VTexTGVertex = 
"#version 150\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertex;
const char* pSource_GLSL150_FTexTGVertex = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexMul;
const char* pSource_GLSL150_FTexTGVertexMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexInv;
const char* pSource_GLSL150_FTexTGVertexInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexEAlpha;
const char* pSource_GLSL150_FTexTGVertexEAlpha = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexEAlphaMul;
const char* pSource_GLSL150_FTexTGVertexEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexEAlphaInv;
const char* pSource_GLSL150_FTexTGVertexEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VTexTGVertexCxform;
const char* pSource_GLSL150_VTexTGVertexCxform = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[2];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxform;
const char* pSource_GLSL150_FTexTGVertexCxform = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformMul;
const char* pSource_GLSL150_FTexTGVertexCxformMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformInv;
const char* pSource_GLSL150_FTexTGVertexCxformInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformEAlpha;
const char* pSource_GLSL150_FTexTGVertexCxformEAlpha = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformEAlphaMul;
const char* pSource_GLSL150_FTexTGVertexCxformEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformEAlphaInv;
const char* pSource_GLSL150_FTexTGVertexCxformEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformAc;
const char* pSource_GLSL150_FTexTGVertexCxformAc = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformAcMul;
const char* pSource_GLSL150_FTexTGVertexCxformAcMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformAcInv;
const char* pSource_GLSL150_FTexTGVertexCxformAcInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformAcEAlpha;
const char* pSource_GLSL150_FTexTGVertexCxformAcEAlpha = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformAcEAlphaMul;
const char* pSource_GLSL150_FTexTGVertexCxformAcEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGVertexCxformAcEAlphaInv;
const char* pSource_GLSL150_FTexTGVertexCxformAcEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dTexTG;
const char* pSource_GLSL150_VPosition3dTexTG = 
"#version 150\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dTexTGEAlpha;
const char* pSource_GLSL150_VPosition3dTexTGEAlpha = 
"#version 150\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dTexTGCxform;
const char* pSource_GLSL150_VPosition3dTexTGCxform = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"in vec4 pos;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dTexTGCxformEAlpha;
const char* pSource_GLSL150_VPosition3dTexTGCxformEAlpha = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dVertex;
const char* pSource_GLSL150_VPosition3dVertex = 
"#version 150\n"
"uniform mat4 mvp;\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dVertexEAlpha;
const char* pSource_GLSL150_VPosition3dVertexEAlpha = 
"#version 150\n"
"uniform mat4 mvp;\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dVertexCxform;
const char* pSource_GLSL150_VPosition3dVertexCxform = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dVertexCxformEAlpha;
const char* pSource_GLSL150_VPosition3dVertexCxformEAlpha = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dTexTGTexTG;
const char* pSource_GLSL150_VPosition3dTexTGTexTG = 
"#version 150\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[4];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dTexTGTexTGCxform;
const char* pSource_GLSL150_VPosition3dTexTGTexTGCxform = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[4];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dTexTGVertex;
const char* pSource_GLSL150_VPosition3dTexTGVertex = 
"#version 150\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dTexTGVertexCxform;
const char* pSource_GLSL150_VPosition3dTexTGVertexCxform = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"uniform vec4 texgen[2];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"color = acolor;\n"
"tc.x = dot(pos, texgen[int(0.0)]);\n"
"tc.y = dot(pos, texgen[int(1.0)]);\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchTexTG;
const char* pSource_GLSL150_VBatchTexTG = 
"#version 150\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_VBatchTexTGEAlpha;
const char* pSource_GLSL150_VBatchTexTGEAlpha = 
"#version 150\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchTexTGCxform;
const char* pSource_GLSL150_VBatchTexTGCxform = 
"#version 150\n"
"uniform vec4 vfuniforms[144];\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(vbatch * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 6.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_VBatchTexTGCxformEAlpha;
const char* pSource_GLSL150_VBatchTexTGCxformEAlpha = 
"#version 150\n"
"uniform vec4 vfuniforms[144];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchVertex;
const char* pSource_GLSL150_VBatchVertex = 
"#version 150\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec4 color;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchVertexEAlpha;
const char* pSource_GLSL150_VBatchVertexEAlpha = 
"#version 150\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchVertexCxform;
const char* pSource_GLSL150_VBatchVertexCxform = 
"#version 150\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec4 color;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_VBatchVertexCxformEAlpha;
const char* pSource_GLSL150_VBatchVertexCxformEAlpha = 
"#version 150\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchTexTGTexTG;
const char* pSource_GLSL150_VBatchTexTGTexTG = 
"#version 150\n"
"uniform vec4 vfuniforms[144];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchTexTGTexTGCxform;
const char* pSource_GLSL150_VBatchTexTGTexTGCxform = 
"#version 150\n"
"uniform vec4 vfuniforms[192];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 8.0 + 4.0+ 0.1 + 3.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 8.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 8.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchTexTGVertex;
const char* pSource_GLSL150_VBatchTexTGVertex = 
"#version 150\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchTexTGVertexCxform;
const char* pSource_GLSL150_VBatchTexTGVertexCxform = 
"#version 150\n"
"uniform vec4 vfuniforms[144];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dTexTG;
const char* pSource_GLSL150_VBatchPosition3dTexTG = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dTexTGEAlpha;
const char* pSource_GLSL150_VBatchPosition3dTexTGEAlpha = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dTexTGCxform;
const char* pSource_GLSL150_VBatchPosition3dTexTGCxform = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dTexTGCxformEAlpha;
const char* pSource_GLSL150_VBatchPosition3dTexTGCxformEAlpha = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dVertex;
const char* pSource_GLSL150_VBatchPosition3dVertex = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec4 color;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dVertexEAlpha;
const char* pSource_GLSL150_VBatchPosition3dVertexEAlpha = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dVertexCxform;
const char* pSource_GLSL150_VBatchPosition3dVertexCxform = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec4 color;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 2.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dVertexCxformEAlpha;
const char* pSource_GLSL150_VBatchPosition3dVertexCxformEAlpha = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 2.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dTexTGTexTG;
const char* pSource_GLSL150_VBatchPosition3dTexTGTexTG = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1 + 3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dTexTGTexTGCxform;
const char* pSource_GLSL150_VBatchPosition3dTexTGTexTGCxform = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[144];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"tc0.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 6.0 + 2.0+ 0.1 + 3.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dTexTGVertex;
const char* pSource_GLSL150_VBatchPosition3dTexTGVertex = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dTexTGVertexCxform;
const char* pSource_GLSL150_VBatchPosition3dTexTGVertexCxform = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(afactor.b*255.01 * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(afactor.b*255.01 * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(afactor.b*255.01 * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(afactor.b*255.01 * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedTexTG;
const char* pSource_GLSL150_VInstancedTexTG = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTG;
const char* pSource_GLSL150_FInstancedTexTG = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGMul;
const char* pSource_GLSL150_FInstancedTexTGMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGInv;
const char* pSource_GLSL150_FInstancedTexTGInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedTexTGEAlpha;
const char* pSource_GLSL150_VInstancedTexTGEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGEAlpha;
const char* pSource_GLSL150_FInstancedTexTGEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGEAlphaMul;
const char* pSource_GLSL150_FInstancedTexTGEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGEAlphaInv;
const char* pSource_GLSL150_FInstancedTexTGEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedTexTGCxform;
const char* pSource_GLSL150_VInstancedTexTGCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[144];\n"
"in vec4 pos;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 6.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxform;
const char* pSource_GLSL150_FInstancedTexTGCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformMul;
const char* pSource_GLSL150_FInstancedTexTGCxformMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformInv;
const char* pSource_GLSL150_FInstancedTexTGCxformInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedTexTGCxformEAlpha;
const char* pSource_GLSL150_VInstancedTexTGCxformEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[144];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformEAlpha;
const char* pSource_GLSL150_FInstancedTexTGCxformEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformEAlphaMul;
const char* pSource_GLSL150_FInstancedTexTGCxformEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformEAlphaInv;
const char* pSource_GLSL150_FInstancedTexTGCxformEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformAc;
const char* pSource_GLSL150_FInstancedTexTGCxformAc = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformAcMul;
const char* pSource_GLSL150_FInstancedTexTGCxformAcMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformAcInv;
const char* pSource_GLSL150_FInstancedTexTGCxformAcInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformAcEAlpha;
const char* pSource_GLSL150_FInstancedTexTGCxformAcEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformAcEAlphaMul;
const char* pSource_GLSL150_FInstancedTexTGCxformAcEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGCxformAcEAlphaInv;
const char* pSource_GLSL150_FInstancedTexTGCxformAcEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedVertex;
const char* pSource_GLSL150_VInstancedVertex = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertex;
const char* pSource_GLSL150_FInstancedVertex = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexMul;
const char* pSource_GLSL150_FInstancedVertexMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexInv;
const char* pSource_GLSL150_FInstancedVertexInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedVertexEAlpha;
const char* pSource_GLSL150_VInstancedVertexEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexEAlpha;
const char* pSource_GLSL150_FInstancedVertexEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexEAlphaMul;
const char* pSource_GLSL150_FInstancedVertexEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexEAlphaInv;
const char* pSource_GLSL150_FInstancedVertexEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedVertexCxform;
const char* pSource_GLSL150_VInstancedVertexCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxform;
const char* pSource_GLSL150_FInstancedVertexCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformMul;
const char* pSource_GLSL150_FInstancedVertexCxformMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformInv;
const char* pSource_GLSL150_FInstancedVertexCxformInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedVertexCxformEAlpha;
const char* pSource_GLSL150_VInstancedVertexCxformEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformEAlpha;
const char* pSource_GLSL150_FInstancedVertexCxformEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformEAlphaMul;
const char* pSource_GLSL150_FInstancedVertexCxformEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformEAlphaInv;
const char* pSource_GLSL150_FInstancedVertexCxformEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformAc;
const char* pSource_GLSL150_FInstancedVertexCxformAc = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformAcMul;
const char* pSource_GLSL150_FInstancedVertexCxformAcMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformAcInv;
const char* pSource_GLSL150_FInstancedVertexCxformAcInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformAcEAlpha;
const char* pSource_GLSL150_FInstancedVertexCxformAcEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformAcEAlphaMul;
const char* pSource_GLSL150_FInstancedVertexCxformAcEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedVertexCxformAcEAlphaInv;
const char* pSource_GLSL150_FInstancedVertexCxformAcEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = color;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedTexTGTexTG;
const char* pSource_GLSL150_VInstancedTexTGTexTG = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[144];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc0.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTG;
const char* pSource_GLSL150_FInstancedTexTGTexTG = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGMul;
const char* pSource_GLSL150_FInstancedTexTGTexTGMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGInv;
const char* pSource_GLSL150_FInstancedTexTGTexTGInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGEAlpha;
const char* pSource_GLSL150_FInstancedTexTGTexTGEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGEAlphaMul;
const char* pSource_GLSL150_FInstancedTexTGTexTGEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGEAlphaInv;
const char* pSource_GLSL150_FInstancedTexTGTexTGEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedTexTGTexTGCxform;
const char* pSource_GLSL150_VInstancedTexTGTexTGCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[192];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 8.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 8.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc0.x = dot(pos, vfuniforms[int(gl_InstanceID * 8.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(gl_InstanceID * 8.0 + 4.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(gl_InstanceID * 8.0 + 4.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(gl_InstanceID * 8.0 + 4.0+ 0.1 + 3.0)]);\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 8.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 8.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxform;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformMul;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformInv;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformEAlpha;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformEAlphaMul;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformEAlphaInv;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAc;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAc = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAcMul;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAcMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAcInv;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAcInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAcEAlpha;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAcEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAcEAlphaMul;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAcEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAcEAlphaInv;
const char* pSource_GLSL150_FInstancedTexTGTexTGCxformAcEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[2];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedTexTGVertex;
const char* pSource_GLSL150_VInstancedTexTGVertex = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertex;
const char* pSource_GLSL150_FInstancedTexTGVertex = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexMul;
const char* pSource_GLSL150_FInstancedTexTGVertexMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexInv;
const char* pSource_GLSL150_FInstancedTexTGVertexInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexEAlpha;
const char* pSource_GLSL150_FInstancedTexTGVertexEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexEAlphaMul;
const char* pSource_GLSL150_FInstancedTexTGVertexEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexEAlphaInv;
const char* pSource_GLSL150_FInstancedTexTGVertexEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedTexTGVertexCxform;
const char* pSource_GLSL150_VInstancedTexTGVertexCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[144];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 4.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 4.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxform;
const char* pSource_GLSL150_FInstancedTexTGVertexCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformMul;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformInv;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformEAlpha;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformEAlphaMul;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformEAlphaInv;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformAc;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformAc = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformAcMul;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformAcMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformAcInv;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformAcInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformAcEAlpha;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformAcEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformAcEAlphaMul;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformAcEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTexTGVertexCxformAcEAlphaInv;
const char* pSource_GLSL150_FInstancedTexTGVertexCxformAcEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec4 color;\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex,tc);\n"
"vec4 fcolor1 = color;\n"
"fcolor = mix(fcolor1, fcolor0, factor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dTexTG;
const char* pSource_GLSL150_VInstancedPosition3dTexTG = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dTexTGEAlpha;
const char* pSource_GLSL150_VInstancedPosition3dTexTGEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dTexTGCxform;
const char* pSource_GLSL150_VInstancedPosition3dTexTGCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 pos;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dTexTGCxformEAlpha;
const char* pSource_GLSL150_VInstancedPosition3dTexTGCxformEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dVertex;
const char* pSource_GLSL150_VInstancedPosition3dVertex = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dVertexEAlpha;
const char* pSource_GLSL150_VInstancedPosition3dVertexEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dVertexCxform;
const char* pSource_GLSL150_VInstancedPosition3dVertexCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 2.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dVertexCxformEAlpha;
const char* pSource_GLSL150_VInstancedPosition3dVertexCxformEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 2.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dTexTGTexTG;
const char* pSource_GLSL150_VInstancedPosition3dTexTGTexTG = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"tc0.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1 + 3.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dTexTGTexTGCxform;
const char* pSource_GLSL150_VInstancedPosition3dTexTGTexTGCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[144];\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"tc0.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc0.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc1.x = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 2.0)]);\n"
"tc1.y = dot(pos, vfuniforms[int(gl_InstanceID * 6.0 + 2.0+ 0.1 + 3.0)]);\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 6.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 6.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dTexTGVertex;
const char* pSource_GLSL150_VInstancedPosition3dTexTGVertex = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dTexTGVertexCxform;
const char* pSource_GLSL150_VInstancedPosition3dTexTGVertexCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 acolor;\n"
"in vec4 afactor;\n"
"in vec4 pos;\n"
"out vec4 color;\n"
"out vec4 factor;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"color = acolor;\n"
"tc.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"tc.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 4.0 + 1.0+ 0.1)];\n"
"factor = afactor;\n"
"}\n";

extern const char* pSource_GLSL150_VSolid;
const char* pSource_GLSL150_VSolid = 
"#version 150\n"
"uniform vec4 mvp[2];\n"
"in vec4 pos;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_FSolid;
const char* pSource_GLSL150_FSolid = 
"#version 150\n"
"uniform vec4 cxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = cxmul;\n"
"}\n";

extern const char* pSource_GLSL150_FSolidMul;
const char* pSource_GLSL150_FSolidMul = 
"#version 150\n"
"uniform vec4 cxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = cxmul;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FSolidInv;
const char* pSource_GLSL150_FSolidInv = 
"#version 150\n"
"uniform vec4 cxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = cxmul;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VText;
const char* pSource_GLSL150_VText = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"in vec4 acolor;\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"out vec4 vcolor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"vcolor = acolor * cxmul + cxadd;\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_FText;
const char* pSource_GLSL150_FText = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"in vec4 vcolor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture(tex, tc).r;\n"
"fcolor = c;\n"
"}\n";

extern const char* pSource_GLSL150_FTextMul;
const char* pSource_GLSL150_FTextMul = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"in vec4 vcolor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture(tex, tc).r;\n"
"fcolor = c;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTextInv;
const char* pSource_GLSL150_FTextInv = 
"#version 150\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"in vec4 vcolor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture(tex, tc).r;\n"
"fcolor = c;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VTextColor;
const char* pSource_GLSL150_VTextColor = 
"#version 150\n"
"uniform vec4 mvp[2];\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_VTextColorCxform;
const char* pSource_GLSL150_VTextColorCxform = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform vec4 mvp[2];\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc = atc;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dSolid;
const char* pSource_GLSL150_VPosition3dSolid = 
"#version 150\n"
"uniform mat4 mvp;\n"
"in vec4 pos;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dText;
const char* pSource_GLSL150_VPosition3dText = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"in vec4 acolor;\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"out vec4 vcolor;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"vcolor = acolor * cxmul + cxadd;\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dTextColor;
const char* pSource_GLSL150_VPosition3dTextColor = 
"#version 150\n"
"uniform mat4 mvp;\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_VPosition3dTextColorCxform;
const char* pSource_GLSL150_VPosition3dTextColorCxform = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform vec4 cxmul;\n"
"uniform mat4 mvp;\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( mvp);\n"
"tc = atc;\n"
"fucxadd = cxadd;\n"
"fucxmul = cxmul;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchSolid;
const char* pSource_GLSL150_VBatchSolid = 
"#version 150\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_VBatchText;
const char* pSource_GLSL150_VBatchText = 
"#version 150\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 acolor;\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec2 tc;\n"
"out vec4 vcolor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"vcolor = acolor * vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)] + vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchTextColor;
const char* pSource_GLSL150_VBatchTextColor = 
"#version 150\n"
"uniform vec4 vfuniforms[48];\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchTextColorCxform;
const char* pSource_GLSL150_VBatchTextColorCxform = 
"#version 150\n"
"uniform vec4 vfuniforms[96];\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(vbatch * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc = atc;\n"
"fucxadd = vfuniforms[int(vbatch * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dSolid;
const char* pSource_GLSL150_VBatchPosition3dSolid = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dText;
const char* pSource_GLSL150_VBatchPosition3dText = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec2 tc;\n"
"out vec4 vcolor;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"vcolor = acolor * vfuniforms[int(vbatch * 2.0 + 1.0+ 0.1)] + vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1)];\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dTextColor;
const char* pSource_GLSL150_VBatchPosition3dTextColor = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_VBatchPosition3dTextColorCxform;
const char* pSource_GLSL150_VBatchPosition3dTextColorCxform = 
"#version 150\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"in float vbatch;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(vbatch * 1.0 + 0.0+ 0.1)]);\n"
"tc = atc;\n"
"fucxadd = vfuniforms[int(vbatch * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(vbatch * 2.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedSolid;
const char* pSource_GLSL150_VInstancedSolid = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 pos;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedSolid;
const char* pSource_GLSL150_FInstancedSolid = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 cxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = cxmul;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedSolidMul;
const char* pSource_GLSL150_FInstancedSolidMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 cxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = cxmul;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedSolidInv;
const char* pSource_GLSL150_FInstancedSolidInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 cxmul;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = cxmul;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedText;
const char* pSource_GLSL150_VInstancedText = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[96];\n"
"in vec4 acolor;\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"out vec4 vcolor;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"vcolor = acolor * vfuniforms[int(gl_InstanceID * 4.0 + 1.0+ 0.1)] + vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1)];\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedText;
const char* pSource_GLSL150_FInstancedText = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"in vec4 vcolor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture(tex, tc).r;\n"
"fcolor = c;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTextMul;
const char* pSource_GLSL150_FInstancedTextMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"in vec4 vcolor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture(tex, tc).r;\n"
"fcolor = c;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedTextInv;
const char* pSource_GLSL150_FInstancedTextInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"in vec4 vcolor;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 c = vcolor;\n"
"c.a = c.a * texture(tex, tc).r;\n"
"fcolor = c;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedTextColor;
const char* pSource_GLSL150_VInstancedTextColor = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[48];\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1 + 1.0)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedTextColorCxform;
const char* pSource_GLSL150_VInstancedTextColorCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform vec4 vfuniforms[96];\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 0.0)]);\n"
"gl_Position.y = dot(pos, vfuniforms[int(gl_InstanceID * 4.0 + 2.0+ 0.1 + 1.0)]);\n"
"tc = atc;\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 4.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 4.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dSolid;
const char* pSource_GLSL150_VInstancedPosition3dSolid = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"in vec4 pos;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dText;
const char* pSource_GLSL150_VInstancedPosition3dText = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec4 acolor;\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"out vec4 vcolor;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"vcolor = acolor * vfuniforms[int(gl_InstanceID * 2.0 + 1.0+ 0.1)] + vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1)];\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dTextColor;
const char* pSource_GLSL150_VInstancedPosition3dTextColor = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"tc = atc;\n"
"}\n";

extern const char* pSource_GLSL150_VInstancedPosition3dTextColorCxform;
const char* pSource_GLSL150_VInstancedPosition3dTextColorCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform mat4 vfmuniforms[24];\n"
"uniform vec4 vfuniforms[48];\n"
"in vec2 atc;\n"
"in vec4 pos;\n"
"out vec4 fucxadd;\n"
"out vec4 fucxmul;\n"
"out vec2 tc;\n"
"void main() {\n"
"gl_Position = (pos) * ( vfmuniforms[int(gl_InstanceID * 1.0 + 0.0+ 0.1)]);\n"
"tc = atc;\n"
"fucxadd = vfuniforms[int(gl_InstanceID * 2.0 + 0.0+ 0.1)];\n"
"fucxmul = vfuniforms[int(gl_InstanceID * 2.0 + 1.0+ 0.1)];\n"
"}\n";

extern const char* pSource_GLSL150_FYUV;
const char* pSource_GLSL150_FYUV = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVMul;
const char* pSource_GLSL150_FYUVMul = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVEAlpha;
const char* pSource_GLSL150_FYUVEAlpha = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVEAlphaMul;
const char* pSource_GLSL150_FYUVEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVCxform;
const char* pSource_GLSL150_FYUVCxform = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVCxformMul;
const char* pSource_GLSL150_FYUVCxformMul = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVCxformEAlpha;
const char* pSource_GLSL150_FYUVCxformEAlpha = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVCxformEAlphaMul;
const char* pSource_GLSL150_FYUVCxformEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVCxformAc;
const char* pSource_GLSL150_FYUVCxformAc = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVCxformAcMul;
const char* pSource_GLSL150_FYUVCxformAcMul = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVCxformAcEAlpha;
const char* pSource_GLSL150_FYUVCxformAcEAlpha = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVCxformAcEAlphaMul;
const char* pSource_GLSL150_FYUVCxformAcEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVA;
const char* pSource_GLSL150_FYUVA = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVAMul;
const char* pSource_GLSL150_FYUVAMul = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVAInv;
const char* pSource_GLSL150_FYUVAInv = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FYUVAEAlpha;
const char* pSource_GLSL150_FYUVAEAlpha = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVAEAlphaMul;
const char* pSource_GLSL150_FYUVAEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVAEAlphaInv;
const char* pSource_GLSL150_FYUVAEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxform;
const char* pSource_GLSL150_FYUVACxform = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformMul;
const char* pSource_GLSL150_FYUVACxformMul = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformInv;
const char* pSource_GLSL150_FYUVACxformInv = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformEAlpha;
const char* pSource_GLSL150_FYUVACxformEAlpha = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformEAlphaMul;
const char* pSource_GLSL150_FYUVACxformEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformEAlphaInv;
const char* pSource_GLSL150_FYUVACxformEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformAc;
const char* pSource_GLSL150_FYUVACxformAc = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformAcMul;
const char* pSource_GLSL150_FYUVACxformAcMul = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformAcInv;
const char* pSource_GLSL150_FYUVACxformAcInv = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformAcEAlpha;
const char* pSource_GLSL150_FYUVACxformAcEAlpha = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformAcEAlphaMul;
const char* pSource_GLSL150_FYUVACxformAcEAlphaMul = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FYUVACxformAcEAlphaInv;
const char* pSource_GLSL150_FYUVACxformAcEAlphaInv = 
"#version 150\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUV;
const char* pSource_GLSL150_FInstancedYUV = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVMul;
const char* pSource_GLSL150_FInstancedYUVMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVEAlpha;
const char* pSource_GLSL150_FInstancedYUVEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVEAlphaMul;
const char* pSource_GLSL150_FInstancedYUVEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVCxform;
const char* pSource_GLSL150_FInstancedYUVCxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVCxformMul;
const char* pSource_GLSL150_FInstancedYUVCxformMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVCxformEAlpha;
const char* pSource_GLSL150_FInstancedYUVCxformEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVCxformEAlphaMul;
const char* pSource_GLSL150_FInstancedYUVCxformEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVCxformAc;
const char* pSource_GLSL150_FInstancedYUVCxformAc = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVCxformAcMul;
const char* pSource_GLSL150_FInstancedYUVCxformAcMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVCxformAcEAlpha;
const char* pSource_GLSL150_FInstancedYUVCxformAcEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVCxformAcEAlphaMul;
const char* pSource_GLSL150_FInstancedYUVCxformAcEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[3];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = 1.0;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVA;
const char* pSource_GLSL150_FInstancedYUVA = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVAMul;
const char* pSource_GLSL150_FInstancedYUVAMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVAInv;
const char* pSource_GLSL150_FInstancedYUVAInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVAEAlpha;
const char* pSource_GLSL150_FInstancedYUVAEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVAEAlphaMul;
const char* pSource_GLSL150_FInstancedYUVAEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVAEAlphaInv;
const char* pSource_GLSL150_FInstancedYUVAEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxform;
const char* pSource_GLSL150_FInstancedYUVACxform = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformMul;
const char* pSource_GLSL150_FInstancedYUVACxformMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformInv;
const char* pSource_GLSL150_FInstancedYUVACxformInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformEAlpha;
const char* pSource_GLSL150_FInstancedYUVACxformEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformEAlphaMul;
const char* pSource_GLSL150_FInstancedYUVACxformEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformEAlphaInv;
const char* pSource_GLSL150_FInstancedYUVACxformEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = fcolor * fucxmul + fucxadd;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformAc;
const char* pSource_GLSL150_FInstancedYUVACxformAc = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformAcMul;
const char* pSource_GLSL150_FInstancedYUVACxformAcMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformAcInv;
const char* pSource_GLSL150_FInstancedYUVACxformAcInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformAcEAlpha;
const char* pSource_GLSL150_FInstancedYUVACxformAcEAlpha = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformAcEAlphaMul;
const char* pSource_GLSL150_FInstancedYUVACxformAcEAlphaMul = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FInstancedYUVACxformAcEAlphaInv;
const char* pSource_GLSL150_FInstancedYUVACxformAcEAlphaInv = 
"#version 150\n"
"#extension GL_ARB_draw_instanced : enable\n"
"uniform sampler2D tex[4];\n"
"in vec4 factor;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"float c0 = float((texture(tex[int(0.0)], tc).r - 16./255.) * 1.164);\n"
"float U0 = float(texture(tex[int(1.0)], tc).r - 128./255.);\n"
"float V0 = float(texture(tex[int(2.0)], tc).r - 128./255.);\n"
"vec4 c = vec4(c0,c0,c0,c0);\n"
"vec4 U = vec4(U0,U0,U0,U0);\n"
"vec4 V = vec4(V0,V0,V0,V0);\n"
"c += V * vec4(1.596, -0.813, 0.0, 0.0);\n"
"c += U * vec4(0.0, -0.392, 2.017, 0.0);\n"
"c.a = texture(tex[int(3.0)], tc).r;\n"
"fcolor = c;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = vec3(fcolor.a, fcolor.a, fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCMatrixAc;
const char* pSource_GLSL150_FTexTGCMatrixAc = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor) * (cxmul) + cxadd * (fcolor.a + cxadd.a);\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCMatrixAcMul;
const char* pSource_GLSL150_FTexTGCMatrixAcMul = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor) * (cxmul) + cxadd * (fcolor.a + cxadd.a);\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCMatrixAcEAlpha;
const char* pSource_GLSL150_FTexTGCMatrixAcEAlpha = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor) * (cxmul) + cxadd * (fcolor.a + cxadd.a);\n"
"fcolor.a *= factor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FTexTGCMatrixAcEAlphaMul;
const char* pSource_GLSL150_FTexTGCMatrixAcEAlphaMul = 
"#version 150\n"
"uniform vec4 cxadd;\n"
"uniform mat4 cxmul;\n"
"uniform sampler2D tex;\n"
"in vec4 factor;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor = texture(tex,tc);\n"
"fcolor = (fcolor) * (cxmul) + cxadd * (fcolor.a + cxadd.a);\n"
"fcolor.a *= factor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox1Blur;
const char* pSource_GLSL150_FBox1Blur = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"float  i = 0.0;\n"
"for (i = -fsize.x; i <= fsize.x; i++)\n"
"{{\n"
"color += textureLod(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"fcolor = color * fsize.w;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox1BlurMul;
const char* pSource_GLSL150_FBox1BlurMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"float  i = 0.0;\n"
"for (i = -fsize.x; i <= fsize.x; i++)\n"
"{{\n"
"color += textureLod(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"fcolor = color * fsize.w;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2Blur;
const char* pSource_GLSL150_FBox2Blur = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"fcolor = color * fsize.w;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2BlurMul;
const char* pSource_GLSL150_FBox2BlurMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + i * texscale.xy, 0.0);\n"
"}} // EndBox1/2.\n"
"fcolor = color * fsize.w;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2Shadow;
const char* pSource_GLSL150_FBox2Shadow = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor = scolor * clamp(fcolor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2ShadowMul;
const char* pSource_GLSL150_FBox2ShadowMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor = scolor * clamp(fcolor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2ShadowKnockout;
const char* pSource_GLSL150_FBox2ShadowKnockout = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor = scolor * clamp(fcolor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"fcolor -= knockout;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2ShadowKnockoutMul;
const char* pSource_GLSL150_FBox2ShadowKnockoutMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor = scolor * clamp(fcolor.a * (1.0-base.a) * fsize.z, 0.0, 1.0) + base;\n"
"vec4 knockout = base;\n"
"fcolor -= knockout;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2InnerShadow;
const char* pSource_GLSL150_FBox2InnerShadow = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - fcolor.a) * fsize.z, 0.0, 1.0);\n"
"fcolor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2InnerShadowMul;
const char* pSource_GLSL150_FBox2InnerShadowMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - fcolor.a) * fsize.z, 0.0, 1.0);\n"
"fcolor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2InnerShadowKnockout;
const char* pSource_GLSL150_FBox2InnerShadowKnockout = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - fcolor.a) * fsize.z, 0.0, 1.0);\n"
"fcolor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"fcolor -= knockout;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2InnerShadowKnockoutMul;
const char* pSource_GLSL150_FBox2InnerShadowKnockoutMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"float lerpval = clamp((base.a - fcolor.a) * fsize.z, 0.0, 1.0);\n"
"fcolor = mix(base, scolor, lerpval) * base.a;\n"
"vec4 knockout = base * (1.0-lerpval) * base.a;\n"
"fcolor -= knockout;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2Shadowonly;
const char* pSource_GLSL150_FBox2Shadowonly = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"fcolor = scolor * clamp(fcolor.a * fsize.z, 0.0, 1.0);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2ShadowonlyMul;
const char* pSource_GLSL150_FBox2ShadowonlyMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0);\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"fcolor = scolor * clamp(fcolor.a * fsize.z, 0.0, 1.0);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2ShadowHighlight;
const char* pSource_GLSL150_FBox2ShadowHighlight = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"fcolor = ((scolor * fcolor.a + scolor2 * fcolor.r)*(1.0-base.a) + base);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2ShadowHighlightMul;
const char* pSource_GLSL150_FBox2ShadowHighlightMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"fcolor = ((scolor * fcolor.a + scolor2 * fcolor.r)*(1.0-base.a) + base);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2ShadowHighlightKnockout;
const char* pSource_GLSL150_FBox2ShadowHighlightKnockout = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"fcolor = ((scolor * fcolor.a + scolor2 * fcolor.r)*(1.0-base.a) + base);\n"
"fcolor -= knockout;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2ShadowHighlightKnockoutMul;
const char* pSource_GLSL150_FBox2ShadowHighlightKnockoutMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base;\n"
"fcolor = ((scolor * fcolor.a + scolor2 * fcolor.r)*(1.0-base.a) + base);\n"
"fcolor -= knockout;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2InnerShadowHighlight;
const char* pSource_GLSL150_FBox2InnerShadowHighlight = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - fcolor.a - fcolor.r) * base.a;\n"
"fcolor = (scolor * fcolor.a + scolor2 * fcolor.r + base* (1.0 - fcolor.a - fcolor.r)) * base.a;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2InnerShadowHighlightMul;
const char* pSource_GLSL150_FBox2InnerShadowHighlightMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - fcolor.a - fcolor.r) * base.a;\n"
"fcolor = (scolor * fcolor.a + scolor2 * fcolor.r + base* (1.0 - fcolor.a - fcolor.r)) * base.a;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2InnerShadowHighlightKnockout;
const char* pSource_GLSL150_FBox2InnerShadowHighlightKnockout = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - fcolor.a - fcolor.r) * base.a;\n"
"fcolor = (scolor * fcolor.a + scolor2 * fcolor.r + base* (1.0 - fcolor.a - fcolor.r)) * base.a;\n"
"fcolor -= knockout;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2InnerShadowHighlightKnockoutMul;
const char* pSource_GLSL150_FBox2InnerShadowHighlightKnockoutMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - fcolor.a - fcolor.r) * base.a;\n"
"fcolor = (scolor * fcolor.a + scolor2 * fcolor.r + base* (1.0 - fcolor.a - fcolor.r)) * base.a;\n"
"fcolor -= knockout;\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2FullShadowHighlight;
const char* pSource_GLSL150_FBox2FullShadowHighlight = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - fcolor.a - fcolor.r);\n"
"fcolor = (scolor * fcolor.a + scolor2 * fcolor.r + base* (1.0 - fcolor.a - fcolor.r));\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2FullShadowHighlightMul;
const char* pSource_GLSL150_FBox2FullShadowHighlightMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D srctex;\n"
"uniform vec4 srctexscale;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"vec4 base = textureLod(srctex, tc * srctexscale.xy, 0.0);\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"vec4 knockout = base * (1.0 - fcolor.a - fcolor.r);\n"
"fcolor = (scolor * fcolor.a + scolor2 * fcolor.r + base* (1.0 - fcolor.a - fcolor.r));\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2ShadowonlyHighlight;
const char* pSource_GLSL150_FBox2ShadowonlyHighlight = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"fcolor = (scolor * fcolor.a + scolor2 * fcolor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_FBox2ShadowonlyHighlightMul;
const char* pSource_GLSL150_FBox2ShadowonlyHighlightMul = 
"#version 150\n"
"uniform vec4 fsize;\n"
"uniform vec4 offset;\n"
"uniform vec4 scolor;\n"
"uniform vec4 scolor2;\n"
"uniform sampler2D tex;\n"
"uniform vec4 texscale;\n"
"in vec4 fucxadd;\n"
"in vec4 fucxmul;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"fcolor       = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec4 color = vec4(0.0, 0.0, 0.0, 0.0);\n"
"vec2 i = vec2(0.0, 0.0);\n"
"for (i.x = -fsize.x; i.x <= fsize.x; i.x++)\n"
"{\n"
"for (i.y = -fsize.y; i.y <= fsize.y; i.y++)\n"
"{\n"
"color.a += textureLod(tex, tc + (offset.xy + i) * texscale.xy, 0.0).a;\n"
"color.r += textureLod(tex, tc - (offset.xy + i) * texscale.xy, 0.0).a;\n"
"}\n"
"} // EndBox2.\n"
"fcolor = color * fsize.w;\n"
"fcolor.ar = clamp((1.0 - fcolor.ar * fsize.z) - (1.0 - fcolor.ra * fsize.z), 0.0, 1.0);\n"
"fcolor = (scolor * fcolor.a + scolor2 * fcolor.r);\n"
"fcolor = (fcolor * vec4(fucxmul.rgb,1.0)) * fucxmul.a;\n"
"fcolor += fucxadd * fcolor.a;\n"
"fcolor.rgb = fcolor.rgb * fcolor.a;\n"
"}\n";

extern const char* pSource_GLSL150_VDrawableCopyPixels;
const char* pSource_GLSL150_VDrawableCopyPixels = 
"#version 150\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[4];\n"
"in vec4 pos;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_FDrawableCopyPixels;
const char* pSource_GLSL150_FDrawableCopyPixels = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor_org = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture(tex[int(1.0)], tc1);\n"
"float inAlpha = fcolor_src.a;\n"
"fcolor.a = inAlpha;\n"
"fcolor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FDrawableCopyPixelsMergeAlpha;
const char* pSource_GLSL150_FDrawableCopyPixelsMergeAlpha = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor_org = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture(tex[int(1.0)], tc1);\n"
"float inAlpha = fcolor_src.a;\n"
"fcolor.a = mix(inAlpha, 1.0, fcolor_org.a);\n"
"fcolor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FDrawableCopyPixelsNoDestAlpha;
const char* pSource_GLSL150_FDrawableCopyPixelsNoDestAlpha = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor_org = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture(tex[int(1.0)], tc1);\n"
"float inAlpha = fcolor_src.a;\n"
"fcolor.a = 1.0;\n"
"fcolor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_VDrawableCopyPixelsAlpha;
const char* pSource_GLSL150_VDrawableCopyPixelsAlpha = 
"#version 150\n"
"uniform vec4 mvp[2];\n"
"uniform vec4 texgen[6];\n"
"in vec4 pos;\n"
"out vec2 tc0;\n"
"out vec2 tc1;\n"
"out vec2 tc2;\n"
"void main() {\n"
"gl_Position = vec4(0.0,0,0.0,1);\n"
"gl_Position.x = dot(pos, mvp[int(0.0)]);\n"
"gl_Position.y = dot(pos, mvp[int(1.0)]);\n"
"tc0.x = dot(pos, texgen[int(0.0)]);\n"
"tc0.y = dot(pos, texgen[int(1.0)]);\n"
"tc1.x = dot(pos, texgen[int(2.0)]);\n"
"tc1.y = dot(pos, texgen[int(3.0)]);\n"
"tc2.x = dot(pos, texgen[int(4.0)]);\n"
"tc2.y = dot(pos, texgen[int(5.0)]);\n"
"}\n";

extern const char* pSource_GLSL150_FDrawableCopyPixelsAlpha;
const char* pSource_GLSL150_FDrawableCopyPixelsAlpha = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"in vec2 tc2;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor_org = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture(tex[int(1.0)], tc1);\n"
"vec4 fcolor_alp = texture(tex[int(2.0)], tc2);\n"
"float inAlpha = fcolor_src.a * fcolor_alp.a;\n"
"fcolor.a = inAlpha;\n"
"fcolor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FDrawableCopyPixelsAlphaMergeAlpha;
const char* pSource_GLSL150_FDrawableCopyPixelsAlphaMergeAlpha = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"in vec2 tc2;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor_org = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture(tex[int(1.0)], tc1);\n"
"vec4 fcolor_alp = texture(tex[int(2.0)], tc2);\n"
"float inAlpha = fcolor_src.a * fcolor_alp.a;\n"
"fcolor.a = mix(inAlpha, 1.0, fcolor_org.a);\n"
"fcolor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FDrawableCopyPixelsAlphaNoDestAlpha;
const char* pSource_GLSL150_FDrawableCopyPixelsAlphaNoDestAlpha = 
"#version 150\n"
"uniform sampler2D tex[3];\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"in vec2 tc2;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor_org = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor_src = texture(tex[int(1.0)], tc1);\n"
"vec4 fcolor_alp = texture(tex[int(2.0)], tc2);\n"
"float inAlpha = fcolor_src.a * fcolor_alp.a;\n"
"fcolor.a = 1.0;\n"
"fcolor.rgb = mix(fcolor_org.rgb, fcolor_src.rgb, inAlpha / fcolor.a);\n"
"}\n";

extern const char* pSource_GLSL150_FDrawableMerge;
const char* pSource_GLSL150_FDrawableMerge = 
"#version 150\n"
"uniform mat4 cxmul;\n"
"uniform mat4 cxmul1;\n"
"uniform sampler2D tex[2];\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor_original = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor_source   = texture(tex[int(1.0)], tc1);\n"
"fcolor = (fcolor_original) * ( cxmul) + (fcolor_source) * ( cxmul1);\n"
"}\n";

extern const char* pSource_GLSL150_FDrawableCompare;
const char* pSource_GLSL150_FDrawableCompare = 
"#version 150\n"
"uniform sampler2D tex[2];\n"
"in vec2 tc0;\n"
"in vec2 tc1;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fcolor0 = texture(tex[int(0.0)], tc0);\n"
"vec4 fcolor1 = texture(tex[int(1.0)], tc1);\n"
"vec4 diff = fcolor0 - fcolor1;\n"
"vec4 oneValue = vec4(1.0/255.0, 1.0/255.0, 1.0/255.0, 1.0/255.0 );\n"
"vec4 ltZero = (sign(diff)+vec4(1.0,1,1.0,1))*-0.25;\n"
"vec4 partDiff = oneValue * (sign(ltZero)+vec4(1.0,1,1.0,1));\n"
"vec4 wrapDiff = fract(diff + vec4(1.0,1,1.0,1)) + partDiff;\n"
"float rgbdiff = sign(dot(wrapDiff.rgb, vec3(1.0,1,1.0)));\n"
"fcolor = mix( vec4(1.0,1,1.0, wrapDiff.a), vec4(wrapDiff.rgb, 1.0), rgbdiff );\n"
"}\n";

extern const char* pSource_GLSL150_FDrawablePaletteMap;
const char* pSource_GLSL150_FDrawablePaletteMap = 
"#version 150\n"
"uniform sampler2D srctex;\n"
"uniform sampler2D tex;\n"
"in vec2 tc;\n"
"out vec4 fcolor;\n"
"void main() {\n"
"vec4 fchannels = texture(tex, tc);\n"
"fcolor  = texture(srctex, vec2(fchannels.r, 0.125));\n"
"fcolor += texture(srctex, vec2(fchannels.g, 0.375));\n"
"fcolor += texture(srctex, vec2(fchannels.b, 0.625));\n"
"fcolor += texture(srctex, vec2(fchannels.a, 0.875));\n"
"}\n";

}}}; // Scaleform::Render::GL


