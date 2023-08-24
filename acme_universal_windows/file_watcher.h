#pragma once


#include "acme/filesystem/watcher/watch.h"
#include "acme/filesystem/watcher/watcher.h"
#include "_winrt_storage.h"
#include <winrt/Windows.Storage.Search.h>


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS watch :
      virtual public ::file::watch
   {
   public:


      atom                   m_atom;

      string               m_strFolder;

      ::winrt::Windows::Storage::StorageFolder                    m_folder = nullptr;
      ::winrt::Windows::Storage::Search::StorageItemQueryResult   m_queryresult = nullptr;
      ::winrt::event_token                                        m_evtoken;
      bool                                                        m_bRecursive;
      bool                                                        m_bOwn;

         ///static watch_ref ^ create_watch(String ^ strDirectory, bool bRecursive);

      watch();
      ~watch() override;


      bool open(const ::file::path& pathFolder, bool bRecursive) override;


      void ContentsChanged(::winrt::Windows::Storage::Search::IStorageQueryResultBase const & r, ::winrt::Windows::Foundation::IInspectable const & object);


   };



   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS watcher :
      virtual public ::file::watcher
   {
   public:


      watcher();
      ~watcher() override;


   };


} // namespace apex_universal_windows



