// created by Camilo CamiloSasuke<3ThomasBorregaardSoerensen
// recreated by Camilo 2021-02-03 22:01 BRT
#pragma once


#include "aura/windowing/cursor.h"


namespace windowing_universal_windows
{


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS cursor :
      virtual public ::windowing::cursor
   {
   public:


      cursor(HCURSOR hcursor = nullptr);
      ~cursor() override;


      void _create_os_cursor() override;

      inline HCURSOR get_hcursor() const { return (HCURSOR)get_os_data(); }

      inline void set_hcursor(HCURSOR hcursor) { set_os_data(hcursor); }

      void _load_default_cursor(enum_cursor ecursor);

      void _create_from_image(const ::image::image* pimage, int xHotspot, int yHotspot);


   };


} // namespace windowing_universal_windows



