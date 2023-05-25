#pragma once



#ifndef UNIVERSAL_WINDOWS

typedef struct tag_MSG
{
   oswindow    hwnd;
   ::u32        message;
   WPARAM      wParam;
   LPARAM      lParam;
   ::point_i32       pt;
} MESSAGE, * MESSAGE *;
#endif


