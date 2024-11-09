#include "framework.h"
//#include "app/draw2d_direct2d/_.h"
//#include "app/draw2d_direct2d/_.h"
//#include "aura/os/windows_common/draw2d_direct2d_global.h"
//#include "_uwp.h"
//
//
//::int_size winrt_get_big_back_buffer_size();
////
////using namespace ::winrt::Windows::UI::Core;
////using namespace ::winrt::Windows::Foundation;
////using namespace Microsoft::WRL;
////using namespace ::winrt::Windows::Graphics::Display;
////using namespace D2D1;
//
//
//extern CLASS_DECL_AURA image_array * g_pimagea;
//
//
////CLASS_DECL_ACME void dpi_os_initialize();
//
//
//namespace windowing_universal_windows
//{
//
//
//   direct2d_buffer::direct2d_buffer() :
//      m_dpi(-1.0f)
//   {
//
//      m_ephase = e_phase_draw;
//
//      m_bCreated = false;
//
//      m_b3D = false;
//
//      m_dpiIni = 1.0f;
//      m_dpi = -999.0f;
//      m_bInitialized = false;
//      m_bInit = false;
//
//   }
//
//
//   direct2d_buffer::~direct2d_buffer()
//   {
//
//
//   }
//
//
//   // Initialize the DirectX resources required to run.
//   void direct2d_buffer::Initialize(::winrt::Windows::UI::Core::CoreWindow window, float dpi)
//   {
//
//      m_window = window;
//
//      m_dpiIni = dpi;
//
//      CreateDeviceIndependentResources();
//
//      m_bInit = true;
//
//   }
//
//
//   bool direct2d_buffer::defer_init()
//   {
//
//      ::draw2d::lock draw2dlock;
//
//      if (m_bInitialized)
//      {
//
//         return true;
//
//      }
//
//      if (!m_bInit)
//      {
//
//         return false;
//
//      }
//
//      CreateDeviceResources();
//
//      //SetDpi(m_dpiIni);
//
//      m_dpi = m_dpiIni;
//
//      system()->m_dpi = m_dpiIni;
//
//      m_bInitialized = true;
//
//      system()->m_pnode->m_pauranode->dpi_os_initialize();
//
//      //m_pimage->alloc(get_application()->create_new, this);
//      //m_pimage = create_image({1000,  1000});
//
//
//      return true;
//
//   }
//
//
//   // Recreate all device resources and set them back to the current state.
//   void direct2d_buffer::HandleDeviceLost()
//   {
//
//      ::draw2d::lock draw2dlock;
//
//      //// Reset these member variables to ensure that SetDpi recreates all resources.
//      float dpi = m_dpi;
//      m_dpi = -1.0f;
//      m_windowBounds.Width = 0;
//      m_windowBounds.Height = 0;
//      m_swapChain = nullptr;
//
//      {
//
//         ID3D11RenderTargetView * nullViews[] = { nullptr };
//         if (directx::directx()->m_pd3devicecontext)
//         {
//            directx::directx()->m_pd3devicecontext->OMSetRenderTargets(ARRAYSIZE(nullViews), nullViews, nullptr);
//
//         }
//         m_d3dRenderTargetView = nullptr;
//         if (direct2d::direct2d()->m_pd2devicecontext)
//         {
//            direct2d::direct2d()->m_pd2devicecontext->SetTarget(nullptr);
//         }
//         m_d2dTargetBitmap = nullptr;
//         m_d3dDepthStencilView = nullptr;
//         directx::directx()->m_pd3devicecontext->Flush();
//
//         m_pd2d1devicecontext = nullptr;
//         m_d2dTargetBitmap = nullptr;
//         m_d3dRenderTargetView = nullptr;
//         m_d3dDepthStencilView = nullptr;
//
//
//      }
//
//      CreateDeviceResources();
//
//      SetDpi(dpi);
//
//   }
//
//
//   // These are the resources required independent of the device.
//   void direct2d_buffer::CreateDeviceIndependentResources()
//   {
//
//      ::draw2d::lock draw2dlock;
//
//      D2D1_FACTORY_OPTIONS options;
//      ZeroMemory(&options,sizeof(D2D1_FACTORY_OPTIONS));
//
//#if defined(__DEBUG)
//      
//      // If the project is in a debug build, enable Direct2D debugging via SDK Layers.
//      options.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;
//
//#endif // __DEBUG
//
//
//      ::universal_windows::throw_if_failed(
//      DWriteCreateFactory(
//      DWRITE_FACTORY_TYPE_SHARED,
//      __uuidof(IDWriteFactory),
//      &m_dwriteFactory
//      )
//      );
//
//      ::universal_windows::throw_if_failed(
//      CoCreateInstance(
//      CLSID_WICImagingFactory,
//      nullptr,
//      CLSCTX_INPROC_SERVER,
//      IID_PPV_ARGS(&m_wicFactory)
//      )
//      );
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//      //// Create a DirectWrite text format object.
//      //::universal_windows::throw_if_failed(
//      //m_dwriteFactory->CreateTextFormat(
//      //L"Gabriola",
//      //nullptr,
//      //DWRITE_FONT_WEIGHT_REGULAR,
//      //DWRITE_FONT_STYLE_NORMAL,
//      //DWRITE_FONT_STRETCH_NORMAL,
//      //64.0f,
//      //L"en-US", // locale
//      //&m_textFormat
//      //)
//      //);
//
//      //// Center the text horizontally.
//      //::universal_windows::throw_if_failed(
//      //m_textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER)
//      //);
//
//      //// Center the text vertically.
//      //::universal_windows::throw_if_failed(
//      //m_textFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER)
//      //);
//
//
//
//
//
//   }
//
//   // These are the resources that depend on the device.
//   void direct2d_buffer::CreateDeviceResources()
//   {
//
//      ::draw2d::lock draw2dlock;
//
//      //direct2d::direct2d() = __allocate ::draw2d_direct2d::plugin();
//
//      //direct2d::direct2d()->initialize();
//
//      // m_d3dDevice = global_draw_get_d3d11_device1();
//
//      //direct2d::direct2d()->m_pd3devicecontext = global_draw_get_d3d11_device_context1();
//
//      //m_d2dDevice = global_draw_get_d2d1_device();
//
//      //::draw2d_direct2d::g_pdirect2dplugin->g_pd2factory.As(&m_d2dMultithread);
//
//   }
//
//   // Helps track the DPI in the helper class.
//   // This is called in the dpiChanged happening handler in the impact class.
//   void direct2d_buffer::SetDpi(float dpi)
//   {
//      
//      // Only handle window int_size changed if there is no pending DPI change.
//
//      session()->system()->windowing()->windowing_branch(__routine([this, dpi]()
//         {
//
//            OnChangeDpi(dpi);
//
//         //m_window->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref ___new ::winrt::Windows::UI::Core::DispatchedHandler([this,dpi]()
//         //{
//           // OnChangeDpi(dpi);
//
//            //         system()->m_possystemwindow->m_bWindowSizeChange = true;
//
//         //}));
//
//         }));
//
//   }
//
//
//   void direct2d_buffer::OnChangeDpi(float dpi)
//   {
//
//      ::draw2d::lock draw2dlock;
//
//      if (dpi != m_dpi)
//      {
//
//         m_dpi = dpi;
//
//         system()->m_dpi = dpi;
//
//         if (m_bCreated)
//         {
//
//            //m_size.cx = (int)m_window->Bounds.Width;
//
//            //m_size.cy = (int)m_window->Bounds.Height;
//
//
//
//            OnWindowSizeChange();
//
//         }
//
//      }
//
//   }
//
//
//   void direct2d_buffer::UpdateForWindowSizeChange()
//   {
//
//      session()->system()->windowing()->windowing_branch(__routine([this]()
//         {
//            //m_window->Dispatcher->RunAsync(CoreDispatcherPriority::Normal,ref ___new ::winrt::Windows::UI::Core::DispatchedHandler([this]()
//            //{
//
//            OnWindowSizeChange();
//
//            //}));
//
//         }));
//
//   }
//
//
//   void direct2d_buffer::OnWindowSizeChange()
//   {
//
//      if (m_size.cx != m_windowBounds.Width || m_size.cy != m_windowBounds.Height)
//      {
//
//         ::draw2d::lock lock;
//
//         auto ptopic = system()->topic(id_os_dark_mode);
//
//         system()->handle_subject(ptopic);
//
//         CreateWindowSizeDependentResources();
//
//         if (m_size.area() > 0)
//         {
//
//            system()->fork([this]()
//            {
//
//               system()->on_graphics_ready();
//
//            });
//
//         }
//
//      }
//
//      if (m_pwindow->m_pimpl->m_puserinteraction)
//      {
//
//         //m_pwindow->m_puserinteraction->start_layout();
//
//         m_pwindow->m_pimpl->m_puserinteraction->set_dim(0, 0, m_size.cx, m_size.cy);
//
//         m_pwindow->m_pimpl->m_puserinteraction->order_top();
//
//         m_pwindow->m_pimpl->m_puserinteraction->display(e_display_normal);
//
//         //defer_resize_top_level_windows();
//
//         m_pwindow->m_pimpl->m_puserinteraction->set_reposition();
//
//         m_pwindow->m_pimpl->m_puserinteraction->set_need_layout();
//
//         m_pwindow->m_pimpl->m_puserinteraction->set_need_redraw();
//
//         m_pwindow->m_pimpl->m_puserinteraction->post_redraw();
//
//      }
//
//
//   }
//
//
//   ID2D1DeviceContext* direct2d_buffer::get_device_context()
//   {
//
//      return m_pd2d1devicecontext.Get();
//
//   }
//
//
//   //void direct2d_buffer::defer_resize_top_level_windows()
//   //{
//
//   //   if (system()->m_bExperienceMainFrame)
//   //   {
//
//   //      auto puserinteractionpointeraChild = m_pwindow->m_puserinteraction->m_puserinteractionpointeraChild;
//
//   //      if (puserinteractionpointeraChild)
//   //      {
//
//   //         auto children = puserinteractionpointeraChild->m_interactiona;
//
//   //         for (auto & pinteraction : children)
//   //         {
//
//   //            //if (pinteraction->is_window_visible())
//   //            {
//
//   //               pinteraction->set_dim(0, 0, m_size.cx, m_size.cy);
//
//   //               pinteraction->order_top();
//
//   //               pinteraction->display();
//
//   //               pinteraction->set_need_layout();
//
//   //               pinteraction->set_need_redraw();
//
//   //            }
//
//   //         }
//
//   //      }
//
//   //   }
//
//   //}
//
//
//   // Allocate all memory resources that change on a window SizeChanged happening.
//   void direct2d_buffer::CreateWindowSizeDependentResources()
//   {
//
//      HRESULT hr;
//
//      ::windowing::graphics_lock graphicslock(m_pwindow);
//
//      // Store the window bounds so the next time we get a SizeChanged happening we can
//      // avoid rebuilding everything if the int_size is identical.
//      m_windowBounds.Width = (float) m_size.cx;
//      m_windowBounds.Height = (float) m_size.cy;
//
//      if(m_swapChain != nullptr)
//      {
//         ID3D11RenderTargetView * nullViews[] = { nullptr };
//         directx::directx()->m_pd3devicecontext->OMSetRenderTargets(ARRAYSIZE(nullViews), nullViews, nullptr);
//         m_d3dRenderTargetView = nullptr;
//         m_pd2d1devicecontext->SetTarget(nullptr);
//         m_d2dTargetBitmap = nullptr;
//         m_d3dDepthStencilView = nullptr;
//         directx::directx()->m_pd3devicecontext->Flush();
//
//         m_pd2d1devicecontext = nullptr;
//         m_d2dTargetBitmap = nullptr;
//         m_d3dRenderTargetView = nullptr;
//         m_d3dDepthStencilView = nullptr;
//         //m_windowSizeChangeInProgress = true;
//
//
//         directx::directx()->m_pd3devicecontext->Flush();
//         directx::directx()->m_pd3devicecontext->ClearState();
//         direct2d::direct2d()->m_pd2device->ClearResources();
//         {
//            comptr < ID3D11CommandList > pcommandlist;
//            hr = directx::directx()->m_pd3devicecontext->FinishCommandList(false, &pcommandlist);
//            if (SUCCEEDED(hr))
//            {
//            }
//         }
//
//         // If the __swap chain already exists, resize it.
//         hr = m_swapChain->ResizeBuffers(
//              0,
//              0, // If you specify zero, DXGI will use the width of the client area of the target window.
//              0, // If you specify zero, DXGI will use the height of the client area of the target window.
//              DXGI_FORMAT_UNKNOWN, // Set this value to DXGI_FORMAT_UNKNOWN to preserve the existing format of the back buffer.
//              0);
//
//         if(hr == DXGI_ERROR_DEVICE_REMOVED)
//         {
//            // If the device was erased for any reason, a ___new device and swapchain will need to be created.
//            HandleDeviceLost();
//
//            // Everything is set up now. Do not continue execution of this method.
//            return;
//         }
//         else if(hr == DXGI_ERROR_INVALID_CALL)
//         {
//            // i1;
//            //  return;
//            informationf("direct2d_buffer::CreateWindowSizeDependentResources(1) DXGI_ERROR_INVALID_CALL");
//         }
//         else
//         {
//            if (FAILED(hr))
//            {
//               ::universal_windows::throw_if_failed(hr);
//
//            }
//         }
//      }
//      
//      if(m_swapChain== nullptr)
//      {
//
//         m_sizeBuffer = winrt_get_big_back_buffer_size();
//
//         // Otherwise, create a ___new one using the same adapter as the existing Direct3D device.
//         DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {0};
//         swapChainDesc.Width = m_sizeBuffer.cx;                                     // Use automatic sizing.
//         swapChainDesc.Height = m_sizeBuffer.cy;
//         swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;           // This is the most common __swap chain format.
//         swapChainDesc.Stereo = false;
//         swapChainDesc.SampleDesc.Count = 1;                          // Don't use multi-sampling.
//         swapChainDesc.SampleDesc.Quality = 0;
//         swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
//         swapChainDesc.BufferCount = 2;                               // Use double-buffering to minimize latency.
//         swapChainDesc.Scaling = DXGI_SCALING_NONE;
//         swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL; // All Metro style apps must use this SwapEffect.
//         //swapChainDesc.AlphaMode = DXGI_ALPHA_MODE_PREMULTIPLIED;
//         swapChainDesc.Flags = 0;
//
//         comptr<IDXGIDevice1> dxgiDevice;
//         
//         hr = directx::directx()->m_pd3device.As(&dxgiDevice);
//
//         ::universal_windows::throw_if_failed(hr);
//
//         comptr<IDXGIAdapter> dxgiAdapter;
//
//         hr = dxgiDevice->GetAdapter(&dxgiAdapter);
//            
//         ::universal_windows::throw_if_failed(hr);
//
//         comptr<IDXGIFactory2> dxgiFactory;
//
//         hr = dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory));
//
//         ::universal_windows::throw_if_failed(hr);
//
//         auto window = m_window;
//
//         hr = dxgiFactory->CreateSwapChainForCoreWindow(
//            directx::directx()->m_pd3device.Get(),
//            reinterpret_cast<IUnknown *>(&m_window),
//            &swapChainDesc,
//            nullptr,
//            &m_swapChain
//         );
//
//         ::universal_windows::throw_if_failed(hr);
//
//         // Ensure that DXGI does not queue more than one frame at a time. This both reduces latency and
//         // ensures that the application will only render after each VSync, minimizing power consumption.
//         hr = dxgiDevice->SetMaximumFrameLatency(1);
//
//         ::universal_windows::throw_if_failed(hr);
//
//      }
//
//      if (m_b3D)
//      {
//
//         // Create a Direct3D render target impact of the __swap chain back buffer.
//         comptr<ID3D11Texture2D> backBuffer;
//
//         HRESULT hr = m_swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));
//         
//         ::universal_windows::throw_if_failed(hr);
//
//         hr = directx::directx()->m_pd3device->CreateRenderTargetView(
//            backBuffer.Get(),
//            nullptr,
//            &m_d3dRenderTargetView
//         );
//
//         ::universal_windows::throw_if_failed(hr);
//
//         // Cache the rendertarget dimensions in our helper class for convenient use.
//         D3D11_TEXTURE2D_DESC backBufferDesc = { 0 };
//         backBuffer->GetDesc(&backBufferDesc);
//         m_renderTargetSize.Width = static_cast<float>(backBufferDesc.Width);
//         m_renderTargetSize.Height = static_cast<float>(backBufferDesc.Height);
//
//         // Create a depth stencil impact for use with 3D rendering if needed.
//         CD3D11_TEXTURE2D_DESC depthStencilDesc(
//         DXGI_FORMAT_D24_UNORM_S8_UINT,
//         backBufferDesc.Width,
//         backBufferDesc.Height,
//         1,
//         1,
//         D3D11_BIND_DEPTH_STENCIL
//         );
//
//         comptr<ID3D11Texture2D> depthStencil;
//
//         hr = directx::directx()->m_pd3device->CreateTexture2D(
//            &depthStencilDesc,
//            nullptr,
//            &depthStencil
//         );
//
//         ::universal_windows::throw_if_failed(hr);
//
//         auto viewDesc = CD3D11_DEPTH_STENCIL_VIEW_DESC(D3D11_DSV_DIMENSION_TEXTURE2D);
//         
//         hr = directx::directx()->m_pd3device->CreateDepthStencilView(
//         depthStencil.Get(),
//         &viewDesc,
//         &m_d3dDepthStencilView
//         );
//
//         ::universal_windows::throw_if_failed(hr);
//
//         // Set the 3D rendering viewport to target the entire window.
//         CD3D11_VIEWPORT viewport(
//         0.0f,
//         0.0f,
//         static_cast<float>(backBufferDesc.Width),
//         static_cast<float>(backBufferDesc.Height)
//         );
//
//         directx::directx()->m_pd3devicecontext->RSSetViewports(1, &viewport);
//
//      }
//
//      // Create a Direct2D target bitmap associated with the
//      // __swap chain back buffer and set it as the current target.
//      D2D1_BITMAP_PROPERTIES1 bitmapProperties =
//         D2D1::BitmapProperties1(
//      D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW,
//      D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM,D2D1_ALPHA_MODE_PREMULTIPLIED),
//      m_dpi,
//      m_dpi
//      );
//
//
//      hr = direct2d::direct2d()->m_pd2device->CreateDeviceContext(
//         //D2D1_DEVICE_CONTEXT_OPTIONS_NONE,
//         D2D1_DEVICE_CONTEXT_OPTIONS_ENABLE_MULTITHREADED_OPTIMIZATIONS,
//         &m_pd2d1devicecontext
//      );
//
//      ::throw_if_failed(hr);
//
//      comptr<IDXGISurface> dxgiBackBuffer;
//      
//      hr = m_swapChain->GetBuffer(0, IID_PPV_ARGS(&dxgiBackBuffer));
//
//      ::throw_if_failed(hr);
//
//      
//      hr = m_pd2d1devicecontext->CreateBitmapFromDxgiSurface(
//         dxgiBackBuffer.Get(),
//         &bitmapProperties,
//         &m_d2dTargetBitmap);
//      
//      ::throw_if_failed(hr);
//
//      m_pd2d1devicecontext->SetTarget(m_d2dTargetBitmap.Get());
//
//   }
//
//
//   void direct2d_buffer::DestroyWindowSizeDependentResources()
//   {
//
//      HRESULT hr;
//
//      ::windowing::graphics_lock devicelock(m_pwindow);
//
//      // Store the window bounds so the next time we get a SizeChanged happening we can
//      // avoid rebuilding everything if the int_size is identical.
//      m_windowBounds.Width = (float)m_size.cx;
//      m_windowBounds.Height = (float)m_size.cy;
//
//      m_sizeBuffer = { 0,0 };
//
//         
//      m_swapChain = nullptr;
//
//      m_d3dRenderTargetView = nullptr;
//      m_d3dDepthStencilView = nullptr;
//      if (m_pd2d1devicecontext)
//      {
//         m_pd2d1devicecontext->SetTarget(nullptr);
//
//      }
//      m_pd2d1devicecontext = nullptr;
//      m_d2dTargetBitmap = nullptr;
//
//   }
//
//
//   void direct2d_buffer::Present()
//   {
//
//      if (m_ephase != ::windowing_universal_windows::e_phase_present)
//      {
//
//         return ;
//
//      }
//
//      HRESULT hr = S_OK;
//
//      {
//
//         ::windowing::graphics_lock graphicslock(m_pwindow);
//
//         if (!defer_init())
//         {
//
//            return;
//
//         }
//
//         try
//         {
//
//            // The application may optionally specify "dirty" or "scroll" rects to improve efficiency
//            // in certain scenarios.  In this sample, however, we do not utilize those features.
//            DXGI_PRESENT_PARAMETERS parameters = {};
//
//            parameters.DirtyRectsCount = 0;
//
//            parameters.pDirtyRects = nullptr;
//
//            parameters.pScrollRect = nullptr;
//
//            parameters.pScrollOffset = nullptr;
//
//            if (m_swapChain == nullptr)
//            {
//
//               return;
//
//            }
//
//            {
//
//
//               // The first argument instructs DXGI to block until VSync, putting the application
//               // to sleep until the next VSync. This ensures we don't waste any cycles rendering
//               // frames that will never be displayed to the screen.
//               hr = m_swapChain->Present1(1, 0, &parameters);
//
//               if (directx::directx()->m_pd3devicecontext.Get())
//               {
//
//                  if (m_d3dRenderTargetView.Get())
//                  {
//
//                     // Discard the contents of the render target.
//                     // This is a valid operation only when the existing contents will be entirely
//                     // overwritten. If dirty or scroll rects are used, this call should be erased.
//                     directx::directx()->m_pd3devicecontext1->DiscardView(m_d3dRenderTargetView.Get());
//
//                  }
//
//                  if (m_d3dDepthStencilView.Get())
//                  {
//
//                     // Discard the contents of the depth stencil.
//                     directx::directx()->m_pd3devicecontext1->DiscardView(m_d3dDepthStencilView.Get());
//
//                  }
//
//               }
//
//               g_pimagea->erase_all();
//
//            }
//
//            // If the device was erased either by a disconnect or a driver upgrade, we
//            // must recreate all device resources.
//            if (hr == DXGI_ERROR_DEVICE_REMOVED)
//            {
//
//               HandleDeviceLost();
//
//            }
//            else
//            {
//               if (FAILED(hr))
//               {
//
//                  ::universal_windows::throw_if_failed(hr);
//
//
//               }
//
//            }
//
//         }
//         catch (...)
//         {
//
//         }
//
//         m_ephase = ::windowing_universal_windows::e_phase_draw;
//
//      }
//
//      //if (m_windowSizeChangeInProgress)
//      //{
//
//      //   m_windowSizeChangeInProgress = false;
//
//      //   m_window->Dispatcher->RunAsync(CoreDispatcherPriority::Normal, ref ___new ::winrt::Windows::UI::Core::DispatchedHandler([this]()
//      //   {
//
//      // A window int_size change has been initiated and the app has just completed presenting
//      // the first frame with the ___new size. Notify the resize manager so we can short
//      // circuit any resize animation and prevent unnecessary delays.
//      //      CoreWindowResizeManager::GetForCurrentView()->NotifyLayoutCompleted();
//
//      //   }));
//
//      //}
//
//   }
//
//
//   void direct2d_buffer::ValidateDevice()
//   {
//
//      ::draw2d::lock draw2dlock;
//      // The D3D Device is no longer valid if the default adapter changes or if
//      // the device has been erased.
//
//      // First, get the information for the adapter related to the current device.
//
//      comptr<IDXGIDevice1> dxgiDevice;
//      comptr<IDXGIAdapter> deviceAdapter;
//      DXGI_ADAPTER_DESC deviceDesc;
//      ::universal_windows::throw_if_failed(directx::directx()->m_pd3device.As(&dxgiDevice));
//      ::universal_windows::throw_if_failed(dxgiDevice->GetAdapter(&deviceAdapter));
//      ::universal_windows::throw_if_failed(deviceAdapter->GetDesc(&deviceDesc));
//
//      // Next, get the information for the default adapter.
//
//      comptr<IDXGIFactory2> dxgiFactory;
//      comptr<IDXGIAdapter1> currentAdapter;
//      DXGI_ADAPTER_DESC currentDesc;
//      ::universal_windows::throw_if_failed(CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory)));
//      ::universal_windows::throw_if_failed(dxgiFactory->EnumAdapters1(0,&currentAdapter));
//      ::universal_windows::throw_if_failed(currentAdapter->GetDesc(&currentDesc));
//
//      // If the adapter LUIDs don't match, or if the device reports that it has been erased,
//      // a ___new D3D device must be created.
//
//      if((deviceDesc.AdapterLuid.LowPart != currentDesc.AdapterLuid.LowPart) ||
//            (deviceDesc.AdapterLuid.HighPart != currentDesc.AdapterLuid.HighPart) ||
//            FAILED(directx::directx()->m_pd3device->GetDeviceRemovedReason()))
//      {
//         // Release references to resources related to the old device.
//         dxgiDevice = nullptr;
//         deviceAdapter = nullptr;
//
//         // Create a ___new device and __swap chain.
//         HandleDeviceLost();
//
//      }
//
//   }
//
//
//   //HRESULT direct2d_buffer::Render()
//   //{
//
//   //   ::draw2d::lock draw2dlock;
//
//   //   if (!defer_init())
//   //   {
//
//   //      return E_FAIL;
//
//   //   }
//
//   //   m_pd2d1devicecontext->BeginDraw();
//
//   //   auto colorBackground = ::winrt::Windows::UI::ViewManagement::UISettings().GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);
//
//   //   D2D1_COLOR_F color32;
//
//   //   color32.a = 1.0f;
//   //   color32.r = colorBackground.R / 255.f;
//   //   color32.g = colorBackground.G / 255.f;
//   //   color32.b = colorBackground.B / 255.f;
//
//   //   m_pd2d1devicecontext->Clear(color32);
//
//   //   m_pd2d1devicecontext->SetTransform(D2D1::Matrix3x2F::Identity());
//
//   //   ::draw2d::graphics_pointer dc(e_create_new, ::get_context_system());
//
//   //   dc->attach((ID2D1DeviceContext *) m_pd2d1devicecontext.Get());
//
//   //   auto pimpl = session()->m_puserinteractionHost->m_pimpl;
//
//   //   //throw_todo();
//
//   //   //if (pimpl.is_set())
//   //   //{
//
//   //   //   pimpl->_001UpdateBuffer();
//
//   //   //   ::pointer<::window_double_buffer>pbuffer = pimpl->m_spgraphics;
//
//   //   //   if (pbuffer.is_set())
//   //   //   {
//
//   //   //      int_size sz = pbuffer->get_buffer().get_size();
//
//   //   //      ::draw2d::graphics_pointer & pgraphics = pbuffer->get_buffer().get_graphics();
//
//   //   //      //pgraphics->fill_solid_rect_dim(300, 300, 100, 100, argb(255, 200, 60, 80));
//
//   //   //      dc->from(sz, pgraphics);
//
//   //   //   }
//
//   //   //}
//
//   //   ////_001UpdateBuffer();
//
//   //   ////Sys(::get_context_system()).m_possystemwindow->m_puserinteraction->_000OnDraw(m_pimage->g());
//
//   //   ////dc->from(m_pimage->get_size(), m_pimage->g());
//   //   ////dc->from(m_pimage->get_size(), m_pimage->g());
//
//   //   ////synchronouslock.lock();
//
//   //   //dc->detach();
//
//
//   //   //// We ignore D2DERR_RECREATE_TARGET here. This error indicates that the device
//   //   //// is lost. It will be handled during the next call to Present.
//   //   //HRESULT hr = m_pd2d1devicecontext->EndDraw();
//
//   //   //if(FAILED(hr))
//   //   //{
//
//   //   //   if(hr == D2DERR_RECREATE_TARGET)
//   //   //   {
//
//   //   //      trace_hr("direct2d_buffer::Render, EndDraw", hr);
//
//   //   //   }
//   //   //   else if(hr == D2DERR_WRONG_STATE)
//   //   //   {
//
//   //   //      trace_hr("direct2d_buffer::Render, EndDraw",hr);
//
//   //   //   }
//   //   //   else
//   //   //   {
//
//   //   //      trace_hr("direct2d_buffer::Render, EndDraw",hr);
//
//   //   //   }
//
//   //   //}
//
//   //   // return hr;
//
//   //   return E_FAIL;
//
//   //}
//
//
//} // namespace windowing_universal_windows
//
//
//
