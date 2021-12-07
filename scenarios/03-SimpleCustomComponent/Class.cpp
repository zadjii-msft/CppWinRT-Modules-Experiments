#include "pch.h"

#ifdef COMPILE_WITH_MODULES

// #define CPPWINRT_VERSION "2.0.210806.1"
// import winrt;
// #define WINRT_EXPORT ;

#endif

#include "Class.h"
#include "Class.g.cpp"

#ifdef COMPILE_WITH_MODULES

// #define CPPWINRT_VERSION "2.0.210806.1"
// import winrt;
// #define WINRT_EXPORT ;

#endif

namespace winrt::SimpleCustomComponent::implementation
{
    int32_t Class::MyProperty()
    {
        return _myProperty;
    }

    void Class::MyProperty(int32_t value)
    {
        _myProperty = value;
    }

    winrt::hstring MyTestString()
    {
        winrt::Windows::Foundation::Uri rssFeedUri{ L"https://github.com/microsoft/terminal" };
        return rssFeedUri.Domain();
    }
}
