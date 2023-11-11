// Created by camilo on 2023-11-11 04:26 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "device_group.h"



namespace aura_universal_windows
{


   namespace hardware
   {


      device_group::device_group()
      {

         m_bAlreadyEnumerated = false;
      }


      device_group::~device_group()
      {


      }

      void device_group::initialize_device_group(::hardware::enum_device edevice, ::hardware::devices * pdevices)
      {

         ::hardware::device_group::initialize_device_group(edevice, pdevices);

         if (edevice == ::hardware::e_device_video_input)
         {

            m_devicewatcher = ::winrt::Windows::Devices::Enumeration::DeviceInformation::CreateWatcher(          ::winrt::Windows::Devices::Enumeration::DeviceClass::VideoCapture);

         }

         if (m_devicewatcher)
         {

            m_devicewatcher.Added({ this, &device_group::DeviceWatcherAdded });
            m_devicewatcher.EnumerationCompleted({ this, &device_group::DeviceWatcherEnumerationComplete });
            m_devicewatcher.Removed({ this, &device_group::DeviceWatcherRemoved });
            m_devicewatcher.Stopped({ this, &device_group::DeviceWatcherStopped });
            m_devicewatcher.Updated({ this, &device_group::DeviceWatcherUpdated });

            m_devicewatcher.Start();


         }

      }


      void device_group::DeviceWatcherAdded(
         const ::winrt::Windows::Devices::Enumeration::DeviceWatcher watcher,
   const ::winrt::Windows::Devices::Enumeration::DeviceInformation & update)
      {

         if (m_bAlreadyEnumerated)
         {

            on_device_list_updated();

         }

      }


      void device_group::DeviceWatcherEnumerationComplete(
         const ::winrt::Windows::Devices::Enumeration::DeviceWatcher watcher,
         const ::winrt::Windows::Foundation::IInspectable & inspectable)
      {
         
         m_bAlreadyEnumerated = true;
         
         on_device_list_updated();

      }         



      void device_group::DeviceWatcherRemoved(
         const ::winrt::Windows::Devices::Enumeration::DeviceWatcher watcher,
         const ::winrt::Windows::Devices::Enumeration::DeviceInformationUpdate & update)
      {

         if (m_bAlreadyEnumerated)
         {

            on_device_list_updated();

         }

      }


      void device_group::DeviceWatcherStopped(
         const ::winrt::Windows::Devices::Enumeration::DeviceWatcher watcher,
         const ::winrt::Windows::Foundation::IInspectable & inspectable)
      {


      }


      void device_group::DeviceWatcherUpdated(
         const ::winrt::Windows::Devices::Enumeration::DeviceWatcher watcher,
         const ::winrt::Windows::Devices::Enumeration::DeviceInformationUpdate & update)
      {

      }



   } // namespace hardware


} // namespace aura_universal_windows




