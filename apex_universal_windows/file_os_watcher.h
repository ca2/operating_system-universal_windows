#pragma once


#include "apex/filesystem/filesystem/file_watcher.h"


namespace apex_universal_windows
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS os_watch :
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

      os_watch();
      ~os_watch() override;


      bool open(const ::file::path& pathFolder, bool bRecursive) override;


      void ContentsChanged(::winrt::Windows::Storage::Search::IStorageQueryResultBase const & r, ::winrt::Windows::Foundation::IInspectable const & object);


   };



   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS os_watcher :
      virtual public ::file::watcher
   {
   public:


      os_watcher();
      ~os_watcher() override;


   };


} // namespace apex_universal_windows



