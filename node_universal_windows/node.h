// From windowing_universal_windows by camilo on 2022-09-22 01:07 <3ThomasBorregaardSorensen!!
// Created by camilo on 2021-09-04 22:51 BRT <3ThomasBS_!!
#pragma once


#include "aura_universal_windows/node.h"


namespace node_universal_windows
{


   class CLASS_DECL_NODE_UNIVERSAL_WINDOWS node :
      virtual public aura_universal_windows::node
   {
   public:



      //__reference(::aura_universal_windows::interaction_impl) m_pimplMain;

      //bool                          m_bAppInit;

      ////auto uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

      //::winrt::Windows::UI::ViewManagement::UISettings m_uisettings;



      node();
      ~node() override;


      //void message_box_factory() override;


      void implement(__pointer(::acme::node)& pnode, __pointer(::acme::system)& psystem) override;


      void call_member(::i64 i) override;
      

      //bool _os_calc_app_dark_mode() override;

      //bool _os_calc_system_dark_mode() override;

      //void OnUISettingsColorValuesChange(::winrt::Windows::UI::ViewManagement::UISettings, ::winrt::Windows::Foundation::IInspectable);

      //virtual void fetch_user_color();

      //void app_init();

      //__pointer(::extended::future < ::conversation >) _message_box(::object * pobject, const ::string & pszMessage, const ::string & pszTitle, const ::e_message_box & emessagebox) override;

      void node_post(const ::procedure & procedure) override;


      void windowing_post(const ::procedure& procedure) override;


   };


   //inline window * __window(::acme::node * pnode) { return pnode->m_pWindowingUniversalWindowsNode->m_pwindowNode; }


} // namespace node_universal_windows


