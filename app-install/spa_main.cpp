#include "installer_install.h"

HWND g_hwndMessage = NULL;
MSG g_msg;

extern "C" int WinMainCRTStartup()
{
   
   initialize_heap();

   initialize_http_dup();

   LPSTR lpsz = ::GetCommandLineA();

   int iRet = 0;

   if(!installer_install_register_window_class(::GetModuleHandle(NULL)))
      return -1;

   g_hwndMessage = ::CreateWindowExA(0, "ca2InstallerWindowClass", "ca2::fontopus::installer_install:callback_window", 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);

   DWORD dw = GetLastError();
   if(g_hwndMessage == NULL)
      return -1;


	while(PeekMessage(&g_msg, NULL, 0, 0xffffffffu, PM_REMOVE))
	{
		TranslateMessage(&g_msg);
		DispatchMessage(&g_msg);
	}

   finalize_heap();

   return iRet;

}



void installer_install_command(HWND hwnd, const ::scoped_string & scopedstr)
{
   if(stricmp_dup(psz, "install_installer") == 0)
   {
      install_installer();
   }
   else if(stricmp_dup(psz, "install_npca2plugin") == 0)
   {
      install_npca2plugin();
   }
   else if(stristr_dup(psz, "install=") == psz)
   {
      install_npca2plugin();
   }
   else if(stristr_dup(psz, "quit"))
   {
      PostMessage(hwnd, WM_QUIT, 0, 0);
   }
   free((void *) psz);
}
