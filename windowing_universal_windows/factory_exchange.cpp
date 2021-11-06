#include "framework.h"


extern "C"
void aura_universal_windows_factory_exchange(::factory_map * pfactorymap);


extern "C"
void windowing_universal_windows_factory_exchange(::factory_map * pfactorymap)
{

   aura_universal_windows_factory_exchange(pfactorymap);

   pfactorymap->create_factory < ::windowing_universal_windows::windowing, ::windowing::windowing >();
   pfactorymap->create_factory < ::windowing_universal_windows::window, ::windowing::window >();
   pfactorymap->create_factory < ::windowing_universal_windows::display, ::windowing::display >();
   pfactorymap->create_factory < ::windowing_universal_windows::display >();
   pfactorymap->create_factory < ::windowing_universal_windows::buffer, ::graphics::graphics >();
   //pfactorymap->create_factory < ::windowing_universal_windows::notify_icon, ::user::notify_icon >();
   pfactorymap->create_factory < ::windowing_universal_windows::cursor, ::windowing::cursor >();
   pfactorymap->create_factory < ::windowing_universal_windows::icon, ::windowing::icon >();
   pfactorymap->create_factory < ::windowing_universal_windows::shell, ::user::shell >();
   pfactorymap->create_factory < ::windowing_universal_windows::copydesk, ::user::copydesk >();
   //pfactorymap->create_factory < imm_client, ::user::text_composition_client >();

   pfactorymap->create_factory < ::windowing_universal_windows::keyboard, ::windowing::keyboard >();

   pfactorymap->create_factory < ::windowing_universal_windows::node, ::acme::node >();

}
