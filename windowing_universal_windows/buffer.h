﻿#pragma once


namespace windowing_universal_windows
{

   
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

      ::logic::bit                                          m_bCoreWindowVisible;
      bool                                                  m_bWindowSizeChangeInProgress;
      bool                                                  m_b3D;
      ::mutex                                               m_mutexDc;
      size_i32                                              m_size;
      ::size_i32                                            m_sizeBuffer;
      __pointer(window)                                     m_pwindow;
      bool                                                  m_bInitialized;
      bool                                                  m_bInit;
      ::image_pointer                                       m_pimage;
      bool                                                  m_bCreated;
      ::winrt::Windows::Foundation::Rect                    m_windowBounds;


     /* direct2d_buffer();
      ~direct2d_buffer() override;*/


      //virtual void defer_resize_top_level_windows();

      //protected private:
      //winrt::agile_ref<::winrt::Windows::UI::Core::CoreWindow>  m_window;

      // DirectWrite & Windows Imaging Component Objects.
      Microsoft::WRL::ComPtr<IDWriteFactory1>         m_dwriteFactory;
      Microsoft::WRL::ComPtr<IWICImagingFactory2>     m_wicFactory;

      // DirectX Core Objects. Required for 2D and 3D.
      //Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice;
      //Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext;
      Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain;
      Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_d3dRenderTargetView;

      // Direct2D Rendering Objects. Required for 2D.
      //Microsoft::WRL::ComPtr<ID2D1Device>             m_d2dDevice;
      Microsoft::WRL::ComPtr<ID2D1DeviceContext>      m_pd2d1devicecontext;
      Microsoft::WRL::ComPtr<ID2D1Bitmap1>            m_d2dTargetBitmap;

      // Direct3D Rendering Objects. Required for 3D.
      Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_d3dDepthStencilView;
      // Cached renderer properties.
      D3D_FEATURE_LEVEL                               m_featureLevel;
      ::winrt::Windows::Foundation::Size                       m_renderTargetSize;
      float                                           m_dpi;
      float                                           m_dpiIni;
      //bool                                            m_windowSizeChangeInProgress;



      //Microsoft::WRL::ComPtr<ID2D1SolidColorBrush>                    m_blackBrush;
      //Microsoft::WRL::ComPtr<IDWriteTextFormat>                       m_textFormat;
      //Microsoft::WRL::ComPtr<IDWriteTypography>                       m_textTypography;
      //Microsoft::WRL::ComPtr<IDWriteTextLayout>                       m_textLayout;
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

      //Microsoft::WRL::ComPtr<ID2D1DeviceContext>      m_pd2d1devicecontext;
      //app  ^        m_pframeworkview;

      ::draw2d::graphics_pointer       m_pdraw2dgraphics;


      buffer();
      ~buffer() override;



      virtual ::e_status initialize_graphics_graphics(::user::interaction_impl* pimpl) override;


      virtual bool create_buffer(const ::size_i32& size, int iStride = -1);
      virtual void destroy_buffer();
      virtual bool update_window();


      ID2D1DeviceContext * get_device_context();


      virtual bool update_window(::image* pimage);


      virtual ::draw2d::graphics* on_begin_draw() override;

      virtual void on_end_draw();


      bool create_os_buffer(const ::size_i32& size, int iStride = -1);
      void destroy_os_buffer();


      bool update_buffer(const ::size_i32 & size, int iStrideParam = -1) override;


      virtual bool buffer_lock_round_swap_key_buffers() override;
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
      virtual void UpdateForWindowSizeChange();
      virtual void CreateWindowSizeDependentResources();
      virtual void DestroyWindowSizeDependentResources();
      //virtual HRESULT Render();
      virtual void Present();
      void ValidateDevice();

      virtual void OnWindowSizeChange();

   };


} // namespace windowing_universal_windows


