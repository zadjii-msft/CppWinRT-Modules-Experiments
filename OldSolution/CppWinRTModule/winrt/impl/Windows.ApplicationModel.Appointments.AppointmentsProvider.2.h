// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_ApplicationModel_Appointments_AppointmentsProvider_2_H
#define WINRT_Windows_ApplicationModel_Appointments_AppointmentsProvider_2_H
#include "winrt/impl/Windows.ApplicationModel.Appointments.AppointmentsProvider.1.h"
WINRT_EXPORT namespace winrt::Windows::ApplicationModel::Appointments::AppointmentsProvider
{
    struct __declspec(empty_bases) AddAppointmentOperation : winrt::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation
    {
        AddAppointmentOperation(std::nullptr_t) noexcept {}
        AddAppointmentOperation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation(ptr, take_ownership_from_abi) {}
        AddAppointmentOperation(AddAppointmentOperation const&) noexcept = default;
        AddAppointmentOperation(AddAppointmentOperation&&) noexcept = default;
        AddAppointmentOperation& operator=(AddAppointmentOperation const&) & noexcept = default;
        AddAppointmentOperation& operator=(AddAppointmentOperation&&) & noexcept = default;
    };
    struct AppointmentsProviderLaunchActionVerbs
    {
        AppointmentsProviderLaunchActionVerbs() = delete;
        [[nodiscard]] static auto AddAppointment();
        [[nodiscard]] static auto ReplaceAppointment();
        [[nodiscard]] static auto RemoveAppointment();
        [[nodiscard]] static auto ShowTimeFrame();
        [[nodiscard]] static auto ShowAppointmentDetails();
    };
    struct __declspec(empty_bases) RemoveAppointmentOperation : winrt::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation
    {
        RemoveAppointmentOperation(std::nullptr_t) noexcept {}
        RemoveAppointmentOperation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation(ptr, take_ownership_from_abi) {}
        RemoveAppointmentOperation(RemoveAppointmentOperation const&) noexcept = default;
        RemoveAppointmentOperation(RemoveAppointmentOperation&&) noexcept = default;
        RemoveAppointmentOperation& operator=(RemoveAppointmentOperation const&) & noexcept = default;
        RemoveAppointmentOperation& operator=(RemoveAppointmentOperation&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ReplaceAppointmentOperation : winrt::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation
    {
        ReplaceAppointmentOperation(std::nullptr_t) noexcept {}
        ReplaceAppointmentOperation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation(ptr, take_ownership_from_abi) {}
        ReplaceAppointmentOperation(ReplaceAppointmentOperation const&) noexcept = default;
        ReplaceAppointmentOperation(ReplaceAppointmentOperation&&) noexcept = default;
        ReplaceAppointmentOperation& operator=(ReplaceAppointmentOperation const&) & noexcept = default;
        ReplaceAppointmentOperation& operator=(ReplaceAppointmentOperation&&) & noexcept = default;
    };
}
#endif