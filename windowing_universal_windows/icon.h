// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen - Honoring Thomas Borregaard Soerensen My ONLY GOD
// recreated by Camilo 2021-02-01 16:43
#pragma once


#include "aura/windowing/icon.h"


namespace windowing_universal_windows
{


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS icon :
      virtual public ::windowing::icon
   {
   public:


      //map < ::int_size, HICON >              m_iconmap;

      ::file::path                           m_path;

      map < ::int_size, ::image::image_pointer >      m_imagemap;

      
      icon();
      ~icon() override;


      void load_file(const ::scoped_string & scopedstrPath) override;

      void load_app_tray_icon(const ::scoped_string & scopedstrApp) override;

      virtual bool add_icon(HICON hicon);

      void get_sizes(::int_size_array & a) override;

      ::image::image_pointer get_image(const ::int_size & size) override;

      virtual ::image::image_pointer _create_image(const ::int_size & size);


      void _erase_all();

      
   };


} // namespace windowing_universal_windows



