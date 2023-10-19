// from window by Camilo 2022-03-25 08:54 BRT <3CamiloSasukeThomasBorregaardSoerensen
#pragma once


#undef new
#include <winrt/Windows.ApplicationModel.Core.h>
//
//
//namespace windowing_universal_windows
//{
//
//
//   class framework_impact :
//      public winrt::implements< framework_impact, ::winrt::Windows::ApplicationModel::Core::IFrameworkView>
//   {
//   public:
//
//
//      window * m_pwindow;
//
//
//      framework_impact(window * pwindow);
//
//
//      void Initialize(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView);
//      void SetWindow(::winrt::Windows::UI::Core::CoreWindow const & window);
//      virtual void Load(winrt::param::hstring entryPoint);
//      virtual void Run();
//      virtual void Uninitialize();
//
//
//
//   };
//
//
//} // namespace windowing_universal_windows
//




#include <winrt/Windows.ApplicationModel.Core.h>


namespace windowing_universal_windows
{
   using namespace winrt;
   using namespace Windows;
   using namespace Windows::ApplicationModel::Activation;
   using namespace Windows::ApplicationModel::Core;
   using namespace Windows::Foundation::Numerics;
   using namespace Windows::UI;
   using namespace Windows::UI::Core;
   using namespace Windows::UI::Composition;


   class application :
      public winrt::implements < application, ::winrt::Windows::ApplicationModel::Core::IFrameworkViewSource, ::winrt::Windows::ApplicationModel::Core::IFrameworkView >
   {
   public:

      windowing * m_pwindowing;
      //winrt::agile_ref<CoreWindow> m_window;
      //winrt::com_ptr<IDXGISwapChain1> m_swapChain;
      //winrt::com_ptr<ID3D11Device1> m_d3dDevice;
      //winrt::com_ptr<ID3D11DeviceContext1> m_d3dDeviceContext;
      //winrt::com_ptr<ID3D11RenderTargetView> m_renderTargetView;

      application(windowing * pwindowing);

      IFrameworkView CreateView();

      // This method is called on application launch.
      void Initialize(CoreApplicationView const & applicationView);

      void Load(winrt::hstring const & /*entryPoint*/);

      void OnActivated(CoreApplicationView const & /* applicationView */, IActivatedEventArgs const & /* args */);

      // This method is called after Load.
      void Run();

      // This method is called after Initialize.
      void SetWindow(CoreWindow const & window);

      // This method is called before the application exits.
      void Uninitialize();


      //// This method creates all application resources that depend on
      //// the application window size.  It is called at app initialization,
      //// and whenever the application window size changes.
      //void CreateWindowSizeDependentResources()
      //{
      //   if (m_swapChain != nullptr)
      //   {
      //      // If the swap chain already exists, resize it.
      //      winrt::check_hresult(
      //          m_swapChain->ResizeBuffers(
      //             2,
      //             0,
      //             0,
      //             DXGI_FORMAT_B8G8R8A8_UNORM,
      //             0
      //          )
      //      );
      //   }
      //   else
      //   {
      //      // If the swap chain does not exist, create it.
      //      DXGI_SWAP_CHAIN_DESC1 swapChainDesc = { 0 };

      //      swapChainDesc.Stereo = false;
      //      swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
      //      swapChainDesc.Scaling = DXGI_SCALING_NONE;
      //      swapChainDesc.Flags = 0;

      //      // Use automatic sizing.
      //      swapChainDesc.Width = 0;
      //      swapChainDesc.Height = 0;

      //      // This is the most common swap chain format.
      //      swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;

      //      // Don't use multi-sampling.
      //      swapChainDesc.SampleDesc.Count = 1;
      //      swapChainDesc.SampleDesc.Quality = 0;

      //      // Use two buffers to enable flip effect.
      //      swapChainDesc.BufferCount = 2;

      //      // We recommend using this swap effect for all applications.
      //      swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;


      //      // Once the swap chain description is configured, it must be
      //      // created on the same adapter as the existing D3D Device.

      //      // First, retrieve the underlying DXGI Device from the D3D Device.
      //      winrt::com_ptr<IDXGIDevice2> dxgiDevice{ m_d3dDevice.as<IDXGIDevice2>() };

      //      // Ensure that DXGI does not queue more than one frame at a time. This both reduces
      //      // latency and ensures that the application will only render after each VSync, minimizing
      //      // power consumption.
      //      winrt::check_hresult(
      //          dxgiDevice->SetMaximumFrameLatency(1)
      //      );

      //      // Next, get the parent factory from the DXGI Device.
      //      winrt::com_ptr<IDXGIAdapter> dxgiAdapter;
      //      winrt::check_hresult(
      //          dxgiDevice->GetAdapter(dxgiAdapter.put())
      //      );

      //      winrt::com_ptr<IDXGIFactory2> dxgiFactory;
      //      winrt::check_hresult(
      //          dxgiAdapter->GetParent(__uuidof(dxgiFactory), dxgiFactory.put_void())
      //      );

      //      // Finally, create the swap chain.
      //      winrt::check_hresult(
      //          dxgiFactory->CreateSwapChainForCoreWindow(
      //             m_d3dDevice.get(),
      //             winrt::get_unknown(m_window.get()),
      //             &swapChainDesc,
      //             nullptr, // allow on all displays
      //             m_swapChain.put()
      //          )
      //      );
      //   }

      //   // Once the swap chain is created, create a render target view.  This will
      //   // allow Direct3D to render graphics to the window.

      //   winrt::com_ptr<ID3D11Texture2D> backBuffer;
      //   winrt::check_hresult(
      //       m_swapChain->GetBuffer(0, __uuidof(backBuffer), backBuffer.put_void())
      //   );

      //   winrt::check_hresult(
      //       m_d3dDevice->CreateRenderTargetView(
      //          backBuffer.get(),
      //          nullptr,
      //          m_renderTargetView.put()
      //       )
      //   );

      //   // After the render target view is created, specify that the viewport,
      //   // which describes what portion of the window to draw to, should cover
      //   // the entire window.

      //   D3D11_TEXTURE2D_DESC backBufferDesc = { 0 };
      //   backBuffer->GetDesc(&backBufferDesc);

      //   D3D11_VIEWPORT viewport;
      //   viewport.TopLeftX = 0.0f;
      //   viewport.TopLeftY = 0.0f;
      //   viewport.Width = static_cast<float>(backBufferDesc.Width);
      //   viewport.Height = static_cast<float>(backBufferDesc.Height);
      //   viewport.MinDepth = D3D11_MIN_DEPTH;
      //   viewport.MaxDepth = D3D11_MAX_DEPTH;

      //   m_d3dDeviceContext->RSSetViewports(1, &viewport);
      //}

      // This method is called whenever the application window size changes.
//void OnWindowSizeChanged(CoreWindow const & /*sender*/, WindowSizeChangedEventArgs const & /* args */);

   };



} // namespace windowing_universal_windows



