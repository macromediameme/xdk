														 
/* THIS FILE IS OVERWRITTEN BY AUTOBUILD SCRIPTS */	
														
#ifndef DVERSION_H										
#define DVERSION_H										
														
#define VER_BUILDNUM 127							
#define VER_BUILDNUM_STRING "127"					
														
#ifndef VER_COUNTRY									
#if defined(FVers)													   
#define VER_COUNTRY VER_COUNTRY_FRANCE						
#elif defined(GVers)										
#define VER_COUNTRY VER_COUNTRY_GERMANY					
#elif defined(JVers)										
#define VER_COUNTRY VER_COUNTRY_JAPAN						
#elif defined(KVers)										
#define VER_COUNTRY VER_COUNTRY_KOREA						
#else														
#define VER_COUNTRY VER_COUNTRY_US							
#endif   																					   
#endif 													  								   
														
#ifndef VER_MAJORVERSION								
#define VER_MAJORVERSION 8				    
#endif													
														
#ifndef VER_MAJORVERSION_STRING						
#define VER_MAJORVERSION_STRING "8"     
#endif													
														
#ifndef VER_MINORVERSION								
#define VER_MINORVERSION 5				    
#endif													
														
#ifndef VER_MINORVERSION_STRING						
#define VER_MINORVERSION_STRING "5"     
#endif													
														
#ifndef VER_BUGFIXVERSION								
#define VER_BUGFIXVERSION 0                   
#endif													
														
#ifndef VER_BUGFIXVERSION_STRING						
#define VER_BUGFIXVERSION_STRING "0"      
#endif													
														
#endif													
