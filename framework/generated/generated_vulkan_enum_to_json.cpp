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

#include "generated_vulkan_enum_to_json.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

using util::JsonOptions;
using util::to_hex_fixed_width;

template<typename TFlags, typename ToStringFunctionType>
std::string ExpandFlags(TFlags flags, ToStringFunctionType toString)
{
    if (flags == 0)
    {
        return to_hex_fixed_width(flags);
    }
    uint32_t bit_number = 0;
    bool first = true;
    std::ostringstream ostr;
    while (flags != 0)
    {
        if (flags & 1)
        {
            if (!first) ostr << "|";
            ostr << toString((flags & 1) << bit_number);
            first = false;
        }
        bit_number++;
        flags = flags >> 1;
    }
    return ostr.str();
}


void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1ChromaSamplePosition& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_UNKNOWN:
            jdata = "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_UNKNOWN";
            break;
        case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_VERTICAL:
            jdata = "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_VERTICAL";
            break;
        case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_COLOCATED:
            jdata = "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_COLOCATED";
            break;
        case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_RESERVED:
            jdata = "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_RESERVED";
            break;
        case STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_INVALID:
            jdata = "STD_VIDEO_AV1_CHROMA_SAMPLE_POSITION_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1ColorPrimaries& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_709:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_709";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_UNSPECIFIED:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_UNSPECIFIED";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_M:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_M";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_B_G:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_470_B_G";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_601:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_601";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_240:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_240";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_GENERIC_FILM:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_GENERIC_FILM";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_BT_2020:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_BT_2020";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_XYZ:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_XYZ";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_431:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_431";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_432:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_SMPTE_432";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_EBU_3213:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_EBU_3213";
            break;
        case STD_VIDEO_AV1_COLOR_PRIMARIES_INVALID:
            jdata = "STD_VIDEO_AV1_COLOR_PRIMARIES_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1FrameRestorationType& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_NONE:
            jdata = "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_NONE";
            break;
        case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_WIENER:
            jdata = "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_WIENER";
            break;
        case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SGRPROJ:
            jdata = "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SGRPROJ";
            break;
        case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SWITCHABLE:
            jdata = "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_SWITCHABLE";
            break;
        case STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_INVALID:
            jdata = "STD_VIDEO_AV1_FRAME_RESTORATION_TYPE_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1FrameType& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_FRAME_TYPE_KEY:
            jdata = "STD_VIDEO_AV1_FRAME_TYPE_KEY";
            break;
        case STD_VIDEO_AV1_FRAME_TYPE_INTER:
            jdata = "STD_VIDEO_AV1_FRAME_TYPE_INTER";
            break;
        case STD_VIDEO_AV1_FRAME_TYPE_INTRA_ONLY:
            jdata = "STD_VIDEO_AV1_FRAME_TYPE_INTRA_ONLY";
            break;
        case STD_VIDEO_AV1_FRAME_TYPE_SWITCH:
            jdata = "STD_VIDEO_AV1_FRAME_TYPE_SWITCH";
            break;
        case STD_VIDEO_AV1_FRAME_TYPE_INVALID:
            jdata = "STD_VIDEO_AV1_FRAME_TYPE_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1InterpolationFilter& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP:
            jdata = "STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP";
            break;
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SMOOTH:
            jdata = "STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SMOOTH";
            break;
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SHARP:
            jdata = "STD_VIDEO_AV1_INTERPOLATION_FILTER_EIGHTTAP_SHARP";
            break;
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_BILINEAR:
            jdata = "STD_VIDEO_AV1_INTERPOLATION_FILTER_BILINEAR";
            break;
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_SWITCHABLE:
            jdata = "STD_VIDEO_AV1_INTERPOLATION_FILTER_SWITCHABLE";
            break;
        case STD_VIDEO_AV1_INTERPOLATION_FILTER_INVALID:
            jdata = "STD_VIDEO_AV1_INTERPOLATION_FILTER_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1Level& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_LEVEL_2_0:
            jdata = "STD_VIDEO_AV1_LEVEL_2_0";
            break;
        case STD_VIDEO_AV1_LEVEL_2_1:
            jdata = "STD_VIDEO_AV1_LEVEL_2_1";
            break;
        case STD_VIDEO_AV1_LEVEL_2_2:
            jdata = "STD_VIDEO_AV1_LEVEL_2_2";
            break;
        case STD_VIDEO_AV1_LEVEL_2_3:
            jdata = "STD_VIDEO_AV1_LEVEL_2_3";
            break;
        case STD_VIDEO_AV1_LEVEL_3_0:
            jdata = "STD_VIDEO_AV1_LEVEL_3_0";
            break;
        case STD_VIDEO_AV1_LEVEL_3_1:
            jdata = "STD_VIDEO_AV1_LEVEL_3_1";
            break;
        case STD_VIDEO_AV1_LEVEL_3_2:
            jdata = "STD_VIDEO_AV1_LEVEL_3_2";
            break;
        case STD_VIDEO_AV1_LEVEL_3_3:
            jdata = "STD_VIDEO_AV1_LEVEL_3_3";
            break;
        case STD_VIDEO_AV1_LEVEL_4_0:
            jdata = "STD_VIDEO_AV1_LEVEL_4_0";
            break;
        case STD_VIDEO_AV1_LEVEL_4_1:
            jdata = "STD_VIDEO_AV1_LEVEL_4_1";
            break;
        case STD_VIDEO_AV1_LEVEL_4_2:
            jdata = "STD_VIDEO_AV1_LEVEL_4_2";
            break;
        case STD_VIDEO_AV1_LEVEL_4_3:
            jdata = "STD_VIDEO_AV1_LEVEL_4_3";
            break;
        case STD_VIDEO_AV1_LEVEL_5_0:
            jdata = "STD_VIDEO_AV1_LEVEL_5_0";
            break;
        case STD_VIDEO_AV1_LEVEL_5_1:
            jdata = "STD_VIDEO_AV1_LEVEL_5_1";
            break;
        case STD_VIDEO_AV1_LEVEL_5_2:
            jdata = "STD_VIDEO_AV1_LEVEL_5_2";
            break;
        case STD_VIDEO_AV1_LEVEL_5_3:
            jdata = "STD_VIDEO_AV1_LEVEL_5_3";
            break;
        case STD_VIDEO_AV1_LEVEL_6_0:
            jdata = "STD_VIDEO_AV1_LEVEL_6_0";
            break;
        case STD_VIDEO_AV1_LEVEL_6_1:
            jdata = "STD_VIDEO_AV1_LEVEL_6_1";
            break;
        case STD_VIDEO_AV1_LEVEL_6_2:
            jdata = "STD_VIDEO_AV1_LEVEL_6_2";
            break;
        case STD_VIDEO_AV1_LEVEL_6_3:
            jdata = "STD_VIDEO_AV1_LEVEL_6_3";
            break;
        case STD_VIDEO_AV1_LEVEL_7_0:
            jdata = "STD_VIDEO_AV1_LEVEL_7_0";
            break;
        case STD_VIDEO_AV1_LEVEL_7_1:
            jdata = "STD_VIDEO_AV1_LEVEL_7_1";
            break;
        case STD_VIDEO_AV1_LEVEL_7_2:
            jdata = "STD_VIDEO_AV1_LEVEL_7_2";
            break;
        case STD_VIDEO_AV1_LEVEL_7_3:
            jdata = "STD_VIDEO_AV1_LEVEL_7_3";
            break;
        case STD_VIDEO_AV1_LEVEL_INVALID:
            jdata = "STD_VIDEO_AV1_LEVEL_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1MatrixCoefficients& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_IDENTITY:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_IDENTITY";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_709:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_709";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_UNSPECIFIED:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_UNSPECIFIED";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_RESERVED_3:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_RESERVED_3";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_FCC:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_FCC";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_470_B_G:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_470_B_G";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_601:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_601";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_240:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_240";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_YCGCO:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_YCGCO";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_NCL:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_NCL";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_CL:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_BT_2020_CL";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_2085:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_SMPTE_2085";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_NCL:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_NCL";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_CL:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_CHROMAT_CL";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_ICTCP:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_ICTCP";
            break;
        case STD_VIDEO_AV1_MATRIX_COEFFICIENTS_INVALID:
            jdata = "STD_VIDEO_AV1_MATRIX_COEFFICIENTS_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1Profile& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_PROFILE_MAIN:
            jdata = "STD_VIDEO_AV1_PROFILE_MAIN";
            break;
        case STD_VIDEO_AV1_PROFILE_HIGH:
            jdata = "STD_VIDEO_AV1_PROFILE_HIGH";
            break;
        case STD_VIDEO_AV1_PROFILE_PROFESSIONAL:
            jdata = "STD_VIDEO_AV1_PROFILE_PROFESSIONAL";
            break;
        case STD_VIDEO_AV1_PROFILE_INVALID:
            jdata = "STD_VIDEO_AV1_PROFILE_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1ReferenceName& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_REFERENCE_NAME_INTRA_FRAME:
            jdata = "STD_VIDEO_AV1_REFERENCE_NAME_INTRA_FRAME";
            break;
        case STD_VIDEO_AV1_REFERENCE_NAME_LAST_FRAME:
            jdata = "STD_VIDEO_AV1_REFERENCE_NAME_LAST_FRAME";
            break;
        case STD_VIDEO_AV1_REFERENCE_NAME_LAST2_FRAME:
            jdata = "STD_VIDEO_AV1_REFERENCE_NAME_LAST2_FRAME";
            break;
        case STD_VIDEO_AV1_REFERENCE_NAME_LAST3_FRAME:
            jdata = "STD_VIDEO_AV1_REFERENCE_NAME_LAST3_FRAME";
            break;
        case STD_VIDEO_AV1_REFERENCE_NAME_GOLDEN_FRAME:
            jdata = "STD_VIDEO_AV1_REFERENCE_NAME_GOLDEN_FRAME";
            break;
        case STD_VIDEO_AV1_REFERENCE_NAME_BWDREF_FRAME:
            jdata = "STD_VIDEO_AV1_REFERENCE_NAME_BWDREF_FRAME";
            break;
        case STD_VIDEO_AV1_REFERENCE_NAME_ALTREF2_FRAME:
            jdata = "STD_VIDEO_AV1_REFERENCE_NAME_ALTREF2_FRAME";
            break;
        case STD_VIDEO_AV1_REFERENCE_NAME_ALTREF_FRAME:
            jdata = "STD_VIDEO_AV1_REFERENCE_NAME_ALTREF_FRAME";
            break;
        case STD_VIDEO_AV1_REFERENCE_NAME_INVALID:
            jdata = "STD_VIDEO_AV1_REFERENCE_NAME_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1TransferCharacteristics& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_0:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_0";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_709:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_709";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_UNSPECIFIED:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_UNSPECIFIED";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_3:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_RESERVED_3";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_M:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_M";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_B_G:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_470_B_G";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_601:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_601";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_240:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_240";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LINEAR:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LINEAR";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100_SQRT10:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_LOG_100_SQRT10";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_IEC_61966:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_IEC_61966";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_1361:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_1361";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SRGB:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SRGB";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_10_BIT:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_10_BIT";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_12_BIT:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_BT_2020_12_BIT";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_2084:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_2084";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_428:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_SMPTE_428";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_HLG:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_HLG";
            break;
        case STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_INVALID:
            jdata = "STD_VIDEO_AV1_TRANSFER_CHARACTERISTICS_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoAV1TxMode& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_AV1_TX_MODE_ONLY_4X4:
            jdata = "STD_VIDEO_AV1_TX_MODE_ONLY_4X4";
            break;
        case STD_VIDEO_AV1_TX_MODE_LARGEST:
            jdata = "STD_VIDEO_AV1_TX_MODE_LARGEST";
            break;
        case STD_VIDEO_AV1_TX_MODE_SELECT:
            jdata = "STD_VIDEO_AV1_TX_MODE_SELECT";
            break;
        case STD_VIDEO_AV1_TX_MODE_INVALID:
            jdata = "STD_VIDEO_AV1_TX_MODE_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoDecodeH264FieldOrderCount& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_TOP:
            jdata = "STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_TOP";
            break;
        case STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_BOTTOM:
            jdata = "STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_BOTTOM";
            break;
        case STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_INVALID:
            jdata = "STD_VIDEO_DECODE_H264_FIELD_ORDER_COUNT_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264AspectRatioIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_UNSPECIFIED:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_UNSPECIFIED";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_SQUARE:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_SQUARE";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_12_11:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_12_11";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_10_11:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_10_11";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_16_11:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_16_11";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_40_33:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_40_33";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_24_11:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_24_11";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_20_11:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_20_11";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_32_11:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_32_11";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_80_33:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_80_33";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_18_11:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_18_11";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_15_11:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_15_11";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_64_33:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_64_33";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_160_99:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_160_99";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_4_3:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_4_3";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_3_2:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_3_2";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_2_1:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_2_1";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_EXTENDED_SAR:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_EXTENDED_SAR";
            break;
        case STD_VIDEO_H264_ASPECT_RATIO_IDC_INVALID:
            jdata = "STD_VIDEO_H264_ASPECT_RATIO_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264CabacInitIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_CABAC_INIT_IDC_0:
            jdata = "STD_VIDEO_H264_CABAC_INIT_IDC_0";
            break;
        case STD_VIDEO_H264_CABAC_INIT_IDC_1:
            jdata = "STD_VIDEO_H264_CABAC_INIT_IDC_1";
            break;
        case STD_VIDEO_H264_CABAC_INIT_IDC_2:
            jdata = "STD_VIDEO_H264_CABAC_INIT_IDC_2";
            break;
        case STD_VIDEO_H264_CABAC_INIT_IDC_INVALID:
            jdata = "STD_VIDEO_H264_CABAC_INIT_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264ChromaFormatIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_CHROMA_FORMAT_IDC_MONOCHROME:
            jdata = "STD_VIDEO_H264_CHROMA_FORMAT_IDC_MONOCHROME";
            break;
        case STD_VIDEO_H264_CHROMA_FORMAT_IDC_420:
            jdata = "STD_VIDEO_H264_CHROMA_FORMAT_IDC_420";
            break;
        case STD_VIDEO_H264_CHROMA_FORMAT_IDC_422:
            jdata = "STD_VIDEO_H264_CHROMA_FORMAT_IDC_422";
            break;
        case STD_VIDEO_H264_CHROMA_FORMAT_IDC_444:
            jdata = "STD_VIDEO_H264_CHROMA_FORMAT_IDC_444";
            break;
        case STD_VIDEO_H264_CHROMA_FORMAT_IDC_INVALID:
            jdata = "STD_VIDEO_H264_CHROMA_FORMAT_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264DisableDeblockingFilterIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_DISABLED:
            jdata = "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_DISABLED";
            break;
        case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_ENABLED:
            jdata = "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_ENABLED";
            break;
        case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_PARTIAL:
            jdata = "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_PARTIAL";
            break;
        case STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_INVALID:
            jdata = "STD_VIDEO_H264_DISABLE_DEBLOCKING_FILTER_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264LevelIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_LEVEL_IDC_1_0:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_1_0";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_1_1:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_1_1";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_1_2:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_1_2";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_1_3:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_1_3";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_2_0:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_2_0";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_2_1:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_2_1";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_2_2:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_2_2";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_3_0:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_3_0";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_3_1:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_3_1";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_3_2:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_3_2";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_4_0:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_4_0";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_4_1:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_4_1";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_4_2:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_4_2";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_5_0:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_5_0";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_5_1:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_5_1";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_5_2:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_5_2";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_6_0:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_6_0";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_6_1:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_6_1";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_6_2:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_6_2";
            break;
        case STD_VIDEO_H264_LEVEL_IDC_INVALID:
            jdata = "STD_VIDEO_H264_LEVEL_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264MemMgmtControlOp& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_END:
            jdata = "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_END";
            break;
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_SHORT_TERM:
            jdata = "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_SHORT_TERM";
            break;
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_LONG_TERM:
            jdata = "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_LONG_TERM";
            break;
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_LONG_TERM:
            jdata = "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_LONG_TERM";
            break;
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_SET_MAX_LONG_TERM_INDEX:
            jdata = "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_SET_MAX_LONG_TERM_INDEX";
            break;
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_ALL:
            jdata = "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_UNMARK_ALL";
            break;
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_CURRENT_AS_LONG_TERM:
            jdata = "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_MARK_CURRENT_AS_LONG_TERM";
            break;
        case STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_INVALID:
            jdata = "STD_VIDEO_H264_MEM_MGMT_CONTROL_OP_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264ModificationOfPicNumsIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_SUBTRACT:
            jdata = "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_SUBTRACT";
            break;
        case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_ADD:
            jdata = "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_SHORT_TERM_ADD";
            break;
        case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_LONG_TERM:
            jdata = "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_LONG_TERM";
            break;
        case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_END:
            jdata = "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_END";
            break;
        case STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_INVALID:
            jdata = "STD_VIDEO_H264_MODIFICATION_OF_PIC_NUMS_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264NonVclNaluType& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_SPS:
            jdata = "STD_VIDEO_H264_NON_VCL_NALU_TYPE_SPS";
            break;
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_PPS:
            jdata = "STD_VIDEO_H264_NON_VCL_NALU_TYPE_PPS";
            break;
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_AUD:
            jdata = "STD_VIDEO_H264_NON_VCL_NALU_TYPE_AUD";
            break;
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_PREFIX:
            jdata = "STD_VIDEO_H264_NON_VCL_NALU_TYPE_PREFIX";
            break;
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_SEQUENCE:
            jdata = "STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_SEQUENCE";
            break;
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_STREAM:
            jdata = "STD_VIDEO_H264_NON_VCL_NALU_TYPE_END_OF_STREAM";
            break;
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_PRECODED:
            jdata = "STD_VIDEO_H264_NON_VCL_NALU_TYPE_PRECODED";
            break;
        case STD_VIDEO_H264_NON_VCL_NALU_TYPE_INVALID:
            jdata = "STD_VIDEO_H264_NON_VCL_NALU_TYPE_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264PictureType& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_PICTURE_TYPE_P:
            jdata = "STD_VIDEO_H264_PICTURE_TYPE_P";
            break;
        case STD_VIDEO_H264_PICTURE_TYPE_B:
            jdata = "STD_VIDEO_H264_PICTURE_TYPE_B";
            break;
        case STD_VIDEO_H264_PICTURE_TYPE_I:
            jdata = "STD_VIDEO_H264_PICTURE_TYPE_I";
            break;
        case STD_VIDEO_H264_PICTURE_TYPE_IDR:
            jdata = "STD_VIDEO_H264_PICTURE_TYPE_IDR";
            break;
        case STD_VIDEO_H264_PICTURE_TYPE_INVALID:
            jdata = "STD_VIDEO_H264_PICTURE_TYPE_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264PocType& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_POC_TYPE_0:
            jdata = "STD_VIDEO_H264_POC_TYPE_0";
            break;
        case STD_VIDEO_H264_POC_TYPE_1:
            jdata = "STD_VIDEO_H264_POC_TYPE_1";
            break;
        case STD_VIDEO_H264_POC_TYPE_2:
            jdata = "STD_VIDEO_H264_POC_TYPE_2";
            break;
        case STD_VIDEO_H264_POC_TYPE_INVALID:
            jdata = "STD_VIDEO_H264_POC_TYPE_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264ProfileIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_PROFILE_IDC_BASELINE:
            jdata = "STD_VIDEO_H264_PROFILE_IDC_BASELINE";
            break;
        case STD_VIDEO_H264_PROFILE_IDC_MAIN:
            jdata = "STD_VIDEO_H264_PROFILE_IDC_MAIN";
            break;
        case STD_VIDEO_H264_PROFILE_IDC_HIGH:
            jdata = "STD_VIDEO_H264_PROFILE_IDC_HIGH";
            break;
        case STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE:
            jdata = "STD_VIDEO_H264_PROFILE_IDC_HIGH_444_PREDICTIVE";
            break;
        case STD_VIDEO_H264_PROFILE_IDC_INVALID:
            jdata = "STD_VIDEO_H264_PROFILE_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264SliceType& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_SLICE_TYPE_P:
            jdata = "STD_VIDEO_H264_SLICE_TYPE_P";
            break;
        case STD_VIDEO_H264_SLICE_TYPE_B:
            jdata = "STD_VIDEO_H264_SLICE_TYPE_B";
            break;
        case STD_VIDEO_H264_SLICE_TYPE_I:
            jdata = "STD_VIDEO_H264_SLICE_TYPE_I";
            break;
        case STD_VIDEO_H264_SLICE_TYPE_INVALID:
            jdata = "STD_VIDEO_H264_SLICE_TYPE_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH264WeightedBipredIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_DEFAULT:
            jdata = "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_DEFAULT";
            break;
        case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_EXPLICIT:
            jdata = "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_EXPLICIT";
            break;
        case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_IMPLICIT:
            jdata = "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_IMPLICIT";
            break;
        case STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_INVALID:
            jdata = "STD_VIDEO_H264_WEIGHTED_BIPRED_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265AspectRatioIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_UNSPECIFIED:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_UNSPECIFIED";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_SQUARE:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_SQUARE";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_12_11:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_12_11";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_10_11:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_10_11";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_16_11:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_16_11";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_40_33:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_40_33";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_24_11:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_24_11";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_20_11:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_20_11";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_32_11:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_32_11";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_80_33:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_80_33";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_18_11:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_18_11";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_15_11:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_15_11";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_64_33:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_64_33";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_160_99:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_160_99";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_4_3:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_4_3";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_3_2:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_3_2";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_2_1:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_2_1";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_EXTENDED_SAR:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_EXTENDED_SAR";
            break;
        case STD_VIDEO_H265_ASPECT_RATIO_IDC_INVALID:
            jdata = "STD_VIDEO_H265_ASPECT_RATIO_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265ChromaFormatIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H265_CHROMA_FORMAT_IDC_MONOCHROME:
            jdata = "STD_VIDEO_H265_CHROMA_FORMAT_IDC_MONOCHROME";
            break;
        case STD_VIDEO_H265_CHROMA_FORMAT_IDC_420:
            jdata = "STD_VIDEO_H265_CHROMA_FORMAT_IDC_420";
            break;
        case STD_VIDEO_H265_CHROMA_FORMAT_IDC_422:
            jdata = "STD_VIDEO_H265_CHROMA_FORMAT_IDC_422";
            break;
        case STD_VIDEO_H265_CHROMA_FORMAT_IDC_444:
            jdata = "STD_VIDEO_H265_CHROMA_FORMAT_IDC_444";
            break;
        case STD_VIDEO_H265_CHROMA_FORMAT_IDC_INVALID:
            jdata = "STD_VIDEO_H265_CHROMA_FORMAT_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265LevelIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H265_LEVEL_IDC_1_0:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_1_0";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_2_0:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_2_0";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_2_1:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_2_1";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_3_0:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_3_0";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_3_1:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_3_1";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_4_0:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_4_0";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_4_1:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_4_1";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_5_0:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_5_0";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_5_1:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_5_1";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_5_2:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_5_2";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_6_0:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_6_0";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_6_1:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_6_1";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_6_2:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_6_2";
            break;
        case STD_VIDEO_H265_LEVEL_IDC_INVALID:
            jdata = "STD_VIDEO_H265_LEVEL_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265PictureType& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H265_PICTURE_TYPE_P:
            jdata = "STD_VIDEO_H265_PICTURE_TYPE_P";
            break;
        case STD_VIDEO_H265_PICTURE_TYPE_B:
            jdata = "STD_VIDEO_H265_PICTURE_TYPE_B";
            break;
        case STD_VIDEO_H265_PICTURE_TYPE_I:
            jdata = "STD_VIDEO_H265_PICTURE_TYPE_I";
            break;
        case STD_VIDEO_H265_PICTURE_TYPE_IDR:
            jdata = "STD_VIDEO_H265_PICTURE_TYPE_IDR";
            break;
        case STD_VIDEO_H265_PICTURE_TYPE_INVALID:
            jdata = "STD_VIDEO_H265_PICTURE_TYPE_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265ProfileIdc& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H265_PROFILE_IDC_MAIN:
            jdata = "STD_VIDEO_H265_PROFILE_IDC_MAIN";
            break;
        case STD_VIDEO_H265_PROFILE_IDC_MAIN_10:
            jdata = "STD_VIDEO_H265_PROFILE_IDC_MAIN_10";
            break;
        case STD_VIDEO_H265_PROFILE_IDC_MAIN_STILL_PICTURE:
            jdata = "STD_VIDEO_H265_PROFILE_IDC_MAIN_STILL_PICTURE";
            break;
        case STD_VIDEO_H265_PROFILE_IDC_FORMAT_RANGE_EXTENSIONS:
            jdata = "STD_VIDEO_H265_PROFILE_IDC_FORMAT_RANGE_EXTENSIONS";
            break;
        case STD_VIDEO_H265_PROFILE_IDC_SCC_EXTENSIONS:
            jdata = "STD_VIDEO_H265_PROFILE_IDC_SCC_EXTENSIONS";
            break;
        case STD_VIDEO_H265_PROFILE_IDC_INVALID:
            jdata = "STD_VIDEO_H265_PROFILE_IDC_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const StdVideoH265SliceType& value, const JsonOptions& options)
{
    switch (value) {
        case STD_VIDEO_H265_SLICE_TYPE_B:
            jdata = "STD_VIDEO_H265_SLICE_TYPE_B";
            break;
        case STD_VIDEO_H265_SLICE_TYPE_P:
            jdata = "STD_VIDEO_H265_SLICE_TYPE_P";
            break;
        case STD_VIDEO_H265_SLICE_TYPE_I:
            jdata = "STD_VIDEO_H265_SLICE_TYPE_I";
            break;
        case STD_VIDEO_H265_SLICE_TYPE_INVALID:
            jdata = "STD_VIDEO_H265_SLICE_TYPE_INVALID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureBuildTypeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR:
            jdata = "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR";
            break;
        case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR:
            jdata = "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR";
            break;
        case VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR:
            jdata = "VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureCompatibilityKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR:
            jdata = "VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR";
            break;
        case VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR:
            jdata = "VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureCreateFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR:
            jdata = "VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR";
            break;
        case VK_ACCELERATION_STRUCTURE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
            jdata = "VK_ACCELERATION_STRUCTURE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT";
            break;
        case VK_ACCELERATION_STRUCTURE_CREATE_MOTION_BIT_NV:
            jdata = "VK_ACCELERATION_STRUCTURE_CREATE_MOTION_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureMemoryRequirementsTypeNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV:
            jdata = "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV";
            break;
        case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV:
            jdata = "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV";
            break;
        case VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV:
            jdata = "VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureMotionInstanceTypeNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV:
            jdata = "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_STATIC_NV";
            break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV:
            jdata = "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_MATRIX_MOTION_NV";
            break;
        case VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV:
            jdata = "VK_ACCELERATION_STRUCTURE_MOTION_INSTANCE_TYPE_SRT_MOTION_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccelerationStructureTypeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR:
            jdata = "VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR";
            break;
        case VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR:
            jdata = "VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR";
            break;
        case VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR:
            jdata = "VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAccessFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ACCESS_INDIRECT_COMMAND_READ_BIT:
            jdata = "VK_ACCESS_INDIRECT_COMMAND_READ_BIT";
            break;
        case VK_ACCESS_INDEX_READ_BIT:
            jdata = "VK_ACCESS_INDEX_READ_BIT";
            break;
        case VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT:
            jdata = "VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT";
            break;
        case VK_ACCESS_UNIFORM_READ_BIT:
            jdata = "VK_ACCESS_UNIFORM_READ_BIT";
            break;
        case VK_ACCESS_INPUT_ATTACHMENT_READ_BIT:
            jdata = "VK_ACCESS_INPUT_ATTACHMENT_READ_BIT";
            break;
        case VK_ACCESS_SHADER_READ_BIT:
            jdata = "VK_ACCESS_SHADER_READ_BIT";
            break;
        case VK_ACCESS_SHADER_WRITE_BIT:
            jdata = "VK_ACCESS_SHADER_WRITE_BIT";
            break;
        case VK_ACCESS_COLOR_ATTACHMENT_READ_BIT:
            jdata = "VK_ACCESS_COLOR_ATTACHMENT_READ_BIT";
            break;
        case VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT:
            jdata = "VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT";
            break;
        case VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT:
            jdata = "VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT";
            break;
        case VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT:
            jdata = "VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT";
            break;
        case VK_ACCESS_TRANSFER_READ_BIT:
            jdata = "VK_ACCESS_TRANSFER_READ_BIT";
            break;
        case VK_ACCESS_TRANSFER_WRITE_BIT:
            jdata = "VK_ACCESS_TRANSFER_WRITE_BIT";
            break;
        case VK_ACCESS_HOST_READ_BIT:
            jdata = "VK_ACCESS_HOST_READ_BIT";
            break;
        case VK_ACCESS_HOST_WRITE_BIT:
            jdata = "VK_ACCESS_HOST_WRITE_BIT";
            break;
        case VK_ACCESS_MEMORY_READ_BIT:
            jdata = "VK_ACCESS_MEMORY_READ_BIT";
            break;
        case VK_ACCESS_MEMORY_WRITE_BIT:
            jdata = "VK_ACCESS_MEMORY_WRITE_BIT";
            break;
        case VK_ACCESS_NONE:
            jdata = "VK_ACCESS_NONE";
            break;
        case VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT:
            jdata = "VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT";
            break;
        case VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT:
            jdata = "VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT";
            break;
        case VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT:
            jdata = "VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT";
            break;
        case VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT:
            jdata = "VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT";
            break;
        case VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT:
            jdata = "VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT";
            break;
        case VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR:
            jdata = "VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR";
            break;
        case VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR:
            jdata = "VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR";
            break;
        case VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT:
            jdata = "VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT";
            break;
        case VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR:
            jdata = "VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR";
            break;
        case VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV:
            jdata = "VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV";
            break;
        case VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV:
            jdata = "VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(VkAccessFlagBits2_t, nlohmann::ordered_json& jdata, const VkAccessFlagBits2& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ACCESS_2_NONE:
            jdata = "VK_ACCESS_2_NONE";
            break;
        case VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT:
            jdata = "VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT";
            break;
        case VK_ACCESS_2_INDEX_READ_BIT:
            jdata = "VK_ACCESS_2_INDEX_READ_BIT";
            break;
        case VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT:
            jdata = "VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT";
            break;
        case VK_ACCESS_2_UNIFORM_READ_BIT:
            jdata = "VK_ACCESS_2_UNIFORM_READ_BIT";
            break;
        case VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT:
            jdata = "VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT";
            break;
        case VK_ACCESS_2_SHADER_READ_BIT:
            jdata = "VK_ACCESS_2_SHADER_READ_BIT";
            break;
        case VK_ACCESS_2_SHADER_WRITE_BIT:
            jdata = "VK_ACCESS_2_SHADER_WRITE_BIT";
            break;
        case VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT:
            jdata = "VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT";
            break;
        case VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT:
            jdata = "VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT";
            break;
        case VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT:
            jdata = "VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT";
            break;
        case VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT:
            jdata = "VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT";
            break;
        case VK_ACCESS_2_TRANSFER_READ_BIT:
            jdata = "VK_ACCESS_2_TRANSFER_READ_BIT";
            break;
        case VK_ACCESS_2_TRANSFER_WRITE_BIT:
            jdata = "VK_ACCESS_2_TRANSFER_WRITE_BIT";
            break;
        case VK_ACCESS_2_HOST_READ_BIT:
            jdata = "VK_ACCESS_2_HOST_READ_BIT";
            break;
        case VK_ACCESS_2_HOST_WRITE_BIT:
            jdata = "VK_ACCESS_2_HOST_WRITE_BIT";
            break;
        case VK_ACCESS_2_MEMORY_READ_BIT:
            jdata = "VK_ACCESS_2_MEMORY_READ_BIT";
            break;
        case VK_ACCESS_2_MEMORY_WRITE_BIT:
            jdata = "VK_ACCESS_2_MEMORY_WRITE_BIT";
            break;
        case VK_ACCESS_2_SHADER_SAMPLED_READ_BIT:
            jdata = "VK_ACCESS_2_SHADER_SAMPLED_READ_BIT";
            break;
        case VK_ACCESS_2_SHADER_STORAGE_READ_BIT:
            jdata = "VK_ACCESS_2_SHADER_STORAGE_READ_BIT";
            break;
        case VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT:
            jdata = "VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT";
            break;
        case VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR:
            jdata = "VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR";
            break;
        case VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR:
            jdata = "VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR";
            break;
        case VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR:
            jdata = "VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR";
            break;
        case VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR:
            jdata = "VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR";
            break;
        case VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT:
            jdata = "VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT";
            break;
        case VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT:
            jdata = "VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT";
            break;
        case VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_NV:
            jdata = "VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_NV";
            break;
        case VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_NV:
            jdata = "VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_NV";
            break;
        case VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR:
            jdata = "VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR";
            break;
        case VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR:
            jdata = "VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR";
            break;
        case VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR:
            jdata = "VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR";
            break;
        case VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT:
            jdata = "VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT";
            break;
        case VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI:
            jdata = "VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI";
            break;
        case VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR:
            jdata = "VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR";
            break;
        case VK_ACCESS_2_MICROMAP_READ_BIT_EXT:
            jdata = "VK_ACCESS_2_MICROMAP_READ_BIT_EXT";
            break;
        case VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT:
            jdata = "VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT";
            break;
        case VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV:
            jdata = "VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV";
            break;
        case VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV:
            jdata = "VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAcquireProfilingLockFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAttachmentDescriptionFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT:
            jdata = "VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAttachmentLoadOp& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ATTACHMENT_LOAD_OP_LOAD:
            jdata = "VK_ATTACHMENT_LOAD_OP_LOAD";
            break;
        case VK_ATTACHMENT_LOAD_OP_CLEAR:
            jdata = "VK_ATTACHMENT_LOAD_OP_CLEAR";
            break;
        case VK_ATTACHMENT_LOAD_OP_DONT_CARE:
            jdata = "VK_ATTACHMENT_LOAD_OP_DONT_CARE";
            break;
        case VK_ATTACHMENT_LOAD_OP_NONE_KHR:
            jdata = "VK_ATTACHMENT_LOAD_OP_NONE_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkAttachmentStoreOp& value, const JsonOptions& options)
{
    switch (value) {
        case VK_ATTACHMENT_STORE_OP_STORE:
            jdata = "VK_ATTACHMENT_STORE_OP_STORE";
            break;
        case VK_ATTACHMENT_STORE_OP_DONT_CARE:
            jdata = "VK_ATTACHMENT_STORE_OP_DONT_CARE";
            break;
        case VK_ATTACHMENT_STORE_OP_NONE:
            jdata = "VK_ATTACHMENT_STORE_OP_NONE";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBlendFactor& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BLEND_FACTOR_ZERO:
            jdata = "VK_BLEND_FACTOR_ZERO";
            break;
        case VK_BLEND_FACTOR_ONE:
            jdata = "VK_BLEND_FACTOR_ONE";
            break;
        case VK_BLEND_FACTOR_SRC_COLOR:
            jdata = "VK_BLEND_FACTOR_SRC_COLOR";
            break;
        case VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR:
            jdata = "VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR";
            break;
        case VK_BLEND_FACTOR_DST_COLOR:
            jdata = "VK_BLEND_FACTOR_DST_COLOR";
            break;
        case VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR:
            jdata = "VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR";
            break;
        case VK_BLEND_FACTOR_SRC_ALPHA:
            jdata = "VK_BLEND_FACTOR_SRC_ALPHA";
            break;
        case VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA:
            jdata = "VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA";
            break;
        case VK_BLEND_FACTOR_DST_ALPHA:
            jdata = "VK_BLEND_FACTOR_DST_ALPHA";
            break;
        case VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA:
            jdata = "VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA";
            break;
        case VK_BLEND_FACTOR_CONSTANT_COLOR:
            jdata = "VK_BLEND_FACTOR_CONSTANT_COLOR";
            break;
        case VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR:
            jdata = "VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR";
            break;
        case VK_BLEND_FACTOR_CONSTANT_ALPHA:
            jdata = "VK_BLEND_FACTOR_CONSTANT_ALPHA";
            break;
        case VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA:
            jdata = "VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA";
            break;
        case VK_BLEND_FACTOR_SRC_ALPHA_SATURATE:
            jdata = "VK_BLEND_FACTOR_SRC_ALPHA_SATURATE";
            break;
        case VK_BLEND_FACTOR_SRC1_COLOR:
            jdata = "VK_BLEND_FACTOR_SRC1_COLOR";
            break;
        case VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR:
            jdata = "VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR";
            break;
        case VK_BLEND_FACTOR_SRC1_ALPHA:
            jdata = "VK_BLEND_FACTOR_SRC1_ALPHA";
            break;
        case VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA:
            jdata = "VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBlendOp& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BLEND_OP_ADD:
            jdata = "VK_BLEND_OP_ADD";
            break;
        case VK_BLEND_OP_SUBTRACT:
            jdata = "VK_BLEND_OP_SUBTRACT";
            break;
        case VK_BLEND_OP_REVERSE_SUBTRACT:
            jdata = "VK_BLEND_OP_REVERSE_SUBTRACT";
            break;
        case VK_BLEND_OP_MIN:
            jdata = "VK_BLEND_OP_MIN";
            break;
        case VK_BLEND_OP_MAX:
            jdata = "VK_BLEND_OP_MAX";
            break;
        case VK_BLEND_OP_ZERO_EXT:
            jdata = "VK_BLEND_OP_ZERO_EXT";
            break;
        case VK_BLEND_OP_SRC_EXT:
            jdata = "VK_BLEND_OP_SRC_EXT";
            break;
        case VK_BLEND_OP_DST_EXT:
            jdata = "VK_BLEND_OP_DST_EXT";
            break;
        case VK_BLEND_OP_SRC_OVER_EXT:
            jdata = "VK_BLEND_OP_SRC_OVER_EXT";
            break;
        case VK_BLEND_OP_DST_OVER_EXT:
            jdata = "VK_BLEND_OP_DST_OVER_EXT";
            break;
        case VK_BLEND_OP_SRC_IN_EXT:
            jdata = "VK_BLEND_OP_SRC_IN_EXT";
            break;
        case VK_BLEND_OP_DST_IN_EXT:
            jdata = "VK_BLEND_OP_DST_IN_EXT";
            break;
        case VK_BLEND_OP_SRC_OUT_EXT:
            jdata = "VK_BLEND_OP_SRC_OUT_EXT";
            break;
        case VK_BLEND_OP_DST_OUT_EXT:
            jdata = "VK_BLEND_OP_DST_OUT_EXT";
            break;
        case VK_BLEND_OP_SRC_ATOP_EXT:
            jdata = "VK_BLEND_OP_SRC_ATOP_EXT";
            break;
        case VK_BLEND_OP_DST_ATOP_EXT:
            jdata = "VK_BLEND_OP_DST_ATOP_EXT";
            break;
        case VK_BLEND_OP_XOR_EXT:
            jdata = "VK_BLEND_OP_XOR_EXT";
            break;
        case VK_BLEND_OP_MULTIPLY_EXT:
            jdata = "VK_BLEND_OP_MULTIPLY_EXT";
            break;
        case VK_BLEND_OP_SCREEN_EXT:
            jdata = "VK_BLEND_OP_SCREEN_EXT";
            break;
        case VK_BLEND_OP_OVERLAY_EXT:
            jdata = "VK_BLEND_OP_OVERLAY_EXT";
            break;
        case VK_BLEND_OP_DARKEN_EXT:
            jdata = "VK_BLEND_OP_DARKEN_EXT";
            break;
        case VK_BLEND_OP_LIGHTEN_EXT:
            jdata = "VK_BLEND_OP_LIGHTEN_EXT";
            break;
        case VK_BLEND_OP_COLORDODGE_EXT:
            jdata = "VK_BLEND_OP_COLORDODGE_EXT";
            break;
        case VK_BLEND_OP_COLORBURN_EXT:
            jdata = "VK_BLEND_OP_COLORBURN_EXT";
            break;
        case VK_BLEND_OP_HARDLIGHT_EXT:
            jdata = "VK_BLEND_OP_HARDLIGHT_EXT";
            break;
        case VK_BLEND_OP_SOFTLIGHT_EXT:
            jdata = "VK_BLEND_OP_SOFTLIGHT_EXT";
            break;
        case VK_BLEND_OP_DIFFERENCE_EXT:
            jdata = "VK_BLEND_OP_DIFFERENCE_EXT";
            break;
        case VK_BLEND_OP_EXCLUSION_EXT:
            jdata = "VK_BLEND_OP_EXCLUSION_EXT";
            break;
        case VK_BLEND_OP_INVERT_EXT:
            jdata = "VK_BLEND_OP_INVERT_EXT";
            break;
        case VK_BLEND_OP_INVERT_RGB_EXT:
            jdata = "VK_BLEND_OP_INVERT_RGB_EXT";
            break;
        case VK_BLEND_OP_LINEARDODGE_EXT:
            jdata = "VK_BLEND_OP_LINEARDODGE_EXT";
            break;
        case VK_BLEND_OP_LINEARBURN_EXT:
            jdata = "VK_BLEND_OP_LINEARBURN_EXT";
            break;
        case VK_BLEND_OP_VIVIDLIGHT_EXT:
            jdata = "VK_BLEND_OP_VIVIDLIGHT_EXT";
            break;
        case VK_BLEND_OP_LINEARLIGHT_EXT:
            jdata = "VK_BLEND_OP_LINEARLIGHT_EXT";
            break;
        case VK_BLEND_OP_PINLIGHT_EXT:
            jdata = "VK_BLEND_OP_PINLIGHT_EXT";
            break;
        case VK_BLEND_OP_HARDMIX_EXT:
            jdata = "VK_BLEND_OP_HARDMIX_EXT";
            break;
        case VK_BLEND_OP_HSL_HUE_EXT:
            jdata = "VK_BLEND_OP_HSL_HUE_EXT";
            break;
        case VK_BLEND_OP_HSL_SATURATION_EXT:
            jdata = "VK_BLEND_OP_HSL_SATURATION_EXT";
            break;
        case VK_BLEND_OP_HSL_COLOR_EXT:
            jdata = "VK_BLEND_OP_HSL_COLOR_EXT";
            break;
        case VK_BLEND_OP_HSL_LUMINOSITY_EXT:
            jdata = "VK_BLEND_OP_HSL_LUMINOSITY_EXT";
            break;
        case VK_BLEND_OP_PLUS_EXT:
            jdata = "VK_BLEND_OP_PLUS_EXT";
            break;
        case VK_BLEND_OP_PLUS_CLAMPED_EXT:
            jdata = "VK_BLEND_OP_PLUS_CLAMPED_EXT";
            break;
        case VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT:
            jdata = "VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT";
            break;
        case VK_BLEND_OP_PLUS_DARKER_EXT:
            jdata = "VK_BLEND_OP_PLUS_DARKER_EXT";
            break;
        case VK_BLEND_OP_MINUS_EXT:
            jdata = "VK_BLEND_OP_MINUS_EXT";
            break;
        case VK_BLEND_OP_MINUS_CLAMPED_EXT:
            jdata = "VK_BLEND_OP_MINUS_CLAMPED_EXT";
            break;
        case VK_BLEND_OP_CONTRAST_EXT:
            jdata = "VK_BLEND_OP_CONTRAST_EXT";
            break;
        case VK_BLEND_OP_INVERT_OVG_EXT:
            jdata = "VK_BLEND_OP_INVERT_OVG_EXT";
            break;
        case VK_BLEND_OP_RED_EXT:
            jdata = "VK_BLEND_OP_RED_EXT";
            break;
        case VK_BLEND_OP_GREEN_EXT:
            jdata = "VK_BLEND_OP_GREEN_EXT";
            break;
        case VK_BLEND_OP_BLUE_EXT:
            jdata = "VK_BLEND_OP_BLUE_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBlendOverlapEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BLEND_OVERLAP_UNCORRELATED_EXT:
            jdata = "VK_BLEND_OVERLAP_UNCORRELATED_EXT";
            break;
        case VK_BLEND_OVERLAP_DISJOINT_EXT:
            jdata = "VK_BLEND_OVERLAP_DISJOINT_EXT";
            break;
        case VK_BLEND_OVERLAP_CONJOINT_EXT:
            jdata = "VK_BLEND_OVERLAP_CONJOINT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBlockMatchWindowCompareModeQCOM& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MIN_QCOM:
            jdata = "VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MIN_QCOM";
            break;
        case VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MAX_QCOM:
            jdata = "VK_BLOCK_MATCH_WINDOW_COMPARE_MODE_MAX_QCOM";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBorderColor& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK:
            jdata = "VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK";
            break;
        case VK_BORDER_COLOR_INT_TRANSPARENT_BLACK:
            jdata = "VK_BORDER_COLOR_INT_TRANSPARENT_BLACK";
            break;
        case VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK:
            jdata = "VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK";
            break;
        case VK_BORDER_COLOR_INT_OPAQUE_BLACK:
            jdata = "VK_BORDER_COLOR_INT_OPAQUE_BLACK";
            break;
        case VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE:
            jdata = "VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE";
            break;
        case VK_BORDER_COLOR_INT_OPAQUE_WHITE:
            jdata = "VK_BORDER_COLOR_INT_OPAQUE_WHITE";
            break;
        case VK_BORDER_COLOR_FLOAT_CUSTOM_EXT:
            jdata = "VK_BORDER_COLOR_FLOAT_CUSTOM_EXT";
            break;
        case VK_BORDER_COLOR_INT_CUSTOM_EXT:
            jdata = "VK_BORDER_COLOR_INT_CUSTOM_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBufferCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BUFFER_CREATE_SPARSE_BINDING_BIT:
            jdata = "VK_BUFFER_CREATE_SPARSE_BINDING_BIT";
            break;
        case VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT:
            jdata = "VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT";
            break;
        case VK_BUFFER_CREATE_SPARSE_ALIASED_BIT:
            jdata = "VK_BUFFER_CREATE_SPARSE_ALIASED_BIT";
            break;
        case VK_BUFFER_CREATE_PROTECTED_BIT:
            jdata = "VK_BUFFER_CREATE_PROTECTED_BIT";
            break;
        case VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT:
            jdata = "VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT";
            break;
        case VK_BUFFER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
            jdata = "VK_BUFFER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT";
            break;
        case VK_BUFFER_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR:
            jdata = "VK_BUFFER_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBufferUsageFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BUFFER_USAGE_TRANSFER_SRC_BIT:
            jdata = "VK_BUFFER_USAGE_TRANSFER_SRC_BIT";
            break;
        case VK_BUFFER_USAGE_TRANSFER_DST_BIT:
            jdata = "VK_BUFFER_USAGE_TRANSFER_DST_BIT";
            break;
        case VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_STORAGE_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_STORAGE_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_INDEX_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_INDEX_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_VERTEX_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_VERTEX_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT:
            jdata = "VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT";
            break;
        case VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT:
            jdata = "VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT";
            break;
        case VK_BUFFER_USAGE_VIDEO_DECODE_SRC_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_VIDEO_DECODE_SRC_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_VIDEO_DECODE_DST_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_VIDEO_DECODE_DST_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_EXECUTION_GRAPH_SCRATCH_BIT_AMDX:
            jdata = "VK_BUFFER_USAGE_EXECUTION_GRAPH_SCRATCH_BIT_AMDX";
            break;
        case VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_VIDEO_ENCODE_DST_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_VIDEO_ENCODE_DST_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_VIDEO_ENCODE_SRC_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_VIDEO_ENCODE_SRC_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_MICROMAP_STORAGE_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_MICROMAP_STORAGE_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(VkBufferUsageFlagBits2KHR_t, nlohmann::ordered_json& jdata, const VkBufferUsageFlagBits2KHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_TRANSFER_DST_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_TRANSFER_DST_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_EXECUTION_GRAPH_SCRATCH_BIT_AMDX:
            jdata = "VK_BUFFER_USAGE_2_EXECUTION_GRAPH_SCRATCH_BIT_AMDX";
            break;
        case VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR:
            jdata = "VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR";
            break;
        case VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT";
            break;
        case VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT:
            jdata = "VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBuildAccelerationStructureFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_MOTION_BIT_NV:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_MOTION_BIT_NV";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_UPDATE_EXT:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_UPDATE_EXT";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISABLE_OPACITY_MICROMAPS_EXT:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISABLE_OPACITY_MICROMAPS_EXT";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_DATA_UPDATE_EXT:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_DATA_UPDATE_EXT";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISPLACEMENT_MICROMAP_UPDATE_NV:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISPLACEMENT_MICROMAP_UPDATE_NV";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DATA_ACCESS_KHR:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DATA_ACCESS_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBuildAccelerationStructureModeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR";
            break;
        case VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR:
            jdata = "VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBuildMicromapFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BUILD_MICROMAP_PREFER_FAST_TRACE_BIT_EXT:
            jdata = "VK_BUILD_MICROMAP_PREFER_FAST_TRACE_BIT_EXT";
            break;
        case VK_BUILD_MICROMAP_PREFER_FAST_BUILD_BIT_EXT:
            jdata = "VK_BUILD_MICROMAP_PREFER_FAST_BUILD_BIT_EXT";
            break;
        case VK_BUILD_MICROMAP_ALLOW_COMPACTION_BIT_EXT:
            jdata = "VK_BUILD_MICROMAP_ALLOW_COMPACTION_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkBuildMicromapModeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_BUILD_MICROMAP_MODE_BUILD_EXT:
            jdata = "VK_BUILD_MICROMAP_MODE_BUILD_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkChromaLocation& value, const JsonOptions& options)
{
    switch (value) {
        case VK_CHROMA_LOCATION_COSITED_EVEN:
            jdata = "VK_CHROMA_LOCATION_COSITED_EVEN";
            break;
        case VK_CHROMA_LOCATION_MIDPOINT:
            jdata = "VK_CHROMA_LOCATION_MIDPOINT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCoarseSampleOrderTypeNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV:
            jdata = "VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV";
            break;
        case VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV:
            jdata = "VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV";
            break;
        case VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV:
            jdata = "VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV";
            break;
        case VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV:
            jdata = "VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkColorComponentFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COLOR_COMPONENT_R_BIT:
            jdata = "VK_COLOR_COMPONENT_R_BIT";
            break;
        case VK_COLOR_COMPONENT_G_BIT:
            jdata = "VK_COLOR_COMPONENT_G_BIT";
            break;
        case VK_COLOR_COMPONENT_B_BIT:
            jdata = "VK_COLOR_COMPONENT_B_BIT";
            break;
        case VK_COLOR_COMPONENT_A_BIT:
            jdata = "VK_COLOR_COMPONENT_A_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkColorSpaceKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COLOR_SPACE_SRGB_NONLINEAR_KHR:
            jdata = "VK_COLOR_SPACE_SRGB_NONLINEAR_KHR";
            break;
        case VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT:
            jdata = "VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT";
            break;
        case VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT:
            jdata = "VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT";
            break;
        case VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT:
            jdata = "VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT";
            break;
        case VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT:
            jdata = "VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT";
            break;
        case VK_COLOR_SPACE_BT709_LINEAR_EXT:
            jdata = "VK_COLOR_SPACE_BT709_LINEAR_EXT";
            break;
        case VK_COLOR_SPACE_BT709_NONLINEAR_EXT:
            jdata = "VK_COLOR_SPACE_BT709_NONLINEAR_EXT";
            break;
        case VK_COLOR_SPACE_BT2020_LINEAR_EXT:
            jdata = "VK_COLOR_SPACE_BT2020_LINEAR_EXT";
            break;
        case VK_COLOR_SPACE_HDR10_ST2084_EXT:
            jdata = "VK_COLOR_SPACE_HDR10_ST2084_EXT";
            break;
        case VK_COLOR_SPACE_DOLBYVISION_EXT:
            jdata = "VK_COLOR_SPACE_DOLBYVISION_EXT";
            break;
        case VK_COLOR_SPACE_HDR10_HLG_EXT:
            jdata = "VK_COLOR_SPACE_HDR10_HLG_EXT";
            break;
        case VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT:
            jdata = "VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT";
            break;
        case VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT:
            jdata = "VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT";
            break;
        case VK_COLOR_SPACE_PASS_THROUGH_EXT:
            jdata = "VK_COLOR_SPACE_PASS_THROUGH_EXT";
            break;
        case VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT:
            jdata = "VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT";
            break;
        case VK_COLOR_SPACE_DISPLAY_NATIVE_AMD:
            jdata = "VK_COLOR_SPACE_DISPLAY_NATIVE_AMD";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandBufferLevel& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COMMAND_BUFFER_LEVEL_PRIMARY:
            jdata = "VK_COMMAND_BUFFER_LEVEL_PRIMARY";
            break;
        case VK_COMMAND_BUFFER_LEVEL_SECONDARY:
            jdata = "VK_COMMAND_BUFFER_LEVEL_SECONDARY";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandBufferResetFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT:
            jdata = "VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandBufferUsageFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT:
            jdata = "VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT";
            break;
        case VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT:
            jdata = "VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT";
            break;
        case VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT:
            jdata = "VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandPoolCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COMMAND_POOL_CREATE_TRANSIENT_BIT:
            jdata = "VK_COMMAND_POOL_CREATE_TRANSIENT_BIT";
            break;
        case VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT:
            jdata = "VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT";
            break;
        case VK_COMMAND_POOL_CREATE_PROTECTED_BIT:
            jdata = "VK_COMMAND_POOL_CREATE_PROTECTED_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCommandPoolResetFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT:
            jdata = "VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCompareOp& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COMPARE_OP_NEVER:
            jdata = "VK_COMPARE_OP_NEVER";
            break;
        case VK_COMPARE_OP_LESS:
            jdata = "VK_COMPARE_OP_LESS";
            break;
        case VK_COMPARE_OP_EQUAL:
            jdata = "VK_COMPARE_OP_EQUAL";
            break;
        case VK_COMPARE_OP_LESS_OR_EQUAL:
            jdata = "VK_COMPARE_OP_LESS_OR_EQUAL";
            break;
        case VK_COMPARE_OP_GREATER:
            jdata = "VK_COMPARE_OP_GREATER";
            break;
        case VK_COMPARE_OP_NOT_EQUAL:
            jdata = "VK_COMPARE_OP_NOT_EQUAL";
            break;
        case VK_COMPARE_OP_GREATER_OR_EQUAL:
            jdata = "VK_COMPARE_OP_GREATER_OR_EQUAL";
            break;
        case VK_COMPARE_OP_ALWAYS:
            jdata = "VK_COMPARE_OP_ALWAYS";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkComponentSwizzle& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COMPONENT_SWIZZLE_IDENTITY:
            jdata = "VK_COMPONENT_SWIZZLE_IDENTITY";
            break;
        case VK_COMPONENT_SWIZZLE_ZERO:
            jdata = "VK_COMPONENT_SWIZZLE_ZERO";
            break;
        case VK_COMPONENT_SWIZZLE_ONE:
            jdata = "VK_COMPONENT_SWIZZLE_ONE";
            break;
        case VK_COMPONENT_SWIZZLE_R:
            jdata = "VK_COMPONENT_SWIZZLE_R";
            break;
        case VK_COMPONENT_SWIZZLE_G:
            jdata = "VK_COMPONENT_SWIZZLE_G";
            break;
        case VK_COMPONENT_SWIZZLE_B:
            jdata = "VK_COMPONENT_SWIZZLE_B";
            break;
        case VK_COMPONENT_SWIZZLE_A:
            jdata = "VK_COMPONENT_SWIZZLE_A";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkComponentTypeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COMPONENT_TYPE_FLOAT16_KHR:
            jdata = "VK_COMPONENT_TYPE_FLOAT16_KHR";
            break;
        case VK_COMPONENT_TYPE_FLOAT32_KHR:
            jdata = "VK_COMPONENT_TYPE_FLOAT32_KHR";
            break;
        case VK_COMPONENT_TYPE_FLOAT64_KHR:
            jdata = "VK_COMPONENT_TYPE_FLOAT64_KHR";
            break;
        case VK_COMPONENT_TYPE_SINT8_KHR:
            jdata = "VK_COMPONENT_TYPE_SINT8_KHR";
            break;
        case VK_COMPONENT_TYPE_SINT16_KHR:
            jdata = "VK_COMPONENT_TYPE_SINT16_KHR";
            break;
        case VK_COMPONENT_TYPE_SINT32_KHR:
            jdata = "VK_COMPONENT_TYPE_SINT32_KHR";
            break;
        case VK_COMPONENT_TYPE_SINT64_KHR:
            jdata = "VK_COMPONENT_TYPE_SINT64_KHR";
            break;
        case VK_COMPONENT_TYPE_UINT8_KHR:
            jdata = "VK_COMPONENT_TYPE_UINT8_KHR";
            break;
        case VK_COMPONENT_TYPE_UINT16_KHR:
            jdata = "VK_COMPONENT_TYPE_UINT16_KHR";
            break;
        case VK_COMPONENT_TYPE_UINT32_KHR:
            jdata = "VK_COMPONENT_TYPE_UINT32_KHR";
            break;
        case VK_COMPONENT_TYPE_UINT64_KHR:
            jdata = "VK_COMPONENT_TYPE_UINT64_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCompositeAlphaFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR:
            jdata = "VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR";
            break;
        case VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR:
            jdata = "VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR";
            break;
        case VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR:
            jdata = "VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR";
            break;
        case VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR:
            jdata = "VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkConditionalRenderingFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT:
            jdata = "VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkConservativeRasterizationModeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT:
            jdata = "VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT";
            break;
        case VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT:
            jdata = "VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT";
            break;
        case VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT:
            jdata = "VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCopyAccelerationStructureModeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR:
            jdata = "VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR";
            break;
        case VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR:
            jdata = "VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR";
            break;
        case VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR:
            jdata = "VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR";
            break;
        case VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR:
            jdata = "VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCopyMicromapModeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COPY_MICROMAP_MODE_CLONE_EXT:
            jdata = "VK_COPY_MICROMAP_MODE_CLONE_EXT";
            break;
        case VK_COPY_MICROMAP_MODE_SERIALIZE_EXT:
            jdata = "VK_COPY_MICROMAP_MODE_SERIALIZE_EXT";
            break;
        case VK_COPY_MICROMAP_MODE_DESERIALIZE_EXT:
            jdata = "VK_COPY_MICROMAP_MODE_DESERIALIZE_EXT";
            break;
        case VK_COPY_MICROMAP_MODE_COMPACT_EXT:
            jdata = "VK_COPY_MICROMAP_MODE_COMPACT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCoverageModulationModeNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COVERAGE_MODULATION_MODE_NONE_NV:
            jdata = "VK_COVERAGE_MODULATION_MODE_NONE_NV";
            break;
        case VK_COVERAGE_MODULATION_MODE_RGB_NV:
            jdata = "VK_COVERAGE_MODULATION_MODE_RGB_NV";
            break;
        case VK_COVERAGE_MODULATION_MODE_ALPHA_NV:
            jdata = "VK_COVERAGE_MODULATION_MODE_ALPHA_NV";
            break;
        case VK_COVERAGE_MODULATION_MODE_RGBA_NV:
            jdata = "VK_COVERAGE_MODULATION_MODE_RGBA_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCoverageReductionModeNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_COVERAGE_REDUCTION_MODE_MERGE_NV:
            jdata = "VK_COVERAGE_REDUCTION_MODE_MERGE_NV";
            break;
        case VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV:
            jdata = "VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCubicFilterWeightsQCOM& value, const JsonOptions& options)
{
    switch (value) {
        case VK_CUBIC_FILTER_WEIGHTS_CATMULL_ROM_QCOM:
            jdata = "VK_CUBIC_FILTER_WEIGHTS_CATMULL_ROM_QCOM";
            break;
        case VK_CUBIC_FILTER_WEIGHTS_ZERO_TANGENT_CARDINAL_QCOM:
            jdata = "VK_CUBIC_FILTER_WEIGHTS_ZERO_TANGENT_CARDINAL_QCOM";
            break;
        case VK_CUBIC_FILTER_WEIGHTS_B_SPLINE_QCOM:
            jdata = "VK_CUBIC_FILTER_WEIGHTS_B_SPLINE_QCOM";
            break;
        case VK_CUBIC_FILTER_WEIGHTS_MITCHELL_NETRAVALI_QCOM:
            jdata = "VK_CUBIC_FILTER_WEIGHTS_MITCHELL_NETRAVALI_QCOM";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkCullModeFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_CULL_MODE_NONE:
            jdata = "VK_CULL_MODE_NONE";
            break;
        case VK_CULL_MODE_FRONT_BIT:
            jdata = "VK_CULL_MODE_FRONT_BIT";
            break;
        case VK_CULL_MODE_BACK_BIT:
            jdata = "VK_CULL_MODE_BACK_BIT";
            break;
        case VK_CULL_MODE_FRONT_AND_BACK:
            jdata = "VK_CULL_MODE_FRONT_AND_BACK";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDebugReportFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEBUG_REPORT_INFORMATION_BIT_EXT:
            jdata = "VK_DEBUG_REPORT_INFORMATION_BIT_EXT";
            break;
        case VK_DEBUG_REPORT_WARNING_BIT_EXT:
            jdata = "VK_DEBUG_REPORT_WARNING_BIT_EXT";
            break;
        case VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT:
            jdata = "VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT";
            break;
        case VK_DEBUG_REPORT_ERROR_BIT_EXT:
            jdata = "VK_DEBUG_REPORT_ERROR_BIT_EXT";
            break;
        case VK_DEBUG_REPORT_DEBUG_BIT_EXT:
            jdata = "VK_DEBUG_REPORT_DEBUG_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDebugReportObjectTypeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_CU_MODULE_NVX_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_CU_MODULE_NVX_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_CU_FUNCTION_NVX_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_CU_FUNCTION_NVX_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_MODULE_NV_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_MODULE_NV_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_FUNCTION_NV_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_CUDA_FUNCTION_NV_EXT";
            break;
        case VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA_EXT:
            jdata = "VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDebugUtilsMessageSeverityFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
            jdata = "VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT";
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
            jdata = "VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT";
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
            jdata = "VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT";
            break;
        case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
            jdata = "VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDebugUtilsMessageTypeFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT:
            jdata = "VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT";
            break;
        case VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT:
            jdata = "VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT";
            break;
        case VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT:
            jdata = "VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT";
            break;
        case VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT:
            jdata = "VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDependencyFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEPENDENCY_BY_REGION_BIT:
            jdata = "VK_DEPENDENCY_BY_REGION_BIT";
            break;
        case VK_DEPENDENCY_DEVICE_GROUP_BIT:
            jdata = "VK_DEPENDENCY_DEVICE_GROUP_BIT";
            break;
        case VK_DEPENDENCY_VIEW_LOCAL_BIT:
            jdata = "VK_DEPENDENCY_VIEW_LOCAL_BIT";
            break;
        case VK_DEPENDENCY_FEEDBACK_LOOP_BIT_EXT:
            jdata = "VK_DEPENDENCY_FEEDBACK_LOOP_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDepthBiasRepresentationEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORMAT_EXT:
            jdata = "VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORMAT_EXT";
            break;
        case VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORCE_UNORM_EXT:
            jdata = "VK_DEPTH_BIAS_REPRESENTATION_LEAST_REPRESENTABLE_VALUE_FORCE_UNORM_EXT";
            break;
        case VK_DEPTH_BIAS_REPRESENTATION_FLOAT_EXT:
            jdata = "VK_DEPTH_BIAS_REPRESENTATION_FLOAT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorBindingFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT:
            jdata = "VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT";
            break;
        case VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT:
            jdata = "VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT";
            break;
        case VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT:
            jdata = "VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT";
            break;
        case VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT:
            jdata = "VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorPoolCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT:
            jdata = "VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT";
            break;
        case VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT:
            jdata = "VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT";
            break;
        case VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_EXT:
            jdata = "VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_EXT";
            break;
        case VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_SETS_BIT_NV:
            jdata = "VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_SETS_BIT_NV";
            break;
        case VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_POOLS_BIT_NV:
            jdata = "VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_POOLS_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorSetLayoutCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT:
            jdata = "VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT";
            break;
        case VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR:
            jdata = "VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR";
            break;
        case VK_DESCRIPTOR_SET_LAYOUT_CREATE_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_DESCRIPTOR_SET_LAYOUT_CREATE_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_DESCRIPTOR_SET_LAYOUT_CREATE_EMBEDDED_IMMUTABLE_SAMPLERS_BIT_EXT:
            jdata = "VK_DESCRIPTOR_SET_LAYOUT_CREATE_EMBEDDED_IMMUTABLE_SAMPLERS_BIT_EXT";
            break;
        case VK_DESCRIPTOR_SET_LAYOUT_CREATE_INDIRECT_BINDABLE_BIT_NV:
            jdata = "VK_DESCRIPTOR_SET_LAYOUT_CREATE_INDIRECT_BINDABLE_BIT_NV";
            break;
        case VK_DESCRIPTOR_SET_LAYOUT_CREATE_HOST_ONLY_POOL_BIT_EXT:
            jdata = "VK_DESCRIPTOR_SET_LAYOUT_CREATE_HOST_ONLY_POOL_BIT_EXT";
            break;
        case VK_DESCRIPTOR_SET_LAYOUT_CREATE_PER_STAGE_BIT_NV:
            jdata = "VK_DESCRIPTOR_SET_LAYOUT_CREATE_PER_STAGE_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DESCRIPTOR_TYPE_SAMPLER:
            jdata = "VK_DESCRIPTOR_TYPE_SAMPLER";
            break;
        case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
            jdata = "VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER";
            break;
        case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
            jdata = "VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE";
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
            jdata = "VK_DESCRIPTOR_TYPE_STORAGE_IMAGE";
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
            jdata = "VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER";
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
            jdata = "VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER";
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
            jdata = "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER";
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
            jdata = "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER";
            break;
        case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
            jdata = "VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC";
            break;
        case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
            jdata = "VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC";
            break;
        case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
            jdata = "VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT";
            break;
        case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
            jdata = "VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK";
            break;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
            jdata = "VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR";
            break;
        case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
            jdata = "VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV";
            break;
        case VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM:
            jdata = "VK_DESCRIPTOR_TYPE_SAMPLE_WEIGHT_IMAGE_QCOM";
            break;
        case VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM:
            jdata = "VK_DESCRIPTOR_TYPE_BLOCK_MATCH_IMAGE_QCOM";
            break;
        case VK_DESCRIPTOR_TYPE_MUTABLE_EXT:
            jdata = "VK_DESCRIPTOR_TYPE_MUTABLE_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDescriptorUpdateTemplateType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET:
            jdata = "VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET";
            break;
        case VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS_KHR:
            jdata = "VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceAddressBindingFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEVICE_ADDRESS_BINDING_INTERNAL_OBJECT_BIT_EXT:
            jdata = "VK_DEVICE_ADDRESS_BINDING_INTERNAL_OBJECT_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceAddressBindingTypeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEVICE_ADDRESS_BINDING_TYPE_BIND_EXT:
            jdata = "VK_DEVICE_ADDRESS_BINDING_TYPE_BIND_EXT";
            break;
        case VK_DEVICE_ADDRESS_BINDING_TYPE_UNBIND_EXT:
            jdata = "VK_DEVICE_ADDRESS_BINDING_TYPE_UNBIND_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceDiagnosticsConfigFlagBitsNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV:
            jdata = "VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV";
            break;
        case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV:
            jdata = "VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV";
            break;
        case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV:
            jdata = "VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV";
            break;
        case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_ERROR_REPORTING_BIT_NV:
            jdata = "VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_ERROR_REPORTING_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceEventTypeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT:
            jdata = "VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceFaultAddressTypeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEVICE_FAULT_ADDRESS_TYPE_NONE_EXT:
            jdata = "VK_DEVICE_FAULT_ADDRESS_TYPE_NONE_EXT";
            break;
        case VK_DEVICE_FAULT_ADDRESS_TYPE_READ_INVALID_EXT:
            jdata = "VK_DEVICE_FAULT_ADDRESS_TYPE_READ_INVALID_EXT";
            break;
        case VK_DEVICE_FAULT_ADDRESS_TYPE_WRITE_INVALID_EXT:
            jdata = "VK_DEVICE_FAULT_ADDRESS_TYPE_WRITE_INVALID_EXT";
            break;
        case VK_DEVICE_FAULT_ADDRESS_TYPE_EXECUTE_INVALID_EXT:
            jdata = "VK_DEVICE_FAULT_ADDRESS_TYPE_EXECUTE_INVALID_EXT";
            break;
        case VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_UNKNOWN_EXT:
            jdata = "VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_UNKNOWN_EXT";
            break;
        case VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_INVALID_EXT:
            jdata = "VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_INVALID_EXT";
            break;
        case VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_FAULT_EXT:
            jdata = "VK_DEVICE_FAULT_ADDRESS_TYPE_INSTRUCTION_POINTER_FAULT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceFaultVendorBinaryHeaderVersionEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEVICE_FAULT_VENDOR_BINARY_HEADER_VERSION_ONE_EXT:
            jdata = "VK_DEVICE_FAULT_VENDOR_BINARY_HEADER_VERSION_ONE_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceGroupPresentModeFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR:
            jdata = "VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR";
            break;
        case VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR:
            jdata = "VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR";
            break;
        case VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR:
            jdata = "VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR";
            break;
        case VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR:
            jdata = "VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceMemoryReportEventTypeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT:
            jdata = "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT";
            break;
        case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT:
            jdata = "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT";
            break;
        case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT:
            jdata = "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT";
            break;
        case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT:
            jdata = "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT";
            break;
        case VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT:
            jdata = "VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDeviceQueueCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT:
            jdata = "VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDirectDriverLoadingModeLUNARG& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG:
            jdata = "VK_DIRECT_DRIVER_LOADING_MODE_EXCLUSIVE_LUNARG";
            break;
        case VK_DIRECT_DRIVER_LOADING_MODE_INCLUSIVE_LUNARG:
            jdata = "VK_DIRECT_DRIVER_LOADING_MODE_INCLUSIVE_LUNARG";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDiscardRectangleModeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT:
            jdata = "VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT";
            break;
        case VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT:
            jdata = "VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplacementMicromapFormatNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DISPLACEMENT_MICROMAP_FORMAT_64_TRIANGLES_64_BYTES_NV:
            jdata = "VK_DISPLACEMENT_MICROMAP_FORMAT_64_TRIANGLES_64_BYTES_NV";
            break;
        case VK_DISPLACEMENT_MICROMAP_FORMAT_256_TRIANGLES_128_BYTES_NV:
            jdata = "VK_DISPLACEMENT_MICROMAP_FORMAT_256_TRIANGLES_128_BYTES_NV";
            break;
        case VK_DISPLACEMENT_MICROMAP_FORMAT_1024_TRIANGLES_128_BYTES_NV:
            jdata = "VK_DISPLACEMENT_MICROMAP_FORMAT_1024_TRIANGLES_128_BYTES_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplayEventTypeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT:
            jdata = "VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplayPlaneAlphaFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR:
            jdata = "VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR";
            break;
        case VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR:
            jdata = "VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR";
            break;
        case VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR:
            jdata = "VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR";
            break;
        case VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR:
            jdata = "VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDisplayPowerStateEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DISPLAY_POWER_STATE_OFF_EXT:
            jdata = "VK_DISPLAY_POWER_STATE_OFF_EXT";
            break;
        case VK_DISPLAY_POWER_STATE_SUSPEND_EXT:
            jdata = "VK_DISPLAY_POWER_STATE_SUSPEND_EXT";
            break;
        case VK_DISPLAY_POWER_STATE_ON_EXT:
            jdata = "VK_DISPLAY_POWER_STATE_ON_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDriverId& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DRIVER_ID_AMD_PROPRIETARY:
            jdata = "VK_DRIVER_ID_AMD_PROPRIETARY";
            break;
        case VK_DRIVER_ID_AMD_OPEN_SOURCE:
            jdata = "VK_DRIVER_ID_AMD_OPEN_SOURCE";
            break;
        case VK_DRIVER_ID_MESA_RADV:
            jdata = "VK_DRIVER_ID_MESA_RADV";
            break;
        case VK_DRIVER_ID_NVIDIA_PROPRIETARY:
            jdata = "VK_DRIVER_ID_NVIDIA_PROPRIETARY";
            break;
        case VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS:
            jdata = "VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS";
            break;
        case VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA:
            jdata = "VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA";
            break;
        case VK_DRIVER_ID_IMAGINATION_PROPRIETARY:
            jdata = "VK_DRIVER_ID_IMAGINATION_PROPRIETARY";
            break;
        case VK_DRIVER_ID_QUALCOMM_PROPRIETARY:
            jdata = "VK_DRIVER_ID_QUALCOMM_PROPRIETARY";
            break;
        case VK_DRIVER_ID_ARM_PROPRIETARY:
            jdata = "VK_DRIVER_ID_ARM_PROPRIETARY";
            break;
        case VK_DRIVER_ID_GOOGLE_SWIFTSHADER:
            jdata = "VK_DRIVER_ID_GOOGLE_SWIFTSHADER";
            break;
        case VK_DRIVER_ID_GGP_PROPRIETARY:
            jdata = "VK_DRIVER_ID_GGP_PROPRIETARY";
            break;
        case VK_DRIVER_ID_BROADCOM_PROPRIETARY:
            jdata = "VK_DRIVER_ID_BROADCOM_PROPRIETARY";
            break;
        case VK_DRIVER_ID_MESA_LLVMPIPE:
            jdata = "VK_DRIVER_ID_MESA_LLVMPIPE";
            break;
        case VK_DRIVER_ID_MOLTENVK:
            jdata = "VK_DRIVER_ID_MOLTENVK";
            break;
        case VK_DRIVER_ID_COREAVI_PROPRIETARY:
            jdata = "VK_DRIVER_ID_COREAVI_PROPRIETARY";
            break;
        case VK_DRIVER_ID_JUICE_PROPRIETARY:
            jdata = "VK_DRIVER_ID_JUICE_PROPRIETARY";
            break;
        case VK_DRIVER_ID_VERISILICON_PROPRIETARY:
            jdata = "VK_DRIVER_ID_VERISILICON_PROPRIETARY";
            break;
        case VK_DRIVER_ID_MESA_TURNIP:
            jdata = "VK_DRIVER_ID_MESA_TURNIP";
            break;
        case VK_DRIVER_ID_MESA_V3DV:
            jdata = "VK_DRIVER_ID_MESA_V3DV";
            break;
        case VK_DRIVER_ID_MESA_PANVK:
            jdata = "VK_DRIVER_ID_MESA_PANVK";
            break;
        case VK_DRIVER_ID_SAMSUNG_PROPRIETARY:
            jdata = "VK_DRIVER_ID_SAMSUNG_PROPRIETARY";
            break;
        case VK_DRIVER_ID_MESA_VENUS:
            jdata = "VK_DRIVER_ID_MESA_VENUS";
            break;
        case VK_DRIVER_ID_MESA_DOZEN:
            jdata = "VK_DRIVER_ID_MESA_DOZEN";
            break;
        case VK_DRIVER_ID_MESA_NVK:
            jdata = "VK_DRIVER_ID_MESA_NVK";
            break;
        case VK_DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA:
            jdata = "VK_DRIVER_ID_IMAGINATION_OPEN_SOURCE_MESA";
            break;
        case VK_DRIVER_ID_MESA_AGXV:
            jdata = "VK_DRIVER_ID_MESA_AGXV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkDynamicState& value, const JsonOptions& options)
{
    switch (value) {
        case VK_DYNAMIC_STATE_VIEWPORT:
            jdata = "VK_DYNAMIC_STATE_VIEWPORT";
            break;
        case VK_DYNAMIC_STATE_SCISSOR:
            jdata = "VK_DYNAMIC_STATE_SCISSOR";
            break;
        case VK_DYNAMIC_STATE_LINE_WIDTH:
            jdata = "VK_DYNAMIC_STATE_LINE_WIDTH";
            break;
        case VK_DYNAMIC_STATE_DEPTH_BIAS:
            jdata = "VK_DYNAMIC_STATE_DEPTH_BIAS";
            break;
        case VK_DYNAMIC_STATE_BLEND_CONSTANTS:
            jdata = "VK_DYNAMIC_STATE_BLEND_CONSTANTS";
            break;
        case VK_DYNAMIC_STATE_DEPTH_BOUNDS:
            jdata = "VK_DYNAMIC_STATE_DEPTH_BOUNDS";
            break;
        case VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK:
            jdata = "VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK";
            break;
        case VK_DYNAMIC_STATE_STENCIL_WRITE_MASK:
            jdata = "VK_DYNAMIC_STATE_STENCIL_WRITE_MASK";
            break;
        case VK_DYNAMIC_STATE_STENCIL_REFERENCE:
            jdata = "VK_DYNAMIC_STATE_STENCIL_REFERENCE";
            break;
        case VK_DYNAMIC_STATE_CULL_MODE:
            jdata = "VK_DYNAMIC_STATE_CULL_MODE";
            break;
        case VK_DYNAMIC_STATE_FRONT_FACE:
            jdata = "VK_DYNAMIC_STATE_FRONT_FACE";
            break;
        case VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY:
            jdata = "VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY";
            break;
        case VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT:
            jdata = "VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT";
            break;
        case VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT:
            jdata = "VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT";
            break;
        case VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE:
            jdata = "VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE";
            break;
        case VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE:
            jdata = "VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE";
            break;
        case VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE:
            jdata = "VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE";
            break;
        case VK_DYNAMIC_STATE_DEPTH_COMPARE_OP:
            jdata = "VK_DYNAMIC_STATE_DEPTH_COMPARE_OP";
            break;
        case VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE:
            jdata = "VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE";
            break;
        case VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE:
            jdata = "VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE";
            break;
        case VK_DYNAMIC_STATE_STENCIL_OP:
            jdata = "VK_DYNAMIC_STATE_STENCIL_OP";
            break;
        case VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE:
            jdata = "VK_DYNAMIC_STATE_RASTERIZER_DISCARD_ENABLE";
            break;
        case VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE:
            jdata = "VK_DYNAMIC_STATE_DEPTH_BIAS_ENABLE";
            break;
        case VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE:
            jdata = "VK_DYNAMIC_STATE_PRIMITIVE_RESTART_ENABLE";
            break;
        case VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV:
            jdata = "VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV";
            break;
        case VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT:
            jdata = "VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT";
            break;
        case VK_DYNAMIC_STATE_DISCARD_RECTANGLE_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_DISCARD_RECTANGLE_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_DISCARD_RECTANGLE_MODE_EXT:
            jdata = "VK_DYNAMIC_STATE_DISCARD_RECTANGLE_MODE_EXT";
            break;
        case VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT:
            jdata = "VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT";
            break;
        case VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR:
            jdata = "VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR";
            break;
        case VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV:
            jdata = "VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV";
            break;
        case VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV:
            jdata = "VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV";
            break;
        case VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_ENABLE_NV:
            jdata = "VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_ENABLE_NV";
            break;
        case VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV:
            jdata = "VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV";
            break;
        case VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR:
            jdata = "VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR";
            break;
        case VK_DYNAMIC_STATE_VERTEX_INPUT_EXT:
            jdata = "VK_DYNAMIC_STATE_VERTEX_INPUT_EXT";
            break;
        case VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT:
            jdata = "VK_DYNAMIC_STATE_PATCH_CONTROL_POINTS_EXT";
            break;
        case VK_DYNAMIC_STATE_LOGIC_OP_EXT:
            jdata = "VK_DYNAMIC_STATE_LOGIC_OP_EXT";
            break;
        case VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_COLOR_WRITE_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_DEPTH_CLAMP_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_DEPTH_CLAMP_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_POLYGON_MODE_EXT:
            jdata = "VK_DYNAMIC_STATE_POLYGON_MODE_EXT";
            break;
        case VK_DYNAMIC_STATE_RASTERIZATION_SAMPLES_EXT:
            jdata = "VK_DYNAMIC_STATE_RASTERIZATION_SAMPLES_EXT";
            break;
        case VK_DYNAMIC_STATE_SAMPLE_MASK_EXT:
            jdata = "VK_DYNAMIC_STATE_SAMPLE_MASK_EXT";
            break;
        case VK_DYNAMIC_STATE_ALPHA_TO_COVERAGE_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_ALPHA_TO_COVERAGE_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_ALPHA_TO_ONE_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_ALPHA_TO_ONE_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_LOGIC_OP_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_LOGIC_OP_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_COLOR_BLEND_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_COLOR_BLEND_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_COLOR_BLEND_EQUATION_EXT:
            jdata = "VK_DYNAMIC_STATE_COLOR_BLEND_EQUATION_EXT";
            break;
        case VK_DYNAMIC_STATE_COLOR_WRITE_MASK_EXT:
            jdata = "VK_DYNAMIC_STATE_COLOR_WRITE_MASK_EXT";
            break;
        case VK_DYNAMIC_STATE_TESSELLATION_DOMAIN_ORIGIN_EXT:
            jdata = "VK_DYNAMIC_STATE_TESSELLATION_DOMAIN_ORIGIN_EXT";
            break;
        case VK_DYNAMIC_STATE_RASTERIZATION_STREAM_EXT:
            jdata = "VK_DYNAMIC_STATE_RASTERIZATION_STREAM_EXT";
            break;
        case VK_DYNAMIC_STATE_CONSERVATIVE_RASTERIZATION_MODE_EXT:
            jdata = "VK_DYNAMIC_STATE_CONSERVATIVE_RASTERIZATION_MODE_EXT";
            break;
        case VK_DYNAMIC_STATE_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT:
            jdata = "VK_DYNAMIC_STATE_EXTRA_PRIMITIVE_OVERESTIMATION_SIZE_EXT";
            break;
        case VK_DYNAMIC_STATE_DEPTH_CLIP_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_DEPTH_CLIP_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_COLOR_BLEND_ADVANCED_EXT:
            jdata = "VK_DYNAMIC_STATE_COLOR_BLEND_ADVANCED_EXT";
            break;
        case VK_DYNAMIC_STATE_PROVOKING_VERTEX_MODE_EXT:
            jdata = "VK_DYNAMIC_STATE_PROVOKING_VERTEX_MODE_EXT";
            break;
        case VK_DYNAMIC_STATE_LINE_RASTERIZATION_MODE_EXT:
            jdata = "VK_DYNAMIC_STATE_LINE_RASTERIZATION_MODE_EXT";
            break;
        case VK_DYNAMIC_STATE_LINE_STIPPLE_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_LINE_STIPPLE_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT:
            jdata = "VK_DYNAMIC_STATE_DEPTH_CLIP_NEGATIVE_ONE_TO_ONE_EXT";
            break;
        case VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_ENABLE_NV:
            jdata = "VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_ENABLE_NV";
            break;
        case VK_DYNAMIC_STATE_VIEWPORT_SWIZZLE_NV:
            jdata = "VK_DYNAMIC_STATE_VIEWPORT_SWIZZLE_NV";
            break;
        case VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_ENABLE_NV:
            jdata = "VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_ENABLE_NV";
            break;
        case VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_LOCATION_NV:
            jdata = "VK_DYNAMIC_STATE_COVERAGE_TO_COLOR_LOCATION_NV";
            break;
        case VK_DYNAMIC_STATE_COVERAGE_MODULATION_MODE_NV:
            jdata = "VK_DYNAMIC_STATE_COVERAGE_MODULATION_MODE_NV";
            break;
        case VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_ENABLE_NV:
            jdata = "VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_ENABLE_NV";
            break;
        case VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_NV:
            jdata = "VK_DYNAMIC_STATE_COVERAGE_MODULATION_TABLE_NV";
            break;
        case VK_DYNAMIC_STATE_SHADING_RATE_IMAGE_ENABLE_NV:
            jdata = "VK_DYNAMIC_STATE_SHADING_RATE_IMAGE_ENABLE_NV";
            break;
        case VK_DYNAMIC_STATE_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV:
            jdata = "VK_DYNAMIC_STATE_REPRESENTATIVE_FRAGMENT_TEST_ENABLE_NV";
            break;
        case VK_DYNAMIC_STATE_COVERAGE_REDUCTION_MODE_NV:
            jdata = "VK_DYNAMIC_STATE_COVERAGE_REDUCTION_MODE_NV";
            break;
        case VK_DYNAMIC_STATE_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT:
            jdata = "VK_DYNAMIC_STATE_ATTACHMENT_FEEDBACK_LOOP_ENABLE_EXT";
            break;
        case VK_DYNAMIC_STATE_LINE_STIPPLE_KHR:
            jdata = "VK_DYNAMIC_STATE_LINE_STIPPLE_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkEventCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_EVENT_CREATE_DEVICE_ONLY_BIT:
            jdata = "VK_EVENT_CREATE_DEVICE_ONLY_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalFenceFeatureFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT:
            jdata = "VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT";
            break;
        case VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT:
            jdata = "VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalFenceHandleTypeFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT:
            jdata = "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT";
            break;
        case VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT:
            jdata = "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT";
            break;
        case VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT:
            jdata = "VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT";
            break;
        case VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT:
            jdata = "VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalMemoryFeatureFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT:
            jdata = "VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT";
            break;
        case VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT:
            jdata = "VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT";
            break;
        case VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT:
            jdata = "VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalMemoryFeatureFlagBitsNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV:
            jdata = "VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV";
            break;
        case VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV:
            jdata = "VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV";
            break;
        case VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV:
            jdata = "VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalMemoryHandleTypeFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_RDMA_ADDRESS_BIT_NV:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_RDMA_ADDRESS_BIT_NV";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_SCREEN_BUFFER_BIT_QNX:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_SCREEN_BUFFER_BIT_QNX";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalMemoryHandleTypeFlagBitsNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV";
            break;
        case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV:
            jdata = "VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalSemaphoreFeatureFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT:
            jdata = "VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT";
            break;
        case VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT:
            jdata = "VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkExternalSemaphoreHandleTypeFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT:
            jdata = "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT";
            break;
        case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT:
            jdata = "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT";
            break;
        case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT:
            jdata = "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT";
            break;
        case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT:
            jdata = "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT";
            break;
        case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT:
            jdata = "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT";
            break;
        case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA:
            jdata = "VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFenceCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FENCE_CREATE_SIGNALED_BIT:
            jdata = "VK_FENCE_CREATE_SIGNALED_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFenceImportFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FENCE_IMPORT_TEMPORARY_BIT:
            jdata = "VK_FENCE_IMPORT_TEMPORARY_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFilter& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FILTER_NEAREST:
            jdata = "VK_FILTER_NEAREST";
            break;
        case VK_FILTER_LINEAR:
            jdata = "VK_FILTER_LINEAR";
            break;
        case VK_FILTER_CUBIC_EXT:
            jdata = "VK_FILTER_CUBIC_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFormat& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FORMAT_UNDEFINED:
            jdata = "VK_FORMAT_UNDEFINED";
            break;
        case VK_FORMAT_R4G4_UNORM_PACK8:
            jdata = "VK_FORMAT_R4G4_UNORM_PACK8";
            break;
        case VK_FORMAT_R4G4B4A4_UNORM_PACK16:
            jdata = "VK_FORMAT_R4G4B4A4_UNORM_PACK16";
            break;
        case VK_FORMAT_B4G4R4A4_UNORM_PACK16:
            jdata = "VK_FORMAT_B4G4R4A4_UNORM_PACK16";
            break;
        case VK_FORMAT_R5G6B5_UNORM_PACK16:
            jdata = "VK_FORMAT_R5G6B5_UNORM_PACK16";
            break;
        case VK_FORMAT_B5G6R5_UNORM_PACK16:
            jdata = "VK_FORMAT_B5G6R5_UNORM_PACK16";
            break;
        case VK_FORMAT_R5G5B5A1_UNORM_PACK16:
            jdata = "VK_FORMAT_R5G5B5A1_UNORM_PACK16";
            break;
        case VK_FORMAT_B5G5R5A1_UNORM_PACK16:
            jdata = "VK_FORMAT_B5G5R5A1_UNORM_PACK16";
            break;
        case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
            jdata = "VK_FORMAT_A1R5G5B5_UNORM_PACK16";
            break;
        case VK_FORMAT_R8_UNORM:
            jdata = "VK_FORMAT_R8_UNORM";
            break;
        case VK_FORMAT_R8_SNORM:
            jdata = "VK_FORMAT_R8_SNORM";
            break;
        case VK_FORMAT_R8_USCALED:
            jdata = "VK_FORMAT_R8_USCALED";
            break;
        case VK_FORMAT_R8_SSCALED:
            jdata = "VK_FORMAT_R8_SSCALED";
            break;
        case VK_FORMAT_R8_UINT:
            jdata = "VK_FORMAT_R8_UINT";
            break;
        case VK_FORMAT_R8_SINT:
            jdata = "VK_FORMAT_R8_SINT";
            break;
        case VK_FORMAT_R8_SRGB:
            jdata = "VK_FORMAT_R8_SRGB";
            break;
        case VK_FORMAT_R8G8_UNORM:
            jdata = "VK_FORMAT_R8G8_UNORM";
            break;
        case VK_FORMAT_R8G8_SNORM:
            jdata = "VK_FORMAT_R8G8_SNORM";
            break;
        case VK_FORMAT_R8G8_USCALED:
            jdata = "VK_FORMAT_R8G8_USCALED";
            break;
        case VK_FORMAT_R8G8_SSCALED:
            jdata = "VK_FORMAT_R8G8_SSCALED";
            break;
        case VK_FORMAT_R8G8_UINT:
            jdata = "VK_FORMAT_R8G8_UINT";
            break;
        case VK_FORMAT_R8G8_SINT:
            jdata = "VK_FORMAT_R8G8_SINT";
            break;
        case VK_FORMAT_R8G8_SRGB:
            jdata = "VK_FORMAT_R8G8_SRGB";
            break;
        case VK_FORMAT_R8G8B8_UNORM:
            jdata = "VK_FORMAT_R8G8B8_UNORM";
            break;
        case VK_FORMAT_R8G8B8_SNORM:
            jdata = "VK_FORMAT_R8G8B8_SNORM";
            break;
        case VK_FORMAT_R8G8B8_USCALED:
            jdata = "VK_FORMAT_R8G8B8_USCALED";
            break;
        case VK_FORMAT_R8G8B8_SSCALED:
            jdata = "VK_FORMAT_R8G8B8_SSCALED";
            break;
        case VK_FORMAT_R8G8B8_UINT:
            jdata = "VK_FORMAT_R8G8B8_UINT";
            break;
        case VK_FORMAT_R8G8B8_SINT:
            jdata = "VK_FORMAT_R8G8B8_SINT";
            break;
        case VK_FORMAT_R8G8B8_SRGB:
            jdata = "VK_FORMAT_R8G8B8_SRGB";
            break;
        case VK_FORMAT_B8G8R8_UNORM:
            jdata = "VK_FORMAT_B8G8R8_UNORM";
            break;
        case VK_FORMAT_B8G8R8_SNORM:
            jdata = "VK_FORMAT_B8G8R8_SNORM";
            break;
        case VK_FORMAT_B8G8R8_USCALED:
            jdata = "VK_FORMAT_B8G8R8_USCALED";
            break;
        case VK_FORMAT_B8G8R8_SSCALED:
            jdata = "VK_FORMAT_B8G8R8_SSCALED";
            break;
        case VK_FORMAT_B8G8R8_UINT:
            jdata = "VK_FORMAT_B8G8R8_UINT";
            break;
        case VK_FORMAT_B8G8R8_SINT:
            jdata = "VK_FORMAT_B8G8R8_SINT";
            break;
        case VK_FORMAT_B8G8R8_SRGB:
            jdata = "VK_FORMAT_B8G8R8_SRGB";
            break;
        case VK_FORMAT_R8G8B8A8_UNORM:
            jdata = "VK_FORMAT_R8G8B8A8_UNORM";
            break;
        case VK_FORMAT_R8G8B8A8_SNORM:
            jdata = "VK_FORMAT_R8G8B8A8_SNORM";
            break;
        case VK_FORMAT_R8G8B8A8_USCALED:
            jdata = "VK_FORMAT_R8G8B8A8_USCALED";
            break;
        case VK_FORMAT_R8G8B8A8_SSCALED:
            jdata = "VK_FORMAT_R8G8B8A8_SSCALED";
            break;
        case VK_FORMAT_R8G8B8A8_UINT:
            jdata = "VK_FORMAT_R8G8B8A8_UINT";
            break;
        case VK_FORMAT_R8G8B8A8_SINT:
            jdata = "VK_FORMAT_R8G8B8A8_SINT";
            break;
        case VK_FORMAT_R8G8B8A8_SRGB:
            jdata = "VK_FORMAT_R8G8B8A8_SRGB";
            break;
        case VK_FORMAT_B8G8R8A8_UNORM:
            jdata = "VK_FORMAT_B8G8R8A8_UNORM";
            break;
        case VK_FORMAT_B8G8R8A8_SNORM:
            jdata = "VK_FORMAT_B8G8R8A8_SNORM";
            break;
        case VK_FORMAT_B8G8R8A8_USCALED:
            jdata = "VK_FORMAT_B8G8R8A8_USCALED";
            break;
        case VK_FORMAT_B8G8R8A8_SSCALED:
            jdata = "VK_FORMAT_B8G8R8A8_SSCALED";
            break;
        case VK_FORMAT_B8G8R8A8_UINT:
            jdata = "VK_FORMAT_B8G8R8A8_UINT";
            break;
        case VK_FORMAT_B8G8R8A8_SINT:
            jdata = "VK_FORMAT_B8G8R8A8_SINT";
            break;
        case VK_FORMAT_B8G8R8A8_SRGB:
            jdata = "VK_FORMAT_B8G8R8A8_SRGB";
            break;
        case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
            jdata = "VK_FORMAT_A8B8G8R8_UNORM_PACK32";
            break;
        case VK_FORMAT_A8B8G8R8_SNORM_PACK32:
            jdata = "VK_FORMAT_A8B8G8R8_SNORM_PACK32";
            break;
        case VK_FORMAT_A8B8G8R8_USCALED_PACK32:
            jdata = "VK_FORMAT_A8B8G8R8_USCALED_PACK32";
            break;
        case VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
            jdata = "VK_FORMAT_A8B8G8R8_SSCALED_PACK32";
            break;
        case VK_FORMAT_A8B8G8R8_UINT_PACK32:
            jdata = "VK_FORMAT_A8B8G8R8_UINT_PACK32";
            break;
        case VK_FORMAT_A8B8G8R8_SINT_PACK32:
            jdata = "VK_FORMAT_A8B8G8R8_SINT_PACK32";
            break;
        case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
            jdata = "VK_FORMAT_A8B8G8R8_SRGB_PACK32";
            break;
        case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
            jdata = "VK_FORMAT_A2R10G10B10_UNORM_PACK32";
            break;
        case VK_FORMAT_A2R10G10B10_SNORM_PACK32:
            jdata = "VK_FORMAT_A2R10G10B10_SNORM_PACK32";
            break;
        case VK_FORMAT_A2R10G10B10_USCALED_PACK32:
            jdata = "VK_FORMAT_A2R10G10B10_USCALED_PACK32";
            break;
        case VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
            jdata = "VK_FORMAT_A2R10G10B10_SSCALED_PACK32";
            break;
        case VK_FORMAT_A2R10G10B10_UINT_PACK32:
            jdata = "VK_FORMAT_A2R10G10B10_UINT_PACK32";
            break;
        case VK_FORMAT_A2R10G10B10_SINT_PACK32:
            jdata = "VK_FORMAT_A2R10G10B10_SINT_PACK32";
            break;
        case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
            jdata = "VK_FORMAT_A2B10G10R10_UNORM_PACK32";
            break;
        case VK_FORMAT_A2B10G10R10_SNORM_PACK32:
            jdata = "VK_FORMAT_A2B10G10R10_SNORM_PACK32";
            break;
        case VK_FORMAT_A2B10G10R10_USCALED_PACK32:
            jdata = "VK_FORMAT_A2B10G10R10_USCALED_PACK32";
            break;
        case VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
            jdata = "VK_FORMAT_A2B10G10R10_SSCALED_PACK32";
            break;
        case VK_FORMAT_A2B10G10R10_UINT_PACK32:
            jdata = "VK_FORMAT_A2B10G10R10_UINT_PACK32";
            break;
        case VK_FORMAT_A2B10G10R10_SINT_PACK32:
            jdata = "VK_FORMAT_A2B10G10R10_SINT_PACK32";
            break;
        case VK_FORMAT_R16_UNORM:
            jdata = "VK_FORMAT_R16_UNORM";
            break;
        case VK_FORMAT_R16_SNORM:
            jdata = "VK_FORMAT_R16_SNORM";
            break;
        case VK_FORMAT_R16_USCALED:
            jdata = "VK_FORMAT_R16_USCALED";
            break;
        case VK_FORMAT_R16_SSCALED:
            jdata = "VK_FORMAT_R16_SSCALED";
            break;
        case VK_FORMAT_R16_UINT:
            jdata = "VK_FORMAT_R16_UINT";
            break;
        case VK_FORMAT_R16_SINT:
            jdata = "VK_FORMAT_R16_SINT";
            break;
        case VK_FORMAT_R16_SFLOAT:
            jdata = "VK_FORMAT_R16_SFLOAT";
            break;
        case VK_FORMAT_R16G16_UNORM:
            jdata = "VK_FORMAT_R16G16_UNORM";
            break;
        case VK_FORMAT_R16G16_SNORM:
            jdata = "VK_FORMAT_R16G16_SNORM";
            break;
        case VK_FORMAT_R16G16_USCALED:
            jdata = "VK_FORMAT_R16G16_USCALED";
            break;
        case VK_FORMAT_R16G16_SSCALED:
            jdata = "VK_FORMAT_R16G16_SSCALED";
            break;
        case VK_FORMAT_R16G16_UINT:
            jdata = "VK_FORMAT_R16G16_UINT";
            break;
        case VK_FORMAT_R16G16_SINT:
            jdata = "VK_FORMAT_R16G16_SINT";
            break;
        case VK_FORMAT_R16G16_SFLOAT:
            jdata = "VK_FORMAT_R16G16_SFLOAT";
            break;
        case VK_FORMAT_R16G16B16_UNORM:
            jdata = "VK_FORMAT_R16G16B16_UNORM";
            break;
        case VK_FORMAT_R16G16B16_SNORM:
            jdata = "VK_FORMAT_R16G16B16_SNORM";
            break;
        case VK_FORMAT_R16G16B16_USCALED:
            jdata = "VK_FORMAT_R16G16B16_USCALED";
            break;
        case VK_FORMAT_R16G16B16_SSCALED:
            jdata = "VK_FORMAT_R16G16B16_SSCALED";
            break;
        case VK_FORMAT_R16G16B16_UINT:
            jdata = "VK_FORMAT_R16G16B16_UINT";
            break;
        case VK_FORMAT_R16G16B16_SINT:
            jdata = "VK_FORMAT_R16G16B16_SINT";
            break;
        case VK_FORMAT_R16G16B16_SFLOAT:
            jdata = "VK_FORMAT_R16G16B16_SFLOAT";
            break;
        case VK_FORMAT_R16G16B16A16_UNORM:
            jdata = "VK_FORMAT_R16G16B16A16_UNORM";
            break;
        case VK_FORMAT_R16G16B16A16_SNORM:
            jdata = "VK_FORMAT_R16G16B16A16_SNORM";
            break;
        case VK_FORMAT_R16G16B16A16_USCALED:
            jdata = "VK_FORMAT_R16G16B16A16_USCALED";
            break;
        case VK_FORMAT_R16G16B16A16_SSCALED:
            jdata = "VK_FORMAT_R16G16B16A16_SSCALED";
            break;
        case VK_FORMAT_R16G16B16A16_UINT:
            jdata = "VK_FORMAT_R16G16B16A16_UINT";
            break;
        case VK_FORMAT_R16G16B16A16_SINT:
            jdata = "VK_FORMAT_R16G16B16A16_SINT";
            break;
        case VK_FORMAT_R16G16B16A16_SFLOAT:
            jdata = "VK_FORMAT_R16G16B16A16_SFLOAT";
            break;
        case VK_FORMAT_R32_UINT:
            jdata = "VK_FORMAT_R32_UINT";
            break;
        case VK_FORMAT_R32_SINT:
            jdata = "VK_FORMAT_R32_SINT";
            break;
        case VK_FORMAT_R32_SFLOAT:
            jdata = "VK_FORMAT_R32_SFLOAT";
            break;
        case VK_FORMAT_R32G32_UINT:
            jdata = "VK_FORMAT_R32G32_UINT";
            break;
        case VK_FORMAT_R32G32_SINT:
            jdata = "VK_FORMAT_R32G32_SINT";
            break;
        case VK_FORMAT_R32G32_SFLOAT:
            jdata = "VK_FORMAT_R32G32_SFLOAT";
            break;
        case VK_FORMAT_R32G32B32_UINT:
            jdata = "VK_FORMAT_R32G32B32_UINT";
            break;
        case VK_FORMAT_R32G32B32_SINT:
            jdata = "VK_FORMAT_R32G32B32_SINT";
            break;
        case VK_FORMAT_R32G32B32_SFLOAT:
            jdata = "VK_FORMAT_R32G32B32_SFLOAT";
            break;
        case VK_FORMAT_R32G32B32A32_UINT:
            jdata = "VK_FORMAT_R32G32B32A32_UINT";
            break;
        case VK_FORMAT_R32G32B32A32_SINT:
            jdata = "VK_FORMAT_R32G32B32A32_SINT";
            break;
        case VK_FORMAT_R32G32B32A32_SFLOAT:
            jdata = "VK_FORMAT_R32G32B32A32_SFLOAT";
            break;
        case VK_FORMAT_R64_UINT:
            jdata = "VK_FORMAT_R64_UINT";
            break;
        case VK_FORMAT_R64_SINT:
            jdata = "VK_FORMAT_R64_SINT";
            break;
        case VK_FORMAT_R64_SFLOAT:
            jdata = "VK_FORMAT_R64_SFLOAT";
            break;
        case VK_FORMAT_R64G64_UINT:
            jdata = "VK_FORMAT_R64G64_UINT";
            break;
        case VK_FORMAT_R64G64_SINT:
            jdata = "VK_FORMAT_R64G64_SINT";
            break;
        case VK_FORMAT_R64G64_SFLOAT:
            jdata = "VK_FORMAT_R64G64_SFLOAT";
            break;
        case VK_FORMAT_R64G64B64_UINT:
            jdata = "VK_FORMAT_R64G64B64_UINT";
            break;
        case VK_FORMAT_R64G64B64_SINT:
            jdata = "VK_FORMAT_R64G64B64_SINT";
            break;
        case VK_FORMAT_R64G64B64_SFLOAT:
            jdata = "VK_FORMAT_R64G64B64_SFLOAT";
            break;
        case VK_FORMAT_R64G64B64A64_UINT:
            jdata = "VK_FORMAT_R64G64B64A64_UINT";
            break;
        case VK_FORMAT_R64G64B64A64_SINT:
            jdata = "VK_FORMAT_R64G64B64A64_SINT";
            break;
        case VK_FORMAT_R64G64B64A64_SFLOAT:
            jdata = "VK_FORMAT_R64G64B64A64_SFLOAT";
            break;
        case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
            jdata = "VK_FORMAT_B10G11R11_UFLOAT_PACK32";
            break;
        case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
            jdata = "VK_FORMAT_E5B9G9R9_UFLOAT_PACK32";
            break;
        case VK_FORMAT_D16_UNORM:
            jdata = "VK_FORMAT_D16_UNORM";
            break;
        case VK_FORMAT_X8_D24_UNORM_PACK32:
            jdata = "VK_FORMAT_X8_D24_UNORM_PACK32";
            break;
        case VK_FORMAT_D32_SFLOAT:
            jdata = "VK_FORMAT_D32_SFLOAT";
            break;
        case VK_FORMAT_S8_UINT:
            jdata = "VK_FORMAT_S8_UINT";
            break;
        case VK_FORMAT_D16_UNORM_S8_UINT:
            jdata = "VK_FORMAT_D16_UNORM_S8_UINT";
            break;
        case VK_FORMAT_D24_UNORM_S8_UINT:
            jdata = "VK_FORMAT_D24_UNORM_S8_UINT";
            break;
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            jdata = "VK_FORMAT_D32_SFLOAT_S8_UINT";
            break;
        case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
            jdata = "VK_FORMAT_BC1_RGB_UNORM_BLOCK";
            break;
        case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
            jdata = "VK_FORMAT_BC1_RGB_SRGB_BLOCK";
            break;
        case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
            jdata = "VK_FORMAT_BC1_RGBA_UNORM_BLOCK";
            break;
        case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
            jdata = "VK_FORMAT_BC1_RGBA_SRGB_BLOCK";
            break;
        case VK_FORMAT_BC2_UNORM_BLOCK:
            jdata = "VK_FORMAT_BC2_UNORM_BLOCK";
            break;
        case VK_FORMAT_BC2_SRGB_BLOCK:
            jdata = "VK_FORMAT_BC2_SRGB_BLOCK";
            break;
        case VK_FORMAT_BC3_UNORM_BLOCK:
            jdata = "VK_FORMAT_BC3_UNORM_BLOCK";
            break;
        case VK_FORMAT_BC3_SRGB_BLOCK:
            jdata = "VK_FORMAT_BC3_SRGB_BLOCK";
            break;
        case VK_FORMAT_BC4_UNORM_BLOCK:
            jdata = "VK_FORMAT_BC4_UNORM_BLOCK";
            break;
        case VK_FORMAT_BC4_SNORM_BLOCK:
            jdata = "VK_FORMAT_BC4_SNORM_BLOCK";
            break;
        case VK_FORMAT_BC5_UNORM_BLOCK:
            jdata = "VK_FORMAT_BC5_UNORM_BLOCK";
            break;
        case VK_FORMAT_BC5_SNORM_BLOCK:
            jdata = "VK_FORMAT_BC5_SNORM_BLOCK";
            break;
        case VK_FORMAT_BC6H_UFLOAT_BLOCK:
            jdata = "VK_FORMAT_BC6H_UFLOAT_BLOCK";
            break;
        case VK_FORMAT_BC6H_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_BC6H_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_BC7_UNORM_BLOCK:
            jdata = "VK_FORMAT_BC7_UNORM_BLOCK";
            break;
        case VK_FORMAT_BC7_SRGB_BLOCK:
            jdata = "VK_FORMAT_BC7_SRGB_BLOCK";
            break;
        case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
            jdata = "VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK";
            break;
        case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
            jdata = "VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK";
            break;
        case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
            jdata = "VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK";
            break;
        case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
            jdata = "VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK";
            break;
        case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
            jdata = "VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK";
            break;
        case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
            jdata = "VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK";
            break;
        case VK_FORMAT_EAC_R11_UNORM_BLOCK:
            jdata = "VK_FORMAT_EAC_R11_UNORM_BLOCK";
            break;
        case VK_FORMAT_EAC_R11_SNORM_BLOCK:
            jdata = "VK_FORMAT_EAC_R11_SNORM_BLOCK";
            break;
        case VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
            jdata = "VK_FORMAT_EAC_R11G11_UNORM_BLOCK";
            break;
        case VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
            jdata = "VK_FORMAT_EAC_R11G11_SNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_4x4_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_4x4_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_5x4_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_5x4_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_5x5_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_5x5_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_6x5_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_6x5_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_6x6_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_6x6_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_8x5_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_8x5_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_8x6_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_8x6_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_8x8_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_8x8_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x5_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x5_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x6_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x6_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x8_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x8_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x10_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x10_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_12x10_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_12x10_SRGB_BLOCK";
            break;
        case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
            jdata = "VK_FORMAT_ASTC_12x12_UNORM_BLOCK";
            break;
        case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
            jdata = "VK_FORMAT_ASTC_12x12_SRGB_BLOCK";
            break;
        case VK_FORMAT_G8B8G8R8_422_UNORM:
            jdata = "VK_FORMAT_G8B8G8R8_422_UNORM";
            break;
        case VK_FORMAT_B8G8R8G8_422_UNORM:
            jdata = "VK_FORMAT_B8G8R8G8_422_UNORM";
            break;
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
            jdata = "VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM";
            break;
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
            jdata = "VK_FORMAT_G8_B8R8_2PLANE_420_UNORM";
            break;
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
            jdata = "VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM";
            break;
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
            jdata = "VK_FORMAT_G8_B8R8_2PLANE_422_UNORM";
            break;
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
            jdata = "VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM";
            break;
        case VK_FORMAT_R10X6_UNORM_PACK16:
            jdata = "VK_FORMAT_R10X6_UNORM_PACK16";
            break;
        case VK_FORMAT_R10X6G10X6_UNORM_2PACK16:
            jdata = "VK_FORMAT_R10X6G10X6_UNORM_2PACK16";
            break;
        case VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16:
            jdata = "VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16";
            break;
        case VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16:
            jdata = "VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16";
            break;
        case VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16:
            jdata = "VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16";
            break;
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
            jdata = "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16";
            break;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
            jdata = "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16";
            break;
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
            jdata = "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16";
            break;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
            jdata = "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16";
            break;
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
            jdata = "VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16";
            break;
        case VK_FORMAT_R12X4_UNORM_PACK16:
            jdata = "VK_FORMAT_R12X4_UNORM_PACK16";
            break;
        case VK_FORMAT_R12X4G12X4_UNORM_2PACK16:
            jdata = "VK_FORMAT_R12X4G12X4_UNORM_2PACK16";
            break;
        case VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16:
            jdata = "VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16";
            break;
        case VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16:
            jdata = "VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16";
            break;
        case VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16:
            jdata = "VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16";
            break;
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
            jdata = "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16";
            break;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
            jdata = "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16";
            break;
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
            jdata = "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16";
            break;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
            jdata = "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16";
            break;
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
            jdata = "VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16";
            break;
        case VK_FORMAT_G16B16G16R16_422_UNORM:
            jdata = "VK_FORMAT_G16B16G16R16_422_UNORM";
            break;
        case VK_FORMAT_B16G16R16G16_422_UNORM:
            jdata = "VK_FORMAT_B16G16R16G16_422_UNORM";
            break;
        case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
            jdata = "VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM";
            break;
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
            jdata = "VK_FORMAT_G16_B16R16_2PLANE_420_UNORM";
            break;
        case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
            jdata = "VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM";
            break;
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
            jdata = "VK_FORMAT_G16_B16R16_2PLANE_422_UNORM";
            break;
        case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
            jdata = "VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM";
            break;
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM:
            jdata = "VK_FORMAT_G8_B8R8_2PLANE_444_UNORM";
            break;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16:
            jdata = "VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16";
            break;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16:
            jdata = "VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16";
            break;
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM:
            jdata = "VK_FORMAT_G16_B16R16_2PLANE_444_UNORM";
            break;
        case VK_FORMAT_A4R4G4B4_UNORM_PACK16:
            jdata = "VK_FORMAT_A4R4G4B4_UNORM_PACK16";
            break;
        case VK_FORMAT_A4B4G4R4_UNORM_PACK16:
            jdata = "VK_FORMAT_A4B4G4R4_UNORM_PACK16";
            break;
        case VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK:
            jdata = "VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK";
            break;
        case VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG:
            jdata = "VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG";
            break;
        case VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG:
            jdata = "VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG";
            break;
        case VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG:
            jdata = "VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG";
            break;
        case VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG:
            jdata = "VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG";
            break;
        case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
            jdata = "VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG";
            break;
        case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
            jdata = "VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG";
            break;
        case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
            jdata = "VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG";
            break;
        case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
            jdata = "VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG";
            break;
        case VK_FORMAT_R16G16_S10_5_NV:
            jdata = "VK_FORMAT_R16G16_S10_5_NV";
            break;
        case VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR:
            jdata = "VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR";
            break;
        case VK_FORMAT_A8_UNORM_KHR:
            jdata = "VK_FORMAT_A8_UNORM_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFormatFeatureFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT:
            jdata = "VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT";
            break;
        case VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT:
            jdata = "VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT";
            break;
        case VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT:
            jdata = "VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT";
            break;
        case VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT:
            jdata = "VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT";
            break;
        case VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT:
            jdata = "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT";
            break;
        case VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT:
            jdata = "VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT";
            break;
        case VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT:
            jdata = "VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT";
            break;
        case VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT:
            jdata = "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT";
            break;
        case VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT:
            jdata = "VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT";
            break;
        case VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT:
            jdata = "VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT";
            break;
        case VK_FORMAT_FEATURE_BLIT_SRC_BIT:
            jdata = "VK_FORMAT_FEATURE_BLIT_SRC_BIT";
            break;
        case VK_FORMAT_FEATURE_BLIT_DST_BIT:
            jdata = "VK_FORMAT_FEATURE_BLIT_DST_BIT";
            break;
        case VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT:
            jdata = "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT";
            break;
        case VK_FORMAT_FEATURE_TRANSFER_SRC_BIT:
            jdata = "VK_FORMAT_FEATURE_TRANSFER_SRC_BIT";
            break;
        case VK_FORMAT_FEATURE_TRANSFER_DST_BIT:
            jdata = "VK_FORMAT_FEATURE_TRANSFER_DST_BIT";
            break;
        case VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT:
            jdata = "VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT";
            break;
        case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT:
            jdata = "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT";
            break;
        case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT:
            jdata = "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT";
            break;
        case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT:
            jdata = "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT";
            break;
        case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT:
            jdata = "VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT";
            break;
        case VK_FORMAT_FEATURE_DISJOINT_BIT:
            jdata = "VK_FORMAT_FEATURE_DISJOINT_BIT";
            break;
        case VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT:
            jdata = "VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT";
            break;
        case VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT:
            jdata = "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT";
            break;
        case VK_FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT:
            jdata = "VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT";
            break;
        case VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT:
            jdata = "VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT";
            break;
        case VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(VkFormatFeatureFlagBits2_t, nlohmann::ordered_json& jdata, const VkFormatFeatureFlagBits2& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT";
            break;
        case VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT";
            break;
        case VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT:
            jdata = "VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT";
            break;
        case VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_BLIT_SRC_BIT:
            jdata = "VK_FORMAT_FEATURE_2_BLIT_SRC_BIT";
            break;
        case VK_FORMAT_FEATURE_2_BLIT_DST_BIT:
            jdata = "VK_FORMAT_FEATURE_2_BLIT_DST_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT";
            break;
        case VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT:
            jdata = "VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT";
            break;
        case VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT:
            jdata = "VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT";
            break;
        case VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT:
            jdata = "VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT";
            break;
        case VK_FORMAT_FEATURE_2_DISJOINT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_DISJOINT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT:
            jdata = "VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT:
            jdata = "VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT";
            break;
        case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT:
            jdata = "VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT";
            break;
        case VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT:
            jdata = "VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT";
            break;
        case VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT_EXT:
            jdata = "VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT_EXT";
            break;
        case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR:
            jdata = "VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR";
            break;
        case VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV:
            jdata = "VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV";
            break;
        case VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM:
            jdata = "VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM";
            break;
        case VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM:
            jdata = "VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM";
            break;
        case VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM:
            jdata = "VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM";
            break;
        case VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM:
            jdata = "VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM";
            break;
        case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV:
            jdata = "VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV";
            break;
        case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV:
            jdata = "VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV";
            break;
        case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV:
            jdata = "VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFragmentShadingRateCombinerOpKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR:
            jdata = "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR";
            break;
        case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR:
            jdata = "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR";
            break;
        case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR:
            jdata = "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR";
            break;
        case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR:
            jdata = "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR";
            break;
        case VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR:
            jdata = "VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFragmentShadingRateNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFragmentShadingRateTypeNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV";
            break;
        case VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV:
            jdata = "VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFrameBoundaryFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT:
            jdata = "VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFramebufferCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT:
            jdata = "VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFrontFace& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FRONT_FACE_COUNTER_CLOCKWISE:
            jdata = "VK_FRONT_FACE_COUNTER_CLOCKWISE";
            break;
        case VK_FRONT_FACE_CLOCKWISE:
            jdata = "VK_FRONT_FACE_CLOCKWISE";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkFullScreenExclusiveEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT:
            jdata = "VK_FULL_SCREEN_EXCLUSIVE_DEFAULT_EXT";
            break;
        case VK_FULL_SCREEN_EXCLUSIVE_ALLOWED_EXT:
            jdata = "VK_FULL_SCREEN_EXCLUSIVE_ALLOWED_EXT";
            break;
        case VK_FULL_SCREEN_EXCLUSIVE_DISALLOWED_EXT:
            jdata = "VK_FULL_SCREEN_EXCLUSIVE_DISALLOWED_EXT";
            break;
        case VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT:
            jdata = "VK_FULL_SCREEN_EXCLUSIVE_APPLICATION_CONTROLLED_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkGeometryFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_GEOMETRY_OPAQUE_BIT_KHR:
            jdata = "VK_GEOMETRY_OPAQUE_BIT_KHR";
            break;
        case VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR:
            jdata = "VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkGeometryInstanceFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR:
            jdata = "VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR";
            break;
        case VK_GEOMETRY_INSTANCE_TRIANGLE_FLIP_FACING_BIT_KHR:
            jdata = "VK_GEOMETRY_INSTANCE_TRIANGLE_FLIP_FACING_BIT_KHR";
            break;
        case VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR:
            jdata = "VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR";
            break;
        case VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR:
            jdata = "VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR";
            break;
        case VK_GEOMETRY_INSTANCE_FORCE_OPACITY_MICROMAP_2_STATE_EXT:
            jdata = "VK_GEOMETRY_INSTANCE_FORCE_OPACITY_MICROMAP_2_STATE_EXT";
            break;
        case VK_GEOMETRY_INSTANCE_DISABLE_OPACITY_MICROMAPS_EXT:
            jdata = "VK_GEOMETRY_INSTANCE_DISABLE_OPACITY_MICROMAPS_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkGeometryTypeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_GEOMETRY_TYPE_TRIANGLES_KHR:
            jdata = "VK_GEOMETRY_TYPE_TRIANGLES_KHR";
            break;
        case VK_GEOMETRY_TYPE_AABBS_KHR:
            jdata = "VK_GEOMETRY_TYPE_AABBS_KHR";
            break;
        case VK_GEOMETRY_TYPE_INSTANCES_KHR:
            jdata = "VK_GEOMETRY_TYPE_INSTANCES_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkGraphicsPipelineLibraryFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_GRAPHICS_PIPELINE_LIBRARY_VERTEX_INPUT_INTERFACE_BIT_EXT:
            jdata = "VK_GRAPHICS_PIPELINE_LIBRARY_VERTEX_INPUT_INTERFACE_BIT_EXT";
            break;
        case VK_GRAPHICS_PIPELINE_LIBRARY_PRE_RASTERIZATION_SHADERS_BIT_EXT:
            jdata = "VK_GRAPHICS_PIPELINE_LIBRARY_PRE_RASTERIZATION_SHADERS_BIT_EXT";
            break;
        case VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_SHADER_BIT_EXT:
            jdata = "VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_SHADER_BIT_EXT";
            break;
        case VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_OUTPUT_INTERFACE_BIT_EXT:
            jdata = "VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_OUTPUT_INTERFACE_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkHostImageCopyFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_HOST_IMAGE_COPY_MEMCPY_EXT:
            jdata = "VK_HOST_IMAGE_COPY_MEMCPY_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageAspectFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_IMAGE_ASPECT_COLOR_BIT:
            jdata = "VK_IMAGE_ASPECT_COLOR_BIT";
            break;
        case VK_IMAGE_ASPECT_DEPTH_BIT:
            jdata = "VK_IMAGE_ASPECT_DEPTH_BIT";
            break;
        case VK_IMAGE_ASPECT_STENCIL_BIT:
            jdata = "VK_IMAGE_ASPECT_STENCIL_BIT";
            break;
        case VK_IMAGE_ASPECT_METADATA_BIT:
            jdata = "VK_IMAGE_ASPECT_METADATA_BIT";
            break;
        case VK_IMAGE_ASPECT_PLANE_0_BIT:
            jdata = "VK_IMAGE_ASPECT_PLANE_0_BIT";
            break;
        case VK_IMAGE_ASPECT_PLANE_1_BIT:
            jdata = "VK_IMAGE_ASPECT_PLANE_1_BIT";
            break;
        case VK_IMAGE_ASPECT_PLANE_2_BIT:
            jdata = "VK_IMAGE_ASPECT_PLANE_2_BIT";
            break;
        case VK_IMAGE_ASPECT_NONE:
            jdata = "VK_IMAGE_ASPECT_NONE";
            break;
        case VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT:
            jdata = "VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT";
            break;
        case VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT:
            jdata = "VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT";
            break;
        case VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT:
            jdata = "VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT";
            break;
        case VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT:
            jdata = "VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageCompressionFixedRateFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_IMAGE_COMPRESSION_FIXED_RATE_NONE_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_NONE_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_1BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_1BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_2BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_2BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_3BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_3BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_4BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_4BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_5BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_5BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_6BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_6BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_7BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_7BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_8BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_8BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_9BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_9BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_10BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_10BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_11BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_11BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_12BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_12BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_13BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_13BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_14BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_14BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_15BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_15BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_16BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_16BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_17BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_17BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_18BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_18BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_19BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_19BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_20BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_20BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_21BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_21BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_22BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_22BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_23BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_23BPC_BIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_24BPC_BIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_24BPC_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageCompressionFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_IMAGE_COMPRESSION_DEFAULT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_DEFAULT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_DEFAULT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_DEFAULT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_FIXED_RATE_EXPLICIT_EXT:
            jdata = "VK_IMAGE_COMPRESSION_FIXED_RATE_EXPLICIT_EXT";
            break;
        case VK_IMAGE_COMPRESSION_DISABLED_EXT:
            jdata = "VK_IMAGE_COMPRESSION_DISABLED_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_IMAGE_CREATE_SPARSE_BINDING_BIT:
            jdata = "VK_IMAGE_CREATE_SPARSE_BINDING_BIT";
            break;
        case VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT:
            jdata = "VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT";
            break;
        case VK_IMAGE_CREATE_SPARSE_ALIASED_BIT:
            jdata = "VK_IMAGE_CREATE_SPARSE_ALIASED_BIT";
            break;
        case VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT:
            jdata = "VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT";
            break;
        case VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT:
            jdata = "VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT";
            break;
        case VK_IMAGE_CREATE_ALIAS_BIT:
            jdata = "VK_IMAGE_CREATE_ALIAS_BIT";
            break;
        case VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT:
            jdata = "VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT";
            break;
        case VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT:
            jdata = "VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT";
            break;
        case VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT:
            jdata = "VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT";
            break;
        case VK_IMAGE_CREATE_EXTENDED_USAGE_BIT:
            jdata = "VK_IMAGE_CREATE_EXTENDED_USAGE_BIT";
            break;
        case VK_IMAGE_CREATE_PROTECTED_BIT:
            jdata = "VK_IMAGE_CREATE_PROTECTED_BIT";
            break;
        case VK_IMAGE_CREATE_DISJOINT_BIT:
            jdata = "VK_IMAGE_CREATE_DISJOINT_BIT";
            break;
        case VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV:
            jdata = "VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV";
            break;
        case VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_2D_VIEW_COMPATIBLE_BIT_EXT:
            jdata = "VK_IMAGE_CREATE_2D_VIEW_COMPATIBLE_BIT_EXT";
            break;
        case VK_IMAGE_CREATE_FRAGMENT_DENSITY_MAP_OFFSET_BIT_QCOM:
            jdata = "VK_IMAGE_CREATE_FRAGMENT_DENSITY_MAP_OFFSET_BIT_QCOM";
            break;
        case VK_IMAGE_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR:
            jdata = "VK_IMAGE_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageLayout& value, const JsonOptions& options)
{
    switch (value) {
        case VK_IMAGE_LAYOUT_UNDEFINED:
            jdata = "VK_IMAGE_LAYOUT_UNDEFINED";
            break;
        case VK_IMAGE_LAYOUT_GENERAL:
            jdata = "VK_IMAGE_LAYOUT_GENERAL";
            break;
        case VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_PREINITIALIZED:
            jdata = "VK_IMAGE_LAYOUT_PREINITIALIZED";
            break;
        case VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL:
            jdata = "VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL";
            break;
        case VK_IMAGE_LAYOUT_PRESENT_SRC_KHR:
            jdata = "VK_IMAGE_LAYOUT_PRESENT_SRC_KHR";
            break;
        case VK_IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR:
            jdata = "VK_IMAGE_LAYOUT_VIDEO_DECODE_DST_KHR";
            break;
        case VK_IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR:
            jdata = "VK_IMAGE_LAYOUT_VIDEO_DECODE_SRC_KHR";
            break;
        case VK_IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR:
            jdata = "VK_IMAGE_LAYOUT_VIDEO_DECODE_DPB_KHR";
            break;
        case VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR:
            jdata = "VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR";
            break;
        case VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT:
            jdata = "VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT";
            break;
        case VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR:
            jdata = "VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR";
            break;
        case VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ_KHR:
            jdata = "VK_IMAGE_LAYOUT_RENDERING_LOCAL_READ_KHR";
            break;
        case VK_IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR:
            jdata = "VK_IMAGE_LAYOUT_VIDEO_ENCODE_DST_KHR";
            break;
        case VK_IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR:
            jdata = "VK_IMAGE_LAYOUT_VIDEO_ENCODE_SRC_KHR";
            break;
        case VK_IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR:
            jdata = "VK_IMAGE_LAYOUT_VIDEO_ENCODE_DPB_KHR";
            break;
        case VK_IMAGE_LAYOUT_ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT:
            jdata = "VK_IMAGE_LAYOUT_ATTACHMENT_FEEDBACK_LOOP_OPTIMAL_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageTiling& value, const JsonOptions& options)
{
    switch (value) {
        case VK_IMAGE_TILING_OPTIMAL:
            jdata = "VK_IMAGE_TILING_OPTIMAL";
            break;
        case VK_IMAGE_TILING_LINEAR:
            jdata = "VK_IMAGE_TILING_LINEAR";
            break;
        case VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT:
            jdata = "VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_IMAGE_TYPE_1D:
            jdata = "VK_IMAGE_TYPE_1D";
            break;
        case VK_IMAGE_TYPE_2D:
            jdata = "VK_IMAGE_TYPE_2D";
            break;
        case VK_IMAGE_TYPE_3D:
            jdata = "VK_IMAGE_TYPE_3D";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageUsageFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_IMAGE_USAGE_TRANSFER_SRC_BIT:
            jdata = "VK_IMAGE_USAGE_TRANSFER_SRC_BIT";
            break;
        case VK_IMAGE_USAGE_TRANSFER_DST_BIT:
            jdata = "VK_IMAGE_USAGE_TRANSFER_DST_BIT";
            break;
        case VK_IMAGE_USAGE_SAMPLED_BIT:
            jdata = "VK_IMAGE_USAGE_SAMPLED_BIT";
            break;
        case VK_IMAGE_USAGE_STORAGE_BIT:
            jdata = "VK_IMAGE_USAGE_STORAGE_BIT";
            break;
        case VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT:
            jdata = "VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT";
            break;
        case VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT:
            jdata = "VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT";
            break;
        case VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT:
            jdata = "VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT";
            break;
        case VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT:
            jdata = "VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT";
            break;
        case VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT:
            jdata = "VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT";
            break;
        case VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT:
            jdata = "VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT";
            break;
        case VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR:
            jdata = "VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR";
            break;
        case VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
            jdata = "VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
            break;
        case VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI:
            jdata = "VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI";
            break;
        case VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM:
            jdata = "VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM";
            break;
        case VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM:
            jdata = "VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageViewCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT:
            jdata = "VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT";
            break;
        case VK_IMAGE_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
            jdata = "VK_IMAGE_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT";
            break;
        case VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DEFERRED_BIT_EXT:
            jdata = "VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DEFERRED_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkImageViewType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_IMAGE_VIEW_TYPE_1D:
            jdata = "VK_IMAGE_VIEW_TYPE_1D";
            break;
        case VK_IMAGE_VIEW_TYPE_2D:
            jdata = "VK_IMAGE_VIEW_TYPE_2D";
            break;
        case VK_IMAGE_VIEW_TYPE_3D:
            jdata = "VK_IMAGE_VIEW_TYPE_3D";
            break;
        case VK_IMAGE_VIEW_TYPE_CUBE:
            jdata = "VK_IMAGE_VIEW_TYPE_CUBE";
            break;
        case VK_IMAGE_VIEW_TYPE_1D_ARRAY:
            jdata = "VK_IMAGE_VIEW_TYPE_1D_ARRAY";
            break;
        case VK_IMAGE_VIEW_TYPE_2D_ARRAY:
            jdata = "VK_IMAGE_VIEW_TYPE_2D_ARRAY";
            break;
        case VK_IMAGE_VIEW_TYPE_CUBE_ARRAY:
            jdata = "VK_IMAGE_VIEW_TYPE_CUBE_ARRAY";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkIndexType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_INDEX_TYPE_UINT16:
            jdata = "VK_INDEX_TYPE_UINT16";
            break;
        case VK_INDEX_TYPE_UINT32:
            jdata = "VK_INDEX_TYPE_UINT32";
            break;
        case VK_INDEX_TYPE_NONE_KHR:
            jdata = "VK_INDEX_TYPE_NONE_KHR";
            break;
        case VK_INDEX_TYPE_UINT8_KHR:
            jdata = "VK_INDEX_TYPE_UINT8_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkIndirectCommandsLayoutUsageFlagBitsNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV:
            jdata = "VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV";
            break;
        case VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV:
            jdata = "VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV";
            break;
        case VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV:
            jdata = "VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkIndirectCommandsTokenTypeNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV";
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV";
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV";
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV";
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV";
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV";
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV";
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV";
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_MESH_TASKS_NV";
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_PIPELINE_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_PIPELINE_NV";
            break;
        case VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_NV:
            jdata = "VK_INDIRECT_COMMANDS_TOKEN_TYPE_DISPATCH_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkIndirectStateFlagBitsNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV:
            jdata = "VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkInstanceCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR:
            jdata = "VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkInternalAllocationType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE:
            jdata = "VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkLatencyMarkerNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_LATENCY_MARKER_SIMULATION_START_NV:
            jdata = "VK_LATENCY_MARKER_SIMULATION_START_NV";
            break;
        case VK_LATENCY_MARKER_SIMULATION_END_NV:
            jdata = "VK_LATENCY_MARKER_SIMULATION_END_NV";
            break;
        case VK_LATENCY_MARKER_RENDERSUBMIT_START_NV:
            jdata = "VK_LATENCY_MARKER_RENDERSUBMIT_START_NV";
            break;
        case VK_LATENCY_MARKER_RENDERSUBMIT_END_NV:
            jdata = "VK_LATENCY_MARKER_RENDERSUBMIT_END_NV";
            break;
        case VK_LATENCY_MARKER_PRESENT_START_NV:
            jdata = "VK_LATENCY_MARKER_PRESENT_START_NV";
            break;
        case VK_LATENCY_MARKER_PRESENT_END_NV:
            jdata = "VK_LATENCY_MARKER_PRESENT_END_NV";
            break;
        case VK_LATENCY_MARKER_INPUT_SAMPLE_NV:
            jdata = "VK_LATENCY_MARKER_INPUT_SAMPLE_NV";
            break;
        case VK_LATENCY_MARKER_TRIGGER_FLASH_NV:
            jdata = "VK_LATENCY_MARKER_TRIGGER_FLASH_NV";
            break;
        case VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_START_NV:
            jdata = "VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_START_NV";
            break;
        case VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_END_NV:
            jdata = "VK_LATENCY_MARKER_OUT_OF_BAND_RENDERSUBMIT_END_NV";
            break;
        case VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_START_NV:
            jdata = "VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_START_NV";
            break;
        case VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_END_NV:
            jdata = "VK_LATENCY_MARKER_OUT_OF_BAND_PRESENT_END_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkLayerSettingTypeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_LAYER_SETTING_TYPE_BOOL32_EXT:
            jdata = "VK_LAYER_SETTING_TYPE_BOOL32_EXT";
            break;
        case VK_LAYER_SETTING_TYPE_INT32_EXT:
            jdata = "VK_LAYER_SETTING_TYPE_INT32_EXT";
            break;
        case VK_LAYER_SETTING_TYPE_INT64_EXT:
            jdata = "VK_LAYER_SETTING_TYPE_INT64_EXT";
            break;
        case VK_LAYER_SETTING_TYPE_UINT32_EXT:
            jdata = "VK_LAYER_SETTING_TYPE_UINT32_EXT";
            break;
        case VK_LAYER_SETTING_TYPE_UINT64_EXT:
            jdata = "VK_LAYER_SETTING_TYPE_UINT64_EXT";
            break;
        case VK_LAYER_SETTING_TYPE_FLOAT32_EXT:
            jdata = "VK_LAYER_SETTING_TYPE_FLOAT32_EXT";
            break;
        case VK_LAYER_SETTING_TYPE_FLOAT64_EXT:
            jdata = "VK_LAYER_SETTING_TYPE_FLOAT64_EXT";
            break;
        case VK_LAYER_SETTING_TYPE_STRING_EXT:
            jdata = "VK_LAYER_SETTING_TYPE_STRING_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkLayeredDriverUnderlyingApiMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_LAYERED_DRIVER_UNDERLYING_API_NONE_MSFT:
            jdata = "VK_LAYERED_DRIVER_UNDERLYING_API_NONE_MSFT";
            break;
        case VK_LAYERED_DRIVER_UNDERLYING_API_D3D12_MSFT:
            jdata = "VK_LAYERED_DRIVER_UNDERLYING_API_D3D12_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkLineRasterizationModeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_LINE_RASTERIZATION_MODE_DEFAULT_KHR:
            jdata = "VK_LINE_RASTERIZATION_MODE_DEFAULT_KHR";
            break;
        case VK_LINE_RASTERIZATION_MODE_RECTANGULAR_KHR:
            jdata = "VK_LINE_RASTERIZATION_MODE_RECTANGULAR_KHR";
            break;
        case VK_LINE_RASTERIZATION_MODE_BRESENHAM_KHR:
            jdata = "VK_LINE_RASTERIZATION_MODE_BRESENHAM_KHR";
            break;
        case VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_KHR:
            jdata = "VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkLogicOp& value, const JsonOptions& options)
{
    switch (value) {
        case VK_LOGIC_OP_CLEAR:
            jdata = "VK_LOGIC_OP_CLEAR";
            break;
        case VK_LOGIC_OP_AND:
            jdata = "VK_LOGIC_OP_AND";
            break;
        case VK_LOGIC_OP_AND_REVERSE:
            jdata = "VK_LOGIC_OP_AND_REVERSE";
            break;
        case VK_LOGIC_OP_COPY:
            jdata = "VK_LOGIC_OP_COPY";
            break;
        case VK_LOGIC_OP_AND_INVERTED:
            jdata = "VK_LOGIC_OP_AND_INVERTED";
            break;
        case VK_LOGIC_OP_NO_OP:
            jdata = "VK_LOGIC_OP_NO_OP";
            break;
        case VK_LOGIC_OP_XOR:
            jdata = "VK_LOGIC_OP_XOR";
            break;
        case VK_LOGIC_OP_OR:
            jdata = "VK_LOGIC_OP_OR";
            break;
        case VK_LOGIC_OP_NOR:
            jdata = "VK_LOGIC_OP_NOR";
            break;
        case VK_LOGIC_OP_EQUIVALENT:
            jdata = "VK_LOGIC_OP_EQUIVALENT";
            break;
        case VK_LOGIC_OP_INVERT:
            jdata = "VK_LOGIC_OP_INVERT";
            break;
        case VK_LOGIC_OP_OR_REVERSE:
            jdata = "VK_LOGIC_OP_OR_REVERSE";
            break;
        case VK_LOGIC_OP_COPY_INVERTED:
            jdata = "VK_LOGIC_OP_COPY_INVERTED";
            break;
        case VK_LOGIC_OP_OR_INVERTED:
            jdata = "VK_LOGIC_OP_OR_INVERTED";
            break;
        case VK_LOGIC_OP_NAND:
            jdata = "VK_LOGIC_OP_NAND";
            break;
        case VK_LOGIC_OP_SET:
            jdata = "VK_LOGIC_OP_SET";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryAllocateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT:
            jdata = "VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT";
            break;
        case VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT:
            jdata = "VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT";
            break;
        case VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT:
            jdata = "VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryHeapFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_MEMORY_HEAP_DEVICE_LOCAL_BIT:
            jdata = "VK_MEMORY_HEAP_DEVICE_LOCAL_BIT";
            break;
        case VK_MEMORY_HEAP_MULTI_INSTANCE_BIT:
            jdata = "VK_MEMORY_HEAP_MULTI_INSTANCE_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryMapFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_MEMORY_MAP_PLACED_BIT_EXT:
            jdata = "VK_MEMORY_MAP_PLACED_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryOverallocationBehaviorAMD& value, const JsonOptions& options)
{
    switch (value) {
        case VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD:
            jdata = "VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD";
            break;
        case VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD:
            jdata = "VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD";
            break;
        case VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD:
            jdata = "VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryPropertyFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT:
            jdata = "VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT";
            break;
        case VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT:
            jdata = "VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT";
            break;
        case VK_MEMORY_PROPERTY_HOST_COHERENT_BIT:
            jdata = "VK_MEMORY_PROPERTY_HOST_COHERENT_BIT";
            break;
        case VK_MEMORY_PROPERTY_HOST_CACHED_BIT:
            jdata = "VK_MEMORY_PROPERTY_HOST_CACHED_BIT";
            break;
        case VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT:
            jdata = "VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT";
            break;
        case VK_MEMORY_PROPERTY_PROTECTED_BIT:
            jdata = "VK_MEMORY_PROPERTY_PROTECTED_BIT";
            break;
        case VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD:
            jdata = "VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD";
            break;
        case VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD:
            jdata = "VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD";
            break;
        case VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV:
            jdata = "VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMemoryUnmapFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_MEMORY_UNMAP_RESERVE_BIT_EXT:
            jdata = "VK_MEMORY_UNMAP_RESERVE_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMicromapCreateFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_MICROMAP_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT:
            jdata = "VK_MICROMAP_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkMicromapTypeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_MICROMAP_TYPE_OPACITY_MICROMAP_EXT:
            jdata = "VK_MICROMAP_TYPE_OPACITY_MICROMAP_EXT";
            break;
        case VK_MICROMAP_TYPE_DISPLACEMENT_MICROMAP_NV:
            jdata = "VK_MICROMAP_TYPE_DISPLACEMENT_MICROMAP_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkObjectType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_OBJECT_TYPE_UNKNOWN:
            jdata = "VK_OBJECT_TYPE_UNKNOWN";
            break;
        case VK_OBJECT_TYPE_INSTANCE:
            jdata = "VK_OBJECT_TYPE_INSTANCE";
            break;
        case VK_OBJECT_TYPE_PHYSICAL_DEVICE:
            jdata = "VK_OBJECT_TYPE_PHYSICAL_DEVICE";
            break;
        case VK_OBJECT_TYPE_DEVICE:
            jdata = "VK_OBJECT_TYPE_DEVICE";
            break;
        case VK_OBJECT_TYPE_QUEUE:
            jdata = "VK_OBJECT_TYPE_QUEUE";
            break;
        case VK_OBJECT_TYPE_SEMAPHORE:
            jdata = "VK_OBJECT_TYPE_SEMAPHORE";
            break;
        case VK_OBJECT_TYPE_COMMAND_BUFFER:
            jdata = "VK_OBJECT_TYPE_COMMAND_BUFFER";
            break;
        case VK_OBJECT_TYPE_FENCE:
            jdata = "VK_OBJECT_TYPE_FENCE";
            break;
        case VK_OBJECT_TYPE_DEVICE_MEMORY:
            jdata = "VK_OBJECT_TYPE_DEVICE_MEMORY";
            break;
        case VK_OBJECT_TYPE_BUFFER:
            jdata = "VK_OBJECT_TYPE_BUFFER";
            break;
        case VK_OBJECT_TYPE_IMAGE:
            jdata = "VK_OBJECT_TYPE_IMAGE";
            break;
        case VK_OBJECT_TYPE_EVENT:
            jdata = "VK_OBJECT_TYPE_EVENT";
            break;
        case VK_OBJECT_TYPE_QUERY_POOL:
            jdata = "VK_OBJECT_TYPE_QUERY_POOL";
            break;
        case VK_OBJECT_TYPE_BUFFER_VIEW:
            jdata = "VK_OBJECT_TYPE_BUFFER_VIEW";
            break;
        case VK_OBJECT_TYPE_IMAGE_VIEW:
            jdata = "VK_OBJECT_TYPE_IMAGE_VIEW";
            break;
        case VK_OBJECT_TYPE_SHADER_MODULE:
            jdata = "VK_OBJECT_TYPE_SHADER_MODULE";
            break;
        case VK_OBJECT_TYPE_PIPELINE_CACHE:
            jdata = "VK_OBJECT_TYPE_PIPELINE_CACHE";
            break;
        case VK_OBJECT_TYPE_PIPELINE_LAYOUT:
            jdata = "VK_OBJECT_TYPE_PIPELINE_LAYOUT";
            break;
        case VK_OBJECT_TYPE_RENDER_PASS:
            jdata = "VK_OBJECT_TYPE_RENDER_PASS";
            break;
        case VK_OBJECT_TYPE_PIPELINE:
            jdata = "VK_OBJECT_TYPE_PIPELINE";
            break;
        case VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT:
            jdata = "VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT";
            break;
        case VK_OBJECT_TYPE_SAMPLER:
            jdata = "VK_OBJECT_TYPE_SAMPLER";
            break;
        case VK_OBJECT_TYPE_DESCRIPTOR_POOL:
            jdata = "VK_OBJECT_TYPE_DESCRIPTOR_POOL";
            break;
        case VK_OBJECT_TYPE_DESCRIPTOR_SET:
            jdata = "VK_OBJECT_TYPE_DESCRIPTOR_SET";
            break;
        case VK_OBJECT_TYPE_FRAMEBUFFER:
            jdata = "VK_OBJECT_TYPE_FRAMEBUFFER";
            break;
        case VK_OBJECT_TYPE_COMMAND_POOL:
            jdata = "VK_OBJECT_TYPE_COMMAND_POOL";
            break;
        case VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION:
            jdata = "VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION";
            break;
        case VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE:
            jdata = "VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE";
            break;
        case VK_OBJECT_TYPE_PRIVATE_DATA_SLOT:
            jdata = "VK_OBJECT_TYPE_PRIVATE_DATA_SLOT";
            break;
        case VK_OBJECT_TYPE_SURFACE_KHR:
            jdata = "VK_OBJECT_TYPE_SURFACE_KHR";
            break;
        case VK_OBJECT_TYPE_SWAPCHAIN_KHR:
            jdata = "VK_OBJECT_TYPE_SWAPCHAIN_KHR";
            break;
        case VK_OBJECT_TYPE_DISPLAY_KHR:
            jdata = "VK_OBJECT_TYPE_DISPLAY_KHR";
            break;
        case VK_OBJECT_TYPE_DISPLAY_MODE_KHR:
            jdata = "VK_OBJECT_TYPE_DISPLAY_MODE_KHR";
            break;
        case VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT:
            jdata = "VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT";
            break;
        case VK_OBJECT_TYPE_VIDEO_SESSION_KHR:
            jdata = "VK_OBJECT_TYPE_VIDEO_SESSION_KHR";
            break;
        case VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR:
            jdata = "VK_OBJECT_TYPE_VIDEO_SESSION_PARAMETERS_KHR";
            break;
        case VK_OBJECT_TYPE_CU_MODULE_NVX:
            jdata = "VK_OBJECT_TYPE_CU_MODULE_NVX";
            break;
        case VK_OBJECT_TYPE_CU_FUNCTION_NVX:
            jdata = "VK_OBJECT_TYPE_CU_FUNCTION_NVX";
            break;
        case VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            jdata = "VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT";
            break;
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR:
            jdata = "VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR";
            break;
        case VK_OBJECT_TYPE_VALIDATION_CACHE_EXT:
            jdata = "VK_OBJECT_TYPE_VALIDATION_CACHE_EXT";
            break;
        case VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV:
            jdata = "VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV";
            break;
        case VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL:
            jdata = "VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL";
            break;
        case VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR:
            jdata = "VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR";
            break;
        case VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV:
            jdata = "VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV";
            break;
        case VK_OBJECT_TYPE_CUDA_MODULE_NV:
            jdata = "VK_OBJECT_TYPE_CUDA_MODULE_NV";
            break;
        case VK_OBJECT_TYPE_CUDA_FUNCTION_NV:
            jdata = "VK_OBJECT_TYPE_CUDA_FUNCTION_NV";
            break;
        case VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA:
            jdata = "VK_OBJECT_TYPE_BUFFER_COLLECTION_FUCHSIA";
            break;
        case VK_OBJECT_TYPE_MICROMAP_EXT:
            jdata = "VK_OBJECT_TYPE_MICROMAP_EXT";
            break;
        case VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV:
            jdata = "VK_OBJECT_TYPE_OPTICAL_FLOW_SESSION_NV";
            break;
        case VK_OBJECT_TYPE_SHADER_EXT:
            jdata = "VK_OBJECT_TYPE_SHADER_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpacityMicromapFormatEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_OPACITY_MICROMAP_FORMAT_2_STATE_EXT:
            jdata = "VK_OPACITY_MICROMAP_FORMAT_2_STATE_EXT";
            break;
        case VK_OPACITY_MICROMAP_FORMAT_4_STATE_EXT:
            jdata = "VK_OPACITY_MICROMAP_FORMAT_4_STATE_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpacityMicromapSpecialIndexEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_TRANSPARENT_EXT:
            jdata = "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_TRANSPARENT_EXT";
            break;
        case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_OPAQUE_EXT:
            jdata = "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_OPAQUE_EXT";
            break;
        case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_TRANSPARENT_EXT:
            jdata = "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_TRANSPARENT_EXT";
            break;
        case VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE_EXT:
            jdata = "VK_OPACITY_MICROMAP_SPECIAL_INDEX_FULLY_UNKNOWN_OPAQUE_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowExecuteFlagBitsNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_OPTICAL_FLOW_EXECUTE_DISABLE_TEMPORAL_HINTS_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_EXECUTE_DISABLE_TEMPORAL_HINTS_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowGridSizeFlagBitsNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_OPTICAL_FLOW_GRID_SIZE_UNKNOWN_NV:
            jdata = "VK_OPTICAL_FLOW_GRID_SIZE_UNKNOWN_NV";
            break;
        case VK_OPTICAL_FLOW_GRID_SIZE_1X1_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_GRID_SIZE_1X1_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_GRID_SIZE_2X2_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_GRID_SIZE_2X2_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_GRID_SIZE_8X8_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_GRID_SIZE_8X8_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowPerformanceLevelNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_UNKNOWN_NV:
            jdata = "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_UNKNOWN_NV";
            break;
        case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_SLOW_NV:
            jdata = "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_SLOW_NV";
            break;
        case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_MEDIUM_NV:
            jdata = "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_MEDIUM_NV";
            break;
        case VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_FAST_NV:
            jdata = "VK_OPTICAL_FLOW_PERFORMANCE_LEVEL_FAST_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowSessionBindingPointNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_UNKNOWN_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_UNKNOWN_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_INPUT_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_INPUT_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_REFERENCE_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_REFERENCE_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_HINT_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_HINT_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_FLOW_VECTOR_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_FLOW_VECTOR_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_FLOW_VECTOR_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_FLOW_VECTOR_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_COST_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_COST_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_COST_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_BACKWARD_COST_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_BINDING_POINT_GLOBAL_FLOW_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_BINDING_POINT_GLOBAL_FLOW_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowSessionCreateFlagBitsNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_HINT_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_HINT_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_COST_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_COST_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_GLOBAL_FLOW_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_GLOBAL_FLOW_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_CREATE_ALLOW_REGIONS_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_CREATE_ALLOW_REGIONS_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_SESSION_CREATE_BOTH_DIRECTIONS_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_SESSION_CREATE_BOTH_DIRECTIONS_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOpticalFlowUsageFlagBitsNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_OPTICAL_FLOW_USAGE_UNKNOWN_NV:
            jdata = "VK_OPTICAL_FLOW_USAGE_UNKNOWN_NV";
            break;
        case VK_OPTICAL_FLOW_USAGE_INPUT_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_USAGE_INPUT_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_USAGE_OUTPUT_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_USAGE_OUTPUT_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_USAGE_HINT_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_USAGE_HINT_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_USAGE_COST_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_USAGE_COST_BIT_NV";
            break;
        case VK_OPTICAL_FLOW_USAGE_GLOBAL_FLOW_BIT_NV:
            jdata = "VK_OPTICAL_FLOW_USAGE_GLOBAL_FLOW_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkOutOfBandQueueTypeNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_OUT_OF_BAND_QUEUE_TYPE_RENDER_NV:
            jdata = "VK_OUT_OF_BAND_QUEUE_TYPE_RENDER_NV";
            break;
        case VK_OUT_OF_BAND_QUEUE_TYPE_PRESENT_NV:
            jdata = "VK_OUT_OF_BAND_QUEUE_TYPE_PRESENT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPeerMemoryFeatureFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT:
            jdata = "VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT";
            break;
        case VK_PEER_MEMORY_FEATURE_COPY_DST_BIT:
            jdata = "VK_PEER_MEMORY_FEATURE_COPY_DST_BIT";
            break;
        case VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT:
            jdata = "VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT";
            break;
        case VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT:
            jdata = "VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceConfigurationTypeINTEL& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL:
            jdata = "VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterDescriptionFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterScopeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterStorageKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceCounterUnitKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR";
            break;
        case VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR:
            jdata = "VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceOverrideTypeINTEL& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL:
            jdata = "VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL";
            break;
        case VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL:
            jdata = "VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceParameterTypeINTEL& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL:
            jdata = "VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL";
            break;
        case VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL:
            jdata = "VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPerformanceValueTypeINTEL& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL:
            jdata = "VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL";
            break;
        case VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL:
            jdata = "VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL";
            break;
        case VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL:
            jdata = "VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL";
            break;
        case VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL:
            jdata = "VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL";
            break;
        case VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL:
            jdata = "VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(VkPhysicalDeviceSchedulingControlsFlagBitsARM_t, nlohmann::ordered_json& jdata, const VkPhysicalDeviceSchedulingControlsFlagBitsARM& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM:
            jdata = "VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPhysicalDeviceType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PHYSICAL_DEVICE_TYPE_OTHER:
            jdata = "VK_PHYSICAL_DEVICE_TYPE_OTHER";
            break;
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU:
            jdata = "VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU";
            break;
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:
            jdata = "VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU";
            break;
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:
            jdata = "VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU";
            break;
        case VK_PHYSICAL_DEVICE_TYPE_CPU:
            jdata = "VK_PHYSICAL_DEVICE_TYPE_CPU";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineBindPoint& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_BIND_POINT_GRAPHICS:
            jdata = "VK_PIPELINE_BIND_POINT_GRAPHICS";
            break;
        case VK_PIPELINE_BIND_POINT_COMPUTE:
            jdata = "VK_PIPELINE_BIND_POINT_COMPUTE";
            break;
        case VK_PIPELINE_BIND_POINT_EXECUTION_GRAPH_AMDX:
            jdata = "VK_PIPELINE_BIND_POINT_EXECUTION_GRAPH_AMDX";
            break;
        case VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR:
            jdata = "VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR";
            break;
        case VK_PIPELINE_BIND_POINT_SUBPASS_SHADING_HUAWEI:
            jdata = "VK_PIPELINE_BIND_POINT_SUBPASS_SHADING_HUAWEI";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCacheCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT:
            jdata = "VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCacheHeaderVersion& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_CACHE_HEADER_VERSION_ONE:
            jdata = "VK_PIPELINE_CACHE_HEADER_VERSION_ONE";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineColorBlendStateCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_COLOR_BLEND_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_BIT_EXT:
            jdata = "VK_PIPELINE_COLOR_BLEND_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCompilerControlFlagBitsAMD& value, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT:
            jdata = "VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT";
            break;
        case VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT:
            jdata = "VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT";
            break;
        case VK_PIPELINE_CREATE_DERIVATIVE_BIT:
            jdata = "VK_PIPELINE_CREATE_DERIVATIVE_BIT";
            break;
        case VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT:
            jdata = "VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT";
            break;
        case VK_PIPELINE_CREATE_DISPATCH_BASE_BIT:
            jdata = "VK_PIPELINE_CREATE_DISPATCH_BASE_BIT";
            break;
        case VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT:
            jdata = "VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT";
            break;
        case VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT:
            jdata = "VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT";
            break;
        case VK_PIPELINE_CREATE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_LIBRARY_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_LIBRARY_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_LINK_TIME_OPTIMIZATION_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_LINK_TIME_OPTIMIZATION_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_RAY_TRACING_ALLOW_MOTION_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_RAY_TRACING_ALLOW_MOTION_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_NO_PROTECTED_ACCESS_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_NO_PROTECTED_ACCESS_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_PROTECTED_ACCESS_ONLY_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_PROTECTED_ACCESS_ONLY_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(VkPipelineCreateFlagBits2KHR_t, nlohmann::ordered_json& jdata, const VkPipelineCreateFlagBits2KHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_DERIVATIVE_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_DERIVATIVE_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT_EXT";
            break;
        case VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV:
            jdata = "VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV";
            break;
        case VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT:
            jdata = "VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineCreationFeedbackFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT:
            jdata = "VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT";
            break;
        case VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT:
            jdata = "VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT";
            break;
        case VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT:
            jdata = "VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineDepthStencilStateCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT:
            jdata = "VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT";
            break;
        case VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT:
            jdata = "VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineExecutableStatisticFormatKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR:
            jdata = "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR";
            break;
        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR:
            jdata = "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR";
            break;
        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR:
            jdata = "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR";
            break;
        case VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR:
            jdata = "VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineLayoutCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_LAYOUT_CREATE_INDEPENDENT_SETS_BIT_EXT:
            jdata = "VK_PIPELINE_LAYOUT_CREATE_INDEPENDENT_SETS_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineRobustnessBufferBehaviorEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT_EXT:
            jdata = "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DEVICE_DEFAULT_EXT";
            break;
        case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED_EXT:
            jdata = "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_DISABLED_EXT";
            break;
        case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_EXT:
            jdata = "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_EXT";
            break;
        case VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2_EXT:
            jdata = "VK_PIPELINE_ROBUSTNESS_BUFFER_BEHAVIOR_ROBUST_BUFFER_ACCESS_2_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineRobustnessImageBehaviorEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT_EXT:
            jdata = "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DEVICE_DEFAULT_EXT";
            break;
        case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED_EXT:
            jdata = "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_DISABLED_EXT";
            break;
        case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_EXT:
            jdata = "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_EXT";
            break;
        case VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2_EXT:
            jdata = "VK_PIPELINE_ROBUSTNESS_IMAGE_BEHAVIOR_ROBUST_IMAGE_ACCESS_2_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineShaderStageCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT:
            jdata = "VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT";
            break;
        case VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT:
            jdata = "VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPipelineStageFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT:
            jdata = "VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT";
            break;
        case VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT:
            jdata = "VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT";
            break;
        case VK_PIPELINE_STAGE_VERTEX_INPUT_BIT:
            jdata = "VK_PIPELINE_STAGE_VERTEX_INPUT_BIT";
            break;
        case VK_PIPELINE_STAGE_VERTEX_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_VERTEX_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT:
            jdata = "VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT";
            break;
        case VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT:
            jdata = "VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT";
            break;
        case VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT:
            jdata = "VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT";
            break;
        case VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_TRANSFER_BIT:
            jdata = "VK_PIPELINE_STAGE_TRANSFER_BIT";
            break;
        case VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT:
            jdata = "VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT";
            break;
        case VK_PIPELINE_STAGE_HOST_BIT:
            jdata = "VK_PIPELINE_STAGE_HOST_BIT";
            break;
        case VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT:
            jdata = "VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT";
            break;
        case VK_PIPELINE_STAGE_ALL_COMMANDS_BIT:
            jdata = "VK_PIPELINE_STAGE_ALL_COMMANDS_BIT";
            break;
        case VK_PIPELINE_STAGE_NONE:
            jdata = "VK_PIPELINE_STAGE_NONE";
            break;
        case VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV:
            jdata = "VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV";
            break;
        case VK_PIPELINE_STAGE_TASK_SHADER_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_TASK_SHADER_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_MESH_SHADER_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_MESH_SHADER_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(VkPipelineStageFlagBits2_t, nlohmann::ordered_json& jdata, const VkPipelineStageFlagBits2& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PIPELINE_STAGE_2_NONE:
            jdata = "VK_PIPELINE_STAGE_2_NONE";
            break;
        case VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT:
            jdata = "VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT";
            break;
        case VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT:
            jdata = "VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT";
            break;
        case VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT:
            jdata = "VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT";
            break;
        case VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT:
            jdata = "VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT";
            break;
        case VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT:
            jdata = "VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT";
            break;
        case VK_PIPELINE_STAGE_2_HOST_BIT:
            jdata = "VK_PIPELINE_STAGE_2_HOST_BIT";
            break;
        case VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT:
            jdata = "VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT";
            break;
        case VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT:
            jdata = "VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT";
            break;
        case VK_PIPELINE_STAGE_2_COPY_BIT:
            jdata = "VK_PIPELINE_STAGE_2_COPY_BIT";
            break;
        case VK_PIPELINE_STAGE_2_RESOLVE_BIT:
            jdata = "VK_PIPELINE_STAGE_2_RESOLVE_BIT";
            break;
        case VK_PIPELINE_STAGE_2_BLIT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_BLIT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_CLEAR_BIT:
            jdata = "VK_PIPELINE_STAGE_2_CLEAR_BIT";
            break;
        case VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT:
            jdata = "VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT";
            break;
        case VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT:
            jdata = "VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT";
            break;
        case VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV:
            jdata = "VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV";
            break;
        case VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI:
            jdata = "VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI";
            break;
        case VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI:
            jdata = "VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI";
            break;
        case VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR:
            jdata = "VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR";
            break;
        case VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT:
            jdata = "VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT";
            break;
        case VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI:
            jdata = "VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI";
            break;
        case VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV:
            jdata = "VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPointClippingBehavior& value, const JsonOptions& options)
{
    switch (value) {
        case VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES:
            jdata = "VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES";
            break;
        case VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY:
            jdata = "VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPolygonMode& value, const JsonOptions& options)
{
    switch (value) {
        case VK_POLYGON_MODE_FILL:
            jdata = "VK_POLYGON_MODE_FILL";
            break;
        case VK_POLYGON_MODE_LINE:
            jdata = "VK_POLYGON_MODE_LINE";
            break;
        case VK_POLYGON_MODE_POINT:
            jdata = "VK_POLYGON_MODE_POINT";
            break;
        case VK_POLYGON_MODE_FILL_RECTANGLE_NV:
            jdata = "VK_POLYGON_MODE_FILL_RECTANGLE_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPresentGravityFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PRESENT_GRAVITY_MIN_BIT_EXT:
            jdata = "VK_PRESENT_GRAVITY_MIN_BIT_EXT";
            break;
        case VK_PRESENT_GRAVITY_MAX_BIT_EXT:
            jdata = "VK_PRESENT_GRAVITY_MAX_BIT_EXT";
            break;
        case VK_PRESENT_GRAVITY_CENTERED_BIT_EXT:
            jdata = "VK_PRESENT_GRAVITY_CENTERED_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPresentModeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PRESENT_MODE_IMMEDIATE_KHR:
            jdata = "VK_PRESENT_MODE_IMMEDIATE_KHR";
            break;
        case VK_PRESENT_MODE_MAILBOX_KHR:
            jdata = "VK_PRESENT_MODE_MAILBOX_KHR";
            break;
        case VK_PRESENT_MODE_FIFO_KHR:
            jdata = "VK_PRESENT_MODE_FIFO_KHR";
            break;
        case VK_PRESENT_MODE_FIFO_RELAXED_KHR:
            jdata = "VK_PRESENT_MODE_FIFO_RELAXED_KHR";
            break;
        case VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR:
            jdata = "VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR";
            break;
        case VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR:
            jdata = "VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPresentScalingFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PRESENT_SCALING_ONE_TO_ONE_BIT_EXT:
            jdata = "VK_PRESENT_SCALING_ONE_TO_ONE_BIT_EXT";
            break;
        case VK_PRESENT_SCALING_ASPECT_RATIO_STRETCH_BIT_EXT:
            jdata = "VK_PRESENT_SCALING_ASPECT_RATIO_STRETCH_BIT_EXT";
            break;
        case VK_PRESENT_SCALING_STRETCH_BIT_EXT:
            jdata = "VK_PRESENT_SCALING_STRETCH_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkPrimitiveTopology& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PRIMITIVE_TOPOLOGY_POINT_LIST:
            jdata = "VK_PRIMITIVE_TOPOLOGY_POINT_LIST";
            break;
        case VK_PRIMITIVE_TOPOLOGY_LINE_LIST:
            jdata = "VK_PRIMITIVE_TOPOLOGY_LINE_LIST";
            break;
        case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP:
            jdata = "VK_PRIMITIVE_TOPOLOGY_LINE_STRIP";
            break;
        case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST:
            jdata = "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST";
            break;
        case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP:
            jdata = "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP";
            break;
        case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN:
            jdata = "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN";
            break;
        case VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY:
            jdata = "VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY";
            break;
        case VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY:
            jdata = "VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY";
            break;
        case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY:
            jdata = "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY";
            break;
        case VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY:
            jdata = "VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY";
            break;
        case VK_PRIMITIVE_TOPOLOGY_PATCH_LIST:
            jdata = "VK_PRIMITIVE_TOPOLOGY_PATCH_LIST";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkProvokingVertexModeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_PROVOKING_VERTEX_MODE_FIRST_VERTEX_EXT:
            jdata = "VK_PROVOKING_VERTEX_MODE_FIRST_VERTEX_EXT";
            break;
        case VK_PROVOKING_VERTEX_MODE_LAST_VERTEX_EXT:
            jdata = "VK_PROVOKING_VERTEX_MODE_LAST_VERTEX_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryControlFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_QUERY_CONTROL_PRECISE_BIT:
            jdata = "VK_QUERY_CONTROL_PRECISE_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryPipelineStatisticFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_TASK_SHADER_INVOCATIONS_BIT_EXT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_TASK_SHADER_INVOCATIONS_BIT_EXT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_MESH_SHADER_INVOCATIONS_BIT_EXT:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_MESH_SHADER_INVOCATIONS_BIT_EXT";
            break;
        case VK_QUERY_PIPELINE_STATISTIC_CLUSTER_CULLING_SHADER_INVOCATIONS_BIT_HUAWEI:
            jdata = "VK_QUERY_PIPELINE_STATISTIC_CLUSTER_CULLING_SHADER_INVOCATIONS_BIT_HUAWEI";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryPoolSamplingModeINTEL& value, const JsonOptions& options)
{
    switch (value) {
        case VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL:
            jdata = "VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryResultFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_QUERY_RESULT_64_BIT:
            jdata = "VK_QUERY_RESULT_64_BIT";
            break;
        case VK_QUERY_RESULT_WAIT_BIT:
            jdata = "VK_QUERY_RESULT_WAIT_BIT";
            break;
        case VK_QUERY_RESULT_WITH_AVAILABILITY_BIT:
            jdata = "VK_QUERY_RESULT_WITH_AVAILABILITY_BIT";
            break;
        case VK_QUERY_RESULT_PARTIAL_BIT:
            jdata = "VK_QUERY_RESULT_PARTIAL_BIT";
            break;
        case VK_QUERY_RESULT_WITH_STATUS_BIT_KHR:
            jdata = "VK_QUERY_RESULT_WITH_STATUS_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryResultStatusKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_QUERY_RESULT_STATUS_ERROR_KHR:
            jdata = "VK_QUERY_RESULT_STATUS_ERROR_KHR";
            break;
        case VK_QUERY_RESULT_STATUS_NOT_READY_KHR:
            jdata = "VK_QUERY_RESULT_STATUS_NOT_READY_KHR";
            break;
        case VK_QUERY_RESULT_STATUS_COMPLETE_KHR:
            jdata = "VK_QUERY_RESULT_STATUS_COMPLETE_KHR";
            break;
        case VK_QUERY_RESULT_STATUS_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_KHR:
            jdata = "VK_QUERY_RESULT_STATUS_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueryType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_QUERY_TYPE_OCCLUSION:
            jdata = "VK_QUERY_TYPE_OCCLUSION";
            break;
        case VK_QUERY_TYPE_PIPELINE_STATISTICS:
            jdata = "VK_QUERY_TYPE_PIPELINE_STATISTICS";
            break;
        case VK_QUERY_TYPE_TIMESTAMP:
            jdata = "VK_QUERY_TYPE_TIMESTAMP";
            break;
        case VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR:
            jdata = "VK_QUERY_TYPE_RESULT_STATUS_ONLY_KHR";
            break;
        case VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT:
            jdata = "VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT";
            break;
        case VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR:
            jdata = "VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR";
            break;
        case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR:
            jdata = "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR";
            break;
        case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR:
            jdata = "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR";
            break;
        case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV:
            jdata = "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV";
            break;
        case VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL:
            jdata = "VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL";
            break;
        case VK_QUERY_TYPE_VIDEO_ENCODE_FEEDBACK_KHR:
            jdata = "VK_QUERY_TYPE_VIDEO_ENCODE_FEEDBACK_KHR";
            break;
        case VK_QUERY_TYPE_MESH_PRIMITIVES_GENERATED_EXT:
            jdata = "VK_QUERY_TYPE_MESH_PRIMITIVES_GENERATED_EXT";
            break;
        case VK_QUERY_TYPE_PRIMITIVES_GENERATED_EXT:
            jdata = "VK_QUERY_TYPE_PRIMITIVES_GENERATED_EXT";
            break;
        case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_BOTTOM_LEVEL_POINTERS_KHR:
            jdata = "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_BOTTOM_LEVEL_POINTERS_KHR";
            break;
        case VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SIZE_KHR:
            jdata = "VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SIZE_KHR";
            break;
        case VK_QUERY_TYPE_MICROMAP_SERIALIZATION_SIZE_EXT:
            jdata = "VK_QUERY_TYPE_MICROMAP_SERIALIZATION_SIZE_EXT";
            break;
        case VK_QUERY_TYPE_MICROMAP_COMPACTED_SIZE_EXT:
            jdata = "VK_QUERY_TYPE_MICROMAP_COMPACTED_SIZE_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueueFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_QUEUE_GRAPHICS_BIT:
            jdata = "VK_QUEUE_GRAPHICS_BIT";
            break;
        case VK_QUEUE_COMPUTE_BIT:
            jdata = "VK_QUEUE_COMPUTE_BIT";
            break;
        case VK_QUEUE_TRANSFER_BIT:
            jdata = "VK_QUEUE_TRANSFER_BIT";
            break;
        case VK_QUEUE_SPARSE_BINDING_BIT:
            jdata = "VK_QUEUE_SPARSE_BINDING_BIT";
            break;
        case VK_QUEUE_PROTECTED_BIT:
            jdata = "VK_QUEUE_PROTECTED_BIT";
            break;
        case VK_QUEUE_VIDEO_DECODE_BIT_KHR:
            jdata = "VK_QUEUE_VIDEO_DECODE_BIT_KHR";
            break;
        case VK_QUEUE_VIDEO_ENCODE_BIT_KHR:
            jdata = "VK_QUEUE_VIDEO_ENCODE_BIT_KHR";
            break;
        case VK_QUEUE_OPTICAL_FLOW_BIT_NV:
            jdata = "VK_QUEUE_OPTICAL_FLOW_BIT_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkQueueGlobalPriorityKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR:
            jdata = "VK_QUEUE_GLOBAL_PRIORITY_LOW_KHR";
            break;
        case VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR:
            jdata = "VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_KHR";
            break;
        case VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR:
            jdata = "VK_QUEUE_GLOBAL_PRIORITY_HIGH_KHR";
            break;
        case VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR:
            jdata = "VK_QUEUE_GLOBAL_PRIORITY_REALTIME_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkRasterizationOrderAMD& value, const JsonOptions& options)
{
    switch (value) {
        case VK_RASTERIZATION_ORDER_STRICT_AMD:
            jdata = "VK_RASTERIZATION_ORDER_STRICT_AMD";
            break;
        case VK_RASTERIZATION_ORDER_RELAXED_AMD:
            jdata = "VK_RASTERIZATION_ORDER_RELAXED_AMD";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkRayTracingInvocationReorderModeNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_RAY_TRACING_INVOCATION_REORDER_MODE_NONE_NV:
            jdata = "VK_RAY_TRACING_INVOCATION_REORDER_MODE_NONE_NV";
            break;
        case VK_RAY_TRACING_INVOCATION_REORDER_MODE_REORDER_NV:
            jdata = "VK_RAY_TRACING_INVOCATION_REORDER_MODE_REORDER_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkRayTracingShaderGroupTypeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR:
            jdata = "VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR";
            break;
        case VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR:
            jdata = "VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR";
            break;
        case VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR:
            jdata = "VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkRenderPassCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_RENDER_PASS_CREATE_TRANSFORM_BIT_QCOM:
            jdata = "VK_RENDER_PASS_CREATE_TRANSFORM_BIT_QCOM";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkRenderingFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_RENDERING_CONTENTS_SECONDARY_COMMAND_BUFFERS_BIT:
            jdata = "VK_RENDERING_CONTENTS_SECONDARY_COMMAND_BUFFERS_BIT";
            break;
        case VK_RENDERING_SUSPENDING_BIT:
            jdata = "VK_RENDERING_SUSPENDING_BIT";
            break;
        case VK_RENDERING_RESUMING_BIT:
            jdata = "VK_RENDERING_RESUMING_BIT";
            break;
        case VK_RENDERING_CONTENTS_INLINE_BIT_EXT:
            jdata = "VK_RENDERING_CONTENTS_INLINE_BIT_EXT";
            break;
        case VK_RENDERING_ENABLE_LEGACY_DITHERING_BIT_EXT:
            jdata = "VK_RENDERING_ENABLE_LEGACY_DITHERING_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkResolveModeFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_RESOLVE_MODE_NONE:
            jdata = "VK_RESOLVE_MODE_NONE";
            break;
        case VK_RESOLVE_MODE_SAMPLE_ZERO_BIT:
            jdata = "VK_RESOLVE_MODE_SAMPLE_ZERO_BIT";
            break;
        case VK_RESOLVE_MODE_AVERAGE_BIT:
            jdata = "VK_RESOLVE_MODE_AVERAGE_BIT";
            break;
        case VK_RESOLVE_MODE_MIN_BIT:
            jdata = "VK_RESOLVE_MODE_MIN_BIT";
            break;
        case VK_RESOLVE_MODE_MAX_BIT:
            jdata = "VK_RESOLVE_MODE_MAX_BIT";
            break;
        case VK_RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_ANDROID:
            jdata = "VK_RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_ANDROID";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkResult& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SUCCESS:
            jdata = "VK_SUCCESS";
            break;
        case VK_NOT_READY:
            jdata = "VK_NOT_READY";
            break;
        case VK_TIMEOUT:
            jdata = "VK_TIMEOUT";
            break;
        case VK_EVENT_SET:
            jdata = "VK_EVENT_SET";
            break;
        case VK_EVENT_RESET:
            jdata = "VK_EVENT_RESET";
            break;
        case VK_INCOMPLETE:
            jdata = "VK_INCOMPLETE";
            break;
        case VK_ERROR_OUT_OF_HOST_MEMORY:
            jdata = "VK_ERROR_OUT_OF_HOST_MEMORY";
            break;
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:
            jdata = "VK_ERROR_OUT_OF_DEVICE_MEMORY";
            break;
        case VK_ERROR_INITIALIZATION_FAILED:
            jdata = "VK_ERROR_INITIALIZATION_FAILED";
            break;
        case VK_ERROR_DEVICE_LOST:
            jdata = "VK_ERROR_DEVICE_LOST";
            break;
        case VK_ERROR_MEMORY_MAP_FAILED:
            jdata = "VK_ERROR_MEMORY_MAP_FAILED";
            break;
        case VK_ERROR_LAYER_NOT_PRESENT:
            jdata = "VK_ERROR_LAYER_NOT_PRESENT";
            break;
        case VK_ERROR_EXTENSION_NOT_PRESENT:
            jdata = "VK_ERROR_EXTENSION_NOT_PRESENT";
            break;
        case VK_ERROR_FEATURE_NOT_PRESENT:
            jdata = "VK_ERROR_FEATURE_NOT_PRESENT";
            break;
        case VK_ERROR_INCOMPATIBLE_DRIVER:
            jdata = "VK_ERROR_INCOMPATIBLE_DRIVER";
            break;
        case VK_ERROR_TOO_MANY_OBJECTS:
            jdata = "VK_ERROR_TOO_MANY_OBJECTS";
            break;
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            jdata = "VK_ERROR_FORMAT_NOT_SUPPORTED";
            break;
        case VK_ERROR_FRAGMENTED_POOL:
            jdata = "VK_ERROR_FRAGMENTED_POOL";
            break;
        case VK_ERROR_UNKNOWN:
            jdata = "VK_ERROR_UNKNOWN";
            break;
        case VK_ERROR_OUT_OF_POOL_MEMORY:
            jdata = "VK_ERROR_OUT_OF_POOL_MEMORY";
            break;
        case VK_ERROR_INVALID_EXTERNAL_HANDLE:
            jdata = "VK_ERROR_INVALID_EXTERNAL_HANDLE";
            break;
        case VK_ERROR_FRAGMENTATION:
            jdata = "VK_ERROR_FRAGMENTATION";
            break;
        case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:
            jdata = "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS";
            break;
        case VK_PIPELINE_COMPILE_REQUIRED:
            jdata = "VK_PIPELINE_COMPILE_REQUIRED";
            break;
        case VK_ERROR_SURFACE_LOST_KHR:
            jdata = "VK_ERROR_SURFACE_LOST_KHR";
            break;
        case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
            jdata = "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
            break;
        case VK_SUBOPTIMAL_KHR:
            jdata = "VK_SUBOPTIMAL_KHR";
            break;
        case VK_ERROR_OUT_OF_DATE_KHR:
            jdata = "VK_ERROR_OUT_OF_DATE_KHR";
            break;
        case VK_ERROR_INCOMPATIBLE_DISPLAY_KHR:
            jdata = "VK_ERROR_INCOMPATIBLE_DISPLAY_KHR";
            break;
        case VK_ERROR_VALIDATION_FAILED_EXT:
            jdata = "VK_ERROR_VALIDATION_FAILED_EXT";
            break;
        case VK_ERROR_INVALID_SHADER_NV:
            jdata = "VK_ERROR_INVALID_SHADER_NV";
            break;
        case VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR:
            jdata = "VK_ERROR_IMAGE_USAGE_NOT_SUPPORTED_KHR";
            break;
        case VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR:
            jdata = "VK_ERROR_VIDEO_PICTURE_LAYOUT_NOT_SUPPORTED_KHR";
            break;
        case VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR:
            jdata = "VK_ERROR_VIDEO_PROFILE_OPERATION_NOT_SUPPORTED_KHR";
            break;
        case VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR:
            jdata = "VK_ERROR_VIDEO_PROFILE_FORMAT_NOT_SUPPORTED_KHR";
            break;
        case VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR:
            jdata = "VK_ERROR_VIDEO_PROFILE_CODEC_NOT_SUPPORTED_KHR";
            break;
        case VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR:
            jdata = "VK_ERROR_VIDEO_STD_VERSION_NOT_SUPPORTED_KHR";
            break;
        case VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT:
            jdata = "VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT";
            break;
        case VK_ERROR_NOT_PERMITTED_KHR:
            jdata = "VK_ERROR_NOT_PERMITTED_KHR";
            break;
        case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
            jdata = "VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT";
            break;
        case VK_THREAD_IDLE_KHR:
            jdata = "VK_THREAD_IDLE_KHR";
            break;
        case VK_THREAD_DONE_KHR:
            jdata = "VK_THREAD_DONE_KHR";
            break;
        case VK_OPERATION_DEFERRED_KHR:
            jdata = "VK_OPERATION_DEFERRED_KHR";
            break;
        case VK_OPERATION_NOT_DEFERRED_KHR:
            jdata = "VK_OPERATION_NOT_DEFERRED_KHR";
            break;
        case VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR:
            jdata = "VK_ERROR_INVALID_VIDEO_STD_PARAMETERS_KHR";
            break;
        case VK_ERROR_COMPRESSION_EXHAUSTED_EXT:
            jdata = "VK_ERROR_COMPRESSION_EXHAUSTED_EXT";
            break;
        case VK_INCOMPATIBLE_SHADER_BINARY_EXT:
            jdata = "VK_INCOMPATIBLE_SHADER_BINARY_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSampleCountFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SAMPLE_COUNT_1_BIT:
            jdata = "VK_SAMPLE_COUNT_1_BIT";
            break;
        case VK_SAMPLE_COUNT_2_BIT:
            jdata = "VK_SAMPLE_COUNT_2_BIT";
            break;
        case VK_SAMPLE_COUNT_4_BIT:
            jdata = "VK_SAMPLE_COUNT_4_BIT";
            break;
        case VK_SAMPLE_COUNT_8_BIT:
            jdata = "VK_SAMPLE_COUNT_8_BIT";
            break;
        case VK_SAMPLE_COUNT_16_BIT:
            jdata = "VK_SAMPLE_COUNT_16_BIT";
            break;
        case VK_SAMPLE_COUNT_32_BIT:
            jdata = "VK_SAMPLE_COUNT_32_BIT";
            break;
        case VK_SAMPLE_COUNT_64_BIT:
            jdata = "VK_SAMPLE_COUNT_64_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerAddressMode& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SAMPLER_ADDRESS_MODE_REPEAT:
            jdata = "VK_SAMPLER_ADDRESS_MODE_REPEAT";
            break;
        case VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT:
            jdata = "VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT";
            break;
        case VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE:
            jdata = "VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE";
            break;
        case VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER:
            jdata = "VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER";
            break;
        case VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE:
            jdata = "VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerCreateFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT:
            jdata = "VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT";
            break;
        case VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT:
            jdata = "VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT";
            break;
        case VK_SAMPLER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
            jdata = "VK_SAMPLER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT";
            break;
        case VK_SAMPLER_CREATE_NON_SEAMLESS_CUBE_MAP_BIT_EXT:
            jdata = "VK_SAMPLER_CREATE_NON_SEAMLESS_CUBE_MAP_BIT_EXT";
            break;
        case VK_SAMPLER_CREATE_IMAGE_PROCESSING_BIT_QCOM:
            jdata = "VK_SAMPLER_CREATE_IMAGE_PROCESSING_BIT_QCOM";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerMipmapMode& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SAMPLER_MIPMAP_MODE_NEAREST:
            jdata = "VK_SAMPLER_MIPMAP_MODE_NEAREST";
            break;
        case VK_SAMPLER_MIPMAP_MODE_LINEAR:
            jdata = "VK_SAMPLER_MIPMAP_MODE_LINEAR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerReductionMode& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE:
            jdata = "VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE";
            break;
        case VK_SAMPLER_REDUCTION_MODE_MIN:
            jdata = "VK_SAMPLER_REDUCTION_MODE_MIN";
            break;
        case VK_SAMPLER_REDUCTION_MODE_MAX:
            jdata = "VK_SAMPLER_REDUCTION_MODE_MAX";
            break;
        case VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_RANGECLAMP_QCOM:
            jdata = "VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_RANGECLAMP_QCOM";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerYcbcrModelConversion& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY:
            jdata = "VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY";
            break;
        case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY:
            jdata = "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY";
            break;
        case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709:
            jdata = "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709";
            break;
        case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601:
            jdata = "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601";
            break;
        case VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020:
            jdata = "VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSamplerYcbcrRange& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SAMPLER_YCBCR_RANGE_ITU_FULL:
            jdata = "VK_SAMPLER_YCBCR_RANGE_ITU_FULL";
            break;
        case VK_SAMPLER_YCBCR_RANGE_ITU_NARROW:
            jdata = "VK_SAMPLER_YCBCR_RANGE_ITU_NARROW";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkScopeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SCOPE_DEVICE_KHR:
            jdata = "VK_SCOPE_DEVICE_KHR";
            break;
        case VK_SCOPE_WORKGROUP_KHR:
            jdata = "VK_SCOPE_WORKGROUP_KHR";
            break;
        case VK_SCOPE_SUBGROUP_KHR:
            jdata = "VK_SCOPE_SUBGROUP_KHR";
            break;
        case VK_SCOPE_QUEUE_FAMILY_KHR:
            jdata = "VK_SCOPE_QUEUE_FAMILY_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSemaphoreImportFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SEMAPHORE_IMPORT_TEMPORARY_BIT:
            jdata = "VK_SEMAPHORE_IMPORT_TEMPORARY_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSemaphoreType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SEMAPHORE_TYPE_BINARY:
            jdata = "VK_SEMAPHORE_TYPE_BINARY";
            break;
        case VK_SEMAPHORE_TYPE_TIMELINE:
            jdata = "VK_SEMAPHORE_TYPE_TIMELINE";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSemaphoreWaitFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SEMAPHORE_WAIT_ANY_BIT:
            jdata = "VK_SEMAPHORE_WAIT_ANY_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderCodeTypeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SHADER_CODE_TYPE_BINARY_EXT:
            jdata = "VK_SHADER_CODE_TYPE_BINARY_EXT";
            break;
        case VK_SHADER_CODE_TYPE_SPIRV_EXT:
            jdata = "VK_SHADER_CODE_TYPE_SPIRV_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderCorePropertiesFlagBitsAMD& value, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderCreateFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SHADER_CREATE_LINK_STAGE_BIT_EXT:
            jdata = "VK_SHADER_CREATE_LINK_STAGE_BIT_EXT";
            break;
        case VK_SHADER_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT:
            jdata = "VK_SHADER_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT";
            break;
        case VK_SHADER_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT:
            jdata = "VK_SHADER_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT";
            break;
        case VK_SHADER_CREATE_NO_TASK_SHADER_BIT_EXT:
            jdata = "VK_SHADER_CREATE_NO_TASK_SHADER_BIT_EXT";
            break;
        case VK_SHADER_CREATE_DISPATCH_BASE_BIT_EXT:
            jdata = "VK_SHADER_CREATE_DISPATCH_BASE_BIT_EXT";
            break;
        case VK_SHADER_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_EXT:
            jdata = "VK_SHADER_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_EXT";
            break;
        case VK_SHADER_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT:
            jdata = "VK_SHADER_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderFloatControlsIndependence& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY:
            jdata = "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY";
            break;
        case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL:
            jdata = "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL";
            break;
        case VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE:
            jdata = "VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderGroupShaderKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SHADER_GROUP_SHADER_GENERAL_KHR:
            jdata = "VK_SHADER_GROUP_SHADER_GENERAL_KHR";
            break;
        case VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR:
            jdata = "VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR";
            break;
        case VK_SHADER_GROUP_SHADER_ANY_HIT_KHR:
            jdata = "VK_SHADER_GROUP_SHADER_ANY_HIT_KHR";
            break;
        case VK_SHADER_GROUP_SHADER_INTERSECTION_KHR:
            jdata = "VK_SHADER_GROUP_SHADER_INTERSECTION_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderInfoTypeAMD& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SHADER_INFO_TYPE_STATISTICS_AMD:
            jdata = "VK_SHADER_INFO_TYPE_STATISTICS_AMD";
            break;
        case VK_SHADER_INFO_TYPE_BINARY_AMD:
            jdata = "VK_SHADER_INFO_TYPE_BINARY_AMD";
            break;
        case VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD:
            jdata = "VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShaderStageFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SHADER_STAGE_VERTEX_BIT:
            jdata = "VK_SHADER_STAGE_VERTEX_BIT";
            break;
        case VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT:
            jdata = "VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT";
            break;
        case VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT:
            jdata = "VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT";
            break;
        case VK_SHADER_STAGE_GEOMETRY_BIT:
            jdata = "VK_SHADER_STAGE_GEOMETRY_BIT";
            break;
        case VK_SHADER_STAGE_FRAGMENT_BIT:
            jdata = "VK_SHADER_STAGE_FRAGMENT_BIT";
            break;
        case VK_SHADER_STAGE_COMPUTE_BIT:
            jdata = "VK_SHADER_STAGE_COMPUTE_BIT";
            break;
        case VK_SHADER_STAGE_ALL_GRAPHICS:
            jdata = "VK_SHADER_STAGE_ALL_GRAPHICS";
            break;
        case VK_SHADER_STAGE_ALL:
            jdata = "VK_SHADER_STAGE_ALL";
            break;
        case VK_SHADER_STAGE_RAYGEN_BIT_KHR:
            jdata = "VK_SHADER_STAGE_RAYGEN_BIT_KHR";
            break;
        case VK_SHADER_STAGE_ANY_HIT_BIT_KHR:
            jdata = "VK_SHADER_STAGE_ANY_HIT_BIT_KHR";
            break;
        case VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR:
            jdata = "VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR";
            break;
        case VK_SHADER_STAGE_MISS_BIT_KHR:
            jdata = "VK_SHADER_STAGE_MISS_BIT_KHR";
            break;
        case VK_SHADER_STAGE_INTERSECTION_BIT_KHR:
            jdata = "VK_SHADER_STAGE_INTERSECTION_BIT_KHR";
            break;
        case VK_SHADER_STAGE_CALLABLE_BIT_KHR:
            jdata = "VK_SHADER_STAGE_CALLABLE_BIT_KHR";
            break;
        case VK_SHADER_STAGE_TASK_BIT_EXT:
            jdata = "VK_SHADER_STAGE_TASK_BIT_EXT";
            break;
        case VK_SHADER_STAGE_MESH_BIT_EXT:
            jdata = "VK_SHADER_STAGE_MESH_BIT_EXT";
            break;
        case VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI:
            jdata = "VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI";
            break;
        case VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI:
            jdata = "VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkShadingRatePaletteEntryNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV";
            break;
        case VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV:
            jdata = "VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSharingMode& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SHARING_MODE_EXCLUSIVE:
            jdata = "VK_SHARING_MODE_EXCLUSIVE";
            break;
        case VK_SHARING_MODE_CONCURRENT:
            jdata = "VK_SHARING_MODE_CONCURRENT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSparseImageFormatFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT:
            jdata = "VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT";
            break;
        case VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT:
            jdata = "VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT";
            break;
        case VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT:
            jdata = "VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSparseMemoryBindFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SPARSE_MEMORY_BIND_METADATA_BIT:
            jdata = "VK_SPARSE_MEMORY_BIND_METADATA_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkStencilFaceFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_STENCIL_FACE_FRONT_BIT:
            jdata = "VK_STENCIL_FACE_FRONT_BIT";
            break;
        case VK_STENCIL_FACE_BACK_BIT:
            jdata = "VK_STENCIL_FACE_BACK_BIT";
            break;
        case VK_STENCIL_FACE_FRONT_AND_BACK:
            jdata = "VK_STENCIL_FACE_FRONT_AND_BACK";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkStencilOp& value, const JsonOptions& options)
{
    switch (value) {
        case VK_STENCIL_OP_KEEP:
            jdata = "VK_STENCIL_OP_KEEP";
            break;
        case VK_STENCIL_OP_ZERO:
            jdata = "VK_STENCIL_OP_ZERO";
            break;
        case VK_STENCIL_OP_REPLACE:
            jdata = "VK_STENCIL_OP_REPLACE";
            break;
        case VK_STENCIL_OP_INCREMENT_AND_CLAMP:
            jdata = "VK_STENCIL_OP_INCREMENT_AND_CLAMP";
            break;
        case VK_STENCIL_OP_DECREMENT_AND_CLAMP:
            jdata = "VK_STENCIL_OP_DECREMENT_AND_CLAMP";
            break;
        case VK_STENCIL_OP_INVERT:
            jdata = "VK_STENCIL_OP_INVERT";
            break;
        case VK_STENCIL_OP_INCREMENT_AND_WRAP:
            jdata = "VK_STENCIL_OP_INCREMENT_AND_WRAP";
            break;
        case VK_STENCIL_OP_DECREMENT_AND_WRAP:
            jdata = "VK_STENCIL_OP_DECREMENT_AND_WRAP";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkStructureType& value, const JsonOptions& options)
{
    switch (value) {
        case VK_STRUCTURE_TYPE_APPLICATION_INFO:
            jdata = "VK_STRUCTURE_TYPE_APPLICATION_INFO";
            break;
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO:
            jdata = "VK_STRUCTURE_TYPE_SUBMIT_INFO";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
            jdata = "VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE";
            break;
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
            jdata = "VK_STRUCTURE_TYPE_BIND_SPARSE_INFO";
            break;
        case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_FENCE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_EVENT_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET:
            jdata = "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET";
            break;
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
            jdata = "VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET";
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
            jdata = "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO";
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
            jdata = "VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_BARRIER";
            break;
        case VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
            jdata = "VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO";
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
            jdata = "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO";
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            jdata = "VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO";
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            jdata = "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2";
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2:
            jdata = "VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2";
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2:
            jdata = "VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2:
            jdata = "VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2";
            break;
        case VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2:
            jdata = "VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            jdata = "VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO";
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            jdata = "VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO";
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO";
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO";
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO";
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2:
            jdata = "VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2";
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2:
            jdata = "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2";
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2:
            jdata = "VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2";
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2:
            jdata = "VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO:
            jdata = "VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO";
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_END_INFO:
            jdata = "VK_STRUCTURE_TYPE_SUBPASS_END_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            jdata = "VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO:
            jdata = "VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            jdata = "VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT";
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            jdata = "VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            jdata = "VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO";
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO:
            jdata = "VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO";
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO:
            jdata = "VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_BARRIER_2";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER_2";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER_2";
            break;
        case VK_STRUCTURE_TYPE_DEPENDENCY_INFO:
            jdata = "VK_STRUCTURE_TYPE_DEPENDENCY_INFO";
            break;
        case VK_STRUCTURE_TYPE_SUBMIT_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_SUBMIT_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO:
            jdata = "VK_STRUCTURE_TYPE_SEMAPHORE_SUBMIT_INFO";
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO:
            jdata = "VK_STRUCTURE_TYPE_COMMAND_BUFFER_SUBMIT_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2:
            jdata = "VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_COPY_2:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_COPY_2";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COPY_2:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_COPY_2";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_BLIT_2:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_BLIT_2";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            jdata = "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_RENDERING_INFO:
            jdata = "VK_STRUCTURE_TYPE_RENDERING_INFO";
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO:
            jdata = "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_INFO";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            jdata = "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            jdata = "VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_BUFFER_MEMORY_REQUIREMENTS";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_IMAGE_MEMORY_REQUIREMENTS";
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PRESENT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PRESENT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD";
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_PICTURE_RESOURCE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_SESSION_MEMORY_REQUIREMENTS_KHR";
            break;
        case VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_BIND_VIDEO_SESSION_MEMORY_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_SESSION_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_SESSION_PARAMETERS_UPDATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_BEGIN_CODING_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_END_CODING_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_CODING_CONTROL_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_REFERENCE_SLOT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_FORMAT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_FORMAT_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX:
            jdata = "VK_STRUCTURE_TYPE_CU_MODULE_CREATE_INFO_NVX";
            break;
        case VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX:
            jdata = "VK_STRUCTURE_TYPE_CU_FUNCTION_CREATE_INFO_NVX";
            break;
        case VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX:
            jdata = "VK_STRUCTURE_TYPE_CU_LAUNCH_INFO_NVX";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_NALU_SLICE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PICTURE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_DPB_SLOT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_NALU_SLICE_SEGMENT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_GOP_REMAINING_FRAME_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUALITY_LEVEL_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_GET_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_FEEDBACK_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            jdata = "VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD";
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            jdata = "VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD";
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            jdata = "VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX";
            break;
        case VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP:
            jdata = "VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            jdata = "VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT";
            break;
        case VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN:
            jdata = "VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            jdata = "VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            jdata = "VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_HDR_METADATA_EXT:
            jdata = "VK_STRUCTURE_TYPE_HDR_METADATA_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG";
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR:
            jdata = "VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR";
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR:
            jdata = "VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR";
            break;
        case VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK:
            jdata = "VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK";
            break;
        case VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK:
            jdata = "VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK";
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            jdata = "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID";
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID:
            jdata = "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID";
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            jdata = "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID";
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            jdata = "VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID";
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            jdata = "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_FEATURES_AMDX";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ENQUEUE_PROPERTIES_AMDX";
            break;
        case VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_SCRATCH_SIZE_AMDX:
            jdata = "VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_SCRATCH_SIZE_AMDX";
            break;
        case VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_CREATE_INFO_AMDX:
            jdata = "VK_STRUCTURE_TYPE_EXECUTION_GRAPH_PIPELINE_CREATE_INFO_AMDX";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_NODE_CREATE_INFO_AMDX:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_NODE_CREATE_INFO_AMDX";
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            jdata = "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            jdata = "VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            jdata = "VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT";
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_NV:
            jdata = "VK_STRUCTURE_TYPE_GEOMETRY_NV";
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV:
            jdata = "VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV";
            break;
        case VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV:
            jdata = "VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV";
            break;
        case VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            jdata = "VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            jdata = "VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV:
            jdata = "VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV";
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL";
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            jdata = "VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL";
            break;
        case VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL:
            jdata = "VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL";
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL:
            jdata = "VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL";
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL:
            jdata = "VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL";
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL:
            jdata = "VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL";
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL:
            jdata = "VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            jdata = "VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD";
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            jdata = "VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD";
            break;
        case VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV:
            jdata = "VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_TO_IMAGE_COPY_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_TO_MEMORY_COPY_EXT";
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_COPY_IMAGE_TO_MEMORY_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_COPY_MEMORY_TO_IMAGE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_HOST_IMAGE_LAYOUT_TRANSITION_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_COPY_IMAGE_TO_IMAGE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT:
            jdata = "VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE_EXT";
            break;
        case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT:
            jdata = "VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY_EXT";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_MAP_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_UNMAP_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_RELEASE_SWAPCHAIN_IMAGES_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV:
            jdata = "VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV";
            break;
        case VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            jdata = "VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEPTH_BIAS_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            jdata = "VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV";
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            jdata = "VK_STRUCTURE_TYPE_PRESENT_ID_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_GET_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_PARAMETERS_FEEDBACK_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_CUDA_MODULE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_CUDA_FUNCTION_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_CUDA_LAUNCH_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUDA_KERNEL_LAUNCH_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
            jdata = "VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECT_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_METAL_OBJECTS_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_METAL_DEVICE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_METAL_COMMAND_QUEUE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_METAL_BUFFER_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_METAL_BUFFER_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_METAL_TEXTURE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_METAL_TEXTURE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_METAL_IO_SURFACE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_METAL_IO_SURFACE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_EXPORT_METAL_SHARED_EVENT_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_METAL_SHARED_EVENT_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            jdata = "VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV";
            break;
        case VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV:
            jdata = "VK_STRUCTURE_TYPE_CHECKPOINT_DATA_2_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_DENSITY_MAP_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_BUFFER_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_ADDRESS_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_GET_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_OPAQUE_CAPTURE_DESCRIPTOR_DATA_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_BUFFER_BINDING_PUSH_DESCRIPTOR_BUFFER_HANDLE_EXT";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            jdata = "VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_FAULT_COUNTS_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_FAULT_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT:
            jdata = "VK_STRUCTURE_TYPE_VERTEX_INPUT_BINDING_DESCRIPTION_2_EXT";
            break;
        case VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT:
            jdata = "VK_STRUCTURE_TYPE_VERTEX_INPUT_ATTRIBUTE_DESCRIPTION_2_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_ZIRCON_HANDLE_PROPERTIES_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_GET_ZIRCON_HANDLE_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_ZIRCON_HANDLE_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_SEMAPHORE_GET_ZIRCON_HANDLE_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CREATE_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_MEMORY_BUFFER_COLLECTION_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_IMAGE_CREATE_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_PROPERTIES_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_CONSTRAINTS_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_BUFFER_CREATE_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_CONSTRAINTS_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_FORMAT_CONSTRAINTS_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_SYSMEM_COLOR_SPACE_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_COLLECTION_CONSTRAINTS_INFO_FUCHSIA";
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI:
            jdata = "VK_STRUCTURE_TYPE_SUBPASS_SHADING_PIPELINE_CREATE_INFO_HUAWEI";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_FEATURES_HUAWEI";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_SHADING_PROPERTIES_HUAWEI";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI";
            break;
        case VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_MEMORY_GET_REMOTE_ADDRESS_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_PROPERTIES_IDENTIFIER_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROPERTIES_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            jdata = "VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            jdata = "VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT";
            break;
        case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX:
            jdata = "VK_STRUCTURE_TYPE_SCREEN_SURFACE_CREATE_INFO_QNX";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_MICROMAP_BUILD_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_MICROMAP_VERSION_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_COPY_MICROMAP_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_COPY_MICROMAP_TO_MEMORY_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_COPY_MEMORY_TO_MICROMAP_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_MICROMAP_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_MICROMAP_BUILD_SIZES_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            jdata = "VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_BINDING_REFERENCE_VALVE";
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE:
            jdata = "VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_HOST_MAPPING_INFO_VALVE";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_INFO_ARM";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM:
            jdata = "VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_INDIRECT_DEVICE_ADDRESS_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
            jdata = "VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG:
            jdata = "VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_INFO_LUNARG";
            break;
        case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            jdata = "VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT:
            jdata = "VK_STRUCTURE_TYPE_SHADER_MODULE_IDENTIFIER_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_OPTICAL_FLOW_EXECUTE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID";
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            jdata = "VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_RENDERING_AREA_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_DEVICE_IMAGE_SUBRESOURCE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR:
            jdata = "VK_STRUCTURE_TYPE_SUBRESOURCE_LAYOUT_2_KHR";
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR:
            jdata = "VK_STRUCTURE_TYPE_IMAGE_SUBRESOURCE_2_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT";
            break;
        case VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SHADER_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_TILE_PROPERTIES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC";
            break;
        case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            jdata = "VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_LATENCY_SLEEP_MODE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_LATENCY_SLEEP_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_SET_LATENCY_MARKER_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_GET_LATENCY_MARKER_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV:
            jdata = "VK_STRUCTURE_TYPE_LATENCY_TIMINGS_FRAME_REPORT_NV";
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            jdata = "VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV";
            break;
        case VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_OUT_OF_BAND_QUEUE_TYPE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
            jdata = "VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV";
            break;
        case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
            jdata = "VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            jdata = "VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            jdata = "VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
            jdata = "VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX:
            jdata = "VK_STRUCTURE_TYPE_SCREEN_BUFFER_PROPERTIES_QNX";
            break;
        case VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX:
            jdata = "VK_STRUCTURE_TYPE_SCREEN_BUFFER_FORMAT_PROPERTIES_QNX";
            break;
        case VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX:
            jdata = "VK_STRUCTURE_TYPE_IMPORT_SCREEN_BUFFER_INFO_QNX";
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX:
            jdata = "VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_QNX";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_SCREEN_BUFFER_FEATURES_QNX";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES_KHR";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES_KHR";
            break;
        case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR:
            jdata = "VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS_KHR";
            break;
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_SETS_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PUSH_CONSTANTS_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR:
            jdata = "VK_STRUCTURE_TYPE_PUSH_DESCRIPTOR_SET_WITH_TEMPLATE_INFO_KHR";
            break;
        case VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_SET_DESCRIPTOR_BUFFER_OFFSETS_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT:
            jdata = "VK_STRUCTURE_TYPE_BIND_DESCRIPTOR_BUFFER_EMBEDDED_SAMPLERS_INFO_EXT";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV";
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            jdata = "VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSubgroupFeatureFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SUBGROUP_FEATURE_BASIC_BIT:
            jdata = "VK_SUBGROUP_FEATURE_BASIC_BIT";
            break;
        case VK_SUBGROUP_FEATURE_VOTE_BIT:
            jdata = "VK_SUBGROUP_FEATURE_VOTE_BIT";
            break;
        case VK_SUBGROUP_FEATURE_ARITHMETIC_BIT:
            jdata = "VK_SUBGROUP_FEATURE_ARITHMETIC_BIT";
            break;
        case VK_SUBGROUP_FEATURE_BALLOT_BIT:
            jdata = "VK_SUBGROUP_FEATURE_BALLOT_BIT";
            break;
        case VK_SUBGROUP_FEATURE_SHUFFLE_BIT:
            jdata = "VK_SUBGROUP_FEATURE_SHUFFLE_BIT";
            break;
        case VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT:
            jdata = "VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT";
            break;
        case VK_SUBGROUP_FEATURE_CLUSTERED_BIT:
            jdata = "VK_SUBGROUP_FEATURE_CLUSTERED_BIT";
            break;
        case VK_SUBGROUP_FEATURE_QUAD_BIT:
            jdata = "VK_SUBGROUP_FEATURE_QUAD_BIT";
            break;
        case VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV:
            jdata = "VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV";
            break;
        case VK_SUBGROUP_FEATURE_ROTATE_BIT_KHR:
            jdata = "VK_SUBGROUP_FEATURE_ROTATE_BIT_KHR";
            break;
        case VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT_KHR:
            jdata = "VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSubmitFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SUBMIT_PROTECTED_BIT:
            jdata = "VK_SUBMIT_PROTECTED_BIT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSubpassContents& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SUBPASS_CONTENTS_INLINE:
            jdata = "VK_SUBPASS_CONTENTS_INLINE";
            break;
        case VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS:
            jdata = "VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS";
            break;
        case VK_SUBPASS_CONTENTS_INLINE_AND_SECONDARY_COMMAND_BUFFERS_EXT:
            jdata = "VK_SUBPASS_CONTENTS_INLINE_AND_SECONDARY_COMMAND_BUFFERS_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSubpassDescriptionFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX:
            jdata = "VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX";
            break;
        case VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX:
            jdata = "VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX";
            break;
        case VK_SUBPASS_DESCRIPTION_FRAGMENT_REGION_BIT_QCOM:
            jdata = "VK_SUBPASS_DESCRIPTION_FRAGMENT_REGION_BIT_QCOM";
            break;
        case VK_SUBPASS_DESCRIPTION_SHADER_RESOLVE_BIT_QCOM:
            jdata = "VK_SUBPASS_DESCRIPTION_SHADER_RESOLVE_BIT_QCOM";
            break;
        case VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_BIT_EXT:
            jdata = "VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_BIT_EXT";
            break;
        case VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT:
            jdata = "VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT";
            break;
        case VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT:
            jdata = "VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT";
            break;
        case VK_SUBPASS_DESCRIPTION_ENABLE_LEGACY_DITHERING_BIT_EXT:
            jdata = "VK_SUBPASS_DESCRIPTION_ENABLE_LEGACY_DITHERING_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSubpassMergeStatusEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SUBPASS_MERGE_STATUS_MERGED_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_MERGED_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_DISALLOWED_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_DISALLOWED_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SIDE_EFFECTS_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SIDE_EFFECTS_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SAMPLES_MISMATCH_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SAMPLES_MISMATCH_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_VIEWS_MISMATCH_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_VIEWS_MISMATCH_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_ALIASING_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_ALIASING_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPENDENCIES_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPENDENCIES_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INCOMPATIBLE_INPUT_ATTACHMENT_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_TOO_MANY_ATTACHMENTS_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_TOO_MANY_ATTACHMENTS_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INSUFFICIENT_STORAGE_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_INSUFFICIENT_STORAGE_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPTH_STENCIL_COUNT_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_DEPTH_STENCIL_COUNT_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_RESOLVE_ATTACHMENT_REUSE_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_RESOLVE_ATTACHMENT_REUSE_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SINGLE_SUBPASS_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_SINGLE_SUBPASS_EXT";
            break;
        case VK_SUBPASS_MERGE_STATUS_NOT_MERGED_UNSPECIFIED_EXT:
            jdata = "VK_SUBPASS_MERGE_STATUS_NOT_MERGED_UNSPECIFIED_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSurfaceCounterFlagBitsEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SURFACE_COUNTER_VBLANK_BIT_EXT:
            jdata = "VK_SURFACE_COUNTER_VBLANK_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSurfaceTransformFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR:
            jdata = "VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR";
            break;
        case VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR:
            jdata = "VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR";
            break;
        case VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR:
            jdata = "VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR";
            break;
        case VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR:
            jdata = "VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR";
            break;
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR:
            jdata = "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR";
            break;
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR:
            jdata = "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR";
            break;
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR:
            jdata = "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR";
            break;
        case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR:
            jdata = "VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR";
            break;
        case VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR:
            jdata = "VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSwapchainCreateFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR:
            jdata = "VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR";
            break;
        case VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR:
            jdata = "VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR";
            break;
        case VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR:
            jdata = "VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR";
            break;
        case VK_SWAPCHAIN_CREATE_DEFERRED_MEMORY_ALLOCATION_BIT_EXT:
            jdata = "VK_SWAPCHAIN_CREATE_DEFERRED_MEMORY_ALLOCATION_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkSystemAllocationScope& value, const JsonOptions& options)
{
    switch (value) {
        case VK_SYSTEM_ALLOCATION_SCOPE_COMMAND:
            jdata = "VK_SYSTEM_ALLOCATION_SCOPE_COMMAND";
            break;
        case VK_SYSTEM_ALLOCATION_SCOPE_OBJECT:
            jdata = "VK_SYSTEM_ALLOCATION_SCOPE_OBJECT";
            break;
        case VK_SYSTEM_ALLOCATION_SCOPE_CACHE:
            jdata = "VK_SYSTEM_ALLOCATION_SCOPE_CACHE";
            break;
        case VK_SYSTEM_ALLOCATION_SCOPE_DEVICE:
            jdata = "VK_SYSTEM_ALLOCATION_SCOPE_DEVICE";
            break;
        case VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE:
            jdata = "VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkTessellationDomainOrigin& value, const JsonOptions& options)
{
    switch (value) {
        case VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT:
            jdata = "VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT";
            break;
        case VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT:
            jdata = "VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkTimeDomainKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_TIME_DOMAIN_DEVICE_KHR:
            jdata = "VK_TIME_DOMAIN_DEVICE_KHR";
            break;
        case VK_TIME_DOMAIN_CLOCK_MONOTONIC_KHR:
            jdata = "VK_TIME_DOMAIN_CLOCK_MONOTONIC_KHR";
            break;
        case VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_KHR:
            jdata = "VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_KHR";
            break;
        case VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_KHR:
            jdata = "VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkToolPurposeFlagBits& value, const JsonOptions& options)
{
    switch (value) {
        case VK_TOOL_PURPOSE_VALIDATION_BIT:
            jdata = "VK_TOOL_PURPOSE_VALIDATION_BIT";
            break;
        case VK_TOOL_PURPOSE_PROFILING_BIT:
            jdata = "VK_TOOL_PURPOSE_PROFILING_BIT";
            break;
        case VK_TOOL_PURPOSE_TRACING_BIT:
            jdata = "VK_TOOL_PURPOSE_TRACING_BIT";
            break;
        case VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT:
            jdata = "VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT";
            break;
        case VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT:
            jdata = "VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT";
            break;
        case VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT:
            jdata = "VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT";
            break;
        case VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT:
            jdata = "VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationCacheHeaderVersionEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT:
            jdata = "VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationCheckEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VALIDATION_CHECK_ALL_EXT:
            jdata = "VK_VALIDATION_CHECK_ALL_EXT";
            break;
        case VK_VALIDATION_CHECK_SHADERS_EXT:
            jdata = "VK_VALIDATION_CHECK_SHADERS_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationFeatureDisableEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VALIDATION_FEATURE_DISABLE_ALL_EXT:
            jdata = "VK_VALIDATION_FEATURE_DISABLE_ALL_EXT";
            break;
        case VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT:
            jdata = "VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT";
            break;
        case VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT:
            jdata = "VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT";
            break;
        case VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT:
            jdata = "VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT";
            break;
        case VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT:
            jdata = "VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT";
            break;
        case VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT:
            jdata = "VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT";
            break;
        case VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT:
            jdata = "VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT";
            break;
        case VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT:
            jdata = "VK_VALIDATION_FEATURE_DISABLE_SHADER_VALIDATION_CACHE_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkValidationFeatureEnableEXT& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT:
            jdata = "VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT";
            break;
        case VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT:
            jdata = "VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT";
            break;
        case VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT:
            jdata = "VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT";
            break;
        case VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT:
            jdata = "VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT";
            break;
        case VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT:
            jdata = "VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVendorId& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VENDOR_ID_VIV:
            jdata = "VK_VENDOR_ID_VIV";
            break;
        case VK_VENDOR_ID_VSI:
            jdata = "VK_VENDOR_ID_VSI";
            break;
        case VK_VENDOR_ID_KAZAN:
            jdata = "VK_VENDOR_ID_KAZAN";
            break;
        case VK_VENDOR_ID_CODEPLAY:
            jdata = "VK_VENDOR_ID_CODEPLAY";
            break;
        case VK_VENDOR_ID_MESA:
            jdata = "VK_VENDOR_ID_MESA";
            break;
        case VK_VENDOR_ID_POCL:
            jdata = "VK_VENDOR_ID_POCL";
            break;
        case VK_VENDOR_ID_MOBILEYE:
            jdata = "VK_VENDOR_ID_MOBILEYE";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVertexInputRate& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VERTEX_INPUT_RATE_VERTEX:
            jdata = "VK_VERTEX_INPUT_RATE_VERTEX";
            break;
        case VK_VERTEX_INPUT_RATE_INSTANCE:
            jdata = "VK_VERTEX_INPUT_RATE_INSTANCE";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoCapabilityFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_CAPABILITY_PROTECTED_CONTENT_BIT_KHR:
            jdata = "VK_VIDEO_CAPABILITY_PROTECTED_CONTENT_BIT_KHR";
            break;
        case VK_VIDEO_CAPABILITY_SEPARATE_REFERENCE_IMAGES_BIT_KHR:
            jdata = "VK_VIDEO_CAPABILITY_SEPARATE_REFERENCE_IMAGES_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoChromaSubsamplingFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_CHROMA_SUBSAMPLING_INVALID_KHR:
            jdata = "VK_VIDEO_CHROMA_SUBSAMPLING_INVALID_KHR";
            break;
        case VK_VIDEO_CHROMA_SUBSAMPLING_MONOCHROME_BIT_KHR:
            jdata = "VK_VIDEO_CHROMA_SUBSAMPLING_MONOCHROME_BIT_KHR";
            break;
        case VK_VIDEO_CHROMA_SUBSAMPLING_420_BIT_KHR:
            jdata = "VK_VIDEO_CHROMA_SUBSAMPLING_420_BIT_KHR";
            break;
        case VK_VIDEO_CHROMA_SUBSAMPLING_422_BIT_KHR:
            jdata = "VK_VIDEO_CHROMA_SUBSAMPLING_422_BIT_KHR";
            break;
        case VK_VIDEO_CHROMA_SUBSAMPLING_444_BIT_KHR:
            jdata = "VK_VIDEO_CHROMA_SUBSAMPLING_444_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoCodecOperationFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_CODEC_OPERATION_NONE_KHR:
            jdata = "VK_VIDEO_CODEC_OPERATION_NONE_KHR";
            break;
        case VK_VIDEO_CODEC_OPERATION_ENCODE_H264_BIT_KHR:
            jdata = "VK_VIDEO_CODEC_OPERATION_ENCODE_H264_BIT_KHR";
            break;
        case VK_VIDEO_CODEC_OPERATION_ENCODE_H265_BIT_KHR:
            jdata = "VK_VIDEO_CODEC_OPERATION_ENCODE_H265_BIT_KHR";
            break;
        case VK_VIDEO_CODEC_OPERATION_DECODE_H264_BIT_KHR:
            jdata = "VK_VIDEO_CODEC_OPERATION_DECODE_H264_BIT_KHR";
            break;
        case VK_VIDEO_CODEC_OPERATION_DECODE_H265_BIT_KHR:
            jdata = "VK_VIDEO_CODEC_OPERATION_DECODE_H265_BIT_KHR";
            break;
        case VK_VIDEO_CODEC_OPERATION_DECODE_AV1_BIT_KHR:
            jdata = "VK_VIDEO_CODEC_OPERATION_DECODE_AV1_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoCodingControlFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_CODING_CONTROL_RESET_BIT_KHR:
            jdata = "VK_VIDEO_CODING_CONTROL_RESET_BIT_KHR";
            break;
        case VK_VIDEO_CODING_CONTROL_ENCODE_RATE_CONTROL_BIT_KHR:
            jdata = "VK_VIDEO_CODING_CONTROL_ENCODE_RATE_CONTROL_BIT_KHR";
            break;
        case VK_VIDEO_CODING_CONTROL_ENCODE_QUALITY_LEVEL_BIT_KHR:
            jdata = "VK_VIDEO_CODING_CONTROL_ENCODE_QUALITY_LEVEL_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoComponentBitDepthFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_COMPONENT_BIT_DEPTH_INVALID_KHR:
            jdata = "VK_VIDEO_COMPONENT_BIT_DEPTH_INVALID_KHR";
            break;
        case VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR:
            jdata = "VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR";
            break;
        case VK_VIDEO_COMPONENT_BIT_DEPTH_10_BIT_KHR:
            jdata = "VK_VIDEO_COMPONENT_BIT_DEPTH_10_BIT_KHR";
            break;
        case VK_VIDEO_COMPONENT_BIT_DEPTH_12_BIT_KHR:
            jdata = "VK_VIDEO_COMPONENT_BIT_DEPTH_12_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoDecodeCapabilityFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR:
            jdata = "VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR";
            break;
        case VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR:
            jdata = "VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoDecodeH264PictureLayoutFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR:
            jdata = "VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR";
            break;
        case VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_INTERLEAVED_LINES_BIT_KHR:
            jdata = "VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_INTERLEAVED_LINES_BIT_KHR";
            break;
        case VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_SEPARATE_PLANES_BIT_KHR:
            jdata = "VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_SEPARATE_PLANES_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoDecodeUsageFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_DECODE_USAGE_DEFAULT_KHR:
            jdata = "VK_VIDEO_DECODE_USAGE_DEFAULT_KHR";
            break;
        case VK_VIDEO_DECODE_USAGE_TRANSCODING_BIT_KHR:
            jdata = "VK_VIDEO_DECODE_USAGE_TRANSCODING_BIT_KHR";
            break;
        case VK_VIDEO_DECODE_USAGE_OFFLINE_BIT_KHR:
            jdata = "VK_VIDEO_DECODE_USAGE_OFFLINE_BIT_KHR";
            break;
        case VK_VIDEO_DECODE_USAGE_STREAMING_BIT_KHR:
            jdata = "VK_VIDEO_DECODE_USAGE_STREAMING_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeCapabilityFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_CAPABILITY_PRECEDING_EXTERNALLY_ENCODED_BYTES_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_CAPABILITY_PRECEDING_EXTERNALLY_ENCODED_BYTES_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_CAPABILITY_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_DETECTION_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_CAPABILITY_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_DETECTION_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeContentFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_CONTENT_DEFAULT_KHR:
            jdata = "VK_VIDEO_ENCODE_CONTENT_DEFAULT_KHR";
            break;
        case VK_VIDEO_ENCODE_CONTENT_CAMERA_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_CONTENT_CAMERA_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_CONTENT_DESKTOP_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_CONTENT_DESKTOP_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_CONTENT_RENDERED_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_CONTENT_RENDERED_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeFeedbackFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BUFFER_OFFSET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BUFFER_OFFSET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BYTES_WRITTEN_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BYTES_WRITTEN_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_HAS_OVERRIDES_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_HAS_OVERRIDES_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeFlagBitsKHR& value, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(value);
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH264CapabilityFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_H264_CAPABILITY_HRD_COMPLIANCE_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_CAPABILITY_HRD_COMPLIANCE_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_CAPABILITY_ROW_UNALIGNED_SLICE_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_CAPABILITY_ROW_UNALIGNED_SLICE_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_CAPABILITY_DIFFERENT_SLICE_TYPE_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_CAPABILITY_DIFFERENT_SLICE_TYPE_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_CAPABILITY_PER_SLICE_CONSTANT_QP_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_CAPABILITY_PER_SLICE_CONSTANT_QP_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_CAPABILITY_GENERATE_PREFIX_NALU_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_CAPABILITY_GENERATE_PREFIX_NALU_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH264RateControlFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_H264_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_RATE_CONTROL_REGULAR_GOP_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_RATE_CONTROL_REGULAR_GOP_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_RATE_CONTROL_TEMPORAL_LAYER_PATTERN_DYADIC_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_RATE_CONTROL_TEMPORAL_LAYER_PATTERN_DYADIC_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH264StdFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_H264_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_QPPRIME_Y_ZERO_TRANSFORM_BYPASS_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_QPPRIME_Y_ZERO_TRANSFORM_BYPASS_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_SCALING_MATRIX_PRESENT_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_SCALING_MATRIX_PRESENT_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_CHROMA_QP_INDEX_OFFSET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_CHROMA_QP_INDEX_OFFSET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_SECOND_CHROMA_QP_INDEX_OFFSET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_SECOND_CHROMA_QP_INDEX_OFFSET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_PIC_INIT_QP_MINUS26_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_PIC_INIT_QP_MINUS26_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_EXPLICIT_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_EXPLICIT_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_IMPLICIT_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_IMPLICIT_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_TRANSFORM_8X8_MODE_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_TRANSFORM_8X8_MODE_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_DIRECT_SPATIAL_MV_PRED_FLAG_UNSET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_DIRECT_SPATIAL_MV_PRED_FLAG_UNSET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_UNSET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_UNSET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_DIRECT_8X8_INFERENCE_FLAG_UNSET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_DIRECT_8X8_INFERENCE_FLAG_UNSET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_DISABLED_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_DISABLED_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_ENABLED_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_ENABLED_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_PARTIAL_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_PARTIAL_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_SLICE_QP_DELTA_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_SLICE_QP_DELTA_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H264_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H264_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH265CapabilityFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_H265_CAPABILITY_HRD_COMPLIANCE_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CAPABILITY_HRD_COMPLIANCE_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CAPABILITY_ROW_UNALIGNED_SLICE_SEGMENT_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CAPABILITY_ROW_UNALIGNED_SLICE_SEGMENT_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CAPABILITY_DIFFERENT_SLICE_SEGMENT_TYPE_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CAPABILITY_DIFFERENT_SLICE_SEGMENT_TYPE_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CAPABILITY_PER_SLICE_SEGMENT_CONSTANT_QP_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CAPABILITY_PER_SLICE_SEGMENT_CONSTANT_QP_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_TILES_PER_SLICE_SEGMENT_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_TILES_PER_SLICE_SEGMENT_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_SLICE_SEGMENTS_PER_TILE_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_SLICE_SEGMENTS_PER_TILE_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH265CtbSizeFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_H265_CTB_SIZE_16_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CTB_SIZE_16_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CTB_SIZE_32_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CTB_SIZE_32_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_CTB_SIZE_64_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_CTB_SIZE_64_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH265RateControlFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_H265_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_RATE_CONTROL_REGULAR_GOP_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_RATE_CONTROL_REGULAR_GOP_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_RATE_CONTROL_TEMPORAL_SUB_LAYER_PATTERN_DYADIC_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_RATE_CONTROL_TEMPORAL_SUB_LAYER_PATTERN_DYADIC_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH265StdFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_H265_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_SAMPLE_ADAPTIVE_OFFSET_ENABLED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_SAMPLE_ADAPTIVE_OFFSET_ENABLED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_SCALING_LIST_DATA_PRESENT_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_SCALING_LIST_DATA_PRESENT_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_PCM_ENABLED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_PCM_ENABLED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_SPS_TEMPORAL_MVP_ENABLED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_SPS_TEMPORAL_MVP_ENABLED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_INIT_QP_MINUS26_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_INIT_QP_MINUS26_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_WEIGHTED_BIPRED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_WEIGHTED_BIPRED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_LOG2_PARALLEL_MERGE_LEVEL_MINUS2_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_LOG2_PARALLEL_MERGE_LEVEL_MINUS2_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_SIGN_DATA_HIDING_ENABLED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_SIGN_DATA_HIDING_ENABLED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_UNSET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_UNSET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_PPS_SLICE_CHROMA_QP_OFFSETS_PRESENT_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_PPS_SLICE_CHROMA_QP_OFFSETS_PRESENT_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_TRANSQUANT_BYPASS_ENABLED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_TRANSQUANT_BYPASS_ENABLED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_ENTROPY_CODING_SYNC_ENABLED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_ENTROPY_CODING_SYNC_ENABLED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENTS_ENABLED_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENTS_ENABLED_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENT_FLAG_SET_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENT_FLAG_SET_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_SLICE_QP_DELTA_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_SLICE_QP_DELTA_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeH265TransformBlockSizeFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_4_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_4_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_8_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_8_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_16_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_16_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_32_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_32_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeRateControlModeFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DEFAULT_KHR:
            jdata = "VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DEFAULT_KHR";
            break;
        case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DISABLED_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DISABLED_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_CBR_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_RATE_CONTROL_MODE_CBR_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_VBR_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_RATE_CONTROL_MODE_VBR_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeTuningModeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_TUNING_MODE_DEFAULT_KHR:
            jdata = "VK_VIDEO_ENCODE_TUNING_MODE_DEFAULT_KHR";
            break;
        case VK_VIDEO_ENCODE_TUNING_MODE_HIGH_QUALITY_KHR:
            jdata = "VK_VIDEO_ENCODE_TUNING_MODE_HIGH_QUALITY_KHR";
            break;
        case VK_VIDEO_ENCODE_TUNING_MODE_LOW_LATENCY_KHR:
            jdata = "VK_VIDEO_ENCODE_TUNING_MODE_LOW_LATENCY_KHR";
            break;
        case VK_VIDEO_ENCODE_TUNING_MODE_ULTRA_LOW_LATENCY_KHR:
            jdata = "VK_VIDEO_ENCODE_TUNING_MODE_ULTRA_LOW_LATENCY_KHR";
            break;
        case VK_VIDEO_ENCODE_TUNING_MODE_LOSSLESS_KHR:
            jdata = "VK_VIDEO_ENCODE_TUNING_MODE_LOSSLESS_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoEncodeUsageFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_ENCODE_USAGE_DEFAULT_KHR:
            jdata = "VK_VIDEO_ENCODE_USAGE_DEFAULT_KHR";
            break;
        case VK_VIDEO_ENCODE_USAGE_TRANSCODING_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_USAGE_TRANSCODING_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_USAGE_STREAMING_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_USAGE_STREAMING_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_USAGE_RECORDING_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_USAGE_RECORDING_BIT_KHR";
            break;
        case VK_VIDEO_ENCODE_USAGE_CONFERENCING_BIT_KHR:
            jdata = "VK_VIDEO_ENCODE_USAGE_CONFERENCING_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkVideoSessionCreateFlagBitsKHR& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIDEO_SESSION_CREATE_PROTECTED_CONTENT_BIT_KHR:
            jdata = "VK_VIDEO_SESSION_CREATE_PROTECTED_CONTENT_BIT_KHR";
            break;
        case VK_VIDEO_SESSION_CREATE_ALLOW_ENCODE_PARAMETER_OPTIMIZATIONS_BIT_KHR:
            jdata = "VK_VIDEO_SESSION_CREATE_ALLOW_ENCODE_PARAMETER_OPTIMIZATIONS_BIT_KHR";
            break;
        case VK_VIDEO_SESSION_CREATE_INLINE_QUERIES_BIT_KHR:
            jdata = "VK_VIDEO_SESSION_CREATE_INLINE_QUERIES_BIT_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const VkViewportCoordinateSwizzleNV& value, const JsonOptions& options)
{
    switch (value) {
        case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV:
            jdata = "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV";
            break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV:
            jdata = "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV";
            break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV:
            jdata = "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV";
            break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV:
            jdata = "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV";
            break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV:
            jdata = "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV";
            break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV:
            jdata = "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV";
            break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV:
            jdata = "VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV";
            break;
        case VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV:
            jdata = "VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(VkAccelerationStructureCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR:
                return std::string("VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR");
            case VK_ACCELERATION_STRUCTURE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
                return std::string("VK_ACCELERATION_STRUCTURE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT");
            case VK_ACCELERATION_STRUCTURE_CREATE_MOTION_BIT_NV:
                return std::string("VK_ACCELERATION_STRUCTURE_CREATE_MOTION_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkAccelerationStructureMotionInfoFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkAccelerationStructureMotionInstanceFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkAccessFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_ACCESS_INDIRECT_COMMAND_READ_BIT:
                return std::string("VK_ACCESS_INDIRECT_COMMAND_READ_BIT");
            case VK_ACCESS_INDEX_READ_BIT:
                return std::string("VK_ACCESS_INDEX_READ_BIT");
            case VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT:
                return std::string("VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT");
            case VK_ACCESS_UNIFORM_READ_BIT:
                return std::string("VK_ACCESS_UNIFORM_READ_BIT");
            case VK_ACCESS_INPUT_ATTACHMENT_READ_BIT:
                return std::string("VK_ACCESS_INPUT_ATTACHMENT_READ_BIT");
            case VK_ACCESS_SHADER_READ_BIT:
                return std::string("VK_ACCESS_SHADER_READ_BIT");
            case VK_ACCESS_SHADER_WRITE_BIT:
                return std::string("VK_ACCESS_SHADER_WRITE_BIT");
            case VK_ACCESS_COLOR_ATTACHMENT_READ_BIT:
                return std::string("VK_ACCESS_COLOR_ATTACHMENT_READ_BIT");
            case VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT:
                return std::string("VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT");
            case VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT:
                return std::string("VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT");
            case VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT:
                return std::string("VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT");
            case VK_ACCESS_TRANSFER_READ_BIT:
                return std::string("VK_ACCESS_TRANSFER_READ_BIT");
            case VK_ACCESS_TRANSFER_WRITE_BIT:
                return std::string("VK_ACCESS_TRANSFER_WRITE_BIT");
            case VK_ACCESS_HOST_READ_BIT:
                return std::string("VK_ACCESS_HOST_READ_BIT");
            case VK_ACCESS_HOST_WRITE_BIT:
                return std::string("VK_ACCESS_HOST_WRITE_BIT");
            case VK_ACCESS_MEMORY_READ_BIT:
                return std::string("VK_ACCESS_MEMORY_READ_BIT");
            case VK_ACCESS_MEMORY_WRITE_BIT:
                return std::string("VK_ACCESS_MEMORY_WRITE_BIT");
            case VK_ACCESS_NONE:
                return std::string("VK_ACCESS_NONE");
            case VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT:
                return std::string("VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT");
            case VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT:
                return std::string("VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT");
            case VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT:
                return std::string("VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT");
            case VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT:
                return std::string("VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT");
            case VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT:
                return std::string("VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT");
            case VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR:
                return std::string("VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR");
            case VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR:
                return std::string("VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR");
            case VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT:
                return std::string("VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT");
            case VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR:
                return std::string("VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR");
            case VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV:
                return std::string("VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV");
            case VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV:
                return std::string("VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkAccessFlags2_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_ACCESS_2_NONE:
                return std::string("VK_ACCESS_2_NONE");
            case VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT:
                return std::string("VK_ACCESS_2_INDIRECT_COMMAND_READ_BIT");
            case VK_ACCESS_2_INDEX_READ_BIT:
                return std::string("VK_ACCESS_2_INDEX_READ_BIT");
            case VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT:
                return std::string("VK_ACCESS_2_VERTEX_ATTRIBUTE_READ_BIT");
            case VK_ACCESS_2_UNIFORM_READ_BIT:
                return std::string("VK_ACCESS_2_UNIFORM_READ_BIT");
            case VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT:
                return std::string("VK_ACCESS_2_INPUT_ATTACHMENT_READ_BIT");
            case VK_ACCESS_2_SHADER_READ_BIT:
                return std::string("VK_ACCESS_2_SHADER_READ_BIT");
            case VK_ACCESS_2_SHADER_WRITE_BIT:
                return std::string("VK_ACCESS_2_SHADER_WRITE_BIT");
            case VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT:
                return std::string("VK_ACCESS_2_COLOR_ATTACHMENT_READ_BIT");
            case VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT:
                return std::string("VK_ACCESS_2_COLOR_ATTACHMENT_WRITE_BIT");
            case VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT:
                return std::string("VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_READ_BIT");
            case VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT:
                return std::string("VK_ACCESS_2_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT");
            case VK_ACCESS_2_TRANSFER_READ_BIT:
                return std::string("VK_ACCESS_2_TRANSFER_READ_BIT");
            case VK_ACCESS_2_TRANSFER_WRITE_BIT:
                return std::string("VK_ACCESS_2_TRANSFER_WRITE_BIT");
            case VK_ACCESS_2_HOST_READ_BIT:
                return std::string("VK_ACCESS_2_HOST_READ_BIT");
            case VK_ACCESS_2_HOST_WRITE_BIT:
                return std::string("VK_ACCESS_2_HOST_WRITE_BIT");
            case VK_ACCESS_2_MEMORY_READ_BIT:
                return std::string("VK_ACCESS_2_MEMORY_READ_BIT");
            case VK_ACCESS_2_MEMORY_WRITE_BIT:
                return std::string("VK_ACCESS_2_MEMORY_WRITE_BIT");
            case VK_ACCESS_2_SHADER_SAMPLED_READ_BIT:
                return std::string("VK_ACCESS_2_SHADER_SAMPLED_READ_BIT");
            case VK_ACCESS_2_SHADER_STORAGE_READ_BIT:
                return std::string("VK_ACCESS_2_SHADER_STORAGE_READ_BIT");
            case VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT:
                return std::string("VK_ACCESS_2_SHADER_STORAGE_WRITE_BIT");
            case VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR:
                return std::string("VK_ACCESS_2_VIDEO_DECODE_READ_BIT_KHR");
            case VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR:
                return std::string("VK_ACCESS_2_VIDEO_DECODE_WRITE_BIT_KHR");
            case VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR:
                return std::string("VK_ACCESS_2_VIDEO_ENCODE_READ_BIT_KHR");
            case VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR:
                return std::string("VK_ACCESS_2_VIDEO_ENCODE_WRITE_BIT_KHR");
            case VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT:
                return std::string("VK_ACCESS_2_TRANSFORM_FEEDBACK_WRITE_BIT_EXT");
            case VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT");
            case VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT:
                return std::string("VK_ACCESS_2_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT");
            case VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_CONDITIONAL_RENDERING_READ_BIT_EXT");
            case VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_NV:
                return std::string("VK_ACCESS_2_COMMAND_PREPROCESS_READ_BIT_NV");
            case VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_NV:
                return std::string("VK_ACCESS_2_COMMAND_PREPROCESS_WRITE_BIT_NV");
            case VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR:
                return std::string("VK_ACCESS_2_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR");
            case VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR:
                return std::string("VK_ACCESS_2_ACCELERATION_STRUCTURE_READ_BIT_KHR");
            case VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR:
                return std::string("VK_ACCESS_2_ACCELERATION_STRUCTURE_WRITE_BIT_KHR");
            case VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_FRAGMENT_DENSITY_MAP_READ_BIT_EXT");
            case VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT:
                return std::string("VK_ACCESS_2_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT");
            case VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_DESCRIPTOR_BUFFER_READ_BIT_EXT");
            case VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI:
                return std::string("VK_ACCESS_2_INVOCATION_MASK_READ_BIT_HUAWEI");
            case VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR:
                return std::string("VK_ACCESS_2_SHADER_BINDING_TABLE_READ_BIT_KHR");
            case VK_ACCESS_2_MICROMAP_READ_BIT_EXT:
                return std::string("VK_ACCESS_2_MICROMAP_READ_BIT_EXT");
            case VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT:
                return std::string("VK_ACCESS_2_MICROMAP_WRITE_BIT_EXT");
            case VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV:
                return std::string("VK_ACCESS_2_OPTICAL_FLOW_READ_BIT_NV");
            case VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV:
                return std::string("VK_ACCESS_2_OPTICAL_FLOW_WRITE_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkAcquireProfilingLockFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkAndroidSurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkAttachmentDescriptionFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT:
                return std::string("VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkBufferCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_BUFFER_CREATE_SPARSE_BINDING_BIT:
                return std::string("VK_BUFFER_CREATE_SPARSE_BINDING_BIT");
            case VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT:
                return std::string("VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT");
            case VK_BUFFER_CREATE_SPARSE_ALIASED_BIT:
                return std::string("VK_BUFFER_CREATE_SPARSE_ALIASED_BIT");
            case VK_BUFFER_CREATE_PROTECTED_BIT:
                return std::string("VK_BUFFER_CREATE_PROTECTED_BIT");
            case VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT:
                return std::string("VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT");
            case VK_BUFFER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
                return std::string("VK_BUFFER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT");
            case VK_BUFFER_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR:
                return std::string("VK_BUFFER_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkBufferUsageFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_BUFFER_USAGE_TRANSFER_SRC_BIT:
                return std::string("VK_BUFFER_USAGE_TRANSFER_SRC_BIT");
            case VK_BUFFER_USAGE_TRANSFER_DST_BIT:
                return std::string("VK_BUFFER_USAGE_TRANSFER_DST_BIT");
            case VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT");
            case VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT");
            case VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT");
            case VK_BUFFER_USAGE_STORAGE_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_STORAGE_BUFFER_BIT");
            case VK_BUFFER_USAGE_INDEX_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_INDEX_BUFFER_BIT");
            case VK_BUFFER_USAGE_VERTEX_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_VERTEX_BUFFER_BIT");
            case VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT:
                return std::string("VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT");
            case VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT:
                return std::string("VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT");
            case VK_BUFFER_USAGE_VIDEO_DECODE_SRC_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_VIDEO_DECODE_SRC_BIT_KHR");
            case VK_BUFFER_USAGE_VIDEO_DECODE_DST_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_VIDEO_DECODE_DST_BIT_KHR");
            case VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT");
            case VK_BUFFER_USAGE_EXECUTION_GRAPH_SCRATCH_BIT_AMDX:
                return std::string("VK_BUFFER_USAGE_EXECUTION_GRAPH_SCRATCH_BIT_AMDX");
            case VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR");
            case VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR");
            case VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR");
            case VK_BUFFER_USAGE_VIDEO_ENCODE_DST_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_VIDEO_ENCODE_DST_BIT_KHR");
            case VK_BUFFER_USAGE_VIDEO_ENCODE_SRC_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_VIDEO_ENCODE_SRC_BIT_KHR");
            case VK_BUFFER_USAGE_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT");
            case VK_BUFFER_USAGE_MICROMAP_STORAGE_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_MICROMAP_STORAGE_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkBufferUsageFlags2KHR_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT_KHR");
            case VK_BUFFER_USAGE_2_TRANSFER_DST_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_TRANSFER_DST_BIT_KHR");
            case VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_UNIFORM_TEXEL_BUFFER_BIT_KHR");
            case VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_STORAGE_TEXEL_BUFFER_BIT_KHR");
            case VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_UNIFORM_BUFFER_BIT_KHR");
            case VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_STORAGE_BUFFER_BIT_KHR");
            case VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_INDEX_BUFFER_BIT_KHR");
            case VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_VERTEX_BUFFER_BIT_KHR");
            case VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_INDIRECT_BUFFER_BIT_KHR");
            case VK_BUFFER_USAGE_2_EXECUTION_GRAPH_SCRATCH_BIT_AMDX:
                return std::string("VK_BUFFER_USAGE_2_EXECUTION_GRAPH_SCRATCH_BIT_AMDX");
            case VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_CONDITIONAL_RENDERING_BIT_EXT");
            case VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_SHADER_BINDING_TABLE_BIT_KHR");
            case VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_VIDEO_DECODE_SRC_BIT_KHR");
            case VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_VIDEO_DECODE_DST_BIT_KHR");
            case VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_VIDEO_ENCODE_DST_BIT_KHR");
            case VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_VIDEO_ENCODE_SRC_BIT_KHR");
            case VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT_KHR");
            case VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR");
            case VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR:
                return std::string("VK_BUFFER_USAGE_2_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR");
            case VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_SAMPLER_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_RESOURCE_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_PUSH_DESCRIPTORS_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_MICROMAP_BUILD_INPUT_READ_ONLY_BIT_EXT");
            case VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT:
                return std::string("VK_BUFFER_USAGE_2_MICROMAP_STORAGE_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkBufferViewCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkBuildAccelerationStructureFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR");
            case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR");
            case VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR");
            case VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR");
            case VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR");
            case VK_BUILD_ACCELERATION_STRUCTURE_MOTION_BIT_NV:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_MOTION_BIT_NV");
            case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_UPDATE_EXT:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_UPDATE_EXT");
            case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISABLE_OPACITY_MICROMAPS_EXT:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISABLE_OPACITY_MICROMAPS_EXT");
            case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_DATA_UPDATE_EXT:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_OPACITY_MICROMAP_DATA_UPDATE_EXT");
            case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISPLACEMENT_MICROMAP_UPDATE_NV:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DISPLACEMENT_MICROMAP_UPDATE_NV");
            case VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DATA_ACCESS_KHR:
                return std::string("VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_DATA_ACCESS_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkBuildMicromapFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_BUILD_MICROMAP_PREFER_FAST_TRACE_BIT_EXT:
                return std::string("VK_BUILD_MICROMAP_PREFER_FAST_TRACE_BIT_EXT");
            case VK_BUILD_MICROMAP_PREFER_FAST_BUILD_BIT_EXT:
                return std::string("VK_BUILD_MICROMAP_PREFER_FAST_BUILD_BIT_EXT");
            case VK_BUILD_MICROMAP_ALLOW_COMPACTION_BIT_EXT:
                return std::string("VK_BUILD_MICROMAP_ALLOW_COMPACTION_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkColorComponentFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_COLOR_COMPONENT_R_BIT:
                return std::string("VK_COLOR_COMPONENT_R_BIT");
            case VK_COLOR_COMPONENT_G_BIT:
                return std::string("VK_COLOR_COMPONENT_G_BIT");
            case VK_COLOR_COMPONENT_B_BIT:
                return std::string("VK_COLOR_COMPONENT_B_BIT");
            case VK_COLOR_COMPONENT_A_BIT:
                return std::string("VK_COLOR_COMPONENT_A_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkCommandBufferResetFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT:
                return std::string("VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkCommandBufferUsageFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT:
                return std::string("VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT");
            case VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT:
                return std::string("VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT");
            case VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT:
                return std::string("VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkCommandPoolCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_COMMAND_POOL_CREATE_TRANSIENT_BIT:
                return std::string("VK_COMMAND_POOL_CREATE_TRANSIENT_BIT");
            case VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT:
                return std::string("VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT");
            case VK_COMMAND_POOL_CREATE_PROTECTED_BIT:
                return std::string("VK_COMMAND_POOL_CREATE_PROTECTED_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkCommandPoolResetFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT:
                return std::string("VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkCommandPoolTrimFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkCompositeAlphaFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR:
                return std::string("VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR");
            case VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR:
                return std::string("VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR");
            case VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR:
                return std::string("VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR");
            case VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR:
                return std::string("VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkConditionalRenderingFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT:
                return std::string("VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkCullModeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_CULL_MODE_NONE:
                return std::string("VK_CULL_MODE_NONE");
            case VK_CULL_MODE_FRONT_BIT:
                return std::string("VK_CULL_MODE_FRONT_BIT");
            case VK_CULL_MODE_BACK_BIT:
                return std::string("VK_CULL_MODE_BACK_BIT");
            case VK_CULL_MODE_FRONT_AND_BACK:
                return std::string("VK_CULL_MODE_FRONT_AND_BACK");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDebugReportFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DEBUG_REPORT_INFORMATION_BIT_EXT:
                return std::string("VK_DEBUG_REPORT_INFORMATION_BIT_EXT");
            case VK_DEBUG_REPORT_WARNING_BIT_EXT:
                return std::string("VK_DEBUG_REPORT_WARNING_BIT_EXT");
            case VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT:
                return std::string("VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT");
            case VK_DEBUG_REPORT_ERROR_BIT_EXT:
                return std::string("VK_DEBUG_REPORT_ERROR_BIT_EXT");
            case VK_DEBUG_REPORT_DEBUG_BIT_EXT:
                return std::string("VK_DEBUG_REPORT_DEBUG_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDebugUtilsMessageSeverityFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
                return std::string("VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT");
            case VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
                return std::string("VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT");
            case VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
                return std::string("VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT");
            case VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
                return std::string("VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDebugUtilsMessageTypeFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT:
                return std::string("VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT");
            case VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT:
                return std::string("VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT");
            case VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT:
                return std::string("VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT");
            case VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT:
                return std::string("VK_DEBUG_UTILS_MESSAGE_TYPE_DEVICE_ADDRESS_BINDING_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDebugUtilsMessengerCallbackDataFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkDebugUtilsMessengerCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkDependencyFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DEPENDENCY_BY_REGION_BIT:
                return std::string("VK_DEPENDENCY_BY_REGION_BIT");
            case VK_DEPENDENCY_DEVICE_GROUP_BIT:
                return std::string("VK_DEPENDENCY_DEVICE_GROUP_BIT");
            case VK_DEPENDENCY_VIEW_LOCAL_BIT:
                return std::string("VK_DEPENDENCY_VIEW_LOCAL_BIT");
            case VK_DEPENDENCY_FEEDBACK_LOOP_BIT_EXT:
                return std::string("VK_DEPENDENCY_FEEDBACK_LOOP_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDescriptorBindingFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT:
                return std::string("VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT");
            case VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT:
                return std::string("VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT");
            case VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT:
                return std::string("VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT");
            case VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT:
                return std::string("VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDescriptorPoolCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT:
                return std::string("VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT");
            case VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT:
                return std::string("VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT");
            case VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_EXT:
                return std::string("VK_DESCRIPTOR_POOL_CREATE_HOST_ONLY_BIT_EXT");
            case VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_SETS_BIT_NV:
                return std::string("VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_SETS_BIT_NV");
            case VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_POOLS_BIT_NV:
                return std::string("VK_DESCRIPTOR_POOL_CREATE_ALLOW_OVERALLOCATION_POOLS_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDescriptorPoolResetFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkDescriptorSetLayoutCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT:
                return std::string("VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT");
            case VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR:
                return std::string("VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR");
            case VK_DESCRIPTOR_SET_LAYOUT_CREATE_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_DESCRIPTOR_SET_LAYOUT_CREATE_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_DESCRIPTOR_SET_LAYOUT_CREATE_EMBEDDED_IMMUTABLE_SAMPLERS_BIT_EXT:
                return std::string("VK_DESCRIPTOR_SET_LAYOUT_CREATE_EMBEDDED_IMMUTABLE_SAMPLERS_BIT_EXT");
            case VK_DESCRIPTOR_SET_LAYOUT_CREATE_INDIRECT_BINDABLE_BIT_NV:
                return std::string("VK_DESCRIPTOR_SET_LAYOUT_CREATE_INDIRECT_BINDABLE_BIT_NV");
            case VK_DESCRIPTOR_SET_LAYOUT_CREATE_HOST_ONLY_POOL_BIT_EXT:
                return std::string("VK_DESCRIPTOR_SET_LAYOUT_CREATE_HOST_ONLY_POOL_BIT_EXT");
            case VK_DESCRIPTOR_SET_LAYOUT_CREATE_PER_STAGE_BIT_NV:
                return std::string("VK_DESCRIPTOR_SET_LAYOUT_CREATE_PER_STAGE_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDescriptorUpdateTemplateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkDeviceAddressBindingFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DEVICE_ADDRESS_BINDING_INTERNAL_OBJECT_BIT_EXT:
                return std::string("VK_DEVICE_ADDRESS_BINDING_INTERNAL_OBJECT_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDeviceCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkDeviceDiagnosticsConfigFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV:
                return std::string("VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV");
            case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV:
                return std::string("VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV");
            case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV:
                return std::string("VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV");
            case VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_ERROR_REPORTING_BIT_NV:
                return std::string("VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_ERROR_REPORTING_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDeviceGroupPresentModeFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR:
                return std::string("VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR");
            case VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR:
                return std::string("VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR");
            case VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR:
                return std::string("VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR");
            case VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR:
                return std::string("VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDeviceMemoryReportFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkDeviceQueueCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT:
                return std::string("VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDirectDriverLoadingFlagsLUNARG_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkDirectFBSurfaceCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkDisplayModeCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkDisplayPlaneAlphaFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR:
                return std::string("VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR");
            case VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR:
                return std::string("VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR");
            case VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR:
                return std::string("VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR");
            case VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR:
                return std::string("VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkDisplaySurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkEventCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_EVENT_CREATE_DEVICE_ONLY_BIT:
                return std::string("VK_EVENT_CREATE_DEVICE_ONLY_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkExternalFenceFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT:
                return std::string("VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT");
            case VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT:
                return std::string("VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkExternalFenceHandleTypeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT:
                return std::string("VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT");
            case VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT:
                return std::string("VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT");
            case VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT:
                return std::string("VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT");
            case VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT:
                return std::string("VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkExternalMemoryFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT:
                return std::string("VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT");
            case VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT:
                return std::string("VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT");
            case VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT:
                return std::string("VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkExternalMemoryFeatureFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV:
                return std::string("VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV");
            case VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV:
                return std::string("VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV");
            case VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV:
                return std::string("VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkExternalMemoryHandleTypeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_ZIRCON_VMO_BIT_FUCHSIA");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_RDMA_ADDRESS_BIT_NV:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_RDMA_ADDRESS_BIT_NV");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_SCREEN_BUFFER_BIT_QNX:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_SCREEN_BUFFER_BIT_QNX");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV");
            case VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV:
                return std::string("VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkExternalSemaphoreFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT:
                return std::string("VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT");
            case VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT:
                return std::string("VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkExternalSemaphoreHandleTypeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT:
                return std::string("VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT");
            case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT:
                return std::string("VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT");
            case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT:
                return std::string("VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT");
            case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT:
                return std::string("VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT");
            case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT:
                return std::string("VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT");
            case VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA:
                return std::string("VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_ZIRCON_EVENT_BIT_FUCHSIA");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkFenceCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_FENCE_CREATE_SIGNALED_BIT:
                return std::string("VK_FENCE_CREATE_SIGNALED_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkFenceImportFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_FENCE_IMPORT_TEMPORARY_BIT:
                return std::string("VK_FENCE_IMPORT_TEMPORARY_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkFormatFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT:
                return std::string("VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT");
            case VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT:
                return std::string("VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT");
            case VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT:
                return std::string("VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT");
            case VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT:
                return std::string("VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT");
            case VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT:
                return std::string("VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT");
            case VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT:
                return std::string("VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT");
            case VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT:
                return std::string("VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT");
            case VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT:
                return std::string("VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT");
            case VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT:
                return std::string("VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT");
            case VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT:
                return std::string("VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT");
            case VK_FORMAT_FEATURE_BLIT_SRC_BIT:
                return std::string("VK_FORMAT_FEATURE_BLIT_SRC_BIT");
            case VK_FORMAT_FEATURE_BLIT_DST_BIT:
                return std::string("VK_FORMAT_FEATURE_BLIT_DST_BIT");
            case VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT:
                return std::string("VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT");
            case VK_FORMAT_FEATURE_TRANSFER_SRC_BIT:
                return std::string("VK_FORMAT_FEATURE_TRANSFER_SRC_BIT");
            case VK_FORMAT_FEATURE_TRANSFER_DST_BIT:
                return std::string("VK_FORMAT_FEATURE_TRANSFER_DST_BIT");
            case VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT:
                return std::string("VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT");
            case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT:
                return std::string("VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT");
            case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT:
                return std::string("VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT");
            case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT:
                return std::string("VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT");
            case VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT:
                return std::string("VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT");
            case VK_FORMAT_FEATURE_DISJOINT_BIT:
                return std::string("VK_FORMAT_FEATURE_DISJOINT_BIT");
            case VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT:
                return std::string("VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT");
            case VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT:
                return std::string("VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT");
            case VK_FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_VIDEO_DECODE_OUTPUT_BIT_KHR");
            case VK_FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_VIDEO_DECODE_DPB_BIT_KHR");
            case VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR");
            case VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT:
                return std::string("VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT");
            case VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT:
                return std::string("VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT");
            case VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_VIDEO_ENCODE_INPUT_BIT_KHR");
            case VK_FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_VIDEO_ENCODE_DPB_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkFormatFeatureFlags2_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_IMAGE_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_IMAGE_ATOMIC_BIT");
            case VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_UNIFORM_TEXEL_BUFFER_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_TEXEL_BUFFER_ATOMIC_BIT");
            case VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_VERTEX_BUFFER_BIT");
            case VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BIT");
            case VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT:
                return std::string("VK_FORMAT_FEATURE_2_COLOR_ATTACHMENT_BLEND_BIT");
            case VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_DEPTH_STENCIL_ATTACHMENT_BIT");
            case VK_FORMAT_FEATURE_2_BLIT_SRC_BIT:
                return std::string("VK_FORMAT_FEATURE_2_BLIT_SRC_BIT");
            case VK_FORMAT_FEATURE_2_BLIT_DST_BIT:
                return std::string("VK_FORMAT_FEATURE_2_BLIT_DST_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_LINEAR_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_CUBIC_BIT");
            case VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT:
                return std::string("VK_FORMAT_FEATURE_2_TRANSFER_SRC_BIT");
            case VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT:
                return std::string("VK_FORMAT_FEATURE_2_TRANSFER_DST_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_FILTER_MINMAX_BIT");
            case VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT:
                return std::string("VK_FORMAT_FEATURE_2_MIDPOINT_CHROMA_SAMPLES_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT");
            case VK_FORMAT_FEATURE_2_DISJOINT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_DISJOINT_BIT");
            case VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT:
                return std::string("VK_FORMAT_FEATURE_2_COSITED_CHROMA_SAMPLES_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_READ_WITHOUT_FORMAT_BIT");
            case VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT:
                return std::string("VK_FORMAT_FEATURE_2_STORAGE_WRITE_WITHOUT_FORMAT_BIT");
            case VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT:
                return std::string("VK_FORMAT_FEATURE_2_SAMPLED_IMAGE_DEPTH_COMPARISON_BIT");
            case VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_VIDEO_DECODE_OUTPUT_BIT_KHR");
            case VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_VIDEO_DECODE_DPB_BIT_KHR");
            case VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR");
            case VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT:
                return std::string("VK_FORMAT_FEATURE_2_FRAGMENT_DENSITY_MAP_BIT_EXT");
            case VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT_EXT:
                return std::string("VK_FORMAT_FEATURE_2_HOST_IMAGE_TRANSFER_BIT_EXT");
            case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_VIDEO_ENCODE_INPUT_BIT_KHR");
            case VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR:
                return std::string("VK_FORMAT_FEATURE_2_VIDEO_ENCODE_DPB_BIT_KHR");
            case VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV:
                return std::string("VK_FORMAT_FEATURE_2_LINEAR_COLOR_ATTACHMENT_BIT_NV");
            case VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM:
                return std::string("VK_FORMAT_FEATURE_2_WEIGHT_IMAGE_BIT_QCOM");
            case VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM:
                return std::string("VK_FORMAT_FEATURE_2_WEIGHT_SAMPLED_IMAGE_BIT_QCOM");
            case VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM:
                return std::string("VK_FORMAT_FEATURE_2_BLOCK_MATCHING_BIT_QCOM");
            case VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM:
                return std::string("VK_FORMAT_FEATURE_2_BOX_FILTER_SAMPLED_BIT_QCOM");
            case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV:
                return std::string("VK_FORMAT_FEATURE_2_OPTICAL_FLOW_IMAGE_BIT_NV");
            case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV:
                return std::string("VK_FORMAT_FEATURE_2_OPTICAL_FLOW_VECTOR_BIT_NV");
            case VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV:
                return std::string("VK_FORMAT_FEATURE_2_OPTICAL_FLOW_COST_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkFrameBoundaryFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT:
                return std::string("VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkFramebufferCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT:
                return std::string("VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkGeometryFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_GEOMETRY_OPAQUE_BIT_KHR:
                return std::string("VK_GEOMETRY_OPAQUE_BIT_KHR");
            case VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR:
                return std::string("VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkGeometryInstanceFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR:
                return std::string("VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR");
            case VK_GEOMETRY_INSTANCE_TRIANGLE_FLIP_FACING_BIT_KHR:
                return std::string("VK_GEOMETRY_INSTANCE_TRIANGLE_FLIP_FACING_BIT_KHR");
            case VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR:
                return std::string("VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR");
            case VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR:
                return std::string("VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR");
            case VK_GEOMETRY_INSTANCE_FORCE_OPACITY_MICROMAP_2_STATE_EXT:
                return std::string("VK_GEOMETRY_INSTANCE_FORCE_OPACITY_MICROMAP_2_STATE_EXT");
            case VK_GEOMETRY_INSTANCE_DISABLE_OPACITY_MICROMAPS_EXT:
                return std::string("VK_GEOMETRY_INSTANCE_DISABLE_OPACITY_MICROMAPS_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkGraphicsPipelineLibraryFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_GRAPHICS_PIPELINE_LIBRARY_VERTEX_INPUT_INTERFACE_BIT_EXT:
                return std::string("VK_GRAPHICS_PIPELINE_LIBRARY_VERTEX_INPUT_INTERFACE_BIT_EXT");
            case VK_GRAPHICS_PIPELINE_LIBRARY_PRE_RASTERIZATION_SHADERS_BIT_EXT:
                return std::string("VK_GRAPHICS_PIPELINE_LIBRARY_PRE_RASTERIZATION_SHADERS_BIT_EXT");
            case VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_SHADER_BIT_EXT:
                return std::string("VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_SHADER_BIT_EXT");
            case VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_OUTPUT_INTERFACE_BIT_EXT:
                return std::string("VK_GRAPHICS_PIPELINE_LIBRARY_FRAGMENT_OUTPUT_INTERFACE_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkHeadlessSurfaceCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkHostImageCopyFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_HOST_IMAGE_COPY_MEMCPY_EXT:
                return std::string("VK_HOST_IMAGE_COPY_MEMCPY_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkIOSSurfaceCreateFlagsMVK_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkImageAspectFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_IMAGE_ASPECT_COLOR_BIT:
                return std::string("VK_IMAGE_ASPECT_COLOR_BIT");
            case VK_IMAGE_ASPECT_DEPTH_BIT:
                return std::string("VK_IMAGE_ASPECT_DEPTH_BIT");
            case VK_IMAGE_ASPECT_STENCIL_BIT:
                return std::string("VK_IMAGE_ASPECT_STENCIL_BIT");
            case VK_IMAGE_ASPECT_METADATA_BIT:
                return std::string("VK_IMAGE_ASPECT_METADATA_BIT");
            case VK_IMAGE_ASPECT_PLANE_0_BIT:
                return std::string("VK_IMAGE_ASPECT_PLANE_0_BIT");
            case VK_IMAGE_ASPECT_PLANE_1_BIT:
                return std::string("VK_IMAGE_ASPECT_PLANE_1_BIT");
            case VK_IMAGE_ASPECT_PLANE_2_BIT:
                return std::string("VK_IMAGE_ASPECT_PLANE_2_BIT");
            case VK_IMAGE_ASPECT_NONE:
                return std::string("VK_IMAGE_ASPECT_NONE");
            case VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT:
                return std::string("VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT");
            case VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT:
                return std::string("VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT");
            case VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT:
                return std::string("VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT");
            case VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT:
                return std::string("VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkImageCompressionFixedRateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_IMAGE_COMPRESSION_FIXED_RATE_NONE_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_NONE_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_1BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_1BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_2BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_2BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_3BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_3BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_4BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_4BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_5BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_5BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_6BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_6BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_7BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_7BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_8BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_8BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_9BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_9BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_10BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_10BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_11BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_11BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_12BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_12BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_13BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_13BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_14BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_14BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_15BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_15BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_16BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_16BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_17BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_17BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_18BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_18BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_19BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_19BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_20BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_20BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_21BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_21BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_22BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_22BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_23BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_23BPC_BIT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_24BPC_BIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_24BPC_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkImageCompressionFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_IMAGE_COMPRESSION_DEFAULT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_DEFAULT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_DEFAULT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_DEFAULT_EXT");
            case VK_IMAGE_COMPRESSION_FIXED_RATE_EXPLICIT_EXT:
                return std::string("VK_IMAGE_COMPRESSION_FIXED_RATE_EXPLICIT_EXT");
            case VK_IMAGE_COMPRESSION_DISABLED_EXT:
                return std::string("VK_IMAGE_COMPRESSION_DISABLED_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkImageCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_IMAGE_CREATE_SPARSE_BINDING_BIT:
                return std::string("VK_IMAGE_CREATE_SPARSE_BINDING_BIT");
            case VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT:
                return std::string("VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT");
            case VK_IMAGE_CREATE_SPARSE_ALIASED_BIT:
                return std::string("VK_IMAGE_CREATE_SPARSE_ALIASED_BIT");
            case VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT:
                return std::string("VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT");
            case VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT:
                return std::string("VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT");
            case VK_IMAGE_CREATE_ALIAS_BIT:
                return std::string("VK_IMAGE_CREATE_ALIAS_BIT");
            case VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT:
                return std::string("VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT");
            case VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT:
                return std::string("VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT");
            case VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT:
                return std::string("VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT");
            case VK_IMAGE_CREATE_EXTENDED_USAGE_BIT:
                return std::string("VK_IMAGE_CREATE_EXTENDED_USAGE_BIT");
            case VK_IMAGE_CREATE_PROTECTED_BIT:
                return std::string("VK_IMAGE_CREATE_PROTECTED_BIT");
            case VK_IMAGE_CREATE_DISJOINT_BIT:
                return std::string("VK_IMAGE_CREATE_DISJOINT_BIT");
            case VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV:
                return std::string("VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV");
            case VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT");
            case VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT");
            case VK_IMAGE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT");
            case VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_BIT_EXT");
            case VK_IMAGE_CREATE_2D_VIEW_COMPATIBLE_BIT_EXT:
                return std::string("VK_IMAGE_CREATE_2D_VIEW_COMPATIBLE_BIT_EXT");
            case VK_IMAGE_CREATE_FRAGMENT_DENSITY_MAP_OFFSET_BIT_QCOM:
                return std::string("VK_IMAGE_CREATE_FRAGMENT_DENSITY_MAP_OFFSET_BIT_QCOM");
            case VK_IMAGE_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR:
                return std::string("VK_IMAGE_CREATE_VIDEO_PROFILE_INDEPENDENT_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkImagePipeSurfaceCreateFlagsFUCHSIA_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkImageUsageFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_IMAGE_USAGE_TRANSFER_SRC_BIT:
                return std::string("VK_IMAGE_USAGE_TRANSFER_SRC_BIT");
            case VK_IMAGE_USAGE_TRANSFER_DST_BIT:
                return std::string("VK_IMAGE_USAGE_TRANSFER_DST_BIT");
            case VK_IMAGE_USAGE_SAMPLED_BIT:
                return std::string("VK_IMAGE_USAGE_SAMPLED_BIT");
            case VK_IMAGE_USAGE_STORAGE_BIT:
                return std::string("VK_IMAGE_USAGE_STORAGE_BIT");
            case VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT:
                return std::string("VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT");
            case VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT:
                return std::string("VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT");
            case VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT:
                return std::string("VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT");
            case VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT:
                return std::string("VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT");
            case VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_VIDEO_DECODE_DST_BIT_KHR");
            case VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_VIDEO_DECODE_SRC_BIT_KHR");
            case VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_VIDEO_DECODE_DPB_BIT_KHR");
            case VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT:
                return std::string("VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT");
            case VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT:
                return std::string("VK_IMAGE_USAGE_HOST_TRANSFER_BIT_EXT");
            case VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_VIDEO_ENCODE_DST_BIT_KHR");
            case VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_VIDEO_ENCODE_SRC_BIT_KHR");
            case VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR:
                return std::string("VK_IMAGE_USAGE_VIDEO_ENCODE_DPB_BIT_KHR");
            case VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
                return std::string("VK_IMAGE_USAGE_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT");
            case VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI:
                return std::string("VK_IMAGE_USAGE_INVOCATION_MASK_BIT_HUAWEI");
            case VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM:
                return std::string("VK_IMAGE_USAGE_SAMPLE_WEIGHT_BIT_QCOM");
            case VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM:
                return std::string("VK_IMAGE_USAGE_SAMPLE_BLOCK_MATCH_BIT_QCOM");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkImageViewCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT:
                return std::string("VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT");
            case VK_IMAGE_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
                return std::string("VK_IMAGE_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT");
            case VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DEFERRED_BIT_EXT:
                return std::string("VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DEFERRED_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkIndirectCommandsLayoutUsageFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV:
                return std::string("VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV");
            case VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV:
                return std::string("VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV");
            case VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV:
                return std::string("VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkIndirectStateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV:
                return std::string("VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkInstanceCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR:
                return std::string("VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkMacOSSurfaceCreateFlagsMVK_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkMemoryAllocateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT:
                return std::string("VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT");
            case VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT:
                return std::string("VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT");
            case VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT:
                return std::string("VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkMemoryHeapFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_MEMORY_HEAP_DEVICE_LOCAL_BIT:
                return std::string("VK_MEMORY_HEAP_DEVICE_LOCAL_BIT");
            case VK_MEMORY_HEAP_MULTI_INSTANCE_BIT:
                return std::string("VK_MEMORY_HEAP_MULTI_INSTANCE_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkMemoryMapFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_MEMORY_MAP_PLACED_BIT_EXT:
                return std::string("VK_MEMORY_MAP_PLACED_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkMemoryPropertyFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT:
                return std::string("VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT");
            case VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT:
                return std::string("VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT");
            case VK_MEMORY_PROPERTY_HOST_COHERENT_BIT:
                return std::string("VK_MEMORY_PROPERTY_HOST_COHERENT_BIT");
            case VK_MEMORY_PROPERTY_HOST_CACHED_BIT:
                return std::string("VK_MEMORY_PROPERTY_HOST_CACHED_BIT");
            case VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT:
                return std::string("VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT");
            case VK_MEMORY_PROPERTY_PROTECTED_BIT:
                return std::string("VK_MEMORY_PROPERTY_PROTECTED_BIT");
            case VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD:
                return std::string("VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD");
            case VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD:
                return std::string("VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD");
            case VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV:
                return std::string("VK_MEMORY_PROPERTY_RDMA_CAPABLE_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkMemoryUnmapFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_MEMORY_UNMAP_RESERVE_BIT_EXT:
                return std::string("VK_MEMORY_UNMAP_RESERVE_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkMetalSurfaceCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkMicromapCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_MICROMAP_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT:
                return std::string("VK_MICROMAP_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkOpticalFlowExecuteFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_OPTICAL_FLOW_EXECUTE_DISABLE_TEMPORAL_HINTS_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_EXECUTE_DISABLE_TEMPORAL_HINTS_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkOpticalFlowGridSizeFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_OPTICAL_FLOW_GRID_SIZE_UNKNOWN_NV:
                return std::string("VK_OPTICAL_FLOW_GRID_SIZE_UNKNOWN_NV");
            case VK_OPTICAL_FLOW_GRID_SIZE_1X1_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_GRID_SIZE_1X1_BIT_NV");
            case VK_OPTICAL_FLOW_GRID_SIZE_2X2_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_GRID_SIZE_2X2_BIT_NV");
            case VK_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_GRID_SIZE_4X4_BIT_NV");
            case VK_OPTICAL_FLOW_GRID_SIZE_8X8_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_GRID_SIZE_8X8_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkOpticalFlowSessionCreateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_HINT_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_HINT_BIT_NV");
            case VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_COST_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_COST_BIT_NV");
            case VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_GLOBAL_FLOW_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_SESSION_CREATE_ENABLE_GLOBAL_FLOW_BIT_NV");
            case VK_OPTICAL_FLOW_SESSION_CREATE_ALLOW_REGIONS_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_SESSION_CREATE_ALLOW_REGIONS_BIT_NV");
            case VK_OPTICAL_FLOW_SESSION_CREATE_BOTH_DIRECTIONS_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_SESSION_CREATE_BOTH_DIRECTIONS_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkOpticalFlowUsageFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_OPTICAL_FLOW_USAGE_UNKNOWN_NV:
                return std::string("VK_OPTICAL_FLOW_USAGE_UNKNOWN_NV");
            case VK_OPTICAL_FLOW_USAGE_INPUT_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_USAGE_INPUT_BIT_NV");
            case VK_OPTICAL_FLOW_USAGE_OUTPUT_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_USAGE_OUTPUT_BIT_NV");
            case VK_OPTICAL_FLOW_USAGE_HINT_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_USAGE_HINT_BIT_NV");
            case VK_OPTICAL_FLOW_USAGE_COST_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_USAGE_COST_BIT_NV");
            case VK_OPTICAL_FLOW_USAGE_GLOBAL_FLOW_BIT_NV:
                return std::string("VK_OPTICAL_FLOW_USAGE_GLOBAL_FLOW_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPeerMemoryFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT:
                return std::string("VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT");
            case VK_PEER_MEMORY_FEATURE_COPY_DST_BIT:
                return std::string("VK_PEER_MEMORY_FEATURE_COPY_DST_BIT");
            case VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT:
                return std::string("VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT");
            case VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT:
                return std::string("VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPerformanceCounterDescriptionFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR:
                return std::string("VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR");
            case VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR:
                return std::string("VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPhysicalDeviceSchedulingControlsFlagsARM_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM:
                return std::string("VK_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_SHADER_CORE_COUNT_ARM");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineCacheCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT:
                return std::string("VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineColorBlendStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_COLOR_BLEND_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_BIT_EXT:
                return std::string("VK_PIPELINE_COLOR_BLEND_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineCompilerControlFlagsAMD_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineCoverageModulationStateCreateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineCoverageReductionStateCreateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineCoverageToColorStateCreateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT:
                return std::string("VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT");
            case VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT:
                return std::string("VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT");
            case VK_PIPELINE_CREATE_DERIVATIVE_BIT:
                return std::string("VK_PIPELINE_CREATE_DERIVATIVE_BIT");
            case VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT:
                return std::string("VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT");
            case VK_PIPELINE_CREATE_DISPATCH_BASE_BIT:
                return std::string("VK_PIPELINE_CREATE_DISPATCH_BASE_BIT");
            case VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT:
                return std::string("VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT");
            case VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT:
                return std::string("VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT");
            case VK_PIPELINE_CREATE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_PIPELINE_CREATE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT");
            case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR");
            case VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR");
            case VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR");
            case VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV");
            case VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR");
            case VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR");
            case VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV");
            case VK_PIPELINE_CREATE_LIBRARY_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_LIBRARY_BIT_KHR");
            case VK_PIPELINE_CREATE_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_DESCRIPTOR_BUFFER_BIT_EXT");
            case VK_PIPELINE_CREATE_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT");
            case VK_PIPELINE_CREATE_LINK_TIME_OPTIMIZATION_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_LINK_TIME_OPTIMIZATION_BIT_EXT");
            case VK_PIPELINE_CREATE_RAY_TRACING_ALLOW_MOTION_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_RAY_TRACING_ALLOW_MOTION_BIT_NV");
            case VK_PIPELINE_CREATE_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT");
            case VK_PIPELINE_CREATE_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT");
            case VK_PIPELINE_CREATE_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT");
            case VK_PIPELINE_CREATE_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV");
            case VK_PIPELINE_CREATE_NO_PROTECTED_ACCESS_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_NO_PROTECTED_ACCESS_BIT_EXT");
            case VK_PIPELINE_CREATE_PROTECTED_ACCESS_ONLY_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_PROTECTED_ACCESS_ONLY_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineCreateFlags2KHR_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_DISABLE_OPTIMIZATION_BIT_KHR");
            case VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_ALLOW_DERIVATIVES_BIT_KHR");
            case VK_PIPELINE_CREATE_2_DERIVATIVE_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_DERIVATIVE_BIT_KHR");
            case VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR");
            case VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_DISPATCH_BASE_BIT_KHR");
            case VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_2_DEFER_COMPILE_BIT_NV");
            case VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_CAPTURE_STATISTICS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_KHR");
            case VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_EARLY_RETURN_ON_FAILURE_BIT_KHR");
            case VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_LINK_TIME_OPTIMIZATION_BIT_EXT");
            case VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_RETAIN_LINK_TIME_OPTIMIZATION_INFO_BIT_EXT");
            case VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_LIBRARY_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_SKIP_AABBS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR");
            case VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_2_INDIRECT_BINDABLE_BIT_NV");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_ALLOW_MOTION_BIT_NV");
            case VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_OPACITY_MICROMAP_BIT_EXT");
            case VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_COLOR_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT");
            case VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_DEPTH_STENCIL_ATTACHMENT_FEEDBACK_LOOP_BIT_EXT");
            case VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_NO_PROTECTED_ACCESS_BIT_EXT");
            case VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_PROTECTED_ACCESS_ONLY_BIT_EXT");
            case VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV:
                return std::string("VK_PIPELINE_CREATE_2_RAY_TRACING_DISPLACEMENT_MICROMAP_BIT_NV");
            case VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT:
                return std::string("VK_PIPELINE_CREATE_2_DESCRIPTOR_BUFFER_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineCreationFeedbackFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT:
                return std::string("VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT");
            case VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT:
                return std::string("VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT");
            case VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT:
                return std::string("VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineDepthStencilStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT:
                return std::string("VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT");
            case VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT:
                return std::string("VK_PIPELINE_DEPTH_STENCIL_STATE_CREATE_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineDiscardRectangleStateCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineDynamicStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineInputAssemblyStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineLayoutCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_LAYOUT_CREATE_INDEPENDENT_SETS_BIT_EXT:
                return std::string("VK_PIPELINE_LAYOUT_CREATE_INDEPENDENT_SETS_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineMultisampleStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineRasterizationConservativeStateCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineRasterizationDepthClipStateCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineRasterizationStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineRasterizationStateStreamCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineShaderStageCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT:
                return std::string("VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT");
            case VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT:
                return std::string("VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineStageFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT:
                return std::string("VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT");
            case VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT:
                return std::string("VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT");
            case VK_PIPELINE_STAGE_VERTEX_INPUT_BIT:
                return std::string("VK_PIPELINE_STAGE_VERTEX_INPUT_BIT");
            case VK_PIPELINE_STAGE_VERTEX_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_VERTEX_SHADER_BIT");
            case VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT");
            case VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT");
            case VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT");
            case VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT");
            case VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT:
                return std::string("VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT");
            case VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT:
                return std::string("VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT");
            case VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT:
                return std::string("VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT");
            case VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT");
            case VK_PIPELINE_STAGE_TRANSFER_BIT:
                return std::string("VK_PIPELINE_STAGE_TRANSFER_BIT");
            case VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT:
                return std::string("VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT");
            case VK_PIPELINE_STAGE_HOST_BIT:
                return std::string("VK_PIPELINE_STAGE_HOST_BIT");
            case VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT:
                return std::string("VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT");
            case VK_PIPELINE_STAGE_ALL_COMMANDS_BIT:
                return std::string("VK_PIPELINE_STAGE_ALL_COMMANDS_BIT");
            case VK_PIPELINE_STAGE_NONE:
                return std::string("VK_PIPELINE_STAGE_NONE");
            case VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT");
            case VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT");
            case VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR");
            case VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR");
            case VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT");
            case VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV:
                return std::string("VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV");
            case VK_PIPELINE_STAGE_TASK_SHADER_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_TASK_SHADER_BIT_EXT");
            case VK_PIPELINE_STAGE_MESH_SHADER_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_MESH_SHADER_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineStageFlags2_t, nlohmann::ordered_json& jdata, const VkFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags64 flags)
    {
        switch (flags)
        {
            case VK_PIPELINE_STAGE_2_NONE:
                return std::string("VK_PIPELINE_STAGE_2_NONE");
            case VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT:
                return std::string("VK_PIPELINE_STAGE_2_TOP_OF_PIPE_BIT");
            case VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_DRAW_INDIRECT_BIT");
            case VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_VERTEX_INPUT_BIT");
            case VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_VERTEX_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_TESSELLATION_CONTROL_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_TESSELLATION_EVALUATION_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_GEOMETRY_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_FRAGMENT_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT:
                return std::string("VK_PIPELINE_STAGE_2_EARLY_FRAGMENT_TESTS_BIT");
            case VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT:
                return std::string("VK_PIPELINE_STAGE_2_LATE_FRAGMENT_TESTS_BIT");
            case VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_COLOR_ATTACHMENT_OUTPUT_BIT");
            case VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_COMPUTE_SHADER_BIT");
            case VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT:
                return std::string("VK_PIPELINE_STAGE_2_ALL_TRANSFER_BIT");
            case VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT:
                return std::string("VK_PIPELINE_STAGE_2_BOTTOM_OF_PIPE_BIT");
            case VK_PIPELINE_STAGE_2_HOST_BIT:
                return std::string("VK_PIPELINE_STAGE_2_HOST_BIT");
            case VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT:
                return std::string("VK_PIPELINE_STAGE_2_ALL_GRAPHICS_BIT");
            case VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT:
                return std::string("VK_PIPELINE_STAGE_2_ALL_COMMANDS_BIT");
            case VK_PIPELINE_STAGE_2_COPY_BIT:
                return std::string("VK_PIPELINE_STAGE_2_COPY_BIT");
            case VK_PIPELINE_STAGE_2_RESOLVE_BIT:
                return std::string("VK_PIPELINE_STAGE_2_RESOLVE_BIT");
            case VK_PIPELINE_STAGE_2_BLIT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_BLIT_BIT");
            case VK_PIPELINE_STAGE_2_CLEAR_BIT:
                return std::string("VK_PIPELINE_STAGE_2_CLEAR_BIT");
            case VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_INDEX_INPUT_BIT");
            case VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT:
                return std::string("VK_PIPELINE_STAGE_2_VERTEX_ATTRIBUTE_INPUT_BIT");
            case VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT:
                return std::string("VK_PIPELINE_STAGE_2_PRE_RASTERIZATION_SHADERS_BIT");
            case VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_VIDEO_DECODE_BIT_KHR");
            case VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_VIDEO_ENCODE_BIT_KHR");
            case VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_TRANSFORM_FEEDBACK_BIT_EXT");
            case VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_CONDITIONAL_RENDERING_BIT_EXT");
            case VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV:
                return std::string("VK_PIPELINE_STAGE_2_COMMAND_PREPROCESS_BIT_NV");
            case VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR");
            case VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_BUILD_BIT_KHR");
            case VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_RAY_TRACING_SHADER_BIT_KHR");
            case VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_FRAGMENT_DENSITY_PROCESS_BIT_EXT");
            case VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_TASK_SHADER_BIT_EXT");
            case VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_MESH_SHADER_BIT_EXT");
            case VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI:
                return std::string("VK_PIPELINE_STAGE_2_SUBPASS_SHADER_BIT_HUAWEI");
            case VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI:
                return std::string("VK_PIPELINE_STAGE_2_INVOCATION_MASK_BIT_HUAWEI");
            case VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR:
                return std::string("VK_PIPELINE_STAGE_2_ACCELERATION_STRUCTURE_COPY_BIT_KHR");
            case VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT:
                return std::string("VK_PIPELINE_STAGE_2_MICROMAP_BUILD_BIT_EXT");
            case VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI:
                return std::string("VK_PIPELINE_STAGE_2_CLUSTER_CULLING_SHADER_BIT_HUAWEI");
            case VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV:
                return std::string("VK_PIPELINE_STAGE_2_OPTICAL_FLOW_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPipelineTessellationStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineVertexInputStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineViewportStateCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPipelineViewportSwizzleStateCreateFlagsNV_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkPresentGravityFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PRESENT_GRAVITY_MIN_BIT_EXT:
                return std::string("VK_PRESENT_GRAVITY_MIN_BIT_EXT");
            case VK_PRESENT_GRAVITY_MAX_BIT_EXT:
                return std::string("VK_PRESENT_GRAVITY_MAX_BIT_EXT");
            case VK_PRESENT_GRAVITY_CENTERED_BIT_EXT:
                return std::string("VK_PRESENT_GRAVITY_CENTERED_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPresentScalingFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_PRESENT_SCALING_ONE_TO_ONE_BIT_EXT:
                return std::string("VK_PRESENT_SCALING_ONE_TO_ONE_BIT_EXT");
            case VK_PRESENT_SCALING_ASPECT_RATIO_STRETCH_BIT_EXT:
                return std::string("VK_PRESENT_SCALING_ASPECT_RATIO_STRETCH_BIT_EXT");
            case VK_PRESENT_SCALING_STRETCH_BIT_EXT:
                return std::string("VK_PRESENT_SCALING_STRETCH_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkPrivateDataSlotCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkQueryControlFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_QUERY_CONTROL_PRECISE_BIT:
                return std::string("VK_QUERY_CONTROL_PRECISE_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkQueryPipelineStatisticFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT");
            case VK_QUERY_PIPELINE_STATISTIC_TASK_SHADER_INVOCATIONS_BIT_EXT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_TASK_SHADER_INVOCATIONS_BIT_EXT");
            case VK_QUERY_PIPELINE_STATISTIC_MESH_SHADER_INVOCATIONS_BIT_EXT:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_MESH_SHADER_INVOCATIONS_BIT_EXT");
            case VK_QUERY_PIPELINE_STATISTIC_CLUSTER_CULLING_SHADER_INVOCATIONS_BIT_HUAWEI:
                return std::string("VK_QUERY_PIPELINE_STATISTIC_CLUSTER_CULLING_SHADER_INVOCATIONS_BIT_HUAWEI");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkQueryPoolCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkQueryResultFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_QUERY_RESULT_64_BIT:
                return std::string("VK_QUERY_RESULT_64_BIT");
            case VK_QUERY_RESULT_WAIT_BIT:
                return std::string("VK_QUERY_RESULT_WAIT_BIT");
            case VK_QUERY_RESULT_WITH_AVAILABILITY_BIT:
                return std::string("VK_QUERY_RESULT_WITH_AVAILABILITY_BIT");
            case VK_QUERY_RESULT_PARTIAL_BIT:
                return std::string("VK_QUERY_RESULT_PARTIAL_BIT");
            case VK_QUERY_RESULT_WITH_STATUS_BIT_KHR:
                return std::string("VK_QUERY_RESULT_WITH_STATUS_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkQueueFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_QUEUE_GRAPHICS_BIT:
                return std::string("VK_QUEUE_GRAPHICS_BIT");
            case VK_QUEUE_COMPUTE_BIT:
                return std::string("VK_QUEUE_COMPUTE_BIT");
            case VK_QUEUE_TRANSFER_BIT:
                return std::string("VK_QUEUE_TRANSFER_BIT");
            case VK_QUEUE_SPARSE_BINDING_BIT:
                return std::string("VK_QUEUE_SPARSE_BINDING_BIT");
            case VK_QUEUE_PROTECTED_BIT:
                return std::string("VK_QUEUE_PROTECTED_BIT");
            case VK_QUEUE_VIDEO_DECODE_BIT_KHR:
                return std::string("VK_QUEUE_VIDEO_DECODE_BIT_KHR");
            case VK_QUEUE_VIDEO_ENCODE_BIT_KHR:
                return std::string("VK_QUEUE_VIDEO_ENCODE_BIT_KHR");
            case VK_QUEUE_OPTICAL_FLOW_BIT_NV:
                return std::string("VK_QUEUE_OPTICAL_FLOW_BIT_NV");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkRenderPassCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_RENDER_PASS_CREATE_TRANSFORM_BIT_QCOM:
                return std::string("VK_RENDER_PASS_CREATE_TRANSFORM_BIT_QCOM");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkRenderingFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_RENDERING_CONTENTS_SECONDARY_COMMAND_BUFFERS_BIT:
                return std::string("VK_RENDERING_CONTENTS_SECONDARY_COMMAND_BUFFERS_BIT");
            case VK_RENDERING_SUSPENDING_BIT:
                return std::string("VK_RENDERING_SUSPENDING_BIT");
            case VK_RENDERING_RESUMING_BIT:
                return std::string("VK_RENDERING_RESUMING_BIT");
            case VK_RENDERING_CONTENTS_INLINE_BIT_EXT:
                return std::string("VK_RENDERING_CONTENTS_INLINE_BIT_EXT");
            case VK_RENDERING_ENABLE_LEGACY_DITHERING_BIT_EXT:
                return std::string("VK_RENDERING_ENABLE_LEGACY_DITHERING_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkResolveModeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_RESOLVE_MODE_NONE:
                return std::string("VK_RESOLVE_MODE_NONE");
            case VK_RESOLVE_MODE_SAMPLE_ZERO_BIT:
                return std::string("VK_RESOLVE_MODE_SAMPLE_ZERO_BIT");
            case VK_RESOLVE_MODE_AVERAGE_BIT:
                return std::string("VK_RESOLVE_MODE_AVERAGE_BIT");
            case VK_RESOLVE_MODE_MIN_BIT:
                return std::string("VK_RESOLVE_MODE_MIN_BIT");
            case VK_RESOLVE_MODE_MAX_BIT:
                return std::string("VK_RESOLVE_MODE_MAX_BIT");
            case VK_RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_ANDROID:
                return std::string("VK_RESOLVE_MODE_EXTERNAL_FORMAT_DOWNSAMPLE_ANDROID");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkSampleCountFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SAMPLE_COUNT_1_BIT:
                return std::string("VK_SAMPLE_COUNT_1_BIT");
            case VK_SAMPLE_COUNT_2_BIT:
                return std::string("VK_SAMPLE_COUNT_2_BIT");
            case VK_SAMPLE_COUNT_4_BIT:
                return std::string("VK_SAMPLE_COUNT_4_BIT");
            case VK_SAMPLE_COUNT_8_BIT:
                return std::string("VK_SAMPLE_COUNT_8_BIT");
            case VK_SAMPLE_COUNT_16_BIT:
                return std::string("VK_SAMPLE_COUNT_16_BIT");
            case VK_SAMPLE_COUNT_32_BIT:
                return std::string("VK_SAMPLE_COUNT_32_BIT");
            case VK_SAMPLE_COUNT_64_BIT:
                return std::string("VK_SAMPLE_COUNT_64_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkSamplerCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT:
                return std::string("VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT");
            case VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT:
                return std::string("VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT");
            case VK_SAMPLER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT:
                return std::string("VK_SAMPLER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT");
            case VK_SAMPLER_CREATE_NON_SEAMLESS_CUBE_MAP_BIT_EXT:
                return std::string("VK_SAMPLER_CREATE_NON_SEAMLESS_CUBE_MAP_BIT_EXT");
            case VK_SAMPLER_CREATE_IMAGE_PROCESSING_BIT_QCOM:
                return std::string("VK_SAMPLER_CREATE_IMAGE_PROCESSING_BIT_QCOM");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkScreenSurfaceCreateFlagsQNX_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkSemaphoreCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkSemaphoreImportFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SEMAPHORE_IMPORT_TEMPORARY_BIT:
                return std::string("VK_SEMAPHORE_IMPORT_TEMPORARY_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkSemaphoreWaitFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SEMAPHORE_WAIT_ANY_BIT:
                return std::string("VK_SEMAPHORE_WAIT_ANY_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkShaderCorePropertiesFlagsAMD_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkShaderCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SHADER_CREATE_LINK_STAGE_BIT_EXT:
                return std::string("VK_SHADER_CREATE_LINK_STAGE_BIT_EXT");
            case VK_SHADER_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT:
                return std::string("VK_SHADER_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT");
            case VK_SHADER_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT:
                return std::string("VK_SHADER_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT");
            case VK_SHADER_CREATE_NO_TASK_SHADER_BIT_EXT:
                return std::string("VK_SHADER_CREATE_NO_TASK_SHADER_BIT_EXT");
            case VK_SHADER_CREATE_DISPATCH_BASE_BIT_EXT:
                return std::string("VK_SHADER_CREATE_DISPATCH_BASE_BIT_EXT");
            case VK_SHADER_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_EXT:
                return std::string("VK_SHADER_CREATE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_EXT");
            case VK_SHADER_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT:
                return std::string("VK_SHADER_CREATE_FRAGMENT_DENSITY_MAP_ATTACHMENT_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkShaderModuleCreateFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkShaderStageFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SHADER_STAGE_VERTEX_BIT:
                return std::string("VK_SHADER_STAGE_VERTEX_BIT");
            case VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT:
                return std::string("VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT");
            case VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT:
                return std::string("VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT");
            case VK_SHADER_STAGE_GEOMETRY_BIT:
                return std::string("VK_SHADER_STAGE_GEOMETRY_BIT");
            case VK_SHADER_STAGE_FRAGMENT_BIT:
                return std::string("VK_SHADER_STAGE_FRAGMENT_BIT");
            case VK_SHADER_STAGE_COMPUTE_BIT:
                return std::string("VK_SHADER_STAGE_COMPUTE_BIT");
            case VK_SHADER_STAGE_ALL_GRAPHICS:
                return std::string("VK_SHADER_STAGE_ALL_GRAPHICS");
            case VK_SHADER_STAGE_ALL:
                return std::string("VK_SHADER_STAGE_ALL");
            case VK_SHADER_STAGE_RAYGEN_BIT_KHR:
                return std::string("VK_SHADER_STAGE_RAYGEN_BIT_KHR");
            case VK_SHADER_STAGE_ANY_HIT_BIT_KHR:
                return std::string("VK_SHADER_STAGE_ANY_HIT_BIT_KHR");
            case VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR:
                return std::string("VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR");
            case VK_SHADER_STAGE_MISS_BIT_KHR:
                return std::string("VK_SHADER_STAGE_MISS_BIT_KHR");
            case VK_SHADER_STAGE_INTERSECTION_BIT_KHR:
                return std::string("VK_SHADER_STAGE_INTERSECTION_BIT_KHR");
            case VK_SHADER_STAGE_CALLABLE_BIT_KHR:
                return std::string("VK_SHADER_STAGE_CALLABLE_BIT_KHR");
            case VK_SHADER_STAGE_TASK_BIT_EXT:
                return std::string("VK_SHADER_STAGE_TASK_BIT_EXT");
            case VK_SHADER_STAGE_MESH_BIT_EXT:
                return std::string("VK_SHADER_STAGE_MESH_BIT_EXT");
            case VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI:
                return std::string("VK_SHADER_STAGE_SUBPASS_SHADING_BIT_HUAWEI");
            case VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI:
                return std::string("VK_SHADER_STAGE_CLUSTER_CULLING_BIT_HUAWEI");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkSparseImageFormatFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT:
                return std::string("VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT");
            case VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT:
                return std::string("VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT");
            case VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT:
                return std::string("VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkSparseMemoryBindFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SPARSE_MEMORY_BIND_METADATA_BIT:
                return std::string("VK_SPARSE_MEMORY_BIND_METADATA_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkStencilFaceFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_STENCIL_FACE_FRONT_BIT:
                return std::string("VK_STENCIL_FACE_FRONT_BIT");
            case VK_STENCIL_FACE_BACK_BIT:
                return std::string("VK_STENCIL_FACE_BACK_BIT");
            case VK_STENCIL_FACE_FRONT_AND_BACK:
                return std::string("VK_STENCIL_FACE_FRONT_AND_BACK");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkStreamDescriptorSurfaceCreateFlagsGGP_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkSubgroupFeatureFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SUBGROUP_FEATURE_BASIC_BIT:
                return std::string("VK_SUBGROUP_FEATURE_BASIC_BIT");
            case VK_SUBGROUP_FEATURE_VOTE_BIT:
                return std::string("VK_SUBGROUP_FEATURE_VOTE_BIT");
            case VK_SUBGROUP_FEATURE_ARITHMETIC_BIT:
                return std::string("VK_SUBGROUP_FEATURE_ARITHMETIC_BIT");
            case VK_SUBGROUP_FEATURE_BALLOT_BIT:
                return std::string("VK_SUBGROUP_FEATURE_BALLOT_BIT");
            case VK_SUBGROUP_FEATURE_SHUFFLE_BIT:
                return std::string("VK_SUBGROUP_FEATURE_SHUFFLE_BIT");
            case VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT:
                return std::string("VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT");
            case VK_SUBGROUP_FEATURE_CLUSTERED_BIT:
                return std::string("VK_SUBGROUP_FEATURE_CLUSTERED_BIT");
            case VK_SUBGROUP_FEATURE_QUAD_BIT:
                return std::string("VK_SUBGROUP_FEATURE_QUAD_BIT");
            case VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV:
                return std::string("VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV");
            case VK_SUBGROUP_FEATURE_ROTATE_BIT_KHR:
                return std::string("VK_SUBGROUP_FEATURE_ROTATE_BIT_KHR");
            case VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT_KHR:
                return std::string("VK_SUBGROUP_FEATURE_ROTATE_CLUSTERED_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkSubmitFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SUBMIT_PROTECTED_BIT:
                return std::string("VK_SUBMIT_PROTECTED_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkSubpassDescriptionFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX:
                return std::string("VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX");
            case VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX:
                return std::string("VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX");
            case VK_SUBPASS_DESCRIPTION_FRAGMENT_REGION_BIT_QCOM:
                return std::string("VK_SUBPASS_DESCRIPTION_FRAGMENT_REGION_BIT_QCOM");
            case VK_SUBPASS_DESCRIPTION_SHADER_RESOLVE_BIT_QCOM:
                return std::string("VK_SUBPASS_DESCRIPTION_SHADER_RESOLVE_BIT_QCOM");
            case VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_BIT_EXT:
                return std::string("VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_COLOR_ACCESS_BIT_EXT");
            case VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT:
                return std::string("VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_DEPTH_ACCESS_BIT_EXT");
            case VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT:
                return std::string("VK_SUBPASS_DESCRIPTION_RASTERIZATION_ORDER_ATTACHMENT_STENCIL_ACCESS_BIT_EXT");
            case VK_SUBPASS_DESCRIPTION_ENABLE_LEGACY_DITHERING_BIT_EXT:
                return std::string("VK_SUBPASS_DESCRIPTION_ENABLE_LEGACY_DITHERING_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkSurfaceCounterFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SURFACE_COUNTER_VBLANK_BIT_EXT:
                return std::string("VK_SURFACE_COUNTER_VBLANK_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkSurfaceTransformFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR:
                return std::string("VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR");
            case VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR:
                return std::string("VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR");
            case VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR:
                return std::string("VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR");
            case VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR:
                return std::string("VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR");
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR:
                return std::string("VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR");
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR:
                return std::string("VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR");
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR:
                return std::string("VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR");
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR:
                return std::string("VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR");
            case VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR:
                return std::string("VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkSwapchainCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR:
                return std::string("VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR");
            case VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR:
                return std::string("VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR");
            case VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR:
                return std::string("VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR");
            case VK_SWAPCHAIN_CREATE_DEFERRED_MEMORY_ALLOCATION_BIT_EXT:
                return std::string("VK_SWAPCHAIN_CREATE_DEFERRED_MEMORY_ALLOCATION_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkToolPurposeFlags_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_TOOL_PURPOSE_VALIDATION_BIT:
                return std::string("VK_TOOL_PURPOSE_VALIDATION_BIT");
            case VK_TOOL_PURPOSE_PROFILING_BIT:
                return std::string("VK_TOOL_PURPOSE_PROFILING_BIT");
            case VK_TOOL_PURPOSE_TRACING_BIT:
                return std::string("VK_TOOL_PURPOSE_TRACING_BIT");
            case VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT:
                return std::string("VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT");
            case VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT:
                return std::string("VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT");
            case VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT:
                return std::string("VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT");
            case VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT:
                return std::string("VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkValidationCacheCreateFlagsEXT_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkViSurfaceCreateFlagsNN_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkVideoBeginCodingFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkVideoCapabilityFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_CAPABILITY_PROTECTED_CONTENT_BIT_KHR:
                return std::string("VK_VIDEO_CAPABILITY_PROTECTED_CONTENT_BIT_KHR");
            case VK_VIDEO_CAPABILITY_SEPARATE_REFERENCE_IMAGES_BIT_KHR:
                return std::string("VK_VIDEO_CAPABILITY_SEPARATE_REFERENCE_IMAGES_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoChromaSubsamplingFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_CHROMA_SUBSAMPLING_INVALID_KHR:
                return std::string("VK_VIDEO_CHROMA_SUBSAMPLING_INVALID_KHR");
            case VK_VIDEO_CHROMA_SUBSAMPLING_MONOCHROME_BIT_KHR:
                return std::string("VK_VIDEO_CHROMA_SUBSAMPLING_MONOCHROME_BIT_KHR");
            case VK_VIDEO_CHROMA_SUBSAMPLING_420_BIT_KHR:
                return std::string("VK_VIDEO_CHROMA_SUBSAMPLING_420_BIT_KHR");
            case VK_VIDEO_CHROMA_SUBSAMPLING_422_BIT_KHR:
                return std::string("VK_VIDEO_CHROMA_SUBSAMPLING_422_BIT_KHR");
            case VK_VIDEO_CHROMA_SUBSAMPLING_444_BIT_KHR:
                return std::string("VK_VIDEO_CHROMA_SUBSAMPLING_444_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoCodecOperationFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_CODEC_OPERATION_NONE_KHR:
                return std::string("VK_VIDEO_CODEC_OPERATION_NONE_KHR");
            case VK_VIDEO_CODEC_OPERATION_ENCODE_H264_BIT_KHR:
                return std::string("VK_VIDEO_CODEC_OPERATION_ENCODE_H264_BIT_KHR");
            case VK_VIDEO_CODEC_OPERATION_ENCODE_H265_BIT_KHR:
                return std::string("VK_VIDEO_CODEC_OPERATION_ENCODE_H265_BIT_KHR");
            case VK_VIDEO_CODEC_OPERATION_DECODE_H264_BIT_KHR:
                return std::string("VK_VIDEO_CODEC_OPERATION_DECODE_H264_BIT_KHR");
            case VK_VIDEO_CODEC_OPERATION_DECODE_H265_BIT_KHR:
                return std::string("VK_VIDEO_CODEC_OPERATION_DECODE_H265_BIT_KHR");
            case VK_VIDEO_CODEC_OPERATION_DECODE_AV1_BIT_KHR:
                return std::string("VK_VIDEO_CODEC_OPERATION_DECODE_AV1_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoCodingControlFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_CODING_CONTROL_RESET_BIT_KHR:
                return std::string("VK_VIDEO_CODING_CONTROL_RESET_BIT_KHR");
            case VK_VIDEO_CODING_CONTROL_ENCODE_RATE_CONTROL_BIT_KHR:
                return std::string("VK_VIDEO_CODING_CONTROL_ENCODE_RATE_CONTROL_BIT_KHR");
            case VK_VIDEO_CODING_CONTROL_ENCODE_QUALITY_LEVEL_BIT_KHR:
                return std::string("VK_VIDEO_CODING_CONTROL_ENCODE_QUALITY_LEVEL_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoComponentBitDepthFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_COMPONENT_BIT_DEPTH_INVALID_KHR:
                return std::string("VK_VIDEO_COMPONENT_BIT_DEPTH_INVALID_KHR");
            case VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR:
                return std::string("VK_VIDEO_COMPONENT_BIT_DEPTH_8_BIT_KHR");
            case VK_VIDEO_COMPONENT_BIT_DEPTH_10_BIT_KHR:
                return std::string("VK_VIDEO_COMPONENT_BIT_DEPTH_10_BIT_KHR");
            case VK_VIDEO_COMPONENT_BIT_DEPTH_12_BIT_KHR:
                return std::string("VK_VIDEO_COMPONENT_BIT_DEPTH_12_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoDecodeCapabilityFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR:
                return std::string("VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_COINCIDE_BIT_KHR");
            case VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR:
                return std::string("VK_VIDEO_DECODE_CAPABILITY_DPB_AND_OUTPUT_DISTINCT_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoDecodeFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkVideoDecodeH264PictureLayoutFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR:
                return std::string("VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_PROGRESSIVE_KHR");
            case VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_INTERLEAVED_LINES_BIT_KHR:
                return std::string("VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_INTERLEAVED_LINES_BIT_KHR");
            case VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_SEPARATE_PLANES_BIT_KHR:
                return std::string("VK_VIDEO_DECODE_H264_PICTURE_LAYOUT_INTERLACED_SEPARATE_PLANES_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoDecodeUsageFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_DECODE_USAGE_DEFAULT_KHR:
                return std::string("VK_VIDEO_DECODE_USAGE_DEFAULT_KHR");
            case VK_VIDEO_DECODE_USAGE_TRANSCODING_BIT_KHR:
                return std::string("VK_VIDEO_DECODE_USAGE_TRANSCODING_BIT_KHR");
            case VK_VIDEO_DECODE_USAGE_OFFLINE_BIT_KHR:
                return std::string("VK_VIDEO_DECODE_USAGE_OFFLINE_BIT_KHR");
            case VK_VIDEO_DECODE_USAGE_STREAMING_BIT_KHR:
                return std::string("VK_VIDEO_DECODE_USAGE_STREAMING_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeCapabilityFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_CAPABILITY_PRECEDING_EXTERNALLY_ENCODED_BYTES_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_CAPABILITY_PRECEDING_EXTERNALLY_ENCODED_BYTES_BIT_KHR");
            case VK_VIDEO_ENCODE_CAPABILITY_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_DETECTION_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_CAPABILITY_INSUFFICIENT_BITSTREAM_BUFFER_RANGE_DETECTION_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeContentFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_CONTENT_DEFAULT_KHR:
                return std::string("VK_VIDEO_ENCODE_CONTENT_DEFAULT_KHR");
            case VK_VIDEO_ENCODE_CONTENT_CAMERA_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_CONTENT_CAMERA_BIT_KHR");
            case VK_VIDEO_ENCODE_CONTENT_DESKTOP_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_CONTENT_DESKTOP_BIT_KHR");
            case VK_VIDEO_ENCODE_CONTENT_RENDERED_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_CONTENT_RENDERED_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeFeedbackFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BUFFER_OFFSET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BUFFER_OFFSET_BIT_KHR");
            case VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BYTES_WRITTEN_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_BYTES_WRITTEN_BIT_KHR");
            case VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_HAS_OVERRIDES_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_FEEDBACK_BITSTREAM_HAS_OVERRIDES_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkVideoEncodeH264CapabilityFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_H264_CAPABILITY_HRD_COMPLIANCE_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_CAPABILITY_HRD_COMPLIANCE_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_CAPABILITY_ROW_UNALIGNED_SLICE_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_CAPABILITY_ROW_UNALIGNED_SLICE_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_CAPABILITY_DIFFERENT_SLICE_TYPE_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_CAPABILITY_DIFFERENT_SLICE_TYPE_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_CAPABILITY_PER_SLICE_CONSTANT_QP_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_CAPABILITY_PER_SLICE_CONSTANT_QP_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_CAPABILITY_GENERATE_PREFIX_NALU_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_CAPABILITY_GENERATE_PREFIX_NALU_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeH264RateControlFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_H264_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_RATE_CONTROL_REGULAR_GOP_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_RATE_CONTROL_REGULAR_GOP_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_RATE_CONTROL_TEMPORAL_LAYER_PATTERN_DYADIC_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_RATE_CONTROL_TEMPORAL_LAYER_PATTERN_DYADIC_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeH264StdFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_H264_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_QPPRIME_Y_ZERO_TRANSFORM_BYPASS_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_QPPRIME_Y_ZERO_TRANSFORM_BYPASS_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_SCALING_MATRIX_PRESENT_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_SCALING_MATRIX_PRESENT_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_CHROMA_QP_INDEX_OFFSET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_CHROMA_QP_INDEX_OFFSET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_SECOND_CHROMA_QP_INDEX_OFFSET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_SECOND_CHROMA_QP_INDEX_OFFSET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_PIC_INIT_QP_MINUS26_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_PIC_INIT_QP_MINUS26_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_EXPLICIT_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_EXPLICIT_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_IMPLICIT_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_WEIGHTED_BIPRED_IDC_IMPLICIT_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_TRANSFORM_8X8_MODE_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_TRANSFORM_8X8_MODE_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_DIRECT_SPATIAL_MV_PRED_FLAG_UNSET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_DIRECT_SPATIAL_MV_PRED_FLAG_UNSET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_UNSET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_UNSET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_ENTROPY_CODING_MODE_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_DIRECT_8X8_INFERENCE_FLAG_UNSET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_DIRECT_8X8_INFERENCE_FLAG_UNSET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_DISABLED_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_DISABLED_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_ENABLED_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_ENABLED_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_PARTIAL_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_DEBLOCKING_FILTER_PARTIAL_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_SLICE_QP_DELTA_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_SLICE_QP_DELTA_BIT_KHR");
            case VK_VIDEO_ENCODE_H264_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H264_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeH265CapabilityFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_H265_CAPABILITY_HRD_COMPLIANCE_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CAPABILITY_HRD_COMPLIANCE_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CAPABILITY_PREDICTION_WEIGHT_TABLE_GENERATED_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CAPABILITY_ROW_UNALIGNED_SLICE_SEGMENT_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CAPABILITY_ROW_UNALIGNED_SLICE_SEGMENT_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CAPABILITY_DIFFERENT_SLICE_SEGMENT_TYPE_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CAPABILITY_DIFFERENT_SLICE_SEGMENT_TYPE_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L0_LIST_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CAPABILITY_B_FRAME_IN_L1_LIST_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CAPABILITY_PER_PICTURE_TYPE_MIN_MAX_QP_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CAPABILITY_PER_SLICE_SEGMENT_CONSTANT_QP_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CAPABILITY_PER_SLICE_SEGMENT_CONSTANT_QP_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_TILES_PER_SLICE_SEGMENT_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_TILES_PER_SLICE_SEGMENT_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_SLICE_SEGMENTS_PER_TILE_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CAPABILITY_MULTIPLE_SLICE_SEGMENTS_PER_TILE_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeH265CtbSizeFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_H265_CTB_SIZE_16_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CTB_SIZE_16_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CTB_SIZE_32_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CTB_SIZE_32_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_CTB_SIZE_64_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_CTB_SIZE_64_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeH265RateControlFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_H265_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_RATE_CONTROL_ATTEMPT_HRD_COMPLIANCE_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_RATE_CONTROL_REGULAR_GOP_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_RATE_CONTROL_REGULAR_GOP_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_FLAT_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_RATE_CONTROL_REFERENCE_PATTERN_DYADIC_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_RATE_CONTROL_TEMPORAL_SUB_LAYER_PATTERN_DYADIC_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_RATE_CONTROL_TEMPORAL_SUB_LAYER_PATTERN_DYADIC_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeH265StdFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_H265_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_SEPARATE_COLOR_PLANE_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_SAMPLE_ADAPTIVE_OFFSET_ENABLED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_SAMPLE_ADAPTIVE_OFFSET_ENABLED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_SCALING_LIST_DATA_PRESENT_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_SCALING_LIST_DATA_PRESENT_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_PCM_ENABLED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_PCM_ENABLED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_SPS_TEMPORAL_MVP_ENABLED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_SPS_TEMPORAL_MVP_ENABLED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_INIT_QP_MINUS26_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_INIT_QP_MINUS26_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_WEIGHTED_PRED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_WEIGHTED_BIPRED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_WEIGHTED_BIPRED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_LOG2_PARALLEL_MERGE_LEVEL_MINUS2_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_LOG2_PARALLEL_MERGE_LEVEL_MINUS2_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_SIGN_DATA_HIDING_ENABLED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_SIGN_DATA_HIDING_ENABLED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_UNSET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_TRANSFORM_SKIP_ENABLED_FLAG_UNSET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_PPS_SLICE_CHROMA_QP_OFFSETS_PRESENT_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_PPS_SLICE_CHROMA_QP_OFFSETS_PRESENT_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_TRANSQUANT_BYPASS_ENABLED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_TRANSQUANT_BYPASS_ENABLED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_CONSTRAINED_INTRA_PRED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_ENTROPY_CODING_SYNC_ENABLED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_ENTROPY_CODING_SYNC_ENABLED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_DEBLOCKING_FILTER_OVERRIDE_ENABLED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENTS_ENABLED_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENTS_ENABLED_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENT_FLAG_SET_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_DEPENDENT_SLICE_SEGMENT_FLAG_SET_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_SLICE_QP_DELTA_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_SLICE_QP_DELTA_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_STD_DIFFERENT_SLICE_QP_DELTA_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeH265TransformBlockSizeFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_4_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_4_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_8_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_8_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_16_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_16_BIT_KHR");
            case VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_32_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_H265_TRANSFORM_BLOCK_SIZE_32_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeRateControlFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkVideoEncodeRateControlModeFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DEFAULT_KHR:
                return std::string("VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DEFAULT_KHR");
            case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DISABLED_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_RATE_CONTROL_MODE_DISABLED_BIT_KHR");
            case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_CBR_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_RATE_CONTROL_MODE_CBR_BIT_KHR");
            case VK_VIDEO_ENCODE_RATE_CONTROL_MODE_VBR_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_RATE_CONTROL_MODE_VBR_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEncodeUsageFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_ENCODE_USAGE_DEFAULT_KHR:
                return std::string("VK_VIDEO_ENCODE_USAGE_DEFAULT_KHR");
            case VK_VIDEO_ENCODE_USAGE_TRANSCODING_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_USAGE_TRANSCODING_BIT_KHR");
            case VK_VIDEO_ENCODE_USAGE_STREAMING_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_USAGE_STREAMING_BIT_KHR");
            case VK_VIDEO_ENCODE_USAGE_RECORDING_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_USAGE_RECORDING_BIT_KHR");
            case VK_VIDEO_ENCODE_USAGE_CONFERENCING_BIT_KHR:
                return std::string("VK_VIDEO_ENCODE_USAGE_CONFERENCING_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoEndCodingFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkVideoSessionCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](VkFlags flags)
    {
        switch (flags)
        {
            case VK_VIDEO_SESSION_CREATE_PROTECTED_CONTENT_BIT_KHR:
                return std::string("VK_VIDEO_SESSION_CREATE_PROTECTED_CONTENT_BIT_KHR");
            case VK_VIDEO_SESSION_CREATE_ALLOW_ENCODE_PARAMETER_OPTIMIZATIONS_BIT_KHR:
                return std::string("VK_VIDEO_SESSION_CREATE_ALLOW_ENCODE_PARAMETER_OPTIMIZATIONS_BIT_KHR");
            case VK_VIDEO_SESSION_CREATE_INLINE_QUERIES_BIT_KHR:
                return std::string("VK_VIDEO_SESSION_CREATE_INLINE_QUERIES_BIT_KHR");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(VkVideoSessionParametersCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkWaylandSurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkWin32SurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkXcbSurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(VkXlibSurfaceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const VkFlags flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
