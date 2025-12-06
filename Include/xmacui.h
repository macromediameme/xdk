
#ifndef _H_XMacUI
#define _H_XMacUI

/* ================================================================================

	XMacUI.h    $Revision: 2 $

	Copyright (c) 1994, 1995, 1996, 1997 Macromedia, Inc.  All Rights Reserved
	
	You may utilize this source file to create and compile object code for use
	within products you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
	WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
	INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
	PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
	FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
	USE OR INABILITY TO USE THIS CODE.
	
	Purpose:
	
	Provides some useful utilities for drawing mui compliant macintosh ui.
	
	History:

	24sep98	LLB	Now called CMacUI etc.
	18mar97	alx	Renamed includes
	18mar97	alx	Renamed includes
	08mar97	jcw	new header file format, documentation for external consumption.
	11dec96	alx	Added DrawButtonFrame and related routines, stubs
	25nov96	alx	Broken out from MuiCtrl.cpp

=================================================================================== */

#ifdef MACINTOSH

///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////

#ifndef __MACTYPES__
#include <MacTypes.h>
#endif

#ifndef _H_XMuiUI
#include "XMuiUI.h"
#endif

#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma push
	#pragma pointers_in_D0
#endif 


///////////////////////////////////////////////////////////////////////////////////
//
// CMacUI Declares
//
///////////////////////////////////////////////////////////////////////////////////

// DO NOT INSTATIATE THIS CLASS -- contains some drawing routines
class CMacUI
{
// --------------------------------------------------------------------------------
// Construction and Destruction
// --------------------------------------------------------------------------------
	private:
		CMacUI( void )	{}
		~CMacUI( void ) {}

// --------------------------------------------------------------------------------
// Drawing routines
// --------------------------------------------------------------------------------
	public:
		static void 	DrawFrame( const Rect& ,
								   CMuiUI::FrameStyle frameStyle = CMuiUI::kFlatFrameAndSunkenBevel);
		static void 	DrawRoundFrame( const Rect&, short tweak = 0);
		static void		DrawButtonOutline( const Rect&, Boolean enabled = true );

// --------------------------------------------------------------------------------
// Private routines
// --------------------------------------------------------------------------------
	private:		
		static Boolean	Use3D( void ) { return true; }
		static short	CalcCornerRadius( const Rect& theRect, Boolean small = false );
};


#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma pop
#endif 

#endif // MACINTOSH
#endif	// _H_XMacUI

// EOF
