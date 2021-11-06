#include "framework.h"


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         ::e_status translate_hr(HRESULT hr)
         {

            if(SUCCEEDED(hr))
            {

               return ::success;

            }
            else
            {

               return ::error_failed;

            }

         }


      } // namespace winrt

   } // namespace midi_winrt


} // namespace music      
