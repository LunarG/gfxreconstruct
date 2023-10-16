/*
** Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include "decode/custom_ags_struct_decoders.h"
#include "custom_ags_ascii_consumer.h"
#include "util/logging.h"
#include "generated/generated_dx12_enum_to_string.h"

#include <amd_ags.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

static std::string GetAgsResultValueString(AGSReturnCode result)
{
    switch (result)
    {
        case AGS_SUCCESS:
            return "AGS_SUCCESS";
        case AGS_FAILURE:
            return "AGS_FAILURE";
        case AGS_INVALID_ARGS:
            return "AGS_INVALID_ARGS";
        case AGS_OUT_OF_MEMORY:
            return "AGS_OUT_OF_MEMORY";
        case AGS_MISSING_D3D_DLL:
            return "AGS_MISSING_D3D_DLL";
        case AGS_LEGACY_DRIVER:
            return "AGS_LEGACY_DRIVER";
        case AGS_NO_AMD_DRIVER_INSTALLED:
            return "AGS_NO_AMD_DRIVER_INSTALLED";
        case AGS_EXTENSION_NOT_SUPPORTED:
            return "AGS_EXTENSION_NOT_SUPPORTED";
        case AGS_ADL_FAILURE:
            return "AGS_ADL_FAILURE";
        case AGS_DX_FAILURE:
            return "AGS_DX_FAILURE";
        default:
            return std::to_string(result);
    }
}

std::string InterfaceIdToString(const IID& iid)
{
    if (iid == IID_IDXGIDevice)
        return "\"IID_IDXGIDevice\"";
    if (iid == IID_IDXGIDevice1)
        return "\"IID_IDXGIDevice1\"";
    if (iid == IID_IDXGIDevice2)
        return "\"IID_IDXGIDevice2\"";
    if (iid == IID_IDXGIDevice3)
        return "\"IID_IDXGIDevice3\"";
    if (iid == IID_IDXGIDevice4)
        return "\"IID_IDXGIDevice4\"";
    if (iid == IID_ID3D12Device)
        return "\"IID_ID3D12Device\"";
    if (iid == IID_ID3D12Device1)
        return "\"IID_ID3D12Device1\"";
    if (iid == IID_ID3D12Device2)
        return "\"IID_ID3D12Device2\"";
    if (iid == IID_ID3D12Device3)
        return "\"IID_ID3D12Device3\"";
    if (iid == IID_ID3D12Device4)
        return "\"IID_ID3D12Device4\"";
    if (iid == IID_ID3D12Device5)
        return "\"IID_ID3D12Device5\"";
    if (iid == IID_ID3D12Device6)
        return "\"IID_ID3D12Device6\"";
    if (iid == IID_ID3D12Device7)
        return "\"IID_ID3D12Device7\"";
    if (iid == IID_ID3D12Device8)
        return "\"IID_ID3D12Device8\"";
    if (iid == IID_ID3D12Device9)
        return "\"IID_ID3D12Device9\"";
    if (iid == IID_ID3D12Device10)
        return "\"IID_ID3D12Device10\"";
    if (iid == IID_ID3D12Device11)
        return "\"IID_ID3D12Device11\"";
    if (iid == IID_ID3D12DebugDevice1)
        return "\"IID_ID3D12DebugDevice1\"";
    if (iid == IID_ID3D12DebugDevice)
        return "\"IID_ID3D12DebugDevice\"";
    if (iid == IID_ID3D12DebugDevice2)
        return "\"IID_ID3D12DebugDevice2\"";
    return "\"Invalid IID\"";
}

std::string FeatureLevelToString(const D3D_FEATURE_LEVEL& value)
{
    switch (value)
    {
        case D3D_FEATURE_LEVEL_1_0_CORE:
            return "D3D_FEATURE_LEVEL_1_0_CORE";
        case D3D_FEATURE_LEVEL_9_1:
            return "D3D_FEATURE_LEVEL_9_1";
        case D3D_FEATURE_LEVEL_9_2:
            return "D3D_FEATURE_LEVEL_9_2";
        case D3D_FEATURE_LEVEL_9_3:
            return "D3D_FEATURE_LEVEL_9_3";
        case D3D_FEATURE_LEVEL_10_0:
            return "D3D_FEATURE_LEVEL_10_0";
        case D3D_FEATURE_LEVEL_10_1:
            return "D3D_FEATURE_LEVEL_10_1";
        case D3D_FEATURE_LEVEL_11_0:
            return "D3D_FEATURE_LEVEL_11_0";
        case D3D_FEATURE_LEVEL_11_1:
            return "D3D_FEATURE_LEVEL_11_1";
        case D3D_FEATURE_LEVEL_12_0:
            return "D3D_FEATURE_LEVEL_12_0";
        case D3D_FEATURE_LEVEL_12_1:
            return "D3D_FEATURE_LEVEL_12_1";
        case D3D_FEATURE_LEVEL_12_2:
            return "D3D_FEATURE_LEVEL_12_2";
        default:
            break;
    }
    return "Unhandled D3D_FEATURE_LEVEL";
}

std::string DisplayModeToString(const AGSDisplaySettings::Mode mode)
{
    switch (mode)
    {
        case AGSDisplaySettings::Mode::Mode_SDR:
            return "Mode_HDR10_PQ";
        case AGSDisplaySettings::Mode::Mode_HDR10_PQ:
            return "Mode_HDR10_PQ";
        case AGSDisplaySettings::Mode::Mode_HDR10_scRGB:
            return "Mode_HDR10_scRGB";
        case AGSDisplaySettings::Mode::Mode_FreesyncHDR_scRGB:
            return "Mode_FreesyncHDR_scRGB";
        case AGSDisplaySettings::Mode::Mode_FreesyncHDR_Gamma22:
            return "Mode_FreesyncHDR_Gamma22";
        default:
            break;
    }
    return "Unknown mode value";
}

void AgsAsciiConsumer::Initialize(FILE* file, gfxrecon::util::ToStringFlags to_string_flags)
{
    GFXRECON_ASSERT(file);
    file_            = file;
    to_string_flags_ = to_string_flags;
}

void AgsAsciiConsumer::Destroy()
{
    if (file_)
    {
        file_ = nullptr;
    }
}

void AgsAsciiConsumer::Process_agsInitialize(const ApiCallInfo&      call_info,
                                             AGSReturnCode           return_value,
                                             int                     agsVersion,
                                             const AGSConfiguration* config,
                                             AGSContext* const       context,
                                             const AGSGPUInfo&       gpuInfo)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteAgsCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.block_index   = current_block_index_;
    writeApiCallToFileInfo.pFunctionName = "agsInitialize";
    std::string returnValue              = util::ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue  = !returnValue.empty() ? returnValue.c_str() : nullptr;
    int      major                       = (agsVersion & 0xFFC00000) >> 22;
    int      minor                       = (agsVersion & 0x003FF000) >> 12;
    int      patch                       = (agsVersion & 0x00000FFF);
    uint64_t allocCallback{ 0 };
    uint64_t freeCallback{ 0 };
    if (config != nullptr)
    {
        allocCallback = reinterpret_cast<uint64_t>(config->allocCallback);
        freeCallback  = reinterpret_cast<uint64_t>(config->freeCallback);
    }
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm,
                      true,
                      "ags version, major",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(major, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "ags version, minor",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(minor, to_string_flags_, tab_count, tab_size));
        FieldToString(str_strm,
                      false,
                      "ags version, patch",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(patch, to_string_flags_, tab_count, tab_size));
        FieldToString(
            str_strm, false, "ags alloc callback", to_string_flags_, tab_count, tab_size, PtrToString(allocCallback));
        FieldToString(
            str_strm, false, "ags free callback", to_string_flags_, tab_count, tab_size, PtrToString(freeCallback));
        FieldToString(str_strm, false, "[out]ags context", to_string_flags_, tab_count, tab_size, PtrToString(context));
        FieldToString(
            str_strm,
            false,
            "[out]gpuInfo",
            to_string_flags_,
            tab_count,
            tab_size,
            ObjectToString(to_string_flags_, tab_count, tab_size, [&](std::stringstream& strStrm) {
                FieldToString(
                    strStrm, true, "driverVersion", to_string_flags_, tab_count, tab_size, gpuInfo.driverVersion);
                FieldToString(strStrm,
                              false,
                              "radeonSoftwareVersion",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              gpuInfo.radeonSoftwareVersion);
                FieldToString(
                    strStrm, false, "numDevices", to_string_flags_, tab_count, tab_size, ToString(gpuInfo.numDevices));
                AGSDeviceInfo* returned_devices = gpuInfo.devices;
                FieldToString(strStrm,
                              false,
                              "devices",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              StringOfDevices(gpuInfo.numDevices, returned_devices, tab_count, tab_size));
            }));
    });
}

void AgsAsciiConsumer::Process_agsDriverExtensionsDX12_CreateDevice(
    const ApiCallInfo&                                    call_info,
    AGSReturnCode                                         return_value,
    AGSContext*                                           context,
    AGSDX12DeviceCreationParams*                          creationParams,
    const AGSDX12ExtensionParams*                         extensionParams,
    StructPointerDecoder<Decoded_AGS_DX12_RETURN_PARAMS>* pReturnParams)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteAgsCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.block_index   = current_block_index_;
    writeApiCallToFileInfo.pFunctionName = "agsDriverExtensionsDX12_CreateDevice";
    std::string returnValue              = util::ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue  = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm, true, "ags context", to_string_flags_, tab_count, tab_size, PtrToString(context));

        FieldToString(str_strm,
                      false,
                      "creationParams",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ObjectToString(to_string_flags_, tab_count, tab_size, [&](std::stringstream& strStrm) {
                          FieldToString(strStrm,
                                        true,
                                        "pAdapter",
                                        to_string_flags_,
                                        tab_count,
                                        tab_size,
                                        PtrToString(creationParams->pAdapter));
                          FieldToString(strStrm,
                                        false,
                                        "riid",
                                        to_string_flags_,
                                        tab_count,
                                        tab_size,
                                        ToString(creationParams->iid, to_string_flags_, tab_count, tab_size));
                          FieldToString(strStrm,
                                        false,
                                        "FeatureLevel",
                                        to_string_flags_,
                                        tab_count,
                                        tab_size,
                                        FeatureLevelToString(creationParams->FeatureLevel));
                      }));

        FieldToString(str_strm,
                      false,
                      "extensionParams",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ObjectToString(to_string_flags_, tab_count, tab_size, [&](std::stringstream& strStrm) {
                          FieldToString(strStrm,
                                        true,
                                        "pAppName",
                                        to_string_flags_,
                                        tab_count,
                                        tab_size,
                                        WCharArrayToString(extensionParams->pAppName));
                          FieldToString(strStrm,
                                        false,
                                        "pEngineName",
                                        to_string_flags_,
                                        tab_count,
                                        tab_size,
                                        WCharArrayToString(extensionParams->pEngineName));
                          FieldToString(strStrm,
                                        false,
                                        "appVersion",
                                        to_string_flags_,
                                        tab_count,
                                        tab_size,
                                        ToString(extensionParams->appVersion));
                          FieldToString(strStrm,
                                        false,
                                        "engineVersion",
                                        to_string_flags_,
                                        tab_count,
                                        tab_size,
                                        ToString(extensionParams->engineVersion));
                          FieldToString(strStrm,
                                        false,
                                        "uavSlot",
                                        to_string_flags_,
                                        tab_count,
                                        tab_size,
                                        ToString(extensionParams->uavSlot));
                      }));

        auto returned_params = pReturnParams->GetMetaStructPointer();
        FieldToString(str_strm,
                      false,
                      "pReturnParams",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ObjectToString(to_string_flags_, tab_count, tab_size, [&](std::stringstream& strStrm) {
                          FieldToString(strStrm,
                                        true,
                                        "pDevice",
                                        to_string_flags_,
                                        tab_count,
                                        tab_size,
                                        PtrToString(returned_params->pDevice));
                          auto extensions_supported = returned_params->extensionsSupported->decoded_value;
                          FieldToString(
                              strStrm,
                              false,
                              "extensionsSupported",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ObjectToString(to_string_flags_, tab_count, tab_size, [&](std::stringstream& strStrm) {
                                  FieldToString(strStrm,
                                                true,
                                                "intrinsics16",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->intrinsics16));
                                  FieldToString(strStrm,
                                                false,
                                                "intrinsics17",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->intrinsics17));
                                  FieldToString(strStrm,
                                                false,
                                                "userMarkers",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->userMarkers));
                                  FieldToString(strStrm,
                                                false,
                                                "appRegistration",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->appRegistration));
                                  FieldToString(strStrm,
                                                false,
                                                "UAVBindSlot",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->UAVBindSlot));
                                  FieldToString(strStrm,
                                                false,
                                                "intrinsics19",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->intrinsics19));
                                  FieldToString(strStrm,
                                                false,
                                                "baseVertex",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->baseVertex));
                                  FieldToString(strStrm,
                                                false,
                                                "baseInstance",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->baseInstance));
                                  FieldToString(strStrm,
                                                false,
                                                "getWaveSize",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->getWaveSize));
                                  FieldToString(strStrm,
                                                false,
                                                "floatConversion",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->floatConversion));
                                  FieldToString(strStrm,
                                                false,
                                                "readLaneAt",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->readLaneAt));
                                  FieldToString(strStrm,
                                                false,
                                                "rayHitToken",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->rayHitToken));
                                  FieldToString(strStrm,
                                                false,
                                                "padding",
                                                to_string_flags_,
                                                tab_count,
                                                tab_size,
                                                ToString(extensions_supported->padding));
                              }));
                      }));
    });
}

void AgsAsciiConsumer::Process_agsDriverExtensionsDX12_DestroyDevice(const ApiCallInfo& call_info,
                                                                     AGSReturnCode      return_value,
                                                                     AGSContext*        context,
                                                                     ID3D12Device*      device,
                                                                     unsigned int*      deviceReferences)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteAgsCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.block_index   = current_block_index_;
    writeApiCallToFileInfo.pFunctionName = "agsDriverExtensionsDX12_DestroyDevice";
    std::string returnValue              = util::ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue  = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm, true, "ags context", to_string_flags_, tab_count, tab_size, PtrToString(context));
        FieldToString(str_strm, false, "device", to_string_flags_, tab_count, tab_size, PtrToString(device));
        FieldToString(
            str_strm, false, "deviceReferences", to_string_flags_, tab_count, tab_size, PtrToString(deviceReferences));
    });
}

void AgsAsciiConsumer::Process_agsDeInitialize(const ApiCallInfo& call_info,
                                               AGSReturnCode      return_value,
                                               AGSContext*        context)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteAgsCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.block_index   = current_block_index_;
    writeApiCallToFileInfo.pFunctionName = "agsDeInitialize";
    std::string returnValue              = util::ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue  = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm, true, "ags context", to_string_flags_, tab_count, tab_size, PtrToString(context));
    });
}

void AgsAsciiConsumer::Process_agsCheckDriverVersion(const ApiCallInfo&     call_info,
                                                     AGSDriverVersionResult return_value,
                                                     const char*            radeonSoftwareVersionReported,
                                                     unsigned int           radeonSoftwareVersionRequired)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteAgsCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.block_index   = current_block_index_;
    writeApiCallToFileInfo.pFunctionName = "agsCheckDriverVersion";
    std::string returnValue              = util::ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue  = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm,
                      true,
                      "radeonSoftwareVersionReported",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      radeonSoftwareVersionReported);
        FieldToString(str_strm,
                      false,
                      "radeonSoftwareVersionRequired",
                      to_string_flags_,
                      tab_count,
                      tab_size,
                      ToString(radeonSoftwareVersionRequired));
    });
}

void AgsAsciiConsumer::Process_agsGetVersionNumber(const ApiCallInfo& call_info, int return_value)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteAgsCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.block_index   = current_block_index_;
    writeApiCallToFileInfo.pFunctionName = "agsGetVersionNumber";
    std::string returnValue              = util::ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue  = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {});
}

void AgsAsciiConsumer::Process_agsSetDisplayMode(const ApiCallInfo&        call_info,
                                                 AGSReturnCode             return_value,
                                                 AGSContext*               context,
                                                 int                       deviceIndex,
                                                 int                       displayIndex,
                                                 const AGSDisplaySettings* settings)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteAgsCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.block_index   = current_block_index_;
    writeApiCallToFileInfo.pFunctionName = "agsSetDisplayMode";
    std::string returnValue              = util::ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue  = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm, true, "ags context", to_string_flags_, tab_count, tab_size, PtrToString(context));
        FieldToString(str_strm, false, "deviceIndex", to_string_flags_, tab_count, tab_size, ToString(deviceIndex));
        FieldToString(str_strm, false, "displayIndex", to_string_flags_, tab_count, tab_size, ToString(displayIndex));
        FieldToString(
            str_strm,
            false,
            "settings",
            to_string_flags_,
            tab_count,
            tab_size,
            ObjectToString(to_string_flags_, tab_count, tab_size, [&](std::stringstream& strStrm) {
                FieldToString(
                    strStrm, true, "Mode", to_string_flags_, tab_count, tab_size, DisplayModeToString(settings->mode));
                FieldToString(strStrm,
                              false,
                              "chromaticityRedX",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->chromaticityRedX));
                FieldToString(strStrm,
                              false,
                              "chromaticityRedY",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->chromaticityRedY));
                FieldToString(strStrm,
                              false,
                              "chromaticityGreenX",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->chromaticityGreenX));
                FieldToString(strStrm,
                              false,
                              "chromaticityGreenY",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->chromaticityGreenY));
                FieldToString(strStrm,
                              false,
                              "chromaticityBlueX",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->chromaticityBlueX));
                FieldToString(strStrm,
                              false,
                              "chromaticityBlueY",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->chromaticityBlueY));
                FieldToString(strStrm,
                              false,
                              "chromaticityWhitePointX",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->chromaticityWhitePointX));
                FieldToString(strStrm,
                              false,
                              "chromaticityWhitePointY",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->chromaticityWhitePointY));
                FieldToString(strStrm,
                              false,
                              "minLuminance",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->minLuminance));
                FieldToString(strStrm,
                              false,
                              "maxLuminance",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->maxLuminance));
                FieldToString(strStrm,
                              false,
                              "maxContentLightLevel",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->maxContentLightLevel));
                FieldToString(strStrm,
                              false,
                              "maxFrameAverageLightLevel",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->maxFrameAverageLightLevel));
                FieldToString(strStrm,
                              false,
                              "disableLocalDimming",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->disableLocalDimming));
                FieldToString(strStrm,
                              false,
                              "reservedPadding",
                              to_string_flags_,
                              tab_count,
                              tab_size,
                              ToString(settings->reservedPadding));
            }));
    });
}

void AgsAsciiConsumer::Process_agsDriverExtensionsDX12_PushMarker(const ApiCallInfo& call_info,
                                                                  AGSReturnCode      return_value,
                                                                  AGSContext*        context,
                                                                  format::HandleId   object_id,
                                                                  const char*        data)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteAgsCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.block_index   = current_block_index_;
    writeApiCallToFileInfo.pFunctionName = "agsDriverExtensionsDX12_PushMarker";
    std::string returnValue              = util::ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue  = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm, true, "ags context", to_string_flags_, tab_count, tab_size, PtrToString(context));
        FieldToString(str_strm, false, "object_id", to_string_flags_, tab_count, tab_size, ToString(object_id));
        FieldToString(str_strm, false, "data", to_string_flags_, tab_count, tab_size, data);
    });
}

void AgsAsciiConsumer::Process_agsDriverExtensionsDX12_PopMarker(const ApiCallInfo& call_info,
                                                                 AGSReturnCode      return_value,
                                                                 AGSContext*        context,
                                                                 format::HandleId   object_id)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteAgsCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.block_index   = current_block_index_;
    writeApiCallToFileInfo.pFunctionName = "agsDriverExtensionsDX12_PopMarker";
    std::string returnValue              = util::ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue  = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm, true, "ags context", to_string_flags_, tab_count, tab_size, PtrToString(context));
        FieldToString(str_strm, false, "object_id", to_string_flags_, tab_count, tab_size, ToString(object_id));
    });
}

void AgsAsciiConsumer::Process_agsDriverExtensionsDX12_SetMarker(const ApiCallInfo& call_info,
                                                                 AGSReturnCode      return_value,
                                                                 AGSContext*        context,
                                                                 format::HandleId   object_id,
                                                                 const char*        data)
{
    using namespace gfxrecon::util;
    uint32_t               tab_count = 0;
    uint32_t               tab_size  = 4;
    WriteAgsCallToFileInfo writeApiCallToFileInfo{};
    writeApiCallToFileInfo.block_index   = current_block_index_;
    writeApiCallToFileInfo.pFunctionName = "agsDriverExtensionsDX12_SetMarker";
    std::string returnValue              = util::ToString(return_value, to_string_flags_, tab_count, tab_size);
    writeApiCallToFileInfo.pReturnValue  = !returnValue.empty() ? returnValue.c_str() : nullptr;
    WriteApiCallToFile(writeApiCallToFileInfo, tab_count, tab_size, [&](std::stringstream& str_strm) {
        FieldToString(str_strm, true, "ags context", to_string_flags_, tab_count, tab_size, PtrToString(context));
        FieldToString(str_strm, false, "object_id", to_string_flags_, tab_count, tab_size, ToString(object_id));
        FieldToString(str_strm, false, "data", to_string_flags_, tab_count, tab_size, data);
    });
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
