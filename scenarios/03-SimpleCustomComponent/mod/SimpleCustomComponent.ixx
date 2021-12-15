module;

#define WINRT_IMPL_SHIM(...) (*(abi_t<__VA_ARGS__>**)&static_cast<__VA_ARGS__ const&>(static_cast<D const&>(*this)))

#ifdef __INTELLISENSE__
#define WINRT_IMPL_AUTO(...) __VA_ARGS__
#else
#define WINRT_IMPL_AUTO(...) auto
#endif

export module SimpleCustomComponent;

import winrt;

#define WINRT_EXPORT export

#include "winrt/SimpleCustomComponent.h"
