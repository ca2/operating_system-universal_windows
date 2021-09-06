// Created by camilo on 2021-09-04 22:55 BRT <3ThomasBS_!!
#include "framework.h"


float g_DPIScaleX__2;
float g_DPIScaleY__2;


namespace windowing_universal_windows
{


   node::node() :
      m_frameworkviewsource(this)
   {

      m_pWindowingUniversalWindowsNode = this;

   }


   node::~node()
   {


   }





   ::e_status node::implement()
   {

      auto pwindow = new window;

      m_pwindowNode = ::move_transfer(pwindow);

      pwindow->initialize(this);

      auto estatus = m_psystem->m_paurasystem->begin_synch();

      if (!estatus)
      {

         return estatus;

      }

      estatus = call_member(SOUL_ID);

      if (!estatus)
      {

         return estatus;

      }

      return ::success;

   }


   ::e_status node::call_member(::i64 i)
   {

      if (i == SOUL_ID)
      {

         ::winrt::Windows::ApplicationModel::Core::CoreApplication::Run(m_frameworkviewsource);

         return ::success;

      }

      auto estatus = aura::universal_windows::node::call_member(i);

      if (!estatus)
      {

         return estatus;

      }

      return estatus;

   }


   node::framework_view_source::framework_view_source(node * pnode) :
      m_pnode(pnode)
   {

   }


   ::winrt::Windows::ApplicationModel::Core::IFrameworkView node::framework_view_source::CreateView()
   {

      return  m_pnode->m_pwindowNode->m_frameworkview;

   }


} // namespace windowing_universal_windows



