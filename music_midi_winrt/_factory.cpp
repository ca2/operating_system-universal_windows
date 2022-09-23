#include "framework.h"
#include "midi.h"


__FACTORY_EXPORT void music_midi_winrt_factory(::factory::factory * pfactory)// :
   // ::object(pobject) //,
            //::multimedia::winrt::factory_exchange(pobject)
{

   // pfactory->add_factory_item < ::music::midi::winrt::sequence, ::music::midi::sequence                  >();
   //       pfactory->add_factory_item < buffer, ::music::midi::file::buffer                 >();
   //       pfactory->add_factory_item < sequence_thread, ::music::midi::sequence_thread                 >();
     //       pfactory->add_factory_item < player::player  ,::music::midi::player::player                 > ();
            pfactory->add_factory_item < ::music::midi::winrt::midi, ::music::midi::midi>();
            //add_factory_item < player:: player_interface   >  (psystem->type_info < ::music::midi::player::player_interface                 > ());

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
//void ca2_factory(::object * pobject)
//{
//
//   ::music::midi::winrt::factory_exchange factoryexchange(pobject);
//
//}









