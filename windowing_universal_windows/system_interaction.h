#pragma once


#include "aura/user/user/interaction.h"


namespace windowing_win32
{

   // top level window for receiving system messages broadcasted to top level windows in Windows

   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS system_interaction :
      virtual public ::user::interaction
   {
   public:


      system_interaction();
      ~system_interaction() override;


      void install_message_routing(::channel * pchannel) override;

      DECLARE_MESSAGE_HANDLER(_001OnMessage);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);


      //void start_destroying_window() override;

      bool is_system_message_window() override;


   };


} // namespace windowing_win32



