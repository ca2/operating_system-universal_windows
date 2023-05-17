// From acme/filesystem/file/_.cpp by camilo on 2021-08-09 
// 03:09 BRT <3ThomasBorregaardSørensen
// Copied by camilo from operating_system-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
#include "framework.h"
#include "acme_file.h"
#include "acme/platform/node.h"


#include "acme/_operating_system.h"


#undef new
#include <winrt/Windows.Storage.h>


#define DEBUG_POPULATING_APPLICATION_DATA


namespace acme_universal_windows
{


   acme_file::acme_file()
   {

      //auto data = ::winrt::Windows::Storage::ApplicationData::Current();
      
      //data.ClearAsync().get();

   }


   acme_file::~acme_file()
   {


   }


   ::file::path acme_file::module()
   {

      ::file::path path;

      {

         wstring wstrPath(e_get_buffer, MAX_PATH * 16);

         if (!GetModuleFileNameW(nullptr, wstrPath, (DWORD)wstrPath.length()))
         {

            return "";

         }

         path = wstrPath.release_buffer();

      }

      return path;

   }


   void acme_file::clear_application_data()
   {

      acmenode()->node_post([]()
         {

            auto data = ::winrt::Windows::Storage::ApplicationData::Current();

            data.ClearAsync();

         });

   }


} // namespace acme_universal_windows



