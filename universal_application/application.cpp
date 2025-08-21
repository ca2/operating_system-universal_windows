#include "framework.h"


namespace app_net
{


   __IMPLEMENT_APPLICATION_RELEASE_TIME();
IMPLEMENT_APPLICATION_FACTORY();


   application::application()
   {

      m_strAppId = "app/app";

      m_strBaseSupportId = "app_app";

      m_strAppName = "app/app";

      m_bLicense = false;

   }


   application::~application()
   {

   }


   void application::init_instance()
   {

      if (!::aura::application::init_instance())
      {

         return false;

      }

      return true;

   }


   void application::term_application()
   {

      ::aura::application::term_application();

   }


   void application::on_request(::request * prequest)
   {

      øconstruct_new(m_pwindow);

      m_pwindow->create_main_window();

      m_pwindow->start_layout();

      m_pwindow->display(e_display_normal);

      m_pwindow->set_need_layout();

      m_pwindow->set_need_redraw();

      m_pwindow->set_layout_ready();

      m_pwindow->post_redraw();

   }


#ifdef _DEBUG


   int64_t application::increment_reference_count()
   {

      return ::object::increment_reference_count();

   }


   int64_t application::decrement_reference_count()
   {

      return ::object::decrement_reference_count();

   }


#endif


   __namespace_application_factory("app/net");


} // namespace app_net



