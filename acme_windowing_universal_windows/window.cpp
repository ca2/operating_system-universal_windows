// Created by camilo on 2022-01-21 05:05 PM <3ThomasBorregaardSorensen
#include "framework.h"
#include "acme/nano/graphics/device.h"
#include "application.h"
#include "window.h"
#include "windowing.h"
//#include "user.h"
#include "acme/constant/user_key.h"
#include "acme/parallelization/task.h"
//#include "acme/nano/nano.h"
//#include "acme/nano/user/button.h"
//#include "acme/nano/user/message_box.h"
#include "acme/platform/application.h"
#include "acme/platform/node.h"
#include "acme/platform/system.h"
#include "acme/user/micro/elemental.h"
#include "acme/user/user/frame_interaction.h"
#include "acme/user/user/interaction.h"
#include "acme/user/user/key.h"
#include "acme/user/user/mouse.h"
//#include "acme/windowing/windowing.h"
//#include "acme/operating_system/windows/windows.h"
#include "acme_universal_windows/_winrt_system.h"
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.ApplicationModel.Activation.h>


//CLASS_DECL_ACME bool _c_simple_message_loop_step();

CLASS_DECL_ACME string task_get_name();
CLASS_DECL_ACME void task_set_name(const char * pszName);


class CLASS_DECL_ACME scoped_task_name
{
public:

   ::string       m_strTask;

   scoped_task_name(const ::string & strTask)
   {

      m_strTask = ::task_get_name();

      ::task_set_name(strTask);

   }

   ~scoped_task_name()
   {

      ::task_set_name(m_strTask);

   }


};


namespace universal_windows
{


   namespace acme
   {


      namespace windowing
      {


         window::window()
         {

            //m_bSizeMoveMode = false;
            //      m_bDestroy = false;
            //m_hwnd = nullptr;
            //m_hmenuSystem = nullptr;
            //m_bNcActive = false;
         }


         window::~window()
         {

            //delete_drawing_objects();

         }


         bool g_bNanoWindowClassRegistered = false;



         //CLASS_DECL_ACME_WINDOWING_UNIVERSAL_WINDOWS LRESULT CALLBACK acme_window_procedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


#define ACME_WINDOW_CLASS "acme_window_class"





         void register_nano_window_class()
         {

            if (g_bNanoWindowClassRegistered)
            {

               return;

            }

            //auto hinstanceWndProc = ::windows::get_window_procedure_hinstance();

            //WNDCLASSEX wndclassex{};

            ////Step 1: Registering the Window Class
            //wndclassex.cbSize = sizeof(WNDCLASSEX);
            //wndclassex.style = CS_DBLCLKS;
            //wndclassex.lpfnWndProc = &windows::window_procedure;
            //wndclassex.cbClsExtra = 0;
            //wndclassex.cbWndExtra = 0;
            //wndclassex.hInstance = hinstanceWndProc;
            //wndclassex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
            //wndclassex.hCursor = LoadCursor(NULL, IDC_ARROW);
            //wndclassex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
            //wndclassex.lpszMenuName = NULL;
            //wndclassex.lpszClassName = _T(ACME_WINDOW_CLASS);
            //wndclassex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

            //if (!RegisterClassEx(&wndclassex))
            //{

            //   throw ::exception(error_failed, "Failed to register nano message box window class.");

            //}

            g_bNanoWindowClassRegistered = true;

         }




         void window::create_window()
         {

            _create_window();

         }


         void window::_create_window()
         {


            if (!g_bNanoWindowClassRegistered)
            {

               register_nano_window_class();

            }

            wstring wstrTitle(m_pacmeuserinteraction->get_title());

            //auto hinstanceWndProc = ::windows::get_window_procedure_hinstance();

            //m_ptask = ::get_task();

            //auto r = m_pacmeuserinteraction->get_rectangle();

            //::cast < ::acme::user::frame_interaction > pframeinteraction = m_pacmeuserinteraction;

            //DWORD dwExStyle = 0;

            //if (pframeinteraction && pframeinteraction->m_bTopMost)
            //{

            //   dwExStyle |= WS_EX_TOPMOST;

            //}

            //HWND hwnd = CreateWindowEx(
            //   dwExStyle,
            //   _T(ACME_WINDOW_CLASS),
            //   wstrTitle,
            //   WS_POPUP | WS_SYSMENU,
            //   r.left(),
            //   r.top(),
            //   r.width(),
            //   r.height(),
            //   NULL, NULL, hinstanceWndProc,
            //   (::windows::window *)this);

            //if (hwnd == NULL)
            //{
            //   throw ::exception(error_failed, "Failed to create nano message box window.");
            //   return;
            //}

            //nanowindowimplementationa().add(this);

            //system()->window_

         }


         void window::destroy_window()
         {

            main_send()
               << [this]()
               {

                  //if (!::DestroyWindow(m_hwnd))
                  //{

                  //   informationf("window::destroy_window Failed to destroy window");

                  //}
                  //else
                  //{

                  //   informationf("window::destroy_window Window destroyed!!");

                  //}

               };

            destroy();

         }


         //void window::on_char(int iChar)
         //{

         //   m_pacmeuserinteraction->on_char(iChar);

         //}


         void window::_draw(HDC hdc)
         {

            ::int_rectangle r;

            //GetWindowRect(m_hwnd, (LPRECT)&r);

            //HGDIOBJ hbrushOld = ::GetCurrentObject(hdc, OBJ_BRUSH);
            //HGDIOBJ hfontOld = ::GetCurrentObject(hdc, OBJ_FONT);
            //HGDIOBJ hpenOld = ::GetCurrentObject(hdc, OBJ_PEN);

            //{

            //   //nano()->graphics();

            //   __øconstruct(m_pnanodevice);

            //   m_pnanodevice->attach(hdc, { ::width(r), ::height(r) });

            //   ::pointer < ::micro::elemental > pelemental;

            //   pelemental = m_pacmeuserinteraction;

            //   if (pelemental)
            //   {

            //      pelemental->draw_background(m_pnanodevice);

            //      pelemental->draw_foreground(m_pnanodevice);

            //   }

            //}

            //::SelectObject(hdc, hpenOld);
            //::SelectObject(hdc, hfontOld);
            //::SelectObject(hdc, hbrushOld);

         }


         //bool window::is_active()
         //{

         //   return m_pm_bNcActive;

         //}


         //void window::draw_children(HDC hdc)
         //{

         //   for (auto & pchild: m_childa)
         //   {

         //      pchild->on_draw(hdc);

         //   }

         //}

         //void window::delete_drawing_objects()
         //{

         //   //if (m_hbrushWindow)
         //   //{

         //   //   ::DeleteObject(m_hbrushWindow);

         //   //   m_hbrushWindow = nullptr;

         //   //}

         //   //if (m_hpenBorder)
         //   //{

         //   //   ::DeleteObject(m_hpenBorder);

         //   //   m_hpenBorder = nullptr;

         //   //}


         //   //if (m_hpenBorderFocus)
         //   //{

         //   //   ::DeleteObject(m_hpenBorderFocus);

         //   //   m_hpenBorderFocus = nullptr;

         //   //}

         //   m_pacmeuserinteraction->delete_drawing_objects();

         //}


         //bool window::get_dark_mode()
         //{

         //   return !_is_light_theme();

         //}


         //void window::create_drawing_objects()
         //{

         //   //if (m_hfont == nullptr)
         //   //{

         //   //   HDC hdc = ::GetDC(m_hwnd);
         //   //   int nHeight = -MulDiv(14, GetDeviceCaps(hdc, LOGPIXELSY), 72);
         //   //   m_hfont = ::CreateFontW(nHeight, 0, 0, 0, FW_NORMAL, 0, 0, 0, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
         //   //                           CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, FF_SWISS, L"Segoe UI");
         //   //   ::ReleaseDC(m_hwnd, hdc);

         //   //}

         //   //bool bDarkMode = get_dark_mode();

         //   //if (bDarkMode)
         //   //{

         //   //   m_crWindow = RGB(0, 0, 0);
         //   //   m_crText = RGB(255, 255, 255);
         //   //   m_crFocus = RGB(2, 128, 255);

         //   //} else
         //   //{

         //   //   m_crWindow = RGB(255, 255, 255);
         //   //   m_crText = RGB(0, 0, 0);
         //   //   m_crFocus = RGB(1, 64, 128);

         //   //}

         //   //m_hbrushWindow = CreateSolidBrush(m_crWindow);
         //   //m_hpenBorder = CreatePen(PS_SOLID, 1, m_crText);
         //   //m_hpenBorderFocus = CreatePen(PS_SOLID, 1, m_crFocus);

         //   m_pacmeuserinteraction->create_drawing_objects();

         //}

         //void window::update_drawing_objects()
         //{

         //   delete_drawing_objects();
         //   create_drawing_objects();


         //}


         //::atom window::hit_test(int x, int y)
         //{
         //
         //   for (int i = 0; i < m_iButtonCount; i++)
         //   {
         //      if (m_buttona[i].m_rectangle.contains(int_point(x, y)))
         //      {
         //
         //         return m_buttona[i].m_edialogresult;
         //
         //      }
         //
         //   }
         //
         //   return e_dialog_result_none;
         //
         //}
         //

         //void window::on_left_button_down(::user::mouse* pmouse)
         //{

         //   //SetCapture(m_hwnd);

         //   //m_atomLeftButtonDown = hit_test(x, y);

         //   //if (m_pdragmove && m_atomLeftButtonDown == e_dialog_result_none)
         //   //{

         //   //   m_pdragmove->m_bLButtonDown = true;

         //   //   m_pdragmove->m_bDrag = false;

         //   //   int_point pointCursor(x, y);

         //   //   pointCursor += m_rectangle.origin();

         //   //   m_pdragmove->m_pointLButtonDown = pointCursor;

         //   //   m_pdragmove->m_sizeLButtonDownOffset = m_pdragmove->m_pointLButtonDown - m_rectangle.origin();

         //   //   return;

         //   //}

         //   m_pacmeuserinteraction->on_left_button_down(pmouse);

         //}


         //void window::on_left_button_up(::user::mouse* pmouse)
         //{

         //   //ReleaseCapture();

         //   //if (m_pdragmove && (m_pdragmove->m_bLButtonDown || m_pdragmove->m_bDrag))
         //   //{

         //   //   m_pdragmove->m_bLButtonDown = false;

         //   //   m_pdragmove->m_bDrag = false;

         //   //   return;

         //   //}

         //   //m_atomLeftButtonUp = hit_test(x, y);

         //   //if (m_atomLeftButtonUp == m_atomLeftButtonDown && m_atomLeftButtonUp != e_dialog_result_none)
         //   //{

         //   //   m_atomResult = m_atomLeftButtonUp;

         //   //   on_click(m_atomResult);

         //   //}

         //   m_pacmeuserinteraction->on_left_button_up(pmouse);

         //}

         //void window::on_mouse_move(::user::mouse* pmouse)
         //{

         //   //if (m_pdragmove && m_pdragmove->m_bLButtonDown)
         //   //{

         //   //   ::SetCursor(::LoadCursor(NULL, IDC_SIZEALL));

         //   //   if (!m_pdragmove->m_bDrag)
         //   //   {

         //   //      m_pdragmove->m_bDrag = true;

         //   //      int_point pointCursor(x, y);

         //   //      pointCursor += m_rectangle.origin();

         //   //      auto point = pointCursor - m_pdragmove->m_sizeLButtonDownOffset;

         //   //      move_to(pmouse);

         //   //      m_pdragmove->m_bDrag = false;

         //   //   }

         //   //   return;

         //   //}

         //   m_pacmeuserinteraction->on_mouse_move(pmouse);

         //}


         //void window::on_right_button_down(::user::mouse* pmouse)
         //{

         //   //SetCapture(m_hwnd);

         //   //m_atomLeftButtonDown = hit_test(x, y);

         //   //if (m_pdragmove && m_atomLeftButtonDown == e_dialog_result_none)
         //   //{

         //   //   m_pdragmove->m_bLButtonDown = true;

         //   //   m_pdragmove->m_bDrag = false;

         //   //   int_point pointCursor(x, y);

         //   //   pointCursor += m_rectangle.origin();

         //   //   m_pdragmove->m_pointLButtonDown = pointCursor;

         //   //   m_pdragmove->m_sizeLButtonDownOffset = m_pdragmove->m_pointLButtonDown - m_rectangle.origin();

         //   //   return;

         //   //}

         //   m_pacmeuserinteraction->on_right_button_down(pmouse);

         //}


         //void window::on_right_button_up(::user::mouse* pmouse)
         //{

         //   //ReleaseCapture();

         //   //if (m_pdragmove && (m_pdragmove->m_bLButtonDown || m_pdragmove->m_bDrag))
         //   //{

         //   //   m_pdragmove->m_bLButtonDown = false;

         //   //   m_pdragmove->m_bDrag = false;

         //   //   return;

         //   //}

         //   //m_atomLeftButtonUp = hit_test(x, y);

         //   //if (m_atomLeftButtonUp == m_atomLeftButtonDown && m_atomLeftButtonUp != e_dialog_result_none)
         //   //{

         //   //   m_atomResult = m_atomLeftButtonUp;

         //   //   on_click(m_atomResult);

         //   //}

         //   m_pacmeuserinteraction->on_right_button_up(pmouse);

         //}



         //::payload window::get_result()
         //{

         //   return m_pacmeuserinteraction->get_result();

         //}




         //::micro::child * window::hit_test(const ::int_point & point, ::user::e_zorder ezorder)
         //{

         //   return m_pacmeuserinteraction->hit_test(point);

         //}


      //LRESULT CALLBACK ::micro::message_box::s_window_procedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
      //{
      //if (msg == WM_NCCREATE)
      //{
      //
      //   CREATESTRUCT * pcreatestruct = (CREATESTRUCT *)lParam;
      //   SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pcreatestruct->lpCreateParams);
      //
      //}
      //::micro::message_box * pwindow = (::micro::message_box *)GetWindowLongPtr(hwnd, GWLP_USERDATA);
      //
      //if (!pwindow)
      //{
      //   return DefWindowProc(hwnd, msg, wParam, lParam);
      //}
      //return pwindow->window_procedure(msg, wParam, lParam);
      //
      //}


         ::oswindow window::oswindow()
         {

            //return as_oswindow(m_hwnd);

            return {};

         }

         bool window::_is_light_theme()
         {

            DWORD dwBuffer;

            DWORD dwSize = sizeof(dwBuffer);

            auto res = RegGetValueW(
               HKEY_CURRENT_USER,
               L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
               L"AppsUseLightTheme",
               RRF_RT_REG_DWORD, // expected value type
               nullptr,
               &dwBuffer,
               &dwSize);

            if (res != ERROR_SUCCESS)
            {

               throw ::exception(error_failed);

            }

            return dwBuffer != FALSE;

         }


         //bool window::on_window_procedure(LRESULT & lresult, UINT message, WPARAM wparam, LPARAM lparam)
         //{

         //   if (::windows::window::on_window_procedure(lresult, message, wparam, lparam))
         //   {

         //      return true;

         //   }

         //   lresult = window_procedure(message, wparam, lparam);

         //   return true;

         //}



         //LRESULT window::window_procedure(unsigned int message, wparam wparam, lparam lparam)
         //{

         //   //{

         //   //   LRESULT lresult = 0;

         //   //   if (on_window_procedure(lresult, message, wparam, lparam))
         //   //   {

         //   //      return lresult;

         //   //   }

         //   //}

         //   switch (message)
         //   {
         //   case WM_COMMAND:
         //   {
         //      /* ::pointer < ::windows::micro::user > pnanouser = system()->acme_windowing();

         //       LRESULT lresult = 0;

         //       if (pnanouser->_on_command(lresult, m_hwnd, wparam, lparam))
         //       {

         //          return lresult;

         //       }*/

         //      return DefWindowProc(m_hwnd, message, wparam, lparam);

         //   }

         //   break;
         //   case WM_SYSCOMMAND:
         //   {

         //      return DefWindowProc(m_hwnd, message, wparam, lparam);

         //   }

         //   break;
         //   case WM_CLOSE:
         //   {
         //      //DestroyWindow(m_hwnd);

         //      ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;

         //      if (pelemental)
         //      {

         //         pelemental->on_click(e_dialog_result_cancel, nullptr);

         //      }

         //   }
         //   return 0;
         //   break;
         //   case WM_NCDESTROY:
         //      break;
         //      //case WM_INITMENU:
         //      //   {
         //      //   ::pointer < ::windows::micro::user > pnanouser = system()->acme_windowing();

         //      //   LRESULT lresult = 0;

         //      //   if (pnanouser->_on_default_system_menu_init_menu(lresult, m_hwnd, m_hmenuSystem, wparam))
         //      //   {

         //      //      return lresult;

         //      //   }

         //      //   }
         //      //   break;
         //   case WM_DESTROY:
         //      //PostQuitMessage(0);
         //      system()->acme_windowing()->m_windowa.erase(this);
         //      break;
         //   case WM_CREATE:
         //   {
         //      //update_drawing_objects();

         //      on_create_window();

         //   }
         //   break;
         //   case WM_CHAR:
         //   {

         //      ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;

         //      if (pelemental)
         //      {

         //         pelemental->on_char((int)wparam);

         //      }
         //      return 0;
         //   }
         //   break;
         //   case WM_LBUTTONDOWN:
         //   {

         //      auto pmouse = __create_new < ::user::mouse >();

         //      pmouse->m_pointHost = lparam;

         //      pmouse->m_pointAbsolute = client_to_screen(lparam);

         //      ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;

         //      if (pelemental)
         //      {

         //         pelemental->fore_on_left_button_down(pmouse);

         //      }

         //      if (!pmouse->m_bRet)
         //      {


         //         if (pelemental)
         //         {

         //            pelemental->back_on_left_button_down(pmouse);

         //         }

         //      }

         //   }
         //   break;
         //   case WM_MOUSEMOVE:
         //   {

         //      auto pmouse = __create_new < ::user::mouse >();

         //      pmouse->m_pointHost = lparam;

         //      pmouse->m_pointAbsolute = client_to_screen(lparam);

         //      ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;

         //      if (pelemental)
         //      {

         //         pelemental->fore_on_mouse_move(pmouse);

         //      }

         //      if (!pmouse->m_bRet)
         //      {


         //         if (pelemental)
         //         {

         //            pelemental->fore_on_mouse_move(pmouse);

         //         }

         //      }


         //   }
         //   break;
         //   case WM_LBUTTONUP:
         //   {

         //      auto pmouse = __create_new < ::user::mouse >();

         //      pmouse->m_pointHost = lparam;

         //      pmouse->m_pointAbsolute = client_to_screen(lparam);

         //      ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;

         //      if (pelemental)
         //      {

         //         pelemental->fore_on_left_button_up(pmouse);

         //      }

         //      if (!pmouse->m_bRet)
         //      {


         //         if (pelemental)
         //         {

         //            pelemental->back_on_left_button_up(pmouse);

         //         }

         //      }


         //   }
         //   break;
         //   case WM_RBUTTONDOWN:
         //   {

         //      auto pmouse = __create_new < ::user::mouse >();

         //      pmouse->m_pointHost = lparam;

         //      pmouse->m_pointAbsolute = client_to_screen(lparam);

         //      ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;

         //      if (pelemental)
         //      {

         //         pelemental->fore_on_right_button_down(pmouse);

         //      }

         //      if (!pmouse->m_bRet)
         //      {


         //         if (pelemental)
         //         {

         //            pelemental->back_on_right_button_down(pmouse);

         //         }

         //      }


         //   }
         //   break;
         //   case WM_RBUTTONUP:
         //   {

         //      auto pmouse = __create_new < ::user::mouse >();

         //      pmouse->m_pointHost = lparam;

         //      pmouse->m_pointAbsolute = client_to_screen(lparam);

         //      ::cast < ::micro::elemental > pelemental = m_pacmeuserinteraction;

         //      if (pelemental)
         //      {

         //         pelemental->fore_on_right_button_up(pmouse);

         //      }

         //      if (!pmouse->m_bRet)
         //      {


         //         if (pelemental)
         //         {

         //            pelemental->back_on_right_button_up(pmouse);

         //         }

         //      }


         //   }
         //   break;
         //   case WM_ERASEBKGND:
         //      return 1;
         //   case WM_MOUSEACTIVATE:
         //      return MA_ACTIVATE;
         //   case WM_PAINT:
         //   {

         //      PAINTSTRUCT paintstruct{};

         //      HDC hdcWindow = BeginPaint(m_hwnd, &paintstruct);

         //      HDC hdc = ::CreateCompatibleDC(hdcWindow);

         //      ::int_rectangle rectangleX;

         //      ::GetClientRect(m_hwnd, (LPRECT)&rectangleX);

         //      HBITMAP hbitmap = ::CreateCompatibleBitmap(hdcWindow, rectangleX.width(), rectangleX.height());

         //      HGDIOBJ hbitmapOld = ::SelectObject(hdc, hbitmap);

         //      _draw(hdc);


         //      ::BitBlt(hdcWindow, 0, 0, rectangleX.width(), rectangleX.height(),
         //         hdc, 0, 0, SRCCOPY);

         //      hbitmapOld = ::SelectObject(hdc, hbitmapOld);

         //      ::DeleteDC(hdc);
         //      EndPaint(m_hwnd, &paintstruct);
         //   }
         //   break;
         //   case WM_NCACTIVATE:
         //   {
         //      LRESULT lresult = DefWindowProc(m_hwnd, message, wparam, lparam);
         //      m_bNcActive = wparam != 0;
         //      redraw();

         //      return lresult;

         //   }
         //   case WM_ACTIVATE:
         //   {

         //      if (wparam > 0)
         //      {

         //         ::SetFocus(m_hwnd);

         //      }

         //      return 0;

         //   }
         //   case WM_FONTCHANGE:
         //   {

         //      redraw();

         //   }
         //   break;
         //   case WM_SETTINGCHANGE:
         //   {

         //      string strLparamString;

         //      if (wparam == 0)
         //      {

         //         strLparamString = (const WCHAR *)(LPARAM(lparam));

         //      }

         //      if (strLparamString == "ImmersiveColorSet")
         //      {

         //         //system()->acme_windowing()->fetch_dark_mode();

         //         //update_drawing_objects();

         //         //redraw();

         //      }
         //      else if (wparam == SPI_SETWORKAREA)
         //      {

         //         redraw();

         //      }

         //   }
         //   break;

         //   default:
         //   {

         //      return DefWindowProc(m_hwnd, message, wparam, lparam);

         //   }

         //   }

         //   return 0;

         //}

         ////
         ////
         ////HINSTANCE nano_message_box_hinstance()
         ////{
         ////
         ////   HINSTANCE hinstanceWndProc = (HINSTANCE) ::GetModuleHandleA("acme.dll");
         ////
         ////   if (hinstanceWndProc == nullptr)
         ////   {
         ////
         ////      hinstanceWndProc = (HINSTANCE)::GetModuleHandleA(NULL);
         ////
         ////   }
         ////
         ////   return hinstanceWndProc;
         ////
         ////}

         ////
         ////void register_nano_window_class()
         ////{
         ////
         ////   if (g_bNanoWindowClassRegistered)
         ////   {
         ////
         ////      return;
         ////
         ////   }
         ////
         ////   auto hinstanceWndProc = nano_message_box_hinstance();
         ////
         ////   WNDCLASSEX wndclassex;
         ////
         ////   //Step 1: Registering the Window Class
         ////   wndclassex.cbSize = sizeof(WNDCLASSEX);
         ////   wndclassex.style = 0;
         ////   wndclassex.lpfnWndProc = &message_box_window_procedure;
         ////   wndclassex.cbClsExtra = 0;
         ////   wndclassex.cbWndExtra = 0;
         ////   wndclassex.hInstance = hinstanceWndProc;
         ////   wndclassex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
         ////   wndclassex.hCursor = LoadCursor(NULL, IDC_ARROW);
         ////   wndclassex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
         ////   wndclassex.lpszMenuName = NULL;
         ////   wndclassex.lpszClassName = _T(NANO_MESSAGE_BOX_WINDOW_CLASS);
         ////   wndclassex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
         ////
         ////   if (!RegisterClassEx(&wndclassex))
         ////   {
         ////
         ////      throw ::exception(error_failed, "Failed to register nano message box window class.");
         ////
         ////   }
         ////
         ////   g_bNanoWindowClassRegistered = true;
         ////
         ////}
         ////

         void window::show_window()
         {

            main_send([this]()
               {

                  //if (!::IsWindow(m_hwnd))
                  {

                     create_window();

                  }

                  /*              ::ShowWindow(m_hwnd, SW_SHOW);

                                ::UpdateWindow(m_hwnd);

                                ::BringWindowToTop(m_hwnd);*/

            });

         }


         void window::hide_window()
         {

            main_send([this]()
               {

                  //if (::IsWindow(m_hwnd))
                  //{

                  //   ::ShowWindow(m_hwnd, SW_HIDE);

                  //}

            });

         }

         //void window::add_child(::micro::child* pchild)
         //{

         //   m_pacmeuserinteraction->add_child(pchild);

         //}


         void window::redraw()
         {

            // ::RedrawWindow(m_hwnd, nullptr, nullptr, RDW_UPDATENOW | RDW_INVALIDATE);

         }


         bool window::_is_window()
         {

            //return ::IsWindow(m_hwnd);

            return true;

         }


         ::int_point window::client_to_screen(const ::int_point & point)
         {

            POINT p{ point.x(), point.y() };

            //::ClientToScreen(m_hwnd, &p);

            return { p.x, p.y };

         }


         //void window::_destroy_window()
         //{
         //
         //}


         void window::destroy()
         {

            ::acme::windowing::window::destroy();
            //::windows::window::destroy();
            //user_post([this]()
            //   {

            //      //::ShowWindow(m_hwnd, SW_HIDE);

            //      ::DestroyWindow(m_hwnd);

            //      system()->acme_windowing()->process_messages();

            //   });

         }


         //
         //LRESULT window::window_procedure(UINT message, WPARAM wparam, LPARAM lparam)
         //{
         //   switch (message)
         //   {
         //   case WM_CLOSE:
         //      DestroyWindow(m_hwnd);
         //      break;
         //   case WM_DESTROY:
         //      PostQuitMessage(0);
         //      break;
         //   case WM_CREATE:
         //   {
         //      update_drawing_objects();
         //   }
         //   break;
         //   case WM_LBUTTONDOWN:
         //      on_left_button_down(lparam_int_x(lparam), lparam_int_y(lparam));
         //      break;
         //   case WM_LBUTTONUP:
         //   {
         //      on_left_button_up(lparam_int_x(lparam), lparam_int_y(lparam));
         //   }
         //
         //   break;
         //   case WM_PAINT:
         //   {
         //      PAINTSTRUCT paintstruct{};
         //      HDC hdc = BeginPaint(m_hwnd, &paintstruct);
         //      draw(hdc);
         //      EndPaint(m_hwnd, &paintstruct);
         //   }
         //   break;
         //   default:
         //      return DefWindowProc(m_hwnd, message, wparam, lparam);
         //   }
         //   return 0;
         //}


         //void window::on_click(const ::payload& payloadParam, ::user::mouse* pmouse)
         //{

         //   auto payload = payloadParam;

         //   //fork([this, atom, pmouse]()
         //      //{

         //   m_pacmeuserinteraction->on_click(payload, pmouse);

         //   //}, { pmouse });

         //}


         //void window::on_right_click(const ::payload& payloadParam, ::user::mouse* pmouse)
         //{

         //   auto payload = payloadParam;

         //   //fork([this, atom, pmouse]()
         //     // {

         //   m_pacmeuserinteraction->on_right_click(payload, pmouse);

         //   //}, {pmouse});


         //}


         void window::set_position(const ::int_point & point)
         {

            auto pacmeuserinteractionOwner = owner_interaction();

            HWND hwndParent = nullptr;

            //if (pacmeuserinteractionOwner)
            //{

            //   ::cast < ::universal_windows::acme::windowing::window > pwindowOwner = pacmeuserinteractionOwner->m_pacmewindowingwindow;

            //   hwndParent = pwindowOwner->m_hwnd;

            //}

            //::cast < ::acme::user::frame_interaction > pframeinteraction = m_pacmeuserinteraction;

            //DWORD dwFlags = SWP_NOSIZE;

            //if (pframeinteraction && pframeinteraction->m_bTopMost)
            //{

            //   hwndParent = HWND_TOPMOST;

            //}
            //else if (!hwndParent)
            //{

            //   dwFlags |= SWP_NOZORDER;

            //}

            //::SetWindowPos(m_hwnd, hwndParent, point.x(), point.y(), 0, 0, dwFlags);

         }


         //::int_point window::try_absolute_mouse_position(const ::int_point& point)
         //{

         //   return point;

         //}


         //::int_rectangle window::get_client_rectangle()
         //{

         //   ::int_rectangle rectangle;

         //   ::GetClientRect(m_hwnd, (LPRECT)&rectangle);

         //   return rectangle;

         //}


         int_rectangle window::get_window_rectangle()
         {

            ::int_rectangle rectangle;

            //::GetWindowRect(m_hwnd, (LPRECT)&rectangle);

            return rectangle;

         }


         void window::set_capture()
         {

            //SetCapture(m_hwnd);

         }


         bool window::has_capture()
         {

            //return ::GetCapture() == m_hwnd;

            return false;

         }


         void window::release_capture()
         {

            //ReleaseCapture();

         }


         void window::set_cursor(enum_cursor ecursor)
         {

            if (ecursor == e_cursor_move)
            {

               //::SetCursor(::LoadCursor(NULL, IDC_SIZEALL));

            }

         }






         void window::_user_post(const ::procedure & procedure)
         {

            if (m_ptask)
            {

               m_ptask->post(procedure);

            }
            else
            {

               ::acme::windowing::window::_user_post(procedure);

            }


         }


         void window::implementation_message_loop_step()
         {

            //_c_simple_message_loop_step();

         }


         void window::defer_show_system_menu(::user::mouse * pmouse)
         {

            //::pointer < ::windows::micro::user > pnanouser = system()->acme_windowing();

            //pnanouser->_defer_show_system_menu(m_hwnd, &m_hmenuSystem, pointAbsolute);

            ///_defer_show_system_menu(pmouse);


         }


         void process_messages(bool bWait)
         {

            auto strThreadName = ::task_get_name();

            //auto pmessagebox = m_pacmeuserinteraction.cast < ::micro::message_box >();

            //::string strAbbreviation("window");

            //if (strType.contains("message_box"))
            //if (pmessagebox)
            //{
               //auto pmessagebox = m_pacmeuserinteraction.cast<nano::me
               /// @brief ////////123456789012345
               //strAbbreviation = "msgbx:" + pmessagebox->m_strMessage.left(20);

              // strAbbreviation = "msgbx:" + pmessagebox->m_strMessage;

            //}

            //scoped_task_name scopedtaskname(strAbbreviation);

            //::task_set_name("nanownd");

            //MSG msg;

            //while (bWait ? (::GetMessage(&msg, NULL, 0, 0) > 0) :
            //   (::PeekMessage(&msg, NULL, 0, 0, TRUE)))
            //{

            //   TranslateMessage(&msg);

            //   DispatchMessage(&msg);

            //}

         }


         void window::set_mouse_capture()
         {

            //HWND hwnd = m_hwnd;

            //HWND hwndPreviouslyCapturedIfAny = ::SetCapture(hwnd);

            //HWND hwndGet = ::GetCapture();

            //if (hwndGet != hwnd && hwndGet != nullptr)
            //{

            //   //return ::error_failed;

            //   throw ::exception(error_failed);

            //}

         }


         bool window::has_mouse_capture()
         {

            //itask_t itask = get_itask();

            //HWND hwndCapture = ::windows::get_mouse_capture(itask);

            //HWND hwnd = m_hwnd;

            //if (hwndCapture == hwnd)
            //{

            //   return true;

            //}

            return false;

         }


         void window::Initialize(CoreApplicationView const & coreapplicationview)
         {

            m_coreapplicationview = coreapplicationview;

            ::winrt::Windows::ApplicationModel::Core::CoreApplication::Suspending(::winrt::Windows::Foundation::EventHandler<::winrt::Windows::ApplicationModel::SuspendingEventArgs>(this, &window::OnSuspending));

            ::winrt::Windows::ApplicationModel::Core::CoreApplication::Resuming(::winrt::Windows::Foundation::EventHandler<::winrt::Windows::Foundation::IInspectable >(this, &window::OnResuming));

            m_coreapplicationview.Activated({ this, &window::OnActivated });
            ::winrt::Windows::UI::ViewManagement::UISettings uisettings;

            auto uicolorBackground = uisettings.GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

            ::color::color colorBackground;

            colorBackground = argb(255, uicolorBackground.R, uicolorBackground.G, uicolorBackground.B);

            system()->set_background_color(colorBackground);

            //m_coreapplicationview.Activated(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::ApplicationModel::Core::CoreApplicationView, ::winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs>(this, &window::OnActivated));

            //Initialize(coreapplicationview);

         }



         void window::SetWindow(::winrt::Windows::UI::Core::CoreWindow const & window)
         {

            m_windowscorewindow = window;
            // Specify the cursor type as the standard arrow cursor.
            m_windowscorewindow.PointerCursor(CoreCursor{ CoreCursorType::Arrow, 0 });

            // Allow the application to respond when the window size changes.
            //window.SizeChanged({ this, &App::OnWindowSizeChanged });

            InstallPrototypeHappeningHandling();


            UpdateFocusUI();

            //window::SetWindow(window);

            //pbuffer = __create_new< directx_base >();

            //pbuffer->system() = system();

            auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

            //pbuffer->Initialize(window, displayinformation.LogicalDpi());

            //pbuffer->initialize(system()->m_papplicationStartup);

            //install_directx_application_message_routing();

            //initialize_directx_application();

            //m_bXXXFirst = true;

            //system()->get_session()->system()->windowing()->m_pwindowFirst = this;

            //system()->get_session()->system()->windowing()->m_bXXXFirst = true;

            ::cast <windowing> pwindowing = system()->acme_windowing();

            if (!pwindowing->m_bAppInit)
            {

               pwindowing->app_init();

            }

            if (!system()->node()->m_bHasNodePostedSystemInitialRequest)
            {

               system()->node()->m_bHasNodePostedSystemInitialRequest = true;

               system()->defer_post_initial_request();

            }


         }

         void window::UpdateFocusUI()
         {

            //BorderPanel->BorderBrush = _internalFocus ? ___new ::winrt::Windows::UI::Xaml::Media::SolidColorBrush(::winrt::Windows::UI::Colors::Green) : null;

         }


         void window::InstallPrototypeHappeningHandling()
         {

            auto window = m_windowscorewindow;

            window.VisibilityChanged(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs>(this, &window::OnWindowVisibilityChanged));

            window.PointerCursor(::winrt::Windows::UI::Core::CoreCursor(::winrt::Windows::UI::Core::CoreCursorType::Arrow, 0));

            window.SizeChanged(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::WindowSizeChangedEventArgs>(this, &window::OnWindowSizeChanged));

            window.PointerMoved(::winrt::Windows::Foundation::TypedEventHandler <::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs>(this, &window::OnPointerMoved));

            window.CharacterReceived(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs>(this, &window::OnCharacterReceived));

            window.KeyDown(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs>(this, &window::OnKeyDown));

            window.KeyUp(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs>(this, &window::OnKeyUp));

            window.PointerPressed(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs>(this, &window::OnPointerPressed));

            window.PointerReleased(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs >(this, &window::OnPointerReleased));

            //auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

            //system()->m_dDpi = displayinformation.LogicalDpi();

            //displayinformation.DpiChanged(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::Graphics::Display::DisplayInformation, ::winrt::Windows::Foundation::IInspectable >(this, &window::DpiChanged));

            //displayinformation.DisplayContentsInvalidated(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::Graphics::Display::DisplayInformation, ::winrt::Windows::Foundation::IInspectable >(this, &window::DisplayContentsInvalidated));



            m_resizemanager = ::winrt::Windows::UI::Core::CoreWindowResizeManager::GetForCurrentView();

            m_resizemanager.ShouldWaitForLayoutCompletion(true);

            //auto coreTitleBar = ::winrt::Windows::ApplicationModel::Core::CoreApplication::GetCurrentView()->TitleBar;

            //coreTitleBar->ExtendViewIntoTitleBar = true;

            m_tokenActivated = m_windowscorewindow.Activated(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::WindowActivatedEventArgs>(this, &window::CoreWindow_WindowActivated));

            m_tokenClosed = m_windowscorewindow.Closed(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CoreWindowEventArgs>(this, &window::CoreWindow_CoreWindowClosed));

            m_tokenKeyDown = m_windowscorewindow.KeyDown(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs>(this, &window::CoreWindow_KeyDown));

            m_tokenPointerPressed = m_windowscorewindow.PointerPressed(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs>(this, &window::CoreWindow_PointerPressed));

            //auto manager = ::winrt::Windows::UI::Text::Core::CoreTextServicesManager::GetForCurrentView();

            //m_editcontext = manager.CreateEditContext();

            //// Get the Input Pane so we can programmatically hide and show it.
            //m_inputpane = ::winrt::Windows::UI::ViewManagement::InputPane::GetForCurrentView();

            //// For demonstration purposes, this sample sets the Input Pane display policy to Manual
            //// so that it can manually show the software keyboard when the control gains focus and
            //// dismiss it when the control loses focus. If you leave the policy as Automatic, then
            //// the system will hide and show the Input Pane for you. Note that on Desktop, you will
            //// need to implement the UIA text pattern to get expected automatic behavior.
            //m_editcontext.InputPaneDisplayPolicy(::winrt::Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy::Automatic);

            //// Set the input scope to Text because this text box is for any text.
            //// This also informs software keyboards to show their regular
            //// text entry layout.  There are many other input scopes and each will
            //// inform a keyboard layout and text behavior.
            //m_editcontext.InputScope(::winrt::Windows::UI::Text::Core::CoreTextInputScope::Text);

            //// The system raises this happening to request a specific range of text.
            //m_editcontext.TextRequested(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextTextRequestedEventArgs>(this, &window::EditContext_TextRequested));

            //// The system raises this happening to request the current selection.
            //m_editcontext.SelectionRequested(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs>(this, &window::EditContext_SelectionRequested));

            //// The system raises this happening when it wants the edit control to erase focus.
            //m_editcontext.FocusRemoved(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::Foundation::IInspectable>(this, &window::EditContext_FocusRemoved));

            //// The system raises this happening to update text in the edit control.
            //m_editcontext.TextUpdating(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs>(this, &window::EditContext_TextUpdating));

            //// The system raises this happening to change the selection in the edit control.
            //m_editcontext.SelectionUpdating(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs>(this, &window::EditContext_SelectionUpdating));

            //// The system raises this happening when it wants the edit control
            //// to apply formatting on a r::winrt::Windows::Foundation::Tange of text.
            //m_editcontext.FormatUpdating(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs>(this, &window::EditContext_FormatUpdating));

            //// The system raises this happening to request layout information.
            //// This is used to help choose a position for the IME candidate window.
            //m_editcontext.LayoutRequested(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs>(this, &window::EditContext_LayoutRequested));

            //// The system raises this happening to notify the edit control
            //// that the string composition has started.
            //m_editcontext.CompositionStarted(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs>(this, &window::EditContext_CompositionStarted));

            //// The system raises this happening to notify the edit control
            //// that the string composition is finished.
            //m_editcontext.CompositionCompleted(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs>(this, &window::EditContext_CompositionCompleted));

            //// The system raises this happening when the NotifyFocusLeave operation has
            //// completed. Our sample does not use this happening.
            //m_editcontext.NotifyFocusLeaveCompleted(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::Foundation::IInspectable>(this, &window::EditContext_NotifyFocusLeaveCompleted));

            //// Set our initial UI.
            //UpdateTextUI();

            UpdateFocusUI();

            //window::SetWindow(window);

            //pbuffer = __create_new< directx_base >();

            //pbuffer->system() = system();

            auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

            //pbuffer->Initialize(window, displayinformation.LogicalDpi());

            //pbuffer->initialize(system()->m_papplicationStartup);

            //install_directx_application_message_routing();

            //initialize_directx_application();

            //m_bXXXFirst = true;

            //system()->get_session()->system()->windowing()->m_pwindowFirst = this;

            //system()->get_session()->system()->windowing()->m_bXXXFirst = true;

            //auto pwindowing = windowing();

            //if (!pwindowing->m_bAppInit)
            //{

            //   pwindowing->app_init();

            //}

            //if (!system()->node()->m_bHasNodePostedSystemInitialRequest)
            //{

            //   system()->node()->m_bHasNodePostedSystemInitialRequest = true;

            //   system()->defer_post_initial_request();

            //}

            //auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

            system()->m_dDpi = displayinformation.LogicalDpi();

            displayinformation.DpiChanged(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::Graphics::Display::DisplayInformation, ::winrt::Windows::Foundation::IInspectable >(this, &window::DpiChanged));

            displayinformation.DisplayContentsInvalidated(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::Graphics::Display::DisplayInformation, ::winrt::Windows::Foundation::IInspectable >(this, &window::DisplayContentsInvalidated));


         }


         void window::on_window_size_changed(::winrt::Windows::UI::Core::CoreWindow sender, const ::int_size & size)
         {

            //         auto pbuffer = get_window_graphics();

            //         if (::is_set(pbuffer))
            //         {

            //            auto pbufferitem = pbuffer->get_buffer_item();

            //            pbufferitem->m_size = size;

            //            pbuffer->update_buffer(pbufferitem);

            //         }

            //         //::lparam lparam(size);
            ////
            //         //puserinteraction->send_message(e_message_size, 0, lparam);

            //         puserinteraction->place({ int_point(), size });

            //         //puserinteraction->set_size(size);

            //         puserinteraction->set_need_layout();

            //         puserinteraction->set_need_redraw();

            //         puserinteraction->post_redraw();

         }



         void window::CoreWindow_PointerPressed(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::PointerEventArgs args)
         {
            // See whether the pointer is inside or outside the control.
            //Rect contentRect = GetElementRect(BorderPanel);
            //if (contentRect.Contains(args.CurrentPoint.Position))
            //{
            //   // The user tapped inside the control. Give it focus.
            //   SetInternalFocus();

            //   // Tell XAML that this matter has focus, so we don't have two
            //   // focus elements. That is the extent of our integration with XAML focus.
            //   Focus(FocusState.Programmatic);

            //   // A more complete custom control would move the caret to the
            //   // pointer position. It would also provide some way to select
            //   // text via touch. We do neither in this sample.

            //}
            //else
            //{
            //   // The user tapped outside the control. Remove focus.
            //   RemoveInternalFocus();
            //}
         }

         void window::CoreWindow_WindowActivated(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::WindowActivatedEventArgs args)
         {

            if (args.WindowActivationState() == ::winrt::Windows::UI::Core::CoreWindowActivationState::Deactivated)
            {

               ::output_debug_string("Deactivated");

               //auto puserinteraction = Sess(system()).host();

               //puserinteraction->set_need_layout();

               //puserinteraction->set_need_redraw();

               //puserinteraction->post_redraw();

            }

         }


         void window::CoreWindow_CoreWindowClosed(::winrt::Windows::UI::Core::CoreWindow  sender, ::winrt::Windows::UI::Core::CoreWindowEventArgs  args)
         {

            ::output_debug_string("window closed");

         }


         void window::CoreWindow_KeyDown(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::KeyEventArgs args)
         {

            //// Do not process keyboard input if the custom edit control does not
            //// have focus.
            //if (!m_bInternalFocus)
            //{

            //   return;

            //}

            //// This holds the range we intend to operate on, or which we intend
            //// to become the ___new selection. Start with the current selection.
            //::winrt::Windows::UI::Text::Core::CoreTextRange range = m_selection;

            // For the purpose of this sample, we will support only the left and right
            // arrow keys and the backspace key. A more complete text edit control
            // would also handle keys like Home, End, and Delete, as well as
            // hotkeys like Ctrl+V to paste.
            //
            // Note that this sample does not properly handle surrogate pairs
            // nor does it handle grapheme clusters.

            switch (args.VirtualKey())
            {
               // Backspace
            case ::winrt::Windows::System::VirtualKey::Back:
               // If there is a selection, then delete the selection.
               //if (HasSelection())
               //{
               //   // Set the text in the selection to nothing.
               //   ReplaceText(range, "");
               //}
               //else
               //{
               //   // Delete the character to the left of the caret, if one exists,
               //   // by creating a range that encloses the character to the left
               //   // of the caret, and setting the contents of that range to nothing.
               //   range.StartCaretPosition = maximum(0, range.StartCaretPosition - 1);
               //   ReplaceText(range, "");
               //}
               //m_strNewText.empty();
               break;

               // Left arrow
            case ::winrt::Windows::System::VirtualKey::Left:
               // If the shift key is down, then adjust the int_size of the selection.
               //if ((int)m_windowscorewindow->GetKeyState(VirtualKey::Shift) & (int) CoreVirtualKeyStates::Down)
               //{
               //   // If this is the start of a selection, then remember which edge we are adjusting.
               //   if (!HasSelection())
               //   {
               //      _extendingLeft = true;
               //   }

               //   // Adjust the selection and notify CoreTextEditContext.
               //   AdjustSelectionEndpoint(-1);
               //}
               //else
               //{
               //   // The shift key is not down. If there was a selection, then snap the
               //   // caret at the left edge of the selection.
               //   if (HasSelection())
               //   {
               //      range.EndCaretPosition = range.StartCaretPosition;
               //      SetSelectionAndNotify(range);
               //   }
               //   else
               //   {
               //      // There was no selection. Move the caret left one code unit if possible.
               //      range.StartCaretPosition = maximum(0, range.StartCaretPosition - 1);
               //      range.EndCaretPosition = range.StartCaretPosition;
               //      SetSelectionAndNotify(range);
               //   }
               //}
               //m_strNewText.empty();
               break;

               // Right arrow
            case ::winrt::Windows::System::VirtualKey::Right:
               // If the shift key is down, then adjust the int_size of the selection.
               //if ((int)m_windowscorewindow->GetKeyState(VirtualKey::Shift) & (int) CoreVirtualKeyStates::Down)
               //{
               //   // If this is the start of a selection, then remember which edge we are adjusting.
               //   if (!HasSelection())
               //   {
               //      _extendingLeft = false;
               //   }

               //   // Adjust the selection and notify CoreTextEditContext.
               //   AdjustSelectionEndpoint(+1);
               //}
               //else
               //{
               //   // The shift key is not down. If there was a selection, then snap the
               //   // caret at the right edge of the selection.
               //   if (HasSelection())
               //   {
               //      range.StartCaretPosition = range.EndCaretPosition;
               //      SetSelectionAndNotify(range);
               //   }
               //   else
               //   {
               //      // There was no selection. Move the caret right one code unit if possible.
               //      range.StartCaretPosition = minimum(m_strText.length(), range.StartCaretPosition + 1);
               //      range.EndCaretPosition = range.StartCaretPosition;
               //      SetSelectionAndNotify(range);
               //   }
               //}
               //m_strNewText.empty();
               break;
            }
         }


         void window::OnWindowSizeChanged(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::WindowSizeChangedEventArgs args)
         {

            ::int_size size((LONG)args.Size().Width, (LONG)args.Size().Height);

            on_window_size_changed(sender, size);

         }


         void window::DpiChanged(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable)
         {

            on_dpi_changed(sender, inspectable);



         }

         void window::on_dpi_changed(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable)
         {

            m_rectangleLastWindowRect = m_windowscorewindow.Bounds();


         }

         void window::DisplayContentsInvalidated(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable)
         {

            // Ensure the D3D Device is available for rendering.

            on_display_contents_invalidated(sender, inspectable);

            //   auto pbuffer = __buffer(get_window_graphics());

            //   pbuffer->ValidateDevice();

         }
         void window::on_display_contents_invalidated(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable)
         {

         }


         void window::OnActivated(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView, ::winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs const & args)
         {

            ::cast <windowing> pwindowing = system()->acme_windowing();

            //auto pwindowing = windowing();

            if (pwindowing)
            {

               if (!pwindowing->m_applicationview)
               {

                  pwindowing->m_applicationview = ::winrt::Windows::UI::ViewManagement::ApplicationView::GetForCurrentView();

               }

            }

            if (args != nullptr)
            {

               //preempt(20_s);

               auto kind = args.Kind();

               if (args.Kind() == ::winrt::Windows::ApplicationModel::Activation::ActivationKind::Launch)
               {

                  auto launchActivatedEventArgs = args.as<::winrt::Windows::ApplicationModel::Activation::LaunchActivatedEventArgs>();

                  string str = launchActivatedEventArgs.Arguments().begin();

                  if (str.has_character())
                  {

                     if (system()->_handle_uri(str))
                     {

                        return;

                     }

                  }

               }
               else if (args.Kind() == ::winrt::Windows::ApplicationModel::Activation::ActivationKind::Protocol)
               {

                  auto protocolActivatedEventArgs = args.as<::winrt::Windows::ApplicationModel::Activation::ProtocolActivatedEventArgs>();

                  string str = protocolActivatedEventArgs.Uri().AbsoluteUri().begin();

                  application()->payload("activation") = str;

                  system()->post([this, str]()
                     {

                        if (system()->_handle_uri(str))
                        {

                           return;

                        }

                  });

                  //string strServer = system()->url()->get_server(str);

                  //if (strServer == "send")
                  //{

                  //   string strMessage = system()->url()->get_param(str, "message");

                  //   if (strMessage.has_character())
                  //   {

                  //      system()->application()->add_activation_message(strMessage);

                  //   }

                  //}

                  //system()->add_create(pcreate);

                  //auto papp = system()->m_papplicationStartup;

                  //if (papp == nullptr)
                  //{

                  //   papp = session()->m_papplicationCurrent;

                  //}

                  //system()->post_object(e_message_system, e_system_message_create, pcreate);

               }

            }

            m_windowscorewindow.Activate();

         }


         void window::OnSuspending(::winrt::Windows::Foundation::IInspectable const & sender, ::winrt::Windows::ApplicationModel::SuspendingEventArgs const & args)
         {

         }


         void window::OnResuming(::winrt::Windows::Foundation::IInspectable const & sender, ::winrt::Windows::Foundation::IInspectable const & args)
         {

         }

         void window::OnWindowVisibilityChanged(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs args)
         {

            on_window_visibility_changed(sender, args);

         }


         void window::on_window_visibility_changed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs args)
         {


         }


         void window::OnPointerMoved(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::PointerEventArgs args)
         {

            on_pointer_moved(sender, args);

         }


         void window::on_pointer_moved(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::PointerEventArgs args)
         {

            auto puserinteraction = user_interaction();

            if (puserinteraction == nullptr)
            {

               return;

            }

            //if (puserinteraction->m_pinteractionimpl == nullptr)
            //{

            //   return;

            //}

            //::pointer<::message::message>pusermessage;

            ::winrt::Windows::UI::Input::PointerPoint pointerPoint = args.CurrentPoint();

            m_iMouse = pointerPoint.PointerId();

            auto pmouse = __create_new< ::user::mouse >();

            //pusermessage = pmouse;

            //pmouse->m_pwindow = this;

            //pmouse->m_oswindow = this;

            pmouse->m_pointHost.x() = (int)pointerPoint.Position().X;

            pmouse->m_pointHost.y() = (int)pointerPoint.Position().Y;

            pmouse->m_pointAbsolute.x() = (int)pointerPoint.RawPosition().X;

            pmouse->m_pointAbsolute.y() = (int)pointerPoint.RawPosition().Y;

            pmouse->m_atom = e_message_mouse_move;
            //pmouse->m_playeredUserPrimitive  = session()->m_puserinteractionHost;

            m_pointLastCursor = pointerPoint.RawPosition();

            //set_cursor_position({ (int) m_pointLastCursor.X, (int) m_pointLastCursor.Y});

            m_pointCursor2.x() = (int)pointerPoint.RawPosition().X;

            m_pointCursor2.y() = (int)pointerPoint.RawPosition().Y;

            //puserinteraction->message_handler(pusermessage);

            ::pointer<::micro::elemental> pelemental = m_pacmeuserinteraction;

            if (pelemental)
            {

               pelemental->fore_on_mouse_move(pmouse);

               if (pmouse->m_bRet)
               {

                  return;

               }

               pelemental->back_on_mouse_move(pmouse);

            }

            m_timeLastMouseMove = ::time::now();

         }


         void window::OnPointerPressed(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::PointerEventArgs args)
         {

            on_pointer_pressed(sender, args);

         }


         void window::on_pointer_pressed(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::PointerEventArgs args)
         {

            if (system() == nullptr)
            {

               return;

            }

            auto puserinteraction = user_interaction();

            if (puserinteraction == nullptr)
            {

               return;

            }

            //if (puserinteraction->m_pinteractionimpl == nullptr)
            //{

            //   return;

            //}

            ::winrt::Windows::UI::Input::PointerPoint pointerPoint = args.CurrentPoint();

            m_iMouse = pointerPoint.PointerId();

            auto pmouse = __create_new< ::user::mouse >();

            //pmouse->m_pwindow = this;

            //pmouse->m_oswindow = this;

            pmouse->m_pointHost.x() = (int)pointerPoint.Position().X;

            pmouse->m_pointHost.y() = (int)pointerPoint.Position().Y;

            pmouse->m_pointAbsolute.x() = (int)pointerPoint.RawPosition().X;

            pmouse->m_pointAbsolute.y() = (int)pointerPoint.RawPosition().Y;

            int button = -1;

            if (args.CurrentPoint().Properties().IsLeftButtonPressed() && !m_bLeftButton)
            {

               button = 1;

               pmouse->m_atom = e_message_left_button_down;

               m_bLeftButton = true;
               m_bMiddleButton = false;
               m_bRightButton = false;

            }
            else if (args.CurrentPoint().Properties().IsRightButtonPressed() && !m_bRightButton)
            {

               button = 3;
               pmouse->m_atom = e_message_right_button_down;

               m_bLeftButton = false;
               m_bMiddleButton = false;
               m_bRightButton = true;

            }
            else if (args.CurrentPoint().Properties().IsMiddleButtonPressed() && !m_bMiddleButton)
            {

               button = 2;
               pmouse->m_atom = e_message_middle_button_down;

               m_bLeftButton = false;
               m_bMiddleButton = true;
               m_bRightButton = false;

            }

            m_pointLastCursor = pointerPoint.RawPosition();

            m_pointCursor2.x() = (int)pointerPoint.RawPosition().X;

            m_pointCursor2.y() = (int)pointerPoint.RawPosition().Y;

            //puserinteraction->message_handler(pmouse);

            ::pointer<::micro::elemental> pelemental = m_pacmeuserinteraction;

            if (pelemental)
            {

               if (button == 1)
               {

                  information() << "LeftButtonDown";

                  pelemental->fore_on_left_button_down(pmouse);

                  if (pmouse->m_bRet)
                  {

                     return;

                  }

                  pelemental->back_on_left_button_down(pmouse);

               }
               else if (button == 3)
               {

                  pelemental->fore_on_right_button_down(pmouse);

                  if (pmouse->m_bRet)
                  {

                     return;

                  }

                  pelemental->back_on_right_button_down(pmouse);

               }

            }

         }


         void window::OnPointerReleased(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::PointerEventArgs args)
         {

            on_pointer_released(sender, args);

         }


         void window::on_pointer_released(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args)
         {

            if (system() == nullptr)
            {

               return;

            }

            ::winrt::Windows::UI::Input::PointerPoint pointerPoint = args.CurrentPoint();

            m_iMouse = pointerPoint.PointerId();

            auto puserinteraction = user_interaction();

            if (puserinteraction == nullptr)
            {

               return;

            }

            //if (puserinteraction->m_pinteractionimpl == nullptr)
            //{

            //   return;

            //}

            int button = -1;

            auto pmouse = __create_new< ::user::mouse >();

            //pmouse->m_pwindow = this;

            //pmouse->m_oswindow = this;

            pmouse->m_pointHost.x() = (int)pointerPoint.Position().X;

            pmouse->m_pointHost.y() = (int)pointerPoint.Position().Y;

            pmouse->m_pointAbsolute.x() = (int)pointerPoint.RawPosition().X;

            pmouse->m_pointAbsolute.y() = (int)pointerPoint.RawPosition().Y;

            if (m_bLeftButton && !args.CurrentPoint().Properties().IsLeftButtonPressed())
            {


               button = 1;

               pmouse->m_atom = e_message_left_button_up;

               m_bLeftButton = false;

            }
            else if (m_bRightButton && !args.CurrentPoint().Properties().IsRightButtonPressed())
            {

               button = 3;

               pmouse->m_atom = e_message_right_button_up;

               m_bRightButton = false;

            }
            else if (m_bMiddleButton && !args.CurrentPoint().Properties().IsMiddleButtonPressed())
            {

               button = 2;

               pmouse->m_atom = e_message_middle_button_up;

               m_bMiddleButton = false;

            }

            m_pointLastCursor = pointerPoint.RawPosition();

            m_pointCursor2.x() = (int)pointerPoint.RawPosition().X;

            m_pointCursor2.y() = (int)pointerPoint.RawPosition().Y;

            //puserinteraction->message_handler(pmouse);


            ::pointer<::micro::elemental> pelemental = m_pacmeuserinteraction;

            if (pelemental)
            {

               if (button == 1)
               {

                  information() << "LeftButtonUp";

                  pelemental->fore_on_left_button_up(pmouse);

                  if (pmouse->m_bRet)
                  {

                     return;

                  }

                  pelemental->back_on_left_button_up(pmouse);

               }
               else if (button == 3)
               {

                  pelemental->fore_on_right_button_up(pmouse);

                  if (pmouse->m_bRet)
                  {

                     return;

                  }

                  pelemental->back_on_right_button_up(pmouse);
               }

            }

         }

         void window::OnCharacterReceived(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs args)
         {

            on_character_received(sender, args);

         }

         void window::on_character_received(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs args)
         {


            //if (m_bInternalFocus)
            //{

            //   return;

            //}

            auto puserinteraction = acme_user_interaction();

            if (puserinteraction == nullptr)
            {

               return;

            }

            //if (puserinteraction->m_pinteractionimpl == nullptr)
            //{

            //   return;

            //}

            ::wd32_character wd32ch = args.KeyCode();

            if (wd32ch < 32)
            {

               // It is control character.

               return;

            }

            auto pkey = __create_new< ::user::key >();
            //pkey->m_pwindow = this;

            //pkey->m_oswindow = this;

            pkey->m_atom = e_message_char;

            pkey->m_ekey = ::user::e_key_refer_to_text_member;

            char szUtf8[32];

            wd32_to_ansi(szUtf8, &wd32ch, 1);

            pkey->m_strText = szUtf8;

            ::pointer<::micro::elemental> pelemental = m_pacmeuserinteraction;

            pelemental->on_character(pkey);

            //puserinteraction->message_handler(pkey);

         }


         void window::OnKeyDown(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::KeyEventArgs args)
         {

            on_key_down(sender, args);

         }


         void window::on_key_down(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::KeyEventArgs args)
         {
            if (args.VirtualKey() == ::winrt::Windows::System::VirtualKey::Shift)
            {

               m_bFontopusShift = true;

            }

            if (system() == nullptr)
            {

               return;

            }

            auto puserinteraction = acme_user_interaction();

            if (puserinteraction == nullptr)
            {

               return;

            }

            //if (puserinteraction->m_pinteractionimpl == nullptr)
              // return;

            auto pkey = __create_new< ::user::key >();

            //bool bTextFocus = puserinteraction->get_keyboard_focus() != nullptr;

            bool bSpecialKey = false;

            ::user::enum_key ekey = ::universal_windows::virtualkey_to_userkey(args.VirtualKey(), bSpecialKey);

            //if (bSpecialKey s || session()->is_key_pressed(::user::e_key_control)
            //   || session()->is_key_pressed(::user::e_key_alt))
            //{
            //pkey->m_pwindow = this;

            //pkey->m_oswindow = this;

            pkey->m_atom = e_message_key_down;
            //pkey->m_playeredUserPrimitive       = session()->m_puserinteractionHost;
            pkey->m_nChar = ::universal_windows::virtualkey_to_char(args.VirtualKey());
            pkey->m_ekey = ekey;
            pkey->m_wparam = pkey->m_nChar;
            pkey->m_nFlags = (unsigned int)::universal_windows::virtualkey_to_code(args.VirtualKey());
            pkey->m_lparam = pkey->m_nFlags << 16;
            //pkey->m_strText            = m_strNewText;
            //if (pkey->m_strText.has_character())
            //{
              // pkey->m_ekey = ::user::e_key_refer_to_text_member;
            //}
      //      pkey->m_key = args;

            ::pointer<::micro::elemental> pelemental = m_pacmeuserinteraction;

            pelemental->on_key_down(pkey);

            //   ;;
            //}

         }

         void window::OnKeyUp(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::KeyEventArgs args)
         {

            on_key_up(sender, args);

         }


         void window::on_key_up(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args)
         {

            if (system() == nullptr)
               return;

            auto puserinteraction = acme_user_interaction();

            if (puserinteraction == nullptr)
               return;

            //if (puserinteraction->m_pinteractionimpl == nullptr)
            //   return;

            //::pointer<::message::message>pusermessage;

            auto pkey = __create_new< ::user::key >();

            // pusermessage = pkey;


            //if (args.VirtualKey() == ::winrt::Windows::System::VirtualKey::Shift)
            //{

            //   m_bFontopusShift = false;

            //}

            bool bTextFocus = puserinteraction->get_keyboard_focus() != nullptr;

            bool bSpecialKey = false;

            ::user::enum_key ekey = ::universal_windows::virtualkey_to_userkey(args.VirtualKey(), bSpecialKey);

            //if (bSpecialKey || !bTextFocus)
            //{
            //pkey->m_pwindow = this;

            //pkey->m_oswindow = this;

            pkey->m_atom = e_message_key_up;
            //pkey->m_playeredUserPrimitive = session()->m_puserinteractionHost;
            pkey->m_nChar = ::universal_windows::virtualkey_to_char(args.VirtualKey());
            pkey->m_ekey = ekey;
            pkey->m_wparam = pkey->m_nChar;


            //      pkey->m_key = args;

                  //if (system()->m_psimpleui != nullptr && system()->m_psimpleui->is_window_visible())
                  //{
                  //   string str;
                  //   str = (char)pkey->m_nChar;
                  //   if (m_bFontopusShift)
                  //   {
                  //      if (pkey->m_nChar == 0xbe)
                  //      {
                  //         str = ">";
                  //      }
                  //      else if (str == "2")
                  //      {
                  //         str = "@";
                  //      }
                  //      else
                  //      {
                  //         str.make_upper();
                  //      }
                  //   }
                  //   else
                  //   {
                  //      if (pkey->m_nChar == 0xbe)
                  //      {
                  //         str = ".";
                  //      }
                  //   }
                  //   system()->m_psimpleui->on_char(virtualkey_to_userkey(args.VirtualKey), str);
                  //}
                  //else
                  //{

            ::pointer<::micro::elemental> pelemental = m_pacmeuserinteraction;
            pelemental->on_key_up(pkey);
            //}

         //}

         }

         void window::_main_post(const ::procedure & procedure)
         {

            auto window = m_windowscorewindow;

            if (!window)
            {

               system()->acme_windowing()->_main_post(procedure);

               return;

            }



            auto dispatcher = window.Dispatcher();

            dispatcher.RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal,
               ::winrt::Windows::UI::Core::DispatchedHandler([procedure]()
                  {

                     procedure();

                  }));

         }




      } // namespace windowing


   } // namespace acme


} // namespace universal_windows



