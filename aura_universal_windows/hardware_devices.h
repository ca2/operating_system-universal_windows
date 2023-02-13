// From windowing_win32/devices by camilo on 2023-02-12 18:20 <3ThomasBorregaardS�rensen!!
#pragma once


#include "aura/hardware/devices.h"


#include "acme/_operating_system.h"


namespace aura_universal_windows
{


   class CLASS_DECL_AURA_UNIVERSAL_WINDOWS devices :
      virtual public ::hardware::devices
   {
   public:


      //HWND                                                                       m_hwnd;
      //map < ::hardware::enum_device, ::pointer<master_device_listener >>        m_mapmasterdevicelistener;


      devices();
      ~devices() override;

      virtual void on_initialize_object();

      void on_message_device_change(::message::message * pmessage);

      void register_device_listener(::hardware::device_listener * pdevicelistener, ::hardware::enum_device edevice) override;

      //void _register_device_listener(master_device_listener * pdevicelistener, GUID InterfaceClassGuid);


   };


} // namespace aura_universal_windows



