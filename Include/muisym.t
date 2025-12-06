
#ifndef _T_MuiSym
#define _T_MuiSym

/* ================================================================================

	MuiSym.T    $Revision: 3 $

	Copyright (c) 1994, 1995, 1996, 2000 Macromedia, Inc.  All Rights Reserved
	
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
	MuiSym manipulation can be used to do quick runtime conversion of muiSymbols
	(which are constant) to lingo symbols, which vary with each execution, and are
	based on non-unique strings. MuiSym.T documents many MuiSyms which are used
	with the c and lingo interfaces for MuiDialog.
	
	History:

	03jan00	alx	Added Editable popups
	09sep97	LLB	Added kControlClassID.
	01apr97	LLB	Include windows.h before any MOA files
	24mar97	jcw	Added kMuiLayout_Minimize.
	08mar97	jcw	new header file format, documentation for external consumption.
				Added kMuiLingoEvent_ItemEnteringFocus, kMuiLingoEvent_ItemLosingFocus
	19Feb97 jcw	Added kMuiLingoPropAlert, kMuiLingoPropDialogUnit
	18Feb97 jcw	Added kMuiLingoWidgetButton_CancelPushButton. Cleaned up table.
	30jan97 alx	Symbol strings moved to MuiSym.cpp
	29jan97 alx	Renamed Moa to Mm + includes
	28jan97	jcw	Added kMuiLayoutStyle and all the layout style symbols.
	15jan97 jcw	Added symbols for alert lingo interface button layouts.
	10jan97 alx	Added symbols for bitmap items
	20dec96 alx	Added static storage class for Symbol Table
	12dec96 jcw	Moved declares and defines out of converter header.
	10dec96 LLB	Use min and max rather than their longer spellings
	10dec96 jcw added lingo consts
	08dec96 alx Renumber items and add back spaces for duplicates
	04dec96 alx Change kMuiPropPopupList -> kMuiPropValueList, 
				add kMuiPropValueRange and related symbols
	27Nov96 alx Created.

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

#ifndef _H_mmtypes
#include "mmtypes.h"
#endif

///////////////////////////////////////////////////////////////////////////////////
//
// Declares
//
///////////////////////////////////////////////////////////////////////////////////

typedef MoaLong TMuiSymbol;

typedef struct
{
	TMuiSymbol 	enumeration;
	char*		string;
} MmSymbolTableEntry;

typedef MmSymbolTableEntry FAR * PMmSymbolTableEntry;
typedef const PMmSymbolTableEntry ConstPMmSymbolTableEntry;

///////////////////////////////////////////////////////////////////////////////////
//
// Defines
//
///////////////////////////////////////////////////////////////////////////////////

const TMuiSymbol kMuiBadSymbol = -1L;


///////////////////////////////////////////////////////////////////////////////////
//
// Our Symbol table
//
///////////////////////////////////////////////////////////////////////////////////

enum
{
	// Property symbols
	kMuiPropTextSize = 0,						// 0
	kMuiPropTextStyle,
	kMuiPropTextAlignment,
	kMuiPropValueRange, 
	kMuiPropValueList,

	kMuiPropPopupStyle,							// 5
	kMuiPropSliderStyle,
	kMuiPropEditStyle,

	// Text Size symbols
	kMuiTextSizeNormal,
	kMuiTextSizeTiny,
	kMuiTextSizeLarge,							// 10

	// Text Styles
	kMuiTextStyleNormal 	= kMuiTextSizeNormal,	// - if a symbol matches another you
	kMuiTextStyleBold 		= 12,					// need to match that enum and restart
	kMuiTextStyleItalic,							// the enumeration + 1
	kMuiTextStyleUnderline,

	// Alignment
	kMuiTextAlignLeft,							// 15
	kMuiTextAlignRight,
	kMuiTextAlignCenter,
	kMuiTextAlignDefault,

	// Popup Styles
	kMuiPopupStyleNormal 	= kMuiTextSizeNormal,
	kMuiPopupStyleTiny 		= kMuiTextSizeTiny,		// 20
	kMuiPopupStyleCramped	= 21,

	// Slider Styles
	kMuiSliderStyleTicks,
	kMuiSliderStyleValue,
	kMuiSliderStyleBoth,

	// Edit text specific symbols
	kMuiEditStyleVScrollbar,					// 25
	kMuiEditStyleHScrollbar,
	kMuiEditStyleBoth		= kMuiSliderStyleBoth,

	// Range specific symbols
	kMuiRangeMinimum 		= 28,
	kMuiRangeMaximum,
	kMuiRangeIncrement,							// 30
	kMuiRangeJump,
	kMuiRangeAcceleration,

	// lingo window ops
	kMuiLingoWindowOpHide,
	kMuiLingoWindowOpShow,
	kMuiLingoWindowOpCenter,					// 35
	kMuiLingoWindowOpZoom,
	kMuiLingoWindowOpTipsOn,
	kMuiLingoWindowOpTipsOff,

	// lingo props
	kMuiLingoPropHeight,
	kMuiLingoPropWidth,							// 40
	kMuiLingoPropData,
	kMuiLingoPropPixel,
	kMuiLingoPropDialogUnit,
	kMuiLingoPropNormal	= kMuiTextSizeNormal,
	kMuiLingoPropPalette = 45,					// 45
	kMuiLingoPropAlert,		
	kMuiLingoPropDefaultWidget,					

	// lingo props for window init list
	kMuiLingoPropType,
	kMuiLingoPropName,
	kMuiLingoPropCallback,						// 50
	kMuiLingoPropMode,
	kMuiLingoPropXPosition,						
	kMuiLingoPropYPosition,
	kMuiLingoPropModal,
	kMuiLingoPropToolTips,						// 55
	kMuiLingoPropCloseBox,
	kMuiLingoPropCanZoom,

	// lingo  props for item prop list
	kMuiLingoPropItemValue	= kMuiSliderStyleValue,
	kMuiLingoPropWidget	= 59,
	kMuiLingoPropAttributes,					// 60
	kMuiLingoPropTitle,
	kMuiLingoPropTip,
	kMuiLingoPropLocH,
	kMuiLingoPropLocV,
	kMuiLingoPropEnabled,						// 65

	// lingo for names of the big lingo lists
	kMui_Lingo_WindowPropList,
	kMui_Lingo_WindowItemList,

	// lingo widget props
	kMuiLingoWidgetUNSUPPORTED,

	// lingo props for widget types, note, none can be out of this range
	kMuiLingoWidgetNone,

	kMuiLingoWidgetVoid_VDivider,				// 70
	kMuiLingoWidgetVoid_VDividerExpander,
	kMuiLingoWidgetVoid_HDivider,
	kMuiLingoWidgetVoid_HDividerExpander,

	kMuiLingoWidget_Bitmap,

	kMuiLingoWidgetBoolean_Checkbox,			// 75
	kMuiLingoWidgetBoolean_RadioButton,

	kMuiLingoWidgetEnum_TriStateCheckbox,
	kMuiLingoWidgetEnum_TriStateRadioButton,

	kMuiLingoWidgetEnum_PopupList,
	kMuiLingoWidgetEnum_EditablePopupList,		// 80
	kMuiLingoWidgetEnum_PopupMenu,		
	kMuiLingoWidgetEnum_ListBox,

	kMuiLingoWidgetChar_EditText,
	kMuiLingoWidgetChar_EditTextVScroll,
	kMuiLingoWidgetChar_EditTextHScroll,		// 85
	kMuiLingoWidgetChar_EditTextVHScroll,

	kMuiLingoWidgetGroup_WindowBegin,
	kMuiLingoWidgetGroup_WindowEnd,
	kMuiLingoWidgetGroup_HBegin,
	kMuiLingoWidgetGroup_HEnd,					// 90
	kMuiLingoWidgetGroup_VBegin,
	kMuiLingoWidgetGroup_VEnd,
	kMuiLingoWidgetGroup_TabBegin,
	kMuiLingoWidgetGroup_TabEnd,
	kMuiLingoWidgetGroup_HScrollbarBegin,		// 95
	kMuiLingoWidgetGroup_HScrollbarEnd,
	kMuiLingoWidgetGroup_VScrollbarBegin,
	kMuiLingoWidgetGroup_VScrollbarEnd,

	kMuiLingoWidgetLabel_Normal,

	kMuiLingoWidgetDragWell_Blank,				// 100
	kMuiLingoWidgetDragWell_Text,
	kMuiLingoWidgetDragWell_Graphic,
	kMuiLingoWidgetDragWell_Color,

	kMuiLingoWidgetLong_HSlider,
	kMuiLingoWidgetLong_VSlider,				// 105
	kMuiLingoWidgetLong_Dial,

	kMuiLingoWidgetFloat_HSlider,
	kMuiLingoWidgetFloat_VSlider,
	kMuiLingoWidgetFloat_Dial,

	kMuiLingoWidgetPoint2d_Picker,				// 110
	kMuiLingoWidgetPoint2d_Vector,
	kMuiLingoWidgetPoint3d_Picker,
	kMuiLingoWidgetPoint3d_Vector,

	kMuiLingoWidgetRect_Sizer,

	kMuiLingoWidgetButton_DefaultPushButton,	// 115
	kMuiLingoWidgetButton_CancelPushButton,
	kMuiLingoWidgetButton_PushButton,
	kMuiLingoWidgetButton_Toggle,
	kMuiLingoWidgetButton_EllipseButton,
	kMuiLingoWidgetButton_Push_Up,				// 120
	kMuiLingoWidgetButton_Push_Down,

	kMuiLingoWidgetButton_NavUp,
	kMuiLingoWidgetButton_NavDown,
	kMuiLingoWidgetButton_NavLeft,
	kMuiLingoWidgetButton_NavRight,				// 125
	kMuiLingoWidgetButton_NavInfo,
	kMuiLingoWidgetButton_NavScript,
	kMuiLingoWidgetButton_NavPlus,
	kMuiLingoWidgetButton_NavPlusPopMenu,
	kMuiLingoWidgetButton_NavMinus,				// 130
	kMuiLingoWidgetButton_NavMinusPopMenu,
	kMuiLingoWidgetButton_NavTrash,

	kMuiLingoWidgetRGB_ColorPicker,
	kMuiLingoWidgetIndex_ColorPicker,

	kMuiLingoWidgetLastWidgetType,				// 135

	// bitmap icons
	kMuiPropBitmapIcon,
	kMuiBitmapIcon_Stop,
	kMuiBitmapIcon_Note,
	kMuiBitmapIcon_Caution,
	kMuiBitmapIcon_Question,					// 140
	kMuiBitmapIcon_Error,

	// lingo alert button styles
	kMuiAlertLingoButtons_Ok,
	kMuiAlertLingoButtons_OkCancel,
	kMuiAlertLingoButtons_AbortRetryIgnore,
	kMuiAlertLingoButtons_YesNoCancel,			// 145
	kMuiAlertLingoButtons_YesNo,	
	kMuiAlertLingoButtons_RetryCancel,	

	// lingo alert init properties
	kMuiAlertLingoButtons,
	kMuiAlertLingoDefault = kMuiTextAlignDefault,
	kMuiAlertLingoTitle	= kMuiLingoPropTitle,	// 150
	kMuiAlertLingoMessage = 151,
	kMuiAlertLingoIcon,
	kMuiAlertLingoMovable,						

	// lingo callback flags
	kMuiLingoEvent_itemChanged,
	kMuiLingoEvent_itemClicked,					// 155
	kMuiLingoEvent_windowOpening,
	kMuiLingoEvent_windowClosed,
	kMuiLingoEvent_windowZoomed,				
	kMuiLingoEvent_windowResized,
	kMuiLingoEvent_ItemEnteringFocus,			// 160
	kMuiLingoEvent_ItemLosingFocus,

	kMuiLingoWidget_Actor,						

	// layout styles
	kMuiLayoutStyle,
	kMuiLayout_LockPosition,
	kMuiLayout_LockSize,						// 165
	kMuiLayout_CenterH,
	kMuiLayout_Left = kMuiTextAlignLeft,		
	kMuiLayout_Right = kMuiTextAlignRight,
	kMuiLayout_CenterV = 169,
	kMuiLayout_Top,								// 170				
	kMuiLayout_Bottom,
	kMuiLayout_Minimize,
	kMuiLayout_MaxSize,


	// classID
	kMuiControlClassID,
	
	kMuiControlPopupEnabledState,

	// Insert new Items HERE

	kMuiSymItemCount							// MUST be last item in list.
};

#endif	// _T_MuiSym

// EOF