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

      //rectangle_i32_array                                         m_rectangleaMonitor;
      //rectangle_i32_array                                             m_rectangleaWork;

      rectangle_i32_array                                               m_rectangleaMonitor;
      rectangle_i32_array                                               m_rectangleaWkspace;
#endif
      //#pragma message("at macos??")
      //raw_array < MONITORINFO >                          m_monitorinfoa;
      //comparable_array < HMONITOR >                      m_hmonitora;
      //raw_array < MONITORINFO >                          m_monitorinfoaDesk;





      display();
      ~display() override;


      void initialize_display(::windowing::windowing * pwindowing) override;


      virtual void update_dpi();

      void enum_display_monitors() override;

      ::collection::index get_main_monitor(::rectangle_i32 & rectangle) override;

      ::collection::count get_monitor_count() override;
      //virtual bool  get_monitor_rect(::collection::index iMonitor, ::rectangle_i32 * prectangle) override;

      ::collection::count get_desk_monitor_count() override;
      //virtual bool  get_desk_monitor_rect(::collection::index iMonitor, ::rectangle_i32 * prectangle) override;


      ::collection::index get_main_workspace(::rectangle_i32 & rectangle) override;

      ::collection::count get_workspace_count() override;
      //virtual bool  get_wkspace_rect(::collection::index iWkspace, ::rectangle_i32 * prectangle) override;

      ::collection::count get_desk_workspace_count() override;
      //virtual bool  get_desk_wkspace_rect(::collection::index iWkspace, ::rectangle_i32 * prectangle) override;

      //virtual ::collection::index get_ui_wkspace(::user::interaction * pinteraction) override;


      static BOOL CALLBACK monitor_enum_proc(HMONITOR hmonitor, HDC hdcMonitor, LPRECT prcMonitor, LPARAM dwData);


      virtual void monitor_enum(HMONITOR hmonitor, HDC hdcMonitor, LPRECT prcMonitor);


      virtual bool set_main_monitor(::collection::index iMonitor);


      //virtual bool wkspace_to_monitor(::rectangle_i32 * prectangle, ::collection::index iMonitor, ::collection::index iWkspace) override;

      //virtual bool monitor_to_wkspace(::rectangle_i32 * prectangle, ::collection::index iWkspace, ::collection::index iMonitor) override;

      //virtual bool wkspace_to_monitor(::rectangle_i32 * prectangle) override;

      //virtual bool monitor_to_wkspace(::rectangle_i32 * prectangle) override;


      virtual void _get_monitor(rectangle_i32_array & rectaMonitor, rectangle_i32_array& rectaIntersect, const rectangle_i32 & rectangleParam);


      virtual ::collection::index _get_best_zoneing(::e_display * pedisplay, ::rectangle_i32 * prectangle, const ::rectangle_i32 & rectangle, bool bPreserveSize = false);

      ::collection::index get_best_monitor(::rectangle_i32 * prectangle, const ::rectangle_i32 & rectangle, ::e_activation eactivation = e_activation_default, ::user::interaction* puserinteractionGetCursorPosition = nullptr) override;

      ::collection::index get_best_workspace(::rectangle_i32 * prectangle, const ::rectangle_i32 & rectangle, ::e_activation eactivation = e_activation_default, ::user::interaction * puserinteractionGetCursorPosition = nullptr) override;

      ::collection::index get_good_iconify(::rectangle_i32 * prectangle, const ::rectangle_i32 & rectangle) override;
      
      //virtual ::collection::index get_window_restore_1(::rectangle_i32 * prectangle, const ::rectangle_i32 & rectangle, ::user::interaction * pinteraction, edisplay edisplayRestore);

      //virtual ::collection::index get_window_restore_2(::rectangle_i32 * prectangle, const ::rectangle_i32 & rectangle, ::user::interaction * pinteraction, edisplay edisplayRestore);

      //virtual ::collection::index get_good_move(::rectangle_i32 * prectangle, const ::rectangle_i32 & rectangle, ::user::interaction * pinteraction);


      bool impl_set_wallpaper(::collection::index iScreen, string strLocalImagePath) override;
      string impl_get_wallpaper(::collection::index iScreen) override;


      ::point_i32 _get_mouse_cursor_position() override;


   };


} // namespace windowing_universal_windows



