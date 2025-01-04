#include "framework.h"
#include "file_system.h"
// From acme/filesystem/file/_.cpp by camilo on 2021-08-09 
// 03:09 BRT <3ThomasBorregaardSorensen
// Copied by camilo from operating_system-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
//#include "framework.h"
//#include "file_system.h"
#include "acme/platform/node.h"


#include "acme/_operating_system.h"


#undef ___new
#include <winrt/Windows.Storage.h>


#define DEBUG_POPULATING_APPLICATION_DATA


namespace acme_universal_windows
{


   file_system::file_system()
   {

      //auto data = ::winrt::Windows::Storage::ApplicationData::Current();

      //data.ClearAsync().get();

   }


   file_system::~file_system()
   {


   }


   //::file::path file_system::module()
   //{

   //   ::file::path path;

   //   {

   //      wstring wstrPath;
   //      
   //      auto wstrPath.get_bufer((e_get_buffer, MAX_PATH * 16);

   //      if (!GetModuleFileNameW(nullptr, wstrPath, (DWORD)wstrPath.length()))
   //      {

   //         return "";

   //      }

   //      path = wstrPath.release_buffer();

   //   }

   //   return path;

   //}


   void file_system::clear_application_data()
   {

      user_post([]()
         {

            auto data = ::winrt::Windows::Storage::ApplicationData::Current();

            data.ClearAsync();

         });

   }

//
//} // namespace acme_universal_windows
//
//
//
//
//
//namespace acme_universal_windows
//{


   //file_system::file_system()
   //{

   //}


   //file_system::~file_system()
   //{

   //}


   void file_system::init_system()
   {

      //auto estatus = 
      
      ::file_system::init_system();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


} // namespace acme_universal_windows



