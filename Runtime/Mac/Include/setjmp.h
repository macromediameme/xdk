/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	File:				setjmp.h
 *							©1993-1997 metrowerks Inc. All rights reserved
 *	Author:			Andreas Hommel
 *
 *	Content:		Interface to setjmp/longjmp ANSI functions ...
 */

#ifndef __csetjmp__
#define __csetjmp__

#include <ansi_parms.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif
// AGS 22jul99 #pragma direct_destruction off

__namespace(__stdc_space(setjmp))

__extern_c	/* 960917 */

#if __dest_os == __powertv_os

	typedef long *jmp_buf[64];

#elif __POWERPC__

	typedef long *jmp_buf[70];
	
	#define setjmp(jmp_buf)	__setjmp(jmp_buf)

#elif	__INTEL__

	typedef int jmp_buf[10];
	
	#define setjmp(jmp_buf) _Setjmp(jmp_buf)
	int _Setjmp(jmp_buf);
	
#else

	typedef long *jmp_buf[13];			/*	D3-D7,PC,A2-A6,SP,__local_destructor_chain */

#endif

#if __dest_os == __powertv_os

	int		setjmp(jmp_buf);
	
#elif __POWERPC__

#ifndef __SETJMP_NOT_INTERNAL__
#pragma internal on
#endif

	int		__setjmp(jmp_buf);

#ifndef __SETJMP_NOT_INTERNAL__
#pragma internal reset
#endif

	void	longjmp (jmp_buf,int);

#elif __CFM68K__

#ifndef __SETJMP_NOT_INTERNAL__
#pragma internal on
#endif

	int		setjmp(jmp_buf);

#ifndef __SETJMP_NOT_INTERNAL__
#pragma internal reset
#endif

	void	longjmp(jmp_buf,int);

#else

	int		setjmp (jmp_buf);
	void	longjmp(jmp_buf,int);

#endif

void __longjmp_ldestr(jmp_buf,int);

__end_extern_c

#if __dest_os == __be_os
	typedef long *sigjmp_buf[(sizeof(jmp_buf)/sizeof(int)) + (32*4)];      /* mm 970708 */

	int  sigsetjmp(sigjmp_buf jmp, int savemask);                          /* mm 970708 */
    void siglongjmp(sigjmp_buf jmp, int val);                              /* mm 970708 */

#endif

__end_namespace(stdc_space(setjmp))

__import_stdc_into_std_space(setjmp)

// AGS 22jul99 #pragma direct_destruction reset
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif

/*     Change record
 * 960829 bkoz added l.you's changes for powerTV

 * 960917 KO: Moved the __extern_c block up here so it now encloses
           the Intel function declaration.
 * mm 970708  Inserted Be changes
 */
