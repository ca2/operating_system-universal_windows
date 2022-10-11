// From interprocess_communication.h by Camilo 2022-10-11 11:32 BRT <3ThomasBorregaardSoerensen
#pragma once


#include "apex/interprocess/base.h"


namespace apex_universal_windows
{


   class CLASS_DECL_APEX_UNIVERSAL_WINDOWS interprocess_base :
      virtual public interprocess::base
   {
   public:


      //HWND              m_hwnd;
      //string            m_strBaseChannel;


      interprocess_base();
      ~interprocess_base() override;


      //HWND get_hwnd() const { return (HWND)m_hwnd; }
      //void set_hwnd(HWND hwnd) { m_hwnd = hwnd; }

   };


} // namespace apex_universal_windows



