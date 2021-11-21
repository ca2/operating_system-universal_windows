#include "framework.h"


__FACTORY_EXPORT void aura_universal_windows_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void windowing_universal_windows_factory(::factory::factory * pfactory)
{

   aura_universal_windows_factory(pfactory);

   pfactory->add_factory_item < ::windowing_universal_windows::windowing, ::windowing::windowing >();
   pfactory->add_factory_item < ::windowing_universal_windows::window, ::windowing::window >();
   pfactory->add_factory_item < ::windowing_universal_windows::display, ::windowing::display >();
   pfactory->add_factory_item < ::windowing_universal_windows::display >();
   pfactory->add_factory_item < ::windowing_universal_windows::buffer, ::graphics::graphics >();
   //pfactory->add_factory_item < ::windowing_universal_windows::notify_icon, ::user::notify_icon >();
   pfactory->add_factory_item < ::windowing_universal_windows::cursor, ::windowing::cursor >();
   pfactory->add_factory_item < ::windowing_universal_windows::icon, ::windowing::icon >();
   pfactory->add_factory_item < ::windowing_universal_windows::shell, ::user::shell >();
   pfactory->add_factory_item < ::windowing_universal_windows::copydesk, ::user::copydesk >();
   //pfactory->add_factory_item < imm_client, ::user::text_composition_client >();

   pfactory->add_factory_item < ::windowing_universal_windows::keyboard, ::windowing::keyboard >();

   pfactory->add_factory_item < ::windowing_universal_windows::node, ::acme::node >();

}
