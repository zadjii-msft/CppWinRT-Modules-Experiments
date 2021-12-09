// BasicConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <coroutine>
#include <iostream>

import winrt;

using namespace winrt;
using namespace Windows::Foundation;
using namespace Windows::Web::Syndication;

void PrintFeed(SyndicationFeed const& syndicationFeed)
{
    for (SyndicationItem const& syndicationItem : syndicationFeed.Items())
    {
        std::wcout << syndicationItem.Title().Text().c_str() << std::endl;
    }
}

IAsyncAction ProcessFeedAsync()
{
    Uri rssFeedUri{ L"https://blogs.windows.com/feed" };
    SyndicationClient syndicationClient;
    SyndicationFeed syndicationFeed{ co_await syndicationClient.RetrieveFeedAsync(rssFeedUri) };
    PrintFeed(syndicationFeed);
}

int main()
{
    init_apartment();
    auto processOp{ ProcessFeedAsync() };
    processOp.get(); 
}

//int main()
//{
//    Uri uri(L"http://kennykerr.ca");
//    printf("%ls\n", uri.Domain().c_str());
//}
//
