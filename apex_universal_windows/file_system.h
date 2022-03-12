#pragma once


namespace universal_windows
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS file_system:
      virtual public ::file_system
   {
   public:


      file_system();
      ~file_system() override;


      void init_system() override;


      //void update_module_path() override;


   };


} // namespace universal_windows



