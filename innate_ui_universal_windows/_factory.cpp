#include "framework.h"
#include "dialog.h"
#include "window.h"
#include "button.h"
#include "icon.h"
#include "still.h"
#include "innate_ui.h"



IMPLEMENT_FACTORY(innate_ui_universal_windows)
{

   pfactory->add_factory_item < ::innate_ui_universal_windows::window, ::innate_ui::window >();
   pfactory->add_factory_item < ::innate_ui_universal_windows::dialog, ::innate_ui::dialog >();
   
   
   pfactory->add_factory_item < ::innate_ui_universal_windows::button, ::innate_ui::button >();
   pfactory->add_factory_item < ::innate_ui_universal_windows::still, ::innate_ui::still >();

   
   pfactory->add_factory_item < ::innate_ui_universal_windows::icon, ::innate_ui::icon >();


   pfactory->add_factory_item < ::innate_ui_universal_windows::innate_ui, ::innate_ui::innate_ui >();

}



