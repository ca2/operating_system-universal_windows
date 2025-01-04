#include "framework.h"
#include "node.h"
//#include "interaction_impl.h"
#include "hardware/device_group.h"
#include "hardware/devices.h"


__FACTORY_EXPORT void apex_universal_windows_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_windows_common_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_universal_windows_factory(::factory::factory * pfactory)
{

   aura_windows_common_factory(pfactory);

   apex_universal_windows_factory(pfactory);


   //pfactory->add_factory_item < ::aura_universal_windows::interaction_impl, ::windowing::window >();

   pfactory->add_factory_item < ::aura_universal_windows::node, ::platform::node >();

   pfactory->add_factory_item < ::aura_universal_windows::hardware::device_group, ::hardware::device_group >();
   pfactory->add_factory_item < ::aura_universal_windows::hardware::devices, ::hardware::devices >();

}



