#include "framework.h"
#include "directory_system.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme_universal_windows/directory_system.h"


#include "acme/_operating_system.h"


#include <Shlobj.h>


namespace acme_universal_windows
{


   directory_system::directory_system()
   {


   }


   directory_system::~directory_system()
   {

   }



   void directory_system::initialize(::particle* pparticle)
   {

      //auto estatus =

      ::directory_system::initialize(pparticle);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      m_pathInstall = directory_system()->install();

      //directory_system()->m_pplatformdir->_shell_get_special_folder_path(
        // nullptr,
         //m_strCommonAppData,
         //CSIDL_COMMON_APPDATA,
         //false);
      //shell_get_special_folder_path(
      // nullptr,
      //m_pathProfile,
      //CSIDL_PROFILE,
      //false);

      //m_pathHome = directory_system()->m_pplatformdir->_get_known_folder(FOLDERID_Profile);

      string strHome = getenv("USERPROFILE");

      strHome.trim();

      if (strHome.has_char())
      {

         m_pathHome = strHome;

      }
      else
      {

         m_pathHome = m_pathInstall / "home";

      }

      //m_pathCa2Config = directory_system()->ca2roaming();

      m_pathCa2Config = m_pathInstall / "ca2/config";

      m_strCommonAppData = m_pathInstall / "commonappdata";

      m_strAppData = m_pathInstall / "appdata";

      //directory_system()->m_pplatformdir->_shell_get_special_folder_path(
      //   nullptr,
      //   m_strPrograms,
      //   CSIDL_PROGRAMS,
      //   false);
      //directory_system()->m_pplatformdir->_shell_get_special_folder_path(
      //   nullptr,
      //   m_strCommonPrograms,
      //   CSIDL_COMMON_PROGRAMS,
      //   false);

      {

         //string strRelative;
         //strRelative = install();
         //index iFind = strRelative.find(':');
         //if (iFind >= 0)
         //{
         //   strsize iFind1 = strRelative.rear_find("\\", iFind);
         //   strsize iFind2 = strRelative.rear_find("/", iFind);
         //   strsize iStart = maximum(iFind1 + 1, iFind2 + 1);
         //   strRelative = strRelative.left()(iFind - 1) + "_" + strRelative.substr(iStart, iFind - iStart) + strRelative.substr(iFind + 1);
         //}



      }

      if (m_strTimeFolder.is_empty())
      {

         m_strTimeFolder = directory_system()->appdata() / "time";

      }

      if (m_strNetSeedFolder.is_empty())
      {

         m_strNetSeedFolder = directory_system()->install() / "net";

      }

      directory_system()->create(m_strTimeFolder);
      //xxdebug_box("win_dir::initialize (m_strTimeFolder)", "win_dir::initialize", 0);

      if (!directory_system()->is(m_strTimeFolder))
      {
         throw exception(error_failed, "Time folder doesn't exist");

      }

      /*     auto psystem = system();

     auto pacmedir = psystem->m_pdirectorysystem;*/

      directory_system()->create(m_strTimeFolder / "time");

      //xxdebug_box("win_dir::initialize", "win_dir::initialize", 0);

      //return ::success;

   }


   void directory_system::init_system()
   {

      //auto estatus = 

      ::directory_system::init_system();

      //if (!estatus)
      //{

      //   return estatus;

      //}


      //return ::success;

   }


} // namespace acme_universal_windows



