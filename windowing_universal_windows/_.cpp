#include "framework.h"
#include "acme/_library.h"
//
//
//Gdiplus::GdiplusStartupInput *   g_pgdiplusStartupInput = nullptr;
//Gdiplus::GdiplusStartupOutput *  g_pgdiplusStartupOutput = nullptr;
//DWORD_PTR                        g_gdiplusToken = NULL;
//DWORD_PTR                        g_gdiplusHookToken = NULL;
//
//
//CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS ::e_status initialize_gdiplus()
//{
//
//   g_pgdiplusStartupInput = ___new Gdiplus::GdiplusStartupInput();
//
//   g_pgdiplusStartupOutput = ___new Gdiplus::GdiplusStartupOutput();
//
//   g_gdiplusToken = NULL;
//
//   g_gdiplusHookToken = NULL;
//
//   g_pgdiplusStartupInput->SuppressBackgroundThread = true;
//
//   Gdiplus::Status statusStartup = GdiplusStartup(&g_gdiplusToken, g_pgdiplusStartupInput, g_pgdiplusStartupOutput);
//
//   if (statusStartup != Gdiplus::Ok)
//   {
//
//      output_debug_string("Gdiplus Failed to Startup. ca cannot continue.", "Gdiplus Failure", e_message_box_icon_error);
//
//      return ::error_failed;
//
//   }
//
//   statusStartup = g_pgdiplusStartupOutput->NotificationHook(&g_gdiplusHookToken);
//
//   if (statusStartup != Gdiplus::Ok)
//   {
//
//      output_debug_string("Gdiplus Failed to Hook. ca cannot continue.", "Gdiplus Failure", e_message_box_icon_error);
//
//      return ::error_failed;
//
//   }
//
//   return ::success;
//
//}
//
//
//CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS void terminate_gdiplus()
//{
//
//   if (g_pgdiplusStartupOutput != nullptr)
//   {
//
//      g_pgdiplusStartupOutput->NotificationUnhook(g_gdiplusHookToken);
//
//
//      ::Gdiplus::GdiplusShutdown(g_gdiplusToken);
//
//
//      ::acme::del(g_pgdiplusStartupInput);
//      ::acme::del(g_pgdiplusStartupOutput);
//   }
//
//}
//
