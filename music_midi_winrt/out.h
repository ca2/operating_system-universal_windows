#pragma once


#include "acme/primitive/primitive/memory.h"
#include "app-veriwell/multimedia/music/midi/out.h"
#undef new
#include <winrt/Windows.Devices.h>
#include <winrt/Windows.Devices.Midi.h>


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
            memory m_memoryBuffer;
            ::winrt::agile_ref < ::winrt::Windows::Devices::Midi::IMidiOutPort >    m_midiOutPort;


            out();
            ~out() override;


            void open() override;
            void close() override;


            void note_on(int iChannel, unsigned char uchNote, unsigned char uchVelocity) override;
            void note_off(int iChannel, unsigned char uchNote, unsigned char uchVelocity) override;
            void program_change(int iChannel, unsigned char uchProgram) override;
            void control_change(int iChannel, unsigned char uchController, unsigned char uchValue);
            void pitch_bend(int iChannel, unsigned short ushBend);
            void send(::winrt::Windows::Devices::Midi::IMidiMessage const & message);


            void send_short_message(::music::midi::enum_midi_message emessage, int iChannel, int iData1, int iData2);

            bool step() override;

         };


      } // namespace winrt


   } // namespace midi


} // namespace music




