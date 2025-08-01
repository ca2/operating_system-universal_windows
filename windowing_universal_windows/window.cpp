// created by Camilo 2021-01-31 04:56 BRT <3CamiloSasukeThomasBorregaardSoerensen
#include "framework.h"
#include "window.h"
#include "windowing.h"
#include "buffer.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/constant/timer.h"
#include "acme/constant/user_key.h"
#include "acme/exception/interface_only.h"
#include "acme/operating_system/universal_windows/geometry2d.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/node.h"
//#include "aura_universal_windows/interaction_impl.h"
#include "aura/user/user/interaction_graphics_thread.h"
#include "aura/user/user/system.h"
#include "aura/message/user.h"
#include "aura/graphics/draw2d/graphics.h"
//#include "universal_windows/framework_impact_source.h"
//#include "universal_windows/framework_impact.h"
#include "direct2d/direct2d.h"
#include "aura/platform/system.h"
#include "cursor.h"
#include "windowing.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include "acme_universal_windows/_winrt_system.h"
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.ApplicationModel.Activation.h>



#undef ALOG_CONTEXT
#define ALOG_CONTEXT ::trace_object(::trace_category_windowing)
//wstring CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS windows_get_user_interaction_window_class(::user::interaction * puserinteraction);

//extern CLASS_DECL_ACME const unichar gen_Wnd[];           // simple child windows/controls
//extern CLASS_DECL_ACME const unichar gen_WndControlBar[]; // controls with gray backgrounds
//extern CLASS_DECL_ACME const unichar gen_WndMDIFrame[];
//extern CLASS_DECL_ACME const unichar gen_WndFrameOrView[];
//extern CLASS_DECL_ACME const unichar gen_WndOleControl[];



//CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS WNDPROC windows_user_interaction_impl_get_window_procedure();


//bool has_autohide_appbar(unsigned int edge, const int_rectangle & mon);


//CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS bool __is_combo_box_control(HWND hwnd, unsigned int nStyle);
//CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS bool __check_center_dialog(const ::string & pszResource);
//
//CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS bool __compare_class_name(HWND hwnd, const ::string & pszClassName);
//
//CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS bool hook_window_create(::windowing_universal_windows::window * pwindow);
//CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS bool unhook_window_create();
//CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS void reset_message_cache();


namespace windowing_universal_windows
{


   



   window::window() //:
      //m_frameworkview{ {::winrt::make<framework_impact >(this)} }
   {

      //m_straActivationMessage.add("app-core-flag://send/?message=");
      //m_bXXXFirst = true;
      //
      m_bInternalFocus = false;
      m_bExtendingLeft = false;
      m_bTextCompositionActive = false;
      //m_bMainWindow = false;
      //m_pWindow4 = this;

      //set_layer(LAYERED_IMPL, this);
      //m_plongmap  = ___new iptr_to_iptr;

//      m_iXic = 0;
//
//      m_xic = nullptr;
//
//      for (auto &i : m_iaNetWmState)
//      {
//
//         i = -1;
//
//      }
//
//      m_hcursorLast = 0;
//
//      m_htask = 0;
//
//      m_windowscorewindow = None;

      m_bTrackMouseLeave = false;

      //m_pwindow = nullptr;

      m_bMessageOnlyWindow = false;

      //      m_osdisplay = nullptr;
      //
      //      zero(m_visual);
      //
      //      m_iDepth = -1;
      //
      //      m_iScreen = -1;
      //
      //      m_colormap = None;
      //
      //      m_iXic = 0;

   }


   window::~window()
   {

      //::acme::del(m_plongmap);

   }


   //void window::assert_ok() const
   //{

   //   //::windowing_universal_windows::window::assert_ok();

   //   //if (((::windowing_universal_windows::window *)this)->get_hwnd() == nullptr)
   //   //   return;     // null (unattached) windows are valid

   //   //// check for special wnd??? values
   //   //ASSERT(HWND_TOP == nullptr);       // same as desktop
   //   //if (((::windowing_universal_windows::window *)this)->get_hwnd() == HWND_BOTTOM)
   //   //{
   //   //}
   //   //else if (((::windowing_universal_windows::window *)this)->get_hwnd() == HWND_TOPMOST)
   //   //{
   //   //}
   //   //else if (((::windowing_universal_windows::window *)this)->get_hwnd() == HWND_NOTOPMOST)
   //   //{
   //   //}
   //   //else
   //   //{
   //   //   // should be a normal window
   //   //   ASSERT(::IsWindow(((::windowing_universal_windows::window *)this)->get_hwnd()));

   //   //}
   //}

   //
   //void window::dump(dump_context & dumpcontext) const
   //{

   //   //::windowing_universal_windows::window::dump(dumpcontext);

   //   //dumpcontext << "\nm_oswindow_ = " << ((::windowing_universal_windows::window *)this)->get_hwnd();

   //   //if (((::windowing_universal_windows::window *)this)->get_hwnd() == nullptr || ((::windowing_universal_windows::window *)this)->get_hwnd() == HWND_BOTTOM ||
   //   //   ((::windowing_universal_windows::window *)this)->get_hwnd() == HWND_TOPMOST || ((::windowing_universal_windows::window *)this)->get_hwnd() == HWND_NOTOPMOST)
   //   //{
   //   //   // not a normal window - nothing more to dump
   //   //   return;
   //   //}

   //   //if (!::IsWindow(((::windowing_universal_windows::window *)this)->get_hwnd()))
   //   //{
   //   //   // not a valid window
   //   //   dumpcontext << " (illegal hwnd)";
   //   //   return; // don't do anything more
   //   //}

   //   ////auto puserinteraction = psystem->ui_from_handle(((::windowing_universal_windows::window *)this)->get_hwnd());
   //   ////if (puserinteraction->m_pinteractionimpl != (::user::window *)this)
   //   ////   dumpcontext << " (Detached or temporary window)";
   //   ////else
   //   ////   dumpcontext << " (permanent window)";

   //   ////wchar_t szBuf[64];
   //   ////::GetClassNameW(((::windowing_universal_windows::window *)this)->get_hwnd(), szBuf, _countof(szBuf));
   //   ////dumpcontext << "\nclass name = \"" << szBuf << "\"";

   //   ////::int_rectangle rectangle;
   //   ////((::windowing_universal_windows::window *)this)->puserinteraction->layout().window().screen_rect(&rectangle);
   //   ////dumpcontext << "\nrect = " << int_rectangle;
   //   ////dumpcontext << "\nparent ::user::window * = " << ::hex::lower_from((::iptr)((::windowing_universal_windows::window *)this)->get_parent());

   //   ////dumpcontext << "\nstyle = " << (uptr)::GetWindowLong(((::windowing_universal_windows::window *)this)->get_hwnd(), GWL_STYLE);
   //   ////if (::GetWindowLong(((::windowing_universal_windows::window *)this)->get_hwnd(), GWL_STYLE) & WS_CHILD)
   //   ////   dumpcontext << "\nid = " << __get_dialog_control_id(((::windowing_universal_windows::window *)this)->get_hwnd());

   //   ////dumpcontext << "\n";

   //}


   //void window::install_system_interaction_message_handling(::user::interaction * puserinteraction)
   //{

   //   auto pchannel = puserinteraction->m_pinteractionimpl;

   //   MESSAGE_LINK(WM_SETTINGCHANGE, pchannel, this, &window::_001OnMessage);
   //   MESSAGE_LINK(WM_FONTCHANGE, pchannel, this, &window::_001OnMessage);

   //}

   
   void window::install_message_routing(channel * pchannel)
   {

      ::windowing::window::install_message_routing(pchannel);

      MESSAGE_LINK(e_message_create, pchannel, this, &window::on_message_create);

      auto puserinteraction = user_interaction();

      //auto pimpl = m_pwindow.m_p;

      if (!puserinteraction->m_bMessageWindow)
      {

         //MESSAGE_LINK(e_message_redraw, pchannel, pimpl, &::windowing::window::_001OnRedraw);
         //MESSAGE_LINK(e_message_apply_visual, pchannel, pimpl, &::windowing::window::_001OnApplyVisual);


         //#ifndef LINUX
         //MESSAGE_LINK(e_message_move, pchannel, this, &window::on_message_move);
         MESSAGE_LINK(e_message_size, pchannel, this, &window::on_message_size);
         //#endif


         //MESSAGE_LINK(e_message_show_window, pchannel, this, &window::on_message_show_window);
         //MESSAGE_LINK(e_message_kill_focus, pchannel, this, &window::on_message_kill_focus);
         //MESSAGE_LINK(e_message_set_focus, pchannel, this, &window::on_message_set_focus);
         //MESSAGE_LINK(e_message_set_cursor, pchannel, this, &window::on_message_set_cursor);

      }

      MESSAGE_LINK(WM_ACTIVATE, pchannel, this, &window::_001OnActivate);
      MESSAGE_LINK(WM_DWMNCRENDERINGCHANGED, pchannel, this, &window::_001OnDwmNcRenderingChanged);

      ::windowing::window::install_message_routing(pchannel);


      MESSAGE_LINK(e_message_destroy, pchannel, this, &window::on_message_destroy);
      MESSAGE_LINK(WM_GETICON, pchannel, this, &window::on_message_get_icon);

      //MESSAGE_LINK(e_message_create, pchannel, pimpl, &::windowing::window::_001OnPrioCreate);

   }


   //void window::create_window(::windowing::window * pimpl)
   void window::create_window()
   {

      ::windowing::window::create_window();

   }


   bool window::get_rect_normal(::int_rectangle * prectangle)
   {

      auto bounds = m_windowscorewindow.Bounds();

      prectangle->left() = (int) bounds.X;
      prectangle->top() = (int)bounds.Y;
      prectangle->right() = (int)(prectangle->left()+ bounds.Width);
      prectangle->bottom() = (int) (prectangle->top() + bounds.Height);

      return true;

   }


   bool window::has_capture() const
   {

      //return ::GetCapture() == get_hwnd();

      return false;

   }


   bool window::has_keyboard_focus() const
   {

      //return ::GetFocus() == get_hwnd();
      return false;

   }


   bool window::is_full_screen() 
   {

      auto pwindowing = windowing();

      if (!pwindowing)
      {

         return false;

      }

      auto applicationview = pwindowing->m_applicationview;

      if (!applicationview)
      {

         return false;

      }

      return applicationview.IsFullScreenMode();

   }

   ::oswindow window::oswindow() const
   {

      return (::windowing::window *) this;

   }
   ::oswindow window::oswindow()
   {

      return this;

   }

   class windowing * window::windowing() const
   {
      ::cast < ::windowing_universal_windows::windowing > pwindowing = system()->windowing();

      if (!pwindowing)
      {
         return nullptr;

      }

      return pwindowing;
   }


   void window::_001OnMessage(::message::message * pmessage)
   {

      if (pmessage != nullptr)
      {

         wparam wparam = pmessage->m_wparam;

         lparam lparam = pmessage->m_lparam;

         string strLparamString;

         if (pmessage->m_emessage == WM_SETTINGCHANGE && wparam == 0)
         {

            strLparamString = (const WCHAR *) (LPARAM(lparam));

         }

         if (pmessage->m_emessage == WM_FONTCHANGE)
         {

            auto psystem = system();

            ::cast < ::manager > pmanager = psystem;

            if (pmanager)
            {
               
               pmanager->send_signal(id_operating_system_font_list_change);

            }

            //psystem->handle_subject(ptopic);

            //fork([this]()
              // {

                 // psession->call(e_routine_font_change);

               //});

         //}
         }
         else if (pmessage->m_emessage == e_message_display_change ||
            (pmessage->m_emessage == WM_SETTINGCHANGE &&
               (pmessage->m_wparam == SPI_SETWORKAREA)))
         {

            output_debug_string("test");

            //throw_todo();

            //psystem->enum_display_monitors();

            //::pointer<::user::interaction>puserinteraction;

            //while(psystem->get_frame(puserinteraction))
            //{

            //   try
            //   {

            //      puserinteraction->post_message(e_message_display_change);

            //   }
            //   catch(...)
            //   {
            //   }

            //}


         }

      }

   }



   //void window::set_wm_class(const ::string & psz)
   //{

   //   //      m_strWMClass = psz;
   //   //
   //   //      xdisplay d(display());
   //   //
   //   //      XClassHint classHint;
   //   //
   //   //      classHint.res_name = m_strWMClass;
   //   //
   //   //      classHint.res_class = m_strWMClass;
   //   //
   //   //      XSetClassHint(display(), window(), &classHint);

   //}


   //int window::map_window()
   //{

   //   //      int i = 0;
   //   //
   //   //      {
   //   //
   //   //         windowing_output_debug_string("\nwindow::map_window");
   //   //
   //   //         xdisplay d(display());
   //   //
   //   //         i = XMapWindow(display(), window());
   //   //
   //   //      }
   //   //
   //   //#ifndef RASPBIAN
   //   //
   //   //      if (g_psncontext != nullptr)
   //   //      {
   //   //
   //   //         sn_launchee_context_complete(g_psncontext);
   //   //
   //   //         g_psncontext = nullptr;
   //   //
   //   //      }
   //   //
   //   //#endif // RASPBIAN
   //   //
   //   //      windowing_output_debug_string("\nwindow::map_window END");

   //   return 0;

   //}


   //int window::unmap_window(bool bWithdraw)
   //{

   //   //windowing_output_debug_string("\nwindow::unmap_window");

   //   //xdisplay d(display());

   //   //int i;

   //   //if (bWithdraw)
   //   //{

   //   //   i = XWithdrawWindow(display(), window(), m_iScreen);

   //   //}
   //   //else
   //   //{

   //   //   i = XUnmapWindow(display(), window());

   //   //}

   //   //windowing_output_debug_string("\nwindow::unmap_window END");

   //   //return i;

   //}


   //oswindow_dataptra * window::s_pdataptra = nullptr;


   //::mutex * window::s_pmutex = nullptr;


   //int oswindow_find_message_only_window(::user::window * pimpl)
   //{

   //   if (pimpl == nullptr)
   //      return -1;

   //   single_lock slOsWindow(window::s_pmutex, true);

   //   for (int i = 0; i < ::window::s_pdataptra->get_count(); i++)
   //   {

   //      if (::window::s_pdataptra->element_at(i)->m_bMessageOnlyWindow
   //         && ::window::s_pdataptra->element_at(i)->m_pwindow == pimpl)
   //      {

   //         return i;

   //      }

   //   }

   //   return -1;

   //}

   //int oswindow_find(Display * pdisplay, Window window)
   //{

   //   single_lock slOsWindow(::window::s_pmutex, true);

   //   for (int i = 0; i < ::window::s_pdataptra->get_count(); i++)
   //   {
   //      if (!::window::s_pdataptra->element_at(i)->m_bMessageOnlyWindow
   //         && ::window::s_pdataptra->element_at(i)->m_osdisplay->display() == pdisplay
   //         && ::window::s_pdataptra->element_at(i)->m_windowscorewindow == window)
   //      {
   //         return i;
   //      }
   //   }

   //   return -1;

   //}

   //int oswindow_find(Window window)
   //{

   //   single_lock slOsWindow(::window::s_pmutex, true);

   //   for (int i = 0; i < ::window::s_pdataptra->get_count(); i++)
   //   {
   //      if (!::window::s_pdataptra->element_at(i)->m_bMessageOnlyWindow
   //         && ::window::s_pdataptra->element_at(i)->m_windowscorewindow == window)
   //      {
   //         return i;
   //      }
   //   }

   //   return -1;

   //}


   //window * oswindow_get_message_only_window(::user::window * puserinteraction)
   //{

   //   if (puserinteraction == nullptr)
   //   {

   //      return nullptr;

   //   }

   //   single_lock slOsWindow(::window::s_pmutex, true);

   //   iptr iFind = oswindow_find_message_only_window(puserinteraction);

   //   if (iFind >= 0)
   //   {

   //      return ::window::s_pdataptra->element_at(iFind);

   //   }

   //   ::window * pdata = ___new window;

   //   pdata->m_bMessageOnlyWindow = true;
   //   pdata->m_windowscorewindow = None;
   //   pdata->m_pwindow = puserinteraction;
   //   pdata->m_osdisplay = nullptr;
   //   pdata->m_parent = 0;
   //   pdata->m_pmq = puserinteraction->puserinteraction->m_pthreadUserInteraction->aaa_get_message_queue();

   //   ::window::s_pdataptra->add(pdata);

   //   return pdata;

   //}


   //window * oswindow_defer_get(Display * pdisplay, Window window)
   //{

   //   single_lock slOsWindow(::window::s_pmutex, true);

   //   iptr iFind = oswindow_find(pdisplay, window);

   //   if (iFind < 0)
   //   {

   //      return nullptr;

   //   }

   //   return ::window::s_pdataptra->element_at(iFind);

   //}


   //window *
   //   oswindow_get(Display * pdisplay, Window window, Visual * pvisual, int iDepth, int iScreen, Colormap colormap)
   //{

   //   single_lock slOsWindow(::window::s_pmutex, true);

   //   iptr iFind = oswindow_find(pdisplay, window);

   //   if (iFind >= 0)
   //   {

   //      return ::window::s_pdataptra->element_at(iFind);

   //   }

   //   ::window * pdata = ___new ::window;

   //   pdata->m_bMessageOnlyWindow = false;
   //   pdata->m_osdisplay = osdisplay_get(pdisplay);
   //   pdata->m_windowscorewindow = window;

   //   if (pvisual != nullptr)
   //   {

   //      pdata->m_visual = *pvisual;

   //   }

   //   pdata->m_iDepth = iDepth;
   //   pdata->m_iScreen = iScreen;
   //   pdata->m_colormap = colormap;
   //   pdata->m_parent = 0;

   //   ::window::s_pdataptra->add(pdata);

   //   return pdata;

   //}


   //void x11_on_start_session()
   //{

   //   Display * dpy = x11_get_display();
   //
   //   g_oswindowDesktop = oswindow_get(dpy, DefaultRootWindow(dpy));
   //
   //   g_oswindowDesktop->m_pwindow = nullptr;
   //
   //   XSelectInput(g_oswindowDesktop->display(), g_oswindowDesktop->window(), StructureNotifyMask);
   //
   //}


   /*window * oswindow_get(Window window)
   {

      single_lock slOsWindow(::window::s_pmutex, true);

      iptr iFind = oswindow_find(window);

      if (iFind < 0)
      {

         return nullptr;

      }

      return ::window::s_pdataptra->element_at(iFind);

   }*/


   //bool window::bamf_set_icon()
   //{

   //   ::linux::desktop_file file;

   //   file.bamf_set_icon(this);

   //   return true;

   //}


   //int window::x_change_property(Atom property, Atom type, int format, int mode, const unsigned char * data,
   //   int nelements)
   //{

   //   return XChangeProperty(display(), window(), property, type, format, mode, data, nelements);

   //}


   //Atom window::intern_atom(const ::string & pszAtomName, bool bCreate)
   //{

   //   return m_osdisplay->intern_atom(pszAtomName, bCreate);

   //}


   //Atom window::intern_atom(e_net_wm_state estate, bool bCreate)
   //{

   //   return m_osdisplay->intern_atom(estate, bCreate);

   //}

//
//   bool window::set_icon(::image::image * pimage)
//   {
//
//      // http://stackoverflow.com/questions/10699927/xlib-argb-window-icon
//      // http://stackoverflow.com/users/432509/ideasman42
//
//#if 0
//
//      unsigned int buffer[] =
//      {
//         16, 16,
//         4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 338034905, 3657433343, 0, 184483840, 234881279, 3053453567, 3221225727, 1879048447, 0, 0, 0, 0, 0, 0, 0, 1224737023, 3305111807, 3875537151,0, 0, 2063597823, 1291845887, 0, 67109119, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 50266112, 3422552319, 0, 0, 3070230783, 2063597823, 2986344703, 771752191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3422552319, 0, 0, 3372220671, 1509949695, 704643327, 3355443455, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 3422552319, 0, 134152192, 3187671295, 251658495, 0, 3439329535, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3422552319, 0, 0, 2332033279, 1342177535, 167772415, 3338666239, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 3422552319, 0, 0, 436207871, 3322085628, 3456106751, 1375731967, 4278255360, 4026597120, 3758161664, 3489726208, 3204513536, 2952855296, 2684419840, 2399207168, 2130771712, 1845559040, 1593900800, 1308688128, 1040252672, 755040000, 486604544, 234946304, 4278255360, 4043374336, 3774938880, 3506503424, 3221290752, 2952855296, 2667642624, 2399207168, 2130771712, 1862336256, 1627453957, 1359017481, 1073805064, 788591627, 503379721, 218169088, 4278255360, 4043374336, 3758161664, 3506503424, 3221290752, 2952855296, 2684419840, 2415984384, 2130771712, 1862336256, 1577123584, 1308688128, 1040252672, 755040000, 486604544, 218169088, 4278190335, 4026532095, 3758096639, 3489661183, 3221225727, 2952790271, 2667577599, 2415919359, 2130706687, 1862271231, 1593835775, 1325400319, 1056964863, 771752191, 520093951, 234881279, 4278190335, 4026532095, 3758096639, 3489661183, 3221225727, 2952790271, 2667577599, 2415919359, 2130706687, 1862271231, 1593835775, 1325400319, 1056964863, 771752191, 503316735, 234881279, 4278190335, 4026532095, 3758096639, 3489661183, 3221225727, 2952790271, 2684354815, 2399142143, 2130706687, 1862271231, 1593835775, 1325400319, 1040187647, 771752191, 520093951, 234881279, 4294901760, 4043243520, 3774808064, 3506372608, 3221159936, 2952724480, 2684289024, 2399076352, 2147418112, 1862205440, 1593769984, 1308557312, 1040121856, 771686400, 503250944, 234815488, 4294901760, 4060020736, 3758030848, 3506372608, 3221159936, 2952724480, 2684289024, 2415853568, 2130640896, 1862205440, 1593769984, 1308557312, 1040121856, 771686400, 503250944, 234815488, 4294901760, 4043243520, 3774808064, 3489595392, 3237937152, 2952724480, 2684289024, 2415853568, 2147418112, 1862205440, 1593769984, 1325334528, 1056899072, 788463616, 503250944, 234815488,
//         32, 32,
//         4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 0, 0, 0, 0, 0, 0, 0, 0, 268369920, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 1509949695, 3120562431, 4009754879, 4194304255, 3690987775, 2130706687, 83886335, 0, 50331903, 1694499071, 3170894079, 3992977663, 4211081471, 3657433343, 1879048447, 16777471, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3087007999, 2281701631, 1191182591, 1040187647, 2030043391, 4127195391, 2566914303, 0, 16777471, 3254780159, 2181038335, 1191182591, 973078783, 2030043391,4177527039, 2130706687, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 0, 0, 0, 0, 2214592767, 4093640959, 0, 0, 0, 0, 0, 0, 0, 2298478847, 3909091583, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2214592767, 3607101695, 0, 0, 0, 0, 0, 0, 0, 1946157311, 4093640959, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 0, 536871167, 1191182591, 2281701631,3019899135, 637534463, 0, 0, 0, 100597760, 251592704, 33488896, 0, 3321889023, 2919235839, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2550137087, 4278190335, 4278190335, 3405775103, 570425599, 0, 0, 0, 0, 0, 0, 2046820607, 4043309311, 620757247, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 33488896, 0, 0, 218104063, 1291845887, 3841982719, 3388997887, 0, 0, 0, 0, 0, 1996488959, 4093640959, 1073742079, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1761607935, 4278190335, 150995199, 0, 0, 67109119, 2550137087, 3909091583, 889192703, 0, 0, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 0, 0, 0, 0, 2181038335, 3925868799, 0, 0, 218104063, 3070230783, 3623878911, 570425599, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 805306623, 3288334591, 1795162367, 1040187647, 1023410431, 2231369983, 4211081471, 1694499071, 0, 369099007, 3456106751, 3825205503, 1174405375, 872415487, 872415487, 872415487, 872415487, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4293984270, 2046951677, 3422552319, 4110418175, 4177527039, 3405775103, 1409286399, 0, 0, 1409286399, 4278190335, 4278190335, 4278190335, 4278190335, 4278190335, 4278190335, 4278190335, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760,4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 4294901760, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4278255360, 4144037632, 4009819904, 3875602176, 3741384448, 3607166720, 3472948992, 3338731264, 3204513536, 3053518592, 2936078080, 2801860352, 2650865408, 2516647680, 2382429952, 2264989440, 2113994496, 1996553984, 1862336256, 1728118528, 1577123584, 1459683072, 1325465344, 1191247616, 1040252672, 922812160, 771817216, 637599488, 503381760, 385941248, 234946304, 100728576, 4278255360, 4144037632, 4009819904, 3875602176, 3724607232, 3607166720, 3472948992, 3338731264, 3204513536, 3070295808, 2936078080, 2801860352, 2667642624, 2516647680, 2399207168, 2264989440, 2130771712, 1996553984, 1845559040, 1728118528, 1593900800, 1459683072, 1308688128, 1191247616, 1057029888, 922812160, 788594432, 637599488, 503381760, 369164032, 234946304, 117505792, 4278255360, 4144037632, 4009819904, 3875602176, 3741384448, 3607166720, 3472948992, 3338731264, 3204513536, 3053518592, 2919300864, 2801860352, 2650865408, 2533424896, 2399207168, 2264989440, 2113994496, 1996553984, 1862336256, 1728118528,1593900800, 1459683072, 1325465344, 1191247616, 1040252672, 906034944, 771817216, 654376704, 503381760, 369164032, 234946304, 117505792, 4278255360, 4144037632, 4009819904, 3858824960, 3741384448, 3607166720, 3472948992, 3338731264, 3204513536, 3070295808, 2936078080, 2801860352, 2667642624, 2533424896, 2382429952, 2264989440, 2130771712, 1979776768, 1862336256, 1728118528, 1577123584, 1442905856, 1325465344, 1191247616, 1040252672, 922812160, 771817216, 637599488, 503381760, 369164032, 234946304, 100728576, 4278255360, 4144037632, 4009819904, 3875602176, 3741384448, 3607166720, 3472948992, 3338731264, 3204513536, 3070295808, 2919300864, 2801860352, 2667642624, 2533424896, 2399207168, 2264989440, 2113994496, 1996553984, 1862336256, 1728118528, 1593900800, 1442905856, 1342241795, 1174470400, 1057029888, 906034944, 788594432, 654376704, 503381760, 385941248, 251723520, 100728576, 4278190335, 4160749823, 4026532095, 3892314367, 3741319423, 3623878911, 3472883967, 3338666239, 3221225727, 3070230783, 2952790271, 2818572543, 2667577599, 2533359871, 2399142143, 2264924415, 2147483903, 1996488959, 1862271231, 1728053503, 1593835775, 1459618047, 1325400319, 1191182591, 1056964863, 922747135, 788529407, 654311679, 520093951,385876223, 251658495, 117440767, 4278190335, 4160749823, 4026532095, 3892314367, 3741319423, 3623878911, 3489661183, 3355443455, 3221225727, 3087007999, 2936013055, 2801795327, 2667577599, 2533359871, 2399142143, 2281701631, 2130706687, 1996488959, 1862271231, 1728053503, 1593835775,1459618047, 1325400319, 1191182591, 1056964863, 922747135, 788529407, 654311679, 520093951, 385876223, 234881279, 100663551, 4278190335, 4160749823, 4026532095, 3892314367, 3758096639, 3623878911, 3489661183, 3355443455, 3221225727, 3087007999, 2936013055, 2801795327, 2667577599, 2550137087, 2415919359, 2264924415, 2130706687, 1996488959, 1862271231, 1728053503, 1593835775, 1459618047, 1325400319, 1191182591, 1056964863, 922747135, 788529407, 654311679, 503316735, 369099007, 251658495, 100663551, 4278190335, 4160749823, 4026532095, 3892314367, 3758096639, 3623878911, 3489661183, 3355443455, 3204448511, 3087007999, 2936013055, 2818572543, 2667577599, 2533359871, 2399142143, 2264924415, 2130706687, 1996488959, 1879048447, 1728053503, 1593835775, 1459618047, 1325400319, 1191182591, 1056964863, 922747135, 788529407, 654311679, 520093951, 385876223, 251658495, 117440767, 4278190335, 4160749823, 4026532095, 3892314367, 3758096639, 3623878911, 3489661183, 3355443455, 3221225727, 3087007999, 2952790271, 2818572543, 2667577599, 2533359871, 2399142143, 2264924415, 2147483903, 2013266175, 1862271231, 1744830719, 1610612991, 1476395263, 1342177535, 1191182591, 1056964863, 922747135, 788529407, 654311679, 520093951, 385876223, 251658495, 100663551, 4294901760, 4160684032, 4026466304, 3909025792, 3774808064, 3623813120, 3489595392, 3355377664, 3237937152, 3103719424, 2952724480, 2818506752, 2684289024, 2550071296, 2415853568, 2281635840, 2147418112, 2013200384, 1878982656, 1744764928, 1593769984, 1476329472,1325334528, 1207894016, 1056899072, 939458560, 788463616, 654245888, 520028160, 385810432, 251592704, 117374976, 4294901760, 4177461248, 4043243520, 3909025792, 3774808064, 3640590336, 3506372608, 3355377664, 3221159936, 3086942208, 2952724480, 2818506752, 2701066240, 2550071296, 2415853568, 2281635840, 2147418112, 2013200384, 1878982656, 1727987712, 1610547200, 1476329472, 1325334528, 1191116800, 1073676288, 922681344, 788463616, 654245888, 520028160, 385810432, 251592704, 100597760, 4294901760, 4177461248, 4043243520, 3909025792, 3774808064, 3640590336, 3489595392, 3372154880, 3237937152, 3103719424, 2952724480, 2818506752, 2700935170, 2550071296, 2415853568, 2281635840, 2147418112, 2013200384, 1878982656, 1744764928, 1610547200, 1459552256, 1342111744, 1191116800, 1056899072, 922681344, 788463616, 671023104, 520028160, 385810432, 251592704, 100597760, 4294901760, 4177461248, 4043243520, 3909025792, 3774808064, 3640590336, 3489595392, 3372154880, 3237937152, 3086942208, 2969501696, 2818506752, 2684289024, 2550071296, 2432630784, 2281635840, 2147418112, 2013200384, 1862205440, 1744764928, 1610547200, 1476329472, 1342111744, 1191116800, 1056899072, 922681344, 788463616, 654245888, 520028160, 385810432, 251592704, 117374976, 4294901760, 4177461248, 4043243520, 3909025792, 3774808064, 3623813120, 3506372608, 3372154880, 3237937152, 3103719424, 2952724480, 2835283968, 2684289024, 2550071296, 2432630784, 2281635840, 2147418112, 2046492676, 1862205440, 1744764928, 1610547200, 1476329472, 1342111744,1207894016, 1056899072, 939458560, 788463616, 654245888, 536281096, 385810432, 251592704, 134152192,
//      };
//
//      xdisplay d(display());
//
//      int iScreen = DefaultScreen(d);
//
//      Atom net_wm_icon = d.intern_atom("_NET_WM_ICON", False);
//
//      Atom cardinal = d.intern_atom("CARDINAL", False);
//
//      int length = 2 + 16 * 16 + 2 + 32 * 32;
//
//      int status = XChangeProperty(d, w->window(), net_wm_icon, cardinal, 32, PropModeReplace, (const unsigned char *)buffer, length);
//
//      if (status != 0)
//      {
//
//         return false;
//
//      }
//
//#elif 1
//
//      auto d1 = create_image({ 32, 32 });
//
//      if (!::is_ok(d1))
//      {
//
//         return false;
//
//      }
//
//      d1->g()->set_interpolation_mode(::draw2d::e_interpolation_mode_high_quality_bicubic);
//
//      d1->g()->stretch(d1->rectangle(), pimage->g(), pimage->rectangle());
//
//      memory m(puserinteraction->get_application());
//
//      int length = 2 + d1->area();
//
//      m.set_size(length * 4);
//
//      unsigned int * pcr = (unsigned int *)m.get_data();
//
//      pcr[0] = d1->width();
//
//      pcr[1] = d1->height();
//
//      int c = d1->area();
//
//      for (int i = 0; i < c; i++)
//      {
//
//         pcr[i + 2] = d1->colorref()[i];
//
//      }
//
//      windowing_output_debug_string("\nwindow::set_icon");
//
//      xdisplay d(display());
//
//      Atom net_wm_icon = intern_atom("_NET_WM_ICON", False);
//
//      Atom cardinal = intern_atom("CARDINAL", False);
//
//      int status = x_change_property(net_wm_icon, cardinal, 32, PropModeReplace, (const unsigned char *)pcr, length);
//
//      if (status == BadAlloc)
//      {
//
//
//      }
//      else if (status != 0)
//      {
//
//         return false;
//
//      }
//
//      windowing_output_debug_string("\nwindow::set_icon END");
//
//      fflush(stdout);
//
//#else
//
//      image d1(w->puserinteraction->create_new, this);
//
//      if (!d1->create(24, 24))
//      {
//
//         return false;
//
//      }
//
//      d1->get_graphics()->set_interpolation_mode(e_interpolation_mode_high_quality_bicubic);
//
//      d1->get_graphics()->StretchBlt(0, 0, d1.width(), d1.height(), int_point->get_graphics(), 0, 0, point.width(), point.height());
//
//      image d2(w->puserinteraction->create_new, this);
//
//      if (!d2->create(54, 54))
//      {
//
//         return false;
//
//      }
//
//      d2->get_graphics()->set_interpolation_mode(e_interpolation_mode_high_quality_bicubic);
//
//      d2->get_graphics()->StretchBlt(0, 0, d2.width(), d2.height(), int_point->get_graphics(), 0, 0, point.width(), point.height());
//
//      memory m(w->puserinteraction->get_application());
//
//      int length = 2 + d1->area() + 2 + d2->area();
//
//      m.set_size(length * 4);
//
//      unsigned int * pcr = (unsigned int *)m.get_data();
//
//      pcr[0] = d1.width();
//
//      pcr[1] = d1.height();
//
//      int c = d1->area();
//
//      for (int i = 0; i < c; i++)
//      {
//
//         pcr[i + 2] = d1->m_pcolorref[i];
//
//      }
//
//      memsize o;
//
//      o = 2 + d1->area();
//
//      pcr[o] = d2.width();
//
//      pcr[o + 1] = d2.height();
//
//      c = d2->area();
//
//      for (int i = 0; i < c; i++)
//      {
//
//         pcr[i + o + 2] = d2->m_pcolorref[i];
//
//      }
//
//      Display * display = w->display();
//
//      Atom net_wm_icon = XInternAtom(display, "_NET_WM_ICON", False);
//
//      Atom cardinal = XInternAtom(display, "CARDINAL", False);
//
//      int status = XChangeProperty(display, w->window(), net_wm_icon, cardinal, 32, PropModeReplace, (const unsigned char *)pcr, length);
//
//      if (status != 0)
//      {
//
//         //file_system()->put_contents("/home/camilo/window.txt", __string((int)w->window()));
//         return false;
//
//      }
//#endif
//      return true;
//
//   }
//

   //int window::store_name(const ::string & psz)
   //{

   //   windowing_output_debug_string("\nwindow::store_name");

   //   xdisplay d(display());

   //   int i = XStoreName(display(), window(), psz);

   //   windowing_output_debug_string("\nwindow::store_name END");

   //   return i;

   //}


   //int window::select_input(int iInput)
   //{

   //   windowing_output_debug_string("\nwindow::select_input");

   //   xdisplay d(display());

   //   int i = XSelectInput(display(), window(), iInput);

   //   windowing_output_debug_string("\nwindow::select_input END");

   //   return i;

   //}


   //int window::select_all_input()
   //{

   //   windowing_output_debug_string("\nwindow::select_all_input");

   //   xdisplay d(display());

   //   int i = select_input(ExposureMask | ButtonPressMask);

   //   windowing_output_debug_string("\nwindow::select_all_input");

   //   return i;

   //}


   void window::on_message_non_client_destroy(::message::message * pmessage)
   {

      auto pwindowing = system()->windowing();

      pwindowing->erase_window(this);

   }


   ::windowing::window * window::window_get_parent()
   {

      auto oswindow = get_parent_oswindow();

      if (!oswindow)
      {
         
         return nullptr;

      }

      auto pwindowing = system()->windowing();

      auto pacmewindowingwindow = pwindowing->window(oswindow);

      ::cast < ::windowing::window > pwindow = pacmewindowingwindow;

      return pwindow;

   }


   oswindow window::get_parent_oswindow()
   {

      //auto hwnd = get_hwnd();

      //auto hwndParent = ::GetParent(hwnd);

      //auto oswindowParent = __oswindow(hwndParent);

      //return oswindowParent;

      return nullptr;

   }


   void window::set_parent(::windowing::window * pwindowParent)
   {

      //auto hwnd = get_hwnd();

      //HWND hwndParent = nullptr;

      //if (::is_set(pwindowParent))
      //{

      //   hwndParent = as_hwnd(pwindowParent->get_oswindow());

      //}

      //if (!::SetParent(hwnd, hwndParent))
      //{

      //   return ::error_failed;

      //}

      //return ::success;

   }


   //void window::show_window(const ::e_display & edisplay, const ::user::e_activation & useractivation)
   bool window::_configure_window_unlocked(const class ::zorder & zorder, const ::user::activation & useractivation, bool bNoZorder, ::e_display edisplay) 
   {

      //auto iShowWindow = windows_show_window(edisplay, useractivation);

      //HWND hwnd = get_hwnd();

      //if (iShowWindow == SW_MAXIMIZE)
      //{

      //   if (_get_ex_style() & WS_EX_LAYERED)
      //   {

      //      iShowWindow = SW_NORMAL;

      //   }

      //}

      //if (!::XXXShowWindow(hwnd, iShowWindow))
      //{

      //   return ::error_failed;

      //}

      //return ::success;

      return true;

   }


   void window::full_screen(const ::int_rectangle & rectangle)
   {

      //::int_rectangle rBest;

      //int iMonitor = best_xinerama_monitor(puserinteraction, rectangle, rBest);

      //windowing_output_debug_string("\n::window::full_screen 1");

      //xdisplay d(display());

      //if (d.is_null())
      //{

      //   windowing_output_debug_string("\n::window::full_screen 1.1");

      //   return;

      //}

      //XWindowAttributes attr;

      //if (!XGetWindowAttributes(display(), window(), &attr))
      //{

      //   windowing_output_debug_string("\n::window::full_screen 1.2");

      //   fflush(stdout);

      //   return;

      //}

      //::int_rectangle rWindow;

      //rWindow.left() = attr.x;
      //rWindow.top() = attr.y;
      //rWindow.right() = attr.x + attr.width;
      //rWindow.bottom() = attr.y + attr.height;

      //if (rBest != rWindow)
      //{

      //   puserinteraction->place(rBest);

      //   XMoveResizeWindow(d, m_windowscorewindow, rBest.left(), rBest.top(), rBest.width(), rBest.height());

      //}

      //if (attr.map_state == IsViewable)
      //{

      //   mapped_net_state_raw(true, d, window(), m_iScreen, intern_atom(net_wm_state_fullscreen, false), 0);

      //}
      //else
      //{

      //   unmapped_net_state_raw(d, window(), intern_atom(net_wm_state_fullscreen, false), 0);

      //   XMapWindow(display(), window());

      //}

      //windowing_output_debug_string("\n::window::full_screen 2");

      //::fflush(stdout);

      //return ::success;

   }


   void window::exit_iconify()
   {

      //xdisplay d(display());

      //if (d.is_null())
      //{

      //   windowing_output_debug_string("\n::window::exit_iconify 1.1");

      //   return;

      //}

      //XWindowAttributes attr;

      //if (!XGetWindowAttributes(display(), window(), &attr))
      //{

      //   windowing_output_debug_string("\n::window::exit_full_screen 1.2");

      //   fflush(stdout);

      //   return;

      //}

      //if (attr.map_state == IsViewable)
      //{

      //   mapped_net_state_raw(false, d, window(), m_iScreen, intern_atom(net_wm_state_hidden, false), 0);

      //}

      //return ::success;

   }

   
   void window::exit_full_screen()
   {

      //xdisplay d(display());

      //if (d.is_null())
      //{

      //   windowing_output_debug_string("\n::window::exit_full_screen 1.1");

      //   return;

      //}

      //XWindowAttributes attr;

      //if (!XGetWindowAttributes(display(), window(), &attr))
      //{

      //   windowing_output_debug_string("\n::window::exit_full_screen 1.2");

      //   fflush(stdout);

      //   return;

      //}

      //if (attr.map_state == IsViewable)
      //{

      //   mapped_net_state_raw(false, d, window(), m_iScreen, intern_atom("_NET_WM_STATE_FULLSCREEN", false), 0);

      //}

      //return ::success;

   }


   void window::exit_zoomed()
   {

      //synchronous_lock synchronouslock(x11_mutex());

      //xdisplay d(display());

      //if (d.is_null())
      //{

      //   windowing_output_debug_string("\n::window::exit_zoomed 1.1");

      //   return;

      //}

      //XWindowAttributes attr;

      //if (!XGetWindowAttributes(display(), window(), &attr))
      //{

      //   windowing_output_debug_string("\n::window::exit_zoomed 1.2");

      //   fflush(stdout);

      //   return;

      //}

      //if (attr.map_state == IsViewable)
      //{

      //   mapped_net_state_raw(false, d, window(), m_iScreen,
      //      intern_atom("_NET_WM_STATE_MAXIMIZED_HORZ", false),
      //      intern_atom("_NET_WM_STATE_MAXIMIZED_VERT", false));

      //}

      //return ::success;

   }


   //void window::set_keyboard_focus()
   //{

   //   windowing()->m_pwindowFocus = this;

   //   if (m_pwindow)
   //   {

   //      if (m_puserinteractionFocusRequest)
   //      {

   //         m_puserinteractionFocus1 = m_puserinteractionFocusRequest;

   //         m_puserinteractionFocusRequest.release();

   //         if (m_puserinteractionFocus1)
   //         {

   //            if (m_puserinteractionFocus1->keyboard_focus_is_focusable())
   //            {


   //               SetInternalFocus();

   //            }

   //         }

   //      }

   //   }


   //   //return ::success;

   //}


   //::pointer<window>window::get_active_window()
   //{

   //   throw ::interface_only();

   //   return nullptr;

   //}


   void window::set_active_window()
   {

      //HWND hwnd = get_hwnd();

      //if (!::XXXSetActiveWindow(hwnd))
      //{

      //   return ::error_failed;

      //}

      //return ::success;

   }


   void window::bring_to_front()
   {

      //HWND hwnd = get_hwnd();

      //if (!::BringWindowToTop(hwnd))
      //{

      //   return ::error_failed;

      //}

      //return ::success;

   }


   //void window::set_mouse_capture()
   //{

   //   windowing()->m_pwindowMouseCapture = this;

   //}



   //bool window::has_mouse_capture() const
   //{

   //   return windowing()->m_pwindowCapture == this;

   //}


   //bool window::has_keyboard_focus() const
   //{

   //   return windowing()->m_pwindowFocus == this && m_bInternalFocus;

   //}


   //bool window::is_active_window() const
   //{

   //   //itask itask = 0;

   //   //auto puserinteraction = user_interaction();

   //   //if (puserinteraction && puserinteraction->m_pthreadUserInteraction)
   //   //{

   //   //   itask = puserinteraction->m_pthreadUserInteraction->get_ithread();

   //   //}

   //   //GUITHREADINFO info = {};

   //   //info.cbSize = sizeof(GUITHREADINFO);

   //   //HWND hwndActive;

   //   //if (GetGUIThreadInfo((DWORD)itask, &info))
   //   //{

   //   //   hwndActive = info.hwndActive;

   //   //}
   //   //else
   //   //{

   //   //   hwndActive = ::GetActiveWindow();

   //   //}

   //   //if (hwndActive == get_hwnd())
   //   //{

   //   //   return true;

   //   //}

   //   ////auto puserinteraction = psystem->ui_from_handle(oswindowActive);

   //   ////if (::is_set(puserinteraction))
   //   ////{

   //   ////   if (puserinteraction->m_pthreadUserInteraction == puserinteraction->m_pthreadUserInteraction)
   //   ////   {

   //   ////      if (puserinteraction->m_ewindowflag & e_window_flag_satellite_window)
   //   ////      {

   //   ////         return true;

   //   ////      }

   //   ////   }

   //   ////}

   //   return false;

   //}


   void window::destroy_window()
   {

      //HWND hwnd = get_hwnd();

      //if (!::DestroyWindow(hwnd))
      //{

      //   return ::error_failed;

      //}

      //return ::success;

   }


   bool window::client_to_screen(::int_point * ppoint)
   {

      //HWND hwnd = get_hwnd();

      //ClientToScreen(hwnd, (POINT *) ppoint);

      return true;

   }


   bool window::screen_to_client(::int_point * ppoint)
   {

      //HWND hwnd = get_hwnd();

      //ScreenToClient(hwnd, (POINT *)ppoint);

      return true;

   }


   //long window::get_state()
   //{

   //   windowing_output_debug_string("\n::window::get_state 1");

   //   xdisplay d(display());

   //   static const long WM_STATE_ELEMENTS = 2L;

   //   unsigned long nitems = 0;

   //   unsigned long leftover = 0;

   //   Atom atomWmState = 0;

   //   Atom actual_type = 0;

   //   int actual_format = 0;

   //   int status = 0;

   //   unsigned char * point = nullptr;

   //   if (d.m_pdata->m_atomWmState == None)
   //   {

   //      d.m_pdata->m_atomWmState = d.intern_atom("WM_STATE", false);

   //   }

   //   atomWmState = d.m_pdata->m_atomWmState;

   //   status = XGetWindowProperty(d, m_windowscorewindow, atomWmState, 0L, WM_STATE_ELEMENTS, False, AnyPropertyType, &actual_type,
   //      &actual_format, &nitems, &leftover, &point);

   //   if (status == 0)
   //   {

   //      long lStatus = -1;

   //      if (point != nullptr)
   //      {

   //         lStatus = (long)*int_point;

   //      }

   //      XFree(point);

   //      windowing_output_debug_string("\n::window::get_state 1.1");

   //      return lStatus;

   //   }

   //   windowing_output_debug_string("\n::window::get_state 2");

   //   return -1;

   //}


   //bool window::is_iconic()
   //{

   //   HWND hwnd = get_hwnd();

   //   auto bIconic = ::IsIconic(hwnd);

   //   return bIconic != FALSE;

   //}


   bool window::is_window()
   {

      //HWND hwnd = get_hwnd();

      //auto bWindow = ::IsWindow(hwnd);

      //return bWindow != FALSE;

      return true;

   }


   bool window::is_window_visible()
   {

      //HWND hwnd = get_hwnd();

      //auto bWindowVisible = ::IsWindowVisible(hwnd);

      //return bWindowVisible != FALSE;

      return true;

   }


   bool window::is_destroying()
   {

      //if (::is_null(this))
      //{

      //   return true;

      //}

      //if (m_pwindow == nullptr)
      //{

      //   return true;

      //}

      //auto puserinteraction = user_interaction();

      //if (!puserinteraction->m_bUserElementOk)
      //{

      //   return true;

      //}

      return false;

   }


   //bool window::on_set_window_position(const class ::zorder& zorder, int x, int y, int cx, int cy, const ::user::e_activation& useractivation, bool bNoZorder, bool bNoMove, bool bNoSize, bool bShow, bool bHide)
   bool window::_strict_set_window_position_unlocked(int x, int y, int cx, int cy, bool bNoMove, bool bNoSize)
   {

      //m_coreapplicationview.Cu

      //if (!(_get_ex_style() & WS_EX_LAYERED))
      //{

      //   ::windowing::window::on_set_window_position(zorder, x, y, cx, cy, useractivation, bNoZorder, bNoMove, bNoSize, bShow, bHide);

      //}

      return false;

   }


//#undef SET_WINDOW_POS_LOG
//
//   bool window::_strict_set_window_position_unlocked(int x, int y, int cx, int cy, bool bNoMove, bool bNoSize)
//   {
//
//      //HWND hwnd = get_hwnd();
//
//      //auto pwindowing = windowing();
//
//      //HWND hwndInsertAfter = pwindowing->zorder_to_hwnd(zorder);
//
//      //bool bNoZorder = nFlags & SWP_NOZORDER;
//
//      //if (::GetWindowLong(hwnd, GWL_EXSTYLE) & WS_EX_LAYERED)
//      //{
//
//      //   nFlags |= SWP_NOMOVE;
//
//      //   nFlags |= SWP_NOSIZE;
//
//      //}
//
//      //auto bSetWindowPos = ::SetWindowPos(hwnd, hwndInsertAfter, x, y, cx, cy, nFlags);
//
//      //return bSetWindowPos != FALSE;
//
//      return false;
//
//   }
//

//   bool window::_set_window_pos(class ::zorder zorder, int x, int y, int cx, int cy, unsigned int nFlags)
//   {
//
//      synchronous_lock synchronouslock(x11_mutex());
//
//      windowing_output_debug_string("\n::window::set_window_position 1");
//
//      auto pdisplay = display();
//
//      xdisplay d(pdisplay);
//
//      XWindowAttributes attrs = {};
//
//      Window w = window();
//
//      if (!XGetWindowAttributes(pdisplay, w, &attrs))
//      {
//
//         windowing_output_debug_string("\n::window::set_window_position 1.1 xgetwindowattr failed");
//
//         return false;
//
//      }
//
//      if (nFlags & SWP_SHOWWINDOW)
//      {
//
//         if (attrs.map_state == IsUnmapped)
//         {
//
//            windowing_output_debug_string("\n::window::set_window_position Mapping Window 1.2");
//
//            XMapWindow(display(), window());
//
//         }
//
//         if (!XGetWindowAttributes(display(), window(), &attrs))
//         {
//
//            windowing_output_debug_string("\n::window::set_window_position 1.3 xgetwindowattr failed");
//
//            return false;
//
//         }
//
//      }
//
//      bool bMove = !(nFlags & SWP_NOMOVE);
//
//      bool bSize = !(nFlags & SWP_NOSIZE);
//
//      if (bMove)
//      {
//
//         if (bSize)
//         {
//
//            windowing_output_debug_string("\n::window::set_window_position Move Resize Window 1.4");
//
//#ifdef SET_WINDOW_POS_LOG
//
//            information() << "XMoveResizeWindow (%d, %d) - (%d, %d)", x, y, cx, cy;
//
//#endif
//
//            if (cx <= 0 || cy <= 0)
//            {
//
//               cx = 1;
//
//               cy = 1;
//
//#ifdef SET_WINDOW_POS_LOG
//
//               information() << "Changing parameters... (%d, %d) - (%d, %d)", x, y, cx, cy;
//
//#endif
//
//            }
//
//            XMoveResizeWindow(display(), window(), x, y, cx, cy);
//
//         }
//         else
//         {
//
//            windowing_output_debug_string("\n::window::set_window_position Move Window 1.4.1");
//
//            XMoveWindow(display(), window(), x, y);
//
//         }
//
//      }
//      else if (bSize)
//      {
//
//         windowing_output_debug_string("\n::window::set_window_position Resize Window 1.4.2");
//
//         XResizeWindow(display(), window(), cx, cy);
//
//      }
//
//      //   if(bMove || bSize)
//      //   {
//      //
//      //      if(attrs.override_redirect)
//      //      {
//      //
//      //         if(!(puserinteraction->m_ewindowflag & e_window_flag_arbitrary_positioning))
//      //         {
//      //
//      //            XSetWindowAttributes set;
//      //
//      //            set.override_redirect = False;
//      //
//      //            if(!XChangeWindowAttributes(display(), window(), CWOverrideRedirect, &set))
//      //            {
//      //
//      //               information() << "linux::window::_native_create_window_ex failed to clear override_redirect";
//      //
//      //            }
//      //
//      //         }
//      //
//      //      }
//      //
//      //   }
//
//
//      if (nFlags & SWP_HIDEWINDOW)
//      {
//
//         if (attrs.map_state == IsViewable)
//         {
//
//            windowing_output_debug_string("\n::window::set_window_position Withdraw Window 1.4.3");
//
//            XWithdrawWindow(display(), window(), m_iScreen);
//
//         }
//
//      }
//
//      if (!XGetWindowAttributes(display(), window(), &attrs))
//      {
//
//         windowing_output_debug_string("\n::window::set_window_position xgetwndattr 1.4.4");
//
//         return false;
//
//      }
//
//      if (attrs.map_state == IsViewable || (nFlags & SWP_SHOWWINDOW))
//      {
//
//         if (!(nFlags & SWP_NOZORDER))
//         {
//
//            if (zorder.m_ezorder == e_zorder_top_most)
//            {
//
//               if (m_iaNetWmState[net_wm_state_above] != 1)
//               {
//
//                  wm_state_above_raw(this, true);
//
//               }
//
//               XRaiseWindow(display(), window());
//
//            }
//            else if (zorder.m_ezorder == e_zorder_top)
//            {
//
//               if (m_iaNetWmState[net_wm_state_above] != 0
//                  || m_iaNetWmState[net_wm_state_below] != 0
//                  || m_iaNetWmState[net_wm_state_hidden] != 0
//                  || m_iaNetWmState[net_wm_state_maximized_horz] != 0
//                  || m_iaNetWmState[net_wm_state_maximized_vert] != 0
//                  || m_iaNetWmState[net_wm_state_fullscreen] != 0)
//               {
//
//                  wm_state_clear_raw(this, false);
//
//               }
//
//               XRaiseWindow(display(), window());
//
//            }
//            else if (zorder.m_ezorder == e_zorder_bottom)
//            {
//
//               if (m_iaNetWmState[net_wm_state_below] != 1)
//               {
//
//                  wm_state_below_raw(this, true);
//
//               }
//
//               XLowerWindow(display(), window());
//
//            }
//
//         }
//
//         puserinteraction->ModifyStyle(0, WS_VISIBLE, 0);
//
//      }
//      else
//      {
//
//         puserinteraction->ModifyStyle(WS_VISIBLE, 0, 0);
//
//      }
//
//      //on_change_visibility();
//
//      windowing_output_debug_string("\n::window::set_window_position 2");
//
//      return 1;
//
//   }


   void window::set_mouse_cursor(::windowing::cursor * pcursor)
   {

      HCURSOR hcursor = nullptr;
      
      if (::is_set(pcursor))
      {

         hcursor = (HCURSOR)pcursor->get_os_data();

         if (hcursor == nullptr)
         {

            //auto estatus = 
            
            pcursor->_create_os_cursor();

 /*           if (!estatus)
            {

               throw ::exception(estatus);

            };*/

            hcursor = (HCURSOR)pcursor->get_os_data();

            if (!hcursor)
            {

               throw ::exception(error_resource);

            }

         }

      }

      // At windows SetMouseCursor(nullptr) removes the cursor from screen
      // similar apis in other platforms behave the same?

      //if (!::SetCursor(hcursor))
      //{

      //   return ::error_failed;

      //}

      //return ::success;

   }


   //bool window::reset(::windowing::cursor * pcursor, ::aura::session * psession)
   //{

   //   synchronous_lock synchronouslock(psession->synchronization());

   //   if (::is_null(puserinteraction))
   //   {

   //      return false;

   //   }

   //   App(puserinteraction).window_set_mouse_cursor(puserinteraction->get_hwnd(), 0);

   //   return true;

   //}


   //void window::message_handler(::message::message * pmessage)
   //{
   //   
   //   if (pmessage->m_emessage == (enum_message)WM_SYSCOMMAND)
   //   {

   //      if (pmessage->m_wparam == SC_SCREENSAVE)
   //      {

   //         auto puserinteraction = user_interaction();

   //         if (puserinteraction && !puserinteraction->_001CanEnterScreenSaver())
   //         {

   //            pmessage->m_bRet = true;

   //            pmessage->m_lresult = 0;

   //         }

   //         return;

   //      }
   //      else if (pmessage->m_wparam == SC_MAXIMIZE)
   //      {

   //         auto puserinteraction = user_interaction();

   //         if (puserinteraction && !puserinteraction->_001Maximize())
   //         {

   //            pmessage->m_bRet = true;

   //            pmessage->m_lresult = 0;

   //         }

   //         return;
   //      }
   //      else if (pmessage->m_wparam == SC_RESTORE)
   //      {

   //         auto puserinteraction = user_interaction();

   //         if (puserinteraction && !puserinteraction->_001Restore())
   //         {

   //            pmessage->m_bRet = true;

   //            pmessage->m_lresult = 0;

   //         }

   //         return;
   //      }

   //   }

   //   auto puserinteraction = user_interaction();

   //   if (puserinteraction)
   //   {

   //      puserinteraction->message_handler(pmessage);

   //   }

   //}


//   int_bool window::set_mouse_cursor(hwnd window, hcursor hcursor)
//   {
//
//#ifdef WINDOWS_DESKTOP
//
//      __UNREFERENCED_PARAMETER(window);
//
//      if (!::SetCursor(hcursor))
//      {
//
//         return false;
//
//      }
//
//#endif
//
//      return true;
//
//   }


   //bool window::get_window_placement(WINDOWPLACEMENT * puserinteractionpl)
   //{

   //   puserinteractionpl->length = sizeof(WINDOWPLACEMENT);

   //   return ::GetWindowPlacement(get_hwnd(), puserinteractionpl) != false;

   //}


   //bool window::set_window_placement(const WINDOWPLACEMENT * puserinteractionpl)
   //{

   //   auto puserinteraction = user_interaction();

   //   synchronous_lock synchronouslock(puserinteraction->synchronization());

   //   ASSERT(::IsWindow(get_hwnd()));

   //   ((WINDOWPLACEMENT *)puserinteractionpl)->length = sizeof(WINDOWPLACEMENT);

   //   return ::SetWindowPlacement(get_hwnd(), puserinteractionpl) != false;

   //}


   void window::set_foreground_window(::user::activation_token * puseractivationtoken)
   {

      /*HWND hwnd = get_hwnd();

      if (!::SetForegroundWindow(hwnd))
      {

         return ::error_failed;

      }*/

      //return ::success;

      //// special activate logic for floating toolbars and palettes
      //auto pActiveWnd = GetForegroundWindow();

      //if (!pActiveWnd || !((pActiveWnd)->get_hwnd() == get_hwnd() || ::IsChild((pActiveWnd)->get_hwnd(), get_hwnd())))
      //{
      //   // clicking on floating frame when it does not have
      //   // focus itself -- activate the toplevel frame instead.

      //   auto puserinteractionTopLevel = get_top_level();

      //   if (puserinteractionTopLevel)
      //   {

      //      puserinteractionTopLevel->set_foreground_window();

      //   }

   }


   void window::_001OnPaint(::message::message * pmessage)
   {

      //HideCaret();

      //PAINTSTRUCT ps;
      //HDC hdc1 = BeginPaint(m_oswindow, &ps);
      //// TODO: Add any drawing code that uses hdc here...
      //EndPaint(m_oswindow, &ps);

      //return
      //   ;
      //if (GetExStyle() & WS_EX_LAYERED)
      //{


      //   return;

      //}

      ::int_rectangle rectangleWindow;

      auto puserinteraction = user_interaction();

      rectangleWindow = puserinteraction->screen_rectangle();

      //PAINTSTRUCT paint;

      //memory_set(&paint, 0, sizeof(paint));

      //HDC hdc = ::BeginPaint(get_hwnd(), &paint);

      //::SelectClipRgn(hdc, nullptr);

      //::int_rectangle rectanglePaint;

      //::int_rectangle rectangleUpdate;

      //rectanglePaint = paint.rcPaint;


      throw ::exception(todo);

      //if (rectanglePaint.is_null() || (GetExStyle() & WS_EX_LAYERED))
      //{

      //   rectangleUpdate = rectangleWindow;

      //   rectanglePaint = rectangleWindow;

      //   puserinteraction->_001ScreenToClient(rectanglePaint, ::user::e_layout_design);

      //}
      //else
      //{

      //   rectangleUpdate = rectanglePaint;

      //}

      //if (m_pgraphics.is_null())
      //{

      //   update_graphics_resources();

      //}

      //::pointer<::windows::buffer>pbuffer = m_pgraphics;

      //ASSERT(pbuffer.is_set());

      //single_lock synchronouslock(pbuffer->mutex());

      //auto & buffer = pbuffer->m_osbuffera[!pbuffer->m_iCurrentBuffer];

      //::BitBlt(hdc, rectangleUpdate.left(), rectangleUpdate.top(), rectangleUpdate.width(), rectangleUpdate.height(), buffer.m_hdc, 0, 0, SRCCOPY);








      //if (m_spgraphics.is_set())
      //{

      //   ::draw2d::graphics_pointer & pgraphics = m_spgraphics->on_begin_draw();

      //   if (pgraphics != nullptr)
      //   {

      //      try
      //      {

      //         _001Print(pgraphics);

      //      }
      //      catch (...)
      //      {


      //      }

      //      ::draw2d::graphics_pointer g(e_create);

      //      try
      //      {

      //         if (pgraphics != nullptr && g->attach_hdc(hdc))
      //         {

      //            pgraphics->SetViewportOrg(0, 0);

      //            g->BitBlt(rectanglePaint.left(), rectanglePaint.top(), rectanglePaint.width(), rectanglePaint.height(), pgraphics, rectangleUpdate.left(), rectangleUpdate.top());

      //         }

      //      }
      //      catch (...)
      //      {

      //      }

      //   }

      //}

      //::EndPaint(get_hwnd(), &paint);

      pmessage->m_bRet = true;

      pmessage->m_lresult = 0;

      //ShowCaret();

   }


   //::user::interaction * window::set_parent(::user::interaction * pWndNewParent)
   //{

   //   return nullptr;

   //   //ASSERT(::IsWindow(get_hwnd()));

   //   //return psystem->ui_from_handle(::SetParent(get_hwnd(), pWndNewParent->get_hwnd()));

   //}


   //::user::interaction * window::get_parent() const
   //{

   //   return nullptr;

   //   //if (!::IsWindow(get_hwnd()))
   //   //{

   //   //   return nullptr;

   //   //}

   //   //if (get_hwnd() == nullptr)
   //   //{

   //   //   return nullptr;

   //   //}

   //   //HWND hwndParent = ::GetParent(get_hwnd());

   //   //if (hwndParent == nullptr)
   //   //{

   //   //   return nullptr;

   //   //}

   //   //return psystem->ui_from_handle(hwndParent);

   //}


   bool window::is_iconic()
   {

      //if (_get_ex_style() & WS_EX_LAYERED)
      //{
      //   
      //   auto puserinteraction = user_interaction();

      //   return puserinteraction->layout().sketch().display() == ::e_display_iconic;

      //}
      //else
      //{

      //   if (!::IsWindow(get_hwnd()))
      //   {

      //      return false;

      //   }

      //   return ::IsIconic(get_hwnd()) != false;

      //}

      return false;

   }




   ::user::interaction * window::get_owner()
   {

      ::oswindow oswindow = get_owner_oswindow();

      auto pwindowing = system()->windowing();

      auto pacmewindowingwindow = pwindowing->window(oswindow);

      ::cast < ::windowing::window > pwindow = pacmewindowingwindow;

      return pwindow->user_interaction();

   }


   oswindow window::get_owner_oswindow()
   {

      //if (!::IsWindow(get_hwnd()))
      //{

      //   return nullptr;

      //}

      //if (get_hwnd() == nullptr)
      //{

      //   return nullptr;

      //}

      //HWND hwndOwner = ::GetWindow(get_hwnd(), GW_OWNER);

      //if (hwndOwner == nullptr)
      //{

      //   return get_parent_oswindow();

      //}

      //return __oswindow(hwndOwner);

      return nullptr;

   }


   void window::set_owner(::windowing::window * pWndNewOwner)
   {

      //auto hwnd = get_hwnd();

      //HWND hwndOwner = nullptr;

      //if (::is_set(pWndNewOwner))
      //{

      //   hwndOwner = as_hwnd(pWndNewOwner->get_oswindow());

      //}

      //if (!::SetWindowLongPtr(hwnd, GWLP_HWNDPARENT, (LONG_PTR) hwndOwner))
      //{

      //   return ::error_failed;

      //}

      //return ::success;

   }



   //int window::get_window_long(int nIndex) const
   //{
   //   return ::GetWindowLong(get_hwnd(), nIndex);
   //}

   //int window::set_window_long(int nIndex, int lValue)
   //{
   //   return ::SetWindowLong(get_hwnd(), nIndex, lValue);
   //}


   //iptr window::get_window_long_ptr(int nIndex) const
   //{

   //   return ::GetWindowLongPtr(get_hwnd(), nIndex);

   //}


   //iptr window::set_window_long_ptr(int nIndex, iptr lValue)
   //{

   //   return ::SetWindowLongPtr(get_hwnd(), nIndex, lValue);

   //}


   // window
      /* window::operator hwnd() const
      { return this == nullptr ? nullptr : get_hwnd(); }*/
   //bool window::operator==(const window & wnd) const
   //{

   //   return (((window *)&wnd)->get_hwnd()) == ((window *)this)->get_hwnd();

   //}


   //bool window::operator!=(const window & wnd) const
   //{

   //   return (((window *)&wnd)->get_hwnd()) != ((window *)this)->get_hwnd();

   //}


   //unsigned int window::GetStyle() const
   //{

   //   if (!::IsWindow(get_hwnd()))
   //      return 0;

   //   return (unsigned int)::GetWindowLong(get_hwnd(), GWL_STYLE);

   //}


   void window::default_message_handler(::message::message * pmessage)
   {

      //HWND hwnd = as_hwnd(pmessage->m_oswindow);

      //UINT message = pmessage->m_emessage.unsigned int();

      //WPARAM wparam = pmessage->m_wparam;

      //LPARAM lparam = pmessage->m_lparam;

      //LRESULT lresult = ::DefWindowProcW(hwnd, message, wparam, lparam);

      //pmessage->m_lresult = lresult;

   }


   //iptr window::_get_style() const
   //{

   //   return _get_window_long_ptr(GWL_STYLE);

   //}


   //iptr window::_get_ex_style() const
   //{

   //   return _get_window_long_ptr(GWL_EXSTYLE);

   //}


   //bool window::_set_style(iptr iStyle)
   //{

   //   return _set_window_long_ptr(GWL_STYLE, iStyle);

   //}


   //bool window::_set_ex_style(iptr iExStyle)
   //{

   //   return _set_window_long_ptr(GWL_EXSTYLE, iExStyle);

   //}

   //bool window::_modify_style(iptr dwRemove, iptr dwAdd, unsigned int nFlags)
   //{

   //   auto nStyle = _get_style();

   //   nStyle &= ~dwRemove;

   //   nStyle |= dwAdd;

   //   _set_style(nStyle);

   //   if (nFlags)
   //   {

   //      ::SetWindowPos(get_hwnd(), 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOMOVE | nFlags);

   //   }

   //   return true;

   //}


   //bool window::_modify_ex_style(iptr dwRemove, iptr dwAdd, unsigned int nFlags)
   //{

   //   auto nExStyle = _get_ex_style();

   //   nExStyle &= ~dwRemove;

   //   nExStyle |= dwAdd;

   //   _set_ex_style(nExStyle);

   //   if (nFlags)
   //   {

   //      ::SetWindowPos(get_hwnd(), 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOMOVE | nFlags);

   //   }

   //   return true;

   //}


   //bool window::ModifyStyleEx(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags)
   //{

   //   if (!::IsWindow(get_hwnd()))
   //      return false;

   //   return ModifyStyleEx(get_hwnd(), dwRemove, dwAdd, nFlags);

   //}


   lresult window::send_message(::enum_message emessage, ::wparam wparam, ::lparam lparam)
   {

      ///return ::SendMessage(get_hwnd(), atom.umessage(), wParam, lParam);

      return 0;

   }


   void window::post_message(::enum_message emessage, ::wparam wparam, ::lparam lparam)
   {

      //HWND hwnd = get_hwnd();

      //unsigned int message = atom.umessage();

      //wparam wparam = wParam;

      //return ::PostMessage(hwnd, message, wparam, lParam.m_lparam) != false;

      //return false;
   }


   //bool window::DragDetect(const ::int_point & point) const
   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   return ::DragDetect(((window *)this)->get_hwnd(), int_point) != false;

   //}


   //void window::set_window_text(const ::string & pszString)
   //{

   //   

   //   //DWORD_PTR lresult = 0;

   //   //auto puserinteraction = user_interaction();

   //   //puserinteraction->m_strWindowText = pszString;

   //   //wstring wstrText(puserinteraction->m_strWindowText);

   //   //const unichar * pwszText = wstrText;

   //   //if (!::SendMessageTimeoutW(get_hwnd(), WM_SETTEXT, 0, (LONG_PTR)pwszText, SMTO_ABORTIFHUNG, 500, &lresult))
   //   //{

   //   //   return;

   //   //}

   //   //string str;

   //   //get_window_text(str);

   //}


   //character_count window::get_window_text(char * pszString, character_count nMaxCount)
   //{

   //   string str;

   //   get_window_text(str);

   //   ansi_count_copy(pszString, str, (size_t)minimum(nMaxCount, str.length()));

   //   return str.length();

   //}


   //void window::get_window_text(string & str)
   //{

   //   //DWORD_PTR lresult = 0;

   //   //if (!::SendMessageTimeoutW(get_hwnd(), WM_GETTEXTLENGTH, 0, 0, SMTO_ABORTIFHUNG, 90, &lresult))
   //   //   return;

   //   //wstring wstr;

   //   //if (!::SendMessageTimeoutW(get_hwnd(), WM_GETTEXT, (lparam)wstr.get_buffer(lresult + 1), lresult + 1, SMTO_ABORTIFHUNG, 90, &lresult))
   //   //   return;

   //   //str = wstr;
   //   m_pwindowing->windowing_send({ e_timeout, 15_s, [&str]()
   //      {

   //         auto  applicationview = ::winrt::Windows::UI::ViewManagement::ApplicationView::GetForCurrentView();

   //         str = applicationview.Title().begin();

   //      } });

   //}


   //character_count window::get_window_text_length()
   //{

   //   //ASSERT(::IsWindow(get_hwnd()));

   //   //return ::GetWindowTextLength(get_hwnd());

   //   return 0;

   //}


   //void window::DragAcceptFiles(bool bAccept)
   //{
   //   ASSERT(::IsWindow(get_hwnd()));
   //   ::DragAcceptFiles(get_hwnd(), bAccept);
   //}


   unsigned int window::ArrangeIconicWindows()
   {

      //ASSERT(::IsWindow(get_hwnd()));
      //return ::ArrangeIconicWindows(get_hwnd());

      return 0;

   }


   //int window::SetWindowRgn(HRGN hRgn,bool bRedraw)
   //{

   //   //ASSERT(::IsWindow(get_hwnd())); return ::SetWindowRgn(get_hwnd(),hRgn,bRedraw);

   //}


   //int window::GetWindowRgn(HRGN hRgn)
   //{

   //   //ASSERT(::IsWindow(get_hwnd()) && hRgn != nullptr); return ::GetWindowRgn(get_hwnd(),hRgn);

   //}


      //void window::bring_to_top(::e_display edisplay)
      //{

      //   if (get_parent() == nullptr)
      //   {

      //      // place the window on top except for certain nCmdShow

      //      if (is_visible(edisplay)
      //         && edisplay_command(edisplay) != e_display_iconic &&
      //         !no_activate(edisplay))
      //      {

      //         HWND hwnd = get_hwnd();

      //         hwnd = ::GetLastActivePopup(hwnd);

      //         ::user::interaction * puserinteraction = psystem->ui_from_handle(hwnd);

      //         if (puserinteraction == nullptr)
      //            BringWindowToTop();
      //         else
      //            puserinteraction->BringWindowToTop();

      //      }

      //   }

      //}

      // MSDN
      // Brings the specified window to the top of the Z order.
      // If the window is a top-level window, it is activated.
      // If the window is a child window, the top-level parent
      // window associated with the child window is activated.
      //
      // Use the BringWindowToTop function to uncover any window
      // that is partially or completely obscured by other windows.
      // Calling this function is similar to calling the set_window_position
      // function to change a window's position in the Z order.
      // BringWindowToTop does not make a window a top-level window.

      //bool window::BringWindowToTop()
      //{

      //   bool bOk = ::BringWindowToTop(get_hwnd()) != false;


      //   if (GetExStyle() & WS_EX_LAYERED)
      //   {

      //      if (!(GetExStyle() & WS_EX_TOPMOST))
      //      {

      //         ::set_window_position(get_hwnd(), (HWND)e_zorder_top, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

      //         //::set_window_position(get_hwnd(),(HWND)e_zorder_top,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

      //         //::set_window_position(get_hwnd(),(HWND)e_zorder_top_most,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

      //         //::set_window_position(get_hwnd(),(HWND)e_zorder_top,0,0,0,0,SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW);

      //      }

      //   }

      //   return bOk;

      //}


   //void window::MapWindowPoints(::user::window * puserinteractionTo, ::int_point * pPoint, unsigned int nCount)
   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   ::MapWindowPoints(get_hwnd(), puserinteractionTo->get_hwnd(), pPoint, nCount);

   //}


   //void window::MapWindowPoints(::user::window * puserinteractionTo, ::int_rectangle * prectangle)

   //{
   //   ASSERT(::IsWindow(get_hwnd()));
   //   ::MapWindowPoints(get_hwnd(), puserinteractionTo->get_hwnd(), (::int_point *)prectangle, 2);

   //}



   void window::UpdateWindow()
   {
      //::UpdateWindow(get_hwnd());
   }

   void window::SetRedraw(bool bRedraw)
   {
      //ASSERT(::IsWindow(get_hwnd()));
      //::SendMessage(get_hwnd(), WM_SETREDRAW, bRedraw, 0);
   }

   bool window::GetUpdateRect(::int_rectangle * prectangle, bool bErase)
   {

      //ASSERT(::IsWindow(get_hwnd()));
      //return ::GetUpdateRect(get_hwnd(), (RECT *) prectangle, bErase) != false;

      return false;
   }


   int window::GetUpdateRgn(::draw2d::region * pRgn, bool bErase)
   {

      //ASSERT(::IsWindow(get_hwnd()));
      //return ::GetUpdateRgn(get_hwnd(), (HRGN)pRgn->get_os_data(), bErase);

      return 0;

   }


   void window::Invalidate(bool bErase)
   {
      //ASSERT(::IsWindow(get_hwnd()));
      //::InvalidateRect(get_hwnd(), nullptr, bErase);
   }

   void window::InvalidateRect(const ::int_rectangle * rectangle, bool bErase)

   {
      //ASSERT(::IsWindow(get_hwnd()));
      //::InvalidateRect(get_hwnd(), (RECT *) rectangle, bErase);

   }


   void window::InvalidateRgn(::draw2d::region * pRgn, bool bErase)
   {

      //ASSERT(::IsWindow(get_hwnd()));
      //::InvalidateRgn(get_hwnd(), (HRGN)pRgn->get_os_data(), bErase);

   }


   void window::ValidateRect(const ::int_rectangle * rectangle)

   {

      //ASSERT(::IsWindow(get_hwnd()));

      //::ValidateRect(get_hwnd(), (RECT *) rectangle);


   }


   void window::ValidateRgn(::draw2d::region * pRgn)
   {

      //ASSERT(::IsWindow(get_hwnd()));

      ////::ValidateRgn(get_hwnd(), (HRGN)pRgn->get_os_data());

   }


   void window::_on_configure_notify_unlocked(const ::int_rectangle & rectangle)
   {

   }


   void window::ShowOwnedPopups(bool bShow)
   {


   }


   ::pointer<::draw2d::graphics>window::GetDCEx(::draw2d::region * prgnClip, unsigned int flags)
   {

      //ASSERT(::IsWindow(get_hwnd()));

      auto pgraphics = __øcreate < ::draw2d::graphics >();

      throw ::exception(todo);

      //pgraphics->attach(::GetDCEx(get_hwnd(), (HRGN)prgnClip->get_os_data(), flags));

      return pgraphics;


   }


   bool window::LockWindowUpdate()
   {

      //ASSERT(::IsWindow(get_hwnd()));

      //return ::LockWindowUpdate(get_hwnd()) != false;

      return false;
   }

   void window::UnlockWindowUpdate()
   {

      //ASSERT(::IsWindow(get_hwnd()));

      //::LockWindowUpdate(nullptr);

   }


   bool window::RedrawWindow(const ::int_rectangle & rectangleUpdate, ::draw2d::region * prgnUpdate, unsigned int flags)
   {

      //if (m_bDestroyImplOnly)
      //{

      //   return false;

      //}

      auto puserinteraction = user_interaction();

      if (!puserinteraction->is_window_visible(::user::e_layout_sketch))
      {

         return true;

      }

      //if (!(_get_ex_style() & WS_EX_LAYERED))
      //{

      //   //::RedrawWindow(get_hwnd(), nullptr, nullptr, flags);

      //}

      if (flags & RDW_UPDATENOW)
      {





         //if (GetExStyle() & WS_EX_LAYERED)
         {

            //_001UpdateWindow();

            //return true;

         }
         //else
         //{

         //   if (!is_window_visible() && !m_bShowFlags)
         //      return false;

         //   if (!is_window_visible())
         //   {

         //      if (m_iShowFlags & SWP_SHOWWINDOW)
         //      {

         //         display(e_display_normal);

         //      }

         //   }

         //   return ::set_need_redraw(get_hwnd(), pRectUpdate, prgnUpdate == nullptr ? nullptr : (HRGN)prgnUpdate->get_os_data(),

         //      flags | RDW_NOERASE | RDW_NOFRAME | RDW_INVALIDATE) != false;

         //}

      }
      else
      {

         puserinteraction->set_need_redraw();

      }

      return true;

   }





   //bool window::EnableScrollBar(int nSBFlags, unsigned int nArrowFlags)
   //{

   //   //ASSERT(::IsWindow(get_hwnd()));

   //   //return ::EnableScrollBar(get_hwnd(), nSBFlags, nArrowFlags) != false;

   //   return false;

   //}

   //bool window::DrawAnimatedRects(int idAni, const LPRECTprcFrom, const LPRECTlprcTo)

   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   return ::DrawAnimatedRects(get_hwnd(), idAni, prcFrom, lprcTo) != false;


   //}

   bool window::DrawCaption(::draw2d::graphics_pointer & pgraphics, const int_rectangle & prc, unsigned int uFlags)

   {

      //ASSERT(::IsWindow(get_hwnd()));

      throw ::interface_only();
      return false;
      //      return ::DrawCaption(get_hwnd(), (HDC)(dynamic_cast<::windows::graphics * >(pgraphics))->get_hwnd(), prc, uFlags) != false;


   }


   bool window::is_this_enabled()
   {

      //return ::IsWindowEnabled(get_hwnd()) != false;

      return true;

   }


   void window::enable_window(bool bEnable)
   {

      //return ::EnableWindow(get_hwnd(), bEnable) != false;

      //return false;

   }


   //void window::set_focus()
   //{

   //   HWND hwnd = get_hwnd();

   //   if (!::XXXSetFocus(hwnd))
   //   {

   //      return ::error_failed;
   //      
   //   }

   //   return ::success;

   //}




   //bool window::XXXSetFocus()
   //{

   //   if (!::IsWindow(get_hwnd()))
   //   {

   //      return false;

   //   }

   //   if (!::IsWindowVisible(get_hwnd()))
   //   {

   //      return false;

   //   }

   //   puserinteraction->post_procedure(__routine([this]()
   //      {

   //         HWND hwnd = ::XXXSetFocus(get_hwnd());

   //         ::output_debug_string("::windowing_universal_windows::window::XXXSetFocus ::XXXSetFocus(" + ::hex::lower_from((iptr)hwnd) + ")");

   //         return ::success;

   //      }));

   //   return true;

   //}


   //::user::interaction * window::get_desktop_window()
   //{

   //   return psystem->ui_from_handle(::get_desktop_window());

   //}


   // helper for radio buttons
   //int window::GetCheckedRadioButton(int nIDFirstButton, int nIDLastButton)
   //{
   //   for (int nID = nIDFirstButton; nID <= nIDLastButton; nID++)
   //   {
   //      if (IsDlgButtonChecked(nID))
   //         return nID; // atom that matched
   //   }
   //   return 0; // invalid ID
   //}


   //void window::CheckDlgButton(int nIDButton, unsigned int nCheck)
   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   ::CheckDlgButton(get_hwnd(), nIDButton, nCheck);

   //}


   //void window::CheckRadioButton(int nIDFirstButton, int nIDLastButton, int nIDCheckButton)
   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   ::CheckRadioButton(get_hwnd(), nIDFirstButton, nIDLastButton, nIDCheckButton);

   //}


   //int window::DlgDirList(TCHAR * pPathSpec, int nIDListBox, int nIDStaticPath, unsigned int nFileType)

   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   return ::DlgDirList(get_hwnd(), pPathSpec, nIDListBox, nIDStaticPath, nFileType);


   //}


   //int window::DlgDirListComboBox(TCHAR * pPathSpec, int nIDComboBox, int nIDStaticPath, unsigned int nFileType)

   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   return ::DlgDirListComboBox(get_hwnd(), pPathSpec, nIDComboBox, nIDStaticPath, nFileType);


   //}


   //bool window::DlgDirSelect(TCHAR * pString, int nSize, int nIDListBox)

   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   return ::DlgDirSelectEx(get_hwnd(), pString, nSize, nIDListBox) != false;


   //}


   //bool window::DlgDirSelectComboBox(TCHAR * pString, int nSize, int nIDComboBox)

   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   return ::DlgDirSelectComboBoxEx(get_hwnd(), pString, nSize, nIDComboBox) != false;


   //}


   //void window::get_child_by_id(atom atom, hwnd * poswindow_) const
   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   ASSERT(poswindow_ != nullptr);

   //   *poswindow_ = ::GetDlgItem(((window *)this)->get_hwnd(), (int)atom);

   //}


   //unsigned int window::GetChildByIdInt(int nID, BOOL * pTrans, bool bSigned) const

   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   return ::GetDlgItemInt(((window *)this)->get_hwnd(), nID, pTrans, bSigned);


   //}


   //int window::GetChildByIdText(int nID, TCHAR * pStr, int nMaxCount) const

   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   return ::GetDlgItemText(((window *)this)->get_hwnd(), nID, pStr, nMaxCount);


   //}


   //::user::window * window::GetNextDlgGroupItem(::user::window * pWndCtl, bool bPrevious) const
   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   return psystem->ui_from_handle(::GetNextDlgGroupItem(((window *)this)->get_hwnd(), pWndCtl->get_hwnd(), bPrevious));

   //}


   //::user::window * window::GetNextDlgTabItem(::user::window * pWndCtl, bool bPrevious) const
   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   return psystem->ui_from_handle(::GetNextDlgTabItem(((window *)this)->get_hwnd(), pWndCtl->get_hwnd(), bPrevious));

   //}


   //unsigned int window::IsDlgButtonChecked(int nIDButton) const
   //{
   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));
   //   return ::IsDlgButtonChecked(((window *)this)->get_hwnd(), nIDButton);
   //}


   //lparam window::SendDlgItemMessage(int nID, unsigned int message, wparam wParam, lparam lParam)
   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   return ::SendDlgItemMessage(((window *)this)->get_hwnd(), message, message, wParam, lParam);

   //}


   //void window::SetDlgItemInt(int nID, unsigned int nValue, bool bSigned)
   //{
   //   ASSERT(::IsWindow(get_hwnd()));
   //   ::SetDlgItemInt(get_hwnd(), nID, nValue, bSigned);
   //}
   //void window::SetDlgItemText(int nID, const ::string & pszString)

   //{
   //   ASSERT(::IsWindow(get_hwnd()));
   //   ::SetDlgItemTextW(get_hwnd(), nID, wstring(pszString));

   //}
   //int window::ScrollWindowEx(int dx, int dy,
   //   const ::int_rectangle * pRectScroll, const ::int_rectangle * lpRectClip,

   //   ::draw2d::region * prgnUpdate, ::int_rectangle * pRectUpdate, unsigned int flags)

   //{

   //   //ASSERT(::IsWindow(get_hwnd()));
   //   //return ::ScrollWindowEx(get_hwnd(), dx, dy, pRectScroll, lpRectClip,

   //   //                        (HRGN)prgnUpdate->get_os_data(), pRectUpdate, flags);

   //   return 0;


   //}

   //void window::ShowScrollBar(unsigned int nBar, bool bShow)
   //{
   //   ASSERT(::IsWindow(get_hwnd()));
   //   ::ShowScrollBar(get_hwnd(), nBar, bShow);
   //}
   //::user::interaction * window::ChildWindowFromPoint(const ::int_point & point)
   //{
   //   ASSERT(::IsWindow(get_hwnd()));

   //   return  psystem->ui_from_handle(::ChildWindowFromPoint(get_hwnd(), int_point));


   //}

   //::user::interaction * window::ChildWindowFromPoint(const ::int_point & point, unsigned int nFlags)
   //{
   //   ASSERT(::IsWindow(get_hwnd()));

   //   return  psystem->ui_from_handle(::ChildWindowFromPointEx(get_hwnd(), point, nFlags));


   //}



   ::windowing::window * window::get_next_window(unsigned int nFlag)
   {

      //HWND hwnd = get_hwnd();

      //HWND hwndNext = ::GetNextWindow(hwnd, nFlag);

      //auto pwindowing = windowing();

      //auto pwindowNext = pwindowing->_window(hwndNext);

      //return pwindowNext;

      return nullptr;

   }


   ::windowing::window * window::get_top_window() const
   {

      //HWND hwnd = get_hwnd();

      //HWND hwndTop = ::GetTopWindow(hwnd);

      //auto pwindowing = windowing();

      //auto pwindowTop = pwindowing->_window(hwndTop);

      //return pwindowTop;

      return nullptr;

   }


   ::windowing::window * window::get_window(unsigned int nCmd) const
   {

      //HWND hwnd = get_hwnd();

      //HWND hwndGet = ::GetWindow(hwnd, nCmd);

      //auto pwindowing = windowing();

      //auto pwindowGet = pwindowing->_window(hwndGet);

      //return pwindowGet;

      return nullptr;

   }


   ::windowing::window * window::get_last_active_popup() const
   {

      //HWND hwnd = get_hwnd();

      //HWND hwndLastActivePopup = ::GetLastActivePopup(hwnd);

      //auto pwindowing = windowing();

      //auto pwindowLastActivePopup = pwindowing->_window(hwndLastActivePopup);

      //return pwindowLastActivePopup;

      return nullptr;

   }


   //bool window::FlashWindow(bool bInvert)
   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   return ::FlashWindow(get_hwnd(), bInvert) != false;

   //}


   //bool window::ChangeClipboardChain(hwnd oswindow_Next)
   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   return ::ChangeClipboardChain(get_hwnd(), oswindow_Next) != false;

   //}


   //hwnd window::SetClipboardViewer()
   //{

   //   ASSERT(::IsWindow(get_hwnd()));

   //   return ::SetClipboardViewer(get_hwnd());

   //}


   //bool window::open_clipboard()
   //{

   //   if (m_bClipboardOpened)
   //   {

   //      return true;

   //   }

   //   if (!::OpenClipboard(get_hwnd()))
   //   {

   //      return false;

   //   }

   //   m_bClipboardOpened = true;

   //   return true;

   //}


   //bool window::close_clipboard()
   //{

   //   if (!m_bClipboardOpened)
   //   {

   //      return false;

   //   }

   //   if (!::CloseClipboard())
   //   {

   //      return false;

   //   }

   //   m_bClipboardOpened = false;

   //   return true;

   //}


   //::user::interaction * window::GetOpenClipboardWindow()
   //{

   //   return psystem->ui_from_handle(::GetOpenClipboardWindow());

   //}


   //::user::interaction * window::GetClipboardOwner()
   //{

   //   return psystem->ui_from_handle(::GetClipboardOwner());

   //}

   
   //::user::interaction * window::GetClipboardViewer()
   //{

   //   return psystem->ui_from_handle(::GetClipboardViewer());

   //}


   int_point window::GetCaretPos()
   {

      //::int_point point;

      //::GetCaretPos((POINT *)&point);

      //return point;

      return {};

   }


   void window::SetCaretPos(const ::int_point & point)
   {

      //::SetCaretPos(point.x, point.y);

   }


   void window::HideCaret()
   {

      //::HideCaret(get_hwnd());

   }


   void window::ShowCaret()
   {

      //::ShowCaret(get_hwnd());

   }

   
   //hicon window::SetIcon(hicon hIcon, bool bBigIcon)
   //{

   //   return (hicon)send_message(WM_SETICON, bBigIcon, (lparam)hIcon);

   //}

   //hicon window::GetIcon(bool bBigIcon) const
   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   return (hicon)const_cast <::windowing_universal_windows::window *> (this)->send_message(WM_GETICON, bBigIcon);

   //}

   //void window::Print(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const
   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   throw ::interface_only();
   //   //      const_cast < ::windowing_universal_windows::window * > (this)->send_message(WM_PRINT, (wparam)(dynamic_cast<::windows::graphics * >(pgraphics))->get_hwnd(), (lparam) dwFlags);

   //}

   //void window::PrintClient(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const
   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   throw ::interface_only();
   //   //const_cast < ::windowing_universal_windows::window * > (this)->send_message(WM_PRINTCLIENT, (wparam)(dynamic_cast<::windows::graphics * >(pgraphics))->get_hwnd(), (lparam) dwFlags);

   //}

   //bool window::SetWindowContextHelpId(unsigned int dwContextHelpId)
   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   return ::SetWindowContextHelpId(((window *)this)->get_hwnd(), dwContextHelpId) != false;

   //}

   //unsigned int window::GetWindowContextHelpId() const
   //{

   //   ASSERT(::IsWindow(((window *)this)->get_hwnd()));

   //   return ::GetWindowContextHelpId(((window *)this)->get_hwnd());

   //}


   // Default message map implementations
      //void window::OnActivateApp(bool, unsigned int)
      //{
      //   Default();
      //}
      //void window::OnActivate(unsigned int, ::user::window *, bool)
      //{
      //   Default();
      //}
      //void window::OnCancelMode()
      //{
      //   Default();
      //}
      //void window::OnChildActivate()
      //{
      //   Default();
      //}
      //void window::OnClose()
      //{
      //   Default();
      //}
      //void window::OnContextMenu(::user::window *, int_point)
      //{
      //   Default();
      //}

      //bool window::OnCopyData(::user::window *, COPYDATASTRUCT*)
      //{

      //   return Default() != false;

      //}

      //void window::OnEnable(bool)
      //{
      //   Default();
      //}
      //void window::OnEndSession(bool)
      //{
      //   Default();
      //}

      //bool window::OnEraseBkgnd(::draw2d::graphics *)
      //{

      //   return Default() != false;

      //}

      //void window::OnGetMinMaxInfo(MINMAXINFO*)
      //{
      //   Default();
      //}
      //void window::OnIconEraseBkgnd(::draw2d::graphics *)
      //{
      //   Default();
      //}


   //void window::on_message_set_focus(::message::message * pmessage)
   //{

   //   //m_bFocusImpl = true;

   //   //if (!m_bSystemCaret)
   //   //{

   //   //   m_bSystemCaret = true;

   //   //}

   //}


   //void window::on_message_kill_focus(::message::message * pmessage)
   //{

   //   //m_bFocusImpl = false;

   //   //if (m_bSystemCaret)
   //   //{

   //   //   m_bSystemCaret = false;

   //   //   ::DestroyCaret();

   //   //}

   //}


   //lresult window::OnMenuChar(unsigned int, unsigned int, ::user::menu*)
   //{

   //   return Default();

   //}


   //void window::OnMenuSelect(unsigned int, unsigned int, HMENU)
   //{

   //   Default();

   //}


   //void window::OnMove(int, int)
   //{

   //   Default();

   //}


   //hcursor window::OnQueryDragIcon()
   //{

   //   return (hcursor)Default();

   //}

   //bool window::OnQueryEndSession()
   //{

   //   return Default() != false;

   //}

   //bool window::OnQueryNewPalette()
   //{

   //   return Default() != false;

   //}

   //bool window::OnQueryOpen()
   //{

   //   return Default() != false;

   //}

   //void window::on_message_set_cursor(::message::message * pmessage)
   //{

   //   if (m_pcursor != nullptr)
   //   {

   //      set_cursor(m_pcursor);

   //      pmessage->m_lresult = TRUE;

   //      pmessage->m_bRet = true;

   //   }

   //}


   //void window::OnShowWindow(bool, unsigned int)
   //{

   //   Default();

   //}


   //void window::OnSize(unsigned int, int, int)
   //{

   //   Default();

   //}


   //void window::OnTCard(unsigned int, unsigned int)
   //{

   //   Default();

   //}


   void window::_001OnWindowPosChanging(::message::message * pmessage)
   {

      return;


   }


   void window::_001OnWindowPosChanged(::message::message * pmessage)
   {

      //WINDOWPOS * pwindowpos = (WINDOWPOS *)pmessage->m_lparam.m_lparam;

      //output_debug_string("\ninteraction_impl::_001OnWindowPosChanged");

      //if (::IsIconic(get_hwnd()))
      //{

      //   auto puserinteraction = user_interaction();

      //   if (puserinteraction->layout().sketch().display() != ::e_display_iconic)
      //   {

      //      output_debug_string(" IsIconic or not IsIconic, thats the question window::_001OnWindowPosChanged");

      //   }

      //}
      //else if (::IsZoomed(get_hwnd()))
      //{

      //   auto puserinteraction = user_interaction();

      //   if (puserinteraction->layout().window().display() != ::e_display_zoomed)
      //   {

      //      output_debug_string(" IsZoomed or not IsZoomed, thats the question window::_001OnWindowPosChanged");

      //   }

      //}


      ////if (m_bDestroyImplOnly)
      ////{

      ////   return;

      ////}

      //auto puserinteraction = user_interaction();

      //if (puserinteraction->layout().m_eflag)
      //{

      //   return;

      //}

      //::int_point point(pwindowpos->x, pwindowpos->y);

      //bool bMove = false;

      //if (puserinteraction->layout().sketch().origin() != point)
      //{

      //   if (puserinteraction->layout().is_moving())
      //   {

      //      information() << "Window is Moving :: on_message_move";

      //   }

      //   puserinteraction->layout().sketch().origin() = point;

      //   bMove = true;

      //}

      //::int_size size(pwindowpos->cx, pwindowpos->cy);

      //bool bSize = false;

      //if (puserinteraction->layout().sketch().size() != size)
      //{

      //   puserinteraction->layout().sketch().size() = size;

      //   bSize = true;

      //}

      //if (bMove)
      //{

      //   puserinteraction->set_reposition();

      //   puserinteraction->set_need_redraw();

      //}

      //if (bSize)
      //{

      //   puserinteraction->set_need_layout();

      //}

      //if (bMove || bSize)
      //{

      //   puserinteraction->set_need_redraw();

      //}


      //pmessage->m_bRet = true;

   }


   //void window::_001OnGetMinMaxInfo(::message::message * pmessage)
   //{

   //   ::pointer<::message::message>pmessage(pmessage);

   //}

   //   void window::OnDropFiles(HDROP)
   //   {
   //      Default();
   //   }
   //   void window::OnPaletteIsChanging(::user::window *)
   //   {
   //      Default();
   //   }
   //
   //   bool window::OnNcActivate(bool)
   //   {
   //
   //      return Default() != false;
   //
   //   }
   //
   //   void window::OnNcCalcSize(bool, NCCALCSIZE_PARAMS*)
   //   {
   //      Default();
   //   }
   //
   //   bool window::OnNcCreate(::user::system *)
   //   {
   //
   //      return Default() != false;
   //
   //   }
   //
   //   lresult window::OnNcHitTest(const int_point & )
   //   {
   //      return Default();
   //   }
   //   void window::OnNcLButtonDblClk(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnNcLButtonDown(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnNcLButtonUp(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnNcMButtonDblClk(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnNcMButtonDown(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnNcMButtonUp(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnNcMouseMove(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnNcPaint()
   //   {
   //      Default();
   //   }
   //   void window::OnNcRButtonDblClk(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnNcRButtonDown(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnNcRButtonUp(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnSysChar(unsigned int, unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnSysCommand(unsigned int, lparam)
   //   {
   //      Default();
   //   }
   //   void window::OnSysDeadChar(unsigned int, unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnSysKeyDown(unsigned int, unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnSysKeyUp(unsigned int, unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnCompacting(unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnFontChange()
   //   {
   //      Default();
   //   }
   //   void window::OnPaletteChanged(::user::window *)
   //   {
   //      Default();
   //   }
   //   void window::OnSpoolerStatus(unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnTimeChange()
   //   {
   //      Default();
   //   }
   //   void window::OnChar(unsigned int, unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnDeadChar(unsigned int, unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnKeyDown(unsigned int, unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnKeyUp(unsigned int, unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnLButtonDblClk(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnLButtonDown(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnLButtonUp(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnMButtonDblClk(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnMButtonDown(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnMButtonUp(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   int window::OnMouseActivate(::user::window *, unsigned int, unsigned int)
   //   {
   //      return (int)Default();
   //   }
   //   void window::OnMouseMove(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //
   //   bool window::OnMouseWheel(unsigned int, short, const int_point&)
   //   {
   //
   //      return Default() != false;
   //
   //   }
   //
   //   lresult window::OnRegisteredMouseWheel(wparam, lparam)
   //   {
   //      return Default();
   //   }
   //   void window::OnRButtonDblClk(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnRButtonDown(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnRButtonUp(unsigned int, const int_point&)
   //   {
   //      Default();
   //   }
   //   void window::OnTimer(uptr)
   //   {
   //      Default();
   //   }
   //   void window::OnInitMenu(::user::menu*)
   //   {
   //      Default();
   //   }
   //   void window::OnInitMenuPopup(::user::menu*, unsigned int, bool)
   //   {
   //      Default();
   //   }
   //   void window::OnAskCbFormatName(__in unsigned int nMaxCount, __out_ecount_z(nMaxCount) char * lpszName)
   //   {
   //      (nMaxCount);
   //      if (nMaxCount > 0)
   //      {
   //         /* defwindow proc should do this for us, but to be safe, we'hi do it here too */
   //         lpszName[0] = '\0';
   //      }
   //      Default();
   //   }
   //   void window::OnChangeCbChain(hwnd, hwnd)
   //   {
   //      Default();
   //   }
   //   void window::OnDestroyClipboard()
   //   {
   //      Default();
   //   }
   //   void window::OnDrawClipboard()
   //   {
   //      Default();
   //   }
   //   void window::OnHScrollClipboard(::user::window *, unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnPaintClipboard(::user::window *, HGLOBAL)
   //   {
   //      Default();
   //   }
   //   void window::OnRenderAllFormats()
   //   {
   //      Default();
   //   }
   //   void window::OnRenderFormat(unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnSizeClipboard(::user::window *, HGLOBAL)
   //   {
   //      Default();
   //   }
   //   void window::OnVScrollClipboard(::user::window *, unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   unsigned int window::OnGetDlgCode()
   //   {
   //      return (unsigned int)Default();
   //   }
   //   void window::OnMDIActivate(bool, ::user::window *, ::user::window *)
   //   {
   //      Default();
   //   }
   //   void window::OnEnterMenuLoop(bool)
   //   {
   //      Default();
   //   }
   //   void window::OnExitMenuLoop(bool)
   //   {
   //      Default();
   //   }
   //// Win4 support
   //   void window::OnStyleChanged(int, LPSTYLESTRUCT)
   //   {
   //      Default();
   //   }
   //   void window::OnStyleChanging(int, LPSTYLESTRUCT)
   //   {
   //      Default();
   //   }
   //   void window::OnSizing(unsigned int, ::int_rectangle *)
   //   {
   //      Default();
   //   }
   //   void window::OnMoving(unsigned int, ::int_rectangle *)
   //   {
   //      Default();
   //   }
   //   void window::OnCaptureChanged(::user::window *)
   //   {
   //      Default();
   //   }
   //
   //   bool window::OnDeviceChange(unsigned int, uptr)
   //   {
   //
   //      return Default() != false;
   //
   //   }
   //
   //   void window::OnWinIniChange(const ::string &)
   //   {
   //      Default();
   //   }
   //   void window::OnChangeUIState(unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   void window::OnUpdateUIState(unsigned int, unsigned int)
   //   {
   //      Default();
   //   }
   //   unsigned int window::OnQueryUIState()
   //   {
   //      return (unsigned int)Default();
   //   }

   // window dialog data support
   //    void window::do_data_exchange(CDataExchange*)
   //   { } // default does nothing

   // window modality support

   void window::BeginModalState()
   {

      //::EnableWindow(get_hwnd(), false);

   }

   void window::EndModalState()
   {

      //::EnableWindow(get_hwnd(), true);

   }

   // frame_window
      /*    void frame_window::DelayUpdateFrameTitle()
      { m_nIdleFlags |= idleTitle; }
      void frame_window::DelayRecalcLayout(bool bNotify)
      { m_nIdleFlags |= (idleLayout | (bNotify ? idleNotify : 0)); };
      bool frame_window::InModalState() const
      { return m_cModalStack != 0; }
      void frame_window::set_title(const ::string & pszTitle)

      { m_strTitle = pszTitle; }

      string frame_window::get_title() const
      { return m_strTitle; }
      */



   void window::CloseWindow()
   {
      //ASSERT(::IsWindow(get_hwnd()));
      //::CloseWindow(get_hwnd());
   }

   bool window::OpenIcon()
   {

      //ASSERT(::IsWindow(get_hwnd()));

      //return ::OpenIcon(get_hwnd()) != false;


      return false;
   }


   //////////////////////////////////////////////////////////////////////////////
   //// UI related window functions


   //hwnd window::get_safe_owner(hwnd hParent, hwnd * pWndTop)
   //{
   //   // get window to start with
   //   HWND hwnd = hParent;
   //   if (hwnd == nullptr)
   //   {
   //      /* trans      ::pointer<::user::frame_window>pFrame = channel::GetRoutingFrame_();
   //      if (pFrame != nullptr)
   //      hwnd = pFrame->get_hwnd();
   //      else
   //      hwnd = psystem->m_puiMain->get_hwnd();*/
   //   }

   //   // a popup window cannot be owned by a child window
   //   while (hwnd != nullptr && (::GetWindowLong(hwnd, GWL_STYLE) & WS_CHILD))
   //   {

   //      hwnd = ::GetParent(hwnd);

   //   }

   //   // determine toplevel window to disable as well
   //   ::hwnd oswindow_Top = hwnd;
   //   ::hwnd oswindow_Temp = hwnd;
   //   for (;;)
   //   {
   //      if (oswindow_Temp == nullptr)
   //         break;
   //      else
   //         oswindow_Top = oswindow_Temp;
   //      oswindow_Temp = ::GetParent(oswindow_Top);
   //   }

   //   // get last active popup of first non-child that was found
   //   if (hParent == nullptr && hwnd != nullptr)
   //      hwnd = ::GetLastActivePopup(hwnd);

   //   // disable and store top level parent window if specified
   //   if (pWndTop != nullptr)
   //   {
   //      if (oswindow_Top != nullptr && ::IsWindowEnabled(oswindow_Top) && oswindow_Top != hwnd)
   //      {
   //         *pWndTop = oswindow_Top;
   //         ::EnableWindow(oswindow_Top, false);
   //      }
   //      else
   //         *pWndTop = nullptr;
   //   }

   //   return hwnd;    // return the owner as hwnd
   //}


   //lresult CALLBACK __cbt_filter_hook(int code, wparam wParam, lparam lParam)
   //{

   //   if (code != HCBT_CREATEWND)
   //   {

   //      goto call_next_hook;

   //   }

   //   ASSERT(lParam != 0);

   //   ::user::system * pcs = (::user::system *) ((LPCBT_CREATEWND)lParam)->lpcs;

   //   ASSERT(pcs != nullptr);

   //   ::windowing_universal_windows::window * puserinteraction = thread_set("wnd_init");

   //   if (puserinteraction != nullptr || (!(pcs->style & WS_CHILD)))
   //   {

   //      thread_set("wnd_init") = nullptr;

   //      // Note: special check to avoid subclassing the IME window
   //      //if (gen_DBCS)
   //      {
   //         // check for cheap CS_IME style first...
   //         if (GetClassLongW((hwnd)wParam, GCL_STYLE) & CS_IME)
   //         {

   //            goto call_next_hook;

   //         }

   //         const wchar_t * pszClassName;

   //         wchar_t szClassName[128] = {};

   //         if(uptr(pcs->lpszClass) > 0xffff)
   //         {

   //            pszClassName = pcs->lpszClass;

   //         }
   //         else
   //         {

   //            ::GlobalGetAtomNameW((ATOM)(uptr)pcs->lpszClass, szClassName, _countof(szClassName));

   //            pszClassName = szClassName;

   //         }

   //         // a little more expensive to test this way, but necessary...
   //         if (wide_find_string_case_insensitive(pszClassName, L"ime") != 0)
   //         {
   //          
   //            goto call_next_hook;

   //         }

   //      }

   //      ASSERT(wParam != 0);

   //      ::HWND hwnd = (::hwnd) wParam;

   //      if (puserinteraction != nullptr)
   //      {

   //         ASSERT(oswindow_get(hwnd) == nullptr);

   //         puserinteraction->puserinteraction->m_pinteractionimpl = puserinteraction;

   //         puserinteraction->attach(hwnd);

   //         puserinteraction->pre_subclass_window();

   //         WNDPROC * ppuserinteractionprocSuper = puserinteraction->GetSuperWndProcAddr();

   //         ASSERT(ppuserinteractionprocSuper != nullptr);

   //         WNDPROC puserinteractionprocOld = (WNDPROC)SetWindowLongPtrW(hwnd, GWLP_WNDPROC, (uptr)get_window_procedure();

   //         ASSERT(puserinteractionprocOld != nullptr);

   //         if (puserinteractionprocOld != get_window_procedure())
   //         {

   //            *ppuserinteractionprocSuper = puserinteractionprocOld;

   //         }

   //      }

   //   }

   //call_next_hook:

   //   lresult lResult = CallNextHookEx(t_hHookOldCbtFilter, code, wParam, lParam);

   //   return lResult;

   //}


   // void window::_001OnEraseBkgnd(::message::message * pmessage)
   // {
   //    ::pointer<::message::erase_bkgnd>perasebkgnd(pmessage);
   //    perasebkgnd->m_bRet = true;
   //    perasebkgnd->set_result(true);
   // }

   
   void window::on_message_get_icon(::message::message * pmessage)
   {

      if (pmessage->m_wparam == ICON_BIG)
      {

         if (m_picon)
         {

            ::int_size size;

            //size.cx = GetSystemMetrics(SM_CXICON);
            //size.cy = GetSystemMetrics(SM_CYICON);

            //HICON hicon = (HICON)m_picon->get_os_data(size);

//            pmessage->m_lresult = (LRESULT)hicon;

            pmessage->m_bRet = true;

         }

      }
      else if (pmessage->m_wparam == ICON_SMALL
         || pmessage->m_wparam == ICON_SMALL2)
      {

         if (m_picon)
         {

            ::int_size size;

            //size.cx = GetSystemMetrics(SM_CXSMICON);
            //size.cy = GetSystemMetrics(SM_CYSMICON);

            //HICON hicon = (HICON)m_picon->get_os_data(size);

            //pmessage->m_lresult = (LRESULT)hicon;

            pmessage->m_bRet = true;

         }

      }

   }


   void window::track_mouse_hover()
   {

      if (m_bTransparentMouseEvents)
      {

         m_bTrackMouseLeave = true;

         return;

      }

      //TRACKMOUSEEVENT tme = { sizeof(tme) };
      //tme.dwFlags = TME_LEAVE;
      //tme.hwndTrack = get_hwnd();
      //TrackMouseEvent(&tme);

      track_mouse_leave();

   }


   void window::set_context_org(::draw2d::graphics_pointer & pgraphics)
   {

      // graphics will be already set its window port to the window for linux - cairo with xlib

      pgraphics->set_origin(::int_point());

   }


   void window::on_set_parent(::user::interaction * puserinteraction) 
   {

      throw ::interface_only();

   }

    //// virtual void register_drop_target();
    //void window::show_task(bool bShow)
    //{

    //   throw ::interface_only();

    //}
    //

    void window::_window_show_change_visibility(::e_display edisplay, const ::user::activation & useractivation)
    {

       throw ::interface_only();

    }



   /*

/*   void window::_001DeferPaintLayeredWindowBackground(::image::image * pimage)
   {


   }

   */



   //bool window::get_rect_normal(::int_rectangle * prectangle)

   //{

   //   WINDOWPLACEMENT wp;

   //   zero(wp);

   //   if (!GetWindowPlacement(&wp))
   //      return false;

   //   *prectangle = wp.rcNormalPosition;


   //   return true;

   //}


   //DWORD WINAPI drop_target(LPVOID int_point)
   //{

   //   window * pimpl = (window *)int_point;

   //   HRESULT hr = OleInitialize(nullptr);

   //   hr = ::RegisterDragDrop(pimpl->get_hwnd(), pimpl);

   //   if (SUCCEEDED(CoCreateInstance(CLSID_DragDropHelper, nullptr,
   //      CLSCTX_INPROC_SERVER,
   //      IID_IDropTargetHelper,
   //      (void **)&pimpl->m_piDropHelper)))
   //   {
   //      pimpl->m_bUseDnDHelper = true;
   //   }

   //   MSG msg;

   //   while (::GetMessage(&msg, nullptr, 0, 0xffffffffu))
   //   {

   //      TranslateMessage(&msg);

   //      DispatchMessage(&msg);

   //   }

   //   return 0;

   //}


   //void window::register_drop_target()
   //{
   //   m_bUseDnDHelper = false;

   //   ::CreateThread(nullptr, 0, drop_target, this, 0, nullptr);


   //}


   void window::show_task(bool bShow)
   {

      synchronous_lock synchronouslock(synchronization());

      // https://www.daniweb.com/programming/software-development/threads/457564/mfc-window-disablehide-taskbar-icon

      //if (bShow)
      //{

      //   _modify_ex_style(WS_EX_TOOLWINDOW, 0, SWP_FRAMECHANGED);

      //}
      //else
      //{

      //   _modify_ex_style(0, WS_EX_TOOLWINDOW, SWP_FRAMECHANGED);

      //}

      node()->defer_co_initialize_ex(false);

      //comptr < ITaskbarList>                     tasklist;

      //HRESULT hr = tasklist.CoCreateInstance(CLSID_TaskbarList, nullptr, CLSCTX_INPROC_SERVER);

      //if (SUCCEEDED(hr) && SUCCEEDED(hr = tasklist->HrInit()))
      //{

      //   if (bShow)
      //   {

      //      hr = tasklist->AddTab(get_hwnd());

      //      informationf("result = %d", hr);

      //   }
      //   else
      //   {

      //      tasklist->DeleteTab(get_hwnd());

      //   }

      //}

   }


   /*bool window::set_window_position(class ::user::zorder zorder, int x, int y, int cx, int cy, unsigned int nFlags)
   {

      if (!::user::window::set_window_position(zorder, x, y, cx, cy, nFlags))
      {

         return false;

      }

      if (!(GetExStyle() & WS_EX_LAYERED))
      {


         if (!::set_window_position(get_hwnd(), zorder, x, y, cx, cy, nFlags))
         {

            return false;

         }

      }

      return true;

   }
*/


   //void window::window_show_change_visibility(::e_display edisplay, const ::user::activation & useractivation)
   //{

   //   ::user::window::window_show_change_visibility(edisplay, useractivation);

   //}


   void window::_001OnActivate(::message::message * pmessage)
   {

      BOOL enabled = false;

      //DwmIsCompositionEnabled(&enabled);

      ////data->composition_enabled = enabled;

      //if (enabled)
      //{

      //   /* The u needs a frame to show a shadow, so give it the smallest amount of frame possible */

      //   MARGINS m = { 0,0,0,0 };

      //   unsigned int  dw = DWMNCRP_ENABLED;

      //   HWND hwnd = get_hwnd();

      //   DwmExtendFrameIntoClientArea(hwnd, &m);

      //   DwmSetWindowAttribute(hwnd, DWMWA_NCRENDERING_POLICY, &dw, sizeof(unsigned int));

      //}
      //else
      //{

      //}

   }


   void window::_001OnDwmNcRenderingChanged(::message::message * pmessage)
   {

      //#ifdef WINDOWS_DESKTOP

      wparam wparam;

      lparam lparam;

      wparam = pmessage->m_wparam;

      lparam = pmessage->m_lparam;

      //return Default();

      //BOOL enabled = false;

      //DwmIsCompositionEnabled(&enabled);

      ////data->composition_enabled = enabled;

      //if (enabled)
      //{

      //   /* The u needs a frame to show a shadow, so give it the smallest amount of frame possible */

      //   MARGINS m = { 0,0,0,0 };

      //   unsigned int  dw = DWMNCRP_ENABLED;

      //   HWND hwnd = get_hwnd();

      //   DwmExtendFrameIntoClientArea(hwnd, &m);

      //   DwmSetWindowAttribute(hwnd, DWMWA_NCRENDERING_POLICY, &dw, sizeof(unsigned int));

      //}
      //else
      //{

      //}

      ////update_region(data);
      ////      long dwEx = ::GetWindowLong(GetSafeHwnd(),GWL_EXSTYLE);
      ////      dwEx &= ~(WS_EX_LAYERED);
      ////      ::SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,dwEx);
      ////      ::InvalidateRect(GetSafeHwnd(),nullptr,true);
      ////      ::UpdateWindow(GetSafeHwnd());
      ////      //MoveAnchorsImmediatelly(hwndDlg);
      //pmessage->m_bRet = true;

      //pmessage->m_lresult = 0;

      ////#endif

   }


   void window::on_message_non_client_calculate_size(::message::message * pmessage)
   {

      //::pointer<::message::nc_calc_size>pcalcsize(pmessage);

      //BOOL bCalcValidRects = pcalcsize->GetCalcValidRects();

      //NCCALCSIZE_PARAMS * pncsp = (NCCALCSIZE_PARAMS *) pcalcsize->m_pNCCALCSIZE_PARAMS;

      // TODO: Add your message handler code here and/or call default
      //if(bCalcValidRects)
      //{
      //   informationf("1");
      //   pncsp->rgrc[0].left() = lpncsp->lppos->x + 1;

      //   pncsp->rgrc[0].right() = lpncsp->lppos->x + lpncsp->lppos->cx - 1;

      //   pncsp->rgrc[0].top() = lpncsp->lppos->y + 32;

      //   pncsp->rgrc[0].bottom() = lpncsp->lppos->y + lpncsp->lppos->cy - 1;

      //}
      //else
      //{
      //   CRect * prectangle = (CRect *) pncsp;

      //   prectangle->top() += 32;
      //   prectangle->left()++;
      //   prectangle->bottom()--;
      //   prectangle->right()--;

      //   informationf("2");
      //}
      //const int_rectangle & nonclient = pncsp->rgrc[0];

      ////CMiniFrameWnd::OnNcCalcSize(bCalcValidRects, pncsp);

      //const int_rectangle & client = pncsp->rgrc[0];

      //if (is_zoomed())
      //{

      //   WINDOWINFO wi = {};
      //   wi.cbSize = sizeof(wi);

      //   HWND hwnd = get_hwnd();

      //   ::GetWindowInfo(hwnd, &wi);

      //   /* Maximized windows always have a non-client border that hangs over
      //   the edge of the screen, so the int_size proposed by e_message_non_client_calc_size is
      //   fine. Just adjust the top border to erase the u title. */
      //   pncsp->rgrc[0].left() = client.left();

      //   pncsp->rgrc[0].top() = nonclient.top() + wi.cyWindowBorders;

      //   pncsp->rgrc[0].right() = client.right();

      //   pncsp->rgrc[0].bottom() = client.bottom();


      //   HMONITOR mon = MonitorFromWindow(hwnd, MONITOR_DEFAULTTOPRIMARY);
      //   MONITORINFO mi = {};
      //   mi.cbSize = sizeof(mi);
      //   GetMonitorInfoW(mon, &mi);

      //   /* If the client int_rectangle is the same as the monitor's rectangle,
      //   the shell assumes that the u has gone fullscreen, so it erases
      //   the topmost attribute from any auto-hide appbars, making them
      //   inaccessible. To avoid this, reduce the int_size of the client area by
      //   one pixel on a certain edge. The edge is chosen based on which side
      //   of the monitor is likely to contain an auto-hide appbar, so the
      //   missing client area is covered by it. */
      //   if (EqualRect(&pncsp->rgrc[0], &mi.rcMonitor))

      //   {
      //      if (has_autohide_appbar(ABE_BOTTOM, mi.rcMonitor))
      //         pncsp->rgrc[0].bottom()--;

      //      else if (has_autohide_appbar(ABE_LEFT, mi.rcMonitor))
      //         pncsp->rgrc[0].left()++;

      //      else if (has_autohide_appbar(ABE_TOP, mi.rcMonitor))
      //         pncsp->rgrc[0].top()++;

      //      else if (has_autohide_appbar(ABE_RIGHT, mi.rcMonitor))
      //         pncsp->rgrc[0].right()--;

      //   }
      //}
      //else
      //{
      //   /* For the non-maximized case, set the output const int_rectangle & to what it was
      //   before e_message_non_client_calc_size modified it. This will make the client int_size the
      //   same as the non-client size. */
      //   __copy(pncsp->rgrc[0],nonclient);


      //}


      ////::pointer<::message::message>pmessage(pmessage);

      //pcalcsize->m_lresult = 0;

      //pcalcsize->m_bRet = true;

      //#endif

   }



   //void window::default_message_handler(::message::message * pmessage)
   //{

   //   if (get_hwnd() == nullptr)
   //   {

   //      return;

   //   }

   //   WNDPROC pfnWndProc = *GetSuperWndProcAddr();

   //   lresult lresult = 0;

   //   if (pfnWndProc == nullptr)
   //   {

   //      lresult = ::DefWindowProcW(m_oswindow, (unsigned int)pmessage->m_emessage.long_long(), pmessage->m_wparam, pmessage->m_lparam);

   //   }
   //   else
   //   {

   //      lresult = ::CallWindowProc(pfnWndProc, m_oswindow, (unsigned int)pmessage->m_emessage.long_long(), pmessage->m_wparam, pmessage->m_lparam);

   //   }

   //   pmessage->m_lresult = lresult;

   //}


   void window::set_icon(::windowing::icon * picon)
   {

      //auto estatus = 
      
      ::windowing::window::set_icon(picon);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

    /*  m_hiconSmall = nullptr;

      m_hiconBig = nullptr;

      if (::is_set(picon))
      {

         ::int_size sizeSmall;
           
         sizeSmall.cx = GetSystemMetrics(SM_CXSMICON);
         sizeSmall.cy = GetSystemMetrics(SM_CYSMICON);

         m_hiconSmall = (HICON) picon->get_os_data(sizeSmall);

         ::int_size sizeBig;

         sizeBig.cx = GetSystemMetrics(SM_CXICON);
         sizeBig.cy = GetSystemMetrics(SM_CYICON);

         m_hiconBig = (HICON) picon->get_os_data(sizeBig);

      }*/

      // HWND hwnd = get_hwnd();

      //SendMessage(hwnd, WM_SETICON, ICON_SMALL, 0);

      //SendMessage(hwnd, WM_SETICON, ICON_BIG, 0);

      //if (hiconSmall)
      //{

      //   ::SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hiconSmall);

      //}

      ////if (hiconBig)
      //{

      //   ::SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hiconBig);

      //}

      //return true;

   }


//   void window::message_handler(::message::message * pmessage)
//   {
//
//      if (::is_set(puserinteraction))
//      {
//
//         puserinteraction->pre_translate_message(pmessage);
//
//      }
//
//      if (pmessage->m_bRet)
//      {
//
//         return;
//
//      }
//
//      unsigned int message;
//
//      message = pmessage->m_emessage.umessage();
//
//      m_uiMessage = message;
//
//      m_wparam = pmessage->m_wparam;
//
//      m_lparam = pmessage->m_lparam;
//
//      if (message == WM_IME_SETCONTEXT)
//      {
//
//         if (m_wparam == 1)
//         {
//
//            m_lparam &= ~ISC_SHOWUICOMPOSITIONWINDOW;
//
//         }
//
//         pmessage->m_lresult = ::DefWindowProcW(m_oswindow, m_uiMessage, m_wparam, m_lparam);
//
//         pmessage->m_bRet = true;
//
//         return;
//
//      }
//
//      bool bUserElementalOk = !m_bDestroyImplOnly && puserinteraction && puserinteraction->m_bUserElementOk;
//
//      if (message == e_message_key_down ||
//         message == e_message_key_up ||
//         message == e_message_char ||
//         message == e_message_sys_key_down ||
//         message == e_message_sys_key_up ||
//         message == e_message_sys_char ||
//         message == WM_IME_KEYDOWN ||
//         message == WM_IME_SETCONTEXT ||
//         message == WM_IME_SELECT ||
//         message == WM_IME_KEYUP ||
//         message == WM_IME_CHAR ||
//         message == WM_IME_STARTCOMPOSITION ||
//         message == WM_IME_COMPOSITION ||
//         message == WM_IME_COMPOSITIONFULL ||
//         message == WM_IME_NOTIFY ||
//         message == WM_IME_ENDCOMPOSITION)
//      {
//
//         auto pkey = pmessage->m_pkey;
//
//         if (message == e_message_key_down)
//         {
//
//            output_debug_string("\n Key Down Event ");
//
//         }
//
//         
//
//         if (message == e_message_key_down || message == e_message_sys_key_down)
//         {
//            try
//            {
//               psession->set_key_pressed(pkey->m_ekey, true);
//            }
//            catch (...)
//            {
//            }
//         }
//         else if (message == e_message_key_up || message == e_message_sys_key_up)
//         {
//
//            try
//            {
//
//               psession->set_key_pressed(pkey->m_ekey, false);
//
//            }
//            catch (...)
//            {
//
//            }
//
//         }
//
//      }
//
//      if (message == e_message_timer)
//      {
//         //         puserinteraction->get_application()->step_timer();
//      }
//      else if (message == e_message_left_button_down)
//      {
//         ::int_rectangle rectangleX;
//         ::GetClientRect(get_hwnd(), rectangleX);
//         ::int_rectangle rectangleWindow;
//         ::GetWindowRect(get_hwnd(), rectangleWindow);
//         ::int_rectangle rectangleRegion;
//         HRGN hrgn = CreateRectRgn(0, 0, 0, 0);
//         int regionType = ::GetWindowRgn(get_hwnd(), hrgn);
//         if (regionType != ERROR)
//         {
//            ::GetRgnBox(hrgn, rectangleRegion);
//         }
//         ::DeleteObject(hrgn); /* finished with region */
//         WINDOWPLACEMENT wp;
//         zero(wp);
//         wp.length = sizeof(WINDOWPLACEMENT);
//         ::GetWindowPlacement(get_hwnd(), &wp);
//         bool bZoomed = ::IsZoomed(get_hwnd()) != false;
//         bool bIconic = ::IsIconic(get_hwnd()) != false;
//      }
//      else if (message == e_message_set_cursor
//         || message == e_message_non_client_mouse_move)
//      {
//         //output_debug_string(".");
//      }
//      else
//      {
//
//#ifdef _DEBUG
//
//         if (0)
//         {
//            switch (message)
//            {
//            case e_message_create:
//               informationf("e_message_create wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            case e_message_window_position_changing:
//               informationf("e_message_window_position_changing wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            case e_message_window_position_changed:
//               informationf("e_message_window_position_changed wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            case e_message_activate:
//               informationf("e_message_activate wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            case WM_ACTIVATEAPP:
//               informationf("WM_ACTIVATEAPP wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            case e_message_mouse_activate:
//               informationf("e_message_mouse_activate wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            case e_message_non_client_activate:
//               informationf("e_message_non_client_activate wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            case e_message_set_focus:
//               informationf("e_message_set_focus wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            case e_message_kill_focus:
//               informationf("e_message_kill_focus wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            case e_message_move:
//               informationf("e_message_move wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            case e_message_size:
//               informationf("e_message_size wparam=%08x lparam=%08x", pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            default:
//               informationf("MESSAGE %08x wparam=%08x lparam=%08x", message, pmessage->m_wparam, pmessage->m_lparam);
//
//               break;
//            }
//
//         }
//
//#endif //__DEBUG
//
//      }
//
//      //
//
//
//
//      /*      else if(message == CA2M_BERGEDGE)
//      {
//      if(pmessage->m_wparam == BERGEDGE_GETAPP)
//      {
//      ::pointer<::aura::window> ppapp= (::pointer<::aura::window> pmessage->m_lparam;
//      *ppapp = get_application();
//      pmessage->m_bRet = true;
//      return;
//      }
//      }*/
//      //pmessage->set_lresult(0);
//
//      if (message == e_message_mouse_leave)
//      {
//
//         auto papexsession = get_session();
//
//         ::aura::session * psession = nullptr;
//
//         if (papexsession)
//         {
//
//            psession = papexsession;
//
//         }
//
//         if (psession && psession->m_puiCapture)
//         {
//
//            psession->m_puiCapture->_000OnMouseLeave(pmessage);
//
//         }
//         else if (puserinteraction)
//         {
//
//            puserinteraction->_000OnMouseLeave(pmessage);
//
//         }
//
//         return;
//
//      }
//
//      if (message == e_message_left_button_down ||
//         message == e_message_left_button_up ||
//         message == e_message_middle_button_down ||
//         message == e_message_middle_button_up ||
//         message == e_message_right_button_down ||
//         message == e_message_right_button_up ||
//         message == e_message_left_button_double_click ||
//         message == e_message_mouse_move ||
//         message == e_message_non_client_mouse_move ||
//         message == e_message_mouse_wheel)
//      {
//
//         message::mouse * pmouse = dynamic_cast <::message::mouse *> (pmessage);
//
//         if (message >= WM_MOUSEFIRST
//            && message <= WM_MOUSELAST
//            && m_bTranslateMouseMessageCursor
//            && !pmouse->m_bTranslated)
//         {
//
//            pmouse->m_bTranslated = true;
//
//            ::ClientToScreen(get_hwnd(), &pmouse->m_point);
//
//         }
//
//         if (message == e_message_left_button_down)
//         {
//
//            informationf("e_message_left_button_down");
//
//            string strType = ::str().demangle(puserinteraction->type_name());
//
//            if (strType.case_insensitive_contains("list_box"))
//            {
//
//               ::output_debug_string("list_box e_message_left_button_down");
//
//            }
//
//         }
//         else if (message == e_message_left_button_up)
//         {
//
//            informationf("e_message_left_button_up");
//
//         }
//         else if (message == e_message_non_client_left_button_up)
//         {
//
//            informationf("e_message_non_client_left_button_up");
//
//         }
//         else if (message == e_message_non_client_left_button_down)
//         {
//
//            informationf("e_message_non_client_left_button_down");
//
//            string strType;
//
//            if (strType.case_insensitive_contains("list_box"))
//            {
//
//               ::output_debug_string("list_box e_message_non_client_left_button_down");
//
//            }
//
//         }
//
//         auto papexsession = get_session();
//
//         ::aura::session * psession = nullptr;
//
//         if (papexsession)
//         {
//
//            psession = papexsession;
//
//         }
//
//         if (psession)
//         {
//
//            psession->on_ui_mouse_message(pmouse);
//
//         }
//
//         if (message == e_message_mouse_move)
//         {
//            // We are at the message handler procedure.
//            // mouse messages originated from message handler and that are mouse move happenings should end up with the correct cursor.
//            // So the procedure starts by setting to the default cursor,
//            // what forces, at the end of message processing, setting the bergedge cursor to the default cursor, if no other
//            // handler has set it to another one.
//            pmouse->m_ecursor = cursor_default;
//
//            //information() << "windows::e_message_mouse_move(%d,%d)", pmouse->m_point.x, pmouse->m_point.y;
//
//            string strType;
//
//            if (puserinteraction)
//            {
//
//               strType = ::str().demangle(puserinteraction->type_name());
//
//               if (strType.case_insensitive_contains("list_box"))
//               {
//
//                  //::output_debug_string("list_box e_message_mouse_move");
//
//               }
//
//            }
//
//         }
//         else if (message == e_message_non_client_mouse_move)
//         {
//            // We are at the message handler procedure.
//            // mouse messages originated from message handler and that are mouse move happenings should end up with the correct cursor.
//            // So the procedure starts by setting to the default cursor,
//            // what forces, at the end of message processing, setting the bergedge cursor to the default cursor, if no other
//            // handler has set it to another one.
//            pmouse->m_ecursor = cursor_default;
//         }
//
//         if (psession)
//         {
//
//            auto puiCapture = psession->m_puiCapture;
//
//            if (::is_set(puiCapture))
//            {
//
//               puiCapture->_000OnMouse(pmouse);
//
//               return;
//
//            }
//
//         }
//
//         _008OnMouse(pmouse);
//
//         return;
//
//      }
//
//      if (message == MESSAGE_OLE_DRAGENTER ||
//         message == MESSAGE_OLE_DRAGOVER ||
//         message == MESSAGE_OLE_DRAGLEAVE ||
//         message == MESSAGE_OLE_DRAGDROP)
//      {
//
//         message::drag_and_drop * pdrag = (::message::drag_and_drop *)pmessage;
//
//         auto puserinteraction = pdrag->userinteraction();
//
//         //hwnd_array hwnda;
//         //user::interaction_pointer_array wnda;
//         //wnda = *psystem->m_puiptraFrame;
//         //hwnda = wnda.get_hwnda();
//         //user::window_util::SortByZOrder(hwnda);
//         //for (int i = 0; i < hwnda.get_size(); i++)
//         //{
//         //   ::pointer<::user::interaction>puserinteraction = wnda.find_first(hwnda[i]);
//         //   if (puserinteraction != nullptr)
//         //   {
//
//         if (puserinteraction)
//         {
//            puserinteraction->_000OnDrag(pdrag);
//            if (pdrag->m_bRet)
//               return;
//
//         }
//         /*        }
//              }*/
//         return;
//      }
//      if (message == e_message_key_down ||
//         message == e_message_key_up ||
//         message == e_message_char ||
//         message == e_message_sys_key_down ||
//         message == e_message_sys_key_up ||
//         message == e_message_sys_char ||
//         message == WM_IME_KEYDOWN ||
//         message == WM_IME_KEYUP ||
//         message == WM_IME_CHAR ||
//         message == WM_IME_SELECT ||
//         message == WM_IME_SETCONTEXT ||
//         message == WM_IME_STARTCOMPOSITION ||
//         message == WM_IME_COMPOSITION ||
//         message == WM_IME_COMPOSITIONFULL ||
//         message == WM_IME_NOTIFY ||
//         message == WM_IME_ENDCOMPOSITION ||
//         message == WM_INPUTLANGCHANGE)
//      {
//
//
//         message::key * pkey = (::message::key *)pmessage;
//
//         ::pointer<::user::interaction>puiFocus;
//
//         auto papexsession = get_session();
//
//         ::aura::session * psession = nullptr;
//
//         if (papexsession)
//         {
//
//            psession = papexsession;
//
//         }
//
//         if (psession)
//         {
//
//            puiFocus = puserinteraction->get_keyboard_focus();
//
//         }
//
//         if (puiFocus && puiFocus->IsWindow() && puiFocus != puserinteraction)
//         {
//
//            puiFocus->send(pkey);
//
//            if (pmessage->m_bRet)
//            {
//
//               return;
//
//            }
//
//         }
//         else if (!pkey->m_bRet)
//         {
//
//            if (puserinteraction != nullptr)
//            {
//
//               puserinteraction->_000OnKey(pkey);
//
//               if (pmessage->m_bRet)
//               {
//
//                  return;
//
//               }
//
//            }
//
//         }
//
//         //m_wparam-
//
//         //m_lparam = pmessage->m_lparam;
//
//         //pmessage->set_lresult(::default_window_procedure(message, pmessage->m_wparam, pmessage->m_lparam));
//
//         //return;
//
//      }
//
//      if (message == e_message_event)
//      {
//
//         puserinteraction->handle_event(pmessage);
//
//         return;
//
//      }
//
//      ::user::window::message_handler(pmessage);
//
//      //if(pmessage->m_bRet && !pmessage->m_bDoSystemDefault)
//
//      if (pmessage->m_bRet)
//      {
//
//         return;
//
//      }
//
//      if (message == WM_IME_STARTCOMPOSITION ||
//         message == WM_IME_COMPOSITION ||
//         message == WM_IME_COMPOSITIONFULL ||
//         message == WM_IME_NOTIFY ||
//         message == WM_IME_ENDCOMPOSITION ||
//         message == WM_IME_SELECT ||
//         message == WM_IME_SETCONTEXT)
//      {
//
//         //return;
//
//      }
//
//      //if (bUserElementalOk && pmessage->m_bWindowProc)
//      //{
//      //   
//      //   if (puserinteraction != nullptr)
//      //   {
//      //      
//      //      puserinteraction->default_window_procedure(pmessage);
//
//      //   }
//      //   else
//      //   {
//      //      
//      //      pmessage->set_lresult(::DefWindowProcW(m_oswindow, pmessage->m_emessage, pmessage->m_wparam, pmessage->m_lparam));
//
//      //   }
//
//      //}
//
//   }


   //bool window::window_rectangle(::int_rectangle * prectangle)
   //{

   //   //RECT rectangle;

   //   //if (!::GetWindowRect(get_hwnd(), &rectangle))
   //   //{

   //   //   return false;

   //   //}

   //   //__copy(prectangle, rectangle);

   //   return true;

   //}


   ////WNDPROC* window::GetSuperWndProcAddr()
   ////{

   ////   // Note: it is no longer necessary to override GetSuperWndProcAddr
   ////   //  for each control class with a different WNDCLASS.
   ////   //  This implementation now uses instance data, such that the previous
   ////   //  WNDPROC can be anything.

   ////   //return &m_pfnSuper;

   ////   return nullptr;

   ////}


   //bool window::client_rectangle(::int_rectangle * prectangle)
   //{

   //   //RECT rectangle;

   //   //if (!::GetClientRect(get_hwnd(), &rectangle))/*
   //   //{

   //   //   return false;

   //   //}

   //   //__copy(prectangle, rectangle);*/

   //   return true;

   //}



   void window::non_top_most_upper_window_rects(::int_rectangle_array & recta)
   {

      ///// from top to bottom
      //top_level_enum toplevelenum;

      //auto phwnda = toplevelenum.m_phwnda;

      //HWND hwnd = get_hwnd();

      //index iFind = phwnda->find_first(hwnd);

      //if (iFind < 0)
      //{

      //   return;

      //}

      //::int_rectangle rHigher;

      //for (iFind--; iFind >= 0; iFind--)
      //{

      //   hwnd = phwnda->element_at(iFind);

      //   int iExStyle = GetWindowLong(hwnd, GWL_EXSTYLE);

      //   if ((iExStyle & WS_EX_TOPMOST) == WS_EX_TOPMOST)
      //   {

      //      continue;

      //   }

      //   if (::GetWindowRect(hwnd, (RECT *) &rHigher))
      //   {

      //      recta.add(rHigher);

      //   }

      //}

   }


   void window::set_finish()
   {

      //auto estatus =
      
      ::windowing::window::set_finish();

      //return estatus;

   }




   void window::set_tool_window(bool bSet)
   {

      //if (bSet)
      //{

      //   _modify_ex_style(0, WS_EX_TOOLWINDOW, SWP_FRAMECHANGED);

      //}
      //else
      //{

      //   _modify_ex_style(WS_EX_TOOLWINDOW, 0, SWP_FRAMECHANGED);

      //}

      //return ::success;

   }


   void window::_task_transparent_mouse_event()
   {

      //informationf("start window::_task_transparent_mouse_event");

      //auto ptask = ::get_task();

      //::int_point pointCursor;

      //::int_point pointMouseMove;

      //auto pimpl = m_pwindow;

      //auto pwindowing = windowing();

      //auto itask = puserinteraction->m_pthreadUserInteraction->m_itask;

      //HWND hwnd = get_hwnd();

      //lparam lparam;

      //::int_rectangle rectangleX;

      //while (ptask->task_get_run())
      //{

      //   if (m_timeLastMouseMove.elapsed() < 20_ms)
      //   {

      //      ::preempt(30_ms);

      //      continue;

      //   }

      //   auto hwndCapture = windowing::_get_mouse_capture(itask);

      //   if (hwndCapture != nullptr)
      //   {

      //      output_debug_string("a mouse capture");

      //   }

      //   if (hwndCapture == hwnd)
      //   {

      //      ::preempt(50_ms);

      //      continue;

      //   }

      //   ::GetCursorPos((POINT *)&pointCursor);

      //   pointMouseMove = pointCursor;

      //   ::ScreenToClient(hwnd, (POINT *) &pointMouseMove);

      //   if (m_pointMouseMove == pointMouseMove)
      //   {

      //      ::preempt(30_ms);

      //      continue;

      //   }

      //   ::GetClientRect(hwnd, (RECT *)&rectangleX);

      //   if (!rectangleX.contains(pointMouseMove))
      //   {

      //      if (m_bTrackMouseLeave)
      //      {

      //         puserinteraction->post_message(e_message_mouse_leave);

      //      }

      //      ::preempt(100_ms);

      //      continue;

      //   }

      //   lparam = MAKELPARAM(pointMouseMove.x, pointMouseMove.y);

      //   m_timeLastMouseMove.Now();

      //   //pimpl->puserinteraction->post_message(e_message_mouse_move, 0, lparam);
      //   
      //   pimpl->puserinteraction->send_message(e_message_mouse_move, 0, lparam);

      //   //::SendMessage(hwnd, e_message_mouse_move, 0, lparam);

      //   ::preempt(5_ms);

      //}

      //informationf("end window::_task_transparent_mouse_event");

   }


   void window::on_message_destroy(::message::message * pmessage)
   {

      __UNREFERENCED_PARAMETER(pmessage);

   }


   void window::on_message_create(::message::message * pmessage)
   {

      ::pointer<::message::create>pcreate(pmessage);


      //direct2d::defer_initialize();

      int nReturnCode = 0;


      

      //if (!system()->m_htask)
      //{

      //   if (!system()->begin_synch())
      //   {

      //      throw ::exception(error_failed, "failed to begin_synch the system");

      //   }

      //}

      //auto estatus = m_pdxi->initialize(system());

      //if (!estatus)
      //{

      //   throw ::exception(error_resource);

      //}

      //session() = this;

      //session()->m_puserprimitiveHost = m_pdxi;

      //::user::os_calc_dark_mode();

      //auto pcs = __create_new< ::user::system >();

      auto puserinteractionUserSystem = user_interaction();

      auto pusersystem = puserinteractionUserSystem->m_pusersystem;

      auto puserinteraction = session()->m_puserprimitiveHost;

      auto routine = [this]()
      {

         main_send({ e_timeout, 15_s, [this]()
            {

               //pbuffer->m_windowscorewindowBounds = m_windowscorewindow->Bounds;

               //auto pchanged = ref ___new ::winrt::Windows::UI::Core::WindowSizeChangedEventArgs();

               ::int_size size((LONG)m_windowscorewindow.Bounds().Width, (LONG)m_windowscorewindow.Bounds().Height);

               //pchanged->Size.Height = m_windowscorewindow.Bounds().Height;

               on_window_size_changed(m_windowscorewindow, size);

            } });

         auto puserinteraction = session()->m_puserprimitiveHost;

         //auto puserinteraction = m_pdxi;

         //puserinteraction->display(e_display_normal);

         //puserinteraction->set_need_layout();

         //puserinteraction->set_need_redraw();

         //puserinteraction->post_redraw();


      };

      pusersystem->m_procedureSuccess = routine;

      //m_pwindow = __create < ::windowing::window >();

      main_send({ e_timeout, 15_s, [this]()
         {

            auto window = m_windowscorewindow;

            //window.VisibilityChanged(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs>(this, &window::OnWindowVisibilityChanged));

            //window.PointerCursor(::winrt::Windows::UI::Core::CoreCursor(::winrt::Windows::UI::Core::CoreCursorType::Arrow, 0));

            //window.SizeChanged(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::WindowSizeChangedEventArgs>(this, &window::OnWindowSizeChanged));

            //window.PointerMoved(::winrt::Windows::Foundation::TypedEventHandler <::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs>(this, &window::OnPointerMoved));

            //window.CharacterReceived(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs>(this, &window::OnCharacterReceived));

            //window.KeyDown(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs>(this, &window::OnKeyDown));

            //window.KeyUp(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs>(this, &window::OnKeyUp));

            //window.PointerPressed(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs>(this, &window::OnPointerPressed));

            //window.PointerReleased(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs >(this, &window::OnPointerReleased));

            //auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

            //system()->m_dDpi = displayinformation.LogicalDpi();

            //displayinformation.DpiChanged(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::Graphics::Display::DisplayInformation, ::winrt::Windows::Foundation::IInspectable >(this, &window::DpiChanged));

            //displayinformation.DisplayContentsInvalidated(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::Graphics::Display::DisplayInformation, ::winrt::Windows::Foundation::IInspectable >(this, &window::DisplayContentsInvalidated));



            ::double_rectangle rectangle;

            rectangle.left() = (LONG)m_windowscorewindow.Bounds().X;
            rectangle.top() = (LONG)m_windowscorewindow.Bounds().Y;
            rectangle.right() = (LONG)(m_windowscorewindow.Bounds().X + m_windowscorewindow.Bounds().Width);
            rectangle.top() = (LONG)(m_windowscorewindow.Bounds().Y + m_windowscorewindow.Bounds().Height);

            //puserinteraction->m_puiThis->place(rectangle);

            //m_pwindow = system()->m_papplicationStartup->__create_new < ::windowing_universal_windows::window >();

            //if (window.Visible())
            //{

            //   __on_window_visible();

            //}

            //m_windowscorewindow = m_windowscorewindow;

         } } );

      pusersystem->m_pwindow = this;

      system()->m_pacmeuserinteractionMain = m_pacmeuserinteraction;

      //m_bNotifyLayoutCompletedPending = true;

      //if (!puserinteraction->m_puiThis->create_window_ex(pcs))
      //{

      //   throw ::exception(resource_exception("Couldn't create Main Window"));

      //   return;

      //}



      //::direct2d::defer_direct2d_initialize();

      //add_factory_item < ::windowing_universal_windows::buffer, ::graphics::graphics >();

      m_dwMouseMoveThrottle = 10;

      //m_pwindow = nullptr;

      m_pointLastCursor.X = 0;
      m_pointLastCursor.Y = 0;

      m_bLeftButton = false;
      m_bMiddleButton = false;
      m_bRightButton = false;

      //m_strId = strId;

      //if (!main_initialize())
      //{

      //   throw ::exception(error_failed, "Failed to run main_initialize at window constructor.");

      //}

      //system() = psystem;

      //      psystem->get_session()->m_frameworkview = this;

      //m_pdxi = psystem->m_papplicationStartup->__create_new < directx_interaction>();

      //return ::success;


      {

/*          DEVMODE dm;

         if (EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &dm))
         {

            set_config_per_second(dm.dmDisplayFrequency);

         }*/

      }

//         default_message_handler(pmessage);

      //auto puserinteraction = user_interaction();

      if (puserinteraction)
      {

         //if (puserinteraction->is_message_only_window() || m_puserinteraction.cast <::windowing_universal_windows::system_interaction >())
         //{

         //   informationf("good : opt out!");

         //}

         if (puserinteraction->m_bUserElementOk)
         {

            pcreate->m_lresult = 0;

         }

      }

   }


   float window::get_dpi_for_window()
   {

      //::oswindow oswindow = this;

      //return (float) ::get_dpi_for_window(oswindow);

      return 96.0f;

   }


   float window::point_dpi(float points)
   {

      float fDpi = get_dpi_for_window();

      return points * fDpi / 72.f;

   }


   float window::dpiy(float y)
   {

      float fDpi = get_dpi_for_window();

      return y * fDpi / 96.f;

   }


   float window::dpix(float x)
   {

      float fDpi = get_dpi_for_window();

      return x * fDpi / 96.f;

   }


   float window::y_dpi(float y)
   {

      float fDpi = get_dpi_for_window();

      return y / fDpi;

   }


   float window::x_dpi(float x)
   {

      float fDpi = get_dpi_for_window();

      return x / fDpi;

   }


   //void window::_window_request_presentation()
   //{

   //   ::windowing::window::_window_request_presentation();

   //   //auto puserinteraction = user_interaction();

   //   //auto pprodevian = m_pprodevian;

   //   //puserinteraction->post_procedure(pprodevian->m_procedureWindowShow);

   //}


   void window::__update_graphics_buffer()
   {

      /*auto puserinteraction = user_interaction();

      if (!puserinteraction)
      {

         return;

      }

      auto pprodevian = m_pprodevian;

      if (!pprodevian)
      {

         return;

      }

      puserinteraction->post_procedure(pprodevian->m_procedureUpdateScreen);*/

      set_window_position_unlocked();

      ::pointer<::windowing_universal_windows::buffer>pbuffer = m_pgraphicsgraphics;

      pbuffer->update_screen();

   }


   void window::on_redraw_window(unsigned int flags)
   {

      //if (!(_get_ex_style() & WS_EX_LAYERED))
      //{

      //   ::RedrawWindow(get_hwnd(), nullptr, nullptr, flags);

      //}

   }


   void window::graphics_lock()
   {

      ///direct2d::direct2d()->m_d2dMultithread->Enter();

   }


   void window::graphics_unlock()
   {

      ///direct2d::direct2d()->m_d2dMultithread->Leave();

   }


   //void window::show_task(bool bShowTask)
   //{

   //   if (bShow)
   //   {

   //      ModifyStyleEx(WS_EX_TOOLWINDOW, 0, SWP_FRAMECHANGED);

   //   }
   //   else
   //   {

   //      ModifyStyleEx(0, WS_EX_TOOLWINDOW, SWP_FRAMECHANGED);

   //   }

   //   defer_co_initialize_ex(false);

   //   comptr < ITaskbarList>                     tasklist;

   //   HRESULT hr = tasklist.CoCreateInstance(CLSID_TaskbarList, nullptr, CLSCTX_INPROC_SERVER);

   //   if (SUCCEEDED(hr) && SUCCEEDED(hr = tasklist->HrInit()))
   //   {

   //      if (bShow)
   //      {

   //         hr = tasklist->AddTab((HWND)get_oswindow());

   //         informationf("result = %d", hr);

   //      }
   //      else
   //      {

   //         tasklist->DeleteTab((HWND)get_oswindow());

   //      }

   //   }

   //}


   //window::window()
   //{

   //   m_bInternalFocus = false;
   //   m_bExtendingLeft = false;
   //   m_bTextCompositionActive = false;

   //}

   
   void window::on_initialize_particle()
   {

      //auto estatus = 
      
      ::windowing::window::on_initialize_particle();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //m_pwindowing = system()->system()->windowing();

      //if (!m_pwindowing->m_pwindowSoul)
      //{

      //   system()->m_pnode->call_member(SOUL_ID);

      //}

      //return estatus;

   }


   void window::destroy()
   {

      ::sandbox_windowing::window::destroy();

         ::universal_windows::acme::windowing::window::destroy();


   }

   //void window::main_post(const ::procedure & procedure)
   //{



   //}




   void window::SetInternalFocus()
   {

      if (!m_bInternalFocus)
      {

         // Update internal notion of focus.
         m_bInternalFocus = true;

         // Update the UI.
         //UpdateTextUI();
         //UpdateFocusUI();

         // Notify the CoreTextEditContext that the edit context has focus,
         // so it should start processing text input.
         m_editcontext.NotifyFocusEnter();

      }

      // Ask the software keyboard to show.  The system will ultimately decide if it will show.
      // For example, it will not show if there is a keyboard attached.
      m_inputpane.TryShow();


      ::sandbox_windowing::window::SetInternalFocus();

      //if (m_puserinteractionFocusRequest != nullptr)
      //{

      //   m_puserinteractionFocus1 = m_puserinteractionFocusRequest;

      //   m_puserinteractionFocusRequest = nullptr;


      //}

   }


   void window::RemoveInternalFocus()
   {

      if (m_bInternalFocus)
      {

         //Notify the system that this edit context is no longer in focus
         m_editcontext.NotifyFocusLeave();

         RemoveInternalFocusWorker();

      }

   }


   void window::RemoveInternalFocusWorker()
   {

      //Update the internal notion of focus
      m_bInternalFocus = false;

      // Ask the software keyboard to dismiss.
      m_inputpane.TryHide();

      // Update our UI.
      UpdateTextUI();

      UpdateFocusUI();

   }


   void window::EditContext_FocusRemoved(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::Foundation::IInspectable inspectable)
   {

      RemoveInternalFocusWorker();

   }


   //void window::Element_Unloaded(winrt::Windows::Foundation::IInspectable  sender, ::winrt::Windows::UI::Xaml::RoutedEventArgs  e)
   //{

   //   m_windowscorewindow->KeyDown -= m_tokenKeyDown;

   //   m_windowscorewindow->PointerPressed -= m_tokenPointerPressed;

   //}


   void window::SetText(const ::wstring & wstrText, int iBeg, int iEnd)
   {

      //auto 

//      m_strText = text;

      set_input_text(wstrText);

      main_post([this, iBeg, iEnd]()
         {

            wide_string wstrText = get_input_text();

            ::winrt::Windows::UI::Text::Core::CoreTextRange sel;

            sel.StartCaretPosition = iBeg;

            sel.EndCaretPosition = iEnd < 0 ? (int) (wstrText.length() + iEnd + 1) : iEnd;

            m_editcontext.NotifyTextChanged(m_selection, (int) wstrText.length(),  sel);

         });

   }


   // Replace the text in the specified range.
   void window::ReplaceText(::winrt::Windows::UI::Text::Core::CoreTextRange  modifiedRange, const ::wstring & text)
   {

      wstring wstrText = get_input_text();

      // Modify the internal text store.
      wstrText = wstrText.left(modifiedRange.StartCaretPosition) +
         text +
         wstrText.substr(modifiedRange.EndCaretPosition);

      // Move the caret to the end of the replacement text.
      m_selection.StartCaretPosition = (int) (modifiedRange.StartCaretPosition + wstrText.length());
      m_selection.EndCaretPosition = m_selection.StartCaretPosition;

      // Update the selection of the edit context.  There is no need to notify the system
      // of the selection change because we are going to call NotifyTextChanged soon.
      SetSelection(m_selection);

      // Let the CoreTextEditContext know what changed.
      m_editcontext.NotifyTextChanged(modifiedRange, (int) wstrText.length(), m_selection);

   }


   bool window::HasSelection()
   {

      return m_selection.StartCaretPosition != m_selection.EndCaretPosition;

   }


   // Change the selection without notifying CoreTextEditContext of the ___new selection.
   void window::SetSelection(::winrt::Windows::UI::Text::Core::CoreTextRange selection)
   {

      // Modify the internal selection.
      m_selection = selection;

      //Update the UI to show the ___new selection.
      UpdateTextUI();

   }


   // Change the selection and notify CoreTextEditContext of the ___new selection.
   void window::SetSelectionAndNotify(::winrt::Windows::UI::Text::Core::CoreTextRange selection)
   {

      SetSelection(selection);

      m_editcontext.NotifySelectionChanged(m_selection);

   }


   // Return the specified range of text. Note that the system may ask for more text
   // than exists in the text buffer.
   void window::EditContext_TextRequested(::winrt::Windows::UI::Text::Core::CoreTextEditContext  sender, ::winrt::Windows::UI::Text::Core::CoreTextTextRequestedEventArgs args)
   {

      ::winrt::Windows::UI::Text::Core::CoreTextTextRequest  request = args.Request();

      wide_string wstrText = get_input_text();

      wstrText = wstrText.substr(
         request.Range().StartCaretPosition,
         minimum(request.Range().EndCaretPosition, wstrText.length()) - request.Range().StartCaretPosition);

      auto hstrText = as_hstring(string(wstrText));

      request.Text(hstrText);

   }


   // Return the current selection.
   void window::EditContext_SelectionRequested(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs args)
   {

      auto request = args.Request();

      request.Selection(m_selection);

   }


   void window::EditContext_TextUpdating(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs  args)
   {

      auto range = args.Range();

      ::output_debug_string("range" + ::as_string(range.StartCaretPosition) + "," + ::as_string(range.EndCaretPosition) + "\n");

      wide_string newText = args.Text().begin();

      auto newSelection = args.NewSelection();

      auto pwsz = newText.c_str();

      wide_string wstrText = get_input_text();

      string strText = wstrText.left(range.StartCaretPosition) + newText + wstrText.substr(range.EndCaretPosition);

      m_strNewText = newText;

      // Modify the internal text store.
      //m_strText = strText;

      // You can set the proper font or direction for the updated text based on the language by checking
      // args.InputLanguage.  We will not do that in this sample.

      // Modify the current selection.
      newSelection.EndCaretPosition = newSelection.StartCaretPosition;

      // Update the selection of the edit context. There is no need to notify the system
      // because the system itself changed the selection.
      SetSelection(newSelection);

      if (m_strNewText.has_character())
      {

         auto puserinteraction = user_interaction();

         auto pfocusui = puserinteraction->get_keyboard_focus();

         if (pfocusui)
         {

            pfocusui->insert_text(m_strNewText, false, e_source_sync);

         }
         else
         {

            ::pointer<::user::message>spbase;

            auto pkey = __create_new< ::message::key >();

            spbase = pkey;

            auto puserinteraction = user_interaction();

            bool bTextFocus = puserinteraction != nullptr;

            bool bSpecialKey = false;
            pkey->m_pwindow = this;

            pkey->m_oswindow = this;

            pkey->m_emessage = e_message_key_down;
            //pkey->m_playeredUserPrimitive = psession->get_user_interaction_host();
            pkey->m_nChar = 0;
            pkey->m_ekey = ::user::e_key_refer_to_text_member;
            pkey->m_wparam = pkey->m_nChar;
            pkey->m_nFlags = 0;
            pkey->m_lparam = pkey->m_nFlags << 16;
            pkey->m_strText = m_strNewText;

            puserinteraction->message_handler(spbase);

         }

      }

   }


   void window::EditContext_SelectionUpdating(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs  args)
   {

      // Set the ___new selection to the value specified by the system.
      auto range = args.Selection();

      // Update the selection of the edit context. There is no need to notify the system
      // because the system itself changed the selection.
      SetSelection(range);

   }


   void window::EditContext_FormatUpdating(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs  args)
   {

      // The following code specifies how you would apply any formatting to the specified range of text
      // For this sample, we do not make any changes to the format.

      // Apply text color if specified.
      // A null value indicates that the default should be used.
      if (args.TextColor() != nullptr)
      {

         //InternalSetTextColor(args.Range, args.TextColor.Value);

      }
      else
      {

         //InternalSetDefaultTextColor(args.Range);

      }

      // Apply background color if specified.
      // A null value indicates that the default should be used.
      if (args.BackgroundColor() != nullptr)
      {

         //InternalSetBackgroundColor(args.Range, args.BackgroundColor.Value);

      }
      else
      {

         //InternalSetDefaultBackgroundColor(args.Range);

      }

      // Apply underline if specified.
      // A null value indicates that the default should be used.
      if (args.UnderlineType() != nullptr)
      {

         //TextDecoration underline = ___new TextDecoration(args.Range,args.UnderlineType.Value,args.UnderlineColor.Value);

         //InternalAddTextDecoration(underline);

      }
      else
      {

         //InternalRemoveTextDecoration(args.Range);

      }

   }


   void window::EditContext_LayoutRequested(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs args)
   {

      auto  request = args.Request();

      // Get the screen coordinates of the entire control and the selected text.
      // This information is used to position the IME candidate window.

      // First, get the coordinates of the edit control and the selection
      // relative to the Window.

      auto contentRect = _get_input_content_rect();

      auto selectionRect = _get_input_selection_rect();

      // Next, convert to screen coordinates in window pixels.
      auto windowBounds = m_windowscorewindow.Bounds();
      contentRect.X += windowBounds.X;
      contentRect.Y += windowBounds.Y;
      selectionRect.X += windowBounds.X;
      selectionRect.Y += windowBounds.Y;

      // Finally, scale up to raw pixels.
      double scaleFactor = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView().RawPixelsPerViewPixel();

      contentRect = ScaleRect(contentRect, scaleFactor);
      selectionRect = ScaleRect(selectionRect, scaleFactor);

      // This is the bounds of the selection.
      // Note: If you return bounds with 0 width and 0 height, candidates will not appear while typing.
      request.LayoutBounds().TextBounds(selectionRect);

      //This is the bounds of the whole control
      request.LayoutBounds().ControlBounds(contentRect);

   }


   // This indicates that an IME has started composition.  If there is no handler for this happening,
   // then composition will not start.
   void window::EditContext_CompositionStarted(::winrt::Windows::UI::Text::Core::CoreTextEditContext  sender, ::winrt::Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs  args)
   {

      m_bTextCompositionActive = true;

   }


   void window::EditContext_CompositionCompleted(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs  args)
   {

      m_bTextCompositionActive = false;

      auto puserinteraction = user_interaction();

      auto pfocusui = puserinteraction->get_keyboard_focus();

      //m_strText.empty();

      //m_strNewText.empty();

      if (pfocusui)
      {

         pfocusui->on_text_composition_done();

      }

   }


   void window::EditContext_NotifyFocusLeaveCompleted(::winrt::Windows::UI::Text::Core::CoreTextEditContext  sender, ::winrt::Windows::Foundation::IInspectable args)
   {


   }



   // Adjust the active endpoint of the selection in the specified direction.
   void window::AdjustSelectionEndpoint(int direction)
   {

      ::winrt::Windows::UI::Text::Core::CoreTextRange range = m_selection;

      if (m_bExtendingLeft)
      {

         range.StartCaretPosition = maximum(0, range.StartCaretPosition + direction);

      }
      else
      {

         wide_string wstrText = get_input_text();

         range.EndCaretPosition = minimum((int) wstrText.length(), (range.EndCaretPosition + direction));

      }

      SetSelectionAndNotify(range);

   }


   // Helper function to put a zero-width non-breaking space at the end of a string.
   // This prevents TextBlock from trimming trailing spaces.
   ::string  window::PreserveTrailingSpaces(const ::scoped_string & scopedstr)
   {

      return str + L"\ufeff";

   }


   void window::UpdateFocusUI()
   {

      //BorderPanel->BorderBrush = _internalFocus ? ___new ::winrt::Windows::UI::Xaml::Media::SolidColorBrush(::winrt::Windows::UI::Colors::Green) : null;

   }


   void window::UpdateTextUI()
   {

      // The raw materials we have are a string (_text) and information about
      // where the caret/selection is (_selection). We can render the control
      // any way we like.

      //BeforeSelectionText->Text = PreserveTrailingSpaces(_text->Substring(0, _selection->StartCaretPosition));
      //if (HasSelection())
      //{
      //   // There is a selection. Draw that.
      //   CaretText.Visibility = Visibility.Collapsed;
      //   SelectionText.Text = PreserveTrailingSpaces(
      //      _text->Substring(_selection->StartCaretPosition, _selection->EndCaretPosition - _selection->StartCaretPosition));
      //}
      //else
      //{
      //   // There is no selection. Remove it.
      //   SelectionText.Text = "";

      //   // Draw the caret if we have focus.
      //   CaretText.Visibility = _internalFocus ? Visibility.Visible : Visibility.Collapsed;
      //}

      //AfterSelectionText.Text = PreserveTrailingSpaces(_text->Substring(_selection->EndCaretPosition));

      //// Update statistics for demonstration purposes.
      //FullText.Text = _text;
      //SelectionStartIndexText.Text = _selection->StartCaretPosition.ToString();
      //SelectionEndIndexText.Text = _selection->EndCaretPosition.ToString();
   }


   //Rect window::GetElementRect(FrameworkElement matter)
   //{
   //   GeneralTransform transform = matter.TransformToVisual(null);
   //   Point point = transform.TransformPoint(___new Point());
   //   return ___new Rect(point, ___new Size(matter.ActualWidth, matter.ActualHeight));
   //}


   int g_iMouse;


   //#undef ::auraacmesystem()
   //#undef Platform
   //
   //
   //using namespace Platform;
   //using namespace Microsoft::WRL;
   //using namespace ::winrt::Windows::Foundation;
   //using namespace ::winrt::Windows::UI::Core;
   //using namespace ::winrt::Windows::ApplicationModel;
   //using namespace ::winrt::Windows::ApplicationModel::Core;
   //using namespace ::winrt::Windows::ApplicationModel::Activation;
   //using namespace ::winrt::Windows::auraacmesystem();
   //using namespace ::winrt::Windows::Graphics::Display;
   //using namespace ::winrt::Windows::auraacmesystem()::Threading;
   //
   //

   /*namespace windowing_universal_windows
   {*/


      //window::window()
      //{



      //}


      //void window::initialize_application(::aura::system * psystem, const ::scoped_string & scopedstrId)
      //{


      //}


  /*    window::~window()
      {

         ::direct2d::finalize();

      }*/


      //void window::initialize_directx_application()
      //{

      //   //direct2d::defer_initialize();

      //   int nReturnCode = 0;

      //   if (!system()->m_htask)
      //   {

      //      if (!system()->begin_synch())
      //      {

      //         throw ::exception(error_failed, "failed to begin_synch the system");

      //      }

      //   }

      //   //auto estatus = m_pdxi->initialize(system());

      //   //if (!estatus)
      //   //{

      //   //   throw ::exception(error_resource);

      //   //}

      //   //session() = this;

      //   //session()->m_puserprimitiveHost = m_pdxi;

      //   //::user::os_calc_dark_mode();

      //   auto pcs = __create_new< ::user::system >();

      //   auto puserinteraction = session()->m_puserprimitiveHost;

      //   auto routine = [this]()
      //   {

      //      session()->system()->windowing()->windowing_sync(15_s, __routine([this]()
      //         {

      //            //pbuffer->m_windowscorewindowBounds = m_windowscorewindow->Bounds;

      //            //auto pchanged = ref ___new ::winrt::Windows::UI::Core::WindowSizeChangedEventArgs();

      //            ::int_size size((LONG)m_windowscorewindow.Bounds().Width, (LONG)m_windowscorewindow.Bounds().Height);

      //            //pchanged->Size.Height = m_windowscorewindow.Bounds().Height;

      //            on_window_size_changed(m_windowscorewindow, size);

      //         }));

      //      auto puserinteraction = session()->m_puserprimitiveHost;

      //      //auto puserinteraction = m_pdxi;

      //      //puserinteraction->display(e_display_normal);

      //      //puserinteraction->set_need_layout();

      //      //puserinteraction->set_need_redraw();

      //      //puserinteraction->post_redraw();


      //   };

      //   pcs->m_procedureSuccess = __routine(routine);

      //   //m_pwindow = __create < ::windowing::window >();

      //   ::double_rectangle rectangle;

      //   rectangle.left() = (LONG)m_windowscorewindow.Bounds().X;
      //   rectangle.top() = (LONG)m_windowscorewindow.Bounds().Y;
      //   rectangle.right() = (LONG)(m_windowscorewindow.Bounds().X + m_windowscorewindow.Bounds().Width);
      //   rectangle.top() = (LONG)(m_windowscorewindow.Bounds().Y + m_windowscorewindow.Bounds().Height);

      //   //puserinteraction->m_puiThis->place(rectangle);

      //   m_pwindow = system()->m_papplicationStartup->__create_new < ::windowing_universal_windows::window >();

      //   system()->get_session()->system()->windowing()->m_pwindowFirst = m_pwindow;

      //   system()->get_session()->system()->windowing()->m_bXXXFirst = true;

      //   m_windowscorewindow = m_windowscorewindow;

      //   pbuffer->m_pwindow = m_pwindow;

      //   pbuffer = pbuffer;

      //   //m_papexapplication = this;

      //   pcs->m_pwindow = m_pwindow;

      //   system()->__refer(system()->m_pwindowMain, m_pwindow);

      //   //m_bNotifyLayoutCompletedPending = true;

      //   //if (!puserinteraction->m_puiThis->create_window_ex(pcs))
      //   //{

      //   //   throw ::exception(resource_exception("Couldn't create Main Window"));

      //   //   return;

      //   //}

      //}


      //void window::Initialize(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView)
      //{


      //}


 /*     void window::install_directx_application_message_routing()
      {


      }*/


      //void window::SetWindow(::winrt::Windows::UI::Core::CoreWindow const & window)
      //{


      //}


void window::set_mouse_capture()
{
   ::sandbox_windowing::window::set_mouse_capture();

}
bool window::has_mouse_capture()
{
   return ::sandbox_windowing::window::has_mouse_capture();

}

void window::defer_show_system_menu(::user::mouse * pmouse)
{

   ::universal_windows::acme::windowing::window::defer_show_system_menu(pmouse);

}

      //void window::OnWindowSizeChanged(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::WindowSizeChangedEventArgs args)
      //{

      //   ::int_size size((LONG)args.Size().Width, (LONG)args.Size().Height);

      //   on_window_size_changed(sender, size);

      //}


      void window::InstallPrototypeHappeningHandling()
      {

         ::universal_windows::acme::windowing::window::InstallPrototypeHappeningHandling();

         auto manager = ::winrt::Windows::UI::Text::Core::CoreTextServicesManager::GetForCurrentView();

         m_editcontext = manager.CreateEditContext();

         // Get the Input Pane so we can programmatically hide and show it.
         m_inputpane = ::winrt::Windows::UI::ViewManagement::InputPane::GetForCurrentView();

         // For demonstration purposes, this sample sets the Input Pane display policy to Manual
         // so that it can manually show the software keyboard when the control gains focus and
         // dismiss it when the control loses focus. If you leave the policy as Automatic, then
         // the system will hide and show the Input Pane for you. Note that on Desktop, you will
         // need to implement the UIA text pattern to get expected automatic behavior.
         m_editcontext.InputPaneDisplayPolicy(::winrt::Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy::Automatic);

         // Set the input scope to Text because this text box is for any text.
         // This also informs software keyboards to show their regular
         // text entry layout.  There are many other input scopes and each will
         // inform a keyboard layout and text behavior.
         m_editcontext.InputScope(::winrt::Windows::UI::Text::Core::CoreTextInputScope::Text);

         // The system raises this happening to request a specific range of text.
         m_editcontext.TextRequested(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextTextRequestedEventArgs>(this, &window::EditContext_TextRequested));

         // The system raises this happening to request the current selection.
         m_editcontext.SelectionRequested(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs>(this, &window::EditContext_SelectionRequested));

         // The system raises this happening when it wants the edit control to erase focus.
         m_editcontext.FocusRemoved(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::Foundation::IInspectable>(this, &window::EditContext_FocusRemoved));

         // The system raises this happening to update text in the edit control.
         m_editcontext.TextUpdating(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs>(this, &window::EditContext_TextUpdating));

         // The system raises this happening to change the selection in the edit control.
         m_editcontext.SelectionUpdating(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs>(this, &window::EditContext_SelectionUpdating));

         // The system raises this happening when it wants the edit control
         // to apply formatting on a r::winrt::Windows::Foundation::Tange of text.
         m_editcontext.FormatUpdating(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs>(this, &window::EditContext_FormatUpdating));

         // The system raises this happening to request layout information.
         // This is used to help choose a position for the IME candidate window.
         m_editcontext.LayoutRequested(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs>(this, &window::EditContext_LayoutRequested));

         // The system raises this happening to notify the edit control
         // that the string composition has started.
         m_editcontext.CompositionStarted(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs>(this, &window::EditContext_CompositionStarted));

         // The system raises this happening to notify the edit control
         // that the string composition is finished.
         m_editcontext.CompositionCompleted(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs>(this, &window::EditContext_CompositionCompleted));

         // The system raises this happening when the NotifyFocusLeave operation has
         // completed. Our sample does not use this happening.
         m_editcontext.NotifyFocusLeaveCompleted(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Text::Core::CoreTextEditContext, ::winrt::Windows::Foundation::IInspectable>(this, &window::EditContext_NotifyFocusLeaveCompleted));

         // Set our initial UI.
         UpdateTextUI();

         UpdateFocusUI();


      }

      void window::on_window_size_changed(::winrt::Windows::UI::Core::CoreWindow sender, const ::int_size & size)
      {

         auto pbuffer = get_window_graphics();

         if (::is_set(pbuffer))
         {

            auto pbufferitem = pbuffer->get_buffer_item();

            pbufferitem->m_size = size;

            pbuffer->update_buffer(pbufferitem);

         }

         //::lparam lparam(size);
//
         //puserinteraction->send_message(e_message_size, 0, lparam);

         auto puserinteraction = user_interaction();

         puserinteraction->place({ int_point(), size });

         //puserinteraction->set_size(size);

         puserinteraction->set_need_layout();

         puserinteraction->set_need_redraw();

         puserinteraction->post_redraw();

      }


      //void window::DpiChanged(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable)
      //{

      //   m_rectangleLastWindowRect = m_windowscorewindow.Bounds();

      //   auto pbuffer = __buffer(get_window_graphics());

      //   pbuffer->OnChangeDpi(sender.LogicalDpi());

      //}

      void window::on_dpi_changed(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable)
      {

         ::universal_windows::acme::windowing::window::on_dpi_changed(sender, inspectable);

         auto pbuffer = __buffer(get_window_graphics());

         pbuffer->OnChangeDpi(sender.LogicalDpi());

      }




      //void window::DisplayContentsInvalidated(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable)
      //{

      //   // Ensure the D3D Device is available for rendering.

      //   auto pbuffer = __buffer(get_window_graphics());

      //   pbuffer->ValidateDevice();

      //}


      void window::on_display_contents_invalidated(::winrt::Windows::Graphics::Display::DisplayInformation sender, ::winrt::Windows::Foundation::IInspectable inspectable)
      {

         // Ensure the D3D Device is available for rendering.

         auto pbuffer = __buffer(get_window_graphics());

         pbuffer->ValidateDevice();

      }



      void window::on_character_received(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs args)
      {

         if (m_bInternalFocus)
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

         ::wd32_character wd32ch = args.KeyCode();

         if (wd32ch < 32)
         {

            // It is control character.

            return;

         }

         auto pkey = __create_new< ::message::key >();
         pkey->m_pwindow = this;

         pkey->m_oswindow = this;

         pkey->m_emessage = e_message_char;

         pkey->m_ekey = ::user::e_key_refer_to_text_member;

         char szUtf8[32];

         wd32_to_ansi(szUtf8, &wd32ch, 1);
         
         pkey->m_strText = szUtf8;

         puserinteraction->message_handler(pkey);

      }


      void window::on_key_down(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args)
      {

         if (args.VirtualKey() == ::winrt::Windows::System::VirtualKey::Shift)
         {

            m_bFontopusShift = true;

         }

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
           // return;

         auto pkey = __create_new< ::message::key >();

         bool bTextFocus = puserinteraction->get_keyboard_focus() != nullptr;

         bool bSpecialKey = false;

         ::user::enum_key ekey = ::universal_windows::virtualkey_to_userkey(args.VirtualKey(), bSpecialKey);

         //if (bSpecialKey s || session()->is_key_pressed(::user::e_key_control)
         //   || session()->is_key_pressed(::user::e_key_alt))
         //{
         pkey->m_pwindow = this;

         pkey->m_oswindow = this;

         pkey->m_emessage = e_message_key_down;
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


         puserinteraction->message_handler(pkey);

      //   ;;
      //}

      }

      void window::on_key_up(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args)
      {

         if (system() == nullptr)
            return;

         auto puserinteraction = user_interaction();

         if (puserinteraction == nullptr)
            return;

         //if (puserinteraction->m_pinteractionimpl == nullptr)
         //   return;

         ::pointer<::user::message>pusermessage;

         auto pkey = __create_new< ::message::key >();

         pusermessage = pkey;


         if (args.VirtualKey() == ::winrt::Windows::System::VirtualKey::Shift)
         {

            m_bFontopusShift = false;

         }

         bool bTextFocus = puserinteraction->get_keyboard_focus() != nullptr;

         bool bSpecialKey = false;

         ::user::enum_key ekey = ::universal_windows::virtualkey_to_userkey(args.VirtualKey(), bSpecialKey);

         //if (bSpecialKey || !bTextFocus)
         //{
         pkey->m_pwindow = this;

         pkey->m_oswindow = this;

            pkey->m_emessage = e_message_key_up;
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
            puserinteraction->message_handler(pusermessage);
            //}

         //}



      }


      //void window::OnWindowClosed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CoreWindowEventArgs args)
      //{

      //}

      void window::__on_window_visible()
      {


         auto pbuffer = __buffer(get_window_graphics());

         if (pbuffer)
         {

            if (pbuffer->m_tristateCoreWindowVisible.undefined())
            {

               pbuffer->m_tristateCoreWindowVisible = true;

            }
            else if (pbuffer->m_tristateCoreWindowVisible.is_set_false())
            {

               pbuffer->m_tristateCoreWindowVisible = true;

               winrt::Windows::UI::Core::CoreWindow window = m_windowscorewindow;

               if (window)
               {

                  //pbuffer->HandleDeviceLost();
                  pbuffer->CreateWindowSizeDependentResources();


               }

            }

         }

      }


      void window::_create_window()
      {


         //::universal_windows::acme::windowing::window::_create_window();

               //auto pwindowing = windowing();

      //m_pwindowing = pwindowing;

      // m_pwindow = pimpl;

      //__refer(puserinteraction->m_pthreadUserInteraction, ::get_task() REFERENCING_DEBUGGING_COMMA_THIS_FUNCTION_FILE_LINE);

      //puserinteraction->m_pthreadUserInteraction->uiptra().add(puserinteraction);

      //__refer(m_pthreadUserImpl, puserinteraction->m_pthreadUserInteraction REFERENCING_DEBUGGING_COMMA_THIS_FUNCTION_FILE_LINE);

      //m_strDebug += ::str().demangle(puserinteraction->type_name()) + ";";

      //ASSERT(pusersystem->m_createstruct.lpszClass == nullptr || is_string_ok(pusersystem->m_createstruct.lpszClass) || __is_valid_atom(pusersystem->m_createstruct.lpszClass));

      //ENSURE_ARG(pusersystem->m_createstruct.lpszName == nullptr || is_string_ok(pusersystem->m_createstruct.lpszName));

      //wstring wstrClassName(pusersystem->m_createstruct.lpszClass);
         wstring wstrClassName;

         //if (wstrClassName.is_empty())
         //{

         //auto pimpl = m_pwindow;

         auto puserinteraction = user_interaction();

         //auto pwindowing = windowing();

         //wstrClassName = _windows_get_user_interaction_window_class(puserinteraction);

         //->initialize(system()->m_papplicationStartup);

         //}

         //pusersystem->m_createstruct.lpszClass = wstrClassName;

         if (!puserinteraction->m_pusersystem)
         {

            puserinteraction->m_pusersystem = __create_new< ::user::system >();

         }

         if (!puserinteraction->pre_create_window(puserinteraction->m_pusersystem))
         {

            //return false;

            throw ::exception(error_failed);

         }

         set_oswindow(this);

         //m_pwindow = pimpl;

         //pimpl->install_message_routing(puserinteraction);

         //install_message_routing(puserinteraction);

         //if (!hook_window_create(this))
         //{

         //   post_non_client_destroy();

         //   return false;

         //}

         // if window is not created, it may destroy this object, so keep the app as local ::payload

         //thread_property("wnd_init") = this;

         //::aura::window * papp = &papplication;

         //wstring wstrWindowName(pusersystem->m_createstruct.lpszName);
         wstring wstrWindowName;

         //string char

         //wstring wchar_t

         //if (wstrWindowName.is_empty())
         //{

         //   wstrWindowName = L"window";

         //}

#if 0

         WCHAR szTitle[256];
         WCHAR szWindowClass[256];

         wcscpy(szTitle, L"123");
         wcscpy(szWindowClass, L"WindowsDestkop1");

         //HWND hwnd = CreateWindowExW(pusersystem->m_createstruct.dwExStyle, szWindowClass, wstrWindowName, pusersystem->m_createstruct.style,
           // pusersystem->m_createstruct.x, pusersystem->m_createstruct.y, pusersystem->m_createstruct.cx, pusersystem->m_createstruct.cy, pusersystem->m_createstruct.hwndParent, pusersystem->m_createstruct.hMenu, pusersystem->m_createstruct.hInstance, pusersystem->m_createstruct.lpCreateParams);
         HWND hwnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPED,
            CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, pusersystem->m_createstruct.hInstance, nullptr);
         //if (!hwnd)
         //{
            //return false;
         //}

         ::ShowWindow(hwnd, SW_SHOWNORMAL);
         ::UpdateWindow(hwnd);

#if 0

         MSG msg;

         // Main message loop:
         while (mq_get_message(&msg, nullptr, 0, 0))
         {
            //if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
               TranslateMessage(&msg);
               DispatchMessage(&msg);
            }
         }

#else

         m_puserthread->run();

#endif

         //return true;

#else

      //unsigned int dwExStyle = puserinteraction->GetExStyle();
      //unsigned int dwStyle = puserinteraction->GetStyle();

         unsigned int dwExStyle = 0;
         unsigned int dwStyle = 0;

         auto pusersystem = puserinteraction->m_pusersystem;

         //CREATESTRUCTW createstruct{};

         //auto & createstruct = pusersystem->m_createstruct;

         wstrWindowName = puserinteraction->m_strWindowText2;

         //if (pusersystem->m_createstruct.lpszName)
         //{

         //   wstrWindowName = pusersystem->m_createstruct.lpszName;

         //}

         ::winrt::Windows::Foundation::Rect rectangleWindow;

         rectangleWindow.X = (float)puserinteraction->const_layout().design().origin().x();

         rectangleWindow.Y = (float)puserinteraction->const_layout().design().origin().y();

         rectangleWindow.Width = (float)puserinteraction->const_layout().design().size().cx();

         rectangleWindow.Height = (float)puserinteraction->const_layout().design().size().cy();

         auto pwindowing = windowing();

         if (!m_windowscorewindow)
         {

            //manual_reset_happening ev;

            //fork([this, &ev]()
              // {

            pwindowing->m_pwindowCreating = this;

            auto coreapplicationview = ::winrt::Windows::ApplicationModel::Core::CoreApplication::CreateNewView(pwindowing->m_frameworkviewsource);

            //Initialize(coreapplicationview);

            //SetWindow(coreapplicationview.CoreWindow());

            // m_windowscorewindow = m_coreapplicationview.CoreWindow();

              //    topic.set_happening();
                //  coreapplicationview.Dispatcher().ProcessEvents(
                  //   ::winrt::Windows::UI::Core::CoreProcessEventsOption::ProcessUntilQuit);

               //});

               //topic.wait();
            user_post([this]()
               {

               //   m_applicationview = ::winrt::Windows::UI::ViewManagement::ApplicationView::GetForCurrentView();

               //   if (rectangleWindow.Width > 0 && rectangleWindow.Height > 0)
               //   {

               //      m_applicationview.SetPreferredMinSize({ (float)rectangleWindow.Width, (float)rectangleWindow.Height });

               //   }

               m_windowscorewindow.Activate();



               //   //auto applicationview1 = m_applicationview;

               //   //auto Id1 = applicationview1.Id();

               //   //::winrt::Windows::UI::ViewManagement::ApplicationViewSwitcher::TryShowAsStandaloneAsync(
               //   //Id1,
               //   //::winrt::Windows::UI::ViewManagement::ViewSizePreference::UseMore);

               //   //rectangleWindow = m_windowscorewindow.Bounds();
               //
               //   if (rectangleWindow.Width > 0 && rectangleWindow.Height > 0)
               //   {

               //      m_applicationview.TryResizeView(::winrt::Windows::Foundation::Size({ (float)rectangleWindow.Width,(float)rectangleWindow.Height }));

               //   }




               });


         }
         //else
         //{

         user_post([this, pusersystem, puserinteraction, &rectangleWindow]()
         {


               ::int_rectangle rectangle;

               get_rect_normal(&rectangle);

               auto puserinteraction = user_interaction();

               auto & sketch = puserinteraction->const_layout().sketch();

               puserinteraction->place(rectangle);

               puserinteraction->place(rectangle, ::user::e_layout_design);


         });

         //}

         if (!puserinteraction->pre_create_window(pusersystem))
         {

            throw ::exception(error_failed);

         }

         //puserinteraction->m_puserinteractionTopLevel = puserinteraction->_top_level();

         //puserinteraction->m_puserframeParent = puserinteraction->_parent_frame();

         //puserinteraction->m_puserframeTopLevel = puserinteraction->_top_level_frame();

         //puserinteraction->m_pwindow = this;

         //set_window_long(GWL_STYLE, pusersystem->m_createstruct.style);

         //set_window_long(GWL_EXSTYLE, pusersystem->m_createstruct.dwExStyle);

         //install_message_routing(puserinteraction);

         //m_rectangleWindowScreen = m_rectangle;

         //send_message(e_message_create, 0, (LPARAM)&pusersystem->m_createstruct);

         puserinteraction->send_message(e_message_create, 0, 0);

         user_post([this]()

            {

                  if (m_windowscorewindow.Visible())
                  {

                     __on_window_visible();

                  }
   });

         //on_window_size_changed()

         //send_message(e_message_size, 0, MAKELPARAM(pusersystem->m_createstruct.cx, cy));

         //::int_size sizeDrawn;

         //synchronous_lock slGraphics(m_pgraphics->synchronization());

         //::synchronization_object * psync = m_pgraphics->get_draw_lock();

         //synchronous_lock synchronouslock(psync);

         ////::draw2d::graphics_pointer pgraphics = m_pgraphics->on_begin_draw();

         //slGraphics.unlock();

         synchronous_lock synchronouslock(puserinteraction->synchronization());

         if (rectangleWindow.Width > 0 && rectangleWindow.Height > 0)
         {

            puserinteraction->place(double_rectangle_dimension(rectangleWindow.X, rectangleWindow.Y, rectangleWindow.Width, rectangleWindow.Height));

         }

         puserinteraction->increment_reference_count(REFERENCING_DEBUGGING_THIS_FUNCTION_FILE_LINE);

         puserinteraction->m_ewindowflag |= ::e_window_flag_is_window;

         puserinteraction->m_ewindowflag |= ::e_window_flag_window_created;

         puserinteraction->set_flag(e_flag_task_started);

         //puserinteraction->m_layout.sketch().set_modified();

         //return true;



         //dwExStyle = createstruct.dwExStyle;
         //dwStyle = createstruct.style;

         windowing()->__synthesizes_creates_styles(puserinteraction, dwExStyle, dwStyle);

         pusersystem->m_pwindow = this;

         //puserinteraction->layout().sketch().set_modified();

         int x = puserinteraction->const_layout().sketch().origin().x();
         int y = puserinteraction->const_layout().sketch().origin().y();
         int cx = puserinteraction->const_layout().sketch().size().cx();
         int cy = puserinteraction->const_layout().sketch().size().cy();

         HWND hwndParent = nullptr;

         HMENU hmenu = nullptr;

         //      HINSTANCE hinstance = (HINSTANCE)GetModuleHandleW(L"windowing_universal_windows.dll");
         //
         //      void * lpCreateParams = nullptr;
         //
         //      if (puserinteraction->m_bMessageWindow)
         //      {
         //
         //         hwndParent = HWND_MESSAGE;
         //         dwExStyle = 0;
         //         dwStyle = 0;
         //         x = y = cx = cy = 0;
         //
         //      }
         //
         //      //if (puserinteraction->m_pusersystem)
         //      //{
         //
         //      //   lpCreateParams = puserinteraction->m_pusersystem->m_createstruct.lpCreateParams;
         //
         //      //}
         //
         //      HWND hwnd = ::CreateWindowExW(
         //         dwExStyle,
         //         wstrClassName,
         //         wstrWindowName,
         //         dwStyle,
         //         x,
         //         y,
         //         cx,
         //         cy,
         //         hwndParent,
         //         hmenu,
         //         hinstance,
         //         pusersystem);
         //
#endif
//
//      //HWND hwnd = CreateWindowW(wstrClassName, wstrWindowName, WS_OVERLAPPED,
//      //   CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, pusersystem->m_createstruct.hInstance, nullptr);
//
//      //::XXXShowWindow(hwnd,SW_SHOWNORMAL);
//      //::UpdateWindow(hwnd);
//
//      //bool bUnicode = IsWindowUnicode(hwnd);
//
//      unsigned int dwLastError = ::GetLastError();
//
//      //if (!unhook_window_create())
//      //{
//
//      //   post_non_client_destroy();        // cleanup if CreateWindowEx fails too soon
//
//      //}
//
         if (puserinteraction->m_bMessageWindow)
         {

            puserinteraction->m_ewindowflag -= e_window_flag_graphical;

         }

         //if (hwnd == nullptr)
         //{

         //   //if (papp == nullptr)
         //   //{

         //   //   return false;

         //   //}

         //   string strLastError = FormatMessageFromSystem(dwLastError);

         //   string strMessage;

         //   strMessage.formatf("%s\n\nSystem Error Code: %d", strLastError, dwLastError);

         //   information(trace_category_appmsg, e_trace_level_warning, "Warning: Window creation failed: get_last_error returned:\n");

         //   information(trace_category_appmsg, e_trace_level_warning, "%s\n", strMessage);

         //   try
         //   {

         //      if (dwLastError == 0x0000057e)
         //      {

         //         informationf("Cannot create a top-level child window.");

         //      }
         //      else
         //      {

         //         informationf("%s", strMessage);

         //      }

         //   }
         //   catch (...)
         //   {

         //   }

         //}

         //if (hwnd == nullptr)
         //{

         //   return false;

         //}

         //if (puserinteraction->m_bEdgeGestureDisableTouchWhenFullscreen)
         //{

         //   SetTouchDisableProperty(hwnd, true);

         //}

         puserinteraction->m_ewindowflag += ::e_window_flag_is_window;

         //puserinteraction->layout().sketch() = ::int_point(pusersystem->m_createstruct.x, pusersystem->m_createstruct.y);
         //puserinteraction->layout().sketch() = ::int_size(pusersystem->m_createstruct.cx, pusersystem->m_createstruct.cy);

         //puserinteraction->layout().window() = ::int_point(pusersystem->m_createstruct.x, pusersystem->m_createstruct.y);
         //puserinteraction->layout().window() = ::int_size(pusersystem->m_createstruct.cx, pusersystem->m_createstruct.cy);

         //bool bUnicode = ::IsWindowUnicode(hwnd) != false;

         //if (bUnicode)
         //{

         //   output_debug_string("window is unicode");

         //}
         //else
         //{

         //   output_debug_string("window is ANSI");

         //}

         ////WNDCLASSEXW wndcls;

         ////if (wstrClassName.get_length() > 0 && GetClassInfoExW(psystem->m_hinstance, wstrClassName, &wndcls) && wndcls.hIcon != nullptr)
         //{

         //   //papplication->set_icon(puserinteraction, __create_new< ::image::icon >(get_application(), wndcls.hIcon), false);

         //   //papplication->set_icon(puserinteraction, __create_new< ::image::icon >(get_application(), wndcls.hIcon), true);

         //}

         //if (hwnd != get_hwnd())
         //{

         //   set_hwnd(hwnd);
         //   //ASSERT(false); // should have been set in send msg hook

         //}

         //send_message(e_message_create);

         /// this Windows native window "holds" object to the
         /// wrapping object.
         puserinteraction->increment_reference_count();

         puserinteraction->m_ewindowflag |= e_window_flag_window_created;

         //return true;

      }


      void window::on_window_visibility_changed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs args)
      {

         if (args.Visible())
         {

            __on_window_visible();

         }
         else
         {

            auto pbuffer = __buffer(get_window_graphics());

            if (pbuffer && pbuffer->m_tristateCoreWindowVisible)
            {

               pbuffer->m_tristateCoreWindowVisible = false;

               pbuffer->DestroyWindowSizeDependentResources();

            }

         }

      }


      //void window::on_window_visibility_changed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::VisibilityChangedEventArgs args)
      //{

      //   if (args.Visible())
      //   {

      //      __on_window_visible();

      //   }
      //   else
      //   {

      //      auto pbuffer = __buffer(get_window_graphics());

      //      if (pbuffer && pbuffer->m_tristateCoreWindowVisible)
      //      {

      //         pbuffer->m_tristateCoreWindowVisible = false;

      //         pbuffer->DestroyWindowSizeDependentResources();

      //      }

      //   }

      //}


      void window::on_pointer_moved(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args)
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

         ::pointer<::user::message>pusermessage;

         ::winrt::Windows::UI::Input::PointerPoint pointerPoint = args.CurrentPoint();

         m_iMouse = pointerPoint.PointerId();

         auto pmouse = __create_new< ::message::mouse >();

         pusermessage = pmouse;

         pmouse->m_pwindow = this;

         pmouse->m_oswindow = this;

         pmouse->m_pointHost.x() = (int)pointerPoint.Position().X;

         pmouse->m_pointHost.y() = (int)pointerPoint.Position().Y;

         pmouse->m_pointAbsolute.x() = (int)pointerPoint.RawPosition().X;

         pmouse->m_pointAbsolute.y() = (int)pointerPoint.RawPosition().Y;

         pmouse->m_emessage = e_message_mouse_move;
         //pmouse->m_playeredUserPrimitive  = session()->m_puserinteractionHost;

         m_pointLastCursor = pointerPoint.RawPosition();

         //set_cursor_position({ (int) m_pointLastCursor.X, (int) m_pointLastCursor.Y});

         m_pointCursor2.x() = (int)pointerPoint.RawPosition().X;

         m_pointCursor2.y() = (int)pointerPoint.RawPosition().Y;

         puserinteraction->message_handler(pusermessage);

         m_timeLastMouseMove = ::time::now();

      }


      void window::on_pointer_pressed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args)
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

         auto pmouse = __create_new< ::message::mouse >();

         pmouse->m_pwindow = this;

         pmouse->m_oswindow = this;

         pmouse->m_pointHost.x() = (int)pointerPoint.Position().X;

         pmouse->m_pointHost.y() = (int)pointerPoint.Position().Y;

         pmouse->m_pointAbsolute.x() = (int)pointerPoint.RawPosition().X;

         pmouse->m_pointAbsolute.y() = (int)pointerPoint.RawPosition().Y;

         if (args.CurrentPoint().Properties().IsLeftButtonPressed() && !m_bLeftButton)
         {

            pmouse->m_emessage = e_message_left_button_down;

            m_bLeftButton = true;
            m_bMiddleButton = false;
            m_bRightButton = false;

         }
         else if (args.CurrentPoint().Properties().IsRightButtonPressed() && !m_bRightButton)
         {

            pmouse->m_emessage = e_message_right_button_down;

            m_bLeftButton = false;
            m_bMiddleButton = false;
            m_bRightButton = true;

         }
         else if (args.CurrentPoint().Properties().IsMiddleButtonPressed() && !m_bMiddleButton)
         {

            pmouse->m_emessage = e_message_middle_button_down;

            m_bLeftButton = false;
            m_bMiddleButton = true;
            m_bRightButton = false;

         }

         m_pointLastCursor = pointerPoint.RawPosition();

         m_pointCursor2.x() = (int)pointerPoint.RawPosition().X;

         m_pointCursor2.y() = (int)pointerPoint.RawPosition().Y;

         puserinteraction->message_handler(pmouse);

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

         auto pmouse = __create_new< ::message::mouse >();

         pmouse->m_pwindow = this;

         pmouse->m_oswindow = this;

         pmouse->m_pointHost.x() = (int)pointerPoint.Position().X;

         pmouse->m_pointHost.y() = (int)pointerPoint.Position().Y;

         pmouse->m_pointAbsolute.x() = (int)pointerPoint.RawPosition().X;

         pmouse->m_pointAbsolute.y() = (int)pointerPoint.RawPosition().Y;

         if (m_bLeftButton && !args.CurrentPoint().Properties().IsLeftButtonPressed())
         {

            pmouse->m_emessage = e_message_left_button_up;

            m_bLeftButton = false;

         }
         else if (m_bRightButton && !args.CurrentPoint().Properties().IsRightButtonPressed())
         {

            pmouse->m_emessage = e_message_right_button_up;

            m_bRightButton = false;

         }
         else if (m_bMiddleButton && !args.CurrentPoint().Properties().IsMiddleButtonPressed())
         {

            pmouse->m_emessage = e_message_middle_button_up;

            m_bMiddleButton = false;

         }

         m_pointLastCursor = pointerPoint.RawPosition();

         m_pointCursor2.x() = (int)pointerPoint.RawPosition().X;

         m_pointCursor2.y() = (int)pointerPoint.RawPosition().Y;

         puserinteraction->message_handler(pmouse);

      }


//void window::on_pointer_moved(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::PointerEventArgs args)
//{
//
//   auto puserinteraction = user_interaction();
//
//   if (puserinteraction == nullptr)
//   {
//
//      return;
//
//   }
//
//   //if (puserinteraction->m_pinteractionimpl == nullptr)
//   //{
//
//   //   return;
//
//   //}
//
//   ::pointer<::user::message>pusermessage;
//
//   ::winrt::Windows::UI::Input::PointerPoint pointerPoint = args.CurrentPoint();
//
//   m_iMouse = pointerPoint.PointerId();
//
//   auto pmouse = __create_new< ::message::mouse >();
//
//   pusermessage = pmouse;
//
//   pmouse->m_pwindow = this;
//
//   pmouse->m_oswindow = this;
//
//   pmouse->m_pointHost.x() = (int)pointerPoint.Position().X;
//
//   pmouse->m_pointHost.y() = (int)pointerPoint.Position().Y;
//
//   pmouse->m_pointAbsolute.x() = (int)pointerPoint.RawPosition().X;
//
//   pmouse->m_pointAbsolute.y() = (int)pointerPoint.RawPosition().Y;
//
//   pmouse->m_emessage = e_message_mouse_move;
//   //pmouse->m_playeredUserPrimitive  = session()->m_puserinteractionHost;
//
//   m_pointLastCursor = pointerPoint.RawPosition();
//
//   //set_cursor_position({ (int) m_pointLastCursor.X, (int) m_pointLastCursor.Y});
//
//   m_pointCursor2.x() = (int)pointerPoint.RawPosition().X;
//
//   m_pointCursor2.y() = (int)pointerPoint.RawPosition().Y;
//
//   puserinteraction->message_handler(pusermessage);
//
//   m_timeLastMouseMove = ::time::now();
//
//}
//
//
//void window::on_pointer_pressed(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::PointerEventArgs args)
//{
//
//   if (system() == nullptr)
//   {
//
//      return;
//
//   }
//
//   auto puserinteraction = user_interaction();
//
//   if (puserinteraction == nullptr)
//   {
//
//      return;
//
//   }
//
//   //if (puserinteraction->m_pinteractionimpl == nullptr)
//   //{
//
//   //   return;
//
//   //}
//
//   ::winrt::Windows::UI::Input::PointerPoint pointerPoint = args.CurrentPoint();
//
//   m_iMouse = pointerPoint.PointerId();
//
//   auto pmouse = __create_new< ::message::mouse >();
//
//   pmouse->m_pwindow = this;
//
//   pmouse->m_oswindow = this;
//
//   pmouse->m_pointHost.x() = (int)pointerPoint.Position().X;
//
//   pmouse->m_pointHost.y() = (int)pointerPoint.Position().Y;
//
//   pmouse->m_pointAbsolute.x() = (int)pointerPoint.RawPosition().X;
//
//   pmouse->m_pointAbsolute.y() = (int)pointerPoint.RawPosition().Y;
//
//   if (args.CurrentPoint().Properties().IsLeftButtonPressed() && !m_bLeftButton)
//   {
//
//      pmouse->m_emessage = e_message_left_button_down;
//
//      m_bLeftButton = true;
//      m_bMiddleButton = false;
//      m_bRightButton = false;
//
//   }
//   else if (args.CurrentPoint().Properties().IsRightButtonPressed() && !m_bRightButton)
//   {
//
//      pmouse->m_emessage = e_message_right_button_down;
//
//      m_bLeftButton = false;
//      m_bMiddleButton = false;
//      m_bRightButton = true;
//
//   }
//   else if (args.CurrentPoint().Properties().IsMiddleButtonPressed() && !m_bMiddleButton)
//   {
//
//      pmouse->m_emessage = e_message_middle_button_down;
//
//      m_bLeftButton = false;
//      m_bMiddleButton = true;
//      m_bRightButton = false;
//
//   }
//
//   m_pointLastCursor = pointerPoint.RawPosition();
//
//   m_pointCursor2.x() = (int)pointerPoint.RawPosition().X;
//
//   m_pointCursor2.y() = (int)pointerPoint.RawPosition().Y;
//
//   puserinteraction->message_handler(pmouse);
//
//}
//
//
//
//void window::on_pointer_released(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args)
//{
//
//   if (system() == nullptr)
//   {
//
//      return;
//
//   }
//
//   ::winrt::Windows::UI::Input::PointerPoint pointerPoint = args.CurrentPoint();
//
//   m_iMouse = pointerPoint.PointerId();
//
//   auto puserinteraction = user_interaction();
//
//   if (puserinteraction == nullptr)
//   {
//
//      return;
//
//   }
//
//   //if (puserinteraction->m_pinteractionimpl == nullptr)
//   //{
//
//   //   return;
//
//   //}
//
//   auto pmouse = __create_new< ::message::mouse >();
//
//   pmouse->m_pwindow = this;
//
//   pmouse->m_oswindow = this;
//
//   pmouse->m_pointHost.x() = (int)pointerPoint.Position().X;
//
//   pmouse->m_pointHost.y() = (int)pointerPoint.Position().Y;
//
//   pmouse->m_pointAbsolute.x() = (int)pointerPoint.RawPosition().X;
//
//   pmouse->m_pointAbsolute.y() = (int)pointerPoint.RawPosition().Y;
//
//   if (m_bLeftButton && !args.CurrentPoint().Properties().IsLeftButtonPressed())
//   {
//
//      pmouse->m_emessage = e_message_left_button_up;
//
//      m_bLeftButton = false;
//
//   }
//   else if (m_bRightButton && !args.CurrentPoint().Properties().IsRightButtonPressed())
//   {
//
//      pmouse->m_emessage = e_message_right_button_up;
//
//      m_bRightButton = false;
//
//   }
//   else if (m_bMiddleButton && !args.CurrentPoint().Properties().IsMiddleButtonPressed())
//   {
//
//      pmouse->m_emessage = e_message_middle_button_up;
//
//      m_bMiddleButton = false;
//
//   }
//
//   m_pointLastCursor = pointerPoint.RawPosition();
//
//   m_pointCursor2.x() = (int)pointerPoint.RawPosition().X;
//
//   m_pointCursor2.y() = (int)pointerPoint.RawPosition().Y;
//
//   puserinteraction->message_handler(pmouse);
//
//}


      ::int_rectangle window::get_input_content_rect()
      {

         return as_int_rectangle(_get_input_content_rect());

      }


      ::int_rectangle window::get_input_selection_rect()
      {

         return as_int_rectangle(_get_input_content_rect());

      }


      ::winrt::Windows::Foundation::Rect window::_get_input_content_rect()
      {

         ::winrt::Windows::Foundation::Rect rectangle;

         auto puserinteraction = user_interaction();

         auto puserprimitiveFocus = puserinteraction->get_keyboard_focus();

         if (puserprimitiveFocus)
         {

            ::cast <::user::interaction> puserinteractionFocus = puserprimitiveFocus;

            if (puserinteractionFocus)
            {

               ::int_rectangle r = puserinteractionFocus->window_rectangle();

               m_rectangleInputContentRect.X = (float)r.left();
               m_rectangleInputContentRect.Y = (float)r.top();
               m_rectangleInputContentRect.Width = (float)r.width();
               m_rectangleInputContentRect.Height = (float)r.height();

            }

         }

         rectangle = m_rectangleInputContentRect;

         return rectangle;

      }


      ::winrt::Windows::Foundation::Rect window::_get_input_selection_rect()
      {

         ::winrt::Windows::Foundation::Rect rectangle = m_rectangleInputSelectionRect;

         return rectangle;

      }


      wide_string window::get_input_text()
      {

         wide_string wstrText;

         auto puserinteraction = user_interaction();

         auto pfocusui = puserinteraction->get_keyboard_focus();

         ::cast < ::user::interaction > puserinteractionFocus = pfocusui;

         if (puserinteractionFocus)
         {

            string strText;

            strText = puserinteractionFocus->get_text();

            wstrText = strText;

         }

         return wstrText;

      }


      bool window::set_input_text(const wide_string & wstr)
      {

         auto puserinteraction = user_interaction();

         auto pfocusui = puserinteraction->get_keyboard_focus();

         ::cast < ::user::interaction > puserinteractionFocus = pfocusui;

         if (puserinteractionFocus)
         {

            string strText;

            strText = wstr;

            puserinteractionFocus->set_text(strText, e_source_user);

         }

         //return wstrText;
         return true;

      }


      //void window::get_input_text(const wide_string & wstr)
      //{


      //}


      ::winrt::Windows::Foundation::Rect window::window_rectangle()
      {

         ::winrt::Windows::Foundation::Rect rectangle = m_rectangleLastWindowRect;

         /*      rectangle.X = 0;
               rectangle.Y = 0;
               rectangle.Width = 600;
               rectangle.Height = 480;

               if(m_windowscorewindow == nullptr)
                  return rectangle;

               ::wait(m_windowscorewindow->Dispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal, ref ___new ::winrt::Windows::UI::Core::DispatchedHandler ([=, &rectangle]()
               {
                  try
                  {
                     rectangle = m_windowscorewindow->Bounds;
                  }
                  catch(...)
                  {
                  }
               })));*/

         return rectangle;

      }


      ::winrt::Windows::Foundation::Point window::get_cursor_position()
      {

         single_lock synchronouslock(m_pparticleMutex, true);

         ::winrt::Windows::Foundation::Point p = m_pointLastCursor;

         /*      if(m_windowscorewindow == nullptr)
                  return p;

               if(g_iMouse < 0)
                  return p;

               ::wait(m_windowscorewindow->Dispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal, ref ___new ::winrt::Windows::UI::Core::DispatchedHandler ([=, &p]()
               {
                  try
                  {

                     ::winrt::Windows::Foundation::Collections::IVectorView < ::winrt::Windows::Devices::Input::PointerDevice > deva = ::winrt::Windows::Devices::Input::PointerDevice::GetPointerDevices();

                     for(unsigned int u = 0; u < deva->Size; u++)
                     {

                        ::winrt::Windows::Devices::Input::PointerDevice dev = deva->GetAt(u);

                        if(dev->PointerDeviceType == ::winrt::Windows::Devices::Input::PointerDeviceType::Mouse)
                        {

                           ::winrt::Windows::UI::Input::PointerPoint pointerPoint = ::winrt::Windows::UI::Input::PointerPoint::GetCurrentPoint(g_iMouse);

                           p = pointerPoint->RawPosition;

                           break;

                        }

                     }

                  }
                  catch(...)
                  {
                  }
               })), 5); // wait for up to 5 ::times

               m_pointLastCursor = p;*/

         return p;

      }


      //::int_point window::get_mouse_cursor_position()
      //{

      //   auto p = get_cursor_position();

      //   return { (int) p.X, (int) p.Y };


      //}


      void window::on_message_size(::message::message * pmessage)
      {

      }


      //void window::user_post(const ::procedure & procedure)
      //{

      //   auto dispatcher = m_windowscorewindow.Dispatcher();

      //   if (dispatcher)
      //   {

      //      auto handler = ::winrt::Windows::UI::Core::DispatchedHandler([procedure]()
      //         {

      //            procedure();

      //         });

      //      dispatcher.RunAsync(
      //         ::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal,
      //         handler);

      //   }


      //   //return ::success;

      //}


      bool window::is_branch_current() const
      {

         auto dispatcher = ((window *)this)->_get_dispatcher();

         return dispatcher.HasThreadAccess();

      }


      ::winrt::Windows::UI::Core::CoreDispatcher window::_get_dispatcher()
      {

         ::winrt::Windows::UI::Core::CoreDispatcher dispatcher = nullptr;

         if (m_coreapplicationview)
         {

            dispatcher = m_coreapplicationview.Dispatcher();

         }
         else if (m_windowscorewindow)
         {

            dispatcher = m_windowscorewindow.Dispatcher();

         }
         else
         {

            dispatcher = ::winrt::Windows::ApplicationModel::Core::CoreApplication::MainView().CoreWindow().Dispatcher();

         }

         return dispatcher;

      }


      void window::_user_post(const ::procedure & procedure)
      {

         ::winrt::Windows::UI::Core::CoreDispatcher dispatcher = _get_dispatcher();

         if (dispatcher.HasThreadAccess())
         {

            procedure();

         }
         else
         {

            dispatcher.RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal,
               ::winrt::Windows::UI::Core::DispatchedHandler([procedure]()
                  {

                     procedure();

                  }));

         }

      }


      //void window::Initialize(CoreApplicationView const & coreapplicationview)
      //{

      //   m_coreapplicationview = coreapplicationview;

      //   ::winrt::Windows::ApplicationModel::Core::CoreApplication::Suspending(::winrt::Windows::Foundation::EventHandler<::winrt::Windows::ApplicationModel::SuspendingEventArgs>(this, &window::OnSuspending));

      //   ::winrt::Windows::ApplicationModel::Core::CoreApplication::Resuming(::winrt::Windows::Foundation::EventHandler<::winrt::Windows::Foundation::IInspectable >(this, &window::OnResuming));

      //   m_coreapplicationview.Activated({ this, &window::OnActivated });
      //   ::winrt::Windows::UI::ViewManagement::UISettings uisettings;

      //   auto uicolorBackground = uisettings.GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

      //   ::color::color colorBackground;

      //   colorBackground = argb(255, uicolorBackground.R, uicolorBackground.G, uicolorBackground.B);

      //   system()->set_background_color(colorBackground);

      //   //m_coreapplicationview.Activated(::winrt::Windows::Foundation::TypedEventHandler<::winrt::Windows::ApplicationModel::Core::CoreApplicationView, ::winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs>(this, &window::OnActivated));

      //   //Initialize(coreapplicationview);

      //}



      //void window::SetWindow(::winrt::Windows::UI::Core::CoreWindow const & window)
      //{

      //   m_windowscorewindow = window;
      //   // Specify the cursor type as the standard arrow cursor.
      //   m_windowscorewindow.PointerCursor(CoreCursor{ CoreCursorType::Arrow, 0 });

      //   // Allow the application to respond when the window size changes.
      //   //window.SizeChanged({ this, &App::OnWindowSizeChanged });



      //   //m_windowscorewindow = window;

      //   m_resizemanager = ::winrt::Windows::UI::Core::CoreWindowResizeManager::GetForCurrentView();

      //   m_resizemanager.ShouldWaitForLayoutCompletion(true);

      //   //auto coreTitleBar = ::winrt::Windows::ApplicationModel::Core::CoreApplication::GetCurrentView()->TitleBar;

      //   //coreTitleBar->ExtendViewIntoTitleBar = true;

      //   m_tokenActivated = m_windowscorewindow.Activated(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::WindowActivatedEventArgs>(this, &window::CoreWindow_WindowActivated));

      //   m_tokenClosed = m_windowscorewindow.Closed(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CoreWindowEventArgs>(this, &window::CoreWindow_CoreWindowClosed));

      //   m_tokenKeyDown = m_windowscorewindow.KeyDown(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs>(this, &window::CoreWindow_KeyDown));

      //   m_tokenPointerPressed = m_windowscorewindow.PointerPressed(::winrt::Windows::Foundation::TypedEventHandler < ::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs>(this, &window::CoreWindow_PointerPressed));

      //   //window::SetWindow(window);

      //   //pbuffer = __create_new< directx_base >();

      //   //pbuffer->system() = system();

      //   auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

      //   //pbuffer->Initialize(window, displayinformation.LogicalDpi());

      //   //pbuffer->initialize(system()->m_papplicationStartup);

      //   //install_directx_application_message_routing();

      //   //initialize_directx_application();

      //   //m_bXXXFirst = true;

      //   //system()->get_session()->system()->windowing()->m_pwindowFirst = this;

      //   //system()->get_session()->system()->windowing()->m_bXXXFirst = true;

      //   //auto pwindowing = windowing();

      //   //if (!pwindowing->m_bAppInit)
      //   //{

      //   //   pwindowing->app_init();

      //   //}

      //   //if (!system()->node()->m_bHasNodePostedSystemInitialRequest)
      //   //{

      //   //   system()->node()->m_bHasNodePostedSystemInitialRequest = true;

      //   //   system()->defer_post_initial_request();

      //   //}


      //}

      void window::_set_oswindow(::oswindow oswindow)
      {

         

      }


      void window::_main_send(const ::procedure & procedure)
      {

         auto window = m_windowscorewindow;

         if (!window)
         {

            ::cast < ::windowing_universal_windows::window > pwindowOwner =
                  owner_window();

            if(pwindowOwner)
            {

               window = pwindowOwner->m_windowscorewindow;

            }

         }

         auto dispatcher = window.Dispatcher();

         if (dispatcher.HasThreadAccess())
         {

            procedure();

            return;

         }

         //__matter_send_procedure(this, this, &node::node_post, procedure);

   //      CLASS_DECL_ACME bool main_synchronous(const class time & time, const ::procedure & function)
   //      {

         auto phappening = __allocate manual_reset_happening();

         _user_post([procedure, phappening]
                   {

                   procedure();

                   phappening->set_happening();

                   });


         auto timeout = procedure.timeout();

         if (!phappening->wait(timeout))
         {

            throw ::exception(error_timeout);
            //phappening.release();

            //return false;

         }

         ///return true;
   //
   //      }

      }

      
      void window::_main_post(const ::procedure & procedure)
      {

         ::universal_windows::acme::windowing::window::_main_post(procedure);

         //

         /*auto window = m_windowscorewindow;

         auto dispatcher = window.Dispatcher();

         dispatcher.RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal,
            ::winrt::Windows::UI::Core::DispatchedHandler([procedure]()
               {
                  
                  procedure();

               }));*/

      }


   //} // namespace windowing_universal_windows


} // namespace windowing_universal_windows



