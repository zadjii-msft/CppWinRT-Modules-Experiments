// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Devices_Gpio_1_H
#define WINRT_Windows_Devices_Gpio_1_H
#include "winrt/impl/Windows.Foundation.0.h"
#include "winrt/impl/Windows.Devices.Gpio.0.h"
WINRT_EXPORT namespace winrt::Windows::Devices::Gpio
{
    struct __declspec(empty_bases) IGpioChangeCounter :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IGpioChangeCounter>,
        impl::require<winrt::Windows::Devices::Gpio::IGpioChangeCounter, winrt::Windows::Foundation::IClosable>
    {
        IGpioChangeCounter(std::nullptr_t = nullptr) noexcept {}
        IGpioChangeCounter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IGpioChangeCounter(IGpioChangeCounter const&) noexcept = default;
        IGpioChangeCounter(IGpioChangeCounter&&) noexcept = default;
        IGpioChangeCounter& operator=(IGpioChangeCounter const&) & noexcept = default;
        IGpioChangeCounter& operator=(IGpioChangeCounter&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IGpioChangeCounterFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IGpioChangeCounterFactory>
    {
        IGpioChangeCounterFactory(std::nullptr_t = nullptr) noexcept {}
        IGpioChangeCounterFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IGpioChangeCounterFactory(IGpioChangeCounterFactory const&) noexcept = default;
        IGpioChangeCounterFactory(IGpioChangeCounterFactory&&) noexcept = default;
        IGpioChangeCounterFactory& operator=(IGpioChangeCounterFactory const&) & noexcept = default;
        IGpioChangeCounterFactory& operator=(IGpioChangeCounterFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IGpioChangeReader :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IGpioChangeReader>,
        impl::require<winrt::Windows::Devices::Gpio::IGpioChangeReader, winrt::Windows::Foundation::IClosable>
    {
        IGpioChangeReader(std::nullptr_t = nullptr) noexcept {}
        IGpioChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IGpioChangeReader(IGpioChangeReader const&) noexcept = default;
        IGpioChangeReader(IGpioChangeReader&&) noexcept = default;
        IGpioChangeReader& operator=(IGpioChangeReader const&) & noexcept = default;
        IGpioChangeReader& operator=(IGpioChangeReader&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IGpioChangeReaderFactory :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IGpioChangeReaderFactory>
    {
        IGpioChangeReaderFactory(std::nullptr_t = nullptr) noexcept {}
        IGpioChangeReaderFactory(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IGpioChangeReaderFactory(IGpioChangeReaderFactory const&) noexcept = default;
        IGpioChangeReaderFactory(IGpioChangeReaderFactory&&) noexcept = default;
        IGpioChangeReaderFactory& operator=(IGpioChangeReaderFactory const&) & noexcept = default;
        IGpioChangeReaderFactory& operator=(IGpioChangeReaderFactory&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IGpioController :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IGpioController>
    {
        IGpioController(std::nullptr_t = nullptr) noexcept {}
        IGpioController(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IGpioController(IGpioController const&) noexcept = default;
        IGpioController(IGpioController&&) noexcept = default;
        IGpioController& operator=(IGpioController const&) & noexcept = default;
        IGpioController& operator=(IGpioController&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IGpioControllerStatics :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IGpioControllerStatics>
    {
        IGpioControllerStatics(std::nullptr_t = nullptr) noexcept {}
        IGpioControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IGpioControllerStatics(IGpioControllerStatics const&) noexcept = default;
        IGpioControllerStatics(IGpioControllerStatics&&) noexcept = default;
        IGpioControllerStatics& operator=(IGpioControllerStatics const&) & noexcept = default;
        IGpioControllerStatics& operator=(IGpioControllerStatics&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IGpioControllerStatics2 :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IGpioControllerStatics2>
    {
        IGpioControllerStatics2(std::nullptr_t = nullptr) noexcept {}
        IGpioControllerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IGpioControllerStatics2(IGpioControllerStatics2 const&) noexcept = default;
        IGpioControllerStatics2(IGpioControllerStatics2&&) noexcept = default;
        IGpioControllerStatics2& operator=(IGpioControllerStatics2 const&) & noexcept = default;
        IGpioControllerStatics2& operator=(IGpioControllerStatics2&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IGpioPin :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IGpioPin>,
        impl::require<winrt::Windows::Devices::Gpio::IGpioPin, winrt::Windows::Foundation::IClosable>
    {
        IGpioPin(std::nullptr_t = nullptr) noexcept {}
        IGpioPin(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IGpioPin(IGpioPin const&) noexcept = default;
        IGpioPin(IGpioPin&&) noexcept = default;
        IGpioPin& operator=(IGpioPin const&) & noexcept = default;
        IGpioPin& operator=(IGpioPin&&) & noexcept = default;
    };
    struct __declspec(empty_bases) IGpioPinValueChangedEventArgs :
        winrt::Windows::Foundation::IInspectable,
        impl::consume_t<IGpioPinValueChangedEventArgs>
    {
        IGpioPinValueChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGpioPinValueChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        IGpioPinValueChangedEventArgs(IGpioPinValueChangedEventArgs const&) noexcept = default;
        IGpioPinValueChangedEventArgs(IGpioPinValueChangedEventArgs&&) noexcept = default;
        IGpioPinValueChangedEventArgs& operator=(IGpioPinValueChangedEventArgs const&) & noexcept = default;
        IGpioPinValueChangedEventArgs& operator=(IGpioPinValueChangedEventArgs&&) & noexcept = default;
    };
}
#endif
