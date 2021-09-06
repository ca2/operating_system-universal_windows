#include "framework.h"


extern "C"
void acme_universal_windows_factory_exchange(::factory_map* pfactorymap);


extern "C"
void apex_windows_common_factory_exchange(::factory_map * pfactorymap);


extern "C"
void apex_universal_windows_factory_exchange(::factory_map * pfactorymap)
{

   
   apex_windows_common_factory_exchange(pfactorymap);


   acme_universal_windows_factory_exchange(pfactorymap);



   pfactorymap->create_factory < ::universal_windows::file_context, ::file_context >();
   pfactorymap->create_factory < ::universal_windows::file_system, ::file_system >();
   pfactorymap->create_factory < ::universal_windows::dir_context, ::dir_context >();
   pfactorymap->create_factory < ::universal_windows::dir_system, ::dir_system >();

   pfactorymap->create_factory < ::universal_windows::os_context, ::os_context >();

   pfactorymap->create_factory < ::apex::windows_common::node, ::acme::node >();


}



