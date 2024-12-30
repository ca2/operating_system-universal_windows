// Created by camilo on 2021-08-30 21:54 BRT <3ThomasBS_!!
#include "framework.h"
#include "node.h"
#include "aura/platform/system.h"
#include "aura/platform/session.h"
#include "aura/user/user/user.h"
#include "aura/windowing/windowing.h"
//#include "interaction_impl.h"
#undef ___new
#include <winrt/Windows.Graphics.Display.h>

//#include "_windows_runtime.h"


float g_DPIScaleX__2;
float g_DPIScaleY__2;


namespace aura_universal_windows
{


   node::node()
   {

   }


   node::~node()
   {


   }


   //void node::main()
   //{

   //   //auto psystem = system();

   //   //auto estatus = psystem->main();

   //   //if (!estatus)
   //   //{

   //   //   return estatus;

   //   //}

   //   //return estatus;

   //   //return ::success;

   //}


   void node::dpi_os_initialize()
   {

      user_post([this]()
         {
            //::wait(::winrt::Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal, ref ___new ::winrt::Windows::UI::Core::DispatchedHandler([]()
              // {

            auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

            g_DPIScaleX__2 = displayinformation.LogicalDpi();
            g_DPIScaleY__2 = displayinformation.LogicalDpi();

            //   })));
         });

   }


} // namespace aura_universal_windows



