#include "framework.h"
#include "imm_context.h"


imm_context::imm_context(::user::interaction * pinteraction) :
   m_pinteraction(pinteraction)
{

   HWND hwnd = as_hwnd(m_pinteraction->get_oswindow());

   m_himc = ImmGetContext(hwnd);

}


imm_context::~imm_context()
{

   HWND hwnd = as_hwnd(m_pinteraction->get_oswindow());

   ImmReleaseContext(hwnd, m_himc);

}



bool imm_context::close()
{

   return ImmSetOpenStatus(m_himc, false) != false;

}


bool imm_context::is_opened() const
{

   return ImmGetOpenStatus(m_himc) != false;

}


bool imm_context::close_candidate(::collection::index iIndex)
{

   return ImmNotifyIME(m_himc, NI_CLOSECANDIDATE, 0, (unsigned int)iIndex) != false;

}


string imm_context::get_string(int iStr)
{

   int iLen = ImmGetCompositionStringW(m_himc, iStr, nullptr, 0);

   wstring wstr;

   unichar * point = wstr.get_buffer(iLen);

   ImmGetCompositionStringW(m_himc, iStr, point, iLen);

   wstr.release_buffer();

   return wstr;

}


string imm_context::_get_candidate(int iList)
{

   memory mem;

   unsigned int dwCount = 0;

   unsigned int dwSize = ImmGetCandidateListW(m_himc, iList, 0, 0);

   if (dwSize == 0)
   {

      unsigned int dw = GetLastError();

      output_debug_string("error " + __string(dw));

   }

   mem.set_size(dwSize);

   LPCANDIDATELIST pc = (LPCANDIDATELIST)mem.get_data();

   if (::is_null(pc))
   {

      return "";

   }

   ImmGetCandidateListW(m_himc, iList, pc, (unsigned int)mem.get_size());

   int iTest = pc->dwOffset[0];

   auto iTest2 = (unsigned char *)&pc->dwOffset[pc->dwCount] - (unsigned char *)pc;

   unichar * pwsz = (unichar *)(mem.get_data() + pc->dwOffset[pc->dwSelection]);

   return pwsz;

}


string imm_context::get_candidate()
{

   for (::collection::index i = 3; i >= 0; i--)
   {

      string str = _get_candidate((int)i);

      if (str.has_character())
      {

         return str;

      }

   }

   return "";

}




