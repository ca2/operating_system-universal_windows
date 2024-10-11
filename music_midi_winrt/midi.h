#pragma once


#include "app-veriwell/multimedia/music/midi/midi.h"
#undef __new

#include <winrt/Windows.Devices.h>
#include <winrt/Windows.Devices.Midi.h>


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT midi :
            virtual public ::music::midi::midi
         {
         public:


            ::map < ::winrt::Windows::Devices::Midi::MidiMessageType, ::string >                 m_messageTypeMap;
            ::winrt::Windows::Devices::Midi::MidiMessageType                                 m_messageType;
            array < ::winrt::agile_ref < ::winrt::Windows::Devices::Midi::MidiInPort > >     m_midiInPortArray;
            array < ::winrt::agile_ref < ::winrt::Windows::Devices::Midi::IMidiOutPort > >   m_midiOutPortArray;

            string_array                                    m_straOut;


            ::pointer<device_watcher>                      m_pmidiInDeviceWatcher;
            ::pointer<device_watcher>                      m_pmidiOutDeviceWatcher;


            midi();
            ~midi() override;


            //int get_out_port_count();
            //::winrt::hstring get_out_port_name(int i);
            //void select_out_port(::winrt::hstring str);


            //void add_out_port(::winrt::hstring portId);
            //void clear_out_ports();


            ::winrt::Windows::Devices::Enumeration::DeviceInformation GetDeviceInformationForInPort(::winrt::hstring friendlyName);
            ::winrt::Windows::Devices::Enumeration::DeviceInformation GetDeviceInformationForOutPort(::winrt::hstring friendlyName);

            //void CloseOutPort(::winrt::hstring portId);

            //void CloseInPort(::winrt::hstring portId);


            ::pointer<::music::midi::message_out>get_message_out(const string & strDevice) override;

            void enumerate_midi_out_devices() override;

            ::pointer<::music::midi::sequencer>create_midi_sequencer(sequence * psequence, const string & strDevice);


         };


      } // namespace winrt


   } // namespace midi


} // namespace music




