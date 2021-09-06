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


//#ifdef _UWP
//
//         Agile < ::winrt::Windows::UI::Core::CoreWindow >      m_window;
//
//#endif

         node();
         ~node() override;


      };

   
   } // namespace universal_windows


} // namespace apex



