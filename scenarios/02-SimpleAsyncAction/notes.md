
Notes from trying to get `02-SimpleAsyncAction` to build as a module.
The PCH version built without a hitch.


Okay, without any other modifications, this is the first set of errors I got building this sample.

```
...main.cpp(23,42): error C2672: 'begin': no matching overloaded function found

...main.cpp(24,1): error C2893: Failed to specialize function template 'unknown-type std::begin(_Container &)'
    ...\include\xutility(1801): message : see declaration of 'std::begin'
...main.cpp(24,1): message : With the following template arguments:
...main.cpp(24,1): message : '_Container=winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Web::Syndication::SyndicationItem>'

...main.cpp(24,1): error C2784: 'const _Elem *std::begin(std::initializer_list<_Elem>) noexcept': could not deduce template argument for 'std::initializer_list<_Elem>' from 'winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Web::Syndication::SyndicationItem>'
    ...\include\initializer_list(55): message : see declaration of 'std::begin'

...main.cpp(23,42): error C2672: 'end': no matching overloaded function found

...main.cpp(24,1): error C2893: Failed to specialize function template 'unknown-type std::end(_Container &)'
    ...\include\xutility(1811): message : see declaration of 'std::end'
...main.cpp(24,1): message : With the following template arguments:
...main.cpp(24,1): message : '_Container=winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Web::Syndication::SyndicationItem>'

...main.cpp(24,1): error C2784: 'const _Elem *std::end(std::initializer_list<_Elem>) noexcept': could not deduce template argument for 'std::initializer_list<_Elem>' from 'winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Web::Syndication::SyndicationItem>'
    ...\include\initializer_list(60): message : see declaration of 'std::end'

...main.cpp(24,1): error C3536: '<begin>$L0': cannot be used before it is initialized

...main.cpp(24,1): error C3536: '<end>$L0': cannot be used before it is initialized

...main.cpp(23,44): error C2100: illegal indirection

...main.cpp(23,44): error C2440: 'initializing': cannot convert from 'int' to 'const winrt::Windows::Web::Syndication::SyndicationItem &'
...main.cpp(24,1): message : Reason: cannot convert from 'int' to 'const winrt::Windows::Web::Syndication::SyndicationItem'
...main.cpp(24,1): message : No constructor could take the source type, or constructor overload resolution was ambiguous

...main.cpp(33,2): error C3774: cannot find 'std::experimental::coroutine_traits': Please include <experimental/coroutine> header
```

I tried slamming includes in for `<experimental/coroutine>` and the rest of the STL, but they didn't really make it better.


Okay, i think that boiled down to two main issues.

```
error C2893: Failed to specialize function template 'unknown-type std::begin(_Container &)'
    include\xutility(1801): message : see declaration of 'std::begin'
    main.cpp(45,1): message : With the following template arguments:
    main.cpp(45,1): message : '_Container=winrt::Windows::Foundation::Collections::IVector<winrt::Windows::Web::Syndication::SyndicationItem>'
```

```
error C2039: 'promise_type': is not a member of 'std::experimental::coroutine_traits<winrt::Windows::Foundation::IAsyncAction>'
```


OBSERVATION:
I must be doing some ranges thing wrong with cpp20. Converting the code to instead:

```diff
void PrintFeed(SyndicationFeed const& syndicationFeed)
{
-    for (SyndicationItem const& syndicationItem : syndicationFeed.Items())
-    {
+    for (auto i = 0u; i < syndicationFeed.Items().Size(); i++)
+    {
+        const auto& syndicationItem{ syndicationFeed.Items().GetAt(i) };
        std::wcout << syndicationItem.Title().Text().c_str() << std::endl;
    }
```

then we no longer get those ranges issues. Then, with both the 953 patched and the release version of cppwinrt, we get the following build error:

```
3>...\02-SimpleAsyncAction\main.cpp(62,82): error C2039: 'promise_type': is not a member of 'std::experimental::coroutine_traits<winrt::Windows::Foundation::IAsyncAction>'
3>...\02-SimpleAsyncAction\main.cpp(62,1): error C2440: 'initializing': cannot convert from 'initializer list' to 'winrt::Windows::Web::Syndication::SyndicationFeed'
3>...\02-SimpleAsyncAction\main.cpp(70,21): error C2065: 'ProcessFeedAsync': undeclared identifier
```

```
'promise_type': is not a member of 'std::experimental::coroutine_traits<winrt::Windows::Foundation::IAsyncAction>'
```

promise_type is defined over in `Windows.Foundation.h`,

```c++

#ifdef __cpp_lib_coroutine
namespace std
#else
namespace std::experimental
#endif
{
    template <typename... Args>
    struct coroutine_traits<winrt::Windows::Foundation::IAsyncAction, Args...>
    {
        struct promise_type final : winrt::impl::promise_base<promise_type, winrt::Windows::Foundation::IAsyncAction>
        {
            void return_void() const noexcept
            {
            }
        };
    };
```

so maybe we're setting `__cpp_lib_coroutine` wrong. Maybe the module thinks it's defined, and the impl doesn't?


I've checked
* module and exe both `/await:strict`
* module `/await:strict`, exe `/await`
* module and exe both `/await`
* module `/await:strict`, exe `/await`



Ah I know what I did wrong. I once again had the include path pointing at the wrong files, so it wasn't actually including the updated cppwinty module, it was only including the SDK version.


Adding that, and some other includes, we get down to the crux of the issue:

## tl;dr

When compiling the exe with the patched cppwinrt module, you'll get an error like:

```
...00-WinRTModule\winrt-with-953-patch\winrt\base.h(8689,34): error C3861: 'get_apartment_type': identifier not found
```

The code that causes this is in `base.h`:

```c++

namespace winrt::impl
{
    ...

    inline std::pair<int32_t, int32_t> get_apartment_type() noexcept
    {
        int32_t aptType;
        int32_t aptTypeQualifier;
        if (0 == WINRT_IMPL_CoGetApartmentType(&aptType, &aptTypeQualifier))
        {
            return { aptType, aptTypeQualifier };
        }
        else
        {
            return { 1 /* APTTYPE_MTA */, 1 /* APTTYPEQUALIFIER_IMPLICIT_MTA */ };
        }
    }

    struct resume_apartment_context
    {
        resume_apartment_context() = default;
        resume_apartment_context(std::nullptr_t) : m_context(nullptr), m_context_type(-1) {}
        resume_apartment_context(resume_apartment_context const&) = default;
        resume_apartment_context(resume_apartment_context&& other) noexcept :
            m_context(std::move(other.m_context)), m_context_type(std::exchange(other.m_context_type, -1)) {}
        resume_apartment_context& operator=(resume_apartment_context const&) = default;
        resume_apartment_context& operator=(resume_apartment_context&& other) noexcept
        {
            m_context = std::move(other.m_context);
            m_context_type = std::exchange(other.m_context_type, -1);
            return *this;
        }
        bool valid() const noexcept
        {
            return m_context_type >= 0;
        }

        com_ptr<IContextCallback> m_context = try_capture<IContextCallback>(WINRT_IMPL_CoGetObjectContext);
        int32_t m_context_type = get_apartment_type().first;
    };

```

the error comes from the last line in the `resume_apartment_context` struct, combined with a [compiler error](https://developercommunity.visualstudio.com/t/identifier-not-found-with-default-membe/1376824):

```c++
int32_t m_context_type = get_apartment_type().first;
```

Even if you manually add the definition of `get_apartment_type` before the WinRT module, you're still going to run into the error in other places. `IContextCallback` in that same struct is also in the `winrt::impl` module, and therefore not exported.


### Solutions(?)
You can manually patch base.h to workaround the compiler bug.

If you do that, the code will compile! but it won't run:

```
    02-SimpleAsyncActionMod.exe!std::basic_string_view<wchar_t,std::char_traits<wchar_t>>::basic_string_view<wchar_t,std::char_traits<wchar_t>>(const wchar_t * const _Cts, const unsigned __int64 _Count) Line 1263    C++
    02-SimpleAsyncActionMod.exe!winrt::impl::to_wstring_view<23>(const wchar_t[23] & value) Line 1553   C++
>   02-SimpleAsyncActionMod.exe!winrtWith953Patch::winrt::name_of<winrt::Windows::Foundation::Uri>() Line 1562  C++
    02-SimpleAsyncActionMod.exe!winrt::impl::factory_cache_entry<winrt::Windows::Foundation::Uri,winrt::Windows::Foundation::IUriRuntimeClassFactory>::call<`winrt::Windows::Foundation::Uri::Uri'::`1'::<lambda_347_> &>(winrt::Windows::Foundation::Uri::{ctor}::__l1::<lambda_347_> & callback) Line 6509    C++
    02-SimpleAsyncActionMod.exe!winrt::impl::call_factory<winrt::Windows::Foundation::Uri,winrt::Windows::Foundation::IUriRuntimeClassFactory,`winrt::Windows::Foundation::Uri::Uri'::`1'::<lambda_347_>>(winrt::Windows::Foundation::Uri::{ctor}::__l1::<lambda_347_> && callback) Line 6553   C++
    02-SimpleAsyncActionMod.exe!winrtWith953Patch::winrt::Windows::Foundation::Uri::Uri(const winrt::param::hstring & uri) Line 2302    C++
    02-SimpleAsyncActionMod.exe!ProcessFeedAsync() Line 86  C++
```

This might be the

> Adding winrt::name_of<Uri>(); in main, weirdly, solves it and makes the example run as expected. This might be a codegen bug but I haven't taken time to reduce it yet.

thing that @sylveon mentioned
