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
#include <string>
#include <string_view>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>
