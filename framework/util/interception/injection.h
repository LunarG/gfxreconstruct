/*
** Copyright (c) 2021 Advanced Micro Devices, Inc. All rights reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_INTERCEPTION_UTILS_INJECTION_H
#define GFXRECON_INTERCEPTION_UTILS_INJECTION_H

#include "util/defines.h"

#include <Windows.h>
#include <string>

/// Encapsulate app data for CreateProcess()
struct CreateProcessInfo
{
    std::string app_path;
    std::string app_path_plus_args;
    std::string app_dir;
};

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(interception)

//----------------------------------------------------------------------------
/// Loads the DLL into the target process.
/// \param target_proc_handle Handle to target application process
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
static bool LoadDllIntoTargetProcess(HANDLE target_proc_handle);

//----------------------------------------------------------------------------
/// Allocated memory that will contain the injected memory.
/// This memory will be accessible by the target process.
/// \param target_proc_handle Handle to target application process
/// \param size_of_memory_to_inject Size of memory to inject, in bytes
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
static bool AllocateSpaceForInjectedMemory(HANDLE target_proc_handle, size_t size_of_memory_to_inject);

//----------------------------------------------------------------------------
/// Injects the memory into the target process.
/// This function should be called after allocateSpaceForInjectedMemory()
/// was called.
/// \param target_proc_handle Handle to target application process
/// \param dll_path Full path and name of dll to be injected
/// \param size_of_memory_to_inject Size of memory to inject, in bytes
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
static bool InjectMemory(HANDLE target_proc_handle, LPCSTR dll_path, size_t size_of_memory_to_inject);

//----------------------------------------------------------------------------
/// Injects the DLL path into the target process.
/// \param target_proc_handle Handle to target application process
/// \param dll_path Full path and name of dll to be injected
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
static bool InjectDllPathIntoTargetProcess(HANDLE target_proc_handle, LPCSTR dll_path);

//----------------------------------------------------------------------------
/// Loads the DLL into the target process via a process handle
/// \param dllPath Full path and name of dll to be injected
/// \param process_handle Handle to target application process into.
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool InjectDllIntoProcess(LPCSTR dll_path, HANDLE process_handle);

//----------------------------------------------------------------------------
/// Launch an application and inject our DLLs into it
/// \param application_name Application name
/// \param command_line Command line
/// \param process_attributes Process attributes
/// \param thread_attributes Thread attributes
/// \param inherit_handles Inherit handles flag
/// \param creation_flags flags
/// \param environment Environment
/// \param current_directory Current directory
/// \param startup_info Startup info
/// \param process_information Process info
/// \return True or false
//----------------------------------------------------------------------------
bool LaunchAndInjectA(LPCSTR                lpApplicationName,
                      LPSTR                 lpCommandLine,
                      LPSECURITY_ATTRIBUTES lpProcessAttributes,
                      LPSECURITY_ATTRIBUTES lpThreadAttributes,
                      BOOL                  bInheritHandles,
                      DWORD                 dwCreationFlags,
                      LPVOID                lpEnvironment,
                      LPCSTR                lpCurrentDirectory,
                      LPSTARTUPINFOA        lpStartupInfo,
                      LPPROCESS_INFORMATION lpProcessInformation);

//----------------------------------------------------------------------------
/// Launch an application and inject our DLLs into it
/// \param application_name Application name
/// \param command_line Command line
/// \param process_attributes Process attributes
/// \param thread_attributes Thread attributes
/// \param inherit_handles Inherit handles flag
/// \param creation_flags flags
/// \param environment Environment
/// \param current_directory Current directory
/// \param startup_info Startup info
/// \param process_information Process info
/// \return True or false
//----------------------------------------------------------------------------
bool LaunchAndInjectW(LPCWSTR               lpApplicationName,
                      LPWSTR                lpCommandLine,
                      LPSECURITY_ATTRIBUTES lpProcessAttributes,
                      LPSECURITY_ATTRIBUTES lpThreadAttributes,
                      BOOL                  bInheritHandles,
                      DWORD                 dwCreationFlags,
                      LPVOID                lpEnvironment,
                      LPCWSTR               lpCurrentDirectory,
                      LPSTARTUPINFOW        lpStartupInfo,
                      LPPROCESS_INFORMATION lpProcessInformation);

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_INTERCEPTION_UTILS_INJECTION_H
