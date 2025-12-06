/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */

/*
 *	typeinfo
 *	
 *		Copyright © 1996-1997 Metrowerks, Inc.
 *		All rights reserved.
 */
 
#ifndef __typeinfo__
#define __typeinfo__

#include <mcompile.h>

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

__namespace(std)

#if __MOTO__
#pragma define_type_info
#endif
class type_info
{
		const char	*tname;
		const void	*tbase;
	
	public:
		// 960905 KO: This line creates a virtual table which throws off thecompiler generated
		// RTTI code on x86.
		#if	__dest_os != __win32_os
			virtual 	~type_info	() {};
		#endif
		bool	operator==	(const type_info&)	const;
		bool	operator!=	(const type_info&)	const;
		bool	before	(const type_info&)	const;
		const	char *	name ()	const;
	
	private:
		type_info	(const type_info&);
		type_info&	 operator=	(const type_info&);
};

class bad_typeid
{
	public :
		// we do nothing with this for now ???
    	bad_typeid() {};
    	virtual ~bad_typeid () {};
};

class bad_cast
{
	public :
		// we do nothing with this for now ???
    	bad_cast(const char* str) {};
    	virtual ~bad_cast() {};
};



__end_namespace(std)

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#endif

/* Change Record
// 06oct98	alx 		Removed unwanted garbage exceptions
// mm 960609a          Commented out to avoid duplicate declaration
// mm 960509b          Moved from mexcept.h
// bkoz960828          changes to move exception classes back into typeinfo
//981210 bkoz added alignment wrapper
//961221 bkoz	line 23 added moto pragme (mmoss)
//961229 bkoz removed bool_type and substituted bool
//970211 bkoz added defs for bad_cast ctors, bad_typeid dtor
*/

/*     Change record
*/
