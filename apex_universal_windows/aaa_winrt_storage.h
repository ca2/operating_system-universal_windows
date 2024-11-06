// Created by camilo on 2021-08-31 19:54 BRT <3ThomasBS__!!
// From _windows_storage.h on 2022-09-23 01:49 <3ThomasBorregaardSorensen!!
#pragma once


#include "acme_universal_windows/_winrt_storage.h"
//#include <winrt/Windows.Storage.Search.h>

//::winrt::Windows::Storage::StorageFile windows_runtime_file(const char * lpcszFileName, unsigned int dwDesiredAcces, unsigned int dwShareMode, LPSECURITY_ATTRIBUTES lpSA, unsigned int dwCreationDisposition, unsigned int dwFlagsAndAttributes, HANDLE hTemplateFile)

CLASS_DECL_APEX_UNIVERSAL_WINDOWS::winrt::Windows::Storage::StorageFile windows_runtime_file(::particle * pparticle, const char * lpcszFileName, unsigned int dwDesiredAcces, unsigned int dwShareMode, unsigned int dwCreationDisposition, unsigned int dwFlagsAndAttributes);

CLASS_DECL_APEX_UNIVERSAL_WINDOWS bool windows_runtime_filetime(::winrt::Windows::Storage::StorageFile file, LPFILETIME lpCreationTime, LPFILETIME lpItemTime, LPFILETIME lpLastWriteTime);
