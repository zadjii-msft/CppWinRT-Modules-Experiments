// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Devices_WiFiDirect_Services_2_H
#define WINRT_Windows_Devices_WiFiDirect_Services_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Storage.Streams.1.h"
#include "winrt/impl/Windows.Devices.WiFiDirect.Services.1.h"
WINRT_EXPORT namespace winrt::Windows::Devices::WiFiDirect::Services
{
    struct __declspec(empty_bases) WiFiDirectService : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectService
    {
        WiFiDirectService(std::nullptr_t) noexcept {}
        WiFiDirectService(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectService(ptr, take_ownership_from_abi) {}
        WiFiDirectService(WiFiDirectService const&) noexcept = default;
        WiFiDirectService(WiFiDirectService&&) noexcept = default;
        WiFiDirectService& operator=(WiFiDirectService const&) & noexcept = default;
        WiFiDirectService& operator=(WiFiDirectService&&) & noexcept = default;
        static auto GetSelector(param::hstring const& serviceName);
        static auto GetSelector(param::hstring const& serviceName, winrt::Windows::Storage::Streams::IBuffer const& serviceInfoFilter);
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) WiFiDirectServiceAdvertiser : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser
    {
        WiFiDirectServiceAdvertiser(std::nullptr_t) noexcept {}
        WiFiDirectServiceAdvertiser(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAdvertiser(ptr, take_ownership_from_abi) {}
        explicit WiFiDirectServiceAdvertiser(param::hstring const& serviceName);
        WiFiDirectServiceAdvertiser(WiFiDirectServiceAdvertiser const&) noexcept = default;
        WiFiDirectServiceAdvertiser(WiFiDirectServiceAdvertiser&&) noexcept = default;
        WiFiDirectServiceAdvertiser& operator=(WiFiDirectServiceAdvertiser const&) & noexcept = default;
        WiFiDirectServiceAdvertiser& operator=(WiFiDirectServiceAdvertiser&&) & noexcept = default;
    };
    struct __declspec(empty_bases) WiFiDirectServiceAutoAcceptSessionConnectedEventArgs : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs
    {
        WiFiDirectServiceAutoAcceptSessionConnectedEventArgs(std::nullptr_t) noexcept {}
        WiFiDirectServiceAutoAcceptSessionConnectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceAutoAcceptSessionConnectedEventArgs(ptr, take_ownership_from_abi) {}
        WiFiDirectServiceAutoAcceptSessionConnectedEventArgs(WiFiDirectServiceAutoAcceptSessionConnectedEventArgs const&) noexcept = default;
        WiFiDirectServiceAutoAcceptSessionConnectedEventArgs(WiFiDirectServiceAutoAcceptSessionConnectedEventArgs&&) noexcept = default;
        WiFiDirectServiceAutoAcceptSessionConnectedEventArgs& operator=(WiFiDirectServiceAutoAcceptSessionConnectedEventArgs const&) & noexcept = default;
        WiFiDirectServiceAutoAcceptSessionConnectedEventArgs& operator=(WiFiDirectServiceAutoAcceptSessionConnectedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) WiFiDirectServiceProvisioningInfo : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo
    {
        WiFiDirectServiceProvisioningInfo(std::nullptr_t) noexcept {}
        WiFiDirectServiceProvisioningInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceProvisioningInfo(ptr, take_ownership_from_abi) {}
        WiFiDirectServiceProvisioningInfo(WiFiDirectServiceProvisioningInfo const&) noexcept = default;
        WiFiDirectServiceProvisioningInfo(WiFiDirectServiceProvisioningInfo&&) noexcept = default;
        WiFiDirectServiceProvisioningInfo& operator=(WiFiDirectServiceProvisioningInfo const&) & noexcept = default;
        WiFiDirectServiceProvisioningInfo& operator=(WiFiDirectServiceProvisioningInfo&&) & noexcept = default;
    };
    struct __declspec(empty_bases) WiFiDirectServiceRemotePortAddedEventArgs : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs
    {
        WiFiDirectServiceRemotePortAddedEventArgs(std::nullptr_t) noexcept {}
        WiFiDirectServiceRemotePortAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceRemotePortAddedEventArgs(ptr, take_ownership_from_abi) {}
        WiFiDirectServiceRemotePortAddedEventArgs(WiFiDirectServiceRemotePortAddedEventArgs const&) noexcept = default;
        WiFiDirectServiceRemotePortAddedEventArgs(WiFiDirectServiceRemotePortAddedEventArgs&&) noexcept = default;
        WiFiDirectServiceRemotePortAddedEventArgs& operator=(WiFiDirectServiceRemotePortAddedEventArgs const&) & noexcept = default;
        WiFiDirectServiceRemotePortAddedEventArgs& operator=(WiFiDirectServiceRemotePortAddedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) WiFiDirectServiceSession : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession
    {
        WiFiDirectServiceSession(std::nullptr_t) noexcept {}
        WiFiDirectServiceSession(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSession(ptr, take_ownership_from_abi) {}
        WiFiDirectServiceSession(WiFiDirectServiceSession const&) noexcept = default;
        WiFiDirectServiceSession(WiFiDirectServiceSession&&) noexcept = default;
        WiFiDirectServiceSession& operator=(WiFiDirectServiceSession const&) & noexcept = default;
        WiFiDirectServiceSession& operator=(WiFiDirectServiceSession&&) & noexcept = default;
    };
    struct __declspec(empty_bases) WiFiDirectServiceSessionDeferredEventArgs : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs
    {
        WiFiDirectServiceSessionDeferredEventArgs(std::nullptr_t) noexcept {}
        WiFiDirectServiceSessionDeferredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionDeferredEventArgs(ptr, take_ownership_from_abi) {}
        WiFiDirectServiceSessionDeferredEventArgs(WiFiDirectServiceSessionDeferredEventArgs const&) noexcept = default;
        WiFiDirectServiceSessionDeferredEventArgs(WiFiDirectServiceSessionDeferredEventArgs&&) noexcept = default;
        WiFiDirectServiceSessionDeferredEventArgs& operator=(WiFiDirectServiceSessionDeferredEventArgs const&) & noexcept = default;
        WiFiDirectServiceSessionDeferredEventArgs& operator=(WiFiDirectServiceSessionDeferredEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) WiFiDirectServiceSessionRequest : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest
    {
        WiFiDirectServiceSessionRequest(std::nullptr_t) noexcept {}
        WiFiDirectServiceSessionRequest(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequest(ptr, take_ownership_from_abi) {}
        WiFiDirectServiceSessionRequest(WiFiDirectServiceSessionRequest const&) noexcept = default;
        WiFiDirectServiceSessionRequest(WiFiDirectServiceSessionRequest&&) noexcept = default;
        WiFiDirectServiceSessionRequest& operator=(WiFiDirectServiceSessionRequest const&) & noexcept = default;
        WiFiDirectServiceSessionRequest& operator=(WiFiDirectServiceSessionRequest&&) & noexcept = default;
    };
    struct __declspec(empty_bases) WiFiDirectServiceSessionRequestedEventArgs : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs
    {
        WiFiDirectServiceSessionRequestedEventArgs(std::nullptr_t) noexcept {}
        WiFiDirectServiceSessionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Devices::WiFiDirect::Services::IWiFiDirectServiceSessionRequestedEventArgs(ptr, take_ownership_from_abi) {}
        WiFiDirectServiceSessionRequestedEventArgs(WiFiDirectServiceSessionRequestedEventArgs const&) noexcept = default;
        WiFiDirectServiceSessionRequestedEventArgs(WiFiDirectServiceSessionRequestedEventArgs&&) noexcept = default;
        WiFiDirectServiceSessionRequestedEventArgs& operator=(WiFiDirectServiceSessionRequestedEventArgs const&) & noexcept = default;
        WiFiDirectServiceSessionRequestedEventArgs& operator=(WiFiDirectServiceSessionRequestedEventArgs&&) & noexcept = default;
    };
}
#endif
