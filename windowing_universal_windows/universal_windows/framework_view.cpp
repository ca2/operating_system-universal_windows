// from window by Camilo 2022-03-25 09:00 BRT <3CamiloSasukeThomasBorregaardSoerensen
#include "framework.h"


namespace windowing_universal_windows
{


   framework_view::framework_view(window * pwindow) :
      m_pwindow(pwindow)
   {



   }


   void framework_view::Initialize(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & coreapplicationview)
   {

      ::winrt::Windows::UI::ViewManagement::UISettings uisettings;

      auto uicolorBackground = uisettings.GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

      ::color::color colorBackground;

      colorBackground.alpha = 255;
      colorBackground.red = uicolorBackground.R;
      colorBackground.green = uicolorBackground.G;
      colorBackground.blue = uicolorBackground.B;

      m_pwindow->m_psystem->m_pnode->background_color(colorBackground);

      m_pwindow->m_coreapplicationview = coreapplicationview;

      m_pwindow->m_coreapplicationview.Activated(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::ApplicationModel::Core::CoreApplicationView, ::winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs>(m_pwindow, &window::OnActivated));

      ::winrt::Windows::ApplicationModel::Core::CoreApplication::Suspending(::winrt::Windows::Foundation::EventHandler<::winrt::Windows::ApplicationModel::SuspendingEventArgs>(m_pwindow, &window::OnSuspending));

      ::winrt::Windows::ApplicationModel::Core::CoreApplication::Resuming(::winrt::Windows::Foundation::EventHandler<::winrt::Windows::Foundation::IInspectable >(m_pwindow, &window::OnResuming));

   }


   void framework_view::SetWindow(::winrt::Windows::UI::Core::CoreWindow const & window)
   {

      m_pwindow->m_window = window;

      m_pwindow->m_resizemanager = ::winrt::Windows::UI::Core::CoreWindowResizeManager::GetForCurrentView();

      m_pwindow->m_resizemanager.ShouldWaitForLayoutCompletion(true);

      //auto coreTitleBar = ::winrt::Windows::ApplicationModel::Core::CoreApplication::GetCurrentView()->TitleBar;

      //coreTitleBar->ExtendViewIntoTitleBar = true;

      m_pwindow->m_tokenActivated = m_pwindow->m_window.Activated(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::WindowActivatedEventArgs>(m_pwindow, &window::CoreWindow_WindowActivated));

      m_pwindow->m_tokenClosed = m_pwindow->m_window.Closed(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CoreWindowEventArgs>(m_pwindow, &window::CoreWindow_CoreWindowClosed));

      m_pwindow->m_tokenKeyDown = m_pwindow->m_window.KeyDown(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs>(m_pwindow, &window::CoreWindow_KeyDown));

      m_pwindow->m_tokenPointerPressed = m_pwindow->m_window.PointerPressed(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs>(m_pwindow, &window::CoreWindow_PointerPressed));

      auto manager = ::winrt::Windows::UI::Text::Core::CoreTextServicesManager::GetForCurrentView();

      m_pwindow->m_editcontext = manager.CreateEditContext();

      // Get the Input Pane so we can programmatically hide and show it.
      m_pwindow->m_inputpane = ::winrt::Windows::UI::ViewManagement::InputPane::GetForCurrentView();

      // For demonstration purposes, this sample sets the Input Pane display policy to Manual
      // so that it can manually show the software keyboard when the control gains focus and
      // dismiss it when the control loses focus. If you leave the policy as Automatic, then
      // the system will hide and show the Input Pane for you. Note that on Desktop, you will
      // need to implement the UIA text pattern to get expected automatic behavior.
      m_pwindow->m_editcontext.InputPaneDisplayPolicy(::winrt::Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy::Automatic);

      // Set the input scope to Text because this text box is for any text.
      // This also informs software keyboards to show their regular
      // text entry layout.  There are many other input scopes and each will
      // inform a keyboard layout and text behavior.
      m_pwindow->m_editcontext.InputScope(::winrt::Windows::UI::Text::Core::CoreTextInputScope::Text);

      // The system raises this event to request a specific range of text.
      m_pwindow->m_editcontext.TextRequested(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextTextRequestedEventArgs>(m_pwindow, &window::EditContext_TextRequested));

      // The system raises this event to request the current selection.
      m_pwindow->m_editcontext.SelectionRequested(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs>(m_pwindow, &window::EditContext_SelectionRequested));

      // The system raises this event when it wants the edit control to erase focus.
      m_pwindow->m_editcontext.FocusRemoved(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::Foundation::IInspectable>(m_pwindow, &window::EditContext_FocusRemoved));

      // The system raises this event to update text in the edit control.
      m_pwindow->m_editcontext.TextUpdating(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs>(m_pwindow, &window::EditContext_TextUpdating));

      // The system raises this event to change the selection in the edit control.
      m_pwindow->m_editcontext.SelectionUpdating(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs>(m_pwindow, &window::EditContext_SelectionUpdating));

      // The system raises this event when it wants the edit control
      // to apply formatting on a r::winrt::Windows::Foundation::Tange of text.
      m_pwindow->m_editcontext.FormatUpdating(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs>(m_pwindow, &window::EditContext_FormatUpdating));

      // The system raises this event to request layout information.
      // This is used to help choose a position for the IME candidate window.
      m_pwindow->m_editcontext.LayoutRequested(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs>(m_pwindow, &window::EditContext_LayoutRequested));

      // The system raises this event to notify the edit control
      // that the string composition has started.
      m_pwindow->m_editcontext.CompositionStarted(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs>(m_pwindow, &window::EditContext_CompositionStarted));

      // The system raises this event to notify the edit control
      // that the string composition is finished.
      m_pwindow->m_editcontext.CompositionCompleted(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs>(m_pwindow, &window::EditContext_CompositionCompleted));

      // The system raises this event when the NotifyFocusLeave operation has
      // completed. Our sample does not use this event.
      m_pwindow->m_editcontext.NotifyFocusLeaveCompleted(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::Foundation::IInspectable>(m_pwindow, &window::EditContext_NotifyFocusLeaveCompleted));

      // Set our initial UI.
      m_pwindow->UpdateTextUI();

      m_pwindow->UpdateFocusUI();

      //window::SetWindow(window);

      //pbuffer = __new(directx_base);

      //pbuffer->m_psystem = m_psystem;

      auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

      //pbuffer->Initialize(window, displayinformation.LogicalDpi());

      //pbuffer->initialize(m_psystem->m_papplicationStartup);

      //install_directx_application_message_routing();

      //initialize_directx_application();

      //m_bXXXFirst = true;

      //m_psystem->m_paurasystem->get_session()->m_puser->m_pwindowing->m_pwindowFirst = this;

      //m_psystem->m_paurasystem->get_session()->m_puser->m_pwindowing->m_bXXXFirst = true;

      auto pnode = m_pwindow->m_psystem->m_pnode->m_pWindowingUniversalWindowsNode;

      if (!pnode->m_bAppInit)
      {

         pnode->app_init();

      }

      if (!pnode->m_bHasNodePostedSystemInitialRequest)
      {

         pnode->m_bHasNodePostedSystemInitialRequest = true;

         m_pwindow->m_psystem->post_initial_request();

      }

   }


   void framework_view::Load(winrt::param::hstring entryPoint)
   {

   }


   void framework_view::Run()
   {

      m_pwindow->m_window.Activate();

      m_pwindow->m_window.Dispatcher().ProcessEvents(::winrt::Windows::UI::Core::CoreProcessEventsOption::ProcessUntilQuit);

   }


   void framework_view::Uninitialize()
   {

   }

} // namespace windowing_universal_windows



