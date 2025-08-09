#pragma once


#include "acme/filesystem/filesystem/directory_context.h"


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS directory_context :
      virtual public ::directory_context
   {
   public:


      ::pointer<::acme_universal_windows::file_system>     m_pfilesystem;
      ::pointer<::acme_universal_windows::directory_system>      m_pdirectorysystem;


      directory_context();
      ~directory_context() override;


      void initialize(::particle * pparticle) override;

      void init_system() override;

      using ::directory_context::enumerate;
      // rls fetchs should set a meaningful m_iRelative value at each returned path
      bool enumerate(::file::listing_base & path) override;
      //bool ls_relative_name(::file::listing_base & path) override;


      //bool  is_impl(const ::file::path & path) override;
      bool is_inside(const ::file::path & pathFolder, const ::file::path & path);
      bool is_inside_time(const ::file::path & path);
      bool name_is(const ::file::path & path);
      bool has_subdir(const ::file::path & path);

      ::file::listing_base & root_ones(::file::listing_base & listing);
      //virtual bool mk(const ::file::path & path);
      //virtual bool rm(const ::file::path & path, bool bRecursive = true);


      ::file::path name(const ::file::path & path);

      ::file::path time() override;
      ::file::path stage() override;
      ::file::path stageapp() override;
      ::file::path netseed() override;
      //virtual ::file::path matter();

      //virtual ::file::path module() override;
      //virtual ::file::path ca2module();
      ::file::path time_square() override;
      ::file::path time_log(const ::scoped_string & scopedstrId) override;


      ::file::path trash_that_is_not_trash(const ::file::path & path) override;



      ::file::path appdata(const ::scoped_string & scopedstrAppId = "") override;
      ::file::path commonappdata_root() override;

      //virtual ::file::path usersystemappdata(const ::scoped_string & scopedstrPrefix);

      //virtual ::file::path userappdata();
      //virtual ::file::path userdata();
      //virtual ::file::path userfolder();
      //virtual ::file::path default_os_user_path_prefix();
      //virtual ::file::path default_userappdata(const string & pcszPrefix,const string & lpcszLogin );

      //virtual ::file::path default_userdata(const string & pcszPrefix,const string & lpcszLogin);

      //virtual ::file::path default_userfolder(const string & pcszPrefix,const string & lpcszLogin);

      ::file::path userquicklaunch() override;
      ::file::path userprograms() override;

      ::file::path commonprograms() override;




      ::file::path document() override;
      ::file::path desktop() override;
      ::file::path download() override;


      ::file::path music() override;
      ::file::path video() override;
      ::file::path image() override;


      ::file::path dropbox() override;
      ::file::path onedrive() override;


   };


} // namespace acme_universal_windows



