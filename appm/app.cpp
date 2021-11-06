#include "framework.h"
#include <DirectXMath.h>

#undef System

using namespace Microsoft::WRL;
using namespace ::winrt::Windows::Foundation;
using namespace ::winrt::Windows::UI::Core;
using namespace DirectX;
using namespace ::winrt::Windows::ApplicationModel;
using namespace ::winrt::Windows::ApplicationModel::Core;
using namespace ::winrt::Windows::ApplicationModel::Activation;
using namespace ::winrt::Windows::System;
using namespace ::winrt::Windows::Graphics::Display;





[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
   
   auto source = ::metrowin::new_directx_application_source("m_app.exe : app=bergedge");

   ::winrt::Windows::ApplicationModel::Core::CoreApplication::Run(source);
   
   return 0;

}
