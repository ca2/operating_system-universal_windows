#include "framework.h"


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




         ::e_status out::open()
         {

            HRESULT mmrc;

            //uint32_t uDeviceID = 0;

            //m_hmidiout = NULL;

            //mmrc = midiOutOpen(&m_hmidiout, uDeviceID,  0, 0, CALLBACK_NULL);

            //if(mmrc != MMSYSERR_NOERROR)
            //   return ::error_failed;


            return ::success;

         }

         ::e_status out::close()
         {

            //if(m_hmidiout != NULL)
            //{

            //   midiOutClose(m_hmidiout);

            //}

            return ::success;

         }

         ::e_status out::send_short_message(::music::midi::e_message emessage, int iChannel, int iData1, int iData2)
         {

            //return translate_mmr(midiOutShortMsg(m_hmidiout, MIDIMSG(((int) etype) >> 4, iChannel, iData1, iData2)));
            return ::success;

         }

         ::e_status out::step()
         {

            auto IBuffer = windows_runtime_buffer(m_memoryBuffer.get_data(), m_memoryBuffer.get_size());

            m_midiOutPort.get().SendBuffer(IBuffer);

            m_memoryBuffer.clear();

            return ::success;

         }


         void out::send(IMidiMessage const & message)
         {
            //for (auto out : _midiOutPortArray)
            //{
              //m_midiOutPort.get().SendMessage(message);

            //}

            auto rawData = message.RawData();

            m_memoryBuffer.append(rawData.data(), rawData.Length());

         }


         ::e_status out::note_on(int iChannel, unsigned char uchNote, unsigned char uchVelocity)
         {

            iChannel = clip(0, 15, iChannel);

            uchNote = clip(0, 127, uchNote);

            uchVelocity = clip(0, 127, uchVelocity);

            MidiNoteOnMessage message(iChannel, uchNote, uchVelocity);

            send(message);

            return ::success;

         }


         ::e_status out::note_off(int iChannel, unsigned char uchNote, unsigned char uchVelocity)
         {

            iChannel = clip(0, 15, iChannel);

            uchNote = clip(0, 127, uchNote);

            uchVelocity = clip(0, 127, uchVelocity);

            MidiNoteOffMessage message(iChannel, uchNote, uchVelocity);

            send(message);

            return ::success;

         }


         ::e_status out::program_change(int iChannel, unsigned char uchProgram)
         {

            MidiProgramChangeMessage message(iChannel, uchProgram);

            send(message);

            return ::success;

         }


         void out::control_change(int iChannel, unsigned char uchController, unsigned char uchValue)
         {

            MidiControlChangeMessage message(iChannel, uchController, uchValue);

            send(message);

         }

         void out::pitch_bend(int iChannel, unsigned short ushBend)
         {


            MidiPitchBendChangeMessage message(iChannel, ushBend);

            send(message);

         }


         __pointer(::music::midi::sequencer) midi::create_midi_sequencer(sequence * psequence, const string & strDevice)
         {

            string strEngine = device_engine(strDevice);

            if (strEngine.compare_ci(m_strName) == 0)
            {

               return __new(sequencer(psequence, get_message_out(strDevice)));

            }

            auto psequencer = ::music::midi::midi::create_midi_sequencer(psequence, strDevice);

            if (psequencer)
            {

               return psequencer;

            }

            return __new(sequencer(psequence, get_message_out(strDevice)
            ));

         }


      } //


   } // namespace midi_winrt


} // namespace music




