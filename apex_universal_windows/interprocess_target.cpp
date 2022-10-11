// From interprocess_communication.cpp by Camilo 2022-10-11 09:27 BRT <3ThomasBorregaardSoerensen
#include "framework.h"
#include "interprocess_target.h"
#include "acme/primitive/string/base64.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include <winrt/Windows.System.h>


//#include "universal_windows.h"
//#ifndef _UWP

// loop question http://stackoverflow.com/users/2101860/loop
// http://stackoverflow.com/questions/23709329/launch-one-metro-app-from-other-metro-app-windows-8
// souvickcse http://stackoverflow.com/users/2246798/souvickcse

namespace apex_universal_windows
{


   interprocess_target::interprocess_target()
   {

   }


   interprocess_target::~interprocess_target()
   {

   }


   void interprocess_target::create(const ::string & strChannel)
   {

      if (m_strBaseChannel.has_char())
      {

         destroy();

      }

      m_strBaseChannel = strChannel;

      m_strBaseChannel.find_replace("_", "-");
      m_strBaseChannel.find_replace("/", "-");

      // return true;

   }


   void interprocess_target::destroy()
   {

      //if (m_strBaseChannel.is_empty())
      //{

      //   return true;

      //}


      m_strBaseChannel.Empty();

      //return true;

   }

   //void rx::receiver::on_ipc_receive(rx * prx, const char * pszMessage)
   //{

   //}

   //void rx::receiver::on_ipc_receive(rx * prx, int message, void * pdata, memsize len)
   //{

   //}


   //void rx::receiver::on_ipc_post(rx * prx, long long int a, long long int b)
   //{

   //}


   //void * interprocess_target::on_interprocess_receive(const char * pszMessage)
   //{

   //   if (m_preceiver != nullptr)
   //   {
   //      m_preceiver->on_interprocess_receive(prx, pszMessage);
   //   }

   //   // ODOW - on date of writing : return ignored by this windows implementation

   //   return nullptr;

   //}

   //void * rx::on_interprocess_receive(rx * prx, int message, void * pdata, memsize len)
   //{

   //   if (m_preceiver != nullptr)
   //   {
   //      m_preceiver->on_interprocess_receive(prx, message, pdata, len);
   //   }

   //   // ODOW - on date of writing : return ignored by this windows implementation

   //   return nullptr;

   //}


   //void * rx::on_interprocess_post(rx * prx, long long int a, long long int b)
   //{

   //   if (m_preceiver != nullptr)
   //   {

   //      m_preceiver->on_interprocess_post(prx, a, b);

   //   }

   //   // ODOW - on date of writing : return ignored by this windows implementation

   //   return nullptr;

   //}



   bool interprocess_target::on_idle()
   {

      return false;

   }

   bool interprocess_target::is_rx_ok()
   {

      return m_strBaseChannel.has_char();

   }


} // namespace apex_universal_windows



