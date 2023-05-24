/*
** Copyright (c) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "hook_ags.h"

#include "util/file_path.h"

// Static data required for hook management
static AgsHookInfo hook_info_ = {};

AMD_AGS_API AGSReturnCode Mine_agsInitialize(int, const AGSConfiguration*, AGSContext**, AGSGPUInfo*)
{
    AGSReturnCode result = AGS_FAILURE;

    return result;
}

//----------------------------------------------------------------------------
/// Fill in a dispatch table with function addresses obtained from amd_ags_x64.dll
///
/// \param  amd_ags_x64_module Output dispatch table.
///
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool GetAgsDispatchTable(gfxrecon::encode::AgsDispatchTable& ags_table)
{
    std::string library_base_path = "";

    bool success = gfxrecon::util::filepath::GetWindowsSystemLibrariesPath(library_base_path);

    if (success == true)
    {
        std::string library_path = library_base_path + "\\" + kHookingDllName;

        hook_info_.ags_dll = LoadLibraryA(library_path.c_str());

        if (hook_info_.ags_dll != nullptr)
        {
            ags_table.agsInitialize =
                reinterpret_cast<AGS_INITIALIZE>(GetProcAddress(hook_info_.ags_dll, "agsInitialize"));

            ags_table.agsDeInitialize =
                reinterpret_cast<AGS_DEINITIALIZE>(GetProcAddress(hook_info_.ags_dll, "agsDeInitialize"));

            ags_table.agsCheckDriverVersion =
                reinterpret_cast<AGS_CHECKDRIVERVERSION>(GetProcAddress(hook_info_.ags_dll, "agsCheckDriverVersion"));

            success = true;
        }
    }

    return success;
}

//----------------------------------------------------------------------------
/// Given a amd_ags_x64 dispatch table, perform hooking and write out the final
/// dispatch table that will be called by intercepted entry points.
///
/// \param  amd_ags_x64_table  Incoming dispatch table with entry function addresses
///                     in amd_ags_x64.
///
/// \param  gpu_table Outgoing dispatch table with hooked entry points that
///                   will either go to the GPU or capture layer.
///
/// \return True if successful, false otherwise.
//----------------------------------------------------------------------------
bool GetAgsDispatchTableHooked(gfxrecon::encode::AgsDispatchTable  ags_table,
                               gfxrecon::encode::AgsDispatchTable& gpu_table)
{
    bool success = false;

    Hook_AGS* pInterceptor = Hook_AGS::GetInterceptor();

    if (pInterceptor != nullptr)
    {
        bool attach_success = false;

        if (ags_table.agsInitialize != nullptr)
        {
            pInterceptor->hook_agsInitialize_.SetHooks(ags_table.agsInitialize, Mine_agsInitialize);
            attach_success = pInterceptor->hook_agsInitialize_.Attach();

            gpu_table.agsInitialize = pInterceptor->hook_agsInitialize_.real_hook_;
        }

        success = true;
    }

    return success;
}

//-----------------------------------------------------------------------------
/// Get unique instance of Hook_AGS
//-----------------------------------------------------------------------------
Hook_AGS* Hook_AGS::GetInterceptor()
{
    if (hook_info_.interceptor == nullptr)
    {
        hook_info_.interceptor = new Hook_AGS();
    }

    return hook_info_.interceptor;
}

//-----------------------------------------------------------------------------
/// Attach API entry points for hooking.
///
/// \param capture Whether capture is enabled
///
/// \return True if entry points were successfully hooked.
//-----------------------------------------------------------------------------
bool Hook_AGS::HookInterceptor(bool capture)
{
    bool success = false;

    Hook_AGS* pInterceptor = GetInterceptor();

    if (pInterceptor != nullptr)
    {
        gfxrecon::encode::AgsDispatchTable dispatch_table_ags = {};

        success = GetAgsDispatchTable(dispatch_table_ags);

        if (success == true)
        {
            success = GetAgsDispatchTableHooked(dispatch_table_ags, hook_info_.dispatch_table);

            if (success == true)
            {
                if (capture == true)
                {
                    if (hook_info_.capture_dll == nullptr)
                    {
                        hook_info_.capture_dll = gfxrecon::util::platform::OpenLibrary(GFXR_D3D12_CAPTURE_PATH);

                        if (hook_info_.capture_dll != nullptr)
                        {
                            auto init_func = reinterpret_cast<PFN_InitializeAgsCapture>(
                                GetProcAddress(hook_info_.capture_dll, "InitializeAgsCapture"));

                            if (init_func != nullptr)
                            {
                                init_func(&hook_info_.dispatch_table);
                            }
                        }
                    }
                }
            }
        }
    }

    return success;
}

//-----------------------------------------------------------------------------
/// Detach all hooked API entry points.
/// \return True if entry points were successfully detached.
//-----------------------------------------------------------------------------
bool Hook_AGS::UnhookInterceptor()
{
    bool success = false;

    Hook_AGS* pInterceptor = GetInterceptor();

    if (pInterceptor != nullptr)
    {
        pInterceptor->hook_agsInitialize_.Detach();

        success = true;
    }

    return success;
}
