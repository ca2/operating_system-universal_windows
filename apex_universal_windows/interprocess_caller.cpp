// From interprocess_communication.cpp by Camilo 2022-10-11 09:27 BRT <3ThomasBorregaardSoerensen
#include "framework.h"
#include "interprocess_caller.h"
#include "interprocess_target.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include "acme/platform/node.h"
#include "acme/primitive/string/base64.h"
#include <winrt/Windows.System.h>


//#include "universal_windows.h"
//#ifndef UNIVERSAL_WINDOWS

// loop question http://stackoverflow.com/users/2101860/loop
// http://stackoverflow.com/questions/23709329/launch-one-metro-app-from-other-metro-app-windows-8
// souvickcse http://stackoverflow.com/users/2246798/souvickcse

namespace apex_universal_windows
{


   interprocess_caller::interprocess_caller()
   {

   }


   interprocess_caller::~interprocess_caller()
   {

   }


   //bool tx::open(const scoped_string & strChannel, launcher * plauncher)
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
      m_strBaseChannel.find_replace("/", ".");

   }


   void interprocess_caller::close()
   {

      //if (m_strBaseChannel.is_empty())
      //{

      //   return true;

      //}

      m_strBaseChannel.empty();

      //         return true;

   }


   void interprocess_caller::call(const ::string & strUri, const class time & timeTimeout)
   {

      //if (!is_tx_ok())
      //{
      // 
      //   return false;

      //}

      //string anotherappUri = m_strBaseChannel + "://send?message=" + acmesystem()->url()->::url::encode(strMessage);

      //string anotherappUri = strUri;

      //windows_runtime_launch_uri_synchronously(anotherappUri, timeTimeout);

      auto hstrUri = __hstring(strUri);

      acmenode()->node_post([this, hstrUri]()
         {

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


   bool interprocess_caller::is_caller_ok()
   {

      //return ::IsWindow(m_hwnd) != false;

      return m_strBaseChannel.has_char();

   }


   //void interprocess_caller::call(int message, void * pdata, int len, const class time & timeTimeout)
   //{

   //   //if (!is_tx_ok())
   //   //{

   //   //   return false;

   //   //}

   //   //memory m;

   //   string anotherappUri = m_strBaseChannel + "://send?messagebin=" + __string(message) + "," + acmesystem()->url()->::url::encode(acmesystem()->base64()->encode({ pdata, len }));

   //   auto pnode = acmesystem()->node();

   //   pnode->node_post([anotherappUri]()
   //      {

   //         auto hstrUri = __hstring(anotherappUri);

   //         ::winrt::Windows::Foundation::Uri uri(hstrUri);

   //         ::winrt::Windows::System::Launcher::LaunchUriAsync(uri).get();

   //      });

   //   //::winrt::Windows::Foundation::Uri ^uri = ref new ::winrt::Windows::Foundation::Uri(anotherappURI);

   //   //::wait(Launcher::LaunchUriAsync(uri), timeTimeout);

   //   //return true;

   //}


} // namespace apex_universal_windows



