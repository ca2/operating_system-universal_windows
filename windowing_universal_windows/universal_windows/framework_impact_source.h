// from window by Camilo 2022-03-25 08:56 BRT <3CamiloSasukeThomasBorregaardSoerensen
#pragma once


#undef new
#include <winrt/Windows.ApplicationModel.Core.h>


namespace windowing_universal_windows
{


   struct framework_impact_source :
      public winrt::implements < framework_impact_source, ::winrt::Windows::ApplicationModel::Core::IFrameworkViewSource >
   {


      window * m_pwindow;

      framework_impact_source(window * pwindow);

      ::winrt::Windows::ApplicationModel::Core::IFrameworkView CreateView();


   };



} // namespace windowing_universal_windows



