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

#include "generated_vulkan_enum_to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(util)
template <> std::string ToString<StdVideoAV1ChromaSamplePosition>(const StdVideoAV1ChromaSamplePosition& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_UNKNOWN: return "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_UNKNOWN";
    case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_VERTICAL: return "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_VERTICAL";
    case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_COLOCATED: return "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_COLOCATED";
    case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_RESERVED: return "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_RESERVED";
    case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_INVALID: return "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1ChromaSamplePosition";
}

template <> std::string ToString<StdVideoAV1ColorPrimaries>(const StdVideoAV1ColorPrimaries& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_709: return "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_709";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_UNSPECIFIED: return "STD_VIDEO_AV1_COLOR_PRIMARIES_UNSPECIFIED";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_M: return "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_M";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_B_G: return "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_B_G";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_601: return "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_601";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_240: return "STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_240";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_GENERIC_FILM: return "STD_VIDEO_AV1_COLOR_PRIMARIES_GENERIC_FILM";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_2020: return "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_2020";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_XYZ: return "STD_VIDEO_AV1_COLOR_PRIMARIES_XYZ";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_431: return "STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_431";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_432: return "STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_432";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_EBU_3213: return "STD_VIDEO_AV1_COLOR_PRIMARIES_EBU_3213";
    case STD_VIDEO_AV1_COLOR_PRIMARIES_INVALID: return "STD_VIDEO_AV1_COLOR_PRIMARIES_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1ColorPrimaries";
}

template <> std::string ToString<StdVideoAV1FrameRestorationType>(const StdVideoAV1FrameRestorationType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_NONE: return "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_NONE";
    case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_WIENER: return "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_WIENER";
    case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SGRPROJ: return "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SGRPROJ";
    case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SWITCHABLE: return "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SWITCHABLE";
    case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_INVALID: return "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1FrameRestorationType";
}

template <> std::string ToString<StdVideoAV1FrameType>(const StdVideoAV1FrameType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_FRAME_TYPE_KEY: return "STD_VIDEO_AV1_FRAME_TYPE_KEY";
    case STD_VIDEO_AV1_FRAME_TYPE_INTER: return "STD_VIDEO_AV1_FRAME_TYPE_INTER";
    case STD_VIDEO_AV1_FRAME_TYPE_INTRA_ONLY: return "STD_VIDEO_AV1_FRAME_TYPE_INTRA_ONLY";
    case STD_VIDEO_AV1_FRAME_TYPE_SWITCH: return "STD_VIDEO_AV1_FRAME_TYPE_SWITCH";
    case STD_VIDEO_AV1_FRAME_TYPE_INVALID: return "STD_VIDEO_AV1_FRAME_TYPE_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1FrameType";
}

template <> std::string ToString<StdVideoAV1InterpolationFilter>(const StdVideoAV1InterpolationFilter& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP";
    case STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SMOOTH: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SMOOTH";
    case STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SHARP: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SHARP";
    case STD_VIDEO_AV1_INTERPOLATION_FILTER_BILINEAR: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_BILINEAR";
    case STD_VIDEO_AV1_INTERPOLATION_FILTER_SWITCHABLE: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_SWITCHABLE";
    case STD_VIDEO_AV1_INTERPOLATION_FILTER_INVALID: return "STD_VIDEO_AV1_INTERPOLATION_FILTER_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1InterpolationFilter";
}

template <> std::string ToString<StdVideoAV1Level>(const StdVideoAV1Level& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_LEVEL_2_0: return "STD_VIDEO_AV1_LEVEL_2_0";
    case STD_VIDEO_AV1_LEVEL_2_1: return "STD_VIDEO_AV1_LEVEL_2_1";
    case STD_VIDEO_AV1_LEVEL_2_2: return "STD_VIDEO_AV1_LEVEL_2_2";
    case STD_VIDEO_AV1_LEVEL_2_3: return "STD_VIDEO_AV1_LEVEL_2_3";
    case STD_VIDEO_AV1_LEVEL_3_0: return "STD_VIDEO_AV1_LEVEL_3_0";
    case STD_VIDEO_AV1_LEVEL_3_1: return "STD_VIDEO_AV1_LEVEL_3_1";
    case STD_VIDEO_AV1_LEVEL_3_2: return "STD_VIDEO_AV1_LEVEL_3_2";
    case STD_VIDEO_AV1_LEVEL_3_3: return "STD_VIDEO_AV1_LEVEL_3_3";
    case STD_VIDEO_AV1_LEVEL_4_0: return "STD_VIDEO_AV1_LEVEL_4_0";
    case STD_VIDEO_AV1_LEVEL_4_1: return "STD_VIDEO_AV1_LEVEL_4_1";
    case STD_VIDEO_AV1_LEVEL_4_2: return "STD_VIDEO_AV1_LEVEL_4_2";
    case STD_VIDEO_AV1_LEVEL_4_3: return "STD_VIDEO_AV1_LEVEL_4_3";
    case STD_VIDEO_AV1_LEVEL_5_0: return "STD_VIDEO_AV1_LEVEL_5_0";
    case STD_VIDEO_AV1_LEVEL_5_1: return "STD_VIDEO_AV1_LEVEL_5_1";
    case STD_VIDEO_AV1_LEVEL_5_2: return "STD_VIDEO_AV1_LEVEL_5_2";
    case STD_VIDEO_AV1_LEVEL_5_3: return "STD_VIDEO_AV1_LEVEL_5_3";
    case STD_VIDEO_AV1_LEVEL_6_0: return "STD_VIDEO_AV1_LEVEL_6_0";
    case STD_VIDEO_AV1_LEVEL_6_1: return "STD_VIDEO_AV1_LEVEL_6_1";
    case STD_VIDEO_AV1_LEVEL_6_2: return "STD_VIDEO_AV1_LEVEL_6_2";
    case STD_VIDEO_AV1_LEVEL_6_3: return "STD_VIDEO_AV1_LEVEL_6_3";
    case STD_VIDEO_AV1_LEVEL_7_0: return "STD_VIDEO_AV1_LEVEL_7_0";
    case STD_VIDEO_AV1_LEVEL_7_1: return "STD_VIDEO_AV1_LEVEL_7_1";
    case STD_VIDEO_AV1_LEVEL_7_2: return "STD_VIDEO_AV1_LEVEL_7_2";
    case STD_VIDEO_AV1_LEVEL_7_3: return "STD_VIDEO_AV1_LEVEL_7_3";
    case STD_VIDEO_AV1_LEVEL_INVALID: return "STD_VIDEO_AV1_LEVEL_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1Level";
}

template <> std::string ToString<StdVideoAV1MatrixCoefficients>(const StdVideoAV1MatrixCoefficients& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_IDENTITY: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_IDENTITY";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_709: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_709";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_UNSPECIFIED: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_UNSPECIFIED";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_RESERVED_3: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_RESERVED_3";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_FCC: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_FCC";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_470_B_G: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_470_B_G";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_601: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_601";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_240: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_240";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_YCGCO: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_YCGCO";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_NCL: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_NCL";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_CL: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_CL";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_2085: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_2085";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_NCL: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_NCL";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_CL: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_CL";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_ICTCP: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_ICTCP";
    case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_INVALID: return "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1MatrixCoefficients";
}

template <> std::string ToString<StdVideoAV1Profile>(const StdVideoAV1Profile& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_PROFILE_MAIN: return "STD_VIDEO_AV1_PROFILE_MAIN";
    case STD_VIDEO_AV1_PROFILE_HIGH: return "STD_VIDEO_AV1_PROFILE_HIGH";
    case STD_VIDEO_AV1_PROFILE_PROFESSIONAL: return "STD_VIDEO_AV1_PROFILE_PROFESSIONAL";
    case STD_VIDEO_AV1_PROFILE_INVALID: return "STD_VIDEO_AV1_PROFILE_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1Profile";
}

template <> std::string ToString<StdVideoAV1ReferenceName>(const StdVideoAV1ReferenceName& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_REFERENCE_NAME_INTRA_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_INTRA_FRAME";
    case STD_VIDEO_AV1_REFERENCE_NAME_LAST_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_LAST_FRAME";
    case STD_VIDEO_AV1_REFERENCE_NAME_LAST2_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_LAST2_FRAME";
    case STD_VIDEO_AV1_REFERENCE_NAME_LAST3_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_LAST3_FRAME";
    case STD_VIDEO_AV1_REFERENCE_NAME_GOLDEN_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_GOLDEN_FRAME";
    case STD_VIDEO_AV1_REFERENCE_NAME_BWDREF_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_BWDREF_FRAME";
    case STD_VIDEO_AV1_REFERENCE_NAME_ALTREF2_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_ALTREF2_FRAME";
    case STD_VIDEO_AV1_REFERENCE_NAME_ALTREF_FRAME: return "STD_VIDEO_AV1_REFERENCE_NAME_ALTREF_FRAME";
    case STD_VIDEO_AV1_REFERENCE_NAME_INVALID: return "STD_VIDEO_AV1_REFERENCE_NAME_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1ReferenceName";
}

template <> std::string ToString<StdVideoAV1TransferCharacteristics>(const StdVideoAV1TransferCharacteristics& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_0: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_0";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_709: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_709";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_UNSPECIFIED: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_UNSPECIFIED";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_3: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_3";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_M: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_M";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_B_G: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_B_G";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_601: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_601";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_240: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_240";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LINEAR: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LINEAR";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100_SQRT10: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100_SQRT10";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_IEC_61966: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_IEC_61966";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_1361: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_1361";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SRGB: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SRGB";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_10_BIT: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_10_BIT";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_12_BIT: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_12_BIT";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_2084: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_2084";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_428: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_428";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_HLG: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_HLG";
    case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_INVALID: return "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1TransferCharacteristics";
}

template <> std::string ToString<StdVideoAV1TxMode>(const StdVideoAV1TxMode& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_AV1_TX_MODE_ONLY_4X4: return "STD_VIDEO_AV1_TX_MODE_ONLY_4X4";
    case STD_VIDEO_AV1_TX_MODE_LARGEST: return "STD_VIDEO_AV1_TX_MODE_LARGEST";
    case STD_VIDEO_AV1_TX_MODE_SELECT: return "STD_VIDEO_AV1_TX_MODE_SELECT";
    case STD_VIDEO_AV1_TX_MODE_INVALID: return "STD_VIDEO_AV1_TX_MODE_INVALID";
    default: break;
    }
    return "Unhandled StdVideoAV1TxMode";
}

template <> std::string ToString<StdVideoDecodeH264FieldOrderCount>(const StdVideoDecodeH264FieldOrderCount& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_TOP: return "STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_TOP";
    case STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_BOTTOM: return "STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_BOTTOM";
    case STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_INVALID: return "STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_INVALID";
    default: break;
    }
    return "Unhandled StdVideoDecodeH264FieldOrderCount";
}

template <> std::string ToString<StdVideoH264AspectRatioIdc>(const StdVideoH264AspectRatioIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_UNSPECIFIED: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_UNSPECIFIED";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_SQUARE: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_SQUARE";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_12_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_12_11";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_10_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_10_11";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_16_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_16_11";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_40_33: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_40_33";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_24_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_24_11";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_20_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_20_11";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_32_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_32_11";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_80_33: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_80_33";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_18_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_18_11";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_15_11: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_15_11";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_64_33: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_64_33";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_160_99: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_160_99";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_4_3: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_4_3";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_3_2: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_3_2";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_2_1: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_2_1";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_EXTENDED_SAR: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_EXTENDED_SAR";
    case STD_VIDEO_H264_ASPECT_RATIO_IDC_INVALID: return "STD_VIDEO_H264_ASPECT_RATIO_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264AspectRatioIdc";
}

template <> std::string ToString<StdVideoH264CabacInitIdc>(const StdVideoH264CabacInitIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_CABAC_INIT_IDC_0: return "STD_VIDEO_H264_CABAC_INIT_IDC_0";
    case STD_VIDEO_H264_CABAC_INIT_IDC_1: return "STD_VIDEO_H264_CABAC_INIT_IDC_1";
    case STD_VIDEO_H264_CABAC_INIT_IDC_2: return "STD_VIDEO_H264_CABAC_INIT_IDC_2";
    case STD_VIDEO_H264_CABAC_INIT_IDC_INVALID: return "STD_VIDEO_H264_CABAC_INIT_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264CabacInitIdc";
}

template <> std::string ToString<StdVideoH264ChromaFormatIdc>(const StdVideoH264ChromaFormatIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_CHROMA_FORMAT_IDC_MONOCHROME: return "STD_VIDEO_H264_CHROMA_FORMAT_IDC_MONOCHROME";
    case STD_VIDEO_H264_CHROMA_FORMAT_IDC_420: return "STD_VIDEO_H264_CHROMA_FORMAT_IDC_420";
    case STD_VIDEO_H264_CHROMA_FORMAT_IDC_422: return "STD_VIDEO_H264_CHROMA_FORMAT_IDC_422";
    case STD_VIDEO_H264_CHROMA_FORMAT_IDC_444: return "STD_VIDEO_H264_CHROMA_FORMAT_IDC_444";
    case STD_VIDEO_H264_CHROMA_FORMAT_IDC_INVALID: return "STD_VIDEO_H264_CHROMA_FORMAT_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264ChromaFormatIdc";
}

template <> std::string ToString<StdVideoH264DisableDeblockingFilterIdc>(const StdVideoH264DisableDeblockingFilterIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_DISABLED: return "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_DISABLED";
    case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_ENABLED: return "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_ENABLED";
    case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_PARTIAL: return "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_PARTIAL";
    case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_INVALID: return "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264DisableDeblockingFilterIdc";
}

template <> std::string ToString<StdVideoH264LevelIdc>(const StdVideoH264LevelIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_LEVEL_IDC_1_0: return "STD_VIDEO_H264_LEVEL_IDC_1_0";
    case STD_VIDEO_H264_LEVEL_IDC_1_1: return "STD_VIDEO_H264_LEVEL_IDC_1_1";
    case STD_VIDEO_H264_LEVEL_IDC_1_2: return "STD_VIDEO_H264_LEVEL_IDC_1_2";
    case STD_VIDEO_H264_LEVEL_IDC_1_3: return "STD_VIDEO_H264_LEVEL_IDC_1_3";
    case STD_VIDEO_H264_LEVEL_IDC_2_0: return "STD_VIDEO_H264_LEVEL_IDC_2_0";
    case STD_VIDEO_H264_LEVEL_IDC_2_1: return "STD_VIDEO_H264_LEVEL_IDC_2_1";
    case STD_VIDEO_H264_LEVEL_IDC_2_2: return "STD_VIDEO_H264_LEVEL_IDC_2_2";
    case STD_VIDEO_H264_LEVEL_IDC_3_0: return "STD_VIDEO_H264_LEVEL_IDC_3_0";
    case STD_VIDEO_H264_LEVEL_IDC_3_1: return "STD_VIDEO_H264_LEVEL_IDC_3_1";
    case STD_VIDEO_H264_LEVEL_IDC_3_2: return "STD_VIDEO_H264_LEVEL_IDC_3_2";
    case STD_VIDEO_H264_LEVEL_IDC_4_0: return "STD_VIDEO_H264_LEVEL_IDC_4_0";
    case STD_VIDEO_H264_LEVEL_IDC_4_1: return "STD_VIDEO_H264_LEVEL_IDC_4_1";
    case STD_VIDEO_H264_LEVEL_IDC_4_2: return "STD_VIDEO_H264_LEVEL_IDC_4_2";
    case STD_VIDEO_H264_LEVEL_IDC_5_0: return "STD_VIDEO_H264_LEVEL_IDC_5_0";
    case STD_VIDEO_H264_LEVEL_IDC_5_1: return "STD_VIDEO_H264_LEVEL_IDC_5_1";
    case STD_VIDEO_H264_LEVEL_IDC_5_2: return "STD_VIDEO_H264_LEVEL_IDC_5_2";
    case STD_VIDEO_H264_LEVEL_IDC_6_0: return "STD_VIDEO_H264_LEVEL_IDC_6_0";
    case STD_VIDEO_H264_LEVEL_IDC_6_1: return "STD_VIDEO_H264_LEVEL_IDC_6_1";
    case STD_VIDEO_H264_LEVEL_IDC_6_2: return "STD_VIDEO_H264_LEVEL_IDC_6_2";
    case STD_VIDEO_H264_LEVEL_IDC_INVALID: return "STD_VIDEO_H264_LEVEL_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264LevelIdc";
}

template <> std::string ToString<StdVideoH264MemMgmtControlOp>(const StdVideoH264MemMgmtControlOp& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_END: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_END";
    case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_SHORT_TERM: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_SHORT_TERM";
    case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_LONG_TERM: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_LONG_TERM";
    case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_LONG_TERM: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_LONG_TERM";
    case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_SET_MAX_LONG_TERM_INDEX: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_SET_MAX_LONG_TERM_INDEX";
    case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_ALL: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_ALL";
    case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_CURRENT_AS_LONG_TERM: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_CURRENT_AS_LONG_TERM";
    case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_INVALID: return "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264MemMgmtControlOp";
}

template <> std::string ToString<StdVideoH264ModificationOfPicNumsIdc>(const StdVideoH264ModificationOfPicNumsIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_SUBTRACT: return "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_SUBTRACT";
    case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_ADD: return "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_ADD";
    case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_LONG_TERM: return "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_LONG_TERM";
    case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_END: return "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_END";
    case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_INVALID: return "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264ModificationOfPicNumsIdc";
}

template <> std::string ToString<StdVideoH264NonVclNaluType>(const StdVideoH264NonVclNaluType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_NON_VCL_NALU_TYPE_SPS: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_SPS";
    case STD_VIDEO_H264_NON_VCL_NALU_TYPE_PPS: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_PPS";
    case STD_VIDEO_H264_NON_VCL_NALU_TYPE_AUD: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_AUD";
    case STD_VIDEO_H264_NON_VCL_NALU_TYPE_PREFIX: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_PREFIX";
    case STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_SEQUENCE: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_SEQUENCE";
    case STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_STREAM: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_STREAM";
    case STD_VIDEO_H264_NON_VCL_NALU_TYPE_PRECODED: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_PRECODED";
    case STD_VIDEO_H264_NON_VCL_NALU_TYPE_INVALID: return "STD_VIDEO_H264_NON_VCL_NALU_TYPE_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264NonVclNaluType";
}

template <> std::string ToString<StdVideoH264PictureType>(const StdVideoH264PictureType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_PICTURE_TYPE_P: return "STD_VIDEO_H264_PICTURE_TYPE_P";
    case STD_VIDEO_H264_PICTURE_TYPE_B: return "STD_VIDEO_H264_PICTURE_TYPE_B";
    case STD_VIDEO_H264_PICTURE_TYPE_I: return "STD_VIDEO_H264_PICTURE_TYPE_I";
    case STD_VIDEO_H264_PICTURE_TYPE_IDR: return "STD_VIDEO_H264_PICTURE_TYPE_IDR";
    case STD_VIDEO_H264_PICTURE_TYPE_INVALID: return "STD_VIDEO_H264_PICTURE_TYPE_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264PictureType";
}

template <> std::string ToString<StdVideoH264PocType>(const StdVideoH264PocType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_POC_TYPE_0: return "STD_VIDEO_H264_POC_TYPE_0";
    case STD_VIDEO_H264_POC_TYPE_1: return "STD_VIDEO_H264_POC_TYPE_1";
    case STD_VIDEO_H264_POC_TYPE_2: return "STD_VIDEO_H264_POC_TYPE_2";
    case STD_VIDEO_H264_POC_TYPE_INVALID: return "STD_VIDEO_H264_POC_TYPE_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264PocType";
}

template <> std::string ToString<StdVideoH264ProfileIdc>(const StdVideoH264ProfileIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_PROFILE_IDC_BASELINE: return "STD_VIDEO_H264_PROFILE_IDC_BASELINE";
    case STD_VIDEO_H264_PROFILE_IDC_MAIN: return "STD_VIDEO_H264_PROFILE_IDC_MAIN";
    case STD_VIDEO_H264_PROFILE_IDC_HIGH: return "STD_VIDEO_H264_PROFILE_IDC_HIGH";
    case STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE: return "STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE";
    case STD_VIDEO_H264_PROFILE_IDC_INVALID: return "STD_VIDEO_H264_PROFILE_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264ProfileIdc";
}

template <> std::string ToString<StdVideoH264SliceType>(const StdVideoH264SliceType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_SLICE_TYPE_P: return "STD_VIDEO_H264_SLICE_TYPE_P";
    case STD_VIDEO_H264_SLICE_TYPE_B: return "STD_VIDEO_H264_SLICE_TYPE_B";
    case STD_VIDEO_H264_SLICE_TYPE_I: return "STD_VIDEO_H264_SLICE_TYPE_I";
    case STD_VIDEO_H264_SLICE_TYPE_INVALID: return "STD_VIDEO_H264_SLICE_TYPE_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264SliceType";
}

template <> std::string ToString<StdVideoH264WeightedBipredIdc>(const StdVideoH264WeightedBipredIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_DEFAULT: return "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_DEFAULT";
    case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_EXPLICIT: return "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_EXPLICIT";
    case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_IMPLICIT: return "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_IMPLICIT";
    case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_INVALID: return "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH264WeightedBipredIdc";
}

template <> std::string ToString<StdVideoH265AspectRatioIdc>(const StdVideoH265AspectRatioIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_UNSPECIFIED: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_UNSPECIFIED";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_SQUARE: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_SQUARE";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_12_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_12_11";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_10_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_10_11";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_16_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_16_11";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_40_33: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_40_33";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_24_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_24_11";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_20_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_20_11";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_32_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_32_11";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_80_33: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_80_33";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_18_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_18_11";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_15_11: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_15_11";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_64_33: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_64_33";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_160_99: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_160_99";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_4_3: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_4_3";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_3_2: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_3_2";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_2_1: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_2_1";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_EXTENDED_SAR: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_EXTENDED_SAR";
    case STD_VIDEO_H265_ASPECT_RATIO_IDC_INVALID: return "STD_VIDEO_H265_ASPECT_RATIO_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH265AspectRatioIdc";
}

template <> std::string ToString<StdVideoH265ChromaFormatIdc>(const StdVideoH265ChromaFormatIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H265_CHROMA_FORMAT_IDC_MONOCHROME: return "STD_VIDEO_H265_CHROMA_FORMAT_IDC_MONOCHROME";
    case STD_VIDEO_H265_CHROMA_FORMAT_IDC_420: return "STD_VIDEO_H265_CHROMA_FORMAT_IDC_420";
    case STD_VIDEO_H265_CHROMA_FORMAT_IDC_422: return "STD_VIDEO_H265_CHROMA_FORMAT_IDC_422";
    case STD_VIDEO_H265_CHROMA_FORMAT_IDC_444: return "STD_VIDEO_H265_CHROMA_FORMAT_IDC_444";
    case STD_VIDEO_H265_CHROMA_FORMAT_IDC_INVALID: return "STD_VIDEO_H265_CHROMA_FORMAT_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH265ChromaFormatIdc";
}

template <> std::string ToString<StdVideoH265LevelIdc>(const StdVideoH265LevelIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H265_LEVEL_IDC_1_0: return "STD_VIDEO_H265_LEVEL_IDC_1_0";
    case STD_VIDEO_H265_LEVEL_IDC_2_0: return "STD_VIDEO_H265_LEVEL_IDC_2_0";
    case STD_VIDEO_H265_LEVEL_IDC_2_1: return "STD_VIDEO_H265_LEVEL_IDC_2_1";
    case STD_VIDEO_H265_LEVEL_IDC_3_0: return "STD_VIDEO_H265_LEVEL_IDC_3_0";
    case STD_VIDEO_H265_LEVEL_IDC_3_1: return "STD_VIDEO_H265_LEVEL_IDC_3_1";
    case STD_VIDEO_H265_LEVEL_IDC_4_0: return "STD_VIDEO_H265_LEVEL_IDC_4_0";
    case STD_VIDEO_H265_LEVEL_IDC_4_1: return "STD_VIDEO_H265_LEVEL_IDC_4_1";
    case STD_VIDEO_H265_LEVEL_IDC_5_0: return "STD_VIDEO_H265_LEVEL_IDC_5_0";
    case STD_VIDEO_H265_LEVEL_IDC_5_1: return "STD_VIDEO_H265_LEVEL_IDC_5_1";
    case STD_VIDEO_H265_LEVEL_IDC_5_2: return "STD_VIDEO_H265_LEVEL_IDC_5_2";
    case STD_VIDEO_H265_LEVEL_IDC_6_0: return "STD_VIDEO_H265_LEVEL_IDC_6_0";
    case STD_VIDEO_H265_LEVEL_IDC_6_1: return "STD_VIDEO_H265_LEVEL_IDC_6_1";
    case STD_VIDEO_H265_LEVEL_IDC_6_2: return "STD_VIDEO_H265_LEVEL_IDC_6_2";
    case STD_VIDEO_H265_LEVEL_IDC_INVALID: return "STD_VIDEO_H265_LEVEL_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH265LevelIdc";
}

template <> std::string ToString<StdVideoH265PictureType>(const StdVideoH265PictureType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H265_PICTURE_TYPE_P: return "STD_VIDEO_H265_PICTURE_TYPE_P";
    case STD_VIDEO_H265_PICTURE_TYPE_B: return "STD_VIDEO_H265_PICTURE_TYPE_B";
    case STD_VIDEO_H265_PICTURE_TYPE_I: return "STD_VIDEO_H265_PICTURE_TYPE_I";
    case STD_VIDEO_H265_PICTURE_TYPE_IDR: return "STD_VIDEO_H265_PICTURE_TYPE_IDR";
    case STD_VIDEO_H265_PICTURE_TYPE_INVALID: return "STD_VIDEO_H265_PICTURE_TYPE_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH265PictureType";
}

template <> std::string ToString<StdVideoH265ProfileIdc>(const StdVideoH265ProfileIdc& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H265_PROFILE_IDC_MAIN: return "STD_VIDEO_H265_PROFILE_IDC_MAIN";
    case STD_VIDEO_H265_PROFILE_IDC_MAIN_10: return "STD_VIDEO_H265_PROFILE_IDC_MAIN_10";
    case STD_VIDEO_H265_PROFILE_IDC_MAIN_STILL_PICTURE: return "STD_VIDEO_H265_PROFILE_IDC_MAIN_STILL_PICTURE";
    case STD_VIDEO_H265_PROFILE_IDC_FORMAT_RANGE_EXTENSIONS: return "STD_VIDEO_H265_PROFILE_IDC_FORMAT_RANGE_EXTENSIONS";
    case STD_VIDEO_H265_PROFILE_IDC_SCC_EXTENSIONS: return "STD_VIDEO_H265_PROFILE_IDC_SCC_EXTENSIONS";
    case STD_VIDEO_H265_PROFILE_IDC_INVALID: return "STD_VIDEO_H265_PROFILE_IDC_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH265ProfileIdc";
}

template <> std::string ToString<StdVideoH265SliceType>(const StdVideoH265SliceType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case STD_VIDEO_H265_SLICE_TYPE_B: return "STD_VIDEO_H265_SLICE_TYPE_B";
    case STD_VIDEO_H265_SLICE_TYPE_P: return "STD_VIDEO_H265_SLICE_TYPE_P";
    case STD_VIDEO_H265_SLICE_TYPE_I: return "STD_VIDEO_H265_SLICE_TYPE_I";
    case STD_VIDEO_H265_SLICE_TYPE_INVALID: return "STD_VIDEO_H265_SLICE_TYPE_INVALID";
    default: break;
    }
    return "Unhandled StdVideoH265SliceType";
}

template <> std::string ToString<VkAccessFlagBits>(const VkAccessFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_ACCESS_NONE: return "VK_ACCESS_NONE";
    default: break;
    }
    return "Unhandled VkAccessFlagBits";
}

template <> std::string ToString<VkAccessFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkAccessFlagBits>(vkFlags);
}

template <> std::string ToString<VkAttachmentDescriptionFlagBits>(const VkAttachmentDescriptionFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkAttachmentDescriptionFlagBits";
}

template <> std::string ToString<VkAttachmentDescriptionFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkAttachmentDescriptionFlagBits>(vkFlags);
}

template <> std::string ToString<VkAttachmentLoadOp>(const VkAttachmentLoadOp& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_ATTACHMENT_LOAD_OP_LOAD: return "VK_ATTACHMENT_LOAD_OP_LOAD";
    case VK_ATTACHMENT_LOAD_OP_CLEAR: return "VK_ATTACHMENT_LOAD_OP_CLEAR";
    case VK_ATTACHMENT_LOAD_OP_DONT_CARE: return "VK_ATTACHMENT_LOAD_OP_DONT_CARE";
    default: break;
    }
    return "Unhandled VkAttachmentLoadOp";
}

template <> std::string ToString<VkAttachmentStoreOp>(const VkAttachmentStoreOp& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_ATTACHMENT_STORE_OP_STORE: return "VK_ATTACHMENT_STORE_OP_STORE";
    case VK_ATTACHMENT_STORE_OP_DONT_CARE: return "VK_ATTACHMENT_STORE_OP_DONT_CARE";
    default: break;
    }
    return "Unhandled VkAttachmentStoreOp";
}

template <> std::string ToString<VkBlendFactor>(const VkBlendFactor& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_BLEND_FACTOR_ZERO: return "VK_BLEND_FACTOR_ZERO";
    case VK_BLEND_FACTOR_ONE: return "VK_BLEND_FACTOR_ONE";
    case VK_BLEND_FACTOR_SRC_COLOR: return "VK_BLEND_FACTOR_SRC_COLOR";
    case VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR: return "VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR";
    case VK_BLEND_FACTOR_DST_COLOR: return "VK_BLEND_FACTOR_DST_COLOR";
    case VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR: return "VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR";
    case VK_BLEND_FACTOR_SRC_ALPHA: return "VK_BLEND_FACTOR_SRC_ALPHA";
    case VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA: return "VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA";
    case VK_BLEND_FACTOR_DST_ALPHA: return "VK_BLEND_FACTOR_DST_ALPHA";
    case VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA: return "VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA";
    case VK_BLEND_FACTOR_CONSTANT_COLOR: return "VK_BLEND_FACTOR_CONSTANT_COLOR";
    case VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR: return "VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR";
    case VK_BLEND_FACTOR_CONSTANT_ALPHA: return "VK_BLEND_FACTOR_CONSTANT_ALPHA";
    case VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA: return "VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA";
    case VK_BLEND_FACTOR_SRC_ALPHA_SATURATE: return "VK_BLEND_FACTOR_SRC_ALPHA_SATURATE";
    case VK_BLEND_FACTOR_SRC1_COLOR: return "VK_BLEND_FACTOR_SRC1_COLOR";
    case VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR: return "VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR";
    case VK_BLEND_FACTOR_SRC1_ALPHA: return "VK_BLEND_FACTOR_SRC1_ALPHA";
    case VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA: return "VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA";
    default: break;
    }
    return "Unhandled VkBlendFactor";
}

template <> std::string ToString<VkBlendOp>(const VkBlendOp& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_BLEND_OP_ADD: return "VK_BLEND_OP_ADD";
    case VK_BLEND_OP_SUBTRACT: return "VK_BLEND_OP_SUBTRACT";
    case VK_BLEND_OP_REVERSE_SUBTRACT: return "VK_BLEND_OP_REVERSE_SUBTRACT";
    case VK_BLEND_OP_MIN: return "VK_BLEND_OP_MIN";
    case VK_BLEND_OP_MAX: return "VK_BLEND_OP_MAX";
    default: break;
    }
    return "Unhandled VkBlendOp";
}

template <> std::string ToString<VkBorderColor>(const VkBorderColor& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK: return "VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK";
    case VK_BORDER_COLOR_INT_TRANSPARENT_BLACK: return "VK_BORDER_COLOR_INT_TRANSPARENT_BLACK";
    case VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK: return "VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK";
    case VK_BORDER_COLOR_INT_OPAQUE_BLACK: return "VK_BORDER_COLOR_INT_OPAQUE_BLACK";
    case VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE: return "VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE";
    case VK_BORDER_COLOR_INT_OPAQUE_WHITE: return "VK_BORDER_COLOR_INT_OPAQUE_WHITE";
    default: break;
    }
    return "Unhandled VkBorderColor";
}

template <> std::string ToString<VkBufferCreateFlagBits>(const VkBufferCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkBufferCreateFlagBits";
}

template <> std::string ToString<VkBufferCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkBufferCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkBufferUsageFlagBits>(const VkBufferUsageFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkBufferUsageFlagBits";
}

template <> std::string ToString<VkBufferUsageFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkBufferUsageFlagBits>(vkFlags);
}

template <> std::string ToString<VkColorComponentFlagBits>(const VkColorComponentFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkColorComponentFlagBits";
}

template <> std::string ToString<VkColorComponentFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkColorComponentFlagBits>(vkFlags);
}

template <> std::string ToString<VkCommandBufferLevel>(const VkCommandBufferLevel& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_COMMAND_BUFFER_LEVEL_PRIMARY: return "VK_COMMAND_BUFFER_LEVEL_PRIMARY";
    case VK_COMMAND_BUFFER_LEVEL_SECONDARY: return "VK_COMMAND_BUFFER_LEVEL_SECONDARY";
    default: break;
    }
    return "Unhandled VkCommandBufferLevel";
}

template <> std::string ToString<VkCommandBufferResetFlagBits>(const VkCommandBufferResetFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkCommandBufferResetFlagBits";
}

template <> std::string ToString<VkCommandBufferResetFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkCommandBufferResetFlagBits>(vkFlags);
}

template <> std::string ToString<VkCommandBufferUsageFlagBits>(const VkCommandBufferUsageFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkCommandBufferUsageFlagBits";
}

template <> std::string ToString<VkCommandBufferUsageFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkCommandBufferUsageFlagBits>(vkFlags);
}

template <> std::string ToString<VkCommandPoolCreateFlagBits>(const VkCommandPoolCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkCommandPoolCreateFlagBits";
}

template <> std::string ToString<VkCommandPoolCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkCommandPoolCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkCommandPoolResetFlagBits>(const VkCommandPoolResetFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkCommandPoolResetFlagBits";
}

template <> std::string ToString<VkCommandPoolResetFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkCommandPoolResetFlagBits>(vkFlags);
}

template <> std::string ToString<VkCompareOp>(const VkCompareOp& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_COMPARE_OP_NEVER: return "VK_COMPARE_OP_NEVER";
    case VK_COMPARE_OP_LESS: return "VK_COMPARE_OP_LESS";
    case VK_COMPARE_OP_EQUAL: return "VK_COMPARE_OP_EQUAL";
    case VK_COMPARE_OP_LESS_OR_EQUAL: return "VK_COMPARE_OP_LESS_OR_EQUAL";
    case VK_COMPARE_OP_GREATER: return "VK_COMPARE_OP_GREATER";
    case VK_COMPARE_OP_NOT_EQUAL: return "VK_COMPARE_OP_NOT_EQUAL";
    case VK_COMPARE_OP_GREATER_OR_EQUAL: return "VK_COMPARE_OP_GREATER_OR_EQUAL";
    case VK_COMPARE_OP_ALWAYS: return "VK_COMPARE_OP_ALWAYS";
    default: break;
    }
    return "Unhandled VkCompareOp";
}

template <> std::string ToString<VkComponentSwizzle>(const VkComponentSwizzle& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_COMPONENT_SWIZZLE_IDENTITY: return "VK_COMPONENT_SWIZZLE_IDENTITY";
    case VK_COMPONENT_SWIZZLE_ZERO: return "VK_COMPONENT_SWIZZLE_ZERO";
    case VK_COMPONENT_SWIZZLE_ONE: return "VK_COMPONENT_SWIZZLE_ONE";
    case VK_COMPONENT_SWIZZLE_R: return "VK_COMPONENT_SWIZZLE_R";
    case VK_COMPONENT_SWIZZLE_G: return "VK_COMPONENT_SWIZZLE_G";
    case VK_COMPONENT_SWIZZLE_B: return "VK_COMPONENT_SWIZZLE_B";
    case VK_COMPONENT_SWIZZLE_A: return "VK_COMPONENT_SWIZZLE_A";
    default: break;
    }
    return "Unhandled VkComponentSwizzle";
}

template <> std::string ToString<VkCullModeFlagBits>(const VkCullModeFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_CULL_MODE_NONE: return "VK_CULL_MODE_NONE";
    case VK_CULL_MODE_FRONT_AND_BACK: return "VK_CULL_MODE_FRONT_AND_BACK";
    default: break;
    }
    return "Unhandled VkCullModeFlagBits";
}

template <> std::string ToString<VkCullModeFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkCullModeFlagBits>(vkFlags);
}

template <> std::string ToString<VkDependencyFlagBits>(const VkDependencyFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDependencyFlagBits";
}

template <> std::string ToString<VkDependencyFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDependencyFlagBits>(vkFlags);
}

template <> std::string ToString<VkDescriptorPoolCreateFlagBits>(const VkDescriptorPoolCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDescriptorPoolCreateFlagBits";
}

template <> std::string ToString<VkDescriptorPoolCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDescriptorPoolCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkDescriptorSetLayoutCreateFlagBits>(const VkDescriptorSetLayoutCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDescriptorSetLayoutCreateFlagBits";
}

template <> std::string ToString<VkDescriptorSetLayoutCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDescriptorSetLayoutCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkDescriptorType>(const VkDescriptorType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DESCRIPTOR_TYPE_SAMPLER: return "VK_DESCRIPTOR_TYPE_SAMPLER";
    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER: return "VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER";
    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE: return "VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE";
    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE: return "VK_DESCRIPTOR_TYPE_STORAGE_IMAGE";
    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER: return "VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER";
    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER: return "VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER";
    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER: return "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER";
    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER: return "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER";
    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC: return "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC";
    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC: return "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC";
    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT: return "VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT";
    default: break;
    }
    return "Unhandled VkDescriptorType";
}

template <> std::string ToString<VkDeviceQueueCreateFlagBits>(const VkDeviceQueueCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDeviceQueueCreateFlagBits";
}

template <> std::string ToString<VkDeviceQueueCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDeviceQueueCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkDynamicState>(const VkDynamicState& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DYNAMIC_STATE_VIEWPORT: return "VK_DYNAMIC_STATE_VIEWPORT";
    case VK_DYNAMIC_STATE_SCISSOR: return "VK_DYNAMIC_STATE_SCISSOR";
    case VK_DYNAMIC_STATE_LINE_WIDTH: return "VK_DYNAMIC_STATE_LINE_WIDTH";
    case VK_DYNAMIC_STATE_DEPTH_BIAS: return "VK_DYNAMIC_STATE_DEPTH_BIAS";
    case VK_DYNAMIC_STATE_BLEND_CONSTANTS: return "VK_DYNAMIC_STATE_BLEND_CONSTANTS";
    case VK_DYNAMIC_STATE_DEPTH_BOUNDS: return "VK_DYNAMIC_STATE_DEPTH_BOUNDS";
    case VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK: return "VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK";
    case VK_DYNAMIC_STATE_STENCIL_WRITE_MASK: return "VK_DYNAMIC_STATE_STENCIL_WRITE_MASK";
    case VK_DYNAMIC_STATE_STENCIL_REFERENCE: return "VK_DYNAMIC_STATE_STENCIL_REFERENCE";
    default: break;
    }
    return "Unhandled VkDynamicState";
}

template <> std::string ToString<VkEventCreateFlagBits>(const VkEventCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkEventCreateFlagBits";
}

template <> std::string ToString<VkEventCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkEventCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkFenceCreateFlagBits>(const VkFenceCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkFenceCreateFlagBits";
}

template <> std::string ToString<VkFenceCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkFenceCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkFilter>(const VkFilter& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_FILTER_NEAREST: return "VK_FILTER_NEAREST";
    case VK_FILTER_LINEAR: return "VK_FILTER_LINEAR";
    default: break;
    }
    return "Unhandled VkFilter";
}

template <> std::string ToString<VkFormat>(const VkFormat& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_FORMAT_UNDEFINED: return "VK_FORMAT_UNDEFINED";
    case VK_FORMAT_R4G4_UNORM_PACK8: return "VK_FORMAT_R4G4_UNORM_PACK8";
    case VK_FORMAT_R4G4B4A4_UNORM_PACK16: return "VK_FORMAT_R4G4B4A4_UNORM_PACK16";
    case VK_FORMAT_B4G4R4A4_UNORM_PACK16: return "VK_FORMAT_B4G4R4A4_UNORM_PACK16";
    case VK_FORMAT_R5G6B5_UNORM_PACK16: return "VK_FORMAT_R5G6B5_UNORM_PACK16";
    case VK_FORMAT_B5G6R5_UNORM_PACK16: return "VK_FORMAT_B5G6R5_UNORM_PACK16";
    case VK_FORMAT_R5G5B5A1_UNORM_PACK16: return "VK_FORMAT_R5G5B5A1_UNORM_PACK16";
    case VK_FORMAT_B5G5R5A1_UNORM_PACK16: return "VK_FORMAT_B5G5R5A1_UNORM_PACK16";
    case VK_FORMAT_A1R5G5B5_UNORM_PACK16: return "VK_FORMAT_A1R5G5B5_UNORM_PACK16";
    case VK_FORMAT_R8_UNORM: return "VK_FORMAT_R8_UNORM";
    case VK_FORMAT_R8_SNORM: return "VK_FORMAT_R8_SNORM";
    case VK_FORMAT_R8_USCALED: return "VK_FORMAT_R8_USCALED";
    case VK_FORMAT_R8_SSCALED: return "VK_FORMAT_R8_SSCALED";
    case VK_FORMAT_R8_UINT: return "VK_FORMAT_R8_UINT";
    case VK_FORMAT_R8_SINT: return "VK_FORMAT_R8_SINT";
    case VK_FORMAT_R8_SRGB: return "VK_FORMAT_R8_SRGB";
    case VK_FORMAT_R8G8_UNORM: return "VK_FORMAT_R8G8_UNORM";
    case VK_FORMAT_R8G8_SNORM: return "VK_FORMAT_R8G8_SNORM";
    case VK_FORMAT_R8G8_USCALED: return "VK_FORMAT_R8G8_USCALED";
    case VK_FORMAT_R8G8_SSCALED: return "VK_FORMAT_R8G8_SSCALED";
    case VK_FORMAT_R8G8_UINT: return "VK_FORMAT_R8G8_UINT";
    case VK_FORMAT_R8G8_SINT: return "VK_FORMAT_R8G8_SINT";
    case VK_FORMAT_R8G8_SRGB: return "VK_FORMAT_R8G8_SRGB";
    case VK_FORMAT_R8G8B8_UNORM: return "VK_FORMAT_R8G8B8_UNORM";
    case VK_FORMAT_R8G8B8_SNORM: return "VK_FORMAT_R8G8B8_SNORM";
    case VK_FORMAT_R8G8B8_USCALED: return "VK_FORMAT_R8G8B8_USCALED";
    case VK_FORMAT_R8G8B8_SSCALED: return "VK_FORMAT_R8G8B8_SSCALED";
    case VK_FORMAT_R8G8B8_UINT: return "VK_FORMAT_R8G8B8_UINT";
    case VK_FORMAT_R8G8B8_SINT: return "VK_FORMAT_R8G8B8_SINT";
    case VK_FORMAT_R8G8B8_SRGB: return "VK_FORMAT_R8G8B8_SRGB";
    case VK_FORMAT_B8G8R8_UNORM: return "VK_FORMAT_B8G8R8_UNORM";
    case VK_FORMAT_B8G8R8_SNORM: return "VK_FORMAT_B8G8R8_SNORM";
    case VK_FORMAT_B8G8R8_USCALED: return "VK_FORMAT_B8G8R8_USCALED";
    case VK_FORMAT_B8G8R8_SSCALED: return "VK_FORMAT_B8G8R8_SSCALED";
    case VK_FORMAT_B8G8R8_UINT: return "VK_FORMAT_B8G8R8_UINT";
    case VK_FORMAT_B8G8R8_SINT: return "VK_FORMAT_B8G8R8_SINT";
    case VK_FORMAT_B8G8R8_SRGB: return "VK_FORMAT_B8G8R8_SRGB";
    case VK_FORMAT_R8G8B8A8_UNORM: return "VK_FORMAT_R8G8B8A8_UNORM";
    case VK_FORMAT_R8G8B8A8_SNORM: return "VK_FORMAT_R8G8B8A8_SNORM";
    case VK_FORMAT_R8G8B8A8_USCALED: return "VK_FORMAT_R8G8B8A8_USCALED";
    case VK_FORMAT_R8G8B8A8_SSCALED: return "VK_FORMAT_R8G8B8A8_SSCALED";
    case VK_FORMAT_R8G8B8A8_UINT: return "VK_FORMAT_R8G8B8A8_UINT";
    case VK_FORMAT_R8G8B8A8_SINT: return "VK_FORMAT_R8G8B8A8_SINT";
    case VK_FORMAT_R8G8B8A8_SRGB: return "VK_FORMAT_R8G8B8A8_SRGB";
    case VK_FORMAT_B8G8R8A8_UNORM: return "VK_FORMAT_B8G8R8A8_UNORM";
    case VK_FORMAT_B8G8R8A8_SNORM: return "VK_FORMAT_B8G8R8A8_SNORM";
    case VK_FORMAT_B8G8R8A8_USCALED: return "VK_FORMAT_B8G8R8A8_USCALED";
    case VK_FORMAT_B8G8R8A8_SSCALED: return "VK_FORMAT_B8G8R8A8_SSCALED";
    case VK_FORMAT_B8G8R8A8_UINT: return "VK_FORMAT_B8G8R8A8_UINT";
    case VK_FORMAT_B8G8R8A8_SINT: return "VK_FORMAT_B8G8R8A8_SINT";
    case VK_FORMAT_B8G8R8A8_SRGB: return "VK_FORMAT_B8G8R8A8_SRGB";
    case VK_FORMAT_A8B8G8R8_UNORM_PACK32: return "VK_FORMAT_A8B8G8R8_UNORM_PACK32";
    case VK_FORMAT_A8B8G8R8_SNORM_PACK32: return "VK_FORMAT_A8B8G8R8_SNORM_PACK32";
    case VK_FORMAT_A8B8G8R8_USCALED_PACK32: return "VK_FORMAT_A8B8G8R8_USCALED_PACK32";
    case VK_FORMAT_A8B8G8R8_SSCALED_PACK32: return "VK_FORMAT_A8B8G8R8_SSCALED_PACK32";
    case VK_FORMAT_A8B8G8R8_UINT_PACK32: return "VK_FORMAT_A8B8G8R8_UINT_PACK32";
    case VK_FORMAT_A8B8G8R8_SINT_PACK32: return "VK_FORMAT_A8B8G8R8_SINT_PACK32";
    case VK_FORMAT_A8B8G8R8_SRGB_PACK32: return "VK_FORMAT_A8B8G8R8_SRGB_PACK32";
    case VK_FORMAT_A2R10G10B10_UNORM_PACK32: return "VK_FORMAT_A2R10G10B10_UNORM_PACK32";
    case VK_FORMAT_A2R10G10B10_SNORM_PACK32: return "VK_FORMAT_A2R10G10B10_SNORM_PACK32";
    case VK_FORMAT_A2R10G10B10_USCALED_PACK32: return "VK_FORMAT_A2R10G10B10_USCALED_PACK32";
    case VK_FORMAT_A2R10G10B10_SSCALED_PACK32: return "VK_FORMAT_A2R10G10B10_SSCALED_PACK32";
    case VK_FORMAT_A2R10G10B10_UINT_PACK32: return "VK_FORMAT_A2R10G10B10_UINT_PACK32";
    case VK_FORMAT_A2R10G10B10_SINT_PACK32: return "VK_FORMAT_A2R10G10B10_SINT_PACK32";
    case VK_FORMAT_A2B10G10R10_UNORM_PACK32: return "VK_FORMAT_A2B10G10R10_UNORM_PACK32";
    case VK_FORMAT_A2B10G10R10_SNORM_PACK32: return "VK_FORMAT_A2B10G10R10_SNORM_PACK32";
    case VK_FORMAT_A2B10G10R10_USCALED_PACK32: return "VK_FORMAT_A2B10G10R10_USCALED_PACK32";
    case VK_FORMAT_A2B10G10R10_SSCALED_PACK32: return "VK_FORMAT_A2B10G10R10_SSCALED_PACK32";
    case VK_FORMAT_A2B10G10R10_UINT_PACK32: return "VK_FORMAT_A2B10G10R10_UINT_PACK32";
    case VK_FORMAT_A2B10G10R10_SINT_PACK32: return "VK_FORMAT_A2B10G10R10_SINT_PACK32";
    case VK_FORMAT_R16_UNORM: return "VK_FORMAT_R16_UNORM";
    case VK_FORMAT_R16_SNORM: return "VK_FORMAT_R16_SNORM";
    case VK_FORMAT_R16_USCALED: return "VK_FORMAT_R16_USCALED";
    case VK_FORMAT_R16_SSCALED: return "VK_FORMAT_R16_SSCALED";
    case VK_FORMAT_R16_UINT: return "VK_FORMAT_R16_UINT";
    case VK_FORMAT_R16_SINT: return "VK_FORMAT_R16_SINT";
    case VK_FORMAT_R16_SFLOAT: return "VK_FORMAT_R16_SFLOAT";
    case VK_FORMAT_R16G16_UNORM: return "VK_FORMAT_R16G16_UNORM";
    case VK_FORMAT_R16G16_SNORM: return "VK_FORMAT_R16G16_SNORM";
    case VK_FORMAT_R16G16_USCALED: return "VK_FORMAT_R16G16_USCALED";
    case VK_FORMAT_R16G16_SSCALED: return "VK_FORMAT_R16G16_SSCALED";
    case VK_FORMAT_R16G16_UINT: return "VK_FORMAT_R16G16_UINT";
    case VK_FORMAT_R16G16_SINT: return "VK_FORMAT_R16G16_SINT";
    case VK_FORMAT_R16G16_SFLOAT: return "VK_FORMAT_R16G16_SFLOAT";
    case VK_FORMAT_R16G16B16_UNORM: return "VK_FORMAT_R16G16B16_UNORM";
    case VK_FORMAT_R16G16B16_SNORM: return "VK_FORMAT_R16G16B16_SNORM";
    case VK_FORMAT_R16G16B16_USCALED: return "VK_FORMAT_R16G16B16_USCALED";
    case VK_FORMAT_R16G16B16_SSCALED: return "VK_FORMAT_R16G16B16_SSCALED";
    case VK_FORMAT_R16G16B16_UINT: return "VK_FORMAT_R16G16B16_UINT";
    case VK_FORMAT_R16G16B16_SINT: return "VK_FORMAT_R16G16B16_SINT";
    case VK_FORMAT_R16G16B16_SFLOAT: return "VK_FORMAT_R16G16B16_SFLOAT";
    case VK_FORMAT_R16G16B16A16_UNORM: return "VK_FORMAT_R16G16B16A16_UNORM";
    case VK_FORMAT_R16G16B16A16_SNORM: return "VK_FORMAT_R16G16B16A16_SNORM";
    case VK_FORMAT_R16G16B16A16_USCALED: return "VK_FORMAT_R16G16B16A16_USCALED";
    case VK_FORMAT_R16G16B16A16_SSCALED: return "VK_FORMAT_R16G16B16A16_SSCALED";
    case VK_FORMAT_R16G16B16A16_UINT: return "VK_FORMAT_R16G16B16A16_UINT";
    case VK_FORMAT_R16G16B16A16_SINT: return "VK_FORMAT_R16G16B16A16_SINT";
    case VK_FORMAT_R16G16B16A16_SFLOAT: return "VK_FORMAT_R16G16B16A16_SFLOAT";
    case VK_FORMAT_R32_UINT: return "VK_FORMAT_R32_UINT";
    case VK_FORMAT_R32_SINT: return "VK_FORMAT_R32_SINT";
    case VK_FORMAT_R32_SFLOAT: return "VK_FORMAT_R32_SFLOAT";
    case VK_FORMAT_R32G32_UINT: return "VK_FORMAT_R32G32_UINT";
    case VK_FORMAT_R32G32_SINT: return "VK_FORMAT_R32G32_SINT";
    case VK_FORMAT_R32G32_SFLOAT: return "VK_FORMAT_R32G32_SFLOAT";
    case VK_FORMAT_R32G32B32_UINT: return "VK_FORMAT_R32G32B32_UINT";
    case VK_FORMAT_R32G32B32_SINT: return "VK_FORMAT_R32G32B32_SINT";
    case VK_FORMAT_R32G32B32_SFLOAT: return "VK_FORMAT_R32G32B32_SFLOAT";
    case VK_FORMAT_R32G32B32A32_UINT: return "VK_FORMAT_R32G32B32A32_UINT";
    case VK_FORMAT_R32G32B32A32_SINT: return "VK_FORMAT_R32G32B32A32_SINT";
    case VK_FORMAT_R32G32B32A32_SFLOAT: return "VK_FORMAT_R32G32B32A32_SFLOAT";
    case VK_FORMAT_R64_UINT: return "VK_FORMAT_R64_UINT";
    case VK_FORMAT_R64_SINT: return "VK_FORMAT_R64_SINT";
    case VK_FORMAT_R64_SFLOAT: return "VK_FORMAT_R64_SFLOAT";
    case VK_FORMAT_R64G64_UINT: return "VK_FORMAT_R64G64_UINT";
    case VK_FORMAT_R64G64_SINT: return "VK_FORMAT_R64G64_SINT";
    case VK_FORMAT_R64G64_SFLOAT: return "VK_FORMAT_R64G64_SFLOAT";
    case VK_FORMAT_R64G64B64_UINT: return "VK_FORMAT_R64G64B64_UINT";
    case VK_FORMAT_R64G64B64_SINT: return "VK_FORMAT_R64G64B64_SINT";
    case VK_FORMAT_R64G64B64_SFLOAT: return "VK_FORMAT_R64G64B64_SFLOAT";
    case VK_FORMAT_R64G64B64A64_UINT: return "VK_FORMAT_R64G64B64A64_UINT";
    case VK_FORMAT_R64G64B64A64_SINT: return "VK_FORMAT_R64G64B64A64_SINT";
    case VK_FORMAT_R64G64B64A64_SFLOAT: return "VK_FORMAT_R64G64B64A64_SFLOAT";
    case VK_FORMAT_B10G11R11_UFLOAT_PACK32: return "VK_FORMAT_B10G11R11_UFLOAT_PACK32";
    case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32: return "VK_FORMAT_E5B9G9R9_UFLOAT_PACK32";
    case VK_FORMAT_D16_UNORM: return "VK_FORMAT_D16_UNORM";
    case VK_FORMAT_X8_D24_UNORM_PACK32: return "VK_FORMAT_X8_D24_UNORM_PACK32";
    case VK_FORMAT_D32_SFLOAT: return "VK_FORMAT_D32_SFLOAT";
    case VK_FORMAT_S8_UINT: return "VK_FORMAT_S8_UINT";
    case VK_FORMAT_D16_UNORM_S8_UINT: return "VK_FORMAT_D16_UNORM_S8_UINT";
    case VK_FORMAT_D24_UNORM_S8_UINT: return "VK_FORMAT_D24_UNORM_S8_UINT";
    case VK_FORMAT_D32_SFLOAT_S8_UINT: return "VK_FORMAT_D32_SFLOAT_S8_UINT";
    case VK_FORMAT_BC1_RGB_UNORM_BLOCK: return "VK_FORMAT_BC1_RGB_UNORM_BLOCK";
    case VK_FORMAT_BC1_RGB_SRGB_BLOCK: return "VK_FORMAT_BC1_RGB_SRGB_BLOCK";
    case VK_FORMAT_BC1_RGBA_UNORM_BLOCK: return "VK_FORMAT_BC1_RGBA_UNORM_BLOCK";
    case VK_FORMAT_BC1_RGBA_SRGB_BLOCK: return "VK_FORMAT_BC1_RGBA_SRGB_BLOCK";
    case VK_FORMAT_BC2_UNORM_BLOCK: return "VK_FORMAT_BC2_UNORM_BLOCK";
    case VK_FORMAT_BC2_SRGB_BLOCK: return "VK_FORMAT_BC2_SRGB_BLOCK";
    case VK_FORMAT_BC3_UNORM_BLOCK: return "VK_FORMAT_BC3_UNORM_BLOCK";
    case VK_FORMAT_BC3_SRGB_BLOCK: return "VK_FORMAT_BC3_SRGB_BLOCK";
    case VK_FORMAT_BC4_UNORM_BLOCK: return "VK_FORMAT_BC4_UNORM_BLOCK";
    case VK_FORMAT_BC4_SNORM_BLOCK: return "VK_FORMAT_BC4_SNORM_BLOCK";
    case VK_FORMAT_BC5_UNORM_BLOCK: return "VK_FORMAT_BC5_UNORM_BLOCK";
    case VK_FORMAT_BC5_SNORM_BLOCK: return "VK_FORMAT_BC5_SNORM_BLOCK";
    case VK_FORMAT_BC6H_UFLOAT_BLOCK: return "VK_FORMAT_BC6H_UFLOAT_BLOCK";
    case VK_FORMAT_BC6H_SFLOAT_BLOCK: return "VK_FORMAT_BC6H_SFLOAT_BLOCK";
    case VK_FORMAT_BC7_UNORM_BLOCK: return "VK_FORMAT_BC7_UNORM_BLOCK";
    case VK_FORMAT_BC7_SRGB_BLOCK: return "VK_FORMAT_BC7_SRGB_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK: return "VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK: return "VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK: return "VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK: return "VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK: return "VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK";
    case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK: return "VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK";
    case VK_FORMAT_EAC_R11_UNORM_BLOCK: return "VK_FORMAT_EAC_R11_UNORM_BLOCK";
    case VK_FORMAT_EAC_R11_SNORM_BLOCK: return "VK_FORMAT_EAC_R11_SNORM_BLOCK";
    case VK_FORMAT_EAC_R11G11_UNORM_BLOCK: return "VK_FORMAT_EAC_R11G11_UNORM_BLOCK";
    case VK_FORMAT_EAC_R11G11_SNORM_BLOCK: return "VK_FORMAT_EAC_R11G11_SNORM_BLOCK";
    case VK_FORMAT_ASTC_4x4_UNORM_BLOCK: return "VK_FORMAT_ASTC_4x4_UNORM_BLOCK";
    case VK_FORMAT_ASTC_4x4_SRGB_BLOCK: return "VK_FORMAT_ASTC_4x4_SRGB_BLOCK";
    case VK_FORMAT_ASTC_5x4_UNORM_BLOCK: return "VK_FORMAT_ASTC_5x4_UNORM_BLOCK";
    case VK_FORMAT_ASTC_5x4_SRGB_BLOCK: return "VK_FORMAT_ASTC_5x4_SRGB_BLOCK";
    case VK_FORMAT_ASTC_5x5_UNORM_BLOCK: return "VK_FORMAT_ASTC_5x5_UNORM_BLOCK";
    case VK_FORMAT_ASTC_5x5_SRGB_BLOCK: return "VK_FORMAT_ASTC_5x5_SRGB_BLOCK";
    case VK_FORMAT_ASTC_6x5_UNORM_BLOCK: return "VK_FORMAT_ASTC_6x5_UNORM_BLOCK";
    case VK_FORMAT_ASTC_6x5_SRGB_BLOCK: return "VK_FORMAT_ASTC_6x5_SRGB_BLOCK";
    case VK_FORMAT_ASTC_6x6_UNORM_BLOCK: return "VK_FORMAT_ASTC_6x6_UNORM_BLOCK";
    case VK_FORMAT_ASTC_6x6_SRGB_BLOCK: return "VK_FORMAT_ASTC_6x6_SRGB_BLOCK";
    case VK_FORMAT_ASTC_8x5_UNORM_BLOCK: return "VK_FORMAT_ASTC_8x5_UNORM_BLOCK";
    case VK_FORMAT_ASTC_8x5_SRGB_BLOCK: return "VK_FORMAT_ASTC_8x5_SRGB_BLOCK";
    case VK_FORMAT_ASTC_8x6_UNORM_BLOCK: return "VK_FORMAT_ASTC_8x6_UNORM_BLOCK";
    case VK_FORMAT_ASTC_8x6_SRGB_BLOCK: return "VK_FORMAT_ASTC_8x6_SRGB_BLOCK";
    case VK_FORMAT_ASTC_8x8_UNORM_BLOCK: return "VK_FORMAT_ASTC_8x8_UNORM_BLOCK";
    case VK_FORMAT_ASTC_8x8_SRGB_BLOCK: return "VK_FORMAT_ASTC_8x8_SRGB_BLOCK";
    case VK_FORMAT_ASTC_10x5_UNORM_BLOCK: return "VK_FORMAT_ASTC_10x5_UNORM_BLOCK";
    case VK_FORMAT_ASTC_10x5_SRGB_BLOCK: return "VK_FORMAT_ASTC_10x5_SRGB_BLOCK";
    case VK_FORMAT_ASTC_10x6_UNORM_BLOCK: return "VK_FORMAT_ASTC_10x6_UNORM_BLOCK";
    case VK_FORMAT_ASTC_10x6_SRGB_BLOCK: return "VK_FORMAT_ASTC_10x6_SRGB_BLOCK";
    case VK_FORMAT_ASTC_10x8_UNORM_BLOCK: return "VK_FORMAT_ASTC_10x8_UNORM_BLOCK";
    case VK_FORMAT_ASTC_10x8_SRGB_BLOCK: return "VK_FORMAT_ASTC_10x8_SRGB_BLOCK";
    case VK_FORMAT_ASTC_10x10_UNORM_BLOCK: return "VK_FORMAT_ASTC_10x10_UNORM_BLOCK";
    case VK_FORMAT_ASTC_10x10_SRGB_BLOCK: return "VK_FORMAT_ASTC_10x10_SRGB_BLOCK";
    case VK_FORMAT_ASTC_12x10_UNORM_BLOCK: return "VK_FORMAT_ASTC_12x10_UNORM_BLOCK";
    case VK_FORMAT_ASTC_12x10_SRGB_BLOCK: return "VK_FORMAT_ASTC_12x10_SRGB_BLOCK";
    case VK_FORMAT_ASTC_12x12_UNORM_BLOCK: return "VK_FORMAT_ASTC_12x12_UNORM_BLOCK";
    case VK_FORMAT_ASTC_12x12_SRGB_BLOCK: return "VK_FORMAT_ASTC_12x12_SRGB_BLOCK";
    default: break;
    }
    return "Unhandled VkFormat";
}

template <> std::string ToString<VkFormatFeatureFlagBits>(const VkFormatFeatureFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkFormatFeatureFlagBits";
}

template <> std::string ToString<VkFormatFeatureFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkFormatFeatureFlagBits>(vkFlags);
}

template <> std::string ToString<VkFramebufferCreateFlagBits>(const VkFramebufferCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkFramebufferCreateFlagBits";
}

template <> std::string ToString<VkFramebufferCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkFramebufferCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkFrontFace>(const VkFrontFace& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_FRONT_FACE_COUNTER_CLOCKWISE: return "VK_FRONT_FACE_COUNTER_CLOCKWISE";
    case VK_FRONT_FACE_CLOCKWISE: return "VK_FRONT_FACE_CLOCKWISE";
    default: break;
    }
    return "Unhandled VkFrontFace";
}

template <> std::string ToString<VkImageAspectFlagBits>(const VkImageAspectFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_IMAGE_ASPECT_NONE: return "VK_IMAGE_ASPECT_NONE";
    default: break;
    }
    return "Unhandled VkImageAspectFlagBits";
}

template <> std::string ToString<VkImageAspectFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkImageAspectFlagBits>(vkFlags);
}

template <> std::string ToString<VkImageCreateFlagBits>(const VkImageCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkImageCreateFlagBits";
}

template <> std::string ToString<VkImageCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkImageCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkImageLayout>(const VkImageLayout& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_IMAGE_LAYOUT_UNDEFINED: return "VK_IMAGE_LAYOUT_UNDEFINED";
    case VK_IMAGE_LAYOUT_GENERAL: return "VK_IMAGE_LAYOUT_GENERAL";
    case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL: return "VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL";
    case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL: return "VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL";
    case VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL: return "VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL";
    case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL: return "VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL";
    case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL: return "VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL";
    case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL: return "VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL";
    case VK_IMAGE_LAYOUT_PREINITIALIZED: return "VK_IMAGE_LAYOUT_PREINITIALIZED";
    default: break;
    }
    return "Unhandled VkImageLayout";
}

template <> std::string ToString<VkImageTiling>(const VkImageTiling& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_IMAGE_TILING_OPTIMAL: return "VK_IMAGE_TILING_OPTIMAL";
    case VK_IMAGE_TILING_LINEAR: return "VK_IMAGE_TILING_LINEAR";
    default: break;
    }
    return "Unhandled VkImageTiling";
}

template <> std::string ToString<VkImageType>(const VkImageType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_IMAGE_TYPE_1D: return "VK_IMAGE_TYPE_1D";
    case VK_IMAGE_TYPE_2D: return "VK_IMAGE_TYPE_2D";
    case VK_IMAGE_TYPE_3D: return "VK_IMAGE_TYPE_3D";
    default: break;
    }
    return "Unhandled VkImageType";
}

template <> std::string ToString<VkImageUsageFlagBits>(const VkImageUsageFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkImageUsageFlagBits";
}

template <> std::string ToString<VkImageUsageFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkImageUsageFlagBits>(vkFlags);
}

template <> std::string ToString<VkImageViewCreateFlagBits>(const VkImageViewCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkImageViewCreateFlagBits";
}

template <> std::string ToString<VkImageViewCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkImageViewCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkImageViewType>(const VkImageViewType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_IMAGE_VIEW_TYPE_1D: return "VK_IMAGE_VIEW_TYPE_1D";
    case VK_IMAGE_VIEW_TYPE_2D: return "VK_IMAGE_VIEW_TYPE_2D";
    case VK_IMAGE_VIEW_TYPE_3D: return "VK_IMAGE_VIEW_TYPE_3D";
    case VK_IMAGE_VIEW_TYPE_CUBE: return "VK_IMAGE_VIEW_TYPE_CUBE";
    case VK_IMAGE_VIEW_TYPE_1D_ARRAY: return "VK_IMAGE_VIEW_TYPE_1D_ARRAY";
    case VK_IMAGE_VIEW_TYPE_2D_ARRAY: return "VK_IMAGE_VIEW_TYPE_2D_ARRAY";
    case VK_IMAGE_VIEW_TYPE_CUBE_ARRAY: return "VK_IMAGE_VIEW_TYPE_CUBE_ARRAY";
    default: break;
    }
    return "Unhandled VkImageViewType";
}

template <> std::string ToString<VkIndexType>(const VkIndexType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_INDEX_TYPE_UINT16: return "VK_INDEX_TYPE_UINT16";
    case VK_INDEX_TYPE_UINT32: return "VK_INDEX_TYPE_UINT32";
    default: break;
    }
    return "Unhandled VkIndexType";
}

template <> std::string ToString<VkInstanceCreateFlagBits>(const VkInstanceCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkInstanceCreateFlagBits";
}

template <> std::string ToString<VkInstanceCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkInstanceCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkInternalAllocationType>(const VkInternalAllocationType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE: return "VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE";
    default: break;
    }
    return "Unhandled VkInternalAllocationType";
}

template <> std::string ToString<VkLogicOp>(const VkLogicOp& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_LOGIC_OP_CLEAR: return "VK_LOGIC_OP_CLEAR";
    case VK_LOGIC_OP_AND: return "VK_LOGIC_OP_AND";
    case VK_LOGIC_OP_AND_REVERSE: return "VK_LOGIC_OP_AND_REVERSE";
    case VK_LOGIC_OP_COPY: return "VK_LOGIC_OP_COPY";
    case VK_LOGIC_OP_AND_INVERTED: return "VK_LOGIC_OP_AND_INVERTED";
    case VK_LOGIC_OP_NO_OP: return "VK_LOGIC_OP_NO_OP";
    case VK_LOGIC_OP_XOR: return "VK_LOGIC_OP_XOR";
    case VK_LOGIC_OP_OR: return "VK_LOGIC_OP_OR";
    case VK_LOGIC_OP_NOR: return "VK_LOGIC_OP_NOR";
    case VK_LOGIC_OP_EQUIVALENT: return "VK_LOGIC_OP_EQUIVALENT";
    case VK_LOGIC_OP_INVERT: return "VK_LOGIC_OP_INVERT";
    case VK_LOGIC_OP_OR_REVERSE: return "VK_LOGIC_OP_OR_REVERSE";
    case VK_LOGIC_OP_COPY_INVERTED: return "VK_LOGIC_OP_COPY_INVERTED";
    case VK_LOGIC_OP_OR_INVERTED: return "VK_LOGIC_OP_OR_INVERTED";
    case VK_LOGIC_OP_NAND: return "VK_LOGIC_OP_NAND";
    case VK_LOGIC_OP_SET: return "VK_LOGIC_OP_SET";
    default: break;
    }
    return "Unhandled VkLogicOp";
}

template <> std::string ToString<VkMemoryHeapFlagBits>(const VkMemoryHeapFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkMemoryHeapFlagBits";
}

template <> std::string ToString<VkMemoryHeapFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkMemoryHeapFlagBits>(vkFlags);
}

template <> std::string ToString<VkMemoryMapFlagBits>(const VkMemoryMapFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkMemoryMapFlagBits";
}

template <> std::string ToString<VkMemoryMapFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkMemoryMapFlagBits>(vkFlags);
}

template <> std::string ToString<VkMemoryPropertyFlagBits>(const VkMemoryPropertyFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkMemoryPropertyFlagBits";
}

template <> std::string ToString<VkMemoryPropertyFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkMemoryPropertyFlagBits>(vkFlags);
}

template <> std::string ToString<VkObjectType>(const VkObjectType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_OBJECT_TYPE_UNKNOWN: return "VK_OBJECT_TYPE_UNKNOWN";
    case VK_OBJECT_TYPE_INSTANCE: return "VK_OBJECT_TYPE_INSTANCE";
    case VK_OBJECT_TYPE_PHYSICAL_DEVICE: return "VK_OBJECT_TYPE_PHYSICAL_DEVICE";
    case VK_OBJECT_TYPE_DEVICE: return "VK_OBJECT_TYPE_DEVICE";
    case VK_OBJECT_TYPE_QUEUE: return "VK_OBJECT_TYPE_QUEUE";
    case VK_OBJECT_TYPE_SEMAPHORE: return "VK_OBJECT_TYPE_SEMAPHORE";
    case VK_OBJECT_TYPE_COMMAND_BUFFER: return "VK_OBJECT_TYPE_COMMAND_BUFFER";
    case VK_OBJECT_TYPE_FENCE: return "VK_OBJECT_TYPE_FENCE";
    case VK_OBJECT_TYPE_DEVICE_MEMORY: return "VK_OBJECT_TYPE_DEVICE_MEMORY";
    case VK_OBJECT_TYPE_BUFFER: return "VK_OBJECT_TYPE_BUFFER";
    case VK_OBJECT_TYPE_IMAGE: return "VK_OBJECT_TYPE_IMAGE";
    case VK_OBJECT_TYPE_EVENT: return "VK_OBJECT_TYPE_EVENT";
    case VK_OBJECT_TYPE_QUERY_POOL: return "VK_OBJECT_TYPE_QUERY_POOL";
    case VK_OBJECT_TYPE_BUFFER_VIEW: return "VK_OBJECT_TYPE_BUFFER_VIEW";
    case VK_OBJECT_TYPE_IMAGE_VIEW: return "VK_OBJECT_TYPE_IMAGE_VIEW";
    case VK_OBJECT_TYPE_SHADER_MODULE: return "VK_OBJECT_TYPE_SHADER_MODULE";
    case VK_OBJECT_TYPE_PIPELINE_CACHE: return "VK_OBJECT_TYPE_PIPELINE_CACHE";
    case VK_OBJECT_TYPE_PIPELINE_LAYOUT: return "VK_OBJECT_TYPE_PIPELINE_LAYOUT";
    case VK_OBJECT_TYPE_RENDER_PASS: return "VK_OBJECT_TYPE_RENDER_PASS";
    case VK_OBJECT_TYPE_PIPELINE: return "VK_OBJECT_TYPE_PIPELINE";
    case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT: return "VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT";
    case VK_OBJECT_TYPE_SAMPLER: return "VK_OBJECT_TYPE_SAMPLER";
    case VK_OBJECT_TYPE_DESCRIPTOR_POOL: return "VK_OBJECT_TYPE_DESCRIPTOR_POOL";
    case VK_OBJECT_TYPE_DESCRIPTOR_SET: return "VK_OBJECT_TYPE_DESCRIPTOR_SET";
    case VK_OBJECT_TYPE_FRAMEBUFFER: return "VK_OBJECT_TYPE_FRAMEBUFFER";
    case VK_OBJECT_TYPE_COMMAND_POOL: return "VK_OBJECT_TYPE_COMMAND_POOL";
    default: break;
    }
    return "Unhandled VkObjectType";
}

template <> std::string ToString<VkPhysicalDeviceType>(const VkPhysicalDeviceType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PHYSICAL_DEVICE_TYPE_OTHER: return "VK_PHYSICAL_DEVICE_TYPE_OTHER";
    case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: return "VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU";
    case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU: return "VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU";
    case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU: return "VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU";
    case VK_PHYSICAL_DEVICE_TYPE_CPU: return "VK_PHYSICAL_DEVICE_TYPE_CPU";
    default: break;
    }
    return "Unhandled VkPhysicalDeviceType";
}

template <> std::string ToString<VkPipelineBindPoint>(const VkPipelineBindPoint& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PIPELINE_BIND_POINT_GRAPHICS: return "VK_PIPELINE_BIND_POINT_GRAPHICS";
    case VK_PIPELINE_BIND_POINT_COMPUTE: return "VK_PIPELINE_BIND_POINT_COMPUTE";
    default: break;
    }
    return "Unhandled VkPipelineBindPoint";
}

template <> std::string ToString<VkPipelineCacheCreateFlagBits>(const VkPipelineCacheCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPipelineCacheCreateFlagBits";
}

template <> std::string ToString<VkPipelineCacheCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPipelineCacheCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkPipelineCacheHeaderVersion>(const VkPipelineCacheHeaderVersion& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PIPELINE_CACHE_HEADER_VERSION_ONE: return "VK_PIPELINE_CACHE_HEADER_VERSION_ONE";
    default: break;
    }
    return "Unhandled VkPipelineCacheHeaderVersion";
}

template <> std::string ToString<VkPipelineColorBlendStateCreateFlagBits>(const VkPipelineColorBlendStateCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPipelineColorBlendStateCreateFlagBits";
}

template <> std::string ToString<VkPipelineColorBlendStateCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPipelineColorBlendStateCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkPipelineCreateFlagBits>(const VkPipelineCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPipelineCreateFlagBits";
}

template <> std::string ToString<VkPipelineCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPipelineCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkPipelineDepthStencilStateCreateFlagBits>(const VkPipelineDepthStencilStateCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPipelineDepthStencilStateCreateFlagBits";
}

template <> std::string ToString<VkPipelineDepthStencilStateCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPipelineDepthStencilStateCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkPipelineLayoutCreateFlagBits>(const VkPipelineLayoutCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPipelineLayoutCreateFlagBits";
}

template <> std::string ToString<VkPipelineLayoutCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPipelineLayoutCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkPipelineShaderStageCreateFlagBits>(const VkPipelineShaderStageCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPipelineShaderStageCreateFlagBits";
}

template <> std::string ToString<VkPipelineShaderStageCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPipelineShaderStageCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkPipelineStageFlagBits>(const VkPipelineStageFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PIPELINE_STAGE_NONE: return "VK_PIPELINE_STAGE_NONE";
    default: break;
    }
    return "Unhandled VkPipelineStageFlagBits";
}

template <> std::string ToString<VkPipelineStageFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPipelineStageFlagBits>(vkFlags);
}

template <> std::string ToString<VkPolygonMode>(const VkPolygonMode& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_POLYGON_MODE_FILL: return "VK_POLYGON_MODE_FILL";
    case VK_POLYGON_MODE_LINE: return "VK_POLYGON_MODE_LINE";
    case VK_POLYGON_MODE_POINT: return "VK_POLYGON_MODE_POINT";
    default: break;
    }
    return "Unhandled VkPolygonMode";
}

template <> std::string ToString<VkPrimitiveTopology>(const VkPrimitiveTopology& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PRIMITIVE_TOPOLOGY_POINT_LIST: return "VK_PRIMITIVE_TOPOLOGY_POINT_LIST";
    case VK_PRIMITIVE_TOPOLOGY_LINE_LIST: return "VK_PRIMITIVE_TOPOLOGY_LINE_LIST";
    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP: return "VK_PRIMITIVE_TOPOLOGY_LINE_STRIP";
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST";
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP";
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN";
    case VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY: return "VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY";
    case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY: return "VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY";
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY";
    case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY: return "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY";
    case VK_PRIMITIVE_TOPOLOGY_PATCH_LIST: return "VK_PRIMITIVE_TOPOLOGY_PATCH_LIST";
    default: break;
    }
    return "Unhandled VkPrimitiveTopology";
}

template <> std::string ToString<VkQueryControlFlagBits>(const VkQueryControlFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkQueryControlFlagBits";
}

template <> std::string ToString<VkQueryControlFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkQueryControlFlagBits>(vkFlags);
}

template <> std::string ToString<VkQueryPipelineStatisticFlagBits>(const VkQueryPipelineStatisticFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkQueryPipelineStatisticFlagBits";
}

template <> std::string ToString<VkQueryPipelineStatisticFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkQueryPipelineStatisticFlagBits>(vkFlags);
}

template <> std::string ToString<VkQueryResultFlagBits>(const VkQueryResultFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkQueryResultFlagBits";
}

template <> std::string ToString<VkQueryResultFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkQueryResultFlagBits>(vkFlags);
}

template <> std::string ToString<VkQueryType>(const VkQueryType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_QUERY_TYPE_OCCLUSION: return "VK_QUERY_TYPE_OCCLUSION";
    case VK_QUERY_TYPE_PIPELINE_STATISTICS: return "VK_QUERY_TYPE_PIPELINE_STATISTICS";
    case VK_QUERY_TYPE_TIMESTAMP: return "VK_QUERY_TYPE_TIMESTAMP";
    default: break;
    }
    return "Unhandled VkQueryType";
}

template <> std::string ToString<VkQueueFlagBits>(const VkQueueFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkQueueFlagBits";
}

template <> std::string ToString<VkQueueFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkQueueFlagBits>(vkFlags);
}

template <> std::string ToString<VkRenderPassCreateFlagBits>(const VkRenderPassCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkRenderPassCreateFlagBits";
}

template <> std::string ToString<VkRenderPassCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkRenderPassCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkResult>(const VkResult& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SUCCESS: return "VK_SUCCESS";
    case VK_NOT_READY: return "VK_NOT_READY";
    case VK_TIMEOUT: return "VK_TIMEOUT";
    case VK_EVENT_SET: return "VK_EVENT_SET";
    case VK_EVENT_RESET: return "VK_EVENT_RESET";
    case VK_INCOMPLETE: return "VK_INCOMPLETE";
    case VK_ERROR_OUT_OF_HOST_MEMORY: return "VK_ERROR_OUT_OF_HOST_MEMORY";
    case VK_ERROR_OUT_OF_DEVICE_MEMORY: return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
    case VK_ERROR_INITIALIZATION_FAILED: return "VK_ERROR_INITIALIZATION_FAILED";
    case VK_ERROR_DEVICE_LOST: return "VK_ERROR_DEVICE_LOST";
    case VK_ERROR_MEMORY_MAP_FAILED: return "VK_ERROR_MEMORY_MAP_FAILED";
    case VK_ERROR_LAYER_NOT_PRESENT: return "VK_ERROR_LAYER_NOT_PRESENT";
    case VK_ERROR_EXTENSION_NOT_PRESENT: return "VK_ERROR_EXTENSION_NOT_PRESENT";
    case VK_ERROR_FEATURE_NOT_PRESENT: return "VK_ERROR_FEATURE_NOT_PRESENT";
    case VK_ERROR_INCOMPATIBLE_DRIVER: return "VK_ERROR_INCOMPATIBLE_DRIVER";
    case VK_ERROR_TOO_MANY_OBJECTS: return "VK_ERROR_TOO_MANY_OBJECTS";
    case VK_ERROR_FORMAT_NOT_SUPPORTED: return "VK_ERROR_FORMAT_NOT_SUPPORTED";
    case VK_ERROR_FRAGMENTED_POOL: return "VK_ERROR_FRAGMENTED_POOL";
    case VK_ERROR_UNKNOWN: return "VK_ERROR_UNKNOWN";
    default: break;
    }
    return "Unhandled VkResult";
}

template <> std::string ToString<VkSampleCountFlagBits>(const VkSampleCountFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSampleCountFlagBits";
}

template <> std::string ToString<VkSampleCountFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSampleCountFlagBits>(vkFlags);
}

template <> std::string ToString<VkSamplerAddressMode>(const VkSamplerAddressMode& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SAMPLER_ADDRESS_MODE_REPEAT: return "VK_SAMPLER_ADDRESS_MODE_REPEAT";
    case VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT: return "VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT";
    case VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE: return "VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE";
    case VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER: return "VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER";
    case VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE: return "VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE";
    default: break;
    }
    return "Unhandled VkSamplerAddressMode";
}

template <> std::string ToString<VkSamplerCreateFlagBits>(const VkSamplerCreateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSamplerCreateFlagBits";
}

template <> std::string ToString<VkSamplerCreateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSamplerCreateFlagBits>(vkFlags);
}

template <> std::string ToString<VkSamplerMipmapMode>(const VkSamplerMipmapMode& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SAMPLER_MIPMAP_MODE_NEAREST: return "VK_SAMPLER_MIPMAP_MODE_NEAREST";
    case VK_SAMPLER_MIPMAP_MODE_LINEAR: return "VK_SAMPLER_MIPMAP_MODE_LINEAR";
    default: break;
    }
    return "Unhandled VkSamplerMipmapMode";
}

template <> std::string ToString<VkShaderStageFlagBits>(const VkShaderStageFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SHADER_STAGE_ALL_GRAPHICS: return "VK_SHADER_STAGE_ALL_GRAPHICS";
    case VK_SHADER_STAGE_ALL: return "VK_SHADER_STAGE_ALL";
    default: break;
    }
    return "Unhandled VkShaderStageFlagBits";
}

template <> std::string ToString<VkShaderStageFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkShaderStageFlagBits>(vkFlags);
}

template <> std::string ToString<VkSharingMode>(const VkSharingMode& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SHARING_MODE_EXCLUSIVE: return "VK_SHARING_MODE_EXCLUSIVE";
    case VK_SHARING_MODE_CONCURRENT: return "VK_SHARING_MODE_CONCURRENT";
    default: break;
    }
    return "Unhandled VkSharingMode";
}

template <> std::string ToString<VkSparseImageFormatFlagBits>(const VkSparseImageFormatFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSparseImageFormatFlagBits";
}

template <> std::string ToString<VkSparseImageFormatFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSparseImageFormatFlagBits>(vkFlags);
}

template <> std::string ToString<VkSparseMemoryBindFlagBits>(const VkSparseMemoryBindFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSparseMemoryBindFlagBits";
}

template <> std::string ToString<VkSparseMemoryBindFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSparseMemoryBindFlagBits>(vkFlags);
}

template <> std::string ToString<VkStencilFaceFlagBits>(const VkStencilFaceFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_STENCIL_FACE_FRONT_AND_BACK: return "VK_STENCIL_FACE_FRONT_AND_BACK";
    default: break;
    }
    return "Unhandled VkStencilFaceFlagBits";
}

template <> std::string ToString<VkStencilFaceFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkStencilFaceFlagBits>(vkFlags);
}

template <> std::string ToString<VkStencilOp>(const VkStencilOp& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_STENCIL_OP_KEEP: return "VK_STENCIL_OP_KEEP";
    case VK_STENCIL_OP_ZERO: return "VK_STENCIL_OP_ZERO";
    case VK_STENCIL_OP_REPLACE: return "VK_STENCIL_OP_REPLACE";
    case VK_STENCIL_OP_INCREMENT_AND_CLAMP: return "VK_STENCIL_OP_INCREMENT_AND_CLAMP";
    case VK_STENCIL_OP_DECREMENT_AND_CLAMP: return "VK_STENCIL_OP_DECREMENT_AND_CLAMP";
    case VK_STENCIL_OP_INVERT: return "VK_STENCIL_OP_INVERT";
    case VK_STENCIL_OP_INCREMENT_AND_WRAP: return "VK_STENCIL_OP_INCREMENT_AND_WRAP";
    case VK_STENCIL_OP_DECREMENT_AND_WRAP: return "VK_STENCIL_OP_DECREMENT_AND_WRAP";
    default: break;
    }
    return "Unhandled VkStencilOp";
}

template <> std::string ToString<VkStructureType>(const VkStructureType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_STRUCTURE_TYPE_APPLICATION_INFO: return "VK_STRUCTURE_TYPE_APPLICATION_INFO";
    case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO: return "VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO: return "VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO: return "VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_SUBMIT_INFO: return "VK_STRUCTURE_TYPE_SUBMIT_INFO";
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO: return "VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO";
    case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE: return "VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE";
    case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO: return "VK_STRUCTURE_TYPE_BIND_SPARSE_INFO";
    case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO: return "VK_STRUCTURE_TYPE_FENCE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO: return "VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO: return "VK_STRUCTURE_TYPE_EVENT_CREATE_INFO";
    case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO: return "VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO";
    case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO: return "VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO";
    case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO: return "VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO";
    case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO: return "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO: return "VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO";
    case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO: return "VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO: return "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO: return "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: return "VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO";
    case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO: return "VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO: return "VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO";
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO: return "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO";
    case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET: return "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET";
    case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET: return "VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET";
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO: return "VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO";
    case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO: return "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO";
    case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO: return "VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO";
    case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO: return "VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO";
    case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO: return "VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO";
    case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER: return "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER";
    case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER: return "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER";
    case VK_STRUCTURE_TYPE_MEMORY_BARRIER: return "VK_STRUCTURE_TYPE_MEMORY_BARRIER";
    case VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO: return "VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO: return "VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES";
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES: return "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES";
    default: break;
    }
    return "Unhandled VkStructureType";
}

template <> std::string ToString<VkSubpassContents>(const VkSubpassContents& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SUBPASS_CONTENTS_INLINE: return "VK_SUBPASS_CONTENTS_INLINE";
    case VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS: return "VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS";
    default: break;
    }
    return "Unhandled VkSubpassContents";
}

template <> std::string ToString<VkSubpassDescriptionFlagBits>(const VkSubpassDescriptionFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSubpassDescriptionFlagBits";
}

template <> std::string ToString<VkSubpassDescriptionFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSubpassDescriptionFlagBits>(vkFlags);
}

template <> std::string ToString<VkSystemAllocationScope>(const VkSystemAllocationScope& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SYSTEM_ALLOCATION_SCOPE_COMMAND: return "VK_SYSTEM_ALLOCATION_SCOPE_COMMAND";
    case VK_SYSTEM_ALLOCATION_SCOPE_OBJECT: return "VK_SYSTEM_ALLOCATION_SCOPE_OBJECT";
    case VK_SYSTEM_ALLOCATION_SCOPE_CACHE: return "VK_SYSTEM_ALLOCATION_SCOPE_CACHE";
    case VK_SYSTEM_ALLOCATION_SCOPE_DEVICE: return "VK_SYSTEM_ALLOCATION_SCOPE_DEVICE";
    case VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE: return "VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE";
    default: break;
    }
    return "Unhandled VkSystemAllocationScope";
}

template <> std::string ToString<VkVendorId>(const VkVendorId& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VENDOR_ID_KHRONOS: return "VK_VENDOR_ID_KHRONOS";
    case VK_VENDOR_ID_VIV: return "VK_VENDOR_ID_VIV";
    case VK_VENDOR_ID_VSI: return "VK_VENDOR_ID_VSI";
    case VK_VENDOR_ID_KAZAN: return "VK_VENDOR_ID_KAZAN";
    case VK_VENDOR_ID_CODEPLAY: return "VK_VENDOR_ID_CODEPLAY";
    case VK_VENDOR_ID_MESA: return "VK_VENDOR_ID_MESA";
    case VK_VENDOR_ID_POCL: return "VK_VENDOR_ID_POCL";
    case VK_VENDOR_ID_MOBILEYE: return "VK_VENDOR_ID_MOBILEYE";
    default: break;
    }
    return "Unhandled VkVendorId";
}

template <> std::string ToString<VkVertexInputRate>(const VkVertexInputRate& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VERTEX_INPUT_RATE_VERTEX: return "VK_VERTEX_INPUT_RATE_VERTEX";
    case VK_VERTEX_INPUT_RATE_INSTANCE: return "VK_VERTEX_INPUT_RATE_INSTANCE";
    default: break;
    }
    return "Unhandled VkVertexInputRate";
}

template <> std::string ToString<VkChromaLocation>(const VkChromaLocation& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_CHROMA_LOCATION_COSITED_EVEN: return "VK_CHROMA_LOCATION_COSITED_EVEN";
    case VK_CHROMA_LOCATION_MIDPOINT: return "VK_CHROMA_LOCATION_MIDPOINT";
    default: break;
    }
    return "Unhandled VkChromaLocation";
}

template <> std::string ToString<VkDescriptorUpdateTemplateType>(const VkDescriptorUpdateTemplateType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET: return "VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET";
    case VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS: return "VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS";
    default: break;
    }
    return "Unhandled VkDescriptorUpdateTemplateType";
}

template <> std::string ToString<VkExternalFenceFeatureFlagBits>(const VkExternalFenceFeatureFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkExternalFenceFeatureFlagBits";
}

template <> std::string ToString<VkExternalFenceFeatureFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkExternalFenceFeatureFlagBits>(vkFlags);
}

template <> std::string ToString<VkExternalFenceHandleTypeFlagBits>(const VkExternalFenceHandleTypeFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkExternalFenceHandleTypeFlagBits";
}

template <> std::string ToString<VkExternalFenceHandleTypeFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkExternalFenceHandleTypeFlagBits>(vkFlags);
}

template <> std::string ToString<VkExternalMemoryFeatureFlagBits>(const VkExternalMemoryFeatureFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkExternalMemoryFeatureFlagBits";
}

template <> std::string ToString<VkExternalMemoryFeatureFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkExternalMemoryFeatureFlagBits>(vkFlags);
}

template <> std::string ToString<VkExternalMemoryHandleTypeFlagBits>(const VkExternalMemoryHandleTypeFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkExternalMemoryHandleTypeFlagBits";
}

template <> std::string ToString<VkExternalMemoryHandleTypeFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkExternalMemoryHandleTypeFlagBits>(vkFlags);
}

template <> std::string ToString<VkExternalSemaphoreFeatureFlagBits>(const VkExternalSemaphoreFeatureFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkExternalSemaphoreFeatureFlagBits";
}

template <> std::string ToString<VkExternalSemaphoreFeatureFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkExternalSemaphoreFeatureFlagBits>(vkFlags);
}

template <> std::string ToString<VkExternalSemaphoreHandleTypeFlagBits>(const VkExternalSemaphoreHandleTypeFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkExternalSemaphoreHandleTypeFlagBits";
}

template <> std::string ToString<VkExternalSemaphoreHandleTypeFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkExternalSemaphoreHandleTypeFlagBits>(vkFlags);
}

template <> std::string ToString<VkFenceImportFlagBits>(const VkFenceImportFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkFenceImportFlagBits";
}

template <> std::string ToString<VkFenceImportFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkFenceImportFlagBits>(vkFlags);
}

template <> std::string ToString<VkMemoryAllocateFlagBits>(const VkMemoryAllocateFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkMemoryAllocateFlagBits";
}

template <> std::string ToString<VkMemoryAllocateFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkMemoryAllocateFlagBits>(vkFlags);
}

template <> std::string ToString<VkPeerMemoryFeatureFlagBits>(const VkPeerMemoryFeatureFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPeerMemoryFeatureFlagBits";
}

template <> std::string ToString<VkPeerMemoryFeatureFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPeerMemoryFeatureFlagBits>(vkFlags);
}

template <> std::string ToString<VkPointClippingBehavior>(const VkPointClippingBehavior& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES: return "VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES";
    case VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY: return "VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY";
    default: break;
    }
    return "Unhandled VkPointClippingBehavior";
}

template <> std::string ToString<VkSamplerYcbcrModelConversion>(const VkSamplerYcbcrModelConversion& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY";
    case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY";
    case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709";
    case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601";
    case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020: return "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020";
    default: break;
    }
    return "Unhandled VkSamplerYcbcrModelConversion";
}

template <> std::string ToString<VkSamplerYcbcrRange>(const VkSamplerYcbcrRange& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SAMPLER_YCBCR_RANGE_ITU_FULL: return "VK_SAMPLER_YCBCR_RANGE_ITU_FULL";
    case VK_SAMPLER_YCBCR_RANGE_ITU_NARROW: return "VK_SAMPLER_YCBCR_RANGE_ITU_NARROW";
    default: break;
    }
    return "Unhandled VkSamplerYcbcrRange";
}

template <> std::string ToString<VkSemaphoreImportFlagBits>(const VkSemaphoreImportFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSemaphoreImportFlagBits";
}

template <> std::string ToString<VkSemaphoreImportFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSemaphoreImportFlagBits>(vkFlags);
}

template <> std::string ToString<VkSubgroupFeatureFlagBits>(const VkSubgroupFeatureFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSubgroupFeatureFlagBits";
}

template <> std::string ToString<VkSubgroupFeatureFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSubgroupFeatureFlagBits>(vkFlags);
}

template <> std::string ToString<VkTessellationDomainOrigin>(const VkTessellationDomainOrigin& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT: return "VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT";
    case VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT: return "VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT";
    default: break;
    }
    return "Unhandled VkTessellationDomainOrigin";
}

template <> std::string ToString<VkDescriptorBindingFlagBits>(const VkDescriptorBindingFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDescriptorBindingFlagBits";
}

template <> std::string ToString<VkDescriptorBindingFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDescriptorBindingFlagBits>(vkFlags);
}

template <> std::string ToString<VkDriverId>(const VkDriverId& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DRIVER_ID_AMD_PROPRIETARY: return "VK_DRIVER_ID_AMD_PROPRIETARY";
    case VK_DRIVER_ID_AMD_OPEN_SOURCE: return "VK_DRIVER_ID_AMD_OPEN_SOURCE";
    case VK_DRIVER_ID_MESA_RADV: return "VK_DRIVER_ID_MESA_RADV";
    case VK_DRIVER_ID_NVIDIA_PROPRIETARY: return "VK_DRIVER_ID_NVIDIA_PROPRIETARY";
    case VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS: return "VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS";
    case VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA: return "VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA";
    case VK_DRIVER_ID_IMAGINATION_PROPRIETARY: return "VK_DRIVER_ID_IMAGINATION_PROPRIETARY";
    case VK_DRIVER_ID_QUALCOMM_PROPRIETARY: return "VK_DRIVER_ID_QUALCOMM_PROPRIETARY";
    case VK_DRIVER_ID_ARM_PROPRIETARY: return "VK_DRIVER_ID_ARM_PROPRIETARY";
    case VK_DRIVER_ID_GOOGLE_SWIFTSHADER: return "VK_DRIVER_ID_GOOGLE_SWIFTSHADER";
    case VK_DRIVER_ID_GGP_PROPRIETARY: return "VK_DRIVER_ID_GGP_PROPRIETARY";
    case VK_DRIVER_ID_BROADCOM_PROPRIETARY: return "VK_DRIVER_ID_BROADCOM_PROPRIETARY";
    case VK_DRIVER_ID_MESA_LLVMPIPE: return "VK_DRIVER_ID_MESA_LLVMPIPE";
    case VK_DRIVER_ID_MOLTENVK: return "VK_DRIVER_ID_MOLTENVK";
    case VK_DRIVER_ID_COREAVI_PROPRIETARY: return "VK_DRIVER_ID_COREAVI_PROPRIETARY";
    case VK_DRIVER_ID_JUICE_PROPRIETARY: return "VK_DRIVER_ID_JUICE_PROPRIETARY";
    case VK_DRIVER_ID_VERISILICON_PROPRIETARY: return "VK_DRIVER_ID_VERISILICON_PROPRIETARY";
    case VK_DRIVER_ID_MESA_TURNIP: return "VK_DRIVER_ID_MESA_TURNIP";
    case VK_DRIVER_ID_MESA_V3DV: return "VK_DRIVER_ID_MESA_V3DV";
    case VK_DRIVER_ID_MESA_PANVK: return "VK_DRIVER_ID_MESA_PANVK";
    case VK_DRIVER_ID_SAMSUNG_PROPRIETARY: return "VK_DRIVER_ID_SAMSUNG_PROPRIETARY";
    case VK_DRIVER_ID_MESA_VENUS: return "VK_DRIVER_ID_MESA_VENUS";
    case VK_DRIVER_ID_MESA_DOZEN: return "VK_DRIVER_ID_MESA_DOZEN";
    case VK_DRIVER_ID_MESA_NVK: return "VK_DRIVER_ID_MESA_NVK";
    case VK_DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA: return "VK_DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA";
    case VK_DRIVER_ID_MESA_HONEYKRISP: return "VK_DRIVER_ID_MESA_HONEYKRISP";
    case VK_DRIVER_ID_RESERVED_27: return "VK_DRIVER_ID_RESERVED_27";
    default: break;
    }
    return "Unhandled VkDriverId";
}

template <> std::string ToString<VkResolveModeFlagBits>(const VkResolveModeFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_RESOLVE_MODE_NONE: return "VK_RESOLVE_MODE_NONE";
    default: break;
    }
    return "Unhandled VkResolveModeFlagBits";
}

template <> std::string ToString<VkResolveModeFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkResolveModeFlagBits>(vkFlags);
}

template <> std::string ToString<VkSamplerReductionMode>(const VkSamplerReductionMode& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE: return "VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE";
    case VK_SAMPLER_REDUCTION_MODE_MIN: return "VK_SAMPLER_REDUCTION_MODE_MIN";
    case VK_SAMPLER_REDUCTION_MODE_MAX: return "VK_SAMPLER_REDUCTION_MODE_MAX";
    default: break;
    }
    return "Unhandled VkSamplerReductionMode";
}

template <> std::string ToString<VkSemaphoreType>(const VkSemaphoreType& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SEMAPHORE_TYPE_BINARY: return "VK_SEMAPHORE_TYPE_BINARY";
    case VK_SEMAPHORE_TYPE_TIMELINE: return "VK_SEMAPHORE_TYPE_TIMELINE";
    default: break;
    }
    return "Unhandled VkSemaphoreType";
}

template <> std::string ToString<VkSemaphoreWaitFlagBits>(const VkSemaphoreWaitFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSemaphoreWaitFlagBits";
}

template <> std::string ToString<VkSemaphoreWaitFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSemaphoreWaitFlagBits>(vkFlags);
}

template <> std::string ToString<VkShaderFloatControlsIndependence>(const VkShaderFloatControlsIndependence& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY: return "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY";
    case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL: return "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL";
    case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE: return "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE";
    default: break;
    }
    return "Unhandled VkShaderFloatControlsIndependence";
}

std::string VkAccessFlagBits2ToString(const VkAccessFlagBits2 value)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkAccessFlagBits2";
}

std::string VkAccessFlags2ToString(VkFlags64 vkFlags)
{
    std::string   str;
    VkFlags64     index = 0U;
    while (vkFlags)
    {
        if (vkFlags & 1U)
        {
            if (!str.empty())
            {
                str += '|';
            }
            str.append(VkAccessFlagBits2ToString(static_cast<VkAccessFlagBits2>(1U) << index));
        }
        ++index;
        vkFlags >>= 1U;
    }
    if (str.empty())
    {
        str.append(VkAccessFlagBits2ToString(0U));
    }
    return str;
}

std::string VkFormatFeatureFlagBits2ToString(const VkFormatFeatureFlagBits2 value)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkFormatFeatureFlagBits2";
}

std::string VkFormatFeatureFlags2ToString(VkFlags64 vkFlags)
{
    std::string   str;
    VkFlags64     index = 0U;
    while (vkFlags)
    {
        if (vkFlags & 1U)
        {
            if (!str.empty())
            {
                str += '|';
            }
            str.append(VkFormatFeatureFlagBits2ToString(static_cast<VkFormatFeatureFlagBits2>(1U) << index));
        }
        ++index;
        vkFlags >>= 1U;
    }
    if (str.empty())
    {
        str.append(VkFormatFeatureFlagBits2ToString(0U));
    }
    return str;
}

template <> std::string ToString<VkPipelineCreationFeedbackFlagBits>(const VkPipelineCreationFeedbackFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPipelineCreationFeedbackFlagBits";
}

template <> std::string ToString<VkPipelineCreationFeedbackFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPipelineCreationFeedbackFlagBits>(vkFlags);
}

std::string VkPipelineStageFlagBits2ToString(const VkPipelineStageFlagBits2 value)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPipelineStageFlagBits2";
}

std::string VkPipelineStageFlags2ToString(VkFlags64 vkFlags)
{
    std::string   str;
    VkFlags64     index = 0U;
    while (vkFlags)
    {
        if (vkFlags & 1U)
        {
            if (!str.empty())
            {
                str += '|';
            }
            str.append(VkPipelineStageFlagBits2ToString(static_cast<VkPipelineStageFlagBits2>(1U) << index));
        }
        ++index;
        vkFlags >>= 1U;
    }
    if (str.empty())
    {
        str.append(VkPipelineStageFlagBits2ToString(0U));
    }
    return str;
}

template <> std::string ToString<VkRenderingFlagBits>(const VkRenderingFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkRenderingFlagBits";
}

template <> std::string ToString<VkRenderingFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkRenderingFlagBits>(vkFlags);
}

template <> std::string ToString<VkSubmitFlagBits>(const VkSubmitFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSubmitFlagBits";
}

template <> std::string ToString<VkSubmitFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSubmitFlagBits>(vkFlags);
}

template <> std::string ToString<VkToolPurposeFlagBits>(const VkToolPurposeFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkToolPurposeFlagBits";
}

template <> std::string ToString<VkToolPurposeFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkToolPurposeFlagBits>(vkFlags);
}

std::string VkBufferUsageFlagBits2ToString(const VkBufferUsageFlagBits2 value)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkBufferUsageFlagBits2";
}

std::string VkBufferUsageFlags2ToString(VkFlags64 vkFlags)
{
    std::string   str;
    VkFlags64     index = 0U;
    while (vkFlags)
    {
        if (vkFlags & 1U)
        {
            if (!str.empty())
            {
                str += '|';
            }
            str.append(VkBufferUsageFlagBits2ToString(static_cast<VkBufferUsageFlagBits2>(1U) << index));
        }
        ++index;
        vkFlags >>= 1U;
    }
    if (str.empty())
    {
        str.append(VkBufferUsageFlagBits2ToString(0U));
    }
    return str;
}

template <> std::string ToString<VkHostImageCopyFlagBits>(const VkHostImageCopyFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkHostImageCopyFlagBits";
}

template <> std::string ToString<VkHostImageCopyFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkHostImageCopyFlagBits>(vkFlags);
}

template <> std::string ToString<VkLineRasterizationMode>(const VkLineRasterizationMode& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_LINE_RASTERIZATION_MODE_DEFAULT: return "VK_LINE_RASTERIZATION_MODE_DEFAULT";
    case VK_LINE_RASTERIZATION_MODE_RECTANGULAR: return "VK_LINE_RASTERIZATION_MODE_RECTANGULAR";
    case VK_LINE_RASTERIZATION_MODE_BRESENHAM: return "VK_LINE_RASTERIZATION_MODE_BRESENHAM";
    case VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH: return "VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH";
    default: break;
    }
    return "Unhandled VkLineRasterizationMode";
}

template <> std::string ToString<VkMemoryUnmapFlagBits>(const VkMemoryUnmapFlagBits& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkMemoryUnmapFlagBits";
}

template <> std::string ToString<VkMemoryUnmapFlagBits>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkMemoryUnmapFlagBits>(vkFlags);
}

std::string VkPipelineCreateFlagBits2ToString(const VkPipelineCreateFlagBits2 value)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPipelineCreateFlagBits2";
}

std::string VkPipelineCreateFlags2ToString(VkFlags64 vkFlags)
{
    std::string   str;
    VkFlags64     index = 0U;
    while (vkFlags)
    {
        if (vkFlags & 1U)
        {
            if (!str.empty())
            {
                str += '|';
            }
            str.append(VkPipelineCreateFlagBits2ToString(static_cast<VkPipelineCreateFlagBits2>(1U) << index));
        }
        ++index;
        vkFlags >>= 1U;
    }
    if (str.empty())
    {
        str.append(VkPipelineCreateFlagBits2ToString(0U));
    }
    return str;
}

template <> std::string ToString<VkPipelineRobustnessBufferBehavior>(const VkPipelineRobustnessBufferBehavior& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT: return "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT";
    case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED: return "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED";
    case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS: return "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS";
    case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2: return "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2";
    default: break;
    }
    return "Unhandled VkPipelineRobustnessBufferBehavior";
}

template <> std::string ToString<VkPipelineRobustnessImageBehavior>(const VkPipelineRobustnessImageBehavior& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT: return "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT";
    case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED: return "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED";
    case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS: return "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS";
    case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2: return "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2";
    default: break;
    }
    return "Unhandled VkPipelineRobustnessImageBehavior";
}

template <> std::string ToString<VkQueueGlobalPriority>(const VkQueueGlobalPriority& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_QUEUE_GLOBAL_PRIORITY_LOW: return "VK_QUEUE_GLOBAL_PRIORITY_LOW";
    case VK_QUEUE_GLOBAL_PRIORITY_MEDIUM: return "VK_QUEUE_GLOBAL_PRIORITY_MEDIUM";
    case VK_QUEUE_GLOBAL_PRIORITY_HIGH: return "VK_QUEUE_GLOBAL_PRIORITY_HIGH";
    case VK_QUEUE_GLOBAL_PRIORITY_REALTIME: return "VK_QUEUE_GLOBAL_PRIORITY_REALTIME";
    default: break;
    }
    return "Unhandled VkQueueGlobalPriority";
}

template <> std::string ToString<VkColorSpaceKHR>(const VkColorSpaceKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_COLOR_SPACE_SRGB_NONLINEAR_KHR: return "VK_COLOR_SPACE_SRGB_NONLINEAR_KHR";
    default: break;
    }
    return "Unhandled VkColorSpaceKHR";
}

template <> std::string ToString<VkCompositeAlphaFlagBitsKHR>(const VkCompositeAlphaFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkCompositeAlphaFlagBitsKHR";
}

template <> std::string ToString<VkCompositeAlphaFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkCompositeAlphaFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkPresentModeKHR>(const VkPresentModeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PRESENT_MODE_IMMEDIATE_KHR: return "VK_PRESENT_MODE_IMMEDIATE_KHR";
    case VK_PRESENT_MODE_MAILBOX_KHR: return "VK_PRESENT_MODE_MAILBOX_KHR";
    case VK_PRESENT_MODE_FIFO_KHR: return "VK_PRESENT_MODE_FIFO_KHR";
    case VK_PRESENT_MODE_FIFO_RELAXED_KHR: return "VK_PRESENT_MODE_FIFO_RELAXED_KHR";
    default: break;
    }
    return "Unhandled VkPresentModeKHR";
}

template <> std::string ToString<VkSurfaceTransformFlagBitsKHR>(const VkSurfaceTransformFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSurfaceTransformFlagBitsKHR";
}

template <> std::string ToString<VkSurfaceTransformFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSurfaceTransformFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkDeviceGroupPresentModeFlagBitsKHR>(const VkDeviceGroupPresentModeFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDeviceGroupPresentModeFlagBitsKHR";
}

template <> std::string ToString<VkDeviceGroupPresentModeFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDeviceGroupPresentModeFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkSwapchainCreateFlagBitsKHR>(const VkSwapchainCreateFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSwapchainCreateFlagBitsKHR";
}

template <> std::string ToString<VkSwapchainCreateFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSwapchainCreateFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkDisplayPlaneAlphaFlagBitsKHR>(const VkDisplayPlaneAlphaFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDisplayPlaneAlphaFlagBitsKHR";
}

template <> std::string ToString<VkDisplayPlaneAlphaFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDisplayPlaneAlphaFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkQueryResultStatusKHR>(const VkQueryResultStatusKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_QUERY_RESULT_STATUS_ERROR_KHR: return "VK_QUERY_RESULT_STATUS_ERROR_KHR";
    case VK_QUERY_RESULT_STATUS_NOT_READY_KHR: return "VK_QUERY_RESULT_STATUS_NOT_READY_KHR";
    case VK_QUERY_RESULT_STATUS_COMPLETE_KHR: return "VK_QUERY_RESULT_STATUS_COMPLETE_KHR";
    default: break;
    }
    return "Unhandled VkQueryResultStatusKHR";
}

template <> std::string ToString<VkVideoCapabilityFlagBitsKHR>(const VkVideoCapabilityFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoCapabilityFlagBitsKHR";
}

template <> std::string ToString<VkVideoCapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoCapabilityFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoChromaSubsamplingFlagBitsKHR>(const VkVideoChromaSubsamplingFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_CHROMA_SUBSAMPLING_INVALID_KHR: return "VK_VIDEO_CHROMA_SUBSAMPLING_INVALID_KHR";
    default: break;
    }
    return "Unhandled VkVideoChromaSubsamplingFlagBitsKHR";
}

template <> std::string ToString<VkVideoChromaSubsamplingFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoChromaSubsamplingFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoCodecOperationFlagBitsKHR>(const VkVideoCodecOperationFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_CODEC_OPERATION_NONE_KHR: return "VK_VIDEO_CODEC_OPERATION_NONE_KHR";
    default: break;
    }
    return "Unhandled VkVideoCodecOperationFlagBitsKHR";
}

template <> std::string ToString<VkVideoCodecOperationFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoCodecOperationFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoCodingControlFlagBitsKHR>(const VkVideoCodingControlFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoCodingControlFlagBitsKHR";
}

template <> std::string ToString<VkVideoCodingControlFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoCodingControlFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoComponentBitDepthFlagBitsKHR>(const VkVideoComponentBitDepthFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_COMPONENT_BIT_DEPTH_INVALID_KHR: return "VK_VIDEO_COMPONENT_BIT_DEPTH_INVALID_KHR";
    default: break;
    }
    return "Unhandled VkVideoComponentBitDepthFlagBitsKHR";
}

template <> std::string ToString<VkVideoComponentBitDepthFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoComponentBitDepthFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoSessionCreateFlagBitsKHR>(const VkVideoSessionCreateFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoSessionCreateFlagBitsKHR";
}

template <> std::string ToString<VkVideoSessionCreateFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoSessionCreateFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoSessionParametersCreateFlagBitsKHR>(const VkVideoSessionParametersCreateFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoSessionParametersCreateFlagBitsKHR";
}

template <> std::string ToString<VkVideoSessionParametersCreateFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoSessionParametersCreateFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoDecodeCapabilityFlagBitsKHR>(const VkVideoDecodeCapabilityFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoDecodeCapabilityFlagBitsKHR";
}

template <> std::string ToString<VkVideoDecodeCapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoDecodeCapabilityFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoDecodeUsageFlagBitsKHR>(const VkVideoDecodeUsageFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_DECODE_USAGE_DEFAULT_KHR: return "VK_VIDEO_DECODE_USAGE_DEFAULT_KHR";
    default: break;
    }
    return "Unhandled VkVideoDecodeUsageFlagBitsKHR";
}

template <> std::string ToString<VkVideoDecodeUsageFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoDecodeUsageFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeH264CapabilityFlagBitsKHR>(const VkVideoEncodeH264CapabilityFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeH264CapabilityFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeH264CapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeH264CapabilityFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeH264RateControlFlagBitsKHR>(const VkVideoEncodeH264RateControlFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeH264RateControlFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeH264RateControlFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeH264RateControlFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeH264StdFlagBitsKHR>(const VkVideoEncodeH264StdFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeH264StdFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeH264StdFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeH264StdFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeH265CapabilityFlagBitsKHR>(const VkVideoEncodeH265CapabilityFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeH265CapabilityFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeH265CapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeH265CapabilityFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeH265CtbSizeFlagBitsKHR>(const VkVideoEncodeH265CtbSizeFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeH265CtbSizeFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeH265CtbSizeFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeH265CtbSizeFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeH265RateControlFlagBitsKHR>(const VkVideoEncodeH265RateControlFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeH265RateControlFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeH265RateControlFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeH265RateControlFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeH265StdFlagBitsKHR>(const VkVideoEncodeH265StdFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeH265StdFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeH265StdFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeH265StdFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeH265TransformBlockSizeFlagBitsKHR>(const VkVideoEncodeH265TransformBlockSizeFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeH265TransformBlockSizeFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeH265TransformBlockSizeFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeH265TransformBlockSizeFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoDecodeH264PictureLayoutFlagBitsKHR>(const VkVideoDecodeH264PictureLayoutFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR: return "VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR";
    default: break;
    }
    return "Unhandled VkVideoDecodeH264PictureLayoutFlagBitsKHR";
}

template <> std::string ToString<VkVideoDecodeH264PictureLayoutFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoDecodeH264PictureLayoutFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkAcquireProfilingLockFlagBitsKHR>(const VkAcquireProfilingLockFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    return "Unhandled VkAcquireProfilingLockFlagBitsKHR";
}

template <> std::string ToString<VkAcquireProfilingLockFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkAcquireProfilingLockFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkPerformanceCounterDescriptionFlagBitsKHR>(const VkPerformanceCounterDescriptionFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPerformanceCounterDescriptionFlagBitsKHR";
}

template <> std::string ToString<VkPerformanceCounterDescriptionFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPerformanceCounterDescriptionFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkPerformanceCounterScopeKHR>(const VkPerformanceCounterScopeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR: return "VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR";
    case VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR: return "VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR";
    case VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR: return "VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR";
    default: break;
    }
    return "Unhandled VkPerformanceCounterScopeKHR";
}

template <> std::string ToString<VkPerformanceCounterStorageKHR>(const VkPerformanceCounterStorageKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR";
    case VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR";
    case VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR";
    case VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR";
    case VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR";
    case VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR: return "VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR";
    default: break;
    }
    return "Unhandled VkPerformanceCounterStorageKHR";
}

template <> std::string ToString<VkPerformanceCounterUnitKHR>(const VkPerformanceCounterUnitKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR";
    case VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR: return "VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR";
    default: break;
    }
    return "Unhandled VkPerformanceCounterUnitKHR";
}

template <> std::string ToString<VkFragmentShadingRateCombinerOpKHR>(const VkFragmentShadingRateCombinerOpKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR";
    case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR";
    case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR";
    case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR";
    case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR: return "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR";
    default: break;
    }
    return "Unhandled VkFragmentShadingRateCombinerOpKHR";
}

template <> std::string ToString<VkPipelineExecutableStatisticFormatKHR>(const VkPipelineExecutableStatisticFormatKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR: return "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR";
    case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR: return "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR";
    case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR: return "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR";
    case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR: return "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR";
    default: break;
    }
    return "Unhandled VkPipelineExecutableStatisticFormatKHR";
}

template <> std::string ToString<VkVideoEncodeCapabilityFlagBitsKHR>(const VkVideoEncodeCapabilityFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeCapabilityFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeCapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeCapabilityFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeContentFlagBitsKHR>(const VkVideoEncodeContentFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_ENCODE_CONTENT_DEFAULT_KHR: return "VK_VIDEO_ENCODE_CONTENT_DEFAULT_KHR";
    default: break;
    }
    return "Unhandled VkVideoEncodeContentFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeContentFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeContentFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeFeedbackFlagBitsKHR>(const VkVideoEncodeFeedbackFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeFeedbackFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeFeedbackFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeFeedbackFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeFlagBitsKHR>(const VkVideoEncodeFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeRateControlModeFlagBitsKHR>(const VkVideoEncodeRateControlModeFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DEFAULT_KHR: return "VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DEFAULT_KHR";
    default: break;
    }
    return "Unhandled VkVideoEncodeRateControlModeFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeRateControlModeFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeRateControlModeFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeTuningModeKHR>(const VkVideoEncodeTuningModeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_ENCODE_TUNING_MODE_DEFAULT_KHR: return "VK_VIDEO_ENCODE_TUNING_MODE_DEFAULT_KHR";
    case VK_VIDEO_ENCODE_TUNING_MODE_HIGH_QUALITY_KHR: return "VK_VIDEO_ENCODE_TUNING_MODE_HIGH_QUALITY_KHR";
    case VK_VIDEO_ENCODE_TUNING_MODE_LOW_LATENCY_KHR: return "VK_VIDEO_ENCODE_TUNING_MODE_LOW_LATENCY_KHR";
    case VK_VIDEO_ENCODE_TUNING_MODE_ULTRA_LOW_LATENCY_KHR: return "VK_VIDEO_ENCODE_TUNING_MODE_ULTRA_LOW_LATENCY_KHR";
    case VK_VIDEO_ENCODE_TUNING_MODE_LOSSLESS_KHR: return "VK_VIDEO_ENCODE_TUNING_MODE_LOSSLESS_KHR";
    default: break;
    }
    return "Unhandled VkVideoEncodeTuningModeKHR";
}

template <> std::string ToString<VkVideoEncodeUsageFlagBitsKHR>(const VkVideoEncodeUsageFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_ENCODE_USAGE_DEFAULT_KHR: return "VK_VIDEO_ENCODE_USAGE_DEFAULT_KHR";
    default: break;
    }
    return "Unhandled VkVideoEncodeUsageFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeUsageFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeUsageFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkComponentTypeKHR>(const VkComponentTypeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_COMPONENT_TYPE_FLOAT16_KHR: return "VK_COMPONENT_TYPE_FLOAT16_KHR";
    case VK_COMPONENT_TYPE_FLOAT32_KHR: return "VK_COMPONENT_TYPE_FLOAT32_KHR";
    case VK_COMPONENT_TYPE_FLOAT64_KHR: return "VK_COMPONENT_TYPE_FLOAT64_KHR";
    case VK_COMPONENT_TYPE_SINT8_KHR: return "VK_COMPONENT_TYPE_SINT8_KHR";
    case VK_COMPONENT_TYPE_SINT16_KHR: return "VK_COMPONENT_TYPE_SINT16_KHR";
    case VK_COMPONENT_TYPE_SINT32_KHR: return "VK_COMPONENT_TYPE_SINT32_KHR";
    case VK_COMPONENT_TYPE_SINT64_KHR: return "VK_COMPONENT_TYPE_SINT64_KHR";
    case VK_COMPONENT_TYPE_UINT8_KHR: return "VK_COMPONENT_TYPE_UINT8_KHR";
    case VK_COMPONENT_TYPE_UINT16_KHR: return "VK_COMPONENT_TYPE_UINT16_KHR";
    case VK_COMPONENT_TYPE_UINT32_KHR: return "VK_COMPONENT_TYPE_UINT32_KHR";
    case VK_COMPONENT_TYPE_UINT64_KHR: return "VK_COMPONENT_TYPE_UINT64_KHR";
    default: break;
    }
    return "Unhandled VkComponentTypeKHR";
}

template <> std::string ToString<VkScopeKHR>(const VkScopeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SCOPE_DEVICE_KHR: return "VK_SCOPE_DEVICE_KHR";
    case VK_SCOPE_WORKGROUP_KHR: return "VK_SCOPE_WORKGROUP_KHR";
    case VK_SCOPE_SUBGROUP_KHR: return "VK_SCOPE_SUBGROUP_KHR";
    case VK_SCOPE_QUEUE_FAMILY_KHR: return "VK_SCOPE_QUEUE_FAMILY_KHR";
    default: break;
    }
    return "Unhandled VkScopeKHR";
}

template <> std::string ToString<VkVideoEncodeAV1CapabilityFlagBitsKHR>(const VkVideoEncodeAV1CapabilityFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeAV1CapabilityFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeAV1CapabilityFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeAV1CapabilityFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeAV1PredictionModeKHR>(const VkVideoEncodeAV1PredictionModeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_INTRA_ONLY_KHR: return "VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_INTRA_ONLY_KHR";
    case VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_SINGLE_REFERENCE_KHR: return "VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_SINGLE_REFERENCE_KHR";
    case VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_UNIDIRECTIONAL_COMPOUND_KHR: return "VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_UNIDIRECTIONAL_COMPOUND_KHR";
    case VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_BIDIRECTIONAL_COMPOUND_KHR: return "VK_VIDEO_ENCODE_AV1_PREDICTION_MODE_BIDIRECTIONAL_COMPOUND_KHR";
    default: break;
    }
    return "Unhandled VkVideoEncodeAV1PredictionModeKHR";
}

template <> std::string ToString<VkVideoEncodeAV1RateControlFlagBitsKHR>(const VkVideoEncodeAV1RateControlFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeAV1RateControlFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeAV1RateControlFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeAV1RateControlFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeAV1RateControlGroupKHR>(const VkVideoEncodeAV1RateControlGroupKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIDEO_ENCODE_AV1_RATE_CONTROL_GROUP_INTRA_KHR: return "VK_VIDEO_ENCODE_AV1_RATE_CONTROL_GROUP_INTRA_KHR";
    case VK_VIDEO_ENCODE_AV1_RATE_CONTROL_GROUP_PREDICTIVE_KHR: return "VK_VIDEO_ENCODE_AV1_RATE_CONTROL_GROUP_PREDICTIVE_KHR";
    case VK_VIDEO_ENCODE_AV1_RATE_CONTROL_GROUP_BIPREDICTIVE_KHR: return "VK_VIDEO_ENCODE_AV1_RATE_CONTROL_GROUP_BIPREDICTIVE_KHR";
    default: break;
    }
    return "Unhandled VkVideoEncodeAV1RateControlGroupKHR";
}

template <> std::string ToString<VkVideoEncodeAV1StdFlagBitsKHR>(const VkVideoEncodeAV1StdFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeAV1StdFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeAV1StdFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeAV1StdFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkVideoEncodeAV1SuperblockSizeFlagBitsKHR>(const VkVideoEncodeAV1SuperblockSizeFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkVideoEncodeAV1SuperblockSizeFlagBitsKHR";
}

template <> std::string ToString<VkVideoEncodeAV1SuperblockSizeFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkVideoEncodeAV1SuperblockSizeFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkTimeDomainKHR>(const VkTimeDomainKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_TIME_DOMAIN_DEVICE_KHR: return "VK_TIME_DOMAIN_DEVICE_KHR";
    case VK_TIME_DOMAIN_CLOCK_MONOTONIC_KHR: return "VK_TIME_DOMAIN_CLOCK_MONOTONIC_KHR";
    case VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_KHR: return "VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_KHR";
    case VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_KHR: return "VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_KHR";
    default: break;
    }
    return "Unhandled VkTimeDomainKHR";
}

template <> std::string ToString<VkPhysicalDeviceLayeredApiKHR>(const VkPhysicalDeviceLayeredApiKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PHYSICAL_DEVICE_LAYERED_API_VULKAN_KHR: return "VK_PHYSICAL_DEVICE_LAYERED_API_VULKAN_KHR";
    case VK_PHYSICAL_DEVICE_LAYERED_API_D3D12_KHR: return "VK_PHYSICAL_DEVICE_LAYERED_API_D3D12_KHR";
    case VK_PHYSICAL_DEVICE_LAYERED_API_METAL_KHR: return "VK_PHYSICAL_DEVICE_LAYERED_API_METAL_KHR";
    case VK_PHYSICAL_DEVICE_LAYERED_API_OPENGL_KHR: return "VK_PHYSICAL_DEVICE_LAYERED_API_OPENGL_KHR";
    case VK_PHYSICAL_DEVICE_LAYERED_API_OPENGLES_KHR: return "VK_PHYSICAL_DEVICE_LAYERED_API_OPENGLES_KHR";
    default: break;
    }
    return "Unhandled VkPhysicalDeviceLayeredApiKHR";
}

template <> std::string ToString<VkDebugReportFlagBitsEXT>(const VkDebugReportFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDebugReportFlagBitsEXT";
}

template <> std::string ToString<VkDebugReportFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDebugReportFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkDebugReportObjectTypeEXT>(const VkDebugReportObjectTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT";
    case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT: return "VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT";
    default: break;
    }
    return "Unhandled VkDebugReportObjectTypeEXT";
}

template <> std::string ToString<VkRasterizationOrderAMD>(const VkRasterizationOrderAMD& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_RASTERIZATION_ORDER_STRICT_AMD: return "VK_RASTERIZATION_ORDER_STRICT_AMD";
    case VK_RASTERIZATION_ORDER_RELAXED_AMD: return "VK_RASTERIZATION_ORDER_RELAXED_AMD";
    default: break;
    }
    return "Unhandled VkRasterizationOrderAMD";
}

template <> std::string ToString<VkShaderInfoTypeAMD>(const VkShaderInfoTypeAMD& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SHADER_INFO_TYPE_STATISTICS_AMD: return "VK_SHADER_INFO_TYPE_STATISTICS_AMD";
    case VK_SHADER_INFO_TYPE_BINARY_AMD: return "VK_SHADER_INFO_TYPE_BINARY_AMD";
    case VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD: return "VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD";
    default: break;
    }
    return "Unhandled VkShaderInfoTypeAMD";
}

template <> std::string ToString<VkExternalMemoryFeatureFlagBitsNV>(const VkExternalMemoryFeatureFlagBitsNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkExternalMemoryFeatureFlagBitsNV";
}

template <> std::string ToString<VkExternalMemoryFeatureFlagBitsNV>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkExternalMemoryFeatureFlagBitsNV>(vkFlags);
}

template <> std::string ToString<VkExternalMemoryHandleTypeFlagBitsNV>(const VkExternalMemoryHandleTypeFlagBitsNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkExternalMemoryHandleTypeFlagBitsNV";
}

template <> std::string ToString<VkExternalMemoryHandleTypeFlagBitsNV>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkExternalMemoryHandleTypeFlagBitsNV>(vkFlags);
}

template <> std::string ToString<VkValidationCheckEXT>(const VkValidationCheckEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VALIDATION_CHECK_ALL_EXT: return "VK_VALIDATION_CHECK_ALL_EXT";
    case VK_VALIDATION_CHECK_SHADERS_EXT: return "VK_VALIDATION_CHECK_SHADERS_EXT";
    default: break;
    }
    return "Unhandled VkValidationCheckEXT";
}

template <> std::string ToString<VkConditionalRenderingFlagBitsEXT>(const VkConditionalRenderingFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkConditionalRenderingFlagBitsEXT";
}

template <> std::string ToString<VkConditionalRenderingFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkConditionalRenderingFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkSurfaceCounterFlagBitsEXT>(const VkSurfaceCounterFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkSurfaceCounterFlagBitsEXT";
}

template <> std::string ToString<VkSurfaceCounterFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkSurfaceCounterFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkDeviceEventTypeEXT>(const VkDeviceEventTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT: return "VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT";
    default: break;
    }
    return "Unhandled VkDeviceEventTypeEXT";
}

template <> std::string ToString<VkDisplayEventTypeEXT>(const VkDisplayEventTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT: return "VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT";
    default: break;
    }
    return "Unhandled VkDisplayEventTypeEXT";
}

template <> std::string ToString<VkDisplayPowerStateEXT>(const VkDisplayPowerStateEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DISPLAY_POWER_STATE_OFF_EXT: return "VK_DISPLAY_POWER_STATE_OFF_EXT";
    case VK_DISPLAY_POWER_STATE_SUSPEND_EXT: return "VK_DISPLAY_POWER_STATE_SUSPEND_EXT";
    case VK_DISPLAY_POWER_STATE_ON_EXT: return "VK_DISPLAY_POWER_STATE_ON_EXT";
    default: break;
    }
    return "Unhandled VkDisplayPowerStateEXT";
}

template <> std::string ToString<VkViewportCoordinateSwizzleNV>(const VkViewportCoordinateSwizzleNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV";
    case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV: return "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV";
    default: break;
    }
    return "Unhandled VkViewportCoordinateSwizzleNV";
}

template <> std::string ToString<VkDiscardRectangleModeEXT>(const VkDiscardRectangleModeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT: return "VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT";
    case VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT: return "VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT";
    default: break;
    }
    return "Unhandled VkDiscardRectangleModeEXT";
}

template <> std::string ToString<VkConservativeRasterizationModeEXT>(const VkConservativeRasterizationModeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT: return "VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT";
    case VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT: return "VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT";
    case VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT: return "VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT";
    default: break;
    }
    return "Unhandled VkConservativeRasterizationModeEXT";
}

template <> std::string ToString<VkDebugUtilsMessageSeverityFlagBitsEXT>(const VkDebugUtilsMessageSeverityFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDebugUtilsMessageSeverityFlagBitsEXT";
}

template <> std::string ToString<VkDebugUtilsMessageSeverityFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDebugUtilsMessageSeverityFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkDebugUtilsMessageTypeFlagBitsEXT>(const VkDebugUtilsMessageTypeFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDebugUtilsMessageTypeFlagBitsEXT";
}

template <> std::string ToString<VkDebugUtilsMessageTypeFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDebugUtilsMessageTypeFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkBlendOverlapEXT>(const VkBlendOverlapEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_BLEND_OVERLAP_UNCORRELATED_EXT: return "VK_BLEND_OVERLAP_UNCORRELATED_EXT";
    case VK_BLEND_OVERLAP_DISJOINT_EXT: return "VK_BLEND_OVERLAP_DISJOINT_EXT";
    case VK_BLEND_OVERLAP_CONJOINT_EXT: return "VK_BLEND_OVERLAP_CONJOINT_EXT";
    default: break;
    }
    return "Unhandled VkBlendOverlapEXT";
}

template <> std::string ToString<VkCoverageModulationModeNV>(const VkCoverageModulationModeNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_COVERAGE_MODULATION_MODE_NONE_NV: return "VK_COVERAGE_MODULATION_MODE_NONE_NV";
    case VK_COVERAGE_MODULATION_MODE_RGB_NV: return "VK_COVERAGE_MODULATION_MODE_RGB_NV";
    case VK_COVERAGE_MODULATION_MODE_ALPHA_NV: return "VK_COVERAGE_MODULATION_MODE_ALPHA_NV";
    case VK_COVERAGE_MODULATION_MODE_RGBA_NV: return "VK_COVERAGE_MODULATION_MODE_RGBA_NV";
    default: break;
    }
    return "Unhandled VkCoverageModulationModeNV";
}

template <> std::string ToString<VkValidationCacheHeaderVersionEXT>(const VkValidationCacheHeaderVersionEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT: return "VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT";
    default: break;
    }
    return "Unhandled VkValidationCacheHeaderVersionEXT";
}

template <> std::string ToString<VkCoarseSampleOrderTypeNV>(const VkCoarseSampleOrderTypeNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV: return "VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV";
    case VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV: return "VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV";
    case VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV: return "VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV";
    case VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV: return "VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV";
    default: break;
    }
    return "Unhandled VkCoarseSampleOrderTypeNV";
}

template <> std::string ToString<VkShadingRatePaletteEntryNV>(const VkShadingRatePaletteEntryNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV";
    case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV: return "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV";
    default: break;
    }
    return "Unhandled VkShadingRatePaletteEntryNV";
}

template <> std::string ToString<VkAccelerationStructureMemoryRequirementsTypeNV>(const VkAccelerationStructureMemoryRequirementsTypeNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV: return "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV";
    case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV: return "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV";
    case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV: return "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV";
    default: break;
    }
    return "Unhandled VkAccelerationStructureMemoryRequirementsTypeNV";
}

template <> std::string ToString<VkAccelerationStructureTypeKHR>(const VkAccelerationStructureTypeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR: return "VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR";
    case VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR: return "VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR";
    case VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR: return "VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR";
    default: break;
    }
    return "Unhandled VkAccelerationStructureTypeKHR";
}

template <> std::string ToString<VkBuildAccelerationStructureFlagBitsKHR>(const VkBuildAccelerationStructureFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkBuildAccelerationStructureFlagBitsKHR";
}

template <> std::string ToString<VkBuildAccelerationStructureFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkBuildAccelerationStructureFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkCopyAccelerationStructureModeKHR>(const VkCopyAccelerationStructureModeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR: return "VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR";
    case VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR: return "VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR";
    case VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR: return "VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR";
    case VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR: return "VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR";
    default: break;
    }
    return "Unhandled VkCopyAccelerationStructureModeKHR";
}

template <> std::string ToString<VkGeometryFlagBitsKHR>(const VkGeometryFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkGeometryFlagBitsKHR";
}

template <> std::string ToString<VkGeometryFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkGeometryFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkGeometryInstanceFlagBitsKHR>(const VkGeometryInstanceFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkGeometryInstanceFlagBitsKHR";
}

template <> std::string ToString<VkGeometryInstanceFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkGeometryInstanceFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkGeometryTypeKHR>(const VkGeometryTypeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_GEOMETRY_TYPE_TRIANGLES_KHR: return "VK_GEOMETRY_TYPE_TRIANGLES_KHR";
    case VK_GEOMETRY_TYPE_AABBS_KHR: return "VK_GEOMETRY_TYPE_AABBS_KHR";
    case VK_GEOMETRY_TYPE_INSTANCES_KHR: return "VK_GEOMETRY_TYPE_INSTANCES_KHR";
    default: break;
    }
    return "Unhandled VkGeometryTypeKHR";
}

template <> std::string ToString<VkRayTracingShaderGroupTypeKHR>(const VkRayTracingShaderGroupTypeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR: return "VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR";
    case VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR: return "VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR";
    case VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR: return "VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR";
    default: break;
    }
    return "Unhandled VkRayTracingShaderGroupTypeKHR";
}

template <> std::string ToString<VkPipelineCompilerControlFlagBitsAMD>(const VkPipelineCompilerControlFlagBitsAMD& value, ToStringFlags, uint32_t, uint32_t)
{
    return "Unhandled VkPipelineCompilerControlFlagBitsAMD";
}

template <> std::string ToString<VkPipelineCompilerControlFlagBitsAMD>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPipelineCompilerControlFlagBitsAMD>(vkFlags);
}

template <> std::string ToString<VkMemoryOverallocationBehaviorAMD>(const VkMemoryOverallocationBehaviorAMD& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD: return "VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD";
    case VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD: return "VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD";
    case VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD: return "VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD";
    default: break;
    }
    return "Unhandled VkMemoryOverallocationBehaviorAMD";
}

template <> std::string ToString<VkPerformanceConfigurationTypeINTEL>(const VkPerformanceConfigurationTypeINTEL& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL: return "VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL";
    default: break;
    }
    return "Unhandled VkPerformanceConfigurationTypeINTEL";
}

template <> std::string ToString<VkPerformanceOverrideTypeINTEL>(const VkPerformanceOverrideTypeINTEL& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL: return "VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL";
    case VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL: return "VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL";
    default: break;
    }
    return "Unhandled VkPerformanceOverrideTypeINTEL";
}

template <> std::string ToString<VkPerformanceParameterTypeINTEL>(const VkPerformanceParameterTypeINTEL& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL: return "VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL";
    case VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL: return "VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL";
    default: break;
    }
    return "Unhandled VkPerformanceParameterTypeINTEL";
}

template <> std::string ToString<VkPerformanceValueTypeINTEL>(const VkPerformanceValueTypeINTEL& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL: return "VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL";
    case VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL: return "VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL";
    case VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL: return "VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL";
    case VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL: return "VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL";
    case VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL: return "VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL";
    default: break;
    }
    return "Unhandled VkPerformanceValueTypeINTEL";
}

template <> std::string ToString<VkQueryPoolSamplingModeINTEL>(const VkQueryPoolSamplingModeINTEL& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL: return "VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL";
    default: break;
    }
    return "Unhandled VkQueryPoolSamplingModeINTEL";
}

template <> std::string ToString<VkShaderCorePropertiesFlagBitsAMD>(const VkShaderCorePropertiesFlagBitsAMD& value, ToStringFlags, uint32_t, uint32_t)
{
    return "Unhandled VkShaderCorePropertiesFlagBitsAMD";
}

template <> std::string ToString<VkShaderCorePropertiesFlagBitsAMD>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkShaderCorePropertiesFlagBitsAMD>(vkFlags);
}

template <> std::string ToString<VkValidationFeatureDisableEXT>(const VkValidationFeatureDisableEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VALIDATION_FEATURE_DISABLE_ALL_EXT: return "VK_VALIDATION_FEATURE_DISABLE_ALL_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT: return "VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT: return "VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT: return "VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT: return "VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT: return "VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT: return "VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT";
    case VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT: return "VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT";
    default: break;
    }
    return "Unhandled VkValidationFeatureDisableEXT";
}

template <> std::string ToString<VkValidationFeatureEnableEXT>(const VkValidationFeatureEnableEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT: return "VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT";
    case VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT: return "VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT";
    case VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT: return "VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT";
    case VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT: return "VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT";
    case VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT: return "VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT";
    default: break;
    }
    return "Unhandled VkValidationFeatureEnableEXT";
}

template <> std::string ToString<VkCoverageReductionModeNV>(const VkCoverageReductionModeNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_COVERAGE_REDUCTION_MODE_MERGE_NV: return "VK_COVERAGE_REDUCTION_MODE_MERGE_NV";
    case VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV: return "VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV";
    default: break;
    }
    return "Unhandled VkCoverageReductionModeNV";
}

template <> std::string ToString<VkProvokingVertexModeEXT>(const VkProvokingVertexModeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_PROVOKING_VERTEX_MODE_FIRST_VERTEX_EXT: return "VK_PROVOKING_VERTEX_MODE_FIRST_VERTEX_EXT";
    case VK_PROVOKING_VERTEX_MODE_LAST_VERTEX_EXT: return "VK_PROVOKING_VERTEX_MODE_LAST_VERTEX_EXT";
    default: break;
    }
    return "Unhandled VkProvokingVertexModeEXT";
}

template <> std::string ToString<VkFullScreenExclusiveEXT>(const VkFullScreenExclusiveEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT: return "VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT";
    case VK_FULL_SCREEN_EXCLUSIVE_ALLOWED_EXT: return "VK_FULL_SCREEN_EXCLUSIVE_ALLOWED_EXT";
    case VK_FULL_SCREEN_EXCLUSIVE_DISALLOWED_EXT: return "VK_FULL_SCREEN_EXCLUSIVE_DISALLOWED_EXT";
    case VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT: return "VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT";
    default: break;
    }
    return "Unhandled VkFullScreenExclusiveEXT";
}

template <> std::string ToString<VkPresentGravityFlagBitsEXT>(const VkPresentGravityFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPresentGravityFlagBitsEXT";
}

template <> std::string ToString<VkPresentGravityFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPresentGravityFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkPresentScalingFlagBitsEXT>(const VkPresentScalingFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPresentScalingFlagBitsEXT";
}

template <> std::string ToString<VkPresentScalingFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPresentScalingFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkIndirectCommandsLayoutUsageFlagBitsNV>(const VkIndirectCommandsLayoutUsageFlagBitsNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkIndirectCommandsLayoutUsageFlagBitsNV";
}

template <> std::string ToString<VkIndirectCommandsLayoutUsageFlagBitsNV>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkIndirectCommandsLayoutUsageFlagBitsNV>(vkFlags);
}

template <> std::string ToString<VkIndirectCommandsTokenTypeNV>(const VkIndirectCommandsTokenTypeNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV";
    default: break;
    }
    return "Unhandled VkIndirectCommandsTokenTypeNV";
}

template <> std::string ToString<VkIndirectStateFlagBitsNV>(const VkIndirectStateFlagBitsNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkIndirectStateFlagBitsNV";
}

template <> std::string ToString<VkIndirectStateFlagBitsNV>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkIndirectStateFlagBitsNV>(vkFlags);
}

template <> std::string ToString<VkDepthBiasRepresentationEXT>(const VkDepthBiasRepresentationEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORMAT_EXT: return "VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORMAT_EXT";
    case VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORCE_UNORM_EXT: return "VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORCE_UNORM_EXT";
    case VK_DEPTH_BIAS_REPRESENTATION_FLOAT_EXT: return "VK_DEPTH_BIAS_REPRESENTATION_FLOAT_EXT";
    default: break;
    }
    return "Unhandled VkDepthBiasRepresentationEXT";
}

template <> std::string ToString<VkDeviceMemoryReportEventTypeEXT>(const VkDeviceMemoryReportEventTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT: return "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT";
    case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT: return "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT";
    case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT: return "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT";
    case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT: return "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT";
    case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT: return "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT";
    default: break;
    }
    return "Unhandled VkDeviceMemoryReportEventTypeEXT";
}

template <> std::string ToString<VkDeviceDiagnosticsConfigFlagBitsNV>(const VkDeviceDiagnosticsConfigFlagBitsNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDeviceDiagnosticsConfigFlagBitsNV";
}

template <> std::string ToString<VkDeviceDiagnosticsConfigFlagBitsNV>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDeviceDiagnosticsConfigFlagBitsNV>(vkFlags);
}

template <> std::string ToString<VkGraphicsPipelineLibraryFlagBitsEXT>(const VkGraphicsPipelineLibraryFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkGraphicsPipelineLibraryFlagBitsEXT";
}

template <> std::string ToString<VkGraphicsPipelineLibraryFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkGraphicsPipelineLibraryFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkFragmentShadingRateNV>(const VkFragmentShadingRateNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV: return "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV";
    case VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV: return "VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV";
    case VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV: return "VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV";
    case VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV: return "VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV";
    case VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV: return "VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV";
    case VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV: return "VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV";
    default: break;
    }
    return "Unhandled VkFragmentShadingRateNV";
}

template <> std::string ToString<VkFragmentShadingRateTypeNV>(const VkFragmentShadingRateTypeNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV: return "VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV";
    case VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV: return "VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV";
    default: break;
    }
    return "Unhandled VkFragmentShadingRateTypeNV";
}

template <> std::string ToString<VkAccelerationStructureMotionInstanceTypeNV>(const VkAccelerationStructureMotionInstanceTypeNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV: return "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV";
    case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV: return "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV";
    case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV: return "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV";
    default: break;
    }
    return "Unhandled VkAccelerationStructureMotionInstanceTypeNV";
}

template <> std::string ToString<VkImageCompressionFixedRateFlagBitsEXT>(const VkImageCompressionFixedRateFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_IMAGE_COMPRESSION_FIXED_RATE_NONE_EXT: return "VK_IMAGE_COMPRESSION_FIXED_RATE_NONE_EXT";
    default: break;
    }
    return "Unhandled VkImageCompressionFixedRateFlagBitsEXT";
}

template <> std::string ToString<VkImageCompressionFixedRateFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkImageCompressionFixedRateFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkImageCompressionFlagBitsEXT>(const VkImageCompressionFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_IMAGE_COMPRESSION_DEFAULT_EXT: return "VK_IMAGE_COMPRESSION_DEFAULT_EXT";
    default: break;
    }
    return "Unhandled VkImageCompressionFlagBitsEXT";
}

template <> std::string ToString<VkImageCompressionFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkImageCompressionFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkDeviceFaultAddressTypeEXT>(const VkDeviceFaultAddressTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DEVICE_FAULT_ADDRESS_TYPE_NONE_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_NONE_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_READ_INVALID_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_READ_INVALID_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_WRITE_INVALID_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_WRITE_INVALID_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_EXECUTE_INVALID_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_EXECUTE_INVALID_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_UNKNOWN_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_UNKNOWN_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_INVALID_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_INVALID_EXT";
    case VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_FAULT_EXT: return "VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_FAULT_EXT";
    default: break;
    }
    return "Unhandled VkDeviceFaultAddressTypeEXT";
}

template <> std::string ToString<VkDeviceFaultVendorBinaryHeaderVersionEXT>(const VkDeviceFaultVendorBinaryHeaderVersionEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DEVICE_FAULT_VENDOR_BINARY_HEADER_VERSION_ONE_EXT: return "VK_DEVICE_FAULT_VENDOR_BINARY_HEADER_VERSION_ONE_EXT";
    default: break;
    }
    return "Unhandled VkDeviceFaultVendorBinaryHeaderVersionEXT";
}

template <> std::string ToString<VkDeviceAddressBindingFlagBitsEXT>(const VkDeviceAddressBindingFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkDeviceAddressBindingFlagBitsEXT";
}

template <> std::string ToString<VkDeviceAddressBindingFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkDeviceAddressBindingFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkDeviceAddressBindingTypeEXT>(const VkDeviceAddressBindingTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DEVICE_ADDRESS_BINDING_TYPE_BIND_EXT: return "VK_DEVICE_ADDRESS_BINDING_TYPE_BIND_EXT";
    case VK_DEVICE_ADDRESS_BINDING_TYPE_UNBIND_EXT: return "VK_DEVICE_ADDRESS_BINDING_TYPE_UNBIND_EXT";
    default: break;
    }
    return "Unhandled VkDeviceAddressBindingTypeEXT";
}

template <> std::string ToString<VkFrameBoundaryFlagBitsEXT>(const VkFrameBoundaryFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkFrameBoundaryFlagBitsEXT";
}

template <> std::string ToString<VkFrameBoundaryFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkFrameBoundaryFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkAccelerationStructureBuildTypeKHR>(const VkAccelerationStructureBuildTypeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR: return "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR";
    case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR: return "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR";
    case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR: return "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR";
    default: break;
    }
    return "Unhandled VkAccelerationStructureBuildTypeKHR";
}

template <> std::string ToString<VkAccelerationStructureCompatibilityKHR>(const VkAccelerationStructureCompatibilityKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR: return "VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR";
    case VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR: return "VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR";
    default: break;
    }
    return "Unhandled VkAccelerationStructureCompatibilityKHR";
}

template <> std::string ToString<VkBuildMicromapFlagBitsEXT>(const VkBuildMicromapFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkBuildMicromapFlagBitsEXT";
}

template <> std::string ToString<VkBuildMicromapFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkBuildMicromapFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkBuildMicromapModeEXT>(const VkBuildMicromapModeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_BUILD_MICROMAP_MODE_BUILD_EXT: return "VK_BUILD_MICROMAP_MODE_BUILD_EXT";
    default: break;
    }
    return "Unhandled VkBuildMicromapModeEXT";
}

template <> std::string ToString<VkCopyMicromapModeEXT>(const VkCopyMicromapModeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_COPY_MICROMAP_MODE_CLONE_EXT: return "VK_COPY_MICROMAP_MODE_CLONE_EXT";
    case VK_COPY_MICROMAP_MODE_SERIALIZE_EXT: return "VK_COPY_MICROMAP_MODE_SERIALIZE_EXT";
    case VK_COPY_MICROMAP_MODE_DESERIALIZE_EXT: return "VK_COPY_MICROMAP_MODE_DESERIALIZE_EXT";
    case VK_COPY_MICROMAP_MODE_COMPACT_EXT: return "VK_COPY_MICROMAP_MODE_COMPACT_EXT";
    default: break;
    }
    return "Unhandled VkCopyMicromapModeEXT";
}

template <> std::string ToString<VkMicromapCreateFlagBitsEXT>(const VkMicromapCreateFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkMicromapCreateFlagBitsEXT";
}

template <> std::string ToString<VkMicromapCreateFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkMicromapCreateFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkMicromapTypeEXT>(const VkMicromapTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_MICROMAP_TYPE_OPACITY_MICROMAP_EXT: return "VK_MICROMAP_TYPE_OPACITY_MICROMAP_EXT";
    default: break;
    }
    return "Unhandled VkMicromapTypeEXT";
}

template <> std::string ToString<VkOpacityMicromapFormatEXT>(const VkOpacityMicromapFormatEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_OPACITY_MICROMAP_FORMAT_2_STATE_EXT: return "VK_OPACITY_MICROMAP_FORMAT_2_STATE_EXT";
    case VK_OPACITY_MICROMAP_FORMAT_4_STATE_EXT: return "VK_OPACITY_MICROMAP_FORMAT_4_STATE_EXT";
    default: break;
    }
    return "Unhandled VkOpacityMicromapFormatEXT";
}

template <> std::string ToString<VkOpacityMicromapSpecialIndexEXT>(const VkOpacityMicromapSpecialIndexEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_TRANSPARENT_EXT: return "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_TRANSPARENT_EXT";
    case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_OPAQUE_EXT: return "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_OPAQUE_EXT";
    case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_TRANSPARENT_EXT: return "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_TRANSPARENT_EXT";
    case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE_EXT: return "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE_EXT";
    default: break;
    }
    return "Unhandled VkOpacityMicromapSpecialIndexEXT";
}

template <> std::string ToString<VkDisplacementMicromapFormatNV>(const VkDisplacementMicromapFormatNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DISPLACEMENT_MICROMAP_FORMAT_64_TRIANGLES_64_BYTES_NV: return "VK_DISPLACEMENT_MICROMAP_FORMAT_64_TRIANGLES_64_BYTES_NV";
    case VK_DISPLACEMENT_MICROMAP_FORMAT_256_TRIANGLES_128_BYTES_NV: return "VK_DISPLACEMENT_MICROMAP_FORMAT_256_TRIANGLES_128_BYTES_NV";
    case VK_DISPLACEMENT_MICROMAP_FORMAT_1024_TRIANGLES_128_BYTES_NV: return "VK_DISPLACEMENT_MICROMAP_FORMAT_1024_TRIANGLES_128_BYTES_NV";
    default: break;
    }
    return "Unhandled VkDisplacementMicromapFormatNV";
}

template <> std::string ToString<VkPhysicalDeviceSchedulingControlsFlagBitsARM>(const VkPhysicalDeviceSchedulingControlsFlagBitsARM& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkPhysicalDeviceSchedulingControlsFlagBitsARM";
}

template <> std::string ToString<VkPhysicalDeviceSchedulingControlsFlagBitsARM>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkPhysicalDeviceSchedulingControlsFlagBitsARM>(vkFlags);
}

template <> std::string ToString<VkSubpassMergeStatusEXT>(const VkSubpassMergeStatusEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SUBPASS_MERGE_STATUS_MERGED_EXT: return "VK_SUBPASS_MERGE_STATUS_MERGED_EXT";
    case VK_SUBPASS_MERGE_STATUS_DISALLOWED_EXT: return "VK_SUBPASS_MERGE_STATUS_DISALLOWED_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SIDE_EFFECTS_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SIDE_EFFECTS_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SAMPLES_MISMATCH_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SAMPLES_MISMATCH_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_VIEWS_MISMATCH_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_VIEWS_MISMATCH_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_ALIASING_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_ALIASING_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPENDENCIES_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPENDENCIES_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_TOO_MANY_ATTACHMENTS_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_TOO_MANY_ATTACHMENTS_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INSUFFICIENT_STORAGE_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INSUFFICIENT_STORAGE_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPTH_STENCIL_COUNT_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPTH_STENCIL_COUNT_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_RESOLVE_ATTACHMENT_REUSE_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_RESOLVE_ATTACHMENT_REUSE_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SINGLE_SUBPASS_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SINGLE_SUBPASS_EXT";
    case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_UNSPECIFIED_EXT: return "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_UNSPECIFIED_EXT";
    default: break;
    }
    return "Unhandled VkSubpassMergeStatusEXT";
}

template <> std::string ToString<VkDirectDriverLoadingModeLUNARG>(const VkDirectDriverLoadingModeLUNARG& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG: return "VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG";
    case VK_DIRECT_DRIVER_LOADING_MODE_INCLUSIVE_LUNARG: return "VK_DIRECT_DRIVER_LOADING_MODE_INCLUSIVE_LUNARG";
    default: break;
    }
    return "Unhandled VkDirectDriverLoadingModeLUNARG";
}

template <> std::string ToString<VkOpticalFlowExecuteFlagBitsNV>(const VkOpticalFlowExecuteFlagBitsNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkOpticalFlowExecuteFlagBitsNV";
}

template <> std::string ToString<VkOpticalFlowExecuteFlagBitsNV>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkOpticalFlowExecuteFlagBitsNV>(vkFlags);
}

template <> std::string ToString<VkOpticalFlowGridSizeFlagBitsNV>(const VkOpticalFlowGridSizeFlagBitsNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_OPTICAL_FLOW_GRID_SIZE_UNKNOWN_NV: return "VK_OPTICAL_FLOW_GRID_SIZE_UNKNOWN_NV";
    default: break;
    }
    return "Unhandled VkOpticalFlowGridSizeFlagBitsNV";
}

template <> std::string ToString<VkOpticalFlowGridSizeFlagBitsNV>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkOpticalFlowGridSizeFlagBitsNV>(vkFlags);
}

template <> std::string ToString<VkOpticalFlowPerformanceLevelNV>(const VkOpticalFlowPerformanceLevelNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_UNKNOWN_NV: return "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_UNKNOWN_NV";
    case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_SLOW_NV: return "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_SLOW_NV";
    case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_MEDIUM_NV: return "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_MEDIUM_NV";
    case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_FAST_NV: return "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_FAST_NV";
    default: break;
    }
    return "Unhandled VkOpticalFlowPerformanceLevelNV";
}

template <> std::string ToString<VkOpticalFlowSessionBindingPointNV>(const VkOpticalFlowSessionBindingPointNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_UNKNOWN_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_UNKNOWN_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_INPUT_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_INPUT_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_REFERENCE_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_REFERENCE_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_HINT_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_HINT_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_FLOW_VECTOR_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_FLOW_VECTOR_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_FLOW_VECTOR_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_FLOW_VECTOR_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_COST_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_COST_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_COST_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_COST_NV";
    case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_GLOBAL_FLOW_NV: return "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_GLOBAL_FLOW_NV";
    default: break;
    }
    return "Unhandled VkOpticalFlowSessionBindingPointNV";
}

template <> std::string ToString<VkOpticalFlowSessionCreateFlagBitsNV>(const VkOpticalFlowSessionCreateFlagBitsNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkOpticalFlowSessionCreateFlagBitsNV";
}

template <> std::string ToString<VkOpticalFlowSessionCreateFlagBitsNV>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkOpticalFlowSessionCreateFlagBitsNV>(vkFlags);
}

template <> std::string ToString<VkOpticalFlowUsageFlagBitsNV>(const VkOpticalFlowUsageFlagBitsNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_OPTICAL_FLOW_USAGE_UNKNOWN_NV: return "VK_OPTICAL_FLOW_USAGE_UNKNOWN_NV";
    default: break;
    }
    return "Unhandled VkOpticalFlowUsageFlagBitsNV";
}

template <> std::string ToString<VkOpticalFlowUsageFlagBitsNV>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkOpticalFlowUsageFlagBitsNV>(vkFlags);
}

template <> std::string ToString<VkAntiLagModeAMD>(const VkAntiLagModeAMD& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_ANTI_LAG_MODE_DRIVER_CONTROL_AMD: return "VK_ANTI_LAG_MODE_DRIVER_CONTROL_AMD";
    case VK_ANTI_LAG_MODE_ON_AMD: return "VK_ANTI_LAG_MODE_ON_AMD";
    case VK_ANTI_LAG_MODE_OFF_AMD: return "VK_ANTI_LAG_MODE_OFF_AMD";
    default: break;
    }
    return "Unhandled VkAntiLagModeAMD";
}

template <> std::string ToString<VkAntiLagStageAMD>(const VkAntiLagStageAMD& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_ANTI_LAG_STAGE_INPUT_AMD: return "VK_ANTI_LAG_STAGE_INPUT_AMD";
    case VK_ANTI_LAG_STAGE_PRESENT_AMD: return "VK_ANTI_LAG_STAGE_PRESENT_AMD";
    default: break;
    }
    return "Unhandled VkAntiLagStageAMD";
}

template <> std::string ToString<VkDepthClampModeEXT>(const VkDepthClampModeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DEPTH_CLAMP_MODE_VIEWPORT_RANGE_EXT: return "VK_DEPTH_CLAMP_MODE_VIEWPORT_RANGE_EXT";
    case VK_DEPTH_CLAMP_MODE_USER_DEFINED_RANGE_EXT: return "VK_DEPTH_CLAMP_MODE_USER_DEFINED_RANGE_EXT";
    default: break;
    }
    return "Unhandled VkDepthClampModeEXT";
}

template <> std::string ToString<VkShaderCodeTypeEXT>(const VkShaderCodeTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SHADER_CODE_TYPE_BINARY_EXT: return "VK_SHADER_CODE_TYPE_BINARY_EXT";
    case VK_SHADER_CODE_TYPE_SPIRV_EXT: return "VK_SHADER_CODE_TYPE_SPIRV_EXT";
    default: break;
    }
    return "Unhandled VkShaderCodeTypeEXT";
}

template <> std::string ToString<VkShaderCreateFlagBitsEXT>(const VkShaderCreateFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkShaderCreateFlagBitsEXT";
}

template <> std::string ToString<VkShaderCreateFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkShaderCreateFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkRayTracingInvocationReorderModeNV>(const VkRayTracingInvocationReorderModeNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_RAY_TRACING_INVOCATION_REORDER_MODE_NONE_NV: return "VK_RAY_TRACING_INVOCATION_REORDER_MODE_NONE_NV";
    case VK_RAY_TRACING_INVOCATION_REORDER_MODE_REORDER_NV: return "VK_RAY_TRACING_INVOCATION_REORDER_MODE_REORDER_NV";
    default: break;
    }
    return "Unhandled VkRayTracingInvocationReorderModeNV";
}

template <> std::string ToString<VkLayerSettingTypeEXT>(const VkLayerSettingTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_LAYER_SETTING_TYPE_BOOL32_EXT: return "VK_LAYER_SETTING_TYPE_BOOL32_EXT";
    case VK_LAYER_SETTING_TYPE_INT32_EXT: return "VK_LAYER_SETTING_TYPE_INT32_EXT";
    case VK_LAYER_SETTING_TYPE_INT64_EXT: return "VK_LAYER_SETTING_TYPE_INT64_EXT";
    case VK_LAYER_SETTING_TYPE_UINT32_EXT: return "VK_LAYER_SETTING_TYPE_UINT32_EXT";
    case VK_LAYER_SETTING_TYPE_UINT64_EXT: return "VK_LAYER_SETTING_TYPE_UINT64_EXT";
    case VK_LAYER_SETTING_TYPE_FLOAT32_EXT: return "VK_LAYER_SETTING_TYPE_FLOAT32_EXT";
    case VK_LAYER_SETTING_TYPE_FLOAT64_EXT: return "VK_LAYER_SETTING_TYPE_FLOAT64_EXT";
    case VK_LAYER_SETTING_TYPE_STRING_EXT: return "VK_LAYER_SETTING_TYPE_STRING_EXT";
    default: break;
    }
    return "Unhandled VkLayerSettingTypeEXT";
}

template <> std::string ToString<VkLatencyMarkerNV>(const VkLatencyMarkerNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_LATENCY_MARKER_SIMULATION_START_NV: return "VK_LATENCY_MARKER_SIMULATION_START_NV";
    case VK_LATENCY_MARKER_SIMULATION_END_NV: return "VK_LATENCY_MARKER_SIMULATION_END_NV";
    case VK_LATENCY_MARKER_RENDERSUBMIT_START_NV: return "VK_LATENCY_MARKER_RENDERSUBMIT_START_NV";
    case VK_LATENCY_MARKER_RENDERSUBMIT_END_NV: return "VK_LATENCY_MARKER_RENDERSUBMIT_END_NV";
    case VK_LATENCY_MARKER_PRESENT_START_NV: return "VK_LATENCY_MARKER_PRESENT_START_NV";
    case VK_LATENCY_MARKER_PRESENT_END_NV: return "VK_LATENCY_MARKER_PRESENT_END_NV";
    case VK_LATENCY_MARKER_INPUT_SAMPLE_NV: return "VK_LATENCY_MARKER_INPUT_SAMPLE_NV";
    case VK_LATENCY_MARKER_TRIGGER_FLASH_NV: return "VK_LATENCY_MARKER_TRIGGER_FLASH_NV";
    case VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_START_NV: return "VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_START_NV";
    case VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_END_NV: return "VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_END_NV";
    case VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_START_NV: return "VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_START_NV";
    case VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_END_NV: return "VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_END_NV";
    default: break;
    }
    return "Unhandled VkLatencyMarkerNV";
}

template <> std::string ToString<VkOutOfBandQueueTypeNV>(const VkOutOfBandQueueTypeNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_OUT_OF_BAND_QUEUE_TYPE_RENDER_NV: return "VK_OUT_OF_BAND_QUEUE_TYPE_RENDER_NV";
    case VK_OUT_OF_BAND_QUEUE_TYPE_PRESENT_NV: return "VK_OUT_OF_BAND_QUEUE_TYPE_PRESENT_NV";
    default: break;
    }
    return "Unhandled VkOutOfBandQueueTypeNV";
}

template <> std::string ToString<VkBlockMatchWindowCompareModeQCOM>(const VkBlockMatchWindowCompareModeQCOM& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MIN_QCOM: return "VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MIN_QCOM";
    case VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MAX_QCOM: return "VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MAX_QCOM";
    default: break;
    }
    return "Unhandled VkBlockMatchWindowCompareModeQCOM";
}

template <> std::string ToString<VkCubicFilterWeightsQCOM>(const VkCubicFilterWeightsQCOM& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_CUBIC_FILTER_WEIGHTS_CATMULL_ROM_QCOM: return "VK_CUBIC_FILTER_WEIGHTS_CATMULL_ROM_QCOM";
    case VK_CUBIC_FILTER_WEIGHTS_ZERO_TANGENT_CARDINAL_QCOM: return "VK_CUBIC_FILTER_WEIGHTS_ZERO_TANGENT_CARDINAL_QCOM";
    case VK_CUBIC_FILTER_WEIGHTS_B_SPLINE_QCOM: return "VK_CUBIC_FILTER_WEIGHTS_B_SPLINE_QCOM";
    case VK_CUBIC_FILTER_WEIGHTS_MITCHELL_NETRAVALI_QCOM: return "VK_CUBIC_FILTER_WEIGHTS_MITCHELL_NETRAVALI_QCOM";
    default: break;
    }
    return "Unhandled VkCubicFilterWeightsQCOM";
}

template <> std::string ToString<VkLayeredDriverUnderlyingApiMSFT>(const VkLayeredDriverUnderlyingApiMSFT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_LAYERED_DRIVER_UNDERLYING_API_NONE_MSFT: return "VK_LAYERED_DRIVER_UNDERLYING_API_NONE_MSFT";
    case VK_LAYERED_DRIVER_UNDERLYING_API_D3D12_MSFT: return "VK_LAYERED_DRIVER_UNDERLYING_API_D3D12_MSFT";
    default: break;
    }
    return "Unhandled VkLayeredDriverUnderlyingApiMSFT";
}

template <> std::string ToString<VkDisplaySurfaceStereoTypeNV>(const VkDisplaySurfaceStereoTypeNV& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_DISPLAY_SURFACE_STEREO_TYPE_NONE_NV: return "VK_DISPLAY_SURFACE_STEREO_TYPE_NONE_NV";
    case VK_DISPLAY_SURFACE_STEREO_TYPE_ONBOARD_DIN_NV: return "VK_DISPLAY_SURFACE_STEREO_TYPE_ONBOARD_DIN_NV";
    case VK_DISPLAY_SURFACE_STEREO_TYPE_HDMI_3D_NV: return "VK_DISPLAY_SURFACE_STEREO_TYPE_HDMI_3D_NV";
    case VK_DISPLAY_SURFACE_STEREO_TYPE_INBAND_DISPLAYPORT_NV: return "VK_DISPLAY_SURFACE_STEREO_TYPE_INBAND_DISPLAYPORT_NV";
    default: break;
    }
    return "Unhandled VkDisplaySurfaceStereoTypeNV";
}

template <> std::string ToString<VkIndirectCommandsInputModeFlagBitsEXT>(const VkIndirectCommandsInputModeFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkIndirectCommandsInputModeFlagBitsEXT";
}

template <> std::string ToString<VkIndirectCommandsInputModeFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkIndirectCommandsInputModeFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkIndirectCommandsLayoutUsageFlagBitsEXT>(const VkIndirectCommandsLayoutUsageFlagBitsEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkIndirectCommandsLayoutUsageFlagBitsEXT";
}

template <> std::string ToString<VkIndirectCommandsLayoutUsageFlagBitsEXT>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkIndirectCommandsLayoutUsageFlagBitsEXT>(vkFlags);
}

template <> std::string ToString<VkIndirectCommandsTokenTypeEXT>(const VkIndirectCommandsTokenTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_EXECUTION_SET_EXT";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_EXT: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_EXT";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_SEQUENCE_INDEX_EXT: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_SEQUENCE_INDEX_EXT";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_EXT";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_EXT";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_EXT: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_EXT";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_EXT: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_EXT";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_COUNT_EXT: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_COUNT_EXT";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_COUNT_EXT: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_COUNT_EXT";
    case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_EXT: return "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_EXT";
    default: break;
    }
    return "Unhandled VkIndirectCommandsTokenTypeEXT";
}

template <> std::string ToString<VkIndirectExecutionSetInfoTypeEXT>(const VkIndirectExecutionSetInfoTypeEXT& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT: return "VK_INDIRECT_EXECUTION_SET_INFO_TYPE_PIPELINES_EXT";
    case VK_INDIRECT_EXECUTION_SET_INFO_TYPE_SHADER_OBJECTS_EXT: return "VK_INDIRECT_EXECUTION_SET_INFO_TYPE_SHADER_OBJECTS_EXT";
    default: break;
    }
    return "Unhandled VkIndirectExecutionSetInfoTypeEXT";
}

template <> std::string ToString<VkAccelerationStructureCreateFlagBitsKHR>(const VkAccelerationStructureCreateFlagBitsKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    default: break;
    }
    return "Unhandled VkAccelerationStructureCreateFlagBitsKHR";
}

template <> std::string ToString<VkAccelerationStructureCreateFlagBitsKHR>(VkFlags vkFlags, ToStringFlags, uint32_t, uint32_t)
{
    return BitmaskToString<VkAccelerationStructureCreateFlagBitsKHR>(vkFlags);
}

template <> std::string ToString<VkBuildAccelerationStructureModeKHR>(const VkBuildAccelerationStructureModeKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR: return "VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR";
    case VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR: return "VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR";
    default: break;
    }
    return "Unhandled VkBuildAccelerationStructureModeKHR";
}

template <> std::string ToString<VkShaderGroupShaderKHR>(const VkShaderGroupShaderKHR& value, ToStringFlags, uint32_t, uint32_t)
{
    switch (value) {
    case VK_SHADER_GROUP_SHADER_GENERAL_KHR: return "VK_SHADER_GROUP_SHADER_GENERAL_KHR";
    case VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR: return "VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR";
    case VK_SHADER_GROUP_SHADER_ANY_HIT_KHR: return "VK_SHADER_GROUP_SHADER_ANY_HIT_KHR";
    case VK_SHADER_GROUP_SHADER_INTERSECTION_KHR: return "VK_SHADER_GROUP_SHADER_INTERSECTION_KHR";
    default: break;
    }
    return "Unhandled VkShaderGroupShaderKHR";
}

GFXRECON_END_NAMESPACE(util)
GFXRECON_END_NAMESPACE(gfxrecon)
