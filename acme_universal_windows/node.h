// Created by camilo on 2021-08-30 16:40 BRT <3ThomasBS_!!
#pragma once


#include "acme_windows_common/node.h"


namespace acme_universal_windows
{


   class CLASS_DECL_ACME_UNIVERSAL_WINDOWS node :
      virtual public ::acme_windows_common::node
   {
   public:


      node();
      ~node() override;


      void implement(::pointer<::acme::node>& pnode, ::pointer<::acme::system> & psystem) override;


      string audio_get_default_library_name() override;

      string veriwell_multimedia_music_midi_get_default_library_name() override;


      bool set_process_priority(::enum_priority epriority);


   };


} // namespace acme_universal_windows



