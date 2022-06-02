// From acme/filesystem/file/_.cpp by camilo on 2021-08-09 
// 03:09 BRT <3ThomasBorregaardSørensen
// Copied by camilo from operating-system-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
#include "framework.h"
#include "acme/operating_system.h"
#include <stdio.h>


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

         wstring wstrPath(get_buffer, MAX_PATH * 16);

         if (!GetModuleFileNameW(nullptr, wstrPath, (DWORD)wstrPath.get_length()))
         {

            return "";

         }

         path = wstrPath.release_string_buffer();

      }

      return path;

   }


   void acme_file::clear_application_data()
   {

      m_psystem->m_pnode->node_post([]()
         {

            auto data = ::winrt::Windows::Storage::ApplicationData::Current();

            data.ClearAsync();

         });

   }


} // namespace acme_universal_windows



