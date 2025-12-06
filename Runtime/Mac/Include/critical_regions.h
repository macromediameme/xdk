/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	critical_regions.h
 *	
 *		Copyright © 1995-1997 Metrowerks, Inc.
 *		All rights reserved.
 *
 *		Notes
 *		-----
 *
 *			What we need in certain areas of the library is the ability to "lock"
 *			certain critical regions of code against reentrance by preemptive
 *			threads. For example, when fopen searches for an unused FILE struct, it
 *			would be unfortunate if another thread "found" the same struct before the
 *			first one could mark it as in-use.
 *			
 *			Because the mechanisms used to manage critical regions will vary widely
 *			depending on the underlying hardware and/or system software, *all*
 *			details about how critical regions are locked and released are kept
 *			hidden. Instead, we define a finite number of critical regions that are
 *			of interest to us and leave the details of how they are managed invisible.
 */

#ifndef __critical_regions__
#define __critical_regions__

#include <ansi_parms.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

enum critical_regions {
	atexit_funcs_access,
	malloc_pool_access,
	files_access,
	console_status_access,
	signal_funcs_access,
	num_critical_regions
};

__extern_c

void	__init_critical_regions (void);
void	__kill_critical_regions (void);

void	__begin_critical_region (int region);
void	__end_critical_region   (int region);

__end_extern_c

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif
/*     Change record
*/
