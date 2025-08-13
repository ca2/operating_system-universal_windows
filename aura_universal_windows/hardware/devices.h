// From windowing_win32/devices by camilo on 2023-02-12 18:20 <3ThomasBorregaardSorensen!!
#pragma once


#include "aura/hardware/devices.h"


#include "acme/_operating_system.h"


namespace aura_universal_windows
{


   namespace hardware
   {


      class CLASS_DECL_AURA_UNIVERSAL_WINDOWS devices :
         virtual public ::hardware::devices
      {
      public:


         //HWND                                                                       m_hwnd;
         //map_base < ::hardware::enum_device, ::pointer<master_device_listener >>        m_mapmasterdevicelistener;


         devices();
         ~devices() override;

         virtual void on_initialize_object();

         void on_message_device_change(::message::message * pmessage);

         void register_device_listener(::hardware::device_listener * pdevicelistener, ::hardware::enum_device edevice) override;

         //void _register_device_listener(master_device_listener * pdevicelistener, GUID InterfaceClassGuid);

         //void on_register_device_listener(::hardware::enum_device edevice) override;


         void update_device_list(::hardware::enum_device edevice) override;


      };


   } // namespace hardware


} // namespace aura_universal_windows



