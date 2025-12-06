
#ifndef _H_MuiProp
#define _H_MuiProp

/* ================================================================================

	MuiProp.h    $Revision: 3 $

	Copyright (c) 1994, 1995, 1996, 1997, 2000 Macromedia, Inc.  All Rights Reserved
	
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
	RangHelp is specifically designed to help manipulate the range property list
	of the attributes for a MuiDialog item with a range attribute, such as a 
	slider.
	
	History:

	03jan00	alx	Added Editable popups
	09mar98	LLB	Added few variants to set methods in LingoPropList helpers.
	09sep97	LLB	Added Get/SetClassID.
	18mar97	alx	Renamed and stuff added from PropHelp.h
	08mar97	jcw	new header file format, documentation for external consumption.
	30jan97	alx	Moved from PropHelp.h

=================================================================================== */

///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////


#ifndef _H_XMmPList
#include "XMmPList.h"
#endif

///////////////////////////////////////////////////////////////////////////////////
//
// MuiPropListHelper Class Declares
//
///////////////////////////////////////////////////////////////////////////////////

class MuiPropListHelper : public MmPropListHelper
{
// --------------------------------------------------------------------------------
// Construction and Destruction
// --------------------------------------------------------------------------------
	public:
		MuiPropListHelper( MoaMmValue& list, MoaBool release = FALSE ) : 
			MmPropListHelper( list, release )
		{
		}

// --------------------------------------------------------------------------------
// Methods
// --------------------------------------------------------------------------------
	
		TMuiSymbol 	GetTextSize( void );
		MoaError 	SetTextSize( TMuiSymbol style );

		TMuiSymbol 	GetAlignment( void );
		MoaError 	SetAlignment( TMuiSymbol style );

		TMuiSymbol 	GetPopupStyle( void );
		MoaError 	SetPopupStyle( TMuiSymbol style );
		
		TMuiSymbol 	GetEditStyle( void );		
		MoaError 	SetEditStyle( TMuiSymbol style );

		MoaError	GetList( MoaMmValue& theValue );
		MoaError 	SetList( MoaMmValue& list );
		
		MoaError 	GetRange( MoaMmValue& theValue );		
		MoaError 	SetRange( MoaMmValue& list );

		TMuiSymbol 	GetBitmapIcon( void );
		MoaError 	SetBitmapIcon( TMuiSymbol style );

		MoaError 	GetLayoutStyle( MoaMmValue& theValue );		
		MoaError 	SetLayoutStyle( MoaMmValue& list );

		MoaError 	GetSliderStyle( MoaMmValue& style );						
		MoaError 	SetSliderStyle( MoaMmValue& style );
		
		MoaError	GetTextStyle( MoaMmValue& style );
		MoaError 	SetTextStyle( MoaMmValue& style );
		
		MoaError 	GetClassID( MoaMmValue& clsID );		
		MoaError 	SetClassID( MoaMmValue& clsID );

		MoaError 	GetPopupEnabled( MoaMmValue& popupEnabledState );		
		MoaError 	SetPopupEnabled( MoaMmValue& popupEnabledState );
};


///////////////////////////////////////////////////////////////////////////////////
//
// MuiLingoWindowPropListHelper Class Declares / Implementation
//
///////////////////////////////////////////////////////////////////////////////////

class MuiLingoWindowPropListHelper : public MmPropListHelper
{
// --------------------------------------------------------------------------------
// Construction and Destruction
// --------------------------------------------------------------------------------
	public:
		MuiLingoWindowPropListHelper( MoaMmValue& list, MoaBoolParam release = FALSE ) : 
			MmPropListHelper( list, release )
		{
		}
		
		// **** WINDOW TYPE
		TMuiSymbol	GetType( void );
		MoaError 	SetType( TMuiSymbol type );
		MoaError 	SetTypeByWindowType( TMuiWindowType type );

		// **** WINDOW NAME
		MoaError	GetName( MoaMmValue& theValue );		
		MoaError 	SetName( MoaMmValue& name );
		MoaError 	SetName( ConstPMoaChar pName );

		// **** WINDOW CALLBACK
		MoaError	GetCallback( MoaMmValue& theValue );
		MoaError 	SetCallback( MoaMmValue& callback );
					
		// **** WINDOW LAYOUT MODE
		TMuiSymbol	GetMode( void );
		MoaError 	SetMode( TMuiSymbol mode );
		MoaError 	SetModeByLayoutType( TMuiLayoutType mode );
					
		// **** WINDOW XPOSITION
		MoaError 	GetXPosition( MoaLong& value );
		MoaError 	SetXPosition( const MoaLong& value );
		
		// **** WINDOW YPOSITION
		MoaError	GetYPosition( MoaLong& value );
		MoaError	SetYPosition( const MoaLong& value );

		// **** WINDOW WIDTH
		MoaError	GetWidth( MoaLong& value );
		MoaError 	SetWidth( const MoaLong& value );

		// **** WINDOW HEIGHT
		MoaError 	GetHeight( MoaLong& value );
		MoaError	SetHeight( const MoaLong& value );

		// **** WINDOW MODALITY
		MoaError	GetModality( MoaLong& value );
		MoaError 	SetModality( const MoaLong& value );

		// **** WINDOW TOOLTIPS
		MoaError 	GetTooltips( MoaLong& value );
		MoaError	SetTooltips( const MoaLong& value );

		// **** WINDOW CLOSEBOX
		MoaError 	GetCloseBox( MoaLong& value );
		MoaError 	SetCloseBox( const MoaLong& value );

		// **** WINDOW CANZOOM
		MoaError	GetCanZoom( MoaLong& value );
		MoaError	SetCanZoom( const MoaLong& value );
};



///////////////////////////////////////////////////////////////////////////////////
//
// MuiLingoItemPropListHelper Class Declares
//
///////////////////////////////////////////////////////////////////////////////////

class MuiLingoItemPropListHelper : public MmPropListHelper
{
// --------------------------------------------------------------------------------
// Construction and Destruction
// --------------------------------------------------------------------------------
	public:
		MuiLingoItemPropListHelper( MoaMmValue& list, MoaBoolParam release = FALSE ) : 
			MmPropListHelper( list, release )
		{}
				
		// **** ITEM VALUE
		MoaError	GetValue( MoaMmValue& theValue );
		MoaError 	SetValue( const MoaMmValue& name );

		// **** ITEM WIDGET
		TMuiSymbol	GetWidget( void );
		MoaError 	SetWidget( TMuiSymbol type );
		MoaError 	SetWidgetByWidgetType( TMuiWidgetType type );

		// **** ITEM ATTRIBUTES
		MoaError	GetAttributes( MoaMmValue& theValue );
		MoaError 	SetAttributes( const MoaMmValue& name );

		// **** ITEM TITLE
		MoaError	GetTitle( MoaMmValue& theValue );
		MoaError 	SetTitle( const MoaMmValue& vTitle );
		MoaError 	SetTitle( ConstPMoaChar pTitle );

		// **** ITEM TIP
		MoaError	GetTip( MoaMmValue& theValue );
		MoaError 	SetTip( const MoaMmValue& vToolTip );
		MoaError 	SetTip( ConstPMoaChar pToolTip );

		// **** ITEM LOCH
		MoaError 	GetLocH( MoaLong& value );
		MoaError 	SetLocH( const MoaLong& value );
		
		// **** ITEM LOCV
		MoaError 	GetLocV( MoaLong& value );
		MoaError 	SetLocV( const MoaLong& value );

		// **** ITEM WIDTH
		MoaError 	GetWidth( MoaLong& value );
		MoaError 	SetWidth( const MoaLong& value );
		
		// **** ITEM HEIGHT
		MoaError 	GetHeight( MoaLong& value );
		MoaError 	SetHeight( const MoaLong& value );

		// **** ITEM ENABLED
		MoaError 	GetEnabled( MoaLong& value );
		MoaError 	SetEnabled( const MoaLong& value );
};


///////////////////////////////////////////////////////////////////////////////////
//
// MuiLingoAlertPropListHelper Class Declares
//
///////////////////////////////////////////////////////////////////////////////////

class MuiLingoAlertPropListHelper : public MmPropListHelper
{
// --------------------------------------------------------------------------------
// Construction and Destruction
// --------------------------------------------------------------------------------
	public:
		MuiLingoAlertPropListHelper( MoaMmValue& list, MoaBoolParam release = FALSE ) : 
			MmPropListHelper( list, release )
		{}
				
		// **** #buttons
		TMuiSymbol	GetButtons( void );
		MoaError 	SetButtons( TMuiSymbol buttons );

		// **** #default
		MoaError	GetDefault( MoaLong& value );
		MoaError 	SetDefault( const MoaLong& value );

		// **** #title
		MoaError	GetTitle( MoaMmValue& theValue );
		MoaError 	SetTitle( MoaMmValue& title );

		// **** #message
		MoaError	GetMessage( MoaMmValue& theValue );
		MoaError 	SetMessage( MoaMmValue& message );

		// **** #icon
		TMuiSymbol	GetIcon( void );
		MoaError 	SetIcon( TMuiSymbol icon );
	
		// **** #movable
		MoaError	GetMovable( MoaLong& movable );
		MoaError 	SetMovable( const MoaLong& movable );

};


///////////////////////////////////////////////////////////////////////////////////
//
// MuiRangeHelper Class Declares
//
///////////////////////////////////////////////////////////////////////////////////

class MuiRangeHelper : public MmPropListHelper
{
// --------------------------------------------------------------------------------
// Construction and Destruction
// --------------------------------------------------------------------------------
	public:
		MuiRangeHelper( MoaMmValue& list, MoaBoolParam release = FALSE ) : 
			MmPropListHelper( list, release )
		{}

// --------------------------------------------------------------------------------
// Methods
// --------------------------------------------------------------------------------

		MoaError 	GetMinimum( MoaLong& value );
		MoaError 	SetMinimum( const MoaLong& value );
	
		MoaError 	GetMinimum( MoaDouble& value );
		MoaError 	SetMinimum( const MoaDouble& value );


		MoaError 	GetMaximum( MoaLong& value );
		MoaError 	SetMaximum( const MoaLong& value );
	
		MoaError 	GetMaximum( MoaDouble& value );
		MoaError 	SetMaximum( const MoaDouble& value );

		MoaError 	GetIncrement( MoaLong& value );
		MoaError 	SetIncrement( const MoaLong& value );

		MoaError 	GetIncrement( MoaDouble& value );
		MoaError 	SetIncrement( const MoaDouble& value );

		MoaError 	GetJump( MoaLong& value );
		MoaError 	SetJump( const MoaLong& value );

		MoaError 	GetJump( MoaDouble& value );
		MoaError 	SetJump( const MoaDouble& value );

		MoaError 	GetAcceleration( MoaLong& value );
		MoaError 	SetAcceleration( const MoaLong& value );

		MoaError 	GetAcceleration( MoaDouble& value );
		MoaError 	SetAcceleration( const MoaDouble& value );
};

#endif	// _H_MuiProp

// EOF
