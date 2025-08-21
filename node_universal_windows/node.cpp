// From windowing_universal_windows by camilo on 2022-09-22 01:07 <3ThomasBorregaardSorensen!!
// Created by camilo on 2021-09-04 22:55 BRT <3ThomasBS_!!
#include "framework.h"
#include "node.h"
#include "aura/platform/session.h"
#include "aura/platform/system.h"
#include "aura/user/user/user.h"
#include "windowing_universal_windows/window.h"
#include "windowing_universal_windows/windowing.h"


float g_DPIScaleX__2;
float g_DPIScaleY__2;


namespace node_universal_windows
{


   node::node()
   {

      //m_bAppInit = false;
      //m_pWindowingUniversalWindowsNode = this;

   }


   node::~node()
   {


   }


   //void node::message_box_factory()
   //{

   //   factory()->add_factory_item < ::windowing_universal_windows::message_box, ::user::message_box >();

   //}


   //void node::implement(::pointer<::platform::node> & pnode, ::pointer<::platform::system> & psystem)
   void node::node_main()
   {

      ::aura_universal_windows::node::node_main();

   }


   //void node::on_system_main()
   //{

   //   ////auto estatus = 

   //   //system()->m_itask = 0;

   //   //system()->m_htask = nullptr;

   //   //system()->branch_synchronously();

   //   ////if (!estatus)
   //   ////{

   //   ////   return estatus;

   //   ////}

   //   //if (!windowing())
   //   //{

   //   //   session()->user()->create_windowing();

   //   //}

   //   auto pwindow = øallocate ::windowing_universal_windows::window;

   //   ::cast 

   //   pwindow->windowing()->m_pwindowMain = pwindow;

   //   pwindow->initialize(this);

   //   system()->m_pwindowMain = pwindow;

   //   auto frameworkviewsource = system()->m_frameworkviewsource;

   //   ::winrt::Windows::ApplicationModel::Core::CoreApplication::Run(frameworkviewsource);

   //   //estatus = call_member(SOUL_ID);

   //   //if (!estatus)
   //   //{

   //   //   return estatus;

   //   //}

   //   //return ::success;

   //}


   void node::call_member(long long i)
   {

      //if (i == SOUL_ID)
      //{

      //   ::winrt::Windows::ApplicationModel::Core::CoreApplication::Run(m_frameworkviewsource);

      //   return ::success;

      //}

      //auto estatus = 

      aura_universal_windows::node::call_member(i);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


   //bool node::_os_calc_app_dark_mode()
   //{

   //   return _os_calc_system_dark_mode();

   //}


   //bool node::_os_calc_system_dark_mode()
   //{

   //   auto colortypeBackground = ::winrt::Windows::UI::ViewManagement::UIColorType::Background;

   //   auto uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

   //   auto colorvalue = uisettings.GetColorValue(colortypeBackground);

   //   auto color = argb(colorvalue.A, colorvalue.R, colorvalue.G, colorvalue.B);

   //   auto luminance = color.get_luminance();

   //   return luminance < 0.5;

   //}


   //void node::OnUISettingsColorValuesChange(::winrt::Windows::UI::ViewManagement::UISettings uisettings, ::winrt::Windows::Foundation::IInspectable inpectable)
   //{

   //   fetch_user_color();

   //   //auto luminance = color.get_luminance();

   //   //return luminance < 0.5;


   //   //system()->signal(id_user_color);

   //}


   //void node::fetch_user_color()
   //{

   //   auto colortypeBackground = ::winrt::Windows::UI::ViewManagement::UIColorType::Background;

   //   auto uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

   //   auto colorvalue = uisettings.GetColorValue(colortypeBackground);

   //   auto colorBackground = argb(colorvalue.A, colorvalue.R, colorvalue.G, colorvalue.B);

   //   system()->m_pnode->background_color(colorBackground);

   //}

   //
   //void node::app_init()
   //{

   //   //m_uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

   //   m_uisettings.ColorValuesChanged(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::ViewManagement::UISettings, winrt::Windows::Foundation::IInspectable>(this, &node::OnUISettingsColorValuesChange));

   //}

   ////void node::CommandInvokedHandler(::winrt::Windows::UI::Popups::IUICommand const & command)
   ////{
   ////   // Display message.
   ////   std::wstringstream stringstream;
   ////   stringstream << L"The '" << command.Label().c_str() << L"' command has been selected.";
   ////   rootPage.NotifyUser(stringstream.str().c_str(), NotifyType::StatusMessage);
   ////}


   //void node::user_post(const ::procedure & procedure)
   //{

   //   auto window = ::winrt::Windows::ApplicationModel::Core::CoreApplication::MainView().CoreWindow();

   //   auto dispatcher = window.Dispatcher();

   //   dispatcher.RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal,
   //      [procedure]()
   //   {

   //      procedure();

   //   });

   //}

   //void node::windowing_post(const ::procedure & procedure)
   //{

   //   node_post(procedure);

   //}



} // namespace node_universal_windows



