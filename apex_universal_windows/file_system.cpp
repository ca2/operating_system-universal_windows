#include "framework.h"
#include "apex/operating_system.h"


namespace universal_windows
{


   file_system::file_system()
   {

   }


   file_system::~file_system()
   {

   }


   ::e_status file_system::init_system()
   {

      auto estatus = ::file_system::init_system();

      if (!estatus)
      {

         return estatus;

      }

      return estatus;

   }

   
   ::e_status file_system::update_module_path()
   {

      //m_pathModule = ::get_module_path(nullptr);

      //m_pathCa2Module = ::get_module_path(::GetModuleHandleA("apex.dll"));

      m_pathModule.Empty();

      m_pathCa2Module.Empty();

      return true;

   }



} // namespace windows


