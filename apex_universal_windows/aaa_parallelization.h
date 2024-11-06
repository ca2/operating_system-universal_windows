#pragma once



#ifndef UNIVERSAL_WINDOWS

typedef struct tag_MSG
{
   oswindow    hwnd;
   unsigned int        message;
   WPARAM      wParam;
   LPARAM      lParam;
   ::int_point       pt;
} MESSAGE, * MESSAGE *;
#endif


