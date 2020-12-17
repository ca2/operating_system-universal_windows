#include "framework.h"


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         factory_exchange::factory_exchange(::layered * pobjectContext) :
            ::object(pobject) //,
            //::multimedia::winrt::factory_exchange(pobject)
         {

            create_factory < sequence                    >  (System.type_info < ::music::midi::sequence                  > ());
            create_factory < buffer                      >  (System.type_info < ::music::midi::file::buffer                 > ());
            create_factory < sequence_thread             >  (System.type_info < ::music::midi::sequence_thread                 > ());
            create_factory < player::player              >  (System.type_info < ::music::midi::player::player                 > ());
            create_factory < midi              >(System.type_info < ::music::midi::midi>());
            //create_factory < player:: player_interface   >  (System.type_info < ::music::midi::player::player_interface                 > ());

         }


         factory_exchange::~factory_exchange()
         {

         }


      } // namespace winrt


   } // namespace midi_winrt


} // namespace music


void ca2_factory_exchange(::layered * pobjectContext)
{

   ::music::midi::winrt::factory_exchange factoryexchange(pobject);

}








