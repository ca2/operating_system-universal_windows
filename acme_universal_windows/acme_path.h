// Create on 2021-03-22 09:12 <3ThomasBS_
// Copied by camilo from operating_system-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
#pragma once


#include "acme_windows_common/acme_path.h"


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS acme_path :
      virtual public ::acme_windows_common::acme_path
   {
   public:


      acme_path();
      ~acme_path() override;


      ::file::path _real_path(const ::file::path & path) override;


      ::file::enum_type get_type(const ::file::path & path) override;


   };


} // namespace acme_universal_windows



