#include "framework.h"


int installer_start();


HWND g_hwndMessage = NULL;
stra_dup * g_pstraRestartCommandLine;
MSG g_msgSentinel;
HANDLE g_hmutexInstallerInstall;

ATOM sentinel_RegisterClass(HINSTANCE hInstance);

LRESULT CALLBACK sentinel_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


extern "C" int WinMainCRTStartup()
{

   initialize_primitive_heap();

   if(!os_initialize())
      return -1;

   if(!main_initialize())
      return -1;

   
   g_hmutexInstallerInstall = ::CreateMutex(NULL, false, "Local\\ca2::fontopus::ca2_installer_install_sentinel::7807e510-5579-11dd-ae16-0800200c7784");
   if(::GetLastError() == ERROR_ALREADY_EXISTS)
   {
      return false;
   }

   g_pstraRestartCommandLine = NULL;;

   if(!sentinel_RegisterClass(::GetModuleHandleA(NULL)))
      return -1;


   g_hwndMessage = ::CreateWindowExA(0, "ca2::fontopus::installer:callback_window", "ca2::fontopus::installer:callback_window", 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);

   if(g_hwndMessage == NULL)
   {
      DWORD dw = GetLastError();
      return -1;
   }


   int iRet = installer_start();


   SetTimer(g_hwndMessage, 1245, 5000 * 8, NULL);


	while(true)
	{
      GetMessage(&g_msgSentinel, NULL, 0, 0xffffffffu);
		TranslateMessage(&g_msgSentinel);
		DispatchMessage(&g_msgSentinel);
	}

   main_finalize();

   os_finalize();

   finalize_primitive_heap();


   return iRet;

}





ATOM sentinel_RegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			   = 0;
	wcex.lpfnWndProc	   = sentinel_WndProc;
	wcex.cbClsExtra	   = 0;
	wcex.cbWndExtra	   = 0;
	wcex.hInstance		   = hInstance;
	wcex.hIcon			   = NULL;
	wcex.hCursor		   = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
   wcex.lpszMenuName	   = NULL;
	wcex.lpszClassName	= "ca2::fontopus::installer:callback_window";
	wcex.hIconSm		   = NULL;

	return RegisterClassEx(&wcex);
}


LRESULT CALLBACK sentinel_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
   case WM_COPYDATA:
      {
         COPYDATASTRUCT * pcds = (COPYDATASTRUCT *) lParam;
         if(pcds->dwData == 15111984)
         {
            g_pstraRestartCommandLine = ___new stra_dup;
            char * str = (char *) ca2_alloc(pcds->cbData + 1);
            strncpy_dup(str, (const ::string &) pcds->lpData, pcds->cbData);
            str[pcds->cbData] = '\0';
            g_pstraRestartCommandLine->decode_v16(str);
            ca2_free(str);
         }
      }
      break;
   case WM_TIMER:
      {
         if(wParam == 1245)
         {
            KillTimer(g_hwndMessage, 12);
            spa::installer::spa();
            SetTimer(g_hwndMessage, 1245, (5000) * 8, NULL);
         }
      }
      break;
   default:
      return DefWindowProc(hWnd, message, wParam, lParam);
   }
	return 0;
}






vsstring calc_id();


int installer(const ::string & param);
int APIENTRY ca2_cube_install(const ::scoped_string & scopedstrId);

int installer_start()
{

   vsstring atom = calc_id();
   if(atom == NULL || atom.is_empty())
      atom = "installer_install";

   int iRetry = 0;

   int iRetryLimit;

   bool bBackground;

   if(!stricmp_dup(atom, "installer_install"))
   {
      iRetryLimit = 5;
      bBackground = true;
   }
   else
   {
      iRetryLimit = -1;
      bBackground = false;
   }

   while(iRetry < iRetryLimit || iRetryLimit < 0)
   {
      update_ca2_installed(true);
      if(is_ca2_installed() && is_installed("application", atom))
      {  
         break;
      }
      vsstring strCommandLine;

      strCommandLine = ": app=session session_start=" + atom + " app_type=application install";

      ca2_cube_install(strCommandLine, bBackground);
      iRetry++;
   }

   if(!is_ca2_installed() || !is_installed("application", atom))
   {  
      return 1;
   }

   if(stricmp_dup(atom, "installer_install"))
   {
      cube_run(atom);
   }

   return 0;

}



vsstring calc_id()
{

   char szModulePath[MAX_PATH * 3];
   ::GetModuleFileNameA((HINSTANCE) NULL, szModulePath, sizeof(szModulePath));
   vsstring strId = read_resource_as_string_dup(::GetModuleHandleA(szModulePath), 2000, "SPA");
   if(strId == "mplite") // use veriwell_mplite
      strId = "bergedge";
   return strId;

}


