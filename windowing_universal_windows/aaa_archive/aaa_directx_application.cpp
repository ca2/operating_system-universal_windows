#include "framework.h"
#include "_windows_runtime.h"
//#include "aura/node/operating_system/universal_windows/_.h"
//#include "aura/node/universal_windows/_uwp.h"
//#include "aura/node/universal_windows/buffer.h"
//#include "_uwp.h"
//
//
//int g_iMouse;
//
//
////#undef ::auraacmesystem()
////#undef Platform
////
////
////using namespace Platform;
////using namespace Microsoft::WRL;
////using namespace ::winrt::Windows::Foundation;
////using namespace ::winrt::Windows::UI::Core;
////using namespace ::winrt::Windows::ApplicationModel;
////using namespace ::winrt::Windows::ApplicationModel::Core;
////using namespace ::winrt::Windows::ApplicationModel::Activation;
////using namespace ::winrt::Windows::auraacmesystem();
////using namespace ::winrt::Windows::Graphics::Display;
////using namespace ::winrt::Windows::auraacmesystem()::Threading;
////
////
//
//namespace windowing_universal_windows
//{
//
//
//   __IMPLEMENT_APPLICATION_RELEASE_TIME();


   application::application()
//   {
//
//
//
//   }
//
//
//   ::e_status application::initialize_application(::aura::system * psystem, const ::string & strId)
//   {
//
//      //::direct2d::defer_direct2d_initialize();
//
//      m_puisettings = ::winrt::Windows::UI::ViewManagement::UISettings();
//
//      add_factory_item < ::windowing_universal_windows::buffer, ::graphics::graphics >();
//
//      m_dwMouseMoveThrottle = 10;
//
//      //m_pimpl = nullptr;
//
//      m_pointLastCursor.X = 0;
//      m_pointLastCursor.Y = 0;
//
//      m_bLeftButton = false;
//      m_bMiddleButton = false;
//      m_bRightButton = false;
//
//      m_strId = strId;
//
//      if (!main_initialize())
//      {
//
//         throw ::exception(error_failed, "Failed to run main_initialize at application constructor.");
//
//      }
//
//      system() = psystem;
//
//      //      psystem->get_session()->m_frameworkview = this;
//
//      //m_pdxi = psystem->m_papplicationStartup->__create_new < directx_interaction>();
//
//      return ::success;
//
//   }
//
//
//   application::~application()
//   {
//
//      ::direct2d::finalize();
//
//   }
//
//
//   void application::initialize_directx_application()
//   {
//
//      //direct2d::defer_initialize();
//
//      int nReturnCode = 0;
//
//      if (!system()->m_htask)
//      {
//
//         if (!system()->begin_synch())
//         {
//
//            throw ::exception(error_failed, "failed to begin_synch the system");
//
//         }
//
//      }
//
//      //auto estatus = m_pdxi->initialize(system());
//
//      //if (!estatus)
//      //{
//
//      //   throw ::exception(error_resource);
//
//      //}
//
//      //session() = this;
//
//      //session()->m_puserprimitiveHost = m_pdxi;
//
//      //::user::os_calc_dark_mode();
//
//      auto pcs = __allocate ::user::system();
//
//      auto puserinteractionHost = session()->m_puserprimitiveHost;
//
//      auto routine = [this]()
//      {
//
//         session()->system()->windowing()->windowing_sync(15_s, __routine([this]()
//            {
//
//               //m_pdirectxbase->m_windowBounds = m_window->Bounds;
//
//               //auto pchanged = ref ___new ::winrt::Windows::UI::Core::WindowSizeChangedEventArgs();
//
//               ::int_size size((LONG) m_window.Bounds().Width, (LONG) m_window.Bounds().Height);
//
//               //pchanged->Size.Height = m_window.Bounds().Height;
//
//               on_window_size_changed(m_window, size);
//
//            }));
//
//         auto puserinteractionHost = session()->m_puserprimitiveHost;
//
//         //auto puserinteraction = m_pdxi;
//
//         //puserinteraction->display(e_display_normal);
//
//         //puserinteraction->set_need_layout();
//
//         //puserinteraction->set_need_redraw();
//
//         //puserinteraction->post_redraw();
//
//
//      };
//
//      pcs->m_procedureSuccess = __routine(routine);
//
//      //m_pimpl = __create < ::windowing::window >();
//
//      ::double_rectangle rectangle;
//
//      rectangle.left() = (LONG) m_window.Bounds().X;
//      rectangle.top() = (LONG) m_window.Bounds().Y;
//      rectangle.right() = (LONG) (m_window.Bounds().X + m_window.Bounds().Width);
//      rectangle.top() = (LONG) (m_window.Bounds().Y + m_window.Bounds().Height);
//
//      //puserinteractionHost->m_puiThis->place(rectangle);
//
//      m_pwindow = system()->m_papplicationStartup->__create_new < ::windowing_universal_windows::window >();
//
//      system()->get_session()->system()->windowing()->m_pwindowFirst = m_pwindow;
//
//      system()->get_session()->system()->windowing()->m_bXXXFirst = true;
//
//      m_pwindow->m_window = m_window;
//
//      m_pdirectxbase->m_pwindow = m_pwindow;
//
//      m_pwindow->m_pdirectxbase = m_pdirectxbase;
//
//      //m_pwindow = this;
//
//      pcs->m_pimpl = m_pwindow->m_pimpl;
//
//      system()->__refer(system()->m_pimplMain, m_pwindow->m_pimpl);
//
//      //m_pwindow->m_bNotifyLayoutCompletedPending = true;
//
//      //if (!puserinteractionHost->m_puiThis->create_window_ex(pcs))
//      //{
//
//      //   throw ::exception(resource_exception("Couldn't create Main Window"));
//
//      //   return;
//
//      //}
//
//   }
//
//
//   void application::Initialize(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView)
//   {
//
//      impact::Initialize(applicationView);
//
//      applicationView.Activated(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::ApplicationModel::Core::CoreApplicationView, ::winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs>(this, &application::OnActivated));
//
//      ::winrt::Windows::ApplicationModel::Core::CoreApplication::Suspending(::winrt::Windows::Foundation::EventHandler<::winrt::Windows::ApplicationModel::SuspendingEventArgs>(this, &application::OnSuspending));
//
//      ::winrt::Windows::ApplicationModel::Core::CoreApplication::Resuming(::winrt::Windows::Foundation::EventHandler<::winrt::Windows::Foundation::IInspectable >(this, &application::OnResuming));
//
//   }
//
//
//   void application::install_directx_application_message_routing()
//   {
//
//      m_puisettings.ColorValuesChanged(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::ViewManagement::UISettings, winrt::Windows::Foundation::IInspectable>(this, &application::OnUISettingsColorValuesChange));
//
//      auto window = m_window;
//
//      window.VisibilityChanged(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs>(this, &application::OnWindowVisibilityChanged));
//
//      window.PointerCursor(::winrt::Windows::UI::Core::CoreCursor(::winrt::Windows::UI::Core::CoreCursorType::Arrow, 0));
//
//      window.SizeChanged(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::WindowSizeChangedEventArgs>(this, &application::OnWindowSizeChanged));
//
//      window.PointerMoved(::winrt::Windows::Foundation::TypedEventHandler <::winrt::Windows::UI::Core::CoreWindow , ::winrt::Windows::UI::Core::PointerEventArgs>(this, &application::OnPointerMoved));
//
//      window.CharacterReceived(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs>(this, &application::OnCharacterReceived));
//
//      window.KeyDown(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs>(this, &application::OnKeyDown));
//
//      window.KeyUp(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs>(this, &application::OnKeyUp));
//
//      window.PointerPressed(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs>(this, &application::OnPointerPressed));
//
//      window.PointerReleased(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow , ::winrt::Windows::UI::Core::PointerEventArgs >(this, &application::OnPointerReleased));
//
//      auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();
//
//      displayinformation.DpiChanged(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::Graphics::Display::DisplayInformation, ::winrt::Windows::Foundation::IInspectable > (this, &application::DpiChanged));
//
//      displayinformation.DisplayContentsInvalidated(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::Graphics::Display::DisplayInformation, ::winrt::Windows::Foundation::IInspectable >(this, &application::DisplayContentsInvalidated));
//
//   }
//
//
//   void application::SetWindow(::winrt::Windows::UI::Core::CoreWindow const & window)
//   {
//
//      impact::SetWindow(window);
//
//      m_pdirectxbase = __allocate directx_base();
//
//      m_pdirectxbase->system() = system();
//
//      auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();
//
//      //m_pdirectxbase->Initialize(window, displayinformation.LogicalDpi());
//
//      m_pdirectxbase->initialize(system()->m_papplicationStartup);
//
//      install_directx_application_message_routing();
//
//      initialize_directx_application();
//
//   }
//
//
//   void application::Load(winrt::param::hstring entryPoint)
//   {
//
//   }
//
//
//   void application::Run()
//   {
//
//      m_window.Dispatcher().ProcessEvents(::winrt::Windows::UI::Core::CoreProcessEventsOption::ProcessUntilQuit);
//
//   }
//
//
//   void application::Uninitialize()
//   {
//
//   }
//
//
//   void application::OnUISettingsColorValuesChange(::winrt::Windows::UI::ViewManagement::UISettings uisettings, ::winrt::Windows::Foundation::IInspectable inpectable)
//   {
//
//      ///::user::os_calc_dark_mode();
//
//   }
//
//
//   void application::OnWindowSizeChanged(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::WindowSizeChangedEventArgs args)
//   {
//
//      ::int_size size((LONG) args.Size().Width, (LONG) args.Size().Height);
//
//      on_window_size_changed(sender, size);
//
//   }
//
//
//   void application::on_window_size_changed(::winrt::Windows::UI::Core::CoreWindow sender, const ::int_size & size)
//   {
//
//      //m_pdirectxbase->m_size = size;
//
//      // m_pdirectxbase->set_size(size);
//
//      //m_rectangleLastWindowRect.Width = (float)m_pdirectxbase->width();
//
//      //m_rectangleLastWindowRect.Height = (float)m_pdirectxbase->height();
//
//      //m_pdirectxbase->OnWindowSizeChange();
//
//   }
//
// 
//   void application::DpiChanged(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable)
//   {
//
//      m_rectangleLastWindowRect = m_window.Bounds();
//
//      m_pdirectxbase->OnChangeDpi(sender.LogicalDpi());
//
//   }
//
//
//   void application::DisplayContentsInvalidated(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable)
//   {
//
//      // Ensure the D3D Device is available for rendering.
//
//      m_pdirectxbase->ValidateDevice();
//
//   }
//
//
//   void application::OnActivated(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView, ::winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs const & args)
//   {
//
//      m_window.Activate();
//
//      if (args != nullptr)
//      {
//
//         if (args.Kind() == ::winrt::Windows::ApplicationModel::Activation::ActivationKind::Protocol)
//         {
//
//            ::winrt::Windows::ApplicationModel::Activation::ProtocolActivatedEventArgs const & eventArgs = (::winrt::Windows::ApplicationModel::Activation::ProtocolActivatedEventArgs const &) args;
//
//            string str = eventArgs.Uri().AbsoluteUri().begin();
//
//            auto pcreate = system()->__create_new < ::create >();
//
//            pcreate->m_ecommand = ::command_protocol;
//
//            pcreate->m_payloadFile = str;
//
//            //system()->add_create(pcreate);
//
//            //auto papp = system()->m_papplicationStartup;
//
//            //if (papp == nullptr)
//            //{
//
//            //   papp = session()->m_papplicationCurrent;
//
//            //}
//
//            system()->post_object(e_message_system, e_system_message_create, pcreate);
//
//         }
//
//      }
//
//
//   }
//
//
//   void application::OnSuspending(::winrt::Windows::Foundation::IInspectable const & sender, ::winrt::Windows::ApplicationModel::SuspendingEventArgs const & args)
//   {
//
//   }
//
//
//   void application::OnResuming(::winrt::Windows::Foundation::IInspectable const & sender, ::winrt::Windows::Foundation::IInspectable const & args)
//   {
//
//   }
//
//
//   void application::OnCharacterReceived(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs args)
//   {
//
//      if(session() == nullptr)
//         return;
//
//      auto puserinteractionHost = session()->m_puserprimitiveHost->m_puiThis;
//
//      if (puserinteractionHost == nullptr)
//         return;
//
//      if (puserinteractionHost->m_pimpl == nullptr)
//         return;
//
//      ::pointer<::user::message>pusermessage;
//
//      auto pkey  = __allocate ::message::key();
//
//      pusermessage = pkey;
//
//      pkey->m_atom = e_message_char;
//      //pkey->m_playeredUserPrimitive = puserinteractionHost;
//      pkey->m_nChar = keycode_to_char(args.KeyCode());
//
//      puserinteractionHost->m_pimpl2->queue_message_handler(pusermessage);
//
//   }
//
//
//   void application::OnKeyDown(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args)
//   {
//      
//      if (args.VirtualKey() == ::winrt::Windows::System::VirtualKey::Shift)
//      {
//
//         m_bFontopusShift = true;
//
//      }
//
//      if (system() == nullptr)
//      {
//
//         return;
//
//      }
//
//      auto puserinteractionHost = session()->m_puserprimitiveHost->m_puiThis;
//
//      if (puserinteractionHost == nullptr)
//         return;
//
//      //if (puserinteractionHost->m_pimpl == nullptr)
//        // return;
//
//      ::pointer<::user::message>pusermessage;
//
//      auto pkey  = __allocate ::message::key();
//
//      pusermessage = pkey;
//
//      bool bTextFocus = m_puserinteraction->get_keyboard_focus() != nullptr;
//
//      bool bSpecialKey = false;
//
//      ::user::enum_key ekey = virtualkey_to_userkey(args.VirtualKey(), bSpecialKey);
//
//      if(bSpecialKey || !bTextFocus || session()->is_key_pressed(::user::e_key_control)
//         || session()->is_key_pressed(::user::e_key_alt))
//      {
//
//         pkey->m_atom                 = e_message_key_down;
//         //pkey->m_playeredUserPrimitive       = session()->m_puserinteractionHost;
//         pkey->m_nChar              = virtualkey_to_char(args.VirtualKey());
//         pkey->m_ekey               = ekey;
//         pkey->m_wparam             = pkey->m_nChar;
//         pkey->m_nFlags             = virtualkey_to_code(args.VirtualKey());
//         pkey->m_lparam             = pkey->m_nFlags << 16;
//         //pkey->m_strText            = m_strNewText;
//         //if (pkey->m_strText.has_character())
//         //{
//           // pkey->m_ekey = ::user::e_key_refer_to_text_member;
//         //}
//   //      pkey->m_key = args;
//
//
//         puserinteractionHost->m_pimpl->queue_message_handler(pusermessage);
//
//
//
//      }
//
//   }
//
//   void application::OnKeyUp(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args)
//   {
//
//      if(system() == nullptr)
//         return;
//
//      auto puserinteractionHost = session()->m_puserprimitiveHost->m_puiThis;
//
//      if (puserinteractionHost == nullptr)
//         return;
//
//      if (puserinteractionHost->m_pimpl == nullptr)
//         return;
//
//      ::pointer<::user::message>pusermessage;
//
//      ::message::key * pkey = ___new  ::message::key;
//
//      pusermessage = pkey;
//
//
//      if (args.VirtualKey() == ::winrt::Windows::System::VirtualKey::Shift)
//      {
//
//         m_bFontopusShift = false;
//
//      }
//      
//      bool bTextFocus = m_puserinteraction->get_keyboard_focus() != nullptr;
//
//      bool bSpecialKey = false;
//
//      ::user::enum_key ekey = virtualkey_to_userkey(args.VirtualKey(), bSpecialKey);
//
//      if (bSpecialKey || !bTextFocus)
//      {
//
//         pkey->m_atom = e_message_key_up;
//         //pkey->m_playeredUserPrimitive = session()->m_puserinteractionHost;
//         pkey->m_nChar = virtualkey_to_char(args.VirtualKey());
//         pkey->m_ekey = ekey;
//         pkey->m_wparam = pkey->m_nChar;
//
//
//         //      pkey->m_key = args;
//
//               //if (system()->m_psimpleui != nullptr && system()->m_psimpleui->is_window_visible())
//               //{
//               //   string str;
//               //   str = (char)pkey->m_nChar;
//               //   if (m_bFontopusShift)
//               //   {
//               //      if (pkey->m_nChar == 0xbe)
//               //      {
//               //         str = ">";
//               //      }
//               //      else if (str == "2")
//               //      {
//               //         str = "@";
//               //      }
//               //      else
//               //      {
//               //         str.make_upper();
//               //      }
//               //   }
//               //   else
//               //   {
//               //      if (pkey->m_nChar == 0xbe)
//               //      {
//               //         str = ".";
//               //      }
//               //   }
//               //   system()->m_psimpleui->on_char(virtualkey_to_userkey(args.VirtualKey), str);
//               //}
//               //else
//               //{
//         puserinteractionHost->m_pimpl->queue_message_handler(pusermessage);
//         //}
//
//      }
//
//
//
//   }
//
//
//   void application::OnWindowClosed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CoreWindowEventArgs args)
//   {
//
//   }
//
//
//   void application::OnWindowVisibilityChanged(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs args)
//   {
//
//      if (args.Visible())
//      {
//
//         if (m_pdirectxbase->m_bCoreWindowVisible.is_empty())
//         {
//
//            m_pdirectxbase->m_bCoreWindowVisible = true;
//
//         }
//         else if (m_pdirectxbase->m_bCoreWindowVisible.isFalse())
//         {
//
//            m_pdirectxbase->m_bCoreWindowVisible = true;
//
//            winrt::Windows::UI::Core::CoreWindow window = m_window;
//
//            if (window)
//            {
//
//               m_pdirectxbase->HandleDeviceLost();
//
//            }
//
//         }
//
//      }
//      else
//      {
//
//         if (m_pdirectxbase->m_bCoreWindowVisible)
//         {
//
//            m_pdirectxbase->m_bCoreWindowVisible = false;
//
//            m_pdirectxbase->DestroyWindowSizeDependentResources();
//
//         }
//
//      }
//
//   }
//
//   void application::OnPointerMoved(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args)
//   {
//
//      //if (m_dwMouseMoveThrottle && m_durationLastMouseMove.elapsed() < m_dwMouseMoveThrottle)
//      //{
//
//        // return;
//
//      //}
//
//      if(system() == nullptr)
//         return;
//
//      auto puserinteractionHost = session()->m_puserprimitiveHost->m_puiThis;
//
//      if (puserinteractionHost == nullptr)
//         return;
//
//      if (puserinteractionHost->m_pimpl == nullptr)
//         return;
//
//      ::pointer<::user::message>pusermessage;
//
//      ::winrt::Windows::UI::Input::PointerPoint pointerPoint = args.CurrentPoint();
//
//      ::g_iMouse = pointerPoint.PointerId();
//
//      ::message::mouse * pmouse = ___new ::message::mouse;
//
//      pusermessage = pmouse;
//
//      pmouse->m_point.x       = (int) pointerPoint.RawPosition().X;
//      pmouse->m_point.y       = (int) pointerPoint.RawPosition().Y;
//      pmouse->m_atom            = e_message_mouse_move;
//      //pmouse->m_playeredUserPrimitive  = session()->m_puserinteractionHost;
//
//      m_pointLastCursor = pointerPoint.RawPosition();
//
//      auto pimpl = puserinteractionHost->m_pimpl;
//
//      //pimpl->m_pointCursor.set(
//        // (LONG) pointerPoint.RawPosition().X, 
//        // (LONG) pointerPoint.RawPosition().Y);
//
//      puserinteractionHost->m_pimpl->queue_message_handler(pusermessage);
//
//      m_durationLastMouseMove= ::duration::now();
//
//   }
//
//
//   void application::OnPointerPressed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args)
//   {
//
//      if (system() == nullptr)
//      {
//
//         return;
//
//      }
//
//      auto puserinteractionHost = session()->m_puserprimitiveHost->m_puiThis;
//
//      if (puserinteractionHost == nullptr)
//      {
//
//         return;
//
//      }
//
//      if (puserinteractionHost->m_pimpl == nullptr)
//      {
//
//         return;
//
//      }
//
//      ::pointer<::user::message>pusermessage;
//
//      ::winrt::Windows::UI::Input::PointerPoint pointerPoint = args.CurrentPoint();
//
//      ::g_iMouse = pointerPoint.PointerId();
//
//      ::message::mouse * pmouse = ___new  ::message::mouse;
//
//      pusermessage = pmouse;
//
//      pmouse->m_point.x = (int) pointerPoint.RawPosition().X;
//
//      pmouse->m_point.y = (int) pointerPoint.RawPosition().Y;
//
//      if(args.CurrentPoint().Properties().IsLeftButtonPressed() && !m_bLeftButton)
//      {
//
//         pmouse->m_atom     = e_message_left_button_down;
//
//         m_bLeftButton           = true;
//         m_bMiddleButton         = false;
//         m_bRightButton          = false;
//
//      }
//      else if(args.CurrentPoint().Properties().IsRightButtonPressed() && !m_bRightButton)
//      {
//
//         pmouse->m_atom     = e_message_right_button_down;
//
//         m_bLeftButton           = false;
//         m_bMiddleButton         = false;
//         m_bRightButton          = true;
//
//      }
//      else if(args.CurrentPoint().Properties().IsMiddleButtonPressed() && !m_bMiddleButton)
//      {
//
//         pmouse->m_atom     = e_message_middle_button_down;
//
//         m_bLeftButton           = false;
//         m_bMiddleButton         = true;
//         m_bRightButton          = false;
//
//      }
//
//      //pmouse->m_playeredUserPrimitive = session()->m_puserinteractionHost;
//
//      m_pointLastCursor = pointerPoint.RawPosition();
//
//      puserinteractionHost->m_pimpl->queue_message_handler(pusermessage);
//
//   }
//
//
//   void application::OnPointerReleased(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args)
//   {
//
//      if (system() == nullptr)
//      {
//
//         return;
//
//      }
//
//      ::winrt::Windows::UI::Input::PointerPoint pointerPoint = args.CurrentPoint();
//
//      ::g_iMouse = pointerPoint.PointerId();
//
//      auto puserinteractionHost = session()->m_puserprimitiveHost->m_puiThis;
//
//      if (puserinteractionHost == nullptr)
//         return;
//
//      if (puserinteractionHost->m_pimpl == nullptr)
//         return;
//
//      ::pointer<::user::message>pusermessage;
//
//      ::message::mouse * pmouse = ___new  ::message::mouse;
//
//      pusermessage = pmouse;
//
//      pmouse->m_point.x = (int) pointerPoint.RawPosition().X;
//
//      pmouse->m_point.y = (int) pointerPoint.RawPosition().Y;
//
//      if(m_bLeftButton && !args.CurrentPoint().Properties().IsLeftButtonPressed())
//      {
//
//         pmouse->m_atom     = e_message_left_button_up;
//         m_bLeftButton           = false;
//
//      }
//      else if(m_bRightButton && !args.CurrentPoint().Properties().IsRightButtonPressed())
//      {
//
//         pmouse->m_atom     = e_message_right_button_up;
//         m_bRightButton          = false;
//
//      }
//      else if(m_bMiddleButton && !args.CurrentPoint().Properties().IsMiddleButtonPressed())
//      {
//
//         pmouse->m_atom     = e_message_middle_button_up;
//         m_bMiddleButton         = false;
//
//      }
//
//      //pmouse->m_playeredUserPrimitive = session()->m_puserinteractionHost;
//
//      m_pointLastCursor = pointerPoint.RawPosition();
//
//      puserinteractionHost->m_pimpl->queue_message_handler(pusermessage);
//
//   }
//
//
//   //directx_application_source::directx_application_source(::aura::system * paxissystem, const ::string & strId)
//   //{
//
//   //   system()     = paxissystem;
//
//   //   m_strId           = strId;
//
//   //}
//
//
//   ::winrt::Windows::ApplicationModel::Core::IFrameworkView application::CreateView()
//   {
//
//      return *this;
//
//   }
//
//
//   //directx_application_source new_directx_application_source(::aura::system * papexsystem, const ::string & strId)
//   //{
//
//   //   string str = strId;
//
//   //   //str += " client_only";
//
//   //   //str += " full_screen";
//
//   //   return ref ___new directx_application_source(papexsystem, str);
//
//   //}
//
//   
//   ::winrt::Windows::Foundation::Rect application::get_input_content_rect()
//   {
//
//      ::winrt::Windows::Foundation::Rect rectangle;
//      
//      auto pfocusui = m_puserinteraction->get_keyboard_focus();
//
//      auto puserinteraction = pfocusui->m_puiThis;
//
//      if (puserinteraction)
//      {
//
//         ::int_rectangle r = puserinteraction->window_rectangle();
//
//         m_rectangleInputContentRect.X = (float) r.left();
//         m_rectangleInputContentRect.Y = (float)r.top();
//         m_rectangleInputContentRect.Width = (float)r.width();
//         m_rectangleInputContentRect.Height = (float)r.height();
//
//      }
//
//      rectangle = m_rectangleInputContentRect;
//
//      return rectangle;
//
//   }
//
//
//   ::winrt::Windows::Foundation::Rect application::get_input_selection_rect()
//   {
//
//      ::winrt::Windows::Foundation::Rect rectangle = m_rectangleInputSelectionRect;
//
//      return rectangle;
//
//   }
//
//   
//   wide_string application::get_input_text()
//   {
//
//      wide_string wstrText;
//
//      auto pfocusui = m_puserinteraction->get_keyboard_focus();
//
//      auto puserinteraction = pfocusui;
//
//      if (puserinteraction)
//      {
//
//         string strText;
//
//         puserinteraction->get_text(strText);
//
//         wstrText = strText;
//
//      }
//
//      return wstrText;
//
//   }
//
//
//   bool application::set_input_text(const wide_string & wstr)
//   {
//
//      auto pfocusui = m_puserinteraction->get_keyboard_focus();
//
//      auto puserinteraction = pfocusui;
//
//      if (puserinteraction)
//      {
//
//         string strText;
//
//         strText = wstr;
//
//         puserinteraction->set_text(strText, e_source_user);
//
//      }
//
//      //return wstrText;
//      return true;
//
//   }
//
//
//   //void application::get_input_text(const wide_string & wstr)
//   //{
//
//
//   //}
//
//
//   ::winrt::Windows::Foundation::Rect application::window_rectangle()
//   {
//
//      ::winrt::Windows::Foundation::Rect rectangle = m_rectangleLastWindowRect;
//
//      /*      rectangle.X = 0;
//            rectangle.Y = 0;
//            rectangle.Width = 600;
//            rectangle.Height = 480;
//
//            if(m_window == nullptr)
//               return rectangle;
//
//            ::wait(m_window->Dispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal, ref ___new ::winrt::Windows::UI::Core::DispatchedHandler ([=, &rectangle]()
//            {
//               try
//               {
//                  rectangle = m_window->Bounds;
//               }
//               catch(...)
//               {
//               }
//            })));*/
//
//      return rectangle;
//
//   }
//
//   ::winrt::Windows::Foundation::Point application::get_cursor_position()
//   {
//
//      single_lock synchronouslock(&m_mutex, true);
//
//      ::winrt::Windows::Foundation::Point p = m_pointLastCursor;
//
//      /*      if(m_window == nullptr)
//               return p;
//
//            if(g_iMouse < 0)
//               return p;
//
//            ::wait(m_window->Dispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal, ref ___new ::winrt::Windows::UI::Core::DispatchedHandler ([=, &p]()
//            {
//               try
//               {
//
//                  ::winrt::Windows::Foundation::Collections::IVectorView < ::winrt::Windows::Devices::Input::PointerDevice > deva = ::winrt::Windows::Devices::Input::PointerDevice::GetPointerDevices();
//
//                  for(unsigned int u = 0; u < deva->Size; u++)
//                  {
//
//                     ::winrt::Windows::Devices::Input::PointerDevice dev = deva->GetAt(u);
//
//                     if(dev->PointerDeviceType == ::winrt::Windows::Devices::Input::PointerDeviceType::Mouse)
//                     {
//
//                        ::winrt::Windows::UI::Input::PointerPoint pointerPoint = ::winrt::Windows::UI::Input::PointerPoint::GetCurrentPoint(g_iMouse);
//
//                        p = pointerPoint->RawPosition;
//
//                        break;
//
//                     }
//
//                  }
//
//               }
//               catch(...)
//               {
//               }
//            })), 5); // wait for up to 5 ::durations
//
//            m_pointLastCursor = p;*/
//
//      return p;
//
//   }
//
//
//} // namespace windowing_universal_windows
//
//
//
//
