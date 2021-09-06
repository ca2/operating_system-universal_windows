#pragma once





#include <sdkddkver.h>

//#define  NTDDI_VERSION     0x06020000        //  NTDDI_WIN8
//#define  WINVER            0x0602            // _WIN32_WINNT_WIN8
//#define _WIN32_WINNT 	   0x0602            // _WIN32_WINNT_WIN8
//#define _WIN32_IE          0x0A00            // _WIN32_IE_IE100


#define VC_EXTRALEAN




#ifndef WIN32
#define WIN32
#endif

//#ifndef WIN32_LEAN_AND_MEAN
//#define WIN32_LEAN_AND_MEAN
//#endif

#ifdef _UNICODE
#ifndef UNICODE
#define UNICODE         // UNICODE is used by Windows headers
#endif
#endif

#ifdef UNICODE
#ifndef _UNICODE
#define _UNICODE        // _UNICODE is used by C-runtime/MFC headers
#endif
#endif

#ifdef VC_EXTRALEAN
#define NOSERVICE
#define NOMCX
#define NOIME
#define NOSOUND
#define NOCOMM
#define NORPC

#ifndef NO_ANSIUNI_ONLY
#ifdef _UNICODE
#define UNICODE_ONLY
#else
#define ANSI_ONLY
#endif
#endif //!NO_ANSIUNI_ONLY

#endif //VC_EXTRALEAN

/////////////////////////////////////////////////////////////////////////////
// Turn off warnings for /W4
// To resume any of these warning: #pragma warning(default: 4xxx)
// which should be placed after the AFX include files

#pragma warning(push)
#pragma warning(disable: 4311 4312)
#pragma warning(disable: 4201)  // winnt.h uses nameless structs
#define _WINSOCKAPI_

#include <winapifamily.h>
#include <windows.h>
#include <shlwapi.h>
#include <shellapi.h>
#include <winuser.h>
#if defined(__cplusplus_winrt)
#include <wrl/client.h>
//#define __PLACEMENT_NEW_INLINE
//#define _IOSFWD_
//#define _ALGORITHM_
//#define std _std
#include <agile.h>
//#undef std
#endif
#if defined(__cplusplus_winrt)
using namespace ::Platform;
using namespace ::winrt::Windows::System;
using namespace ::winrt::Windows::System::Threading;
using namespace ::winrt::Windows::Storage;
#endif


#include "__stdint.h"

#include <stdio.h>
#include <string.h>
#include <math.h>





#include <winreg.h>
#include <winnls.h>
#include <stddef.h>
#include <limits.h>
#include <malloc.h>
#ifdef VC6
#include <mbstring.h>
#endif
#include <new.h>
#include <eh.h>

#undef __window_procedure

//#define MAX_DWORD_PTR ((dword_ptr)(-1))


#define WINRT_SOCKETS
#define _WINSOCK_DEPRECATED_NO_WARNINGS


#pragma once




#pragma once

//#ifdef WINDOWS_DESKTOP
//#define IMPLEMENT_VISTA_TOOLS
//#endif

#define WIN32
#define DRAWDIB_INCLUDE_STRETCHDIB

#include <typeinfo>

//typedef std::type_info ::std::type_info;



#include <vadefs.h>



#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <stddef.h>
#include <stdarg.h>
#include <errno.h>


#ifdef __cplusplus_winrt

#include <wrl.h>
#include <wrl/client.h>
//#include <agile.h>

#endif



