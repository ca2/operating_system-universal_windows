// from window by Camilo 2022-03-25 08:56 BRT <3CamiloSasukeThomasBorregaardSoerensen
#pragma once


namespace windowing_universal_windows
{


   struct framework_view_source :
      public winrt::implements < framework_view_source, ::winrt::Windows::ApplicationModel::Core::IFrameworkViewSource >
   {


      window * m_pwindow;

      framework_view_source(window * pwindow);

      ::winrt::Windows::ApplicationModel::Core::IFrameworkView CreateView();


   };



} // namespace windowing_universal_windows



