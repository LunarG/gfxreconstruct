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

#include <string>
#include <windows.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

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
                                // TODO(GH-68): Unify logging
                                OutputDebugStringA(debug_str.c_str());
                                OutputDebugStringA("GFXRECON: GFXReconstruct capture will be disabled");
                            }
                        }
                        else
                        {
                            std::string debug_str =
                                std::string("GFXRECON: Failed to load GFXReconstruct capture DLL '") +
                                capture_dll_name + "' needed to get proc '" + initialize_func_name + "'";
                            // TODO(GH-68): Unify logging
                            OutputDebugStringA(debug_str.c_str());
                            OutputDebugStringA("GFXRECON: GFXReconstruct capture will be disabled");
                        }
                    }
                }
                else
                {
                    std::string debug_str =
                        std::string("GFXRECON: Failed to load system DLL '") + system_dll_name + "'";
                    // TODO(GH-68): Unify logging
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
        // TODO(GH-48): Read environment variable.
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
