#pragma once


#include "aura/user/user/copydesk.h"


namespace windowing_universal_windows
{


   class CLASS_DECL_WINDOWING_UNIVERSAL_WINDOWS copydesk :
      virtual public ::user::copydesk
   {
   public:


      //HWND m_hwnd;

      //::pointer<::user::interaction>     m_puserinteraction;

      /// negative value undefined
      ::collection::count  m_cFileCount;
      /// -2 value undefined
      int   m_iPriorityTextFormat;
      /// negative value undefined
      int  m_iFilea;
      /// negative value undefined
      int  m_iText;
      /// negative value undefined
      int  m_iDib;


      copydesk();
      ~copydesk() override;


      //static lresult WINAPI WindowProc(HWND hwnd, unsigned int message, wparam wparam, lparam lparam);


      DECLARE_MESSAGE_HANDLER(_001OnClipboardUpdate);
      DECLARE_MESSAGE_HANDLER(on_message_destroy);

      //void install_message_routing(::channel * pchannel) override;



      void initialize(::particle * pparticle) override;
      void destroy() override;


      virtual void OnClipboardUpdate();

      virtual ::collection::count _get_file_count();
      virtual int _get_priority_text_format();

      //virtual HGLOBAL hglobal_get_filea(const ::file::path_array & stra);
      //virtual HGLOBAL hglobal_get_wide_text(const ::string & str);
      //virtual HGLOBAL hglobal_get_utf8_text(const ::string & str);
      //virtual HGLOBAL hglobal_get_image(const ::image::image * pimage);

      bool _set_filea(const ::file::path_array & stra, enum_op eop) override;
      bool _get_filea(::file::path_array & stra, enum_op & eop) override;
      bool _has_filea() override;

      bool _set_plain_text(const ::string & str) override;
      bool _get_plain_text(string & str) override;
      bool _has_plain_text() override;

      bool _desk_to_image(::image::image * pimage) override;
      bool _image_to_desk(const ::image::image * pimage) override;
      bool _has_image() override;


   };


} // namespace windowing_universal_windows



