#include "framework.h"
#include "node.h"


__FACTORY_EXPORT void windowing_universal_windows_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void node_universal_windows_factory(::factory::factory * pfactory)
{

   windowing_universal_windows_factory(pfactory);

   //add_factory_item < ::windows::console, ::console::console >();
   //add_factory_item < ::windows::crypto, ::crypto::crypto >();
   //add_factory_item < ::windows::ip_enum, ::net::ip_enum >();


   //add_factory_item < ::windows::buffer, ::graphics::graphics >();
   //pfactory->add_factory_item < ::windows::interaction_impl, ::windowing::window >();

   //add_factory_item < ::file::os_watcher, ::file::watcher >();
   //add_factory_item < ::file::os_watch, ::file::watch >();

   //add_factory_item < ::windows::copydesk, ::user::copydesk >();
   //add_factory_item < ::windows::shell_open, ::shell_open >();
   //add_factory_item < ::windows::interprocess_communication_base, ::inteprocess_channel::base >();
   //add_factory_item < ::windows::interprocess_caller, ::interprocess::caller >();
   //add_factory_item < ::windows::interprocess_handler, ::interprocess::handler >();
   //add_factory_item < ::windows::inteprocess_channel, ::inteprocess_channel::inteprocess_channel >();


   //pfactory->add_factory_item < ::windows::interaction_impl, ::windowing::window >();

   pfactory->add_factory_item < ::node_universal_windows::node, ::platform::node >();


}




