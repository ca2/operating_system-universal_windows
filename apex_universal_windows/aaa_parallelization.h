#pragma once



#ifndef UNIVERSAL_WINDOWS

typedef struct tag_MSG
{
   oswindow    hwnd;
   unsigned int        message;
   WPARAM      wParam;
   LPARAM      lParam;
   ::point_i32       pt;
} MESSAGE, * MESSAGE *;
#endif


