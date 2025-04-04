// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen  - Honoring Thomas Borregaard Soerensen MY ONLY LORD
// recreated by Camilo 2021-02-01 23:29
#pragma once


namespace windowing_universal_windows
{


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS buffer :
      virtual public ::graphics::double_buffer,
      virtual public ::graphics::bitmap_source_buffer
   {
   public:


      class os_buffer
      {
      public:


         os_buffer();
         ~os_buffer();


         ::pixmap                      m_pixmap;
         HBITMAP                       m_hbitmap;
         HBITMAP                       m_hbitmapOld;
         HDC                           m_hdc;


         void destroy_buffer();


      };


      os_buffer                     m_osbuffera[2];
      HDC                           m_hdcScreen;
      bool                          m_bWindowDC;
      oswindow                      m_hwndIpc;
      ::int_rectangle               m_rectangleLast;


      buffer();
      virtual ~buffer();


      virtual ::e_status initialize_graphics_graphics(::windowing::window * pimpl) override;


      virtual bool update_buffer(const ::int_size & size, int iStride = -1) override;
      virtual void destroy_buffer() override;
      virtual bool update_window() override;


      virtual bool update_window(::image::image * pimage) override;


      virtual ::draw2d::graphics * on_begin_draw() override;


      bool create_os_buffer(const ::int_size & size, int iStride = -1);
      void destroy_os_buffer();


      virtual bool buffer_lock_round_swap_key_buffers() override;

      inline HWND get_hwnd() const { return (HWND) m_pwindow->get_os_data();  }

   };


} // namespace windowing_universal_windows



