/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	file_io.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 */

#ifndef __file_io__
#define __file_io__

#include <stdio.h>
#include <ansi_parms.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

extern __file_modes	__temp_file_mode;

__extern_c

int			__open_file				(const char * name, __file_modes mode, __file_handle * handle);
int			__open_temp_file	(__file_handle * handle);
int			__read_file				(__file_handle handle, unsigned char * buffer, size_t * count, __idle_proc idle_proc);
int			__write_file			(__file_handle handle, unsigned char * buffer, size_t * count, __idle_proc idle_proc);
/*int			__position_file		(__file_handle handle, long * position, int mode, __idle_proc idle_proc);*/
int			__position_file		(__file_handle handle, fpos_t * position, int mode, __idle_proc idle_proc);
int			__close_file			(__file_handle handle);
void		__temp_file_name	(char * name_str, void *);
int			__delete_file			(const char * name);
int			__rename_file			(const char * old_name, const char * new_name);

int			__get_file_modes(const char * mode, __file_modes * modes);
int         __flush_line_buffered_output_files(void);              /*mm 970702*/
__end_extern_c

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif /* __file_io__ */
/*     Change record
 *   mm 970702   Synchronization with Be
*/
