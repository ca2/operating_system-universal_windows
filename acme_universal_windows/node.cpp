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


   void node::implement(::pointer<::acme::node>& pnode, ::pointer<::acme::system>& psystem)
   {

      //auto psystem = acmesystem();

      //auto estatus = 

      psystem->main();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


   string node::audio_get_default_implementation_name()
   {

      return acmesystem()->implementation_name("audio", "xaudio");

   }


   string node::veriwell_multimedia_music_midi_get_default_implementation_name()
   {

      return acmesystem()->implementation_name("music_midi", "winrt");

   }


   bool node::set_process_priority(::enum_priority epriority)
   {


      return false;


   }


   //void node::unzip_to_folder(const ::file::path & pathFolder, const ::file::path & pathZip)
   //{


   //   auto pfile = __new(::acme_universal_windows::native_buffer(pathZip, ::file::e_open_read | ::file::e_open_binary));

   //   pfile->initialize(this);

   //   ::winrt::Windows::Compression::

   //   //unzip
   //   ZipArchive archive = new ZipArchive(a);
   //   archive.ExtractToDirectory(folder.Path);

   //}


} // namespace acme_universal_windows



