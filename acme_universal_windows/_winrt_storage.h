// From _windows_runtime.h by camilo on 2022-09-23 ~01:10 <3ThomasBorregaardSørensen!!
#pragma once


#undef new
#include <winrt/Windows.Storage.h>


CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::Storage::StorageFolder windows_runtime_folder(::particle * pparticle, string & strRelative, string & strPrefix);


CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::Storage::StorageFolder _windows_runtime_folder(::particle * pparticle, string & strRelative, string & strPrefix);


CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::Storage::StorageFolder windows_runtime_known_folder(::particle * pparticle, string & strRelative, string & strPrefix);


CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::Storage::StorageFolder windows_runtime_folder(::particle * pparticle, const ::file::path & path);



