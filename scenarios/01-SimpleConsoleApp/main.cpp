#include "pch.h"

#ifdef COMPILE_WITH_MODULES

import winrt;
#pragma comment(lib, "oleaut32")
#pragma comment(lib, "ole32")
#pragma comment(lib, "advapi32")

#endif

#ifndef COMPILE_WITH_MODULES
#endif


#include <iostream>

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    init_apartment();
    Uri uri(L"http://aka.ms/cppwinrt");
    printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());
}
