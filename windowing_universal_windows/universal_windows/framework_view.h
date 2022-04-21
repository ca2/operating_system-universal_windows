// from window by Camilo 2022-03-25 08:54 BRT <3CamiloSasukeThomasBorregaardSoerensen
#pragma once


namespace windowing_universal_windows
{


   class framework_view :
      public winrt::implements< framework_view, ::winrt::Windows::ApplicationModel::Core::IFrameworkView>
   {
   public:


      window * m_pwindow;


      framework_view(window * pwindow);


      void Initialize(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView);
      void SetWindow(::winrt::Windows::UI::Core::CoreWindow const & window);
      virtual void Load(winrt::param::hstring entryPoint);
      virtual void Run();
      virtual void Uninitialize();



   };


} // namespace windowing_universal_windows



