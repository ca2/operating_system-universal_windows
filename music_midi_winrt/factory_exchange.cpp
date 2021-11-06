#include "framework.h"
//

extern "C"
void music_midi_winrt_factory_exchange(::factory_map * pfactorymap)// :
   // ::object(pobject) //,
            //::multimedia::winrt::factory_exchange(pobject)
         {

   // pfactorymap->create_factory < ::music::midi::winrt::sequence, ::music::midi::sequence                  >();
   //       pfactorymap->create_factory < buffer, ::music::midi::file::buffer                 >();
   //       pfactorymap->create_factory < sequence_thread, ::music::midi::sequence_thread                 >();
     //       pfactorymap->create_factory < player::player  ,::music::midi::player::player                 > ();
            pfactorymap->create_factory < ::music::midi::winrt::midi, ::music::midi::midi>();
            //create_factory < player:: player_interface   >  (psystem->type_info < ::music::midi::player::player_interface                 > ());

         }

//
//         factory_exchange::~factory_exchange()
//         {
//
//         }
//
//
//      } // namespace winrt
//
//
//   } // namespace midi_winrt
//
//
//} // namespace music
//
//
//void ca2_factory_exchange(::object * pobject)
//{
//
//   ::music::midi::winrt::factory_exchange factoryexchange(pobject);
//
//}









