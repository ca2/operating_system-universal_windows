#include "framework.h"
#include "windowing.h"
#include "window.h"
#include "display.h"
#include "buffer.h"
#include "cursor.h"
#include "icon.h"
#include "shell.h"
#include "copydesk.h"
#include "keyboard.h"
#include "node.h"
#include "aura/windowing/desktop_environment.h"
#include "aura/windowing/monitor.h"


__FACTORY_EXPORT void aura_universal_windows_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void windowing_universal_windows_factory(::factory::factory * pfactory)
{

   aura_universal_windows_factory(pfactory);

   pfactory->add_factory_item < ::windowing_universal_windows::windowing, ::acme::windowing::windowing >();
   pfactory->add_factory_item < ::windowing_universal_windows::window, ::acme::windowing::window >();
   pfactory->add_factory_item < ::windowing_universal_windows::display, ::acme::windowing::display >();
   pfactory->add_factory_item < ::windowing_universal_windows::display >();
   pfactory->add_factory_item < ::windowing_universal_windows::buffer, ::graphics::graphics >();
   pfactory->add_factory_item < ::windowing::monitor >();
   //pfactory->add_factory_item < ::windowing_universal_windows::notify_icon, ::user::notify_icon >();
   pfactory->add_factory_item < ::windowing_universal_windows::cursor, ::windowing::cursor >();
   pfactory->add_factory_item < ::windowing_universal_windows::icon, ::windowing::icon >();
   pfactory->add_factory_item < ::windowing_universal_windows::shell, ::user::shell >();
   pfactory->add_factory_item < ::windowing_universal_windows::copydesk, ::user::copydesk >();
   //pfactory->add_factory_item < imm_client, ::user::text_composition_client >();

   pfactory->add_factory_item < ::windowing_universal_windows::keyboard, ::windowing::keyboard >();

   pfactory->add_factory_item < ::windowing::desktop_environment >();

}
