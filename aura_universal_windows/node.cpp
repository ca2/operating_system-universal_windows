// Created by camilo on 2021-08-30 21:54 BRT <3ThomasBS_!!
#include "framework.h"


float g_DPIScaleX__2;
float g_DPIScaleY__2;


namespace aura
{


   namespace universal_windows
   {

  
      node::node()
      {

      }
       
      
      node::~node()
      {


      }


      ::e_status node::main()
      {

         //auto psystem = m_psystem;

         //auto estatus = psystem->main();

         //if (!estatus)
         //{

         //   return estatus;

         //}

         //return estatus;

         return ::success;

      }


      void node::dpi_os_initialize()
      {

         m_psystem->m_paurasystem->get_session()->m_puser->m_pwindowing->windowing_branch(__routine([this]()
            {
               //::wait(::winrt::Windows::ApplicationModel::Core::CoreApplication::MainView->CoreWindow->Dispatcher->RunAsync(::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal, ref new ::winrt::Windows::UI::Core::DispatchedHandler([]()
                 // {

               auto displayinformation = ::winrt::Windows::Graphics::Display::DisplayInformation::GetForCurrentView();

               g_DPIScaleX__2 = displayinformation.LogicalDpi();
               g_DPIScaleY__2 = displayinformation.LogicalDpi();

               //   })));
            }));

      }




   } // namespace universal_windows


} // namespace aura



