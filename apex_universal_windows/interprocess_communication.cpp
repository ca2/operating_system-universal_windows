#include "framework.h"

//#include "universal_windows.h"
//#ifndef _UWP

// loop question http://stackoverflow.com/users/2101860/loop
// http://stackoverflow.com/questions/23709329/launch-one-metro-app-from-other-metro-app-windows-8
// souvickcse http://stackoverflow.com/users/2246798/souvickcse

namespace universal_windows
{


   //namespace interprocess_communication
   //{


      // extern bool (WINAPI * g_pfnChangeWindowMessageFilter)(
      // _In_ const ::id & id,
      // _In_ ::u32 dwFlag);


   interprocess_communication_base::interprocess_communication_base()
      {

      }

   interprocess_communication_base::~interprocess_communication_base()
      {
      }

   interprocess_communication_tx::interprocess_communication_tx()
      {

      }

   interprocess_communication_tx::~interprocess_communication_tx()
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

      bool interprocess_communication_tx::open(const ::string & strChannel, ::launcher * plauncher)
      {

         if (m_strBaseChannel.has_char())
            close();

         // LaunchUri protocol is m_strBaseChannel

         m_strBaseChannel = strChannel;

         m_strBaseChannel.replace("_", "-");
         m_strBaseChannel.replace("/", "-");

         return true;

      }


      bool interprocess_communication_tx::close()
      {

         if (m_strBaseChannel.is_empty())
            return true;

         m_strBaseChannel.Empty();

         return true;

      }


      bool interprocess_communication_tx::send(const ::string & strMessage, duration durationTimeout)
      {

         if (!is_tx_ok())
         {
          
            return false;

         }

         string anotherappUri = m_strBaseChannel + "://send?message=" + m_psystem->url()->url_encode(strMessage);

         //windows_runtime_launch_uri_synchronously(anotherappUri, durationTimeout);

         auto pnode = m_psystem->node();

         pnode->node_post(__routine([anotherappUri]()
            {

               auto hstrUri = __hstring(anotherappUri);

               ::winrt::Windows::Foundation::Uri uri(hstrUri);

               ::winrt::Windows::System::Launcher::LaunchUriAsync(uri);

            }));

         return true;

      }


      bool interprocess_communication_tx::is_tx_ok()
      {

         //return ::IsWindow(m_hwnd) != false;

         return m_strBaseChannel.has_char();


      }


      bool interprocess_communication_tx::send(int message, void * pdata, int len, ::duration durationTimeout)
      {

         if (!is_tx_ok())
            return false;

         //memory m;

         string anotherappUri = m_strBaseChannel + "://send?messagebin=" + __string(message) + "," + m_psystem->url()->url_encode(m_psystem->base64()->encode({ pdata, len }));
         
         
         auto pnode = m_psystem->node();

         pnode->node_post(__routine([anotherappUri]()
            {

               auto hstrUri = __hstring(anotherappUri);

               ::winrt::Windows::Foundation::Uri uri(hstrUri);

               ::winrt::Windows::System::Launcher::LaunchUriAsync(uri).get();

            }));

         //::winrt::Windows::Foundation::Uri ^uri = ref new ::winrt::Windows::Foundation::Uri(anotherappURI);

         //::wait(Launcher::LaunchUriAsync(uri), durationTimeout);

         return true;

      }


      interprocess_communication_rx::interprocess_communication_rx()
      {

         m_preceiver = nullptr;

      }


      interprocess_communication_rx::~interprocess_communication_rx()
      {

      }


      bool interprocess_communication_rx::create(const ::string & strChannel)
      {

         if (m_strBaseChannel.has_char())
            destroy();

         m_strBaseChannel = strChannel;

         m_strBaseChannel.replace("_", "-");
         m_strBaseChannel.replace("/", "-");


         return true;

      }


      ::e_status interprocess_communication_rx::destroy()
      {

         if (m_strBaseChannel.is_empty())
         {

            return true;

         }


         m_strBaseChannel.Empty();

         return true;

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


      //void * interprocess_communication_rx::on_interprocess_receive(const char * pszMessage)
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



      bool interprocess_communication_rx::on_idle()
      {

         return false;

      }

      bool interprocess_communication_rx::is_rx_ok()
      {

         return m_strBaseChannel.has_char();

      }


      //interprocess_communication::interprocess_communication()
      //{


      //}


      //interprocess_communication::~interprocess_communication()
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


      //bool interprocess_communication::create(const ::string & strChannel, const char * pszModule)
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


      //bool interprocess_communication::open_ba(const char * pszChannel, const char * pszModule)
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




      //bool interprocess_communication::is_rx_tx_ok()
      //{

      //   return m_rx.is_rx_ok() && is_tx_ok();

      //}


   //} // namespace ipc


} // namespace universal_windows



//#endif
