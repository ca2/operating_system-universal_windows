#include "framework.h"
#include "interaction_impl.h"
#include "acme/constant/message.h"
#include "acme/exception/not_implemented.h"
#include "aura/graphics/graphics/graphics.h"
#include "aura/graphics/image/image.h"
#include "acme/parallelization/synchronous_lock.h"
#include "aura/platform/session.h"
#include "aura/message/user.h"
#include "aura/user/user/user.h"
#include "aura/windowing/window.h"
#include "aura/windowing/windowing.h"


namespace aura_universal_windows
{


   interaction_impl::interaction_impl()
   {

      m_pImpl2 = this;
      m_bNotifyLayoutCompletedPending        = false;
      m_bScreenRelativeMouseMessagePosition  = false;
      m_nModalResult                         = 0;

   }


   void interaction_impl::construct(::oswindow hWnd)
   {

      m_bScreenRelativeMouseMessagePosition  = false;

      m_nModalResult = 0;

   }


   //const MSG* interaction_impl::GetCurrentMessage()
   //{

   //   return nullptr;

   //}


   LRESULT interaction_impl::Default()
   {

      return 0;

   }


   void interaction_impl::pre_subclass_window()
   {

   }


   bool interaction_impl::_native_create_window_ex(::pointer<::user::system>pusersystem)
   {

      auto x = m_puserinteraction->const_layout().design().origin().x();

      auto y = m_puserinteraction->const_layout().design().origin().y();

      auto cx = m_puserinteraction->width();

      auto cy = m_puserinteraction->height();

      return true;

   }


   bool interaction_impl::pre_create_window(::user::system * pusersystem)
   {

      throw ::exception(todo);

      return true;

   }

   interaction_impl::~interaction_impl()
   {

   }


   void interaction_impl::install_message_routing(::channel * pchannel)
   {
      last_install_message_routing(pchannel);
      //m_pbuffer->InstallMessageHandling(pinterface);
      MESSAGE_LINK(e_message_destroy, pchannel, this,&interaction_impl::on_message_destroy);
      MESSAGE_LINK(e_message_paint, pchannel, this,&interaction_impl::_001OnPaint);
      MESSAGE_LINK(WM_PRINT, pchannel, this,&interaction_impl::_001OnPrint);
      if(m_puserinteraction != nullptr)
      {
         m_puserinteraction->install_message_routing(pchannel);
      }
      MESSAGE_LINK(e_message_create, pchannel, this,&interaction_impl::on_message_create);
      //MESSAGE_LINK(e_message_set_cursor, pchannel, this,&interaction_impl::on_message_set_cursor);
      //MESSAGE_LINK(e_message_erase_background, pchannel, this,&interaction_impl::_001OnEraseBkgnd);
      MESSAGE_LINK(e_message_reposition, pchannel, this,&interaction_impl::on_message_move);
      MESSAGE_LINK(e_message_size, pchannel, this,&interaction_impl::on_message_size);
      MESSAGE_LINK(e_message_set_focus, pchannel, this, &interaction_impl::on_message_set_focus);
      MESSAGE_LINK(e_message_kill_focus, pchannel, this, &interaction_impl::on_message_kill_focus);
      //MESSAGE_LINK(e_message_show_window, pchannel, this,&interaction_impl::on_message_show_window);
//      MESSAGE_LINK(ca2m_PRODEVIAN_SYNCH, pchannel, this,&interaction_impl::_001OnProdevianSynch);
      prio_install_message_routing(pchannel);
   }

   void interaction_impl::on_message_move(::message::message * pmessage)
   {
   }

   void interaction_impl::on_message_size(::message::message * pmessage)
   {


   }


   void interaction_impl::on_message_set_focus(::message::message* pmessage)
   {

      ::pointer<::message::set_keyboard_focus>psetfocus(pmessage);

      //if (psession->get_focus_ui())
      //{

         //m_pframeworkview.get().SetInternalFocus();

      //}

   }


   void interaction_impl::on_message_kill_focus(::message::message* pmessage)
   {

      ::pointer<::message::kill_keyboard_focus>pkillfocus(pmessage);

      //m_pframeworkview.get().RemoveInternalFocus();

   }


   void interaction_impl::show_software_keyboard(::user::element* pelement)
   {

      

   }


   void interaction_impl::hide_software_keyboard(::user::element* pelement)
   {

      

   }



   void interaction_impl::on_message_destroy(::message::message * pmessage)
   {
      
      __UNREFERENCED_PARAMETER(pmessage);
      
      Default();

   }


   void interaction_impl::post_non_client_destroy()
   {

      ::windowing::window::post_non_client_destroy();

#ifdef WINDOWS_DESKTOP
      
      WNDPROC pfnWndProc = WNDPROC(GetWindowLongPtr(get_handle(), GWLP_WNDPROC));
      
      Default();

      if (WNDPROC(GetWindowLongPtr(get_handle(), GWLP_WNDPROC)) == pfnWndProc)
      {
         
         WNDPROC pfnSuper = *GetSuperWndProcAddr();
         
         if (pfnSuper != nullptr)
         {

            SetWindowLongPtr(get_handle(), GWLP_WNDPROC, reinterpret_cast<iptr>(pfnSuper));

         }

      }

#else

      throw ::exception(todo);

#endif
      
      //ASSERT(get_handle() == nullptr);

   }


   void interaction_impl::on_final_release()
   {
      //if(get_handle() != nullptr)
         DestroyWindow();    // will call post_non_client_destroy
      //else
        // post_non_client_destroy();
   }
   bool interaction_impl::DestroyWindow()
   {
      //single_lock synchronouslock(m_pthread == nullptr ? nullptr : &m_pthread->m_mutex,true);
      //::windowing::window * pWnd;
      //hwnd_map * pMap;
      //oswindow hWndOrig;
      bool bResult = false;

      //if((get_handle() == nullptr))
        // return false;

      //XXXShowWindow(SW_HIDE);

      return bResult;

   }


   LRESULT interaction_impl::DefWindowProc(unsigned int nMsg,WPARAM wParam,lparam lParam)
   {
      return 0;

#ifdef WINDOWS_DESKTOP
      if (m_pfnSuper != nullptr)
         return ::CallWindowProc(m_pfnSuper, get_handle(), nMsg, wParam, lParam);

      WNDPROC pfnWndProc;
      if ((pfnWndProc = *GetSuperWndProcAddr()) == nullptr)
         return ::DefWindowProc(get_handle(), nMsg, wParam, lParam);
      else
         return ::CallWindowProc(pfnWndProc, get_handle(), nMsg, wParam, lParam);
#else
      throw ::exception(todo);
#endif
   }

#ifdef WINDOWS_DESKTOP
   WNDPROC* interaction_impl::GetSuperWndProcAddr()
   {
      // Note: it is no longer necessary to override GetSuperWndProcAddr
      //  for each control class with a different WNDCLASS.
      //  This implementation now uses instance data, such that the previous
      //  WNDPROC can be anything.

      return &m_pfnSuper;
   }
#endif


   void interaction_impl::pre_translate_message(::message::message * pmessage)
   {
      __UNREFERENCED_PARAMETER(pmessage);
      // no default processing
   }


   void interaction_impl::get_window_text(string & rString)
   {


  /*    ::wait(m_window->Dispatcher->RunAsync(
             CoreDispatcherPriority::Normal,
             ref ___new ::winrt::Windows::UI::Core::DispatchedHandler([this]()
      {*/

      //m_pwindowing->windowing_sync(15_s, __routine([this]()
      //   {

      //   auto  applicationview = ::winrt::Windows::UI::ViewManagement::ApplicationView::GetForCurrentView();

      //   m_strWindowText = applicationview.Title().begin();

      //}));

      rString = m_strWindowText;

   }


#ifdef WINDOWS_DESKTOP

   int interaction_impl::GetDlgItemText(int nID, string & rString) const
   {
      ASSERT(::is_window(get_handle()));
      rString = "";    // is_empty without deallocating

      oswindow hWnd = ::GetDlgItem(get_handle(), nID);
      if (hWnd != nullptr)
      {
         int nLen = ::GetWindowTextLength(hWnd);
         ::GetWindowText(hWnd, rString.get_buffer(nLen), nLen+1);
         rString.ReleaseBuffer();
      }

      return (int)rString.get_length();

   }

#endif

#ifdef WINDOWS_DESKTOP
   bool interaction_impl::GetWindowPlacement(WINDOWPLACEMENT* lpuserinteractionpl)
   {
      ASSERT(::is_window(get_handle()));
      lpuserinteractionpl->length = sizeof(WINDOWPLACEMENT);
      return ::GetWindowPlacement(get_handle(), lpuserinteractionpl) != false;
   }

   bool interaction_impl::SetWindowPlacement(const WINDOWPLACEMENT* lpuserinteractionpl)
   {
      ASSERT(::is_window(get_handle()));
      ((WINDOWPLACEMENT*)lpuserinteractionpl)->length = sizeof(WINDOWPLACEMENT);
      return ::SetWindowPlacement(get_handle(), lpuserinteractionpl) != false;
   }
   /////////////////////////////////////////////////////////////////////////////
   // interaction_impl will delegate owner draw messages to self drawing controls

   // Drawing: for all 4 control types
   void interaction_impl::OnDrawItem(int /*nIDCtl*/, LPDRAWITEMSTRUCT lpDrawItemStruct)
   {

      // reflect notification to child interaction_impl control
      if (ReflectLastMsg(lpDrawItemStruct->hwndItem))
         return;     // eat it

      // not handled - do default
      Default();
   }

   // Drawing: for all 4 control types
   int interaction_impl::OnCompareItem(int /*nIDCtl*/, LPCOMPAREITEMSTRUCT lpCompareItemStruct)
   {
      // reflect notification to child interaction_impl control
      LRESULT lResult;
      if (ReflectLastMsg(lpCompareItemStruct->hwndItem, &lResult))
         return (int)lResult;        // eat it

      // not handled - do default
      return (int)Default();
   }

   void interaction_impl::OnDeleteItem(int /*nIDCtl*/, LPDELETEITEMSTRUCT lpDeleteItemStruct)
   {
      // reflect notification to child interaction_impl control
      if (ReflectLastMsg(lpDeleteItemStruct->hwndItem))
         return;     // eat it
      // not handled - do default
      Default();
   }

#endif


   bool interaction_impl::_EnableToolTips(bool bEnable,unsigned int nFlag)
   {
      __UNREFERENCED_PARAMETER(bEnable);
      __UNREFERENCED_PARAMETER(nFlag);
      return false;
   }




   ::windowing::window * interaction_impl::GetAncestor(unsigned int gaFlags) const
   {

#ifdef WINDOWS_DESKTOP
      ASSERT(::is_window((oswindow)get_os_data()));
      return  ::universal_windows::interaction_impl::from_handle(::GetAncestor((oswindow)get_os_data(), gaFlags));
#else
      throw ::exception(todo);
#endif

      return nullptr;


   }



#ifdef WINDOWS_DESKTOP
   bool interaction_impl::GetScrollBarInfo(int idObject, PSCROLLBARINFO psbi) const
   {
      ASSERT(::is_window((oswindow)get_os_data()));
      ASSERT(psbi != nullptr);
      return ::GetScrollBarInfo((oswindow)get_os_data(), idObject, psbi) != false;
   }

   bool interaction_impl::GetTitleBarInfo(PTITLEBARINFO pti) const
   {
      ASSERT(::is_window((oswindow)get_os_data()));
      ASSERT(pti != nullptr);
      return ::GetTitleBarInfo((oswindow)get_os_data(), pti) != false;
   }
#endif

//   bool interaction_impl::AnimateWindow(::time ::time,unsigned int dwFlags)
//   {
//#ifdef WINDOWS_DESKTOP
//      ASSERT(::is_window((oswindow)get_os_data()));
//      return ::AnimateWindow((oswindow)get_os_data(), ::time, dwFlags) != false;
//#else
//      throw ::exception(todo);
//#endif
//      return false;
//   }

   //bool interaction_impl::FlashWindowEx(unsigned int dwFlags,unsigned int  uCount,::time tickTimeout)
   //{
   //   throw ::exception(todo);

   //   //   ASSERT(::is_window((oswindow)get_os_data()));
   //   //   FLASHWINFO fwi;
   //   //   fwi.cbSize = sizeof(fwi);
   //   //   fwi.hwnd = (oswindow)get_os_data();
   //   //   fwi.dwFlags = dwFlags;
   //   //   fwi.uCount = uCount;
   //   //   fwi.tickTimeout = tickTimeout;

   //   //   return ::FlashWindowEx(&fwi) != false;
   //   return false;
   //}



   //bool interaction_impl::SetLayeredWindowAttributes(color32_t crKey,unsigned char bAlpha,unsigned int dwFlags)
   //{
   //   throw ::exception(todo);
   //   //ASSERT(::is_window((oswindow)get_os_data()));
   //   //return ::SetLayeredWindowAttributes((oswindow)get_os_data(), crKey, bAlpha, dwFlags) != false;
   //}

   //bool interaction_impl::UpdateLayeredWindow(::draw2d::graphics * pDCDst,::int_point *pptDst,::int_size *psize,
   //      ::draw2d::graphics * pDCSrc,::int_point *pptSrc,color32_t crKey,BLENDFUNCTION *pblend,unsigned int dwFlags)
   //{
   //   throw ::exception(todo);
   //   //ASSERT(::is_window((oswindow)get_os_data()));
   //   //return ::UpdateLayeredWindow((oswindow)get_os_data(), WIN_HDC(pDCDst), pptDst, psize,
   //   //   WIN_HDC(pDCSrc), pptSrc, crKey, pblend, dwFlags) != false;
   //}


   //bool interaction_impl::GetLayeredWindowAttributes(color32_t *pcrKey,unsigned char *pbAlpha,unsigned int *pdwFlags) const
   //{
   //   throw ::exception(todo);
   //   //ASSERT(::is_window((oswindow)get_os_data()));
   //   //return ::GetLayeredWindowAttributes((oswindow)get_os_data(), pcrKey, pbAlpha, pdwFlags) != false;
   //}

   bool interaction_impl::PrintWindow(::draw2d::graphics_pointer & pgraphics,unsigned int nFlags) const
   {
      throw ::exception(todo);
      //ASSERT(::is_window((oswindow)get_os_data()));
      //return ::PrintWindow((oswindow)get_os_data(), (HDC)(dynamic_cast<::universal_windows::graphics * >(pgraphics))->get_os_data(), nFlags) != false;
      return false;
   }


   //LRESULT interaction_impl::OnNTCtlColor(WPARAM wParam,LPARAM lParam)
   //{

   //   throw ::exception(todo);

   //}


   void interaction_impl::PrepareForHelp()
   {

   }
   

#ifdef WINDOWS_DESKTOP
   void interaction_impl::WinHelpInternal(dword_ptr dwData, unsigned int nCmd)
   {
      __UNREFERENCED_PARAMETER(dwData);
      __UNREFERENCED_PARAMETER(nCmd);
      throw ::not_implemented();
   }

#endif

   void interaction_impl::route_command(::message::command * pcommand, bool bRouteToKeyDescendant)
   {

      channel::route_command(pcommand, bRouteToKeyDescendant);

      if (pcommand->m_bRet)
      {

         return;

      }

   }


   void interaction_impl::handle(::topic * ptopic, ::context * pcontext)
   {

      __UNREFERENCED_PARAMETER(ptopic);

      __UNREFERENCED_PARAMETER(pcontext);

//      return false;

   }


   //::e_status interaction_impl::main_async(const ::procedure & procedure, enum_priority epriority)
   //{

   //   ::winrt::Windows::UI::Core::CoreDispatcher dispatcher(nullptr);

   //   if (m_impact.get())
   //   {

   //      dispatcher = m_impact.get().Dispatcher();

   //   }
   //   else
   //   {

   //      dispatcher = m_window.get().Dispatcher();

   //   }

   //   pdispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal, ref ___new ::winrt::Windows::UI::Core::DispatchedHandler([routine]()
   //      {

   //         routine();

   //      }));

   //   return ::success;

   //}


   void interaction_impl::_002OnDraw(::image::image * pimage)
   {
      throw ::exception(todo);
      //::CallWindowProc(*GetSuperWndProcAddr(), get_handle(), WM_PRINT, (WPARAM)((dynamic_cast<::universal_windows::graphics * >(pgraphics))->get_os_data()), (LPARAM)(PRF_CHILDREN | PRF_CLIENT));

   }


   void interaction_impl::message_handler(::message::message * pmessage)
   {

      if (pmessage == nullptr)
      {

         return;

      }

      //if(m_puserinteraction != nullptr)
      //{

      //   m_puserinteraction->pre_translate_message(pusermessage);

      //   if(pusermessage->m_bRet)
      //   {

      //      return;

      //   }

      //}

      //if(m_plistener != nullptr)
      //{

      //   m_plistener->message_queue_message_handler(pusermessage);

      //   if(pusermessage->m_bRet)
      //   {

      //      return;

      //   }

      //}


      if(pmessage->m_atom == e_message_key_down ||
         pmessage->m_atom == e_message_key_up ||
         pmessage->m_atom == e_message_char ||
         pmessage->m_atom == e_message_sys_key_down ||
         pmessage->m_atom == e_message_sys_key_up ||
         pmessage->m_atom == e_message_sys_char)
      {

         auto pkey = pmessage->m_union.m_pkey;

         //psession->keyboard().translate_os_key_message(pkey);

         if(pmessage->m_atom == e_message_key_down || pmessage->m_atom == e_message_sys_key_down)
         {

            

            try
            {
               psession->set_key_pressed(pkey->m_ekey,true);
            }
            catch(...)
            {
            }
         }
         else if(pmessage->m_atom == e_message_key_up || pmessage->m_atom == e_message_sys_key_up)
         {

            

            try
            {
               psession->set_key_pressed(pkey->m_ekey,false);
            }
            catch(...)
            {
            }
         }
      }

      if(pmessage->m_atom == e_message_timer)
      {
//         m_puserinteraction->get_application()->step_timer();
      }
      else if(pmessage->m_atom == e_message_left_button_down)
      {
         //g_puserinteractionLastLButtonDown = m_puserinteraction;
      }
      /*      else if(pusermessage->m_atom == CA2M_BERGEDGE)
      {
      if(pusermessage->m_wparam == BERGEDGE_GETAPP)
      {
      ::aura::application ** ppapp= (::aura::application **) pusermessage->m_lparam;
      *ppapp = get_application();
      pusermessage->m_bRet = true;
      return;
      }
      }*/
      pmessage->set_lresult(0);

      //_000OnMouseLeave(pusermessage);

      if(pmessage->m_atom == e_message_left_button_down ||
         pmessage->m_atom == e_message_left_button_up ||
         pmessage->m_atom == e_message_middle_button_down ||
         pmessage->m_atom == e_message_middle_button_up ||
         pmessage->m_atom == e_message_right_button_down ||
         pmessage->m_atom == e_message_right_button_up ||
         pmessage->m_atom == e_message_mouse_move ||
         pmessage->m_atom == e_message_mouse_wheel)
      {

         auto pmouse = pmessage->m_union.m_pmouse;

         //if (pmessage)
         //{

         //   if (pmessage->m_atom == e_message_left_button_up)
         //   {

         //      output_debug_string("e_message_left_button_up");

         //   }

         //}

         //

         //psession->on_ui_mouse_message(pmouse);


         ////papplication->m_pointCursor = pmouse->m_point;
         ////if(get_application()->m_pcoreapp->m_psession != nullptr)
         ////{
         ////   psession->m_pointCursor = pmouse->m_point;
         ////}
         ////if(m_puserinteraction != nullptr && m_puserinteraction->get_application()->m_pcoreapp->m_psession != nullptr && m_puserinteraction->get_application()->m_pcoreapp->m_psession != get_application()->m_pcoreapp->m_psession)
         ////{
         ////   Sess(m_puserinteraction->get_application()->m_pcoreapp->m_psession).m_pointCursor = pmouse->m_point;
         ////}

         ////::pointer<base_session>psession;
         ////if(get_application()->m_pcoreapp->is_system())
         ////{
         ////   psession = ::auraacmesystem()->query_session(0);
         ////   if(psession != nullptr && psession->m_bSessionSynchronizedCursor)
         ////   {
         ////      psession->m_pointCursor = pmouse->m_point;
         ////   }
         ////}

         //if(m_bTranslateMouseMessageCursor && !pmouse->m_bTranslated)
         //{
         //   pmouse->m_bTranslated = true;
         //   int_rectangle rectangleWindow;
         //   if(m_bScreenRelativeMouseMessagePosition)
         //   {
         //      /*               ::int_rectangle rectangleWindow32;
         //                     ::window_rectangle(get_handle(), &rectangleWindow32);
         //                     ::copy(rectangleWindow, rectangleWindow32);*/
         //   }
         //   else
         //   {

         //      m_puserinteraction->window_rectangle(rectangleWindow);

         //   }

         //   //if(get_session()->get_monitor_count() > 0)
         //   //{
         //   //   
         //   //   ::int_rectangle rcMonitor;

         //   //   get_session()->get_monitor_rectangle(0,&rcMonitor);
         //   //   if(rectangleWindow.left() >= rcMonitor.left())
         //   //      pmouse->m_point.x += (int)rectangleWindow.left();
         //   //   if(rectangleWindow.top() >= rcMonitor.top())
         //   //      pmouse->m_point.y += (int)rectangleWindow.top();
         //   //}
         //   //else
         //   {
         //      if(rectangleWindow.left() >= 0)
         //         pmouse->m_point.x += (int)rectangleWindow.left();
         //      if(rectangleWindow.top() >= 0)
         //         pmouse->m_point.y += (int)rectangleWindow.top();
         //   }
         //}

         //if(pmessage->m_atom == e_message_mouse_move)
         //{
         //   // We are at the message handler procedure.
         //   // mouse messages originated from message handler and that are mouse move events should end up with the correct cursor.
         //   // So the procedure starts by setting to the default cursor,
         //   // what forces, at the end of message processing, setting the bergedge cursor to the default cursor, if no other
         //   // handler has set it to another one.
         //   //pmouse->m_ecursor = cursor_default;
         //}

         ////_008OnMouse(pmouse);

         //m_puserinteraction->route_message(pmouse);

         if (on_mouse_message(pmouse))
         {

            return;

         }

      }
      else if(pmessage->m_atom == e_message_key_down ||
      pmessage->m_atom == e_message_key_up ||
      pmessage->m_atom == e_message_char)
      {

         auto pkey = pmessage->m_union.m_pkey;

         

         auto puserprimitiveFocus = m_puserinteraction->get_keyboard_focus();

         ::user::interaction * puserinteractionFocus = puserprimitiveFocus
            ? puserprimitiveFocus->m_puserinteraction : nullptr;

         if(puserinteractionFocus != nullptr
               && puserinteractionFocus->is_window()
               && puserinteractionFocus->top_level() != nullptr)
         {
            puserinteractionFocus->send_message(pkey);
            if(pmessage->m_bRet)
               return;
         }
         else if(!pkey->m_bRet)
         {
            if(m_puserinteraction != nullptr)
            {
               m_puserinteraction->_000OnKey(pkey);
               if(pmessage->m_bRet)
                  return;
            }
         }
         pmessage->set_lresult(DefWindowProc((unsigned int)pmessage->m_atom.as_huge_integer(), pmessage->m_wparam, pmessage->m_lparam));
         return;
      }
      //if(pmessage->m_atom == e_message_event)
      //{
      //   if(m_puserinteraction != nullptr)
      //   {
      //      m_puserinteraction->handle_event((::user::control_event *)pmessage->m_lparam.m_lparam);
      //   }
      //   else
      //   {
      //      handle_event((::user::control_event *)pmessage->m_lparam.m_lparam);
      //   }
      //   return;
      //}
      //(this->*m_pfnDispatchWindowProc)(pmessage);

      m_puserinteraction->route_message(pmessage);

      if (pmessage->m_bRet)
      {

         return;

      }

      /*
      if(m_puserinteraction != nullptr)
      {
      m_puserinteraction->_user_message_handler(pmessage);
      if(pmessage->m_bRet)
      return;
      }
      */
      pmessage->set_lresult(DefWindowProc((unsigned int)pmessage->m_atom.as_huge_integer(), pmessage->m_wparam, pmessage->m_lparam));
   }

   /*
   bool interaction_impl::OnWndMsg(const ::atom & atom, WPARAM wParam, LPARAM lParam, LRESULT* pResult)
   {
   LRESULT lResult = 0;
   union MessageMapFunctions mmf;
   mmf.pfn = 0;
   CInternalGlobalLock winMsgLock;
   // special case for commands
   if (message == e_message_command)
   {
   if (OnCommand(wParam, lParam))
   {
   lResult = 1;
   goto LReturnTrue;
   }
   return false;
   }

   // special case for notifies
   if (message == WM_NOTIFY)
   {
   NMHDR* pNMHDR = (NMHDR*)lParam;
   if (pNMHDR->hwndFrom != nullptr && OnNotify(wParam, lParam, &lResult))
   goto LReturnTrue;
   return false;
   }

   // special case for activation
   if (message == e_message_activate)
   __handle_activate(this, wParam, ::universal_windows::interaction_impl::from_handle((oswindow)lParam));

   // special case for set cursor HTERROR
   if (message == e_message_set_cursor &&
   __handle_set_cursor(this, (short)LOWORD(lParam), HIWORD(lParam)))
   {
   lResult = 1;
   goto LReturnTrue;
   }

   // special case for windows that contain windowless ActiveX controls
   bool bHandled;

   bHandled = false;

   const __MSGMAP* pMessageMap; pMessageMap = GetMessageMap();
   unsigned int iHash; iHash = (LOWORD((dword_ptr)pMessageMap)  message) & (iHashMax-1);
   winMsgLock.lock(CRIT_WINMSGCACHE);
   __MSG_CACHE* pMsgCache; pMsgCache = &gen_MsgCache[iHash];
   const __MSGMAP_ENTRY* lpEntry;
   if (message == pMsgCache->nMsg && pMessageMap == pMsgCache->pMessageMap)
   {
   // cache hit
   lpEntry = pMsgCache->lpEntry;
   winMsgLock.unlock();
   if (lpEntry == nullptr)
   return false;

   // cache hit, and it needs to be handled
   if (message < 0xC000)
   goto LDispatch;
   else
   goto LDispatchRegistered;
   }
   else
   {
   // not in cache, look for it
   pMsgCache->nMsg = message;
   pMsgCache->pMessageMap = pMessageMap;

   for (/* pMessageMap already init'ed */ /*; pMessageMap->pfnGetBaseMap != nullptr;
pMessageMap = (*pMessageMap->pfnGetBaseMap)())
{
// Note: catch not so common but fatal mistake!!
//       // 
ASSERT(pMessageMap != (*pMessageMap->pfnGetBaseMap)());
if (message < 0xC000)
{
// constant interaction_impl message
if ((lpEntry = ::ca2::FindMessageEntry(pMessageMap->lpEntries,
message, 0, 0)) != nullptr)
{
pMsgCache->lpEntry = lpEntry;
winMsgLock.unlock();
goto LDispatch;
}
}
else
{
// registered windows message
lpEntry = pMessageMap->lpEntries;
while ((lpEntry = ::ca2::FindMessageEntry(lpEntry, 0xC000, 0, 0)) != nullptr)
{
unsigned int* pnID = (unsigned int*)(lpEntry->nSig);
ASSERT(*pnID >= 0xC000 || *pnID == 0);
// must be successfully registered
if (*pnID == message)
{
pMsgCache->lpEntry = lpEntry;
winMsgLock.unlock();
goto LDispatchRegistered;
}
lpEntry++;      // keep looking past this one
}
}
}

pMsgCache->lpEntry = nullptr;
winMsgLock.unlock();
return false;
}

LDispatch:
ASSERT(message < 0xC000);

mmf.pfn = lpEntry->pfn;

switch (lpEntry->nSig)
{
default:
ASSERT(false);
break;
case ::ca2::Sig_l_p:
{
::int_point point(lParam);
lResult = (this->*mmf.pfn_l_p)(point);
break;
}
case ::ca2::Sig_b_D_v:
lResult = (this->*mmf.pfn_b_D)(::universal_windows::graphics::from_handle(reinterpret_cast<HDC>(wParam)));
break;

case ::ca2::Sig_b_b_v:
lResult = (this->*mmf.pfn_b_b)(static_cast<bool>(wParam));
break;

case ::ca2::Sig_b_u_v:
lResult = (this->*mmf.pfn_b_u)(static_cast<unsigned int>(wParam));
break;

case ::ca2::Sig_b_h_v:
lResult = (this->*mmf.pfn_b_h)(reinterpret_cast<HANDLE>(wParam));
break;

case ::ca2::Sig_i_u_v:
lResult = (this->*mmf.pfn_i_u)(static_cast<unsigned int>(wParam));
break;

case ::ca2::Sig_C_v_v:
lResult = reinterpret_cast<LRESULT>((this->*mmf.pfn_C_v)());
break;

case ::ca2::Sig_v_u_W:
(this->*mmf.pfn_v_u_W)(static_cast<unsigned int>(wParam),
::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(lParam)));
break;

case ::ca2::Sig_u_u_v:
lResult = (this->*mmf.pfn_u_u)(static_cast<unsigned int>(wParam));
break;

case ::ca2::Sig_b_v_v:
lResult = (this->*mmf.pfn_b_v)();
break;

case ::ca2::Sig_b_W_uu:
lResult = (this->*mmf.pfn_b_W_u_u)(::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(wParam)),
LOWORD(lParam), HIWORD(lParam));
break;

case ::ca2::Sig_b_W_COPYDATASTRUCT:
lResult = (this->*mmf.pfn_b_W_COPYDATASTRUCT)(
::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(wParam)),
reinterpret_cast<COPYDATASTRUCT*>(lParam));
break;

case ::ca2::Sig_b_v_HELPINFO:
lResult = (this->*mmf.pfn_b_HELPINFO)(reinterpret_cast<LPHELPINFO>(lParam));
break;

case ::ca2::Sig_CTLCOLOR:
{
// special case for OnCtlColor to avoid too many temporary objects
ASSERT(message == WM_CTLCOLOR);
__CTLCOLOR* pCtl = reinterpret_cast<__CTLCOLOR*>(lParam);
::draw2d::graphics_pointer dcTemp;
dcTemp.set_handle1(pCtl->hDC);
interaction_impl wndTemp;
wndTemp.set_handle(pCtl->hWnd);
unsigned int nCtlType = pCtl->nCtlType;
// if not coming from a permanent interaction_impl, use stack temporary
::windowing::window * pWnd = ::universal_windows::interaction_impl::FromHandlePermanent(wndTemp.get_handle());
if (pWnd == nullptr)
{
pWnd = &wndTemp;
}
HBRUSH hbr = (this->*mmf.pfn_B_D_W_u)(&dcTemp, pWnd, nCtlType);
// fast detach of temporary objects
dcTemp.set_handle1(nullptr);
wndTemp.set_handle(nullptr);
lResult = reinterpret_cast<LRESULT>(hbr);
}
break;

case ::ca2::Sig_CTLCOLOR_REFLECT:
{
// special case for CtlColor to avoid too many temporary objects
ASSERT(message == WM_REFLECT_BASE+WM_CTLCOLOR);
__CTLCOLOR* pCtl = reinterpret_cast<__CTLCOLOR*>(lParam);
::draw2d::graphics_pointer dcTemp;
dcTemp.set_handle1(pCtl->hDC);
unsigned int nCtlType = pCtl->nCtlType;
HBRUSH hbr = (this->*mmf.pfn_B_D_u)(&dcTemp, nCtlType);
// fast detach of temporary objects
dcTemp.set_handle1(nullptr);
lResult = reinterpret_cast<LRESULT>(hbr);
}
break;

case ::ca2::Sig_i_u_W_u:
lResult = (this->*mmf.pfn_i_u_W_u)(LOWORD(wParam),
::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(lParam)), HIWORD(wParam));
break;

case ::ca2::Sig_i_uu_v:
lResult = (this->*mmf.pfn_i_u_u)(LOWORD(wParam), HIWORD(wParam));
break;

case ::ca2::Sig_i_W_uu:
lResult = (this->*mmf.pfn_i_W_u_u)(::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(wParam)),
LOWORD(lParam), HIWORD(lParam));
break;

case ::ca2::Sig_i_v_s:
lResult = (this->*mmf.pfn_i_s)(reinterpret_cast<char *>(lParam));
break;

case ::ca2::Sig_l_w_l:
lResult = (this->*mmf.pfn_l_w_l)(wParam, lParam);
break;



case ::ca2::Sig_v_b_h:
(this->*mmf.pfn_v_b_h)(static_cast<bool>(wParam),
reinterpret_cast<HANDLE>(lParam));
break;

case ::ca2::Sig_v_h_v:
(this->*mmf.pfn_v_h)(reinterpret_cast<HANDLE>(wParam));
break;

case ::ca2::Sig_v_h_h:
(this->*mmf.pfn_v_h_h)(reinterpret_cast<HANDLE>(wParam),
reinterpret_cast<HANDLE>(lParam));
break;

case ::ca2::Sig_v_v_v:
(this->*mmf.pfn_v_v)();
break;

case ::ca2::Sig_v_u_v:
(this->*mmf.pfn_v_u)(static_cast<unsigned int>(wParam));
break;

case ::ca2::Sig_v_u_u:
(this->*mmf.pfn_v_u_u)(static_cast<unsigned int>(wParam), static_cast<unsigned int>(lParam));
break;

case ::ca2::Sig_v_uu_v:
(this->*mmf.pfn_v_u_u)(LOWORD(wParam), HIWORD(wParam));
break;

case ::ca2::Sig_v_v_ii:
(this->*mmf.pfn_v_i_i)(lparam_int_x(lParam), lparam_int_y(lParam));
break;

case ::ca2::Sig_v_u_uu:
(this->*mmf.pfn_v_u_u_u)(static_cast<unsigned int>(wParam), LOWORD(lParam), HIWORD(lParam));
break;

case ::ca2::Sig_v_u_ii:
(this->*mmf.pfn_v_u_i_i)(static_cast<unsigned int>(wParam), LOWORD(lParam), HIWORD(lParam));
break;

case ::ca2::Sig_v_w_l:
(this->*mmf.pfn_v_w_l)(wParam, lParam);
break;

case ::ca2::Sig_MDIACTIVATE:
(this->*mmf.pfn_v_b_W_W)(get_handle() == reinterpret_cast<oswindow>(lParam),
::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(lParam)),
::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(wParam)));
break;

case ::ca2::Sig_v_D_v:
(this->*mmf.pfn_v_D)(::universal_windows::graphics::from_handle(reinterpret_cast<HDC>(wParam)));
break;


case ::ca2::Sig_v_W_v:
(this->*mmf.pfn_v_W)(::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(wParam)));
break;

case ::ca2::Sig_v_v_W:
(this->*mmf.pfn_v_W)(::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(lParam)));
break;

case ::ca2::Sig_v_W_uu:
(this->*mmf.pfn_v_W_u_u)(::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(wParam)), LOWORD(lParam),
HIWORD(lParam));
break;

case ::ca2::Sig_v_W_p:
{
::int_point point(lParam);
(this->*mmf.pfn_v_W_p)(::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(wParam)), point);
}
break;

case ::ca2::Sig_v_W_h:
(this->*mmf.pfn_v_W_h)(::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(wParam)),
reinterpret_cast<HANDLE>(lParam));
break;

case ::ca2::Sig_ACTIVATE:
(this->*mmf.pfn_v_u_W_b)(LOWORD(wParam),
::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(lParam)), HIWORD(wParam));
break;

case ::ca2::Sig_SCROLL:
case ::ca2::Sig_SCROLL_REFLECT:
{
// special case for e_message_scroll_y and e_message_scroll_x
ASSERT(message == e_message_scroll_y || message == e_message_scroll_x ||
message == e_message_scroll_y+WM_REFLECT_BASE || message == e_message_scroll_x+WM_REFLECT_BASE);
int nScrollCode = (short)LOWORD(wParam);
int nPos = (short)HIWORD(wParam);
if (lpEntry->nSig == ::ca2::Sig_SCROLL)
(this->*mmf.pfn_v_u_u_W)(nScrollCode, nPos,
::universal_windows::interaction_impl::from_handle(reinterpret_cast<oswindow>(lParam)));
else
(this->*mmf.pfn_v_u_u)(nScrollCode, nPos);
}
break;

case ::ca2::Sig_v_v_s:
(this->*mmf.pfn_v_s)(reinterpret_cast<char *>(lParam));
break;

case ::ca2::Sig_v_u_cs:
(this->*mmf.pfn_v_u_cs)(static_cast<unsigned int>(wParam), reinterpret_cast<const char *>(lParam));
break;

case ::ca2::Sig_OWNERDRAW:
(this->*mmf.pfn_v_i_s)(static_cast<int>(wParam), reinterpret_cast<char *>(lParam));
lResult = true;
break;

case ::ca2::Sig_i_i_s:
lResult = (this->*mmf.pfn_i_i_s)(static_cast<int>(wParam), reinterpret_cast<char *>(lParam));
break;

case ::ca2::Sig_u_v_p:
{
::int_point point(lParam);
lResult = (this->*mmf.pfn_u_p)(point);
}
break;

case ::ca2::Sig_u_v_v:
lResult = (this->*mmf.pfn_u_v)();
break;

case ::ca2::Sig_v_b_NCCALCSIZEPARAMS:
(this->*mmf.pfn_v_b_NCCALCSIZEPARAMS)(static_cast<bool>(wParam),
reinterpret_cast<NCCALCSIZE_PARAMS*>(lParam));
break;

case ::ca2::Sig_v_v_WINDOWPOS:
(this->*mmf.pfn_v_v_WINDOWPOS)(reinterpret_cast<WINDOWPOS*>(lParam));
break;

case ::ca2::Sig_v_uu_M:
(this->*mmf.pfn_v_u_u_M)(LOWORD(wParam), HIWORD(wParam), reinterpret_cast<HMENU>(lParam));
break;

case ::ca2::Sig_v_u_p:
{
::int_point point(lParam);
(this->*mmf.pfn_v_u_p)(static_cast<unsigned int>(wParam), point);
}
break;

case ::ca2::Sig_SIZING:
(this->*mmf.pfn_v_u_pr)(static_cast<unsigned int>(wParam), reinterpret_cast<::int_rectangle *>(lParam));
lResult = true;
break;

case ::ca2::Sig_MOUSEWHEEL:
lResult = (this->*mmf.pfn_b_u_s_p)(LOWORD(wParam), (short)HIWORD(wParam),
int_point(lparam_int_x(lParam), lparam_int_y(lParam)));
if (!lResult)
return false;
break;
case ::ca2::Sig_l:
lResult = (this->*mmf.pfn_l_v)();
if (lResult != 0)
return false;
break;
}
goto LReturnTrue;

LDispatchRegistered:    // for registered windows messages
ASSERT(message >= 0xC000);
ASSERT(sizeof(mmf) == sizeof(mmf.pfn));
mmf.pfn = lpEntry->pfn;
lResult = (this->*mmf.pfn_l_w_l)(wParam, lParam);

LReturnTrue:
if (pResult != nullptr)
*pResult = lResult;
return true;
}
*/


   /////////////////////////////////////////////////////////////////////////////
   // interaction_impl command handling


   //bool interaction_impl::OnCommand(WPARAM wParam,LPARAM lParam)
   //{
   //   
   //   __UNREFERENCED_PARAMETER(wParam);
   //   __UNREFERENCED_PARAMETER(lParam);

   //   return false;

   //}


   //bool interaction_impl::OnNotify(WPARAM,LPARAM lParam,LRESULT* pResult)
   //{
   //   ASSERT(pResult != nullptr);
   //   NMHDR* pNMHDR = (NMHDR*)lParam;
   //   oswindow hWndCtrl = (oswindow)pNMHDR->hwndFrom;

   //   // get the child ID from the interaction_impl itself
   //   //      uptr nID = __get_dialog_control_id(hWndCtrl);
   //   //      int nCode = pNMHDR->code;

   //   ASSERT(hWndCtrl != nullptr);
   //   ASSERT(::is_window(hWndCtrl));

   //   //if(gen_ThreadState->m_hLockoutNotifyWindow == get_handle())
   //   //   return true;        // locked out - ignore control notification

   //   // reflect notification to child interaction_impl control
   //   if(ReflectLastMsg(hWndCtrl,pResult))
   //      return true;        // eaten by child

   //   //      __NOTIFY notify;
   //   //    notify.pResult = pResult;
   //   //  notify.pNMHDR = pNMHDR;
   //   //xxx   return _001OnCommand((unsigned int)nID, MAKELONG(nCode, WM_NOTIFY), &notify, nullptr);
   //   return false;
   //}

   /////////////////////////////////////////////////////////////////////////////
   // interaction_impl extensions

   //::user::frame_window *  interaction_impl::get_parent_frame()
   //{
   //   if(get_handle() == nullptr) // no Window attached
   //   {
   //      return nullptr;
   //   }

   //   ASSERT_VALID(this);

   //   ::user::interaction * puiParent = get_parent();  // start with one parent up
   //   while(puiParent != nullptr)
   //   {
   //      if(puiParent->is_frame_window())
   //      {
   //         return dynamic_cast <::user::frame_window *> (puiParent);
   //      }
   //      puiParent = puiParent->get_parent();
   //   }
   //   return nullptr;
   //}

   ///* trans oswindow CLASS_DECL_AURA __get_parent_owner(::user::interaction * hWnd)
   //{
   //// check for permanent-owned interaction_impl first
   //::windowing::window * pWnd = ::universal_windows::interaction_impl::FromHandlePermanent(hWnd);
   //if (pWnd != nullptr)
   //return WIN_WINDOW(pWnd)->get_owner();

   //// otherwise, return parent in the Windows sense
   //return (::GetWindowLong(hWnd, GWL_STYLE) & WS_CHILD) ?
   //::get_parent(hWnd) : ::GetWindow(hWnd, GW_OWNER);
   //}*/


   //::user::interaction *  interaction_impl::get_top_level()
   //{
   //   if(get_handle() == nullptr) // no Window attached
   //      return nullptr;

   //   ASSERT_VALID(this);

   //   ::user::interaction * hWndParent = this;
   //   ::user::interaction * hWndT;
   //   while((hWndT = ::user::get_parent_owner(hWndParent)) != nullptr)
   //      hWndParent = hWndT;

   //   return hWndParent;
   //}

   //::user::interaction *  interaction_impl::GetTopLevelOwner()
   //{

   //   throw ::exception(todo);


   //   //if (get_handle() == nullptr) // no Window attached
   //   //   return nullptr;

   //   //ASSERT_VALID(this);

   //   //oswindow hWndOwner = get_handle();
   //   //oswindow hWndT;
   //   //while ((hWndT = ::GetWindow(hWndOwner, GW_OWNER)) != nullptr)
   //   //   hWndOwner = hWndT;

   //   //return ::universal_windows::interaction_impl::from_handle(hWndOwner);
   //}

   //::user::interaction *  interaction_impl::GetParentOwner()
   //{

   //   throw ::exception(todo);

   //   //if (get_handle() == nullptr) // no Window attached
   //   //   return nullptr;

   //   //ASSERT_VALID(this);

   //   //oswindow hWndParent = get_handle();
   //   //oswindow hWndT;
   //   //while ((::GetWindowLong(hWndParent, GWL_STYLE) & WS_CHILD) &&
   //   //   (hWndT = ::get_parent(hWndParent)) != nullptr)
   //   //{
   //   //   hWndParent = hWndT;
   //   //}

   //   //return ::universal_windows::interaction_impl::from_handle(hWndParent);
   //}

   //bool interaction_impl::IsTopParentActive()
   //{
   //   ASSERT(get_handle() != nullptr);
   //   ASSERT_VALID(this);

   //   ::user::interaction *pWndTopLevel=EnsureTopLevelParent();

   //   return interaction_impl::GetForegroundWindow() == pWndTopLevel->GetLastActivePopup();
   //}

   void interaction_impl::ActivateTopParent()
   {

      throw ::exception(todo);

      //// special activate logic for floating toolbars and palettes
      //::windowing::window * pActiveWnd = GetForegroundWindow();
      //if (pActiveWnd == nullptr || !(WIN_WINDOW(pActiveWnd)->get_handle() == get_handle() || ::IsChild(WIN_WINDOW(pActiveWnd)->get_handle(), get_handle())))
      //{
      //   // clicking on floating frame when it does not have
      //   // focus itself -- activate the toplevel frame instead.
      //   EnsureTopLevelParent()->set_foreground_window();
      //}
   }

   //::user::frame_window *  interaction_impl::top_level_frame()
   //{
   //   if(get_handle() == nullptr) // no Window attached
   //      return nullptr;

   //   ASSERT_VALID(this);

   //   ::user::frame_window* pFrameWnd = nullptr;
   //   if(m_puserinteraction != this)
   //      pFrameWnd = dynamic_cast <::user::frame_window *> (m_puserinteraction.m_p);
   //   else
   //      pFrameWnd = dynamic_cast <::user::frame_window *> (this);
   //   if(pFrameWnd == nullptr || !pFrameWnd->is_frame_window())
   //      pFrameWnd = get_parent_frame();

   //   if(pFrameWnd != nullptr)
   //   {
   //      ::user:: frame_window* pTemp;
   //      while((pTemp = pFrameWnd->get_parent_frame()) != nullptr)
   //         pFrameWnd = pTemp;
   //   }
   //   return pFrameWnd;
   //}

   /*   ::windowing::window * interaction_impl::GetSafeOwner(::windowing::window * pParent, oswindow* pWndTop)
      {
      oswindow hWnd = GetSafeOwner_((oswindow) pParent->get_os_data(), pWndTop);
      return ::universal_windows::interaction_impl::from_handle(hWnd);
      }
      */
   //int interaction_impl::message_box(const ::string & lpszText, const ::string & lpszCaption,unsigned int nType)
   //{
   //   if(lpszCaption == nullptr)
   //      lpszCaption = papplication->m_strAppName;
   //   int nResult = ::message_box(get_handle(),lpszText,lpszCaption,nType,callback);
   //   return nResult;
   //}

   
   int interaction_impl::SetScrollPos(int nBar,int nPos,bool bRedraw)
   {

      throw ::exception(todo);

      //return ::SetScrollPos(get_handle(), nBar, nPos, bRedraw);

      return 0;

   }


   int interaction_impl::GetScrollPos(int nBar) const
   {

      throw ::exception(todo);

      //return ::GetScrollPos(get_handle(), nBar);

      return 0;

   }


   void interaction_impl::SetScrollRange(int nBar,int nMinPos,int nMaxPos,bool bRedraw)
   {

      throw ::exception(todo);

      //::SetScrollRange(get_handle(), nBar, nMinPos, nMaxPos, bRedraw);

   }


   void interaction_impl::GetScrollRange(int nBar,LPINT lpMinPos,LPINT lpMaxPos) const
   {

      throw ::exception(todo);

      //::GetScrollRange(get_handle(), nBar, lpMinPos, lpMaxPos);
   }

   // Turn on/off non-control scrollbars
   //   for WS_?SCROLL scrollbars - show/hide them
   //   for control scrollbar - enable/disable them
   void interaction_impl::EnableScrollBarCtrl(int nBar,bool bEnable)
   {
      // WS_?SCROLL scrollbar - show or hide
      ShowScrollBar(nBar,bEnable);
   }

#ifdef WINDOWS_DESKTOP

   bool interaction_impl::SetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, bool bRedraw)
   {
      ASSERT(lpScrollInfo != nullptr);

      oswindow hWnd = get_handle();
      lpScrollInfo->cbSize = sizeof(*lpScrollInfo);
      ::SetScrollInfo(hWnd, nBar, lpScrollInfo, bRedraw);
      return true;
   }

   bool interaction_impl::GetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, unsigned int nMask)
   {
      __UNREFERENCED_PARAMETER(nMask);
      ASSERT(lpScrollInfo != nullptr);

      oswindow hWnd = get_handle();
      return ::GetScrollInfo(hWnd, nBar, lpScrollInfo) != false;
   }

#endif

   int interaction_impl::GetScrollLimit(int nBar)
   {

#ifdef WINDOWS_DESKTOP

      int nMin, nMax;
      GetScrollRange(nBar, &nMin, &nMax);
      SCROLLINFO info;
      if (GetScrollInfo(nBar, &info, SIF_PAGE))
      {
         nMax -= maximum(info.nPage-1,0);
      }
      return nMax;

#endif

      return 0;

   }

   //void interaction_impl::ScrollWindow(int xAmount,int yAmount,const ::int_rectangle & rectangle,const ::int_rectangle * lpClipRect)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));

   //   //if (is_window_visible() || lpRect != nullptr || lpClipRect != nullptr)
   //   //{
   //   //   // When visible, let Windows do the scrolling
   //   //   ::ScrollWindow(get_handle(), xAmount, yAmount, lpRect, lpClipRect);
   //   //}
   //   //else
   //   //{
   //   //   // Windows does not perform any scrolling if the interaction_impl is
   //   //   // not visible.  This leaves child windows unscrolled.
   //   //   // To account for this oversight, the child windows are moved
   //   //   // directly instead.
   //   //   oswindow hWndChild = ::GetWindow(get_handle(), GW_CHILD);
   //   //   if (hWndChild != nullptr)
   //   //   {
   //   //      for (; hWndChild != nullptr;
   //   //         hWndChild = ::GetNextWindow(hWndChild, GW_HWNDNEXT))
   //   //      {
   //   //         ::int_rectangle rectangle;
   //   //         ::window_rectangle(hWndChild, &rectangle);
   //   //         screen_to_client(&rectangle);
   //   //         ::set_window_position(hWndChild, nullptr,
   //   //            rectangle.left()+xAmount, rectangle.top()+yAmount, 0, 0,
   //   //            SWP_NOSIZE|SWP_NOACTIVATE|SWP_NOZORDER);
   //   //      }
   //   //   }
   //   //}

   //}


   void interaction_impl::CalcWindowRect(::int_rectangle * lpClientRect,unsigned int nAdjustType)
   {

      throw ::exception(todo);

      //unsigned int dwExStyle = GetExStyle();
      //if (nAdjustType == 0)
      //   dwExStyle &= ~WS_EX_CLIENTEDGE;
      //::AdjustWindowRectEx(lpClientRect, GetStyle(), false, dwExStyle);
   }

   /////////////////////////////////////////////////////////////////////////////
   // Special keyboard/system command processing

   //bool interaction_impl::HandleFloatingSysCommand(unsigned int nID,LPARAM lParam)
   //{


   //   throw ::exception(todo);


   //   return false;


   //   //::user::interaction* pParent = get_top_level();
   //   //switch (nID & 0xfff0)
   //   //{
   //   //case SC_PREVWINDOW:
   //   //case SC_NEXTWINDOW:
   //   //   if (LOWORD(lParam) == VK_F6 && pParent != nullptr)
   //   //   {
   //   //      pParent->XXXSetFocus();
   //   //      return true;
   //   //   }
   //   //   break;

   //   //case SC_CLOSE:
   //   //case SC_KEYMENU:
   //   //   // Check lParam.  If it is 0L, then the ::account::user may have done
   //   //   // an Alt+Tab, so just ignore it.  This breaks the ability to
   //   //   // just press the Alt-key and have the first menu selected,
   //   //   // but this is minor compared to what happens in the Alt+Tab
   //   //   // case.
   //   //   if ((nID & 0xfff0) == SC_CLOSE || lParam != 0L)
   //   //   {
   //   //      if (pParent != nullptr)
   //   //      {
   //   //         // Sending the above WM_SYSCOMMAND may destroy the cast,
   //   //         // so we have to be careful about restoring activation
   //   //         // and focus after sending it.
   //   //         oswindow hWndSave = get_handle();
   //   //         oswindow hWndFocus = ::GetFocus();
   //   //         pParent->XXXSetActiveWindow();
   //   //         pParent->send_message(WM_SYSCOMMAND, nID, lParam);

   //   //         // be very careful here...
   //   //         if (::is_window(hWndSave))
   //   //            ::XXXSetActiveWindow(hWndSave);
   //   //         if (::is_window(hWndFocus))
   //   //            ::XXXSetFocus(hWndFocus);
   //   //      }
   //   //   }
   //   //   return true;
   //   //}
   //   //return false;
   //}


   void interaction_impl::WalkPreTranslateTree(::user::interaction * puiStop,::message::message * pmessage)
   {
      ASSERT(puiStop == nullptr || puiStop->is_window());
      ASSERT(pmessage != nullptr);

      ::pointer<::user::message>pusermessage(pmessage);
      // walk from the target interaction_impl up to the hWndStop interaction_impl checking
      //  if any interaction_impl wants to translate this message

      for(::user::interaction * pinteraction = ::user::message_user_interaction(pusermessage); pinteraction != nullptr; pinteraction->get_parent())
      {

         pinteraction->pre_translate_message(pmessage);

         if(pmessage->m_bRet)
            return; // trapped by target interaction_impl (eg: accelerators)

         // got to hWndStop interaction_impl without interest
         if(pinteraction == puiStop)
            break;

      }
      // no special processing
   }

   //   return false;   // let the parent handle it
   //}

   //void interaction_impl::OnParentNotify(unsigned int message,LPARAM lParam)
   //{
   //   if((LOWORD(message) == e_message_create || LOWORD(message) == e_message_destroy))
   //   {
   //      if(ReflectLastMsg((oswindow)lParam))
   //         return;     // eat it
   //   }
   //   // not handled - do default
   //   Default();
   //}

   void interaction_impl::OnSetFocus(::windowing::window *)
   {
      bool bHandled;

      bHandled = false;
      if(!bHandled)
      {
         Default();
      }
   }

   //LRESULT interaction_impl::OnActivateTopLevel(WPARAM wParam,LPARAM)
   //{
   //   if(LOWORD(wParam) == WA_INACTIVE)
   //   {
   //      //         __MODULE_THREAD_STATE* pModuleThreadState = __get_module_thread_state();
   //   }

   //   return 0;
   //}

   void interaction_impl::OnSysColorChange()
   {
      throw ::not_implemented();

   }

   //bool gen_GotScrollLines;

   //void interaction_impl::OnSettingChange(unsigned int uFlags, const ::string & lpszSection)
   //{
   //   UNUSED_ALWAYS(uFlags);
   //   UNUSED_ALWAYS(lpszSection);

   //   // force refresh of settings that we cache
   //   gen_GotScrollLines = false;


   //   //interaction_impl::OnDisplayChange(0,0);    // to update system metrics, etc.
   //}

   void interaction_impl::OnDevModeChange(char * lpDeviceName)
   {
      __UNREFERENCED_PARAMETER(lpDeviceName);
      throw ::not_implemented();
      /*application* pApp = ::auraacmesystem();
      if (pApp != nullptr && pApp->GetMainWnd() == this)
      pApp->DevModeChange(lpDeviceName);

      // forward this message to all other child windows
      if (!(GetStyle() & WS_CHILD))
      {
      const MSG* pMsg = GetCurrentMessage();
      send_message_to_descendants(pMsg->message, pMsg->wParam, pMsg->lParam,
      true, true);
      }*/
   }


#ifdef WINDOWS_DESKTOP

   bool interaction_impl::OnHelpInfo(HELPINFO* /*pHelpInfo*/)
   {
      if (!(GetStyle() & WS_CHILD))
      {
         ::user::interaction* pMainWnd = ::auraacmesystem()->GetMainWnd();
         if (pMainWnd != nullptr &&
               GetKeyState(VK_SHIFT) >= 0 &&
               GetKeyState(VK_CONTROL) >= 0 &&
               GetKeyState(VK_MENU) >= 0)
         {
            //            pMainWnd->SendMessage(e_message_command, ID_HELP);
            return true;
         }
      }
      return Default() != 0;
   }

#endif


   LRESULT interaction_impl::OnDragList(WPARAM,LPARAM lParam)
   {

      throw ::exception(todo);

      //LPDRAGLISTINFO lpInfo = (LPDRAGLISTINFO)lParam;
      //ASSERT(lpInfo != nullptr);

      //LRESULT lResult;
      //if (ReflectLastMsg(lpInfo->hWnd, &lResult))
      //   return (int)lResult;    // eat it

      //// not handled - do default
      //return (int)Default();

      return 0;

   }


   void interaction_impl::on_message_create(::message::message * pmessage)
   {

      //

      //auto phost = psession->get_user_interaction_host();

      //auto puserinteractionHost = __user_interaction(phost);


      //m_pframeworkview.get().m_puserinteraction = m_puserinteraction;


      //m_rectangleWindowScreen.left() = 0;
      //m_rectangleWindowScreen.top() = 0;
      //m_rectangleWindowScreen.right() = (int)m_window->Bounds.Width;
      //m_rectangleWindowScreen.bottom() = (int)m_window->Bounds.Height;

      //m_pframeworkview.get().m_directx->m_bCreated = true;

      //::set_core_window_once_visible();

      //m_pframeworkview.get().m_directx->m_pimpl = this;

      //xxx directx
      //m_pframeworkview.get().on_size(m_rectangle.size());


      __UNREFERENCED_PARAMETER(pmessage);

      Default();



   }


   bool interaction_impl::is_composite()
   {

      return false;

   }

   //void interaction_impl::OnHScroll(unsigned int,unsigned int,CScrollBar* pScrollBar)
   //{
   //   __UNREFERENCED_PARAMETER(pScrollBar);
   //   Default();
   //}

   //void interaction_impl::OnVScroll(unsigned int,unsigned int,CScrollBar* pScrollBar)
   //{
   //   __UNREFERENCED_PARAMETER(pScrollBar);
   //   Default();
   //}

   //BOOL CALLBACK interaction_impl::GetAppsEnumWindowsProc(oswindow hwnd,LPARAM lParam)
   //{
   //   user::oswindow_array * phwnda = (user::oswindow_array *) lParam;
   //   phwnda->add(hwnd);
   //   return true;
   //}

   //void interaction_impl::get_app_wnda(user::oswindow_array & wnda)
   //{

   //   throw ::exception(todo(::get_application()));

   //   //      EnumWindows(GetAppsEnumWindowsProc, (LPARAM) &wnda);
   //}

  /*   void interaction_impl::_001OnDeferPaintLayeredWindowBackground(::image::image * pimage)
   {
   _001DeferPaintLayeredWindowBackground(pgraphics);
   }*/


   //class print_window:
   //   virtual ::object
   //{
   //public:



   //   manual_reset_happening m_happening;
   //   oswindow m_hwnd;
   //   HDC m_hdc;

   //   print_window(oswindow hwnd,HDC hdc,::time tickTimeout)
   //   {
   //      m_happening.reset_happening();
   //      m_hwnd = hwnd;
   //      m_hdc = hdc;
   //      begin_thread(&print_window::s_print_window,(LPVOID) this,::e_priority_above_normal);
   //      if(m_happening.wait(::time(tickTimeout)).timeout())
   //      {
   //         informationf("print_window::time_out");
   //      }
   //   }


   //    ::e_status     c_cdecl print_window(LPVOID pvoid)
   //   {
   //      throw ::exception(todo(::get_application()));

   //      //print_window * pprintwindow = (print_window *) pvoid;
   //      //try
   //      //{
   //      //   HANDLE hevent = (HANDLE) pprintwindow->m_happening.get_os_data();
   //      //   ::PrintWindow(pprintwindow->m_hwnd, pprintwindow->m_hdc, 0);
   //      //   ::SetEvent(hevent);
   //      //}
   //      //catch(...)
   //      //{
   //      //}
   //      //return 0;
   //   }
   //};

   void interaction_impl::_001DeferPaintLayeredWindowBackground(HDC hdc)
   {

   }

   void interaction_impl::_001OnProdevianSynch(::message::message * pmessage)
   {
      __UNREFERENCED_PARAMETER(pmessage);
      //      ::auraacmesystem()->get_event(m_pthread)->set_happening();
      //    ::auraacmesystem()->get_event(::auraacmesystem()->get_twf())->wait(::time(8400));
   }

   void interaction_impl::_001OnPaint(::message::message * pmessage)
   {

      //lock lock(m_puserinteraction, 2000);
      throw ::exception(todo);

   }


   void interaction_impl::_001OnPrint(::message::message * pmessage)
   {
      throw ::exception(todo);

      //::pointer<::user::message>pusermessage(pmessage);

      //if(pusermessage->m_wparam == nullptr)
      //   return;

      //::draw2d::graphics_pointer graphics(this);
      //METROWIN_DC(graphics.m_p)->Attach((HDC) pusermessage->m_wparam);
      //::int_rectangle rectx;
      //::draw2d::bitmap * pbitmap = &pgraphics->GetCurrentBitmap();
      //::GetCurrentObject((HDC) pusermessage->m_wparam, OBJ_BITMAP);
      ////      unsigned int dw = ::get_last_error();
      //::int_size size = pbitmap->get_size();
      //rectx.left() = 0;
      //rectx.top() = 0;
      //rectx.right() = size.cx;
      //rectx.bottom() = size.cy;
      //try
      //{
      //   ::int_rectangle rectangleWindow;
      //   window_rectangle(rectangleWindow);

      //   ::image::image_pointer pimage(this);
      //   if(!pimage = create_image(rectangleWindow.bottom_right()))
      //      return;

      //   ::draw2d::graphics_pointer & pgraphics = pimage->get_graphics();

      //   if(pgraphics->get_os_data() == nullptr)
      //      return;

      //   ::int_rectangle rectanglePaint;
      //   ::int_rectangle rectangleUpdate;
      //   rectangleUpdate = rectangleWindow;
      //   rectanglePaint = rectangleWindow;
      //   rectanglePaint.offset(-rectanglePaint.top_left());
      //   (dynamic_cast<::universal_windows::graphics * >(pgraphics))->SelectClipRgn(nullptr);
      //   if(m_puserinteraction != nullptr)
      //   {
      //      m_puserinteraction->_001OnDeferPaintLayeredWindowBackground(pgraphics);
      //   }
      //   else
      //   {
      //      _001OnDeferPaintLayeredWindowBackground(pgraphics);
      //   }
      //   (dynamic_cast<::universal_windows::graphics * >(pgraphics))->SelectClipRgn(nullptr);
      //   (dynamic_cast<::universal_windows::graphics * >(pgraphics))->SetViewportOrg(::int_point());
      //   _000OnDraw(pgraphics);
      //   (dynamic_cast<::universal_windows::graphics * >(pgraphics))->SetViewportOrg(::int_point());
      //   //(dynamic_cast<::universal_windows::graphics * >(pgraphics))->FillSolidRect(rectangleUpdate.left(), rectangleUpdate.top(), 100, 100, 255);
      //   (dynamic_cast<::universal_windows::graphics * >(pgraphics))->SelectClipRgn(nullptr);
      //   (dynamic_cast<::universal_windows::graphics * >(pgraphics))->SetViewportOrg(::int_point());

      //   pgraphics->SelectClipRgn( nullptr);
      //   pgraphics->BitBlt(rectanglePaint.left(), rectanglePaint.top(),
      //      rectanglePaint.width(), rectanglePaint.height(),
      //      pgraphics, rectangleUpdate.left(), rectangleUpdate.top(),
      //      SRCCOPY);

      //   pgraphics->text_out(0, 0, "Te Amo Carlinhos!!", 11);
      //}
      //catch(...)
      //{
      //}
      //pgraphics->FillSolidRect(rectx, rgb(255, 255, 255));
      //METROWIN_DC(graphics.m_p)->Detach();
      //pmessage->m_bRet = true;
      //pusermessage->set_lresult(0);
   }


   void interaction_impl::OnEnterIdle(unsigned int /*nWhy*/,::windowing::window * /*pWho*/)
   {

      throw ::exception(todo);


      //// In some OLE inplace active scenarios, OLE will post a
      //// message instead of sending it.  This causes so many WM_ENTERIDLE
      //// messages to be sent that tasks running in the background stop
      //// running.  By dispatching the pending WM_ENTERIDLE messages
      //// when the first one is received, we trick Windows into thinking
      //// that only one was really sent and dispatched.
      //{
      //   MSG msg;
      //   while (PeekMessage(&msg, nullptr, WM_ENTERIDLE, WM_ENTERIDLE, PM_REMOVE))
      //      DispatchMessage(&msg);
      //}

      //Default();
   }

   //HBRUSH interaction_impl::OnCtlColor(::draw2d::graphics *,::windowing::window * pWnd,unsigned int)
   //{
   //   //ASSERT(pWnd != nullptr && pWnd->get_handle() != nullptr);
   //   //LRESULT lResult;
   //   //if(pWnd->SendChildNotifyLastMsg(&lResult))
   //   //   return (HBRUSH)lResult;     // eat it
   //   //return (HBRUSH)Default();

   //   return nullptr;

   //}

   //// implementation of OnCtlColor for default gray backgrounds
   ////   (works for any interaction_impl containing controls)
   ////  return value of false means caller must call DefWindowProc's default
   ////  true means that 'hbrGray' will be used and the appropriate text
   ////    ('clrText') and background colors are set.
   //bool interaction_impl::GrayCtlColor(HDC hDC,oswindow hWnd,unsigned int nCtlColor,HBRUSH hbrGray,color32_t clrText)
   //{

   //   //if (hDC == nullptr)
   //   //{
   //   //   // sometimes Win32 passes a nullptr hDC in the WM_CTLCOLOR message.
   //   //   //         information(::aura::trace::category_AppMsg, 0, "Warning: hDC is nullptr in interaction_impl::GrayCtlColor; WM_CTLCOLOR not processed.\n");
   //   //   return false;
   //   //}

   //   //if (hbrGray == nullptr ||
   //   //   nCtlColor == CTLCOLOR_EDIT || nCtlColor == CTLCOLOR_MSGBOX ||
   //   //   nCtlColor == CTLCOLOR_SCROLLBAR)
   //   //{
   //   //   return false;
   //   //}

   //   //if (nCtlColor == CTLCOLOR_LISTBOX)
   //   //{
   //   //   // only handle requests to draw the space between edit and drop button
   //   //   //  in a drop-down combo (not a drop-down list)
   //   //   if (!__is_combo_box_control(hWnd, (unsigned int)CBS_DROPDOWN))
   //   //      return false;
   //   //}

   //   //// set background color and return handle to brush
   //   //LOGBRUSH logbrush;
   //   //VERIFY(::GetObject(hbrGray, sizeof(LOGBRUSH), (LPVOID)&logbrush));
   //   //::SetBkColor(hDC, logbrush.lbColor);
   //   //if (clrText == (color32_t)-1)
   //   //   clrText = ::GetSysColor(COLOR_WINDOWTEXT);  // normal text
   //   //::SetTextColor(hDC, clrText);
   //   //return true;


   //   throw ::exception(todo);

   //   return false;


   //}


   //void interaction_impl::CenterWindow(::user::interaction * pAlternateOwner)
   //{

   //   throw ::exception(todo);

   //   ////ASSERT(::is_window(get_handle()));

   //   ////// determine owner interaction_impl to center against
   //   ////unsigned int uStyle = GetStyle();
   //   ////::user::interaction * hWndCenter = pAlternateOwner;
   //   ////if (pAlternateOwner == nullptr)
   //   ////{
   //   ////   if (uStyle & WS_CHILD)
   //   ////      hWndCenter = get_parent();
   //   ////   else
   //   ////      hWndCenter = GetWindow(GW_OWNER);
   //   ////   if (hWndCenter != nullptr)
   //   ////   {
   //   ////      // let parent determine alternate center interaction_impl
   //   ////      ::user::interaction * hWndTemp =
   //   ////         (::user::interaction * )hWndCenter->send_message(WM_QUERYCENTERWND, 0, 0);
   //   ////      if (hWndTemp != nullptr)
   //   ////         hWndCenter = hWndTemp;
   //   ////   }
   //   ////}

   //   ////// get coordinates of the interaction_impl relative to its parent
   //   ////int_rectangle rcDlg;
   //   ////window_rectangle(&rcDlg);
   //   ////int_rectangle rcArea;
   //   ////int_rectangle rcCenter;
   //   ////::user::interaction * hWndParent;
   //   ////if (!(uStyle & WS_CHILD))
   //   ////{
   //   ////   // don't center against invisible or minimized windows
   //   ////   if (hWndCenter != nullptr)
   //   ////   {
   //   ////      unsigned int dwAlternateStyle = hWndCenter->GetWindowLong(GWL_STYLE);
   //   ////      if (!(dwAlternateStyle & WS_VISIBLE) || (dwAlternateStyle & WS_MINIMIZE))
   //   ////         hWndCenter = nullptr;
   //   ////   }

   //   ////   MONITORINFO mi;
   //   ////   mi.cbSize = sizeof(mi);

   //   ////   // center within appropriate monitor coordinates
   //   ////   if (hWndCenter == nullptr)
   //   ////   {
   //   ////      oswindow hwDefault = ::auraacmesystem()->GetMainWnd()->_get_handle();

   //   ////      GetMonitorInfo(
   //   ////         MonitorFromWindow(hwDefault, MONITOR_DEFAULTTOPRIMARY), &mi);
   //   ////      rcCenter = mi.rcWork;
   //   ////      rcArea = mi.rcWork;
   //   ////   }
   //   ////   else
   //   ////   {
   //   ////      hWndCenter->window_rectangle(&rcCenter);
   //   ////      GetMonitorInfo(
   //   ////         MonitorFromWindow(hWndCenter->_get_handle(), MONITOR_DEFAULTTONEAREST), &mi);
   //   ////      rcArea = mi.rcWork;
   //   ////   }
   //   ////}
   //   ////else
   //   ////{
   //   ////   // center within parent client coordinates
   //   ////   hWndParent = get_parent();
   //   ////   ASSERT(hWndParent->is_window());

   //   ////   hWndParent->rectangle(&rcArea);
   //   ////   ASSERT(hWndCenter->is_window());
   //   ////   hWndCenter->rectangle(&rcCenter);
   //   ////   ::MapWindowPoints(hWndCenter->_get_handle(), hWndParent->_get_handle(), (::int_point*)&rcCenter, 2);
   //   ////}

   //   ////// find dialog's upper left based on rcCenter
   //   ////int xLeft = (rcCenter.left() + rcCenter.right()) / 2 - rcDlg.width() / 2;
   //   ////int yTop = (rcCenter.top() + rcCenter.bottom()) / 2 - rcDlg.height() / 2;

   //   ////// if the dialog is outside the screen, move it inside
   //   ////if (xLeft < rcArea.left())
   //   ////   xLeft = rcArea.left();
   //   ////else if (xLeft + rcDlg.width() > rcArea.right())
   //   ////   xLeft = rcArea.right() - rcDlg.width();

   //   ////if (yTop < rcArea.top())
   //   ////   yTop = rcArea.top();
   //   ////else if (yTop + rcDlg.height() > rcArea.bottom())
   //   ////   yTop = rcArea.bottom() - rcDlg.height();

   //   ////// ::map screen coordinates to child coordinates
   //   ////set_window_position(nullptr, xLeft, yTop, -1, -1,
   //   ////   SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
   //}

   //bool interaction_impl::CheckAutoCenter()
   //{
   //   return true;
   //}

   ///////////////////////////////////////////////////////////////////////////////
   //// Dialog initialization support

   //bool interaction_impl::ExecuteDlgInit(const ::string & lpszResourceName)
   //{
   //   // find resource handle
   //   LPVOID lpResource = nullptr;
   //   HGLOBAL hResource = nullptr;
   //   if(lpszResourceName != nullptr)
   //   {
   //      //         HINSTANCE hInst = ::ca2::FindResourceHandle(lpszResourceName, RT_DLGINIT);
   //      //       HRSRC hDlgInit = ::FindResource(hInst, lpszResourceName, RT_DLGINIT);
   //      /*     if (hDlgInit != nullptr)
   //      {
   //      // load it
   //      hResource = LoadResource(hInst, hDlgInit);
   //      if (hResource == nullptr)
   //      return false;
   //      // lock it
   //      lpResource = LockResource(hResource);
   //      ASSERT(lpResource != nullptr);
   //      }*/
   //   }


   //   throw ::exception(todo);


   //}

   //bool interaction_impl::ExecuteDlgInit(LPVOID lpResource)
   //{


   //   throw ::exception(todo);

   //   return false;

   //}


   bool interaction_impl::is_frame_window()
   {
      return false;
   }
   /////////////////////////////////////////////////////////////////////////////
   // Extra interaction_impl support for dynamic subclassing of controls


   //bool interaction_impl::SubclassWindow(::oswindow oswindow)
   //{

   //   throw ::exception(todo);

   //   return false;

   //}
   //

   //bool interaction_impl::SubclassDlgItem(unsigned int nID,::windowing::window * pParent)
   //{

   //   throw ::exception(todo);
   //   return false;

   //   //ASSERT(pParent != nullptr);
   //   //ASSERT(::is_window(WIN_WINDOW(pParent)->get_handle()));

   //   //// check for normal dialog control first
   //   //oswindow hWndControl = ::GetDlgItem(WIN_WINDOW(pParent)->get_handle(), nID);
   //   //if (hWndControl != nullptr)
   //   //   return SubclassWindow(hWndControl);


   //   //return false;   // control not found
   //}

   //oswindow interaction_impl::UnsubclassWindow()
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));

   //   //// set WNDPROC back to original value
   //   //WNDPROC* lplpfn = GetSuperWndProcAddr();
   //   //SetWindowLongPtr(get_handle(), GWLP_WNDPROC, (iptr)*lplpfn);
   //   //*lplpfn = nullptr;

   //   //// and Detach the oswindow from the interaction_impl object
   //   //return Detach();
   //   return nullptr;
   //}


   bool interaction_impl::IsChild(::user::interaction *  pWnd)
   {

      throw ::exception(todo);

      return false;

      //ASSERT(::is_window(get_handle()));
      //if(WIN_WINDOW(pWnd)->_get_handle() == nullptr)
      //{
      //   return ::user::interaction::IsChild(pWnd);
      //}
      //else
      //{
      //   return ::IsChild(get_handle(), WIN_WINDOW(pWnd)->_get_handle()) != false;
      //}
   }


   //oswindow interaction_impl::_get_handle()
   //{

   //   return get_handle();

   //}


   //bool interaction_impl::set_window_position(iptr z,int x,int y,int cx,int cy,unsigned int nFlags)
   //{
   //   /*bool b;
   //   bool * pb = &b;
   //   if(get_application()->m_pcoreapp->s_ptwf != nullptr)
   //   pb = &get_application()->m_pcoreapp->s_ptwf->m_bProDevianMode;
   //   keeper < bool > keepOnDemandDraw(pb, false, *pb, true);
   //   */
   //   //ASSERT(::is_window(get_handle()));
   //   ///*   return ::set_window_position(get_handle(), pWndInsertAfter->get_handle(),
   //   //x, y, cx, cy, nFlags) != false; */
   //   //huge_integer_rectangle rectangleWindowOld = m_rectangleParentClient;
   //   if(nFlags & SWP_NOMOVE)
   //   {
   //      if(nFlags & SWP_NOSIZE)
   //      {
   //      }
   //      else
   //      {
   //         m_rectangleParentClient.right()   = m_rectangleParentClient.left() + cx;
   //         m_rectangleParentClient.bottom()  = m_rectangleParentClient.top() + cy;
   //      }
   //   }
   //   else
   //   {
   //      if(nFlags & SWP_NOSIZE)
   //      {
   //         m_rectangleParentClient.offset(x - m_rectangleParentClient.left(),y - m_rectangleParentClient.top());
   //      }
   //      else
   //      {
   //         m_rectangleParentClient.left()    = x;
   //         m_rectangleParentClient.top()     = y;
   //         m_rectangleParentClient.right()   = m_rectangleParentClient.left() + cx;
   //         m_rectangleParentClient.bottom()  = m_rectangleParentClient.top() + cy;
   //      }
   //   }
   //   return true;

   //}

   //void interaction_impl::MoveWindow(int x,int y,int nWidth,int nHeight,bool bRepaint)
   //{

   //   ASSERT(::is_window(get_handle()));

   //   set_window_position(nullptr,x,y,nWidth,nHeight,bRepaint ? SWP_SHOWWINDOW : 0);

   //}


   //bool interaction_impl::client_to_screen(::int_rectangle * lprect)
   //{

   //   ::huge_integer_rectangle rectangleWindow;

   //   if(!m_puserinteraction->window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lprect->left()   += (int)rectangleWindow.left();
   //   lprect->right()  += (int)rectangleWindow.left();
   //   lprect->top()    += (int)rectangleWindow.top();
   //   lprect->bottom() += (int)rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::client_to_screen(::int_point * lppoint)
   //{

   //   ::huge_integer_rectangle rectangleWindow;

   //   if(!m_puserinteraction->window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lppoint->x     += (int)rectangleWindow.left();
   //   lppoint->y     += (int)rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::client_to_screen(::huge_integer_rectangle * lprect)
   //{

   //   ::int_rectangle rectangleWindow;

   //   if(!m_puserinteraction->window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lprect->left()   += rectangleWindow.left();
   //   lprect->right()  += rectangleWindow.left();
   //   lprect->top()    += rectangleWindow.top();
   //   lprect->bottom() += rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::client_to_screen(::huge_integer_point * lppoint)
   //{

   //   ::huge_integer_rectangle rectangleWindow;

   //   if(!m_puserinteraction->window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lppoint->x     += rectangleWindow.left();
   //   lppoint->y     += rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::screen_to_client(::int_rectangle * lprect)
   //{

   //   ::huge_integer_rectangle rectangleWindow;

   //   if(!m_puserinteraction->window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lprect->left()   -= (int)rectangleWindow.left();
   //   lprect->right()  -= (int)rectangleWindow.left();
   //   lprect->top()    -= (int)rectangleWindow.top();
   //   lprect->bottom() -= (int)rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::screen_to_client(::int_point * lppoint)
   //{

   //   ::huge_integer_rectangle rectangleWindow;

   //   if(!m_puserinteraction->window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lppoint->x     -= (int)rectangleWindow.left();
   //   lppoint->y     -= (int)rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::screen_to_client(::huge_integer_rectangle * lprect)
   //{

   //   ::huge_integer_rectangle rectangleWindow;

   //   if(!m_puserinteraction->window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lprect->left()   -= rectangleWindow.left();
   //   lprect->right()  -= rectangleWindow.left();
   //   lprect->top()    -= rectangleWindow.top();
   //   lprect->bottom() -= rectangleWindow.top();

   //   return true;

   //}


   //bool interaction_impl::screen_to_client(::huge_integer_point * lppoint)
   //{

   //   ::huge_integer_rectangle rectangleWindow;

   //   if(!m_puserinteraction->window_rectangle(rectangleWindow))
   //   {

   //      return false;

   //   }

   //   lppoint->x     -= rectangleWindow.left();
   //   lppoint->y     -= rectangleWindow.top();

   //   return true;

   //}



   //bool interaction_impl::window_rectangle(::huge_integer_rectangle * lprect)
   //{

   //   if(m_pwindow == nullptr)
   //   {

   //      return false;

   //   }

   //   if(m_pwindow->m_pwindow == nullptr)
   //   {

   //      return false;

   //   }

   //   if(!::is_window(get_handle()))
   //   {

   //      return false;

   //   }

   //   ::winrt::Windows::Foundation::Rect rectangle = m_pwindow->m_pwindow->window_rectangle();


   //   lprect->left()   = (huge_integer)rectangle.X;

   //   lprect->top()    = (huge_integer)rectangle.Y;

   //   lprect->right()  = (huge_integer)(lprect->left() + rectangle.Width);

   //   lprect->bottom() = (huge_integer)(lprect->top() + rectangle.Height);

   //   /*if(!::is_window(get_handle()))
   //      throw ::exception(::exception("no more a window"));
   //      // if it is temporary interaction_impl - probably not ca2 wrapped interaction_impl
   //      if(m_puserinteraction == nullptr || m_puserinteraction == this)
   //      {
   //      throw ::exception(todo);
   //      //::int_rectangle rect32;
   //      //::window_rectangle(get_handle(), rect32);
   //      //::copy(lprect, rect32);

   //      //#endif
   //      }
   //      else
   //      {
   //      interaction::window_rectangle(lprect);
   //      }*/

   //   return true;

   //}


   //bool interaction_impl::this->rectangle(::huge_integer_rectangle * lprect)
   //{

   //   if(!::is_window(get_handle()))
   //   {

   //      return false;

   //   }

   //   window_rectangle(lprect);

   //   lprect->right() -= lprect->left();
   //   lprect->left() = 0;
   //   lprect->bottom() -= lprect->top();
   //   lprect->top() = 0;
   //   // if it is temporary interaction_impl - probably not ca2 wrapped interaction_impl
   //   //if(m_puserinteraction == nullptr || m_puserinteraction == this)
   //   {
   //      // throw ::exception(todo);
   //      //::int_rectangle rect32;
   //      //::this->rectangle(get_handle(), rect32);
   //      //::copy(lprect, rect32);
   //   }
   //   //else
   //   {
   //      // interaction::this->rectangle(lprect);
   //   }

   //   return true;

   //}


   atom interaction_impl::SetDlgCtrlId(atom atom)
   {
//      m_atom = atom;
      //    return m_atom;
      m_puserinteraction->m_atom = atom;
      return m_puserinteraction->m_atom;
   }

   atom interaction_impl::GetDlgCtrlId()
   {
      return m_puserinteraction->m_atom;
   }


   void interaction_impl::_001WindowMaximize()
   {

      //::user::interaction::_001WindowMaximize();

   }


   void interaction_impl::_001WindowRestore()
   {

      throw ::exception(todo);

      /*      m_edisplay = e_display_normal;
            if(m_puserinteraction != nullptr)
            m_puserinteraction->m_edisplay = e_display_normal;
            ::XXXShowWindow(get_handle(), SW_RESTORE);*/
   }


   bool interaction_impl::show_window(int nCmdShow)
   {

      return m_puserinteraction->is_window_visible();

   }




   ::user::interaction *  interaction_impl::get_parent() const
   {

      return nullptr;
      throw ::exception(todo);

      //if(!::is_window(get_handle()))
      //   return nullptr;
      //if(get_handle() == nullptr)
      //   return nullptr;
      //return ::universal_windows::interaction_impl::from_handle(::get_parent(get_handle()));
   }

   int interaction_impl::GetWindowLong(int nIndex)
   {

      throw ::exception(todo);

      //return ::GetWindowLong(get_handle(), nIndex);
      return -1;

   }


   int interaction_impl::SetWindowLong(int nIndex,int lValue)
   {

      throw ::exception(todo);

      //return ::SetWindowLong(get_handle(), nIndex, lValue);
      return -1;

   }


   //// interaction_impl
   ///* interaction_impl::operator oswindow() const
   //{ return this == nullptr ? nullptr : get_handle(); }*/
   //bool interaction_impl::operator==(const ::windowing::window& wnd) const
   //{

   //   return wnd.get_handle() == get_handle();

   //}


   //bool interaction_impl::operator!=(const ::windowing::window& wnd) const
   //{

   //   return wnd.get_handle() != get_handle();

   //}


   iptr interaction_impl::get_window_long_ptr(int nIndex) const
   {

      return m_mapLong[nIndex];

   }


   iptr interaction_impl::set_window_long_ptr(int nIndex, iptr lValue)
   {

      return m_mapLong[nIndex] = lValue;

   }


   unsigned int interaction_impl::GetStyle() const
   {

      return (unsigned int) get_window_long_ptr(GWL_STYLE);

   }


   unsigned int interaction_impl::GetExStyle() const
   {

      return (unsigned int) get_window_long_ptr(GWL_EXSTYLE);

   }


   bool interaction_impl::ModifyStyle(unsigned int dwRemove,unsigned int dwAdd,unsigned int nFlags)
   {

      //set_window_long_ptr(GWL_STYLE, (get_window_long_ptr(GWL_STYLE) | dwAdd) & ~(dwRemove));

      if (nFlags != 0)
      {

         set_need_redraw();

      }

      return true;
   }


   bool interaction_impl::ModifyStyleEx(unsigned int dwRemove,unsigned int dwAdd,unsigned int nFlags)
   {

      //set_window_long_ptr(GWL_EXSTYLE, (get_window_long_ptr(GWL_EXSTYLE) | dwAdd) & ~(dwRemove));

      if (nFlags != 0)
      {

         set_need_redraw();

      }

      return true;
   }

   //void interaction_impl::SetOwner(::user::interaction * pOwnerWnd)
   //{
   //   m_pguieOwner = pOwnerWnd;
   //}

   //LRESULT interaction_impl::send_message(const ::atom & atom,wparam wparam,lparam lparam)
   //{

   //   ::pointer<::user::message>spbase;

   //   spbase = m_puserinteraction->get_message_base(m_oswindow, atom,wparam,lparam);

   //   /*      try
   //         {
   //         ::user::interaction * pinteraction = m_puserinteraction;
   //         while(pinteraction != nullptr)
   //         {
   //         try
   //         {
   //         pinteraction->pre_translate_message(spbase);
   //         }
   //         catch(...)
   //         {
   //         break;
   //         }
   //         if(spbase->m_bRet)
   //         return spbase->get_lresult();
   //         try
   //         {
   //         pinteraction = pinteraction->get_parent();
   //         }
   //         catch(...)
   //         {
   //         break;
   //         }
   //         }
   //         }
   //         catch(...)
   //         {
   //         }*/
   //   message_handler(spbase);
   //   return spbase->m_lresult;

   //   //throw ::exception(todo);

   //   ////ASSERT(::is_window(get_handle()));
   //   //return ::SendMessage(get_handle(), message, wParam, lParam);
   //}


//   bool interaction_impl::post_message(const ::atom & atom,WPARAM wParam,lparam lParam)
//   {
//
////      return ::PostMessageW(get_handle(),message,wParam,lParam) != false;
//      //return m_puserinteraction->post_message(message, wParam, lParam);
//      return message_queue_post(get_handle(), atom, wParam, lParam) != false;
//
//   }


   //bool interaction_impl::DragDetect(::int_point int_point) const
   //{


   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));

   //   //return ::DragDetect(get_handle(), int_point) != false;

   //}


   void interaction_impl::set_window_text(const ::string & lpszString)
   {

      {

         synchronous_lock synchronouslock(m_puserinteraction->synchronization());

         m_strWindowText = lpszString;

      }

      //m_window->Dispatcher->RunAsync(
      //CoreDispatcherPriority::Normal,
      //ref ___new ::winrt::Windows::UI::Core::DispatchedHandler([this]()
      //{

      //   ::winrt::Windows::UI::ViewManagement::ApplicationView  applicationview = ::winrt::Windows::UI::ViewManagement::ApplicationView::GetForCurrentView();

      //   {

      //      synchronous_lock synchronouslock(m_puserinteraction->synchronization());

      //      applicationview->Title = m_strWindowText;

      //   }

      //}));

   }

   //character_count interaction_impl::GetWindowText(char * lpszString,character_count nMaxCount)
   //{
   //   strncpy(lpszString,m_strWindowText,nMaxCount);
   //   return minimum(nMaxCount,m_strWindowText.get_length());
   //}

   //character_count interaction_impl::get_window_text_length()
   //{

   //   string str;

   //   get_window_text(str);

   //   return str.length();

   //   //throw ::exception(todo);

   //   ////ASSERT(::is_window(get_handle()));

   //   ////return ::GetWindowTextLength(get_handle());

   //}

   //void interaction_impl::SetFont(::write_text::font* pfont,bool bRedraw)
   //{
   //   __UNREFERENCED_PARAMETER(bRedraw);
   //   ASSERT(::is_window(get_handle()));
   //   m_pfont = ___new ::write_text::font(*pfont);
   //}

   //::write_text::font* interaction_impl::GetFont()
   //{
   //   ASSERT(::is_window(get_handle()));
   //   return m_pfont;
   //}

   void interaction_impl::DragAcceptFiles(bool bAccept)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //::DragAcceptFiles(get_handle(), bAccept);
   }

   //::user::frame_window *  interaction_impl::EnsureParentFrame()
   //{
   //   ::user::frame_window * pFrameWnd=get_parent_frame();
   //   ENSURE_VALID(pFrameWnd);
   //   return pFrameWnd;
   //}

   //::user::interaction *  interaction_impl::EnsureTopLevelParent()
   //{
   //   ::user::interaction *pWnd=get_top_level();
   //   ENSURE_VALID(pWnd);
   //   return pWnd;
   //}

   //void interaction_impl::MoveWindow(const ::int_rectangle & rectangle,bool bRepaint)
   //{
   //   MoveWindow(lpRect->left(),lpRect->top(),lpRect->right() - lpRect->left(),lpRect->bottom() - lpRect->top(),bRepaint);
   //}

   unsigned int interaction_impl::ArrangeIconicWindows()
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle())); return ::ArrangeIconicWindows(get_handle());

      return 0;

   }


   bool interaction_impl::BringWindowToTop()
   {

      throw ::exception(todo);

      //return ::BringWindowToTop(get_handle()) != false;

      return false;

   }


   void interaction_impl::MapWindowPoints(::windowing::window * puserinteractionTo,::int_point * lpPoint,unsigned int nCount)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //::MapWindowPoints(get_handle(), (oswindow) puserinteractionTo->get_os_data(), lpPoint, nCount);
   }

   void interaction_impl::MapWindowPoints(::windowing::window * puserinteractionTo,::int_rectangle * lpRect)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //::MapWindowPoints(get_handle(), (oswindow) puserinteractionTo->get_os_data(), (::int_point *)lpRect, 2);
   }

   ::draw2d::graphics * interaction_impl::GetDC()
   {

      throw ::exception(todo);

      return nullptr;
      //::draw2d::graphics_pointer g(this);
      //if(get_handle() == nullptr)
      //{
      //   (dynamic_cast < ::universal_windows::graphics * >(g.m_p))->Attach(::GetDC(nullptr));
      //}
      //else
      //{
      //   (dynamic_cast < ::universal_windows::graphics * >(g.m_p))->Attach(::GetDC(get_handle()));
      //}
      //return g.detach();
   }

   ::draw2d::graphics * interaction_impl::GetWindowDC()
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //::draw2d::graphics_pointer g(this);
      //g->attach(::GetWindowDC(get_handle()));
      //return g.detach();
      return nullptr;
   }

  bool interaction_impl::ReleaseDC(::image::image * pimage)
   {

      throw ::exception(todo);

      //if(pgraphics == nullptr)
      //   return false;

      //if(((Gdiplus::Graphics *)(dynamic_cast<::universal_windows::graphics * >(pgraphics))->get_os_data()) == nullptr)
      //   return false;

      //::ReleaseDC(get_handle(), (dynamic_cast<::universal_windows::graphics * >(pgraphics))->m_hdc);

      //(dynamic_cast<::universal_windows::graphics * >(pgraphics))->m_hdc = nullptr;

      //pgraphics->release();

      //return true;
      return false;

   }

   void interaction_impl::UpdateWindow()
   {

      throw ::exception(todo);

      //::UpdateWindow(get_handle());
   }

   void interaction_impl::SetRedraw(bool bRedraw)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //::SendMessage(get_handle(), WM_SETREDRAW, bRedraw, 0);
   }

   //bool interaction_impl::GetUpdateRect(::int_rectangle * lpRect,bool bErase)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //return ::GetUpdateRect(get_handle(), lpRect, bErase) != false;
   //}

   //int interaction_impl::GetUpdateRgn(::draw2d::region* pRgn,bool bErase)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //return ::GetUpdateRgn(get_handle(), (HRGN)pRgn->get_os_data(), bErase);
   //}

   //void interaction_impl::Invalidate(bool bErase)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //::InvalidateRect(get_handle(), nullptr, bErase);
   //}

   //void interaction_impl::InvalidateRect(const ::int_rectangle & rectangle,bool bErase)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //::InvalidateRect(get_handle(), lpRect, bErase);
   //}

   //void interaction_impl::InvalidateRgn(::draw2d::region* pRgn,bool bErase)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //::InvalidateRgn(get_handle(), (HRGN)pRgn->get_os_data(), bErase);
   //}

   //void interaction_impl::ValidateRect(const ::int_rectangle & rectangle)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //
   //   //::ValidateRect(get_handle(), lpRect);

   //}

   //void interaction_impl::ValidateRgn(::draw2d::region* pRgn)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //
   //   //::ValidateRgn(get_handle(), (HRGN)pRgn->get_os_data());

   //}

   bool interaction_impl::is_window_visible()
   {

      return true;

      //if(!::is_window(get_handle()))
        // return false;

      if(m_puserinteraction != nullptr)
      {

         if(!m_puserinteraction->is_this_visible())
            return false;

         if(m_puserinteraction->get_parent() != nullptr && !m_puserinteraction->get_parent()->is_window_visible())
            return false;

      }


      throw ::exception(todo);


      //if(!::IsWindowVisible(get_handle()))
      //   return false;

      return true;

   }


   void interaction_impl::ShowOwnedPopups(bool bShow)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //::ShowOwnedPopups(get_handle(), bShow);

   }

   //void interaction_impl::send_message_to_descendants(const ::atom & atom,WPARAM wParam,lparam lParam,bool bDeep,bool bOnlyPerm)
   //{
   //   ASSERT(::is_window(get_handle()));
   //   //interaction_impl::send_message_to_descendants(get_handle(), message, wParam, lParam, bDeep, bOnlyPerm);

   //   // walk through HWNDs to avoid creating temporary interaction_impl objects
   //   // unless we need to call this function recursively
   //   user::interaction * pinteraction = m_puserinteraction->top_child();
   //   while(pinteraction != nullptr)
   //   {
   //      try
   //      {
   //         pinteraction->send_message(message,wParam,lParam);
   //      }
   //      catch(...)
   //      {
   //      }
   //      if(bDeep)
   //      {
   //         // send to child windows after parent
   //         try
   //         {
   //            pinteraction->send_message_to_descendants(message,wParam,lParam,bDeep,bOnlyPerm);
   //         }
   //         catch(...)
   //         {
   //         }
   //      }
   //      try
   //      {
   //         pinteraction = pinteraction->under_sibling();
   //      }
   //      catch(...)
   //      {
   //         break;
   //      }
   //   }
   //}



   ::draw2d::graphics * interaction_impl::GetDCEx(::draw2d::region* prgnClip,unsigned int flags)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //::draw2d::graphics_pointer g(this);
      //g->attach(::GetDCEx(get_handle(), (HRGN)prgnClip->get_os_data(), flags));
      //return g.detach();

      return nullptr;

   }


   //void interaction_impl::LockWindowUpdate()
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));

   //   //return ::LockWindowUpdate(get_handle()) != false;

   //   //return false;

   //}


   //void interaction_impl::UnlockWindowUpdate()
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //
   //   //::LockWindowUpdate(nullptr);

   //}


   //void interaction_impl::RedrawWindow(const ::int_rectangle& rectangleUpdate, ::draw2d::region* prgnUpdate, unsigned int flags)
   //{

   //   m_puserinteraction->m_bNeedRedraw = true;

   //   //throw ::exception(todo);

   //   //if(::auraacmesystem()->get_twf() == nullptr)
   //   //   return false;

   //   //if(::auraacmesystem()->get_twf()->m_bProDevianMode)
   //   //   return true;

   //   //ASSERT(::is_window(get_handle()));

   //   //return ::set_need_redraw(get_handle(), lpRectUpdate, prgnUpdate == nullptr ? nullptr : (HRGN)prgnUpdate->get_os_data(), flags) != false;

   //   return true;

   //}

#ifdef WINDOWS_DESKTOP

   bool interaction_impl::EnableScrollBar(int nSBFlags, unsigned int nArrowFlags)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::EnableScrollBar(get_handle(), nSBFlags, nArrowFlags) != false;

   }

#endif

   bool interaction_impl::DrawAnimatedRects(int idAni,const ::int_rectangle *lprcFrom,const ::int_rectangle *lprcTo)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::DrawAnimatedRects(get_handle(), idAni, lprcFrom, lprcTo) != false;

      return false;

   }


   bool interaction_impl::DrawCaption(::draw2d::graphics_pointer & pgraphics,const ::int_rectangle * lprc,unsigned int uFlags)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::DrawCaption(get_handle(), (HDC)(dynamic_cast<::universal_windows::graphics * >(pgraphics))->get_os_data(), lprc, uFlags) != false;

      return false;

   }


   void interaction_impl::SetTimer(uptr uEvent, const class time & timeElapse, PFN_TIMER pfnTimer, bool bPeriodic, void* pdata)
   {


      return ::windowing::window::SetTimer(uEvent, timeElapse,pfnTimer, bPeriodic, pdata);


   }


   void interaction_impl::KillTimer(uptr uEvent)
   {

      return ::windowing::window::KillTimer(uEvent);

   }


   bool interaction_impl::IsWindowEnabled()
   {

      return true;

      return interaction_impl::IsWindowEnabled();

   }


   bool interaction_impl::EnableWindow(bool bEnable)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::EnableWindow(get_handle(), bEnable) != false;

      return false;

   }


   //::user::interaction *  interaction_impl::GetActiveWindow()
   //{

   //   oswindow window = ::get_active_window();

   //   return window == nullptr ? nullptr : oswindow_interaction(window);

   //}


   //::user::interaction *  interaction_impl::set_active_window()
   //{

   //   oswindow window = ::set_active_window(get_handle());

   //   return window == nullptr ? nullptr : oswindow_interaction(window);

   //}


   //::user::interaction *  interaction_impl::GetFocus()
   //{

   //   return oswindow_interaction(::get_focus());

   //}


   //bool interaction_impl::XXXSetFocus()
   //{

   //   ::set_focus(m_puserinteraction->get_handle());

   //   return true;

   //}


   //::user::interaction *  interaction_impl::get_desktop_window()
   //{

   //   return nullptr;

   //}


   // Helper for radio buttons
   int interaction_impl::GetCheckedRadioButton(int nIDFirstButton,int nIDLastButton)
   {
      for(int nID = nIDFirstButton; nID <= nIDLastButton; nID++)
      {
         if(IsDlgButtonChecked(nID))
            return nID; // atom that matched
      }
      return 0; // invalid ID
   }

   void interaction_impl::CheckDlgButton(int nIDButton,unsigned int nCheck)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));

      //::CheckDlgButton(get_handle(), nIDButton, nCheck);

   }

   void interaction_impl::CheckRadioButton(int nIDFirstButton,int nIDLastButton,int nIDCheckButton)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));

      //::CheckRadioButton(get_handle(), nIDFirstButton, nIDLastButton, nIDCheckButton);

   }

#ifdef WINDOWS_DESKTOP

   int interaction_impl::DlgDirList(__inout_z char * lpPathSpec, __in int nIDListBox, __in int nIDStaticPath, __in unsigned int nFileType)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));

      //return ::DlgDirList(get_handle(), lpPathSpec, nIDListBox, nIDStaticPath, nFileType);

   }

   int interaction_impl::DlgDirListComboBox(__inout_z char * lpPathSpec, __in int nIDComboBox,  __in int nIDStaticPath, __in unsigned int nFileType)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));

      //return ::DlgDirListComboBox(get_handle(), lpPathSpec, nIDComboBox, nIDStaticPath, nFileType);

   }

   bool interaction_impl::DlgDirSelect(char * lpString, int nSize, int nIDListBox)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));

      //return ::DlgDirSelectEx(get_handle(), lpString, nSize, nIDListBox) != false;

   }

   bool interaction_impl::DlgDirSelectComboBox(char * lpString, int nSize, int nIDComboBox)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));

      //return ::DlgDirSelectComboBoxEx(get_handle(), lpString, nSize, nIDComboBox) != false;

   }

#endif

   //void interaction_impl::GetDlgItem(atom atom,oswindow* phWnd) const
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //ASSERT(phWnd != nullptr);
   //   //*phWnd = ::GetDlgItem(get_handle(), (int) atom);

   //}

   //unsigned int interaction_impl::GetDlgItemInt(int nID,BOOL * lpTrans,bool bSigned) const
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));

   //   //return ::GetDlgItemInt(get_handle(), nID, lpTrans, bSigned);

   //   return 0;

   //}

#ifdef WINDOWS_DESKTOP

   int interaction_impl::GetDlgItemText(__in int nID, __out_ecount_part_z(nMaxCount, return + 1) char * lpStr, __in int nMaxCount) const
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::GetDlgItemText(get_handle(), nID, lpStr, nMaxCount);

   }

#endif

   ::windowing::window * interaction_impl::GetNextDlgGroupItem(::windowing::window * pWndCtl,bool bPrevious) const
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //return ::universal_windows::interaction_impl::from_handle(::GetNextDlgGroupItem(get_handle(), (oswindow) pWndCtl->get_os_data(), bPrevious));

      return nullptr;

   }

   ::windowing::window * interaction_impl::GetNextDlgTabItem(::windowing::window * pWndCtl,bool bPrevious) const
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //return ::universal_windows::interaction_impl::from_handle(::GetNextDlgTabItem(get_handle(), (oswindow) pWndCtl->get_os_data(), bPrevious));

      return nullptr;

   }


   unsigned int interaction_impl::IsDlgButtonChecked(int nIDButton) const
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::IsDlgButtonChecked(get_handle(), nIDButton);

      return 0;

   }
   
   
   LPARAM interaction_impl::SendDlgItemMessage(int nID,const ::atom & atom,WPARAM wParam,LPARAM lParam)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::SendDlgItemMessage(get_handle(), nID, message, wParam, lParam);

      return 0;

   }


   void interaction_impl::SetDlgItemInt(int nID,unsigned int nValue,bool bSigned)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //::SetDlgItemInt(get_handle(), nID, nValue, bSigned);

   }


   void interaction_impl::SetDlgItemText(int nID, const ::string & lpszString)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //::SetDlgItemText(get_handle(), nID, lpszString);

   }


   //int interaction_impl::ScrollWindowEx(int dx,int dy,const ::int_rectangle & rectangleScroll,const ::int_rectangle & rectangleClip,::draw2d::region* prgnUpdate,::int_rectangle * lpRectUpdate,unsigned int flags)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //
   //   //return ::ScrollWindowEx(get_handle(), dx, dy, lpRectScroll, lpRectClip, (HRGN)prgnUpdate->get_os_data(), lpRectUpdate, flags);

   //}


   void interaction_impl::ShowScrollBar(unsigned int nBar,bool bShow)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //::ShowScrollBar(get_handle(), nBar, bShow);

   }


   ::user::interaction *  interaction_impl::ChildWindowFromPoint(::int_point int_point)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::universal_windows::interaction_impl::from_handle(::ChildWindowFromPoint(get_handle(), int_point));

      return nullptr;

   }


   ::user::interaction *  interaction_impl::ChildWindowFromPoint(::int_point point,unsigned int nFlags)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::universal_windows::interaction_impl::from_handle(::ChildWindowFromPointEx(get_handle(), point, nFlags));

      return nullptr;

   }




   ::user::interaction *  interaction_impl::GetTopWindow()
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::universal_windows::interaction_impl::from_handle(::GetTopWindow(get_handle()));

      return nullptr;

   }


   ::user::interaction *  interaction_impl::GetWindow(unsigned int nCmd)
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::universal_windows::interaction_impl::from_handle(::GetWindow(get_handle(), nCmd));

      return nullptr;

   }


   ::user::interaction *  interaction_impl::GetLastActivePopup()
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::universal_windows::interaction_impl::from_handle(::GetLastActivePopup(get_handle()));

      return nullptr;

   }


   //::user::interaction *  interaction_impl::set_parent(::user::interaction *  pWndNewParent)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));
   //   //return ::universal_windows::interaction_impl::from_handle(::SetParent(get_handle(), (oswindow) pWndNewParent->get_os_data()));
   //}

   
   //::pointer<::windowing::window>interaction_impl::WindowFromPoint(::int_point int_point)
   //{

   //   throw ::exception(todo);

   //   //return ::universal_windows::interaction_impl::from_handle(::WindowFromPoint(point));

   //}


   //bool interaction_impl::FlashWindow(bool bInvert)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));

   //   //return ::FlashWindow(get_handle(), bInvert) != false;

   //}

   //bool interaction_impl::ChangeClipboardChain(oswindow hWndNext)
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));

   //   //return ::ChangeClipboardChain(get_handle(), hWndNext) != false;

   //}

   //oswindow interaction_impl::SetClipboardViewer()
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));

   //   //return ::SetClipboardViewer(get_handle());

   //}

   //bool interaction_impl::OpenClipboard()
   //{

   //   throw ::exception(todo);

   //   //ASSERT(::is_window(get_handle()));

   //   //return ::OpenClipboard(get_handle()) != false;

   //}


   //::windowing::window * interaction_impl::GetOpenClipboardWindow()
   //{

   //   throw ::exception(todo);

   //   //return ::universal_windows::interaction_impl::from_handle(::GetOpenClipboardWindow());

   //}


   //::windowing::window * interaction_impl::GetClipboardOwner()
   //{

   //   throw ::exception(todo);

   //   //return ::universal_windows::interaction_impl::from_handle(::GetClipboardOwner());

   //}


   //::windowing::window * interaction_impl::GetClipboardViewer()
   //{

   //   throw ::exception(todo);

   //}


   //int_point interaction_impl::GetCaretPos()
   //{

   //   throw ::exception(todo);

   //}


   //void interaction_impl::SetCaretPos(::int_point int_point)
   //{

   //   throw ::exception(todo);

   //}


   //void interaction_impl::HideCaret()
   //{

   //   throw ::exception(todo);

   //   //::HideCaret(get_handle());

   //}


   //void interaction_impl::ShowCaret()
   //{

   //   throw ::exception(todo);

   //   //::ShowCaret(get_handle());

   //}


   //bool interaction_impl::set_foreground_window()
   //{

   //   throw ::exception(todo);

   //   //return ::XXXSetForegroundWindow(get_handle()) != false;

   //}


   //::pointer<::windowing::window>interaction_impl::GetForegroundWindow()
   //{

   //   throw ::exception(todo);

   //   //return ::universal_windows::interaction_impl::from_handle(::GetForegroundWindow());

   //}


   //bool interaction_impl::SendNotifyMessage(const ::atom & atom,WPARAM wParam,LPARAM lParam)
   //{

   //   throw ::exception(todo);

   //   //return ::SendNotifyMessage(get_handle(), message, wParam, lParam) != false;

   //}

   ////// Win4
   ////HICON interaction_impl::SetIcon(HICON hIcon,bool bBigIcon)
   ////{

   ////   throw ::exception(todo);

   ////   //return (HICON)send_message(WM_SETICON, bBigIcon, (LPARAM)hIcon);

   ////}


   ////HICON interaction_impl::GetIcon(bool bBigIcon) const
   ////{

   ////   throw ::exception(todo);

   ////   //ASSERT(::is_window(get_handle()));

   ////   //return (HICON)const_cast < interaction_impl * > (this)->send_message(WM_GETICON, bBigIcon, 0);



   ////}


   void interaction_impl::Print(::draw2d::graphics_pointer & pgraphics,unsigned int dwFlags) const
   {

      //ASSERT(::is_window(get_handle()));

      throw ::not_implemented();
      //      const_cast < interaction_impl * > (this)->send_message(WM_PRINT, (WPARAM)(dynamic_cast<::universal_windows::graphics * >(pgraphics))->get_os_data(), (LPARAM) dwFlags);

   }


   void interaction_impl::PrintClient(::draw2d::graphics_pointer & pgraphics,unsigned int dwFlags) const
   {

      //ASSERT(::is_window(get_handle()));

      throw ::not_implemented();
      //const_cast < interaction_impl * > (this)->send_message(WM_PRINTCLIENT, (WPARAM)(dynamic_cast<::universal_windows::graphics * >(pgraphics))->get_os_data(), (LPARAM) dwFlags);

   }


   //bool interaction_impl::SetWindowContextHelpId(unsigned int dwContextHelpId)
   //{

   //   throw ::exception(todo);

   //   return false;

   //}


   //unsigned int interaction_impl::GetWindowContextHelpId() const
   //{

   //   throw ::exception(todo);

   //   return 0;

   //}


   //void interaction_impl::OnActivateApp(bool,unsigned int)
   //{

   //   Default();

   //}


   //void interaction_impl::OnActivate(unsigned int,::windowing::window *,bool)
   //{
   //   
   //   Default();

   //}


   void interaction_impl::OnCancelMode()
   {

      Default();

   }


   void interaction_impl::OnChildActivate()
   {
      Default();
   }
   void interaction_impl::OnClose()
   {
      Default();
   }
   void interaction_impl::OnContextMenu(::windowing::window *,int_point)
   {
      Default();
   }

#ifdef WINDOWS_DESKTOP

   bool interaction_impl::OnCopyData(::windowing::window *, COPYDATASTRUCT*)
   {

      return Default() != false;

   }

#endif

   void interaction_impl::OnEnable(bool)
   {
      Default();
   }
   void interaction_impl::OnEndSession(bool)
   {
      Default();
   }

   
   //bool interaction_impl::OnEraseBkgnd(::draw2d::graphics *)
   //{

   //   return Default() != false;

   //}


#ifdef WINDOWS_DESKTOP

   void interaction_impl::OnGetMinMaxInfo(MINMAXINFO*)
   {
      Default();
   }

#endif

   //void interaction_impl::OnIconEraseBkgnd(::draw2d::graphics *)
   //{
   //   Default();
   //}
   void interaction_impl::OnKillFocus(::windowing::window *)
   {
      Default();
   }
   //LRESULT interaction_impl::OnMenuChar(unsigned int,unsigned int,::user::menu*)
   //{
   //   return Default();
   //}
   void interaction_impl::OnMenuSelect(unsigned int,unsigned int,HMENU)
   {
      Default();
   }
   void interaction_impl::OnMove(int,int)
   {
      Default();
   }
   HCURSOR interaction_impl::OnQueryDragIcon()
   {
      return (HCURSOR)Default();
   }

   bool interaction_impl::OnQueryEndSession()
   {

      return Default() != false;

   }

   bool interaction_impl::OnQueryNewPalette()
   {

      return Default() != false;

   }

   bool interaction_impl::OnQueryOpen()
   {

      return Default() != false;

   }

   // void interaction_impl::on_message_set_cursor(::message::message * pmessage)
   // {

   //    throw ::exception(todo);

   //    //::pointer<::user::message>pusermessage(pmessage);
   //    //if(::auraacmesystem()->get_cursor() != nullptr
   //    //   && ::auraacmesystem()->get_cursor()->m_ecursor != cursor_system)
   //    //{
   //    //   ::SetCursor(nullptr);
   //    //}
   //    //pusermessage->set_lresult(1);
   //    //pusermessage->m_bRet = true;
   //    ////(bool)Default();

   // }

   void interaction_impl::OnShowWindow(bool,unsigned int)
   {
      Default();
   }
   void interaction_impl::OnSize(unsigned int,int,int)
   {
      Default();
   }
   void interaction_impl::OnTCard(unsigned int,unsigned int)
   {
      Default();
   }

#ifdef WINDOWS_DESKTOP

   void interaction_impl::OnWindowPosChanging(WINDOWPOS*)
   {
      Default();
   }

   void interaction_impl::OnWindowPosChanged(WINDOWPOS*)
   {
      Default();
   }

   void interaction_impl::OnDropFiles(HDROP)
   {
      Default();
   }

#endif

   
   void interaction_impl::OnPaletteIsChanging(::windowing::window *)
   {
      
      Default();

   }


   //bool interaction_impl::OnNcActivate(bool)
   //{

   //   return Default() != false;

   //}


#ifdef WINDOWS_DESKTOP

   void interaction_impl::OnNcCalcSize(bool, NCCALCSIZE_PARAMS*)
   {
      Default();
   }

#endif

   //bool interaction_impl::OnNcCreate(LPCREATESTRUCT)
   //{

   //   return Default() != false;

   //}


   //LRESULT interaction_impl::OnNcHitTest(point)
   //{

   //   return Default();

   //}


   //void interaction_impl::OnNcLButtonDblClk(unsigned int,int_point)
   //{

   //   Default();

   //}


   //void interaction_impl::OnNcLButtonDown(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnNcLButtonUp(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnNcMButtonDblClk(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnNcMButtonDown(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnNcMButtonUp(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnNcMouseMove(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnNcPaint()
   //{
   //   Default();
   //}
   //void interaction_impl::OnNcRButtonDblClk(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnNcRButtonDown(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnNcRButtonUp(unsigned int,int_point)
   //{
   //   Default();
   //}
   void interaction_impl::OnSysChar(unsigned int,unsigned int,unsigned int)
   {
      Default();
   }
   void interaction_impl::OnSysCommand(unsigned int,LPARAM)
   {
      Default();
   }
   void interaction_impl::OnSysDeadChar(unsigned int,unsigned int,unsigned int)
   {
      Default();
   }
   void interaction_impl::OnSysKeyDown(unsigned int,unsigned int,unsigned int)
   {
      Default();
   }
   void interaction_impl::OnSysKeyUp(unsigned int,unsigned int,unsigned int)
   {
      Default();
   }
   void interaction_impl::OnCompacting(unsigned int)
   {
      Default();
   }
   void interaction_impl::OnFontChange()
   {
      Default();
   }
   void interaction_impl::OnPaletteChanged(::windowing::window *)
   {
      Default();
   }
   void interaction_impl::OnSpoolerStatus(unsigned int,unsigned int)
   {
      Default();
   }
   void interaction_impl::OnTimeChange()
   {
      Default();
   }
   void interaction_impl::OnChar(unsigned int,unsigned int,unsigned int)
   {
      Default();
   }
   void interaction_impl::OnDeadChar(unsigned int,unsigned int,unsigned int)
   {
      Default();
   }
   void interaction_impl::OnKeyDown(unsigned int,unsigned int,unsigned int)
   {
      Default();
   }
   void interaction_impl::OnKeyUp(unsigned int,unsigned int,unsigned int)
   {
      Default();
   }
   //void interaction_impl::OnLButtonDblClk(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnLButtonDown(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnLButtonUp(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnMButtonDblClk(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnMButtonDown(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnMButtonUp(unsigned int,int_point)
   //{
   //   Default();
   //}
   int interaction_impl::OnMouseActivate(::windowing::window *,unsigned int,const ::atom & atom)
   {
      return (int)Default();
   }
   //void interaction_impl::OnMouseMove(unsigned int,int_point)
   //{
   //   Default();
   //}

   //bool interaction_impl::OnMouseWheel(unsigned int,short,int_point)
   //{

   //   return Default() != false;

   //}

   LRESULT interaction_impl::OnRegisteredMouseWheel(WPARAM,LPARAM)
   {
      return Default();
   }
   //void interaction_impl::OnRButtonDblClk(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnRButtonDown(unsigned int,int_point)
   //{
   //   Default();
   //}
   //void interaction_impl::OnRButtonUp(unsigned int,int_point)
   //{
   //   Default();
   //}
   void interaction_impl::OnTimer(uptr)
   {
      Default();
   }
   //void interaction_impl::OnInitMenu(::user::menu*)
   //{
   //   Default();
   //}
   //void interaction_impl::OnInitMenuPopup(::user::menu*,unsigned int,bool)
   //{
   //   Default();
   //}

#ifdef WINDOWS_DESKTOP

   void interaction_impl::OnAskCbFormatName(__in unsigned int nMaxCount, __out_ecount_z(nMaxCount) char * pszName)
   {
      (nMaxCount);
      if(nMaxCount>0)
      {
         /* defwindow proc should do this for us, but to be safe, we'hi do it here too */
         pszName[0]='\0';
      }
      Default();
   }

#endif

   
   void interaction_impl::OnDestroyClipboard()
   {
      
      Default();

   }


   void interaction_impl::OnDrawClipboard()
   {

      Default();

   }


   void interaction_impl::OnHScrollClipboard(::windowing::window *,unsigned int,unsigned int)
   {

      Default();

   }


   void interaction_impl::OnPaintClipboard(::windowing::window *,HGLOBAL)
   {

      Default();

   }


   void interaction_impl::OnRenderAllFormats()
   {

      Default();

   }


   void interaction_impl::OnRenderFormat(unsigned int)
   {

      Default();

   }


   void interaction_impl::OnSizeClipboard(::windowing::window *,HGLOBAL)
   {

      Default();

   }


   void interaction_impl::OnVScrollClipboard(::windowing::window *,unsigned int,unsigned int)
   {

      Default();

   }


   unsigned int interaction_impl::OnGetDlgCode()
   {

      return (unsigned int)Default();

   }


   void interaction_impl::OnMDIActivate(bool,::windowing::window *,::windowing::window *)
   {

      Default();

   }


   void interaction_impl::OnEnterMenuLoop(bool)
   {

      Default();

   }


   void interaction_impl::OnExitMenuLoop(bool)
   {

      Default();

   }


   // Win4 support

#ifdef WINDOWS_DESKTOP

   void interaction_impl::OnStyleChanged(int, LPSTYLESTRUCT)
   {
      Default();
   }
   void interaction_impl::OnStyleChanging(int, LPSTYLESTRUCT)
   {
      Default();
   }

#endif

   void interaction_impl::OnSizing(unsigned int,::int_rectangle *)
   {
      Default();
   }
   void interaction_impl::OnMoving(unsigned int,::int_rectangle *)
   {
      Default();
   }
   void interaction_impl::OnCaptureChanged(::windowing::window *)
   {
      Default();
   }

   bool interaction_impl::OnDeviceChange(unsigned int,::uptr)
   {

      return Default() != false;

   }

   //void interaction_impl::OnWinIniChange(const ::string &)
   //{
   //   Default();
   //}
   void interaction_impl::OnChangeUIState(unsigned int,unsigned int)
   {
      Default();
   }
   void interaction_impl::OnUpdateUIState(unsigned int,unsigned int)
   {
      Default();
   }
   unsigned int interaction_impl::OnQueryUIState()
   {
      return (unsigned int)Default();
   }

   // interaction_impl dialog data support
   //    void interaction_impl::DoDataExchange(CDataExchange*)
   //   { } // default does nothing

   // interaction_impl modality support

   void interaction_impl::BeginModalState()
   {

      throw ::exception(todo);

      //::EnableWindow(get_handle(), false);

   }

   void interaction_impl::EndModalState()
   {

      throw ::exception(todo);

      //::EnableWindow(get_handle(), true);

   }

   // frame_window
   /*    void frame_window::DelayUpdateFrameTitle()
   { m_nIdleFlags |= idleTitle; }
   void frame_window::DelayRecalcLayout(bool bNotify)
   { m_nIdleFlags |= (idleLayout | (bNotify ? idleNotify : 0)); };
   bool frame_window::InModalState() const
   { return m_cModalStack != 0; }
   void frame_window::set_title(const ::string & lpszTitle)
   { m_strTitle = lpszTitle; }
   string frame_window::get_title() const
   { return m_strTitle; }
   */



   void interaction_impl::CloseWindow()
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //::CloseWindow(get_handle());

   }

   bool interaction_impl::OpenIcon()
   {

      throw ::exception(todo);

      //ASSERT(::is_window(get_handle()));
      //
      //return ::OpenIcon(get_handle()) != false;

      return false;

   }

   //////////////////////////////////////////////////////////////////////////////
   //// UI related ::windowing::window functions

   //oswindow interaction_impl::GetSafeOwner_(oswindow hParent,oswindow* pWndTop)
   //{

   //   throw ::exception(todo);

   //   //// get ::windowing::window to start with
   //   //oswindow hWnd = hParent;
   //   //if (hWnd == nullptr)
   //   //{
   //   //   /* trans      frame_window* pFrame = channel::GetRoutingFrame_();
   //   //   if (pFrame != nullptr)
   //   //   hWnd = pFrame->get_handle();
   //   //   else
   //   //   hWnd = ::auraacmesystem()->GetMainWnd()->get_handle();*/
   //   //}

   //   //// a popup ::windowing::window cannot be owned by a child ::windowing::window
   //   //while (hWnd != nullptr && (::GetWindowLong(hWnd, GWL_STYLE) & WS_CHILD))
   //   //   hWnd = ::get_parent(hWnd);

   //   //// determine toplevel ::windowing::window to disable as well
   //   //oswindow hWndTop = hWnd, hWndTemp = hWnd;
   //   //for (;;)
   //   //{
   //   //   if (hWndTemp == nullptr)
   //   //      break;
   //   //   else
   //   //      hWndTop = hWndTemp;
   //   //   hWndTemp = ::get_parent(hWndTop);
   //   //}

   //   //// get last active popup of first non-child that was found
   //   //if (hParent == nullptr && hWnd != nullptr)
   //   //   hWnd = ::GetLastActivePopup(hWnd);

   //   //// disable and store top level parent ::windowing::window if specified
   //   //if (pWndTop != nullptr)
   //   //{
   //   //   if (hWndTop != nullptr && ::IsWindowEnabled(hWndTop) && hWndTop != hWnd)
   //   //   {
   //   //      *pWndTop = hWndTop;
   //   //      ::EnableWindow(hWndTop, false);
   //   //   }
   //   //   else
   //   //      *pWndTop = nullptr;
   //   //}

   //   //return hWnd;    // return the owner as oswindow

   //   return nullptr;

   //}


   /////////////////////////////////////////////////////////////////////////////
   // Official way to send message to a interaction_impl

#ifdef WINDOWS_DESKTOP

   CLASS_DECL_AURA LRESULT __call_window_procedure(::user::interaction * pinteraction, oswindow hWnd, unsigned int nMsg, WPARAM wParam, LPARAM lParam)
   {


      // Catch exceptions thrown outside the scope of a callback
      // in debug builds and warn the ::account::user.
      ::pointer<::user::message>spbase;

      spbase(pinteraction->get_base(pinteraction, nMsg, wParam, lParam));

      __trace_message("WndProc", spbase);

      try
      {

         // special case for WM_INITDIALOG
         ::int_rectangle rectangleOld;
         unsigned int uStyle = 0;
         if (nMsg == WM_INITDIALOG)
            __pre_init_dialog(pinteraction, &rectangleOld, &uStyle);

         if(pinteraction->m_puserinteraction != nullptr && pinteraction->m_puserinteraction != pinteraction)
         {
            pinteraction->m_puserinteraction->message_handler(spbase);
         }
         else
         {
            pinteraction->message_handler(spbase);
         }
         // more special case for WM_INITDIALOG
         if (nMsg == WM_INITDIALOG)
            __post_init_dialog(pinteraction, rectangleOld, uStyle);
      }
      catch(const const ::exception & e)
      {
         try
         {
            if(App(pinteraction->get_application()).on_run_exception((::exception &) e))
               goto run;
         }
         catch(...)
         {
         }
         return -1;
      }
      catch(::exception::aura * pe)
      {
         __process_window_procedure_exception(pe, spbase);
         //         information(::aura::trace::category_AppMsg, 0, "Warning: Uncaught exception in message_handler (returning %ld).\n", spbase->get_lresult());
         ::exception_pointer esp(pe);
      }
      catch(...)
      {
      }
run:
      try
      {
         pThreadState->m_lastSentMsg = oldState;
         LRESULT lresult = spbase->get_lresult();
         return lresult;
      }
      catch(...)
      {
         return 0;
      }
   }

#endif


   /*CDataExchange::CDataExchange(::windowing::window * pDlgWnd, bool bSaveAndValidate)
   {
   ASSERT_VALID(pDlgWnd);
   m_bSaveAndValidate = bSaveAndValidate;
   m_pDlgWnd = pDlgWnd;
   m_atomLastControl = 0;
   }*/

   /////////////////////////////////////////////////////////////////////////////
   // Window creation hooks


#ifdef WINDOWS_DESKTOP

   LRESULT CALLBACK __cbt_filter_hook(int code, WPARAM wParam, LPARAM lParam)
   {
      if (code != HCBT_CREATEWND)
      {
         // wait for HCBT_CREATEWND just pass others on...
         return CallNextHookEx(pThreadState->m_hHookOldCbtFilter, code,
                               wParam, lParam);
      }

      ASSERT(lParam != nullptr);
      LPCREATESTRUCT lpcs = ((LPCBT_CREATEWND)lParam)->lpcs;
      ASSERT(lpcs != nullptr);

      ::user::interaction * pWndInit = pThreadState->m_pWndInit;
      bool bContextIsDLL = ::windows_definition::ContextIsDLL;
      if (pWndInit != nullptr || (!(lpcs->style & WS_CHILD) && !bContextIsDLL))
      {
         // Note: special check to avoid subclassing the IME interaction_impl
         //if (gen_DBCS)
         {
            // check for cheap CS_IME style first...
            if (GetClassLong((oswindow)wParam, GCL_STYLE) & CS_IME)
               goto lCallNextHook;

            // get class name of the interaction_impl that is being created
            const scoped_string & strClassName;
            char szClassName[_countof("ime")+1];
            if (dword_ptr(lpcs->lpszClass) > 0xffff)
            {
               pszClassName = lpcs->lpszClass;
            }
            else
            {
               szClassName[0] = '\0';
               GlobalGetAtomName((ATOM)lpcs->lpszClass, szClassName, _countof(szClassName));
               pszClassName = szClassName;
            }

            // a little more expensive to test this way, but necessary...
            if (::__invariant_stricmp(pszClassName, "ime") == 0)
               goto lCallNextHook;
         }

         ASSERT(wParam != nullptr); // should be non-nullptr oswindow
         oswindow hWnd = (oswindow)wParam;
         WNDPROC oldWndProc;
         if (pWndInit != nullptr)
         {
            // the interaction_impl should not be in the permanent ::map at this time
            ASSERT(::universal_windows::interaction_impl::FromHandlePermanent(hWnd) == nullptr);

            pWndInit->m_pthread = dynamic_cast < ::thread * > (::universal_windows::get_task());
            pWndInit->m_pthread->add(pWndInit);
            pWndInit->m_puserinteraction->m_pthread = pWndInit->m_pthread;
            pWndInit->m_puserinteraction->m_pthread->add(pWndInit->m_puserinteraction);
            pWndInit->m_puserinteraction->m_pimpl = pWndInit;

            // connect the oswindow to pWndInit...
            pWndInit->Attach(hWnd);
            // allow other subclassing to occur first
            pWndInit->pre_subclass_window();

            WNDPROC *pOldWndProc = pWndInit->GetSuperWndProcAddr();
            ASSERT(pOldWndProc != nullptr);

            // subclass the interaction_impl with standard __window_procedure
            WNDPROC ::windows_definition::WndProc = __get_window_procedure();
            oldWndProc = (WNDPROC)SetWindowLongPtr(hWnd, GWLP_WNDPROC,
                                                   (dword_ptr)::windows_definition::WndProc);
            ASSERT(oldWndProc != nullptr);
            if (oldWndProc != ::windows_definition::WndProc)
               *pOldWndProc = oldWndProc;

            pThreadState->m_pWndInit = nullptr;
         }
         else
         {
            ASSERT(!bContextIsDLL);   // should never get here

            static ATOM s_atomMenu = 0;
            bool bSubclass = true;

            if (s_atomMenu == 0)
            {
               WNDCLASSEX wc;
               memory_set(&wc, 0, sizeof(WNDCLASSEX));
               wc.cbSize = sizeof(WNDCLASSEX);
               s_atomMenu = (ATOM)::GetClassInfoEx(nullptr, "#32768", &wc);
            }

            // Do not subclass menus.
            if (s_atomMenu != 0)
            {
               ATOM atomWnd = (ATOM)::GetClassLongPtr(hWnd, GCW_ATOM);
               if (atomWnd == s_atomMenu)
                  bSubclass = false;
            }
            else
            {
               char szClassName[256];
               if (::GetClassName(hWnd, szClassName, 256))
               {
                  szClassName[255] = nullptr;
                  if (_tcscmp(szClassName, "#32768") == 0)
                     bSubclass = false;
               }
            }
            if (bSubclass)
            {
               // subclass the interaction_impl with the proc which does gray backgrounds
               oldWndProc = (WNDPROC)GetWindowLongPtr(hWnd, GWLP_WNDPROC);
               if (oldWndProc != nullptr && GetProp(hWnd, gen_OldWndProc) == nullptr)
               {
                  SetProp(hWnd, gen_OldWndProc, oldWndProc);
                  if ((WNDPROC)GetProp(hWnd, gen_OldWndProc) == oldWndProc)
                  {
                     GlobalAddAtom(gen_OldWndProc);
                     SetWindowLongPtr(hWnd, GWLP_WNDPROC, (dword_ptr)__activation_window_procedure);
                     ASSERT(oldWndProc != nullptr);
                  }
               }
            }
         }
      }

lCallNextHook:
      LRESULT lResult = CallNextHookEx(pThreadState->m_hHookOldCbtFilter, code,
                                       wParam, lParam);

      return lResult;
   }

#endif


   //void interaction_impl::_001OnEraseBkgnd(::message::message * pmessage)
   //{
   //   ::pointer<::message::erase_bkgnd>perasebkgnd(pmessage);
   //   perasebkgnd->m_bRet = true;
   //   perasebkgnd->set_result(true);
   //}


   //void interaction_impl::_001BaseWndInterfaceMap()
   //{

   //   ::auraacmesystem()->window_map().set((oswindow)(iptr)(void *)get_handle(),this);

   //}


   void interaction_impl::_001OnTriggerMouseInside()
   {

      //throw ::exception(todo);


//      m_bMouseHover = true;
      //TRACKMOUSEEVENT tme = { sizeof(tme) };
      //tme.dwFlags = TME_LEAVE;
      //tme.hwndTrack = get_handle();
      //TrackMouseEvent(&tme);

   }


} // namespace universal_windows




namespace aura_universal_windows
{



   ::user::interaction *  interaction_impl::get_wnd() const
   {

      return  m_puserinteraction;

   }


   //Agile<::winrt::Windows::UI::Core::CoreWindow> interaction_impl::get_os_window()
   //{
   //   
   //   return m_window;

   //}


   void interaction_impl::set_impact_port_org(::image::image * pimage)
   {
      // graphics will be already set its impact port to the interaction_impl for linux - cairo with xlib


      int_rectangle rectangleWindow;
      m_puserinteraction->window_rectangle(rectangleWindow);
      //      get_wnd()->screen_to_client(rectangleWindow);
      pimage->set_origin(int_point(rectangleWindow.top_left()));
      //pimage->SelectClipRgn(nullptr);

   }


   void interaction_impl::offset_impact_port_org(::int_rectangle * lprectScreen)
   {
   }


   //bool interaction_impl::has_pending_graphical_update()
   //{

   //   if (::windowing::window::has_pending_graphical_update())
   //   {

   //      return true;

   //   }

   //   {

   //      synchronous_lock synchronouslock(m_puserinteraction->synchronization());

   //      auto puserinteractionpointeraChild = m_puserinteraction->m_puserinteractionpointeraChild;

   //      if (puserinteractionpointeraChild)
   //      {

   //         for (auto p : puserinteractionpointeraChild->m_interactiona)
   //         {

   //            if (p != nullptr)
   //            {

   //               if (p->has_pending_graphical_update())
   //               {

   //                  return true;

   //               }

   //            }

   //         }

   //      }

   //   }

   //   return false;

   //}


   void interaction_impl::on_after_graphical_update()
   {

      //m_puserinteraction->on_after_graphical_update();

      {

         auto children = m_puserinteraction->synchronized_get_children();

         for (auto p : children)
         {

            p->on_after_graphical_update();

         }

      }

      m_pgraphicsgraphics->on_after_graphical_update();


      if (m_bNotifyLayoutCompletedPending)
      {

         m_bNotifyLayoutCompletedPending = false;

         //main_async(__routine([this]()
               //{

                  //int x = m_window->Bounds.X;

                  //int y = m_window->Bounds.Y;

                  //int cx = m_window->Bounds.Width;

                  //int cy = m_window->Bounds.Height;

         //m_pframeworkview.get().m_resizemanager->NotifyLayoutCompleted();

         ::output_debug_string("interaction_impl::on_after_graphical_update NotifyLayoutCompleted\n");

         //if (m_pframeworkview.get().m_directx->m_bCoreWindowVisible)
         //{

         //   ::output_debug_string("WindowVisible\n");

         //}
         //else
         //{

         //   ::output_debug_string("WindowNotVisible\n");

         //}

         //if (m_bPendingActivation)
         //{

         //   m_bPendingActivation = false;

         //   m_window->Activate();

         //}
      //}
               //}));

      }

   }


   void interaction_impl::update_graphics_resources()
   {

      ::windowing::window::update_graphics_resources();




   }


   void interaction_impl::queue_message_handler(::message::message * pmessage)
   {

      return ::windowing::window::queue_message_handler(pmessage);

      //synchronous_lock synchronouslock(synchronization());

      //m_messagelist.add_tail(pmessage);


      //defer_create_thread(this);

      //if (bFreeHandDrawingMode)
      //{

      //   return m_puserinteraction->message_handler(pbaseParam);

      //}
      //else
      //{

         //::pointer<::message::mouse>pmouse = pbaseParam;

         //if (pmouse)
         //{

         //   if (pmouse->m_atom == e_message_mouse_move)
         //   {

         //      double_point pointNow(pmouse->m_point);

         //      double dx = pointNow.x - m_pointLastMouseMove.x;

         //      double dy = pointNow.y - m_pointLastMouseMove.y;

         //      m_pointLastMouseMove = pointNow;

         //      double dDistanceFromLast = sqrt(dx * dx + dy * dy);

         //      m_dAccumulatedMouseMoveDistance += dDistanceFromLast;

         //      double dTimeFromLast = (double) m_timeLastMouseMove.elapsed().m_i / 1000.0;

         //      if (dTimeFromLast == 0.) dTimeFromLast = 0.001;

         //      double dDistanceMomentum = m_dAccumulatedMouseMoveDistance * dTimeFromLast;

         //      bool bIgnoreMessage = dDistanceMomentum < 2.0;

         //      if (bIgnoreMessage)
         //      {

         //         return;

         //      }

         //      m_dAccumulatedMouseMoveDistance = 0.0;

         //      m_timeLastMouseMove.Now();

         //   }

         //}

         //synchronous_lock synchronouslock(&m_mutexQueue);

         //m_messageaQueue.add(pusermessage);

         //m_evQueue.set_event();
      
         //void primitive_impl::queue_message_handler(::user::message * pbaseParam)
         //{

         //::pointer<::user::message>pusermessage = pbaseParam;

      synchronous_lock synchronouslock(synchronization());

      m_messagelist.add_tail(pmessage);

         //post(pmessage);

      //}

      //m_puserinteraction->message_handler(pusermessage);

   }


   bool interaction_impl::has_keyboard_focus()
   {

      //return get_handle() == ::get_focus();

      return m_pwindow->has_keyboard_focus();

   }


   bool interaction_impl::is_active()
   {

      return m_pwindow->is_active_window();

   }


   //void interaction_impl::_001UpdateScreen()
   //{

   //   ::windowing::window::_001UpdateScreen();

   //}


   bool interaction_impl::_is_window() const
   {

      return m_pwindow != nullptr;

   }


   //void interaction_impl::show_software_keyboard(::user::primitive * pprimitive, string str, character_count iBeg, character_count iEnd)
   //{

   //}


   //void interaction_impl::hide_software_keyboard(::user::primitive * pprimitive)
   //{

   //}


   void interaction_impl::edit_on_set_focus(::user::interaction* pinteraction)
   {

      string strText;

      pinteraction->get_text(strText);

      character_count sizeLen = strText.length();

      //m_pframeworkview.get().SetText(strText, 0, sizeLen);

   }


   bool interaction_impl::is_text_composition_active()
   {

      //return m_pframeworkview.get().m_bTextCompositionActive;

      return false;


   }


   void interaction_impl::set_input_content_rect(const int_rectangle& rectangle)
   {

      //__copy(m_pframeworkview.get().m_rectangleInputContentRect, rectangle);

   }


   void interaction_impl::set_input_selection_rect(const int_rectangle& rectangle)
   {

      //__copy(m_pframeworkview.get().m_rectangleInputSelectionRect, rectangle);

   }


   int_rectangle interaction_impl::get_input_content_rect()
   {

      ::int_rectangle rectangle;

      //__copy(rectangle, m_pframeworkview.get().m_rectangleInputContentRect);

      return rectangle;

   }


   int_rectangle interaction_impl::get_input_selection_rect()
   {

      ::int_rectangle rectangle;

      return rectangle;


   }


   void interaction_impl::on_layout(::draw2d::graphics_pointer & pgraphics)
   {

      ::windowing::window::on_layout(pgraphics);

      int_rectangle rectangleX;

      rectangleX = m_puserinteraction->rectangle();

      if (rectangleX.is_empty())
      {

         return;

      }

      m_bNotifyLayoutCompletedPending = true;

   }

   
   void interaction_impl::_create_window()
   {

      

      auto puser = user();

      auto pwindowing = system()->windowing();

      pwindowing->new_window(this);

      if (m_pwindow)
      {

         information() << "operating_system_create_host window created";

      }
      else
      {

         informationf("operating_system_create_host window not created");

      }

   }


   void interaction_impl::user_post(const ::procedure & procedure)
   {

      if (!m_pwindow)
      {

         ::channel::user_post(procedure);

         return;

      }

      m_pwindow->user_post(procedure);

   }


} // namespace aura_universal_windows



