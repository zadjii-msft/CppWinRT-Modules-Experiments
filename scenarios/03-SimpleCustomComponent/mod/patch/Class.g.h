// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210806.1

#pragma once
#include "winrt/SimpleCustomComponent.h"
namespace winrt::SimpleCustomComponent::implementation
{
    template <typename D, typename... I>
    struct __declspec(empty_bases) Class_base : implements<D, SimpleCustomComponent::Class, I...>
    {
        using base_type = Class_base;
        using class_type = SimpleCustomComponent::Class;
        using implements_type = typename Class_base::implements_type;
        using implements_type::implements_type;
        
        hstring GetRuntimeClassName() const
        {
            return L"SimpleCustomComponent.Class";
        }
    };
}
namespace winrt::SimpleCustomComponent::factory_implementation
{
    template <typename D, typename T, typename... I>
    struct __declspec(empty_bases) ClassT : implements<D, winrt::Windows::Foundation::IActivationFactory, I...>
    {
        using instance_type = SimpleCustomComponent::Class;

        hstring GetRuntimeClassName() const
        {
            return L"SimpleCustomComponent.Class";
        }
        auto ActivateInstance() const
        {
            return make<T>();
        }
    };
}

#if defined(WINRT_FORCE_INCLUDE_CLASS_XAML_G_H) || __has_include("Class.xaml.g.h")
#include "Class.xaml.g.h"
#else

namespace winrt::SimpleCustomComponent::implementation
{
    template <typename D, typename... I>
    using ClassT = Class_base<D, I...>;
}

#endif
