#include "pch.h"

#ifdef COMPILE_WITH_MODULES

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
#include <coroutine>

import winrtWith953Patch;
#pragma comment(lib, "oleaut32")
#pragma comment(lib, "ole32")
#pragma comment(lib, "advapi32")


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
    // A silly fire_and_forget, just to compare fire_and_forgets vs a full IAsyncAction
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

    // As mentioned in microsoft/cppwinrt#935. Root cause is yet unknown.
    auto name{ winrt::name_of<Uri>() };
    name;

    DoAnotherThing();

    auto processOp{ ProcessFeedAsync() };
    // do other work while the feed is being printed.
    processOp.get(); // no more work to do; call get() so that we see the printout before the application exits.
}
