#pragma once


#include "aura_universal_windows/_.h"
#include "direct2d/_.h"



#ifdef _windowing_universal_windows_project
#define CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS  CLASS_DECL_IMPORT
#endif


namespace windowing_universal_windows
{


   class windowing;
   class hwnd_array;
   class window;

   CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS buffer * __buffer(::graphics::graphics * pgraphics);


} // namespace windowing_universal_windows



