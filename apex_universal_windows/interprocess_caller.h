// From interprocess_communication.h by Camilo 2022-10-11 09:25 BRT <3ThomasBorregaardSoerensen
#pragma once


#include "interprocess_base.h"
#include "apex/interprocess/caller.h"


namespace apex_universal_windows
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS interprocess_caller :
      virtual public interprocess_base,
      virtual public interprocess::caller
   {
   public:


      interprocess_caller();
      ~interprocess_caller() override;



      //#if defined(UNIVERSAL_WINDOWS)
      //      bool open(const ::string & pszChannel) override;
      //#else
      void open(const ::string & strChannel, ::launcher * plauncher = nullptr) override;
      //#endif
      void close() override;


      void call(const ::string & strUri, const class time & timeTimeout) override;
      //void send(int message, void * pdata, int len, const class time & timeTimeout) override;


      bool is_caller_ok() override;


   };


} // namespace apex_universal_windows



