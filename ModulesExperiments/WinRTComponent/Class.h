#pragma once

#include "Class.g.h"

namespace winrt::WinRTComponent::implementation
{
    struct Class : ClassT<Class>
    {
        Class() = default;

        winrt::hstring MyProperty();
        void MyProperty(winrt::hstring value);

    private:
        winrt::hstring _foo{ L"Hello from a module 2" };
        // winrt::Windows::Foundation::Uri _uri{};
    };
}

namespace winrt::WinRTComponent::factory_implementation
{
    struct Class : ClassT<Class, implementation::Class>
    {
    };
}
