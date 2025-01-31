#include "framework.h"
#include "file_watcher.h"
#include "node.h"
#include "acme/filesystem/watcher/action.h"
#include "acme/platform/application.h"
#include "acme/_operating_system.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include "windows_runtime.h"
#include "_winrt_storage.h"


namespace acme_universal_windows
{


   watch::watch()
   {


   }


   watch::~watch()
   {


   }


// forward decl
   //bool RefreshWatch(watch_ref ^ pWatch, bool _clear = false);

/// Unpacks happenings and passes them to a user defined callback.
   /*void CALLBACK WatchCallback(unsigned int dwErrorCode, unsigned int dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped)
   {
   	TCHAR szFile[MAX_PATH];
   	PFILE_NOTIFY_INFORMATION pNotify;
   	watch_struct* pWatch = (watch_struct*) lpOverlapped;
   	size_t offset = 0;

   	if(dwNumberOfBytesTransfered == 0)
   		return;

   	if (dwErrorCode == ERROR_SUCCESS)
   	{
   		do
   		{
   			pNotify = (PFILE_NOTIFY_INFORMATION) &pWatch->m_buffer[offset];
   			offset += pNotify->NextEntryOffset;

   #			if defined(UNICODE)
   			{
   				lstrcpynW(szFile, pNotify->FileName,
   					minimum(MAX_PATH, pNotify->FileNameLength / sizeof(WCHAR) + 1));
   			}
   #			else
   			{
   				int count = WideCharToMultiByte2(CP_ACP, 0, pNotify->FileName,
   					pNotify->FileNameLength / sizeof(WCHAR),
   					szFile, MAX_PATH - 1, nullptr, nullptr);
   				szFile[count] = TEXT('\0');
   			}
   #			endif

   			pWatch->m_pwatcher->handle_action(pWatch, szFile, pNotify->Action);

   		} while (pNotify->NextEntryOffset != 0);
   	}

   	if (!pWatch->m_bStop)
   	{
   		RefreshWatch(pWatch);
   	}
   }

   /// Refreshes the directory monitoring.
   bool RefreshWatch(watch_struct* pWatch, bool _clear)
   {
   	return ReadDirectoryChangesW(
   		pWatch->m_hDirectory, pWatch->m_buffer, sizeof(pWatch->m_buffer), false,
   		pWatch->m_dwNotify, nullptr, &pWatch->m_overlapped, _clear ? 0 : WatchCallback) != 0;
   }*/

/// Stops monitoring a directory.
   //void DestroyWatch(watch_ref ^ pwatch)
   //{
   //   if(pwatch != nullptr)
   //   {
   //      //delete pWatch;
   //   }
   //}
/// Starts monitoring a directory.
   bool watch::open(const ::file::path & pathFolderParam, bool bRecursive)
   {

      try
      {

         ::file::path pathFolder = m_papplication->defer_process_path(pathFolderParam);

         ::winrt::Windows::Storage::Search::QueryOptions options;

         m_bRecursive = bRecursive;

         if (m_bRecursive)
         {

            options.FolderDepth(::winrt::Windows::Storage::Search::FolderDepth::Deep);

         }
         else
         {

            options.FolderDepth(::winrt::Windows::Storage::Search::FolderDepth::Shallow);

         }

         options.IndexerOption(::winrt::Windows::Storage::Search::IndexerOption::DoNotUseIndexer);

         string strPrefix;

         string strDirectory = pathFolder;

         ::pointer < ::acme_universal_windows::node > pnode = node();

         m_folder = pnode->windows_runtime_folder(m_papplication, strDirectory, false);

         if (m_folder == nullptr)
         {

            return false;

         }

         m_queryresult = m_folder.CreateItemQuery();

         if (m_queryresult == nullptr)
         {

            return false;

         }

         m_evtoken = m_queryresult.ContentsChanged(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::Storage::Search::IStorageQueryResultBase,
                 ::winrt::Windows::Foundation::IInspectable >(this, &watch::ContentsChanged));

         return true;

      }
      catch (...)
      {

      }

      return false;

   }


   watcher::watcher()
   {

      m_bCreateWatchThread = false;

   }


   watcher::~watcher()
   {

      //watch_map::pair * ppair = m_watchmap.get_start();
      //for(; ppair != nullptr; m_watchmap.get_next(ppair))
      //{
      //   DestroyWatch(ppair->element2().w);
      //}
      //m_watchmap.erase_all();

   }


   //bool watch::open(const ::file::path& pathFolderParam, bool bRecursive)
   //{

   //   ::file::path pathFolder = get_context()->defer_process_path(pathFolderParam);

   //   if (!watch::open(pathFolderParam, bRecursive))
   //   {

   //      return false;

   //   }

   //   //watch_struct ^ pwatch = watch_struct::create_watch(m_str(directory), FILE_NOTIFY_CHANGE_CREATION | FILE_NOTIFY_CHANGE_SIZE | FILE_NOTIFY_CHANGE_FILE_NAME);
   //   watch_ref^ watchref = watch_ref::create_watch(pathFolder, bRecursive);

   //   if (watchref == nullptr)
   //   {

   //      return false;

   //   }

   //   m_watchref = watchref;

   //   return true;

   //}


   void watch::ContentsChanged(::winrt::Windows::Storage::Search::IStorageQueryResultBase const & r, ::winrt::Windows::Foundation::IInspectable const & object)
   {

      //::winrt::Windows::Storage::Search::StorageItemQueryResult^ results = (::winrt::Windows::Storage::Search::StorageItemQueryResult^) r;

      //if (results != nullptr)
      //{

      //   auto items = ::wait(results->GetItemsAsync());

      //   for (::collection::index i = 0; i < items->Size; i++)
      //   {

      //auto item = items->GetAt(i);

      ::file::action action;

      action.m_pfilewatch = this;

      action.m_pathFolder = m_pathFolder;

      //ptopic->m_ulOsAction = -1;

      //m_pwatch->handle_action(m_pwatch->id(), m_pwatch->m_strFolder,
        //    "", (::file_watcher::e_action) -1);

      //}
      handle_action(&action);


      //}


   }


} // namespace acme_universal_windows



