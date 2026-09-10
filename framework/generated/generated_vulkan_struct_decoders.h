/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2026 LunarG, Inc.
** Copyright (c) 2023 Advanced Micro Devices, Inc.
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

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#ifndef  GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_H
#define  GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_H

#include "decode/custom_vulkan_struct_decoders_forward.h"
#include "decode/handle_pointer_decoder.h"
#include "decode/pointer_decoder.h"
#include "decode/string_array_decoder.h"
#include "decode/string_decoder.h"
#include "decode/struct_pointer_decoder.h"
#include "decode/vulkan_decode_struct.h"
#include "decode/vulkan_pnext_node.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_schema_types.h"
#include "util/defines.h"
#include "util/logging.h"

#include "vulkan/vulkan.h"
#include "vk_video/vulkan_video_codec_h264std.h"
#include "vk_video/vulkan_video_codec_h264std_decode.h"
#include "vk_video/vulkan_video_codec_h264std_encode.h"
#include "vk_video/vulkan_video_codec_h265std.h"
#include "vk_video/vulkan_video_codec_h265std_decode.h"
#include "vk_video/vulkan_video_codec_h265std_encode.h"
#include "vk_video/vulkan_video_codecs_common.h"

#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct Decoded_StdVideoH264SpsVuiFlags
{
    using struct_type = StdVideoH264SpsVuiFlags;
    using api_element = schema::api_type::vulkan::StdVideoH264SpsVuiFlags;

    StdVideoH264SpsVuiFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH264HrdParameters
{
    using struct_type = StdVideoH264HrdParameters;
    using api_element = schema::api_type::vulkan::StdVideoH264HrdParameters;

    StdVideoH264HrdParameters* decoded_value{ nullptr };

    PointerDecoder<uint32_t> bit_rate_value_minus1;
    PointerDecoder<uint32_t> cpb_size_value_minus1;
    PointerDecoder<uint8_t> cbr_flag;
};

struct Decoded_StdVideoH264SequenceParameterSetVui
{
    using struct_type = StdVideoH264SequenceParameterSetVui;
    using api_element = schema::api_type::vulkan::StdVideoH264SequenceParameterSetVui;

    StdVideoH264SequenceParameterSetVui* decoded_value{ nullptr };

    Decoded_StdVideoH264SpsVuiFlags* flags{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264HrdParameters>* pHrdParameters{ nullptr };
};

struct Decoded_StdVideoH264SpsFlags
{
    using struct_type = StdVideoH264SpsFlags;
    using api_element = schema::api_type::vulkan::StdVideoH264SpsFlags;

    StdVideoH264SpsFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH264ScalingLists
{
    using struct_type = StdVideoH264ScalingLists;
    using api_element = schema::api_type::vulkan::StdVideoH264ScalingLists;

    StdVideoH264ScalingLists* decoded_value{ nullptr };

    PointerDecoder<uint8_t> ScalingList4x4;
    PointerDecoder<uint8_t> ScalingList8x8;
};

struct Decoded_StdVideoH264SequenceParameterSet
{
    using struct_type = StdVideoH264SequenceParameterSet;
    using api_element = schema::api_type::vulkan::StdVideoH264SequenceParameterSet;

    StdVideoH264SequenceParameterSet* decoded_value{ nullptr };

    Decoded_StdVideoH264SpsFlags* flags{ nullptr };
    PointerDecoder<int32_t> pOffsetForRefFrame;
    StructPointerDecoder<Decoded_StdVideoH264ScalingLists>* pScalingLists{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264SequenceParameterSetVui>* pSequenceParameterSetVui{ nullptr };
};

struct Decoded_StdVideoH264PpsFlags
{
    using struct_type = StdVideoH264PpsFlags;
    using api_element = schema::api_type::vulkan::StdVideoH264PpsFlags;

    StdVideoH264PpsFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH264PictureParameterSet
{
    using struct_type = StdVideoH264PictureParameterSet;
    using api_element = schema::api_type::vulkan::StdVideoH264PictureParameterSet;

    StdVideoH264PictureParameterSet* decoded_value{ nullptr };

    Decoded_StdVideoH264PpsFlags* flags{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264ScalingLists>* pScalingLists{ nullptr };
};

struct Decoded_StdVideoDecodeH264PictureInfoFlags
{
    using struct_type = StdVideoDecodeH264PictureInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoDecodeH264PictureInfoFlags;

    StdVideoDecodeH264PictureInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeH264PictureInfo
{
    using struct_type = StdVideoDecodeH264PictureInfo;
    using api_element = schema::api_type::vulkan::StdVideoDecodeH264PictureInfo;

    StdVideoDecodeH264PictureInfo* decoded_value{ nullptr };

    Decoded_StdVideoDecodeH264PictureInfoFlags* flags{ nullptr };
    PointerDecoder<int32_t> PicOrderCnt;
};

struct Decoded_StdVideoDecodeH264ReferenceInfoFlags
{
    using struct_type = StdVideoDecodeH264ReferenceInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoDecodeH264ReferenceInfoFlags;

    StdVideoDecodeH264ReferenceInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeH264ReferenceInfo
{
    using struct_type = StdVideoDecodeH264ReferenceInfo;
    using api_element = schema::api_type::vulkan::StdVideoDecodeH264ReferenceInfo;

    StdVideoDecodeH264ReferenceInfo* decoded_value{ nullptr };

    Decoded_StdVideoDecodeH264ReferenceInfoFlags* flags{ nullptr };
    PointerDecoder<int32_t> PicOrderCnt;
};

struct Decoded_StdVideoEncodeH264WeightTableFlags
{
    using struct_type = StdVideoEncodeH264WeightTableFlags;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264WeightTableFlags;

    StdVideoEncodeH264WeightTableFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264WeightTable
{
    using struct_type = StdVideoEncodeH264WeightTable;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264WeightTable;

    StdVideoEncodeH264WeightTable* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH264WeightTableFlags* flags{ nullptr };
    PointerDecoder<int8_t> luma_weight_l0;
    PointerDecoder<int8_t> luma_offset_l0;
    PointerDecoder<int8_t> chroma_weight_l0;
    PointerDecoder<int8_t> chroma_offset_l0;
    PointerDecoder<int8_t> luma_weight_l1;
    PointerDecoder<int8_t> luma_offset_l1;
    PointerDecoder<int8_t> chroma_weight_l1;
    PointerDecoder<int8_t> chroma_offset_l1;
};

struct Decoded_StdVideoEncodeH264SliceHeaderFlags
{
    using struct_type = StdVideoEncodeH264SliceHeaderFlags;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264SliceHeaderFlags;

    StdVideoEncodeH264SliceHeaderFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264PictureInfoFlags
{
    using struct_type = StdVideoEncodeH264PictureInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264PictureInfoFlags;

    StdVideoEncodeH264PictureInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264ReferenceInfoFlags
{
    using struct_type = StdVideoEncodeH264ReferenceInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264ReferenceInfoFlags;

    StdVideoEncodeH264ReferenceInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264ReferenceListsInfoFlags
{
    using struct_type = StdVideoEncodeH264ReferenceListsInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264ReferenceListsInfoFlags;

    StdVideoEncodeH264ReferenceListsInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264RefListModEntry
{
    using struct_type = StdVideoEncodeH264RefListModEntry;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264RefListModEntry;

    StdVideoEncodeH264RefListModEntry* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264RefPicMarkingEntry
{
    using struct_type = StdVideoEncodeH264RefPicMarkingEntry;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264RefPicMarkingEntry;

    StdVideoEncodeH264RefPicMarkingEntry* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264ReferenceListsInfo
{
    using struct_type = StdVideoEncodeH264ReferenceListsInfo;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264ReferenceListsInfo;

    StdVideoEncodeH264ReferenceListsInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH264ReferenceListsInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> RefPicList0;
    PointerDecoder<uint8_t> RefPicList1;
    PointerDecoder<uint8_t> reserved1;
    StructPointerDecoder<Decoded_StdVideoEncodeH264RefListModEntry>* pRefList0ModOperations{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH264RefListModEntry>* pRefList1ModOperations{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH264RefPicMarkingEntry>* pRefPicMarkingOperations{ nullptr };
};

struct Decoded_StdVideoEncodeH264PictureInfo
{
    using struct_type = StdVideoEncodeH264PictureInfo;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264PictureInfo;

    StdVideoEncodeH264PictureInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH264PictureInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> reserved1;
    StructPointerDecoder<Decoded_StdVideoEncodeH264ReferenceListsInfo>* pRefLists{ nullptr };
};

struct Decoded_StdVideoEncodeH264ReferenceInfo
{
    using struct_type = StdVideoEncodeH264ReferenceInfo;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264ReferenceInfo;

    StdVideoEncodeH264ReferenceInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH264ReferenceInfoFlags* flags{ nullptr };
};

struct Decoded_StdVideoEncodeH264SliceHeader
{
    using struct_type = StdVideoEncodeH264SliceHeader;
    using api_element = schema::api_type::vulkan::StdVideoEncodeH264SliceHeader;

    StdVideoEncodeH264SliceHeader* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH264SliceHeaderFlags* flags{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH264WeightTable>* pWeightTable{ nullptr };
};

struct Decoded_StdVideoVP9ColorConfigFlags
{
    using struct_type = StdVideoVP9ColorConfigFlags;
    using api_element = schema::api_type::vulkan::StdVideoVP9ColorConfigFlags;

    StdVideoVP9ColorConfigFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoVP9ColorConfig
{
    using struct_type = StdVideoVP9ColorConfig;
    using api_element = schema::api_type::vulkan::StdVideoVP9ColorConfig;

    StdVideoVP9ColorConfig* decoded_value{ nullptr };

    Decoded_StdVideoVP9ColorConfigFlags* flags{ nullptr };
};

struct Decoded_StdVideoVP9LoopFilterFlags
{
    using struct_type = StdVideoVP9LoopFilterFlags;
    using api_element = schema::api_type::vulkan::StdVideoVP9LoopFilterFlags;

    StdVideoVP9LoopFilterFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoVP9LoopFilter
{
    using struct_type = StdVideoVP9LoopFilter;
    using api_element = schema::api_type::vulkan::StdVideoVP9LoopFilter;

    StdVideoVP9LoopFilter* decoded_value{ nullptr };

    Decoded_StdVideoVP9LoopFilterFlags* flags{ nullptr };
    PointerDecoder<int8_t> loop_filter_ref_deltas;
    PointerDecoder<int8_t> loop_filter_mode_deltas;
};

struct Decoded_StdVideoVP9SegmentationFlags
{
    using struct_type = StdVideoVP9SegmentationFlags;
    using api_element = schema::api_type::vulkan::StdVideoVP9SegmentationFlags;

    StdVideoVP9SegmentationFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoVP9Segmentation
{
    using struct_type = StdVideoVP9Segmentation;
    using api_element = schema::api_type::vulkan::StdVideoVP9Segmentation;

    StdVideoVP9Segmentation* decoded_value{ nullptr };

    Decoded_StdVideoVP9SegmentationFlags* flags{ nullptr };
    PointerDecoder<uint8_t> segmentation_tree_probs;
    PointerDecoder<uint8_t> segmentation_pred_prob;
    PointerDecoder<uint8_t> FeatureEnabled;
    PointerDecoder<int16_t> FeatureData;
};

struct Decoded_StdVideoDecodeVP9PictureInfoFlags
{
    using struct_type = StdVideoDecodeVP9PictureInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoDecodeVP9PictureInfoFlags;

    StdVideoDecodeVP9PictureInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeVP9PictureInfo
{
    using struct_type = StdVideoDecodeVP9PictureInfo;
    using api_element = schema::api_type::vulkan::StdVideoDecodeVP9PictureInfo;

    StdVideoDecodeVP9PictureInfo* decoded_value{ nullptr };

    Decoded_StdVideoDecodeVP9PictureInfoFlags* flags{ nullptr };
    PointerDecoder<uint16_t> reserved1;
    StructPointerDecoder<Decoded_StdVideoVP9ColorConfig>* pColorConfig{ nullptr };
    StructPointerDecoder<Decoded_StdVideoVP9LoopFilter>* pLoopFilter{ nullptr };
    StructPointerDecoder<Decoded_StdVideoVP9Segmentation>* pSegmentation{ nullptr };
};

struct Decoded_StdVideoAV1ColorConfigFlags
{
    using struct_type = StdVideoAV1ColorConfigFlags;
    using api_element = schema::api_type::vulkan::StdVideoAV1ColorConfigFlags;

    StdVideoAV1ColorConfigFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1ColorConfig
{
    using struct_type = StdVideoAV1ColorConfig;
    using api_element = schema::api_type::vulkan::StdVideoAV1ColorConfig;

    StdVideoAV1ColorConfig* decoded_value{ nullptr };

    Decoded_StdVideoAV1ColorConfigFlags* flags{ nullptr };
};

struct Decoded_StdVideoAV1TimingInfoFlags
{
    using struct_type = StdVideoAV1TimingInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoAV1TimingInfoFlags;

    StdVideoAV1TimingInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1TimingInfo
{
    using struct_type = StdVideoAV1TimingInfo;
    using api_element = schema::api_type::vulkan::StdVideoAV1TimingInfo;

    StdVideoAV1TimingInfo* decoded_value{ nullptr };

    Decoded_StdVideoAV1TimingInfoFlags* flags{ nullptr };
};

struct Decoded_StdVideoAV1SequenceHeaderFlags
{
    using struct_type = StdVideoAV1SequenceHeaderFlags;
    using api_element = schema::api_type::vulkan::StdVideoAV1SequenceHeaderFlags;

    StdVideoAV1SequenceHeaderFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1SequenceHeader
{
    using struct_type = StdVideoAV1SequenceHeader;
    using api_element = schema::api_type::vulkan::StdVideoAV1SequenceHeader;

    StdVideoAV1SequenceHeader* decoded_value{ nullptr };

    Decoded_StdVideoAV1SequenceHeaderFlags* flags{ nullptr };
    PointerDecoder<uint8_t> reserved1;
    StructPointerDecoder<Decoded_StdVideoAV1ColorConfig>* pColorConfig{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1TimingInfo>* pTimingInfo{ nullptr };
};

struct Decoded_StdVideoAV1LoopFilterFlags
{
    using struct_type = StdVideoAV1LoopFilterFlags;
    using api_element = schema::api_type::vulkan::StdVideoAV1LoopFilterFlags;

    StdVideoAV1LoopFilterFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1LoopFilter
{
    using struct_type = StdVideoAV1LoopFilter;
    using api_element = schema::api_type::vulkan::StdVideoAV1LoopFilter;

    StdVideoAV1LoopFilter* decoded_value{ nullptr };

    Decoded_StdVideoAV1LoopFilterFlags* flags{ nullptr };
    PointerDecoder<uint8_t> loop_filter_level;
    PointerDecoder<int8_t> loop_filter_ref_deltas;
    PointerDecoder<int8_t> loop_filter_mode_deltas;
};

struct Decoded_StdVideoAV1QuantizationFlags
{
    using struct_type = StdVideoAV1QuantizationFlags;
    using api_element = schema::api_type::vulkan::StdVideoAV1QuantizationFlags;

    StdVideoAV1QuantizationFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1Quantization
{
    using struct_type = StdVideoAV1Quantization;
    using api_element = schema::api_type::vulkan::StdVideoAV1Quantization;

    StdVideoAV1Quantization* decoded_value{ nullptr };

    Decoded_StdVideoAV1QuantizationFlags* flags{ nullptr };
};

struct Decoded_StdVideoAV1Segmentation
{
    using struct_type = StdVideoAV1Segmentation;
    using api_element = schema::api_type::vulkan::StdVideoAV1Segmentation;

    StdVideoAV1Segmentation* decoded_value{ nullptr };

    PointerDecoder<uint8_t> FeatureEnabled;
    PointerDecoder<int16_t> FeatureData;
};

struct Decoded_StdVideoAV1TileInfoFlags
{
    using struct_type = StdVideoAV1TileInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoAV1TileInfoFlags;

    StdVideoAV1TileInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1TileInfo
{
    using struct_type = StdVideoAV1TileInfo;
    using api_element = schema::api_type::vulkan::StdVideoAV1TileInfo;

    StdVideoAV1TileInfo* decoded_value{ nullptr };

    Decoded_StdVideoAV1TileInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> reserved1;
    PointerDecoder<uint16_t> pMiColStarts;
    PointerDecoder<uint16_t> pMiRowStarts;
    PointerDecoder<uint16_t> pWidthInSbsMinus1;
    PointerDecoder<uint16_t> pHeightInSbsMinus1;
};

struct Decoded_StdVideoAV1CDEF
{
    using struct_type = StdVideoAV1CDEF;
    using api_element = schema::api_type::vulkan::StdVideoAV1CDEF;

    StdVideoAV1CDEF* decoded_value{ nullptr };

    PointerDecoder<uint8_t> cdef_y_pri_strength;
    PointerDecoder<uint8_t> cdef_y_sec_strength;
    PointerDecoder<uint8_t> cdef_uv_pri_strength;
    PointerDecoder<uint8_t> cdef_uv_sec_strength;
};

struct Decoded_StdVideoAV1LoopRestoration
{
    using struct_type = StdVideoAV1LoopRestoration;
    using api_element = schema::api_type::vulkan::StdVideoAV1LoopRestoration;

    StdVideoAV1LoopRestoration* decoded_value{ nullptr };

    PointerDecoder<StdVideoAV1FrameRestorationType> FrameRestorationType;
    PointerDecoder<uint16_t> LoopRestorationSize;
};

struct Decoded_StdVideoAV1GlobalMotion
{
    using struct_type = StdVideoAV1GlobalMotion;
    using api_element = schema::api_type::vulkan::StdVideoAV1GlobalMotion;

    StdVideoAV1GlobalMotion* decoded_value{ nullptr };

    PointerDecoder<uint8_t> GmType;
    PointerDecoder<int32_t> gm_params;
};

struct Decoded_StdVideoAV1FilmGrainFlags
{
    using struct_type = StdVideoAV1FilmGrainFlags;
    using api_element = schema::api_type::vulkan::StdVideoAV1FilmGrainFlags;

    StdVideoAV1FilmGrainFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1FilmGrain
{
    using struct_type = StdVideoAV1FilmGrain;
    using api_element = schema::api_type::vulkan::StdVideoAV1FilmGrain;

    StdVideoAV1FilmGrain* decoded_value{ nullptr };

    Decoded_StdVideoAV1FilmGrainFlags* flags{ nullptr };
    PointerDecoder<uint8_t> point_y_value;
    PointerDecoder<uint8_t> point_y_scaling;
    PointerDecoder<uint8_t> point_cb_value;
    PointerDecoder<uint8_t> point_cb_scaling;
    PointerDecoder<uint8_t> point_cr_value;
    PointerDecoder<uint8_t> point_cr_scaling;
    PointerDecoder<int8_t> ar_coeffs_y_plus_128;
    PointerDecoder<int8_t> ar_coeffs_cb_plus_128;
    PointerDecoder<int8_t> ar_coeffs_cr_plus_128;
};

struct Decoded_StdVideoDecodeAV1PictureInfoFlags
{
    using struct_type = StdVideoDecodeAV1PictureInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoDecodeAV1PictureInfoFlags;

    StdVideoDecodeAV1PictureInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeAV1PictureInfo
{
    using struct_type = StdVideoDecodeAV1PictureInfo;
    using api_element = schema::api_type::vulkan::StdVideoDecodeAV1PictureInfo;

    StdVideoDecodeAV1PictureInfo* decoded_value{ nullptr };

    Decoded_StdVideoDecodeAV1PictureInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> SkipModeFrame;
    PointerDecoder<uint8_t> reserved2;
    PointerDecoder<uint8_t> OrderHints;
    PointerDecoder<uint32_t> expectedFrameId;
    StructPointerDecoder<Decoded_StdVideoAV1TileInfo>* pTileInfo{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1Quantization>* pQuantization{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1Segmentation>* pSegmentation{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1LoopFilter>* pLoopFilter{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1CDEF>* pCDEF{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1LoopRestoration>* pLoopRestoration{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1GlobalMotion>* pGlobalMotion{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1FilmGrain>* pFilmGrain{ nullptr };
};

struct Decoded_StdVideoDecodeAV1ReferenceInfoFlags
{
    using struct_type = StdVideoDecodeAV1ReferenceInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoDecodeAV1ReferenceInfoFlags;

    StdVideoDecodeAV1ReferenceInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeAV1ReferenceInfo
{
    using struct_type = StdVideoDecodeAV1ReferenceInfo;
    using api_element = schema::api_type::vulkan::StdVideoDecodeAV1ReferenceInfo;

    StdVideoDecodeAV1ReferenceInfo* decoded_value{ nullptr };

    Decoded_StdVideoDecodeAV1ReferenceInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> SavedOrderHints;
};

struct Decoded_StdVideoEncodeAV1ExtensionHeader
{
    using struct_type = StdVideoEncodeAV1ExtensionHeader;
    using api_element = schema::api_type::vulkan::StdVideoEncodeAV1ExtensionHeader;

    StdVideoEncodeAV1ExtensionHeader* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeAV1DecoderModelInfo
{
    using struct_type = StdVideoEncodeAV1DecoderModelInfo;
    using api_element = schema::api_type::vulkan::StdVideoEncodeAV1DecoderModelInfo;

    StdVideoEncodeAV1DecoderModelInfo* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeAV1OperatingPointInfoFlags
{
    using struct_type = StdVideoEncodeAV1OperatingPointInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoEncodeAV1OperatingPointInfoFlags;

    StdVideoEncodeAV1OperatingPointInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeAV1OperatingPointInfo
{
    using struct_type = StdVideoEncodeAV1OperatingPointInfo;
    using api_element = schema::api_type::vulkan::StdVideoEncodeAV1OperatingPointInfo;

    StdVideoEncodeAV1OperatingPointInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeAV1OperatingPointInfoFlags* flags{ nullptr };
};

struct Decoded_StdVideoEncodeAV1PictureInfoFlags
{
    using struct_type = StdVideoEncodeAV1PictureInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoEncodeAV1PictureInfoFlags;

    StdVideoEncodeAV1PictureInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeAV1PictureInfo
{
    using struct_type = StdVideoEncodeAV1PictureInfo;
    using api_element = schema::api_type::vulkan::StdVideoEncodeAV1PictureInfo;

    StdVideoEncodeAV1PictureInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeAV1PictureInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> ref_order_hint;
    PointerDecoder<int8_t> ref_frame_idx;
    PointerDecoder<uint8_t> reserved1;
    PointerDecoder<uint32_t> delta_frame_id_minus_1;
    StructPointerDecoder<Decoded_StdVideoAV1TileInfo>* pTileInfo{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1Quantization>* pQuantization{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1Segmentation>* pSegmentation{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1LoopFilter>* pLoopFilter{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1CDEF>* pCDEF{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1LoopRestoration>* pLoopRestoration{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1GlobalMotion>* pGlobalMotion{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeAV1ExtensionHeader>* pExtensionHeader{ nullptr };
    PointerDecoder<uint32_t> pBufferRemovalTimes;
};

struct Decoded_StdVideoEncodeAV1ReferenceInfoFlags
{
    using struct_type = StdVideoEncodeAV1ReferenceInfoFlags;
    using api_element = schema::api_type::vulkan::StdVideoEncodeAV1ReferenceInfoFlags;

    StdVideoEncodeAV1ReferenceInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeAV1ReferenceInfo
{
    using struct_type = StdVideoEncodeAV1ReferenceInfo;
    using api_element = schema::api_type::vulkan::StdVideoEncodeAV1ReferenceInfo;

    StdVideoEncodeAV1ReferenceInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeAV1ReferenceInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> reserved1;
    StructPointerDecoder<Decoded_StdVideoEncodeAV1ExtensionHeader>* pExtensionHeader{ nullptr };
};

struct Decoded_VkExtent2D
{
    using struct_type = VkExtent2D;
    using api_element = schema::api_type::vulkan::VkExtent2D;

    VkExtent2D* decoded_value{ nullptr };
};

struct Decoded_VkExtent3D
{
    using struct_type = VkExtent3D;
    using api_element = schema::api_type::vulkan::VkExtent3D;

    VkExtent3D* decoded_value{ nullptr };
};

struct Decoded_VkOffset2D
{
    using struct_type = VkOffset2D;
    using api_element = schema::api_type::vulkan::VkOffset2D;

    VkOffset2D* decoded_value{ nullptr };
};

struct Decoded_VkOffset3D
{
    using struct_type = VkOffset3D;
    using api_element = schema::api_type::vulkan::VkOffset3D;

    VkOffset3D* decoded_value{ nullptr };
};

struct Decoded_VkRect2D
{
    using struct_type = VkRect2D;
    using api_element = schema::api_type::vulkan::VkRect2D;

    VkRect2D* decoded_value{ nullptr };

    Decoded_VkOffset2D* offset{ nullptr };
    Decoded_VkExtent2D* extent{ nullptr };
};

struct Decoded_VkAllocationCallbacks
{
    using struct_type = VkAllocationCallbacks;
    using api_element = schema::api_type::vulkan::VkAllocationCallbacks;

    VkAllocationCallbacks* decoded_value{ nullptr };

    uint64_t pUserData{ 0 };
    uint64_t pfnAllocation{ 0 };
    uint64_t pfnReallocation{ 0 };
    uint64_t pfnFree{ 0 };
    uint64_t pfnInternalAllocation{ 0 };
    uint64_t pfnInternalFree{ 0 };
};

struct Decoded_VkApplicationInfo
{
    using struct_type = VkApplicationInfo;
    using api_element = schema::api_type::vulkan::VkApplicationInfo;

    VkApplicationInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder pApplicationName;
    StringDecoder pEngineName;
};

struct Decoded_VkFormatProperties
{
    using struct_type = VkFormatProperties;
    using api_element = schema::api_type::vulkan::VkFormatProperties;

    VkFormatProperties* decoded_value{ nullptr };
};

struct Decoded_VkImageFormatProperties
{
    using struct_type = VkImageFormatProperties;
    using api_element = schema::api_type::vulkan::VkImageFormatProperties;

    VkImageFormatProperties* decoded_value{ nullptr };

    Decoded_VkExtent3D* maxExtent{ nullptr };
};

struct Decoded_VkInstanceCreateInfo
{
    using struct_type = VkInstanceCreateInfo;
    using api_element = schema::api_type::vulkan::VkInstanceCreateInfo;

    VkInstanceCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkApplicationInfo>* pApplicationInfo{ nullptr };
    StringArrayDecoder ppEnabledLayerNames;
    StringArrayDecoder ppEnabledExtensionNames;
};

struct Decoded_VkMemoryHeap
{
    using struct_type = VkMemoryHeap;
    using api_element = schema::api_type::vulkan::VkMemoryHeap;

    VkMemoryHeap* decoded_value{ nullptr };
};

struct Decoded_VkMemoryType
{
    using struct_type = VkMemoryType;
    using api_element = schema::api_type::vulkan::VkMemoryType;

    VkMemoryType* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceFeatures
{
    using struct_type = VkPhysicalDeviceFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFeatures;

    VkPhysicalDeviceFeatures* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceLimits
{
    using struct_type = VkPhysicalDeviceLimits;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLimits;

    VkPhysicalDeviceLimits* decoded_value{ nullptr };

    PointerDecoder<uint32_t> maxComputeWorkGroupCount;
    PointerDecoder<uint32_t> maxComputeWorkGroupSize;
    PointerDecoder<uint32_t> maxViewportDimensions;
    PointerDecoder<float> viewportBoundsRange;
    PointerDecoder<float> pointSizeRange;
    PointerDecoder<float> lineWidthRange;
};

struct Decoded_VkPhysicalDeviceMemoryProperties
{
    using struct_type = VkPhysicalDeviceMemoryProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMemoryProperties;

    VkPhysicalDeviceMemoryProperties* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkMemoryType>* memoryTypes{ nullptr };
    StructPointerDecoder<Decoded_VkMemoryHeap>* memoryHeaps{ nullptr };
};

struct Decoded_VkPhysicalDeviceSparseProperties
{
    using struct_type = VkPhysicalDeviceSparseProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSparseProperties;

    VkPhysicalDeviceSparseProperties* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceProperties
{
    using struct_type = VkPhysicalDeviceProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceProperties;

    VkPhysicalDeviceProperties* decoded_value{ nullptr };

    StringDecoder deviceName;
    PointerDecoder<uint8_t> pipelineCacheUUID;
    Decoded_VkPhysicalDeviceLimits* limits{ nullptr };
    Decoded_VkPhysicalDeviceSparseProperties* sparseProperties{ nullptr };
};

struct Decoded_VkQueueFamilyProperties
{
    using struct_type = VkQueueFamilyProperties;
    using api_element = schema::api_type::vulkan::VkQueueFamilyProperties;

    VkQueueFamilyProperties* decoded_value{ nullptr };

    Decoded_VkExtent3D* minImageTransferGranularity{ nullptr };
};

struct Decoded_VkDeviceQueueCreateInfo
{
    using struct_type = VkDeviceQueueCreateInfo;
    using api_element = schema::api_type::vulkan::VkDeviceQueueCreateInfo;

    VkDeviceQueueCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<float> pQueuePriorities;
};

struct Decoded_VkDeviceCreateInfo
{
    using struct_type = VkDeviceCreateInfo;
    using api_element = schema::api_type::vulkan::VkDeviceCreateInfo;

    VkDeviceCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDeviceQueueCreateInfo>* pQueueCreateInfos{ nullptr };
    StringArrayDecoder ppEnabledLayerNames;
    StringArrayDecoder ppEnabledExtensionNames;
    StructPointerDecoder<Decoded_VkPhysicalDeviceFeatures>* pEnabledFeatures{ nullptr };
};

struct Decoded_VkExtensionProperties
{
    using struct_type = VkExtensionProperties;
    using api_element = schema::api_type::vulkan::VkExtensionProperties;

    VkExtensionProperties* decoded_value{ nullptr };

    StringDecoder extensionName;
};

struct Decoded_VkLayerProperties
{
    using struct_type = VkLayerProperties;
    using api_element = schema::api_type::vulkan::VkLayerProperties;

    VkLayerProperties* decoded_value{ nullptr };

    StringDecoder layerName;
    StringDecoder description;
};

struct Decoded_VkSubmitInfo
{
    using struct_type = VkSubmitInfo;
    using api_element = schema::api_type::vulkan::VkSubmitInfo;

    VkSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkSemaphore> pWaitSemaphores;
    PointerDecoder<VkPipelineStageFlags> pWaitDstStageMask;
    HandlePointerDecoder<VkCommandBuffer> pCommandBuffers;
    HandlePointerDecoder<VkSemaphore> pSignalSemaphores;
};

struct Decoded_VkMappedMemoryRange
{
    using struct_type = VkMappedMemoryRange;
    using api_element = schema::api_type::vulkan::VkMappedMemoryRange;

    VkMappedMemoryRange* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkMemoryAllocateInfo
{
    using struct_type = VkMemoryAllocateInfo;
    using api_element = schema::api_type::vulkan::VkMemoryAllocateInfo;

    VkMemoryAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryRequirements
{
    using struct_type = VkMemoryRequirements;
    using api_element = schema::api_type::vulkan::VkMemoryRequirements;

    VkMemoryRequirements* decoded_value{ nullptr };
};

struct Decoded_VkImageSubresource
{
    using struct_type = VkImageSubresource;
    using api_element = schema::api_type::vulkan::VkImageSubresource;

    VkImageSubresource* decoded_value{ nullptr };
};

struct Decoded_VkSparseImageFormatProperties
{
    using struct_type = VkSparseImageFormatProperties;
    using api_element = schema::api_type::vulkan::VkSparseImageFormatProperties;

    VkSparseImageFormatProperties* decoded_value{ nullptr };

    Decoded_VkExtent3D* imageGranularity{ nullptr };
};

struct Decoded_VkSparseImageMemoryBind
{
    using struct_type = VkSparseImageMemoryBind;
    using api_element = schema::api_type::vulkan::VkSparseImageMemoryBind;

    VkSparseImageMemoryBind* decoded_value{ nullptr };

    Decoded_VkImageSubresource* subresource{ nullptr };
    Decoded_VkOffset3D* offset{ nullptr };
    Decoded_VkExtent3D* extent{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkSparseImageMemoryBindInfo
{
    using struct_type = VkSparseImageMemoryBindInfo;
    using api_element = schema::api_type::vulkan::VkSparseImageMemoryBindInfo;

    VkSparseImageMemoryBindInfo* decoded_value{ nullptr };

    format::HandleId image{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkSparseImageMemoryBind>* pBinds{ nullptr };
};

struct Decoded_VkSparseImageMemoryRequirements
{
    using struct_type = VkSparseImageMemoryRequirements;
    using api_element = schema::api_type::vulkan::VkSparseImageMemoryRequirements;

    VkSparseImageMemoryRequirements* decoded_value{ nullptr };

    Decoded_VkSparseImageFormatProperties* formatProperties{ nullptr };
};

struct Decoded_VkSparseMemoryBind
{
    using struct_type = VkSparseMemoryBind;
    using api_element = schema::api_type::vulkan::VkSparseMemoryBind;

    VkSparseMemoryBind* decoded_value{ nullptr };

    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkSparseBufferMemoryBindInfo
{
    using struct_type = VkSparseBufferMemoryBindInfo;
    using api_element = schema::api_type::vulkan::VkSparseBufferMemoryBindInfo;

    VkSparseBufferMemoryBindInfo* decoded_value{ nullptr };

    format::HandleId buffer{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkSparseMemoryBind>* pBinds{ nullptr };
};

struct Decoded_VkSparseImageOpaqueMemoryBindInfo
{
    using struct_type = VkSparseImageOpaqueMemoryBindInfo;
    using api_element = schema::api_type::vulkan::VkSparseImageOpaqueMemoryBindInfo;

    VkSparseImageOpaqueMemoryBindInfo* decoded_value{ nullptr };

    format::HandleId image{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkSparseMemoryBind>* pBinds{ nullptr };
};

struct Decoded_VkBindSparseInfo
{
    using struct_type = VkBindSparseInfo;
    using api_element = schema::api_type::vulkan::VkBindSparseInfo;

    VkBindSparseInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkSemaphore> pWaitSemaphores;
    StructPointerDecoder<Decoded_VkSparseBufferMemoryBindInfo>* pBufferBinds{ nullptr };
    StructPointerDecoder<Decoded_VkSparseImageOpaqueMemoryBindInfo>* pImageOpaqueBinds{ nullptr };
    StructPointerDecoder<Decoded_VkSparseImageMemoryBindInfo>* pImageBinds{ nullptr };
    HandlePointerDecoder<VkSemaphore> pSignalSemaphores;
};

struct Decoded_VkFenceCreateInfo
{
    using struct_type = VkFenceCreateInfo;
    using api_element = schema::api_type::vulkan::VkFenceCreateInfo;

    VkFenceCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSemaphoreCreateInfo
{
    using struct_type = VkSemaphoreCreateInfo;
    using api_element = schema::api_type::vulkan::VkSemaphoreCreateInfo;

    VkSemaphoreCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueryPoolCreateInfo
{
    using struct_type = VkQueryPoolCreateInfo;
    using api_element = schema::api_type::vulkan::VkQueryPoolCreateInfo;

    VkQueryPoolCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferCreateInfo
{
    using struct_type = VkBufferCreateInfo;
    using api_element = schema::api_type::vulkan::VkBufferCreateInfo;

    VkBufferCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkImageCreateInfo
{
    using struct_type = VkImageCreateInfo;
    using api_element = schema::api_type::vulkan::VkImageCreateInfo;

    VkImageCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent3D* extent{ nullptr };
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkSubresourceLayout
{
    using struct_type = VkSubresourceLayout;
    using api_element = schema::api_type::vulkan::VkSubresourceLayout;

    VkSubresourceLayout* decoded_value{ nullptr };
};

struct Decoded_VkComponentMapping
{
    using struct_type = VkComponentMapping;
    using api_element = schema::api_type::vulkan::VkComponentMapping;

    VkComponentMapping* decoded_value{ nullptr };
};

struct Decoded_VkImageSubresourceRange
{
    using struct_type = VkImageSubresourceRange;
    using api_element = schema::api_type::vulkan::VkImageSubresourceRange;

    VkImageSubresourceRange* decoded_value{ nullptr };
};

struct Decoded_VkImageViewCreateInfo
{
    using struct_type = VkImageViewCreateInfo;
    using api_element = schema::api_type::vulkan::VkImageViewCreateInfo;

    VkImageViewCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    Decoded_VkComponentMapping* components{ nullptr };
    Decoded_VkImageSubresourceRange* subresourceRange{ nullptr };
};

struct Decoded_VkCommandPoolCreateInfo
{
    using struct_type = VkCommandPoolCreateInfo;
    using api_element = schema::api_type::vulkan::VkCommandPoolCreateInfo;

    VkCommandPoolCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCommandBufferAllocateInfo
{
    using struct_type = VkCommandBufferAllocateInfo;
    using api_element = schema::api_type::vulkan::VkCommandBufferAllocateInfo;

    VkCommandBufferAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId commandPool{ format::kNullHandleId };
};

struct Decoded_VkCommandBufferInheritanceInfo
{
    using struct_type = VkCommandBufferInheritanceInfo;
    using api_element = schema::api_type::vulkan::VkCommandBufferInheritanceInfo;

    VkCommandBufferInheritanceInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId renderPass{ format::kNullHandleId };
    format::HandleId framebuffer{ format::kNullHandleId };
};

struct Decoded_VkCommandBufferBeginInfo
{
    using struct_type = VkCommandBufferBeginInfo;
    using api_element = schema::api_type::vulkan::VkCommandBufferBeginInfo;

    VkCommandBufferBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkCommandBufferInheritanceInfo>* pInheritanceInfo{ nullptr };
};

struct Decoded_VkBufferCopy
{
    using struct_type = VkBufferCopy;
    using api_element = schema::api_type::vulkan::VkBufferCopy;

    VkBufferCopy* decoded_value{ nullptr };
};

struct Decoded_VkImageSubresourceLayers
{
    using struct_type = VkImageSubresourceLayers;
    using api_element = schema::api_type::vulkan::VkImageSubresourceLayers;

    VkImageSubresourceLayers* decoded_value{ nullptr };
};

struct Decoded_VkBufferImageCopy
{
    using struct_type = VkBufferImageCopy;
    using api_element = schema::api_type::vulkan::VkBufferImageCopy;

    VkBufferImageCopy* decoded_value{ nullptr };

    Decoded_VkImageSubresourceLayers* imageSubresource{ nullptr };
    Decoded_VkOffset3D* imageOffset{ nullptr };
    Decoded_VkExtent3D* imageExtent{ nullptr };
};

struct Decoded_VkImageCopy
{
    using struct_type = VkImageCopy;
    using api_element = schema::api_type::vulkan::VkImageCopy;

    VkImageCopy* decoded_value{ nullptr };

    Decoded_VkImageSubresourceLayers* srcSubresource{ nullptr };
    Decoded_VkOffset3D* srcOffset{ nullptr };
    Decoded_VkImageSubresourceLayers* dstSubresource{ nullptr };
    Decoded_VkOffset3D* dstOffset{ nullptr };
    Decoded_VkExtent3D* extent{ nullptr };
};

struct Decoded_VkBufferMemoryBarrier
{
    using struct_type = VkBufferMemoryBarrier;
    using api_element = schema::api_type::vulkan::VkBufferMemoryBarrier;

    VkBufferMemoryBarrier* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkImageMemoryBarrier
{
    using struct_type = VkImageMemoryBarrier;
    using api_element = schema::api_type::vulkan::VkImageMemoryBarrier;

    VkImageMemoryBarrier* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    Decoded_VkImageSubresourceRange* subresourceRange{ nullptr };
};

struct Decoded_VkMemoryBarrier
{
    using struct_type = VkMemoryBarrier;
    using api_element = schema::api_type::vulkan::VkMemoryBarrier;

    VkMemoryBarrier* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDispatchIndirectCommand
{
    using struct_type = VkDispatchIndirectCommand;
    using api_element = schema::api_type::vulkan::VkDispatchIndirectCommand;

    VkDispatchIndirectCommand* decoded_value{ nullptr };
};

struct Decoded_VkPipelineCacheHeaderVersionOne
{
    using struct_type = VkPipelineCacheHeaderVersionOne;
    using api_element = schema::api_type::vulkan::VkPipelineCacheHeaderVersionOne;

    VkPipelineCacheHeaderVersionOne* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pipelineCacheUUID;
};

struct Decoded_VkEventCreateInfo
{
    using struct_type = VkEventCreateInfo;
    using api_element = schema::api_type::vulkan::VkEventCreateInfo;

    VkEventCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferViewCreateInfo
{
    using struct_type = VkBufferViewCreateInfo;
    using api_element = schema::api_type::vulkan::VkBufferViewCreateInfo;

    VkBufferViewCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkShaderModuleCreateInfo
{
    using struct_type = VkShaderModuleCreateInfo;
    using api_element = schema::api_type::vulkan::VkShaderModuleCreateInfo;

    VkShaderModuleCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pCode;
};

struct Decoded_VkPipelineCacheCreateInfo
{
    using struct_type = VkPipelineCacheCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineCacheCreateInfo;

    VkPipelineCacheCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pInitialData;
};

struct Decoded_VkSpecializationMapEntry
{
    using struct_type = VkSpecializationMapEntry;
    using api_element = schema::api_type::vulkan::VkSpecializationMapEntry;

    VkSpecializationMapEntry* decoded_value{ nullptr };
};

struct Decoded_VkSpecializationInfo
{
    using struct_type = VkSpecializationInfo;
    using api_element = schema::api_type::vulkan::VkSpecializationInfo;

    VkSpecializationInfo* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkSpecializationMapEntry>* pMapEntries{ nullptr };
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkPipelineShaderStageCreateInfo
{
    using struct_type = VkPipelineShaderStageCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineShaderStageCreateInfo;

    VkPipelineShaderStageCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId module{ format::kNullHandleId };
    StringDecoder pName;
    StructPointerDecoder<Decoded_VkSpecializationInfo>* pSpecializationInfo{ nullptr };
};

struct Decoded_VkComputePipelineCreateInfo
{
    using struct_type = VkComputePipelineCreateInfo;
    using api_element = schema::api_type::vulkan::VkComputePipelineCreateInfo;

    VkComputePipelineCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPipelineShaderStageCreateInfo* stage{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    format::HandleId basePipelineHandle{ format::kNullHandleId };
};

struct Decoded_VkPushConstantRange
{
    using struct_type = VkPushConstantRange;
    using api_element = schema::api_type::vulkan::VkPushConstantRange;

    VkPushConstantRange* decoded_value{ nullptr };
};

struct Decoded_VkPipelineLayoutCreateInfo
{
    using struct_type = VkPipelineLayoutCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineLayoutCreateInfo;

    VkPipelineLayoutCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
    StructPointerDecoder<Decoded_VkPushConstantRange>* pPushConstantRanges{ nullptr };
};

struct Decoded_VkSamplerCreateInfo
{
    using struct_type = VkSamplerCreateInfo;
    using api_element = schema::api_type::vulkan::VkSamplerCreateInfo;

    VkSamplerCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCopyDescriptorSet
{
    using struct_type = VkCopyDescriptorSet;
    using api_element = schema::api_type::vulkan::VkCopyDescriptorSet;

    VkCopyDescriptorSet* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcSet{ format::kNullHandleId };
    format::HandleId dstSet{ format::kNullHandleId };
};

struct Decoded_VkDescriptorBufferInfo
{
    using struct_type = VkDescriptorBufferInfo;
    using api_element = schema::api_type::vulkan::VkDescriptorBufferInfo;

    VkDescriptorBufferInfo* decoded_value{ nullptr };

    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkDescriptorPoolSize
{
    using struct_type = VkDescriptorPoolSize;
    using api_element = schema::api_type::vulkan::VkDescriptorPoolSize;

    VkDescriptorPoolSize* decoded_value{ nullptr };
};

struct Decoded_VkDescriptorPoolCreateInfo
{
    using struct_type = VkDescriptorPoolCreateInfo;
    using api_element = schema::api_type::vulkan::VkDescriptorPoolCreateInfo;

    VkDescriptorPoolCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDescriptorPoolSize>* pPoolSizes{ nullptr };
};

struct Decoded_VkDescriptorSetAllocateInfo
{
    using struct_type = VkDescriptorSetAllocateInfo;
    using api_element = schema::api_type::vulkan::VkDescriptorSetAllocateInfo;

    VkDescriptorSetAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId descriptorPool{ format::kNullHandleId };
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
};

struct Decoded_VkDescriptorSetLayoutBinding
{
    using struct_type = VkDescriptorSetLayoutBinding;
    using api_element = schema::api_type::vulkan::VkDescriptorSetLayoutBinding;

    VkDescriptorSetLayoutBinding* decoded_value{ nullptr };

    HandlePointerDecoder<VkSampler> pImmutableSamplers;
};

struct Decoded_VkDescriptorSetLayoutCreateInfo
{
    using struct_type = VkDescriptorSetLayoutCreateInfo;
    using api_element = schema::api_type::vulkan::VkDescriptorSetLayoutCreateInfo;

    VkDescriptorSetLayoutCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutBinding>* pBindings{ nullptr };
};

struct Decoded_VkDrawIndexedIndirectCommand
{
    using struct_type = VkDrawIndexedIndirectCommand;
    using api_element = schema::api_type::vulkan::VkDrawIndexedIndirectCommand;

    VkDrawIndexedIndirectCommand* decoded_value{ nullptr };
};

struct Decoded_VkDrawIndirectCommand
{
    using struct_type = VkDrawIndirectCommand;
    using api_element = schema::api_type::vulkan::VkDrawIndirectCommand;

    VkDrawIndirectCommand* decoded_value{ nullptr };
};

struct Decoded_VkStencilOpState
{
    using struct_type = VkStencilOpState;
    using api_element = schema::api_type::vulkan::VkStencilOpState;

    VkStencilOpState* decoded_value{ nullptr };
};

struct Decoded_VkVertexInputAttributeDescription
{
    using struct_type = VkVertexInputAttributeDescription;
    using api_element = schema::api_type::vulkan::VkVertexInputAttributeDescription;

    VkVertexInputAttributeDescription* decoded_value{ nullptr };
};

struct Decoded_VkVertexInputBindingDescription
{
    using struct_type = VkVertexInputBindingDescription;
    using api_element = schema::api_type::vulkan::VkVertexInputBindingDescription;

    VkVertexInputBindingDescription* decoded_value{ nullptr };
};

struct Decoded_VkViewport
{
    using struct_type = VkViewport;
    using api_element = schema::api_type::vulkan::VkViewport;

    VkViewport* decoded_value{ nullptr };
};

struct Decoded_VkPipelineColorBlendAttachmentState
{
    using struct_type = VkPipelineColorBlendAttachmentState;
    using api_element = schema::api_type::vulkan::VkPipelineColorBlendAttachmentState;

    VkPipelineColorBlendAttachmentState* decoded_value{ nullptr };
};

struct Decoded_VkPipelineColorBlendStateCreateInfo
{
    using struct_type = VkPipelineColorBlendStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineColorBlendStateCreateInfo;

    VkPipelineColorBlendStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineColorBlendAttachmentState>* pAttachments{ nullptr };
    PointerDecoder<float> blendConstants;
};

struct Decoded_VkPipelineDepthStencilStateCreateInfo
{
    using struct_type = VkPipelineDepthStencilStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineDepthStencilStateCreateInfo;

    VkPipelineDepthStencilStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkStencilOpState* front{ nullptr };
    Decoded_VkStencilOpState* back{ nullptr };
};

struct Decoded_VkPipelineDynamicStateCreateInfo
{
    using struct_type = VkPipelineDynamicStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineDynamicStateCreateInfo;

    VkPipelineDynamicStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkDynamicState> pDynamicStates;
};

struct Decoded_VkPipelineInputAssemblyStateCreateInfo
{
    using struct_type = VkPipelineInputAssemblyStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineInputAssemblyStateCreateInfo;

    VkPipelineInputAssemblyStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineMultisampleStateCreateInfo
{
    using struct_type = VkPipelineMultisampleStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineMultisampleStateCreateInfo;

    VkPipelineMultisampleStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkSampleMask> pSampleMask;
};

struct Decoded_VkPipelineRasterizationStateCreateInfo
{
    using struct_type = VkPipelineRasterizationStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineRasterizationStateCreateInfo;

    VkPipelineRasterizationStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineTessellationStateCreateInfo
{
    using struct_type = VkPipelineTessellationStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineTessellationStateCreateInfo;

    VkPipelineTessellationStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineVertexInputStateCreateInfo
{
    using struct_type = VkPipelineVertexInputStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineVertexInputStateCreateInfo;

    VkPipelineVertexInputStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription>* pVertexBindingDescriptions{ nullptr };
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription>* pVertexAttributeDescriptions{ nullptr };
};

struct Decoded_VkPipelineViewportStateCreateInfo
{
    using struct_type = VkPipelineViewportStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineViewportStateCreateInfo;

    VkPipelineViewportStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkViewport>* pViewports{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pScissors{ nullptr };
};

struct Decoded_VkGraphicsPipelineCreateInfo
{
    using struct_type = VkGraphicsPipelineCreateInfo;
    using api_element = schema::api_type::vulkan::VkGraphicsPipelineCreateInfo;

    VkGraphicsPipelineCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>* pStages{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineVertexInputStateCreateInfo>* pVertexInputState{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineInputAssemblyStateCreateInfo>* pInputAssemblyState{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineTessellationStateCreateInfo>* pTessellationState{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineViewportStateCreateInfo>* pViewportState{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineRasterizationStateCreateInfo>* pRasterizationState{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineMultisampleStateCreateInfo>* pMultisampleState{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineDepthStencilStateCreateInfo>* pDepthStencilState{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineColorBlendStateCreateInfo>* pColorBlendState{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineDynamicStateCreateInfo>* pDynamicState{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    format::HandleId renderPass{ format::kNullHandleId };
    format::HandleId basePipelineHandle{ format::kNullHandleId };
};

struct Decoded_VkAttachmentDescription
{
    using struct_type = VkAttachmentDescription;
    using api_element = schema::api_type::vulkan::VkAttachmentDescription;

    VkAttachmentDescription* decoded_value{ nullptr };
};

struct Decoded_VkAttachmentReference
{
    using struct_type = VkAttachmentReference;
    using api_element = schema::api_type::vulkan::VkAttachmentReference;

    VkAttachmentReference* decoded_value{ nullptr };
};

struct Decoded_VkFramebufferCreateInfo
{
    using struct_type = VkFramebufferCreateInfo;
    using api_element = schema::api_type::vulkan::VkFramebufferCreateInfo;

    VkFramebufferCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId renderPass{ format::kNullHandleId };
    HandlePointerDecoder<VkImageView> pAttachments;
};

struct Decoded_VkSubpassDependency
{
    using struct_type = VkSubpassDependency;
    using api_element = schema::api_type::vulkan::VkSubpassDependency;

    VkSubpassDependency* decoded_value{ nullptr };
};

struct Decoded_VkSubpassDescription
{
    using struct_type = VkSubpassDescription;
    using api_element = schema::api_type::vulkan::VkSubpassDescription;

    VkSubpassDescription* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkAttachmentReference>* pInputAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference>* pColorAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference>* pResolveAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference>* pDepthStencilAttachment{ nullptr };
    PointerDecoder<uint32_t> pPreserveAttachments;
};

struct Decoded_VkRenderPassCreateInfo
{
    using struct_type = VkRenderPassCreateInfo;
    using api_element = schema::api_type::vulkan::VkRenderPassCreateInfo;

    VkRenderPassCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentDescription>* pAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkSubpassDescription>* pSubpasses{ nullptr };
    StructPointerDecoder<Decoded_VkSubpassDependency>* pDependencies{ nullptr };
};

struct Decoded_VkClearDepthStencilValue
{
    using struct_type = VkClearDepthStencilValue;
    using api_element = schema::api_type::vulkan::VkClearDepthStencilValue;

    VkClearDepthStencilValue* decoded_value{ nullptr };
};

struct Decoded_VkClearRect
{
    using struct_type = VkClearRect;
    using api_element = schema::api_type::vulkan::VkClearRect;

    VkClearRect* decoded_value{ nullptr };

    Decoded_VkRect2D* rect{ nullptr };
};

struct Decoded_VkClearAttachment
{
    using struct_type = VkClearAttachment;
    using api_element = schema::api_type::vulkan::VkClearAttachment;

    VkClearAttachment* decoded_value{ nullptr };

    Decoded_VkClearValue* clearValue{ nullptr };
};

struct Decoded_VkImageBlit
{
    using struct_type = VkImageBlit;
    using api_element = schema::api_type::vulkan::VkImageBlit;

    VkImageBlit* decoded_value{ nullptr };

    Decoded_VkImageSubresourceLayers* srcSubresource{ nullptr };
    StructPointerDecoder<Decoded_VkOffset3D>* srcOffsets{ nullptr };
    Decoded_VkImageSubresourceLayers* dstSubresource{ nullptr };
    StructPointerDecoder<Decoded_VkOffset3D>* dstOffsets{ nullptr };
};

struct Decoded_VkImageResolve
{
    using struct_type = VkImageResolve;
    using api_element = schema::api_type::vulkan::VkImageResolve;

    VkImageResolve* decoded_value{ nullptr };

    Decoded_VkImageSubresourceLayers* srcSubresource{ nullptr };
    Decoded_VkOffset3D* srcOffset{ nullptr };
    Decoded_VkImageSubresourceLayers* dstSubresource{ nullptr };
    Decoded_VkOffset3D* dstOffset{ nullptr };
    Decoded_VkExtent3D* extent{ nullptr };
};

struct Decoded_VkRenderPassBeginInfo
{
    using struct_type = VkRenderPassBeginInfo;
    using api_element = schema::api_type::vulkan::VkRenderPassBeginInfo;

    VkRenderPassBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId renderPass{ format::kNullHandleId };
    format::HandleId framebuffer{ format::kNullHandleId };
    Decoded_VkRect2D* renderArea{ nullptr };
    StructPointerDecoder<Decoded_VkClearValue>* pClearValues{ nullptr };
};

struct Decoded_VkBindBufferMemoryInfo
{
    using struct_type = VkBindBufferMemoryInfo;
    using api_element = schema::api_type::vulkan::VkBindBufferMemoryInfo;

    VkBindBufferMemoryInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkBindImageMemoryInfo
{
    using struct_type = VkBindImageMemoryInfo;
    using api_element = schema::api_type::vulkan::VkBindImageMemoryInfo;

    VkBindImageMemoryInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkMemoryDedicatedRequirements
{
    using struct_type = VkMemoryDedicatedRequirements;
    using api_element = schema::api_type::vulkan::VkMemoryDedicatedRequirements;

    VkMemoryDedicatedRequirements* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryDedicatedAllocateInfo
{
    using struct_type = VkMemoryDedicatedAllocateInfo;
    using api_element = schema::api_type::vulkan::VkMemoryDedicatedAllocateInfo;

    VkMemoryDedicatedAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkMemoryAllocateFlagsInfo
{
    using struct_type = VkMemoryAllocateFlagsInfo;
    using api_element = schema::api_type::vulkan::VkMemoryAllocateFlagsInfo;

    VkMemoryAllocateFlagsInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceGroupCommandBufferBeginInfo
{
    using struct_type = VkDeviceGroupCommandBufferBeginInfo;
    using api_element = schema::api_type::vulkan::VkDeviceGroupCommandBufferBeginInfo;

    VkDeviceGroupCommandBufferBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceGroupSubmitInfo
{
    using struct_type = VkDeviceGroupSubmitInfo;
    using api_element = schema::api_type::vulkan::VkDeviceGroupSubmitInfo;

    VkDeviceGroupSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pWaitSemaphoreDeviceIndices;
    PointerDecoder<uint32_t> pCommandBufferDeviceMasks;
    PointerDecoder<uint32_t> pSignalSemaphoreDeviceIndices;
};

struct Decoded_VkDeviceGroupBindSparseInfo
{
    using struct_type = VkDeviceGroupBindSparseInfo;
    using api_element = schema::api_type::vulkan::VkDeviceGroupBindSparseInfo;

    VkDeviceGroupBindSparseInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBindBufferMemoryDeviceGroupInfo
{
    using struct_type = VkBindBufferMemoryDeviceGroupInfo;
    using api_element = schema::api_type::vulkan::VkBindBufferMemoryDeviceGroupInfo;

    VkBindBufferMemoryDeviceGroupInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pDeviceIndices;
};

struct Decoded_VkBindImageMemoryDeviceGroupInfo
{
    using struct_type = VkBindImageMemoryDeviceGroupInfo;
    using api_element = schema::api_type::vulkan::VkBindImageMemoryDeviceGroupInfo;

    VkBindImageMemoryDeviceGroupInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pDeviceIndices;
    StructPointerDecoder<Decoded_VkRect2D>* pSplitInstanceBindRegions{ nullptr };
};

struct Decoded_VkPhysicalDeviceGroupProperties
{
    using struct_type = VkPhysicalDeviceGroupProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceGroupProperties;

    VkPhysicalDeviceGroupProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkPhysicalDevice> physicalDevices;
};

struct Decoded_VkDeviceGroupDeviceCreateInfo
{
    using struct_type = VkDeviceGroupDeviceCreateInfo;
    using api_element = schema::api_type::vulkan::VkDeviceGroupDeviceCreateInfo;

    VkDeviceGroupDeviceCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkPhysicalDevice> pPhysicalDevices;
};

struct Decoded_VkBufferMemoryRequirementsInfo2
{
    using struct_type = VkBufferMemoryRequirementsInfo2;
    using api_element = schema::api_type::vulkan::VkBufferMemoryRequirementsInfo2;

    VkBufferMemoryRequirementsInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkImageMemoryRequirementsInfo2
{
    using struct_type = VkImageMemoryRequirementsInfo2;
    using api_element = schema::api_type::vulkan::VkImageMemoryRequirementsInfo2;

    VkImageMemoryRequirementsInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
};

struct Decoded_VkImageSparseMemoryRequirementsInfo2
{
    using struct_type = VkImageSparseMemoryRequirementsInfo2;
    using api_element = schema::api_type::vulkan::VkImageSparseMemoryRequirementsInfo2;

    VkImageSparseMemoryRequirementsInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
};

struct Decoded_VkMemoryRequirements2
{
    using struct_type = VkMemoryRequirements2;
    using api_element = schema::api_type::vulkan::VkMemoryRequirements2;

    VkMemoryRequirements2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkMemoryRequirements* memoryRequirements{ nullptr };
};

struct Decoded_VkSparseImageMemoryRequirements2
{
    using struct_type = VkSparseImageMemoryRequirements2;
    using api_element = schema::api_type::vulkan::VkSparseImageMemoryRequirements2;

    VkSparseImageMemoryRequirements2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSparseImageMemoryRequirements* memoryRequirements{ nullptr };
};

struct Decoded_VkPhysicalDeviceFeatures2
{
    using struct_type = VkPhysicalDeviceFeatures2;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFeatures2;

    VkPhysicalDeviceFeatures2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPhysicalDeviceFeatures* features{ nullptr };
};

struct Decoded_VkPhysicalDeviceProperties2
{
    using struct_type = VkPhysicalDeviceProperties2;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceProperties2;

    VkPhysicalDeviceProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPhysicalDeviceProperties* properties{ nullptr };
};

struct Decoded_VkFormatProperties2
{
    using struct_type = VkFormatProperties2;
    using api_element = schema::api_type::vulkan::VkFormatProperties2;

    VkFormatProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkFormatProperties* formatProperties{ nullptr };
};

struct Decoded_VkImageFormatProperties2
{
    using struct_type = VkImageFormatProperties2;
    using api_element = schema::api_type::vulkan::VkImageFormatProperties2;

    VkImageFormatProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkImageFormatProperties* imageFormatProperties{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageFormatInfo2
{
    using struct_type = VkPhysicalDeviceImageFormatInfo2;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageFormatInfo2;

    VkPhysicalDeviceImageFormatInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyProperties2
{
    using struct_type = VkQueueFamilyProperties2;
    using api_element = schema::api_type::vulkan::VkQueueFamilyProperties2;

    VkQueueFamilyProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkQueueFamilyProperties* queueFamilyProperties{ nullptr };
};

struct Decoded_VkPhysicalDeviceMemoryProperties2
{
    using struct_type = VkPhysicalDeviceMemoryProperties2;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMemoryProperties2;

    VkPhysicalDeviceMemoryProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPhysicalDeviceMemoryProperties* memoryProperties{ nullptr };
};

struct Decoded_VkSparseImageFormatProperties2
{
    using struct_type = VkSparseImageFormatProperties2;
    using api_element = schema::api_type::vulkan::VkSparseImageFormatProperties2;

    VkSparseImageFormatProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSparseImageFormatProperties* properties{ nullptr };
};

struct Decoded_VkPhysicalDeviceSparseImageFormatInfo2
{
    using struct_type = VkPhysicalDeviceSparseImageFormatInfo2;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSparseImageFormatInfo2;

    VkPhysicalDeviceSparseImageFormatInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageViewUsageCreateInfo
{
    using struct_type = VkImageViewUsageCreateInfo;
    using api_element = schema::api_type::vulkan::VkImageViewUsageCreateInfo;

    VkImageViewUsageCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceProtectedMemoryFeatures
{
    using struct_type = VkPhysicalDeviceProtectedMemoryFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceProtectedMemoryFeatures;

    VkPhysicalDeviceProtectedMemoryFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceProtectedMemoryProperties
{
    using struct_type = VkPhysicalDeviceProtectedMemoryProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceProtectedMemoryProperties;

    VkPhysicalDeviceProtectedMemoryProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceQueueInfo2
{
    using struct_type = VkDeviceQueueInfo2;
    using api_element = schema::api_type::vulkan::VkDeviceQueueInfo2;

    VkDeviceQueueInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkProtectedSubmitInfo
{
    using struct_type = VkProtectedSubmitInfo;
    using api_element = schema::api_type::vulkan::VkProtectedSubmitInfo;

    VkProtectedSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBindImagePlaneMemoryInfo
{
    using struct_type = VkBindImagePlaneMemoryInfo;
    using api_element = schema::api_type::vulkan::VkBindImagePlaneMemoryInfo;

    VkBindImagePlaneMemoryInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImagePlaneMemoryRequirementsInfo
{
    using struct_type = VkImagePlaneMemoryRequirementsInfo;
    using api_element = schema::api_type::vulkan::VkImagePlaneMemoryRequirementsInfo;

    VkImagePlaneMemoryRequirementsInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalMemoryProperties
{
    using struct_type = VkExternalMemoryProperties;
    using api_element = schema::api_type::vulkan::VkExternalMemoryProperties;

    VkExternalMemoryProperties* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalImageFormatInfo
{
    using struct_type = VkPhysicalDeviceExternalImageFormatInfo;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExternalImageFormatInfo;

    VkPhysicalDeviceExternalImageFormatInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalImageFormatProperties
{
    using struct_type = VkExternalImageFormatProperties;
    using api_element = schema::api_type::vulkan::VkExternalImageFormatProperties;

    VkExternalImageFormatProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExternalMemoryProperties* externalMemoryProperties{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalBufferInfo
{
    using struct_type = VkPhysicalDeviceExternalBufferInfo;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExternalBufferInfo;

    VkPhysicalDeviceExternalBufferInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalBufferProperties
{
    using struct_type = VkExternalBufferProperties;
    using api_element = schema::api_type::vulkan::VkExternalBufferProperties;

    VkExternalBufferProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExternalMemoryProperties* externalMemoryProperties{ nullptr };
};

struct Decoded_VkPhysicalDeviceIDProperties
{
    using struct_type = VkPhysicalDeviceIDProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceIDProperties;

    VkPhysicalDeviceIDProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> deviceUUID;
    PointerDecoder<uint8_t> driverUUID;
    PointerDecoder<uint8_t> deviceLUID;
};

struct Decoded_VkExternalMemoryImageCreateInfo
{
    using struct_type = VkExternalMemoryImageCreateInfo;
    using api_element = schema::api_type::vulkan::VkExternalMemoryImageCreateInfo;

    VkExternalMemoryImageCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalMemoryBufferCreateInfo
{
    using struct_type = VkExternalMemoryBufferCreateInfo;
    using api_element = schema::api_type::vulkan::VkExternalMemoryBufferCreateInfo;

    VkExternalMemoryBufferCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExportMemoryAllocateInfo
{
    using struct_type = VkExportMemoryAllocateInfo;
    using api_element = schema::api_type::vulkan::VkExportMemoryAllocateInfo;

    VkExportMemoryAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalFenceInfo
{
    using struct_type = VkPhysicalDeviceExternalFenceInfo;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExternalFenceInfo;

    VkPhysicalDeviceExternalFenceInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalFenceProperties
{
    using struct_type = VkExternalFenceProperties;
    using api_element = schema::api_type::vulkan::VkExternalFenceProperties;

    VkExternalFenceProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExportFenceCreateInfo
{
    using struct_type = VkExportFenceCreateInfo;
    using api_element = schema::api_type::vulkan::VkExportFenceCreateInfo;

    VkExportFenceCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExportSemaphoreCreateInfo
{
    using struct_type = VkExportSemaphoreCreateInfo;
    using api_element = schema::api_type::vulkan::VkExportSemaphoreCreateInfo;

    VkExportSemaphoreCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalSemaphoreInfo
{
    using struct_type = VkPhysicalDeviceExternalSemaphoreInfo;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExternalSemaphoreInfo;

    VkPhysicalDeviceExternalSemaphoreInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalSemaphoreProperties
{
    using struct_type = VkExternalSemaphoreProperties;
    using api_element = schema::api_type::vulkan::VkExternalSemaphoreProperties;

    VkExternalSemaphoreProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSubgroupProperties
{
    using struct_type = VkPhysicalDeviceSubgroupProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSubgroupProperties;

    VkPhysicalDeviceSubgroupProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevice16BitStorageFeatures
{
    using struct_type = VkPhysicalDevice16BitStorageFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDevice16BitStorageFeatures;

    VkPhysicalDevice16BitStorageFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVariablePointersFeatures
{
    using struct_type = VkPhysicalDeviceVariablePointersFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVariablePointersFeatures;

    VkPhysicalDeviceVariablePointersFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorUpdateTemplateEntry
{
    using struct_type = VkDescriptorUpdateTemplateEntry;
    using api_element = schema::api_type::vulkan::VkDescriptorUpdateTemplateEntry;

    VkDescriptorUpdateTemplateEntry* decoded_value{ nullptr };
};

struct Decoded_VkDescriptorUpdateTemplateCreateInfo
{
    using struct_type = VkDescriptorUpdateTemplateCreateInfo;
    using api_element = schema::api_type::vulkan::VkDescriptorUpdateTemplateCreateInfo;

    VkDescriptorUpdateTemplateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateEntry>* pDescriptorUpdateEntries{ nullptr };
    format::HandleId descriptorSetLayout{ format::kNullHandleId };
    format::HandleId pipelineLayout{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceMaintenance3Properties
{
    using struct_type = VkPhysicalDeviceMaintenance3Properties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance3Properties;

    VkPhysicalDeviceMaintenance3Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorSetLayoutSupport
{
    using struct_type = VkDescriptorSetLayoutSupport;
    using api_element = schema::api_type::vulkan::VkDescriptorSetLayoutSupport;

    VkDescriptorSetLayoutSupport* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerYcbcrConversionCreateInfo
{
    using struct_type = VkSamplerYcbcrConversionCreateInfo;
    using api_element = schema::api_type::vulkan::VkSamplerYcbcrConversionCreateInfo;

    VkSamplerYcbcrConversionCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkComponentMapping* components{ nullptr };
};

struct Decoded_VkSamplerYcbcrConversionInfo
{
    using struct_type = VkSamplerYcbcrConversionInfo;
    using api_element = schema::api_type::vulkan::VkSamplerYcbcrConversionInfo;

    VkSamplerYcbcrConversionInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId conversion{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures
{
    using struct_type = VkPhysicalDeviceSamplerYcbcrConversionFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSamplerYcbcrConversionFeatures;

    VkPhysicalDeviceSamplerYcbcrConversionFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerYcbcrConversionImageFormatProperties
{
    using struct_type = VkSamplerYcbcrConversionImageFormatProperties;
    using api_element = schema::api_type::vulkan::VkSamplerYcbcrConversionImageFormatProperties;

    VkSamplerYcbcrConversionImageFormatProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceGroupRenderPassBeginInfo
{
    using struct_type = VkDeviceGroupRenderPassBeginInfo;
    using api_element = schema::api_type::vulkan::VkDeviceGroupRenderPassBeginInfo;

    VkDeviceGroupRenderPassBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pDeviceRenderAreas{ nullptr };
};

struct Decoded_VkPhysicalDevicePointClippingProperties
{
    using struct_type = VkPhysicalDevicePointClippingProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePointClippingProperties;

    VkPhysicalDevicePointClippingProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkInputAttachmentAspectReference
{
    using struct_type = VkInputAttachmentAspectReference;
    using api_element = schema::api_type::vulkan::VkInputAttachmentAspectReference;

    VkInputAttachmentAspectReference* decoded_value{ nullptr };
};

struct Decoded_VkRenderPassInputAttachmentAspectCreateInfo
{
    using struct_type = VkRenderPassInputAttachmentAspectCreateInfo;
    using api_element = schema::api_type::vulkan::VkRenderPassInputAttachmentAspectCreateInfo;

    VkRenderPassInputAttachmentAspectCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkInputAttachmentAspectReference>* pAspectReferences{ nullptr };
};

struct Decoded_VkPipelineTessellationDomainOriginStateCreateInfo
{
    using struct_type = VkPipelineTessellationDomainOriginStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineTessellationDomainOriginStateCreateInfo;

    VkPipelineTessellationDomainOriginStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderPassMultiviewCreateInfo
{
    using struct_type = VkRenderPassMultiviewCreateInfo;
    using api_element = schema::api_type::vulkan::VkRenderPassMultiviewCreateInfo;

    VkRenderPassMultiviewCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pViewMasks;
    PointerDecoder<int32_t> pViewOffsets;
    PointerDecoder<uint32_t> pCorrelationMasks;
};

struct Decoded_VkPhysicalDeviceMultiviewFeatures
{
    using struct_type = VkPhysicalDeviceMultiviewFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMultiviewFeatures;

    VkPhysicalDeviceMultiviewFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiviewProperties
{
    using struct_type = VkPhysicalDeviceMultiviewProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMultiviewProperties;

    VkPhysicalDeviceMultiviewProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderDrawParametersFeatures
{
    using struct_type = VkPhysicalDeviceShaderDrawParametersFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderDrawParametersFeatures;

    VkPhysicalDeviceShaderDrawParametersFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkConformanceVersion
{
    using struct_type = VkConformanceVersion;
    using api_element = schema::api_type::vulkan::VkConformanceVersion;

    VkConformanceVersion* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceDriverProperties
{
    using struct_type = VkPhysicalDeviceDriverProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDriverProperties;

    VkPhysicalDeviceDriverProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder driverName;
    StringDecoder driverInfo;
    Decoded_VkConformanceVersion* conformanceVersion{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkan11Features
{
    using struct_type = VkPhysicalDeviceVulkan11Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVulkan11Features;

    VkPhysicalDeviceVulkan11Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkan11Properties
{
    using struct_type = VkPhysicalDeviceVulkan11Properties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVulkan11Properties;

    VkPhysicalDeviceVulkan11Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> deviceUUID;
    PointerDecoder<uint8_t> driverUUID;
    PointerDecoder<uint8_t> deviceLUID;
};

struct Decoded_VkPhysicalDeviceVulkan12Features
{
    using struct_type = VkPhysicalDeviceVulkan12Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVulkan12Features;

    VkPhysicalDeviceVulkan12Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkan12Properties
{
    using struct_type = VkPhysicalDeviceVulkan12Properties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVulkan12Properties;

    VkPhysicalDeviceVulkan12Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder driverName;
    StringDecoder driverInfo;
    Decoded_VkConformanceVersion* conformanceVersion{ nullptr };
};

struct Decoded_VkImageFormatListCreateInfo
{
    using struct_type = VkImageFormatListCreateInfo;
    using api_element = schema::api_type::vulkan::VkImageFormatListCreateInfo;

    VkImageFormatListCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pViewFormats;
};

struct Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures
{
    using struct_type = VkPhysicalDeviceVulkanMemoryModelFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVulkanMemoryModelFeatures;

    VkPhysicalDeviceVulkanMemoryModelFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceHostQueryResetFeatures
{
    using struct_type = VkPhysicalDeviceHostQueryResetFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceHostQueryResetFeatures;

    VkPhysicalDeviceHostQueryResetFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures
{
    using struct_type = VkPhysicalDeviceTimelineSemaphoreFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTimelineSemaphoreFeatures;

    VkPhysicalDeviceTimelineSemaphoreFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTimelineSemaphoreProperties
{
    using struct_type = VkPhysicalDeviceTimelineSemaphoreProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTimelineSemaphoreProperties;

    VkPhysicalDeviceTimelineSemaphoreProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSemaphoreTypeCreateInfo
{
    using struct_type = VkSemaphoreTypeCreateInfo;
    using api_element = schema::api_type::vulkan::VkSemaphoreTypeCreateInfo;

    VkSemaphoreTypeCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTimelineSemaphoreSubmitInfo
{
    using struct_type = VkTimelineSemaphoreSubmitInfo;
    using api_element = schema::api_type::vulkan::VkTimelineSemaphoreSubmitInfo;

    VkTimelineSemaphoreSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint64_t> pWaitSemaphoreValues;
    PointerDecoder<uint64_t> pSignalSemaphoreValues;
};

struct Decoded_VkSemaphoreWaitInfo
{
    using struct_type = VkSemaphoreWaitInfo;
    using api_element = schema::api_type::vulkan::VkSemaphoreWaitInfo;

    VkSemaphoreWaitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkSemaphore> pSemaphores;
    PointerDecoder<uint64_t> pValues;
};

struct Decoded_VkSemaphoreSignalInfo
{
    using struct_type = VkSemaphoreSignalInfo;
    using api_element = schema::api_type::vulkan::VkSemaphoreSignalInfo;

    VkSemaphoreSignalInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures
{
    using struct_type = VkPhysicalDeviceBufferDeviceAddressFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceBufferDeviceAddressFeatures;

    VkPhysicalDeviceBufferDeviceAddressFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferDeviceAddressInfo
{
    using struct_type = VkBufferDeviceAddressInfo;
    using api_element = schema::api_type::vulkan::VkBufferDeviceAddressInfo;

    VkBufferDeviceAddressInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkBufferOpaqueCaptureAddressCreateInfo
{
    using struct_type = VkBufferOpaqueCaptureAddressCreateInfo;
    using api_element = schema::api_type::vulkan::VkBufferOpaqueCaptureAddressCreateInfo;

    VkBufferOpaqueCaptureAddressCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo
{
    using struct_type = VkMemoryOpaqueCaptureAddressAllocateInfo;
    using api_element = schema::api_type::vulkan::VkMemoryOpaqueCaptureAddressAllocateInfo;

    VkMemoryOpaqueCaptureAddressAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo
{
    using struct_type = VkDeviceMemoryOpaqueCaptureAddressInfo;
    using api_element = schema::api_type::vulkan::VkDeviceMemoryOpaqueCaptureAddressInfo;

    VkDeviceMemoryOpaqueCaptureAddressInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDevice8BitStorageFeatures
{
    using struct_type = VkPhysicalDevice8BitStorageFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDevice8BitStorageFeatures;

    VkPhysicalDevice8BitStorageFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderAtomicInt64Features
{
    using struct_type = VkPhysicalDeviceShaderAtomicInt64Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderAtomicInt64Features;

    VkPhysicalDeviceShaderAtomicInt64Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderFloat16Int8Features
{
    using struct_type = VkPhysicalDeviceShaderFloat16Int8Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderFloat16Int8Features;

    VkPhysicalDeviceShaderFloat16Int8Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFloatControlsProperties
{
    using struct_type = VkPhysicalDeviceFloatControlsProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFloatControlsProperties;

    VkPhysicalDeviceFloatControlsProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo
{
    using struct_type = VkDescriptorSetLayoutBindingFlagsCreateInfo;
    using api_element = schema::api_type::vulkan::VkDescriptorSetLayoutBindingFlagsCreateInfo;

    VkDescriptorSetLayoutBindingFlagsCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkDescriptorBindingFlags> pBindingFlags;
};

struct Decoded_VkPhysicalDeviceDescriptorIndexingFeatures
{
    using struct_type = VkPhysicalDeviceDescriptorIndexingFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDescriptorIndexingFeatures;

    VkPhysicalDeviceDescriptorIndexingFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDescriptorIndexingProperties
{
    using struct_type = VkPhysicalDeviceDescriptorIndexingProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDescriptorIndexingProperties;

    VkPhysicalDeviceDescriptorIndexingProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo
{
    using struct_type = VkDescriptorSetVariableDescriptorCountAllocateInfo;
    using api_element = schema::api_type::vulkan::VkDescriptorSetVariableDescriptorCountAllocateInfo;

    VkDescriptorSetVariableDescriptorCountAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pDescriptorCounts;
};

struct Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport
{
    using struct_type = VkDescriptorSetVariableDescriptorCountLayoutSupport;
    using api_element = schema::api_type::vulkan::VkDescriptorSetVariableDescriptorCountLayoutSupport;

    VkDescriptorSetVariableDescriptorCountLayoutSupport* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures
{
    using struct_type = VkPhysicalDeviceScalarBlockLayoutFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceScalarBlockLayoutFeatures;

    VkPhysicalDeviceScalarBlockLayoutFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerReductionModeCreateInfo
{
    using struct_type = VkSamplerReductionModeCreateInfo;
    using api_element = schema::api_type::vulkan::VkSamplerReductionModeCreateInfo;

    VkSamplerReductionModeCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties
{
    using struct_type = VkPhysicalDeviceSamplerFilterMinmaxProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSamplerFilterMinmaxProperties;

    VkPhysicalDeviceSamplerFilterMinmaxProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures
{
    using struct_type = VkPhysicalDeviceUniformBufferStandardLayoutFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceUniformBufferStandardLayoutFeatures;

    VkPhysicalDeviceUniformBufferStandardLayoutFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures
{
    using struct_type = VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures;

    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAttachmentDescription2
{
    using struct_type = VkAttachmentDescription2;
    using api_element = schema::api_type::vulkan::VkAttachmentDescription2;

    VkAttachmentDescription2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAttachmentReference2
{
    using struct_type = VkAttachmentReference2;
    using api_element = schema::api_type::vulkan::VkAttachmentReference2;

    VkAttachmentReference2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSubpassDescription2
{
    using struct_type = VkSubpassDescription2;
    using api_element = schema::api_type::vulkan::VkSubpassDescription2;

    VkSubpassDescription2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference2>* pInputAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference2>* pColorAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference2>* pResolveAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference2>* pDepthStencilAttachment{ nullptr };
    PointerDecoder<uint32_t> pPreserveAttachments;
};

struct Decoded_VkSubpassDependency2
{
    using struct_type = VkSubpassDependency2;
    using api_element = schema::api_type::vulkan::VkSubpassDependency2;

    VkSubpassDependency2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSubpassBeginInfo
{
    using struct_type = VkSubpassBeginInfo;
    using api_element = schema::api_type::vulkan::VkSubpassBeginInfo;

    VkSubpassBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSubpassEndInfo
{
    using struct_type = VkSubpassEndInfo;
    using api_element = schema::api_type::vulkan::VkSubpassEndInfo;

    VkSubpassEndInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderPassCreateInfo2
{
    using struct_type = VkRenderPassCreateInfo2;
    using api_element = schema::api_type::vulkan::VkRenderPassCreateInfo2;

    VkRenderPassCreateInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentDescription2>* pAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkSubpassDescription2>* pSubpasses{ nullptr };
    StructPointerDecoder<Decoded_VkSubpassDependency2>* pDependencies{ nullptr };
    PointerDecoder<uint32_t> pCorrelatedViewMasks;
};

struct Decoded_VkSubpassDescriptionDepthStencilResolve
{
    using struct_type = VkSubpassDescriptionDepthStencilResolve;
    using api_element = schema::api_type::vulkan::VkSubpassDescriptionDepthStencilResolve;

    VkSubpassDescriptionDepthStencilResolve* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference2>* pDepthStencilResolveAttachment{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthStencilResolveProperties
{
    using struct_type = VkPhysicalDeviceDepthStencilResolveProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDepthStencilResolveProperties;

    VkPhysicalDeviceDepthStencilResolveProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageStencilUsageCreateInfo
{
    using struct_type = VkImageStencilUsageCreateInfo;
    using api_element = schema::api_type::vulkan::VkImageStencilUsageCreateInfo;

    VkImageStencilUsageCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImagelessFramebufferFeatures
{
    using struct_type = VkPhysicalDeviceImagelessFramebufferFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImagelessFramebufferFeatures;

    VkPhysicalDeviceImagelessFramebufferFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFramebufferAttachmentImageInfo
{
    using struct_type = VkFramebufferAttachmentImageInfo;
    using api_element = schema::api_type::vulkan::VkFramebufferAttachmentImageInfo;

    VkFramebufferAttachmentImageInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pViewFormats;
};

struct Decoded_VkRenderPassAttachmentBeginInfo
{
    using struct_type = VkRenderPassAttachmentBeginInfo;
    using api_element = schema::api_type::vulkan::VkRenderPassAttachmentBeginInfo;

    VkRenderPassAttachmentBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkImageView> pAttachments;
};

struct Decoded_VkFramebufferAttachmentsCreateInfo
{
    using struct_type = VkFramebufferAttachmentsCreateInfo;
    using api_element = schema::api_type::vulkan::VkFramebufferAttachmentsCreateInfo;

    VkFramebufferAttachmentsCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkFramebufferAttachmentImageInfo>* pAttachmentImageInfos{ nullptr };
};

struct Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures
{
    using struct_type = VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures;

    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAttachmentReferenceStencilLayout
{
    using struct_type = VkAttachmentReferenceStencilLayout;
    using api_element = schema::api_type::vulkan::VkAttachmentReferenceStencilLayout;

    VkAttachmentReferenceStencilLayout* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAttachmentDescriptionStencilLayout
{
    using struct_type = VkAttachmentDescriptionStencilLayout;
    using api_element = schema::api_type::vulkan::VkAttachmentDescriptionStencilLayout;

    VkAttachmentDescriptionStencilLayout* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkan13Features
{
    using struct_type = VkPhysicalDeviceVulkan13Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVulkan13Features;

    VkPhysicalDeviceVulkan13Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkan13Properties
{
    using struct_type = VkPhysicalDeviceVulkan13Properties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVulkan13Properties;

    VkPhysicalDeviceVulkan13Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceToolProperties
{
    using struct_type = VkPhysicalDeviceToolProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceToolProperties;

    VkPhysicalDeviceToolProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
    StringDecoder version;
    StringDecoder description;
    StringDecoder layer;
};

struct Decoded_VkPhysicalDevicePrivateDataFeatures
{
    using struct_type = VkPhysicalDevicePrivateDataFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePrivateDataFeatures;

    VkPhysicalDevicePrivateDataFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDevicePrivateDataCreateInfo
{
    using struct_type = VkDevicePrivateDataCreateInfo;
    using api_element = schema::api_type::vulkan::VkDevicePrivateDataCreateInfo;

    VkDevicePrivateDataCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPrivateDataSlotCreateInfo
{
    using struct_type = VkPrivateDataSlotCreateInfo;
    using api_element = schema::api_type::vulkan::VkPrivateDataSlotCreateInfo;

    VkPrivateDataSlotCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryBarrier2
{
    using struct_type = VkMemoryBarrier2;
    using api_element = schema::api_type::vulkan::VkMemoryBarrier2;

    VkMemoryBarrier2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferMemoryBarrier2
{
    using struct_type = VkBufferMemoryBarrier2;
    using api_element = schema::api_type::vulkan::VkBufferMemoryBarrier2;

    VkBufferMemoryBarrier2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkImageMemoryBarrier2
{
    using struct_type = VkImageMemoryBarrier2;
    using api_element = schema::api_type::vulkan::VkImageMemoryBarrier2;

    VkImageMemoryBarrier2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    Decoded_VkImageSubresourceRange* subresourceRange{ nullptr };
};

struct Decoded_VkDependencyInfo
{
    using struct_type = VkDependencyInfo;
    using api_element = schema::api_type::vulkan::VkDependencyInfo;

    VkDependencyInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkMemoryBarrier2>* pMemoryBarriers{ nullptr };
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier2>* pBufferMemoryBarriers{ nullptr };
    StructPointerDecoder<Decoded_VkImageMemoryBarrier2>* pImageMemoryBarriers{ nullptr };
};

struct Decoded_VkSemaphoreSubmitInfo
{
    using struct_type = VkSemaphoreSubmitInfo;
    using api_element = schema::api_type::vulkan::VkSemaphoreSubmitInfo;

    VkSemaphoreSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkCommandBufferSubmitInfo
{
    using struct_type = VkCommandBufferSubmitInfo;
    using api_element = schema::api_type::vulkan::VkCommandBufferSubmitInfo;

    VkCommandBufferSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId commandBuffer{ format::kNullHandleId };
};

struct Decoded_VkSubmitInfo2
{
    using struct_type = VkSubmitInfo2;
    using api_element = schema::api_type::vulkan::VkSubmitInfo2;

    VkSubmitInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* pWaitSemaphoreInfos{ nullptr };
    StructPointerDecoder<Decoded_VkCommandBufferSubmitInfo>* pCommandBufferInfos{ nullptr };
    StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* pSignalSemaphoreInfos{ nullptr };
};

struct Decoded_VkPhysicalDeviceSynchronization2Features
{
    using struct_type = VkPhysicalDeviceSynchronization2Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSynchronization2Features;

    VkPhysicalDeviceSynchronization2Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferCopy2
{
    using struct_type = VkBufferCopy2;
    using api_element = schema::api_type::vulkan::VkBufferCopy2;

    VkBufferCopy2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCopyBufferInfo2
{
    using struct_type = VkCopyBufferInfo2;
    using api_element = schema::api_type::vulkan::VkCopyBufferInfo2;

    VkCopyBufferInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcBuffer{ format::kNullHandleId };
    format::HandleId dstBuffer{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkBufferCopy2>* pRegions{ nullptr };
};

struct Decoded_VkImageCopy2
{
    using struct_type = VkImageCopy2;
    using api_element = schema::api_type::vulkan::VkImageCopy2;

    VkImageCopy2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkImageSubresourceLayers* srcSubresource{ nullptr };
    Decoded_VkOffset3D* srcOffset{ nullptr };
    Decoded_VkImageSubresourceLayers* dstSubresource{ nullptr };
    Decoded_VkOffset3D* dstOffset{ nullptr };
    Decoded_VkExtent3D* extent{ nullptr };
};

struct Decoded_VkCopyImageInfo2
{
    using struct_type = VkCopyImageInfo2;
    using api_element = schema::api_type::vulkan::VkCopyImageInfo2;

    VkCopyImageInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageCopy2>* pRegions{ nullptr };
};

struct Decoded_VkBufferImageCopy2
{
    using struct_type = VkBufferImageCopy2;
    using api_element = schema::api_type::vulkan::VkBufferImageCopy2;

    VkBufferImageCopy2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkImageSubresourceLayers* imageSubresource{ nullptr };
    Decoded_VkOffset3D* imageOffset{ nullptr };
    Decoded_VkExtent3D* imageExtent{ nullptr };
};

struct Decoded_VkCopyBufferToImageInfo2
{
    using struct_type = VkCopyBufferToImageInfo2;
    using api_element = schema::api_type::vulkan::VkCopyBufferToImageInfo2;

    VkCopyBufferToImageInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcBuffer{ format::kNullHandleId };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkBufferImageCopy2>* pRegions{ nullptr };
};

struct Decoded_VkCopyImageToBufferInfo2
{
    using struct_type = VkCopyImageToBufferInfo2;
    using api_element = schema::api_type::vulkan::VkCopyImageToBufferInfo2;

    VkCopyImageToBufferInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    format::HandleId dstBuffer{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkBufferImageCopy2>* pRegions{ nullptr };
};

struct Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures
{
    using struct_type = VkPhysicalDeviceTextureCompressionASTCHDRFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTextureCompressionASTCHDRFeatures;

    VkPhysicalDeviceTextureCompressionASTCHDRFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFormatProperties3
{
    using struct_type = VkFormatProperties3;
    using api_element = schema::api_type::vulkan::VkFormatProperties3;

    VkFormatProperties3* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance4Features
{
    using struct_type = VkPhysicalDeviceMaintenance4Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance4Features;

    VkPhysicalDeviceMaintenance4Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance4Properties
{
    using struct_type = VkPhysicalDeviceMaintenance4Properties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance4Properties;

    VkPhysicalDeviceMaintenance4Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceBufferMemoryRequirements
{
    using struct_type = VkDeviceBufferMemoryRequirements;
    using api_element = schema::api_type::vulkan::VkDeviceBufferMemoryRequirements;

    VkDeviceBufferMemoryRequirements* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo{ nullptr };
};

struct Decoded_VkDeviceImageMemoryRequirements
{
    using struct_type = VkDeviceImageMemoryRequirements;
    using api_element = schema::api_type::vulkan::VkDeviceImageMemoryRequirements;

    VkDeviceImageMemoryRequirements* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo{ nullptr };
};

struct Decoded_VkPipelineCreationFeedback
{
    using struct_type = VkPipelineCreationFeedback;
    using api_element = schema::api_type::vulkan::VkPipelineCreationFeedback;

    VkPipelineCreationFeedback* decoded_value{ nullptr };
};

struct Decoded_VkPipelineCreationFeedbackCreateInfo
{
    using struct_type = VkPipelineCreationFeedbackCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineCreationFeedbackCreateInfo;

    VkPipelineCreationFeedbackCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineCreationFeedback>* pPipelineCreationFeedback{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineCreationFeedback>* pPipelineStageCreationFeedbacks{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures
{
    using struct_type = VkPhysicalDeviceShaderTerminateInvocationFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderTerminateInvocationFeatures;

    VkPhysicalDeviceShaderTerminateInvocationFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures
{
    using struct_type = VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures;

    VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures
{
    using struct_type = VkPhysicalDevicePipelineCreationCacheControlFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePipelineCreationCacheControlFeatures;

    VkPhysicalDevicePipelineCreationCacheControlFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures
{
    using struct_type = VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures;

    VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageRobustnessFeatures
{
    using struct_type = VkPhysicalDeviceImageRobustnessFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageRobustnessFeatures;

    VkPhysicalDeviceImageRobustnessFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures
{
    using struct_type = VkPhysicalDeviceSubgroupSizeControlFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSubgroupSizeControlFeatures;

    VkPhysicalDeviceSubgroupSizeControlFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSubgroupSizeControlProperties
{
    using struct_type = VkPhysicalDeviceSubgroupSizeControlProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSubgroupSizeControlProperties;

    VkPhysicalDeviceSubgroupSizeControlProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo
{
    using struct_type = VkPipelineShaderStageRequiredSubgroupSizeCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineShaderStageRequiredSubgroupSizeCreateInfo;

    VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceInlineUniformBlockFeatures
{
    using struct_type = VkPhysicalDeviceInlineUniformBlockFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceInlineUniformBlockFeatures;

    VkPhysicalDeviceInlineUniformBlockFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceInlineUniformBlockProperties
{
    using struct_type = VkPhysicalDeviceInlineUniformBlockProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceInlineUniformBlockProperties;

    VkPhysicalDeviceInlineUniformBlockProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkWriteDescriptorSetInlineUniformBlock
{
    using struct_type = VkWriteDescriptorSetInlineUniformBlock;
    using api_element = schema::api_type::vulkan::VkWriteDescriptorSetInlineUniformBlock;

    VkWriteDescriptorSetInlineUniformBlock* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo
{
    using struct_type = VkDescriptorPoolInlineUniformBlockCreateInfo;
    using api_element = schema::api_type::vulkan::VkDescriptorPoolInlineUniformBlockCreateInfo;

    VkDescriptorPoolInlineUniformBlockCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures
{
    using struct_type = VkPhysicalDeviceShaderIntegerDotProductFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderIntegerDotProductFeatures;

    VkPhysicalDeviceShaderIntegerDotProductFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties
{
    using struct_type = VkPhysicalDeviceShaderIntegerDotProductProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderIntegerDotProductProperties;

    VkPhysicalDeviceShaderIntegerDotProductProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties
{
    using struct_type = VkPhysicalDeviceTexelBufferAlignmentProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTexelBufferAlignmentProperties;

    VkPhysicalDeviceTexelBufferAlignmentProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageBlit2
{
    using struct_type = VkImageBlit2;
    using api_element = schema::api_type::vulkan::VkImageBlit2;

    VkImageBlit2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkImageSubresourceLayers* srcSubresource{ nullptr };
    StructPointerDecoder<Decoded_VkOffset3D>* srcOffsets{ nullptr };
    Decoded_VkImageSubresourceLayers* dstSubresource{ nullptr };
    StructPointerDecoder<Decoded_VkOffset3D>* dstOffsets{ nullptr };
};

struct Decoded_VkBlitImageInfo2
{
    using struct_type = VkBlitImageInfo2;
    using api_element = schema::api_type::vulkan::VkBlitImageInfo2;

    VkBlitImageInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageBlit2>* pRegions{ nullptr };
};

struct Decoded_VkImageResolve2
{
    using struct_type = VkImageResolve2;
    using api_element = schema::api_type::vulkan::VkImageResolve2;

    VkImageResolve2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkImageSubresourceLayers* srcSubresource{ nullptr };
    Decoded_VkOffset3D* srcOffset{ nullptr };
    Decoded_VkImageSubresourceLayers* dstSubresource{ nullptr };
    Decoded_VkOffset3D* dstOffset{ nullptr };
    Decoded_VkExtent3D* extent{ nullptr };
};

struct Decoded_VkResolveImageInfo2
{
    using struct_type = VkResolveImageInfo2;
    using api_element = schema::api_type::vulkan::VkResolveImageInfo2;

    VkResolveImageInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageResolve2>* pRegions{ nullptr };
};

struct Decoded_VkRenderingAttachmentInfo
{
    using struct_type = VkRenderingAttachmentInfo;
    using api_element = schema::api_type::vulkan::VkRenderingAttachmentInfo;

    VkRenderingAttachmentInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId imageView{ format::kNullHandleId };
    format::HandleId resolveImageView{ format::kNullHandleId };
    Decoded_VkClearValue* clearValue{ nullptr };
};

struct Decoded_VkRenderingInfo
{
    using struct_type = VkRenderingInfo;
    using api_element = schema::api_type::vulkan::VkRenderingInfo;

    VkRenderingInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkRect2D* renderArea{ nullptr };
    StructPointerDecoder<Decoded_VkRenderingAttachmentInfo>* pColorAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkRenderingAttachmentInfo>* pDepthAttachment{ nullptr };
    StructPointerDecoder<Decoded_VkRenderingAttachmentInfo>* pStencilAttachment{ nullptr };
};

struct Decoded_VkPipelineRenderingCreateInfo
{
    using struct_type = VkPipelineRenderingCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineRenderingCreateInfo;

    VkPipelineRenderingCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pColorAttachmentFormats;
};

struct Decoded_VkPhysicalDeviceDynamicRenderingFeatures
{
    using struct_type = VkPhysicalDeviceDynamicRenderingFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDynamicRenderingFeatures;

    VkPhysicalDeviceDynamicRenderingFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCommandBufferInheritanceRenderingInfo
{
    using struct_type = VkCommandBufferInheritanceRenderingInfo;
    using api_element = schema::api_type::vulkan::VkCommandBufferInheritanceRenderingInfo;

    VkCommandBufferInheritanceRenderingInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pColorAttachmentFormats;
};

struct Decoded_VkPhysicalDeviceVulkan14Features
{
    using struct_type = VkPhysicalDeviceVulkan14Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVulkan14Features;

    VkPhysicalDeviceVulkan14Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkan14Properties
{
    using struct_type = VkPhysicalDeviceVulkan14Properties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVulkan14Properties;

    VkPhysicalDeviceVulkan14Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkImageLayout> pCopySrcLayouts;
    PointerDecoder<VkImageLayout> pCopyDstLayouts;
    PointerDecoder<uint8_t> optimalTilingLayoutUUID;
};

struct Decoded_VkDeviceQueueGlobalPriorityCreateInfo
{
    using struct_type = VkDeviceQueueGlobalPriorityCreateInfo;
    using api_element = schema::api_type::vulkan::VkDeviceQueueGlobalPriorityCreateInfo;

    VkDeviceQueueGlobalPriorityCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures
{
    using struct_type = VkPhysicalDeviceGlobalPriorityQueryFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceGlobalPriorityQueryFeatures;

    VkPhysicalDeviceGlobalPriorityQueryFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyGlobalPriorityProperties
{
    using struct_type = VkQueueFamilyGlobalPriorityProperties;
    using api_element = schema::api_type::vulkan::VkQueueFamilyGlobalPriorityProperties;

    VkQueueFamilyGlobalPriorityProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkQueueGlobalPriority> priorities;
};

struct Decoded_VkPhysicalDeviceIndexTypeUint8Features
{
    using struct_type = VkPhysicalDeviceIndexTypeUint8Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceIndexTypeUint8Features;

    VkPhysicalDeviceIndexTypeUint8Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryMapInfo
{
    using struct_type = VkMemoryMapInfo;
    using api_element = schema::api_type::vulkan::VkMemoryMapInfo;

    VkMemoryMapInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkMemoryUnmapInfo
{
    using struct_type = VkMemoryUnmapInfo;
    using api_element = schema::api_type::vulkan::VkMemoryUnmapInfo;

    VkMemoryUnmapInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceMaintenance5Features
{
    using struct_type = VkPhysicalDeviceMaintenance5Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance5Features;

    VkPhysicalDeviceMaintenance5Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance5Properties
{
    using struct_type = VkPhysicalDeviceMaintenance5Properties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance5Properties;

    VkPhysicalDeviceMaintenance5Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSubresourceLayout2
{
    using struct_type = VkSubresourceLayout2;
    using api_element = schema::api_type::vulkan::VkSubresourceLayout2;

    VkSubresourceLayout2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSubresourceLayout* subresourceLayout{ nullptr };
};

struct Decoded_VkImageSubresource2
{
    using struct_type = VkImageSubresource2;
    using api_element = schema::api_type::vulkan::VkImageSubresource2;

    VkImageSubresource2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkImageSubresource* imageSubresource{ nullptr };
};

struct Decoded_VkDeviceImageSubresourceInfo
{
    using struct_type = VkDeviceImageSubresourceInfo;
    using api_element = schema::api_type::vulkan::VkDeviceImageSubresourceInfo;

    VkDeviceImageSubresourceInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo{ nullptr };
    StructPointerDecoder<Decoded_VkImageSubresource2>* pSubresource{ nullptr };
};

struct Decoded_VkBufferUsageFlags2CreateInfo
{
    using struct_type = VkBufferUsageFlags2CreateInfo;
    using api_element = schema::api_type::vulkan::VkBufferUsageFlags2CreateInfo;

    VkBufferUsageFlags2CreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance6Features
{
    using struct_type = VkPhysicalDeviceMaintenance6Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance6Features;

    VkPhysicalDeviceMaintenance6Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance6Properties
{
    using struct_type = VkPhysicalDeviceMaintenance6Properties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance6Properties;

    VkPhysicalDeviceMaintenance6Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBindMemoryStatus
{
    using struct_type = VkBindMemoryStatus;
    using api_element = schema::api_type::vulkan::VkBindMemoryStatus;

    VkBindMemoryStatus* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkResult> pResult;
};

struct Decoded_VkPhysicalDeviceHostImageCopyFeatures
{
    using struct_type = VkPhysicalDeviceHostImageCopyFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceHostImageCopyFeatures;

    VkPhysicalDeviceHostImageCopyFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceHostImageCopyProperties
{
    using struct_type = VkPhysicalDeviceHostImageCopyProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceHostImageCopyProperties;

    VkPhysicalDeviceHostImageCopyProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkImageLayout> pCopySrcLayouts;
    PointerDecoder<VkImageLayout> pCopyDstLayouts;
    PointerDecoder<uint8_t> optimalTilingLayoutUUID;
};

struct Decoded_VkCopyImageToImageInfo
{
    using struct_type = VkCopyImageToImageInfo;
    using api_element = schema::api_type::vulkan::VkCopyImageToImageInfo;

    VkCopyImageToImageInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageCopy2>* pRegions{ nullptr };
};

struct Decoded_VkHostImageLayoutTransitionInfo
{
    using struct_type = VkHostImageLayoutTransitionInfo;
    using api_element = schema::api_type::vulkan::VkHostImageLayoutTransitionInfo;

    VkHostImageLayoutTransitionInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    Decoded_VkImageSubresourceRange* subresourceRange{ nullptr };
};

struct Decoded_VkSubresourceHostMemcpySize
{
    using struct_type = VkSubresourceHostMemcpySize;
    using api_element = schema::api_type::vulkan::VkSubresourceHostMemcpySize;

    VkSubresourceHostMemcpySize* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkHostImageCopyDevicePerformanceQuery
{
    using struct_type = VkHostImageCopyDevicePerformanceQuery;
    using api_element = schema::api_type::vulkan::VkHostImageCopyDevicePerformanceQuery;

    VkHostImageCopyDevicePerformanceQuery* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderSubgroupRotateFeatures
{
    using struct_type = VkPhysicalDeviceShaderSubgroupRotateFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderSubgroupRotateFeatures;

    VkPhysicalDeviceShaderSubgroupRotateFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderFloatControls2Features
{
    using struct_type = VkPhysicalDeviceShaderFloatControls2Features;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderFloatControls2Features;

    VkPhysicalDeviceShaderFloatControls2Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderExpectAssumeFeatures
{
    using struct_type = VkPhysicalDeviceShaderExpectAssumeFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderExpectAssumeFeatures;

    VkPhysicalDeviceShaderExpectAssumeFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCreateFlags2CreateInfo
{
    using struct_type = VkPipelineCreateFlags2CreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineCreateFlags2CreateInfo;

    VkPipelineCreateFlags2CreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePushDescriptorProperties
{
    using struct_type = VkPhysicalDevicePushDescriptorProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePushDescriptorProperties;

    VkPhysicalDevicePushDescriptorProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBindDescriptorSetsInfo
{
    using struct_type = VkBindDescriptorSetsInfo;
    using api_element = schema::api_type::vulkan::VkBindDescriptorSetsInfo;

    VkBindDescriptorSetsInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;
    PointerDecoder<uint32_t> pDynamicOffsets;
};

struct Decoded_VkPushConstantsInfo
{
    using struct_type = VkPushConstantsInfo;
    using api_element = schema::api_type::vulkan::VkPushConstantsInfo;

    VkPushConstantsInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    PointerDecoder<uint8_t> pValues;
};

struct Decoded_VkPushDescriptorSetInfo
{
    using struct_type = VkPushDescriptorSetInfo;
    using api_element = schema::api_type::vulkan::VkPushDescriptorSetInfo;

    VkPushDescriptorSetInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineProtectedAccessFeatures
{
    using struct_type = VkPhysicalDevicePipelineProtectedAccessFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePipelineProtectedAccessFeatures;

    VkPhysicalDevicePipelineProtectedAccessFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineRobustnessFeatures
{
    using struct_type = VkPhysicalDevicePipelineRobustnessFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePipelineRobustnessFeatures;

    VkPhysicalDevicePipelineRobustnessFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineRobustnessProperties
{
    using struct_type = VkPhysicalDevicePipelineRobustnessProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePipelineRobustnessProperties;

    VkPhysicalDevicePipelineRobustnessProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRobustnessCreateInfo
{
    using struct_type = VkPipelineRobustnessCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineRobustnessCreateInfo;

    VkPipelineRobustnessCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceLineRasterizationFeatures
{
    using struct_type = VkPhysicalDeviceLineRasterizationFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLineRasterizationFeatures;

    VkPhysicalDeviceLineRasterizationFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceLineRasterizationProperties
{
    using struct_type = VkPhysicalDeviceLineRasterizationProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLineRasterizationProperties;

    VkPhysicalDeviceLineRasterizationProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRasterizationLineStateCreateInfo
{
    using struct_type = VkPipelineRasterizationLineStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineRasterizationLineStateCreateInfo;

    VkPipelineRasterizationLineStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorProperties
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorProperties;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVertexAttributeDivisorProperties;

    VkPhysicalDeviceVertexAttributeDivisorProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVertexInputBindingDivisorDescription
{
    using struct_type = VkVertexInputBindingDivisorDescription;
    using api_element = schema::api_type::vulkan::VkVertexInputBindingDivisorDescription;

    VkVertexInputBindingDivisorDescription* decoded_value{ nullptr };
};

struct Decoded_VkPipelineVertexInputDivisorStateCreateInfo
{
    using struct_type = VkPipelineVertexInputDivisorStateCreateInfo;
    using api_element = schema::api_type::vulkan::VkPipelineVertexInputDivisorStateCreateInfo;

    VkPipelineVertexInputDivisorStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVertexInputBindingDivisorDescription>* pVertexBindingDivisors{ nullptr };
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVertexAttributeDivisorFeatures;

    VkPhysicalDeviceVertexAttributeDivisorFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderingAreaInfo
{
    using struct_type = VkRenderingAreaInfo;
    using api_element = schema::api_type::vulkan::VkRenderingAreaInfo;

    VkRenderingAreaInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pColorAttachmentFormats;
};

struct Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeatures
{
    using struct_type = VkPhysicalDeviceDynamicRenderingLocalReadFeatures;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDynamicRenderingLocalReadFeatures;

    VkPhysicalDeviceDynamicRenderingLocalReadFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderingAttachmentLocationInfo
{
    using struct_type = VkRenderingAttachmentLocationInfo;
    using api_element = schema::api_type::vulkan::VkRenderingAttachmentLocationInfo;

    VkRenderingAttachmentLocationInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pColorAttachmentLocations;
};

struct Decoded_VkRenderingInputAttachmentIndexInfo
{
    using struct_type = VkRenderingInputAttachmentIndexInfo;
    using api_element = schema::api_type::vulkan::VkRenderingInputAttachmentIndexInfo;

    VkRenderingInputAttachmentIndexInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pColorAttachmentInputIndices;
    PointerDecoder<uint32_t> pDepthInputAttachmentIndex;
    PointerDecoder<uint32_t> pStencilInputAttachmentIndex;
};

struct Decoded_VkSurfaceCapabilitiesKHR
{
    using struct_type = VkSurfaceCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkSurfaceCapabilitiesKHR;

    VkSurfaceCapabilitiesKHR* decoded_value{ nullptr };

    Decoded_VkExtent2D* currentExtent{ nullptr };
    Decoded_VkExtent2D* minImageExtent{ nullptr };
    Decoded_VkExtent2D* maxImageExtent{ nullptr };
};

struct Decoded_VkSurfaceFormatKHR
{
    using struct_type = VkSurfaceFormatKHR;
    using api_element = schema::api_type::vulkan::VkSurfaceFormatKHR;

    VkSurfaceFormatKHR* decoded_value{ nullptr };
};

struct Decoded_VkSwapchainCreateInfoKHR
{
    using struct_type = VkSwapchainCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkSwapchainCreateInfoKHR;

    VkSwapchainCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId surface{ format::kNullHandleId };
    Decoded_VkExtent2D* imageExtent{ nullptr };
    PointerDecoder<uint32_t> pQueueFamilyIndices;
    format::HandleId oldSwapchain{ format::kNullHandleId };
};

struct Decoded_VkPresentInfoKHR
{
    using struct_type = VkPresentInfoKHR;
    using api_element = schema::api_type::vulkan::VkPresentInfoKHR;

    VkPresentInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkSemaphore> pWaitSemaphores;
    HandlePointerDecoder<VkSwapchainKHR> pSwapchains;
    PointerDecoder<uint32_t> pImageIndices;
    PointerDecoder<VkResult> pResults;
};

struct Decoded_VkImageSwapchainCreateInfoKHR
{
    using struct_type = VkImageSwapchainCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkImageSwapchainCreateInfoKHR;

    VkImageSwapchainCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId swapchain{ format::kNullHandleId };
};

struct Decoded_VkBindImageMemorySwapchainInfoKHR
{
    using struct_type = VkBindImageMemorySwapchainInfoKHR;
    using api_element = schema::api_type::vulkan::VkBindImageMemorySwapchainInfoKHR;

    VkBindImageMemorySwapchainInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId swapchain{ format::kNullHandleId };
};

struct Decoded_VkAcquireNextImageInfoKHR
{
    using struct_type = VkAcquireNextImageInfoKHR;
    using api_element = schema::api_type::vulkan::VkAcquireNextImageInfoKHR;

    VkAcquireNextImageInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId swapchain{ format::kNullHandleId };
    format::HandleId semaphore{ format::kNullHandleId };
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkDeviceGroupPresentCapabilitiesKHR
{
    using struct_type = VkDeviceGroupPresentCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkDeviceGroupPresentCapabilitiesKHR;

    VkDeviceGroupPresentCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> presentMask;
};

struct Decoded_VkDeviceGroupPresentInfoKHR
{
    using struct_type = VkDeviceGroupPresentInfoKHR;
    using api_element = schema::api_type::vulkan::VkDeviceGroupPresentInfoKHR;

    VkDeviceGroupPresentInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pDeviceMasks;
};

struct Decoded_VkDeviceGroupSwapchainCreateInfoKHR
{
    using struct_type = VkDeviceGroupSwapchainCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkDeviceGroupSwapchainCreateInfoKHR;

    VkDeviceGroupSwapchainCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDisplayModeParametersKHR
{
    using struct_type = VkDisplayModeParametersKHR;
    using api_element = schema::api_type::vulkan::VkDisplayModeParametersKHR;

    VkDisplayModeParametersKHR* decoded_value{ nullptr };

    Decoded_VkExtent2D* visibleRegion{ nullptr };
};

struct Decoded_VkDisplayModeCreateInfoKHR
{
    using struct_type = VkDisplayModeCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkDisplayModeCreateInfoKHR;

    VkDisplayModeCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDisplayModeParametersKHR* parameters{ nullptr };
};

struct Decoded_VkDisplayModePropertiesKHR
{
    using struct_type = VkDisplayModePropertiesKHR;
    using api_element = schema::api_type::vulkan::VkDisplayModePropertiesKHR;

    VkDisplayModePropertiesKHR* decoded_value{ nullptr };

    format::HandleId displayMode{ format::kNullHandleId };
    Decoded_VkDisplayModeParametersKHR* parameters{ nullptr };
};

struct Decoded_VkDisplayPlaneCapabilitiesKHR
{
    using struct_type = VkDisplayPlaneCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkDisplayPlaneCapabilitiesKHR;

    VkDisplayPlaneCapabilitiesKHR* decoded_value{ nullptr };

    Decoded_VkOffset2D* minSrcPosition{ nullptr };
    Decoded_VkOffset2D* maxSrcPosition{ nullptr };
    Decoded_VkExtent2D* minSrcExtent{ nullptr };
    Decoded_VkExtent2D* maxSrcExtent{ nullptr };
    Decoded_VkOffset2D* minDstPosition{ nullptr };
    Decoded_VkOffset2D* maxDstPosition{ nullptr };
    Decoded_VkExtent2D* minDstExtent{ nullptr };
    Decoded_VkExtent2D* maxDstExtent{ nullptr };
};

struct Decoded_VkDisplayPlanePropertiesKHR
{
    using struct_type = VkDisplayPlanePropertiesKHR;
    using api_element = schema::api_type::vulkan::VkDisplayPlanePropertiesKHR;

    VkDisplayPlanePropertiesKHR* decoded_value{ nullptr };

    format::HandleId currentDisplay{ format::kNullHandleId };
};

struct Decoded_VkDisplayPropertiesKHR
{
    using struct_type = VkDisplayPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkDisplayPropertiesKHR;

    VkDisplayPropertiesKHR* decoded_value{ nullptr };

    format::HandleId display{ format::kNullHandleId };
    StringDecoder displayName;
    Decoded_VkExtent2D* physicalDimensions{ nullptr };
    Decoded_VkExtent2D* physicalResolution{ nullptr };
};

struct Decoded_VkDisplaySurfaceCreateInfoKHR
{
    using struct_type = VkDisplaySurfaceCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkDisplaySurfaceCreateInfoKHR;

    VkDisplaySurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId displayMode{ format::kNullHandleId };
    Decoded_VkExtent2D* imageExtent{ nullptr };
};

struct Decoded_VkDisplayPresentInfoKHR
{
    using struct_type = VkDisplayPresentInfoKHR;
    using api_element = schema::api_type::vulkan::VkDisplayPresentInfoKHR;

    VkDisplayPresentInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkRect2D* srcRect{ nullptr };
    Decoded_VkRect2D* dstRect{ nullptr };
};

struct Decoded_VkXlibSurfaceCreateInfoKHR
{
    using struct_type = VkXlibSurfaceCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkXlibSurfaceCreateInfoKHR;

    VkXlibSurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t dpy{ 0 };
};

struct Decoded_VkXcbSurfaceCreateInfoKHR
{
    using struct_type = VkXcbSurfaceCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkXcbSurfaceCreateInfoKHR;

    VkXcbSurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t connection{ 0 };
};

struct Decoded_VkWaylandSurfaceCreateInfoKHR
{
    using struct_type = VkWaylandSurfaceCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkWaylandSurfaceCreateInfoKHR;

    VkWaylandSurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t display{ 0 };
    uint64_t surface{ 0 };
};

struct Decoded_VkAndroidSurfaceCreateInfoKHR
{
    using struct_type = VkAndroidSurfaceCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkAndroidSurfaceCreateInfoKHR;

    VkAndroidSurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t window{ 0 };
};

struct Decoded_VkWin32SurfaceCreateInfoKHR
{
    using struct_type = VkWin32SurfaceCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkWin32SurfaceCreateInfoKHR;

    VkWin32SurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t hinstance{ 0 };
    uint64_t hwnd{ 0 };
};

struct Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR
{
    using struct_type = VkQueueFamilyQueryResultStatusPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkQueueFamilyQueryResultStatusPropertiesKHR;

    VkQueueFamilyQueryResultStatusPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyVideoPropertiesKHR
{
    using struct_type = VkQueueFamilyVideoPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkQueueFamilyVideoPropertiesKHR;

    VkQueueFamilyVideoPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoProfileInfoKHR
{
    using struct_type = VkVideoProfileInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoProfileInfoKHR;

    VkVideoProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoProfileListInfoKHR
{
    using struct_type = VkVideoProfileListInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoProfileListInfoKHR;

    VkVideoProfileListInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pProfiles{ nullptr };
};

struct Decoded_VkVideoCapabilitiesKHR
{
    using struct_type = VkVideoCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoCapabilitiesKHR;

    VkVideoCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* pictureAccessGranularity{ nullptr };
    Decoded_VkExtent2D* minCodedExtent{ nullptr };
    Decoded_VkExtent2D* maxCodedExtent{ nullptr };
    Decoded_VkExtensionProperties* stdHeaderVersion{ nullptr };
};

struct Decoded_VkPhysicalDeviceVideoFormatInfoKHR
{
    using struct_type = VkPhysicalDeviceVideoFormatInfoKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVideoFormatInfoKHR;

    VkPhysicalDeviceVideoFormatInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoFormatPropertiesKHR
{
    using struct_type = VkVideoFormatPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoFormatPropertiesKHR;

    VkVideoFormatPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkComponentMapping* componentMapping{ nullptr };
};

struct Decoded_VkVideoPictureResourceInfoKHR
{
    using struct_type = VkVideoPictureResourceInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoPictureResourceInfoKHR;

    VkVideoPictureResourceInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkOffset2D* codedOffset{ nullptr };
    Decoded_VkExtent2D* codedExtent{ nullptr };
    format::HandleId imageViewBinding{ format::kNullHandleId };
};

struct Decoded_VkVideoReferenceSlotInfoKHR
{
    using struct_type = VkVideoReferenceSlotInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoReferenceSlotInfoKHR;

    VkVideoReferenceSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoPictureResourceInfoKHR>* pPictureResource{ nullptr };
};

struct Decoded_VkVideoSessionMemoryRequirementsKHR
{
    using struct_type = VkVideoSessionMemoryRequirementsKHR;
    using api_element = schema::api_type::vulkan::VkVideoSessionMemoryRequirementsKHR;

    VkVideoSessionMemoryRequirementsKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkMemoryRequirements* memoryRequirements{ nullptr };
};

struct Decoded_VkBindVideoSessionMemoryInfoKHR
{
    using struct_type = VkBindVideoSessionMemoryInfoKHR;
    using api_element = schema::api_type::vulkan::VkBindVideoSessionMemoryInfoKHR;

    VkBindVideoSessionMemoryInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkVideoSessionCreateInfoKHR
{
    using struct_type = VkVideoSessionCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoSessionCreateInfoKHR;

    VkVideoSessionCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile{ nullptr };
    Decoded_VkExtent2D* maxCodedExtent{ nullptr };
    StructPointerDecoder<Decoded_VkExtensionProperties>* pStdHeaderVersion{ nullptr };
};

struct Decoded_VkVideoSessionParametersCreateInfoKHR
{
    using struct_type = VkVideoSessionParametersCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoSessionParametersCreateInfoKHR;

    VkVideoSessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId videoSessionParametersTemplate{ format::kNullHandleId };
    format::HandleId videoSession{ format::kNullHandleId };
};

struct Decoded_VkVideoSessionParametersUpdateInfoKHR
{
    using struct_type = VkVideoSessionParametersUpdateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoSessionParametersUpdateInfoKHR;

    VkVideoSessionParametersUpdateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoBeginCodingInfoKHR
{
    using struct_type = VkVideoBeginCodingInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoBeginCodingInfoKHR;

    VkVideoBeginCodingInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId videoSession{ format::kNullHandleId };
    format::HandleId videoSessionParameters{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkVideoReferenceSlotInfoKHR>* pReferenceSlots{ nullptr };
};

struct Decoded_VkVideoEndCodingInfoKHR
{
    using struct_type = VkVideoEndCodingInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEndCodingInfoKHR;

    VkVideoEndCodingInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoCodingControlInfoKHR
{
    using struct_type = VkVideoCodingControlInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoCodingControlInfoKHR;

    VkVideoCodingControlInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeCapabilitiesKHR
{
    using struct_type = VkVideoDecodeCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeCapabilitiesKHR;

    VkVideoDecodeCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeUsageInfoKHR
{
    using struct_type = VkVideoDecodeUsageInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeUsageInfoKHR;

    VkVideoDecodeUsageInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeInfoKHR
{
    using struct_type = VkVideoDecodeInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeInfoKHR;

    VkVideoDecodeInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcBuffer{ format::kNullHandleId };
    Decoded_VkVideoPictureResourceInfoKHR* dstPictureResource{ nullptr };
    StructPointerDecoder<Decoded_VkVideoReferenceSlotInfoKHR>* pSetupReferenceSlot{ nullptr };
    StructPointerDecoder<Decoded_VkVideoReferenceSlotInfoKHR>* pReferenceSlots{ nullptr };
};

struct Decoded_VkVideoEncodeH264CapabilitiesKHR
{
    using struct_type = VkVideoEncodeH264CapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264CapabilitiesKHR;

    VkVideoEncodeH264CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264QpKHR
{
    using struct_type = VkVideoEncodeH264QpKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264QpKHR;

    VkVideoEncodeH264QpKHR* decoded_value{ nullptr };
};

struct Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR
{
    using struct_type = VkVideoEncodeH264QualityLevelPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264QualityLevelPropertiesKHR;

    VkVideoEncodeH264QualityLevelPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkVideoEncodeH264QpKHR* preferredConstantQp{ nullptr };
};

struct Decoded_VkVideoEncodeH264SessionCreateInfoKHR
{
    using struct_type = VkVideoEncodeH264SessionCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264SessionCreateInfoKHR;

    VkVideoEncodeH264SessionCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR
{
    using struct_type = VkVideoEncodeH264SessionParametersAddInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264SessionParametersAddInfoKHR;

    VkVideoEncodeH264SessionParametersAddInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264SequenceParameterSet>* pStdSPSs{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264PictureParameterSet>* pStdPPSs{ nullptr };
};

struct Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR
{
    using struct_type = VkVideoEncodeH264SessionParametersCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264SessionParametersCreateInfoKHR;

    VkVideoEncodeH264SessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR>* pParametersAddInfo{ nullptr };
};

struct Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR
{
    using struct_type = VkVideoEncodeH264SessionParametersGetInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264SessionParametersGetInfoKHR;

    VkVideoEncodeH264SessionParametersGetInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR
{
    using struct_type = VkVideoEncodeH264SessionParametersFeedbackInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264SessionParametersFeedbackInfoKHR;

    VkVideoEncodeH264SessionParametersFeedbackInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264NaluSliceInfoKHR
{
    using struct_type = VkVideoEncodeH264NaluSliceInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264NaluSliceInfoKHR;

    VkVideoEncodeH264NaluSliceInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH264SliceHeader>* pStdSliceHeader{ nullptr };
};

struct Decoded_VkVideoEncodeH264PictureInfoKHR
{
    using struct_type = VkVideoEncodeH264PictureInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264PictureInfoKHR;

    VkVideoEncodeH264PictureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoEncodeH264NaluSliceInfoKHR>* pNaluSliceEntries{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH264PictureInfo>* pStdPictureInfo{ nullptr };
};

struct Decoded_VkVideoEncodeH264DpbSlotInfoKHR
{
    using struct_type = VkVideoEncodeH264DpbSlotInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264DpbSlotInfoKHR;

    VkVideoEncodeH264DpbSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH264ReferenceInfo>* pStdReferenceInfo{ nullptr };
};

struct Decoded_VkVideoEncodeH264ProfileInfoKHR
{
    using struct_type = VkVideoEncodeH264ProfileInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264ProfileInfoKHR;

    VkVideoEncodeH264ProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264RateControlInfoKHR
{
    using struct_type = VkVideoEncodeH264RateControlInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264RateControlInfoKHR;

    VkVideoEncodeH264RateControlInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264FrameSizeKHR
{
    using struct_type = VkVideoEncodeH264FrameSizeKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264FrameSizeKHR;

    VkVideoEncodeH264FrameSizeKHR* decoded_value{ nullptr };
};

struct Decoded_VkVideoEncodeH264RateControlLayerInfoKHR
{
    using struct_type = VkVideoEncodeH264RateControlLayerInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264RateControlLayerInfoKHR;

    VkVideoEncodeH264RateControlLayerInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkVideoEncodeH264QpKHR* minQp{ nullptr };
    Decoded_VkVideoEncodeH264QpKHR* maxQp{ nullptr };
    Decoded_VkVideoEncodeH264FrameSizeKHR* maxFrameSize{ nullptr };
};

struct Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR
{
    using struct_type = VkVideoEncodeH264GopRemainingFrameInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264GopRemainingFrameInfoKHR;

    VkVideoEncodeH264GopRemainingFrameInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeH264ProfileInfoKHR
{
    using struct_type = VkVideoDecodeH264ProfileInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeH264ProfileInfoKHR;

    VkVideoDecodeH264ProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeH264CapabilitiesKHR
{
    using struct_type = VkVideoDecodeH264CapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeH264CapabilitiesKHR;

    VkVideoDecodeH264CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkOffset2D* fieldOffsetGranularity{ nullptr };
};

struct Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR
{
    using struct_type = VkVideoDecodeH264SessionParametersAddInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeH264SessionParametersAddInfoKHR;

    VkVideoDecodeH264SessionParametersAddInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264SequenceParameterSet>* pStdSPSs{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264PictureParameterSet>* pStdPPSs{ nullptr };
};

struct Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR
{
    using struct_type = VkVideoDecodeH264SessionParametersCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeH264SessionParametersCreateInfoKHR;

    VkVideoDecodeH264SessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR>* pParametersAddInfo{ nullptr };
};

struct Decoded_VkVideoDecodeH264PictureInfoKHR
{
    using struct_type = VkVideoDecodeH264PictureInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeH264PictureInfoKHR;

    VkVideoDecodeH264PictureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoDecodeH264PictureInfo>* pStdPictureInfo{ nullptr };
    PointerDecoder<uint32_t> pSliceOffsets;
};

struct Decoded_VkVideoDecodeH264DpbSlotInfoKHR
{
    using struct_type = VkVideoDecodeH264DpbSlotInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeH264DpbSlotInfoKHR;

    VkVideoDecodeH264DpbSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoDecodeH264ReferenceInfo>* pStdReferenceInfo{ nullptr };
};

struct Decoded_VkImportMemoryWin32HandleInfoKHR
{
    using struct_type = VkImportMemoryWin32HandleInfoKHR;
    using api_element = schema::api_type::vulkan::VkImportMemoryWin32HandleInfoKHR;

    VkImportMemoryWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportMemoryWin32HandleInfoKHR
{
    using struct_type = VkExportMemoryWin32HandleInfoKHR;
    using api_element = schema::api_type::vulkan::VkExportMemoryWin32HandleInfoKHR;

    VkExportMemoryWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>* pAttributes{ nullptr };
    WStringDecoder name;
};

struct Decoded_VkMemoryWin32HandlePropertiesKHR
{
    using struct_type = VkMemoryWin32HandlePropertiesKHR;
    using api_element = schema::api_type::vulkan::VkMemoryWin32HandlePropertiesKHR;

    VkMemoryWin32HandlePropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryGetWin32HandleInfoKHR
{
    using struct_type = VkMemoryGetWin32HandleInfoKHR;
    using api_element = schema::api_type::vulkan::VkMemoryGetWin32HandleInfoKHR;

    VkMemoryGetWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkImportMemoryFdInfoKHR
{
    using struct_type = VkImportMemoryFdInfoKHR;
    using api_element = schema::api_type::vulkan::VkImportMemoryFdInfoKHR;

    VkImportMemoryFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryFdPropertiesKHR
{
    using struct_type = VkMemoryFdPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkMemoryFdPropertiesKHR;

    VkMemoryFdPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryGetFdInfoKHR
{
    using struct_type = VkMemoryGetFdInfoKHR;
    using api_element = schema::api_type::vulkan::VkMemoryGetFdInfoKHR;

    VkMemoryGetFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR
{
    using struct_type = VkWin32KeyedMutexAcquireReleaseInfoKHR;
    using api_element = schema::api_type::vulkan::VkWin32KeyedMutexAcquireReleaseInfoKHR;

    VkWin32KeyedMutexAcquireReleaseInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkDeviceMemory> pAcquireSyncs;
    PointerDecoder<uint64_t> pAcquireKeys;
    PointerDecoder<uint32_t> pAcquireTimeouts;
    HandlePointerDecoder<VkDeviceMemory> pReleaseSyncs;
    PointerDecoder<uint64_t> pReleaseKeys;
};

struct Decoded_VkImportSemaphoreWin32HandleInfoKHR
{
    using struct_type = VkImportSemaphoreWin32HandleInfoKHR;
    using api_element = schema::api_type::vulkan::VkImportSemaphoreWin32HandleInfoKHR;

    VkImportSemaphoreWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportSemaphoreWin32HandleInfoKHR
{
    using struct_type = VkExportSemaphoreWin32HandleInfoKHR;
    using api_element = schema::api_type::vulkan::VkExportSemaphoreWin32HandleInfoKHR;

    VkExportSemaphoreWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>* pAttributes{ nullptr };
    WStringDecoder name;
};

struct Decoded_VkD3D12FenceSubmitInfoKHR
{
    using struct_type = VkD3D12FenceSubmitInfoKHR;
    using api_element = schema::api_type::vulkan::VkD3D12FenceSubmitInfoKHR;

    VkD3D12FenceSubmitInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint64_t> pWaitSemaphoreValues;
    PointerDecoder<uint64_t> pSignalSemaphoreValues;
};

struct Decoded_VkSemaphoreGetWin32HandleInfoKHR
{
    using struct_type = VkSemaphoreGetWin32HandleInfoKHR;
    using api_element = schema::api_type::vulkan::VkSemaphoreGetWin32HandleInfoKHR;

    VkSemaphoreGetWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkImportSemaphoreFdInfoKHR
{
    using struct_type = VkImportSemaphoreFdInfoKHR;
    using api_element = schema::api_type::vulkan::VkImportSemaphoreFdInfoKHR;

    VkImportSemaphoreFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkSemaphoreGetFdInfoKHR
{
    using struct_type = VkSemaphoreGetFdInfoKHR;
    using api_element = schema::api_type::vulkan::VkSemaphoreGetFdInfoKHR;

    VkSemaphoreGetFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkRectLayerKHR
{
    using struct_type = VkRectLayerKHR;
    using api_element = schema::api_type::vulkan::VkRectLayerKHR;

    VkRectLayerKHR* decoded_value{ nullptr };

    Decoded_VkOffset2D* offset{ nullptr };
    Decoded_VkExtent2D* extent{ nullptr };
};

struct Decoded_VkPresentRegionKHR
{
    using struct_type = VkPresentRegionKHR;
    using api_element = schema::api_type::vulkan::VkPresentRegionKHR;

    VkPresentRegionKHR* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkRectLayerKHR>* pRectangles{ nullptr };
};

struct Decoded_VkPresentRegionsKHR
{
    using struct_type = VkPresentRegionsKHR;
    using api_element = schema::api_type::vulkan::VkPresentRegionsKHR;

    VkPresentRegionsKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPresentRegionKHR>* pRegions{ nullptr };
};

struct Decoded_VkSharedPresentSurfaceCapabilitiesKHR
{
    using struct_type = VkSharedPresentSurfaceCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkSharedPresentSurfaceCapabilitiesKHR;

    VkSharedPresentSurfaceCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImportFenceWin32HandleInfoKHR
{
    using struct_type = VkImportFenceWin32HandleInfoKHR;
    using api_element = schema::api_type::vulkan::VkImportFenceWin32HandleInfoKHR;

    VkImportFenceWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId fence{ format::kNullHandleId };
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportFenceWin32HandleInfoKHR
{
    using struct_type = VkExportFenceWin32HandleInfoKHR;
    using api_element = schema::api_type::vulkan::VkExportFenceWin32HandleInfoKHR;

    VkExportFenceWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>* pAttributes{ nullptr };
    WStringDecoder name;
};

struct Decoded_VkFenceGetWin32HandleInfoKHR
{
    using struct_type = VkFenceGetWin32HandleInfoKHR;
    using api_element = schema::api_type::vulkan::VkFenceGetWin32HandleInfoKHR;

    VkFenceGetWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkImportFenceFdInfoKHR
{
    using struct_type = VkImportFenceFdInfoKHR;
    using api_element = schema::api_type::vulkan::VkImportFenceFdInfoKHR;

    VkImportFenceFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkFenceGetFdInfoKHR
{
    using struct_type = VkFenceGetFdInfoKHR;
    using api_element = schema::api_type::vulkan::VkFenceGetFdInfoKHR;

    VkFenceGetFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR
{
    using struct_type = VkPhysicalDevicePerformanceQueryFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePerformanceQueryFeaturesKHR;

    VkPhysicalDevicePerformanceQueryFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR
{
    using struct_type = VkPhysicalDevicePerformanceQueryPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePerformanceQueryPropertiesKHR;

    VkPhysicalDevicePerformanceQueryPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceCounterKHR
{
    using struct_type = VkPerformanceCounterKHR;
    using api_element = schema::api_type::vulkan::VkPerformanceCounterKHR;

    VkPerformanceCounterKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> uuid;
};

struct Decoded_VkPerformanceCounterDescriptionKHR
{
    using struct_type = VkPerformanceCounterDescriptionKHR;
    using api_element = schema::api_type::vulkan::VkPerformanceCounterDescriptionKHR;

    VkPerformanceCounterDescriptionKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
    StringDecoder category;
    StringDecoder description;
};

struct Decoded_VkQueryPoolPerformanceCreateInfoKHR
{
    using struct_type = VkQueryPoolPerformanceCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkQueryPoolPerformanceCreateInfoKHR;

    VkQueryPoolPerformanceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pCounterIndices;
};

struct Decoded_VkAcquireProfilingLockInfoKHR
{
    using struct_type = VkAcquireProfilingLockInfoKHR;
    using api_element = schema::api_type::vulkan::VkAcquireProfilingLockInfoKHR;

    VkAcquireProfilingLockInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceQuerySubmitInfoKHR
{
    using struct_type = VkPerformanceQuerySubmitInfoKHR;
    using api_element = schema::api_type::vulkan::VkPerformanceQuerySubmitInfoKHR;

    VkPerformanceQuerySubmitInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSurfaceInfo2KHR
{
    using struct_type = VkPhysicalDeviceSurfaceInfo2KHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSurfaceInfo2KHR;

    VkPhysicalDeviceSurfaceInfo2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId surface{ format::kNullHandleId };
};

struct Decoded_VkSurfaceCapabilities2KHR
{
    using struct_type = VkSurfaceCapabilities2KHR;
    using api_element = schema::api_type::vulkan::VkSurfaceCapabilities2KHR;

    VkSurfaceCapabilities2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSurfaceCapabilitiesKHR* surfaceCapabilities{ nullptr };
};

struct Decoded_VkSurfaceFormat2KHR
{
    using struct_type = VkSurfaceFormat2KHR;
    using api_element = schema::api_type::vulkan::VkSurfaceFormat2KHR;

    VkSurfaceFormat2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSurfaceFormatKHR* surfaceFormat{ nullptr };
};

struct Decoded_VkDisplayProperties2KHR
{
    using struct_type = VkDisplayProperties2KHR;
    using api_element = schema::api_type::vulkan::VkDisplayProperties2KHR;

    VkDisplayProperties2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDisplayPropertiesKHR* displayProperties{ nullptr };
};

struct Decoded_VkDisplayPlaneProperties2KHR
{
    using struct_type = VkDisplayPlaneProperties2KHR;
    using api_element = schema::api_type::vulkan::VkDisplayPlaneProperties2KHR;

    VkDisplayPlaneProperties2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDisplayPlanePropertiesKHR* displayPlaneProperties{ nullptr };
};

struct Decoded_VkDisplayModeProperties2KHR
{
    using struct_type = VkDisplayModeProperties2KHR;
    using api_element = schema::api_type::vulkan::VkDisplayModeProperties2KHR;

    VkDisplayModeProperties2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDisplayModePropertiesKHR* displayModeProperties{ nullptr };
};

struct Decoded_VkDisplayPlaneInfo2KHR
{
    using struct_type = VkDisplayPlaneInfo2KHR;
    using api_element = schema::api_type::vulkan::VkDisplayPlaneInfo2KHR;

    VkDisplayPlaneInfo2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId mode{ format::kNullHandleId };
};

struct Decoded_VkDisplayPlaneCapabilities2KHR
{
    using struct_type = VkDisplayPlaneCapabilities2KHR;
    using api_element = schema::api_type::vulkan::VkDisplayPlaneCapabilities2KHR;

    VkDisplayPlaneCapabilities2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDisplayPlaneCapabilitiesKHR* capabilities{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderBfloat16FeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderBfloat16FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderBfloat16FeaturesKHR;

    VkPhysicalDeviceShaderBfloat16FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR
{
    using struct_type = VkPhysicalDevicePortabilitySubsetFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePortabilitySubsetFeaturesKHR;

    VkPhysicalDevicePortabilitySubsetFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR
{
    using struct_type = VkPhysicalDevicePortabilitySubsetPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePortabilitySubsetPropertiesKHR;

    VkPhysicalDevicePortabilitySubsetPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderClockFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderClockFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderClockFeaturesKHR;

    VkPhysicalDeviceShaderClockFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFragmentShadingRateAttachmentInfoKHR
{
    using struct_type = VkFragmentShadingRateAttachmentInfoKHR;
    using api_element = schema::api_type::vulkan::VkFragmentShadingRateAttachmentInfoKHR;

    VkFragmentShadingRateAttachmentInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference2>* pFragmentShadingRateAttachment{ nullptr };
    Decoded_VkExtent2D* shadingRateAttachmentTexelSize{ nullptr };
};

struct Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR
{
    using struct_type = VkPipelineFragmentShadingRateStateCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkPipelineFragmentShadingRateStateCreateInfoKHR;

    VkPipelineFragmentShadingRateStateCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* fragmentSize{ nullptr };
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;
};

struct Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR
{
    using struct_type = VkPhysicalDeviceFragmentShadingRateFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentShadingRateFeaturesKHR;

    VkPhysicalDeviceFragmentShadingRateFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR
{
    using struct_type = VkPhysicalDeviceFragmentShadingRatePropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentShadingRatePropertiesKHR;

    VkPhysicalDeviceFragmentShadingRatePropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* minFragmentShadingRateAttachmentTexelSize{ nullptr };
    Decoded_VkExtent2D* maxFragmentShadingRateAttachmentTexelSize{ nullptr };
    Decoded_VkExtent2D* maxFragmentSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShadingRateKHR
{
    using struct_type = VkPhysicalDeviceFragmentShadingRateKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentShadingRateKHR;

    VkPhysicalDeviceFragmentShadingRateKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* fragmentSize{ nullptr };
};

struct Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR
{
    using struct_type = VkRenderingFragmentShadingRateAttachmentInfoKHR;
    using api_element = schema::api_type::vulkan::VkRenderingFragmentShadingRateAttachmentInfoKHR;

    VkRenderingFragmentShadingRateAttachmentInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId imageView{ format::kNullHandleId };
    Decoded_VkExtent2D* shadingRateAttachmentTexelSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderConstantDataFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderConstantDataFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderConstantDataFeaturesKHR;

    VkPhysicalDeviceShaderConstantDataFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderAbortFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderAbortFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderAbortFeaturesKHR;

    VkPhysicalDeviceShaderAbortFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceFaultShaderAbortMessageInfoKHR
{
    using struct_type = VkDeviceFaultShaderAbortMessageInfoKHR;
    using api_element = schema::api_type::vulkan::VkDeviceFaultShaderAbortMessageInfoKHR;

    VkDeviceFaultShaderAbortMessageInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pMessageData;
};

struct Decoded_VkPhysicalDeviceShaderAbortPropertiesKHR
{
    using struct_type = VkPhysicalDeviceShaderAbortPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderAbortPropertiesKHR;

    VkPhysicalDeviceShaderAbortPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderQuadControlFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderQuadControlFeaturesKHR;

    VkPhysicalDeviceShaderQuadControlFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceProtectedCapabilitiesKHR
{
    using struct_type = VkSurfaceProtectedCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkSurfaceProtectedCapabilitiesKHR;

    VkSurfaceProtectedCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePresentWaitFeaturesKHR
{
    using struct_type = VkPhysicalDevicePresentWaitFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePresentWaitFeaturesKHR;

    VkPhysicalDevicePresentWaitFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR
{
    using struct_type = VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR;

    VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineInfoKHR
{
    using struct_type = VkPipelineInfoKHR;
    using api_element = schema::api_type::vulkan::VkPipelineInfoKHR;

    VkPipelineInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkPipelineExecutablePropertiesKHR
{
    using struct_type = VkPipelineExecutablePropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPipelineExecutablePropertiesKHR;

    VkPipelineExecutablePropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
    StringDecoder description;
};

struct Decoded_VkPipelineExecutableInfoKHR
{
    using struct_type = VkPipelineExecutableInfoKHR;
    using api_element = schema::api_type::vulkan::VkPipelineExecutableInfoKHR;

    VkPipelineExecutableInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkPipelineExecutableStatisticKHR
{
    using struct_type = VkPipelineExecutableStatisticKHR;
    using api_element = schema::api_type::vulkan::VkPipelineExecutableStatisticKHR;

    VkPipelineExecutableStatisticKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
    StringDecoder description;
    Decoded_VkPipelineExecutableStatisticValueKHR* value{ nullptr };
};

struct Decoded_VkPipelineExecutableInternalRepresentationKHR
{
    using struct_type = VkPipelineExecutableInternalRepresentationKHR;
    using api_element = schema::api_type::vulkan::VkPipelineExecutableInternalRepresentationKHR;

    VkPipelineExecutableInternalRepresentationKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
    StringDecoder description;
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkPipelineLibraryCreateInfoKHR
{
    using struct_type = VkPipelineLibraryCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkPipelineLibraryCreateInfoKHR;

    VkPipelineLibraryCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkPipeline> pLibraries;
};

struct Decoded_VkPresentIdKHR
{
    using struct_type = VkPresentIdKHR;
    using api_element = schema::api_type::vulkan::VkPresentIdKHR;

    VkPresentIdKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint64_t> pPresentIds;
};

struct Decoded_VkPhysicalDevicePresentIdFeaturesKHR
{
    using struct_type = VkPhysicalDevicePresentIdFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePresentIdFeaturesKHR;

    VkPhysicalDevicePresentIdFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeInfoKHR
{
    using struct_type = VkVideoEncodeInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeInfoKHR;

    VkVideoEncodeInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId dstBuffer{ format::kNullHandleId };
    Decoded_VkVideoPictureResourceInfoKHR* srcPictureResource{ nullptr };
    StructPointerDecoder<Decoded_VkVideoReferenceSlotInfoKHR>* pSetupReferenceSlot{ nullptr };
    StructPointerDecoder<Decoded_VkVideoReferenceSlotInfoKHR>* pReferenceSlots{ nullptr };
};

struct Decoded_VkVideoEncodeCapabilitiesKHR
{
    using struct_type = VkVideoEncodeCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeCapabilitiesKHR;

    VkVideoEncodeCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* encodeInputPictureGranularity{ nullptr };
};

struct Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR
{
    using struct_type = VkQueryPoolVideoEncodeFeedbackCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkQueryPoolVideoEncodeFeedbackCreateInfoKHR;

    VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeUsageInfoKHR
{
    using struct_type = VkVideoEncodeUsageInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeUsageInfoKHR;

    VkVideoEncodeUsageInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeRateControlLayerInfoKHR
{
    using struct_type = VkVideoEncodeRateControlLayerInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeRateControlLayerInfoKHR;

    VkVideoEncodeRateControlLayerInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeRateControlInfoKHR
{
    using struct_type = VkVideoEncodeRateControlInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeRateControlInfoKHR;

    VkVideoEncodeRateControlInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoEncodeRateControlLayerInfoKHR>* pLayers{ nullptr };
};

struct Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR
{
    using struct_type = VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR;

    VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile{ nullptr };
};

struct Decoded_VkVideoEncodeQualityLevelPropertiesKHR
{
    using struct_type = VkVideoEncodeQualityLevelPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeQualityLevelPropertiesKHR;

    VkVideoEncodeQualityLevelPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeQualityLevelInfoKHR
{
    using struct_type = VkVideoEncodeQualityLevelInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeQualityLevelInfoKHR;

    VkVideoEncodeQualityLevelInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeSessionParametersGetInfoKHR
{
    using struct_type = VkVideoEncodeSessionParametersGetInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeSessionParametersGetInfoKHR;

    VkVideoEncodeSessionParametersGetInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId videoSessionParameters{ format::kNullHandleId };
};

struct Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR
{
    using struct_type = VkVideoEncodeSessionParametersFeedbackInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeSessionParametersFeedbackInfoKHR;

    VkVideoEncodeSessionParametersFeedbackInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceAddressRangeKHR
{
    using struct_type = VkDeviceAddressRangeKHR;
    using api_element = schema::api_type::vulkan::VkDeviceAddressRangeKHR;

    VkDeviceAddressRangeKHR* decoded_value{ nullptr };
};

struct Decoded_VkStridedDeviceAddressRangeKHR
{
    using struct_type = VkStridedDeviceAddressRangeKHR;
    using api_element = schema::api_type::vulkan::VkStridedDeviceAddressRangeKHR;

    VkStridedDeviceAddressRangeKHR* decoded_value{ nullptr };
};

struct Decoded_VkDeviceMemoryCopyKHR
{
    using struct_type = VkDeviceMemoryCopyKHR;
    using api_element = schema::api_type::vulkan::VkDeviceMemoryCopyKHR;

    VkDeviceMemoryCopyKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* srcRange{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* dstRange{ nullptr };
};

struct Decoded_VkCopyDeviceMemoryInfoKHR
{
    using struct_type = VkCopyDeviceMemoryInfoKHR;
    using api_element = schema::api_type::vulkan::VkCopyDeviceMemoryInfoKHR;

    VkCopyDeviceMemoryInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDeviceMemoryCopyKHR>* pRegions{ nullptr };
};

struct Decoded_VkDeviceMemoryImageCopyKHR
{
    using struct_type = VkDeviceMemoryImageCopyKHR;
    using api_element = schema::api_type::vulkan::VkDeviceMemoryImageCopyKHR;

    VkDeviceMemoryImageCopyKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* addressRange{ nullptr };
    Decoded_VkImageSubresourceLayers* imageSubresource{ nullptr };
    Decoded_VkOffset3D* imageOffset{ nullptr };
    Decoded_VkExtent3D* imageExtent{ nullptr };
};

struct Decoded_VkCopyDeviceMemoryImageInfoKHR
{
    using struct_type = VkCopyDeviceMemoryImageInfoKHR;
    using api_element = schema::api_type::vulkan::VkCopyDeviceMemoryImageInfoKHR;

    VkCopyDeviceMemoryImageInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkDeviceMemoryImageCopyKHR>* pRegions{ nullptr };
};

struct Decoded_VkMemoryRangeBarrierKHR
{
    using struct_type = VkMemoryRangeBarrierKHR;
    using api_element = schema::api_type::vulkan::VkMemoryRangeBarrierKHR;

    VkMemoryRangeBarrierKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* addressRange{ nullptr };
};

struct Decoded_VkMemoryRangeBarriersInfoKHR
{
    using struct_type = VkMemoryRangeBarriersInfoKHR;
    using api_element = schema::api_type::vulkan::VkMemoryRangeBarriersInfoKHR;

    VkMemoryRangeBarriersInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkMemoryRangeBarrierKHR>* pMemoryRangeBarriers{ nullptr };
};

struct Decoded_VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR
{
    using struct_type = VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR;

    VkPhysicalDeviceDeviceAddressCommandsFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBindIndexBuffer3InfoKHR
{
    using struct_type = VkBindIndexBuffer3InfoKHR;
    using api_element = schema::api_type::vulkan::VkBindIndexBuffer3InfoKHR;

    VkBindIndexBuffer3InfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* addressRange{ nullptr };
};

struct Decoded_VkBindVertexBuffer3InfoKHR
{
    using struct_type = VkBindVertexBuffer3InfoKHR;
    using api_element = schema::api_type::vulkan::VkBindVertexBuffer3InfoKHR;

    VkBindVertexBuffer3InfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkStridedDeviceAddressRangeKHR* addressRange{ nullptr };
};

struct Decoded_VkDrawIndirect2InfoKHR
{
    using struct_type = VkDrawIndirect2InfoKHR;
    using api_element = schema::api_type::vulkan::VkDrawIndirect2InfoKHR;

    VkDrawIndirect2InfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkStridedDeviceAddressRangeKHR* addressRange{ nullptr };
};

struct Decoded_VkDrawIndirectCount2InfoKHR
{
    using struct_type = VkDrawIndirectCount2InfoKHR;
    using api_element = schema::api_type::vulkan::VkDrawIndirectCount2InfoKHR;

    VkDrawIndirectCount2InfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkStridedDeviceAddressRangeKHR* addressRange{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* countAddressRange{ nullptr };
};

struct Decoded_VkDispatchIndirect2InfoKHR
{
    using struct_type = VkDispatchIndirect2InfoKHR;
    using api_element = schema::api_type::vulkan::VkDispatchIndirect2InfoKHR;

    VkDispatchIndirect2InfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* addressRange{ nullptr };
};

struct Decoded_VkConditionalRenderingBeginInfo2EXT
{
    using struct_type = VkConditionalRenderingBeginInfo2EXT;
    using api_element = schema::api_type::vulkan::VkConditionalRenderingBeginInfo2EXT;

    VkConditionalRenderingBeginInfo2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* addressRange{ nullptr };
};

struct Decoded_VkBindTransformFeedbackBuffer2InfoEXT
{
    using struct_type = VkBindTransformFeedbackBuffer2InfoEXT;
    using api_element = schema::api_type::vulkan::VkBindTransformFeedbackBuffer2InfoEXT;

    VkBindTransformFeedbackBuffer2InfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* addressRange{ nullptr };
};

struct Decoded_VkMemoryMarkerInfoAMD
{
    using struct_type = VkMemoryMarkerInfoAMD;
    using api_element = schema::api_type::vulkan::VkMemoryMarkerInfoAMD;

    VkMemoryMarkerInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* dstRange{ nullptr };
};

struct Decoded_VkAccelerationStructureCreateInfo2KHR
{
    using struct_type = VkAccelerationStructureCreateInfo2KHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureCreateInfo2KHR;

    VkAccelerationStructureCreateInfo2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceAddressRangeKHR* addressRange{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR
{
    using struct_type = VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR;

    VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR
{
    using struct_type = VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR;

    VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR;

    VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR
{
    using struct_type = VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR;

    VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR
{
    using struct_type = VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR;

    VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTraceRaysIndirectCommand2KHR
{
    using struct_type = VkTraceRaysIndirectCommand2KHR;
    using api_element = schema::api_type::vulkan::VkTraceRaysIndirectCommand2KHR;

    VkTraceRaysIndirectCommand2KHR* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderUntypedPointersFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderUntypedPointersFeaturesKHR;

    VkPhysicalDeviceShaderUntypedPointersFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR;

    VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceCapabilitiesPresentId2KHR
{
    using struct_type = VkSurfaceCapabilitiesPresentId2KHR;
    using api_element = schema::api_type::vulkan::VkSurfaceCapabilitiesPresentId2KHR;

    VkSurfaceCapabilitiesPresentId2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPresentId2KHR
{
    using struct_type = VkPresentId2KHR;
    using api_element = schema::api_type::vulkan::VkPresentId2KHR;

    VkPresentId2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint64_t> pPresentIds;
};

struct Decoded_VkPhysicalDevicePresentId2FeaturesKHR
{
    using struct_type = VkPhysicalDevicePresentId2FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePresentId2FeaturesKHR;

    VkPhysicalDevicePresentId2FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceCapabilitiesPresentWait2KHR
{
    using struct_type = VkSurfaceCapabilitiesPresentWait2KHR;
    using api_element = schema::api_type::vulkan::VkSurfaceCapabilitiesPresentWait2KHR;

    VkSurfaceCapabilitiesPresentWait2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePresentWait2FeaturesKHR
{
    using struct_type = VkPhysicalDevicePresentWait2FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePresentWait2FeaturesKHR;

    VkPhysicalDevicePresentWait2FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPresentWait2InfoKHR
{
    using struct_type = VkPresentWait2InfoKHR;
    using api_element = schema::api_type::vulkan::VkPresentWait2InfoKHR;

    VkPresentWait2InfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR
{
    using struct_type = VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR;

    VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineBinaryFeaturesKHR
{
    using struct_type = VkPhysicalDevicePipelineBinaryFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePipelineBinaryFeaturesKHR;

    VkPhysicalDevicePipelineBinaryFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineBinaryPropertiesKHR
{
    using struct_type = VkPhysicalDevicePipelineBinaryPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePipelineBinaryPropertiesKHR;

    VkPhysicalDevicePipelineBinaryPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDevicePipelineBinaryInternalCacheControlKHR
{
    using struct_type = VkDevicePipelineBinaryInternalCacheControlKHR;
    using api_element = schema::api_type::vulkan::VkDevicePipelineBinaryInternalCacheControlKHR;

    VkDevicePipelineBinaryInternalCacheControlKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineBinaryKeyKHR
{
    using struct_type = VkPipelineBinaryKeyKHR;
    using api_element = schema::api_type::vulkan::VkPipelineBinaryKeyKHR;

    VkPipelineBinaryKeyKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> key;
};

struct Decoded_VkPipelineBinaryDataKHR
{
    using struct_type = VkPipelineBinaryDataKHR;
    using api_element = schema::api_type::vulkan::VkPipelineBinaryDataKHR;

    VkPipelineBinaryDataKHR* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkPipelineBinaryKeysAndDataKHR
{
    using struct_type = VkPipelineBinaryKeysAndDataKHR;
    using api_element = schema::api_type::vulkan::VkPipelineBinaryKeysAndDataKHR;

    VkPipelineBinaryKeysAndDataKHR* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkPipelineBinaryKeyKHR>* pPipelineBinaryKeys{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineBinaryDataKHR>* pPipelineBinaryData{ nullptr };
};

struct Decoded_VkPipelineCreateInfoKHR
{
    using struct_type = VkPipelineCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkPipelineCreateInfoKHR;

    VkPipelineCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineBinaryCreateInfoKHR
{
    using struct_type = VkPipelineBinaryCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkPipelineBinaryCreateInfoKHR;

    VkPipelineBinaryCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineBinaryKeysAndDataKHR>* pKeysAndDataInfo{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkPipelineCreateInfoKHR>* pPipelineCreateInfo{ nullptr };
};

struct Decoded_VkPipelineBinaryInfoKHR
{
    using struct_type = VkPipelineBinaryInfoKHR;
    using api_element = schema::api_type::vulkan::VkPipelineBinaryInfoKHR;

    VkPipelineBinaryInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkPipelineBinaryKHR> pPipelineBinaries;
};

struct Decoded_VkReleaseCapturedPipelineDataInfoKHR
{
    using struct_type = VkReleaseCapturedPipelineDataInfoKHR;
    using api_element = schema::api_type::vulkan::VkReleaseCapturedPipelineDataInfoKHR;

    VkReleaseCapturedPipelineDataInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkPipelineBinaryDataInfoKHR
{
    using struct_type = VkPipelineBinaryDataInfoKHR;
    using api_element = schema::api_type::vulkan::VkPipelineBinaryDataInfoKHR;

    VkPipelineBinaryDataInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipelineBinary{ format::kNullHandleId };
};

struct Decoded_VkPipelineBinaryHandlesInfoKHR
{
    using struct_type = VkPipelineBinaryHandlesInfoKHR;
    using api_element = schema::api_type::vulkan::VkPipelineBinaryHandlesInfoKHR;

    VkPipelineBinaryHandlesInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkPipelineBinaryKHR> pPipelineBinaries;
};

struct Decoded_VkSurfacePresentModeKHR
{
    using struct_type = VkSurfacePresentModeKHR;
    using api_element = schema::api_type::vulkan::VkSurfacePresentModeKHR;

    VkSurfacePresentModeKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfacePresentScalingCapabilitiesKHR
{
    using struct_type = VkSurfacePresentScalingCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkSurfacePresentScalingCapabilitiesKHR;

    VkSurfacePresentScalingCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* minScaledImageExtent{ nullptr };
    Decoded_VkExtent2D* maxScaledImageExtent{ nullptr };
};

struct Decoded_VkSurfacePresentModeCompatibilityKHR
{
    using struct_type = VkSurfacePresentModeCompatibilityKHR;
    using api_element = schema::api_type::vulkan::VkSurfacePresentModeCompatibilityKHR;

    VkSurfacePresentModeCompatibilityKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkPresentModeKHR> pPresentModes;
};

struct Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR
{
    using struct_type = VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR;

    VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainPresentFenceInfoKHR
{
    using struct_type = VkSwapchainPresentFenceInfoKHR;
    using api_element = schema::api_type::vulkan::VkSwapchainPresentFenceInfoKHR;

    VkSwapchainPresentFenceInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkFence> pFences;
};

struct Decoded_VkSwapchainPresentModesCreateInfoKHR
{
    using struct_type = VkSwapchainPresentModesCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkSwapchainPresentModesCreateInfoKHR;

    VkSwapchainPresentModesCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkPresentModeKHR> pPresentModes;
};

struct Decoded_VkSwapchainPresentModeInfoKHR
{
    using struct_type = VkSwapchainPresentModeInfoKHR;
    using api_element = schema::api_type::vulkan::VkSwapchainPresentModeInfoKHR;

    VkSwapchainPresentModeInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkPresentModeKHR> pPresentModes;
};

struct Decoded_VkSwapchainPresentScalingCreateInfoKHR
{
    using struct_type = VkSwapchainPresentScalingCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkSwapchainPresentScalingCreateInfoKHR;

    VkSwapchainPresentScalingCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkReleaseSwapchainImagesInfoKHR
{
    using struct_type = VkReleaseSwapchainImagesInfoKHR;
    using api_element = schema::api_type::vulkan::VkReleaseSwapchainImagesInfoKHR;

    VkReleaseSwapchainImagesInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId swapchain{ format::kNullHandleId };
    PointerDecoder<uint32_t> pImageIndices;
};

struct Decoded_VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR
{
    using struct_type = VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR;

    VkPhysicalDeviceInternallySynchronizedQueuesFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCooperativeMatrixPropertiesKHR
{
    using struct_type = VkCooperativeMatrixPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkCooperativeMatrixPropertiesKHR;

    VkCooperativeMatrixPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeMatrixFeaturesKHR;

    VkPhysicalDeviceCooperativeMatrixFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeMatrixPropertiesKHR;

    VkPhysicalDeviceCooperativeMatrixPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR
{
    using struct_type = VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR;

    VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR
{
    using struct_type = VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR;

    VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeAV1ProfileInfoKHR
{
    using struct_type = VkVideoDecodeAV1ProfileInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeAV1ProfileInfoKHR;

    VkVideoDecodeAV1ProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeAV1CapabilitiesKHR
{
    using struct_type = VkVideoDecodeAV1CapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeAV1CapabilitiesKHR;

    VkVideoDecodeAV1CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR
{
    using struct_type = VkVideoDecodeAV1SessionParametersCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeAV1SessionParametersCreateInfoKHR;

    VkVideoDecodeAV1SessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1SequenceHeader>* pStdSequenceHeader{ nullptr };
};

struct Decoded_VkVideoDecodeAV1PictureInfoKHR
{
    using struct_type = VkVideoDecodeAV1PictureInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeAV1PictureInfoKHR;

    VkVideoDecodeAV1PictureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoDecodeAV1PictureInfo>* pStdPictureInfo{ nullptr };
    PointerDecoder<int32_t> referenceNameSlotIndices;
    PointerDecoder<uint32_t> pTileOffsets;
    PointerDecoder<uint32_t> pTileSizes;
};

struct Decoded_VkVideoDecodeAV1DpbSlotInfoKHR
{
    using struct_type = VkVideoDecodeAV1DpbSlotInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeAV1DpbSlotInfoKHR;

    VkVideoDecodeAV1DpbSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoDecodeAV1ReferenceInfo>* pStdReferenceInfo{ nullptr };
};

struct Decoded_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR
{
    using struct_type = VkPhysicalDeviceVideoEncodeAV1FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVideoEncodeAV1FeaturesKHR;

    VkPhysicalDeviceVideoEncodeAV1FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeAV1CapabilitiesKHR
{
    using struct_type = VkVideoEncodeAV1CapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1CapabilitiesKHR;

    VkVideoEncodeAV1CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* codedPictureAlignment{ nullptr };
    Decoded_VkExtent2D* maxTiles{ nullptr };
    Decoded_VkExtent2D* minTileSize{ nullptr };
    Decoded_VkExtent2D* maxTileSize{ nullptr };
};

struct Decoded_VkVideoEncodeAV1QIndexKHR
{
    using struct_type = VkVideoEncodeAV1QIndexKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1QIndexKHR;

    VkVideoEncodeAV1QIndexKHR* decoded_value{ nullptr };
};

struct Decoded_VkVideoEncodeAV1QualityLevelPropertiesKHR
{
    using struct_type = VkVideoEncodeAV1QualityLevelPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1QualityLevelPropertiesKHR;

    VkVideoEncodeAV1QualityLevelPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkVideoEncodeAV1QIndexKHR* preferredConstantQIndex{ nullptr };
};

struct Decoded_VkVideoEncodeAV1SessionCreateInfoKHR
{
    using struct_type = VkVideoEncodeAV1SessionCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1SessionCreateInfoKHR;

    VkVideoEncodeAV1SessionCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeAV1SessionParametersCreateInfoKHR
{
    using struct_type = VkVideoEncodeAV1SessionParametersCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1SessionParametersCreateInfoKHR;

    VkVideoEncodeAV1SessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1SequenceHeader>* pStdSequenceHeader{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeAV1DecoderModelInfo>* pStdDecoderModelInfo{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeAV1OperatingPointInfo>* pStdOperatingPoints{ nullptr };
};

struct Decoded_VkVideoEncodeAV1PictureInfoKHR
{
    using struct_type = VkVideoEncodeAV1PictureInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1PictureInfoKHR;

    VkVideoEncodeAV1PictureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeAV1PictureInfo>* pStdPictureInfo{ nullptr };
    PointerDecoder<int32_t> referenceNameSlotIndices;
};

struct Decoded_VkVideoEncodeAV1DpbSlotInfoKHR
{
    using struct_type = VkVideoEncodeAV1DpbSlotInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1DpbSlotInfoKHR;

    VkVideoEncodeAV1DpbSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeAV1ReferenceInfo>* pStdReferenceInfo{ nullptr };
};

struct Decoded_VkVideoEncodeAV1ProfileInfoKHR
{
    using struct_type = VkVideoEncodeAV1ProfileInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1ProfileInfoKHR;

    VkVideoEncodeAV1ProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeAV1FrameSizeKHR
{
    using struct_type = VkVideoEncodeAV1FrameSizeKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1FrameSizeKHR;

    VkVideoEncodeAV1FrameSizeKHR* decoded_value{ nullptr };
};

struct Decoded_VkVideoEncodeAV1GopRemainingFrameInfoKHR
{
    using struct_type = VkVideoEncodeAV1GopRemainingFrameInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1GopRemainingFrameInfoKHR;

    VkVideoEncodeAV1GopRemainingFrameInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeAV1RateControlInfoKHR
{
    using struct_type = VkVideoEncodeAV1RateControlInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1RateControlInfoKHR;

    VkVideoEncodeAV1RateControlInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeAV1RateControlLayerInfoKHR
{
    using struct_type = VkVideoEncodeAV1RateControlLayerInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1RateControlLayerInfoKHR;

    VkVideoEncodeAV1RateControlLayerInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkVideoEncodeAV1QIndexKHR* minQIndex{ nullptr };
    Decoded_VkVideoEncodeAV1QIndexKHR* maxQIndex{ nullptr };
    Decoded_VkVideoEncodeAV1FrameSizeKHR* maxFrameSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR
{
    using struct_type = VkPhysicalDeviceVideoDecodeVP9FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVideoDecodeVP9FeaturesKHR;

    VkPhysicalDeviceVideoDecodeVP9FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeVP9ProfileInfoKHR
{
    using struct_type = VkVideoDecodeVP9ProfileInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeVP9ProfileInfoKHR;

    VkVideoDecodeVP9ProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeVP9CapabilitiesKHR
{
    using struct_type = VkVideoDecodeVP9CapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeVP9CapabilitiesKHR;

    VkVideoDecodeVP9CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeVP9PictureInfoKHR
{
    using struct_type = VkVideoDecodeVP9PictureInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoDecodeVP9PictureInfoKHR;

    VkVideoDecodeVP9PictureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoDecodeVP9PictureInfo>* pStdPictureInfo{ nullptr };
    PointerDecoder<int32_t> referenceNameSlotIndices;
};

struct Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR
{
    using struct_type = VkPhysicalDeviceVideoMaintenance1FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVideoMaintenance1FeaturesKHR;

    VkPhysicalDeviceVideoMaintenance1FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoInlineQueryInfoKHR
{
    using struct_type = VkVideoInlineQueryInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoInlineQueryInfoKHR;

    VkVideoInlineQueryInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId queryPool{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR
{
    using struct_type = VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR;

    VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAttachmentFeedbackLoopInfoEXT
{
    using struct_type = VkAttachmentFeedbackLoopInfoEXT;
    using api_element = schema::api_type::vulkan::VkAttachmentFeedbackLoopInfoEXT;

    VkAttachmentFeedbackLoopInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCalibratedTimestampInfoKHR
{
    using struct_type = VkCalibratedTimestampInfoKHR;
    using api_element = schema::api_type::vulkan::VkCalibratedTimestampInfoKHR;

    VkCalibratedTimestampInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSetDescriptorBufferOffsetsInfoEXT
{
    using struct_type = VkSetDescriptorBufferOffsetsInfoEXT;
    using api_element = schema::api_type::vulkan::VkSetDescriptorBufferOffsetsInfoEXT;

    VkSetDescriptorBufferOffsetsInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    PointerDecoder<uint32_t> pBufferIndices;
    PointerDecoder<VkDeviceSize> pOffsets;
};

struct Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT
{
    using struct_type = VkBindDescriptorBufferEmbeddedSamplersInfoEXT;
    using api_element = schema::api_type::vulkan::VkBindDescriptorBufferEmbeddedSamplersInfoEXT;

    VkBindDescriptorBufferEmbeddedSamplersInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
};

struct Decoded_VkCopyMemoryIndirectCommandKHR
{
    using struct_type = VkCopyMemoryIndirectCommandKHR;
    using api_element = schema::api_type::vulkan::VkCopyMemoryIndirectCommandKHR;

    VkCopyMemoryIndirectCommandKHR* decoded_value{ nullptr };
};

struct Decoded_VkCopyMemoryIndirectInfoKHR
{
    using struct_type = VkCopyMemoryIndirectInfoKHR;
    using api_element = schema::api_type::vulkan::VkCopyMemoryIndirectInfoKHR;

    VkCopyMemoryIndirectInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkStridedDeviceAddressRangeKHR* copyAddressRange{ nullptr };
};

struct Decoded_VkCopyMemoryToImageIndirectCommandKHR
{
    using struct_type = VkCopyMemoryToImageIndirectCommandKHR;
    using api_element = schema::api_type::vulkan::VkCopyMemoryToImageIndirectCommandKHR;

    VkCopyMemoryToImageIndirectCommandKHR* decoded_value{ nullptr };

    Decoded_VkImageSubresourceLayers* imageSubresource{ nullptr };
    Decoded_VkOffset3D* imageOffset{ nullptr };
    Decoded_VkExtent3D* imageExtent{ nullptr };
};

struct Decoded_VkCopyMemoryToImageIndirectInfoKHR
{
    using struct_type = VkCopyMemoryToImageIndirectInfoKHR;
    using api_element = schema::api_type::vulkan::VkCopyMemoryToImageIndirectInfoKHR;

    VkCopyMemoryToImageIndirectInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkStridedDeviceAddressRangeKHR* copyAddressRange{ nullptr };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageSubresourceLayers>* pImageSubresources{ nullptr };
};

struct Decoded_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR
{
    using struct_type = VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR;

    VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR
{
    using struct_type = VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR;

    VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeIntraRefreshCapabilitiesKHR
{
    using struct_type = VkVideoEncodeIntraRefreshCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeIntraRefreshCapabilitiesKHR;

    VkVideoEncodeIntraRefreshCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeSessionIntraRefreshCreateInfoKHR
{
    using struct_type = VkVideoEncodeSessionIntraRefreshCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeSessionIntraRefreshCreateInfoKHR;

    VkVideoEncodeSessionIntraRefreshCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeIntraRefreshInfoKHR
{
    using struct_type = VkVideoEncodeIntraRefreshInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeIntraRefreshInfoKHR;

    VkVideoEncodeIntraRefreshInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoReferenceIntraRefreshInfoKHR
{
    using struct_type = VkVideoReferenceIntraRefreshInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoReferenceIntraRefreshInfoKHR;

    VkVideoReferenceIntraRefreshInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR
{
    using struct_type = VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR;

    VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeQuantizationMapCapabilitiesKHR
{
    using struct_type = VkVideoEncodeQuantizationMapCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeQuantizationMapCapabilitiesKHR;

    VkVideoEncodeQuantizationMapCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* maxQuantizationMapExtent{ nullptr };
};

struct Decoded_VkVideoFormatQuantizationMapPropertiesKHR
{
    using struct_type = VkVideoFormatQuantizationMapPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoFormatQuantizationMapPropertiesKHR;

    VkVideoFormatQuantizationMapPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* quantizationMapTexelSize{ nullptr };
};

struct Decoded_VkVideoEncodeQuantizationMapInfoKHR
{
    using struct_type = VkVideoEncodeQuantizationMapInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeQuantizationMapInfoKHR;

    VkVideoEncodeQuantizationMapInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId quantizationMap{ format::kNullHandleId };
    Decoded_VkExtent2D* quantizationMapExtent{ nullptr };
};

struct Decoded_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR
{
    using struct_type = VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR;

    VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* quantizationMapTexelSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR
{
    using struct_type = VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR;

    VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264QuantizationMapCapabilitiesKHR
{
    using struct_type = VkVideoEncodeH264QuantizationMapCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH264QuantizationMapCapabilitiesKHR;

    VkVideoEncodeH264QuantizationMapCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH265QuantizationMapCapabilitiesKHR
{
    using struct_type = VkVideoEncodeH265QuantizationMapCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeH265QuantizationMapCapabilitiesKHR;

    VkVideoEncodeH265QuantizationMapCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoFormatH265QuantizationMapPropertiesKHR
{
    using struct_type = VkVideoFormatH265QuantizationMapPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoFormatH265QuantizationMapPropertiesKHR;

    VkVideoFormatH265QuantizationMapPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR
{
    using struct_type = VkVideoEncodeAV1QuantizationMapCapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeAV1QuantizationMapCapabilitiesKHR;

    VkVideoEncodeAV1QuantizationMapCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoFormatAV1QuantizationMapPropertiesKHR
{
    using struct_type = VkVideoFormatAV1QuantizationMapPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoFormatAV1QuantizationMapPropertiesKHR;

    VkVideoFormatAV1QuantizationMapPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR;

    VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance7FeaturesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance7FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance7FeaturesKHR;

    VkPhysicalDeviceMaintenance7FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance7PropertiesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance7PropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance7PropertiesKHR;

    VkPhysicalDeviceMaintenance7PropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceLayeredApiPropertiesKHR
{
    using struct_type = VkPhysicalDeviceLayeredApiPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLayeredApiPropertiesKHR;

    VkPhysicalDeviceLayeredApiPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder deviceName;
};

struct Decoded_VkPhysicalDeviceLayeredApiPropertiesListKHR
{
    using struct_type = VkPhysicalDeviceLayeredApiPropertiesListKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLayeredApiPropertiesListKHR;

    VkPhysicalDeviceLayeredApiPropertiesListKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPhysicalDeviceLayeredApiPropertiesKHR>* pLayeredApis{ nullptr };
};

struct Decoded_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR
{
    using struct_type = VkPhysicalDeviceLayeredApiVulkanPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLayeredApiVulkanPropertiesKHR;

    VkPhysicalDeviceLayeredApiVulkanPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPhysicalDeviceProperties2* properties{ nullptr };
};

struct Decoded_VkPhysicalDeviceFaultFeaturesKHR
{
    using struct_type = VkPhysicalDeviceFaultFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFaultFeaturesKHR;

    VkPhysicalDeviceFaultFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFaultPropertiesKHR
{
    using struct_type = VkPhysicalDeviceFaultPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFaultPropertiesKHR;

    VkPhysicalDeviceFaultPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceFaultAddressInfoKHR
{
    using struct_type = VkDeviceFaultAddressInfoKHR;
    using api_element = schema::api_type::vulkan::VkDeviceFaultAddressInfoKHR;

    VkDeviceFaultAddressInfoKHR* decoded_value{ nullptr };
};

struct Decoded_VkDeviceFaultVendorInfoKHR
{
    using struct_type = VkDeviceFaultVendorInfoKHR;
    using api_element = schema::api_type::vulkan::VkDeviceFaultVendorInfoKHR;

    VkDeviceFaultVendorInfoKHR* decoded_value{ nullptr };

    StringDecoder description;
};

struct Decoded_VkDeviceFaultInfoKHR
{
    using struct_type = VkDeviceFaultInfoKHR;
    using api_element = schema::api_type::vulkan::VkDeviceFaultInfoKHR;

    VkDeviceFaultInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder description;
    Decoded_VkDeviceFaultAddressInfoKHR* faultAddressInfo{ nullptr };
    Decoded_VkDeviceFaultAddressInfoKHR* instructionAddressInfo{ nullptr };
    Decoded_VkDeviceFaultVendorInfoKHR* vendorInfo{ nullptr };
};

struct Decoded_VkDeviceFaultDebugInfoKHR
{
    using struct_type = VkDeviceFaultDebugInfoKHR;
    using api_element = schema::api_type::vulkan::VkDeviceFaultDebugInfoKHR;

    VkDeviceFaultDebugInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pVendorBinaryData;
};

struct Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneKHR
{
    using struct_type = VkDeviceFaultVendorBinaryHeaderVersionOneKHR;
    using api_element = schema::api_type::vulkan::VkDeviceFaultVendorBinaryHeaderVersionOneKHR;

    VkDeviceFaultVendorBinaryHeaderVersionOneKHR* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pipelineCacheUUID;
};

struct Decoded_VkMemoryBarrierAccessFlags3KHR
{
    using struct_type = VkMemoryBarrierAccessFlags3KHR;
    using api_element = schema::api_type::vulkan::VkMemoryBarrierAccessFlags3KHR;

    VkMemoryBarrierAccessFlags3KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance8FeaturesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance8FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance8FeaturesKHR;

    VkPhysicalDeviceMaintenance8FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderFmaFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderFmaFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderFmaFeaturesKHR;

    VkPhysicalDeviceShaderFmaFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance9FeaturesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance9FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance9FeaturesKHR;

    VkPhysicalDeviceMaintenance9FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance9PropertiesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance9PropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance9PropertiesKHR;

    VkPhysicalDeviceMaintenance9PropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyOwnershipTransferPropertiesKHR
{
    using struct_type = VkQueueFamilyOwnershipTransferPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkQueueFamilyOwnershipTransferPropertiesKHR;

    VkQueueFamilyOwnershipTransferPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR
{
    using struct_type = VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR;

    VkPhysicalDeviceVideoEncodeFeedback2FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeFeedback2CapabilitiesKHR
{
    using struct_type = VkVideoEncodeFeedback2CapabilitiesKHR;
    using api_element = schema::api_type::vulkan::VkVideoEncodeFeedback2CapabilitiesKHR;

    VkVideoEncodeFeedback2CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR
{
    using struct_type = VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR;

    VkQueryPoolVideoEncodePerPartitionFeedbackCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR
{
    using struct_type = VkPhysicalDeviceDepthClampZeroOneFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDepthClampZeroOneFeaturesKHR;

    VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRobustness2FeaturesKHR
{
    using struct_type = VkPhysicalDeviceRobustness2FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRobustness2FeaturesKHR;

    VkPhysicalDeviceRobustness2FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRobustness2PropertiesKHR
{
    using struct_type = VkPhysicalDeviceRobustness2PropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRobustness2PropertiesKHR;

    VkPhysicalDeviceRobustness2PropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR
{
    using struct_type = VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR;

    VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMicromapUsageKHR
{
    using struct_type = VkMicromapUsageKHR;
    using api_element = schema::api_type::vulkan::VkMicromapUsageKHR;

    VkMicromapUsageKHR* decoded_value{ nullptr };
};

struct Decoded_VkAccelerationStructureGeometryMicromapDataKHR
{
    using struct_type = VkAccelerationStructureGeometryMicromapDataKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureGeometryMicromapDataKHR;

    VkAccelerationStructureGeometryMicromapDataKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkMicromapUsageKHR>* pUsageCounts{ nullptr };
    StructPointerDecoder<Decoded_VkMicromapUsageKHR*>* ppUsageCounts{ nullptr };
};

struct Decoded_VkPhysicalDeviceOpacityMicromapFeaturesKHR
{
    using struct_type = VkPhysicalDeviceOpacityMicromapFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceOpacityMicromapFeaturesKHR;

    VkPhysicalDeviceOpacityMicromapFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceOpacityMicromapPropertiesKHR
{
    using struct_type = VkPhysicalDeviceOpacityMicromapPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceOpacityMicromapPropertiesKHR;

    VkPhysicalDeviceOpacityMicromapPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMicromapTriangleKHR
{
    using struct_type = VkMicromapTriangleKHR;
    using api_element = schema::api_type::vulkan::VkMicromapTriangleKHR;

    VkMicromapTriangleKHR* decoded_value{ nullptr };
};

struct Decoded_VkAccelerationStructureTrianglesOpacityMicromapKHR
{
    using struct_type = VkAccelerationStructureTrianglesOpacityMicromapKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureTrianglesOpacityMicromapKHR;

    VkAccelerationStructureTrianglesOpacityMicromapKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId micromap{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceMaintenance10FeaturesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance10FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance10FeaturesKHR;

    VkPhysicalDeviceMaintenance10FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance10PropertiesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance10PropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance10PropertiesKHR;

    VkPhysicalDeviceMaintenance10PropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderingEndInfoKHR
{
    using struct_type = VkRenderingEndInfoKHR;
    using api_element = schema::api_type::vulkan::VkRenderingEndInfoKHR;

    VkRenderingEndInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderingAttachmentFlagsInfoKHR
{
    using struct_type = VkRenderingAttachmentFlagsInfoKHR;
    using api_element = schema::api_type::vulkan::VkRenderingAttachmentFlagsInfoKHR;

    VkRenderingAttachmentFlagsInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkResolveImageModeInfoKHR
{
    using struct_type = VkResolveImageModeInfoKHR;
    using api_element = schema::api_type::vulkan::VkResolveImageModeInfoKHR;

    VkResolveImageModeInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance11FeaturesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance11FeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMaintenance11FeaturesKHR;

    VkPhysicalDeviceMaintenance11FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR
{
    using struct_type = VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR;
    using api_element = schema::api_type::vulkan::VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR;

    VkQueueFamilyOptimalImageTransferGranularityPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent3D* optimalImageTransferGranularity{ nullptr };
};

struct Decoded_VkFormatProperties4KHR
{
    using struct_type = VkFormatProperties4KHR;
    using api_element = schema::api_type::vulkan::VkFormatProperties4KHR;

    VkFormatProperties4KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageUsageFlags2CreateInfoKHR
{
    using struct_type = VkImageUsageFlags2CreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkImageUsageFlags2CreateInfoKHR;

    VkImageUsageFlags2CreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageCreateFlags2CreateInfoKHR
{
    using struct_type = VkImageCreateFlags2CreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkImageCreateFlags2CreateInfoKHR;

    VkImageCreateFlags2CreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageViewUsage2CreateInfoKHR
{
    using struct_type = VkImageViewUsage2CreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkImageViewUsage2CreateInfoKHR;

    VkImageViewUsage2CreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedFlagsFeaturesKHR
{
    using struct_type = VkPhysicalDeviceExtendedFlagsFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExtendedFlagsFeaturesKHR;

    VkPhysicalDeviceExtendedFlagsFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageStencilUsage2CreateInfoKHR
{
    using struct_type = VkImageStencilUsage2CreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkImageStencilUsage2CreateInfoKHR;

    VkImageStencilUsage2CreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSharedPresentSurfaceCapabilities2KHR
{
    using struct_type = VkSharedPresentSurfaceCapabilities2KHR;
    using api_element = schema::api_type::vulkan::VkSharedPresentSurfaceCapabilities2KHR;

    VkSharedPresentSurfaceCapabilities2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDebugReportCallbackCreateInfoEXT
{
    using struct_type = VkDebugReportCallbackCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkDebugReportCallbackCreateInfoEXT;

    VkDebugReportCallbackCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pfnCallback{ 0 };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkPipelineRasterizationStateRasterizationOrderAMD
{
    using struct_type = VkPipelineRasterizationStateRasterizationOrderAMD;
    using api_element = schema::api_type::vulkan::VkPipelineRasterizationStateRasterizationOrderAMD;

    VkPipelineRasterizationStateRasterizationOrderAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDebugMarkerObjectNameInfoEXT
{
    using struct_type = VkDebugMarkerObjectNameInfoEXT;
    using api_element = schema::api_type::vulkan::VkDebugMarkerObjectNameInfoEXT;

    VkDebugMarkerObjectNameInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t object{ 0 };
    StringDecoder pObjectName;
};

struct Decoded_VkDebugMarkerObjectTagInfoEXT
{
    using struct_type = VkDebugMarkerObjectTagInfoEXT;
    using api_element = schema::api_type::vulkan::VkDebugMarkerObjectTagInfoEXT;

    VkDebugMarkerObjectTagInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t object{ 0 };
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkDebugMarkerMarkerInfoEXT
{
    using struct_type = VkDebugMarkerMarkerInfoEXT;
    using api_element = schema::api_type::vulkan::VkDebugMarkerMarkerInfoEXT;

    VkDebugMarkerMarkerInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder pMarkerName;
    PointerDecoder<float> color;
};

struct Decoded_VkDedicatedAllocationImageCreateInfoNV
{
    using struct_type = VkDedicatedAllocationImageCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkDedicatedAllocationImageCreateInfoNV;

    VkDedicatedAllocationImageCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDedicatedAllocationBufferCreateInfoNV
{
    using struct_type = VkDedicatedAllocationBufferCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkDedicatedAllocationBufferCreateInfoNV;

    VkDedicatedAllocationBufferCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDedicatedAllocationMemoryAllocateInfoNV
{
    using struct_type = VkDedicatedAllocationMemoryAllocateInfoNV;
    using api_element = schema::api_type::vulkan::VkDedicatedAllocationMemoryAllocateInfoNV;

    VkDedicatedAllocationMemoryAllocateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT
{
    using struct_type = VkPhysicalDeviceTransformFeedbackFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTransformFeedbackFeaturesEXT;

    VkPhysicalDeviceTransformFeedbackFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT
{
    using struct_type = VkPhysicalDeviceTransformFeedbackPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTransformFeedbackPropertiesEXT;

    VkPhysicalDeviceTransformFeedbackPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationStateStreamCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineRasterizationStateStreamCreateInfoEXT;

    VkPipelineRasterizationStateStreamCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageViewHandleInfoNVX
{
    using struct_type = VkImageViewHandleInfoNVX;
    using api_element = schema::api_type::vulkan::VkImageViewHandleInfoNVX;

    VkImageViewHandleInfoNVX* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId imageView{ format::kNullHandleId };
    format::HandleId sampler{ format::kNullHandleId };
};

struct Decoded_VkImageViewAddressPropertiesNVX
{
    using struct_type = VkImageViewAddressPropertiesNVX;
    using api_element = schema::api_type::vulkan::VkImageViewAddressPropertiesNVX;

    VkImageViewAddressPropertiesNVX* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTextureLODGatherFormatPropertiesAMD
{
    using struct_type = VkTextureLODGatherFormatPropertiesAMD;
    using api_element = schema::api_type::vulkan::VkTextureLODGatherFormatPropertiesAMD;

    VkTextureLODGatherFormatPropertiesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkShaderResourceUsageAMD
{
    using struct_type = VkShaderResourceUsageAMD;
    using api_element = schema::api_type::vulkan::VkShaderResourceUsageAMD;

    VkShaderResourceUsageAMD* decoded_value{ nullptr };
};

struct Decoded_VkShaderStatisticsInfoAMD
{
    using struct_type = VkShaderStatisticsInfoAMD;
    using api_element = schema::api_type::vulkan::VkShaderStatisticsInfoAMD;

    VkShaderStatisticsInfoAMD* decoded_value{ nullptr };

    Decoded_VkShaderResourceUsageAMD* resourceUsage{ nullptr };
    PointerDecoder<uint32_t> computeWorkGroupSize;
};

struct Decoded_VkStreamDescriptorSurfaceCreateInfoGGP
{
    using struct_type = VkStreamDescriptorSurfaceCreateInfoGGP;
    using api_element = schema::api_type::vulkan::VkStreamDescriptorSurfaceCreateInfoGGP;

    VkStreamDescriptorSurfaceCreateInfoGGP* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV
{
    using struct_type = VkPhysicalDeviceCornerSampledImageFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCornerSampledImageFeaturesNV;

    VkPhysicalDeviceCornerSampledImageFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalImageFormatPropertiesNV
{
    using struct_type = VkExternalImageFormatPropertiesNV;
    using api_element = schema::api_type::vulkan::VkExternalImageFormatPropertiesNV;

    VkExternalImageFormatPropertiesNV* decoded_value{ nullptr };

    Decoded_VkImageFormatProperties* imageFormatProperties{ nullptr };
};

struct Decoded_VkExternalMemoryImageCreateInfoNV
{
    using struct_type = VkExternalMemoryImageCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkExternalMemoryImageCreateInfoNV;

    VkExternalMemoryImageCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExportMemoryAllocateInfoNV
{
    using struct_type = VkExportMemoryAllocateInfoNV;
    using api_element = schema::api_type::vulkan::VkExportMemoryAllocateInfoNV;

    VkExportMemoryAllocateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImportMemoryWin32HandleInfoNV
{
    using struct_type = VkImportMemoryWin32HandleInfoNV;
    using api_element = schema::api_type::vulkan::VkImportMemoryWin32HandleInfoNV;

    VkImportMemoryWin32HandleInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t handle{ 0 };
};

struct Decoded_VkExportMemoryWin32HandleInfoNV
{
    using struct_type = VkExportMemoryWin32HandleInfoNV;
    using api_element = schema::api_type::vulkan::VkExportMemoryWin32HandleInfoNV;

    VkExportMemoryWin32HandleInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>* pAttributes{ nullptr };
};

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV
{
    using struct_type = VkWin32KeyedMutexAcquireReleaseInfoNV;
    using api_element = schema::api_type::vulkan::VkWin32KeyedMutexAcquireReleaseInfoNV;

    VkWin32KeyedMutexAcquireReleaseInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkDeviceMemory> pAcquireSyncs;
    PointerDecoder<uint64_t> pAcquireKeys;
    PointerDecoder<uint32_t> pAcquireTimeoutMilliseconds;
    HandlePointerDecoder<VkDeviceMemory> pReleaseSyncs;
    PointerDecoder<uint64_t> pReleaseKeys;
};

struct Decoded_VkValidationFlagsEXT
{
    using struct_type = VkValidationFlagsEXT;
    using api_element = schema::api_type::vulkan::VkValidationFlagsEXT;

    VkValidationFlagsEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkValidationCheckEXT> pDisabledValidationChecks;
};

struct Decoded_VkViSurfaceCreateInfoNN
{
    using struct_type = VkViSurfaceCreateInfoNN;
    using api_element = schema::api_type::vulkan::VkViSurfaceCreateInfoNN;

    VkViSurfaceCreateInfoNN* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t window{ 0 };
};

struct Decoded_VkImageViewASTCDecodeModeEXT
{
    using struct_type = VkImageViewASTCDecodeModeEXT;
    using api_element = schema::api_type::vulkan::VkImageViewASTCDecodeModeEXT;

    VkImageViewASTCDecodeModeEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT
{
    using struct_type = VkPhysicalDeviceASTCDecodeFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceASTCDecodeFeaturesEXT;

    VkPhysicalDeviceASTCDecodeFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkConditionalRenderingBeginInfoEXT
{
    using struct_type = VkConditionalRenderingBeginInfoEXT;
    using api_element = schema::api_type::vulkan::VkConditionalRenderingBeginInfoEXT;

    VkConditionalRenderingBeginInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT
{
    using struct_type = VkPhysicalDeviceConditionalRenderingFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceConditionalRenderingFeaturesEXT;

    VkPhysicalDeviceConditionalRenderingFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT
{
    using struct_type = VkCommandBufferInheritanceConditionalRenderingInfoEXT;
    using api_element = schema::api_type::vulkan::VkCommandBufferInheritanceConditionalRenderingInfoEXT;

    VkCommandBufferInheritanceConditionalRenderingInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkViewportWScalingNV
{
    using struct_type = VkViewportWScalingNV;
    using api_element = schema::api_type::vulkan::VkViewportWScalingNV;

    VkViewportWScalingNV* decoded_value{ nullptr };
};

struct Decoded_VkPipelineViewportWScalingStateCreateInfoNV
{
    using struct_type = VkPipelineViewportWScalingStateCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineViewportWScalingStateCreateInfoNV;

    VkPipelineViewportWScalingStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings{ nullptr };
};

struct Decoded_VkSurfaceCapabilities2EXT
{
    using struct_type = VkSurfaceCapabilities2EXT;
    using api_element = schema::api_type::vulkan::VkSurfaceCapabilities2EXT;

    VkSurfaceCapabilities2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* currentExtent{ nullptr };
    Decoded_VkExtent2D* minImageExtent{ nullptr };
    Decoded_VkExtent2D* maxImageExtent{ nullptr };
};

struct Decoded_VkDisplayPowerInfoEXT
{
    using struct_type = VkDisplayPowerInfoEXT;
    using api_element = schema::api_type::vulkan::VkDisplayPowerInfoEXT;

    VkDisplayPowerInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceEventInfoEXT
{
    using struct_type = VkDeviceEventInfoEXT;
    using api_element = schema::api_type::vulkan::VkDeviceEventInfoEXT;

    VkDeviceEventInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDisplayEventInfoEXT
{
    using struct_type = VkDisplayEventInfoEXT;
    using api_element = schema::api_type::vulkan::VkDisplayEventInfoEXT;

    VkDisplayEventInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainCounterCreateInfoEXT
{
    using struct_type = VkSwapchainCounterCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkSwapchainCounterCreateInfoEXT;

    VkSwapchainCounterCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRefreshCycleDurationGOOGLE
{
    using struct_type = VkRefreshCycleDurationGOOGLE;
    using api_element = schema::api_type::vulkan::VkRefreshCycleDurationGOOGLE;

    VkRefreshCycleDurationGOOGLE* decoded_value{ nullptr };
};

struct Decoded_VkPastPresentationTimingGOOGLE
{
    using struct_type = VkPastPresentationTimingGOOGLE;
    using api_element = schema::api_type::vulkan::VkPastPresentationTimingGOOGLE;

    VkPastPresentationTimingGOOGLE* decoded_value{ nullptr };
};

struct Decoded_VkPresentTimeGOOGLE
{
    using struct_type = VkPresentTimeGOOGLE;
    using api_element = schema::api_type::vulkan::VkPresentTimeGOOGLE;

    VkPresentTimeGOOGLE* decoded_value{ nullptr };
};

struct Decoded_VkPresentTimesInfoGOOGLE
{
    using struct_type = VkPresentTimesInfoGOOGLE;
    using api_element = schema::api_type::vulkan::VkPresentTimesInfoGOOGLE;

    VkPresentTimesInfoGOOGLE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPresentTimeGOOGLE>* pTimes{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX
{
    using struct_type = VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;

    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMultiviewPerViewAttributesInfoNVX
{
    using struct_type = VkMultiviewPerViewAttributesInfoNVX;
    using api_element = schema::api_type::vulkan::VkMultiviewPerViewAttributesInfoNVX;

    VkMultiviewPerViewAttributesInfoNVX* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkViewportSwizzleNV
{
    using struct_type = VkViewportSwizzleNV;
    using api_element = schema::api_type::vulkan::VkViewportSwizzleNV;

    VkViewportSwizzleNV* decoded_value{ nullptr };
};

struct Decoded_VkPipelineViewportSwizzleStateCreateInfoNV
{
    using struct_type = VkPipelineViewportSwizzleStateCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineViewportSwizzleStateCreateInfoNV;

    VkPipelineViewportSwizzleStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles{ nullptr };
};

struct Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT
{
    using struct_type = VkPhysicalDeviceDiscardRectanglePropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDiscardRectanglePropertiesEXT;

    VkPhysicalDeviceDiscardRectanglePropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT
{
    using struct_type = VkPipelineDiscardRectangleStateCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineDiscardRectangleStateCreateInfoEXT;

    VkPipelineDiscardRectangleStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pDiscardRectangles{ nullptr };
};

struct Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT
{
    using struct_type = VkPhysicalDeviceConservativeRasterizationPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceConservativeRasterizationPropertiesEXT;

    VkPhysicalDeviceConservativeRasterizationPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationConservativeStateCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineRasterizationConservativeStateCreateInfoEXT;

    VkPipelineRasterizationConservativeStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDepthClipEnableFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDepthClipEnableFeaturesEXT;

    VkPhysicalDeviceDepthClipEnableFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationDepthClipStateCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineRasterizationDepthClipStateCreateInfoEXT;

    VkPipelineRasterizationDepthClipStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkXYColorEXT
{
    using struct_type = VkXYColorEXT;
    using api_element = schema::api_type::vulkan::VkXYColorEXT;

    VkXYColorEXT* decoded_value{ nullptr };
};

struct Decoded_VkHdrMetadataEXT
{
    using struct_type = VkHdrMetadataEXT;
    using api_element = schema::api_type::vulkan::VkHdrMetadataEXT;

    VkHdrMetadataEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkXYColorEXT* displayPrimaryRed{ nullptr };
    Decoded_VkXYColorEXT* displayPrimaryGreen{ nullptr };
    Decoded_VkXYColorEXT* displayPrimaryBlue{ nullptr };
    Decoded_VkXYColorEXT* whitePoint{ nullptr };
};

struct Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG
{
    using struct_type = VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG;

    VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkIOSSurfaceCreateInfoMVK
{
    using struct_type = VkIOSSurfaceCreateInfoMVK;
    using api_element = schema::api_type::vulkan::VkIOSSurfaceCreateInfoMVK;

    VkIOSSurfaceCreateInfoMVK* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pView{ 0 };
};

struct Decoded_VkMacOSSurfaceCreateInfoMVK
{
    using struct_type = VkMacOSSurfaceCreateInfoMVK;
    using api_element = schema::api_type::vulkan::VkMacOSSurfaceCreateInfoMVK;

    VkMacOSSurfaceCreateInfoMVK* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pView{ 0 };
};

struct Decoded_VkDebugUtilsLabelEXT
{
    using struct_type = VkDebugUtilsLabelEXT;
    using api_element = schema::api_type::vulkan::VkDebugUtilsLabelEXT;

    VkDebugUtilsLabelEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder pLabelName;
    PointerDecoder<float> color;
};

struct Decoded_VkDebugUtilsObjectNameInfoEXT
{
    using struct_type = VkDebugUtilsObjectNameInfoEXT;
    using api_element = schema::api_type::vulkan::VkDebugUtilsObjectNameInfoEXT;

    VkDebugUtilsObjectNameInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t objectHandle{ 0 };
    StringDecoder pObjectName;
};

struct Decoded_VkDebugUtilsMessengerCallbackDataEXT
{
    using struct_type = VkDebugUtilsMessengerCallbackDataEXT;
    using api_element = schema::api_type::vulkan::VkDebugUtilsMessengerCallbackDataEXT;

    VkDebugUtilsMessengerCallbackDataEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder pMessageIdName;
    StringDecoder pMessage;
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pQueueLabels{ nullptr };
    StructPointerDecoder<Decoded_VkDebugUtilsLabelEXT>* pCmdBufLabels{ nullptr };
    StructPointerDecoder<Decoded_VkDebugUtilsObjectNameInfoEXT>* pObjects{ nullptr };
};

struct Decoded_VkDebugUtilsMessengerCreateInfoEXT
{
    using struct_type = VkDebugUtilsMessengerCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkDebugUtilsMessengerCreateInfoEXT;

    VkDebugUtilsMessengerCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pfnUserCallback{ 0 };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkDebugUtilsObjectTagInfoEXT
{
    using struct_type = VkDebugUtilsObjectTagInfoEXT;
    using api_element = schema::api_type::vulkan::VkDebugUtilsObjectTagInfoEXT;

    VkDebugUtilsObjectTagInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t objectHandle{ 0 };
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkAndroidHardwareBufferUsageANDROID
{
    using struct_type = VkAndroidHardwareBufferUsageANDROID;
    using api_element = schema::api_type::vulkan::VkAndroidHardwareBufferUsageANDROID;

    VkAndroidHardwareBufferUsageANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAndroidHardwareBufferPropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferPropertiesANDROID;
    using api_element = schema::api_type::vulkan::VkAndroidHardwareBufferPropertiesANDROID;

    VkAndroidHardwareBufferPropertiesANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferFormatPropertiesANDROID;
    using api_element = schema::api_type::vulkan::VkAndroidHardwareBufferFormatPropertiesANDROID;

    VkAndroidHardwareBufferFormatPropertiesANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkComponentMapping* samplerYcbcrConversionComponents{ nullptr };
};

struct Decoded_VkImportAndroidHardwareBufferInfoANDROID
{
    using struct_type = VkImportAndroidHardwareBufferInfoANDROID;
    using api_element = schema::api_type::vulkan::VkImportAndroidHardwareBufferInfoANDROID;

    VkImportAndroidHardwareBufferInfoANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t buffer{ 0 };
};

struct Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID
{
    using struct_type = VkMemoryGetAndroidHardwareBufferInfoANDROID;
    using api_element = schema::api_type::vulkan::VkMemoryGetAndroidHardwareBufferInfoANDROID;

    VkMemoryGetAndroidHardwareBufferInfoANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkExternalFormatANDROID
{
    using struct_type = VkExternalFormatANDROID;
    using api_element = schema::api_type::vulkan::VkExternalFormatANDROID;

    VkExternalFormatANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID
{
    using struct_type = VkAndroidHardwareBufferFormatProperties2ANDROID;
    using api_element = schema::api_type::vulkan::VkAndroidHardwareBufferFormatProperties2ANDROID;

    VkAndroidHardwareBufferFormatProperties2ANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkComponentMapping* samplerYcbcrConversionComponents{ nullptr };
};

struct Decoded_VkGpaPerfBlockPropertiesAMD
{
    using struct_type = VkGpaPerfBlockPropertiesAMD;
    using api_element = schema::api_type::vulkan::VkGpaPerfBlockPropertiesAMD;

    VkGpaPerfBlockPropertiesAMD* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceGpaFeaturesAMD
{
    using struct_type = VkPhysicalDeviceGpaFeaturesAMD;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceGpaFeaturesAMD;

    VkPhysicalDeviceGpaFeaturesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceGpaPropertiesAMD
{
    using struct_type = VkPhysicalDeviceGpaPropertiesAMD;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceGpaPropertiesAMD;

    VkPhysicalDeviceGpaPropertiesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkGpaPerfBlockPropertiesAMD>* pPerfBlocks{ nullptr };
};

struct Decoded_VkPhysicalDeviceGpaProperties2AMD
{
    using struct_type = VkPhysicalDeviceGpaProperties2AMD;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceGpaProperties2AMD;

    VkPhysicalDeviceGpaProperties2AMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkGpaPerfCounterAMD
{
    using struct_type = VkGpaPerfCounterAMD;
    using api_element = schema::api_type::vulkan::VkGpaPerfCounterAMD;

    VkGpaPerfCounterAMD* decoded_value{ nullptr };
};

struct Decoded_VkGpaSampleBeginInfoAMD
{
    using struct_type = VkGpaSampleBeginInfoAMD;
    using api_element = schema::api_type::vulkan::VkGpaSampleBeginInfoAMD;

    VkGpaSampleBeginInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkGpaPerfCounterAMD>* pPerfCounters{ nullptr };
};

struct Decoded_VkGpaDeviceClockModeInfoAMD
{
    using struct_type = VkGpaDeviceClockModeInfoAMD;
    using api_element = schema::api_type::vulkan::VkGpaDeviceClockModeInfoAMD;

    VkGpaDeviceClockModeInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkGpaDeviceGetClockInfoAMD
{
    using struct_type = VkGpaDeviceGetClockInfoAMD;
    using api_element = schema::api_type::vulkan::VkGpaDeviceGetClockInfoAMD;

    VkGpaDeviceGetClockInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkGpaSessionCreateInfoAMD
{
    using struct_type = VkGpaSessionCreateInfoAMD;
    using api_element = schema::api_type::vulkan::VkGpaSessionCreateInfoAMD;

    VkGpaSessionCreateInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId secondaryCopySource{ format::kNullHandleId };
};

struct Decoded_VkAttachmentSampleCountInfoAMD
{
    using struct_type = VkAttachmentSampleCountInfoAMD;
    using api_element = schema::api_type::vulkan::VkAttachmentSampleCountInfoAMD;

    VkAttachmentSampleCountInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkSampleCountFlagBits> pColorAttachmentSamples;
};

struct Decoded_VkSampleLocationEXT
{
    using struct_type = VkSampleLocationEXT;
    using api_element = schema::api_type::vulkan::VkSampleLocationEXT;

    VkSampleLocationEXT* decoded_value{ nullptr };
};

struct Decoded_VkSampleLocationsInfoEXT
{
    using struct_type = VkSampleLocationsInfoEXT;
    using api_element = schema::api_type::vulkan::VkSampleLocationsInfoEXT;

    VkSampleLocationsInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* sampleLocationGridSize{ nullptr };
    StructPointerDecoder<Decoded_VkSampleLocationEXT>* pSampleLocations{ nullptr };
};

struct Decoded_VkAttachmentSampleLocationsEXT
{
    using struct_type = VkAttachmentSampleLocationsEXT;
    using api_element = schema::api_type::vulkan::VkAttachmentSampleLocationsEXT;

    VkAttachmentSampleLocationsEXT* decoded_value{ nullptr };

    Decoded_VkSampleLocationsInfoEXT* sampleLocationsInfo{ nullptr };
};

struct Decoded_VkSubpassSampleLocationsEXT
{
    using struct_type = VkSubpassSampleLocationsEXT;
    using api_element = schema::api_type::vulkan::VkSubpassSampleLocationsEXT;

    VkSubpassSampleLocationsEXT* decoded_value{ nullptr };

    Decoded_VkSampleLocationsInfoEXT* sampleLocationsInfo{ nullptr };
};

struct Decoded_VkRenderPassSampleLocationsBeginInfoEXT
{
    using struct_type = VkRenderPassSampleLocationsBeginInfoEXT;
    using api_element = schema::api_type::vulkan::VkRenderPassSampleLocationsBeginInfoEXT;

    VkRenderPassSampleLocationsBeginInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentSampleLocationsEXT>* pAttachmentInitialSampleLocations{ nullptr };
    StructPointerDecoder<Decoded_VkSubpassSampleLocationsEXT>* pPostSubpassSampleLocations{ nullptr };
};

struct Decoded_VkPipelineSampleLocationsStateCreateInfoEXT
{
    using struct_type = VkPipelineSampleLocationsStateCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineSampleLocationsStateCreateInfoEXT;

    VkPipelineSampleLocationsStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSampleLocationsInfoEXT* sampleLocationsInfo{ nullptr };
};

struct Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT
{
    using struct_type = VkPhysicalDeviceSampleLocationsPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSampleLocationsPropertiesEXT;

    VkPhysicalDeviceSampleLocationsPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* maxSampleLocationGridSize{ nullptr };
    PointerDecoder<float> sampleLocationCoordinateRange;
};

struct Decoded_VkMultisamplePropertiesEXT
{
    using struct_type = VkMultisamplePropertiesEXT;
    using api_element = schema::api_type::vulkan::VkMultisamplePropertiesEXT;

    VkMultisamplePropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* maxSampleLocationGridSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT;

    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT
{
    using struct_type = VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;

    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT
{
    using struct_type = VkPipelineColorBlendAdvancedStateCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineColorBlendAdvancedStateCreateInfoEXT;

    VkPipelineColorBlendAdvancedStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCoverageToColorStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageToColorStateCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineCoverageToColorStateCreateInfoNV;

    VkPipelineCoverageToColorStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCoverageModulationStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageModulationStateCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineCoverageModulationStateCreateInfoNV;

    VkPipelineCoverageModulationStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<float> pCoverageModulationTable;
};

struct Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV
{
    using struct_type = VkPhysicalDeviceShaderSMBuiltinsPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderSMBuiltinsPropertiesNV;

    VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV
{
    using struct_type = VkPhysicalDeviceShaderSMBuiltinsFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderSMBuiltinsFeaturesNV;

    VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDrmFormatModifierPropertiesEXT
{
    using struct_type = VkDrmFormatModifierPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkDrmFormatModifierPropertiesEXT;

    VkDrmFormatModifierPropertiesEXT* decoded_value{ nullptr };
};

struct Decoded_VkDrmFormatModifierPropertiesListEXT
{
    using struct_type = VkDrmFormatModifierPropertiesListEXT;
    using api_element = schema::api_type::vulkan::VkDrmFormatModifierPropertiesListEXT;

    VkDrmFormatModifierPropertiesListEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDrmFormatModifierPropertiesEXT>* pDrmFormatModifierProperties{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT
{
    using struct_type = VkPhysicalDeviceImageDrmFormatModifierInfoEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageDrmFormatModifierInfoEXT;

    VkPhysicalDeviceImageDrmFormatModifierInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkImageDrmFormatModifierListCreateInfoEXT
{
    using struct_type = VkImageDrmFormatModifierListCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkImageDrmFormatModifierListCreateInfoEXT;

    VkImageDrmFormatModifierListCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint64_t> pDrmFormatModifiers;
};

struct Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT
{
    using struct_type = VkImageDrmFormatModifierExplicitCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkImageDrmFormatModifierExplicitCreateInfoEXT;

    VkImageDrmFormatModifierExplicitCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pPlaneLayouts{ nullptr };
};

struct Decoded_VkImageDrmFormatModifierPropertiesEXT
{
    using struct_type = VkImageDrmFormatModifierPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkImageDrmFormatModifierPropertiesEXT;

    VkImageDrmFormatModifierPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDrmFormatModifierProperties2EXT
{
    using struct_type = VkDrmFormatModifierProperties2EXT;
    using api_element = schema::api_type::vulkan::VkDrmFormatModifierProperties2EXT;

    VkDrmFormatModifierProperties2EXT* decoded_value{ nullptr };
};

struct Decoded_VkDrmFormatModifierPropertiesList2EXT
{
    using struct_type = VkDrmFormatModifierPropertiesList2EXT;
    using api_element = schema::api_type::vulkan::VkDrmFormatModifierPropertiesList2EXT;

    VkDrmFormatModifierPropertiesList2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDrmFormatModifierProperties2EXT>* pDrmFormatModifierProperties{ nullptr };
};

struct Decoded_VkValidationCacheCreateInfoEXT
{
    using struct_type = VkValidationCacheCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkValidationCacheCreateInfoEXT;

    VkValidationCacheCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pInitialData;
};

struct Decoded_VkShaderModuleValidationCacheCreateInfoEXT
{
    using struct_type = VkShaderModuleValidationCacheCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkShaderModuleValidationCacheCreateInfoEXT;

    VkShaderModuleValidationCacheCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId validationCache{ format::kNullHandleId };
};

struct Decoded_VkShadingRatePaletteNV
{
    using struct_type = VkShadingRatePaletteNV;
    using api_element = schema::api_type::vulkan::VkShadingRatePaletteNV;

    VkShadingRatePaletteNV* decoded_value{ nullptr };

    PointerDecoder<VkShadingRatePaletteEntryNV> pShadingRatePaletteEntries;
};

struct Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV
{
    using struct_type = VkPipelineViewportShadingRateImageStateCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineViewportShadingRateImageStateCreateInfoNV;

    VkPipelineViewportShadingRateImageStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes{ nullptr };
};

struct Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV
{
    using struct_type = VkPhysicalDeviceShadingRateImageFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShadingRateImageFeaturesNV;

    VkPhysicalDeviceShadingRateImageFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV
{
    using struct_type = VkPhysicalDeviceShadingRateImagePropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShadingRateImagePropertiesNV;

    VkPhysicalDeviceShadingRateImagePropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* shadingRateTexelSize{ nullptr };
};

struct Decoded_VkCoarseSampleLocationNV
{
    using struct_type = VkCoarseSampleLocationNV;
    using api_element = schema::api_type::vulkan::VkCoarseSampleLocationNV;

    VkCoarseSampleLocationNV* decoded_value{ nullptr };
};

struct Decoded_VkCoarseSampleOrderCustomNV
{
    using struct_type = VkCoarseSampleOrderCustomNV;
    using api_element = schema::api_type::vulkan::VkCoarseSampleOrderCustomNV;

    VkCoarseSampleOrderCustomNV* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkCoarseSampleLocationNV>* pSampleLocations{ nullptr };
};

struct Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV
{
    using struct_type = VkPipelineViewportCoarseSampleOrderStateCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineViewportCoarseSampleOrderStateCreateInfoNV;

    VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders{ nullptr };
};

struct Decoded_VkRayTracingShaderGroupCreateInfoNV
{
    using struct_type = VkRayTracingShaderGroupCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkRayTracingShaderGroupCreateInfoNV;

    VkRayTracingShaderGroupCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRayTracingPipelineCreateInfoNV
{
    using struct_type = VkRayTracingPipelineCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkRayTracingPipelineCreateInfoNV;

    VkRayTracingPipelineCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>* pStages{ nullptr };
    StructPointerDecoder<Decoded_VkRayTracingShaderGroupCreateInfoNV>* pGroups{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    format::HandleId basePipelineHandle{ format::kNullHandleId };
};

struct Decoded_VkGeometryTrianglesNV
{
    using struct_type = VkGeometryTrianglesNV;
    using api_element = schema::api_type::vulkan::VkGeometryTrianglesNV;

    VkGeometryTrianglesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId vertexData{ format::kNullHandleId };
    format::HandleId indexData{ format::kNullHandleId };
    format::HandleId transformData{ format::kNullHandleId };
};

struct Decoded_VkGeometryAABBNV
{
    using struct_type = VkGeometryAABBNV;
    using api_element = schema::api_type::vulkan::VkGeometryAABBNV;

    VkGeometryAABBNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId aabbData{ format::kNullHandleId };
};

struct Decoded_VkGeometryDataNV
{
    using struct_type = VkGeometryDataNV;
    using api_element = schema::api_type::vulkan::VkGeometryDataNV;

    VkGeometryDataNV* decoded_value{ nullptr };

    Decoded_VkGeometryTrianglesNV* triangles{ nullptr };
    Decoded_VkGeometryAABBNV* aabbs{ nullptr };
};

struct Decoded_VkGeometryNV
{
    using struct_type = VkGeometryNV;
    using api_element = schema::api_type::vulkan::VkGeometryNV;

    VkGeometryNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkGeometryDataNV* geometry{ nullptr };
};

struct Decoded_VkAccelerationStructureInfoNV
{
    using struct_type = VkAccelerationStructureInfoNV;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureInfoNV;

    VkAccelerationStructureInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkGeometryNV>* pGeometries{ nullptr };
};

struct Decoded_VkAccelerationStructureCreateInfoNV
{
    using struct_type = VkAccelerationStructureCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureCreateInfoNV;

    VkAccelerationStructureCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkAccelerationStructureInfoNV* info{ nullptr };
};

struct Decoded_VkBindAccelerationStructureMemoryInfoNV
{
    using struct_type = VkBindAccelerationStructureMemoryInfoNV;
    using api_element = schema::api_type::vulkan::VkBindAccelerationStructureMemoryInfoNV;

    VkBindAccelerationStructureMemoryInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId accelerationStructure{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
    PointerDecoder<uint32_t> pDeviceIndices;
};

struct Decoded_VkWriteDescriptorSetAccelerationStructureNV
{
    using struct_type = VkWriteDescriptorSetAccelerationStructureNV;
    using api_element = schema::api_type::vulkan::VkWriteDescriptorSetAccelerationStructureNV;

    VkWriteDescriptorSetAccelerationStructureNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructures;
};

struct Decoded_VkAccelerationStructureMemoryRequirementsInfoNV
{
    using struct_type = VkAccelerationStructureMemoryRequirementsInfoNV;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureMemoryRequirementsInfoNV;

    VkAccelerationStructureMemoryRequirementsInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId accelerationStructure{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceRayTracingPropertiesNV
{
    using struct_type = VkPhysicalDeviceRayTracingPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingPropertiesNV;

    VkPhysicalDeviceRayTracingPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTransformMatrixKHR
{
    using struct_type = VkTransformMatrixKHR;
    using api_element = schema::api_type::vulkan::VkTransformMatrixKHR;

    VkTransformMatrixKHR* decoded_value{ nullptr };

    PointerDecoder<float> matrix;
};

struct Decoded_VkAabbPositionsKHR
{
    using struct_type = VkAabbPositionsKHR;
    using api_element = schema::api_type::vulkan::VkAabbPositionsKHR;

    VkAabbPositionsKHR* decoded_value{ nullptr };
};

struct Decoded_VkAccelerationStructureInstanceKHR
{
    using struct_type = VkAccelerationStructureInstanceKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureInstanceKHR;

    VkAccelerationStructureInstanceKHR* decoded_value{ nullptr };

    Decoded_VkTransformMatrixKHR* transform{ nullptr };
};

struct Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV
{
    using struct_type = VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV;

    VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV
{
    using struct_type = VkPipelineRepresentativeFragmentTestStateCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineRepresentativeFragmentTestStateCreateInfoNV;

    VkPipelineRepresentativeFragmentTestStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT
{
    using struct_type = VkPhysicalDeviceImageViewImageFormatInfoEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageViewImageFormatInfoEXT;

    VkPhysicalDeviceImageViewImageFormatInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT
{
    using struct_type = VkFilterCubicImageViewImageFormatPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkFilterCubicImageViewImageFormatPropertiesEXT;

    VkFilterCubicImageViewImageFormatPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM;

    VkPhysicalDeviceCooperativeMatrixConversionFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM;

    VkPhysicalDeviceElapsedTimerQueryFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImportMemoryHostPointerInfoEXT
{
    using struct_type = VkImportMemoryHostPointerInfoEXT;
    using api_element = schema::api_type::vulkan::VkImportMemoryHostPointerInfoEXT;

    VkImportMemoryHostPointerInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pHostPointer{ 0 };
};

struct Decoded_VkMemoryHostPointerPropertiesEXT
{
    using struct_type = VkMemoryHostPointerPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkMemoryHostPointerPropertiesEXT;

    VkMemoryHostPointerPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT
{
    using struct_type = VkPhysicalDeviceExternalMemoryHostPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExternalMemoryHostPropertiesEXT;

    VkPhysicalDeviceExternalMemoryHostPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCompilerControlCreateInfoAMD
{
    using struct_type = VkPipelineCompilerControlCreateInfoAMD;
    using api_element = schema::api_type::vulkan::VkPipelineCompilerControlCreateInfoAMD;

    VkPipelineCompilerControlCreateInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderCorePropertiesAMD
{
    using struct_type = VkPhysicalDeviceShaderCorePropertiesAMD;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderCorePropertiesAMD;

    VkPhysicalDeviceShaderCorePropertiesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceMemoryOverallocationCreateInfoAMD
{
    using struct_type = VkDeviceMemoryOverallocationCreateInfoAMD;
    using api_element = schema::api_type::vulkan::VkDeviceMemoryOverallocationCreateInfoAMD;

    VkDeviceMemoryOverallocationCreateInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;

    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPresentFrameTokenGGP
{
    using struct_type = VkPresentFrameTokenGGP;
    using api_element = schema::api_type::vulkan::VkPresentFrameTokenGGP;

    VkPresentFrameTokenGGP* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMeshShaderFeaturesNV
{
    using struct_type = VkPhysicalDeviceMeshShaderFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMeshShaderFeaturesNV;

    VkPhysicalDeviceMeshShaderFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMeshShaderPropertiesNV
{
    using struct_type = VkPhysicalDeviceMeshShaderPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMeshShaderPropertiesNV;

    VkPhysicalDeviceMeshShaderPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> maxTaskWorkGroupSize;
    PointerDecoder<uint32_t> maxMeshWorkGroupSize;
};

struct Decoded_VkDrawMeshTasksIndirectCommandNV
{
    using struct_type = VkDrawMeshTasksIndirectCommandNV;
    using api_element = schema::api_type::vulkan::VkDrawMeshTasksIndirectCommandNV;

    VkDrawMeshTasksIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV
{
    using struct_type = VkPhysicalDeviceShaderImageFootprintFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderImageFootprintFeaturesNV;

    VkPhysicalDeviceShaderImageFootprintFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV
{
    using struct_type = VkPipelineViewportExclusiveScissorStateCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineViewportExclusiveScissorStateCreateInfoNV;

    VkPipelineViewportExclusiveScissorStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pExclusiveScissors{ nullptr };
};

struct Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV
{
    using struct_type = VkPhysicalDeviceExclusiveScissorFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExclusiveScissorFeaturesNV;

    VkPhysicalDeviceExclusiveScissorFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyCheckpointPropertiesNV
{
    using struct_type = VkQueueFamilyCheckpointPropertiesNV;
    using api_element = schema::api_type::vulkan::VkQueueFamilyCheckpointPropertiesNV;

    VkQueueFamilyCheckpointPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCheckpointDataNV
{
    using struct_type = VkCheckpointDataNV;
    using api_element = schema::api_type::vulkan::VkCheckpointDataNV;

    VkCheckpointDataNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pCheckpointMarker{ 0 };
};

struct Decoded_VkQueueFamilyCheckpointProperties2NV
{
    using struct_type = VkQueueFamilyCheckpointProperties2NV;
    using api_element = schema::api_type::vulkan::VkQueueFamilyCheckpointProperties2NV;

    VkQueueFamilyCheckpointProperties2NV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCheckpointData2NV
{
    using struct_type = VkCheckpointData2NV;
    using api_element = schema::api_type::vulkan::VkCheckpointData2NV;

    VkCheckpointData2NV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pCheckpointMarker{ 0 };
};

struct Decoded_VkPhysicalDevicePresentTimingFeaturesEXT
{
    using struct_type = VkPhysicalDevicePresentTimingFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePresentTimingFeaturesEXT;

    VkPhysicalDevicePresentTimingFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPresentTimingSurfaceCapabilitiesEXT
{
    using struct_type = VkPresentTimingSurfaceCapabilitiesEXT;
    using api_element = schema::api_type::vulkan::VkPresentTimingSurfaceCapabilitiesEXT;

    VkPresentTimingSurfaceCapabilitiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainCalibratedTimestampInfoEXT
{
    using struct_type = VkSwapchainCalibratedTimestampInfoEXT;
    using api_element = schema::api_type::vulkan::VkSwapchainCalibratedTimestampInfoEXT;

    VkSwapchainCalibratedTimestampInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId swapchain{ format::kNullHandleId };
};

struct Decoded_VkSwapchainTimingPropertiesEXT
{
    using struct_type = VkSwapchainTimingPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkSwapchainTimingPropertiesEXT;

    VkSwapchainTimingPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainTimeDomainPropertiesEXT
{
    using struct_type = VkSwapchainTimeDomainPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkSwapchainTimeDomainPropertiesEXT;

    VkSwapchainTimeDomainPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkTimeDomainKHR> pTimeDomains;
    PointerDecoder<uint64_t> pTimeDomainIds;
};

struct Decoded_VkPastPresentationTimingInfoEXT
{
    using struct_type = VkPastPresentationTimingInfoEXT;
    using api_element = schema::api_type::vulkan::VkPastPresentationTimingInfoEXT;

    VkPastPresentationTimingInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId swapchain{ format::kNullHandleId };
};

struct Decoded_VkPresentStageTimeEXT
{
    using struct_type = VkPresentStageTimeEXT;
    using api_element = schema::api_type::vulkan::VkPresentStageTimeEXT;

    VkPresentStageTimeEXT* decoded_value{ nullptr };
};

struct Decoded_VkPastPresentationTimingEXT
{
    using struct_type = VkPastPresentationTimingEXT;
    using api_element = schema::api_type::vulkan::VkPastPresentationTimingEXT;

    VkPastPresentationTimingEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPresentStageTimeEXT>* pPresentStages{ nullptr };
};

struct Decoded_VkPastPresentationTimingPropertiesEXT
{
    using struct_type = VkPastPresentationTimingPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPastPresentationTimingPropertiesEXT;

    VkPastPresentationTimingPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPastPresentationTimingEXT>* pPresentationTimings{ nullptr };
};

struct Decoded_VkPresentTimingInfoEXT
{
    using struct_type = VkPresentTimingInfoEXT;
    using api_element = schema::api_type::vulkan::VkPresentTimingInfoEXT;

    VkPresentTimingInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPresentTimingsInfoEXT
{
    using struct_type = VkPresentTimingsInfoEXT;
    using api_element = schema::api_type::vulkan::VkPresentTimingsInfoEXT;

    VkPresentTimingsInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPresentTimingInfoEXT>* pTimingInfos{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL
{
    using struct_type = VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL;

    VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkInitializePerformanceApiInfoINTEL
{
    using struct_type = VkInitializePerformanceApiInfoINTEL;
    using api_element = schema::api_type::vulkan::VkInitializePerformanceApiInfoINTEL;

    VkInitializePerformanceApiInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL
{
    using struct_type = VkQueryPoolPerformanceQueryCreateInfoINTEL;
    using api_element = schema::api_type::vulkan::VkQueryPoolPerformanceQueryCreateInfoINTEL;

    VkQueryPoolPerformanceQueryCreateInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceMarkerInfoINTEL
{
    using struct_type = VkPerformanceMarkerInfoINTEL;
    using api_element = schema::api_type::vulkan::VkPerformanceMarkerInfoINTEL;

    VkPerformanceMarkerInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceStreamMarkerInfoINTEL
{
    using struct_type = VkPerformanceStreamMarkerInfoINTEL;
    using api_element = schema::api_type::vulkan::VkPerformanceStreamMarkerInfoINTEL;

    VkPerformanceStreamMarkerInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceOverrideInfoINTEL
{
    using struct_type = VkPerformanceOverrideInfoINTEL;
    using api_element = schema::api_type::vulkan::VkPerformanceOverrideInfoINTEL;

    VkPerformanceOverrideInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceConfigurationAcquireInfoINTEL
{
    using struct_type = VkPerformanceConfigurationAcquireInfoINTEL;
    using api_element = schema::api_type::vulkan::VkPerformanceConfigurationAcquireInfoINTEL;

    VkPerformanceConfigurationAcquireInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT
{
    using struct_type = VkPhysicalDevicePCIBusInfoPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePCIBusInfoPropertiesEXT;

    VkPhysicalDevicePCIBusInfoPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD
{
    using struct_type = VkDisplayNativeHdrSurfaceCapabilitiesAMD;
    using api_element = schema::api_type::vulkan::VkDisplayNativeHdrSurfaceCapabilitiesAMD;

    VkDisplayNativeHdrSurfaceCapabilitiesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD
{
    using struct_type = VkSwapchainDisplayNativeHdrCreateInfoAMD;
    using api_element = schema::api_type::vulkan::VkSwapchainDisplayNativeHdrCreateInfoAMD;

    VkSwapchainDisplayNativeHdrCreateInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA
{
    using struct_type = VkImagePipeSurfaceCreateInfoFUCHSIA;
    using api_element = schema::api_type::vulkan::VkImagePipeSurfaceCreateInfoFUCHSIA;

    VkImagePipeSurfaceCreateInfoFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMetalSurfaceCreateInfoEXT
{
    using struct_type = VkMetalSurfaceCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkMetalSurfaceCreateInfoEXT;

    VkMetalSurfaceCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pLayer{ 0 };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentDensityMapFeaturesEXT;

    VkPhysicalDeviceFragmentDensityMapFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentDensityMapPropertiesEXT;

    VkPhysicalDeviceFragmentDensityMapPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* minFragmentDensityTexelSize{ nullptr };
    Decoded_VkExtent2D* maxFragmentDensityTexelSize{ nullptr };
};

struct Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT
{
    using struct_type = VkRenderPassFragmentDensityMapCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkRenderPassFragmentDensityMapCreateInfoEXT;

    VkRenderPassFragmentDensityMapCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkAttachmentReference* fragmentDensityMapAttachment{ nullptr };
};

struct Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT
{
    using struct_type = VkRenderingFragmentDensityMapAttachmentInfoEXT;
    using api_element = schema::api_type::vulkan::VkRenderingFragmentDensityMapAttachmentInfoEXT;

    VkRenderingFragmentDensityMapAttachmentInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId imageView{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceShaderCoreProperties2AMD
{
    using struct_type = VkPhysicalDeviceShaderCoreProperties2AMD;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderCoreProperties2AMD;

    VkPhysicalDeviceShaderCoreProperties2AMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD
{
    using struct_type = VkPhysicalDeviceCoherentMemoryFeaturesAMD;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCoherentMemoryFeaturesAMD;

    VkPhysicalDeviceCoherentMemoryFeaturesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT;

    VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMemoryBudgetPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMemoryBudgetPropertiesEXT;

    VkPhysicalDeviceMemoryBudgetPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkDeviceSize> heapBudget;
    PointerDecoder<VkDeviceSize> heapUsage;
};

struct Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMemoryPriorityFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMemoryPriorityFeaturesEXT;

    VkPhysicalDeviceMemoryPriorityFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryPriorityAllocateInfoEXT
{
    using struct_type = VkMemoryPriorityAllocateInfoEXT;
    using api_element = schema::api_type::vulkan::VkMemoryPriorityAllocateInfoEXT;

    VkMemoryPriorityAllocateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV
{
    using struct_type = VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;

    VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBufferDeviceAddressFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceBufferDeviceAddressFeaturesEXT;

    VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferDeviceAddressCreateInfoEXT
{
    using struct_type = VkBufferDeviceAddressCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkBufferDeviceAddressCreateInfoEXT;

    VkBufferDeviceAddressCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkValidationFeaturesEXT
{
    using struct_type = VkValidationFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkValidationFeaturesEXT;

    VkValidationFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkValidationFeatureEnableEXT> pEnabledValidationFeatures;
    PointerDecoder<VkValidationFeatureDisableEXT> pDisabledValidationFeatures;
};

struct Decoded_VkCooperativeMatrixPropertiesNV
{
    using struct_type = VkCooperativeMatrixPropertiesNV;
    using api_element = schema::api_type::vulkan::VkCooperativeMatrixPropertiesNV;

    VkCooperativeMatrixPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeMatrixFeaturesNV;

    VkPhysicalDeviceCooperativeMatrixFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeMatrixPropertiesNV;

    VkPhysicalDeviceCooperativeMatrixPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV
{
    using struct_type = VkPhysicalDeviceCoverageReductionModeFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCoverageReductionModeFeaturesNV;

    VkPhysicalDeviceCoverageReductionModeFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCoverageReductionStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageReductionStateCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineCoverageReductionStateCreateInfoNV;

    VkPipelineCoverageReductionStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFramebufferMixedSamplesCombinationNV
{
    using struct_type = VkFramebufferMixedSamplesCombinationNV;
    using api_element = schema::api_type::vulkan::VkFramebufferMixedSamplesCombinationNV;

    VkFramebufferMixedSamplesCombinationNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT;

    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT
{
    using struct_type = VkPhysicalDeviceYcbcrImageArraysFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceYcbcrImageArraysFeaturesEXT;

    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT
{
    using struct_type = VkPhysicalDeviceProvokingVertexFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceProvokingVertexFeaturesEXT;

    VkPhysicalDeviceProvokingVertexFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT
{
    using struct_type = VkPhysicalDeviceProvokingVertexPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceProvokingVertexPropertiesEXT;

    VkPhysicalDeviceProvokingVertexPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationProvokingVertexStateCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineRasterizationProvokingVertexStateCreateInfoEXT;

    VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceFullScreenExclusiveInfoEXT
{
    using struct_type = VkSurfaceFullScreenExclusiveInfoEXT;
    using api_element = schema::api_type::vulkan::VkSurfaceFullScreenExclusiveInfoEXT;

    VkSurfaceFullScreenExclusiveInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT
{
    using struct_type = VkSurfaceCapabilitiesFullScreenExclusiveEXT;
    using api_element = schema::api_type::vulkan::VkSurfaceCapabilitiesFullScreenExclusiveEXT;

    VkSurfaceCapabilitiesFullScreenExclusiveEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT
{
    using struct_type = VkSurfaceFullScreenExclusiveWin32InfoEXT;
    using api_element = schema::api_type::vulkan::VkSurfaceFullScreenExclusiveWin32InfoEXT;

    VkSurfaceFullScreenExclusiveWin32InfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t hmonitor{ 0 };
};

struct Decoded_VkHeadlessSurfaceCreateInfoEXT
{
    using struct_type = VkHeadlessSurfaceCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkHeadlessSurfaceCreateInfoEXT;

    VkHeadlessSurfaceCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderAtomicFloatFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderAtomicFloatFeaturesEXT;

    VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT
{
    using struct_type = VkPhysicalDeviceExtendedDynamicStateFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExtendedDynamicStateFeaturesEXT;

    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMapMemoryPlacedFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMapMemoryPlacedFeaturesEXT;

    VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMapMemoryPlacedPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMapMemoryPlacedPropertiesEXT;

    VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryMapPlacedInfoEXT
{
    using struct_type = VkMemoryMapPlacedInfoEXT;
    using api_element = schema::api_type::vulkan::VkMemoryMapPlacedInfoEXT;

    VkMemoryMapPlacedInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pPlacedAddress{ 0 };
};

struct Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT;

    VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV
{
    using struct_type = VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV;

    VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV
{
    using struct_type = VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV;

    VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkGraphicsShaderGroupCreateInfoNV
{
    using struct_type = VkGraphicsShaderGroupCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkGraphicsShaderGroupCreateInfoNV;

    VkGraphicsShaderGroupCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>* pStages{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineVertexInputStateCreateInfo>* pVertexInputState{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineTessellationStateCreateInfo>* pTessellationState{ nullptr };
};

struct Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV
{
    using struct_type = VkGraphicsPipelineShaderGroupsCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkGraphicsPipelineShaderGroupsCreateInfoNV;

    VkGraphicsPipelineShaderGroupsCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkGraphicsShaderGroupCreateInfoNV>* pGroups{ nullptr };
    HandlePointerDecoder<VkPipeline> pPipelines;
};

struct Decoded_VkBindShaderGroupIndirectCommandNV
{
    using struct_type = VkBindShaderGroupIndirectCommandNV;
    using api_element = schema::api_type::vulkan::VkBindShaderGroupIndirectCommandNV;

    VkBindShaderGroupIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkBindIndexBufferIndirectCommandNV
{
    using struct_type = VkBindIndexBufferIndirectCommandNV;
    using api_element = schema::api_type::vulkan::VkBindIndexBufferIndirectCommandNV;

    VkBindIndexBufferIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkBindVertexBufferIndirectCommandNV
{
    using struct_type = VkBindVertexBufferIndirectCommandNV;
    using api_element = schema::api_type::vulkan::VkBindVertexBufferIndirectCommandNV;

    VkBindVertexBufferIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkSetStateFlagsIndirectCommandNV
{
    using struct_type = VkSetStateFlagsIndirectCommandNV;
    using api_element = schema::api_type::vulkan::VkSetStateFlagsIndirectCommandNV;

    VkSetStateFlagsIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkIndirectCommandsStreamNV
{
    using struct_type = VkIndirectCommandsStreamNV;
    using api_element = schema::api_type::vulkan::VkIndirectCommandsStreamNV;

    VkIndirectCommandsStreamNV* decoded_value{ nullptr };

    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkIndirectCommandsLayoutTokenNV
{
    using struct_type = VkIndirectCommandsLayoutTokenNV;
    using api_element = schema::api_type::vulkan::VkIndirectCommandsLayoutTokenNV;

    VkIndirectCommandsLayoutTokenNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pushconstantPipelineLayout{ format::kNullHandleId };
    PointerDecoder<VkIndexType> pIndexTypes;
    PointerDecoder<uint32_t> pIndexTypeValues;
};

struct Decoded_VkIndirectCommandsLayoutCreateInfoNV
{
    using struct_type = VkIndirectCommandsLayoutCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkIndirectCommandsLayoutCreateInfoNV;

    VkIndirectCommandsLayoutCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutTokenNV>* pTokens{ nullptr };
    PointerDecoder<uint32_t> pStreamStrides;
};

struct Decoded_VkGeneratedCommandsInfoNV
{
    using struct_type = VkGeneratedCommandsInfoNV;
    using api_element = schema::api_type::vulkan::VkGeneratedCommandsInfoNV;

    VkGeneratedCommandsInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
    format::HandleId indirectCommandsLayout{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkIndirectCommandsStreamNV>* pStreams{ nullptr };
    format::HandleId preprocessBuffer{ format::kNullHandleId };
    format::HandleId sequencesCountBuffer{ format::kNullHandleId };
    format::HandleId sequencesIndexBuffer{ format::kNullHandleId };
};

struct Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV
{
    using struct_type = VkGeneratedCommandsMemoryRequirementsInfoNV;
    using api_element = schema::api_type::vulkan::VkGeneratedCommandsMemoryRequirementsInfoNV;

    VkGeneratedCommandsMemoryRequirementsInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
    format::HandleId indirectCommandsLayout{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV
{
    using struct_type = VkPhysicalDeviceInheritedViewportScissorFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceInheritedViewportScissorFeaturesNV;

    VkPhysicalDeviceInheritedViewportScissorFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCommandBufferInheritanceViewportScissorInfoNV
{
    using struct_type = VkCommandBufferInheritanceViewportScissorInfoNV;
    using api_element = schema::api_type::vulkan::VkCommandBufferInheritanceViewportScissorInfoNV;

    VkCommandBufferInheritanceViewportScissorInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkViewport>* pViewportDepths{ nullptr };
};

struct Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT
{
    using struct_type = VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT;

    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderPassTransformBeginInfoQCOM
{
    using struct_type = VkRenderPassTransformBeginInfoQCOM;
    using api_element = schema::api_type::vulkan::VkRenderPassTransformBeginInfoQCOM;

    VkRenderPassTransformBeginInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM
{
    using struct_type = VkCommandBufferInheritanceRenderPassTransformInfoQCOM;
    using api_element = schema::api_type::vulkan::VkCommandBufferInheritanceRenderPassTransformInfoQCOM;

    VkCommandBufferInheritanceRenderPassTransformInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkRect2D* renderArea{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDepthBiasControlFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDepthBiasControlFeaturesEXT;

    VkPhysicalDeviceDepthBiasControlFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDepthBiasInfoEXT
{
    using struct_type = VkDepthBiasInfoEXT;
    using api_element = schema::api_type::vulkan::VkDepthBiasInfoEXT;

    VkDepthBiasInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDepthBiasRepresentationInfoEXT
{
    using struct_type = VkDepthBiasRepresentationInfoEXT;
    using api_element = schema::api_type::vulkan::VkDepthBiasRepresentationInfoEXT;

    VkDepthBiasRepresentationInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDeviceMemoryReportFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDeviceMemoryReportFeaturesEXT;

    VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceMemoryReportCallbackDataEXT
{
    using struct_type = VkDeviceMemoryReportCallbackDataEXT;
    using api_element = schema::api_type::vulkan::VkDeviceMemoryReportCallbackDataEXT;

    VkDeviceMemoryReportCallbackDataEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT
{
    using struct_type = VkDeviceDeviceMemoryReportCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkDeviceDeviceMemoryReportCreateInfoEXT;

    VkDeviceDeviceMemoryReportCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pfnUserCallback{ 0 };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkSamplerCustomBorderColorCreateInfoEXT
{
    using struct_type = VkSamplerCustomBorderColorCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkSamplerCustomBorderColorCreateInfoEXT;

    VkSamplerCustomBorderColorCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkClearColorValue* customBorderColor{ nullptr };
};

struct Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT
{
    using struct_type = VkPhysicalDeviceCustomBorderColorPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCustomBorderColorPropertiesEXT;

    VkPhysicalDeviceCustomBorderColorPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT
{
    using struct_type = VkPhysicalDeviceCustomBorderColorFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCustomBorderColorFeaturesEXT;

    VkPhysicalDeviceCustomBorderColorFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT
{
    using struct_type = VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT;

    VkPhysicalDeviceTextureCompressionASTC3DFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePresentBarrierFeaturesNV
{
    using struct_type = VkPhysicalDevicePresentBarrierFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePresentBarrierFeaturesNV;

    VkPhysicalDevicePresentBarrierFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceCapabilitiesPresentBarrierNV
{
    using struct_type = VkSurfaceCapabilitiesPresentBarrierNV;
    using api_element = schema::api_type::vulkan::VkSurfaceCapabilitiesPresentBarrierNV;

    VkSurfaceCapabilitiesPresentBarrierNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainPresentBarrierCreateInfoNV
{
    using struct_type = VkSwapchainPresentBarrierCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkSwapchainPresentBarrierCreateInfoNV;

    VkSwapchainPresentBarrierCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV
{
    using struct_type = VkPhysicalDeviceDiagnosticsConfigFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDiagnosticsConfigFeaturesNV;

    VkPhysicalDeviceDiagnosticsConfigFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceDiagnosticsConfigCreateInfoNV
{
    using struct_type = VkDeviceDiagnosticsConfigCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkDeviceDiagnosticsConfigCreateInfoNV;

    VkDeviceDiagnosticsConfigCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerfHintInfoQCOM
{
    using struct_type = VkPerfHintInfoQCOM;
    using api_element = schema::api_type::vulkan::VkPerfHintInfoQCOM;

    VkPerfHintInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceQueuePerfHintFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceQueuePerfHintFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceQueuePerfHintFeaturesQCOM;

    VkPhysicalDeviceQueuePerfHintFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceQueuePerfHintPropertiesQCOM
{
    using struct_type = VkPhysicalDeviceQueuePerfHintPropertiesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceQueuePerfHintPropertiesQCOM;

    VkPhysicalDeviceQueuePerfHintPropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageProcessing3FeaturesQCOM
{
    using struct_type = VkPhysicalDeviceImageProcessing3FeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageProcessing3FeaturesQCOM;

    VkPhysicalDeviceImageProcessing3FeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM;

    VkPhysicalDeviceShaderMultipleWaitQueuesFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM
{
    using struct_type = VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM;

    VkPhysicalDeviceShaderMultipleWaitQueuesPropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderSplitBarrierFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderSplitBarrierFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderSplitBarrierFeaturesEXT;

    VkPhysicalDeviceShaderSplitBarrierFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderSplitBarrierPropertiesEXT
{
    using struct_type = VkPhysicalDeviceShaderSplitBarrierPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderSplitBarrierPropertiesEXT;

    VkPhysicalDeviceShaderSplitBarrierPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTileShadingFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceTileShadingFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTileShadingFeaturesQCOM;

    VkPhysicalDeviceTileShadingFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTileShadingPropertiesQCOM
{
    using struct_type = VkPhysicalDeviceTileShadingPropertiesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTileShadingPropertiesQCOM;

    VkPhysicalDeviceTileShadingPropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* tileGranularity{ nullptr };
    Decoded_VkExtent2D* maxTileShadingRate{ nullptr };
};

struct Decoded_VkRenderPassTileShadingCreateInfoQCOM
{
    using struct_type = VkRenderPassTileShadingCreateInfoQCOM;
    using api_element = schema::api_type::vulkan::VkRenderPassTileShadingCreateInfoQCOM;

    VkRenderPassTileShadingCreateInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* tileApronSize{ nullptr };
};

struct Decoded_VkPerTileBeginInfoQCOM
{
    using struct_type = VkPerTileBeginInfoQCOM;
    using api_element = schema::api_type::vulkan::VkPerTileBeginInfoQCOM;

    VkPerTileBeginInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerTileEndInfoQCOM
{
    using struct_type = VkPerTileEndInfoQCOM;
    using api_element = schema::api_type::vulkan::VkPerTileEndInfoQCOM;

    VkPerTileEndInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDispatchTileInfoQCOM
{
    using struct_type = VkDispatchTileInfoQCOM;
    using api_element = schema::api_type::vulkan::VkDispatchTileInfoQCOM;

    VkDispatchTileInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDescriptorBufferPropertiesEXT
{
    using struct_type = VkPhysicalDeviceDescriptorBufferPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDescriptorBufferPropertiesEXT;

    VkPhysicalDeviceDescriptorBufferPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDescriptorBufferFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDescriptorBufferFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDescriptorBufferFeaturesEXT;

    VkPhysicalDeviceDescriptorBufferFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorAddressInfoEXT
{
    using struct_type = VkDescriptorAddressInfoEXT;
    using api_element = schema::api_type::vulkan::VkDescriptorAddressInfoEXT;

    VkDescriptorAddressInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorBufferBindingInfoEXT
{
    using struct_type = VkDescriptorBufferBindingInfoEXT;
    using api_element = schema::api_type::vulkan::VkDescriptorBufferBindingInfoEXT;

    VkDescriptorBufferBindingInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorBufferBindingPushDescriptorBufferHandleEXT
{
    using struct_type = VkDescriptorBufferBindingPushDescriptorBufferHandleEXT;
    using api_element = schema::api_type::vulkan::VkDescriptorBufferBindingPushDescriptorBufferHandleEXT;

    VkDescriptorBufferBindingPushDescriptorBufferHandleEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkBufferCaptureDescriptorDataInfoEXT
{
    using struct_type = VkBufferCaptureDescriptorDataInfoEXT;
    using api_element = schema::api_type::vulkan::VkBufferCaptureDescriptorDataInfoEXT;

    VkBufferCaptureDescriptorDataInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkImageCaptureDescriptorDataInfoEXT
{
    using struct_type = VkImageCaptureDescriptorDataInfoEXT;
    using api_element = schema::api_type::vulkan::VkImageCaptureDescriptorDataInfoEXT;

    VkImageCaptureDescriptorDataInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
};

struct Decoded_VkImageViewCaptureDescriptorDataInfoEXT
{
    using struct_type = VkImageViewCaptureDescriptorDataInfoEXT;
    using api_element = schema::api_type::vulkan::VkImageViewCaptureDescriptorDataInfoEXT;

    VkImageViewCaptureDescriptorDataInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId imageView{ format::kNullHandleId };
};

struct Decoded_VkSamplerCaptureDescriptorDataInfoEXT
{
    using struct_type = VkSamplerCaptureDescriptorDataInfoEXT;
    using api_element = schema::api_type::vulkan::VkSamplerCaptureDescriptorDataInfoEXT;

    VkSamplerCaptureDescriptorDataInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId sampler{ format::kNullHandleId };
};

struct Decoded_VkOpaqueCaptureDescriptorDataCreateInfoEXT
{
    using struct_type = VkOpaqueCaptureDescriptorDataCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkOpaqueCaptureDescriptorDataCreateInfoEXT;

    VkOpaqueCaptureDescriptorDataCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t opaqueCaptureDescriptorData{ 0 };
};

struct Decoded_VkAccelerationStructureCaptureDescriptorDataInfoEXT
{
    using struct_type = VkAccelerationStructureCaptureDescriptorDataInfoEXT;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureCaptureDescriptorDataInfoEXT;

    VkAccelerationStructureCaptureDescriptorDataInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId accelerationStructure{ format::kNullHandleId };
    format::HandleId accelerationStructureNV{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT
{
    using struct_type = VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT;

    VkPhysicalDeviceDescriptorBufferDensityMapPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT
{
    using struct_type = VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT;

    VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT
{
    using struct_type = VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT;

    VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkGraphicsPipelineLibraryCreateInfoEXT
{
    using struct_type = VkGraphicsPipelineLibraryCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkGraphicsPipelineLibraryCreateInfoEXT;

    VkGraphicsPipelineLibraryCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD
{
    using struct_type = VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD;

    VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV
{
    using struct_type = VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV;

    VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV
{
    using struct_type = VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV;

    VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV
{
    using struct_type = VkPipelineFragmentShadingRateEnumStateCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineFragmentShadingRateEnumStateCreateInfoNV;

    VkPipelineFragmentShadingRateEnumStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;
};

struct Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV
{
    using struct_type = VkAccelerationStructureGeometryMotionTrianglesDataNV;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureGeometryMotionTrianglesDataNV;

    VkAccelerationStructureGeometryMotionTrianglesDataNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* vertexData{ nullptr };
};

struct Decoded_VkAccelerationStructureMotionInfoNV
{
    using struct_type = VkAccelerationStructureMotionInfoNV;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureMotionInfoNV;

    VkAccelerationStructureMotionInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureMatrixMotionInstanceNV
{
    using struct_type = VkAccelerationStructureMatrixMotionInstanceNV;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureMatrixMotionInstanceNV;

    VkAccelerationStructureMatrixMotionInstanceNV* decoded_value{ nullptr };

    Decoded_VkTransformMatrixKHR* transformT0{ nullptr };
    Decoded_VkTransformMatrixKHR* transformT1{ nullptr };
};

struct Decoded_VkSRTDataNV
{
    using struct_type = VkSRTDataNV;
    using api_element = schema::api_type::vulkan::VkSRTDataNV;

    VkSRTDataNV* decoded_value{ nullptr };
};

struct Decoded_VkAccelerationStructureSRTMotionInstanceNV
{
    using struct_type = VkAccelerationStructureSRTMotionInstanceNV;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureSRTMotionInstanceNV;

    VkAccelerationStructureSRTMotionInstanceNV* decoded_value{ nullptr };

    Decoded_VkSRTDataNV* transformT0{ nullptr };
    Decoded_VkSRTDataNV* transformT1{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV
{
    using struct_type = VkPhysicalDeviceRayTracingMotionBlurFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingMotionBlurFeaturesNV;

    VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT
{
    using struct_type = VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT;

    VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMap2FeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentDensityMap2FeaturesEXT;

    VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMap2PropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentDensityMap2PropertiesEXT;

    VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCopyCommandTransformInfoQCOM
{
    using struct_type = VkCopyCommandTransformInfoQCOM;
    using api_element = schema::api_type::vulkan::VkCopyCommandTransformInfoQCOM;

    VkCopyCommandTransformInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImageCompressionControlFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageCompressionControlFeaturesEXT;

    VkPhysicalDeviceImageCompressionControlFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageCompressionControlEXT
{
    using struct_type = VkImageCompressionControlEXT;
    using api_element = schema::api_type::vulkan::VkImageCompressionControlEXT;

    VkImageCompressionControlEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkImageCompressionFixedRateFlagsEXT> pFixedRateFlags;
};

struct Decoded_VkImageCompressionPropertiesEXT
{
    using struct_type = VkImageCompressionPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkImageCompressionPropertiesEXT;

    VkImageCompressionPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT
{
    using struct_type = VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT;

    VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevice4444FormatsFeaturesEXT
{
    using struct_type = VkPhysicalDevice4444FormatsFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDevice4444FormatsFeaturesEXT;

    VkPhysicalDevice4444FormatsFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFaultFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFaultFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFaultFeaturesEXT;

    VkPhysicalDeviceFaultFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceFaultCountsEXT
{
    using struct_type = VkDeviceFaultCountsEXT;
    using api_element = schema::api_type::vulkan::VkDeviceFaultCountsEXT;

    VkDeviceFaultCountsEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceFaultInfoEXT
{
    using struct_type = VkDeviceFaultInfoEXT;
    using api_element = schema::api_type::vulkan::VkDeviceFaultInfoEXT;

    VkDeviceFaultInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder description;
    StructPointerDecoder<Decoded_VkDeviceFaultAddressInfoKHR>* pAddressInfos{ nullptr };
    StructPointerDecoder<Decoded_VkDeviceFaultVendorInfoKHR>* pVendorInfos{ nullptr };
    uint64_t pVendorBinaryData{ 0 };
};

struct Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT
{
    using struct_type = VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT;

    VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT
{
    using struct_type = VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT;

    VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDirectFBSurfaceCreateInfoEXT
{
    using struct_type = VkDirectFBSurfaceCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkDirectFBSurfaceCreateInfoEXT;

    VkDirectFBSurfaceCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t dfb{ 0 };
    uint64_t surface{ 0 };
};

struct Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT;

    VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMutableDescriptorTypeListEXT
{
    using struct_type = VkMutableDescriptorTypeListEXT;
    using api_element = schema::api_type::vulkan::VkMutableDescriptorTypeListEXT;

    VkMutableDescriptorTypeListEXT* decoded_value{ nullptr };

    PointerDecoder<VkDescriptorType> pDescriptorTypes;
};

struct Decoded_VkMutableDescriptorTypeCreateInfoEXT
{
    using struct_type = VkMutableDescriptorTypeCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkMutableDescriptorTypeCreateInfoEXT;

    VkMutableDescriptorTypeCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkMutableDescriptorTypeListEXT>* pMutableDescriptorTypeLists{ nullptr };
};

struct Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT
{
    using struct_type = VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT;

    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVertexInputBindingDescription2EXT
{
    using struct_type = VkVertexInputBindingDescription2EXT;
    using api_element = schema::api_type::vulkan::VkVertexInputBindingDescription2EXT;

    VkVertexInputBindingDescription2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVertexInputAttributeDescription2EXT
{
    using struct_type = VkVertexInputAttributeDescription2EXT;
    using api_element = schema::api_type::vulkan::VkVertexInputAttributeDescription2EXT;

    VkVertexInputAttributeDescription2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDrmPropertiesEXT
{
    using struct_type = VkPhysicalDeviceDrmPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDrmPropertiesEXT;

    VkPhysicalDeviceDrmPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT
{
    using struct_type = VkPhysicalDeviceAddressBindingReportFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceAddressBindingReportFeaturesEXT;

    VkPhysicalDeviceAddressBindingReportFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceAddressBindingCallbackDataEXT
{
    using struct_type = VkDeviceAddressBindingCallbackDataEXT;
    using api_element = schema::api_type::vulkan::VkDeviceAddressBindingCallbackDataEXT;

    VkDeviceAddressBindingCallbackDataEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDepthClipControlFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDepthClipControlFeaturesEXT;

    VkPhysicalDeviceDepthClipControlFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT
{
    using struct_type = VkPipelineViewportDepthClipControlCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineViewportDepthClipControlCreateInfoEXT;

    VkPipelineViewportDepthClipControlCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT
{
    using struct_type = VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT;

    VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImportMemoryZirconHandleInfoFUCHSIA
{
    using struct_type = VkImportMemoryZirconHandleInfoFUCHSIA;
    using api_element = schema::api_type::vulkan::VkImportMemoryZirconHandleInfoFUCHSIA;

    VkImportMemoryZirconHandleInfoFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryZirconHandlePropertiesFUCHSIA
{
    using struct_type = VkMemoryZirconHandlePropertiesFUCHSIA;
    using api_element = schema::api_type::vulkan::VkMemoryZirconHandlePropertiesFUCHSIA;

    VkMemoryZirconHandlePropertiesFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryGetZirconHandleInfoFUCHSIA
{
    using struct_type = VkMemoryGetZirconHandleInfoFUCHSIA;
    using api_element = schema::api_type::vulkan::VkMemoryGetZirconHandleInfoFUCHSIA;

    VkMemoryGetZirconHandleInfoFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA
{
    using struct_type = VkImportSemaphoreZirconHandleInfoFUCHSIA;
    using api_element = schema::api_type::vulkan::VkImportSemaphoreZirconHandleInfoFUCHSIA;

    VkImportSemaphoreZirconHandleInfoFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA
{
    using struct_type = VkSemaphoreGetZirconHandleInfoFUCHSIA;
    using api_element = schema::api_type::vulkan::VkSemaphoreGetZirconHandleInfoFUCHSIA;

    VkSemaphoreGetZirconHandleInfoFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI
{
    using struct_type = VkPhysicalDeviceInvocationMaskFeaturesHUAWEI;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceInvocationMaskFeaturesHUAWEI;

    VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryGetRemoteAddressInfoNV
{
    using struct_type = VkMemoryGetRemoteAddressInfoNV;
    using api_element = schema::api_type::vulkan::VkMemoryGetRemoteAddressInfoNV;

    VkMemoryGetRemoteAddressInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV
{
    using struct_type = VkPhysicalDeviceExternalMemoryRDMAFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExternalMemoryRDMAFeaturesNV;

    VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFrameBoundaryFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFrameBoundaryFeaturesEXT;

    VkPhysicalDeviceFrameBoundaryFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFrameBoundaryEXT
{
    using struct_type = VkFrameBoundaryEXT;
    using api_element = schema::api_type::vulkan::VkFrameBoundaryEXT;

    VkFrameBoundaryEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkImage> pImages;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT;

    VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSubpassResolvePerformanceQueryEXT
{
    using struct_type = VkSubpassResolvePerformanceQueryEXT;
    using api_element = schema::api_type::vulkan::VkSubpassResolvePerformanceQueryEXT;

    VkSubpassResolvePerformanceQueryEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMultisampledRenderToSingleSampledInfoEXT
{
    using struct_type = VkMultisampledRenderToSingleSampledInfoEXT;
    using api_element = schema::api_type::vulkan::VkMultisampledRenderToSingleSampledInfoEXT;

    VkMultisampledRenderToSingleSampledInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT
{
    using struct_type = VkPhysicalDeviceExtendedDynamicState2FeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExtendedDynamicState2FeaturesEXT;

    VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkScreenSurfaceCreateInfoQNX
{
    using struct_type = VkScreenSurfaceCreateInfoQNX;
    using api_element = schema::api_type::vulkan::VkScreenSurfaceCreateInfoQNX;

    VkScreenSurfaceCreateInfoQNX* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t context{ 0 };
    uint64_t window{ 0 };
};

struct Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT
{
    using struct_type = VkPhysicalDeviceColorWriteEnableFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceColorWriteEnableFeaturesEXT;

    VkPhysicalDeviceColorWriteEnableFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineColorWriteCreateInfoEXT
{
    using struct_type = VkPipelineColorWriteCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineColorWriteCreateInfoEXT;

    VkPipelineColorWriteCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkBool32> pColorWriteEnables;
};

struct Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT
{
    using struct_type = VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT;

    VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE
{
    using struct_type = VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE;

    VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeRgbConversionCapabilitiesVALVE
{
    using struct_type = VkVideoEncodeRgbConversionCapabilitiesVALVE;
    using api_element = schema::api_type::vulkan::VkVideoEncodeRgbConversionCapabilitiesVALVE;

    VkVideoEncodeRgbConversionCapabilitiesVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeProfileRgbConversionInfoVALVE
{
    using struct_type = VkVideoEncodeProfileRgbConversionInfoVALVE;
    using api_element = schema::api_type::vulkan::VkVideoEncodeProfileRgbConversionInfoVALVE;

    VkVideoEncodeProfileRgbConversionInfoVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeSessionRgbConversionCreateInfoVALVE
{
    using struct_type = VkVideoEncodeSessionRgbConversionCreateInfoVALVE;
    using api_element = schema::api_type::vulkan::VkVideoEncodeSessionRgbConversionCreateInfoVALVE;

    VkVideoEncodeSessionRgbConversionCreateInfoVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImageViewMinLodFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageViewMinLodFeaturesEXT;

    VkPhysicalDeviceImageViewMinLodFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageViewMinLodCreateInfoEXT
{
    using struct_type = VkImageViewMinLodCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkImageViewMinLodCreateInfoEXT;

    VkImageViewMinLodCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMultiDrawFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMultiDrawFeaturesEXT;

    VkPhysicalDeviceMultiDrawFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMultiDrawPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMultiDrawPropertiesEXT;

    VkPhysicalDeviceMultiDrawPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMultiDrawInfoEXT
{
    using struct_type = VkMultiDrawInfoEXT;
    using api_element = schema::api_type::vulkan::VkMultiDrawInfoEXT;

    VkMultiDrawInfoEXT* decoded_value{ nullptr };
};

struct Decoded_VkMultiDrawIndexedInfoEXT
{
    using struct_type = VkMultiDrawIndexedInfoEXT;
    using api_element = schema::api_type::vulkan::VkMultiDrawIndexedInfoEXT;

    VkMultiDrawIndexedInfoEXT* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImage2DViewOf3DFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImage2DViewOf3DFeaturesEXT;

    VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderTileImageFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderTileImageFeaturesEXT;

    VkPhysicalDeviceShaderTileImageFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT
{
    using struct_type = VkPhysicalDeviceShaderTileImagePropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderTileImagePropertiesEXT;

    VkPhysicalDeviceShaderTileImagePropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMicromapUsageEXT
{
    using struct_type = VkMicromapUsageEXT;
    using api_element = schema::api_type::vulkan::VkMicromapUsageEXT;

    VkMicromapUsageEXT* decoded_value{ nullptr };
};

struct Decoded_VkMicromapBuildInfoEXT
{
    using struct_type = VkMicromapBuildInfoEXT;
    using api_element = schema::api_type::vulkan::VkMicromapBuildInfoEXT;

    VkMicromapBuildInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId dstMicromap{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkMicromapUsageEXT>* pUsageCounts{ nullptr };
    StructPointerDecoder<Decoded_VkMicromapUsageEXT*>* ppUsageCounts{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* data{ nullptr };
    Decoded_VkDeviceOrHostAddressKHR* scratchData{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* triangleArray{ nullptr };
};

struct Decoded_VkMicromapCreateInfoEXT
{
    using struct_type = VkMicromapCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkMicromapCreateInfoEXT;

    VkMicromapCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT
{
    using struct_type = VkPhysicalDeviceOpacityMicromapFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceOpacityMicromapFeaturesEXT;

    VkPhysicalDeviceOpacityMicromapFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT
{
    using struct_type = VkPhysicalDeviceOpacityMicromapPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceOpacityMicromapPropertiesEXT;

    VkPhysicalDeviceOpacityMicromapPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMicromapVersionInfoEXT
{
    using struct_type = VkMicromapVersionInfoEXT;
    using api_element = schema::api_type::vulkan::VkMicromapVersionInfoEXT;

    VkMicromapVersionInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pVersionData;
};

struct Decoded_VkCopyMicromapToMemoryInfoEXT
{
    using struct_type = VkCopyMicromapToMemoryInfoEXT;
    using api_element = schema::api_type::vulkan::VkCopyMicromapToMemoryInfoEXT;

    VkCopyMicromapToMemoryInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId src{ format::kNullHandleId };
    Decoded_VkDeviceOrHostAddressKHR* dst{ nullptr };
};

struct Decoded_VkCopyMemoryToMicromapInfoEXT
{
    using struct_type = VkCopyMemoryToMicromapInfoEXT;
    using api_element = schema::api_type::vulkan::VkCopyMemoryToMicromapInfoEXT;

    VkCopyMemoryToMicromapInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* src{ nullptr };
    format::HandleId dst{ format::kNullHandleId };
};

struct Decoded_VkCopyMicromapInfoEXT
{
    using struct_type = VkCopyMicromapInfoEXT;
    using api_element = schema::api_type::vulkan::VkCopyMicromapInfoEXT;

    VkCopyMicromapInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId src{ format::kNullHandleId };
    format::HandleId dst{ format::kNullHandleId };
};

struct Decoded_VkMicromapBuildSizesInfoEXT
{
    using struct_type = VkMicromapBuildSizesInfoEXT;
    using api_element = schema::api_type::vulkan::VkMicromapBuildSizesInfoEXT;

    VkMicromapBuildSizesInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT
{
    using struct_type = VkAccelerationStructureTrianglesOpacityMicromapEXT;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureTrianglesOpacityMicromapEXT;

    VkAccelerationStructureTrianglesOpacityMicromapEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* indexBuffer{ nullptr };
    StructPointerDecoder<Decoded_VkMicromapUsageEXT>* pUsageCounts{ nullptr };
    StructPointerDecoder<Decoded_VkMicromapUsageEXT*>* ppUsageCounts{ nullptr };
    format::HandleId micromap{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV
{
    using struct_type = VkPhysicalDeviceDisplacementMicromapFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDisplacementMicromapFeaturesNV;

    VkPhysicalDeviceDisplacementMicromapFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV
{
    using struct_type = VkPhysicalDeviceDisplacementMicromapPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDisplacementMicromapPropertiesNV;

    VkPhysicalDeviceDisplacementMicromapPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV
{
    using struct_type = VkAccelerationStructureTrianglesDisplacementMicromapNV;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureTrianglesDisplacementMicromapNV;

    VkAccelerationStructureTrianglesDisplacementMicromapNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* displacementBiasAndScaleBuffer{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* displacementVectorBuffer{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* displacedMicromapPrimitiveFlags{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* indexBuffer{ nullptr };
    StructPointerDecoder<Decoded_VkMicromapUsageEXT>* pUsageCounts{ nullptr };
    StructPointerDecoder<Decoded_VkMicromapUsageEXT*>* ppUsageCounts{ nullptr };
    format::HandleId micromap{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI
{
    using struct_type = VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI;

    VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI
{
    using struct_type = VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI;

    VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> maxWorkGroupCount;
    PointerDecoder<uint32_t> maxWorkGroupSize;
};

struct Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI
{
    using struct_type = VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI;

    VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBorderColorSwizzleFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceBorderColorSwizzleFeaturesEXT;

    VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT
{
    using struct_type = VkSamplerBorderColorComponentMappingCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkSamplerBorderColorComponentMappingCreateInfoEXT;

    VkSamplerBorderColorComponentMappingCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkComponentMapping* components{ nullptr };
};

struct Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT
{
    using struct_type = VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT;

    VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderCorePropertiesARM
{
    using struct_type = VkPhysicalDeviceShaderCorePropertiesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderCorePropertiesARM;

    VkPhysicalDeviceShaderCorePropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM
{
    using struct_type = VkDeviceQueueShaderCoreControlCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDeviceQueueShaderCoreControlCreateInfoARM;

    VkDeviceQueueShaderCoreControlCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM
{
    using struct_type = VkPhysicalDeviceSchedulingControlsFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSchedulingControlsFeaturesARM;

    VkPhysicalDeviceSchedulingControlsFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM
{
    using struct_type = VkPhysicalDeviceSchedulingControlsPropertiesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSchedulingControlsPropertiesARM;

    VkPhysicalDeviceSchedulingControlsPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDispatchParametersARM
{
    using struct_type = VkDispatchParametersARM;
    using api_element = schema::api_type::vulkan::VkDispatchParametersARM;

    VkDispatchParametersARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM
{
    using struct_type = VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM;

    VkPhysicalDeviceSchedulingControlsDispatchParametersPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT;

    VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageViewSlicedCreateInfoEXT
{
    using struct_type = VkImageViewSlicedCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkImageViewSlicedCreateInfoEXT;

    VkImageViewSlicedCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE
{
    using struct_type = VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE;

    VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorSetBindingReferenceVALVE
{
    using struct_type = VkDescriptorSetBindingReferenceVALVE;
    using api_element = schema::api_type::vulkan::VkDescriptorSetBindingReferenceVALVE;

    VkDescriptorSetBindingReferenceVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId descriptorSetLayout{ format::kNullHandleId };
};

struct Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE
{
    using struct_type = VkDescriptorSetLayoutHostMappingInfoVALVE;
    using api_element = schema::api_type::vulkan::VkDescriptorSetLayoutHostMappingInfoVALVE;

    VkDescriptorSetLayoutHostMappingInfoVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT
{
    using struct_type = VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT;

    VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM
{
    using struct_type = VkPhysicalDeviceRenderPassStripedFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRenderPassStripedFeaturesARM;

    VkPhysicalDeviceRenderPassStripedFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM
{
    using struct_type = VkPhysicalDeviceRenderPassStripedPropertiesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRenderPassStripedPropertiesARM;

    VkPhysicalDeviceRenderPassStripedPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* renderPassStripeGranularity{ nullptr };
};

struct Decoded_VkRenderPassStripeInfoARM
{
    using struct_type = VkRenderPassStripeInfoARM;
    using api_element = schema::api_type::vulkan::VkRenderPassStripeInfoARM;

    VkRenderPassStripeInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkRect2D* stripeArea{ nullptr };
};

struct Decoded_VkRenderPassStripeBeginInfoARM
{
    using struct_type = VkRenderPassStripeBeginInfoARM;
    using api_element = schema::api_type::vulkan::VkRenderPassStripeBeginInfoARM;

    VkRenderPassStripeBeginInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRenderPassStripeInfoARM>* pStripeInfos{ nullptr };
};

struct Decoded_VkRenderPassStripeSubmitInfoARM
{
    using struct_type = VkRenderPassStripeSubmitInfoARM;
    using api_element = schema::api_type::vulkan::VkRenderPassStripeSubmitInfoARM;

    VkRenderPassStripeSubmitInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* pStripeSemaphoreInfos{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT;

    VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT;

    VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* fragmentDensityOffsetGranularity{ nullptr };
};

struct Decoded_VkRenderPassFragmentDensityMapOffsetEndInfoEXT
{
    using struct_type = VkRenderPassFragmentDensityMapOffsetEndInfoEXT;
    using api_element = schema::api_type::vulkan::VkRenderPassFragmentDensityMapOffsetEndInfoEXT;

    VkRenderPassFragmentDensityMapOffsetEndInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkOffset2D>* pFragmentDensityOffsets{ nullptr };
};

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV
{
    using struct_type = VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV;

    VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkComputePipelineIndirectBufferInfoNV
{
    using struct_type = VkComputePipelineIndirectBufferInfoNV;
    using api_element = schema::api_type::vulkan::VkComputePipelineIndirectBufferInfoNV;

    VkComputePipelineIndirectBufferInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineIndirectDeviceAddressInfoNV
{
    using struct_type = VkPipelineIndirectDeviceAddressInfoNV;
    using api_element = schema::api_type::vulkan::VkPipelineIndirectDeviceAddressInfoNV;

    VkPipelineIndirectDeviceAddressInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkBindPipelineIndirectCommandNV
{
    using struct_type = VkBindPipelineIndirectCommandNV;
    using api_element = schema::api_type::vulkan::VkBindPipelineIndirectCommandNV;

    VkBindPipelineIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV
{
    using struct_type = VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV;

    VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureGeometryLinearSweptSpheresDataNV
{
    using struct_type = VkAccelerationStructureGeometryLinearSweptSpheresDataNV;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureGeometryLinearSweptSpheresDataNV;

    VkAccelerationStructureGeometryLinearSweptSpheresDataNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* vertexData{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* radiusData{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* indexData{ nullptr };
};

struct Decoded_VkAccelerationStructureGeometrySpheresDataNV
{
    using struct_type = VkAccelerationStructureGeometrySpheresDataNV;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureGeometrySpheresDataNV;

    VkAccelerationStructureGeometrySpheresDataNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* vertexData{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* radiusData{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* indexData{ nullptr };
};

struct Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV
{
    using struct_type = VkPhysicalDeviceLinearColorAttachmentFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLinearColorAttachmentFeaturesNV;

    VkPhysicalDeviceLinearColorAttachmentFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT;

    VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageViewSampleWeightCreateInfoQCOM
{
    using struct_type = VkImageViewSampleWeightCreateInfoQCOM;
    using api_element = schema::api_type::vulkan::VkImageViewSampleWeightCreateInfoQCOM;

    VkImageViewSampleWeightCreateInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkOffset2D* filterCenter{ nullptr };
    Decoded_VkExtent2D* filterSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceImageProcessingFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageProcessingFeaturesQCOM;

    VkPhysicalDeviceImageProcessingFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM
{
    using struct_type = VkPhysicalDeviceImageProcessingPropertiesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageProcessingPropertiesQCOM;

    VkPhysicalDeviceImageProcessingPropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* maxWeightFilterDimension{ nullptr };
    Decoded_VkExtent2D* maxBlockMatchRegion{ nullptr };
    Decoded_VkExtent2D* maxBoxFilterBlockSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT
{
    using struct_type = VkPhysicalDeviceNestedCommandBufferFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceNestedCommandBufferFeaturesEXT;

    VkPhysicalDeviceNestedCommandBufferFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT
{
    using struct_type = VkPhysicalDeviceNestedCommandBufferPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceNestedCommandBufferPropertiesEXT;

    VkPhysicalDeviceNestedCommandBufferPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalMemoryAcquireUnmodifiedEXT
{
    using struct_type = VkExternalMemoryAcquireUnmodifiedEXT;
    using api_element = schema::api_type::vulkan::VkExternalMemoryAcquireUnmodifiedEXT;

    VkExternalMemoryAcquireUnmodifiedEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT
{
    using struct_type = VkPhysicalDeviceExtendedDynamicState3FeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExtendedDynamicState3FeaturesEXT;

    VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT
{
    using struct_type = VkPhysicalDeviceExtendedDynamicState3PropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExtendedDynamicState3PropertiesEXT;

    VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkColorBlendEquationEXT
{
    using struct_type = VkColorBlendEquationEXT;
    using api_element = schema::api_type::vulkan::VkColorBlendEquationEXT;

    VkColorBlendEquationEXT* decoded_value{ nullptr };
};

struct Decoded_VkColorBlendAdvancedEXT
{
    using struct_type = VkColorBlendAdvancedEXT;
    using api_element = schema::api_type::vulkan::VkColorBlendAdvancedEXT;

    VkColorBlendAdvancedEXT* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT
{
    using struct_type = VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT;

    VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderPassCreationControlEXT
{
    using struct_type = VkRenderPassCreationControlEXT;
    using api_element = schema::api_type::vulkan::VkRenderPassCreationControlEXT;

    VkRenderPassCreationControlEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderPassCreationFeedbackInfoEXT
{
    using struct_type = VkRenderPassCreationFeedbackInfoEXT;
    using api_element = schema::api_type::vulkan::VkRenderPassCreationFeedbackInfoEXT;

    VkRenderPassCreationFeedbackInfoEXT* decoded_value{ nullptr };
};

struct Decoded_VkRenderPassCreationFeedbackCreateInfoEXT
{
    using struct_type = VkRenderPassCreationFeedbackCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkRenderPassCreationFeedbackCreateInfoEXT;

    VkRenderPassCreationFeedbackCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRenderPassCreationFeedbackInfoEXT>* pRenderPassFeedback{ nullptr };
};

struct Decoded_VkRenderPassSubpassFeedbackInfoEXT
{
    using struct_type = VkRenderPassSubpassFeedbackInfoEXT;
    using api_element = schema::api_type::vulkan::VkRenderPassSubpassFeedbackInfoEXT;

    VkRenderPassSubpassFeedbackInfoEXT* decoded_value{ nullptr };

    StringDecoder description;
};

struct Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT
{
    using struct_type = VkRenderPassSubpassFeedbackCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkRenderPassSubpassFeedbackCreateInfoEXT;

    VkRenderPassSubpassFeedbackCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRenderPassSubpassFeedbackInfoEXT>* pSubpassFeedback{ nullptr };
};

struct Decoded_VkDirectDriverLoadingInfoLUNARG
{
    using struct_type = VkDirectDriverLoadingInfoLUNARG;
    using api_element = schema::api_type::vulkan::VkDirectDriverLoadingInfoLUNARG;

    VkDirectDriverLoadingInfoLUNARG* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pfnGetInstanceProcAddr{ 0 };
};

struct Decoded_VkDirectDriverLoadingListLUNARG
{
    using struct_type = VkDirectDriverLoadingListLUNARG;
    using api_element = schema::api_type::vulkan::VkDirectDriverLoadingListLUNARG;

    VkDirectDriverLoadingListLUNARG* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDirectDriverLoadingInfoLUNARG>* pDrivers{ nullptr };
};

struct Decoded_VkTensorDescriptionARM
{
    using struct_type = VkTensorDescriptionARM;
    using api_element = schema::api_type::vulkan::VkTensorDescriptionARM;

    VkTensorDescriptionARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<int64_t> pDimensions;
    PointerDecoder<int64_t> pStrides;
};

struct Decoded_VkTensorCreateInfoARM
{
    using struct_type = VkTensorCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkTensorCreateInfoARM;

    VkTensorCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkTensorDescriptionARM>* pDescription{ nullptr };
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkTensorViewCreateInfoARM
{
    using struct_type = VkTensorViewCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkTensorViewCreateInfoARM;

    VkTensorViewCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId tensor{ format::kNullHandleId };
};

struct Decoded_VkTensorMemoryRequirementsInfoARM
{
    using struct_type = VkTensorMemoryRequirementsInfoARM;
    using api_element = schema::api_type::vulkan::VkTensorMemoryRequirementsInfoARM;

    VkTensorMemoryRequirementsInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId tensor{ format::kNullHandleId };
};

struct Decoded_VkBindTensorMemoryInfoARM
{
    using struct_type = VkBindTensorMemoryInfoARM;
    using api_element = schema::api_type::vulkan::VkBindTensorMemoryInfoARM;

    VkBindTensorMemoryInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId tensor{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkWriteDescriptorSetTensorARM
{
    using struct_type = VkWriteDescriptorSetTensorARM;
    using api_element = schema::api_type::vulkan::VkWriteDescriptorSetTensorARM;

    VkWriteDescriptorSetTensorARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkTensorViewARM> pTensorViews;
};

struct Decoded_VkTensorFormatPropertiesARM
{
    using struct_type = VkTensorFormatPropertiesARM;
    using api_element = schema::api_type::vulkan::VkTensorFormatPropertiesARM;

    VkTensorFormatPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTensorPropertiesARM
{
    using struct_type = VkPhysicalDeviceTensorPropertiesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTensorPropertiesARM;

    VkPhysicalDeviceTensorPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTensorMemoryBarrierARM
{
    using struct_type = VkTensorMemoryBarrierARM;
    using api_element = schema::api_type::vulkan::VkTensorMemoryBarrierARM;

    VkTensorMemoryBarrierARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId tensor{ format::kNullHandleId };
};

struct Decoded_VkTensorDependencyInfoARM
{
    using struct_type = VkTensorDependencyInfoARM;
    using api_element = schema::api_type::vulkan::VkTensorDependencyInfoARM;

    VkTensorDependencyInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkTensorMemoryBarrierARM>* pTensorMemoryBarriers{ nullptr };
};

struct Decoded_VkPhysicalDeviceTensorFeaturesARM
{
    using struct_type = VkPhysicalDeviceTensorFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTensorFeaturesARM;

    VkPhysicalDeviceTensorFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceTensorMemoryRequirementsARM
{
    using struct_type = VkDeviceTensorMemoryRequirementsARM;
    using api_element = schema::api_type::vulkan::VkDeviceTensorMemoryRequirementsARM;

    VkDeviceTensorMemoryRequirementsARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkTensorCreateInfoARM>* pCreateInfo{ nullptr };
};

struct Decoded_VkTensorCopyARM
{
    using struct_type = VkTensorCopyARM;
    using api_element = schema::api_type::vulkan::VkTensorCopyARM;

    VkTensorCopyARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint64_t> pSrcOffset;
    PointerDecoder<uint64_t> pDstOffset;
    PointerDecoder<uint64_t> pExtent;
};

struct Decoded_VkCopyTensorInfoARM
{
    using struct_type = VkCopyTensorInfoARM;
    using api_element = schema::api_type::vulkan::VkCopyTensorInfoARM;

    VkCopyTensorInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcTensor{ format::kNullHandleId };
    format::HandleId dstTensor{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkTensorCopyARM>* pRegions{ nullptr };
};

struct Decoded_VkMemoryDedicatedAllocateInfoTensorARM
{
    using struct_type = VkMemoryDedicatedAllocateInfoTensorARM;
    using api_element = schema::api_type::vulkan::VkMemoryDedicatedAllocateInfoTensorARM;

    VkMemoryDedicatedAllocateInfoTensorARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId tensor{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceExternalTensorInfoARM
{
    using struct_type = VkPhysicalDeviceExternalTensorInfoARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExternalTensorInfoARM;

    VkPhysicalDeviceExternalTensorInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkTensorDescriptionARM>* pDescription{ nullptr };
};

struct Decoded_VkExternalTensorPropertiesARM
{
    using struct_type = VkExternalTensorPropertiesARM;
    using api_element = schema::api_type::vulkan::VkExternalTensorPropertiesARM;

    VkExternalTensorPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExternalMemoryProperties* externalMemoryProperties{ nullptr };
};

struct Decoded_VkExternalMemoryTensorCreateInfoARM
{
    using struct_type = VkExternalMemoryTensorCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkExternalMemoryTensorCreateInfoARM;

    VkExternalMemoryTensorCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDescriptorBufferTensorFeaturesARM
{
    using struct_type = VkPhysicalDeviceDescriptorBufferTensorFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDescriptorBufferTensorFeaturesARM;

    VkPhysicalDeviceDescriptorBufferTensorFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDescriptorBufferTensorPropertiesARM
{
    using struct_type = VkPhysicalDeviceDescriptorBufferTensorPropertiesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDescriptorBufferTensorPropertiesARM;

    VkPhysicalDeviceDescriptorBufferTensorPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorGetTensorInfoARM
{
    using struct_type = VkDescriptorGetTensorInfoARM;
    using api_element = schema::api_type::vulkan::VkDescriptorGetTensorInfoARM;

    VkDescriptorGetTensorInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId tensorView{ format::kNullHandleId };
};

struct Decoded_VkTensorCaptureDescriptorDataInfoARM
{
    using struct_type = VkTensorCaptureDescriptorDataInfoARM;
    using api_element = schema::api_type::vulkan::VkTensorCaptureDescriptorDataInfoARM;

    VkTensorCaptureDescriptorDataInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId tensor{ format::kNullHandleId };
};

struct Decoded_VkTensorViewCaptureDescriptorDataInfoARM
{
    using struct_type = VkTensorViewCaptureDescriptorDataInfoARM;
    using api_element = schema::api_type::vulkan::VkTensorViewCaptureDescriptorDataInfoARM;

    VkTensorViewCaptureDescriptorDataInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId tensorView{ format::kNullHandleId };
};

struct Decoded_VkFrameBoundaryTensorsARM
{
    using struct_type = VkFrameBoundaryTensorsARM;
    using api_element = schema::api_type::vulkan::VkFrameBoundaryTensorsARM;

    VkFrameBoundaryTensorsARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkTensorARM> pTensors;
};

struct Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT;

    VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT
{
    using struct_type = VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT;

    VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> shaderModuleIdentifierAlgorithmUUID;
};

struct Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT
{
    using struct_type = VkPipelineShaderStageModuleIdentifierCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineShaderStageModuleIdentifierCreateInfoEXT;

    VkPipelineShaderStageModuleIdentifierCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pIdentifier;
};

struct Decoded_VkShaderModuleIdentifierEXT
{
    using struct_type = VkShaderModuleIdentifierEXT;
    using api_element = schema::api_type::vulkan::VkShaderModuleIdentifierEXT;

    VkShaderModuleIdentifierEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> identifier;
};

struct Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV
{
    using struct_type = VkPhysicalDeviceOpticalFlowFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceOpticalFlowFeaturesNV;

    VkPhysicalDeviceOpticalFlowFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV
{
    using struct_type = VkPhysicalDeviceOpticalFlowPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceOpticalFlowPropertiesNV;

    VkPhysicalDeviceOpticalFlowPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkOpticalFlowImageFormatInfoNV
{
    using struct_type = VkOpticalFlowImageFormatInfoNV;
    using api_element = schema::api_type::vulkan::VkOpticalFlowImageFormatInfoNV;

    VkOpticalFlowImageFormatInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkOpticalFlowImageFormatPropertiesNV
{
    using struct_type = VkOpticalFlowImageFormatPropertiesNV;
    using api_element = schema::api_type::vulkan::VkOpticalFlowImageFormatPropertiesNV;

    VkOpticalFlowImageFormatPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkOpticalFlowSessionCreateInfoNV
{
    using struct_type = VkOpticalFlowSessionCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkOpticalFlowSessionCreateInfoNV;

    VkOpticalFlowSessionCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV
{
    using struct_type = VkOpticalFlowSessionCreatePrivateDataInfoNV;
    using api_element = schema::api_type::vulkan::VkOpticalFlowSessionCreatePrivateDataInfoNV;

    VkOpticalFlowSessionCreatePrivateDataInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pPrivateData{ 0 };
};

struct Decoded_VkOpticalFlowExecuteInfoNV
{
    using struct_type = VkOpticalFlowExecuteInfoNV;
    using api_element = schema::api_type::vulkan::VkOpticalFlowExecuteInfoNV;

    VkOpticalFlowExecuteInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pRegions{ nullptr };
};

struct Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT
{
    using struct_type = VkPhysicalDeviceLegacyDitheringFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLegacyDitheringFeaturesEXT;

    VkPhysicalDeviceLegacyDitheringFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID
{
    using struct_type = VkPhysicalDeviceExternalFormatResolveFeaturesANDROID;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExternalFormatResolveFeaturesANDROID;

    VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID
{
    using struct_type = VkPhysicalDeviceExternalFormatResolvePropertiesANDROID;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExternalFormatResolvePropertiesANDROID;

    VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferFormatResolvePropertiesANDROID;
    using api_element = schema::api_type::vulkan::VkAndroidHardwareBufferFormatResolvePropertiesANDROID;

    VkAndroidHardwareBufferFormatResolvePropertiesANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceAntiLagFeaturesAMD
{
    using struct_type = VkPhysicalDeviceAntiLagFeaturesAMD;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceAntiLagFeaturesAMD;

    VkPhysicalDeviceAntiLagFeaturesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAntiLagPresentationInfoAMD
{
    using struct_type = VkAntiLagPresentationInfoAMD;
    using api_element = schema::api_type::vulkan::VkAntiLagPresentationInfoAMD;

    VkAntiLagPresentationInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAntiLagDataAMD
{
    using struct_type = VkAntiLagDataAMD;
    using api_element = schema::api_type::vulkan::VkAntiLagDataAMD;

    VkAntiLagDataAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAntiLagPresentationInfoAMD>* pPresentationInfo{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderObjectFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderObjectFeaturesEXT;

    VkPhysicalDeviceShaderObjectFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT
{
    using struct_type = VkPhysicalDeviceShaderObjectPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderObjectPropertiesEXT;

    VkPhysicalDeviceShaderObjectPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> shaderBinaryUUID;
};

struct Decoded_VkShaderCreateInfoEXT
{
    using struct_type = VkShaderCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkShaderCreateInfoEXT;

    VkShaderCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pCode;
    StringDecoder pName;
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
    StructPointerDecoder<Decoded_VkPushConstantRange>* pPushConstantRanges{ nullptr };
    StructPointerDecoder<Decoded_VkSpecializationInfo>* pSpecializationInfo{ nullptr };
};

struct Decoded_VkDepthClampRangeEXT
{
    using struct_type = VkDepthClampRangeEXT;
    using api_element = schema::api_type::vulkan::VkDepthClampRangeEXT;

    VkDepthClampRangeEXT* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceTilePropertiesFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTilePropertiesFeaturesQCOM;

    VkPhysicalDeviceTilePropertiesFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTilePropertiesQCOM
{
    using struct_type = VkTilePropertiesQCOM;
    using api_element = schema::api_type::vulkan::VkTilePropertiesQCOM;

    VkTilePropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent3D* tileSize{ nullptr };
    Decoded_VkExtent2D* apronSize{ nullptr };
    Decoded_VkOffset2D* origin{ nullptr };
};

struct Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC
{
    using struct_type = VkPhysicalDeviceAmigoProfilingFeaturesSEC;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceAmigoProfilingFeaturesSEC;

    VkPhysicalDeviceAmigoProfilingFeaturesSEC* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAmigoProfilingSubmitInfoSEC
{
    using struct_type = VkAmigoProfilingSubmitInfoSEC;
    using api_element = schema::api_type::vulkan::VkAmigoProfilingSubmitInfoSEC;

    VkAmigoProfilingSubmitInfoSEC* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM;

    VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV
{
    using struct_type = VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV;

    VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV
{
    using struct_type = VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV;

    VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeVectorPropertiesNV
{
    using struct_type = VkPhysicalDeviceCooperativeVectorPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeVectorPropertiesNV;

    VkPhysicalDeviceCooperativeVectorPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeVectorFeaturesNV
{
    using struct_type = VkPhysicalDeviceCooperativeVectorFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeVectorFeaturesNV;

    VkPhysicalDeviceCooperativeVectorFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCooperativeVectorPropertiesNV
{
    using struct_type = VkCooperativeVectorPropertiesNV;
    using api_element = schema::api_type::vulkan::VkCooperativeVectorPropertiesNV;

    VkCooperativeVectorPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkConvertCooperativeVectorMatrixInfoNV
{
    using struct_type = VkConvertCooperativeVectorMatrixInfoNV;
    using api_element = schema::api_type::vulkan::VkConvertCooperativeVectorMatrixInfoNV;

    VkConvertCooperativeVectorMatrixInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* srcData{ nullptr };
    PointerDecoder<size_t> pDstSize;
    Decoded_VkDeviceOrHostAddressKHR* dstData{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV
{
    using struct_type = VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV;

    VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV
{
    using struct_type = VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV;

    VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT
{
    using struct_type = VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT;

    VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT
{
    using struct_type = VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT;

    VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkLayerSettingsCreateInfoEXT
{
    using struct_type = VkLayerSettingsCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkLayerSettingsCreateInfoEXT;

    VkLayerSettingsCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkLayerSettingEXT>* pSettings{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM
{
    using struct_type = VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM;

    VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM
{
    using struct_type = VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM;

    VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT
{
    using struct_type = VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT;

    VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT;

    VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkLatencySleepModeInfoNV
{
    using struct_type = VkLatencySleepModeInfoNV;
    using api_element = schema::api_type::vulkan::VkLatencySleepModeInfoNV;

    VkLatencySleepModeInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkLatencySleepInfoNV
{
    using struct_type = VkLatencySleepInfoNV;
    using api_element = schema::api_type::vulkan::VkLatencySleepInfoNV;

    VkLatencySleepInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId signalSemaphore{ format::kNullHandleId };
};

struct Decoded_VkSetLatencyMarkerInfoNV
{
    using struct_type = VkSetLatencyMarkerInfoNV;
    using api_element = schema::api_type::vulkan::VkSetLatencyMarkerInfoNV;

    VkSetLatencyMarkerInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkLatencyTimingsFrameReportNV
{
    using struct_type = VkLatencyTimingsFrameReportNV;
    using api_element = schema::api_type::vulkan::VkLatencyTimingsFrameReportNV;

    VkLatencyTimingsFrameReportNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkGetLatencyMarkerInfoNV
{
    using struct_type = VkGetLatencyMarkerInfoNV;
    using api_element = schema::api_type::vulkan::VkGetLatencyMarkerInfoNV;

    VkGetLatencyMarkerInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkLatencyTimingsFrameReportNV>* pTimings{ nullptr };
};

struct Decoded_VkLatencySubmissionPresentIdNV
{
    using struct_type = VkLatencySubmissionPresentIdNV;
    using api_element = schema::api_type::vulkan::VkLatencySubmissionPresentIdNV;

    VkLatencySubmissionPresentIdNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainLatencyCreateInfoNV
{
    using struct_type = VkSwapchainLatencyCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkSwapchainLatencyCreateInfoNV;

    VkSwapchainLatencyCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkOutOfBandQueueTypeInfoNV
{
    using struct_type = VkOutOfBandQueueTypeInfoNV;
    using api_element = schema::api_type::vulkan::VkOutOfBandQueueTypeInfoNV;

    VkOutOfBandQueueTypeInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkLatencySurfaceCapabilitiesNV
{
    using struct_type = VkLatencySurfaceCapabilitiesNV;
    using api_element = schema::api_type::vulkan::VkLatencySurfaceCapabilitiesNV;

    VkLatencySurfaceCapabilitiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkPresentModeKHR> pPresentModes;
};

struct Decoded_VkPhysicalDeviceDataGraphFeaturesARM
{
    using struct_type = VkPhysicalDeviceDataGraphFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDataGraphFeaturesARM;

    VkPhysicalDeviceDataGraphFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineResourceInfoARM
{
    using struct_type = VkDataGraphPipelineResourceInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineResourceInfoARM;

    VkDataGraphPipelineResourceInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineCompilerControlCreateInfoARM
{
    using struct_type = VkDataGraphPipelineCompilerControlCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineCompilerControlCreateInfoARM;

    VkDataGraphPipelineCompilerControlCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder pVendorOptions;
};

struct Decoded_VkDataGraphPipelineCreateInfoARM
{
    using struct_type = VkDataGraphPipelineCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineCreateInfoARM;

    VkDataGraphPipelineCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkDataGraphPipelineResourceInfoARM>* pResourceInfos{ nullptr };
};

struct Decoded_VkDataGraphPipelineShaderModuleCreateInfoARM
{
    using struct_type = VkDataGraphPipelineShaderModuleCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineShaderModuleCreateInfoARM;

    VkDataGraphPipelineShaderModuleCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId module{ format::kNullHandleId };
    StringDecoder pName;
    StructPointerDecoder<Decoded_VkSpecializationInfo>* pSpecializationInfo{ nullptr };
    StructPointerDecoder<Decoded_VkDataGraphPipelineConstantARM>* pConstants{ nullptr };
};

struct Decoded_VkDataGraphPipelineSessionCreateInfoARM
{
    using struct_type = VkDataGraphPipelineSessionCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineSessionCreateInfoARM;

    VkDataGraphPipelineSessionCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId dataGraphPipeline{ format::kNullHandleId };
};

struct Decoded_VkDataGraphPipelineSessionBindPointRequirementsInfoARM
{
    using struct_type = VkDataGraphPipelineSessionBindPointRequirementsInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineSessionBindPointRequirementsInfoARM;

    VkDataGraphPipelineSessionBindPointRequirementsInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId session{ format::kNullHandleId };
};

struct Decoded_VkDataGraphPipelineSessionBindPointRequirementARM
{
    using struct_type = VkDataGraphPipelineSessionBindPointRequirementARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineSessionBindPointRequirementARM;

    VkDataGraphPipelineSessionBindPointRequirementARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineSessionMemoryRequirementsInfoARM
{
    using struct_type = VkDataGraphPipelineSessionMemoryRequirementsInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineSessionMemoryRequirementsInfoARM;

    VkDataGraphPipelineSessionMemoryRequirementsInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId session{ format::kNullHandleId };
};

struct Decoded_VkBindDataGraphPipelineSessionMemoryInfoARM
{
    using struct_type = VkBindDataGraphPipelineSessionMemoryInfoARM;
    using api_element = schema::api_type::vulkan::VkBindDataGraphPipelineSessionMemoryInfoARM;

    VkBindDataGraphPipelineSessionMemoryInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId session{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkDataGraphPipelineInfoARM
{
    using struct_type = VkDataGraphPipelineInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineInfoARM;

    VkDataGraphPipelineInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId dataGraphPipeline{ format::kNullHandleId };
};

struct Decoded_VkDataGraphPipelinePropertyQueryResultARM
{
    using struct_type = VkDataGraphPipelinePropertyQueryResultARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelinePropertyQueryResultARM;

    VkDataGraphPipelinePropertyQueryResultARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkDataGraphPipelineIdentifierCreateInfoARM
{
    using struct_type = VkDataGraphPipelineIdentifierCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineIdentifierCreateInfoARM;

    VkDataGraphPipelineIdentifierCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pIdentifier;
};

struct Decoded_VkDataGraphPipelineDispatchInfoARM
{
    using struct_type = VkDataGraphPipelineDispatchInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineDispatchInfoARM;

    VkDataGraphPipelineDispatchInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDataGraphProcessingEngineARM
{
    using struct_type = VkPhysicalDeviceDataGraphProcessingEngineARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDataGraphProcessingEngineARM;

    VkPhysicalDeviceDataGraphProcessingEngineARM* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceDataGraphOperationSupportARM
{
    using struct_type = VkPhysicalDeviceDataGraphOperationSupportARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDataGraphOperationSupportARM;

    VkPhysicalDeviceDataGraphOperationSupportARM* decoded_value{ nullptr };

    StringDecoder name;
};

struct Decoded_VkQueueFamilyDataGraphPropertiesARM
{
    using struct_type = VkQueueFamilyDataGraphPropertiesARM;
    using api_element = schema::api_type::vulkan::VkQueueFamilyDataGraphPropertiesARM;

    VkQueueFamilyDataGraphPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPhysicalDeviceDataGraphProcessingEngineARM* engine{ nullptr };
    Decoded_VkPhysicalDeviceDataGraphOperationSupportARM* operation{ nullptr };
};

struct Decoded_VkDataGraphProcessingEngineCreateInfoARM
{
    using struct_type = VkDataGraphProcessingEngineCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphProcessingEngineCreateInfoARM;

    VkDataGraphProcessingEngineCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPhysicalDeviceDataGraphProcessingEngineARM>* pProcessingEngines{ nullptr };
};

struct Decoded_VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM
{
    using struct_type = VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM;

    VkPhysicalDeviceQueueFamilyDataGraphProcessingEngineInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyDataGraphProcessingEnginePropertiesARM
{
    using struct_type = VkQueueFamilyDataGraphProcessingEnginePropertiesARM;
    using api_element = schema::api_type::vulkan::VkQueueFamilyDataGraphProcessingEnginePropertiesARM;

    VkQueueFamilyDataGraphProcessingEnginePropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM
{
    using struct_type = VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM;

    VkDataGraphPipelineConstantTensorSemiStructuredSparsityInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM;

    VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM
{
    using struct_type = VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM;
    using api_element = schema::api_type::vulkan::VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM;

    VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pPerViewRenderAreas{ nullptr };
};

struct Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV
{
    using struct_type = VkPhysicalDevicePerStageDescriptorSetFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePerStageDescriptorSetFeaturesNV;

    VkPhysicalDevicePerStageDescriptorSetFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM
{
    using struct_type = VkPhysicalDeviceImageProcessing2FeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageProcessing2FeaturesQCOM;

    VkPhysicalDeviceImageProcessing2FeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM
{
    using struct_type = VkPhysicalDeviceImageProcessing2PropertiesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageProcessing2PropertiesQCOM;

    VkPhysicalDeviceImageProcessing2PropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* maxBlockMatchWindow{ nullptr };
};

struct Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM
{
    using struct_type = VkSamplerBlockMatchWindowCreateInfoQCOM;
    using api_element = schema::api_type::vulkan::VkSamplerBlockMatchWindowCreateInfoQCOM;

    VkSamplerBlockMatchWindowCreateInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* windowExtent{ nullptr };
};

struct Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceCubicWeightsFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCubicWeightsFeaturesQCOM;

    VkPhysicalDeviceCubicWeightsFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerCubicWeightsCreateInfoQCOM
{
    using struct_type = VkSamplerCubicWeightsCreateInfoQCOM;
    using api_element = schema::api_type::vulkan::VkSamplerCubicWeightsCreateInfoQCOM;

    VkSamplerCubicWeightsCreateInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBlitImageCubicWeightsInfoQCOM
{
    using struct_type = VkBlitImageCubicWeightsInfoQCOM;
    using api_element = schema::api_type::vulkan::VkBlitImageCubicWeightsInfoQCOM;

    VkBlitImageCubicWeightsInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceYcbcrDegammaFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceYcbcrDegammaFeaturesQCOM;

    VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM
{
    using struct_type = VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM;
    using api_element = schema::api_type::vulkan::VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM;

    VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceCubicClampFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCubicClampFeaturesQCOM;

    VkPhysicalDeviceCubicClampFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT
{
    using struct_type = VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT;

    VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT
{
    using struct_type = VkPhysicalDeviceLayeredDriverPropertiesMSFT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceLayeredDriverPropertiesMSFT;

    VkPhysicalDeviceLayeredDriverPropertiesMSFT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV
{
    using struct_type = VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV;

    VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceTileMemoryHeapFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTileMemoryHeapFeaturesQCOM;

    VkPhysicalDeviceTileMemoryHeapFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM
{
    using struct_type = VkPhysicalDeviceTileMemoryHeapPropertiesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceTileMemoryHeapPropertiesQCOM;

    VkPhysicalDeviceTileMemoryHeapPropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTileMemoryRequirementsQCOM
{
    using struct_type = VkTileMemoryRequirementsQCOM;
    using api_element = schema::api_type::vulkan::VkTileMemoryRequirementsQCOM;

    VkTileMemoryRequirementsQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTileMemoryBindInfoQCOM
{
    using struct_type = VkTileMemoryBindInfoQCOM;
    using api_element = schema::api_type::vulkan::VkTileMemoryBindInfoQCOM;

    VkTileMemoryBindInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkTileMemorySizeInfoQCOM
{
    using struct_type = VkTileMemorySizeInfoQCOM;
    using api_element = schema::api_type::vulkan::VkTileMemorySizeInfoQCOM;

    VkTileMemorySizeInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDecompressMemoryRegionEXT
{
    using struct_type = VkDecompressMemoryRegionEXT;
    using api_element = schema::api_type::vulkan::VkDecompressMemoryRegionEXT;

    VkDecompressMemoryRegionEXT* decoded_value{ nullptr };
};

struct Decoded_VkDecompressMemoryInfoEXT
{
    using struct_type = VkDecompressMemoryInfoEXT;
    using api_element = schema::api_type::vulkan::VkDecompressMemoryInfoEXT;

    VkDecompressMemoryInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDecompressMemoryRegionEXT>* pRegions{ nullptr };
};

struct Decoded_VkPhysicalDeviceMemoryDecompressionFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMemoryDecompressionFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMemoryDecompressionFeaturesEXT;

    VkPhysicalDeviceMemoryDecompressionFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMemoryDecompressionPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMemoryDecompressionPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMemoryDecompressionPropertiesEXT;

    VkPhysicalDeviceMemoryDecompressionPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDisplaySurfaceStereoCreateInfoNV
{
    using struct_type = VkDisplaySurfaceStereoCreateInfoNV;
    using api_element = schema::api_type::vulkan::VkDisplaySurfaceStereoCreateInfoNV;

    VkDisplaySurfaceStereoCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDisplayModeStereoPropertiesNV
{
    using struct_type = VkDisplayModeStereoPropertiesNV;
    using api_element = schema::api_type::vulkan::VkDisplayModeStereoPropertiesNV;

    VkDisplayModeStereoPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV
{
    using struct_type = VkPhysicalDeviceRawAccessChainsFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRawAccessChainsFeaturesNV;

    VkPhysicalDeviceRawAccessChainsFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV
{
    using struct_type = VkPhysicalDeviceCommandBufferInheritanceFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCommandBufferInheritanceFeaturesNV;

    VkPhysicalDeviceCommandBufferInheritanceFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV
{
    using struct_type = VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV;

    VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT;

    VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTensorRollingBackingCreateInfoARM
{
    using struct_type = VkTensorRollingBackingCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkTensorRollingBackingCreateInfoARM;

    VkTensorRollingBackingCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> wraps;
};

struct Decoded_VkTensorExplicitTilingFormatPropertiesARM
{
    using struct_type = VkTensorExplicitTilingFormatPropertiesARM;
    using api_element = schema::api_type::vulkan::VkTensorExplicitTilingFormatPropertiesARM;

    VkTensorExplicitTilingFormatPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderFloat8FeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderFloat8FeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderFloat8FeaturesEXT;

    VkPhysicalDeviceShaderFloat8FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV
{
    using struct_type = VkPhysicalDeviceRayTracingValidationFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingValidationFeaturesNV;

    VkPhysicalDeviceRayTracingValidationFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV
{
    using struct_type = VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV;

    VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV
{
    using struct_type = VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV;

    VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPartitionedAccelerationStructureFlagsNV
{
    using struct_type = VkPartitionedAccelerationStructureFlagsNV;
    using api_element = schema::api_type::vulkan::VkPartitionedAccelerationStructureFlagsNV;

    VkPartitionedAccelerationStructureFlagsNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkStridedDeviceAddressNV
{
    using struct_type = VkStridedDeviceAddressNV;
    using api_element = schema::api_type::vulkan::VkStridedDeviceAddressNV;

    VkStridedDeviceAddressNV* decoded_value{ nullptr };
};

struct Decoded_VkBuildPartitionedAccelerationStructureIndirectCommandNV
{
    using struct_type = VkBuildPartitionedAccelerationStructureIndirectCommandNV;
    using api_element = schema::api_type::vulkan::VkBuildPartitionedAccelerationStructureIndirectCommandNV;

    VkBuildPartitionedAccelerationStructureIndirectCommandNV* decoded_value{ nullptr };

    Decoded_VkStridedDeviceAddressNV* argData{ nullptr };
};

struct Decoded_VkPartitionedAccelerationStructureWriteInstanceDataNV
{
    using struct_type = VkPartitionedAccelerationStructureWriteInstanceDataNV;
    using api_element = schema::api_type::vulkan::VkPartitionedAccelerationStructureWriteInstanceDataNV;

    VkPartitionedAccelerationStructureWriteInstanceDataNV* decoded_value{ nullptr };

    Decoded_VkTransformMatrixKHR* transform{ nullptr };
    PointerDecoder<float> explicitAABB;
};

struct Decoded_VkPartitionedAccelerationStructureUpdateInstanceDataNV
{
    using struct_type = VkPartitionedAccelerationStructureUpdateInstanceDataNV;
    using api_element = schema::api_type::vulkan::VkPartitionedAccelerationStructureUpdateInstanceDataNV;

    VkPartitionedAccelerationStructureUpdateInstanceDataNV* decoded_value{ nullptr };
};

struct Decoded_VkPartitionedAccelerationStructureWritePartitionTranslationDataNV
{
    using struct_type = VkPartitionedAccelerationStructureWritePartitionTranslationDataNV;
    using api_element = schema::api_type::vulkan::VkPartitionedAccelerationStructureWritePartitionTranslationDataNV;

    VkPartitionedAccelerationStructureWritePartitionTranslationDataNV* decoded_value{ nullptr };

    PointerDecoder<float> partitionTranslation;
};

struct Decoded_VkWriteDescriptorSetPartitionedAccelerationStructureNV
{
    using struct_type = VkWriteDescriptorSetPartitionedAccelerationStructureNV;
    using api_element = schema::api_type::vulkan::VkWriteDescriptorSetPartitionedAccelerationStructureNV;

    VkWriteDescriptorSetPartitionedAccelerationStructureNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkDeviceAddress> pAccelerationStructures;
};

struct Decoded_VkPartitionedAccelerationStructureInstancesInputNV
{
    using struct_type = VkPartitionedAccelerationStructureInstancesInputNV;
    using api_element = schema::api_type::vulkan::VkPartitionedAccelerationStructureInstancesInputNV;

    VkPartitionedAccelerationStructureInstancesInputNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBuildPartitionedAccelerationStructureInfoNV
{
    using struct_type = VkBuildPartitionedAccelerationStructureInfoNV;
    using api_element = schema::api_type::vulkan::VkBuildPartitionedAccelerationStructureInfoNV;

    VkBuildPartitionedAccelerationStructureInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPartitionedAccelerationStructureInstancesInputNV* input{ nullptr };
};

struct Decoded_VkAccelerationStructureBuildSizesInfoKHR
{
    using struct_type = VkAccelerationStructureBuildSizesInfoKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureBuildSizesInfoKHR;

    VkAccelerationStructureBuildSizesInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT;

    VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT
{
    using struct_type = VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT;

    VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT
{
    using struct_type = VkGeneratedCommandsMemoryRequirementsInfoEXT;
    using api_element = schema::api_type::vulkan::VkGeneratedCommandsMemoryRequirementsInfoEXT;

    VkGeneratedCommandsMemoryRequirementsInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId indirectExecutionSet{ format::kNullHandleId };
    format::HandleId indirectCommandsLayout{ format::kNullHandleId };
};

struct Decoded_VkIndirectExecutionSetPipelineInfoEXT
{
    using struct_type = VkIndirectExecutionSetPipelineInfoEXT;
    using api_element = schema::api_type::vulkan::VkIndirectExecutionSetPipelineInfoEXT;

    VkIndirectExecutionSetPipelineInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId initialPipeline{ format::kNullHandleId };
};

struct Decoded_VkIndirectExecutionSetShaderLayoutInfoEXT
{
    using struct_type = VkIndirectExecutionSetShaderLayoutInfoEXT;
    using api_element = schema::api_type::vulkan::VkIndirectExecutionSetShaderLayoutInfoEXT;

    VkIndirectExecutionSetShaderLayoutInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
};

struct Decoded_VkIndirectExecutionSetShaderInfoEXT
{
    using struct_type = VkIndirectExecutionSetShaderInfoEXT;
    using api_element = schema::api_type::vulkan::VkIndirectExecutionSetShaderInfoEXT;

    VkIndirectExecutionSetShaderInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkShaderEXT> pInitialShaders;
    StructPointerDecoder<Decoded_VkIndirectExecutionSetShaderLayoutInfoEXT>* pSetLayoutInfos{ nullptr };
    StructPointerDecoder<Decoded_VkPushConstantRange>* pPushConstantRanges{ nullptr };
};

struct Decoded_VkGeneratedCommandsInfoEXT
{
    using struct_type = VkGeneratedCommandsInfoEXT;
    using api_element = schema::api_type::vulkan::VkGeneratedCommandsInfoEXT;

    VkGeneratedCommandsInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId indirectExecutionSet{ format::kNullHandleId };
    format::HandleId indirectCommandsLayout{ format::kNullHandleId };
};

struct Decoded_VkWriteIndirectExecutionSetPipelineEXT
{
    using struct_type = VkWriteIndirectExecutionSetPipelineEXT;
    using api_element = schema::api_type::vulkan::VkWriteIndirectExecutionSetPipelineEXT;

    VkWriteIndirectExecutionSetPipelineEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkIndirectCommandsPushConstantTokenEXT
{
    using struct_type = VkIndirectCommandsPushConstantTokenEXT;
    using api_element = schema::api_type::vulkan::VkIndirectCommandsPushConstantTokenEXT;

    VkIndirectCommandsPushConstantTokenEXT* decoded_value{ nullptr };

    Decoded_VkPushConstantRange* updateRange{ nullptr };
};

struct Decoded_VkIndirectCommandsVertexBufferTokenEXT
{
    using struct_type = VkIndirectCommandsVertexBufferTokenEXT;
    using api_element = schema::api_type::vulkan::VkIndirectCommandsVertexBufferTokenEXT;

    VkIndirectCommandsVertexBufferTokenEXT* decoded_value{ nullptr };
};

struct Decoded_VkIndirectCommandsIndexBufferTokenEXT
{
    using struct_type = VkIndirectCommandsIndexBufferTokenEXT;
    using api_element = schema::api_type::vulkan::VkIndirectCommandsIndexBufferTokenEXT;

    VkIndirectCommandsIndexBufferTokenEXT* decoded_value{ nullptr };
};

struct Decoded_VkIndirectCommandsExecutionSetTokenEXT
{
    using struct_type = VkIndirectCommandsExecutionSetTokenEXT;
    using api_element = schema::api_type::vulkan::VkIndirectCommandsExecutionSetTokenEXT;

    VkIndirectCommandsExecutionSetTokenEXT* decoded_value{ nullptr };
};

struct Decoded_VkIndirectCommandsLayoutCreateInfoEXT
{
    using struct_type = VkIndirectCommandsLayoutCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkIndirectCommandsLayoutCreateInfoEXT;

    VkIndirectCommandsLayoutCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipelineLayout{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutTokenEXT>* pTokens{ nullptr };
};

struct Decoded_VkDrawIndirectCountIndirectCommandEXT
{
    using struct_type = VkDrawIndirectCountIndirectCommandEXT;
    using api_element = schema::api_type::vulkan::VkDrawIndirectCountIndirectCommandEXT;

    VkDrawIndirectCountIndirectCommandEXT* decoded_value{ nullptr };
};

struct Decoded_VkBindVertexBufferIndirectCommandEXT
{
    using struct_type = VkBindVertexBufferIndirectCommandEXT;
    using api_element = schema::api_type::vulkan::VkBindVertexBufferIndirectCommandEXT;

    VkBindVertexBufferIndirectCommandEXT* decoded_value{ nullptr };
};

struct Decoded_VkBindIndexBufferIndirectCommandEXT
{
    using struct_type = VkBindIndexBufferIndirectCommandEXT;
    using api_element = schema::api_type::vulkan::VkBindIndexBufferIndirectCommandEXT;

    VkBindIndexBufferIndirectCommandEXT* decoded_value{ nullptr };
};

struct Decoded_VkGeneratedCommandsPipelineInfoEXT
{
    using struct_type = VkGeneratedCommandsPipelineInfoEXT;
    using api_element = schema::api_type::vulkan::VkGeneratedCommandsPipelineInfoEXT;

    VkGeneratedCommandsPipelineInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkGeneratedCommandsShaderInfoEXT
{
    using struct_type = VkGeneratedCommandsShaderInfoEXT;
    using api_element = schema::api_type::vulkan::VkGeneratedCommandsShaderInfoEXT;

    VkGeneratedCommandsShaderInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkShaderEXT> pShaders;
};

struct Decoded_VkWriteIndirectExecutionSetShaderEXT
{
    using struct_type = VkWriteIndirectExecutionSetShaderEXT;
    using api_element = schema::api_type::vulkan::VkWriteIndirectExecutionSetShaderEXT;

    VkWriteIndirectExecutionSetShaderEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId shader{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceImageAlignmentControlFeaturesMESA
{
    using struct_type = VkPhysicalDeviceImageAlignmentControlFeaturesMESA;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageAlignmentControlFeaturesMESA;

    VkPhysicalDeviceImageAlignmentControlFeaturesMESA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageAlignmentControlPropertiesMESA
{
    using struct_type = VkPhysicalDeviceImageAlignmentControlPropertiesMESA;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageAlignmentControlPropertiesMESA;

    VkPhysicalDeviceImageAlignmentControlPropertiesMESA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageAlignmentControlCreateInfoMESA
{
    using struct_type = VkImageAlignmentControlCreateInfoMESA;
    using api_element = schema::api_type::vulkan::VkImageAlignmentControlCreateInfoMESA;

    VkImageAlignmentControlCreateInfoMESA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPushConstantBankInfoNV
{
    using struct_type = VkPushConstantBankInfoNV;
    using api_element = schema::api_type::vulkan::VkPushConstantBankInfoNV;

    VkPushConstantBankInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePushConstantBankFeaturesNV
{
    using struct_type = VkPhysicalDevicePushConstantBankFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePushConstantBankFeaturesNV;

    VkPhysicalDevicePushConstantBankFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePushConstantBankPropertiesNV
{
    using struct_type = VkPhysicalDevicePushConstantBankPropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePushConstantBankPropertiesNV;

    VkPhysicalDevicePushConstantBankPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT
{
    using struct_type = VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT;

    VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT
{
    using struct_type = VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT;

    VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthClampControlFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDepthClampControlFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDepthClampControlFeaturesEXT;

    VkPhysicalDeviceDepthClampControlFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineViewportDepthClampControlCreateInfoEXT
{
    using struct_type = VkPipelineViewportDepthClampControlCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkPipelineViewportDepthClampControlCreateInfoEXT;

    VkPipelineViewportDepthClampControlCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDepthClampRangeEXT>* pDepthClampRange{ nullptr };
};

struct Decoded_VkPhysicalDeviceHdrVividFeaturesHUAWEI
{
    using struct_type = VkPhysicalDeviceHdrVividFeaturesHUAWEI;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceHdrVividFeaturesHUAWEI;

    VkPhysicalDeviceHdrVividFeaturesHUAWEI* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkHdrVividDynamicMetadataHUAWEI
{
    using struct_type = VkHdrVividDynamicMetadataHUAWEI;
    using api_element = schema::api_type::vulkan::VkHdrVividDynamicMetadataHUAWEI;

    VkHdrVividDynamicMetadataHUAWEI* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pDynamicMetadata;
};

struct Decoded_VkCooperativeMatrixFlexibleDimensionsPropertiesNV
{
    using struct_type = VkCooperativeMatrixFlexibleDimensionsPropertiesNV;
    using api_element = schema::api_type::vulkan::VkCooperativeMatrixFlexibleDimensionsPropertiesNV;

    VkCooperativeMatrixFlexibleDimensionsPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrix2FeaturesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrix2FeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeMatrix2FeaturesNV;

    VkPhysicalDeviceCooperativeMatrix2FeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrix2PropertiesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrix2PropertiesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeMatrix2PropertiesNV;

    VkPhysicalDeviceCooperativeMatrix2PropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM
{
    using struct_type = VkPhysicalDevicePipelineOpacityMicromapFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePipelineOpacityMicromapFeaturesARM;

    VkPhysicalDevicePipelineOpacityMicromapFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImportMemoryMetalHandleInfoEXT
{
    using struct_type = VkImportMemoryMetalHandleInfoEXT;
    using api_element = schema::api_type::vulkan::VkImportMemoryMetalHandleInfoEXT;

    VkImportMemoryMetalHandleInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t handle{ 0 };
};

struct Decoded_VkMemoryMetalHandlePropertiesEXT
{
    using struct_type = VkMemoryMetalHandlePropertiesEXT;
    using api_element = schema::api_type::vulkan::VkMemoryMetalHandlePropertiesEXT;

    VkMemoryMetalHandlePropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryGetMetalHandleInfoEXT
{
    using struct_type = VkMemoryGetMetalHandleInfoEXT;
    using api_element = schema::api_type::vulkan::VkMemoryGetMetalHandleInfoEXT;

    VkMemoryGetMetalHandleInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM
{
    using struct_type = VkPhysicalDevicePerformanceCountersByRegionFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePerformanceCountersByRegionFeaturesARM;

    VkPhysicalDevicePerformanceCountersByRegionFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM
{
    using struct_type = VkPhysicalDevicePerformanceCountersByRegionPropertiesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePerformanceCountersByRegionPropertiesARM;

    VkPhysicalDevicePerformanceCountersByRegionPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* performanceCounterRegionSize{ nullptr };
};

struct Decoded_VkPerformanceCounterARM
{
    using struct_type = VkPerformanceCounterARM;
    using api_element = schema::api_type::vulkan::VkPerformanceCounterARM;

    VkPerformanceCounterARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceCounterDescriptionARM
{
    using struct_type = VkPerformanceCounterDescriptionARM;
    using api_element = schema::api_type::vulkan::VkPerformanceCounterDescriptionARM;

    VkPerformanceCounterDescriptionARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
};

struct Decoded_VkRenderPassPerformanceCountersByRegionBeginInfoARM
{
    using struct_type = VkRenderPassPerformanceCountersByRegionBeginInfoARM;
    using api_element = schema::api_type::vulkan::VkRenderPassPerformanceCountersByRegionBeginInfoARM;

    VkRenderPassPerformanceCountersByRegionBeginInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkDeviceAddress> pCounterAddresses;
    PointerDecoder<uint32_t> pCounterIndices;
};

struct Decoded_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT
{
    using struct_type = VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT;

    VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFormatPackFeaturesARM
{
    using struct_type = VkPhysicalDeviceFormatPackFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFormatPackFeaturesARM;

    VkPhysicalDeviceFormatPackFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE;

    VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE;

    VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE
{
    using struct_type = VkPipelineFragmentDensityMapLayeredCreateInfoVALVE;
    using api_element = schema::api_type::vulkan::VkPipelineFragmentDensityMapLayeredCreateInfoVALVE;

    VkPipelineFragmentDensityMapLayeredCreateInfoVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSetPresentConfigNV
{
    using struct_type = VkSetPresentConfigNV;
    using api_element = schema::api_type::vulkan::VkSetPresentConfigNV;

    VkSetPresentConfigNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePresentMeteringFeaturesNV
{
    using struct_type = VkPhysicalDevicePresentMeteringFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePresentMeteringFeaturesNV;

    VkPhysicalDevicePresentMeteringFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT;

    VkPhysicalDeviceMultisampledRenderToSwapchainFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainFlagsSurfaceCapabilitiesEXT
{
    using struct_type = VkSwapchainFlagsSurfaceCapabilitiesEXT;
    using api_element = schema::api_type::vulkan::VkSwapchainFlagsSurfaceCapabilitiesEXT;

    VkSwapchainFlagsSurfaceCapabilitiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT
{
    using struct_type = VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT;

    VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShader64BitIndexingFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShader64BitIndexingFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShader64BitIndexingFeaturesEXT;

    VkPhysicalDeviceShader64BitIndexingFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCustomResolveFeaturesEXT
{
    using struct_type = VkPhysicalDeviceCustomResolveFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCustomResolveFeaturesEXT;

    VkPhysicalDeviceCustomResolveFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBeginCustomResolveInfoEXT
{
    using struct_type = VkBeginCustomResolveInfoEXT;
    using api_element = schema::api_type::vulkan::VkBeginCustomResolveInfoEXT;

    VkBeginCustomResolveInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCustomResolveCreateInfoEXT
{
    using struct_type = VkCustomResolveCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkCustomResolveCreateInfoEXT;

    VkCustomResolveCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pColorAttachmentFormats;
};

struct Decoded_VkPipelineCacheHeaderVersionDataGraphQCOM
{
    using struct_type = VkPipelineCacheHeaderVersionDataGraphQCOM;
    using api_element = schema::api_type::vulkan::VkPipelineCacheHeaderVersionDataGraphQCOM;

    VkPipelineCacheHeaderVersionDataGraphQCOM* decoded_value{ nullptr };

    PointerDecoder<uint32_t> toolchainVersion;
};

struct Decoded_VkDataGraphPipelineBuiltinModelCreateInfoQCOM
{
    using struct_type = VkDataGraphPipelineBuiltinModelCreateInfoQCOM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineBuiltinModelCreateInfoQCOM;

    VkDataGraphPipelineBuiltinModelCreateInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPhysicalDeviceDataGraphOperationSupportARM>* pOperation{ nullptr };
};

struct Decoded_VkPhysicalDeviceDataGraphModelFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceDataGraphModelFeaturesQCOM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDataGraphModelFeaturesQCOM;

    VkPhysicalDeviceDataGraphModelFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM
{
    using struct_type = VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM;

    VkPhysicalDeviceDataGraphOpticalFlowFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyDataGraphOpticalFlowPropertiesARM
{
    using struct_type = VkQueueFamilyDataGraphOpticalFlowPropertiesARM;
    using api_element = schema::api_type::vulkan::VkQueueFamilyDataGraphOpticalFlowPropertiesARM;

    VkQueueFamilyDataGraphOpticalFlowPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineOpticalFlowCreateInfoARM
{
    using struct_type = VkDataGraphPipelineOpticalFlowCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineOpticalFlowCreateInfoARM;

    VkDataGraphPipelineOpticalFlowCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphOpticalFlowImageFormatPropertiesARM
{
    using struct_type = VkDataGraphOpticalFlowImageFormatPropertiesARM;
    using api_element = schema::api_type::vulkan::VkDataGraphOpticalFlowImageFormatPropertiesARM;

    VkDataGraphOpticalFlowImageFormatPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphOpticalFlowImageFormatInfoARM
{
    using struct_type = VkDataGraphOpticalFlowImageFormatInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphOpticalFlowImageFormatInfoARM;

    VkDataGraphOpticalFlowImageFormatInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineOpticalFlowDispatchInfoARM
{
    using struct_type = VkDataGraphPipelineOpticalFlowDispatchInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineOpticalFlowDispatchInfoARM;

    VkDataGraphPipelineOpticalFlowDispatchInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineResourceInfoImageLayoutARM
{
    using struct_type = VkDataGraphPipelineResourceInfoImageLayoutARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineResourceInfoImageLayoutARM;

    VkDataGraphPipelineResourceInfoImageLayoutARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineSingleNodeConnectionARM
{
    using struct_type = VkDataGraphPipelineSingleNodeConnectionARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineSingleNodeConnectionARM;

    VkDataGraphPipelineSingleNodeConnectionARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineSingleNodeCreateInfoARM
{
    using struct_type = VkDataGraphPipelineSingleNodeCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineSingleNodeCreateInfoARM;

    VkDataGraphPipelineSingleNodeCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDataGraphPipelineSingleNodeConnectionARM>* pConnections{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderLongVectorFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderLongVectorFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderLongVectorFeaturesEXT;

    VkPhysicalDeviceShaderLongVectorFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderLongVectorPropertiesEXT
{
    using struct_type = VkPhysicalDeviceShaderLongVectorPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderLongVectorPropertiesEXT;

    VkPhysicalDeviceShaderLongVectorPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC
{
    using struct_type = VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC;

    VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT;

    VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkComputeOccupancyPriorityParametersNV
{
    using struct_type = VkComputeOccupancyPriorityParametersNV;
    using api_element = schema::api_type::vulkan::VkComputeOccupancyPriorityParametersNV;

    VkComputeOccupancyPriorityParametersNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV
{
    using struct_type = VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV;

    VkPhysicalDeviceComputeOccupancyPriorityFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCooperativeMatrixProperties2EXT
{
    using struct_type = VkCooperativeMatrixProperties2EXT;
    using api_element = schema::api_type::vulkan::VkCooperativeMatrixProperties2EXT;

    VkCooperativeMatrixProperties2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixInfo2EXT
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixInfo2EXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeMatrixInfo2EXT;

    VkPhysicalDeviceCooperativeMatrixInfo2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT;

    VkPhysicalDeviceCooperativeMatrixMaintenance1FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT;

    VkPhysicalDeviceShaderSubgroupPartitionedFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT;

    VkPhysicalDeviceShaderOCPMicroscalingTypesFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE
{
    using struct_type = VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE;

    VkPhysicalDeviceShaderMixedFloatDotProductFeaturesVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkThrottleHintSubmitInfoSEC
{
    using struct_type = VkThrottleHintSubmitInfoSEC;
    using api_element = schema::api_type::vulkan::VkThrottleHintSubmitInfoSEC;

    VkThrottleHintSubmitInfoSEC* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceThrottleHintFeaturesSEC
{
    using struct_type = VkPhysicalDeviceThrottleHintFeaturesSEC;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceThrottleHintFeaturesSEC;

    VkPhysicalDeviceThrottleHintFeaturesSEC* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM
{
    using struct_type = VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM;

    VkPhysicalDeviceDataGraphNeuralAcceleratorStatisticsFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineNeuralStatisticsCreateInfoARM
{
    using struct_type = VkDataGraphPipelineNeuralStatisticsCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineNeuralStatisticsCreateInfoARM;

    VkDataGraphPipelineNeuralStatisticsCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM
{
    using struct_type = VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM;
    using api_element = schema::api_type::vulkan::VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM;

    VkDataGraphPipelineSessionNeuralStatisticsCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT
{
    using struct_type = VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT;

    VkPhysicalDevicePrimitiveRestartIndexFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageTilingControlFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImageTilingControlFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceImageTilingControlFeaturesEXT;

    VkPhysicalDeviceImageTilingControlFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageTilingControlCreateInfoEXT
{
    using struct_type = VkImageTilingControlCreateInfoEXT;
    using api_element = schema::api_type::vulkan::VkImageTilingControlCreateInfoEXT;

    VkImageTilingControlCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV;

    VkPhysicalDeviceCooperativeMatrixDecodeVectorFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePrivateDataBaseHandleFeaturesNV
{
    using struct_type = VkPhysicalDevicePrivateDataBaseHandleFeaturesNV;
    using api_element = schema::api_type::vulkan::VkPhysicalDevicePrivateDataBaseHandleFeaturesNV;

    VkPhysicalDevicePrivateDataBaseHandleFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureBuildRangeInfoKHR
{
    using struct_type = VkAccelerationStructureBuildRangeInfoKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureBuildRangeInfoKHR;

    VkAccelerationStructureBuildRangeInfoKHR* decoded_value{ nullptr };
};

struct Decoded_VkAccelerationStructureGeometryTrianglesDataKHR
{
    using struct_type = VkAccelerationStructureGeometryTrianglesDataKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureGeometryTrianglesDataKHR;

    VkAccelerationStructureGeometryTrianglesDataKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* vertexData{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* indexData{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* transformData{ nullptr };
};

struct Decoded_VkAccelerationStructureGeometryAabbsDataKHR
{
    using struct_type = VkAccelerationStructureGeometryAabbsDataKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureGeometryAabbsDataKHR;

    VkAccelerationStructureGeometryAabbsDataKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* data{ nullptr };
};

struct Decoded_VkAccelerationStructureGeometryInstancesDataKHR
{
    using struct_type = VkAccelerationStructureGeometryInstancesDataKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureGeometryInstancesDataKHR;

    VkAccelerationStructureGeometryInstancesDataKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* data{ nullptr };
};

struct Decoded_VkAccelerationStructureBuildGeometryInfoKHR
{
    using struct_type = VkAccelerationStructureBuildGeometryInfoKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureBuildGeometryInfoKHR;

    VkAccelerationStructureBuildGeometryInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcAccelerationStructure{ format::kNullHandleId };
    format::HandleId dstAccelerationStructure{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkAccelerationStructureGeometryKHR>* pGeometries{ nullptr };
    StructPointerDecoder<Decoded_VkAccelerationStructureGeometryKHR*>* ppGeometries{ nullptr };
    Decoded_VkDeviceOrHostAddressKHR* scratchData{ nullptr };
};

struct Decoded_VkAccelerationStructureCreateInfoKHR
{
    using struct_type = VkAccelerationStructureCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureCreateInfoKHR;

    VkAccelerationStructureCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkWriteDescriptorSetAccelerationStructureKHR
{
    using struct_type = VkWriteDescriptorSetAccelerationStructureKHR;
    using api_element = schema::api_type::vulkan::VkWriteDescriptorSetAccelerationStructureKHR;

    VkWriteDescriptorSetAccelerationStructureKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructures;
};

struct Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR
{
    using struct_type = VkPhysicalDeviceAccelerationStructureFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceAccelerationStructureFeaturesKHR;

    VkPhysicalDeviceAccelerationStructureFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR
{
    using struct_type = VkPhysicalDeviceAccelerationStructurePropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceAccelerationStructurePropertiesKHR;

    VkPhysicalDeviceAccelerationStructurePropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureDeviceAddressInfoKHR
{
    using struct_type = VkAccelerationStructureDeviceAddressInfoKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureDeviceAddressInfoKHR;

    VkAccelerationStructureDeviceAddressInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId accelerationStructure{ format::kNullHandleId };
};

struct Decoded_VkAccelerationStructureVersionInfoKHR
{
    using struct_type = VkAccelerationStructureVersionInfoKHR;
    using api_element = schema::api_type::vulkan::VkAccelerationStructureVersionInfoKHR;

    VkAccelerationStructureVersionInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pVersionData;
};

struct Decoded_VkCopyAccelerationStructureToMemoryInfoKHR
{
    using struct_type = VkCopyAccelerationStructureToMemoryInfoKHR;
    using api_element = schema::api_type::vulkan::VkCopyAccelerationStructureToMemoryInfoKHR;

    VkCopyAccelerationStructureToMemoryInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId src{ format::kNullHandleId };
    Decoded_VkDeviceOrHostAddressKHR* dst{ nullptr };
};

struct Decoded_VkCopyMemoryToAccelerationStructureInfoKHR
{
    using struct_type = VkCopyMemoryToAccelerationStructureInfoKHR;
    using api_element = schema::api_type::vulkan::VkCopyMemoryToAccelerationStructureInfoKHR;

    VkCopyMemoryToAccelerationStructureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* src{ nullptr };
    format::HandleId dst{ format::kNullHandleId };
};

struct Decoded_VkCopyAccelerationStructureInfoKHR
{
    using struct_type = VkCopyAccelerationStructureInfoKHR;
    using api_element = schema::api_type::vulkan::VkCopyAccelerationStructureInfoKHR;

    VkCopyAccelerationStructureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId src{ format::kNullHandleId };
    format::HandleId dst{ format::kNullHandleId };
};

struct Decoded_VkRayTracingShaderGroupCreateInfoKHR
{
    using struct_type = VkRayTracingShaderGroupCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkRayTracingShaderGroupCreateInfoKHR;

    VkRayTracingShaderGroupCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pShaderGroupCaptureReplayHandle{ 0 };
};

struct Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR
{
    using struct_type = VkRayTracingPipelineInterfaceCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkRayTracingPipelineInterfaceCreateInfoKHR;

    VkRayTracingPipelineInterfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRayTracingPipelineCreateInfoKHR
{
    using struct_type = VkRayTracingPipelineCreateInfoKHR;
    using api_element = schema::api_type::vulkan::VkRayTracingPipelineCreateInfoKHR;

    VkRayTracingPipelineCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>* pStages{ nullptr };
    StructPointerDecoder<Decoded_VkRayTracingShaderGroupCreateInfoKHR>* pGroups{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineLibraryCreateInfoKHR>* pLibraryInfo{ nullptr };
    StructPointerDecoder<Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR>* pLibraryInterface{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineDynamicStateCreateInfo>* pDynamicState{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    format::HandleId basePipelineHandle{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR
{
    using struct_type = VkPhysicalDeviceRayTracingPipelineFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingPipelineFeaturesKHR;

    VkPhysicalDeviceRayTracingPipelineFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR
{
    using struct_type = VkPhysicalDeviceRayTracingPipelinePropertiesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayTracingPipelinePropertiesKHR;

    VkPhysicalDeviceRayTracingPipelinePropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkStridedDeviceAddressRegionKHR
{
    using struct_type = VkStridedDeviceAddressRegionKHR;
    using api_element = schema::api_type::vulkan::VkStridedDeviceAddressRegionKHR;

    VkStridedDeviceAddressRegionKHR* decoded_value{ nullptr };
};

struct Decoded_VkTraceRaysIndirectCommandKHR
{
    using struct_type = VkTraceRaysIndirectCommandKHR;
    using api_element = schema::api_type::vulkan::VkTraceRaysIndirectCommandKHR;

    VkTraceRaysIndirectCommandKHR* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayQueryFeaturesKHR
{
    using struct_type = VkPhysicalDeviceRayQueryFeaturesKHR;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceRayQueryFeaturesKHR;

    VkPhysicalDeviceRayQueryFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMeshShaderFeaturesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMeshShaderFeaturesEXT;

    VkPhysicalDeviceMeshShaderFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMeshShaderPropertiesEXT;
    using api_element = schema::api_type::vulkan::VkPhysicalDeviceMeshShaderPropertiesEXT;

    VkPhysicalDeviceMeshShaderPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> maxTaskWorkGroupCount;
    PointerDecoder<uint32_t> maxTaskWorkGroupSize;
    PointerDecoder<uint32_t> maxMeshWorkGroupCount;
    PointerDecoder<uint32_t> maxMeshWorkGroupSize;
};

struct Decoded_VkDrawMeshTasksIndirectCommandEXT
{
    using struct_type = VkDrawMeshTasksIndirectCommandEXT;
    using api_element = schema::api_type::vulkan::VkDrawMeshTasksIndirectCommandEXT;

    VkDrawMeshTasksIndirectCommandEXT* decoded_value{ nullptr };
};

typedef Decoded_VkPhysicalDeviceVariablePointersFeatures Decoded_VkPhysicalDeviceVariablePointerFeatures;

typedef Decoded_VkPhysicalDeviceShaderDrawParametersFeatures Decoded_VkPhysicalDeviceShaderDrawParameterFeatures;

typedef Decoded_VkRenderingInfo Decoded_VkRenderingInfoKHR;

typedef Decoded_VkRenderingAttachmentInfo Decoded_VkRenderingAttachmentInfoKHR;

typedef Decoded_VkPipelineRenderingCreateInfo Decoded_VkPipelineRenderingCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceDynamicRenderingFeatures Decoded_VkPhysicalDeviceDynamicRenderingFeaturesKHR;

typedef Decoded_VkCommandBufferInheritanceRenderingInfo Decoded_VkCommandBufferInheritanceRenderingInfoKHR;

typedef Decoded_VkRenderPassMultiviewCreateInfo Decoded_VkRenderPassMultiviewCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceMultiviewFeatures Decoded_VkPhysicalDeviceMultiviewFeaturesKHR;

typedef Decoded_VkPhysicalDeviceMultiviewProperties Decoded_VkPhysicalDeviceMultiviewPropertiesKHR;

typedef Decoded_VkPhysicalDeviceFeatures2 Decoded_VkPhysicalDeviceFeatures2KHR;

typedef Decoded_VkPhysicalDeviceProperties2 Decoded_VkPhysicalDeviceProperties2KHR;

typedef Decoded_VkFormatProperties2 Decoded_VkFormatProperties2KHR;

typedef Decoded_VkImageFormatProperties2 Decoded_VkImageFormatProperties2KHR;

typedef Decoded_VkPhysicalDeviceImageFormatInfo2 Decoded_VkPhysicalDeviceImageFormatInfo2KHR;

typedef Decoded_VkQueueFamilyProperties2 Decoded_VkQueueFamilyProperties2KHR;

typedef Decoded_VkPhysicalDeviceMemoryProperties2 Decoded_VkPhysicalDeviceMemoryProperties2KHR;

typedef Decoded_VkSparseImageFormatProperties2 Decoded_VkSparseImageFormatProperties2KHR;

typedef Decoded_VkPhysicalDeviceSparseImageFormatInfo2 Decoded_VkPhysicalDeviceSparseImageFormatInfo2KHR;

typedef Decoded_VkMemoryAllocateFlagsInfo Decoded_VkMemoryAllocateFlagsInfoKHR;

typedef Decoded_VkDeviceGroupRenderPassBeginInfo Decoded_VkDeviceGroupRenderPassBeginInfoKHR;

typedef Decoded_VkDeviceGroupCommandBufferBeginInfo Decoded_VkDeviceGroupCommandBufferBeginInfoKHR;

typedef Decoded_VkDeviceGroupSubmitInfo Decoded_VkDeviceGroupSubmitInfoKHR;

typedef Decoded_VkDeviceGroupBindSparseInfo Decoded_VkDeviceGroupBindSparseInfoKHR;

typedef Decoded_VkBindBufferMemoryDeviceGroupInfo Decoded_VkBindBufferMemoryDeviceGroupInfoKHR;

typedef Decoded_VkBindImageMemoryDeviceGroupInfo Decoded_VkBindImageMemoryDeviceGroupInfoKHR;

typedef Decoded_VkPhysicalDeviceGroupProperties Decoded_VkPhysicalDeviceGroupPropertiesKHR;

typedef Decoded_VkDeviceGroupDeviceCreateInfo Decoded_VkDeviceGroupDeviceCreateInfoKHR;

typedef Decoded_VkExternalMemoryProperties Decoded_VkExternalMemoryPropertiesKHR;

typedef Decoded_VkPhysicalDeviceExternalImageFormatInfo Decoded_VkPhysicalDeviceExternalImageFormatInfoKHR;

typedef Decoded_VkExternalImageFormatProperties Decoded_VkExternalImageFormatPropertiesKHR;

typedef Decoded_VkPhysicalDeviceExternalBufferInfo Decoded_VkPhysicalDeviceExternalBufferInfoKHR;

typedef Decoded_VkExternalBufferProperties Decoded_VkExternalBufferPropertiesKHR;

typedef Decoded_VkPhysicalDeviceIDProperties Decoded_VkPhysicalDeviceIDPropertiesKHR;

typedef Decoded_VkExternalMemoryImageCreateInfo Decoded_VkExternalMemoryImageCreateInfoKHR;

typedef Decoded_VkExternalMemoryBufferCreateInfo Decoded_VkExternalMemoryBufferCreateInfoKHR;

typedef Decoded_VkExportMemoryAllocateInfo Decoded_VkExportMemoryAllocateInfoKHR;

typedef Decoded_VkPhysicalDeviceExternalSemaphoreInfo Decoded_VkPhysicalDeviceExternalSemaphoreInfoKHR;

typedef Decoded_VkExternalSemaphoreProperties Decoded_VkExternalSemaphorePropertiesKHR;

typedef Decoded_VkExportSemaphoreCreateInfo Decoded_VkExportSemaphoreCreateInfoKHR;

typedef Decoded_VkPhysicalDevicePushDescriptorProperties Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR;

typedef Decoded_VkPhysicalDeviceShaderFloat16Int8Features Decoded_VkPhysicalDeviceShaderFloat16Int8FeaturesKHR;

typedef Decoded_VkPhysicalDeviceShaderFloat16Int8Features Decoded_VkPhysicalDeviceFloat16Int8FeaturesKHR;

typedef Decoded_VkPhysicalDevice16BitStorageFeatures Decoded_VkPhysicalDevice16BitStorageFeaturesKHR;

typedef Decoded_VkDescriptorUpdateTemplateEntry Decoded_VkDescriptorUpdateTemplateEntryKHR;

typedef Decoded_VkDescriptorUpdateTemplateCreateInfo Decoded_VkDescriptorUpdateTemplateCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceImagelessFramebufferFeatures Decoded_VkPhysicalDeviceImagelessFramebufferFeaturesKHR;

typedef Decoded_VkFramebufferAttachmentsCreateInfo Decoded_VkFramebufferAttachmentsCreateInfoKHR;

typedef Decoded_VkFramebufferAttachmentImageInfo Decoded_VkFramebufferAttachmentImageInfoKHR;

typedef Decoded_VkRenderPassAttachmentBeginInfo Decoded_VkRenderPassAttachmentBeginInfoKHR;

typedef Decoded_VkRenderPassCreateInfo2 Decoded_VkRenderPassCreateInfo2KHR;

typedef Decoded_VkAttachmentDescription2 Decoded_VkAttachmentDescription2KHR;

typedef Decoded_VkAttachmentReference2 Decoded_VkAttachmentReference2KHR;

typedef Decoded_VkSubpassDescription2 Decoded_VkSubpassDescription2KHR;

typedef Decoded_VkSubpassDependency2 Decoded_VkSubpassDependency2KHR;

typedef Decoded_VkSubpassBeginInfo Decoded_VkSubpassBeginInfoKHR;

typedef Decoded_VkSubpassEndInfo Decoded_VkSubpassEndInfoKHR;

typedef Decoded_VkPhysicalDeviceExternalFenceInfo Decoded_VkPhysicalDeviceExternalFenceInfoKHR;

typedef Decoded_VkExternalFenceProperties Decoded_VkExternalFencePropertiesKHR;

typedef Decoded_VkExportFenceCreateInfo Decoded_VkExportFenceCreateInfoKHR;

typedef Decoded_VkPhysicalDevicePointClippingProperties Decoded_VkPhysicalDevicePointClippingPropertiesKHR;

typedef Decoded_VkRenderPassInputAttachmentAspectCreateInfo Decoded_VkRenderPassInputAttachmentAspectCreateInfoKHR;

typedef Decoded_VkInputAttachmentAspectReference Decoded_VkInputAttachmentAspectReferenceKHR;

typedef Decoded_VkImageViewUsageCreateInfo Decoded_VkImageViewUsageCreateInfoKHR;

typedef Decoded_VkPipelineTessellationDomainOriginStateCreateInfo Decoded_VkPipelineTessellationDomainOriginStateCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceVariablePointersFeatures Decoded_VkPhysicalDeviceVariablePointerFeaturesKHR;

typedef Decoded_VkPhysicalDeviceVariablePointersFeatures Decoded_VkPhysicalDeviceVariablePointersFeaturesKHR;

typedef Decoded_VkMemoryDedicatedRequirements Decoded_VkMemoryDedicatedRequirementsKHR;

typedef Decoded_VkMemoryDedicatedAllocateInfo Decoded_VkMemoryDedicatedAllocateInfoKHR;

typedef Decoded_VkBufferMemoryRequirementsInfo2 Decoded_VkBufferMemoryRequirementsInfo2KHR;

typedef Decoded_VkImageMemoryRequirementsInfo2 Decoded_VkImageMemoryRequirementsInfo2KHR;

typedef Decoded_VkImageSparseMemoryRequirementsInfo2 Decoded_VkImageSparseMemoryRequirementsInfo2KHR;

typedef Decoded_VkMemoryRequirements2 Decoded_VkMemoryRequirements2KHR;

typedef Decoded_VkSparseImageMemoryRequirements2 Decoded_VkSparseImageMemoryRequirements2KHR;

typedef Decoded_VkImageFormatListCreateInfo Decoded_VkImageFormatListCreateInfoKHR;

typedef Decoded_VkSamplerYcbcrConversionCreateInfo Decoded_VkSamplerYcbcrConversionCreateInfoKHR;

typedef Decoded_VkSamplerYcbcrConversionInfo Decoded_VkSamplerYcbcrConversionInfoKHR;

typedef Decoded_VkBindImagePlaneMemoryInfo Decoded_VkBindImagePlaneMemoryInfoKHR;

typedef Decoded_VkImagePlaneMemoryRequirementsInfo Decoded_VkImagePlaneMemoryRequirementsInfoKHR;

typedef Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeaturesKHR;

typedef Decoded_VkSamplerYcbcrConversionImageFormatProperties Decoded_VkSamplerYcbcrConversionImageFormatPropertiesKHR;

typedef Decoded_VkBindBufferMemoryInfo Decoded_VkBindBufferMemoryInfoKHR;

typedef Decoded_VkBindImageMemoryInfo Decoded_VkBindImageMemoryInfoKHR;

typedef Decoded_VkPhysicalDeviceMaintenance3Properties Decoded_VkPhysicalDeviceMaintenance3PropertiesKHR;

typedef Decoded_VkDescriptorSetLayoutSupport Decoded_VkDescriptorSetLayoutSupportKHR;

typedef Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR;

typedef Decoded_VkPhysicalDevice8BitStorageFeatures Decoded_VkPhysicalDevice8BitStorageFeaturesKHR;

typedef Decoded_VkPhysicalDeviceShaderAtomicInt64Features Decoded_VkPhysicalDeviceShaderAtomicInt64FeaturesKHR;

typedef Decoded_VkDeviceQueueGlobalPriorityCreateInfo Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR;

typedef Decoded_VkQueueFamilyGlobalPriorityProperties Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR;

typedef Decoded_VkConformanceVersion Decoded_VkConformanceVersionKHR;

typedef Decoded_VkPhysicalDeviceDriverProperties Decoded_VkPhysicalDeviceDriverPropertiesKHR;

typedef Decoded_VkPhysicalDeviceFloatControlsProperties Decoded_VkPhysicalDeviceFloatControlsPropertiesKHR;

typedef Decoded_VkSubpassDescriptionDepthStencilResolve Decoded_VkSubpassDescriptionDepthStencilResolveKHR;

typedef Decoded_VkPhysicalDeviceDepthStencilResolveProperties Decoded_VkPhysicalDeviceDepthStencilResolvePropertiesKHR;

typedef Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures Decoded_VkPhysicalDeviceTimelineSemaphoreFeaturesKHR;

typedef Decoded_VkPhysicalDeviceTimelineSemaphoreProperties Decoded_VkPhysicalDeviceTimelineSemaphorePropertiesKHR;

typedef Decoded_VkSemaphoreTypeCreateInfo Decoded_VkSemaphoreTypeCreateInfoKHR;

typedef Decoded_VkTimelineSemaphoreSubmitInfo Decoded_VkTimelineSemaphoreSubmitInfoKHR;

typedef Decoded_VkSemaphoreWaitInfo Decoded_VkSemaphoreWaitInfoKHR;

typedef Decoded_VkSemaphoreSignalInfo Decoded_VkSemaphoreSignalInfoKHR;

typedef Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures Decoded_VkPhysicalDeviceVulkanMemoryModelFeaturesKHR;

typedef Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures Decoded_VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR;

typedef Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeatures Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR;

typedef Decoded_VkRenderingAttachmentLocationInfo Decoded_VkRenderingAttachmentLocationInfoKHR;

typedef Decoded_VkRenderingInputAttachmentIndexInfo Decoded_VkRenderingInputAttachmentIndexInfoKHR;

typedef Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR;

typedef Decoded_VkAttachmentReferenceStencilLayout Decoded_VkAttachmentReferenceStencilLayoutKHR;

typedef Decoded_VkAttachmentDescriptionStencilLayout Decoded_VkAttachmentDescriptionStencilLayoutKHR;

typedef Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR;

typedef Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesKHR;

typedef Decoded_VkBufferDeviceAddressInfo Decoded_VkBufferDeviceAddressInfoKHR;

typedef Decoded_VkBufferOpaqueCaptureAddressCreateInfo Decoded_VkBufferOpaqueCaptureAddressCreateInfoKHR;

typedef Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo Decoded_VkMemoryOpaqueCaptureAddressAllocateInfoKHR;

typedef Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo Decoded_VkDeviceMemoryOpaqueCaptureAddressInfoKHR;

typedef Decoded_VkMemoryMapInfo Decoded_VkMemoryMapInfoKHR;

typedef Decoded_VkMemoryUnmapInfo Decoded_VkMemoryUnmapInfoKHR;

typedef Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures Decoded_VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR;

typedef Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties Decoded_VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR;

typedef Decoded_VkMemoryBarrier2 Decoded_VkMemoryBarrier2KHR;

typedef Decoded_VkBufferMemoryBarrier2 Decoded_VkBufferMemoryBarrier2KHR;

typedef Decoded_VkImageMemoryBarrier2 Decoded_VkImageMemoryBarrier2KHR;

typedef Decoded_VkDependencyInfo Decoded_VkDependencyInfoKHR;

typedef Decoded_VkSubmitInfo2 Decoded_VkSubmitInfo2KHR;

typedef Decoded_VkSemaphoreSubmitInfo Decoded_VkSemaphoreSubmitInfoKHR;

typedef Decoded_VkCommandBufferSubmitInfo Decoded_VkCommandBufferSubmitInfoKHR;

typedef Decoded_VkPhysicalDeviceSynchronization2Features Decoded_VkPhysicalDeviceSynchronization2FeaturesKHR;

typedef Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR;

typedef Decoded_VkCopyBufferInfo2 Decoded_VkCopyBufferInfo2KHR;

typedef Decoded_VkCopyImageInfo2 Decoded_VkCopyImageInfo2KHR;

typedef Decoded_VkCopyBufferToImageInfo2 Decoded_VkCopyBufferToImageInfo2KHR;

typedef Decoded_VkCopyImageToBufferInfo2 Decoded_VkCopyImageToBufferInfo2KHR;

typedef Decoded_VkBlitImageInfo2 Decoded_VkBlitImageInfo2KHR;

typedef Decoded_VkResolveImageInfo2 Decoded_VkResolveImageInfo2KHR;

typedef Decoded_VkBufferCopy2 Decoded_VkBufferCopy2KHR;

typedef Decoded_VkImageCopy2 Decoded_VkImageCopy2KHR;

typedef Decoded_VkImageBlit2 Decoded_VkImageBlit2KHR;

typedef Decoded_VkBufferImageCopy2 Decoded_VkBufferImageCopy2KHR;

typedef Decoded_VkImageResolve2 Decoded_VkImageResolve2KHR;

typedef Decoded_VkFormatProperties3 Decoded_VkFormatProperties3KHR;

typedef Decoded_VkPhysicalDeviceMaintenance4Features Decoded_VkPhysicalDeviceMaintenance4FeaturesKHR;

typedef Decoded_VkPhysicalDeviceMaintenance4Properties Decoded_VkPhysicalDeviceMaintenance4PropertiesKHR;

typedef Decoded_VkDeviceBufferMemoryRequirements Decoded_VkDeviceBufferMemoryRequirementsKHR;

typedef Decoded_VkDeviceImageMemoryRequirements Decoded_VkDeviceImageMemoryRequirementsKHR;

typedef Decoded_VkPhysicalDeviceShaderSubgroupRotateFeatures Decoded_VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR;

typedef Decoded_VkPhysicalDeviceMaintenance5Features Decoded_VkPhysicalDeviceMaintenance5FeaturesKHR;

typedef Decoded_VkPhysicalDeviceMaintenance5Properties Decoded_VkPhysicalDeviceMaintenance5PropertiesKHR;

typedef Decoded_VkRenderingAreaInfo Decoded_VkRenderingAreaInfoKHR;

typedef Decoded_VkDeviceImageSubresourceInfo Decoded_VkDeviceImageSubresourceInfoKHR;

typedef Decoded_VkImageSubresource2 Decoded_VkImageSubresource2KHR;

typedef Decoded_VkSubresourceLayout2 Decoded_VkSubresourceLayout2KHR;

typedef Decoded_VkPipelineCreateFlags2CreateInfo Decoded_VkPipelineCreateFlags2CreateInfoKHR;

typedef Decoded_VkBufferUsageFlags2CreateInfo Decoded_VkBufferUsageFlags2CreateInfoKHR;

typedef Decoded_VkPhysicalDeviceVertexAttributeDivisorProperties Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR;

typedef Decoded_VkVertexInputBindingDivisorDescription Decoded_VkVertexInputBindingDivisorDescriptionKHR;

typedef Decoded_VkPipelineVertexInputDivisorStateCreateInfo Decoded_VkPipelineVertexInputDivisorStateCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR;

typedef Decoded_VkPhysicalDeviceShaderFloatControls2Features Decoded_VkPhysicalDeviceShaderFloatControls2FeaturesKHR;

typedef Decoded_VkPhysicalDeviceIndexTypeUint8Features Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesKHR;

typedef Decoded_VkPhysicalDeviceLineRasterizationFeatures Decoded_VkPhysicalDeviceLineRasterizationFeaturesKHR;

typedef Decoded_VkPhysicalDeviceLineRasterizationProperties Decoded_VkPhysicalDeviceLineRasterizationPropertiesKHR;

typedef Decoded_VkPipelineRasterizationLineStateCreateInfo Decoded_VkPipelineRasterizationLineStateCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceShaderExpectAssumeFeatures Decoded_VkPhysicalDeviceShaderExpectAssumeFeaturesKHR;

typedef Decoded_VkPhysicalDeviceMaintenance6Features Decoded_VkPhysicalDeviceMaintenance6FeaturesKHR;

typedef Decoded_VkPhysicalDeviceMaintenance6Properties Decoded_VkPhysicalDeviceMaintenance6PropertiesKHR;

typedef Decoded_VkBindMemoryStatus Decoded_VkBindMemoryStatusKHR;

typedef Decoded_VkBindDescriptorSetsInfo Decoded_VkBindDescriptorSetsInfoKHR;

typedef Decoded_VkPushConstantsInfo Decoded_VkPushConstantsInfoKHR;

typedef Decoded_VkPushDescriptorSetInfo Decoded_VkPushDescriptorSetInfoKHR;

typedef Decoded_VkPushDescriptorSetWithTemplateInfo Decoded_VkPushDescriptorSetWithTemplateInfoKHR;

typedef Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT;

typedef Decoded_VkPhysicalDevicePipelineRobustnessFeatures Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT;

typedef Decoded_VkPhysicalDevicePipelineRobustnessProperties Decoded_VkPhysicalDevicePipelineRobustnessPropertiesEXT;

typedef Decoded_VkPipelineRobustnessCreateInfo Decoded_VkPipelineRobustnessCreateInfoEXT;

typedef Decoded_VkSamplerReductionModeCreateInfo Decoded_VkSamplerReductionModeCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT;

typedef Decoded_VkPhysicalDeviceInlineUniformBlockFeatures Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT;

typedef Decoded_VkPhysicalDeviceInlineUniformBlockProperties Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT;

typedef Decoded_VkWriteDescriptorSetInlineUniformBlock Decoded_VkWriteDescriptorSetInlineUniformBlockEXT;

typedef Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT;

typedef Decoded_VkAttachmentSampleCountInfoAMD Decoded_VkAttachmentSampleCountInfoNV;

typedef Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceDescriptorIndexingFeatures Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT;

typedef Decoded_VkPhysicalDeviceDescriptorIndexingProperties Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT;

typedef Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT;

typedef Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT;

typedef Decoded_VkTransformMatrixKHR Decoded_VkTransformMatrixNV;

typedef Decoded_VkAabbPositionsKHR Decoded_VkAabbPositionsNV;

typedef Decoded_VkAccelerationStructureInstanceKHR Decoded_VkAccelerationStructureInstanceNV;

typedef Decoded_VkDeviceQueueGlobalPriorityCreateInfo Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT;

typedef Decoded_VkCalibratedTimestampInfoKHR Decoded_VkCalibratedTimestampInfoEXT;

typedef Decoded_VkVertexInputBindingDivisorDescription Decoded_VkVertexInputBindingDivisorDescriptionEXT;

typedef Decoded_VkPipelineVertexInputDivisorStateCreateInfo Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT;

typedef Decoded_VkPipelineCreationFeedbackCreateInfo Decoded_VkPipelineCreationFeedbackCreateInfoEXT;

typedef Decoded_VkPipelineCreationFeedback Decoded_VkPipelineCreationFeedbackEXT;

typedef Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV;

typedef Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV;

typedef Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL Decoded_VkQueryPoolCreateInfoINTEL;

typedef Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures Decoded_VkPhysicalDeviceScalarBlockLayoutFeaturesEXT;

typedef Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures Decoded_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT;

typedef Decoded_VkPhysicalDeviceSubgroupSizeControlProperties Decoded_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT;

typedef Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT Decoded_VkPhysicalDeviceBufferAddressFeaturesEXT;

typedef Decoded_VkBufferDeviceAddressInfo Decoded_VkBufferDeviceAddressInfoEXT;

typedef Decoded_VkPhysicalDeviceToolProperties Decoded_VkPhysicalDeviceToolPropertiesEXT;

typedef Decoded_VkImageStencilUsageCreateInfo Decoded_VkImageStencilUsageCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceLineRasterizationFeatures Decoded_VkPhysicalDeviceLineRasterizationFeaturesEXT;

typedef Decoded_VkPhysicalDeviceLineRasterizationProperties Decoded_VkPhysicalDeviceLineRasterizationPropertiesEXT;

typedef Decoded_VkPipelineRasterizationLineStateCreateInfo Decoded_VkPipelineRasterizationLineStateCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceHostQueryResetFeatures Decoded_VkPhysicalDeviceHostQueryResetFeaturesEXT;

typedef Decoded_VkPhysicalDeviceIndexTypeUint8Features Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesEXT;

typedef Decoded_VkPhysicalDeviceHostImageCopyFeatures Decoded_VkPhysicalDeviceHostImageCopyFeaturesEXT;

typedef Decoded_VkPhysicalDeviceHostImageCopyProperties Decoded_VkPhysicalDeviceHostImageCopyPropertiesEXT;

typedef Decoded_VkMemoryToImageCopy Decoded_VkMemoryToImageCopyEXT;

typedef Decoded_VkImageToMemoryCopy Decoded_VkImageToMemoryCopyEXT;

typedef Decoded_VkCopyMemoryToImageInfo Decoded_VkCopyMemoryToImageInfoEXT;

typedef Decoded_VkCopyImageToMemoryInfo Decoded_VkCopyImageToMemoryInfoEXT;

typedef Decoded_VkCopyImageToImageInfo Decoded_VkCopyImageToImageInfoEXT;

typedef Decoded_VkHostImageLayoutTransitionInfo Decoded_VkHostImageLayoutTransitionInfoEXT;

typedef Decoded_VkSubresourceHostMemcpySize Decoded_VkSubresourceHostMemcpySizeEXT;

typedef Decoded_VkHostImageCopyDevicePerformanceQuery Decoded_VkHostImageCopyDevicePerformanceQueryEXT;

typedef Decoded_VkSubresourceLayout2 Decoded_VkSubresourceLayout2EXT;

typedef Decoded_VkImageSubresource2 Decoded_VkImageSubresource2EXT;

typedef Decoded_VkSurfacePresentModeKHR Decoded_VkSurfacePresentModeEXT;

typedef Decoded_VkSurfacePresentScalingCapabilitiesKHR Decoded_VkSurfacePresentScalingCapabilitiesEXT;

typedef Decoded_VkSurfacePresentModeCompatibilityKHR Decoded_VkSurfacePresentModeCompatibilityEXT;

typedef Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT;

typedef Decoded_VkSwapchainPresentFenceInfoKHR Decoded_VkSwapchainPresentFenceInfoEXT;

typedef Decoded_VkSwapchainPresentModesCreateInfoKHR Decoded_VkSwapchainPresentModesCreateInfoEXT;

typedef Decoded_VkSwapchainPresentModeInfoKHR Decoded_VkSwapchainPresentModeInfoEXT;

typedef Decoded_VkSwapchainPresentScalingCreateInfoKHR Decoded_VkSwapchainPresentScalingCreateInfoEXT;

typedef Decoded_VkReleaseSwapchainImagesInfoKHR Decoded_VkReleaseSwapchainImagesInfoEXT;

typedef Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT;

typedef Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties Decoded_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT;

typedef Decoded_VkPhysicalDeviceRobustness2FeaturesKHR Decoded_VkPhysicalDeviceRobustness2FeaturesEXT;

typedef Decoded_VkPhysicalDeviceRobustness2PropertiesKHR Decoded_VkPhysicalDeviceRobustness2PropertiesEXT;

typedef Decoded_VkPhysicalDevicePrivateDataFeatures Decoded_VkPhysicalDevicePrivateDataFeaturesEXT;

typedef Decoded_VkDevicePrivateDataCreateInfo Decoded_VkDevicePrivateDataCreateInfoEXT;

typedef Decoded_VkPrivateDataSlotCreateInfo Decoded_VkPrivateDataSlotCreateInfoEXT;

typedef Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures Decoded_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT;

typedef Decoded_VkPhysicalDeviceImageRobustnessFeatures Decoded_VkPhysicalDeviceImageRobustnessFeaturesEXT;

typedef Decoded_VkDeviceFaultAddressInfoKHR Decoded_VkDeviceFaultAddressInfoEXT;

typedef Decoded_VkDeviceFaultVendorInfoKHR Decoded_VkDeviceFaultVendorInfoEXT;

typedef Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneKHR Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneEXT;

typedef Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM;

typedef Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE;

typedef Decoded_VkMutableDescriptorTypeListEXT Decoded_VkMutableDescriptorTypeListVALVE;

typedef Decoded_VkMutableDescriptorTypeCreateInfoEXT Decoded_VkMutableDescriptorTypeCreateInfoVALVE;

typedef Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesEXT;

typedef Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT;

typedef Decoded_VkQueueFamilyGlobalPriorityProperties Decoded_VkQueueFamilyGlobalPriorityPropertiesEXT;

typedef Decoded_VkMicromapTriangleKHR Decoded_VkMicromapTriangleEXT;

typedef Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT;

typedef Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM;

typedef Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM;

typedef Decoded_VkRenderPassFragmentDensityMapOffsetEndInfoEXT Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM;

typedef Decoded_VkPhysicalDevicePipelineProtectedAccessFeatures Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT;

typedef Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo Decoded_VkShaderRequiredSubgroupSizeCreateInfoEXT;

typedef Decoded_VkRenderingEndInfoKHR Decoded_VkRenderingEndInfoEXT;

struct Decoded_VkBaseOutStructure
{
    using struct_type = VkBaseOutStructure;

    union VkBaseOutStructureSizeUnion
    {
        VkQueueFamilyDataGraphOpticalFlowPropertiesARM a;
        VkQueueFamilyDataGraphProcessingEnginePropertiesARM b;
    };

    using union_size_type = VkBaseOutStructureSizeUnion;

    VkBaseOutStructure* decoded_value{ nullptr };
    PNextNode*          pNext{ nullptr };

    static Decoded_VkBaseOutStructure* AllocateAppropriate(const uint8_t* buffer, size_t buffer_size, size_t len, bool initialize = false)
    {
        Decoded_VkBaseOutStructure* return_type = nullptr;

        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        VkStructureType vk_type = static_cast<VkStructureType>(peek_structure_type);

        switch (vk_type)
        {
            default:
                GFXRECON_LOG_WARNING_ONCE("Decoded_VkBaseOutStructure::AllocateAppropriate: unrecognized sType 0x%x", peek_structure_type);
                return_type = DecodeAllocator::Allocate<Decoded_VkBaseOutStructure>(len, initialize);
                break;
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_OPTICAL_FLOW_PROPERTIES_ARM:
                return_type = reinterpret_cast<Decoded_VkBaseOutStructure*>(DecodeAllocator::Allocate<Decoded_VkQueueFamilyDataGraphOpticalFlowPropertiesARM>(len, initialize));
                break;
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM:
                return_type = reinterpret_cast<Decoded_VkBaseOutStructure*>(DecodeAllocator::Allocate<Decoded_VkQueueFamilyDataGraphProcessingEnginePropertiesARM>(len, initialize));
                break;
        }
        return return_type;
    }

    static size_t DecodeAppropriate(const uint8_t* buffer, size_t buffer_size, Decoded_VkBaseOutStructure* dest)
    {
        size_t bytes_read = 0;

        uint32_t peek_structure_type = 0;
        ValueDecoder::DecodeUInt32Value(buffer, buffer_size, &peek_structure_type);
        VkStructureType vk_type = static_cast<VkStructureType>(peek_structure_type);

        switch (vk_type)
        {
            default:
                GFXRECON_LOG_WARNING_ONCE("Decoded_VkBaseOutStructure::DecodeAppropriate: unrecognized sType 0x%x", peek_structure_type);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), dest);
                break;
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_OPTICAL_FLOW_PROPERTIES_ARM:
            {
                Decoded_VkQueueFamilyDataGraphOpticalFlowPropertiesARM* local_dest = reinterpret_cast<Decoded_VkQueueFamilyDataGraphOpticalFlowPropertiesARM*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM:
            {
                Decoded_VkQueueFamilyDataGraphProcessingEnginePropertiesARM* local_dest = reinterpret_cast<Decoded_VkQueueFamilyDataGraphProcessingEnginePropertiesARM*>(dest);
                bytes_read += DecodeStruct((buffer + bytes_read), (buffer_size - bytes_read), local_dest);
                break;
            }
        }
        return bytes_read;
    }

    VkBaseOutStructure* AllocateOutputData(size_t len)
    {
        assert(decoded_value != nullptr);

        switch (decoded_value->sType)
        {
            default:
                return DecodeAllocator::Allocate<VkBaseOutStructure>(len);
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_OPTICAL_FLOW_PROPERTIES_ARM:
            {
                auto* allocation = DecodeAllocator::Allocate<VkQueueFamilyDataGraphOpticalFlowPropertiesARM>(len);
                for (size_t i = 0; i < len; ++i)
                {
                    allocation[i] = VkQueueFamilyDataGraphOpticalFlowPropertiesARM{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_OPTICAL_FLOW_PROPERTIES_ARM, nullptr };
                }
                return reinterpret_cast<VkBaseOutStructure*>(allocation);
            }
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM:
            {
                auto* allocation = DecodeAllocator::Allocate<VkQueueFamilyDataGraphProcessingEnginePropertiesARM>(len);
                for (size_t i = 0; i < len; ++i)
                {
                    allocation[i] = VkQueueFamilyDataGraphProcessingEnginePropertiesARM{ VK_STRUCTURE_TYPE_QUEUE_FAMILY_DATA_GRAPH_PROCESSING_ENGINE_PROPERTIES_ARM, nullptr };
                }
                return reinterpret_cast<VkBaseOutStructure*>(allocation);
            }
        }
    }
};


GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_STRUCT_DECODERS_H
