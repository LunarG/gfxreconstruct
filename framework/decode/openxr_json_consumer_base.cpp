/*
** Copyright (c) 2022-2025 LunarG, Inc.
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

#include "decode/openxr_json_consumer_base.h"
#include "decode/custom_openxr_struct_to_json.h"

#include "util/json_util.h"
#include "util/platform.h"
#include "util/file_path.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using namespace util::platform;
using util::JsonOptions;
using util::uuid_to_string;

OpenXrExportJsonConsumerBase::OpenXrExportJsonConsumerBase() {}

OpenXrExportJsonConsumerBase::~OpenXrExportJsonConsumerBase()
{
    Destroy();
}

void OpenXrExportJsonConsumerBase::Initialize(JsonWriter* writer, const std::string_view openxrVersion)
{
    GFXRECON_ASSERT(writer);
    writer_ = writer;

    writer->GetHeaderJson()["openxr-version"] = std::string(openxrVersion);
}

void OpenXrExportJsonConsumerBase::Destroy()
{
    if (writer_)
    {
        writer_->Destroy();
    }
}

std::string OpenXrExportJsonConsumerBase::GenerateFilename(const std::string& filename)
{
    return writer_->GenerateFilename(filename);
}

bool OpenXrExportJsonConsumerBase::WriteBinaryFile(const std::string& filename, uint64_t data_size, const uint8_t* data)
{
    return writer_->WriteBinaryFile(filename, data_size, data);
}

void OpenXrExportJsonConsumerBase::Process_xrInitializeLoaderKHR(
    const ApiCallInfo&                                           call_info,
    XrResult                                                     returnValue,
    StructPointerDecoder<Decoded_XrLoaderInitInfoBaseHeaderKHR>* loaderInitInfo)
{
    nlohmann::ordered_json& jdata        = WriteApiCallStart(call_info, "xrInitializeLoaderKHR");
    const JsonOptions&      json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
    switch (loaderInitInfo->GetPointer()->type)
    {
        default:
            FieldToJson(args["loaderInitInfo"], loaderInitInfo, json_options);
            break;
        case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
            FieldToJson(args["loaderInitInfo"],
                        reinterpret_cast<StructPointerDecoder<Decoded_XrLoaderInitInfoAndroidKHR>*>(loaderInitInfo),
                        json_options);
            break;
    }
    WriteBlockEnd();
}

void OpenXrExportJsonConsumerBase::Process_xrCreateApiLayerInstance(
    const ApiCallInfo&                                  call_info,
    XrResult                                            returnValue,
    StructPointerDecoder<Decoded_XrInstanceCreateInfo>* info,
    StructPointerDecoder<Decoded_XrApiLayerCreateInfo>* layerInfo,
    HandlePointerDecoder<XrInstance>*                   instance)
{
    nlohmann::ordered_json& jdata        = WriteApiCallStart(call_info, "xrCreateApiLayerInstance");
    const JsonOptions&      json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
    FieldToJson(args["info"], info, json_options);
    FieldToJson(args["layerInfo"], layerInfo, json_options);
    HandleToJson(args["instance"], instance, json_options);
    WriteBlockEnd();
}

// TODO: Add code generation for below
void OpenXrExportJsonConsumerBase::Process_xrEnumerateSwapchainImages(
    const ApiCallInfo&                                        call_info,
    XrResult                                                  returnValue,
    format::HandleId                                          swapchain,
    uint32_t                                                  imageCapacityInput,
    PointerDecoder<uint32_t>*                                 imageCountOutput,
    StructPointerDecoder<Decoded_XrSwapchainImageBaseHeader>* images)
{
    nlohmann::ordered_json& jdata        = WriteApiCallStart(call_info, "xrEnumerateSwapchainImages");
    const JsonOptions&      json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    auto& args = jdata[NameArgs()];
    HandleToJson(args["swapchain"], swapchain, json_options);
    FieldToJson(args["imageCapacityInput"], imageCapacityInput, json_options);
    FieldToJson(args["imageCountOutput"], imageCountOutput, json_options);
    if (images != nullptr && images->GetPointer() != nullptr && images->GetLength() >= 1)
    {
        XrSwapchainImageBaseHeader* header = images->GetPointer();
        switch (header->type)
        {
            case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
            {
                FieldToJson(args["images"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageOpenGLKHR>*>(images),
                            json_options);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            {
                FieldToJson(args["images"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageVulkanKHR>*>(images),
                            json_options);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
            {
                FieldToJson(args["images"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageD3D11KHR>*>(images),
                            json_options);
                break;
            }
            case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
            {
                FieldToJson(args["images"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrSwapchainImageD3D12KHR>*>(images),
                            json_options);
                break;
            }
            default:
            {
                FieldToJson(args["images"], images, json_options);
                break;
            }
        }
    }
    else
    {
        FieldToJson(args["images"], images, json_options);
    }
    WriteBlockEnd();
}

void OpenXrExportJsonConsumerBase::Process_xrPollEvent(const ApiCallInfo&                               call_info,
                                                       XrResult                                         returnValue,
                                                       format::HandleId                                 instance,
                                                       StructPointerDecoder<Decoded_XrEventDataBuffer>* eventData)
{
    nlohmann::ordered_json& jdata        = WriteApiCallStart(call_info, "xrPollEvent");
    const JsonOptions&      json_options = GetJsonOptions();
    FieldToJson(jdata[NameReturn()], returnValue, json_options);
    if (returnValue != XR_EVENT_UNAVAILABLE)
    {
        auto& args = jdata[NameArgs()];
        HandleToJson(args["instance"], instance, json_options);
        switch (eventData->GetPointer()->type)
        {
            default:
                FieldToJson(args["eventData"], eventData, json_options);
                break;
            case XR_TYPE_EVENT_DATA_EVENTS_LOST:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataEventsLost>*>(eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataInstanceLossPending>*>(eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataSessionStateChanged>*>(eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataReferenceSpaceChangePending>*>(eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataPerfSettingsEXT>*>(eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataVisibilityMaskChangedKHR>*>(eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataInteractionProfileChanged>*>(eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataMainSessionVisibilityChangedEXTX>*>(
                        eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataDisplayRefreshRateChangedFB>*>(eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataSpatialAnchorCreateCompleteFB>*>(
                                eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataSpaceSetStatusCompleteFB>*>(eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataSpaceQueryResultsAvailableFB>*>(eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataSpaceQueryCompleteFB>*>(eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataSpaceSaveCompleteFB>*>(eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataSpaceEraseCompleteFB>*>(eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataSpaceShareCompleteFB>*>(eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataSpaceListSaveCompleteFB>*>(eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataViveTrackerConnectedHTCX>*>(eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataMarkerTrackingUpdateVARJO>*>(eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataVirtualKeyboardCommitTextMETA>*>(
                                eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
                FieldToJson(args["eventData"],
                            reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataHeadsetFitChangedML>*>(eventData),
                            json_options);
                break;
            case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataEyeCalibrationChangedML>*>(eventData),
                    json_options);
                break;
            case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
                FieldToJson(
                    args["eventData"],
                    reinterpret_cast<StructPointerDecoder<Decoded_XrEventDataLocalizationChangedML>*>(eventData),
                    json_options);
                break;
        }
    }
    WriteBlockEnd();
}

void OpenXrExportJsonConsumerBase::ProcessViewRelativeLocation(format::ThreadId              thread_id,
                                                               format::ViewRelativeLocation& location)
{
    const util::JsonOptions& json_options = writer_->GetOptions();
    // TODO: Fold this into a override for WriteMetaCommandStart if we add many more meta data blocks
    writer_->SetCurrentBlockIndex(this->block_index_);
    auto& jdata = writer_->WriteMetaCommandStart("ViewRelativeLocation");

    FieldToJson(jdata["session"], location.session_id, json_options);
    FieldToJson(jdata["space"], location.space_id, json_options);
    FieldToJson(jdata["flags"], location.flags, json_options);

    FieldToJson(jdata["qx"], location.qx, json_options);
    FieldToJson(jdata["qy"], location.qy, json_options);
    FieldToJson(jdata["qz"], location.qz, json_options);
    FieldToJson(jdata["qw"], location.qw, json_options);

    FieldToJson(jdata["x"], location.x, json_options);
    FieldToJson(jdata["y"], location.y, json_options);
    FieldToJson(jdata["z"], location.z, json_options);

    writer_->WriteBlockEnd();
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
