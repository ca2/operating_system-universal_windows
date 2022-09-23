// From _windows_runtime.h by camilo on 2022-09-23 ~05:30 <3ThomasBorregaardSorensen!!
#pragma once


#undef new
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.ApplicationModel.Core.h>


CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::UI::Core::CoreDispatcherPriority windows_runtime_UICoreDispatcherPriority(enum_priority epriority);


template < typename PREDICATE >
void windows_runtime_async(PREDICATE predicate, enum_priority epriority = e_priority_normal)
{

   auto priority = windows_runtime_UICoreDispatcherPriority(epriority);

   auto mainview = ::winrt::Windows::ApplicationModel::Core::CoreApplication::MainView();

   auto dispatcher = mainview.CoreWindow().Dispatcher();

   auto handler = ::winrt::Windows::UI::Core::DispatchedHandler(predicate);

   dispatcher.RunAsync(priority, handler);

}
