#pragma once

#ifndef SHARED_LIB_H
#define SHARED_LIB_H

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <array>

#include <fstream>
#include <string>
#include <chrono>
#include <optional>
#include <thread>
#include <map>

#ifdef _WIN32 // windows
#ifndef OS_WINDOWS
#define OS_WINDOWS
#endif
#include <conio.h>
#include <windows.h>
#include <string>
#elif defined(linux) // linux
#ifndef OS_LINUX
#define OS_LINUX
#endif
#include <string.h>
#include <math.h>
#endif // _WIN32

#include "../VM/include/lua.h"
#include "../VM/include/lualib.h"
#include "../Compiler/include/Luau/Compiler.h"
#include "Coverage.h"
#include "FileUtils.h"

using namespace std;

#ifdef __cplusplus
extern "C"
{
#endif

#define SHARED_LIB __declspec(dllexport)

    unsigned long SHARED_LIB InternalNewState();
    void SHARED_LIB InternalCompile(const char* code, char* result); 
    bool SHARED_LIB InternalRun(unsigned long stateId, const char* compiledCode, char* result);

#ifdef __cplusplus
}
#endif

#endif // end of DLL