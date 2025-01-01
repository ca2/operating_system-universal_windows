// Created by camilo on 2021-01-21 05:05 PM <3ThomasBorregaardSorensen
#pragma once


#include "acme/windowing/sandbox/window.h"
//#include "acme/windowing/window_base.h"
//#include "acme/operating_system/windows/window.h"
#undef USUAL_OPERATING_SYSTEM_SUPPRESSIONS
#include "acme/_operating_system.h"
#include <winrt/Windows.UI.Text.Core.h>
#include <winrt/Windows.Graphics.Display.h>
#include <winrt/Windows.ApplicationModel.Core.h>



namespace universal_windows
{


   namespace acme
   {


      namespace windowing
      {


         class CLASS_DECL_ACME_WINDOWING_UNIVERSAL_WINDOWS window :
            virtual public ::acme::sandbox_windowing::window
         {
         public:


            //bool m_bNcActive;
            //CreatableFromBase(window, ::micro::window_implementation);
            //bool m_bSizeMoveMode;
            //HWND m_hwnd;
            //HMENU m_hmenuSystem;
            //bool m_bDestroy;
      //      HFONT m_hfont;
      //      color32_t m_crText;
      //      color32_t m_crFocus;
      //      color32_t m_crWindow;
      //      string m_strTitle;
      //      bool m_bNcActive;

      //      int_rectangle m_rectangle;
      //      int_rectangle m_rectangleX;
      //
      //      pointer_array < ::micro::child > m_childa;
      //      ::atom m_atomLeftButtonDown;
      //      ::atom m_atomLeftButtonUp;
      //      //::atom                             m_atomResult;
      //      ::pointer<::micro::child>m_pchildFocus;
            ::winrt::event_token                                     m_tokenActivated;
            ::winrt::event_token                                     m_tokenClosed;
            ::winrt::event_token                                     m_tokenPointerPressed;
            ::winrt::event_token                                     m_tokenKeyDown;

            ::winrt::Windows::Foundation::Point                      m_pointLastCursor;

            ::winrt::Windows::ApplicationModel::Core::CoreApplicationView m_coreapplicationview = nullptr;
            ::winrt::Windows::UI::Core::CoreWindow  m_windowscorewindow = nullptr;
            ::winrt::Windows::UI::Core::CoreWindowResizeManager      m_resizemanager = nullptr;


            ::task_pointer       m_ptask;

            ::pointer < ::nano::graphics::device > m_pnanodevice;


            ::winrt::Windows::Foundation::Rect                       m_rectangleLastWindowRect;


            int   m_iMouse;

            bool                                                     m_bLeftButton;

            bool                                                     m_bMiddleButton;

            bool                                                     m_bRightButton;

            bool                                                     m_bFontopusShift;



            window();

            ~window() override;

            void create_window() override;

            void _create_window() override;

            void destroy_window() override;

            void show_window() override;

            void hide_window() override;

            virtual void _draw(HDC hdc);

            ::oswindow oswindow() override;

            void Initialize(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & coreapplicationview);
            void SetWindow(::winrt::Windows::UI::Core::CoreWindow const & window);

            void UpdateFocusUI();
            //void on_draw(::nano::graphics::device * pnanodevice) override;

            //void on_char(int iChar) override;

            //bool is_active() override;

            //virtual void draw_children(::nano::graphics::device * pnanodevice);

            //void delete_drawing_objects() override;

            //bool get_dark_mode() override;

            //void create_drawing_objects() override;

            //void update_drawing_objects() override;

            //::micro::child * on_hit_test(const ::int_point & point, ::user::e_zorder ezorder) override;

            //void add_child(::micro::child* pchild) override;

            //::payload get_result() override;

            //void on_mouse_move(::user::mouse* pmouse) override;

            //void on_left_button_down(::user::mouse* pmouse) override;

            //void on_left_button_up(::user::mouse* pmouse) override;

            //void on_click(const ::payload& payload, ::user::mouse* pmouse) override;

            //void on_right_button_down(::user::mouse* pmouse) override;

            //void on_right_button_up(::user::mouse* pmouse) override;

            //void on_right_click(const ::payload& payload, ::user::mouse* pmouse) override;

            //bool on_window_procedure(LRESULT & lresult, UINT message, WPARAM wparam, LPARAM lparam) override;

            //virtual LRESULT window_procedure(unsigned int message, wparam wparam, lparam lparam);

            void set_position(const ::int_point& point) override;

            //void _destroy_window();

            void destroy() override;

            void redraw() override;


            bool _is_window() override;

            
            ::int_point client_to_screen(const ::int_point & point);


            //::int_point try_absolute_mouse_position(const ::int_point& point) override;



            //void get_client_rectangle(::int_rectangle& rectangle) override;

            ::int_rectangle get_window_rectangle() override;

            void set_capture() override;

            bool has_capture() override;

            void release_capture() override;

            void set_cursor(enum_cursor ecursor) override;

            static bool _is_light_theme();


            //::int_size get_main_screen_size() override;


            void _user_post(const ::procedure& procedure) override;


            virtual void implementation_message_loop_step();

            void defer_show_system_menu(::user::mouse * pmouse) override;


            /// ::user::primitive_impl


            using ::acme::windowing::window::set_mouse_capture;

            void set_mouse_capture() override;

            bool has_mouse_capture() override;


            virtual void InstallPrototypeHappeningHandling();


            virtual void on_window_size_changed(::winrt::Windows::UI::Core::CoreWindow  sender, const ::int_size & size);

            void CoreWindow_PointerPressed(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::PointerEventArgs args);

            // Revoke with event_token
            void CoreWindow_WindowActivated(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::WindowActivatedEventArgs args);
            void CoreWindow_CoreWindowClosed(::winrt::Windows::UI::Core::CoreWindow  sender, ::winrt::Windows::UI::Core::CoreWindowEventArgs args);
            void CoreWindow_KeyDown(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::KeyEventArgs args);

            // Event Handlers
            void OnWindowSizeChanged(
               _In_::winrt::Windows::UI::Core::CoreWindow sender,
               _In_::winrt::Windows::UI::Core::WindowSizeChangedEventArgs args
            );

            void DpiChanged(::winrt::Windows::Graphics::Display::DisplayInformation  sender, ::winrt::Windows::Foundation::IInspectable);

            virtual void on_dpi_changed(::winrt::Windows::Graphics::Display::DisplayInformation  sender, ::winrt::Windows::Foundation::IInspectable);

            void DisplayContentsInvalidated(::winrt::Windows::Graphics::Display::DisplayInformation  sender, ::winrt::Windows::Foundation::IInspectable);

            virtual void on_display_contents_invalidated(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable);

            void OnActivated(
               ::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView,
               ::winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs const & args
            );

            void OnSuspending(
               ::winrt::Windows::Foundation::IInspectable const & sender,
               ::winrt::Windows::ApplicationModel::SuspendingEventArgs const & args
            );

            void OnResuming(
               ::winrt::Windows::Foundation::IInspectable const & sender,
               ::winrt::Windows::Foundation::IInspectable const & args
            );

            void OnWindowClosed(::winrt::Windows::UI::Core::CoreWindow  sender, ::winrt::Windows::UI::Core::CoreWindowEventArgs  args);
            void OnWindowVisibilityChanged(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs args);

            void OnPointerMoved(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);
            void OnPointerPressed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);
            void OnPointerReleased(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);
            
            void OnCharacterReceived(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs args);
            void OnKeyDown(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args);
            void OnKeyUp(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args);


            virtual void on_window_visibility_changed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs args);

            virtual void on_pointer_moved(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);
            virtual void on_pointer_pressed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);
            virtual void on_pointer_released(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);

            virtual void on_character_received(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs args);
            virtual void on_key_down(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args);
            virtual void on_key_up(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args);


         };


         //CLASS_DECL_ACME void process_messages(bool bWait = false);


      } // namespace windowing

      
   } // namespace acme


} // namespace universal_windows



