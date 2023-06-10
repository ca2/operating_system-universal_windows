// created by Camilo <3CamiloSasukeThomasBorregaardSoerensen  - Honoring Thomas Borregaard Soerensen MY ONLY LORD
// recreated by Camilo 2021-01-28 16:44
#include "framework.h"
#include "icon.h"
#include "aura/graphics/image/image.h"


// http ://stackoverflow.com/questions/1913468/how-to-determine-the-size_i32-of-an-icon-from-a-hicon
// http://stackoverflow.com/users/739731/sergey



namespace windowing_universal_windows
{


   icon::icon()
   {

      
   }


   icon::~icon()
   {

      _erase_all();

   }


   //void * icon::get_os_data(const ::size_i32 & size) const
   //{

   //   //auto & hicon = ((icon *)this)->m_iconmap[size];

   //   //if (!hicon)
   //   //{

   //   //   if (m_ppathProcessed.has_char())
   //   //   {

   //   //      //hicon = (HICON) ::LoadImageW(nullptr, wstring(m_ppathProcessed), IMAGE_ICON, size.cx, size.cy, LR_LOADFROMFILE);

   //   //   }

   //   //}

   //   //if (!hicon)
   //   //{

   //   //   if (!m_iconmap.is_empty())
   //   //   {

   //   //      ::size_i32 size1 = size;

   //   //      //for (auto& hicon1 : m_iconmap.values())
   //   //      //{

   //   //      //   auto info = MyGetIconInfo(hicon1);

   //   //      //   if (info.nWidth > size1.cx
   //   //      //      && info.nHeight > size1.cy)
   //   //      //   {

   //   //      //      size1.cx = info.nWidth;
   //   //      //      size1.cy = info.nHeight;
   //   //      //      hicon = hicon1;

   //   //      //   }

   //   //      //}

   //   //      //if (!hicon)
   //   //      //{

   //   //      //   size1.cx = 0;
   //   //      //   size1.cy = 0;

   //   //      //   for (auto& hicon1 : m_iconmap.values())
   //   //      //   {

   //   //      //      auto info = MyGetIconInfo(hicon1);

   //   //      //      if (info.nWidth > size1.cx
   //   //      //         && info.nHeight > size1.cy)
   //   //      //      {

   //   //      //         size1.cx = info.nWidth;
   //   //      //         size1.cy = info.nHeight;
   //   //      //         hicon = hicon1;

   //   //      //      }

   //   //      //   }

   //   //      //}


   //   //   }

   //   //}

   //   return hicon;

   //}


   bool icon::add_icon(HICON hicon)
   {

      //auto info = MyGetIconInfo(hicon);

      //m_iconmap[{info.nWidth, info.nHeight}] = hicon;
      
      return true;

   }


   void icon::load_file(const ::string & strPath)
   {

      //m_ppathProcessed = m_pcontext->m_papexcontext->defer_process_matter_path(strPath);

      m_path = strPath;

      //int_array ia;

      //ia.add(16);
      //ia.add(24);
      //ia.add(32);
      //ia.add(48);
      //ia.add(256);

      //for (auto i : ia)
      //{

      //   HICON hicon = (HICON) ::LoadImageW(nullptr, wstring(strProcessedPath), IMAGE_ICON, i, i, LR_LOADFROMFILE);

      //   if (hicon != nullptr)
      //   {

      //      m_iconmap[::size_i32(i, i)] = hicon;

      //   }

      //}

      //return m_path.has_char();

//      return !m_iconmap.is_empty();

//#else
//
//      m_strAppTrayIcon = strPath;
//
//      return true;
//
//#endif

   }


   void icon::load_app_tray_icon(const ::string & strApp)
   {

      string strMatter = "main/icon.ico";

      load_matter(strMatter);

      //if (!load_matter(strMatter))
      //{

      //   return false;

      //}

      //return true;

   }


   void icon::get_sizes(::size_i32_i32 > > & a)
   {

      a.erase_all();

      //for (auto & size : m_iconmap.keys())
      //{

      //   a.add(size);

      //}

   }


   image_pointer icon::get_image(const concrete < ::size_i32 > & size)
   {

      auto& pimage  = m_imagemap[size];

      if (pimage)
      {

         return pimage;

      }

      pimage = _create_image(size);

      return pimage;

   }


   image_pointer icon::_create_image(const concrete < ::size_i32 > & size)
   {

      HICON hicon = (HICON) get_os_data(size);

      if (::is_null(hicon))
      {

         return nullptr;

      }

      ::pointer<::image>pimage;

      ::__construct(this, pimage);

      bool bOk = false;

      HBITMAP hbitmap = nullptr;

      HDC hdc = nullptr;

      HBITMAP hbitmapOld = nullptr;

      try
      {

         //BITMAPINFO info;

         //ZeroMemory(&info, sizeof(BITMAPINFO));

         //auto iScan = size.cx * 4;

         //info.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
         //info.bmiHeader.biWidth = size.cx;
         //info.bmiHeader.biHeight = -size.cy;
         //info.bmiHeader.biPlanes = 1;
         //info.bmiHeader.biBitCount = 32;
         //info.bmiHeader.biCompression = BI_RGB;
         //info.bmiHeader.biSizeImage = size.cy * iScan;

         //::color32_t * pimage32 = nullptr;

         //hbitmap = ::CreateDIBSection(nullptr, &info, DIB_RGB_COLORS, (void **)&pimage32, nullptr, 0);

         //::pixmap pixmap;

         //pixmap.init(size, pimage32, iScan);

         //hdc = ::CreateCompatibleDC(nullptr);

         //hbitmapOld = (HBITMAP) ::SelectObject(hdc, hbitmap);

         //if (!::DrawIconEx(hdc, 0, 0, hicon, size.cx, size.cy, 0, nullptr, DI_IMAGE | DI_MASK))
         //{

         //   return nullptr;

         //}

         //::GdiFlush();

         ////bool bAllZeroAlpha = true;
         ////bool bTheresUint32 = false;

         ////pixmap.map();

         ////int area = size.area();

         ////auto pc = pixmap.colorref();
         ////::u8 * pA = &((::u8 *)pc)[3];

         ////for (int i = 0; i < area; i++)
         ////{
         ////   if (*pc != 0)
         ////   {
         ////      bTheresUint32 = true;
         ////   }
         ////   if (*pA != 0)
         ////   {
         ////      bAllZeroAlpha = false;
         ////      break;
         ////   }
         ////   pc++;
         ////   pA += 4;
         ////}

         ////if (bAllZeroAlpha && bTheresUint32)
         ////{

         ////   pc = pixmap.colorref();
         ////   pA = &((::u8 *)pc)[3];

         ////   for (int i = 0; i < area; i++)
         ////   {
         ////      if (*pc != 0)
         ////      {
         ////         *pA = 255;
         ////      }
         ////      pc++;
         ////      pA += 4;
         ////   }

         ////   ::SelectObject(hdc, hbitmapOld);

         //   pimage->create(size);

         //   pimage->map();

         //   ::copy_image32(pimage, pixmap);

         ////}

      }
      catch (...)
      {

         output_debug_string("!");

      }

      if (hdc != nullptr)
      {

         //if (hbitmapOld != nullptr)
         //{

         //   ::SelectObject(hdc, hbitmapOld);

         //}

         //::DeleteDC(hdc);

      }

      //if (hbitmap != nullptr)
      //{

      //   ::DeleteObject(hbitmap);

      //}

      return pimage;


   }


   void icon::_erase_all()
   {

      //for (auto hicon : m_iconmap.values())
      //{

      //   ::DestroyIcon(hicon);

      //}

      //m_iconmap.erase_all();

   }


} // namespace windowing_universal_windows



