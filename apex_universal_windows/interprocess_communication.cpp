#include "framework.h"
#include "interprocess_handler.h"
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


   //namespace interprocess_handler
   //{


      // extern bool (WINAPI * g_pfnChangeWindowMessageFilter)(
      // _In_ const ::atom & atom,
      // _In_ ::u32 dwFlag);


   interprocess_communication_base::interprocess_communication_base()
   {

   }

   interprocess_communication_base::~interprocess_communication_base()
   {
   }

   interprocess_caller::interprocess_caller()
   {

   }

   interprocess_caller::~interprocess_caller()
   {
   }

   //bool tx::open(const char * pszChannel, launcher * plauncher)
   //{

   //   __UNREFERENCED_PARAMETER(plauncher);

   //   if (m_strBaseChannel.has_char())
   //      close();

   //   // LaunchUri protocol is m_strBaseChannel

   //   m_strBaseChannel = pszChannel;

   //   m_strBaseChannel.replace("_", "-");
   //   m_strBaseChannel.replace("/", "-");

   //   return true;

   //}


   void interprocess_caller::open(const ::string & strChannel, ::launcher * plauncher)
   {

      if (m_strBaseChannel.has_char())
      {

         close();

      }


      // LaunchUri protocol is m_strBaseChannel

      m_strBaseChannel = strChannel;

      m_strBaseChannel.find_replace("_", "-");
      m_strBaseChannel.find_replace("/", "-");

      ///return true;

   }


   void interprocess_caller::close()
   {

      //if (m_strBaseChannel.is_empty())
      //{

      //   return true;

      //}

      m_strBaseChannel.Empty();

      //         return true;

   }


   void interprocess_caller::send(const ::string & strMessage, const class time & timeTimeout)
   {

      //if (!is_tx_ok())
      //{
      // 
      //   return false;

      //}

      string anotherappUri = m_strBaseChannel + "://send?message=" + acmesystem()->url()->::url::encode(strMessage);

      //windows_runtime_launch_uri_synchronously(anotherappUri, timeTimeout);

      auto pnode = acmesystem()->node();

      pnode->node_post([this, anotherappUri]()
         {

            auto hstrUri = __hstring(anotherappUri);

            ::winrt::Windows::Foundation::Uri uri(hstrUri);

            auto res = ::winrt::Windows::System::Launcher::LaunchUriAsync(uri);

            fork([this, res]()
               {


                  bool bOk = res.get();

                  if (bOk)
                  {

                     output_debug_string("LaunchUriAsync was ok");

                  }
                  else
                  {

                     output_debug_string("LaunchUriAsync was nok");
                  }
               });

         });

      //return true;

   }


   bool interprocess_caller::is_tx_ok()
   {

      //return ::IsWindow(m_hwnd) != false;

      return m_strBaseChannel.has_char();


   }


   void interprocess_caller::send(int message, void * pdata, int len, const class time & timeTimeout)
   {

      //if (!is_tx_ok())
      //{

      //   return false;

      //}

      //memory m;

      string anotherappUri = m_strBaseChannel + "://send?messagebin=" + __string(message) + "," + acmesystem()->url()->::url::encode(acmesystem()->base64()->encode({ pdata, len }));

      auto pnode = acmesystem()->node();

      pnode->node_post([anotherappUri]()
         {

            auto hstrUri = __hstring(anotherappUri);

            ::winrt::Windows::Foundation::Uri uri(hstrUri);

            ::winrt::Windows::System::Launcher::LaunchUriAsync(uri).get();

         });

      //::winrt::Windows::Foundation::Uri ^uri = ref new ::winrt::Windows::Foundation::Uri(anotherappURI);

      //::wait(Launcher::LaunchUriAsync(uri), timeTimeout);

      //return true;

   }


   interprocess_handler::interprocess_handler()
   {

      m_preceiver = nullptr;

   }


   interprocess_handler::~interprocess_handler()
   {

   }


   void interprocess_handler::create(const ::string & strChannel)
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


   void interprocess_handler::destroy()
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


   //void * interprocess_handler::on_interprocess_receive(const char * pszMessage)
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



   bool interprocess_handler::on_idle()
   {

      return false;

   }

   bool interprocess_handler::is_rx_ok()
   {

      return m_strBaseChannel.has_char();

   }


   //interprocess_handler::interprocess_handler()
   //{


   //}


   //interprocess_handler::~interprocess_handler()
   //{


   //}


   //bool ipc::open_ab(const char * pszChannel, const char * pszModule, launcher * plauncher)
   //{

   //   m_strChannel = pszChannel;

   //   m_rx.m_preceiver = this;

   //   string strChannelRx = m_strChannel;

   //   string strChannelTx = m_strChannel;

   //   if (!m_rx.create(strChannelRx))
   //   {

   //      return false;

   //   }

   //   if (!tx::open(strChannelTx, plauncher))
   //   {

   //      return false;

   //   }

   //   return true;

   //}


   //bool ipc::open_ba(const char * pszChannel, const char * pszModule, launcher * plauncher)
   //{

   //   m_strChannel = pszChannel;

   //   m_rx.m_preceiver = this;

   //   string strChannelRx = m_strChannel;

   //   string strChannelTx = m_strChannel;

   //   if (!m_rx.create(strChannelRx))
   //   {

   //      return false;

   //   }

   //   if (!tx::open(strChannelTx, plauncher))
   //   {

   //      return false;

   //   }

   //   return true;

   //}


   //bool interprocess_handler::create(const ::string & strChannel, const char * pszModule)
   //{

   //   m_strChannel = pszChannel;

   //   m_rx.m_preceiver = this;

   //   string strChannelRx = m_strChannel;

   //   string strChannelTx = m_strChannel;

   //   if (!m_rx.create(strChannelRx))
   //   {

   //      return false;

   //   }

   //   if (!tx::open(strChannelTx))
   //   {

   //      return false;

   //   }

   //   return true;

   //}


   //bool interprocess_handler::open_ba(const char * pszChannel, const char * pszModule)
   //{

   //   m_strChannel = pszChannel;

   //   m_rx.m_preceiver = this;

   //   string strChannelRx = m_strChannel;

   //   string strChannelTx = m_strChannel;

   //   if (!m_rx.create(strChannelRx))
   //   {

   //      return false;

   //   }

   //   if (!tx::open(strChannelTx))
   //   {

   //      return false;

   //   }

   //   return true;

   //}




   //bool interprocess_handler::is_rx_tx_ok()
   //{

   //   return m_rx.is_rx_ok() && is_tx_ok();

   //}


//} // namespace ipc


} // namespace apex_universal_windows



