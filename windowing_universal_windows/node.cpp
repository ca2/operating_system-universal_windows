// Created by camilo on 2021-09-04 22:55 BRT <3ThomasBS_!!
#include "framework.h"


float g_DPIScaleX__2;
float g_DPIScaleY__2;


namespace windowing_universal_windows
{


   node::node()
   {

      m_bAppInit = false;
      m_pWindowingUniversalWindowsNode = this;

   }


   node::~node()
   {


   }


   //void node::message_box_factory()
   //{

   //   ::factory::add_factory_item < ::windowing_universal_windows::message_box, ::user::message_box >();

   //}


   void node::implement(__pointer(::acme::node)& pnode, __pointer(class ::system)& psystem)
   {

      //auto estatus = 
      
      m_psystem->m_paurasystem->branch_synchronously();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      auto pwindow = new window;

      auto pwindowMain = ::move_transfer(pwindow);

      pwindowMain->initialize(this);

      m_psystem->m_paurasystem->m_pwindowMain = pwindowMain;

      ::winrt::Windows::ApplicationModel::Core::CoreApplication::Run(pwindowMain->m_frameworkviewsource);

      //estatus = call_member(SOUL_ID);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return ::success;

   }


   void node::call_member(::i64 i)
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


   void node::OnUISettingsColorValuesChange(::winrt::Windows::UI::ViewManagement::UISettings uisettings, ::winrt::Windows::Foundation::IInspectable inpectable)
   {

      fetch_user_color();

      //auto luminance = color.get_luminance();

      //return luminance < 0.5;


      //m_psystem->m_papexsystem->signal(id_user_color);

   }


   void node::fetch_user_color()
   {

      auto colortypeBackground = ::winrt::Windows::UI::ViewManagement::UIColorType::Background;

      auto uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

      auto colorvalue = uisettings.GetColorValue(colortypeBackground);

      auto colorBackground = argb(colorvalue.A, colorvalue.R, colorvalue.G, colorvalue.B);

      m_psystem->m_pnode->background_color(colorBackground);

   }

   
   void node::app_init()
   {

      //m_uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

      m_uisettings.ColorValuesChanged(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::ViewManagement::UISettings, winrt::Windows::Foundation::IInspectable>(this, &node::OnUISettingsColorValuesChange));

   }

   //void node::CommandInvokedHandler(::winrt::Windows::UI::Popups::IUICommand const & command)
   //{
   //   // Display message.
   //   std::wstringstream stringstream;
   //   stringstream << L"The '" << command.Label().c_str() << L"' command has been selected.";
   //   rootPage.NotifyUser(stringstream.str().c_str(), NotifyType::StatusMessage);
   //}


   void node::node_post(const ::procedure & procedure)
   {

      auto window = ::winrt::Windows::ApplicationModel::Core::CoreApplication::MainView().CoreWindow();

      auto dispatcher = window.Dispatcher();
      
      dispatcher.RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal,
         [procedure]()
      {
         
            procedure();

      });

   }


   void node::windowing_post(const ::procedure& procedure)
   {

      node_post(procedure);

   }


} // namespace windowing_universal_windows



