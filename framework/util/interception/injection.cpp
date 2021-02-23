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

#include "injection.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(interception)

static void* target_memory_address_ = nullptr;

static bool LoadDllIntoTargetProcess(HANDLE target_proc_handle)
{
    // TODO: LoadLibraryW will fail since everything else in this file is ASCII
    bool ret_val = false;

    HMODULE handle          = GetModuleHandle(TEXT("kernel32.dll"));
    FARPROC fp_load_library = nullptr;

    if (handle != nullptr)
    {
        fp_load_library = GetProcAddress(handle, "LoadLibraryA");

        if (fp_load_library != nullptr)
        {
            HANDLE remote_thread_handle = nullptr;
            DWORD  remote_thread_id     = 0;

            // Create a remote thread that loads the DLL into the target process:
            remote_thread_handle = CreateRemoteThread(target_proc_handle,
                                                      nullptr,
                                                      0,
                                                      reinterpret_cast<LPTHREAD_START_ROUTINE>(fp_load_library),
                                                      target_memory_address_,
                                                      0,
                                                      &remote_thread_id);

            if (remote_thread_handle != nullptr)
            {
                // Wait for the thread to end its task:
                WaitForSingleObject(remote_thread_handle, INFINITE);

                // Get the thread exit code:
                // (This is actually the LoadLibrary return code)
                DWORD thread_exit_code = 0;
                BOOL  rc               = GetExitCodeThread(remote_thread_handle, static_cast<LPDWORD>(&thread_exit_code));

                if (rc)
                {
                    // If the remote LoadLibrary succeeded:
                    if (thread_exit_code != 0)
                    {
                        ret_val = true;
                    }
                }

                // Clean up:
                CloseHandle(remote_thread_handle);
            }
        }
    }

    return ret_val;
}

static bool AllocateSpaceForInjectedMemory(HANDLE target_proc_handle, size_t size_of_memory_to_inject)
{
    target_memory_address_ = VirtualAllocEx(
        target_proc_handle, nullptr, size_of_memory_to_inject, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);

    return target_memory_address_ != nullptr;
}

static bool InjectMemory(HANDLE target_proc_handle, LPCSTR dll_path, size_t size_of_memory_to_inject)
{
    bool ret_val = false;

    // Verify that we have allocated space for the memory to inject:
    if (target_memory_address_)
    {
        // Inject the memory into the target process:
        SIZE_T number_of_bytes_written = 0;

        int rc = WriteProcessMemory(
            target_proc_handle, target_memory_address_, dll_path, size_of_memory_to_inject, &number_of_bytes_written);
        ret_val = ((rc != 0) && (number_of_bytes_written == size_of_memory_to_inject));
    }

    return ret_val;
}

static bool InjectDllPathIntoTargetProcess(HANDLE target_proc_handle, LPCSTR dll_path)
{
    bool ret_val = false;

    size_t size_of_memory_to_inject = strlen(dll_path);

    if (size_of_memory_to_inject > 0)
    {
        ret_val = AllocateSpaceForInjectedMemory(target_proc_handle, size_of_memory_to_inject);

        if (ret_val)
        {
            ret_val = InjectMemory(target_proc_handle, dll_path, size_of_memory_to_inject);
        }
    }

    return ret_val;
}

bool InjectDllIntoProcess(LPCSTR dll_path, HANDLE process_handle)
{
    bool ret_val = InjectDllPathIntoTargetProcess(process_handle, dll_path);

    if (ret_val)
    {
        ret_val = LoadDllIntoTargetProcess(process_handle);
    }

    return ret_val;
}

bool LaunchAndInjectA(LPCSTR                application_name,
                      LPSTR                 command_line,
                      LPSECURITY_ATTRIBUTES process_attributes,
                      LPSECURITY_ATTRIBUTES thread_attributes,
                      BOOL                  inherit_handles,
                      DWORD                 creation_flags,
                      LPVOID                environment,
                      LPCSTR                current_directory,
                      LPSTARTUPINFOA        startup_info,
                      LPPROCESS_INFORMATION process_information)
{
    bool ret_val = true;

    CreateProcessA(
        application_name,
        command_line,
        process_attributes,
        thread_attributes,
        inherit_handles,
        creation_flags,
        environment,
        current_directory,
        startup_info,
        process_information);

    InjectDllIntoProcess(GFXR_INTERCEPTOR_PATH, process_information->hProcess);

    ResumeThread(process_information->hThread);

    return ret_val;
}

bool LaunchAndInjectW(LPCWSTR               application_name,
                      LPWSTR                command_line,
                      LPSECURITY_ATTRIBUTES process_attributes,
                      LPSECURITY_ATTRIBUTES thread_attributes,
                      BOOL                  inherit_handles,
                      DWORD                 creation_flags,
                      LPVOID                environment,
                      LPCWSTR               current_directory,
                      LPSTARTUPINFOW        startup_info,
                      LPPROCESS_INFORMATION process_information)
{
    bool ret_val = true;

    CreateProcessW(
        application_name,
        command_line,
        process_attributes,
        thread_attributes,
        inherit_handles,
        creation_flags,
        environment,
        current_directory,
        startup_info,
        process_information);

    InjectDllIntoProcess(GFXR_INTERCEPTOR_PATH, process_information->hProcess);

    ResumeThread(process_information->hThread);

    return ret_val;
}

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
