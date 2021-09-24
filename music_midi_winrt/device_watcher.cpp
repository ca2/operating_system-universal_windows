// Moved from io to midi to device_watcher by 2021-09-23 20:15 BRT <3ThomasBorregaardSørensen!!
#include "framework.h"
//#include <mmddk.h>

// http://blogs.msdn.com/b/matthew_van_eerde/archive/2012/09/21/enumerating-midi-devices.aspx
// Maurits [MSFT]
//21 Sep 2012 9:31 AM

//0
// MSDN Blogs > Matthew van Eerde's web log > Enumerating MIDI devices 

#define LOG(format, ...) TRACE(format, __VA_ARGS__)


namespace music
{


   namespace midi
   {


      namespace winrt
      {


         device_watcher::device_watcher(midi * pmidi, const ::string & strMidiSelector) : 
            m_pmidi(pmidi),
            m_strMidiSelector(strMidiSelector), 
            m_devicewatcher(nullptr),
            m_deviceinformationcollection(nullptr),
            m_bEnumCompleted(false)
         {

            m_devicewatcher = DeviceInformation::CreateWatcher(__hstring(strMidiSelector));

            m_tokenPortAdded = m_devicewatcher.Added({ this, &device_watcher::OnPortAdded });

            m_tokenPortRemoved = m_devicewatcher.Removed({ this, &device_watcher::OnPortRemoved });

            m_tokenPortUpdated = m_devicewatcher.Updated({ this, &device_watcher::OnPortUpdated });

            m_tokenPortEnumComplete = m_devicewatcher.EnumerationCompleted({ this, &device_watcher::OnPortEnumCompleted });

         }


         device_watcher::~device_watcher()
         {
            
            m_devicewatcher.Added(m_tokenPortAdded);
            
            m_devicewatcher.Removed(m_tokenPortRemoved);
            
            m_devicewatcher.Updated(m_tokenPortUpdated);
            
            m_devicewatcher.EnumerationCompleted(m_tokenPortEnumComplete);

         }


         void device_watcher::start_device_watcher()
         {

            m_devicewatcher.Start();

         }


         void device_watcher::stop_device_watcher()
         {

            m_devicewatcher.Stop();

         }


         DeviceInformationCollection device_watcher::GetDeviceInformationCollection()
         {

            return m_deviceinformationcollection;

         }


         void device_watcher::update_ports()
         {

            DeviceInformationCollection deviceinformationcollection = DeviceInformation::FindAllAsync(__hstring(m_strMidiSelector)).get();

            //m_pmidi->clear_out_ports();

            if ((deviceinformationcollection == nullptr) || (deviceinformationcollection.Size() == 0))
            {


            }
            else
            {

               m_deviceinformationcollection = deviceinformationcollection;

               for (::u32 u = 0; u < deviceinformationcollection.Size(); u++)
               {

                  DeviceInformation deviceinformation = deviceinformationcollection.GetAt(u);

                  //string strId = "winrt:" + string(deviceinformation.Id().begin());

                  string strName = deviceinformation.Name().begin();

                  m_pmidi->add_midi_out_device(strName, "winrt");

               }

            }

         }


         void device_watcher::OnPortAdded(DeviceWatcher const & deviceWatcher, DeviceInformation const & devInfo)
         {

            if (m_bEnumCompleted)
            {

               update_ports();

            }

         }


         void device_watcher::OnPortRemoved(DeviceWatcher const & deviceWatcher, DeviceInformationUpdate const & devInfoUpdate)
         {

            if (m_bEnumCompleted)
            {

               update_ports();

            }

         }


         void device_watcher::OnPortUpdated(DeviceWatcher const & deviceWatcher, DeviceInformationUpdate const & devInfoUpdate)
         {

            if (m_bEnumCompleted)
            {

               update_ports();

            }

         }


         void device_watcher::OnPortEnumCompleted(DeviceWatcher const & deviceWatcher, IInspectable  const & obj)
         {

            m_bEnumCompleted = true;

            update_ports();

         }


      } // namespace winrt


   } // namespace midi


} // namespace music








