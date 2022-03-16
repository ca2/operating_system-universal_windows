// Create on 2021-03-21 20:00 <3ThomasBS_
// Copied by camilo from operating-system-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
#pragma once


namespace universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS acme_directory :
      virtual public ::windows_common::acme_directory
   {
   public:





      acme_directory();
      ~acme_directory() override;


      //::file::path module_folder() override;


      virtual ::file::path install() override;
      virtual ::file::path default_install() override;
      virtual ::file::path beforeca2() override;
      virtual ::file::path module() override;
      virtual ::file::path relative(::file::path path) override;
      virtual ::file::path app_relative() override;
      virtual ::file::path appdata() override; // appdata
      virtual ::file::path archive() override;
      virtual ::file::path tool() override;
      virtual ::file::path public_system() override;
      virtual ::file::path system() override;
      virtual ::file::path config() override;
      virtual ::file::path local() override;
      virtual ::file::path sensitive() override;
      virtual ::file::path localconfig() override; // #vcs C:\\Users\\user\\AppData\\Roaming\\ca2\\localconfig
      virtual ::file::path ca2roaming() override; // writable root (non-bin, non-exe)
      virtual ::file::path ca2appdata() override; // writable root (non-bin, non-exe)
      virtual ::file::path roaming() override;
      virtual ::file::path program_data() override;
      virtual ::file::path public_root() override; // writable common root (non-bin, non-exe)
      virtual ::file::path bookmark() override;
      virtual ::file::path home() override;
      virtual ::file::path pathfind(const string& pszEnv, const string& pszTopic, const string& pszMode) override;
      virtual ::file::path program_files_x86() override;
      virtual ::file::path program_files() override;
      //virtual ::file::path program_data() override;
      virtual ::file::path stage(string strAppId, string strPlatform, string strConfiguration) override;
      virtual ::file::path sys_temp() override;
      virtual ::string dir_root() override;
      //virtual ::file::path home() override;
      //virtual ::file::path program_data() override;
      //virtual ::file::path roaming() override;
      virtual ::file::path get_memory_map_base_folder_path() override;
      //virtual ::file::path ca2appdata() override;
      //virtual ::file::path ca2roaming() override;
      //virtual ::file::path localconfig() override;
      virtual string system_short_name() override;

      //::file::path default_install() override;
      //::file::path inplace_install(string strAppId, string strPlatform, string strConfiguration) override;
      //virtual ::file::path inplace_install(string strAppId, string strPlatform, string strConfiguration) override;
      virtual ::file::path inplace_install(string strAppId, string strPlatform, string strConfiguration) override;
      virtual ::file::path inplace_matter_install(string strAppId, string strPlatform, string strConfiguration) override;


      virtual void set_path_install_folder(const ::string & pszPath) override;

      //virtual  bool        _shell_get_special_folder_path(HWND hwnd, ::file::path& str, i32 csidl, bool fCreate);
      //virtual ::file::path _shell_get_special_folder_path(i32 csidl, bool fCreate = true, ::windowing::window* pwindow = nullptr);
      //virtual ::file::path _get_known_folder(REFKNOWNFOLDERID kfid);

      //virtual ::file::path pathfind(const string& pszEnv, const string& pszTopic, const string& pszMode) override;

      virtual ::file::path user_appdata_local() override;

      bool is(const char * path1) override;
      bool _is(bool & bDir, const char * path1) override;



// From acme/filesystem/file/dir.cpp by camilo 
// From acme_posix/acme_directory.h
// on 2021-08-09 03:20 BRT
// <3ThomasBorregaardSørensen!!


// namespace posix
// {


// class CLASS_DECL_ACME_POSIX acme_directory :
// virtual public ::acme_directory
// {

// public:

// acme_directory();
// ~acme_directory() override;

      //virtual string name(const char * path1) override;


      //virtual ::file::path module_folder() override;
      
      //bool create(const char * path) override;

      //bool _create(const char * path) override;

      //bool create_directory(const char * path) override;

      //::e_status _create_directory(const char * path) override;

      void rls(::file::path_array & stra, const char * psz) override;

      void rls_dir(::file::path_array & stra, const char * psz) override;

      void ls(::file::path_array & stra, const char * psz) override;

      void ls_dir(::file::path_array & stra, const char * psz) override;

      void ls_file(::file::path_array & stra, const char * psz) override;

      //int make_path(const char * psz) override;

      string get_current() override;


   };


} // namespace universal_windows



