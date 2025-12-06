/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	arith.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */
 
#ifndef __arith__
#define __arith__

#include <ansi_parms.h>
#include <div_t.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

__extern_c

int			__add (int  * x, int  y);
int			__ladd(long * x, long y);

int			__mul (int  * x, int  y);
int			__lmul(long * x, long y);

div_t		__div (int  x, int  y);
ldiv_t	__ldiv(long x, long y);

#ifndef __MOTO__
int			__mod (int  x, int  y);
long		__lmod(long x, long y);
#endif

__end_extern_c

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif
/*     Change record
961221 bkoz lien 30 added mmoss's change
*/
