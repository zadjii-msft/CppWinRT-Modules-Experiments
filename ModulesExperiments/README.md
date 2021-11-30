# Modules Experiments, Attempt 2


My second go at working with cppwinrt and modules. 


* [`CppWinRTModule`](./CppWinRTModule): This is a project that builds a module for all of the platform winrt hearders. It's chonky, but substantially smaller than pch.pch's, and way better than having one per-project.
* [`BasicConsoleApplication`](./BasicConsoleApplication): An example console app that uses the winrt module above. This works.
* [`WinRTComponent`](./WinRTComponent): This is where it starts to break down. `WinRTComponent` is supposed to be a dead-simple winrt component. A single class, with a single property. It should be able to be re-used in other projects, and ideally should consume the module version of cppwinrt, so we don't need giant pch's.
* [`WinRTComponentModule`](./WinRTComponentModule): This is really just a test - it's a project that _just_ builds a module from the `WinRTComponent`. This doesn't seem to really work as I hoped.
* [`ConsoleAppWithCustomComponent`](./ConsoleAppWithCustomComponent): This one's just like the `BasicConsoleApplication`, but it should be able to consume both SDK winrt types (like `Windows::Foundation::Uri`) and the winrt types we authored in `WinRTComponent` (e.g. `WinRTComponent::Class`). This currently doesn't seem to build at all.


That's where I'm at now.
