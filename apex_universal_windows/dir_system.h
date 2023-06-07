#pragma once


#include "apex/filesystem/filesystem/dir_system.h"


namespace apex_universal_windows
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS dir_system:
      virtual public ::dir_system
   {
   public:


      ::file::path            m_strTimeFolder;
      ::file::path            m_strNetSeedFolder;

      ::file::path            m_strCommonAppData;
      ::file::path            m_strAppData;
      ::file::path            m_strPrograms;
      ::file::path            m_strCommonPrograms;


      dir_system();
      ~dir_system() override;
      
      
      void initialize(::particle * pparticle) override;


      void init_system() override;

      //virtual ::std::string dir_root() override;


      //virtual ::file::path get_memory_map_base_folder_path() const override;


      //virtual ::file::path home() override;
      //virtual ::file::path program_data() override;

      //virtual ::file::path roaming() override;





      //virtual ::file::path application_installer_folder(const ::file::path& pathExe, string strAppId, const ::string & pszPlatform, const ::string & pszConfiguration, const ::string & pszLocale, const ::string & pszSchema) override;

      //   virtual ::file::path get_application_path(string strAppId, const ::string & pszPlatform, const ::string & pszConfiguration) override;

         //virtual ::file::path get_last_run_application_path_file(string strAppId) override;

         //virtual ::file::path get_last_run_application_path(string strAppId) override;

   };


} // namespace apex_universal_windows



