#pragma once

#ifdef COMPILE_WITH_MODULES

#define WINRT_EXPORT
#ifdef __INTELLISENSE__
#define WINRT_IMPL_AUTO(...) __VA_ARGS__
#else
#define WINRT_IMPL_AUTO(...) auto
#endif

#else

#include <unknwn.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>

#endif
