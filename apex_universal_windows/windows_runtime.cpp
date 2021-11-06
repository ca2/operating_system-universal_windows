// Created by camilo on 2021-08-30 16:53 BRT <3ThomasBS__!!
#include "framework.h"
#include "apex/_defer.h"
#include "acme/node/operating_system/universal_windows/parallelization_winrt.h"
#undef new
//#include <collection.h>
//#include <ppltasks.h>
//#define CLASS_DECL_APEX CLASS_DECL_IMPORT
//#include "acme/constant/_.h"
//#include "acme/constant/_constant.h"
//#include "acme/primitive/primitive/estatus.h"
//#include "acme/primitive/datetime/_.h"
//#include "acme/primitive/primitive/interlocked_count.h"
//#include "acme/primitive/primitive/eobject.h"
//#include "acme/platform/object_reference_count_debug.h"
//#include "acme/primitive/mathematics/index.h"
//#include "acme/parallelization/synchronization_result.h"
//#include "windows_runtime.h"
//#include "acme/node/operating_system/windows_common/arg_sec_attrs.h"
//#include "acme/parallelization/synchronization_object.h"
//#include "acme/parallelization/event.h"
//#include "acme/parallelization/manual_reset_event.h"
//#include "acme/node/operating_system/universal_windows/multithreading_winrt.h"
////#include <winrt/Windows.Foundation.Collections.h>




//template < typename PREDICATE >
//void windows_runtime_async(PREDICATE predicate)
//{
//
//   ::winrt::Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(
//      CoreDispatcherPriority::Normal,
//      ref new ::winrt::Windows::UI::Core::DispatchedHandler(PREDICATE));
//
//
//}
//

//
//::e_status windows_runtime_launch_uri_synchronously(const char * pszUri, const ::duration & duration)
//{
//
//   ::winrt::Windows::Foundation::Uri uri(__hstring(pszUri));
//
//   auto estatus = windows_runtime_synchronously(duration, [uri, duration]()
//   {
//
//      ::wait(::winrt::Windows::System::Launcher::LaunchUriAsync(uri), duration);
//
//   });
//
//   return estatus;
//
//}


::winrt::Windows::Storage::StorageFile windows_runtime_file(::object * pobject, const char * lpcszFileName, ::u32 dwDesiredAcces, ::u32 dwShareMode, ::u32 dwCreationDisposition, ::u32 dwFlagsAndAttributes)
{

   /*
   CREATE_ALWAYS
   2
   Creates a new file, always.
   If the specified file exists and is writable, the function overwrites the file, the function succeeds, and last-error code is set to ERROR_ALREADY_EXISTS (183).
   If the specified file does not exist and is a valid path, a new file is created, the function succeeds, and the last-error code is set to zero.
   For more information, see the Remarks section of this topic.

   CREATE_NEW
   1
   Creates a new file, only if it does not already exist.
   If the specified file exists, the function fails and the last-error code is set to ERROR_FILE_EXISTS (80).
   If the specified file does not exist and is a valid path to a writable location, a new file is created.

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

   ::winrt::Windows::Storage::StorageFolder folder = windows_runtime_folder(pobject, strRelative, strPrefix);

   if (folder == nullptr)
   {

      return nullptr;

   }

   auto hstrRelative = __hstring(strRelative);

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


bool windows_runtime_filetime(::winrt::Windows::Storage::StorageFile file, LPFILETIME lpCreationTime, LPFILETIME lpItemTime, LPFILETIME lpLastWriteTime)
{

   if (lpCreationTime != nullptr)
   {

      *lpCreationTime = (FILETIME&)file.DateCreated();

   }

   if (lpItemTime != nullptr || lpLastWriteTime != nullptr)
   {

      auto properties = file.GetBasicPropertiesAsync().get();

      if (lpItemTime != nullptr)
      {

         *lpItemTime = (FILETIME&)properties.ItemDate();

      }

      if (lpLastWriteTime != nullptr)
      {

         *lpLastWriteTime = (FILETIME&)properties.DateModified();

      }

   }

   return true;

}
