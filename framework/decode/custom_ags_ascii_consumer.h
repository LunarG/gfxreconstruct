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

#ifndef GFXRECON_CUSTOM_AGS_ASCII_CONSUMER_H
#define GFXRECON_CUSTOM_AGS_ASCII_CONSUMER_H

#include "custom_ags_consumer_base.h"
#include "custom_dx12_to_string.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class AgsAsciiConsumer : public AgsConsumerBase
{
  public:
    AgsAsciiConsumer() {}
    virtual ~AgsAsciiConsumer() override {}

    virtual void Process_agsInitialize(const ApiCallInfo&      call_info,
                                       AGSReturnCode           return_value,
                                       int                     agsVersion,
                                       const AGSConfiguration* config,
                                       AGSContext* const       context,
                                       const AGSGPUInfo&       gpuInfo) override;

    virtual void Process_agsDriverExtensionsDX12_CreateDevice(
        const ApiCallInfo&                                    call_info,
        AGSReturnCode                                         return_value,
        AGSContext*                                           context,
        AGSDX12DeviceCreationParams*                          creationParams,
        const AGSDX12ExtensionParams*                         extensionParams,
        StructPointerDecoder<Decoded_AGS_DX12_RETURN_PARAMS>* pReturnParams) override;

    virtual void Process_agsDriverExtensionsDX12_DestroyDevice(const ApiCallInfo& call_info,
                                                               AGSReturnCode      return_value,
                                                               AGSContext*        context,
                                                               ID3D12Device*      device,
                                                               unsigned int*      deviceReferences) override;

    virtual void
    Process_agsDeInitialize(const ApiCallInfo& call_info, AGSReturnCode return_value, AGSContext* context) override;

    virtual void Process_agsCheckDriverVersion(const ApiCallInfo&     call_info,
                                               AGSDriverVersionResult return_value,
                                               const char*            radeonSoftwareVersionReported,
                                               unsigned int           radeonSoftwareVersionRequired) override;

    virtual void Process_agsGetVersionNumber(const ApiCallInfo& call_info, int return_value) override;

    virtual void Process_agsSetDisplayMode(const ApiCallInfo&        call_info,
                                           AGSReturnCode             return_value,
                                           AGSContext*               context,
                                           int                       deviceIndex,
                                           int                       displayIndex,
                                           const AGSDisplaySettings* settings) override;

    virtual void Process_agsDriverExtensionsDX12_PushMarker(const ApiCallInfo& call_info,
                                                            AGSReturnCode      return_value,
                                                            AGSContext*        context,
                                                            format::HandleId   object_id,
                                                            const char*        data) override;

    virtual void Process_agsDriverExtensionsDX12_PopMarker(const ApiCallInfo& call_info,
                                                           AGSReturnCode      return_value,
                                                           AGSContext*        context,
                                                           format::HandleId   object_id) override;

    virtual void Process_agsDriverExtensionsDX12_SetMarker(const ApiCallInfo& call_info,
                                                           AGSReturnCode      return_value,
                                                           AGSContext*        context,
                                                           format::HandleId   object_id,
                                                           const char*        data) override;

    void Initialize(FILE* file, gfxrecon::util::ToStringFlags toStringFlags);

    void Destroy();

  private:
    struct WriteAgsCallToFileInfo
    {
        int         block_index{ 0 };
        const char* pFunctionName{};
        const char* pReturnValue{};
    };

    template <typename ToStringFunctionType>
    inline void WriteApiCallToFile(const WriteAgsCallToFileInfo& writeApiCallToFileInfo,
                                   uint32_t&                     tabCount,
                                   uint32_t                      tabSize,
                                   ToStringFunctionType          toStringFunction)
    {
        using namespace util;
        using namespace util::platform;

        // Add a comma between top-level JSON objects if we are not generating JSON Lines.
        if (to_string_flags_ & kToString_Formatted)
        {
            FilePuts(",\n", file_);
        }
        else
        {
            FilePuts("\n", file_);
        }

        fprintf(file_,
                "%s",
                ObjectToString(to_string_flags_, tabCount, tabSize, [&](std::stringstream& strStrm) {
                    // Output the call block index
                    FieldToString(strStrm,
                                  true,
                                  "index",
                                  to_string_flags_,
                                  tabCount,
                                  tabSize,
                                  ToString(writeApiCallToFileInfo.block_index, to_string_flags_, tabCount, tabSize));

                    auto fieldName = "function";
                    FieldToString(strStrm,
                                  false,
                                  fieldName,
                                  to_string_flags_,
                                  tabCount,
                                  tabSize,
                                  '"' + std::string(writeApiCallToFileInfo.pFunctionName) + '"');

                    // Output the return value
                    if (writeApiCallToFileInfo.pReturnValue)
                    {
                        FieldToString(strStrm,
                                      false,
                                      "return",
                                      to_string_flags_,
                                      tabCount,
                                      tabSize,
                                      std::string(writeApiCallToFileInfo.pReturnValue));
                    }

                    // Output the method/function parameters
                    const auto& parametersStr = ObjectToString(to_string_flags_, tabCount, tabSize, toStringFunction);
                    for (auto c : parametersStr)
                    {
                        if (c != '{' && !isspace(static_cast<unsigned char>(c)) && c != '}')
                        {
                            FieldToString(
                                strStrm, false, "parameters", to_string_flags_, tabCount, tabSize, parametersStr);
                            break;
                        }
                    }
                    return strStrm.str();
                }).c_str());
    }

    inline void AddStringOfAGSRect(
        std::stringstream& strStrm, const char* name, AGSRect rect, uint32_t tab_count, uint32_t tab_size)
    {
        using namespace util;
        FieldToString(
            strStrm,
            false,
            name,
            to_string_flags_,
            tab_count,
            tab_size,
            ObjectToString(to_string_flags_, tab_count, tab_size, [&](std::stringstream& strStrm) {
                FieldToString(strStrm, true, "offsetX", to_string_flags_, tab_count, tab_size, ToString(rect.offsetX));
                FieldToString(strStrm, false, "offsetY", to_string_flags_, tab_count, tab_size, ToString(rect.offsetY));
                FieldToString(strStrm, false, "width", to_string_flags_, tab_count, tab_size, ToString(rect.width));
                FieldToString(strStrm, false, "height", to_string_flags_, tab_count, tab_size, ToString(rect.height));
            }));
    }

    inline std::string
    StringOfDisplays(int num_displays, const AGSDisplayInfo* returned_displays, uint32_t tab_count, uint32_t tab_size)
    {
        using namespace util;
        return ArrayToString<AGSDisplayInfo>(
            num_displays,
            returned_displays,
            to_string_flags_,
            tab_count,
            tab_size,
            [&]() { return returned_displays; },
            [&](size_t i) {
                std::stringstream local_stream;
                uint32_t          obj_tab_count = tab_count + 1;
                local_stream << ObjectToString(
                    to_string_flags_, obj_tab_count, tab_size, [&](std::stringstream& strStrm) {
                        FieldToString(strStrm,
                                      true,
                                      "name",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      returned_displays[i].name);
                        FieldToString(strStrm,
                                      false,
                                      "displayDeviceName",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      returned_displays[i].displayDeviceName);
                        FieldToString(strStrm,
                                      false,
                                      "isPrimaryDisplay",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].isPrimaryDisplay));
                        FieldToString(strStrm,
                                      false,
                                      "HDR10",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].HDR10));
                        FieldToString(strStrm,
                                      false,
                                      "dolbyVision",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].dolbyVision));
                        FieldToString(strStrm,
                                      false,
                                      "freesyncHDR",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].freesyncHDR));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityInGroup",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].eyefinityInGroup));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityPreferredDisplay",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].eyefinityPreferredDisplay));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityInPortraitMode",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].eyefinityInPortraitMode));
                        FieldToString(strStrm,
                                      false,
                                      "reservedPadding",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].reservedPadding));
                        FieldToString(strStrm,
                                      false,
                                      "maxResolutionX",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].maxResolutionX));
                        FieldToString(strStrm,
                                      false,
                                      "maxResolutionY",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].maxResolutionY));
                        FieldToString(strStrm,
                                      false,
                                      "maxRefreshRate",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].maxRefreshRate));

                        AddStringOfAGSRect(strStrm,
                                           "currentResolution",
                                           returned_displays[i].currentResolution,
                                           obj_tab_count,
                                           tab_size);
                        AddStringOfAGSRect(strStrm,
                                           "visibleResolution",
                                           returned_displays[i].visibleResolution,
                                           obj_tab_count,
                                           tab_size);
                        FieldToString(strStrm,
                                      false,
                                      "currentRefreshRate",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].currentRefreshRate));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityGridCoordX",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].eyefinityGridCoordX));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityGridCoordY",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].eyefinityGridCoordY));
                        FieldToString(strStrm,
                                      false,
                                      "chromaticityRedX",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].chromaticityRedX));
                        FieldToString(strStrm,
                                      false,
                                      "chromaticityRedY",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].chromaticityRedY));
                        FieldToString(strStrm,
                                      false,
                                      "chromaticityGreenX",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].chromaticityGreenX));
                        FieldToString(strStrm,
                                      false,
                                      "chromaticityGreenY",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].chromaticityGreenY));
                        FieldToString(strStrm,
                                      false,
                                      "chromaticityBlueX",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].chromaticityBlueX));
                        FieldToString(strStrm,
                                      false,
                                      "chromaticityBlueY",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].chromaticityBlueY));
                        FieldToString(strStrm,
                                      false,
                                      "chromaticityWhitePointX",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].chromaticityWhitePointX));
                        FieldToString(strStrm,
                                      false,
                                      "chromaticityWhitePointY",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].chromaticityWhitePointY));
                        FieldToString(strStrm,
                                      false,
                                      "screenDiffuseReflectance",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].screenDiffuseReflectance));
                        FieldToString(strStrm,
                                      false,
                                      "screenSpecularReflectance",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].screenSpecularReflectance));
                        FieldToString(strStrm,
                                      false,
                                      "minLuminance",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].minLuminance));
                        FieldToString(strStrm,
                                      false,
                                      "maxLuminance",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].maxLuminance));
                        FieldToString(strStrm,
                                      false,
                                      "avgLuminance",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].avgLuminance));
                        FieldToString(strStrm,
                                      false,
                                      "logicalDisplayIndex",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].logicalDisplayIndex));
                        FieldToString(strStrm,
                                      false,
                                      "adlAdapterIndex",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].adlAdapterIndex));
                        FieldToString(strStrm,
                                      false,
                                      "reserved",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_displays[i].reserved));
                    });
                return local_stream.str();
            });
    }

    inline std::string
    StringOfDevices(int num_devices, const AGSDeviceInfo* returned_devices, uint32_t tab_count, uint32_t tab_size)
    {
        using namespace util;
        return ArrayToString<AGSDeviceInfo>(
            num_devices,
            returned_devices,
            to_string_flags_,
            tab_count,
            tab_size,
            [&]() { return returned_devices; },
            [&](size_t i) {
                std::stringstream local_stream;
                uint32_t          obj_tab_count = tab_count + 1;

                local_stream << ObjectToString(
                    to_string_flags_, obj_tab_count, tab_size, [&](std::stringstream& strStrm) {
                        FieldToString(strStrm,
                                      true,
                                      "adapterString",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      returned_devices[i].adapterString);
                        FieldToString(strStrm,
                                      false,
                                      "asicFamily",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].asicFamily));
                        FieldToString(strStrm,
                                      false,
                                      "isAPU",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].isAPU));
                        FieldToString(strStrm,
                                      false,
                                      "isPrimaryDevice",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].isPrimaryDevice));
                        FieldToString(strStrm,
                                      false,
                                      "isExternal",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].isExternal));
                        FieldToString(strStrm,
                                      false,
                                      "reservedPadding",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].reservedPadding));
                        FieldToString(strStrm,
                                      false,
                                      "vendorId",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].vendorId));
                        FieldToString(strStrm,
                                      false,
                                      "deviceId",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].deviceId));
                        FieldToString(strStrm,
                                      false,
                                      "revisionId",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].revisionId));
                        FieldToString(strStrm,
                                      false,
                                      "numCUs",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].numCUs));
                        FieldToString(strStrm,
                                      false,
                                      "numWGPs",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].numWGPs));
                        FieldToString(strStrm,
                                      false,
                                      "numROPs",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].numROPs));
                        FieldToString(strStrm,
                                      false,
                                      "coreClock",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].coreClock));
                        FieldToString(strStrm,
                                      false,
                                      "memoryClock",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].memoryClock));
                        FieldToString(strStrm,
                                      false,
                                      "memoryBandwidth",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].memoryBandwidth));
                        FieldToString(strStrm,
                                      false,
                                      "teraFlops",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].teraFlops));
                        FieldToString(strStrm,
                                      false,
                                      "localMemoryInBytes",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].localMemoryInBytes));
                        FieldToString(strStrm,
                                      false,
                                      "sharedMemoryInBytes",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].sharedMemoryInBytes));
                        FieldToString(strStrm,
                                      false,
                                      "numDisplays",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].numDisplays));

                        AGSDisplayInfo* returned_displays = returned_devices[i].displays;
                        FieldToString(strStrm,
                                      false,
                                      "displays",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      StringOfDisplays(
                                          returned_devices[i].numDisplays, returned_displays, obj_tab_count, tab_size));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityEnabled",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].eyefinityEnabled));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityGridWidth",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].eyefinityGridWidth));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityGridHeight",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].eyefinityGridHeight));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityResolutionX",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].eyefinityResolutionX));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityResolutionY",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].eyefinityResolutionY));
                        FieldToString(strStrm,
                                      false,
                                      "eyefinityBezelCompensated",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].eyefinityBezelCompensated));
                        FieldToString(strStrm,
                                      false,
                                      "adlAdapterIndex",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].adlAdapterIndex));
                        FieldToString(strStrm,
                                      false,
                                      "reserved",
                                      to_string_flags_,
                                      obj_tab_count,
                                      tab_size,
                                      ToString(returned_devices[i].reserved));
                    });

                return local_stream.str();
            });
    }

    FILE*                         file_{ nullptr };
    gfxrecon::util::ToStringFlags to_string_flags_{ gfxrecon::util::kToString_Default };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_CUSTOM_AGS_ASCII_CONSUMER_H
