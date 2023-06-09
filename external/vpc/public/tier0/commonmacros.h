// Copyright Valve Corporation, All rights reserved.
//
// This should contain ONLY general purpose macros that are
// appropriate for use in engine/launcher/all tools

#ifndef VPC_TIER0_COMMONMACROS_H_
#define VPC_TIER0_COMMONMACROS_H_

// Makes a 4-byte "packed ID" int out of 4 characters
#define MAKEID(d, c, b, a) \
  (((int)(a) << 24) | ((int)(b) << 16) | ((int)(c) << 8) | ((int)(d)))

// Compares a string with a 4-byte packed ID constant
#define STRING_MATCHES_ID(p, id) ((*((int *)(p)) == (id)) ? true : false)
#define ID_TO_STRING(id, p)                                        \
  ((p)[3] = (((id) >> 24) & 0xFF), (p)[2] = (((id) >> 16) & 0xFF), \
   (p)[1] = (((id) >> 8) & 0xFF), (p)[0] = (((id) >> 0) & 0xFF))

#define V_ARRAYSIZE(p) (sizeof(p) / sizeof(p[0]))

#define SETBITS(iBitVector, bits) ((iBitVector) |= (bits))
#define CLEARBITS(iBitVector, bits) ((iBitVector) &= ~(bits))
#define FBitSet(iBitVector, bits) ((iBitVector) & (bits))

inline bool IsPowerOfTwo(int value) { return (value & (value - 1)) == 0; }

#ifndef REFERENCE
#define REFERENCE(arg) ((void)arg)
#endif

// Wraps the integer in quotes, allowing us to form constant strings with
// it
#define CONST_INTEGER_AS_STRING(x) #x
//__LINE__ can only be converted to an actual number by going through
// this, otherwise the output is literally "__LINE__"
#define __HACK_LINE_AS_STRING__(x) CONST_INTEGER_AS_STRING(x)
// Gives you the line number in constant string form
#define __LINE__AS_STRING __HACK_LINE_AS_STRING__(__LINE__)

// Using ARRAYSIZE implementation from winnt.h:
#ifdef ARRAYSIZE
#undef ARRAYSIZE
#endif

#ifdef _ARRAYSIZE
#undef _ARRAYSIZE
#endif

#if defined(__cplusplus) && !defined(MIDL_PASS) && !defined(RC_INVOKED) && \
    !defined(_PREFAST_) && (_MSC_FULL_VER >= 13009466) &&                  \
    !defined(SORTPP_PASS)

// From crtdefs.h
#if !defined(UNALIGNED)
#if defined(_M_IA64) || defined(_M_AMD64)
#define UNALIGNED __unaligned
#else
#define UNALIGNED
#endif
#endif

// RtlpNumberOf is a function that takes a reference to an array of N Ts.
//
// typedef T array_of_T[N];
// typedef array_of_T &reference_to_array_of_T;
//
// RtlpNumberOf returns a pointer to an array of N chars.
// We could return a reference instead of a pointer but older compilers do not
// accept that.
//
// typedef char array_of_char[N];
// typedef array_of_char *pointer_to_array_of_char;
//
// sizeof(array_of_char) == N
// sizeof(*pointer_to_array_of_char) == N
//
// pointer_to_array_of_char RtlpNumberOf(reference_to_array_of_T);
//
// We never even call RtlpNumberOf, we just take the size of dereferencing its
// return type. We do not even implement RtlpNumberOf, we just decare it.
//
// Attempts to pass pointers instead of arrays to this macro result in compile
// time errors. That is the point.
extern "C++" template <typename T, size_t N>
char (*RtlpNumberOf(UNALIGNED T (&)[N]))[N];

// ARRAYSIZE is more readable version
// _ARRAYSIZE is a version useful for anonymous types
#define ARRAYSIZE(A) (sizeof(*RtlpNumberOf(A)))
#define _ARRAYSIZE(A) (sizeof(A) / sizeof((A)[0]))

#endif

#endif  // VPC_TIER0_COMMONMACROS_H_
