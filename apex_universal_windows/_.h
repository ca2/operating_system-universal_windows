// Created by camilo on 2021-08-29 21:09 BRT <3ThomasBS_!!
#pragma once


#include "apex_windows_common/_.h"
#include "acme_universal_windows/_.h"
#include "apex/operating_system.h"


#if defined(_APEX_UNIVERSAL_WINDOWS_LIBRARY)
#define CLASS_DECL_APEX_UNIVERSAL_WINDOWS  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APEX_UNIVERSAL_WINDOWS  CLASS_DECL_IMPORT
#endif


namespace apex_universal_windows
{


   class file_system;
   class file_context;

   class dir_system;
   class dir_context;

   class node;


} // namespace apex_universal_windows


#include "_windows_runtime.h"



