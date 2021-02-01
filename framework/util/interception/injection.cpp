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

//----------------------------------------------------------------------------
/// Loads the DLL into the target process.
/// \param target_proc_handle Handle to target application process
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
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

//----------------------------------------------------------------------------
/// Allocated memory that will contain the injected memory.
/// This memory will be accessible by the target process.
/// \param target_proc_handle Handle to target application process
/// \param size_of_memory_to_inject Size of memory to inject, in bytes
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
static bool AllocateSpaceForInjectedMemory(HANDLE target_proc_handle, size_t size_of_memory_to_inject)
{
    target_memory_address_ = VirtualAllocEx(
        target_proc_handle, nullptr, size_of_memory_to_inject, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);

    return target_memory_address_ != nullptr;
}

//----------------------------------------------------------------------------
/// Injects the memory into the target process.
/// This function should be called after allocateSpaceForInjectedMemory()
/// was called.
/// \param target_proc_handle Handle to target application process
/// \param dll_path Full path and name of dll to be injected
/// \param size_of_memory_to_inject Size of memory to inject, in bytes
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
static bool InjectMemory(HANDLE target_proc_handle, LPCSTR dll_path, size_t size_of_memory_to_inject)
{
    bool retVal = false;

    // Verify that we have allocated space for the memory to inject:
    if (target_memory_address_)
    {
        // Inject the memory into the target process:
        SIZE_T number_of_bytes_written = 0;

        int rc = WriteProcessMemory(
            target_proc_handle, target_memory_address_, dll_path, size_of_memory_to_inject, &number_of_bytes_written);
        retVal = ((rc != 0) && (number_of_bytes_written == size_of_memory_to_inject));
    }

    return retVal;
}

//----------------------------------------------------------------------------
/// Injects the DLL path into the target process.
/// \param target_proc_handle Handle to target application process
/// \param dll_path Full path and name of dll to be injected
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
static bool InjectDllPathIntoTargetProcess(HANDLE target_proc_handle, LPCSTR dll_path)
{
    bool retVal = false;

    size_t size_of_memory_to_inject = strlen(dll_path);

    if (size_of_memory_to_inject > 0)
    {
        retVal = AllocateSpaceForInjectedMemory(target_proc_handle, size_of_memory_to_inject);

        if (retVal)
        {
            retVal = InjectMemory(target_proc_handle, dll_path, size_of_memory_to_inject);
        }
    }

    return retVal;
}

//----------------------------------------------------------------------------
/// Loads the DLL into the target process via a process handle
/// \param dllPath Full path and name of dll to be injected
/// \param process_handle Handle to target application process into.
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool InjectDllIntoProcess(LPCSTR dll_path, HANDLE process_handle)
{
    bool retVal = InjectDllPathIntoTargetProcess(process_handle, dll_path);

    if (retVal)
    {
        retVal = LoadDllIntoTargetProcess(process_handle);
    }

    return retVal;
}

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
