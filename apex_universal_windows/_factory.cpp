#include "framework.h"


__FACTORY_EXPORT void acme_universal_windows_factory(::factory::factory* pfactory);


__FACTORY_EXPORT void apex_windows_common_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void apex_universal_windows_factory(::factory::factory * pfactory)
{

   
   apex_windows_common_factory(pfactory);


   acme_universal_windows_factory(pfactory);



   pfactory->add_factory_item < ::apex_universal_windows::file_context, ::file_context >();
   pfactory->add_factory_item < ::apex_universal_windows::file_system, ::file_system >();
   pfactory->add_factory_item < ::apex_universal_windows::dir_context, ::dir_context >();
   pfactory->add_factory_item < ::apex_universal_windows::dir_system, ::dir_system >();

   pfactory->add_factory_item < ::apex_universal_windows::os_context, ::os_context >();

   //pfactory->add_factory_item < ::universal_windows::interprocess_communication, ::interprocess_communication::interprocess_communication >();
   pfactory->add_factory_item < ::apex_universal_windows::interprocess_communication_rx, ::interprocess_communication::rx >();
   pfactory->add_factory_item < ::apex_universal_windows::interprocess_communication_tx, ::interprocess_communication::tx >();

   pfactory->add_factory_item < ::apex_universal_windows::os_watcher, ::file::watcher >();
   pfactory->add_factory_item < ::apex_universal_windows::os_watch, ::file::watch >();

   pfactory->add_factory_item < ::apex_universal_windows::node, ::acme::node >();


}



