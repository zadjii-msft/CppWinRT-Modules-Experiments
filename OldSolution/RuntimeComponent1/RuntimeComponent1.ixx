#include "pch.h"
module;

// import winrt;

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

//#include <winrt\Windows.Foundation.Numerics.h>
// 
#include <winrt\base.h>
// #include <winrt\RuntimeComponent1.h>

export module RuntimeComponent1;

import winrt;
// export namespace winrt::RuntimeComponent1
// {
//     struct IClass;
//     struct Class;
// };

// #include "winrt/base.h"
#define WINRT_EXPORT export
// #include "winrt/impl/RuntimeComponent1.2.h"
#include <winrt\RuntimeComponent1.h>
