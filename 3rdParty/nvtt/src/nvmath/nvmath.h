// This code is in the public domain -- castanyo@yahoo.es

#ifndef NV_MATH_H
#define NV_MATH_H

#include <nvcore/nvcore.h>
#include <nvcore/Debug.h>

#include <math.h>

// Function linkage
#if NVMATH_SHARED
#ifdef NVMATH_EXPORTS
#define NVMATH_API DLL_EXPORT
#define NVMATH_CLASS DLL_EXPORT_CLASS
#else
#define NVMATH_API DLL_IMPORT
#define NVMATH_CLASS DLL_IMPORT
#endif
#else // NVMATH_SHARED
#define NVMATH_API
#define NVMATH_CLASS
#endif // NVMATH_SHARED

#ifndef PI
#define PI      			float(3.1415926535897932384626433833)
#endif

#define NV_EPSILON			(0.0001f)
#define NV_NORMAL_EPSILON	(0.001f)

/*
#define SQ(r)				((r)*(r))

#define	SIGN_BITMASK		0x80000000

/// Integer representation of a floating-point value.
#define IR(x)					((uint32 &)(x))

/// Absolute integer representation of a floating-point value
#define AIR(x)					(IR(x) & 0x7fffffff)

/// Floating-point representation of an integer value.
#define FR(x)					((float&)(x))

/// Integer-based comparison of a floating point value.
/// Don't use it blindly, it can be faster or slower than the FPU comparison, depends on the context.
#define IS_NEGATIVE_FLOAT(x)	(IR(x)&SIGN_BITMASK)
*/

#if NV_OS_WIN32
#include <float.h>
#endif

namespace nv
{
inline float toRadian(float degree) { return degree * (PI / 180.0f); }
inline float toDegree(float radian) { return radian * (180.0f / PI); }
	
inline bool equal(const float f0, const float f1, const float epsilon = NV_EPSILON)
{
	return fabs(f0-f1) <= epsilon;
}

inline bool isZero(const float f, const float epsilon = NV_EPSILON)
{
	return fabs(f) <= epsilon;
}

inline bool isFinite(const float f)
{
#if NV_OS_WIN32
	return _finite(f) != 0;
#elif NV_OS_DARWIN
	return isfinite(f);
#elif NV_OS_LINUX
	return finitef(f);
#else
#	error "isFinite not supported"
#endif
//return std::isfinite (f);
//return finite (f);
}

inline bool isNan(const float f)
{
#if NV_OS_WIN32
	return _isnan(f) != 0;
#elif NV_OS_DARWIN
	return isnan(f);
#elif NV_OS_LINUX
	return isnanf(f);
#else
#	error "isNan not supported"
#endif
}

inline uint log2(uint i)
{
	uint value = 0;
	while( i >>= 1 ) {
		value++;
	}
	return value;
}

inline float lerp(float f0, float f1, float t)
{
	const float s = 1.0f - t;
	return f0 * s + f1 * t;
}

} // nv

#endif // NV_MATH_H
