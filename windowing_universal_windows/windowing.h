// Created by camilo on 2021-01-30 <3ThomasBS_!!
#pragma once


#include "aura/windowing/sandbox/windowing.h"
#include "application.h"
#undef ___new
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.ApplicationModel.Core.h>


namespace windowing_universal_windows
{


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS windowing :
      virtual public ::sandbox_windowing::windowing
      
   {
   public:


      ::pointer < ::windowing_universal_windows::window >    m_pwindowMain;
      // From node
      ::pointer<::aura_universal_windows::interaction_impl>m_pimplMain;

      bool                          m_bAppInit;

      ::winrt::Windows::ApplicationModel::Core::IFrameworkViewSource    m_frameworkviewsource = nullptr;
      ::winrt::Windows::UI::ViewManagement::ApplicationView             m_applicationview = nullptr;

      //winrt::agile_ref< application>    m_application;

      ::windowing_universal_windows::application * m_papplication;
      //auto uisettings = ::winrt::Windows::UI::ViewManagement::UISettings();

      ::winrt::Windows::UI::ViewManagement::UISettings m_uisettings;
      // END From node


      //i64_map < ::user::enum_key >     m_mapKey;


      critical_section                 m_criticalsection;
      //window_map                       m_windowmap;
      ::pointer<class display>         m_pdisplay;
      //::pointer<class window>          m_pwindowCapture;
      //::pointer<class window>          m_pwindowFocus;

//#ifdef WINDOWS_DESKTOP

      //#pragma message("at macos??")
      //::pointer<system_interaction>   system()interaction;

//#endif


      windowing();
      ~windowing() override;


      void initialize_windowing(::user::user * puser) override;

      void defer_term_ui() override;

      void finalize_windowing() override;

      void destroy() override;

      //::e_status destroy() override;

      //void get_cursor_position(::int_point* ppoint) override;

      //virtual bool defer_create_system_window();
      //virtual ::pointer<::user::interaction>create_system_window();
      //::extended::transport < system_interaction > create_system_window();

      // From Node
      void app_init();
      void OnUISettingsColorValuesChange(::winrt::Windows::UI::ViewManagement::UISettings, ::winrt::Windows::Foundation::IInspectable);
      virtual void fetch_user_color();
      // END From Node


      //inline system_interaction * system_window() { return system()interaction; }

      //virtual HICON _load_icon(string_array& straMatter, string strIcon, int cx, int cy);

      //virtual hwnd_array _get_hwnda(const ::user::primitive_pointer_array& primitivepointera);

      ::windowing::window * window(oswindow oswindow) override;

      //virtual ::windowing_universal_windows::window * _window(HWND hwnd);

      ::windowing::display * display() override;

      //::pointer<::windowing::monitor>get_main_monitor();


      virtual ::pointer<::user::message>get_user_message(MESSAGE * pmsg);


      //virtual void enum_draw2d_fonts(::write_text::font_enumeration_item_array & itema) override;
      
      
      ::windowing::window * get_desktop_window() override;


      ::windowing::window * get_active_window(::thread * pthread) override;


      virtual void __synthesizes_creates_styles(::user::interaction * pinteraction, unsigned int & nExStyle, unsigned int & nStyle);

      
      virtual zorder zorder_from_hwnd(HWND hwnd);
      virtual HWND zorder_to_hwnd(const zorder & zorder);

      
      //::windowing::window * get_keyboard_focus(::thread * pthread) override;


      //::windowing::window * get_mouse_capture(::thread * pthread) override;

      
      // oswindow _get_mouse_capture(itask_t itask);


      //void release_mouse_capture() override;


      

      void erase_window(::windowing::window * pwindow) override;
    

      using windowing::windowing::get_cursor;


      virtual ::windowing::cursor * get_cursor();
      virtual ::windowing::cursor * get_default_cursor();


      //virtual enum_dialog_result message_box(const ::string & pszMessage, const ::string & pszTitle, const ::e_message_box & emessagebox);


      //virtual void get_cursor_pos(::int_point * ppoint);

      //void set_cursor_position(const ::int_point & point) override;



      virtual int_bool point_is_window_origin(::int_point ptHitTest, oswindow oswindowExclude, int iMargin);

      //virtual void top_windows_by_z_order(hwnd_array & a);


      bool is_window(oswindow oswindow) override;

      bool _is_window(HWND hwnd);


      //virtual void get_app_wnda(hwnd_array & wnda);

      //::pointer<::windowing::window>window_from_point(::aura::application * papp, const ::int_point & point);

      
      //void windowing_post(const ::procedure & procedure) override;


      //static BOOL CALLBACK GetAppsEnumWindowsProc(HWND hwnd, LPARAM lParam);


      //void set(::message::key * pkey, oswindow oswindow, ::windowing::window * pwindow, const ::atom & atom, wparam wparam, ::lparam lparam) override;
      //void set(::message::mouse * pmouse, oswindow oswindow, ::windowing::window * pwindow, const ::atom & atom, wparam wparam, ::lparam lparam) override;


      void initialize_keyboard(::windowing::keyboard * pkeyboard) override;

      void lock_set_foreground_window(bool bLock) override;

      //virtual wstring _windows_register_window_class(unsigned int nClassStyle, hcursor hCursor = 0, HBRUSH hbrBackground = 0, hicon hIcon = 0);
      //CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS wstring windows_register_window_class(::particle * pparticle, unsigned int nClassStyle, hcursor hCursor = 0, HBRUSH hbrBackground = 0, hicon hIcon = 0);
      //virtual bool _windows_register_class(WNDCLASSEXW* puserinteractionclass);
      //
      //virtual wstring _windows_calc_icon_window_class(::user::interaction* pinteraction, unsigned int dwDefaultStyle, const ::string & pszMatter) override;
      //virtual wstring _windows_get_user_interaction_window_class(::user::interaction* pinteraction) override;
      //virtual bool _windows_register_with_icon(WNDCLASSEXW* puserinteractionclass, const unichar* pszClassName, unsigned int nIDIcon);

      //virtual void _window_create_caret(HWND hwnd, HBITMAP hbitmap);
      //virtual void _window_create_solid_caret(HWND hwnd, int nWidth, int nHeight);
      //virtual void _window_create_gray_caret(HWND hwnd, int nWidth, int nHeight);


      //template < typename PRED >
      //bool _top_level_contains_predicate(PRED pred);


      //template < typename PREDICATE >
      //bool _top_level_contains_bool_member(PREDICATE predicate);


      //virtual bool _visible_top_level_contains_all_names(string_array& stra);
      //virtual bool _visible_top_level_contains_name(string str);
      //virtual bool _top_level_contains_name(string str);
      //virtual string _get_window_text_timeout(oswindow oswindow, const class time & time = 1_s);


   };


} // namespace windowing_universal_windows



