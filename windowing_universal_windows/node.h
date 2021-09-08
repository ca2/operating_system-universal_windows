// Created by camilo on 2021-09-04 22:51 BRT <3ThomasBS_!!
#pragma once


namespace windowing_universal_windows
{


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS node :
      virtual public aura::universal_windows::node
   {
   public:


      struct framework_view_source :
         public winrt::implements < framework_view_source, ::winrt::Windows::ApplicationModel::Core::IFrameworkViewSource >
      {


         node * m_pnode;

         framework_view_source(node * node);

         ::winrt::Windows::ApplicationModel::Core::IFrameworkView CreateView();
         

      };


      __pointer(window)             m_pwindowNode;
      framework_view_source         m_frameworkviewsource;
      bool                          m_bAppInit;

      //auto uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

      ::winrt::Windows::UI::ViewManagement::UISettings m_uisettings;



      node();
      ~node() override;


      ::e_status implement() override;


      ::e_status call_member(::i64 i) override;
      

      bool _os_calc_app_dark_mode() override;

      bool _os_calc_system_dark_mode() override;

      void OnUISettingsColorValuesChange(::winrt::Windows::UI::ViewManagement::UISettings, ::winrt::Windows::Foundation::IInspectable);

      void app_init();




   };


   inline window * __window(::acme::node * pnode) { return pnode->m_pWindowingUniversalWindowsNode->m_pwindowNode; }


} // namespace windowing_universal_windows



