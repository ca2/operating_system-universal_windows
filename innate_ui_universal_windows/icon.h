// Created by camilo on 2024-09-13 07:18 <3ThomasBorregaardSorensen!!
#pragma once


#include "apex/innate_ui/icon.h"


namespace innate_ui_universal_windows
{


   class CLASS_DECL_INNATE_UI_UNIVERSAL_WINDOWS icon :
      virtual public ::innate_ui::icon
   {
   public:


      HICON m_hicon;

      icon();
      ~icon() override;



   };


} // namespace innate_ui



