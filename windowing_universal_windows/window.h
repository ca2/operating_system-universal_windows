// created by Camilo 2021-01-31 04:56 BRT <3CamiloSasukeThomasBorregaardSoerensen
#pragma once


namespace windowing_universal_windows
{


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS window :
      virtual public ::windowing::window
   {
   public:


      class framework_view :
         public winrt::implements< framework_view, ::winrt::Windows::ApplicationModel::Core::IFrameworkView>
      {
      public:

         
         window *          m_pwindow;


         framework_view(window * pwindow);


         void Initialize(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView);
         void SetWindow(::winrt::Windows::UI::Core::CoreWindow const & window);
         virtual void Load(winrt::param::hstring entryPoint);
         virtual void Run();
         virtual void Uninitialize();



      };

      struct framework_view_source :
         public winrt::implements < framework_view_source, ::winrt::Windows::ApplicationModel::Core::IFrameworkViewSource >
      {


         window * m_pwindow;

         framework_view_source(window * pwindow);

         ::winrt::Windows::ApplicationModel::Core::IFrameworkView CreateView();


      };


      //__pointer(window)             m_pwindowNode;
      framework_view_source         m_frameworkviewsource;


      framework_view        m_frameworkview;


      int   m_iMouse;
      //__pointer(class ::windowing_universal_windows::buffer)   m_pBdbuffer;


      //comptr < ::windowing_universal_windows::application > 
      ::winrt::Windows::ApplicationModel::Core::CoreApplicationView     m_coreapplicationview = nullptr;
      ::winrt::Windows::UI::ViewManagement::ApplicationView             m_applicationview = nullptr;
      ::winrt::Windows::UI::Core::CoreWindow                            m_window = nullptr;


      //HICON                                     m_hiconSmall;
      //HICON                                     m_hiconBig;
      bool                                      m_bTrackMouseLeave : 1;
      //WNDPROC                                   m_pfnSuper;
      //UINT                                    m_uiMessage;
      //WPARAM                                  m_wparam;
      //LPARAM                                  m_lparam;
      //__pointer(::universal_windows::interaction_impl)    m_pimpl2;
      ::millis                                  m_millisLastMouseMove;
      ::point_i32                               m_pointMouseMove;
      
      bool                                                     m_bTextCompositionActive;
      //widestring                                             m_strText;
      widestring                                               m_strNewText;
      //::aura::system * m_psystem;

      ::winrt::Windows::UI::Core::CoreWindowResizeManager      m_resizemanager = nullptr;


      //::winrt::Windows::UI::Core::CoreWindow                   m_window = nullptr;

      // The _editContext lets us communicate with the input system.
      ::winrt::Windows::UI::Text::Core::CoreTextEditContext   m_editcontext = nullptr;

      // We will use a plain text string to represent the
      // content of the custom text edit control.
      //String^ _text;

      // If the _selection starts and ends at the same point,
      // then it represents the location of the caret (insertion point_i32).
      ::winrt::Windows::UI::Text::Core::CoreTextRange          m_selection;

      // _internalFocus keeps track of whether our control acts like it has focus.
      bool                                                     m_bInternalFocus;

      // If there is a nonempty selection, then _extendingLeft is true if the user
      // is using shift+arrow to adjust the starting point_i32 of the selection,
      // or false if the user is adjusting the ending point_i32 of the selection.
      bool                                                     m_bExtendingLeft;

      // The input pane object indicates the visibility of the on screen keyboard.
      // Apps can also ask the keyboard to show or hide.
      ::winrt::Windows::UI::ViewManagement::InputPane          m_inputpane = nullptr;


      ::winrt::event_token                                     m_tokenActivated;
      ::winrt::event_token                                     m_tokenClosed;
      ::winrt::event_token                                     m_tokenKeyDown;
      ::winrt::event_token                                     m_tokenPointerPressed;

      ::winrt::Windows::Foundation::Point                      m_pointLastCursor;

      ::u32                                                    m_dwMouseMoveThrottle;

      //millis                                                   m_millisLastMouseMove;

      string                                                   m_strId;

      //impact *                                               m_pimpact;

      bool                                                     m_bFontopusShift;

      ::mutex                                                  m_mutex;

      //__pointer(directx_interaction)                           m_pdxi;

      bool                                                     m_bLeftButton;

      bool                                                     m_bMiddleButton;

      bool                                                     m_bRightButton;

      ::winrt::Windows::Foundation::Rect                       m_rectLastWindowRect;
      ::winrt::Windows::Foundation::Rect                       m_rectInputContentRect;
      ::winrt::Windows::Foundation::Rect                       m_rectInputSelectionRect;



      window();
      ~window() override;
      

      ::e_status on_initialize_object() override;


      void main_branch(const ::routine & routine);


      // IFrameworkView Methods
      // void Initialize(::winrt::Windows::ApplicationModel::Core::CoreApplicationView const & applicationView);
      //void SetWindow(::winrt::Windows::UI::Core::CoreWindow window);
      //      virtual void Load(::winrt::param::hstring entryPoint) override = 0;
        //    virtual void Run() override = 0;
          //  virtual void Uninitialize() override = 0;
            //void Uninitialize();

      virtual ::winrt::Windows::Foundation::Rect get_window_rect();
      virtual ::winrt::Windows::Foundation::Point get_cursor_position();
      ::point_i32 get_mouse_cursor_position() override;


      virtual ::winrt::Windows::Foundation::Rect get_input_content_rect();
      virtual ::winrt::Windows::Foundation::Rect get_input_selection_rect();


      virtual widestring get_input_text();
      virtual bool set_input_text(const widestring & wstr);



      //impact();


      //inline ::user::interaction* host() { return Sess(m_psystem->get_session())->host(); }
      //inline ::user::interaction * host() { return m_puserinteraction->get_host_window(); }
      //inline ::user::interaction * host() { return m_puserinteraction; }


      void CoreWindow_PointerPressed(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::PointerEventArgs args);

      void SetInternalFocus();

      void RemoveInternalFocus();

      void RemoveInternalFocusWorker();

      void EditContext_FocusRemoved(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::Foundation::IInspectable);

      //void Element_Unloaded(Object sender, ::winrt::Windows::UI::Xaml::RoutedEventArgs e);

      // Replace the text in the specified range.
      void ReplaceText(::winrt::Windows::UI::Text::Core::CoreTextRange modifiedRange, const ::wstring & text);
      void SetText(const ::wstring & wstrText, int iBeg, int iEnd);
      bool HasSelection();

      // Change the selection without notifying CoreTextEditContext of the new selection.
      void SetSelection(::winrt::Windows::UI::Text::Core::CoreTextRange selection);
      // Change the selection and notify CoreTextEditContext of the new selection.
      void SetSelectionAndNotify(::winrt::Windows::UI::Text::Core::CoreTextRange selection);

      // Return the specified range of text. Note that the system may ask for more text
      // than exists in the text buffer.
      void EditContext_TextRequested(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextTextRequestedEventArgs args);

      // Return the current selection.
      void EditContext_SelectionRequested(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextSelectionRequestedEventArgs args);

      void EditContext_TextUpdating(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextTextUpdatingEventArgs args);

      void EditContext_SelectionUpdating(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextSelectionUpdatingEventArgs args);


      void EditContext_FormatUpdating(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextFormatUpdatingEventArgs args);



      void EditContext_LayoutRequested(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextLayoutRequestedEventArgs args);

      // This indicates that an IME has started composition.  If there is no handler for this event,
         // then composition will not start.
      void EditContext_CompositionStarted(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextCompositionStartedEventArgs args);
      void EditContext_CompositionCompleted(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::UI::Text::Core::CoreTextCompositionCompletedEventArgs args);


      void EditContext_NotifyFocusLeaveCompleted(::winrt::Windows::UI::Text::Core::CoreTextEditContext sender, ::winrt::Windows::Foundation::IInspectable);


      // Revoke with event_token
      void CoreWindow_WindowActivated(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::WindowActivatedEventArgs args);
      void CoreWindow_CoreWindowClosed(::winrt::Windows::UI::Core::CoreWindow  sender, ::winrt::Windows::UI::Core::CoreWindowEventArgs args);


      void CoreWindow_KeyDown(::winrt::Windows::UI::Core::CoreWindow sender, ::winrt::Windows::UI::Core::KeyEventArgs args);
      // Adjust the active endpoint of the selection in the specified direction.
      void AdjustSelectionEndpoint(int direction);

      // Helper function to put a zero-width non-breaking space at the end of a string.
      // This prevents TextBlock from trimming trailing spaces.
      static string PreserveTrailingSpaces(const ::string & str);

      void UpdateFocusUI();

      void UpdateTextUI();





      virtual void assert_valid() const override;
      virtual void dump(dump_context & dumpcontext) const override;


      virtual void install_message_routing(channel * pchannel) override;
      //Windows::ApplicationModel::Core::CoreApplication::Run(App());


      //application();


      //virtual ::e_status initialize_application(::aura::system * psystem, const ::string & strId);


      // void install_directx_application_message_routing();

      //void initialize_directx_application();

      //virtual widestring get_input_text();
      //virtual bool set_input_text(const widestring & wstr);


      //::aura::system * get_context_system() const;




      // IFrameworkView Methods


      //virtual ::winrt::Windows::Foundation::Rect get_window_rect() override;
      //virtual ::winrt::Windows::Foundation::Point get_cursor_position() override;

      //virtual ::winrt::Windows::Foundation::Rect get_input_content_rect() override;
      //virtual ::winrt::Windows::Foundation::Rect get_input_selection_rect() override;


      //~application() override;




      // Event Handlers
      void OnWindowSizeChanged(
         _In_::winrt::Windows::UI::Core::CoreWindow sender,
         _In_::winrt::Windows::UI::Core::WindowSizeChangedEventArgs args
      );

      void on_window_size_changed(::winrt::Windows::UI::Core::CoreWindow  sender, const ::size_i32 & size);

      void DpiChanged(::winrt::Windows::Graphics::Display::DisplayInformation  sender, ::winrt::Windows::Foundation::IInspectable);

      void DisplayContentsInvalidated(::winrt::Windows::Graphics::Display::DisplayInformation  sender, ::winrt::Windows::Foundation::IInspectable);

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

      void OnCharacterReceived(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::CharacterReceivedEventArgs args);
      void OnKeyDown(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args);
      void OnKeyUp(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::KeyEventArgs args);
      void OnPointerPressed(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);
      void OnPointerReleased(::winrt::Windows::UI::Core::CoreWindow, ::winrt::Windows::UI::Core::PointerEventArgs args);


      //comptr<ID2D1SolidColorBrush>                    m_blackBrush;
      //comptr<IDWriteTextFormat>                       m_textFormat;
      //comptr<IDWriteTypography>                       m_textTypography;
      //comptr<IDWriteTextLayout>                       m_textLayout;
      //SampleOverlay           



      
      virtual ::e_status create_window(::user::interaction_impl * pimpl) override;


      //inline HWND get_hwnd() const { return (HWND) get_oswindow(); }
      //inline void set_hwnd(HWND hwnd) { set_oswindow(__oswindow(hwnd)); }
      bool get_rect_normal(RECTANGLE_I32 * prectangle) override;

      bool operator== (const window & window) const
      {
         return get_oswindow() == window.get_oswindow();
      }

      bool operator!= (const window & window) const
      {
         return !operator==(window);
      }

      class windowing * windowing() const { return m_pwindowing.cast < ::windowing_universal_windows::windowing > (); }

      //virtual void set_oswindow(oswindow oswindow) override;

      DECLARE_MESSAGE_HANDLER(_001OnMessage);

      virtual bool has_capture() const;
      virtual bool has_focus() const;

      //void send_client_event(Atom atom, unsigned int numArgs, ...);
      //i32 store_name(const ::string & psz);
      //i32 select_input(i32 iInput);
      //i32 select_all_input();
      
      //virtual i32 map_window();
      
      //virtual i32 unmap_window(bool bWithdraw) override;

      //virtual void set_wm_class(const ::string & psz) override;

      virtual ::e_status exit_iconify() override;

      virtual ::e_status full_screen(const::rectangle_i32 & rectangle = nullptr) override;

      virtual ::e_status exit_full_screen() override;

      virtual ::e_status exit_zoomed() override;

      virtual ::e_status set_keyboard_focus() override;

      virtual ::e_status set_active_window() override;

      ::e_status bring_to_front() override;

      virtual ::e_status set_foreground_window() override;

      virtual ::e_status set_mouse_capture() override;



      virtual bool has_mouse_capture() const;
      virtual bool has_keyboard_focus() const;


      virtual bool is_active_window() const override;




      virtual ::e_status destroy_window() override;

      virtual ::e_status show_window(const ::e_display & edisplay, const ::e_activation & eactivation) override;

      //virtual void set_user_interaction(::layered * pinteraction) override;

      virtual void post_non_client_destroy() override;

      virtual ::e_status set_mouse_cursor(::windowing::cursor * pcursor) override;

//      virtual bool is_child_of(const ::windowing::window * pwindowAscendantCandidate) const override;
      
      //virtual long get_state() override;

      virtual bool is_iconic() override;

      virtual bool is_window() override;

      virtual bool is_window_visible() override;

      //bool :window_is_iconic()

      //virtual ::e_status show_window(const::e_display & edisplay, const::e_activation & eactivation) override;
      
      virtual bool client_to_screen(POINT_I32 * ppoint) override;

      virtual bool screen_to_client(POINT_I32 * ppoint) override;

      virtual bool on_set_window_position(const class ::zorder& zorder, i32 x, i32 y, i32 cx, i32 cy, ::u32 nFlags) override;

      virtual bool set_window_position(const class ::zorder & zorder, i32 x, i32 y, i32 cx, i32 cy, ::u32 nFlags) override;

      //virtual bool _set_window_pos(class::zorder zorder, i32 x, i32 y, i32 cx, i32 cy, ::u32 nFlags) override;

      virtual bool is_destroying() override;

      //virtual bool bamf_set_icon() override;

      //virtual bool set_icon(::image * pimage) override;

      //int x_change_property(Atom property, Atom type, int format, int mode, const unsigned char * data, int nelements);

      //virtual int_bool set_mouse_cursor(oswindow window, hcursor hcursor);



      //virtual bool __windows_message_bypass(HWND oswindow, ::u32 message, wparam wparam, lparam lparam, lresult & lresult);

      //virtual void install_message_routing(::channel * pchannel);

      //bool operator==(const interaction_impl & wnd) const;
      //bool operator!=(const interaction_impl & wnd) const;

      //virtual iptr _get_style() const;
      //virtual iptr _get_ex_style() const;
      //virtual bool _set_style(iptr iStyle);
      //virtual bool _set_ex_style(iptr iExStyle);
      //virtual bool _modify_style(iptr dwRemove, iptr dwAdd, ::u32 nFlags = 0);
      //virtual bool _modify_ex_style(iptr dwRemove, iptr dwAdd, ::u32 nFlags = 0);
      //virtual iptr _get_window_long_ptr(::i32 iIndex) const;
      //virtual bool _set_window_long_ptr(::i32 iIndex, ::iptr iLong);

      //virtual ::user::interaction * get_owner();
      //virtual void set_owner(::user::interaction * pOwnerWnd);

      // void route_command(::message::command * pcommand, bool bRouteToKeyDescendant = false) override;

      //void _002OnDraw(::image * pimage);

      //virtual void present();

      //virtual void defer_start_prodevian();

      virtual ::e_status set_icon(::windowing::icon * pwindow) override;

      virtual void on_visual_applied() override;




      //virtual void window_apply_visual(const ::user::window_state & windowstate) override;

      DECLARE_MESSAGE_HANDLER(on_message_destroy);
      DECLARE_MESSAGE_HANDLER(on_message_create);
      //DECLARE_MESSAGE_HANDLER(_001OnKillFocus);
      DECLARE_MESSAGE_HANDLER(_001OnPaint);
      DECLARE_MESSAGE_HANDLER(_001OnPrint);
      //DECLARE_MESSAGE_HANDLER(_001OnSetFocus);
      DECLARE_MESSAGE_HANDLER(on_message_non_client_calculate_size);
      ////DECLARE_MESSAGE_HANDLER(on_message_set_cursor);
      DECLARE_MESSAGE_HANDLER(_001OnEraseBkgnd);
      //DECLARE_MESSAGE_HANDLER(on_message_move);
      DECLARE_MESSAGE_HANDLER(on_message_size);
      //DECLARE_MESSAGE_HANDLER(on_message_show_window);
      DECLARE_MESSAGE_HANDLER(_001OnActivate);
      DECLARE_MESSAGE_HANDLER(_001OnDwmNcRenderingChanged);
      DECLARE_MESSAGE_HANDLER(_001OnProdevianSynch);
      DECLARE_MESSAGE_HANDLER(_001OnWindowPosChanging);
      DECLARE_MESSAGE_HANDLER(_001OnWindowPosChanged);
      //DECLARE_MESSAGE_HANDLER(_001OnGetMinMaxInfo);
      DECLARE_MESSAGE_HANDLER(_001OnEnable);
      DECLARE_MESSAGE_HANDLER(on_message_get_icon);


      //virtual void win_update_graphics();

//#if(WINVER >= 0x0500)
//
//      bool GetWindowInfo(PWINDOWINFO pwi) const;
//      bool GetTitleBarInfo(PTITLEBARINFO pti) const;
//
//#endif   // WINVER >= 0x0500

      //      virtual ::user::interaction * from_os_data(void * pdata);
      //virtual void * get_os_data() const;


      virtual ::e_status set_finish() override;


      //      virtual ::user::interaction * from_handle(HWND hwnd);

      // subclassing/unsubclassing functions
      //virtual void pre_subclass_window();
      //bool subclass_window(HWND hwnd);
      //bool SubclassDlgItem(::u32 nID, ::user::interaction_impl * pParent);
      //oswindow unsubclass_window();

      // handling of RT_DLGINIT resource (extension to RT_DIALOG)
      //bool ExecuteDlgInit(const ::string & pszResourceName);

      //bool ExecuteDlgInit(LPVOID pResource);


      // for child windows, views, panes etc
      //virtual bool create_interaction(::user::interaction * pinteraction, const ::string & pszClassName, const ::string & pszWindowName,u32 dwStyle,const ::rectangle_i32 & rectangle,::user::interaction * pParentWnd,id id, ::create * pcreate = nullptr) override;


      // advanced creation (allows access to extended styles)
      //virtual bool create_window_ex(::user::interaction * pinteraction, __pointer(::user::system) pusersystem, ::user::interaction * puiParent, id id) override;

      //virtual ::e_status native_create_host() override;



      //virtual bool destroy_impl_only() override;
      //virtual bool DestroyWindow() override;

      //virtual bool pre_create_window(::user::system * pusersystem);

      // Advanced: virtual AdjustWindowRect
      //enum AdjustType { adjustBorder = 0, adjustOutside = 1 };
      //virtual void CalcWindowRect(RECTANGLE_I32 * pClientRect, ::u32 nAdjustType = adjustBorder);


      void get_child_by_id(id id, oswindow * poswindow_) const;

      //virtual bool _is_window() const override;

      //#if(WINVER >= 0x0500)
      //
      //      ::user::interaction_impl * GetAncestor(::u32 gaFlags) const;
      //
      //#endif   // WINVER >= 0x0500

      virtual lresult send_message(const ::id & id, wparam wParam = 0, lparam lParam = nullptr) override;

      virtual bool post_message(const ::id & id, wparam wParam = 0, lparam lParam = nullptr) override;


      //bool SendNotifyMessage(::u32 message, wparam wParam, lparam lParam);

      //bool SendChildNotifyLastMsg(lresult* pResult = nullptr);

      //bool DragDetect(const ::point_i32 & point) const;



      // Window Text Functions
      virtual void set_window_text(const ::string & pszString) override;

      virtual strsize get_window_text(char * pszStringBuf, strsize nMaxCount) override;

      virtual void get_window_text(string & rectString) override;
      virtual strsize get_window_text_length() override;

      //virtual void on_layout(::draw2d::graphics_pointer & pgraphics) override;
      //virtual void on_reposition() override;
      //virtual void on_show_window() override;
      //virtual void on_zorder() override;

      //virtual void clear_need_layout() override;
      //virtual void clear_need_translation() override;
      //virtual void clear_show_flags() override;
      //virtual void clear_need_zorder() override;


      //virtual bool set_window_position(iptr z, i32 x, i32 y, i32 cx, i32 cy, ::u32 nFlags = SWP_SHOWWINDOW);


      // Window size_i32 and position Functions
      //virtual bool window_is_iconic() override;
      //virtual bool window_is_zoomed() override;
      //i32 SetWindowRgn(HRGN hRgn,bool bRedraw);
      //i32 GetWindowRgn(HRGN hRgn);

      virtual ::u32 ArrangeIconicWindows();
      //virtual void BringToTop(::e_display edisplay);
      //virtual bool BringWindowToTop();
      //using ::user::interaction_impl::get_window_rect;
      //virtual bool get_window_rect(RECTANGLE_I64 * prectangle);

      //using ::user::interaction_impl::get_client_rect;
      //virtual bool get_client_rect(RECTANGLE_I64 * prectangle);


      //virtual void rects_from_os();
      virtual bool get_window_rect(RECTANGLE_I32 * prectangle);
      virtual bool get_client_rect(RECTANGLE_I32 * prectangle);



      //virtual point_f64 client_screen_top_left() override;


      //virtual bool GetWindowPlacement(WINDOWPLACEMENT * puserinteractionpl);

      //virtual bool SetWindowPlacement(const WINDOWPLACEMENT * puserinteractionpl);


      //virtual void MapWindowPoints(::user::interaction_impl * puserinteractionTo, POINT_I32 * pPoint, ::u32 nCount);

      //virtual void MapWindowPoints(::user::interaction_impl * puserinteractionTo, RECTANGLE_I32 * prectangle);


      //virtual void Print(::draw2d::graphics_pointer & pgraphics, u32 dwFlags) const;
      //virtual void PrintClient(::draw2d::graphics_pointer & pgraphics, u32 dwFlags) const;

      virtual void on_redraw_window(::u32 flags) override;

      virtual void show_task(bool bShowTask) override;

      virtual void UpdateWindow();
      virtual void SetRedraw(bool bRedraw = true);
      virtual bool GetUpdateRect(RECTANGLE_I32 * prectangle, bool bErase = false);

      virtual i32 GetUpdateRgn(::draw2d::region * pRgn, bool bErase = false);
      virtual void Invalidate(bool bErase = true);
      virtual void InvalidateRect(const RECTANGLE_I32 * rectangle, bool bErase = true);

      virtual void InvalidateRgn(::draw2d::region * pRgn, bool bErase = true);
      virtual void ValidateRect(const RECTANGLE_I32 * rectangle_i32);

      virtual void ValidateRgn(::draw2d::region * pRgn);
      //virtual bool display(::e_display edisplay);


      //virtual void sketch_prepare_window_minimize(::e_activation eactivation) override;
      //virtual void sketch_prepare_window_maximize() override;
      //virtual void sketch_prepare_window_full_screen(const ::rectangle_i32 & rectHint = nullptr) override;
      //virtual void sketch_prepare_window_restore(edisplay edisplay) override;


      //virtual bool _is_window_visible() override;
      virtual void ShowOwnedPopups(bool bShow = true);

      virtual __pointer(::draw2d::graphics) GetDCEx(::draw2d::region * prgnClip, u32 flags);
      virtual bool LockWindowUpdate();
      virtual void UnlockWindowUpdate();

      virtual bool RedrawWindow(const ::rectangle_i32 & rectUpdate = nullptr,
         ::draw2d::region * prgnUpdate = nullptr,
         ::u32 flags = RDW_INVALIDATE | RDW_ERASE);

      ///virtual bool EnableScrollBar(i32 nSBFlags, ::u32 nArrowFlags = ESB_ENABLE_BOTH);

      //virtual bool DrawAnimatedRects(i32 idAni, const LPRECTprcFrom, const LPRECTlprcTo);

      virtual bool DrawCaption(::draw2d::graphics_pointer & pgraphics, const rectangle_i32 & prc, ::u32 uFlags);


      //#if(WINVER >= 0x0500)
      //
      //      virtual bool AnimateWindow(millis millis, u32 dwFlags);
      //
      //#endif   // WINVER >= 0x0500
      //
      //#if(_WIN32_WINNT >= 0x0501)
      //
      //      virtual bool PrintWindow(::draw2d::graphics_pointer & pgraphics, ::u32 nFlags) const;
      //
      //#endif   // _WIN32_WINNT >= 0x0501
      //
            // Layered Window

      //#if(_WIN32_WINNT >= 0x0500)
      //
      //      virtual bool SetLayeredWindowAttributes(::color::color crKey, byte bAlpha, u32 dwFlags);
      //      virtual bool UpdateLayeredWindow(::draw2d::graphics * pDCDst, POINT_I32 *pptDst, SIZE_I32 *psize,
      //                                       ::draw2d::graphics * pDCSrc, POINT_I32 *pptSrc, ::color::color crKey, BLENDFUNCTION *pblend, u32 dwFlags);
      //
      //#endif   // _WIN32_WINNT >= 0x0500

      //#if(_WIN32_WINNT >= 0x0501)
      //
      //      virtual bool GetLayeredWindowAttributes(::color::color *pcrKey, byte *pbAlpha, u32 *pdwFlags) const;
      //
      //#endif   // _WIN32_WINNT >= 0x0501


            // timer Functions
      //      virtual bool SetTimer(uptr uEvent, ::u32 nElapse, PFN_TIMER pfnTimer);
            //    virtual bool KillTimer(uptr uEvent);

            // Window State Functions
      virtual bool is_this_enabled();
      virtual bool enable_window(bool bEnable = true);

      // the active interaction_impl applies only to top-level (frame windows)
      //virtual ::user::interaction * GetActiveWindow();
      //virtual ::user::interaction * SetActiveWindow();

      // the foreground interaction_impl applies only to top-level windows (frame windows)
      //virtual bool SetForegroundWindow();
      //virtual ::user::interaction * GetForegroundWindow();


      //virtual bool has_keyboard_focus() const override;
      

      //virtual ::user::interaction * GetFocus();

      //virtual ::user::interaction * get_desktop_window();

      // Obsolete and non-portable APIs - not recommended for new code
      virtual void CloseWindow();
      virtual bool OpenIcon();

      //// Dialog-Box Item Functions
      //// (NOTE: Dialog-Box Items/Controls are not necessarily in dialog boxes!)
      //virtual void CheckDlgButton(i32 nIDButton, ::u32 nCheck);
      //virtual void CheckRadioButton(i32 nIDFirstButton, i32 nIDLastButton, i32 nIDCheckButton);
      //virtual i32 GetCheckedRadioButton(i32 nIDFirstButton, i32 nIDLastButton);
      //virtual i32 DlgDirList(__inout_z TCHAR * pPathSpec, __in i32 nIDListBox,

      //   __in i32 nIDStaticPath, __in::u32 nFileType);
      //virtual i32 DlgDirListComboBox(__inout_z TCHAR * pPathSpec, __in i32 nIDComboBox,

      //   __in i32 nIDStaticPath, __in::u32 nFileType);
      //virtual bool DlgDirSelect(__out_ecount_z(nSize) TCHAR * pString, __in i32 nSize, __in i32 nIDListBox);

      //virtual bool DlgDirSelectComboBox(__out_ecount_z(nSize) TCHAR * pString, __in i32 nSize, __in i32 nIDComboBox);


      //virtual ::u32 GetChildByIdInt(i32 nID, BOOL * pTrans = nullptr, bool bSigned = true) const;

      //virtual i32 GetChildByIdText(__in i32 nID, __out_ecount_part_z(nMaxCount, return +1) TCHAR * pStr, __in i32 nMaxCount) const;

      ///virtual i32 GetChildByIdText(i32 nID, string & rectString) const;
      //virtual ::user::interaction * GetNextDlgGroupItem(::user::interaction * pWndCtl, bool bPrevious = false) const;
      //virtual ::user::interaction * GetNextDlgTabItem(::user::interaction * pWndCtl, bool bPrevious = false) const;
      //virtual ::u32 IsDlgButtonChecked(i32 nIDButton) const;
      //virtual lresult SendDlgItemMessage(i32 nID, ::u32 message, wparam wParam = 0, lparam lParam = 0);
      //virtual void SetDlgItemInt(i32 nID, ::u32 nValue, bool bSigned = true);
      //virtual void SetDlgItemText(i32 nID, const ::string & pszString);


      //virtual bool open_clipboard() override;
      //virtual bool close_clipboard() override;


      //// Scrolling Functions
      //virtual i32 GetScrollPos(i32 nBar) const;
      //virtual void GetScrollRange(i32 nBar, LPINT pMinPos, LPINT lpMaxPos) const;

      //virtual void ScrollWindow(i32 xAmount, i32 yAmount,
      //   const RECTANGLE_I32 * rectangle = nullptr,

      //   const RECTANGLE_I32 * pClipRect = nullptr);

      //virtual i32 SetScrollPos(i32 nBar, i32 nPos, bool bRedraw = true);
      //virtual void SetScrollRange(i32 nBar, i32 nMinPos, i32 nMaxPos,
      //   bool bRedraw = true);
      //virtual void ShowScrollBar(::u32 nBar, bool bShow = true);
      //virtual void EnableScrollBarCtrl(i32 nBar, bool bEnable = true);

      //virtual i32 ScrollWindowEx(i32 dx, i32 dy,
      //   const RECTANGLE_I32 * pRectScroll, const RECTANGLE_I32 * lpRectClip,

      //   ::draw2d::region * prgnUpdate, RECTANGLE_I32 * pRectUpdate, ::u32 flags);

      //virtual bool SetScrollInfo(i32 nBar, LPSCROLLINFO pScrollInfo,

      //   bool bRedraw = true);
      //virtual bool GetScrollInfo(i32 nBar, LPSCROLLINFO pScrollInfo, ::u32 nMask = SIF_ALL);

      //virtual i32 GetScrollLimit(i32 nBar);

      //#if(WINVER >= 0x0500)
      //
      //      virtual bool GetScrollBarInfo(::i32 idObject, PSCROLLBARINFO psbi) const;
      //
      //#endif   // WINVER >= 0x0500

            // Window Access Functions
      //virtual ::user::interaction * ChildWindowFromPoint(const ::point_i32 & point);
      //virtual ::user::interaction * ChildWindowFromPoint(const ::point_i32 & point, ::u32 nFlags);
      ///      virtual ::user::interaction_impl * FindWindow(const ::string & pszClassName, const ::string & pszWindowName);

      //   virtual ::user::interaction_impl * FindWindowEx(::windowing::window * pwindowParent,::windowing::window * pwindowChildAfter, const ::string & lpszClass, const ::string & pszWindow);

      //virtual ::point_i64 _client_parent_top_left() override;
      //virtual ::point_i64 _client_screen_top_left() override;


      virtual ::windowing::window * get_next_window(::u32 nFlag = GW_HWNDNEXT);
      virtual ::windowing::window * get_top_window() const;


      virtual ::windowing::window * get_window(::u32 nCmd) const;
      virtual ::windowing::window * get_last_active_popup() const;

      
      virtual ::windowing::window * get_parent() const override;
      virtual oswindow get_parent_oswindow() const override;
      virtual ::e_status set_parent(::windowing::window * pwindow) override;

      virtual ::windowing::window * get_owner() const override;
      virtual oswindow get_owner_oswindow() const override;
      virtual ::e_status set_owner(::windowing::window * pwindow) override;

      //virtual ::user::interaction * set_owner(::user::interaction * pWndNewParent);
      //virtual oswindow get_owner() const;

      // virtual bool FlashWindow(bool bInvert);

      //virtual void message_box(const ::string & pszText, const ::string & pszTitle = nullptr, ::u32 nType = e_message_box_ok, const function_arg & functionarg = function_arg());


//
//#if(WINVER >= 0x0500)
//
//      virtual bool FlashWindowEx(u32 dwFlags, ::u32  uCount, millis tickTimeout);
//
//#endif   // WINVER >= 0x0500
//
      // Clipboard Functions
      //virtual bool ChangeClipboardChain(::windowing::window * pwindow_Next);
      //virtual ::oswindow  SetClipboardViewer();
      ////virtual bool OpenClipboard();
      //virtual ::user::interaction * GetClipboardOwner();
      //virtual ::user::interaction * GetClipboardViewer();
      //virtual ::user::interaction * GetOpenClipboardWindow();

      virtual point_i32 GetCaretPos();
      virtual void SetCaretPos(const ::point_i32 & point);
      virtual void HideCaret();
      virtual void ShowCaret();

      // Shell Interaction Functions
      //virtual void DragAcceptFiles(bool bAccept = true);

      // icon Functions
      //virtual hicon SetIcon(hicon hIcon, bool bBigIcon);
      //virtual hicon GetIcon(bool bBigIcon) const;

      // Context Help Functions
      //virtual bool SetWindowContextHelpId(u32 dwContextHelpId);
      //virtual u32 GetWindowContextHelpId() const;

      // Dialog Data support
      //virtual bool update_data(bool bSaveAndValidate = true);
      // data wnd must be same type as this

      //// Help Command Handlers
      //void OnHelp();          // F1 (uses current action_context)
      //void OnHelpIndex();     // ID_HELP_INDEX
      //void OnHelpFinder();    // ID_HELP_FINDER, ID_DEFAULT_HELP
      //void OnHelpUsing();     // ID_HELP_USING
      //virtual void WinHelp(uptr dwData, ::u32 nCmd = HELP_CONTEXT);
      ////virtual void HtmlHelp(uptr dwData, ::u32 nCmd = 0x000F);
      //virtual void WinHelpInternal(uptr dwData, ::u32 nCmd = HELP_CONTEXT);


      // dialog support
      //void UpdateDialogControls(channel* pTarget, bool bDisableIfNoHndler);
      //void CenterWindow(::user::interaction * pAlternateOwner = nullptr);
      ////virtual id   RunModalLoop(u32 dwFlags = 0,::object * pliveobject = nullptr);
      //virtual bool ContinueModal() override;
      //virtual void EndModalLoop(id nResult) override;
      //virtual void EndAllModalLoops(id nResult);

      // Window-Management message handler member functions
      //virtual bool OnCommand(::message::message * pusermessage);
      //virtual bool OnNotify(::message::message * pusermessage);

      //void OnActivate(::u32 nState, ::user::interaction_impl * pWndOther, bool bMinimized);
      //void OnActivateApp(bool bActive, u32 dwThreadID);
      //lresult OnActivateTopLevel(wparam, lparam);
      //void OnCancelMode();
      //void OnChildActivate();
      //void OnClose();
      //void OnContextMenu(::user::interaction_impl * pwindow, point_i32 pos);
      //bool OnCopyData(::user::interaction_impl * pwindow, COPYDATASTRUCT* pCopyDataStruct);

      //HBRUSH OnCtlColor(::draw2d::graphics_pointer & pgraphics, ::user::interaction_impl * pwindow, ::u32 nCtlColor);


      //void OnEnable(bool bEnable);
      //void OnEndSession(bool bEnding);
      //void OnEnterIdle(::u32 nWhy, ::user::interaction_impl * pWho);
      //bool OnEraseBkgnd(::draw2d::graphics_pointer & pgraphics);
      //void OnGetMinMaxInfo(MINMAXINFO* pMMI);

      //bool OnHelpInfo(HELPINFO* pHelpInfo);

      //void OnIconEraseBkgnd(::draw2d::graphics_pointer & pgraphics);
      //lresult OnMenuChar(::u32 nChar, ::u32 nFlags, ::user::menu* pMenu);
      //void OnMenuSelect(::u32 nItemID, ::u32 nFlags, HMENU hSysMenu);
      //void OnMove(i32 x, i32 y);
      //void OnParentNotify(const ::id & id, lparam lParam);
      //hcursor OnQueryDragIcon();
      //bool OnQueryEndSession();
      //bool OnQueryNewPalette();
      //bool OnQueryOpen();
      //void OnShowWindow(bool bShow, ::u32 nStatus);
      //void OnSize(::u32 nType, i32 cx, i32 cy);
      //void OnTCard(::u32 idAction, u32 dwActionData);

      //void OnChangeUIState(::u32 nAction, ::u32 nUIElement);
      //void OnUpdateUIState(::u32 nAction, ::u32 nUIElement);
      //::u32 OnQueryUIState();

      //// Nonclient-Area message handler member functions
      //bool OnNcActivate(bool bActive);
      //void OnNcCalcSize(bool bCalcValidRects, NCCALCSIZE_PARAMS* pncsp);

      //bool OnNcCreate(::user::system * pCreateStruct);

      //lresult OnNcHitTest(const ::point_i32 & point);
      //void OnNcLButtonDblClk(::u32 nHitTest, const ::point_i32 & point);
      //void OnNcLButtonDown(::u32 nHitTest, const ::point_i32 & point);
      //void OnNcLButtonUp(::u32 nHitTest, const ::point_i32 & point);
      //void OnNcMButtonDblClk(::u32 nHitTest, const ::point_i32 & point);
      //void OnNcMButtonDown(::u32 nHitTest, const ::point_i32 & point);
      //void OnNcMButtonUp(::u32 nHitTest, const ::point_i32 & point);
      //void OnNcMouseMove(::u32 nHitTest, const ::point_i32 & point);
      //void OnNcPaint();
      //void OnNcRButtonDblClk(::u32 nHitTest, const ::point_i32 & point);
      //void OnNcRButtonDown(::u32 nHitTest, const ::point_i32 & point);
      //void OnNcRButtonUp(::u32 nHitTest, const ::point_i32 & point);

      //// System message handler member functions
      //void OnDropFiles(HDROP hDropInfo);
      //void OnPaletteIsChanging(::user::interaction_impl * pRealizeWnd);
      //void OnSysChar(::u32 nChar, ::u32 nRepCnt, ::u32 nFlags);
      //void OnSysCommand(::u32 nID, lparam lParam);
      //void OnSysDeadChar(::u32 nChar, ::u32 nRepCnt, ::u32 nFlags);
      //void OnSysKeyDown(::u32 nChar, ::u32 nRepCnt, ::u32 nFlags);
      //void OnSysKeyUp(::u32 nChar, ::u32 nRepCnt, ::u32 nFlags);
      //void OnCompacting(::u32 nCpuTime);
      //void OnDevModeChange(__in_z char * pDeviceName);

      //void OnFontChange();
      //void OnPaletteChanged(::user::interaction_impl * pFocusWnd);
      //void OnSpoolerStatus(::u32 nStatus, ::u32 nJobs);
      //void OnSysColorChange();
      //void OnTimeChange();
      //void OnSettingChange(::u32 uFlags, const ::string & pszSection);

      //void OnWinIniChange(const ::string & pszSection);


      //// Input message handler member functions
      //void OnChar(::u32 nChar, ::u32 nRepCnt, ::u32 nFlags);
      //void OnDeadChar(::u32 nChar, ::u32 nRepCnt, ::u32 nFlags);
      ////      void OnHScroll(::u32 nSBCode, ::u32 nPos, CScrollBar* pScrollBar);
      ////    void OnVScroll(::u32 nSBCode, ::u32 nPos, CScrollBar* pScrollBar);
      //void OnKeyDown(::u32 nChar, ::u32 nRepCnt, ::u32 nFlags);
      //void OnKeyUp(::u32 nChar, ::u32 nRepCnt, ::u32 nFlags);
      //void OnLButtonDblClk(::u32 nFlags, const ::point_i32 & point);
      //void OnLButtonDown(::u32 nFlags, const ::point_i32 & point);
      //void OnLButtonUp(::u32 nFlags, const ::point_i32 & point);
      //void OnMButtonDblClk(::u32 nFlags, const ::point_i32 & point);
      //void OnMButtonDown(::u32 nFlags, const ::point_i32 & point);
      //void OnMButtonUp(::u32 nFlags, const ::point_i32 & point);
      //i32 OnMouseActivate(::user::interaction_impl * pDesktopWnd, ::u32 nHitTest, const ::id & id);
      //void OnMouseMove(::u32 nFlags, const ::point_i32 & point);
      //bool OnMouseWheel(::u32 nFlags, i16 zDelta, const ::point_i32 & point);
      //lresult OnRegisteredMouseWheel(wparam wParam, lparam lParam);
      //void OnRButtonDblClk(::u32 nFlags, const ::point_i32 & point);
      //void OnRButtonDown(::u32 nFlags, const ::point_i32 & point);
      //void OnRButtonUp(::u32 nFlags, const ::point_i32 & point);
      //void OnTimer(uptr uEvent);

      //// Initialization message handler member functions
      //void OnInitMenu(::user::menu* pMenu);
      //void OnInitMenuPopup(::user::menu* pPopupMenu, ::u32 nIndex, bool bSysMenu);

      //// Clipboard message handler member functions
      //void OnAskCbFormatName(__in ::u32 nMaxCount, __out_ecount_z(nMaxCount) char * pszString);

      //void OnChangeCbChain(::windowing::window * pwindow_Remove, ::windowing::window * pwindow_After);
      //void OnDestroyClipboard();
      //void OnDrawClipboard();
      //void OnHScrollClipboard(::user::interaction_impl * pClipAppWnd, ::u32 nSBCode, ::u32 nPos);
      //void OnPaintClipboard(::user::interaction_impl * pClipAppWnd, HGLOBAL hPaintStruct);
      //void OnRenderAllFormats();
      //void OnRenderFormat(::u32 nFormat);
      //void OnSizeClipboard(::user::interaction_impl * pClipAppWnd, HGLOBAL hRect);
      //void OnVScrollClipboard(::user::interaction_impl * pClipAppWnd, ::u32 nSBCode, ::u32 nPos);

      //// control message handler member functions
      //i32 OnCompareItem(i32 nIDCtl, LPCOMPAREITEMSTRUCT pCompareItemStruct);

      //void OnDeleteItem(i32 nIDCtl, LPDELETEITEMSTRUCT pDeleteItemStruct);

      //void OnDrawItem(i32 nIDCtl, LPDRAWITEMSTRUCT pDrawItemStruct);

      //::u32 OnGetDlgCode();

      // MDI message handler member functions
      //void OnMDIActivate(bool bActivate,
      //                   ::user::interaction_impl * pActivateWnd, ::user::interaction_impl * pDeactivateWnd);

      // menu loop notification messages
      //void OnEnterMenuLoop(bool bIstrack_popup_menu);
      //void OnExitMenuLoop(bool bIstrack_popup_menu);

      //// Win4 messages
      //void OnStyleChanged(i32 nStyleType, LPSTYLESTRUCT pStyleStruct);

      //void OnStyleChanging(i32 nStyleType, LPSTYLESTRUCT pStyleStruct);

      //void OnSizing(::u32 nSide, RECTANGLE_I32 * prectangle);

      //void OnMoving(::u32 nSide, RECTANGLE_I32 * prectangle);

      //void OnCaptureChanged(::user::interaction_impl * pwindow);
      //bool OnDeviceChange(::u32 nEventType, uptr dwData);

      // Overridables and other helpers (for implementation of derived classes)
      // for deriving from a standard control
      ///virtual WNDPROC * GetSuperWndProcAddr();

      // for dialog data exchange and validation
      //      virtual void do_data_exchange(CDataExchange* pDX);

      // for modality
      virtual void BeginModalState();
      virtual void EndModalState();

      // for translating Windows messages in Main message pump
      //virtual void pre_translate_message(::message::message * pmessage);


      //virtual void default_message_handler(::message::message * pusermessage) override;
      //virtual void message_handler(::message::message * pusermessage);


      //virtual bool OnWndMsg(const ::id & id, wparam wParam, lparam lParam, lresult* pResult);

      // for handling default processing
      //lresult Default();
      //virtual void default_window_procedure(::message::message * pmessage) override;


      //virtual void post_non_client_destroy();

      //// for notifications from parent
      //virtual bool OnChildNotify(::message::message * pusermessage);
      //// return true if parent should not process this message
      //virtual bool ReflectChildNotify(::message::message * pusermessage);
      //virtual bool ReflectMessage(::windowing::window * pwindow_Child, ::message::message * pusermessage);

      // Implementation
      //virtual bool CheckAutoCenter();
      //virtual bool GrayCtlColor(HDC hDC, HWND hwnd, ::u32 nCtlColor,
      //                          HBRUSH hbrGray, ::color::color clrText);


      // helper routines for implementation
      //bool HandleFloatingSysCommand(::u32 nID, lparam lParam);
      //bool IsTopParentActive();
      //void ActivateTopParent();
      //virtual void on_final_release();
      ///virtual bool ModifyStyle(u32 dwRemove, u32 dwAdd, ::u32 nFlags);
      //virtual bool ModifyStyleEx(u32 dwRemove, u32 dwAdd, ::u32 nFlags);
      //virtual void _FilterToolTipMessage(MSG* pMsg,::user::interaction_impl * pwindow);
      //bool _EnableToolTips(bool bEnable, ::u32 nFlag);
      //virtual oswindow get_safe_owner(::HWND hwnd, ::oswindow * pWndTop);
      //void PrepareForHelp();


      virtual ::e_status set_tool_window(bool bSet);


      friend class frame_window;

      //bool CreateDlg(const ::string & pszTemplateName, ::user::interaction_impl * pParentWnd);



      //CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS friend lresult CALLBACK __send_message_hook(i32, wparam, lparam);
      //CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS friend lresult CALLBACK __cbt_filter_hook(i32, wparam, lparam);

      // standard message implementation
      //lresult OnNTCtlColor(wparam wParam, lparam lParam);
      //lresult OnDisplayChange(wparam, lparam);
      //lresult OnDragList(wparam, lparam);



      //virtual void _001DeferPaintLayeredWindowBackground(HDC hdc);

      //virtual ::i32 get_window_long(i32 nIndex) const;
      //virtual ::i32 set_window_long(i32 nIndex, ::i32 lValue);
      //virtual iptr get_window_long_ptr(i32 nIndex) const;
      //virtual iptr set_window_long_ptr(i32 nIndex, iptr lValue);


      virtual void _task_transparent_mouse_event() override;


      virtual void track_mouse_hover() override;

      void set_viewport_org(::draw2d::graphics_pointer & pgraphics);


      void on_set_parent(::user::interaction * pinteraction);


//      virtual bool get_rect_normal(RECTANGLE_I32 * prectangle);
      //virtual void register_drop_target();
      //virtual void show_task(bool bShow);
      virtual void window_show_change_visibility(::e_display edisplay, ::e_activation eactivation) override;


      virtual void non_top_most_upper_window_rects(::rectangle_i32_array & recta) override;


      // virtual void activate_top_parent();

      //virtual bool is_same_window(const ::windowing::window * pwindow) const override;  

      // internal to windowing library


      //virtual bool get_window_placement(WINDOWPLACEMENT * puserinteractionpl);
      //virtual bool set_window_placement(const WINDOWPLACEMENT * puserinteractionpl);


      //virtual iptr get_window_long_ptr(i32 nIndex) const override;
      //virtual bool set_window_long_ptr(i32 nIndex, iptr l) override;



      virtual void default_message_handler(::message::message * pusermessage);

      virtual float get_dpi_for_window() override;

      virtual float point_dpi(float points) override;

      virtual float y_dpi(float y) override;
      virtual float x_dpi(float x) override;

      virtual float dpiy(float y) override;
      virtual float dpix(float x) override;

      virtual void window_show() override;
      virtual void update_screen() override;

 
      

      //// IUnknown
      //virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void ** ppvObject);

      //virtual ULONG STDMETHODCALLTYPE AddRef(void);

      //virtual ULONG STDMETHODCALLTYPE Release(void);

      //// IDropTarget
      //virtual HRESULT STDMETHODCALLTYPE DragEnter(
      //   /* [unique][in] */ __RPC__in_opt IDataObject * pDataObj,
      //   /* [in] */ DWORD grfKeyState,
      //   /* [in] */ POINTL point,
      //   /* [out][in] */ __RPC__inout DWORD * pdwEffect);

      //virtual HRESULT STDMETHODCALLTYPE DragOver(
      //   /* [in] */ DWORD grfKeyState,
      //   /* [in] */ POINTL point,
      //   /* [out][in] */ __RPC__inout DWORD * pdwEffect);

      //virtual HRESULT STDMETHODCALLTYPE DragLeave(void);

      //virtual HRESULT STDMETHODCALLTYPE Drop(
      //   /* [unique][in] */ __RPC__in_opt IDataObject * pDataObj,
      //   /* [in] */ DWORD grfKeyState,
      //   /* [in] */ POINTL point,
      //   /* [out][in] */ __RPC__inout DWORD * pdwEffect);

      void graphics_lock() override;
      void graphics_unlock() override;

      
      ::e_status window_branch(const ::routine & routine) override;

      bool is_branch_current() const override;


   };


} // namespace windowing_universal_windows



