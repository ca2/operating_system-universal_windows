// Created by camilo on 2021-08-30 16:40 BRT <3ThomasBS_!!
#include "framework.h"
#include "node.h"


namespace acme_universal_windows
{


   node::node()
   {

   }


   node::~node()
   {


   }


   void node::implement(::pointer<::acme::node> pnode, ::pointer<::acme::system>psystem)
   {

      //auto psystem = m_psystem;

      //auto estatus = 

      psystem->main();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


   string node::audio_get_default_library_name()
   {

      return "audio_xaudio";

   }


   string node::veriwell_multimedia_music_midi_get_default_library_name()
   {

      return "music_midi_winrt";

   }


} // namespace acme_universal_windows



