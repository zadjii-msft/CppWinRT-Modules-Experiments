# Scenarios


This is a list of various samples we could create, with both `pch`'s and modules, to make sure that modules is on par with the pch version (which works today). 


* `01-SimpleConsoleApp`: This is basically the "hello world" for winrt. Create a `Uri`, and print the `Domain`.
* `02-SimpleAsyncAction`: This is a simple console app to demonstrate async in winrt. This is taken from the PR body of [microsoft/cppwinrt/953].
* `03-SimpleCustomComponent`: A WinRT library (`.dll`) that authors a custom WinRT type, which can be used in other WinRT projects.
* `04-CustomConsoleApp`: Basically the hello-world project, but also consuming a type we authored in `03-SimpleCustomComponent`.
* `05-SimpleXamlApp`: Display a simple window with a button, using system XAML.
* `06-CustomXamlApp`: Display a simple window with a button, using system XAML, consuming the type authored in `03-SimpleCustomComponent`
* `07-SimpleWinUiApp`: Display a simple window with a button, using WinUI 3.0.
* `08-CustomWinUiApp`: Display a simple window with a button, using WinUI 3.0, consuming the type authored in `03-SimpleCustomComponent`
* `09-SeparateLibComponent`: _This one I'm on the fence about_. This is a custom WinRT type that we author as a split `lib`&`dll`. This would allow the component's implementation to be re-linked in another `dll` (like a unit test dll), and have the component be consumed in another winrt project, like `04`.
  - We already have enough trouble with projects split like this for the Terminal, so I'm gonna leave this one optional

This should be comprehensive enough that it would cover all the pure C++/WinRT use cases with modules. I'm sure there's other stranger edge cases, but this should be enoguh to give the 👍


#### Current progress [████████▒▒________]

Project                    | `pch.h` state | modules state | notes
---------------------------|---------------|---------------|---------------
`01-SimpleConsoleApp`      | ✔ | ✔ |
`02-SimpleAsyncAction`     | ✔ | ⚠️ | [microsoft/cppwinrt/953] nearly fixed this. Needs another patch to work around a compiler issue. See also [02-SimpleAsyncAction/notes.md](./02-SimpleAsyncAction/notes.md), especially the tl;dr.
`03-SimpleCustomComponent` | ✔ | ⚠️/❌ | See [03-SimpleCustomComponent/README.md](./03-SimpleCustomComponent/README.md). WinRT patches mostly fix this, but if you want to export this component as a module for later re-use, that I haven't gotten right yet.
`04-CustomConsoleApp`      | ✔ | ⚠️/❌ | Module version of exe blocked on module version of _component_ (03) building successfully. Works when it doesn't consume the `SimpleCustomComponent` module, with cppwinrt patches.
`05-SimpleXamlApp`         | 📝 | 📝 |
`06-CustomXamlApp`         | todo | todo |
`07-SimpleWinUiApp`        | todo | todo |
`08-CustomWinUiApp`        | todo | todo |
`09-SeparateLibComponent`  | todo | todo |

* 📝: In progress
* ✔: Complete, works.
* ❌: Authored, with errors
* ⚠️: Complete, works, but with a cppwinrt patch.
* 🛑: blocked on finishing for some reason

### Current status

<!-- _12/14/2021_: Scenarios 01-04 seem to work as modules, using a custom built `cppwinrt.exe`. To build the solution:
* Clone the cppwinrt repro.
* Checkout `origin/user/sjones/modules` in the cppwinrt repo
* run `build_nuget.cmd 2.3.4.5`. If this generates a package with version 1.0.0, then you'll need to re-run the last command (`nuget pack ...`) with the additional `-Version 2.3.4.5` flag.
* copy `cppwinrt\Microsoft.Windows.CppWinRT.2.3.4.5.nupkg` to a `scenarios/PackageStore/Microsoft.Windows.CppWinRT.2.3.4.5.nupkg`.
* run a `nuget restore` in the `scenarios/` directory


Hopefully this shouldn't be _necessary_ - the updated versions of the headers should already be checked-in to the repo. In the future, we'll be using this as the workflow so we can ingest official updated cppwinrt builds.
-->

_12/15/2021_: The custom patched cppwinrt.exe should be in the `nupkg` that ships with the repo now.

The `{Debug|Release}{Mod|Pch}` Configurations allow for you to quickly build either all the Module projects or the pch projects. The plain old `{Debug|Release}` configurations will still just build them all.

### todos:

* [x] I made an absolutely stupid choice with the naming here.
  - The `01-`'s at the start really mess with the templates. They hate that, and the `RootNamespace`s are all messed up.
  -  When compiling `03`, you'll get 3 things: `03-SimpleCustomComponentPch.dll`, `03-SimpleCustomComponentMod.dll`, and `SimpleCustomComponent.winmd`. These are bad, because to unpackaged initialize WinRT, the types for `SimpleCustomComponent.winmd` need to be in `SimpleCustomComponent.dll`, so the you need to manually copypasta the implementation you want to test.
  - That shouldn't be too hard to fix.
  - put the output in `{mod or pch}\$(RootNamespace).dll`, so we can do the SxS thing correctly.
* [x] I should check if the cppwinrt compiler from [microsoft/cppwinrt/953] fixes the module version of `02-SimpleAsyncAction`.
  - It does, with minor other alterations.
* [x] The `name_of` thing mentioned in [microsoft/cppwinrt/953]. Perhaps we can figure that one out?
  - This one seems to be a compiler/linker bug. There's a minimal repro in `02-SimpleAsyncAction/main.cpp`.
* [ ] Mike was able to work with just a ProjectReference to the Module project, but Scott needed to manually reference the `.ifc` (etc). There's some tooling gap here?
* [ ] Collect performance numbers for pch usage vs module usage
  - disk space for a complete `#include <Windows.*>` pch vs the winrt module
    - Including the entirety of Windows.UI.XAML is important
  - Compile time for an exe consuming the module vs one consuming a pch
  - How many projects in a solution does it take for the module to be faster than the pch?
    - how long does a single component take for module vs pch
  - exe & dll sizes for module vs pch
* [ ] Edit `04-CustomConsoleApp/mod` to consume the _module_ created by `03-SimpleCustomComponent`.
  - THIS DIDN'T WORK. Notes are in [03-SimpleCustomComponent/README.md](./03-SimpleCustomComponent/README.md)
* [ ] Import the WUX app from the `sample-wux-app` branch
* [ ] Do we need a sample for a exe that consumes `Foo` which also consumes `Bar` which consumes `winrt`, so there's stacked dependencies here? Or is `04` a good enough example for this?

### Benchmarks

See [Benchmarks](./benchmarks.md) for build speed comparisons.

### Work for 2022:

* [ ] Compiler fix for `resume_apartment_context` bug?
  - [identifier not found, with default member initializer and global module fragment]
  - cppwinrt may be able to work around this.
* [ ] Compiler fix for async/`name_of` bug?
  - [Use of modules with C++/WinRT winrt::impl::name_v causes ICEs and/or runtime errors]
* [ ] VS Tooling fix for needing to manually reference the module outputs?
* [ ] Change to cppwinrt to ingest [microsoft/cppwinrt/953].
* [ ] Change to cppwinrt to export additional `winrt::impl` templates in `base.h`, for component authoring
  - Alternatively, adjust winrt to produce two modules, one for just consuming winrt, another for authoring new components.
* [ ] Change to cppwinrt tooling to accomodate consuming the module when authoring components
* [ ] Change to XAML codegen to accomodate consuming a module when authoring types
  - No LoS on this quite yet.




[Use of modules with C++/WinRT winrt::impl::name_v causes ICEs and/or runtime errors]: https://developercommunity.visualstudio.com/t/use-of-modules-with-cwinrt-winrtimplname-v-causes/1613181?from=email
[identifier not found, with default member initializer and global module fragment]: https://developercommunity.visualstudio.com/t/identifier-not-found-with-default-membe/1376824

[microsoft/cppwinrt/953]: https://github.com/microsoft/cppwinrt/pull/953
