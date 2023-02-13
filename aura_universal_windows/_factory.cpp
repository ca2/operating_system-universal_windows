#include "framework.h"
#include "node.h"
#include "interaction_impl.h"
#include "hardware_devices.h"


__FACTORY_EXPORT void apex_universal_windows_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_windows_common_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_universal_windows_factory(::factory::factory * pfactory)
{

   aura_windows_common_factory(pfactory);

   apex_universal_windows_factory(pfactory);


   pfactory->add_factory_item < ::aura_universal_windows::interaction_impl, ::user::interaction_impl >();

   pfactory->add_factory_item < ::aura_universal_windows::node, ::acme::node >();

   pfactory->add_factory_item < ::aura_universal_windows::devices, ::hardware::devices >();

}



