#include "framework.h"


__FACTORY_EXPORT void acme_windows_common_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_universal_windows_factory(::factory::factory * pfactory)
{

   
   acme_windows_common_factory(pfactory);

   pfactory->add_factory_item < ::universal_windows::acme_dir, ::acme_dir >();
   pfactory->add_factory_item < ::universal_windows::acme_file, ::acme_file >();
   pfactory->add_factory_item < ::universal_windows::acme_path, ::acme_path >();

   //pfactory->add_factory_item < ::universal_windows::file, ::file::file >();
   pfactory->add_factory_item < ::universal_windows::native_buffer, ::file::file >();

   pfactory->add_factory_item < ::acme::universal_windows::node, ::acme::node >();


}



