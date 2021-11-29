// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210505.3

#ifndef WINRT_Windows_Phone_PersonalInformation_2_H
#define WINRT_Windows_Phone_PersonalInformation_2_H
#include "winrt/impl/Windows.Storage.Streams.1.h"
#include "winrt/impl/Windows.Phone.PersonalInformation.1.h"
WINRT_EXPORT namespace winrt::Windows::Phone::PersonalInformation
{
    struct __declspec(empty_bases) ContactAddress : winrt::Windows::Phone::PersonalInformation::IContactAddress
    {
        ContactAddress(std::nullptr_t) noexcept {}
        ContactAddress(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::PersonalInformation::IContactAddress(ptr, take_ownership_from_abi) {}
        ContactAddress();
        ContactAddress(ContactAddress const&) noexcept = default;
        ContactAddress(ContactAddress&&) noexcept = default;
        ContactAddress& operator=(ContactAddress const&) & noexcept = default;
        ContactAddress& operator=(ContactAddress&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ContactChangeRecord : winrt::Windows::Phone::PersonalInformation::IContactChangeRecord
    {
        ContactChangeRecord(std::nullptr_t) noexcept {}
        ContactChangeRecord(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::PersonalInformation::IContactChangeRecord(ptr, take_ownership_from_abi) {}
        ContactChangeRecord(ContactChangeRecord const&) noexcept = default;
        ContactChangeRecord(ContactChangeRecord&&) noexcept = default;
        ContactChangeRecord& operator=(ContactChangeRecord const&) & noexcept = default;
        ContactChangeRecord& operator=(ContactChangeRecord&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ContactInformation : winrt::Windows::Phone::PersonalInformation::IContactInformation
    {
        ContactInformation(std::nullptr_t) noexcept {}
        ContactInformation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::PersonalInformation::IContactInformation(ptr, take_ownership_from_abi) {}
        ContactInformation();
        ContactInformation(ContactInformation const&) noexcept = default;
        ContactInformation(ContactInformation&&) noexcept = default;
        ContactInformation& operator=(ContactInformation const&) & noexcept = default;
        ContactInformation& operator=(ContactInformation&&) & noexcept = default;
        static auto ParseVcardAsync(winrt::Windows::Storage::Streams::IInputStream const& vcard);
    };
    struct __declspec(empty_bases) ContactQueryOptions : winrt::Windows::Phone::PersonalInformation::IContactQueryOptions
    {
        ContactQueryOptions(std::nullptr_t) noexcept {}
        ContactQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::PersonalInformation::IContactQueryOptions(ptr, take_ownership_from_abi) {}
        ContactQueryOptions();
        ContactQueryOptions(ContactQueryOptions const&) noexcept = default;
        ContactQueryOptions(ContactQueryOptions&&) noexcept = default;
        ContactQueryOptions& operator=(ContactQueryOptions const&) & noexcept = default;
        ContactQueryOptions& operator=(ContactQueryOptions&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ContactQueryResult : winrt::Windows::Phone::PersonalInformation::IContactQueryResult
    {
        ContactQueryResult(std::nullptr_t) noexcept {}
        ContactQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::PersonalInformation::IContactQueryResult(ptr, take_ownership_from_abi) {}
        ContactQueryResult(ContactQueryResult const&) noexcept = default;
        ContactQueryResult(ContactQueryResult&&) noexcept = default;
        ContactQueryResult& operator=(ContactQueryResult const&) & noexcept = default;
        ContactQueryResult& operator=(ContactQueryResult&&) & noexcept = default;
    };
    struct __declspec(empty_bases) ContactStore : winrt::Windows::Phone::PersonalInformation::IContactStore,
        impl::require<ContactStore, winrt::Windows::Phone::PersonalInformation::IContactStore2>
    {
        ContactStore(std::nullptr_t) noexcept {}
        ContactStore(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::PersonalInformation::IContactStore(ptr, take_ownership_from_abi) {}
        ContactStore(ContactStore const&) noexcept = default;
        ContactStore(ContactStore&&) noexcept = default;
        ContactStore& operator=(ContactStore const&) & noexcept = default;
        ContactStore& operator=(ContactStore&&) & noexcept = default;
        static auto CreateOrOpenAsync();
        static auto CreateOrOpenAsync(winrt::Windows::Phone::PersonalInformation::ContactStoreSystemAccessMode const& access, winrt::Windows::Phone::PersonalInformation::ContactStoreApplicationAccessMode const& sharing);
    };
    struct KnownContactProperties
    {
        KnownContactProperties() = delete;
        [[nodiscard]] static auto DisplayName();
        [[nodiscard]] static auto FamilyName();
        [[nodiscard]] static auto GivenName();
        [[nodiscard]] static auto HonorificPrefix();
        [[nodiscard]] static auto HonorificSuffix();
        [[nodiscard]] static auto AdditionalName();
        [[nodiscard]] static auto Address();
        [[nodiscard]] static auto OtherAddress();
        [[nodiscard]] static auto Email();
        [[nodiscard]] static auto WorkAddress();
        [[nodiscard]] static auto WorkTelephone();
        [[nodiscard]] static auto JobTitle();
        [[nodiscard]] static auto Birthdate();
        [[nodiscard]] static auto Anniversary();
        [[nodiscard]] static auto Telephone();
        [[nodiscard]] static auto MobileTelephone();
        [[nodiscard]] static auto Url();
        [[nodiscard]] static auto Notes();
        [[nodiscard]] static auto WorkFax();
        [[nodiscard]] static auto Children();
        [[nodiscard]] static auto SignificantOther();
        [[nodiscard]] static auto CompanyName();
        [[nodiscard]] static auto CompanyTelephone();
        [[nodiscard]] static auto HomeFax();
        [[nodiscard]] static auto AlternateTelephone();
        [[nodiscard]] static auto Manager();
        [[nodiscard]] static auto Nickname();
        [[nodiscard]] static auto OfficeLocation();
        [[nodiscard]] static auto WorkEmail();
        [[nodiscard]] static auto YomiGivenName();
        [[nodiscard]] static auto YomiFamilyName();
        [[nodiscard]] static auto YomiCompanyName();
        [[nodiscard]] static auto OtherEmail();
        [[nodiscard]] static auto AlternateMobileTelephone();
        [[nodiscard]] static auto AlternateWorkTelephone();
    };
    struct __declspec(empty_bases) StoredContact : winrt::Windows::Phone::PersonalInformation::IStoredContact,
        impl::require<StoredContact, winrt::Windows::Phone::PersonalInformation::IContactInformation2>
    {
        StoredContact(std::nullptr_t) noexcept {}
        StoredContact(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::Phone::PersonalInformation::IStoredContact(ptr, take_ownership_from_abi) {}
        explicit StoredContact(winrt::Windows::Phone::PersonalInformation::ContactStore const& store);
        StoredContact(winrt::Windows::Phone::PersonalInformation::ContactStore const& store, winrt::Windows::Phone::PersonalInformation::ContactInformation const& contact);
        StoredContact(StoredContact const&) noexcept = default;
        StoredContact(StoredContact&&) noexcept = default;
        StoredContact& operator=(StoredContact const&) & noexcept = default;
        StoredContact& operator=(StoredContact&&) & noexcept = default;
    };
}
#endif
