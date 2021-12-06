
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
