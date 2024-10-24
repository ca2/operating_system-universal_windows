#include "framework.h"
#include "file_context.h"
#include "file_system.h"
#include "directory_context.h"
#include "directory_system.h"
#include "file_watcher.h"
#include "directory_system.h"
#include "file_system.h"
#include "path_system.h"
#include "node.h"

__FACTORY_EXPORT void acme_windows_common_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_universal_windows_factory(::factory::factory * pfactory)
{

   
   acme_windows_common_factory(pfactory);

   pfactory->add_factory_item < ::acme_universal_windows::directory_system, ::directory_system >();
   pfactory->add_factory_item < ::acme_universal_windows::file_system, ::file_system >();
   pfactory->add_factory_item < ::acme_universal_windows::path_system, ::path_system >();


   pfactory->add_factory_item < ::acme_universal_windows::file_context, ::file_context >();
   pfactory->add_factory_item < ::acme_universal_windows::file_system, ::file_system >();
   pfactory->add_factory_item < ::acme_universal_windows::directory_context, ::directory_context >();
   pfactory->add_factory_item < ::acme_universal_windows::directory_system, ::directory_system >();

   //pfactory->add_factory_item < ::universal_windows::file, ::file::file >();
   //pfactory->add_factory_item < ::universal_windows::native_buffer, ::file::file >();

   pfactory->add_factory_item < ::acme_universal_windows::watcher, ::file::watcher >();
   pfactory->add_factory_item < ::acme_universal_windows::watch, ::file::watch >();

   pfactory->add_factory_item < ::acme_universal_windows::node, ::platform::node >();


}



