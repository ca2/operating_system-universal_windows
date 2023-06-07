// From _windows_runtime.h by camilo on 2022-09-23 ~01:15 <3ThomasBorregaardSorensen!!
#pragma once


#undef new
#include <winrt/Windows.System.h>


CLASS_DECL_ACME_UNIVERSAL_WINDOWS uptr virtualkey_to_char(::winrt::Windows::System::VirtualKey e);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS::user::enum_key virtualkey_to_userkey(::winrt::Windows::System::VirtualKey e, bool & bSpecialKey);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS uptr virtualkey_to_code(::winrt::Windows::System::VirtualKey e);



