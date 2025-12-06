
#ifndef _H_XMoaExpt
#define _H_XMoaExpt

/* ================================================================================

	XMoaExpt.h    $Revision: 2 $

	Copyright (c) 1994, 1995, 1996, 1997 Macromedia, Inc.  All Rights Reserved
	
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
	
	Provides a robust exception class which includes the ability to get human
	readable descriptions of moa and system errors.
	
	History:

	09sep98	alx	Added XMOAEXCEPT_EXIT_ to allow any default bad return value
	02apr98	LLB	Added clientMode to XSupport so a single version can be used by
				Xtras and host apps.
	14oct97 alx Added Hardware (low level) exceptions - define INSTALL_EX_HANDLER to use them
	05sep97	alx	Added whether or not exception is silent / also change to use native types +
				added catch(...) to XMOAEXCEPT_ENTER/EXIT macros + MoaBool on MoaErrorToString
	24apr97	alx	Added description.
	10apr97	alx	XDEBUG back to MuiDEBUG --> this will be changed again, temporary.
	28mar97	alx	Stop MSVC 4.1 warnings and strip file and line references.
	18mar97	alx	Rename includes
	08mar97	jcw	new header file format, documentation for external consumption.
	20feb97	alx	Fixed error code for unimplemented
	18feb97	alx	Added Bad Interface exception
	05feb97	alx	Add terminate and unexpected handlers for Mac
	03feb97	alx	Compiles again on Windows
	01feb97	alx	Fixed alot of stuff
	31jan97	alx	Added flag to determine if we are already throwing
	30jan97	alx	UnImplemented exception + includes and statics
	21jan97	alx	Windows compiler is terrible.
	21jan97	alx	Yank implementation
	20jan97	alx	Mac includes were STILL screwy!
	13jan97	alx	Mac includes were screwy
	03jan97	alx	MSVC 4.2 won't catch derived exceptions unless base class
				destructor is public + add exclamation icon
	02jan97	alx	Shrink stack usage
	20dec96	alx	Nicer Mac Alert and formatting/string mapping for MoaErrors
	17dec96	alx	Add MacOS Toolbox exception
	13dec96	alx	Crude windows for exception description
	19nov96	alx	Oops, fixed up those macros!
	19nov96	alx	Added macros for overriding default MoaError Code
	18nov96	alx	Updated for initial checkin

=================================================================================== */

///////////////////////////////////////////////////////////////////////////////////
//
// Description
//
///////////////////////////////////////////////////////////////////////////////////

/*

	Using the exception handler is very simple. It was not designed to cross DLL/CFM
	code boundries therefore the exception carries around a corresponding MoaError
	code for the exception.  Call GetMoaError() to retrieve the error code.  You can
	use this to pass back across the MOA or DLL/CFM boundries.
	
	Use the Macros for throwing exceptions as they can provide you with debugging
	information if you turn on the DEBUG flag in both your headers and in XSupport.

	WARNING: Do not call the Initialize or Terminate methods of this object,
	use the XSupport class to initialize the exception handler.

// EXAMPLE:

// Turning this on triggers recording of line and file for debugging
// Otherwise you get vague error descriptions designed for end-users
//#define MuiDEBUG


#include "XMoaExpt.h"

// declare some function
void foo( void )
{
	// need this for exceptions to work properly
	XSupport::Initialize( pObj->pCallback, 512, MuiDEBUG );

	try
	{
		// print a message to the message window
		IMmUtilsHelper().Use()->PrintMessage( "Hello World, this is about to throw an exception!\n" )
	
		// Try these with MuiDEBUG defined and not defined...
		// you can throw a reagular exception
		kThrowMoaException( CMoaMmValueMismatch );
	
		// or use a reason as well 
		kThrowMoaExceptionReason( CMoaMmValueMismatch, "Wrong Type!" );
		
		// or you can override the error code
		kThrowMoaExceptionErr( CMoaBadException, kMoaErr_NotEnoughSSW );
		kThrowMoaExceptionErr( CMoaToolboxException, -108 );
		
		// or both
		kThrowMoaExceptionReasonErr( CMoaBadException, "Bummer", kMoaErr_NotEnoughSSW );
		
		
		// You don't need to use the kThrowMoaException macros if you don't want to
		// All these do for you is trap the line and file when MuiDEBUG is
		// defined...
		throw CMoaBadException( "Bummer", 0,0, kMoaErr_NotEnoughSSW );
		// or
		throw CMoaBadException( "Bummer" );
		
		// you can also use the exception without throwing it
		MoaChar string[256];
		CMoaException().MoaErrorToString( kMoaErr_NotEnoughSSW, string, sizeof( string ) );
		// or
		CMoaException().MoaErrorToString( CMoaMmValueMismatch().GetMoaError(), string, sizeof( string ) );
		IMmUtilsHelper().Use()->PrintMessage1( "no exception thrown but here is some error text: \n%s\n", (MoaLong)string );
	}
	catch( CMoaException& ex )
	{
		ex.DescribeToUser();
		IMmUtilsHelper().Use()->PrintMessage1("\nException caught: %s\n", (MoaLong)ex.What() );
	}
	catch( ... )
	{
		printf ("Run away exception\n");
	}
	
	// do this last, otherwise the message mapper bites it.
	XSupport::Shutdown();
}
*/

// This is useful for when you are using XSupport with an App (or in an Xtra that is running
// in a host app that also uses XSupport) for catching low level (hardware) exceptions.
// It is disabled here for two reasons:  1. On the Mac the exception handler is system wide
// which means if another app faults the machine we catch it and throw an exception, bad.
// 2. On Windows and Mac an Xtra that is loaded and initialized will intercept exceptions
// and cause an exception to get thrown even though the exception might not have occurred 
// in the Xtra's code.
// The only safe use of this (on Windows for now) is to have your host app and the Xtras use
// the same library (XSupport) and both define INSTALL_EX_HANDLER if the respective code.
// This gives you a graceful way of intercepting every problem that could occur to your 
// program while it is executing.  The hardware exceptions that were added to this file get 
// thrown from the low level exception handler.  Director currently does not link against
// XSupport which is why INSTALL_EX_HANDLER is not defined. This is also very useful for
// debugging on Windows.
//#define INSTALL_EX_HANDLER

///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////

#ifdef MACINTOSH
#ifndef __DIALOGS__
#include <Dialogs.h>	// for ParamText
#endif
#ifndef __TEXTUTILS__
#include <TextUtils.h>	// for c2pstr
#endif
#ifndef _EXCEPTION_		// for terminate/unexpected handlers
#include <exception>
#endif
#ifdef INSTALL_EX_HANDLER
#include <MachineExceptions.H>
#endif
#endif	// MACINTOSH

#ifdef _WINDOWS
#include <Windows.h>	// for MessageBox
#include <eh.h>			// exception handling stuff for Win32
#endif

#ifndef _H_mmtypes
#include "mmtypes.h"
#endif

// ANSI
#include <string.h>
#include <stdio.h>

#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma push
	#pragma pointers_in_D0
#endif 

#ifdef _WINDOWS
	#if( _MSC_VER < 1020 )
	#pragma warning( disable : 4290 )
	#endif
#endif


///////////////////////////////////////////////////////////////////////////////////
//
// Macros / Defines
//
///////////////////////////////////////////////////////////////////////////////////

// define MuiDEBUG to get file and line number information you also need to specify
// TRUE in the XSupport initializer for debugFlag.
#if defined( MuiDEBUG ) || XDEBUG
#define kThrowMoaException( ex )					throw ex( NULL, __FILE__, __LINE__ )
#define kThrowMoaExceptionReason( ex, why )			throw ex( (why), __FILE__, __LINE__ )
#define kThrowMoaExceptionErr( ex, err )			throw ex( 0, __FILE__, __LINE__, (err) )
#define kThrowMoaExceptionReasonErr( ex, why, err )	throw ex( (why), __FILE__, __LINE__, (err) )
#else
#define kThrowMoaException( ex )					throw ex( NULL, NULL, NULL )
#define kThrowMoaExceptionReason( ex, why )			throw ex( (why), NULL, NULL )
#define kThrowMoaExceptionErr( ex, err )			throw ex( 0, NULL, NULL, (err) )
#define kThrowMoaExceptionReasonErr( ex, why, err )	throw ex( (why), NULL, NULL, (err) )
#endif

#define XMOAEXCEPT_ENTER	X_ENTER try {
#define XMOAEXCEPT_EXIT		 } catch( CMoaException& ex ) \
{ \
	ex.DescribeToUser(); \
	X_STD_RETURN( ex.GetMoaError() ); \
} \
catch( ... ) \
{ \
	CMoaException::Terminate();\
	X_STD_RETURN( -1 ); \
} \
X_EXIT

#define XMOAEXCEPT_EXIT_VOID } catch( CMoaException& ex ) \
{ \
	ex.DescribeToUser(); \
	X_RETURN_VOID; \
} \
catch( ... ) \
{ \
	 CMoaException::Terminate(); \
} \
X_EXIT

#define XMOAEXCEPT_EXIT_(badValue) } catch( CMoaException& ex ) \
{ \
	ex.DescribeToUser(); \
	return(badValue); \
} \
catch( ... ) \
{ \
	CMoaException::Terminate();\
	return(badValue); \
} \
X_EXIT


#define kMoaExWhatLength	32
#define kMoaExWhyLength		256

#ifdef MACINTOSH
#define kMoaExWhereLength	32
#endif
// windows has longer paths!
#ifdef _WINDOWS
#define kMoaExWhereLength	256
#endif


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaException Declares -- This object is the baseclass for other exceptions
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaException
{
// --------------------------------------------------------------------------------
// Construction and Destruction
// --------------------------------------------------------------------------------
	public:
		CMoaException( void );
		CMoaException( const char* why, const char* where = 0, 
				MoaLong lineNum = 0, MoaError error = kMoaErr_InternalError );

		virtual ~CMoaException( void );

// --------------------------------------------------------------------------------
// Methods
// --------------------------------------------------------------------------------
		// This is how to retrieve the error code for C callers or for cross DLL/CFM
		virtual MoaError GetMoaError( void ) const throw();

		// What is the exception -- usually the class name
		virtual const char* What( void ) const throw();
		
		// What file did the exception occur in
		virtual const char* Where( void ) const throw();
		
		// user definable reason for the exception
		virtual const char* Why( void ) const throw();

		// Use this to report the exception to the user.
		virtual void DescribeToUser( void ) throw();

		// a utility method for outputting a description
		virtual void Describe( char* description, MoaLong size ) throw();

		// use this to convert a MoaError to a string -- returns whether or not it found that error
		virtual MoaBoolParam MoaErrorToString( const MoaError& theError, char* theString, MoaLong size ) throw();

		// this stops exceptions from displaying.
		virtual void Silent( MoaBoolParam silent = TRUE ) throw();

// --------------------------------------------------------------------------------
// Static Methods
// --------------------------------------------------------------------------------
		static MoaError Initialize( size_t reserveMem, MoaBoolParam debugMode,
									MoaBoolParam clientMode );

		static void		Shutdown( void );
#ifdef MACINTOSH
		static void		Terminate( void );

#ifdef INSTALL_EX_HANDLER
		static OSStatus	LowLevelExHandler( ExceptionInformation* );
#endif
#endif	// !MACINTOSH

#ifdef _WINDOWS
		static void	__cdecl	Terminate( void );

#ifdef INSTALL_EX_HANDLER
		// this catches those Win32 C exceptions that are so kindly generated
		// and turns them into the appropriate CMoaException derivative.
		static void	__cdecl	WinExTranslator( unsigned int, struct _EXCEPTION_POINTERS* );
#endif
#endif	// !WINDOWS
			
// --------------------------------------------------------------------------------
// Protected methods
// --------------------------------------------------------------------------------
	protected:
		virtual void	SetError( MoaError ) throw();
		virtual void	SetWhat( const char* ) throw();
		virtual void	SetWhere( const char*, MoaLong ) throw(); // file and line number
		virtual void	SetWhy( const char* ) throw();
		
// --------------------------------------------------------------------------------
// Member Data
// --------------------------------------------------------------------------------
	private:
		char			mWhat[kMoaExWhatLength];	// release = MoaError mapping / debug = exception type
		char			mWhere[kMoaExWhereLength];
		char			mWhy[kMoaExWhyLength];
		MoaError		mErrorCode;
		MoaLong			mLineNum;
		MoaBoolParam	mSilent;
		
// --------------------------------------------------------------------------------
// Static Member Data
// --------------------------------------------------------------------------------
		static 	MoaBoolParam	mDebugMode;
		static  MoaBoolParam	mIsThrowing;
		static 	void*			mReserveMem;

#ifdef MACINTOSH
		static terminate_handler  mTerminateHandler;
		static unexpected_handler mUnexpectedHandler;
#ifdef INSTALL_EX_HANDLER
		static ExceptionHandler   mLowLevelExHandler;
#endif
#endif	// !MACINTOSH
#ifdef _WINDOWS
		static terminate_function		mTerminateHandler;
		static unexpected_function		mUnexpectedHandler;
#ifdef INSTALL_EX_HANDLER
		static _se_translator_function	mWinExTranslator;
#endif
#endif	// !WINDOWS
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaBadException Declares -- The universal badness exception
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaBadException : public CMoaException 
{
	public:
		CMoaBadException( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaLogicError Declares -- Base class -- useful for creating other logic errors
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaLogicError : public CMoaException
{
	public:
		CMoaLogicError( const char* why = 0, const char* where = 0,
				MoaLong lineNum = 0, MoaError error = kMoaErr_InternalError );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaDomainError -- Domain error (here for sake of completeness)
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaDomainError : public CMoaLogicError
{
	public:
		CMoaDomainError( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaInvalidArgument -- You specified an invalid argument
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaInvalidArgument : public CMoaLogicError
{
	public:
		CMoaInvalidArgument( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_BadParam ) ;
};



///////////////////////////////////////////////////////////////////////////////////
//
// CMoaLengthError -- Invalid length specified
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaLengthError : public CMoaLogicError
{
	public:
		CMoaLengthError( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaOutOfRange -- value out of range
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaOutOfRange : public CMoaLogicError
{
	public:
		CMoaOutOfRange( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaMmErr_ArgOutOfRange );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaRuntimeError -- Base Class, useful for runtime type errors
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaRuntimeError : public CMoaException
{
	public:
		CMoaRuntimeError( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError error = kMoaErr_InternalError );
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaOverflowError -- An overflow occurred
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaOverflowError : public CMoaRuntimeError
{
	public:
		CMoaOverflowError( const char* why = 0, const char* where = 0, 
					MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaRangeError -- Invalid range
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaRangeError : public CMoaRuntimeError
{
	public:
		CMoaRangeError( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaMemoryException -- A memory exception occurred, usually out of memory
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaMemoryException : public CMoaRuntimeError
{
	public:
		CMoaMemoryException( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_OutOfMem );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaResourceException -- A resource is missing or unavailable
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaResourceException : public CMoaRuntimeError
{
	public:
		CMoaResourceException( const char* why = 0, const char* where = 0,
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaToolboxException -- A MacOS toolbox error occurred
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaToolboxException : public CMoaRuntimeError
{
	public:
		CMoaToolboxException( const char* why = 0, const char* where = 0,
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaWindowsException -- A Windows API error occurred
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaWindowsException : public CMoaRuntimeError
{
	public:
		CMoaWindowsException( const char* why = 0, const char* where = 0,
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaFileException -- A File error occurred
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaFileException : public CMoaRuntimeError
{
	public:
		CMoaFileException( const char* why = 0, const char* where = 0,
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaMmValueException -- MoaMmValue mismatch
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaMmValueMismatch : public CMoaLogicError
{
	public:
		CMoaMmValueMismatch( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaMmErr_ValueTypeMismatch );
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaUnImplemented -- No code!
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaUnImplemented : public CMoaRuntimeError
{
	public:
		CMoaUnImplemented( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaMmErr_NotImplemented );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaBadInterface -- Couldn't create an interface
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaBadInterface : public CMoaRuntimeError
{
	public:
		CMoaBadInterface( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_BadInterface );
};




///////////////////////////////////////////////////////////////////////////////////
//
// CMoaHardwareException -- Low Level exception base class
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaHardwareException : public CMoaException
{
	public:
		CMoaHardwareException( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};



///////////////////////////////////////////////////////////////////////////////////
//
// CMoaHardwareAccessFault -- low level exception
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaHardwareAccessFault : public CMoaHardwareException
{
	public:
		CMoaHardwareAccessFault( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaHardwareAccessFault -- low level exception
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaHardwareIllegalInstruction : public CMoaHardwareException
{
	public:
		CMoaHardwareIllegalInstruction( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaHardwareIntegerException -- low level exception
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaHardwareIntegerException: public CMoaHardwareException
{
	public:
		CMoaHardwareIntegerException( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaHardwareFloatException -- low level exception
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaHardwareFloatException: public CMoaHardwareException
{
	public:
		CMoaHardwareFloatException( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaHardwareStackOverflow -- low level exception
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaHardwareStackOverflow: public CMoaHardwareException
{
	public:
		CMoaHardwareStackOverflow( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};

///////////////////////////////////////////////////////////////////////////////////
//
// CMoaHardwareDivideByZero -- low level exception
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaHardwareDivideByZero: public CMoaHardwareException
{
	public:
		CMoaHardwareDivideByZero( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaHardwareBigBadDeath -- low level exception
//
///////////////////////////////////////////////////////////////////////////////////

class CMoaHardwareBigBadDeath: public CMoaHardwareException
{
	public:
		CMoaHardwareBigBadDeath( const char* why = 0, const char* where = 0, 
				MoaLong lineNum = 0, MoaError err =  kMoaErr_InternalError );
};



#ifdef WINDOWS
	#if( _MSC_VER < 1020 )
	#pragma warning( default : 4290 )
	#endif
#endif


#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma pop
#endif 

#endif	// _H_XMoaExpt

// EOF
