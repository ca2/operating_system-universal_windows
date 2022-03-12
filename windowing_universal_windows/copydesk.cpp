#include "framework.h"
#include "apex/operating_system.h"
//#include "apex/platform/app_core.h"
#include "copydesk.h"
#include "aura/graphics/image/image.h"
#include <winrt/Windows.ApplicationModel.DataTransfer.h>
#include <winrt/Windows.Graphics.Imaging.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>
//
//struct __declspec(uuid("5b0d3235-4dba-4d44-865e-8f1d0e4fd04d")) __declspec(novtable) IMemoryBufferByteAccess : ::IUnknown
//{
//   virtual HRESULT __stdcall GetBuffer(uint8_t ** value, uint32_t * capacity) = 0;
//};
namespace windowing_universal_windows
{


   copydesk::copydesk()
   {

      defer_create_mutex();

   }


   copydesk::~copydesk()
   {

   }


   void copydesk::OnClipboardUpdate()
   {

      synchronous_lock synchronouslock(mutex());

      m_cFileCount = -1;
      m_iPriorityTextFormat = -2;
      m_iFilea = -1;
      m_iText = -1;
      m_iDib = -1;

   }


   void copydesk::_001OnClipboardUpdate(::message::message * pmessage)
   {

      //if(message == WM_CLIPBOARDUPDATE)
      //{

        // LONG_PTR l = ::GetWindowLongPtrA(hwnd, GWLP_USERDATA);

         //copydesk * pdesk = (copydesk *) l;

         //if(pdesk != nullptr)
         //{

            OnClipboardUpdate();

         //}

//      }

  //    return DefWindowProc(hwnd, message, wparam, lparam);


   }

   
   //void copydesk::install_message_routing(::channel * pchannel)
   //{

   //   ::user::message_window::install_message_routing(pchannel);

   //   MESSAGE_LINK(WM_CLIPBOARDUPDATE, pchannel, this, &copydesk::_001OnClipboardUpdate);

   //}


   void copydesk::initialize(::object * pobject)
   {

      //auto estatus =
      
      ::user::copydesk::initialize(pobject);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      synchronous_lock synchronouslock(mutex());

      //WNDCLASS wndcls = {};

      //wstring strClass = L"ca2_copydesk_windows_message_queue";

      //HINSTANCE hinstance = psystem->m_hinstance;

      //if (!GetClassInfoW(hinstance, strClass, &wndcls))
      //{

      //   wndcls.style = 0;
      //   wndcls.lpfnWndProc = &copydesk::WindowProc;

      //   wndcls.cbClsExtra = 0;
      //   wndcls.cbWndExtra = 0;
      //   wndcls.hInstance = psystem->m_hinstance;
      //   wndcls.hIcon = nullptr;
      //   wndcls.hCursor = nullptr;
      //   wndcls.hbrBackground = nullptr;
      //   wndcls.lpszMenuName = nullptr;

      //   wndcls.lpszClassName = strClass;


      //   if (!::RegisterClass(&wndcls))
      //   {

      //      return false;

      //   }

      //}

      //if(!create_message_queue("::windows::copydesk"))
      //{

      ////m_hwnd = ::CreateWindowEx(0, strClass, 0, 0, 0, 0, 0, 0, HWND_MESSAGE, 0, 0, nullptr);

      ////if (m_hwnd == nullptr)
      ////{

      //   return false;

      //}

      //::SetWindowLongPtr(m_hwnd, GWLP_USERDATA, (LONG_PTR) this);

      //if(!::AddClipboardFormatListener((HWND)get_oswindow()))
      //{

      //   destroy();

      //   return false;

      //}

      OnClipboardUpdate();

      //return true;

   }


   void copydesk::destroy()
   {

      //auto estatus1 = 
      
      ::user::copydesk::destroy();

//      auto estatus2 = ::user::message_window::destroy();

      //return minimum(estatus1, estatus2);

      //return estatus1;

   }


   void copydesk::on_message_destroy(::message::message * pmessage)
   {

      //bool bOk1 = ::RemoveClipboardFormatListener((HWND)get_oswindow());

      //bool bOk2 = ::DestroyWindow(m_hwnd);

      //::user::copydesk::destroy();

   }


   bool copydesk::_has_filea()
   {

      return _get_file_count() >= 1;

   }


   //HGLOBAL copydesk::hglobal_get_filea(const ::file::path_array & patha)
   //{

   //   strsize iLen = 0;

   //   for (i32 i = 0; i < patha.get_size(); i++)
   //   {

   //      iLen += ::str::international::utf8_to_unicode_count(patha[i]) + 1;

   //   }

   //   HGLOBAL hglb = ::GlobalAlloc(GMEM_MOVEABLE, (SIZE_T) (sizeof(DROPFILES) + (iLen + 1) * sizeof(WCHAR)));
   //   LPDROPFILES pDropFiles = (LPDROPFILES) ::GlobalLock(hglb);
   //   pDropFiles->pFiles = sizeof(DROPFILES);
   //   pDropFiles->pt.x = 0;
   //   pDropFiles->pt.y = 0;
   //   pDropFiles->fNC = true;
   //   pDropFiles->fWide = true;

   //   char * psz = (char *)pDropFiles;

   //   psz += pDropFiles->pFiles;

   //   unichar * pwsz = (unichar *)psz;


   //   for (i32 i = 0; i < patha.get_size(); i++)
   //   {

   //      ::count c = ::str::international::utf8_to_unicode_count(patha[i]) + 1;

   //      ::str::international::utf8_to_unicode(pwsz, c, patha[i]);


   //      pwsz += c;


   //   }

   //   *pwsz = L'\0';


   //   ::GlobalUnlock(hglb);

   //   return hglb;

   //}


   //HGLOBAL copydesk::hglobal_get_wide_text(const ::string & str)
   //{

   //   ::count c = ::str::international::utf8_to_unicode_count(str) + 1;
   //   HGLOBAL hglb = ::GlobalAlloc(GMEM_MOVEABLE, (SIZE_T) (c * sizeof(WCHAR)));
   //   unichar * pwsz = (unichar *) ::GlobalLock(hglb);

   //   ::str::international::utf8_to_unicode(pwsz, c, str);

   //   ::GlobalUnlock(hglb);

   //   return hglb;

   //}


   //HGLOBAL copydesk::hglobal_get_utf8_text(const ::string & str)
   //{

   //   HGLOBAL hglb = ::GlobalAlloc(GMEM_MOVEABLE, (SIZE_T) (sizeof(char) * (str.length() + 1)));
   //   char * psz = (char *) ::GlobalLock(hglb);

   //   strcpy(psz, str);

   //   ::GlobalUnlock(hglb);

   //   return hglb;

   //}


   //HGLOBAL copydesk::hglobal_get_image(const ::image * pimage)
   //{

   //   ::u32 dwWidth, dwHeight;
   //   BITMAPINFOHEADER bi;
   //   hcursor hAlphaCursor = nullptr;

   //   dwWidth = pimage->width();
   //   dwHeight = pimage->height();

   //   ZeroMemory(&bi, sizeof(BITMAPINFOHEADER));
   //   bi.biSize = sizeof(BITMAPINFOHEADER);
   //   bi.biWidth = dwWidth;
   //   bi.biHeight = -(::i32)dwHeight;
   //   bi.biPlanes = 1;
   //   bi.biBitCount = 32;
   //   bi.biCompression = BI_RGB;
   //   bi.biSizeImage = pimage->scan_size() * pimage->height();

   //   HGLOBAL hglb = GlobalAlloc(GMEM_MOVEABLE, sizeof(bi) + pimage->scan_size() * pimage->height());

   //   if (hglb == nullptr)
   //   {

   //      return nullptr;

   //   }

   //   byte * p = (byte *) ::GlobalLock(hglb);


   //   pimage->map();

   //   ::memcpy_dup(p, &bi, sizeof(bi));

   //   ::memcpy_dup(p + sizeof(bi), pimage->get_data(), pimage->scan_size() * pimage->height());

   //   GlobalUnlock(hglb);

   //   return hglb;

   //}


   int copydesk::_get_priority_text_format()
   {

      //if(m_iPriorityTextFormat == -2)
      //{

      //   ::u32 iCfShellInternetUrlW = ::RegisterClipboardFormat(CFSTR_INETURLW);

      //   ::u32 uaFormatPriorityList[] =
      //   {
      //      iCfShellInternetUrlW,
      //      CF_UNICODETEXT,
      //      CF_TEXT,
      //   };

      //   m_iPriorityTextFormat = ::GetPriorityClipboardFormat(uaFormatPriorityList, ARRAYSIZE(uaFormatPriorityList));

      //}

      //return m_iPriorityTextFormat;

      return 0;

   }


   ::count copydesk::_get_file_count()
   {


      if (!m_pwindow)
      {

         throw ::exception(error_not_initialized);

         return -1;

      }

      ::count c = -1;

      m_pwindow->window_post(__routine([this]()
         {

            synchronous_lock synchronouslock(mutex());


            //if(m_cFileCount < 0)
            //{

            //   if (!IsClipboardFormatAvailable(CF_HDROP))
            //   {

            //      m_cFileCount = 0;

            //   }
            //   else
            //   {

            //      synchronous_lock synchronouslock(mutex());

            //      if (!::OpenClipboard(__hwnd(get_oswindow())))
            //      //if(!OpenClipboard())
            //      {

            //         m_cFileCount =  0;

            //      }
            //      else
            //      {

            //         HDROP hdrop = (HDROP) ::GetClipboardData(CF_HDROP);

            //         ::count c = 0;

            //         if (hdrop != nullptr)
            //         {

            //            c = ::DragQueryFile(hdrop, 0xFFFFFFFF, nullptr, 0);

            //         }

            //         ::CloseClipboard();

            //         m_cFileCount = c;

            //      }

            //   }

            //}

            //return m_cFileCount;

         }));

      return c;

   }


   bool copydesk::_get_filea(::file::path_array & patha, enum_op & eop)
   {

      //::count c = _get_file_count();

      //if (c <= 0)
      //{

      //   return false;

      //}

      //synchronous_lock synchronouslock(mutex());

      //if (!::OpenClipboard(__hwnd(get_oswindow())))
      //{

      //   return false;

      //}

      //HDROP hdrop = (HDROP) ::GetClipboardData(CF_HDROP);

      //for (::index i = 0; i < c; i++)
      //{

      //   ::u32 uLen = ::DragQueryFileW(hdrop, (::u32) i, nullptr, 0);

      //   wstring wstr(get_buffer, uLen);

      //   auto x = wstr.length();

      //   ::DragQueryFileW(hdrop, (::u32) i, wstr, (::u32) wstr.length() + 1);

      //   wstr.release_string_buffer();

      //   patha.add(::file::path(wstr));

      //}

      //::CloseClipboard();

      //return true;

      return false;

   }


   bool copydesk::_set_filea(const ::file::path_array & patha, enum_op eop)
   {

      //ASSERT(::IsWindow(m_hwnd));

      //synchronous_lock synchronouslock(mutex());

      //if (!::OpenClipboard(__hwnd(get_oswindow())))
      //{

      //   return false;

      //}

      //EmptyClipboard();

      //SetClipboardData(CF_HDROP, hglobal_get_filea(patha));

      //SetClipboardData(CF_UNICODETEXT, hglobal_get_wide_text(patha.implode("\r\n")));

      //SetClipboardData(CF_TEXT, hglobal_get_utf8_text(patha.implode("\r\n")));

      //VERIFY(::CloseClipboard());

      //return true;

      return false;

   }


   bool copydesk::_has_plain_text()
   {

      if (!m_pwindow)
      {

         throw ::exception(error_not_initialized);

         return false;

      }

      bool bHasText = false;

      m_pwindow->window_send(__routine(15_s, [this, &bHasText]()
         {

            synchronous_lock synchronouslock(mutex());


            auto datapackageview = ::winrt::Windows::ApplicationModel::DataTransfer::Clipboard::GetContent();

            bHasText = datapackageview.Contains(
               ::winrt::Windows::ApplicationModel::DataTransfer::StandardDataFormats::Text());

         }));

      return bHasText;

   }


   bool copydesk::_set_plain_text(const ::string & str)
   {

      if (!m_pwindow)
      {

         throw ::exception(error_not_initialized);

      }

      m_pwindow->window_post(__routine([this, str]()
         {

            synchronous_lock synchronouslock(mutex());

            ::winrt::Windows::ApplicationModel::DataTransfer::DataPackage package;

            auto hstr = __hstring(str);

            package.SetText(hstr);

            ::winrt::Windows::ApplicationModel::DataTransfer::Clipboard::Clear();

            ::winrt::Windows::ApplicationModel::DataTransfer::Clipboard::SetContent(package);

            ::winrt::Windows::ApplicationModel::DataTransfer::Clipboard::Flush();

         }));
      
      return ::success;

   }


   bool copydesk::_get_plain_text(string & str)
   {

      if (!_has_plain_text())
      {

         throw ::exception(error_wrong_state);

      }

      if (!m_pwindow)
      {

         throw ::exception(error_not_initialized);

      }

      synchronous_lock synchronouslock(mutex());

      ::winrt::Windows::ApplicationModel::DataTransfer::DataPackageView datapackageview(nullptr);

      m_pwindow->window_send(__routine(15_s, [&datapackageview]()
         {

            datapackageview = ::winrt::Windows::ApplicationModel::DataTransfer::Clipboard::GetContent();

         }));

         auto hstr = datapackageview.GetTextAsync().get();

         //if (!ppropertyset->is_true("nok_to_set"))
         //{

            str = hstr.begin();

      //   }

      //}));

//      ppropertyset->operator[]("nok_to_set") = true;

//    sleep(100_ms);

      return true;

   }


   bool copydesk::_has_image()
   {

      if (!m_pwindow)
      {

         return false;

      }

      bool bHasImage = false;

      m_pwindow->window_send(__routine(15_s, [&bHasImage]()
         {

            auto datapackageview = ::winrt::Windows::ApplicationModel::DataTransfer::Clipboard::GetContent();

            bHasImage = datapackageview.Contains(
               ::winrt::Windows::ApplicationModel::DataTransfer::StandardDataFormats::Bitmap());

         }));

      return bHasImage;

   }


   bool copydesk::_desk_to_image(::image * pimage)
   {

      if (!_has_image())
      {

         throw ::exception(error_wrong_state);

      }

      if (!m_pwindow)
      {

         throw ::exception(error_not_initialized);

      }

      //synchronous_lock synchronouslock(mutex());

      ::winrt::Windows::ApplicationModel::DataTransfer::DataPackageView datapackageview(nullptr);

      m_pwindow->window_send(__routine(15_min, [&datapackageview]()
         {

            datapackageview = ::winrt::Windows::ApplicationModel::DataTransfer::Clipboard::GetContent();

         }));

      defer_co_initialize_ex(true);

      string str = ::winrt::Windows::ApplicationModel::DataTransfer::StandardDataFormats::Bitmap().begin();

      auto data = datapackageview.GetDataAsync(L"DeviceIndependentBitmap").get();

      auto stream = data.as <::winrt::Windows::Storage::Streams::IRandomAccessStream >();

      memsize s = (memsize)stream.Size();

      ::winrt::Windows::Storage::Streams::Buffer buffer((::u32) s);

      if (buffer == nullptr)
      {

         throw exception(error_failed);

      }

      stream.ReadAsync(buffer, (::u32) s, ::winrt::Windows::Storage::Streams::InputStreamOptions::ReadAhead).get();

      memory m;

      m.set_size(s);

      windows_runtime_read_buffer(m.get_data(), s, buffer);

      BITMAPINFO * pbitmapinfo = (BITMAPINFO *)m.get_data();

      pimage->create({ pbitmapinfo->bmiHeader.biWidth,  pbitmapinfo->bmiHeader.biHeight });

      pimage->map();

      vertical_swap_copy_colorref(
         pimage->get_data(),
         pimage->width(),
         pimage->height(),
         pimage->scan_size(),
         (::color32_t *)&m.get_data()[pbitmapinfo->bmiHeader.biSize],
         pbitmapinfo->bmiHeader.biSizeImage / pbitmapinfo->bmiHeader.biHeight);

      //auto decoder = ::winrt::Windows::Graphics::Imaging::BitmapDecoder::CreateAsync(stream2).get();

      //int cy = decoder.PixelHeight();
      //int cx = decoder.PixelWidth();
      //auto provider = decoder.GetPixelDataAsync(
      //   ::winrt::Windows::Graphics::Imaging::BitmapPixelFormat::Bgra8,
      //   ::winrt::Windows::Graphics::Imaging::BitmapAlphaMode::Premultiplied,
      //   ::winrt::Windows::Graphics::Imaging::BitmapTransform::BitmapTransform(),
      //   ::winrt::Windows::Graphics::Imaging::ExifOrientationMode(),
      //   ::winrt::Windows::Graphics::Imaging::ColorManagementMode()).get();

      //auto data = provider.DetachPixelData();


      ////if (bitmap.BitmapPixelFormat() != ::winrt::Windows::Graphics::Imaging::BitmapPixelFormat::Bgra8)
      ////{

      ////   auto bitmap32 = ::winrt::Windows::Graphics::Imaging::SoftwareBitmap::Convert(
      ////      bitmap,
      ////      ::winrt::Windows::Graphics::Imaging::BitmapPixelFormat::Bgra8);

      ////   bitmap = bitmap32;

      ////}

      ////auto cx = bitmap.PixelWidth();

      ////auto cy = bitmap.PixelHeight();

      ////pimage->create({ cx, cy });

      ////auto bitmapbuffer = bitmap.LockBuffer(::winrt::Windows::Graphics::Imaging::BitmapBufferAccessMode::Read);

      ////auto bitmapbuffer_ref = bitmapbuffer.CreateReference();

      ////auto byteaccess = bitmapbuffer_ref.as<IMemoryBufferByteAccess>();

      //::byte * pdataSrc = data.data();
      //
      //::u32 sizeSrc = data.size();

      ////auto hresult = byteaccess->GetBuffer(&pdataSrc, &sizeSrc);

      //int iSourceStride = sizeSrc / cy;

      //pimage->map();

      //::color::color colorFirstPixel(((::color32_t *)pdataSrc)[0]);

      //copy_colorref(
      //   pimage->get_data(), 
      //   cx, cy, pimage->m_iScan, 
      //   (::color32_t *) pdataSrc, iSourceStride);

      //}));

      return true;

   }


   bool copydesk::_image_to_desk(const ::image * pimage)
   {

      //ASSERT(::IsWindow(m_hwnd));

      synchronous_lock synchronouslock(mutex());

      //if (!::OpenClipboard(__hwnd(get_oswindow())))
      //{

      //   return false;

      //}

      //EmptyClipboard();


      //SetClipboardData(CF_DIB, hglobal_get_image(pimage));


      //VERIFY(::CloseClipboard());

      return true;

   }


} // namespace windowing_universal_windows



