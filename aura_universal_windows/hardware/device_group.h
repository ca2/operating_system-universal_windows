// Created by camilo on 2023-11-11 04:26 <3ThomasBorregaardSorensen!!
#include "framework.h"


#include "aura/hardware/device_group.h"
#include "acme/_operating_system.h"
#include <winrt/windows.foundation.h>
#include <winrt/windows.devices.enumeration.h>


namespace aura_universal_windows
{

   
   namespace hardware
   {


      class CLASS_DECL_AURA_UNIVERSAL_WINDOWS device_group :
         virtual public ::hardware::device_group
      {
      public:



         ::winrt::Windows::Devices::Enumeration::DeviceWatcher m_devicewatcher = nullptr;
         bool                          m_bAlreadyEnumerated;

         device_group();
         ~device_group() override;


         void initialize_device_group(::hardware::enum_device edevice, ::hardware::devices * pdevices) override;

         //void on_device_added();

         void DeviceWatcherAdded(
            ::winrt::Windows::Devices::Enumeration::DeviceWatcher watcher,
            const ::winrt::Windows::Devices::Enumeration::DeviceInformation & information);
         void DeviceWatcherEnumerationComplete(
            ::winrt::Windows::Devices::Enumeration::DeviceWatcher watcher,
            const ::winrt::Windows::Foundation::IInspectable & inspectable);

         void DeviceWatcherRemoved(
            ::winrt::Windows::Devices::Enumeration::DeviceWatcher watcher,
            const ::winrt::Windows::Devices::Enumeration::DeviceInformationUpdate & update);
         void DeviceWatcherStopped(
            ::winrt::Windows::Devices::Enumeration::DeviceWatcher watcher,
            const ::winrt::Windows::Foundation::IInspectable & inspectable);

         void DeviceWatcherUpdated(
            ::winrt::Windows::Devices::Enumeration::DeviceWatcher watcher,
            const ::winrt::Windows::Devices::Enumeration::DeviceInformationUpdate & update);



      };


   } // namespace hardware


} // namespace aura_universal_windows


