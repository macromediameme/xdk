/*
	$Workfile: MOATRY.H $
	$Archive: /Xtras/Include/MOATRY.H $
	$Author: Greggy $
	$Date: 6/23/99 11:55 AM $
	$Revision: 2 $

	Copyright (c) 1994, 1995, 1996, 1997 Macromedia, Inc.	All Rights Reserved

	You may utilize this source file to create and compile object code for use within products
	you may create. THIS CODE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, AND
	MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.	IN NO EVENT WILL MACROMEDIA BE
	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR
	USE OR INABILITY TO USE THIS CODE.
	
	960703	Added a trick (__bad_throw_location) to find problems with Throwing from
			after the moa_catch clause. this can cause an infinite loop! so,
			when compiling in debug mode, we pull some trickery to generate a compile
			error if you try this (it doesn't happen when compiling in nondebug mode).
			(srj)
	
*/

#ifndef _H_moatry
#define _H_moatry

#ifndef _H_moatypes
	#include "moatypes.h"
#endif

/* #define MOATRY_DEBUG */

/* ------------------------------------------------------------------------ */

#define _moa_val(x) #x
#define _moa_str(x) _moa_val(x)

#ifdef MOATRY_DEBUG
	#define _moa_try_debug \
		ConstPMoaChar __throwloc = "";

	#define _moa_throw_debug \
		__throwloc = __FILE__ ":" _moa_str(__LINE__);

	#define moa_get_exception_location	(__throwloc)
#else
	#define _moa_try_debug
	#define _moa_throw_debug
	#define moa_get_exception_location	("")
#endif

#ifndef moa_report_exception
	#define moa_report_exception
#endif

/* ------------------------------------------------------------------------ */

#define Throw(x)		do { __err = (MoaError)(x); _moa_throw_debug; MOA_ASSERT(__bad_throw_location == (PMoaVoid)0, "Bad Throw Location!"); goto __failure; } while (0)

#define ThrowErr(x) 	do { MoaError __temperr = (MoaError)(x); if (__temperr) Throw(__temperr); } while (0)

#define ThrowFailed(x)	do { MoaError __temperr = (MoaError)(x); if FAILED(__temperr) Throw(__temperr); } while (0)

#define ThrowNull(x)	do { if (!(x)) Throw(kMoaErr_OutOfMem); } while (0)

/* ------------------------------------------------------------------------ */

#define moa_get_exception		(__err)

#define moa_set_exception(e)	do { __err = (e); } while (0)

#define moa_try \
			{ \
			X_ENTER \
			MoaError __err = kMoaErr_NoErr; \
			const PMoaVoid __bad_throw_location = (PMoaVoid)0; \
			_moa_try_debug 

#define moa_catch \
			if (0) { \
			goto __failure; /* just to prevent an "unused label" warning */ \
			__failure:; \
			moa_report_exception \
			{ \
			const MoaLong __bad_throw_location = 0; 

#define moa_catch_end	\
			} } { \
			const MoaLong __bad_throw_location = 0; 

#define moa_try_end \
			} \
			X_STD_RETURN(__err); \
			X_EXIT \
			}

#define moa_try_end_void \
			} \
			X_RETURN_VOID; \
			X_EXIT \
			}

#define moa_try_end_(type, value) \
			} \
			X_RETURN(type, value); \
			X_EXIT \
			}

#endif
