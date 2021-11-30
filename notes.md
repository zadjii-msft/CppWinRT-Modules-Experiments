Start here:
* [C++ modules conformance #495](https://github.com/microsoft/cppwinrt/pull/495)


> The `cppwinrt.exe` compiler will now generate a `winrt/winrt.ixx` file that may be compiled as a module as follows:
>
> ```
> cl /c /I . /experimental:module /EHsc /bigobj /std:c++17 /await winrt/winrt.ixx
> ```
>
> This will compile all of the projected namespaces into a single `winrt` module. This step takes quite a while - around 2 minutes on my machine. But once that's built, much like a PCH, you can import the module into any (compatible) TU very quickly as follows:
>
> ```
> cl /experimental:module /EHsc /std:c++17 /await app.cpp winrt.obj
> ```

I'm not sure how I generated that the first time around. Just copy-pasta'd the implementation of cppwinrt from the Terminal project? probably.

--------------------------------------------------------------------------------




```bat
[ 9:19:44.22]>C:\Users\migrie\dev\scratch\PchSizeExperiments\ConsoleApp>
migrie@MIGRIE-SLAPTOP>cl /c /I "Debug\Generated Files" /experimental:module /EHsc /bigobj /std:c++17 /await "Debug\Generated Files\winrt\winrt.ixx"

cl  /JMC /experimental:module /Yu"pch.h" /GS /W4 /Zc:wchar_t /ZI /Gm- /Od /Zc:inline /fp:precise /D "_DEBUG" /D "_CONSOLE" /D "WIN32_LEAN_AND_MEAN" /D "WINRT_LEAN_AND_MEAN" /D "_UNICODE" /D "UNICODE" /errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /MDd /std:c++latest /FC /EHsc /nologo /Fo"x64\Debug\" /Fp"x64\Debug\pch.pch" /diagnostics:column  /await main.cpp winrt.obj


cl /experimental:module /Yu"pch.h" /Fp"x64\Debug\pch.pch" /EHsc /std:c++17 /await main.cpp winrt.obj

cl /experimental:module /D _DEBUG /D _CONSOLE /D WIN32_LEAN_AND_MEAN /D WINRT_LEAN_AND_MEAN /D _UNICODE /D UNICODE /Gm- /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /Yu"pch.h" /Fp"x64\Debug\pch.pch" /EHsc /std:c++17 /await main.cpp winrt.obj



CL.exe /c  /W4 /WX- /Od /D _DEBUG /D _CONSOLE /D WIN32_LEAN_AND_MEAN /D WINRT_LEAN_AND_MEAN /D _UNICODE /D UNICODE /Gm- /EHsc /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /std:c++latest /experimental:module /Yc"pch.h" /Fp"x64\Debug\pch.pch" /Fo"x64\Debug\\" /permissive- /bigobj /await /bigobj pch.cpp

CL.exe /c /D _DEBUG /D _CONSOLE /D WIN32_LEAN_AND_MEAN /D WINRT_LEAN_AND_MEAN /D _UNICODE /D UNICODE /Gm- /EHsc /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /std:c++latest /experimental:module /Yc"pch.h" /Fp"x64\Debug\pch.pch" /Fo"x64\Debug\\" /bigobj /await /bigobj pch.cpp


cl /c /experimental:module /D _DEBUG /D _CONSOLE /D WIN32_LEAN_AND_MEAN /D WINRT_LEAN_AND_MEAN /D _UNICODE /D UNICODE /Gm- /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /Yu"pch.h" /Fp"x64\Debug\pch.pch" /EHsc /std:c++latest /await main.cpp winrt.obj

```

These three did it:
```
cl /c /D _DEBUG /D _CONSOLE /D WIN32_LEAN_AND_MEAN /D WINRT_LEAN_AND_MEAN /D _UNICODE /D UNICODE /Gm- /EHsc /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /std:c++latest /experimental:module /Yc"pch.h" /Fp"x64\Debug\pch.pch" /Fo"x64\Debug\\" /bigobj /await /bigobj pch.cpp

cl /c /experimental:module /D _DEBUG /D _CONSOLE /D WIN32_LEAN_AND_MEAN /D WINRT_LEAN_AND_MEAN /D _UNICODE /D UNICODE /Gm- /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /Yu"pch.h" /Fp"x64\Debug\pch.pch" /EHsc /std:c++latest /await main.cpp

link /out:main.exe main.obj winrt.obj "x64\Debug\pch.obj"
```


```
cl /c /I . /D _DEBUG /experimental:module /D _UNICODE /D UNICODE /Gm- /EHsc /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /bigobj /std:c++17 /await winrt.ixx

cl /c /D _DEBUG /D _CONSOLE /D WIN32_LEAN_AND_MEAN /D WINRT_LEAN_AND_MEAN /D _UNICODE /D UNICODE /Gm- /EHsc /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /std:c++latest /experimental:module /Yc"pch.h" /Fp"x64\Debug\pch.pch" /Fo"x64\Debug\\" /bigobj /await /bigobj pch.cpp

cl /c /experimental:module /D _DEBUG /D _CONSOLE /D WIN32_LEAN_AND_MEAN /D WINRT_LEAN_AND_MEAN /D _UNICODE /D UNICODE /Gm- /fp:precise /Zc:wchar_t /Zc:forScope /Zc:inline /Yu"pch.h" /Fp"x64\Debug\pch.pch" /EHsc /std:c++latest /await main.cpp

link /out:main.exe main.obj winrt.obj "x64\Debug\pch.obj"

```

Curious,
```
cl /c /I . /experimental:module /EHsc /bigobj /std:c++17 /await winrt.ixx
```
Worked, but
```
cl /c /I . /D _DEBUG /experimental:module /EHsc /bigobj /std:c++17 /await winrt.ixx
```

Did _not_.




Okay, awesome. You can totally include headers in pch.h, AND modules. At least the WinRT module works.

* [x] Is compiling with `/std:c++latest` necessary, or would `/std:c++17` work?
  - Module: maybe? I think so? It moved the output from `x64\Release\CppWinRTModule\winrt.ixx.{obj,ifc}` instead to `$(SolutionDir)\CppWinRTModule\winrt.ifc` and `$(SolutionDir)\CppWinRTModule\x64\Release\winrt.obj`.
  - ModuleConsoleApp: totally fine.
* [ ] Update the module project to succeed when built. Right now it's still trying to build an exe
* [ ] Can I configure the module project to build successfully in Debug?
* [ ] update the module project to auto-generate contents in `winrt/`. I had to copypasta those manually
* [x] Create a helper `.props` for including the winrt module project in another project. Including things like the `AdditionalModuleDefinitions` and the `obj` file thing
* [ ] Can I make my own library module? e.g. for `TerminalControl`. That's probably overkill now, but will be important for something like TerminalApp, which imports `winrt` and `TerminalControl`
  - This is proving to be much harder than I anticipated. It's unclear how to create a module that uses winrt, that can also be consumed by another project that uses `winrt`.
    - The VS system for referencing modules from other projects is useless.
    - I keep getting `fatal error C1117: unrecoverable error importing module ... IInspectable already defined`, which is a fatal compiler error that totally blocks me.
    - I'm going to need someone's official help here. Too bad there's no one on the cppwinrt team to help with that.
* [ ] Can I include this madness in the Samples.sln in the Terminal? Because that would be an e2e PoC.

```
MSVC\14.28.29910\bin\HostX86\x64\CL.exe /c /Zi /nologo /W3 /WX- /diagnostics:column /sdl /O2 /Oi /GL /D NDEBUG /D _CONSOLE /D _CONSOLE /D WIN32_LEAN_AND_MEAN /D WINRT_LEAN_AND_MEAN /D _UNICODE /D UNICODE /Gm- /EHsc /MD /GS /Gy /fp:precise /permissive- /Zc:wchar_t /Zc:forScope /Zc:inline /std:c++17 /experimental:module /stdIfcDir "C:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\VC\Tools\MSVC\14.28.29910\ifc\x64" /Fo"x64\Release\\" /Fd"x64\Release\vc142.pdb" /Gd /TP /FC /errorReport:prompt  /permissive- /bigobj /await winrt.ixx
1>

MSVC\14.28.29910\bin\HostX86\x64\link.exe /ERRORREPORT:PROMPT /OUT:"C:\Users\migrie\dev\scratch\PchSizeExperiments\x64\Release\CppWinRTModule.exe" /INCREMENTAL:NO /NOLOGO kernel32.lib user32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /MANIFEST /MANIFESTUAC:"level='asInvoker' uiAccess='false'" /manifest:embed /DEBUG /PDB:"C:\Users\migrie\dev\scratch\PchSizeExperiments\x64\Release\CppWinRTModule.pdb" /SUBSYSTEM:CONSOLE /OPT:REF /OPT:ICF /LTCG:incremental /LTCGOUT:"x64\Release\CppWinRTModule.iobj" /TLBID:1 /DYNAMICBASE /NXCOMPAT /IMPLIB:"C:\Users\migrie\dev\scratch\PchSizeExperiments\x64\Release\CppWinRTModule.lib" /MACHINE:X64 x64\Release\winrt.obj
```

okay there's nothing in that build commandline that indicates where the `ifc` and `obj` are going to land. Nuts.


--------------------------------------------------------------------------------
End of original notes.


z 30-Nov-2021

* Created new solution directory.
* Created a new Console Application.
  - Set it to C++20 `/std:c++20` and toolset `v143`
* Copy the `CppWinRTModule` directory into that solution.
* In `CppWinRTModule`, run: `cl /c /I . /experimental:module /EHsc /bigobj /std:c++17 /await winrt.ixx`
  - There are some warnings, about `CppWinRTModule\winrt/base.h(101): warning C5244: '#include <WindowsNumerics.impl.h>' in the purview of module 'winrt' appears erroneous`
  - This produces a 229,877,076B `winrt.ifc` and 158,347,308B `winrt.obj` (229MB and 158MB respectively).
* Add the module's `.ifc` to the `ClCompile.AdditionalModuleDependencies`, and the `.obj` to the `Link.AdditionalDependencies`
