// Created by camilo on 2021-08-29 21:11 BRT <3ThomasBS_!!
#include "framework.h"


namespace apex
{


   namespace universal_windows
   {

      
      node::node()
      {


      }


      node::~node()
      {


      }


      ::e_status node::implement(__transport(::acme::node)& pnode, __transport(class ::system)& psystem)
      {

         //auto psystem = m_psystem;

         auto estatus = psystem->main();

         if (!estatus)
         {

            return estatus;

         }

         return estatus;

      }


      string node::system_options_main_body()
      {

         string strOptions_;

         strOptions_ += "<br/>";
         strOptions_ += "<br/>";
         strOptions_ += "<input type=\"button\" id=\"clear_application_data\" value=\"Clear Application Data\"/>";
         strOptions_ += "<br/>";
         strOptions_ += "<br/>";

         if (!m_pClearApplicationDataHandler)
         {

            m_pClearApplicationDataHandler = m_psystem->m_papexsystem->add_command_handler(
               "clear_application_data",
               [this](::message::message * pmessage)
               {

                  m_psystem->m_pacmefile->clear_application_data();

               });

         }

         return strOptions_;

      }


      //void node::handle(::subject * psubject, ::context * pcontext)
      //{

      //   if (psubject->m_puserelement->m_id == "clear_application_data")
      //   {

      //      m_psystem->m_pacmefile->clear_application_data();

      //   }

      //}


   } // namespace universal_windows


} // namespace apex



