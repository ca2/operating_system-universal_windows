#include "installer_install.h"



LRESULT CALLBACK installer_install_window_proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

ATOM installer_install_register_window_class(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			   = 0;
	wcex.lpfnWndProc	   = installer_install_window_proc;
	wcex.cbClsExtra	   = 0;
	wcex.cbWndExtra	   = 0;
	wcex.hInstance		   = hInstance;
	wcex.hCursor		   = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
   wcex.lpszMenuName	   = NULL;
	wcex.lpszClassName	= "TeDigoS�";
	//wcex.hIcon			   = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_STORE_CA2_SPA));
	//wcex.hIconSm		   = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
	wcex.hIcon			   = NULL;
	wcex.hIconSm		   = NULL;

	return RegisterClassEx(&wcex);
}


LRESULT CALLBACK installer_install_window_proc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
   case WM_COPYDATA:
      {
         COPYDATASTRUCT * pcds = (COPYDATASTRUCT *) lParam;
         if(pcds->dwData == 15111984)
         {
            char * psz = (char *) malloc(pcds->cbData + 1);
            memcpy_dup(psz, pcds->lpData, pcds->cbData);
            psz[pcds->cbData] = '\0';
            installer_install_command(hWnd, psz);
         }
      }
      break;
   default:
      return DefWindowProc(hWnd, message, wParam, lParam);
   }
	return 0;
}


