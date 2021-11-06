// Create on 2021-03-22 09:12 <3ThomasBS_
// Copied by camilo from platform-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
#pragma once


namespace universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS acme_path :
      virtual public ::windows_common::acme_path
   {
   public:


      acme_path();
      ~acme_path() override;




      //virtual bool __win_find_is_dots(WIN32_FIND_DATAW & data);


      ::file::path _final(const char * path) override;


   };


} // namespace universal_windows



