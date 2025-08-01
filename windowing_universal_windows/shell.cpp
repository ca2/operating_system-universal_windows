#include "framework.h"
#include "icon.h"
#include "shell.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/parallelization/synchronous_lock.h"
#include "acme/platform/node.h"
#include "acme/platform/system.h"
#include "acme/filesystem/filesystem/directory_context.h"
#include "acme/filesystem/filesystem/file_context.h"
#include "apex/platform/context.h"
#include "aura/graphics/image/drawing.h"
#include "aura/graphics/image/icon.h"
#include "aura/graphics/image/list.h"


#include "acme/_operating_system.h"



namespace windowing_universal_windows
{


   shell::shell()
   {

      //m_iMaxThreadCount = maximum(4, ::get_processor_count());

      m_iMaxThreadCount = 1;

      defer_create_synchronization();

      m_iThread = 0;

      //defer_co_initialize_ex(false);


   }


   shell::~shell()
   {

   }


   void shell::initialize(::particle* pparticle)
   {

      if (m_bInitialized)
      {

         //return ::success;

         return;

      }

      //auto estatus = 

      //::user::shell::initialize(pparticle);

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //estatus = __construct_new(m_pmessagequeue);


      //if (!estatus)
      //{

      //   return estatus;

      //}

      //m_pmessagequeue->create_message_queue("user::shell", this);

      //return estatus;

      ::user::shell::initialize(pparticle);
    
      node()->defer_co_initialize_ex(true);

   }


   ::user::shell::_get_file_image_ * shell::new_get_file_image()
   {

      auto pgetfileimage = ___new _get_file_image_;

      //pgetfileimage->m_knownfoldermanager.CoCreateInstance(CLSID_KnownFolderManager);

      //SHGetDesktopFolder(&pgetfileimage->m_pfolderDesktop);

      //SHGetMalloc(&pgetfileimage->m_pmalloc);

      //SHGetImageList(SHIL_SMALL, IID_IImageList, (void **)&pgetfileimage->m_pimagelistSmall);

      //SHGetImageList(SHIL_LARGE, IID_IImageList, (void **)&pgetfileimage->m_pimagelistLarge);

      //SHGetImageList(SHIL_EXTRALARGE, IID_IImageList, (void **)&pgetfileimage->m_pimagelistExtraLarge);

      //SHGetImageList(SHIL_JUMBO, IID_IImageList, (void **)&pgetfileimage->m_pimagelistJumbo);

      return pgetfileimage;

   }


   //      int shell::thread::get_image_by_file_extension(oswindow image_key & imagekey, ::color::color colorBackground)
   //      {
   //
   //#ifdef WINDOWS_DESKTOP
   //
   //         return get_foo_image(imagekey, colorBackground);
   //
   //#else
   //
   //         return I32_MINIMUM;
   //
   //#endif // WINDOWS_DESKTOP
   //
   //      }

   
   bool shell::defer_set_thumbnail(::user::shell::_get_file_image_ & getfileimage)
   {

      //if (m_bRequireHighQualityThumbnail)
      //{

         bool bThumbnail = ::user::shell::defer_set_thumbnail(getfileimage);

         return bThumbnail;

      //}

      //return false;

      //auto bThumbnail = _defer_set_thumbnail_IThumbnailProvider((_get_file_image_ &)getfileimage);

      //return bThumbnail;

   }


   //bool shell::_defer_set_thumbnail_IThumbnailProvider(_get_file_image_ & getfileimage)
   //{
   //   
   //   comptr < IThumbnailHandlerFactory > pthumbnailhandlerfactory;

   //   HRESULT hrThumbnailHandlerFactory = getfileimage.m_pshellfolder.As(pthumbnailhandlerfactory);

   //   if (SUCCEEDED(hrThumbnailHandlerFactory) && pthumbnailhandlerfactory)
   //   {

   //      comptr < IThumbnailProvider > pthumbnailprovider;

   //      HRESULT hrGetThumbnailHandler = pthumbnailhandlerfactory->GetThumbnailHandler(
   //         getfileimage.m_itemidlistChild,
   //         nullptr,
   //         __interface_of(pthumbnailprovider));

   //      if(SUCCEEDED(hrGetThumbnailHandler) && pthumbnailprovider)
   //      {

   //         getfileimage.m_iImage = _reserve_image(getfileimage.m_imagekey);

   //         if (getfileimage.m_iImage >= 0)
   //         {

   //            ::image::image_pointer pimageFirst;

   //            ::image::image_pointer pimage;

   //            for (int i = m_iaSize.get_upper_bound(); i >= 0; i--)
   //            {

   //               WTS_ALPHATYPE alphatype = {};

   //               HBITMAP hbitmap = nullptr;

   //               int iSize = m_iaSize[i];

   //               HRESULT hrThumbnail = pthumbnailprovider->GetThumbnail(iSize, &hbitmap, &alphatype);

   //               if (SUCCEEDED(hrThumbnail) && hbitmap != nullptr)
   //               {

   //                  pimage = create_image_from_hbitmap(hbitmap);

   //               }

   //               if (!pimage)
   //               {

   //                  if (!pimageFirst)
   //                  {

   //                     return false;

   //                  }

   //                  pimage = pimageFirst;

   //               }
   //               else
   //               {

   //                  if (!pimageFirst)
   //                  {

   //                     pimageFirst = pimage;

   //                  }

   //               }

   //               ::image::image_source imagesource(pimage);

   //               ::image::image_drawing_options imagedrawingoptions(::double_rectangle(), e_placement_aspect_fit);

   //               set_image(getfileimage.m_iImage, iSize, { imagedrawingoptions, imagesource });

   //            }

   //            return true;

   //         }

   //      }

   //   }

   //   return false;

   //}

      // returned image should be "Definitive" icon/pimage->
      // maybe fallback but not temporary
   bool shell::_internal_get_file_image(_get_file_image_ & getfileimage)
   {


      getfileimage.m_iImage = 0;

      //_get_file_image_data_ getfileimage;

      //getfileimage.m_itemidlist = getfileimage.m_itemidlistParam;
      //comptr < IShellFolder> pshellfolder;

      //::itemidlist itemidlist(itemidlistParam);

      //::itemidlist itemidlistChild;

      //::itemidlist itemidlistFolder;

      ::string strChild;

      //if (getfileimage.m_itemidlist.has_child())
      //{

      //   getfileimage.m_itemidlistFolder = getfileimage.m_itemidlist.last_item_id_removed();

      //   getfileimage.m_itemidlistChild = getfileimage.m_itemidlist.last();

      //   getfileimage.m_pfolderDesktop->BindToObject(
      //      getfileimage.m_itemidlistFolder,
      //      nullptr,
      //      IID_IShellFolder, 
      //      (void **) &getfileimage.m_pshellfolder);

      //   if (getfileimage.m_pshellfolder && getfileimage.m_itemidlistChild.m_pidl)
      //   {

      //      STRRET strretChild;

      //      HRESULT hr = getfileimage.m_pshellfolder->GetDisplayNameOf(getfileimage.m_itemidlistChild, 0, &strretChild);

      //      if (SUCCEEDED(hr))
      //      {

      //         strChild = ::itemidlist::_display_name(strretChild, getfileimage.m_itemidlistChild);

      //         output_debug_string(strChild);

      //      }

      //   }

      //}
      //else
      //{

      //   getfileimage.m_itemidlistChild = getfileimage.m_itemidlist;

      //}

      //getfileimage.m_iImage = I32_MINIMUM;

      //if (would_set_thumbnail_for(getfileimage))
      //{

      //   if (defer_set_thumbnail(getfileimage))
      //   {

      //      return true;

      //   }

      //}



      //int iType;

      //switch (getfileimage.m_imagekey.m_eicon)
      //{
      //case e_icon_normal:
      //   iType = 0;
      //   break;
      //case e_icon_open:
      //   iType = GIL_OPENICON;
      //   break;
      //default:
      //   // unexpected icon type
      //   ASSERT(false);
      //   getfileimage.m_iImage = I32_MINIMUM;
      //   return false;
      //}




      //string strFileParam(getfileimage.m_imagekey.m_strPath);

      //string strResource;

      //WCHAR wszPath[_MAX_PATH * 6];

      ////WCHAR szPath[_MAX_PATH * 6];

      //HICON hicon16 = nullptr;

      //HICON hicon48 = nullptr;

      //HRESULT hrIconLocation = E_FAIL;

      //HRESULT hrExtract = E_FAIL;

      //HRESULT hrExtractIconUI = E_FAIL;

      //HRESULT hrGetOverlayInfo = E_FAIL;

      //HRESULT hrGetLocation = E_FAIL;

      //string strExtra;

      //string strPathEx;

      //strPathEx = strFileParam;

      //unicode_to_utf8(strExtra, getfileimage.m_wstrExtra);

      //if (strExtra.get_length() > 0)
      //{

      //   strPathEx += ":" + strExtra;

      //}

      //

      //auto puser = user();

      //auto psystem = system();

      //auto pnode = psystem->node();

      //auto pwindowing = puser->windowing()->cast < windowing >();

      //HWND hwnd = as_hwnd(pwindowing->system_window()->get_oswindow());

      //comptr < IExtractIconW > piextracticon;

      //comptr< IShellItemImageFactory> pfactory;

      //string strPath(getfileimage.m_imagekey.m_strPath);

      //wstring wstrPath(strPath);

      //if (getfileimage.m_imagekey.m_strPath.case_insensitive_ends(".sln"))
      //{

      //   output_debug_string(".sln");

      //}

      ////auto psystem = system();


      //comptr < IShellIcon > pshellicon;

      //HRESULT hrShellIcon= getfileimage.m_pshellfolder.As(pshellicon);

      //if (SUCCEEDED(hrShellIcon) && pshellicon)
      //{

      //   int iIconIndex = -1;

      //   HRESULT hrGetIconOf = pshellicon->GetIconOf(getfileimage.m_itemidlistChild, 0, &iIconIndex);

      //   if (SUCCEEDED(hrGetIconOf))
      //   {

      //      getfileimage.m_imagekey.m_strPath = "::system";

      //      getfileimage.m_imagekey.m_iIcon = iIconIndex;

      //      if (contains_image(getfileimage.m_imagekey, getfileimage.m_iImage))
      //      {

      //         return true;
      //         //return getfileimage.m_iImage;

      //      }

      //      getfileimage.m_iImage = _reserve_image(getfileimage.m_imagekey);

      //      if(getfileimage.m_iImage >= 0)
      //      {

      //         add_system_icon(iIconIndex, getfileimage);

      //         //return getfileimage.m_iImage;

      //         return true;

      //      }

      //   }

      //}



      ////HRESULT hr = SHCreateItemFromIDList(itemidlist, IID_IShellItemImageFactory, (void **) &pfactory);

      ////if(SUCCEEDED(hr))
      ////{

      ////   getfileimage.m_iImage = _reserve_image(imagekey);

      ////   int iSuccessCount = 0;

      ////   for (auto & iSize : m_iaSize)
      ////   {

      ////      HBITMAP hbitmap = nullptr;

      ////      SIZE size = { iSize, iSize };

      ////      if (SUCCEEDED(pfactory->GetImage(size, 0, &hbitmap)))
      ////      {

      ////         auto pimage = create_image_from_hbitmap(hbitmap);

      ////         set_image(getfileimage.m_iImage, pimage, imagekey.m_cr);

      ////         DeleteObject(hbitmap);

      ////         iSuccessCount++;

      ////      }

      ////   }
      ////      
      ////   return getfileimage.m_iImage;

      ////}

      //comptr < IShellIconOverlayIdentifier > pioverlay;

      //comptr < IExtractImage > piextractimage;

      //HRESULT hrIconOverlay = E_FAIL;

      //HRESULT hrExtractImage = E_FAIL;

      //if (getfileimage.m_pshellfolder)
      //{

      //   //hrIconOverlay = pshellfolder->GetUIObjectOf(
      //   //   hwnd,
      //   //   1,
      //   //   itemidlistChild,
      //   //   IID_IShellIconOverlayIdentifier,
      //   //   nullptr,
      //   //   (void **)&pioverlay);


      //   //if (pioverlay)
      //   //{

      //   //   int iIndex = 0;

      //   //   DWORD dwFlags = 0;

      //   //   if (SUCCEEDED(hrGetOverlayInfo = pioverlay->GetOverlayInfo(
      //   //      wszPath,
      //   //      sizeof(wszPath),
      //   //      &iIndex,
      //   //      &dwFlags)))
      //   //   {

      //   //      if (wcscmp(wszPath, L"*") == 0)
      //   //      {

      //   //         imagekey.m_iIcon = I32_MINIMUM;

      //   //         imagekey.set_extension(strFileParam);

      //   //         imagekey.m_strPath = "";

      //   //      }
      //   //      else
      //   //      {

      //   //         auto psystem = system();

      //   //         auto pnode = psystem->node();

      //   //         imagekey.set_path(pnode->expand_env(szPath));

      //   //         imagekey.m_iIcon = iIndex;

      //   //         imagekey.m_strExtension = "";

      //   //      }

      //   //   }

      //   //}
      //   //else
      //   //{

      //    hrExtractImage = getfileimage.m_pshellfolder->GetUIObjectOf(
      //         hwnd,
      //         1,
      //       getfileimage.m_itemidlistChild,
      //         IID_IExtractImage,
      //         nullptr,
      //         (void **)&piextractimage);


      //      if (piextractimage)
      //      {

      //         SIZE s;

      //         s.cx = 48;

      //         s.cy = 48;

      //         DWORD dwDepth = 32;

      //         DWORD dwFlags = 0;

      //         if (SUCCEEDED(hrGetLocation = piextractimage->GetLocation(

      //            wszPath,
      //            sizeof(wszPath),
      //            nullptr,
      //            &s,
      //            dwDepth,
      //            &dwFlags)))
      //         {


      //            if (wcscmp(wszPath, L"*") == 0)
      //            {

      //               getfileimage.m_imagekey.m_iIcon = I32_MINIMUM;

      //               getfileimage.m_imagekey.set_path(strFileParam);

      //               getfileimage.m_imagekey.m_strPath = "";

      //            }
      //            else
      //            {

      //               auto psystem = system();

      //               auto pnode = psystem->node();

      //               getfileimage.m_imagekey.set_path(pnode->expand_environment_variables(wszPath));

      //               getfileimage.m_imagekey.m_iIcon = 0;

      //               getfileimage.m_imagekey.m_strExtension = "";

      //            }

      //         }

      //      }
      //      else
      //      {

      //         getfileimage.m_imagekey.set_path(strFileParam);

      //         getfileimage.m_imagekey.m_iIcon = 0;

      //      }

      //   //}

      //}

      //if (FAILED(hrExtractImage) && getfileimage.m_pshellfolder)
      //{

      //   hrExtractIconUI = getfileimage.m_pshellfolder->GetUIObjectOf(
      //      hwnd,
      //      1,
      //      getfileimage.m_itemidlistChild,
      //      IID_IExtractIconW,
      //      nullptr,
      //      (void **)&piextracticon);

      //}

      //unsigned int uExtractIconLocationFlags = 0;

      //string strIconLocation;

      //if(piextracticon)
      //{

      //   int iIcon = 0;

      //   if (SUCCEEDED(hrIconLocation = piextracticon->GetIconLocation(
      //      iType,
      //      wszPath,
      //      sizeof(wszPath) / sizeof(wszPath[0]),
      //      &iIcon,
      //      &uExtractIconLocationFlags)))
      //   {

      //      if (wcscmp(wszPath, L"*") == 0)
      //      {

      //         getfileimage.m_imagekey.m_iIcon = I32_MINIMUM;

      //         getfileimage.m_imagekey.set_extension(strFileParam);

      //         getfileimage.m_imagekey.m_strPath = "";

      //      }
      //      else
      //      {

      //         strIconLocation = pnode->expand_environment_variables(wszPath);

      //         getfileimage.m_imagekey.set_path(strIconLocation);

      //         getfileimage.m_imagekey.m_iIcon = iIcon;

      //         getfileimage.m_imagekey.m_strExtension = "";

      //      }

      //   }

      //}

      //::file::path pathTarget;

      //if (((FAILED(hrIconLocation) && FAILED(hrGetLocation))
      //   || getfileimage.m_imagekey.m_iIcon == I32_MINIMUM
      //   || !m_papplication->file().exists(strIconLocation))
      //   && strFileParam.case_insensitive_ends(".lnk"))
      //{

      //   m_papplication->file().resolve_link(pathTarget, strFileParam);

      //   if (!m_papplication->file().exists(pathTarget) && !m_papplication->dir().is(pathTarget))
      //   {

      //      if (pathTarget.case_insensitive_ends(".exe"))
      //      {

      //         getfileimage.m_imagekey.set_path(pathTarget);

      //      }
      //      else
      //      {

      //         getfileimage.m_imagekey.set_path("");

      //      }

      //      get_image_by_file_extension(getfileimage);

      //      //return getfileimage.m_iImage;
      //      return true;

      //   }

      //   if (FAILED(hrIconLocation) && FAILED(hrGetLocation))
      //   {

      //      getfileimage.m_imagekey.set_path(pathTarget);

      //      //getfileimage.m_iImage = get_file_image(getfileimage.m_imagekey, getfileimage.m_wstrExtra, getfileimage.m_imagekey.m_cr);

      //      _get_file_image(getfileimage);

      //      //return getfileimage.m_iImage;
      //      return true;

      //   }

      //}
      //else
      //{

      //   pathTarget = strFileParam;

      //}

      //if (getfileimage.m_imagekey.m_iIcon == I32_MINIMUM)
      //{

      //   if (getfileimage.m_imagekey.m_strShellThemePrefix.has_character())
      //   {

      //      string strExtension = pathTarget.final_extension();

      //      image_key imagekeyTheme;

      //      string strFooPath = getfileimage.m_imagekey.m_strShellThemePrefix + "foo." + strExtension;

      //      imagekeyTheme.set_path(strFooPath);

      //      imagekeyTheme.m_iIcon = 0;

      //      if (contains_image(imagekeyTheme, getfileimage.m_iImage))
      //      {

      //         //return getfileimage.m_iImage;

      //         return true;

      //      }

      //      string strIcon;

      //      strIcon = directory_system()->config() / "shell/app_theme" / getfileimage.m_imagekey.m_strShellThemePrefix + strExtension + ".ico";

      //      if (m_papplication->file().exists(strIcon))
      //      {

      //         if (reserve_image(getfileimage))
      //         {

      //            set_icon(strIcon, getfileimage);

      //         }

      //         //return getfileimage.m_iImage;
      //         return true;

      //      }

      //   }

      //   if (wcscmp(wszPath, L"*") == 0)
      //   {

      //      get_image_by_file_extension(getfileimage);

      //      return true;

      //   }

      //}

      //if (uExtractIconLocationFlags & GIL_NOTFILENAME)
      //{

      //   if (reserve_image(getfileimage))
      //   {

      //      HICON hicon = nullptr;

      //      HRESULT hrExtract = E_FAIL;

      //      synchronous_lock synchronouslock(synchronization());

      //      auto iaSize = m_iaSize;

      //      synchronouslock.unlock();

      //      for (auto iSize : iaSize)
      //      {

      //         if (iSize <= 16)
      //         {

      //            if (SUCCEEDED(hrExtract = piextracticon->Extract(

      //               wszPath,
      //               getfileimage.m_imagekey.m_iIcon,
      //               nullptr,
      //               &hicon,
      //               iSize << 16)))
      //            {

      //               add_icon(iSize, hicon, getfileimage);

      //               ::DestroyIcon(hicon);

      //            }

      //         }
      //         else
      //         {

      //            if (SUCCEEDED(hrExtract = piextracticon->Extract(

      //               wszPath,
      //               getfileimage.m_imagekey.m_iIcon,
      //               &hicon,
      //               nullptr,
      //               iSize)))
      //            {

      //               add_icon(iSize, hicon, getfileimage);

      //               ::DestroyIcon(hicon);

      //            }

      //         }

      //      }

      //   }

      //   //return getfileimage.m_iImage;

      //   return true;

      //}
      //else if (strIconLocation.has_character())
      //{

      //   if (strIconLocation.case_insensitive_ends(".ico"))
      //   {

      //      set_image_ico(strIconLocation, getfileimage);

      //   }
      //   else
      //   {

      //      set_image_resource(strIconLocation, getfileimage);

      //   }

      //   //return getfileimage.m_iImage;

      //   return true;

      //}


      ////if (imagekey.m_iIcon >= 0 && strFileParam.get_length() > 0)
      ////{

      ////   SHFILEINFOW shfi16;

      ////   SHFILEINFOW shfi48;

      ////   wstring wstrPath(strFileParam);

      ////   SHGetFileInfoW(
      ////   wstrPath,
      ////   FILE_ATTRIBUTE_NORMAL,
      ////   &shfi16,
      ////   sizeof(shfi16),
      ////   SHGFI_ICON
      ////   | SHGFI_SMALLICON);

      ////   SHGetFileInfoW(
      ////   wstrPath,
      ////   FILE_ATTRIBUTE_NORMAL,
      ////   &shfi48,
      ////   sizeof(shfi48),
      ////   SHGFI_ICON
      ////   | SHGFI_LARGEICON);

      ////   bool b16 = false;

      ////   bool b48 = false;

      ////   if (shfi16.hIcon != nullptr || shfi48.hIcon != nullptr)
      ////   {

      ////      if (reserve_image(imagekey, getfileimage.m_iImage))
      ////      {

      ////         add_icon_set(&shfi16, &shfi48, colorBackground, b16, b48, getfileimage.m_iImage);

      ////         if (!b16 && shfi16.hIcon != nullptr)
      ////         {

      ////            ::DestroyIcon(shfi16.hIcon);

      ////         }

      ////         if (!b48 && shfi48.hIcon != nullptr)
      ////         {

      ////            ::DestroyIcon(shfi48.hIcon);

      ////         }


      ////      }

      ////   }

      ////}

      //getfileimage.m_imagekey.set_extension(pathTarget);

      //getfileimage.m_imagekey.m_strPath.empty();

      //getfileimage.m_imagekey.m_iIcon = 0;

      //get_image_by_file_extension(getfileimage);

      return true;

   }


   void shell::get_image_by_file_extension(_get_file_image_ & getfileimage)
   {

      if (reserve_image(getfileimage))
      {

         //SHFILEINFOW shfi = {};

         //wstring wstrFilePath;

         //if (getfileimage.m_imagekey.m_eattribute.has(e_file_attribute_directory))
         //{

         //   SHGetFileInfoW(
         //      L"foo",
         //      FILE_ATTRIBUTE_DIRECTORY,
         //      &shfi,
         //      sizeof(shfi),
         //      SHGFI_USEFILEATTRIBUTES
         //      | SHGFI_SYSICONINDEX);


         //}
         //else
         //{

         //   wstrFilePath = wstring(L"foo.") + wstring(getfileimage.m_imagekey.m_strExtension);

         //   SHGetFileInfoW(
         //      wstrFilePath,
         //      FILE_ATTRIBUTE_NORMAL,
         //      &shfi,
         //      sizeof(shfi),
         //      SHGFI_USEFILEATTRIBUTES |
         //      SHGFI_SYSICONINDEX);

         //}

         //add_system_icon(shfi.iIcon, getfileimage);

      }

//      return iImage;

   }


   //index shell::GetCSIDL(LPITEMIDLIST piidl)

   //{
   //   LPITEMIDLIST ppidl;

   //   int csidla[] =
   //   {
   //      CSIDL_DESKTOP,
   //      CSIDL_DRIVES,
   //      CSIDL_PERSONAL,
   //      CSIDL_NETHOOD,
   //      CSIDL_NETWORK,
   //      CSIDL_BITBUCKET,
   //      -1,
   //   };

   //   int * pcsidl = csidla;

   //   while (*pcsidl != -1)
   //   {
   //      if (SUCCEEDED(SHGetSpecialFolderLocation(
   //                    nullptr,
   //                    *pcsidl,
   //                    &ppidl)))
   //      {
   //         if (_017ItemIDListIsEqual(ppidl, piidl))

   //         {
   //            m_pmalloc->Free(ppidl);
   //            break;
   //         }
   //         m_pmalloc->Free(ppidl);
   //      }
   //      pcsidl++;
   //   }

   //   return *pcsidl;


   //}


   //index shell::GetCSIDLSort(::collection::index iCsidl)
   //{
   //   switch (iCsidl)
   //   {
   //   case CSIDL_DESKTOP:
   //      return 100;
   //   case CSIDL_PERSONAL:
   //      return 200;
   //   case CSIDL_DRIVES:
   //      return 300;
   //   case CSIDL_NETHOOD:
   //      return 1000;
   //   default:
   //      return 2000 + iCsidl;
   //   }

   //}


   shell::enum_folder shell::get_folder_type(::particle * pparticle, const ::scoped_string & scopedstr)
   {

      return get_folder_type(pparticle, wstring(str));

   }


   shell::enum_folder shell::get_folder_type(::particle * pparticle, const ::wstring & wstrPath)
   {

      string strPath;

      strPath = wstrPath;

      if (directory_system()->is(strPath))
      {

         return e_folder_file_system;

      }
      else
      {

         if (system()->fast_is_decompressable_folder(strPath))
         {

            return e_folder_zip;

         }
         else
         {

            return e_folder_none;

         }

      }

   }


   //int shell::_get_file_image(const image_key & key)
   bool shell::_get_file_image(::user::shell::_get_file_image_ & getfileimage)
   {

      return _get_file_image((_get_file_image_ &)getfileimage);

   }


   bool shell::_get_file_image(_get_file_image_ & getfileimage)
   {

      getfileimage.m_iImage = I32_MINIMUM;

      if (getfileimage.m_imagekey.m_strPath.case_insensitive_begins("uifs:"))
      {

         if (reserve_image(getfileimage))
         {

            ::file::path path = directory()->matter("cloud.ico");

            set_icon(path, getfileimage);

         }

         //return iImage;
         return true;

      }
      else if (getfileimage.m_imagekey.m_strPath.case_insensitive_begins("fs:"))
      {

         if (reserve_image(getfileimage))
         {

            ::file::path path = directory()->matter("remote.ico");

            set_icon(path, getfileimage);

         }

         //return iImage;

         return true;

      }
      else if (getfileimage.m_imagekey.m_strPath.case_insensitive_begins("ftp:"))
      {

         if (reserve_image(getfileimage))
         {

            ::file::path path = directory()->matter("ftp.ico");

            set_icon(path, getfileimage);

         }

         //return iImage;

         return true;

      }

      if (getfileimage.m_imagekey.m_strPath.case_insensitive_ends(".aura"))
      {

         string str = file()->as_string(getfileimage.m_imagekey.m_strPath);

         if (str.case_insensitive_begins_eat("ca2prompt\r\n"))
         {

            str.trim();


         }

         //return iImage;

         return true;

      }

      //if (getfileimage.m_knownfoldermanager)
      //{

      //   auto pknownfolderstruct = get_known_folder_struct(getfileimage.m_imagekey.m_strPath);

      //   if (pknownfolderstruct)
      //   {

      //      comptr < IKnownFolder > pknownfolder;

      //      HRESULT hrGetFolder = getfileimage.m_knownfoldermanager->GetFolder(pknownfolderstruct->m_atomKnownFolder, &pknownfolder);

      //      if (SUCCEEDED(hrGetFolder) && pknownfolder)
      //      {

      //         KNOWNFOLDER_DEFINITION definition = {};

      //         HRESULT hrFolderDefinition = pknownfolder->GetFolderDefinition(&definition);

      //         if (SUCCEEDED(hrFolderDefinition))
      //         {

      //            getfileimage.m_iImage = _reserve_image(getfileimage.m_imagekey);

      //            if(getfileimage.m_iImage >= 0)
      //            {

      //               string strResource = definition.pszIcon;

      //               string_array stra;

      //               stra.explode(",", strResource);

      //               if (stra.get_size() == 2)
      //               {

      //                  getfileimage.m_imagekey.m_strPath = stra[0];

      //                  getfileimage.m_imagekey.m_iIcon = atoi(stra[1]);

      //                  set_image_resource(stra[0], getfileimage);

      //                  //return getfileimage.m_iImage;

      //                  return true;

      //               }

      //            }

      //         }

      //      }

      //   }

      //}

      //SHFILEINFOW shfi = {};

      //if (getfileimage.m_imagekey.m_strPath.get_length() == 2
      //   && ansi_char_isalpha(getfileimage.m_imagekey.m_strPath[0])
      //   && getfileimage.m_imagekey.m_strPath[1] == ':')
      //{

      //   ::wstring wstrPath(getfileimage.m_imagekey.m_strPath);

      //   if (SHGetFileInfoW(wstrPath, 0, &shfi, sizeof(shfi), SHGFI_ICONLOCATION))
      //   {

      //      string strPath = shfi.szDisplayName;

      //      if (strPath.has_character())
      //      {

      //         getfileimage.m_imagekey.m_iIcon = shfi.iIcon;

      //         set_image_resource(strPath, getfileimage);

      //         //return getfileimage.m_iImage;
      //         return true;

      //      }

      //   }

      //}



      //// Check for URL addresses like uifs://, http://, or ftp://
      //// Except A: B: C: (Windows drive letters)
      //// And then should find icon by extension if
      //// it is a file or as folder otherwise.

      //character_count iFind = imagekey.m_strPath.case_insensitive_find("://");

      //character_count iFind2 = imagekey.m_strPath.case_insensitive_find(":");

      //if (iFind >= 0 || iFind2 >= 2)
      //{

      //   string strProtocol = imagekey.m_strPath.left()(maximum(iFind, iFind2));

      //   int i = 0;

      //   while (i < strProtocol.get_length() && character_isalnum(strProtocol[i]))
      //   {

      //      i++;

      //   }

      //   if (i > 0 && i == strProtocol.get_length())
      //   {

      //      // heuristically valid protocol
      //      return get_image_by_file_extension(imagekey);

      //   }

      //   if (imagekey.m_eattribute.has(file_attribute_directory))
      //   {

      //      return get_image_by_file_extension(imagekey);

      //   }

      //}

      string strExtension;

      if (getfileimage.m_imagekey.m_strPath.case_insensitive_ends(".sln"))
      {

         //output_debug_string("test .sln");

      }

      string str(getfileimage.m_imagekey.m_strPath);

      if (str == "foo")
      {

         get_image_by_file_extension(getfileimage);

         return true;

      }

      if (str.begins_eat("foo."))
      {

         get_image_by_file_extension(getfileimage);

         return true;

      }

      processed_path(getfileimage);

      ::file::path pathProcessed = getfileimage.m_pathProcessed;

      ::file::path pathFolder = pathProcessed.folder();

      //itemidlist idlist;

      bool bParseError = false;

      //try
      //{

      //   getfileimage.m_itemidlist.parse(pathProcessed);

      //}
      //catch (...)
      //{

      //   bParseError = true;

      //}

      //if (bParseError)
      //{

      //   get_image_by_file_extension(getfileimage);

      //   return true;

      //}

    /*  itemidlist idlistAbsolute = idlist;

      itemidlist idlistChild;

      idlistChild = idlistAbsolute.last();

      if (idlistChild.m_pidl)
      {

         idlistAbsolute = idlist - 1;

      }
      else
      {

         idlistAbsolute = nullptr;

         idlistChild = idlist;

      }*/

      return _internal_get_file_image(getfileimage);

      //return getfileimage.m_iImage;

      //return true;

   }


   //int _017ItemIDListGetLen(LPITEMIDLIST piidl)

   //{
   //   if (piidl == nullptr)

   //      return 0;
   //   LPSHITEMID  pshiid = (LPSHITEMID)lpiidl;

   //   LPSHITEMID  pshiidLast = nullptr;

   //   USHORT cb;
   //   int iLen = 0;
   //   while (true)
   //   {
   //      cb = pshiid->cb;

   //      iLen += cb;
   //      if (cb == 0)
   //         break;
   //      pshiidLast = lpshiid;

   //      pshiid = (LPSHITEMID)(((unsigned char *)lpshiid) + cb);


   //   }

   //   return iLen;

   //}


   //void shell::initialize(::particle * pparticle)
   //{

   //   if (m_bInitialized)
   //   {

   //      //return ::success;

   //      return;

   //   }

   //   //auto estatus = 
   //   
   //   ::user::shell::initialize(pparticle);

   //   //if (!estatus)
   //   //{

   //   //   return estatus;

   //   //}

   //   //estatus = __construct_new(m_pmessagequeue);


   //   //if (!estatus)
   //   //{

   //   //   return estatus;

   //   //}

   //   //m_pmessagequeue->create_message_queue("user::shell", this);

   //   //return estatus;

   //}


   //::e_status shell::run()
   void shell::run()
   {


      node()->defer_co_initialize_ex(true);

      //m_thumbnailhandlerfactory.CoCreateInstance(CLSID_ThumbnailHandlerFactory);

      //auto estatus =
      
      ::user::shell::run();

      //if (!estatus)
      //{

      //   return estatus;

      //}

      //return estatus;

   }


   void shell::add_system_icon(int iIcon, _get_file_image_ & getfileimage)
   {

      synchronous_lock synchronouslock(synchronization());

      auto iaSize = m_iaSize;

      synchronouslock.unlock();

      for (auto iSize : iaSize)
      {

         //getfileimage.m_iImage = add_system_icon(iSize, iIcon, getfileimage);
         add_system_icon(iSize, iIcon, getfileimage);

      }

      //return iImage;

   }


   void shell::set_icon(const ::file::path & pathIconParam, ::user::shell::_get_file_image_ & getfileimageParam)
   {

      auto & getfileimage = (_get_file_image_ &)getfileimageParam;

      //if (pathIconParam.case_insensitive_ends(".ico"))
      //{

      //   synchronous_lock synchronouslock(synchronization());

      //   auto iaSize = m_iaSize;

      //   synchronouslock.unlock();

      //   ::file::path path = m_papplication->defer_process_matter_path(pathIconParam);

      //   for (auto iSize : m_iaSize)
      //   {

      //      HICON hicon = (HICON)LoadImageW(nullptr, wstring(path), IMAGE_ICON, iSize, iSize, LR_LOADFROMFILE);

      //      if (hicon == nullptr)
      //      {

      //         unsigned int dwLastError = ::GetLastError();

      //         output_debug_string("LastError = " + __string(dwLastError));

      //      }

      //      add_icon(iSize, hicon, getfileimage);

      //      ::DestroyIcon(hicon);

      //   }

      //}
      //else
      //{

      //   ::user::shell::set_icon(getfileimage.m_iImage, pathIconParam);

      //}

      //return get;

   }


   void shell::add_icon(int iSize, HICON hicon, _get_file_image_ & getfileimage)
   {

      synchronous_lock synchronouslock(m_pimagelist[iSize]->synchronization());

      synchronous_lock slHover(m_pimagelistHover[iSize]->synchronization());

      auto pwindowingicon = __create_new < icon >();

      pwindowingicon->add_icon(hicon);

      auto pdrawicon = __øcreate < ::image::icon >();
     
      pdrawicon->initialize_with_windowing_icon(pwindowingicon);

      {

         ::image::image_source imagesource(pdrawicon);

         //   m_pimagelist[iSize]->set(getfileimage.m_iImage, imagesource);

         //}

         //if (getfileimage.m_iImage == 14)
         //{

         //   //iImage = m_pimagelist[iSize]->add(picon);

         //}

         //getfileimage.m_iImage = add_hover_image(iSize, getfileimage.m_iImage, getfileimage.m_imagekey.m_cr);

         //return iImage;

         set_image(getfileimage.m_iImage, iSize, imagesource);

      }

   }


   void shell::add_system_icon(int iSize, int iIcon, _get_file_image_ & getfileimage)
   {

      bool bUsed = false;

      //if (iSize <= 16)
      //{

      //   add_system_icon(iSize, getfileimage.m_pimagelistSmall, iIcon, getfileimage);

      //}
      //else if (iSize <= 32)
      //{

      //   add_system_icon(iSize, getfileimage.m_pimagelistLarge, iIcon, getfileimage);

      //}
      //else if (iSize <= 48)
      //{

      //   add_system_icon(iSize, getfileimage.m_pimagelistExtraLarge, iIcon, getfileimage);

      //}
      //else
      //{

      //   add_system_icon(iSize, getfileimage.m_pimagelistJumbo, iIcon, getfileimage);

      //}

   }


   void shell::add_system_icon(int iSize, IImageList * pil, int iIcon, _get_file_image_ & getfileimage)
   {

      if (pil != nullptr)
      {

         //HICON hicon = nullptr;

         //HRESULT hr = pil->GetIcon(iIcon, ILD_TRANSPARENT, &hicon);

         //if (hicon != nullptr)
         //{

         //   add_icon(iSize, hicon, getfileimage);

         //   ::DestroyIcon(hicon);

         //}

      }

      //return iImage;

   }


   void shell::set_image_ico(const ::scoped_string & scopedstrIconLocation, _get_file_image_ & getfileimage)
   {

      ASSERT(strIconLocation.case_insensitive_ends(".ico"));

      image_key imagekeyIco;

      imagekeyIco.set_path(strIconLocation, false);

      imagekeyIco.m_iIcon = 0;

      if (reserve_image(getfileimage))
      {

         set_icon(strIconLocation, getfileimage);

      }

   }


   void shell::set_image_resource(const ::scoped_string & scopedstrIconLocation, _get_file_image_ & getfileimage)
   {

      ASSERT(!strIconLocation.case_insensitive_ends(".ico"));

      //image_key imagekeyIco;

      getfileimage.m_imagekey.set_path(strIconLocation, false);

      //getfileimage.m_imagekey.m_iIcon = imagekey.m_iIcon;

      if (reserve_image(getfileimage))
      {

         //auto psystem = system();

         //auto pnode = psystem->node()->m_pAuraPlatform;

         //synchronous_lock synchronouslock(synchronization());

         //auto iaSize = m_iaSize;

         //synchronouslock.unlock();

         //for (auto iSize : iaSize)
         //{

         //   int iSizeOut = iSize;

         //   HICON hicon = pnode->extract_resource_icon(strIconLocation, iSizeOut, iSizeOut, getfileimage.m_imagekey.m_iIcon);

         //   if (hicon == nullptr && getfileimage.m_imagekey.m_iIcon == 0)
         //   {

         //      hicon = pnode->extract_resource_icon(strIconLocation, iSizeOut, iSizeOut, I32_MINIMUM);

         //   }

         //   add_icon(iSize, hicon, getfileimage);

         //   ::DestroyIcon(hicon);

         //}

      }

   }


   void shell::destroy()
   {

      //return 
      
      ::user::shell::destroy();

   }


} // namespace windowing_universal_windows



