// Created by camilo on 2021-08-29 21:06 BRT <3ThomasBS_!!
#pragma once


#include "acme_universal_windows/node.h"
#include "apex_windows_common/node.h"


namespace apex_universal_windows
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS node :
      virtual public ::acme_universal_windows::node,
      virtual public ::apex_windows_common::node
   {
   public:


      ::pointer < ::particle >           m_pClearApplicationDataHandler;


      node();
      ~node() override;


      //void implement(::pointer<::acme::node> & pnode, ::pointer<::acme::system> & psystem) override;

      void node_main() override;


      string system_options_main_body() override;


      //void handle(::topic * ptopic, ::context * pcontext) override;


   };


} // namespace apex_universal_windows



