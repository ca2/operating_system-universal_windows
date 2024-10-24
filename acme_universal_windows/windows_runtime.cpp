// Created by camilo on 2021-08-31 11:56 BRT <3ThomasBS__!!
// Created by camilo on 2021-08-30 16:53 BRT <3ThomasBS__!!
#include "framework.h"
#include "file_context.h"
#include "node.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/platform/application.h"
#include "acme/platform/application.h"
#include "acme/prototype/prototype/memory.h"
#include "acme/_operating_system.h"
#include "acme/operating_system/universal_windows/parallelization_winrt.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include "_winrt_core.h"
#include "_winrt_stream.h"
#include "_winrt_system.h"
#include "_winrt_storage.h"
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.System.Threading.h>
#include <winrt/Windows.Devices.Geolocation.h>
#include <winrt/Windows.Storage.FileProperties.h>


CLASS_DECL_ACME string consume_token(::string & str, const ::string_array & straSeparator);


::winrt::Windows::UI::Core::CoreDispatcherPriority windows_runtime_UICoreDispatcherPriority(enum_priority epriority)
{

   if (epriority <= e_priority_idle)
   {

      return ::winrt::Windows::UI::Core::CoreDispatcherPriority::Idle;

   }
   else if (epriority <= e_priority_below_normal)
   {

      return ::winrt::Windows::UI::Core::CoreDispatcherPriority::Low;

   }
   else if (epriority >= e_priority_above_normal)
   {

      return ::winrt::Windows::UI::Core::CoreDispatcherPriority::High;

   }
   else if (epriority >= e_priority_above_normal)
   {

      return ::winrt::Windows::UI::Core::CoreDispatcherPriority::High;

   }
   else
   {

      return ::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal;

   }

}


// Converts a Win32 thread priority to WinRT format.
::winrt::Windows::System::Threading::WorkItemPriority windows_runtime_WorkItemPriority(enum_priority epriority)
{

   if (epriority <= e_priority_below_normal)
   {

      return ::winrt::Windows::System::Threading::WorkItemPriority::Low;

   }
   else if (epriority <= e_priority_above_normal)
   {

      return ::winrt::Windows::System::Threading::WorkItemPriority::High;

   }
   else
   {

      return ::winrt::Windows::System::Threading::WorkItemPriority::Normal;

   }

}


CLASS_DECL_EXPORT void main_branch(::matter * pobjectTask, enum_priority epriority)
{

   windows_runtime_async([pobjectTask]()
      {

         pobjectTask->call_run();

      }, epriority);

}


namespace acme_universal_windows
{


   ::winrt::Windows::Storage::StorageFolder node::windows_runtime_known_folder(::particle * pparticle, string & strRelative, string & strPrefix)
   {

      if (strRelative.case_insensitive_begins_eat("image://")
         || strRelative.case_insensitive_begins_eat("image:/")
         || strRelative.case_insensitive_begins_eat("image:"))
      {

         strPrefix = "image://";

         return ::winrt::Windows::Storage::KnownFolders::PicturesLibrary();

      }
      else if (strRelative.case_insensitive_begins_eat("music://")
         || strRelative.case_insensitive_begins_eat("music:/")
         || strRelative.case_insensitive_begins_eat("music:"))
      {

         strPrefix = "music://";

         return ::winrt::Windows::Storage::KnownFolders::MusicLibrary();

      }
      else if (strRelative.case_insensitive_begins_eat("video://")
         || strRelative.case_insensitive_begins_eat("video:/")
         || strRelative.case_insensitive_begins_eat("video:"))
      {

         strPrefix = "video://";

         return ::winrt::Windows::Storage::KnownFolders::VideosLibrary();

      }
      else if (strRelative.case_insensitive_begins_eat("document://")
         || strRelative.case_insensitive_begins_eat("document:/")
         || strRelative.case_insensitive_begins_eat("document:"))
      {

         strPrefix = "document://";

         return ::winrt::Windows::Storage::KnownFolders::DocumentsLibrary();

      }
      else if (strRelative.case_insensitive_begins_eat("localfolder://")
      || strRelative.case_insensitive_begins_eat("localfolder:/")
         || strRelative.case_insensitive_begins_eat("localfolder:"))
      {

         strPrefix = "localfolder://";

         return ::winrt::Windows::Storage::ApplicationData::Current().LocalFolder();

      }
      else if (strRelative.case_insensitive_begins_eat("dropbox://")
         || strRelative.case_insensitive_begins_eat("dropbox:/")
         || strRelative.case_insensitive_begins_eat("dropbox:"))
      {

         string strHome = getenv("USERPROFILE");

         if (platform()->m_bConsole)
         {

            ::file::path path(strHome);

            path /= "dropbox.txt";

            auto strPath = file()->safe_get_string(path);

            if (strPath.has_char())
            {

               if (acmedirectory()->is(strPath))
               {

                  return windows_runtime_folder(pparticle, strPath, false);

               }

            }

         }

         strPrefix = "document://";

         return ::winrt::Windows::Storage::KnownFolders::DocumentsLibrary();

      }
      //else if (str::case_insensitive_begins_eat(strRelative, ::dir::sys_temp()))
      //{

      //   strPrefix = ::dir::sys_temp();

      //   return ::winrt::Windows::Storage::ApplicationData::Current.TemporaryFolder();

      //}
      else if (strRelative.case_insensitive_begins_eat(string(::winrt::Windows::Storage::ApplicationData::Current().LocalFolder().Path().begin())))
      {

         strPrefix = ::winrt::Windows::Storage::ApplicationData::Current().LocalFolder().Path().begin();

         strRelative.begins_eat("\\");

         strRelative.begins_eat("/");

         return ::winrt::Windows::Storage::ApplicationData::Current().LocalFolder();

      }
      else
      {

         return nullptr;

      }

   }


   ::winrt::Windows::Storage::StorageFolder node::_windows_runtime_folder(::particle * pparticle, string & strRelative, string & strPrefix)
   {

      auto pfolder = windows_runtime_known_folder(pparticle, strRelative, strPrefix);

      if (pfolder)
      {

         return pfolder;

      }

      auto path = pparticle->m_papplication->defer_process_path(strRelative);

      if (path.is_empty())
      {

         return nullptr;

      }

      ::file::path pathFolder;

      string strName;

      bool bDir = false;

      if (pparticle->acmedirectory()->::acme_directory::_file_type(path) == ::file::e_type_existent_folder)
      {

         pathFolder = path;

      }
      else
      {

         pathFolder = path.folder();

         strName = path.name();

      }

      if (pathFolder.is_empty())
      {

         auto folder = ::winrt::Windows::ApplicationModel::Package::Current().InstalledLocation();

         return folder;

      }

      //bDir = false;

      //if (!pobject->acmedirectory()->_is(bDir, pathFolder) || !bDir)
      //{

      //   return nullptr;

      //}

      if (!is_directory(pathFolder))
      {

         return nullptr;

      }

      auto hstrRelative = as_hstring(pathFolder.windows_path());

      try
      {

         auto item = ::winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(hstrRelative).get();

         if (!item)
         {

            return nullptr;

         }

         strPrefix = pathFolder;

         strRelative = strName;

         return item;


      }
      catch (const winrt::hresult_error & e)
      {

         output_debug_string("winrt::hresult_error = " + ::as_string((i32)e.code()) + "\n");

      }
      catch (...)
      {


      }

      return nullptr;

   }


   ::winrt::Windows::Storage::StorageFolder node::windows_runtime_folder(::particle * pparticle, string & strRelative, string & strPrefix, bool bDeferCreateFolder)
   {

      auto folder = _windows_runtime_folder(pparticle, strRelative, strPrefix);

      if (folder)
      {

         strRelative.trim_left("\\/");

         string strRelativeHere(strRelative);

         string strPrefixBase(strPrefix);

         try
         {

            string strPrefixMore;

            while (true)
            {

               string strCurrentFolder = consume_token(strRelativeHere, { "\\", "/" });

               if (strCurrentFolder.is_empty())
               {

                  if (strRelativeHere.is_empty())
                  {

                     break;

                  }

                  strCurrentFolder = strRelativeHere;

                  strRelativeHere.empty();

               }

               auto hstrName = as_hstring(strCurrentFolder);

               auto item = folder.TryGetItemAsync(hstrName).get();

               if (!item)
               {

                  if (bDeferCreateFolder)
                  {

                     item = folder.CreateFolderAsync(hstrName).get();

                     if (!item)
                     {

                        break;

                     }

                  }
                  else
                  {

                     break;

                  }

               }

               if (!item.IsOfType(::winrt::Windows::Storage::StorageItemTypes::Folder))
               {

                  break;

               }

               item.as(folder);

               if (strPrefixMore.has_char())
               {

                  strPrefixMore += "/" + strCurrentFolder;

               }
               else
               {

                  strPrefixMore = strCurrentFolder;

               }

               strRelative = strRelativeHere;

               strPrefix = ::file::path(strPrefixBase) / ::file::path(strPrefixMore);

            }

         }
         catch (...)
         {

            folder = nullptr;

         }

      }

      return folder;

   }


   ::winrt::Windows::Storage::StorageFolder node::windows_runtime_folder(::particle * pparticle, const ::file::path & path, bool bDeferCreateFolder)
   {

      try
      {

         string strRelative = path;

         string strPrefix;

         auto folder = windows_runtime_folder(pparticle, strRelative, strPrefix, bDeferCreateFolder);

         if (folder == nullptr)
         {

            return nullptr;

         }

         if (strRelative.has_char())
         {

            return nullptr;

         }

         //string_array straItems;

         //string_array straSeparator;

         //straSeparator.add("/");

         //straSeparator.add("\\");

         //straItems.add_smallest_tokens(strRelative, straSeparator, false);

         //for (auto & strItem : straItems)
         //{

         //   auto hstrItem = as_hstring(strItem);

         //   auto item = folder.TryGetItemAsync(hstrItem).get();

         //   if (!item)
         //   {

         //      return nullptr;

         //   }

         //   if (!item.IsOfType(winrt::Windows::Storage::StorageItemTypes::Folder))
         //   {

         //      return nullptr;

         //   }

         //   folder = item.as<::winrt::Windows::Storage::StorageFolder>();

         //   if (!folder)
         //   {

         //      return nullptr;

         //   }

         //}

         return folder;

      }
      catch (...)
      {

      }

      return nullptr;

   }



   //CLASS_DECL_ACME::winrt::Windows::Storage::StorageFolder ^ winrt_folder(string & strPath, string & strPrefix)
   //{
   //
   //   ::winrt::Windows::Storage::StorageFolder ^ folder = winrt_folder1(strPath, strPrefix);
   //
   //   if (folder != nullptr)
   //   {
   //
   //      return folder;
   //
   //   }
   //
   //
   //   ::file::path_array patha;
   //
   //   ::file::path path(strPath);
   //
   //   patha = path.ascendants_path();
   //
   //   for (auto & pathFolder : patha)
   //   {
   //
   //      ::winrt::Windows::Storage::StorageFolder ^ folder = ::winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(pathFolder).get();
   //
   //      if (folder != nullptr)
   //      {
   //
   //         strPrefix = pathFolder;
   //
   //         return folder;
   //
   //      }
   //
   //   }
   //
   //   return nullptr;
   //
   //}


   //CLASS_DECL_ACME::winrt::Windows::Storage::StorageFolder ^ winrt_get_folder(const ::string & strFolder, string & strPrefix)
   //{
   //
   //   string strPath = strFolder;
   //
   //   ::winrt::Windows::Storage::StorageFolder ^ folder = winrt_folder(strPath, strPrefix);
   //
   //   if (folder == nullptr)
   //   {
   //
   //      return nullptr;
   //
   //   }
   //
   //   if (strPath.is_empty())
   //   {
   //
   //      return folder;
   //
   //   }
   //   else
   //   {
   //
   //      strPath.replace("/", "\\");
   //
   //      return wait(folder->GetFolderAsync(strPath));
   //
   //   }
   //
   //}
   //

   //CLASS_DECL_ACME::winrt::Windows::Storage::StorageFolder ^ winrt_get_folder(const ::string & strFolder)
   //{
   //
   //   string strPrefix;
   //
   //   return winrt_get_folder(strFolder, strPrefix);
   //
   //}
   //
   //
   //CLASS_DECL_ACME::winrt::Windows::Storage::StorageFolder ^ winrt_get_folder(const ::string & strFolder, string & strPrefix, string & strRelative)
   //{
   //
   //   string strPath = strFolder;
   //
   //   ::winrt::Windows::Storage::StorageFolder ^ folder = winrt_folder(strPath, strPrefix);
   //
   //   if (folder == nullptr)
   //   {
   //
   //      return nullptr;
   //
   //   }
   //
   //   strRelative = strFolder;
   //
   //   strPrefix.replace("/", "\\");
   //
   //   strRelative.replace("/", "\\");
   //
   //   strPrefix.trim_right("/\\");
   //
   //   strRelative.trim_right("/\\");
   //
   //   strRelative.case_insensitive_begins_eat(strPrefix);
   //
   //   strRelative.trim_left("/\\");
   //
   //   return folder;
   //
   //}
   //


   //bool windows_runtime_is_folder(const wchar_t * pwszPath)
   //{
   //
   //   ::u32 dwLastError = ::GetLastError();
   //
   //   string strPrefix;
   //
   //   {
   //
   //      string strRelative = path1;
   //
   //      auto folderBase = winrt_folder(strRelative, strPrefix);
   //
   //      if (folderBase != nullptr)
   //      {
   //
   //         strRelative.replace("/", "\\");
   //
   //         strPrefix.replace("/", "\\");
   //
   //         strRelative.case_insensitive_begins_eat(strPrefix);
   //
   //         strRelative.trim("/\\");
   //
   //         //strPrefix.trim_right("/\\");
   //
   //         try
   //         {
   //
   //            auto folder = folderBase->GetFolderAsync(strRelative);
   //
   //            if (folder != nullptr)
   //            {
   //
   //               return true;
   //
   //            }
   //
   //         }
   //         catch (...)
   //         {
   //
   //         }
   //
   //      }
   //
   //   }
   //
   //   return false;
   //
   //
   //
   //}
   //

   //::winrt::Windows::Storage::StorageFolder windows_runtime_folder(const ::string & strPath)
   //{
   //
   //
   //   ::winrt::Windows::Storage::StorageFolder folder(nullptr);
   //
   //   string strPrefix;
   //
   //   string str = strPath;
   //
   //   try
   //   {
   //
   //      if (string(psz).case_insensitive_order("image://") == 0)
   //      {
   //
   //         strPrefix = "image://";
   //
   //         try
   //         {
   //
   //            folder = ::winrt::Windows::Storage::KnownFolders::PicturesLibrary;
   //
   //         }
   //         catch (...)
   //         {
   //
   //            folder = nullptr;
   //
   //         }
   //
   //      }
   //      else if (string(psz).case_insensitive_order("music://") == 0)
   //      {
   //
   //         strPrefix = "music://";
   //
   //         try
   //         {
   //
   //            folder = ::winrt::Windows::Storage::KnownFolders::MusicLibrary;
   //
   //         }
   //         catch (...)
   //         {
   //
   //            folder = nullptr;
   //
   //         }
   //
   //      }
   //      else if (string(psz).case_insensitive_order("video://") == 0)
   //      {
   //
   //         strPrefix = "video://";
   //
   //         try
   //         {
   //
   //            folder = ::winrt::Windows::Storage::KnownFolders::VideosLibrary;
   //
   //         }
   //         catch (...)
   //         {
   //
   //            folder = nullptr;
   //
   //         }
   //
   //      }
   //      else if (string(psz).case_insensitive_order("document://") == 0)
   //      {
   //
   //         strPrefix = "document://";
   //
   //         try
   //         {
   //
   //            folder = ::winrt::Windows::Storage::KnownFolders::DocumentsLibrary;
   //
   //         }
   //         catch (...)
   //         {
   //
   //            folder = nullptr;
   //
   //         }
   //
   //      }
   //      else
   //      {
   //
   //         if (str.case_insensitive_begins_eat("image://"))
   //         {
   //
   //            strPrefix = "image://";
   //
   //            try
   //            {
   //
   //               folder = ::winrt::Windows::Storage::KnownFolders::PicturesLibrary;
   //
   //            }
   //            catch (...)
   //            {
   //
   //               folder = nullptr;
   //
   //            }
   //
   //         }
   //
   //         if (str.case_insensitive_begins_eat("music://"))
   //         {
   //
   //            strPrefix = "music://";
   //
   //            try
   //            {
   //
   //               folder = ::winrt::Windows::Storage::KnownFolders::MusicLibrary;
   //
   //            }
   //            catch (...)
   //            {
   //
   //               folder = nullptr;
   //
   //            }
   //
   //         }
   //
   //         if (str.case_insensitive_begins_eat("video://"))
   //         {
   //
   //            strPrefix = "video://";
   //
   //            try
   //            {
   //
   //               folder = ::winrt::Windows::Storage::KnownFolders::VideosLibrary;
   //
   //            }
   //            catch (...)
   //            {
   //
   //               folder = nullptr;
   //
   //            }
   //
   //         }
   //
   //         if (str.case_insensitive_begins_eat("document://"))
   //         {
   //
   //            strPrefix = "document://";
   //
   //            try
   //            {
   //
   //               folder = ::winrt::Windows::Storage::KnownFolders::DocumentsLibrary;
   //
   //            }
   //            catch (...)
   //            {
   //
   //               folder = nullptr;
   //
   //            }
   //
   //         }
   //
   //         if (strPrefix.has_char())
   //         {
   //
   //            string_array stra;
   //
   //            stra.explode("/", str);
   //
   //            string str;
   //
   //            while (stra.get_count() > 0)
   //            {
   //
   //               str = stra[0];
   //
   //               if (str.has_char())
   //               {
   //
   //                  folder = wait(folder->GetFolderAsync(str));
   //
   //                  strPrefix += str + "/";
   //
   //               }
   //
   //               stra.erase_at(0);
   //
   //            }
   //
   //         }
   //         else
   //         {
   //
   //            folder = ::winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(str).get();
   //
   //            strPrefix = str + "/";
   //
   //         }
   //
   //      }
   //
   //   }
   //   catch (...)
   //   {
   //
   //      return;
   //
   //   }
   //
   //   if (folder == nullptr)
   //   {
   //
   //      return;
   //
   //   }
   //
   //   string strPath = string(begin(folder->Path));
   //
   //   auto a = folder->GetItemsAsync().get();
   //
   //   for (u32 u = 0; u < a->Size; u++)
   //   {
   //
   //      string strPath = string(begin(a->GetAt(u)->Path));
   //
   //      string str = path;
   //
   //      stra.add(path);
   //
   //   }
   //
   //
   //}
   //
   //
   //bool windows_runtime_ls_dir(wchar_t *** ppwszPath, int * piCount, const wchar_t * pwszFolder)
   //{
   //
   //
   //
   //
   //}
   //
   //
   //bool windows_runtime_ls_file(wchar_t *** ppwszPath, int * piCount, const wchar_t * pwszFolder)
   //{
   //
   //   ::winrt::Windows::Storage::StorageFolder ^ folder = wait(::winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(string(psz)));
   //
   //   ::winrt::Windows::Foundation::Collections::IVectorView < ::winrt::Windows::Storage::StorageFolder ^ > ^ a = wait(folder->GetFoldersAsync());
   //
   //   for (u32 u = 0; u < a->Size; u++)
   //   {
   //      stra.add(begin(a->GetAt(u)->Path));
   //   }
   //
   //}



   //::u32 system_main(::apex::system * psystem)
   //{
   //
   //   try
   //   {
   //
   //      psystem->m_bReady = true;
   //
   //      psystem->on_run();
   //
   //      if(psystem->m_error.get_exit_code() != 0)
   //      {
   //
   //         ::output_debug_string(L"application::main on_run termination failure");
   //
   //      }
   //
   //      //if(psystem->is_system())
   //      //{
   //
   //      //   system()->set_finish();
   //
   //      //}
   //
   //      try
   //      {
   //
   //         psystem->term_thread();
   //
   //      }
   //      catch(...)
   //      {
   //
   //         psystem->m_error.set_if_not_set(-1);
   //
   //      }
   //
   //   }
   //   catch(::exit_exception &)
   //   {
   //
   //      //system()->set_finish();
   //
   //   }
   //
   //   return 0;
   //
   //}


   // namespace user
   // {

   //    /*::color::color g_colorSystemAppBackground;

   //    CLASS_DECL_APEX color32_t set_system_app_background_color()

   //    CLASS_DECL_APEX color32_t get_system_app_background_color()
   //    {

   //       auto color = System->get_session()->m_frameworkview->m_puisettings->GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

   //       auto r = color.R;

   //       auto g = color.G;

   //       auto b = color.B;

   //       return argb(255, r, g, b);

   //    }*/

   //    //CLASS_DECL_APEX double get_system_app_luminance()
   //    //{

   //    //   auto color = System->get_session()->m_frameworkview->m_puisettings->GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

   //    //   double r = color.R;

   //    //   double g = color.G;

   //    //   double b = color.B;

   //    //   return (r + g + b) / (255.0 * 3.0);

   //    //}


   //    //CLASS_DECL_APEX void os_update_colors()
   //    //{

   //    //   // App Background Color
   //    //   {


   //    //      auto color = System->get_session()->m_frameworkview->m_puisettings->GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

   //    //      auto r = color.R;

   //    //      auto g = color.G;

   //    //      auto b = color.B;

   //    //      set_system_app_background_color(::color::color(r, g, b));

   //    //   }


   //    //   // Luminance
   //    //   {


   //    //      auto color = System->get_session()->m_frameworkview->m_puisettings->GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

   //    //      double r = color.R;

   //    //      double g = color.G;

   //    //      double b = color.B;

   //    //      set_system_app_luminance((r + g + b) / (255.0 * 3.0));

   //    //   }

   //    //}

   //    CLASS_DECL_APEX void os_update_dark_mode()
   //    {

   //       double dLuminance = get_system_app_luminance();

   //       bool bDarkMode = dLuminance < 0.5;

   //       set_system_dark_mode(bDarkMode);

   //       set_app_dark_mode(bDarkMode);

   //    }


   // } // namespace user





//
//namespace acme_universal_window
//{
//

   ::winrt::Windows::Storage::StorageFile node::windows_runtime_file(::particle * pparticle, const char * lpcszFileName, ::u32 dwDesiredAcces, ::u32 dwShareMode, ::u32 dwCreationDisposition, ::u32 dwFlagsAndAttributes)
   {

      /*
      CREATE_ALWAYS
      2
      Creates a ___new file, always.
      If the specified file exists and is writable, the function overwrites the file, the function succeeds, and last-error code is set to ERROR_ALREADY_EXISTS (183).
      If the specified file does not exist and is a valid path, a ___new file is created, the function succeeds, and the last-error code is set to zero.
      For more information, see the Remarks section of this topic.

      CREATE_NEW
      1
      Creates a ___new file, only if it does not already exist.
      If the specified file exists, the function fails and the last-error code is set to ERROR_FILE_EXISTS (80).
      If the specified file does not exist and is a valid path to a writable location, a ___new file is created.

      OPEN_ALWAYS
      4
      Opens a file, always.
      If the specified file exists, the function succeeds and the last-error code is set to ERROR_ALREADY_EXISTS (183).
      If the specified file does not exist and is a valid path to a writable location, the function creates a file and the last-error code is set to zero.

      OPEN_EXISTING
      3
      Opens a file or device, only if it exists.
      If the specified file or device does not exist, the function fails and the last-error code is set to ERROR_FILE_NOT_FOUND (2).
      For more information about devices, see the Remarks section.

      TRUNCATE_EXISTING
      5
      Opens a file and truncates it so that its size_i32 is zero bytes, only if it exists.
      If the specified file does not exist, the function fails and the last-error code is set to ERROR_FILE_NOT_FOUND (2).
      The calling process must open the file with the GENERIC_WRITE bit set as part of the dwDesiredAccess parameter.

      */

      ::winrt::Windows::Storage::StorageFile file(nullptr);

      string strRelative = lpcszFileName;

      string strPrefix;

      ::winrt::Windows::Storage::StorageFolder folder = windows_runtime_folder(pparticle, strRelative, strPrefix);

      if (folder == nullptr)
      {

         return nullptr;

      }

      auto hstrRelative = as_hstring(strRelative);

      if (dwCreationDisposition == CREATE_ALWAYS)
      {

         auto collisionOption = ::winrt::Windows::Storage::CreationCollisionOption::ReplaceExisting;

         file = folder.CreateFileAsync(hstrRelative, collisionOption).get();

      }
      else if (dwCreationDisposition == CREATE_NEW)
      {

         auto collisionOption = ::winrt::Windows::Storage::CreationCollisionOption::FailIfExists;

         file = folder.CreateFileAsync(hstrRelative, collisionOption).get();

      }
      else if (dwCreationDisposition == OPEN_ALWAYS)
      {

         auto collisionOption = ::winrt::Windows::Storage::CreationCollisionOption::OpenIfExists;

         file = folder.CreateFileAsync(hstrRelative, collisionOption).get();

      }
      else if (dwCreationDisposition == OPEN_EXISTING)
      {

         file = folder.GetFileAsync(hstrRelative).get();

      }
      else if (dwCreationDisposition == TRUNCATE_EXISTING)
      {

         file = folder.GetFileAsync(hstrRelative).get();

         auto transaction = file.OpenTransactedWriteAsync().get();

         transaction.Stream().Size(0);

      }

      return file;

   }


   bool node::windows_runtime_filetime(::particle * pparticle, ::winrt::Windows::Storage::StorageFile file, file_time * lpCreationTime, file_time * lpItemTime, file_time * lpLastWriteTime)
   {

      if (lpCreationTime != nullptr)
      {

         *lpCreationTime = (file_time &)file.DateCreated();

      }

      if (lpItemTime != nullptr || lpLastWriteTime != nullptr)
      {

         auto properties = file.GetBasicPropertiesAsync().get();

         if (lpItemTime != nullptr)
         {

            *lpItemTime = (file_time &)properties.ItemDate();

         }

         if (lpLastWriteTime != nullptr)
         {

            *lpLastWriteTime = (file_time &)properties.DateModified();

         }

      }

      return true;

   }



} // namespace acme_universal_windows



CLASS_DECL_ACME_UNIVERSAL_WINDOWS memsize windows_runtime_read_buffer(void * p, memsize s, ::winrt::Windows::Storage::Streams::IBuffer ibuffer)
{

   s = minimum(s, ibuffer.Length());

   auto reader = ::winrt::Windows::Storage::Streams::DataReader::FromBuffer(ibuffer);

   winrt::array_view < ::u8 > bytes((unsigned char *)p, ((unsigned char *)p) + s);

   reader.ReadBytes(bytes);

   return bytes.size();

}



memory windows_runtime_buffer_memory(::winrt::Windows::Storage::Streams::IBuffer ibuffer)
{

   auto reader = ::winrt::Windows::Storage::Streams::DataReader::FromBuffer(ibuffer);

   memory memory(ibuffer.Capacity());

   ::winrt::array_view < ::u8 > bytes(memory.begin(), memory.end());

   reader.ReadBytes(bytes);

   return ::transfer(memory);

}


::winrt::array_view <::u8 > windows_runtime_bytes(const void * p, memsize s)
{

   return { (::u8 *)p, ((::u8 *)p) + s };


}


::winrt::Windows::Storage::Streams::IBuffer windows_runtime_buffer(const void * p, memsize s)
{

   ::winrt::Windows::Storage::Streams::DataWriter writer;

   ::winrt::array_view < const ::u8 > bytes((::u8 *)p, ((::u8 *)p) + s);

   writer.WriteBytes(bytes);

   return writer.DetachBuffer();

}


