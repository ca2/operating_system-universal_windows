// created by Camilo 2022-03-25 08:58 BRT <3CamiloSasukeThomasBorregaardSoerensen
#include "framework.h"


namespace windowing_universal_windows
{


   framework_impact_source::framework_impact_source(window * pwindow) :
      m_pwindow(pwindow)
   {

   }


   ::winrt::Windows::ApplicationModel::Core::IFrameworkView framework_impact_source::CreateView()
   {

      return m_pwindow->m_frameworkview;

   }


} // namespace windowing_universal_windows



