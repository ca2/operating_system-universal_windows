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


   void node::message_box_factory()
   {

      create_factory < ::windowing_universal_windows::message_box, ::user::message_box >();

   }


   ::e_status node::implement()
   {

      auto estatus = m_psystem->m_paurasystem->branch();

      if (!estatus)
      {

         return estatus;

      }

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

      return ::success;

   }


   ::e_status node::call_member(::i64 i)
   {

      //if (i == SOUL_ID)
      //{

      //   ::winrt::Windows::ApplicationModel::Core::CoreApplication::Run(m_frameworkviewsource);

      //   return ::success;

      //}

      auto estatus = aura::universal_windows::node::call_member(i);

      if (!estatus)
      {

         return estatus;

      }

      return estatus;

   }


   bool node::_os_calc_app_dark_mode()
   {

      return _os_calc_system_dark_mode();

   }


   bool node::_os_calc_system_dark_mode()
   {

      auto colortypeBackground = ::winrt::Windows::UI::ViewManagement::UIColorType::Background;

      auto uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

      auto colorvalue = uisettings.GetColorValue(colortypeBackground);

      auto color = argb(colorvalue.A, colorvalue.R, colorvalue.G, colorvalue.B);

      auto luminance = color.get_luminance();

      return luminance < 0.5;

   }

   void node::OnUISettingsColorValuesChange(::winrt::Windows::UI::ViewManagement::UISettings uisettings, ::winrt::Windows::Foundation::IInspectable inpectable)
   {

      auto psubject = m_psystem->m_papexsystem->subject(id_os_dark_mode);

      m_psystem->m_papexsystem->handle_subject(psubject);

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

} // namespace windowing_universal_windows



