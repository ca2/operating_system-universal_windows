#pragma once



#ifndef _UWP

typedef struct tag_MSG
{
   oswindow    hwnd;
   ::u32        message;
   WPARAM      wParam;
   LPARAM      lParam;
   POINT_I32       pt;
} MESSAGE, * MESSAGE *;
#endif


