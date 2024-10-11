//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************

//
// message_io.xaml.cpp of the message_io class
//
#include "framework.h"
#include "message_io.h"


//using namespace ::winrt::Windows::Foundation;
//using namespace ::winrt::Windows::UI;
//using namespace ::winrt::Windows::UI::Core;
//using namespace ::winrt::Windows::Storage::Streams;
//using namespace ::winrt::Windows::Devices::Midi;

namespace music
{

   namespace midi
   {

      namespace winrt
      {


         message_io::message_io() //:
            //_messageTypeMap(nullptr),
            //_messageType(MidiMessageType::None) //,
            //_midiInDeviceWatcher(nullptr),
            //_midiOutDeviceWatcher(nullptr)
         {
            //_messageTypeMap.set_at(MidiMessageType::ActiveSensing, "Active Sensing");
            //_messageTypeMap.set_at(MidiMessageType::ChannelPressure, "Channel Pressure");
            //_messageTypeMap.set_at(MidiMessageType::Continue, "Continue");
            //_messageTypeMap.set_at(MidiMessageType::ControlChange, "Control Change");
            //_messageTypeMap.set_at(MidiMessageType::MidiTimeCode, "MIDI Time Code");
            ////_messageTypeMap.set_at(MidiMessageType::None, "None");
            //_messageTypeMap.set_at(MidiMessageType::NoteOff, "Note Off");
            //_messageTypeMap.set_at(MidiMessageType::NoteOn, "Note On");
            //_messageTypeMap.set_at(MidiMessageType::PitchBendChange, "Pitch Bend Change");
            //_messageTypeMap.set_at(MidiMessageType::PolyphonicKeyPressure, "Polyphonic Key Pressure");
            //_messageTypeMap.set_at(MidiMessageType::ProgramChange, "Program Change");
            //_messageTypeMap.set_at(MidiMessageType::SongPositionPointer, "Song Position Pointer");
            //_messageTypeMap.set_at(MidiMessageType::SongSelect, "Song Select");
            //_messageTypeMap.set_at(MidiMessageType::Start, "Start");
            //_messageTypeMap.set_at(MidiMessageType::Stop, "Stop");
            //_messageTypeMap.set_at(MidiMessageType::SystemExclusive, "System Exclusive");
            //_messageTypeMap.set_at(MidiMessageType::SystemReset, "System Reset");
            //_messageTypeMap.set_at(MidiMessageType::TimingClock, "Timing Clock");
            //_messageTypeMap.set_at(MidiMessageType::TuneRequest, "Tune Request");

            ScenarioInit();




         }


         message_io::~message_io()
         {

            

         }


         void message_io::ScenarioInit()
         {


         }


         void message_io::ScenarioClose()
         {

         }

       

         void message_io::OnMessageReceived(::winrt::Windows::Devices::Midi::MidiInPort const & sender, ::winrt::Windows::Devices::Midi::MidiMessageReceivedEventArgs const & args)
         {
            //IMidiMessage^ midiMessage = args->Message;

            //create_task(Dispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::High,
            //   ref __new ::winrt::Windows::UI::Core::DispatchedHandler([this, sender, midiMessage]()
            //{
            //   String^ outputString = midiMessage->Timestamp.Duration + ", " + _messageTypeMap->Lookup(midiMessage->Type);

            //   switch (midiMessage->Type)
            //   {
            //   case MidiMessageType::NoteOff:
            //   {
            //      MidiNoteOffMessage^ noteOff = static_cast<MidiNoteOffMessage ^>(midiMessage);

            //      outputString += ", Channel:" + noteOff->Channel + ", Note:" + noteOff->Note + ", Velocity:" + noteOff->Velocity;
            //      break;
            //   }
            //   case MidiMessageType::NoteOn:
            //   {
            //      MidiNoteOnMessage^ noteOn = static_cast<MidiNoteOnMessage ^>(midiMessage);

            //      outputString += ", Channel:" + noteOn->Channel + ", Note:" + noteOn->Note + ", Velocity:" + noteOn->Velocity;
            //      break;
            //   }
            //   case MidiMessageType::PolyphonicKeyPressure:
            //   {
            //      MidiPolyphonicKeyPressureMessage^ polyKeyMessage = static_cast<MidiPolyphonicKeyPressureMessage ^>(midiMessage);

            //      outputString += ", Channel:" + polyKeyMessage->Channel + ", Note:" + polyKeyMessage->Note + ", Pressure:" + polyKeyMessage->Pressure;
            //      break;

            //   }
            //   case MidiMessageType::ControlChange:
            //   {
            //      MidiControlChangeMessage^ controlMessage = static_cast<MidiControlChangeMessage ^>(midiMessage);

            //      outputString += ", Channel:" + controlMessage->Channel + ", Controller:" + controlMessage->Controller + ", Value:" + controlMessage->ControlValue;
            //      break;

            //   }
            //   case MidiMessageType::ProgramChange:
            //   {

            //      MidiProgramChangeMessage^ programMessage = static_cast<MidiProgramChangeMessage ^>(midiMessage);

            //      outputString += ", Channel:" + programMessage->Channel + ", Program:" + programMessage->Program;
            //      break;

            //   }
            //   case MidiMessageType::ChannelPressure:
            //   {
            //      MidiChannelPressureMessage^ channelPressureMessage = static_cast<MidiChannelPressureMessage ^>(midiMessage);

            //      outputString += ", Channel:" + channelPressureMessage->Channel + ", Pressure:" + channelPressureMessage->Pressure;
            //      break;

            //   }
            //   case MidiMessageType::PitchBendChange:
            //   {
            //      MidiPitchBendChangeMessage^ pitchBendMessage = static_cast<MidiPitchBendChangeMessage ^>(midiMessage);

            //      outputString += ", Channel:" + pitchBendMessage->Channel + ", Bend:" + pitchBendMessage->Bend;
            //      break;

            //   }
            //   case MidiMessageType::SystemExclusive:
            //   {
            //      MidiSystemExclusiveMessage^ sysExMessage = static_cast<MidiSystemExclusiveMessage ^>(midiMessage);
            //      DataReader^ sysExReader = DataReader::FromBuffer(sysExMessage->RawData);

            //      outputString += ", ";

            //      while (sysExReader->UnconsumedBufferLength > 0)
            //      {
            //         // prepare SysEx message for printing to the screen.
            //         // convert bytes to hex strings.
            //         Array<wchar_t>^ byteInHex = ref __new Array<wchar_t>(3);
            //         ::u8 byteRead = sysExReader->ReadByte();

            //         swprintf_s(byteInHex->Data, sizeof(byteInHex->Length), L"%02X", byteRead);
            //         String^ hexString = ref __new String(byteInHex->Data);

            //         outputString += hexString + " ";
            //      }
            //      break;

            //   }
            //   case MidiMessageType::MidiTimeCode:
            //   {
            //      MidiTimeCodeMessage^ mtcMessage = static_cast<MidiTimeCodeMessage ^>(midiMessage);

            //      outputString += ", Type:" + mtcMessage->FrameType + ", Values:" + mtcMessage->Values;
            //      break;

            //   }
            //   case MidiMessageType::SongPositionPointer:
            //   {
            //      MidiSongPositionPointerMessage^ songPositionMessage = static_cast<MidiSongPositionPointerMessage ^>(midiMessage);

            //      outputString += ", Beats:" + songPositionMessage->Beats;
            //      break;

            //   }
            //   case MidiMessageType::SongSelect:
            //   {
            //      MidiSongSelectMessage^ songSelectMessage = static_cast<MidiSongSelectMessage ^>(midiMessage);

            //      outputString += ", Song:" + songSelectMessage->Song;
            //      break;

            //   }
            //   case MidiMessageType::TuneRequest:
            //   {
            //      MidiTuneRequestMessage^ tuneRequestMessage = static_cast<MidiTuneRequestMessage ^>(midiMessage);

            //      break;

            //   }
            //   case MidiMessageType::TimingClock:
            //   {
            //      MidiTimingClockMessage^ timingClockMessage = static_cast<MidiTimingClockMessage ^>(midiMessage);

            //      break;

            //   }
            //   case MidiMessageType::Start:
            //   {
            //      MidiStartMessage^ startMessage = static_cast<MidiStartMessage ^>(midiMessage);

            //      break;

            //   }
            //   case MidiMessageType::Continue:
            //   {
            //      MidiContinueMessage^ continueMessage = static_cast<MidiContinueMessage ^>(midiMessage);

            //      break;

            //   }
            //   case MidiMessageType::Stop:
            //   {
            //      MidiStopMessage^ stopMessage = static_cast<MidiStopMessage ^>(midiMessage);

            //      break;

            //   }
            //   case MidiMessageType::ActiveSensing:
            //   {
            //      MidiActiveSensingMessage^ activeSensingMessage = static_cast<MidiActiveSensingMessage ^>(midiMessage);

            //      break;

            //   }
            //   case MidiMessageType::SystemReset:
            //   {
            //      MidiSystemResetMessage^ systemResetMessage = static_cast<MidiSystemResetMessage ^>(midiMessage);

            //      break;

            //   }
            //   case MidiMessageType::None:
            //   default:
            //      break;
            //   }

            //   _messageOutputListBox->Items->Append(outputString);
            //})));
         }

         //DeviceInformation message_io::GetDeviceInformationForInPort(::winrt::hstring friendlyName)
         //{
         //   DeviceInformation retValue = nullptr;
         //   DeviceInformationCollection inputCollection = m_pmidiInDeviceWatcher->GetDeviceInformationCollection();

         //   for (::collection::index i = 0; i < inputCollection.Size(); i++)
         //   {
         //      
         //      DeviceInformation devInfo = inputCollection.GetAt(i);

         //      if (0 == wcsicmp(devInfo.Name().begin(), friendlyName.begin()))
         //      {

         //         retValue = devInfo;

         //      }

         //   }

         //   return retValue;

         //}


         //DeviceInformation message_io::GetDeviceInformationForOutPort(::winrt::hstring friendlyName)
         //{
         //   DeviceInformation retValue = nullptr;
         //   DeviceInformationCollection inputCollection = m_pmidiOutDeviceWatcher->GetDeviceInformationCollection();

         //   for (::collection::index i = 0; i < inputCollection.Size(); i++)
         //   {

         //      DeviceInformation devInfo = inputCollection.GetAt(i);

         //      if (0 == wcscmp(devInfo.Name().begin(), friendlyName.begin()))
         //      {

         //         retValue = devInfo;
         //         break;

         //      }
         //   }

         //   return retValue;

         //}

         //void message_io::CloseInPort(::winrt::hstring portId)
         //{
         //   for (unsigned int index = 0; index < _midiInPortArray.get_size(); index++)
         //   {
         //      if (0 == wcscmp(_midiInPortArray[index].get().DeviceId().begin(), portId.begin()))
         //      {
         //         _midiInPortArray.erase_at(index);

         //         return;
         //      }
         //   }
         //}

         //void message_io::CloseOutPort(::winrt::hstring  portId)
         //{
         //   for (unsigned int index = 0; index < _midiOutPortArray.get_size(); index++)
         //   {
         //      if (0 == wcscmp(_midiOutPortArray[index].get().DeviceId().begin(), portId.begin()))
         //      {
         //         _midiOutPortArray.erase_at(index);

         //         return;
         //      }
         //   }
         //}

         //message_io::MidiDeviceWatcher::MidiDeviceWatcher(message_io * pio, const ::string & strMidiSelector)
         //   : m_pio(pio),m_strMidiSelector(strMidiSelector) // ,
         //   _deviceWatcher(nullptr),
         //   _devInfoCollection(nullptr),
         //   _enumCompleted(false)
         //{
         //   _deviceWatcher = DeviceInformation::CreateWatcher(as_hstring(strMidiSelector));

         //   _portAddedToken = _deviceWatcher.Added({ this, &MidiDeviceWatcher::OnPortAdded });
         //   _portRemovedToken = _deviceWatcher.Removed({ this, &MidiDeviceWatcher::OnPortRemoved });
         //   _portUpdatedToken = _deviceWatcher.Updated({ this, &MidiDeviceWatcher::OnPortUpdated });
         //   _portEnumCompleteToken = _deviceWatcher.EnumerationCompleted({ this, &MidiDeviceWatcher::OnPortEnumCompleted });
         //}

         //message_io::MidiDeviceWatcher::~MidiDeviceWatcher()
         //{
         //   _deviceWatcher.Added(_portAddedToken);
         //   _deviceWatcher.Removed(_portRemovedToken);
         //   _deviceWatcher.Updated(_portUpdatedToken);
         //   _deviceWatcher.EnumerationCompleted(_portEnumCompleteToken);
         //}

         //void message_io::MidiDeviceWatcher::Start()
         //{
         //   _deviceWatcher.Start();
         //}

         //void message_io::MidiDeviceWatcher::Stop()
         //{
         //   _deviceWatcher.Stop();
         //}

         //DeviceInformationCollection message_io::MidiDeviceWatcher::GetDeviceInformationCollection()
         //{
         //   return _devInfoCollection;
         //}

         //
         //void message_io::MidiDeviceWatcher::UpdatePorts()
         //{

         //   DeviceInformationCollection deviceInfoCollection = DeviceInformation::FindAllAsync(as_hstring(m_strMidiSelector)).get();

         //   m_pio->clear_out_ports();

         //   if ((deviceInfoCollection == nullptr) || (deviceInfoCollection.Size() == 0))
         //   {


         //   }
         //   else
         //   {

         //      _devInfoCollection = deviceInfoCollection;

         //      for (::collection::index i = 0; i < deviceInfoCollection.Size(); i++)
         //      {

         //         DeviceInformation devInfo = deviceInfoCollection.GetAt(i);

         //         m_pio->add_out_port(devInfo.Name());

         //      }

         //   }

         //}

         //void message_io::MidiDeviceWatcher::OnPortAdded(DeviceWatcher const & deviceWatcher, DeviceInformation const & devInfo)
         //{
         //   if (_enumCompleted)
         //   {
         //      create_task(_coreDispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::High,
         //         ref __new ::winrt::Windows::UI::Core::DispatchedHandler([this]()
         //      {
         //         UpdatePorts();
         //      })));
         //   }
         //}

         //void message_io::MidiDeviceWatcher::OnPortRemoved(DeviceWatcher const & deviceWatcher, DeviceInformationUpdate const & devInfoUpdate)
         //{
         //   if (_enumCompleted)
         //   {
         //      _coreDispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::High,
         //         ref __new ::winrt::Windows::UI::Core::DispatchedHandler([this]()
         //      {
         //         UpdatePorts();
         //      }));
         //   }
         //}

         //void message_io::MidiDeviceWatcher::OnPortUpdated(DeviceWatcher const & deviceWatcher, DeviceInformationUpdate const & devInfoUpdate)
         //{
         //   if (_enumCompleted)
         //   {
         //      _coreDispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::High,
         //         ref __new ::winrt::Windows::UI::Core::DispatchedHandler([this]()
         //      {
         //         UpdatePorts();
         //      }));
         //   }
         //}

         //void message_io::MidiDeviceWatcher::OnPortEnumCompleted(DeviceWatcher const & deviceWatcher, IInspectable  const & obj)
         //{
         //   _enumCompleted = true;

         //   _coreDispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::High,
         //      ref __new ::winrt::Windows::UI::Core::DispatchedHandler([this]()
         //   {
         //      UpdatePorts();
         //   }));
         //}


         //int message_io::get_out_port_count()
         //{

         //   return m_straOut.get_size();

         //}


         //::winrt::hstring message_io::get_out_port_name(int i)
         //{

         //   return as_hstring(m_straOut[i]);

         //}


         //void message_io::select_out_port(::winrt::hstring str)
         //{

         //   _midiOutPortArray.erase_all();

         //   DeviceInformation portToOpen = GetDeviceInformationForOutPort(str);

         //   if (portToOpen != nullptr)
         //   {
         //      
         //      auto outPort = MidiOutPort::FromIdAsync(portToOpen.Id()).get();

         //      if (outPort != nullptr)
         //      {

         //         _midiOutPortArray.add(outPort);

         //      }

         //   }

         //}

         //void message_io::add_out_port(::winrt::hstring portId)
         //{

         //   m_straOut.add(portId.begin());

         //}

         //void message_io::clear_out_ports()
         //{

         //   m_straOut.erase_all();

         //}


         //void message_io::send(MidiMessageType etype)
         //{

         //   IMidiMessage^ midiMessage;

         //   switch (etype)
         //   {
         //      //case MidiMessageType::NoteOff:

         //      //   midiMessage = ref __new MidiNoteOffMessage(_field1IntValue, _field2IntValue, _field3IntValue);
         //      //   break;

         //   case MidiMessageType::NoteOn:

         //      //midiMessage = ref __new MidiNoteOnMessage(iChannel, uchNote, uchVelocity);
         //      break;

         //      //case MidiMessageType::PolyphonicKeyPressure:

         //      //   midiMessage = ref __new MidiPolyphonicKeyPressureMessage(_field1IntValue, _field2IntValue, _field3IntValue);
         //      //   break;

               //case MidiMessageType::ControlChange:

               //   midiMessage = ref __new MidiControlChangeMessage(_field1IntValue, _field2IntValue, _field3IntValue);
               //   break;

               //case MidiMessageType::ProgramChange:

               //   midiMessage = ref __new MidiProgramChangeMessage(_field1IntValue, _field2IntValue);
               //   break;

               //case MidiMessageType::ChannelPressure:

               //   midiMessage = ref __new MidiChannelPressureMessage(_field1IntValue, _field2IntValue);
               //   break;

               //case MidiMessageType::PitchBendChange:

               //   midiMessage = ref __new MidiPitchBendChangeMessage(_field1IntValue, _field2IntValue);
               //   break;

               //case MidiMessageType::SystemExclusive:
               //{
               //   DataWriter^ dataWriter = ref __new DataWriter();

               //   // expecting a string of format "NN NN NN NN...." where NN is a ::u8 in hex
               //   int len = _sendMessageTextBox->Text->Length();
               //   if (0 == len)
               //   {
               //      return;
               //   }

               //   const wchar_t* startPointer = _sendMessageTextBox->Text->Data();
               //   wchar_t* endPointer = nullptr;

               //   do
               //   {
               //      ::u8 midiByte = (::u8)wcstoul(startPointer, &endPointer, 16);
               //      if (endPointer == startPointer)
               //      {
               //         // conversion failed, bail out
               //         break;
               //      }

               //      dataWriter->WriteByte(midiByte);

               //      // prep for next iteration
               //      startPointer = endPointer;
               //   } while (nullptr != endPointer);

               //   midiMessage = ref __new MidiSystemExclusiveMessage(dataWriter->DetachBuffer());
               //   break;
               //}
               //case MidiMessageType::MidiTimeCode:

               //   midiMessage = ref __new MidiTimeCodeMessage(_field1IntValue, _field2IntValue);
               //   break;

               //case MidiMessageType::SongPositionPointer:

               //   midiMessage = ref __new MidiSongPositionPointerMessage(_field1IntValue);
               //   break;

               //case MidiMessageType::SongSelect:

               //   midiMessage = ref __new MidiSongSelectMessage(_field1IntValue);
               //   break;

               //case MidiMessageType::TuneRequest:

               //   midiMessage = ref __new MidiTuneRequestMessage();
               //   break;

               //case MidiMessageType::TimingClock:

               //   midiMessage = ref __new MidiTimingClockMessage();
               //   break;

               //case MidiMessageType::Start:

               //   midiMessage = ref __new MidiStartMessage();
               //   break;

               //case MidiMessageType::Continue:

               //   midiMessage = ref __new MidiContinueMessage();
               //   break;

               //case MidiMessageType::Stop:

               //   midiMessage = ref __new MidiStopMessage();
               //   break;

               //case MidiMessageType::ActiveSensing:

               //   midiMessage = ref __new MidiActiveSensingMessage();
               //   break;

               //case MidiMessageType::SystemReset:

               //   midiMessage = ref __new MidiSystemResetMessage();
               //   break;

               //case MidiMessageType::None:
         //   default:
         //      return;
         //   }

         //   send(midiMessage);

         //}

      } // namespace winrt

   } // namespace midi

} // namespace music



