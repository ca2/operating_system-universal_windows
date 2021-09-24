// Created by camilo on 2021-08-31 11:56 BRT <3ThomasBS__!!
#include "framework.h"
#include "_windows_runtime.h"


::winrt::Windows::UI::Core::CoreDispatcherPriority windows_runtime_UICoreDispatcherPriority(enum_priority epriority)
{

   if (epriority <= e_priority_idle)
   {

      return ::winrt::Windows::UI::Core::CoreDispatcherPriority::Idle;

   }
   else if (epriority <= e_priority_below_normal)
   {

      return ::winrt::Windows::UI::Core::CoreDispatcherPriority::Low;

   }
   else if (epriority >= e_priority_above_normal)
   {

      return ::winrt::Windows::UI::Core::CoreDispatcherPriority::High;

   }
   else if (epriority >= e_priority_above_normal)
   {

      return ::winrt::Windows::UI::Core::CoreDispatcherPriority::High;

   }
   else
   {

      return ::winrt::Windows::UI::Core::CoreDispatcherPriority::Normal;

   }

}


// Converts a Win32 thread priority to WinRT format.
::winrt::Windows::System::Threading::WorkItemPriority windows_runtime_WorkItemPriority(enum_priority epriority)
{

   if (epriority <= e_priority_below_normal)
   {

      return ::winrt::Windows::System::Threading::WorkItemPriority::Low;

   }
   else if (epriority <= e_priority_above_normal)
   {

      return ::winrt::Windows::System::Threading::WorkItemPriority::High;

   }
   else
   {

      return ::winrt::Windows::System::Threading::WorkItemPriority::Normal;

   }

}


CLASS_DECL_EXPORT void main_branch(::matter * pobjectTask, enum_priority epriority)
{

   windows_runtime_async([pobjectTask]()
   {

      pobjectTask->operator()();

   }, epriority);

}



CLASS_DECL_ACME_UNIVERSAL_WINDOWS ::winrt::Windows::Storage::StorageFolder windows_runtime_folder(::object * pobject, string & strRelative, string & strPrefix)
{

   if (str::begins_eat_ci(strRelative, "image://"))
   {

      strPrefix = "image://";

      return ::winrt::Windows::Storage::KnownFolders::PicturesLibrary();

   }
   else if (str::begins_eat_ci(strRelative, "music://"))
   {

      strPrefix = "music://";

      return ::winrt::Windows::Storage::KnownFolders::MusicLibrary();

   }
   else if (str::begins_eat_ci(strRelative, "video://"))
   {

      strPrefix = "video://";

      return ::winrt::Windows::Storage::KnownFolders::VideosLibrary();

   }
   else if (str::begins_eat_ci(strRelative, "document://"))
   {

      strPrefix = "document://";

      return ::winrt::Windows::Storage::KnownFolders::DocumentsLibrary();

   }
   else if (str::begins_eat_ci(strRelative, "dropbox://"))
   {

      string strHome = getenv("USERPROFILE");

      strPrefix = "document://";

      return ::winrt::Windows::Storage::KnownFolders::DocumentsLibrary();

   }
   //else if (str::begins_eat_ci(strRelative, ::dir::sys_temp()))
   //{

   //   strPrefix = ::dir::sys_temp();

   //   return ::winrt::Windows::Storage::ApplicationData::Current.TemporaryFolder();

   //}
   else if (::str::begins_eat_ci(strRelative, string(::winrt::Windows::Storage::ApplicationData::Current().LocalFolder().Path().begin())))
   {

      strPrefix = ::winrt::Windows::Storage::ApplicationData::Current().LocalFolder().Path().begin();

      return ::winrt::Windows::Storage::ApplicationData::Current().LocalFolder();

   }
   else
   {

      auto path = pobject->m_pcontext->defer_process_path(strRelative);

      if (path.is_empty())
      {

         return nullptr;

      }

      ::file::path pathFolder;

      string strName;

      if (pobject->m_psystem->m_pacmedir->_is(path))
      {

         pathFolder = path;

      }
      else
      {

         pathFolder = path.folder();

         strName = path.name();

      }

      if (pathFolder.is_empty())
      {

         return nullptr;

      }

      auto hstrRelative = __hstring(pathFolder);

      try
      {

         auto item = ::winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(hstrRelative).get();

         if (!item)
         {

            return nullptr;

         }

         strPrefix = pathFolder;

         strRelative = strName;

         return item;


      }
      catch (...)
      {


      }

      return nullptr;

   }

}


CLASS_DECL_ACME_UNIVERSAL_WINDOWS ::winrt::Windows::Storage::StorageFolder windows_runtime_folder(::object * pobject, const ::file::path & path)
{

   try
   {

      string strRelative = path;

      string strPrefix;

      auto folder = windows_runtime_folder(pobject, strRelative, strPrefix);

      if (folder == nullptr)
      {

         return nullptr;

      }

      if (strRelative.is_empty())
      {


         return folder;

      }

      string_array straItems;

      string_array straSeparator;

      straSeparator.add("/");

      straSeparator.add("\\");

      straItems.add_smallest_tokens(strRelative, straSeparator, false);

      for (auto & strItem : straItems)
      {

         auto hstrItem = __hstring(strItem);

         auto item = folder.TryGetItemAsync(hstrItem).get();

         if (!item)
         {

            return nullptr;

         }

         if (!item.IsOfType(winrt::Windows::Storage::StorageItemTypes::Folder))
         {

            return nullptr;

         }

         folder = item.as<::winrt::Windows::Storage::StorageFolder>();

         if (!folder)
         {

            return nullptr;

         }

      }

      return folder;

   }
   catch (...)
   {

   }

   return nullptr;

}



//CLASS_DECL_ACME::winrt::Windows::Storage::StorageFolder ^ winrt_folder(string & strPath, string & strPrefix)
//{
//
//   ::winrt::Windows::Storage::StorageFolder ^ folder = winrt_folder1(strPath, strPrefix);
//
//   if (folder != nullptr)
//   {
//
//      return folder;
//
//   }
//
//
//   ::file::patha patha;
//
//   ::file::path path(strPath);
//
//   patha = path.ascendants_path();
//
//   for (auto & pathFolder : patha)
//   {
//
//      ::winrt::Windows::Storage::StorageFolder ^ folder = ::winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(pathFolder).get();
//
//      if (folder != nullptr)
//      {
//
//         strPrefix = pathFolder;
//
//         return folder;
//
//      }
//
//   }
//
//   return nullptr;
//
//}


//CLASS_DECL_ACME::winrt::Windows::Storage::StorageFolder ^ winrt_get_folder(const ::string & strFolder, string & strPrefix)
//{
//
//   string strPath = strFolder;
//
//   ::winrt::Windows::Storage::StorageFolder ^ folder = winrt_folder(strPath, strPrefix);
//
//   if (folder == nullptr)
//   {
//
//      return nullptr;
//
//   }
//
//   if (strPath.is_empty())
//   {
//
//      return folder;
//
//   }
//   else
//   {
//
//      strPath.replace("/", "\\");
//
//      return wait(folder->GetFolderAsync(strPath));
//
//   }
//
//}
//

//CLASS_DECL_ACME::winrt::Windows::Storage::StorageFolder ^ winrt_get_folder(const ::string & strFolder)
//{
//
//   string strPrefix;
//
//   return winrt_get_folder(strFolder, strPrefix);
//
//}
//
//
//CLASS_DECL_ACME::winrt::Windows::Storage::StorageFolder ^ winrt_get_folder(const ::string & strFolder, string & strPrefix, string & strRelative)
//{
//
//   string strPath = strFolder;
//
//   ::winrt::Windows::Storage::StorageFolder ^ folder = winrt_folder(strPath, strPrefix);
//
//   if (folder == nullptr)
//   {
//
//      return nullptr;
//
//   }
//
//   strRelative = strFolder;
//
//   strPrefix.replace("/", "\\");
//
//   strRelative.replace("/", "\\");
//
//   strPrefix.trim_right("/\\");
//
//   strRelative.trim_right("/\\");
//
//   ::str::begins_eat_ci(strRelative, strPrefix);
//
//   strRelative.trim_left("/\\");
//
//   return folder;
//
//}
//


//bool windows_runtime_is_folder(const wchar_t * pwszPath)
//{
//
//   ::u32 dwLastError = ::GetLastError();
//
//   string strPrefix;
//
//   {
//
//      string strRelative = path1;
//
//      auto folderBase = winrt_folder(strRelative, strPrefix);
//
//      if (folderBase != nullptr)
//      {
//
//         strRelative.replace("/", "\\");
//
//         strPrefix.replace("/", "\\");
//
//         ::str::begins_eat_ci(strRelative, strPrefix);
//
//         strRelative.trim("/\\");
//
//         //strPrefix.trim_right("/\\");
//
//         try
//         {
//
//            auto folder = folderBase->GetFolderAsync(strRelative);
//
//            if (folder != nullptr)
//            {
//
//               return true;
//
//            }
//
//         }
//         catch (...)
//         {
//
//         }
//
//      }
//
//   }
//
//   return false;
//
//
//
//}
//

//::winrt::Windows::Storage::StorageFolder windows_runtime_folder(const ::string & strPath)
//{
//
//
//   ::winrt::Windows::Storage::StorageFolder folder(nullptr);
//
//   string strPrefix;
//
//   string str = strPath;
//
//   try
//   {
//
//      if (string(psz).compare_ci("image://") == 0)
//      {
//
//         strPrefix = "image://";
//
//         try
//         {
//
//            folder = ::winrt::Windows::Storage::KnownFolders::PicturesLibrary;
//
//         }
//         catch (...)
//         {
//
//            folder = nullptr;
//
//         }
//
//      }
//      else if (string(psz).compare_ci("music://") == 0)
//      {
//
//         strPrefix = "music://";
//
//         try
//         {
//
//            folder = ::winrt::Windows::Storage::KnownFolders::MusicLibrary;
//
//         }
//         catch (...)
//         {
//
//            folder = nullptr;
//
//         }
//
//      }
//      else if (string(psz).compare_ci("video://") == 0)
//      {
//
//         strPrefix = "video://";
//
//         try
//         {
//
//            folder = ::winrt::Windows::Storage::KnownFolders::VideosLibrary;
//
//         }
//         catch (...)
//         {
//
//            folder = nullptr;
//
//         }
//
//      }
//      else if (string(psz).compare_ci("document://") == 0)
//      {
//
//         strPrefix = "document://";
//
//         try
//         {
//
//            folder = ::winrt::Windows::Storage::KnownFolders::DocumentsLibrary;
//
//         }
//         catch (...)
//         {
//
//            folder = nullptr;
//
//         }
//
//      }
//      else
//      {
//
//         if (::str::begins_eat_ci(str, "image://"))
//         {
//
//            strPrefix = "image://";
//
//            try
//            {
//
//               folder = ::winrt::Windows::Storage::KnownFolders::PicturesLibrary;
//
//            }
//            catch (...)
//            {
//
//               folder = nullptr;
//
//            }
//
//         }
//
//         if (::str::begins_eat_ci(str, "music://"))
//         {
//
//            strPrefix = "music://";
//
//            try
//            {
//
//               folder = ::winrt::Windows::Storage::KnownFolders::MusicLibrary;
//
//            }
//            catch (...)
//            {
//
//               folder = nullptr;
//
//            }
//
//         }
//
//         if (::str::begins_eat_ci(str, "video://"))
//         {
//
//            strPrefix = "video://";
//
//            try
//            {
//
//               folder = ::winrt::Windows::Storage::KnownFolders::VideosLibrary;
//
//            }
//            catch (...)
//            {
//
//               folder = nullptr;
//
//            }
//
//         }
//
//         if (::str::begins_eat_ci(str, "document://"))
//         {
//
//            strPrefix = "document://";
//
//            try
//            {
//
//               folder = ::winrt::Windows::Storage::KnownFolders::DocumentsLibrary;
//
//            }
//            catch (...)
//            {
//
//               folder = nullptr;
//
//            }
//
//         }
//
//         if (strPrefix.has_char())
//         {
//
//            string_array stra;
//
//            stra.explode("/", str);
//
//            string str;
//
//            while (stra.get_count() > 0)
//            {
//
//               str = stra[0];
//
//               if (str.has_char())
//               {
//
//                  folder = wait(folder->GetFolderAsync(str));
//
//                  strPrefix += str + "/";
//
//               }
//
//               stra.erase_at(0);
//
//            }
//
//         }
//         else
//         {
//
//            folder = ::winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(str).get();
//
//            strPrefix = str + "/";
//
//         }
//
//      }
//
//   }
//   catch (...)
//   {
//
//      return;
//
//   }
//
//   if (folder == nullptr)
//   {
//
//      return;
//
//   }
//
//   string strPath = string(begin(folder->Path));
//
//   auto a = folder->GetItemsAsync().get();
//
//   for (u32 u = 0; u < a->Size; u++)
//   {
//
//      string strPath = string(begin(a->GetAt(u)->Path));
//
//      string str = path;
//
//      stra.add(path);
//
//   }
//
//
//}
//
//
//bool windows_runtime_ls_dir(wchar_t *** ppwszPath, int * piCount, const wchar_t * pwszFolder)
//{
//
//
//
//
//}
//
//
//bool windows_runtime_ls_file(wchar_t *** ppwszPath, int * piCount, const wchar_t * pwszFolder)
//{
//
//   ::winrt::Windows::Storage::StorageFolder ^ folder = wait(::winrt::Windows::Storage::StorageFolder::GetFolderFromPathAsync(string(psz)));
//
//   ::winrt::Windows::Foundation::Collections::IVectorView < ::winrt::Windows::Storage::StorageFolder ^ > ^ a = wait(folder->GetFoldersAsync());
//
//   for (u32 u = 0; u < a->Size; u++)
//   {
//      stra.add(begin(a->GetAt(u)->Path));
//   }
//
//}


CLASS_DECL_ACME_UNIVERSAL_WINDOWS memsize windows_runtime_read_buffer(void * p, memsize s, ::winrt::Windows::Storage::Streams::IBuffer ibuffer)
{

   s = minimum(s, ibuffer.Length());

   auto reader = ::winrt::Windows::Storage::Streams::DataReader::FromBuffer(ibuffer);

   winrt::array_view < byte > bytes((unsigned char *) p, ((unsigned char *)p) + s);

   reader.ReadBytes(bytes);

   return bytes.size();

}



memory windows_runtime_buffer_memory(::winrt::Windows::Storage::Streams::IBuffer ibuffer)
{

   auto reader = ::winrt::Windows::Storage::Streams::DataReader::FromBuffer(ibuffer);

   memory memory(ibuffer.Capacity());

   ::winrt::array_view < byte > bytes(memory.begin(), memory.end());

   reader.ReadBytes(bytes);

   return ::move(memory);

}


::winrt::array_view <byte > windows_runtime_bytes(const void * p, memsize s)
{

   return { (byte *)p, ((byte *)p) + s };


}


::winrt::Windows::Storage::Streams::IBuffer windows_runtime_buffer(const void * p, memsize s)
{

   ::winrt::Windows::Storage::Streams::DataWriter writer;

   ::winrt::array_view < const byte > bytes((byte *) p, ((byte *) p) + s);

   writer.WriteBytes(bytes);

   return writer.DetachBuffer();

}


uptr keycode_to_char(uptr n)
{

   return n;

}


uptr virtualkey_to_char(::winrt::Windows::System::VirtualKey e)
{
   switch (e)
   {
   case ::winrt::Windows::System::VirtualKey::Number0:
      return '0';
   case ::winrt::Windows::System::VirtualKey::Number1:
      return '1';
   case ::winrt::Windows::System::VirtualKey::Number2:
      return '2';
   case ::winrt::Windows::System::VirtualKey::Number3:
      return '3';
   case ::winrt::Windows::System::VirtualKey::Number4:
      return '4';
   case ::winrt::Windows::System::VirtualKey::Number5:
      return '5';
   case ::winrt::Windows::System::VirtualKey::Number6:
      return '6';
   case ::winrt::Windows::System::VirtualKey::Number7:
      return '7';
   case ::winrt::Windows::System::VirtualKey::Number8:
      return '8';
   case ::winrt::Windows::System::VirtualKey::Number9:
      return '9';
   case ::winrt::Windows::System::VirtualKey::A:
      return 'a';
   case ::winrt::Windows::System::VirtualKey::B:
      return 'b';
   case ::winrt::Windows::System::VirtualKey::C:
      return 'c';
   case ::winrt::Windows::System::VirtualKey::D:
      return 'd';
   case ::winrt::Windows::System::VirtualKey::E:
      return 'e';
   case ::winrt::Windows::System::VirtualKey::F:
      return 'f';
   case ::winrt::Windows::System::VirtualKey::G:
      return 'g';
   case ::winrt::Windows::System::VirtualKey::H:
      return 'h';
   case ::winrt::Windows::System::VirtualKey::I:
      return 'i';
   case ::winrt::Windows::System::VirtualKey::J:
      return 'j';
   case ::winrt::Windows::System::VirtualKey::K:
      return 'k';
   case ::winrt::Windows::System::VirtualKey::L:
      return 'l';
   case ::winrt::Windows::System::VirtualKey::M:
      return 'm';
   case ::winrt::Windows::System::VirtualKey::N:
      return 'n';
   case ::winrt::Windows::System::VirtualKey::O:
      return 'o';
   case ::winrt::Windows::System::VirtualKey::P:
      return 'p';
   case ::winrt::Windows::System::VirtualKey::Q:
      return 'q';
   case ::winrt::Windows::System::VirtualKey::R:
      return 'r';
   case ::winrt::Windows::System::VirtualKey::S:
      return 's';
   case ::winrt::Windows::System::VirtualKey::T:
      return 't';
   case ::winrt::Windows::System::VirtualKey::U:
      return 'u';
   case ::winrt::Windows::System::VirtualKey::V:
      return 'v';
   case ::winrt::Windows::System::VirtualKey::W:
      return 'w';
   case ::winrt::Windows::System::VirtualKey::X:
      return 'x';
   case ::winrt::Windows::System::VirtualKey::Y:
      return 'y';
   case ::winrt::Windows::System::VirtualKey::Z:
      return 'z';
   case ::winrt::Windows::System::VirtualKey::Shift:
      return VK_SHIFT;
   case ::winrt::Windows::System::VirtualKey::LeftShift:
      return VK_LSHIFT;
   case ::winrt::Windows::System::VirtualKey::RightShift:
      return VK_RSHIFT;
   case ::winrt::Windows::System::VirtualKey::Control:
      return VK_CONTROL;
   case ::winrt::Windows::System::VirtualKey::LeftControl:
      return VK_LCONTROL;
   case ::winrt::Windows::System::VirtualKey::RightControl:
      return VK_RCONTROL;
   case ::winrt::Windows::System::VirtualKey::Menu:
      return VK_MENU;
   case ::winrt::Windows::System::VirtualKey::LeftMenu:
      return VK_LMENU;
   case ::winrt::Windows::System::VirtualKey::RightMenu:
      return VK_RMENU;
   case ::winrt::Windows::System::VirtualKey::Tab:
      return VK_TAB;
   case ::winrt::Windows::System::VirtualKey::Enter:
      return VK_RETURN;
   default:
      ;
   }
   return (int)e;
}


::user::enum_key virtualkey_to_userkey(::winrt::Windows::System::VirtualKey e, bool & bSpecialKey)
{
   bSpecialKey = false;
   switch (e)
   {
   case ::winrt::Windows::System::VirtualKey::Number0:
      return ::user::e_key_0;
   case ::winrt::Windows::System::VirtualKey::Number1:
      return ::user::e_key_1;
   case ::winrt::Windows::System::VirtualKey::Number2:
      return ::user::e_key_2;
   case ::winrt::Windows::System::VirtualKey::Number3:
      return ::user::e_key_3;
   case ::winrt::Windows::System::VirtualKey::Number4:
      return ::user::e_key_4;
   case ::winrt::Windows::System::VirtualKey::Number5:
      return ::user::e_key_5;
   case ::winrt::Windows::System::VirtualKey::Number6:
      return ::user::e_key_6;
   case ::winrt::Windows::System::VirtualKey::Number7:
      return ::user::e_key_7;
   case ::winrt::Windows::System::VirtualKey::Number8:
      return ::user::e_key_8;
   case ::winrt::Windows::System::VirtualKey::Number9:
      return ::user::e_key_9;
   case ::winrt::Windows::System::VirtualKey::A:
      return ::user::e_key_a;
   case ::winrt::Windows::System::VirtualKey::B:
      return ::user::e_key_b;
   case ::winrt::Windows::System::VirtualKey::C:
      return ::user::e_key_c;
   case ::winrt::Windows::System::VirtualKey::D:
      return ::user::e_key_d;
   case ::winrt::Windows::System::VirtualKey::E:
      return ::user::e_key_e;
   case ::winrt::Windows::System::VirtualKey::F:
      return ::user::e_key_f;
   case ::winrt::Windows::System::VirtualKey::G:
      return ::user::e_key_g;
   case ::winrt::Windows::System::VirtualKey::H:
      return ::user::e_key_h;
   case ::winrt::Windows::System::VirtualKey::I:
      return ::user::e_key_i;
   case ::winrt::Windows::System::VirtualKey::J:
      return ::user::e_key_j;
   case ::winrt::Windows::System::VirtualKey::K:
      return ::user::e_key_k;
   case ::winrt::Windows::System::VirtualKey::L:
      return ::user::e_key_l;
   case ::winrt::Windows::System::VirtualKey::M:
      return ::user::e_key_m;
   case ::winrt::Windows::System::VirtualKey::N:
      return ::user::e_key_n;
   case ::winrt::Windows::System::VirtualKey::O:
      return ::user::e_key_o;
   case ::winrt::Windows::System::VirtualKey::P:
      return ::user::e_key_p;
   case ::winrt::Windows::System::VirtualKey::Q:
      return ::user::e_key_q;
   case ::winrt::Windows::System::VirtualKey::R:
      return ::user::e_key_r;
   case ::winrt::Windows::System::VirtualKey::S:
      return ::user::e_key_s;
   case ::winrt::Windows::System::VirtualKey::T:
      return ::user::e_key_t;
   case ::winrt::Windows::System::VirtualKey::U:
      return ::user::e_key_u;
   case ::winrt::Windows::System::VirtualKey::V:
      return ::user::e_key_v;
   case ::winrt::Windows::System::VirtualKey::W:
      return ::user::e_key_w;
   case ::winrt::Windows::System::VirtualKey::X:
      return ::user::e_key_x;
   case ::winrt::Windows::System::VirtualKey::Y:
      return ::user::e_key_y;
   case ::winrt::Windows::System::VirtualKey::Z:
      return ::user::e_key_z;
   case ::winrt::Windows::System::VirtualKey::Shift:
      bSpecialKey = true;
      return ::user::e_key_shift;
   case ::winrt::Windows::System::VirtualKey::LeftShift:
      bSpecialKey = true;
      return ::user::e_key_left_shift;
   case ::winrt::Windows::System::VirtualKey::RightShift:
      bSpecialKey = true;
      return ::user::e_key_right_shift;
   case ::winrt::Windows::System::VirtualKey::Control:
      bSpecialKey = true;
      return ::user::e_key_control;
   case ::winrt::Windows::System::VirtualKey::LeftControl:
      bSpecialKey = true;
      return ::user::e_key_left_control;
   case ::winrt::Windows::System::VirtualKey::RightControl:
      bSpecialKey = true;
      return ::user::e_key_right_control;
   case ::winrt::Windows::System::VirtualKey::Menu:
      bSpecialKey = true;
      return ::user::e_key_alt;
   case ::winrt::Windows::System::VirtualKey::LeftMenu:
      bSpecialKey = true;
      return ::user::e_key_left_alt;
   case ::winrt::Windows::System::VirtualKey::RightMenu:
      bSpecialKey = true;
      return ::user::e_key_right_alt;
   case ::winrt::Windows::System::VirtualKey::Tab:
      bSpecialKey = true;
      return ::user::e_key_tab;
   case ::winrt::Windows::System::VirtualKey::Enter:
      bSpecialKey = true;
      return ::user::e_key_return;
   case ::winrt::Windows::System::VirtualKey::Delete:
      bSpecialKey = true;
      return ::user::e_key_delete;
   case ::winrt::Windows::System::VirtualKey::Back:
      bSpecialKey = true;
      return ::user::e_key_back;
   case ::winrt::Windows::System::VirtualKey::Left:
      bSpecialKey = true;
      return ::user::e_key_left;
   case ::winrt::Windows::System::VirtualKey::Right:
      bSpecialKey = true;
      return ::user::e_key_right;
   case ::winrt::Windows::System::VirtualKey::Up:
      bSpecialKey = true;
      return ::user::e_key_up;
   case ::winrt::Windows::System::VirtualKey::Down:
      bSpecialKey = true;
      return ::user::e_key_down;
   case ::winrt::Windows::System::VirtualKey::PageUp:
      bSpecialKey = true;
      return ::user::e_key_up;
   case ::winrt::Windows::System::VirtualKey::PageDown:
      bSpecialKey = true;
      return ::user::e_key_down;
   case ::winrt::Windows::System::VirtualKey::Home:
      bSpecialKey = true;
      return ::user::e_key_home;
   case ::winrt::Windows::System::VirtualKey::End:
      bSpecialKey = true;
      return ::user::e_key_end;
   case ::winrt::Windows::System::VirtualKey::Escape:
      bSpecialKey = true;
      return ::user::e_key_escape;
   case (::winrt::Windows::System::VirtualKey) 186:
      return ::user::e_key_semicolon;
   case (::winrt::Windows::System::VirtualKey)187:
      return ::user::e_key_equal;
   case (::winrt::Windows::System::VirtualKey)188:
      return ::user::e_key_comma;
   case (::winrt::Windows::System::VirtualKey)189:
      return ::user::e_key_hyphen;
   case (::winrt::Windows::System::VirtualKey)190:
      return ::user::e_key_dot;
   case (::winrt::Windows::System::VirtualKey)191:
      return ::user::e_key_semicolon2;
   case (::winrt::Windows::System::VirtualKey)193:
      return ::user::e_key_slash2;
   case ::winrt::Windows::System::VirtualKey::Space:
      return ::user::e_key_space;
   default:
      {
         int iKey = (int)e;
         //ASSERT(FALSE);
      }
   }

   return (::user::enum_key)e;

}


uptr virtualkey_to_code(::winrt::Windows::System::VirtualKey e)
{
   switch (e)
   {
   case (::winrt::Windows::System::VirtualKey)190:
      return '.';
   case ::winrt::Windows::System::VirtualKey::Number0:
      return 1;
   case ::winrt::Windows::System::VirtualKey::Number1:
      return 2;
   case ::winrt::Windows::System::VirtualKey::Number2:
      return 3;
   case ::winrt::Windows::System::VirtualKey::Number3:
      return 4;
   case ::winrt::Windows::System::VirtualKey::Number4:
      return 5;
   case ::winrt::Windows::System::VirtualKey::Number5:
      return 6;
   case ::winrt::Windows::System::VirtualKey::Number6:
      return 7;
   case ::winrt::Windows::System::VirtualKey::Number7:
      return 8;
   case ::winrt::Windows::System::VirtualKey::Number8:
      return 9;
   case ::winrt::Windows::System::VirtualKey::Number9:
      return 10;
   case ::winrt::Windows::System::VirtualKey::A:
      return 'a';
   case ::winrt::Windows::System::VirtualKey::B:
      return 'b';
   case ::winrt::Windows::System::VirtualKey::C:
      return 'ca';
   case ::winrt::Windows::System::VirtualKey::D:
      return 'd';
   case ::winrt::Windows::System::VirtualKey::E:
      return 'e';
   case ::winrt::Windows::System::VirtualKey::F:
      return 'f';
   case ::winrt::Windows::System::VirtualKey::G:
      return 'g';
   case ::winrt::Windows::System::VirtualKey::H:
      return 'h';
   case ::winrt::Windows::System::VirtualKey::I:
      return 'i';
   case ::winrt::Windows::System::VirtualKey::J:
      return 'j';
   case ::winrt::Windows::System::VirtualKey::K:
      return 'k';
   case ::winrt::Windows::System::VirtualKey::L:
      return 'l';
   case ::winrt::Windows::System::VirtualKey::M:
      return 'm';
   case ::winrt::Windows::System::VirtualKey::N:
      return 'n';
   case ::winrt::Windows::System::VirtualKey::O:
      return 'o';
   case ::winrt::Windows::System::VirtualKey::P:
      return 'p';
   case ::winrt::Windows::System::VirtualKey::Q:
      return 'q';
   case ::winrt::Windows::System::VirtualKey::R:
      return 'r';
   case ::winrt::Windows::System::VirtualKey::S:
      return 's';
   case ::winrt::Windows::System::VirtualKey::T:
      return 't';
   case ::winrt::Windows::System::VirtualKey::U:
      return 'u';
   case ::winrt::Windows::System::VirtualKey::V:
      return 'v';
   case ::winrt::Windows::System::VirtualKey::W:
      return 'w';
   case ::winrt::Windows::System::VirtualKey::Y:
      return 'y';
   case ::winrt::Windows::System::VirtualKey::Z:
      return 'z';
   case ::winrt::Windows::System::VirtualKey::Shift:
      return VK_SHIFT;
   case ::winrt::Windows::System::VirtualKey::LeftShift:
      return VK_LSHIFT;
   case ::winrt::Windows::System::VirtualKey::RightShift:
      return VK_RSHIFT;
   case ::winrt::Windows::System::VirtualKey::Control:
      return VK_CONTROL;
   case ::winrt::Windows::System::VirtualKey::LeftControl:
      return VK_LCONTROL;
   case ::winrt::Windows::System::VirtualKey::RightControl:
      return VK_RCONTROL;
   case ::winrt::Windows::System::VirtualKey::Menu:
      return VK_MENU;
   case ::winrt::Windows::System::VirtualKey::LeftMenu:
      return VK_LMENU;
   case ::winrt::Windows::System::VirtualKey::RightMenu:
      return VK_RMENU;
   default:
      ;
   }
   return (int)e;
}


//::u32 system_main(::apex::system * psystem)
//{
//
//   try
//   {
//
//      psystem->m_bReady = true;
//
//      psystem->on_run();
//
//      if(psystem->m_error.get_exit_code() != 0)
//      {
//
//         ::output_debug_string(L"application::main on_run termination failure");
//
//      }
//
//      //if(psystem->is_system())
//      //{
//
//      //   m_psystem->set_finish();
//
//      //}
//
//      try
//      {
//
//         psystem->term_thread();
//
//      }
//      catch(...)
//      {
//
//         psystem->m_error.set_if_not_set(-1);
//
//      }
//
//   }
//   catch(::exit_exception &)
//   {
//
//      //m_psystem->set_finish();
//
//   }
//
//   return 0;
//
//}


// namespace user
// {

//    /*::color::color g_colorSystemAppBackground;

//    CLASS_DECL_APEX color32_t set_system_app_background_color()

//    CLASS_DECL_APEX color32_t get_system_app_background_color()
//    {

//       auto color = System->get_session()->m_frameworkview->m_puisettings->GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

//       auto r = color.R;

//       auto g = color.G;

//       auto b = color.B;

//       return argb(255, r, g, b);

//    }*/

//    //CLASS_DECL_APEX double get_system_app_luminance()
//    //{

//    //   auto color = System->get_session()->m_frameworkview->m_puisettings->GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

//    //   double r = color.R;

//    //   double g = color.G;

//    //   double b = color.B;

//    //   return (r + g + b) / (255.0 * 3.0);

//    //}


//    //CLASS_DECL_APEX void os_update_colors()
//    //{

//    //   // App Background Color
//    //   {


//    //      auto color = System->get_session()->m_frameworkview->m_puisettings->GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

//    //      auto r = color.R;

//    //      auto g = color.G;

//    //      auto b = color.B;

//    //      set_system_app_background_color(::color::color(r, g, b));

//    //   }


//    //   // Luminance
//    //   {


//    //      auto color = System->get_session()->m_frameworkview->m_puisettings->GetColorValue(::winrt::Windows::UI::ViewManagement::UIColorType::Background);

//    //      double r = color.R;

//    //      double g = color.G;

//    //      double b = color.B;

//    //      set_system_app_luminance((r + g + b) / (255.0 * 3.0));

//    //   }

//    //}

//    CLASS_DECL_APEX void os_update_dark_mode()
//    {

//       double dLuminance = get_system_app_luminance();

//       bool bDarkMode = dLuminance < 0.5;

//       set_system_dark_mode(bDarkMode);

//       set_app_dark_mode(bDarkMode);

//    }


// } // namespace user



