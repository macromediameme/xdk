
#ifndef _H_XWinHelp
#define _H_XWinHelp

/* ================================================================================

	XWinHelp.h    $Revision: 2 $

	Copyright (c) 1997 Macromedia, Inc.  All Rights Reserved
	
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
	Provides generally useful C++ classes for accessing common toolbox functionality.
	
	History:

	06jan99 AGS Added casts to fix VC6 warnings.
	24sep98	LLB	Added CMoaMmGCSaver, CWinClipSetAndRestore, CWinOriginSetAndRestore,
				CWinPenSetAndRestore, CWinBrushSetAndRestore, WinToMoaModifiers, 
				MoaToWinModifiers and WinGetModifierState.
	06mar98	alx	Added AntiAliasFontBlocker
	10dec97	alx	Added WinIsKeyDown
	03oct97	alx	Created

=================================================================================== */

#ifdef WINDOWS

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

#ifndef  _WINDOWS_
#include <windows.h>
#endif

///////////////////////////////////////////////////////////////////////////////////
//
// Defines
//
///////////////////////////////////////////////////////////////////////////////////


// this class stops antialiasing temporarily
class AntiAliasFontBlocker
{
	public:
		AntiAliasFontBlocker( void ) : mOld( FALSE )
		{
			::SystemParametersInfo( SPI_GETFONTSMOOTHING, 0, &mOld, 0 ); 
			::SystemParametersInfo( SPI_SETFONTSMOOTHING, FALSE, NULL, 0 ); 
		}

		~AntiAliasFontBlocker( void )
		{
			// restore
			::SystemParametersInfo( SPI_GETFONTSMOOTHING, mOld, NULL, 0 ); 
		}

	private:
		BOOL	mOld;
};


class HandleLocker
{
	public:
		HandleLocker( HGLOBAL handleToLock ) :
			mHandle( handleToLock ),
			mVoidPtr( NULL )
		{
			// lock handle
			if( mHandle )
			{
				mVoidPtr = ::GlobalLock( mHandle );
				if( !mVoidPtr )
					kThrowMoaException( CMoaInvalidArgument );
			}
		}
			
		~HandleLocker( void )
		{
			if( mHandle )
				::GlobalUnlock( mHandle );	// don't check for error
			
			mVoidPtr = NULL;
		}
		
		PMoaVoid GetVoidPtr( void ) { return mVoidPtr; }
		
	private:
		HGLOBAL		mHandle;
		PMoaVoid	mVoidPtr;
};


///////////////////////////////////////////////////////////////////////////////////
//
// CWinClipSetAndRestore
//
///////////////////////////////////////////////////////////////////////////////////
class CWinClipSetAndRestore
{

///////////////////////////////////////////////////////////////////////////////////
// Helpers
///////////////////////////////////////////////////////////////////////////////////
	private:
		void CWinClipSetAndRestore::SaveClipRgn(HDC hDC)
		{
			mhOldClipRgn = CreateRectRgn(0, 0, 0, 0);
			if (mhOldClipRgn)
			{
				if (!GetClipRgn(hDC, mhOldClipRgn))
				{
					// no clip so save null clipregion
					DeleteObject(mhOldClipRgn);
					mhOldClipRgn = NULL;
				}
			}
		}

///////////////////////////////////////////////////////////////////////////////////
// Construction and Destruction
///////////////////////////////////////////////////////////////////////////////////
	public:
		CWinClipSetAndRestore(HDC hDC, const RECT* pClipRect = NULL)
		{
			SaveClipRgn(hDC);
			if (pClipRect)
			{
				mhNewClipRgn = CreateRectRgn(pClipRect->left,  pClipRect->top,
											 pClipRect->right, pClipRect->bottom);
				SelectClipRgn(hDC, mhNewClipRgn);
			}
			mhDC = hDC;
		}

		CWinClipSetAndRestore(HDC hDC, HRGN clipRgn = NULL)
		{
			SaveClipRgn(hDC);
			if (clipRgn)
				SelectClipRgn(hDC, clipRgn);
			mhNewClipRgn = NULL;
			mhDC = hDC;
		}

		~CWinClipSetAndRestore()
		{
			SelectClipRgn(mhDC, mhOldClipRgn);

			if (mhNewClipRgn)
				DeleteObject(mhNewClipRgn);
		}

///////////////////////////////////////////////////////////////////////////////////
// Data
///////////////////////////////////////////////////////////////////////////////////
	private:
		HDC  mhDC;
		HRGN mhOldClipRgn;
		HRGN mhNewClipRgn;
};


///////////////////////////////////////////////////////////////////////////////////
//
// CWinOriginSetAndRestore
//
///////////////////////////////////////////////////////////////////////////////////
class CWinOriginSetAndRestore
{

///////////////////////////////////////////////////////////////////////////////////
// Helpers
///////////////////////////////////////////////////////////////////////////////////
	private:
		void CWinOriginSetAndRestore::SaveOldOrigin(HDC hDC)
		{
			GetViewportOrgEx(hDC, &mOldOrigin);
		}

///////////////////////////////////////////////////////////////////////////////////
// Construction and Destruction
///////////////////////////////////////////////////////////////////////////////////
	public:
		CWinOriginSetAndRestore(HDC hDC, const POINT* pNewOrigin = NULL)
		{
			SaveOldOrigin(hDC);
			if (pNewOrigin)
				SetViewportOrgEx(hDC, pNewOrigin->x, pNewOrigin->y, NULL);

			mhDC = hDC;
		}

		~CWinOriginSetAndRestore()
		{
			SetViewportOrgEx(mhDC, mOldOrigin.x, mOldOrigin.y, NULL);
		}

///////////////////////////////////////////////////////////////////////////////////
// Data
///////////////////////////////////////////////////////////////////////////////////
	private:
		HDC		mhDC;
		POINT	mOldOrigin;
};


///////////////////////////////////////////////////////////////////////////////////
//
// CWinPenSetAndRestore
//
///////////////////////////////////////////////////////////////////////////////////
class CWinPenSetAndRestore
{

///////////////////////////////////////////////////////////////////////////////////
// Helpers
///////////////////////////////////////////////////////////////////////////////////
	private:
		void CWinPenSetAndRestore::DoSelectPen(HDC hDC, HPEN hNewPen)
		{
			if (hNewPen)
				mhOldPen = (HPEN)SelectObject(hDC, hNewPen);
			else
				mhOldPen = NULL;
		}

///////////////////////////////////////////////////////////////////////////////////
// Construction and Destruction
///////////////////////////////////////////////////////////////////////////////////
	public:
		CWinPenSetAndRestore(HDC hDC, int penStyle,
							 int penWidth, COLORREF penColor)
		{
			HPEN hNewPen = CreatePen(penStyle, penWidth, penColor);
			DoSelectPen(hDC, hNewPen);
			mbDelete = true;
			mhDC = hDC;
		}

		CWinPenSetAndRestore(HDC hDC, HPEN hPen = NULL)
		{
			HPEN hNewPen = (hPen ? hPen : (HPEN)GetStockObject(BLACK_PEN));
			DoSelectPen(hDC, hNewPen);
			mbDelete = false;
			mhDC = hDC;
		}

		~CWinPenSetAndRestore()
		{
			HPEN hPen = (mhOldPen ? (HPEN)SelectObject(mhDC, mhOldPen) : NULL);

			if (mbDelete && hPen)
				DeleteObject(hPen);
		}

///////////////////////////////////////////////////////////////////////////////////
// Data
///////////////////////////////////////////////////////////////////////////////////
	private:
		HDC  mhDC;
		HPEN mhOldPen;
		bool mbDelete;
};


///////////////////////////////////////////////////////////////////////////////////
//
// CWinBrushSetAndRestore
//
///////////////////////////////////////////////////////////////////////////////////
class CWinBrushSetAndRestore
{
///////////////////////////////////////////////////////////////////////////////////
// Helpers
///////////////////////////////////////////////////////////////////////////////////
	private:
		void CWinBrushSetAndRestore::DoSelectBrush(HDC hDC, HBRUSH hNewBrush)
		{
			if (hNewBrush)
				mhOldBrush = (HBRUSH)SelectObject(hDC, hNewBrush);
			else
				mhOldBrush = NULL;
		}

///////////////////////////////////////////////////////////////////////////////////
// Construction and Destruction
///////////////////////////////////////////////////////////////////////////////////
	public:
		CWinBrushSetAndRestore(HDC hDC, COLORREF brushColor)
		{
			HBRUSH hNewBrush = CreateSolidBrush(brushColor);
			DoSelectBrush(hDC, hNewBrush);
			mbDelete = true;
			mhDC = hDC;
		}

		CWinBrushSetAndRestore(HDC hDC, HBRUSH hBrush = NULL)
		{
			HBRUSH hNewBrush = (hBrush ? hBrush : (HBRUSH)GetStockObject(NULL_BRUSH));
			DoSelectBrush(hDC, hNewBrush);
			mbDelete = false;
			mhDC = hDC;
		}

		~CWinBrushSetAndRestore()
		{
			HBRUSH hBrush = (mhOldBrush ? (HBRUSH)SelectObject(mhDC, mhOldBrush) : NULL);

			if (mbDelete && hBrush)
				DeleteObject(hBrush);
		}

///////////////////////////////////////////////////////////////////////////////////
// Data
///////////////////////////////////////////////////////////////////////////////////
	private:
		HDC		mhDC;
		HBRUSH	mhOldBrush;
		bool	mbDelete;
};


///////////////////////////////////////////////////////////////////////////////////
//
// CMoaMmGCSaver
//
///////////////////////////////////////////////////////////////////////////////////
class CMoaMmGCSaver
{
	public:
		CMoaMmGCSaver(ConstPMoaMmNativeGCInfo pNativeGC, ConstPMoaRect pMoaClipRect,
					   ConstPMoaPoint pMoaOrigin)
		{
			POINT	winOrigin;
			RECT	winClip;
			HDC		hDC = (HDC)pNativeGC->data.win_window.hDC;
			
			if (hDC)
			{
				MoaToWinPoint(pMoaOrigin, &winOrigin);
				MoaToWinRect(pMoaClipRect, &winClip);

				mpOriginSaver = new CWinOriginSetAndRestore (hDC, &winOrigin);
				mpClipSaver	  = new CWinClipSetAndRestore	(hDC, &winClip);
				mpBrushSaver  = new CWinBrushSetAndRestore	(hDC);
				mpPenSaver	  = new CWinPenSetAndRestore	(hDC);
			}
			else
			{
				mpPenSaver		= NULL;
				mpBrushSaver	= NULL;
				mpClipSaver		= NULL;
				mpOriginSaver	= NULL;
			}
			
		}

		~CMoaMmGCSaver()
		{
			if (mpPenSaver)		{ delete mpPenSaver; }
			if (mpBrushSaver)	{ delete mpBrushSaver; }
			if (mpClipSaver)	{ delete mpClipSaver; }
			if (mpOriginSaver)	{ delete mpOriginSaver; }
		}

	private:
		CWinOriginSetAndRestore*	mpOriginSaver;
		CWinClipSetAndRestore*		mpClipSaver;
		CWinBrushSetAndRestore*		mpBrushSaver;
		CWinPenSetAndRestore*		mpPenSaver;
};

inline MoaBool	WinIsKeyDown( unsigned short key )
{
	// check for most significant bit, this is whether or not key is currently down
	MoaShort result = ::GetAsyncKeyState( key );
	
	if( result & 0x8000 )	// top of short
		return TRUE;
	else
		return FALSE;
}

inline MoaLong WinToMoaModifiers(MoaLong winModifiers)
{
	return (((winModifiers & VK_SHIFT)	 ? kMoaMmModifier_Shift								 : 0)	|
            ((winModifiers & VK_CONTROL) ? (kMoaMmModifier_Control | kMoaMmModifier_Command) : 0)	|
            ((winModifiers & VK_MENU)	 ? (kMoaMmModifier_Alt	   | kMoaMmModifier_Option)  : 0));
}

inline MoaLong MoaToWinModifiers(MoaLong moaModifiers)
{
	return (((moaModifiers & kMoaMmModifier_Shift)								? VK_SHIFT	 : 0)	|
            ((moaModifiers & (kMoaMmModifier_Control | kMoaMmModifier_Command)) ? VK_CONTROL : 0)	|
            ((moaModifiers & (kMoaMmModifier_Alt	 | kMoaMmModifier_Option))	? VK_MENU	 : 0));
}

inline MoaLong WinGetModifierState()
{
	return ((WinIsKeyDown(VK_SHIFT)	  ?	VK_SHIFT	: 0)	|
			(WinIsKeyDown(VK_CONTROL) ?	VK_CONTROL	: 0)	|
			(WinIsKeyDown(VK_MENU)    ?	VK_MENU		: 0));
}


#endif // !WINDOWS
#endif // !_H_XWinHelp

// EOF
