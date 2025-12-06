/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	buffer_io.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */

#ifndef __buffer_io__
#define __buffer_io__

#include <stdio.h>
#include <ansi_parms.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

enum {
	__align_buffer,
	__dont_align_buffer
};

__extern_c

void __convert_from_newlines(unsigned char * p, size_t * n);
void __convert_to_newlines  (unsigned char * p, size_t * n);

void	__prep_buffer (FILE * file);	
int		__load_buffer (FILE * file, size_t * bytes_loaded, int alignment);
int		__flush_buffer(FILE * file, size_t * bytes_flushed);

__end_extern_c

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif
/*     Change record
*/
