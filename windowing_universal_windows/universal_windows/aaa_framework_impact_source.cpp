// created by Camilo 2022-03-25 08:58 BRT <3CamiloSasukeThomasBorregaardSoerensen
#include "framework.h"
#include "framework_impact_source.h"
#include "windowing_universal_windows/window.h"
#include "windowing_universal_windows/windowing.h"


namespace windowing_universal_windows
{


   framework_impact_source::framework_impact_source()
   {

   }


   ::winrt::Windows::ApplicationModel::Core::IFrameworkView framework_impact_source::CreateView()
   {

      return *this;

   }


} // namespace windowing_universal_windows



