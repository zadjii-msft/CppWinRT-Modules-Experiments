#include "pch.h"

import winrt;
import WinRTComponent;

#include <iostream>

#pragma comment(lib, "oleaut32")

// Note: these two are only needed when compiling with modules.
// Especially to fix the "unresolved external symbol WINRT_IMPL_CoGetCallContext"
#pragma comment(lib, "ole32")
#pragma comment(lib, "advapi32")

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    init_apartment();
    Uri uri(L"http://aka.ms/cppwinrt");
    printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());

    winrt::WinRTComponent::Class foo{};

    printf("Goodbye, %ls!\n", foo.MyProperty().c_str());
}
