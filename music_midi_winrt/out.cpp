#include "framework.h"
#include "out.h"
#include "midi.h"
#include "acme_universal_windows/_winrt_stream.h"
#include "app-veriwell/multimedia/music/midi/sequencer.h"


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         out::out()
         {

            //m_hmidiout = NULL;

         }


         out::~out()
         {

            close();

         }


         void out::open()
         {

            //HRESULT mmrc;

            //uint32_t uDeviceID = 0;

            //m_hmidiout = NULL;

            //mmrc = midiOutOpen(&m_hmidiout, uDeviceID,  0, 0, CALLBACK_NULL);

            //if(mmrc != MMSYSERR_NOERROR)
            //   return ::error_failed;


            //return ::success;

         }


         void out::close()
         {

            //if(m_hmidiout != NULL)
            //{

            //   midiOutClose(m_hmidiout);

            //}

            //return ::success;

         }


         void out::send_short_message(::music::midi::enum_midi_message emessage, int iChannel, int iData1, int iData2)
         {

            //return translate_mmr(midiOutShortMsg(m_hmidiout, MIDIMSG(((int) etype) >> 4, iChannel, iData1, iData2)));
            //return ::success;

         }


         bool out::sends_on_message() const
         {

            return true;

         }


         bool out::midi_message_step()
         {

            auto IBuffer = windows_runtime_buffer(m_memoryBuffer.data(), m_memoryBuffer.size());

            m_midiOutPort.get().SendBuffer(IBuffer);

            m_memoryBuffer.clear();

            return true;

         }


         void out::send(::winrt::Windows::Devices::Midi::IMidiMessage const & message)
         {
            //for (auto out : _midiOutPortArray)
            //{
              //m_midiOutPort.get().SendMessage(message);

            //}

            auto rawData = message.RawData();

            m_memoryBuffer.append(rawData.data(), rawData.Length());

         }


         void out::note_on(int iChannel, unsigned char uchNote, unsigned char uchVelocity)
         {

            iChannel = minimum_maximum(iChannel, 0, 15);

            uchNote = minimum_maximum(uchNote, 0, 127);

            uchVelocity = minimum_maximum(uchVelocity, 0, 127);

            ::winrt::Windows::Devices::Midi::MidiNoteOnMessage message(iChannel, uchNote, uchVelocity);

            send(message);

            //return ::success;

         }


         void out::note_off(int iChannel, unsigned char uchNote, unsigned char uchVelocity)
         {

            iChannel = minimum_maximum(iChannel, 0, 15);

            uchNote = minimum_maximum(uchNote, 0, 127);

            uchVelocity = minimum_maximum(uchVelocity, 0, 127);

            ::winrt::Windows::Devices::Midi::MidiNoteOffMessage message(iChannel, uchNote, uchVelocity);

            send(message);

            //return ::success;

         }


         void out::program_change(int iChannel, unsigned char uchProgram)
         {

            ::winrt::Windows::Devices::Midi::MidiProgramChangeMessage message(iChannel, uchProgram);

            send(message);

            //return ::success;

         }


         void out::control_change(int iChannel, unsigned char uchController, unsigned char uchValue)
         {

            ::winrt::Windows::Devices::Midi::MidiControlChangeMessage message(iChannel, uchController, uchValue);

            send(message);

         }


         void out::pitch_bend(int iChannel, unsigned short ushBend)
         {

            ::winrt::Windows::Devices::Midi::MidiPitchBendChangeMessage message(iChannel, ushBend);

            send(message);

         }


         ::pointer<::music::midi::sequencer>midi::create_midi_sequencer(sequence * psequence, const string & strDevice)
         {

            string strEngine = device_engine(strDevice);

            if (strEngine.case_insensitive_equals(m_strName))
            {

               return ::place(new sequencer(psequence, get_message_out(strDevice)));

            }

            auto psequencer = ::music::midi::midi::create_midi_sequencer(psequence, strDevice);

            if (psequencer)
            {

               return psequencer;

            }

            return ::place(new sequencer(psequence, get_message_out(strDevice)));

         }


      } //


   } // namespace midi_winrt


} // namespace music



