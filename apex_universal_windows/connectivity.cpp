// Created by Camilo on 2024-05-10 08:07 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "node.h"
#include "acme/_operating_system.h"
#include "acme/platform/application.h"
#include "acme/operating_system/universal_windows/parallelization_winrt.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include "acme_universal_windows/_winrt_core.h"
//#include "acme_universal_windows/_winrt_stream.h"
//#include "acme_universal_windows/_winrt_system.h"
//#include "acme_universal_windows/_winrt_storage.h"
#include <winrt/windows.foundation.collections.h>
#include <winrt/windows.networking.h>
#include <winrt/windows.networking.connectivity.h>
#include <winrt/windows.networking.sockets.h>


// https://wojciechkulik.pl/csharp/winrt-how-to-detect-supported-ip-versions

namespace apex_universal_windows
{


   void node::_has_ip_connectivity(bool & bIp4, bool & bIp6)
   {

      bIp4 = false;

      bIp6 = false;

      auto profile = ::winrt::Windows::Networking::Connectivity::NetworkInformation::GetInternetConnectionProfile();

      auto hostnames = ::winrt::Windows::Networking::Connectivity::NetworkInformation::GetHostNames();

      for (auto h : hostnames)
      {

         if (h.IPInformation() != nullptr &&
       h.IPInformation().NetworkAdapter() != nullptr &&
       h.IPInformation().NetworkAdapter().NetworkAdapterId() == profile.NetworkAdapter().NetworkAdapterId())
         {

            if (h.Type() == ::winrt::Windows::Networking::HostNameType::Ipv4)
            {

               if (!bIp4)
               {

                  bIp4 = true;

               }

            }
            else if (h.Type() == ::winrt::Windows::Networking::HostNameType::Ipv6)
            {

               if (!bIp6)
               {

                  bIp6 = true;

               }

            }

            if (bIp4 && bIp6)
            {

               return;

            }

         }

      }

   }


   void node::_defer_has_ip_connectivity(bool & bIp4, bool & bIp6)
   {

      if (m_timeLastConnectivityCheck.is_null() || m_timeLastConnectivityCheck.elapsed() > 10_s)
      {

         _has_ip_connectivity(m_bIp4Connectivity, m_bIp6Connectivity);

      }

      bIp4 = m_bIp4Connectivity;

      bIp6 = m_bIp6Connectivity;

   }


   bool node::_has_ip4_connectivity()
   {

      bool bIp4 = false;

      bool bIp6 = false;

      _defer_has_ip_connectivity(bIp4, bIp6);

      return bIp4;

   }


   bool node::_has_ip6_connectivity()
   {

      bool bIp4 = false;

      bool bIp6 = false;

      _defer_has_ip_connectivity(bIp4, bIp6);

      return bIp6;

   }


   void node::_can_connect_to_host(const ::scoped_string & scopedstr, bool & bUsingIp4, bool & bUsingIp6)
   {

      bUsingIp4 = false;

      bUsingIp6 = false;

      ::winrt::Windows::Networking::HostName hostname(as_hstring(scopedstr));

      auto hstrPort = as_hstring("0");

      // resolves domain name to IP addresses (may contain several)
      decltype(::winrt::Windows::Networking::Sockets::DatagramSocket::GetEndpointPairsAsync(hostname, hstrPort).get())
         endPointPairs{};

      m_papplication->synchronous_procedure(::winrt::impl::is_sta_thread(), [this, &endPointPairs, &hostname, &hstrPort]()
      {

         endPointPairs = ::winrt::Windows::Networking::Sockets::DatagramSocket::GetEndpointPairsAsync(hostname, hstrPort).get();

      });

      if (endPointPairs == nullptr)
      {

         return;

      }

      for (auto endPoint : endPointPairs)
      {

         if (endPoint.RemoteHostName() != nullptr)
         {

            if (endPoint.RemoteHostName().Type() == ::winrt::Windows::Networking::HostNameType::Ipv4)
            {

               if (!bUsingIp4)
               {

                  bUsingIp4 = true;

               }

            }
            else if (endPoint.RemoteHostName().Type() == ::winrt::Windows::Networking::HostNameType::Ipv6)
            {

               if (!bUsingIp6)
               {

                  bUsingIp6 = true;

               }

            }

            if (bUsingIp4 && bUsingIp6)
            {

               return;

            }

         }

      }

   }


   bool node::_can_connect_to_host_using_ip4(const ::scoped_string & scopedstr)
   {

      bool bUsingIp4 = false;

      bool bUsingIp6 = false;

      _can_connect_to_host(scopedstr, bUsingIp4, bUsingIp6);

      return bUsingIp4;

   }


   bool node::_can_connect_to_host_using_ip6(const ::scoped_string & scopedstr)
   {

      bool bUsingIp4 = false;

      bool bUsingIp6 = false;

      _can_connect_to_host(scopedstr, bUsingIp4, bUsingIp6);

      return bUsingIp6;

   }


   void node::_has_internet(bool & bIp4, bool & bIp6)
   {

      bool bIp4Google = false;

      bool bIp6Google = false;

      _can_connect_to_host("google.com", bIp4Google, bIp6Google);

      bool bIp4Microsoft = false;

      bool bIp6Microsoft = false;

      _can_connect_to_host("microsoft.com", bIp4Microsoft, bIp6Microsoft);

      bIp4 = bIp4Google && bIp4Microsoft;

      bIp6 = bIp6Google && bIp6Microsoft;

   }


   void node::_defer_has_internet(bool & bIp4, bool & bIp6)
   {

      if (m_timeLastInternetCheck.is_null() || m_timeLastInternetCheck.elapsed() > 10_s)
      {

         _has_internet(m_bHasInternetIp4, m_bHasInternetIp6);

      }

      bIp4 = m_bHasInternetIp4;

      bIp6 = m_bHasInternetIp6;

   }


   bool node::_has_ip4_internet()
   {

      bool bIp4 = false;

      bool bIp6 = false;

      _defer_has_internet(bIp4, bIp6);

      return bIp4;

   }


   bool node::_has_ip6_internet()
   {

      bool bIp4 = false;

      bool bIp6 = false;

      _defer_has_internet(bIp4, bIp6);

      return bIp6;

   }


   bool node::has_ip4_internet()
   {

      if (!_has_ip4_connectivity())
      {

         return false;

      }

      if (!_has_ip4_internet())
      {

         return false;

      }

      return true;

   }


   bool node::has_ip6_internet()
   {

      if (!_has_ip6_connectivity())
      {

         return false;

      }

      if (!_has_ip6_internet())
      {

         return false;

      }

      return true;

   }


} // namespace apex_universal_windows



