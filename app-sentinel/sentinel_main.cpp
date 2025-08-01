#include "sentinel.h"

int installer_start();
int initialize_installer();

HWND g_hwndMessage = NULL;
stra_dup * g_pstraRestartCommandLine;
MSG g_msg;

ATOM sentinel_RegisterClass(HINSTANCE hInstance);

LRESULT CALLBACK sentinel_WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


extern "C" int WinMainCRTStartup()
{
   
   initialize_primitive_heap();

   if(initialize_installer() < 0)
   {
      MessageBox(NULL, "Failed to initialize app-sentinel.exe", "ca2", MB_ICONERROR);
      return -1;
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

	while(true)
	{
      GetMessage(&g_msg, NULL, 0, 0xffffffffu);
		TranslateMessage(&g_msg);
		DispatchMessage(&g_msg);
	}


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
   default:
      return DefWindowProc(hWnd, message, wParam, lParam);
   }
	return 0;
}






const_char_pointer calc_id();


int installer(const ::scoped_string & scopedstraram);
int APIENTRY ca2_cube_install(const ::scoped_string & scopedstrId);

int installer_start()
{

   const_char_pointer atom = calc_id();
   if(atom == NULL)
      atom = "installer_install";

   int iRetry = 0;

   while(iRetry < 5)
   {
      update_ca2_installed();
      if(is_ca2_installed() && is_installed(atom))
      {  
         break;
      }
      ca2_cube_install(atom);
      iRetry++;
   }

   if(!is_ca2_installed() || !is_installed(atom))
   {  
      return 1;
   }

   if(stricmp_dup(atom, "installer_install"))
   {
      cube_run(atom);
   }

   return 0;

}



const_char_pointer calc_id()
{

   char szModulePath[MAX_PATH * 3];
   ::GetModuleFileNameA((HINSTANCE) NULL, szModulePath, sizeof(szModulePath));
   return read_resource_as_string_dup(::GetModuleHandleA(szModulePath), 2000, "SPA");

}


