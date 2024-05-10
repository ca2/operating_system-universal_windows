#pragma once


//#undef new
//#include <winrt/Windows.Foundation.h>
//#include <winrt/Windows.Foundation.Collections.h>
//using namespace winrt;
//#define new ACME_NEW


#define NOTHROW throw()
#define THROWS noexcept(false)


#ifdef DEBUG
#define RELEASENOTHROW noexcept(false)
#else
#define RELEASENOTHROW throw()
#endif


#ifndef WIN32
#define WIN32
#endif


#ifndef WINDOWS
#define WINDOWS
#endif


#ifndef _WINDOWS
#define _WINDOWS
#endif


#ifndef UNIVERSAL_WINDOWS
#define UNIVERSAL_WINDOWS
#endif


#define DEBUG_BREAK __debugbreak()


//#include <stdio.h>
//#include <memory.h>
//#include <string.h>
//#include <wchar.h>
//#include <ctype.h>
//#include <stdarg.h>
//#include <tchar.h>


#ifdef __cplusplus

#include <typeinfo>

typedef std::type_info std_type_info;

#endif


#define WIN32_LEAN_AND_MEAN


#ifdef UNICODE

using platform_char = wchar_t;

#else

using platform_char = char;

#endif


#include "cross/cross.h"


// #define __EVALUATE(xxx) xxx
// #define __CONCAT(xxx, yyy) xxx ## yyy
// //#define __STRING(xxx) # xxx

// #define __CONCAT3(xxx, yyy, zzz) xxx ## yyy ## zzz


//#include <stdio.h>
//#include <mmsystem.h>


#define MOVE_SEMANTICS


#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE
#endif

#ifndef _CRT_NONSTDC_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS
#endif

#ifndef _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#endif


typedef wchar_t unichar;
typedef unsigned int unichar32;



#include <stdarg.h>
//

#include <concepts>


#include <tuple>


#include <intrin.h>


#define DEBUG_BREAK __debugbreak()



#include "cross/cross.h"












#include <stddef.h>
#include <limits.h>
#include <new.h>
#include <eh.h>

#undef __window_procedure


#define IMPLEMENT_VISTA_TOOLS
#ifndef WIN32
#define WIN32
#endif
#define DRAWDIB_INCLUDE_STRETCHDIB

#ifdef __cplusplus

#include <typeinfo>

typedef std::type_info std_type_info;

#endif


typedef wchar_t unichar;

#ifdef UNICODE

using platform_char = wchar_t;

#else

using platform_char = char;

#endif

