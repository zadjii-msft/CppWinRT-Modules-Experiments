#pragma once

#include "Class.g.h"

namespace winrt::SimpleCustomComponent::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        int32_t MyProperty();
        void MyProperty(int32_t value);

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
