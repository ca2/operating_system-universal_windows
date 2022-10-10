#include "framework.h"
#include "midi.h"
#include "device_watcher.h"
#include "out.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include <winrt/Windows.Foundation.Collections.h>
//#include <mmddk.h>

// http://blogs.msdn.com/b/matthew_van_eerde/archive/2012/09/21/enumerating-midi-devices.aspx
// Maurits [MSFT]
//21 Sep 2012 9:31 AM

//0
// MSDN Blogs > Matthew van Eerde's web log > Enumerating MIDI devices 

#define LOG(format, ...) TRACE(format, __VA_ARGS__)


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         midi::midi()
         {

            m_pmidiOutDeviceWatcher = __new(device_watcher(this, ::winrt::Windows::Devices::Midi::MidiOutPort::GetDeviceSelector().begin()));

            m_pmidiOutDeviceWatcher->start_device_watcher();

         }


         midi::~midi()
         {

            m_pmidiInDeviceWatcher->stop_device_watcher();

            m_pmidiOutDeviceWatcher->stop_device_watcher();

         }


         ::winrt::Windows::Devices::Enumeration::DeviceInformation midi::GetDeviceInformationForInPort(::winrt::hstring friendlyName)
         {

            ::winrt::Windows::Devices::Enumeration::DeviceInformation retValue = nullptr;

            ::winrt::Windows::Devices::Enumeration::DeviceInformationCollection inputCollection = m_pmidiInDeviceWatcher->GetDeviceInformationCollection();

            for (::u32 u = 0; u < inputCollection.Size(); u++)
            {

               ::winrt::Windows::Devices::Enumeration::DeviceInformation devInfo = inputCollection.GetAt(u);

               if (0 == wcsicmp(devInfo.Name().begin(), friendlyName.begin()))
               {

                  retValue = devInfo;

               }

            }

            return retValue;

         }


         ::winrt::Windows::Devices::Enumeration::DeviceInformation midi::GetDeviceInformationForOutPort(::winrt::hstring atom)
         {

            ::winrt::Windows::Devices::Enumeration::DeviceInformationCollection inputCollection = m_pmidiOutDeviceWatcher->GetDeviceInformationCollection();

            for (::u32 u = 0; u < inputCollection.Size(); u++)
            {

               ::winrt::Windows::Devices::Enumeration::DeviceInformation deviceinformation = inputCollection.GetAt(u);

               if (0 == wcscmp(deviceinformation.Id().begin(), atom.begin()))
               {

                  return deviceinformation;

               }

            }

            return nullptr;

         }


         //void midi::CloseInPort(::winrt::hstring portId)
         //{

         //   for (unsigned int index = 0; index < m_midiInPortArray.get_size(); index++)
         //   {

         //      if (0 == wcscmp(m_midiInPortArray[index].get().DeviceId().begin(), portId.begin()))
         //      {

         //         m_midiInPortArray.erase_at(index);

         //         return;

         //      }

         //   }

         //}


         //void midi::CloseOutPort(::winrt::hstring  portId)
         //{

         //   for (unsigned int index = 0; index < m_midiOutPortArray.get_size(); index++)
         //   {

         //      if (0 == wcscmp(m_midiOutPortArray[index].get().DeviceId().begin(), portId.begin()))
         //      {

         //         m_midiOutPortArray.erase_at(index);

         //         return;

         //      }

         //   }

         //}


         //int midi::get_out_port_count()
         //{

         //   return m_straOut.get_size();

         //}


         //::winrt::hstring midi::get_out_port_name(int i)
         //{

         //   return __hstring(m_straOut[i]);

         //}


         //void midi::select_out_port(::winrt::hstring str)
         //{

         //   m_midiOutPortArray.erase_all();

         //   DeviceInformation portToOpen = GetDeviceInformationForOutPort(str);

         //   if (portToOpen != nullptr)
         //   {

         //      auto outPort = MidiOutPort::FromIdAsync(portToOpen.Id()).get();

         //      if (outPort != nullptr)
         //      {

         //         m_midiOutPortArray.add(outPort);

         //      }

         //   }

         //}


         //void midi::add_out_port(::winrt::hstring portId)
         //{

         //   m_straOut.add(portId.begin());

         //   string strId = portId.begin();

         //   add_midi_out_device(strId, strId);

         //}


         //void midi::clear_out_ports()
         //{

         //   m_straOut.erase_all();

         //}


         ::pointer<::music::midi::message_out>midi::get_message_out(const string & strDeviceParam)
         {

            string strDevice(strDeviceParam);

            if (strDevice.begins_eat_ci("winrt:"))
            {

               auto & pmessageout = m_mapMessageOut[strDevice];

               if (!pmessageout)
               {

                  auto pout = __new(out);

                  ::winrt::Windows::Devices::Enumeration::DeviceInformation deviceinformation = GetDeviceInformationForOutPort(__hstring(strDevice));

                  if (deviceinformation)
                  {

                     string strId = deviceinformation.Id().begin();

                     auto outport = ::winrt::Windows::Devices::Midi::MidiOutPort::FromIdAsync(deviceinformation.Id()).get();

                     if (outport)
                     {

                        pout->m_midiOutPort = outport;

                     }

                  }
                  //   else
                  //   {

                  //      outport = MidiSynthesizer::CreateAsync().get();

                  //      if (wcscmp(outport.DeviceId().begin(), deviceinformation.Id().begin()))
                  //      {

                  //         outport = nullptr;

                  //      }

                  //   }

                  //}

                  pmessageout = pout;

               }

               return pmessageout;

            }

            return nullptr;

         }


         void midi::enumerate_midi_out_devices()
         {

            //add_midi_out_device("GS Synth", "gssynth");

            ::music::midi::midi::enumerate_midi_out_devices();

         }



      } // namespace winrt


   } // namespace midi


} // namespace music




