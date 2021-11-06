#pragma once


#include "aura_universal_windows/_windows_runtime.h" 




#undef new
#include <winrt/Windows.ApplicationModel.Activation.h>
#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.Graphics.Display.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Text.Core.h>
#include <winrt/Windows.UI.Popups.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.UI.Xaml.h>





#include <wrl/client.h>
#include <d3d11_1.h>
#include <d2d1_1.h>
#include <dwrite_1.h>
#include <wincodec.h>

#define new ACME_NEW


inline ::winrt::Windows::Foundation::Rect ScaleRect(::winrt::Windows::Foundation::Rect rectangle, double scale)
{

   rectangle.X = (float)(rectangle.X * scale);
   rectangle.Y = (float)(rectangle.Y * scale);
   rectangle.Width = (float)(rectangle.Width * scale);
   rectangle.Height = (float)(rectangle.Height * scale);

   return rectangle;

}


//#include "direct2d_buffer.h"

//#include "directx_impact.h"

//#include "directx_interaction.h"

//#include "directx_application.h"



