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


#### Current progress

Project                    | `pch.h` state | modules state | notes
---------------------------|---------------|---------------|---------------
`01-SimpleConsoleApp`      | ✔ | ✔ |
`02-SimpleAsyncAction`     | ✔ | ❌ |
`03-SimpleCustomComponent` | ✔ | 📝 |
`04-CustomConsoleApp`      | ✔ | 📝 | Works, but you have to `copy 03-SimpleCustomComponentPch.dll SimpleCustomComponent.dll`, so it can SxS init the winrt type.
`05-SimpleXamlApp`         | todo | todo |
`06-CustomXamlApp`         | todo | todo |
`07-SimpleWinUiApp`        | todo | todo |
`08-CustomWinUiApp`        | todo | todo |
`09-SeparateLibComponent`  | todo | todo |

* 📝: In progress
* ✔: Complete, works.
* ❌: Authored, with errors
* 🛑: blocked on finishing for some reason

* [ ] I made an absolutely stupid choice with the naming here.
  - The `01-`'s at the start really mess with the templates. They hate that, and the `RootNamespace`s are all messed up.
  -  When compiling `03`, you'll get 3 things: `03-SimpleCustomComponentPch.dll`, `03-SimpleCustomComponentMod.dll`, and `SimpleCustomComponent.winmd`. These are bad, because to unpackaged initialize WinRT, the types for `SimpleCustomComponent.winmd` need to be in `SimpleCustomComponent.dll`, so the you need to manually copypasta the implementation you want to test.
  - That shouldn't be too hard to fix.

[microsoft/cppwinrt/953]: https://github.com/microsoft/cppwinrt/pull/953
