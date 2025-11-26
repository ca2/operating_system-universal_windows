#include "framework.h"
////#include "aura/message.h"
#include "buffer.h"
#include "window.h"
#include "windowing.h"
#include <stdio.h>
#include "directx/directx.h"
#include "aura/graphics/draw2d/graphics.h"
#include "aura/graphics/draw2d/lock.h"
//#include "aura/graphics/image/_image.h"
#include "aura/windowing/window.h"
//#include "aura_universal_windows/interaction_impl.h"
#include "aura/platform/session.h"
#include "aura/platform/system.h"
#include "aura/user/user/user.h"
#include "acme/operating_system/windows_common/com/hresult_exception.h"
#include "aura_universal_windows/node.h"


#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.ViewManagement.h>


::int_size winrt_get_big_back_buffer_size();

//#include "__debug_power.h"


#define TIME_REPORTING 0


#undef REDRAW_HINTING
//#define REDRAW_HINTING


#ifdef __DEBUG_POWER
#undef SQUARY_HINT
#define SQUARY_HINT
#endif


namespace windowing_universal_windows
{


   buffer::buffer() :
      m_dDpi(-1.0f)
   {

      //m_bBeginDraw = false;

      m_pWindowingUniversalWindowsBuffer = this;

      m_bWindowSizeChangeInProgress = false;

      m_ephase = e_phase_draw;

      m_bCreated = false;

      m_b3D = false;

      m_dDpiIni = 1.0f;
      m_dDpi = -999.0f;
      m_bInitialized = false;
      m_bInit = false;

   }


   buffer::~buffer()
   {

   }


   void buffer::initialize_graphics_graphics(::windowing::window * pwindow)
   {

      //::e_status estatus = 

      ::graphics::bitmap_source_buffer::initialize_graphics_graphics(pwindow);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //::pointer < ::aura_universal_windows::interaction_impl > puwpimpl = pimpl;

      //m_pwindow = (class window *)pimpl->m_pwindow->m_pWindow4;

      m_pwindow = pwindow;

      m_dDpiIni = (float) system()->m_dDpi;

      m_dDpi = (float) system()->m_dDpi;

      CreateDeviceIndependentResources();

      m_bInit = true;

      //return estatus;

   }


   bool buffer::create_os_buffer(const ::int_size & size, int iStrideParam)
   {


      return true;

   }


   void buffer::destroy_os_buffer()
   {



   }


   bool buffer::_on_begin_draw(::graphics::buffer_item * pbufferitem)
   {

      //ødefer_construct_new(m_pbufferitem);

      //auto pframeworkview = m_pframeworkview;

      //if (!pframeworkview)
      //{

      //   return nullptr;

      //}

      auto pwindow = m_pwindow;

      if (!m_tristateCoreWindowVisible || m_ephase != e_phase_draw)
      {

         return false;

      }

      auto pdevicecontext = get_device_context();

      if (pdevicecontext == nullptr)
      {

         return false;

      }

      //buffer_size_and_position(m_pbufferitem);

      ødefer_construct(m_pdraw2dgraphics);

      if (m_pdraw2dgraphics->get_os_data() != pdevicecontext)
      {

         //m_pdraw2dgraphics->set_direct2d_plugin(pframeworkview->m_directx->m_pplugin);

         m_pdraw2dgraphics->attach(pdevicecontext);

      }

      if (!m_pdevicecontext)
      {

         return false;

      }

      if (!m_pdraw2dgraphics->m_bBeginDraw)
      {

         m_pdevicecontext->BeginDraw();

         m_pdraw2dgraphics->m_bBeginDraw = true;

      }

      if (!is_single_buffer_mode())
      {

         m_pdevicecontext->Clear(m_d2d1colorfBackground);

      }

      m_pdevicecontext->SetTransform(D2D1::Matrix3x2F::Identity());

      m_pbufferitem->m_pgraphics = m_pdraw2dgraphics;

      //return m_pbufferitem;

      return true;

   }


   void buffer::on_end_draw()
   {

      //auto pdevicecontext = (ID2D1DeviceContext*)m_pdraw2dgraphics->detach();

      m_pdraw2dgraphics->on_end_draw(m_pwindow->oswindow());

      if (m_pdevicecontext)
      {

         if (m_pdraw2dgraphics->m_bBeginDraw)
         {

            HRESULT hr = m_pdevicecontext->EndDraw();

            m_pdraw2dgraphics->m_bBeginDraw = false;

            if (SUCCEEDED(hr))
            {

               m_ephase = e_phase_present;

            }
            //else
            if (FAILED(hr))
            {

               output_debug_string("finished drawing with errors");

            }

            

         }

      }



   }


   bool buffer::create_buffer(const ::int_size & size, int iStrideParam)
   {

      return true;

   }


   void buffer::destroy_buffer()
   {


   }


   void buffer::on_after_graphical_update()
   {

   }


   void buffer::update_screen()
   {

      //if (m_bNewBuffer)
      //{

      auto puserinteraction = m_pwindow->user_interaction();

      auto & d = puserinteraction->layout().m_statea[::user::e_layout_design];

      auto & w = puserinteraction->layout().m_statea[::user::e_layout_window];

      w.m_point2 = d.m_point2;

      w.m_size = get_buffer_item()->m_size;

      Present();

      //m_bNewBuffer = false;

   //}

      //return true;

   }


   void buffer::on_update_screen(::graphics::buffer_item * pbufferitem)
   {

      if (m_bNewBuffer)
      {

         Present();

      }

      //return true;

   }


   bool buffer::buffer_lock_round_swap_key_buffers()
   {

      bool bOk2 = bitmap_source_buffer::buffer_lock_round_swap_key_buffers();

      return bOk2;

   }



   //
   //using namespace ::winrt::Windows::UI::Core;
   //using namespace ::winrt::Windows::Foundation;
   //using namespace Microsoft::WRL;
   //using namespace ::winrt::Windows::Graphics::Display;
   //using namespace D2D1;


   extern CLASS_DECL_AURA ::image::image_array * g_pimagea;


   //CLASS_DECL_ACME void dpi_os_initialize();



      //buffer::buffer() :
      //   m_dDpi(-1.0f)
      //{

      //   m_ephase = e_phase_draw;

      //   m_bCreated = false;

      //   m_b3D = false;

      //   m_dDpiIni = 1.0f;
      //   m_dDpi = -999.0f;
      //   m_bInitialized = false;
      //   m_bInit = false;

      //}


      //buffer::~buffer()
      //{


      //}


      //// Initialize the DirectX resources required to run.
      //void buffer::Initialize(::winrt::Windows::UI::Core::CoreWindow window, float dpi)
      //{

      //   m_dDpiIni = dpi;

      //   CreateDeviceIndependentResources();

      //   m_bInit = true;

      //}


   bool buffer::defer_init()
   {

      //::draw2d::lock draw2dlock;

      if (m_bInitialized)
      {

         return true;

      }

      if (!m_bInit)
      {

         return false;

      }

      CreateDeviceResources();

      //SetDpi(m_dDpiIni);

      m_dDpi = m_dDpiIni;

      system()->m_dDpi = m_dDpiIni;

      m_bInitialized = true;

      node()->dpi_os_initialize();

      //m_pimage->alloc(get_application()->create_new, this);
      //m_pimage = create_image({1000,  1000});

      return true;

   }


   // Recreate all device resources and set them back to the current state.
   void buffer::HandleDeviceLost()
   {

      //::draw2d::lock draw2dlock;

      //// Reset these member variables to ensure that SetDpi recreates all resources.
      float dpi = m_dDpi;
      m_dDpi = -1.0f;
      m_windowBounds.Width = 0;
      m_windowBounds.Height = 0;
      m_pswapchain = nullptr;

      {

         ID3D11RenderTargetView * nullViews[] = { nullptr };
         if (directx::directx()->m_pdevicecontext)
         {
            directx::directx()->m_pdevicecontext->OMSetRenderTargets(ARRAYSIZE(nullViews), nullViews, nullptr);

         }
         m_prendertargetview = nullptr;
         if (direct2d::direct2d()->m_pd2devicecontext)
         {
            direct2d::direct2d()->m_pd2devicecontext->SetTarget(nullptr);
         }
         m_pbitmap = nullptr;
         m_pstencilview = nullptr;
         directx::directx()->m_pdevicecontext->Flush();

         m_pdevicecontext = nullptr;
         m_pbitmap = nullptr;
         m_prendertargetview = nullptr;
         m_pstencilview = nullptr;


      }

      CreateDeviceResources();

      SetDpi(dpi);

   }


   // These are the resources required independent of the device.
   void buffer::CreateDeviceIndependentResources()
   {

      //::draw2d::lock draw2dlock;

      D2D1_FACTORY_OPTIONS options;
      ZeroMemory(&options, sizeof(D2D1_FACTORY_OPTIONS));

#if defined(__DEBUG)

      // If the project is in a debug build, enable Direct2D debugging via SDK Layers.
      options.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;

#endif // __DEBUG


      defer_throw_hresult(
         DWriteCreateFactory(
            DWRITE_FACTORY_TYPE_SHARED,
            __unknown_of(m_pwritefactory)
         )
      );

      defer_throw_hresult(
         CoCreateInstance(
            CLSID_WICImagingFactory,
            nullptr,
            CLSCTX_INPROC_SERVER,
            __interface_of(m_pimagingfactory)
         )
      );






















































      //// Create a DirectWrite text format object.
      //::universal_windows::defer_throw_hresult(
      //m_pwritefactory->CreateTextFormat(
      //L"Gabriola",
      //nullptr,
      //DWRITE_FONT_WEIGHT_REGULAR,
      //DWRITE_FONT_STYLE_NORMAL,
      //DWRITE_FONT_STRETCH_NORMAL,
      //64.0f,
      //L"en-US", // locale
      //&m_textFormat
      //)
      //);

      //// Center the text horizontally.
      //::universal_windows::defer_throw_hresult(
      //m_textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER)
      //);

      //// Center the text vertically.
      //::universal_windows::defer_throw_hresult(
      //m_textFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER)
      //);





   }

   // These are the resources that depend on the device.
   void buffer::CreateDeviceResources()
   {

      //::draw2d::lock draw2dlock;

      //direct2d::direct2d() = øallocate ::draw2d_direct2d::plugin();

      //direct2d::direct2d()->initialize();

      // m_d3dDevice = global_draw_get_d3d11_device1();

      //direct2d::direct2d()->m_pdevicecontext = global_draw_get_d3d11_device_context1();

      //m_d2dDevice = global_draw_get_d2d1_device();

      //::draw2d_direct2d::g_pdirect2dplugin->g_pd2factory.As(&m_d2dMultithread);

   }

   // Helps track the DPI in the helper class.
   // This is called in the dpiChanged happening handler in the impact class.
   void buffer::SetDpi(float dpi)
   {

      // Only handle window int_size changed if there is no pending DPI change.

      m_pwindow->main_post([this, dpi]()
         {

            OnChangeDpi(dpi);

            //m_window->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref ___new ::winrt::Windows::UI::Core::DispatchedHandler([this,dpi]()
            //{
              // OnChangeDpi(dpi);

               //         system()->m_possystemwindow->m_bWindowSizeChange = true;

            //}));

         });

   }


   void buffer::OnChangeDpi(float dpi)
   {

      //::draw2d::lock draw2dlock;

      if (dpi != m_dDpi)
      {

         m_dDpi = dpi;

         system()->m_dDpi = dpi;

         if (m_bCreated)
         {

            //m_size.cx = (int)m_window->Bounds.Width;

            //m_size.cy = (int)m_window->Bounds.Height;



            OnWindowSizeChange();

         }

      }

   }


   void buffer::OnChangeTheme()
   {

      ::winrt::Windows::UI::ViewManagement::UISettings uisettings;

      auto colorBackground = uisettings.GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

      m_d2d1colorfBackground.a = 1.0f;
      m_d2d1colorfBackground.r = colorBackground.R / 255.f;
      m_d2d1colorfBackground.g = colorBackground.G / 255.f;
      m_d2d1colorfBackground.b = colorBackground.B / 255.f;

   }


   void buffer::UpdateForWindowSizeChange()
   {

      m_pwindow->main_post([this]()
         {
            //m_window->Dispatcher->RunAsync(CoreDispatcherPriority::Normal,ref ___new ::winrt::Windows::UI::Core::DispatchedHandler([this]()
            //{

            OnWindowSizeChange();

            //}));

         });

   }


   void buffer::OnWindowSizeChange()
   {

      if (m_size.cx != m_windowBounds.Width || m_size.cy != m_windowBounds.Height)
      {

         ::draw2d::lock lock(this);

         CreateWindowSizeDependentResources();

         if (m_size.area() > 0)
         {

            system()->fork([this]()
               {

                  system()->on_graphics_ready();

               });

         }

      }

      auto puserinteraction = m_pwindow->user_interaction();

      if (::is_set(puserinteraction))
      {

         //m_pwindow->m_puserinteraction->start_layout();

         puserinteraction->place(0, 0, m_size.cx, m_size.cy);

         puserinteraction->order_top();

         puserinteraction->display(e_display_normal);

         //defer_resize_top_level_windows();

         puserinteraction->set_reposition();

         puserinteraction->set_need_layout();

         puserinteraction->set_need_redraw();

         puserinteraction->post_redraw();

      }


   }


   ID2D1DeviceContext * buffer::get_device_context()
   {

      return m_pdevicecontext;

   }


   bool buffer::is_single_buffer_mode() const
   {

      return false;

   }


   //void buffer::defer_resize_top_level_windows()
   //{

   //   if (system()->m_bExperienceMainFrame)
   //   {

   //      auto puserinteractionpointeraChild = m_pwindow->m_puserinteraction->m_puserinteractionpointeraChild;

   //      if (puserinteractionpointeraChild)
   //      {

   //         auto children = puserinteractionpointeraChild->m_interactiona;

   //         for (auto & pinteraction : children)
   //         {

   //            //if (pinteraction->is_window_visible())
   //            {

   //               pinteraction->set_dim(0, 0, m_size.cx, m_size.cy);

   //               pinteraction->order_top();

   //               pinteraction->display();

   //               pinteraction->set_need_layout();

   //               pinteraction->set_need_redraw();

   //            }

   //         }

   //      }

   //   }

   //}


   bool buffer::update_buffer(::graphics::buffer_item * pbufferitem)
   {

      if (!::graphics::bitmap_source_buffer::update_buffer(pbufferitem))
      {

         return false;

      }

      m_size = pbufferitem->m_size;

      CreateWindowSizeDependentResources();

      return true;

   }


   // Allocate all memory resources that change on a window SizeChanged happening.
   void buffer::CreateWindowSizeDependentResources()
   {

      m_bWindowSizeChangeInProgress = true;

      HRESULT hr;

      graphics_device_lock graphicsdevicelock;

      // Store the window bounds so the next time we get a SizeChanged happening we can
      // avoid rebuilding everything if the int_size is identical.
      m_windowBounds.Width = (float)m_size.cx;
      m_windowBounds.Height = (float)m_size.cy;

      //if (m_pswapchain != nullptr)
      //{
      //   ID3D11RenderTargetView * nullViews[] = { nullptr };
      //   directx::directx()->m_pdevicecontext->OMSetRenderTargets(ARRAYSIZE(nullViews), nullViews, nullptr);
      //   
      //   m_prendertargetview = nullptr;
      //   m_pdevicecontext->SetTarget(nullptr);
      //   /*m_pbitmap = nullptr;
      //   m_pstencilview = nullptr;
      //   directx::directx()->m_pdevicecontext->Flush();

      //   m_pdevicecontext = nullptr;
      //   m_pbitmap = nullptr;
      //   m_prendertargetview = nullptr;
      //   m_pstencilview = nullptr;
      //   m_bWindowSizeChangeInProgress = true;

      //   */
      //   directx::directx()->m_pdevicecontext->Flush();
      //   directx::directx()->m_pdevicecontext->ClearState();
      //   /*
      //   direct2d::direct2d()->m_pd2device->ClearResources();*/
      //   {
      //      comptr < ID3D11CommandList > pcommandlist;
      //      hr = directx::directx()->m_pdevicecontext->FinishCommandList(false, &pcommandlist);
      //      if (SUCCEEDED(hr))
      //      {
      //      }
      //   }

      //   // If the __swap chain already exists, resize it.
      //   hr = m_pswapchain->ResizeBuffers(
      //      0,
      //      0, // If you specify zero, DXGI will use the width of the client area of the target window.
      //      0, // If you specify zero, DXGI will use the height of the client area of the target window.
      //      DXGI_FORMAT_UNKNOWN, // Set this value to DXGI_FORMAT_UNKNOWN to preserve the existing format of the back buffer.
      //      0);

      //   if (hr == DXGI_ERROR_DEVICE_REMOVED)
      //   {
      //      // If the device was erased for any reason, a ___new device and swapchain will need to be created.
      //      HandleDeviceLost();

      //      // Everything is set up now. Do not continue execution of this method.
      //      return;
      //   }
      //   else if (hr == DXGI_ERROR_INVALID_CALL)
      //   {
      //      // i1;
      //      //  return;
      //      informationf("buffer::CreateWindowSizeDependentResources(1) DXGI_ERROR_INVALID_CALL");
      //   }
      //   else
      //   {
      //      
      //      if (FAILED(hr))
      //      {
      //         
      //         defer_throw_hresult(hr);

      //      }

      //   }
      //}

      auto displayInformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

      int cxScreen = displayInformation.ScreenWidthInRawPixels();

      int cyScreen = displayInformation.ScreenHeightInRawPixels();

      m_sizeBuffer.cx = maximum(cxScreen, m_size.cx);

      m_sizeBuffer.cy = maximum(cyScreen, m_size.cy);

      bool bBufferUpdated = false;

      if (m_pswapchain == nullptr)
      {


         // Otherwise, create a ___new one using the same adapter as the existing Direct3D device.
         DXGI_SWAP_CHAIN_DESC1 swapChainDesc = { 0 };
         swapChainDesc.Width = m_sizeBuffer.cx;                                     // Use automatic sizing.
         swapChainDesc.Height = m_sizeBuffer.cy;
         swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;           // This is the most common __swap chain format.
         swapChainDesc.Stereo = false;
         swapChainDesc.SampleDesc.Count = 1;                          // Don't use multi-sampling.
         swapChainDesc.SampleDesc.Quality = 0;
         swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
         swapChainDesc.BufferCount = 2;                               // Use double-buffering to minimize latency.
         //swapChainDesc.BufferCount = 1;                               // Use double-buffering to minimize latency.
         swapChainDesc.Scaling = DXGI_SCALING_NONE;
         swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL; // All Metro style apps must use this SwapEffect.
         //swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
         swapChainDesc.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;
         swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER;

         comptr<IDXGIDevice1> dxgiDevice;

         hr = directx::directx()->m_pdevice.as(dxgiDevice);

         ::defer_throw_hresult(hr);

         comptr<IDXGIAdapter> dxgiAdapter;

         hr = dxgiDevice->GetAdapter(&dxgiAdapter);

         defer_throw_hresult(hr);

         comptr<IDXGIFactory2> dxgiFactory;

         hr = dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory));

         defer_throw_hresult(hr);

         auto punknown = m_pwindow->m_windowscorewindow.as<IUnknown>();

         hr = dxgiFactory->CreateSwapChainForCoreWindow(
            directx::directx()->m_pdevice,
            punknown.get(),
            &swapChainDesc,
            nullptr,
            &m_pswapchain
         );

         defer_throw_hresult(hr);

         // Ensure that DXGI does not queue more than one frame at a time. This both reduces latency and
         // ensures that the application will only render after each VSync, minimizing power consumption.
         hr = dxgiDevice->SetMaximumFrameLatency(1);

         defer_throw_hresult(hr);

         bBufferUpdated = true;

      }
      else if(m_size.cx > m_sizeBuffer.cx || m_size.cy > m_sizeBuffer.cy)
      {

         //synchronous_lock synchronouslockObjects(system()->draw2d()->get_object_list_mutex());
         //synchronous_lock synchronouslockImages(system()->draw2d()->get_image_list_mutex());
         //synchronous_lock synchronouslockGraphicsContext(system()->draw2d()->get_graphics_context_list_mutex());

         system()->draw2d()->clear_all_objects_os_data();
         //
         //            //if (m_pswapchain != nullptr)
         ////{
         ////   ID3D11RenderTargetView * nullViews[] = { nullptr };
         ////   directx::directx()->m_pdevicecontext->OMSetRenderTargets(ARRAYSIZE(nullViews), nullViews, nullptr);
         ////   
         ////   m_prendertargetview = nullptr;
         ////   m_pdevicecontext->SetTarget(nullptr);
         ////   /*m_pbitmap = nullptr;
         ////   m_pstencilview = nullptr;
         ////   directx::directx()->m_pdevicecontext->Flush();
         //
         ////   m_pdevicecontext = nullptr;
         ////   m_pbitmap = nullptr;
         ////   m_prendertargetview = nullptr;
         ////   m_pstencilview = nullptr;
         ////   m_bWindowSizeChangeInProgress = true;
         //
         ////   */
         ID3D11RenderTargetView * nullViews[] = { nullptr };
         directx::directx()->m_pdevicecontext->OMSetRenderTargets(ARRAYSIZE(nullViews), nullViews, nullptr);
         m_prendertargetview = nullptr;
         m_pdevicecontext->SetTarget(nullptr);
         directx::directx()->m_pdevicecontext->Flush();
         directx::directx()->m_pdevicecontext->ClearState();
         direct2d::direct2d()->m_pd2device->ClearResources();
         m_pdevicecontext = nullptr;
         m_pbitmap = nullptr;
         m_prendertargetview = nullptr;
         m_pstencilview = nullptr;

         if(directx::directx()->m_pdevicecontext->GetType() 
            != D3D11_DEVICE_CONTEXT_IMMEDIATE)
         {
            comptr < ID3D11CommandList > pcommandlist;
            hr = directx::directx()->m_pdevicecontext->FinishCommandList(false, &pcommandlist);
            if (SUCCEEDED(hr))
            {
            }
         }

         //       If the __swap chain already exists, resize it.
         hr = m_pswapchain->ResizeBuffers(
            0,
            m_size.cx, // If you specify zero, DXGI will use the width of the client area of the target window.
            m_size.cy, // If you specify zero, DXGI will use the height of the client area of the target window.
            DXGI_FORMAT_UNKNOWN, // Set this value to DXGI_FORMAT_UNKNOWN to preserve the existing format of the back buffer.
            DXGI_SWAP_CHAIN_FLAG_FOREGROUND_LAYER);

         if (hr == DXGI_ERROR_DEVICE_REMOVED)
         {
            // If the device was erased for any reason, a ___new device and swapchain will need to be created.
            HandleDeviceLost();

            // Everything is set up now. Do not continue execution of this method.
            return;
         }
         else if (hr == DXGI_ERROR_INVALID_CALL)
         {
            // i1;
            //  return;
            informationf("buffer::CreateWindowSizeDependentResources(1) DXGI_ERROR_INVALID_CALL");
         }
         else
         {

            if (FAILED(hr))
            {

               defer_throw_hresult(hr);

            }

         }

         bBufferUpdated = true;

      }

      if (bBufferUpdated)
      {

         DXGI_SWAP_CHAIN_DESC1 desc1 = { 0 };

         m_pswapchain->GetDesc1(&desc1);

         m_sizeBuffer.cx = desc1.Width;

         m_sizeBuffer.cy = desc1.Height;

         if (m_b3D)
         {

            // Create a Direct3D render target impact of the __swap chain back buffer.
            comptr<ID3D11Texture2D> backBuffer;

            HRESULT hr = m_pswapchain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));

            defer_throw_hresult(hr);

            hr = directx::directx()->m_pdevice->CreateRenderTargetView(
               backBuffer,
               nullptr,
               &m_prendertargetview
            );

            defer_throw_hresult(hr);

            // Cache the rendertarget dimensions in our helper class for convenient use.
            D3D11_TEXTURE2D_DESC backBufferDesc = { 0 };
            backBuffer->GetDesc(&backBufferDesc);
            m_renderTargetSize.Width = static_cast<float>(backBufferDesc.Width);
            m_renderTargetSize.Height = static_cast<float>(backBufferDesc.Height);

            // Create a depth stencil impact for use with 3D rendering if needed.
            CD3D11_TEXTURE2D_DESC depthStencilDesc(
               DXGI_FORMAT_D24_UNORM_S8_UINT,
               backBufferDesc.Width,
               backBufferDesc.Height,
               1,
               1,
               D3D11_BIND_DEPTH_STENCIL
            );

            comptr<ID3D11Texture2D> depthStencil;

            hr = directx::directx()->m_pdevice->CreateTexture2D(
               &depthStencilDesc,
               nullptr,
               &depthStencil
            );

            defer_throw_hresult(hr);

            auto viewDesc = CD3D11_DEPTH_STENCIL_VIEW_DESC(D3D11_DSV_DIMENSION_TEXTURE2D);

            hr = directx::directx()->m_pdevice->CreateDepthStencilView(
               depthStencil,
               &viewDesc,
               &m_pstencilview
            );

            defer_throw_hresult(hr);

            // Set the 3D rendering viewport to target the entire window.
            CD3D11_VIEWPORT viewport(
               0.0f,
               0.0f,
               static_cast<float>(backBufferDesc.Width),
               static_cast<float>(backBufferDesc.Height)
            );

            directx::directx()->m_pdevicecontext->RSSetViewports(1, &viewport);

         }

         // Create a Direct2D target bitmap associated with the
         // __swap chain back buffer and set it as the current target.
         D2D1_BITMAP_PROPERTIES1 bitmapProperties =
            D2D1::BitmapProperties1(
               D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW,
               D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED),
               m_dDpi,
               m_dDpi
            );

         hr = direct2d::direct2d()->m_pd2device->CreateDeviceContext(
            //D2D1_DEVICE_CONTEXT_OPTIONS_NONE,
            D2D1_DEVICE_CONTEXT_OPTIONS_ENABLE_MULTITHREADED_OPTIMIZATIONS,
            &m_pdevicecontext
         );

         ::defer_throw_hresult(hr);

         comptr<IDXGISurface> dxgiBackBuffer;

         hr = m_pswapchain->GetBuffer(0, IID_PPV_ARGS(&dxgiBackBuffer));

         ::defer_throw_hresult(hr);

         hr = m_pdevicecontext->CreateBitmapFromDxgiSurface(
            dxgiBackBuffer,
            &bitmapProperties,
            &m_pbitmap);

         ::defer_throw_hresult(hr);

         m_pdevicecontext->SetTarget(m_pbitmap);

      }


      if (m_bWindowSizeChangeInProgress)
      {

         m_bWindowSizeChangeInProgress = false;

         m_pwindow->main_post([this]()
            {

               //A window int_size change has been initiated and the app has just completed presenting
               //the first frame with the ___new size. Notify the resize manager so we can short
               //circuit any resize animation and prevent unnecessary delays.
               m_pwindow->m_resizemanager.NotifyLayoutCompleted();

            });

      }


      //m_bBeginDraw = false;

   }


   void buffer::DestroyWindowSizeDependentResources()
   {



      //HRESULT hr;

      graphics_device_lock devicelock;

      // Store the window bounds so the next time we get a SizeChanged happening we can
      // avoid rebuilding everything if the int_size is identical.
      m_windowBounds.Width = (float)m_size.cx;

      m_windowBounds.Height = (float)m_size.cy;

      m_sizeBuffer = { 0,0 };

      m_pswapchain = nullptr;

      m_prendertargetview = nullptr;
      
      m_pstencilview = nullptr;

      if (m_pdevicecontext)
      {

         m_pdevicecontext->SetTarget(nullptr);

      }
      
      m_pdevicecontext = nullptr;

      m_pbitmap = nullptr;

   }


   void buffer::Present()
   {

      if (m_ephase != e_phase_present)
      {

         return;

      }

      HRESULT hr = S_OK;

      {

         graphics_device_lock devicelock;

         if (!defer_init())
         {

            return;

         }

         try
         {

            // The application may optionally specify "dirty" or "scroll" rects to improve efficiency
            // in certain scenarios.  In this sample, however, we do not utilize those features.
            DXGI_PRESENT_PARAMETERS parameters = {};

            parameters.DirtyRectsCount = 0;

            parameters.pDirtyRects = nullptr;

            parameters.pScrollRect = nullptr;

            parameters.pScrollOffset = nullptr;

            if (m_pswapchain == nullptr)
            {

               return;

            }

            {


               // The first argument instructs DXGI to block until VSync, putting the application
               // to sleep until the next VSync. This ensures we don't waste any cycles rendering
               // frames that will never be displayed to the screen.
               //hr = m_pswapchain->Present1(1, 0, &parameters);

#if TIME_REPORTING

               ::duration durationSwapChainPresent;

               durationSwapChainPresent.Now();

#endif

               hr = m_pswapchain->Present(0, 0);

#if TIME_REPORTING

               auto e2 = durationSwapChainPresent.elapsed();

               output_debug_string("durationSwapChainPresent " + __string(e2.floating_millisecond().m_d) + "ms\n");

#endif

               if (directx::directx()->m_pdevicecontext)
               {

                  if (m_prendertargetview)
                  {

                     // Discard the contents of the render target.
                     // This is a valid operation only when the existing contents will be entirely
                     // overwritten. If dirty or scroll rects are used, this call should be erased.
                     directx::directx()->m_pdevicecontext1->DiscardView(m_prendertargetview);

                  }

                  if (m_pstencilview)
                  {

                     // Discard the contents of the depth stencil.
                     directx::directx()->m_pdevicecontext1->DiscardView(m_pstencilview);

                  }

               }

               //g_pimagea->erase_all();

            }

            // If the device was erased either by a disconnect or a driver upgrade, we
            // must recreate all device resources.
            if (hr == DXGI_ERROR_DEVICE_REMOVED)
            {

               HandleDeviceLost();

            }
            else
            {

               if (FAILED(hr))
               {

                  defer_throw_hresult(hr);

               }

            }

         }
         catch (...)
         {

         }

         m_ephase = e_phase_draw;

      }

   }


   void buffer::ValidateDevice()
   {

      //::draw2d::lock draw2dlock;
      // The D3D Device is no longer valid if the default adapter changes or if
      // the device has been erased.

      // First, get the information for the adapter related to the current device.

      comptr<IDXGIDevice1> dxgiDevice;
      comptr<IDXGIAdapter> deviceAdapter;
      DXGI_ADAPTER_DESC deviceDesc;
      defer_throw_hresult(directx::directx()->m_pdevice.as(dxgiDevice));
      defer_throw_hresult(dxgiDevice->GetAdapter(&deviceAdapter));
      defer_throw_hresult(deviceAdapter->GetDesc(&deviceDesc));

      // Next, get the information for the default adapter.

      comptr<IDXGIFactory2> dxgiFactory;
      comptr<IDXGIAdapter1> currentAdapter;
      DXGI_ADAPTER_DESC currentDesc;
      defer_throw_hresult(CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory)));
      defer_throw_hresult(dxgiFactory->EnumAdapters1(0, &currentAdapter));
      defer_throw_hresult(currentAdapter->GetDesc(&currentDesc));

      // If the adapter LUIDs don't match, or if the device reports that it has been erased,
      // a ___new D3D device must be created.

      if ((deviceDesc.AdapterLuid.LowPart != currentDesc.AdapterLuid.LowPart) ||
         (deviceDesc.AdapterLuid.HighPart != currentDesc.AdapterLuid.HighPart) ||
         FAILED(directx::directx()->m_pdevice->GetDeviceRemovedReason()))
      {
         // Release references to resources related to the old device.
         dxgiDevice = nullptr;
         deviceAdapter = nullptr;

         // Create a ___new device and __swap chain.
         HandleDeviceLost();

      }

   }


   //HRESULT buffer::Render()
   //{

   //   ::draw2d::lock draw2dlock;

   //   if (!defer_init())
   //   {

   //      return E_FAIL;

   //   }

   //   m_pdevicecontext->BeginDraw();

   //   auto colorBackground = ::winrt::Windows::UI::ViewManagement::UISettings().GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

   //   D2D1_COLOR_F color32;

   //   color32.a = 1.0f;
   //   color32.r = colorBackground.R / 255.f;
   //   color32.g = colorBackground.G / 255.f;
   //   color32.b = colorBackground.B / 255.f;

   //   m_pdevicecontext->Clear(color32);

   //   m_pdevicecontext->SetTransform(D2D1::Matrix3x2F::Identity());

   //   ::draw2d::graphics_pointer dc(e_create_new, ::get_context_system());

   //   dc->attach((ID2D1DeviceContext *) m_pdevicecontext);

   //   auto pimpl = session()->m_puserinteractionHost->m_pimpl;

   //   //throw_todo();

   //   //if (pimpl.is_set())
   //   //{

   //   //   pimpl->_001UpdateBuffer();

   //   //   ::pointer<::window_double_buffer>pbuffer = pimpl->m_spgraphics;

   //   //   if (pbuffer.is_set())
   //   //   {

   //   //      int_size sz = pbuffer->get_buffer().get_size();

   //   //      ::draw2d::graphics_pointer & pgraphics = pbuffer->get_buffer().get_graphics();

   //   //      //pgraphics->fill_solid_rect_dim(300, 300, 100, 100, argb(255, 200, 60, 80));

   //   //      dc->from(sz, pgraphics);

   //   //   }

   //   //}

   //   ////_001UpdateBuffer();

   //   ////Sys(::get_context_system()).m_possystemwindow->m_puserinteraction->_000OnDraw(m_pimage->g());

   //   ////dc->from(m_pimage->get_size(), m_pimage->g());
   //   ////dc->from(m_pimage->get_size(), m_pimage->g());

   //   ////synchronouslock.lock();

   //   //dc->detach();


   //   //// We ignore D2DERR_RECREATE_TARGET here. This error indicates that the device
   //   //// is lost. It will be handled during the next call to Present.
   //   //HRESULT hr = m_pdevicecontext->EndDraw();

   //   //if(FAILED(hr))
   //   //{

   //   //   if(hr == D2DERR_RECREATE_TARGET)
   //   //   {

   //   //      trace_hr("buffer::Render, EndDraw", hr);

   //   //   }
   //   //   else if(hr == D2DERR_WRONG_STATE)
   //   //   {

   //   //      trace_hr("buffer::Render, EndDraw",hr);

   //   //   }
   //   //   else
   //   //   {

   //   //      trace_hr("buffer::Render, EndDraw",hr);

   //   //   }

   //   //}

   //   // return hr;

   //   return E_FAIL;

   //}




::graphics::buffer_item * buffer::get_buffer_item()
{

   ødefer_construct_new(m_pbufferitem);

   return m_pbufferitem;

   }

::graphics::buffer_item * buffer::get_screen_item()
{

   ødefer_construct_new(m_pbufferitem);

   return m_pbufferitem;

}




   CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS buffer * __buffer(::graphics::graphics * pgraphics)
   {

      return ::is_null(pgraphics) ? nullptr : pgraphics->m_pWindowingUniversalWindowsBuffer;

   }

} // namespace windowing_universal_windows
