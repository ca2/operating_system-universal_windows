// Created by camilo on 2021-08-30 16:40 BRT <3ThomasBS_!!
#pragma once


namespace acme
{


   namespace universal_windows
   {


      class CLASS_DECL_ACME_UNIVERSAL_WINDOWS node :
         virtual public ::acme::windows_common::node
      {
      public:


         node();
         ~node() override;


         void implement(__pointer(::acme::node) & pnode, __pointer(class ::system) & psystem) override;


         string audio_get_default_library_name() override;

         string veriwell_multimedia_music_midi_get_default_library_name() override;


      };


   } // namespace universal_windows


} // namespace acme



