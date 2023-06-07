// Create on 2021-03-22 09:12 <3ThomasBS_
// Copied by camilo from operating_system-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
#include "framework.h"
#include "acme_path.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/platform/application.h"
#include "acme/platform/system.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include "_winrt_storage.h"


#include "acme/_operating_system.h"


namespace acme_universal_windows
{


   acme_path::acme_path()
   {

      m_pplatformpath = this;

   }


   acme_path::~acme_path()
   {


   }


   ::file::path acme_path::_real_path(const ::file::path & path)
   {

      wstring wstr(path);

      HANDLE hfile = INVALID_HANDLE_VALUE;

      try
      {

         if (path.case_insensitive_ends("://"))
         {

            return path;

         }
         else if (acmedirectory()->is(path))
         {

            hfile = hfile_create(path,
               GENERIC_READ,          // open for reading
               FILE_SHARE_READ,       // share for reading
               nullptr,                  // default security
               OPEN_EXISTING,         // existing file only
               FILE_ATTRIBUTE_NORMAL, // normal file
               nullptr);                 // no attr. template

         }
         else
         {

            hfile = hfile_create(path,
               FILE_LIST_DIRECTORY,          // open for reading
               FILE_SHARE_READ,       // share for reading
               nullptr,                  // default security
               OPEN_EXISTING,         // existing file only
               FILE_ATTRIBUTE_NORMAL, // normal file
               nullptr);                 // no attr. template

         }

         if (hfile == INVALID_HANDLE_VALUE)
         {

            return wstr;

         }

         DWORD dw = GetFinalPathNameByHandleW(hfile, nullptr, 0, VOLUME_NAME_DOS);

         if (dw > 0)
         {

            wstring wstr2;

            auto* pwsz = wstr2.get_buffer(dw + 1);

            dw = GetFinalPathNameByHandleW(hfile, pwsz, dw + 1, VOLUME_NAME_DOS);

            if (dw > 0)
            {

               wstr2.release_buffer();

               wstr = wstr2;

            }

         }

      }
      catch (...)
      {

      }

      ::CloseHandle(hfile);

      return wstr;

   }


   ::file::enum_type acme_path::get_type(const ::file::path & path)
   {

      string strRelative = path;

      string strPrefix;

      ::object* pobject = nullptr;

      if (acmesystem()->acmeapplication())
      {

         pobject = acmesystem()->acmeapplication();

      }
      else if (acmesystem()->acmeapplication())
      {

         pobject = acmesystem()->acmeapplication();

      }
      else
      {

         pobject = acmesystem();
      }

      auto folder = windows_runtime_folder(pobject, strRelative, strPrefix);

      if (folder)
      {

         if (strRelative.is_empty())
         {

            return ::file::e_type_folder;

         }

         auto hstrName = __hstring(strRelative);

         auto item = folder.TryGetItemAsync(hstrName).get();

         if (item)
         {

            if (item.IsOfType(::winrt::Windows::Storage::StorageItemTypes::Folder))
            {

               return ::file::e_type_folder;

            }
            else if (item.IsOfType(::winrt::Windows::Storage::StorageItemTypes::File))
            {

               return ::file::e_type_file;

            }

         }

      }

      return ::file::e_type_unknown;

   }

} // namespace acme_universal_windows





bool windows_find_is_dots(WIN32_FIND_DATAW& data)
{

   if (data.cFileName[0] == L'.')
   {

      if (data.cFileName[1] == L'\0' ||
         (data.cFileName[1] == L'.' &&
            data.cFileName[2] == L'\0'))
      {

         return true;

      }

   }

   return false;

}

