#include "framework.h"


namespace ca2plugin_container
{


   __IMPLEMENT_APPLICATION_RELEASE_TIME();


   application::application()
   {

   }

   application::~application()
   {
   }

   bool application::initialize(const ::scoped_string & scopedstrChannel)
   {

      //Sleep(15 * 1000);
      
      m_phost = ___new host(this);


      vsstring strChannel = "\\ca2\\ca2plugin-container-";
      strChannel += pszChannel;


      m_phost->m_strBitmapChannel = pszChannel;
      
      if(!m_phost->::small_ipc_channel::open_ba(strChannel, "ca2plugin-container.exe"))
         return false;

      m_phost->start_ca2();

//      if(!m_phost->initialize())
  //       return false;


      return true;


   }





   void application::on_receive(small_ipc_rx_channel * prxchannel, const ::scoped_string & scopedstrMessage)
   {

      __UNREFERENCED_PARAMETER(pszMessage);

   }

   void application::on_receive(small_ipc_rx_channel * prxchannel, int message, void * pdata, int len)
   {

      if(m_phost != NULL)
      {

         m_phost->on_receive(prxchannel, message, pdata, len);

      }

   }



   bool application::destroy()
   {

      return true;

   }

   int application::run()
   {

      MSG msg;
      
      while(true)
	   {

         if(!GetMessage(&msg, NULL, 0, 0xffffffffu))
            break;

         if(msg.message == WM_QUIT)
            break;

		   TranslateMessage(&msg);
		   DispatchMessage(&msg);

	   }

      return 0;

   }


} // namespace ca2plugin_container






