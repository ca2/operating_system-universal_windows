// created by Camilo 2021-01-31 05:26 BRT <3CamiloSasukeThomasBorregaardSoerensen
#pragma once


#include "interprocess_caller.h"
#include "apex/interprocess/target.h"


namespace apex_universal_windows
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS interprocess_target :
      virtual public interprocess_base,
      virtual public interprocess::target
   {
   public:


      interprocess_target();
      ~interprocess_target() override;


      void create(const ::string & strChannel) override;
      void destroy() override;


      //void * on_interprocess_receive(const ::string & pszMessage) override;
      //void * on_interprocess_receive(int message, void * pdata, memsize len) override;
      //void * on_interprocess_post(i64 a, i64 b) override;


      virtual bool on_idle() override;


      //LRESULT message_queue_proc(UINT message, WPARAM wparam, LPARAM lparam);


      bool is_rx_ok();


   };


   //   class CLASS_DECL_APEX_WINDOWS interprocess_handler :
   //      virtual public interprocess_communication_base,
   //      virtual public ::interprocess_handler::interprocess_handler
   //   {
   //   public:
   //
   //
   //      interprocess_handler();
   //      virtual ~interprocess_handler();
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
   //      //bool ensure_tx(const ::string & pszMessage, time timeTimeout = one_hour());
   //      //bool ensure_tx(int message, void * pdata, int len, time timeTimeout = one_hour());
   //
   //
   //      bool is_rx_tx_ok();
   //
   //
   //   };


   CLASS_DECL_APEX_UNIVERSAL_WINDOWS string app_install(string strPlatform = "");


} // namespace apex_universal_windows



