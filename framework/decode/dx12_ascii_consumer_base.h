/*
** Copyright (c) 2021-2023 LunarG, Inc.
** Copyright (c) 2023 Qualcomm Innovation Center, Inc. All rights reserved.
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

#ifndef GFXRECON_DECODE_DX12_ASCII_CONSUMER_BASE_H
#define GFXRECON_DECODE_DX12_ASCII_CONSUMER_BASE_H

#include "generated/generated_dx12_consumer.h"
#include "util/to_string.h"

#include <cctype>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class Dx12AsciiConsumerBase : public Dx12Consumer
{
  public:
    Dx12AsciiConsumerBase();
    virtual ~Dx12AsciiConsumerBase();

    void Initialize(FILE* file, gfxrecon::util::ToStringFlags toStringFlags);

    void Destroy();

    bool IsValid() const { return (file_ != nullptr); }

    const std::string& GetFilename() const { return filename_; }

    void Process_ID3D12Device_CheckFeatureSupport(format::HandleId object_id,
                                                  HRESULT          original_result,
                                                  D3D12_FEATURE    feature,
                                                  const void*      capture_feature_data,
                                                  void*            replay_feature_data,
                                                  UINT             feature_data_size) override;

    void Process_IDXGIFactory5_CheckFeatureSupport(format::HandleId object_id,
                                                   HRESULT          original_result,
                                                   DXGI_FEATURE     feature,
                                                   const void*      capture_feature_data,
                                                   void*            replay_feature_data,
                                                   UINT             feature_data_size) override;

    void Process_ID3D12Resource_WriteToSubresource(format::HandleId                         object_id,
                                                   HRESULT                                  original_result,
                                                   UINT                                     DstSubresource,
                                                   StructPointerDecoder<Decoded_D3D12_BOX>* pDstBox,
                                                   void*                                    pSrcData,
                                                   UINT                                     SrcRowPitch,
                                                   UINT                                     SrcDepthPitch) override;

    void Process_ID3D11Device_CheckFeatureSupport(const ApiCallInfo& call_info,
                                                  format::HandleId   object_id,
                                                  HRESULT            return_value,
                                                  D3D11_FEATURE      feature,
                                                  const void*        capture_feature_data,
                                                  void*              replay_feature_data,
                                                  UINT               feature_data_size) override;

    void Process_ID3D11Device_CreateBuffer(const ApiCallInfo&                                    call_info,
                                           format::HandleId                                      object_id,
                                           HRESULT                                               return_value,
                                           StructPointerDecoder<Decoded_D3D11_BUFFER_DESC>*      pDesc,
                                           StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                           HandlePointerDecoder<ID3D11Buffer*>*                  ppBuffer) override;

    void Process_ID3D11Device_CreateTexture1D(const ApiCallInfo&                                    call_info,
                                              format::HandleId                                      object_id,
                                              HRESULT                                               return_value,
                                              StructPointerDecoder<Decoded_D3D11_TEXTURE1D_DESC>*   pDesc,
                                              StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                              HandlePointerDecoder<ID3D11Texture1D*>* ppTexture1D) override;

    void Process_ID3D11Device_CreateTexture2D(const ApiCallInfo&                                    call_info,
                                              format::HandleId                                      object_id,
                                              HRESULT                                               return_value,
                                              StructPointerDecoder<Decoded_D3D11_TEXTURE2D_DESC>*   pDesc,
                                              StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                              HandlePointerDecoder<ID3D11Texture2D*>* ppTexture2D) override;

    void Process_ID3D11Device_CreateTexture3D(const ApiCallInfo&                                    call_info,
                                              format::HandleId                                      object_id,
                                              HRESULT                                               return_value,
                                              StructPointerDecoder<Decoded_D3D11_TEXTURE3D_DESC>*   pDesc,
                                              StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                              HandlePointerDecoder<ID3D11Texture3D*>* ppTexture3D) override;

    void Process_ID3D11DeviceContext_UpdateSubresource(const ApiCallInfo&                       call_info,
                                                       format::HandleId                         object_id,
                                                       format::HandleId                         pDstResource,
                                                       UINT                                     DstSubresource,
                                                       StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                       PointerDecoder<uint8_t>*                 pSrcData,
                                                       UINT                                     SrcRowPitch,
                                                       UINT                                     SrcDepthPitch) override;

    void Process_ID3D11DeviceContext1_UpdateSubresource1(const ApiCallInfo&                       call_info,
                                                         format::HandleId                         object_id,
                                                         format::HandleId                         pDstResource,
                                                         UINT                                     DstSubresource,
                                                         StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                         PointerDecoder<uint8_t>*                 pSrcData,
                                                         UINT                                     SrcRowPitch,
                                                         UINT                                     SrcDepthPitch,
                                                         UINT                                     CopyFlags) override;

    virtual void
    Process_ID3D11Device3_CreateTexture2D1(const ApiCallInfo&                                    call_info,
                                           format::HandleId                                      object_id,
                                           HRESULT                                               return_value,
                                           StructPointerDecoder<Decoded_D3D11_TEXTURE2D_DESC1>*  pDesc,
                                           StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                           HandlePointerDecoder<ID3D11Texture2D1*>*              ppTexture2D) override;

    virtual void
    Process_ID3D11Device3_CreateTexture3D1(const ApiCallInfo&                                    call_info,
                                           format::HandleId                                      object_id,
                                           HRESULT                                               return_value,
                                           StructPointerDecoder<Decoded_D3D11_TEXTURE3D_DESC1>*  pDesc,
                                           StructPointerDecoder<Decoded_D3D11_SUBRESOURCE_DATA>* pInitialData,
                                           HandlePointerDecoder<ID3D11Texture3D1*>*              ppTexture3D) override;

    virtual void Process_ID3D11Device3_WriteToSubresource(const ApiCallInfo&                       call_info,
                                                          format::HandleId                         object_id,
                                                          format::HandleId                         pDstResource,
                                                          UINT                                     DstSubresource,
                                                          StructPointerDecoder<Decoded_D3D11_BOX>* pDstBox,
                                                          PointerDecoder<uint8_t>*                 pSrcData,
                                                          UINT                                     SrcRowPitch,
                                                          UINT SrcDepthPitch) override;

  protected:
    FILE*                         GetFile() const { return file_; }
    uint32_t                      current_frame_number_{ 0 };
    gfxrecon::util::ToStringFlags to_string_flags_{ gfxrecon::util::kToString_Default };

    struct WriteApiCallToFileInfo
    {
        const char*      pObjectTypeName{};
        format::HandleId handleId{};
        const char*      pFunctionName{};
        const char*      pReturnValue{};
    };

    // clang-format off
    template <typename ToStringFunctionType>
    inline void WriteApiCallToFile(const WriteApiCallToFileInfo& writeApiCallToFileInfo, uint32_t& tabCount, uint32_t tabSize, ToStringFunctionType toStringFunction)
    {
        using namespace util;
        using namespace util::platform;

        // Add a comma between top-level JSON objects if we are not generating JSON Lines.
        if (to_string_flags_ & kToString_Formatted) {
            FilePuts(",\n", file_);
        }
        else
        {
            FilePuts("\n", file_);
        }

        fprintf(file_, "%s", ObjectToString(to_string_flags_, tabCount, tabSize,
            [&](std::stringstream& strStrm)
            {
                // Output the API call index
                FieldToString(strStrm, true, "index", to_string_flags_, tabCount, tabSize, ToString(api_call_count_++, to_string_flags_, tabCount, tabSize));

                // Output the method/function name
                assert(writeApiCallToFileInfo.pFunctionName);
                auto fieldName = writeApiCallToFileInfo.pObjectTypeName ? "method" : "function";
                FieldToString(strStrm, false, fieldName, to_string_flags_, tabCount, tabSize, util::Quote(writeApiCallToFileInfo.pFunctionName));

                // If the API call is an object method we output the object type and handle
                if (writeApiCallToFileInfo.pObjectTypeName) {
                    FieldToString(strStrm, false, "object", to_string_flags_, tabCount, tabSize,
                        ObjectToString(to_string_flags_, tabCount, tabSize,
                            [&](std::stringstream& objectStrStrm)
                            {
                                FieldToString(objectStrStrm, true, "type", to_string_flags_, tabCount, tabSize, util::Quote(writeApiCallToFileInfo.pObjectTypeName) + '"');
                                FieldToString(objectStrStrm, false, "handle", to_string_flags_, tabCount, tabSize, HandleIdToString(writeApiCallToFileInfo.handleId));
                            }
                        )
                    );
                }

                // Output the return value
                if (writeApiCallToFileInfo.pReturnValue)
                {
                    FieldToString(strStrm, false, "return", to_string_flags_, tabCount, tabSize, std::string(writeApiCallToFileInfo.pReturnValue));
                }

                // Output the method/function parameters
                const auto& parametersStr = ObjectToString(to_string_flags_, tabCount, tabSize, toStringFunction);
                for (auto c : parametersStr)
                {
                    if (c != '{' && !isspace(static_cast<unsigned char>(c)) && c != '}')
                    {
                        FieldToString(strStrm, false, "parameters", to_string_flags_, tabCount, tabSize, parametersStr);
                        break;
                    }
                }
                return strStrm.str();
            }
        ).c_str());
    }
    // clang-format on

  private:
    FILE*       file_{ nullptr };
    std::string filename_;
    uint64_t    api_call_count_{ 0 };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_DX12_ASCII_CONSUMER_BASE_H
