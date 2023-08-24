// Created by camilo on 2021-08-29 21:01 BRT <3ThomasBS__!!
#pragma once


#include "acme_windows_common/_.h"


#if defined(_acme_universal_windows_project)
#define CLASS_DECL_ACME_UNIVERSAL_WINDOWS  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_ACME_UNIVERSAL_WINDOWS  CLASS_DECL_IMPORT
#endif


CLASS_DECL_ACME_UNIVERSAL_WINDOWS uptr keycode_to_char(uptr n);


namespace acme_universal_windows
{


   class file_system;
   class file_context;

   class dir_system;
   class dir_context;

   class node;


} // namespace acme_universal_windows
