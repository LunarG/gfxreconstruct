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

#ifndef GFXRECON_ENCODE_OPENXR_CAPTURE_MANAGER_H
#define GFXRECON_ENCODE_OPENXR_CAPTURE_MANAGER_H

#if ENABLE_OPENXR_SUPPORT

#include "encode/api_capture_manager.h"

#include "encode/capture_settings.h"
#include "encode/openxr_handle_wrapper_util.h"
#include "encode/openxr_handle_wrappers.h"
#include "encode/openxr_state_tracker.h"
#include "format/api_call_id.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_openxr_dispatch_table.h"
#include "util/defines.h"

#include "openxr/openxr.h"

#include <atomic>
#include <cassert>
#include <memory>
#include <mutex>
#include <set>
#include <unordered_map>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

class OpenXrCaptureManager : public ApiCaptureManager
{
  public:
    static OpenXrCaptureManager* Get() { return instance_; }

    // Creates the capture manager instance if none exists, or increments a reference count if an instance already
    // exists.
    static bool CreateInstance();

    // Decrement the instance reference count, releasing resources when the count reaches zero.  Ignored if the count is
    // already zero.
    static void DestroyInstance();

    // Register special layer provided functions, which perform layer specific initialization.
    // These must be set before the application calls xrCreateInstance.
    static void SetLayerFuncs(PFN_xrCreateInstance create_instance);

    // Called by the layer's xrCreateInstance function, after the driver's xrCreateInstance function has been called, to
    // check for failure.  If xrCreateInstance failed, the reference count will be decremented and resources will be
    // released as necessary.  Allows a failed xrCreateInstance call to be logged to the capture file while performing
    // the appropriate resource cleanup.
    static void CheckXrCreateInstanceStatus(XrResult result);

    static const OpenXrLayerTable* GetLayerTable() { return &layer_table_; }

    void InitXrInstance(XrInstance* instance, PFN_xrGetInstanceProcAddr gpa);

    // Single object creation.
    template <typename ParentHandle, typename Wrapper, typename CreateInfo>
    void EndCreateApiCallCapture(XrResult                      result,
                                 ParentHandle                  parent_handle,
                                 typename Wrapper::HandleType* handle,
                                 const CreateInfo*             create_info)
    {
        if (IsCaptureModeTrack() && (result == XR_SUCCESS))
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddEntry<ParentHandle, Wrapper, CreateInfo>(
                parent_handle, handle, create_info, thread_data->call_id_, thread_data->parameter_buffer_.get());
        }

        EndApiCallCapture();
    }
    template <typename ParentHandle, typename Wrapper, typename CreateInfo>
    void EndCreateAtomApiCallCapture(XrResult                      result,
                                     ParentHandle                  parent_handle,
                                     typename Wrapper::HandleType* handle,
                                     const CreateInfo*             create_info)
    {
        if (IsCaptureModeTrack() && (result == XR_SUCCESS))
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddAtomEntry<ParentHandle, Wrapper, CreateInfo>(
                parent_handle, handle, create_info, thread_data->call_id_, thread_data->parameter_buffer_.get());
        }

        EndApiCallCapture();
    }

    // Multiple implicit object creation inside output struct.
    template <typename ParentHandle, typename Wrapper, typename HandleStruct>
    void EndStructGroupCreateApiCallCapture(XrResult                               result,
                                            ParentHandle                           parent_handle,
                                            uint32_t                               count,
                                            HandleStruct*                          handle_structs,
                                            std::function<Wrapper*(HandleStruct*)> unwrap_struct_handle)
    {
        if (IsCaptureModeTrack() && (result == XR_SUCCESS) && (handle_structs != nullptr))
        {
            assert(state_tracker_ != nullptr);

            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            state_tracker_->AddStructGroupEntry(parent_handle,
                                                count,
                                                handle_structs,
                                                unwrap_struct_handle,
                                                thread_data->call_id_,
                                                thread_data->parameter_buffer_.get());
        }

        EndApiCallCapture();
    }

    // Single object destruction.
    template <typename Wrapper>
    void EndDestroyApiCallCapture(typename Wrapper::HandleType handle)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->RemoveEntry<Wrapper>(handle);
        }

        EndApiCallCapture();
    }

    // Multiple object destruction.
    template <typename Wrapper>
    void EndDestroyApiCallCapture(uint32_t count, const typename Wrapper::HandleType* handles)
    {
        if (IsCaptureModeTrack() && (handles != nullptr))
        {
            assert(state_tracker_ != nullptr);

            for (uint32_t i = 0; i < count; ++i)
            {
                state_tracker_->RemoveEntry<Wrapper>(handles[i]);
            }
        }

        EndApiCallCapture();
    }

    static XrResult OverrideInitializeLoaderKHR(const XrLoaderInitInfoBaseHeaderKHR* loaderInitInfo);
    static XrResult OverrideCreateInstance(const XrInstanceCreateInfo* pCreateInfo, XrInstance* pInstance);

  protected:
    OpenXrCaptureManager() : ApiCaptureManager(format::ApiFamilyId::ApiFamily_OpenXR) {}

    virtual ~OpenXrCaptureManager() {}

    virtual void CreateStateTracker() override { state_tracker_ = std::make_unique<OpenXrStateTracker>(); }

    virtual void DestroyStateTracker() override { state_tracker_ = nullptr; }

    virtual void WriteTrackedState(util::FileOutputStream* file_stream, format::ThreadId thread_id) override;

  private:
    static OpenXrCaptureManager*        instance_;
    static OpenXrLayerTable             layer_table_;
    std::unique_ptr<OpenXrStateTracker> state_tracker_;
};

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_ENCODE_OPENXR_CAPTURE_MANAGER_H
