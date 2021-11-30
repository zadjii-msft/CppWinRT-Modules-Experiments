#include "pch.h"
#include "Class.h"
#include "Class.g.cpp"

// import winrt;

namespace winrt::WinRTComponent::implementation
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
