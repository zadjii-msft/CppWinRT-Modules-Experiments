#include "pch.h"
#include <iostream>

#ifdef COMPILE_WITH_MODULES
import winrt;

// Uncomment this line to try out consuming the SimpleCustomComponent module.
// Spoilers: it doesn't work yet.
//
// #define USE_CUSTOM_MODULE 1

#ifdef USE_CUSTOM_MODULE
import SimpleCustomComponent;
#else
// For now, just include it the old way, so the sln builds.
#include <winrt/SimpleCustomComponent.h>
#endif

#else

#include <winrt/SimpleCustomComponent.h>

#endif

using namespace winrt;
using namespace Windows::Foundation;

int main()
{
    init_apartment();
    Uri uri(L"http://aka.ms/cppwinrt");
    printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());

    winrt::SimpleCustomComponent::Class foo{};

    printf("Foo was %d,\n", foo.MyProperty());
    foo.MyProperty(123);
    printf("    now it's %d\n", foo.MyProperty());
    printf("My string is %ls\n", foo.MyTestString().c_str());
}
