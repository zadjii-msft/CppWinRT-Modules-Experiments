#pragma once
#include "Class.g.h"

namespace winrt::RuntimeComponent1::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        winrt::hstring MyProperty();
        void MyProperty(winrt::hstring value);

    private:
        winrt::hstring _foo{ L"Hello from a module" };
        // winrt::Windows::Foundation::Uri _uri{};
    };
}

namespace winrt::RuntimeComponent1::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
