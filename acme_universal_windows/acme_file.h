// Created by camilo on 2021-08-09 14:19 <3ThomasBS_
// Copied by camilo from platform-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
#pragma once


namespace universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS acme_file :
      virtual public ::windows_common::acme_file
   {
   public:


      acme_file();
      ~acme_file() override;


      ::file::path executable() override;

      
      ::e_status clear_application_data() override;


   };


} // namespace universal_windows



