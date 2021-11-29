// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Phone_Devices_Power_H
#define WINRT_Windows_Phone_Devices_Power_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.210505.3"), "Mismatched C++/WinRT headers.");
#define CPPWINRT_VERSION "2.0.210505.3"
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.Phone.Devices.Power.2.h"
namespace winrt::impl
{
    template <typename D> WINRT_IMPL_AUTO(int32_t) consume_Windows_Phone_Devices_Power_IBattery<D>::RemainingChargePercent() const
    {
        int32_t value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Phone::Devices::Power::IBattery)->get_RemainingChargePercent(&value));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::TimeSpan) consume_Windows_Phone_Devices_Power_IBattery<D>::RemainingDischargeTime() const
    {
        winrt::Windows::Foundation::TimeSpan value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Phone::Devices::Power::IBattery)->get_RemainingDischargeTime(put_abi(value)));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::event_token) consume_Windows_Phone_Devices_Power_IBattery<D>::RemainingChargePercentChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& changeHandler) const
    {
        winrt::event_token token{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Phone::Devices::Power::IBattery)->add_RemainingChargePercentChanged(*(void**)(&changeHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Phone_Devices_Power_IBattery<D>::RemainingChargePercentChanged_revoker consume_Windows_Phone_Devices_Power_IBattery<D>::RemainingChargePercentChanged(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& changeHandler) const
    {
        return impl::make_event_revoker<D, RemainingChargePercentChanged_revoker>(this, RemainingChargePercentChanged(changeHandler));
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Windows_Phone_Devices_Power_IBattery<D>::RemainingChargePercentChanged(winrt::event_token const& token) const noexcept
    {
        WINRT_VERIFY_(0, WINRT_IMPL_SHIM(winrt::Windows::Phone::Devices::Power::IBattery)->remove_RemainingChargePercentChanged(impl::bind_in(token)));
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Phone::Devices::Power::Battery) consume_Windows_Phone_Devices_Power_IBatteryStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Windows::Phone::Devices::Power::IBatteryStatics)->GetDefault(&result));
        return winrt::Windows::Phone::Devices::Power::Battery{ result, take_ownership_from_abi };
    }
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::Phone::Devices::Power::IBattery> : produce_base<D, winrt::Windows::Phone::Devices::Power::IBattery>
    {
        int32_t __stdcall get_RemainingChargePercent(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RemainingChargePercent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemainingDischargeTime(int64_t* value) noexcept final try
        {
            zero_abi<winrt::Windows::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::Foundation::TimeSpan>(this->shim().RemainingDischargeTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RemainingChargePercentChanged(void* changeHandler, winrt::event_token* token) noexcept final try
        {
            zero_abi<winrt::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<winrt::event_token>(this->shim().RemainingChargePercentChanged(*reinterpret_cast<winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const*>(&changeHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RemainingChargePercentChanged(winrt::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemainingChargePercentChanged(*reinterpret_cast<winrt::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Windows::Phone::Devices::Power::IBatteryStatics> : produce_base<D, winrt::Windows::Phone::Devices::Power::IBatteryStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::Phone::Devices::Power::Battery>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
WINRT_EXPORT namespace winrt::Windows::Phone::Devices::Power
{
    inline auto Battery::GetDefault()
    {
        return impl::call_factory_cast<winrt::Windows::Phone::Devices::Power::Battery(*)(IBatteryStatics const&), Battery, IBatteryStatics>([](IBatteryStatics const& f) { return f.GetDefault(); });
    }
}
namespace std
{
#ifndef WINRT_LEAN_AND_MEAN
    template<> struct hash<winrt::Windows::Phone::Devices::Power::IBattery> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Phone::Devices::Power::IBatteryStatics> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Windows::Phone::Devices::Power::Battery> : winrt::impl::hash_base {};
#endif
}
#endif
