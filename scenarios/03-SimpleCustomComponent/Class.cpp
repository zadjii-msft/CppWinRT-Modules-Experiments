#include "pch.h"

// HEY YOU: imports should always come after #includes. Class.h includes
// Class.g.h which includes SimpleCustomComponent.h which includes
// <winrt/base.h>, so make sure these are above the `import winrt`.

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
        winrt::Windows::Foundation::Uri myUri{ L"https://github.com/microsoft/terminal" };
        return myUri.Domain();
    }
}
