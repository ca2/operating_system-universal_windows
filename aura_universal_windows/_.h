// Created by camilo on 2021-08-29 21:17 BRT <3ThomasBS_!!
#pragma once


#include "aura_windows_common/_.h"
#include "apex_universal_windows/_.h"
//#include "directx/_.h"
//#include "direct2d/_.h"


#if defined(_AURA_UNIVERSAL_WINDOWS_LIBRARY)
#define CLASS_DECL_AURA_UNIVERSAL_WINDOWS  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_AURA_UNIVERSAL_WINDOWS  CLASS_DECL_IMPORT
#endif

