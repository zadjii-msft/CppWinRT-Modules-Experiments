// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.3.4.5

#pragma once
#ifndef WINRT_Windows_UI_Xaml_Interop_2_H
#define WINRT_Windows_UI_Xaml_Interop_2_H
#include "winrt/impl/Windows.UI.Xaml.Interop.1.h"
WINRT_EXPORT namespace winrt::Windows::UI::Xaml::Interop
{
    struct BindableVectorChangedEventHandler : winrt::Windows::Foundation::IUnknown
    {
        BindableVectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        BindableVectorChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> BindableVectorChangedEventHandler(L lambda);
        template <typename F> BindableVectorChangedEventHandler(F* function);
        template <typename O, typename M> BindableVectorChangedEventHandler(O* object, M method);
        template <typename O, typename M> BindableVectorChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> BindableVectorChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(winrt::Windows::UI::Xaml::Interop::IBindableObservableVector const& vector, winrt::Windows::Foundation::IInspectable const& e) const;
    };
    struct NotifyCollectionChangedEventHandler : winrt::Windows::Foundation::IUnknown
    {
        NotifyCollectionChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        NotifyCollectionChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> NotifyCollectionChangedEventHandler(L lambda);
        template <typename F> NotifyCollectionChangedEventHandler(F* function);
        template <typename O, typename M> NotifyCollectionChangedEventHandler(O* object, M method);
        template <typename O, typename M> NotifyCollectionChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> NotifyCollectionChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::Interop::NotifyCollectionChangedEventArgs const& e) const;
    };
    struct TypeName
    {
        hstring Name;
        winrt::Windows::UI::Xaml::Interop::TypeKind Kind;
    };
    inline bool operator==(TypeName const& left, TypeName const& right) noexcept
    {
        return left.Name == right.Name && left.Kind == right.Kind;
    }
    inline bool operator!=(TypeName const& left, TypeName const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) NotifyCollectionChangedEventArgs : winrt::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs
    {
        NotifyCollectionChangedEventArgs(std::nullptr_t) noexcept {}
        NotifyCollectionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Interop::INotifyCollectionChangedEventArgs(ptr, take_ownership_from_abi) {}
        NotifyCollectionChangedEventArgs(winrt::Windows::UI::Xaml::Interop::NotifyCollectionChangedAction const& action, winrt::Windows::UI::Xaml::Interop::IBindableVector const& newItems, winrt::Windows::UI::Xaml::Interop::IBindableVector const& oldItems, int32_t newIndex, int32_t oldIndex);
    };
}
#endif
