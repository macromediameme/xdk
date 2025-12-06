#ifndef _H_XStrmHlp
#define _H_XStrmHlp

/* ================================================================================

	XStreamHelp.h    $Revision: 2 $

	Copyright (c) 1994, 1995, 1996, 1997 Macromedia, Inc.  All Rights Reserved
	
	You may utilize this source file to create and compile object code for use
	within products you may create.  THIS CODE IS PROVIDED "AS IS", WITHOUT 
	WARRANTY OF ANY KIND, AND MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES 
	INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY, FITNESS FOR A PARTICULAR 
	PURPOSE AND NONINFRINGEMENT.  IN NO EVENT WILL MACROMEDIA BE LIABLE TO YOU 
	FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR 
	USE OR INABILITY TO USE THIS CODE.
	
	Purpose:
	
	Provides utility functions that make it easier to manage and access files
	in a platform independent manner.
	
	History:

	19jul98	esg	created.

=================================================================================== */

///////////////////////////////////////////////////////////////////////////////////
//
// Description
//
///////////////////////////////////////////////////////////////////////////////////

/*
	This file is used create and access streams.
*/

///////////////////////////////////////////////////////////////////////////////////
//
// Includes
//
///////////////////////////////////////////////////////////////////////////////////

// XStrmHlp.h


#include "MoaStdIf.h"

#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma push
	#pragma pointers_in_D0
#endif 

class MMString;
///////////////////////////////////////////////////////////////////////////////////
//
// Stream helper moved from MuiHelpr.h due to incompatabilities with OLE2 SDK on MAC
//
///////////////////////////////////////////////////////////////////////////////////

// an x/platform stream helper.
class IMoaStreamHelper
{
public:
	IMoaStreamHelper(PIMoaStream pStrm,MoaBool winStream =
#ifdef WINVER
		TRUE
#else
		FALSE
#endif
	);

	virtual ~IMoaStreamHelper();

	MoaError Open(MoaLong accessMode,MoaLong setPositionType)
	{
		return m_pStream->Open(accessMode,setPositionType);
	}
	
	MoaError Close()
	{
		return m_pStream->Close();
	}

	MoaError Read(PMoaVoid pBuf,
					MoaStreamCount numToRead,
					MoaStreamCount FAR * pNumActuallyRead)
	{
		return m_pStream->Read(pBuf,numToRead,pNumActuallyRead);
	}


	MoaError ReadAhead(PMoaVoid pBuf,
						MoaStreamCount numToRead,
						MoaStreamCount FAR * pNumActuallyRead
						)
	{
		return m_pStream->ReadAhead(pBuf,numToRead,pNumActuallyRead);
	}

	MoaError Write(PMoaVoid pBuf,
					MoaStreamCount numToWrite,
					MoaStreamCount FAR * pNumActuallyWritten
					)
	{
		return m_pStream->Write(pBuf,numToWrite,pNumActuallyWritten);
	}

	MoaError GetPosition(
					MoaStreamPosition FAR * pPos
					)
	{
		return m_pStream->GetPosition(pPos);
	}

	MoaError SetPosition(
					MoaStreamPosition pos
					)
	{
		return m_pStream->SetPosition(pos);
	}

	MoaError GetEnd(
					MoaStreamPosition FAR * pPos
					)
	{
		return m_pStream->GetEnd(pPos);
	}

	MoaError Flush()
	{
		return m_pStream->Flush();
	}

	MoaError GetModes(
					MoaLong FAR * pAccessMode,
					MoaLong FAR * pSetPositionType
					)
	{
		return m_pStream->GetModes(pAccessMode,pSetPositionType);
	}

	IMoaStreamHelper& operator<<(MoaLong rhs);
	IMoaStreamHelper& operator<<(MoaShort rhs);
	IMoaStreamHelper& operator<<(MoaUlong rhs);
	IMoaStreamHelper& operator<<(MoaUshort rhs);
	IMoaStreamHelper& operator<<(MoaDouble rhs);
	IMoaStreamHelper& operator<<(MoaChar rhs);
	IMoaStreamHelper& operator<<(MoaBool rhs);
	IMoaStreamHelper& operator<<(PMoaChar rhs);
	IMoaStreamHelper& operator<<(unsigned char* rhs);
	IMoaStreamHelper& operator<<(const MMString& rhs);

	IMoaStreamHelper& operator>>(MoaLong& rhs);
	IMoaStreamHelper& operator>>(MoaShort& rhs);
	IMoaStreamHelper& operator>>(MoaUlong& rhs);
	IMoaStreamHelper& operator>>(MoaUshort& rhs);
	IMoaStreamHelper& operator>>(MoaDouble& rhs);
	IMoaStreamHelper& operator>>(MoaChar& rhs);
	IMoaStreamHelper& operator>>(MoaBool& rhs);
	IMoaStreamHelper& operator>>(PMoaChar rhs);
	IMoaStreamHelper& operator>>(MMString& rhs);
	IMoaStreamHelper& operator>>(unsigned char* rhs);

	static MoaLong XLong(MoaLong rhs);
	static MoaShort XShort(MoaShort rhs);

protected:
	PIMoaStream m_pStream;
	MoaBool		m_swap;
};
typedef IMoaStreamHelper FAR * PIMoaStreamHelper;


#if defined(__MWERKS__) && defined(__MC68K__)
	#pragma pop
#endif 




#endif // _H_XStrmHlp

// EOF

