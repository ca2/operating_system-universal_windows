#pragma once


namespace ca2plugin_container
{


   class application
   {
   public:


      int                        m_iReturn;

      host *                     m_phost;


      application();
      ~application() override;
      
      __DECLARE_APPLICATION_RELEASE_TIME();



      virtual void on_receive(small_ipc_rx_channel * prxchannel, const ::string & pszMessage);
      virtual void on_receive(small_ipc_rx_channel * prxchannel, int message, void * pdata, int len);

      virtual bool initialize(const ::string & pszChannel);

      virtual bool destroy();


      virtual int run();

   };



} // namespace ca2plugin_container






