#pragma once


#include "acme/filesystem/filesystem/file_system.h"


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS file_system:
      virtual public ::file_system
   {
   public:


      file_system();
      ~file_system() override;


      void init_system() override;


      //void update_module_path() override;


   };


} // namespace acme_universal_windows



