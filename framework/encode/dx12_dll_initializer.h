/*
** Copyright (c) 2021 LunarG, Inc.
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

#ifndef GFXRECON_ENCODE_DX12_DLL_INITIALIZER_H
#define GFXRECON_ENCODE_DX12_DLL_INITIALIZER_H

#include "util/defines.h"
#include "util/platform.h"
#include "util/file_path.h"

#include <string>
#include <windows.h>
#include <Shlobj.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

const char kDx12RedistRuntime[] = "D3D12Core.dll";

bool FoundRenamedCaptureModule(const std::string& renamed_module)
{
    char        module_name[MAX_PATH] = {};
    int         path_size             = GetModuleFileNameA(nullptr, module_name, MAX_PATH);
    size_t      separator_pos         = std::string(module_name).find_last_of(util::filepath::kPathSep);
    std::string exe_root              = std::string(module_name).substr(0, separator_pos);
    std::string legacy_path           = exe_root + util::filepath::kPathSep + renamed_module;

    return util::filepath::Exists(legacy_path);
}

std::string GetWindowsModuleRoot()
{
    std::string windows_module_root = "";

    // Get actual Windows folder
    char     win_dir[MAX_PATH]  = {};
    uint32_t windows_dir_result = GetWindowsDirectory(win_dir, MAX_PATH);

    if (windows_dir_result != 0)
    {
        windows_module_root = std::string(win_dir) + util::filepath::kPathSep + std::string("System32");

        // Check if app is 32-bit
        BOOL process_32_bit = FALSE;
        BOOL found_bitness  = IsWow64Process(GetCurrentProcess(), &process_32_bit);

        if (found_bitness != 0)
        {
            if (process_32_bit == TRUE)
            {
                windows_module_root = std::string(win_dir) + util::filepath::kPathSep + std::string("SysWOW64");
            }
        }
    }

    return windows_module_root;
}

bool CopyModule(const std::string& src, const std::string& dst)
{
    // Copy the runtime to "\AppData\Roaming\GFXReconstruct\dx-runtimes"
    BOOL copy_result = CopyFile(src.c_str(), dst.c_str(), FALSE);

    // Only update module path if we're good until now
    if (copy_result == 0)
    {
        std::string debug_str = std::string("GFXRECON: Failed to copy ") + src;
        OutputDebugStringA(debug_str.c_str());
    }

    return copy_result != 0;
}

bool UpdateModule(const std::string& src, const std::string& dst)
{
    bool module_up_to_date = false;

    if (util::filepath::Exists(dst) == true)
    {
        if (util::filepath::FilesEqual(src, dst) == true)
        {
            module_up_to_date = true;
        }
        else
        {
            module_up_to_date = CopyModule(src, dst);
        }
    }
    else
    {
        module_up_to_date = CopyModule(src, dst);
    }

    return module_up_to_date;
}

std::string PrepGfxrRuntimesFolder(const std::string& windows_module_root)
{
    std::string gfxr_runtimes_root = "";

    // Get folder location for "\AppData\Roaming"
    char roaming_path[MAX_PATH] = {};
    if (SUCCEEDED(SHGetFolderPath(nullptr, CSIDL_APPDATA, nullptr, 0, roaming_path)))
    {
        std::string gfxr_user_target =
            std::string(roaming_path) + util::filepath::kPathSep + std::string("GFXReconstruct");
        std::string gfxr_runtimes_target = gfxr_user_target + util::filepath::kPathSep + std::string("dx-runtimes");

        // If "\AppData\Roaming\GFXReconstruct\dx-runtimes" does not exist, create it
        if (util::filepath::Exists(gfxr_runtimes_target) == false)
        {
            int32_t mkdir_result = 0;

            // If "\AppData\Roaming\GFXReconstruct" does not exist, create it
            if (util::filepath::Exists(gfxr_user_target) == false)
            {
                mkdir_result = gfxrecon::util::platform::MakeDirectory(gfxr_user_target.c_str());
            }

            // Create "\AppData\Roaming\GFXReconstruct\dx-runtimes"
            if (mkdir_result == 0)
            {
                mkdir_result = gfxrecon::util::platform::MakeDirectory(gfxr_runtimes_target.c_str());
            }

            if (mkdir_result == 0)
            {
                gfxr_runtimes_root = gfxr_runtimes_target;
            }
            else
            {
                std::string debug_str = std::string("GFXRECON: Failed to setup GFXR user folder");
                OutputDebugStringA(debug_str.c_str());
            }
        }
        else
        {
            gfxr_runtimes_root = gfxr_runtimes_target;
        }

        // Once created "\AppData\Roaming\GFXReconstruct\dx-runtimes" copy in the current in-box D3D12 runtime
        if (gfxr_runtimes_root.empty() == false)
        {
            std::string redist_runtime_path_src =
                windows_module_root + util::filepath::kPathSep + std::string(kDx12RedistRuntime);
            std::string redist_runtime_path_dst =
                gfxr_runtimes_root + util::filepath::kPathSep + std::string(kDx12RedistRuntime);

            UpdateModule(redist_runtime_path_src, redist_runtime_path_dst);
        }
    }

    return gfxr_runtimes_root;
}

std::string SetupCaptureModule(const std::string& dll_name, const std::string& dll_name_renamed)
{
    // First assume we are starting with the "legacy" method with renamed capture binaries
    std::string module_path = dll_name_renamed;

    // If the renamed DLLs are not found beside the app executable, then setup for reading from "\AppData\Roaming"
    if (FoundRenamedCaptureModule(dll_name_renamed) == false)
    {
        std::string windows_module_root = GetWindowsModuleRoot();

        // If obtained path to Windows (for correct app bitness)
        if (windows_module_root.empty() == false)
        {
            // Make sure the roaming folder is present and ready
            std::string gfxr_user_roaming_root = PrepGfxrRuntimesFolder(windows_module_root);

            if (gfxr_user_roaming_root.empty() == false)
            {
                std::string module_path_src = windows_module_root + util::filepath::kPathSep + dll_name;
                std::string module_path_dst = gfxr_user_roaming_root + util::filepath::kPathSep + dll_name_renamed;

                if (UpdateModule(module_path_src, module_path_dst) == true)
                {
                    module_path = module_path_dst;
                }
            }
        }
    }

    return module_path;
}

template <typename DispatchTableT>
class DxDllInitializer
{
  public:
    bool Initialize(const char* system_dll_name,
                    const char* capture_dll_name,
                    const char* initialize_func_name,
                    void (*LoadCaptureProcs)(HMODULE, DispatchTableT*))
    {
        if (util::interception::UseDetoursHooking() == false)
        {
            if (system_dll_ == nullptr)
            {
                system_dll_ = util::platform::OpenLibrary(system_dll_name);

                if (system_dll_ != nullptr)
                {
                    LoadCaptureProcs(system_dll_, &dispatch_table_);

                    if (IsCaptureEnabled() && (capture_dll_ == nullptr))
                    {
                        capture_dll_ = util::platform::OpenLibrary(capture_dll_name);
                        if (capture_dll_ != nullptr)
                        {
                            auto init_func =
                                reinterpret_cast<InitializeFuncT>(GetProcAddress(capture_dll_, initialize_func_name));

                            if (init_func != nullptr)
                            {
                                init_func(&dispatch_table_);
                            }
                            else
                            {
                                std::string debug_str =
                                    std::string("GFXRECON: Failed to retrieve '") + initialize_func_name +
                                    "' proc from GFXReconstruct capture DLL '" + capture_dll_name + "'";
                                // TODO: Unify logging
                                OutputDebugStringA(debug_str.c_str());
                                OutputDebugStringA("GFXRECON: GFXReconstruct capture will be disabled");
                            }
                        }
                        else
                        {
                            std::string debug_str =
                                std::string("GFXRECON: Failed to load GFXReconstruct capture DLL '") +
                                capture_dll_name + "' needed to get proc '" + initialize_func_name + "'";
                            // TODO: Unify logging
                            OutputDebugStringA(debug_str.c_str());
                            OutputDebugStringA("GFXRECON: GFXReconstruct capture will be disabled");
                        }
                    }
                }
                else
                {
                    std::string debug_str =
                        std::string("GFXRECON: Failed to load system DLL '") + system_dll_name + "'";
                    // TODO: Unify logging
                    OutputDebugStringA(debug_str.c_str());
                    return false;
                }
            }
        }

        return true;
    }

    void Destroy(const char* release_func_name)
    {
        if (capture_dll_ != nullptr)
        {
            auto release_func = reinterpret_cast<ReleaseFuncT>(GetProcAddress(capture_dll_, release_func_name));

            if (release_func != nullptr)
            {
                release_func(&dispatch_table_);
            }

            util::platform::CloseLibrary(capture_dll_);
            capture_dll_ = nullptr;
        }

        if (system_dll_ != nullptr)
        {
            util::platform::CloseLibrary(system_dll_);
            system_dll_ = nullptr;
        }
    }

    static bool IsCaptureEnabled()
    {
        // TODO: Read environment variable.
        return true;
    }

    const DispatchTableT& GetDispatchTable() const { return dispatch_table_; }

  private:
    typedef bool (*InitializeFuncT)(DispatchTableT*);
    typedef void (*ReleaseFuncT)(DispatchTableT*);

  private:
    DispatchTableT dispatch_table_;

    // System DLL providing the DX API calls to wrap.
    util::platform::LibraryHandle system_dll_{ nullptr };

    // DLL with capture implementation, which is only loaded when capture is enabled.
    util::platform::LibraryHandle capture_dll_{ nullptr };
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_DX12_DLL_INITIALIZER_H
