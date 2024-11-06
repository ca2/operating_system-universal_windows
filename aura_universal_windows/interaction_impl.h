#pragma once


#include "acme/parallelization/manual_reset_event.h"
//#include "aura/user/user/interaction_impl.h"


namespace aura_universal_windows
{

  
   class CLASS_DECL_AURA_UNIVERSAL_WINDOWS interaction_impl :
      virtual public ::windowing::window
   {
   public:


      bool                                                              m_bNotifyLayoutCompletedPending;
      string                                                            m_strWindowText;
      double_point                                                         m_pointLastMouseMove;
      double                                                            m_dAccumulatedMouseMoveDistance;
      class ::time                                                            m_timeLastMouseMove;
      iptr_to_iptr                                                      m_mapLong;
      ::particle_pointer                                          m_pparticleMutexQueue;
      manual_reset_event                                                m_evQueue;
      pointer_array < ::user::message >                                  m_messageaQueue;
      int m_nModalResult; // for return values from ::windowing::window::RunModalLoop



      interaction_impl();
      //interaction_impl(::particle * pparticle);
      ~interaction_impl() override;


      virtual void construct(::oswindow hwnd);


      //void assert_ok() const override;
      //void dump(dump_context & dumpcontext) const override;


      //virtual bool has_pending_graphical_update();
      virtual void on_after_graphical_update();

      //virtual void on_delete(matter * poc);

      //virtual oswindow get_handle() const;

      virtual ::user::interaction * get_wnd() const;

      //bool create_message_queue(::user::interaction * pinteraction, const ::string & pszName);

      //virtual bool create_native_window(::user::native_window_initialize * pinitialize) ;


      virtual iptr get_window_long_ptr(int nIndex) const;
      virtual iptr set_window_long_ptr(int nIndex, iptr lValue) ;

      //static const MSG* GetCurrentMessage();

      void install_message_routing(::channel * pchannel) override;

      //bool operator==(const ::windowing::window& wnd) const;
      //bool operator!=(const ::windowing::window& wnd) const;

      unsigned int GetStyle() const;
      unsigned int GetExStyle() const;
      bool ModifyStyle(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags = 0);
      bool ModifyStyleEx(unsigned int dwRemove, unsigned int dwAdd, unsigned int nFlags = 0);

      //virtual ::user::interaction * get_owner();
      //virtual ::user::interaction * SetOwner(::user::interaction * pOwnerWnd);

      //virtual oswindow _get_handle();

      void route_command(::message::command * pcommand, bool bRouteToKeyDescendant = false) override;

      virtual void handle(::topic * ptopic, ::context * pcontext);

      //virtual ::e_status main_async(const ::procedure & procedure, enum_priority epriority = e_priority_normal);

      void _002OnDraw(::image::image * pimage);

      void on_layout(::draw2d::graphics_pointer & pgraphics);


      //DECLARE_MESSAGE_HANDLER(_001OnEraseBkgnd);
      DECLARE_MESSAGE_HANDLER(on_message_move);
      DECLARE_MESSAGE_HANDLER(on_message_size);
      // DECLARE_MESSAGE_HANDLER(on_message_show_window);
      DECLARE_MESSAGE_HANDLER(_001OnProdevianSynch);

      DECLARE_MESSAGE_HANDLER(on_message_set_focus);

      DECLARE_MESSAGE_HANDLER(on_message_kill_focus);

      
      void show_software_keyboard(::user::element* pelement) override;

      void hide_software_keyboard(::user::element* pelement) override;
  

      //      virtual ::windowing::window * from_os_data(void * pdata);
      //    virtual void * get_os_data() const;

      //      static interaction_impl * from_handle(oswindow hWnd);
      //    static interaction_impl * FromHandlePermanent(oswindow hWnd);
      //static void DeleteTempMap();
      //      bool Attach(oswindow hWndNew);
      //    oswindow Detach();

      // subclassing/unsubclassing functions
      virtual void pre_subclass_window();
      //bool SubclassWindow(::oswindow hWnd);
      //bool SubclassDlgItem(unsigned int nID, ::windowing::window * pParent);
      //::oswindow UnsubclassWindow();

      // handling of RT_DLGINIT resource (extension to RT_DIALOG)
      //bool ExecuteDlgInit(const ::string & lpszResourceName);
      //bool ExecuteDlgInit(LPVOID lpResource);


      bool is_composite() override;


      void update_graphics_resources() override;

      // for child windows, views, panes etc
      //virtual bool create_window(::user::interaction * pinteraction, const ::string & lpszClassName, const ::string & lpszWindowName,unsigned int dwStyle,const ::int_rectangle &rectangle,::user::interaction * pParentWnd,atom atom, ::request * prequest = nullptr) ;

      virtual bool _native_create_window_ex(::pointer<::user::system>pcs);


      //virtual ::int_point get_cursor_position() const;


      //virtual bool CreateEx(unsigned int dwExStyle, const ::string & lpszClassName,
      //                      const char * lpszWindowName, unsigned int dwStyle,
      //                      int x, int y, int nWidth, int nHeight,
      //                      oswindow hWndParent, atom atom, LPVOID lpParam = nullptr);

      //virtual bool CreateEx(unsigned int dwExStyle, const ::string & lpszClassName,
      //                      const char * lpszWindowName, unsigned int dwStyle,
      //                      const ::int_rectangle &rectangle,
      //                      ::user::interaction* pParentWnd, atom atom,
      //                      LPVOID lpParam = nullptr);

      virtual bool DestroyWindow();

      // special pre-creation and ::windowing::window int_rectangle adjustment hooks
      virtual bool pre_create_window(::user::system * pusersystem);

      // Advanced: virtual AdjustWindowRect
      enum AdjustType { adjustBorder = 0, adjustOutside = 1 };
      virtual void CalcWindowRect(::int_rectangle * lpClientRect, unsigned int nAdjustType = adjustBorder);


      // get immediate child with given ID
      //      using ::user::interaction::GetDlgItem;
      void GetDlgItem(atom atom, ::oswindow* phWnd) const;

      //virtual bool IsWindow() const;

#if(WINVER >= 0x0500)

      ::windowing::window * GetAncestor(unsigned int gaFlags) const ;

#endif   // WINVER >= 0x0500

      //LRESULT send_message(const ::atom & atom, WPARAM wParam = 0, lparam lParam = nullptr);
      //bool post_message(const ::atom & atom, WPARAM wParam = 0, lparam lParam = nullptr);

      //bool SendNotifyMessage(const ::atom & atom, WPARAM wParam, LPARAM lParam);
      //bool SendChildNotifyLastMsg(LRESULT* pResult = nullptr);

      //bool DragDetect(::int_point pt) const;



      // Window Text Functions
      void set_window_text(const ::string & lpszString) ;
      //character_count get_window_text(char * lpszStringBuf, character_count nMaxCount) ;
      void get_window_text(string & rString) ;
      //character_count get_window_text_length() ;
      //void SetFont(::write_text::font* pFont, bool bRedraw = true);
      //::write_text::font* GetFont();


      // Window int_size and position Functions
      //virtual bool layout().is_iconic();
      //virtual bool layout().is_zoomed();
      //void MoveWindow(int x, int y, int nWidth, int nHeight, bool bRepaint = true);
      //void MoveWindow(const ::int_rectangle * lpRect, bool bRepaint = true);
      //int SetWindowRgn(HRGN hRgn, bool bRedraw);
      //int GetWindowRgn(HRGN hRgn);


      //virtual bool set_window_position(iptr z, int x, int y, int cx, int cy, unsigned int nFlags);
      virtual unsigned int ArrangeIconicWindows();
      virtual bool BringWindowToTop();
      //using ::windowing::window::window_rectangle;
      //virtual bool window_rectangle(::i64_rectangle * lpRect);
      //using ::windowing::window::this->rectangle;
      //virtual bool this->rectangle(::i64_rectangle * lpRect);

      //virtual bool client_to_screen(::int_rectangle * lprect);
      //virtual bool client_to_screen(::int_point * lppoint);
      //virtual bool client_to_screen(::i64_rectangle * lprect);
      //virtual bool client_to_screen(::huge_integer_point * lppoint);
      //virtual bool screen_to_client(::int_rectangle * lprect);
      //virtual bool screen_to_client(::int_point * lppoint);
      //virtual bool screen_to_client(::i64_rectangle * lprect);
      //virtual bool screen_to_client(::huge_integer_point * lppoint);

      //      virtual bool GetWindowPlacement(WINDOWPLACEMENT* lpuserinteractionpl);
      //    virtual bool SetWindowPlacement(const WINDOWPLACEMENT* lpuserinteractionpl);

      // Coordinate Mapping Functions
      virtual void MapWindowPoints(::windowing::window * puserinteractionTo, ::int_point * lpPoint, unsigned int nCount);
      virtual void MapWindowPoints(::windowing::window * puserinteractionTo, ::int_rectangle * lpRect);

      // Update/Painting Functions
      virtual ::draw2d::graphics * GetDC();
      virtual ::draw2d::graphics * GetWindowDC();
      virtual bool ReleaseDC(::image::image * pimage);
      virtual void Print(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const;
      virtual void PrintClient(::draw2d::graphics_pointer & pgraphics, unsigned int dwFlags) const;

      virtual void UpdateWindow();
      virtual void SetRedraw(bool bRedraw = true);
      //virtual bool GetUpdateRect(::int_rectangle * lpRect, bool bErase = false);
      //virtual int GetUpdateRgn(::draw2d::region* pRgn, bool bErase = false);
      //virtual void Invalidate(bool bErase = true);
      //virtual void InvalidateRect(const ::int_rectangle * lpRect, bool bErase = true);
      //virtual void InvalidateRgn(::draw2d::region* pRgn, bool bErase = true);
      //virtual void ValidateRect(const ::int_rectangle * lpRect);
      //virtual void ValidateRgn(::draw2d::region* pRgn);
      virtual bool show_window(int nCmdShow);
      virtual void _001WindowMaximize();
      virtual void _001WindowRestore();
      virtual bool is_window_visible();
      virtual void ShowOwnedPopups(bool bShow = true);

      virtual ::draw2d::graphics * GetDCEx(::draw2d::region* prgnClip, unsigned int flags);
      //virtual bool LockWindowUpdate();
      //virtual void UnlockWindowUpdate();
      //virtual bool RedrawWindow(const ::int_rectangle& rectangleUpdate = nullptr,
                                //::draw2d::region* prgnUpdate = nullptr,
                                //unsigned int flags = RDW_INVALIDATE | RDW_ERASE);
      //      virtual bool EnableScrollBar(int nSBFlags, unsigned int nArrowFlags = ESB_ENABLE_BOTH);

      virtual bool DrawAnimatedRects(int idAni, const ::int_rectangle *lprcFrom, const ::int_rectangle *lprcTo);
      virtual bool DrawCaption(::draw2d::graphics_pointer & pgraphics, const ::int_rectangle * lprc, unsigned int uFlags);

//#if(WINVER >= 0x0500)
//
//      virtual bool AnimateWindow(const class time & time, unsigned int dwFlags);
//
//#endif   // WINVER >= 0x0500

#if(_WIN32_WINNT >= 0x0501)

      virtual bool PrintWindow(::draw2d::graphics_pointer & pgraphics, unsigned int nFlags) const;

#endif   // _WIN32_WINNT >= 0x0501

      // Layered Window



      // Timer Functions
      void SetTimer(uptr uEvent, const class ::time& millisElapse, PFN_TIMER pfnTimer = nullptr, bool bPeriodic = true, void* pdata = nullptr) override;
      void KillTimer(uptr uEvent) override;

      // Window State Functions
      virtual bool IsWindowEnabled();
      virtual bool EnableWindow(bool bEnable = true);

      // the active ::windowing::window applies only to top-level (frame windows)
      //virtual ::user::interaction * get_active_window();
      //virtual ::user::interaction * set_active_window();

      // the foreground ::windowing::window applies only to top-level windows (frame windows)
      //virtual bool set_foreground_window();
      //static ::pointer<::windowing::window>get_foreground_window();

      virtual atom SetDlgCtrlId(atom atom);
      virtual atom GetDlgCtrlId();



      //virtual ::user::interaction *  XXXGetFocus();
      //virtual bool  XXXSetFocus() ;

      //static ::user::interaction *  get_desktop_window();

      // Obsolete and non-portable APIs - not recommended for ___new code
      virtual void CloseWindow();
      virtual bool OpenIcon();

      // Dialog-Box Item Functions
      // (NOTE: Dialog-Box Items/Controls are not necessarily in dialog boxes!)
      virtual void CheckDlgButton(int nIDButton, unsigned int nCheck);
      virtual void CheckRadioButton(int nIDFirstButton, int nIDLastButton,
                                    int nIDCheckButton);
      virtual int GetCheckedRadioButton(int nIDFirstButton, int nIDLastButton);
      /*virtual int DlgDirList(__inout_z char * lpPathSpec, __in int nIDListBox,
      __in int nIDStaticPath, __in unsigned int nFileType);
      virtual int DlgDirListComboBox(__inout_z char * lpPathSpec, __in int nIDComboBox,
      __in int nIDStaticPath, __in unsigned int nFileType);
      virtual bool DlgDirSelect(__out_ecount_z(nSize) char * lpString, __in int nSize, __in int nIDListBox);
      virtual bool DlgDirSelectComboBox(__out_ecount_z(nSize) char * lpString, __in int nSize, __in int nIDComboBox);*/

      // virtual unsigned int GetDlgItemInt(int nID, BOOL * lpTrans = nullptr, bool bSigned = true) const;
      //      virtual int GetDlgItemText(__in int nID, __out_ecount_part_z(nMaxCount, return + 1) char * lpStr, __in int nMaxCount) const;
      //    virtual int GetDlgItemText(int nID, string & rString) const;
      virtual ::windowing::window * GetNextDlgGroupItem(::windowing::window * pWndCtl, bool bPrevious = false) const;
      virtual ::windowing::window * GetNextDlgTabItem(::windowing::window * pWndCtl, bool bPrevious = false) const;
      virtual unsigned int IsDlgButtonChecked(int nIDButton) const;
      virtual LRESULT SendDlgItemMessage(int nID, const ::atom & atom, WPARAM wParam = 0, LPARAM lParam = 0);
      virtual void SetDlgItemInt(int nID, unsigned int nValue, bool bSigned = true);
      virtual void SetDlgItemText(int nID, const ::string & lpszString);

      // Scrolling Functions
      virtual int GetScrollPos(int nBar) const;
      virtual void GetScrollRange(int nBar, LPINT lpMinPos, LPINT lpMaxPos) const;
      //virtual void ScrollWindow(int xAmount, int yAmount,
      //                          const ::int_rectangle * lpRect = nullptr,
      //                          const ::int_rectangle * lpClipRect = nullptr);
      virtual int SetScrollPos(int nBar, int nPos, bool bRedraw = true);
      virtual void SetScrollRange(int nBar, int nMinPos, int nMaxPos,
                                  bool bRedraw = true);
      virtual void ShowScrollBar(unsigned int nBar, bool bShow = true);
      virtual void EnableScrollBarCtrl(int nBar, bool bEnable = true);
//      virtual CScrollBar* GetScrollBarCtrl(int nBar) const;
      // return sibling scrollbar control (or nullptr if none)

      //virtual int ScrollWindowEx(int dx, int dy,
      //                           const ::int_rectangle * lpRectScroll, const ::int_rectangle * lpRectClip,
      //                           ::draw2d::region* prgnUpdate, ::int_rectangle * lpRectUpdate, unsigned int flags);
      //      virtual bool SetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo,
      //       bool bRedraw = true);
      //      virtual bool GetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, unsigned int nMask = SIF_ALL);
      virtual int GetScrollLimit(int nBar);

      //#if defined(WINDOWS_DESKTOP) && (WINVER >= 0x0500)

      // virtual bool GetScrollBarInfo(int idObject, PSCROLLBARINFO psbi) const;

      //#endif   // WINVER >= 0x0500

      // Window Access Functions
      virtual ::user::interaction *  ChildWindowFromPoint(::int_point int_point);
      virtual ::user::interaction *  ChildWindowFromPoint(::int_point point, unsigned int nFlags);
      static ::pointer<::windowing::window>FindWindow(const ::string & lpszClassName, const ::string & lpszWindowName);
      static ::pointer<::windowing::window>FindWindowEx(::oswindow hwndParent, ::oswindow hwndChildAfter, const ::string & lpszClass, const ::string & lpszWindow);

      //      virtual ::user::interaction * GetNextWindow(unsigned int nFlag = GW_HWNDNEXT);
      virtual ::user::interaction *  GetTopWindow();

      virtual ::user::interaction *  GetWindow(unsigned int nCmd);
      virtual ::user::interaction *  GetLastActivePopup();

      virtual bool IsChild(::user::interaction *   pWnd);
      virtual ::user::interaction *  get_parent() const ;
      //using ::windowing::window::set_parent;
//      ::user::interaction *  SetParent(::user::interaction *  pWndNewParent);
      //static ::pointer<::windowing::window>WindowFromPoint(::int_point int_point);

      // Alert Functions

      //bool FlashWindow(bool bInvert);

      //virtual int message_box(const ::string & lpszText, const ::string & lpszCaption = nullptr, unsigned int nType = e_message_box_ok);


//#if(WINVER >= 0x0500)
//
//      virtual bool FlashWindowEx(unsigned int dwFlags, unsigned int  uCount, class ::time tickTimeout);
//
//#endif   // WINVER >= 0x0500
//
//      // Clipboard Functions
//      virtual bool ChangeClipboardChain(oswindow hWndNext);
//      virtual oswindow SetClipboardViewer();
//      virtual bool OpenClipboard();
//      static ::windowing::window * GetClipboardOwner();
//      static ::windowing::window * GetClipboardViewer();
//      static ::windowing::window * GetOpenClipboardWindow();
//
//      // Caret Functions
//      static int_point GetCaretPos();
//      static void SetCaretPos(::int_point int_point);
//      virtual void HideCaret();
//      virtual void ShowCaret();

      // Shell Interaction Functions
      virtual void DragAcceptFiles(bool bAccept = true);

      // icon Functions
      //virtual HICON SetIcon(HICON hIcon, bool bBigIcon);
      ///virtual HICON GetIcon(bool bBigIcon) const;

      // Context Help Functions
      //virtual bool SetWindowContextHelpId(unsigned int dwContextHelpId);
      //virtual unsigned int GetWindowContextHelpId() const;

       //support
      //virtual bool UpdateData(bool bSaveAndValidate = true);
      // data wnd must be same type as this

      //// Help Command Handlers
      //void OnHelp();          // F1 (uses current action_context)
      //void OnHelpIndex();     // ID_HELP_INDEX
      //void OnHelpFinder();    // ID_HELP_FINDER, ID_DEFAULT_HELP
      //void OnHelpUsing();     // ID_HELP_USING
      //void UpdateDialogControls(channel* pTarget, bool bDisableIfNoHndler);
      //void CenterWindow(::user::interaction * pAlternateOwner = nullptr);
      ////virtual atom RunModalLoop(unsigned int dwFlags = 0) ;
      //virtual bool ContinueModal() ;
      //virtual void EndModalLoop(atom nResult) ;
      ////virtual void EndAllModalLoops(atom nResult);

      //// Window-Management message handler member functions
      //virtual bool OnCommand(WPARAM wParam, LPARAM lParam);
      //virtual bool OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);

      //void OnActivate(unsigned int nState, ::windowing::window * pWndOther, bool bMinimized);
      //void OnActivateApp(bool bActive, unsigned int dwThreadID);
      //LRESULT OnActivateTopLevel(WPARAM, LPARAM);
      void OnCancelMode();
      void OnChildActivate();
      void OnClose();
      void OnContextMenu(::windowing::window * pWnd, int_point pos);
      //      bool OnCopyData(::windowing::window * pWnd, COPYDATASTRUCT* pCopyDataStruct);
      DECLARE_MESSAGE_HANDLER(on_message_create);


      HBRUSH OnCtlColor(::draw2d::graphics_pointer & pgraphics, ::windowing::window * pWnd, unsigned int nCtlColor);

      DECLARE_MESSAGE_HANDLER(on_message_destroy);
      void OnEnable(bool bEnable);
      void OnEndSession(bool bEnding);
      void OnEnterIdle(unsigned int nWhy, ::windowing::window * pWho);
      bool OnEraseBkgnd(::draw2d::graphics_pointer & pgraphics);
      //      void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
      //    bool OnHelpInfo(HELPINFO* lpHelpInfo);
      void OnIconEraseBkgnd(::draw2d::graphics_pointer & pgraphics);
      void OnKillFocus(::windowing::window * pNewWnd);
      //LRESULT OnMenuChar(unsigned int nChar, unsigned int nFlags, ::user::menu* pMenu);
      void OnMenuSelect(unsigned int nItemID, unsigned int nFlags, HMENU hSysMenu);
      void OnMove(int x, int y);
      DECLARE_MESSAGE_HANDLER(_001OnPaint);
      DECLARE_MESSAGE_HANDLER(_001OnPrint);
      //void OnParentNotify(unsigned int message, LPARAM lParam);
      HCURSOR OnQueryDragIcon();
      bool OnQueryEndSession();
      bool OnQueryNewPalette();
      bool OnQueryOpen();
      void OnSetFocus(::windowing::window * pOldWnd);
      void OnShowWindow(bool bShow, unsigned int nStatus);
      void OnSize(unsigned int nType, int cx, int cy);
      void OnTCard(unsigned int idAction, unsigned int dwActionData);
      //      void OnWindowPosChanging(WINDOWPOS* lpuserinteractionpos);
      //    void OnWindowPosChanged(WINDOWPOS* lpuserinteractionpos);

      void OnChangeUIState(unsigned int nAction, unsigned int nUIElement);
      void OnUpdateUIState(unsigned int nAction, unsigned int nUIElement);
      unsigned int OnQueryUIState();

      // Nonclient-Area message handler member functions
      //bool OnNcActivate(bool bActive);
      //      void OnNcCalcSize(bool bCalcValidRects, NCCALCSIZE_PARAMS* lpncsp);
      //bool OnNcCreate(LPCREATESTRUCT lpCreateStruct);

      //LRESULT OnNcHitTest(::int_point point);
      //void OnNcLButtonDblClk(unsigned int nHitTest, const ::int_point & point);
      //void OnNcLButtonDown(unsigned int nHitTest, const ::int_point & point);
      //void OnNcLButtonUp(unsigned int nHitTest, const ::int_point & point);
      //void OnNcMButtonDblClk(unsigned int nHitTest, const ::int_point & point);
      //void OnNcMButtonDown(unsigned int nHitTest, const ::int_point & point);
      //void OnNcMButtonUp(unsigned int nHitTest, const ::int_point & point);
      //void OnNcMouseMove(unsigned int nHitTest, const ::int_point & point);
      //void OnNcPaint();
      //void OnNcRButtonDblClk(unsigned int nHitTest, const ::int_point & point);
      //void OnNcRButtonDown(unsigned int nHitTest, const ::int_point & point);
      //void OnNcRButtonUp(unsigned int nHitTest, const ::int_point & point);

      // ::auraacmesystem() message handler member functions
      //      void OnDropFiles(HDROP hDropInfo);
      void OnPaletteIsChanging(::windowing::window * pRealizeWnd);
      void OnSysChar(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags);
      void OnSysCommand(unsigned int nID, LPARAM lParam);
      void OnSysDeadChar(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags);
      void OnSysKeyDown(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags);
      void OnSysKeyUp(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags);
      void OnCompacting(unsigned int nCpuTime);
      void OnDevModeChange(char * lpDeviceName);
      void OnFontChange();
      void OnPaletteChanged(::windowing::window * pFocusWnd);
      void OnSpoolerStatus(unsigned int nStatus, unsigned int nJobs);
      void OnSysColorChange();
      void OnTimeChange();
      //void OnSettingChange(unsigned int uFlags, const ::string & lpszSection);
      //void OnWinIniChange(const ::string & lpszSection);

      // Input message handler member functions
      void OnChar(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags);
      void OnDeadChar(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags);
//      void OnHScroll(unsigned int nSBCode, unsigned int nPos, CScrollBar* pScrollBar);
      //    void OnVScroll(unsigned int nSBCode, unsigned int nPos, CScrollBar* pScrollBar);
      void OnKeyDown(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags);
      void OnKeyUp(unsigned int nChar, unsigned int nRepCnt, unsigned int nFlags);
      void OnLButtonDblClk(unsigned int nFlags, const ::int_point & point);
      void OnLButtonDown(unsigned int nFlags, const ::int_point & point);
      void OnLButtonUp(unsigned int nFlags, const ::int_point & point);
      void OnMButtonDblClk(unsigned int nFlags, const ::int_point & point);
      void OnMButtonDown(unsigned int nFlags, const ::int_point & point);
      void OnMButtonUp(unsigned int nFlags, const ::int_point & point);
      int OnMouseActivate(::windowing::window * pDesktopWnd, unsigned int nHitTest, const ::atom & atom);
      void OnMouseMove(unsigned int nFlags, const ::int_point & point);
      bool OnMouseWheel(unsigned int nFlags, short zDelta, const ::int_point & point);
      LRESULT OnRegisteredMouseWheel(WPARAM wParam, LPARAM lParam);
      void OnRButtonDblClk(unsigned int nFlags, const ::int_point & point);
      void OnRButtonDown(unsigned int nFlags, const ::int_point & point);
      void OnRButtonUp(unsigned int nFlags, const ::int_point & point);
      ////DECLARE_MESSAGE_HANDLER(on_message_set_cursor);
      void OnTimer(uptr uEvent);

      // Initialization message handler member functions
      //void OnInitMenu(::user::menu* pMenu);
      //void OnInitMenuPopup(::user::menu* pPopupMenu, unsigned int nIndex, bool bSysMenu);

      // Clipboard message handler member functions
      void OnAskCbFormatName(__in unsigned int nMaxCount, __out_ecount_z(nMaxCount) char * lpszString);
      void OnDestroyClipboard();
      void OnDrawClipboard();
      void OnHScrollClipboard(::windowing::window * pClipAppWnd, unsigned int nSBCode, unsigned int nPos);
      void OnPaintClipboard(::windowing::window * pClipAppWnd, HGLOBAL hPaintStruct);
      void OnRenderAllFormats();
      void OnRenderFormat(unsigned int nFormat);
      void OnSizeClipboard(::windowing::window * pClipAppWnd, HGLOBAL hRect);
      void OnVScrollClipboard(::windowing::window * pClipAppWnd, unsigned int nSBCode, unsigned int nPos);

      // control message handler member functions
      //      int OnCompareItem(int nIDCtl, LPCOMPAREITEMSTRUCT lpCompareItemStruct);
      //    void OnDeleteItem(int nIDCtl, LPDELETEITEMSTRUCT lpDeleteItemStruct);
      //  void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
      unsigned int OnGetDlgCode();
      //void OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct);

      // MDI message handler member functions
      void OnMDIActivate(bool bActivate,
                         ::windowing::window * pActivateWnd, ::windowing::window * pDeactivateWnd);

      // menu loop notification messages
      void OnEnterMenuLoop(bool bIstrack_popup_menu);
      void OnExitMenuLoop(bool bIstrack_popup_menu);

      // Win4 messages
      //      void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
      //    void OnStyleChanging(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
      void OnSizing(unsigned int nSide, ::int_rectangle * lpRect);
      void OnMoving(unsigned int nSide, ::int_rectangle * lpRect);
      void OnCaptureChanged(::windowing::window * pWnd);
      bool OnDeviceChange(unsigned int nEventType, ::uptr dwData);

      // Overridables and other helpers (for implementation of derived classes)
      // for deriving from a standard control
      //      virtual WNDPROC* GetSuperWndProcAddr();

      // for dialog data exchange and validation
      //      virtual void DoDataExchange(CDataExchange* pDX);

      // for modality
      virtual void BeginModalState();
      virtual void EndModalState();

      // for translating Windows messages in main message pump
      virtual void pre_translate_message(::message::message * pmessage);


      // for processing Windows messages
      virtual void message_handler(::message::message * pmessage);
      //virtual bool OnWndMsg(const ::atom & atom, WPARAM wParam, LPARAM lParam, LRESULT* pResult);

      // for handling default processing
      LRESULT Default();
      virtual LRESULT DefWindowProc(unsigned int message, WPARAM wParam, lparam lParam);

      // for custom cleanup after e_message_non_client_destroy
      virtual void post_non_client_destroy();

      // for notifications from parent
      //virtual bool OnChildNotify(unsigned int message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
      // return true if parent should not process this message
      //bool ReflectChildNotify(unsigned int message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
      //static bool ReflectLastMsg(oswindow hWndChild, LRESULT* pResult = nullptr);

      //virtual bool CheckAutoCenter();
      //static bool GrayCtlColor(HDC hDC, oswindow hWnd, unsigned int nCtlColor,
        //                       HBRUSH hbrGray, color32_t clrText);


      // helper routines for implementation
      //bool HandleFloatingSysCommand(unsigned int nID, LPARAM lParam);
      //bool IsTopParentActive();
      void ActivateTopParent();
      virtual void WalkPreTranslateTree(::user::interaction * puiStop, ::message::message * pmessage);
      virtual bool is_frame_window(); // is_kind_of(::auraacmesystem()->template type_info < frame_window > ()))
      virtual void on_final_release();
      //static void _FilterToolTipMessage(MSG* pMsg, ::windowing::window * pWnd);
      bool _EnableToolTips(bool bEnable, unsigned int nFlag);
      //static ::oswindow GetSafeOwner_(::oswindow hWnd, :oswindow* pWndTop);
      void PrepareForHelp();

      //unsigned int m_nFlags;      // see WF_ flags above

      //      WNDPROC m_pfnSuper; // for subclassing of controls
      //static const unsigned int m_nMsgDragList;

      //::write_text::font * m_pfont;

      friend class frame_window;

      // for creating dialogs and dialog-like windows
      bool CreateDlg(const ::string & lpszTemplateName, ::windowing::window * pParentWnd);
      //bool CreateDlgIndirect(LPCDLGTEMPLATE lpDialogTemplate, ::windowing::window * pParentWnd,
      // HINSTANCE hInst);


      // implementation of message dispatch/hooking
      CLASS_DECL_AURA friend LRESULT CALLBACK __send_message_hook(int, WPARAM, LPARAM);
      //CLASS_DECL_AURA friend void _gen::StandardSubclass(oswindow);
      CLASS_DECL_AURA friend LRESULT CALLBACK __cbt_filter_hook(int, WPARAM, LPARAM);
      CLASS_DECL_AURA friend LRESULT __call_window_procedure(::user::interaction * pWnd, ::oswindow hWnd, unsigned int nMsg, WPARAM wParam, LPARAM lParam);

      // standard message implementation
      //LRESULT OnNTCtlColor(WPARAM wParam, LPARAM lParam);
      //LRESULT OnDisplayChange(WPARAM, LPARAM);
      LRESULT OnDragList(WPARAM, LPARAM);

      //static BOOL CALLBACK GetAppsEnumWindowsProc(oswindow hwnd, LPARAM lParam);


      //static void get_app_wnda(user::oswindow_array & wnda);

      virtual void _001DeferPaintLayeredWindowBackground(HDC hdc);

      virtual int GetWindowLong(int nIndex);
      virtual int SetWindowLong(int nIndex, int lValue);

      //virtual void _001BaseWndInterfaceMap();


      // void _001UpdateWindow();
      virtual bool has_keyboard_focus() ;
      virtual bool is_active() ;


      //virtual void _001UpdateScreen() ;

      void _001OnTriggerMouseInside();


      //winrt::agile_ref < ::winrt::Windows::UI::Core::CoreWindow > get_os_window();

      void set_impact_port_org(::image::image * pimage);

      void offset_impact_port_org(::int_rectangle * lprectScreen);

      void queue_message_handler(::message::message * pusermessage) override;

      virtual bool _is_window() const ;

      //void show_software_keyboard(::user::primitive * pprimitive, string str, character_count iBeg, character_count iEnd) override;

      //void hide_software_keyboard(::user::primitive * pprimitive) override;

      virtual void edit_on_set_focus(::user::interaction* pinteraction) ;

      virtual bool is_text_composition_active() ;

      virtual void set_input_content_rect(const int_rectangle& rectangle);
      virtual void set_input_selection_rect(const int_rectangle& rectangle);

      virtual int_rectangle get_input_content_rect();
      virtual int_rectangle get_input_selection_rect();


      //void _create_window(::enum_parallelization eparrallelization) override;
      void _create_window() override;

      void user_post(const ::procedure & procedure) override;


   };


} // namespace aura_universal_windows



