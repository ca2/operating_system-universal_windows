#pragma once


#include "aura_universal_windows/_.h"
//#include "aura/user/_.h"
#include "directx/_.h"
#include "direct2d/_.h"


#ifdef _WINDOWING_UNIVERSAL_WINDOWS_STATIC
#define CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS
#elif defined(_WINDOWING_UNIVERSAL_WINDOWS_LIBRARY)
#define CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS  CLASS_DECL_IMPORT
#endif


namespace windowing_universal_windows
{

   
   class windowing;
   class hwnd_array;
   class window;


   inline buffer * __buffer(::graphics::graphics * pgraphics) { return pgraphics->m_pWindowingUniversalWindowsBuffer; }


} // namespace windowing_universal_windows



