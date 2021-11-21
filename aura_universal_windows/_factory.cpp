#include "framework.h"
#include "_windows_runtime.h"

__FACTORY_EXPORT void apex_universal_windows_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_windows_common_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_universal_windows_factory(::factory::factory * pfactory)
{

   aura_windows_common_factory(pfactory);

   apex_universal_windows_factory(pfactory);


   pfactory->add_factory_item < ::universal_windows::interaction_impl, ::user::interaction_impl >();

   pfactory->add_factory_item < ::aura::universal_windows::node, ::acme::node >();

}



