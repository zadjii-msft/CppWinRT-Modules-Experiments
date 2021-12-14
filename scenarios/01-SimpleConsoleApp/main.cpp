#include "pch.h"
#include <iostream>

#ifdef COMPILE_WITH_MODULES
import winrt;
#endif

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    init_apartment();
    Uri uri(L"http://aka.ms/cppwinrt");
    printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());
}
