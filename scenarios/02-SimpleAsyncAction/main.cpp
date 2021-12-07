#include "pch.h"

#ifdef COMPILE_WITH_MODULES


// #include <ctxtcall.h>
// #include <Objbase.h>
#include <unknwn.h>


#include <algorithm>
#include <array>
#include <atomic>
#include <charconv>
#include <chrono>
#include <cstddef>
#include <iterator>
#include <map>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string_view>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>
// #include <experimental/coroutine>
#include <coroutine>

//inline std::pair<int32_t, int32_t> get_apartment_type() noexcept
//{
//    APTTYPE aptType;
//    APTTYPEQUALIFIER aptTypeQualifier;
//    if (0 == CoGetApartmentType(&aptType, &aptTypeQualifier))
//    {
//        return { aptType, aptTypeQualifier };
//    }
//    else
//    {
//        return { 1 /* APTTYPE_MTA */, 1 /* APTTYPEQUALIFIER_IMPLICIT_MTA */ };
//    }
//}

// import winrt;
import winrtWith953Patch;
#pragma comment(lib, "oleaut32")
#pragma comment(lib, "ole32")
#pragma comment(lib, "advapi32")

// #include "fake_coroutine_traits.h"

#endif

#ifndef COMPILE_WITH_MODULES
#endif

#include <iostream>

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;

void PrintFeed(SyndicationFeed const& syndicationFeed)
{
    // for (SyndicationItem const& syndicationItem : syndicationFeed.Items())
    // {
    for (auto i = 0u; i < syndicationFeed.Items().Size(); i++)
    {
        const auto& syndicationItem{ syndicationFeed.Items().GetAt(i) };

        std::wcout << syndicationItem.Title().Text().c_str() << std::endl;
    }
}

fire_and_forget DoAnotherThing()
{
    co_await winrt::resume_background();
    std::wcout << L"Who knows where I'll be printed?!" << std::endl;
}

winrt::Windows::Foundation::IAsyncAction ProcessFeedAsync()
{
    Uri rssFeedUri{ L"https://blogs.windows.com/feed" };
    SyndicationClient syndicationClient;
    SyndicationFeed syndicationFeed{ co_await syndicationClient.RetrieveFeedAsync(rssFeedUri) };
    PrintFeed(syndicationFeed);
}

int main()
{
    winrt::init_apartment();

    DoAnotherThing();

    auto processOp{ ProcessFeedAsync() };
    // do other work while the feed is being printed.
    processOp.get(); // no more work to do; call get() so that we see the printout before the application exits.
}
