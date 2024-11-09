#include "framework.h"


/* Windows sleep in 100ns units */
//BOOLEAN nanosleep(LONGLONG ns)
//{
//   manual_reset_happening ev(::get_thread_app());
//
//   TimeSpan delay;
//   delay.Duration = maximum((ns / 100), 1) - 1;
//   ThreadPoolTimer ^ PeriodicTimer =
//      ThreadPoolTimer::CreateTimer(ref ___new TimerElapsedHandler([&](ThreadPoolTimer ^) {topic.set_happening(); }), delay);
//
//   topic.wait();
//
//   return true;
//
//}

uint64_t get_micro()
{

   return nanosecond().m_i / 1000;

}

namespace music
{


   namespace midi
   {


      namespace winrt
      {


         thread::thread(::particle * pparticle) :
            ::object(pobject),
            ::thread(pobject),
            m_happeningRun(pobject)
         {

            m_pseq = NULL;

            m_happeningRun.set_happening();

            m_tkPosition = 0;

         }

         thread::~thread()
         {
            if (m_pseq->m_pthreadPlay == this)
            {

               m_pseq->m_pthreadPlay = NULL;

            }

         }


         void thread::run()
         {

            e_result smfrc;

            ::music::midi::happening * pevent = NULL;

            imedia_position tickMax = ::numeric_info <imedia_position>::get_maximum_value();

            imedia_position tickPosition;

            bool bGotEvent = false;

            sequence_thread * pthread = dynamic_cast < sequence_thread * > (m_pseq->m_pthread);

            m_uiStart = ::get_micro() - m_pseq->TicksToMillisecs(m_pseq->m_tkBase) * 1000;

            for (int iTrack = 0; iTrack < 16; iTrack++)
            {

               clip(0, 127, m_pseq->m_iaRefVolume.element_at_grow(iTrack));

               if (m_pseq->m_pfile->m_keyframe.rbControl[iTrack][7] == KF_EMPTY)
               {

                  m_pseq->m_iaRefVolume[iTrack] = 100;

               }
               else
               {

                  m_pseq->m_iaRefVolume[iTrack] = m_pseq->m_pfile->m_keyframe.rbControl[iTrack][7];

               }


            }

            imedia_position tickLastBend = 0;

            m_tkPosition = 0;

            uint64_t uiNow;

            uint64_t uiFile;

            int_map < int_map < int > > map;

            bool bProcessed;

            bool bEqual = false;

            m_happeningRun.wait();

            if (!task_get_run())
            {

               goto end_playback;

            }
            uint64_t dwLastEffect = 0;

            while (task_get_run())
            {

               if (m_pseq == NULL || m_pseq->file() == NULL)
               {

                  break;

               }

               if (m_pseq->file()->m_flags & file::EndOfFile)
               {

                  break;

               }

               if (m_pseq->get_status() != sequence::status_playing)
               {

                  break;

               }


               bProcessed = true;

               if (!bGotEvent)
               {

                  smfrc = m_pseq->file()->WorkGetNextEvent(pevent, tickMax, true);

                  if (::music::success != smfrc)
                  {

                     break;

                  }

                  bGotEvent = true;

               }

               tickPosition = m_pseq->file()->GetPosition();

               uiNow = ::get_micro() - m_uiStart;

               double dVolume = 1.0;

               if (uiNow - dwLastEffect > 100 * 1000)
               {

                  dwLastEffect = uiNow;

                  if (m_pseq->m_eeffect == sequence::effect_fade_in || m_pseq->m_eeffect == sequence::effect_fade_out)
                  {

                     dVolume = m_pseq->get_fade_volume(m_pseq->TicksToMillisecs(tickPosition));

                     for (int iTrack = 0; iTrack < 16; iTrack++)
                     {

                        clip(0, 127, m_pseq->m_iaRefVolume[iTrack]);

                        unsigned char bVolume = (unsigned char)(m_pseq->m_iaRefVolume[iTrack] * maximum(0.0, minimum(1.0, dVolume)));

                        m_pseq->m_io->control_change(ptopic->GetTrack(), 7, bVolume);
                     }

                  }

               }

               uiFile = m_pseq->TickToMicro(tickPosition);

               if (uiNow < uiFile)
               {

                  if (uiFile - uiNow >= 2000)
                  {

                     Sleep(1);

                  }
                  else
                  {
                     Sleep(0);
                  }

               }
               else
               {
                  if (uiNow - uiFile >= 20 * 1000)
                  {

                     for (auto & p1 : map)
                     {
                        for (auto & p2 : p1.m_element2)
                        {
                           if (p2.m_element2 >= 0)
                           {

                              m_pseq->m_io->note_off(p1.m_element1, p2.m_element1, p2.m_element2);

                              p2.m_element2 = -1;

                           }
                        }
                     }

                  }

                  m_tkPosition = tickPosition;

                  if (ptopic->GetType() == ::music::midi::NoteOn)
                  {

                     if (uiNow - uiFile < 20 * 1000)
                     {

                        m_pseq->m_io->note_on(ptopic->GetTrack(), ptopic->GetNotePitch(), ptopic->GetNoteVelocity());

                        map[ptopic->GetTrack()][ptopic->GetNotePitch()] = ptopic->GetNoteVelocity();

                     }

                  }
                  else if (ptopic->GetType() == ::music::midi::NoteOff)
                  {

                     if (uiNow - uiFile < 20 * 1000)
                     {

                        m_pseq->m_io->note_off(ptopic->GetTrack(), ptopic->GetNotePitch(), ptopic->GetNoteVelocity());

                        map[ptopic->GetTrack()][ptopic->GetNotePitch()] = -1;

                     }

                  }
                  else if (ptopic->GetType() == ::music::midi::ProgramChange)
                  {

                     m_pseq->m_io->program_change(ptopic->GetTrack(), ptopic->GetProgram());

                  }
                  else if (ptopic->GetType() == ::music::midi::ControlChange)
                  {

                     if (ptopic->GetController() == 7)
                     {

                        m_pseq->m_iaRefVolume[ptopic->GetTrack()] = ptopic->GetControllerValue();
                     }

                     m_pseq->m_io->control_change(ptopic->GetTrack(), ptopic->GetController(), ptopic->GetControllerValue());

                  }
                  else if (ptopic->GetType() == ::music::midi::PitchBend)
                  {

                     int iChannel = ptopic->GetTrack();

                     uint16_t uiBend = ptopic->GetPitchBendLevel();

                     uint16_t uiBend2;

                     BYTE b1 = ((BYTE*)&uiBend)[0];

                     BYTE b2 = ((BYTE*)&uiBend)[1];

                     ((BYTE*)&uiBend2)[0] = b2;

                     ((BYTE*)&uiBend2)[1] = b1;

                     informationf("pitch_bend ch=%02d bend1=%05d bend2=%05d", iChannel, uiBend, uiBend2);

                     tickLastBend = tickPosition;

                     m_pseq->m_io->pitch_bend(iChannel, minimum(16383, uiBend));

                  }

                  bGotEvent = false;

               }

               if (::music::success != smfrc)
               {

                  break;

               }

            }

         end_playback:

            for (int i = 0; i < 16; i++)
            {
               for (int j = 0; j < 127; j++)
               {
                  m_pseq->m_io->note_off(i, j, 0);

               }
            }

            pthread->PostMidiSequenceEvent(m_pseq, ::music::midi::sequence::e_event_midi_playback_end, NULL);

            if (m_pseq->m_pthreadPlay == this)
            {

               m_pseq->m_pthreadPlay = NULL;

            }

         }


      } // namespace winrt


   } // namespace midi_winrt


} // namespace music





