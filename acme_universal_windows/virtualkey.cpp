// Created by camilo on 2023-10-07 21:26 <3ThomasBorregaardSorensen!!
#include "framework.h"
#include "acme/operating_system/universal_windows/_winrt_foundation.h"
#include "_winrt_core.h"
#include "_winrt_system.h"
#include <winrt/Windows.UI.Core.h>


namespace universal_windows
{


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
         //case ::winrt::Windows::System::VirtualKey::Shift:
         //   return VK_SHIFT;
         //case ::winrt::Windows::System::VirtualKey::LeftShift:
         //   return VK_LSHIFT;
         //case ::winrt::Windows::System::VirtualKey::RightShift:
         //   return VK_RSHIFT;
         //case ::winrt::Windows::System::VirtualKey::Control:
         //   return VK_CONTROL;
         //case ::winrt::Windows::System::VirtualKey::LeftControl:
         //   return VK_LCONTROL;
         //case ::winrt::Windows::System::VirtualKey::RightControl:
         //   return VK_RCONTROL;
         //case ::winrt::Windows::System::VirtualKey::Menu:
         //   return VK_MENU;
         //case ::winrt::Windows::System::VirtualKey::LeftMenu:
         //   return VK_LMENU;
         //case ::winrt::Windows::System::VirtualKey::RightMenu:
         //   return VK_RMENU;
         //case ::winrt::Windows::System::VirtualKey::Tab:
         //   return VK_TAB;
         //case ::winrt::Windows::System::VirtualKey::Enter:
         //   return VK_RETURN;
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
      case (::winrt::Windows::System::VirtualKey)186:
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
         return ::user::e_key_semicolon;
      case (::winrt::Windows::System::VirtualKey)193:
         return ::user::e_key_slash;
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
         //case ::winrt::Windows::System::VirtualKey::Shift:
         //   return VK_SHIFT;
         //case ::winrt::Windows::System::VirtualKey::LeftShift:
         //   return VK_LSHIFT;
         //case ::winrt::Windows::System::VirtualKey::RightShift:
         //   return VK_RSHIFT;
         //case ::winrt::Windows::System::VirtualKey::Control:
         //   return VK_CONTROL;
         //case ::winrt::Windows::System::VirtualKey::LeftControl:
         //   return VK_LCONTROL;
         //case ::winrt::Windows::System::VirtualKey::RightControl:
         //   return VK_RCONTROL;
         //case ::winrt::Windows::System::VirtualKey::Menu:
         //   return VK_MENU;
         //case ::winrt::Windows::System::VirtualKey::LeftMenu:
         //   return VK_LMENU;
         //case ::winrt::Windows::System::VirtualKey::RightMenu:
         //   return VK_RMENU;
      default:
         ;
      }
      return (int)e;
   }


} // namespace universal_windows



