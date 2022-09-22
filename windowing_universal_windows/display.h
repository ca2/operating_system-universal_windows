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

      ::index get_main_monitor(RECTANGLE_I32 * prectangle = nullptr) override;

      ::count get_monitor_count() override;
      //virtual bool  get_monitor_rect(index iMonitor, RECTANGLE_I32 * prectangle) override;

      ::count get_desk_monitor_count() override;
      //virtual bool  get_desk_monitor_rect(index iMonitor, RECTANGLE_I32 * prectangle) override;


      index get_main_workspace(RECTANGLE_I32 * prectangle = nullptr) override;

      ::count get_workspace_count() override;
      //virtual bool  get_wkspace_rect(index iWkspace, RECTANGLE_I32 * prectangle) override;

      ::count get_desk_workspace_count() override;
      //virtual bool  get_desk_wkspace_rect(index iWkspace, RECTANGLE_I32 * prectangle) override;

      //virtual index get_ui_wkspace(::user::interaction * pinteraction) override;


      static BOOL CALLBACK monitor_enum_proc(HMONITOR hmonitor, HDC hdcMonitor, LPRECT prcMonitor, LPARAM dwData);


      virtual void monitor_enum(HMONITOR hmonitor, HDC hdcMonitor, LPRECT prcMonitor);


      virtual bool set_main_monitor(index iMonitor);


      //virtual bool wkspace_to_monitor(RECTANGLE_I32 * prectangle, index iMonitor, index iWkspace) override;

      //virtual bool monitor_to_wkspace(RECTANGLE_I32 * prectangle, index iWkspace, index iMonitor) override;

      //virtual bool wkspace_to_monitor(RECTANGLE_I32 * prectangle) override;

      //virtual bool monitor_to_wkspace(RECTANGLE_I32 * prectangle) override;


      virtual void _get_monitor(rectangle_i32_array & rectaMonitor, rectangle_i32_array& rectaIntersect, const rectangle_i32 & rectangleParam);


      virtual index _get_best_zoneing(edisplay * pedisplay, ::rectangle_i32 * prectangle, const ::rectangle_i32 & rectangle, bool bPreserveSize = false);

      index get_best_monitor(RECTANGLE_I32 * prectangle, const ::rectangle_i32 & rectangle, ::e_activation eactivation = e_activation_default, ::windowing::window* pwindowGetCursorPosition = nullptr) override;

      index get_best_workspace(::rectangle_i32 * prectangle, const ::rectangle_i32 & rectangle, ::e_activation eactivation = e_activation_default, ::windowing::window* pwindowGetCursorPosition = nullptr) override;

      index get_good_iconify(RECTANGLE_I32 * prectangle, const ::rectangle_i32 & rectangle) override;
      
      //virtual index get_window_restore_1(RECTANGLE_I32 * prectangle, const ::rectangle_i32 & rectangle, ::user::interaction * pinteraction, edisplay edisplayRestore);

      //virtual index get_window_restore_2(RECTANGLE_I32 * prectangle, const ::rectangle_i32 & rectangle, ::user::interaction * pinteraction, edisplay edisplayRestore);

      //virtual index get_good_move(RECTANGLE_I32 * prectangle, const ::rectangle_i32 & rectangle, ::user::interaction * pinteraction);


      bool impl_set_wallpaper(index iScreen, string strLocalImagePath) override;
      string impl_get_wallpaper(index iScreen) override;


   };


} // namespace windowing_universal_windows



