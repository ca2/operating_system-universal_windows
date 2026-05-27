// created by Camilo <3ThomasBorregaardSoerensen_!!
// recreated by Camilo 2021-02-02 16:49
#pragma once


#include "aura/windowing/display.h"


namespace windowing_universal_windows
{

   // X11 contribution : a display may contain more than one monitor

   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS display :
      virtual public ::windowing::display
   {
   public:

      int m_iMouseDevice;

#ifdef WINDOWS_DESKTOP


#else

      //::i32_rectangle_array                                         m_rectangleaMonitor;
      //::i32_rectangle_array                                             m_rectangleaWork;

      ::i32_rectangle_array                                               m_rectangleaMonitor;
      ::i32_rectangle_array                                               m_rectangleaWkspace;
#endif
      //#pragma message("at macos??")
      //raw_array < MONITORINFO >                          m_monitorinfoa;
      //comparable_array < HMONITOR >                      m_hmonitora;
      //raw_array < MONITORINFO >                          m_monitorinfoaDesk;





      display();
      ~display() override;


      //void initialize_display(::windowing::windowing * pwindowing) override;


      void open_display() override;


      virtual void update_dpi();

      void enum_display_monitors() override;

      ::collection::index get_main_monitor(::i32_rectangle & rectangle) override;

      ::collection::count get_monitor_count() override;
      //virtual bool  get_monitor_rect(::collection::index iMonitor, ::i32_rectangle * prectangle) override;

      ::collection::count get_desk_monitor_count() override;
      //virtual bool  get_desk_monitor_rect(::collection::index iMonitor, ::i32_rectangle * prectangle) override;


      ::collection::index get_main_workspace(::i32_rectangle & rectangle) override;

      //::collection::count get_workspace_count() override;
      //virtual bool  get_wkspace_rect(::collection::index iWkspace, ::i32_rectangle * prectangle) override;

      //::collection::count get_desk_workspace_count() override;
      //virtual bool  get_desk_wkspace_rect(::collection::index iWkspace, ::i32_rectangle * prectangle) override;

      //virtual ::collection::index get_ui_wkspace(::user::interaction * pinteraction) override;


      static BOOL CALLBACK monitor_enum_proc(HMONITOR hmonitor, HDC hdcMonitor, LPRECT prcMonitor, LPARAM dwData);


      virtual void monitor_enum(HMONITOR hmonitor, HDC hdcMonitor, LPRECT prcMonitor);


      virtual bool set_main_monitor(::collection::index iMonitor);


      //virtual bool wkspace_to_monitor(::i32_rectangle * prectangle, ::collection::index iMonitor, ::collection::index iWkspace) override;

      //virtual bool monitor_to_wkspace(::i32_rectangle * prectangle, ::collection::index iWkspace, ::collection::index iMonitor) override;

      //virtual bool wkspace_to_monitor(::i32_rectangle * prectangle) override;

      //virtual bool monitor_to_wkspace(::i32_rectangle * prectangle) override;


      virtual void _get_monitor(::i32_rectangle_array & rectaMonitor, ::i32_rectangle_array& rectaIntersect, const i32_rectangle & rectangleParam);


      virtual ::collection::index _get_best_zoneing(::e_display * pedisplay, ::i32_rectangle * prectangle, const ::i32_rectangle & rectangle, bool bPreserveSize = false);

      ::collection::index get_best_monitor(::i32_rectangle * prectangle, const ::i32_rectangle & rectangle, const ::user::activation & useractivation = {}, ::user::interaction* puserinteractionGetCursorPosition = nullptr) override;

      ::collection::index get_best_workspace(::i32_rectangle * prectangle, const ::i32_rectangle & rectangle, const ::user::activation & useractivation = {}, ::user::interaction * puserinteractionGetCursorPosition = nullptr) override;

      ::collection::index get_good_iconify(::i32_rectangle * prectangle, const ::i32_rectangle & rectangle) override;
      
      //virtual ::collection::index get_window_restore_1(::i32_rectangle * prectangle, const ::i32_rectangle & rectangle, ::user::interaction * pinteraction, edisplay edisplayRestore);

      //virtual ::collection::index get_window_restore_2(::i32_rectangle * prectangle, const ::i32_rectangle & rectangle, ::user::interaction * pinteraction, edisplay edisplayRestore);

      //virtual ::collection::index get_good_move(::i32_rectangle * prectangle, const ::i32_rectangle & rectangle, ::user::interaction * pinteraction);


      void impl_set_wallpaper(::collection::index iScreen, const ::scoped_string & scopedstrLocalImagePath) override;
      string impl_get_wallpaper(::collection::index iScreen) override;


      ::int_point _get_mouse_cursor_position() override;


   };


} // namespace windowing_universal_windows



