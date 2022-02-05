/**
	Implementation for Windows. Uses ReadDirectoryChangesW to watch for
	file system changes.

	@author James Wynn
	@date 4/15/2009

	Copyright (c) 2009 James Wynn (james@jameswynn.com)

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to uxse, cxopy, mxodify, mxerge, pxublish, dxistribute, sxublicense, and/or sxell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, topic to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.
*/
#pragma once


namespace file
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS os_watch :
      virtual public watch
   {
   public:


      atom                   m_id;

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
      virtual public watcher
   {
   public:


      os_watcher();
      ~os_watcher() override;


      //watch_id os_watcher::add_watch(const ::file::path& pathFolderParam, listener* plistenerParam, bool bRecursive)

      //virtual ::e_status     run() override;

      //virtual bool step();


   };

   ///// Implementation for Win based on StorageFolder::CreateFileQueryWithOptions.
   ///// @class os_file_watcher
   //class os_file_watcher :
   //   public file_watcher_impl
   //{
   //public:


   //   /// type for a map from atom to watch_struct pointer
   //   typedef map < atom, atom, __pointer(watch), __pointer(watch) > watch_map;


   //private:


   //   /// Map of atom to watch_struct pointers
   //   watch_map m_watchmap;
   //   /// The last watchid
   //   atom m_idLast;


   //public:


   //   os_file_watcher(::object * pobject);
   //   virtual ~os_file_watcher();


   //   /// Add a directory watch
   //   /// @exception file_not_found_exception Thrown when the requested directory does not exist
   //   virtual atom add_watch(const string & directory, listener * watcher, bool bRecursive, bool bOwn) override;

   //   /// Remove a directory watch. This is a brute force lazy search O(nlogn).
   //   void erase_watch(const string & directory);

   //   /// Remove a directory watch. This is a map lookup O(logn).
   //   void erase_watch(atom watchid);

   //   /// Return the directory name for a watch atom
   //   string watch_path(atom watchid);

   //   /// Updates the watcher. Must be called often.
   //   bool update();

   //   /// Handles the action
   //   void handle_action(action * ptopic);


   //}; // end os_file_watcher


} // namespace file_watcher



