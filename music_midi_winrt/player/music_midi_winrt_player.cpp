#include "framework.h"


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         namespace player
         {


            player::player()
            {


               m_puserinteraction               = NULL;

            }

            player::~player()
            {

            }


            bool player::init_thread()
            {

               ///m_psequencethread->ResumeThread();

               informationf("player::initialize_instance %X\n", get_os_int());
               //SetMainWnd(NULL);
               //ASSERT(GetMainWnd() == NULL);

               set_thread_priority(::multithreading::e_priority_normal);

               //m_happeningInitialized.set_happening();

               return true;

            }


            void player::term_thread()
            {
               // TODO:  perform any per-thread cleanup here
               //   if(!get_sequence()->IsNull())
               //   {
               //      delete get_sequence();
               //   }
               //    if(m_pmidicallbackdata != NULL)
               //  {
               //    delete m_pmidicallbackdata;
               ///  m_pmidicallbackdata = NULL;
               //}
               thread::term_thread();

            }


            void player::install_message_routing(::message::sender * pinterface)
            {
               ::music::midi::player::player::install_message_routing(pinterface);
               //IGUI_WIN_MSG_LINK(MM_MOM_DONE, pinterface, this, &player::OnMultimediaMidiOutputMessageDone);
               //IGUI_WIN_MSG_LINK(MM_MOM_POSITIONCB, pinterface, this, &player::OnMultimediaMidiOutputMessagePositionCB);
            }

            bool player::Play(imedia_position tickStart, uint32_t dwEllapse)
            {

               ::music::midi::player::command * pcommand = ___new ::music::midi::player::command(m_pobject);

               pcommand->m_ecommand = ::music::midi::player::command_play;
               pcommand->m_dwEllapse = dwEllapse;
               pcommand->m_flags.signalize(::music::midi::player::command::flag_ticks);
               pcommand->m_ticks = tickStart;

               m_psequencethread->ExecuteCommand(pcommand);

               bool bFinished = pcommand->wait_ready();

               pcommand->release();

               return bFinished;
            }

            bool player::PlayRate(double dRate, uint32_t dwEllapse)
            {

               ::music::midi::player::command * pcommand = ___new ::music::midi::player::command(m_pobject);

               pcommand->m_ecommand = ::music::midi::player::command_play;
               pcommand->m_dwEllapse = dwEllapse;
               pcommand->m_flags.signalize(::music::midi::player::command::flag_dRate);
               pcommand->m_dRate = dRate;

               m_psequencethread->ExecuteCommand(pcommand);

               bool bFinished = pcommand->wait_ready();

               pcommand->release();

               return bFinished;

            }

            imedia_position player::RateToTicks(double dRate)
            {
               ASSERT(dRate >= 0.0);
               ASSERT(dRate <= 1.0);
               return (imedia_position) (int32_t) (get_sequence()->m_tkLength * dRate);
            }



            bool player::IsPlaying()
            {
               ASSERT(!get_sequence()->IsNull());
               return (bool) get_sequence()->IsPlaying();

            }

            bool player::ExecuteCommand(::music::midi::player::e_command ecommand, uint32_t dwEllapse)
            {

               ::music::midi::player::command * pcommand = ___new ::music::midi::player::command(m_pobject);

               pcommand->m_ecommand = ecommand;
               pcommand->m_dwEllapse = dwEllapse;

               m_psequencethread->ExecuteCommand(pcommand);

               bool bFinished = pcommand->wait_ready();

               pcommand->release();

               return bFinished;
            }


            void player::CloseFile()
            {

               e_result            mmrc;

               if(success != (mmrc = get_sequence()->close_file()) && mmrc != EFunctionNotSupported)
               {

                  throw ___new exception(EMidiPlayerClose);

               }

            }

            void player::Pause()
            {

               if (get_sequence()->get_status() == ::music::midi::sequence::status_paused)
               {

                  get_sequence()->Restart();

               }
               else
               {

                  get_sequence()->Pause();

               }

            }

            void player::SetPosition(double dRate)
            {
               if (::music::midi::sequence::status_playing != get_sequence()->get_status() &&
                     ::music::midi::sequence::status_stopping != get_sequence()->get_status() &&
                     ::music::midi::sequence::status_opened != get_sequence()->get_status())
                  return;

               if(get_sequence()->IsPlaying())
               {

                  ::music::midi::sequence::PlayerLink & link = get_sequence()->GetPlayerLink();

                  link() |= ::music::midi::sequence::e_flag_setting_position;

                  link.m_tkRestart = RateToTicks(dRate);

                  get_sequence()->Stop();

               }

            }

            void player::OnMmsgDone(::music::midi::sequence * pSeq)
            {
               ASSERT(false);
               ASSERT(false);
               ASSERT(false);
               ASSERT(false);
               ASSERT(false);
               ASSERT(false);
               ASSERT(false);
               ASSERT(false);
               ASSERT(pSeq == get_sequence());
               if(pSeq->IsSettingPosition())
               {
                  get_sequence()->SetSettingPositionFlag(false);
                  try
                  {
                     //         PrerollAndWait(m_dNextPositionRate);
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
               }

            }

            void player::pre_translate_message(::message::message * pmessage)
            {

               ::pointer<::user::message>pusermessage(pmessage);

               //ASSERT(GetMainWnd() == NULL);
               //   if(pMsg->message == MM_MOM_DONE ||
               //      pMsg->message == MM_MOM_POSITIONCB ||
               //      pMsg->message == MM_MOM_OPEN ||
               //      pMsg->message == MM_MOM_OPEN)
               //   {
               //      OnMidiOutMessage(pMsg->message, pMsg->wParam, pMsg->lParam);
               //      return true;
               //   }
               if(pusermessage->m_puserinteraction == NULL)
               {
                  switch(pusermessage->id().long_long())
                  {
                  case WM_USER + 100:
                  {
                     LPDOUBLESTRUCT lpds = (LPDOUBLESTRUCT) pusermessage->m_wparam;
                     SetPosition(lpds->d);
                     delete lpds;
                  }
                  return;
                  }
               }
               if(pusermessage->id() == MMSG_DONE)
               {
                  OnMmsgDone((::music::midi::sequence *) pusermessage->m_wparam);
                  pusermessage->m_bRet = true;
                  return;
               }
               else if(pusermessage->id() == WM_USER)
               {
                  //      OnUserMessage(pMsg->wParam, pMsg->lParam);
               }

               return thread::pre_translate_message(pmessage);

            }


            void player::SaveFile(const ::scoped_string & scopedstrPathName)
            {

               e_result            mmrc;

               if((mmrc = get_sequence()->SaveFile(lpszPathName)) != success)
               {

                  throw ___new exception(EMidiPlayerSave);

               }

            }


            void player::OnUserMessage(::message::message * pmessage)
            {

               ::pointer<::user::message>pusermessage(pmessage);

               if(pusermessage->m_wparam == 3377)
               {

                  m_puserinteraction->send_message(WM_USER, pusermessage->m_wparam, pusermessage->m_lparam);

               }

            }


            void player::PostGMReset()
            {
               m_psequencethread->PostGMReset();
            }

            void player::PostTempoChange()
            {
               m_psequencethread->PostTempoChange();
            }

            void player::SendTempoChange()
            {
               m_psequencethread->SendTempoChange();
            }


            ::e_status player::Initialize(thread * pthread)
            {
               __UNREFERENCED_PARAMETER(pthread);
               return ::success;
            }

            //void player::SetView(CXfplayerView *pimpact)
            //{
            //    m_pView = pimpact;
            //}

            //::music::e_result player::SetInterface(player_interface * pinterface)
            //{
            //   m_pinterface = pinterface;
            //   get_sequence()->m_pthread   = m_psequencethread;
            //   m_psequencethread->m_psequence = &get_sequence();
            //   m_psequencethread->m_pplayer = this;
            //   PostNotifyEvent(::music::midi::player::notify_event_set_sequence);
            //   return success;
            //}


            bool player::SetMidiOutDevice(uint32_t uiDevice)
            {
               __UNREFERENCED_PARAMETER(uiDevice);
               OnMidiOutDeviceChange();
               return true;
            }



            bool player::SetTempoShift(int32_t iTempoShift)
            {
               //   if(IsPlaying())
               {
                  /*
                  get_sequence()->SetTempoChangeFlag();
                  ::music::midi::sequence::PlayerLink & link = get_sequence()->GetPlayerLink();
                  link.ModifyFlag(
                  ::music::midi::sequence::e_flag_tempo_change,
                  ::music::midi::sequence::FlagNull);
                  imedia_position tick = get_sequence()->GetPositionTicks();
                  get_sequence()->m_happeningMmsgDone.reset_happening();
                  link.m_tkRestart = tick + get_sequence()->m_tkBase;
                  //m_bChangingTempo = true;
                  get_sequence()->Stop();
                  //get_sequence()->m_happeningMmsgDone.lock();
                  */
                  bool bPlay = IsPlaying();
                  imedia_position ticks = 0;
                  if(bPlay)
                  {
                     ticks = get_sequence()->get_position_ticks();
                     get_sequence()->Stop();
                  }
                  if(!get_sequence()->SetTempoShift(iTempoShift))
                     return false;
                  if(bPlay)
                  {
                     get_sequence()->m_pthread->PrerollAndWait(ticks);
                     get_sequence()->Start();
                  }

               }
               return true;
            }


            void player::PostNotifyEvent(::music::midi::player::e_notify_event ehappening)
            {

               if(m_puserinteraction != NULL)
               {

                  sp(::music::midi::player::notify_event) pdata(canew(::music::midi::player::notify_event));

                  pdata->m_pplayer = this;

                  pdata->m_enotifyevent = ehappening;

                  m_puserinteraction->post_object(::music::midi::player::message_notify_event, 0, pdata);

               }

            }


            //void player::SendMmsgDone(::music::midi::sequence *pSeq, ::music::midi::LPMIDIDONEDATA lpmdd)
            //{
            //   if(m_puserinteraction != NULL)
            //   {
            //      m_puserinteraction->post_message(MMSG_DONE, (WPARAM) pSeq, (LPARAM) lpmdd);
            //   }

            //}

            uint32_t player::GetMidiOutDevice()
            {

               return papplication->midi()->GetMidiOutDevice();
            }

            void player::SetCallbackWindow(sp(::user::interaction) puie)
            {
               m_puserinteraction = puie;
            }


            void player::on_attribute_change(::message::message * pmessage)
            {

               ::pointer<::music::midi::attribute_message>pchange(pmessage);

               switch(pchange->m_eattribute)
               {
               case ::music::midi::attribute_midi_out_device:
                  OnMidiOutDeviceChange();
                  break;
               }

            }

            void player::OnMidiOutDeviceChange()
            {

               get_sequence()->SetMidiOutDevice(GetMidiOutDevice());

               if(get_sequence()->IsPlaying())
               {

                  imedia_position tickPosition = 0;

                  get_sequence()->get_position(tickPosition);

                  ::music::midi::sequence::PlayerLink & link = get_sequence()->GetPlayerLink();

                  link() |= ::music::midi::sequence::e_flag_tempo_change;

                  link.m_tkRestart = tickPosition;

                  get_sequence()->Stop();

               }

            }


            void player::OnMultimediaMidiOutputMessageDone(::message::message * pmessage)
            {

               ::pointer<::user::message>pusermessage(pmessage);

               //HMIDISTRM hmidistream = (HMIDISTRM) pusermessage->m_wparam;

               //LPMIDIHDR lpmidihdr = (LPMIDIHDR) pusermessage->m_lparam.m_lparam;

               //sp(sequence) sequence = get_sequence();

               //ASSERT(sequence->m_hstream == hmidistream);

               //sequence->OnDone(hmidistream, lpmidihdr);

            }

            void player::OnMultimediaMidiOutputMessagePositionCB(::message::message * pmessage)
            {
               ::pointer<::user::message>pusermessage(pmessage);
               //LPMIDIHDR lpmidihdr = (LPMIDIHDR) pusermessage->m_wparam;
               ////          get_sequence()->OnPositionCB(lpmidihdr);

               //sp(sequence) sequence = get_sequence();

               ////            ASSERT(sequence->m_hstream == hmidistream);

               //sequence->OnPositionCB(lpmidihdr);
            }




            void player::OnNotifyEvent(::message::message * pmessage)
            {

               ::pointer<::user::message>pusermessage(pmessage);

               sp(::music::midi::player::notify_event) pdata(pusermessage->m_lparam);

               pdata->m_pplayer = this;

               if(m_puserinteraction != NULL)
               {

                  m_puserinteraction->post_object(::music::midi::player::message_notify_event, 0, pdata);

               }

            }




            void player::SendReset()
            {
//               HMIDIOUT hmidiout = NULL;
//               ::e_status mmrc;
//               uint32_t uDeviceID = 0;
//               mmrc = translate_mmr(midiOutOpen(&hmidiout, uDeviceID,  0, 0, CALLBACK_NULL));
//               if(mmrc != MMSYSERR_NOERROR)
//                  return;
//               Sleep(284);
//               const uchar gmModeOn[] = {
//                  //        0x00, 0x00, 0x00, 0x00,
//                  //        0x00, 0x00, 0x00, 0x00,
//                  //        0x1b, 0x8a, 0x06, MEVT_TEMPO,
//                  0x00, 0x00, 0x00, 0x00,
//                  0x00, 0x00, 0x00, 0x00,
//                  0x06, 0x00, 0x00, MEVT_LONGMSG,
//                  0xf0, 0x7e, 0x7f, 0x09,
//                  0x01, 0xf7, 0x00, 0x00};
//               //        0x70, 0x01, 0x00, 0x00,
//               //      0x00, 0x00, 0x00, 0x00 };
//               //      0x09, 0x00, 0x00, MEVT_LONGMSG,
//               //      0x43, 0x10, 0x4c,
//               //    0x00, 0x00, 0x7e, 0x00,
//               //  0xf7, 0x00, 0x00, 0x00,};
//               MIDIHDR mh;
//               LPMIDIHDR lpmh = &mh;
//               lpmh->lpData = (char *) gmModeOn;
//               lpmh->dwBufferLength = sizeof(gmModeOn);
//               lpmh->dwBytesRecorded = 0;
//               lpmh->dwFlags = 0;
//               mmrc = translate_mmr(midiOutPrepareHeader( hmidiout, lpmh, sizeof(MIDIHDR)));
//               if(mmrc != MMSYSERR_NOERROR)
//                  goto End;
//               lpmh->dwBytesRecorded = sizeof(gmModeOn);
//               if(mmrc != MMSYSERR_NOERROR)
//                  goto End;
//               mmrc = translate_mmr(midiOutLongMsg( hmidiout, lpmh, sizeof(MIDIHDR)));
//               Sleep(284);
//               mmrc = translate_mmr(midiOutUnprepareHeader( hmidiout, lpmh, sizeof(MIDIHDR)));
//               if(mmrc != MMSYSERR_NOERROR)
//                  goto End;
//End:
//               midiOutClose( hmidiout);
            }


         } // namespace player


      } // namespace winrt


   } // namespace midi_winrt


} // namespace music









