#pragma once



namespace music
{


   namespace midi
   {


      namespace winrt
      {


         class sequence_thread;


         namespace player
         {

            class player_callback;
            class player_interface;




            class CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT player :
               virtual public ::music::midi::player::player
            {
            public:


               player(::object * pobject);
               virtual ~player();


               void install_message_routing(::message::sender * pinterface);


               //void SendMmsgDone(::music::midi::sequence *pSeq, ::music::midi::LPMIDIDONEDATA lpmdd);
               void SetCallbackWindow(sp(::user::interaction) puie);
               bool PlayRate(double dRate = 0.0, uint32_t dwEllapse = 584);
               bool Play(imedia_position tkStart, uint32_t dwEllapse = 584);


               virtual bool init_thread() override;
               virtual void term_thread() override;


               virtual void pre_translate_message(::message::message * pmessage) override;
               void OnMmsgDone(::music::midi::sequence *pSeq);
               void SaveFile(const char * lpszPathName);
               void SetPosition(double dRate);
               void Pause();
               void CloseFile();
               void SendReset();
               bool ExecuteCommand(::music::midi::player::e_command ecommand, uint32_t dwEllapse);
               virtual void OnMidiOutDeviceChange();

               uint32_t GetMidiOutDevice();
               void PostNotifyEvent(::music::midi::player::e_notify_event eevent);

               imedia_position RateToTicks(double dRate);

               bool SetTempoShift(int32_t iTempoShift);

               bool SetMidiOutDevice(uint32_t uiDevice);

               //::music::e_result SetInterface(player_interface * pinterface);

               ::multimedia::e_result Initialize(::thread * pthread);

               bool IsPlaying();

               void PostGMReset();
               void PostTempoChange();
               void SendTempoChange(); // verificar


               DECLARE_MESSAGE_HANDLER(OnUserMessage);
               DECLARE_MESSAGE_HANDLER(OnNotifyEvent);
               DECLARE_MESSAGE_HANDLER(OnMultimediaMidiOutputMessageDone);
               DECLARE_MESSAGE_HANDLER(OnMultimediaMidiOutputMessagePositionCB);

               // midi central listener
               DECLARE_MESSAGE_HANDLER(on_attribute_change);


            };


         } // namespace player


      } // namespace winrt


   } // namespace midi_winrt


} // namespace music






