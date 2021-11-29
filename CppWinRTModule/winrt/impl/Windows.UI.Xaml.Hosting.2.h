// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_UI_Xaml_Hosting_2_H
#define WINRT_Windows_UI_Xaml_Hosting_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.UI.Composition.1.h"
#include "winrt/impl/Windows.UI.WindowManagement.1.h"
#include "winrt/impl/Windows.UI.Xaml.1.h"
#include "winrt/impl/Windows.UI.Xaml.Controls.1.h"
#include "winrt/impl/Windows.UI.Xaml.Controls.Primitives.1.h"
#include "winrt/impl/Windows.UI.Xaml.Hosting.1.h"
WINRT_EXPORT namespace winrt::Windows::UI::Xaml::Hosting
{
    struct __declspec(empty_bases) DesignerAppExitedEventArgs : winrt::Windows::UI::Xaml::Hosting::IDesignerAppExitedEventArgs
    {
        DesignerAppExitedEventArgs(std::nullptr_t) noexcept {}
        DesignerAppExitedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IDesignerAppExitedEventArgs(ptr, take_ownership_from_abi) {}
        DesignerAppExitedEventArgs(DesignerAppExitedEventArgs const&) noexcept = default;
        DesignerAppExitedEventArgs(DesignerAppExitedEventArgs&&) noexcept = default;
        DesignerAppExitedEventArgs& operator=(DesignerAppExitedEventArgs const&) & noexcept = default;
        DesignerAppExitedEventArgs& operator=(DesignerAppExitedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DesignerAppManager : winrt::Windows::UI::Xaml::Hosting::IDesignerAppManager,
        impl::require<DesignerAppManager, winrt::Windows::Foundation::IClosable>
    {
        DesignerAppManager(std::nullptr_t) noexcept {}
        DesignerAppManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IDesignerAppManager(ptr, take_ownership_from_abi) {}
        explicit DesignerAppManager(param::hstring const& appUserModelId);
        DesignerAppManager(DesignerAppManager const&) noexcept = default;
        DesignerAppManager(DesignerAppManager&&) noexcept = default;
        DesignerAppManager& operator=(DesignerAppManager const&) & noexcept = default;
        DesignerAppManager& operator=(DesignerAppManager&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DesignerAppView : winrt::Windows::UI::Xaml::Hosting::IDesignerAppView,
        impl::require<DesignerAppView, winrt::Windows::Foundation::IClosable>
    {
        DesignerAppView(std::nullptr_t) noexcept {}
        DesignerAppView(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IDesignerAppView(ptr, take_ownership_from_abi) {}
        DesignerAppView(DesignerAppView const&) noexcept = default;
        DesignerAppView(DesignerAppView&&) noexcept = default;
        DesignerAppView& operator=(DesignerAppView const&) & noexcept = default;
        DesignerAppView& operator=(DesignerAppView&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DesktopWindowXamlSource : winrt::Windows::UI::Xaml::Hosting::IDesktopWindowXamlSource,
        impl::require<DesktopWindowXamlSource, winrt::Windows::Foundation::IClosable, winrt::Windows::UI::Composition::ICompositionSupportsSystemBackdrop>
    {
        DesktopWindowXamlSource(std::nullptr_t) noexcept {}
        DesktopWindowXamlSource(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IDesktopWindowXamlSource(ptr, take_ownership_from_abi) {}
        DesktopWindowXamlSource();
        DesktopWindowXamlSource(DesktopWindowXamlSource const&) noexcept = default;
        DesktopWindowXamlSource(DesktopWindowXamlSource&&) noexcept = default;
        DesktopWindowXamlSource& operator=(DesktopWindowXamlSource const&) & noexcept = default;
        DesktopWindowXamlSource& operator=(DesktopWindowXamlSource&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DesktopWindowXamlSourceGotFocusEventArgs : winrt::Windows::UI::Xaml::Hosting::IDesktopWindowXamlSourceGotFocusEventArgs
    {
        DesktopWindowXamlSourceGotFocusEventArgs(std::nullptr_t) noexcept {}
        DesktopWindowXamlSourceGotFocusEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IDesktopWindowXamlSourceGotFocusEventArgs(ptr, take_ownership_from_abi) {}
        DesktopWindowXamlSourceGotFocusEventArgs(DesktopWindowXamlSourceGotFocusEventArgs const&) noexcept = default;
        DesktopWindowXamlSourceGotFocusEventArgs(DesktopWindowXamlSourceGotFocusEventArgs&&) noexcept = default;
        DesktopWindowXamlSourceGotFocusEventArgs& operator=(DesktopWindowXamlSourceGotFocusEventArgs const&) & noexcept = default;
        DesktopWindowXamlSourceGotFocusEventArgs& operator=(DesktopWindowXamlSourceGotFocusEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) DesktopWindowXamlSourceTakeFocusRequestedEventArgs : winrt::Windows::UI::Xaml::Hosting::IDesktopWindowXamlSourceTakeFocusRequestedEventArgs
    {
        DesktopWindowXamlSourceTakeFocusRequestedEventArgs(std::nullptr_t) noexcept {}
        DesktopWindowXamlSourceTakeFocusRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IDesktopWindowXamlSourceTakeFocusRequestedEventArgs(ptr, take_ownership_from_abi) {}
        DesktopWindowXamlSourceTakeFocusRequestedEventArgs(DesktopWindowXamlSourceTakeFocusRequestedEventArgs const&) noexcept = default;
        DesktopWindowXamlSourceTakeFocusRequestedEventArgs(DesktopWindowXamlSourceTakeFocusRequestedEventArgs&&) noexcept = default;
        DesktopWindowXamlSourceTakeFocusRequestedEventArgs& operator=(DesktopWindowXamlSourceTakeFocusRequestedEventArgs const&) & noexcept = default;
        DesktopWindowXamlSourceTakeFocusRequestedEventArgs& operator=(DesktopWindowXamlSourceTakeFocusRequestedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ElementCompositionPreview : winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview
    {
        ElementCompositionPreview(std::nullptr_t) noexcept {}
        ElementCompositionPreview(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IElementCompositionPreview(ptr, take_ownership_from_abi) {}
        ElementCompositionPreview(ElementCompositionPreview const&) noexcept = default;
        ElementCompositionPreview(ElementCompositionPreview&&) noexcept = default;
        ElementCompositionPreview& operator=(ElementCompositionPreview const&) & noexcept = default;
        ElementCompositionPreview& operator=(ElementCompositionPreview&&) & noexcept = default;
        static auto GetElementVisual(winrt::Windows::UI::Xaml::UIElement const& element);
        static auto GetElementChildVisual(winrt::Windows::UI::Xaml::UIElement const& element);
        static auto SetElementChildVisual(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::Visual const& visual);
        static auto GetScrollViewerManipulationPropertySet(winrt::Windows::UI::Xaml::Controls::ScrollViewer const& scrollViewer);
        static auto SetImplicitShowAnimation(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::ICompositionAnimationBase const& animation);
        static auto SetImplicitHideAnimation(winrt::Windows::UI::Xaml::UIElement const& element, winrt::Windows::UI::Composition::ICompositionAnimationBase const& animation);
        static auto SetIsTranslationEnabled(winrt::Windows::UI::Xaml::UIElement const& element, bool value);
        static auto GetPointerPositionPropertySet(winrt::Windows::UI::Xaml::UIElement const& targetElement);
        static auto SetAppWindowContent(winrt::Windows::UI::WindowManagement::AppWindow const& appWindow, winrt::Windows::UI::Xaml::UIElement const& xamlContent);
        static auto GetAppWindowContent(winrt::Windows::UI::WindowManagement::AppWindow const& appWindow);
    };
    struct __declspec(empty_bases) WindowsXamlManager : winrt::Windows::UI::Xaml::Hosting::IWindowsXamlManager,
        impl::require<WindowsXamlManager, winrt::Windows::Foundation::IClosable>
    {
        WindowsXamlManager(std::nullptr_t) noexcept {}
        WindowsXamlManager(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IWindowsXamlManager(ptr, take_ownership_from_abi) {}
        WindowsXamlManager(WindowsXamlManager const&) noexcept = default;
        WindowsXamlManager(WindowsXamlManager&&) noexcept = default;
        WindowsXamlManager& operator=(WindowsXamlManager const&) & noexcept = default;
        WindowsXamlManager& operator=(WindowsXamlManager&&) & noexcept = default;
        static auto InitializeForCurrentThread();
    };
    struct __declspec(empty_bases) XamlSourceFocusNavigationRequest : winrt::Windows::UI::Xaml::Hosting::IXamlSourceFocusNavigationRequest
    {
        XamlSourceFocusNavigationRequest(std::nullptr_t) noexcept {}
        XamlSourceFocusNavigationRequest(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IXamlSourceFocusNavigationRequest(ptr, take_ownership_from_abi) {}
        explicit XamlSourceFocusNavigationRequest(winrt::Windows::UI::Xaml::Hosting::XamlSourceFocusNavigationReason const& reason);
        XamlSourceFocusNavigationRequest(winrt::Windows::UI::Xaml::Hosting::XamlSourceFocusNavigationReason const& reason, winrt::Windows::Foundation::Rect const& hintRect);
        XamlSourceFocusNavigationRequest(winrt::Windows::UI::Xaml::Hosting::XamlSourceFocusNavigationReason const& reason, winrt::Windows::Foundation::Rect const& hintRect, winrt::guid const& correlationId);
        XamlSourceFocusNavigationRequest(XamlSourceFocusNavigationRequest const&) noexcept = default;
        XamlSourceFocusNavigationRequest(XamlSourceFocusNavigationRequest&&) noexcept = default;
        XamlSourceFocusNavigationRequest& operator=(XamlSourceFocusNavigationRequest const&) & noexcept = default;
        XamlSourceFocusNavigationRequest& operator=(XamlSourceFocusNavigationRequest&&) & noexcept = default;
    };
    struct __declspec(empty_bases) XamlSourceFocusNavigationResult : winrt::Windows::UI::Xaml::Hosting::IXamlSourceFocusNavigationResult
    {
        XamlSourceFocusNavigationResult(std::nullptr_t) noexcept {}
        XamlSourceFocusNavigationResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IXamlSourceFocusNavigationResult(ptr, take_ownership_from_abi) {}
        explicit XamlSourceFocusNavigationResult(bool focusMoved);
        XamlSourceFocusNavigationResult(XamlSourceFocusNavigationResult const&) noexcept = default;
        XamlSourceFocusNavigationResult(XamlSourceFocusNavigationResult&&) noexcept = default;
        XamlSourceFocusNavigationResult& operator=(XamlSourceFocusNavigationResult const&) & noexcept = default;
        XamlSourceFocusNavigationResult& operator=(XamlSourceFocusNavigationResult&&) & noexcept = default;
    };
    struct __declspec(empty_bases) XamlUIPresenter : winrt::Windows::UI::Xaml::Hosting::IXamlUIPresenter
    {
        XamlUIPresenter(std::nullptr_t) noexcept {}
        XamlUIPresenter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::UI::Xaml::Hosting::IXamlUIPresenter(ptr, take_ownership_from_abi) {}
        XamlUIPresenter(XamlUIPresenter const&) noexcept = default;
        XamlUIPresenter(XamlUIPresenter&&) noexcept = default;
        XamlUIPresenter& operator=(XamlUIPresenter const&) & noexcept = default;
        XamlUIPresenter& operator=(XamlUIPresenter&&) & noexcept = default;
        [[nodiscard]] static auto CompleteTimelinesAutomatically();
        static auto CompleteTimelinesAutomatically(bool value);
        static auto SetHost(winrt::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost const& host);
        static auto NotifyWindowSizeChanged();
        static auto GetFlyoutPlacementTargetInfo(winrt::Windows::UI::Xaml::FrameworkElement const& placementTarget, winrt::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode const& preferredPlacement, winrt::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode& targetPreferredPlacement, bool& allowFallbacks);
        static auto GetFlyoutPlacement(winrt::Windows::Foundation::Rect const& placementTargetBounds, winrt::Windows::Foundation::Size const& controlSize, winrt::Windows::Foundation::Size const& minControlSize, winrt::Windows::Foundation::Rect const& containerRect, winrt::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode const& targetPreferredPlacement, bool allowFallbacks, winrt::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode& chosenPlacement);
    };
}
#endif
