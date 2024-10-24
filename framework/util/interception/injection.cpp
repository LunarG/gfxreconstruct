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

#include "util/logging.h"
#include "util/options.h"

#include <algorithm>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
GFXRECON_BEGIN_NAMESPACE(interception)

static void* target_memory_address_ = nullptr;

//----------------------------------------------------------------------------
/// Convert a wide string to regular
/// \param  src Input string
/// \return Converted string or empty if not successful
//----------------------------------------------------------------------------
std::string WideStringToString(const std::wstring& src)
{
    std::string out = "";

    if (src.empty() == false)
    {
        const int src_len = static_cast<int>(src.length());
        const int out_len = ::WideCharToMultiByte(CP_UTF8, 0, src.data(), src_len, nullptr, 0, nullptr, nullptr);

        if (out_len > 0)
        {
            out.resize(out_len);

            ::WideCharToMultiByte(CP_UTF8, 0, src.data(), src_len, &out[0], out_len, nullptr, nullptr);
        }
    }

    return out;
}

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
                BOOL  rc = GetExitCodeThread(remote_thread_handle, static_cast<LPDWORD>(&thread_exit_code));

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

bool InjectLoadDllIntoProcess(LPCSTR dll_path, HANDLE process_handle)
{
    bool ret_val = InjectDllPathIntoTargetProcess(process_handle, dll_path);

    if (ret_val)
    {
        ret_val = LoadDllIntoTargetProcess(process_handle);
    }

    return ret_val;
}

bool InjectDllIntoProcess(LPCSTR dll_path, DWORD process_id)
{
    HANDLE target_process_handle = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION |
                                                   PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ,
                                               FALSE,
                                               process_id);
    bool   ret_val               = InjectLoadDllIntoProcess(dll_path, target_process_handle);
    CloseHandle(target_process_handle);
    return ret_val;
}

// ---------------------------------------------------------------------------
/// Execute rundll32.exe and use it to call InjectDLL inside our injector.
/// This is needed to inject a 64-bit process from a 32-bit process.
///
/// \param dll_name The full path and name of the dll to be injected.
/// \param app_process_id The process ID of the application to be injected into.
// ---------------------------------------------------------------------------
void StartRundllA(LPCSTR dll_name, DWORD app_process_id)
{
    const uint32_t kCommandLineSize = 1024;

    char  exe_name[kCommandLineSize]     = {};
    char  command_line[kCommandLineSize] = {};
    char  win_dir[MAX_PATH]              = {};
    DWORD len                            = GetEnvironmentVariableA("WINDIR", win_dir, ARRAYSIZE(win_dir));

#ifdef GFXRECON_ARCH64
    const char* sys_dir = "SysWOW64";
#else
    const char*  sys_dir = "System32";
#endif

    sprintf_s(exe_name, "%s\\%s\\rundll32.exe", win_dir, sys_dir);
    sprintf_s(command_line,
              "%s\\%s\\rundll32.exe \"%s\",InjectDLL %d %s",
              win_dir,
              sys_dir,
              dll_name,
              app_process_id,
              dll_name);

    STARTUPINFOA si = {};
    si.cb           = sizeof(si);

    PROCESS_INFORMATION pi = {};

    CreateProcessA(exe_name, command_line, nullptr, nullptr, FALSE, CREATE_SUSPENDED, nullptr, nullptr, &si, &pi);
    ResumeThread(pi.hThread);

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

// ---------------------------------------------------------------------------
/// Execute rundll32.exe and use it to call InjectDLL inside our injector.
/// This is needed to inject a 64-bit process from a 32-bit process.
///
/// \param dll_name The full path and name of the dll to be injected.
/// \param app_process_id The process ID of the application to be injected into.
// ---------------------------------------------------------------------------
void StartRundllW(LPCSTR dll_name, DWORD app_process_id)
{
    const uint32_t kCommandLineSize = 1024;

    WCHAR exe_name[kCommandLineSize]     = {};
    WCHAR command_line[kCommandLineSize] = {};
    WCHAR win_dir[MAX_PATH]              = {};
    DWORD len                            = GetEnvironmentVariableW(L"WINDIR", win_dir, ARRAYSIZE(win_dir));

#ifdef GFXRECON_ARCH64
    const WCHAR* sys_dir = L"SysWOW64";
#else
    const WCHAR* sys_dir = L"System32";
#endif

    swprintf_s(exe_name, L"%s\\%s\\rundll32.exe", win_dir, sys_dir);
    swprintf_s(command_line,
               L"%s\\%s\\rundll32.exe \"%hs\",InjectDLL %d %hs",
               win_dir,
               sys_dir,
               dll_name,
               app_process_id,
               dll_name);

    STARTUPINFOW si = {};
    si.cb           = sizeof(si);

    PROCESS_INFORMATION pi = {};

    CreateProcessW(exe_name, command_line, nullptr, nullptr, FALSE, CREATE_SUSPENDED, nullptr, nullptr, &si, &pi);
    ResumeThread(pi.hThread);

    WaitForSingleObject(pi.hProcess, INFINITE);

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
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
                      LPPROCESS_INFORMATION process_information,
                      LPCSTR                interceptor_path)
{
    DWORD flags = creation_flags | CREATE_SUSPENDED;

    bool ret_val = CreateProcessA(application_name,
                                  command_line,
                                  process_attributes,
                                  thread_attributes,
                                  inherit_handles,
                                  flags,
                                  environment,
                                  current_directory,
                                  startup_info,
                                  process_information);

    if (ret_val == true)
    {
        if (EnableBitnessHopping() == true)
        {
            const bool target_equal_bitness = TargetHasEqualBitness(command_line);

            if (target_equal_bitness == true)
            {
                InjectLoadDllIntoProcess(interceptor_path, process_information->hProcess);
            }
            else
            {
                StartRundllA(interceptor_path, process_information->dwProcessId);
            }
        }
        else
        {
            InjectLoadDllIntoProcess(interceptor_path, process_information->hProcess);
        }

        ResumeThread(process_information->hThread);
    }

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
                      LPPROCESS_INFORMATION process_information,
                      LPCSTR                interceptor_path)
{
    DWORD flags = creation_flags | CREATE_SUSPENDED;

    bool ret_val = CreateProcessW(application_name,
                                  command_line,
                                  process_attributes,
                                  thread_attributes,
                                  inherit_handles,
                                  flags,
                                  environment,
                                  current_directory,
                                  startup_info,
                                  process_information);

    if (ret_val == true)
    {
        if (EnableBitnessHopping() == true)
        {
            const bool target_equal_bitness = TargetHasEqualBitness(command_line);

            if (target_equal_bitness == true)
            {
                InjectLoadDllIntoProcess(interceptor_path, process_information->hProcess);
            }
            else
            {
                StartRundllW(interceptor_path, process_information->dwProcessId);
            }
        }
        else
        {
            InjectLoadDllIntoProcess(interceptor_path, process_information->hProcess);
        }

        ResumeThread(process_information->hThread);
    }

    return ret_val;
}

void Inject(LPSTR cmd_line)
{
    char module_name[MAX_PATH] = {};
    GetModuleFileNameA(nullptr, module_name, MAX_PATH);

    // find end of process ID and put null-terminate
    char* dll_name = cmd_line;
    for (int i = 0; i < 6; i++)
    {
        if (*dll_name == ' ')
        {
            *dll_name++ = '\0';
            break;
        }
        else
        {
            dll_name++;
        }
    }

    DWORD process_id = (DWORD)atoi(cmd_line);

    if (InjectDllIntoProcess(dll_name, process_id) == false)
    {
        GFXRECON_LOG_ERROR("Failed to inject");
    }

    ExitProcess(0);
}

bool GetTargetBinaryType(const std::string target, DWORD& app_type)
{
    bool success = false;

    const size_t ext_loc = target.rfind(".exe");

    if (ext_loc != std::string::npos)
    {
        std::string app_path = target.substr(0, ext_loc + 4);
        app_path.erase(std::remove(app_path.begin(), app_path.end(), '"'), app_path.end());

        success = GetBinaryTypeA(app_path.c_str(), &app_type);
    }

    return success;
}

bool TargetHasEqualBitness(const std::string& target)
{
    char current_filename[MAX_PATH] = {};
    GetModuleFileNameA(nullptr, current_filename, MAX_PATH);

    DWORD current_type = 0;
    GetBinaryTypeA(current_filename, &current_type);

    DWORD app_type = current_type;

    GetTargetBinaryType(target, app_type);

    return app_type == current_type;
}

bool TargetHasEqualBitness(const std::wstring& target)
{
    const std::string target_exe = gfxrecon::util::interception::WideStringToString(target);

    return TargetHasEqualBitness(target_exe);
}

std::string GetInterceptorPath(std::string target)
{
    std::string out = GFXR_INTERCEPTOR_PATH;

    if (EnableBitnessHopping() == true)
    {
        // TODO:
        // Enabling hopping across processes of different bitness implies that we need
        // both 32-bit and 64-bit builds of our gfxrecon-interceptor.
        // These paths need to be set by the developer for debugging purposes.
        // They should point to the root build directories of the 32-bit and 64-bit builds.
        // This will also need to be modified to work with install scripts
        const std::string gfxr_root_32_bit = "";
        const std::string gfxr_root_64_bit = "";

        DWORD app_type = 0;

        if (GetTargetBinaryType(target, app_type) == true)
        {
#ifdef _DEBUG
            const std::string config = "Debug";
#else
            const std::string config = "Release";
#endif

            if (app_type == SCS_64BIT_BINARY)
            {
                out = gfxr_root_64_bit + "\\layer\\gfxrecon_interceptor\\" + config + "\\gfxrecon_interceptor.dll";
            }
            else
            {
                out = gfxr_root_32_bit + "\\layer\\gfxrecon_interceptor\\" + config + "\\gfxrecon_interceptor.dll";
            }
        }
    }

    return out;
}

std::string GetInterceptorPath(std::wstring target)
{
    const std::string dest_str = gfxrecon::util::interception::WideStringToString(target);

    return GetInterceptorPath(dest_str);
}

bool EnableBitnessHopping()
{
    bool bitness_hop = false;

    const std::string value = gfxrecon::util::platform::GetEnv("GFXRECON_ENABLE_BITNESS_HOPPING");

    if (gfxrecon::util::ParseBoolString(value, false) == true)
    {
        bitness_hop = true;
    }

    return bitness_hop;
}

GFXRECON_END_NAMESPACE(interception)
GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
