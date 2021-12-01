// Created by camilo on 2021-08-29 21:06 BRT <3ThomasBS_!!
#pragma once


namespace apex
{


   namespace universal_windows
   {


      class CLASS_DECL_APEX_UNIVERSAL_WINDOWS node :
         virtual public ::acme::universal_windows::node,
         virtual public ::apex::windows_common::node
      {
      public:


         ::matter_pointer           m_pClearApplicationDataHandler;


         node();
         ~node() override;


         ::e_status implement(__transport(::acme::node) & pnode, __transport(class ::system) & psystem) override;


         string system_options_main_body() override;


         //void handle(::subject * psubject, ::context * pcontext) override;


      };

   
   } // namespace universal_windows


} // namespace apex



