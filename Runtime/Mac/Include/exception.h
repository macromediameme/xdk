/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */
/****************************************************************************/
/*	Project...:	Standard C++ Library										*/
/*	Name......:	exception													*/
/*	Purpose...:	exception handling											*/
/*  Copyright.: Copyright © 1995-1997 Metrowerks, Inc. All rights reserved. */
/****************************************************************************/

#ifndef _EXCEPTION_
#define _EXCEPTION_

typedef void (*terminate_handler)();
terminate_handler set_terminate(terminate_handler);
void terminate();

typedef void (*unexpected_handler)();
unexpected_handler set_unexpected(unexpected_handler);
void unexpected();

#ifdef __cplusplus
class exception {
public:
			exception() {}
	virtual	~exception() {}
};
#endif 

#endif	// !_EXCEPTION_

/*     Change record
03aug99	GWR	Added exception class stub. Needed by PowerPlant (in Auth)
06oct98 alx  Call through to exception removed, relevant code moved here.
*/
