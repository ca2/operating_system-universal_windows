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

         void out::send(IMidiMessage const & message)
         {
            //for (auto out : _midiOutPortArray)
            //{
              m_midiOutPort.get().SendMessage(message);

            //}

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



      } //


   } // namespace midi_winrt


} // namespace music




