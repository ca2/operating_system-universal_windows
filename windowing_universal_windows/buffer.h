#pragma once


#include "aura/graphics/graphics/bitmap_source_buffer.h"
#include "direct2d/direct2d.h"
#include <wincodec.h>
#include "acme/operating_system/universal_windows/_winrt_foundation.h"



namespace windowing_universal_windows
{


   class graphics_device_lock
   {
   public:

      graphics_device_lock()
      {

         direct2d::direct2d()->m_d2dMultithread->Enter();

      }


      ~graphics_device_lock()
      {

         direct2d::direct2d()->m_d2dMultithread->Leave();

      }
   };

   
   enum enum_phase
   {

      e_phase_draw,
      e_phase_present,

   };


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS buffer :
      virtual public ::graphics::bitmap_source_buffer
   {
   public:



      enum_phase                                            m_ephase;

      ::logic::boolean                                      m_tristateCoreWindowVisible;
      bool                                                  m_bWindowSizeChangeInProgress;
      bool                                                  m_b3D;
      ::particle_pointer                              m_pparticleMutexDc;
      int_size                                              m_size;
      ::int_size                                            m_sizeBuffer;
      ::pointer < window >                                  m_pwindow;
      ::pointer < ::graphics::buffer_item >                 m_pbufferitem;
      bool                                                  m_bInitialized;
      bool                                                  m_bInit;
      //::image::image_pointer                                       m_pimage;
      bool                                                  m_bCreated;
      ::winrt::Windows::Foundation::Rect                    m_windowBounds;


     /* direct2d_buffer();
      ~direct2d_buffer() override;*/


      //virtual void defer_resize_top_level_windows();

      //protected private:
      //winrt::agile_ref<::winrt::Windows::UI::Core::CoreWindow>  m_window;

      // DirectWrite & Windows Imaging Component Objects.
      comptr<IDWriteFactory1>         m_pwritefactory;
      comptr<IWICImagingFactory2>     m_pimagingfactory;

      // DirectX Core Objects. Required for 2D and 3D.
      //comptr<ID3D11Device1>           m_d3dDevice;
      //comptr<ID3D11DeviceContext1>    m_d3dContext;
      comptr<IDXGISwapChain1>         m_pswapchain;
      comptr<ID3D11RenderTargetView>  m_prendertargetview;

      // Direct2D Rendering Objects. Required for 2D.
      //comptr<ID2D1Device>             m_d2dDevice;
      comptr<ID2D1DeviceContext>      m_pdevicecontext;
      comptr<ID2D1Bitmap1>            m_pbitmap;

      // Direct3D Rendering Objects. Required for 3D.
      comptr<ID3D11DepthStencilView>  m_pstencilview;
      // Cached renderer properties.
      D3D_FEATURE_LEVEL                               m_featureLevel;
      ::winrt::Windows::Foundation::Size                       m_renderTargetSize;
      float                                           m_dDpi;
      float                                           m_dDpiIni;
      //bool                                            m_windowSizeChangeInProgress;



      //comptr<ID2D1SolidColorBrush>                    m_blackBrush;
      //comptr<IDWriteTextFormat>                       m_textFormat;
      //comptr<IDWriteTypography>                       m_textTypography;
      //comptr<IDWriteTextLayout>                       m_textLayout;
      //SampleOverlay^                                                  m_sampleOverlay;


      //class os_buffer :
      //   virtual public ::object
      //{
      //public:


      //   os_buffer();
      //   virtual ~os_buffer();


      //   ::pixmap                      m_pixmap;
      //   HBITMAP                       m_hbitmap;
      //   HBITMAP                       m_hbitmapOld;
      //   HDC                           m_hdc;


      //   void destroy_buffer();


      //};

      //comptr<ID2D1DeviceContext>      m_pd2d1devicecontext;
      //app  ^        m_pframeworkview;

      ::draw2d::graphics_pointer       m_pdraw2dgraphics;
      D2D1_COLOR_F                     m_d2d1colorfBackground;


      buffer();
      ~buffer() override;



      void initialize_graphics_graphics(::windowing::window* pimpl) override;


      virtual bool create_buffer(const ::int_size& size, int iStride = -1);
      void destroy_buffer() override;

      void on_after_graphical_update() override;

      //bool update_screen() override;

      void update_screen() override;

      ID2D1DeviceContext * get_device_context();

      bool is_single_buffer_mode() const override;


      void on_update_screen(::graphics::buffer_item * pimage) override;


      bool _on_begin_draw(::graphics::buffer_item * pbufferitem) override;

      void on_end_draw() override;


      virtual bool create_os_buffer(const ::int_size& size, int iStride = -1);
      virtual void destroy_os_buffer();


      bool update_buffer(::graphics::buffer_item * pbufferitem) override;


      bool buffer_lock_round_swap_key_buffers() override;
      //::aura::application * get_application() const
      //{

      //   return get_application();

      //}


      virtual bool defer_init();

      //virtual void Initialize(::winrt::Windows::UI::Core::CoreWindow window, float dpi);
      virtual void HandleDeviceLost();
      virtual void CreateDeviceIndependentResources();
      virtual void CreateDeviceResources();
      virtual void SetDpi(float dpi);
      virtual void OnChangeDpi(float dpi);
      virtual void OnChangeTheme();
      virtual void UpdateForWindowSizeChange();
      virtual void CreateWindowSizeDependentResources();
      virtual void DestroyWindowSizeDependentResources();
      //virtual HRESULT Render();
      virtual void Present();
      void ValidateDevice();

      virtual void OnWindowSizeChange();


      virtual ::graphics::buffer_item * get_buffer_item();
      virtual ::graphics::buffer_item * get_screen_item();


   };


} // namespace windowing_universal_windows



