// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Gaming_Preview_GamesEnumeration_2_H
#define WINRT_Windows_Gaming_Preview_GamesEnumeration_2_H
#include "winrt/impl/Windows.Foundation.1.h"
#include "winrt/impl/Windows.Gaming.Preview.GamesEnumeration.1.h"
WINRT_EXPORT namespace winrt::Windows::Gaming::Preview::GamesEnumeration
{
    struct GameListChangedEventHandler : Windows::Foundation::IUnknown
    {
        GameListChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        GameListChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        GameListChangedEventHandler(GameListChangedEventHandler const&) noexcept = default;
        GameListChangedEventHandler(GameListChangedEventHandler&&) noexcept = default;
        GameListChangedEventHandler& operator=(GameListChangedEventHandler const&) & noexcept = default;
        GameListChangedEventHandler& operator=(GameListChangedEventHandler&&) & noexcept = default;
        template <typename L> GameListChangedEventHandler(L lambda);
        template <typename F> GameListChangedEventHandler(F* function);
        template <typename O, typename M> GameListChangedEventHandler(O* object, M method);
        template <typename O, typename M> GameListChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> GameListChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(winrt::Windows::Gaming::Preview::GamesEnumeration::GameListEntry const& game) const;
    };
    struct GameListRemovedEventHandler : Windows::Foundation::IUnknown
    {
        GameListRemovedEventHandler(std::nullptr_t = nullptr) noexcept {}
        GameListRemovedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        GameListRemovedEventHandler(GameListRemovedEventHandler const&) noexcept = default;
        GameListRemovedEventHandler(GameListRemovedEventHandler&&) noexcept = default;
        GameListRemovedEventHandler& operator=(GameListRemovedEventHandler const&) & noexcept = default;
        GameListRemovedEventHandler& operator=(GameListRemovedEventHandler&&) & noexcept = default;
        template <typename L> GameListRemovedEventHandler(L lambda);
        template <typename F> GameListRemovedEventHandler(F* function);
        template <typename O, typename M> GameListRemovedEventHandler(O* object, M method);
        template <typename O, typename M> GameListRemovedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> GameListRemovedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(param::hstring const& identifier) const;
    };
    struct GameList
    {
        GameList() = delete;
        static auto FindAllAsync();
        static auto FindAllAsync(param::hstring const& packageFamilyName);
        static auto GameAdded(winrt::Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler);
        using GameAdded_revoker = impl::factory_event_revoker<winrt::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics, &impl::abi_t<winrt::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics>::remove_GameAdded>;
        [[nodiscard]] static GameAdded_revoker GameAdded(auto_revoke_t, winrt::Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler);
        static auto GameAdded(winrt::event_token const& token);
        static auto GameRemoved(winrt::Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler const& handler);
        using GameRemoved_revoker = impl::factory_event_revoker<winrt::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics, &impl::abi_t<winrt::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics>::remove_GameRemoved>;
        [[nodiscard]] static GameRemoved_revoker GameRemoved(auto_revoke_t, winrt::Windows::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler const& handler);
        static auto GameRemoved(winrt::event_token const& token);
        static auto GameUpdated(winrt::Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler);
        using GameUpdated_revoker = impl::factory_event_revoker<winrt::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics, &impl::abi_t<winrt::Windows::Gaming::Preview::GamesEnumeration::IGameListStatics>::remove_GameUpdated>;
        [[nodiscard]] static GameUpdated_revoker GameUpdated(auto_revoke_t, winrt::Windows::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler);
        static auto GameUpdated(winrt::event_token const& token);
        static auto MergeEntriesAsync(winrt::Windows::Gaming::Preview::GamesEnumeration::GameListEntry const& left, winrt::Windows::Gaming::Preview::GamesEnumeration::GameListEntry const& right);
        static auto UnmergeEntryAsync(winrt::Windows::Gaming::Preview::GamesEnumeration::GameListEntry const& mergedEntry);
    };
    struct __declspec(empty_bases) GameListEntry : winrt::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry,
        impl::require<GameListEntry, winrt::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry2>
    {
        GameListEntry(std::nullptr_t) noexcept {}
        GameListEntry(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Gaming::Preview::GamesEnumeration::IGameListEntry(ptr, take_ownership_from_abi) {}
        GameListEntry(GameListEntry const&) noexcept = default;
        GameListEntry(GameListEntry&&) noexcept = default;
        GameListEntry& operator=(GameListEntry const&) & noexcept = default;
        GameListEntry& operator=(GameListEntry&&) & noexcept = default;
    };
    struct __declspec(empty_bases) GameModeConfiguration : winrt::Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration
    {
        GameModeConfiguration(std::nullptr_t) noexcept {}
        GameModeConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Gaming::Preview::GamesEnumeration::IGameModeConfiguration(ptr, take_ownership_from_abi) {}
        GameModeConfiguration(GameModeConfiguration const&) noexcept = default;
        GameModeConfiguration(GameModeConfiguration&&) noexcept = default;
        GameModeConfiguration& operator=(GameModeConfiguration const&) & noexcept = default;
        GameModeConfiguration& operator=(GameModeConfiguration&&) & noexcept = default;
    };
    struct __declspec(empty_bases) GameModeUserConfiguration : winrt::Windows::Gaming::Preview::GamesEnumeration::IGameModeUserConfiguration
    {
        GameModeUserConfiguration(std::nullptr_t) noexcept {}
        GameModeUserConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Gaming::Preview::GamesEnumeration::IGameModeUserConfiguration(ptr, take_ownership_from_abi) {}
        GameModeUserConfiguration(GameModeUserConfiguration const&) noexcept = default;
        GameModeUserConfiguration(GameModeUserConfiguration&&) noexcept = default;
        GameModeUserConfiguration& operator=(GameModeUserConfiguration const&) & noexcept = default;
        GameModeUserConfiguration& operator=(GameModeUserConfiguration&&) & noexcept = default;
        static auto GetDefault();
    };
}
#endif
