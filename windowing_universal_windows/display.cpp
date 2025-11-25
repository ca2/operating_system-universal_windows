// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen  - Honoring Thomas Borregaard Soerensen MY ONLY LORD
// recreated by Camilo 2021-02-02 20:55
#include "framework.h"
#include "display.h"
#include "aura/graphics/draw2d/graphics.h"
#include "aura/platform/system.h"
//#include "aura/user/user/interaction_impl.h"
#include "aura/windowing/monitor.h"
#include "aura/windowing/window.h"
#include "aura/windowing/windowing.h"
#include "acme/_operating_system.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include "acme_universal_windows/_winrt_system.h"
#include <winrt/windows.foundation.collections.h>
#include <winrt/windows.devices.input.h>
#include <winrt/windows.ui.input.h>


namespace windowing_universal_windows
{


   display::display()
   {

      m_iMouseDevice = -1;

   }


   display::~display()
   {


   }


   void display::enum_display_monitors()
   {

      //#ifdef WINDOWS_DESKTOP
      //
      //      m_monitorinfoa.erase_all();
      //
      //      ::EnumDisplayMonitors(nullptr, nullptr, &display::monitor_enum_proc, (LPARAM)this);
      //
      //      synchronous_lock synchronouslock(synchronization());
      //
      //      m_monitora.erase_all();
      //
      //      for (::collection::index iMonitor = 0; iMonitor < m_monitorinfoa.get_count(); iMonitor++)
      //      {
      //
      //         auto pmonitor = øallocate< monitor >(m_hmonitora[iMonitor]);
      //
      //         pmonitor->m_iIndex = iMonitor;
      //
      //         m_monitora.add(pmonitor);
      //
      //         __copy(pmonitor->m_rectangle, m_monitorinfoa[iMonitor].rcMonitor);
      //
      //         __copy(pmonitor->m_rectangleWorkspace, m_monitorinfoa[iMonitor].rcWork);
      //
      //      }
      //
      //#elif defined(LINUX)
      //
      //      ::enum_display_monitors(this);
      //
      //#endif

   }



   ::collection::index display::get_main_monitor(::int_rectangle & rectangle)
   {

      //index iMainMonitor = 0;

      //HMONITOR hmonitorPrimary = get_primary_monitor_handle();

      //for (::collection::index iMonitor = 0; iMonitor < get_monitor_count(); iMonitor++)
      //{

      //   if (m_hmonitora[iMonitor] == hmonitorPrimary)
      //   {

      //      iMainMonitor = iMonitor;

      //      break;

      //   }

      //}

      //if (prectangle != nullptr)
      //{

      //   auto pmonitor = get_monitor(iMainMonitor);

      //   if (::is_null(pmonitor))
      //   {

      //      return -1;

      //   }

      //   if (!pmonitor->get_monitor_rectangle(prectangle))
      //   {

      //      return -1;

      //   }

      //}

//      return iMainMonitor;

      return -1;

   }


   ::collection::count display::get_monitor_count()
   {

      //#ifdef WINDOWS_DESKTOP
      //
      //      return m_monitorinfoa.get_count();
      //
      //#elif defined(MACOS)
      //
      //      return GetScreenCount();
      //
      //#elif defined(LINUX)
      //
      //      synchronous_lock synchronouslock(synchronization());
      //
      //      return m_rectangleaMonitor.get_count();
      //
      //#else

      return 1;
      //
      //#endif

   }


   //   bool display::get_monitor_rectangle(::collection::index iMonitor, ::int_rectangle * prectangle)
   //   {
   //
   //#ifdef UNIVERSAL_WINDOWS
   //
   //      return false;
   //
   //      //prectangle->left = 0;
   //
   //      //prectangle->top = 0;
   //
   //      //auto puserinteraction = __user_interaction(m_puserinteractionHost);
   //
   //      //prectangle->right = puserinteraction->layout().sketch().width();
   //
   //      //prectangle->bottom = puserinteraction->layout().sketch().height();
   //
   //      //return true;
   //
   //#elif MOBILE_PLATFORM
   //
   //      GetMainScreenRect(prectangle);
   //
   //      return true;
   //
   //#elif defined(WINDOWS_DESKTOP)
   //
   //      if (iMonitor < 0 || iMonitor >= get_monitor_count())
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      __copy(prectangle, m_monitorinfoa[iMonitor].rcMonitor);
   //
   //
   //#elif defined(UNIVERSAL_WINDOWS)
   //
   //
   //      return false;
   //
   //
   //#elif defined(LINUX)
   //
   //      synchronous_lock synchronouslock(synchronization());
   //
   //      if (iMonitor < 0 || iMonitor >= get_monitor_count())
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      *prectangle = m_rectangleaMonitor[iMonitor];
   //
   //
   //#elif defined(__APPLE__)
   //
   //      if (iMonitor < 0 || iMonitor >= get_monitor_count())
   //      {
   //
   //         return false;
   //
   //      }
   //
   //      GetScreenRect(prectangle, (int)iMonitor);
   //
   //
   //#else
   //
   //      prectangle->left = 0;
   //
   //      prectangle->top = 0;
   //
   //      prectangle->right = operating_system_driver::get().m_iScreenWidth;
   //
   //      prectangle->bottom = operating_system_driver::get().m_iScreenHeight;
   //
   //
   //#endif
   //
   //      return true;
   //
   //   }
   //

   ::collection::count display::get_desk_monitor_count()
   {

      return get_monitor_count();

   }


   //bool display::get_desk_monitor_rect(::collection::index iMonitor, ::int_rectangle * prectangle)

   //{

   //   return get_monitor_rect(iMonitor, prectangle);


   //}


   ::collection::index display::get_main_workspace(::int_rectangle & rectangle)

   {

      //index iMainWkspace = 0;

      //HMONITOR hwkspacePrimary = get_primary_monitor_handle();

      //for (::collection::index iWkspace = 0; iWkspace < get_workspace_count(); iWkspace++)
      //{

      //   if (m_hmonitora[iWkspace] == hwkspacePrimary)
      //   {

      //      iMainWkspace = iWkspace;

      //      break;

      //   }

      //}


      //if (prectangle != nullptr)
      //{

      //   auto pmonitor = get_monitor(iMainWkspace);

      //   if (::is_null(prectangle))
      //   {

      //      return -1;

      //   }

      //   pmonitor->get_workspace_rectangle(prectangle);

      //}

      //return iMainWkspace;

      return 0;

   }


   //::collection::count display::get_workspace_count()
   //{

   //   //#ifdef WINDOWS_DESKTOP
   //   //
   //   //      return m_monitorinfoa.get_count();
   //   //
   //   //#else
   //   //
   //   //      return get_monitor_count();
   //   //
   //   //#endif
   //   return 1;

   //}


   ////   bool display::get_wkspace_rect(::collection::index iWkspace, ::int_rectangle * prectangle)
   ////   {
   ////
   ////#ifdef WINDOWS_DESKTOP
   ////
   ////      if (iWkspace < 0 || iWkspace >= get_wkspace_count())
   ////         return false;
   ////
   ////      __copy(prectangle, m_monitorinfoa[iWkspace].rcWork);
   ////
   ////
   ////#elif defined(UNIVERSAL_WINDOWS)
   ////
   ////      return get_monitor_rect(iWkspace, prectangle);
   ////
   ////
   ////      //#elif defined(LINUX)
   ////      //
   ////      //return false;
   ////      //
   ////#elif defined(__APPLE__)
   ////
   ////      if (iWkspace < 0 || iWkspace >= get_wkspace_count())
   ////      {
   ////
   ////         return false;
   ////
   ////      }
   ////
   ////      GetWkspaceRect(prectangle, (int)iWkspace);
   ////
   ////
   ////      //      prectangle->top += ::mac::get_system_main_menu_bar_height();
   ////
   ////      //    prectangle->bottom -= ::mac::get_system_dock_height();
   ////
   ////#elif defined(LINUX)
   ////
   ////      synchronous_lock synchronouslock(synchronization());
   ////
   ////      if (iWkspace < 0 || iWkspace >= get_wkspace_count())
   ////      {
   ////
   ////         return false;
   ////
   ////      }
   ////
   ////      *prectangle = m_rectangleaWkspace[iWkspace];
   ////
   ////
   ////      return true;
   ////
   ////#else
   ////
   ////      //throw ::exception(todo);
   ////
   ////      //::window_rectangle(::get_desktop_window(),prectangle);
   ////
   ////
   ////      get_monitor_rect(iWkspace, prectangle);
   ////
   ////
   ////#endif
   ////
   ////      return true;
   ////
   ////   }


   //::collection::count display::get_desk_workspace_count()
   //{

   //   return get_workspace_count();

   //}


   //bool display::get_desk_wkspace_rect(::collection::index iWkspace, ::int_rectangle * prectangle)

   //{

   //   return get_wkspace_rect(iWkspace, prectangle);


   //}


   bool display::set_main_monitor(::collection::index iMonitor)
   {

      if (iMonitor == -1)
      {

         m_iMainMonitor = -1;

         return true;

      }
      else if (iMonitor < 0 || iMonitor >= get_monitor_count())
      {

         return false;

      }
      else
      {

         m_iMainMonitor = iMonitor;

         return true;

      }

   }


   //bool display::wkspace_to_monitor(::int_rectangle * prectangle, ::collection::index iMonitor, ::collection::index iWkspace)
   //{

   //   ::int_rectangle rectangle(*prectangle);

   //   ::int_rectangle rectangleWkspace;

   //   if (!get_wkspace_rect(iWkspace, rectangleWkspace))
   //   {

   //      return false;

   //   }

   //   rectangle -= rectangleWkspace.top_left();

   //   ::int_rectangle rectangleMonitor;

   //   if (!get_monitor_rect(iMonitor, rectangleMonitor))
   //   {

   //      return false;

   //   }

   //   rectangle += rectangleMonitor.top_left();

   //   *prectangle = rectangle;

   //   return true;

   //}


   //bool display::wkspace_to_monitor(::int_rectangle * prectangle)
   //{

   //   index iWkspace = get_best_wkspace(nullptr, int_rectangle(prectangle));

   //   return wkspace_to_monitor(prectangle, iWkspace, iWkspace);

   //}


   //bool display::monitor_to_wkspace(::int_rectangle * prectangle)
   //{

   //   index iMonitor = get_best_monitor(nullptr, int_rectangle(prectangle));

   //   return monitor_to_wkspace(prectangle, iMonitor, iMonitor);

   //}


   //bool display::monitor_to_wkspace(::int_rectangle * prectangle, ::collection::index iWkspace, ::collection::index iMonitor)
   //{

   //   ::int_rectangle rectangle(prectangle);

   //   ::int_rectangle rectangleMonitor;

   //   if (!get_monitor_rect(iMonitor, rectangleMonitor))
   //   {

   //      return false;

   //   }

   //   rectangle -= rectangleMonitor.top_left();

   //   ::int_rectangle rectangleWkspace;

   //   if (!get_wkspace_rect(iWkspace, rectangleWkspace))
   //   {

   //      return false;

   //   }

   //   rectangle += rectangleWkspace.top_left();

   //   *prectangle = rectangle;

   //   return true;

   //}


   void display::_get_monitor(::int_rectangle_array & rectaMonitor, ::int_rectangle_array & rectaIntersect, const int_rectangle & rectangleParam)
   {

      for (::collection::index iMonitor = 0; iMonitor < get_monitor_count(); iMonitor++)
      {

         ::int_rectangle rectangleIntersect;

         ::int_rectangle rectangleMonitor;

         auto pmonitor = get_monitor(iMonitor);

         rectangleMonitor = pmonitor->monitor_rectangle();

         if (rectangleIntersect.top_left_null_intersect(rectangleParam, rectangleMonitor))
         {

            if (rectangleIntersect.area() >= 0)
            {

               rectaMonitor.add(rectangleMonitor);

               rectaIntersect.add(rectangleIntersect);

            }

         }

      }

   }




   //::mutex g_monitor_adjust;



#define ZONEING_COMPARE ::comparison

   long long g_i_get_best_zoneing = 0;


   ::collection::index display::_get_best_zoneing(::e_display * pedisplay, ::int_rectangle * prectangle, const ::int_rectangle & rectangleRequest, bool bPreserveSize)
   {

      ::int_rectangle rectangle(rectangleRequest);

      ::int_rectangle rectangleWkspace;

      ::collection::index iBestWkspace = get_best_workspace(&rectangleWkspace, rectangle);

      ::e_display edisplay;

      ::e_display edisplayPrevious = *pedisplay;

      auto psystem = system();

      double dMargin = psystem->m_dDpi;

      if (ZONEING_COMPARE::is_equal(rectangle.top, rectangleWkspace.top, dMargin, !(edisplayPrevious & e_display_top)))
      {

         edisplay |= e_display_top;

         if (bPreserveSize)
         {

            rectangle.move_top_to(rectangleWkspace.top);

         }
         else
         {

            rectangle.top = rectangleWkspace.top;

         }

      }
      else if (ZONEING_COMPARE::is_equal(rectangle.bottom, rectangleWkspace.bottom, dMargin, !(edisplayPrevious & e_display_bottom)))
      {

         edisplay |= e_display_bottom;

         if (bPreserveSize)
         {

            rectangle.move_bottom_to(rectangleWkspace.bottom);

         }
         else
         {

            rectangle.bottom = rectangleWkspace.bottom;

         }

      }

      if (ZONEING_COMPARE::is_equal(rectangleRequest.left, rectangleWkspace.left, dMargin, !(edisplayPrevious & e_display_left)))
      {

         edisplay |= e_display_left;

         if (bPreserveSize)
         {

            rectangle.move_left_to(rectangleWkspace.left);

         }
         else
         {

            rectangle.left = rectangleWkspace.left;

         }

      }
      else if (ZONEING_COMPARE::is_equal(rectangleRequest.right, rectangleWkspace.right, dMargin, !(edisplayPrevious & e_display_right)))
      {

         edisplay |= e_display_right;

         if (bPreserveSize)
         {

            rectangle.move_right_to(rectangleWkspace.right);

         }
         else
         {

            rectangle.right = rectangleWkspace.right;

         }

      }

      if (!(edisplay & e_display_top || edisplay & e_display_bottom)
         && is_different(edisplay & e_display_left, edisplay & e_display_right))
      {

         if (ZONEING_COMPARE::is_centered(rectangleWkspace.top, rectangle.top, rectangle.bottom, rectangleWkspace.bottom))
         {

            edisplay |= e_display_bottom;

            edisplay |= e_display_top;

            rectangle.bottom = rectangleWkspace.bottom;

            rectangle.top = rectangleWkspace.top;

         }

      }

      if (!(edisplay & e_display_left || edisplay & e_display_right)
         && is_different(edisplay & e_display_top, edisplay & e_display_bottom))
      {

         if (ZONEING_COMPARE::is_centered(rectangleWkspace.left, rectangle.left, rectangle.right, rectangleWkspace.right))
         {

            edisplay |= e_display_left;

            edisplay |= e_display_right;

            rectangle.left = rectangleWkspace.left;

            rectangle.right = rectangleWkspace.right;

         }

      }

      bool bLeftXorRight = is_different(edisplay & e_display_left, edisplay & e_display_right);

      bool bTopXorBottom = is_different(edisplay & e_display_top, edisplay & e_display_bottom);

      bool bTopAndBottom = edisplay & e_display_top && edisplay & e_display_bottom;

      bool bLeftAndRight = edisplay & e_display_left && edisplay & e_display_right;

      if (bLeftXorRight && bTopXorBottom)
      {

      }
      else if (bTopAndBottom && bLeftAndRight)
      {

         edisplay = e_display_zoomed;

      }
      else
      {

         if (bLeftXorRight && !bTopAndBottom)
         {

            edisplay = e_display_none;

         }

         if (bTopXorBottom && !bLeftAndRight)
         {

            edisplay = e_display_none;

         }

         if (bTopAndBottom)
         {

            edisplay -= e_display_top;

            edisplay -= e_display_bottom;

         }

         if (bLeftAndRight)
         {

            edisplay -= e_display_left;

            edisplay -= e_display_right;

         }

      }

      if (edisplay == e_display_none)
      {

         edisplay = e_display_normal;

      }

      if (is_docking_appearance(edisplay))
      {

         *prectangle = rectangle;

      }
      else if (edisplay == e_display_zoomed)
      {

         *prectangle = rectangleWkspace;

      }
      else
      {

         *prectangle = rectangleRequest;

      }

      if (pedisplay)
      {

         *pedisplay = edisplay;

      }

      //if (g_i_get_best_zoneing % 10 == 0)
      //{

      //   string strE("e");
      //   if (edisplay & e_display_left)
      //      strE += "L";
      //   if (edisplay & e_display_top)
      //      strE += "T";
      //   if (edisplay & e_display_right)
      //      strE += "R";
      //   if (edisplay & e_display_bottom)
      //      strE += "B";

      //   string strP("p");
      //   if (edisplayPrevious & e_display_left)
      //      strP += "L";
      //   if (edisplayPrevious & e_display_top)
      //      strP += "T";
      //   if (edisplayPrevious & e_display_right)
      //      strP += "R";
      //   if (edisplayPrevious & e_display_bottom)
      //      strP += "B";

      //   ::output_debug_string(
      //      "w" + __string(rectangleWkspace.left) + ","
      //      + __string(rectangleWkspace.top) + ","
      //      + __string(rectangleWkspace.right) + ","
      //      + __string(rectangleWkspace.bottom) + " " +
      //      "r" + __string(prectangle->left) + ","
      //      + __string(prectangle->top) + ","
      //      + __string(prectangle->right) + ","
      //      + __string(prectangle->bottom) + " " +
      //      strE + " " + strP + "\n");

      //}


      //g_i_get_best_zoneing++;

      //   rectangleWkspace.left,
      //   rectangleWkspace.top,
      //   rectangleWkspace.right,
      //   rectangleWkspace.bottom,
      //   (edisplay & e_display_left)?'L':' ',
      //   (edisplay & e_display_top) ? 'T':' ',
      //   (edisplay & e_display_right) ? 'R':' ',
      //   (edisplay & e_display_bottom) ? 'B':' ',
      //   (edisplayPrevious & e_display_left) ? 'L':' ',
      //   (edisplayPrevious & e_display_top) ? 'T':' ',
      //   (edisplayPrevious & e_display_right) ? 'R':' ',
      //   (edisplayPrevious & e_display_bottom) ? 'B':' ');

      return iBestWkspace;

   }


   ::collection::index display::get_best_monitor(::int_rectangle * prectangle, const int_rectangle & rectangleParam, const ::user::activation & useractivation, ::user::interaction * puserinteractionGetCursorPosition)
   {

      ::collection::index iMatchingMonitor = -1;

      long long iBestArea = -1;

      ::int_rectangle rectangleMatch;

      ::int_rectangle rectangle(rectangleParam);

      if (useractivation & ::user::e_activation_under_mouse_cursor || rectangle.is_null())
      {

         ::int_point pointCursor = puserinteractionGetCursorPosition->host_mouse_cursor_position();

         rectangle.set(pointCursor - ::int_size(5, 5), ::int_size(10, 10));

      }

      for (::collection::index iMonitor = 0; iMonitor < get_monitor_count(); iMonitor++)
      {

         ::int_rectangle rectangleIntersect;

         ::int_rectangle rectangleMonitor;

         auto pmonitor = get_monitor(iMonitor);

         if (pmonitor)
         {

            //if (pmonitor->get_monitor_rectangle(rectangleMonitor))
            rectangleMonitor = pmonitor->monitor_rectangle();
            //{

            if (rectangleIntersect.top_left_null_intersect(rectangle, rectangleMonitor))
            {

               if (rectangleIntersect.area() > iBestArea)
               {

                  iMatchingMonitor = iMonitor;

                  iBestArea = rectangleIntersect.area();

                  rectangleMatch = rectangleMonitor;

               }

            }
            else if (rectangleMonitor.contains(rectangle))
            {

               iMatchingMonitor = iMonitor;

               rectangleMatch = rectangleMonitor;

            }

            //}

         }

      }

      if (iMatchingMonitor >= 0)
      {

         if (prectangle != nullptr)
         {

            *prectangle = rectangleMatch;

         }

         return iMatchingMonitor;

      }

      iMatchingMonitor = get_main_monitor(*prectangle);

      return iMatchingMonitor;

   }


   ::collection::index display::get_best_workspace(::int_rectangle * prectangle, const int_rectangle & rectangleParam, const ::user::activation & useractivation, ::user::interaction * puserinteractionGetCursorPosition)
   {

      ::collection::index iMatchingWkspace = -1;

      long long iBestArea = -1;

      ::int_rectangle rectangleMatch;

      ::int_rectangle rectangle(rectangleParam);

      if (::is_set(puserinteractionGetCursorPosition) && ((useractivation & ::user::e_activation_under_mouse_cursor) || rectangle.is_null()))
      {

         ::int_point pointCursor = puserinteractionGetCursorPosition->host_mouse_cursor_position();

         rectangle.set(pointCursor - ::int_size(5, 5), ::int_size(10, 10));

      }

      for (::collection::index iWorkspace = 0; iWorkspace < get_monitor_count(); iWorkspace++)
      {

         ::int_rectangle rectangleIntersect;

         ::int_rectangle rectangleWorkspace;

         auto pmonitor = get_monitor(iWorkspace);

         if (::is_null(pmonitor))
         {

            continue;

         }

         rectangleWorkspace = pmonitor->workspace_rectangle();

         //if (pmonitor->get_workspace_rectangle(rectangleMonitor))
         //{

         if (rectangleIntersect.top_left_null_intersect(rectangle, rectangleWorkspace))
         {

            if (rectangleIntersect.area() > iBestArea)
            {

               iMatchingWkspace = iWorkspace;

               iBestArea = rectangleIntersect.area();

               rectangleMatch = rectangleWorkspace;

            }

         }
         else if (rectangleWorkspace.contains(rectangle))
         {

            iMatchingWkspace = iWorkspace;

            rectangleMatch = rectangleWorkspace;

         }

         //}

      }

      if (iMatchingWkspace >= 0)
      {

         if (prectangle != nullptr)
         {

            *prectangle = rectangleMatch;

         }

         return iMatchingWkspace;

      }

      iMatchingWkspace = get_main_workspace(*prectangle);

      return iMatchingWkspace;

   }


   ::collection::index display::get_good_iconify(::int_rectangle * prectangle, const int_rectangle & rectangleParam)
   {

      ::int_rectangle rectangleMonitor;

      ::collection::index iMatchingMonitor = get_best_monitor(&rectangleMonitor, rectangleParam);

      prectangle->left = rectangleMonitor.left;

      prectangle->top = rectangleMonitor.top;

      prectangle->right = rectangleMonitor.left;

      prectangle->bottom = rectangleMonitor.top;

      return iMatchingMonitor;

   }


   void display::open_display()
   {

      //auto estatus = 

      ::windowing::display::open_display();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //m_pwindowing = pwindowing;

      //if (!m_pwindowing)
      //{

      //   //return error_no_interface;

      //   throw ::exception(error_no_interface);


      //}

      enum_display_monitors();

      //return estatus;

   }


   void display::update_dpi()
   {


#ifdef WINDOWS_DESKTOP

      {

         auto hdc = CreateCompatibleDC(NULL);

         m_dpi = (float)GetDeviceCaps(hdc, LOGPIXELSX);

         ::DeleteDC(hdc);

      }

#else

      m_dpi = 96.0;

#endif


   }



   BOOL CALLBACK display::monitor_enum_proc(HMONITOR hmonitor, HDC hdcMonitor, LPRECT prcMonitor, LPARAM dwData)
   {

      display * pdisplay = (display *)dwData;


      pdisplay->monitor_enum(hmonitor, hdcMonitor, prcMonitor);


      return true; // to enumerate all

   }


   void display::monitor_enum(HMONITOR hmonitor, HDC hdcMonitor, LPRECT prcMonitor)
   {

      __UNREFERENCED_PARAMETER(hdcMonitor);
      __UNREFERENCED_PARAMETER(prcMonitor);

      //m_monitorinfoa.allocate(m_monitorinfoa.get_size() + 1);

      //zero(m_monitorinfoa.last());

      //m_hmonitora.add(hmonitor);

      //m_monitorinfoa.last().cbSize = sizeof(MONITORINFO);

      //::GetMonitorInfo(hmonitor, &m_monitorinfoa.last());

      //MONITORINFO mi = m_monitorinfoa.last();

      //informationf("display::monitor_enum\n");
      //informationf("upper_bound %d\n", m_monitorinfoa.get_upper_bound());
      //informationf("rcMonitor(left, top, right, bottom) %d, %d, %d, %d\n", mi.rcMonitor.left, mi.rcMonitor.top, mi.rcMonitor.right, mi.rcMonitor.bottom);
      //informationf("rcWork(left, top, right, bottom) %d, %d, %d, %d\n", mi.rcWork.left, mi.rcWork.top, mi.rcWork.right, mi.rcWork.bottom);


   }


   //::collection::index display::get_main_monitor(::int_rectangle * prectangle)
   //{

   //   const POINT pointZero = { 0, 0 };

   //   HMONITOR hmonitor = MonitorFromPoint(pointZero, MONITOR_DEFAULTTOPRIMARY);

   //   auto iIndex = m_hmonitora.find_first(hmonitor);

   //   if (prectangle)
   //   {

   //      __copy(prectangle, m_monitorinfoa[iIndex].rcMonitor);

   //   }

   //   return iIndex;

   //}


   void display::impl_set_wallpaper(::collection::index iScreen, const ::scoped_string & scopedstrLocalImagePath)
   {

      //return SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, wstring(strLocalImagePath), SPIF_UPDATEINIFILE | SPIF_SENDCHANGE) != false;

      //return false;

   }


   string display::impl_get_wallpaper(::collection::index iScreen)
   {

      //wstring  wstr;

      //wstr.get_buffer(MAX_PATH * 8);
      ////unsigned int uLen = pwsz.memsize();

      //if (!SystemParametersInfoW(SPI_GETDESKWALLPAPER, (unsigned int)wstr.get_storage_length(), wstr.m_pdata, 0))
      //{
      //   return "";

      //}
      //wstr.release_buffer();

      wstring wstr;

      return wstr;

   }


   //string user::impl_get_os_desktop_theme()
   //{

   //   return "";

   //}


   //bool user::impl_set_os_desktop_theme(const ::scoped_string & scopedstrTheme)
   //{

   //   __UNREFERENCED_PARAMETER(strTheme);

   //   return true;

   //}


   ::int_point display::_get_mouse_cursor_position()
   {

      ::int_point pointCursor;

      if (m_iMouseDevice < 0)
      {

         return pointCursor;

      }

      user_send([&pointCursor, this]()
      {

         //auto devicea = ::winrt::Windows::Devices::Input::PointerDevice::GetPointerDevices();

         //for (unsigned int u = 0; u < devicea.Size(); u++)
         //{

         //   auto device = devicea.GetAt(u);

         //   if (device.PointerDeviceType() == ::winrt::Windows::Devices::Input::PointerDeviceType::Mouse)
         //   {

               auto pointerPoint = ::winrt::Windows::UI::Input::PointerPoint::GetCurrentPoint(m_iMouseDevice);

               pointCursor.x() = (int)pointerPoint.RawPosition().X;

               pointCursor.y() = (int)pointerPoint.RawPosition().Y;

            //}

         //}

      });

      return pointCursor;

   }


} // namespace windowing_universal_windows



