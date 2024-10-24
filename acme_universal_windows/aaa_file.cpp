#include "framework.h"
#include "file.h"
#include "acme/filesystem/file/exception.h"
#include "acme/filesystem/file/status.h"
#include "acme/filesystem/filesystem/file_system.h"
#include "acme/filesystem/filesystem/directory_system.h"


#include "acme/_operating_system.h"


inline bool hfile_is_ok(HANDLE hfile)
{

   return hfile != INVALID_HANDLE_VALUE && hfile != nullptr;

}


inline bool hfile_is_nok(HANDLE hfile)
{

   return !hfile_is_ok(hfile);

}


namespace acme_universal_windows
{


   //inline bool is_directory_separator(WCHAR ch)
   //{
   //   
   //   return (ch == '\\' || ch == '/');

   //}


   file::file()
   {

      m_hfile = INVALID_HANDLE_VALUE;

      m_bCloseOnDelete = true;

   }



   file::~file()
   {

      if (m_hfile != INVALID_HANDLE_VALUE && m_bCloseOnDelete)
      {

         close();

      }

   }

   //::pointer<::file::file>file::Duplicate() const
   //{
   //   ASSERT_VALID(this);
   //   ASSERT(m_hfile != (::u32)INVALID_HANDLE_VALUE);

   //   ::pointer<file>pFile = __allocate file();
   //   HANDLE hFile;
   //   if (!::DuplicateHandle(::GetCurrentProcess(), (HANDLE)m_hfile,
   //                          ::GetCurrentProcess(), &hFile, 0, false, DUPLICATE_SAME_ACCESS))
   //   {
   //      delete pFile;
   //      //xxx      Ex1::file::throw_os_error((::i32)::GetLastError(), m_path);
   //      throw ::exception(::exception("integer_exception 1"));
   //   }
   //   pFile->m_hfile = (::u32)hFile;
   //   ASSERT(pFile->m_hfile != (::u32)INVALID_HANDLE_VALUE);
   //   pFile->m_bCloseOnDelete = m_bCloseOnDelete;
   //   return pFile;
   //}


   void file::open(const ::file::path & path,  ::file::e_open eopen, ::pointer < ::file::exception > * ppfileexception)
   {

      if (m_hfile != INVALID_HANDLE_VALUE)
      {
       
         close();

      }

      ASSERT_VALID(this);
      ASSERT(is_string_ok(path));
      ASSERT(!(eopen & ::file::e_open_text));   // text mode not supported

      // file objects are always binary and CreateFile does not need flag
      eopen -= ::file::e_open_binary;


      string strPath = path;

      //str().case_insensitive_begins_eat(strPath.case_insensitive_begins_eat("image:\\\\");

      //str().case_insensitive_begins_eat(strPath, "music:\\\\");

      //str().case_insensitive_begins_eat(strPath, "video:\\\\");

      //if (str().case_insensitive_begins_eat(strPath, "document:\\\\"))
      //{

      //   output_debug_string("document:\\\\" + strPath);

      //}


      ::file::path lpszFileName(strPath);
      if ((eopen & ::file::e_open_defer_create_directory) && (eopen & ::file::e_open_write))
      {

         directory_system()->create(lpszFileName.folder());

      }

      m_bCloseOnDelete = false;
      m_hfile = INVALID_HANDLE_VALUE;
      m_path.empty();

      m_path     = lpszFileName;
//      m_wstrFileName    = utf8_to_unicode(m_path);

      ASSERT(sizeof(HANDLE) == sizeof(uptr));
      ASSERT(::file::e_open_share_compat == 0);

      // ::map read/write mode
      ASSERT((::file::e_open_read|::file::e_open_write|::file::e_open_read_write) == 3);
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
         dwAccess = GENERIC_READ|GENERIC_WRITE;
         break;
      default:
         dwAccess = GENERIC_READ;
         break;
      }

      // ::map share mode
      ::u32 dwShareMode = 0;
      switch (eopen & 0x70)    // ::map compatibility mode to exclusive
      {
      default:
         ASSERT(false);  // invalid share mode?
      case ::file::e_open_share_compat:
      case ::file::e_open_share_exclusive:
         dwShareMode = 0;
         break;
      case ::file::e_open_share_deny_write:
         dwShareMode = FILE_SHARE_READ;
         break;
      case ::file::e_open_share_deny_read:
         dwShareMode = FILE_SHARE_WRITE;
         break;
      case ::file::e_open_share_deny_none:
         dwShareMode = FILE_SHARE_WRITE|FILE_SHARE_READ;
         break;
      }

      // Note: type_text and type_binary are used in derived classes only.

      // ::map mode_no_inherit flag
      SECURITY_ATTRIBUTES sa;
      sa.nLength = sizeof(sa);
      sa.lpSecurityDescriptor = nullptr;
      sa.bInheritHandle = !(eopen & ::file::e_open_no_inherit);

      // ::map creation flags
      ::u32 dwCreateFlag;
      if (eopen & ::file::e_open_create)
      {
         if (eopen & ::file::e_open_no_truncate)
            dwCreateFlag = OPEN_ALWAYS;
         else
            dwCreateFlag = CREATE_ALWAYS;
      }
      else
         dwCreateFlag = OPEN_EXISTING;

      // attempt file creation
      //HANDLE hFile = shell::CreateFile(utf8_to_unicode(m_path), dwAccess, dwShareMode, &sa, dwCreateFlag, FILE_ATTRIBUTE_NORMAL, nullptr);
      HANDLE hfile = ::hfile_create(m_path, dwAccess, dwShareMode, &sa, dwCreateFlag, FILE_ATTRIBUTE_NORMAL, nullptr);
      if (hfile_is_nok(hfile))
      {
         ::u32 dwLastError = ::GetLastError();

         m_estatus = ::windows::last_error_status(dwLastError);

         if(dwLastError != ERROR_FILE_NOT_FOUND && dwLastError != ERROR_PATH_NOT_FOUND)
         {
            /*         if (pException != nullptr)
            {
            pException->create(this);
            ::file::exception * pfe = dynamic_cast < ::file::exception * > (pException->m_p);
            if(pfe != nullptr)
            {
            pfe->m_lOsError = dwLastError;
            pfe->m_cause = WinFileException::OsErrorToException(pfe->m_lOsError);
            pfe->m_path = lpszFileName;
            }
            return false;
            }
            else
            {*/

            if (eopen & ::file::e_open_no_exception_on_open)
            {


               return;


            }

            throw ::file::exception(m_estatus, ::windows::last_error_error_code(dwLastError), m_path, m_eopen, "!hfile_create");


            //return ::windows::last_error_status(dwLastError);

            //}

         }

//         try
//         {
////            system()->m_spfilesystem.m_p->FullPath(m_path, m_path);
//         }
//         catch(...)
//         {
//            return error_failed;
//         }

         //m_path = unicode_to_utf8(m_wstrFileName);

         hfile = ::hfile_create("\\\\?\\" + m_path, dwAccess, dwShareMode, &sa, dwCreateFlag, FILE_ATTRIBUTE_NORMAL, nullptr);

         if (hfile_is_nok(hfile))
         {
            /*if (pException != nullptr)
            {
            pException->create(this);
            ::file::exception * pfe = dynamic_cast < ::file::exception * > (pException->m_p);
            if(pfe != nullptr)
            {
            pfe->m_lOsError = ::GetLastError();
            pfe->m_cause = WinFileException::OsErrorToException(pfe->m_lOsError);
            pfe->m_path = lpszFileName;
            }
            return false;
            }
            else
            {*/


            ::u32 dwLastError = ::GetLastError();
            m_estatus = ::windows::last_error_status(dwLastError);

            if (eopen & ::file::e_open_no_exception_on_open)
            {


               return;


            }

            throw ::file::exception(m_estatus, ::windows::last_error_error_code(dwLastError), m_path, m_eopen, "!hfile_create");



            //}

         }

      }

      m_hfile = hfile;

      m_bCloseOnDelete = true;

      //return ::success;

   }


   memsize file::read(void * lpBuf, memsize nCount)
   {
      ASSERT_VALID(this);
      ASSERT(m_hfile != INVALID_HANDLE_VALUE);

      if (nCount == 0)
         return 0;   // avoid Win32 "nullptr-read"

      ASSERT(lpBuf != nullptr);
      ASSERT(is_memory_segment_ok(lpBuf, nCount));

      DWORD dwRead;

      if (!::ReadFile((HANDLE)m_hfile, lpBuf, (::u32)nCount, &dwRead, nullptr))
      {

         auto dwLastError = ::GetLastError();

         auto estatus = ::windows::last_error_status(dwLastError);

         auto errorcode = ::windows::last_error_error_code(dwLastError);
       
         throw ::file::exception(estatus, errorcode, m_path, m_eopen, "!::ReadFile");

      }

      return (::u32)dwRead;

   }


   void file::write(const void * lpBuf, memsize nCount)
   {
      ASSERT_VALID(this);
      ASSERT(m_hfile != INVALID_HANDLE_VALUE);

      if (nCount == 0)
         return;     // avoid Win32 "nullptr-write" option

      ASSERT(lpBuf != nullptr);
      ASSERT(is_memory_segment_ok(lpBuf, nCount));

      DWORD nWritten;

      if (!::WriteFile((HANDLE)m_hfile, lpBuf, (::u32)nCount, &nWritten, nullptr))
      {

         auto dwLastError = ::GetLastError();

         auto estatus = ::windows::last_error_status(dwLastError);

         auto errorcode = ::windows::last_error_error_code(dwLastError);

         throw ::file::exception(estatus, errorcode, m_path, m_eopen, "!::WriteFile");

      }

      // Win32s will not return an error all the time (usually DISK_FULL)
      if (nWritten < (::u32) nCount)
      {

         auto dwLastError = ::GetLastError();

         auto estatus = ::windows::last_error_status(dwLastError);

         auto errorcode = ::windows::last_error_error_code(dwLastError);

         throw ::file::exception(estatus, errorcode, m_path, "nWritten < nCount", m_eopen);

      }

   }

   
   void file::translate(filesize offset, ::enum_seek eseek)
   {

      if (m_hfile == INVALID_HANDLE_VALUE)
      {

         auto dwLastError = ::GetLastError();

         auto estatus = ::windows::last_error_status(dwLastError);

         auto errorcode = ::windows::last_error_error_code(dwLastError);

         throw ::file::exception(estatus, errorcode, m_path, "hfile == INVALID_HANDLE_VALUE", m_eopen);

      }

      ASSERT_VALID(this);
      ASSERT(m_hfile != INVALID_HANDLE_VALUE);
      ASSERT(eseek == ::e_seek_set || eseek == ::e_seek_from_end || eseek == ::e_seek_current);
      ASSERT(::e_seek_set == FILE_BEGIN && ::e_seek_from_end == FILE_END && ::e_seek_current == FILE_CURRENT);

      LONG lLoOffset = offset & 0xffffffff;
      LONG lHiOffset = (offset >> 32) & 0xffffffff;

      filesize posNew = ::SetFilePointer((HANDLE)m_hfile, lLoOffset, &lHiOffset, (::u32)eseek);

      posNew |= ((filesize) lHiOffset) << 32;

      if (posNew == (filesize)-1)
      {

         auto dwLastError = ::GetLastError();

         auto estatus = ::windows::last_error_status(dwLastError);

         auto errorcode = ::windows::last_error_error_code(dwLastError);

         throw ::file::exception(estatus, errorcode, m_path, "!SetFilePointer", m_eopen);

      }

      //return posNew;

   }


   filesize file::get_position() const
   {
      ASSERT_VALID(this);
      ASSERT(m_hfile != INVALID_HANDLE_VALUE);

      LONG lLoOffset = 0;
      LONG lHiOffset = 0;

      filesize pos = ::SetFilePointer((HANDLE)m_hfile, lLoOffset, &lHiOffset, FILE_CURRENT);
      pos |= ((filesize)lHiOffset) << 32;
      if (pos == (filesize)-1)
      {

         auto dwLastError = ::GetLastError();

         auto estatus = ::windows::last_error_status(dwLastError);

         auto errorcode = ::windows::last_error_error_code(dwLastError);

         throw ::file::exception(estatus, errorcode, m_path, "SetFilePointer < 0", m_eopen);

      }

      return pos;
   }

   
   void file::flush()
   {

      ASSERT_VALID(this);

      if (m_hfile == INVALID_HANDLE_VALUE)
         return;

      if (!::FlushFileBuffers((HANDLE)m_hfile))
      {

         auto dwLastError = ::GetLastError();

         auto estatus = ::windows::last_error_status(dwLastError);

         auto errorcode = ::windows::last_error_error_code(dwLastError);

         throw ::file::exception(estatus, errorcode, m_path, "!::FlushFileBuffers", m_eopen);

      }

   }


   void file::close()
   {
      ASSERT_VALID(this);
      ASSERT(m_hfile != INVALID_HANDLE_VALUE);

      bool bError = false;
      if (m_hfile != INVALID_HANDLE_VALUE)
         bError = !::CloseHandle((HANDLE)m_hfile);

      m_hfile = INVALID_HANDLE_VALUE;
      m_bCloseOnDelete = false;
      m_path.empty();

      if (bError)
      {

         auto dwLastError = ::GetLastError();

         auto estatus = ::windows::last_error_status(dwLastError);

         auto errorcode = ::windows::last_error_error_code(dwLastError);

         throw ::file::exception(estatus, errorcode, m_path, "!::CloseHandle", m_eopen);

      }

   }


   //void file::Abort()
   //{
   //   ASSERT_VALID(this);
   //   if (m_hfile != (::u32)INVALID_HANDLE_VALUE)
   //   {
   //      // close but ignore errors
   //      ::CloseHandle((HANDLE)m_hfile);
   //      m_hfile = (::u32)INVALID_HANDLE_VALUE;
   //   }
   //   m_path.empty();
   //}

   
   void file::lock(filesize dwPos, filesize dwCount)
   {
      
      ASSERT_VALID(this);

      ASSERT(m_hfile != INVALID_HANDLE_VALUE);

   }


   void file::unlock(filesize dwPos, filesize dwCount)
   {

      ASSERT_VALID(this);

      ASSERT(m_hfile != INVALID_HANDLE_VALUE);

   }


   void file::set_size(filesize dwNewLen)
   {

      ASSERT_VALID(this);

      ASSERT(m_hfile != INVALID_HANDLE_VALUE);

      translate((::i32)dwNewLen, (::enum_seek)::e_seek_set);

      if (!::SetEndOfFile((HANDLE)m_hfile))
      {

         auto dwLastError = ::GetLastError();

         auto estatus = ::windows::last_error_status(dwLastError);

         auto errorcode = ::windows::last_error_error_code(dwLastError);

         throw ::file::exception(estatus, errorcode, m_path, "!::SetEndOfFile", m_eopen);

      }

   }


   filesize file::size() const
   {
      
      ASSERT_VALID(this);

      filesize dwLen, dwCur;

      // seek is a non const operation
      file* pFile = (file*)this;

      dwCur = pFile->get_position();

      pFile->seek_to_end();

      dwLen = pFile->get_position();

      pFile->translate((filesize) dwCur, ::e_seek_set);

      return (filesize) dwLen;


   }


   //string CLASS_DECL_ACME vfxStringFromCLSID(REFCLSID rclsid)
   //{

   //   char szCLSID[256];

   //   sprintf(szCLSID, "{%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",
   //           rclsid.Data1, rclsid.Data2, rclsid.Data3,
   //           rclsid.Data4[0], rclsid.Data4[1], rclsid.Data4[2], rclsid.Data4[3],
   //           rclsid.Data4[4], rclsid.Data4[5], rclsid.Data4[6], rclsid.Data4[7]);

   //   return szCLSID;

   //}


//   bool CLASS_DECL_ACME vfxGetInProcServer(const char * lpszCLSID, string & str)
//   {
//
//      bool b = false;
//
//#ifdef WINDOWS_DESKTOP
//
//      HKEY hKey = nullptr;
//
//      if (RegOpenKey(HKEY_CLASSES_ROOT, "CLSID", &hKey) == ERROR_SUCCESS)
//      {
//         HKEY hKeyCLSID = nullptr;
//         if (RegOpenKey(hKey, lpszCLSID, &hKeyCLSID) == ERROR_SUCCESS)
//         {
//            HKEY hKeyInProc = nullptr;
//            if (RegOpenKey(hKeyCLSID, "InProcServer32", &hKeyInProc) ==
//                  ERROR_SUCCESS)
//            {
//               char * lpsz = str.GetBuffer(_MAX_PATH);
//               ::u32 dwSize = _MAX_PATH * sizeof(char);
//               ::u32 dwType;
//               ::i32 lRes = ::RegQueryValueEx(hKeyInProc, "",
//                                             nullptr, &dwType, (::u8*)lpsz, &dwSize);
//               str.ReleaseBuffer();
//               b = (lRes == ERROR_SUCCESS);
//               RegCloseKey(hKeyInProc);
//            }
//            RegCloseKey(hKeyCLSID);
//         }
//         RegCloseKey(hKey);
//      }
//#endif
//      return b;
//   }
//   //#endif  //!___NO_OLE_SUPPORT




   //// turn a file, relative path or other into an absolute path
   //bool CLASS_DECL_ACME windows_full_path(unichar * lpszPathOut, const unichar * lpszFileIn)
   //// lpszPathOut = buffer of _MAX_PATH
   //// lpszFileIn = file, relative path or absolute path
   //// (both in ANSI character set)
   //{

   //   ASSERT(is_memory_segment_ok(lpszPathOut, _MAX_PATH));

   //   wcscpy(lpszPathOut, lpszFileIn);

   //   return true;

   //}


   //void CLASS_DECL_ACME vfxGetModuleShortFileName(HINSTANCE hInst, string& strShortName)
   //{
   //   
   //   throw ::exception(todo);

   //}


   //void file::assert_ok() const
   //{

   //   ::file::file::assert_ok();
   //   // we permit the descriptor m_hfile to be any value for derived classes

   //}


   //void file::dump(dump_context & dumpcontext) const
   //{

   //   ::file::file::dump(dumpcontext);

   //   //dumpcontext << "with handle " << (::uptr) m_hfile;
   //   //dumpcontext << " and name \"" << m_path << "\"";
   //   //dumpcontext << "\n";

   //}


/* Error Codes */

#define EPERM           1
#define ENOENT          2
#define ESRCH           3
#define EINTR           4
#define EIO             5
#define ENXIO           6
#define E2BIG           7
#define ENOEXEC         8
#define EBADF           9
#define ECHILD          10
#define EAGAIN          11
#define ENOMEM          12
#define EACCES          13
#define EFAULT          14
#define EBUSY           16
#define EEXIST          17
#define EXDEV           18
#define ENODEV          19
#define ENOTDIR         20
#define EISDIR          21
#define EINVAL          22
#define ENFILE          23
#define EMFILE          24
#define ENOTTY          25
#define EFBIG           27
#define ENOSPC          28
#define ESPIPE          29
#define EROFS           30
#define EMLINK          31
#define EPIPE           32
#define EDOM            33
#define ERANGE          34
#define EDEADLK         36
#define ENAMETOOLONG    38
#define ENOLCK          39
#define ENOSYS          40
#define ENOTEMPTY       41
#define EILSEQ          42

/*
* Support EDEADLOCK for compatibiity with older MS-C versions.
*/
#define EDEADLOCK       EDEADLK


   ::file::path file::get_file_path() const
   {
      ASSERT_VALID(this);

  /*    ::file::file_status status;
      GetStatus(status);
      return status.m_strFullName;*/
      return m_path;

   }


   //::u32 CLASS_DECL_ACME vfxGetFileName(const unichar * lpszPathName, unichar * lpszTitle, ::u32 nMax)
   //{
   //   ASSERT(lpszTitle == nullptr ||
   //          is_memory_segment_ok(lpszTitle, _MAX_FNAME));
   //   ASSERT(is_string_ok(lpszPathName));

   //   // always capture the complete file name including extension (if present)
   //   unichar * lpszTemp = (unichar *)lpszPathName;
   //   for (const unichar * lpsz = lpszPathName; *lpsz != '\0'; lpsz = _wcsinc(lpsz))
   //   {
   //      // remember last directory/drive separator
   //      if (*lpsz == '\\' || *lpsz == '/' || *lpsz == ':')
   //         lpszTemp = (unichar *)_wcsinc(lpsz);
   //   }

   //   // lpszTitle can be nullptr which just returns the number of bytes
   //   if (lpszTitle == nullptr)
   //      return wcslen(lpszTemp)+1;

   //   // otherwise copy it into the buffer provided
   //   wcsncpy(lpszTitle, lpszTemp, nMax);
   //   return 0;
   //}


   /////////////////////////////////////////////////////////////////////////////
   // FileException




   //void WinFileException::ThrowOsError(::matter * pobject, ::i32 lOsError, const char * lpszFileName /* = nullptr */)
   //{
   //   if (lOsError != 0)
   //      ::file::throw_os_error(pobject, WinFileException::OsErrorToException(lOsError), lOsError, ::error_io, lpszFileName);
   //}

   //void WinFileException::ThrowErrno(::matter * pobject, int nErrno, const char * lpszFileName /* = nullptr */)
   //{
   //   if (nErrno != 0)
   //      ::file::throw_os_error(pobject, WinFileException::ErrnoToException(nErrno), _doserrno, ::error_io, lpszFileName);
   //}



   /////////////////////////////////////////////////////////////////////////////
   // WinFileException helpers

   //void CLASS_DECL_ACME throw_exception(::pointer<::platform::application>papp, int cause, ::i32 lOsError, const char * lpszFileName /* == nullptr */)
   //{

   //   throw ::exception(::file::exception(WinFileException::OsErrorToException(lOsError),lOsError,lpszFileName));

   //}


   //::e_status WinFileException::ErrnoToException(int nErrno)
   //{
   //   switch(nErrno)
   //   {
   //   case EPERM:
   //   case EACCES:
   //      return ::file::exception::accessDenied;
   //   case EBADF:
   //      return ::file::exception::invalidFile;
   //   case EDEADLOCK:
   //      return ::file::exception::sharingViolation;
   //   case EMFILE:
   //      return ::file::exception::tooManyOpenFiles;
   //   case ENOENT:
   //   case ENFILE:
   //      return ::file::exception::fileNotFound;
   //   case ENOSPC:
   //      return ::file::exception::diskFull;
   //   case EINVAL:
   //   case EIO:
   //      return ::file::exception::hardIO;
   //   default:
   //      return ::file::exception::type_generic;
   //   }
   //}

   //::e_status WinFileException::OsErrorToException(::i32 lOsErr)
   //{
   //   // NT Error codes
   //   switch ((::u32)lOsErr)
   //   {
   //   case NO_ERROR:
   //      return ::file::exception::none;
   //   case ERROR_FILE_NOT_FOUND:
   //      return ::file::exception::fileNotFound;
   //   case ERROR_PATH_NOT_FOUND:
   //      return ::file::exception::badPath;
   //   case ERROR_TOO_MANY_OPEN_FILES:
   //      return ::file::exception::tooManyOpenFiles;
   //   case ERROR_ACCESS_DENIED:
   //      return ::file::exception::accessDenied;
   //   case ERROR_INVALID_HANDLE:
   //      return ::file::exception::fileNotFound;
   //   case ERROR_BAD_FORMAT:
   //      return ::file::exception::invalidFile;
   //   case ERROR_INVALID_ACCESS:
   //      return ::file::exception::accessDenied;
   //   case ERROR_INVALID_DRIVE:
   //      return ::file::exception::badPath;
   //   case ERROR_CURRENT_DIRECTORY:
   //      return ::file::exception::eraseCurrentDir;
   //   case ERROR_NOT_SAME_DEVICE:
   //      return ::file::exception::badPath;
   //   case ERROR_NO_MORE_FILES:
   //      return ::file::exception::fileNotFound;
   //   case ERROR_WRITE_PROTECT:
   //      return ::file::exception::accessDenied;
   //   case ERROR_BAD_UNIT:
   //      return ::file::exception::hardIO;
   //   case ERROR_NOT_READY:
   //      return ::file::exception::hardIO;
   //   case ERROR_BAD_COMMAND:
   //      return ::file::exception::hardIO;
   //   case ERROR_CRC:
   //      return ::file::exception::hardIO;
   //   case ERROR_BAD_LENGTH:
   //      return ::file::exception::badSeek;
   //   case ERROR_SEEK:
   //      return ::file::exception::badSeek;
   //   case ERROR_NOT_DOS_DISK:
   //      return ::file::exception::invalidFile;
   //   case ERROR_SECTOR_NOT_FOUND:
   //      return ::file::exception::badSeek;
   //   case ERROR_WRITE_FAULT:
   //      return ::file::exception::accessDenied;
   //   case ERROR_READ_FAULT:
   //      return ::file::exception::badSeek;
   //   case ERROR_SHARING_VIOLATION:
   //      return ::file::exception::sharingViolation;
   //   case ERROR_LOCK_VIOLATION:
   //      return ::file::exception::lockViolation;
   //   case ERROR_WRONG_DISK:
   //      return ::file::exception::badPath;
   //   case ERROR_SHARING_BUFFER_EXCEEDED:
   //      return ::file::exception::tooManyOpenFiles;
   //   case ERROR_HANDLE_EOF:
   //      return ::file::exception::endOfFile;
   //   case ERROR_HANDLE_DISK_FULL:
   //      return ::file::exception::diskFull;
   //   case ERROR_DUP_NAME:
   //      return ::file::exception::badPath;
   //   case ERROR_BAD_NETPATH:
   //      return ::file::exception::badPath;
   //   case ERROR_NETWORK_BUSY:
   //      return ::file::exception::accessDenied;
   //   case ERROR_DEV_NOT_EXIST:
   //      return ::file::exception::badPath;
   //   case ERROR_ADAP_HDW_ERR:
   //      return ::file::exception::hardIO;
   //   case ERROR_BAD_NET_RESP:
   //      return ::file::exception::accessDenied;
   //   case ERROR_UNEXP_NET_ERR:
   //      return ::file::exception::hardIO;
   //   case ERROR_BAD_REM_ADAP:
   //      return ::file::exception::invalidFile;
   //   case ERROR_NO_SPOOL_SPACE:
   //      return ::file::exception::directoryFull;
   //   case ERROR_NETNAME_DELETED:
   //      return ::file::exception::accessDenied;
   //   case ERROR_NETWORK_ACCESS_DENIED:
   //      return ::file::exception::accessDenied;
   //   case ERROR_BAD_DEV_TYPE:
   //      return ::file::exception::invalidFile;
   //   case ERROR_BAD_NET_NAME:
   //      return ::file::exception::badPath;
   //   case ERROR_TOO_MANY_NAMES:
   //      return ::file::exception::tooManyOpenFiles;
   //   case ERROR_SHARING_PAUSED:
   //      return ::file::exception::badPath;
   //   case ERROR_REQ_NOT_ACCEP:
   //      return ::file::exception::accessDenied;
   //   case ERROR_FILE_EXISTS:
   //      return ::file::exception::accessDenied;
   //   case ERROR_CANNOT_MAKE:
   //      return ::file::exception::accessDenied;
   //   case ERROR_ALREADY_ASSIGNED:
   //      return ::file::exception::badPath;
   //   case ERROR_INVALID_PASSWORD:
   //      return ::file::exception::accessDenied;
   //   case ERROR_NET_WRITE_FAULT:
   //      return ::file::exception::hardIO;
   //   case ERROR_DISK_CHANGE:
   //      return ::file::exception::fileNotFound;
   //   case ERROR_DRIVE_LOCKED:
   //      return ::file::exception::lockViolation;
   //   case ERROR_BUFFER_OVERFLOW:
   //      return ::file::exception::badPath;
   //   case ERROR_DISK_FULL:
   //      return ::file::exception::diskFull;
   //   case ERROR_NO_MORE_SEARCH_HANDLES:
   //      return ::file::exception::tooManyOpenFiles;
   //   case ERROR_INVALID_TARGET_HANDLE:
   //      return ::file::exception::invalidFile;
   //   case ERROR_INVALID_CATEGORY:
   //      return ::file::exception::hardIO;
   //   case ERROR_INVALID_NAME:
   //      return ::file::exception::badPath;
   //   case ERROR_INVALID_LEVEL:
   //      return ::file::exception::badPath;
   //   case ERROR_NO_VOLUME_LABEL:
   //      return ::file::exception::badPath;
   //   case ERROR_NEGATIVE_SEEK:
   //      return ::file::exception::badSeek;
   //   case ERROR_SEEK_ON_DEVICE:
   //      return ::file::exception::badSeek;
   //   case ERROR_DIR_NOT_ROOT:
   //      return ::file::exception::badPath;
   //   case ERROR_DIR_NOT_EMPTY:
   //      return ::file::exception::eraseCurrentDir;
   //   case ERROR_LABEL_TOO_LONG:
   //      return ::file::exception::badPath;
   //   case ERROR_BAD_PATHNAME:
   //      return ::file::exception::badPath;
   //   case ERROR_LOCK_FAILED:
   //      return ::file::exception::lockViolation;
   //   case ERROR_BUSY:
   //      return ::file::exception::accessDenied;
   //   case ERROR_INVALID_ORDINAL:
   //      return ::file::exception::invalidFile;
   //   case ERROR_ALREADY_EXISTS:
   //      return ::file::exception::accessDenied;
   //   case ERROR_INVALID_EXE_SIGNATURE:
   //      return ::file::exception::invalidFile;
   //   case ERROR_BAD_EXE_FORMAT:
   //      return ::file::exception::invalidFile;
   //   case ERROR_FILENAME_EXCED_RANGE:
   //      return ::file::exception::badPath;
   //   case ERROR_META_EXPANSION_TOO_LONG:
   //      return ::file::exception::badPath;
   //   case ERROR_DIRECTORY:
   //      return ::file::exception::badPath;
   //   case ERROR_OPERATION_ABORTED:
   //      return ::file::exception::hardIO;
   //   case ERROR_IO_INCOMPLETE:
   //      return ::file::exception::hardIO;
   //   case ERROR_IO_PENDING:
   //      return ::file::exception::hardIO;
   //   case ERROR_SWAPERROR:
   //      return ::file::exception::accessDenied;
   //   default:
   //      return ::file::exception::type_generic;
   //   }
   //}


   // IMPLEMENT_DYNAMIC(WinFileException, ::exception::acme)

   /////////////////////////////////////////////////////////////////////////////




   /////////////////////////////////////////////////////////////////////////////
   // file Status implementation

   bool file::get_status(::file::file_status& rStatus) const
   {
      ASSERT_VALID(this);

      //memory_set(&rStatus, 0, sizeof(::file::file_status));

      // copy file name from cached m_path
      rStatus.m_strFullName = m_path;

      return true;

   }


//   bool file::GetStatus(const ::file::path & lpszFileName, ::file::file_status& rStatus)
//   {
//
//#ifdef WINDOWS_DESKTOP
//      // attempt to fully qualify path first
//      wstring wstrFullName;
//      wstring wstrFileName;
//      wstrFileName = utf8_to_unicode(lpszFileName);
//      if (!windows_full_path(wstrFullName, wstrFileName))
//      {
//         rStatus.m_strFullName.empty();
//         return false;
//      }
//      unicode_to_utf8(rStatus.m_strFullName, wstrFullName);
//
//      WIN32_FIND_DATA findFileData;
//      HANDLE hFind = FindFirstFile((char *)lpszFileName, &findFileData);
//      if (hFind == INVALID_HANDLE_VALUE)
//         return false;
//      VERIFY(FindClose(hFind));
//
//      // strip attribute of NORMAL bit, our API doesn't have a "normal" bit.
//      rStatus.m_attribute = (::u8) (findFileData.dwFileAttributes & ~FILE_ATTRIBUTE_NORMAL);
//
//      // get just the low ::u32 of the file size_i32
//      ASSERT(findFileData.nFileSizeHigh == 0);
//      rStatus.m_size = (::i32)findFileData.nFileSizeLow;
//
//      // convert times as appropriate
//      rStatus.m_ctime = ::earth::time(findFileData.ftCreationTime);
//      rStatus.m_atime = ::earth::time(findFileData.ftLastAccessTime);
//      rStatus.m_mtime = ::earth::time(findFileData.ftLastWriteTime);
//
//      if (rStatus.m_ctime.get_time() == 0)
//         rStatus.m_ctime = rStatus.m_mtime;
//
//      if (rStatus.m_atime.get_time() == 0)
//         rStatus.m_atime = rStatus.m_mtime;
//#endif
//      return true;
//   }


   bool file::is_opened() const
   {

      return m_hfile != INVALID_HANDLE_VALUE;

   }


   void file::set_file_path(const ::file::path&  lpszNewName)
   {

      ASSERT_VALID(this);

      ASSERT(is_string_ok(lpszNewName));

      m_path = lpszNewName;

   }


   file::operator HANDLE() const
   { 
      
      return m_hfile; 
      
   }


   u64 file::ReadHuge(void * lpBuffer, u64 dwCount)
   { 
      
      return (u64) read(lpBuffer, (::u32)dwCount);
      
   }


   void file::WriteHuge(const void * lpBuffer, u64 dwCount)
   {
      
      write(lpBuffer, (::u32)dwCount);
      
   }


} // namespace acme_universal_windows



