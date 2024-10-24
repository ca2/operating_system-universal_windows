// Created by camilo on 2021-08-30 16:40 BRT <3ThomasBS_!!
#include "framework.h"
#include "node.h"
#include "acme/platform/system.h"


namespace acme_universal_windows
{


   node::node()
   {

   }


   node::~node()
   {


   }


   //void node::implement(::pointer<::acme::node>& pnode, ::pointer<::platform::system>& psystem)
   void node::node_main()
   {

      //auto psystem = system();

      //auto estatus = 

      //system()->main();

      ::acme::node::node_main();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


   void node::on_start_system()
   {

      system()->on_branch_system_from_main_thread_startup();

   }


   string node::audio_get_default_implementation_name()
   {

      return system()->implementation_name("audio", "xaudio");

   }


   string node::veriwell_multimedia_music_midi_get_default_implementation_name()
   {

      return system()->implementation_name("music_midi", "winrt");

   }


   bool node::set_process_priority(::enum_priority epriority)
   {


      return false;


   }


   //void node::unzip_to_folder(const ::file::path & pathFolder, const ::file::path & pathZip)
   //{


   //   auto pfile = __allocate< ::acme_universal_windows::native_buffer >(pathZip, ::file::e_open_read | ::file::e_open_binary);

   //   pfile->initialize(this);

   //   ::winrt::Windows::Compression::

   //   //unzip
   //   ZipArchive archive = ___new ZipArchive(a);
   //   archive.ExtractToDirectory(folder.Path);

   //}


} // namespace acme_universal_windows



