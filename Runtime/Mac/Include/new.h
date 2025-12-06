/*  Metrowerks Standard Library  Version 2.2  1997 October 17  */
/*
 *	new
 *	
 *		Copyright © 1996-1997 Metrowerks, Inc.
 *		All rights reserved.
 */
 
#ifndef __new__
#define __new__

#include <mcompile.h>
#include <size_t.h>     //MW-mm 960723

#ifdef DebugNew_H     
	#undef new		//970401 bkoz
#endif

#pragma options align=native
#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import on
#endif

#ifdef MSIPL_USING_NAMESPACE  // MW-mm 960213b
namespace std {
#endif

class bad_alloc
{
	public :
	    bad_alloc () MSIPL_THROW {}
//	    bad_alloc (const bad_alloc& ) MSIPL_THROW {}
//	    bad_alloc& operator= (const bad_alloc& exarg) MSIPL_THROW {}
	    virtual ~bad_alloc () MSIPL_THROW {};
	    virtual const char* what () const MSIPL_THROW { return NULL; }

	private :
//	    static  const string alloc_msg;
};

	struct nothrow_t;					//970415 bkoz
	extern nothrow_t nothrow;			//971010 vss
		
	typedef void (*new_handler)(); 
	
	#if __dest_os == __win32_os
		new_handler set_new_handler(new_handler); 
	#else
		new_handler set_new_handler(new_handler) throw(); 
	#endif

#ifdef MSIPL_USING_NAMESPACE // MW-mm 960213b
} /* namespace std */
#endif


#if !__MOTO__	//moto can't have two declarations, one with exception spec and one w/o
	void * 	operator new(size_t size);  // MW-mm 960213c
#endif
#ifdef MSIPL_USING_NAMESPACE	//971006 vss
	void * 	operator new(size_t size) throw (std::bad_alloc); // MW-mm 960213c //bkoz 960813
	void * 	operator new(size_t size, const std::nothrow_t&)		throw();	//9608013 bkoz
#else
	void * 	operator new(size_t size) throw (bad_alloc); // MW-mm 960213c //bkoz 960813
	void * 	operator new(size_t size, const nothrow_t&)		throw();	//9608013 bkoz
#endif
	
	//void	operator delete		(void * ptr);  //MW-mm 960307a
	void	operator delete		(void * ptr) throw(); //MW-mm 960307a

//				void * 	operator new[]		(size_t size)	throw(bad_alloc);
//				void * 	operator new[]		(size_t size, const nothrow& t)	throw();
//				void		operator delete[]	(void * ptr)	throw();

//inline		void *	operator new(size_t, void * ptr)throw()	{ return(ptr); }
    void *	operator new(size_t, void * ptr)throw();
//inline	void * 	operator new[]		(size_t, void * ptr) throw()	{ return(ptr); }
//inline	void		operator delete		(void * , void *) throw()	{}
//inline	void		operator delete[]	(void * , void *) throw()	{}

//	non-standard functions
extern char	__throws_bad_alloc;
extern void __throw_bad_alloc();
extern void _set_newpoolsize(size_t);		//	default: 0x00010000L
extern void _set_newnonptrmax(size_t);		//	default: 0x00001000L
extern char _prealloc_newpool(size_t);		//	preallocte a new buffer

#if defined(__CFM68K__) && !defined(__USING_STATIC_LIBS__)
	#pragma import reset
#endif
#pragma options align=reset

#ifdef DebugNew_H       //970401 bkoz
	#define new NEW
#endif


#endif /*__new__*/

/* Change record
MW-mm 960213a  Deleted the definition of the bad_except class
MW-mm 960213b  Put Modena wrappers around namespace
MW-mm 960213c  Changed declaration to avoid syntax error in line with <new>
MW-mm 960307a  Changed declaration to avoid syntax error in line with delete
MW-mm 960723   Added include of size_t.h so that new.h can be compiled independently
mw-bk 960813   added andreas's changes for new throw bad_alloc()
mw-bk 960902   moved class exception into exception header, including excpt instead of stdexcept
mw-bk 961210 	added alignment wrapper
mw-bk 961221	line 65 added moto wrapper (mmoss)
vss   971006   namespace std
vss   971010   Put in export of nothrow_t as per standards
*/
