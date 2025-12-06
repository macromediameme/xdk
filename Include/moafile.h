/*
	$Workfile: moafile.h $
	$Archive: /Xtras/Include/moafile.h $
	$Author: Greggy $
	$Date: 6/23/99 11:55 AM $
	$Revision: 2 $

	Copyright (c) 1994, 1995, 1996, 1997 Macromedia, Inc.	All Rights Reserved

	You may utilize this source file to create and compile object code for use within products
	you may create.	THIS CODE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, AND
	MACROMEDIA DISCLAIMS ALL IMPLIED WARRANTIES INCLUDING, BUT NOT LIMITED TO, MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.	IN NO EVENT WILL MACROMEDIA BE
	LIABLE TO YOU FOR ANY CONSEQUENTIAL, INDIRECT OR INCIDENTAL DAMAGES ARISING OUT OF YOUR
	USE OR INABILITY TO USE THIS CODE.

	Abstract:
	

  	Revision history:
	951018	Original. (srj)
*/

#ifndef _H_moafile
#define _H_moafile

#ifndef _H_moastdif
	#include "moastdif.h"
#endif

#if defined(__MWERKS__) && defined(__MC68K__)
#pragma push
#pragma pointers_in_D0
#endif

#ifdef MACINTOSH
	#define FILE_SPEC_LEN(pspec) ((pspec) ? (sizeof(short) + sizeof(long) + ((FSSpec*)(pspec))->name[0] + 1) : 0)
	typedef FSSpec MoaSystemFileSpec[1];
#else
	#define FILE_SPEC_LEN(pspec) ((pspec) ? (strlen((ConstPMoaChar)(pspec)) + 1) : 0)
	typedef MoaChar MoaSystemFileSpec[MOA_MAX_PATHNAME];
#endif

/* ----------------- */

#ifndef MOA_STD_METHOD_PROCPTR
	#define MOA_STD_METHOD_PROCPTR(a, b) STDPROCPTR(STDMETHODCALLTYPE, a, b)
#endif
typedef MOA_STD_METHOD_PROCPTR(MoaError, MoaFileEachProc)(
	ConstPMoaSystemFileSpec pSpec, 
	ConstPMoaChar pFileName,
	MoaBoolParam isDirectory, 
	MoaWide lastModDate,
	MoaUlong fileType,
	PMoaVoid refCon
);

/* values returned by GetAccess() */
enum {
	kMoaFileAccessPerm_Read = 1,
	kMoaFileAccessPerm_Write = 2
};

#define kMoaFileErr_IoError			MAKE_MOAERR(0x0384)
#define kMoaFileErr_BufferTooSmall	MAKE_MOAERR(0x0385)
#define kMoaFileErr_DuplicateSpec	MAKE_MOAERR(0x0386)
#define kMoaFileErr_DiskFull		MAKE_MOAERR(0x0387)
#define kMoaFileErr_FileBusy		MAKE_MOAERR(0x0388)
#define kMoaFileErr_BadFileSpec		MAKE_MOAERR(0x0389)

#undef INTERFACE
#define INTERFACE IMoaFile
DECLARE_INTERFACE_(IMoaFile, IMoaUnknown)
{
	STD_IUNKNOWN_METHODS
	STDMETHOD(SetSpec) (THIS_ struct IMoaFile FAR * pDir, ConstPMoaChar pFileName) PURE;
	STDMETHOD(SetNewTempSpec) (THIS_ struct IMoaFile FAR * pDir) PURE;
	STDMETHOD(GetSysSpec) (THIS_ PMoaSystemFileSpec pSpec, MoaLong specBufSize) PURE;
	STDMETHOD(SetSysSpec) (THIS_ ConstPMoaSystemFileSpec pSpec, MoaBoolParam resolveAlias) PURE;
	STDMETHOD(GetPathnameSpec) (THIS_ PMoaChar pNameBuf, MoaLong nameBufSize) PURE;
	STDMETHOD(SetPathnameSpec) (THIS_ ConstPMoaChar pNameBuf, MoaBoolParam resolveAlias) PURE;
	STDMETHOD(CreateFile) (THIS) PURE;
	STDMETHOD(CreateDirectory) (THIS) PURE;
	STDMETHOD(Delete) (THIS) PURE;
	STDMETHOD(SwapFile) (THIS_ struct IMoaFile FAR * pOther) PURE;
	STDMETHOD(GetFilename) (THIS_ PMoaChar pNameBuf, MoaLong nameBufSize) PURE;
	STDMETHOD(SetFilename) (THIS_ ConstPMoaChar pNameBuf) PURE;
	STDMETHOD(GetSize) (THIS_ MoaLong FAR * pFileLen) PURE;
	STDMETHOD(SetSize) (THIS_ MoaLong fileLen) PURE;
	STDMETHOD(GetAccess) (THIS_ MoaLong FAR * pAccessPerm) PURE;
	STDMETHOD(GetDates) (THIS_ MoaWide FAR * pCreate, MoaWide FAR * pModify) PURE;
	STDMETHOD(GetDirectory) (THIS_ struct IMoaFile FAR * FAR * pDir) PURE;
	STDMETHOD(IsDirectory) (THIS) PURE;
	STDMETHOD(IsExisting) (THIS) PURE;
	STDMETHOD(IsSameFile) (THIS_ struct IMoaFile FAR * pOther) PURE;
	STDMETHOD(EachFile) (THIS_ MoaBoolParam resolveAlias, MoaFileEachProc proc, PMoaVoid refCon) PURE;
	STDMETHOD(GetStream) (THIS_ MoaLong bufferSize, PIMoaStream FAR * ppStream) PURE;
	STDMETHOD(Rename) (THIS_ ConstPMoaChar pNameBuf) PURE;
	STDMETHOD(Clone) (THIS_ struct IMoaFile FAR * FAR * ppFile) PURE;
};
typedef IMoaFile FAR * PIMoaFile;

DEFINE_GUID(IID_IMoaFile, 0xAC6B6FA2L, 0x000E, 0x3DD0, 0x00, 0x00, 0x08, 0x00, 0x07, 0x16, 0x0D, 0xC3);
DEFINE_GUID(CLSID_CMoaFile, 0xAC721BD9L, 0x0015, 0x3F3E, 0x00, 0x00, 0x08, 0x00, 0x07, 0x16, 0x0D, 0xC3);

#if defined(__MWERKS__) && defined(__MC68K__)
#pragma pop
#endif

#endif
