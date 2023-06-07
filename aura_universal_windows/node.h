// Created by camilo on 2021-08-30 21:51 BRT <3ThomasBS_!!
#pragma once


#include "aura_windows_common/node.h"
#include "apex_universal_windows/node.h"


namespace aura_universal_windows
{


   class CLASS_DECL_AURA_UNIVERSAL_WINDOWS node :
      virtual public ::aura_windows_common::node,
      virtual public ::apex_universal_windows::node
   {
   public:


      node();
      ~node() override;


      //void on_request(::request * prequest) override;


      void dpi_os_initialize() override;


   };


} // namespace aura_universal_windows



