#pragma once


#undef new
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.System.Threading.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.Storage.FileProperties.h>
#define new ACME_NEW


struct __declspec(uuid("5b0d3235-4dba-4d44-865e-8f1d0e4fd04d")) __declspec(novtable) IMemoryBufferByteAccess : ::IUnknown
{
   virtual HRESULT __stdcall GetBuffer(uint8_t ** value, uint32_t * capacity) = 0;
};


CLASS_DECL_ACME_UNIVERSAL_WINDOWS uptr virtualkey_to_char(::winrt::Windows::System::VirtualKey e);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS ::user::enum_key virtualkey_to_userkey(::winrt::Windows::System::VirtualKey e, bool & bSpecialKey);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS uptr virtualkey_to_code(::winrt::Windows::System::VirtualKey e);


inline winrt::hstring __hstring(const char * psz)
{

   wstring wstr(psz);

   return wstr.c_str();

}



CLASS_DECL_ACME_UNIVERSAL_WINDOWS void main_branch(::matter * pobjectTask, enum_priority epriority);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::UI::Core::CoreDispatcherPriority windows_runtime_UICoreDispatcherPriority(enum_priority epriority);
CLASS_DECL_ACME_UNIVERSAL_WINDOWS::winrt::Windows::System::Threading::WorkItemPriority windows_runtime_WorkItemPriority(enum_priority epriority);



template < typename PREDICATE >
void windows_runtime_async(PREDICATE predicate, enum_priority epriority = e_priority_normal)
{

   auto priority = windows_runtime_UICoreDispatcherPriority(epriority);

   auto mainview = ::winrt::Windows::ApplicationModel::Core::CoreApplication::MainView();

   auto dispatcher = mainview.CoreWindow().Dispatcher();

   auto handler = ::winrt::Windows::UI::Core::DispatchedHandler(predicate);

   dispatcher.RunAsync(priority, handler);

}


CLASS_DECL_ACME_UNIVERSAL_WINDOWS ::winrt::Windows::Storage::StorageFolder windows_runtime_folder(::object * pobject, string & strRelative, string & strPrefix);


CLASS_DECL_ACME_UNIVERSAL_WINDOWS ::winrt::Windows::Storage::StorageFolder windows_runtime_folder(::object * pobject, const ::file::path & path);


template < typename PREDICATE >
::e_status windows_runtime_synchronously(const ::duration & duration, PREDICATE predicate, enum_priority epriority = e_priority_normal)
{

   auto pmutex = __new(mutex);

   auto pevent = __new(manual_reset_event);

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

         if (!pevent->is(e_matter_exited))
         {

            pevent->m_estatus = estatus;

            pevent->set_event();

         }

      }, epriority);

   pevent->wait(duration);

   synchronous_lock synchronouslock(pmutex);

   pevent->set(e_matter_exited);

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
//   struct ByteArray { Platform::Array<byte> ^ data; };
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
//   auto a = ref new Platform::Array<byte>(b->Length);
//   Streams::DataReader::FromBuffer(b)->ReadBytes(a);
//   ByteArray ba = { a };
//   return ba;
//   });
//
//   return byteArrayTask;
//   }*/
//} // namespace dx


CLASS_DECL_ACME_UNIVERSAL_WINDOWS memsize windows_runtime_read_buffer(void * p, memsize s, ::winrt::Windows::Storage::Streams::IBuffer ibuffer);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS ::winrt::Windows::Storage::Streams::IBuffer windows_runtime_buffer(const void * p, memsize s);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS memory windows_runtime_buffer_memory(::winrt::Windows::Storage::Streams::IBuffer ibuffer, memsize pos = 0, memsize size = -1);

CLASS_DECL_ACME_UNIVERSAL_WINDOWS memory windows_runtime_buffer_memory(::winrt::Windows::Storage::Streams::IBuffer ibuffer);



