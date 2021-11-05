#include "framework.h"
#include "_windows_runtime.h"

extern "C"
void apex_universal_windows_factory_exchange(::factory_map * pfactorymap);


extern "C"
void aura_windows_common_factory_exchange(::factory_map * pfactorymap);


extern "C"
void aura_universal_windows_factory_exchange(::factory_map * pfactorymap)
{

   aura_windows_common_factory_exchange(pfactorymap);

   apex_universal_windows_factory_exchange(pfactorymap);


   pfactorymap->create_factory < ::universal_windows::interaction_impl, ::user::interaction_impl >();

   pfactorymap->create_factory < ::aura::universal_windows::node, ::acme::node >();

}



