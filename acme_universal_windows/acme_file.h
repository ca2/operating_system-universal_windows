// Created by camilo on 2021-08-09 14:19 <3ThomasBS_
// Copied by camilo from operating_system-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
#pragma once


#include "acme_windows_common/file_system.h"


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS file_system :
      virtual public ::acme_windows_common::file_system
   {
   public:


      file_system();
      ~file_system() override;


      //::file::path module() override;

      
      void clear_application_data() override;


   };


} // namespace acme_universal_windows



