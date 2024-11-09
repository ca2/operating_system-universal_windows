#pragma once



namespace music
{


   namespace midi
   {


      namespace winrt
      {


         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT thread :
            virtual public ::thread
         {
         public:


            sequence *              m_pseq;

            manual_reset_happening      m_happeningRun;

            imedia_position         m_tkPosition;

            uint64_t                m_uiStart;

            uint64_t                m_uiOffset;


            thread(::particle * pparticle);
            virtual ~thread();


            virtual void run() override;


         };


      } // namespace winrt


   } // namespace midi_winrt


} // namespace music





