#pragma once

#ifdef COMPILE_WITH_MODULES

// These were some bad tests to see if I could workaround the take_ownership_from_abi thing.

// #define CPPWINRT_VERSION "2.0.210806.1"
#define _WINRT_SUPPRESS_NUMERICS

#endif

// HEY YOU: imports should always come after #includes. Class.h includes
// Class.g.h which includes SimpleCustomComponent.h which includes
// <winrt/base.h>, so make sure these are above the `import winrt`.

#include "Class.g.h"

#ifdef COMPILE_WITH_MODULES

#define CPPWINRT_VERSION "2.0.210806.1"
// #define _WINRT_SUPPRESS_NUMERICS
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
