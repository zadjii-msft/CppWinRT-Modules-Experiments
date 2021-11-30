module;

#include "pch.h"

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
// #include <winrt\base.h>
// #include <winrt\RuntimeComponent1.h>

// export module WinRTComponent;

// import winrt;
// export namespace winrt::RuntimeComponent1
// {
//     struct IClass;
//     struct Class;
// };

// #include "winrt/base.h"
// #define WINRT_EXPORT export
// #include "winrt/impl/WinRTComponent.2.h"

// Attempt 1: ------------------------------------------------------------------
//
// export module WinRTComponent;
// import winrt;
// #include <winrt\WinRTComponent.h>
//
// Including this leads to duplicate  _everything_ in numerics. Presumably via base.h

// Attempt 2: ------------------------------------------------------------------
//
// export module WinRTComponent;
// import winrt;
// #include "winrt/impl/WinRTComponent.2.h"
//
// This lead to a compiler error!
//   1>D:\dev\scratch\ModulesExperiments\ModulesExperiments\WinRTComponent\Generated
//   Files\winrt\impl\WinRTComponent.0.h(6,14): error C2143: syntax error:
//   missing ';' before 'namespace'
//

// Attempt 3: ------------------------------------------------------------------
//
// export module WinRTComponent;
// import winrt;
// #define WINRT_EXPORT export
// #include "winrt/impl/WinRTComponent.2.h"
//
// This too lead to a compiler error, this time
//   1> D:\dev\scratch\ModulesExperiments\ModulesExperiments\WinRTComponent\Generated
//   Files\winrt\impl\WinRTComponent.0.h(13,32): error C3856: 'category': symbol
//   is not a class template
//   1> D:\dev\scratch\ModulesExperiments\ModulesExperiments\WinRTComponent\Generated
//   Files\winrt\impl\WinRTComponent.0.h(13,24): error C2143: syntax error:
//   missing ';' before 'winrt::WinRTComponent::IClass'

// Attempt 4: ------------------------------------------------------------------
//
// export module WinRTComponent;
// import winrt;
// #include "winrt/base.h"
// #define WINRT_EXPORT export
// #include "winrt/impl/WinRTComponent.2.h"
//
// This leads to the numerics thing again.

// Attempt 5: ------------------------------------------------------------------
//
// export module WinRTComponent;
// #include "winrt/base.h"
// #define WINRT_EXPORT export
// #include "winrt/impl/WinRTComponent.2.h"
//
// Interesting. That's a bunch of new ones:
//   1>WinRTComponent.ixx.obj : error LNK2019: unresolved external symbol
//   WINRT_IMPL_CoCreateInstance::<!WinRTComponent> referenced in function "int
//   __cdecl winrt::impl::fallback_RoGetAgileReference(unsigned int,struct
//   winrt::guid const &,void *,void * *)"
//   (?fallback_RoGetAgileReference@impl@winrt@@YAHIAEBUguid@2@PEAXPEAPEAX@Z::<!WinRTComponent>)
//
//   1>WinRTComponent.ixx.obj : error LNK2019: unresolved external symbol
//   WINRT_IMPL_CoGetCallContext::<!WinRTComponent> referenced in function
//   "public: static struct winrt::access_token __cdecl
//   winrt::access_token::client(void)"
//   (?client@access_token@winrt@@SA?AU12@XZ::<!WinRTComponent>)
//
//   1>WinRTComponent.ixx.obj : error LNK2019: unresolved external symbol
//   WINRT_IMPL_CoGetObjectContext::<!WinRTComponent> referenced in function
//   "__cdecl winrt::impl::resume_apartment(struct
//   winrt::impl::resume_apartment_context const &,struct
//   std::experimental::coroutine_handle<void>)"
//   (?resume_apartment@impl@winrt@@YA@AEBUresume_apartment_context@12@U?$coroutine_handle@X@experimental@std@@@Z::<!WinRTComponent>)
//
//   1>WinRTComponent.ixx.obj : error LNK2019: unresolved external symbol
//   WINRT_IMPL_IIDFromString::<!WinRTComponent> referenced in function "public:
//   static __cdecl winrt::impl::natvis::abi_val(void *,wchar_t const *,int)"
//   (?abi_val@natvis@impl@winrt@@SA@PEAXPEB_WH@Z::<!WinRTComponent>)
//
// These are linker errors, which would imply that we aren't linking with Ole32.lib

//
// After switching the module project to being a lib, it seemed to compile just
// fine. However, this really does raise a question. The headers that are
// consumed should be the projections of these types, and I think including
// impl/WinRTComponent is going to be the implementation half of the types. We
// want the projection.
//

// Attempt 6: ------------------------------------------------------------------
//
// export module WinRTComponent;
// #include "winrt/base.h"
// #define WINRT_EXPORT export
// #include "winrt/WinRTComponent.h"
//
// Tons of unresolved externals, when we're compiling the
// ConsoleAppWithCustomComponent. No idea what these even mean.
/*
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2001: WINRT_abi_val
3>winrt.ixx.obj : error LNK2001: WINRT_abi_val
3>main.obj : error LNK2001: WINRT_abi_val
3>main.obj : error LNK2001: WINRT_abi_val
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2001: WINRT_abi_val
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2001: WINRT_get_val
3>winrt.ixx.obj : error LNK2001: WINRT_get_val
3>main.obj : error LNK2001: WINRT_get_val
3>main.obj : error LNK2001: WINRT_get_val
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2001: WINRT_get_val
3>main.obj : error LNK2019: unresolved external symbol "public: __cdecl winrt::WinRTComponent::Class::Class(void)" (??0Class@WinRTComponent@winrt@@QEAA@XZ::<!WinRTComponent>) referenced in function main
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2019: unresolved external symbol WINRT_IMPL_CoCreateInstance::<!WinRTComponent> referenced in function "int __cdecl winrt::impl::fallback_RoGetAgileReference(unsigned int,struct winrt::guid const &,void *,void * *)" (?fallback_RoGetAgileReference@impl@winrt@@YAHIAEBUguid@2@PEAXPEAPEAX@Z::<!WinRTComponent>)
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2001: WINRT_IMPL_CoCreateInstance::<!WinRTComponent>
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2019: unresolved external symbol WINRT_IMPL_CoGetCallContext::<!WinRTComponent> referenced in function "public: static struct winrt::access_token __cdecl winrt::access_token::client(void)" (?client@access_token@winrt@@SA?AU12@XZ::<!WinRTComponent>)
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2001: WINRT_IMPL_CoGetCallContext::<!WinRTComponent>
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2019: unresolved external symbol WINRT_IMPL_CoGetObjectContext::<!WinRTComponent> referenced in function "__cdecl winrt::impl::resume_apartment(struct winrt::impl::resume_apartment_context const &,struct std::experimental::coroutine_handle<void>)" (?resume_apartment@impl@winrt@@YA@AEBUresume_apartment_context@12@U?$coroutine_handle@X@experimental@std@@@Z::<!WinRTComponent>)
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2001: WINRT_IMPL_CoGetObjectContext::<!WinRTComponent>
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2019: unresolved external symbol WINRT_IMPL_IIDFromString::<!WinRTComponent> referenced in function "public: static __cdecl winrt::impl::natvis::abi_val(void *,wchar_t const *,int)" (?abi_val@natvis@impl@winrt@@SA@PEAXPEB_WH@Z::<!WinRTComponent>)
3>WinRTComponentModule.lib(WinRTComponent.ixx.obj) : error LNK2001: WINRT_IMPL_IIDFromString::<!WinRTComponent>
*/

// Attempt 7: ------------------------------------------------------------------
//
// export module WinRTComponent;
// #define WINRT_EXPORT export
// #include "winrt/WinRTComponent.h"
//
// When compiling the ConsoleAppWithCustomComponent, we'll get something like:
/*
ConsoleAppWithCustomComponent\main.cpp(20,19): fatal error C1117: unrecoverable error importing module 'WinRTComponent': symbol 'apartment_type' has already been defined
*/
// Comment that line out, and it'll just complain about hstring next.
// That seems to imply that both modules are exporting the same thing? (conjecture)
// BUT, if you comment out the winrt module, then it can't find Windows::Foundation::Uri, so that's clearly needed for something...

// Attempt 8: ------------------------------------------------------------------
//
// import winrt;
// export module WinRTComponent;
// #include "winrt/WinRTComponent.h"
//
// Nope, just more duplicated numerics things again.

// Attempt 9: ------------------------------------------------------------------
//
// import winrt;
// export module WinRTComponent;
// #define WINRT_EXPORT export
// #include "winrt/WinRTComponent.h"
//
//

// Attempt 10: ------------------------------------------------------------------
//
import winrt;
export module WinRTComponent;
#define WINRT_EXPORT export
#include "winrt/WinRTComponent.h"
//
//
