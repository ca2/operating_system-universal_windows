// Created by camilo on 2021-08-29 21:06 BRT <3ThomasBS_!!
#pragma once


#include "acme_universal_windows/node.h"
#include "apex_windows_common/node.h"


namespace apex_universal_windows
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS node :
      virtual public ::acme_universal_windows::node,
      virtual public ::apex_windows_common::node
   {
   public:


      ::particle_pointer           m_pClearApplicationDataHandler;

      class ::time m_timeLastConnectivityCheck;
      class ::time m_timeLastInternetCheck;
      bool m_bIp4Connectivity;
      bool m_bIp6Connectivity;
      bool m_bHasInternetIp4;
      bool m_bHasInternetIp6;

      node();
      ~node() override;


      //void implement(::pointer<::platform::node> & pnode, ::pointer<::platform::system> & psystem) override;

      void node_main() override;


      string system_options_main_body() override;


      //void handle(::topic * ptopic, ::handler_context * phandlercontext) override;

      string get_command_line() override;


      void reboot() override;
      void shutdown(bool bPowerOff) override;

      void terminate_processes_by_title(const ::scoped_string & scopedstrName) override;
      ::process_identifier_array module_path_processes_identifiers(const ::scoped_string & scopedstrName) override;
      ::process_identifier_array title_processes_identifiers(const ::scoped_string & scopedstrName) override;
      ::process_identifier_array processes_identifiers() override;
      ::file::path process_identifier_module_path(::process_identifier processidentifier) override;


      ::process_identifier current_process_identifier() override;


      ::payload connection_settings_get_auto_detect() override;
      ::payload connection_settings_get_auto_config_url() override;


      void local_machine_set_run(const ::scoped_string & scopedstrKey, const ::file::path & pathExecutable, const ::scoped_string & scopedstrArguments, bool bSet) override;
      void local_machine_set_run_once(const ::scoped_string & scopedstrKey, const ::file::path & pathExecutable, const ::scoped_string & scopedstrArguments, bool bSet) override;
      void current_user_set_run(const ::scoped_string & scopedstrKey, const ::file::path & pathExecutable, const ::scoped_string & scopedstrArguments, bool bSet) override;
      void current_user_set_run_once(const ::scoped_string & scopedstrKey, const ::file::path & pathExecutable, const ::scoped_string & scopedstrArguments, bool bSet) override;
      void defer_register_ca2_plugin_for_mozilla() override;

      void file_extension_get_open_with_list_keys(string_array & straKey, const ::scoped_string & scopedstrExtension) override;
      void file_extension_get_open_with_list_commands(string_array & straCommand, const ::scoped_string & scopedstrExtension) override;

      void file_association_set_default_icon(const ::scoped_string & scopedstrExtension, const ::scoped_string & scopedstrExtensionNamingClass, const ::scoped_string & scopedstrIconPath) override;
      void file_association_set_shell_open_command(const ::scoped_string & scopedstrExtension, const ::scoped_string & scopedstrExtensionNamingClass, const ::scoped_string & scopedstrCommand, const ::scoped_string & scopedstrParam) override;
      void file_association_get_shell_open_command(const ::scoped_string & scopedstrExtension, string & strExtensionNamingClass, string & strCommand, string & strParam) override;


      bool open_in_ie(const ::scoped_string & scopedstr);


      //void file_open(::file::path path, const ::scoped_string & scopedstrParams = "", const ::scoped_string & scopedstrFolder = "") override;

      void file_open(const ::file::path & path, const ::scoped_string & scopedstrParams = "", const ::file::path & pathFolder = "") override;


      //void browse_file_open(::property_set & set) override;
      //void browse_file_save(::property_set & set) override;
      //void browse_folder(::property_set & set) override;
      //void browse_file_or_folder(::property_set & set) override;

      void enable_service() override;
      void disable_service() override;

      void start_service() override;
      void stop_service() override;

      bool _getCredentialsForService(const ::scoped_string & scopedstrService, WCHAR * szUsername, WCHAR * szPassword);

      void enable_service(const ::scoped_string & scopedstrServiceName, const ::scoped_string & scopedstrDisplayName, const ::scoped_string & scopedstrCommand, const ::scoped_string & scopedstrUser = "", const ::scoped_string & scopedstrPass = "") override;
      void disable_service(const ::scoped_string & scopedstrServiceName) override;

      void start_service(const ::scoped_string & scopedstrServiceName) override;
      void stop_service(const ::scoped_string & scopedstrServiceName) override;

      string calc_service_name();


      //::pointer < ::file::link > resolve_link(::file::path & path, const ::scoped_string & scopedstrSource, string * pstrDirectory = nullptr, string * pstrParams = nullptr, string * pstrIconLocation = nullptr, int * piIcon = nullptr) override;

      //::pointer < ::file::link > resolve_link(const ::file::path & path, ::file::e_link elink = ::file::e_link_all) override;

      //bool resolve_lnk_link(::file::path & path, const ::scoped_string & scopedstrSource, string * pstrDirectory = nullptr, string * pstrParams = nullptr);

      virtual ::pointer < ::file::link > resolve_lnk_link(const ::file::path & path, ::file::e_link elink = ::file::e_link_all);

      void raise_exception(unsigned int dwExceptionCode, unsigned int dwExceptionFlags);

      bool is_remote_session() override;

      // void set_file_status(const ::file::path & path, const ::file::file_status & status) override;

      bool is_alias(const ::file::path & path) override;

      void initialize_wallpaper_fileset(::file::set * pset, bool bAddSearch) override;

      void get_default_browser(string & strId, ::file::path & path, string & strParam) override;

      void register_user_auto_start(const ::scoped_string & scopedstrId, const ::scoped_string & scopedstrCommand, const ::scoped_string & scopedstrArguments, bool bRegister);

      bool is_user_auto_start(const ::scoped_string & scopedstrId);

      ::file::path get_app_path(const ::scoped_string & scopedstrApp) override;

      void set_default_browser() override;

      void set_file_extension_mime_type(string_array & straExtension, string_array & straMimeType) override;

      void list_process(::file::path_array_base & patha, ::process_identifier_array & uaPid) override;

      //virtual icon_pointer load_icon(const ::payload & payloadFile) override;

      void open_url_link_at_system_browser(const ::scoped_string & scopedstrUrl, const ::scoped_string & scopedstrProfile) override;

      virtual void _has_ip_connectivity(bool & bIp4, bool & bIp6);

      virtual void _defer_has_ip_connectivity(bool & bIp4, bool & bIp6);

      virtual bool _has_ip4_connectivity();

      virtual bool _has_ip6_connectivity();

      virtual void _can_connect_to_host(const ::scoped_string & scopedstr, bool & bUsingIp4, bool & bUsingIp6);

      virtual bool _can_connect_to_host_using_ip4(const ::scoped_string & scopedstr);

      virtual bool _can_connect_to_host_using_ip6(const ::scoped_string & scopedstr);

      virtual void _has_internet(bool & bIp4, bool & bIp6);

      virtual void _defer_has_internet(bool & bIp4, bool & bIp6);

      virtual bool _has_ip4_internet();

      virtual bool _has_ip6_internet();


      bool has_ip4_internet() override;

      bool has_ip6_internet() override;



   };


} // namespace apex_universal_windows



