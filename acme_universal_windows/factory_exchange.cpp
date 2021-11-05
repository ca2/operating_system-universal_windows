#include "framework.h"


extern "C"
void acme_windows_common_factory_exchange(::factory_map * pfactorymap);


extern "C"
void acme_universal_windows_factory_exchange(::factory_map * pfactorymap)
{

   
   acme_windows_common_factory_exchange(pfactorymap);

   pfactorymap->create_factory < ::universal_windows::acme_dir, ::acme_dir >();
   pfactorymap->create_factory < ::universal_windows::acme_file, ::acme_file >();
   pfactorymap->create_factory < ::universal_windows::acme_path, ::acme_path >();

   //pfactorymap->create_factory < ::universal_windows::file, ::file::file >();
   pfactorymap->create_factory < ::universal_windows::native_buffer, ::file::file >();

   pfactorymap->create_factory < ::acme::universal_windows::node, ::acme::node >();


}



