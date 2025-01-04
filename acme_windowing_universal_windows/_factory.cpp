#include "framework.h"
//#include "display.h"
#include "window.h"
#include "windowing.h"


IMPLEMENT_FACTORY(acme_windowing_universal_windows)
{

   //pfactory->add_factory_item < ::universal_windows::acme::windowing::display, ::acme::windowing::display >();
   pfactory->add_factory_item < ::universal_windows::acme::windowing::window, ::acme::windowing::window >();
   pfactory->add_factory_item < ::universal_windows::acme::windowing::windowing, ::acme::windowing::windowing >();

}


