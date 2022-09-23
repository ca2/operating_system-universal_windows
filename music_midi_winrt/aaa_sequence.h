#pragma once


#define  VERSION_MINOR              0x00
#define  VERSION_MAJOR              0x04
#define  SEQ_VERSION                ((uint32_t)(WORD)((BYTE)VERSION_MINOR | (((WORD)(BYTE)VERSION_MAJOR) << 8)))

#define MMSG_DONE                   (WM_USER+20)


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         ref class message_io;

         class buffer;
         class sequence;
         class sequence_thread;
         class thread;


         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT midi_callback_data
         {
         public:


            sequence *          m_psequence;


         };


         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT sequence :
            virtual public ::music::midi::sequence
         {
         public:

            class buffer_array;


            class buffer
            {
            public:


//               MIDIHDR              m_midihdr;
               memory    m_storage;
               bool                 m_bPrepared;

               bool IsPrepared();
               void Reset();
               void Initialize(int32_t iSize, uint_ptr dwUser);

               //::e_status midiStreamOut(HMIDISTRM hmidiout);
               //::e_status midiOutPrepareHeader(HMIDIOUT hmidiout);
               //::e_status midiOutUnprepareHeader(HMIDIOUT hmidiout);


               //inline LPMIDIHDR GetMidiHdr() { return &m_midihdr; }

               //void SetNextMidiHdr(LPMIDIHDR lpNext);


            };

            ::e_status SendGMReset();


            class buffer_array :
               public array < buffer, buffer >
            {
            public:


               void Reset();
               void Initialize(int32_t iCount, int32_t iSize, uint_ptr dwUser);


               //::e_status midiStreamOut(HMIDISTRM hmidiout);
               //::e_status midiOutPrepareHeader(HMIDIOUT hmidiout);
               //::e_status midiOutUnprepareHeader(HMIDIOUT hmidiout);

            };

            midi_callback_data            m_midicallbackdata;

            message_io ^ m_io;

            thread      *     m_pthreadPlay;


            sequence(::object * pobject);
            virtual ~sequence();



            void MuteAll(bool bMute = true, int32_t iExcludeTrack = -1);
            void MuteTrack(int32_t iIndex, bool bMute = true);


            virtual int32_t GetDefaultCodePage();

            //void Prepare(::ikaraoke::data & data);
            //void Prepare(int32_t iTrack, ::ikaraoke::data & data);
            //void Prepare(
            //   string2a & str2a,
            //   imedia::position_2darray & tka2DTokensTicks,
            //   int32_t iMelodyTrack,
            //   int2a & ia2TokenLine,
            //   ::ikaraoke::data & data);

            imedia_position get_position_ticks() override;
            void SetLevelMeter(int32_t iLevel);
            ::e_status CloseStream();
            bool SetMidiOutDevice(uint32_t uiDevice);
            int32_t SetKeyShift(int32_t iKeyShift);
            int32_t GetKeyShift();

            void on_midi_playback_end(::music::midi::sequence::event * pevent);
            int32_t SetTempoShift(int32_t iTempoShift);

            //void OnPositionCB(LPMIDIHDR lpmidihdr);
            //void OnDone(HMIDISTRM hmidistream, LPMIDIHDR lpmidihdr);
            virtual void GetTimeLength(imedia_time & time);
            virtual void GetPositionLength(imedia_position & position);

            using ::ikaraoke::karaoke::TimeToPosition;
            using ::ikaraoke::karaoke::PositionToTime;

            virtual imedia_position TimeToPosition(imedia_time time);
            virtual imedia_time PositionToTime(imedia_position position);

            virtual bool IsOpened();

            virtual bool IsNull();
            virtual void SetTempoChangeFlag(bool bSet = true);
            virtual bool IsChangingTempo();

            virtual double GetTempoShift() override;

            virtual void OnEvent(::music::midi::sequence::event * pevent);


            ::e_status AllocBuffers();

            VOID FreeBuffers();

            //::e_status OpenFile(const ::string & lpFileName, int32_t openMode);
            e_result OpenFile(::music::midi::sequence & sequence, int32_t iOpenMode);
            e_result OpenFile(::file::file & ar, int32_t openMode);
            e_result OpenFile(const ::string & lpFileName, int32_t openMode);
            e_result OpenFile(memory * pmemorystorage, int32_t openMode, ::music::e_storage estorage);

            e_result CloseFile();
            e_result SaveFile(const ::string & lpFileName);
            e_result SaveFile();
            e_result SaveFile(::file::file_sp &ar);

            ::e_status Preroll(::thread * pthread, ::music::midi::LPPREROLL lpPreroll, bool bThrow);
            ::e_status Start();

            ::e_status Pause();

            ::e_status Restart();

            void seq_start();

            //::e_status Stop(uint32_t dwEllapse);
            ::e_status Stop();

            virtual void get_position(imedia_position  & time) override;
            //virtual void get_time(imedia_time  & time) override;

            ::e_status get_ticks(imedia_position & time);
            ::e_status get_millis(imedia_time & time);


            imedia_position MillisecsToTicks(imedia_time msOffset);

            imedia_time TicksToMillisecs(imedia_position tkOffset);
            uint64_t TickToMicro(imedia_position tkOffset);

            bool IsPlaying();

            //static void CALLBACK MidiOutProc(HMIDIOUT hmo, UINT wMsg, DWORD_PTR dwInstance, DWORD_PTR dwParam1, DWORD_PTR dwParam2);


            bool IsSettingPosition();
            void SetSettingPositionFlag(bool bSet = true);

            imedia_position GetQuarterNote();


            inline sp(::music::midi::winrt::buffer) file()
            {
               return get_file();
            }

            inline sp(::music::midi::winrt::sequence_thread) thread()
            {
               return m_pthread;
            }

            //using ::music::midi::sequence::create_new_event;
            //virtual ::music::midi::sequence::event * create_new_event(::music::midi::sequence::e_event eevent);

         };


      } // namespace winrt


   } // namespace midi


} // namespace music







