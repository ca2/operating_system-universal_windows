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

   //pfactorymap->create_factory < ::universal_windows::interprocess_communication, ::interprocess_communication::interprocess_communication >();
   pfactorymap->create_factory < ::universal_windows::interprocess_communication_rx, ::interprocess_communication::rx >();
   pfactorymap->create_factory < ::universal_windows::interprocess_communication_tx, ::interprocess_communication::tx >();

   pfactorymap->create_factory < ::file::os_watcher, ::file::watcher >();
   pfactorymap->create_factory < ::file::os_watch, ::file::watch >();

   pfactorymap->create_factory < ::apex::universal_windows::node, ::acme::node >();


}



