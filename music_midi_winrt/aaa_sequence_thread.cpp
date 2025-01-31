#include "framework.h"


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         sequence_thread::sequence_thread(::particle * pparticle) :
            ::object(pobject),
            thread(pobject),
            ::music::midi::sequence_thread(pobject)
         {

         }

         sequence_thread::~sequence_thread()
         {
         }


         bool sequence_thread::init_thread()
         {

            set_thread_priority(::multithreading::e_priority_highest);

            return true;

         }


         void sequence_thread::term_thread()
         {

            thread::term_thread();

         }


         void sequence_thread::install_message_routing(::message::sender * pinterface)
         {
            ::music::midi::sequence_thread::install_message_routing(pinterface);
//            IGUI_WIN_MSG_LINK(::music::midi::player::message_command, pinterface, this, &sequence_thread::OnCommand);
            IGUI_MSG_LINK(::music::midi::sequence::message_event, pinterface, this, &sequence_thread::OnMidiSequenceEvent);
         }

         void sequence_thread::Stop(imedia_time msEllapse)
         {
            get_sequence()->Stop();
            m_happeningStop.wait(::duration(msEllapse));
         }

         ::music::midi::sequence * sequence_thread::get_sequence()
         {
            return m_psequence;
         }


         bool sequence_thread::PostMidiSequenceEvent(::music::midi::sequence * pseq, ::music::midi::sequence::e_happening ehappening)
         {

            return post_object(::music::midi::sequence::message_event,  (WPARAM) pseq, pseq->create_new_event(ehappening));

         }


         bool sequence_thread::PostMidiSequenceEvent(::music::midi::sequence * pseq, ::music::midi::sequence::e_happening ehappening, LPMIDIHDR lpmh)
         {

            sp(sequence) seq = pseq;

            return post_object(::music::midi::sequence::message_event,  (WPARAM) pseq, seq->create_new_event(ehappening));

         }

         void sequence_thread::OnMidiSequenceEvent(::message::message * pobj)
         {

            ::pointer<::user::message>pusermessage(pobj);

            sp(::music::midi::sequence::happening) pevent(pusermessage->m_lparam);

            ::music::midi::winrt::sequence * pseq = dynamic_cast < ::music::midi::winrt::sequence * > (ptopic->m_psequence);

            pseq->OnHappening(pevent);

            switch(ptopic->id())
            {
            case ::music::midi::sequence::e_event_midi_playback_end:
            {

               ::music::midi::sequence::PlayerLink & link = get_sequence()->GetPlayerLink();

               if(link() & ::music::midi::sequence::FlagStop)
               {

                  link() -= ::music::midi::sequence::FlagStop;

                  link.OnFinishCommand(::music::midi::player::command_stop);

                  PostNotifyEvent(::music::midi::player::notify_event_playback_end);

               }
               else if(link() & ::music::midi::sequence::e_flag_tempo_change)
               {

                  PrerollAndWait(link.m_tkRestart);

                  get_sequence()->SetTempoChangeFlag(false);

                  get_sequence()->Start();

                  link() -= ::music::midi::sequence::e_flag_tempo_change;

               }
               else if(link() & ::music::midi::sequence::e_flag_setting_position)
               {

                  link() -= ::music::midi::sequence::e_flag_setting_position;

                  try
                  {

                     PrerollAndWait(link.m_tkRestart);

                  }
                  catch(exception *pe)
                  {

                     ::exception_sp esp(pe);

                     return;

                  }

                  get_sequence()->Start();

                  PostNotifyEvent(::music::midi::player::notify_event_position_set);

               }
               else if(link() & ::music::midi::sequence::FlagMidiOutDeviceChange)
               {

                  link() -= ::music::midi::sequence::FlagMidiOutDeviceChange;

                  try
                  {

                     PrerollAndWait(link.m_tkRestart);

                  }
                  catch(exception *pe)
                  {

                     ::exception_sp esp(pe);

                     return;

                  }

                  get_sequence()->Start();

               }
               else if(link() & ::music::midi::sequence::FlagStopAndRestart)
               {

                  link() -= ::music::midi::sequence::FlagStopAndRestart;

                  try
                  {

                     PrerollAndWait(link.m_tkRestart);

                  }
                  catch(exception *pe)
                  {

                     ::exception_sp esp(pe);

                     return;

                  }

                  get_sequence()->Start();

               }
               else
               {

                  PostNotifyEvent(::music::midi::player::notify_event_playback_end);

               }

            }
            break;
            case ::music::midi::sequence::EventSpecialModeV001End:
            {
               PostNotifyEvent(::music::midi::player::notify_event_generic_mmsg_done);
            }
            break;

            case ::music::midi::sequence::EventMidiPlaybackStart:
            {
               pseq->seq_start();

               PostNotifyEvent(::music::midi::player::notify_event_playback_start);

            }
            break;
            case ::music::midi::sequence::e_event_midi_stream_out:
            {
               PostNotifyEvent(::music::midi::player::notify_event_midi_stream_out);
            }
            break;
               //case ::music::midi::sequence::e_event_midi_playback_end:
               //{
               //   PostNotifyEvent(::music::midi::player::notify_event_playback_end);
               //}
               //break;

            }

            //delete pevent;


         }


         void sequence_thread::PostNotifyEvent(::music::midi::player::e_notify_event ehappening)
         {

            if(m_pplayer != NULL)
            {

               sp(::music::midi::player::notify_event) pdata(canew(::music::midi::player::notify_event));

               pdata->m_enotifyevent = ehappening;

               m_pplayer->post_object(::music::midi::player::message_notify_event, 0, pdata);

            }

         }


         void sequence_thread::Play(imedia_position tickStart)
         {
            ASSERT(get_sequence() != NULL);
            ASSERT(get_sequence()->get_status() == ::music::midi::sequence::status_opened);

            PrerollAndWait(tickStart);

            get_sequence()->Start();

         }


         void sequence_thread::PlayRate(double dRate)
         {

            ASSERT(get_sequence() != NULL);

            ASSERT(get_sequence()->get_status() == ::music::midi::sequence::status_opened);

            PrerollRateAndWait(dRate);

            get_sequence()->Start();

         }


         void sequence_thread::PrerollAndWait(imedia_position tickStart)
         {

            ::music::midi::PREROLL                 preroll;

            preroll.tickBase = tickStart;
            preroll.tickEnd  = get_sequence()->m_tkLength;

            get_sequence()->SetMidiOutDevice(m_pplayer->GetMidiOutDevice());

            try
            {
               get_sequence()->Preroll(this, &preroll, true);
            }
            catch (exception * pme)
            {
               string str;
               ASSERT(false);

               /* super merge module      CVmsMusDll::load_string(str, IDS_PREROLLUSERERROR001);
               pme->SetUserText(str);*/
               throw pme;
            }

         }


         void sequence_thread::PrerollRateAndWait(double dRate)
         {

            ::music::midi::PREROLL                 preroll;

            ::math::math::MaxClip(&dRate, 1.0);
            ::math::math::MinClip(&dRate,  0.0);

            preroll.tickBase = (imedia_position) (int32_t) ((double) get_sequence()->m_tkLength * dRate);

            preroll.tickEnd  = get_sequence()->m_tkLength;

            get_sequence()->SetMidiOutDevice(m_pplayer->GetMidiOutDevice());

            try
            {

               get_sequence()->Preroll(this, &preroll, true);

            }
            catch (exception * pme)
            {

               throw ::not_implemented();
               /*string str;
               str.load_string(IDS_PREROLLUSERERROR001);
               pme->SetUserText(str);*/
               throw pme;
            }

            //    if(!get_sequence()->IsInSpecialModeV001())
            //  {
            //    SendMessage(m_oswindow_, WM_USER, 33, preroll.tickBase);
            //}
         }


         void sequence_thread::PostGMReset()
         {
            ASSERT(!get_sequence()->IsPlaying());
            get_sequence()->SetSpecialModeV001Operation(::music::midi::sequence::SPMV001GMReset);
            PrerollAndWait(0.0);
            get_sequence()->Start();

         }

         void sequence_thread::PostTempoChange()
         {
            ASSERT(!get_sequence()->IsPlaying());
            get_sequence()->SetSpecialModeV001Operation(::music::midi::sequence::SPMV001TempoChange);
            PrerollAndWait(0.0);
            get_sequence()->Start();
         }

         void sequence_thread::SendTempoChange()
         {
            ASSERT(!get_sequence()->IsPlaying());
            get_sequence()->m_happeningMmsgDone.reset_happening();
            PostTempoChange();
            get_sequence()->m_happeningMmsgDone.wait();
         }


         void sequence_thread::_ExecuteCommand(::music::midi::player::command * spcommand)
         {
            switch(spcommand->GetCommand())
            {
            case ::music::midi::player::command_play:
            {
               if(spcommand->m_flags.is_signalized(::music::midi::player::command::flag_dRate))
               {
                  Play(spcommand->m_dRate);
               }
               else if(spcommand->m_flags.is_signalized(::music::midi::player::command::flag_ticks))
               {
                  Play(spcommand->m_ticks);
               }
               else
               {
                  PlayRate();
               }
               spcommand->OnFinish();
            }
            break;
            case ::music::midi::player::command_close_device:
            {
               if(get_sequence() != NULL)
               {
                  get_sequence()->close_file();
               }
               spcommand->OnFinish();
            }
            break;
            case ::music::midi::player::command_fade_out_and_stop:
            {

               m_happeningStop.reset_happening();

               ::e_status            mmrc;

               sequence::PlayerLink & link = get_sequence()->GetPlayerLink();

               link.SetCommand(spcommand);

               link() |= sequence::FlagFadeOutAndStop;

               if (::success != (mmrc = get_sequence()->FadeOutAndStop()))
               {

                  _throw(exception(::music::EMidiPlayerStop, mmrc));

               }

            }
            break;
            case ::music::midi::player::command_stop:
            {

               m_happeningStop.reset_happening();

               ::e_status            mmrc;

               ::music::midi::sequence::PlayerLink & link = get_sequence()->GetPlayerLink();

               link.SetCommand(spcommand);

               link() |= ::music::midi::sequence::FlagStop;

               //if(MMSYSERR_NOERROR != (mmrc = get_sequence()->Stop()))
               //{
               //   throw ___new exception(EMidiPlayerStop);
               //}
            }
            break;
            case ::music::midi::player::command_stop_and_restart:
            {

               ::e_status            mmrc;

               ::music::midi::sequence::PlayerLink & link = get_sequence()->GetPlayerLink();

               link.SetCommand(spcommand);

               link() |=::music::midi::sequence::FlagStopAndRestart;

               link.m_tkRestart = get_sequence()->get_position_ticks();

               if(::success != (mmrc = get_sequence()->Stop()))
               {

                  throw ___new exception(EMidiPlayerStop);

               }

            }

            break;
            }

         }


      } // namespace winrt


   } // namespace midi


} // namespace music









