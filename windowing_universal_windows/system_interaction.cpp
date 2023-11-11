#include "framework.h"
#include "system_interaction.h"
////#include "aura/message.h"
////#include "aura/procedure.h"
#include "acme/constant/id.h"
#include "acme/constant/message.h"
#include "acme/platform/node.h"
#include "aura/graphics/image/image.h"
#include "aura/platform/system.h"
#include "aura/message/user.h"


namespace windowing_win32
{


   system_interaction::system_interaction()
   {

      m_ewindowflag -= e_window_flag_graphical;
      //m_bMessageWindow = true;

   }


   system_interaction::~system_interaction()
   {


   }


   void system_interaction::install_message_routing(::channel * pchannel)
   {

      ::user::interaction::install_message_routing(pchannel);

      MESSAGE_LINK(MESSAGE_DESTROY, pchannel, this, &system_interaction::on_message_destroy);
      MESSAGE_LINK(e_message_display_change, pchannel, this, &system_interaction::_001OnMessage);
      MESSAGE_LINK(e_message_setting_change, pchannel, this, &system_interaction::_001OnMessage);
      MESSAGE_LINK(e_message_font_change, pchannel, this, &system_interaction::_001OnMessage);

   }


   bool system_interaction::is_system_message_window()
   {

      return true;

   }


   void system_interaction::start_destroying_window()
   {

      ::user::interaction::start_destroying_window();

   }


   void system_interaction::on_message_destroy(::message::message * pmessage)
   {

      ::pointer<::user::message>pusermessage(pmessage);

      ::output_debug_string("system_interaction::on_message_destroy");

   }

   
   void system_interaction::_001OnMessage(::message::message * pmessage)
   {

      if (pmessage != nullptr)
      {

         wparam wparam = pmessage->m_wparam;

         lparam lparam = pmessage->m_lparam;

         string strLparamString;

         if (pmessage->m_atom == WM_SETTINGCHANGE && wparam == 0)
         {

            strLparamString = (const WCHAR *)(LPARAM(lparam));

         }

         if (pmessage->m_atom == WM_FONTCHANGE)
         {

            auto psystem = system()->m_paurasystem;

            psystem->signal(id_operating_system_font_list_change);

            //fork([this]()
              // {

                 // psession->call(e_routine_font_change);

               //});

         //}
         }
         else if (
            pmessage->m_atom == WM_SETTINGCHANGE &&
            strLparamString == "ImmersiveColorSet")
         {

            auto pnode = system()->m_pnode;

            pnode->fetch_user_color();

         }
         else if (pmessage->m_atom == e_message_display_change ||
            (pmessage->m_atom == WM_SETTINGCHANGE &&
               (pmessage->m_wparam == SPI_SETWORKAREA)))
         {

            output_debug_string("test");

            //throw_todo();

            //psystem->enum_display_monitors();

            //::pointer<::user::interaction>puserinteraction;

            //while(psystem->get_frame(puserinteraction))
            //{

            //   try
            //   {

            //      puserinteraction->post_message(e_message_display_change);

            //   }
            //   catch(...)
            //   {
            //   }

            //}


         }

      }


   }


} // namespace windowing_win32



