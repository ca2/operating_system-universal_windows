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



      //::pointer<::aura_universal_windows::interaction_impl>m_pimplMain;

      //bool                          m_bAppInit;

      ////auto uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

      //::winrt::Windows::UI::ViewManagement::UISettings m_uisettings;



      node();
      ~node() override;


      //void message_box_factory() override;


      //void implement(::pointer<::platform::node> & pnode, ::pointer<::platform::system> & psystem) override;
      void node_main() override;


      //void on_system_main() override;


      void call_member(long long i) override;
      

      //bool _os_calc_app_dark_mode() override;

      //bool _os_calc_system_dark_mode() override;

      //void OnUISettingsColorValuesChange(::winrt::Windows::UI::ViewManagement::UISettings, ::winrt::Windows::Foundation::IInspectable);

      //virtual void fetch_user_color();

      //void app_init();

      //pointer< ::extended::future < ::conversation > > _message_box(::particle * pparticle, const ::scoped_string & scopedstrMessage, const ::scoped_string & scopedstrTitle, const ::e_message_box & emessagebox) override;

      //void _user_post(const ::procedure & procedure) override;


      //void windowing_post(const ::procedure& procedure) override;


   };


   //inline window * __window(::platform::node * pnode) { return pnode->m_pWindowingUniversalWindowsNode->m_pwindowNode; }


} // namespace node_universal_windows



