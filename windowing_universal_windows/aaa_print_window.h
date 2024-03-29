#pragma once


namespace windowing_win32
{


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS print_window :
      virtual public ::object
   {
   public:


      manual_reset_event m_event;
      oswindow m_oswindow;
      HDC m_hdc;


      print_window(::particle * pparticle, HWND hwnd, HDC hdc, ::duration tickTimeout) :
         ::object(pobject)
      {

         m_oswindow = oswindow;

         m_hdc = hdc;

         start();

         if (m_event.wait(tickTimeout).timeout())
         {

            information() << "print_window::time_out";

         }

      }


      virtual ::e_status     run() override
      {

         try
         {

            ::PrintWindow(m_oswindow, m_hdc, 0);

         }
         catch (...)
         {

         }

         m_event.set_event();

         return ::success;

      }

   };


}  // namespace windowing_win32



