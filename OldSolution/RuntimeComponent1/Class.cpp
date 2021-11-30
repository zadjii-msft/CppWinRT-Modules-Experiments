#include "pch.h"

// import winrt;

#include "Class.h"
#include "Class.g.cpp"


#include <stdio.h>

#pragma comment(lib, "oleaut32")

// Note: these two are only needed when compiling with modules.
#pragma comment(lib, "ole32")
#pragma comment(lib, "advapi32")

// using namespace winrt;
// using namespace Windows::Foundation;

namespace winrt::RuntimeComponent1::implementation
{
    winrt::hstring Class::MyProperty()
    {
        return _foo;
        // return _uri.ToString();
    }

    void Class::MyProperty(winrt::hstring value)
    {
        _foo = value;
        //_uri.Domain(value);
    }
}
