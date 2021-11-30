#include "pch.h"

//import RuntimeComponent1;
import winrt;
#include <stdio.h>

#pragma comment(lib, "oleaut32")

// Note: these two are only needed when compiling with modules.
#pragma comment(lib, "ole32")
#pragma comment(lib, "advapi32")

using namespace winrt;
using namespace Windows::Foundation;

int main() {
  // init_apartment();
    //winrt::Windows::Foundation::Uri uri(L"http://aka.ms/cppwinrt");
    Uri uri(L"http://aka.ms/cppwinrt");
  printf("%ls\n", uri.Domain().c_str());

  // winrt::RuntimeComponent1::Class bar{};

  // MessageBox(nullptr, L"Foo", bar.MyProperty().c_str(), MB_OK);
  MessageBox(nullptr, L"Foo", uri.Domain().c_str(), MB_OK);
  Sleep(2000);
}
