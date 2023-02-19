#pragma once


//#include "app-veriwell/multimedia/multimedia/_multimedia.h"
//#include "acme_universal_windows/_windows_runtime.h"
//
//
//#if defined(_veriwell_multimedia_music_midi_winrt_project)
//   #define CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT  CLASS_DECL_EXPORT
//#else
//   #define CLASS_DECL_VERIWELL_MULTIMEDIA_MUSIC_MIDI_WINRT  CLASS_DECL_IMPORT
//#endif
//
////#include <collection.h>
//
//#include <winrt/Windows.Devices.h>
//#include <winrt/Windows.Devices.Enumeration.h>
//#include <winrt/Windows.Devices.Midi.h>
//////////////
///////////////* MIDI data block header */
//////////////typedef struct midihdr_tag {
//////////////   LPSTR       lpData;               /* pointer to locked data block */
//////////////   DWORD       dwBufferLength;       /* length of data in data block */
//////////////   DWORD       dwBytesRecorded;      /* used for input only */
//////////////   DWORD_PTR   dwUser;               /* for client's use */
//////////////   DWORD       dwFlags;              /* assorted flags (see defines) */
//////////////   struct midihdr_tag far *lpNext;   /* reserved for driver */
//////////////   DWORD_PTR   reserved;             /* reserved for driver */
//////////////
//////////////   DWORD       dwOffset;             /* Callback offset into buffer */
//////////////   DWORD_PTR   dwReserved[8];        /* Reserved for MMSYSTEM */
//////////////} MIDIHDR, *PMIDIHDR, NEAR *NPMIDIHDR, FAR *LPMIDIHDR;
//////////////
//////////////
//////////////typedef struct midievent_tag
//////////////{
//////////////   DWORD       dwDeltaTime;          /* Ticks since last event */
//////////////   DWORD       dwStreamID;           /* Reserved; must be zero */
//////////////   DWORD       dwEvent;              /* Event type and parameters */
//////////////   DWORD       dwParms[1];           /* Parameters if this is a long event */
//////////////} MIDIEVENT;
//////////////
//
//
////using namespace Platform::Collections;
//using namespace ::winrt::Windows::Foundation;
//using namespace ::winrt::Windows::Foundation::Collections;
////using namespace ::winrt::Windows::UI;
////using namespace ::winrt::Windows::UI::Core;
////using namespace ::winrt::Windows::UI::Xaml;
////using namespace ::winrt::Windows::UI::Xaml::Controls;
////using namespace ::winrt::Windows::UI::Xaml::Navigation;
////using namespace ::winrt::Windows::Storage::Streams;
//using namespace ::winrt::Windows::Devices::Midi;
//
////using namespace SDKSample::MIDI;
////using namespace concurrency;
//
//#include "translation.h"
//
////#include "sequence.h"
//
//#include "io.h"
//
////#include "player/music_midi_winrt_player.h"
//
//#include "out.h"
//
////#include "music_midi_winrt_file.h"
//          
////#include "music_midi_winrt_sequence_thread.h"
//
////#include "music_midi_winrt_thread.h"
//
////#include "factory_exchange.h"
//
//#include "device_watcher.h"
//
//
//#include "midi.h"
//
