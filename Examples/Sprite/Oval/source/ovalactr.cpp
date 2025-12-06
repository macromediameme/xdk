/*****************************************************************************
 * Copyright © 1994-1999 Macromedia, Inc.  All Rights Reserved
 *
 * You may utilize this source file to create and compile object code for use 
 * within products you create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
 * WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
 * INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
 * PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
 * FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
 * USE OR INABILITY TO USE THIS CODE.
 *
 *	Name: ovalactr.cpp
 *	
 * 	Purpose: Definitions of Actor class interface(s) and methods for the 
 *           Sprite Oval Xtra example.
 *
 ****************************************************************************/ 

/*****************************************************************************
 *  INCLUDE FILE(S)
 *  ---------------
 *	This .cpp file should automatically include all the support files needed for 
 *  this particular class. In addition, this file may include other .h files 
 *  defining additional callback interfaces for use by a third party.   
 *****************************************************************************/ 
#include "ovalactr.h"

#ifdef MACINTOSH
#include <QuickDraw.h>
#endif /* /*  MACINTOSH /* */

#include <String.h>

#include "AwiServc.h"
  
/*****************************************************************************
 *  FILE SPECIFIC DEFINE(S)
 *  -----------------------
 *	Any #define's specific to this file.  
 *****************************************************************************/ 
/* These correspond to the two different visual states of our  
   actor:  an animating oval or a static "X". */
#define kMyActorState_Oval	0
#define kMyActorState_X		1

/* Sprite notification messages */ 
enum
{
	kSprNotifyMsg_SetParentAsset = 1
};

#ifndef UNUSED
#define UNUSED(x) x
#endif

/*****************************************************************************
 *  CLASS INTERFACE(S)
 *  ------------------
 *  The interface(s) implemented by your MOA class are specified here.  Note that
 *  at least one class in your Xtra should implement the IMoaRegister interface.
 *  NOTE: Because C++ does not use a lpVtbl to reference an interface's methods, 
 *  the actual method declaration is done in the .h file.
 *
 *  Syntax:
 *  BEGIN_DEFINE_CLASS_INTERFACE(<class-name>, <interface-name>) 
 *****************************************************************************/ 
BEGIN_DEFINE_CLASS_INTERFACE(COvalSpriteActor, IMoaMmXSpriteActor)
END_DEFINE_CLASS_INTERFACE


/*****************************************************************************
 *  CREATE AND DESTROY METHODS
 *  --------------------------
 *  Every interface and class has an associated 'Create' and 'Destroy' pair.
 *  'Create' methods are typically used to acquire interface(s), allocate 
 *  memory, and intialize variables. 'Destroy' methods are typically used to 
 *  release interfaces and free memory. To create 'empty' create and destroy 
 *  methods for an interface, use the STD_INTERFACE_CREATE_DESTROY macro.
 *****************************************************************************/ 

/* NOTE:  In C++, the local variable 'This' is provided implicitly within 
 * a method implementation.  Thus, there is no need explicitly declare 'This' 
 * as a function parameter. However, this implementation detail doesn’t apply 
 * to the MOA class creator and destructor functions, which are standard C 
 * functions, coded exactly as in like they are in C examples.  
 *
 * Syntax:
 * STDMETHODIMP MoaCreate_<class-name>(<class-name> FAR * This)  
 * STDMETHODIMP MoaDestroy_<class-name>(<class-name> FAR * This)  
 */

/* ----------------------------------------------------- MoaCreate_COvalSpriteActor */
STDMETHODIMP  		MoaCreate_COvalSpriteActor(COvalSpriteActor FAR * This)
{
	
	/* variable declaration */
	MoaError	err = kMoaErr_NoErr;

	This->pXAsset = NULL;
	This->state = kMyActorState_Oval;
	This->stepState = 0;
	This->direction = 1;
	This->pAwSpriteCallback = NULL;
	
	return(err);
}

/* --------------------------------------------------- MoaDestroy_COvalSpriteActor */
STDMETHODIMP_(void) MoaDestroy_COvalSpriteActor(COvalSpriteActor FAR * This)
{
		
	if (This->pXAsset)
		This->pXAsset->Release();
	
	if (This->pAwSpriteCallback)
		This->pAwSpriteCallback->Release();

	return;
}

/* macros that create constructors and destructors for the following interface(s) */

STD_INTERFACE_CREATE_DESTROY(COvalSpriteActor, IMoaMmXSpriteActor)

/*****************************************************************************
 *  METHOD IMPLEMENTATION(S)
 *  ------------------------
 *  This is where the methods to be defined by your MOA class are implemented.
 *  The bulk of the work in implementing Xtras is done here.  NOTE: 'This' is 
 *  implemented implicitly in C++, therefore it isn't used in the argument-list.
 *
 *  Syntax:
 *  STDMETHODIMP <class-name>_<interface-name>::<method-name>(<argument-list>)
 *****************************************************************************/ 

/* ---------------------------------- COvalSpriteActor_IMoaMmXSpriteActor::GetProp */
STDMETHODIMP COvalSpriteActor_IMoaMmXSpriteActor::GetProp(MoaMmSymbol symbol,
	PMoaMmValue pPropValue)
{
	
	MoaError	err;

	/* We have no actor properties we wish export */

	err = kMoaMmErr_PropertyNotFound;
	
	return(err);
}

/* ---------------------------------- COvalSpriteActor_IMoaMmXSpriteActor::SetProp */
STDMETHODIMP COvalSpriteActor_IMoaMmXSpriteActor::SetProp(MoaMmSymbol symbol,
	ConstPMoaMmValue pPropValue)
{
	
	MoaError	err;
	
	/* We have no actor properties we wish export */

	err = kMoaMmErr_PropertyNotFound;

	return(err);
}

/* ----------------------------- COvalSpriteActor_IMoaMmXSpriteActor::CallFunction */
STDMETHODIMP COvalSpriteActor_IMoaMmXSpriteActor::CallFunction(MoaMmSymbol methodName, 
	MoaLong nArgs, ConstPMoaMmValue pArgs, PMoaMmValue pResult)
{
	
	MoaError	err;
	
	/* We have no actor functions we wish export */

	err = kMoaMmErr_FunctionNotFound;
	
	return(err);
}

/* ------------------------------ COvalSpriteActor_IMoaMmXSpriteActor::SetCallback */
STDMETHODIMP COvalSpriteActor_IMoaMmXSpriteActor::SetCallback(PIMoaMmSpriteCallback pSpriteCallback)
{

	PIMoaAwSpriteCallback	pAwSpriteCallback;
	MoaError err;

	err = pSpriteCallback->QueryInterface(&IID_IMoaAwSpriteCallback, (PPMoaVoid)&pAwSpriteCallback); 
	if ((err == kMoaErr_NoErr) && pAwSpriteCallback)
	{
		pAwSpriteCallback->AddRef();
		pObj->pAwSpriteCallback = pAwSpriteCallback;
	}

	return(kMoaErr_NoErr);
}

/* ----------------------------------- COvalSpriteActor_IMoaMmXSpriteActor::Notify */
STDMETHODIMP COvalSpriteActor_IMoaMmXSpriteActor::Notify(MoaLong msgCode, PMoaVoid refCon)
{

	/* This method is intended for communicating between the
	   asset and its xtras.  The developer is free to define
	   message codes for private use.  This may be called
	   directly by an asset, or through the 
	   IMoaMmAssetCallback::NotifyAllSprites() callback. */

	switch (msgCode)
	{
		case kSprNotifyMsg_SetParentAsset:
			pObj->pXAsset = (PIMoaMmXAsset) refCon;
			pObj->pXAsset->AddRef();	
			 
			/* up ref count since we're hanging on to this */
			break;

		default:
			break;
	}	

	return(kMoaErr_NoErr);
}

/* ---------------------------------- COvalSpriteActor_IMoaMmXSpriteActor::GetCaps */
STDMETHODIMP COvalSpriteActor_IMoaMmXSpriteActor::GetCaps(PMoaMmXSpriteCaps pActorCaps)
{

	MoaError	err = kMoaErr_NoErr;
		
	/* We only want mouse, play, span, and step events 
	   Optionally get key/focus and environment events too */
	
	pActorCaps->eventMask = (kMoaMmEventMask_Mouse 
						| kMoaMmEventMask_Play
						| kMoaMmEventMask_Span
						| kMoaMmEventMask_Step
#ifdef HANDLE_KEY_EVENTS
						| kMoaMmEventMask_Key
#endif /* HANDLE_KEY_EVENTS */
#ifdef HANDLE_ENV_EVENTS
						| kMoaMmEventMask_Environment
#endif /* HANDLE_ENV_EVENTS */
	);

	/* We support no special actor capabilities
	   use kMoaMmXSpriteCapsFlags_AutoTabEnabled for autoTab support */
	
	pActorCaps->flags = 	kMoaMmXSpriteCapsFlags_None
						| kMoaMmXSpriteCapsFlags_AutoTabEnabled
	 					;
	
	/* We support either offscreen or direct-to-screen imaging,
	   but we're intended for offscreen imaging (the normal case). */
	
	pActorCaps->requiredImageMode = kMoaMmXSpriteImageMode_Any;
	pActorCaps->preferredImageMode = kMoaMmXSpriteImageMode_Offscreen;
	
	return(err);
}

/* --------------------------- COvalSpriteActor_IMoaMmXSpriteActor::CollectChanges */
STDMETHODIMP COvalSpriteActor_IMoaMmXSpriteActor::CollectChanges(ConstPMoaMmXSpriteInfo pActorInfo,
	PIMoaMmChangeCollector pChangeCollector)
{
	
	MoaError	err = kMoaErr_NoErr;
	
	/* Here we always add our entire rect as the change area, since 
	   we may be animating and we want Director to refresh 
	   the stage with our sprite every frame.  
	
	   If our actor is not changing its appearance in the  
	   coming frame, we would not add any change rects here.  
	
	   (Note: if the sprite is moving or any of its attributes 
	   have changed (such as color), it is always updated in 
	   its entirety automatically, and our CollectChanges() 
	   is not called in this case.) 

	 
	   In the actorInfo, Director has supplied us with what will be our 
	   full sprite rect in the coming frame.  We simply 
	   add this entire rectangle to indicate that the 
	   entire sprite needs updating. */

	pChangeCollector->AddChangeRect(&pActorInfo->spriteRect);

	return(err);
}

/* ---------------------------- COvalSpriteActor_IMoaMmXSpriteActor::ContainsPoint */
STDMETHODIMP COvalSpriteActor_IMoaMmXSpriteActor::ContainsPoint(ConstPMoaMmXSpriteInfo pActorInfo,
	ConstPMoaPoint pTestPoint, MoaBoolParam FAR * pTestResult)
{
	
	MoaError	err = kMoaErr_NoErr;
	
	/* anywhere within our spriteRect is a hit. 
	   If we wanted to support non-rectangular hit-testing, we'd 
	   be less lazy here and perform the test based upon, say, 
	   the current oval size (if our state == kMyActorState_Oval). */
	
	*pTestResult = TRUE;
		
	return(err);
}


/* ------------------------------------ COvalSpriteActor_IMoaMmXSpriteActor::Image */
#define PENSIZE 2
#define MAXSTEP	10

STDMETHODIMP COvalSpriteActor_IMoaMmXSpriteActor::Image(ConstPMoaMmXSpriteInfo 	pActorInfo,
	ConstPMoaMmPlayerStateInfo	pPlayerStateInfo, PIMoaMmGC pGC)
{
	
	/* variable declaration */
	MoaError			err = kMoaErr_NoErr;
	PMoaRect			pImageRect = (PMoaRect) &pActorInfo->spriteRect;
	MoaMmNativeGCInfo	nativeInfo;

	pGC->GetNativeGCInfo(&nativeInfo);

#ifdef MACINTOSH
	{
	GrafPtr				savePort, drawPort;
	PenState			savePen;
	RGBColor			saveColor;
	RGBColor			myColor = {65535, 0, 0};	/*  pure red */

	/* Determine what port to draw into based on the 
	   supplied Graphics Context.  The host app sets up 
	   this context for us. */

	switch (nativeInfo.type)
	{
		case kMoaMmGCType_MacWindow:
			drawPort = (GrafPtr) nativeInfo.data.mac_window.windowPtr;
			break;
		case kMoaMmGCType_MacGWorld:
			drawPort = (GrafPtr) nativeInfo.data.mac_gworld.gworldPtr;
			break;
	
		default:
			  
			/* we don't know about this type of graphics context; bail out. */
			goto done;
	}
			
	GetPort(&savePort);
	SetPort( drawPort );
	
	
	/* We could obey the sprite color supplied in pActorInfo here, 
	   but instead we always draw using myColor. */
	
	GetForeColor(&saveColor);
	RGBForeColor(&myColor);
	GetPenState(&savePen);
	PenNormal();
	PenSize(PENSIZE, PENSIZE);
		
	switch (pObj->state)
	{
		case kMyActorState_X:
		{

			/* Draw an "X" if our state is kMyActorState_X */
			
			MoveTo(pImageRect->left+PENSIZE, pImageRect->top+PENSIZE);
			LineTo(pImageRect->right-PENSIZE, pImageRect->bottom-PENSIZE);
			MoveTo(pImageRect->left+PENSIZE, pImageRect->bottom-PENSIZE);
			LineTo(pImageRect->right-PENSIZE, pImageRect->top+PENSIZE);
			
			break;

		}
		case kMyActorState_Oval:
		{

			/* Draw an oval if our state is kMyActorState_Oval */
		
			MoaLong ovalSize = pObj->stepState;
			Rect ovalRect;
			
			MoaToMacRect(pImageRect, &ovalRect);
			ovalSize = (ovalSize * (pImageRect->right - pImageRect->left)/2) / MAXSTEP;
			InsetRect(&ovalRect, ovalSize, ovalSize);
			
			FrameOval(&ovalRect);
			
			break;

		}
			
		default:
		
			/* Unknown state, don't draw anything */
			break;
	}
	
	/* Restore our drawing state and port. */
	
	RGBForeColor(&saveColor);
	
	SetPenState(&savePen);
	SetPort(savePort);
	}
#endif	/*  MACINTOSH */

#ifdef WINDOWS
	{
	HDC			drawDC;
	HPEN		hPen, hOldPen;
	HBRUSH		hOldBrush;
	int			oldRop;

    /* Determine what DC to draw into based on the 
       supplied Graphics Context.  The host app sets up 
       this context for us. */

    switch (nativeInfo.type)
    {
		case kMoaMmGCType_WinDIBDC:
		case kMoaMmGCType_WinDDBDC:
		case kMoaMmGCType_WinWindow:
			drawDC = (HDC)(MoaLong) nativeInfo.data.win_window.hDC;
			break;

        default:
            /*  we don't know about this type of graphics context; bail out. */
            goto done;
    }
                
    
    /* We could obey the sprite color supplied in pActorInfo here, 
       but instead we always draw using a fixed color. */
    
    hPen = CreatePen(PS_SOLID, PENSIZE, PALETTERGB(255, 0, 0));
	hOldPen = (HPEN)SelectObject(drawDC, hPen);
	hOldBrush = (HBRUSH)SelectObject(drawDC, GetStockObject(NULL_BRUSH));
	
	/* Ensure ROP is set correctly, since this might have been 
	   changed by host application. */
	
	oldRop = SetROP2(drawDC, R2_COPYPEN);
	
    switch (pObj->state)
    {
        case kMyActorState_X:
        {
            /* Draw an "X" if our state is kMyActorState_X */
            
            MoveToEx(drawDC, (short) pImageRect->left+PENSIZE, (short) pImageRect->top+PENSIZE, 0);
            LineTo(drawDC, (short) pImageRect->right-PENSIZE, (short) pImageRect->bottom-PENSIZE);
            MoveToEx(drawDC, (short) pImageRect->left+PENSIZE, (short) pImageRect->bottom-PENSIZE, 0);
            LineTo(drawDC, (short) pImageRect->right-PENSIZE, (short) pImageRect->top+PENSIZE);
            
            break;
        }
        case kMyActorState_Oval:
        {
            /* Draw an oval if our state is kMyActorState_Oval */
        
            MoaLong ovalSize = pObj->stepState;
            RECT ovalRect;
            
            ovalRect.top = (short) pImageRect->top;
            ovalRect.left = (short) pImageRect->left;
            ovalRect.bottom = (short) pImageRect->bottom;
            ovalRect.right  = (short) pImageRect->right;
            
			ovalSize = (ovalSize * (pImageRect->right - pImageRect->left)/2) / MAXSTEP;
            InflateRect(&ovalRect, (short) -ovalSize, (short) -ovalSize);
            
            Ellipse(drawDC, ovalRect.left, ovalRect.top, 
            		 ovalRect.right, ovalRect.bottom);
            
            break;
        }
           
        default:
        
            /* Unknown state, don't draw anything */
            break;
    }
    
    /* Restore our drawing state and port. */
    
    if (oldRop)
    	SetROP2(drawDC, oldRop);
    	
    SelectObject(drawDC, hOldBrush);
    SelectObject(drawDC, hOldPen);
	DeleteObject(hPen);
	}
#endif /*  WINDOWS */
	
done:
	return(err);
}

/* ------------------------------------ COvalSpriteActor_IMoaMmXSpriteActor::Event */
STDMETHODIMP COvalSpriteActor_IMoaMmXSpriteActor::Event(ConstPMoaMmEventInfo pEventInfo,
	ConstPMoaMmPlayerStateInfo	pPlayerStateInfo, MoaBoolParam FAR *	pHandled)
{
	
	MoaError	err = kMoaErr_NoErr;
	
	switch (pEventInfo->type)
	{
		case kMoaMmEvent_Step:
			/* Change our step state (this corresponds to 
			   the size of the oval when state == kMyActorState_Oval) */
			pObj->stepState += pObj->direction;
			if (pObj->stepState < 0 || pObj->stepState > MAXSTEP)
			{
				pObj->direction = - pObj->direction;
				pObj->stepState += pObj->direction;
			}
			*pHandled = kMoaMmSprEvent_Handled;
			break;
		
		case kMoaMmEvent_MouseDown:
		case kMoaMmEvent_MouseDblClick:
			/* Toggle our visual state */
			if (pObj->state == kMyActorState_Oval)
				pObj->state = kMyActorState_X;
			else
				pObj->state = kMyActorState_Oval;
			*pHandled = kMoaMmSprEvent_Handled;

			{
				PIMoaAwEventSender    pEventSender;
				PIMoaMmUtils	pMmUtils; 

				MoaMmValue pEventArgs[3];



				if (err == kMoaErr_NoErr)
				{
					err = pObj->pXAsset->QueryInterface(&IID_IMoaAwEventSender, (PPMoaVoid)&pEventSender);
				}

				if (err == kMoaErr_NoErr)
				{
					err = pObj->pCallback->QueryInterface(&IID_IMoaMmUtils, (PPMoaVoid)&pMmUtils); 
				}

				if (pObj->pAwSpriteCallback && (err == kMoaErr_NoErr))
				{
					MoaMmSymbol eventSym;

					pMmUtils->IntegerToValue(pEventInfo->where.x, &(pEventArgs[0]));
					pMmUtils->IntegerToValue(pEventInfo->where.y, &(pEventArgs[1]));
				  	pMmUtils->IntegerToValue(pEventInfo->when, &(pEventArgs[2]));
					pMmUtils->StringToSymbol("mouseDown", &eventSym);
					pObj->pAwSpriteCallback->SendSpriteEventWithReply(eventSym, 3, pEventArgs,  (PMoaVoid)9876);
				}
			}

			break;

		case kMoaMmEvent_MouseUp:
			/* If you handle MouseUp here, set
				*pHandled = TRUE. */
			*pHandled = kMoaMmSprEvent_Pass;
			break;
			
		case kMoaMmEvent_Idle:
			*pHandled = kMoaMmSprEvent_Pass;
			break;
			
		case kMoaMmEvent_SpanBegin:
			/* A new sprite span has started; init our state variables. */
			pObj->state = kMyActorState_Oval;
			pObj->stepState = 0;
			pObj->direction = 1;
			*pHandled = kMoaMmSprEvent_Handled;
			break;
		
		case kMoaMmEvent_SpanEnd:
			*pHandled = kMoaMmSprEvent_Pass;
			break;

#ifdef HANDLE_KEY_EVENTS
		case kMoaMmEvent_KeyFocusEnter:
			/* We've entered keyboard focus. */
			pObj->state = kMyActorState_X;
			pObj->stepState = 0;
			pObj->direction = 1;
			*pHandled = kMoaMmSprEvent_Handled;
			break;
		
		case kMoaMmEvent_KeyFocusExit:
			/* We're exiting keyboard focus. */
			pObj->state = kMyActorState_Oval;
			pObj->stepState = 0;
			pObj->direction = 1;
			*pHandled = kMoaMmSprEvent_Handled;
			break;

		case kMoaMmEvent_KeyDown:
#ifdef MACINTOSH
			SysBeep(1);
#endif /*  MACINTOSH */
			*pHandled = kMoaMmSprEvent_Handled;
			break;

#endif /*  HANDLE_KEY_EVENTS */

#ifdef HANDLE_ENV_EVENTS
		case kMoaMmEvent_AssetModified:
			*pHandled = kMoaMmSprEvent_Handled;
			break;
#endif /* HANDLE_ENV_EVENTS */

		default:
			*pHandled = kMoaMmSprEvent_Pass;
			break;
			
	}

	return(err);
}

