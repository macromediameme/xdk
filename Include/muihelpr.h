#ifndef _H_MuiHelpr
#define _H_MuiHelpr

/* ================================================================================

	MuiHelpr.h    $Revision: 3 $

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
	MuiHelpr provides c++ wrappers around MOA interfaces, and a few other misc.
	helpful classes.
	
	History:

	16mar98	LLB	Added a layoutMode and windowType conversions to MuiLingoConverter.
	27oct97	LLB	Include new mmi*.h files.
	24oct97	esg	added notification helper, added contstructor for other interfaces, fixed includes
	22oct97	LLB	Added optional doThrow arg to MoaHelper template.
	09sep97	jcw	Added IMoaDictHelper, pointers to helper classes typedefs.
	25aug97	alx	autoPtr was mangled
	22jul97	alx	MMToken define
	21jul97	alx Yanked Stream Helper --> Moved into XFileHlp.h (see me for reason)
	17jul97	jcw bool to MoaBool for stream helper so it compiles in older compilers.
	16jul97	esg	added X-platform stream helper
	09jul97	jcw	Added IMoaDrCastHelper.
	05may97	alx	Added some corrections to documentation
	24apr97	alx	Added documentation to Helpers
	01apr97	LLB	Include windows.h before any MOA files
	28mar97	alx	Disabled MSVC 4.1 exception specification warnings.
	18mar97	alx	Deal with new include names
	08mar97	jcw	new header file format, documentation for external consumption.
	25feb97	JCW	Added types and table for MuiSymToWidgetConstantConverter/MuiWidgetToMuiSymConverter.
				Created MuiWidgetToMuiSymConverter, Changed MuiSymToWidgetConstantConverter to MuiLingoConverter
	30jan97	alx	Whoa where did MmValueHelper go? (MMValue.h)
	27jan97	JCW	Added protected accessor for the valueRef.
	24jan97	alx	Removed MuiCommonFileHelper + fixed autoptr
	22jan97	alx	Back and forth, Mac now compiles again.+ ifdef'ed for Windows
	22jan97	LLB	Fix build error by commenting throw from IMoaBitmapHelper declaration.
	21jan97	alx	Windows compiler is terrible.
	20jan97	alx	Stub out MuiCommonFileHelper
	13jan97	alx	Remove CMui.h reference and some mac/win specific prototypes
	10jan97	tgs	Add CoerceValueToFloat and CoerceValueToInteger
	09jan97 alx	Added IMoaBitmapHelper and fake IMoaBitmapUtils classes
	12dec96 JCW	Added helper to convert from muiSymbols to widgetconstants.
	11dec96 alx	Added inline MoaMmValuesAreEqual
	10dec96 JCW	Added size to struc helper, removed ((IMoaUnknown*)mInterface)->AddRef();
				from base class to fix dangling interface problem.
	08dec96 alx	Added SetNewValue so that MmValueHelper can work on more than one value
	04dec96 alx	default param for MmValueHelper changed.
	29Nov96 LLB	re-implemented MmValue helper with built-in type conversion.
	27Nov96 alx	MmValue helper
	26Nov96 alx	Bug fix and more helpers + changed interface helpers to be
				template based + ripped out mac specific code
	25Nov96	JCW	Movie helper fixed.
	22Nov96	JCW	Movie helper
	22Nov96	alx	Font helper
	20Nov96	alx	Name changes
	19Nov96	alx	Add pen size helpers
	18Nov96	alx	Use real exceptions + forgot a few consts
	13Nov96	JCW	Added MuiDefaultStrucHelper, in new Data Helpers section.
	09Nov96	alx	Removed IMuiServiceHelper
	07Nov96	alx	Updated
	06nov96	alx	Added IMoaHandleHelper
	05nov96	alx	Added IMoaCallocHelper
	04nov96	alx	Added MacIsKeyDown()
	04nov96	alx	Missing quote & another helper: IMuiServiceHelper
	02nov96	LLB	Made it compile on windows.
	02nov96	alx	Cookies and file name change
	01nov96	alx	Created.

=================================================================================== */

///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////

// on WINDOWS, include windows.h before any moa files
#ifdef _WINDOWS
	#ifndef _WINDOWS_
	#include <windows.h>
	#endif
#endif

#ifndef _H_moaxtra
#include "moaxtra.h"
#endif

#ifndef _H_moastdif
#include "moastdif.h"
#endif

#ifndef _H_mmiservc
#include "mmiservc.h"
#endif

#ifndef _H_driservc
#include "driservc.h"
#endif

#ifndef _H_awiservc
#include "awiservc.h"
#endif

#ifndef _H_mmillist
#include "mmillist.h"
#endif

#ifndef _H_mmiplist
#include "mmiplist.h"
#endif

#ifndef _H_mmivcoer
#include "mmivcoer.h"
#endif

#ifndef _H_mmixscrp
#include "mmixscrp.h"
#endif

#ifndef __T_MUIINIT__
#include "muiInit.T"
#endif

#ifndef _T_MuiSym
#include "MuiSym.T"
#endif

#ifndef _H_XMoaExpt
#include "XMoaExpt.h"
#endif

#ifndef _H_XSupport
#include "XSupport.h"
#endif

#ifndef _H_moanotif
#include "MoaNotif.h"
#endif

class MMString;


#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma push
	#pragma pointers_in_D0
#endif 

#ifdef WINDOWS
	#pragma warning( disable : 4290 )
#endif

///////////////////////////////////////////////////////////////////////////////////
//
// Declares
//
///////////////////////////////////////////////////////////////////////////////////

typedef struct
{
	TMuiSymbol 			muiSym;
	TMuiWidgetType		muiType;
} MuiSymToWidgetTableEntry;

typedef MuiSymToWidgetTableEntry FAR * PMuiSymToWidgetTableEntry;
typedef const MuiSymToWidgetTableEntry ConstPMuiSymToWidgetTableEntry;

///////////////////////////////////////////////////////////////////////////////////
//
// Defines
//
///////////////////////////////////////////////////////////////////////////////////

#define kMui_InterfaceMissingString	"Interface Missing!"

#define	kMAX_CONVERTED_VALUE_STRING		256
#define kMoaMmValueInternalType_Picture	5

///////////////////////////////////////////////////////////////////////////////////
// 
// Interface helpers
//
//
// NOTE: To use these helpers you must have initialized XSupport
//
// IMPORTANT: These interface helpers THROW CMoaExceptions so you have been warned!
//
///////////////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////////
//
// This template provides exception-safe access to MOA interfaces as well
// as a simpler interface.
//
///////////////////////////////////////////////////////////////////////////////////

/*

// There are three ways to use the helpers, for example:
// to gain access to the IMoaMmUtils interface:

// On the stack, scope based (you don't need to call Use, operator () is overloaded)
IMmUtilsHelper mmUtilsHelper;
mmUtilsHelper()->PrintMessage( "Hello\n" );

// Single line construction/destruction
IMmUtilsHelper().Use()->PrintMessage( "Hello\n" );

// In the heap 
IMmUtilsHelper* mm = new IMmUtilsHelper;
mm->Use()->PrintMessage( "Hello\n" );
delete mm;

// Tips:
- Don't construct or use the single line construction in loops, put the helper on
  the stack first.
- Using the Helpers guarantees compatibility even if the underlying interfaces change.
- You can create your own Helper with one line of code. (See below)

*/


// Need to typedef these, because the Metrowerks compiler gets confused
// by the overloaded constructors and their optional arguments.
typedef enum {
kThrowOnMissingInterface = TRUE,
kDontThrowOnMissingInterface = FALSE
} TThrowOption;

typedef enum {
kReleaseInterface = TRUE,
kDontReleaseInterface = FALSE
} TReleaseOption;

// This class is useful for using any interface
template <ConstPMoaInterfaceID TinterfaceID, class Tpointer> class IMoaHelper
{
	public:
		IMoaHelper( TThrowOption doThrow=kThrowOnMissingInterface ) throw( CMoaException ) :
			mInterface( NULL )
		{
			// first grab the IMoaUnknown interface
			PIMoaCallback unknown = XSupport::GetCallback();

			// find the interface we need
			unknown->QueryInterface( TinterfaceID, (PPMoaVoid)&mInterface );

			if( !mInterface && doThrow )
				kThrowMoaExceptionReason( CMoaBadException, kMui_InterfaceMissingString );
		}

		IMoaHelper( Tpointer pInterface, TReleaseOption release = kReleaseInterface ) :
			mInterface( pInterface )
		{
			// if the caller doesn't want the interface released, we add an extra ref count,
			// since we will always release in the end.
			if (!release)
				mInterface->AddRef();
		}
			
		virtual ~IMoaHelper( void ) throw()
		{
			if( mInterface )
				((IMoaUnknown*)mInterface)->Release();
		}

		// The sole accessor and reason d'etre
		Tpointer	Use( void ) 		const throw() { return mInterface; }
		Tpointer	operator()( void )	const throw() { return Use(); }

	private:
		Tpointer mInterface;
};

// To create your own Helper copy the line below and substitute the appropriate info
// typedef IMoaHelper< &InterfaceIIDHere,   PointerTypeHere >	HelperName;
// See the examples below:

typedef IMoaHelper< &IID_IMoaCalloc,   		PIMoaCalloc >		IMoaCallocHelper;
typedef IMoaHelper< &IID_IMoaHandle,   		PIMoaHandle > 		IMoaHandleHelper;
typedef IMoaHelper< &IID_IMoaMmUtils,  		PIMoaMmUtils > 		IMmUtilsHelper;
typedef IMoaHelper< &IID_IMoaMmUtils, 		PIMoaMmUtils > 		IMoaMmUtilsHelper;
typedef IMoaHelper< &IID_IMoaAppInfo, 		PIMoaAppInfo > 		IMoaAppInfoHelper;
typedef IMoaHelper< &IID_IMoaMmList,   		PIMoaMmList > 		IMoaMmListHelper;
typedef IMoaHelper< &IID_IMoaDrUtils,  		PIMoaDrUtils > 		IMoaDrUtilsHelper;
typedef IMoaHelper< &IID_IMoaDrPlayer, 		PIMoaDrPlayer > 	IMoaDrPlayerHelper;
typedef IMoaHelper< &IID_IMoaDrCast,   		PIMoaDrCast > 		IMoaDrCastHelper;
typedef IMoaHelper< &IID_IMoaDict,	   		PIMoaDict > 		IMoaDictHelper;
typedef IMoaHelper< &IID_IMoaAwPlayer, 		PIMoaAwPlayer > 	IMoaAwPlayerHelper;

typedef IMoaHelper< &IID_IMoaDrValue,			PIMoaDrValue > 			IMoaDrValueHelper;
typedef IMoaHelper< &IID_IMoaMmValue,			PIMoaMmValue >	 		IMoaMmValueHelper;
typedef IMoaHelper< &IID_IMoaMmUtils2,			PIMoaMmUtils2 > 		IMoaMmUtils2Helper;
typedef IMoaHelper< &IID_IMoaDrPaletteAccess,	PIMoaDrPaletteAccess > 	IMoaDrPaletteAccessHelper;
typedef IMoaHelper< &IID_IMoaNotification,		PIMoaNotification > 	IMoaNotificationHelper;
typedef IMoaHelper< &IID_IMoaMmWndWin,			PIMoaMmWndWin > 		IMoaMmWndWinHelper;
typedef IMoaHelper< &IID_IMoaMmWndMac,			PIMoaMmWndMac > 		IMoaMmWndMacHelper;
typedef IMoaHelper< &IID_IMoaDrSound,			PIMoaDrSound > 			IMoaDrSoundHelper;
typedef IMoaHelper< &IID_IMoaMmAssetCallback2,	PIMoaMmAssetCallback2 > IMoaMmAssetCallback2Helper;
typedef IMoaHelper< &IID_IMoaMmLinearList,		PIMoaMmLinearList > 	IMoaMmLinearListHelper;
typedef IMoaHelper< &IID_IMoaMmPropList,		PIMoaMmPropList > 		IMoaMmPropListHelper;
typedef IMoaHelper< &IID_IMoaMmValueCoercion,	PIMoaMmValueCoercion > 	IMoaMmValueCoercionHelper;

// New in D8 -- the interface shipping in D7 I think.
typedef IMoaHelper< &IID_IMoaDrPreferenceAccess, PIMoaDrPreferenceAccess > IMoaDrPrefsHelper;

// typedef IMoaHelper< &IID_IMoaPathName, PIMoaPathName > 	IMoaPathNameHelper;

// and the pointers to helper instances.
typedef IMoaCallocHelper		FAR * 	PIMoaCallocHelper;
typedef IMoaHandleHelper		FAR * 	PIMoaHandleHelper;
typedef IMmUtilsHelper			FAR *	PIMmUtilsHelper;
typedef IMoaMmUtilsHelper		FAR *	PIMoaMmUtilsHelper;
typedef IMoaAppInfoHelper		FAR * 	PIMoaAppInfoHelper;
typedef IMoaMmListHelper		FAR *	PIMoaMmListHelper;
typedef IMoaDrUtilsHelper		FAR *	PIMoaDrUtilsHelper;
typedef IMoaDrPlayerHelper		FAR *	PIMoaDrPlayerHelper;
typedef IMoaDrCastHelper		FAR * 	PIMoaDrCastHelper;
typedef IMoaDictHelper			FAR * 	PIMoaDictHelper;

typedef IMoaDrValueHelper			FAR* PIMoaDrValueHelper;
typedef IMoaMmValueHelper			FAR* PIMoaMmValueHelper;
typedef IMoaMmUtils2Helper			FAR* PIMoaMmUtils2Helper;
typedef IMoaDrPaletteAccessHelper	FAR* PIMoaDrPaletteAccessHelper;
typedef IMoaNotificationHelper		FAR* PIMoaNotificationHelper;
typedef IMoaMmWndWinHelper			FAR* PIMoaMmWndWinHelper;
typedef IMoaMmWndMacHelper			FAR* PIMoaMmWndMacHelper;
typedef IMoaDrSoundHelper			FAR* PIMoaDrSoundHelper;
typedef IMoaMmAssetCallback2Helper	FAR* PIMoaMmAssetCallback2Helper;
typedef IMoaMmLinearListHelper		FAR* PIMoaMmLinearListHelper;
typedef IMoaMmPropListHelper		FAR* PIMoaMmPropListHelper;
typedef IMoaMmValueCoercionHelper	FAR* PIMoaMmValueCoercionHelper;

typedef IMoaDrPrefsHelper			FAR* PIMoaDrPrefsHelper;


// This is a simple class that deletes a pointer when it goes out of scope.
// This handy for when you are forced to allocate an object in the heap
// even though you wanted to treat it like a stack object.
// For example:
/*

{
	IMmUtilsHelper* mmUtils = new IMmUtilsHelper;
	autoptr<IMmUtilsHelper*> deleteMeWhenIGoOutOfScope( mmUtils );
	
	// don't worry about throwing, your pointer will be deleted
	kThrowMoaException( CMoaBadInterface );
}

*/


template <class T> class autoptr
{
	public:
		autoptr( T& ptr ) : mT( ptr ) {}
		~autoptr( void )	{ delete mT; }

		operator T( void ) { return mT; }
		
	private:
		T& mT;
};


// The following classes are used to convert PicHandle/HBITMAPs to and from MoaMmValues
// This code WILL change!  Therefore you should only use the IMoaBitmapHelper and NOT
// the IMoaBitmapUtils object directly.  A MoaBitmap is a PicHandle on Macintosh and
// an HBITMAP (unfortunately a void*) on Windows.


#ifdef MACINTOSH		
typedef PicHandle MoaBitmap;
#elif _WINDOWS
typedef HBITMAP MoaBitmap;
#endif
typedef MoaBitmap FAR * PMoaBitmap;

// this is a temporary solution -- W A R N I N G :   DO NOT USE DIRECTLY --
class IMoaBitmapUtils
{
	public:
		virtual MoaError BitmapToValue( MoaBitmap newBitmap, PMoaMmValue destValue );
		virtual MoaError ValueToBitmap( ConstPMoaMmValue value, MoaBitmap* destBitmap );
};
typedef IMoaBitmapUtils FAR * PIMoaBitmapUtils;



// This class is useful converting to and from MoaBitmaps
// This works the same way as the template based helpers.
class IMoaBitmapHelper 
{
	public:
#ifdef MACINTOSH
		IMoaBitmapHelper( void ) throw( CMoaException );
		virtual ~IMoaBitmapHelper( void ) throw();
#endif
#ifdef WINDOWS	
		// 4.2 & 4.1 have a problem with exception specs
		// with constructors/destructors not implemented in the header
		IMoaBitmapHelper( void );
		virtual ~IMoaBitmapHelper( void );
#endif
		// The sole accessor and reason d'etre
		PIMoaBitmapUtils	Use( void ) 		const throw() { return mInterface; }
		PIMoaBitmapUtils	operator()( void )	const throw() { return Use(); }

	private:
		PIMoaBitmapUtils mInterface;
};


// This class is useful for using the IMoaDrMovie interface
// This works the same way as the template based helpers.
// *** Calls IMoaDrPlayer::GetActiveMovie() to acquire the movie interface
class IMoaDrMovieHelper
{
	public:
#ifdef MACINTOSH
		IMoaDrMovieHelper( void ) throw( CMoaException );
		virtual ~IMoaDrMovieHelper( void ) throw();
#endif
#ifdef WINDOWS
		// 4.2 & 4.1 have a problem with exception specs
		// with constructors/destructors not implemented in the header
		IMoaDrMovieHelper( void );
		virtual ~IMoaDrMovieHelper( void );
#endif
		// The sole accessor and reason d'etre
		PIMoaDrMovie	Use( void ) 		const throw() { return mInterface; }
		PIMoaDrMovie	operator()( void )	const throw() { return Use(); }

	private:
		PIMoaDrMovie mInterface;
};






///////////////////////////////////////////////////////////////////////////////////
// 
// Data Helpers
//
//	Note, strucCreateDefaultInput creates values and addrefs them for the
//	widgetMmValue and widgetInteractionStruc.vLimits members. It is the responsibility
//	of the calling code to release these values.
//
///////////////////////////////////////////////////////////////////////////////////

class MuiDefaultStrucHelper 
{
	public:
		MuiDefaultStrucHelper( void );
		~MuiDefaultStrucHelper( void ) {};

		// util methods
		MoaError 	strucCreateDefaultInit( PTMuiWindow pInitStruc );
		MoaError	strucCreateDefaultInput( PTMuiItem pInputStruc );

	private:
		long	mInitCallCount;
		long 	mInputCallCount;
};


class MuiLingoConverter 
{
	public:
		MuiLingoConverter( void );
		~MuiLingoConverter( void ) {};
		
		// util methods
		static TMuiSymbol		muiWindowTypeToMuiSym( TMuiWindowType layoutMode );
		static TMuiWindowType	muiSymToWindowType( TMuiSymbol muiSym );

		static TMuiSymbol		muiLayoutModeToMuiSym( TMuiLayoutType layoutMode );
		static TMuiLayoutType	muiSymToLayoutMode( TMuiSymbol muiSym );

		static TMuiSymbol		muiWidgetTypeToMuiSym( TMuiWidgetType muiType );
		static TMuiWidgetType	muiSymToWidgetType( TMuiSymbol muiSym );
};

///////////////////////////////////////////////////////////////////////////////////
//
// Resource Helpers
//
///////////////////////////////////////////////////////////////////////////////////

// This resource helper opens up your Xtras resource file in an exception safe
// manner.  Here is an example:

/*

// open res file and grab a resource
{
	MoaRezHelper openResourceFilePlease;

#ifdef MACINTOSH
	aHandle = GetResource( 'BLAH', ID );
#else
	aResource = LoadResource( (HMODULE)openResourceFilePlease->GetFileRef(), hRSRC );
#endif
}

// resource file is closed when we come out of scope.
*/


// This works the same way as the template based helpers.
class MoaRezHelper
{
	public:
		MoaRezHelper( void );
		virtual ~MoaRezHelper( void );

		// Accessor
		XtraResourceCookie 	GetFileRef( void ) { return mFileRef; }

	private:
		XtraResourceCookie 	mFileRef,	// Returned from begin
							mCookie;	// used for restore

};


// This test two MoaMmValues by coersing them to strings and comparing them!
// This means that a long = 200 and a string "200" are equal!
MoaBoolParam MoaMmValuesAreEqual( const MoaMmValue& value1, const MoaMmValue& value2 );

// Windows compiler can't handle assigment to a long of characters (i.e. 'PICT')
#ifdef MACINTOSH
#define MMToken( a, b, c, d ) (((a)<<24) | ((b)<<16) | ((c)<<8) | (d))
#endif

#ifdef WINDOWS
#define MMToken( a, b, c, d ) (((d)<<24) | ((c)<<16) | ((b)<<8) | (a))
#endif

#ifdef WINDOWS
	#if( _MSC_VER < 1020 )
	#pragma warning( default : 4290 )
	#endif
#endif

#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma pop
#endif 


#endif // _H_MuiHelper

// EOF
