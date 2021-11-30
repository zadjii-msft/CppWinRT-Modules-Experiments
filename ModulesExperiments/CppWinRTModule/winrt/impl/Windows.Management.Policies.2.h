// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Management_Policies_2_H
#define WINRT_Windows_Management_Policies_2_H
#include "winrt/impl/Windows.System.1.h"
#include "winrt/impl/Windows.Management.Policies.1.h"
WINRT_EXPORT namespace winrt::Windows::Management::Policies
{
    struct NamedPolicy
    {
        NamedPolicy() = delete;
        static auto GetPolicyFromPath(param::hstring const& area, param::hstring const& name);
        static auto GetPolicyFromPathForUser(winrt::Windows::System::User const& user, param::hstring const& area, param::hstring const& name);
        static auto TryCreatePolicySetter(param::hstring const& accountId);
        static auto TryCreatePolicySetterForUser(winrt::Windows::System::User const& user, param::hstring const& accountId);
        static auto ClearAllPoliciesAsync(param::hstring const& accountId);
        static auto ClearAllPoliciesAsync();
    };
    struct __declspec(empty_bases) NamedPolicyData : winrt::Windows::Management::Policies::INamedPolicyData
    {
        NamedPolicyData(std::nullptr_t) noexcept {}
        NamedPolicyData(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Policies::INamedPolicyData(ptr, take_ownership_from_abi) {}
        NamedPolicyData(NamedPolicyData const&) noexcept = default;
        NamedPolicyData(NamedPolicyData&&) noexcept = default;
        NamedPolicyData& operator=(NamedPolicyData const&) & noexcept = default;
        NamedPolicyData& operator=(NamedPolicyData&&) & noexcept = default;
    };
    struct __declspec(empty_bases) NamedPolicySetter : winrt::Windows::Management::Policies::INamedPolicySetter
    {
        NamedPolicySetter(std::nullptr_t) noexcept {}
        NamedPolicySetter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Management::Policies::INamedPolicySetter(ptr, take_ownership_from_abi) {}
        NamedPolicySetter(NamedPolicySetter const&) noexcept = default;
        NamedPolicySetter(NamedPolicySetter&&) noexcept = default;
        NamedPolicySetter& operator=(NamedPolicySetter const&) & noexcept = default;
        NamedPolicySetter& operator=(NamedPolicySetter&&) & noexcept = default;
    };
}
#endif
