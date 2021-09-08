// created by Camilo 2021-01-31 05:26 BRT <3CamiloSasukeThomasBorregaardSoerensen
#pragma once


namespace universal_windows
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS interprocess_communication_base :
      virtual public interprocess_communication::base
   {
   public:


      HWND              m_hwnd;
      string            m_strBaseChannel;


      interprocess_communication_base();
      ~interprocess_communication_base() override;


      HWND get_hwnd() const { return (HWND)m_hwnd; }
      void set_hwnd(HWND hwnd) { m_hwnd = hwnd; }

   };


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS interprocess_communication_tx :
      virtual public interprocess_communication_base,
      virtual public interprocess_communication::tx
   {
   public:


      interprocess_communication_tx();
      ~interprocess_communication_tx() override;



//#if defined(_UWP)
//      bool open(const ::string & pszChannel) override;
//#else
      bool open(const ::string & pszChannel, ::launcher * plauncher = nullptr) override;
//#endif
      bool close() override;


      bool send(const ::string & pszMessage, duration durationTimeout) override;
      bool send(int message, void * pdata, int len, duration durationTimeout) override;


      bool is_tx_ok() override;

   };


   class rx_private;


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS interprocess_communication_rx :
      virtual public interprocess_communication_base,
      virtual public interprocess_communication::rx
   {
   public:


      interprocess_communication_rx();
      ~interprocess_communication_rx() override;


      bool create(const ::string & pszChannel) override;
      ::e_status destroy() override;


      //void * on_interprocess_receive(const ::string & pszMessage) override;
      //void * on_interprocess_receive(int message, void * pdata, memsize len) override;
      //void * on_interprocess_post(i64 a, i64 b) override;


      virtual bool on_idle() override;


      LRESULT message_queue_proc(UINT message, WPARAM wparam, LPARAM lparam);


      bool is_rx_ok();


   };


   //   class CLASS_DECL_APEX_WINDOWS interprocess_communication :
   //      virtual public interprocess_communication_base,
   //      virtual public ::interprocess_communication::interprocess_communication
   //   {
   //   public:
   //
   //
   //      interprocess_communication();
   //      virtual ~interprocess_communication();
   //
   //
   //#if defined(_UWP)
   //      bool open_ab(const ::string & pszChannel, const ::string & pszModule);
   //      bool open_ba(const ::string & pszChannel, const ::string & pszModule);
   //#elif defined(WINDOWS)
   //      bool open_ab(const ::string & pszChannel, const ::string & pszModule, launcher * plauncher = nullptr);
   //      bool open_ba(const ::string & pszChannel, const ::string & pszModule, launcher * plauncher = nullptr);
   //#else
   //      bool open_ab(const ::string & pszChannel, launcher * plauncher = nullptr);
   //      bool open_ba(const ::string & pszChannel, launcher * plauncher = nullptr);
   //#endif
   //
   //
   //      bool close();
   //
   //
   //      virtual void restart_apex_ipc();
   //
   //      //bool ensure_tx(const ::string & pszMessage, duration durationTimeout = one_hour());
   //      //bool ensure_tx(int message, void * pdata, int len, duration durationTimeout = one_hour());
   //
   //
   //      bool is_rx_tx_ok();
   //
   //
   //   };


   CLASS_DECL_APEX_UNIVERSAL_WINDOWS string app_install(string strPlatform = "");


} // namespace universal_windows


