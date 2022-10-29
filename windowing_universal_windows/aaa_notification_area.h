#pragma once


namespace windowing_win32
{


   struct CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS TRAYDATA
   {

      HWND           hwnd;
      UINT           uID;
      UINT           uCallbackMessage;
      UINT           Reserved[2];
      HICON          hIcon;


   };


   struct CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS TrayItemInfo :
      virtual public object
   {

      HWND           m_hwnd;
      ::u32          m_uID;
      ::u32          m_uCallbackMessage;
      string         m_strTip;
      string         m_strProcessPath;
      bool           m_bVisible;


   };


   CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS char GetDriveLetter(const ::string & pDevicePath);

   CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS HWND find_tray_toolbar_window();


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS notification_area :
      virtual public ::object
   {
   public:


      HWND                             m_hwndTray;
      ::pointer<::image_list>         m_pil16;
      
      pointer_array < TrayItemInfo >    m_infoa;
      HFONT                            m_hfontHidden;
      HFONT                            m_hfontRegular;


      notification_area();
      virtual ~notification_area();

      virtual void Initialize(::particle * pparticle);

      void ListTrayIcons(i32 defindex = 0);
      void EditCopy(i32 iItem);
      void DoubleClick(i32 iItem);
      void RightClick(i32 iItem);
      void LeftClick(i32 iItem);
      void MoveLeft(i32 iItem);
      void MoveRight(i32 iItem);
      void Refresh();
      void PostMessageToTrayIcon(i32 iItem, LPARAM lParam);


   };


} // namespace windowing_win32



