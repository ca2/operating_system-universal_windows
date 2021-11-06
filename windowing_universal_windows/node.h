// Created by camilo on 2021-09-04 22:51 BRT <3ThomasBS_!!
#pragma once


namespace windowing_universal_windows
{


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS node :
      virtual public aura::universal_windows::node
   {
   public:


      bool                          m_bAppInit;

      //auto uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

      ::winrt::Windows::UI::ViewManagement::UISettings m_uisettings;



      node();
      ~node() override;


      void message_box_factory() override;


      ::e_status implement() override;


      ::e_status call_member(::i64 i) override;
      

      //bool _os_calc_app_dark_mode() override;

      //bool _os_calc_system_dark_mode() override;

      void OnUISettingsColorValuesChange(::winrt::Windows::UI::ViewManagement::UISettings, ::winrt::Windows::Foundation::IInspectable);

      virtual void fetch_user_color();

      void app_init();

      //__pointer(::extended::future < ::conversation >) _message_box(::object * pobject, const ::string & pszMessage, const ::string & pszTitle, const ::e_message_box & emessagebox) override;

      ::e_status node_post(const ::routine & routine) override;


   };


   //inline window * __window(::acme::node * pnode) { return pnode->m_pWindowingUniversalWindowsNode->m_pwindowNode; }


} // namespace windowing_universal_windows



