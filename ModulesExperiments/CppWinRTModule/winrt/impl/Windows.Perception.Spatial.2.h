// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Perception_Spatial_2_H
#define WINRT_Windows_Perception_Spatial_2_H
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Windows.Foundation.Collections.2.h"
#include "winrt/impl/Windows.Foundation.Numerics.2.h"
#include "winrt/impl/Windows.Storage.Streams.2.h"
#include "winrt/impl/Windows.System.RemoteSystems.2.h"
#include "winrt/impl/Windows.Perception.Spatial.1.h"
WINRT_EXPORT namespace winrt::Windows::Perception::Spatial
{
    struct SpatialBoundingBox
    {
        winrt::Windows::Foundation::Numerics::float3 Center;
        winrt::Windows::Foundation::Numerics::float3 Extents;
    };
    inline bool operator==(SpatialBoundingBox const& left, SpatialBoundingBox const& right) noexcept
    {
        return left.Center == right.Center && left.Extents == right.Extents;
    }
    inline bool operator!=(SpatialBoundingBox const& left, SpatialBoundingBox const& right) noexcept
    {
        return !(left == right);
    }
    struct SpatialBoundingFrustum
    {
        winrt::Windows::Foundation::Numerics::plane Near;
        winrt::Windows::Foundation::Numerics::plane Far;
        winrt::Windows::Foundation::Numerics::plane Right;
        winrt::Windows::Foundation::Numerics::plane Left;
        winrt::Windows::Foundation::Numerics::plane Top;
        winrt::Windows::Foundation::Numerics::plane Bottom;
    };
    inline bool operator==(SpatialBoundingFrustum const& left, SpatialBoundingFrustum const& right) noexcept
    {
        return left.Near == right.Near && left.Far == right.Far && left.Right == right.Right && left.Left == right.Left && left.Top == right.Top && left.Bottom == right.Bottom;
    }
    inline bool operator!=(SpatialBoundingFrustum const& left, SpatialBoundingFrustum const& right) noexcept
    {
        return !(left == right);
    }
    struct SpatialBoundingOrientedBox
    {
        winrt::Windows::Foundation::Numerics::float3 Center;
        winrt::Windows::Foundation::Numerics::float3 Extents;
        winrt::Windows::Foundation::Numerics::quaternion Orientation;
    };
    inline bool operator==(SpatialBoundingOrientedBox const& left, SpatialBoundingOrientedBox const& right) noexcept
    {
        return left.Center == right.Center && left.Extents == right.Extents && left.Orientation == right.Orientation;
    }
    inline bool operator!=(SpatialBoundingOrientedBox const& left, SpatialBoundingOrientedBox const& right) noexcept
    {
        return !(left == right);
    }
    struct SpatialBoundingSphere
    {
        winrt::Windows::Foundation::Numerics::float3 Center;
        float Radius;
    };
    inline bool operator==(SpatialBoundingSphere const& left, SpatialBoundingSphere const& right) noexcept
    {
        return left.Center == right.Center && left.Radius == right.Radius;
    }
    inline bool operator!=(SpatialBoundingSphere const& left, SpatialBoundingSphere const& right) noexcept
    {
        return !(left == right);
    }
    struct SpatialRay
    {
        winrt::Windows::Foundation::Numerics::float3 Origin;
        winrt::Windows::Foundation::Numerics::float3 Direction;
    };
    inline bool operator==(SpatialRay const& left, SpatialRay const& right) noexcept
    {
        return left.Origin == right.Origin && left.Direction == right.Direction;
    }
    inline bool operator!=(SpatialRay const& left, SpatialRay const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) SpatialAnchor : winrt::Windows::Perception::Spatial::ISpatialAnchor,
        impl::require<SpatialAnchor, winrt::Windows::Perception::Spatial::ISpatialAnchor2>
    {
        SpatialAnchor(std::nullptr_t) noexcept {}
        SpatialAnchor(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialAnchor(ptr, take_ownership_from_abi) {}
        SpatialAnchor(SpatialAnchor const&) noexcept = default;
        SpatialAnchor(SpatialAnchor&&) noexcept = default;
        SpatialAnchor& operator=(SpatialAnchor const&) & noexcept = default;
        SpatialAnchor& operator=(SpatialAnchor&&) & noexcept = default;
        static auto TryCreateRelativeTo(winrt::Windows::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem);
        static auto TryCreateRelativeTo(winrt::Windows::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, winrt::Windows::Foundation::Numerics::float3 const& position);
        static auto TryCreateRelativeTo(winrt::Windows::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, winrt::Windows::Foundation::Numerics::float3 const& position, winrt::Windows::Foundation::Numerics::quaternion const& orientation);
    };
    struct __declspec(empty_bases) SpatialAnchorExportSufficiency : winrt::Windows::Perception::Spatial::ISpatialAnchorExportSufficiency
    {
        SpatialAnchorExportSufficiency(std::nullptr_t) noexcept {}
        SpatialAnchorExportSufficiency(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialAnchorExportSufficiency(ptr, take_ownership_from_abi) {}
        SpatialAnchorExportSufficiency(SpatialAnchorExportSufficiency const&) noexcept = default;
        SpatialAnchorExportSufficiency(SpatialAnchorExportSufficiency&&) noexcept = default;
        SpatialAnchorExportSufficiency& operator=(SpatialAnchorExportSufficiency const&) & noexcept = default;
        SpatialAnchorExportSufficiency& operator=(SpatialAnchorExportSufficiency&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialAnchorExporter : winrt::Windows::Perception::Spatial::ISpatialAnchorExporter
    {
        SpatialAnchorExporter(std::nullptr_t) noexcept {}
        SpatialAnchorExporter(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialAnchorExporter(ptr, take_ownership_from_abi) {}
        SpatialAnchorExporter(SpatialAnchorExporter const&) noexcept = default;
        SpatialAnchorExporter(SpatialAnchorExporter&&) noexcept = default;
        SpatialAnchorExporter& operator=(SpatialAnchorExporter const&) & noexcept = default;
        SpatialAnchorExporter& operator=(SpatialAnchorExporter&&) & noexcept = default;
        static auto GetDefault();
        static auto RequestAccessAsync();
    };
    struct SpatialAnchorManager
    {
        SpatialAnchorManager() = delete;
        static auto RequestStoreAsync();
    };
    struct __declspec(empty_bases) SpatialAnchorRawCoordinateSystemAdjustedEventArgs : winrt::Windows::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs
    {
        SpatialAnchorRawCoordinateSystemAdjustedEventArgs(std::nullptr_t) noexcept {}
        SpatialAnchorRawCoordinateSystemAdjustedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialAnchorRawCoordinateSystemAdjustedEventArgs(ptr, take_ownership_from_abi) {}
        SpatialAnchorRawCoordinateSystemAdjustedEventArgs(SpatialAnchorRawCoordinateSystemAdjustedEventArgs const&) noexcept = default;
        SpatialAnchorRawCoordinateSystemAdjustedEventArgs(SpatialAnchorRawCoordinateSystemAdjustedEventArgs&&) noexcept = default;
        SpatialAnchorRawCoordinateSystemAdjustedEventArgs& operator=(SpatialAnchorRawCoordinateSystemAdjustedEventArgs const&) & noexcept = default;
        SpatialAnchorRawCoordinateSystemAdjustedEventArgs& operator=(SpatialAnchorRawCoordinateSystemAdjustedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialAnchorStore : winrt::Windows::Perception::Spatial::ISpatialAnchorStore
    {
        SpatialAnchorStore(std::nullptr_t) noexcept {}
        SpatialAnchorStore(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialAnchorStore(ptr, take_ownership_from_abi) {}
        SpatialAnchorStore(SpatialAnchorStore const&) noexcept = default;
        SpatialAnchorStore(SpatialAnchorStore&&) noexcept = default;
        SpatialAnchorStore& operator=(SpatialAnchorStore const&) & noexcept = default;
        SpatialAnchorStore& operator=(SpatialAnchorStore&&) & noexcept = default;
    };
    struct SpatialAnchorTransferManager
    {
        SpatialAnchorTransferManager() = delete;
        static auto TryImportAnchorsAsync(winrt::Windows::Storage::Streams::IInputStream const& stream);
        static auto TryExportAnchorsAsync(param::async_iterable<winrt::Windows::Foundation::Collections::IKeyValuePair<hstring, winrt::Windows::Perception::Spatial::SpatialAnchor>> const& anchors, winrt::Windows::Storage::Streams::IOutputStream const& stream);
        static auto RequestAccessAsync();
    };
    struct __declspec(empty_bases) SpatialBoundingVolume : winrt::Windows::Perception::Spatial::ISpatialBoundingVolume
    {
        SpatialBoundingVolume(std::nullptr_t) noexcept {}
        SpatialBoundingVolume(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialBoundingVolume(ptr, take_ownership_from_abi) {}
        SpatialBoundingVolume(SpatialBoundingVolume const&) noexcept = default;
        SpatialBoundingVolume(SpatialBoundingVolume&&) noexcept = default;
        SpatialBoundingVolume& operator=(SpatialBoundingVolume const&) & noexcept = default;
        SpatialBoundingVolume& operator=(SpatialBoundingVolume&&) & noexcept = default;
        static auto FromBox(winrt::Windows::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, winrt::Windows::Perception::Spatial::SpatialBoundingBox const& box);
        static auto FromOrientedBox(winrt::Windows::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, winrt::Windows::Perception::Spatial::SpatialBoundingOrientedBox const& box);
        static auto FromSphere(winrt::Windows::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, winrt::Windows::Perception::Spatial::SpatialBoundingSphere const& sphere);
        static auto FromFrustum(winrt::Windows::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, winrt::Windows::Perception::Spatial::SpatialBoundingFrustum const& frustum);
    };
    struct __declspec(empty_bases) SpatialCoordinateSystem : winrt::Windows::Perception::Spatial::ISpatialCoordinateSystem
    {
        SpatialCoordinateSystem(std::nullptr_t) noexcept {}
        SpatialCoordinateSystem(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialCoordinateSystem(ptr, take_ownership_from_abi) {}
        SpatialCoordinateSystem(SpatialCoordinateSystem const&) noexcept = default;
        SpatialCoordinateSystem(SpatialCoordinateSystem&&) noexcept = default;
        SpatialCoordinateSystem& operator=(SpatialCoordinateSystem const&) & noexcept = default;
        SpatialCoordinateSystem& operator=(SpatialCoordinateSystem&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialEntity : winrt::Windows::Perception::Spatial::ISpatialEntity
    {
        SpatialEntity(std::nullptr_t) noexcept {}
        SpatialEntity(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialEntity(ptr, take_ownership_from_abi) {}
        explicit SpatialEntity(winrt::Windows::Perception::Spatial::SpatialAnchor const& spatialAnchor);
        SpatialEntity(winrt::Windows::Perception::Spatial::SpatialAnchor const& spatialAnchor, winrt::Windows::Foundation::Collections::ValueSet const& propertySet);
        SpatialEntity(SpatialEntity const&) noexcept = default;
        SpatialEntity(SpatialEntity&&) noexcept = default;
        SpatialEntity& operator=(SpatialEntity const&) & noexcept = default;
        SpatialEntity& operator=(SpatialEntity&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialEntityAddedEventArgs : winrt::Windows::Perception::Spatial::ISpatialEntityAddedEventArgs
    {
        SpatialEntityAddedEventArgs(std::nullptr_t) noexcept {}
        SpatialEntityAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialEntityAddedEventArgs(ptr, take_ownership_from_abi) {}
        SpatialEntityAddedEventArgs(SpatialEntityAddedEventArgs const&) noexcept = default;
        SpatialEntityAddedEventArgs(SpatialEntityAddedEventArgs&&) noexcept = default;
        SpatialEntityAddedEventArgs& operator=(SpatialEntityAddedEventArgs const&) & noexcept = default;
        SpatialEntityAddedEventArgs& operator=(SpatialEntityAddedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialEntityRemovedEventArgs : winrt::Windows::Perception::Spatial::ISpatialEntityRemovedEventArgs
    {
        SpatialEntityRemovedEventArgs(std::nullptr_t) noexcept {}
        SpatialEntityRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialEntityRemovedEventArgs(ptr, take_ownership_from_abi) {}
        SpatialEntityRemovedEventArgs(SpatialEntityRemovedEventArgs const&) noexcept = default;
        SpatialEntityRemovedEventArgs(SpatialEntityRemovedEventArgs&&) noexcept = default;
        SpatialEntityRemovedEventArgs& operator=(SpatialEntityRemovedEventArgs const&) & noexcept = default;
        SpatialEntityRemovedEventArgs& operator=(SpatialEntityRemovedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialEntityStore : winrt::Windows::Perception::Spatial::ISpatialEntityStore
    {
        SpatialEntityStore(std::nullptr_t) noexcept {}
        SpatialEntityStore(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialEntityStore(ptr, take_ownership_from_abi) {}
        SpatialEntityStore(SpatialEntityStore const&) noexcept = default;
        SpatialEntityStore(SpatialEntityStore&&) noexcept = default;
        SpatialEntityStore& operator=(SpatialEntityStore const&) & noexcept = default;
        SpatialEntityStore& operator=(SpatialEntityStore&&) & noexcept = default;
        [[nodiscard]] static auto IsSupported();
        static auto TryGet(winrt::Windows::System::RemoteSystems::RemoteSystemSession const& session);
    };
    struct __declspec(empty_bases) SpatialEntityUpdatedEventArgs : winrt::Windows::Perception::Spatial::ISpatialEntityUpdatedEventArgs
    {
        SpatialEntityUpdatedEventArgs(std::nullptr_t) noexcept {}
        SpatialEntityUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialEntityUpdatedEventArgs(ptr, take_ownership_from_abi) {}
        SpatialEntityUpdatedEventArgs(SpatialEntityUpdatedEventArgs const&) noexcept = default;
        SpatialEntityUpdatedEventArgs(SpatialEntityUpdatedEventArgs&&) noexcept = default;
        SpatialEntityUpdatedEventArgs& operator=(SpatialEntityUpdatedEventArgs const&) & noexcept = default;
        SpatialEntityUpdatedEventArgs& operator=(SpatialEntityUpdatedEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialEntityWatcher : winrt::Windows::Perception::Spatial::ISpatialEntityWatcher
    {
        SpatialEntityWatcher(std::nullptr_t) noexcept {}
        SpatialEntityWatcher(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialEntityWatcher(ptr, take_ownership_from_abi) {}
        SpatialEntityWatcher(SpatialEntityWatcher const&) noexcept = default;
        SpatialEntityWatcher(SpatialEntityWatcher&&) noexcept = default;
        SpatialEntityWatcher& operator=(SpatialEntityWatcher const&) & noexcept = default;
        SpatialEntityWatcher& operator=(SpatialEntityWatcher&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialLocation : winrt::Windows::Perception::Spatial::ISpatialLocation,
        impl::require<SpatialLocation, winrt::Windows::Perception::Spatial::ISpatialLocation2>
    {
        SpatialLocation(std::nullptr_t) noexcept {}
        SpatialLocation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialLocation(ptr, take_ownership_from_abi) {}
        SpatialLocation(SpatialLocation const&) noexcept = default;
        SpatialLocation(SpatialLocation&&) noexcept = default;
        SpatialLocation& operator=(SpatialLocation const&) & noexcept = default;
        SpatialLocation& operator=(SpatialLocation&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialLocator : winrt::Windows::Perception::Spatial::ISpatialLocator
    {
        SpatialLocator(std::nullptr_t) noexcept {}
        SpatialLocator(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialLocator(ptr, take_ownership_from_abi) {}
        SpatialLocator(SpatialLocator const&) noexcept = default;
        SpatialLocator(SpatialLocator&&) noexcept = default;
        SpatialLocator& operator=(SpatialLocator const&) & noexcept = default;
        SpatialLocator& operator=(SpatialLocator&&) & noexcept = default;
        static auto GetDefault();
    };
    struct __declspec(empty_bases) SpatialLocatorAttachedFrameOfReference : winrt::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference
    {
        SpatialLocatorAttachedFrameOfReference(std::nullptr_t) noexcept {}
        SpatialLocatorAttachedFrameOfReference(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialLocatorAttachedFrameOfReference(ptr, take_ownership_from_abi) {}
        SpatialLocatorAttachedFrameOfReference(SpatialLocatorAttachedFrameOfReference const&) noexcept = default;
        SpatialLocatorAttachedFrameOfReference(SpatialLocatorAttachedFrameOfReference&&) noexcept = default;
        SpatialLocatorAttachedFrameOfReference& operator=(SpatialLocatorAttachedFrameOfReference const&) & noexcept = default;
        SpatialLocatorAttachedFrameOfReference& operator=(SpatialLocatorAttachedFrameOfReference&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialLocatorPositionalTrackingDeactivatingEventArgs : winrt::Windows::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs
    {
        SpatialLocatorPositionalTrackingDeactivatingEventArgs(std::nullptr_t) noexcept {}
        SpatialLocatorPositionalTrackingDeactivatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialLocatorPositionalTrackingDeactivatingEventArgs(ptr, take_ownership_from_abi) {}
        SpatialLocatorPositionalTrackingDeactivatingEventArgs(SpatialLocatorPositionalTrackingDeactivatingEventArgs const&) noexcept = default;
        SpatialLocatorPositionalTrackingDeactivatingEventArgs(SpatialLocatorPositionalTrackingDeactivatingEventArgs&&) noexcept = default;
        SpatialLocatorPositionalTrackingDeactivatingEventArgs& operator=(SpatialLocatorPositionalTrackingDeactivatingEventArgs const&) & noexcept = default;
        SpatialLocatorPositionalTrackingDeactivatingEventArgs& operator=(SpatialLocatorPositionalTrackingDeactivatingEventArgs&&) & noexcept = default;
    };
    struct __declspec(empty_bases) SpatialStageFrameOfReference : winrt::Windows::Perception::Spatial::ISpatialStageFrameOfReference
    {
        SpatialStageFrameOfReference(std::nullptr_t) noexcept {}
        SpatialStageFrameOfReference(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialStageFrameOfReference(ptr, take_ownership_from_abi) {}
        SpatialStageFrameOfReference(SpatialStageFrameOfReference const&) noexcept = default;
        SpatialStageFrameOfReference(SpatialStageFrameOfReference&&) noexcept = default;
        SpatialStageFrameOfReference& operator=(SpatialStageFrameOfReference const&) & noexcept = default;
        SpatialStageFrameOfReference& operator=(SpatialStageFrameOfReference&&) & noexcept = default;
        [[nodiscard]] static auto Current();
        static auto CurrentChanged(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        using CurrentChanged_revoker = impl::factory_event_revoker<winrt::Windows::Perception::Spatial::ISpatialStageFrameOfReferenceStatics, &impl::abi_t<winrt::Windows::Perception::Spatial::ISpatialStageFrameOfReferenceStatics>::remove_CurrentChanged>;
        [[nodiscard]] static CurrentChanged_revoker CurrentChanged(auto_revoke_t, winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable> const& handler);
        static auto CurrentChanged(winrt::event_token const& cookie);
        static auto RequestNewStageAsync();
    };
    struct __declspec(empty_bases) SpatialStationaryFrameOfReference : winrt::Windows::Perception::Spatial::ISpatialStationaryFrameOfReference
    {
        SpatialStationaryFrameOfReference(std::nullptr_t) noexcept {}
        SpatialStationaryFrameOfReference(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Perception::Spatial::ISpatialStationaryFrameOfReference(ptr, take_ownership_from_abi) {}
        SpatialStationaryFrameOfReference(SpatialStationaryFrameOfReference const&) noexcept = default;
        SpatialStationaryFrameOfReference(SpatialStationaryFrameOfReference&&) noexcept = default;
        SpatialStationaryFrameOfReference& operator=(SpatialStationaryFrameOfReference const&) & noexcept = default;
        SpatialStationaryFrameOfReference& operator=(SpatialStationaryFrameOfReference&&) & noexcept = default;
    };
}
#endif
