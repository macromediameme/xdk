# Microsoft Developer Studio Project File - Name="Transition" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Transition - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TALLWIDE.MAK".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TALLWIDE.MAK" CFG="Transition - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Transition - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Transition - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Transition - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".\Release"
# PROP BASE Intermediate_Dir ".\Release"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".\Release"
# PROP Intermediate_Dir ".\Release"
# PROP Ignore_Export_Lib 0
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /Gz /MT /W3 /GX /O2 /I "..\..\..\..\Include" /I "..\source" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /pdb:none /machine:I386 /out:".\Release\tallwide.x32"
# SUBTRACT LINK32 /map

!ELSEIF  "$(CFG)" == "Transition - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".\Debug"
# PROP BASE Intermediate_Dir ".\Debug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".\Debug"
# PROP Intermediate_Dir ".\Debug"
# ADD BASE CPP /nologo /MT /W3 /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /YX /c
# ADD CPP /nologo /Gz /MTd /W3 /Gm /GX /ZI /Od /I "..\..\..\..\Include" /I "..\source" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /pdb:none /debug /machine:I386 /out:".\Debug\tallwide.x32"

!ENDIF 

# Begin Target

# Name "Transition - Win32 Release"
# Name "Transition - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;hpj;bat;for;f90"
# Begin Source File

SOURCE=.\Tallwide.def
# End Source File
# Begin Source File

SOURCE=..\source\Twasset.cpp
# End Source File
# Begin Source File

SOURCE=..\source\Twreg.cpp
# End Source File
# Begin Source File

SOURCE=..\source\Twtrans.cpp
# End Source File
# Begin Source File

SOURCE=..\source\Twxtra.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# Begin Source File

SOURCE=..\source\TWAsset.h
# End Source File
# Begin Source File

SOURCE=..\source\TWReg.h
# End Source File
# Begin Source File

SOURCE=..\source\TWTrans.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;cnt;rtf;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Bitmap10.bmp
# End Source File
# Begin Source File

SOURCE=.\Bitmap11.bmp
# End Source File
# Begin Source File

SOURCE=.\Bitmap12.bmp
# End Source File
# Begin Source File

SOURCE=.\Bitmap13.bmp
# End Source File
# Begin Source File

SOURCE=.\Media\BITMAP13.BMP
# End Source File
# Begin Source File

SOURCE=..\BMPs\bitmap14.bmp
# End Source File
# Begin Source File

SOURCE=.\bitmap14.bmp
# End Source File
# Begin Source File

SOURCE=.\Media\bitmap15.bmp
# End Source File
# Begin Source File

SOURCE=.\Bitmap7.bmp
# End Source File
# Begin Source File

SOURCE=.\Bitmap8.bmp
# End Source File
# Begin Source File

SOURCE=.\Bitmap9.bmp
# End Source File
# Begin Source File

SOURCE=.\Media\goalie.ico
# End Source File
# Begin Source File

SOURCE=..\BMPs\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\Icon1.ico
# End Source File
# Begin Source File

SOURCE=.\Media\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\Media\mmlogo.bmp
# End Source File
# Begin Source File

SOURCE=".\Picon-bw.bmp"
# End Source File
# Begin Source File

SOURCE=.\Redball.bmp
# End Source File
# Begin Source File

SOURCE=.\Media\SafeForSW.bmp
# End Source File
# Begin Source File

SOURCE=.\Tallwide.rc
# End Source File
# Begin Source File

SOURCE=.\TALWIDE.BMP
# End Source File
# Begin Source File

SOURCE=.\Media\TALWIDE02.BMP
# End Source File
# Begin Source File

SOURCE=.\Talwide2.bmp
# End Source File
# Begin Source File

SOURCE=.\Talwide3.bmp
# End Source File
# Begin Source File

SOURCE=.\Talwide4.bmp
# End Source File
# Begin Source File

SOURCE=.\Talwide5.bmp
# End Source File
# Begin Source File

SOURCE=.\Talwide6.bmp
# End Source File
# End Group
# End Target
# End Project
