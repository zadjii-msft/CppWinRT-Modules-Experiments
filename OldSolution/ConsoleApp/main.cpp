

#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;

int main() {
  init_apartment();
  Uri uri(L"http://aka.ms/cppwinrt");
  printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());
}

/*
import winrt;
#include <stdio.h>

#pragma comment(lib, "oleaut32")

// Note: these two are only needed when compiling with modules.
#pragma comment(lib, "ole32")
#pragma comment(lib, "advapi32")

using namespace winrt;
using namespace Windows::Foundation;

int main() {
  init_apartment();
  Uri uri(L"http://aka.ms/cppwinrt");
  printf("%ls\n", uri.Domain().c_str());
}
*/
