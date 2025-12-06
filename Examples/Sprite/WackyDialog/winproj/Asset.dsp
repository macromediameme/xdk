# Microsoft Developer Studio Project File - Name="Asset" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Asset - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Asset.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Asset.mak" CFG="Asset - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Asset - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Asset - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Asset - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /Gz /Zp4 /MD /W3 /GX /O1 /I "..\..\..\..\include" /I "..\..\..\..\include\win32" /I "..\source\Asset" /I "..\source\Dialog" /D "WINDOWS" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_WINDLL" /D "NDEBUG" /D "RELEASE" /D XDEBUG=0 /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /i "..\..\..\..\include" /d "WIN32" /d "_WINDOWS" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"..\Director.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib winmm.lib vfw32.lib ole32.lib uuid.lib shell32.lib advapi32.lib msvcrt.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib winmm.lib vfw32.lib ole32.lib uuid.lib shell32.lib advapi32.lib msvcrt.lib /nologo /base:"0x6D080000" /subsystem:windows /dll /pdb:none /map /machine:I386 /nodefaultlib /def:".\Asset.def" /out:".\Release\WackyDialogAsset.x32"

!ELSEIF  "$(CFG)" == "Asset - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /c
# ADD CPP /nologo /Gz /Zp4 /MDd /W3 /Gm /Gi /GX /ZI /Od /I "..\..\..\..\include" /I "..\..\..\..\include\win32" /I "..\source\Asset" /I "..\source\Dialog" /D "WINDOWS" /D "_WINDOWS" /D "_WIN32" /D "WIN32" /D "_WINDLL" /D "_DEBUG" /D "DEBUG" /D "TEST" /D XDEBUG=1 /FR /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /i "..\..\..\..\include" /d "WIN32" /d "_WINDOWS" /d "_DEBUG" /d "DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"..\Director.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib winmm.lib vfw32.lib ole32.lib uuid.lib shell32.lib advapi32.lib msvcrtd.lib /nologo /subsystem:windows /dll /debug /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib comdlg32.lib winmm.lib vfw32.lib ole32.lib uuid.lib shell32.lib advapi32.lib msvcrtd.lib /nologo /base:"0x6D080000" /subsystem:windows /dll /debug /machine:I386 /nodefaultlib /def:".\Asset.def" /out:".\Debug\WackyDialogAsset.x32"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "Asset - Win32 Release"
# Name "Asset - Win32 Debug"
# Begin Group "support"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\win\Asset.def
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Asset.rc
# End Source File
# Begin Source File

SOURCE=..\..\..\..\Lib\Win\XSupport.lib
# End Source File
# End Group
# Begin Source File

SOURCE=..\source\Asset\Asset.cpp
# End Source File
# Begin Source File

SOURCE=..\source\Asset\Sprite.cpp
# End Source File
# Begin Source File

SOURCE=..\source\Asset\Xtra.cpp
# End Source File
# End Target
# End Project
