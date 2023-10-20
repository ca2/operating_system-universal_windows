#pragma once


//class directx;


namespace windowing_universal_windows
{


   //class application :
   //   public impact,
   //   public winrt::implements < application, ::winrt::Windows::ApplicationModel::Core::IFrameworkViewSource, ::winrt::Windows::ApplicationModel::Core::IFrameworkView>
   //{
   //public:

   //   //Windows::ApplicationModel::Core::CoreApplication::Run(App());

   //   ::winrt::Windows::Foundation::Point                      m_pointLastCursor;

   //   ::u32                                                    m_dwMouseMoveThrottle;

   //   ::duration                                                   m_durationLastMouseMove;

   //   ::winrt::Windows::UI::ViewManagement::UISettings         m_puisettings = nullptr;

   //   string                                                   m_strId;

   //   //impact *                                               m_pimpact;

   //   bool                                                     m_bFontopusShift;

   //   ::mutex                                                  m_mutex;

   //   //::pointer<directx_interaction>                          m_pdxi;

   //   bool                                                     m_bLeftButton;

   //   bool                                                     m_bMiddleButton;

   //   bool                                                     m_bRightButton;

   //   ::winrt::Windows::Foundation::Rect                       m_rectangleLastWindowRect;
   //   ::winrt::Windows::Foundation::Rect                       m_rectangleInputContentRect;
   //   ::winrt::Windows::Foundation::Rect                       m_rectangleInputSelectionRect;


   //   application();


   //   virtual ::e_status initialize_application(::aura::system * psystem, const ::string & strId);


   //   void install_directx_application_message_routing();

   //   void initialize_directx_application();

   //   virtual wide_string get_input_text();
   //   virtual bool set_input_text(const wide_string & wstr);


   //   //::aura::system * get_context_system() const;




   //   // IFrameworkView Methods
   //   void Initialize(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView);
   //   void SetWindow(::winrt::Windows::UI::Core::CoreWindow const & window);
   //   virtual void Load(winrt::param::hstring entryPoint);
   //   virtual void Run();
   //   virtual void Uninitialize();


   //   virtual ::winrt::Windows::Foundation::Rect window_rectangle() override;
   //   virtual ::winrt::Windows::Foundation::Point get_cursor_position() override;

   //   virtual ::winrt::Windows::Foundation::Rect get_input_content_rect() override;
   //   virtual ::winrt::Windows::Foundation::Rect get_input_selection_rect() override;


   //   ~application() override;
      
      __DECLARE_APPLICATION_RELEASE_TIME();


   //
   //   void OnUISettingsColorValuesChange(::winrt::Windows::UI::ViewManagement::UISettings, ::winrt::Windows::Foundation::IInspectable);


   //   // Event Handlers
   //   void OnWindowSizeChanged(
   //   _In_ ::winrt::Windows::UI::Core::CoreWindow sender,
   //   _In_ ::winrt::Windows::UI::Core::WindowSizeChangedEventArgs args
   //   );

   //   void on_window_size_changed(::winrt::Windows::UI::Core::CoreWindow  sender, const ::size_i32 & size);

   //   void DpiChanged(::winrt::Windows::Graphics::Display::DisplayInformation  sender, ::winrt::Windows::Foundation::IInspectable);

   //   void DisplayContentsInvalidated(::winrt::Windows::Graphics::Display::DisplayInformation  sender, ::winrt::Windows::Foundation::IInspectable);

   //   void OnActivated(
   //   ::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView,
   //   ::winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs const & args
   //   );

   //   void OnSuspending(
   //   ::winrt::Windows::Foundation::IInspectable const & sender,
   //   ::winrt::Windows::ApplicationModel::SuspendingEventArgs const & args
   //   );

   //   void OnResuming(
   //      ::winrt::Windows::Foundation::IInspectable const & sender,
   //      ::winrt::Windows::Foundation::IInspectable const & args
   //   );

   //   void OnWindowClosed(::winrt::Windows::UI::Core::CoreWindow  sender, ::winrt::Windows::UI::Core::CoreWindowEventArgs  args);
   //   void OnWindowVisibilityChanged(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs args);

   //   void OnPointerMoved(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);

   //   void OnCharacterReceived(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs args);
   //   void OnKeyDown(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args);
   //   void OnKeyUp(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args);
   //   void OnPointerPressed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);
   //   void OnPointerReleased(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);


   //   //comptr<ID2D1SolidColorBrush>                    m_blackBrush;
   //   //comptr<IDWriteTextFormat>                       m_textFormat;
   //   //comptr<IDWriteTypography>                       m_textTypography;
   //   //comptr<IDWriteTextLayout>                       m_textLayout;
   //   //SampleOverlay           
   //   
   //   ::winrt::Windows::ApplicationModel::Core::IFrameworkView  CreateView();

   //};


   //class directx_application_source :
   //   
   //{
   //public:

   //   
   //   ::aura::system *     acmesystem();

   //   string               m_strId;


   //   directx_application_source(::aura::system * paxissystem, const ::string & strId);

   ////public:

   //   ::winrt::Windows::ApplicationModel::Core::IFrameworkView  CreateView();

   //};


   //CLASS_DECL_AURA directx_application_source  new_directx_application_source(::aura::system * psystem, const ::string & str);


} // namespace windowing_universal_windows



