
#ifndef _H_XSupport
#define _H_XSupport

/* ================================================================================

	XSupport.h    $Revision: 6 $

	Copyright (c) 1994, 1995, 1996 Macromedia, Inc.  All Rights Reserved
	
	You may utilize this source file to create and compile object code for use
	within products you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
	WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
	INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
	PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
	FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
	USE OR INABILITY TO USE THIS CODE.
	
	Purpose:
	
	Provides access to XSupport library. To use XSupport, you must link the
	XSupport.lib into your Xtra. Not that XSupport is not available for win16.
	
	History:

	27jul99	alx	Removed all 68k support
	02apr98	LLB	Added clientMode to XSupport so a single version can be used by
				Xtras and host apps.
	13oct97 alx Disable MSVC 5.0 warnings.
	16sep97 LLB Re-insert Initialized() method. Disable MSVC 4.1 warnings.
	21aug97 alx Added kXSupportDefaultReserve constant
	20may97 alx Add exception specifications
	17jul97	alx	Fix Mac Build -- bool support is not turned on yet!!
	24apr97	alx	Add description
	18mar97	alx	Rename includes, strip MSymCnvt.h this file is private.
	08mar97	jcw	new header file format, documentation for external consumption.
	20feb97 alx Added VBL task stuff
	10feb97 alx Added Constructor/destructor
	31jan97 alx Added UnSafeGetCallback
	30jan97 alx Created

=================================================================================== */

///////////////////////////////////////////////////////////////////////////////////
//
// Description
//
///////////////////////////////////////////////////////////////////////////////////

/*
	This file is used to initialize and shutdown the XSupport library:
	try
	{
		XSupport::Initialize( pObj->pCallback, reserveMem, debugFlag );
	} ...
	
	Remember most of these routines THROW CMoaExceptions, you must catch these 
	otherwise you will terminate the host application with a fatal error.

	This file allows access to the pCallback anywhere in your code by calling:
	XSupport::GetCallback().
	
	There is also access to the Symbol Converter.  The Symbol Converter maintains
	the many symbols that MuiDialog and future Xtras use.  It is a static lookup
	table of tokens that can be switched on instead of MoaMmValues.  Almost all
	MuiDialog routines take a TMuiSymbol as their input. The Symbol Converter
	converts between tokens (TMuiSymbols) and MoaSymbols (MoaMmValues).
	See MSymCnvt.h for more info.  Use XSupport::GetSymbolConverter() anywhere
	to gain access to the Symbol Converter.
	
	XSupport allows you to install and remove VBLTasks only on the Macintosh. We urge
	you not to use these routines as they will change to support a cross platform
	abstraction of this functionality. Use at your own risk!

 */

///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef _H_moaxtra
#include "moaxtra.h"
#endif
#ifndef _H_XMoaExpt
#include "XMoaExpt.h"
#endif

#ifdef MACINTOSH
#include <Retrace.h>
#endif

#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma push
	#pragma pointers_in_D0
#endif 

#ifdef WINDOWS
#pragma warning( disable : 4290 )
#endif

///////////////////////////////////////////////////////////////////////////////////
//
// Checks
//
///////////////////////////////////////////////////////////////////////////////////

//#ifndef XDEBUG
//#error "You must define XDEBUG as either 1 for Debug or 0 for Release"
//#endif

#if XDEBUG
#define XDebugMessage(a) 		XSupport::XDebuggerMessage( (a) )
#else
#define XDebugMessage(a)
#endif


///////////////////////////////////////////////////////////////////////////////////
//
// Definitions
//
///////////////////////////////////////////////////////////////////////////////////

typedef enum {
	kXSupportDebugMode_Enable	= TRUE,
	kXSupportDebugMode_Disable	= FALSE
} TXSupportDebugMode;

typedef enum {
	kXSupportClientMode_Xtra	= TRUE,
	kXSupportClientMode_App		= FALSE
} TXSupportAppMode;

typedef struct XVBLTaskInternal **XVBLTask;
typedef class MmSymbolConverter FAR * PMmSymbolConverter;

const size_t kXSupportDefaultReserve = 1024;	// grab 1k reserve memory for when memory is too tight to display exception

class XSupport
{
	public:
#ifdef WINDOWS
		// constructors/destructors for temporary or heap construction
		XSupport( PIMoaCallback pInterface,
				  size_t		reserveMem = kXSupportDefaultReserve,
				  MoaBoolParam	debugMode  = kXSupportDebugMode_Disable,
				  MoaBoolParam	clientMode = kXSupportClientMode_Xtra );
		~XSupport( void );
#endif
#ifdef MACINTOSH
		// constructors/destructors for temporary or heap construction
		XSupport( PIMoaCallback pInterface,
				  size_t		reserveMem	= kXSupportDefaultReserve,
				  MoaBoolParam	debugMode	= kXSupportDebugMode_Disable,
				  MoaBoolParam	clientMode	= kXSupportClientMode_Xtra ) throw( CMoaException );
		~XSupport( void ) throw( CMoaException );
#endif
		// Initializes the Exception Handler, Symbol Converter, and the Helpers
		static MoaError				Initialize( PIMoaCallback pInterface,
												size_t		  reserveMem = kXSupportDefaultReserve,
												MoaBoolParam  debugMode	 = kXSupportDebugMode_Disable,
												MoaBoolParam  clientMode = kXSupportClientMode_Xtra  ) throw();

		// Shuts down the library if the refcount is zero, also clears all statics for re-entry
		static void					Shutdown( void ) throw();
		
		static MoaBoolParam			Initialized() { return (mCallbackInterface != NULL); }

		static MoaBoolParam			GetClientMode() { return mClientMode; }

		static PMmSymbolConverter	GetSymbolConverter( void ) throw( CMoaException );

		static PIMoaCallback		GetCallback( void ) throw( CMoaException );
		static PIMoaCallback		UnSafeGetCallback( void ) throw();

#if XDEBUG
		static void					XDebuggerMessage( const char* format, ... );
#endif

#ifdef MACINTOSH
		static XVBLTask				VBLTaskInstall( VBLUPP taskProc, MoaLong argument, MoaShort interval );
		static void					VBLTaskRemove( XVBLTask task );

		static MoaLong				VBLTaskGetArgument( VBLTaskPtr );
#endif // MACINTOSH

	private:
		static PIMoaCallback		mCallbackInterface; 
		static PMmSymbolConverter	mSymbolConverter;
		static MoaLong				mRefCount;
		static MoaBoolParam			mClientMode;
};

#ifdef WINDOWS
#pragma warning( default : 4290 )
#endif

#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma pop
#endif 

#endif	// _H_XSupport

// EOF
