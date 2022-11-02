// Adapted for composition by camilo on 2021-09-01 22:17 <3ThomasBS__!
#include "framework.h"
#include "native_buffer.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include "_winrt_storage.h"
#include "_winrt_stream.h"
#include "acme_windows_common/hresult_exception.h"


namespace acme_universal_windows
{


   native_buffer::native_buffer(::winrt::Windows::Storage::StorageFile file, const ::file::e_open & eopen)
   {

      m_bCloseOnDelete = true;

      open(file, eopen);

   }


   native_buffer::~native_buffer()
   {

      close();

   }


   void native_buffer::open(const ::file::path & path, const ::file::e_open & eopenParam)
   {

      ::file::e_open eopen(eopenParam);

      m_eopen = eopen;
      m_file = nullptr;
      m_folder = nullptr;

      ASSERT_VALID(this);
      ASSERT(__is_valid_string(path));
      ASSERT(!(eopen & ::file::e_open_text));   // text mode not supported

      // native_buffer objects are always binary and Createnative_buffer does not need flag
      eopen -= ::file::e_open_binary;

      if ((eopen & ::file::e_open_defer_create_directory) && (eopen & ::file::e_open_write))
      {

acmedirectory()create(path.folder());

      }

      string strPath = path;

      string strPrefix;

      auto folder = windows_runtime_folder(this, strPath, strPrefix);

      if (folder == nullptr)
      {

         set_nok();

         m_estatus = error_not_found;

         if (eopen & ::file::e_open_no_exception_on_open)
         {

            return;

         }

         auto dwLastError = -1;

         auto estatus = ::windows::last_error_status(dwLastError);

         auto errorcode = __last_error(dwLastError);

         throw ::file::exception(estatus, errorcode, m_path, "!windows_runtime_folder", m_eopen);

      }

      return open(folder, strPath, eopen);

   }
   
   
   //void native_buffer::put_byte_back(::byte byte)
   //{

   //   m_memoryBuffer.write(strUtf8.c_str(), strUtf8.get_length());

   //}


   void native_buffer::open(::winrt::Windows::Storage::StorageFolder folder, const ::file::path & pathFileArgument, const ::file::e_open & efileopenParam)
   {

      set_nok();

      m_estatus = error_failed;

      ::file::e_open eopen(efileopenParam);

      ::file::path pathFile(pathFileArgument);

      pathFile.trim("\\/");

      string strPrefix = folder.Path().begin();

      ::file::path path;

      if (strPrefix.has_char())
      {

         path = strPrefix / pathFile;

      }
      else
      {

         path = pathFile;

      }

      string strName = path.name();

      ::file::path pathFolder = path.folder();

      string strRelative = pathFolder;

      ::str().begins_eat_ci(strRelative, strPrefix);

      strRelative.trim("\\/");

      if (strRelative.is_empty())
      {

         m_folder = folder;

      }
      else
      {

         defer_co_initialize_ex(true);

         string_array straItems;

         string_array straSeparator;

         straSeparator.add("/");

         straSeparator.add("\\");

         straItems.add_smallest_tokens(strRelative, straSeparator, false);

         for (auto & strItem : straItems)
         {

            auto hstrItem = __hstring(strItem);

            auto item = folder.TryGetItemAsync(hstrItem).get();

            if (!item)
            {

               m_estatus = error_failed;

               set_nok();

               if (efileopenParam & ::file::e_open_no_exception_on_open)
               {

                  return;

               }

               throw ::exception(m_estatus);

            }

            if (!item.IsOfType(winrt::Windows::Storage::StorageItemTypes::Folder))
            {

               m_estatus = error_failed;

               set_nok();

               if (efileopenParam & ::file::e_open_no_exception_on_open)
               {

                  return;

               }

               throw ::exception(m_estatus);

            }

            folder = item.as<::winrt::Windows::Storage::StorageFolder>();

         }

         m_folder = folder;

      }

      if (m_folder == nullptr)
      {

         m_estatus = error_not_found;

         set_nok();

         if (efileopenParam & ::file::e_open_no_exception_on_open)
         {

            return;

         }

         throw ::exception(m_estatus);

      }

      m_bCloseOnDelete = false;
      //m_hnative_buffer = (::u32)hnative_bufferNull;
      m_strFileName.Empty();

      m_strFileName = path;
      //      m_wstrnative_bufferName    = utf8_to_unicode(m_strFileName);

      ASSERT(sizeof(HANDLE) == sizeof(uptr));
      ASSERT(::file::e_open_share_compat == 0);

      // ::map read/write mode
      ASSERT((::file::e_open_read | ::file::e_open_write | ::file::e_open_read_write) == 3);
      ::u32 dwAccess = 0;
      switch (eopen & 3)
      {
      case ::file::e_open_read:
         dwAccess = GENERIC_READ;
         break;
      case ::file::e_open_write:
         dwAccess = GENERIC_WRITE;
         break;
      case ::file::e_open_read_write:
         dwAccess = GENERIC_READ | GENERIC_WRITE;
         break;
      default:
         dwAccess = GENERIC_READ;
         break;
      }

      // ::map share mode
      //::u32 dwShareMode = 0;
      //switch(nOpenFlags & 0x70)    // ::map compatibility mode to exclusive
      //{
      //default:
      //   ASSERT(false);  // invalid share mode?
      //case ::file::e_open_share_compat:
      //case ::file::e_open_share_exclusive:
      //   dwShareMode = 0;
      //   break;
      //case ::file::e_open_share_deny_write:
      //   dwShareMode = FILEative_buffer_SHARE_READ;
      //   break;
      //case ::file::e_open_share_deny_read:
      //   dwShareMode = native_buffer_SHARE_WRITE;
      //   break;
      //case ::file::e_open_share_deny_none:
      //   dwShareMode = native_buffer_SHARE_WRITE | native_buffer_SHARE_READ;
      //   break;
      //}

      // Note: type_text and type_binary are used in derived classes only.

      // ::map mode_no_inherit flag
      SECURITY_ATTRIBUTES sa;
      sa.nLength = sizeof(sa);
      sa.lpSecurityDescriptor = nullptr;

      sa.bInheritHandle = !(eopen & ::file::e_open_no_inherit);

      folder = m_folder;

      ::winrt::Windows::Storage::StorageFile                               file = nullptr;

      try
      {

         if (eopen & ::file::e_open_create)
         {

            if (eopen & ::file::e_open_no_truncate)
            {

               file = folder.CreateFileAsync(__hstring(strName), ::winrt::Windows::Storage::CreationCollisionOption::OpenIfExists).get();

            }
            else
            {

               file = folder.CreateFileAsync(__hstring(strName), ::winrt::Windows::Storage::CreationCollisionOption::ReplaceExisting).get();

            }

         }
         else
         {

            try
            {

               auto item = folder.TryGetItemAsync(__hstring(strName)).get();

               if (item && item.IsOfType(::winrt::Windows::Storage::StorageItemTypes::File))
               {

                  file = item.as<::winrt::Windows::Storage::StorageFile>();

               }

            }
            catch (...)
            {

               file = nullptr;

            }

         }

      }
      catch (const winrt::hresult_error & error)
      {

         auto hresult = error.code();

         auto estatus = hresult_to_status(error.code());

         auto errorcode = __hresult(hresult);

         throw ::file::exception(estatus, errorcode, m_path, "!::SetEndOfFile", m_eopen);

      }

      if (file == nullptr)
      {

         m_folder = nullptr;

         m_estatus = error_not_found;

         if (eopen & ::file::e_open_no_exception_on_open)
         {

            set_nok();

            return;

         }

         throw ::file::exception(m_estatus, {e_error_code_type_unknown
      ,-1}, m_path, "!::SetEndOfFile", m_eopen);

      }

      return open(file, eopen);

   }


   void native_buffer::open(::winrt::Windows::Storage::StorageFile file, const ::file::e_open & eopen)
   {

      m_file = file;

      ASSERT((::file::e_open_read | ::file::e_open_write | ::file::e_open_read_write) == 3);

      switch (eopen & 3)
      {
      case ::file::e_open_read:
         m_stream = m_file.OpenAsync(::winrt::Windows::Storage::FileAccessMode::Read).get();
         break;
      case ::file::e_open_write:
         m_stream = m_file.OpenAsync(::winrt::Windows::Storage::FileAccessMode::ReadWrite).get();
         break;
      case ::file::e_open_read_write:
         m_stream = m_file.OpenAsync(::winrt::Windows::Storage::FileAccessMode::ReadWrite).get();
         break;
      default:
         m_stream = m_file.OpenAsync(::winrt::Windows::Storage::FileAccessMode::Read).get();
         break;
      }

      if (m_stream == nullptr)
      {

         m_file = nullptr;

         m_folder = nullptr;

         throw ::file::exception(m_estatus, { e_error_code_type_unknown, -1 }, m_path, "null", m_eopen);

      }

      m_bCloseOnDelete = true;

      m_eopen = eopen;

      set_ok();

      m_estatus = ::success;

      //return ::success;

   }


   memsize native_buffer::read(void * pdata, memsize nCount)
   {

      if (nCount <= 0)
      {

         return 0;

      }

      ::winrt::Windows::Storage::Streams::Buffer buffer((::u32)  nCount);

      auto buffer2 = m_stream.ReadAsync(buffer, (::u32) nCount, ::winrt::Windows::Storage::Streams::InputStreamOptions::None).get();

      auto read = buffer2.Length();

      auto totalRead = windows_runtime_read_buffer(pdata, nCount, buffer);

      return totalRead;

   }


   void native_buffer::write(const void * pdata, memsize nCount)
   {

      auto buffer = windows_runtime_buffer(pdata, nCount);

      unsigned int u = m_stream.WriteAsync(buffer).get();

      if (u != nCount)
      {

         throw ::exception(error_io);

      }

   }


   filesize native_buffer::translate(filesize offset, ::enum_seek eseek)
   {

      if (eseek == ::e_seek_set)
      {

         m_stream.Seek(offset);

      }
      else if (eseek == ::e_seek_current)
      {

         m_stream.Seek(m_stream.Position() + offset);

      }
      else
      {

         m_stream.Seek(m_stream.Size() + offset);

      }

      return m_stream.Position();

   }


   filesize native_buffer::get_position() const
   {

      return m_stream.Position();

   }


   void native_buffer::flush()
   {

      if (m_stream)
      {

         m_stream.FlushAsync().get();

      }

   }


   void native_buffer::close()
   {

      if (m_eopen & ::file::e_open_write)
      {

         flush();

      }

      m_stream = nullptr;

      m_file = nullptr;

      m_folder = nullptr;

   }


   //void native_buffer::Abort()
   //{
   //   //ASSERT_VALID(this);
   //   //if(m_hnative_buffer != (::u32)hnative_bufferNull)
   //   //{
   //   //   // close but ignore errors
   //   //   ::CloseHandle((HANDLE)m_hnative_buffer);
   //   //   m_hnative_buffer = (::u32)hnative_bufferNull;
   //   //}
   //   //m_strFileName.Empty();
   //}

   void native_buffer::lock(filesize dwPos, filesize dwCount)
   {
      //ASSERT_VALID(this);
      //ASSERT(m_hnative_buffer != (::u32)hnative_bufferNull);

      ////      if (!::Locknative_buffer((HANDLE)m_hnative_buffer, LODWORD(dwPos), HIDWORD(dwPos), LODWORD(dwCount), HIDWORD(dwCount)))
      ////       WinFileException::ThrowOsError(get_application(), (::i32)::get_last_error());
   }

   void native_buffer::unlock(filesize dwPos, filesize dwCount)
   {
      //ASSERT_VALID(this);
      //ASSERT(m_hnative_buffer != (::u32)hnative_bufferNull);

      ////  if (!::Unlocknative_buffer((HANDLE)m_hnative_buffer,  LODWORD(dwPos), HIDWORD(dwPos), LODWORD(dwCount), HIDWORD(dwCount)))
      ////   WinFileException::ThrowOsError(get_application(), (::i32)::get_last_error());
   }


   void native_buffer::set_size(filesize dwNewLen)
   {

      m_stream.Size(dwNewLen);

      if (m_stream.Position() > m_stream.Size())
      {

         m_stream.Seek(m_stream.Size());

      }

      //ASSERT_VALID(this);
      //ASSERT(m_hnative_buffer != (::u32)hnative_bufferNull);

      //seek((::i32)dwNewLen,(::enum_seek)::e_seek_set);

      //if(!::SetEndOfnative_buffer((HANDLE)m_hnative_buffer))
      //   WinFileException::ThrowOsError(get_application(),(::i32)::get_last_error());
   }


   filesize native_buffer::get_size() const
   {

      ASSERT_VALID(this);

      filesize dwLen, dwCur;

      // seek is a non const operation
      native_buffer * pnative_buffer = (native_buffer *)this;

      dwCur = pnative_buffer->translate(0L, ::e_seek_current);

      dwLen = pnative_buffer->seek_to_end();

      VERIFY(dwCur == (u64)pnative_buffer->translate((filesize)dwCur, ::e_seek_set));

      return (filesize)dwLen;

   }

   //// native_buffer does not support direct buffering (CMemnative_buffer does)
   //u64 native_buffer::GetBufferPtr(::u32 nCommand,u64 /*nCount*/,
   //                                     void ** /*ppBufStart*/,void ** /*ppBufMax*/)
   //{
   //   ASSERT(nCommand == bufferCheck);
   //   UNUSED(nCommand);    // not used in retail build

   //   return 0;   // no support
   //}

   /*
   void native_buffer::Rename(const char * pszOldName, const char * pszNewName)

   {
   if (!::Movenative_buffer((char *)pszOldName, (char *)pszNewName))

   WinFileException::ThrowOsError(get_application(), (::i32)::get_last_error());
   }

   void native_buffer::erase(const char * pszfileName)

   {
   if (!::Deletenative_buffer((char *)pszfileName))

   WinFileException::ThrowOsError(get_application(), (::i32)::get_last_error());
   }
   */



   void native_buffer::assert_ok() const
   {

      ::file::file::assert_ok();

   }


   void native_buffer::dump(dump_context & dumpcontext) const
   {

      ::file::file::dump(dumpcontext);

   }


   //string native_buffer::GetFileName() const
   //{

   //   ASSERT_VALID(this);

   //   ::file::file_status status;

   //   GetStatus(status);

   //   string wstrResult;

   //   wstrResult = status.m_strFullName.name();

   //   return wstrResult;

   //}


   //string native_buffer::GetFileTitle() const
   //{

   //   ASSERT_VALID(this);

   //   ::file::file_status status;

   //   GetStatus(status);

   //   string wstrResult;

   //   wstrResult = status.m_strFullName.title();

   //   return wstrResult;

   //}


   ::file::path native_buffer::get_file_path() const
   {

      return m_file.Path().begin();

   }


   bool native_buffer::get_status(::file::file_status & rStatus) const
   {

      ASSERT_VALID(this);

      rStatus.m_strFullName = get_file_path();

      return true;

   }


   bool native_buffer::is_opened() const
   {

      return m_file != nullptr;

   }


   //void native_buffer::set_file_path(const ::file::path & path)
   //{

   //   ASSERT_VALID(this);

   //   ASSERT(__is_valid_string(path));

   //   m_strFileName = path;

   //}


} // namespace acme_universal_windows



