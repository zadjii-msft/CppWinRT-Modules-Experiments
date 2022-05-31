#include "pch.h"

#include <iostream>

#ifdef COMPILE_WITH_MODULES
import winrt;
#endif

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;


// https://devdiv.visualstudio.com/DevDiv/_workitems/edit/1458232 fixed with
// Version 17.3.0 Preview 2.0 [32530.156.main]
#if 0   // Async coroutine causes name_v corruptions

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

    DoAnotherThing();

    auto processOp{ ProcessFeedAsync() };
    // do other work while the feed is being printed.
    processOp.get(); // no more work to do; call get() so that we see the printout before the application exits.
}

#endif
