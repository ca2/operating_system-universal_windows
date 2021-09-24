// Moved from io to midi to device_watcher by 2021-09-23 20:15 BRT <3ThomasBorregaardSørensen!!
#pragma once


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


            __pointer(midi)               m_pmidi;
            string                        m_strMidiSelector;

            ::winrt::event_token          m_tokenPortAdded;
            ::winrt::event_token          m_tokenPortRemoved;
            ::winrt::event_token          m_tokenPortUpdated;
            ::winrt::event_token          m_tokenPortEnumComplete;


            DeviceWatcher                 m_devicewatcher = nullptr;
            DeviceInformationCollection   m_deviceinformationcollection = nullptr;

            bool                          m_bEnumCompleted;


            device_watcher(midi * pmidi, const ::string & strMidiSelector);
            ~device_watcher() override;


            void start_device_watcher();
            void stop_device_watcher();

            DeviceInformationCollection GetDeviceInformationCollection();

            void update_ports();

            void OnPortAdded(DeviceWatcher const & deviceWatcher, DeviceInformation const & devInfo);
            void OnPortRemoved(DeviceWatcher  const & deviceWatcher, DeviceInformationUpdate const & devInfoUpdate);
            void OnPortUpdated(DeviceWatcher  const & deviceWatcher, DeviceInformationUpdate const & devInfoUpdate);
            void OnPortEnumCompleted(DeviceWatcher const & deviceWatcher, IInspectable const & obj);


         };


      } // namespace winrt


   } // namespace midi


} // namespace music



