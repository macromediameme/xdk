/*==========================================================================\
|                                                                           |
|                   Copyright (c) 1994-1998, Macromedia, Inc.               |
|                                                                           |
|	You may utilize this source file to create and compile object code for 	|
|	use within products you may create.  THIS CODE IS PROVIDED "AS IS", 	|
|	WITHOUT WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED 		|
|	WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A|
|	PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE |
|	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES 	|
|	ARISING OUT OF YOUR USE OR INABILITY TO USE THIS CODE.					|
|                                                                           |
\==========================================================================*/

#ifndef	NO_PRAGMA_ONCE
#pragma	once
#endif

/****************************************************************************
/ Filename
/   $Workfile: drivalue.h $
/
/ Version:
/   $Revision: 2 $
/
/ Purpose
/	MoaDrValue services interface definitions.
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/drivalue.h $
/   
/   2     6/23/99 11:54 AM Greggy
/   Checkin to synchronize revision numbers.
/   
/   4     10/19/98 11:25 AM Mroeder
/   Changed header from "Confidential" to "You may use..." because these
/   files are in the XDK. Updated copyright notice to cover 1998. 
/   
/   3     8/20/98 8:27p Sallen
/   added IMoaDrMediaValue
/   
/   2     1/30/98 10:51a Greggy
/   Unified header format. Based the guard tag directly on the filename.
/   
/	20nov96	esg	added SoundRef value conversion	
/	18nov96 esg split from IMoaDrUtils & driservc.h
****************************************************************************/

#ifndef	DRIVALUE_H
#define	DRIVALUE_H


#include "moaxtra.h"	 	/* MOA shell */
#include "moastdif.h"		/* MOA standard interfaces */
#include "drtypes.h"		/* multimedia types */


#ifdef	__cplusplus
extern "C" {
#endif


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma push
	#pragma pointers_in_D0
#endif /* MACINTOSH && MWERKS && !powerc */

/* ----------------------------------------------------------------------------
/
/	IMoaMmValue - MoaMmValue services interface
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaDrValue: 151A5780-32BD-11d0-8151-00AA005F3C08 */
DEFINE_GUID(IID_IMoaDrValue, 0xC479AE20L, 0x41B2, 0x11D0, 0x96, 0xBF, 
								0x00, 0x05, 0x9A, 0x80, 0xE8, 0x2F);
#undef INTERFACE
#define INTERFACE IMoaDrValue

DECLARE_INTERFACE_(IMoaDrValue, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
		
/* Description
This interface provides Director-specific value types.  It complements the
features of the <tt>IMoaMmValue</tt> interface, providing application-specific
services to Xtras.
*/

	STDMETHOD(ValueToCMRef)(THIS_ 
		ConstPMoaMmValue pValue,  /* Pointer to a cast member
reference type */
		PMoaDrCMRef pCMRef)  /* Pointer to a MoaDrCMRef 
to receive the result */
		PURE;

/* Category
Data conversion
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>successful</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" 
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: 
<TT>CMRef</TT> expected
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the <tt>MoaDrCMRef </tt>for a cast member reference-type
<tt>MoaMmValue</tt>.  <tt><i>pCMRef </i></tt>is a pointer to a <tt>MoaDrCMRef
</tt>to receive the result.   Returns <tt>kMoaDrErr_CastMemberExpected </tt>if
<tt><i>pValue </i></tt>is not an cast member reference-type value.<p>
*/

	STDMETHOD(CMRefToValue)(THIS_ 
		ConstPMoaDrCMRef pCMRef,  /* Pointer to a <tt>ConstPMoaDrCMRef</tt> 
to be used as the basis for the new value */
		PMoaMmValue pValue)  /* Pointer to <tt>MoaMmValue</tt> to receive the result */
		PURE;

/* Category
Data conversion
*/

/* Description
Creates a new cast member reference-type <tt>MoaMmValue </tt>from a
<tt>MoaDrCMRef</tt>.  <tt><i>pCMRef </i></tt>is a pointer to a <tt>MoaDrCMRef
</tt>to be used as the basis for the new value.  <tt><i>pValue
</i></tt>contains a pointer to a <tt>MoaMmValue </tt>to receive the result.
This call populates the <tt>MoaMmValue </tt>at <tt><i>pValue </i></tt>with a
new <tt>MoaMmValue</tt>, overwriting any current value.  Make sure to release
any preexisting value before making this call.  The caller is responsible for
releasing the returned value using <tt>IMoaMmUtils::ValueRelease()</tt>.
*/

	STDMETHOD(ValueToSpriteRef)(THIS_
		ConstPMoaMmValue pValue,
		PMoaDrSpriteRef pSRef)
		PURE;
		
	STDMETHOD(SpriteRefToValue)(THIS_
		ConstPMoaDrSpriteRef pSRef,
		PMoaMmValue	pValue)
		PURE;

	STDMETHOD(ValueToCastLibRef)(THIS_
		ConstPMoaMmValue pValue,
		PMoaDrCastLibRef pCLRef)
		PURE;
		
	STDMETHOD(CastLibRefToValue)(THIS_
		ConstPMoaDrCastLibRef pCLRef,
		PMoaMmValue	pValue)
		PURE;
		
	STDMETHOD(ValueToSoundSpriteRef)(THIS_
		ConstPMoaMmValue pValue,
		PMoaDrSoundSpriteRef pSRef)
		PURE;
		
	STDMETHOD(SoundSpriteRefToValue)(THIS_
		ConstPMoaDrSoundSpriteRef pSRef,
		PMoaMmValue	pValue)
		PURE;

};

typedef IMoaDrValue FAR * PIMoaDrValue;

/* ---------------------------------------------------------------------------- */

#undef INTERFACE

/* ----------------------------------------------------------------------------
/
/	IID_IMoaDrMediaValue - value services interface for accessing media 
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaDrMediaValue: BA9FA4A5-363E-11d2-AA59-00A0C9091428 */
DEFINE_GUID(IID_IMoaDrMediaValue, 
0xba9fa4a5, 0x363e, 0x11d2, 0xaa, 0x59, 0x0, 0xa0, 0xc9, 0x9, 0x14, 0x28);
								
#undef INTERFACE
#define INTERFACE IMoaDrMediaValue

DECLARE_INTERFACE_(IMoaDrMediaValue, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
		
/* Description
This interface provides Director-specific value types for media.  It complements the
features of the <tt>IMoaDrValue</tt> interface, providing application-specific
services to Xtras.
*/

	STDMETHOD(ValueToMedia)(THIS_ 
		ConstPMoaMmValue pValue,  /* Pointer to a value */
		MoaHandle *phMediaData)  /* Pointer to handle to receive the media data */
		PURE;

	STDMETHOD(MediaToValue)(THIS_ 
		const MoaHandle hMediaData,  /* Pointer to a handle which has the media data */
		PMoaMmValue pValue)  /* Pointer to <tt>MoaMmValue</tt> to receive the result */
		PURE;

	STDMETHOD(ValueToPicture)(THIS_ 
		ConstPMoaMmValue pValue,  /* Pointer to a value */
		MoaHandle *phPictureData)  /* Pointer to handle to receive the media data */
		PURE;

	STDMETHOD(PictureToValue)(THIS_ 
		const MoaHandle hPictureData,  /* Pointer to a handle which has the media data */
		PMoaMmValue pValue)  /* Pointer to <tt>MoaMmValue</tt> to receive the result */
		PURE;

/* Category
Data conversion
*/


};

typedef IMoaDrMediaValue FAR * PIMoaDrMediaValue;

/* ---------------------------------------------------------------------------- */

#undef INTERFACE



#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#ifdef	__cplusplus
}
#endif


#endif	/* DRIVALUE_H */
