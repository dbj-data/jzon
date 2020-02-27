# JZON 

> Original repo: https://github.com/vivkin/jzon

- Does not use std lib
  - only CRT headers
- No exceptions
- No iostream
  - only one `fwrite` call
- Small
- Fast

## Using

- This is header only C++17. 
- Best use as a git sub-module.

## Building the Tests

- Tests are in the `sampling` folder
  - using `dbj nanolib`, installed as sub-module
- please look into the .vscode folder
  - change in accordance with your machine
  - no exceptions are used
- using the latest cl 
  - Microsoft (R) C/C++ Optimizing Compiler Version 19.24.28316 for x64 
- Using Visual Leak Detector
  - In case you do not want ["Visual Leak Detector"](https://kinddragon.github.io/vld/), just simply do not include <vld.h>
  - otherwise vld has to be installed so that its dll is found at runtime

---

> Work in this repo (c) 2019/2020 by dbj@dbj.org
> 
> [Licence: CC BY SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/)

