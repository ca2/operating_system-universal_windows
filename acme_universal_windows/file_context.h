#pragma once


#include "acme_windows_common/file_context.h"


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS file_context :
      virtual public ::acme_windows_common::file_context
   {
   public:


      ::pointer<::acme_universal_windows::file_system>     m_pfilesystem;
      ::pointer<::acme_universal_windows::directory_system>      m_pdirectorysystem;


      file_context();
      ~file_context() override;


      void initialize(::particle * pparticle) override;


      void init_system() override;


      void calculate_main_resource_memory() override;


      //void get_status(::file::file_status & status, const ::file::path & path) override;
      //void set_status(const ::file::path & path, const ::file::file_status & status) override;



      //virtual bool FullPath(string & str, const ::string & pszFileIn);

      //virtual bool FullPath(wstring & wstrFullPath, const wstring & wstrPath);
      //virtual unsigned int GetFileName(const ::string & pszPathName, string & str);

      //virtual void GetModuleShortFileName(HINSTANCE hInst, string & strShortName);

      //bool is_file_or_dir(const ::file::path & path, ::file::enum_type * petype = nullptr) override;

      ::file::enum_type get_type(const ::file::path& path) override;
      
      ::payload length(const ::file::path & path) override;
      ::payload length(const ::file::path & path, ::payload * pvarQuery) override;

      void transfer(const ::file::path & pathNew, const ::file::path & path) override;

      void erase(const ::file::path & path) override;

      virtual bool is_read_only(const ::file::path & path) override;

      ::file_pointer resource_get_file(const ::file::path & path) override;

      virtual bool get_last_write_time(FILETIME * pfiletime, const ::scoped_string & scopedstrFilename);

      //::e_status update_module_path() override;

      ::file_pointer get_file(const ::payload & payloadFile, ::file::e_open eopen, ::pointer < ::file::exception > * ppfileexception = nullptr) override;

      ::file_pointer create_native_file(const ::file::path & path, ::file::e_open eopen, ::pointer < ::file::exception > * ppfileexception = nullptr) override;

      virtual ::file::path dropbox_info_network_payload() override;

      //virtual ::file::path onedrive_global_ini(::particle * pparticle) override;
      //virtual ::file::path onedrive_cid_ini(::particle * pparticle) override;


   };


} // namespace acme_universal_windows



