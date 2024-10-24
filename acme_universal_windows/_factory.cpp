#include "framework.h"
#include "file_context.h"
#include "file_system.h"
#include "dir_context.h"
#include "dir_system.h"
#include "file_watcher.h"
#include "acme_directory.h"
#include "acme_file.h"
#include "acme_path.h"
#include "node.h"

__FACTORY_EXPORT void acme_windows_common_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_universal_windows_factory(::factory::factory * pfactory)
{

   
   acme_windows_common_factory(pfactory);

   pfactory->add_factory_item < ::acme_universal_windows::acme_directory, ::acme_directory >();
   pfactory->add_factory_item < ::acme_universal_windows::acme_file, ::acme_file >();
   pfactory->add_factory_item < ::acme_universal_windows::acme_path, ::acme_path >();


   pfactory->add_factory_item < ::acme_universal_windows::file_context, ::file_context >();
   pfactory->add_factory_item < ::acme_universal_windows::file_system, ::file_system >();
   pfactory->add_factory_item < ::acme_universal_windows::dir_context, ::dir_context >();
   pfactory->add_factory_item < ::acme_universal_windows::dir_system, ::dir_system >();

   //pfactory->add_factory_item < ::universal_windows::file, ::file::file >();
   //pfactory->add_factory_item < ::universal_windows::native_buffer, ::file::file >();

   pfactory->add_factory_item < ::acme_universal_windows::watcher, ::file::watcher >();
   pfactory->add_factory_item < ::acme_universal_windows::watch, ::file::watch >();

   pfactory->add_factory_item < ::acme_universal_windows::node, ::platform::node >();


}



