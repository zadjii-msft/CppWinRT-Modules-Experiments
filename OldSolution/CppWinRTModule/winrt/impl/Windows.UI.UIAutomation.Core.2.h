// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_UI_UIAutomation_Core_2_H
#define WINRT_Windows_UI_UIAutomation_Core_2_H
#include "winrt/impl/Windows.UI.UIAutomation.Core.1.h"
WINRT_EXPORT namespace winrt::Windows::UI::UIAutomation::Core
{
    struct AutomationAnnotationTypeRegistration
    {
        int32_t LocalId;
    };
    inline bool operator==(AutomationAnnotationTypeRegistration const& left, AutomationAnnotationTypeRegistration const& right) noexcept
    {
        return left.LocalId == right.LocalId;
    }
    inline bool operator!=(AutomationAnnotationTypeRegistration const& left, AutomationAnnotationTypeRegistration const& right) noexcept
    {
        return !(left == right);
    }
    struct AutomationRemoteOperationOperandId
    {
        int32_t Value;
    };
    inline bool operator==(AutomationRemoteOperationOperandId const& left, AutomationRemoteOperationOperandId const& right) noexcept
    {
        return left.Value == right.Value;
    }
    inline bool operator!=(AutomationRemoteOperationOperandId const& left, AutomationRemoteOperationOperandId const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AutomationRemoteOperationResult : winrt::Windows::UI::UIAutomation::Core::IAutomationRemoteOperationResult
    {
        AutomationRemoteOperationResult(std::nullptr_t) noexcept {}
        AutomationRemoteOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::UIAutomation::Core::IAutomationRemoteOperationResult(ptr, take_ownership_from_abi) {}
        AutomationRemoteOperationResult(AutomationRemoteOperationResult const&) noexcept = default;
        AutomationRemoteOperationResult(AutomationRemoteOperationResult&&) noexcept = default;
        AutomationRemoteOperationResult& operator=(AutomationRemoteOperationResult const&) & noexcept = default;
        AutomationRemoteOperationResult& operator=(AutomationRemoteOperationResult&&) & noexcept = default;
    };
    struct CoreAutomationRegistrar
    {
        CoreAutomationRegistrar() = delete;
        static auto RegisterAnnotationType(winrt::guid const& guid);
        static auto UnregisterAnnotationType(winrt::Windows::UI::UIAutomation::Core::AutomationAnnotationTypeRegistration const& registration);
    };
    struct __declspec(empty_bases) CoreAutomationRemoteOperation : winrt::Windows::UI::UIAutomation::Core::ICoreAutomationRemoteOperation,
        impl::require<CoreAutomationRemoteOperation, winrt::Windows::UI::UIAutomation::Core::ICoreAutomationRemoteOperation2>
    {
        CoreAutomationRemoteOperation(std::nullptr_t) noexcept {}
        CoreAutomationRemoteOperation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::UIAutomation::Core::ICoreAutomationRemoteOperation(ptr, take_ownership_from_abi) {}
        CoreAutomationRemoteOperation();
        CoreAutomationRemoteOperation(CoreAutomationRemoteOperation const&) noexcept = default;
        CoreAutomationRemoteOperation(CoreAutomationRemoteOperation&&) noexcept = default;
        CoreAutomationRemoteOperation& operator=(CoreAutomationRemoteOperation const&) & noexcept = default;
        CoreAutomationRemoteOperation& operator=(CoreAutomationRemoteOperation&&) & noexcept = default;
    };
    struct __declspec(empty_bases) CoreAutomationRemoteOperationContext : winrt::Windows::UI::UIAutomation::Core::ICoreAutomationRemoteOperationContext
    {
        CoreAutomationRemoteOperationContext(std::nullptr_t) noexcept {}
        CoreAutomationRemoteOperationContext(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::UIAutomation::Core::ICoreAutomationRemoteOperationContext(ptr, take_ownership_from_abi) {}
        CoreAutomationRemoteOperationContext(CoreAutomationRemoteOperationContext const&) noexcept = default;
        CoreAutomationRemoteOperationContext(CoreAutomationRemoteOperationContext&&) noexcept = default;
        CoreAutomationRemoteOperationContext& operator=(CoreAutomationRemoteOperationContext const&) & noexcept = default;
        CoreAutomationRemoteOperationContext& operator=(CoreAutomationRemoteOperationContext&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteAutomationClientSession : winrt::Windows::UI::UIAutomation::Core::IRemoteAutomationClientSession
    {
        RemoteAutomationClientSession(std::nullptr_t) noexcept {}
        RemoteAutomationClientSession(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::UIAutomation::Core::IRemoteAutomationClientSession(ptr, take_ownership_from_abi) {}
        explicit RemoteAutomationClientSession(param::hstring const& name);
        RemoteAutomationClientSession(param::hstring const& name, winrt::guid const& sessionId);
        RemoteAutomationClientSession(RemoteAutomationClientSession const&) noexcept = default;
        RemoteAutomationClientSession(RemoteAutomationClientSession&&) noexcept = default;
        RemoteAutomationClientSession& operator=(RemoteAutomationClientSession const&) & noexcept = default;
        RemoteAutomationClientSession& operator=(RemoteAutomationClientSession&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteAutomationConnectionRequestedEventArgs : winrt::Windows::UI::UIAutomation::Core::IRemoteAutomationConnectionRequestedEventArgs
    {
        RemoteAutomationConnectionRequestedEventArgs(std::nullptr_t) noexcept {}
        RemoteAutomationConnectionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::UIAutomation::Core::IRemoteAutomationConnectionRequestedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteAutomationConnectionRequestedEventArgs(RemoteAutomationConnectionRequestedEventArgs const&) noexcept = default;
        RemoteAutomationConnectionRequestedEventArgs(RemoteAutomationConnectionRequestedEventArgs&&) noexcept = default;
        RemoteAutomationConnectionRequestedEventArgs& operator=(RemoteAutomationConnectionRequestedEventArgs const&) & noexcept = default;
        RemoteAutomationConnectionRequestedEventArgs& operator=(RemoteAutomationConnectionRequestedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) RemoteAutomationDisconnectedEventArgs : winrt::Windows::UI::UIAutomation::Core::IRemoteAutomationDisconnectedEventArgs
    {
        RemoteAutomationDisconnectedEventArgs(std::nullptr_t) noexcept {}
        RemoteAutomationDisconnectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::UIAutomation::Core::IRemoteAutomationDisconnectedEventArgs(ptr, take_ownership_from_abi) {}
        RemoteAutomationDisconnectedEventArgs(RemoteAutomationDisconnectedEventArgs const&) noexcept = default;
        RemoteAutomationDisconnectedEventArgs(RemoteAutomationDisconnectedEventArgs&&) noexcept = default;
        RemoteAutomationDisconnectedEventArgs& operator=(RemoteAutomationDisconnectedEventArgs const&) & noexcept = default;
        RemoteAutomationDisconnectedEventArgs& operator=(RemoteAutomationDisconnectedEventArgs&&) & noexcept = default;
    };
    struct RemoteAutomationServer
    {
        RemoteAutomationServer() = delete;
        static auto ReportSession(winrt::guid const& sessionId);
    };
    struct __declspec(empty_bases) RemoteAutomationWindow : winrt::Windows::UI::UIAutomation::Core::IRemoteAutomationWindow
    {
        RemoteAutomationWindow(std::nullptr_t) noexcept {}
        RemoteAutomationWindow(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::UIAutomation::Core::IRemoteAutomationWindow(ptr, take_ownership_from_abi) {}
        RemoteAutomationWindow(RemoteAutomationWindow const&) noexcept = default;
        RemoteAutomationWindow(RemoteAutomationWindow&&) noexcept = default;
        RemoteAutomationWindow& operator=(RemoteAutomationWindow const&) & noexcept = default;
        RemoteAutomationWindow& operator=(RemoteAutomationWindow&&) & noexcept = default;
    };
}
#endif
