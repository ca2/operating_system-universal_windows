#include "framework.h"


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         out::out(::layered * pobjectContext) :
            ::object(pobject),
            ::music::midi::object(pobject),
            ::music::midi::out(pobject)
         {

            //m_hmidiout = NULL;

         }


         out::~out()
         {

            close();

         }


         ::multimedia::e_result out::open()
         {

            HRESULT mmrc;

            //uint32_t uDeviceID = 0;

            //m_hmidiout = NULL;

            //mmrc = midiOutOpen(&m_hmidiout, uDeviceID,  0, 0, CALLBACK_NULL);

            //if(mmrc != MMSYSERR_NOERROR)
            //   return ::multimedia::result_error;


            return ::multimedia::result_success;

         }

         ::multimedia::e_result out::close()
         {

            //if(m_hmidiout != NULL)
            //{

            //   midiOutClose(m_hmidiout);

            //}

            return ::multimedia::result_success;

         }

         ::multimedia::e_result out::send_short_message(::music::midi::e_type etype, int iChannel, int iData1, int iData2)
         {

            //return translate_mmr(midiOutShortMsg(m_hmidiout, MIDIMSG(((int) etype) >> 4, iChannel, iData1, iData2)));
            return ::multimedia::result_success;

         }


      } //


   } // namespace midi_winrt


} // namespace music




