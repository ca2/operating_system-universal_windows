// From _windows_runtime.h by camilo on 2022-09-23 ~01:10 <3ThomasBorregaardSorensen!!
#pragma once

#include "_.h"
//#undef new
#include "acme/operating_system/universal_windows/nano/_.h"
#include <winrt/Windows.System.Threading.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.Storage.FileProperties.h>
//#define new ACME_NEW


struct __declspec(uuid("5b0d3235-4dba-4d44-865e-8f1d0e4fd04d")) __declspec(novtable) IMemoryBufferByteAccess : ::IUnknown
{
   virtual HRESULT __stdcall GetBuffer(uint8_t ** value, uint32_t * capacity) = 0;
};







CLASS_DECL_ACME_UNIVERSAL_WINDOWS void main_branch(::matter * pobjectTask, enum_priority epriority);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::System::Threading::WorkItemPriority windows_runtime_WorkItemPriority(enum_priority epriority);





//////CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::Storage::StorageFolder windows_runtime_folder(::particle * pparticle, string & strRelative, string & strPrefix);
//////
//////
//////CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::Storage::StorageFolder _windows_runtime_folder(::particle * pparticle, string & strRelative, string & strPrefix);
//////
//////
//////CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::Storage::StorageFolder windows_runtime_known_folder(::particle * pparticle, string & strRelative, string & strPrefix);
//////
//////
//////CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::Storage::StorageFolder windows_runtime_folder(::particle * pparticle, const ::file::path & path);


template < typename PREDICATE >
::e_status windows_runtime_synchronously(const class time & time, PREDICATE predicate, enum_priority epriority = e_priority_normal)
{

   auto pmutex = øallocate mutex();

   auto pevent = øallocate manual_reset_happening();

   pevent->m_estatus = error_timeout;

   windows_runtime_async([predicate, pevent, pmutex, epriority]
      {

         ::e_status estatus = error_timeout;

         try
         {

            predicate();

            estatus = success;

         }
         catch (...)
         {

            estatus = error_exception;

         }

         synchronous_lock synchronouslock(pmutex);

         if (!pevent->has(e_flag_exited))
         {

            pevent->m_estatus = estatus;

            pevent->set_happening();

         }

      }, epriority);

   pevent->wait(time);

   synchronous_lock synchronouslock(pmutex);

   pevent->set(e_flag_exited);

   return pevent->m_estatus;

}




//namespace dx
//{
//   //inline void throw_if_failed(HRESULT hr)
//   //{
//   //   if(FAILED(hr))
//   //   {
//   //      // Set a breakpoint on this line to catch DirectX API errors
//   //      throw Platform::Exception::CreateException(hr);
//   //   }
//   //}
//
//   struct ByteArray { Platform::Array<unsigned char> ^ data; };
//
//   // function that reads from a binary file asynchronously
//   /*	inline Concurrency::task<ByteArray> ReadDataAsync(Platform::String^ filename)
//   {
//   using namespace ::winrt::Windows::Storage;
//   using namespace Concurrency;
//
//   auto folder = ::winrt::Windows::ApplicationModel::Package::Current->InstalledLocation;
//
//   task<StorageFile^> getFileTask(folder->GetFileAsync(filename));
//
//   auto readBufferTask = getFileTask.then([] (StorageFile^ f)
//   {
//   return FileIO::ReadBufferAsync(f);
//   });
//
//   auto byteArrayTask = readBufferTask.then([] (Streams::IBuffer^ b) -> ByteArray
//   {
//   auto a = ref ___new Platform::Array<unsigned char>(b->Length);
//   Streams::DataReader::FromBuffer(b)->ReadBytes(a);
//   ByteArray ba = { a };
//   return ba;
//   });
//
//   return byteArrayTask;
//   }*/
//} // namespace dx


CLASS_DECL_ACME_UNIVERSAL_WINDOWS memsize windows_runtime_read_buffer(void * p, memsize s, ::winrt::Windows::Storage::Streams::IBuffer ibuffer);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::Storage::Streams::IBuffer windows_runtime_buffer(const void * p, memsize s);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS memory windows_runtime_buffer_memory(::winrt::Windows::Storage::Streams::IBuffer ibuffer, memsize pos = 0, memsize size = -1);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS memory windows_runtime_buffer_memory(::winrt::Windows::Storage::Streams::IBuffer ibuffer);



