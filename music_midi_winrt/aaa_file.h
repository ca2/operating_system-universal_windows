#pragma once


#define C_TEMPO_MAP_CHK     16


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT buffer :
            virtual public ::music::midi::file::buffer
         {
         public:



            buffer(::particle * pparticle);
            virtual ~buffer();


            //double GetTempoShiftRate();

            //bool IsTrackMute(int32_t iIndex);

            //void MuteAll(bool bMute = true, int32_t iExcludeTrack = -1);

            //void MuteTrack(int32_t iIndex, bool bMute = true);

            //e_result WorkSeekBegin();

            //e_result CalcTkLength();

            ////e_result CreateTempoMap();

            //::e_status ImmediatePutTempoChange();

            //::music::e_result GetTempoEvent(::music::midi::happening & happening);

            //void OnStop();

            //uint32_t GetImageSize();

            //LPBYTE GetImage();

            //::music::e_result Format0();

            //::music::e_result InsertTempoEvent();

            //::music::midi::tempo_map_entry * GetTempoMapEntry(const imedia_position & position);

            //virtual double GetTempoShift() override;

            //::music::e_result SetTempoShift(double dTempoShift);

            //void ToWorkStorage();

            //void FromWorkStorage();

            //int32_t GetKeyShift();

            //int32_t SetKeyShift(int32_t iKeyShift);

            //bool IsSoftKaraokeFile(bool bWork = false, string_array_base * pstra = NULL);

            //bool IsXFFile();

            //bool IsTune1000File();

            //bool IsOpened();

            //e_result RebuildIndex();

            //e_result WriteHeader(MIDIFILEHDR * lpmfh);

            //e_result ChangeEventDelta(::music::midi::happening *pEvent, imedia_position tickNewDelta);

            //e_result ReplaceSameDeltaEvent(::music::midi::happening & pEventNew);

            //e_result GetPreviousEvent(::music::midi::happening * pPreviousEvent, ::music::midi::happening * pEvent);

            //e_result SaveFile(const ::string & lpFilePath);

            //e_result WorkWriteXFTracks(string_array_base & tokena, imedia::position_array & positiona, ::music::xf::info_header & xfinfoheader);

            ////int32_t CalcMelodyTrack(::music::midi::happenings ** ppEvents, imedia::position_array & ticka);

            ////int32_t WorkCalcMelodyTrack(::music::midi::happenings ** ppEvents, imedia::position_array & positiona, ::int_array & iaTokenLine);

            //int32_t GetFormat();

            //e_result MergeTracks();

            //e_result WorkMergeTracks();

            ////e_result WorkStreamRender(LPMIDIHDR lpmh, imedia_position tickMax, uint32_t cbPrerollNomimalMax);

            //e_result WorkGetNextEvent(::music::midi::happening * & pevent, imedia_position tickMax, bool bTkMaxInclusive);

            //e_result WorkGetNextRawEvent(::music::midi::happening * & pevent, imedia_position tickMax, bool bTkMaxInclusive);

            //e_result WorkGetNextRawMidiEvent(::music::midi::happening * & pevent, imedia_position tickMax, bool bTkMaxInclusive);

            //e_result WorkSeek(imedia_position tickPosition, LPMIDIHDR lpmh);

            //void delete_contents();

            //int32_t GetDivision();

            //imedia_position GetPosition();

            //void AttachSeekSync(::ikaraoke::events_tracks_v1 * ptracksv1);

            //bool IsNull();

            //void WorkSeekEnd();

            //e_result OpenFile(::music::midi::file::buffer &file, int32_t openMode);

            //e_result OpenFile(::file::stream_buffer & file, int32_t openMode);

            //e_result OpenFile(memory * pmemstorage, int32_t openMode, ::music::e_storage);

            //e_result OpenFile(memory * pmemstorage, ::music::midi::file::e_open eopenmode, ::music::e_storage estorage);

            //e_result SaveFile(::file::stream_buffer & file);

            //e_result CloseFile();

            //e_result GetFileInfo(PSMFFILEINFO psfi);

            //int_ptr TicksToMillisecs(imedia_position tickOffset);

            //void TicksToMillisecs(imedia::time_array_base *pMillisArray, imedia::position_array *pTickArray, int_ptr tickOffset);

            //void TicksToMillisecs(imedia::time_array_array_base *ptimeaaArray, imedia::position_2darray & tickaaArray, int_ptr tickOffset);

            //void PositionToTime(imedia::time_array_array_base  & timea, imedia::position_2darray  & positiona, int_ptr tickOffset);

            //void PositionToTime(imedia::time_array_base  & timea, imedia::position_array  & positiona, int_ptr tickOffset);

            //imedia_position MillisecsToTicks(imedia_time msOffset);

            //imedia_time PositionToTime(imedia_position msOffset);

            //imedia_position TimeToPosition(imedia_time msOffset);

            //void MillisecsToTicks(imedia::position_array * pTickArray, imedia::time_array_base *pMillisArray, imedia_time msOffset);

            //void TimeToPosition(imedia::position_array & positiona, imedia::time_array_base & timea, imedia_time msOffset);

            //e_result StreamRender(LPMIDIHDR lpmh, imedia_position tickMax, uint32_t cbPrerollNomimalMax);

            //::music::e_result StreamEvent(imedia_position tickDelta, ::music::midi::happening * Event, LPMIDIHDR lpmh, imedia_position tickMax, uint32_t cbPrerollNomimalMax);

            //::music::e_result StreamEventF1(imedia_position tickDelta, array < ::music::midi::happening *, ::music::midi::happening * > & eventptra, LPMIDIHDR lpmh, imedia_position tickMax, uint32_t cbPrerollNomimalMax);

            //e_result seek(imedia_position tickPosition, LPMIDIHDR lpmh);

            //e_result seek(imedia_position tickPosition);

            ////e_result Build();

            //e_result GetNextEvent(::music::midi::happening *& pevent, imedia_position tickMax, bool   bTkMaxInclusive);

            //e_result GetNextEventTkPosition(imedia_position * pTkPosition, imedia_position tickMax);

            //void _SyncSeek(imedia_position tickPosition, ::ikaraoke::events_tracks_v1 * ptracksv1);

            //void _SyncSeek(imedia_position tickPosition);

            //e_result InsertParmData(imedia_position tickDelta, LPMIDIHDR lpmh);

            //::music::e_result InsertLyricEvents(::ikaraoke::lyric_event_v1 * pLyricEvent, LPMIDIHDR lpmh);

            //e_result InsertPadEvent(imedia_position tickDelta, LPMIDIHDR lpmh);

            //void SetOpened(bool bOpened = true);


         };


      } // namespacewinrt


   } // namespace midi


} // namespace music





