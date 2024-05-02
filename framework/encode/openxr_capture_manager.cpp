/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
** Copyright (c) 2019-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#if ENABLE_OPENXR_SUPPORT

#include "project_version.h"

#include "encode/struct_pointer_encoder.h"
#include "encode/openxr_capture_manager.h"

#include "encode/openxr_handle_wrapper_util.h"
#include "encode/openxr_state_writer.h"
#include "format/format_util.h"
#include "generated/generated_openxr_struct_handle_wrappers.h"
#include "util/compressor.h"
#include "util/logging.h"
#include "util/platform.h"

#include <cassert>
#include <unordered_set>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

OpenXrCaptureManager* OpenXrCaptureManager::instance_ = nullptr;
VulkanLayerTable      OpenXrCaptureManager::layer_table_;

bool OpenXrCaptureManager::CreateInstance()
{
    bool result = CaptureManager::CreateInstance([]() -> CaptureManager* { return instance_; },
                                                 []() {
                                                     assert(instance_ == nullptr);
                                                     instance_ = new OpenXrCaptureManager();
                                                 },
                                                 []() {
                                                     if (instance_)
                                                     {
                                                         delete instance_;
                                                         instance_ = nullptr;
                                                     }
                                                 });

    GFXRECON_LOG_INFO("  OpenXR Header Version %u.%u.%u",
                      XR_VERSION_MAJOR(XR_CURRENT_API_VERSION),
                      XR_VERSION_MINOR(XR_CURRENT_API_VERSION),
                      XR_VERSION_PATCH(XR_CURRENT_API_VERSION));

    return result;
}

void OpenXrCaptureManager::DestroyInstance()
{
    CaptureManager::DestroyInstance([]() -> const CaptureManager* { return instance_; });
}

void OpenXrCaptureManager::WriteTrackedState(util::FileOutputStream* file_stream, format::ThreadId thread_id)
{
    OpenXrStateWriter state_writer(file_stream, compressor_.get(), thread_id);
    uint64_t          n_blocks = state_tracker_->WriteState(&state_writer, GetCurrentFrame());
    block_index_ += n_blocks;

    auto thread_data          = GetThreadData();
    thread_data->block_index_ = block_index_;
}

void OpenXrCaptureManager::SetLayerFuncs(PFN_vkCreateInstance create_instance)
{
    assert(create_instance != nullptr);
    layer_table_.CreateInstance = create_instance;
}

void OpenXrCaptureManager::CheckXrCreateInstanceStatus(XrResult result)
{
    if (result != XR_SUCCESS)
    {
        DestroyInstance();
    }
}

void OpenXrCaptureManager::InitXrInstance(XrInstance* instance, PFN_xrGetInstanceProcAddr gpa)
{
    assert(instance != nullptr);

    CreateWrappedOpenXrHandle<OpenXrNoParentWrapper, OpenXrNoParentWrapper, openxr_wrappers::InstanceWrapper>(
        OpenXrNoParentWrapper::kHandleValue, OpenXrNoParentWrapper::kHandleValue, instance, GetUniqueId);

    auto wrapper = GetOpenXrWrapper<openxr_wrappers::InstanceWrapper>(*instance);
    LoadOpenXrInstanceTable(gpa, wrapper->handle, &wrapper->layer_table);
}

XrResult OpenXrCaptureManager::OverrideInitializeLoaderKHR(const XrLoaderInitInfoBaseHeaderKHR* loaderInitInfo)
{
    XrResult result = VK_ERROR_INITIALIZATION_FAILED;

    result = layer_table_.InitializeLoaderKHR(loaderInitInfo);
}

XrResult OpenXrCaptureManager::OverrideCreateInstance(const XrInstanceCreateInfo* createInfo, XrInstance* instance)
{
    XrResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (CreateInstance())
    {
        result = layer_table_.CreateInstance(createInfo, pInstance);
    }

    if ((result == VK_SUCCESS) && (createInfo->pApplicationInfo != nullptr))
    {
        auto api_version              = createInfo->pApplicationInfo->apiVersion;
        auto instance_wrapper         = GetOpenXrWrapper<openxr_wrappers::InstanceWrapper>(*pInstance);
        instance_wrapper->api_version = api_version;

        // Warn when enabled API version is newer than the supported API version.
        if (api_version > XR_CURRENT_API_VERSION)
        {
            GFXRECON_LOG_WARNING(
                "The application has specified that it uses OpenXR API version %u.%u.%u, which is newer than the "
                "version supported by GFXReconstruct.  Use of unsupported OpenXR features may cause capture or replay "
                "to fail.",
                XR_VERSION_MAJOR(api_version),
                XR_VERSION_MINOR(api_version),
                XR_VERSION_PATCH(api_version));
        }
    }

    return result;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
