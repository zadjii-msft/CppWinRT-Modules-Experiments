#include "pch.h"

#include <iostream>

#ifdef COMPILE_WITH_MODULES

//#include <unknwn.h>
//#include <algorithm>
//#include <array>
//#include <atomic>
//#include <charconv>
//#include <chrono>
//#include <cstddef>
//#include <iterator>
//#include <map>
//#include <memory>
//#include <optional>
//#include <stdexcept>
//#include <string_view>
//#include <string>
//#include <thread>
//#include <tuple>
//#include <type_traits>
//#include <unordered_map>
//#include <utility>
//#include <vector>
//#include <coroutine>

import winrt;

#endif

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;


#if 0

// TODO: open DevDiv issue 
// simply defining any winrt async coroutine causes this string_view assert and subsequent crash:
//  _STL_VERIFY(_Count == 0 || _Cts, "non-zero size null string_view");
// _Count is correctly passed (e.g., 22 for "Windows.Foundation.Uri") but _Cts (data) is nullptr
// problem can be worked around via explicit winrt::name_of<Class>() calls

//winrt::Windows::Foundation::IAsyncOperation<bool> - also fails
//winrt::fire_and_forget - succeeds - failure limited to Windows.Foundation.* coroutine types
winrt::Windows::Foundation::IAsyncAction
AsyncFoo()
{
    co_return;
}

int main()
{
    winrt::init_apartment();
    WwwFormUrlDecoder decoder(L"foo=bar"); // also crashes - not just Uri
    Uri uri(L"http://aka.ms/cppwinrt");
    printf("Hello, %ls!\n", uri.AbsoluteUri().c_str());
}

#else

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

#endif
