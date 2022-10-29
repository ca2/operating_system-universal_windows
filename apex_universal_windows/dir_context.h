#pragma once


namespace apex_universal_windows
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS dir_context :
      virtual public ::dir_context
   {
   public:


      ::pointer<file_system>     m_pfilesystem;
      ::pointer<dir_system>      m_pdirsystem;


      dir_context();
      ~dir_context() override;


      void initialize(::particle * pparticle) override;

      void init_system() override;

      using ::dir_context::enumerate;
      // rls fetchs should set a meaningful m_iRelative value at each returned path
      bool enumerate(::file::listing & path) override;
      //bool ls_relative_name(::file::listing & path) override;


      //bool  is_impl(const ::file::path & path) override;
      virtual bool  is_inside(const ::file::path & pathFolder, const ::file::path & path);
      virtual bool  is_inside_time(const ::file::path & path);
      virtual bool  name_is(const ::file::path & path);
      virtual bool  has_subdir(const ::file::path & path);

      virtual ::file::listing & root_ones(::file::listing & listing);
      //virtual bool mk(const ::file::path & path);
      //virtual bool rm(const ::file::path & path, bool bRecursive = true);


      virtual ::file::path name(const ::file::path & path);

      virtual ::file::path time() override;
      virtual ::file::path stage() override;
      virtual ::file::path stageapp() override;
      virtual ::file::path netseed() override;
      //virtual ::file::path matter();

      virtual ::file::path module() override;
      //virtual ::file::path ca2module();
      virtual ::file::path time_square() override;
      virtual ::file::path time_log(const ::string & strId) override;


      virtual ::file::path trash_that_is_not_trash(const ::file::path & path) override;



      virtual ::file::path appdata(const ::string & strAppId = "") override;
      virtual ::file::path commonappdata_root() override;

      //virtual ::file::path usersystemappdata(const ::string & pcszPrefix);

      //virtual ::file::path userappdata();
      //virtual ::file::path userdata();
      //virtual ::file::path userfolder();
      //virtual ::file::path default_os_user_path_prefix();
      //virtual ::file::path default_userappdata(const string & pcszPrefix,const string & lpcszLogin );

      //virtual ::file::path default_userdata(const string & pcszPrefix,const string & lpcszLogin);

      //virtual ::file::path default_userfolder(const string & pcszPrefix,const string & lpcszLogin);

      virtual ::file::path userquicklaunch() override;
      virtual ::file::path userprograms() override;

      virtual ::file::path commonprograms() override;




      virtual ::file::path document() override;
      virtual ::file::path desktop() override;
      virtual ::file::path download() override;


      virtual ::file::path music() override;
      virtual ::file::path video() override;
      virtual ::file::path image() override;


      virtual ::file::path onedrive() override;


   };


} // namespace apex_universal_windows



