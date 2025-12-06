/*==========================================================================\
|																			|
	Copyright (c) 1996-1998, Macromedia, Inc.  All rights reserved.
	
	You may utilize this source file to create and compile object code for 
	use within products you may create.  THIS CODE IS PROVIDED "AS IS", 
	WITHOUT WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED 
	WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A
	PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE 
	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES 
	ARISING OUT OF YOUR USE OR INABILITY TO USE THIS CODE.
|																			|
\==========================================================================*/

#ifndef NO_PRAGMA_ONCE
#pragma once
#endif

/****************************************************************************
/ Filename
/	$Workfile: driservc.h $
/
/ Version:
/	$Revision: 5 $
/
/ Purpose
/	Director services callback interface definitions.
/	Director-specific common interface defintions.
/
/ Notes
/
/ Modification History
/	$Log: /Xtras/Include/driservc.h $
/   
/   5     1/05/00 12:03p Greggy
/   Changed the input filename parameter to ResolveFileName to a const.
/	
/	4	  11/16/99 11:06a Greggy
/	Added IMoaDrSound2 with a new PauseSound method.
/	
/	3	  10/05/99 10:48a Greggy
/	Exposed animation engine state change to MOA notification clients.
/	
/	2	  6/23/99 11:54 AM Greggy
/	Checkin to synchronize revision numbers.
/	
/	24	  5/2/99 11:22 PM Davidc
/	Add IMoaDrMovieStage; update Flash Xtra to utilize.
/	
/	23	  11/4/98 4:25 PM Jcorbett
/	Added IMoaDrCursor to allow Xtras to set the sprite cursor in Director.
/	
/	22	  10/19/98 12:16 PM Mroeder
/	Replaced "Confidential" header with "You may use" header and updated
/	copyright notice to 1998 for use in D7 xdk. 
/	
/	21	  10/14/98 11:06a Egreenfield2
/	removed waters only code
/	
/	20	  9/15/98 3:04p Kday
/	Added DP calls, Moa interfaces, and dxMgr implementations of
/	thread-switching support calls (for the activex control's apartment
/	model).
/	
/	19	  7/12/98 4:14p Cnuuja
/	
/	18	  5/12/98 2:29p Jcorbett
/	two errors had the same number
/	
/	17	  5/12/98 11:40a Jcorbett
/	IMoaDrPreferenceAccess now uses an officially allocated MOAError block
/	0x1490- >0x149f
/	
/	16	  5/11/98 8:39p Jcorbett
/	ascii comment problem on mac
/	
/	15	  5/11/98 6:52p Jcorbett
/	IMoaPreferenceAccess definition--added here so 3rd party developers can
/	use it.
/	
/	14	  5/05/98 2:44p Egreenfield2
/	removed inheritance from MoaDrMovie2 to eliminate VTable mismatch
/	beteen c and c++
/	
/	13	  1/30/98 10:51a Greggy
/	Unified header format. Based the guard tag directly on the filename.
/	
	13nov97 AGS Added protection against precompilation.
	20feb97 esg added CMoaDrAlphaData GUID.
	19feb97 esg added IMoaDrRTAccess, IMoaDrAlphaData
	02feb97 esg added cast params to style access.
	02feb97 esg added channel proxy and volume control to DrSound
	02feb97 esg added DrMoaJavaServices
	02feb97 esg moved Mm notifications into Dr.
	21nov96 esg added IMoaDrSound
	19nov96 esg added IMoaDrPaletteAccess interface
	16nov96 esg added Dr Notification types.	
	28feb96 dac IMoaDrPropAndMediaOwner-->IMoaDrMediaOwner
				CallHandlerInActiveMovie()-->CallHandler()
	19feb96 dac reformat
	29nov95 mes io notification
	 2oct95 dws Major munge. Put Director-specific stuff from dxtypes.h here
	13sep95 JT: For Utils added: NewPropListValue, AppendValueToPropList,
				ValueReleaseStringHandle,
					CallHandlerInCurrentMovie
				For CastMem added: CallHandler
				Elimated EvaluateHandler
	24aug95 ejs Change IMoaDrInStream, IMoaDrOutStream to IMoaStream
	18apr95 dac add initial defs for Movie, Player interfaces/classes.
	17apr95 dac update for new IMoaHandle.
	 5apr95 dac Created.
****************************************************************************/

#ifndef DRISERVC_H
#define DRISERVC_H


#ifdef PRECOMPILED_HEADER
	#error "moaxtra.h should not be precompiled"
#endif


#include "drtypes.h"
#include "mmiservc.h"
#include "MIXSND.H"


#ifdef	__cplusplus
extern "C" {
#endif


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma push
	#pragma pointers_in_D0
#endif /* MACINTOSH && MWERKS && !powerc */



/* ----------------------------------------------------------------------------
/
/	Director specific notification types
/
/ -------------------------------------------------------------------------- */

DEFINE_GUID(NID_DrNCastMemberModified, 0x010840D0L, 0x3E12, 0x11D0, 0x99,
							0xA6, 0x00, 0x05, 0x9A, 0x80, 0xE8, 0x2F);
DEFINE_GUID(NID_DrNCastSelectionChanged, 0x03F13356L, 0x3E12, 0x11D0, 0x99,
							0xA6, 0x00, 0x05, 0x9A, 0x80, 0xE8, 0x2F);
DEFINE_GUID(NID_DrNScoreModified, 0x065EBFA0L, 0x3E12, 0x11D0, 0x99, 0xA6, 0x00,
							0x05, 0x9A, 0x80, 0xE8, 0x2F);
DEFINE_GUID(NID_DrNScoreSelectionChanged, 0x092315BAL, 0x3E12, 0x11D0, 0x99, 0xA6,
							0x00, 0x05, 0x9A, 0x80, 0xE8, 0x2F);
DEFINE_GUID(NID_DrNCuePointPassed, 0x66C0FB00L, 0x46C9, 0x11D0, 0xBD, 0xEB, 0x00, 0x05,
							0x9A, 0x80, 0xE8, 0x2F);

DEFINE_GUID(NID_DrNPaletteChanged, 0x0FF83488L, 0x3E12, 0x11D0, 0x99, 0xA6, 0x00,
							0x05, 0x9A, 0x80, 0xE8, 0x2F);
DEFINE_GUID(NID_DrNStep, 0x12ABC686L, 0x3E12, 0x11D0, 0x99, 0xA6, 0x00, 0x05,
							0x9A, 0x80, 0xE8, 0x2F);
DEFINE_GUID(NID_DrNIdle, 0x3B881B5EL, 0x3E12, 0x11D0, 0x99, 0xA6, 0x00, 0x05,
							0x9A, 0x80, 0xE8, 0x2F);

DEFINE_GUID(NID_DrNDocumentOpened, 0x90366D2CL, 0x5CB2, 0x11D0, 0xA1, 0xBD, 0x00, 0x05,
							0x9A, 0x80, 0xE8, 0x2F);
DEFINE_GUID(NID_DrNDocumentClosed, 0xA7B849FCL, 0x5CB2, 0x11D0, 0xA1, 0xBD, 0x00, 0x05,
							0x9A, 0x80, 0xE8, 0x2F);							
DEFINE_GUID(NID_DrNAnimationState, 0x8338a8ea, 0x7ae8, 0x11d3, 0xb3, 0xdd, 0x40, 0x2, 0xcf, 0x0, 0x0, 0x0);


/* ----------------------------------------------------------------------------

/
/	IMoaDrMediaOwner
/
/ -------------------------------------------------------------------------- */

/* IID_IMoaDrMediaOwner: AC542D520003AEED00000800072C6326 */
DEFINE_GUID(IID_IMoaDrMediaOwner, 0xAC542D52L, 0x0003, 0xAEED, 0x00,
				0x00, 0x08, 0x00, 0x07, 0x2C, 0x63, 0x26);

#undef INTERFACE
#define INTERFACE IMoaDrMediaOwner

DECLARE_INTERFACE_(IMoaDrMediaOwner, IMoaMmPropOwner)

/* Description
<p>
The <tt>IMoaDrMediaOwner</tt> interface adds three methods to the
<tt>IMoaMmPropOwner</tt> interface, <tt>AttachMedia()</tt>,
<tt>GetMedia()</tt>, and <tt>SetMedia()</tt>.  These methods enable an Xtra
to retrieve media information from objects such as cast members and movies.<p>
<p>
Methods of this interface include pointers to a <tt>MoaDrMediaInfo</tt>
structure as parameters. Before a <tt>GetMedia()</tt>, <tt>SetMedia()</tt>, or
<tt>AttachMedia()</tt> call, use <tt>IMoaDrUtils::NewMediaInfo() </tt>to fill
out the structure, specifying NULL for the <tt>aux </tt>field and
<tt>kMoaDrMediaOpts_None </tt>for the <tt>options </tt>field. Using this call
forces you to fill out all the needed parameters.  The <tt>aux </tt>information
currently applies only when setting image media.<p>
<p>
The <tt>formatSymbol</tt> and <tt>labelSymbol</tt> members of this structure
are <tt>MoaMmSymbols</tt>.	These symbols are obtained from strings using
the host application symbol dictionary, accessed through the
<tt>StringToSymbol()</tt> method of the <tt>IMoaMmUtils</tt> interface<p>
<p>
The <tt>labelSymbol</tt> refers to the specific chunk of media data you want
from the media owner.  These labels are generic descriptors for the content
media.	In the <tt>IMoaDrCastMem</tt> interface, which inherits from
<tt>IMoaDrMediaOwner</tt>, the labels used are different than the cast member
types.	For example, a film loop cast member has score media label, a bitmap
cast member has an image media label, and so on. These generic labels are used
to allow multiple representations for specific media data types.  For example,
a bitmap is really just one type of image.	<p>
<p>
The <tt>formatSymbol</tt> refers to the specific media data type you want to
get or set.  In Director, the media types represented by these sy mbols are
largely platform-specific, except for opaque handles and strings.  For example,
a bitmap cast member provides image media.	On the Macintosh, the format for
getting and setting this data is a Macintosh PICT.	You use the
<tt>formatSymbol</tt> <tt>"macPICT" </tt>to access this data.  On Windows,
packed DIBs are supported; you use the <tt>formatSymbol</tt> <tt>"winDIB"
</tt>to access this data.<p>
<p>
This mechanism uses symbols rather than hardwired constants for future
expansion of media access support.	The goal is to allow Xtra media assets to
export arbitrary labels and formats of their media to other Xtras.	(Currently,
Xtras can only access media data of other Xtras through the opaque handle
provided by composite media. label.  So, for example, in the future, someone
may make a 3D plug-in, and other Xtras could use <tt>GetMedia() </tt>to get
the "geometry" (label) media in "DXF" (format)).<p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetProp)(THIS_
		MoaMmSymbol symbol,  /* <tt>MoaMmSymbol</tt> representing the property
	to get */
		PMoaMmValue pPropValue)  /* Pointer to a <tt>MoaMmValue</tt> to receive
	the property's value */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355><TT>Property</TT> exists and
value was returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists but couldn't get due
to internal err
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for string
value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for other
value data
</TD></TR>
</TABLE>
*/

/* Description
<p>
Retrieves the value of a specified property.<p>
*/

	STDMETHOD(SetProp)(THIS_
		MoaMmSymbol symbol,  /* <tt>MoaMmSymbol</tt> representing the property
	to set */
		ConstPMoaMmValue pPropValue)  /* Pointer to a <tt>ConstPMoaMmValue</tt>
	containing the property value */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists and value was set
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property isn't supported by this class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists, value ok, couldn't -
- internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Couldn't allocate memory for
setting string value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Couldn't allocate memory for
setting other value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_IntegerExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: integer value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_SymbolExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: symbol value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_FloatExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: float value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_StringExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: string value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PointExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: point value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_RectExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch:
<TT>MoaRect</TT> value expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: other value
expected (non-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch:
<TT>CMRef</TT> expected
</TD></TR>
</TABLE>
*/

/* Description
<p>
Sets the value of a specified property.<p>
*/

	STDMETHOD(GetMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)
		PURE;

/* Category
Media owner methods
*/

/* Description
<p>
Gets media data.  This method obtains a copy of the media associated with
an object. Before	making this call, use <tt>IMoaDrUtils::NewMediaInfo()</tt>
to fill out the media information structure, specifying NULL for the
<tt>aux</tt>field and <tt>kMoaDrMediaOpts_None </tt>for the <tt>options</tt>
field. The caller partially populates a <tt>MoaDrMediaInfo</tt> struct with
symbols indicating the requested chunk of media (<tt>labelSymbol</tt>) and
the requested format (<tt>formatSymbol</tt>).  After the call, the
<tt>mediaData</tt>field is populated with the requested data; the type of
this field depends on the format requested.  The caller then owns the data
and is responsible for disposing it, if applicable.  Typically this data is
either a <tt>MoaHandle</tt>, a Macintosh Handle or Pointer, or a Windows
global handle. <p>
*/

	STDMETHOD(SetMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)
		PURE;

/* Category
Media owner methods
*/

/* Description
<p>
Sets media data.  This method copies caller-supplied media data and associates
it with an object. Before making this call, use <tt>IMoaDrUtils::NewMediaInfo()</tt>
to fill out the media information structure, specifying NULL for the <tt>aux</tt> field
and <tt>kMoaDrMediaOpts_None</tt> for the <tt>options</tt>field.  The caller
populates a <tt>MoaDrMediaInfo </tt>structure with symbols indicating the
supplied chunk of media (<tt>labelSymbol</tt>), the supplied format
(<tt>formatSymbol</tt>), and the media data itself (<tt>mediaData</tt>).
If the label and format are supported by the object, a call to this method
copies the caller's data and replaces any existing media data for the supplied
label for the cast	member.  Since the data is copied, the caller retains
ownership of the media data passed in.	Typically, this data is either a
<tt>MoaHandle</tt>, a Macintosh Handle or pointer, or a Windows global handle. <p>
*/

	STDMETHOD(AttachMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)
		PURE;

/* Category
Media owner methods
*/

/* Description
<p>
Attaches media to an object, releasing it from the caller. Before making
this call, use <tt>IMoaDrUtils::NewMediaInfo() </tt>to fill out the media
information structure, specifying NULL for the <tt>aux</tt>field and
<tt>kMoaDrMediaOpts_None</tt>for the <tt>options</tt> field. <p>
<p>
On enter, the <tt>labelSymbol </tt>and <tt>formatSymbol</tt> fields should
be populated with symbols indicating which chunk of media is to be attach
(<tt>labelSymbol</tt>), and what format the media is supplied in
(<tt>formatSymbol</tt>).  The <tt>mediaData </tt>field should hold the data
itself (typically a <tt>MoaHandle </tt>, Macintosh Handle, or Windows global
handle) <p>
<p>
Upon return, if there is no error, the media has changed ownership and
belongs to the host application, and should no longer be referenced by the
caller.<p>
*/

};

typedef IMoaDrMediaOwner FAR * PIMoaDrMediaOwner;


/* Old synonyms for IMoaDrMediaOwner */
#define IMoaDrPropAndMediaOwner 	IMoaDrMediaOwner
#define PIMoaDrPropAndMediaOwner	PIMoaDrMediaOwner
#define IID_IMoaDrPropAndMediaOwner IID_IMoaDrMediaOwner


/* ----------------------------------------------------------------------------
/
/	IMoaDrNotificationClient - interface for receiving
/		notification from the host application.  The type
/		of notification to be received is specified by the
/		clientType.  See DRTYPES.H for the notification
/		type constants available.
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaDrNotificationClient: ACE09C3101BEE5D2000008000757DC04 */
DEFINE_GUID(IID_IMoaDrNotificationClient, 0xACE09C31L, 0x01BE, 0xE5D2, 0x00,
				0x00, 0x08, 0x00, 0x07, 0x57, 0xDC, 0x04);

#undef INTERFACE
#define INTERFACE IMoaDrNotificationClient

DECLARE_INTERFACE_(IMoaDrNotificationClient, IMoaUnknown)

/* Description
<p>
Interface for receiving notification from the host application.  The type of
notification to be received is specified by the notifyType.  See "Types" for
the notification type constants available.	See
<tt>IMoaDrUtils::RegisterNotificationClient() </tt>and
<tt>IMoaDrUtils::UnregisterNotificationClient() </tt>for information on
enabling and disabling callback notification for internal events.<p>
<p>
The <tt>IMoaDrNotificationClient</tt> interface consists of the <tt>Notify()
</tt>method.<p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(Notify)(THIS_
		MoaLong msgCode,  /* The <tt>MoaLong</tt> specifying the type of event
that occurred */
		PMoaVoid data)
		PURE;

/* Description
<p>
Handles notification from host application.  <tt><i>msgCode</i></tt>
specifies the type of event that occurred; a given <tt>notificationType</tt>
can support one or more message codes.	<tt><i>refCon </i></tt>is used to
pass additional message-specific data from the host application to the
notification client.  <p>
<p>
Valid message codes are:<p>
<p>
<tt>kMoaDrMsgCode_DocFileIO</tt>		<b>Windows(TM) version only</b><p>
<p>
Used by notification type <tt>kMoaDrNotifyType_DocFileIO</tt>.	This
notification message is sent just before a chunk read or write occurs from
or to a host application document (a movie or cast file, specifically).
For this message, <tt><i>refCon </i></tt>contains a <tt>PMoaChar</tt>
pointing to a C string containing the pathname of the filename being read
to or written from.<p>
*/

};

typedef IMoaDrNotificationClient FAR * PIMoaDrNotificationClient;

/* ----------------------------------------------------------------------------
/
/  IMoaDrMediaAccess - Generic media interface
/
/  This interface contains the core methods supported by all
/  MediaAccess classes.  MediaAccess objects, such as ScoreAccess, handle
/  communication with the media owner object to provide a task-specific
/  interface for accessing its media.
/
/ -------------------------------------------------------------------------- */

/* IID_IMoaDrMediaAccess: AC401A980000C62600000800072C6326 */
DEFINE_GUID(IID_IMoaDrMediaAccess, 0xAC401A98L, 0x0000, 0xC626, 0x00, 0x00,
				0x08, 0x00, 0x07, 0x2C, 0x63, 0x26);


#undef INTERFACE
#define INTERFACE IMoaDrMediaAccess

DECLARE_INTERFACE_(IMoaDrMediaAccess, IMoaUnknown)

/* Description
<p>
This interface contains the core methods supported by all <tt>MediaAccess</tt>
classes.  <tt>MediaAccess</tt> objects, such as <tt>ScoreAccess</tt>, handle
communication with the media owner object to provide a task-specific interface
for accessing its media.<p>
<p>
<tt>MediaAccess </tt>is typically buffered; the  <tt>MediaAccess</tt> interface
operates on a copy of media data owned by an associated
<tt>IMoaDrMediaOwner</tt> object.  Changes are only reflected in the associated
owner object when <tt>Commit()</tt> is called.	Using <tt>SetAccessInfo()</tt>,
the owner object can be changed on-the-fly, allowing you to obtain media data
from one object, modify it, and commit it back to a different object.<p>
<p>
In Director 5.0, the only type of <tt>MediaAccess </tt>interface supported is
<tt>IMoaDrScoreAccess</tt>, used for editing score data associated with a
filmloop cast member or Director movie.  Director API provides three ways to
obtain a <tt>MediaAccess </tt>interface. <p>
<p>
<ul><ul>	<tt>IMoaDrMovie::GetScoreAccess()</tt> - This method returns a score access
interface for the Director movie.<p></ul></ul>
<ul><ul>	<tt>IMoaDrCastMem::GetScoreAccess()</tt> - This method returns a score access
interface for a filmloop cast member<p></ul></ul>
<ul><ul>	<tt>IMoaDrPlayer::NewScoreAccess()</tt> - This method creates a new score
access interface without an owner.	To save the resulting score to a filmloop
cast member or movie, use <tt>IMoaDrScoreAccess::SetOwner()</tt> or
<tt>MoaDrMediaAccess::SetAccessInfo()</tt> to set the owner before
committing.</ul></ul><p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(New)(THIS)
		PURE;

/* Category
Creating
*/

/* Description
<p>
Obtains the current <tt>accessInfo </tt>for the media accessor.
<tt><i>pAccessInfo </i></tt>is a pointer to a <tt>MoaDrAccessInfo</tt>
structure to receive the information.  This call populates the structure with
the <tt>PIMoaDrMediaOwner </tt>for the media owner, the label symbol for the
media being accessed, and the format symbol for the media being accessed.
Since an interface is being supplied in this structure (<tt>pOwner</tt>), the
caller is responsible for releasing it.<p>
*/

	STDMETHOD(Refresh)(THIS)
		PURE;

/* Category
Editing
*/

/* Description
<p>
Disposes of the current working media and obtains a fresh copy of the
media data from the associated media owner object.	If there is no media owner,
the call fails and <tt>kMoaDrErr_OwnerNotSet </tt>is returned.	This call
causes you to lose any edits made to your media data since the last
<tt>Refresh() </tt>or <tt>Commit() </tt>calls.	<p>
*/

	STDMETHOD(Commit)(THIS)
		PURE;

/* Category
Editing
*/

/* Description
<p>
Commits changes made to the media being accessed back to the object
owning the media data.	Changes are not reflected in the media-owning object
unless this method is called.  For example, after creating a sequence of score
frames using <tt>IMoaDrScoreAccess</tt>, calling <tt>Commit()</tt>updates the
corresponding movie or film loop cast member.  If no media owner has been set,
this call fails and returns <tt>kMoaDrErr_OwnerNotSet</tt>.  The media owner is
set automatically if the <tt>IMoaDrScoreAccess </tt>interface was obtained
directly from the owner using a <tt>GetScoreAccess() </tt>call.  If you have
created a new ScoreAccess object from scratch (using
<tt>IMoaDrPlayer::NewScoreAccess()</tt>), it is up to you to associate the
media owner object using <tt>SetAccessInfo()</tt> (or <tt>SetOwner()</tt> in
<tt>IMoaDrScoreAccess</tt>).  The owner is the object that gets updates when
<tt>Commit() </tt>is called<p>
*/

	STDMETHOD(GetAccessInfo)(THIS_
		PMoaDrAccessInfo pAccessInfo)  /* Pointer to <tt>MoaDrAccessInfo </tt>
structure to receive information */
		PURE;

/* Category
Access Information
*/

/* Description
<p>
Obtains the current <tt>accessInfo </tt>for the media accessor.
<tt><i>pAccessInfo </i></tt>is a pointer to a <tt>MoaDrAccessInfo</tt>
structure to receive the information.  This call populates the structure with
the <tt>PIMoaDrMediaOwner </tt>for the media owner, the label symbol for the
media being accessed, and the format symbol for the media being accessed.
Since an interface is being supplied in this structure (<tt>pOwner</tt>), the
caller is responsible for releasing it.<p>
*/

	STDMETHOD(SetAccessInfo)(THIS_
		ConstPMoaDrAccessInfo pAccessInfo)	/* Pointer to a <tt>MoaDrAccessInfo</tt>
structure to receive the information */
		PURE;

/* Category
Access Information
*/

/* Description
<p>
Sets the current <tt>accessInfo </tt>for the media accessor.
<tt><i>pAccessInfo </i></tt>is a pointer to a <tt>MoaDrAccessInfo
</tt>structure containing the new access information to be used.  This call
sets a new media owner, media label, and media format for the media being
accessed.  If a <tt>mediaOwner</tt> is already set, the media accessor's hold
on the previous owner interface is released.  The caller owns the owner
interface (<tt>pOwner</tt>) provided in the structure.	<p>
<p>
You may change the <tt>accessInfo </tt>during an editing session.  For example,
you could obtain an <tt>IMoaDrScoreAccess </tt>interface for a film loop cast
member, edit the score, set the access information to different film loop cast
member (or movie), and call <tt>Commit()</tt>.	This leaves the original film
loop untouched, and updates the new filmloop or movie with the edited version
of the source film loop score.<p>
*/

};

typedef IMoaDrMediaAccess FAR * PIMoaDrMediaAccess;



/* ----------------------------------------------------------------------------
/
/  IMoaDrCastMem
/
/ -------------------------------------------------------------------------- */

/* IID_IMoaDrCastMem: AC401AB50000CD0300000800072C6326 */
DEFINE_GUID(IID_IMoaDrCastMem, 0xAC401AB5L, 0x0000, 0xCD03, 0x00, 0x00, 0x08,
				0x00, 0x07, 0x2C, 0x63, 0x26);


#undef INTERFACE
#define INTERFACE IMoaDrCastMem

DECLARE_INTERFACE_(IMoaDrCastMem, IMoaDrMediaOwner)

/* Description
<P>
The <TT>IMoaDrCastMem </TT>interface provides access to specific
cast members within a cast.<p>

<H5><A NAME="RTFToC2">Cast member properties</A> </H5><p>

<TT>IMoaDrCastMem</TT> inherits from the <TT>IMoaMmPropOwner</TT>
interface, providing for access to data through the properties
mechanism described in the &quot;Multimedia Services&quot; chapter
in the <I>Development Guide </I>document. See the &quot;Properties&quot;
section for information on the properties defined for objects
providing the <TT>IMoaDrCastMem</TT> interface. <BR>
<BR>

<H5><A NAME="RTFToC3">Cast member media types</A> </H5>

<P>
Because this interface inherits from <TT>IMoaDrMediaOwner</TT>,
you can use it to access the properties and media data associated
with a cast member.
<P>
Methods of the <TT>IMoaDrMediaOwner</TT> interface include pointers
to a <TT>MoaPrMediaInfo</TT> structure as parameters. Before a
<TT>GetMedia()</TT>, <TT>SetMedia()</TT>, or <TT>AttachMedia()</TT>
call, use <TT>IMoaDrUtils::NewMediaInfo() </TT>to fill out the
structure, specifying NULL for the <TT>aux </TT>field and <TT>kMoaDrMediaOpts_None
</TT>for the <TT>options </TT>field. Using this call forces you
to fill out all the needed parameters. The <TT>aux </TT>information
currently applies only when setting image media.
<P>
The <TT>formatSymbol</TT> and <TT>labelSymbol</TT> members of
this structure are <TT>MoaMmSymbols</TT>. These symbols are obtained
from strings using the host app symbol dictionary, accessed through
the <TT>StringToSymbol()</TT> method of the <TT>IMoaMmUtils</TT>
interface For more on how this mechanism is implemented, see the
<TT>IMoaDrMediaOwner</TT>.
<P>
Here's a brief summary of the media labels supported for Director
cast members:<P>

<table border="2">
<tr><th align="left" valign="middle" width="105"><b>Media</b></th>
<th align="left" valign="middle"><b>Label Description</b></th></tr>

<tr><td align="left" valign="top"><tt>Composite</tt></td>
<td align="left" valign="top">Cast member media data in a portable (byte-swapped) opaque
handle.</td></tr>

<tr><td align="left" valign="top"><tt>Image</tt></td>
<td align="left" valign="top">Primary image data (for a bitmap, PICT, and so on). </td></tr>

<tr><td align="left" valign="top"><tt>Text</tt></td>
<td align="left" valign="top">Text character string</td></tr>

<tr><td align="left" valign="top"><tt>TextStyles</tt></td>
<td align="left" valign="top">Text style run data</td></tr>

<tr><td align="left" valign="top"><tt>Sound</tt></td>
<td align="left" valign="top">Sound samples</td></tr>

<tr><td align="left" valign="top"><tt>Palette</tt></td>
<td align="left" valign="top">Palette entries</td></tr>

<tr><td align="left" valign="top"><tt>Score</tt></td>
<td align="left" valign="top">Score data for a movie or film loop</td></tr>
</table>

<P>
The following table provides a brief summary of the media formats
supported for Director cast members.<P>

<table border="2">
<tr><th align="left" valign="middle" width="125"><b>Media Format</b></th>
<th align="left" valign="middle"> <b>Description</b></th></tr>

<tr><td align="left" valign="top"><tt>moaHandle</tt></td>
<td align="left" valign="top">Generic <tt>MoaHandle</tt> of data</td></tr>

<tr><td align="left" valign="top"><tt>moaTEStyles</tt></td>
<td align="left" valign="top"><tt>textStyles</tt> stored in a <tt>MoaHandle</tt></td></tr>

<tr><td align="left" valign="top"><tt>macTEStyles</tt></td>
<td align="left" valign="top"><tt>textStyles</tt> in TextEdit <tt>StScrpHandle</tt> format stored in a
Macintosh handle</td></tr>

<tr><td align="left" valign="top"><tt>macPICT</tt></td>
<td align="left" valign="top">Macintosh  <tt>PicHandle</tt></td></tr>

<tr><td align="left" valign="top"><tt>macSnd</tt></td>
<td align="left" valign="top">Macintosh  <tt>sndHdl.</tt> Handle in Macintosh sound resource format.
</td></tr>

<tr><td align="left" valign="top"><tt>macColorTable</tt></td>
<td align="left" valign="top">Macintosh <tt>CTabHandle</tt> . Handle to a <tt>ColorTable</tt>
record</td></tr>

<tr><td align="left" valign="top"><tt>winDIB</tt></td>
<td align="left" valign="top">Windows packed DIB <tt>GlobalHandle</tt> with bitmap information, color
table, and bits</td></tr>

<tr><td align="left" valign="top"><tt>winWAVE</tt></td>
<td align="left" valign="top">Windows RIFF WAVE <tt>GlobalHandle</tt> . RIFF sound format.
</td></tr>

<tr><td align="left" valign="top"><tt>winPALETTE</tt></td>
<td align="left" valign="top">Windows HPALETTE <tt>GlobalHandle</tt>. RIFF palette format
</td></tr>
</table>

<P>
<A NAME="RTFToC4">Composite media </A>label
<P>
All media types support the composite label; that is, you can
get the media data for any cast member as a single, opaque portable
<TT>MoaHandle</TT>. Because Director handles the byteswapping
of these, they're safe to write out to disk and read back in on
another platform. The format for composite media is always <TT>MoaHandle</TT>.
<H6><A NAME="RTFToC5">Other media</A> labels </H6>

<P>
In addition to composite, each built-in cast member type supports
one or more other labels or formats. For example, bitmaps, PICTs,
Rich Text, and OLE support the image label (RichText and OLE are
Get-only for this); the bitmap format supported depends on the
platform (macPICT on mac, winDIB on Windows). In the future, we
may add additional formats, such as a portable pixel map format
which is identical on both platforms.
<P>
Text supports multiple labels: <TT>text</TT> to get or set the
ASCII text, <TT>textStyles</TT> (Macintosh-only) to get or set
the style data independently from the ASCII.
<P>
Both movies and cast members support the <TT>score</TT> media
label, with the format <TT>MoaHandle</TT>. This lets you get and
set the score data itself. You can attach a <TT>ScoreAccess </TT>interface
to one of these data handles using <TT>IMoaDrUtils::NewScoreAccess()</TT>.
However, if you want to edit the score of an existing movie or
cast member, it's easier just to obtain the <TT>ScoreAccess </TT>interface
directly from the object itself using<TT> IMoaDrCastMem::GetScoreAccess()</TT>,
<P>
Here's a complete list of the media labels and formats supported
by the Director cast member types:<P>

<TABLE BORDER="2">
<TR><TH ALIGN="LEFT" WIDTH=151><B>Cast member type</B></TH>
<TH ALIGN="LEFT" WIDTH=220><B>Media label</B></TH><TH ALIGN="LEFT"
WIDTH=220><B>Media format</B></TH></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>BITMAP</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT><br>
<TT>Image</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle </TT><br>
<TT>mac: macPICT</TT><br>
<TT>win: winDIB</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>FILMLOOP</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT><br>
<TT>Score</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle</TT><br>
<TT>moaHandle</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>TEXTFIELD</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT><br>
<TT>Text</TT><br><br>
<TT>TextStyles</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle </TT><br>
<TT>moaHandle	(null-terminated string)</TT><br>
<TT>mac: macTEStyles</TT><br>
<TT>mac &amp; win: moaTEStyles</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>PALETTE</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT><br>
<TT>Palette</TT><br>
<TT>Palette</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle </TT><br>
<TT>mac: macColorTable</TT><br>
<TT>win: winPALETTE</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>PICT</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT><br>
<TT>Image</TT><br>
<TT>Image</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle </TT><br>
<TT>mac: macPICT</TT><br>
<TT>win: winDIB</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>SOUND</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT><br>
<TT>Sound</TT><br>
<TT>Sound</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle </TT><br>
<TT>mac: macSnd </TT><br>
<TT>win: winWAVE</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>BUTTON</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT><br>
<TT>Text</TT><br><br>
<TT>TextStyles</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle</TT><br>
<TT>moaHandle (null-terminated string handle) </TT><br>
<TT>mac: macTEStyles </TT><br>
<TT>mac &amp; win: moaTEStyles</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>SHAPE</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>MOVIE</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>DIGITAL VIDEO</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>SCRIPT</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle</TT><br>
<TT>NOTE: Script text can be accessed using GetProp() and SetProp()</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>RICH TEXT</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT><br>
<TT>Text</TT><br><br><br><br>
<TT>Image  (Get Only)</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle</TT><br>
<TT>moaHandle  (null-terminated string handle). Set allowed only in authoring applications</TT><br>
<TT>mac: macPICT </TT><br>
<TT>win: winDIB</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>OLE</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT><br>
<TT>Image  (Get Only)</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle</TT><br>
<TT>mac: macPICT </TT><br>
<TT>win: winDIB</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>XTRA</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle</TT></TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=151><TT>TRANS</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>Composite</TT></TD>
<TD ALIGN="LEFT" VALIGN="TOP" WIDTH=220><TT>moaHandle</TT></TD></TR>
</TABLE>

<P>
<A NAME="RTFToC6">Media access in </A>sprite Xtras
<P>
Sprite Xtras, which provide cast members through extensions to
Director, only support the <TT>composite</TT> media label, which
is a combination of the Xtra's media, properties, and built-in
properties combined in an opaque format. You can get or set the
media data of any Xtra-based cast member type as a composite <TT>MoaHandle</TT>.
*/

{
	STD_IUNKNOWN_METHODS

	/* IMoaDrMediaOwner methods */

	STDMETHOD(GetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol </tt>for the property of
interest */
		PMoaMmValue pPropValue)  /* Pointer to a caller-owned <tt>MoaMmValue
</tt>structure to receive the value of the property */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists and value was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists but couldn't get due
to internal err
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for string
value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for other
value data
</TD></TR>
</TABLE>
*/

/* Description
Obtains the value of the specified cast member property. To get the symbol
from a string, use the <tt>IMoaMmUtils::StringToSymbol()</tt>. The caller
is responsible for releasing the value with<tt>IMoaMmUtils::ValueRelease()</tt>
when it is no longer needed.
*/

	STDMETHOD(SetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol </tt>for the property of
interest.*/
		ConstPMoaMmValue pPropValue)  /* Pointer to a caller-owned <tt>MoaMmValue
</tt>structure to copy the new value for the property from.*/
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Property exists and value was set
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Property isn't supported by this class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Property exists, value ok, couldn't
set--internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Couldn't allocate memory for
setting string value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Couldn't allocate memory for
setting other value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_IntegerExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Type mismatch: integer value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_SymbolExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Type mismatch: symbol value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_FloatExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Type mismatch: float value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_StringExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Type mismatch: string value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PointExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Type mismatch: point value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_RectExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Type mismatch: rect value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Type mismatch: other value
expected (non-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=343>Type mismatch:
<TT>CMRef</TT> value expected
</TD></TR>
</TABLE>
*/

/* Description
Sets a cast member	property to a new value.  To get the symbol from a string,
use the <tt>IMoaMmUtils::StringToSymbol()</tt>., The caller continues to
maintain ownership of the value passed in at <tt><i>pPropValue</i></tt>, and
should release it using <tt>IMoaMmUtils::ValueRelease()</tt> when it is no
longer needed.
*/

	STDMETHOD(GetMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)  /* Pointer to a caller-owned media
information structure */
		PURE;

/* Category
Media owner methods
*/

/* Description
Gets cast member media data.  This method obtains a copy of the media
associated with a cast member. Before making this call, use
<tt>IMoaDrUtils::NewMediaInfo() </tt>to fill out the media information
structure, specifying NULL for the <tt>aux </tt>field and
<tt>kMoaDrMediaOpts_None </tt>for the <tt>options </tt>field.  The caller
partially populates a <tt>MoaDrMediaInfo</tt> struct with symbols indicating
the requested chunk of media (<tt>labelSymbol</tt>) and the requested format
(<tt>formatSymbol</tt>).  After the call, the <tt>mediaData </tt>field is
populated with the requested data; the type of this field depends on the format
requested.	The caller then owns the data and is responsible for disposing it,
if applicable.	Typically this data is either a <tt>MoaHandle</tt>, a Macintosh
Handle or Pointer, or a Windows global handle.
*/

	STDMETHOD(SetMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)  /* Pointer to a caller-owned media
information structure */
		PURE;

/* Category
Media owner methods
*/

/* Description
Sets cast member media data.  This method copies caller-supplied media data and
associates it with a cast member. Before making this call, use
<tt>IMoaDrUtils::NewMediaInfo() </tt>to fill out the media information
structure, specifying NULL for the <tt>aux </tt>field and
<tt>kMoaDrMediaOpts_None </tt>for the <tt>options </tt>field.  The caller
populates a <tt>MoaDrMediaInfo </tt>structure with symbols indicating the
supplied chunk of media (<tt>labelSymbol</tt>), the supplied format
(<tt>formatSymbol</tt>), and the media data itself (<tt>mediaData</tt>).  If
the label and format are supported by the cast member, a call to this method
copies the caller's data and replaces any existing media data for the supplied
label for the cast member.	Since the data is copied, the caller retains
ownership of the media data passed in. Typically, this data is either a
<tt>MoaHandle</tt>, a Macintosh Handle or pointer, or a Windows global
handle.
*/

	STDMETHOD(AttachMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)  /* Pointer to a caller-
owned media information structure */
		PURE;

/* Category
Media owner methods
*/

/* Description
<p>
Attaches media to a cast member, releasing it from the caller. This is the same
as the <tt>SetMedia() </tt>method except instead of copying the data, it is
moved to the cast member.  (In effect this method is a <tt>SetMedia() </tt>call
followed by a <tt>ReleaseMedia()</tt> call.)  <p>
<p>
Before making this call, use <tt>IMoaDrUtils::NewMediaInfo() </tt>to fill out
the media information structure, specifying NULL for the <tt>aux </tt>field and
<tt>kMoaDrMediaOpts_None </tt>for the <tt>options </tt>field. <p>
<p>
On enter, the <tt>labelSymbol </tt>and <tt>formatSymbol</tt> fields should be
populated with symbols indicating which chunk of media is to be attach
(<tt>labelSymbol</tt>), and what format the media is supplied in
(<tt>formatSymbol</tt>).  The <tt>mediaData </tt>field should hold the data
itself (typically a <tt>MoaHandle</tt>, Macintosh Handle, or Windows global
handle) <p>
<p>
Upon return, if there is no error, the media has changed ownership and belongs
to the host application, and should no longer be referenced by the caller.
This method is provided to allow the host application to optimize
media-transfer if possible; it may prevent an extra copy of the media data,
which may occur with separate <tt>SetMedia()</tt> and <tt>ReleaseMedia()</tt>
calls).<p>
*/

	STDMETHOD(CallFunction)(THIS_
		MoaMmSymbol methodName,  /* Symbol of the method (function)
to call */
		MoaLong nArgs, /* Number of arguments, excluding the Xtra
instance in <tt><i>pArgs</i>[0]</tt> */
		ConstPMoaMmValue pArgs,  /* Array of arguments, with the first
valid argument at <tt><i>pArgs</i>[1]</tt> */
		PMoaMmValue pResult)  /* Pointer to a <tt>MoaMmValue </tt>to receive a result
value, if any.	*/
		PURE;

/* Category
Scripting Support
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=295><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=295>Successful</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=295><TT>kMoaMmErr_FunctionNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=295><TT>F</TT>unction not
supported
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=295><TT>kMoaMmErr_WrongNumberOfArgs</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=295><TT>A</TT>rgument count
wrong,
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=295>Other Property/CallHandler errors
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=295>Also acceptable here
</TD></TR>
</TABLE>
*/

/* Description
<p>
Calls a cast member Lingo function. Pass the symbol of the function to call in
the <tt><i>methodName </i></tt>parameter, along with the argument count
(<tt><i>nArgs</i></tt>), the argument array (<tt><i>pArgs</i></tt>), and
optionally, a pointer to a <tt>MoaMmValue </tt>to receive any result value. The
argument array, <tt><i>pArgs</i></tt>, contains an array of <tt>MoaMmValues
</tt>corresponding to the function arguments.  <tt><i>pArgs</i>[0]</tt> is a
reserved value and should not be referenced.  The function parameters are
supplied in <tt><i>pArgs</i>[1] </tt>through
<tt><i>pArgs</i>[<i>nArgs</i>]</tt>. If the method has a return value, it
should populate <tt><i>pResult </i></tt>with a new <tt>MoaMmValue
</tt>containing the result.  If the cast member does not support the function
specified by <tt><i>methodName</i></tt>, it returns the error code
<tt>kMoaMmErr_FunctionNotFound</tt>.  If the number or types of arguments are
incorrect, the function returns one of the appropriate <tt>MoaMmErrors
</tt>(see mmtypes.h).<p>
*/

	STDMETHOD(GetMemberIndex) (THIS_
		MoaDrMemberIndex FAR * pMemberIndex)  /* Pointer to position
of cast member in cast */
		PURE;

/* Category
Member information
*/

/* Description
<p>
Returns the position of the cast member <tt><i>This</i></tt>  in its cast.	<p>
*/

	STDMETHOD(GetScoreAccess) (THIS_
		struct IMoaDrScoreAccess FAR * FAR * ppScore)
		PURE;

/* Category
Acquiring <tt>IMoaMmScoreAccess</tt>
*/

/* Description
Obtains a <tt>IMoaDrScoreAccess </tt>interface for accessing or editing the
score associated with a film loop cast member.	This method is only valid for
film loop cast members
*/

	STDMETHOD(CallHandler)(THIS_
		MoaMmSymbol handlerName,  /* Symbol for handler (message)
name */
		MoaLong nArgs,	/* Number of arguments you're passing */
		PMoaMmValue pArgs,	/* Pointer to an array of <tt>MoaMmValues </tt>containing
arguments */
		PMoaMmValue pResult,  /* Pointer to an array of <tt>MoaMmValues </tt>containing
arguments */
		MoaBool FAR * pHandled)  /* Pointer to a <tt>MoaBool</tt> to receive TRUE if the
handler exists in the script (message handled), or FALSE if it does not.*/
		PURE;

/* Category
Scripting support
*/

/* Description
Calls a handler <tt><i>handlerName</i></tt>  defined in the script associated
with this cast member. The <tt><i>nArgs</i></tt>  argument is the number of
arguments to the handler, the <i>pArgs</i> argument is a <tt>MoaMmList</tt> of
arguments as <tt>MoaMmValues</tt>.	You must pass in NULL to
<tt><i>pResult</i></tt>  if you do not expect a result.  You must pass in a
valid pointer if you do expect a result.  The handler call will be passed up
the standard Lingo messaging hierarchy.  The argument <i>pHandled</i> reports
whether the handler was handled by any object in the hierarchy.
*/

};

typedef IMoaDrCastMem FAR * PIMoaDrCastMem;


/* ----------------------------------------------------------------------------
/
/  IMoaDrCast
/
/ -------------------------------------------------------------------------- */

/* IID_IMoaDrCast: AC401AEC0000D9F800000800072C6326 */
DEFINE_GUID(IID_IMoaDrCast, 0xAC401AECL, 0x0000, 0xD9F8, 0x00, 0x00, 0x08,
				0x00, 0x07, 0x2C, 0x63, 0x26);


#undef INTERFACE
#define INTERFACE IMoaDrCast

DECLARE_INTERFACE_(IMoaDrCast, IMoaMmPropOwner)

/* Description
<p>
The <tt>IMoaDrCast</tt> interface represents a cast in a movie.  This interface
can be acquired by calling the <tt>IMoaDrMovie</tt> methods <tt>NewCast()</tt>,
<tt>GetCastFromName()</tt> and <tt>GetNthCast()</tt>.  <p>
<p>
<h5><a name="RTFToC2">Cast properties</a></a></a></a></a></a></a></a></a></a></a>
</a></h5><p>
<p>
<tt>IMoaDrCast</tt> inherits from the <tt>IMoaMmPropOwner</tt> interface,
providing for access to data through the properties mechanism described in the
chapter "Properties" earlier in this document.	The following table lists
properties defined for objects providing the <tt>IMoaDrCast </tt>interface.  <p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetProp)(THIS_
		MoaMmSymbol symbol, /* The <tt>MoaMmSymbol </tt>for the property of
interest */
		PMoaMmValue pPropValue)  /* Pointer to a <tt>MoaMmValue </tt>structure to
receive the value */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists and value was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue</FONT></I></TT> passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists but couldn't get due
to internal err
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for string
value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for other
value data
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the value of the specified cast property. To get the symbol from a
string, use the <tt>IMoaMmUtils::StringToSymbol()</tt>.The caller  is
responsible for releasing the value referenced by <tt><i>pPropValue
</i></tt>with <tt>IMoaMmUtils::ValueRelease() </tt>when it is no longer
needed.<p>
*/

	STDMETHOD(SetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the property
of interest */
		ConstPMoaMmValue pPropValue)  /* Pointer to a caller-owned
 <tt>ConstPMoaMmValue</tt> structure containing the new value */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists and value was set
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists, value ok, couldn't
set--internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Couldn't allocate memory for
setting string value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Couldn't allocate memory for
setting other value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_IntegerExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: integer value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_SymbolExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: symbol value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_FloatExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: float value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_StringExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: string value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PointExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: point value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_RectExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: rect value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: other value
expected (non-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch:
<TT>CMRef</TT> value expected
</TD></TR>
</TABLE>
*/

/* Description
<p>
Sets a cast property to a new value.  The caller continues to maintain
ownership of the value passed in, and should release it using
<tt>IMoaMmUtils::ValueRelease() </tt>when it is no longer needed. <p>
*/

	STDMETHOD(GetIndexInMovie)(THIS_
		struct IMoaDrMovie FAR * pIMoaDirMovie,  /* Pointer to a caller-owned
interface for the movie of interest. */
		MoaDrCastIndex	FAR * pCastIndex)  /* Pointer to a <tt>MoaDrCastIndex</tt>
to receive the index of the cast in the specified movie */
		PURE;

/* Category
Movie Interaction
*/

/* Description
<p>
Obtains the index of the cast in the specified movie's cast list. Casts can be
shared among several simultaneously-playing movies; each cast can have a
different position within each movie's cast list.  The caller must supply an
interface to the movie of interest, which continues to be owned by the caller.
<p>
*/

	STDMETHOD(GetFirstUsedMemberIndex)(THIS_
		MoaDrMemberIndex FAR * pMemberIndex)  /* Pointer to a
<tt>MoaDrMemberIndex</tt> to receive the <tt>memberIndex</tt>. */
		PURE;

/* Category
Cast member access
*/

/* Description
<p>
Obtains the index of the first occupied (non-empty) cast member  slot in the
cast. Returns a <tt>NULL</tt> member index if there are no cast members in the
cast. <p>
*/

	STDMETHOD(GetNextUsedMemberIndex)(THIS_
		MoaDrMemberIndex afterMemberIndex,	/* Index of cast member
slot after which to begin search for a non-empty cast member */
		MoaDrMemberIndex FAR * pMemberIndex)  /* Pointer to a
<tt>MoaDrMemberIndex</tt> to receive the member index */
		PURE;

/* Category
Cast member access
*/

/* Description
Obtains the index of the next occupied (non-empty) cast member slot in the cast
after the specified cast member slot. Returns a <tt>NULL</tt> member index if
there are no cast members in the cast after <tt><i>afterMemberIndex</i></tt>.
*/

	STDMETHOD(GetLastUsedMemberIndex)(THIS_
		MoaDrMemberIndex FAR * pMemberIndex)  /* Pointer to a <tt>MoaDrMemberIndex</tt> to receive the memberIndex.*/
		PURE;

/* Category
Cast member access
*/

/* Description
Obtains the index of the last occupied (non-empty) cast member slot in the
cast.  Returns a <tt>NULL</tt> member index if there are no cast members in the cast.
*/

	STDMETHOD(GetFirstFreeMemberIndex)(THIS_
		MoaDrMemberIndex FAR * pMemberIndex)  /* Pointer to a
<tt>MoaDrMemberIndex</tt> to receive the memberIndex.*/
		PURE;

/* Category
Cast member access
*/

/* Description
<p>
Obtains the index of the first empty cast member slot in the cast. Returns a
<tt>NULL </tt>member index if there are no empty cast member slots	remaining
in the cast.<p>
*/

	STDMETHOD(GetNextFreeMemberIndex)(THIS_
		MoaDrMemberIndex afterMemberIndex,	/* Index of cast member
slot after which to begin searching for an empty cast member slot. */
		MoaDrMemberIndex FAR * pMemberIndex)  /* Pointer to a
<tt>MoaDrMemberIndex</tt> to receive the member index */
		PURE;

/* Category
Cast member access
*/

/* Description
Obtains the index of the next empty cast member slot in the cast after the
specified cast member slot. Returns a <tt>NULL</tt> member index if there are
no empty cast member slots in the cast after <tt><i>afterMemberIndex</i></tt>.
*/

	STDMETHOD(GetLastFreeMemberIndex)(THIS_
		MoaDrMemberIndex FAR * pMemberIndex)  /* Pointer to a
<tt>MoaDrMemberIndex</tt>
to receive the <tt>memberIndex</tt> */
		PURE;

/* Category
Cast member access
*/

/* Description
Obtains the index of the last empty cast member slot in the cast.  Returns a
<tt>NULL</tt> member index if there are no empty cast member slots	remaining
in the cast.
*/

	STDMETHOD(GetMemberIndexFromName)(THIS_
		PMoaChar pCastMemName,	/* Pointer to a C string buffer containing
the name of the cast member of interest */
		MoaDrMemberIndex FAR * pMemberIndex)  /* Pointer to a <tt>MoaDrMemberIndex</tt>
 to receive the index of the cast member */
		PURE;

/* Category
Cast member access
*/

/* Description
Obtains the index of a cast member in the cast given the cast member name.
Returns 0 if the cast member cannot be found in the cast.  Name comparisons are
case-insensitive.
*/

	STDMETHOD(GetCastMem)(THIS_
		MoaDrMemberIndex memberIndex,  /* Index of the cast member of
interest. This must be an occupied cast member slot. */
		PIMoaDrCastMem FAR * ppIMoaDrCastMem)  /* Pointer to a
<tt>PIMoaDrCastMem</tt> to receive a pointer to the cast member's interface.  Interface is then
owned by caller which must dispose when no longer needed.*/
		PURE;

/* Category
Cast member access
*/

/* Description
<p>
Obtains a cast member interface for the specified cast member. The caller
subsequently owns the interface and is responsible for releasing it when it is
no longer needed.  A cast member interface may no longer be valid if the
associated cast member is moved or deleted from the cast.  You should always
release the cast member interface before returning from the method
implementation that calls this method.	<p>
*/

	STDMETHOD(CreateCastMem)(THIS_
		MoaDrMemberIndex memberIndex,  /* Index of the cast
member slot into which the newly created cast member will be placed */
		MoaMmSymbol typeSymbol)  /* The <tt>MoaMmSymbol </tt>of the
type of cast member to create */
		PURE;

/* Category
Cast member management
*/

/* Description
<p>
Creates a new cast member of the specified type in the specified cast member
slot.  The caller must provide the symbol of the type to create.  Symbols of
all registered types can be obtained from the Player cast member type methods
(<tt>GetNthCastMemTypeSymbol</tt>).  If you know that the type is registered
and the text string for the type, you can get the symbol directly using
<tt>IMoaMmUtils::StringToSymbol()</tt>. If the specified cast member slot is
occupied, the existing cast member is deleted.	At the time of creation, the
cast member probably will not have any media associated with it; use the
<tt>IMoaDrCastMem::SetMedia() </tt>(or its media accessor interface) to supply
it. <p>
*/

	STDMETHOD(DeleteCastMem)(THIS_
		MoaDrMemberIndex memberIndex)  /* Index of the cast
member to delete */
		PURE;

/* Category
Cast member management
*/

/* Description
<p>
Deletes the cast member in the specified slot. The cast member is removed
immediately.  Any references to the cast member in the score will be
dangling.<p>
*/

	STDMETHOD(DuplicateCastMem)(THIS_
		MoaDrMemberIndex sourceMemberIndex,  /* Index of the cast member
in this cast to duplicate */
		struct IMoaDrCast FAR * pDestCast,	/* Pointer to a caller-owned <tt>IMoaDrCast
</tt>interface for the destination cast */
		MoaDrMemberIndex destMemberIndex)  /* Index in <tt><i>pDestCast </i></tt>of the
cast member slot in which to place the copied cast member */
		PURE;

/* Category
Cast member management
*/

/* Description
<p>
Duplicates a cast member, placing the copy in the specified slot within the
specified cast.  The caller must pass in an interface to the destination cast;
this interface continues to be owned by the caller.  This method duplicates the
cast member entirely, including its properties (name, and so on) and media
data.  If the destination cast member slot is occupied, the existing cast
member is deleted. <p>
*/

	STDMETHOD(Save)(THIS_
		PMoaChar pNewPathName)	/* Pointer to a specified path */
		PURE;

/* Category
Cast management
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=157><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=433>Successful</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=157><TT>kMoaDrErr_DiskIO</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=433>IO error encountered during file
access.
</TD></TR>
</TABLE>
*/

/* Description
 <p>
Saves the cast to the specified path, which should include the filename.  This
method applies only to external cast members.  <p>
*/

};

typedef IMoaDrCast FAR * PIMoaDrCast;


/* ----------------------------------------------------------------------------
/
/  IMoaDrScoreFrame
/
/ -------------------------------------------------------------------------- */


/* IID_IMoaDrScoreFrame: AC5E874200FE19A700000800072C6326 */
DEFINE_GUID(IID_IMoaDrScoreFrame, 0xAC5E8742L, 0x00FE, 0x19A7, 0x00, 0x00,
				0x08, 0x00, 0x07, 0x2C, 0x63, 0x26);


#undef INTERFACE
#define INTERFACE IMoaDrScoreFrame

DECLARE_INTERFACE_(IMoaDrScoreFrame, IMoaMmPropOwner)

/* Description
<p>
The <tt>IMoaDrScoreFrame</tt> interface represents a particular frame in a
score.	You acquire this interface through the
<tt>IMoaDrScoreAccess::GetFrame()</tt> method. <p>
<h5><a name="RTFToC2">Score
frame properties</a></a></a></a></a></a></a></a></a></a></a></a></h5>
<p>
<tt>IMoaDrScoreFrame</tt> inherits from the <tt>IMoaMmPropOwner</tt> interface,
providing for access to data through the properties mechanism described in the
"Multimedia Services" chapter in the <i>Development Guide </i>document.  See
the "Properties" section for information on the properties defined for objects
providing the <tt>IMoaDrScoreFrame</tt> interface.<p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the property
of interest */
		PMoaMmValue pPropValue)  /* Pointer to a caller-owned
<tt>MoaMmValue</tt> structure to receive the value of the property */
		PURE;

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists and value was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid<TT> <I><FONT SIZE=2
FACE="Courier New">pPropValue</FONT></I> </TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists but couldn't get due
to internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for string
value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for other
value data
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the value of the specified score frame property. To get the
<tt><i>symbol </i></tt>from a string, use the
<tt>IMoaMmUtils::StringToSymbol()</tt>.The caller is responsible for releasing
the value with <tt>IMoaMmUtils::ValueRelease() </tt>when it is no longer
needed.<p>
*/

	STDMETHOD(SetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the property of
interest */
		ConstPMoaMmValue pPropValue)  /* Pointer to a caller-owned
<tt>ConstPMoaMmValue</tt> structure from which to copy the value of the property */
		PURE;

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists and value was set
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists, value ok, but can't
set--internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Can't allocate memory for setting
string value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Can't allocate memory for setting
other value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_IntegerExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: integer value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_SymbolExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: symbol value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_FloatExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: float value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_StringExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: string value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PointExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: point value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_RectExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: rect value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: other value
expected (non-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch:
<TT>CMRef</TT> value expected
</TD></TR>
</TABLE>
*/

/* Description
<p>
Sets a score frame property to a new value. To get the <tt><i>symbol
</i></tt>from a string, use the <tt>IMoaMmUtils::StringToSymbol()</tt>.The
caller continues to maintain ownership of the value passed in, and should
release it using <tt>IMoaMmUtils::ValueRelease() </tt>when it is no longer
needed. <p>
*/

};

typedef IMoaDrScoreFrame FAR * PIMoaDrScoreFrame;



/* ----------------------------------------------------------------------------
/
/  IMoaDrScoreSound
/
/ -------------------------------------------------------------------------- */

/* IID_IMoaDrScoreSound: AC5E876500FE21EC00000800072C6326 */
DEFINE_GUID(IID_IMoaDrScoreSound, 0xAC5E8765L, 0x00FE, 0x21EC, 0x00, 0x00,
				0x08, 0x00, 0x07, 0x2C, 0x63, 0x26);

#undef INTERFACE
#define INTERFACE IMoaDrScoreSound

DECLARE_INTERFACE_(IMoaDrScoreSound, IMoaMmPropOwner)

/* Description
<p>
The <tt>IMoaDrScoreSound</tt> interface represents the sound in a particular
channel in a particular frame in a score.  You acquire this interface through
the <tt>IMoaDrScoreAccess::GetSound()</tt> method. <p>
<h5><a name="RTFToC2">Score sound properties</a></a></a></a></a></a></a></a></a></a></a>
</a></h5>
<p>
<tt>IMoaDrScoreSound</tt> inherits from the <tt>IMoaMmPropOwner</tt> interface,
providing for access to data through the properties mechanism described in the
"Multimedia Services" chapter in the <i>Development Guide </i>document.  See
the "Properties" section for information on the properties defined for objects
providing the <tt>IMoaDrScoreSound</tt> interface.<p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the property
of interest */
		PMoaMmValue pPropValue)  /* Pointer to a caller-owned
<tt>MoaMmValue</tt> structure to receive the value of the property */
		PURE;

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists and value was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid<TT> <I><FONT SIZE=2
FACE="Courier New">pPropValue</FONT></I> </TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists but couldn't get due
to internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for string
value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for other
value data
</TD></TR>
</TABLE>
*/

/* Description
Obtains the value of the specified score sound property.  To get the
<tt><i>symbol </i></tt>from a string, use the
<tt>IMoaMmUtils::StringToSymbol()</tt>.  The caller  is responsible for
releasing the value with <tt>IMoaMmUtils::ValueRelease() </tt>when it is no
longer needed.
*/

	STDMETHOD(SetProp)(THIS_
		MoaMmSymbol symbol,  /* <tt>The MoaMmSymbol</tt> for the property of
interest */
		ConstPMoaMmValue pPropValue)  /* Pointer to a caller-owned
<tt>ConstPMoaMmValue</tt> structure from which to copy the value of the property */
		PURE;

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists and value was set
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists, value ok, but can't
set--internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Can't allocate memory for setting
string value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Can't allocate memory for setting
other value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_IntegerExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: integer value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_SymbolExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: symbol value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_FloatExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: float value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_StringExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: string value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PointExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: point value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_RectExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: rect value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: other value
expected (non-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch:
<TT>CMRef</TT> value expected
</TD></TR>
</TABLE>
*/

/* Description
<p>
Sets a score sound property to a new value. To get the <tt><i>symbol
</i></tt>from a string, use the <tt>IMoaMmUtils::StringToSymbol()</tt>.The
caller continues to maintain ownership of the value passed in, and should
release it using <tt>IMoaMmUtils::ValueRelease()</tt> when it is no longer
needed. <p>
*/

};

typedef IMoaDrScoreSound FAR * PIMoaDrScoreSound;


/* ----------------------------------------------------------------------------
/
/  IMoaDrScoreSprite
/
/ -------------------------------------------------------------------------- */

/* IID_IMoaDrScoreSprite: AC5E878200FE28B400000800072C6326 */
DEFINE_GUID(IID_IMoaDrScoreSprite, 0xAC5E8782L, 0x00FE, 0x28B4, 0x00, 0x00,
				0x08, 0x00, 0x07, 0x2C, 0x63, 0x26);


#undef INTERFACE
#define INTERFACE IMoaDrScoreSprite

DECLARE_INTERFACE_(IMoaDrScoreSprite, IMoaMmPropOwner)

/* Description
<p>
The <tt>IMoaDrScoreSprite</tt> interface represents the sprite in a particular
channel in a particular frame in a score.  You acquire this interface through
the <tt>IMoaDrScoreAccess::GetSprite()</tt> method. <p>
<p>
<h5><a name="RTFToC2">Score sprite properties</a></a></a></a></a></a></a></a></a></a></a>
</a></h5>
<p>
<tt>IMoaDrScoreSprite</tt> inherits from the <tt>IMoaMmPropOwner</tt>
interface, providing for access to data through the properties mechanism
described in the "Multimedia Services" chapter in the <i>Development Guide
</i>document.  See the "Properties" section for information on the properties
defined for objects providing the <tt>IMoaDrScoreSprite</tt> interface.<p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetProp) (THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the
property of interest */
		PMoaMmValue pPropValue)  /* Pointer to a caller-owned
<tt>MoaMmValue</tt> structure to receive the value of the property */
		PURE;

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists and value was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid<TT> <I><FONT SIZE=2
FACE="Courier New">pPropValue</FONT></I> </TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists but couldn't get due
to internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for string
value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for other
alue data
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the value of the specified score sprite property. To get the
<tt><i>symbol </i></tt>from a string, use the
<tt>IMoaMmUtils::StringToSymbol()</tt>.  The caller  is responsible for
releasing the value with <tt>IMoaMmUtils::ValueRelease() </tt>when it is no
longer	needed.<p>
*/

	STDMETHOD(SetProp) (THIS_
		MoaMmSymbol symbol,  /* <tt>The MoaMmSymbol</tt> for the property of
interest */
		ConstPMoaMmValue pPropValue)  /* Pointer to a caller-owned
<tt>ConstPMoaMmValue</tt> structure from which to copy the value of the property */
		PURE;

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists and value was set
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists, value ok, but can't
set--internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Can't allocate memory for setting
string value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Can't allocate memory for setting
other value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_IntegerExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: integer value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_SymbolExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: symbol value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_FloatExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: float value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_StringExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: string value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PointExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: point value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_RectExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: rect value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: other value
expected (non-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch:
<TT>CMRef</TT> value expected
</TD></TR>
</TABLE>
*/

/* Description
<p>
Sets a score sprite property to a new value  To get the
<tt><i>symbol</i></tt><i> </i>from a string, use the
<tt>IMoaMmUtils::StringToSymbol()</tt>.  The caller continues to maintain
ownership of the value passed in, and should release it using
<tt>IMoaMmUtils::ValueRelease()</tt> when it is no longer needed.<p>
*/

};

typedef IMoaDrScoreSprite FAR * PIMoaDrScoreSprite;



/* ----------------------------------------------------------------------------
/
/  IMoaDrScoreAccess
/
/ -------------------------------------------------------------------------- */


/* INTERFACEID */
/* IID_IMoaDrScoreAccess: AC401B2A0000E88800000800072C6326 */
DEFINE_GUID(IID_IMoaDrScoreAccess, 0xAC401B2AL, 0x0000, 0xE888, 0x00, 0x00,
				0x08, 0x00, 0x07, 0x2C, 0x63, 0x26);


#undef INTERFACE
#define INTERFACE IMoaDrScoreAccess

DECLARE_INTERFACE_(IMoaDrScoreAccess, IMoaDrMediaAccess)

/* Description
<p>
<tt>IMoaDrScoreAccess </tt>inherits from <tt>IMoaDrMediaAccess</tt>.  This
interface provides specific methods for accessing and editing the contents of a
Director movie's score.  You can acquire a score interface by calling the
<tt>IMoaDrMovie::GetScoreAccess()</tt> method.	Film loop cast members also
have scores, which can be acquired by <tt>IMoaDrCastMem::GetScoreAccess()</tt>. <p>
<p>
See the section entitled <tt>IMoaDrMediaAccess </tt>for information regarding
the inherited <tt>IMoaDrMediaAccess</tt>-specific methods of this interface.<p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(New)(THIS)
		PURE;

/* Category
Editing support
*/

/* Description
See <tt>IMoaDrMediaAccess</tt>
*/

	STDMETHOD(Refresh)(THIS)
		PURE;

/* Category
Editing support
*/

/* Description
See <tt>IMoaDrMediaAccess</tt>
*/

	STDMETHOD(Commit)(THIS)
		PURE;

/* Category
Editing support
*/

/* Description
Commits changes made to media back since the last <tt>BeginUpdate()</tt>,
<tt>Commit()</tt>, or <tt>Refresh().</tt>  Call this method to apply changes to
media back to the owner.
*/

	STDMETHOD(GetAccessInfo)(THIS_
		PMoaDrAccessInfo pAccessInfo)  /* Pointer to <tt>MoaDrAccessInfo</tt>
structure to receive information */
		PURE;

/* Category
Media access
*/

/* Description
<p>
Obtains the current <tt>accessInfo </tt>for the score accessor.
<tt><i>pAccessInfo </i></tt>is a pointer to a <tt>MoaDrAccessInfo</tt>
structure to receive the information.  This call populates the structure with
the <tt>PIMoaDrMediaOwner </tt>for the media owner, the label symbol for the
media being accessed, and the format symbol for the media being accessed.
Since an interface is being supplied in this structure (<tt>pOwner</tt>), the
caller is responsible for releasing it.<p>
*/

	STDMETHOD(SetAccessInfo)(THIS_
		ConstPMoaDrAccessInfo pAccessInfo)	/* Pointer to <tt>MoaDrAccessInfo</tt>
structure to receive information */
		PURE;

/* Category
Media access
*/

/* Description
<p>
Sets the current <tt>accessInfo </tt>for the score accessor.
<tt><i>pAccessInfo </i></tt>is a pointer to a <tt>MoaDrAccessInfo</tt>
structure providing the information.  This call populates the structure with
the <tt>PIMoaDrMediaOwner </tt>for the media owner, the label symbol for the
media being accessed, and the format symbol for the media being accessed.
Since the caller supplies an interface in this structure (<tt>pOwner</tt>), the
caller is responsible for releasing it.<p>
*/

	/* ScoreAccess methods */

	STDMETHOD(SetOwner)(THIS_
		PIMoaDrMediaOwner pOwner)
		PURE;

/* Category
Media access
*/

/* Description
Convenience method to set the access information for the <tt>ScoreAccess
</tt>object.  Calling this method results in the same behavior as calling
<tt>SetAccessInfo()</tt> with <tt>score</tt> and M<tt>oaHandle </tt>as the
label and format symbols, respectively.
*/

	STDMETHOD(BeginUpdate)(THIS)
		PURE;

/* Category
Editing support
*/

/* Description
Begins a score editing session.  Before inserting or deleting frames, or
modifying score frames, sounds, or sprites, you must call
<tt>BeginUpdate()</tt>.  When done with your changes, call <tt>EndUpdate()</tt>.
*/

	STDMETHOD(EndUpdate)(THIS)
		PURE;

/* Category
Editing support
*/

/* Description
Finishes an update session initiated by a call to <tt>BeginUpdate()</tt>.  If
you wish to keep score changes, call <tt>Commit()</tt> before calling this
method; to revert to previous score, simply call this method without committing
the media.
*/

	STDMETHOD(SetCurFrameIndex)(THIS_
		MoaDrFrameIndex frameIndex)  /* Frame number of the new current frame */
		PURE;

/* Category
Frame access
*/

/* Description
Sets the current frame being accessed.	<tt><i>frameIndex</i></tt> is the frame
number of the new current frame.
*/

	STDMETHOD(GetCurFrameIndex)(THIS_
		PMoaDrFrameIndex pFrameIndex)
		PURE;

/* Category
Frame access
*/

/* Description
Obtains the frame number of the current frame being accessed.
*/

	STDMETHOD(GetLastFrameIndex)(THIS_
		PMoaDrFrameIndex pFrameIndex)
		PURE;	

/* Category
Frame access
*/

/* Description
Obtains the frame number of the last occupied frame in the score.
 */

	STDMETHOD(UpdateFrame)(THIS)
		PURE;

/* Category
Frame editing
*/

/* Description
<p>
Updates the current frame.	This method has two effects, it<p>
<p><ul><ul> saves any changes made to frame, sound, and sprite channels to the working
score data</ul></ul><p>
<p><ul><ul> increments the current frame by 1. </ul></ul><p>
*/

	STDMETHOD(InsertFrame)(THIS)
		PURE;

/* Category
Frame Editing
*/

/* Description
Inserts a frame at the current frame position.	This has the same effect as
<tt>DuplicateFrame()</tt>.
*/

	STDMETHOD(DuplicateFrame)(THIS)
		PURE;

/* Category
Frame Editing
*/

/* Description
Duplicates the current frame.  The new frame is inserted at position
<i>&lt;currentFrame + 1&gt;</i>.  The current frame is incremented to the new
frame (<i>&lt;currentFrame + 1&gt;</i>).
*/

	STDMETHOD(ClearFrame)(THIS)
		PURE;

/* Category
Frame Editing
*/

/* Description
Clears all of the cells in the current frame to their default (empty) values.
*/

	STDMETHOD(DeleteFrame)(THIS)
		PURE;

/* Category
Frame Editing
*/

/* Description
Deletes the current frame from the score.
*/

	STDMETHOD(GetFrame)(THIS_
		PIMoaDrScoreFrame FAR * ppFrame)
		PURE;

/* Category
Frame access
*/

/* Description
Obtains the <tt>IMoaDrScoreFrame </tt>interface for the score data being
accessed.  This interface is used to get and set frame-level properties of the
score data.
*/

	STDMETHOD(GetSound)(THIS_
		MoaDrSoundChanIndex chanIndex,	/* Specifies the sound channel to access */
		PIMoaDrScoreSound FAR * ppSound)
		PURE;

/* Category
Channel access
*/

/* Description
Obtains the <tt>IMoaDrScoreSound </tt>interface for a certain sound channel of
the score data being accessed.	<tt><i>chanIndex</i> </tt>specifies the sound
channel to access; in Director 5.0, this must be either 1 or 2.  This interface
is used to get and set sound channel-level properties of the score data.
*/

	STDMETHOD(GetSprite)(THIS_
		MoaDrSpriteChanIndex chanIndex,  /* Specifies the sprite channel to access */
		PIMoaDrScoreSprite FAR * ppSprite)
		PURE;

/* Category
Channel access
*/

/* Description
Obtains the <tt>IMoaDrScoreSprite </tt>interface for a certain sprite channel
of the score data being accessed.  <tt><i>chanIndex</i></tt> specifies the
sprite channel to access; in Director 5.0, this must be in the range 1 to 48.
This interface is used to get and set sprite channel-level properties of the
score data.
*/

};

typedef IMoaDrScoreAccess FAR * PIMoaDrScoreAccess;




/* ----------------------------------------------------------------------------
/
/  IMoaDrMovie
/
/ -------------------------------------------------------------------------- */


/* IID_IMoaDrMovie: AC401B610000F57600000800072C6326 */
DEFINE_GUID(IID_IMoaDrMovie, 0xAC401B61L, 0x0000, 0xF576, 0x00, 0x00, 0x08,
				0x00, 0x07, 0x2C, 0x63, 0x26);


#undef INTERFACE
#define INTERFACE IMoaDrMovie

DECLARE_INTERFACE_(IMoaDrMovie, IMoaDrMediaOwner)

/* Description
<p>
The IMoaDrMovie interface represents open movies in Director.  You acquire a
movie interface by calling the <tt>IMoaDrPlayer</tt> methods
<tt>GetActiveMovie()</tt> or <tt>GetNthMovie()</tt>.<p>
<p>
<h5><a name="RTFToC2">Movie
properties</a></a></a></a></a></a></a></a></a></a></a></a></h5>
<p>
<tt>IMoaDrMovie</tt> inherits from the <tt>IMoaMmPropOwner</tt> interface,
providing for access to data through the properties mechanism described in the
"Multimedia Services" chapter in the <i>Development Guide </i>document.  See
the "Properties" section for information on the properties defined for objects
providing the <tt>IMoaDrMovie</tt> interface.  <p>
<p>
<h5><a name="RTFToC3">Movie
media</a></a></a></a></a></a></h5>
<p>
<tt>IMoaDrMovie</tt> inherits from the <tt>IMoaDrMediaOwner</tt> interface,
providing for access to media through the media owner mechanism described in
the "Director Services" chapter in the <i>Development Guide </i>document.
Movies have one kind of media: scores.	Scores are editable through the
<tt>IMoaDrScoreAccess</tt> interface.  You acquire a movie's score data by
calling either <tt>IMoaDrMovie::GetMedia()</tt>, which returns a handle to the
score data, or<tt> GetScoreAccess()</tt>, which returns an
<tt>IMoaDrScoreAccess</tt> interface to the score data.  <p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the
property of interest.*/
		PMoaMmValue pPropValue)  /* Pointer to a <tt>MoaMmValue</tt>
to receive the value */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists and value was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists but couldn't get due
to internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for string
value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for other
value data
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the value of the specified movie property. To get the symbol from a
string, use the <tt>IMoaMmUtils::StringToSymbol()</tt>.  The caller is
responsible for releasing the value at <tt><i>pPropValue  </i></tt>with
<tt>IMoaMmUtils::ValueRelease()</tt> when it is no longer  needed.<p>
*/

	STDMETHOD(SetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the property of
interest */
		ConstPMoaMmValue pPropValue)  /* Pointer to a caller-owned
<tt>ConstPMoaMmValue</tt> structure from which to copy the new value */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists and value was set
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists, value ok, couldn't
set--internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Couldn't allocate memory for
setting string value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Couldn't allocate memory for
setting other value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_IntegerExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: integer value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_SymbolExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: symbol value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_FloatExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: float value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_StringExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: string value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PointExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: point value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_RectExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: rect value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: other value
expected (non-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch:
<TT>CMRef</TT> value expected
</TD></TR>
</TABLE>
*/

/* Description
<p>
Sets the value of the specified property. To get the symbol from a string, use
the <tt>IMoaMmUtils::StringToSymbol() </tt>method.	The caller continues to
maintain ownership of the value passed in, and should release it using
<tt>IMoaMmUtils::ValueRelease() </tt>when it is no longer needed.<p>
*/

	STDMETHOD(GetMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)  /* Pointer to a caller-owned
media information structure */
		PURE;

/* Category
Media owner methods
*/

/* Description
<p>
Gets movie media data by obtaining a copy of the media associated with a movie.
This is how one obtains the score data associated with a movie. Before making
this call, use <tt>IMoaDrUtils::NewMediaInfo() </tt>to fill out the structure,
specifying NULL for the <tt>aux </tt>field and <tt>kMoaDrMediaOpts_None
</tt>for the <tt>options </tt>field.  The caller partially populates a
<tt>MoaDrMediaInfo </tt>structure with symbols indicating the requested chunk
of media (<tt>labelSymbol</tt>) and the requested format
(<tt>formatSymbol</tt>).  After the call, the <tt>mediaData</tt> field is
populated with the requested data.	The type of this field depends on the
format requested.  The caller owns the data and is responsible for disposing
it, if applicable.	Typically, this data is either a <tt>MoaHandle</tt>, a
Macintosh handle or pointer, or a Windows global handle.  See Director
property.rtf for a table of <tt>mediaLabels </tt>and <tt>mediaFormats</tt>
supported for movies. <p>
*/

	STDMETHOD(SetMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)  /* Pointer to a caller-owned media
information structure */
		PURE;

/* Category
Media owner methods
*/

/* Description
Sets movie media data.	This is how one replaces the score data associated with
a movie.  This method copies caller-supplied media data and associates it with
the movie. Before making this call, use <tt>IMoaDrUtils::NewMediaInfo() </tt>to
fill out the structure, specifying NULL for the <tt>aux </tt>field and
<tt>kMoaDrMediaOpts_None </tt>for the <tt>options </tt>field.  The caller
populates a <tt>MoaDrMediaInfo </tt>structure with symbols indicating the
supplied chunk of media (<tt>labelSymbol</tt>) and the supplied format
(<tt>formatSymbol</tt>), and the media data itself (<tt>mediaData</tt>).  If
the label and format are supported by the movie, a call to this method copies
the caller's data and replaces any existing media data for the supplied label
for the movie.	Since the data is copied, the caller retains ownership of the
media data passed in. Typically this data is either a <tt>MoaHandle</tt>, a
Macintosh handle or pointer, or a Windows global handle.   See Director
property.rtf for a table of <tt>mediaLabels  </tt>and <tt>mediaFormats
</tt>supported for movies.
*/

	STDMETHOD(AttachMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)  /* Pointer to a caller-owned
media information structure */
		PURE;

/* Category
Media owner methods
*/

/* Description
<p>
Attaches media to a movie, releasing it from the caller. This is the same as
<tt>SetMedia()</tt> except instead of copying the data, it is moved to the
movie.	(In effect, a <tt>SetMedia() </tt>call followed by
<tt>ReleaseMedia()</tt>.)  Before making this call, use
<tt>IMoaDrUtils::NewMediaInfo() </tt>to fill out the structure, specifying NULL
for the <tt>aux </tt>field and <tt>kMoaDrMediaOpts_None </tt>for the
<tt>options </tt>field.<p>
<p>
On enter, the <tt>labelSymbol </tt>and <tt>formatSymbol </tt>fields should be
populated with symbols indicating which chunk of media is to be attach
(<tt>labelSymbol</tt>), and what format the media is supplied in
(<tt>formatSymbol</tt>).  The <tt>mediaData </tt>field should hold the data
itself (typically a <tt>MoaHandle</tt>, Macintosh Handle, or Windows global
handle) <p>
<p>
Upon return, if there is no error, the media has changed ownership and belongs
to the host application, and should no longer be referenced by the caller.
This method is provided to allow the host application to optimize
media-transfer if possible, preventing an extra copy of the media data, which
may occur with separate <tt>SetMedia() </tt>and <tt>ReleaseMedia()
</tt>calls).<p>
*/

	STDMETHOD(CallHandler)(THIS_
		MoaMmSymbol name,  /* Symbol of the handler name to call
MoaMmSymbol */
		MoaLong nArgs,	/* Number of arguments to pass */
		PMoaMmValue pArgs,	/* Array of <tt>MoaDrValues</tt> containing the
arguments to the call */
		PMoaMmValue pResult)  /* Pointer to a caller-owned <tt>MoaMmValue</tt> to
receive the return value */
		PURE;

/* Category
Scripting support
*/

/* Description
Calls the Lingo handler <tt><i>name</i></tt> in the movie. The
<tt><i>nArgs</i></tt>  argument is the number of arguments to the handler, the
<i>pArgs</i> argument is a <tt>MoaMmList</tt> of arguments as
<tt>MoaMmValues</tt>.  You must pass in NULL to <tt><i>pResult</i></tt>  if you
do not expect a result.  You must pass in a valid pointer if you do expect a
result.
*/

	STDMETHOD(GetCastCount)(THIS_
		MoaLong FAR * pCastCount)  /* Pointer to a <tt>MoaLong</tt> to receive
the number of casts */
		PURE;

/* Category
Managing casts
*/

/* Description
Obtains the number of casts in the movie.
*/

	STDMETHOD(GetNthCast)(THIS_
		MoaDrCastIndex movieCastIndex,	/* Index of the cast (from 1 to
GetCastCount()) of interest */
		PIMoaDrCast FAR * ppIMoaDrCast)  /* Pointer to a <tt>PIMoaDrCast</tt>
to receive a pointer to the cast interface */
		PURE;

/* Category
Managing casts
*/

/* Description
Obtains an interface to one of the movie's casts by index. The interface is then
owned by the caller, and the caller is responsible for releasing it when it is no longer
needed.
*/

	STDMETHOD(GetCastFromName)(THIS_
		PMoaChar pCastName,  /* Pointer to a null-terminated C string
containing the cast name of interest */
		PIMoaDrCast FAR * ppIMoaDrCast)  /* Pointer to a
<tt>PIMoaDrCast</tt> to receive a pointer to the cast interface */
		PURE;

/* Category
Managing casts
*/

/* Description
Obtains an interface to one of the movie's casts by name, as it appears in
the Cast Properties dialog. The interface is then owned by the caller, and
the caller is responsible for releasing it when it is no longer needed.
*/

	STDMETHOD(GetCastIndexFromName)(THIS_
		PMoaChar pCastName,  /* Pointer to a null-terminated C string
containing the cast name of interest */
		MoaDrCastIndex FAR * pCastIndex)  /* Pointer to a
<tt>MoaDrCastIndex</tt> to receive the index */
		PURE;

/* Category
Managing casts
*/

/* Description
Obtains the movie cast index associated with a named cast. This is a value
from 1 to <tt>GetCastCount()</tt>.
*/

	STDMETHOD(NewCast) (THIS_
		PMoaChar pCastName,
		MoaBoolParam bExternal,
		PMoaDrCastIndex pNewCastIndex)
		PURE;

/* Category
Managing casts
*/

/* Description
Creates a new cast and add it to the movie's cast list.  Returns the position
of the new cast in the <tt><i>pNewCastIndex</i></tt> argument.
*/

	STDMETHOD(AddExternalCast) (THIS_
		PMoaChar pCastName,  /* The user reference name for the cast */
		PMoaChar pPathName,  /* The full path name for an external cast */
		PMoaDrCastIndex pNewCastIndex)	/* <tt>PMoaDrCastIndex</tt> for
the position in the cast list */
		PURE;

/* Category
Managing casts
*/

/* Description
<p>
Adds an existing external cast to the movie's cast list.  Returns in
<tt><i>pNewCastIndex</i></tt> the position of the cast in the movie's cast
list.  <p>
*/

	STDMETHOD(RemoveCast)(THIS_
		MoaDrCastIndex castIndexToRemove)  /* <tt>MoaDrCastIndex</tt> for
the cast to remove */
		PURE;

/* Category
Managing casts
*/

/* Description
Removes the cast specified by <tt><i>castToRemove</i></tt> from the movie's
cast list.
*/

	STDMETHOD(GetCMRefFromMemberName)(THIS_
		PMoaChar pMemberName,  /* Pointer to a null-terminated C
string containing the cast member name of interest */
		PMoaDrCMRef pCastMemRef)  /* Pointer to a <tt>MoaDrCMRef</tt>
to receive cast member reference */
		PURE;

/* Category
Managing casts
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=229><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=361>Successful</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=229><TT>kMoaDrErr_CastMemNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=361>Cast member not found
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the cast member reference (<tt>MoaDrCMRef</tt>) for a cast member from
its name.  This method scans all of the casts for the movie, and returns the
<tt>MoaDrCMRef</tt> for the first cast member whose name matches the one
supplied.  If no cast member is found with the specified name,
<tt>kMoaDrErr_CastMemNotFound </tt>is returned and
<tt><i>pCastMemRef</i></tt><i> </i>is set to a null reference .  Use
<tt>CMRef_IsNull()</tt> to test the result.<p>
*/

	STDMETHOD(GetCastMemFromCMRef)(THIS_
		PMoaDrCMRef pCastMemRef,  /* Pointer to a <tt>MoaDrCMRef</tt>
which specifies the cast member of interest */
		PIMoaDrCastMem FAR * ppIMoaDrCastMem)  /* Pointer to a
<tt>PIMoaDrCastMem</tt> to receive the interface for the cast member */
		PURE;

/* Category
Acquiring ImoaDrCastMem
*/

/* Description
<p>
Obtains the <tt>IMoaDrCastMem</tt> interface for the cast member with the
supplied cast member reference.  The cast member reference specifies the
<tt>movieCastIndex </tt>(index to cast in the movie) and <tt>memberIndex
</tt>(index to cast member slot position within the cast); use the CMRef_
macros in drtypes.h to create and access a <tt>0</tt>.	The caller owns the
returned  interface and is responsible for releasing it when it is no longer
needed.  <p>
*/

	STDMETHOD(UpdateStageRect) (THIS_
		MoaRect FAR * pWindowRect,	/* Pointer to a <tt>MoaRect</tt> describing
the area of the stage window to update */
		MoaRect FAR * pBufferRect)	/* Pointer to a <tt>MoaRect</tt> describing
the area of the offscreen buffer from where to update */
		PURE;

/* Category
Imaging support
*/

/* Description
Updates a rectangular area of the stage window from a rectangular area of the
stage's offscreen buffer.  Stretching or shrinking of parts of the image can be
achieved by using a <tt>windowRect </tt>which differs in size from the
<tt>bufferRect</tt>.  Note that this call does not cause all sprites on the
stage to be reimaged; it simply refreshes the stage window from Director's
offscreen compositing buffer.
*/

	STDMETHOD(GetStageWindowGC)(THIS_
		PIMoaMmGC FAR * ppWindowGC)  /* Pointer to a <tt>IMoaMmGC</tt>
interface for the stage window */
		PURE;

/* Category
Imaging support
*/

/* Description
<p>
Obtains the graphics context for the stage window.	This includes the bounds
rectangle, pixel depth, as well as platform-specific information (such as the
WindowPtr of the window on the Macintosh, or the HWND on Windows). This
information is valid only for the duration of the current call into your Xtra
method, because the stage window can change in depth or size at any time (and
may be disposed of and reallocated in the process).   You must release the
graphics context when done by calling its <tt>Release() </tt>method.   <p>
<p>
<h6><a name="RTFToC22">Important note about graphic contexts</a></h6><p>
<p>
This method should only be called by Lingo and Tool Xtras to do temporary
drawing into the stage window.	It should be called just before doing your
drawing, and the acquired interface should be released before returning control
to the calling application. This is because <tt>nativeGCInfo</tt> for the stage
buffer can become invalid at any time.	For example, the buffer may be dumped
and recreated if window size, monitor depth, or other display characteristics
change.  <p>
<p>
It's not always possible to obtain the a graphics context for the stage window.
During registration, startup, and shut-down, internal movie data structures may
not be initialized, thus trying to get the GC for it will return the err
<tt>kMoaDrErr_MovieNotOpen</tt>.  Xtra developers should never attempt to
acquire a graphics context and hold onto it; instead, you should acquire the
interface each time you need to draw and release it before your method
returns.<p>
<p>
Also, <tt>GetStageWindowGC()</tt> should not be used to get a parent window for
Windows(TM) dialogs.  The correct procedure is to use the <tt>IMoaMmUtils</tt>
Windows API cover methods such as <tt>WinDialogBox()</tt> and
<tt>WinDialogBoxParam()</tt>.  If you're putting up a system dialog on Windows,
use <tt>WinGetParent()</tt> to get the parent HWND to use, and bracket your
dialog call with <tt>WinPrepareDialogBox()</tt> and
<tt>WinUnprepareDialogBox()</tt>.<p>
<p>
Finally, these calls should not be used for sprite or transition drawing.
Instead, use the graphic context passed to you explicitly in
<tt>IMoaMmSpriteActor::Image()</tt> or
<tt>IMoaDrTransitionActor::Continue()</tt>.  If you do attempt to use this
context, your Xtra will not work correctly in MIAWs, export, or other
applications such as Authorware.
 <p>
*/

	STDMETHOD(GetStageBufferGC)(THIS_
		PIMoaMmGC FAR * ppBufferGC)  /* Pointer to a <tt>IMoaMmGC</tt> interface
for the stage offscreen buffer */
		PURE;

/* Category
Imaging support
*/

/* Description
Obtains the graphics context for the stage offscreen buffer.  This includes the
bounds rectangle, pixel depth, as well as platform-specific information (such
as the WindowPtr of the window on the Macintosh or the HWND on Windows). This
information is valid only for the duration of the current call into your Xtra
method, because the stage window can change in depth or size at any time (and
may be disposed of and reallocated in the process).   You must release the
graphics context when done by calling its <tt>Release()</tt> method.
<p>
<h6><a name="RTFToC20">Important note about graphic contexts</a></h6><p>
<p>
This method should only be called by Lingo and Tool Xtras to do temporary
drawing into the stage window.	It should be called just before doing your
drawing, and the acquired interface should be released before returning control
to the calling application. This is because <tt>nativeGCInfo</tt> for the stage
buffer can become invalid at any time.	For example, the buffer may be dumped
and recreated if window size, monitor depth, or other display characteristics
change.  <p>
<p>
It's not always possible to obtain the a graphics context for the stage buffer.
During registration, startup, and shut-down, internal movie data structures may
not be initialized, thus trying to get the GC for it will return the err
<tt>kMoaDrErr_MovieNotOpen</tt>.  Xtra developers should never attempt to
acquire a graphics context and hold onto it; instead, you should acquire the
interface each time you need to draw and release it before your method
returns.<p>
<p>
Finally, this method should not be called to get a context for sprite or
transition drawing.  Instead, use the graphic context passed to you explicitly
in <tt>IMoaMmSpriteActor::Image()</tt> or
<tt>IMoaDrTransitionActor::Continue()</tt>.  If you attempt to use this
context, your Xtra will not work correctly in MIAWs, export, or other
applications such as Authorware. <p>
*/

	STDMETHOD(GetFrameIndexFromLabel)(THIS_
		PMoaChar pLabelName,  /* Pointer to a null-terminated C-string
containing the name of the marker associated with the score frame (case-insensitive) */
		PMoaDrFrameIndex pFrameIndex)  /* Pointer to a <tt>MoaDrFrameIndex</tt>
to receive the frame number of the label (marker) */
		PURE;

/* Category
Accessing frame labels
*/

/* Returns
<TABLE BORDER="2">
<TR><TD WIDTH=133><TT>kMoaErr_NoErr</TT></TD><TD WIDTH=457>if successful,
<TT>kMoaDrErr_LabelNotFound</TT> if marker doesn't exist.
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the frame number from a label (marker) name. <p>
*/

	STDMETHOD(GetFrameLabelFromIndex)(THIS_
		MoaDrFrameIndex frameIndex,  /* A <tt>MoaDrFrameIndex</tt> holding
the frame number of interest */
		PMoaChar pLabelName,  /* Pointer to a string buffer to receive the
name of the marker associated with the given score frame */
		MoaLong maxLen)  /* The length in bytes of the caller's C string buffer */
		PURE;

/* Category
Accessing frame labels
*/

/* Description
Obtains the name of the label (marker) at a given score frame number. Returns
an empty string if no marker exists for the frame.
*/

	STDMETHOD(SetFrameLabel)(THIS_
		MoaDrFrameIndex frameIndex,  /* A <tt>MoaDrFrameIndex</tt> holding the
number of the frame */
		PMoaChar pLabelName)  /* Pointer to a <tt>MoaChar</tt> to receive the name
of the marker associated with the given score frame */
		PURE;

/* Category
Accessing frame labels
*/

/* Description
Adds, modifies, or deletes a score label (marker) or a frame.  You pass in the
frame number and a C string for the new label.	If a label doesn't exist for
that frame, one will be added.	If one does exist, it'll be replaced with the
new one you specify.  If you pass in NULL for <tt><i>pLabelName</i></tt>, any
current label for that frame is deleted.
*/

	STDMETHOD(GetScoreAccess)(THIS_
		PIMoaDrScoreAccess FAR * ppScore)
		PURE;

/* Category
Acquiring IMoaDrScoreAccess
*/

/* Description
Gets a ScoreAccess interface provider for the movie's score.
*/

	STDMETHOD(Save)(THIS_
		PMoaChar pNewPathName,	/* Null-terminated C string for the path */
		MoaBoolParam bSaveExtCasts)
		PURE;

/* Category
Managing movies
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=157><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=433>Successful</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=157><TT>kMoaDrErr_DiskIO</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=433>IO error during file access
</TD></TR>
</TABLE>
*/

/* Description
<p>
Saves the movie to the path. Specify the complete path, including file name, to
save the cast to a new file.  Pass NULL as <tt><i>pNewPathName</i></tt>  to
save the cast in its previous file.  <p>
*/

	STDMETHOD(SendSpriteMessage)(THIS_
		MoaDrSpriteChanIndex chanIndex,  /* Channel number of sprite to which to send the<i>
</i>message. Valid values are from 1 to 48. */
		MoaMmSymbol handlerName,  /* Symbol for the handler (message)
name */
		MoaLong nArgs,	/* Number of arguments you're passing */
		PMoaMmValue pArgs,	/* Pointer to an array of <tt>MoaMmValues</tt>
containing arguments */
		PMoaMmValue pResult,  /* Pointer to a <tt>MoaMmValue</tt> to receive
a result */
		MoaBool FAR * pHandled)  /* arguments to a <tt>MoaBool</tt> to receive
TRUE if the message was handled somewhere down the chain or FALSE if it was not. */
		PURE;

/* Category
Scripting support
*/

/* Description
Sends a sprite message to be passed through the standard Director sprite
message hierarchy beginning with the sprite script of the sprite in the
specified channel. This method is similar to
<tt>IMoaDrSpriteCallback::SendSpriteMessage()</tt>.You must pass in NULL to
<tt><i>pResult</i></tt> if you do not expect a result; you must pass in a valid
pointer if you do expect a result.
*/

};

typedef IMoaDrMovie FAR * PIMoaDrMovie;



/* ----------------------------------------------------------------------------
/
/  IMoaDrMovie2
/
/ -------------------------------------------------------------------------- */


/* IID_IMoaDrMovie2: 5B0D82A7-3257-11d0-A222-00A02453444C */
DEFINE_GUID(IID_IMoaDrMovie2,
0x5b0d82a7, 0x3257, 0x11d0, 0xa2, 0x22, 0x0, 0xa0, 0x24, 0x53, 0x44, 0x4c);


#undef INTERFACE
#define INTERFACE IMoaDrMovie2

DECLARE_INTERFACE_(IMoaDrMovie2, IMoaUnknown)

/* Description
<p>
The IMoaDrMovie2 interface represents open movies in Director.	You acquire a
movie interface by calling the <tt>IMoaDrPlayer</tt> methods
<tt>GetActiveMovie()</tt> or <tt>GetNthMovie()</tt>. This returns to you an <tt>IMoaDrMovie</tt>
interface.	You can calling the <tt>QueryInterface</tt> method off this interface to retrieve
an <tt>IMoaDrMovie2 interface</tt><p>
<p>
<h5><a name="RTFToC2">Movie
properties</a></a></a></a></a></a></a></a></a></a></a></a></h5>
<p>
<tt>IMoaDrMovie2</tt> inherits from the <tt>IMoaMmPropOwner</tt> interface,
providing for access to data through the properties mechanism described in the
"Multimedia Services" chapter in the <i>Development Guide </i>document.  See
the "Properties" section for information on the properties defined for objects
providing the <tt>IMoaDrMovie</tt> interface.  <p>
<p>
<h5><a name="RTFToC3">Movie
media</a></a></a></a></a></a></h5>
<p>
<tt>IMoaDrMovie</tt> inherits from the <tt>IMoaDrMediaOwner</tt> interface,
providing for access to media through the media owner mechanism described in
the "Director Services" chapter in the <i>Development Guide </i>document.
Movies have one kind of media: scores.	Scores are editable through the
<tt>IMoaDrScoreAccess</tt> interface.  You acquire a movie's score data by
calling either <tt>IMoaDrMovie::GetMedia()</tt>, which returns a handle to the
score data, or<tt> GetScoreAccess()</tt>, which returns an
<tt>IMoaDrScoreAccess</tt> interface to the score data.  <p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the
property of interest.*/
		PMoaMmValue pPropValue)  /* Pointer to a <tt>MoaMmValue</tt>
to receive the value */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists and value was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists but couldn't get due
to internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for string
value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for other
value data
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the value of the specified movie property. To get the symbol from a
string, use the <tt>IMoaMmUtils::StringToSymbol()</tt>.  The caller is
responsible for releasing the value at <tt><i>pPropValue  </i></tt>with
<tt>IMoaMmUtils::ValueRelease()</tt> when it is no longer  needed.<p>
*/

	STDMETHOD(SetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the property of
interest */
		ConstPMoaMmValue pPropValue)  /* Pointer to a caller-owned
<tt>ConstPMoaMmValue</tt> structure from which to copy the new value */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists and value was set
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists, value ok, couldn't
set--internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Couldn't allocate memory for
setting string value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Couldn't allocate memory for
setting other value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_IntegerExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: integer value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_SymbolExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: symbol value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_FloatExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: float value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_StringExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: string value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PointExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: point value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_RectExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: rect value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: other value
expected (non-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch:
<TT>CMRef</TT> value expected
</TD></TR>
</TABLE>
*/

/* Description
<p>
Sets the value of the specified property. To get the symbol from a string, use
the <tt>IMoaMmUtils::StringToSymbol() </tt>method.	The caller continues to
maintain ownership of the value passed in, and should release it using
<tt>IMoaMmUtils::ValueRelease() </tt>when it is no longer needed.<p>
*/

	STDMETHOD(GetMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)  /* Pointer to a caller-owned
media information structure */
		PURE;

/* Category
Media owner methods
*/

/* Description
<p>
Gets movie media data by obtaining a copy of the media associated with a movie.
This is how one obtains the score data associated with a movie. Before making
this call, use <tt>IMoaDrUtils::NewMediaInfo() </tt>to fill out the structure,
specifying NULL for the <tt>aux </tt>field and <tt>kMoaDrMediaOpts_None
</tt>for the <tt>options </tt>field.  The caller partially populates a
<tt>MoaDrMediaInfo </tt>structure with symbols indicating the requested chunk
of media (<tt>labelSymbol</tt>) and the requested format
(<tt>formatSymbol</tt>).  After the call, the <tt>mediaData</tt> field is
populated with the requested data.	The type of this field depends on the
format requested.  The caller owns the data and is responsible for disposing
it, if applicable.	Typically, this data is either a <tt>MoaHandle</tt>, a
Macintosh handle or pointer, or a Windows global handle.  See Director
property.rtf for a table of <tt>mediaLabels </tt>and <tt>mediaFormats</tt>
supported for movies. <p>
*/

	STDMETHOD(SetMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)  /* Pointer to a caller-owned media
information structure */
		PURE;

/* Category
Media owner methods
*/

/* Description
Sets movie media data.	This is how one replaces the score data associated with
a movie.  This method copies caller-supplied media data and associates it with
the movie. Before making this call, use <tt>IMoaDrUtils::NewMediaInfo() </tt>to
fill out the structure, specifying NULL for the <tt>aux </tt>field and
<tt>kMoaDrMediaOpts_None </tt>for the <tt>options </tt>field.  The caller
populates a <tt>MoaDrMediaInfo </tt>structure with symbols indicating the
supplied chunk of media (<tt>labelSymbol</tt>) and the supplied format
(<tt>formatSymbol</tt>), and the media data itself (<tt>mediaData</tt>).  If
the label and format are supported by the movie, a call to this method copies
the caller's data and replaces any existing media data for the supplied label
for the movie.	Since the data is copied, the caller retains ownership of the
media data passed in. Typically this data is either a <tt>MoaHandle</tt>, a
Macintosh handle or pointer, or a Windows global handle.   See Director
property.rtf for a table of <tt>mediaLabels  </tt>and <tt>mediaFormats
</tt>supported for movies.
*/

	STDMETHOD(AttachMedia)(THIS_
		PMoaDrMediaInfo pMediaInfo)  /* Pointer to a caller-owned
media information structure */
		PURE;

/* Category
Media owner methods
*/

/* Description
<p>
Attaches media to a movie, releasing it from the caller. This is the same as
<tt>SetMedia()</tt> except instead of copying the data, it is moved to the
movie.	(In effect, a <tt>SetMedia() </tt>call followed by
<tt>ReleaseMedia()</tt>.)  Before making this call, use
<tt>IMoaDrUtils::NewMediaInfo() </tt>to fill out the structure, specifying NULL
for the <tt>aux </tt>field and <tt>kMoaDrMediaOpts_None </tt>for the
<tt>options </tt>field.<p>
<p>
On enter, the <tt>labelSymbol </tt>and <tt>formatSymbol </tt>fields should be
populated with symbols indicating which chunk of media is to be attach
(<tt>labelSymbol</tt>), and what format the media is supplied in
(<tt>formatSymbol</tt>).  The <tt>mediaData </tt>field should hold the data
itself (typically a <tt>MoaHandle</tt>, Macintosh Handle, or Windows global
handle) <p>
<p>
Upon return, if there is no error, the media has changed ownership and belongs
to the host application, and should no longer be referenced by the caller.
This method is provided to allow the host application to optimize
media-transfer if possible, preventing an extra copy of the media data, which
may occur with separate <tt>SetMedia() </tt>and <tt>ReleaseMedia()
</tt>calls).<p>
*/

	STDMETHOD(CallHandler)(THIS_
		MoaMmSymbol name,  /* Symbol of the handler name to call
MoaMmSymbol */
		MoaLong nArgs,	/* Number of arguments to pass */
		PMoaMmValue pArgs,	/* Array of <tt>MoaDrValues</tt> containing the
arguments to the call */
		PMoaMmValue pResult)  /* Pointer to a caller-owned <tt>MoaMmValue</tt> to
receive the return value */
		PURE;

/* Category
Scripting support
*/

/* Description
Calls the Lingo handler <tt><i>name</i></tt> in the movie. The
<tt><i>nArgs</i></tt>  argument is the number of arguments to the handler, the
<i>pArgs</i> argument is a <tt>MoaMmList</tt> of arguments as
<tt>MoaMmValues</tt>.  You must pass in NULL to <tt><i>pResult</i></tt>  if you
do not expect a result.  You must pass in a valid pointer if you do expect a
result.
*/

	STDMETHOD(GetCastCount)(THIS_
		MoaLong FAR * pCastCount)  /* Pointer to a <tt>MoaLong</tt> to receive
the number of casts */
		PURE;

/* Category
Managing casts
*/

/* Description
Obtains the number of casts in the movie.
*/

	STDMETHOD(GetNthCast)(THIS_
		MoaDrCastIndex movieCastIndex,	/* Index of the cast (from 1 to
GetCastCount()) of interest */
		PIMoaDrCast FAR * ppIMoaDrCast)  /* Pointer to a <tt>PIMoaDrCast</tt>
to receive a pointer to the cast interface */
		PURE;

/* Category
Managing casts
*/

/* Description
Obtains an interface to one of the movie's casts by index. The interface is then
owned by the caller, and the caller is responsible for releasing it when it is no longer
needed.
*/

	STDMETHOD(GetCastFromName)(THIS_
		PMoaChar pCastName,  /* Pointer to a null-terminated C string
containing the cast name of interest */
		PIMoaDrCast FAR * ppIMoaDrCast)  /* Pointer to a
<tt>PIMoaDrCast</tt> to receive a pointer to the cast interface */
		PURE;

/* Category
Managing casts
*/

/* Description
Obtains an interface to one of the movie's casts by name, as it appears in
the Cast Properties dialog. The interface is then owned by the caller, and
the caller is responsible for releasing it when it is no longer needed.
*/

	STDMETHOD(GetCastIndexFromName)(THIS_
		PMoaChar pCastName,  /* Pointer to a null-terminated C string
containing the cast name of interest */
		MoaDrCastIndex FAR * pCastIndex)  /* Pointer to a
<tt>MoaDrCastIndex</tt> to receive the index */
		PURE;

/* Category
Managing casts
*/

/* Description
Obtains the movie cast index associated with a named cast. This is a value
from 1 to <tt>GetCastCount()</tt>.
*/

	STDMETHOD(NewCast) (THIS_
		PMoaChar pCastName,
		MoaBoolParam bExternal,
		PMoaDrCastIndex pNewCastIndex)
		PURE;

/* Category
Managing casts
*/

/* Description
Creates a new cast and add it to the movie's cast list.  Returns the position
of the new cast in the <tt><i>pNewCastIndex</i></tt> argument.
*/

	STDMETHOD(AddExternalCast) (THIS_
		PMoaChar pCastName,  /* The user reference name for the cast */
		PMoaChar pPathName,  /* The full path name for an external cast */
		PMoaDrCastIndex pNewCastIndex)	/* <tt>PMoaDrCastIndex</tt> for
the position in the cast list */
		PURE;

/* Category
Managing casts
*/

/* Description
<p>
Adds an existing external cast to the movie's cast list.  Returns in
<tt><i>pNewCastIndex</i></tt> the position of the cast in the movie's cast
list.  <p>
*/

	STDMETHOD(RemoveCast)(THIS_
		MoaDrCastIndex castIndexToRemove)  /* <tt>MoaDrCastIndex</tt> for
the cast to remove */
		PURE;

/* Category
Managing casts
*/

/* Description
Removes the cast specified by <tt><i>castToRemove</i></tt> from the movie's
cast list.
*/

	STDMETHOD(GetCMRefFromMemberName)(THIS_
		PMoaChar pMemberName,  /* Pointer to a null-terminated C
string containing the cast member name of interest */
		PMoaDrCMRef pCastMemRef)  /* Pointer to a <tt>MoaDrCMRef</tt>
to receive cast member reference */
		PURE;

/* Category
Managing casts
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=229><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=361>Successful</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=229><TT>kMoaDrErr_CastMemNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=361>Cast member not found
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the cast member reference (<tt>MoaDrCMRef</tt>) for a cast member from
its name.  This method scans all of the casts for the movie, and returns the
<tt>MoaDrCMRef</tt> for the first cast member whose name matches the one
supplied.  If no cast member is found with the specified name,
<tt>kMoaDrErr_CastMemNotFound </tt>is returned and
<tt><i>pCastMemRef</i></tt><i> </i>is set to a null reference .  Use
<tt>CMRef_IsNull()</tt> to test the result.<p>
*/

	STDMETHOD(GetCastMemFromCMRef)(THIS_
		PMoaDrCMRef pCastMemRef,  /* Pointer to a <tt>MoaDrCMRef</tt>
which specifies the cast member of interest */
		PIMoaDrCastMem FAR * ppIMoaDrCastMem)  /* Pointer to a
<tt>PIMoaDrCastMem</tt> to receive the interface for the cast member */
		PURE;

/* Category
Acquiring ImoaDrCastMem
*/

/* Description
<p>
Obtains the <tt>IMoaDrCastMem</tt> interface for the cast member with the
supplied cast member reference.  The cast member reference specifies the
<tt>movieCastIndex </tt>(index to cast in the movie) and <tt>memberIndex
</tt>(index to cast member slot position within the cast); use the CMRef_
macros in drtypes.h to create and access a <tt>0</tt>.	The caller owns the
returned  interface and is responsible for releasing it when it is no longer
needed.  <p>
*/

	STDMETHOD(GetCMRefFromCMId)(THIS_
		PMoaDrCMId	pCastMemId,/* Pointer to a <tt>MoaDrCMId</tt>
identifying the cast member to search for*/
		PMoaDrCMRef pCastMemRef)/* Pointer to a <tt>MoaDrCMRef</tt>
to receive cast member reference */
		PURE;

	/* Category
Managing casts
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=229><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=361>Successful</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=229><TT>kMoaDrErr_CastMemNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=361>Cast member not found
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the cast member reference (<tt>MoaDrCMRef</tt>) for a cast member from
its unique identifier.	This method scans all of the casts for the movie, and returns the
<tt>MoaDrCMRef</tt> for the cast member whose id matches the one
supplied.  If no cast member is found with the specified id,
<tt>kMoaDrErr_CastMemNotFound </tt>is returned and
<tt><i>pCastMemRef</i></tt><i> </i>is set to a null reference .  Use
<tt>CMRef_IsNull()</tt> to test the result.<p>
*/

	STDMETHOD(GetCMIdFromCMRef)(THIS_
		PMoaDrCMRef pCastMemRef,/* Pointer to a <tt>MoaDrCMRef</tt>
	identifying the cast member we want a unique ID from*/
		PMoaDrCMId	pCastMemId) /* Pointer to a <tt>MoaDrCMId</tt>
to recieve the unique cast member identifier */
		PURE;

/* Category
managing casts
*/

/* Description
<p>
Obtains a unique identifier (<tt> MoaDrCMId</tt>) for the cast member referred to
by <i>pCastMemRef</i>.	This identifer can be used to retrieve the <tt>MoaDrCMRef</tt> for
this cast member at a later time, even if the cast member has been moved across cast boundaries.
*/

	STDMETHOD(UpdateStageRect) (THIS_
		MoaRect FAR * pWindowRect,	/* Pointer to a <tt>MoaRect</tt> describing
the area of the stage window to update */
		MoaRect FAR * pBufferRect)	/* Pointer to a <tt>MoaRect</tt> describing
the area of the offscreen buffer from where to update */
		PURE;

/* Category
Imaging support
*/

/* Description
Updates a rectangular area of the stage window from a rectangular area of the
stage's offscreen buffer.  Stretching or shrinking of parts of the image can be
achieved by using a <tt>windowRect </tt>which differs in size from the
<tt>bufferRect</tt>.  Note that this call does not cause all sprites on the
stage to be reimaged; it simply refreshes the stage window from Director's
offscreen compositing buffer.
*/

	STDMETHOD(GetStageWindowGC)(THIS_
		PIMoaMmGC FAR * ppWindowGC)  /* Pointer to a <tt>IMoaMmGC</tt>
interface for the stage window */
		PURE;

/* Category
Imaging support
*/

/* Description
<p>
Obtains the graphics context for the stage window.	This includes the bounds
rectangle, pixel depth, as well as platform-specific information (such as the
WindowPtr of the window on the Macintosh, or the HWND on Windows). This
information is valid only for the duration of the current call into your Xtra
method, because the stage window can change in depth or size at any time (and
may be disposed of and reallocated in the process).   You must release the
graphics context when done by calling its <tt>Release() </tt>method.   <p>
<p>
<h6><a name="RTFToC22">Important note about graphic contexts</a></h6><p>
<p>
This method should only be called by Lingo and Tool Xtras to do temporary
drawing into the stage window.	It should be called just before doing your
drawing, and the acquired interface should be released before returning control
to the calling application. This is because <tt>nativeGCInfo</tt> for the stage
buffer can become invalid at any time.	For example, the buffer may be dumped
and recreated if window size, monitor depth, or other display characteristics
change.  <p>
<p>
It's not always possible to obtain the a graphics context for the stage window.
During registration, startup, and shut-down, internal movie data structures may
not be initialized, thus trying to get the GC for it will return the err
<tt>kMoaDrErr_MovieNotOpen</tt>.  Xtra developers should never attempt to
acquire a graphics context and hold onto it; instead, you should acquire the
interface each time you need to draw and release it before your method
returns.<p>
<p>
Also, <tt>GetStageWindowGC()</tt> should not be used to get a parent window for
Windows(TM) dialogs.  The correct procedure is to use the <tt>IMoaMmUtils</tt>
Windows API cover methods such as <tt>WinDialogBox()</tt> and
<tt>WinDialogBoxParam()</tt>.  If you're putting up a system dialog on Windows,
use <tt>WinGetParent()</tt> to get the parent HWND to use, and bracket your
dialog call with <tt>WinPrepareDialogBox()</tt> and
<tt>WinUnprepareDialogBox()</tt>.<p>
<p>
Finally, these calls should not be used for sprite or transition drawing.
Instead, use the graphic context passed to you explicitly in
<tt>IMoaMmSpriteActor::Image()</tt> or
<tt>IMoaDrTransitionActor::Continue()</tt>.  If you do attempt to use this
context, your Xtra will not work correctly in MIAWs, export, or other
applications such as Authorware.
 <p>
*/

	STDMETHOD(GetStageBufferGC)(THIS_
		PIMoaMmGC FAR * ppBufferGC)  /* Pointer to a <tt>IMoaMmGC</tt> interface
for the stage offscreen buffer */
		PURE;

/* Category
Imaging support
*/

/* Description
Obtains the graphics context for the stage offscreen buffer.  This includes the
bounds rectangle, pixel depth, as well as platform-specific information (such
as the WindowPtr of the window on the Macintosh or the HWND on Windows). This
information is valid only for the duration of the current call into your Xtra
method, because the stage window can change in depth or size at any time (and
may be disposed of and reallocated in the process).   You must release the
graphics context when done by calling its <tt>Release()</tt> method.
<p>
<h6><a name="RTFToC20">Important note about graphic contexts</a></h6><p>
<p>
This method should only be called by Lingo and Tool Xtras to do temporary
drawing into the stage window.	It should be called just before doing your
drawing, and the acquired interface should be released before returning control
to the calling application. This is because <tt>nativeGCInfo</tt> for the stage
buffer can become invalid at any time.	For example, the buffer may be dumped
and recreated if window size, monitor depth, or other display characteristics
change.  <p>
<p>
It's not always possible to obtain the a graphics context for the stage buffer.
During registration, startup, and shut-down, internal movie data structures may
not be initialized, thus trying to get the GC for it will return the err
<tt>kMoaDrErr_MovieNotOpen</tt>.  Xtra developers should never attempt to
acquire a graphics context and hold onto it; instead, you should acquire the
interface each time you need to draw and release it before your method
returns.<p>
<p>
Finally, this method should not be called to get a context for sprite or
transition drawing.  Instead, use the graphic context passed to you explicitly
in <tt>IMoaMmSpriteActor::Image()</tt> or
<tt>IMoaDrTransitionActor::Continue()</tt>.  If you attempt to use this
context, your Xtra will not work correctly in MIAWs, export, or other
applications such as Authorware. <p>
*/

	STDMETHOD(GetFrameIndexFromLabel)(THIS_
		PMoaChar pLabelName,  /* Pointer to a null-terminated C-string
containing the name of the marker associated with the score frame (case-insensitive) */
		PMoaDrFrameIndex pFrameIndex)  /* Pointer to a <tt>MoaDrFrameIndex</tt>
to receive the frame number of the label (marker) */
		PURE;

/* Category
Accessing frame labels
*/

/* Returns
<TABLE BORDER="2">
<TR><TD WIDTH=133><TT>kMoaErr_NoErr</TT></TD><TD WIDTH=457>if successful,
<TT>kMoaDrErr_LabelNotFound</TT> if marker doesn't exist.
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the frame number from a label (marker) name. <p>
*/

	STDMETHOD(GetFrameLabelFromIndex)(THIS_
		MoaDrFrameIndex frameIndex,  /* A <tt>MoaDrFrameIndex</tt> holding
the frame number of interest */
		PMoaChar pLabelName,  /* Pointer to a string buffer to receive the
name of the marker associated with the given score frame */
		MoaLong maxLen)  /* The length in bytes of the caller's C string buffer */
		PURE;

/* Category
Accessing frame labels
*/

/* Description
Obtains the name of the label (marker) at a given score frame number. Returns
an empty string if no marker exists for the frame.
*/

	STDMETHOD(SetFrameLabel)(THIS_
		MoaDrFrameIndex frameIndex,  /* A <tt>MoaDrFrameIndex</tt> holding the
number of the frame */
		PMoaChar pLabelName)  /* Pointer to a <tt>MoaChar</tt> to receive the name
of the marker associated with the given score frame */
		PURE;

/* Category
Accessing frame labels
*/

/* Description
Adds, modifies, or deletes a score label (marker) or a frame.  You pass in the
frame number and a C string for the new label.	If a label doesn't exist for
that frame, one will be added.	If one does exist, it'll be replaced with the
new one you specify.  If you pass in NULL for <tt><i>pLabelName</i></tt>, any
current label for that frame is deleted.
*/

	STDMETHOD(GetScoreAccess)(THIS_
		PIMoaDrScoreAccess FAR * ppScore)
		PURE;

/* Category
Acquiring IMoaDrScoreAccess
*/

/* Description
Gets a ScoreAccess interface provider for the movie's score.
*/

	STDMETHOD(Save)(THIS_
		PMoaChar pNewPathName,	/* Null-terminated C string for the path */
		MoaBoolParam bSaveExtCasts)
		PURE;

/* Category
Managing movies
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=157><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=433>Successful</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=157><TT>kMoaDrErr_DiskIO</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=433>IO error during file access
</TD></TR>
</TABLE>
*/

/* Description
<p>
Saves the movie to the path. Specify the complete path, including file name, to
save the cast to a new file.  Pass NULL as <tt><i>pNewPathName</i></tt>  to
save the cast in its previous file.  <p>
*/

	STDMETHOD(SendSpriteMessage)(THIS_
		MoaDrSpriteChanIndex chanIndex,  /* Channel number of sprite to which to send the<i>
</i>message. Valid values are from 1 to 48. */
		MoaMmSymbol handlerName,  /* Symbol for the handler (message)
name */
		MoaLong nArgs,	/* Number of arguments you're passing */
		PMoaMmValue pArgs,	/* Pointer to an array of <tt>MoaMmValues</tt>
containing arguments */
		PMoaMmValue pResult,  /* Pointer to a <tt>MoaMmValue</tt> to receive
a result */
		MoaBool FAR * pHandled)  /* arguments to a <tt>MoaBool</tt> to receive
TRUE if the message was handled somewhere down the chain or FALSE if it was not. */
		PURE;

/* Category
Scripting support
*/

/* Description
Sends a sprite message to be passed through the standard Director sprite
message hierarchy beginning with the sprite script of the sprite in the
specified channel. This method is similar to
<tt>IMoaDrSpriteCallback::SendSpriteMessage()</tt>.You must pass in NULL to
<tt><i>pResult</i></tt> if you do not expect a result; you must pass in a valid
pointer if you do expect a result.
*/
	STDMETHOD(MoveCastMember)(THIS_
		PMoaDrCMRef pSrcMemRef,/* Pointer to a <tt>MoaDrCMRef</tt> containing the cast member you
		want to move  */
		PMoaDrCMRef pDestMemRef)/* Pointer to the <tt>MoaDrCMRef</tt> containing the location
		you want to move it to	*/
		PURE;
/* Category
Managing Casts
*/

/* Description
Moves the cast member in the location referred to by <tt>pSrcMemRef</tt> to the location
referred to by <tt>pDestMemRef</tt>.  If there is an existing cast member in the destination
slot, it will be removed.
*/

};

typedef IMoaDrMovie2 FAR * PIMoaDrMovie2;




/* ----------------------------------------------------------------------------
/
/  IMoaDrMovieStage
/
/ -------------------------------------------------------------------------- */

/* IID_IMoaDrMovieStage */
DEFINE_GUID(IID_IMoaDrMovieStage, 0x4418DAB2L, 0xFEF7, 0x11D2, 0x8C, 0xDC, 
			0x00, 0x05, 0x02, 0x0E, 0x2E, 0x6D);



#undef INTERFACE
#define INTERFACE IMoaDrMovieStage

DECLARE_INTERFACE_(IMoaDrMovieStage, IMoaUnknown)

/* Description
<p>
The IMoaDrMovieStage interface provides access to new stage-related
functions associated with a movie.	IMoaDrMovieStage is an additional interface
on the same movie class that supports IMoaDrMovie and IMoaDrMovie2.  You acquire a
movie interface by calling the <tt>IMoaDrPlayer</tt> methods
<tt>GetActiveMovie()</tt> or <tt>GetNthMovie()</tt>. This returns to you an <tt>IMoaDrMovie</tt>
interface.	You can calling the <tt>QueryInterface</tt> method off this interface to retrieve
an <tt>IMoaDrMovieStage interface</tt><p>
<p>
<h5><a name="RTFToC2">Movie
properties</a></a></a></a></a></a></a></a></a></a></a></a></h5>
<p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(TransformStagePointUnscaledToScaled)(THIS_
				PMoaPoint pStagePoint)			/* IN: The unscaled point, OUT: The scaled point */
		PURE;

/* Category
	Movie stage utility functions
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Point valid and transformed point was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pStagePoint </FONT></I></TT>passed in
</TD></TR>
</TABLE>
*/

/* Description
<p>
Transforms a given point from unscaled to scaled stage coordinates.
Unscaled is the coordinate space of the original, un-zoomed
movie.	Scaled is the coordinate space of the movie scaled to its
current drawRect.
<p>
*/

	STDMETHOD(TransformStagePointScaledToUnscaled)(THIS_
				PMoaPoint pStagePoint)			/* IN: The scaled point, OUT: The unscaled point */
		PURE;

/* Category
	Movie stage utility functions
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Point valid and transformed point was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pStagePoint </FONT></I></TT>passed in
</TD></TR>
</TABLE>
*/

/* Description
<p>
Transforms a given point from scaled to unscaled stage coordinates.
Scaled is the coordinate space of the movie scaled to its
current drawRect.  Unscaled is the coordinate space of the original, 
un-zoomed movie. 
<p>
*/

};

typedef IMoaDrMovieStage FAR * PIMoaDrMovieStage;


/* ----------------------------------------------------------------------------
/
/  IMoaDrPlayer
/
/ -------------------------------------------------------------------------- */


/* IID_IMoaDrPlayer: AC401B780000FA7D00000800072C6326 */
DEFINE_GUID(IID_IMoaDrPlayer, 0xAC401B78L, 0x0000, 0xFA7D, 0x00, 0x00, 0x08,
				0x00, 0x07, 0x2C, 0x63, 0x26);


#undef INTERFACE
#define INTERFACE IMoaDrPlayer

DECLARE_INTERFACE_(IMoaDrPlayer, IMoaMmPropOwner)

/* Descripiton
<p>
The <tt>IMoaDrPlayer</tt> interface provides top-level access to the interfaces
representing the Director object model.  <tt>IMoaDrPlayer</tt> is provided by
the Director callback object, and is acquired by calling
<tt>QueryInterface()</tt> on the <tt>IMoaCallback</tt> interface, provided
through the <tt>pCallback</tt> instance variable of all MOA objects.  <p>
<p>
From an instance of the <tt>IMoaDrPlayer</tt> interface, you can access the
movies, casts, cast members, and scores that make up all open movies.  <p>
<p>
<h5><a name="RTFToC2">Player
properties</a></a></a></a></a></a></a></a></a></a></a>
</a></h5>
<p>
<tt>IMoaDrPlayer</tt> inherits from the <tt>IMoaMmPropOwner</tt> interface,
providing for access to data through the properties mechanism described in the
chapter "Properties" earlier in this document.<p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the
property of interest */
		PMoaMmValue pPropValue)  /* Pointer to a caller-owned
<tt>MoaMmValue</tt> structure to receive the value of the property */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists and value was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid<TT> <I><FONT SIZE=2
FACE="Courier New">pPropValue</FONT></I> </TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists but couldn't get due
to internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for string
value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for other
value data
</TD></TR>
</TABLE>
*/

/* Description
<p>
Obtains the value of the specified player property. To get the symbol from a
string, use the <tt>IMoaMmUtils::StringToSymbol()</tt>.The caller  is
responsible for releasing the value with  <tt>IMoaMmUtils::ValueRelease()</tt>
when it is no longer needed.<p>
*/

	STDMETHOD(SetProp)(THIS_
		MoaMmSymbol symbol,  /* The <tt>MoaMmSymbol</tt> for the
property of interest */
		ConstPMoaMmValue pPropValue)  /* Pointer to a caller-owned
<tt>MoaMmValue</tt> structure from which to copy the value */
		PURE;

/* Category
Property owner methods
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists and value was set
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists, value ok, can't
set--internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Can't allocate memory for setting
string value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Can't allocate memory for setting
other value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_IntegerExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: integer value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_SymbolExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: symbol value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_FloatExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: float value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_StringExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: string value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PointExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: point value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_RectExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: rect value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: other value
expected (non-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch:
<TT>CMRef</TT> value expected
</TD></TR>
</TABLE>
*/

/* Description
<p>
Sets a player property to a new value. To get the symbol from a string, use the
<tt>IMoaMmUtils::StringToSymbol()</tt>.  The caller continues to maintain
ownership of the value passed in, and should release it using
<tt>IMoaMmUtils::ValueRelease() </tt>when it is no longer needed.
<p>
*/

	STDMETHOD(CallHandler) (THIS_
		MoaMmSymbol name,  /* The <tt>MoaMmSymbol</tt> for the name
of the method to call */
		MoaLong nArgs,	/* The number of arguments you are passing
 to the handler */
		PMoaMmValue pArgs,	/* The array of <tt>MoaMmValue</tt>
arguments */
		PMoaMmValue pResult)  /* Pointer to a caller-owned
<tt>MoaMmValue</tt> to receive a result value from the handler */
		PURE;

/* Category
Scripting support
*/

/* Description
<p>
Calls the Lingo handler <tt><i>name</i></tt> in the currently active movie. The
<tt><i>nArgs</i></tt>  argument is the number of arguments to the handler, the
<i>pArgs</i> argument is a <tt>MoaMmList</tt> of arguments as
<tt>MoaMmValues</tt>.  You must pass in NULL to <tt><i>pResult</i></tt>  if you
do not expect a result.  You must pass in a valid pointer if you do expect a
result. <p>
<p>
This method has the same behavior as obtaining the active movie interface by
calling <tt>GetActiveMovie()</tt>, and then calling
<tt>IMoaDrMovie::CallHandler()</tt>.  This method is supplied as a convenience,
as it eliminates the extra call needed to <tt>GetActiveMovie() </tt>for this
common operation.<p>
*/

	STDMETHOD(GetActiveMovie)(THIS_
		PIMoaDrMovie FAR * ppIMoaDrMovie)  /* Pointer to a
<tt>PIMoaDrMovie</tt> to receive new interface */
		PURE;

/* Category
Movie access
*/

/* Description
Gets an interface to the currently active movie. The active movie may
vary depending upon the context in which this method is called. If there
are no MIAWs executing, the active movie is the single main movie
currently being played. If MIAWs are present, the active movie can be a
MIAW. This is the case if a Lingo Xtra is being called by a MIAW Lingo
script; if an asset Xtra is being used by a MIAW; or if a Transition Xtra is
being called on behalf of a MIAW. The caller is responsible for releasing
the movie interface when it is no longer needed.
*/

	STDMETHOD(GetMovieCount)(THIS_
		MoaLong FAR * pMovieCount) /* Pointer to a <tt>MoaLong</tt> to
receive count of open movies */
		PURE;

/* Category
Movie access
*/

/* Description
Obtains the current number of movies open in the player. In
Director 5.0, there is always at least one open movie, the main stage movie.
Each open movie in a window also contributes to the movie count. Using
<tt>GetNthMovie()</tt>, you can access any open movie directly.
*/

	STDMETHOD(GetNthMovie)(THIS_
		MoaLong movieIndex,  /* Index of movie to obtain interface
for; ranges from 1 to the number of open movies */
		PIMoaDrMovie FAR * ppIMoaDrMovie)  /* Pointer to a
<tt>PIMoaDrMovie</tt> to receive new interface */
		PURE;

/* Category
Movie access
*/

/* Description
Gets an interface to the <i>n</i>th movie in the player's movie list. There's
always at least one open movie in Director 5.0, the main stage movie.  Use
<tt>GetMovieCount() </tt>to determine the number of open movies.  Using this
method, you could, for example, access data in a Movie In A Window even though
you're currently being called in the context of the main stage movie. The
caller is responsible for releasing the movie interface when it is no longer
needed.Gets an interface to the nth movie in the player's movie list. There's
*/

	STDMETHOD(ResolveFileName)(THIS_
		ConstPMoaChar pFileName,  /* Pointer to C string of filename in
native platform format to resolve */
		PMoaChar pPathName,  /* Pointer to C string to receive
resolved full pathname */
		MoaLong maxLen)  /* Size of the caller's <tt><i>pPathName
</i></tt>buffer */
		PURE;

/* Category
Accessing files
*/

/* Description
Resolves a file name to a full path name using Director's standard
filename resolution algorithm. This can include scanning the searchPaths,
and so on, for the appropriate file. Director's "@:" filename notation is also
supported here.
*/

	STDMETHOD(GetCastMemTypeCount)(THIS_
		MoaLong FAR * pTypeCount)  /* Pointer to a <tt>MoaLong</tt> to
receive the count */
		PURE;

/* Category
Cast member access
*/

/* Description
Obtains the number of currently registered cast member types. This value
is the sum of Director's built-in types and any types registered by external
asset Xtras.
*/

	STDMETHOD(GetNthCastMemTypeSymbol)(THIS_
		MoaLong typeIndex,	/* Index (from 1 to <tt>GetCastMemTypeCount()</tt>) of the cast
member type of interest */
		PMoaMmSymbol pSymbol)  /* Pointer to a <tt>MoaMmSymbol</tt> to
receive the type's symbol */
		PURE;

/* Category
Cast member access
*/

/* Description
Obtains the unique run-time symbol for the specified cast member type
by index. This symbol is then passed as a parameter to callback methods
operating on cast member types, such as <tt>GetCastMemTypeDisplayName()</tt>.
*/

	STDMETHOD(GetCastMemTypeDisplayName)(THIS_
		MoaMmSymbol typeSymbol,  /* The symbol of the type of interest */
		PMoaChar pName,  /* Pointer to buffer to receive null-terminated C string text of the
display name */
		MoaLong maxLen)  /* Size of the caller's name buffer */
		PURE;

/* Category
Cast member access
*/

/* Description
Obtains the user-readable text string associated with a cast member type. This
is the same string that appears in the Insert submenu in Director.	You can
obtain <tt>typeSymbol </tt>using <tt>StringToSymbol() </tt>or
<tt>GetNthCastMemTypeSymbol()</tt>.
*/

	STDMETHOD(GetGlobalVarValue)(THIS_
		MoaMmSymbol globalVarName,	/* The symbol of the global variable of interest */
		PMoaMmValue pValue)  /* Pointer to a <tt>MoaMmValue</tt> to receive the value */
		PURE;

/* Category
Scripting support
*/

/* Description
Obtains the value of a Lingo global variable.  Use
<tt>IMoaMmUtils::StringToSymbol() </tt>to get a symbol from a string for
<tt><i>globalVarName</i></tt>. The caller is responsible for releasing the
value with <tt>IMoaMmUtils::ValueRelease() </tt>when it is no longer needed.
*/

	STDMETHOD(SetGlobalVarValue)(THIS_
		MoaMmSymbol globalVarName,	/* The symbol of the global variable of interest */
		PMoaMmValue pValue)  /* Pointer to a <tt>MoaMmValue</tt> to copy the new value
from */
		PURE;

/* Category
Scripting support
*/

/* Description
Sets the value of a Lingo global variable. Use
<tt>IMoaDrUtils-&gt;StringToSymbol() </tt>to get a symbol from a string for
<tt><i>globalVarName. </i></tt>The caller maintains ownership of the value
passed in, and should release it using <tt>IMoaMmUtils::ValueRelease()
</tt>when it is no longer needed.
*/

};

typedef IMoaDrPlayer FAR * PIMoaDrPlayer;


/* Synonyms for old method names */
#define CallHandlerInActiveMovie(me, name, nargs, pargs, presult) \
			CallHandler(me, name, nargs, pargs, presult)


/* ----------------------------------------------------------------------------
/
/	IMoaDrUtils - Director-specific utility functions
/
/ -------------------------------------------------------------------------- */

/* IID_IMoaDrUtils: AC96CFC00045659700000040105023FB */
DEFINE_GUID(IID_IMoaDrUtils, 0xAC96CFC0L, 0x0045, 0x6597, 0x00, 0x00, 0x00,
				0x40, 0x10, 0x50, 0x23, 0xFB);

#undef INTERFACE
#define INTERFACE IMoaDrUtils

DECLARE_INTERFACE_(IMoaDrUtils, IMoaUnknown)

/* Description
This interface provides Director-specific utilities.  It complements the
features of the <tt>IMoaMmUtils</tt> interface, providing application-specific
services to Xtras.
*/

{
	STD_IUNKNOWN_METHODS

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
any preexisting value before making this call.	The caller is responsible for
releasing the returned value using <tt>IMoaMmUtils::ValueRelease()</tt>.
*/

	STDMETHOD(NewMediaInfo)(THIS_
		MoaMmSymbol labelSymbol,
		MoaMmSymbol formatSymbol,
		PMoaVoid mediaData,
		MoaLong options,  /* Used when setting image media. Use
a <tt>kMoaDrImgMediaOpts_</tt> constant */
		PMoaVoid aux,  /* Pointer to a <tt>MoaDrImageAuxInfo</tt>
structure if you use the "AuxInfo" option */
		PMoaDrMediaInfo pMediaInfo)
		PURE;

/* Category
Media management
*/

/* Description
<p>
Populates a <tt>MoaDrMediaInfo </tt>structure.	This call does not allocate any
media data, it simply populates the supplied structure.  If populating the
structure for a call to <tt>SetMedia()</tt>, you must populate the
<tt><i>labelSymbol</i></tt>, <tt><i>formatSymbol</i></tt>, <tt><i>mediaData
</i></tt>, <tt><i>options</i></tt> , and <tt><i>aux </i></tt>fields
accordingly.  <tt><i>options </i></tt>tells Director how the palette and color
depth of the image should be set; it currently varies only for "image" label
media.	<tt><i>aux </i></tt>is used only when specifying <tt>AuxInfo
</tt>options; it is ignored for other options.	If populating the structure for
a call to <tt>GetMedia()</tt>, only the <tt><i>labelSymbol </i></tt>and
<tt><i>formatSymbol </i></tt>fields are required.<p>
<p>
Before a <tt>GetMedia()</tt>, <tt>SetMedia()</tt>, or <tt>AttachMedia()</tt>
call, use this method to fill out the supplied structure, specifying NULL for
the <tt>aux </tt>field.  Using this call forces you to fill out all the needed
parameters.<p>
<p>
When setting or getting any media label other than "image", use the value
<tt>kMoaDrMediaOpts_None </tt>for the <tt><i>options</i> </tt>argument. When
setting or attaching an "image" media label type, there are a number of image
media constants to use as the <tt><i>options</i></tt> argument.  These are
described in the "Constants" section later in this document.  <p>
*/

	STDMETHOD(MediaRelease)(THIS_
		PMoaDrMediaInfo pMediaInfo)
		PURE;

/* Category
Media management
*/

/* Description
Releases the bulk media data referenced by the <tt>MoaDrMediaInfo
</tt>structure in <tt><i>pMediaInfo</i></tt><i>.</i>  The <tt>formatSymbol
</tt>and <tt>mediaData </tt>fields of <tt>pMediaInfo </tt>must be valid on
entry.	If the format of the media data is unknown to the host application,
<tt>kMoaDrErr_MediaFormatNotSupported </tt>is returned and the media data is
not be released.  You can also release the data yourself using the appropriate
native memory manager call (if the media data is a native data type), such as
<tt>KillPicture() </tt>for "<tt>macPICT</tt>".	The host application does not
guarantee that it can dispose media data of all formats; only those that are
built-in data types of the host application are supported by this call.
*/

	STDMETHOD(NewScoreAccess)(THIS_ 
		PIMoaDrScoreAccess FAR * ppScore)
		PURE;

/* Category
Acquiring IMoaDrScoreAccess
*/

/* Description
Creates a new instance of an object supporting <tt>IMoaDrScoreAccess</tt>.	The
<tt>IMoaDrScoreAccess</tt> interface is used to access and edit score data for
movies and film loops.	Normally, if you want to access an existing movie or
film loop, you would call <tt>IMoaDrMovie::GetScoreAccess()</tt> or
<tt>IMoaDrCastMem::GetScoreAccess()</tt>.  However, if you do not want to
create new score from scratch which is not yet associated with a movie or film
loop, this method can be used.	To save the resulting score, you must call the
<tt>IMoaDrScoreAccess::SetOwner() </tt>method to associate an owner object with
the score, and then call <tt>Commit() </tt>to save the score to the object
*/

	STDMETHOD(RegisterNotificationClient)(THIS_
		PIMoaDrNotificationClient pNotificationClient,	/* Pointer
to a pre-existing <tt>IMoaDrNotificationClient</tt> interface */
		MoaDrNotifyType notifyType,  /* Value indicating the type
of notification requested */
		PMoaVoid refCon)
		PURE;

/* Category
Managing notification clients
*/

/* Description
<p>
Registers a notification client object with the host application.  Notification
clients are used to receive notification from the host application when certain
events occur.  <tt><i>pClient </i></tt>is a pointer to a pre-existing
<tt>IMoaDrNotificationClient</tt> interface.  <tt><i>notifyType </i></tt>is a
value indicating the type of notification requested.  When the internal event
occurs, the host application calls the <tt>Notify() </tt>method of the
specified  <tt>IMoaDrNotificationClient </tt>interface.  Additional
notification-specific information can be supplied by the host application in
the <tt>Notify() </tt>method's <tt><i>refCon </i></tt>parameter.  To cease
notification for a given <tt>PIMoaDrNotifyClient </tt>and
<tt><i>notifyType</i></tt>, call <tt>UnregisterNotifyClient()</tt>.<p>
<p>
The same <tt>IMoaDrNotificationClient </tt>interface can be used to service
multiple <tt><i>notifyTypes</i></tt>.  When calling
<tt>UnregisterNotificationClient()</tt>, only the notification for the supplied
<tt><i>notifyType </i></tt>is disabled.<p>
<p>
Acceptable values for <tt>notifyType</tt> are:<p>
<p>
<tt>kMoaDrNotifyType_DocFileIO</tt> 		<b>Windows(TM) version
only</b><p>
<p>
Notification occurs whenever a chunk is read from or written to any a movie or
cast file document in use by the host application.	This is most interesting
for Windows 3.1, where the operating system fails to read from a CD-ROM if
Redbook audio is playing off of the same device.  Use this hook to cease
Redbook audio playing, so that subsequent document chunk file reads and writes
will be successful.  In the <tt><i>refCon </i></tt>argument of the <tt>Notify()
</tt>method, the host application passes a <tt>PMoaChar</tt>, a pointer to a
character array specifying the pathname of the file being read to or written
from (a null-terminated C string). <p>
*/

	STDMETHOD(UnregisterNotificationClient)(THIS_	
		PIMoaDrNotificationClient pNotificationClient,	/* Pointer to
a pre-existing <tt>IMoaDrNotificationClient</tt> interface */
		MoaDrNotifyType notifyType,  /* Value indicating the type of
notification requested */
		PMoaVoid refCon)
		PURE;

/* Category
Managing notification clients
*/

/* Description
Unregisters a notification client previously registered by a call to
<tt>RegisterNotificationClient()</tt>.	The same
<tt>IMoaDrNotificationClient</tt> interface can be used to service multiple
<tt><i>notifyTypes</i></tt>.  When calling
<tt>UnregisterNotificationClient()</tt>, only the notification for the supplied
<tt><i>notifyType </i></tt>is disabled.<p>
*/

};

typedef IMoaDrUtils FAR * PIMoaDrUtils;


/* ----------------------------------------------------------------------------
/
/	IMoaDrStyleAccess2
/
/	Text style-related utility functions
/
/
/				These are equivalent to the Macintosh GetFNum() and
/				GetFontName() calls.
/
/ -------------------------------------------------------------------------- */

/* IID_IMoaDrStyleAccess2 */
DEFINE_GUID(IID_IMoaDrStyleAccess2, 0xD974E0C4L, 0x5D88, 0x11CF, 0xBA, 0x41,
			0x08, 0x00, 0x07, 0x9F, 0x01, 0x6C);

#undef INTERFACE
#define INTERFACE IMoaDrStyleAccess2

DECLARE_INTERFACE_(IMoaDrStyleAccess2, IMoaUnknown)

/* Descripiton
Provides helpers for accessing text edit style data.  This interface is
available on Macintosh and Windows.  On the Macintosh, the functionality is
also available directly through the Macintosh toolbox.
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetFontNumber)(THIS_
		PMoaChar pFontName,  /* Pointer to a C null-terminated C
string containing the name of the font of interest. Case is not significant.*/
		MoaLong FAR * pFontNumber,	/* Pointer to a <tt>MoaLong</tt>
to receive the font number corresponding with <tt>pFontName</tt> */
		PIMoaDrCast   pCast)	/* pointer to the director cast storing the font information
we are accessing */
		;

/* Description
Gets the font identification number associated with a font name string.  This
identification number corresponds to values in the <tt>"scrpFont"</tt> field of
the <tt>ScrpSTElement </tt>sub-structure in <tt>moaTEStyles</tt>.  This method
is equivalent to the Macintosh <tt>GetFNum() </tt>toolbox call.  Currently this
method always returns <tt>kMoaErr_NoErr</tt>.
*/

	STDMETHOD(GetFontName)(THIS_
		MoaLong fontNumber,  /* Number of the font of interest */
		PMoaChar pFontName,  /* Pointer to a buffer to receive a
null-terminated C string for the name of the font */
		MoaLong maxLen,  /* Size of the string buffer at <tt>pFontName</tt> */
		PIMoaDrCast   pCast)	/* pointer to the director cast storing the font information
we are accessing */
		;

/* Description
Gets the font name associated with a font identification number.  This
identification number corresponds to values in the <tt>"scrpFont" </tt>field of
the <tt>ScrpSTElement</tt> sub-structure in <tt>moaTEStyles</tt>. This method
is equivalent to Macintosh <tt>GetFontName()</tt> toolbox call.
*/

};

typedef IMoaDrStyleAccess2 FAR * PIMoaDrStyleAccess2;



/* ----------------------------------------------------------------------------
/
/	IMoaDrStyleAccess
/
/	WARNING: This interface is obsolete!  Using this interface in Director 6.0 and on
/	may have unpredictable results.  Use the IMoaDrStyleAccess2 interface instead.
/
/ -------------------------------------------------------------------------- */

/* IID_IMoaDrStyleAccess */
DEFINE_GUID(IID_IMoaDrStyleAccess, 0xD974E0C4L, 0x5D88, 0x11CF, 0xBA, 0x41,
			0x08, 0x00, 0x07, 0x9F, 0x01, 0x6C);

#undef INTERFACE
#define INTERFACE IMoaDrStyleAccess

DECLARE_INTERFACE_(IMoaDrStyleAccess, IMoaUnknown)

/* Descripiton
Provides helpers for accessing text edit style data.  This interface is
available on Macintosh and Windows.  On the Macintosh, the functionality is
also available directly through the Macintosh toolbox.
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetFontNumber)(THIS_
		PMoaChar pFontName,  /* Pointer to a C null-terminated C
string containing the name of the font of interest. Case is not significant.*/
		MoaLong FAR * pFontNumber)	/* Pointer to a <tt>MoaLong</tt>
to receive the font number corresponding with <tt>pFontName</tt> */
		;

/* Description
Gets the font identification number associated with a font name string.  This
identification number corresponds to values in the <tt>"scrpFont"</tt> field of
the <tt>ScrpSTElement </tt>sub-structure in <tt>moaTEStyles</tt>.  This method
is equivalent to the Macintosh <tt>GetFNum() </tt>toolbox call.  Currently this
method always returns <tt>kMoaErr_NoErr</tt>.
*/

	STDMETHOD(GetFontName)(THIS_
		MoaLong fontNumber,  /* Number of the font of interest */
		PMoaChar pFontName,  /* Pointer to a buffer to receive a
null-terminated C string for the name of the font */
		MoaLong maxLen)  /* Size of the string buffer at <tt>pFontName</tt> */
		;

/* Description
Gets the font name associated with a font identification number.  This
identification number corresponds to values in the <tt>"scrpFont" </tt>field of
the <tt>ScrpSTElement</tt> sub-structure in <tt>moaTEStyles</tt>. This method
is equivalent to Macintosh <tt>GetFontName()</tt> toolbox call.
*/

};

typedef IMoaDrStyleAccess FAR * PIMoaDrStyleAccess;



/* ---------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
/
/	IMoaDrAssetCallback - Director-specific callback interface for asset xtras.
/
/ --------------------------------------------------------------------------- */


/* IID_IMoaDrAssetCallback: ACC33F91013724E70000080007FC20C1 */
DEFINE_GUID(IID_IMoaDrAssetCallback, 0xACC33F91L, 0x0137, 0x24E7, 0x00, 0x00, 0x08, 0x00,
0x07, 0xFC, 0x20, 0xC1);

#undef INTERFACE
#define INTERFACE IMoaDrAssetCallback

DECLARE_INTERFACE_(IMoaDrAssetCallback, IMoaMmPropOwner)

/* Description
<p>
The <tt>IMoaDrAssetCallback</tt> interface is provided in Director by the class
that implements <tt>IMoaMmAssetCallback</tt>, which is provided by through the
asset initialization method <tt>IMoaMmXAsset::SetCallback()</tt>.  To acquire
<tt>IMoaDrAssetCallback</tt>, the asset can call <tt>QueryInterface()</tt> on
<tt>IMoaMmAssetCallback</tt>.  <p>
<p>
This interface provides additional, Director-specific callback services to a
media asset.  In Director, an asset Xtra has both an external representation,
implemented by the Xtra developer, and an internal representation, provided by
Director.  The Xtra developer defines custom behavior by implementing standard
asset Xtra interfaces.	This interface provides controlled access to the
internal representation of the Xtra provided by Director.  <p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetProp)(THIS_
		MoaMmSymbol symbol,  /* <tt>MoaMmSymbol</tt> representing the
property to get */
		PMoaMmValue pPropValue)  /* Pointer to a <tt>MoaMmValue</tt> to
receive the property's value */
		PURE;

/* Category
Property owner
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists and value was
returned
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Property exists but couldn't get due
to internal err
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=235><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for string
value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=235><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=355>Couldn't allocate memory for other
value data
</TD></TR>
</TABLE>
*/

/* Description
<p>
Gets any property of the cast member associated with your asset.  This includes
both built-in ones handled by the host application (such as <tt>name</tt> in
Director for cast member name), as well as your own properties.  If you
retrieve your own properties, it may result in a callback to your own
<tt>GetProp() </tt>method; be careful not to get stuck in a loop.<p>
*/

	STDMETHOD(SetProp)(THIS_
		MoaMmSymbol symbol,  /* MoaMmSymbol representing the property to set */
		ConstPMoaMmValue pPropValue)  /* Pointer to a ConstPMoaMmValue containing
the property value */
		PURE;

/* Category
Property owner
*/

/* Returns
<TABLE BORDER="2">
<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_NoErr</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists and value was set
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_BadParam</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Invalid <TT><I><FONT SIZE=2
FACE="Courier New">pPropValue </FONT></I></TT>passed in
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PropertyNotFound</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property isn't supported by this
class
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_InternalError</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Property exists, value ok, can't
set--internal error
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_NoMemForString</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Can't allocate memory for setting
string value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=253><TT>kMoaErr_OutOfMem</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Can't allocate memory for setting
other value data
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_IntegerExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: integer value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_SymbolExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: symbol value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_FloatExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: float value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_StringExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: string value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_PointExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: point value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_RectExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: rect value
expected
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaMmErr_ValueTypeMismatch</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch: other value
expected (non-specific)
</TD></TR>

<TR><TD ALIGN="LEFT" VALIGN="TOP"
WIDTH=253><TT>kMoaDrErr_CastMemberExpected</TT>
</TD><TD ALIGN="LEFT" VALIGN="TOP" WIDTH=337>Type mismatch:
<TT>CMRef</TT> value expected
</TD></TR>
</TABLE>
*/

/* Description
<p>
Sets any property of the cast member associated with your asset.  This includes
both built-in ones handled by the host application (such as <tt>name</tt> in
Director for cast member name), as well as your own properties.  This may
result in a call back to your own <tt>SetProp() </tt>method; be careful not to
get stuck in a loop. <p>
*/

	STDMETHOD(GetCMRef)(THIS_
		PMoaDrCMRef pCMRef)  /* Pointer to a <tt>MoaDrCMRef</tt> to
receive the reference for the cast member associated with your asset */
		PURE;

/* Category
Internal cast member access
*/

/* Description
Gets the cast member reference for the cast member associated with
your asset. This lets you determine the Director cast member with
your asset is associated. The cast index supplied in this reference is
relative to the active movie.
*/

	STDMETHOD(CallCMHandler)(THIS_
		MoaMmSymbol handlerName,  /* MoaMmSymbol representing the handler to call */
		MoaLong nArgs,	/* Number of arguments, excluding the Xtra instance in
<tt><i>pArgs</i>[0]</tt> */
		PMoaMmValue pArgs,	/* Array of arguments, with the first valid argument at
<tt><i>pArgs</i>[1]</tt> */
		PMoaMmValue pResult,  /* Pointer to a <tt>MoaMmValue</tt>
to receive the result */
		MoaBool FAR * pHandled)  /* Boolean value */
		PURE;

/* Category
Scripting support
*/

/* Description
<p>
Calls a handler defined in the asset's cast member script. For
<tt>CallCMHandler()</tt>, only the cast member script is checked; the message
does not proceed up to the movie or frame level, as it does with the sprite
<tt>SendMessage() </tt>call.<p>
<p>
Caller supplies a symbol for handler to call (<tt><i>name</i></tt>), the
arguments (<tt><i>nArgs</i></tt>, <tt><i>pArgs</i></tt>), and a pointer to a
<tt>MoaMmValue </tt>to receive a result, if any, from the handler call.<p>
<p>
Upon return, <tt><i>pHandled </i></tt>is set to <tt>TRUE </tt>if the call was
handled, that is the handler existed in the cast member script. If message was
not handled, it silently disappears and <tt>FALSE </tt>is returned.<p>
<p>
*/

};

typedef IMoaDrAssetCallback FAR * PIMoaDrAssetCallback;


/* ----------------------------------------------------------------------------
/
/	IMoaDrSpriteCallback - Director-specific callback interface for
/							sprite asset xtras.
/
/ --------------------------------------------------------------------------- */

/* IID_IMoaDrSpriteCallback: ACC33FCA013732510000080007FC20C1 */
DEFINE_GUID(IID_IMoaDrSpriteCallback, 0xACC33FCAL, 0x0137, 0x3251, 0x00,
				0x00, 0x08, 0x00, 0x07, 0xFC, 0x20, 0xC1);

#undef INTERFACE
#define INTERFACE IMoaDrSpriteCallback

DECLARE_INTERFACE_(IMoaDrSpriteCallback, IMoaUnknown)

/* Description
<p>
The <tt>IMoaDrSpriteCallback</tt> interface is provided in Director by the
class that implements <tt>IMoaMmSpriteCallback</tt>, which is provided through
the sprite actor initialization method
<tt>IMoaMmXSpriteActor::SetCallback()</tt>.  To acquire
<tt>IMoaDrSpriteCallback</tt>, the asset can call <tt>QueryInterface()</tt> on
<tt>IMoaMmSpriteCallback</tt>.	<p>
<p>
This interface provides additional, Director-specific callback services to a
media asset.  <p>
*/

{
	STD_IUNKNOWN_METHODS

	STDMETHOD(GetMovie)(THIS_
		PIMoaDrMovie FAR * ppIMoaDrMovie)
		PURE;

/* Category
Acquiring IMoaDrMovie
*/

/* Description
Gets the movie interface for the movie in which the sprite is appearing. You
are responsible for releasing this interface when you're done with it.
*/

	STDMETHOD(GetSpriteChanIndex)(THIS_
		PMoaDrSpriteChanIndex pChanIndex)
		PURE;

/* Category
Sprite access
*/

/* Description
Gets the sprite channel number for the Director sprite associated with this
sprite instance. Channel numbers are 1-based.
*/

	STDMETHOD(SendSpriteMessage)(THIS_
		MoaMmSymbol handlerName,
		MoaLong nArgs,
		PMoaMmValue pArgs,
		PMoaMmValue pResult,
		MoaBool FAR * pHandled)
		PURE;

/* Category
Scripting support
*/

/* Description
<p>
Sends a message along the standard message hierarchy starting with the sprite.
The message proceeds along the path:<p>
<p>
sprite --&gt; cast member --&gt; frame --&gt; movie <p>
<p>
until it is consumed by a script at some level.  (If no such handler exists at
a given level, the message proceeds to the next level.	Alternatively, a Lingo
script can intentionally pass a message to the next level using the
<tt>pass</tt> Lingo command.<p>
<p>
The caller supplies symbol for handler to call (<tt><i>name</i></tt>), the
arguments (<tt><i>nArgs</i></tt>, <tt><i>pArgs</i></tt>), and a pointer to a
<tt>MoaMmValue </tt>to receive a result, if any, from the handler call.<p>
<p>
Upon return, <tt><i>pHandled </i></tt>is set to <tt>TRUE </tt>if the call was
handled.  If the message is not handled, it silently disappears and <tt>FALSE
</tt>is returned.<p>
<p>
This method is ideal for implementing widget-type sprite Xtras.  For example,
if you're implementing a button Xtra, you could send a <tt>buttonClicked</tt>
message whenever the button was clicked.  Developers could then handle this
message by putting an <tt>on buttonClicked</tt> handler in the sprite script
for any object in the hierarchy: sprite, cast member, frame, movie.).  The Xtra
could, of course, emit multiple messages,  which would be needed to implement a
multi-part widget such as a scrollbar.
<p>
*/

};

typedef IMoaDrSpriteCallback FAR * PIMoaDrSpriteCallback;


/* ----------------------------------------------------------------------------
/
/  IMoaDrPaletteAccess
/
/ -------------------------------------------------------------------------- */


/* IID_IMoaDrPlayer: AC401B780000FA7D00000800072C6326 */

DEFINE_GUID(IID_IMoaDrPaletteAccess, 0x7C29A966L, 0x4150, 0x11D0, 0xAD, 0xEF, 0x00,
				0x05, 0x9A, 0x80, 0xE8, 0x2F);
/* Description
<p>
The <tt>IMoaDrPaletteAccess</tt> interface is provided in Director by the
main callback object.  Use this interface to access the media of the built in
palettes supplied by director.
To acquire <tt>IMoaDrPaletteAccess,</tt> call <tt>QueryInterface()</tt> on the main
callback object. <p>
*/

#undef INTERFACE
#define INTERFACE IMoaDrPaletteAccess
DECLARE_INTERFACE_(IMoaDrPaletteAccess,IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	STDMETHOD(GetBuiltInPaletteCount)(THIS_
		MoaUlong FAR * pCount /* returns the number of build in palettes in Director*/
		)
		PURE;
/* Category
Media access
*/

/* Description
<p>
Returns the number of palettes supported internally by Director.
*/
	
	STDMETHOD(GetNthBuiltInPaletteSymbol)(THIS_
		MoaUlong	 nPalette, /* the index of the palette to access. */
		PMoaMmSymbol pPaletteSymbol /* returns the symbol for the palette */
		)
		
		PURE;
/* Category
Media access
*/
/* Description
<p>
Returns the symbol for the nth palette.  You can pass this symbol to
<tt>GetBuildInPaletteMedia</tt> to get the actual palette.
*/
	STDMETHOD(GetBuiltInPaletteMedia)(THIS_
		MoaMmSymbol paletteSymbol, /* the symbol for the palette to access */
		PMoaVoid	FAR * pPaletteMedia /* returns the actual palette media */
		)
		PURE;
/* Category
Media access
*/
/* Description
<p>
returns the palette media for the built in palette referred to by paletteSymbol.
You can call <tt>GetNthBuildInPaletteSymbol</tt> to get this symbol. the palette
returned is either a CTabHandle on the macintosh, or an HPALETTE on windows.
*/
};

typedef IMoaDrPaletteAccess FAR * PIMoaDrPaletteAccess;

/* ---------------------------------------------------------------------------- */



DEFINE_GUID(IID_IMoaDrSound, 0x57A629DEL, 0x43FD, 0x11D0, 0x91, 0x7B,
									0x00, 0x05, 0x9A, 0x80, 0xE8, 0x2F);
#undef INTERFACE
#define INTERFACE IMoaDrSound

DECLARE_INTERFACE_(IMoaDrSound,IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	STDMETHOD(GetSoundChannelCount)(THIS_
		MoaUlong FAR *	pCount)
		PURE;
	STDMETHOD_(MoaDrSoundChannelPlayStatus,GetSoundChannelStatus)(THIS_
		MoaUlong	iChannel)		
		PURE;
	STDMETHOD(GetFreeSoundChannel)(THIS_
		MoaUlong FAR *	piChannel)
	PURE;
	STDMETHOD(PlaySoundFormat)(THIS_
		MoaUlong		iChannel,
		PIMoaStream 	pSoundStream,
		ConstPMoaChar	psSoundFormat,
		PMoaMmValue 	pProxyChannel,
		PIMoaDrMovie	pMovieContext)
	PURE;
	STDMETHOD(PlaySoundRaw)(THIS_
		MoaUlong		iChannel,
		PIMoaStream 	pRawSoundStream,
		PMoaSoundFormat pSndFormat,
		PMoaMmCuePoint	pCuePointList,
		MoaUlong		nCuePoints,
		PMoaMmValue 	pProxyChannel,
		PIMoaDrMovie	pMovieContext)
	PURE;	
	STDMETHOD(StopSoundChannel)(THIS_
		MoaUlong		iChannel,
		MoaUlong*		pTime)
	PURE;
	STDMETHOD(SetSoundChannelVolume)(THIS_
		MoaUlong		iChannel,
		MoaUshort		nVolume)
	PURE;
	STDMETHOD(GetTime)(THIS_
		MoaUlong		iChannel,
		MoaUlong*		pTime)
	PURE;
};

typedef IMoaDrSound FAR * PIMoaDrSound; 


#undef INTERFACE
/* ---------------------------------------------------------------------------- */


DEFINE_GUID(IID_IMoaDrSound2, 0x250cab9e, 0x9bb9, 0x11d3, 0x88, 0x8e,
									0x0, 0x90, 0x27, 0x72, 0x4, 0xfa);
#undef INTERFACE
#define INTERFACE IMoaDrSound2

DECLARE_INTERFACE_(IMoaDrSound2,IMoaDrSound)
{
	STD_IUNKNOWN_METHODS
	STDMETHOD(GetSoundChannelCount)(THIS_
		MoaUlong FAR *	pCount)
		PURE;
	STDMETHOD_(MoaDrSoundChannelPlayStatus,GetSoundChannelStatus)(THIS_
		MoaUlong	iChannel)		
		PURE;
	STDMETHOD(GetFreeSoundChannel)(THIS_
		MoaUlong FAR *	piChannel)
	PURE;
	STDMETHOD(PlaySoundFormat)(THIS_
		MoaUlong		iChannel,
		PIMoaStream 	pSoundStream,
		ConstPMoaChar	psSoundFormat,
		PMoaMmValue 	pProxyChannel,
		PIMoaDrMovie	pMovieContext)
	PURE;
	STDMETHOD(PlaySoundRaw)(THIS_
		MoaUlong		iChannel,
		PIMoaStream 	pRawSoundStream,
		PMoaSoundFormat pSndFormat,
		PMoaMmCuePoint	pCuePointList,
		MoaUlong		nCuePoints,
		PMoaMmValue 	pProxyChannel,
		PIMoaDrMovie	pMovieContext)
	PURE;	
	STDMETHOD(StopSoundChannel)(THIS_
		MoaUlong		iChannel,
		MoaUlong*		pTime)
	PURE;
	STDMETHOD(SetSoundChannelVolume)(THIS_
		MoaUlong		iChannel,
		MoaUshort		nVolume)
	PURE;
	STDMETHOD(GetTime)(THIS_
		MoaUlong		iChannel,
		MoaUlong*		pTime)
	PURE;
	STDMETHOD(PauseSound)(THIS_
		MoaUlong		iChannel,
		MoaBoolParam	bPauseState)
	PURE;
};

typedef IMoaDrSound2 FAR * PIMoaDrSound2;	


#undef INTERFACE
/* ---------------------------------------------------------------------------- */

/* IMoaDrPreferenceAccess */
DEFINE_GUID(IID_IMoaDrPreferenceAccess, 0x4BA52EC4L, 0x64B2, 0x11CF, 0x98, 0x4A, 0x08,
	0x00, 0x07, 0x4F, 0x01, 0x6C);

#define INTERFACE IMoaDrPreferenceAccess

DECLARE_INTERFACE_(IMoaDrPreferenceAccess, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS

	STDMETHOD(SetDataPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			PMoaVoid					pData,
			MoaUlong					size)  PURE;
	STDMETHOD(SetStringPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			PMoaChar					pValue)  PURE;
	STDMETHOD(SetFlagPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			MoaBool 					value)	PURE;
	STDMETHOD(SetLongPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			MoaLong 					value)	PURE;
	STDMETHOD(SetDoublePref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			MoaDouble					value)	PURE;
	STDMETHOD(SetPointPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			MoaPoint					value)	PURE;
	STDMETHOD(SetRectPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			MoaRect 					value)	PURE;

	STDMETHOD(GetDataPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			PMoaVoid					pValue,
			MoaUlong					size)  PURE;
	STDMETHOD(GetStringPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			PMoaChar*					ppValue,
			MoaLong 					bufLen)  PURE;
	STDMETHOD(GetFlagPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			MoaBool*					pValue)  PURE;
	STDMETHOD(GetLongPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			MoaLong*					pValue)  PURE;
	STDMETHOD(GetDoublePref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			PMoaDouble					pValue)  PURE;
	STDMETHOD(GetPointPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			PMoaPoint					pValue)  PURE;
	STDMETHOD(GetRectPref) (THIS_ 
			PMoaChar					prefKey,
			MoaID						prefGUID,
			PMoaRect					pValue)  PURE;

};

typedef IMoaDrPreferenceAccess FAR * PIMoaDrPreferenceAccess;
#undef INTERFACE


/*MOA Error block for IMoaDrPreferences----------0x1490->0x149F  */
#define 	kMoaDrPrefsErr_Base 					0x1490

#define 	kMoaDrPrefsErr_BufferOverrun			MAKE_MOAERR(kMoaMmErr_Base)
#define 	kMoaDrPrefsErr_InvalidKey				MAKE_MOAERR(kMoaMmErr_Base + 1)
#define 	kMoaDrPrefsErr_InvalidPointer			MAKE_MOAERR(kMoaMmErr_Base + 2)
#define 	kMoaDrPrefsErr_InvalidData				MAKE_MOAERR(kMoaMmErr_Base + 3)
#define 	kMoaDrPrefsErr_ClassIDNotValid			MAKE_MOAERR(kMoaMmErr_Base + 4)


/* ---------------------------------------------------------------------------- */

DEFINE_GUID(IID_IMoaDrCursor,
0xb8bca0d1, 0x7388, 0x11d2, 0x91, 0x20, 0x0, 0xa0, 0xc9, 0x2e, 0x3a, 0x0f);
															
#undef INTERFACE
#define INTERFACE IMoaDrCursor

DECLARE_INTERFACE_(IMoaDrCursor, IMoaUnknown)
{
	/* IMoaUnknown methods */
	STD_IUNKNOWN_METHODS

	/* The cursorID can be one of the built in types, above, or
	a resource ID.	The pCursorBitmap is the CMRef of a cast member,
	(either a 1-bit bitmap or a Cursor Xtra Asset) to be used as the sprite 
	cursor.  pCursorMask is an optional 1-bit mask bitmap (only used with 
	a 1-bit bitmap cursor)*/
	/* a spriteNum of 0 indicates setting of the stage cursor*/
	
	STDMETHOD(SetSpriteCursor)	(THIS_
			MoaDrSpriteChanIndex		spriteNum,
			MoaDrCursorID				cursorID,
			PMoaDrCMRef 				pCursorBitmap,
			PMoaDrCMRef 				pCursorMask
			)
			PURE;
			
};
								
typedef IMoaDrCursor FAR * PIMoaDrCursor;

#undef INTERFACE

/* ---------------------------------------------------------------------------- */
/* IMoaDrMovieContext */
DEFINE_GUID(IID_IMoaDrMovieContext,
			0x99cd6df0, 0x49e8, 0x11d2, 0xa6, 0x6d, 0x00, 0xa0, 0xc9, 0xe7, 0x37, 0x36);

#define INTERFACE IMoaDrMovieContext

typedef struct
{
	MoaLong dontUseEver[4];
} DrContextState, FAR * PDrContextState;

DECLARE_INTERFACE_(IMoaDrMovieContext, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS

	STDMETHOD(PushXtraContext) (THIS_
			PDrContextState pDrContextState)  PURE;
	STDMETHOD(PopXtraContext) (THIS_ 
			PDrContextState pDrContextState)  PURE;
	STDMETHOD(ReleaseExclusiveThread) (THIS_
			PDrContextState pDrContextState) PURE;
	STDMETHOD(ReacquireExclusiveThread) (THIS_
			PDrContextState pDrContextState) PURE;
};

typedef IMoaDrMovieContext FAR * PIMoaDrMovieContext;

#undef INTERFACE


#if defined( MACINTOSH ) && defined( __MWERKS__ ) && !defined( powerc )
	#pragma pop
#endif /* MACINTOSH && MWERKS && !powerc */


#ifdef	__cplusplus
}
#endif


#include "drivalue.h"


#endif	/* DRISERVC_H */
