#pragma once


namespace music
{


   namespace midi
   {


      namespace winrt
      {

         class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT out :
            virtual public ::music::midi::message_out
         {
         public:


//            HMIDIOUT       m_hmidiout;

            ::winrt::agile_ref < IMidiOutPort >    m_midiOutPort;


            out();
            ~out() override;


            virtual ::e_status open();
            virtual ::e_status close();

            ::e_status note_on(int iChannel, unsigned char uchNote, unsigned char uchVelocity) override;
            ::e_status note_off(int iChannel, unsigned char uchNote, unsigned char uchVelocity) override;
            ::e_status program_change(int iChannel, unsigned char uchProgram) override;
            void control_change(int iChannel, unsigned char uchController, unsigned char uchValue);
            void pitch_bend(int iChannel, unsigned short ushBend);
            void send(IMidiMessage const & message);


            ::e_status send_short_message(::music::midi::e_message emessage, int iChannel, int iData1, int iData2);

         };


      } // namespace winrt


   } // namespace midi


} // namespace music




