// From _windows_runtime.h by camilo on 2022-09-23 ~01:15 <3ThomasBorregaardSorensen!!
#pragma once


#undef new
#include <windows.h>
#include <winrt/Windows.Storage.Streams.h>


CLASS_DECL_ACME_UNIVERSAL_WINDOWS memsize windows_runtime_read_buffer(void * p, memsize s, ::winrt::Windows::Storage::Streams::IBuffer ibuffer);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::Storage::Streams::IBuffer windows_runtime_buffer(const void * p, memsize s);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS memory windows_runtime_buffer_memory(::winrt::Windows::Storage::Streams::IBuffer ibuffer, memsize pos = 0, memsize size = -1);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS memory windows_runtime_buffer_memory(::winrt::Windows::Storage::Streams::IBuffer ibuffer);



