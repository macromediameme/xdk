/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	math.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */
 
#ifndef __cmath__
#define __cmath__

#include <ansi_parms.h>

#if __dest_os == __be_os
	#include <be_math.h>       /* useful constants like M_PI, etc */
#endif

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif
// AGS 22jul99 #pragma direct_destruction off

__namespace(__stdc_space(math))


/* 
 *	common function prototype declarations 
 */

/* 	float declarations */
/* 	970413 bkoz
	have been depreciated
*/
__extern_c
#ifdef __INTEL__
#define  cosf(x)       cos(x)
#define  sinf(f)       sin(f)
#define  tanf(f)       tan(f)
#define  acosf(f)      acos(f)
#define  asinf(f)      asin(f)
#define  atanf(f)      atan(f)
#define  atan2f(f,g)   atan2(f,g)
#define  coshf(f)      cosh(f)
#define  sinhf(f)      sinh(f)
#define  tanhf(f)      tanh(f)
#define  expf(f)       exp(f)
#define  frexpf(f, i)  frexp(f,i)
#define  ldexpf(f, i)  ldexp(f,i)
#define  logf(f)       log(f)
#define  log10f(f)     log10(f)
#define  fabsf(f)      fabs(f)
#define  powf(f, g)    pow(f,g)
#define  sqrtf(f)      sqrt(f)
#define  ceilf(f)      ceil(f)
#define  floorf(f)     floor(f)
#define  fmodf(f,g)    fmod(f,g)
#else
float cosf(float);
float sinf(float);
float tanf(float);
float acosf(float);
float asinf(float);
float atanf(float);
float atan2f(float,float);
float coshf(float);
float sinhf(float);
float tanhf(float);
float expf(float);
float frexpf(float, int*);
float ldexpf(float, int);
float logf(float);
float log10f(float);
float fabsf(float);
float powf(float, float);
float sqrtf(float);
float ceilf(float);
float floorf(float);
float fmodf(float, float);

#endif 
/* these are needed for performance reasons on PPC*/
/* modff  needs to be written separately 
since casting a float* to a double* isn't portable with our compilers */

float modff(float, float*);

/* double declarations */
double cos(double);
double sin(double);
double tan(double);
double acos(double);
double asin(double);
double atan(double);
double atan2(double, double);
double cosh(double);
double sinh(double);
double tanh(double);
double exp(double);
double fabs(double);
double frexp(double, int *);
double ldexp(double, int);
double log(double);
double log10(double);
double modf(double, double *);
double pow(double, double);
double sqrt(double);
double ceil(double);
double floor(double);
double fmod(double, double);
__end_extern_c


/* long double declarations */


#if __dest_os == __mac_os 	
__extern_c
long double cosl(long double);
long double sinl(long double);
long double tanl(long double);
long double acosl(long double);
long double asinl(long double);
long double atanl(long double);
long double atan2l(long double, long double);
long double coshl(long double);
long double sinhl(long double);
long double tanhl(long double);
long double expl(long double);
long double frexpl(long double, int *);
long double ldexpl(long double, int);
long double logl(long double);
long double log10l(long double);
long double modfl(long double, long double *);
long double fabsl(long double);
long double powl(long double, long double);
long double sqrtl(long double);
long double ceill(long double);
long double floorl(long double);
long double fmodl(long double, long double);
__end_extern_c
#endif 


/* 970411 bkoz
 * eventually will need this logic for all platforms at this place, right now only 68K
 * has distinct double and long double types (and only when not using 68881)
 */
/*
 
	#ifdef __cplusplus
		inline long double cos(long double x)		{ return ( cosl(x));}
	#else
		#define cos(x)  ( (sizeof(x) == sizeof(double)) ? cos(x) : cosl(x) );
	#endif

 */
 __extern_c 
long __double_huge[];
long __extended_huge[] ; /* used by HUGE_VALL in C9X section */

#ifndef __FP__  /* avoid conflict with fp.h */

 #if __MC68K__ 
  #if!(__option(IEEEdoubles))
 
   #define      HUGE_VAL   (*(double*)__std(__extended_huge))
  #else
   #define      HUGE_VAL   (*(double*)__std(__double_huge))
  #endif /*__option(IEEEdoubles)*/
 #else

  #define      HUGE_VAL   (*(double*)       __std(__double_huge))
  
 #endif /* __MC68K__  */


#endif /* __FP__ */
__end_extern_c
/*
 * 	x86 specific functionality
 */
#if	__INTEL__
	/* isnan and isfinite are approved extensions to the ANSI C standard and are in
	 * the current draft standard.  They are now included in the extended Intel math
	 * library (fpce.obj).  mf-- 10/02/97
	 */
	 
	 /* 970411 bkoz
	  * isnan is now defined in the C9X portion of this file also. . .
	  */
	  
__extern_c

	int isnan (double);
	int isfinite(double);
	#define __isnan(x) isnan(x)
	#define __isfinite(x) isfinite(x)
__end_extern_c
	
	
#endif /* __INTEL__ */


/*
 * 	PPC specific functionality
 */	
#if __POWERPC__
	#define fabs(x)			__fabs(x)
#endif	/* __POWERPC__ */


/*
 * 	68K specific functionality
 */	
#if __MC68K__
/* you get the "d" suffixed functions on 68K no matter what.  
   HOWEVER, our suggestion is to NOT use these functions
   as they are unique to the version of the 68k math libraries that is supplied to us by Apple.
   The "d" suffixed functions are not part of any C standard including the C draft standard.
   If you want your code to run anywhere besides 68K using SANE, use the unsuffixed STANDARD
   math functions instead (eg. cos instead of cosd ).
*/
__extern_c

    double cosd(double);
	double sind(double);
	double tand(double);
	double acosd(double);
	double asind(double);
	double atand(double);
	double coshd(double);
	double sinhd(double);
	double tanhd(double);
	double expd(double);
	double ldexpd(double, int);
	double logd(double);
	double log10d(double);
	double fabsd(double);
	double sqrtd(double);
	double fmodd(double, double);
	double atan2d(double, double);
	double frexpd(double, int *);
	double modfd(double, double *);
	double powd(double, double);
	double ceild(double);
	double floord(double);
	
__end_extern_c


/*	68K math support is a bit confusing, so this is a small map of the defines herein:

	#if __MC68k__
		#if !defined(_INLINE_FPU_CALLS_)
			#define _INLINE_FPU_CALLS_	0
		#endif

		#if _INLINE_FPU_CALLS_ && __MC68881__
			 
		#elif __option(IEEEdoubles)
			
		#else	
		#endif

	#endif	
*/

/*
 *  Set the following define to 1 to force the ANSI math header to inline FPU
 *	calls whenever possible.  This behaviour is not ANSI compatible, so should
 *	be used with care.
 *	
 */
 
#if !defined(_INLINE_FPU_CALLS_)
	#define _INLINE_FPU_CALLS_	0
#endif

/*	From the above diagram, it is assumed that 
 *
 * 	#if _INLINE_FPU_CALLS_ && __MC68881__ && __option(IEEEdoubles)
 *	
 *	will lead to inconsistencies, ie. using inlines in conjunction with 8byte 
 *	doubles will not work correctly. (Pick any two) Therefore, check for this error now:
 */

#if _INLINE_FPU_CALLS_ && __MC68881__ && __option(IEEEdoubles)
#error	cannot_have_68881_and_inlinies_and_8-byte_doubles
#endif
		
#if _INLINE_FPU_CALLS_ && __MC68881__
	/* call the FPU directly (NOT ANSI COMPATIBLE) */
	long double _fpucos(long double:__FP0):__FP0                    = { 0xF200,0x001D };
	long double _fpusin(long double:__FP0):__FP0                    = { 0xF200,0x000E };
	long double _fputan(long double:__FP0):__FP0                    = { 0xF200,0x000F };
	long double _fpuacos(long double:__FP0):__FP0                   = { 0xF200,0x001C };
	long double _fpuasin(long double:__FP0):__FP0                   = { 0xF200,0x000C };
	long double _fpuatan(long double:__FP0):__FP0                   = { 0xF200,0x000A };
	long double _fpucosh(long double:__FP0):__FP0                   = { 0xF200,0x0019 };
	long double _fpusinh(long double:__FP0):__FP0                   = { 0xF200,0x0002 };
	long double _fputanh(long double:__FP0):__FP0                   = { 0xF200,0x0009 };
	long double _fpuexp(long double:__FP0):__FP0                    = { 0xF200,0x0010 };
	long double _fpuldexp(long double:__FP0,long:__D0):__FP0        = { 0xF200,0x4026 };
	long double _fpulog(long double:__FP0):__FP0                    = { 0xF200,0x0014 };
	long double _fpulog10(long double:__FP0):__FP0                  = { 0xF200,0x0015 };
	long double _fpufabs(long double:__FP0):__FP0                   = { 0xF200,0x0018 };
	long double _fpusqrt(long double:__FP0):__FP0                   = { 0xF200,0x0004 };
	long double _fpufmod(long double:__FP0,long double:__FP1):__FP0 = { 0xF200,0x0421 };

/* note APPLE numerics is NOT ANSI C standard. 
 six of the basic ANSI math functions(atan2,frexpd,
 modf,pow,ceil,floor) do not have FPU Inlines
*/	                                     
	
		#define cos(x)				_fpucos(x)
		#define sin(x)				_fpusin(x)
		#define tan(x)				_fputan(x)
		#define acos(x)				_fpuacos(x)
		#define asin(x)				_fpuasin(x)
		#define atan(x)				_fpuatan(x)
		#define cosh(x)				_fpucosh(x)
		#define sinh(x)				_fpusinh(x)
		#define tanh(x)				_fputanh(x)
		#define exp(x)				_fpuexp(x)
		#define ldexp(x,n)			_fpuldexp(x,n)
		#define log(x)				_fpulog(x)
		#define log10(x)			_fpulog10(x)
		#define fabs(x)				_fpufabs(x)
		#define sqrt(x)				_fpusqrt(x)
		#define fmod(x,y)			_fpufmod(x,y)
		
#elif __option(IEEEdoubles)
	
	
		#define cos(x)  	cosd(x)
		#define sin(x)		sind(x)
		#define tan(x)		tand(x)
		#define acos(x)		acosd(x)
		#define asin(x)		asind(x)
		#define atan(x)		atand(x)
		#define cosh(x)		coshd(x)
		#define sinh(x)		sinhd(x)
		#define tanh(x)		tanhd(x)
		#define exp(x)		expd(x)
		#define ldexp(x,n)	ldexpd(x,n)
		#define log(x)		logd(x)
		#define log10(x)	log10d(x)
		#define fabs(x)		fabsd(x)
		#define sqrt(x)		sqrtd(x)
		#define fmod(x,y)	fmodd(x,y)
		
#endif
		#define atan2(x,y)	atan2d(x,y)
		#define frexp(x,y)	frexpd(x,y)
		#define modf(x,y)	modfd(x,y)
		#define pow(x,y)	powd(x,y)
		#define ceil(x)		ceild(x)
		#define floor(x)	floord(x)

#endif	/* __MC68K__ */

__end_namespace(stdc_space(math))

__import_stdc_into_std_space(math)


	/*
	 * FLT_EVAL_METHOD
	 * 
	 * (eventually move into float.h)
	 *
	 *	pick only one method!!
	 */	
	/*#define FLT_EVAL_METHOD 	-1	*/
	/*indeterminable*/
	
	/*#define FLT_EVAL_METHOD		0	*/
	/*	evaluate operations and constants of
	 * 	float 		in 	float
	 * 	double 		in 	double
	 * 	long double in 	long double
	 */
	
	/*#define FLT_EVAL_METHOD		1	*/
	/* evaluate operations and constants of 
	 * float 		in 	double
	 * double 		in 	double
	 * long double 	in 	long double
	 */
	
	/*#define FLT_EVAL_METHOD		2	*/
	/* evaluate operations and constants of 
	 * float 		in 	long double
	 * double 		in 	long double
	 * long double 	in 	long double
	 */
#ifndef __FP__ /* MacOs Support/Headers/Universal Headers/fp.h 
                     also defines efficiency types
                     we recommend NOT using fp.h to do
                     this if you want your code to be
                     portable outside the MAC environment.
                     The draft standard specifies
                     double_t and float_t be introduced in math.h.
                     fp.h is a MAC specific header.
                     */
                  
    
	#ifndef __MC68K__
    	#define FLT_EVAL_METHOD		0	
	#else
	   #define  FLT_EVAL_METHOD		2
	#endif

	
	/*
	 * 7.x
	 * FLOAT_T
	 * DOUBLE_T
	 */	
	#if	(FLT_EVAL_METHOD == 0)
	
		typedef float float_t;
		typedef double double_t;
		
	#elif (FLT_EVAL_METHOD == 1)
	
		typedef double float_t;
		typedef double double_t;
		
	#elif (FLT_EVAL_METHOD == 2)
	
		typedef long double float_t;
		typedef long double double_t;	
	
	#endif
#endif /* __FP__ */	



/* 
 * 	970410 b.kosnik(bkoz)/m.fassiotto
 *
  	
 	If you are currently using fp.h on the Macintosh, try defining
    __MSL_C9X__ below and using this header instead as an all-inclusive header.
 
 	NB: most of this functionality will not work on __INTEL__!! (scalb, logb,hypot,
    isnan, isfinite, rint, round  only)
 
 	For more info on C9X, try getting these documents:
 	ftp://ftp.dmk.com/DMK/sc22wg14/c9x/floating-point/floating-point.txt.gz
 	ftp://ftp.dmk.com/DMK/sc22wg14/c9x/floating-point/fp_edits.txt.gz
 *
 *
 */
 

/* 092897  mf--MSL on all platforms defines __MSL_C9X__ by default and no longer
               uses mac specific headers such as fp.h and types.h.  This define
               is in the stock prefix files. Comment the line "#define __MSL_C9X__"
               out of the prefix file if you want your project to continue using 
               the prototypes and macros below from the non-standard, mac specific 
               header fp.h.
*/

#ifndef __FP__
	
	#ifndef __STDC_IEC_559__
	#define __STDC_IEC_559__

	__extern_c
	/*
	 * 7.x
	 * float_huge
	 * HUGE_VALL
	 * INFINITY
	 * NAN
	 * FP_NAN
	 * FP_INFINITE
	 * FP_NORMAL
	 * FP_SUBNORMAL
	 * FP_ZERO
	 * 
	 */	
	/*
	#define      float_huge					??
	#define      HUGE_VALL					??
	*/
long __float_huge[];
long __float_nan[];
#define	     HUGE_VALF  (*(float*)  	__std(__float_huge))
#define	     HUGE_VALL  (*(double_t*)   __std(__extended_huge))
#define      INFINITY   (*(float_t*)	__std(__float_huge))               	
#define      NAN	    (*(float_t*)    __std(__float_nan))
	
	/*
	#define      FP_NAN						??
	#define      FP_INFINITE				??
	#define      FP_NORMAL					??
	#define      FP_SUBNORMAL				??
	#define      FP_ZERO					??
	*/
	
	#if __MC68K__
		#define    DECIMAL_DIG				21
	#else
		#define    DECIMAL_DIG				17   /*970423 bkoz ->fassiotto is this ok?*/
												 /* 970928  yes, now it's o.k. */
	#endif      


	/*
	 * 7.x.1
	 * FP_CONTRACT_ON
	 * FP_CONTRACT_OFF
	 * FP_CONTRACT_DEFAULT
	 */
	

	/*
	 * 7.x.2.1
	 * CLASSIFICATION MACROS
	 * 
	 * fpclassify
	 * signbit
	 * isfinite
	 * isnormal
	 * isnan
	 */
	#if __dest_os == __mac_os /*need to match Apple numerics*/
		long int __fpclassify  ( long double x ); 
		long int __fpclassifyd ( double x );
		long int __fpclassifyf ( float x );
		long int __signbit  ( long double x );
		long int __signbitd ( double x );
		long int __signbitf ( float x );
		long int __isfinite  ( long double x );
		long int __isfinited ( double x );
		long int __isfinitef ( float x );
		long int __isnormal  ( long double x );
		long int __isnormald ( double x );
		long int __isnormalf ( float x );
		long int __isnan  ( long double x );
		long int __isnand ( double x );
		long int __isnanf ( float x );
	#else /*follow standard*/
		int __fpclassify  ( long double x ); 
		int __fpclassifyd ( double x );
		int __fpclassifyf ( float x );
		int __signbit  ( long double x );
		int __signbitd ( double x );
		int __signbitf ( float x );
#ifndef __INTEL__  /* contraction works on INTEL so we don't need these */
		int __isfinite  ( long double x );
		int __isfinited ( double x );
		int __isfinitef ( float x );
		int __isnan  ( long double x );
		int __isnand ( double x );
		int __isnanf ( float x );
#endif
		int __isnormal  ( long double x );
		int __isnormald ( double x );
		int __isnormalf ( float x );
		
	#endif	

	#define fpclassify(x)  (sizeof(x) == sizeof(float)) ? __fpclassifyf(x) \
		: (sizeof(x) == sizeof(double)) ? __fpclassifyd(x) \
		: __fpclassify(x) 
	
	#define signbit(x)  (sizeof(x) == sizeof(float)) ? __signbitf(x) \
		: (sizeof(x) == sizeof(double)) ? __signbitd(x) \
		: __signbit(x) 

	#define isnormal(x)  (sizeof(x) == sizeof(float)) ? __isnormalf(x) \
		: (sizeof(x) == sizeof(double)) ? __isnormald(x) \
		: __isnormal(x) 
	
	
	#ifndef __INTEL__
		#define isfinite(x)  (sizeof(x) == sizeof(float)) ? __isfinitef(x) \
			: (sizeof(x) == sizeof(double)) ? __isfinited(x) \
			: __isfinite(x) 

		#define isnan(x)  (sizeof(x) == sizeof(float)) ? __isnanf(x) \
			: (sizeof(x) == sizeof(double)) ? __isnand(x) \
			: __isnan(x)
   #endif			 

	/*
	 * 7.x.5.1
	 * ACOSH
	 * 
	 * computes the (nonnegative) arc hyperbolic cosine of x in the range [0, +INF]
	 * a domain error occurs for arguments less than 1
	 * a range error occurs if x is too large
	 */
	 double_t acosh ( double_t x ); 
	

	/*
	 * 7.x.5.2
	 * ASINH
	 * 
	 * computes the arc hyperbolic sine of x 
	 * a range error occurs if the magnitude of x is too large
	 */
    double_t asinh ( double_t x ); 
	
	
	/*
	 * 7.x.5.3
	 * ATANH
	 * 
	 * computes the arc hyperbolic tangent of x 
	 * a domain error occurs for arguments not in the range [-1,+1]
	 */
	 double_t atanh ( double_t x ); 


	/*
	 * 7.x.6.2
	 * EXP2
	 * 
	 * computes the base-2 exponential of x: 2^x
	 * a range error occurs if the magnitude of x is too large
	 */
	double_t exp2  ( double_t x );
	
	/*
	 * 7.x.5.2
	 * EXPM1
	 * 
	 * computes the base-e exponential of x, minus 1: (e^x) -1
	 * for small magnitude x, expm1(x) is expected to be more accurate than exp(x) -1
	 * a range error occurs if x is too large
	 */
	double_t expm1  ( double_t x );
	
	/*
	 * 7.x.5.3
	 * LOG1P
	 * 
	 * computes the base-e logarithm of 1 plus x
	 * for small magnitude x, log1p(x) is expected to be more accurate than log(x+1)
	 * a domain error occurs if x < -1
	 * a range error may occur if x == 1
	 */
	double_t log1p ( double_t x );

	/*
	 * 7.x.6.9
	 * LOG2
	 * 
	 * computes the base-2 logrithm of x
	 * a domain error may occur if x < 0
	 * a range error may occur if x == 0
	 */
	double_t log2 ( double_t x );
	
	/*
	 * 7.x.6.10
	 * LOGB
	 * 
	 * extracts the exponent of x as a signed integral value in the format of x
	 * if x is subnormal it is treated as though it were normalized
	 * a range error may occur if x == 0
	 */
	double_t logb ( double_t x );
	
	/*
	 * 7.x.6.12
	 * SCALB
	 * 
	 * computes x * FLT_RADIX^n efficiently, not normally by computing FLT_RADIX^n explicitly
	 * a range error may occur 
	 */
	double_t scalb ( double_t x, long int n ); 

	/*
	 * 7.x.7.2
	 * HYPOT
	 * 
	 * computes the square root of the sum of the squares of x and y
	 * without undue overflow or underflow
	 * a range error may occur
	 */
	double_t hypot ( double_t x, double_t y );
	
	/*
	 * 7.x.8.1
	 * ERF
	 * 
	 * computes the error function of x
	 */
	double_t erf  ( double_t x );	
	
	/*
	 * 7.x.8.2
	 * ERFC
	 * 
	 * computes the complementary error function of x
	 */
	double_t erfc ( double_t x );

	/*
	 * 7.x.8.3
	 * GAMMA
	 * 
	 * computes the gamma function of x
	 * a domain error occurs if x == 0 || x == negative integer
	 * a range error may occur 
	 */
	double_t gamma ( double_t x );
	
	/*
	 * 7.x.8.4
	 * LGAMMA
	 * 
	 * computes the log of the absolute value of gamma of x
	 * a range error occurs if x is too large 
	 */
	double_t lgamma ( double_t x );

	/*
	 * 7.x.9
	 * NEARBYINT
	 * 
	 * computes like rint but doesn't raise inexact exception
	 */
	double_t nearbyint ( double_t x );

	/*
	 * 7.x.9.4
	 * RINT
	 * 
	 * rounds its argument to an integral value in floating-point format
	 * using the current rounding direction
	 */
	double_t rint ( double_t x );

	/*
	 * 7.x.9.5
	 * RINTTOL
	 * 
	 * rounds its argument to the nearest integral value 
	 * using the current rounding direction
	 * if the rounded range is outside the range of long, result is unspecified
	 */
	long int rinttol ( double_t x );

	/*
	 * 7.x.9.6
	 * ROUND
	 * 
	 * rounds its argument to an integral value in floating-point format
	 * rounding halfway cases away from zero, regardless of the current rounding direction
	 */
	double_t round ( double_t x );

	/*
	 * 7.x.9.7
	 * ROUNDTOL
	 * 
	 * rounds its argument to the nearest integral value 
	 * rounding halfway cases away from zero, regardless of the current rounding direction
	 * if the rounded range is outside the range of long, result is unspecified
	 */
	long int roundtol ( double_t round );

	/*
	 * 7.x.9.9
	 * TRUNC
	 * 
	 * rounds its argument to an integral value in floating-point format
	 * nearest to but no larger in magnitude than the argument
	 */
	#if __MC68K__
		int      trunc ( double_t x );  
	#else
		double_t trunc ( double_t x );
	#endif

	/*
	 * 7.x.10
	 * REMAINDER
	 * 
	 * computes the remainder x REM y required by IEC 559
	 */
	double_t remainder ( double_t x, double_t y );

	/*
	 * 7.x.10.3
	 * REMAINDER
	 * 
	 * computes the remainder x REM y required by IEC 559
	 */
	double_t remquo    ( double_t x, double_t y, int *quo );

	/*
	 * 7.x.11
	 * COPYSIGN
	 * 
	 * produces a value withthe magnitude of x and the sign of y
	 */
	double_t copysign ( double_t x, double_t y );

	/*
	 * 7.x.11.2
	 * NAN
	 * 
	 * returns a quiet NAN if available
	 */
	double      nan  ( const char *tagp );

	/*
	 * 7.x.11.3
	 * NEXTAFTER
	 * 
	 * determines the next representable value,in the type of the function
	 * after x in the direction of y, where x and y are first converted to the
	 * type of the function
	 */
	#if __dest_os == __mac_os /*need to match Apple numerics*/
		long double nextafterl ( long double x, long double y );
		double      nextafterd ( double x, double y );
		float       nextafterf ( float x, float y );
		#define nextafter(x,y) ( (sizeof(x) == sizeof(float)) ? nextafterf(x,y) \
			: (sizeof(x) == sizeof(double)) ? nextafterd(x,y) \
			: nextafterl(x,y) )
	#else /*follow standard, and naming convention of above*/
		long double __nextafter  ( long double x, long double y );
		double      __nextafterd ( double x, double y );
		float       __nextafterf ( float x, float y );
		#define nextafter(x,y) ( (sizeof(x) == sizeof(float)) ? __nextafterf(x,y) \
			: (sizeof(x) == sizeof(double)) ? __nextafterd(x,y) \
			: __nextafter(x,y)	)
	#endif


	/*
	 * 7.x.12.1
	 * FDIM
	 * 
	 * computes the positive difference of its arguments
	 * x - y 	if	 	x > y
	 * +0 		if 		x <= y
	 * a range error may occur
	 */
	double_t fdim ( double_t x, double_t y );

	/*
	 * 7.x.12.2
	 * FMAX
	 * 
	 * computes the maximum numeric value of its arguments
	 */
	double_t fmax ( double_t x, double_t y );

	/*
	 * 7.x.12.3
	 * FMIN
	 * 
	 * computes the minimum numeric value of its arguments
	 */
	double_t fmin ( double_t x, double_t y );
	__end_extern_c
	#endif  /*__STDC_IEC_559__*/

#endif /*__FP__*/

// AGS 22jul99 #pragma direct_destruction reset
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif /*__cmath__*/

/*     Change record
mm-960722       Inserted declaration for pi
mm-9607225  	Added declaration for pi for Infinity Marathon.
mm-961008       Removed declaration for pi since it does not conform to the ANSI C Standard
bk-961221		line 121 wrapped fabs intrinsic (mmoss)
bk 961223 		line 24 wrapped HUGE_VAL define
bk 970318		restructured for 68K, PPC, x86 to reduce confusion
bk 970410		restructured more to reduce 68K mess, started to add C9X support
bk 970411		added long double support for PPC cplus plus, 68K cplus plus and c
bk 970415		68K changes
bk 970423		c++ long double overrides replaced with casts to double versions
mf 970902       took out all c++ inlines for math functions on all platforms. They don't do 
                anything!  Still have fpu inlines on 68k with either C or C++ .
mf 970915       corrected a bug that defines regular math functions to the "d" suffixed 
                macros on 68K.  They should only be defined for 8 byte doubles
mf 970916		moved __extern_c to surround long __double_huge[]                
mf 970928       define efficiency types double_t, float_t by default(used to require
                __MSL_C9X__ to be defined).
mf 971005       updated math.h to be compatible with 3.0.1 universal headers. Removed
                __MSL_C9X__ altogether.                
*/
