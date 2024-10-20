
#include <collection.h>
#include <ppltasks.h>


class RunBeforeMain
{
public:
   RunBeforeMain()
   {
      //HMODULE hNtDll = (HMODULE)LoadLibrary(_T("ntdll.dll"));
      //FARPROC lpNeeded = GetProcAddress(hNtDll, "NtWaitForMultipleObjects");
      //DebugBreakPoint();
   }
};

RunBeforeMain go;

int wmain(const wchar_t ** psz, int iSize);

//[MTAThread]
int main(::Platform::Array < ::Platform::String ^ > ^ stra)
{

   //auto psystem = p(::apex::system());

   wchar_t ** pp;

   int iSize = stra->Length + 1;

   pp = ___new wchar_t*[iSize];

   pp[0] = nullptr;

   for (int i = 1; i < iSize; i++)
   {

      pp[i] = wcsdup(stra[i - 1]->Data());

   }

   int iRet = wmain(pp, iSize);
   
   return iRet;

}


//#include "openssl/applink.c"



