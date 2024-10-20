// Created by camilo on 2021-08-30 16:40 BRT <3ThomasBS_!!
#pragma once


#include "acme_windows_common/node.h"


#undef ___new
#include <winrt/Windows.Storage.h>


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS node :
      virtual public ::acme_windows_common::node
   {
   public:


      node();
      ~node() override;


      //void implement(::pointer<::acme::node>& pnode, ::pointer<::acme::system> & psystem) override;


      void node_main() override;


      string audio_get_default_implementation_name() override;

      string veriwell_multimedia_music_midi_get_default_implementation_name() override;


      bool set_process_priority(::enum_priority epriority);

      
      virtual ::winrt::Windows::Storage::StorageFolder windows_runtime_folder(::particle * pparticle, string & strRelative, string & strPrefix, bool bDeferCreateFolder);
      
      
      virtual ::winrt::Windows::Storage::StorageFolder _windows_runtime_folder(::particle * pparticle, string & strRelative, string & strPrefix);
      
      
      virtual ::winrt::Windows::Storage::StorageFolder windows_runtime_known_folder(::particle * pparticle, string & strRelative, string & strPrefix);
      
      
      virtual ::winrt::Windows::Storage::StorageFolder windows_runtime_folder(::particle * pparticle, const ::file::path & path, bool bDeferCreateFolder);


      virtual ::winrt::Windows::Storage::StorageFile windows_runtime_file(::particle * pparticle, const char * lpcszFileName, ::u32 dwDesiredAcces, ::u32 dwShareMode, ::u32 dwCreationDisposition, ::u32 dwFlagsAndAttributes);


      virtual bool windows_runtime_filetime(::particle * pparticle, ::winrt::Windows::Storage::StorageFile file, file_time * lpCreationTime, file_time * lpItemTime, file_time * lpLastWriteTime);


      void on_start_system() override;


   };


} // namespace acme_universal_windows



