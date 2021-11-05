#pragma once


//using namespace Platform;
using namespace ::winrt::Windows::Devices::Enumeration;
using namespace ::winrt::Windows::Devices::Midi;

namespace music
{


   namespace midi
   {


      namespace winrt
      {


         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT message_io :
            virtual public ::matter
         {
         public:



            message_io();
            ~message_io() override;

            void ScenarioInit();
            void ScenarioClose();

            //void ShowStatusMessage(String^ text);
            //void ShowExceptionMessage(Exception^ ex);

            //void EnableMessageBuilding();
            //void ResetMessageBuilding(bool resetMessageType);



            void OnMessageReceived(MidiInPort const &sender, MidiMessageReceivedEventArgs const & args);

          /*  DeviceInformation GetDeviceInformationForInPort(::winrt::hstring friendlyName);
            DeviceInformation GetDeviceInformationForOutPort(::winrt::hstring friendlyName);
            void CloseOutPort(::winrt::hstring portId);

            void CloseInPort(::winrt::hstring portId);*/


//            void send(MidiMessageType etype);



         };
      }

   }

}

