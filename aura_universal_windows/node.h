// Created by camilo on 2021-08-30 21:51 BRT <3ThomasBS_!!
#pragma once


namespace aura
{

   
   namespace universal_windows
   {

      class CLASS_DECL_AURA_UNIVERSAL_WINDOWS node :
         virtual public aura::windows_common::node,
         virtual public apex::universal_windows::node
      {
      public:


         node();
         ~node() override;


         ::e_status main() override;


         virtual void dpi_os_initialize();


      };


   } // namespace universal_windows


} // namespace aura



