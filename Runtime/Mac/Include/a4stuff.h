/*
 *	File:		A4Stuff.h
 *				©1993-1995 metrowerks Inc. All rights reserved
 *
 *	Content:	CodeResource / DRVR / DA support functions
 *
 *	2 macros have been added to help with setting up the global
 *	world for code resources.  They are platform (68K and PPC) safe.
 *	Call EnterCodeResource() when you first enter a code resource that 
 *	accesses globals or strings.  Call ExitCodeResource() when you are 
 *	ready to leave the code resource.  Please see SetupA4.h for similiar
 *	functions to be used by callbacks in code resources.
 */

#ifndef __A4STUFF__
#define __A4STUFF__

#include <Devices.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef powerc

	#define EnterCodeResource() long oldA4 = SetCurrentA4()
	#define ExitCodeResource() SetA4(oldA4)
	long SetCurrentA4(void);
	long SetA4(long:__D0):__D0 = 0xC18C;
	long GetCurrentA4(void) = 0x200C;
	pascal void UnloadA4Seg(void *);

#else

	#define EnterCodeResource()
	#define ExitCodeResource()
	#define SetCurrentA4() 	0L
	#define SetA4(x)		0L
	#define GetCurrentA4() 	0L
	#define UnloadA4Seg(x) 	0

#endif

#ifdef __cplusplus
}
#endif

#endif
