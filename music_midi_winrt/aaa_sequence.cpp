#include "framework.h"


uint64_t get_micro();


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         sequence::sequence(::particle * pparticle) :
            ::object(pobject),
            ::music::midi::object(pobject),
            ::ikaraoke::karaoke(pobject),
            ::music::midi::sequence(pobject)
         {

            m_pthreadPlay = NULL;

//            m_hstream = NULL;

            //m_buffera.Initialize(16, m_cbPreroll, (uint_ptr) (void *) &m_midicallbackdata);
            m_midicallbackdata.m_psequence = this;


         };

         sequence::~sequence()
         {

            CloseFile();

         }


         /***************************************************************************
         *
         * seqAllocBuffers
         *
         * allocate buffers for this instance.
         *
         * pSeq                      - The sequencer instance to allocate buffers for.
         *
         * Returns
         *   ::success If the operation was successful.
         *
         *   MCIERR_OUT_OF_MEMORY  If there is insufficient memory for
         *     the requested number and int_size of buffers.
         *
         * seqAllocBuffers allocates playback buffers based on the
         * cbBuffer and cBuffer fields of pSeq. cbBuffer specifies the
         * number of bytes in each buffer, and cBuffer specifies the
         * number of buffers to allocate.
         *
         * seqAllocBuffers must be called before any other sequencer call
         * on a newly allocted SEQUENCE structure. It must be paired with
         * a call to seqFreeBuffers, which should be the last call made
         * before the SEQUENCE structure is discarded.
         *
         ***************************************************************************/
         ::e_status sequence::AllocBuffers()
         {
            ASSERT(false);
            /*
            uint32_t                   dwEachBufferSize;
            uint32_t                   dwAlloc;
            uint32_t                    i;
            LPBYTE                  lpbWork;

            //    assert(pSeq != NULL);

            set_status(status_no_file);
            m_lpmhFree  = NULL;
            m_lpbAlloc  = NULL;
            //    m_hSmf      = (HSMF)NULL;

            // First make sure we can allocate the buffers they asked for
            //
            dwEachBufferSize = sizeof(MIDIHDR) + (uint32_t)(m_cbBuffer);
            dwAlloc          = dwEachBufferSize * (uint32_t)(m_cBuffer);

            //m_lpbAlloc = (uchar *) GlobalAllocPtr(GMEM_MOVEABLE|GMEM_SHARE, dwAlloc);
            m_lpbAlloc = (uchar *) HeapAlloc(GetProcessHeap(), 0, dwAlloc);
            if (NULL == m_lpbAlloc)
            return MCIERR_OUT_OF_MEMORY;

            // Initialize all MIDIHDR's and throw them into a free list
            //
            m_lpmhFree = NULL;

            lpbWork = m_lpbAlloc;
            for (i=0; i < m_cBuffer; i++)
            {
            ((LPMIDIHDR)lpbWork)->lpNext            = m_lpmhFree;

            ((LPMIDIHDR)lpbWork)->lpData            = (char *) (lpbWork + sizeof(MIDIHDR));
            ((LPMIDIHDR)lpbWork)->dwBufferLength    = m_cbBuffer;
            ((LPMIDIHDR)lpbWork)->dwBytesRecorded   = 0;
            ((LPMIDIHDR)lpbWork)->dwUser            = (uint32_t)(uint32_t)this;
            ((LPMIDIHDR)lpbWork)->dwFlags           = 0;

            m_lpmhFree = (LPMIDIHDR)lpbWork;

            lpbWork += dwEachBufferSize;
            }

            return ::success;*/

            return ::error_failed;

         }

         /***************************************************************************
         *
         * seqFreeBuffers
         *
         * Free buffers for this instance.
         *
         * pSeq                      - The sequencer instance to free buffers for.
         *
         * seqFreeBuffers frees all allocated memory belonging to the
         * given sequencer instance pSeq. It must be the last call
         * performed on the instance before it is destroyed.
         *
         ****************************************************************************/
         VOID sequence::FreeBuffers()
         {
            ASSERT(false);
         }

         /***************************************************************************
         *
         * seqOpenFile
         *
         * Associates a MIDI file with the given sequencer instance.
         *
         * pSeq                      - The sequencer instance.
         *
         * Returns
         *   ::success If the operation is successful.
         *
         *   ::multimedia::result_unsupported_function If there is already a file open
         *     on this instance.
         *
         *   MCIERR_OUT_OF_MEMORY If there was insufficient memory to
         *     allocate internal buffers on the file.
         *
         *   MCIERR_INVALID_FILE If initial attempts to parse the file
         *     failed (such as the file is not a MIDI or RMI file).
         *
         * seqOpenFile may only be called if there is no currently open file
         * on the instance. It must be paired with a call to seqCloseFile
         * when operations on this file are complete.
         *
         * The pstrFile field of pSeq contains the name of the file
         * to open. This name will be passed directly to mmioOpen; it may
         * contain a specifcation for a custom MMIO file handler. The task
         * context used for all I/O will be the task which calls seqOpenFile.
         *
         ***************************************************************************/

         e_result sequence::OpenFile(::music::midi::sequence & sequence, int32_t openMode)
         {

            e_result                rc = success;
            SMFFILEINFO             sfi;
            e_result                smfrc;
            uint32_t                cbBuffer;

            if (get_status() != status_no_file)
            {

               return EFunctionNotSupported;

            }

            m_iOpenMode = openMode;

            smfrc = file()->OpenFile(*sequence.get_file(), openMode);


            if(::music::success != smfrc)
            {

               goto Seq_Open_File_Cleanup;

            }

            file()->GetFileInfo(&sfi);

            m_dwTimeDivision = sfi.dwTimeDivision;
            m_tkLength       = sfi.tickLength;
            if(m_iOpenMode == file::OpenForPlaying)
            {
               m_msLength      = TicksToMillisecs(m_tkLength);
            }
            /* Track buffers must be big enough to hold the state data returned
            ** by smfSeek()
            */
            cbBuffer = minimum(m_cbBuffer, ::music::midi::GetStateMaxSize());


Seq_Open_File_Cleanup:
            if (::success != rc)
               CloseFile();
            else
               set_status(status_opened);

            return rc;
         }


         e_result sequence::OpenFile(const ::string & lpFileName, int32_t openMode)
         {

            ::file::file_sp file;

            try
            {

               file = papplication->file().get_file(lpFileName, ::file::e_open_read | ::file::e_open_share_deny_write | ::file::e_open_binary);

            }
            catch(...)
            {

            }

            return OpenFile(*file, openMode);

         }


         e_result sequence::OpenFile(memory * pmemorystorage, int32_t openMode, e_storage estorage)
         {

            SMFFILEINFO                sfi;
            e_result                   smfrc;
            uint32_t                   cbBuffer;

            if (get_status() != status_no_file)
            {

               CloseFile();

            }

            m_iOpenMode = openMode;

            smfrc = file()->OpenFile(pmemorystorage, openMode, estorage);

            if (::music::success != smfrc)
            {

            }
            else
            {
               file()->GetFileInfo(&sfi);

               m_dwTimeDivision = sfi.dwTimeDivision;
               m_tkLength       = sfi.tickLength;
               if(m_iOpenMode == file::OpenForPlaying)
               {
                  m_msLength      = TicksToMillisecs(m_tkLength);
               }
               /* Track buffers must be big enough to hold the state data returned
               ** by smfSeek()
               */
               cbBuffer = minimum(m_cbBuffer, ::music::midi::GetStateMaxSize());
            }

            if(::music::success != smfrc)
               CloseFile();
            else
               set_status(status_opened);

            return smfrc;

         }

         e_result sequence::OpenFile(::file::file & ar, int32_t openMode)
         {

            SMFFILEINFO                sfi;
            e_result                   smfrc = success;
            uint32_t                   cbBuffer;

            if (get_status() != status_no_file)
            {

               return EFunctionNotSupported;

            }



            //   m_pstrFile = _tcsdup(lpFileName);
            //   m_strFile = lpFileName;

            //    ASSERT(m_pstrFile != NULL);

            m_iOpenMode = openMode;

            //    sofs.pstrName     = m_pstrFile;

            //PSMF pSmf = ___new SMF();

            //smfrc = file()->OpenFile(&sofs);
            smfrc = file()->OpenFile(ar, openMode);

            //smfrc = smfOpenFile(&sofs);
            if (::music::success != smfrc)
            {
            }
            else
            {
               //    m_hSmf = sofs.hSmf;
               //    ((PSMF) m_hSmf)->GetFileInfo(&sfi);
               file()->GetFileInfo(&sfi);

               m_dwTimeDivision = sfi.dwTimeDivision;
               m_tkLength       = sfi.tickLength;
               if(m_iOpenMode == file::OpenForPlaying)
               {
                  m_msLength      = TicksToMillisecs(m_tkLength);
               }
               /* Track buffers must be big enough to hold the state data returned
               ** by smfSeek()
               */
               cbBuffer = minimum(m_cbBuffer, ::music::midi::GetStateMaxSize());
            }

            if(success != smfrc)
               CloseFile();
            else
               set_status(status_opened);

            return smfrc;

         }


         /***************************************************************************
         *
         * seqCloseFile
         *
         * Deassociates a MIDI file with the given sequencer instance.
         *
         * pSeq                      -  The sequencer instance.
         *
         * Returns
         *   ::success If the operation is successful.
         *
         *   ::multimedia::result_unsupported_function If the sequencer instance is not
         *     stopped.
         *
         * A call to seqCloseFile must be paired with a prior call to
         * seqOpenFile. All buffers associated with the file will be
         * freed and the file will be closed. The sequencer must be
         * stopped before this call will be accepted.
         *
         ***************************************************************************/
         e_result sequence::CloseFile()
         {

            single_lock synchronouslock(m_mutex, true);

            //if (status_no_file == get_status())
            //   return ::multimedia::result_unsupported_function;

            file()->close_file();

            /* If we were prerolled, need to clean up -- have an open MIDI handle
            ** and buffers in the ready queue
            */

            //    single_lock slStream(&m_csStream, false);

            //    for (lpmh = m_lpmhFree; lpmh; lpmh = lpmh->lpNext)
            //    for (lpmh = m_buffera[0]; lpmh != NULL; lpmh = lpmh->lpNext)


            /*   m_lpmhFree = NULL;

            if (m_lpmhPreroll != NULL)
            {
            slStream.lock();
            if(m_hstream != NULL)
            {
            midiOutUnprepareHeader((HMIDIOUT) m_hstream, m_lpmhPreroll, sizeof(*m_lpmhPreroll));
            }
            slStream.unlock();
            }
            m_lpmhPreroll = NULL;*/
            //    slStream.lock();
            //if (m_hstream != NULL)
            //{
            //   m_buffera.midiOutUnprepareHeader((HMIDIOUT) m_hstream);
            //   midiStreamClose( m_hstream);
            //   m_hstream = NULL;
            //}
            //  slStream.unlock();

            set_status(status_no_file);

            return success;

         }


         /***************************************************************************
         *
         * seqPreroll
         *
         * Prepares the file for playback at the given position.
         *
         * pSeq                      - The sequencer instance.
         *
         * lpPreroll                 - Specifies the starting and ending tick
         *                             positions to play between.
         *
         * Returns
         *   ::success If the operation is successful.
         *
         *   ::multimedia::result_unsupported_function If the sequencer instance is not
         *     opened or prerolled.
         *
         * open the device so we can initialize channels.
         *
         * Loop through the tracks. For each track, seek to the given position and
         * send the init data SMF gives us to the handle.
         *
         * Wait for all init buffers to finish.
         *
         * Unprepare the buffers (they're only ever sent here; the sequencer
         * engine merges them into a single stream during normal playback) and
         * refill them with the first chunk of data from the track.
         *
         *
         ****************************************************************************/
         ::e_status sequence::Preroll(::thread * pthread, ::music::midi::LPPREROLL lpPreroll, bool bThrow)
         {

            __UNREFERENCED_PARAMETER(pthread);

            single_lock synchronouslock(m_mutex, true);

            int32_t                 i;
            e_result                smfrc;
            ::e_status  mmrc = ::success;
            //MIDIPROPTIMEDIV         mptd;
            LPMIDIHDR               lpmh = NULL;
            uint32_t                uDeviceID;


            ASSERT(m_iOpenMode == file::OpenForPlaying || IsInSpecialModeV001());

            m_flags.unsignalize(e_flag_end_of_file);

            m_mmrcLastErr = ::success;

            if(get_status() != status_opened &&
                  get_status() != status_pre_rolled &&
                  !IsInSpecialModeV001())
               return ::multimedia::result_unsupported_function;

            m_tkBase = lpPreroll->tickBase;
            m_tkEnd = lpPreroll->tickEnd;

            set_status(::music::midi::sequence::status_pre_rolling);

            m_flags.unsignalize(e_flag_end_of_file);

            file()->m_flags &= ~file::EndOfFile;

            //smfrc = file()->WorkSeek(m_tkBase);

            smfrc = file()->WorkSeek(0);

            m_tkPrerollBase = get_file()->GetPosition();

            set_status(status_pre_rolled);

            return mmrc;

         }


         /***************************************************************************
         *
         * seqStart
         *
         * Starts playback at the current position.
         *
         * pSeq                      - The sequencer instance.
         *
         * Returns
         *   ::success If the operation is successful.
         *
         *   ::multimedia::result_unsupported_function If the sequencer instance is not
         *     stopped.
         *
         *   ::multimedia::result_not_ready If the underlying MIDI device could
         *     not be opened or fails any call.
         *
         * The sequencer must be prerolled before seqStart may be called.
         *
         * Just feed everything in the ready queue to the device.
         *
         ***************************************************************************/
         ::e_status sequence::Start()
         {

            single_lock synchronouslock(m_mutex, true);

            if (::music::midi::sequence::status_pre_rolled != get_status())
            {

               information( "seqStart(): State is wrong! [%u]", get_status());

               return ::multimedia::result_unsupported_function;

            }

            set_status(::music::midi::sequence::status_playing);

            m_happeningMmsgDone.reset_happening();

            ::e_status mmrc = ::success;

            synchronouslock.unlock();

            if(mmrc == ::success)
            {

               thread()->PostMidiSequenceEvent(this, ::music::midi::sequence::EventMidiPlaybackStart);

            }

            return mmrc;
         }

         /***************************************************************************
         *
         * seqPause
         *
         * Pauses playback of the instance.
         *
         * pSeq                      - The sequencer instance.
         *
         * Returns
         *   ::success If the operation is successful.
         *
         *   ::multimedia::result_unsupported_function If the sequencer instance is not
         *     playing.
         *
         * The sequencer must be playing before seqPause may be called.
         * Pausing the sequencer will cause all currently on notes to be turned
         * off. This may cause playback to be slightly inaccurate on restart
         * due to missing notes.
         *
         ***************************************************************************/
         ::e_status sequence::Pause()

         {
            single_lock synchronouslock(m_mutex, true);

            //    assert(NULL != pSeq);

            if (status_playing != get_status())
               return ::multimedia::result_unsupported_function;

            set_status(status_paused);

            ::e_status mmrc = ::success;
            //    single_lock slStream(&m_csStream, false);
            //  slStream.lock();
            //if(m_hstream != NULL)
            //{
            //   mmrc = translate_mmr(midiStreamPause(m_hstream));
            //}
            //slStream.unlock();

            SetLevelMeter(0);

            return ::success;
         }

         /***************************************************************************
         *
         * seqRestart
         *
         * Restarts playback of an instance after a pause.
         *
         * pSeq                      - The sequencer instance.
         *
         * Returns
         *    ::success If the operation is successful.
         *
         *    ::multimedia::result_unsupported_function If the sequencer instance is not
         *     paused.
         *
         * The sequencer must be paused before seqRestart may be called.
         *
         ***************************************************************************/
         ::e_status sequence::Restart()
         {
            //    assert(NULL != pSeq);

            single_lock synchronouslock(m_mutex, true);

            if (status_paused != get_status())
               return ::multimedia::result_unsupported_function;

            set_status(status_playing);
            m_happeningMmsgDone.reset_happening();

            //    ::e_status mmrc = 0;
            //    single_lock slStream(&m_csStream, false);
            //  slStream.lock();
            //if(m_hstream != NULL)
            //{
            //   midiStreamRestart(m_hstream);
            //}
            //slStream.unlock();
            return ::success;
         }

         /***************************************************************************
         *
         * seqStop
         *
         * Totally stops playback of an instance.
         *
         * pSeq                      - The sequencer instance.
         *
         * Returns
         *   ::success If the operation is successful.
         *
         *   ::multimedia::result_unsupported_function If the sequencer instance is not
         *     paused or playing.
         *
         * The sequencer must be paused or playing before seqStop may be called.
         *
         ***************************************************************************/
         ::e_status sequence::Stop()
         {

            single_lock synchronouslock(m_mutex, true);

            if(get_status() == status_stopping)
               return ::success;

            // Automatic success if we're already stopped
            if (get_status() != status_playing
                  && get_status() != status_paused)
            {
               m_flags.unsignalize(::music::midi::sequence::e_flag_waiting);
               GetPlayerLink().OnFinishCommand(::music::midi::player::command_stop);
               return ::success;
            }

            set_status(status_stopping);
            m_flags.signalize(::music::midi::sequence::e_flag_waiting);

            m_happeningMidiPlaybackEnd.reset_happening();

            //if(m_hstream != NULL)
            //{

            //   m_mmrcLastErr = translate_mmr(midiStreamStop(m_hstream));

            //   if(::success != m_mmrcLastErr)
            //   {

            //      information( "::music::midi::sequence::Stop() -> midiOutStop() returned %lu in seqStop()!\n", (uint32_t)m_mmrcLastErr);

            //      m_flags.unsignalize(e_flag_waiting);

            //      return ::multimedia::result_not_ready;

            //   }

            //}

            //m_happeningMidiPlaybackEnd.lock();

            SetLevelMeter(0);

            return ::success;

         }

         /***************************************************************************
         *
         * seqTime
         *
         * Determine the current position in playback of an instance.
         *
         * pSeq                      - The sequencer instance.
         *
         & ticka                    - A pointer to a uint32_t where the current position
         *                             in ticks will be returned.
         *
         * Returns
         *   ::success If the operation is successful.
         *
         *   ::multimedia::result_not_ready If the underlying device fails to report
         *     the position.
         *
         *   ::multimedia::result_unsupported_function If the sequencer instance is not
         *     paused or playing.
         *
         * The sequencer must be paused, playing or prerolled before seqTime
         * may be called.
         *
         ***************************************************************************/
         ::e_status sequence::get_ticks(imedia_position &  ticks)
         {

            synchronous_lock synchronouslock(m_mutex);

            try
            {

               if (m_pthreadPlay != NULL)
               {

                  imedia_time time = 0;

                  get_millis(time);

                  ticks = MillisecsToTicks(time);

               }

            }
            catch (...)
            {

            }

            return ::success;

         }


         //void sequence::get_time(imedia_time & time)
         //{
         //
         //   get_millis(time);

         //}


         ::e_status sequence::get_millis(imedia_time & time)
         {

            synchronous_lock synchronouslock(m_mutex);

            if (m_pthreadPlay == NULL)
            {

               time = 0;

               return ::success;

            }

            time = ::get_micro() - m_pthreadPlay->m_uiStart + m_pthreadPlay->m_uiOffset;

            time /= 1000;

            return ::success;

         }


         /***************************************************************************
         *
         * seqMillisecsToTicks
         *
         * Given a ::duration offset in the output stream, returns the associated
         * tick position.
         *
         * pSeq                      - The sequencer instance.
         *
         * msOffset                  - The ::duration offset into the stream.
         *
         * Returns the number of ticks into the stream.
         *
         ***************************************************************************/
         imedia_position sequence::MillisecsToTicks(imedia_time msOffset)
         {
            return file()->MillisecsToTicks(msOffset);
         }

         /***************************************************************************
         *
         * seqTicksToMillisecs
         *
         * Given a tick offset in the output stream, returns the associated
         * ::duration position.
         *
         * pSeq                      - The sequencer instance.
         *
         * tickOffset                  - The tick offset into the stream.
         *
         * Returns the number of ::durations into the stream.
         *
         ***************************************************************************/
         imedia_time sequence::TicksToMillisecs(imedia_position tickOffset)
         {
            return file()->TicksToMillisecs(tickOffset);
         }
         uint64_t sequence::TickToMicro(imedia_position tickOffset)
         {
            return file()->TickToMicro(tickOffset);
         }

         //void sequence::OnDone(HMIDISTRM hmidistream, LPMIDIHDR lpmidihdr)
         //{
         //   __UNREFERENCED_PARAMETER(hmidistream);
         //   e_result               smfrc;
         //   midi_callback_data *      lpData;
         //   ASSERT(lpmidihdr != NULL);
         //   lpData = (midi_callback_data *) lpmidihdr->dwUser;
         //   ASSERT(lpData != NULL);

         //   ::music::midi::sequence * psequence = lpData->m_psequence;

         //   sequence_thread * pthread = dynamic_cast < sequence_thread * > (psequence->m_pthread);

         //   ASSERT(NULL != lpmidihdr);

         //   --m_uBuffersInMMSYSTEM;

         //   if(m_uBuffersInMMSYSTEM <= 0)
         //   {
         //      m_happeningBuffersZero.set_happening();
         //   }

         //   if (status_reset == get_status())
         //   {
         //      // We're recollecting buffers from MMSYSTEM
         //      //
         //      //      if (lpmidihdr != m_lpmhPreroll)
         //      //    {
         //      //     lpmidihdr->lpNext    = m_lpmhFree;
         //      //   m_lpmhFree           = lpmidihdr;
         //      //      }
         //      return;
         //   }

         //   bool bStopping = status_stopping == get_status();
         //   bool bEndOfPlay = m_uBuffersInMMSYSTEM <= 0;
         //   bool bSpecialModeV001End = m_flags.is_signalized(FlagSpecialModeV001End);

         //   if (bStopping || bEndOfPlay || bSpecialModeV001End)
         //   {
         //      //
         //      // Reached EOF, just put the buffer back on the free
         //      // list
         //      //
         //      if(bSpecialModeV001End)
         //      {
         //         m_flags.unsignalize(FlagSpecialModeV001End);
         //         informationf("void CALLBACK ::music::midi::sequence::MidiOutProc m_flags.is_signalized(FlagSpecialModeV001End\n");
         //         pthread->PostMidiSequenceEvent(
         //            this,
         //            ::music::midi::sequence::EventSpecialModeV001End,
         //            lpmidihdr);
         //      }
         //      else if(bStopping)
         //      {
         //         if(m_uBuffersInMMSYSTEM == 0)
         //         {
         //            informationf("void CALLBACK ::music::midi::sequence::MidiOutProc status_stopping == pSeq->get_status()\n");
         //            pthread->PostMidiSequenceEvent(
         //               this,
         //               ::music::midi::sequence::EventStopped,
         //               lpmidihdr);
         //         }
         //      }
         //      else
         //      {
         //         if(m_flags.is_signalized(e_flag_end_of_file))
         //         {
         //            informationf("void CALLBACK ::music::midi::sequence::MidiOutProc m_flags.is_signalized(e_flag_end_of_file\n");
         //         }
         //         if(m_uBuffersInMMSYSTEM <= 0)
         //         {
         //            pthread->PostMidiSequenceEvent(
         //               this,
         //               ::music::midi::sequence::e_event_midi_playback_end,
         //               lpmidihdr);
         //         }
         //      }
         //   }
         //   else
         //   {
         //      if(IsInSpecialModeV001())
         //      {
         //         if(m_uiSpecialModeV001Operation == SPMV001GMReset)
         //         {
         //            const uchar gmModeOn[] = {
         //               //        0x00, 0x00, 0x00, 0x00,
         //               //        0x00, 0x00, 0x00, 0x00,
         //               //        0x1b, 0x8a, 0x06, MEVT_TEMPO,
         //               0x00, 0x00, 0x00, 0x00,
         //               0x00, 0x00, 0x00, 0x00,
         //               0x06, 0x00, 0x00, MEVT_LONGMSG,
         //               0xf0, 0x7e, 0x7f, 0x09,
         //               0x01, 0xf7, 0x00, 0x00};
         //            lpmidihdr->dwBytesRecorded = sizeof(gmModeOn);
         //            memory_copy(lpmidihdr->lpData, gmModeOn, sizeof(gmModeOn));
         //         }
         //         else if(m_uiSpecialModeV001Operation == SPMV001TempoChange)
         //         {
         //            ::music::midi::happening happening;
         //            file()->GetTempoEvent(happening);
         //            file()->StreamEvent(happening.GetDelta(), &happening, lpmidihdr, I32_MAXIMUM, 256);
         //            // lpmidihdr->dwBytesRecorded = sizeof(gmModeOn);
         //            // memory_copy(lpmidihdr->lpData, gmModeOn, sizeof(gmModeOn));
         //         }
         //         else
         //         {
         //            ASSERT(false);
         //         }
         //         //post_thread_message(lpData->dwThreadID, MIDIPLAYERMESSAGE_STREAMOUT, (WPARAM) pSeq, (LPARAM) lpmidihdr);
         //         pthread->PostMidiSequenceEvent(
         //            this,
         //            e_event_midi_stream_out,
         //            lpmidihdr);
         //         m_flags.signalize(FlagSpecialModeV001End);
         //         smfrc = ::music::success;
         //         return;
         //      }
         //      //
         //      // Not EOF yet; attempt to fill another buffer
         //      //
         //      pthread->PostMidiSequenceEvent(
         //         this,
         //         e_event_midi_stream_out,
         //         lpmidihdr);
         //   }

         //}

         //void sequence::OnPositionCB(LPMIDIHDR lpmidihdr)
         //{
         //   ASSERT(lpmidihdr != NULL);
         //   LPBYTE lpbData = (LPBYTE) (lpmidihdr->lpData + lpmidihdr->dwOffset);
         //   MIDIEVENT * lpme = (MIDIEVENT *) lpbData;
         //   file::buffer::midi_stream_happening_header * pheader = (file::buffer::midi_stream_happening_header *) &lpme->dwParms[0];
         //   lpbData = (LPBYTE) pheader;
         //   LPDWORD lpdwParam;

         //   int32_t iSize = pheader->m_dwLength;
         //   switch(pheader->m_dwType)
         //   {
         //   case 0:
         //      {
         //         array < ::ikaraoke::lyric_event_v1, ::ikaraoke::lyric_event_v1 &> * plyriceventa = NULL;
         //         array < ::ikaraoke::lyric_event_v1, ::ikaraoke::lyric_event_v1 &> lyriceventa;
         //         for(int32_t i = sizeof(file::buffer::midi_stream_happening_header); i < iSize;)
         //         {
         //            pheader = (file::buffer::midi_stream_happening_header *) &lpbData[i];
         //            lpdwParam = (LPDWORD) &lpbData[i + sizeof(file::buffer::midi_stream_happening_header)];
         //            ASSERT(*lpdwParam == pheader->m_dwType);
         //            switch(pheader->m_dwType)
         //            {
         //            case EVENT_ID_LYRIC_V1:
         //               {
         //                  if(plyriceventa == NULL)
         //                  {
         //                     plyriceventa = ___new array <::ikaraoke::lyric_event_v1, ::ikaraoke::lyric_event_v1 &>;
         //                  }
         //                  ::file::memory_buffer memFile(get_app(), (LPBYTE) &lpdwParam[1], pheader->m_dwLength - sizeof(uint32_t));
         //                  /* x2x                  CArchive ar(&memFile, CArchive::load);
         //                  lyriceventa.Serialize(ar);
         //                  plyriceventa->append(lyriceventa); */
         //               }
         //               break;
         //            case EVENT_ID_PAD:
         //               {
         //               }
         //               break;
         //            case EVENT_ID_NOTE_ON:
         //               {
         //                  ::file::byte_stream_memory_buffer memFile(get_app(), (LPBYTE) &lpdwParam[1], pheader->m_dwLength - sizeof(uint32_t));
         //                  for(int32_t i = 0; i < m_iaLevel.get_size(); i++)
         //                  {
         //                     BYTE b;
         //                     memFile >> b;
         //                     m_iaLevel.element_at(i) = b;
         //                  }
         //               }
         //               break;
         //            }
         //            i += pheader->m_dwLength + sizeof(file::buffer::midi_stream_happening_header);
         //         }
         //         /*         if(plyriceventa != NULL)
         //         {
         //         ::PostMessage(m_midicallbackdata.oswindow, WM_APP + 3388, 3388, (LPARAM) plyriceventa);
         //         }*/
         //      }
         //      break;
         //   case EVENT_ID_PAD:
         //      break;
         //   default:
         //      ASSERT(false);
         //      break;
         //   }

         //}

         //void CALLBACK sequence::MidiOutProc(HMIDIOUT hmo, UINT wMsg, DWORD_PTR dwInstance, DWORD_PTR dwParam1, DWORD_PTR dwParam2)
         //{

         //   __UNREFERENCED_PARAMETER(hmo);
         //   __UNREFERENCED_PARAMETER(dwInstance);
         //   __UNREFERENCED_PARAMETER(dwParam2);

         //   LPMIDIHDR               lpmh         = (LPMIDIHDR) dwParam1;

         //   switch(wMsg)
         //   {
         //   case MOM_POSITIONCB:
         //      ((midi_callback_data *) lpmh->dwUser)->m_psequence->OnPositionCB(lpmh);
         //      break;
         //   case MOM_DONE:
         //      ((midi_callback_data *) lpmh->dwUser)->m_psequence->OnDone(NULL,lpmh);
         //      return;
         //   }

         //}


         bool sequence::IsPlaying()
         {
            return get_status() == status_playing ||
                   get_status() == status_stopping;
         }




         e_result sequence::SaveFile()
         {

            return SaveFile(file()->m_strName);

         }


         e_result sequence::SaveFile(const ::string & lpFileName)
         {

            return file()->SaveFile(lpFileName);

         }


         e_result sequence::SaveFile(::file::file_sp &ar)
         {

            return file()->SaveFile(*ar);

         }









         int32_t sequence::GetKeyShift()
         {

            if(m_pfile == NULL)
               return 0;

            return file()->GetKeyShift();

         }


         int32_t sequence::SetKeyShift(int32_t iKeyShift)
         {

            /*//    single_lock slStream(&m_csStream, false);
            //  slStream.lock();
            if(m_hstream)
            {
            midiStreamPause(m_hstream);
            if(!file()->SetKeyShift(iKeyShift))
            return false;
            midiStreamRestart(m_hstream);
            }
            //slStream.unlock();
            return true;
            void ::music::midi::sequence::SetKeyShift(int32_t iShift)
            {*/

            bool bPlay = IsPlaying();

            imedia_position ticks = 0;

            if(bPlay)
            {

               ticks = get_position_ticks();

               Stop();

            }

            get_file()->SetKeyShift(iKeyShift);

            if(bPlay)
            {

               m_pthread->PrerollAndWait(ticks);

               Start();

            }

            //}

            return true;

         }


         double sequence::GetTempoShift()
         {

            return file()->GetTempoShift();

         }



         int32_t sequence::SetTempoShift(int32_t iTempoShift)
         {

            //midiStreamPause(m_hstream);

            if(failed(file()->SetTempoShift(iTempoShift)))
               return false;

            //midiStreamRestart(m_hstream);

            return true;

         }


         bool sequence::SetMidiOutDevice(uint32_t uiDevice)
         {

            if(uiDevice == ::music::midi::device_default)
            {

//               m_uiDeviceID = MIDI_MAPPER;
               m_uiDeviceID = -1;

            }
            else
            {

               m_uiDeviceID = uiDevice;

            }

            return true;
         }

         ::e_status sequence::CloseStream()
         {
            single_lock synchronouslock(m_mutex, true);
            if(IsPlaying())
            {
               Stop();
            }

            /* If we were prerolled, need to clean up -- have an open MIDI handle
            ** and buffers in the ready queue
            */

            //m_buffera.midiOutUnprepareHeader((HMIDIOUT) m_hstream);

            //if (m_hstream != NULL)
            //{
            //   midiStreamClose( m_hstream);
            //   m_hstream = NULL;
            //}

            set_status(status_opened);

            return ::success;
         }

         void sequence::SetLevelMeter(int32_t iLevel)
         {
            for(int32_t i = 0; i < m_iaLevel.get_size(); i++)
            {
               m_iaLevel.element_at(i) = iLevel;
            }
         }


         void sequence::on_midi_playback_end(::music::midi::sequence::happening * pevent)
         {

            __UNREFERENCED_PARAMETER(pevent);

            single_lock synchronouslock(m_mutex, true);

            m_mmrcLastErr = ::success;

            m_flags.unsignalize(e_flag_waiting);

            m_happeningMmsgDone.set_happening();

         }

         void sequence::OnHappening(::music::midi::sequence::happening * pevent)
         {
            switch(ptopic->id())
            {
            case EventSpecialModeV001End:
            {
               SetSpecialModeV001Flag(false);
               on_midi_playback_end(pevent);
               set_status(m_estatusPreSpecialModeV001);
            }
            break;
            case e_event_midi_playback_end:
            {
               on_midi_playback_end(pevent);
               set_status(status_opened);
            }
            break;
            case e_event_midi_stream_out:
            {



               single_lock synchronouslock(m_mutex, true);

               ::music::midi::winrt::sequence::happening * pev = (::music::midi::winrt::sequence::happening *) pevent;

               if(m_flags.is_signalized(e_flag_end_of_file))
               {

                  return;

               }

               //LPMIDIHDR lpmh = pev->m_lpmh;

               //e_result smfrc;

               //if(IsInSpecialModeV001())
               //{
               //   informationf("::music::midi::sequence::OnHappening e_event_midi_stream_out IsInSpecialModeV001");
               //}
               //else
               //{
               //   smfrc = file()->WorkStreamRender(lpmh, m_tkEnd, m_cbPrerollNominalMax);
               //}

               //switch(smfrc)
               //{
               //case ::music::success:

               //   break;

               //case SEndOfFile:

               //   m_flags.signalize(e_flag_end_of_file);

               //   smfrc = ::music::success;

               //   break;

               //default:


               //   information( "smfReadEvents returned %lu in callback!", (uint32_t) smfrc);

               //   set_status(status_stopping);

               //   break;

               //}

               //if(::music::midi::sequence::status_stopping == get_status())
               //{

               //   thread()->PostMidiSequenceEvent(this, e_event_midi_playback_end, lpmh);

               //   return;

               //}

               //::e_status mmrc;

               //if(m_hstream != NULL)
               //{

               //   mmrc = translate_mmr(midiStreamOut(m_hstream, lpmh, sizeof(*lpmh)));

               //   if(mmrc == ::success)
               //   {

               //      ++m_uBuffersInMMSYSTEM;

               //   }
               //   else
               //   {

               //      informationf("seqBufferDone(): midiStreamOut() returned %lu!", (uint32_t)mmrc);

               //      set_status(::music::midi::sequence::status_stopping);

               //   }


               //}

            }
            default:
               break;
            }
         }


         imedia_position sequence::get_position_ticks()
         {

            if (m_pthreadPlay == NULL)
            {

               return 0;

            }

            return m_pthreadPlay->m_tkPosition;

         }


         bool sequence::IsChangingTempo()
         {
            return m_flags.is_signalized(::music::midi::sequence::e_flag_tempo_change);
         }
         void sequence::SetTempoChangeFlag(bool bSet)
         {
            if(bSet)
               m_flags.signalize(::music::midi::sequence::e_flag_tempo_change);
            else
               m_flags.unsignalize(::music::midi::sequence::e_flag_tempo_change);
         }




         bool sequence::IsNull()
         {
            if(this == NULL)
               return true;
            return false;
         }

         imedia_position sequence::TimeToPosition(imedia_time ::duration)
         {
            return imedia_position(MillisecsToTicks((int_ptr) ::duration));
         }

         imedia_time sequence::PositionToTime(imedia_position tick)
         {
            return imedia_time(TicksToMillisecs((imedia_position) (int_ptr) tick));
         }


         void sequence::get_position(imedia_position & position)
         {

            get_ticks(position);

         }


         bool sequence::IsOpened()
         {
            return get_status() != status_no_file;
         }

         void sequence::GetTimeLength(imedia_time & time)
         {
            time = m_msLength;
         }


         ::e_status sequence::SendGMReset()
         {

            return ::success;

         }
         //void sequence::Prepare(
         //   string_array_array_base & straa,
         //   imedia::position_2darray & tickaaTokensTicks,
         //   int32_t iMelodyTrack,
         //   int2a & ia2TokenLine,
         //   ::ikaraoke::data & data)
         //{

         //   __UNREFERENCED_PARAMETER(straa);

         //   ::music::midi::file::buffer & file = *this->file();

         //   ::music::midi::tracks & tracks = file.GetTracks();

         //   ASSERT(!file.IsNull());
         //   file.GetTracks().seek_begin();
         //   imedia_position               tickMax = file.m_tkLength;
         //   imedia_position               tickLastPosition = 0;


         //   ::ikaraoke::static_data & staticdata = data.GetStaticData();

         //   if(staticdata.m_LyricsDisplayOffset < 480)
         //   {
         //      staticdata.m_LyricsDisplayOffset = 480;
         //   }
         //   if(staticdata.m_LyricsDisplayOffset > 720)
         //   {
         //      staticdata.m_LyricsDisplayOffset = 720;
         //   }
         //   staticdata.m_LyricsDisplay = 30;

         //   imedia::position_2darray tickaaNoteOnPositions(m_pobject);
         //   imedia::position_2darray tickaaNoteOffPositions(m_pobject);
         //   imedia::position_2darray tickaaBegPositions(m_pobject);
         //   imedia::position_2darray tickaaEndPositions(m_pobject);
         //   imedia::time_array_array_base ms2DTokensMillis(m_pobject);
         //   imedia::time_array_array_base ms2DNoteOnMillis(m_pobject);
         //   imedia::time_array_array_base ms2DNoteOffMillis(m_pobject);
         //   imedia::time_array_array_base ms2DBegMillis(m_pobject);
         //   imedia::time_array_array_base ms2DEndMillis(m_pobject);
         //   ::music::midi::happenings midiEvents;




         //   // Note on and off happenings
         //   // and maximum and minimum
         //   // pitch bend peaks.
         //   ::music::midi::happenings midiEventsLevel2;

         //   ::music::midi::happenings noteOnHappenings;
         //   ::music::midi::happenings noteOffEvents;

         //   ::music::midi::happenings eventsLevel2Beg;
         //   ::music::midi::happenings eventsLevel2End;
         //   ::ikaraoke::events_tracks_v1 lyricEventsForPositionCB;
         //   ::ikaraoke::events_tracks_v1 lyricEventsForBouncingBall;
         //   ::ikaraoke::events_tracks_v1 lyricEventsForScoring;
         //   ::ikaraoke::events_tracks_v1 lyricEvents;

         //   //   tracks.seek_begin();
         //   // tracks.GetXFInfoHeaders(
         //   //  &m_xfInfoHeaders);



         //   file.PositionToTime(
         //      ms2DTokensMillis,
         //      tickaaTokensTicks,
         //      0);

         //   ::ikaraoke::lyric_events_v2 *pLyricEventsV2;
         //   ::ikaraoke::lyric_events_v2 *pLyricEventsV2_;
         //   ::ikaraoke::lyric_events_v2 *pLyricEventsV2B;
         //   ::ikaraoke::lyric_events_v2 *pLyricEventsV2C;
         //   ::music::midi::happenings *pMidiEventsV1;

         //   tickaaNoteOnPositions.set_size_create(tickaaTokensTicks.get_size());
         //   tickaaNoteOffPositions.set_size_create(tickaaTokensTicks.get_size());
         //   tickaaBegPositions.set_size_create(tickaaTokensTicks.get_size());
         //   tickaaEndPositions.set_size_create(tickaaTokensTicks.get_size());
         //   int32_t i;
         //   for(i = 0; i < tickaaTokensTicks.get_size(); i++)
         //   {
         //      pLyricEventsV2 = ___new ::ikaraoke::lyric_events_v2();
         //      pLyricEventsV2B = ___new ::ikaraoke::lyric_events_v2();
         //      pLyricEventsV2C = ___new ::ikaraoke::lyric_events_v2();
         //      pLyricEventsV2_ = ___new ::ikaraoke::lyric_events_v2();
         //      staticdata.m_happeningsv1.add(pLyricEventsV2);
         //      staticdata.m_happeningsv1.add(pLyricEventsV2B);
         //      staticdata.m_happeningsv1.add(pLyricEventsV2C);
         //      staticdata.m_happeningsv1.add(pLyricEventsV2_);
         //      lyricEvents.add(pLyricEventsV2_);
         //      lyricEventsForScoring.add(pLyricEventsV2);
         //      lyricEventsForPositionCB.add(pLyricEventsV2B);
         //      lyricEventsForBouncingBall.add(pLyricEventsV2C);
         //      pLyricEventsV2->m_iType = 0;
         //      pLyricEventsV2->m_iOrder = i;
         //      pLyricEventsV2->m_iType = 2;
         //      pLyricEventsV2->m_iOrder = i;
         //      pLyricEventsV2B->m_iType = ikaraoke::EventRunningElement;
         //      pLyricEventsV2B->m_iOrder = i;
         //      pLyricEventsV2C->m_iType = 4;
         //      pLyricEventsV2C->m_iOrder = i;
         //      pMidiEventsV1 = NULL;
         //      if(iMelodyTrack < 0)
         //      {
         //         //pLyricEventsV2->m_iTrack =
         //         //   file.WorkCalcMelodyTrack(
         //         //   &pMidiEventsV1,
         //         //   tickaaTokensTicks.operator[](i),
         //         //   ia2TokenLine[i]);
         //      }
         //      else
         //      {
         //         pLyricEventsV2->m_iTrack = iMelodyTrack;
         //      }
         //      pLyricEventsV2B->m_iTrack = pLyricEventsV2->m_iTrack;
         //      pLyricEventsV2C->m_iTrack = pLyricEventsV2->m_iTrack;
         //      pLyricEventsV2_->m_iTrack = pLyricEventsV2->m_iTrack;
         //      if(pLyricEventsV2->m_iTrack < 0)
         //      {
         //         pLyricEventsV2->m_iTrack = tracks.m_iMelodyTrackTipA;
         //         pLyricEventsV2B->m_iTrack = tracks.m_iMelodyTrackTipA;
         //         pLyricEventsV2C->m_iTrack = tracks.m_iMelodyTrackTipA;
         //         pLyricEventsV2_->m_iTrack = tracks.m_iMelodyTrackTipA;
         //      }
         //      staticdata.SetGuessMelodyTrack(pLyricEventsV2->m_iTrack);
         //      if(pLyricEventsV2->m_iTrack >= 0)
         //      {
         //         if(file.GetFormat() == 0)
         //         {
         //            tracks.TrackAt(0)->WorkSeekBegin();
         //            ((::music::midi::track *)tracks.TrackAt(0))->WorkGetNoteOnOffEventsV1(
         //               &midiEvents,
         //               (int32_t) pLyricEventsV2->m_iTrack,
         //               file.GetFormat() == 1);
         //            tracks.TrackAt(0)->WorkSeekBegin();
         //            ((::music::midi::track *)tracks.TrackAt(0))->WorkGetLevel2Events(
         //               &midiEventsLevel2,
         //               (int32_t) pLyricEventsV2->m_iTrack,
         //               file.GetFormat() == 1);
         //         }
         //         else
         //         {
         //            tracks.TrackAt(pLyricEventsV2->m_iTrack)->seek_begin();
         //            ((::music::midi::track *)tracks.TrackAt(pLyricEventsV2->m_iTrack))->GetLevel2Events(
         //               &midiEvents,
         //               (int32_t) pLyricEventsV2->m_iTrack,
         //               file.GetFormat() == 1);
         //            tracks.TrackAt(pLyricEventsV2->m_iTrack)->seek_begin();
         //            ((::music::midi::track *)tracks.TrackAt(pLyricEventsV2->m_iTrack))->GetLevel2Events(
         //               &midiEventsLevel2,
         //               (int32_t) pLyricEventsV2->m_iTrack,
         //               file.GetFormat() == 1);
         //         }
         //      }

         //      ::music::midi::util miditutil(m_pobject);

         //      miditutil.PrepareNoteOnOffEvents(
         //         &noteOnHappenings,
         //         &noteOffEvents,
         //         (int32_t) pLyricEventsV2->m_iTrack,
         //         file.GetFormat(),
         //         &midiEvents,
         //         tickaaTokensTicks.operator()(i));

         //      miditutil.PrepareLevel2Events(
         //         &eventsLevel2Beg,
         //         &eventsLevel2End,
         //         (int32_t) pLyricEventsV2->m_iTrack,
         //         file.GetFormat(),
         //         &midiEventsLevel2,
         //         tickaaTokensTicks.operator()(i));


         //      tickaaNoteOnPositions(i)     = noteOnHappenings.m_tickaEventsPosition;
         //      tickaaNoteOffPositions(i)    = noteOffEvents.m_tickaEventsPosition;
         //      tickaaBegPositions(i)        = eventsLevel2Beg.m_tickaEventsPosition;
         //      tickaaEndPositions(i)        = eventsLevel2End.m_tickaEventsPosition;
         //      pLyricEventsV2->m_dwaNotesData.copy(noteOnHappenings.m_dwaEventsData);
         //      pLyricEventsV2B->m_dwaNotesData.copy(eventsLevel2Beg.m_dwaEventsData);
         //      pLyricEventsV2C->m_dwaNotesData.copy(eventsLevel2Beg.m_dwaEventsData);
         //      pLyricEventsV2_->m_dwaNotesData.copy(eventsLevel2Beg.m_dwaEventsData);
         //      midiEvents.erase_all();
         //      noteOnHappenings.erase_all();
         //      noteOffEvents.erase_all();
         //      midiEventsLevel2.erase_all();
         //      eventsLevel2Beg.erase_all();
         //      eventsLevel2End.erase_all();
         //      delete pMidiEventsV1;
         //   }

         //   file.PositionToTime(
         //      ms2DNoteOnMillis,
         //      tickaaNoteOnPositions,
         //      0);

         //   file.PositionToTime(
         //      ms2DNoteOffMillis,
         //      tickaaNoteOffPositions,
         //      0);

         //   file.PositionToTime(
         //      ms2DBegMillis,
         //      tickaaBegPositions,
         //      0);

         //   file.PositionToTime(
         //      ms2DEndMillis,
         //      tickaaEndPositions,
         //      0);


         //   ::ikaraoke::lyric_events_v1 *pLyricEventsV1;


         //   for(i = 0; i < tickaaTokensTicks.get_size(); i++)
         //   {
         //      pLyricEventsV2 = (::ikaraoke::lyric_events_v2 *) lyricEvents.get_at(i);
         //      staticdata.m_happeningstracks.add(pLyricEventsV2);
         //      file.TimeToPosition(
         //         pLyricEventsV2->m_tickaTokensPosition,
         //         ms2DTokensMillis(i),
         //         0);
         //      file.TimeToPosition(
         //         pLyricEventsV2->m_tickaNotesPosition,
         //         ms2DNoteOnMillis(i),
         //         0);

         //      imedia_time time1(0);
         //      imedia_time time2(0);

         //      pLyricEventsV2->m_timeaTokensPosition.CopySorted(
         //         ms2DTokensMillis(i),
         //         time1,
         //         time2);

         //      pLyricEventsV2->m_timeaNotesDuration.Diff(
         //         ms2DNoteOffMillis(i),
         //         ms2DNoteOnMillis(i));

         //      imedia_time time3(0);
         //      imedia_time time4(0);

         //      pLyricEventsV2->m_timeaNotesPosition.CopySorted(
         //         ms2DNoteOnMillis(i),
         //         time3,
         //         time4);

         //      imedia_time time5(I32_MAXIMUM);

         //      pLyricEventsV2->m_timeaTokensDuration.ElementDiff(
         //         ms2DTokensMillis(i),
         //         time5);

         //   }


         //   for(i = 0; i < tickaaTokensTicks.get_size(); i++)
         //   {
         //      pLyricEventsV1 = ___new ::ikaraoke::lyric_events_v1();
         //      pLyricEventsV1->m_iType = ikaraoke::EventAdvanceShow;
         //      pLyricEventsV1->m_iOrder = i;
         //      //staticdata.m_happeningsTracksForPositionCB.add(pLyricEventsV1);
         //      file.TimeToPosition(
         //         pLyricEventsV1->m_tickaTokensPosition,
         //         ms2DTokensMillis(i),
         //         -1000);
         //      //lyric_track * pLyricTrk = file.GetTracks().CreateLyricTrack();
         //      //pLyricTrk->Prepare(*pLyricEventsV1);
         //   }


         //   for(i = 0; i < tickaaTokensTicks.get_size(); i++)
         //   {
         //      pLyricEventsV2 = (::ikaraoke::lyric_events_v2 *) lyricEventsForScoring.get_at(i);
         //      staticdata.m_happeningsTracksForScoring.add(pLyricEventsV2);
         //      file.TimeToPosition(
         //         pLyricEventsV2->m_tickaTokensPosition,
         //         ms2DTokensMillis(i),
         //         0);
         //      file.TimeToPosition(
         //         pLyricEventsV2->m_tickaNotesPosition,
         //         ms2DNoteOnMillis(i),
         //         0);

         //      imedia_time time1(-100);
         //      imedia_time time2(0);

         //      pLyricEventsV2->m_timeaTokensPosition.CopySorted(
         //         ms2DTokensMillis(i),
         //         time1,
         //         time2);

         //      pLyricEventsV2->m_timeaNotesDuration.Diff(
         //         ms2DNoteOffMillis(i),
         //         ms2DNoteOnMillis(i));

         //      imedia_time time3(-100);
         //      imedia_time time4(0);

         //      pLyricEventsV2->m_timeaNotesPosition.CopySorted(
         //         ms2DNoteOnMillis(i),
         //         time3,
         //         time4);

         //      imedia_time time5(I32_MAXIMUM);

         //      pLyricEventsV2->m_timeaTokensDuration.ElementDiff(
         //         ms2DTokensMillis(i),
         //         time5);

         //      pLyricEventsV2->PrepareForScoring(this);
         //   }







         //   for(i = 0; i < tickaaTokensTicks.get_size(); i++)
         //   {
         //      pLyricEventsV2 = (::ikaraoke::lyric_events_v2 *) lyricEventsForPositionCB.get_at(i);
         //      staticdata.m_happeningsTracksForPositionCB.add(pLyricEventsV2);

         //      staticdata.m_happeningstracksV002.add(pLyricEventsV2);

         //      file.TimeToPosition(
         //         pLyricEventsV2->m_tickaTokensPosition,
         //         ms2DTokensMillis(i),
         //         -100);

         //      file.TimeToPosition(
         //         pLyricEventsV2->m_tickaNotesPosition,
         //         ms2DNoteOnMillis(i),
         //         -100);

         //      imedia_time time1(-100);
         //      imedia_time time2(0);

         //      pLyricEventsV2->m_timeaTokensPosition.CopySorted(
         //         ms2DTokensMillis(i),
         //         time1,
         //         time2);

         //      pLyricEventsV2->m_timeaNotesDuration.Diff(
         //         ms2DNoteOffMillis(i),
         //         ms2DNoteOnMillis(i));

         //      /*
         //      pLyricEventsV2->m_timeaNotesDuration.Diff(
         //      ms2DNoteOffMillis[i],
         //      ms2DNoteOnMillis(i));
         //      */


         //      imedia_time time3(-100);
         //      imedia_time time4(0);

         //      pLyricEventsV2->m_timeaNotesPosition.CopySorted(
         //         ms2DNoteOnMillis(i),
         //         time3,
         //         time4);

         //      imedia_time time5(I32_MAXIMUM);

         //      pLyricEventsV2->m_timeaTokensDuration.ElementDiff(
         //         ms2DTokensMillis(i),
         //         time5);

         //      pLyricEventsV2->PrepareForLyricsDisplay(this);
         //      //lyric_track * pLyricTrk = file.GetTracks().CreateLyricTrack();
         //      //pLyricTrk->Prepare(*pLyricEventsV2);
         //   }










         //   for(i = 0; i < tickaaTokensTicks.get_size(); i++)
         //   {
         //      pLyricEventsV2 = (::ikaraoke::lyric_events_v2 *) lyricEventsForBouncingBall.get_at(i);
         //      staticdata.m_happeningsTracksForBouncingBall.add(pLyricEventsV2);

         //      file.TimeToPosition(
         //         pLyricEventsV2->m_tickaTokensPosition,
         //         ms2DTokensMillis(i),
         //         -100);

         //      file.TimeToPosition(
         //         pLyricEventsV2->m_tickaNotesPosition,
         //         ms2DNoteOnMillis(i),
         //         -100);

         //      imedia_time time1(-100);
         //      imedia_time time2(0);

         //      pLyricEventsV2->m_timeaTokensPosition.CopySorted(
         //         ms2DTokensMillis(i),
         //         time1,
         //         time2);

         //      pLyricEventsV2->m_timeaNotesDuration.Diff(
         //         ms2DEndMillis(i),
         //         ms2DBegMillis(i));

         //      /*
         //      pLyricEventsV2->m_timeaNotesDuration.Diff(
         //      ms2DNoteOffMillis[i],
         //      ms2DNoteOnMillis(i));
         //      */

         //      imedia_time time3(-100);
         //      imedia_time time4(0);

         //      pLyricEventsV2->m_timeaNotesPosition.CopySorted(
         //         ms2DNoteOnMillis(i),
         //         time3,
         //         time4);

         //      imedia_time time5(I32_MAXIMUM);

         //      pLyricEventsV2->m_timeaTokensDuration.ElementDiff(
         //         ms2DTokensMillis(i),
         //         time5);

         //      pLyricEventsV2->PrepareForBouncingBall(this);
         //   }

         //}

         //void sequence::Prepare(int32_t iTrack, ::ikaraoke::data & data)
         //{

         //   ::music::midi::winrt::buffer & file = *this->file();

         //   ::music::midi::tracks & tracks = file.GetTracks();

         //   string_array_array_base & straa = data.GetStaticData().m_straaRawTokens;

         //   imedia::position_2darray position2a;

         //   int2a ia2TokenLine;


         //   ia2TokenLine.add_new();

         //   tracks.WorkSeekBegin();
         //   tracks.WorkGetEmptyXFTokens(
         //      iTrack,
         //      straa,
         //      position2a,
         //      NULL);

         //   Prepare(
         //      straa,
         //      position2a,
         //      iTrack,
         //      ia2TokenLine,
         //      data);

         //}

         //void sequence::Prepare(::ikaraoke::data & data)
         //{
         //   ::music::midi::winrt::buffer & file = *this->file();
         //   ::music::midi::tracks & tracks = file.GetTracks();
         //   string_array_array_base & straa = data.GetStaticData().m_straaRawTokens;
         //   imedia::position_2darray position2a;
         //   int2a iaaTokenLine;

         //   ::music::xf::info_headers xfihs;
         //   get_file()->GetTracks().GetXFInfoHeaders(&xfihs);

         //   ::ikaraoke::static_data & staticdata = data.GetStaticData();
         //   string str;

         //   // add Title
         //   staticdata.m_straTitleFormat.add("%0");
         //   staticdata.m_straaTitle.set_app(m_pobject);
         //   staticdata.m_straaTitle.add_new();
         //   staticdata.m_straaTitle[0].add(xfihs.m_strSongName);

         //   if(xfihs.m_xfInfoHeader.m_straComposer.get_size() > 0)
         //   {
         //      // add Performer
         //      staticdata.m_straTitleFormat.add("Performer: %0");
         //      xfihs.m_xfInfoHeader.m_straPerformer.get_format_string(str, ", ");
         //      staticdata.m_straaTitle.add_new();
         //      staticdata.m_straaTitle[1].add(str);

         //      // add Composer
         //      staticdata.m_straTitleFormat.add("Composer: %0");
         //      xfihs.m_xfInfoHeader.m_straComposer.get_format_string(str, ", ");
         //      staticdata.m_straaTitle.add_new();
         //      staticdata.m_straaTitle[1].add(str);


         //      //      staticdata.m_straPerformer = xfihs.m_xfInfoHeader.m_straPerformer;
         //      //    staticdata.m_straArtist = xfihs.m_xfInfoHeader.m_straPerformer;
         //   }

         //   staticdata.m_dwDefaultCodePage = 1252; // Latin (Default of All Default Code Pages)

         //   if(xfihs.m_xfaInfoHeaderLS.get_count())
         //   {
         //      staticdata.m_dwDefaultCodePage = ::music::xf::SymbolCharCodeToCodePage(xfihs.m_xfaInfoHeaderLS[0].m_strLanguage);
         //   }

         //   tracks.WorkSeekBegin();
         //   //tracks.WorkGetXFTokens(staticdata.m_dwDefaultCodePage, straa, position2a, iaaTokenLine, NULL);
         //   tracks.WorkGetXFTokens((uint32_t) -1, straa, position2a, iaaTokenLine, NULL, false);

         //   Prepare(
         //      straa,
         //      position2a,
         //      -1,
         //      iaaTokenLine,
         //      data);

         //   tracks.WorkSeekBegin();
         //   tracks.WorkGetLongestXFLyrics(staticdata.m_strLyrics, false);
         //   tracks.WorkGetLongestXFLyrics(staticdata.m_strLyricsEx1, true);



         //}


         void sequence::GetPositionLength(imedia_position &position)
         {
            position = m_tkLength;
         }

         void sequence::buffer::Initialize(int32_t iSize, uint_ptr dwUser)
         {
            m_storage.allocate(iSize);
            //m_midihdr.lpData           = (char *) m_storage.get_data();
            //m_midihdr.dwBufferLength   = (uint32_t) m_storage.get_size();
            //m_midihdr.dwUser           = dwUser;
            m_bPrepared                = false;

         }

         void sequence::buffer_array::Initialize(int32_t iCount, int32_t iSize, uint_ptr dwUser)
         {
            set_size(iCount);

            int32_t i;

            /*   for(int32_t i = 0; i < this->get_size() - 1; i++)
            {
            this->element_at(i).SetNextMidiHdr(this->element_at(i + 1).GetMidiHdr());
            }

            if(this->get_size() > 1)
            {
            this->element_at(get_upper_bound()).SetNextMidiHdr(this->element_at(0).GetMidiHdr());
            }
            else
            {
            this->element_at(0).SetNextMidiHdr(NULL);
            }*/

            for(i = 0; i < this->get_size(); i++)
            {
               this->element_at(i).Initialize(iSize, dwUser);
            }
         }

         void sequence::buffer_array::Reset()
         {
            for(int32_t i = 0; i < this->get_size(); i++)
            {
               this->element_at(i).Reset();
            }
         }

         void sequence::buffer::Reset()
         {
            //m_midihdr.dwBytesRecorded  = 0;
            //m_midihdr.dwFlags          = 0;
         }

         bool sequence::buffer::IsPrepared()
         {
            return m_bPrepared;
         }


         //::e_status sequence::buffer::midiOutPrepareHeader(HMIDIOUT hmidiout)
         //{

         //   ::e_status mmr = ::success;

         //   if(hmidiout == NULL)
         //      return mmr;

         //   if(m_bPrepared)
         //      return mmr;

         //   mmr = translate_mmr(::midiOutPrepareHeader(hmidiout, &m_midihdr, sizeof(m_midihdr)));

         //   if(mmr == ::success)
         //   {

         //      m_bPrepared = true;

         //   }

         //   return mmr;

         //}


         //::e_status sequence::buffer::midiOutUnprepareHeader(HMIDIOUT hmidiout)
         //{

         //   ::e_status mmr = ::success;

         //   if(hmidiout == NULL)
         //      return mmr;

         //   if(!m_bPrepared)
         //      return mmr;

         //   mmr = translate_mmr(::midiOutUnprepareHeader(hmidiout, &m_midihdr, sizeof(m_midihdr)));

         //   if(mmr == ::success)
         //   {

         //      m_bPrepared = false;

         //   }

         //   return mmr;

         //}

         //::e_status sequence::buffer_array::midiOutUnprepareHeader(HMIDIOUT hmidiout)
         //{
         //   ::e_status mmr = ::success;

         //   for (int32_t i = 0; i < this->get_size(); i++)
         //   {
         //      ::e_status mmrBuffer = this->element_at(i).midiOutUnprepareHeader(hmidiout);
         //      if(mmrBuffer != ::success)
         //      {
         //         mmr = mmrBuffer;
         //      }
         //   }
         //   return mmr;
         //}

         //::e_status sequence::buffer_array::midiOutPrepareHeader(HMIDIOUT hmidiout)
         //{
         //   ::e_status mmrc = ::success;
         //   for(int32_t i = 0; i < this->get_size(); i++)
         //   {
         //      mmrc = this->element_at(i).midiOutPrepareHeader(
         //         hmidiout);
         //      if(mmrc != ::success)
         //      {
         //         for(; i >= 0; i--)
         //         {
         //            this->element_at(i).midiOutUnprepareHeader(hmidiout);
         //         }
         //         return mmrc;
         //      }
         //   }
         //   return mmrc;
         //}

         //void sequence::buffer::SetNextMidiHdr(LPMIDIHDR lpNext)
         //{
         //   m_midihdr.lpNext = lpNext;
         //}


         //::e_status sequence::buffer::midiStreamOut(HMIDISTRM hmidiout)
         //{
         //   ASSERT(hmidiout != NULL);
         //   return translate_mmr(::midiStreamOut(hmidiout, &m_midihdr, sizeof(m_midihdr)));
         //}

         //::e_status sequence::buffer_array::midiStreamOut(HMIDISTRM hmidiout)
         //{
         //   ::e_status mmrc = ::success;
         //   for(int32_t i = 0; i < this->get_size(); i++)
         //   {
         //      mmrc = this->element_at(i).midiStreamOut(
         //         hmidiout);
         //      if(mmrc != ::success)
         //      {
         //         //         for(; i >= 0; i--)
         //         //       {
         //         //        this->element_at(i).midiOutUnprepareHeader(hmidiout);
         //         //   }
         //         return mmrc;
         //      }
         //   }
         //   return mmrc;
         //}





         void sequence::MuteAll(bool bMute, int32_t iExcludeTrack)
         {
            bool bPlay = IsPlaying();
            imedia_position ticks = 0;
            if(bPlay)
            {
               ticks = get_position_ticks();
               Stop();
            }
            get_file()->MuteAll(bMute, iExcludeTrack);
            if(bPlay)
            {
               m_pthread->PrerollAndWait(ticks);
               Start();
            }
         }

         void sequence::MuteTrack(int32_t iIndex, bool bMute)
         {
            bool bPlay = IsPlaying();
            imedia_position ticks = 0;
            if(bPlay)
            {
               ticks = get_position_ticks();
               Stop();
            }
            get_file()->MuteTrack(iIndex, bMute);
            if(bPlay)
            {
               m_pthread->PrerollAndWait(ticks);
               Start();
            }
         }

         imedia_position sequence::GetQuarterNote()
         {
            return get_file()->m_pFileHeader->GetQuarterNoteTicks();
         }


         int32_t sequence::GetDefaultCodePage()
         {
            return 1252;
         }


         bool sequence::IsSettingPosition()
         {
            return m_flags.is_signalized(::music::midi::sequence::e_flag_setting_position);
         }


         void sequence::SetSettingPositionFlag(bool bSet)
         {
            if(bSet)
               m_flags.signalize(::music::midi::sequence::e_flag_setting_position);
            else
               m_flags.unsignalize(::music::midi::sequence::e_flag_setting_position);
         }


         void sequence::seq_start()
         {

            m_io = ref ___new message_io;

            int i = 10;

            while (true)
            {
               int iPortCount = m_io->get_out_port_count();

               if (iPortCount > 0)
               {

                  Sleep(500);

                  break;

               }
               Sleep(500);

               i--;

               if (i < 0)
               {

                  return;

               }
            }

            string strPort = m_io->get_out_port_name(0);

            if (strPort.is_empty())
            {

               return;

            }

            m_io->select_out_port(strPort);

            m_pthreadPlay = ___new ::music::midi::winrt::thread(m_pobject);

            m_pthreadPlay->m_pseq = this;

            m_pthreadPlay->begin();

         }


      } // namespace winrt


   } // namespace midi


} // namespace music









