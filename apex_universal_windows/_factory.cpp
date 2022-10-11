#include "framework.h"
#include "file_context.h"
#include "file_system.h"
#include "dir_context.h"
#include "dir_system.h"
#include "os_context.h"
#include "interprocess_caller.h"
#include "interprocess_target.h"
#include "file_os_watcher.h"
//#include "file_os_watch.h"
#include "node.h"


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

   //pfactory->add_factory_item < ::universal_windows::inteprocess_channel, ::inteprocess_channel::inteprocess_channel >();
   pfactory->add_factory_item < ::apex_universal_windows::interprocess_caller, ::interprocess::caller >();
   pfactory->add_factory_item < ::apex_universal_windows::interprocess_target, ::interprocess::target >();

   pfactory->add_factory_item < ::apex_universal_windows::os_watcher, ::file::watcher >();
   pfactory->add_factory_item < ::apex_universal_windows::os_watch, ::file::watch >();

   pfactory->add_factory_item < ::apex_universal_windows::node, ::acme::node >();


}



