#pragma once


namespace sockets
{


   class CLASS_DECL_APEX sip_event :
      virtual public base_object
   {
   public:
      enum e_happening
      {
         event_invite,
      };

      e_happening     m_eevent;

      sip_event(::ca::application * papp);
   };


} // namespace sockets



