#include "framework.h"


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         factory_exchange::factory_exchange(::context_object * pcontextobject) :
            ::object(pobject) //,
            //::multimedia::winrt::factory_exchange(pobject)
         {

            create_factory < sequence                    >  (psystem->type_info < ::music::midi::sequence                  > ());
            create_factory < buffer                      >  (psystem->type_info < ::music::midi::file::buffer                 > ());
            create_factory < sequence_thread             >  (psystem->type_info < ::music::midi::sequence_thread                 > ());
            create_factory < player::player              >  (psystem->type_info < ::music::midi::player::player                 > ());
            create_factory < midi              >(psystem->type_info < ::music::midi::midi>());
            //create_factory < player:: player_interface   >  (psystem->type_info < ::music::midi::player::player_interface                 > ());

         }


         factory_exchange::~factory_exchange()
         {

         }


      } // namespace winrt


   } // namespace midi_winrt


} // namespace music


void ca2_factory_exchange(::context_object * pcontextobject)
{

   ::music::midi::winrt::factory_exchange factoryexchange(pobject);

}









