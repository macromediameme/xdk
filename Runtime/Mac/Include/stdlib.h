/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	stdlib.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */
 
#ifndef __cstdlib__
#define __cstdlib__

#include <ansi_parms.h>

__namespace(__stdc_space(stdlib))

#include <div_t.h>
#include <size_t.h>
#include <null.h>
#include <wchar_t.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

#define RAND_MAX		32767
#define MB_CUR_MAX	    1

#define EXIT_SUCCESS		0
#define EXIT_FAILURE		1

#if (__dest_os	!= __powertv_os)
#define _MAX_PATH				1024
#endif

__extern_c

double				atof(const char * str);
int					atoi(const char * str);
long				atol(const char * str);

double				strtod (const char * str, char ** end);
long				strtol (const char * str, char ** end, int base);
unsigned long		strtoul(const char * str, char ** end, int base);

#ifdef __MSL_LONGLONG_SUPPORT__               							/*mm 961219*/
long long			strtoll (const char * str, char ** end, int base);	/*mm 961219*/
unsigned long long	strtoull(const char * str, char ** end, int base);	/*mm 961219*/
#endif  /*__MSL_LONGLONG_SUPPORT__*/                      				/*mm 961220*/

int		rand (void);
void	srand(unsigned int seed);
#if __dest_os == __be_os               /* mm 970708 */
int		random (void);                 /* mm 970708 */
void	srandom(unsigned int seed);    /* mm 970708 */
#endif                                 /* mm 970708 */

void *	calloc(size_t nmemb, size_t size);
void	free(void *ptr);
void *	malloc(size_t size);
void *	realloc(void * ptr, size_t size);

void	abort(void);
int		atexit(void (*func)(void));
void	exit(int status);

char *	getenv(const char * name);
int		system(const char * command);

typedef int (*_compare_function)(const void*, const void*);                 /* mm 961031 */

void*	bsearch(const void*, const void*, size_t, size_t, _compare_function); /* mm 961031 */

void  qsort(void*, size_t, size_t, _compare_function);                      /* mm 961031 */
							
#if __POWERPC__

	#if __cplusplus && !__MOTO__ && !__MRC__
	
		inline int	abs (int n) { return(__abs(n)); }
		inline long	labs(long n){ return(__labs(n)); }
	
	#else
	
		int		abs (int n);
		long	labs(long n);
		
		#if !__MOTO__ && !__MRC__
		#define abs(n)	__abs(n)
		#define labs(n)	__labs(n)
		#endif
	
	#endif

#else

	int		abs (int n);
	long	labs(long n);

#endif

div_t		div (int numerator,  int denominator);
ldiv_t	ldiv(long numerator, long denominator);

int			mblen(const char * s, size_t n);
int			mbtowc(wchar_t * pwc, const char * s, size_t n);
int			wctomb(char * s, wchar_t wchar);
size_t	mbstowcs(wchar_t * pwcs, const char * s, size_t n);
size_t	wcstombs(char * s, const wchar_t * pwcs, size_t n);

#if (__dest_os	== __win32_os)

	/* This #ifdef block contains declarations found in the corresponding */
	/* Visual C++ ANSI header.		*/

	/* These functions are defined in extras.c */
	char * _fullpath(char * absPath, const char * relPath, size_t maxLength);
	char *_gcvt(double value, int digits, char *buffer);
	char * _itoa(int val, char *str, int radix);
	char * _ultoa(unsigned long val, char *str, int radix);
	#define _ltoa(x, y, z) _itoa(x, y, z)
	extern int _doserrno;
	#define _MAX_FNAME 256
#endif


__end_extern_c

__end_namespace(stdc_space(stdlib))

__import_stdc_into_std_space(stdlib)

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif /* __cstdlib__ */
/*     Change record
 * mm 961031  Improved legibility with introduction of typedef
 * mm 961220	line 44    Added headers for strtoll and strtoull for long long support
 * mm 970708  Inserted Be changes
 */
