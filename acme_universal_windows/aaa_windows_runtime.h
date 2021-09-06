// Created by camilo on 2021-08-31 14:04 BRT <3ThomasBS__!!
#pragma once


#include "acme/_start.h"
#include <windows.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.System.Threading.h>
#undef new
class matter;
class lparam;
class object;
//#include <collection.h>
//#include <ppltasks.h>
#if defined(_ACME_UNIVERSAL_WINDOWS_LIBRARY)
#define CLASS_DECL_ACME_UNIVERSAL_WINDOWS  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_ACME_UNIVERSAL_WINDOWS  CLASS_DECL_IMPORT
#endif
#include "acme/constant/_.h"
#include "acme/constant/_constant.h"
#include "acme/constant/exception.h"
#include "acme/constant/filesystem.h"

inline bool is_set(const void * p) { return (uptr)p > 65536; }
inline bool is_null(const void * p)
{

   const auto MAX = (size_t)(-1) - 65536;

   return ((size_t)p <= 65536) || ((size_t)p) >= (MAX);

}




