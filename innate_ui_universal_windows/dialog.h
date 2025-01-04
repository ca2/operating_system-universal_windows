// Created by camilo on 2024-09-12 22:34 <3ThomasBorregaardSorensen!!
#pragma once


#include "apex/innate_ui/dialog.h"
#include "window.h"


namespace innate_ui_universal_windows
{


   class CLASS_DECL_INNATE_UI_UNIVERSAL_WINDOWS dialog :
      virtual public ::innate_ui_universal_windows::window,
      virtual public ::innate_ui::dialog
   {
   public:



      dialog();
      ~dialog() override;

      void create() override;
      void _create() override;
      //void _get_class(WNDCLASSEXW & wcex);

   };


} // namespace innate_ui_universal_windows




