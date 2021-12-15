# Benchmarks

This branch is used for trying to compare build times for the modules and the PCH versions of our scenarios here.


## Directions

Start by opening a VS Dev Command Prompt. 

To measure how long the modules build takes: 
```
msbuild /bl:dbgmodx64.binlog /t:rebuild /p:platform=x64;configuration=debugmod Scenarios.sln
```

For the PCH build:
```
msbuild /bl:dbgpchx64.binlog /t:rebuild /p:platform=x64;configuration=debugpch Scenarios.sln
```


## Variations

_Terminology_: When I refer to 4 projects, I mean the first 4 building scenarios:

> * `01-SimpleConsoleApp`: This is basically the "hello world" for winrt. Create a `Uri`, and print the `Domain`.
> * `02-SimpleAsyncAction`: This is a simple console app to demonstrate async in winrt. This is taken from the PR body of [microsoft/cppwinrt/953].
> * `03-SimpleCustomComponent`: A WinRT library (`.dll`) that authors a custom WinRT type, which can be used in other WinRT projects.
> * `04-CustomConsoleApp`: Basically the hello-world project, but also consuming a type we authored in `03-SimpleCustomComponent`.

For the variations with more projects, I'm just copy-pasting the `02-SimpleAsyncAction` project additional times, to create more copies of it in the repo.

The "Full" projection is one that includes all of the cppwinrt headers that ship as a part of the platform projection.

The "minimal" projection is just `Windows.Foundation.h`, `Windows.Foundation.Collections.h`, `Windows.Web.h`, and `Windows.Web.Syndication.h`, which were all that's actually needed for these simple test projects.

### 4 projects, full winrt projection in both PCH and module

Build  | Projection | time    | average
-------|------------|---------|--------
PCH    | Full       | 3:59.32 |
PCH    | Full       | 4:10.24 |
PCH    | Full       | 3:57.66 |
PCH    | Full       |         | 4:02.41
Module | Full       | 2:42.32 |
Module | Full       | 2:38.57 |
Module | Full       | 2:48.47 |
Module | Full       |         | 2:43.12
PCH    | Minimal    | 0:23.20 |
PCH    | Minimal    | 0:23.98 |
PCH    | Minimal    | 0:24.47 |
PCH    | Minimal    |         | 4:02.41
Module | Minimal    | 0:21.67 |
Module | Minimal    | 0:20.25 |
Module | Minimal    | 0:19.52 |
Module | Minimal    |         | 4:02.41


### 5 projects, full winrt projection in both PCH and module

### 10 projects, full winrt projection in both PCH and module

### 4 projects, minimal winrt projection in both PCH and module

### 4 projects, full projection in module, minimal winrt projection PCH

### Single project, full projections

### Single project, minimal projections


[microsoft/cppwinrt/953]: https://github.com/microsoft/cppwinrt/pull/953
