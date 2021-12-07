#pragma once

#ifdef COMPILE_WITH_MODULES

// #define CPPWINRT_VERSION "2.0.210806.1"
// #define _WINRT_SUPPRESS_NUMERICS
// import winrt;
// #define WINRT_EXPORT ;

#endif

#include "Class.g.h"

#ifdef COMPILE_WITH_MODULES

#define CPPWINRT_VERSION "2.0.210806.1"
#define _WINRT_SUPPRESS_NUMERICS
import winrt;

#endif

namespace winrt::SimpleCustomComponent::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);
        hstring MyTestString();

    private:
        int32_t _myProperty{ 42 };
    };
}

namespace winrt::SimpleCustomComponent::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
