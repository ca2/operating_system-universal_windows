// Moved from io to midi to device_watcher by 2021-09-23 20:15 BRT <3ThomasBorregaardSorensen!!
#pragma once


#undef new
#include <winrt/Windows.Devices.Enumeration.h>


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         class device_watcher :
            virtual public ::matter
         {
         public:


            ::pointer<midi>              m_pmidi;
            string                        m_strMidiSelector;

            ::winrt::event_token          m_tokenPortAdded;
            ::winrt::event_token          m_tokenPortRemoved;
            ::winrt::event_token          m_tokenPortUpdated;
            ::winrt::event_token          m_tokenPortEnumComplete;


            ::winrt::Windows::Devices::Enumeration::DeviceWatcher                 m_devicewatcher = nullptr;
            ::winrt::Windows::Devices::Enumeration::DeviceInformationCollection   m_deviceinformationcollection = nullptr;

            bool                          m_bEnumCompleted;


            device_watcher(midi * pmidi, const ::string & strMidiSelector);
            ~device_watcher() override;


            void start_device_watcher();
            void stop_device_watcher();

            ::winrt::Windows::Devices::Enumeration::DeviceInformationCollection GetDeviceInformationCollection();

            void update_ports();

            void OnPortAdded(::winrt::Windows::Devices::Enumeration::DeviceWatcher const & deviceWatcher, ::winrt::Windows::Devices::Enumeration::DeviceInformation const & devInfo);
            void OnPortRemoved(::winrt::Windows::Devices::Enumeration::DeviceWatcher  const & deviceWatcher, ::winrt::Windows::Devices::Enumeration::DeviceInformationUpdate const & devInfoUpdate);
            void OnPortUpdated(::winrt::Windows::Devices::Enumeration::DeviceWatcher  const & deviceWatcher, ::winrt::Windows::Devices::Enumeration::DeviceInformationUpdate const & devInfoUpdate);
            void OnPortEnumCompleted(::winrt::Windows::Devices::Enumeration::DeviceWatcher const & deviceWatcher, ::winrt::Windows::Foundation::IInspectable const & obj);


         };


      } // namespace winrt


   } // namespace midi


} // namespace music



