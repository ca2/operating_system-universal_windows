#pragma once


#include "app-veriwell/multimedia/multimedia/_.h"
#include "acme_universal_windows/_.h"


#if defined(_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT_LIBRARY)
   #define CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT  CLASS_DECL_IMPORT
#endif



namespace music
{


   namespace midi
   {


      namespace winrt
      {

         
         class midi;


      } // namespace winrt


   } // namespace midi


} // namespace music



