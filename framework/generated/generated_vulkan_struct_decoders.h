/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2023 LunarG, Inc.
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
#include "decode/vulkan_pnext_node.h"
#include "format/format.h"
#include "format/platform_types.h"
#include "generated/generated_vulkan_struct_decoders_forward.h"
#include "util/defines.h"

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

    StdVideoH264SpsVuiFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH264HrdParameters
{
    using struct_type = StdVideoH264HrdParameters;

    StdVideoH264HrdParameters* decoded_value{ nullptr };

    PointerDecoder<uint32_t> bit_rate_value_minus1;
    PointerDecoder<uint32_t> cpb_size_value_minus1;
    PointerDecoder<uint8_t> cbr_flag;
};

struct Decoded_StdVideoH264SequenceParameterSetVui
{
    using struct_type = StdVideoH264SequenceParameterSetVui;

    StdVideoH264SequenceParameterSetVui* decoded_value{ nullptr };

    Decoded_StdVideoH264SpsVuiFlags* flags{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264HrdParameters>* pHrdParameters{ nullptr };
};

struct Decoded_StdVideoH264SpsFlags
{
    using struct_type = StdVideoH264SpsFlags;

    StdVideoH264SpsFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH264ScalingLists
{
    using struct_type = StdVideoH264ScalingLists;

    StdVideoH264ScalingLists* decoded_value{ nullptr };

    PointerDecoder<uint8_t> ScalingList4x4;
    PointerDecoder<uint8_t> ScalingList8x8;
};

struct Decoded_StdVideoH264SequenceParameterSet
{
    using struct_type = StdVideoH264SequenceParameterSet;

    StdVideoH264SequenceParameterSet* decoded_value{ nullptr };

    Decoded_StdVideoH264SpsFlags* flags{ nullptr };
    PointerDecoder<int32_t> pOffsetForRefFrame;
    StructPointerDecoder<Decoded_StdVideoH264ScalingLists>* pScalingLists{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264SequenceParameterSetVui>* pSequenceParameterSetVui{ nullptr };
};

struct Decoded_StdVideoH264PpsFlags
{
    using struct_type = StdVideoH264PpsFlags;

    StdVideoH264PpsFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH264PictureParameterSet
{
    using struct_type = StdVideoH264PictureParameterSet;

    StdVideoH264PictureParameterSet* decoded_value{ nullptr };

    Decoded_StdVideoH264PpsFlags* flags{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264ScalingLists>* pScalingLists{ nullptr };
};

struct Decoded_StdVideoDecodeH264PictureInfoFlags
{
    using struct_type = StdVideoDecodeH264PictureInfoFlags;

    StdVideoDecodeH264PictureInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeH264PictureInfo
{
    using struct_type = StdVideoDecodeH264PictureInfo;

    StdVideoDecodeH264PictureInfo* decoded_value{ nullptr };

    Decoded_StdVideoDecodeH264PictureInfoFlags* flags{ nullptr };
    PointerDecoder<int32_t> PicOrderCnt;
};

struct Decoded_StdVideoDecodeH264ReferenceInfoFlags
{
    using struct_type = StdVideoDecodeH264ReferenceInfoFlags;

    StdVideoDecodeH264ReferenceInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeH264ReferenceInfo
{
    using struct_type = StdVideoDecodeH264ReferenceInfo;

    StdVideoDecodeH264ReferenceInfo* decoded_value{ nullptr };

    Decoded_StdVideoDecodeH264ReferenceInfoFlags* flags{ nullptr };
    PointerDecoder<int32_t> PicOrderCnt;
};

struct Decoded_StdVideoEncodeH264WeightTableFlags
{
    using struct_type = StdVideoEncodeH264WeightTableFlags;

    StdVideoEncodeH264WeightTableFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264WeightTable
{
    using struct_type = StdVideoEncodeH264WeightTable;

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

    StdVideoEncodeH264SliceHeaderFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264PictureInfoFlags
{
    using struct_type = StdVideoEncodeH264PictureInfoFlags;

    StdVideoEncodeH264PictureInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264ReferenceInfoFlags
{
    using struct_type = StdVideoEncodeH264ReferenceInfoFlags;

    StdVideoEncodeH264ReferenceInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264ReferenceListsInfoFlags
{
    using struct_type = StdVideoEncodeH264ReferenceListsInfoFlags;

    StdVideoEncodeH264ReferenceListsInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264RefListModEntry
{
    using struct_type = StdVideoEncodeH264RefListModEntry;

    StdVideoEncodeH264RefListModEntry* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264RefPicMarkingEntry
{
    using struct_type = StdVideoEncodeH264RefPicMarkingEntry;

    StdVideoEncodeH264RefPicMarkingEntry* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH264ReferenceListsInfo
{
    using struct_type = StdVideoEncodeH264ReferenceListsInfo;

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

    StdVideoEncodeH264PictureInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH264PictureInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> reserved1;
    StructPointerDecoder<Decoded_StdVideoEncodeH264ReferenceListsInfo>* pRefLists{ nullptr };
};

struct Decoded_StdVideoEncodeH264ReferenceInfo
{
    using struct_type = StdVideoEncodeH264ReferenceInfo;

    StdVideoEncodeH264ReferenceInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH264ReferenceInfoFlags* flags{ nullptr };
};

struct Decoded_StdVideoEncodeH264SliceHeader
{
    using struct_type = StdVideoEncodeH264SliceHeader;

    StdVideoEncodeH264SliceHeader* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH264SliceHeaderFlags* flags{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH264WeightTable>* pWeightTable{ nullptr };
};

struct Decoded_StdVideoH265ProfileTierLevelFlags
{
    using struct_type = StdVideoH265ProfileTierLevelFlags;

    StdVideoH265ProfileTierLevelFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH265ProfileTierLevel
{
    using struct_type = StdVideoH265ProfileTierLevel;

    StdVideoH265ProfileTierLevel* decoded_value{ nullptr };

    Decoded_StdVideoH265ProfileTierLevelFlags* flags{ nullptr };
};

struct Decoded_StdVideoH265DecPicBufMgr
{
    using struct_type = StdVideoH265DecPicBufMgr;

    StdVideoH265DecPicBufMgr* decoded_value{ nullptr };

    PointerDecoder<uint32_t> max_latency_increase_plus1;
    PointerDecoder<uint8_t> max_dec_pic_buffering_minus1;
    PointerDecoder<uint8_t> max_num_reorder_pics;
};

struct Decoded_StdVideoH265SubLayerHrdParameters
{
    using struct_type = StdVideoH265SubLayerHrdParameters;

    StdVideoH265SubLayerHrdParameters* decoded_value{ nullptr };

    PointerDecoder<uint32_t> bit_rate_value_minus1;
    PointerDecoder<uint32_t> cpb_size_value_minus1;
    PointerDecoder<uint32_t> cpb_size_du_value_minus1;
    PointerDecoder<uint32_t> bit_rate_du_value_minus1;
};

struct Decoded_StdVideoH265HrdFlags
{
    using struct_type = StdVideoH265HrdFlags;

    StdVideoH265HrdFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH265HrdParameters
{
    using struct_type = StdVideoH265HrdParameters;

    StdVideoH265HrdParameters* decoded_value{ nullptr };

    Decoded_StdVideoH265HrdFlags* flags{ nullptr };
    PointerDecoder<uint8_t> cpb_cnt_minus1;
    PointerDecoder<uint16_t> elemental_duration_in_tc_minus1;
    PointerDecoder<uint16_t> reserved;
    StructPointerDecoder<Decoded_StdVideoH265SubLayerHrdParameters>* pSubLayerHrdParametersNal{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265SubLayerHrdParameters>* pSubLayerHrdParametersVcl{ nullptr };
};

struct Decoded_StdVideoH265VpsFlags
{
    using struct_type = StdVideoH265VpsFlags;

    StdVideoH265VpsFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH265VideoParameterSet
{
    using struct_type = StdVideoH265VideoParameterSet;

    StdVideoH265VideoParameterSet* decoded_value{ nullptr };

    Decoded_StdVideoH265VpsFlags* flags{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265DecPicBufMgr>* pDecPicBufMgr{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265HrdParameters>* pHrdParameters{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265ProfileTierLevel>* pProfileTierLevel{ nullptr };
};

struct Decoded_StdVideoH265ScalingLists
{
    using struct_type = StdVideoH265ScalingLists;

    StdVideoH265ScalingLists* decoded_value{ nullptr };

    PointerDecoder<uint8_t> ScalingList4x4;
    PointerDecoder<uint8_t> ScalingList8x8;
    PointerDecoder<uint8_t> ScalingList16x16;
    PointerDecoder<uint8_t> ScalingList32x32;
    PointerDecoder<uint8_t> ScalingListDCCoef16x16;
    PointerDecoder<uint8_t> ScalingListDCCoef32x32;
};

struct Decoded_StdVideoH265ShortTermRefPicSetFlags
{
    using struct_type = StdVideoH265ShortTermRefPicSetFlags;

    StdVideoH265ShortTermRefPicSetFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH265ShortTermRefPicSet
{
    using struct_type = StdVideoH265ShortTermRefPicSet;

    StdVideoH265ShortTermRefPicSet* decoded_value{ nullptr };

    Decoded_StdVideoH265ShortTermRefPicSetFlags* flags{ nullptr };
    PointerDecoder<uint16_t> delta_poc_s0_minus1;
    PointerDecoder<uint16_t> delta_poc_s1_minus1;
};

struct Decoded_StdVideoH265LongTermRefPicsSps
{
    using struct_type = StdVideoH265LongTermRefPicsSps;

    StdVideoH265LongTermRefPicsSps* decoded_value{ nullptr };

    PointerDecoder<uint32_t> lt_ref_pic_poc_lsb_sps;
};

struct Decoded_StdVideoH265SpsVuiFlags
{
    using struct_type = StdVideoH265SpsVuiFlags;

    StdVideoH265SpsVuiFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH265SequenceParameterSetVui
{
    using struct_type = StdVideoH265SequenceParameterSetVui;

    StdVideoH265SequenceParameterSetVui* decoded_value{ nullptr };

    Decoded_StdVideoH265SpsVuiFlags* flags{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265HrdParameters>* pHrdParameters{ nullptr };
};

struct Decoded_StdVideoH265PredictorPaletteEntries
{
    using struct_type = StdVideoH265PredictorPaletteEntries;

    StdVideoH265PredictorPaletteEntries* decoded_value{ nullptr };

    PointerDecoder<uint16_t> PredictorPaletteEntries;
};

struct Decoded_StdVideoH265SpsFlags
{
    using struct_type = StdVideoH265SpsFlags;

    StdVideoH265SpsFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH265SequenceParameterSet
{
    using struct_type = StdVideoH265SequenceParameterSet;

    StdVideoH265SequenceParameterSet* decoded_value{ nullptr };

    Decoded_StdVideoH265SpsFlags* flags{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265ProfileTierLevel>* pProfileTierLevel{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265DecPicBufMgr>* pDecPicBufMgr{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265ScalingLists>* pScalingLists{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265ShortTermRefPicSet>* pShortTermRefPicSet{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265LongTermRefPicsSps>* pLongTermRefPicsSps{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265SequenceParameterSetVui>* pSequenceParameterSetVui{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265PredictorPaletteEntries>* pPredictorPaletteEntries{ nullptr };
};

struct Decoded_StdVideoH265PpsFlags
{
    using struct_type = StdVideoH265PpsFlags;

    StdVideoH265PpsFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoH265PictureParameterSet
{
    using struct_type = StdVideoH265PictureParameterSet;

    StdVideoH265PictureParameterSet* decoded_value{ nullptr };

    Decoded_StdVideoH265PpsFlags* flags{ nullptr };
    PointerDecoder<int8_t> cb_qp_offset_list;
    PointerDecoder<int8_t> cr_qp_offset_list;
    PointerDecoder<uint16_t> column_width_minus1;
    PointerDecoder<uint16_t> row_height_minus1;
    StructPointerDecoder<Decoded_StdVideoH265ScalingLists>* pScalingLists{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265PredictorPaletteEntries>* pPredictorPaletteEntries{ nullptr };
};

struct Decoded_StdVideoDecodeH265PictureInfoFlags
{
    using struct_type = StdVideoDecodeH265PictureInfoFlags;

    StdVideoDecodeH265PictureInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeH265PictureInfo
{
    using struct_type = StdVideoDecodeH265PictureInfo;

    StdVideoDecodeH265PictureInfo* decoded_value{ nullptr };

    Decoded_StdVideoDecodeH265PictureInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> RefPicSetStCurrBefore;
    PointerDecoder<uint8_t> RefPicSetStCurrAfter;
    PointerDecoder<uint8_t> RefPicSetLtCurr;
};

struct Decoded_StdVideoDecodeH265ReferenceInfoFlags
{
    using struct_type = StdVideoDecodeH265ReferenceInfoFlags;

    StdVideoDecodeH265ReferenceInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeH265ReferenceInfo
{
    using struct_type = StdVideoDecodeH265ReferenceInfo;

    StdVideoDecodeH265ReferenceInfo* decoded_value{ nullptr };

    Decoded_StdVideoDecodeH265ReferenceInfoFlags* flags{ nullptr };
};

struct Decoded_StdVideoEncodeH265WeightTableFlags
{
    using struct_type = StdVideoEncodeH265WeightTableFlags;

    StdVideoEncodeH265WeightTableFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH265WeightTable
{
    using struct_type = StdVideoEncodeH265WeightTable;

    StdVideoEncodeH265WeightTable* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH265WeightTableFlags* flags{ nullptr };
    PointerDecoder<int8_t> delta_luma_weight_l0;
    PointerDecoder<int8_t> luma_offset_l0;
    PointerDecoder<int8_t> delta_chroma_weight_l0;
    PointerDecoder<int8_t> delta_chroma_offset_l0;
    PointerDecoder<int8_t> delta_luma_weight_l1;
    PointerDecoder<int8_t> luma_offset_l1;
    PointerDecoder<int8_t> delta_chroma_weight_l1;
    PointerDecoder<int8_t> delta_chroma_offset_l1;
};

struct Decoded_StdVideoEncodeH265LongTermRefPics
{
    using struct_type = StdVideoEncodeH265LongTermRefPics;

    StdVideoEncodeH265LongTermRefPics* decoded_value{ nullptr };

    PointerDecoder<uint8_t> lt_idx_sps;
    PointerDecoder<uint8_t> poc_lsb_lt;
    PointerDecoder<uint8_t> delta_poc_msb_present_flag;
    PointerDecoder<uint8_t> delta_poc_msb_cycle_lt;
};

struct Decoded_StdVideoEncodeH265SliceSegmentHeaderFlags
{
    using struct_type = StdVideoEncodeH265SliceSegmentHeaderFlags;

    StdVideoEncodeH265SliceSegmentHeaderFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH265SliceSegmentHeader
{
    using struct_type = StdVideoEncodeH265SliceSegmentHeader;

    StdVideoEncodeH265SliceSegmentHeader* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH265SliceSegmentHeaderFlags* flags{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH265WeightTable>* pWeightTable{ nullptr };
};

struct Decoded_StdVideoEncodeH265ReferenceListsInfoFlags
{
    using struct_type = StdVideoEncodeH265ReferenceListsInfoFlags;

    StdVideoEncodeH265ReferenceListsInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH265ReferenceListsInfo
{
    using struct_type = StdVideoEncodeH265ReferenceListsInfo;

    StdVideoEncodeH265ReferenceListsInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH265ReferenceListsInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> RefPicList0;
    PointerDecoder<uint8_t> RefPicList1;
    PointerDecoder<uint8_t> list_entry_l0;
    PointerDecoder<uint8_t> list_entry_l1;
};

struct Decoded_StdVideoEncodeH265PictureInfoFlags
{
    using struct_type = StdVideoEncodeH265PictureInfoFlags;

    StdVideoEncodeH265PictureInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH265PictureInfo
{
    using struct_type = StdVideoEncodeH265PictureInfo;

    StdVideoEncodeH265PictureInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH265PictureInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> reserved1;
    StructPointerDecoder<Decoded_StdVideoEncodeH265ReferenceListsInfo>* pRefLists{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265ShortTermRefPicSet>* pShortTermRefPicSet{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH265LongTermRefPics>* pLongTermRefPics{ nullptr };
};

struct Decoded_StdVideoEncodeH265ReferenceInfoFlags
{
    using struct_type = StdVideoEncodeH265ReferenceInfoFlags;

    StdVideoEncodeH265ReferenceInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoEncodeH265ReferenceInfo
{
    using struct_type = StdVideoEncodeH265ReferenceInfo;

    StdVideoEncodeH265ReferenceInfo* decoded_value{ nullptr };

    Decoded_StdVideoEncodeH265ReferenceInfoFlags* flags{ nullptr };
};

struct Decoded_StdVideoAV1ColorConfigFlags
{
    using struct_type = StdVideoAV1ColorConfigFlags;

    StdVideoAV1ColorConfigFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1ColorConfig
{
    using struct_type = StdVideoAV1ColorConfig;

    StdVideoAV1ColorConfig* decoded_value{ nullptr };

    Decoded_StdVideoAV1ColorConfigFlags* flags{ nullptr };
};

struct Decoded_StdVideoAV1TimingInfoFlags
{
    using struct_type = StdVideoAV1TimingInfoFlags;

    StdVideoAV1TimingInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1TimingInfo
{
    using struct_type = StdVideoAV1TimingInfo;

    StdVideoAV1TimingInfo* decoded_value{ nullptr };

    Decoded_StdVideoAV1TimingInfoFlags* flags{ nullptr };
};

struct Decoded_StdVideoAV1SequenceHeaderFlags
{
    using struct_type = StdVideoAV1SequenceHeaderFlags;

    StdVideoAV1SequenceHeaderFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1SequenceHeader
{
    using struct_type = StdVideoAV1SequenceHeader;

    StdVideoAV1SequenceHeader* decoded_value{ nullptr };

    Decoded_StdVideoAV1SequenceHeaderFlags* flags{ nullptr };
    PointerDecoder<uint8_t> reserved1;
    StructPointerDecoder<Decoded_StdVideoAV1ColorConfig>* pColorConfig{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1TimingInfo>* pTimingInfo{ nullptr };
};

struct Decoded_StdVideoAV1LoopFilterFlags
{
    using struct_type = StdVideoAV1LoopFilterFlags;

    StdVideoAV1LoopFilterFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1LoopFilter
{
    using struct_type = StdVideoAV1LoopFilter;

    StdVideoAV1LoopFilter* decoded_value{ nullptr };

    Decoded_StdVideoAV1LoopFilterFlags* flags{ nullptr };
    PointerDecoder<uint8_t> loop_filter_level;
    PointerDecoder<int8_t> loop_filter_ref_deltas;
    PointerDecoder<int8_t> loop_filter_mode_deltas;
};

struct Decoded_StdVideoAV1QuantizationFlags
{
    using struct_type = StdVideoAV1QuantizationFlags;

    StdVideoAV1QuantizationFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1Quantization
{
    using struct_type = StdVideoAV1Quantization;

    StdVideoAV1Quantization* decoded_value{ nullptr };

    Decoded_StdVideoAV1QuantizationFlags* flags{ nullptr };
};

struct Decoded_StdVideoAV1Segmentation
{
    using struct_type = StdVideoAV1Segmentation;

    StdVideoAV1Segmentation* decoded_value{ nullptr };

    PointerDecoder<uint8_t> FeatureEnabled;
    PointerDecoder<int16_t> FeatureData;
};

struct Decoded_StdVideoAV1TileInfoFlags
{
    using struct_type = StdVideoAV1TileInfoFlags;

    StdVideoAV1TileInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1TileInfo
{
    using struct_type = StdVideoAV1TileInfo;

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

    StdVideoAV1CDEF* decoded_value{ nullptr };

    PointerDecoder<uint8_t> cdef_y_pri_strength;
    PointerDecoder<uint8_t> cdef_y_sec_strength;
    PointerDecoder<uint8_t> cdef_uv_pri_strength;
    PointerDecoder<uint8_t> cdef_uv_sec_strength;
};

struct Decoded_StdVideoAV1LoopRestoration
{
    using struct_type = StdVideoAV1LoopRestoration;

    StdVideoAV1LoopRestoration* decoded_value{ nullptr };

    PointerDecoder<StdVideoAV1FrameRestorationType> FrameRestorationType;
    PointerDecoder<uint16_t> LoopRestorationSize;
};

struct Decoded_StdVideoAV1GlobalMotion
{
    using struct_type = StdVideoAV1GlobalMotion;

    StdVideoAV1GlobalMotion* decoded_value{ nullptr };

    PointerDecoder<uint8_t> GmType;
    PointerDecoder<int32_t> gm_params;
};

struct Decoded_StdVideoAV1FilmGrainFlags
{
    using struct_type = StdVideoAV1FilmGrainFlags;

    StdVideoAV1FilmGrainFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoAV1FilmGrain
{
    using struct_type = StdVideoAV1FilmGrain;

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

    StdVideoDecodeAV1PictureInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeAV1PictureInfo
{
    using struct_type = StdVideoDecodeAV1PictureInfo;

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

    StdVideoDecodeAV1ReferenceInfoFlags* decoded_value{ nullptr };
};

struct Decoded_StdVideoDecodeAV1ReferenceInfo
{
    using struct_type = StdVideoDecodeAV1ReferenceInfo;

    StdVideoDecodeAV1ReferenceInfo* decoded_value{ nullptr };

    Decoded_StdVideoDecodeAV1ReferenceInfoFlags* flags{ nullptr };
    PointerDecoder<uint8_t> SavedOrderHints;
};

struct Decoded_VkExtent2D
{
    using struct_type = VkExtent2D;

    VkExtent2D* decoded_value{ nullptr };
};

struct Decoded_VkExtent3D
{
    using struct_type = VkExtent3D;

    VkExtent3D* decoded_value{ nullptr };
};

struct Decoded_VkOffset2D
{
    using struct_type = VkOffset2D;

    VkOffset2D* decoded_value{ nullptr };
};

struct Decoded_VkOffset3D
{
    using struct_type = VkOffset3D;

    VkOffset3D* decoded_value{ nullptr };
};

struct Decoded_VkRect2D
{
    using struct_type = VkRect2D;

    VkRect2D* decoded_value{ nullptr };

    Decoded_VkOffset2D* offset{ nullptr };
    Decoded_VkExtent2D* extent{ nullptr };
};

struct Decoded_VkBufferMemoryBarrier
{
    using struct_type = VkBufferMemoryBarrier;

    VkBufferMemoryBarrier* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkDispatchIndirectCommand
{
    using struct_type = VkDispatchIndirectCommand;

    VkDispatchIndirectCommand* decoded_value{ nullptr };
};

struct Decoded_VkDrawIndexedIndirectCommand
{
    using struct_type = VkDrawIndexedIndirectCommand;

    VkDrawIndexedIndirectCommand* decoded_value{ nullptr };
};

struct Decoded_VkDrawIndirectCommand
{
    using struct_type = VkDrawIndirectCommand;

    VkDrawIndirectCommand* decoded_value{ nullptr };
};

struct Decoded_VkImageSubresourceRange
{
    using struct_type = VkImageSubresourceRange;

    VkImageSubresourceRange* decoded_value{ nullptr };
};

struct Decoded_VkImageMemoryBarrier
{
    using struct_type = VkImageMemoryBarrier;

    VkImageMemoryBarrier* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    Decoded_VkImageSubresourceRange* subresourceRange{ nullptr };
};

struct Decoded_VkMemoryBarrier
{
    using struct_type = VkMemoryBarrier;

    VkMemoryBarrier* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCacheHeaderVersionOne
{
    using struct_type = VkPipelineCacheHeaderVersionOne;

    VkPipelineCacheHeaderVersionOne* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pipelineCacheUUID;
};

struct Decoded_VkAllocationCallbacks
{
    using struct_type = VkAllocationCallbacks;

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

    VkApplicationInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder pApplicationName;
    StringDecoder pEngineName;
};

struct Decoded_VkFormatProperties
{
    using struct_type = VkFormatProperties;

    VkFormatProperties* decoded_value{ nullptr };
};

struct Decoded_VkImageFormatProperties
{
    using struct_type = VkImageFormatProperties;

    VkImageFormatProperties* decoded_value{ nullptr };

    Decoded_VkExtent3D* maxExtent{ nullptr };
};

struct Decoded_VkInstanceCreateInfo
{
    using struct_type = VkInstanceCreateInfo;

    VkInstanceCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkApplicationInfo>* pApplicationInfo{ nullptr };
    StringArrayDecoder ppEnabledLayerNames;
    StringArrayDecoder ppEnabledExtensionNames;
};

struct Decoded_VkMemoryHeap
{
    using struct_type = VkMemoryHeap;

    VkMemoryHeap* decoded_value{ nullptr };
};

struct Decoded_VkMemoryType
{
    using struct_type = VkMemoryType;

    VkMemoryType* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceFeatures
{
    using struct_type = VkPhysicalDeviceFeatures;

    VkPhysicalDeviceFeatures* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceLimits
{
    using struct_type = VkPhysicalDeviceLimits;

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

    VkPhysicalDeviceMemoryProperties* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkMemoryType>* memoryTypes{ nullptr };
    StructPointerDecoder<Decoded_VkMemoryHeap>* memoryHeaps{ nullptr };
};

struct Decoded_VkPhysicalDeviceSparseProperties
{
    using struct_type = VkPhysicalDeviceSparseProperties;

    VkPhysicalDeviceSparseProperties* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceProperties
{
    using struct_type = VkPhysicalDeviceProperties;

    VkPhysicalDeviceProperties* decoded_value{ nullptr };

    StringDecoder deviceName;
    PointerDecoder<uint8_t> pipelineCacheUUID;
    Decoded_VkPhysicalDeviceLimits* limits{ nullptr };
    Decoded_VkPhysicalDeviceSparseProperties* sparseProperties{ nullptr };
};

struct Decoded_VkQueueFamilyProperties
{
    using struct_type = VkQueueFamilyProperties;

    VkQueueFamilyProperties* decoded_value{ nullptr };

    Decoded_VkExtent3D* minImageTransferGranularity{ nullptr };
};

struct Decoded_VkDeviceQueueCreateInfo
{
    using struct_type = VkDeviceQueueCreateInfo;

    VkDeviceQueueCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<float> pQueuePriorities;
};

struct Decoded_VkDeviceCreateInfo
{
    using struct_type = VkDeviceCreateInfo;

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

    VkExtensionProperties* decoded_value{ nullptr };

    StringDecoder extensionName;
};

struct Decoded_VkLayerProperties
{
    using struct_type = VkLayerProperties;

    VkLayerProperties* decoded_value{ nullptr };

    StringDecoder layerName;
    StringDecoder description;
};

struct Decoded_VkSubmitInfo
{
    using struct_type = VkSubmitInfo;

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

    VkMappedMemoryRange* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkMemoryAllocateInfo
{
    using struct_type = VkMemoryAllocateInfo;

    VkMemoryAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryRequirements
{
    using struct_type = VkMemoryRequirements;

    VkMemoryRequirements* decoded_value{ nullptr };
};

struct Decoded_VkSparseMemoryBind
{
    using struct_type = VkSparseMemoryBind;

    VkSparseMemoryBind* decoded_value{ nullptr };

    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkSparseBufferMemoryBindInfo
{
    using struct_type = VkSparseBufferMemoryBindInfo;

    VkSparseBufferMemoryBindInfo* decoded_value{ nullptr };

    format::HandleId buffer{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkSparseMemoryBind>* pBinds{ nullptr };
};

struct Decoded_VkSparseImageOpaqueMemoryBindInfo
{
    using struct_type = VkSparseImageOpaqueMemoryBindInfo;

    VkSparseImageOpaqueMemoryBindInfo* decoded_value{ nullptr };

    format::HandleId image{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkSparseMemoryBind>* pBinds{ nullptr };
};

struct Decoded_VkImageSubresource
{
    using struct_type = VkImageSubresource;

    VkImageSubresource* decoded_value{ nullptr };
};

struct Decoded_VkSparseImageMemoryBind
{
    using struct_type = VkSparseImageMemoryBind;

    VkSparseImageMemoryBind* decoded_value{ nullptr };

    Decoded_VkImageSubresource* subresource{ nullptr };
    Decoded_VkOffset3D* offset{ nullptr };
    Decoded_VkExtent3D* extent{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkSparseImageMemoryBindInfo
{
    using struct_type = VkSparseImageMemoryBindInfo;

    VkSparseImageMemoryBindInfo* decoded_value{ nullptr };

    format::HandleId image{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkSparseImageMemoryBind>* pBinds{ nullptr };
};

struct Decoded_VkBindSparseInfo
{
    using struct_type = VkBindSparseInfo;

    VkBindSparseInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkSemaphore> pWaitSemaphores;
    StructPointerDecoder<Decoded_VkSparseBufferMemoryBindInfo>* pBufferBinds{ nullptr };
    StructPointerDecoder<Decoded_VkSparseImageOpaqueMemoryBindInfo>* pImageOpaqueBinds{ nullptr };
    StructPointerDecoder<Decoded_VkSparseImageMemoryBindInfo>* pImageBinds{ nullptr };
    HandlePointerDecoder<VkSemaphore> pSignalSemaphores;
};

struct Decoded_VkSparseImageFormatProperties
{
    using struct_type = VkSparseImageFormatProperties;

    VkSparseImageFormatProperties* decoded_value{ nullptr };

    Decoded_VkExtent3D* imageGranularity{ nullptr };
};

struct Decoded_VkSparseImageMemoryRequirements
{
    using struct_type = VkSparseImageMemoryRequirements;

    VkSparseImageMemoryRequirements* decoded_value{ nullptr };

    Decoded_VkSparseImageFormatProperties* formatProperties{ nullptr };
};

struct Decoded_VkFenceCreateInfo
{
    using struct_type = VkFenceCreateInfo;

    VkFenceCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSemaphoreCreateInfo
{
    using struct_type = VkSemaphoreCreateInfo;

    VkSemaphoreCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkEventCreateInfo
{
    using struct_type = VkEventCreateInfo;

    VkEventCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueryPoolCreateInfo
{
    using struct_type = VkQueryPoolCreateInfo;

    VkQueryPoolCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferCreateInfo
{
    using struct_type = VkBufferCreateInfo;

    VkBufferCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkBufferViewCreateInfo
{
    using struct_type = VkBufferViewCreateInfo;

    VkBufferViewCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkImageCreateInfo
{
    using struct_type = VkImageCreateInfo;

    VkImageCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent3D* extent{ nullptr };
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkSubresourceLayout
{
    using struct_type = VkSubresourceLayout;

    VkSubresourceLayout* decoded_value{ nullptr };
};

struct Decoded_VkComponentMapping
{
    using struct_type = VkComponentMapping;

    VkComponentMapping* decoded_value{ nullptr };
};

struct Decoded_VkImageViewCreateInfo
{
    using struct_type = VkImageViewCreateInfo;

    VkImageViewCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    Decoded_VkComponentMapping* components{ nullptr };
    Decoded_VkImageSubresourceRange* subresourceRange{ nullptr };
};

struct Decoded_VkShaderModuleCreateInfo
{
    using struct_type = VkShaderModuleCreateInfo;

    VkShaderModuleCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pCode;
};

struct Decoded_VkPipelineCacheCreateInfo
{
    using struct_type = VkPipelineCacheCreateInfo;

    VkPipelineCacheCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pInitialData;
};

struct Decoded_VkSpecializationMapEntry
{
    using struct_type = VkSpecializationMapEntry;

    VkSpecializationMapEntry* decoded_value{ nullptr };
};

struct Decoded_VkSpecializationInfo
{
    using struct_type = VkSpecializationInfo;

    VkSpecializationInfo* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkSpecializationMapEntry>* pMapEntries{ nullptr };
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkPipelineShaderStageCreateInfo
{
    using struct_type = VkPipelineShaderStageCreateInfo;

    VkPipelineShaderStageCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId module{ format::kNullHandleId };
    StringDecoder pName;
    StructPointerDecoder<Decoded_VkSpecializationInfo>* pSpecializationInfo{ nullptr };
};

struct Decoded_VkComputePipelineCreateInfo
{
    using struct_type = VkComputePipelineCreateInfo;

    VkComputePipelineCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPipelineShaderStageCreateInfo* stage{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    format::HandleId basePipelineHandle{ format::kNullHandleId };
};

struct Decoded_VkVertexInputBindingDescription
{
    using struct_type = VkVertexInputBindingDescription;

    VkVertexInputBindingDescription* decoded_value{ nullptr };
};

struct Decoded_VkVertexInputAttributeDescription
{
    using struct_type = VkVertexInputAttributeDescription;

    VkVertexInputAttributeDescription* decoded_value{ nullptr };
};

struct Decoded_VkPipelineVertexInputStateCreateInfo
{
    using struct_type = VkPipelineVertexInputStateCreateInfo;

    VkPipelineVertexInputStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVertexInputBindingDescription>* pVertexBindingDescriptions{ nullptr };
    StructPointerDecoder<Decoded_VkVertexInputAttributeDescription>* pVertexAttributeDescriptions{ nullptr };
};

struct Decoded_VkPipelineInputAssemblyStateCreateInfo
{
    using struct_type = VkPipelineInputAssemblyStateCreateInfo;

    VkPipelineInputAssemblyStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineTessellationStateCreateInfo
{
    using struct_type = VkPipelineTessellationStateCreateInfo;

    VkPipelineTessellationStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkViewport
{
    using struct_type = VkViewport;

    VkViewport* decoded_value{ nullptr };
};

struct Decoded_VkPipelineViewportStateCreateInfo
{
    using struct_type = VkPipelineViewportStateCreateInfo;

    VkPipelineViewportStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkViewport>* pViewports{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pScissors{ nullptr };
};

struct Decoded_VkPipelineRasterizationStateCreateInfo
{
    using struct_type = VkPipelineRasterizationStateCreateInfo;

    VkPipelineRasterizationStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineMultisampleStateCreateInfo
{
    using struct_type = VkPipelineMultisampleStateCreateInfo;

    VkPipelineMultisampleStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkSampleMask> pSampleMask;
};

struct Decoded_VkStencilOpState
{
    using struct_type = VkStencilOpState;

    VkStencilOpState* decoded_value{ nullptr };
};

struct Decoded_VkPipelineDepthStencilStateCreateInfo
{
    using struct_type = VkPipelineDepthStencilStateCreateInfo;

    VkPipelineDepthStencilStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkStencilOpState* front{ nullptr };
    Decoded_VkStencilOpState* back{ nullptr };
};

struct Decoded_VkPipelineColorBlendAttachmentState
{
    using struct_type = VkPipelineColorBlendAttachmentState;

    VkPipelineColorBlendAttachmentState* decoded_value{ nullptr };
};

struct Decoded_VkPipelineColorBlendStateCreateInfo
{
    using struct_type = VkPipelineColorBlendStateCreateInfo;

    VkPipelineColorBlendStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineColorBlendAttachmentState>* pAttachments{ nullptr };
    PointerDecoder<float> blendConstants;
};

struct Decoded_VkPipelineDynamicStateCreateInfo
{
    using struct_type = VkPipelineDynamicStateCreateInfo;

    VkPipelineDynamicStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkDynamicState> pDynamicStates;
};

struct Decoded_VkGraphicsPipelineCreateInfo
{
    using struct_type = VkGraphicsPipelineCreateInfo;

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

struct Decoded_VkPushConstantRange
{
    using struct_type = VkPushConstantRange;

    VkPushConstantRange* decoded_value{ nullptr };
};

struct Decoded_VkPipelineLayoutCreateInfo
{
    using struct_type = VkPipelineLayoutCreateInfo;

    VkPipelineLayoutCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
    StructPointerDecoder<Decoded_VkPushConstantRange>* pPushConstantRanges{ nullptr };
};

struct Decoded_VkSamplerCreateInfo
{
    using struct_type = VkSamplerCreateInfo;

    VkSamplerCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCopyDescriptorSet
{
    using struct_type = VkCopyDescriptorSet;

    VkCopyDescriptorSet* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcSet{ format::kNullHandleId };
    format::HandleId dstSet{ format::kNullHandleId };
};

struct Decoded_VkDescriptorBufferInfo
{
    using struct_type = VkDescriptorBufferInfo;

    VkDescriptorBufferInfo* decoded_value{ nullptr };

    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkDescriptorPoolSize
{
    using struct_type = VkDescriptorPoolSize;

    VkDescriptorPoolSize* decoded_value{ nullptr };
};

struct Decoded_VkDescriptorPoolCreateInfo
{
    using struct_type = VkDescriptorPoolCreateInfo;

    VkDescriptorPoolCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDescriptorPoolSize>* pPoolSizes{ nullptr };
};

struct Decoded_VkDescriptorSetAllocateInfo
{
    using struct_type = VkDescriptorSetAllocateInfo;

    VkDescriptorSetAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId descriptorPool{ format::kNullHandleId };
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
};

struct Decoded_VkDescriptorSetLayoutBinding
{
    using struct_type = VkDescriptorSetLayoutBinding;

    VkDescriptorSetLayoutBinding* decoded_value{ nullptr };

    HandlePointerDecoder<VkSampler> pImmutableSamplers;
};

struct Decoded_VkDescriptorSetLayoutCreateInfo
{
    using struct_type = VkDescriptorSetLayoutCreateInfo;

    VkDescriptorSetLayoutCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDescriptorSetLayoutBinding>* pBindings{ nullptr };
};

struct Decoded_VkAttachmentDescription
{
    using struct_type = VkAttachmentDescription;

    VkAttachmentDescription* decoded_value{ nullptr };
};

struct Decoded_VkAttachmentReference
{
    using struct_type = VkAttachmentReference;

    VkAttachmentReference* decoded_value{ nullptr };
};

struct Decoded_VkFramebufferCreateInfo
{
    using struct_type = VkFramebufferCreateInfo;

    VkFramebufferCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId renderPass{ format::kNullHandleId };
    HandlePointerDecoder<VkImageView> pAttachments;
};

struct Decoded_VkSubpassDescription
{
    using struct_type = VkSubpassDescription;

    VkSubpassDescription* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkAttachmentReference>* pInputAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference>* pColorAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference>* pResolveAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference>* pDepthStencilAttachment{ nullptr };
    PointerDecoder<uint32_t> pPreserveAttachments;
};

struct Decoded_VkSubpassDependency
{
    using struct_type = VkSubpassDependency;

    VkSubpassDependency* decoded_value{ nullptr };
};

struct Decoded_VkRenderPassCreateInfo
{
    using struct_type = VkRenderPassCreateInfo;

    VkRenderPassCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentDescription>* pAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkSubpassDescription>* pSubpasses{ nullptr };
    StructPointerDecoder<Decoded_VkSubpassDependency>* pDependencies{ nullptr };
};

struct Decoded_VkCommandPoolCreateInfo
{
    using struct_type = VkCommandPoolCreateInfo;

    VkCommandPoolCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCommandBufferAllocateInfo
{
    using struct_type = VkCommandBufferAllocateInfo;

    VkCommandBufferAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId commandPool{ format::kNullHandleId };
};

struct Decoded_VkCommandBufferInheritanceInfo
{
    using struct_type = VkCommandBufferInheritanceInfo;

    VkCommandBufferInheritanceInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId renderPass{ format::kNullHandleId };
    format::HandleId framebuffer{ format::kNullHandleId };
};

struct Decoded_VkCommandBufferBeginInfo
{
    using struct_type = VkCommandBufferBeginInfo;

    VkCommandBufferBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkCommandBufferInheritanceInfo>* pInheritanceInfo{ nullptr };
};

struct Decoded_VkBufferCopy
{
    using struct_type = VkBufferCopy;

    VkBufferCopy* decoded_value{ nullptr };
};

struct Decoded_VkImageSubresourceLayers
{
    using struct_type = VkImageSubresourceLayers;

    VkImageSubresourceLayers* decoded_value{ nullptr };
};

struct Decoded_VkBufferImageCopy
{
    using struct_type = VkBufferImageCopy;

    VkBufferImageCopy* decoded_value{ nullptr };

    Decoded_VkImageSubresourceLayers* imageSubresource{ nullptr };
    Decoded_VkOffset3D* imageOffset{ nullptr };
    Decoded_VkExtent3D* imageExtent{ nullptr };
};

struct Decoded_VkClearDepthStencilValue
{
    using struct_type = VkClearDepthStencilValue;

    VkClearDepthStencilValue* decoded_value{ nullptr };
};

struct Decoded_VkClearAttachment
{
    using struct_type = VkClearAttachment;

    VkClearAttachment* decoded_value{ nullptr };

    Decoded_VkClearValue* clearValue{ nullptr };
};

struct Decoded_VkClearRect
{
    using struct_type = VkClearRect;

    VkClearRect* decoded_value{ nullptr };

    Decoded_VkRect2D* rect{ nullptr };
};

struct Decoded_VkImageBlit
{
    using struct_type = VkImageBlit;

    VkImageBlit* decoded_value{ nullptr };

    Decoded_VkImageSubresourceLayers* srcSubresource{ nullptr };
    StructPointerDecoder<Decoded_VkOffset3D>* srcOffsets{ nullptr };
    Decoded_VkImageSubresourceLayers* dstSubresource{ nullptr };
    StructPointerDecoder<Decoded_VkOffset3D>* dstOffsets{ nullptr };
};

struct Decoded_VkImageCopy
{
    using struct_type = VkImageCopy;

    VkImageCopy* decoded_value{ nullptr };

    Decoded_VkImageSubresourceLayers* srcSubresource{ nullptr };
    Decoded_VkOffset3D* srcOffset{ nullptr };
    Decoded_VkImageSubresourceLayers* dstSubresource{ nullptr };
    Decoded_VkOffset3D* dstOffset{ nullptr };
    Decoded_VkExtent3D* extent{ nullptr };
};

struct Decoded_VkImageResolve
{
    using struct_type = VkImageResolve;

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

    VkRenderPassBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId renderPass{ format::kNullHandleId };
    format::HandleId framebuffer{ format::kNullHandleId };
    Decoded_VkRect2D* renderArea{ nullptr };
    StructPointerDecoder<Decoded_VkClearValue>* pClearValues{ nullptr };
};

struct Decoded_VkPhysicalDeviceSubgroupProperties
{
    using struct_type = VkPhysicalDeviceSubgroupProperties;

    VkPhysicalDeviceSubgroupProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBindBufferMemoryInfo
{
    using struct_type = VkBindBufferMemoryInfo;

    VkBindBufferMemoryInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkBindImageMemoryInfo
{
    using struct_type = VkBindImageMemoryInfo;

    VkBindImageMemoryInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDevice16BitStorageFeatures
{
    using struct_type = VkPhysicalDevice16BitStorageFeatures;

    VkPhysicalDevice16BitStorageFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryDedicatedRequirements
{
    using struct_type = VkMemoryDedicatedRequirements;

    VkMemoryDedicatedRequirements* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryDedicatedAllocateInfo
{
    using struct_type = VkMemoryDedicatedAllocateInfo;

    VkMemoryDedicatedAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkMemoryAllocateFlagsInfo
{
    using struct_type = VkMemoryAllocateFlagsInfo;

    VkMemoryAllocateFlagsInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceGroupRenderPassBeginInfo
{
    using struct_type = VkDeviceGroupRenderPassBeginInfo;

    VkDeviceGroupRenderPassBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pDeviceRenderAreas{ nullptr };
};

struct Decoded_VkDeviceGroupCommandBufferBeginInfo
{
    using struct_type = VkDeviceGroupCommandBufferBeginInfo;

    VkDeviceGroupCommandBufferBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceGroupSubmitInfo
{
    using struct_type = VkDeviceGroupSubmitInfo;

    VkDeviceGroupSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pWaitSemaphoreDeviceIndices;
    PointerDecoder<uint32_t> pCommandBufferDeviceMasks;
    PointerDecoder<uint32_t> pSignalSemaphoreDeviceIndices;
};

struct Decoded_VkDeviceGroupBindSparseInfo
{
    using struct_type = VkDeviceGroupBindSparseInfo;

    VkDeviceGroupBindSparseInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBindBufferMemoryDeviceGroupInfo
{
    using struct_type = VkBindBufferMemoryDeviceGroupInfo;

    VkBindBufferMemoryDeviceGroupInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pDeviceIndices;
};

struct Decoded_VkBindImageMemoryDeviceGroupInfo
{
    using struct_type = VkBindImageMemoryDeviceGroupInfo;

    VkBindImageMemoryDeviceGroupInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pDeviceIndices;
    StructPointerDecoder<Decoded_VkRect2D>* pSplitInstanceBindRegions{ nullptr };
};

struct Decoded_VkPhysicalDeviceGroupProperties
{
    using struct_type = VkPhysicalDeviceGroupProperties;

    VkPhysicalDeviceGroupProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkPhysicalDevice> physicalDevices;
};

struct Decoded_VkDeviceGroupDeviceCreateInfo
{
    using struct_type = VkDeviceGroupDeviceCreateInfo;

    VkDeviceGroupDeviceCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkPhysicalDevice> pPhysicalDevices;
};

struct Decoded_VkBufferMemoryRequirementsInfo2
{
    using struct_type = VkBufferMemoryRequirementsInfo2;

    VkBufferMemoryRequirementsInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkImageMemoryRequirementsInfo2
{
    using struct_type = VkImageMemoryRequirementsInfo2;

    VkImageMemoryRequirementsInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
};

struct Decoded_VkImageSparseMemoryRequirementsInfo2
{
    using struct_type = VkImageSparseMemoryRequirementsInfo2;

    VkImageSparseMemoryRequirementsInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
};

struct Decoded_VkMemoryRequirements2
{
    using struct_type = VkMemoryRequirements2;

    VkMemoryRequirements2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkMemoryRequirements* memoryRequirements{ nullptr };
};

struct Decoded_VkSparseImageMemoryRequirements2
{
    using struct_type = VkSparseImageMemoryRequirements2;

    VkSparseImageMemoryRequirements2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSparseImageMemoryRequirements* memoryRequirements{ nullptr };
};

struct Decoded_VkPhysicalDeviceFeatures2
{
    using struct_type = VkPhysicalDeviceFeatures2;

    VkPhysicalDeviceFeatures2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPhysicalDeviceFeatures* features{ nullptr };
};

struct Decoded_VkPhysicalDeviceProperties2
{
    using struct_type = VkPhysicalDeviceProperties2;

    VkPhysicalDeviceProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPhysicalDeviceProperties* properties{ nullptr };
};

struct Decoded_VkFormatProperties2
{
    using struct_type = VkFormatProperties2;

    VkFormatProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkFormatProperties* formatProperties{ nullptr };
};

struct Decoded_VkImageFormatProperties2
{
    using struct_type = VkImageFormatProperties2;

    VkImageFormatProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkImageFormatProperties* imageFormatProperties{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageFormatInfo2
{
    using struct_type = VkPhysicalDeviceImageFormatInfo2;

    VkPhysicalDeviceImageFormatInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyProperties2
{
    using struct_type = VkQueueFamilyProperties2;

    VkQueueFamilyProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkQueueFamilyProperties* queueFamilyProperties{ nullptr };
};

struct Decoded_VkPhysicalDeviceMemoryProperties2
{
    using struct_type = VkPhysicalDeviceMemoryProperties2;

    VkPhysicalDeviceMemoryProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkPhysicalDeviceMemoryProperties* memoryProperties{ nullptr };
};

struct Decoded_VkSparseImageFormatProperties2
{
    using struct_type = VkSparseImageFormatProperties2;

    VkSparseImageFormatProperties2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSparseImageFormatProperties* properties{ nullptr };
};

struct Decoded_VkPhysicalDeviceSparseImageFormatInfo2
{
    using struct_type = VkPhysicalDeviceSparseImageFormatInfo2;

    VkPhysicalDeviceSparseImageFormatInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePointClippingProperties
{
    using struct_type = VkPhysicalDevicePointClippingProperties;

    VkPhysicalDevicePointClippingProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkInputAttachmentAspectReference
{
    using struct_type = VkInputAttachmentAspectReference;

    VkInputAttachmentAspectReference* decoded_value{ nullptr };
};

struct Decoded_VkRenderPassInputAttachmentAspectCreateInfo
{
    using struct_type = VkRenderPassInputAttachmentAspectCreateInfo;

    VkRenderPassInputAttachmentAspectCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkInputAttachmentAspectReference>* pAspectReferences{ nullptr };
};

struct Decoded_VkImageViewUsageCreateInfo
{
    using struct_type = VkImageViewUsageCreateInfo;

    VkImageViewUsageCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineTessellationDomainOriginStateCreateInfo
{
    using struct_type = VkPipelineTessellationDomainOriginStateCreateInfo;

    VkPipelineTessellationDomainOriginStateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderPassMultiviewCreateInfo
{
    using struct_type = VkRenderPassMultiviewCreateInfo;

    VkRenderPassMultiviewCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pViewMasks;
    PointerDecoder<int32_t> pViewOffsets;
    PointerDecoder<uint32_t> pCorrelationMasks;
};

struct Decoded_VkPhysicalDeviceMultiviewFeatures
{
    using struct_type = VkPhysicalDeviceMultiviewFeatures;

    VkPhysicalDeviceMultiviewFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiviewProperties
{
    using struct_type = VkPhysicalDeviceMultiviewProperties;

    VkPhysicalDeviceMultiviewProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVariablePointersFeatures
{
    using struct_type = VkPhysicalDeviceVariablePointersFeatures;

    VkPhysicalDeviceVariablePointersFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceProtectedMemoryFeatures
{
    using struct_type = VkPhysicalDeviceProtectedMemoryFeatures;

    VkPhysicalDeviceProtectedMemoryFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceProtectedMemoryProperties
{
    using struct_type = VkPhysicalDeviceProtectedMemoryProperties;

    VkPhysicalDeviceProtectedMemoryProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceQueueInfo2
{
    using struct_type = VkDeviceQueueInfo2;

    VkDeviceQueueInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkProtectedSubmitInfo
{
    using struct_type = VkProtectedSubmitInfo;

    VkProtectedSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerYcbcrConversionCreateInfo
{
    using struct_type = VkSamplerYcbcrConversionCreateInfo;

    VkSamplerYcbcrConversionCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkComponentMapping* components{ nullptr };
};

struct Decoded_VkSamplerYcbcrConversionInfo
{
    using struct_type = VkSamplerYcbcrConversionInfo;

    VkSamplerYcbcrConversionInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId conversion{ format::kNullHandleId };
};

struct Decoded_VkBindImagePlaneMemoryInfo
{
    using struct_type = VkBindImagePlaneMemoryInfo;

    VkBindImagePlaneMemoryInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImagePlaneMemoryRequirementsInfo
{
    using struct_type = VkImagePlaneMemoryRequirementsInfo;

    VkImagePlaneMemoryRequirementsInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures
{
    using struct_type = VkPhysicalDeviceSamplerYcbcrConversionFeatures;

    VkPhysicalDeviceSamplerYcbcrConversionFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerYcbcrConversionImageFormatProperties
{
    using struct_type = VkSamplerYcbcrConversionImageFormatProperties;

    VkSamplerYcbcrConversionImageFormatProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorUpdateTemplateEntry
{
    using struct_type = VkDescriptorUpdateTemplateEntry;

    VkDescriptorUpdateTemplateEntry* decoded_value{ nullptr };
};

struct Decoded_VkDescriptorUpdateTemplateCreateInfo
{
    using struct_type = VkDescriptorUpdateTemplateCreateInfo;

    VkDescriptorUpdateTemplateCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDescriptorUpdateTemplateEntry>* pDescriptorUpdateEntries{ nullptr };
    format::HandleId descriptorSetLayout{ format::kNullHandleId };
    format::HandleId pipelineLayout{ format::kNullHandleId };
};

struct Decoded_VkExternalMemoryProperties
{
    using struct_type = VkExternalMemoryProperties;

    VkExternalMemoryProperties* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalImageFormatInfo
{
    using struct_type = VkPhysicalDeviceExternalImageFormatInfo;

    VkPhysicalDeviceExternalImageFormatInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalImageFormatProperties
{
    using struct_type = VkExternalImageFormatProperties;

    VkExternalImageFormatProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExternalMemoryProperties* externalMemoryProperties{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalBufferInfo
{
    using struct_type = VkPhysicalDeviceExternalBufferInfo;

    VkPhysicalDeviceExternalBufferInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalBufferProperties
{
    using struct_type = VkExternalBufferProperties;

    VkExternalBufferProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExternalMemoryProperties* externalMemoryProperties{ nullptr };
};

struct Decoded_VkPhysicalDeviceIDProperties
{
    using struct_type = VkPhysicalDeviceIDProperties;

    VkPhysicalDeviceIDProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> deviceUUID;
    PointerDecoder<uint8_t> driverUUID;
    PointerDecoder<uint8_t> deviceLUID;
};

struct Decoded_VkExternalMemoryImageCreateInfo
{
    using struct_type = VkExternalMemoryImageCreateInfo;

    VkExternalMemoryImageCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalMemoryBufferCreateInfo
{
    using struct_type = VkExternalMemoryBufferCreateInfo;

    VkExternalMemoryBufferCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExportMemoryAllocateInfo
{
    using struct_type = VkExportMemoryAllocateInfo;

    VkExportMemoryAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalFenceInfo
{
    using struct_type = VkPhysicalDeviceExternalFenceInfo;

    VkPhysicalDeviceExternalFenceInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalFenceProperties
{
    using struct_type = VkExternalFenceProperties;

    VkExternalFenceProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExportFenceCreateInfo
{
    using struct_type = VkExportFenceCreateInfo;

    VkExportFenceCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExportSemaphoreCreateInfo
{
    using struct_type = VkExportSemaphoreCreateInfo;

    VkExportSemaphoreCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalSemaphoreInfo
{
    using struct_type = VkPhysicalDeviceExternalSemaphoreInfo;

    VkPhysicalDeviceExternalSemaphoreInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalSemaphoreProperties
{
    using struct_type = VkExternalSemaphoreProperties;

    VkExternalSemaphoreProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance3Properties
{
    using struct_type = VkPhysicalDeviceMaintenance3Properties;

    VkPhysicalDeviceMaintenance3Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorSetLayoutSupport
{
    using struct_type = VkDescriptorSetLayoutSupport;

    VkDescriptorSetLayoutSupport* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderDrawParametersFeatures
{
    using struct_type = VkPhysicalDeviceShaderDrawParametersFeatures;

    VkPhysicalDeviceShaderDrawParametersFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceVariablePointersFeatures Decoded_VkPhysicalDeviceVariablePointerFeatures;

typedef Decoded_VkPhysicalDeviceShaderDrawParametersFeatures Decoded_VkPhysicalDeviceShaderDrawParameterFeatures;

struct Decoded_VkPhysicalDeviceVulkan11Features
{
    using struct_type = VkPhysicalDeviceVulkan11Features;

    VkPhysicalDeviceVulkan11Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkan11Properties
{
    using struct_type = VkPhysicalDeviceVulkan11Properties;

    VkPhysicalDeviceVulkan11Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> deviceUUID;
    PointerDecoder<uint8_t> driverUUID;
    PointerDecoder<uint8_t> deviceLUID;
};

struct Decoded_VkPhysicalDeviceVulkan12Features
{
    using struct_type = VkPhysicalDeviceVulkan12Features;

    VkPhysicalDeviceVulkan12Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkConformanceVersion
{
    using struct_type = VkConformanceVersion;

    VkConformanceVersion* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkan12Properties
{
    using struct_type = VkPhysicalDeviceVulkan12Properties;

    VkPhysicalDeviceVulkan12Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder driverName;
    StringDecoder driverInfo;
    Decoded_VkConformanceVersion* conformanceVersion{ nullptr };
};

struct Decoded_VkImageFormatListCreateInfo
{
    using struct_type = VkImageFormatListCreateInfo;

    VkImageFormatListCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pViewFormats;
};

struct Decoded_VkAttachmentDescription2
{
    using struct_type = VkAttachmentDescription2;

    VkAttachmentDescription2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAttachmentReference2
{
    using struct_type = VkAttachmentReference2;

    VkAttachmentReference2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSubpassDescription2
{
    using struct_type = VkSubpassDescription2;

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

    VkSubpassDependency2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderPassCreateInfo2
{
    using struct_type = VkRenderPassCreateInfo2;

    VkRenderPassCreateInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentDescription2>* pAttachments{ nullptr };
    StructPointerDecoder<Decoded_VkSubpassDescription2>* pSubpasses{ nullptr };
    StructPointerDecoder<Decoded_VkSubpassDependency2>* pDependencies{ nullptr };
    PointerDecoder<uint32_t> pCorrelatedViewMasks;
};

struct Decoded_VkSubpassBeginInfo
{
    using struct_type = VkSubpassBeginInfo;

    VkSubpassBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSubpassEndInfo
{
    using struct_type = VkSubpassEndInfo;

    VkSubpassEndInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevice8BitStorageFeatures
{
    using struct_type = VkPhysicalDevice8BitStorageFeatures;

    VkPhysicalDevice8BitStorageFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDriverProperties
{
    using struct_type = VkPhysicalDeviceDriverProperties;

    VkPhysicalDeviceDriverProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder driverName;
    StringDecoder driverInfo;
    Decoded_VkConformanceVersion* conformanceVersion{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderAtomicInt64Features
{
    using struct_type = VkPhysicalDeviceShaderAtomicInt64Features;

    VkPhysicalDeviceShaderAtomicInt64Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderFloat16Int8Features
{
    using struct_type = VkPhysicalDeviceShaderFloat16Int8Features;

    VkPhysicalDeviceShaderFloat16Int8Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFloatControlsProperties
{
    using struct_type = VkPhysicalDeviceFloatControlsProperties;

    VkPhysicalDeviceFloatControlsProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo
{
    using struct_type = VkDescriptorSetLayoutBindingFlagsCreateInfo;

    VkDescriptorSetLayoutBindingFlagsCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkDescriptorBindingFlags> pBindingFlags;
};

struct Decoded_VkPhysicalDeviceDescriptorIndexingFeatures
{
    using struct_type = VkPhysicalDeviceDescriptorIndexingFeatures;

    VkPhysicalDeviceDescriptorIndexingFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDescriptorIndexingProperties
{
    using struct_type = VkPhysicalDeviceDescriptorIndexingProperties;

    VkPhysicalDeviceDescriptorIndexingProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo
{
    using struct_type = VkDescriptorSetVariableDescriptorCountAllocateInfo;

    VkDescriptorSetVariableDescriptorCountAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pDescriptorCounts;
};

struct Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport
{
    using struct_type = VkDescriptorSetVariableDescriptorCountLayoutSupport;

    VkDescriptorSetVariableDescriptorCountLayoutSupport* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSubpassDescriptionDepthStencilResolve
{
    using struct_type = VkSubpassDescriptionDepthStencilResolve;

    VkSubpassDescriptionDepthStencilResolve* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference2>* pDepthStencilResolveAttachment{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthStencilResolveProperties
{
    using struct_type = VkPhysicalDeviceDepthStencilResolveProperties;

    VkPhysicalDeviceDepthStencilResolveProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures
{
    using struct_type = VkPhysicalDeviceScalarBlockLayoutFeatures;

    VkPhysicalDeviceScalarBlockLayoutFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageStencilUsageCreateInfo
{
    using struct_type = VkImageStencilUsageCreateInfo;

    VkImageStencilUsageCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerReductionModeCreateInfo
{
    using struct_type = VkSamplerReductionModeCreateInfo;

    VkSamplerReductionModeCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties
{
    using struct_type = VkPhysicalDeviceSamplerFilterMinmaxProperties;

    VkPhysicalDeviceSamplerFilterMinmaxProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures
{
    using struct_type = VkPhysicalDeviceVulkanMemoryModelFeatures;

    VkPhysicalDeviceVulkanMemoryModelFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImagelessFramebufferFeatures
{
    using struct_type = VkPhysicalDeviceImagelessFramebufferFeatures;

    VkPhysicalDeviceImagelessFramebufferFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFramebufferAttachmentImageInfo
{
    using struct_type = VkFramebufferAttachmentImageInfo;

    VkFramebufferAttachmentImageInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pViewFormats;
};

struct Decoded_VkFramebufferAttachmentsCreateInfo
{
    using struct_type = VkFramebufferAttachmentsCreateInfo;

    VkFramebufferAttachmentsCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkFramebufferAttachmentImageInfo>* pAttachmentImageInfos{ nullptr };
};

struct Decoded_VkRenderPassAttachmentBeginInfo
{
    using struct_type = VkRenderPassAttachmentBeginInfo;

    VkRenderPassAttachmentBeginInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkImageView> pAttachments;
};

struct Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures
{
    using struct_type = VkPhysicalDeviceUniformBufferStandardLayoutFeatures;

    VkPhysicalDeviceUniformBufferStandardLayoutFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures
{
    using struct_type = VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures;

    VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures
{
    using struct_type = VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures;

    VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAttachmentReferenceStencilLayout
{
    using struct_type = VkAttachmentReferenceStencilLayout;

    VkAttachmentReferenceStencilLayout* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAttachmentDescriptionStencilLayout
{
    using struct_type = VkAttachmentDescriptionStencilLayout;

    VkAttachmentDescriptionStencilLayout* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceHostQueryResetFeatures
{
    using struct_type = VkPhysicalDeviceHostQueryResetFeatures;

    VkPhysicalDeviceHostQueryResetFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures
{
    using struct_type = VkPhysicalDeviceTimelineSemaphoreFeatures;

    VkPhysicalDeviceTimelineSemaphoreFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTimelineSemaphoreProperties
{
    using struct_type = VkPhysicalDeviceTimelineSemaphoreProperties;

    VkPhysicalDeviceTimelineSemaphoreProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSemaphoreTypeCreateInfo
{
    using struct_type = VkSemaphoreTypeCreateInfo;

    VkSemaphoreTypeCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTimelineSemaphoreSubmitInfo
{
    using struct_type = VkTimelineSemaphoreSubmitInfo;

    VkTimelineSemaphoreSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint64_t> pWaitSemaphoreValues;
    PointerDecoder<uint64_t> pSignalSemaphoreValues;
};

struct Decoded_VkSemaphoreWaitInfo
{
    using struct_type = VkSemaphoreWaitInfo;

    VkSemaphoreWaitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkSemaphore> pSemaphores;
    PointerDecoder<uint64_t> pValues;
};

struct Decoded_VkSemaphoreSignalInfo
{
    using struct_type = VkSemaphoreSignalInfo;

    VkSemaphoreSignalInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures
{
    using struct_type = VkPhysicalDeviceBufferDeviceAddressFeatures;

    VkPhysicalDeviceBufferDeviceAddressFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferDeviceAddressInfo
{
    using struct_type = VkBufferDeviceAddressInfo;

    VkBufferDeviceAddressInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkBufferOpaqueCaptureAddressCreateInfo
{
    using struct_type = VkBufferOpaqueCaptureAddressCreateInfo;

    VkBufferOpaqueCaptureAddressCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo
{
    using struct_type = VkMemoryOpaqueCaptureAddressAllocateInfo;

    VkMemoryOpaqueCaptureAddressAllocateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo
{
    using struct_type = VkDeviceMemoryOpaqueCaptureAddressInfo;

    VkDeviceMemoryOpaqueCaptureAddressInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceVulkan13Features
{
    using struct_type = VkPhysicalDeviceVulkan13Features;

    VkPhysicalDeviceVulkan13Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVulkan13Properties
{
    using struct_type = VkPhysicalDeviceVulkan13Properties;

    VkPhysicalDeviceVulkan13Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCreationFeedback
{
    using struct_type = VkPipelineCreationFeedback;

    VkPipelineCreationFeedback* decoded_value{ nullptr };
};

struct Decoded_VkPipelineCreationFeedbackCreateInfo
{
    using struct_type = VkPipelineCreationFeedbackCreateInfo;

    VkPipelineCreationFeedbackCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineCreationFeedback>* pPipelineCreationFeedback{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineCreationFeedback>* pPipelineStageCreationFeedbacks{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures
{
    using struct_type = VkPhysicalDeviceShaderTerminateInvocationFeatures;

    VkPhysicalDeviceShaderTerminateInvocationFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceToolProperties
{
    using struct_type = VkPhysicalDeviceToolProperties;

    VkPhysicalDeviceToolProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
    StringDecoder version;
    StringDecoder description;
    StringDecoder layer;
};

struct Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures
{
    using struct_type = VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures;

    VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePrivateDataFeatures
{
    using struct_type = VkPhysicalDevicePrivateDataFeatures;

    VkPhysicalDevicePrivateDataFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDevicePrivateDataCreateInfo
{
    using struct_type = VkDevicePrivateDataCreateInfo;

    VkDevicePrivateDataCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPrivateDataSlotCreateInfo
{
    using struct_type = VkPrivateDataSlotCreateInfo;

    VkPrivateDataSlotCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures
{
    using struct_type = VkPhysicalDevicePipelineCreationCacheControlFeatures;

    VkPhysicalDevicePipelineCreationCacheControlFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryBarrier2
{
    using struct_type = VkMemoryBarrier2;

    VkMemoryBarrier2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferMemoryBarrier2
{
    using struct_type = VkBufferMemoryBarrier2;

    VkBufferMemoryBarrier2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkImageMemoryBarrier2
{
    using struct_type = VkImageMemoryBarrier2;

    VkImageMemoryBarrier2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    Decoded_VkImageSubresourceRange* subresourceRange{ nullptr };
};

struct Decoded_VkDependencyInfo
{
    using struct_type = VkDependencyInfo;

    VkDependencyInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkMemoryBarrier2>* pMemoryBarriers{ nullptr };
    StructPointerDecoder<Decoded_VkBufferMemoryBarrier2>* pBufferMemoryBarriers{ nullptr };
    StructPointerDecoder<Decoded_VkImageMemoryBarrier2>* pImageMemoryBarriers{ nullptr };
};

struct Decoded_VkSemaphoreSubmitInfo
{
    using struct_type = VkSemaphoreSubmitInfo;

    VkSemaphoreSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkCommandBufferSubmitInfo
{
    using struct_type = VkCommandBufferSubmitInfo;

    VkCommandBufferSubmitInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId commandBuffer{ format::kNullHandleId };
};

struct Decoded_VkSubmitInfo2
{
    using struct_type = VkSubmitInfo2;

    VkSubmitInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* pWaitSemaphoreInfos{ nullptr };
    StructPointerDecoder<Decoded_VkCommandBufferSubmitInfo>* pCommandBufferInfos{ nullptr };
    StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* pSignalSemaphoreInfos{ nullptr };
};

struct Decoded_VkPhysicalDeviceSynchronization2Features
{
    using struct_type = VkPhysicalDeviceSynchronization2Features;

    VkPhysicalDeviceSynchronization2Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures
{
    using struct_type = VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures;

    VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageRobustnessFeatures
{
    using struct_type = VkPhysicalDeviceImageRobustnessFeatures;

    VkPhysicalDeviceImageRobustnessFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferCopy2
{
    using struct_type = VkBufferCopy2;

    VkBufferCopy2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCopyBufferInfo2
{
    using struct_type = VkCopyBufferInfo2;

    VkCopyBufferInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcBuffer{ format::kNullHandleId };
    format::HandleId dstBuffer{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkBufferCopy2>* pRegions{ nullptr };
};

struct Decoded_VkImageCopy2
{
    using struct_type = VkImageCopy2;

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

    VkCopyImageInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageCopy2>* pRegions{ nullptr };
};

struct Decoded_VkBufferImageCopy2
{
    using struct_type = VkBufferImageCopy2;

    VkBufferImageCopy2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkImageSubresourceLayers* imageSubresource{ nullptr };
    Decoded_VkOffset3D* imageOffset{ nullptr };
    Decoded_VkExtent3D* imageExtent{ nullptr };
};

struct Decoded_VkCopyBufferToImageInfo2
{
    using struct_type = VkCopyBufferToImageInfo2;

    VkCopyBufferToImageInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcBuffer{ format::kNullHandleId };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkBufferImageCopy2>* pRegions{ nullptr };
};

struct Decoded_VkCopyImageToBufferInfo2
{
    using struct_type = VkCopyImageToBufferInfo2;

    VkCopyImageToBufferInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    format::HandleId dstBuffer{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkBufferImageCopy2>* pRegions{ nullptr };
};

struct Decoded_VkImageBlit2
{
    using struct_type = VkImageBlit2;

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

    VkBlitImageInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageBlit2>* pRegions{ nullptr };
};

struct Decoded_VkImageResolve2
{
    using struct_type = VkImageResolve2;

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

    VkResolveImageInfo2* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageResolve2>* pRegions{ nullptr };
};

struct Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures
{
    using struct_type = VkPhysicalDeviceSubgroupSizeControlFeatures;

    VkPhysicalDeviceSubgroupSizeControlFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSubgroupSizeControlProperties
{
    using struct_type = VkPhysicalDeviceSubgroupSizeControlProperties;

    VkPhysicalDeviceSubgroupSizeControlProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo
{
    using struct_type = VkPipelineShaderStageRequiredSubgroupSizeCreateInfo;

    VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceInlineUniformBlockFeatures
{
    using struct_type = VkPhysicalDeviceInlineUniformBlockFeatures;

    VkPhysicalDeviceInlineUniformBlockFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceInlineUniformBlockProperties
{
    using struct_type = VkPhysicalDeviceInlineUniformBlockProperties;

    VkPhysicalDeviceInlineUniformBlockProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkWriteDescriptorSetInlineUniformBlock
{
    using struct_type = VkWriteDescriptorSetInlineUniformBlock;

    VkWriteDescriptorSetInlineUniformBlock* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo
{
    using struct_type = VkDescriptorPoolInlineUniformBlockCreateInfo;

    VkDescriptorPoolInlineUniformBlockCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures
{
    using struct_type = VkPhysicalDeviceTextureCompressionASTCHDRFeatures;

    VkPhysicalDeviceTextureCompressionASTCHDRFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderingAttachmentInfo
{
    using struct_type = VkRenderingAttachmentInfo;

    VkRenderingAttachmentInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId imageView{ format::kNullHandleId };
    format::HandleId resolveImageView{ format::kNullHandleId };
    Decoded_VkClearValue* clearValue{ nullptr };
};

struct Decoded_VkRenderingInfo
{
    using struct_type = VkRenderingInfo;

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

    VkPipelineRenderingCreateInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pColorAttachmentFormats;
};

struct Decoded_VkPhysicalDeviceDynamicRenderingFeatures
{
    using struct_type = VkPhysicalDeviceDynamicRenderingFeatures;

    VkPhysicalDeviceDynamicRenderingFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCommandBufferInheritanceRenderingInfo
{
    using struct_type = VkCommandBufferInheritanceRenderingInfo;

    VkCommandBufferInheritanceRenderingInfo* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pColorAttachmentFormats;
};

struct Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures
{
    using struct_type = VkPhysicalDeviceShaderIntegerDotProductFeatures;

    VkPhysicalDeviceShaderIntegerDotProductFeatures* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties
{
    using struct_type = VkPhysicalDeviceShaderIntegerDotProductProperties;

    VkPhysicalDeviceShaderIntegerDotProductProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties
{
    using struct_type = VkPhysicalDeviceTexelBufferAlignmentProperties;

    VkPhysicalDeviceTexelBufferAlignmentProperties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFormatProperties3
{
    using struct_type = VkFormatProperties3;

    VkFormatProperties3* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance4Features
{
    using struct_type = VkPhysicalDeviceMaintenance4Features;

    VkPhysicalDeviceMaintenance4Features* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance4Properties
{
    using struct_type = VkPhysicalDeviceMaintenance4Properties;

    VkPhysicalDeviceMaintenance4Properties* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceBufferMemoryRequirements
{
    using struct_type = VkDeviceBufferMemoryRequirements;

    VkDeviceBufferMemoryRequirements* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkBufferCreateInfo>* pCreateInfo{ nullptr };
};

struct Decoded_VkDeviceImageMemoryRequirements
{
    using struct_type = VkDeviceImageMemoryRequirements;

    VkDeviceImageMemoryRequirements* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo{ nullptr };
};

struct Decoded_VkSurfaceCapabilitiesKHR
{
    using struct_type = VkSurfaceCapabilitiesKHR;

    VkSurfaceCapabilitiesKHR* decoded_value{ nullptr };

    Decoded_VkExtent2D* currentExtent{ nullptr };
    Decoded_VkExtent2D* minImageExtent{ nullptr };
    Decoded_VkExtent2D* maxImageExtent{ nullptr };
};

struct Decoded_VkSurfaceFormatKHR
{
    using struct_type = VkSurfaceFormatKHR;

    VkSurfaceFormatKHR* decoded_value{ nullptr };
};

struct Decoded_VkSwapchainCreateInfoKHR
{
    using struct_type = VkSwapchainCreateInfoKHR;

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

    VkImageSwapchainCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId swapchain{ format::kNullHandleId };
};

struct Decoded_VkBindImageMemorySwapchainInfoKHR
{
    using struct_type = VkBindImageMemorySwapchainInfoKHR;

    VkBindImageMemorySwapchainInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId swapchain{ format::kNullHandleId };
};

struct Decoded_VkAcquireNextImageInfoKHR
{
    using struct_type = VkAcquireNextImageInfoKHR;

    VkAcquireNextImageInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId swapchain{ format::kNullHandleId };
    format::HandleId semaphore{ format::kNullHandleId };
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkDeviceGroupPresentCapabilitiesKHR
{
    using struct_type = VkDeviceGroupPresentCapabilitiesKHR;

    VkDeviceGroupPresentCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> presentMask;
};

struct Decoded_VkDeviceGroupPresentInfoKHR
{
    using struct_type = VkDeviceGroupPresentInfoKHR;

    VkDeviceGroupPresentInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pDeviceMasks;
};

struct Decoded_VkDeviceGroupSwapchainCreateInfoKHR
{
    using struct_type = VkDeviceGroupSwapchainCreateInfoKHR;

    VkDeviceGroupSwapchainCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDisplayModeParametersKHR
{
    using struct_type = VkDisplayModeParametersKHR;

    VkDisplayModeParametersKHR* decoded_value{ nullptr };

    Decoded_VkExtent2D* visibleRegion{ nullptr };
};

struct Decoded_VkDisplayModeCreateInfoKHR
{
    using struct_type = VkDisplayModeCreateInfoKHR;

    VkDisplayModeCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDisplayModeParametersKHR* parameters{ nullptr };
};

struct Decoded_VkDisplayModePropertiesKHR
{
    using struct_type = VkDisplayModePropertiesKHR;

    VkDisplayModePropertiesKHR* decoded_value{ nullptr };

    format::HandleId displayMode{ format::kNullHandleId };
    Decoded_VkDisplayModeParametersKHR* parameters{ nullptr };
};

struct Decoded_VkDisplayPlaneCapabilitiesKHR
{
    using struct_type = VkDisplayPlaneCapabilitiesKHR;

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

    VkDisplayPlanePropertiesKHR* decoded_value{ nullptr };

    format::HandleId currentDisplay{ format::kNullHandleId };
};

struct Decoded_VkDisplayPropertiesKHR
{
    using struct_type = VkDisplayPropertiesKHR;

    VkDisplayPropertiesKHR* decoded_value{ nullptr };

    format::HandleId display{ format::kNullHandleId };
    StringDecoder displayName;
    Decoded_VkExtent2D* physicalDimensions{ nullptr };
    Decoded_VkExtent2D* physicalResolution{ nullptr };
};

struct Decoded_VkDisplaySurfaceCreateInfoKHR
{
    using struct_type = VkDisplaySurfaceCreateInfoKHR;

    VkDisplaySurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId displayMode{ format::kNullHandleId };
    Decoded_VkExtent2D* imageExtent{ nullptr };
};

struct Decoded_VkDisplayPresentInfoKHR
{
    using struct_type = VkDisplayPresentInfoKHR;

    VkDisplayPresentInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkRect2D* srcRect{ nullptr };
    Decoded_VkRect2D* dstRect{ nullptr };
};

struct Decoded_VkXlibSurfaceCreateInfoKHR
{
    using struct_type = VkXlibSurfaceCreateInfoKHR;

    VkXlibSurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t dpy{ 0 };
};

struct Decoded_VkXcbSurfaceCreateInfoKHR
{
    using struct_type = VkXcbSurfaceCreateInfoKHR;

    VkXcbSurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t connection{ 0 };
};

struct Decoded_VkWaylandSurfaceCreateInfoKHR
{
    using struct_type = VkWaylandSurfaceCreateInfoKHR;

    VkWaylandSurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t display{ 0 };
    uint64_t surface{ 0 };
};

struct Decoded_VkAndroidSurfaceCreateInfoKHR
{
    using struct_type = VkAndroidSurfaceCreateInfoKHR;

    VkAndroidSurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t window{ 0 };
};

struct Decoded_VkWin32SurfaceCreateInfoKHR
{
    using struct_type = VkWin32SurfaceCreateInfoKHR;

    VkWin32SurfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t hinstance{ 0 };
    uint64_t hwnd{ 0 };
};

struct Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR
{
    using struct_type = VkQueueFamilyQueryResultStatusPropertiesKHR;

    VkQueueFamilyQueryResultStatusPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyVideoPropertiesKHR
{
    using struct_type = VkQueueFamilyVideoPropertiesKHR;

    VkQueueFamilyVideoPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoProfileInfoKHR
{
    using struct_type = VkVideoProfileInfoKHR;

    VkVideoProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoProfileListInfoKHR
{
    using struct_type = VkVideoProfileListInfoKHR;

    VkVideoProfileListInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pProfiles{ nullptr };
};

struct Decoded_VkVideoCapabilitiesKHR
{
    using struct_type = VkVideoCapabilitiesKHR;

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

    VkPhysicalDeviceVideoFormatInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoFormatPropertiesKHR
{
    using struct_type = VkVideoFormatPropertiesKHR;

    VkVideoFormatPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkComponentMapping* componentMapping{ nullptr };
};

struct Decoded_VkVideoPictureResourceInfoKHR
{
    using struct_type = VkVideoPictureResourceInfoKHR;

    VkVideoPictureResourceInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkOffset2D* codedOffset{ nullptr };
    Decoded_VkExtent2D* codedExtent{ nullptr };
    format::HandleId imageViewBinding{ format::kNullHandleId };
};

struct Decoded_VkVideoReferenceSlotInfoKHR
{
    using struct_type = VkVideoReferenceSlotInfoKHR;

    VkVideoReferenceSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoPictureResourceInfoKHR>* pPictureResource{ nullptr };
};

struct Decoded_VkVideoSessionMemoryRequirementsKHR
{
    using struct_type = VkVideoSessionMemoryRequirementsKHR;

    VkVideoSessionMemoryRequirementsKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkMemoryRequirements* memoryRequirements{ nullptr };
};

struct Decoded_VkBindVideoSessionMemoryInfoKHR
{
    using struct_type = VkBindVideoSessionMemoryInfoKHR;

    VkBindVideoSessionMemoryInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkVideoSessionCreateInfoKHR
{
    using struct_type = VkVideoSessionCreateInfoKHR;

    VkVideoSessionCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile{ nullptr };
    Decoded_VkExtent2D* maxCodedExtent{ nullptr };
    StructPointerDecoder<Decoded_VkExtensionProperties>* pStdHeaderVersion{ nullptr };
};

struct Decoded_VkVideoSessionParametersCreateInfoKHR
{
    using struct_type = VkVideoSessionParametersCreateInfoKHR;

    VkVideoSessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId videoSessionParametersTemplate{ format::kNullHandleId };
    format::HandleId videoSession{ format::kNullHandleId };
};

struct Decoded_VkVideoSessionParametersUpdateInfoKHR
{
    using struct_type = VkVideoSessionParametersUpdateInfoKHR;

    VkVideoSessionParametersUpdateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoBeginCodingInfoKHR
{
    using struct_type = VkVideoBeginCodingInfoKHR;

    VkVideoBeginCodingInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId videoSession{ format::kNullHandleId };
    format::HandleId videoSessionParameters{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkVideoReferenceSlotInfoKHR>* pReferenceSlots{ nullptr };
};

struct Decoded_VkVideoEndCodingInfoKHR
{
    using struct_type = VkVideoEndCodingInfoKHR;

    VkVideoEndCodingInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoCodingControlInfoKHR
{
    using struct_type = VkVideoCodingControlInfoKHR;

    VkVideoCodingControlInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeCapabilitiesKHR
{
    using struct_type = VkVideoDecodeCapabilitiesKHR;

    VkVideoDecodeCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeUsageInfoKHR
{
    using struct_type = VkVideoDecodeUsageInfoKHR;

    VkVideoDecodeUsageInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeInfoKHR
{
    using struct_type = VkVideoDecodeInfoKHR;

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

    VkVideoEncodeH264CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264QpKHR
{
    using struct_type = VkVideoEncodeH264QpKHR;

    VkVideoEncodeH264QpKHR* decoded_value{ nullptr };
};

struct Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR
{
    using struct_type = VkVideoEncodeH264QualityLevelPropertiesKHR;

    VkVideoEncodeH264QualityLevelPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkVideoEncodeH264QpKHR* preferredConstantQp{ nullptr };
};

struct Decoded_VkVideoEncodeH264SessionCreateInfoKHR
{
    using struct_type = VkVideoEncodeH264SessionCreateInfoKHR;

    VkVideoEncodeH264SessionCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR
{
    using struct_type = VkVideoEncodeH264SessionParametersAddInfoKHR;

    VkVideoEncodeH264SessionParametersAddInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264SequenceParameterSet>* pStdSPSs{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264PictureParameterSet>* pStdPPSs{ nullptr };
};

struct Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR
{
    using struct_type = VkVideoEncodeH264SessionParametersCreateInfoKHR;

    VkVideoEncodeH264SessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR>* pParametersAddInfo{ nullptr };
};

struct Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR
{
    using struct_type = VkVideoEncodeH264SessionParametersGetInfoKHR;

    VkVideoEncodeH264SessionParametersGetInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR
{
    using struct_type = VkVideoEncodeH264SessionParametersFeedbackInfoKHR;

    VkVideoEncodeH264SessionParametersFeedbackInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264NaluSliceInfoKHR
{
    using struct_type = VkVideoEncodeH264NaluSliceInfoKHR;

    VkVideoEncodeH264NaluSliceInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH264SliceHeader>* pStdSliceHeader{ nullptr };
};

struct Decoded_VkVideoEncodeH264PictureInfoKHR
{
    using struct_type = VkVideoEncodeH264PictureInfoKHR;

    VkVideoEncodeH264PictureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoEncodeH264NaluSliceInfoKHR>* pNaluSliceEntries{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH264PictureInfo>* pStdPictureInfo{ nullptr };
};

struct Decoded_VkVideoEncodeH264DpbSlotInfoKHR
{
    using struct_type = VkVideoEncodeH264DpbSlotInfoKHR;

    VkVideoEncodeH264DpbSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH264ReferenceInfo>* pStdReferenceInfo{ nullptr };
};

struct Decoded_VkVideoEncodeH264ProfileInfoKHR
{
    using struct_type = VkVideoEncodeH264ProfileInfoKHR;

    VkVideoEncodeH264ProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264RateControlInfoKHR
{
    using struct_type = VkVideoEncodeH264RateControlInfoKHR;

    VkVideoEncodeH264RateControlInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH264FrameSizeKHR
{
    using struct_type = VkVideoEncodeH264FrameSizeKHR;

    VkVideoEncodeH264FrameSizeKHR* decoded_value{ nullptr };
};

struct Decoded_VkVideoEncodeH264RateControlLayerInfoKHR
{
    using struct_type = VkVideoEncodeH264RateControlLayerInfoKHR;

    VkVideoEncodeH264RateControlLayerInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkVideoEncodeH264QpKHR* minQp{ nullptr };
    Decoded_VkVideoEncodeH264QpKHR* maxQp{ nullptr };
    Decoded_VkVideoEncodeH264FrameSizeKHR* maxFrameSize{ nullptr };
};

struct Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR
{
    using struct_type = VkVideoEncodeH264GopRemainingFrameInfoKHR;

    VkVideoEncodeH264GopRemainingFrameInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH265CapabilitiesKHR
{
    using struct_type = VkVideoEncodeH265CapabilitiesKHR;

    VkVideoEncodeH265CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* maxTiles{ nullptr };
};

struct Decoded_VkVideoEncodeH265SessionCreateInfoKHR
{
    using struct_type = VkVideoEncodeH265SessionCreateInfoKHR;

    VkVideoEncodeH265SessionCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH265QpKHR
{
    using struct_type = VkVideoEncodeH265QpKHR;

    VkVideoEncodeH265QpKHR* decoded_value{ nullptr };
};

struct Decoded_VkVideoEncodeH265QualityLevelPropertiesKHR
{
    using struct_type = VkVideoEncodeH265QualityLevelPropertiesKHR;

    VkVideoEncodeH265QualityLevelPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkVideoEncodeH265QpKHR* preferredConstantQp{ nullptr };
};

struct Decoded_VkVideoEncodeH265SessionParametersAddInfoKHR
{
    using struct_type = VkVideoEncodeH265SessionParametersAddInfoKHR;

    VkVideoEncodeH265SessionParametersAddInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265VideoParameterSet>* pStdVPSs{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265SequenceParameterSet>* pStdSPSs{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265PictureParameterSet>* pStdPPSs{ nullptr };
};

struct Decoded_VkVideoEncodeH265SessionParametersCreateInfoKHR
{
    using struct_type = VkVideoEncodeH265SessionParametersCreateInfoKHR;

    VkVideoEncodeH265SessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoEncodeH265SessionParametersAddInfoKHR>* pParametersAddInfo{ nullptr };
};

struct Decoded_VkVideoEncodeH265SessionParametersGetInfoKHR
{
    using struct_type = VkVideoEncodeH265SessionParametersGetInfoKHR;

    VkVideoEncodeH265SessionParametersGetInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH265SessionParametersFeedbackInfoKHR
{
    using struct_type = VkVideoEncodeH265SessionParametersFeedbackInfoKHR;

    VkVideoEncodeH265SessionParametersFeedbackInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH265NaluSliceSegmentInfoKHR
{
    using struct_type = VkVideoEncodeH265NaluSliceSegmentInfoKHR;

    VkVideoEncodeH265NaluSliceSegmentInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH265SliceSegmentHeader>* pStdSliceSegmentHeader{ nullptr };
};

struct Decoded_VkVideoEncodeH265PictureInfoKHR
{
    using struct_type = VkVideoEncodeH265PictureInfoKHR;

    VkVideoEncodeH265PictureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoEncodeH265NaluSliceSegmentInfoKHR>* pNaluSliceSegmentEntries{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH265PictureInfo>* pStdPictureInfo{ nullptr };
};

struct Decoded_VkVideoEncodeH265DpbSlotInfoKHR
{
    using struct_type = VkVideoEncodeH265DpbSlotInfoKHR;

    VkVideoEncodeH265DpbSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoEncodeH265ReferenceInfo>* pStdReferenceInfo{ nullptr };
};

struct Decoded_VkVideoEncodeH265ProfileInfoKHR
{
    using struct_type = VkVideoEncodeH265ProfileInfoKHR;

    VkVideoEncodeH265ProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH265RateControlInfoKHR
{
    using struct_type = VkVideoEncodeH265RateControlInfoKHR;

    VkVideoEncodeH265RateControlInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeH265FrameSizeKHR
{
    using struct_type = VkVideoEncodeH265FrameSizeKHR;

    VkVideoEncodeH265FrameSizeKHR* decoded_value{ nullptr };
};

struct Decoded_VkVideoEncodeH265RateControlLayerInfoKHR
{
    using struct_type = VkVideoEncodeH265RateControlLayerInfoKHR;

    VkVideoEncodeH265RateControlLayerInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkVideoEncodeH265QpKHR* minQp{ nullptr };
    Decoded_VkVideoEncodeH265QpKHR* maxQp{ nullptr };
    Decoded_VkVideoEncodeH265FrameSizeKHR* maxFrameSize{ nullptr };
};

struct Decoded_VkVideoEncodeH265GopRemainingFrameInfoKHR
{
    using struct_type = VkVideoEncodeH265GopRemainingFrameInfoKHR;

    VkVideoEncodeH265GopRemainingFrameInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeH264ProfileInfoKHR
{
    using struct_type = VkVideoDecodeH264ProfileInfoKHR;

    VkVideoDecodeH264ProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeH264CapabilitiesKHR
{
    using struct_type = VkVideoDecodeH264CapabilitiesKHR;

    VkVideoDecodeH264CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkOffset2D* fieldOffsetGranularity{ nullptr };
};

struct Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR
{
    using struct_type = VkVideoDecodeH264SessionParametersAddInfoKHR;

    VkVideoDecodeH264SessionParametersAddInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264SequenceParameterSet>* pStdSPSs{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH264PictureParameterSet>* pStdPPSs{ nullptr };
};

struct Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR
{
    using struct_type = VkVideoDecodeH264SessionParametersCreateInfoKHR;

    VkVideoDecodeH264SessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR>* pParametersAddInfo{ nullptr };
};

struct Decoded_VkVideoDecodeH264PictureInfoKHR
{
    using struct_type = VkVideoDecodeH264PictureInfoKHR;

    VkVideoDecodeH264PictureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoDecodeH264PictureInfo>* pStdPictureInfo{ nullptr };
    PointerDecoder<uint32_t> pSliceOffsets;
};

struct Decoded_VkVideoDecodeH264DpbSlotInfoKHR
{
    using struct_type = VkVideoDecodeH264DpbSlotInfoKHR;

    VkVideoDecodeH264DpbSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoDecodeH264ReferenceInfo>* pStdReferenceInfo{ nullptr };
};

struct Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR
{
    using struct_type = VkRenderingFragmentShadingRateAttachmentInfoKHR;

    VkRenderingFragmentShadingRateAttachmentInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId imageView{ format::kNullHandleId };
    Decoded_VkExtent2D* shadingRateAttachmentTexelSize{ nullptr };
};

struct Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT
{
    using struct_type = VkRenderingFragmentDensityMapAttachmentInfoEXT;

    VkRenderingFragmentDensityMapAttachmentInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId imageView{ format::kNullHandleId };
};

struct Decoded_VkAttachmentSampleCountInfoAMD
{
    using struct_type = VkAttachmentSampleCountInfoAMD;

    VkAttachmentSampleCountInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkSampleCountFlagBits> pColorAttachmentSamples;
};

struct Decoded_VkMultiviewPerViewAttributesInfoNVX
{
    using struct_type = VkMultiviewPerViewAttributesInfoNVX;

    VkMultiviewPerViewAttributesInfoNVX* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkRenderingInfo Decoded_VkRenderingInfoKHR;

typedef Decoded_VkRenderingAttachmentInfo Decoded_VkRenderingAttachmentInfoKHR;

typedef Decoded_VkPipelineRenderingCreateInfo Decoded_VkPipelineRenderingCreateInfoKHR;

typedef Decoded_VkPhysicalDeviceDynamicRenderingFeatures Decoded_VkPhysicalDeviceDynamicRenderingFeaturesKHR;

typedef Decoded_VkCommandBufferInheritanceRenderingInfo Decoded_VkCommandBufferInheritanceRenderingInfoKHR;

typedef Decoded_VkAttachmentSampleCountInfoAMD Decoded_VkAttachmentSampleCountInfoNV;

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

struct Decoded_VkImportMemoryWin32HandleInfoKHR
{
    using struct_type = VkImportMemoryWin32HandleInfoKHR;

    VkImportMemoryWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportMemoryWin32HandleInfoKHR
{
    using struct_type = VkExportMemoryWin32HandleInfoKHR;

    VkExportMemoryWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>* pAttributes{ nullptr };
    WStringDecoder name;
};

struct Decoded_VkMemoryWin32HandlePropertiesKHR
{
    using struct_type = VkMemoryWin32HandlePropertiesKHR;

    VkMemoryWin32HandlePropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryGetWin32HandleInfoKHR
{
    using struct_type = VkMemoryGetWin32HandleInfoKHR;

    VkMemoryGetWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkImportMemoryFdInfoKHR
{
    using struct_type = VkImportMemoryFdInfoKHR;

    VkImportMemoryFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryFdPropertiesKHR
{
    using struct_type = VkMemoryFdPropertiesKHR;

    VkMemoryFdPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryGetFdInfoKHR
{
    using struct_type = VkMemoryGetFdInfoKHR;

    VkMemoryGetFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR
{
    using struct_type = VkWin32KeyedMutexAcquireReleaseInfoKHR;

    VkWin32KeyedMutexAcquireReleaseInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkDeviceMemory> pAcquireSyncs;
    PointerDecoder<uint64_t> pAcquireKeys;
    PointerDecoder<uint32_t> pAcquireTimeouts;
    HandlePointerDecoder<VkDeviceMemory> pReleaseSyncs;
    PointerDecoder<uint64_t> pReleaseKeys;
};

typedef Decoded_VkPhysicalDeviceExternalSemaphoreInfo Decoded_VkPhysicalDeviceExternalSemaphoreInfoKHR;

typedef Decoded_VkExternalSemaphoreProperties Decoded_VkExternalSemaphorePropertiesKHR;

typedef Decoded_VkExportSemaphoreCreateInfo Decoded_VkExportSemaphoreCreateInfoKHR;

struct Decoded_VkImportSemaphoreWin32HandleInfoKHR
{
    using struct_type = VkImportSemaphoreWin32HandleInfoKHR;

    VkImportSemaphoreWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportSemaphoreWin32HandleInfoKHR
{
    using struct_type = VkExportSemaphoreWin32HandleInfoKHR;

    VkExportSemaphoreWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>* pAttributes{ nullptr };
    WStringDecoder name;
};

struct Decoded_VkD3D12FenceSubmitInfoKHR
{
    using struct_type = VkD3D12FenceSubmitInfoKHR;

    VkD3D12FenceSubmitInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint64_t> pWaitSemaphoreValues;
    PointerDecoder<uint64_t> pSignalSemaphoreValues;
};

struct Decoded_VkSemaphoreGetWin32HandleInfoKHR
{
    using struct_type = VkSemaphoreGetWin32HandleInfoKHR;

    VkSemaphoreGetWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkImportSemaphoreFdInfoKHR
{
    using struct_type = VkImportSemaphoreFdInfoKHR;

    VkImportSemaphoreFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkSemaphoreGetFdInfoKHR
{
    using struct_type = VkSemaphoreGetFdInfoKHR;

    VkSemaphoreGetFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR
{
    using struct_type = VkPhysicalDevicePushDescriptorPropertiesKHR;

    VkPhysicalDevicePushDescriptorPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceShaderFloat16Int8Features Decoded_VkPhysicalDeviceShaderFloat16Int8FeaturesKHR;

typedef Decoded_VkPhysicalDeviceShaderFloat16Int8Features Decoded_VkPhysicalDeviceFloat16Int8FeaturesKHR;

typedef Decoded_VkPhysicalDevice16BitStorageFeatures Decoded_VkPhysicalDevice16BitStorageFeaturesKHR;

struct Decoded_VkRectLayerKHR
{
    using struct_type = VkRectLayerKHR;

    VkRectLayerKHR* decoded_value{ nullptr };

    Decoded_VkOffset2D* offset{ nullptr };
    Decoded_VkExtent2D* extent{ nullptr };
};

struct Decoded_VkPresentRegionKHR
{
    using struct_type = VkPresentRegionKHR;

    VkPresentRegionKHR* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkRectLayerKHR>* pRectangles{ nullptr };
};

struct Decoded_VkPresentRegionsKHR
{
    using struct_type = VkPresentRegionsKHR;

    VkPresentRegionsKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPresentRegionKHR>* pRegions{ nullptr };
};

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

struct Decoded_VkSharedPresentSurfaceCapabilitiesKHR
{
    using struct_type = VkSharedPresentSurfaceCapabilitiesKHR;

    VkSharedPresentSurfaceCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceExternalFenceInfo Decoded_VkPhysicalDeviceExternalFenceInfoKHR;

typedef Decoded_VkExternalFenceProperties Decoded_VkExternalFencePropertiesKHR;

typedef Decoded_VkExportFenceCreateInfo Decoded_VkExportFenceCreateInfoKHR;

struct Decoded_VkImportFenceWin32HandleInfoKHR
{
    using struct_type = VkImportFenceWin32HandleInfoKHR;

    VkImportFenceWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId fence{ format::kNullHandleId };
    uint64_t handle{ 0 };
    WStringDecoder name;
};

struct Decoded_VkExportFenceWin32HandleInfoKHR
{
    using struct_type = VkExportFenceWin32HandleInfoKHR;

    VkExportFenceWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>* pAttributes{ nullptr };
    WStringDecoder name;
};

struct Decoded_VkFenceGetWin32HandleInfoKHR
{
    using struct_type = VkFenceGetWin32HandleInfoKHR;

    VkFenceGetWin32HandleInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkImportFenceFdInfoKHR
{
    using struct_type = VkImportFenceFdInfoKHR;

    VkImportFenceFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkFenceGetFdInfoKHR
{
    using struct_type = VkFenceGetFdInfoKHR;

    VkFenceGetFdInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId fence{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR
{
    using struct_type = VkPhysicalDevicePerformanceQueryFeaturesKHR;

    VkPhysicalDevicePerformanceQueryFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR
{
    using struct_type = VkPhysicalDevicePerformanceQueryPropertiesKHR;

    VkPhysicalDevicePerformanceQueryPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceCounterKHR
{
    using struct_type = VkPerformanceCounterKHR;

    VkPerformanceCounterKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> uuid;
};

struct Decoded_VkPerformanceCounterDescriptionKHR
{
    using struct_type = VkPerformanceCounterDescriptionKHR;

    VkPerformanceCounterDescriptionKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
    StringDecoder category;
    StringDecoder description;
};

struct Decoded_VkQueryPoolPerformanceCreateInfoKHR
{
    using struct_type = VkQueryPoolPerformanceCreateInfoKHR;

    VkQueryPoolPerformanceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pCounterIndices;
};

struct Decoded_VkAcquireProfilingLockInfoKHR
{
    using struct_type = VkAcquireProfilingLockInfoKHR;

    VkAcquireProfilingLockInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceQuerySubmitInfoKHR
{
    using struct_type = VkPerformanceQuerySubmitInfoKHR;

    VkPerformanceQuerySubmitInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDevicePointClippingProperties Decoded_VkPhysicalDevicePointClippingPropertiesKHR;

typedef Decoded_VkRenderPassInputAttachmentAspectCreateInfo Decoded_VkRenderPassInputAttachmentAspectCreateInfoKHR;

typedef Decoded_VkInputAttachmentAspectReference Decoded_VkInputAttachmentAspectReferenceKHR;

typedef Decoded_VkImageViewUsageCreateInfo Decoded_VkImageViewUsageCreateInfoKHR;

typedef Decoded_VkPipelineTessellationDomainOriginStateCreateInfo Decoded_VkPipelineTessellationDomainOriginStateCreateInfoKHR;

struct Decoded_VkPhysicalDeviceSurfaceInfo2KHR
{
    using struct_type = VkPhysicalDeviceSurfaceInfo2KHR;

    VkPhysicalDeviceSurfaceInfo2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId surface{ format::kNullHandleId };
};

struct Decoded_VkSurfaceCapabilities2KHR
{
    using struct_type = VkSurfaceCapabilities2KHR;

    VkSurfaceCapabilities2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSurfaceCapabilitiesKHR* surfaceCapabilities{ nullptr };
};

struct Decoded_VkSurfaceFormat2KHR
{
    using struct_type = VkSurfaceFormat2KHR;

    VkSurfaceFormat2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSurfaceFormatKHR* surfaceFormat{ nullptr };
};

typedef Decoded_VkPhysicalDeviceVariablePointersFeatures Decoded_VkPhysicalDeviceVariablePointerFeaturesKHR;

typedef Decoded_VkPhysicalDeviceVariablePointersFeatures Decoded_VkPhysicalDeviceVariablePointersFeaturesKHR;

struct Decoded_VkDisplayProperties2KHR
{
    using struct_type = VkDisplayProperties2KHR;

    VkDisplayProperties2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDisplayPropertiesKHR* displayProperties{ nullptr };
};

struct Decoded_VkDisplayPlaneProperties2KHR
{
    using struct_type = VkDisplayPlaneProperties2KHR;

    VkDisplayPlaneProperties2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDisplayPlanePropertiesKHR* displayPlaneProperties{ nullptr };
};

struct Decoded_VkDisplayModeProperties2KHR
{
    using struct_type = VkDisplayModeProperties2KHR;

    VkDisplayModeProperties2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDisplayModePropertiesKHR* displayModeProperties{ nullptr };
};

struct Decoded_VkDisplayPlaneInfo2KHR
{
    using struct_type = VkDisplayPlaneInfo2KHR;

    VkDisplayPlaneInfo2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId mode{ format::kNullHandleId };
};

struct Decoded_VkDisplayPlaneCapabilities2KHR
{
    using struct_type = VkDisplayPlaneCapabilities2KHR;

    VkDisplayPlaneCapabilities2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDisplayPlaneCapabilitiesKHR* capabilities{ nullptr };
};

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

struct Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR
{
    using struct_type = VkPhysicalDevicePortabilitySubsetFeaturesKHR;

    VkPhysicalDevicePortabilitySubsetFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR
{
    using struct_type = VkPhysicalDevicePortabilitySubsetPropertiesKHR;

    VkPhysicalDevicePortabilitySubsetPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceMaintenance3Properties Decoded_VkPhysicalDeviceMaintenance3PropertiesKHR;

typedef Decoded_VkDescriptorSetLayoutSupport Decoded_VkDescriptorSetLayoutSupportKHR;

typedef Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeaturesKHR;

typedef Decoded_VkPhysicalDevice8BitStorageFeatures Decoded_VkPhysicalDevice8BitStorageFeaturesKHR;

typedef Decoded_VkPhysicalDeviceShaderAtomicInt64Features Decoded_VkPhysicalDeviceShaderAtomicInt64FeaturesKHR;

struct Decoded_VkPhysicalDeviceShaderClockFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderClockFeaturesKHR;

    VkPhysicalDeviceShaderClockFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeH265ProfileInfoKHR
{
    using struct_type = VkVideoDecodeH265ProfileInfoKHR;

    VkVideoDecodeH265ProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeH265CapabilitiesKHR
{
    using struct_type = VkVideoDecodeH265CapabilitiesKHR;

    VkVideoDecodeH265CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeH265SessionParametersAddInfoKHR
{
    using struct_type = VkVideoDecodeH265SessionParametersAddInfoKHR;

    VkVideoDecodeH265SessionParametersAddInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265VideoParameterSet>* pStdVPSs{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265SequenceParameterSet>* pStdSPSs{ nullptr };
    StructPointerDecoder<Decoded_StdVideoH265PictureParameterSet>* pStdPPSs{ nullptr };
};

struct Decoded_VkVideoDecodeH265SessionParametersCreateInfoKHR
{
    using struct_type = VkVideoDecodeH265SessionParametersCreateInfoKHR;

    VkVideoDecodeH265SessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoDecodeH265SessionParametersAddInfoKHR>* pParametersAddInfo{ nullptr };
};

struct Decoded_VkVideoDecodeH265PictureInfoKHR
{
    using struct_type = VkVideoDecodeH265PictureInfoKHR;

    VkVideoDecodeH265PictureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoDecodeH265PictureInfo>* pStdPictureInfo{ nullptr };
    PointerDecoder<uint32_t> pSliceSegmentOffsets;
};

struct Decoded_VkVideoDecodeH265DpbSlotInfoKHR
{
    using struct_type = VkVideoDecodeH265DpbSlotInfoKHR;

    VkVideoDecodeH265DpbSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoDecodeH265ReferenceInfo>* pStdReferenceInfo{ nullptr };
};

struct Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR
{
    using struct_type = VkDeviceQueueGlobalPriorityCreateInfoKHR;

    VkDeviceQueueGlobalPriorityCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR
{
    using struct_type = VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR;

    VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR
{
    using struct_type = VkQueueFamilyGlobalPriorityPropertiesKHR;

    VkQueueFamilyGlobalPriorityPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkQueueGlobalPriorityKHR> priorities;
};

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

struct Decoded_VkFragmentShadingRateAttachmentInfoKHR
{
    using struct_type = VkFragmentShadingRateAttachmentInfoKHR;

    VkFragmentShadingRateAttachmentInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentReference2>* pFragmentShadingRateAttachment{ nullptr };
    Decoded_VkExtent2D* shadingRateAttachmentTexelSize{ nullptr };
};

struct Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR
{
    using struct_type = VkPipelineFragmentShadingRateStateCreateInfoKHR;

    VkPipelineFragmentShadingRateStateCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* fragmentSize{ nullptr };
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;
};

struct Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR
{
    using struct_type = VkPhysicalDeviceFragmentShadingRateFeaturesKHR;

    VkPhysicalDeviceFragmentShadingRateFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR
{
    using struct_type = VkPhysicalDeviceFragmentShadingRatePropertiesKHR;

    VkPhysicalDeviceFragmentShadingRatePropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* minFragmentShadingRateAttachmentTexelSize{ nullptr };
    Decoded_VkExtent2D* maxFragmentShadingRateAttachmentTexelSize{ nullptr };
    Decoded_VkExtent2D* maxFragmentSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShadingRateKHR
{
    using struct_type = VkPhysicalDeviceFragmentShadingRateKHR;

    VkPhysicalDeviceFragmentShadingRateKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* fragmentSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR
{
    using struct_type = VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR;

    VkPhysicalDeviceDynamicRenderingLocalReadFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderingAttachmentLocationInfoKHR
{
    using struct_type = VkRenderingAttachmentLocationInfoKHR;

    VkRenderingAttachmentLocationInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pColorAttachmentLocations;
};

struct Decoded_VkRenderingInputAttachmentIndexInfoKHR
{
    using struct_type = VkRenderingInputAttachmentIndexInfoKHR;

    VkRenderingInputAttachmentIndexInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pColorAttachmentInputIndices;
    PointerDecoder<uint32_t> pDepthInputAttachmentIndex;
    PointerDecoder<uint32_t> pStencilInputAttachmentIndex;
};

struct Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderQuadControlFeaturesKHR;

    VkPhysicalDeviceShaderQuadControlFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceProtectedCapabilitiesKHR
{
    using struct_type = VkSurfaceProtectedCapabilitiesKHR;

    VkSurfaceProtectedCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeaturesKHR;

typedef Decoded_VkAttachmentReferenceStencilLayout Decoded_VkAttachmentReferenceStencilLayoutKHR;

typedef Decoded_VkAttachmentDescriptionStencilLayout Decoded_VkAttachmentDescriptionStencilLayoutKHR;

struct Decoded_VkPhysicalDevicePresentWaitFeaturesKHR
{
    using struct_type = VkPhysicalDevicePresentWaitFeaturesKHR;

    VkPhysicalDevicePresentWaitFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeaturesKHR;

typedef Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesKHR;

typedef Decoded_VkBufferDeviceAddressInfo Decoded_VkBufferDeviceAddressInfoKHR;

typedef Decoded_VkBufferOpaqueCaptureAddressCreateInfo Decoded_VkBufferOpaqueCaptureAddressCreateInfoKHR;

typedef Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo Decoded_VkMemoryOpaqueCaptureAddressAllocateInfoKHR;

typedef Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo Decoded_VkDeviceMemoryOpaqueCaptureAddressInfoKHR;

struct Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR
{
    using struct_type = VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR;

    VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineInfoKHR
{
    using struct_type = VkPipelineInfoKHR;

    VkPipelineInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkPipelineExecutablePropertiesKHR
{
    using struct_type = VkPipelineExecutablePropertiesKHR;

    VkPipelineExecutablePropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
    StringDecoder description;
};

struct Decoded_VkPipelineExecutableInfoKHR
{
    using struct_type = VkPipelineExecutableInfoKHR;

    VkPipelineExecutableInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkPipelineExecutableStatisticKHR
{
    using struct_type = VkPipelineExecutableStatisticKHR;

    VkPipelineExecutableStatisticKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
    StringDecoder description;
    Decoded_VkPipelineExecutableStatisticValueKHR* value{ nullptr };
};

struct Decoded_VkPipelineExecutableInternalRepresentationKHR
{
    using struct_type = VkPipelineExecutableInternalRepresentationKHR;

    VkPipelineExecutableInternalRepresentationKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder name;
    StringDecoder description;
    PointerDecoder<uint8_t> pData;
};

struct Decoded_VkMemoryMapInfoKHR
{
    using struct_type = VkMemoryMapInfoKHR;

    VkMemoryMapInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkMemoryUnmapInfoKHR
{
    using struct_type = VkMemoryUnmapInfoKHR;

    VkMemoryUnmapInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

typedef Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures Decoded_VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR;

typedef Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties Decoded_VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR;

struct Decoded_VkPipelineLibraryCreateInfoKHR
{
    using struct_type = VkPipelineLibraryCreateInfoKHR;

    VkPipelineLibraryCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkPipeline> pLibraries;
};

struct Decoded_VkPresentIdKHR
{
    using struct_type = VkPresentIdKHR;

    VkPresentIdKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint64_t> pPresentIds;
};

struct Decoded_VkPhysicalDevicePresentIdFeaturesKHR
{
    using struct_type = VkPhysicalDevicePresentIdFeaturesKHR;

    VkPhysicalDevicePresentIdFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeInfoKHR
{
    using struct_type = VkVideoEncodeInfoKHR;

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

    VkVideoEncodeCapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* encodeInputPictureGranularity{ nullptr };
};

struct Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR
{
    using struct_type = VkQueryPoolVideoEncodeFeedbackCreateInfoKHR;

    VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeUsageInfoKHR
{
    using struct_type = VkVideoEncodeUsageInfoKHR;

    VkVideoEncodeUsageInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeRateControlLayerInfoKHR
{
    using struct_type = VkVideoEncodeRateControlLayerInfoKHR;

    VkVideoEncodeRateControlLayerInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeRateControlInfoKHR
{
    using struct_type = VkVideoEncodeRateControlInfoKHR;

    VkVideoEncodeRateControlInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoEncodeRateControlLayerInfoKHR>* pLayers{ nullptr };
};

struct Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR
{
    using struct_type = VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR;

    VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVideoProfileInfoKHR>* pVideoProfile{ nullptr };
};

struct Decoded_VkVideoEncodeQualityLevelPropertiesKHR
{
    using struct_type = VkVideoEncodeQualityLevelPropertiesKHR;

    VkVideoEncodeQualityLevelPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeQualityLevelInfoKHR
{
    using struct_type = VkVideoEncodeQualityLevelInfoKHR;

    VkVideoEncodeQualityLevelInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoEncodeSessionParametersGetInfoKHR
{
    using struct_type = VkVideoEncodeSessionParametersGetInfoKHR;

    VkVideoEncodeSessionParametersGetInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId videoSessionParameters{ format::kNullHandleId };
};

struct Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR
{
    using struct_type = VkVideoEncodeSessionParametersFeedbackInfoKHR;

    VkVideoEncodeSessionParametersFeedbackInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyCheckpointProperties2NV
{
    using struct_type = VkQueueFamilyCheckpointProperties2NV;

    VkQueueFamilyCheckpointProperties2NV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCheckpointData2NV
{
    using struct_type = VkCheckpointData2NV;

    VkCheckpointData2NV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pCheckpointMarker{ 0 };
};

typedef Decoded_VkMemoryBarrier2 Decoded_VkMemoryBarrier2KHR;

typedef Decoded_VkBufferMemoryBarrier2 Decoded_VkBufferMemoryBarrier2KHR;

typedef Decoded_VkImageMemoryBarrier2 Decoded_VkImageMemoryBarrier2KHR;

typedef Decoded_VkDependencyInfo Decoded_VkDependencyInfoKHR;

typedef Decoded_VkSubmitInfo2 Decoded_VkSubmitInfo2KHR;

typedef Decoded_VkSemaphoreSubmitInfo Decoded_VkSemaphoreSubmitInfoKHR;

typedef Decoded_VkCommandBufferSubmitInfo Decoded_VkCommandBufferSubmitInfoKHR;

typedef Decoded_VkPhysicalDeviceSynchronization2Features Decoded_VkPhysicalDeviceSynchronization2FeaturesKHR;

struct Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR
{
    using struct_type = VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR;

    VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR
{
    using struct_type = VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR;

    VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR;

    VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR;

struct Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR
{
    using struct_type = VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR;

    VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

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

struct Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR
{
    using struct_type = VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR;

    VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTraceRaysIndirectCommand2KHR
{
    using struct_type = VkTraceRaysIndirectCommand2KHR;

    VkTraceRaysIndirectCommand2KHR* decoded_value{ nullptr };
};

typedef Decoded_VkPhysicalDeviceMaintenance4Features Decoded_VkPhysicalDeviceMaintenance4FeaturesKHR;

typedef Decoded_VkPhysicalDeviceMaintenance4Properties Decoded_VkPhysicalDeviceMaintenance4PropertiesKHR;

typedef Decoded_VkDeviceBufferMemoryRequirements Decoded_VkDeviceBufferMemoryRequirementsKHR;

typedef Decoded_VkDeviceImageMemoryRequirements Decoded_VkDeviceImageMemoryRequirementsKHR;

struct Decoded_VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR;

    VkPhysicalDeviceShaderSubgroupRotateFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR;

    VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance5FeaturesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance5FeaturesKHR;

    VkPhysicalDeviceMaintenance5FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance5PropertiesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance5PropertiesKHR;

    VkPhysicalDeviceMaintenance5PropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderingAreaInfoKHR
{
    using struct_type = VkRenderingAreaInfoKHR;

    VkRenderingAreaInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFormat> pColorAttachmentFormats;
};

struct Decoded_VkImageSubresource2KHR
{
    using struct_type = VkImageSubresource2KHR;

    VkImageSubresource2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkImageSubresource* imageSubresource{ nullptr };
};

struct Decoded_VkDeviceImageSubresourceInfoKHR
{
    using struct_type = VkDeviceImageSubresourceInfoKHR;

    VkDeviceImageSubresourceInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkImageCreateInfo>* pCreateInfo{ nullptr };
    StructPointerDecoder<Decoded_VkImageSubresource2KHR>* pSubresource{ nullptr };
};

struct Decoded_VkSubresourceLayout2KHR
{
    using struct_type = VkSubresourceLayout2KHR;

    VkSubresourceLayout2KHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSubresourceLayout* subresourceLayout{ nullptr };
};

struct Decoded_VkPipelineCreateFlags2CreateInfoKHR
{
    using struct_type = VkPipelineCreateFlags2CreateInfoKHR;

    VkPipelineCreateFlags2CreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferUsageFlags2CreateInfoKHR
{
    using struct_type = VkBufferUsageFlags2CreateInfoKHR;

    VkBufferUsageFlags2CreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR
{
    using struct_type = VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR;

    VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCooperativeMatrixPropertiesKHR
{
    using struct_type = VkCooperativeMatrixPropertiesKHR;

    VkCooperativeMatrixPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixFeaturesKHR;

    VkPhysicalDeviceCooperativeMatrixFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixPropertiesKHR;

    VkPhysicalDeviceCooperativeMatrixPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeAV1ProfileInfoKHR
{
    using struct_type = VkVideoDecodeAV1ProfileInfoKHR;

    VkVideoDecodeAV1ProfileInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeAV1CapabilitiesKHR
{
    using struct_type = VkVideoDecodeAV1CapabilitiesKHR;

    VkVideoDecodeAV1CapabilitiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR
{
    using struct_type = VkVideoDecodeAV1SessionParametersCreateInfoKHR;

    VkVideoDecodeAV1SessionParametersCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoAV1SequenceHeader>* pStdSequenceHeader{ nullptr };
};

struct Decoded_VkVideoDecodeAV1PictureInfoKHR
{
    using struct_type = VkVideoDecodeAV1PictureInfoKHR;

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

    VkVideoDecodeAV1DpbSlotInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_StdVideoDecodeAV1ReferenceInfo>* pStdReferenceInfo{ nullptr };
};

struct Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR
{
    using struct_type = VkPhysicalDeviceVideoMaintenance1FeaturesKHR;

    VkPhysicalDeviceVideoMaintenance1FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVideoInlineQueryInfoKHR
{
    using struct_type = VkVideoInlineQueryInfoKHR;

    VkVideoInlineQueryInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId queryPool{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR;

    VkPhysicalDeviceVertexAttributeDivisorPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVertexInputBindingDivisorDescriptionKHR
{
    using struct_type = VkVertexInputBindingDivisorDescriptionKHR;

    VkVertexInputBindingDivisorDescriptionKHR* decoded_value{ nullptr };
};

struct Decoded_VkPipelineVertexInputDivisorStateCreateInfoKHR
{
    using struct_type = VkPipelineVertexInputDivisorStateCreateInfoKHR;

    VkPipelineVertexInputDivisorStateCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkVertexInputBindingDivisorDescriptionKHR>* pVertexBindingDivisors{ nullptr };
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR;

    VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderFloatControls2FeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderFloatControls2FeaturesKHR;

    VkPhysicalDeviceShaderFloatControls2FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesKHR
{
    using struct_type = VkPhysicalDeviceIndexTypeUint8FeaturesKHR;

    VkPhysicalDeviceIndexTypeUint8FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceLineRasterizationFeaturesKHR
{
    using struct_type = VkPhysicalDeviceLineRasterizationFeaturesKHR;

    VkPhysicalDeviceLineRasterizationFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceLineRasterizationPropertiesKHR
{
    using struct_type = VkPhysicalDeviceLineRasterizationPropertiesKHR;

    VkPhysicalDeviceLineRasterizationPropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRasterizationLineStateCreateInfoKHR
{
    using struct_type = VkPipelineRasterizationLineStateCreateInfoKHR;

    VkPipelineRasterizationLineStateCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCalibratedTimestampInfoKHR
{
    using struct_type = VkCalibratedTimestampInfoKHR;

    VkCalibratedTimestampInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderExpectAssumeFeaturesKHR
{
    using struct_type = VkPhysicalDeviceShaderExpectAssumeFeaturesKHR;

    VkPhysicalDeviceShaderExpectAssumeFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance6FeaturesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance6FeaturesKHR;

    VkPhysicalDeviceMaintenance6FeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMaintenance6PropertiesKHR
{
    using struct_type = VkPhysicalDeviceMaintenance6PropertiesKHR;

    VkPhysicalDeviceMaintenance6PropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBindMemoryStatusKHR
{
    using struct_type = VkBindMemoryStatusKHR;

    VkBindMemoryStatusKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkResult> pResult;
};

struct Decoded_VkBindDescriptorSetsInfoKHR
{
    using struct_type = VkBindDescriptorSetsInfoKHR;

    VkBindDescriptorSetsInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    HandlePointerDecoder<VkDescriptorSet> pDescriptorSets;
    PointerDecoder<uint32_t> pDynamicOffsets;
};

struct Decoded_VkPushConstantsInfoKHR
{
    using struct_type = VkPushConstantsInfoKHR;

    VkPushConstantsInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    PointerDecoder<uint8_t> pValues;
};

struct Decoded_VkPushDescriptorSetInfoKHR
{
    using struct_type = VkPushDescriptorSetInfoKHR;

    VkPushDescriptorSetInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkWriteDescriptorSet>* pDescriptorWrites{ nullptr };
};

struct Decoded_VkPushDescriptorSetWithTemplateInfoKHR
{
    using struct_type = VkPushDescriptorSetWithTemplateInfoKHR;

    VkPushDescriptorSetWithTemplateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId descriptorUpdateTemplate{ format::kNullHandleId };
    format::HandleId layout{ format::kNullHandleId };
    uint64_t pData{ 0 };
};

struct Decoded_VkSetDescriptorBufferOffsetsInfoEXT
{
    using struct_type = VkSetDescriptorBufferOffsetsInfoEXT;

    VkSetDescriptorBufferOffsetsInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
    PointerDecoder<uint32_t> pBufferIndices;
    PointerDecoder<VkDeviceSize> pOffsets;
};

struct Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT
{
    using struct_type = VkBindDescriptorBufferEmbeddedSamplersInfoEXT;

    VkBindDescriptorBufferEmbeddedSamplersInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId layout{ format::kNullHandleId };
};

struct Decoded_VkDebugReportCallbackCreateInfoEXT
{
    using struct_type = VkDebugReportCallbackCreateInfoEXT;

    VkDebugReportCallbackCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pfnCallback{ 0 };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkPipelineRasterizationStateRasterizationOrderAMD
{
    using struct_type = VkPipelineRasterizationStateRasterizationOrderAMD;

    VkPipelineRasterizationStateRasterizationOrderAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDebugMarkerObjectNameInfoEXT
{
    using struct_type = VkDebugMarkerObjectNameInfoEXT;

    VkDebugMarkerObjectNameInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t object{ 0 };
    StringDecoder pObjectName;
};

struct Decoded_VkDebugMarkerObjectTagInfoEXT
{
    using struct_type = VkDebugMarkerObjectTagInfoEXT;

    VkDebugMarkerObjectTagInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t object{ 0 };
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkDebugMarkerMarkerInfoEXT
{
    using struct_type = VkDebugMarkerMarkerInfoEXT;

    VkDebugMarkerMarkerInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder pMarkerName;
    PointerDecoder<float> color;
};

struct Decoded_VkDedicatedAllocationImageCreateInfoNV
{
    using struct_type = VkDedicatedAllocationImageCreateInfoNV;

    VkDedicatedAllocationImageCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDedicatedAllocationBufferCreateInfoNV
{
    using struct_type = VkDedicatedAllocationBufferCreateInfoNV;

    VkDedicatedAllocationBufferCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDedicatedAllocationMemoryAllocateInfoNV
{
    using struct_type = VkDedicatedAllocationMemoryAllocateInfoNV;

    VkDedicatedAllocationMemoryAllocateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT
{
    using struct_type = VkPhysicalDeviceTransformFeedbackFeaturesEXT;

    VkPhysicalDeviceTransformFeedbackFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT
{
    using struct_type = VkPhysicalDeviceTransformFeedbackPropertiesEXT;

    VkPhysicalDeviceTransformFeedbackPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationStateStreamCreateInfoEXT;

    VkPipelineRasterizationStateStreamCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageViewHandleInfoNVX
{
    using struct_type = VkImageViewHandleInfoNVX;

    VkImageViewHandleInfoNVX* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId imageView{ format::kNullHandleId };
    format::HandleId sampler{ format::kNullHandleId };
};

struct Decoded_VkImageViewAddressPropertiesNVX
{
    using struct_type = VkImageViewAddressPropertiesNVX;

    VkImageViewAddressPropertiesNVX* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTextureLODGatherFormatPropertiesAMD
{
    using struct_type = VkTextureLODGatherFormatPropertiesAMD;

    VkTextureLODGatherFormatPropertiesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkShaderResourceUsageAMD
{
    using struct_type = VkShaderResourceUsageAMD;

    VkShaderResourceUsageAMD* decoded_value{ nullptr };
};

struct Decoded_VkShaderStatisticsInfoAMD
{
    using struct_type = VkShaderStatisticsInfoAMD;

    VkShaderStatisticsInfoAMD* decoded_value{ nullptr };

    Decoded_VkShaderResourceUsageAMD* resourceUsage{ nullptr };
    PointerDecoder<uint32_t> computeWorkGroupSize;
};

struct Decoded_VkStreamDescriptorSurfaceCreateInfoGGP
{
    using struct_type = VkStreamDescriptorSurfaceCreateInfoGGP;

    VkStreamDescriptorSurfaceCreateInfoGGP* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV
{
    using struct_type = VkPhysicalDeviceCornerSampledImageFeaturesNV;

    VkPhysicalDeviceCornerSampledImageFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalImageFormatPropertiesNV
{
    using struct_type = VkExternalImageFormatPropertiesNV;

    VkExternalImageFormatPropertiesNV* decoded_value{ nullptr };

    Decoded_VkImageFormatProperties* imageFormatProperties{ nullptr };
};

struct Decoded_VkExternalMemoryImageCreateInfoNV
{
    using struct_type = VkExternalMemoryImageCreateInfoNV;

    VkExternalMemoryImageCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExportMemoryAllocateInfoNV
{
    using struct_type = VkExportMemoryAllocateInfoNV;

    VkExportMemoryAllocateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImportMemoryWin32HandleInfoNV
{
    using struct_type = VkImportMemoryWin32HandleInfoNV;

    VkImportMemoryWin32HandleInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t handle{ 0 };
};

struct Decoded_VkExportMemoryWin32HandleInfoNV
{
    using struct_type = VkExportMemoryWin32HandleInfoNV;

    VkExportMemoryWin32HandleInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_SECURITY_ATTRIBUTES>* pAttributes{ nullptr };
};

struct Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV
{
    using struct_type = VkWin32KeyedMutexAcquireReleaseInfoNV;

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

    VkValidationFlagsEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkValidationCheckEXT> pDisabledValidationChecks;
};

struct Decoded_VkViSurfaceCreateInfoNN
{
    using struct_type = VkViSurfaceCreateInfoNN;

    VkViSurfaceCreateInfoNN* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t window{ 0 };
};

typedef Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT;

struct Decoded_VkImageViewASTCDecodeModeEXT
{
    using struct_type = VkImageViewASTCDecodeModeEXT;

    VkImageViewASTCDecodeModeEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT
{
    using struct_type = VkPhysicalDeviceASTCDecodeFeaturesEXT;

    VkPhysicalDeviceASTCDecodeFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT
{
    using struct_type = VkPhysicalDevicePipelineRobustnessFeaturesEXT;

    VkPhysicalDevicePipelineRobustnessFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineRobustnessPropertiesEXT
{
    using struct_type = VkPhysicalDevicePipelineRobustnessPropertiesEXT;

    VkPhysicalDevicePipelineRobustnessPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRobustnessCreateInfoEXT
{
    using struct_type = VkPipelineRobustnessCreateInfoEXT;

    VkPipelineRobustnessCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkConditionalRenderingBeginInfoEXT
{
    using struct_type = VkConditionalRenderingBeginInfoEXT;

    VkConditionalRenderingBeginInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT
{
    using struct_type = VkPhysicalDeviceConditionalRenderingFeaturesEXT;

    VkPhysicalDeviceConditionalRenderingFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT
{
    using struct_type = VkCommandBufferInheritanceConditionalRenderingInfoEXT;

    VkCommandBufferInheritanceConditionalRenderingInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkViewportWScalingNV
{
    using struct_type = VkViewportWScalingNV;

    VkViewportWScalingNV* decoded_value{ nullptr };
};

struct Decoded_VkPipelineViewportWScalingStateCreateInfoNV
{
    using struct_type = VkPipelineViewportWScalingStateCreateInfoNV;

    VkPipelineViewportWScalingStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkViewportWScalingNV>* pViewportWScalings{ nullptr };
};

struct Decoded_VkSurfaceCapabilities2EXT
{
    using struct_type = VkSurfaceCapabilities2EXT;

    VkSurfaceCapabilities2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* currentExtent{ nullptr };
    Decoded_VkExtent2D* minImageExtent{ nullptr };
    Decoded_VkExtent2D* maxImageExtent{ nullptr };
};

struct Decoded_VkDisplayPowerInfoEXT
{
    using struct_type = VkDisplayPowerInfoEXT;

    VkDisplayPowerInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceEventInfoEXT
{
    using struct_type = VkDeviceEventInfoEXT;

    VkDeviceEventInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDisplayEventInfoEXT
{
    using struct_type = VkDisplayEventInfoEXT;

    VkDisplayEventInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainCounterCreateInfoEXT
{
    using struct_type = VkSwapchainCounterCreateInfoEXT;

    VkSwapchainCounterCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRefreshCycleDurationGOOGLE
{
    using struct_type = VkRefreshCycleDurationGOOGLE;

    VkRefreshCycleDurationGOOGLE* decoded_value{ nullptr };
};

struct Decoded_VkPastPresentationTimingGOOGLE
{
    using struct_type = VkPastPresentationTimingGOOGLE;

    VkPastPresentationTimingGOOGLE* decoded_value{ nullptr };
};

struct Decoded_VkPresentTimeGOOGLE
{
    using struct_type = VkPresentTimeGOOGLE;

    VkPresentTimeGOOGLE* decoded_value{ nullptr };
};

struct Decoded_VkPresentTimesInfoGOOGLE
{
    using struct_type = VkPresentTimesInfoGOOGLE;

    VkPresentTimesInfoGOOGLE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPresentTimeGOOGLE>* pTimes{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX
{
    using struct_type = VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX;

    VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkViewportSwizzleNV
{
    using struct_type = VkViewportSwizzleNV;

    VkViewportSwizzleNV* decoded_value{ nullptr };
};

struct Decoded_VkPipelineViewportSwizzleStateCreateInfoNV
{
    using struct_type = VkPipelineViewportSwizzleStateCreateInfoNV;

    VkPipelineViewportSwizzleStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkViewportSwizzleNV>* pViewportSwizzles{ nullptr };
};

struct Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT
{
    using struct_type = VkPhysicalDeviceDiscardRectanglePropertiesEXT;

    VkPhysicalDeviceDiscardRectanglePropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT
{
    using struct_type = VkPipelineDiscardRectangleStateCreateInfoEXT;

    VkPipelineDiscardRectangleStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pDiscardRectangles{ nullptr };
};

struct Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT
{
    using struct_type = VkPhysicalDeviceConservativeRasterizationPropertiesEXT;

    VkPhysicalDeviceConservativeRasterizationPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationConservativeStateCreateInfoEXT;

    VkPipelineRasterizationConservativeStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDepthClipEnableFeaturesEXT;

    VkPhysicalDeviceDepthClipEnableFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationDepthClipStateCreateInfoEXT;

    VkPipelineRasterizationDepthClipStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkXYColorEXT
{
    using struct_type = VkXYColorEXT;

    VkXYColorEXT* decoded_value{ nullptr };
};

struct Decoded_VkHdrMetadataEXT
{
    using struct_type = VkHdrMetadataEXT;

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

    VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkIOSSurfaceCreateInfoMVK
{
    using struct_type = VkIOSSurfaceCreateInfoMVK;

    VkIOSSurfaceCreateInfoMVK* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pView{ 0 };
};

struct Decoded_VkMacOSSurfaceCreateInfoMVK
{
    using struct_type = VkMacOSSurfaceCreateInfoMVK;

    VkMacOSSurfaceCreateInfoMVK* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pView{ 0 };
};

struct Decoded_VkDebugUtilsLabelEXT
{
    using struct_type = VkDebugUtilsLabelEXT;

    VkDebugUtilsLabelEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder pLabelName;
    PointerDecoder<float> color;
};

struct Decoded_VkDebugUtilsObjectNameInfoEXT
{
    using struct_type = VkDebugUtilsObjectNameInfoEXT;

    VkDebugUtilsObjectNameInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t objectHandle{ 0 };
    StringDecoder pObjectName;
};

struct Decoded_VkDebugUtilsMessengerCallbackDataEXT
{
    using struct_type = VkDebugUtilsMessengerCallbackDataEXT;

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

    VkDebugUtilsMessengerCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pfnUserCallback{ 0 };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkDebugUtilsObjectTagInfoEXT
{
    using struct_type = VkDebugUtilsObjectTagInfoEXT;

    VkDebugUtilsObjectTagInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t objectHandle{ 0 };
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkAndroidHardwareBufferUsageANDROID
{
    using struct_type = VkAndroidHardwareBufferUsageANDROID;

    VkAndroidHardwareBufferUsageANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAndroidHardwareBufferPropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferPropertiesANDROID;

    VkAndroidHardwareBufferPropertiesANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferFormatPropertiesANDROID;

    VkAndroidHardwareBufferFormatPropertiesANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkComponentMapping* samplerYcbcrConversionComponents{ nullptr };
};

struct Decoded_VkImportAndroidHardwareBufferInfoANDROID
{
    using struct_type = VkImportAndroidHardwareBufferInfoANDROID;

    VkImportAndroidHardwareBufferInfoANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t buffer{ 0 };
};

struct Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID
{
    using struct_type = VkMemoryGetAndroidHardwareBufferInfoANDROID;

    VkMemoryGetAndroidHardwareBufferInfoANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkExternalFormatANDROID
{
    using struct_type = VkExternalFormatANDROID;

    VkExternalFormatANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID
{
    using struct_type = VkAndroidHardwareBufferFormatProperties2ANDROID;

    VkAndroidHardwareBufferFormatProperties2ANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkComponentMapping* samplerYcbcrConversionComponents{ nullptr };
};

typedef Decoded_VkSamplerReductionModeCreateInfo Decoded_VkSamplerReductionModeCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties Decoded_VkPhysicalDeviceSamplerFilterMinmaxPropertiesEXT;

typedef Decoded_VkPhysicalDeviceInlineUniformBlockFeatures Decoded_VkPhysicalDeviceInlineUniformBlockFeaturesEXT;

typedef Decoded_VkPhysicalDeviceInlineUniformBlockProperties Decoded_VkPhysicalDeviceInlineUniformBlockPropertiesEXT;

typedef Decoded_VkWriteDescriptorSetInlineUniformBlock Decoded_VkWriteDescriptorSetInlineUniformBlockEXT;

typedef Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo Decoded_VkDescriptorPoolInlineUniformBlockCreateInfoEXT;

struct Decoded_VkSampleLocationEXT
{
    using struct_type = VkSampleLocationEXT;

    VkSampleLocationEXT* decoded_value{ nullptr };
};

struct Decoded_VkSampleLocationsInfoEXT
{
    using struct_type = VkSampleLocationsInfoEXT;

    VkSampleLocationsInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* sampleLocationGridSize{ nullptr };
    StructPointerDecoder<Decoded_VkSampleLocationEXT>* pSampleLocations{ nullptr };
};

struct Decoded_VkAttachmentSampleLocationsEXT
{
    using struct_type = VkAttachmentSampleLocationsEXT;

    VkAttachmentSampleLocationsEXT* decoded_value{ nullptr };

    Decoded_VkSampleLocationsInfoEXT* sampleLocationsInfo{ nullptr };
};

struct Decoded_VkSubpassSampleLocationsEXT
{
    using struct_type = VkSubpassSampleLocationsEXT;

    VkSubpassSampleLocationsEXT* decoded_value{ nullptr };

    Decoded_VkSampleLocationsInfoEXT* sampleLocationsInfo{ nullptr };
};

struct Decoded_VkRenderPassSampleLocationsBeginInfoEXT
{
    using struct_type = VkRenderPassSampleLocationsBeginInfoEXT;

    VkRenderPassSampleLocationsBeginInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkAttachmentSampleLocationsEXT>* pAttachmentInitialSampleLocations{ nullptr };
    StructPointerDecoder<Decoded_VkSubpassSampleLocationsEXT>* pPostSubpassSampleLocations{ nullptr };
};

struct Decoded_VkPipelineSampleLocationsStateCreateInfoEXT
{
    using struct_type = VkPipelineSampleLocationsStateCreateInfoEXT;

    VkPipelineSampleLocationsStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkSampleLocationsInfoEXT* sampleLocationsInfo{ nullptr };
};

struct Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT
{
    using struct_type = VkPhysicalDeviceSampleLocationsPropertiesEXT;

    VkPhysicalDeviceSampleLocationsPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* maxSampleLocationGridSize{ nullptr };
    PointerDecoder<float> sampleLocationCoordinateRange;
};

struct Decoded_VkMultisamplePropertiesEXT
{
    using struct_type = VkMultisamplePropertiesEXT;

    VkMultisamplePropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* maxSampleLocationGridSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT;

    VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT
{
    using struct_type = VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT;

    VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT
{
    using struct_type = VkPipelineColorBlendAdvancedStateCreateInfoEXT;

    VkPipelineColorBlendAdvancedStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCoverageToColorStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageToColorStateCreateInfoNV;

    VkPipelineCoverageToColorStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCoverageModulationStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageModulationStateCreateInfoNV;

    VkPipelineCoverageModulationStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<float> pCoverageModulationTable;
};

struct Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV
{
    using struct_type = VkPhysicalDeviceShaderSMBuiltinsPropertiesNV;

    VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV
{
    using struct_type = VkPhysicalDeviceShaderSMBuiltinsFeaturesNV;

    VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDrmFormatModifierPropertiesEXT
{
    using struct_type = VkDrmFormatModifierPropertiesEXT;

    VkDrmFormatModifierPropertiesEXT* decoded_value{ nullptr };
};

struct Decoded_VkDrmFormatModifierPropertiesListEXT
{
    using struct_type = VkDrmFormatModifierPropertiesListEXT;

    VkDrmFormatModifierPropertiesListEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDrmFormatModifierPropertiesEXT>* pDrmFormatModifierProperties{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT
{
    using struct_type = VkPhysicalDeviceImageDrmFormatModifierInfoEXT;

    VkPhysicalDeviceImageDrmFormatModifierInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> pQueueFamilyIndices;
};

struct Decoded_VkImageDrmFormatModifierListCreateInfoEXT
{
    using struct_type = VkImageDrmFormatModifierListCreateInfoEXT;

    VkImageDrmFormatModifierListCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint64_t> pDrmFormatModifiers;
};

struct Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT
{
    using struct_type = VkImageDrmFormatModifierExplicitCreateInfoEXT;

    VkImageDrmFormatModifierExplicitCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkSubresourceLayout>* pPlaneLayouts{ nullptr };
};

struct Decoded_VkImageDrmFormatModifierPropertiesEXT
{
    using struct_type = VkImageDrmFormatModifierPropertiesEXT;

    VkImageDrmFormatModifierPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDrmFormatModifierProperties2EXT
{
    using struct_type = VkDrmFormatModifierProperties2EXT;

    VkDrmFormatModifierProperties2EXT* decoded_value{ nullptr };
};

struct Decoded_VkDrmFormatModifierPropertiesList2EXT
{
    using struct_type = VkDrmFormatModifierPropertiesList2EXT;

    VkDrmFormatModifierPropertiesList2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDrmFormatModifierProperties2EXT>* pDrmFormatModifierProperties{ nullptr };
};

struct Decoded_VkValidationCacheCreateInfoEXT
{
    using struct_type = VkValidationCacheCreateInfoEXT;

    VkValidationCacheCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pInitialData;
};

struct Decoded_VkShaderModuleValidationCacheCreateInfoEXT
{
    using struct_type = VkShaderModuleValidationCacheCreateInfoEXT;

    VkShaderModuleValidationCacheCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId validationCache{ format::kNullHandleId };
};

typedef Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceDescriptorIndexingFeatures Decoded_VkPhysicalDeviceDescriptorIndexingFeaturesEXT;

typedef Decoded_VkPhysicalDeviceDescriptorIndexingProperties Decoded_VkPhysicalDeviceDescriptorIndexingPropertiesEXT;

typedef Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfoEXT;

typedef Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupportEXT;

struct Decoded_VkShadingRatePaletteNV
{
    using struct_type = VkShadingRatePaletteNV;

    VkShadingRatePaletteNV* decoded_value{ nullptr };

    PointerDecoder<VkShadingRatePaletteEntryNV> pShadingRatePaletteEntries;
};

struct Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV
{
    using struct_type = VkPipelineViewportShadingRateImageStateCreateInfoNV;

    VkPipelineViewportShadingRateImageStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkShadingRatePaletteNV>* pShadingRatePalettes{ nullptr };
};

struct Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV
{
    using struct_type = VkPhysicalDeviceShadingRateImageFeaturesNV;

    VkPhysicalDeviceShadingRateImageFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV
{
    using struct_type = VkPhysicalDeviceShadingRateImagePropertiesNV;

    VkPhysicalDeviceShadingRateImagePropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* shadingRateTexelSize{ nullptr };
};

struct Decoded_VkCoarseSampleLocationNV
{
    using struct_type = VkCoarseSampleLocationNV;

    VkCoarseSampleLocationNV* decoded_value{ nullptr };
};

struct Decoded_VkCoarseSampleOrderCustomNV
{
    using struct_type = VkCoarseSampleOrderCustomNV;

    VkCoarseSampleOrderCustomNV* decoded_value{ nullptr };

    StructPointerDecoder<Decoded_VkCoarseSampleLocationNV>* pSampleLocations{ nullptr };
};

struct Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV
{
    using struct_type = VkPipelineViewportCoarseSampleOrderStateCreateInfoNV;

    VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkCoarseSampleOrderCustomNV>* pCustomSampleOrders{ nullptr };
};

struct Decoded_VkRayTracingShaderGroupCreateInfoNV
{
    using struct_type = VkRayTracingShaderGroupCreateInfoNV;

    VkRayTracingShaderGroupCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRayTracingPipelineCreateInfoNV
{
    using struct_type = VkRayTracingPipelineCreateInfoNV;

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

    VkGeometryTrianglesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId vertexData{ format::kNullHandleId };
    format::HandleId indexData{ format::kNullHandleId };
    format::HandleId transformData{ format::kNullHandleId };
};

struct Decoded_VkGeometryAABBNV
{
    using struct_type = VkGeometryAABBNV;

    VkGeometryAABBNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId aabbData{ format::kNullHandleId };
};

struct Decoded_VkGeometryDataNV
{
    using struct_type = VkGeometryDataNV;

    VkGeometryDataNV* decoded_value{ nullptr };

    Decoded_VkGeometryTrianglesNV* triangles{ nullptr };
    Decoded_VkGeometryAABBNV* aabbs{ nullptr };
};

struct Decoded_VkGeometryNV
{
    using struct_type = VkGeometryNV;

    VkGeometryNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkGeometryDataNV* geometry{ nullptr };
};

struct Decoded_VkAccelerationStructureInfoNV
{
    using struct_type = VkAccelerationStructureInfoNV;

    VkAccelerationStructureInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkGeometryNV>* pGeometries{ nullptr };
};

struct Decoded_VkAccelerationStructureCreateInfoNV
{
    using struct_type = VkAccelerationStructureCreateInfoNV;

    VkAccelerationStructureCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkAccelerationStructureInfoNV* info{ nullptr };
};

struct Decoded_VkBindAccelerationStructureMemoryInfoNV
{
    using struct_type = VkBindAccelerationStructureMemoryInfoNV;

    VkBindAccelerationStructureMemoryInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId accelerationStructure{ format::kNullHandleId };
    format::HandleId memory{ format::kNullHandleId };
    PointerDecoder<uint32_t> pDeviceIndices;
};

struct Decoded_VkWriteDescriptorSetAccelerationStructureNV
{
    using struct_type = VkWriteDescriptorSetAccelerationStructureNV;

    VkWriteDescriptorSetAccelerationStructureNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkAccelerationStructureNV> pAccelerationStructures;
};

struct Decoded_VkAccelerationStructureMemoryRequirementsInfoNV
{
    using struct_type = VkAccelerationStructureMemoryRequirementsInfoNV;

    VkAccelerationStructureMemoryRequirementsInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId accelerationStructure{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceRayTracingPropertiesNV
{
    using struct_type = VkPhysicalDeviceRayTracingPropertiesNV;

    VkPhysicalDeviceRayTracingPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTransformMatrixKHR
{
    using struct_type = VkTransformMatrixKHR;

    VkTransformMatrixKHR* decoded_value{ nullptr };

    PointerDecoder<float> matrix;
};

struct Decoded_VkAabbPositionsKHR
{
    using struct_type = VkAabbPositionsKHR;

    VkAabbPositionsKHR* decoded_value{ nullptr };
};

struct Decoded_VkAccelerationStructureInstanceKHR
{
    using struct_type = VkAccelerationStructureInstanceKHR;

    VkAccelerationStructureInstanceKHR* decoded_value{ nullptr };

    Decoded_VkTransformMatrixKHR* transform{ nullptr };
};

typedef Decoded_VkTransformMatrixKHR Decoded_VkTransformMatrixNV;

typedef Decoded_VkAabbPositionsKHR Decoded_VkAabbPositionsNV;

typedef Decoded_VkAccelerationStructureInstanceKHR Decoded_VkAccelerationStructureInstanceNV;

struct Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV
{
    using struct_type = VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV;

    VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV
{
    using struct_type = VkPipelineRepresentativeFragmentTestStateCreateInfoNV;

    VkPipelineRepresentativeFragmentTestStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT
{
    using struct_type = VkPhysicalDeviceImageViewImageFormatInfoEXT;

    VkPhysicalDeviceImageViewImageFormatInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT
{
    using struct_type = VkFilterCubicImageViewImageFormatPropertiesEXT;

    VkFilterCubicImageViewImageFormatPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR Decoded_VkDeviceQueueGlobalPriorityCreateInfoEXT;

struct Decoded_VkImportMemoryHostPointerInfoEXT
{
    using struct_type = VkImportMemoryHostPointerInfoEXT;

    VkImportMemoryHostPointerInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pHostPointer{ 0 };
};

struct Decoded_VkMemoryHostPointerPropertiesEXT
{
    using struct_type = VkMemoryHostPointerPropertiesEXT;

    VkMemoryHostPointerPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT
{
    using struct_type = VkPhysicalDeviceExternalMemoryHostPropertiesEXT;

    VkPhysicalDeviceExternalMemoryHostPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCompilerControlCreateInfoAMD
{
    using struct_type = VkPipelineCompilerControlCreateInfoAMD;

    VkPipelineCompilerControlCreateInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkCalibratedTimestampInfoKHR Decoded_VkCalibratedTimestampInfoEXT;

struct Decoded_VkPhysicalDeviceShaderCorePropertiesAMD
{
    using struct_type = VkPhysicalDeviceShaderCorePropertiesAMD;

    VkPhysicalDeviceShaderCorePropertiesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceMemoryOverallocationCreateInfoAMD
{
    using struct_type = VkDeviceMemoryOverallocationCreateInfoAMD;

    VkDeviceMemoryOverallocationCreateInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT
{
    using struct_type = VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT;

    VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkVertexInputBindingDivisorDescriptionKHR Decoded_VkVertexInputBindingDivisorDescriptionEXT;

typedef Decoded_VkPipelineVertexInputDivisorStateCreateInfoKHR Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT;

typedef Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesKHR Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT;

struct Decoded_VkPresentFrameTokenGGP
{
    using struct_type = VkPresentFrameTokenGGP;

    VkPresentFrameTokenGGP* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPipelineCreationFeedbackCreateInfo Decoded_VkPipelineCreationFeedbackCreateInfoEXT;

typedef Decoded_VkPipelineCreationFeedback Decoded_VkPipelineCreationFeedbackEXT;

struct Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV
{
    using struct_type = VkPhysicalDeviceComputeShaderDerivativesFeaturesNV;

    VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMeshShaderFeaturesNV
{
    using struct_type = VkPhysicalDeviceMeshShaderFeaturesNV;

    VkPhysicalDeviceMeshShaderFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMeshShaderPropertiesNV
{
    using struct_type = VkPhysicalDeviceMeshShaderPropertiesNV;

    VkPhysicalDeviceMeshShaderPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> maxTaskWorkGroupSize;
    PointerDecoder<uint32_t> maxMeshWorkGroupSize;
};

struct Decoded_VkDrawMeshTasksIndirectCommandNV
{
    using struct_type = VkDrawMeshTasksIndirectCommandNV;

    VkDrawMeshTasksIndirectCommandNV* decoded_value{ nullptr };
};

typedef Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV;

struct Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV
{
    using struct_type = VkPhysicalDeviceShaderImageFootprintFeaturesNV;

    VkPhysicalDeviceShaderImageFootprintFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV
{
    using struct_type = VkPipelineViewportExclusiveScissorStateCreateInfoNV;

    VkPipelineViewportExclusiveScissorStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pExclusiveScissors{ nullptr };
};

struct Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV
{
    using struct_type = VkPhysicalDeviceExclusiveScissorFeaturesNV;

    VkPhysicalDeviceExclusiveScissorFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueueFamilyCheckpointPropertiesNV
{
    using struct_type = VkQueueFamilyCheckpointPropertiesNV;

    VkQueueFamilyCheckpointPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCheckpointDataNV
{
    using struct_type = VkCheckpointDataNV;

    VkCheckpointDataNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pCheckpointMarker{ 0 };
};

struct Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL
{
    using struct_type = VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL;

    VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkInitializePerformanceApiInfoINTEL
{
    using struct_type = VkInitializePerformanceApiInfoINTEL;

    VkInitializePerformanceApiInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL
{
    using struct_type = VkQueryPoolPerformanceQueryCreateInfoINTEL;

    VkQueryPoolPerformanceQueryCreateInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceMarkerInfoINTEL
{
    using struct_type = VkPerformanceMarkerInfoINTEL;

    VkPerformanceMarkerInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceStreamMarkerInfoINTEL
{
    using struct_type = VkPerformanceStreamMarkerInfoINTEL;

    VkPerformanceStreamMarkerInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceOverrideInfoINTEL
{
    using struct_type = VkPerformanceOverrideInfoINTEL;

    VkPerformanceOverrideInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPerformanceConfigurationAcquireInfoINTEL
{
    using struct_type = VkPerformanceConfigurationAcquireInfoINTEL;

    VkPerformanceConfigurationAcquireInfoINTEL* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL Decoded_VkQueryPoolCreateInfoINTEL;

struct Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT
{
    using struct_type = VkPhysicalDevicePCIBusInfoPropertiesEXT;

    VkPhysicalDevicePCIBusInfoPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD
{
    using struct_type = VkDisplayNativeHdrSurfaceCapabilitiesAMD;

    VkDisplayNativeHdrSurfaceCapabilitiesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD
{
    using struct_type = VkSwapchainDisplayNativeHdrCreateInfoAMD;

    VkSwapchainDisplayNativeHdrCreateInfoAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA
{
    using struct_type = VkImagePipeSurfaceCreateInfoFUCHSIA;

    VkImagePipeSurfaceCreateInfoFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMetalSurfaceCreateInfoEXT
{
    using struct_type = VkMetalSurfaceCreateInfoEXT;

    VkMetalSurfaceCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pLayer{ 0 };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapFeaturesEXT;

    VkPhysicalDeviceFragmentDensityMapFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapPropertiesEXT;

    VkPhysicalDeviceFragmentDensityMapPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* minFragmentDensityTexelSize{ nullptr };
    Decoded_VkExtent2D* maxFragmentDensityTexelSize{ nullptr };
};

struct Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT
{
    using struct_type = VkRenderPassFragmentDensityMapCreateInfoEXT;

    VkRenderPassFragmentDensityMapCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkAttachmentReference* fragmentDensityMapAttachment{ nullptr };
};

typedef Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures Decoded_VkPhysicalDeviceScalarBlockLayoutFeaturesEXT;

typedef Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures Decoded_VkPhysicalDeviceSubgroupSizeControlFeaturesEXT;

typedef Decoded_VkPhysicalDeviceSubgroupSizeControlProperties Decoded_VkPhysicalDeviceSubgroupSizeControlPropertiesEXT;

typedef Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT;

struct Decoded_VkPhysicalDeviceShaderCoreProperties2AMD
{
    using struct_type = VkPhysicalDeviceShaderCoreProperties2AMD;

    VkPhysicalDeviceShaderCoreProperties2AMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD
{
    using struct_type = VkPhysicalDeviceCoherentMemoryFeaturesAMD;

    VkPhysicalDeviceCoherentMemoryFeaturesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT;

    VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMemoryBudgetPropertiesEXT;

    VkPhysicalDeviceMemoryBudgetPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkDeviceSize> heapBudget;
    PointerDecoder<VkDeviceSize> heapUsage;
};

struct Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMemoryPriorityFeaturesEXT;

    VkPhysicalDeviceMemoryPriorityFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryPriorityAllocateInfoEXT
{
    using struct_type = VkMemoryPriorityAllocateInfoEXT;

    VkMemoryPriorityAllocateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV
{
    using struct_type = VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV;

    VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBufferDeviceAddressFeaturesEXT;

    VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBufferDeviceAddressCreateInfoEXT
{
    using struct_type = VkBufferDeviceAddressCreateInfoEXT;

    VkBufferDeviceAddressCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT Decoded_VkPhysicalDeviceBufferAddressFeaturesEXT;

typedef Decoded_VkBufferDeviceAddressInfo Decoded_VkBufferDeviceAddressInfoEXT;

typedef Decoded_VkPhysicalDeviceToolProperties Decoded_VkPhysicalDeviceToolPropertiesEXT;

typedef Decoded_VkImageStencilUsageCreateInfo Decoded_VkImageStencilUsageCreateInfoEXT;

struct Decoded_VkValidationFeaturesEXT
{
    using struct_type = VkValidationFeaturesEXT;

    VkValidationFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkValidationFeatureEnableEXT> pEnabledValidationFeatures;
    PointerDecoder<VkValidationFeatureDisableEXT> pDisabledValidationFeatures;
};

struct Decoded_VkCooperativeMatrixPropertiesNV
{
    using struct_type = VkCooperativeMatrixPropertiesNV;

    VkCooperativeMatrixPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixFeaturesNV;

    VkPhysicalDeviceCooperativeMatrixFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV
{
    using struct_type = VkPhysicalDeviceCooperativeMatrixPropertiesNV;

    VkPhysicalDeviceCooperativeMatrixPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV
{
    using struct_type = VkPhysicalDeviceCoverageReductionModeFeaturesNV;

    VkPhysicalDeviceCoverageReductionModeFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineCoverageReductionStateCreateInfoNV
{
    using struct_type = VkPipelineCoverageReductionStateCreateInfoNV;

    VkPipelineCoverageReductionStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFramebufferMixedSamplesCombinationNV
{
    using struct_type = VkFramebufferMixedSamplesCombinationNV;

    VkFramebufferMixedSamplesCombinationNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT;

    VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT
{
    using struct_type = VkPhysicalDeviceYcbcrImageArraysFeaturesEXT;

    VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT
{
    using struct_type = VkPhysicalDeviceProvokingVertexFeaturesEXT;

    VkPhysicalDeviceProvokingVertexFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT
{
    using struct_type = VkPhysicalDeviceProvokingVertexPropertiesEXT;

    VkPhysicalDeviceProvokingVertexPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT
{
    using struct_type = VkPipelineRasterizationProvokingVertexStateCreateInfoEXT;

    VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceFullScreenExclusiveInfoEXT
{
    using struct_type = VkSurfaceFullScreenExclusiveInfoEXT;

    VkSurfaceFullScreenExclusiveInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT
{
    using struct_type = VkSurfaceCapabilitiesFullScreenExclusiveEXT;

    VkSurfaceCapabilitiesFullScreenExclusiveEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT
{
    using struct_type = VkSurfaceFullScreenExclusiveWin32InfoEXT;

    VkSurfaceFullScreenExclusiveWin32InfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t hmonitor{ 0 };
};

struct Decoded_VkHeadlessSurfaceCreateInfoEXT
{
    using struct_type = VkHeadlessSurfaceCreateInfoEXT;

    VkHeadlessSurfaceCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceLineRasterizationFeaturesKHR Decoded_VkPhysicalDeviceLineRasterizationFeaturesEXT;

typedef Decoded_VkPhysicalDeviceLineRasterizationPropertiesKHR Decoded_VkPhysicalDeviceLineRasterizationPropertiesEXT;

typedef Decoded_VkPipelineRasterizationLineStateCreateInfoKHR Decoded_VkPipelineRasterizationLineStateCreateInfoEXT;

struct Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderAtomicFloatFeaturesEXT;

    VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceHostQueryResetFeatures Decoded_VkPhysicalDeviceHostQueryResetFeaturesEXT;

typedef Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesKHR Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesEXT;

struct Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT
{
    using struct_type = VkPhysicalDeviceExtendedDynamicStateFeaturesEXT;

    VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceHostImageCopyFeaturesEXT
{
    using struct_type = VkPhysicalDeviceHostImageCopyFeaturesEXT;

    VkPhysicalDeviceHostImageCopyFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceHostImageCopyPropertiesEXT
{
    using struct_type = VkPhysicalDeviceHostImageCopyPropertiesEXT;

    VkPhysicalDeviceHostImageCopyPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkImageLayout> pCopySrcLayouts;
    PointerDecoder<VkImageLayout> pCopyDstLayouts;
    PointerDecoder<uint8_t> optimalTilingLayoutUUID;
};

struct Decoded_VkMemoryToImageCopyEXT
{
    using struct_type = VkMemoryToImageCopyEXT;

    VkMemoryToImageCopyEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pHostPointer{ 0 };
    Decoded_VkImageSubresourceLayers* imageSubresource{ nullptr };
    Decoded_VkOffset3D* imageOffset{ nullptr };
    Decoded_VkExtent3D* imageExtent{ nullptr };
};

struct Decoded_VkImageToMemoryCopyEXT
{
    using struct_type = VkImageToMemoryCopyEXT;

    VkImageToMemoryCopyEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pHostPointer{ 0 };
    Decoded_VkImageSubresourceLayers* imageSubresource{ nullptr };
    Decoded_VkOffset3D* imageOffset{ nullptr };
    Decoded_VkExtent3D* imageExtent{ nullptr };
};

struct Decoded_VkCopyMemoryToImageInfoEXT
{
    using struct_type = VkCopyMemoryToImageInfoEXT;

    VkCopyMemoryToImageInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkMemoryToImageCopyEXT>* pRegions{ nullptr };
};

struct Decoded_VkCopyImageToMemoryInfoEXT
{
    using struct_type = VkCopyImageToMemoryInfoEXT;

    VkCopyImageToMemoryInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageToMemoryCopyEXT>* pRegions{ nullptr };
};

struct Decoded_VkCopyImageToImageInfoEXT
{
    using struct_type = VkCopyImageToImageInfoEXT;

    VkCopyImageToImageInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId srcImage{ format::kNullHandleId };
    format::HandleId dstImage{ format::kNullHandleId };
    StructPointerDecoder<Decoded_VkImageCopy2>* pRegions{ nullptr };
};

struct Decoded_VkHostImageLayoutTransitionInfoEXT
{
    using struct_type = VkHostImageLayoutTransitionInfoEXT;

    VkHostImageLayoutTransitionInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId image{ format::kNullHandleId };
    Decoded_VkImageSubresourceRange* subresourceRange{ nullptr };
};

struct Decoded_VkSubresourceHostMemcpySizeEXT
{
    using struct_type = VkSubresourceHostMemcpySizeEXT;

    VkSubresourceHostMemcpySizeEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkHostImageCopyDevicePerformanceQueryEXT
{
    using struct_type = VkHostImageCopyDevicePerformanceQueryEXT;

    VkHostImageCopyDevicePerformanceQueryEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkSubresourceLayout2KHR Decoded_VkSubresourceLayout2EXT;

typedef Decoded_VkImageSubresource2KHR Decoded_VkImageSubresource2EXT;

struct Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMapMemoryPlacedFeaturesEXT;

    VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMapMemoryPlacedPropertiesEXT;

    VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryMapPlacedInfoEXT
{
    using struct_type = VkMemoryMapPlacedInfoEXT;

    VkMemoryMapPlacedInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pPlacedAddress{ 0 };
};

struct Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT;

    VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfacePresentModeEXT
{
    using struct_type = VkSurfacePresentModeEXT;

    VkSurfacePresentModeEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfacePresentScalingCapabilitiesEXT
{
    using struct_type = VkSurfacePresentScalingCapabilitiesEXT;

    VkSurfacePresentScalingCapabilitiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* minScaledImageExtent{ nullptr };
    Decoded_VkExtent2D* maxScaledImageExtent{ nullptr };
};

struct Decoded_VkSurfacePresentModeCompatibilityEXT
{
    using struct_type = VkSurfacePresentModeCompatibilityEXT;

    VkSurfacePresentModeCompatibilityEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkPresentModeKHR> pPresentModes;
};

struct Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT
{
    using struct_type = VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT;

    VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainPresentFenceInfoEXT
{
    using struct_type = VkSwapchainPresentFenceInfoEXT;

    VkSwapchainPresentFenceInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkFence> pFences;
};

struct Decoded_VkSwapchainPresentModesCreateInfoEXT
{
    using struct_type = VkSwapchainPresentModesCreateInfoEXT;

    VkSwapchainPresentModesCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkPresentModeKHR> pPresentModes;
};

struct Decoded_VkSwapchainPresentModeInfoEXT
{
    using struct_type = VkSwapchainPresentModeInfoEXT;

    VkSwapchainPresentModeInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkPresentModeKHR> pPresentModes;
};

struct Decoded_VkSwapchainPresentScalingCreateInfoEXT
{
    using struct_type = VkSwapchainPresentScalingCreateInfoEXT;

    VkSwapchainPresentScalingCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkReleaseSwapchainImagesInfoEXT
{
    using struct_type = VkReleaseSwapchainImagesInfoEXT;

    VkReleaseSwapchainImagesInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId swapchain{ format::kNullHandleId };
    PointerDecoder<uint32_t> pImageIndices;
};

typedef Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT;

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV
{
    using struct_type = VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV;

    VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV
{
    using struct_type = VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV;

    VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkGraphicsShaderGroupCreateInfoNV
{
    using struct_type = VkGraphicsShaderGroupCreateInfoNV;

    VkGraphicsShaderGroupCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineShaderStageCreateInfo>* pStages{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineVertexInputStateCreateInfo>* pVertexInputState{ nullptr };
    StructPointerDecoder<Decoded_VkPipelineTessellationStateCreateInfo>* pTessellationState{ nullptr };
};

struct Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV
{
    using struct_type = VkGraphicsPipelineShaderGroupsCreateInfoNV;

    VkGraphicsPipelineShaderGroupsCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkGraphicsShaderGroupCreateInfoNV>* pGroups{ nullptr };
    HandlePointerDecoder<VkPipeline> pPipelines;
};

struct Decoded_VkBindShaderGroupIndirectCommandNV
{
    using struct_type = VkBindShaderGroupIndirectCommandNV;

    VkBindShaderGroupIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkBindIndexBufferIndirectCommandNV
{
    using struct_type = VkBindIndexBufferIndirectCommandNV;

    VkBindIndexBufferIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkBindVertexBufferIndirectCommandNV
{
    using struct_type = VkBindVertexBufferIndirectCommandNV;

    VkBindVertexBufferIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkSetStateFlagsIndirectCommandNV
{
    using struct_type = VkSetStateFlagsIndirectCommandNV;

    VkSetStateFlagsIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkIndirectCommandsStreamNV
{
    using struct_type = VkIndirectCommandsStreamNV;

    VkIndirectCommandsStreamNV* decoded_value{ nullptr };

    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkIndirectCommandsLayoutTokenNV
{
    using struct_type = VkIndirectCommandsLayoutTokenNV;

    VkIndirectCommandsLayoutTokenNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pushconstantPipelineLayout{ format::kNullHandleId };
    PointerDecoder<VkIndexType> pIndexTypes;
    PointerDecoder<uint32_t> pIndexTypeValues;
};

struct Decoded_VkIndirectCommandsLayoutCreateInfoNV
{
    using struct_type = VkIndirectCommandsLayoutCreateInfoNV;

    VkIndirectCommandsLayoutCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkIndirectCommandsLayoutTokenNV>* pTokens{ nullptr };
    PointerDecoder<uint32_t> pStreamStrides;
};

struct Decoded_VkGeneratedCommandsInfoNV
{
    using struct_type = VkGeneratedCommandsInfoNV;

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

    VkGeneratedCommandsMemoryRequirementsInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
    format::HandleId indirectCommandsLayout{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV
{
    using struct_type = VkPhysicalDeviceInheritedViewportScissorFeaturesNV;

    VkPhysicalDeviceInheritedViewportScissorFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCommandBufferInheritanceViewportScissorInfoNV
{
    using struct_type = VkCommandBufferInheritanceViewportScissorInfoNV;

    VkCommandBufferInheritanceViewportScissorInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkViewport>* pViewportDepths{ nullptr };
};

struct Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT
{
    using struct_type = VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT;

    VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties Decoded_VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT;

struct Decoded_VkRenderPassTransformBeginInfoQCOM
{
    using struct_type = VkRenderPassTransformBeginInfoQCOM;

    VkRenderPassTransformBeginInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM
{
    using struct_type = VkCommandBufferInheritanceRenderPassTransformInfoQCOM;

    VkCommandBufferInheritanceRenderPassTransformInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkRect2D* renderArea{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDepthBiasControlFeaturesEXT;

    VkPhysicalDeviceDepthBiasControlFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDepthBiasInfoEXT
{
    using struct_type = VkDepthBiasInfoEXT;

    VkDepthBiasInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDepthBiasRepresentationInfoEXT
{
    using struct_type = VkDepthBiasRepresentationInfoEXT;

    VkDepthBiasRepresentationInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDeviceMemoryReportFeaturesEXT;

    VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceMemoryReportCallbackDataEXT
{
    using struct_type = VkDeviceMemoryReportCallbackDataEXT;

    VkDeviceMemoryReportCallbackDataEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT
{
    using struct_type = VkDeviceDeviceMemoryReportCreateInfoEXT;

    VkDeviceDeviceMemoryReportCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pfnUserCallback{ 0 };
    uint64_t pUserData{ 0 };
};

struct Decoded_VkPhysicalDeviceRobustness2FeaturesEXT
{
    using struct_type = VkPhysicalDeviceRobustness2FeaturesEXT;

    VkPhysicalDeviceRobustness2FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRobustness2PropertiesEXT
{
    using struct_type = VkPhysicalDeviceRobustness2PropertiesEXT;

    VkPhysicalDeviceRobustness2PropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerCustomBorderColorCreateInfoEXT
{
    using struct_type = VkSamplerCustomBorderColorCreateInfoEXT;

    VkSamplerCustomBorderColorCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkClearColorValue* customBorderColor{ nullptr };
};

struct Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT
{
    using struct_type = VkPhysicalDeviceCustomBorderColorPropertiesEXT;

    VkPhysicalDeviceCustomBorderColorPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT
{
    using struct_type = VkPhysicalDeviceCustomBorderColorFeaturesEXT;

    VkPhysicalDeviceCustomBorderColorFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePresentBarrierFeaturesNV
{
    using struct_type = VkPhysicalDevicePresentBarrierFeaturesNV;

    VkPhysicalDevicePresentBarrierFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSurfaceCapabilitiesPresentBarrierNV
{
    using struct_type = VkSurfaceCapabilitiesPresentBarrierNV;

    VkSurfaceCapabilitiesPresentBarrierNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainPresentBarrierCreateInfoNV
{
    using struct_type = VkSwapchainPresentBarrierCreateInfoNV;

    VkSwapchainPresentBarrierCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDevicePrivateDataFeatures Decoded_VkPhysicalDevicePrivateDataFeaturesEXT;

typedef Decoded_VkDevicePrivateDataCreateInfo Decoded_VkDevicePrivateDataCreateInfoEXT;

typedef Decoded_VkPrivateDataSlotCreateInfo Decoded_VkPrivateDataSlotCreateInfoEXT;

typedef Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures Decoded_VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT;

struct Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV
{
    using struct_type = VkPhysicalDeviceDiagnosticsConfigFeaturesNV;

    VkPhysicalDeviceDiagnosticsConfigFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceDiagnosticsConfigCreateInfoNV
{
    using struct_type = VkDeviceDiagnosticsConfigCreateInfoNV;

    VkDeviceDiagnosticsConfigCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkQueryLowLatencySupportNV
{
    using struct_type = VkQueryLowLatencySupportNV;

    VkQueryLowLatencySupportNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pQueriedLowLatencyData{ 0 };
};

struct Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT
{
    using struct_type = VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT;

    VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT
{
    using struct_type = VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT;

    VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkGraphicsPipelineLibraryCreateInfoEXT
{
    using struct_type = VkGraphicsPipelineLibraryCreateInfoEXT;

    VkGraphicsPipelineLibraryCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD
{
    using struct_type = VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD;

    VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV
{
    using struct_type = VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV;

    VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV
{
    using struct_type = VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV;

    VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV
{
    using struct_type = VkPipelineFragmentShadingRateEnumStateCreateInfoNV;

    VkPipelineFragmentShadingRateEnumStateCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkFragmentShadingRateCombinerOpKHR> combinerOps;
};

struct Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV
{
    using struct_type = VkAccelerationStructureGeometryMotionTrianglesDataNV;

    VkAccelerationStructureGeometryMotionTrianglesDataNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* vertexData{ nullptr };
};

struct Decoded_VkAccelerationStructureMotionInfoNV
{
    using struct_type = VkAccelerationStructureMotionInfoNV;

    VkAccelerationStructureMotionInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureMatrixMotionInstanceNV
{
    using struct_type = VkAccelerationStructureMatrixMotionInstanceNV;

    VkAccelerationStructureMatrixMotionInstanceNV* decoded_value{ nullptr };

    Decoded_VkTransformMatrixKHR* transformT0{ nullptr };
    Decoded_VkTransformMatrixKHR* transformT1{ nullptr };
};

struct Decoded_VkSRTDataNV
{
    using struct_type = VkSRTDataNV;

    VkSRTDataNV* decoded_value{ nullptr };
};

struct Decoded_VkAccelerationStructureSRTMotionInstanceNV
{
    using struct_type = VkAccelerationStructureSRTMotionInstanceNV;

    VkAccelerationStructureSRTMotionInstanceNV* decoded_value{ nullptr };

    Decoded_VkSRTDataNV* transformT0{ nullptr };
    Decoded_VkSRTDataNV* transformT1{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV
{
    using struct_type = VkPhysicalDeviceRayTracingMotionBlurFeaturesNV;

    VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT
{
    using struct_type = VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT;

    VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMap2FeaturesEXT;

    VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT
{
    using struct_type = VkPhysicalDeviceFragmentDensityMap2PropertiesEXT;

    VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkCopyCommandTransformInfoQCOM
{
    using struct_type = VkCopyCommandTransformInfoQCOM;

    VkCopyCommandTransformInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceImageRobustnessFeatures Decoded_VkPhysicalDeviceImageRobustnessFeaturesEXT;

struct Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImageCompressionControlFeaturesEXT;

    VkPhysicalDeviceImageCompressionControlFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageCompressionControlEXT
{
    using struct_type = VkImageCompressionControlEXT;

    VkImageCompressionControlEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkImageCompressionFixedRateFlagsEXT> pFixedRateFlags;
};

struct Decoded_VkImageCompressionPropertiesEXT
{
    using struct_type = VkImageCompressionPropertiesEXT;

    VkImageCompressionPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT
{
    using struct_type = VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT;

    VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevice4444FormatsFeaturesEXT
{
    using struct_type = VkPhysicalDevice4444FormatsFeaturesEXT;

    VkPhysicalDevice4444FormatsFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFaultFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFaultFeaturesEXT;

    VkPhysicalDeviceFaultFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceFaultCountsEXT
{
    using struct_type = VkDeviceFaultCountsEXT;

    VkDeviceFaultCountsEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceFaultAddressInfoEXT
{
    using struct_type = VkDeviceFaultAddressInfoEXT;

    VkDeviceFaultAddressInfoEXT* decoded_value{ nullptr };
};

struct Decoded_VkDeviceFaultVendorInfoEXT
{
    using struct_type = VkDeviceFaultVendorInfoEXT;

    VkDeviceFaultVendorInfoEXT* decoded_value{ nullptr };

    StringDecoder description;
};

struct Decoded_VkDeviceFaultInfoEXT
{
    using struct_type = VkDeviceFaultInfoEXT;

    VkDeviceFaultInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StringDecoder description;
    StructPointerDecoder<Decoded_VkDeviceFaultAddressInfoEXT>* pAddressInfos{ nullptr };
    StructPointerDecoder<Decoded_VkDeviceFaultVendorInfoEXT>* pVendorInfos{ nullptr };
    uint64_t pVendorBinaryData{ 0 };
};

struct Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneEXT
{
    using struct_type = VkDeviceFaultVendorBinaryHeaderVersionOneEXT;

    VkDeviceFaultVendorBinaryHeaderVersionOneEXT* decoded_value{ nullptr };

    PointerDecoder<uint8_t> pipelineCacheUUID;
};

struct Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT
{
    using struct_type = VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT;

    VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesARM;

struct Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT
{
    using struct_type = VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT;

    VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDirectFBSurfaceCreateInfoEXT
{
    using struct_type = VkDirectFBSurfaceCreateInfoEXT;

    VkDirectFBSurfaceCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t dfb{ 0 };
    uint64_t surface{ 0 };
};

struct Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT;

    VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMutableDescriptorTypeListEXT
{
    using struct_type = VkMutableDescriptorTypeListEXT;

    VkMutableDescriptorTypeListEXT* decoded_value{ nullptr };

    PointerDecoder<VkDescriptorType> pDescriptorTypes;
};

struct Decoded_VkMutableDescriptorTypeCreateInfoEXT
{
    using struct_type = VkMutableDescriptorTypeCreateInfoEXT;

    VkMutableDescriptorTypeCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkMutableDescriptorTypeListEXT>* pMutableDescriptorTypeLists{ nullptr };
};

typedef Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE;

typedef Decoded_VkMutableDescriptorTypeListEXT Decoded_VkMutableDescriptorTypeListVALVE;

typedef Decoded_VkMutableDescriptorTypeCreateInfoEXT Decoded_VkMutableDescriptorTypeCreateInfoVALVE;

struct Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT
{
    using struct_type = VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT;

    VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVertexInputBindingDescription2EXT
{
    using struct_type = VkVertexInputBindingDescription2EXT;

    VkVertexInputBindingDescription2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkVertexInputAttributeDescription2EXT
{
    using struct_type = VkVertexInputAttributeDescription2EXT;

    VkVertexInputAttributeDescription2EXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDrmPropertiesEXT
{
    using struct_type = VkPhysicalDeviceDrmPropertiesEXT;

    VkPhysicalDeviceDrmPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT
{
    using struct_type = VkPhysicalDeviceAddressBindingReportFeaturesEXT;

    VkPhysicalDeviceAddressBindingReportFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceAddressBindingCallbackDataEXT
{
    using struct_type = VkDeviceAddressBindingCallbackDataEXT;

    VkDeviceAddressBindingCallbackDataEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDepthClipControlFeaturesEXT;

    VkPhysicalDeviceDepthClipControlFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT
{
    using struct_type = VkPipelineViewportDepthClipControlCreateInfoEXT;

    VkPipelineViewportDepthClipControlCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT
{
    using struct_type = VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT;

    VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImportMemoryZirconHandleInfoFUCHSIA
{
    using struct_type = VkImportMemoryZirconHandleInfoFUCHSIA;

    VkImportMemoryZirconHandleInfoFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryZirconHandlePropertiesFUCHSIA
{
    using struct_type = VkMemoryZirconHandlePropertiesFUCHSIA;

    VkMemoryZirconHandlePropertiesFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryGetZirconHandleInfoFUCHSIA
{
    using struct_type = VkMemoryGetZirconHandleInfoFUCHSIA;

    VkMemoryGetZirconHandleInfoFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA
{
    using struct_type = VkImportSemaphoreZirconHandleInfoFUCHSIA;

    VkImportSemaphoreZirconHandleInfoFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA
{
    using struct_type = VkSemaphoreGetZirconHandleInfoFUCHSIA;

    VkSemaphoreGetZirconHandleInfoFUCHSIA* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId semaphore{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI
{
    using struct_type = VkPhysicalDeviceInvocationMaskFeaturesHUAWEI;

    VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMemoryGetRemoteAddressInfoNV
{
    using struct_type = VkMemoryGetRemoteAddressInfoNV;

    VkMemoryGetRemoteAddressInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId memory{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV
{
    using struct_type = VkPhysicalDeviceExternalMemoryRDMAFeaturesNV;

    VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT
{
    using struct_type = VkPhysicalDeviceFrameBoundaryFeaturesEXT;

    VkPhysicalDeviceFrameBoundaryFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkFrameBoundaryEXT
{
    using struct_type = VkFrameBoundaryEXT;

    VkFrameBoundaryEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkImage> pImages;
    HandlePointerDecoder<VkBuffer> pBuffers;
    PointerDecoder<uint8_t> pTag;
};

struct Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT;

    VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSubpassResolvePerformanceQueryEXT
{
    using struct_type = VkSubpassResolvePerformanceQueryEXT;

    VkSubpassResolvePerformanceQueryEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMultisampledRenderToSingleSampledInfoEXT
{
    using struct_type = VkMultisampledRenderToSingleSampledInfoEXT;

    VkMultisampledRenderToSingleSampledInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT
{
    using struct_type = VkPhysicalDeviceExtendedDynamicState2FeaturesEXT;

    VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkScreenSurfaceCreateInfoQNX
{
    using struct_type = VkScreenSurfaceCreateInfoQNX;

    VkScreenSurfaceCreateInfoQNX* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t context{ 0 };
    uint64_t window{ 0 };
};

struct Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT
{
    using struct_type = VkPhysicalDeviceColorWriteEnableFeaturesEXT;

    VkPhysicalDeviceColorWriteEnableFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineColorWriteCreateInfoEXT
{
    using struct_type = VkPipelineColorWriteCreateInfoEXT;

    VkPipelineColorWriteCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkBool32> pColorWriteEnables;
};

struct Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT
{
    using struct_type = VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT;

    VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

typedef Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT;

typedef Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR Decoded_VkQueueFamilyGlobalPriorityPropertiesEXT;

struct Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImageViewMinLodFeaturesEXT;

    VkPhysicalDeviceImageViewMinLodFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageViewMinLodCreateInfoEXT
{
    using struct_type = VkImageViewMinLodCreateInfoEXT;

    VkImageViewMinLodCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMultiDrawFeaturesEXT;

    VkPhysicalDeviceMultiDrawFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMultiDrawPropertiesEXT;

    VkPhysicalDeviceMultiDrawPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMultiDrawInfoEXT
{
    using struct_type = VkMultiDrawInfoEXT;

    VkMultiDrawInfoEXT* decoded_value{ nullptr };
};

struct Decoded_VkMultiDrawIndexedInfoEXT
{
    using struct_type = VkMultiDrawIndexedInfoEXT;

    VkMultiDrawIndexedInfoEXT* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImage2DViewOf3DFeaturesEXT;

    VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderTileImageFeaturesEXT;

    VkPhysicalDeviceShaderTileImageFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT
{
    using struct_type = VkPhysicalDeviceShaderTileImagePropertiesEXT;

    VkPhysicalDeviceShaderTileImagePropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMicromapUsageEXT
{
    using struct_type = VkMicromapUsageEXT;

    VkMicromapUsageEXT* decoded_value{ nullptr };
};

struct Decoded_VkMicromapBuildInfoEXT
{
    using struct_type = VkMicromapBuildInfoEXT;

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

    VkMicromapCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT
{
    using struct_type = VkPhysicalDeviceOpacityMicromapFeaturesEXT;

    VkPhysicalDeviceOpacityMicromapFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT
{
    using struct_type = VkPhysicalDeviceOpacityMicromapPropertiesEXT;

    VkPhysicalDeviceOpacityMicromapPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMicromapVersionInfoEXT
{
    using struct_type = VkMicromapVersionInfoEXT;

    VkMicromapVersionInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pVersionData;
};

struct Decoded_VkCopyMicromapToMemoryInfoEXT
{
    using struct_type = VkCopyMicromapToMemoryInfoEXT;

    VkCopyMicromapToMemoryInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId src{ format::kNullHandleId };
    Decoded_VkDeviceOrHostAddressKHR* dst{ nullptr };
};

struct Decoded_VkCopyMemoryToMicromapInfoEXT
{
    using struct_type = VkCopyMemoryToMicromapInfoEXT;

    VkCopyMemoryToMicromapInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* src{ nullptr };
    format::HandleId dst{ format::kNullHandleId };
};

struct Decoded_VkCopyMicromapInfoEXT
{
    using struct_type = VkCopyMicromapInfoEXT;

    VkCopyMicromapInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId src{ format::kNullHandleId };
    format::HandleId dst{ format::kNullHandleId };
};

struct Decoded_VkMicromapBuildSizesInfoEXT
{
    using struct_type = VkMicromapBuildSizesInfoEXT;

    VkMicromapBuildSizesInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT
{
    using struct_type = VkAccelerationStructureTrianglesOpacityMicromapEXT;

    VkAccelerationStructureTrianglesOpacityMicromapEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* indexBuffer{ nullptr };
    StructPointerDecoder<Decoded_VkMicromapUsageEXT>* pUsageCounts{ nullptr };
    StructPointerDecoder<Decoded_VkMicromapUsageEXT*>* ppUsageCounts{ nullptr };
    format::HandleId micromap{ format::kNullHandleId };
};

struct Decoded_VkMicromapTriangleEXT
{
    using struct_type = VkMicromapTriangleEXT;

    VkMicromapTriangleEXT* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV
{
    using struct_type = VkPhysicalDeviceDisplacementMicromapFeaturesNV;

    VkPhysicalDeviceDisplacementMicromapFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV
{
    using struct_type = VkPhysicalDeviceDisplacementMicromapPropertiesNV;

    VkPhysicalDeviceDisplacementMicromapPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV
{
    using struct_type = VkAccelerationStructureTrianglesDisplacementMicromapNV;

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

    VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI
{
    using struct_type = VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI;

    VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint32_t> maxWorkGroupCount;
    PointerDecoder<uint32_t> maxWorkGroupSize;
};

struct Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI
{
    using struct_type = VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI;

    VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT
{
    using struct_type = VkPhysicalDeviceBorderColorSwizzleFeaturesEXT;

    VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT
{
    using struct_type = VkSamplerBorderColorComponentMappingCreateInfoEXT;

    VkSamplerBorderColorComponentMappingCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkComponentMapping* components{ nullptr };
};

struct Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT
{
    using struct_type = VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT;

    VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderCorePropertiesARM
{
    using struct_type = VkPhysicalDeviceShaderCorePropertiesARM;

    VkPhysicalDeviceShaderCorePropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM
{
    using struct_type = VkDeviceQueueShaderCoreControlCreateInfoARM;

    VkDeviceQueueShaderCoreControlCreateInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM
{
    using struct_type = VkPhysicalDeviceSchedulingControlsFeaturesARM;

    VkPhysicalDeviceSchedulingControlsFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM
{
    using struct_type = VkPhysicalDeviceSchedulingControlsPropertiesARM;

    VkPhysicalDeviceSchedulingControlsPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT;

    VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageViewSlicedCreateInfoEXT
{
    using struct_type = VkImageViewSlicedCreateInfoEXT;

    VkImageViewSlicedCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE
{
    using struct_type = VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE;

    VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkDescriptorSetBindingReferenceVALVE
{
    using struct_type = VkDescriptorSetBindingReferenceVALVE;

    VkDescriptorSetBindingReferenceVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId descriptorSetLayout{ format::kNullHandleId };
};

struct Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE
{
    using struct_type = VkDescriptorSetLayoutHostMappingInfoVALVE;

    VkDescriptorSetLayoutHostMappingInfoVALVE* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDepthClampZeroOneFeaturesEXT;

    VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT
{
    using struct_type = VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT;

    VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM
{
    using struct_type = VkPhysicalDeviceRenderPassStripedFeaturesARM;

    VkPhysicalDeviceRenderPassStripedFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM
{
    using struct_type = VkPhysicalDeviceRenderPassStripedPropertiesARM;

    VkPhysicalDeviceRenderPassStripedPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* renderPassStripeGranularity{ nullptr };
};

struct Decoded_VkRenderPassStripeInfoARM
{
    using struct_type = VkRenderPassStripeInfoARM;

    VkRenderPassStripeInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkRect2D* stripeArea{ nullptr };
};

struct Decoded_VkRenderPassStripeBeginInfoARM
{
    using struct_type = VkRenderPassStripeBeginInfoARM;

    VkRenderPassStripeBeginInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRenderPassStripeInfoARM>* pStripeInfos{ nullptr };
};

struct Decoded_VkRenderPassStripeSubmitInfoARM
{
    using struct_type = VkRenderPassStripeSubmitInfoARM;

    VkRenderPassStripeSubmitInfoARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkSemaphoreSubmitInfo>* pStripeSemaphoreInfos{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM;

    VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM
{
    using struct_type = VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM;

    VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* fragmentDensityOffsetGranularity{ nullptr };
};

struct Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM
{
    using struct_type = VkSubpassFragmentDensityMapOffsetEndInfoQCOM;

    VkSubpassFragmentDensityMapOffsetEndInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkOffset2D>* pFragmentDensityOffsets{ nullptr };
};

struct Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV
{
    using struct_type = VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV;

    VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkComputePipelineIndirectBufferInfoNV
{
    using struct_type = VkComputePipelineIndirectBufferInfoNV;

    VkComputePipelineIndirectBufferInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPipelineIndirectDeviceAddressInfoNV
{
    using struct_type = VkPipelineIndirectDeviceAddressInfoNV;

    VkPipelineIndirectDeviceAddressInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId pipeline{ format::kNullHandleId };
};

struct Decoded_VkBindPipelineIndirectCommandNV
{
    using struct_type = VkBindPipelineIndirectCommandNV;

    VkBindPipelineIndirectCommandNV* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV
{
    using struct_type = VkPhysicalDeviceLinearColorAttachmentFeaturesNV;

    VkPhysicalDeviceLinearColorAttachmentFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT
{
    using struct_type = VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT;

    VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkImageViewSampleWeightCreateInfoQCOM
{
    using struct_type = VkImageViewSampleWeightCreateInfoQCOM;

    VkImageViewSampleWeightCreateInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkOffset2D* filterCenter{ nullptr };
    Decoded_VkExtent2D* filterSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceImageProcessingFeaturesQCOM;

    VkPhysicalDeviceImageProcessingFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM
{
    using struct_type = VkPhysicalDeviceImageProcessingPropertiesQCOM;

    VkPhysicalDeviceImageProcessingPropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* maxWeightFilterDimension{ nullptr };
    Decoded_VkExtent2D* maxBlockMatchRegion{ nullptr };
    Decoded_VkExtent2D* maxBoxFilterBlockSize{ nullptr };
};

struct Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT
{
    using struct_type = VkPhysicalDeviceNestedCommandBufferFeaturesEXT;

    VkPhysicalDeviceNestedCommandBufferFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT
{
    using struct_type = VkPhysicalDeviceNestedCommandBufferPropertiesEXT;

    VkPhysicalDeviceNestedCommandBufferPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkExternalMemoryAcquireUnmodifiedEXT
{
    using struct_type = VkExternalMemoryAcquireUnmodifiedEXT;

    VkExternalMemoryAcquireUnmodifiedEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT
{
    using struct_type = VkPhysicalDeviceExtendedDynamicState3FeaturesEXT;

    VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT
{
    using struct_type = VkPhysicalDeviceExtendedDynamicState3PropertiesEXT;

    VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkColorBlendEquationEXT
{
    using struct_type = VkColorBlendEquationEXT;

    VkColorBlendEquationEXT* decoded_value{ nullptr };
};

struct Decoded_VkColorBlendAdvancedEXT
{
    using struct_type = VkColorBlendAdvancedEXT;

    VkColorBlendAdvancedEXT* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT
{
    using struct_type = VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT;

    VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderPassCreationControlEXT
{
    using struct_type = VkRenderPassCreationControlEXT;

    VkRenderPassCreationControlEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRenderPassCreationFeedbackInfoEXT
{
    using struct_type = VkRenderPassCreationFeedbackInfoEXT;

    VkRenderPassCreationFeedbackInfoEXT* decoded_value{ nullptr };
};

struct Decoded_VkRenderPassCreationFeedbackCreateInfoEXT
{
    using struct_type = VkRenderPassCreationFeedbackCreateInfoEXT;

    VkRenderPassCreationFeedbackCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRenderPassCreationFeedbackInfoEXT>* pRenderPassFeedback{ nullptr };
};

struct Decoded_VkRenderPassSubpassFeedbackInfoEXT
{
    using struct_type = VkRenderPassSubpassFeedbackInfoEXT;

    VkRenderPassSubpassFeedbackInfoEXT* decoded_value{ nullptr };

    StringDecoder description;
};

struct Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT
{
    using struct_type = VkRenderPassSubpassFeedbackCreateInfoEXT;

    VkRenderPassSubpassFeedbackCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRenderPassSubpassFeedbackInfoEXT>* pSubpassFeedback{ nullptr };
};

struct Decoded_VkDirectDriverLoadingInfoLUNARG
{
    using struct_type = VkDirectDriverLoadingInfoLUNARG;

    VkDirectDriverLoadingInfoLUNARG* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pfnGetInstanceProcAddr{ 0 };
};

struct Decoded_VkDirectDriverLoadingListLUNARG
{
    using struct_type = VkDirectDriverLoadingListLUNARG;

    VkDirectDriverLoadingListLUNARG* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkDirectDriverLoadingInfoLUNARG>* pDrivers{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT;

    VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT
{
    using struct_type = VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT;

    VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> shaderModuleIdentifierAlgorithmUUID;
};

struct Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT
{
    using struct_type = VkPipelineShaderStageModuleIdentifierCreateInfoEXT;

    VkPipelineShaderStageModuleIdentifierCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pIdentifier;
};

struct Decoded_VkShaderModuleIdentifierEXT
{
    using struct_type = VkShaderModuleIdentifierEXT;

    VkShaderModuleIdentifierEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> identifier;
};

struct Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV
{
    using struct_type = VkPhysicalDeviceOpticalFlowFeaturesNV;

    VkPhysicalDeviceOpticalFlowFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV
{
    using struct_type = VkPhysicalDeviceOpticalFlowPropertiesNV;

    VkPhysicalDeviceOpticalFlowPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkOpticalFlowImageFormatInfoNV
{
    using struct_type = VkOpticalFlowImageFormatInfoNV;

    VkOpticalFlowImageFormatInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkOpticalFlowImageFormatPropertiesNV
{
    using struct_type = VkOpticalFlowImageFormatPropertiesNV;

    VkOpticalFlowImageFormatPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkOpticalFlowSessionCreateInfoNV
{
    using struct_type = VkOpticalFlowSessionCreateInfoNV;

    VkOpticalFlowSessionCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV
{
    using struct_type = VkOpticalFlowSessionCreatePrivateDataInfoNV;

    VkOpticalFlowSessionCreatePrivateDataInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pPrivateData{ 0 };
};

struct Decoded_VkOpticalFlowExecuteInfoNV
{
    using struct_type = VkOpticalFlowExecuteInfoNV;

    VkOpticalFlowExecuteInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pRegions{ nullptr };
};

struct Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT
{
    using struct_type = VkPhysicalDeviceLegacyDitheringFeaturesEXT;

    VkPhysicalDeviceLegacyDitheringFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT
{
    using struct_type = VkPhysicalDevicePipelineProtectedAccessFeaturesEXT;

    VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID
{
    using struct_type = VkPhysicalDeviceExternalFormatResolveFeaturesANDROID;

    VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID
{
    using struct_type = VkPhysicalDeviceExternalFormatResolvePropertiesANDROID;

    VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID
{
    using struct_type = VkAndroidHardwareBufferFormatResolvePropertiesANDROID;

    VkAndroidHardwareBufferFormatResolvePropertiesANDROID* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT
{
    using struct_type = VkPhysicalDeviceShaderObjectFeaturesEXT;

    VkPhysicalDeviceShaderObjectFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT
{
    using struct_type = VkPhysicalDeviceShaderObjectPropertiesEXT;

    VkPhysicalDeviceShaderObjectPropertiesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> shaderBinaryUUID;
};

struct Decoded_VkShaderCreateInfoEXT
{
    using struct_type = VkShaderCreateInfoEXT;

    VkShaderCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pCode;
    StringDecoder pName;
    HandlePointerDecoder<VkDescriptorSetLayout> pSetLayouts;
    StructPointerDecoder<Decoded_VkPushConstantRange>* pPushConstantRanges{ nullptr };
    StructPointerDecoder<Decoded_VkSpecializationInfo>* pSpecializationInfo{ nullptr };
};

typedef Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo Decoded_VkShaderRequiredSubgroupSizeCreateInfoEXT;

struct Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceTilePropertiesFeaturesQCOM;

    VkPhysicalDeviceTilePropertiesFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkTilePropertiesQCOM
{
    using struct_type = VkTilePropertiesQCOM;

    VkTilePropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent3D* tileSize{ nullptr };
    Decoded_VkExtent2D* apronSize{ nullptr };
    Decoded_VkOffset2D* origin{ nullptr };
};

struct Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC
{
    using struct_type = VkPhysicalDeviceAmigoProfilingFeaturesSEC;

    VkPhysicalDeviceAmigoProfilingFeaturesSEC* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAmigoProfilingSubmitInfoSEC
{
    using struct_type = VkAmigoProfilingSubmitInfoSEC;

    VkAmigoProfilingSubmitInfoSEC* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM;

    VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV
{
    using struct_type = VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV;

    VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV
{
    using struct_type = VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV;

    VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV
{
    using struct_type = VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV;

    VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV
{
    using struct_type = VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV;

    VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkLayerSettingEXT
{
    using struct_type = VkLayerSettingEXT;

    VkLayerSettingEXT* decoded_value{ nullptr };

    StringDecoder pLayerName;
    StringDecoder pSettingName;
    PointerDecoder<uint8_t> pValues;
};

struct Decoded_VkLayerSettingsCreateInfoEXT
{
    using struct_type = VkLayerSettingsCreateInfoEXT;

    VkLayerSettingsCreateInfoEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkLayerSettingEXT>* pSettings{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM
{
    using struct_type = VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM;

    VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM
{
    using struct_type = VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM;

    VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT
{
    using struct_type = VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT;

    VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT
{
    using struct_type = VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT;

    VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkLatencySleepModeInfoNV
{
    using struct_type = VkLatencySleepModeInfoNV;

    VkLatencySleepModeInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkLatencySleepInfoNV
{
    using struct_type = VkLatencySleepInfoNV;

    VkLatencySleepInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId signalSemaphore{ format::kNullHandleId };
};

struct Decoded_VkSetLatencyMarkerInfoNV
{
    using struct_type = VkSetLatencyMarkerInfoNV;

    VkSetLatencyMarkerInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkLatencyTimingsFrameReportNV
{
    using struct_type = VkLatencyTimingsFrameReportNV;

    VkLatencyTimingsFrameReportNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkGetLatencyMarkerInfoNV
{
    using struct_type = VkGetLatencyMarkerInfoNV;

    VkGetLatencyMarkerInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkLatencyTimingsFrameReportNV>* pTimings{ nullptr };
};

struct Decoded_VkLatencySubmissionPresentIdNV
{
    using struct_type = VkLatencySubmissionPresentIdNV;

    VkLatencySubmissionPresentIdNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSwapchainLatencyCreateInfoNV
{
    using struct_type = VkSwapchainLatencyCreateInfoNV;

    VkSwapchainLatencyCreateInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkOutOfBandQueueTypeInfoNV
{
    using struct_type = VkOutOfBandQueueTypeInfoNV;

    VkOutOfBandQueueTypeInfoNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkLatencySurfaceCapabilitiesNV
{
    using struct_type = VkLatencySurfaceCapabilitiesNV;

    VkLatencySurfaceCapabilitiesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<VkPresentModeKHR> pPresentModes;
};

struct Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM;

    VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM
{
    using struct_type = VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM;

    VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    StructPointerDecoder<Decoded_VkRect2D>* pPerViewRenderAreas{ nullptr };
};

struct Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV
{
    using struct_type = VkPhysicalDevicePerStageDescriptorSetFeaturesNV;

    VkPhysicalDevicePerStageDescriptorSetFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM
{
    using struct_type = VkPhysicalDeviceImageProcessing2FeaturesQCOM;

    VkPhysicalDeviceImageProcessing2FeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM
{
    using struct_type = VkPhysicalDeviceImageProcessing2PropertiesQCOM;

    VkPhysicalDeviceImageProcessing2PropertiesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* maxBlockMatchWindow{ nullptr };
};

struct Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM
{
    using struct_type = VkSamplerBlockMatchWindowCreateInfoQCOM;

    VkSamplerBlockMatchWindowCreateInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkExtent2D* windowExtent{ nullptr };
};

struct Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceCubicWeightsFeaturesQCOM;

    VkPhysicalDeviceCubicWeightsFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerCubicWeightsCreateInfoQCOM
{
    using struct_type = VkSamplerCubicWeightsCreateInfoQCOM;

    VkSamplerCubicWeightsCreateInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkBlitImageCubicWeightsInfoQCOM
{
    using struct_type = VkBlitImageCubicWeightsInfoQCOM;

    VkBlitImageCubicWeightsInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceYcbcrDegammaFeaturesQCOM;

    VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM
{
    using struct_type = VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM;

    VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM
{
    using struct_type = VkPhysicalDeviceCubicClampFeaturesQCOM;

    VkPhysicalDeviceCubicClampFeaturesQCOM* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT
{
    using struct_type = VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT;

    VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT
{
    using struct_type = VkPhysicalDeviceLayeredDriverPropertiesMSFT;

    VkPhysicalDeviceLayeredDriverPropertiesMSFT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV
{
    using struct_type = VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV;

    VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV
{
    using struct_type = VkPhysicalDeviceRawAccessChainsFeaturesNV;

    VkPhysicalDeviceRawAccessChainsFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV
{
    using struct_type = VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV;

    VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV
{
    using struct_type = VkPhysicalDeviceRayTracingValidationFeaturesNV;

    VkPhysicalDeviceRayTracingValidationFeaturesNV* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureBuildRangeInfoKHR
{
    using struct_type = VkAccelerationStructureBuildRangeInfoKHR;

    VkAccelerationStructureBuildRangeInfoKHR* decoded_value{ nullptr };
};

struct Decoded_VkAccelerationStructureGeometryTrianglesDataKHR
{
    using struct_type = VkAccelerationStructureGeometryTrianglesDataKHR;

    VkAccelerationStructureGeometryTrianglesDataKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* vertexData{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* indexData{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* transformData{ nullptr };
};

struct Decoded_VkAccelerationStructureGeometryAabbsDataKHR
{
    using struct_type = VkAccelerationStructureGeometryAabbsDataKHR;

    VkAccelerationStructureGeometryAabbsDataKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* data{ nullptr };
};

struct Decoded_VkAccelerationStructureGeometryInstancesDataKHR
{
    using struct_type = VkAccelerationStructureGeometryInstancesDataKHR;

    VkAccelerationStructureGeometryInstancesDataKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* data{ nullptr };
};

struct Decoded_VkAccelerationStructureBuildGeometryInfoKHR
{
    using struct_type = VkAccelerationStructureBuildGeometryInfoKHR;

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

    VkAccelerationStructureCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId buffer{ format::kNullHandleId };
};

struct Decoded_VkWriteDescriptorSetAccelerationStructureKHR
{
    using struct_type = VkWriteDescriptorSetAccelerationStructureKHR;

    VkWriteDescriptorSetAccelerationStructureKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    HandlePointerDecoder<VkAccelerationStructureKHR> pAccelerationStructures;
};

struct Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR
{
    using struct_type = VkPhysicalDeviceAccelerationStructureFeaturesKHR;

    VkPhysicalDeviceAccelerationStructureFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR
{
    using struct_type = VkPhysicalDeviceAccelerationStructurePropertiesKHR;

    VkPhysicalDeviceAccelerationStructurePropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkAccelerationStructureDeviceAddressInfoKHR
{
    using struct_type = VkAccelerationStructureDeviceAddressInfoKHR;

    VkAccelerationStructureDeviceAddressInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId accelerationStructure{ format::kNullHandleId };
};

struct Decoded_VkAccelerationStructureVersionInfoKHR
{
    using struct_type = VkAccelerationStructureVersionInfoKHR;

    VkAccelerationStructureVersionInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    PointerDecoder<uint8_t> pVersionData;
};

struct Decoded_VkCopyAccelerationStructureToMemoryInfoKHR
{
    using struct_type = VkCopyAccelerationStructureToMemoryInfoKHR;

    VkCopyAccelerationStructureToMemoryInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId src{ format::kNullHandleId };
    Decoded_VkDeviceOrHostAddressKHR* dst{ nullptr };
};

struct Decoded_VkCopyMemoryToAccelerationStructureInfoKHR
{
    using struct_type = VkCopyMemoryToAccelerationStructureInfoKHR;

    VkCopyMemoryToAccelerationStructureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    Decoded_VkDeviceOrHostAddressConstKHR* src{ nullptr };
    format::HandleId dst{ format::kNullHandleId };
};

struct Decoded_VkCopyAccelerationStructureInfoKHR
{
    using struct_type = VkCopyAccelerationStructureInfoKHR;

    VkCopyAccelerationStructureInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    format::HandleId src{ format::kNullHandleId };
    format::HandleId dst{ format::kNullHandleId };
};

struct Decoded_VkAccelerationStructureBuildSizesInfoKHR
{
    using struct_type = VkAccelerationStructureBuildSizesInfoKHR;

    VkAccelerationStructureBuildSizesInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRayTracingShaderGroupCreateInfoKHR
{
    using struct_type = VkRayTracingShaderGroupCreateInfoKHR;

    VkRayTracingShaderGroupCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
    uint64_t pShaderGroupCaptureReplayHandle{ 0 };
};

struct Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR
{
    using struct_type = VkRayTracingPipelineInterfaceCreateInfoKHR;

    VkRayTracingPipelineInterfaceCreateInfoKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkRayTracingPipelineCreateInfoKHR
{
    using struct_type = VkRayTracingPipelineCreateInfoKHR;

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

    VkPhysicalDeviceRayTracingPipelineFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR
{
    using struct_type = VkPhysicalDeviceRayTracingPipelinePropertiesKHR;

    VkPhysicalDeviceRayTracingPipelinePropertiesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkStridedDeviceAddressRegionKHR
{
    using struct_type = VkStridedDeviceAddressRegionKHR;

    VkStridedDeviceAddressRegionKHR* decoded_value{ nullptr };
};

struct Decoded_VkTraceRaysIndirectCommandKHR
{
    using struct_type = VkTraceRaysIndirectCommandKHR;

    VkTraceRaysIndirectCommandKHR* decoded_value{ nullptr };
};

struct Decoded_VkPhysicalDeviceRayQueryFeaturesKHR
{
    using struct_type = VkPhysicalDeviceRayQueryFeaturesKHR;

    VkPhysicalDeviceRayQueryFeaturesKHR* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT
{
    using struct_type = VkPhysicalDeviceMeshShaderFeaturesEXT;

    VkPhysicalDeviceMeshShaderFeaturesEXT* decoded_value{ nullptr };

    PNextNode* pNext{ nullptr };
};

struct Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT
{
    using struct_type = VkPhysicalDeviceMeshShaderPropertiesEXT;

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

    VkDrawMeshTasksIndirectCommandEXT* decoded_value{ nullptr };
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif
