// Created by camilo on 2021-08-31 19:54 BRT <3ThomasBS__!!
// From _windows_storage.h on 2022-09-23 01:49 <3ThomasBorregaardSørensen!!
#pragma once


#include "acme_universal_windows/_winrt_storage.h"
//#include <winrt/Windows.Storage.Search.h>

//::winrt::Windows::Storage::StorageFile windows_runtime_file(const char * lpcszFileName, ::u32 dwDesiredAcces, ::u32 dwShareMode, LPSECURITY_ATTRIBUTES lpSA, ::u32 dwCreationDisposition, ::u32 dwFlagsAndAttributes, HANDLE hTemplateFile)

CLASS_DECL_APEX_UNIVERSAL_WINDOWS::winrt::Windows::Storage::StorageFile windows_runtime_file(::particle * pparticle, const char * lpcszFileName, ::u32 dwDesiredAcces, ::u32 dwShareMode, ::u32 dwCreationDisposition, ::u32 dwFlagsAndAttributes);

CLASS_DECL_APEX_UNIVERSAL_WINDOWS bool windows_runtime_filetime(::winrt::Windows::Storage::StorageFile file, LPFILETIME lpCreationTime, LPFILETIME lpItemTime, LPFILETIME lpLastWriteTime);
