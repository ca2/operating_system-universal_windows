// Create on 2021-03-21 20:00 <3ThomasBS_
// Copied by camilo from operating_system-windows on 2021-09-01 22:01 ThomasMonth!! <3ThomasBS_
#include "framework.h"
#include "directory_system.h"
#include "file_system.h"
#include "node.h"
#include "acme/filesystem/filesystem/listing.h"
#include "acme/platform/node.h"


#include "acme/_operating_system.h"


#include "_winrt_storage.h"

#undef ___new
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Foundation.Collections.h>



namespace acme_universal_windows
{


   directory_system::directory_system()
   {

      m_pplatformdir = this;

   }


   directory_system::~directory_system()
   {


   }


   string directory_system::dir_root()
   {

      ::string path;

      //path = _get_known_folder(FOLDERID_RoamingAppData);

      //if (path.length() > 0 && path[path.length() - 1] != '\\')
      //{

      //   path += "\\";

      //}

      path += "ca2";

      return path;

   }


   ::file::path directory_system::get_memory_map_base_folder_path()
   {

      //to path = _get_known_folder(FOLDERID_RoamingAppData);

      ::file::path path;

      path = "ca2/memory_map";

      return path;

   }



   ::file::path directory_system::program_data()
   {

      return install() / "data";

   }


   ::file::path directory_system::roaming()
   {

      return install() / "roaming";

   }


   ::file::path directory_system::appdata()
   {

      return roaming() / appid();

   }


   ::file::path directory_system::public_system()
   {

      return public_root() / "system";

   }


   ::file::path directory_system::system()
   {

      return ca2roaming() / "system";

   }


   ::file::path directory_system::config()
   {

      return ca2roaming() / "config";

   }


   ::file::path directory_system::local()
   {

      return ca2roaming() / "local";

   }


   ::file::path directory_system::sensitive()
   {

#ifdef WINDOWS

      return "C:\\sensitive\\sensitive";

#else

      return "/sensitive/sensitive";

#endif

   }







   string directory_system::system_short_name()
   {

#ifdef UNIVERSAL_WINDOWS

      return "metro";

#else

      ::file::path pathSystemShortName = localconfig() / "system_short_name.txt";

      return file_system()->as_string(pathSystemShortName).trimmed();

#endif

   }


   ::file::path directory_system::relative(::file::path path)
   {

      path.find_replace(":", "");

      path.case_insensitive_ends_eat(".exe");

      return path;

   }


   ::file::path directory_system::inplace_install(string strAppId, string strPlatform, string strConfiguration)
   {

#ifdef WINDOWS_DESKTOP

      ::file::path path;

      string strFolder;

      character_count iFind = strAppId.find('/');

      if (strPlatform.case_insensitive_order("win32") == 0 || strPlatform.case_insensitive_order("x86") == 0)
      {

         path = program_files_x86();

      }
      else
      {
         path = program_files_x86();


         path = program_files();

      }

      if (iFind < 0)
      {

         path /= strAppId;

      }
      else
      {

         path /= strAppId.left()(iFind);

         path /= strAppId.substr(iFind + 1);

      }

      return path;

#elif defined(ANDROID)

      auto psystem = system();

      auto pacmedir = psystem->m_pdirectorysystem;


      return          auto psystem = system();

      auto pacmedir = psystem->m_pdirectorysystem;

      pacmedir->roaming();

#else

      return "";

#endif


   }


   ::file::path directory_system::inplace_matter_install(string strAppId, string strPlatform, string strConfiguration)
   {

#ifdef WINDOWS_DESKTOP

      ::file::path path;

      string strFolder;

      character_count iFind = strAppId.find('/');

      path = ca2roaming();

      path /= "_matter";

      return path;

#elif defined(ANDROID)

      auto psystem = system();

      auto pacmedir = psystem->m_pdirectorysystem;


      return          auto psystem = system();

      auto pacmedir = psystem->m_pdirectorysystem;

      pacmedir->roaming();

#else

      return "";

#endif


   }


   ::file::path directory_system::install()
   {

      if (m_pathInstallFolder.is_empty())
      {

         return default_install();

      }

      return m_pathInstallFolder;

   }


   ::file::path directory_system::default_install()
   {

      auto pwsz = ::winrt::Windows::Storage::ApplicationData::Current().LocalFolder().Path().begin();

      ::file::path path;

      path = pwsz;

      return path;

   }


   ::file::path directory_system::beforeca2()
   {

      return ::file_path_folder(install());

   }






#ifdef WINDOWS_DESKTOP


#include <Shlobj.h>


   ::file::path directory_system::program_files_x86()
   {

      wstring wstrModuleFolder(get_buffer, sizeof(unichar) * 8);

      wstring wstrModuleFilePath(get_buffer, sizeof(unichar) * 8);

      wcscpy(wstrModuleFilePath, _wgetenv(L"PROGRAMFILES(X86)"));

      if (wcslen(wstrModuleFilePath) == 0)
      {

         SHGetSpecialFolderPathW(nullptr, wstrModuleFilePath, CSIDL_PROGRAM_FILES, false);

      }

      wstrModuleFilePath.trim_right(L"\\/");

      wcscpy(wstrModuleFolder, wstrModuleFilePath);

      return string(wstrModuleFolder);

   }


   ::file::path directory_system::program_files()
   {

      wstring wstrModuleFolder(get_buffer, sizeof(unichar) * 8);

      wstring wstrModuleFilePath(get_buffer, sizeof(unichar) * 8);

      wcscpy(wstrModuleFilePath, _wgetenv(L"PROGRAMW6432"));

      if (wcslen(wstrModuleFilePath) == 0)
      {

         SHGetSpecialFolderPathW(nullptr, wstrModuleFilePath, CSIDL_PROGRAM_FILES, false);

      }

      wstrModuleFilePath.trim_right(L"\\/");

      wstrModuleFolder = wstrModuleFilePath;

      return string(wstrModuleFolder);



   }


#else


   ::file::path directory_system::program_files_x86()
   {

      ::file::path path("/opt/ca2");

      return path;

   }


   ::file::path directory_system::program_files()
   {

      ::file::path path("/opt/ca2");

      return path;

   }


#endif


   ::file::path directory_system::stage(string strAppId, string strPlatform, string strConfiguration)
   {

      return inplace_install(strAppId, strPlatform, strConfiguration) / "time" / node()->time_binary_platform(strPlatform) / strConfiguration;

   }


#ifdef LINUX


   ::file::path directory_system::home()
   {

      return getenv("HOME");

   }


#endif


#if defined(UNIVERSAL_WINDOWS) || defined(__APPLE__) || defined(LINUX) || defined(ANDROID)

   ::file::path directory_system::bookmark()
   {

      return localconfig() / "bookmark";

   }


#endif


   ::file::path directory_system::home()
   {

      return m_pathInstallFolder / "home";

   }


   void directory_system::set_path_install_folder(const ::string & pszPath)
   {

      m_pathInstallFolder = pszPath;

   }




   ::file::path directory_system::sys_temp()
   {

      return appdata() / "time";

   }


   ::file::path directory_system::ca2appdata()
   {

      return ca2roaming() / "appdata";

   }


   ::file::path directory_system::public_root()
   {

      return program_data() / "ca2";

   }

   ::file::path directory_system::ca2roaming()
   {

      return roaming() / "ca2";

   }


   ::file::path directory_system::localconfig()
   {

      return ca2roaming() / "localconfig";

   }


   //

   //::file::path directory_system::pathfind(const string& pszEnv, const string& pszTopic, const string& pszMode)
   //{

   //   ::file::path_array stra;

   //   stra.add_tokens(pszEnv, ":", false);

   //   string strCandidate;

   //   for (int i = 0; i < stra.get_count(); i++)
   //   {

   //      strCandidate = stra[i] / pszTopic;

   //      //if (m_papplication->file().exists(strCandidate))
   //      if (m_pfilesystem->exists(strCandidate))
   //      {

   //         return strCandidate;

   //      }

   //   }

   //   return "";

   //}



   //::file::path directory_system::get_memory_map_base_folder_path()
   //{

   //   return "";

   //}


   ::file::path directory_system::user_appdata_local()
   {

      //return _shell_get_special_folder_path(CSIDL_LOCAL_APPDATA);
      return "local";

   }


   ::file::e_type directory_system::_file_type(const ::file::path & path)
   {

      ::pointer < ::acme_universal_windows::node > pnode = node();

      auto folder = pnode->windows_runtime_folder(this, path, false);

      if (folder)
      {

         return ::file::e_type_existent_folder;

      }
      else
      {

         if (file_system()->exists(path))
         {

            return ::file::e_type_existent_file;

         }

      }

      return ::file::e_type_doesnt_exist;

   }


   //bool directory_system::_is(bool & bDir, const ::file::path & path)
   //{

   //   unsigned int dwFileAttributes = ::windows::_get_file_attributes(path);

   //   if (dwFileAttributes == INVALID_FILE_ATTRIBUTES)
   //   {

   //      auto lasterror = ::GetLastError();

   //      if (lasterror == ERROR_PATH_NOT_FOUND)
   //      {

   //         // Path would be accessible...

   //         // Parent Folder is not folder...

   //         bDir = false;

   //         return true;

   //      }
   //      else if (lasterror == ERROR_FILE_NOT_FOUND)
   //      {

   //         // Path would be accessible...

   //         // Parent folder exists...

   //         bDir = false;

   //         return true;

   //      }
   //      else if (lasterror == ERROR_INVALID_NAME)
   //      {

   //         //throw_last_error_exception(path, ::file::e_open_none, lasterror, "ERROR_INVALID_NAME");

   //         return false;

   //      }

   //      //::file::path pathCamilo = "C:\\Users\\camilo";

   //      //::file::path pathThomasBS_ = "C:\\Users\\thoma";

   //      //unsigned int dwFileAttributesCamilo = ::windows::_get_file_attributes(pathCamilo);

   //      //auto lasterror2 = ::GetLastError();

   //      //unsigned int dwFileAttributesThomasBS_ = ::windows::_get_file_attributes(pathThomasBS_);

   //      //auto lasterror5 = ::GetLastError();

   //      return false;

   //   }

   //   if(!(dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
   //   {

   //      bDir = false;

   //   }
   //   else
   //   {

   //      bDir = true;

   //   }

   //   return true;

   //}


   void TranslateLastError()
   {

      if (errno == EEXIST)
      {

         set_last_status(error_already_exists);

      }
      else
      {

         set_last_status(::success);

      }

   }


bool windows_file_find_is_dots(WIN32_FIND_DATAW & data)
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


//#if defined(UNIVERSAL_WINDOWS)
//
//#pragma push_macro("system()")
//
//#undef system()
//
//   //using namespace ::winrt::Windowsacmesystem();
//
//#pragma pop_macro("system()")
//
//#endif


   //namespace dir
   //{


      //string directory_system::name(const char * path1)
      //{
      //   const scoped_string & str = path1 + strlen(path1) - 1;
      //   while (psz >= path1)
      //   {
      //      if (*psz != '\\' && *psz != '/' && *psz != ':')
      //         break;
      //      psz--;
      //   }
      //   while (psz >= path1)
      //   {
      //      if (*psz == '\\' || *psz == '/' || *psz == ':')
      //         break;
      //      psz--;
      //   }
      //   if (psz >= path1) // strChar == "\\" || strChar == "/"
      //   {
      //      const scoped_string & strEnd = psz;
      //      /*while(psz >= path1)
      //       {
      //       if(*psz != '\\' && *psz != '/' && *psz != ':')
      //       break;
      //       psz--;
      //       }*/
      //      return string(path1, pszEnd - path1 + 1);
      //   }
      //   else
      //   {
      //      return "";
      //   }
      //}


   //   ::file::path directory_system::module_folder()
   //   {
   //
   //   #if defined(ANDROID)
   //
   //      return path_system()->app_module().folder();
   //
   //   #elif defined(UNIVERSAL_WINDOWS)
   //
   //      wstring wstrModuleFilePath;
   //
   //      auto pwszModuleFilePath = wstrModuleFilePath.get_buffer(MAX_PATH * 8);
   //
   //      if (!GetModuleFileNameW(nullptr, pwszModuleFilePath, MAX_PATH * 8))
   //      {
   //         
   //         return "";
   //         
   //      }
   //
   //      wstrModuleFilePath.release_buffer();
   //
   //      LPWSTR pszModuleFileName;
   //
   //      wstring wstrModuleFolder;
   //
   //      auto pwszModuleFolder = wstrModuleFolder.get_buffer(MAX_PATH * 8);
   //
   //      if (!GetFullPathNameW(wstrModuleFilePath, MAX_PATH * 8, pwszModuleFolder, &pszModuleFileName))
   //      {
   //
   //         return "";
   //         
   //      }
   //
   //      wstrModuleFolder.release_buffer();
   //
   //      wstrModuleFolder.ends_eat_ci("\\");
   //      wstrModuleFolder.ends_eat_ci("/");
   //      wstrModuleFolder.ends_eat_ci("\\");
   //      wstrModuleFolder.ends_eat_ci("/");
   //
   //      return string(wstrModuleFolder);
   //
   //
   //   #elif defined(WINDOWS)
   //
   //
   //      wstring wstrModuleFolder(get_buffer, MAX_PATH * 8);
   //
   //
   //      wstring wstrModuleFilePath(get_buffer, MAX_PATH * 8);
   //
   //
   //      HMODULE hmodule = ::GetModuleHandleA("acme.dll");
   //
   //      if(hmodule == nullptr)
   //         hmodule = ::GetModuleHandleA("spalib.dll");
   //
   //      if(hmodule == nullptr)
   //      {
   //
   //         cotaskp(PWSTR) pwstr;
   //
   //         HRESULT hr = SHGetKnownFolderPath(
   //                     FOLDERID_ProgramFilesX86,
   //                     KF_FLAG_DEFAULT,
   //                     nullptr,
   //                     &pwstr);
   //
   //         wcscpy(wstrModuleFilePath, pwstr);
   //
   //
   //         //if(wstrModuleFilePath[wcslen(wstrModuleFilePath) - 1] == '\\'
   //
   //         //      || wstrModuleFilePath[wcslen(wstrModuleFilePath) - 1] == '/')
   //
   //         //{
   //         //   wstrModuleFilePath[wcslen(wstrModuleFilePath) - 1] = '\0';
   //
   //         //}
   //         wcscat(wstrModuleFilePath, L"\\ca2\\");
   //
   //   #ifdef X86
   //         wcscat(wstrModuleFilePath,L"stage\\x86\\");
   //
   //   #else
   //         wide_concatenate(wstrModuleFilePath, L"stage\\x64\\");
   //
   //   #endif
   //
   //         wcscpy(wstrModuleFolder, wstrModuleFilePath);
   //
   //         wstrModuleFilePath.release_buffer();
   //
   //         return string(wstrModuleFolder);
   //
   //
   //      }
   //
   //      if (!GetModuleFileNameW(hmodule, wstrModuleFilePath, (unsigned int)wstrModuleFilePath.length()))
   //      {
   //
   //         return "";
   //
   //      }
   //
   //      wstrModuleFilePath.release_buffer();
   //
   //      LPWSTR pszModuleFileName;
   //
   //      if (!GetFullPathNameW(wstrModuleFilePath, (unsigned int)wstrModuleFilePath.length(), wstrModuleFolder, &pszModuleFileName))
   //      {
   //
   //         return "";
   //
   //      }
   //
   //      wstrModuleFolder.release_buffer();
   //
   //      if(wstrModuleFolder.has_character())
   //      {
   //
   //         wstrModuleFolder.trim_right(L"\\/");
   //
   //      }
   //
   //      return wstrModuleFolder;
   //
   //   #elif defined(__APPLE__)
   //
   //      string str;
   //
   //      {
   //
   ////         str = ::dir::pathfind(getenv("DYLD_LIBRARY_PATH"), "libacme.dylib", "rfs"); // readable - normal file - non zero double_size
   ////
   ////         if(str.has_character())
   ////         {
   ////            str = ::file::path(str).folder();
   ////            goto found;
   ////
   ////         }
   ////
   ////
   ////         str = ::dir::pathfind(getenv("DYLD_FALLBACK_LIBRARY_PATH"), "libacme.dylib", "rfs"); // readable - normal file - non zero double_size
   ////
   ////         if(str.has_character())
   ////         {
   ////            str = ::file::path(str).folder();
   ////            goto found;
   ////
   ////         }
   //
   //         str = get_exe_path();
   //
   //
   //         if(str.has_character())
   //         {
   //            str = ::file::path(str).folder();
   //            goto found;
   //         }
   //
   //
   //      }
   //   found:
   //      ;
   //
   //      return str;
   //
   //   #else
   //
   //      string strModuleFolder;
   //
   //      auto wstrModuleFolder = strModuleFolder.get_buffer(MAX_PATH * 8);
   //
   //      void * handle = dlopen("libacme.so", RTLD_NOW);
   //
   //      if(handle == nullptr)
   //      {
   //
   //         strcpy(wstrModuleFolder, "/ca2/");
   //
   //      }
   //      else
   //      {
   //
   //         link_map * plm;
   //
   //         dlinfo(handle, RTLD_DI_LINKMAP, &plm);
   //
   //         strcpy(wstrModuleFolder, plm->l_name);
   //
   //         dlclose(handle);
   //
   //         strcpy(wstrModuleFolder, ::file_path_folder(wstrModuleFolder));
   //
   //      }
   //
   //      return string(wstrModuleFolder);
   //
   //
   //
   //   #endif
   //
   //
   //   }


//      ::file::path directory_system::module_folder()
//      {
//
//#if defined(UNIVERSAL_WINDOWS)
//
//         wstring wstrModuleFolder(get_buffer, MAX_PATH * 8);
//
//         wstring wstrModuleFilePath(get_buffer, MAX_PATH * 8);
//
//         if (!GetModuleFileNameW(nullptr, wstrModuleFilePath, (unsigned int)wstrModuleFilePath.length()))
//         {
//
//            return "";
//
//         }
//
//         LPWSTR pszModuleFileName;
//
//         if (!GetFullPathNameW(wstrModuleFilePath, (unsigned int)wstrModuleFilePath.length(), wstrModuleFolder, &pszModuleFileName))
//         {
//
//            return "";
//
//         }
//
//         wstrModuleFolder.release_buffer();
//
//         wstrModuleFolder.trim_right(L"\\/");
//
//         return wstrModuleFolder;
//
//#elif defined(WINDOWS)
//
//         wstring wstrModuleFolder(get_buffer, MAX_PATH * 8);
//
//         wstring wstrModuleFilePath(get_buffer, MAX_PATH * 8);
//
//         HMODULE hmodule = ::GetModuleHandleA("acme.dll");
//
//         if (hmodule == nullptr)
//         {
//
//            hmodule = ::GetModuleHandleA("spalib.dll");
//
//         }
//
//         if (hmodule == nullptr)
//         {
//
//            wcscpy(wstrModuleFilePath, _wgetenv(L"PROGRAMFILES(X86)"));
//
//
//            if (wstrModuleFilePath.empty())
//            {
//
//               SHGetSpecialFolderPathW(nullptr, wstrModuleFilePath, CSIDL_PROGRAM_FILES, false);
//
//            }
//
//            wstrModuleFilePath.trim_right(L"\\/");
//
//            wcscat(wstrModuleFilePath, L"\\ca2\\");
//
//#ifdef X86
//
//            wcscat(wstrModuleFilePath, L"stage\\x86\\");
//
//#else
//            wide_concatenate(wstrModuleFilePath, L"stage\\x64\\");
//
//#endif
//
//            wcscpy(wstrModuleFolder, wstrModuleFilePath);
//
//            return string(wstrModuleFolder);
//
//         }
//
//         if (!GetModuleFileNameW(hmodule, wstrModuleFilePath, (unsigned int)wstrModuleFilePath.length()))
//         {
//
//            return "";
//
//         }
//
//         LPWSTR pszModuleFileName;
//
//         if (!GetFullPathNameW(wstrModuleFilePath, (unsigned int)wstrModuleFilePath.length(), wstrModuleFolder, &pszModuleFileName))
//         {
//
//            return "";
//
//         }
//
//         wstrModuleFolder.release_buffer();
//
//         wstrModuleFolder.trim_right(L"\\/");
//
//         return wstrModuleFolder;
//
//#else
//
//         string strModuleFolder;
//
//         auto wstrModuleFolder = strModuleFolder.get_buffer(MAX_PATH * 8);
//
//         throw ::exception(todo);
//
//         return wstrModuleFolder;
//
//#endif
//
//      }


      // bool eat_end_level(string & str, int iLevelCount, const char * pSeparator)
      // {

      //    character_count iLast = str.length() - 1;

      //    if(iLast < 0)
      //       return iLevelCount <= 0;

      //    while(str[iLast] == '/' || str[iLast] == '\\')
      //       iLast--;

      //    for(int i = 0; i < iLevelCount; i++)
      //    {

      //       character_count iFind1 = str.rear_find('/', iLast);

      //       character_count iFind2 = str.rear_find('\\', iLast);

      //       character_count iFind = maximum(iFind1, iFind2);

      //       if(iFind >= iLast)
      //          return false;

      //       if(iFind < 0)
      //          return false;

      //       iLast = iFind;

      //       while(str[iLast] == '/' || str[iLast] == '\\')
      //          iLast--;

      //    }

      //    str = str.substr(0, iLast + 1);

      //    return true;

      // }
      //
      //
      //   string ca2_module_dup()
      //   {
      //
      //      static string * s_pstrCalc = nullptr;
      //
      //      if(s_pstrCalc != nullptr)
      //      {
      //
      //         return *s_pstrCalc;
      //
      //      }
      //
      //      string str;
      //
      //   #ifdef WINDOWS_DESKTOP
      //
      //      wstring wstrModuleFilePath(get_buffer, MAX_PATH * 8);
      //
      //      GetModuleFileNameW(::GetModuleHandleA("acme.dll"), wstrModuleFilePath, MAX_PATH + 1);
      //
      //      str = (const unichar *) wstrModuleFilePath;
      //
      //   #elif defined(LINUX)
      //
      //      void * handle = dlopen("libacme.so", RTLD_NOW);
      //
      //      if(handle == nullptr)
      //         return "";
      //
      //      link_map * plm;
      //
      //      dlinfo(handle, RTLD_DI_LINKMAP, &plm);
      //
      //      string strCa2ModuleFolder = plm->l_name;
      //
      //      dlclose(handle);
      //
      //      str = strCa2ModuleFolder;
      //
      //   #elif defined(UNIVERSAL_WINDOWS)
      //
      //      str = "";
      //
      //   #elif defined(__APPLE__)
      //
      //      {
      //
      //         str = get_exe_path();
      //
      //         if(str.has_character())
      //         {
      //
      //            goto found;
      //
      //         }
      //
      //         str = ::dir::pathfind(::file::path(str).folder(), "libacme.dylib", "rfs"); // readable - normal file - non zero double_size
      //
      //         if(str.has_character())
      //         {
      //
      //            goto found;
      //
      //         }
      //
      //         str = ::dir::pathfind(getenv("DYLD_LIBRARY_PATH"), "libacme.dylib", "rfs"); // readable - normal file - non zero double_size
      //
      //         if(str.has_character())
      //         {
      //
      //            goto found;
      //
      //         }
      //
      //         str = get_exe_path();
      //
      //         if(str.has_character())
      //         {
      //
      //            goto found;
      //
      //         }
      //
      //         str = ::dir::pathfind(getenv("DYLD_FALLBACK_LIBRARY_PATH"), "libacme.dylib", "rfs"); // readable - normal file - non zero double_size
      //
      //         if(str.has_character())
      //         {
      //
      //            goto found;
      //
      //         }
      //
      //      }
      //
      //   found:
      //      ;
      //
      //   #endif
      //
      //      s_pstrCalc = ___new string(str);
      //
      //      return *s_pstrCalc;
      //
      //
      //   }



      //bool directory_system::create(const char * path)
      //{

      //   //if (::file::system_dir::g_pthis == nullptr)
      //   //{

      //   return _create(path);

      //   //}

      //   //return ::file::system_dir::g_pthis->mk(path, ::get_context_system());

      //}

//
//#ifndef WINDOWS_DESKTOP
//
//
//      bool directory_system::create_directory(const char * path)
//      {
//
//         if (is(path))
//         {
//
//            return true;
//
//         }
//
//         string strName;
//
//         ::file::path pathDir;
//
//         character_count iLastPos;
//
//#ifdef UNIVERSAL_WINDOWS
//
//         {
//
//            string strPath = path;
//
//            string strPrefix;
//
//            windows_runtime_folder(strPath, strPrefix);
//
//            pathDir = strPrefix;
//
//            iLastPos = strPrefix.get_length();
//
//         }
//
//#else
//
//         iLastPos = -1;
//
//#endif
//
//         ::file::path_array stra;
//
//         path.ascendants_path(stra);
//
//         ::collection::index i = stra.get_upper_bound();
//
//         for (; i >= 0; i--)
//         {
//
//            string strDir = stra[i];
//
//            if (is(strDir))
//            {
//
//               break;
//
//            }
//
//         }
//
//         if (i < 0)
//         {
//
//            return true;
//
//         }
//
//         for (; i < stra.get_count(); i++)
//         {
//
//            string strDir = stra[i];
//
//            if (::dir::mkdir(strDir))
//            {
//
//            }
//            else
//            {
//
//               auto estatus = ::get_last_status();
//
//               if (estatus == ::error_already_exists)
//               {
//
//                  try
//                  {
//
//                     file_delete(strDir);
//
//                  }
//                  catch (...)
//                  {
//
//                  }
//
//                  string str = stra[i];
//
//                  str.trim_right("\\/");
//
//                  try
//                  {
//
//                     file_delete(str);
//
//                  }
//                  catch (...)
//                  {
//
//                  }
//
//                  if (::dir::mkdir(stra[i]))
//                  {
//
//                     continue;
//
//                  }
//                  else
//                  {
//
//                     estatus = ::get_last_status();
//
//                  }
//
//               }
//
//#ifdef WINDOWS_DESKTOP
//
//               char * pszError;
//
//               FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, nullptr, dwError, 0, (char *)&pszError, 8, nullptr);
//
//               //informationf("         auto psystem = system();
//
//         auto pacmedir = psystem->m_pdirectorysystem;
//
//pacmedir->create CreateDirectoryW last error(%d)=%s", dwError, pszError);
//
//               ::LocalFree(pszError);
//
//               //m_isdirmap.set(stra[i], false);
//
//#endif
//
//               return false;
//
//            }
//
//         }
//
//         return true;
//
//      }
//
//
//#endif


//      ::e_status directory_system::_create_directory(const char * path)
//      {
//
//         wstring wstr;
//
//         if (file_path_is_absolute(path))
//         {
//
//            wstr = "\\\\?\\" + wstring(path);
//
//         }
//         else
//         {
//
//            wstr = path;
//
//         }
//
//         if (!::CreateDirectoryW(wstr, nullptr))
//         {
//
//            DWORD dwLastError = ::GetLastError();
//
//            auto estatus = os_error_to_status()
//
//            return false;
//
//         }
//
////#else
////
////         if (::mkdir(path, S_IRWXU | S_IRWXG | S_IRWXO) != 0)
////         {
////
////            TranslateLastError();
////
////            return false;
////
////         }
////
////         set_last_status(success);
////
////#endif
//
//         return true;
//
//      }



      ::file::path directory_system::module()
      {

#ifdef WINDOWS

         wstring path;
         
         auto p = path.get_buffer(MAX_PATH * 8);

         if (!GetModuleFileNameW(nullptr, p, MAX_PATH * 8))
         {

            return "";

         }
         else
         {

            path.release_buffer();

            auto pathFolder = file_path_folder(string(path));

            return pathFolder;

         }

#else

         return "/acme/stage";

#endif

      }


      //void directory_system::rls(::file::path_array & stra, const scoped_string & str)
      //{
      //   ::collection::count start = stra.get_count();
      //   ls(stra, psz);
      //   ::collection::count end = stra.get_count();
      //   for (::collection::index i = start; i < end; i++)
      //   {
      //      if (is(stra[i]))
      //      {
      //         rls(stra, stra[i]);
      //      }
      //   }

      //}


      //void directory_system::rls_dir(::file::path_array & stra, const scoped_string & str)
      //{

      //   ::collection::count start = stra.get_count();

      //   ls_dir(stra, psz);

      //   ::collection::count end = stra.get_count();

      //   for (::collection::index i = start; i < end; i++)
      //   {

      //      ::file::path path = stra[i];

      //      rls_dir(stra, path);

      //   }

      //}


      bool directory_system::enumerate(::file::listing & listing)
      {

         if (listing.m_pathFinal.is_empty())
         {

            listing.m_pathFinal = listing.m_pathUser;

         }

         //if (!is(listing.m_pathFinal))
         //{

         //   return false;

         //}

         if (!listing.on_start_enumerating(this))
         {

            return true;

         }

         string strRelative(listing.m_pathFinal);

         string strPrefix;

         ::pointer < ::acme_universal_windows::node > pnode = node();

         auto folder = pnode->windows_runtime_folder(this, strRelative, strPrefix, false);

         auto items = folder.GetItemsAsync().get();

         for (unsigned int u = 0; u < items.Size(); u++)
         {

            auto item = items.GetAt(u);

            ::file::path path(item.Path().begin());

            if (items.GetAt(u).IsOfType(::winrt::Windows::Storage::StorageItemTypes::Folder))
            {

               path.m_etype = ::file::e_type_existent_folder;

            }
            else
            {

               path.m_etype = ::file::e_type_existent_file;

            }

            listing.defer_add(path);

         }

         return true;

      }


//      void directory_system::ls_dir(::file::path_array & stra, const scoped_string & str)
//      {
//
//#if defined(LINUX) || defined(__APPLE__) || defined(ANDROID)
//
//         DIR * dirp = opendir(psz);
//
//         if (dirp == nullptr)
//            return;
//
//         dirent * dp;
//
//         while ((dp = readdir(dirp)) != nullptr)
//         {
//            if (dp->d_name[0] == '.')
//            {
//               if (dp->d_name[1] == '\0')
//                  continue;
//               if (dp->d_name[1] == '.')
//               {
//                  if (dp->d_name[2] == '\0')
//                     continue;
//               }
//            }
//            ::file::path strPath = psz / dp->d_name;
//            if (is(strPath))
//            {
//               stra.add(strPath);
//            }
//
//         }
//
//         closedir(dirp);
//
//#elif defined(UNIVERSAL_WINDOWS)
//
//         string strRelative(psz);
//
//         string strPrefix;
//
//         auto folder = windows_runtime_folder(system(), strRelative, strPrefix);
//
//         auto folders = folder.GetFoldersAsync().get();
//
//         for (unsigned int u = 0; u < folders.Size(); u++)
//         {
//
//            stra.add(folders.GetAt(u).Path().begin());
//
//         }
//
//#else
//
//         WIN32_FIND_DATAW FindFileData;
//
//         HANDLE hFind;
//
//         hFind = FindFirstFileW(wstring(psz), &FindFileData);
//
//         if (hFind == INVALID_HANDLE_VALUE)
//            return;
//
//         while (true)
//         {
//
//            if (!windows_file_find_is_dots(FindFileData) && (FindFileData.dwFileAttributes != INVALID_FILE_ATTRIBUTES) && (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
//            {
//
//               stra.add(::file::path(FindFileData.cFileName));
//
//            }
//
//            stra.add(::file::path(FindFileData.cFileName));
//
//            if (!FindNextFileW(hFind, &FindFileData))
//               break;
//
//         }
//
//         FindClose(hFind);
//
//#endif
//
//
//      }
//
//
//      void directory_system::ls_file(::file::path_array & stra, const scoped_string & str)
//      {
//
//#if defined(LINUX) || defined(__APPLE__) || defined(ANDROID)
//
//         DIR * dirp = opendir(psz);
//
//         if (dirp == nullptr)
//            return;
//
//         dirent * dp;
//
//         while ((dp = readdir(dirp)) != nullptr)
//         {
//            if (dp->d_name[0] == '.')
//            {
//               if (dp->d_name[1] == '\0')
//                  continue;
//               if (dp->d_name[1] == '.')
//               {
//                  if (dp->d_name[2] == '\0')
//                     continue;
//               }
//            }
//            ::file::path strPath = psz / dp->d_name;
//            if (!is(strPath))
//            {
//               stra.add(strPath);
//            }
//
//         }
//
//         closedir(dirp);
//
//#elif defined(UNIVERSAL_WINDOWS)
//
//         string strRelative(psz);
//
//         string strPrefix;
//
//         auto folder = windows_runtime_folder(system(), strRelative, strPrefix);
//
//         auto files = folder.GetFilesAsync().get();
//
//         for (unsigned int u = 0; u < files.Size(); u++)
//         {
//
//            stra.add(files.GetAt(u).Path().begin());
//
//         }
//
//
//#else
//
//         WIN32_FIND_DATAW FindFileData;
//
//         HANDLE hFind;
//
//         hFind = FindFirstFileW(wstring(psz), &FindFileData);
//
//         if (hFind == INVALID_HANDLE_VALUE)
//            return;
//
//         while (true)
//         {
//
//            if (!windows_file_find_is_dots(FindFileData) && (FindFileData.dwFileAttributes != INVALID_FILE_ATTRIBUTES) && (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
//            {
//            }
//            else
//            {
//               stra.add(::file::path(FindFileData.cFileName));
//            }
//
//
//            stra.add(::file::path(FindFileData.cFileName));
//
//            if (!FindNextFileW(hFind, &FindFileData))
//               break;
//
//         }
//
//         FindClose(hFind);
//
//#endif

      //}


      ::file::path directory_system::pathfind(const string & pszEnv, const string & pszTopic, const string & pszMode)
      {

         string_array_base stra;

         stra.add_tokens(pszEnv, ":");

         string strCandidate;

         for (int i = 0; i < stra.get_count(); i++)
         {

            if (stra[i].is_empty())
               continue;

            strCandidate = ::file::path(stra[i]) / pszTopic;

            if (m_pfilesystem->exists(strCandidate))
            {
               return strCandidate;
            }

         }

         return "";

      }


      ::file::path directory_system::archive()
      {

#ifdef WINDOWS

         ::file::path pathArchive = getenv("__archive");

         return pathArchive;

#else

         return "/archive";

#endif

      }


      ::file::path directory_system::tool()
      {

         return archive() / "tool-windows";

      }


      //int directory_system::make_path(const scoped_string & str)
      //{


      //   return create(psz) != false;

      //}


//      bool directory_system::_create(const char * pathParam)
//      {
//
//         if (is(pathParam))
//         {
//
//            return true;
//
//         }
//
//         ::file::path path(pathParam);
//
//         string strName;
//
//         ::file::path pathDir;
//
//         character_count iLastPo = -1;
//
//         ::file::path_array stra;
//
//
//         path.ascendants_path(stra);
//
//         ::collection::index i = stra.get_upper_bound();
//
//         for (; i >= 0; i--)
//         {
//
//            string strDir = stra[i];
//
//            if (is(strDir))
//            {
//
//               break;
//
//            }
//
//         }
//
//         if (i < 0)
//         {
//
//            return true;
//
//         }
//
//         for (; i < stra.get_count(); i++)
//         {
//
//            string strDir = stra[i];
//
//            if (create_directory(strDir))
//            {
//
//            }
//            else
//            {
//
//               DWORD dwError = ::GetLastError();
//
//               if (dwError == ERROR_ALREADY_EXISTS)
//               {
//
//                  try
//                  {
//
//                     m_pfilesystem->delete_file(strDir);
//
//                  }
//                  catch (...)
//                  {
//
//                  }
//
//                  string str = stra[i];
//
//                  str.trim_right("\\/");
//
//                  try
//                  {
//
//                     m_pfilesystem->delete_file(str);
//
//                  }
//                  catch (...)
//                  {
//
//                  }
//
//                  if (create_directory(stra[i]))
//                  {
//
//                     continue;
//
//                  }
//                  else
//                  {
//
//                     dwError = ::GetLastError();
//
//                  }
//
//               }
//
//#ifdef WINDOWS_DESKTOP
//
//               WCHAR * pwszError;
//
//               FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, nullptr, dwError, 0, (WCHAR *)&pwszError, 8, nullptr);
//
//               //informationf("         auto psystem = system();
//
////         auto pacmedir = psystem->m_pdirectorysystem;
////
////pacmedir->create CreateDirectoryW last error(%d)=%s", dwError, pszError);
////
//               ::LocalFree(pwszError);
//
//               //m_isdirmap.set(stra[i], false);
//
//#endif
//
//               return false;
//
//            }
//
//         }
//
//         return true;
//
//      }


   //::file::path directory_system::get_current()
   //{

   //   auto size = GetCurrentDirectoryW(0, nullptr);

   //   wstring wstr;

   //   auto buffer = wstr.get_buffer(size);

   //   GetCurrentDirectoryW(size + 1, buffer);

   //   wstr.release_buffer(size);

   //   return wstr;

   //}



} // namespace acme_universal_windows



