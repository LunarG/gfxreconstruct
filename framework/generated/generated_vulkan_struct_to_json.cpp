/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2022 LunarG, Inc.
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

#include "generated_vulkan_struct_to_json.h"
#include "generated_vulkan_enum_to_json.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264SpsVuiFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["aspect_ratio_info_present_flag"], decoded_value.aspect_ratio_info_present_flag, options);
        FieldToJson(jdata["overscan_info_present_flag"], decoded_value.overscan_info_present_flag, options);
        FieldToJson(jdata["overscan_appropriate_flag"], decoded_value.overscan_appropriate_flag, options);
        FieldToJson(jdata["video_signal_type_present_flag"], decoded_value.video_signal_type_present_flag, options);
        FieldToJson(jdata["video_full_range_flag"], decoded_value.video_full_range_flag, options);
        FieldToJson(jdata["color_description_present_flag"], decoded_value.color_description_present_flag, options);
        FieldToJson(jdata["chroma_loc_info_present_flag"], decoded_value.chroma_loc_info_present_flag, options);
        FieldToJson(jdata["timing_info_present_flag"], decoded_value.timing_info_present_flag, options);
        FieldToJson(jdata["fixed_frame_rate_flag"], decoded_value.fixed_frame_rate_flag, options);
        FieldToJson(jdata["bitstream_restriction_flag"], decoded_value.bitstream_restriction_flag, options);
        FieldToJson(jdata["nal_hrd_parameters_present_flag"], decoded_value.nal_hrd_parameters_present_flag, options);
        FieldToJson(jdata["vcl_hrd_parameters_present_flag"], decoded_value.vcl_hrd_parameters_present_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264HrdParameters* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["cpb_cnt_minus1"], decoded_value.cpb_cnt_minus1, options);
        FieldToJson(jdata["bit_rate_scale"], decoded_value.bit_rate_scale, options);
        FieldToJson(jdata["cpb_size_scale"], decoded_value.cpb_size_scale, options);
        FieldToJson(jdata["reserved1"], decoded_value.reserved1, options);
        FieldToJson(jdata["bit_rate_value_minus1"], &meta_struct.bit_rate_value_minus1, options);
        FieldToJson(jdata["cpb_size_value_minus1"], &meta_struct.cpb_size_value_minus1, options);
        FieldToJson(jdata["cbr_flag"], &meta_struct.cbr_flag, options);
        FieldToJson(jdata["initial_cpb_removal_delay_length_minus1"], decoded_value.initial_cpb_removal_delay_length_minus1, options);
        FieldToJson(jdata["cpb_removal_delay_length_minus1"], decoded_value.cpb_removal_delay_length_minus1, options);
        FieldToJson(jdata["dpb_output_delay_length_minus1"], decoded_value.dpb_output_delay_length_minus1, options);
        FieldToJson(jdata["time_offset_length"], decoded_value.time_offset_length, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264SequenceParameterSetVui* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["aspect_ratio_idc"], decoded_value.aspect_ratio_idc, options);
        FieldToJson(jdata["sar_width"], decoded_value.sar_width, options);
        FieldToJson(jdata["sar_height"], decoded_value.sar_height, options);
        FieldToJson(jdata["video_format"], decoded_value.video_format, options);
        FieldToJson(jdata["colour_primaries"], decoded_value.colour_primaries, options);
        FieldToJson(jdata["transfer_characteristics"], decoded_value.transfer_characteristics, options);
        FieldToJson(jdata["matrix_coefficients"], decoded_value.matrix_coefficients, options);
        FieldToJson(jdata["num_units_in_tick"], decoded_value.num_units_in_tick, options);
        FieldToJson(jdata["time_scale"], decoded_value.time_scale, options);
        FieldToJson(jdata["max_num_reorder_frames"], decoded_value.max_num_reorder_frames, options);
        FieldToJson(jdata["max_dec_frame_buffering"], decoded_value.max_dec_frame_buffering, options);
        FieldToJson(jdata["chroma_sample_loc_type_top_field"], decoded_value.chroma_sample_loc_type_top_field, options);
        FieldToJson(jdata["chroma_sample_loc_type_bottom_field"], decoded_value.chroma_sample_loc_type_bottom_field, options);
        FieldToJson(jdata["reserved1"], decoded_value.reserved1, options);
        FieldToJson(jdata["pHrdParameters"], meta_struct.pHrdParameters, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264SpsFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["constraint_set0_flag"], decoded_value.constraint_set0_flag, options);
        FieldToJson(jdata["constraint_set1_flag"], decoded_value.constraint_set1_flag, options);
        FieldToJson(jdata["constraint_set2_flag"], decoded_value.constraint_set2_flag, options);
        FieldToJson(jdata["constraint_set3_flag"], decoded_value.constraint_set3_flag, options);
        FieldToJson(jdata["constraint_set4_flag"], decoded_value.constraint_set4_flag, options);
        FieldToJson(jdata["constraint_set5_flag"], decoded_value.constraint_set5_flag, options);
        FieldToJson(jdata["direct_8x8_inference_flag"], decoded_value.direct_8x8_inference_flag, options);
        FieldToJson(jdata["mb_adaptive_frame_field_flag"], decoded_value.mb_adaptive_frame_field_flag, options);
        FieldToJson(jdata["frame_mbs_only_flag"], decoded_value.frame_mbs_only_flag, options);
        FieldToJson(jdata["delta_pic_order_always_zero_flag"], decoded_value.delta_pic_order_always_zero_flag, options);
        FieldToJson(jdata["separate_colour_plane_flag"], decoded_value.separate_colour_plane_flag, options);
        FieldToJson(jdata["gaps_in_frame_num_value_allowed_flag"], decoded_value.gaps_in_frame_num_value_allowed_flag, options);
        FieldToJson(jdata["qpprime_y_zero_transform_bypass_flag"], decoded_value.qpprime_y_zero_transform_bypass_flag, options);
        FieldToJson(jdata["frame_cropping_flag"], decoded_value.frame_cropping_flag, options);
        FieldToJson(jdata["seq_scaling_matrix_present_flag"], decoded_value.seq_scaling_matrix_present_flag, options);
        FieldToJson(jdata["vui_parameters_present_flag"], decoded_value.vui_parameters_present_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264ScalingLists* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["scaling_list_present_mask"], decoded_value.scaling_list_present_mask, options);
        FieldToJson(jdata["use_default_scaling_matrix_mask"], decoded_value.use_default_scaling_matrix_mask, options);
        FieldToJson(jdata["ScalingList4x4"], &meta_struct.ScalingList4x4, options);
        FieldToJson(jdata["ScalingList8x8"], &meta_struct.ScalingList8x8, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264SequenceParameterSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["profile_idc"], decoded_value.profile_idc, options);
        FieldToJson(jdata["level_idc"], decoded_value.level_idc, options);
        FieldToJson(jdata["chroma_format_idc"], decoded_value.chroma_format_idc, options);
        FieldToJson(jdata["seq_parameter_set_id"], decoded_value.seq_parameter_set_id, options);
        FieldToJson(jdata["bit_depth_luma_minus8"], decoded_value.bit_depth_luma_minus8, options);
        FieldToJson(jdata["bit_depth_chroma_minus8"], decoded_value.bit_depth_chroma_minus8, options);
        FieldToJson(jdata["log2_max_frame_num_minus4"], decoded_value.log2_max_frame_num_minus4, options);
        FieldToJson(jdata["pic_order_cnt_type"], decoded_value.pic_order_cnt_type, options);
        FieldToJson(jdata["offset_for_non_ref_pic"], decoded_value.offset_for_non_ref_pic, options);
        FieldToJson(jdata["offset_for_top_to_bottom_field"], decoded_value.offset_for_top_to_bottom_field, options);
        FieldToJson(jdata["log2_max_pic_order_cnt_lsb_minus4"], decoded_value.log2_max_pic_order_cnt_lsb_minus4, options);
        FieldToJson(jdata["num_ref_frames_in_pic_order_cnt_cycle"], decoded_value.num_ref_frames_in_pic_order_cnt_cycle, options);
        FieldToJson(jdata["max_num_ref_frames"], decoded_value.max_num_ref_frames, options);
        FieldToJson(jdata["reserved1"], decoded_value.reserved1, options);
        FieldToJson(jdata["pic_width_in_mbs_minus1"], decoded_value.pic_width_in_mbs_minus1, options);
        FieldToJson(jdata["pic_height_in_map_units_minus1"], decoded_value.pic_height_in_map_units_minus1, options);
        FieldToJson(jdata["frame_crop_left_offset"], decoded_value.frame_crop_left_offset, options);
        FieldToJson(jdata["frame_crop_right_offset"], decoded_value.frame_crop_right_offset, options);
        FieldToJson(jdata["frame_crop_top_offset"], decoded_value.frame_crop_top_offset, options);
        FieldToJson(jdata["frame_crop_bottom_offset"], decoded_value.frame_crop_bottom_offset, options);
        FieldToJson(jdata["reserved2"], decoded_value.reserved2, options);
        FieldToJson(jdata["pOffsetForRefFrame"], meta_struct.pOffsetForRefFrame, options);
        FieldToJson(jdata["pScalingLists"], meta_struct.pScalingLists, options);
        FieldToJson(jdata["pSequenceParameterSetVui"], meta_struct.pSequenceParameterSetVui, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264PpsFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["transform_8x8_mode_flag"], decoded_value.transform_8x8_mode_flag, options);
        FieldToJson(jdata["redundant_pic_cnt_present_flag"], decoded_value.redundant_pic_cnt_present_flag, options);
        FieldToJson(jdata["constrained_intra_pred_flag"], decoded_value.constrained_intra_pred_flag, options);
        FieldToJson(jdata["deblocking_filter_control_present_flag"], decoded_value.deblocking_filter_control_present_flag, options);
        FieldToJson(jdata["weighted_pred_flag"], decoded_value.weighted_pred_flag, options);
        FieldToJson(jdata["bottom_field_pic_order_in_frame_present_flag"], decoded_value.bottom_field_pic_order_in_frame_present_flag, options);
        FieldToJson(jdata["entropy_coding_mode_flag"], decoded_value.entropy_coding_mode_flag, options);
        FieldToJson(jdata["pic_scaling_matrix_present_flag"], decoded_value.pic_scaling_matrix_present_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264PictureParameterSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["seq_parameter_set_id"], decoded_value.seq_parameter_set_id, options);
        FieldToJson(jdata["pic_parameter_set_id"], decoded_value.pic_parameter_set_id, options);
        FieldToJson(jdata["num_ref_idx_l0_default_active_minus1"], decoded_value.num_ref_idx_l0_default_active_minus1, options);
        FieldToJson(jdata["num_ref_idx_l1_default_active_minus1"], decoded_value.num_ref_idx_l1_default_active_minus1, options);
        FieldToJson(jdata["weighted_bipred_idc"], decoded_value.weighted_bipred_idc, options);
        FieldToJson(jdata["pic_init_qp_minus26"], decoded_value.pic_init_qp_minus26, options);
        FieldToJson(jdata["pic_init_qs_minus26"], decoded_value.pic_init_qs_minus26, options);
        FieldToJson(jdata["chroma_qp_index_offset"], decoded_value.chroma_qp_index_offset, options);
        FieldToJson(jdata["second_chroma_qp_index_offset"], decoded_value.second_chroma_qp_index_offset, options);
        FieldToJson(jdata["pScalingLists"], meta_struct.pScalingLists, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH264PictureInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["field_pic_flag"], decoded_value.field_pic_flag, options);
        FieldToJson(jdata["is_intra"], decoded_value.is_intra, options);
        FieldToJson(jdata["IdrPicFlag"], decoded_value.IdrPicFlag, options);
        FieldToJson(jdata["bottom_field_flag"], decoded_value.bottom_field_flag, options);
        FieldToJson(jdata["is_reference"], decoded_value.is_reference, options);
        FieldToJson(jdata["complementary_field_pair"], decoded_value.complementary_field_pair, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH264PictureInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["seq_parameter_set_id"], decoded_value.seq_parameter_set_id, options);
        FieldToJson(jdata["pic_parameter_set_id"], decoded_value.pic_parameter_set_id, options);
        FieldToJson(jdata["reserved1"], decoded_value.reserved1, options);
        FieldToJson(jdata["reserved2"], decoded_value.reserved2, options);
        FieldToJson(jdata["frame_num"], decoded_value.frame_num, options);
        FieldToJson(jdata["idr_pic_id"], decoded_value.idr_pic_id, options);
        FieldToJson(jdata["PicOrderCnt"], &meta_struct.PicOrderCnt, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH264ReferenceInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["top_field_flag"], decoded_value.top_field_flag, options);
        FieldToJson(jdata["bottom_field_flag"], decoded_value.bottom_field_flag, options);
        FieldToJson(jdata["used_for_long_term_reference"], decoded_value.used_for_long_term_reference, options);
        FieldToJson(jdata["is_non_existing"], decoded_value.is_non_existing, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH264ReferenceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["FrameNum"], decoded_value.FrameNum, options);
        FieldToJson(jdata["reserved"], decoded_value.reserved, options);
        FieldToJson(jdata["PicOrderCnt"], &meta_struct.PicOrderCnt, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264WeightTableFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["luma_weight_l0_flag"], decoded_value.luma_weight_l0_flag, options);
        FieldToJson(jdata["chroma_weight_l0_flag"], decoded_value.chroma_weight_l0_flag, options);
        FieldToJson(jdata["luma_weight_l1_flag"], decoded_value.luma_weight_l1_flag, options);
        FieldToJson(jdata["chroma_weight_l1_flag"], decoded_value.chroma_weight_l1_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264WeightTable* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["luma_log2_weight_denom"], decoded_value.luma_log2_weight_denom, options);
        FieldToJson(jdata["chroma_log2_weight_denom"], decoded_value.chroma_log2_weight_denom, options);
        FieldToJson(jdata["luma_weight_l0"], &meta_struct.luma_weight_l0, options);
        FieldToJson(jdata["luma_offset_l0"], &meta_struct.luma_offset_l0, options);
        FieldToJson(jdata["chroma_weight_l0"], &meta_struct.chroma_weight_l0, options);
        FieldToJson(jdata["chroma_offset_l0"], &meta_struct.chroma_offset_l0, options);
        FieldToJson(jdata["luma_weight_l1"], &meta_struct.luma_weight_l1, options);
        FieldToJson(jdata["luma_offset_l1"], &meta_struct.luma_offset_l1, options);
        FieldToJson(jdata["chroma_weight_l1"], &meta_struct.chroma_weight_l1, options);
        FieldToJson(jdata["chroma_offset_l1"], &meta_struct.chroma_offset_l1, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264SliceHeaderFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["direct_spatial_mv_pred_flag"], decoded_value.direct_spatial_mv_pred_flag, options);
        FieldToJson(jdata["num_ref_idx_active_override_flag"], decoded_value.num_ref_idx_active_override_flag, options);
        FieldToJson(jdata["no_output_of_prior_pics_flag"], decoded_value.no_output_of_prior_pics_flag, options);
        FieldToJson(jdata["adaptive_ref_pic_marking_mode_flag"], decoded_value.adaptive_ref_pic_marking_mode_flag, options);
        FieldToJson(jdata["no_prior_references_available_flag"], decoded_value.no_prior_references_available_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264PictureInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["idr_flag"], decoded_value.idr_flag, options);
        FieldToJson(jdata["is_reference_flag"], decoded_value.is_reference_flag, options);
        FieldToJson(jdata["used_for_long_term_reference"], decoded_value.used_for_long_term_reference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264ReferenceInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["used_for_long_term_reference"], decoded_value.used_for_long_term_reference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264RefMgmtFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["ref_pic_list_modification_l0_flag"], decoded_value.ref_pic_list_modification_l0_flag, options);
        FieldToJson(jdata["ref_pic_list_modification_l1_flag"], decoded_value.ref_pic_list_modification_l1_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264RefListModEntry* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["modification_of_pic_nums_idc"], decoded_value.modification_of_pic_nums_idc, options);
        FieldToJson(jdata["abs_diff_pic_num_minus1"], decoded_value.abs_diff_pic_num_minus1, options);
        FieldToJson(jdata["long_term_pic_num"], decoded_value.long_term_pic_num, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264RefPicMarkingEntry* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["operation"], decoded_value.operation, options);
        FieldToJson(jdata["difference_of_pic_nums_minus1"], decoded_value.difference_of_pic_nums_minus1, options);
        FieldToJson(jdata["long_term_pic_num"], decoded_value.long_term_pic_num, options);
        FieldToJson(jdata["long_term_frame_idx"], decoded_value.long_term_frame_idx, options);
        FieldToJson(jdata["max_long_term_frame_idx_plus1"], decoded_value.max_long_term_frame_idx_plus1, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264RefMemMgmtCtrlOperations* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["refList0ModOpCount"], decoded_value.refList0ModOpCount, options);
        FieldToJson(jdata["pRefList0ModOperations"], meta_struct.pRefList0ModOperations, options);
        FieldToJson(jdata["refList1ModOpCount"], decoded_value.refList1ModOpCount, options);
        FieldToJson(jdata["pRefList1ModOperations"], meta_struct.pRefList1ModOperations, options);
        FieldToJson(jdata["refPicMarkingOpCount"], decoded_value.refPicMarkingOpCount, options);
        FieldToJson(jdata["pRefPicMarkingOperations"], meta_struct.pRefPicMarkingOperations, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264PictureInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["seq_parameter_set_id"], decoded_value.seq_parameter_set_id, options);
        FieldToJson(jdata["pic_parameter_set_id"], decoded_value.pic_parameter_set_id, options);
        FieldToJson(jdata["pictureType"], decoded_value.pictureType, options);
        FieldToJson(jdata["frame_num"], decoded_value.frame_num, options);
        FieldToJson(jdata["PicOrderCnt"], decoded_value.PicOrderCnt, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264ReferenceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["FrameNum"], decoded_value.FrameNum, options);
        FieldToJson(jdata["PicOrderCnt"], decoded_value.PicOrderCnt, options);
        FieldToJson(jdata["long_term_pic_num"], decoded_value.long_term_pic_num, options);
        FieldToJson(jdata["long_term_frame_idx"], decoded_value.long_term_frame_idx, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264SliceHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["first_mb_in_slice"], decoded_value.first_mb_in_slice, options);
        FieldToJson(jdata["slice_type"], decoded_value.slice_type, options);
        FieldToJson(jdata["idr_pic_id"], decoded_value.idr_pic_id, options);
        FieldToJson(jdata["num_ref_idx_l0_active_minus1"], decoded_value.num_ref_idx_l0_active_minus1, options);
        FieldToJson(jdata["num_ref_idx_l1_active_minus1"], decoded_value.num_ref_idx_l1_active_minus1, options);
        FieldToJson(jdata["cabac_init_idc"], decoded_value.cabac_init_idc, options);
        FieldToJson(jdata["disable_deblocking_filter_idc"], decoded_value.disable_deblocking_filter_idc, options);
        FieldToJson(jdata["slice_alpha_c0_offset_div2"], decoded_value.slice_alpha_c0_offset_div2, options);
        FieldToJson(jdata["slice_beta_offset_div2"], decoded_value.slice_beta_offset_div2, options);
        FieldToJson(jdata["pWeightTable"], meta_struct.pWeightTable, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265ProfileTierLevelFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["general_tier_flag"], decoded_value.general_tier_flag, options);
        FieldToJson(jdata["general_progressive_source_flag"], decoded_value.general_progressive_source_flag, options);
        FieldToJson(jdata["general_interlaced_source_flag"], decoded_value.general_interlaced_source_flag, options);
        FieldToJson(jdata["general_non_packed_constraint_flag"], decoded_value.general_non_packed_constraint_flag, options);
        FieldToJson(jdata["general_frame_only_constraint_flag"], decoded_value.general_frame_only_constraint_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265ProfileTierLevel* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["general_profile_idc"], decoded_value.general_profile_idc, options);
        FieldToJson(jdata["general_level_idc"], decoded_value.general_level_idc, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265DecPicBufMgr* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["max_latency_increase_plus1"], &meta_struct.max_latency_increase_plus1, options);
        FieldToJson(jdata["max_dec_pic_buffering_minus1"], &meta_struct.max_dec_pic_buffering_minus1, options);
        FieldToJson(jdata["max_num_reorder_pics"], &meta_struct.max_num_reorder_pics, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265SubLayerHrdParameters* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["bit_rate_value_minus1"], &meta_struct.bit_rate_value_minus1, options);
        FieldToJson(jdata["cpb_size_value_minus1"], &meta_struct.cpb_size_value_minus1, options);
        FieldToJson(jdata["cpb_size_du_value_minus1"], &meta_struct.cpb_size_du_value_minus1, options);
        FieldToJson(jdata["bit_rate_du_value_minus1"], &meta_struct.bit_rate_du_value_minus1, options);
        FieldToJson(jdata["cbr_flag"], decoded_value.cbr_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265HrdFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["nal_hrd_parameters_present_flag"], decoded_value.nal_hrd_parameters_present_flag, options);
        FieldToJson(jdata["vcl_hrd_parameters_present_flag"], decoded_value.vcl_hrd_parameters_present_flag, options);
        FieldToJson(jdata["sub_pic_hrd_params_present_flag"], decoded_value.sub_pic_hrd_params_present_flag, options);
        FieldToJson(jdata["sub_pic_cpb_params_in_pic_timing_sei_flag"], decoded_value.sub_pic_cpb_params_in_pic_timing_sei_flag, options);
        FieldToJson(jdata["fixed_pic_rate_general_flag"], decoded_value.fixed_pic_rate_general_flag, options);
        FieldToJson(jdata["fixed_pic_rate_within_cvs_flag"], decoded_value.fixed_pic_rate_within_cvs_flag, options);
        FieldToJson(jdata["low_delay_hrd_flag"], decoded_value.low_delay_hrd_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265HrdParameters* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["tick_divisor_minus2"], decoded_value.tick_divisor_minus2, options);
        FieldToJson(jdata["du_cpb_removal_delay_increment_length_minus1"], decoded_value.du_cpb_removal_delay_increment_length_minus1, options);
        FieldToJson(jdata["dpb_output_delay_du_length_minus1"], decoded_value.dpb_output_delay_du_length_minus1, options);
        FieldToJson(jdata["bit_rate_scale"], decoded_value.bit_rate_scale, options);
        FieldToJson(jdata["cpb_size_scale"], decoded_value.cpb_size_scale, options);
        FieldToJson(jdata["cpb_size_du_scale"], decoded_value.cpb_size_du_scale, options);
        FieldToJson(jdata["initial_cpb_removal_delay_length_minus1"], decoded_value.initial_cpb_removal_delay_length_minus1, options);
        FieldToJson(jdata["au_cpb_removal_delay_length_minus1"], decoded_value.au_cpb_removal_delay_length_minus1, options);
        FieldToJson(jdata["dpb_output_delay_length_minus1"], decoded_value.dpb_output_delay_length_minus1, options);
        FieldToJson(jdata["cpb_cnt_minus1"], &meta_struct.cpb_cnt_minus1, options);
        FieldToJson(jdata["elemental_duration_in_tc_minus1"], &meta_struct.elemental_duration_in_tc_minus1, options);
        FieldToJson(jdata["reserved"], &meta_struct.reserved, options);
        FieldToJson(jdata["pSubLayerHrdParametersNal"], meta_struct.pSubLayerHrdParametersNal, options);
        FieldToJson(jdata["pSubLayerHrdParametersVcl"], meta_struct.pSubLayerHrdParametersVcl, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265VpsFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["vps_temporal_id_nesting_flag"], decoded_value.vps_temporal_id_nesting_flag, options);
        FieldToJson(jdata["vps_sub_layer_ordering_info_present_flag"], decoded_value.vps_sub_layer_ordering_info_present_flag, options);
        FieldToJson(jdata["vps_timing_info_present_flag"], decoded_value.vps_timing_info_present_flag, options);
        FieldToJson(jdata["vps_poc_proportional_to_timing_flag"], decoded_value.vps_poc_proportional_to_timing_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265VideoParameterSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["vps_video_parameter_set_id"], decoded_value.vps_video_parameter_set_id, options);
        FieldToJson(jdata["vps_max_sub_layers_minus1"], decoded_value.vps_max_sub_layers_minus1, options);
        FieldToJson(jdata["reserved1"], decoded_value.reserved1, options);
        FieldToJson(jdata["reserved2"], decoded_value.reserved2, options);
        FieldToJson(jdata["vps_num_units_in_tick"], decoded_value.vps_num_units_in_tick, options);
        FieldToJson(jdata["vps_time_scale"], decoded_value.vps_time_scale, options);
        FieldToJson(jdata["vps_num_ticks_poc_diff_one_minus1"], decoded_value.vps_num_ticks_poc_diff_one_minus1, options);
        FieldToJson(jdata["reserved3"], decoded_value.reserved3, options);
        FieldToJson(jdata["pDecPicBufMgr"], meta_struct.pDecPicBufMgr, options);
        FieldToJson(jdata["pHrdParameters"], meta_struct.pHrdParameters, options);
        FieldToJson(jdata["pProfileTierLevel"], meta_struct.pProfileTierLevel, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265ScalingLists* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["ScalingList4x4"], &meta_struct.ScalingList4x4, options);
        FieldToJson(jdata["ScalingList8x8"], &meta_struct.ScalingList8x8, options);
        FieldToJson(jdata["ScalingList16x16"], &meta_struct.ScalingList16x16, options);
        FieldToJson(jdata["ScalingList32x32"], &meta_struct.ScalingList32x32, options);
        FieldToJson(jdata["ScalingListDCCoef16x16"], &meta_struct.ScalingListDCCoef16x16, options);
        FieldToJson(jdata["ScalingListDCCoef32x32"], &meta_struct.ScalingListDCCoef32x32, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265ShortTermRefPicSetFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["inter_ref_pic_set_prediction_flag"], decoded_value.inter_ref_pic_set_prediction_flag, options);
        FieldToJson(jdata["delta_rps_sign"], decoded_value.delta_rps_sign, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265ShortTermRefPicSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["delta_idx_minus1"], decoded_value.delta_idx_minus1, options);
        FieldToJson(jdata["use_delta_flag"], decoded_value.use_delta_flag, options);
        FieldToJson(jdata["abs_delta_rps_minus1"], decoded_value.abs_delta_rps_minus1, options);
        FieldToJson(jdata["used_by_curr_pic_flag"], decoded_value.used_by_curr_pic_flag, options);
        FieldToJson(jdata["used_by_curr_pic_s0_flag"], decoded_value.used_by_curr_pic_s0_flag, options);
        FieldToJson(jdata["used_by_curr_pic_s1_flag"], decoded_value.used_by_curr_pic_s1_flag, options);
        FieldToJson(jdata["reserved1"], decoded_value.reserved1, options);
        FieldToJson(jdata["reserved2"], decoded_value.reserved2, options);
        FieldToJson(jdata["reserved3"], decoded_value.reserved3, options);
        FieldToJson(jdata["num_negative_pics"], decoded_value.num_negative_pics, options);
        FieldToJson(jdata["num_positive_pics"], decoded_value.num_positive_pics, options);
        FieldToJson(jdata["delta_poc_s0_minus1"], &meta_struct.delta_poc_s0_minus1, options);
        FieldToJson(jdata["delta_poc_s1_minus1"], &meta_struct.delta_poc_s1_minus1, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265LongTermRefPicsSps* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["used_by_curr_pic_lt_sps_flag"], decoded_value.used_by_curr_pic_lt_sps_flag, options);
        FieldToJson(jdata["lt_ref_pic_poc_lsb_sps"], &meta_struct.lt_ref_pic_poc_lsb_sps, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265SpsVuiFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["aspect_ratio_info_present_flag"], decoded_value.aspect_ratio_info_present_flag, options);
        FieldToJson(jdata["overscan_info_present_flag"], decoded_value.overscan_info_present_flag, options);
        FieldToJson(jdata["overscan_appropriate_flag"], decoded_value.overscan_appropriate_flag, options);
        FieldToJson(jdata["video_signal_type_present_flag"], decoded_value.video_signal_type_present_flag, options);
        FieldToJson(jdata["video_full_range_flag"], decoded_value.video_full_range_flag, options);
        FieldToJson(jdata["colour_description_present_flag"], decoded_value.colour_description_present_flag, options);
        FieldToJson(jdata["chroma_loc_info_present_flag"], decoded_value.chroma_loc_info_present_flag, options);
        FieldToJson(jdata["neutral_chroma_indication_flag"], decoded_value.neutral_chroma_indication_flag, options);
        FieldToJson(jdata["field_seq_flag"], decoded_value.field_seq_flag, options);
        FieldToJson(jdata["frame_field_info_present_flag"], decoded_value.frame_field_info_present_flag, options);
        FieldToJson(jdata["default_display_window_flag"], decoded_value.default_display_window_flag, options);
        FieldToJson(jdata["vui_timing_info_present_flag"], decoded_value.vui_timing_info_present_flag, options);
        FieldToJson(jdata["vui_poc_proportional_to_timing_flag"], decoded_value.vui_poc_proportional_to_timing_flag, options);
        FieldToJson(jdata["vui_hrd_parameters_present_flag"], decoded_value.vui_hrd_parameters_present_flag, options);
        FieldToJson(jdata["bitstream_restriction_flag"], decoded_value.bitstream_restriction_flag, options);
        FieldToJson(jdata["tiles_fixed_structure_flag"], decoded_value.tiles_fixed_structure_flag, options);
        FieldToJson(jdata["motion_vectors_over_pic_boundaries_flag"], decoded_value.motion_vectors_over_pic_boundaries_flag, options);
        FieldToJson(jdata["restricted_ref_pic_lists_flag"], decoded_value.restricted_ref_pic_lists_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265SequenceParameterSetVui* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["aspect_ratio_idc"], decoded_value.aspect_ratio_idc, options);
        FieldToJson(jdata["sar_width"], decoded_value.sar_width, options);
        FieldToJson(jdata["sar_height"], decoded_value.sar_height, options);
        FieldToJson(jdata["video_format"], decoded_value.video_format, options);
        FieldToJson(jdata["colour_primaries"], decoded_value.colour_primaries, options);
        FieldToJson(jdata["transfer_characteristics"], decoded_value.transfer_characteristics, options);
        FieldToJson(jdata["matrix_coeffs"], decoded_value.matrix_coeffs, options);
        FieldToJson(jdata["chroma_sample_loc_type_top_field"], decoded_value.chroma_sample_loc_type_top_field, options);
        FieldToJson(jdata["chroma_sample_loc_type_bottom_field"], decoded_value.chroma_sample_loc_type_bottom_field, options);
        FieldToJson(jdata["reserved1"], decoded_value.reserved1, options);
        FieldToJson(jdata["reserved2"], decoded_value.reserved2, options);
        FieldToJson(jdata["def_disp_win_left_offset"], decoded_value.def_disp_win_left_offset, options);
        FieldToJson(jdata["def_disp_win_right_offset"], decoded_value.def_disp_win_right_offset, options);
        FieldToJson(jdata["def_disp_win_top_offset"], decoded_value.def_disp_win_top_offset, options);
        FieldToJson(jdata["def_disp_win_bottom_offset"], decoded_value.def_disp_win_bottom_offset, options);
        FieldToJson(jdata["vui_num_units_in_tick"], decoded_value.vui_num_units_in_tick, options);
        FieldToJson(jdata["vui_time_scale"], decoded_value.vui_time_scale, options);
        FieldToJson(jdata["vui_num_ticks_poc_diff_one_minus1"], decoded_value.vui_num_ticks_poc_diff_one_minus1, options);
        FieldToJson(jdata["min_spatial_segmentation_idc"], decoded_value.min_spatial_segmentation_idc, options);
        FieldToJson(jdata["reserved3"], decoded_value.reserved3, options);
        FieldToJson(jdata["max_bytes_per_pic_denom"], decoded_value.max_bytes_per_pic_denom, options);
        FieldToJson(jdata["max_bits_per_min_cu_denom"], decoded_value.max_bits_per_min_cu_denom, options);
        FieldToJson(jdata["log2_max_mv_length_horizontal"], decoded_value.log2_max_mv_length_horizontal, options);
        FieldToJson(jdata["log2_max_mv_length_vertical"], decoded_value.log2_max_mv_length_vertical, options);
        FieldToJson(jdata["pHrdParameters"], meta_struct.pHrdParameters, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265PredictorPaletteEntries* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["PredictorPaletteEntries"], &meta_struct.PredictorPaletteEntries, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265SpsFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sps_temporal_id_nesting_flag"], decoded_value.sps_temporal_id_nesting_flag, options);
        FieldToJson(jdata["separate_colour_plane_flag"], decoded_value.separate_colour_plane_flag, options);
        FieldToJson(jdata["conformance_window_flag"], decoded_value.conformance_window_flag, options);
        FieldToJson(jdata["sps_sub_layer_ordering_info_present_flag"], decoded_value.sps_sub_layer_ordering_info_present_flag, options);
        FieldToJson(jdata["scaling_list_enabled_flag"], decoded_value.scaling_list_enabled_flag, options);
        FieldToJson(jdata["sps_scaling_list_data_present_flag"], decoded_value.sps_scaling_list_data_present_flag, options);
        FieldToJson(jdata["amp_enabled_flag"], decoded_value.amp_enabled_flag, options);
        FieldToJson(jdata["sample_adaptive_offset_enabled_flag"], decoded_value.sample_adaptive_offset_enabled_flag, options);
        FieldToJson(jdata["pcm_enabled_flag"], decoded_value.pcm_enabled_flag, options);
        FieldToJson(jdata["pcm_loop_filter_disabled_flag"], decoded_value.pcm_loop_filter_disabled_flag, options);
        FieldToJson(jdata["long_term_ref_pics_present_flag"], decoded_value.long_term_ref_pics_present_flag, options);
        FieldToJson(jdata["sps_temporal_mvp_enabled_flag"], decoded_value.sps_temporal_mvp_enabled_flag, options);
        FieldToJson(jdata["strong_intra_smoothing_enabled_flag"], decoded_value.strong_intra_smoothing_enabled_flag, options);
        FieldToJson(jdata["vui_parameters_present_flag"], decoded_value.vui_parameters_present_flag, options);
        FieldToJson(jdata["sps_extension_present_flag"], decoded_value.sps_extension_present_flag, options);
        FieldToJson(jdata["sps_range_extension_flag"], decoded_value.sps_range_extension_flag, options);
        FieldToJson(jdata["transform_skip_rotation_enabled_flag"], decoded_value.transform_skip_rotation_enabled_flag, options);
        FieldToJson(jdata["transform_skip_context_enabled_flag"], decoded_value.transform_skip_context_enabled_flag, options);
        FieldToJson(jdata["implicit_rdpcm_enabled_flag"], decoded_value.implicit_rdpcm_enabled_flag, options);
        FieldToJson(jdata["explicit_rdpcm_enabled_flag"], decoded_value.explicit_rdpcm_enabled_flag, options);
        FieldToJson(jdata["extended_precision_processing_flag"], decoded_value.extended_precision_processing_flag, options);
        FieldToJson(jdata["intra_smoothing_disabled_flag"], decoded_value.intra_smoothing_disabled_flag, options);
        FieldToJson(jdata["high_precision_offsets_enabled_flag"], decoded_value.high_precision_offsets_enabled_flag, options);
        FieldToJson(jdata["persistent_rice_adaptation_enabled_flag"], decoded_value.persistent_rice_adaptation_enabled_flag, options);
        FieldToJson(jdata["cabac_bypass_alignment_enabled_flag"], decoded_value.cabac_bypass_alignment_enabled_flag, options);
        FieldToJson(jdata["sps_scc_extension_flag"], decoded_value.sps_scc_extension_flag, options);
        FieldToJson(jdata["sps_curr_pic_ref_enabled_flag"], decoded_value.sps_curr_pic_ref_enabled_flag, options);
        FieldToJson(jdata["palette_mode_enabled_flag"], decoded_value.palette_mode_enabled_flag, options);
        FieldToJson(jdata["sps_palette_predictor_initializers_present_flag"], decoded_value.sps_palette_predictor_initializers_present_flag, options);
        FieldToJson(jdata["intra_boundary_filtering_disabled_flag"], decoded_value.intra_boundary_filtering_disabled_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265SequenceParameterSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["chroma_format_idc"], decoded_value.chroma_format_idc, options);
        FieldToJson(jdata["pic_width_in_luma_samples"], decoded_value.pic_width_in_luma_samples, options);
        FieldToJson(jdata["pic_height_in_luma_samples"], decoded_value.pic_height_in_luma_samples, options);
        FieldToJson(jdata["sps_video_parameter_set_id"], decoded_value.sps_video_parameter_set_id, options);
        FieldToJson(jdata["sps_max_sub_layers_minus1"], decoded_value.sps_max_sub_layers_minus1, options);
        FieldToJson(jdata["sps_seq_parameter_set_id"], decoded_value.sps_seq_parameter_set_id, options);
        FieldToJson(jdata["bit_depth_luma_minus8"], decoded_value.bit_depth_luma_minus8, options);
        FieldToJson(jdata["bit_depth_chroma_minus8"], decoded_value.bit_depth_chroma_minus8, options);
        FieldToJson(jdata["log2_max_pic_order_cnt_lsb_minus4"], decoded_value.log2_max_pic_order_cnt_lsb_minus4, options);
        FieldToJson(jdata["log2_min_luma_coding_block_size_minus3"], decoded_value.log2_min_luma_coding_block_size_minus3, options);
        FieldToJson(jdata["log2_diff_max_min_luma_coding_block_size"], decoded_value.log2_diff_max_min_luma_coding_block_size, options);
        FieldToJson(jdata["log2_min_luma_transform_block_size_minus2"], decoded_value.log2_min_luma_transform_block_size_minus2, options);
        FieldToJson(jdata["log2_diff_max_min_luma_transform_block_size"], decoded_value.log2_diff_max_min_luma_transform_block_size, options);
        FieldToJson(jdata["max_transform_hierarchy_depth_inter"], decoded_value.max_transform_hierarchy_depth_inter, options);
        FieldToJson(jdata["max_transform_hierarchy_depth_intra"], decoded_value.max_transform_hierarchy_depth_intra, options);
        FieldToJson(jdata["num_short_term_ref_pic_sets"], decoded_value.num_short_term_ref_pic_sets, options);
        FieldToJson(jdata["num_long_term_ref_pics_sps"], decoded_value.num_long_term_ref_pics_sps, options);
        FieldToJson(jdata["pcm_sample_bit_depth_luma_minus1"], decoded_value.pcm_sample_bit_depth_luma_minus1, options);
        FieldToJson(jdata["pcm_sample_bit_depth_chroma_minus1"], decoded_value.pcm_sample_bit_depth_chroma_minus1, options);
        FieldToJson(jdata["log2_min_pcm_luma_coding_block_size_minus3"], decoded_value.log2_min_pcm_luma_coding_block_size_minus3, options);
        FieldToJson(jdata["log2_diff_max_min_pcm_luma_coding_block_size"], decoded_value.log2_diff_max_min_pcm_luma_coding_block_size, options);
        FieldToJson(jdata["reserved1"], decoded_value.reserved1, options);
        FieldToJson(jdata["reserved2"], decoded_value.reserved2, options);
        FieldToJson(jdata["palette_max_size"], decoded_value.palette_max_size, options);
        FieldToJson(jdata["delta_palette_max_predictor_size"], decoded_value.delta_palette_max_predictor_size, options);
        FieldToJson(jdata["motion_vector_resolution_control_idc"], decoded_value.motion_vector_resolution_control_idc, options);
        FieldToJson(jdata["sps_num_palette_predictor_initializers_minus1"], decoded_value.sps_num_palette_predictor_initializers_minus1, options);
        FieldToJson(jdata["conf_win_left_offset"], decoded_value.conf_win_left_offset, options);
        FieldToJson(jdata["conf_win_right_offset"], decoded_value.conf_win_right_offset, options);
        FieldToJson(jdata["conf_win_top_offset"], decoded_value.conf_win_top_offset, options);
        FieldToJson(jdata["conf_win_bottom_offset"], decoded_value.conf_win_bottom_offset, options);
        FieldToJson(jdata["pProfileTierLevel"], meta_struct.pProfileTierLevel, options);
        FieldToJson(jdata["pDecPicBufMgr"], meta_struct.pDecPicBufMgr, options);
        FieldToJson(jdata["pScalingLists"], meta_struct.pScalingLists, options);
        FieldToJson(jdata["pShortTermRefPicSet"], meta_struct.pShortTermRefPicSet, options);
        FieldToJson(jdata["pLongTermRefPicsSps"], meta_struct.pLongTermRefPicsSps, options);
        FieldToJson(jdata["pSequenceParameterSetVui"], meta_struct.pSequenceParameterSetVui, options);
        FieldToJson(jdata["pPredictorPaletteEntries"], meta_struct.pPredictorPaletteEntries, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265PpsFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["dependent_slice_segments_enabled_flag"], decoded_value.dependent_slice_segments_enabled_flag, options);
        FieldToJson(jdata["output_flag_present_flag"], decoded_value.output_flag_present_flag, options);
        FieldToJson(jdata["sign_data_hiding_enabled_flag"], decoded_value.sign_data_hiding_enabled_flag, options);
        FieldToJson(jdata["cabac_init_present_flag"], decoded_value.cabac_init_present_flag, options);
        FieldToJson(jdata["constrained_intra_pred_flag"], decoded_value.constrained_intra_pred_flag, options);
        FieldToJson(jdata["transform_skip_enabled_flag"], decoded_value.transform_skip_enabled_flag, options);
        FieldToJson(jdata["cu_qp_delta_enabled_flag"], decoded_value.cu_qp_delta_enabled_flag, options);
        FieldToJson(jdata["pps_slice_chroma_qp_offsets_present_flag"], decoded_value.pps_slice_chroma_qp_offsets_present_flag, options);
        FieldToJson(jdata["weighted_pred_flag"], decoded_value.weighted_pred_flag, options);
        FieldToJson(jdata["weighted_bipred_flag"], decoded_value.weighted_bipred_flag, options);
        FieldToJson(jdata["transquant_bypass_enabled_flag"], decoded_value.transquant_bypass_enabled_flag, options);
        FieldToJson(jdata["tiles_enabled_flag"], decoded_value.tiles_enabled_flag, options);
        FieldToJson(jdata["entropy_coding_sync_enabled_flag"], decoded_value.entropy_coding_sync_enabled_flag, options);
        FieldToJson(jdata["uniform_spacing_flag"], decoded_value.uniform_spacing_flag, options);
        FieldToJson(jdata["loop_filter_across_tiles_enabled_flag"], decoded_value.loop_filter_across_tiles_enabled_flag, options);
        FieldToJson(jdata["pps_loop_filter_across_slices_enabled_flag"], decoded_value.pps_loop_filter_across_slices_enabled_flag, options);
        FieldToJson(jdata["deblocking_filter_control_present_flag"], decoded_value.deblocking_filter_control_present_flag, options);
        FieldToJson(jdata["deblocking_filter_override_enabled_flag"], decoded_value.deblocking_filter_override_enabled_flag, options);
        FieldToJson(jdata["pps_deblocking_filter_disabled_flag"], decoded_value.pps_deblocking_filter_disabled_flag, options);
        FieldToJson(jdata["pps_scaling_list_data_present_flag"], decoded_value.pps_scaling_list_data_present_flag, options);
        FieldToJson(jdata["lists_modification_present_flag"], decoded_value.lists_modification_present_flag, options);
        FieldToJson(jdata["slice_segment_header_extension_present_flag"], decoded_value.slice_segment_header_extension_present_flag, options);
        FieldToJson(jdata["pps_extension_present_flag"], decoded_value.pps_extension_present_flag, options);
        FieldToJson(jdata["cross_component_prediction_enabled_flag"], decoded_value.cross_component_prediction_enabled_flag, options);
        FieldToJson(jdata["chroma_qp_offset_list_enabled_flag"], decoded_value.chroma_qp_offset_list_enabled_flag, options);
        FieldToJson(jdata["pps_curr_pic_ref_enabled_flag"], decoded_value.pps_curr_pic_ref_enabled_flag, options);
        FieldToJson(jdata["residual_adaptive_colour_transform_enabled_flag"], decoded_value.residual_adaptive_colour_transform_enabled_flag, options);
        FieldToJson(jdata["pps_slice_act_qp_offsets_present_flag"], decoded_value.pps_slice_act_qp_offsets_present_flag, options);
        FieldToJson(jdata["pps_palette_predictor_initializers_present_flag"], decoded_value.pps_palette_predictor_initializers_present_flag, options);
        FieldToJson(jdata["monochrome_palette_flag"], decoded_value.monochrome_palette_flag, options);
        FieldToJson(jdata["pps_range_extension_flag"], decoded_value.pps_range_extension_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH265PictureParameterSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["pps_pic_parameter_set_id"], decoded_value.pps_pic_parameter_set_id, options);
        FieldToJson(jdata["pps_seq_parameter_set_id"], decoded_value.pps_seq_parameter_set_id, options);
        FieldToJson(jdata["sps_video_parameter_set_id"], decoded_value.sps_video_parameter_set_id, options);
        FieldToJson(jdata["num_extra_slice_header_bits"], decoded_value.num_extra_slice_header_bits, options);
        FieldToJson(jdata["num_ref_idx_l0_default_active_minus1"], decoded_value.num_ref_idx_l0_default_active_minus1, options);
        FieldToJson(jdata["num_ref_idx_l1_default_active_minus1"], decoded_value.num_ref_idx_l1_default_active_minus1, options);
        FieldToJson(jdata["init_qp_minus26"], decoded_value.init_qp_minus26, options);
        FieldToJson(jdata["diff_cu_qp_delta_depth"], decoded_value.diff_cu_qp_delta_depth, options);
        FieldToJson(jdata["pps_cb_qp_offset"], decoded_value.pps_cb_qp_offset, options);
        FieldToJson(jdata["pps_cr_qp_offset"], decoded_value.pps_cr_qp_offset, options);
        FieldToJson(jdata["pps_beta_offset_div2"], decoded_value.pps_beta_offset_div2, options);
        FieldToJson(jdata["pps_tc_offset_div2"], decoded_value.pps_tc_offset_div2, options);
        FieldToJson(jdata["log2_parallel_merge_level_minus2"], decoded_value.log2_parallel_merge_level_minus2, options);
        FieldToJson(jdata["log2_max_transform_skip_block_size_minus2"], decoded_value.log2_max_transform_skip_block_size_minus2, options);
        FieldToJson(jdata["diff_cu_chroma_qp_offset_depth"], decoded_value.diff_cu_chroma_qp_offset_depth, options);
        FieldToJson(jdata["chroma_qp_offset_list_len_minus1"], decoded_value.chroma_qp_offset_list_len_minus1, options);
        FieldToJson(jdata["cb_qp_offset_list"], &meta_struct.cb_qp_offset_list, options);
        FieldToJson(jdata["cr_qp_offset_list"], &meta_struct.cr_qp_offset_list, options);
        FieldToJson(jdata["log2_sao_offset_scale_luma"], decoded_value.log2_sao_offset_scale_luma, options);
        FieldToJson(jdata["log2_sao_offset_scale_chroma"], decoded_value.log2_sao_offset_scale_chroma, options);
        FieldToJson(jdata["pps_act_y_qp_offset_plus5"], decoded_value.pps_act_y_qp_offset_plus5, options);
        FieldToJson(jdata["pps_act_cb_qp_offset_plus5"], decoded_value.pps_act_cb_qp_offset_plus5, options);
        FieldToJson(jdata["pps_act_cr_qp_offset_plus3"], decoded_value.pps_act_cr_qp_offset_plus3, options);
        FieldToJson(jdata["pps_num_palette_predictor_initializers"], decoded_value.pps_num_palette_predictor_initializers, options);
        FieldToJson(jdata["luma_bit_depth_entry_minus8"], decoded_value.luma_bit_depth_entry_minus8, options);
        FieldToJson(jdata["chroma_bit_depth_entry_minus8"], decoded_value.chroma_bit_depth_entry_minus8, options);
        FieldToJson(jdata["num_tile_columns_minus1"], decoded_value.num_tile_columns_minus1, options);
        FieldToJson(jdata["num_tile_rows_minus1"], decoded_value.num_tile_rows_minus1, options);
        FieldToJson(jdata["reserved1"], decoded_value.reserved1, options);
        FieldToJson(jdata["reserved2"], decoded_value.reserved2, options);
        FieldToJson(jdata["column_width_minus1"], &meta_struct.column_width_minus1, options);
        FieldToJson(jdata["row_height_minus1"], &meta_struct.row_height_minus1, options);
        FieldToJson(jdata["reserved3"], decoded_value.reserved3, options);
        FieldToJson(jdata["pScalingLists"], meta_struct.pScalingLists, options);
        FieldToJson(jdata["pPredictorPaletteEntries"], meta_struct.pPredictorPaletteEntries, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH265PictureInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["IrapPicFlag"], decoded_value.IrapPicFlag, options);
        FieldToJson(jdata["IdrPicFlag"], decoded_value.IdrPicFlag, options);
        FieldToJson(jdata["IsReference"], decoded_value.IsReference, options);
        FieldToJson(jdata["short_term_ref_pic_set_sps_flag"], decoded_value.short_term_ref_pic_set_sps_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH265PictureInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["sps_video_parameter_set_id"], decoded_value.sps_video_parameter_set_id, options);
        FieldToJson(jdata["pps_seq_parameter_set_id"], decoded_value.pps_seq_parameter_set_id, options);
        FieldToJson(jdata["pps_pic_parameter_set_id"], decoded_value.pps_pic_parameter_set_id, options);
        FieldToJson(jdata["NumDeltaPocsOfRefRpsIdx"], decoded_value.NumDeltaPocsOfRefRpsIdx, options);
        FieldToJson(jdata["PicOrderCntVal"], decoded_value.PicOrderCntVal, options);
        FieldToJson(jdata["NumBitsForSTRefPicSetInSlice"], decoded_value.NumBitsForSTRefPicSetInSlice, options);
        FieldToJson(jdata["reserved"], decoded_value.reserved, options);
        FieldToJson(jdata["RefPicSetStCurrBefore"], &meta_struct.RefPicSetStCurrBefore, options);
        FieldToJson(jdata["RefPicSetStCurrAfter"], &meta_struct.RefPicSetStCurrAfter, options);
        FieldToJson(jdata["RefPicSetLtCurr"], &meta_struct.RefPicSetLtCurr, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH265ReferenceInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["used_for_long_term_reference"], decoded_value.used_for_long_term_reference, options);
        FieldToJson(jdata["unused_for_reference"], decoded_value.unused_for_reference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH265ReferenceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["PicOrderCntVal"], decoded_value.PicOrderCntVal, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265WeightTableFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["luma_weight_l0_flag"], decoded_value.luma_weight_l0_flag, options);
        FieldToJson(jdata["chroma_weight_l0_flag"], decoded_value.chroma_weight_l0_flag, options);
        FieldToJson(jdata["luma_weight_l1_flag"], decoded_value.luma_weight_l1_flag, options);
        FieldToJson(jdata["chroma_weight_l1_flag"], decoded_value.chroma_weight_l1_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265WeightTable* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["luma_log2_weight_denom"], decoded_value.luma_log2_weight_denom, options);
        FieldToJson(jdata["delta_chroma_log2_weight_denom"], decoded_value.delta_chroma_log2_weight_denom, options);
        FieldToJson(jdata["delta_luma_weight_l0"], &meta_struct.delta_luma_weight_l0, options);
        FieldToJson(jdata["luma_offset_l0"], &meta_struct.luma_offset_l0, options);
        FieldToJson(jdata["delta_chroma_weight_l0"], &meta_struct.delta_chroma_weight_l0, options);
        FieldToJson(jdata["delta_chroma_offset_l0"], &meta_struct.delta_chroma_offset_l0, options);
        FieldToJson(jdata["delta_luma_weight_l1"], &meta_struct.delta_luma_weight_l1, options);
        FieldToJson(jdata["luma_offset_l1"], &meta_struct.luma_offset_l1, options);
        FieldToJson(jdata["delta_chroma_weight_l1"], &meta_struct.delta_chroma_weight_l1, options);
        FieldToJson(jdata["delta_chroma_offset_l1"], &meta_struct.delta_chroma_offset_l1, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265SliceSegmentLongTermRefPics* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["num_long_term_sps"], decoded_value.num_long_term_sps, options);
        FieldToJson(jdata["num_long_term_pics"], decoded_value.num_long_term_pics, options);
        FieldToJson(jdata["lt_idx_sps"], &meta_struct.lt_idx_sps, options);
        FieldToJson(jdata["poc_lsb_lt"], &meta_struct.poc_lsb_lt, options);
        FieldToJson(jdata["used_by_curr_pic_lt_flag"], decoded_value.used_by_curr_pic_lt_flag, options);
        FieldToJson(jdata["delta_poc_msb_present_flag"], &meta_struct.delta_poc_msb_present_flag, options);
        FieldToJson(jdata["delta_poc_msb_cycle_lt"], &meta_struct.delta_poc_msb_cycle_lt, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265SliceSegmentHeaderFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["first_slice_segment_in_pic_flag"], decoded_value.first_slice_segment_in_pic_flag, options);
        FieldToJson(jdata["no_output_of_prior_pics_flag"], decoded_value.no_output_of_prior_pics_flag, options);
        FieldToJson(jdata["dependent_slice_segment_flag"], decoded_value.dependent_slice_segment_flag, options);
        FieldToJson(jdata["pic_output_flag"], decoded_value.pic_output_flag, options);
        FieldToJson(jdata["short_term_ref_pic_set_sps_flag"], decoded_value.short_term_ref_pic_set_sps_flag, options);
        FieldToJson(jdata["slice_temporal_mvp_enable_flag"], decoded_value.slice_temporal_mvp_enable_flag, options);
        FieldToJson(jdata["slice_sao_luma_flag"], decoded_value.slice_sao_luma_flag, options);
        FieldToJson(jdata["slice_sao_chroma_flag"], decoded_value.slice_sao_chroma_flag, options);
        FieldToJson(jdata["num_ref_idx_active_override_flag"], decoded_value.num_ref_idx_active_override_flag, options);
        FieldToJson(jdata["mvd_l1_zero_flag"], decoded_value.mvd_l1_zero_flag, options);
        FieldToJson(jdata["cabac_init_flag"], decoded_value.cabac_init_flag, options);
        FieldToJson(jdata["cu_chroma_qp_offset_enabled_flag"], decoded_value.cu_chroma_qp_offset_enabled_flag, options);
        FieldToJson(jdata["deblocking_filter_override_flag"], decoded_value.deblocking_filter_override_flag, options);
        FieldToJson(jdata["slice_deblocking_filter_disabled_flag"], decoded_value.slice_deblocking_filter_disabled_flag, options);
        FieldToJson(jdata["collocated_from_l0_flag"], decoded_value.collocated_from_l0_flag, options);
        FieldToJson(jdata["slice_loop_filter_across_slices_enabled_flag"], decoded_value.slice_loop_filter_across_slices_enabled_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265SliceSegmentHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["slice_type"], decoded_value.slice_type, options);
        FieldToJson(jdata["slice_segment_address"], decoded_value.slice_segment_address, options);
        FieldToJson(jdata["short_term_ref_pic_set_idx"], decoded_value.short_term_ref_pic_set_idx, options);
        FieldToJson(jdata["collocated_ref_idx"], decoded_value.collocated_ref_idx, options);
        FieldToJson(jdata["num_ref_idx_l0_active_minus1"], decoded_value.num_ref_idx_l0_active_minus1, options);
        FieldToJson(jdata["num_ref_idx_l1_active_minus1"], decoded_value.num_ref_idx_l1_active_minus1, options);
        FieldToJson(jdata["MaxNumMergeCand"], decoded_value.MaxNumMergeCand, options);
        FieldToJson(jdata["slice_cb_qp_offset"], decoded_value.slice_cb_qp_offset, options);
        FieldToJson(jdata["slice_cr_qp_offset"], decoded_value.slice_cr_qp_offset, options);
        FieldToJson(jdata["slice_beta_offset_div2"], decoded_value.slice_beta_offset_div2, options);
        FieldToJson(jdata["slice_tc_offset_div2"], decoded_value.slice_tc_offset_div2, options);
        FieldToJson(jdata["slice_act_y_qp_offset"], decoded_value.slice_act_y_qp_offset, options);
        FieldToJson(jdata["slice_act_cb_qp_offset"], decoded_value.slice_act_cb_qp_offset, options);
        FieldToJson(jdata["slice_act_cr_qp_offset"], decoded_value.slice_act_cr_qp_offset, options);
        FieldToJson(jdata["pShortTermRefPicSet"], meta_struct.pShortTermRefPicSet, options);
        FieldToJson(jdata["pLongTermRefPics"], meta_struct.pLongTermRefPics, options);
        FieldToJson(jdata["pWeightTable"], meta_struct.pWeightTable, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265ReferenceModificationFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["ref_pic_list_modification_flag_l0"], decoded_value.ref_pic_list_modification_flag_l0, options);
        FieldToJson(jdata["ref_pic_list_modification_flag_l1"], decoded_value.ref_pic_list_modification_flag_l1, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265ReferenceModifications* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["referenceList0ModificationsCount"], decoded_value.referenceList0ModificationsCount, options);
        FieldToJson(jdata["pReferenceList0Modifications"], meta_struct.pReferenceList0Modifications, options);
        FieldToJson(jdata["referenceList1ModificationsCount"], decoded_value.referenceList1ModificationsCount, options);
        FieldToJson(jdata["pReferenceList1Modifications"], meta_struct.pReferenceList1Modifications, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265PictureInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["is_reference_flag"], decoded_value.is_reference_flag, options);
        FieldToJson(jdata["IrapPicFlag"], decoded_value.IrapPicFlag, options);
        FieldToJson(jdata["long_term_flag"], decoded_value.long_term_flag, options);
        FieldToJson(jdata["discardable_flag"], decoded_value.discardable_flag, options);
        FieldToJson(jdata["cross_layer_bla_flag"], decoded_value.cross_layer_bla_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265PictureInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["PictureType"], decoded_value.PictureType, options);
        FieldToJson(jdata["sps_video_parameter_set_id"], decoded_value.sps_video_parameter_set_id, options);
        FieldToJson(jdata["pps_seq_parameter_set_id"], decoded_value.pps_seq_parameter_set_id, options);
        FieldToJson(jdata["pps_pic_parameter_set_id"], decoded_value.pps_pic_parameter_set_id, options);
        FieldToJson(jdata["PicOrderCntVal"], decoded_value.PicOrderCntVal, options);
        FieldToJson(jdata["TemporalId"], decoded_value.TemporalId, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265ReferenceInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["used_for_long_term_reference"], decoded_value.used_for_long_term_reference, options);
        FieldToJson(jdata["unused_for_reference"], decoded_value.unused_for_reference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH265ReferenceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["flags"], meta_struct.flags, options);
        FieldToJson(jdata["PicOrderCntVal"], decoded_value.PicOrderCntVal, options);
        FieldToJson(jdata["TemporalId"], decoded_value.TemporalId, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExtent2D* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExtent3D* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["depth"], decoded_value.depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOffset2D* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOffset3D* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
        FieldToJson(jdata["z"], decoded_value.z, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRect2D* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["offset"], meta_struct.offset, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferMemoryBarrier* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkAccessFlags_t(),jdata["srcAccessMask"], decoded_value.srcAccessMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["dstAccessMask"], decoded_value.dstAccessMask, options);
        FieldToJson(jdata["srcQueueFamilyIndex"], decoded_value.srcQueueFamilyIndex, options);
        FieldToJson(jdata["dstQueueFamilyIndex"], decoded_value.dstQueueFamilyIndex, options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDispatchIndirectCommand* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
        FieldToJson(jdata["z"], decoded_value.z, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrawIndexedIndirectCommand* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["indexCount"], decoded_value.indexCount, options);
        FieldToJson(jdata["instanceCount"], decoded_value.instanceCount, options);
        FieldToJson(jdata["firstIndex"], decoded_value.firstIndex, options);
        FieldToJson(jdata["vertexOffset"], decoded_value.vertexOffset, options);
        FieldToJson(jdata["firstInstance"], decoded_value.firstInstance, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrawIndirectCommand* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["vertexCount"], decoded_value.vertexCount, options);
        FieldToJson(jdata["instanceCount"], decoded_value.instanceCount, options);
        FieldToJson(jdata["firstVertex"], decoded_value.firstVertex, options);
        FieldToJson(jdata["firstInstance"], decoded_value.firstInstance, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSubresourceRange* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], decoded_value.aspectMask, options);
        FieldToJson(jdata["baseMipLevel"], decoded_value.baseMipLevel, options);
        FieldToJson(jdata["levelCount"], decoded_value.levelCount, options);
        FieldToJson(jdata["baseArrayLayer"], decoded_value.baseArrayLayer, options);
        FieldToJson(jdata["layerCount"], decoded_value.layerCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageMemoryBarrier* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkAccessFlags_t(),jdata["srcAccessMask"], decoded_value.srcAccessMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["dstAccessMask"], decoded_value.dstAccessMask, options);
        FieldToJson(jdata["oldLayout"], decoded_value.oldLayout, options);
        FieldToJson(jdata["newLayout"], decoded_value.newLayout, options);
        FieldToJson(jdata["srcQueueFamilyIndex"], decoded_value.srcQueueFamilyIndex, options);
        FieldToJson(jdata["dstQueueFamilyIndex"], decoded_value.dstQueueFamilyIndex, options);
        FieldToJson(jdata["image"], to_hex(meta_struct.image), options);
        FieldToJson(jdata["subresourceRange"], meta_struct.subresourceRange, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryBarrier* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkAccessFlags_t(),jdata["srcAccessMask"], decoded_value.srcAccessMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["dstAccessMask"], decoded_value.dstAccessMask, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCacheHeaderVersionOne* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["headerSize"], decoded_value.headerSize, options);
        FieldToJson(jdata["headerVersion"], decoded_value.headerVersion, options);
        FieldToJson(jdata["vendorID"], decoded_value.vendorID, options);
        FieldToJson(jdata["deviceID"], decoded_value.deviceID, options);
        FieldToJson(jdata["pipelineCacheUUID"], uuid_to_string(sizeof(decoded_value.pipelineCacheUUID), decoded_value.pipelineCacheUUID), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAllocationCallbacks* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["pUserData"], to_hex(meta_struct.pUserData), options);
        FieldToJson(jdata["pfnAllocation"], to_hex(meta_struct.pfnAllocation), options);
        FieldToJson(jdata["pfnReallocation"], to_hex(meta_struct.pfnReallocation), options);
        FieldToJson(jdata["pfnFree"], to_hex(meta_struct.pfnFree), options);
        FieldToJson(jdata["pfnInternalAllocation"], to_hex(meta_struct.pfnInternalAllocation), options);
        FieldToJson(jdata["pfnInternalFree"], to_hex(meta_struct.pfnInternalFree), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkApplicationInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pApplicationName"], &meta_struct.pApplicationName, options);
        FieldToJson(jdata["applicationVersion"], decoded_value.applicationVersion, options);
        FieldToJson(jdata["pEngineName"], &meta_struct.pEngineName, options);
        FieldToJson(jdata["engineVersion"], decoded_value.engineVersion, options);
        FieldToJson(jdata["apiVersion"], decoded_value.apiVersion, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFormatProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkFormatFeatureFlags_t(),jdata["linearTilingFeatures"], decoded_value.linearTilingFeatures, options);
        FieldToJson(VkFormatFeatureFlags_t(),jdata["optimalTilingFeatures"], decoded_value.optimalTilingFeatures, options);
        FieldToJson(VkFormatFeatureFlags_t(),jdata["bufferFeatures"], decoded_value.bufferFeatures, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageFormatProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["maxExtent"], meta_struct.maxExtent, options);
        FieldToJson(jdata["maxMipLevels"], decoded_value.maxMipLevels, options);
        FieldToJson(jdata["maxArrayLayers"], decoded_value.maxArrayLayers, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampleCounts"], decoded_value.sampleCounts, options);
        FieldToJson(jdata["maxResourceSize"], decoded_value.maxResourceSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkInstanceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkInstanceCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pApplicationInfo"], meta_struct.pApplicationInfo, options);
        FieldToJson(jdata["enabledLayerCount"], decoded_value.enabledLayerCount, options);
        FieldToJson(jdata["ppEnabledLayerNames"], &meta_struct.ppEnabledLayerNames, options);
        FieldToJson(jdata["enabledExtensionCount"], decoded_value.enabledExtensionCount, options);
        FieldToJson(jdata["ppEnabledExtensionNames"], &meta_struct.ppEnabledExtensionNames, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryHeap* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(VkMemoryHeapFlags_t(),jdata["flags"], decoded_value.flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryType* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkMemoryPropertyFlags_t(),jdata["propertyFlags"], decoded_value.propertyFlags, options);
        FieldToJson(jdata["heapIndex"], decoded_value.heapIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["robustBufferAccess"], decoded_value.robustBufferAccess, options);
        FieldToJson(jdata["fullDrawIndexUint32"], decoded_value.fullDrawIndexUint32, options);
        FieldToJson(jdata["imageCubeArray"], decoded_value.imageCubeArray, options);
        FieldToJson(jdata["independentBlend"], decoded_value.independentBlend, options);
        FieldToJson(jdata["geometryShader"], decoded_value.geometryShader, options);
        FieldToJson(jdata["tessellationShader"], decoded_value.tessellationShader, options);
        FieldToJson(jdata["sampleRateShading"], decoded_value.sampleRateShading, options);
        FieldToJson(jdata["dualSrcBlend"], decoded_value.dualSrcBlend, options);
        FieldToJson(jdata["logicOp"], decoded_value.logicOp, options);
        FieldToJson(jdata["multiDrawIndirect"], decoded_value.multiDrawIndirect, options);
        FieldToJson(jdata["drawIndirectFirstInstance"], decoded_value.drawIndirectFirstInstance, options);
        FieldToJson(jdata["depthClamp"], decoded_value.depthClamp, options);
        FieldToJson(jdata["depthBiasClamp"], decoded_value.depthBiasClamp, options);
        FieldToJson(jdata["fillModeNonSolid"], decoded_value.fillModeNonSolid, options);
        FieldToJson(jdata["depthBounds"], decoded_value.depthBounds, options);
        FieldToJson(jdata["wideLines"], decoded_value.wideLines, options);
        FieldToJson(jdata["largePoints"], decoded_value.largePoints, options);
        FieldToJson(jdata["alphaToOne"], decoded_value.alphaToOne, options);
        FieldToJson(jdata["multiViewport"], decoded_value.multiViewport, options);
        FieldToJson(jdata["samplerAnisotropy"], decoded_value.samplerAnisotropy, options);
        FieldToJson(jdata["textureCompressionETC2"], decoded_value.textureCompressionETC2, options);
        FieldToJson(jdata["textureCompressionASTC_LDR"], decoded_value.textureCompressionASTC_LDR, options);
        FieldToJson(jdata["textureCompressionBC"], decoded_value.textureCompressionBC, options);
        FieldToJson(jdata["occlusionQueryPrecise"], decoded_value.occlusionQueryPrecise, options);
        FieldToJson(jdata["pipelineStatisticsQuery"], decoded_value.pipelineStatisticsQuery, options);
        FieldToJson(jdata["vertexPipelineStoresAndAtomics"], decoded_value.vertexPipelineStoresAndAtomics, options);
        FieldToJson(jdata["fragmentStoresAndAtomics"], decoded_value.fragmentStoresAndAtomics, options);
        FieldToJson(jdata["shaderTessellationAndGeometryPointSize"], decoded_value.shaderTessellationAndGeometryPointSize, options);
        FieldToJson(jdata["shaderImageGatherExtended"], decoded_value.shaderImageGatherExtended, options);
        FieldToJson(jdata["shaderStorageImageExtendedFormats"], decoded_value.shaderStorageImageExtendedFormats, options);
        FieldToJson(jdata["shaderStorageImageMultisample"], decoded_value.shaderStorageImageMultisample, options);
        FieldToJson(jdata["shaderStorageImageReadWithoutFormat"], decoded_value.shaderStorageImageReadWithoutFormat, options);
        FieldToJson(jdata["shaderStorageImageWriteWithoutFormat"], decoded_value.shaderStorageImageWriteWithoutFormat, options);
        FieldToJson(jdata["shaderUniformBufferArrayDynamicIndexing"], decoded_value.shaderUniformBufferArrayDynamicIndexing, options);
        FieldToJson(jdata["shaderSampledImageArrayDynamicIndexing"], decoded_value.shaderSampledImageArrayDynamicIndexing, options);
        FieldToJson(jdata["shaderStorageBufferArrayDynamicIndexing"], decoded_value.shaderStorageBufferArrayDynamicIndexing, options);
        FieldToJson(jdata["shaderStorageImageArrayDynamicIndexing"], decoded_value.shaderStorageImageArrayDynamicIndexing, options);
        FieldToJson(jdata["shaderClipDistance"], decoded_value.shaderClipDistance, options);
        FieldToJson(jdata["shaderCullDistance"], decoded_value.shaderCullDistance, options);
        FieldToJson(jdata["shaderFloat64"], decoded_value.shaderFloat64, options);
        FieldToJson(jdata["shaderInt64"], decoded_value.shaderInt64, options);
        FieldToJson(jdata["shaderInt16"], decoded_value.shaderInt16, options);
        FieldToJson(jdata["shaderResourceResidency"], decoded_value.shaderResourceResidency, options);
        FieldToJson(jdata["shaderResourceMinLod"], decoded_value.shaderResourceMinLod, options);
        FieldToJson(jdata["sparseBinding"], decoded_value.sparseBinding, options);
        FieldToJson(jdata["sparseResidencyBuffer"], decoded_value.sparseResidencyBuffer, options);
        FieldToJson(jdata["sparseResidencyImage2D"], decoded_value.sparseResidencyImage2D, options);
        FieldToJson(jdata["sparseResidencyImage3D"], decoded_value.sparseResidencyImage3D, options);
        FieldToJson(jdata["sparseResidency2Samples"], decoded_value.sparseResidency2Samples, options);
        FieldToJson(jdata["sparseResidency4Samples"], decoded_value.sparseResidency4Samples, options);
        FieldToJson(jdata["sparseResidency8Samples"], decoded_value.sparseResidency8Samples, options);
        FieldToJson(jdata["sparseResidency16Samples"], decoded_value.sparseResidency16Samples, options);
        FieldToJson(jdata["sparseResidencyAliased"], decoded_value.sparseResidencyAliased, options);
        FieldToJson(jdata["variableMultisampleRate"], decoded_value.variableMultisampleRate, options);
        FieldToJson(jdata["inheritedQueries"], decoded_value.inheritedQueries, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLimits* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["maxImageDimension1D"], decoded_value.maxImageDimension1D, options);
        FieldToJson(jdata["maxImageDimension2D"], decoded_value.maxImageDimension2D, options);
        FieldToJson(jdata["maxImageDimension3D"], decoded_value.maxImageDimension3D, options);
        FieldToJson(jdata["maxImageDimensionCube"], decoded_value.maxImageDimensionCube, options);
        FieldToJson(jdata["maxImageArrayLayers"], decoded_value.maxImageArrayLayers, options);
        FieldToJson(jdata["maxTexelBufferElements"], decoded_value.maxTexelBufferElements, options);
        FieldToJson(jdata["maxUniformBufferRange"], decoded_value.maxUniformBufferRange, options);
        FieldToJson(jdata["maxStorageBufferRange"], decoded_value.maxStorageBufferRange, options);
        FieldToJson(jdata["maxPushConstantsSize"], decoded_value.maxPushConstantsSize, options);
        FieldToJson(jdata["maxMemoryAllocationCount"], decoded_value.maxMemoryAllocationCount, options);
        FieldToJson(jdata["maxSamplerAllocationCount"], decoded_value.maxSamplerAllocationCount, options);
        FieldToJson(jdata["bufferImageGranularity"], decoded_value.bufferImageGranularity, options);
        FieldToJson(jdata["sparseAddressSpaceSize"], decoded_value.sparseAddressSpaceSize, options);
        FieldToJson(jdata["maxBoundDescriptorSets"], decoded_value.maxBoundDescriptorSets, options);
        FieldToJson(jdata["maxPerStageDescriptorSamplers"], decoded_value.maxPerStageDescriptorSamplers, options);
        FieldToJson(jdata["maxPerStageDescriptorUniformBuffers"], decoded_value.maxPerStageDescriptorUniformBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorStorageBuffers"], decoded_value.maxPerStageDescriptorStorageBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorSampledImages"], decoded_value.maxPerStageDescriptorSampledImages, options);
        FieldToJson(jdata["maxPerStageDescriptorStorageImages"], decoded_value.maxPerStageDescriptorStorageImages, options);
        FieldToJson(jdata["maxPerStageDescriptorInputAttachments"], decoded_value.maxPerStageDescriptorInputAttachments, options);
        FieldToJson(jdata["maxPerStageResources"], decoded_value.maxPerStageResources, options);
        FieldToJson(jdata["maxDescriptorSetSamplers"], decoded_value.maxDescriptorSetSamplers, options);
        FieldToJson(jdata["maxDescriptorSetUniformBuffers"], decoded_value.maxDescriptorSetUniformBuffers, options);
        FieldToJson(jdata["maxDescriptorSetUniformBuffersDynamic"], decoded_value.maxDescriptorSetUniformBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetStorageBuffers"], decoded_value.maxDescriptorSetStorageBuffers, options);
        FieldToJson(jdata["maxDescriptorSetStorageBuffersDynamic"], decoded_value.maxDescriptorSetStorageBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetSampledImages"], decoded_value.maxDescriptorSetSampledImages, options);
        FieldToJson(jdata["maxDescriptorSetStorageImages"], decoded_value.maxDescriptorSetStorageImages, options);
        FieldToJson(jdata["maxDescriptorSetInputAttachments"], decoded_value.maxDescriptorSetInputAttachments, options);
        FieldToJson(jdata["maxVertexInputAttributes"], decoded_value.maxVertexInputAttributes, options);
        FieldToJson(jdata["maxVertexInputBindings"], decoded_value.maxVertexInputBindings, options);
        FieldToJson(jdata["maxVertexInputAttributeOffset"], decoded_value.maxVertexInputAttributeOffset, options);
        FieldToJson(jdata["maxVertexInputBindingStride"], decoded_value.maxVertexInputBindingStride, options);
        FieldToJson(jdata["maxVertexOutputComponents"], decoded_value.maxVertexOutputComponents, options);
        FieldToJson(jdata["maxTessellationGenerationLevel"], decoded_value.maxTessellationGenerationLevel, options);
        FieldToJson(jdata["maxTessellationPatchSize"], decoded_value.maxTessellationPatchSize, options);
        FieldToJson(jdata["maxTessellationControlPerVertexInputComponents"], decoded_value.maxTessellationControlPerVertexInputComponents, options);
        FieldToJson(jdata["maxTessellationControlPerVertexOutputComponents"], decoded_value.maxTessellationControlPerVertexOutputComponents, options);
        FieldToJson(jdata["maxTessellationControlPerPatchOutputComponents"], decoded_value.maxTessellationControlPerPatchOutputComponents, options);
        FieldToJson(jdata["maxTessellationControlTotalOutputComponents"], decoded_value.maxTessellationControlTotalOutputComponents, options);
        FieldToJson(jdata["maxTessellationEvaluationInputComponents"], decoded_value.maxTessellationEvaluationInputComponents, options);
        FieldToJson(jdata["maxTessellationEvaluationOutputComponents"], decoded_value.maxTessellationEvaluationOutputComponents, options);
        FieldToJson(jdata["maxGeometryShaderInvocations"], decoded_value.maxGeometryShaderInvocations, options);
        FieldToJson(jdata["maxGeometryInputComponents"], decoded_value.maxGeometryInputComponents, options);
        FieldToJson(jdata["maxGeometryOutputComponents"], decoded_value.maxGeometryOutputComponents, options);
        FieldToJson(jdata["maxGeometryOutputVertices"], decoded_value.maxGeometryOutputVertices, options);
        FieldToJson(jdata["maxGeometryTotalOutputComponents"], decoded_value.maxGeometryTotalOutputComponents, options);
        FieldToJson(jdata["maxFragmentInputComponents"], decoded_value.maxFragmentInputComponents, options);
        FieldToJson(jdata["maxFragmentOutputAttachments"], decoded_value.maxFragmentOutputAttachments, options);
        FieldToJson(jdata["maxFragmentDualSrcAttachments"], decoded_value.maxFragmentDualSrcAttachments, options);
        FieldToJson(jdata["maxFragmentCombinedOutputResources"], decoded_value.maxFragmentCombinedOutputResources, options);
        FieldToJson(jdata["maxComputeSharedMemorySize"], decoded_value.maxComputeSharedMemorySize, options);
        FieldToJson(jdata["maxComputeWorkGroupCount"], &meta_struct.maxComputeWorkGroupCount, options);
        FieldToJson(jdata["maxComputeWorkGroupInvocations"], decoded_value.maxComputeWorkGroupInvocations, options);
        FieldToJson(jdata["maxComputeWorkGroupSize"], &meta_struct.maxComputeWorkGroupSize, options);
        FieldToJson(jdata["subPixelPrecisionBits"], decoded_value.subPixelPrecisionBits, options);
        FieldToJson(jdata["subTexelPrecisionBits"], decoded_value.subTexelPrecisionBits, options);
        FieldToJson(jdata["mipmapPrecisionBits"], decoded_value.mipmapPrecisionBits, options);
        FieldToJson(jdata["maxDrawIndexedIndexValue"], decoded_value.maxDrawIndexedIndexValue, options);
        FieldToJson(jdata["maxDrawIndirectCount"], decoded_value.maxDrawIndirectCount, options);
        FieldToJson(jdata["maxSamplerLodBias"], decoded_value.maxSamplerLodBias, options);
        FieldToJson(jdata["maxSamplerAnisotropy"], decoded_value.maxSamplerAnisotropy, options);
        FieldToJson(jdata["maxViewports"], decoded_value.maxViewports, options);
        FieldToJson(jdata["maxViewportDimensions"], &meta_struct.maxViewportDimensions, options);
        FieldToJson(jdata["viewportBoundsRange"], &meta_struct.viewportBoundsRange, options);
        FieldToJson(jdata["viewportSubPixelBits"], decoded_value.viewportSubPixelBits, options);
        FieldToJson(jdata["minMemoryMapAlignment"], decoded_value.minMemoryMapAlignment, options);
        FieldToJson(jdata["minTexelBufferOffsetAlignment"], decoded_value.minTexelBufferOffsetAlignment, options);
        FieldToJson(jdata["minUniformBufferOffsetAlignment"], decoded_value.minUniformBufferOffsetAlignment, options);
        FieldToJson(jdata["minStorageBufferOffsetAlignment"], decoded_value.minStorageBufferOffsetAlignment, options);
        FieldToJson(jdata["minTexelOffset"], decoded_value.minTexelOffset, options);
        FieldToJson(jdata["maxTexelOffset"], decoded_value.maxTexelOffset, options);
        FieldToJson(jdata["minTexelGatherOffset"], decoded_value.minTexelGatherOffset, options);
        FieldToJson(jdata["maxTexelGatherOffset"], decoded_value.maxTexelGatherOffset, options);
        FieldToJson(jdata["minInterpolationOffset"], decoded_value.minInterpolationOffset, options);
        FieldToJson(jdata["maxInterpolationOffset"], decoded_value.maxInterpolationOffset, options);
        FieldToJson(jdata["subPixelInterpolationOffsetBits"], decoded_value.subPixelInterpolationOffsetBits, options);
        FieldToJson(jdata["maxFramebufferWidth"], decoded_value.maxFramebufferWidth, options);
        FieldToJson(jdata["maxFramebufferHeight"], decoded_value.maxFramebufferHeight, options);
        FieldToJson(jdata["maxFramebufferLayers"], decoded_value.maxFramebufferLayers, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["framebufferColorSampleCounts"], decoded_value.framebufferColorSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["framebufferDepthSampleCounts"], decoded_value.framebufferDepthSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["framebufferStencilSampleCounts"], decoded_value.framebufferStencilSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["framebufferNoAttachmentsSampleCounts"], decoded_value.framebufferNoAttachmentsSampleCounts, options);
        FieldToJson(jdata["maxColorAttachments"], decoded_value.maxColorAttachments, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampledImageColorSampleCounts"], decoded_value.sampledImageColorSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampledImageIntegerSampleCounts"], decoded_value.sampledImageIntegerSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampledImageDepthSampleCounts"], decoded_value.sampledImageDepthSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampledImageStencilSampleCounts"], decoded_value.sampledImageStencilSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["storageImageSampleCounts"], decoded_value.storageImageSampleCounts, options);
        FieldToJson(jdata["maxSampleMaskWords"], decoded_value.maxSampleMaskWords, options);
        FieldToJson(jdata["timestampComputeAndGraphics"], decoded_value.timestampComputeAndGraphics, options);
        FieldToJson(jdata["timestampPeriod"], decoded_value.timestampPeriod, options);
        FieldToJson(jdata["maxClipDistances"], decoded_value.maxClipDistances, options);
        FieldToJson(jdata["maxCullDistances"], decoded_value.maxCullDistances, options);
        FieldToJson(jdata["maxCombinedClipAndCullDistances"], decoded_value.maxCombinedClipAndCullDistances, options);
        FieldToJson(jdata["discreteQueuePriorities"], decoded_value.discreteQueuePriorities, options);
        FieldToJson(jdata["pointSizeRange"], &meta_struct.pointSizeRange, options);
        FieldToJson(jdata["lineWidthRange"], &meta_struct.lineWidthRange, options);
        FieldToJson(jdata["pointSizeGranularity"], decoded_value.pointSizeGranularity, options);
        FieldToJson(jdata["lineWidthGranularity"], decoded_value.lineWidthGranularity, options);
        FieldToJson(jdata["strictLines"], decoded_value.strictLines, options);
        FieldToJson(jdata["standardSampleLocations"], decoded_value.standardSampleLocations, options);
        FieldToJson(jdata["optimalBufferCopyOffsetAlignment"], decoded_value.optimalBufferCopyOffsetAlignment, options);
        FieldToJson(jdata["optimalBufferCopyRowPitchAlignment"], decoded_value.optimalBufferCopyRowPitchAlignment, options);
        FieldToJson(jdata["nonCoherentAtomSize"], decoded_value.nonCoherentAtomSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMemoryProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["memoryTypeCount"], decoded_value.memoryTypeCount, options);
        FieldToJson(jdata["memoryTypes"], meta_struct.memoryTypes, options);
        FieldToJson(jdata["memoryHeapCount"], decoded_value.memoryHeapCount, options);
        FieldToJson(jdata["memoryHeaps"], meta_struct.memoryHeaps, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSparseProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["residencyStandard2DBlockShape"], decoded_value.residencyStandard2DBlockShape, options);
        FieldToJson(jdata["residencyStandard2DMultisampleBlockShape"], decoded_value.residencyStandard2DMultisampleBlockShape, options);
        FieldToJson(jdata["residencyStandard3DBlockShape"], decoded_value.residencyStandard3DBlockShape, options);
        FieldToJson(jdata["residencyAlignedMipSize"], decoded_value.residencyAlignedMipSize, options);
        FieldToJson(jdata["residencyNonResidentStrict"], decoded_value.residencyNonResidentStrict, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["apiVersion"], decoded_value.apiVersion, options);
        FieldToJson(jdata["driverVersion"], decoded_value.driverVersion, options);
        FieldToJson(jdata["vendorID"], decoded_value.vendorID, options);
        FieldToJson(jdata["deviceID"], decoded_value.deviceID, options);
        FieldToJson(jdata["deviceType"], decoded_value.deviceType, options);
        FieldToJson(jdata["deviceName"], &meta_struct.deviceName, options);
        FieldToJson(jdata["pipelineCacheUUID"], uuid_to_string(sizeof(decoded_value.pipelineCacheUUID), decoded_value.pipelineCacheUUID), options);
        FieldToJson(jdata["limits"], meta_struct.limits, options);
        FieldToJson(jdata["sparseProperties"], meta_struct.sparseProperties, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkQueueFlags_t(),jdata["queueFlags"], decoded_value.queueFlags, options);
        FieldToJson(jdata["queueCount"], decoded_value.queueCount, options);
        FieldToJson(jdata["timestampValidBits"], decoded_value.timestampValidBits, options);
        FieldToJson(jdata["minImageTransferGranularity"], meta_struct.minImageTransferGranularity, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceQueueCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDeviceQueueCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["queueFamilyIndex"], decoded_value.queueFamilyIndex, options);
        FieldToJson(jdata["queueCount"], decoded_value.queueCount, options);
        FieldToJson(jdata["pQueuePriorities"], meta_struct.pQueuePriorities, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDeviceCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["queueCreateInfoCount"], decoded_value.queueCreateInfoCount, options);
        FieldToJson(jdata["pQueueCreateInfos"], meta_struct.pQueueCreateInfos, options);
        FieldToJson(jdata["enabledLayerCount"], decoded_value.enabledLayerCount, options);
        FieldToJson(jdata["ppEnabledLayerNames"], &meta_struct.ppEnabledLayerNames, options);
        FieldToJson(jdata["enabledExtensionCount"], decoded_value.enabledExtensionCount, options);
        FieldToJson(jdata["ppEnabledExtensionNames"], &meta_struct.ppEnabledExtensionNames, options);
        FieldToJson(jdata["pEnabledFeatures"], meta_struct.pEnabledFeatures, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExtensionProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["extensionName"], &meta_struct.extensionName, options);
        FieldToJson(jdata["specVersion"], decoded_value.specVersion, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkLayerProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["layerName"], &meta_struct.layerName, options);
        FieldToJson(jdata["specVersion"], decoded_value.specVersion, options);
        FieldToJson(jdata["implementationVersion"], decoded_value.implementationVersion, options);
        FieldToJson(jdata["description"], &meta_struct.description, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["waitSemaphoreCount"], decoded_value.waitSemaphoreCount, options);
        FieldToJson(jdata["pWaitSemaphores"], &meta_struct.pWaitSemaphores, options);
        FieldToJson(jdata["pWaitDstStageMask"], meta_struct.pWaitDstStageMask, options);
        FieldToJson(jdata["commandBufferCount"], decoded_value.commandBufferCount, options);
        FieldToJson(jdata["pCommandBuffers"], &meta_struct.pCommandBuffers, options);
        FieldToJson(jdata["signalSemaphoreCount"], decoded_value.signalSemaphoreCount, options);
        FieldToJson(jdata["pSignalSemaphores"], &meta_struct.pSignalSemaphores, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMappedMemoryRange* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["allocationSize"], decoded_value.allocationSize, options);
        FieldToJson(jdata["memoryTypeIndex"], decoded_value.memoryTypeIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryRequirements* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["alignment"], decoded_value.alignment, options);
        FieldToJson(jdata["memoryTypeBits"], decoded_value.memoryTypeBits, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseMemoryBind* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["resourceOffset"], decoded_value.resourceOffset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["memoryOffset"], decoded_value.memoryOffset, options);
        FieldToJson(VkSparseMemoryBindFlags_t(),jdata["flags"], decoded_value.flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseBufferMemoryBindInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["bindCount"], decoded_value.bindCount, options);
        FieldToJson(jdata["pBinds"], meta_struct.pBinds, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageOpaqueMemoryBindInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["image"], to_hex(meta_struct.image), options);
        FieldToJson(jdata["bindCount"], decoded_value.bindCount, options);
        FieldToJson(jdata["pBinds"], meta_struct.pBinds, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSubresource* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], decoded_value.aspectMask, options);
        FieldToJson(jdata["mipLevel"], decoded_value.mipLevel, options);
        FieldToJson(jdata["arrayLayer"], decoded_value.arrayLayer, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageMemoryBind* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["subresource"], meta_struct.subresource, options);
        FieldToJson(jdata["offset"], meta_struct.offset, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["memoryOffset"], decoded_value.memoryOffset, options);
        FieldToJson(VkSparseMemoryBindFlags_t(),jdata["flags"], decoded_value.flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageMemoryBindInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["image"], to_hex(meta_struct.image), options);
        FieldToJson(jdata["bindCount"], decoded_value.bindCount, options);
        FieldToJson(jdata["pBinds"], meta_struct.pBinds, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindSparseInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["waitSemaphoreCount"], decoded_value.waitSemaphoreCount, options);
        FieldToJson(jdata["pWaitSemaphores"], &meta_struct.pWaitSemaphores, options);
        FieldToJson(jdata["bufferBindCount"], decoded_value.bufferBindCount, options);
        FieldToJson(jdata["pBufferBinds"], meta_struct.pBufferBinds, options);
        FieldToJson(jdata["imageOpaqueBindCount"], decoded_value.imageOpaqueBindCount, options);
        FieldToJson(jdata["pImageOpaqueBinds"], meta_struct.pImageOpaqueBinds, options);
        FieldToJson(jdata["imageBindCount"], decoded_value.imageBindCount, options);
        FieldToJson(jdata["pImageBinds"], meta_struct.pImageBinds, options);
        FieldToJson(jdata["signalSemaphoreCount"], decoded_value.signalSemaphoreCount, options);
        FieldToJson(jdata["pSignalSemaphores"], &meta_struct.pSignalSemaphores, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageFormatProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], decoded_value.aspectMask, options);
        FieldToJson(jdata["imageGranularity"], meta_struct.imageGranularity, options);
        FieldToJson(VkSparseImageFormatFlags_t(),jdata["flags"], decoded_value.flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageMemoryRequirements* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["formatProperties"], meta_struct.formatProperties, options);
        FieldToJson(jdata["imageMipTailFirstLod"], decoded_value.imageMipTailFirstLod, options);
        FieldToJson(jdata["imageMipTailSize"], decoded_value.imageMipTailSize, options);
        FieldToJson(jdata["imageMipTailOffset"], decoded_value.imageMipTailOffset, options);
        FieldToJson(jdata["imageMipTailStride"], decoded_value.imageMipTailStride, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFenceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkFenceCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkSemaphoreCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkEventCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkEventCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueryPoolCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkQueryPoolCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["queryType"], decoded_value.queryType, options);
        FieldToJson(jdata["queryCount"], decoded_value.queryCount, options);
        FieldToJson(VkQueryPipelineStatisticFlags_t(),jdata["pipelineStatistics"], decoded_value.pipelineStatistics, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkBufferCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(VkBufferUsageFlags_t(),jdata["usage"], decoded_value.usage, options);
        FieldToJson(jdata["sharingMode"], decoded_value.sharingMode, options);
        FieldToJson(jdata["queueFamilyIndexCount"], decoded_value.queueFamilyIndexCount, options);
        FieldToJson(jdata["pQueueFamilyIndices"], meta_struct.pQueueFamilyIndices, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferViewCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkBufferViewCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["range"], decoded_value.range, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkImageCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["imageType"], decoded_value.imageType, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
        FieldToJson(jdata["mipLevels"], decoded_value.mipLevels, options);
        FieldToJson(jdata["arrayLayers"], decoded_value.arrayLayers, options);
        FieldToJson(jdata["samples"], decoded_value.samples, options);
        FieldToJson(jdata["tiling"], decoded_value.tiling, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["usage"], decoded_value.usage, options);
        FieldToJson(jdata["sharingMode"], decoded_value.sharingMode, options);
        FieldToJson(jdata["queueFamilyIndexCount"], decoded_value.queueFamilyIndexCount, options);
        FieldToJson(jdata["pQueueFamilyIndices"], meta_struct.pQueueFamilyIndices, options);
        FieldToJson(jdata["initialLayout"], decoded_value.initialLayout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubresourceLayout* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["rowPitch"], decoded_value.rowPitch, options);
        FieldToJson(jdata["arrayPitch"], decoded_value.arrayPitch, options);
        FieldToJson(jdata["depthPitch"], decoded_value.depthPitch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkComponentMapping* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["r"], decoded_value.r, options);
        FieldToJson(jdata["g"], decoded_value.g, options);
        FieldToJson(jdata["b"], decoded_value.b, options);
        FieldToJson(jdata["a"], decoded_value.a, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkImageViewCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["image"], to_hex(meta_struct.image), options);
        FieldToJson(jdata["viewType"], decoded_value.viewType, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["components"], meta_struct.components, options);
        FieldToJson(jdata["subresourceRange"], meta_struct.subresourceRange, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSpecializationMapEntry* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["constantID"], decoded_value.constantID, options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSpecializationInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["mapEntryCount"], decoded_value.mapEntryCount, options);
        FieldToJson(jdata["pMapEntries"], meta_struct.pMapEntries, options);
        FieldToJson(jdata["dataSize"], decoded_value.dataSize, options);
        FieldToJson(jdata["pData"], meta_struct.pData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineShaderStageCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineShaderStageCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["stage"], decoded_value.stage, options);
        FieldToJson(jdata["module"], to_hex(meta_struct.module), options);
        FieldToJson(jdata["pName"], &meta_struct.pName, options);
        FieldToJson(jdata["pSpecializationInfo"], meta_struct.pSpecializationInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkComputePipelineCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["stage"], meta_struct.stage, options);
        FieldToJson(jdata["layout"], to_hex(meta_struct.layout), options);
        FieldToJson(jdata["basePipelineHandle"], to_hex(meta_struct.basePipelineHandle), options);
        FieldToJson(jdata["basePipelineIndex"], decoded_value.basePipelineIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVertexInputBindingDescription* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["binding"], decoded_value.binding, options);
        FieldToJson(jdata["stride"], decoded_value.stride, options);
        FieldToJson(jdata["inputRate"], decoded_value.inputRate, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVertexInputAttributeDescription* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["location"], decoded_value.location, options);
        FieldToJson(jdata["binding"], decoded_value.binding, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineVertexInputStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineVertexInputStateCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["vertexBindingDescriptionCount"], decoded_value.vertexBindingDescriptionCount, options);
        FieldToJson(jdata["pVertexBindingDescriptions"], meta_struct.pVertexBindingDescriptions, options);
        FieldToJson(jdata["vertexAttributeDescriptionCount"], decoded_value.vertexAttributeDescriptionCount, options);
        FieldToJson(jdata["pVertexAttributeDescriptions"], meta_struct.pVertexAttributeDescriptions, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineInputAssemblyStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineInputAssemblyStateCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["topology"], decoded_value.topology, options);
        FieldToJson(jdata["primitiveRestartEnable"], decoded_value.primitiveRestartEnable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineTessellationStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineTessellationStateCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["patchControlPoints"], decoded_value.patchControlPoints, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkViewport* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["minDepth"], decoded_value.minDepth, options);
        FieldToJson(jdata["maxDepth"], decoded_value.maxDepth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineViewportStateCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["viewportCount"], decoded_value.viewportCount, options);
        FieldToJson(jdata["pViewports"], meta_struct.pViewports, options);
        FieldToJson(jdata["scissorCount"], decoded_value.scissorCount, options);
        FieldToJson(jdata["pScissors"], meta_struct.pScissors, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineRasterizationStateCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["depthClampEnable"], decoded_value.depthClampEnable, options);
        FieldToJson(jdata["rasterizerDiscardEnable"], decoded_value.rasterizerDiscardEnable, options);
        FieldToJson(jdata["polygonMode"], decoded_value.polygonMode, options);
        FieldToJson(VkCullModeFlags_t(),jdata["cullMode"], decoded_value.cullMode, options);
        FieldToJson(jdata["frontFace"], decoded_value.frontFace, options);
        FieldToJson(jdata["depthBiasEnable"], decoded_value.depthBiasEnable, options);
        FieldToJson(jdata["depthBiasConstantFactor"], decoded_value.depthBiasConstantFactor, options);
        FieldToJson(jdata["depthBiasClamp"], decoded_value.depthBiasClamp, options);
        FieldToJson(jdata["depthBiasSlopeFactor"], decoded_value.depthBiasSlopeFactor, options);
        FieldToJson(jdata["lineWidth"], decoded_value.lineWidth, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineMultisampleStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineMultisampleStateCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["rasterizationSamples"], decoded_value.rasterizationSamples, options);
        FieldToJson(jdata["sampleShadingEnable"], decoded_value.sampleShadingEnable, options);
        FieldToJson(jdata["minSampleShading"], decoded_value.minSampleShading, options);
        FieldToJson(jdata["pSampleMask"], meta_struct.pSampleMask, options);
        FieldToJson(jdata["alphaToCoverageEnable"], decoded_value.alphaToCoverageEnable, options);
        FieldToJson(jdata["alphaToOneEnable"], decoded_value.alphaToOneEnable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkStencilOpState* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["failOp"], decoded_value.failOp, options);
        FieldToJson(jdata["passOp"], decoded_value.passOp, options);
        FieldToJson(jdata["depthFailOp"], decoded_value.depthFailOp, options);
        FieldToJson(jdata["compareOp"], decoded_value.compareOp, options);
        FieldToJson(jdata["compareMask"], decoded_value.compareMask, options);
        FieldToJson(jdata["writeMask"], decoded_value.writeMask, options);
        FieldToJson(jdata["reference"], decoded_value.reference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineDepthStencilStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineDepthStencilStateCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["depthTestEnable"], decoded_value.depthTestEnable, options);
        FieldToJson(jdata["depthWriteEnable"], decoded_value.depthWriteEnable, options);
        FieldToJson(jdata["depthCompareOp"], decoded_value.depthCompareOp, options);
        FieldToJson(jdata["depthBoundsTestEnable"], decoded_value.depthBoundsTestEnable, options);
        FieldToJson(jdata["stencilTestEnable"], decoded_value.stencilTestEnable, options);
        FieldToJson(jdata["front"], meta_struct.front, options);
        FieldToJson(jdata["back"], meta_struct.back, options);
        FieldToJson(jdata["minDepthBounds"], decoded_value.minDepthBounds, options);
        FieldToJson(jdata["maxDepthBounds"], decoded_value.maxDepthBounds, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineColorBlendAttachmentState* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["blendEnable"], decoded_value.blendEnable, options);
        FieldToJson(jdata["srcColorBlendFactor"], decoded_value.srcColorBlendFactor, options);
        FieldToJson(jdata["dstColorBlendFactor"], decoded_value.dstColorBlendFactor, options);
        FieldToJson(jdata["colorBlendOp"], decoded_value.colorBlendOp, options);
        FieldToJson(jdata["srcAlphaBlendFactor"], decoded_value.srcAlphaBlendFactor, options);
        FieldToJson(jdata["dstAlphaBlendFactor"], decoded_value.dstAlphaBlendFactor, options);
        FieldToJson(jdata["alphaBlendOp"], decoded_value.alphaBlendOp, options);
        FieldToJson(VkColorComponentFlags_t(),jdata["colorWriteMask"], decoded_value.colorWriteMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineColorBlendStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineColorBlendStateCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["logicOpEnable"], decoded_value.logicOpEnable, options);
        FieldToJson(jdata["logicOp"], decoded_value.logicOp, options);
        FieldToJson(jdata["attachmentCount"], decoded_value.attachmentCount, options);
        FieldToJson(jdata["pAttachments"], meta_struct.pAttachments, options);
        FieldToJson(jdata["blendConstants"], &meta_struct.blendConstants, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineDynamicStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineDynamicStateCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["dynamicStateCount"], decoded_value.dynamicStateCount, options);
        FieldToJson(jdata["pDynamicStates"], meta_struct.pDynamicStates, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGraphicsPipelineCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["stageCount"], decoded_value.stageCount, options);
        FieldToJson(jdata["pStages"], meta_struct.pStages, options);
        FieldToJson(jdata["pVertexInputState"], meta_struct.pVertexInputState, options);
        FieldToJson(jdata["pInputAssemblyState"], meta_struct.pInputAssemblyState, options);
        FieldToJson(jdata["pTessellationState"], meta_struct.pTessellationState, options);
        FieldToJson(jdata["pViewportState"], meta_struct.pViewportState, options);
        FieldToJson(jdata["pRasterizationState"], meta_struct.pRasterizationState, options);
        FieldToJson(jdata["pMultisampleState"], meta_struct.pMultisampleState, options);
        FieldToJson(jdata["pDepthStencilState"], meta_struct.pDepthStencilState, options);
        FieldToJson(jdata["pColorBlendState"], meta_struct.pColorBlendState, options);
        FieldToJson(jdata["pDynamicState"], meta_struct.pDynamicState, options);
        FieldToJson(jdata["layout"], to_hex(meta_struct.layout), options);
        FieldToJson(jdata["renderPass"], to_hex(meta_struct.renderPass), options);
        FieldToJson(jdata["subpass"], decoded_value.subpass, options);
        FieldToJson(jdata["basePipelineHandle"], to_hex(meta_struct.basePipelineHandle), options);
        FieldToJson(jdata["basePipelineIndex"], decoded_value.basePipelineIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPushConstantRange* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkShaderStageFlags_t(),jdata["stageFlags"], decoded_value.stageFlags, options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineLayoutCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineLayoutCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["setLayoutCount"], decoded_value.setLayoutCount, options);
        FieldToJson(jdata["pSetLayouts"], &meta_struct.pSetLayouts, options);
        FieldToJson(jdata["pushConstantRangeCount"], decoded_value.pushConstantRangeCount, options);
        FieldToJson(jdata["pPushConstantRanges"], meta_struct.pPushConstantRanges, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkSamplerCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["magFilter"], decoded_value.magFilter, options);
        FieldToJson(jdata["minFilter"], decoded_value.minFilter, options);
        FieldToJson(jdata["mipmapMode"], decoded_value.mipmapMode, options);
        FieldToJson(jdata["addressModeU"], decoded_value.addressModeU, options);
        FieldToJson(jdata["addressModeV"], decoded_value.addressModeV, options);
        FieldToJson(jdata["addressModeW"], decoded_value.addressModeW, options);
        FieldToJson(jdata["mipLodBias"], decoded_value.mipLodBias, options);
        FieldToJson(jdata["anisotropyEnable"], decoded_value.anisotropyEnable, options);
        FieldToJson(jdata["maxAnisotropy"], decoded_value.maxAnisotropy, options);
        FieldToJson(jdata["compareEnable"], decoded_value.compareEnable, options);
        FieldToJson(jdata["compareOp"], decoded_value.compareOp, options);
        FieldToJson(jdata["minLod"], decoded_value.minLod, options);
        FieldToJson(jdata["maxLod"], decoded_value.maxLod, options);
        FieldToJson(jdata["borderColor"], decoded_value.borderColor, options);
        FieldToJson(jdata["unnormalizedCoordinates"], decoded_value.unnormalizedCoordinates, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyDescriptorSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcSet"], to_hex(meta_struct.srcSet), options);
        FieldToJson(jdata["srcBinding"], decoded_value.srcBinding, options);
        FieldToJson(jdata["srcArrayElement"], decoded_value.srcArrayElement, options);
        FieldToJson(jdata["dstSet"], to_hex(meta_struct.dstSet), options);
        FieldToJson(jdata["dstBinding"], decoded_value.dstBinding, options);
        FieldToJson(jdata["dstArrayElement"], decoded_value.dstArrayElement, options);
        FieldToJson(jdata["descriptorCount"], decoded_value.descriptorCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorBufferInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["range"], decoded_value.range, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorPoolSize* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["descriptorCount"], decoded_value.descriptorCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorPoolCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDescriptorPoolCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["maxSets"], decoded_value.maxSets, options);
        FieldToJson(jdata["poolSizeCount"], decoded_value.poolSizeCount, options);
        FieldToJson(jdata["pPoolSizes"], meta_struct.pPoolSizes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["descriptorPool"], to_hex(meta_struct.descriptorPool), options);
        FieldToJson(jdata["descriptorSetCount"], decoded_value.descriptorSetCount, options);
        FieldToJson(jdata["pSetLayouts"], &meta_struct.pSetLayouts, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetLayoutBinding* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["binding"], decoded_value.binding, options);
        FieldToJson(jdata["descriptorType"], decoded_value.descriptorType, options);
        FieldToJson(jdata["descriptorCount"], decoded_value.descriptorCount, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["stageFlags"], decoded_value.stageFlags, options);
        FieldToJson(jdata["pImmutableSamplers"], &meta_struct.pImmutableSamplers, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetLayoutCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDescriptorSetLayoutCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["bindingCount"], decoded_value.bindingCount, options);
        FieldToJson(jdata["pBindings"], meta_struct.pBindings, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentDescription* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkAttachmentDescriptionFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["samples"], decoded_value.samples, options);
        FieldToJson(jdata["loadOp"], decoded_value.loadOp, options);
        FieldToJson(jdata["storeOp"], decoded_value.storeOp, options);
        FieldToJson(jdata["stencilLoadOp"], decoded_value.stencilLoadOp, options);
        FieldToJson(jdata["stencilStoreOp"], decoded_value.stencilStoreOp, options);
        FieldToJson(jdata["initialLayout"], decoded_value.initialLayout, options);
        FieldToJson(jdata["finalLayout"], decoded_value.finalLayout, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentReference* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["attachment"], decoded_value.attachment, options);
        FieldToJson(jdata["layout"], decoded_value.layout, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFramebufferCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkFramebufferCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["renderPass"], to_hex(meta_struct.renderPass), options);
        FieldToJson(jdata["attachmentCount"], decoded_value.attachmentCount, options);
        FieldToJson(jdata["pAttachments"], &meta_struct.pAttachments, options);
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["layers"], decoded_value.layers, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassDescription* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkSubpassDescriptionFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pipelineBindPoint"], decoded_value.pipelineBindPoint, options);
        FieldToJson(jdata["inputAttachmentCount"], decoded_value.inputAttachmentCount, options);
        FieldToJson(jdata["pInputAttachments"], meta_struct.pInputAttachments, options);
        FieldToJson(jdata["colorAttachmentCount"], decoded_value.colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachments"], meta_struct.pColorAttachments, options);
        FieldToJson(jdata["pResolveAttachments"], meta_struct.pResolveAttachments, options);
        FieldToJson(jdata["pDepthStencilAttachment"], meta_struct.pDepthStencilAttachment, options);
        FieldToJson(jdata["preserveAttachmentCount"], decoded_value.preserveAttachmentCount, options);
        FieldToJson(jdata["pPreserveAttachments"], meta_struct.pPreserveAttachments, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassDependency* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["srcSubpass"], decoded_value.srcSubpass, options);
        FieldToJson(jdata["dstSubpass"], decoded_value.dstSubpass, options);
        FieldToJson(VkPipelineStageFlags_t(),jdata["srcStageMask"], decoded_value.srcStageMask, options);
        FieldToJson(VkPipelineStageFlags_t(),jdata["dstStageMask"], decoded_value.dstStageMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["srcAccessMask"], decoded_value.srcAccessMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["dstAccessMask"], decoded_value.dstAccessMask, options);
        FieldToJson(VkDependencyFlags_t(),jdata["dependencyFlags"], decoded_value.dependencyFlags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkRenderPassCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["attachmentCount"], decoded_value.attachmentCount, options);
        FieldToJson(jdata["pAttachments"], meta_struct.pAttachments, options);
        FieldToJson(jdata["subpassCount"], decoded_value.subpassCount, options);
        FieldToJson(jdata["pSubpasses"], meta_struct.pSubpasses, options);
        FieldToJson(jdata["dependencyCount"], decoded_value.dependencyCount, options);
        FieldToJson(jdata["pDependencies"], meta_struct.pDependencies, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandPoolCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkCommandPoolCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["queueFamilyIndex"], decoded_value.queueFamilyIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["commandPool"], to_hex(meta_struct.commandPool), options);
        FieldToJson(jdata["level"], decoded_value.level, options);
        FieldToJson(jdata["commandBufferCount"], decoded_value.commandBufferCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferInheritanceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["renderPass"], to_hex(meta_struct.renderPass), options);
        FieldToJson(jdata["subpass"], decoded_value.subpass, options);
        FieldToJson(jdata["framebuffer"], to_hex(meta_struct.framebuffer), options);
        FieldToJson(jdata["occlusionQueryEnable"], decoded_value.occlusionQueryEnable, options);
        FieldToJson(VkQueryControlFlags_t(),jdata["queryFlags"], decoded_value.queryFlags, options);
        FieldToJson(VkQueryPipelineStatisticFlags_t(),jdata["pipelineStatistics"], decoded_value.pipelineStatistics, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkCommandBufferUsageFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pInheritanceInfo"], meta_struct.pInheritanceInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferCopy* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["srcOffset"], decoded_value.srcOffset, options);
        FieldToJson(jdata["dstOffset"], decoded_value.dstOffset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSubresourceLayers* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], decoded_value.aspectMask, options);
        FieldToJson(jdata["mipLevel"], decoded_value.mipLevel, options);
        FieldToJson(jdata["baseArrayLayer"], decoded_value.baseArrayLayer, options);
        FieldToJson(jdata["layerCount"], decoded_value.layerCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferImageCopy* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["bufferOffset"], decoded_value.bufferOffset, options);
        FieldToJson(jdata["bufferRowLength"], decoded_value.bufferRowLength, options);
        FieldToJson(jdata["bufferImageHeight"], decoded_value.bufferImageHeight, options);
        FieldToJson(jdata["imageSubresource"], meta_struct.imageSubresource, options);
        FieldToJson(jdata["imageOffset"], meta_struct.imageOffset, options);
        FieldToJson(jdata["imageExtent"], meta_struct.imageExtent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkClearDepthStencilValue* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["depth"], decoded_value.depth, options);
        FieldToJson(jdata["stencil"], decoded_value.stencil, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkClearAttachment* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], decoded_value.aspectMask, options);
        FieldToJson(jdata["colorAttachment"], decoded_value.colorAttachment, options);
        FieldToJson(jdata["clearValue"], meta_struct.clearValue, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkClearRect* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["rect"], meta_struct.rect, options);
        FieldToJson(jdata["baseArrayLayer"], decoded_value.baseArrayLayer, options);
        FieldToJson(jdata["layerCount"], decoded_value.layerCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageBlit* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["srcSubresource"], meta_struct.srcSubresource, options);
        FieldToJson(jdata["srcOffsets"], meta_struct.srcOffsets, options);
        FieldToJson(jdata["dstSubresource"], meta_struct.dstSubresource, options);
        FieldToJson(jdata["dstOffsets"], meta_struct.dstOffsets, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageCopy* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["srcSubresource"], meta_struct.srcSubresource, options);
        FieldToJson(jdata["srcOffset"], meta_struct.srcOffset, options);
        FieldToJson(jdata["dstSubresource"], meta_struct.dstSubresource, options);
        FieldToJson(jdata["dstOffset"], meta_struct.dstOffset, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageResolve* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["srcSubresource"], meta_struct.srcSubresource, options);
        FieldToJson(jdata["srcOffset"], meta_struct.srcOffset, options);
        FieldToJson(jdata["dstSubresource"], meta_struct.dstSubresource, options);
        FieldToJson(jdata["dstOffset"], meta_struct.dstOffset, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["renderPass"], to_hex(meta_struct.renderPass), options);
        FieldToJson(jdata["framebuffer"], to_hex(meta_struct.framebuffer), options);
        FieldToJson(jdata["renderArea"], meta_struct.renderArea, options);
        FieldToJson(jdata["clearValueCount"], decoded_value.clearValueCount, options);
        FieldToJson(jdata["pClearValues"], meta_struct.pClearValues, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSubgroupProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["subgroupSize"], decoded_value.subgroupSize, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["supportedStages"], decoded_value.supportedStages, options);
        FieldToJson(VkSubgroupFeatureFlags_t(),jdata["supportedOperations"], decoded_value.supportedOperations, options);
        FieldToJson(jdata["quadOperationsInAllStages"], decoded_value.quadOperationsInAllStages, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindBufferMemoryInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["memoryOffset"], decoded_value.memoryOffset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindImageMemoryInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["image"], to_hex(meta_struct.image), options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["memoryOffset"], decoded_value.memoryOffset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevice16BitStorageFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["storageBuffer16BitAccess"], decoded_value.storageBuffer16BitAccess, options);
        FieldToJson(jdata["uniformAndStorageBuffer16BitAccess"], decoded_value.uniformAndStorageBuffer16BitAccess, options);
        FieldToJson(jdata["storagePushConstant16"], decoded_value.storagePushConstant16, options);
        FieldToJson(jdata["storageInputOutput16"], decoded_value.storageInputOutput16, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryDedicatedRequirements* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["prefersDedicatedAllocation"], decoded_value.prefersDedicatedAllocation, options);
        FieldToJson(jdata["requiresDedicatedAllocation"], decoded_value.requiresDedicatedAllocation, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryDedicatedAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["image"], to_hex(meta_struct.image), options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryAllocateFlagsInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkMemoryAllocateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["deviceMask"], decoded_value.deviceMask, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupRenderPassBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceMask"], decoded_value.deviceMask, options);
        FieldToJson(jdata["deviceRenderAreaCount"], decoded_value.deviceRenderAreaCount, options);
        FieldToJson(jdata["pDeviceRenderAreas"], meta_struct.pDeviceRenderAreas, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupCommandBufferBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceMask"], decoded_value.deviceMask, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["waitSemaphoreCount"], decoded_value.waitSemaphoreCount, options);
        FieldToJson(jdata["pWaitSemaphoreDeviceIndices"], meta_struct.pWaitSemaphoreDeviceIndices, options);
        FieldToJson(jdata["commandBufferCount"], decoded_value.commandBufferCount, options);
        FieldToJson(jdata["pCommandBufferDeviceMasks"], meta_struct.pCommandBufferDeviceMasks, options);
        FieldToJson(jdata["signalSemaphoreCount"], decoded_value.signalSemaphoreCount, options);
        FieldToJson(jdata["pSignalSemaphoreDeviceIndices"], meta_struct.pSignalSemaphoreDeviceIndices, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupBindSparseInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["resourceDeviceIndex"], decoded_value.resourceDeviceIndex, options);
        FieldToJson(jdata["memoryDeviceIndex"], decoded_value.memoryDeviceIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindBufferMemoryDeviceGroupInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceIndexCount"], decoded_value.deviceIndexCount, options);
        FieldToJson(jdata["pDeviceIndices"], meta_struct.pDeviceIndices, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindImageMemoryDeviceGroupInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceIndexCount"], decoded_value.deviceIndexCount, options);
        FieldToJson(jdata["pDeviceIndices"], meta_struct.pDeviceIndices, options);
        FieldToJson(jdata["splitInstanceBindRegionCount"], decoded_value.splitInstanceBindRegionCount, options);
        FieldToJson(jdata["pSplitInstanceBindRegions"], meta_struct.pSplitInstanceBindRegions, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceGroupProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["physicalDeviceCount"], decoded_value.physicalDeviceCount, options);
        FieldToJson(jdata["physicalDevices"], &meta_struct.physicalDevices, options);
        FieldToJson(jdata["subsetAllocation"], decoded_value.subsetAllocation, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupDeviceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["physicalDeviceCount"], decoded_value.physicalDeviceCount, options);
        FieldToJson(jdata["pPhysicalDevices"], &meta_struct.pPhysicalDevices, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferMemoryRequirementsInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageMemoryRequirementsInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["image"], to_hex(meta_struct.image), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSparseMemoryRequirementsInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["image"], to_hex(meta_struct.image), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryRequirements2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memoryRequirements"], meta_struct.memoryRequirements, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageMemoryRequirements2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memoryRequirements"], meta_struct.memoryRequirements, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFeatures2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["features"], meta_struct.features, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["properties"], meta_struct.properties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFormatProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["formatProperties"], meta_struct.formatProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageFormatProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageFormatProperties"], meta_struct.imageFormatProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageFormatInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["tiling"], decoded_value.tiling, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["usage"], decoded_value.usage, options);
        FieldToJson(VkImageCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["queueFamilyProperties"], meta_struct.queueFamilyProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMemoryProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memoryProperties"], meta_struct.memoryProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageFormatProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["properties"], meta_struct.properties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSparseImageFormatInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["samples"], decoded_value.samples, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["usage"], decoded_value.usage, options);
        FieldToJson(jdata["tiling"], decoded_value.tiling, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePointClippingProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pointClippingBehavior"], decoded_value.pointClippingBehavior, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkInputAttachmentAspectReference* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["subpass"], decoded_value.subpass, options);
        FieldToJson(jdata["inputAttachmentIndex"], decoded_value.inputAttachmentIndex, options);
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], decoded_value.aspectMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassInputAttachmentAspectCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["aspectReferenceCount"], decoded_value.aspectReferenceCount, options);
        FieldToJson(jdata["pAspectReferences"], meta_struct.pAspectReferences, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewUsageCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["usage"], decoded_value.usage, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["domainOrigin"], decoded_value.domainOrigin, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassMultiviewCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["subpassCount"], decoded_value.subpassCount, options);
        FieldToJson(jdata["pViewMasks"], meta_struct.pViewMasks, options);
        FieldToJson(jdata["dependencyCount"], decoded_value.dependencyCount, options);
        FieldToJson(jdata["pViewOffsets"], meta_struct.pViewOffsets, options);
        FieldToJson(jdata["correlationMaskCount"], decoded_value.correlationMaskCount, options);
        FieldToJson(jdata["pCorrelationMasks"], meta_struct.pCorrelationMasks, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiviewFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["multiview"], decoded_value.multiview, options);
        FieldToJson(jdata["multiviewGeometryShader"], decoded_value.multiviewGeometryShader, options);
        FieldToJson(jdata["multiviewTessellationShader"], decoded_value.multiviewTessellationShader, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiviewProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxMultiviewViewCount"], decoded_value.maxMultiviewViewCount, options);
        FieldToJson(jdata["maxMultiviewInstanceIndex"], decoded_value.maxMultiviewInstanceIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVariablePointersFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["variablePointersStorageBuffer"], decoded_value.variablePointersStorageBuffer, options);
        FieldToJson(jdata["variablePointers"], decoded_value.variablePointers, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProtectedMemoryFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["protectedMemory"], decoded_value.protectedMemory, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProtectedMemoryProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["protectedNoFault"], decoded_value.protectedNoFault, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceQueueInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDeviceQueueCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["queueFamilyIndex"], decoded_value.queueFamilyIndex, options);
        FieldToJson(jdata["queueIndex"], decoded_value.queueIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkProtectedSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["protectedSubmit"], decoded_value.protectedSubmit, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerYcbcrConversionCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["ycbcrModel"], decoded_value.ycbcrModel, options);
        FieldToJson(jdata["ycbcrRange"], decoded_value.ycbcrRange, options);
        FieldToJson(jdata["components"], meta_struct.components, options);
        FieldToJson(jdata["xChromaOffset"], decoded_value.xChromaOffset, options);
        FieldToJson(jdata["yChromaOffset"], decoded_value.yChromaOffset, options);
        FieldToJson(jdata["chromaFilter"], decoded_value.chromaFilter, options);
        FieldToJson(jdata["forceExplicitReconstruction"], decoded_value.forceExplicitReconstruction, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerYcbcrConversionInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["conversion"], to_hex(meta_struct.conversion), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindImagePlaneMemoryInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["planeAspect"], decoded_value.planeAspect, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImagePlaneMemoryRequirementsInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["planeAspect"], decoded_value.planeAspect, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["samplerYcbcrConversion"], decoded_value.samplerYcbcrConversion, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerYcbcrConversionImageFormatProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["combinedImageSamplerDescriptorCount"], decoded_value.combinedImageSamplerDescriptorCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorUpdateTemplateEntry* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["dstBinding"], decoded_value.dstBinding, options);
        FieldToJson(jdata["dstArrayElement"], decoded_value.dstArrayElement, options);
        FieldToJson(jdata["descriptorCount"], decoded_value.descriptorCount, options);
        FieldToJson(jdata["descriptorType"], decoded_value.descriptorType, options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["stride"], decoded_value.stride, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorUpdateTemplateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDescriptorUpdateTemplateCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["descriptorUpdateEntryCount"], decoded_value.descriptorUpdateEntryCount, options);
        FieldToJson(jdata["pDescriptorUpdateEntries"], meta_struct.pDescriptorUpdateEntries, options);
        FieldToJson(jdata["templateType"], decoded_value.templateType, options);
        FieldToJson(jdata["descriptorSetLayout"], to_hex(meta_struct.descriptorSetLayout), options);
        FieldToJson(jdata["pipelineBindPoint"], decoded_value.pipelineBindPoint, options);
        FieldToJson(jdata["pipelineLayout"], to_hex(meta_struct.pipelineLayout), options);
        FieldToJson(jdata["set"], decoded_value.set, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalMemoryProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkExternalMemoryFeatureFlags_t(),jdata["externalMemoryFeatures"], decoded_value.externalMemoryFeatures, options);
        FieldToJson(VkExternalMemoryHandleTypeFlags_t(),jdata["exportFromImportedHandleTypes"], decoded_value.exportFromImportedHandleTypes, options);
        FieldToJson(VkExternalMemoryHandleTypeFlags_t(),jdata["compatibleHandleTypes"], decoded_value.compatibleHandleTypes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalImageFormatInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalImageFormatProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["externalMemoryProperties"], meta_struct.externalMemoryProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalBufferInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkBufferCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(VkBufferUsageFlags_t(),jdata["usage"], decoded_value.usage, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalBufferProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["externalMemoryProperties"], meta_struct.externalMemoryProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceIDProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceUUID"], uuid_to_string(sizeof(decoded_value.deviceUUID), decoded_value.deviceUUID), options);
        FieldToJson(jdata["driverUUID"], uuid_to_string(sizeof(decoded_value.driverUUID), decoded_value.driverUUID), options);
        FieldToJson(jdata["deviceLUID"], uuid_to_string(sizeof(decoded_value.deviceLUID), decoded_value.deviceLUID), options);
        FieldToJson(jdata["deviceNodeMask"], decoded_value.deviceNodeMask, options);
        FieldToJson(jdata["deviceLUIDValid"], decoded_value.deviceLUIDValid, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalMemoryImageCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlags_t(),jdata["handleTypes"], decoded_value.handleTypes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalMemoryBufferCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlags_t(),jdata["handleTypes"], decoded_value.handleTypes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportMemoryAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlags_t(),jdata["handleTypes"], decoded_value.handleTypes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalFenceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalFenceProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkExternalFenceHandleTypeFlags_t(),jdata["exportFromImportedHandleTypes"], decoded_value.exportFromImportedHandleTypes, options);
        FieldToJson(VkExternalFenceHandleTypeFlags_t(),jdata["compatibleHandleTypes"], decoded_value.compatibleHandleTypes, options);
        FieldToJson(VkExternalFenceFeatureFlags_t(),jdata["externalFenceFeatures"], decoded_value.externalFenceFeatures, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportFenceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkExternalFenceHandleTypeFlags_t(),jdata["handleTypes"], decoded_value.handleTypes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportSemaphoreCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkExternalSemaphoreHandleTypeFlags_t(),jdata["handleTypes"], decoded_value.handleTypes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalSemaphoreInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalSemaphoreProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkExternalSemaphoreHandleTypeFlags_t(),jdata["exportFromImportedHandleTypes"], decoded_value.exportFromImportedHandleTypes, options);
        FieldToJson(VkExternalSemaphoreHandleTypeFlags_t(),jdata["compatibleHandleTypes"], decoded_value.compatibleHandleTypes, options);
        FieldToJson(VkExternalSemaphoreFeatureFlags_t(),jdata["externalSemaphoreFeatures"], decoded_value.externalSemaphoreFeatures, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance3Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxPerSetDescriptors"], decoded_value.maxPerSetDescriptors, options);
        FieldToJson(jdata["maxMemoryAllocationSize"], decoded_value.maxMemoryAllocationSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetLayoutSupport* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["supported"], decoded_value.supported, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderDrawParametersFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderDrawParameters"], decoded_value.shaderDrawParameters, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan11Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["storageBuffer16BitAccess"], decoded_value.storageBuffer16BitAccess, options);
        FieldToJson(jdata["uniformAndStorageBuffer16BitAccess"], decoded_value.uniformAndStorageBuffer16BitAccess, options);
        FieldToJson(jdata["storagePushConstant16"], decoded_value.storagePushConstant16, options);
        FieldToJson(jdata["storageInputOutput16"], decoded_value.storageInputOutput16, options);
        FieldToJson(jdata["multiview"], decoded_value.multiview, options);
        FieldToJson(jdata["multiviewGeometryShader"], decoded_value.multiviewGeometryShader, options);
        FieldToJson(jdata["multiviewTessellationShader"], decoded_value.multiviewTessellationShader, options);
        FieldToJson(jdata["variablePointersStorageBuffer"], decoded_value.variablePointersStorageBuffer, options);
        FieldToJson(jdata["variablePointers"], decoded_value.variablePointers, options);
        FieldToJson(jdata["protectedMemory"], decoded_value.protectedMemory, options);
        FieldToJson(jdata["samplerYcbcrConversion"], decoded_value.samplerYcbcrConversion, options);
        FieldToJson(jdata["shaderDrawParameters"], decoded_value.shaderDrawParameters, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan11Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceUUID"], uuid_to_string(sizeof(decoded_value.deviceUUID), decoded_value.deviceUUID), options);
        FieldToJson(jdata["driverUUID"], uuid_to_string(sizeof(decoded_value.driverUUID), decoded_value.driverUUID), options);
        FieldToJson(jdata["deviceLUID"], uuid_to_string(sizeof(decoded_value.deviceLUID), decoded_value.deviceLUID), options);
        FieldToJson(jdata["deviceNodeMask"], decoded_value.deviceNodeMask, options);
        FieldToJson(jdata["deviceLUIDValid"], decoded_value.deviceLUIDValid, options);
        FieldToJson(jdata["subgroupSize"], decoded_value.subgroupSize, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["subgroupSupportedStages"], decoded_value.subgroupSupportedStages, options);
        FieldToJson(VkSubgroupFeatureFlags_t(),jdata["subgroupSupportedOperations"], decoded_value.subgroupSupportedOperations, options);
        FieldToJson(jdata["subgroupQuadOperationsInAllStages"], decoded_value.subgroupQuadOperationsInAllStages, options);
        FieldToJson(jdata["pointClippingBehavior"], decoded_value.pointClippingBehavior, options);
        FieldToJson(jdata["maxMultiviewViewCount"], decoded_value.maxMultiviewViewCount, options);
        FieldToJson(jdata["maxMultiviewInstanceIndex"], decoded_value.maxMultiviewInstanceIndex, options);
        FieldToJson(jdata["protectedNoFault"], decoded_value.protectedNoFault, options);
        FieldToJson(jdata["maxPerSetDescriptors"], decoded_value.maxPerSetDescriptors, options);
        FieldToJson(jdata["maxMemoryAllocationSize"], decoded_value.maxMemoryAllocationSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan12Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["samplerMirrorClampToEdge"], decoded_value.samplerMirrorClampToEdge, options);
        FieldToJson(jdata["drawIndirectCount"], decoded_value.drawIndirectCount, options);
        FieldToJson(jdata["storageBuffer8BitAccess"], decoded_value.storageBuffer8BitAccess, options);
        FieldToJson(jdata["uniformAndStorageBuffer8BitAccess"], decoded_value.uniformAndStorageBuffer8BitAccess, options);
        FieldToJson(jdata["storagePushConstant8"], decoded_value.storagePushConstant8, options);
        FieldToJson(jdata["shaderBufferInt64Atomics"], decoded_value.shaderBufferInt64Atomics, options);
        FieldToJson(jdata["shaderSharedInt64Atomics"], decoded_value.shaderSharedInt64Atomics, options);
        FieldToJson(jdata["shaderFloat16"], decoded_value.shaderFloat16, options);
        FieldToJson(jdata["shaderInt8"], decoded_value.shaderInt8, options);
        FieldToJson(jdata["descriptorIndexing"], decoded_value.descriptorIndexing, options);
        FieldToJson(jdata["shaderInputAttachmentArrayDynamicIndexing"], decoded_value.shaderInputAttachmentArrayDynamicIndexing, options);
        FieldToJson(jdata["shaderUniformTexelBufferArrayDynamicIndexing"], decoded_value.shaderUniformTexelBufferArrayDynamicIndexing, options);
        FieldToJson(jdata["shaderStorageTexelBufferArrayDynamicIndexing"], decoded_value.shaderStorageTexelBufferArrayDynamicIndexing, options);
        FieldToJson(jdata["shaderUniformBufferArrayNonUniformIndexing"], decoded_value.shaderUniformBufferArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderSampledImageArrayNonUniformIndexing"], decoded_value.shaderSampledImageArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderStorageBufferArrayNonUniformIndexing"], decoded_value.shaderStorageBufferArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderStorageImageArrayNonUniformIndexing"], decoded_value.shaderStorageImageArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderInputAttachmentArrayNonUniformIndexing"], decoded_value.shaderInputAttachmentArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderUniformTexelBufferArrayNonUniformIndexing"], decoded_value.shaderUniformTexelBufferArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderStorageTexelBufferArrayNonUniformIndexing"], decoded_value.shaderStorageTexelBufferArrayNonUniformIndexing, options);
        FieldToJson(jdata["descriptorBindingUniformBufferUpdateAfterBind"], decoded_value.descriptorBindingUniformBufferUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingSampledImageUpdateAfterBind"], decoded_value.descriptorBindingSampledImageUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingStorageImageUpdateAfterBind"], decoded_value.descriptorBindingStorageImageUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingStorageBufferUpdateAfterBind"], decoded_value.descriptorBindingStorageBufferUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingUniformTexelBufferUpdateAfterBind"], decoded_value.descriptorBindingUniformTexelBufferUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingStorageTexelBufferUpdateAfterBind"], decoded_value.descriptorBindingStorageTexelBufferUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingUpdateUnusedWhilePending"], decoded_value.descriptorBindingUpdateUnusedWhilePending, options);
        FieldToJson(jdata["descriptorBindingPartiallyBound"], decoded_value.descriptorBindingPartiallyBound, options);
        FieldToJson(jdata["descriptorBindingVariableDescriptorCount"], decoded_value.descriptorBindingVariableDescriptorCount, options);
        FieldToJson(jdata["runtimeDescriptorArray"], decoded_value.runtimeDescriptorArray, options);
        FieldToJson(jdata["samplerFilterMinmax"], decoded_value.samplerFilterMinmax, options);
        FieldToJson(jdata["scalarBlockLayout"], decoded_value.scalarBlockLayout, options);
        FieldToJson(jdata["imagelessFramebuffer"], decoded_value.imagelessFramebuffer, options);
        FieldToJson(jdata["uniformBufferStandardLayout"], decoded_value.uniformBufferStandardLayout, options);
        FieldToJson(jdata["shaderSubgroupExtendedTypes"], decoded_value.shaderSubgroupExtendedTypes, options);
        FieldToJson(jdata["separateDepthStencilLayouts"], decoded_value.separateDepthStencilLayouts, options);
        FieldToJson(jdata["hostQueryReset"], decoded_value.hostQueryReset, options);
        FieldToJson(jdata["timelineSemaphore"], decoded_value.timelineSemaphore, options);
        FieldToJson(jdata["bufferDeviceAddress"], decoded_value.bufferDeviceAddress, options);
        FieldToJson(jdata["bufferDeviceAddressCaptureReplay"], decoded_value.bufferDeviceAddressCaptureReplay, options);
        FieldToJson(jdata["bufferDeviceAddressMultiDevice"], decoded_value.bufferDeviceAddressMultiDevice, options);
        FieldToJson(jdata["vulkanMemoryModel"], decoded_value.vulkanMemoryModel, options);
        FieldToJson(jdata["vulkanMemoryModelDeviceScope"], decoded_value.vulkanMemoryModelDeviceScope, options);
        FieldToJson(jdata["vulkanMemoryModelAvailabilityVisibilityChains"], decoded_value.vulkanMemoryModelAvailabilityVisibilityChains, options);
        FieldToJson(jdata["shaderOutputViewportIndex"], decoded_value.shaderOutputViewportIndex, options);
        FieldToJson(jdata["shaderOutputLayer"], decoded_value.shaderOutputLayer, options);
        FieldToJson(jdata["subgroupBroadcastDynamicId"], decoded_value.subgroupBroadcastDynamicId, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkConformanceVersion* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["major"], decoded_value.major, options);
        FieldToJson(jdata["minor"], decoded_value.minor, options);
        FieldToJson(jdata["subminor"], decoded_value.subminor, options);
        FieldToJson(jdata["patch"], decoded_value.patch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan12Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["driverID"], decoded_value.driverID, options);
        FieldToJson(jdata["driverName"], &meta_struct.driverName, options);
        FieldToJson(jdata["driverInfo"], &meta_struct.driverInfo, options);
        FieldToJson(jdata["conformanceVersion"], meta_struct.conformanceVersion, options);
        FieldToJson(jdata["denormBehaviorIndependence"], decoded_value.denormBehaviorIndependence, options);
        FieldToJson(jdata["roundingModeIndependence"], decoded_value.roundingModeIndependence, options);
        FieldToJson(jdata["shaderSignedZeroInfNanPreserveFloat16"], decoded_value.shaderSignedZeroInfNanPreserveFloat16, options);
        FieldToJson(jdata["shaderSignedZeroInfNanPreserveFloat32"], decoded_value.shaderSignedZeroInfNanPreserveFloat32, options);
        FieldToJson(jdata["shaderSignedZeroInfNanPreserveFloat64"], decoded_value.shaderSignedZeroInfNanPreserveFloat64, options);
        FieldToJson(jdata["shaderDenormPreserveFloat16"], decoded_value.shaderDenormPreserveFloat16, options);
        FieldToJson(jdata["shaderDenormPreserveFloat32"], decoded_value.shaderDenormPreserveFloat32, options);
        FieldToJson(jdata["shaderDenormPreserveFloat64"], decoded_value.shaderDenormPreserveFloat64, options);
        FieldToJson(jdata["shaderDenormFlushToZeroFloat16"], decoded_value.shaderDenormFlushToZeroFloat16, options);
        FieldToJson(jdata["shaderDenormFlushToZeroFloat32"], decoded_value.shaderDenormFlushToZeroFloat32, options);
        FieldToJson(jdata["shaderDenormFlushToZeroFloat64"], decoded_value.shaderDenormFlushToZeroFloat64, options);
        FieldToJson(jdata["shaderRoundingModeRTEFloat16"], decoded_value.shaderRoundingModeRTEFloat16, options);
        FieldToJson(jdata["shaderRoundingModeRTEFloat32"], decoded_value.shaderRoundingModeRTEFloat32, options);
        FieldToJson(jdata["shaderRoundingModeRTEFloat64"], decoded_value.shaderRoundingModeRTEFloat64, options);
        FieldToJson(jdata["shaderRoundingModeRTZFloat16"], decoded_value.shaderRoundingModeRTZFloat16, options);
        FieldToJson(jdata["shaderRoundingModeRTZFloat32"], decoded_value.shaderRoundingModeRTZFloat32, options);
        FieldToJson(jdata["shaderRoundingModeRTZFloat64"], decoded_value.shaderRoundingModeRTZFloat64, options);
        FieldToJson(jdata["maxUpdateAfterBindDescriptorsInAllPools"], decoded_value.maxUpdateAfterBindDescriptorsInAllPools, options);
        FieldToJson(jdata["shaderUniformBufferArrayNonUniformIndexingNative"], decoded_value.shaderUniformBufferArrayNonUniformIndexingNative, options);
        FieldToJson(jdata["shaderSampledImageArrayNonUniformIndexingNative"], decoded_value.shaderSampledImageArrayNonUniformIndexingNative, options);
        FieldToJson(jdata["shaderStorageBufferArrayNonUniformIndexingNative"], decoded_value.shaderStorageBufferArrayNonUniformIndexingNative, options);
        FieldToJson(jdata["shaderStorageImageArrayNonUniformIndexingNative"], decoded_value.shaderStorageImageArrayNonUniformIndexingNative, options);
        FieldToJson(jdata["shaderInputAttachmentArrayNonUniformIndexingNative"], decoded_value.shaderInputAttachmentArrayNonUniformIndexingNative, options);
        FieldToJson(jdata["robustBufferAccessUpdateAfterBind"], decoded_value.robustBufferAccessUpdateAfterBind, options);
        FieldToJson(jdata["quadDivergentImplicitLod"], decoded_value.quadDivergentImplicitLod, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindSamplers"], decoded_value.maxPerStageDescriptorUpdateAfterBindSamplers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindUniformBuffers"], decoded_value.maxPerStageDescriptorUpdateAfterBindUniformBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindStorageBuffers"], decoded_value.maxPerStageDescriptorUpdateAfterBindStorageBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindSampledImages"], decoded_value.maxPerStageDescriptorUpdateAfterBindSampledImages, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindStorageImages"], decoded_value.maxPerStageDescriptorUpdateAfterBindStorageImages, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindInputAttachments"], decoded_value.maxPerStageDescriptorUpdateAfterBindInputAttachments, options);
        FieldToJson(jdata["maxPerStageUpdateAfterBindResources"], decoded_value.maxPerStageUpdateAfterBindResources, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindSamplers"], decoded_value.maxDescriptorSetUpdateAfterBindSamplers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindUniformBuffers"], decoded_value.maxDescriptorSetUpdateAfterBindUniformBuffers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindUniformBuffersDynamic"], decoded_value.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageBuffers"], decoded_value.maxDescriptorSetUpdateAfterBindStorageBuffers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageBuffersDynamic"], decoded_value.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindSampledImages"], decoded_value.maxDescriptorSetUpdateAfterBindSampledImages, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageImages"], decoded_value.maxDescriptorSetUpdateAfterBindStorageImages, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindInputAttachments"], decoded_value.maxDescriptorSetUpdateAfterBindInputAttachments, options);
        FieldToJson(VkResolveModeFlags_t(),jdata["supportedDepthResolveModes"], decoded_value.supportedDepthResolveModes, options);
        FieldToJson(VkResolveModeFlags_t(),jdata["supportedStencilResolveModes"], decoded_value.supportedStencilResolveModes, options);
        FieldToJson(jdata["independentResolveNone"], decoded_value.independentResolveNone, options);
        FieldToJson(jdata["independentResolve"], decoded_value.independentResolve, options);
        FieldToJson(jdata["filterMinmaxSingleComponentFormats"], decoded_value.filterMinmaxSingleComponentFormats, options);
        FieldToJson(jdata["filterMinmaxImageComponentMapping"], decoded_value.filterMinmaxImageComponentMapping, options);
        FieldToJson(jdata["maxTimelineSemaphoreValueDifference"], decoded_value.maxTimelineSemaphoreValueDifference, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["framebufferIntegerColorSampleCounts"], decoded_value.framebufferIntegerColorSampleCounts, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageFormatListCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["viewFormatCount"], decoded_value.viewFormatCount, options);
        FieldToJson(jdata["pViewFormats"], meta_struct.pViewFormats, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentDescription2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkAttachmentDescriptionFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["samples"], decoded_value.samples, options);
        FieldToJson(jdata["loadOp"], decoded_value.loadOp, options);
        FieldToJson(jdata["storeOp"], decoded_value.storeOp, options);
        FieldToJson(jdata["stencilLoadOp"], decoded_value.stencilLoadOp, options);
        FieldToJson(jdata["stencilStoreOp"], decoded_value.stencilStoreOp, options);
        FieldToJson(jdata["initialLayout"], decoded_value.initialLayout, options);
        FieldToJson(jdata["finalLayout"], decoded_value.finalLayout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentReference2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["attachment"], decoded_value.attachment, options);
        FieldToJson(jdata["layout"], decoded_value.layout, options);
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], decoded_value.aspectMask, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassDescription2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkSubpassDescriptionFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pipelineBindPoint"], decoded_value.pipelineBindPoint, options);
        FieldToJson(jdata["viewMask"], decoded_value.viewMask, options);
        FieldToJson(jdata["inputAttachmentCount"], decoded_value.inputAttachmentCount, options);
        FieldToJson(jdata["pInputAttachments"], meta_struct.pInputAttachments, options);
        FieldToJson(jdata["colorAttachmentCount"], decoded_value.colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachments"], meta_struct.pColorAttachments, options);
        FieldToJson(jdata["pResolveAttachments"], meta_struct.pResolveAttachments, options);
        FieldToJson(jdata["pDepthStencilAttachment"], meta_struct.pDepthStencilAttachment, options);
        FieldToJson(jdata["preserveAttachmentCount"], decoded_value.preserveAttachmentCount, options);
        FieldToJson(jdata["pPreserveAttachments"], meta_struct.pPreserveAttachments, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassDependency2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcSubpass"], decoded_value.srcSubpass, options);
        FieldToJson(jdata["dstSubpass"], decoded_value.dstSubpass, options);
        FieldToJson(VkPipelineStageFlags_t(),jdata["srcStageMask"], decoded_value.srcStageMask, options);
        FieldToJson(VkPipelineStageFlags_t(),jdata["dstStageMask"], decoded_value.dstStageMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["srcAccessMask"], decoded_value.srcAccessMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["dstAccessMask"], decoded_value.dstAccessMask, options);
        FieldToJson(VkDependencyFlags_t(),jdata["dependencyFlags"], decoded_value.dependencyFlags, options);
        FieldToJson(jdata["viewOffset"], decoded_value.viewOffset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassCreateInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkRenderPassCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["attachmentCount"], decoded_value.attachmentCount, options);
        FieldToJson(jdata["pAttachments"], meta_struct.pAttachments, options);
        FieldToJson(jdata["subpassCount"], decoded_value.subpassCount, options);
        FieldToJson(jdata["pSubpasses"], meta_struct.pSubpasses, options);
        FieldToJson(jdata["dependencyCount"], decoded_value.dependencyCount, options);
        FieldToJson(jdata["pDependencies"], meta_struct.pDependencies, options);
        FieldToJson(jdata["correlatedViewMaskCount"], decoded_value.correlatedViewMaskCount, options);
        FieldToJson(jdata["pCorrelatedViewMasks"], meta_struct.pCorrelatedViewMasks, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["contents"], decoded_value.contents, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassEndInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevice8BitStorageFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["storageBuffer8BitAccess"], decoded_value.storageBuffer8BitAccess, options);
        FieldToJson(jdata["uniformAndStorageBuffer8BitAccess"], decoded_value.uniformAndStorageBuffer8BitAccess, options);
        FieldToJson(jdata["storagePushConstant8"], decoded_value.storagePushConstant8, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDriverProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["driverID"], decoded_value.driverID, options);
        FieldToJson(jdata["driverName"], &meta_struct.driverName, options);
        FieldToJson(jdata["driverInfo"], &meta_struct.driverInfo, options);
        FieldToJson(jdata["conformanceVersion"], meta_struct.conformanceVersion, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderAtomicInt64Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderBufferInt64Atomics"], decoded_value.shaderBufferInt64Atomics, options);
        FieldToJson(jdata["shaderSharedInt64Atomics"], decoded_value.shaderSharedInt64Atomics, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderFloat16Int8Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderFloat16"], decoded_value.shaderFloat16, options);
        FieldToJson(jdata["shaderInt8"], decoded_value.shaderInt8, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFloatControlsProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["denormBehaviorIndependence"], decoded_value.denormBehaviorIndependence, options);
        FieldToJson(jdata["roundingModeIndependence"], decoded_value.roundingModeIndependence, options);
        FieldToJson(jdata["shaderSignedZeroInfNanPreserveFloat16"], decoded_value.shaderSignedZeroInfNanPreserveFloat16, options);
        FieldToJson(jdata["shaderSignedZeroInfNanPreserveFloat32"], decoded_value.shaderSignedZeroInfNanPreserveFloat32, options);
        FieldToJson(jdata["shaderSignedZeroInfNanPreserveFloat64"], decoded_value.shaderSignedZeroInfNanPreserveFloat64, options);
        FieldToJson(jdata["shaderDenormPreserveFloat16"], decoded_value.shaderDenormPreserveFloat16, options);
        FieldToJson(jdata["shaderDenormPreserveFloat32"], decoded_value.shaderDenormPreserveFloat32, options);
        FieldToJson(jdata["shaderDenormPreserveFloat64"], decoded_value.shaderDenormPreserveFloat64, options);
        FieldToJson(jdata["shaderDenormFlushToZeroFloat16"], decoded_value.shaderDenormFlushToZeroFloat16, options);
        FieldToJson(jdata["shaderDenormFlushToZeroFloat32"], decoded_value.shaderDenormFlushToZeroFloat32, options);
        FieldToJson(jdata["shaderDenormFlushToZeroFloat64"], decoded_value.shaderDenormFlushToZeroFloat64, options);
        FieldToJson(jdata["shaderRoundingModeRTEFloat16"], decoded_value.shaderRoundingModeRTEFloat16, options);
        FieldToJson(jdata["shaderRoundingModeRTEFloat32"], decoded_value.shaderRoundingModeRTEFloat32, options);
        FieldToJson(jdata["shaderRoundingModeRTEFloat64"], decoded_value.shaderRoundingModeRTEFloat64, options);
        FieldToJson(jdata["shaderRoundingModeRTZFloat16"], decoded_value.shaderRoundingModeRTZFloat16, options);
        FieldToJson(jdata["shaderRoundingModeRTZFloat32"], decoded_value.shaderRoundingModeRTZFloat32, options);
        FieldToJson(jdata["shaderRoundingModeRTZFloat64"], decoded_value.shaderRoundingModeRTZFloat64, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["bindingCount"], decoded_value.bindingCount, options);
        FieldToJson(jdata["pBindingFlags"], meta_struct.pBindingFlags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDescriptorIndexingFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderInputAttachmentArrayDynamicIndexing"], decoded_value.shaderInputAttachmentArrayDynamicIndexing, options);
        FieldToJson(jdata["shaderUniformTexelBufferArrayDynamicIndexing"], decoded_value.shaderUniformTexelBufferArrayDynamicIndexing, options);
        FieldToJson(jdata["shaderStorageTexelBufferArrayDynamicIndexing"], decoded_value.shaderStorageTexelBufferArrayDynamicIndexing, options);
        FieldToJson(jdata["shaderUniformBufferArrayNonUniformIndexing"], decoded_value.shaderUniformBufferArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderSampledImageArrayNonUniformIndexing"], decoded_value.shaderSampledImageArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderStorageBufferArrayNonUniformIndexing"], decoded_value.shaderStorageBufferArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderStorageImageArrayNonUniformIndexing"], decoded_value.shaderStorageImageArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderInputAttachmentArrayNonUniformIndexing"], decoded_value.shaderInputAttachmentArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderUniformTexelBufferArrayNonUniformIndexing"], decoded_value.shaderUniformTexelBufferArrayNonUniformIndexing, options);
        FieldToJson(jdata["shaderStorageTexelBufferArrayNonUniformIndexing"], decoded_value.shaderStorageTexelBufferArrayNonUniformIndexing, options);
        FieldToJson(jdata["descriptorBindingUniformBufferUpdateAfterBind"], decoded_value.descriptorBindingUniformBufferUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingSampledImageUpdateAfterBind"], decoded_value.descriptorBindingSampledImageUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingStorageImageUpdateAfterBind"], decoded_value.descriptorBindingStorageImageUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingStorageBufferUpdateAfterBind"], decoded_value.descriptorBindingStorageBufferUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingUniformTexelBufferUpdateAfterBind"], decoded_value.descriptorBindingUniformTexelBufferUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingStorageTexelBufferUpdateAfterBind"], decoded_value.descriptorBindingStorageTexelBufferUpdateAfterBind, options);
        FieldToJson(jdata["descriptorBindingUpdateUnusedWhilePending"], decoded_value.descriptorBindingUpdateUnusedWhilePending, options);
        FieldToJson(jdata["descriptorBindingPartiallyBound"], decoded_value.descriptorBindingPartiallyBound, options);
        FieldToJson(jdata["descriptorBindingVariableDescriptorCount"], decoded_value.descriptorBindingVariableDescriptorCount, options);
        FieldToJson(jdata["runtimeDescriptorArray"], decoded_value.runtimeDescriptorArray, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDescriptorIndexingProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxUpdateAfterBindDescriptorsInAllPools"], decoded_value.maxUpdateAfterBindDescriptorsInAllPools, options);
        FieldToJson(jdata["shaderUniformBufferArrayNonUniformIndexingNative"], decoded_value.shaderUniformBufferArrayNonUniformIndexingNative, options);
        FieldToJson(jdata["shaderSampledImageArrayNonUniformIndexingNative"], decoded_value.shaderSampledImageArrayNonUniformIndexingNative, options);
        FieldToJson(jdata["shaderStorageBufferArrayNonUniformIndexingNative"], decoded_value.shaderStorageBufferArrayNonUniformIndexingNative, options);
        FieldToJson(jdata["shaderStorageImageArrayNonUniformIndexingNative"], decoded_value.shaderStorageImageArrayNonUniformIndexingNative, options);
        FieldToJson(jdata["shaderInputAttachmentArrayNonUniformIndexingNative"], decoded_value.shaderInputAttachmentArrayNonUniformIndexingNative, options);
        FieldToJson(jdata["robustBufferAccessUpdateAfterBind"], decoded_value.robustBufferAccessUpdateAfterBind, options);
        FieldToJson(jdata["quadDivergentImplicitLod"], decoded_value.quadDivergentImplicitLod, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindSamplers"], decoded_value.maxPerStageDescriptorUpdateAfterBindSamplers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindUniformBuffers"], decoded_value.maxPerStageDescriptorUpdateAfterBindUniformBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindStorageBuffers"], decoded_value.maxPerStageDescriptorUpdateAfterBindStorageBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindSampledImages"], decoded_value.maxPerStageDescriptorUpdateAfterBindSampledImages, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindStorageImages"], decoded_value.maxPerStageDescriptorUpdateAfterBindStorageImages, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindInputAttachments"], decoded_value.maxPerStageDescriptorUpdateAfterBindInputAttachments, options);
        FieldToJson(jdata["maxPerStageUpdateAfterBindResources"], decoded_value.maxPerStageUpdateAfterBindResources, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindSamplers"], decoded_value.maxDescriptorSetUpdateAfterBindSamplers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindUniformBuffers"], decoded_value.maxDescriptorSetUpdateAfterBindUniformBuffers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindUniformBuffersDynamic"], decoded_value.maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageBuffers"], decoded_value.maxDescriptorSetUpdateAfterBindStorageBuffers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageBuffersDynamic"], decoded_value.maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindSampledImages"], decoded_value.maxDescriptorSetUpdateAfterBindSampledImages, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageImages"], decoded_value.maxDescriptorSetUpdateAfterBindStorageImages, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindInputAttachments"], decoded_value.maxDescriptorSetUpdateAfterBindInputAttachments, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["descriptorSetCount"], decoded_value.descriptorSetCount, options);
        FieldToJson(jdata["pDescriptorCounts"], meta_struct.pDescriptorCounts, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxVariableDescriptorCount"], decoded_value.maxVariableDescriptorCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassDescriptionDepthStencilResolve* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["depthResolveMode"], decoded_value.depthResolveMode, options);
        FieldToJson(jdata["stencilResolveMode"], decoded_value.stencilResolveMode, options);
        FieldToJson(jdata["pDepthStencilResolveAttachment"], meta_struct.pDepthStencilResolveAttachment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDepthStencilResolveProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkResolveModeFlags_t(),jdata["supportedDepthResolveModes"], decoded_value.supportedDepthResolveModes, options);
        FieldToJson(VkResolveModeFlags_t(),jdata["supportedStencilResolveModes"], decoded_value.supportedStencilResolveModes, options);
        FieldToJson(jdata["independentResolveNone"], decoded_value.independentResolveNone, options);
        FieldToJson(jdata["independentResolve"], decoded_value.independentResolve, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["scalarBlockLayout"], decoded_value.scalarBlockLayout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageStencilUsageCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["stencilUsage"], decoded_value.stencilUsage, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerReductionModeCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["reductionMode"], decoded_value.reductionMode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["filterMinmaxSingleComponentFormats"], decoded_value.filterMinmaxSingleComponentFormats, options);
        FieldToJson(jdata["filterMinmaxImageComponentMapping"], decoded_value.filterMinmaxImageComponentMapping, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["vulkanMemoryModel"], decoded_value.vulkanMemoryModel, options);
        FieldToJson(jdata["vulkanMemoryModelDeviceScope"], decoded_value.vulkanMemoryModelDeviceScope, options);
        FieldToJson(jdata["vulkanMemoryModelAvailabilityVisibilityChains"], decoded_value.vulkanMemoryModelAvailabilityVisibilityChains, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImagelessFramebufferFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imagelessFramebuffer"], decoded_value.imagelessFramebuffer, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFramebufferAttachmentImageInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkImageCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["usage"], decoded_value.usage, options);
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["layerCount"], decoded_value.layerCount, options);
        FieldToJson(jdata["viewFormatCount"], decoded_value.viewFormatCount, options);
        FieldToJson(jdata["pViewFormats"], meta_struct.pViewFormats, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFramebufferAttachmentsCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["attachmentImageInfoCount"], decoded_value.attachmentImageInfoCount, options);
        FieldToJson(jdata["pAttachmentImageInfos"], meta_struct.pAttachmentImageInfos, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassAttachmentBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["attachmentCount"], decoded_value.attachmentCount, options);
        FieldToJson(jdata["pAttachments"], &meta_struct.pAttachments, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["uniformBufferStandardLayout"], decoded_value.uniformBufferStandardLayout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderSubgroupExtendedTypes"], decoded_value.shaderSubgroupExtendedTypes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["separateDepthStencilLayouts"], decoded_value.separateDepthStencilLayouts, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentReferenceStencilLayout* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stencilLayout"], decoded_value.stencilLayout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentDescriptionStencilLayout* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stencilInitialLayout"], decoded_value.stencilInitialLayout, options);
        FieldToJson(jdata["stencilFinalLayout"], decoded_value.stencilFinalLayout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceHostQueryResetFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["hostQueryReset"], decoded_value.hostQueryReset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["timelineSemaphore"], decoded_value.timelineSemaphore, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTimelineSemaphoreProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxTimelineSemaphoreValueDifference"], decoded_value.maxTimelineSemaphoreValueDifference, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreTypeCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["semaphoreType"], decoded_value.semaphoreType, options);
        FieldToJson(jdata["initialValue"], decoded_value.initialValue, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTimelineSemaphoreSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["waitSemaphoreValueCount"], decoded_value.waitSemaphoreValueCount, options);
        FieldToJson(jdata["pWaitSemaphoreValues"], meta_struct.pWaitSemaphoreValues, options);
        FieldToJson(jdata["signalSemaphoreValueCount"], decoded_value.signalSemaphoreValueCount, options);
        FieldToJson(jdata["pSignalSemaphoreValues"], meta_struct.pSignalSemaphoreValues, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreWaitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkSemaphoreWaitFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["semaphoreCount"], decoded_value.semaphoreCount, options);
        FieldToJson(jdata["pSemaphores"], &meta_struct.pSemaphores, options);
        FieldToJson(jdata["pValues"], meta_struct.pValues, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreSignalInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["semaphore"], to_hex(meta_struct.semaphore), options);
        FieldToJson(jdata["value"], decoded_value.value, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["bufferDeviceAddress"], decoded_value.bufferDeviceAddress, options);
        FieldToJson(jdata["bufferDeviceAddressCaptureReplay"], decoded_value.bufferDeviceAddressCaptureReplay, options);
        FieldToJson(jdata["bufferDeviceAddressMultiDevice"], decoded_value.bufferDeviceAddressMultiDevice, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferDeviceAddressInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferOpaqueCaptureAddressCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["opaqueCaptureAddress"], decoded_value.opaqueCaptureAddress, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["opaqueCaptureAddress"], decoded_value.opaqueCaptureAddress, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan13Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["robustImageAccess"], decoded_value.robustImageAccess, options);
        FieldToJson(jdata["inlineUniformBlock"], decoded_value.inlineUniformBlock, options);
        FieldToJson(jdata["descriptorBindingInlineUniformBlockUpdateAfterBind"], decoded_value.descriptorBindingInlineUniformBlockUpdateAfterBind, options);
        FieldToJson(jdata["pipelineCreationCacheControl"], decoded_value.pipelineCreationCacheControl, options);
        FieldToJson(jdata["privateData"], decoded_value.privateData, options);
        FieldToJson(jdata["shaderDemoteToHelperInvocation"], decoded_value.shaderDemoteToHelperInvocation, options);
        FieldToJson(jdata["shaderTerminateInvocation"], decoded_value.shaderTerminateInvocation, options);
        FieldToJson(jdata["subgroupSizeControl"], decoded_value.subgroupSizeControl, options);
        FieldToJson(jdata["computeFullSubgroups"], decoded_value.computeFullSubgroups, options);
        FieldToJson(jdata["synchronization2"], decoded_value.synchronization2, options);
        FieldToJson(jdata["textureCompressionASTC_HDR"], decoded_value.textureCompressionASTC_HDR, options);
        FieldToJson(jdata["shaderZeroInitializeWorkgroupMemory"], decoded_value.shaderZeroInitializeWorkgroupMemory, options);
        FieldToJson(jdata["dynamicRendering"], decoded_value.dynamicRendering, options);
        FieldToJson(jdata["shaderIntegerDotProduct"], decoded_value.shaderIntegerDotProduct, options);
        FieldToJson(jdata["maintenance4"], decoded_value.maintenance4, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan13Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["minSubgroupSize"], decoded_value.minSubgroupSize, options);
        FieldToJson(jdata["maxSubgroupSize"], decoded_value.maxSubgroupSize, options);
        FieldToJson(jdata["maxComputeWorkgroupSubgroups"], decoded_value.maxComputeWorkgroupSubgroups, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["requiredSubgroupSizeStages"], decoded_value.requiredSubgroupSizeStages, options);
        FieldToJson(jdata["maxInlineUniformBlockSize"], decoded_value.maxInlineUniformBlockSize, options);
        FieldToJson(jdata["maxPerStageDescriptorInlineUniformBlocks"], decoded_value.maxPerStageDescriptorInlineUniformBlocks, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks"], decoded_value.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, options);
        FieldToJson(jdata["maxDescriptorSetInlineUniformBlocks"], decoded_value.maxDescriptorSetInlineUniformBlocks, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindInlineUniformBlocks"], decoded_value.maxDescriptorSetUpdateAfterBindInlineUniformBlocks, options);
        FieldToJson(jdata["maxInlineUniformTotalSize"], decoded_value.maxInlineUniformTotalSize, options);
        FieldToJson(jdata["integerDotProduct8BitUnsignedAccelerated"], decoded_value.integerDotProduct8BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct8BitSignedAccelerated"], decoded_value.integerDotProduct8BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct8BitMixedSignednessAccelerated"], decoded_value.integerDotProduct8BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProduct4x8BitPackedUnsignedAccelerated"], decoded_value.integerDotProduct4x8BitPackedUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct4x8BitPackedSignedAccelerated"], decoded_value.integerDotProduct4x8BitPackedSignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct4x8BitPackedMixedSignednessAccelerated"], decoded_value.integerDotProduct4x8BitPackedMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProduct16BitUnsignedAccelerated"], decoded_value.integerDotProduct16BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct16BitSignedAccelerated"], decoded_value.integerDotProduct16BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct16BitMixedSignednessAccelerated"], decoded_value.integerDotProduct16BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProduct32BitUnsignedAccelerated"], decoded_value.integerDotProduct32BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct32BitSignedAccelerated"], decoded_value.integerDotProduct32BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct32BitMixedSignednessAccelerated"], decoded_value.integerDotProduct32BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProduct64BitUnsignedAccelerated"], decoded_value.integerDotProduct64BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct64BitSignedAccelerated"], decoded_value.integerDotProduct64BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct64BitMixedSignednessAccelerated"], decoded_value.integerDotProduct64BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating8BitUnsignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating8BitSignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating8BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated"], decoded_value.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated"], decoded_value.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating16BitUnsignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating16BitSignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating16BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated"], decoded_value.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating32BitUnsignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating32BitSignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating32BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated"], decoded_value.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating64BitUnsignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating64BitSignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating64BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated"], decoded_value.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["storageTexelBufferOffsetAlignmentBytes"], decoded_value.storageTexelBufferOffsetAlignmentBytes, options);
        FieldToJson(jdata["storageTexelBufferOffsetSingleTexelAlignment"], decoded_value.storageTexelBufferOffsetSingleTexelAlignment, options);
        FieldToJson(jdata["uniformTexelBufferOffsetAlignmentBytes"], decoded_value.uniformTexelBufferOffsetAlignmentBytes, options);
        FieldToJson(jdata["uniformTexelBufferOffsetSingleTexelAlignment"], decoded_value.uniformTexelBufferOffsetSingleTexelAlignment, options);
        FieldToJson(jdata["maxBufferSize"], decoded_value.maxBufferSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCreationFeedback* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkPipelineCreationFeedbackFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["duration"], decoded_value.duration, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCreationFeedbackCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pPipelineCreationFeedback"], meta_struct.pPipelineCreationFeedback, options);
        FieldToJson(jdata["pipelineStageCreationFeedbackCount"], decoded_value.pipelineStageCreationFeedbackCount, options);
        FieldToJson(jdata["pPipelineStageCreationFeedbacks"], meta_struct.pPipelineStageCreationFeedbacks, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderTerminateInvocation"], decoded_value.shaderTerminateInvocation, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceToolProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["version"], &meta_struct.version, options);
        FieldToJson(VkToolPurposeFlags_t(),jdata["purposes"], decoded_value.purposes, options);
        FieldToJson(jdata["description"], &meta_struct.description, options);
        FieldToJson(jdata["layer"], &meta_struct.layer, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderDemoteToHelperInvocation"], decoded_value.shaderDemoteToHelperInvocation, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePrivateDataFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["privateData"], decoded_value.privateData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDevicePrivateDataCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["privateDataSlotRequestCount"], decoded_value.privateDataSlotRequestCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPrivateDataSlotCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPrivateDataSlotCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pipelineCreationCacheControl"], decoded_value.pipelineCreationCacheControl, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryBarrier2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["srcStageMask"], decoded_value.srcStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["srcAccessMask"], decoded_value.srcAccessMask, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["dstStageMask"], decoded_value.dstStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["dstAccessMask"], decoded_value.dstAccessMask, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferMemoryBarrier2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["srcStageMask"], decoded_value.srcStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["srcAccessMask"], decoded_value.srcAccessMask, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["dstStageMask"], decoded_value.dstStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["dstAccessMask"], decoded_value.dstAccessMask, options);
        FieldToJson(jdata["srcQueueFamilyIndex"], decoded_value.srcQueueFamilyIndex, options);
        FieldToJson(jdata["dstQueueFamilyIndex"], decoded_value.dstQueueFamilyIndex, options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageMemoryBarrier2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["srcStageMask"], decoded_value.srcStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["srcAccessMask"], decoded_value.srcAccessMask, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["dstStageMask"], decoded_value.dstStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["dstAccessMask"], decoded_value.dstAccessMask, options);
        FieldToJson(jdata["oldLayout"], decoded_value.oldLayout, options);
        FieldToJson(jdata["newLayout"], decoded_value.newLayout, options);
        FieldToJson(jdata["srcQueueFamilyIndex"], decoded_value.srcQueueFamilyIndex, options);
        FieldToJson(jdata["dstQueueFamilyIndex"], decoded_value.dstQueueFamilyIndex, options);
        FieldToJson(jdata["image"], to_hex(meta_struct.image), options);
        FieldToJson(jdata["subresourceRange"], meta_struct.subresourceRange, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDependencyInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDependencyFlags_t(),jdata["dependencyFlags"], decoded_value.dependencyFlags, options);
        FieldToJson(jdata["memoryBarrierCount"], decoded_value.memoryBarrierCount, options);
        FieldToJson(jdata["pMemoryBarriers"], meta_struct.pMemoryBarriers, options);
        FieldToJson(jdata["bufferMemoryBarrierCount"], decoded_value.bufferMemoryBarrierCount, options);
        FieldToJson(jdata["pBufferMemoryBarriers"], meta_struct.pBufferMemoryBarriers, options);
        FieldToJson(jdata["imageMemoryBarrierCount"], decoded_value.imageMemoryBarrierCount, options);
        FieldToJson(jdata["pImageMemoryBarriers"], meta_struct.pImageMemoryBarriers, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["semaphore"], to_hex(meta_struct.semaphore), options);
        FieldToJson(jdata["value"], decoded_value.value, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["stageMask"], decoded_value.stageMask, options);
        FieldToJson(jdata["deviceIndex"], decoded_value.deviceIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["commandBuffer"], to_hex(meta_struct.commandBuffer), options);
        FieldToJson(jdata["deviceMask"], decoded_value.deviceMask, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubmitInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkSubmitFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["waitSemaphoreInfoCount"], decoded_value.waitSemaphoreInfoCount, options);
        FieldToJson(jdata["pWaitSemaphoreInfos"], meta_struct.pWaitSemaphoreInfos, options);
        FieldToJson(jdata["commandBufferInfoCount"], decoded_value.commandBufferInfoCount, options);
        FieldToJson(jdata["pCommandBufferInfos"], meta_struct.pCommandBufferInfos, options);
        FieldToJson(jdata["signalSemaphoreInfoCount"], decoded_value.signalSemaphoreInfoCount, options);
        FieldToJson(jdata["pSignalSemaphoreInfos"], meta_struct.pSignalSemaphoreInfos, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSynchronization2Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["synchronization2"], decoded_value.synchronization2, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderZeroInitializeWorkgroupMemory"], decoded_value.shaderZeroInitializeWorkgroupMemory, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageRobustnessFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["robustImageAccess"], decoded_value.robustImageAccess, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferCopy2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcOffset"], decoded_value.srcOffset, options);
        FieldToJson(jdata["dstOffset"], decoded_value.dstOffset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyBufferInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcBuffer"], to_hex(meta_struct.srcBuffer), options);
        FieldToJson(jdata["dstBuffer"], to_hex(meta_struct.dstBuffer), options);
        FieldToJson(jdata["regionCount"], decoded_value.regionCount, options);
        FieldToJson(jdata["pRegions"], meta_struct.pRegions, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageCopy2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcSubresource"], meta_struct.srcSubresource, options);
        FieldToJson(jdata["srcOffset"], meta_struct.srcOffset, options);
        FieldToJson(jdata["dstSubresource"], meta_struct.dstSubresource, options);
        FieldToJson(jdata["dstOffset"], meta_struct.dstOffset, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyImageInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcImage"], to_hex(meta_struct.srcImage), options);
        FieldToJson(jdata["srcImageLayout"], decoded_value.srcImageLayout, options);
        FieldToJson(jdata["dstImage"], to_hex(meta_struct.dstImage), options);
        FieldToJson(jdata["dstImageLayout"], decoded_value.dstImageLayout, options);
        FieldToJson(jdata["regionCount"], decoded_value.regionCount, options);
        FieldToJson(jdata["pRegions"], meta_struct.pRegions, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferImageCopy2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["bufferOffset"], decoded_value.bufferOffset, options);
        FieldToJson(jdata["bufferRowLength"], decoded_value.bufferRowLength, options);
        FieldToJson(jdata["bufferImageHeight"], decoded_value.bufferImageHeight, options);
        FieldToJson(jdata["imageSubresource"], meta_struct.imageSubresource, options);
        FieldToJson(jdata["imageOffset"], meta_struct.imageOffset, options);
        FieldToJson(jdata["imageExtent"], meta_struct.imageExtent, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyBufferToImageInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcBuffer"], to_hex(meta_struct.srcBuffer), options);
        FieldToJson(jdata["dstImage"], to_hex(meta_struct.dstImage), options);
        FieldToJson(jdata["dstImageLayout"], decoded_value.dstImageLayout, options);
        FieldToJson(jdata["regionCount"], decoded_value.regionCount, options);
        FieldToJson(jdata["pRegions"], meta_struct.pRegions, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyImageToBufferInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcImage"], to_hex(meta_struct.srcImage), options);
        FieldToJson(jdata["srcImageLayout"], decoded_value.srcImageLayout, options);
        FieldToJson(jdata["dstBuffer"], to_hex(meta_struct.dstBuffer), options);
        FieldToJson(jdata["regionCount"], decoded_value.regionCount, options);
        FieldToJson(jdata["pRegions"], meta_struct.pRegions, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageBlit2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcSubresource"], meta_struct.srcSubresource, options);
        FieldToJson(jdata["srcOffsets"], meta_struct.srcOffsets, options);
        FieldToJson(jdata["dstSubresource"], meta_struct.dstSubresource, options);
        FieldToJson(jdata["dstOffsets"], meta_struct.dstOffsets, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBlitImageInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcImage"], to_hex(meta_struct.srcImage), options);
        FieldToJson(jdata["srcImageLayout"], decoded_value.srcImageLayout, options);
        FieldToJson(jdata["dstImage"], to_hex(meta_struct.dstImage), options);
        FieldToJson(jdata["dstImageLayout"], decoded_value.dstImageLayout, options);
        FieldToJson(jdata["regionCount"], decoded_value.regionCount, options);
        FieldToJson(jdata["pRegions"], meta_struct.pRegions, options);
        FieldToJson(jdata["filter"], decoded_value.filter, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageResolve2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcSubresource"], meta_struct.srcSubresource, options);
        FieldToJson(jdata["srcOffset"], meta_struct.srcOffset, options);
        FieldToJson(jdata["dstSubresource"], meta_struct.dstSubresource, options);
        FieldToJson(jdata["dstOffset"], meta_struct.dstOffset, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkResolveImageInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcImage"], to_hex(meta_struct.srcImage), options);
        FieldToJson(jdata["srcImageLayout"], decoded_value.srcImageLayout, options);
        FieldToJson(jdata["dstImage"], to_hex(meta_struct.dstImage), options);
        FieldToJson(jdata["dstImageLayout"], decoded_value.dstImageLayout, options);
        FieldToJson(jdata["regionCount"], decoded_value.regionCount, options);
        FieldToJson(jdata["pRegions"], meta_struct.pRegions, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["subgroupSizeControl"], decoded_value.subgroupSizeControl, options);
        FieldToJson(jdata["computeFullSubgroups"], decoded_value.computeFullSubgroups, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSubgroupSizeControlProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["minSubgroupSize"], decoded_value.minSubgroupSize, options);
        FieldToJson(jdata["maxSubgroupSize"], decoded_value.maxSubgroupSize, options);
        FieldToJson(jdata["maxComputeWorkgroupSubgroups"], decoded_value.maxComputeWorkgroupSubgroups, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["requiredSubgroupSizeStages"], decoded_value.requiredSubgroupSizeStages, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["requiredSubgroupSize"], decoded_value.requiredSubgroupSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceInlineUniformBlockFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["inlineUniformBlock"], decoded_value.inlineUniformBlock, options);
        FieldToJson(jdata["descriptorBindingInlineUniformBlockUpdateAfterBind"], decoded_value.descriptorBindingInlineUniformBlockUpdateAfterBind, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceInlineUniformBlockProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxInlineUniformBlockSize"], decoded_value.maxInlineUniformBlockSize, options);
        FieldToJson(jdata["maxPerStageDescriptorInlineUniformBlocks"], decoded_value.maxPerStageDescriptorInlineUniformBlocks, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks"], decoded_value.maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, options);
        FieldToJson(jdata["maxDescriptorSetInlineUniformBlocks"], decoded_value.maxDescriptorSetInlineUniformBlocks, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindInlineUniformBlocks"], decoded_value.maxDescriptorSetUpdateAfterBindInlineUniformBlocks, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteDescriptorSetInlineUniformBlock* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["dataSize"], decoded_value.dataSize, options);
        FieldToJson(jdata["pData"], meta_struct.pData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxInlineUniformBlockBindings"], decoded_value.maxInlineUniformBlockBindings, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["textureCompressionASTC_HDR"], decoded_value.textureCompressionASTC_HDR, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingAttachmentInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageView"], to_hex(meta_struct.imageView), options);
        FieldToJson(jdata["imageLayout"], decoded_value.imageLayout, options);
        FieldToJson(jdata["resolveMode"], decoded_value.resolveMode, options);
        FieldToJson(jdata["resolveImageView"], to_hex(meta_struct.resolveImageView), options);
        FieldToJson(jdata["resolveImageLayout"], decoded_value.resolveImageLayout, options);
        FieldToJson(jdata["loadOp"], decoded_value.loadOp, options);
        FieldToJson(jdata["storeOp"], decoded_value.storeOp, options);
        FieldToJson(jdata["clearValue"], meta_struct.clearValue, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkRenderingFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["renderArea"], meta_struct.renderArea, options);
        FieldToJson(jdata["layerCount"], decoded_value.layerCount, options);
        FieldToJson(jdata["viewMask"], decoded_value.viewMask, options);
        FieldToJson(jdata["colorAttachmentCount"], decoded_value.colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachments"], meta_struct.pColorAttachments, options);
        FieldToJson(jdata["pDepthAttachment"], meta_struct.pDepthAttachment, options);
        FieldToJson(jdata["pStencilAttachment"], meta_struct.pStencilAttachment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRenderingCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["viewMask"], decoded_value.viewMask, options);
        FieldToJson(jdata["colorAttachmentCount"], decoded_value.colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachmentFormats"], meta_struct.pColorAttachmentFormats, options);
        FieldToJson(jdata["depthAttachmentFormat"], decoded_value.depthAttachmentFormat, options);
        FieldToJson(jdata["stencilAttachmentFormat"], decoded_value.stencilAttachmentFormat, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDynamicRenderingFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["dynamicRendering"], decoded_value.dynamicRendering, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferInheritanceRenderingInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkRenderingFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["viewMask"], decoded_value.viewMask, options);
        FieldToJson(jdata["colorAttachmentCount"], decoded_value.colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachmentFormats"], meta_struct.pColorAttachmentFormats, options);
        FieldToJson(jdata["depthAttachmentFormat"], decoded_value.depthAttachmentFormat, options);
        FieldToJson(jdata["stencilAttachmentFormat"], decoded_value.stencilAttachmentFormat, options);
        FieldToJson(jdata["rasterizationSamples"], decoded_value.rasterizationSamples, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderIntegerDotProduct"], decoded_value.shaderIntegerDotProduct, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["integerDotProduct8BitUnsignedAccelerated"], decoded_value.integerDotProduct8BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct8BitSignedAccelerated"], decoded_value.integerDotProduct8BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct8BitMixedSignednessAccelerated"], decoded_value.integerDotProduct8BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProduct4x8BitPackedUnsignedAccelerated"], decoded_value.integerDotProduct4x8BitPackedUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct4x8BitPackedSignedAccelerated"], decoded_value.integerDotProduct4x8BitPackedSignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct4x8BitPackedMixedSignednessAccelerated"], decoded_value.integerDotProduct4x8BitPackedMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProduct16BitUnsignedAccelerated"], decoded_value.integerDotProduct16BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct16BitSignedAccelerated"], decoded_value.integerDotProduct16BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct16BitMixedSignednessAccelerated"], decoded_value.integerDotProduct16BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProduct32BitUnsignedAccelerated"], decoded_value.integerDotProduct32BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct32BitSignedAccelerated"], decoded_value.integerDotProduct32BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct32BitMixedSignednessAccelerated"], decoded_value.integerDotProduct32BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProduct64BitUnsignedAccelerated"], decoded_value.integerDotProduct64BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct64BitSignedAccelerated"], decoded_value.integerDotProduct64BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProduct64BitMixedSignednessAccelerated"], decoded_value.integerDotProduct64BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating8BitUnsignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating8BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating8BitSignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating8BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated"], decoded_value.integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated"], decoded_value.integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating16BitUnsignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating16BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating16BitSignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating16BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated"], decoded_value.integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating32BitUnsignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating32BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating32BitSignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating32BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated"], decoded_value.integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating64BitUnsignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating64BitUnsignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating64BitSignedAccelerated"], decoded_value.integerDotProductAccumulatingSaturating64BitSignedAccelerated, options);
        FieldToJson(jdata["integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated"], decoded_value.integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["storageTexelBufferOffsetAlignmentBytes"], decoded_value.storageTexelBufferOffsetAlignmentBytes, options);
        FieldToJson(jdata["storageTexelBufferOffsetSingleTexelAlignment"], decoded_value.storageTexelBufferOffsetSingleTexelAlignment, options);
        FieldToJson(jdata["uniformTexelBufferOffsetAlignmentBytes"], decoded_value.uniformTexelBufferOffsetAlignmentBytes, options);
        FieldToJson(jdata["uniformTexelBufferOffsetSingleTexelAlignment"], decoded_value.uniformTexelBufferOffsetSingleTexelAlignment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFormatProperties3* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkFormatFeatureFlags2_t(),jdata["linearTilingFeatures"], decoded_value.linearTilingFeatures, options);
        FieldToJson(VkFormatFeatureFlags2_t(),jdata["optimalTilingFeatures"], decoded_value.optimalTilingFeatures, options);
        FieldToJson(VkFormatFeatureFlags2_t(),jdata["bufferFeatures"], decoded_value.bufferFeatures, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance4Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maintenance4"], decoded_value.maintenance4, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance4Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxBufferSize"], decoded_value.maxBufferSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceBufferMemoryRequirements* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pCreateInfo"], meta_struct.pCreateInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceImageMemoryRequirements* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pCreateInfo"], meta_struct.pCreateInfo, options);
        FieldToJson(jdata["planeAspect"], decoded_value.planeAspect, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["minImageCount"], decoded_value.minImageCount, options);
        FieldToJson(jdata["maxImageCount"], decoded_value.maxImageCount, options);
        FieldToJson(jdata["currentExtent"], meta_struct.currentExtent, options);
        FieldToJson(jdata["minImageExtent"], meta_struct.minImageExtent, options);
        FieldToJson(jdata["maxImageExtent"], meta_struct.maxImageExtent, options);
        FieldToJson(jdata["maxImageArrayLayers"], decoded_value.maxImageArrayLayers, options);
        FieldToJson(VkSurfaceTransformFlagsKHR_t(),jdata["supportedTransforms"], decoded_value.supportedTransforms, options);
        FieldToJson(jdata["currentTransform"], decoded_value.currentTransform, options);
        FieldToJson(VkCompositeAlphaFlagsKHR_t(),jdata["supportedCompositeAlpha"], decoded_value.supportedCompositeAlpha, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["supportedUsageFlags"], decoded_value.supportedUsageFlags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceFormatKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["colorSpace"], decoded_value.colorSpace, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkSwapchainCreateFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["surface"], to_hex(meta_struct.surface), options);
        FieldToJson(jdata["minImageCount"], decoded_value.minImageCount, options);
        FieldToJson(jdata["imageFormat"], decoded_value.imageFormat, options);
        FieldToJson(jdata["imageColorSpace"], decoded_value.imageColorSpace, options);
        FieldToJson(jdata["imageExtent"], meta_struct.imageExtent, options);
        FieldToJson(jdata["imageArrayLayers"], decoded_value.imageArrayLayers, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["imageUsage"], decoded_value.imageUsage, options);
        FieldToJson(jdata["imageSharingMode"], decoded_value.imageSharingMode, options);
        FieldToJson(jdata["queueFamilyIndexCount"], decoded_value.queueFamilyIndexCount, options);
        FieldToJson(jdata["pQueueFamilyIndices"], meta_struct.pQueueFamilyIndices, options);
        FieldToJson(jdata["preTransform"], decoded_value.preTransform, options);
        FieldToJson(jdata["compositeAlpha"], decoded_value.compositeAlpha, options);
        FieldToJson(jdata["presentMode"], decoded_value.presentMode, options);
        FieldToJson(jdata["clipped"], decoded_value.clipped, options);
        FieldToJson(jdata["oldSwapchain"], to_hex(meta_struct.oldSwapchain), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["waitSemaphoreCount"], decoded_value.waitSemaphoreCount, options);
        FieldToJson(jdata["pWaitSemaphores"], &meta_struct.pWaitSemaphores, options);
        FieldToJson(jdata["swapchainCount"], decoded_value.swapchainCount, options);
        FieldToJson(jdata["pSwapchains"], &meta_struct.pSwapchains, options);
        FieldToJson(jdata["pImageIndices"], meta_struct.pImageIndices, options);
        FieldToJson(jdata["pResults"], meta_struct.pResults, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSwapchainCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchain"], to_hex(meta_struct.swapchain), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindImageMemorySwapchainInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchain"], to_hex(meta_struct.swapchain), options);
        FieldToJson(jdata["imageIndex"], decoded_value.imageIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAcquireNextImageInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchain"], to_hex(meta_struct.swapchain), options);
        FieldToJson(jdata["timeout"], decoded_value.timeout, options);
        FieldToJson(jdata["semaphore"], to_hex(meta_struct.semaphore), options);
        FieldToJson(jdata["fence"], to_hex(meta_struct.fence), options);
        FieldToJson(jdata["deviceMask"], decoded_value.deviceMask, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupPresentCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["presentMask"], &meta_struct.presentMask, options);
        FieldToJson(VkDeviceGroupPresentModeFlagsKHR_t(),jdata["modes"], decoded_value.modes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupPresentInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchainCount"], decoded_value.swapchainCount, options);
        FieldToJson(jdata["pDeviceMasks"], meta_struct.pDeviceMasks, options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupSwapchainCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDeviceGroupPresentModeFlagsKHR_t(),jdata["modes"], decoded_value.modes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayModeParametersKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["visibleRegion"], meta_struct.visibleRegion, options);
        FieldToJson(jdata["refreshRate"], decoded_value.refreshRate, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayModeCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDisplayModeCreateFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["parameters"], meta_struct.parameters, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayModePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["displayMode"], to_hex(meta_struct.displayMode), options);
        FieldToJson(jdata["parameters"], meta_struct.parameters, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPlaneCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkDisplayPlaneAlphaFlagsKHR_t(),jdata["supportedAlpha"], decoded_value.supportedAlpha, options);
        FieldToJson(jdata["minSrcPosition"], meta_struct.minSrcPosition, options);
        FieldToJson(jdata["maxSrcPosition"], meta_struct.maxSrcPosition, options);
        FieldToJson(jdata["minSrcExtent"], meta_struct.minSrcExtent, options);
        FieldToJson(jdata["maxSrcExtent"], meta_struct.maxSrcExtent, options);
        FieldToJson(jdata["minDstPosition"], meta_struct.minDstPosition, options);
        FieldToJson(jdata["maxDstPosition"], meta_struct.maxDstPosition, options);
        FieldToJson(jdata["minDstExtent"], meta_struct.minDstExtent, options);
        FieldToJson(jdata["maxDstExtent"], meta_struct.maxDstExtent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPlanePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["currentDisplay"], to_hex(meta_struct.currentDisplay), options);
        FieldToJson(jdata["currentStackIndex"], decoded_value.currentStackIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["display"], to_hex(meta_struct.display), options);
        FieldToJson(jdata["displayName"], &meta_struct.displayName, options);
        FieldToJson(jdata["physicalDimensions"], meta_struct.physicalDimensions, options);
        FieldToJson(jdata["physicalResolution"], meta_struct.physicalResolution, options);
        FieldToJson(VkSurfaceTransformFlagsKHR_t(),jdata["supportedTransforms"], decoded_value.supportedTransforms, options);
        FieldToJson(jdata["planeReorderPossible"], decoded_value.planeReorderPossible, options);
        FieldToJson(jdata["persistentContent"], decoded_value.persistentContent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplaySurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDisplaySurfaceCreateFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["displayMode"], to_hex(meta_struct.displayMode), options);
        FieldToJson(jdata["planeIndex"], decoded_value.planeIndex, options);
        FieldToJson(jdata["planeStackIndex"], decoded_value.planeStackIndex, options);
        FieldToJson(jdata["transform"], decoded_value.transform, options);
        FieldToJson(jdata["globalAlpha"], decoded_value.globalAlpha, options);
        FieldToJson(jdata["alphaMode"], decoded_value.alphaMode, options);
        FieldToJson(jdata["imageExtent"], meta_struct.imageExtent, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPresentInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcRect"], meta_struct.srcRect, options);
        FieldToJson(jdata["dstRect"], meta_struct.dstRect, options);
        FieldToJson(jdata["persistent"], decoded_value.persistent, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkXlibSurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkXlibSurfaceCreateFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["dpy"], meta_struct.dpy, options);
        FieldToJson(jdata["window"], decoded_value.window, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkXcbSurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkXcbSurfaceCreateFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["connection"], meta_struct.connection, options);
        FieldToJson(jdata["window"], decoded_value.window, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWaylandSurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkWaylandSurfaceCreateFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["display"], meta_struct.display, options);
        FieldToJson(jdata["surface"], meta_struct.surface, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidSurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkAndroidSurfaceCreateFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["window"], meta_struct.window, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWin32SurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkWin32SurfaceCreateFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["hinstance"], meta_struct.hinstance, options);
        FieldToJson(jdata["hwnd"], meta_struct.hwnd, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["queryResultStatusSupport"], decoded_value.queryResultStatusSupport, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyVideoPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoCodecOperationFlagsKHR_t(),jdata["videoCodecOperations"], decoded_value.videoCodecOperations, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoProfileInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["videoCodecOperation"], decoded_value.videoCodecOperation, options);
        FieldToJson(VkVideoChromaSubsamplingFlagsKHR_t(),jdata["chromaSubsampling"], decoded_value.chromaSubsampling, options);
        FieldToJson(VkVideoComponentBitDepthFlagsKHR_t(),jdata["lumaBitDepth"], decoded_value.lumaBitDepth, options);
        FieldToJson(VkVideoComponentBitDepthFlagsKHR_t(),jdata["chromaBitDepth"], decoded_value.chromaBitDepth, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoProfileListInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["profileCount"], decoded_value.profileCount, options);
        FieldToJson(jdata["pProfiles"], meta_struct.pProfiles, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoCapabilityFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["minBitstreamBufferOffsetAlignment"], decoded_value.minBitstreamBufferOffsetAlignment, options);
        FieldToJson(jdata["minBitstreamBufferSizeAlignment"], decoded_value.minBitstreamBufferSizeAlignment, options);
        FieldToJson(jdata["pictureAccessGranularity"], meta_struct.pictureAccessGranularity, options);
        FieldToJson(jdata["minCodedExtent"], meta_struct.minCodedExtent, options);
        FieldToJson(jdata["maxCodedExtent"], meta_struct.maxCodedExtent, options);
        FieldToJson(jdata["maxDpbSlots"], decoded_value.maxDpbSlots, options);
        FieldToJson(jdata["maxActiveReferencePictures"], decoded_value.maxActiveReferencePictures, options);
        FieldToJson(jdata["stdHeaderVersion"], meta_struct.stdHeaderVersion, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVideoFormatInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["imageUsage"], decoded_value.imageUsage, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoFormatPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["componentMapping"], meta_struct.componentMapping, options);
        FieldToJson(VkImageCreateFlags_t(),jdata["imageCreateFlags"], decoded_value.imageCreateFlags, options);
        FieldToJson(jdata["imageType"], decoded_value.imageType, options);
        FieldToJson(jdata["imageTiling"], decoded_value.imageTiling, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["imageUsageFlags"], decoded_value.imageUsageFlags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoPictureResourceInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["codedOffset"], meta_struct.codedOffset, options);
        FieldToJson(jdata["codedExtent"], meta_struct.codedExtent, options);
        FieldToJson(jdata["baseArrayLayer"], decoded_value.baseArrayLayer, options);
        FieldToJson(jdata["imageViewBinding"], to_hex(meta_struct.imageViewBinding), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoReferenceSlotInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["slotIndex"], decoded_value.slotIndex, options);
        FieldToJson(jdata["pPictureResource"], meta_struct.pPictureResource, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoSessionMemoryRequirementsKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memoryBindIndex"], decoded_value.memoryBindIndex, options);
        FieldToJson(jdata["memoryRequirements"], meta_struct.memoryRequirements, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindVideoSessionMemoryInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memoryBindIndex"], decoded_value.memoryBindIndex, options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["memoryOffset"], decoded_value.memoryOffset, options);
        FieldToJson(jdata["memorySize"], decoded_value.memorySize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoSessionCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["queueFamilyIndex"], decoded_value.queueFamilyIndex, options);
        FieldToJson(VkVideoSessionCreateFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pVideoProfile"], meta_struct.pVideoProfile, options);
        FieldToJson(jdata["pictureFormat"], decoded_value.pictureFormat, options);
        FieldToJson(jdata["maxCodedExtent"], meta_struct.maxCodedExtent, options);
        FieldToJson(jdata["referencePictureFormat"], decoded_value.referencePictureFormat, options);
        FieldToJson(jdata["maxDpbSlots"], decoded_value.maxDpbSlots, options);
        FieldToJson(jdata["maxActiveReferencePictures"], decoded_value.maxActiveReferencePictures, options);
        FieldToJson(jdata["pStdHeaderVersion"], meta_struct.pStdHeaderVersion, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoSessionParametersCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoSessionParametersCreateFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["videoSessionParametersTemplate"], to_hex(meta_struct.videoSessionParametersTemplate), options);
        FieldToJson(jdata["videoSession"], to_hex(meta_struct.videoSession), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoSessionParametersUpdateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["updateSequenceCount"], decoded_value.updateSequenceCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoBeginCodingInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoBeginCodingFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["videoSession"], to_hex(meta_struct.videoSession), options);
        FieldToJson(jdata["videoSessionParameters"], to_hex(meta_struct.videoSessionParameters), options);
        FieldToJson(jdata["referenceSlotCount"], decoded_value.referenceSlotCount, options);
        FieldToJson(jdata["pReferenceSlots"], meta_struct.pReferenceSlots, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEndCodingInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoEndCodingFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoCodingControlInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoCodingControlFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoDecodeCapabilityFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeUsageInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoDecodeUsageFlagsKHR_t(),jdata["videoUsageHints"], decoded_value.videoUsageHints, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoDecodeFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["srcBuffer"], to_hex(meta_struct.srcBuffer), options);
        FieldToJson(jdata["srcBufferOffset"], decoded_value.srcBufferOffset, options);
        FieldToJson(jdata["srcBufferRange"], decoded_value.srcBufferRange, options);
        FieldToJson(jdata["dstPictureResource"], meta_struct.dstPictureResource, options);
        FieldToJson(jdata["pSetupReferenceSlot"], meta_struct.pSetupReferenceSlot, options);
        FieldToJson(jdata["referenceSlotCount"], decoded_value.referenceSlotCount, options);
        FieldToJson(jdata["pReferenceSlots"], meta_struct.pReferenceSlots, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264ProfileInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stdProfileIdc"], decoded_value.stdProfileIdc, options);
        FieldToJson(jdata["pictureLayout"], decoded_value.pictureLayout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264CapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxLevelIdc"], decoded_value.maxLevelIdc, options);
        FieldToJson(jdata["fieldOffsetGranularity"], meta_struct.fieldOffsetGranularity, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stdSPSCount"], decoded_value.stdSPSCount, options);
        FieldToJson(jdata["pStdSPSs"], meta_struct.pStdSPSs, options);
        FieldToJson(jdata["stdPPSCount"], decoded_value.stdPPSCount, options);
        FieldToJson(jdata["pStdPPSs"], meta_struct.pStdPPSs, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxStdSPSCount"], decoded_value.maxStdSPSCount, options);
        FieldToJson(jdata["maxStdPPSCount"], decoded_value.maxStdPPSCount, options);
        FieldToJson(jdata["pParametersAddInfo"], meta_struct.pParametersAddInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264PictureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pStdPictureInfo"], meta_struct.pStdPictureInfo, options);
        FieldToJson(jdata["sliceCount"], decoded_value.sliceCount, options);
        FieldToJson(jdata["pSliceOffsets"], meta_struct.pSliceOffsets, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264DpbSlotInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pStdReferenceInfo"], meta_struct.pStdReferenceInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageView"], to_hex(meta_struct.imageView), options);
        FieldToJson(jdata["imageLayout"], decoded_value.imageLayout, options);
        FieldToJson(jdata["shadingRateAttachmentTexelSize"], meta_struct.shadingRateAttachmentTexelSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageView"], to_hex(meta_struct.imageView), options);
        FieldToJson(jdata["imageLayout"], decoded_value.imageLayout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentSampleCountInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["colorAttachmentCount"], decoded_value.colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachmentSamples"], meta_struct.pColorAttachmentSamples, options);
        FieldToJson(jdata["depthStencilAttachmentSamples"], decoded_value.depthStencilAttachmentSamples, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultiviewPerViewAttributesInfoNVX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["perViewAttributes"], decoded_value.perViewAttributes, options);
        FieldToJson(jdata["perViewAttributesPositionXOnly"], decoded_value.perViewAttributesPositionXOnly, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["handle"], meta_struct.handle, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportMemoryWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pAttributes"], meta_struct.pAttributes, options);
        FieldToJson(jdata["dwAccess"], decoded_value.dwAccess, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryWin32HandlePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memoryTypeBits"], decoded_value.memoryTypeBits, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["fd"], decoded_value.fd, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryFdPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memoryTypeBits"], decoded_value.memoryTypeBits, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["acquireCount"], decoded_value.acquireCount, options);
        FieldToJson(jdata["pAcquireSyncs"], &meta_struct.pAcquireSyncs, options);
        FieldToJson(jdata["pAcquireKeys"], meta_struct.pAcquireKeys, options);
        FieldToJson(jdata["pAcquireTimeouts"], meta_struct.pAcquireTimeouts, options);
        FieldToJson(jdata["releaseCount"], decoded_value.releaseCount, options);
        FieldToJson(jdata["pReleaseSyncs"], &meta_struct.pReleaseSyncs, options);
        FieldToJson(jdata["pReleaseKeys"], meta_struct.pReleaseKeys, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportSemaphoreWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["semaphore"], to_hex(meta_struct.semaphore), options);
        FieldToJson(VkSemaphoreImportFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["handle"], meta_struct.handle, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportSemaphoreWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pAttributes"], meta_struct.pAttributes, options);
        FieldToJson(jdata["dwAccess"], decoded_value.dwAccess, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkD3D12FenceSubmitInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["waitSemaphoreValuesCount"], decoded_value.waitSemaphoreValuesCount, options);
        FieldToJson(jdata["pWaitSemaphoreValues"], meta_struct.pWaitSemaphoreValues, options);
        FieldToJson(jdata["signalSemaphoreValuesCount"], decoded_value.signalSemaphoreValuesCount, options);
        FieldToJson(jdata["pSignalSemaphoreValues"], meta_struct.pSignalSemaphoreValues, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreGetWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["semaphore"], to_hex(meta_struct.semaphore), options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportSemaphoreFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["semaphore"], to_hex(meta_struct.semaphore), options);
        FieldToJson(VkSemaphoreImportFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["fd"], decoded_value.fd, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreGetFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["semaphore"], to_hex(meta_struct.semaphore), options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxPushDescriptors"], decoded_value.maxPushDescriptors, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRectLayerKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["offset"], meta_struct.offset, options);
        FieldToJson(jdata["extent"], meta_struct.extent, options);
        FieldToJson(jdata["layer"], decoded_value.layer, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentRegionKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["rectangleCount"], decoded_value.rectangleCount, options);
        FieldToJson(jdata["pRectangles"], meta_struct.pRectangles, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentRegionsKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchainCount"], decoded_value.swapchainCount, options);
        FieldToJson(jdata["pRegions"], meta_struct.pRegions, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSharedPresentSurfaceCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["sharedPresentSupportedUsageFlags"], decoded_value.sharedPresentSupportedUsageFlags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportFenceWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fence"], to_hex(meta_struct.fence), options);
        FieldToJson(VkFenceImportFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["handle"], meta_struct.handle, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportFenceWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pAttributes"], meta_struct.pAttributes, options);
        FieldToJson(jdata["dwAccess"], decoded_value.dwAccess, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFenceGetWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fence"], to_hex(meta_struct.fence), options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportFenceFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fence"], to_hex(meta_struct.fence), options);
        FieldToJson(VkFenceImportFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["fd"], decoded_value.fd, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFenceGetFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fence"], to_hex(meta_struct.fence), options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["performanceCounterQueryPools"], decoded_value.performanceCounterQueryPools, options);
        FieldToJson(jdata["performanceCounterMultipleQueryPools"], decoded_value.performanceCounterMultipleQueryPools, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["allowCommandBufferQueryCopies"], decoded_value.allowCommandBufferQueryCopies, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceCounterKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["unit"], decoded_value.unit, options);
        FieldToJson(jdata["scope"], decoded_value.scope, options);
        FieldToJson(jdata["storage"], decoded_value.storage, options);
        FieldToJson(jdata["uuid"], uuid_to_string(sizeof(decoded_value.uuid), decoded_value.uuid), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceCounterDescriptionKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPerformanceCounterDescriptionFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["category"], &meta_struct.category, options);
        FieldToJson(jdata["description"], &meta_struct.description, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueryPoolPerformanceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["queueFamilyIndex"], decoded_value.queueFamilyIndex, options);
        FieldToJson(jdata["counterIndexCount"], decoded_value.counterIndexCount, options);
        FieldToJson(jdata["pCounterIndices"], meta_struct.pCounterIndices, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAcquireProfilingLockInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkAcquireProfilingLockFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["timeout"], decoded_value.timeout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceQuerySubmitInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["counterPassIndex"], decoded_value.counterPassIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSurfaceInfo2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["surface"], to_hex(meta_struct.surface), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilities2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["surfaceCapabilities"], meta_struct.surfaceCapabilities, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceFormat2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["surfaceFormat"], meta_struct.surfaceFormat, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayProperties2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["displayProperties"], meta_struct.displayProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPlaneProperties2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["displayPlaneProperties"], meta_struct.displayPlaneProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayModeProperties2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["displayModeProperties"], meta_struct.displayModeProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPlaneInfo2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["mode"], to_hex(meta_struct.mode), options);
        FieldToJson(jdata["planeIndex"], decoded_value.planeIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPlaneCapabilities2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["capabilities"], meta_struct.capabilities, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["constantAlphaColorBlendFactors"], decoded_value.constantAlphaColorBlendFactors, options);
        FieldToJson(jdata["events"], decoded_value.events, options);
        FieldToJson(jdata["imageViewFormatReinterpretation"], decoded_value.imageViewFormatReinterpretation, options);
        FieldToJson(jdata["imageViewFormatSwizzle"], decoded_value.imageViewFormatSwizzle, options);
        FieldToJson(jdata["imageView2DOn3DImage"], decoded_value.imageView2DOn3DImage, options);
        FieldToJson(jdata["multisampleArrayImage"], decoded_value.multisampleArrayImage, options);
        FieldToJson(jdata["mutableComparisonSamplers"], decoded_value.mutableComparisonSamplers, options);
        FieldToJson(jdata["pointPolygons"], decoded_value.pointPolygons, options);
        FieldToJson(jdata["samplerMipLodBias"], decoded_value.samplerMipLodBias, options);
        FieldToJson(jdata["separateStencilMaskRef"], decoded_value.separateStencilMaskRef, options);
        FieldToJson(jdata["shaderSampleRateInterpolationFunctions"], decoded_value.shaderSampleRateInterpolationFunctions, options);
        FieldToJson(jdata["tessellationIsolines"], decoded_value.tessellationIsolines, options);
        FieldToJson(jdata["tessellationPointMode"], decoded_value.tessellationPointMode, options);
        FieldToJson(jdata["triangleFans"], decoded_value.triangleFans, options);
        FieldToJson(jdata["vertexAttributeAccessBeyondStride"], decoded_value.vertexAttributeAccessBeyondStride, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["minVertexInputBindingStrideAlignment"], decoded_value.minVertexInputBindingStrideAlignment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderClockFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderSubgroupClock"], decoded_value.shaderSubgroupClock, options);
        FieldToJson(jdata["shaderDeviceClock"], decoded_value.shaderDeviceClock, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH265ProfileInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stdProfileIdc"], decoded_value.stdProfileIdc, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH265CapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxLevelIdc"], decoded_value.maxLevelIdc, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH265SessionParametersAddInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stdVPSCount"], decoded_value.stdVPSCount, options);
        FieldToJson(jdata["pStdVPSs"], meta_struct.pStdVPSs, options);
        FieldToJson(jdata["stdSPSCount"], decoded_value.stdSPSCount, options);
        FieldToJson(jdata["pStdSPSs"], meta_struct.pStdSPSs, options);
        FieldToJson(jdata["stdPPSCount"], decoded_value.stdPPSCount, options);
        FieldToJson(jdata["pStdPPSs"], meta_struct.pStdPPSs, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH265SessionParametersCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxStdVPSCount"], decoded_value.maxStdVPSCount, options);
        FieldToJson(jdata["maxStdSPSCount"], decoded_value.maxStdSPSCount, options);
        FieldToJson(jdata["maxStdPPSCount"], decoded_value.maxStdPPSCount, options);
        FieldToJson(jdata["pParametersAddInfo"], meta_struct.pParametersAddInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH265PictureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pStdPictureInfo"], meta_struct.pStdPictureInfo, options);
        FieldToJson(jdata["sliceSegmentCount"], decoded_value.sliceSegmentCount, options);
        FieldToJson(jdata["pSliceSegmentOffsets"], meta_struct.pSliceSegmentOffsets, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH265DpbSlotInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pStdReferenceInfo"], meta_struct.pStdReferenceInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["globalPriority"], decoded_value.globalPriority, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["globalPriorityQuery"], decoded_value.globalPriorityQuery, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["priorityCount"], decoded_value.priorityCount, options);
        FieldToJson(jdata["priorities"], &meta_struct.priorities, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFragmentShadingRateAttachmentInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pFragmentShadingRateAttachment"], meta_struct.pFragmentShadingRateAttachment, options);
        FieldToJson(jdata["shadingRateAttachmentTexelSize"], meta_struct.shadingRateAttachmentTexelSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fragmentSize"], meta_struct.fragmentSize, options);
        FieldToJson(jdata["combinerOps"], &meta_struct.combinerOps, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pipelineFragmentShadingRate"], decoded_value.pipelineFragmentShadingRate, options);
        FieldToJson(jdata["primitiveFragmentShadingRate"], decoded_value.primitiveFragmentShadingRate, options);
        FieldToJson(jdata["attachmentFragmentShadingRate"], decoded_value.attachmentFragmentShadingRate, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["minFragmentShadingRateAttachmentTexelSize"], meta_struct.minFragmentShadingRateAttachmentTexelSize, options);
        FieldToJson(jdata["maxFragmentShadingRateAttachmentTexelSize"], meta_struct.maxFragmentShadingRateAttachmentTexelSize, options);
        FieldToJson(jdata["maxFragmentShadingRateAttachmentTexelSizeAspectRatio"], decoded_value.maxFragmentShadingRateAttachmentTexelSizeAspectRatio, options);
        FieldToJson(jdata["primitiveFragmentShadingRateWithMultipleViewports"], decoded_value.primitiveFragmentShadingRateWithMultipleViewports, options);
        FieldToJson(jdata["layeredShadingRateAttachments"], decoded_value.layeredShadingRateAttachments, options);
        FieldToJson(jdata["fragmentShadingRateNonTrivialCombinerOps"], decoded_value.fragmentShadingRateNonTrivialCombinerOps, options);
        FieldToJson(jdata["maxFragmentSize"], meta_struct.maxFragmentSize, options);
        FieldToJson(jdata["maxFragmentSizeAspectRatio"], decoded_value.maxFragmentSizeAspectRatio, options);
        FieldToJson(jdata["maxFragmentShadingRateCoverageSamples"], decoded_value.maxFragmentShadingRateCoverageSamples, options);
        FieldToJson(jdata["maxFragmentShadingRateRasterizationSamples"], decoded_value.maxFragmentShadingRateRasterizationSamples, options);
        FieldToJson(jdata["fragmentShadingRateWithShaderDepthStencilWrites"], decoded_value.fragmentShadingRateWithShaderDepthStencilWrites, options);
        FieldToJson(jdata["fragmentShadingRateWithSampleMask"], decoded_value.fragmentShadingRateWithSampleMask, options);
        FieldToJson(jdata["fragmentShadingRateWithShaderSampleMask"], decoded_value.fragmentShadingRateWithShaderSampleMask, options);
        FieldToJson(jdata["fragmentShadingRateWithConservativeRasterization"], decoded_value.fragmentShadingRateWithConservativeRasterization, options);
        FieldToJson(jdata["fragmentShadingRateWithFragmentShaderInterlock"], decoded_value.fragmentShadingRateWithFragmentShaderInterlock, options);
        FieldToJson(jdata["fragmentShadingRateWithCustomSampleLocations"], decoded_value.fragmentShadingRateWithCustomSampleLocations, options);
        FieldToJson(jdata["fragmentShadingRateStrictMultiplyCombiner"], decoded_value.fragmentShadingRateStrictMultiplyCombiner, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShadingRateKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampleCounts"], decoded_value.sampleCounts, options);
        FieldToJson(jdata["fragmentSize"], meta_struct.fragmentSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceProtectedCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["supportsProtected"], decoded_value.supportsProtected, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePresentWaitFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["presentWait"], decoded_value.presentWait, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pipelineExecutableInfo"], decoded_value.pipelineExecutableInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pipeline"], to_hex(meta_struct.pipeline), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineExecutablePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["stages"], decoded_value.stages, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["description"], &meta_struct.description, options);
        FieldToJson(jdata["subgroupSize"], decoded_value.subgroupSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineExecutableInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pipeline"], to_hex(meta_struct.pipeline), options);
        FieldToJson(jdata["executableIndex"], decoded_value.executableIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineExecutableInternalRepresentationKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["name"], &meta_struct.name, options);
        FieldToJson(jdata["description"], &meta_struct.description, options);
        FieldToJson(jdata["isText"], decoded_value.isText, options);
        FieldToJson(jdata["dataSize"], decoded_value.dataSize, options);
        FieldToJson(jdata["pData"], meta_struct.pData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineLibraryCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["libraryCount"], decoded_value.libraryCount, options);
        FieldToJson(jdata["pLibraries"], &meta_struct.pLibraries, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentIdKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchainCount"], decoded_value.swapchainCount, options);
        FieldToJson(jdata["pPresentIds"], meta_struct.pPresentIds, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePresentIdFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["presentId"], decoded_value.presentId, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoEncodeFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["qualityLevel"], decoded_value.qualityLevel, options);
        FieldToJson(jdata["dstBitstreamBuffer"], to_hex(meta_struct.dstBitstreamBuffer), options);
        FieldToJson(jdata["dstBitstreamBufferOffset"], decoded_value.dstBitstreamBufferOffset, options);
        FieldToJson(jdata["dstBitstreamBufferMaxRange"], decoded_value.dstBitstreamBufferMaxRange, options);
        FieldToJson(jdata["srcPictureResource"], meta_struct.srcPictureResource, options);
        FieldToJson(jdata["pSetupReferenceSlot"], meta_struct.pSetupReferenceSlot, options);
        FieldToJson(jdata["referenceSlotCount"], decoded_value.referenceSlotCount, options);
        FieldToJson(jdata["pReferenceSlots"], meta_struct.pReferenceSlots, options);
        FieldToJson(jdata["precedingExternallyEncodedBytes"], decoded_value.precedingExternallyEncodedBytes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoEncodeCapabilityFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(VkVideoEncodeRateControlModeFlagsKHR_t(),jdata["rateControlModes"], decoded_value.rateControlModes, options);
        FieldToJson(jdata["rateControlLayerCount"], decoded_value.rateControlLayerCount, options);
        FieldToJson(jdata["qualityLevelCount"], decoded_value.qualityLevelCount, options);
        FieldToJson(jdata["inputImageDataFillAlignment"], meta_struct.inputImageDataFillAlignment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeUsageInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoEncodeUsageFlagsKHR_t(),jdata["videoUsageHints"], decoded_value.videoUsageHints, options);
        FieldToJson(VkVideoEncodeContentFlagsKHR_t(),jdata["videoContentHints"], decoded_value.videoContentHints, options);
        FieldToJson(jdata["tuningMode"], decoded_value.tuningMode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeRateControlLayerInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["averageBitrate"], decoded_value.averageBitrate, options);
        FieldToJson(jdata["maxBitrate"], decoded_value.maxBitrate, options);
        FieldToJson(jdata["frameRateNumerator"], decoded_value.frameRateNumerator, options);
        FieldToJson(jdata["frameRateDenominator"], decoded_value.frameRateDenominator, options);
        FieldToJson(jdata["virtualBufferSizeInMs"], decoded_value.virtualBufferSizeInMs, options);
        FieldToJson(jdata["initialVirtualBufferSizeInMs"], decoded_value.initialVirtualBufferSizeInMs, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeRateControlInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoEncodeRateControlFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["rateControlMode"], decoded_value.rateControlMode, options);
        FieldToJson(jdata["layerCount"], decoded_value.layerCount, options);
        FieldToJson(jdata["pLayerConfigs"], meta_struct.pLayerConfigs, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyCheckpointProperties2NV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["checkpointExecutionStageMask"], decoded_value.checkpointExecutionStageMask, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCheckpointData2NV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["stage"], decoded_value.stage, options);
        FieldToJson(jdata["pCheckpointMarker"], meta_struct.pCheckpointMarker, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fragmentShaderBarycentric"], decoded_value.fragmentShaderBarycentric, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["triStripVertexOrderIndependentOfProvokingVertex"], decoded_value.triStripVertexOrderIndependentOfProvokingVertex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderSubgroupUniformControlFlow"], decoded_value.shaderSubgroupUniformControlFlow, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["workgroupMemoryExplicitLayout"], decoded_value.workgroupMemoryExplicitLayout, options);
        FieldToJson(jdata["workgroupMemoryExplicitLayoutScalarBlockLayout"], decoded_value.workgroupMemoryExplicitLayoutScalarBlockLayout, options);
        FieldToJson(jdata["workgroupMemoryExplicitLayout8BitAccess"], decoded_value.workgroupMemoryExplicitLayout8BitAccess, options);
        FieldToJson(jdata["workgroupMemoryExplicitLayout16BitAccess"], decoded_value.workgroupMemoryExplicitLayout16BitAccess, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["rayTracingMaintenance1"], decoded_value.rayTracingMaintenance1, options);
        FieldToJson(jdata["rayTracingPipelineTraceRaysIndirect2"], decoded_value.rayTracingPipelineTraceRaysIndirect2, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTraceRaysIndirectCommand2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["raygenShaderRecordAddress"], to_hex(decoded_value.raygenShaderRecordAddress), options);
        FieldToJson(jdata["raygenShaderRecordSize"], decoded_value.raygenShaderRecordSize, options);
        FieldToJson(jdata["missShaderBindingTableAddress"], to_hex(decoded_value.missShaderBindingTableAddress), options);
        FieldToJson(jdata["missShaderBindingTableSize"], decoded_value.missShaderBindingTableSize, options);
        FieldToJson(jdata["missShaderBindingTableStride"], decoded_value.missShaderBindingTableStride, options);
        FieldToJson(jdata["hitShaderBindingTableAddress"], to_hex(decoded_value.hitShaderBindingTableAddress), options);
        FieldToJson(jdata["hitShaderBindingTableSize"], decoded_value.hitShaderBindingTableSize, options);
        FieldToJson(jdata["hitShaderBindingTableStride"], decoded_value.hitShaderBindingTableStride, options);
        FieldToJson(jdata["callableShaderBindingTableAddress"], to_hex(decoded_value.callableShaderBindingTableAddress), options);
        FieldToJson(jdata["callableShaderBindingTableSize"], decoded_value.callableShaderBindingTableSize, options);
        FieldToJson(jdata["callableShaderBindingTableStride"], decoded_value.callableShaderBindingTableStride, options);
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["depth"], decoded_value.depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugReportCallbackCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDebugReportFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pfnCallback"], to_hex(meta_struct.pfnCallback), options);
        FieldToJson(jdata["pUserData"], to_hex(meta_struct.pUserData), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["rasterizationOrder"], decoded_value.rasterizationOrder, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugMarkerObjectNameInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["objectType"], decoded_value.objectType, options);
        FieldToJson(jdata["object"], decoded_value.object, options);
        FieldToJson(jdata["pObjectName"], &meta_struct.pObjectName, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugMarkerObjectTagInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["objectType"], decoded_value.objectType, options);
        FieldToJson(jdata["object"], decoded_value.object, options);
        FieldToJson(jdata["tagName"], decoded_value.tagName, options);
        FieldToJson(jdata["tagSize"], decoded_value.tagSize, options);
        FieldToJson(jdata["pTag"], meta_struct.pTag, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugMarkerMarkerInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pMarkerName"], &meta_struct.pMarkerName, options);
        FieldToJson(jdata["color"], &meta_struct.color, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDedicatedAllocationImageCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["dedicatedAllocation"], decoded_value.dedicatedAllocation, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDedicatedAllocationBufferCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["dedicatedAllocation"], decoded_value.dedicatedAllocation, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["image"], to_hex(meta_struct.image), options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["transformFeedback"], decoded_value.transformFeedback, options);
        FieldToJson(jdata["geometryStreams"], decoded_value.geometryStreams, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxTransformFeedbackStreams"], decoded_value.maxTransformFeedbackStreams, options);
        FieldToJson(jdata["maxTransformFeedbackBuffers"], decoded_value.maxTransformFeedbackBuffers, options);
        FieldToJson(jdata["maxTransformFeedbackBufferSize"], decoded_value.maxTransformFeedbackBufferSize, options);
        FieldToJson(jdata["maxTransformFeedbackStreamDataSize"], decoded_value.maxTransformFeedbackStreamDataSize, options);
        FieldToJson(jdata["maxTransformFeedbackBufferDataSize"], decoded_value.maxTransformFeedbackBufferDataSize, options);
        FieldToJson(jdata["maxTransformFeedbackBufferDataStride"], decoded_value.maxTransformFeedbackBufferDataStride, options);
        FieldToJson(jdata["transformFeedbackQueries"], decoded_value.transformFeedbackQueries, options);
        FieldToJson(jdata["transformFeedbackStreamsLinesTriangles"], decoded_value.transformFeedbackStreamsLinesTriangles, options);
        FieldToJson(jdata["transformFeedbackRasterizationStreamSelect"], decoded_value.transformFeedbackRasterizationStreamSelect, options);
        FieldToJson(jdata["transformFeedbackDraw"], decoded_value.transformFeedbackDraw, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineRasterizationStateStreamCreateFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["rasterizationStream"], decoded_value.rasterizationStream, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewHandleInfoNVX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageView"], to_hex(meta_struct.imageView), options);
        FieldToJson(jdata["descriptorType"], decoded_value.descriptorType, options);
        FieldToJson(jdata["sampler"], to_hex(meta_struct.sampler), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewAddressPropertiesNVX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceAddress"], to_hex(decoded_value.deviceAddress), options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264CapabilitiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoEncodeH264CapabilityFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(VkVideoEncodeH264InputModeFlagsEXT_t(),jdata["inputModeFlags"], decoded_value.inputModeFlags, options);
        FieldToJson(VkVideoEncodeH264OutputModeFlagsEXT_t(),jdata["outputModeFlags"], decoded_value.outputModeFlags, options);
        FieldToJson(jdata["maxPPictureL0ReferenceCount"], decoded_value.maxPPictureL0ReferenceCount, options);
        FieldToJson(jdata["maxBPictureL0ReferenceCount"], decoded_value.maxBPictureL0ReferenceCount, options);
        FieldToJson(jdata["maxL1ReferenceCount"], decoded_value.maxL1ReferenceCount, options);
        FieldToJson(jdata["motionVectorsOverPicBoundariesFlag"], decoded_value.motionVectorsOverPicBoundariesFlag, options);
        FieldToJson(jdata["maxBytesPerPicDenom"], decoded_value.maxBytesPerPicDenom, options);
        FieldToJson(jdata["maxBitsPerMbDenom"], decoded_value.maxBitsPerMbDenom, options);
        FieldToJson(jdata["log2MaxMvLengthHorizontal"], decoded_value.log2MaxMvLengthHorizontal, options);
        FieldToJson(jdata["log2MaxMvLengthVertical"], decoded_value.log2MaxMvLengthVertical, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264SessionParametersAddInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stdSPSCount"], decoded_value.stdSPSCount, options);
        FieldToJson(jdata["pStdSPSs"], meta_struct.pStdSPSs, options);
        FieldToJson(jdata["stdPPSCount"], decoded_value.stdPPSCount, options);
        FieldToJson(jdata["pStdPPSs"], meta_struct.pStdPPSs, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264SessionParametersCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxStdSPSCount"], decoded_value.maxStdSPSCount, options);
        FieldToJson(jdata["maxStdPPSCount"], decoded_value.maxStdPPSCount, options);
        FieldToJson(jdata["pParametersAddInfo"], meta_struct.pParametersAddInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264DpbSlotInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["slotIndex"], decoded_value.slotIndex, options);
        FieldToJson(jdata["pStdReferenceInfo"], meta_struct.pStdReferenceInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264ReferenceListsInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["referenceList0EntryCount"], decoded_value.referenceList0EntryCount, options);
        FieldToJson(jdata["pReferenceList0Entries"], meta_struct.pReferenceList0Entries, options);
        FieldToJson(jdata["referenceList1EntryCount"], decoded_value.referenceList1EntryCount, options);
        FieldToJson(jdata["pReferenceList1Entries"], meta_struct.pReferenceList1Entries, options);
        FieldToJson(jdata["pMemMgmtCtrlOperations"], meta_struct.pMemMgmtCtrlOperations, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264NaluSliceInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["mbCount"], decoded_value.mbCount, options);
        FieldToJson(jdata["pReferenceFinalLists"], meta_struct.pReferenceFinalLists, options);
        FieldToJson(jdata["pSliceHeaderStd"], meta_struct.pSliceHeaderStd, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264VclFrameInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pReferenceFinalLists"], meta_struct.pReferenceFinalLists, options);
        FieldToJson(jdata["naluSliceEntryCount"], decoded_value.naluSliceEntryCount, options);
        FieldToJson(jdata["pNaluSliceEntries"], meta_struct.pNaluSliceEntries, options);
        FieldToJson(jdata["pCurrentPictureInfo"], meta_struct.pCurrentPictureInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264EmitPictureParametersInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["spsId"], decoded_value.spsId, options);
        FieldToJson(jdata["emitSpsEnable"], decoded_value.emitSpsEnable, options);
        FieldToJson(jdata["ppsIdEntryCount"], decoded_value.ppsIdEntryCount, options);
        FieldToJson(jdata["ppsIdEntries"], meta_struct.ppsIdEntries, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264ProfileInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stdProfileIdc"], decoded_value.stdProfileIdc, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264RateControlInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["gopFrameCount"], decoded_value.gopFrameCount, options);
        FieldToJson(jdata["idrPeriod"], decoded_value.idrPeriod, options);
        FieldToJson(jdata["consecutiveBFrameCount"], decoded_value.consecutiveBFrameCount, options);
        FieldToJson(jdata["rateControlStructure"], decoded_value.rateControlStructure, options);
        FieldToJson(jdata["temporalLayerCount"], decoded_value.temporalLayerCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264QpEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["qpI"], decoded_value.qpI, options);
        FieldToJson(jdata["qpP"], decoded_value.qpP, options);
        FieldToJson(jdata["qpB"], decoded_value.qpB, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264FrameSizeEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["frameISize"], decoded_value.frameISize, options);
        FieldToJson(jdata["framePSize"], decoded_value.framePSize, options);
        FieldToJson(jdata["frameBSize"], decoded_value.frameBSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264RateControlLayerInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["temporalLayerId"], decoded_value.temporalLayerId, options);
        FieldToJson(jdata["useInitialRcQp"], decoded_value.useInitialRcQp, options);
        FieldToJson(jdata["initialRcQp"], meta_struct.initialRcQp, options);
        FieldToJson(jdata["useMinQp"], decoded_value.useMinQp, options);
        FieldToJson(jdata["minQp"], meta_struct.minQp, options);
        FieldToJson(jdata["useMaxQp"], decoded_value.useMaxQp, options);
        FieldToJson(jdata["maxQp"], meta_struct.maxQp, options);
        FieldToJson(jdata["useMaxFrameSize"], decoded_value.useMaxFrameSize, options);
        FieldToJson(jdata["maxFrameSize"], meta_struct.maxFrameSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265CapabilitiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkVideoEncodeH265CapabilityFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(VkVideoEncodeH265InputModeFlagsEXT_t(),jdata["inputModeFlags"], decoded_value.inputModeFlags, options);
        FieldToJson(VkVideoEncodeH265OutputModeFlagsEXT_t(),jdata["outputModeFlags"], decoded_value.outputModeFlags, options);
        FieldToJson(VkVideoEncodeH265CtbSizeFlagsEXT_t(),jdata["ctbSizes"], decoded_value.ctbSizes, options);
        FieldToJson(VkVideoEncodeH265TransformBlockSizeFlagsEXT_t(),jdata["transformBlockSizes"], decoded_value.transformBlockSizes, options);
        FieldToJson(jdata["maxPPictureL0ReferenceCount"], decoded_value.maxPPictureL0ReferenceCount, options);
        FieldToJson(jdata["maxBPictureL0ReferenceCount"], decoded_value.maxBPictureL0ReferenceCount, options);
        FieldToJson(jdata["maxL1ReferenceCount"], decoded_value.maxL1ReferenceCount, options);
        FieldToJson(jdata["maxSubLayersCount"], decoded_value.maxSubLayersCount, options);
        FieldToJson(jdata["minLog2MinLumaCodingBlockSizeMinus3"], decoded_value.minLog2MinLumaCodingBlockSizeMinus3, options);
        FieldToJson(jdata["maxLog2MinLumaCodingBlockSizeMinus3"], decoded_value.maxLog2MinLumaCodingBlockSizeMinus3, options);
        FieldToJson(jdata["minLog2MinLumaTransformBlockSizeMinus2"], decoded_value.minLog2MinLumaTransformBlockSizeMinus2, options);
        FieldToJson(jdata["maxLog2MinLumaTransformBlockSizeMinus2"], decoded_value.maxLog2MinLumaTransformBlockSizeMinus2, options);
        FieldToJson(jdata["minMaxTransformHierarchyDepthInter"], decoded_value.minMaxTransformHierarchyDepthInter, options);
        FieldToJson(jdata["maxMaxTransformHierarchyDepthInter"], decoded_value.maxMaxTransformHierarchyDepthInter, options);
        FieldToJson(jdata["minMaxTransformHierarchyDepthIntra"], decoded_value.minMaxTransformHierarchyDepthIntra, options);
        FieldToJson(jdata["maxMaxTransformHierarchyDepthIntra"], decoded_value.maxMaxTransformHierarchyDepthIntra, options);
        FieldToJson(jdata["maxDiffCuQpDeltaDepth"], decoded_value.maxDiffCuQpDeltaDepth, options);
        FieldToJson(jdata["minMaxNumMergeCand"], decoded_value.minMaxNumMergeCand, options);
        FieldToJson(jdata["maxMaxNumMergeCand"], decoded_value.maxMaxNumMergeCand, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265SessionParametersAddInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stdVPSCount"], decoded_value.stdVPSCount, options);
        FieldToJson(jdata["pStdVPSs"], meta_struct.pStdVPSs, options);
        FieldToJson(jdata["stdSPSCount"], decoded_value.stdSPSCount, options);
        FieldToJson(jdata["pStdSPSs"], meta_struct.pStdSPSs, options);
        FieldToJson(jdata["stdPPSCount"], decoded_value.stdPPSCount, options);
        FieldToJson(jdata["pStdPPSs"], meta_struct.pStdPPSs, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265SessionParametersCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxStdVPSCount"], decoded_value.maxStdVPSCount, options);
        FieldToJson(jdata["maxStdSPSCount"], decoded_value.maxStdSPSCount, options);
        FieldToJson(jdata["maxStdPPSCount"], decoded_value.maxStdPPSCount, options);
        FieldToJson(jdata["pParametersAddInfo"], meta_struct.pParametersAddInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265DpbSlotInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["slotIndex"], decoded_value.slotIndex, options);
        FieldToJson(jdata["pStdReferenceInfo"], meta_struct.pStdReferenceInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265ReferenceListsInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["referenceList0EntryCount"], decoded_value.referenceList0EntryCount, options);
        FieldToJson(jdata["pReferenceList0Entries"], meta_struct.pReferenceList0Entries, options);
        FieldToJson(jdata["referenceList1EntryCount"], decoded_value.referenceList1EntryCount, options);
        FieldToJson(jdata["pReferenceList1Entries"], meta_struct.pReferenceList1Entries, options);
        FieldToJson(jdata["pReferenceModifications"], meta_struct.pReferenceModifications, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265NaluSliceSegmentInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["ctbCount"], decoded_value.ctbCount, options);
        FieldToJson(jdata["pReferenceFinalLists"], meta_struct.pReferenceFinalLists, options);
        FieldToJson(jdata["pSliceSegmentHeaderStd"], meta_struct.pSliceSegmentHeaderStd, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265VclFrameInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pReferenceFinalLists"], meta_struct.pReferenceFinalLists, options);
        FieldToJson(jdata["naluSliceSegmentEntryCount"], decoded_value.naluSliceSegmentEntryCount, options);
        FieldToJson(jdata["pNaluSliceSegmentEntries"], meta_struct.pNaluSliceSegmentEntries, options);
        FieldToJson(jdata["pCurrentPictureInfo"], meta_struct.pCurrentPictureInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265EmitPictureParametersInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["vpsId"], decoded_value.vpsId, options);
        FieldToJson(jdata["spsId"], decoded_value.spsId, options);
        FieldToJson(jdata["emitVpsEnable"], decoded_value.emitVpsEnable, options);
        FieldToJson(jdata["emitSpsEnable"], decoded_value.emitSpsEnable, options);
        FieldToJson(jdata["ppsIdEntryCount"], decoded_value.ppsIdEntryCount, options);
        FieldToJson(jdata["ppsIdEntries"], meta_struct.ppsIdEntries, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265ProfileInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stdProfileIdc"], decoded_value.stdProfileIdc, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265RateControlInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["gopFrameCount"], decoded_value.gopFrameCount, options);
        FieldToJson(jdata["idrPeriod"], decoded_value.idrPeriod, options);
        FieldToJson(jdata["consecutiveBFrameCount"], decoded_value.consecutiveBFrameCount, options);
        FieldToJson(jdata["rateControlStructure"], decoded_value.rateControlStructure, options);
        FieldToJson(jdata["subLayerCount"], decoded_value.subLayerCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265QpEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["qpI"], decoded_value.qpI, options);
        FieldToJson(jdata["qpP"], decoded_value.qpP, options);
        FieldToJson(jdata["qpB"], decoded_value.qpB, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265FrameSizeEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["frameISize"], decoded_value.frameISize, options);
        FieldToJson(jdata["framePSize"], decoded_value.framePSize, options);
        FieldToJson(jdata["frameBSize"], decoded_value.frameBSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265RateControlLayerInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["temporalId"], decoded_value.temporalId, options);
        FieldToJson(jdata["useInitialRcQp"], decoded_value.useInitialRcQp, options);
        FieldToJson(jdata["initialRcQp"], meta_struct.initialRcQp, options);
        FieldToJson(jdata["useMinQp"], decoded_value.useMinQp, options);
        FieldToJson(jdata["minQp"], meta_struct.minQp, options);
        FieldToJson(jdata["useMaxQp"], decoded_value.useMaxQp, options);
        FieldToJson(jdata["maxQp"], meta_struct.maxQp, options);
        FieldToJson(jdata["useMaxFrameSize"], decoded_value.useMaxFrameSize, options);
        FieldToJson(jdata["maxFrameSize"], meta_struct.maxFrameSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTextureLODGatherFormatPropertiesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["supportsTextureGatherLODBiasAMD"], decoded_value.supportsTextureGatherLODBiasAMD, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShaderResourceUsageAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["numUsedVgprs"], decoded_value.numUsedVgprs, options);
        FieldToJson(jdata["numUsedSgprs"], decoded_value.numUsedSgprs, options);
        FieldToJson(jdata["ldsSizePerLocalWorkGroup"], decoded_value.ldsSizePerLocalWorkGroup, options);
        FieldToJson(jdata["ldsUsageSizeInBytes"], decoded_value.ldsUsageSizeInBytes, options);
        FieldToJson(jdata["scratchMemUsageInBytes"], decoded_value.scratchMemUsageInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShaderStatisticsInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(VkShaderStageFlags_t(),jdata["shaderStageMask"], decoded_value.shaderStageMask, options);
        FieldToJson(jdata["resourceUsage"], meta_struct.resourceUsage, options);
        FieldToJson(jdata["numPhysicalVgprs"], decoded_value.numPhysicalVgprs, options);
        FieldToJson(jdata["numPhysicalSgprs"], decoded_value.numPhysicalSgprs, options);
        FieldToJson(jdata["numAvailableVgprs"], decoded_value.numAvailableVgprs, options);
        FieldToJson(jdata["numAvailableSgprs"], decoded_value.numAvailableSgprs, options);
        FieldToJson(jdata["computeWorkGroupSize"], &meta_struct.computeWorkGroupSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkStreamDescriptorSurfaceCreateInfoGGP* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkStreamDescriptorSurfaceCreateFlagsGGP_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["streamDescriptor"], decoded_value.streamDescriptor, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["cornerSampledImage"], decoded_value.cornerSampledImage, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalImageFormatPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["imageFormatProperties"], meta_struct.imageFormatProperties, options);
        FieldToJson(VkExternalMemoryFeatureFlagsNV_t(),jdata["externalMemoryFeatures"], decoded_value.externalMemoryFeatures, options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(),jdata["exportFromImportedHandleTypes"], decoded_value.exportFromImportedHandleTypes, options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(),jdata["compatibleHandleTypes"], decoded_value.compatibleHandleTypes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalMemoryImageCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(),jdata["handleTypes"], decoded_value.handleTypes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportMemoryAllocateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(),jdata["handleTypes"], decoded_value.handleTypes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryWin32HandleInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(),jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["handle"], meta_struct.handle, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportMemoryWin32HandleInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pAttributes"], meta_struct.pAttributes, options);
        FieldToJson(jdata["dwAccess"], decoded_value.dwAccess, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["acquireCount"], decoded_value.acquireCount, options);
        FieldToJson(jdata["pAcquireSyncs"], &meta_struct.pAcquireSyncs, options);
        FieldToJson(jdata["pAcquireKeys"], meta_struct.pAcquireKeys, options);
        FieldToJson(jdata["pAcquireTimeoutMilliseconds"], meta_struct.pAcquireTimeoutMilliseconds, options);
        FieldToJson(jdata["releaseCount"], decoded_value.releaseCount, options);
        FieldToJson(jdata["pReleaseSyncs"], &meta_struct.pReleaseSyncs, options);
        FieldToJson(jdata["pReleaseKeys"], meta_struct.pReleaseKeys, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkValidationFlagsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["disabledValidationCheckCount"], decoded_value.disabledValidationCheckCount, options);
        FieldToJson(jdata["pDisabledValidationChecks"], meta_struct.pDisabledValidationChecks, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkViSurfaceCreateInfoNN* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkViSurfaceCreateFlagsNN_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["window"], meta_struct.window, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewASTCDecodeModeEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["decodeMode"], decoded_value.decodeMode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["decodeModeSharedExponent"], decoded_value.decodeModeSharedExponent, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pipelineRobustness"], decoded_value.pipelineRobustness, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineRobustnessPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["defaultRobustnessStorageBuffers"], decoded_value.defaultRobustnessStorageBuffers, options);
        FieldToJson(jdata["defaultRobustnessUniformBuffers"], decoded_value.defaultRobustnessUniformBuffers, options);
        FieldToJson(jdata["defaultRobustnessVertexInputs"], decoded_value.defaultRobustnessVertexInputs, options);
        FieldToJson(jdata["defaultRobustnessImages"], decoded_value.defaultRobustnessImages, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRobustnessCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["storageBuffers"], decoded_value.storageBuffers, options);
        FieldToJson(jdata["uniformBuffers"], decoded_value.uniformBuffers, options);
        FieldToJson(jdata["vertexInputs"], decoded_value.vertexInputs, options);
        FieldToJson(jdata["images"], decoded_value.images, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkConditionalRenderingBeginInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(VkConditionalRenderingFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["conditionalRendering"], decoded_value.conditionalRendering, options);
        FieldToJson(jdata["inheritedConditionalRendering"], decoded_value.inheritedConditionalRendering, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["conditionalRenderingEnable"], decoded_value.conditionalRenderingEnable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkViewportWScalingNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["xcoeff"], decoded_value.xcoeff, options);
        FieldToJson(jdata["ycoeff"], decoded_value.ycoeff, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportWScalingStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["viewportWScalingEnable"], decoded_value.viewportWScalingEnable, options);
        FieldToJson(jdata["viewportCount"], decoded_value.viewportCount, options);
        FieldToJson(jdata["pViewportWScalings"], meta_struct.pViewportWScalings, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilities2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["minImageCount"], decoded_value.minImageCount, options);
        FieldToJson(jdata["maxImageCount"], decoded_value.maxImageCount, options);
        FieldToJson(jdata["currentExtent"], meta_struct.currentExtent, options);
        FieldToJson(jdata["minImageExtent"], meta_struct.minImageExtent, options);
        FieldToJson(jdata["maxImageExtent"], meta_struct.maxImageExtent, options);
        FieldToJson(jdata["maxImageArrayLayers"], decoded_value.maxImageArrayLayers, options);
        FieldToJson(VkSurfaceTransformFlagsKHR_t(),jdata["supportedTransforms"], decoded_value.supportedTransforms, options);
        FieldToJson(jdata["currentTransform"], decoded_value.currentTransform, options);
        FieldToJson(VkCompositeAlphaFlagsKHR_t(),jdata["supportedCompositeAlpha"], decoded_value.supportedCompositeAlpha, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["supportedUsageFlags"], decoded_value.supportedUsageFlags, options);
        FieldToJson(VkSurfaceCounterFlagsEXT_t(),jdata["supportedSurfaceCounters"], decoded_value.supportedSurfaceCounters, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPowerInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["powerState"], decoded_value.powerState, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceEventInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceEvent"], decoded_value.deviceEvent, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayEventInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["displayEvent"], decoded_value.displayEvent, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainCounterCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkSurfaceCounterFlagsEXT_t(),jdata["surfaceCounters"], decoded_value.surfaceCounters, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRefreshCycleDurationGOOGLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["refreshDuration"], decoded_value.refreshDuration, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPastPresentationTimingGOOGLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["presentID"], decoded_value.presentID, options);
        FieldToJson(jdata["desiredPresentTime"], decoded_value.desiredPresentTime, options);
        FieldToJson(jdata["actualPresentTime"], decoded_value.actualPresentTime, options);
        FieldToJson(jdata["earliestPresentTime"], decoded_value.earliestPresentTime, options);
        FieldToJson(jdata["presentMargin"], decoded_value.presentMargin, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentTimeGOOGLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["presentID"], decoded_value.presentID, options);
        FieldToJson(jdata["desiredPresentTime"], decoded_value.desiredPresentTime, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentTimesInfoGOOGLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchainCount"], decoded_value.swapchainCount, options);
        FieldToJson(jdata["pTimes"], meta_struct.pTimes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["perViewPositionAllComponents"], decoded_value.perViewPositionAllComponents, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkViewportSwizzleNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
        FieldToJson(jdata["z"], decoded_value.z, options);
        FieldToJson(jdata["w"], decoded_value.w, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineViewportSwizzleStateCreateFlagsNV_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["viewportCount"], decoded_value.viewportCount, options);
        FieldToJson(jdata["pViewportSwizzles"], meta_struct.pViewportSwizzles, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxDiscardRectangles"], decoded_value.maxDiscardRectangles, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineDiscardRectangleStateCreateFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["discardRectangleMode"], decoded_value.discardRectangleMode, options);
        FieldToJson(jdata["discardRectangleCount"], decoded_value.discardRectangleCount, options);
        FieldToJson(jdata["pDiscardRectangles"], meta_struct.pDiscardRectangles, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["primitiveOverestimationSize"], decoded_value.primitiveOverestimationSize, options);
        FieldToJson(jdata["maxExtraPrimitiveOverestimationSize"], decoded_value.maxExtraPrimitiveOverestimationSize, options);
        FieldToJson(jdata["extraPrimitiveOverestimationSizeGranularity"], decoded_value.extraPrimitiveOverestimationSizeGranularity, options);
        FieldToJson(jdata["primitiveUnderestimation"], decoded_value.primitiveUnderestimation, options);
        FieldToJson(jdata["conservativePointAndLineRasterization"], decoded_value.conservativePointAndLineRasterization, options);
        FieldToJson(jdata["degenerateTrianglesRasterized"], decoded_value.degenerateTrianglesRasterized, options);
        FieldToJson(jdata["degenerateLinesRasterized"], decoded_value.degenerateLinesRasterized, options);
        FieldToJson(jdata["fullyCoveredFragmentShaderInputVariable"], decoded_value.fullyCoveredFragmentShaderInputVariable, options);
        FieldToJson(jdata["conservativeRasterizationPostDepthCoverage"], decoded_value.conservativeRasterizationPostDepthCoverage, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineRasterizationConservativeStateCreateFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["conservativeRasterizationMode"], decoded_value.conservativeRasterizationMode, options);
        FieldToJson(jdata["extraPrimitiveOverestimationSize"], decoded_value.extraPrimitiveOverestimationSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["depthClipEnable"], decoded_value.depthClipEnable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineRasterizationDepthClipStateCreateFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["depthClipEnable"], decoded_value.depthClipEnable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkXYColorEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkHdrMetadataEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["displayPrimaryRed"], meta_struct.displayPrimaryRed, options);
        FieldToJson(jdata["displayPrimaryGreen"], meta_struct.displayPrimaryGreen, options);
        FieldToJson(jdata["displayPrimaryBlue"], meta_struct.displayPrimaryBlue, options);
        FieldToJson(jdata["whitePoint"], meta_struct.whitePoint, options);
        FieldToJson(jdata["maxLuminance"], decoded_value.maxLuminance, options);
        FieldToJson(jdata["minLuminance"], decoded_value.minLuminance, options);
        FieldToJson(jdata["maxContentLightLevel"], decoded_value.maxContentLightLevel, options);
        FieldToJson(jdata["maxFrameAverageLightLevel"], decoded_value.maxFrameAverageLightLevel, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIOSSurfaceCreateInfoMVK* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkIOSSurfaceCreateFlagsMVK_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pView"], meta_struct.pView, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMacOSSurfaceCreateInfoMVK* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkMacOSSurfaceCreateFlagsMVK_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pView"], meta_struct.pView, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugUtilsLabelEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pLabelName"], &meta_struct.pLabelName, options);
        FieldToJson(jdata["color"], &meta_struct.color, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugUtilsObjectNameInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["objectType"], decoded_value.objectType, options);
        FieldToJson(jdata["objectHandle"], decoded_value.objectHandle, options);
        FieldToJson(jdata["pObjectName"], &meta_struct.pObjectName, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugUtilsMessengerCallbackDataEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDebugUtilsMessengerCallbackDataFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pMessageIdName"], &meta_struct.pMessageIdName, options);
        FieldToJson(jdata["messageIdNumber"], decoded_value.messageIdNumber, options);
        FieldToJson(jdata["pMessage"], &meta_struct.pMessage, options);
        FieldToJson(jdata["queueLabelCount"], decoded_value.queueLabelCount, options);
        FieldToJson(jdata["pQueueLabels"], meta_struct.pQueueLabels, options);
        FieldToJson(jdata["cmdBufLabelCount"], decoded_value.cmdBufLabelCount, options);
        FieldToJson(jdata["pCmdBufLabels"], meta_struct.pCmdBufLabels, options);
        FieldToJson(jdata["objectCount"], decoded_value.objectCount, options);
        FieldToJson(jdata["pObjects"], meta_struct.pObjects, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugUtilsMessengerCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDebugUtilsMessengerCreateFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(VkDebugUtilsMessageSeverityFlagsEXT_t(),jdata["messageSeverity"], decoded_value.messageSeverity, options);
        FieldToJson(VkDebugUtilsMessageTypeFlagsEXT_t(),jdata["messageType"], decoded_value.messageType, options);
        FieldToJson(jdata["pfnUserCallback"], to_hex(meta_struct.pfnUserCallback), options);
        FieldToJson(jdata["pUserData"], to_hex(meta_struct.pUserData), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugUtilsObjectTagInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["objectType"], decoded_value.objectType, options);
        FieldToJson(jdata["objectHandle"], decoded_value.objectHandle, options);
        FieldToJson(jdata["tagName"], decoded_value.tagName, options);
        FieldToJson(jdata["tagSize"], decoded_value.tagSize, options);
        FieldToJson(jdata["pTag"], meta_struct.pTag, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidHardwareBufferUsageANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["androidHardwareBufferUsage"], decoded_value.androidHardwareBufferUsage, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidHardwareBufferPropertiesANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["allocationSize"], decoded_value.allocationSize, options);
        FieldToJson(jdata["memoryTypeBits"], decoded_value.memoryTypeBits, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["externalFormat"], decoded_value.externalFormat, options);
        FieldToJson(VkFormatFeatureFlags_t(),jdata["formatFeatures"], decoded_value.formatFeatures, options);
        FieldToJson(jdata["samplerYcbcrConversionComponents"], meta_struct.samplerYcbcrConversionComponents, options);
        FieldToJson(jdata["suggestedYcbcrModel"], decoded_value.suggestedYcbcrModel, options);
        FieldToJson(jdata["suggestedYcbcrRange"], decoded_value.suggestedYcbcrRange, options);
        FieldToJson(jdata["suggestedXChromaOffset"], decoded_value.suggestedXChromaOffset, options);
        FieldToJson(jdata["suggestedYChromaOffset"], decoded_value.suggestedYChromaOffset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportAndroidHardwareBufferInfoANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["buffer"], meta_struct.buffer, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalFormatANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["externalFormat"], decoded_value.externalFormat, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["externalFormat"], decoded_value.externalFormat, options);
        FieldToJson(VkFormatFeatureFlags2_t(),jdata["formatFeatures"], decoded_value.formatFeatures, options);
        FieldToJson(jdata["samplerYcbcrConversionComponents"], meta_struct.samplerYcbcrConversionComponents, options);
        FieldToJson(jdata["suggestedYcbcrModel"], decoded_value.suggestedYcbcrModel, options);
        FieldToJson(jdata["suggestedYcbcrRange"], decoded_value.suggestedYcbcrRange, options);
        FieldToJson(jdata["suggestedXChromaOffset"], decoded_value.suggestedXChromaOffset, options);
        FieldToJson(jdata["suggestedYChromaOffset"], decoded_value.suggestedYChromaOffset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSampleLocationEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["x"], decoded_value.x, options);
        FieldToJson(jdata["y"], decoded_value.y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSampleLocationsInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["sampleLocationsPerPixel"], decoded_value.sampleLocationsPerPixel, options);
        FieldToJson(jdata["sampleLocationGridSize"], meta_struct.sampleLocationGridSize, options);
        FieldToJson(jdata["sampleLocationsCount"], decoded_value.sampleLocationsCount, options);
        FieldToJson(jdata["pSampleLocations"], meta_struct.pSampleLocations, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentSampleLocationsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["attachmentIndex"], decoded_value.attachmentIndex, options);
        FieldToJson(jdata["sampleLocationsInfo"], meta_struct.sampleLocationsInfo, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassSampleLocationsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["subpassIndex"], decoded_value.subpassIndex, options);
        FieldToJson(jdata["sampleLocationsInfo"], meta_struct.sampleLocationsInfo, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassSampleLocationsBeginInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["attachmentInitialSampleLocationsCount"], decoded_value.attachmentInitialSampleLocationsCount, options);
        FieldToJson(jdata["pAttachmentInitialSampleLocations"], meta_struct.pAttachmentInitialSampleLocations, options);
        FieldToJson(jdata["postSubpassSampleLocationsCount"], decoded_value.postSubpassSampleLocationsCount, options);
        FieldToJson(jdata["pPostSubpassSampleLocations"], meta_struct.pPostSubpassSampleLocations, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["sampleLocationsEnable"], decoded_value.sampleLocationsEnable, options);
        FieldToJson(jdata["sampleLocationsInfo"], meta_struct.sampleLocationsInfo, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampleLocationSampleCounts"], decoded_value.sampleLocationSampleCounts, options);
        FieldToJson(jdata["maxSampleLocationGridSize"], meta_struct.maxSampleLocationGridSize, options);
        FieldToJson(jdata["sampleLocationCoordinateRange"], &meta_struct.sampleLocationCoordinateRange, options);
        FieldToJson(jdata["sampleLocationSubPixelBits"], decoded_value.sampleLocationSubPixelBits, options);
        FieldToJson(jdata["variableSampleLocations"], decoded_value.variableSampleLocations, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultisamplePropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxSampleLocationGridSize"], meta_struct.maxSampleLocationGridSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["advancedBlendCoherentOperations"], decoded_value.advancedBlendCoherentOperations, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["advancedBlendMaxColorAttachments"], decoded_value.advancedBlendMaxColorAttachments, options);
        FieldToJson(jdata["advancedBlendIndependentBlend"], decoded_value.advancedBlendIndependentBlend, options);
        FieldToJson(jdata["advancedBlendNonPremultipliedSrcColor"], decoded_value.advancedBlendNonPremultipliedSrcColor, options);
        FieldToJson(jdata["advancedBlendNonPremultipliedDstColor"], decoded_value.advancedBlendNonPremultipliedDstColor, options);
        FieldToJson(jdata["advancedBlendCorrelatedOverlap"], decoded_value.advancedBlendCorrelatedOverlap, options);
        FieldToJson(jdata["advancedBlendAllOperations"], decoded_value.advancedBlendAllOperations, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["srcPremultiplied"], decoded_value.srcPremultiplied, options);
        FieldToJson(jdata["dstPremultiplied"], decoded_value.dstPremultiplied, options);
        FieldToJson(jdata["blendOverlap"], decoded_value.blendOverlap, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCoverageToColorStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineCoverageToColorStateCreateFlagsNV_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["coverageToColorEnable"], decoded_value.coverageToColorEnable, options);
        FieldToJson(jdata["coverageToColorLocation"], decoded_value.coverageToColorLocation, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCoverageModulationStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineCoverageModulationStateCreateFlagsNV_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["coverageModulationMode"], decoded_value.coverageModulationMode, options);
        FieldToJson(jdata["coverageModulationTableEnable"], decoded_value.coverageModulationTableEnable, options);
        FieldToJson(jdata["coverageModulationTableCount"], decoded_value.coverageModulationTableCount, options);
        FieldToJson(jdata["pCoverageModulationTable"], meta_struct.pCoverageModulationTable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderSMCount"], decoded_value.shaderSMCount, options);
        FieldToJson(jdata["shaderWarpsPerSM"], decoded_value.shaderWarpsPerSM, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderSMBuiltins"], decoded_value.shaderSMBuiltins, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrmFormatModifierPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["drmFormatModifier"], decoded_value.drmFormatModifier, options);
        FieldToJson(jdata["drmFormatModifierPlaneCount"], decoded_value.drmFormatModifierPlaneCount, options);
        FieldToJson(VkFormatFeatureFlags_t(),jdata["drmFormatModifierTilingFeatures"], decoded_value.drmFormatModifierTilingFeatures, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrmFormatModifierPropertiesListEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["drmFormatModifierCount"], decoded_value.drmFormatModifierCount, options);
        FieldToJson(jdata["pDrmFormatModifierProperties"], meta_struct.pDrmFormatModifierProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["drmFormatModifier"], decoded_value.drmFormatModifier, options);
        FieldToJson(jdata["sharingMode"], decoded_value.sharingMode, options);
        FieldToJson(jdata["queueFamilyIndexCount"], decoded_value.queueFamilyIndexCount, options);
        FieldToJson(jdata["pQueueFamilyIndices"], meta_struct.pQueueFamilyIndices, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageDrmFormatModifierListCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["drmFormatModifierCount"], decoded_value.drmFormatModifierCount, options);
        FieldToJson(jdata["pDrmFormatModifiers"], meta_struct.pDrmFormatModifiers, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["drmFormatModifier"], decoded_value.drmFormatModifier, options);
        FieldToJson(jdata["drmFormatModifierPlaneCount"], decoded_value.drmFormatModifierPlaneCount, options);
        FieldToJson(jdata["pPlaneLayouts"], meta_struct.pPlaneLayouts, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageDrmFormatModifierPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["drmFormatModifier"], decoded_value.drmFormatModifier, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrmFormatModifierProperties2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["drmFormatModifier"], decoded_value.drmFormatModifier, options);
        FieldToJson(jdata["drmFormatModifierPlaneCount"], decoded_value.drmFormatModifierPlaneCount, options);
        FieldToJson(VkFormatFeatureFlags2_t(),jdata["drmFormatModifierTilingFeatures"], decoded_value.drmFormatModifierTilingFeatures, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrmFormatModifierPropertiesList2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["drmFormatModifierCount"], decoded_value.drmFormatModifierCount, options);
        FieldToJson(jdata["pDrmFormatModifierProperties"], meta_struct.pDrmFormatModifierProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkValidationCacheCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkValidationCacheCreateFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["initialDataSize"], decoded_value.initialDataSize, options);
        FieldToJson(jdata["pInitialData"], meta_struct.pInitialData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShaderModuleValidationCacheCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["validationCache"], to_hex(meta_struct.validationCache), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShadingRatePaletteNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["shadingRatePaletteEntryCount"], decoded_value.shadingRatePaletteEntryCount, options);
        FieldToJson(jdata["pShadingRatePaletteEntries"], meta_struct.pShadingRatePaletteEntries, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shadingRateImageEnable"], decoded_value.shadingRateImageEnable, options);
        FieldToJson(jdata["viewportCount"], decoded_value.viewportCount, options);
        FieldToJson(jdata["pShadingRatePalettes"], meta_struct.pShadingRatePalettes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shadingRateImage"], decoded_value.shadingRateImage, options);
        FieldToJson(jdata["shadingRateCoarseSampleOrder"], decoded_value.shadingRateCoarseSampleOrder, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shadingRateTexelSize"], meta_struct.shadingRateTexelSize, options);
        FieldToJson(jdata["shadingRatePaletteSize"], decoded_value.shadingRatePaletteSize, options);
        FieldToJson(jdata["shadingRateMaxCoarseSamples"], decoded_value.shadingRateMaxCoarseSamples, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCoarseSampleLocationNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["pixelX"], decoded_value.pixelX, options);
        FieldToJson(jdata["pixelY"], decoded_value.pixelY, options);
        FieldToJson(jdata["sample"], decoded_value.sample, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCoarseSampleOrderCustomNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["shadingRate"], decoded_value.shadingRate, options);
        FieldToJson(jdata["sampleCount"], decoded_value.sampleCount, options);
        FieldToJson(jdata["sampleLocationCount"], decoded_value.sampleLocationCount, options);
        FieldToJson(jdata["pSampleLocations"], meta_struct.pSampleLocations, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["sampleOrderType"], decoded_value.sampleOrderType, options);
        FieldToJson(jdata["customSampleOrderCount"], decoded_value.customSampleOrderCount, options);
        FieldToJson(jdata["pCustomSampleOrders"], meta_struct.pCustomSampleOrders, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRayTracingShaderGroupCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["generalShader"], decoded_value.generalShader, options);
        FieldToJson(jdata["closestHitShader"], decoded_value.closestHitShader, options);
        FieldToJson(jdata["anyHitShader"], decoded_value.anyHitShader, options);
        FieldToJson(jdata["intersectionShader"], decoded_value.intersectionShader, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRayTracingPipelineCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["stageCount"], decoded_value.stageCount, options);
        FieldToJson(jdata["pStages"], meta_struct.pStages, options);
        FieldToJson(jdata["groupCount"], decoded_value.groupCount, options);
        FieldToJson(jdata["pGroups"], meta_struct.pGroups, options);
        FieldToJson(jdata["maxRecursionDepth"], decoded_value.maxRecursionDepth, options);
        FieldToJson(jdata["layout"], to_hex(meta_struct.layout), options);
        FieldToJson(jdata["basePipelineHandle"], to_hex(meta_struct.basePipelineHandle), options);
        FieldToJson(jdata["basePipelineIndex"], decoded_value.basePipelineIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeometryTrianglesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["vertexData"], to_hex(meta_struct.vertexData), options);
        FieldToJson(jdata["vertexOffset"], decoded_value.vertexOffset, options);
        FieldToJson(jdata["vertexCount"], decoded_value.vertexCount, options);
        FieldToJson(jdata["vertexStride"], decoded_value.vertexStride, options);
        FieldToJson(jdata["vertexFormat"], decoded_value.vertexFormat, options);
        FieldToJson(jdata["indexData"], to_hex(meta_struct.indexData), options);
        FieldToJson(jdata["indexOffset"], decoded_value.indexOffset, options);
        FieldToJson(jdata["indexCount"], decoded_value.indexCount, options);
        FieldToJson(jdata["indexType"], decoded_value.indexType, options);
        FieldToJson(jdata["transformData"], to_hex(meta_struct.transformData), options);
        FieldToJson(jdata["transformOffset"], decoded_value.transformOffset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeometryAABBNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["aabbData"], to_hex(meta_struct.aabbData), options);
        FieldToJson(jdata["numAABBs"], decoded_value.numAABBs, options);
        FieldToJson(jdata["stride"], decoded_value.stride, options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeometryDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["triangles"], meta_struct.triangles, options);
        FieldToJson(jdata["aabbs"], meta_struct.aabbs, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeometryNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["geometryType"], decoded_value.geometryType, options);
        FieldToJson(jdata["geometry"], meta_struct.geometry, options);
        FieldToJson(VkGeometryFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(VkBuildAccelerationStructureFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["instanceCount"], decoded_value.instanceCount, options);
        FieldToJson(jdata["geometryCount"], decoded_value.geometryCount, options);
        FieldToJson(jdata["pGeometries"], meta_struct.pGeometries, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["compactedSize"], decoded_value.compactedSize, options);
        FieldToJson(jdata["info"], meta_struct.info, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindAccelerationStructureMemoryInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["accelerationStructure"], to_hex(meta_struct.accelerationStructure), options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["memoryOffset"], decoded_value.memoryOffset, options);
        FieldToJson(jdata["deviceIndexCount"], decoded_value.deviceIndexCount, options);
        FieldToJson(jdata["pDeviceIndices"], meta_struct.pDeviceIndices, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteDescriptorSetAccelerationStructureNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["accelerationStructureCount"], decoded_value.accelerationStructureCount, options);
        FieldToJson(jdata["pAccelerationStructures"], &meta_struct.pAccelerationStructures, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["accelerationStructure"], to_hex(meta_struct.accelerationStructure), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderGroupHandleSize"], decoded_value.shaderGroupHandleSize, options);
        FieldToJson(jdata["maxRecursionDepth"], decoded_value.maxRecursionDepth, options);
        FieldToJson(jdata["maxShaderGroupStride"], decoded_value.maxShaderGroupStride, options);
        FieldToJson(jdata["shaderGroupBaseAlignment"], decoded_value.shaderGroupBaseAlignment, options);
        FieldToJson(jdata["maxGeometryCount"], decoded_value.maxGeometryCount, options);
        FieldToJson(jdata["maxInstanceCount"], decoded_value.maxInstanceCount, options);
        FieldToJson(jdata["maxTriangleCount"], decoded_value.maxTriangleCount, options);
        FieldToJson(jdata["maxDescriptorSetAccelerationStructures"], decoded_value.maxDescriptorSetAccelerationStructures, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTransformMatrixKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["matrix"], &meta_struct.matrix, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAabbPositionsKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["minX"], decoded_value.minX, options);
        FieldToJson(jdata["minY"], decoded_value.minY, options);
        FieldToJson(jdata["minZ"], decoded_value.minZ, options);
        FieldToJson(jdata["maxX"], decoded_value.maxX, options);
        FieldToJson(jdata["maxY"], decoded_value.maxY, options);
        FieldToJson(jdata["maxZ"], decoded_value.maxZ, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureInstanceKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["transform"], meta_struct.transform, options);
        FieldToJson(jdata["instanceCustomIndex"], decoded_value.instanceCustomIndex, options);
        FieldToJson(jdata["mask"], decoded_value.mask, options);
        FieldToJson(jdata["instanceShaderBindingTableRecordOffset"], decoded_value.instanceShaderBindingTableRecordOffset, options);
        FieldToJson(VkGeometryInstanceFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["accelerationStructureReference"], decoded_value.accelerationStructureReference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["representativeFragmentTest"], decoded_value.representativeFragmentTest, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["representativeFragmentTestEnable"], decoded_value.representativeFragmentTestEnable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageViewType"], decoded_value.imageViewType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["filterCubic"], decoded_value.filterCubic, options);
        FieldToJson(jdata["filterCubicMinmax"], decoded_value.filterCubicMinmax, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryHostPointerInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pHostPointer"], meta_struct.pHostPointer, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryHostPointerPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memoryTypeBits"], decoded_value.memoryTypeBits, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["minImportedHostPointerAlignment"], decoded_value.minImportedHostPointerAlignment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCompilerControlCreateInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineCompilerControlFlagsAMD_t(),jdata["compilerControlFlags"], decoded_value.compilerControlFlags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCalibratedTimestampInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["timeDomain"], decoded_value.timeDomain, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderEngineCount"], decoded_value.shaderEngineCount, options);
        FieldToJson(jdata["shaderArraysPerEngineCount"], decoded_value.shaderArraysPerEngineCount, options);
        FieldToJson(jdata["computeUnitsPerShaderArray"], decoded_value.computeUnitsPerShaderArray, options);
        FieldToJson(jdata["simdPerComputeUnit"], decoded_value.simdPerComputeUnit, options);
        FieldToJson(jdata["wavefrontsPerSimd"], decoded_value.wavefrontsPerSimd, options);
        FieldToJson(jdata["wavefrontSize"], decoded_value.wavefrontSize, options);
        FieldToJson(jdata["sgprsPerSimd"], decoded_value.sgprsPerSimd, options);
        FieldToJson(jdata["minSgprAllocation"], decoded_value.minSgprAllocation, options);
        FieldToJson(jdata["maxSgprAllocation"], decoded_value.maxSgprAllocation, options);
        FieldToJson(jdata["sgprAllocationGranularity"], decoded_value.sgprAllocationGranularity, options);
        FieldToJson(jdata["vgprsPerSimd"], decoded_value.vgprsPerSimd, options);
        FieldToJson(jdata["minVgprAllocation"], decoded_value.minVgprAllocation, options);
        FieldToJson(jdata["maxVgprAllocation"], decoded_value.maxVgprAllocation, options);
        FieldToJson(jdata["vgprAllocationGranularity"], decoded_value.vgprAllocationGranularity, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["overallocationBehavior"], decoded_value.overallocationBehavior, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxVertexAttribDivisor"], decoded_value.maxVertexAttribDivisor, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVertexInputBindingDivisorDescriptionEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["binding"], decoded_value.binding, options);
        FieldToJson(jdata["divisor"], decoded_value.divisor, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["vertexBindingDivisorCount"], decoded_value.vertexBindingDivisorCount, options);
        FieldToJson(jdata["pVertexBindingDivisors"], meta_struct.pVertexBindingDivisors, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["vertexAttributeInstanceRateDivisor"], decoded_value.vertexAttributeInstanceRateDivisor, options);
        FieldToJson(jdata["vertexAttributeInstanceRateZeroDivisor"], decoded_value.vertexAttributeInstanceRateZeroDivisor, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentFrameTokenGGP* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["frameToken"], decoded_value.frameToken, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["computeDerivativeGroupQuads"], decoded_value.computeDerivativeGroupQuads, options);
        FieldToJson(jdata["computeDerivativeGroupLinear"], decoded_value.computeDerivativeGroupLinear, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["taskShader"], decoded_value.taskShader, options);
        FieldToJson(jdata["meshShader"], decoded_value.meshShader, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxDrawMeshTasksCount"], decoded_value.maxDrawMeshTasksCount, options);
        FieldToJson(jdata["maxTaskWorkGroupInvocations"], decoded_value.maxTaskWorkGroupInvocations, options);
        FieldToJson(jdata["maxTaskWorkGroupSize"], &meta_struct.maxTaskWorkGroupSize, options);
        FieldToJson(jdata["maxTaskTotalMemorySize"], decoded_value.maxTaskTotalMemorySize, options);
        FieldToJson(jdata["maxTaskOutputCount"], decoded_value.maxTaskOutputCount, options);
        FieldToJson(jdata["maxMeshWorkGroupInvocations"], decoded_value.maxMeshWorkGroupInvocations, options);
        FieldToJson(jdata["maxMeshWorkGroupSize"], &meta_struct.maxMeshWorkGroupSize, options);
        FieldToJson(jdata["maxMeshTotalMemorySize"], decoded_value.maxMeshTotalMemorySize, options);
        FieldToJson(jdata["maxMeshOutputVertices"], decoded_value.maxMeshOutputVertices, options);
        FieldToJson(jdata["maxMeshOutputPrimitives"], decoded_value.maxMeshOutputPrimitives, options);
        FieldToJson(jdata["maxMeshMultiviewViewCount"], decoded_value.maxMeshMultiviewViewCount, options);
        FieldToJson(jdata["meshOutputPerVertexGranularity"], decoded_value.meshOutputPerVertexGranularity, options);
        FieldToJson(jdata["meshOutputPerPrimitiveGranularity"], decoded_value.meshOutputPerPrimitiveGranularity, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrawMeshTasksIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["taskCount"], decoded_value.taskCount, options);
        FieldToJson(jdata["firstTask"], decoded_value.firstTask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageFootprint"], decoded_value.imageFootprint, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["exclusiveScissorCount"], decoded_value.exclusiveScissorCount, options);
        FieldToJson(jdata["pExclusiveScissors"], meta_struct.pExclusiveScissors, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["exclusiveScissor"], decoded_value.exclusiveScissor, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyCheckpointPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineStageFlags_t(),jdata["checkpointExecutionStageMask"], decoded_value.checkpointExecutionStageMask, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCheckpointDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stage"], decoded_value.stage, options);
        FieldToJson(jdata["pCheckpointMarker"], meta_struct.pCheckpointMarker, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderIntegerFunctions2"], decoded_value.shaderIntegerFunctions2, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkInitializePerformanceApiInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pUserData"], to_hex(meta_struct.pUserData), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["performanceCountersSampling"], decoded_value.performanceCountersSampling, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceMarkerInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["marker"], decoded_value.marker, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceStreamMarkerInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["marker"], decoded_value.marker, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceOverrideInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["enable"], decoded_value.enable, options);
        FieldToJson(jdata["parameter"], decoded_value.parameter, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceConfigurationAcquireInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pciDomain"], decoded_value.pciDomain, options);
        FieldToJson(jdata["pciBus"], decoded_value.pciBus, options);
        FieldToJson(jdata["pciDevice"], decoded_value.pciDevice, options);
        FieldToJson(jdata["pciFunction"], decoded_value.pciFunction, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["localDimmingSupport"], decoded_value.localDimmingSupport, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["localDimmingEnable"], decoded_value.localDimmingEnable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkImagePipeSurfaceCreateFlagsFUCHSIA_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["imagePipeHandle"], decoded_value.imagePipeHandle, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMetalSurfaceCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkMetalSurfaceCreateFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pLayer"], meta_struct.pLayer, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fragmentDensityMap"], decoded_value.fragmentDensityMap, options);
        FieldToJson(jdata["fragmentDensityMapDynamic"], decoded_value.fragmentDensityMapDynamic, options);
        FieldToJson(jdata["fragmentDensityMapNonSubsampledImages"], decoded_value.fragmentDensityMapNonSubsampledImages, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["minFragmentDensityTexelSize"], meta_struct.minFragmentDensityTexelSize, options);
        FieldToJson(jdata["maxFragmentDensityTexelSize"], meta_struct.maxFragmentDensityTexelSize, options);
        FieldToJson(jdata["fragmentDensityInvocations"], decoded_value.fragmentDensityInvocations, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fragmentDensityMapAttachment"], meta_struct.fragmentDensityMapAttachment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderCoreProperties2AMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkShaderCorePropertiesFlagsAMD_t(),jdata["shaderCoreFeatures"], decoded_value.shaderCoreFeatures, options);
        FieldToJson(jdata["activeComputeUnitCount"], decoded_value.activeComputeUnitCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceCoherentMemory"], decoded_value.deviceCoherentMemory, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderImageInt64Atomics"], decoded_value.shaderImageInt64Atomics, options);
        FieldToJson(jdata["sparseImageInt64Atomics"], decoded_value.sparseImageInt64Atomics, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["heapBudget"], &meta_struct.heapBudget, options);
        FieldToJson(jdata["heapUsage"], &meta_struct.heapUsage, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memoryPriority"], decoded_value.memoryPriority, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryPriorityAllocateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["priority"], decoded_value.priority, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["dedicatedAllocationImageAliasing"], decoded_value.dedicatedAllocationImageAliasing, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["bufferDeviceAddress"], decoded_value.bufferDeviceAddress, options);
        FieldToJson(jdata["bufferDeviceAddressCaptureReplay"], decoded_value.bufferDeviceAddressCaptureReplay, options);
        FieldToJson(jdata["bufferDeviceAddressMultiDevice"], decoded_value.bufferDeviceAddressMultiDevice, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferDeviceAddressCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceAddress"], to_hex(decoded_value.deviceAddress), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkValidationFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["enabledValidationFeatureCount"], decoded_value.enabledValidationFeatureCount, options);
        FieldToJson(jdata["pEnabledValidationFeatures"], meta_struct.pEnabledValidationFeatures, options);
        FieldToJson(jdata["disabledValidationFeatureCount"], decoded_value.disabledValidationFeatureCount, options);
        FieldToJson(jdata["pDisabledValidationFeatures"], meta_struct.pDisabledValidationFeatures, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCooperativeMatrixPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["MSize"], decoded_value.MSize, options);
        FieldToJson(jdata["NSize"], decoded_value.NSize, options);
        FieldToJson(jdata["KSize"], decoded_value.KSize, options);
        FieldToJson(jdata["AType"], decoded_value.AType, options);
        FieldToJson(jdata["BType"], decoded_value.BType, options);
        FieldToJson(jdata["CType"], decoded_value.CType, options);
        FieldToJson(jdata["DType"], decoded_value.DType, options);
        FieldToJson(jdata["scope"], decoded_value.scope, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["cooperativeMatrix"], decoded_value.cooperativeMatrix, options);
        FieldToJson(jdata["cooperativeMatrixRobustBufferAccess"], decoded_value.cooperativeMatrixRobustBufferAccess, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["cooperativeMatrixSupportedStages"], decoded_value.cooperativeMatrixSupportedStages, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["coverageReductionMode"], decoded_value.coverageReductionMode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCoverageReductionStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineCoverageReductionStateCreateFlagsNV_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["coverageReductionMode"], decoded_value.coverageReductionMode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFramebufferMixedSamplesCombinationNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["coverageReductionMode"], decoded_value.coverageReductionMode, options);
        FieldToJson(jdata["rasterizationSamples"], decoded_value.rasterizationSamples, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["depthStencilSamples"], decoded_value.depthStencilSamples, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["colorSamples"], decoded_value.colorSamples, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fragmentShaderSampleInterlock"], decoded_value.fragmentShaderSampleInterlock, options);
        FieldToJson(jdata["fragmentShaderPixelInterlock"], decoded_value.fragmentShaderPixelInterlock, options);
        FieldToJson(jdata["fragmentShaderShadingRateInterlock"], decoded_value.fragmentShaderShadingRateInterlock, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["ycbcrImageArrays"], decoded_value.ycbcrImageArrays, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["provokingVertexLast"], decoded_value.provokingVertexLast, options);
        FieldToJson(jdata["transformFeedbackPreservesProvokingVertex"], decoded_value.transformFeedbackPreservesProvokingVertex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["provokingVertexModePerPipeline"], decoded_value.provokingVertexModePerPipeline, options);
        FieldToJson(jdata["transformFeedbackPreservesTriangleFanProvokingVertex"], decoded_value.transformFeedbackPreservesTriangleFanProvokingVertex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["provokingVertexMode"], decoded_value.provokingVertexMode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceFullScreenExclusiveInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fullScreenExclusive"], decoded_value.fullScreenExclusive, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fullScreenExclusiveSupported"], decoded_value.fullScreenExclusiveSupported, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["hmonitor"], meta_struct.hmonitor, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkHeadlessSurfaceCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkHeadlessSurfaceCreateFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLineRasterizationFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["rectangularLines"], decoded_value.rectangularLines, options);
        FieldToJson(jdata["bresenhamLines"], decoded_value.bresenhamLines, options);
        FieldToJson(jdata["smoothLines"], decoded_value.smoothLines, options);
        FieldToJson(jdata["stippledRectangularLines"], decoded_value.stippledRectangularLines, options);
        FieldToJson(jdata["stippledBresenhamLines"], decoded_value.stippledBresenhamLines, options);
        FieldToJson(jdata["stippledSmoothLines"], decoded_value.stippledSmoothLines, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLineRasterizationPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["lineSubPixelPrecisionBits"], decoded_value.lineSubPixelPrecisionBits, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationLineStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["lineRasterizationMode"], decoded_value.lineRasterizationMode, options);
        FieldToJson(jdata["stippledLineEnable"], decoded_value.stippledLineEnable, options);
        FieldToJson(jdata["lineStippleFactor"], decoded_value.lineStippleFactor, options);
        FieldToJson(jdata["lineStipplePattern"], decoded_value.lineStipplePattern, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderBufferFloat32Atomics"], decoded_value.shaderBufferFloat32Atomics, options);
        FieldToJson(jdata["shaderBufferFloat32AtomicAdd"], decoded_value.shaderBufferFloat32AtomicAdd, options);
        FieldToJson(jdata["shaderBufferFloat64Atomics"], decoded_value.shaderBufferFloat64Atomics, options);
        FieldToJson(jdata["shaderBufferFloat64AtomicAdd"], decoded_value.shaderBufferFloat64AtomicAdd, options);
        FieldToJson(jdata["shaderSharedFloat32Atomics"], decoded_value.shaderSharedFloat32Atomics, options);
        FieldToJson(jdata["shaderSharedFloat32AtomicAdd"], decoded_value.shaderSharedFloat32AtomicAdd, options);
        FieldToJson(jdata["shaderSharedFloat64Atomics"], decoded_value.shaderSharedFloat64Atomics, options);
        FieldToJson(jdata["shaderSharedFloat64AtomicAdd"], decoded_value.shaderSharedFloat64AtomicAdd, options);
        FieldToJson(jdata["shaderImageFloat32Atomics"], decoded_value.shaderImageFloat32Atomics, options);
        FieldToJson(jdata["shaderImageFloat32AtomicAdd"], decoded_value.shaderImageFloat32AtomicAdd, options);
        FieldToJson(jdata["sparseImageFloat32Atomics"], decoded_value.sparseImageFloat32Atomics, options);
        FieldToJson(jdata["sparseImageFloat32AtomicAdd"], decoded_value.sparseImageFloat32AtomicAdd, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["indexTypeUint8"], decoded_value.indexTypeUint8, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["extendedDynamicState"], decoded_value.extendedDynamicState, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderBufferFloat16Atomics"], decoded_value.shaderBufferFloat16Atomics, options);
        FieldToJson(jdata["shaderBufferFloat16AtomicAdd"], decoded_value.shaderBufferFloat16AtomicAdd, options);
        FieldToJson(jdata["shaderBufferFloat16AtomicMinMax"], decoded_value.shaderBufferFloat16AtomicMinMax, options);
        FieldToJson(jdata["shaderBufferFloat32AtomicMinMax"], decoded_value.shaderBufferFloat32AtomicMinMax, options);
        FieldToJson(jdata["shaderBufferFloat64AtomicMinMax"], decoded_value.shaderBufferFloat64AtomicMinMax, options);
        FieldToJson(jdata["shaderSharedFloat16Atomics"], decoded_value.shaderSharedFloat16Atomics, options);
        FieldToJson(jdata["shaderSharedFloat16AtomicAdd"], decoded_value.shaderSharedFloat16AtomicAdd, options);
        FieldToJson(jdata["shaderSharedFloat16AtomicMinMax"], decoded_value.shaderSharedFloat16AtomicMinMax, options);
        FieldToJson(jdata["shaderSharedFloat32AtomicMinMax"], decoded_value.shaderSharedFloat32AtomicMinMax, options);
        FieldToJson(jdata["shaderSharedFloat64AtomicMinMax"], decoded_value.shaderSharedFloat64AtomicMinMax, options);
        FieldToJson(jdata["shaderImageFloat32AtomicMinMax"], decoded_value.shaderImageFloat32AtomicMinMax, options);
        FieldToJson(jdata["sparseImageFloat32AtomicMinMax"], decoded_value.sparseImageFloat32AtomicMinMax, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfacePresentModeEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["presentMode"], decoded_value.presentMode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfacePresentScalingCapabilitiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPresentScalingFlagsEXT_t(),jdata["supportedPresentScaling"], decoded_value.supportedPresentScaling, options);
        FieldToJson(VkPresentGravityFlagsEXT_t(),jdata["supportedPresentGravityX"], decoded_value.supportedPresentGravityX, options);
        FieldToJson(VkPresentGravityFlagsEXT_t(),jdata["supportedPresentGravityY"], decoded_value.supportedPresentGravityY, options);
        FieldToJson(jdata["minScaledImageExtent"], meta_struct.minScaledImageExtent, options);
        FieldToJson(jdata["maxScaledImageExtent"], meta_struct.maxScaledImageExtent, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfacePresentModeCompatibilityEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["presentModeCount"], decoded_value.presentModeCount, options);
        FieldToJson(jdata["pPresentModes"], meta_struct.pPresentModes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchainMaintenance1"], decoded_value.swapchainMaintenance1, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainPresentFenceInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchainCount"], decoded_value.swapchainCount, options);
        FieldToJson(jdata["pFences"], &meta_struct.pFences, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainPresentModesCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["presentModeCount"], decoded_value.presentModeCount, options);
        FieldToJson(jdata["pPresentModes"], meta_struct.pPresentModes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainPresentModeInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchainCount"], decoded_value.swapchainCount, options);
        FieldToJson(jdata["pPresentModes"], meta_struct.pPresentModes, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainPresentScalingCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPresentScalingFlagsEXT_t(),jdata["scalingBehavior"], decoded_value.scalingBehavior, options);
        FieldToJson(VkPresentGravityFlagsEXT_t(),jdata["presentGravityX"], decoded_value.presentGravityX, options);
        FieldToJson(VkPresentGravityFlagsEXT_t(),jdata["presentGravityY"], decoded_value.presentGravityY, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkReleaseSwapchainImagesInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["swapchain"], to_hex(meta_struct.swapchain), options);
        FieldToJson(jdata["imageIndexCount"], decoded_value.imageIndexCount, options);
        FieldToJson(jdata["pImageIndices"], meta_struct.pImageIndices, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxGraphicsShaderGroupCount"], decoded_value.maxGraphicsShaderGroupCount, options);
        FieldToJson(jdata["maxIndirectSequenceCount"], decoded_value.maxIndirectSequenceCount, options);
        FieldToJson(jdata["maxIndirectCommandsTokenCount"], decoded_value.maxIndirectCommandsTokenCount, options);
        FieldToJson(jdata["maxIndirectCommandsStreamCount"], decoded_value.maxIndirectCommandsStreamCount, options);
        FieldToJson(jdata["maxIndirectCommandsTokenOffset"], decoded_value.maxIndirectCommandsTokenOffset, options);
        FieldToJson(jdata["maxIndirectCommandsStreamStride"], decoded_value.maxIndirectCommandsStreamStride, options);
        FieldToJson(jdata["minSequencesCountBufferOffsetAlignment"], decoded_value.minSequencesCountBufferOffsetAlignment, options);
        FieldToJson(jdata["minSequencesIndexBufferOffsetAlignment"], decoded_value.minSequencesIndexBufferOffsetAlignment, options);
        FieldToJson(jdata["minIndirectCommandsBufferOffsetAlignment"], decoded_value.minIndirectCommandsBufferOffsetAlignment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceGeneratedCommands"], decoded_value.deviceGeneratedCommands, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGraphicsShaderGroupCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["stageCount"], decoded_value.stageCount, options);
        FieldToJson(jdata["pStages"], meta_struct.pStages, options);
        FieldToJson(jdata["pVertexInputState"], meta_struct.pVertexInputState, options);
        FieldToJson(jdata["pTessellationState"], meta_struct.pTessellationState, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["groupCount"], decoded_value.groupCount, options);
        FieldToJson(jdata["pGroups"], meta_struct.pGroups, options);
        FieldToJson(jdata["pipelineCount"], decoded_value.pipelineCount, options);
        FieldToJson(jdata["pPipelines"], &meta_struct.pPipelines, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindShaderGroupIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["groupIndex"], decoded_value.groupIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindIndexBufferIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["bufferAddress"], to_hex(decoded_value.bufferAddress), options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["indexType"], decoded_value.indexType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindVertexBufferIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["bufferAddress"], to_hex(decoded_value.bufferAddress), options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["stride"], decoded_value.stride, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSetStateFlagsIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["data"], decoded_value.data, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsStreamNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsLayoutTokenNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["tokenType"], decoded_value.tokenType, options);
        FieldToJson(jdata["stream"], decoded_value.stream, options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["vertexBindingUnit"], decoded_value.vertexBindingUnit, options);
        FieldToJson(jdata["vertexDynamicStride"], decoded_value.vertexDynamicStride, options);
        FieldToJson(jdata["pushconstantPipelineLayout"], to_hex(meta_struct.pushconstantPipelineLayout), options);
        FieldToJson(VkShaderStageFlags_t(),jdata["pushconstantShaderStageFlags"], decoded_value.pushconstantShaderStageFlags, options);
        FieldToJson(jdata["pushconstantOffset"], decoded_value.pushconstantOffset, options);
        FieldToJson(jdata["pushconstantSize"], decoded_value.pushconstantSize, options);
        FieldToJson(VkIndirectStateFlagsNV_t(),jdata["indirectStateFlags"], decoded_value.indirectStateFlags, options);
        FieldToJson(jdata["indexTypeCount"], decoded_value.indexTypeCount, options);
        FieldToJson(jdata["pIndexTypes"], meta_struct.pIndexTypes, options);
        FieldToJson(jdata["pIndexTypeValues"], meta_struct.pIndexTypeValues, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsLayoutCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkIndirectCommandsLayoutUsageFlagsNV_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pipelineBindPoint"], decoded_value.pipelineBindPoint, options);
        FieldToJson(jdata["tokenCount"], decoded_value.tokenCount, options);
        FieldToJson(jdata["pTokens"], meta_struct.pTokens, options);
        FieldToJson(jdata["streamCount"], decoded_value.streamCount, options);
        FieldToJson(jdata["pStreamStrides"], meta_struct.pStreamStrides, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeneratedCommandsInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pipelineBindPoint"], decoded_value.pipelineBindPoint, options);
        FieldToJson(jdata["pipeline"], to_hex(meta_struct.pipeline), options);
        FieldToJson(jdata["indirectCommandsLayout"], to_hex(meta_struct.indirectCommandsLayout), options);
        FieldToJson(jdata["streamCount"], decoded_value.streamCount, options);
        FieldToJson(jdata["pStreams"], meta_struct.pStreams, options);
        FieldToJson(jdata["sequencesCount"], decoded_value.sequencesCount, options);
        FieldToJson(jdata["preprocessBuffer"], to_hex(meta_struct.preprocessBuffer), options);
        FieldToJson(jdata["preprocessOffset"], decoded_value.preprocessOffset, options);
        FieldToJson(jdata["preprocessSize"], decoded_value.preprocessSize, options);
        FieldToJson(jdata["sequencesCountBuffer"], to_hex(meta_struct.sequencesCountBuffer), options);
        FieldToJson(jdata["sequencesCountOffset"], decoded_value.sequencesCountOffset, options);
        FieldToJson(jdata["sequencesIndexBuffer"], to_hex(meta_struct.sequencesIndexBuffer), options);
        FieldToJson(jdata["sequencesIndexOffset"], decoded_value.sequencesIndexOffset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pipelineBindPoint"], decoded_value.pipelineBindPoint, options);
        FieldToJson(jdata["pipeline"], to_hex(meta_struct.pipeline), options);
        FieldToJson(jdata["indirectCommandsLayout"], to_hex(meta_struct.indirectCommandsLayout), options);
        FieldToJson(jdata["maxSequencesCount"], decoded_value.maxSequencesCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["inheritedViewportScissor2D"], decoded_value.inheritedViewportScissor2D, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferInheritanceViewportScissorInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["viewportScissor2D"], decoded_value.viewportScissor2D, options);
        FieldToJson(jdata["viewportDepthCount"], decoded_value.viewportDepthCount, options);
        FieldToJson(jdata["pViewportDepths"], meta_struct.pViewportDepths, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["texelBufferAlignment"], decoded_value.texelBufferAlignment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassTransformBeginInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["transform"], decoded_value.transform, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["transform"], decoded_value.transform, options);
        FieldToJson(jdata["renderArea"], meta_struct.renderArea, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceMemoryReport"], decoded_value.deviceMemoryReport, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceMemoryReportCallbackDataEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDeviceMemoryReportFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["memoryObjectId"], decoded_value.memoryObjectId, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["objectType"], decoded_value.objectType, options);
        FieldToJson(jdata["objectHandle"], decoded_value.objectHandle, options);
        FieldToJson(jdata["heapIndex"], decoded_value.heapIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDeviceMemoryReportFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pfnUserCallback"], to_hex(meta_struct.pfnUserCallback), options);
        FieldToJson(jdata["pUserData"], to_hex(meta_struct.pUserData), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRobustness2FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["robustBufferAccess2"], decoded_value.robustBufferAccess2, options);
        FieldToJson(jdata["robustImageAccess2"], decoded_value.robustImageAccess2, options);
        FieldToJson(jdata["nullDescriptor"], decoded_value.nullDescriptor, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRobustness2PropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["robustStorageBufferAccessSizeAlignment"], decoded_value.robustStorageBufferAccessSizeAlignment, options);
        FieldToJson(jdata["robustUniformBufferAccessSizeAlignment"], decoded_value.robustUniformBufferAccessSizeAlignment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerCustomBorderColorCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["customBorderColor"], meta_struct.customBorderColor, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxCustomBorderColorSamplers"], decoded_value.maxCustomBorderColorSamplers, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["customBorderColors"], decoded_value.customBorderColors, options);
        FieldToJson(jdata["customBorderColorWithoutFormat"], decoded_value.customBorderColorWithoutFormat, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePresentBarrierFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["presentBarrier"], decoded_value.presentBarrier, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilitiesPresentBarrierNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["presentBarrierSupported"], decoded_value.presentBarrierSupported, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainPresentBarrierCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["presentBarrierEnable"], decoded_value.presentBarrierEnable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["diagnosticsConfig"], decoded_value.diagnosticsConfig, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceDiagnosticsConfigCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDeviceDiagnosticsConfigFlagsNV_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["graphicsPipelineLibrary"], decoded_value.graphicsPipelineLibrary, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["graphicsPipelineLibraryFastLinking"], decoded_value.graphicsPipelineLibraryFastLinking, options);
        FieldToJson(jdata["graphicsPipelineLibraryIndependentInterpolationDecoration"], decoded_value.graphicsPipelineLibraryIndependentInterpolationDecoration, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGraphicsPipelineLibraryCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkGraphicsPipelineLibraryFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderEarlyAndLateFragmentTests"], decoded_value.shaderEarlyAndLateFragmentTests, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fragmentShadingRateEnums"], decoded_value.fragmentShadingRateEnums, options);
        FieldToJson(jdata["supersampleFragmentShadingRates"], decoded_value.supersampleFragmentShadingRates, options);
        FieldToJson(jdata["noInvocationFragmentShadingRates"], decoded_value.noInvocationFragmentShadingRates, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxFragmentShadingRateInvocationCount"], decoded_value.maxFragmentShadingRateInvocationCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shadingRateType"], decoded_value.shadingRateType, options);
        FieldToJson(jdata["shadingRate"], decoded_value.shadingRate, options);
        FieldToJson(jdata["combinerOps"], &meta_struct.combinerOps, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["vertexData"], meta_struct.vertexData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureMotionInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxInstances"], decoded_value.maxInstances, options);
        FieldToJson(VkAccelerationStructureMotionInfoFlagsNV_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureMatrixMotionInstanceNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["transformT0"], meta_struct.transformT0, options);
        FieldToJson(jdata["transformT1"], meta_struct.transformT1, options);
        FieldToJson(jdata["instanceCustomIndex"], decoded_value.instanceCustomIndex, options);
        FieldToJson(jdata["mask"], decoded_value.mask, options);
        FieldToJson(jdata["instanceShaderBindingTableRecordOffset"], decoded_value.instanceShaderBindingTableRecordOffset, options);
        FieldToJson(VkGeometryInstanceFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["accelerationStructureReference"], decoded_value.accelerationStructureReference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSRTDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sx"], decoded_value.sx, options);
        FieldToJson(jdata["a"], decoded_value.a, options);
        FieldToJson(jdata["b"], decoded_value.b, options);
        FieldToJson(jdata["pvx"], decoded_value.pvx, options);
        FieldToJson(jdata["sy"], decoded_value.sy, options);
        FieldToJson(jdata["c"], decoded_value.c, options);
        FieldToJson(jdata["pvy"], decoded_value.pvy, options);
        FieldToJson(jdata["sz"], decoded_value.sz, options);
        FieldToJson(jdata["pvz"], decoded_value.pvz, options);
        FieldToJson(jdata["qx"], decoded_value.qx, options);
        FieldToJson(jdata["qy"], decoded_value.qy, options);
        FieldToJson(jdata["qz"], decoded_value.qz, options);
        FieldToJson(jdata["qw"], decoded_value.qw, options);
        FieldToJson(jdata["tx"], decoded_value.tx, options);
        FieldToJson(jdata["ty"], decoded_value.ty, options);
        FieldToJson(jdata["tz"], decoded_value.tz, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureSRTMotionInstanceNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["transformT0"], meta_struct.transformT0, options);
        FieldToJson(jdata["transformT1"], meta_struct.transformT1, options);
        FieldToJson(jdata["instanceCustomIndex"], decoded_value.instanceCustomIndex, options);
        FieldToJson(jdata["mask"], decoded_value.mask, options);
        FieldToJson(jdata["instanceShaderBindingTableRecordOffset"], decoded_value.instanceShaderBindingTableRecordOffset, options);
        FieldToJson(VkGeometryInstanceFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["accelerationStructureReference"], decoded_value.accelerationStructureReference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["rayTracingMotionBlur"], decoded_value.rayTracingMotionBlur, options);
        FieldToJson(jdata["rayTracingMotionBlurPipelineTraceRaysIndirect"], decoded_value.rayTracingMotionBlurPipelineTraceRaysIndirect, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["ycbcr2plane444Formats"], decoded_value.ycbcr2plane444Formats, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fragmentDensityMapDeferred"], decoded_value.fragmentDensityMapDeferred, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["subsampledLoads"], decoded_value.subsampledLoads, options);
        FieldToJson(jdata["subsampledCoarseReconstructionEarlyAccess"], decoded_value.subsampledCoarseReconstructionEarlyAccess, options);
        FieldToJson(jdata["maxSubsampledArrayLayers"], decoded_value.maxSubsampledArrayLayers, options);
        FieldToJson(jdata["maxDescriptorSetSubsampledSamplers"], decoded_value.maxDescriptorSetSubsampledSamplers, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyCommandTransformInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["transform"], decoded_value.transform, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageCompressionControl"], decoded_value.imageCompressionControl, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageCompressionControlEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkImageCompressionFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["compressionControlPlaneCount"], decoded_value.compressionControlPlaneCount, options);
        FieldToJson(jdata["pFixedRateFlags"], meta_struct.pFixedRateFlags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubresourceLayout2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["subresourceLayout"], meta_struct.subresourceLayout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSubresource2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageSubresource"], meta_struct.imageSubresource, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageCompressionPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkImageCompressionFlagsEXT_t(),jdata["imageCompressionFlags"], decoded_value.imageCompressionFlags, options);
        FieldToJson(VkImageCompressionFixedRateFlagsEXT_t(),jdata["imageCompressionFixedRateFlags"], decoded_value.imageCompressionFixedRateFlags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["attachmentFeedbackLoopLayout"], decoded_value.attachmentFeedbackLoopLayout, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevice4444FormatsFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["formatA4R4G4B4"], decoded_value.formatA4R4G4B4, options);
        FieldToJson(jdata["formatA4B4G4R4"], decoded_value.formatA4B4G4R4, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFaultFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["deviceFault"], decoded_value.deviceFault, options);
        FieldToJson(jdata["deviceFaultVendorBinary"], decoded_value.deviceFaultVendorBinary, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceFaultCountsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["addressInfoCount"], decoded_value.addressInfoCount, options);
        FieldToJson(jdata["vendorInfoCount"], decoded_value.vendorInfoCount, options);
        FieldToJson(jdata["vendorBinarySize"], decoded_value.vendorBinarySize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceFaultAddressInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["addressType"], decoded_value.addressType, options);
        FieldToJson(jdata["reportedAddress"], to_hex(decoded_value.reportedAddress), options);
        FieldToJson(jdata["addressPrecision"], decoded_value.addressPrecision, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceFaultVendorInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["description"], &meta_struct.description, options);
        FieldToJson(jdata["vendorFaultCode"], decoded_value.vendorFaultCode, options);
        FieldToJson(jdata["vendorFaultData"], decoded_value.vendorFaultData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceFaultInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["description"], &meta_struct.description, options);
        FieldToJson(jdata["pAddressInfos"], meta_struct.pAddressInfos, options);
        FieldToJson(jdata["pVendorInfos"], meta_struct.pVendorInfos, options);
        FieldToJson(jdata["pVendorBinaryData"], meta_struct.pVendorBinaryData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["headerSize"], decoded_value.headerSize, options);
        FieldToJson(jdata["headerVersion"], decoded_value.headerVersion, options);
        FieldToJson(jdata["vendorID"], decoded_value.vendorID, options);
        FieldToJson(jdata["deviceID"], decoded_value.deviceID, options);
        FieldToJson(jdata["driverVersion"], decoded_value.driverVersion, options);
        FieldToJson(jdata["pipelineCacheUUID"], uuid_to_string(sizeof(decoded_value.pipelineCacheUUID), decoded_value.pipelineCacheUUID), options);
        FieldToJson(jdata["applicationNameOffset"], decoded_value.applicationNameOffset, options);
        FieldToJson(jdata["applicationVersion"], decoded_value.applicationVersion, options);
        FieldToJson(jdata["engineNameOffset"], decoded_value.engineNameOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["rasterizationOrderColorAttachmentAccess"], decoded_value.rasterizationOrderColorAttachmentAccess, options);
        FieldToJson(jdata["rasterizationOrderDepthAttachmentAccess"], decoded_value.rasterizationOrderDepthAttachmentAccess, options);
        FieldToJson(jdata["rasterizationOrderStencilAttachmentAccess"], decoded_value.rasterizationOrderStencilAttachmentAccess, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["formatRgba10x6WithoutYCbCrSampler"], decoded_value.formatRgba10x6WithoutYCbCrSampler, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDirectFBSurfaceCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDirectFBSurfaceCreateFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["dfb"], meta_struct.dfb, options);
        FieldToJson(jdata["surface"], meta_struct.surface, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["mutableDescriptorType"], decoded_value.mutableDescriptorType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMutableDescriptorTypeListEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["descriptorTypeCount"], decoded_value.descriptorTypeCount, options);
        FieldToJson(jdata["pDescriptorTypes"], meta_struct.pDescriptorTypes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMutableDescriptorTypeCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["mutableDescriptorTypeListCount"], decoded_value.mutableDescriptorTypeListCount, options);
        FieldToJson(jdata["pMutableDescriptorTypeLists"], meta_struct.pMutableDescriptorTypeLists, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["vertexInputDynamicState"], decoded_value.vertexInputDynamicState, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVertexInputBindingDescription2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["binding"], decoded_value.binding, options);
        FieldToJson(jdata["stride"], decoded_value.stride, options);
        FieldToJson(jdata["inputRate"], decoded_value.inputRate, options);
        FieldToJson(jdata["divisor"], decoded_value.divisor, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVertexInputAttributeDescription2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["location"], decoded_value.location, options);
        FieldToJson(jdata["binding"], decoded_value.binding, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDrmPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["hasPrimary"], decoded_value.hasPrimary, options);
        FieldToJson(jdata["hasRender"], decoded_value.hasRender, options);
        FieldToJson(jdata["primaryMajor"], decoded_value.primaryMajor, options);
        FieldToJson(jdata["primaryMinor"], decoded_value.primaryMinor, options);
        FieldToJson(jdata["renderMajor"], decoded_value.renderMajor, options);
        FieldToJson(jdata["renderMinor"], decoded_value.renderMinor, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["reportAddressBinding"], decoded_value.reportAddressBinding, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceAddressBindingCallbackDataEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDeviceAddressBindingFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["baseAddress"], to_hex(decoded_value.baseAddress), options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["bindingType"], decoded_value.bindingType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["depthClipControl"], decoded_value.depthClipControl, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["negativeOneToOne"], decoded_value.negativeOneToOne, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["primitiveTopologyListRestart"], decoded_value.primitiveTopologyListRestart, options);
        FieldToJson(jdata["primitiveTopologyPatchListRestart"], decoded_value.primitiveTopologyPatchListRestart, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryZirconHandleInfoFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["handle"], decoded_value.handle, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryZirconHandlePropertiesFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memoryTypeBits"], decoded_value.memoryTypeBits, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["semaphore"], to_hex(meta_struct.semaphore), options);
        FieldToJson(VkSemaphoreImportFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["zirconHandle"], decoded_value.zirconHandle, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["semaphore"], to_hex(meta_struct.semaphore), options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["invocationMask"], decoded_value.invocationMask, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetRemoteAddressInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["memory"], to_hex(meta_struct.memory), options);
        FieldToJson(jdata["handleType"], decoded_value.handleType, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["externalMemoryRDMA"], decoded_value.externalMemoryRDMA, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["multisampledRenderToSingleSampled"], decoded_value.multisampledRenderToSingleSampled, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassResolvePerformanceQueryEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["optimal"], decoded_value.optimal, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultisampledRenderToSingleSampledInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["multisampledRenderToSingleSampledEnable"], decoded_value.multisampledRenderToSingleSampledEnable, options);
        FieldToJson(jdata["rasterizationSamples"], decoded_value.rasterizationSamples, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["extendedDynamicState2"], decoded_value.extendedDynamicState2, options);
        FieldToJson(jdata["extendedDynamicState2LogicOp"], decoded_value.extendedDynamicState2LogicOp, options);
        FieldToJson(jdata["extendedDynamicState2PatchControlPoints"], decoded_value.extendedDynamicState2PatchControlPoints, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkScreenSurfaceCreateInfoQNX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkScreenSurfaceCreateFlagsQNX_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["context"], meta_struct.context, options);
        FieldToJson(jdata["window"], meta_struct.window, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["colorWriteEnable"], decoded_value.colorWriteEnable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineColorWriteCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["attachmentCount"], decoded_value.attachmentCount, options);
        FieldToJson(jdata["pColorWriteEnables"], meta_struct.pColorWriteEnables, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["primitivesGeneratedQuery"], decoded_value.primitivesGeneratedQuery, options);
        FieldToJson(jdata["primitivesGeneratedQueryWithRasterizerDiscard"], decoded_value.primitivesGeneratedQueryWithRasterizerDiscard, options);
        FieldToJson(jdata["primitivesGeneratedQueryWithNonZeroStreams"], decoded_value.primitivesGeneratedQueryWithNonZeroStreams, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["minLod"], decoded_value.minLod, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewMinLodCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["minLod"], decoded_value.minLod, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["multiDraw"], decoded_value.multiDraw, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxMultiDrawCount"], decoded_value.maxMultiDrawCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultiDrawInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["firstVertex"], decoded_value.firstVertex, options);
        FieldToJson(jdata["vertexCount"], decoded_value.vertexCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultiDrawIndexedInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["firstIndex"], decoded_value.firstIndex, options);
        FieldToJson(jdata["indexCount"], decoded_value.indexCount, options);
        FieldToJson(jdata["vertexOffset"], decoded_value.vertexOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["image2DViewOf3D"], decoded_value.image2DViewOf3D, options);
        FieldToJson(jdata["sampler2DViewOf3D"], decoded_value.sampler2DViewOf3D, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapUsageEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["count"], decoded_value.count, options);
        FieldToJson(jdata["subdivisionLevel"], decoded_value.subdivisionLevel, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapBuildInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(VkBuildMicromapFlagsEXT_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["dstMicromap"], to_hex(meta_struct.dstMicromap), options);
        FieldToJson(jdata["usageCountsCount"], decoded_value.usageCountsCount, options);
        FieldToJson(jdata["pUsageCounts"], meta_struct.pUsageCounts, options);
        FieldToJson(jdata["ppUsageCounts"], meta_struct.ppUsageCounts, options);
        FieldToJson(jdata["data"], meta_struct.data, options);
        FieldToJson(jdata["scratchData"], meta_struct.scratchData, options);
        FieldToJson(jdata["triangleArray"], meta_struct.triangleArray, options);
        FieldToJson(jdata["triangleArrayStride"], decoded_value.triangleArrayStride, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkMicromapCreateFlagsEXT_t(),jdata["createFlags"], decoded_value.createFlags, options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["deviceAddress"], to_hex(decoded_value.deviceAddress), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["micromap"], decoded_value.micromap, options);
        FieldToJson(jdata["micromapCaptureReplay"], decoded_value.micromapCaptureReplay, options);
        FieldToJson(jdata["micromapHostCommands"], decoded_value.micromapHostCommands, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxOpacity2StateSubdivisionLevel"], decoded_value.maxOpacity2StateSubdivisionLevel, options);
        FieldToJson(jdata["maxOpacity4StateSubdivisionLevel"], decoded_value.maxOpacity4StateSubdivisionLevel, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapVersionInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pVersionData"], meta_struct.pVersionData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMicromapToMemoryInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["src"], to_hex(meta_struct.src), options);
        FieldToJson(jdata["dst"], meta_struct.dst, options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMemoryToMicromapInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["src"], meta_struct.src, options);
        FieldToJson(jdata["dst"], to_hex(meta_struct.dst), options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMicromapInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["src"], to_hex(meta_struct.src), options);
        FieldToJson(jdata["dst"], to_hex(meta_struct.dst), options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapBuildSizesInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["micromapSize"], decoded_value.micromapSize, options);
        FieldToJson(jdata["buildScratchSize"], decoded_value.buildScratchSize, options);
        FieldToJson(jdata["discardable"], decoded_value.discardable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["indexType"], decoded_value.indexType, options);
        FieldToJson(jdata["indexBuffer"], meta_struct.indexBuffer, options);
        FieldToJson(jdata["indexStride"], decoded_value.indexStride, options);
        FieldToJson(jdata["baseTriangle"], decoded_value.baseTriangle, options);
        FieldToJson(jdata["usageCountsCount"], decoded_value.usageCountsCount, options);
        FieldToJson(jdata["pUsageCounts"], meta_struct.pUsageCounts, options);
        FieldToJson(jdata["ppUsageCounts"], meta_struct.ppUsageCounts, options);
        FieldToJson(jdata["micromap"], to_hex(meta_struct.micromap), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapTriangleEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["dataOffset"], decoded_value.dataOffset, options);
        FieldToJson(jdata["subdivisionLevel"], decoded_value.subdivisionLevel, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["clustercullingShader"], decoded_value.clustercullingShader, options);
        FieldToJson(jdata["multiviewClusterCullingShader"], decoded_value.multiviewClusterCullingShader, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxWorkGroupCount"], &meta_struct.maxWorkGroupCount, options);
        FieldToJson(jdata["maxWorkGroupSize"], &meta_struct.maxWorkGroupSize, options);
        FieldToJson(jdata["maxOutputClusterCount"], decoded_value.maxOutputClusterCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["borderColorSwizzle"], decoded_value.borderColorSwizzle, options);
        FieldToJson(jdata["borderColorSwizzleFromImage"], decoded_value.borderColorSwizzleFromImage, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["components"], meta_struct.components, options);
        FieldToJson(jdata["srgb"], decoded_value.srgb, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pageableDeviceLocalMemory"], decoded_value.pageableDeviceLocalMemory, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderCorePropertiesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pixelRate"], decoded_value.pixelRate, options);
        FieldToJson(jdata["texelRate"], decoded_value.texelRate, options);
        FieldToJson(jdata["fmaRate"], decoded_value.fmaRate, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageSlicedViewOf3D"], decoded_value.imageSlicedViewOf3D, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewSlicedCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["sliceOffset"], decoded_value.sliceOffset, options);
        FieldToJson(jdata["sliceCount"], decoded_value.sliceCount, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["descriptorSetHostMapping"], decoded_value.descriptorSetHostMapping, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetBindingReferenceVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["descriptorSetLayout"], to_hex(meta_struct.descriptorSetLayout), options);
        FieldToJson(jdata["binding"], decoded_value.binding, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["descriptorOffset"], decoded_value.descriptorOffset, options);
        FieldToJson(jdata["descriptorSize"], decoded_value.descriptorSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["depthClampZeroOne"], decoded_value.depthClampZeroOne, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["nonSeamlessCubeMap"], decoded_value.nonSeamlessCubeMap, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fragmentDensityMapOffset"], decoded_value.fragmentDensityMapOffset, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fragmentDensityOffsetGranularity"], meta_struct.fragmentDensityOffsetGranularity, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["fragmentDensityOffsetCount"], decoded_value.fragmentDensityOffsetCount, options);
        FieldToJson(jdata["pFragmentDensityOffsets"], meta_struct.pFragmentDensityOffsets, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["linearColorAttachment"], decoded_value.linearColorAttachment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["imageCompressionControlSwapchain"], decoded_value.imageCompressionControlSwapchain, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewSampleWeightCreateInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["filterCenter"], meta_struct.filterCenter, options);
        FieldToJson(jdata["filterSize"], meta_struct.filterSize, options);
        FieldToJson(jdata["numPhases"], decoded_value.numPhases, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["textureSampleWeighted"], decoded_value.textureSampleWeighted, options);
        FieldToJson(jdata["textureBoxFilter"], decoded_value.textureBoxFilter, options);
        FieldToJson(jdata["textureBlockMatch"], decoded_value.textureBlockMatch, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxWeightFilterPhases"], decoded_value.maxWeightFilterPhases, options);
        FieldToJson(jdata["maxWeightFilterDimension"], meta_struct.maxWeightFilterDimension, options);
        FieldToJson(jdata["maxBlockMatchRegion"], meta_struct.maxBlockMatchRegion, options);
        FieldToJson(jdata["maxBoxFilterBlockSize"], meta_struct.maxBoxFilterBlockSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["extendedDynamicState3TessellationDomainOrigin"], decoded_value.extendedDynamicState3TessellationDomainOrigin, options);
        FieldToJson(jdata["extendedDynamicState3DepthClampEnable"], decoded_value.extendedDynamicState3DepthClampEnable, options);
        FieldToJson(jdata["extendedDynamicState3PolygonMode"], decoded_value.extendedDynamicState3PolygonMode, options);
        FieldToJson(jdata["extendedDynamicState3RasterizationSamples"], decoded_value.extendedDynamicState3RasterizationSamples, options);
        FieldToJson(jdata["extendedDynamicState3SampleMask"], decoded_value.extendedDynamicState3SampleMask, options);
        FieldToJson(jdata["extendedDynamicState3AlphaToCoverageEnable"], decoded_value.extendedDynamicState3AlphaToCoverageEnable, options);
        FieldToJson(jdata["extendedDynamicState3AlphaToOneEnable"], decoded_value.extendedDynamicState3AlphaToOneEnable, options);
        FieldToJson(jdata["extendedDynamicState3LogicOpEnable"], decoded_value.extendedDynamicState3LogicOpEnable, options);
        FieldToJson(jdata["extendedDynamicState3ColorBlendEnable"], decoded_value.extendedDynamicState3ColorBlendEnable, options);
        FieldToJson(jdata["extendedDynamicState3ColorBlendEquation"], decoded_value.extendedDynamicState3ColorBlendEquation, options);
        FieldToJson(jdata["extendedDynamicState3ColorWriteMask"], decoded_value.extendedDynamicState3ColorWriteMask, options);
        FieldToJson(jdata["extendedDynamicState3RasterizationStream"], decoded_value.extendedDynamicState3RasterizationStream, options);
        FieldToJson(jdata["extendedDynamicState3ConservativeRasterizationMode"], decoded_value.extendedDynamicState3ConservativeRasterizationMode, options);
        FieldToJson(jdata["extendedDynamicState3ExtraPrimitiveOverestimationSize"], decoded_value.extendedDynamicState3ExtraPrimitiveOverestimationSize, options);
        FieldToJson(jdata["extendedDynamicState3DepthClipEnable"], decoded_value.extendedDynamicState3DepthClipEnable, options);
        FieldToJson(jdata["extendedDynamicState3SampleLocationsEnable"], decoded_value.extendedDynamicState3SampleLocationsEnable, options);
        FieldToJson(jdata["extendedDynamicState3ColorBlendAdvanced"], decoded_value.extendedDynamicState3ColorBlendAdvanced, options);
        FieldToJson(jdata["extendedDynamicState3ProvokingVertexMode"], decoded_value.extendedDynamicState3ProvokingVertexMode, options);
        FieldToJson(jdata["extendedDynamicState3LineRasterizationMode"], decoded_value.extendedDynamicState3LineRasterizationMode, options);
        FieldToJson(jdata["extendedDynamicState3LineStippleEnable"], decoded_value.extendedDynamicState3LineStippleEnable, options);
        FieldToJson(jdata["extendedDynamicState3DepthClipNegativeOneToOne"], decoded_value.extendedDynamicState3DepthClipNegativeOneToOne, options);
        FieldToJson(jdata["extendedDynamicState3ViewportWScalingEnable"], decoded_value.extendedDynamicState3ViewportWScalingEnable, options);
        FieldToJson(jdata["extendedDynamicState3ViewportSwizzle"], decoded_value.extendedDynamicState3ViewportSwizzle, options);
        FieldToJson(jdata["extendedDynamicState3CoverageToColorEnable"], decoded_value.extendedDynamicState3CoverageToColorEnable, options);
        FieldToJson(jdata["extendedDynamicState3CoverageToColorLocation"], decoded_value.extendedDynamicState3CoverageToColorLocation, options);
        FieldToJson(jdata["extendedDynamicState3CoverageModulationMode"], decoded_value.extendedDynamicState3CoverageModulationMode, options);
        FieldToJson(jdata["extendedDynamicState3CoverageModulationTableEnable"], decoded_value.extendedDynamicState3CoverageModulationTableEnable, options);
        FieldToJson(jdata["extendedDynamicState3CoverageModulationTable"], decoded_value.extendedDynamicState3CoverageModulationTable, options);
        FieldToJson(jdata["extendedDynamicState3CoverageReductionMode"], decoded_value.extendedDynamicState3CoverageReductionMode, options);
        FieldToJson(jdata["extendedDynamicState3RepresentativeFragmentTestEnable"], decoded_value.extendedDynamicState3RepresentativeFragmentTestEnable, options);
        FieldToJson(jdata["extendedDynamicState3ShadingRateImageEnable"], decoded_value.extendedDynamicState3ShadingRateImageEnable, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["dynamicPrimitiveTopologyUnrestricted"], decoded_value.dynamicPrimitiveTopologyUnrestricted, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkColorBlendEquationEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["srcColorBlendFactor"], decoded_value.srcColorBlendFactor, options);
        FieldToJson(jdata["dstColorBlendFactor"], decoded_value.dstColorBlendFactor, options);
        FieldToJson(jdata["colorBlendOp"], decoded_value.colorBlendOp, options);
        FieldToJson(jdata["srcAlphaBlendFactor"], decoded_value.srcAlphaBlendFactor, options);
        FieldToJson(jdata["dstAlphaBlendFactor"], decoded_value.dstAlphaBlendFactor, options);
        FieldToJson(jdata["alphaBlendOp"], decoded_value.alphaBlendOp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkColorBlendAdvancedEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["advancedBlendOp"], decoded_value.advancedBlendOp, options);
        FieldToJson(jdata["srcPremultiplied"], decoded_value.srcPremultiplied, options);
        FieldToJson(jdata["dstPremultiplied"], decoded_value.dstPremultiplied, options);
        FieldToJson(jdata["blendOverlap"], decoded_value.blendOverlap, options);
        FieldToJson(jdata["clampResults"], decoded_value.clampResults, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["subpassMergeFeedback"], decoded_value.subpassMergeFeedback, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassCreationControlEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["disallowMerging"], decoded_value.disallowMerging, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassCreationFeedbackInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["postMergeSubpassCount"], decoded_value.postMergeSubpassCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassCreationFeedbackCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pRenderPassFeedback"], meta_struct.pRenderPassFeedback, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassSubpassFeedbackInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["subpassMergeStatus"], decoded_value.subpassMergeStatus, options);
        FieldToJson(jdata["description"], &meta_struct.description, options);
        FieldToJson(jdata["postMergeIndex"], decoded_value.postMergeIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pSubpassFeedback"], meta_struct.pSubpassFeedback, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDirectDriverLoadingInfoLUNARG* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkDirectDriverLoadingFlagsLUNARG_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pfnGetInstanceProcAddr"], to_hex(meta_struct.pfnGetInstanceProcAddr), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDirectDriverLoadingListLUNARG* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["driverCount"], decoded_value.driverCount, options);
        FieldToJson(jdata["pDrivers"], meta_struct.pDrivers, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderModuleIdentifier"], decoded_value.shaderModuleIdentifier, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderModuleIdentifierAlgorithmUUID"], uuid_to_string(sizeof(decoded_value.shaderModuleIdentifierAlgorithmUUID), decoded_value.shaderModuleIdentifierAlgorithmUUID), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["identifierSize"], decoded_value.identifierSize, options);
        FieldToJson(jdata["pIdentifier"], meta_struct.pIdentifier, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShaderModuleIdentifierEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["identifierSize"], decoded_value.identifierSize, options);
        FieldToJson(jdata["identifier"], &meta_struct.identifier, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["opticalFlow"], decoded_value.opticalFlow, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkOpticalFlowGridSizeFlagsNV_t(),jdata["supportedOutputGridSizes"], decoded_value.supportedOutputGridSizes, options);
        FieldToJson(VkOpticalFlowGridSizeFlagsNV_t(),jdata["supportedHintGridSizes"], decoded_value.supportedHintGridSizes, options);
        FieldToJson(jdata["hintSupported"], decoded_value.hintSupported, options);
        FieldToJson(jdata["costSupported"], decoded_value.costSupported, options);
        FieldToJson(jdata["bidirectionalFlowSupported"], decoded_value.bidirectionalFlowSupported, options);
        FieldToJson(jdata["globalFlowSupported"], decoded_value.globalFlowSupported, options);
        FieldToJson(jdata["minWidth"], decoded_value.minWidth, options);
        FieldToJson(jdata["minHeight"], decoded_value.minHeight, options);
        FieldToJson(jdata["maxWidth"], decoded_value.maxWidth, options);
        FieldToJson(jdata["maxHeight"], decoded_value.maxHeight, options);
        FieldToJson(jdata["maxNumRegionsOfInterest"], decoded_value.maxNumRegionsOfInterest, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOpticalFlowImageFormatInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkOpticalFlowUsageFlagsNV_t(),jdata["usage"], decoded_value.usage, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOpticalFlowImageFormatPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["format"], decoded_value.format, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOpticalFlowSessionCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["imageFormat"], decoded_value.imageFormat, options);
        FieldToJson(jdata["flowVectorFormat"], decoded_value.flowVectorFormat, options);
        FieldToJson(jdata["costFormat"], decoded_value.costFormat, options);
        FieldToJson(VkOpticalFlowGridSizeFlagsNV_t(),jdata["outputGridSize"], decoded_value.outputGridSize, options);
        FieldToJson(VkOpticalFlowGridSizeFlagsNV_t(),jdata["hintGridSize"], decoded_value.hintGridSize, options);
        FieldToJson(jdata["performanceLevel"], decoded_value.performanceLevel, options);
        FieldToJson(VkOpticalFlowSessionCreateFlagsNV_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["id"], decoded_value.id, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["pPrivateData"], meta_struct.pPrivateData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOpticalFlowExecuteInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkOpticalFlowExecuteFlagsNV_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["regionCount"], decoded_value.regionCount, options);
        FieldToJson(jdata["pRegions"], meta_struct.pRegions, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["legacyDithering"], decoded_value.legacyDithering, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pipelineProtectedAccess"], decoded_value.pipelineProtectedAccess, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["tileProperties"], decoded_value.tileProperties, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTilePropertiesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["tileSize"], meta_struct.tileSize, options);
        FieldToJson(jdata["apronSize"], meta_struct.apronSize, options);
        FieldToJson(jdata["origin"], meta_struct.origin, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["amigoProfiling"], decoded_value.amigoProfiling, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAmigoProfilingSubmitInfoSEC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["firstDrawTimestamp"], decoded_value.firstDrawTimestamp, options);
        FieldToJson(jdata["swapBufferTimestamp"], decoded_value.swapBufferTimestamp, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["multiviewPerViewViewports"], decoded_value.multiviewPerViewViewports, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["rayTracingInvocationReorderReorderingHint"], decoded_value.rayTracingInvocationReorderReorderingHint, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["rayTracingInvocationReorder"], decoded_value.rayTracingInvocationReorder, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderCoreBuiltins"], decoded_value.shaderCoreBuiltins, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderCoreMask"], decoded_value.shaderCoreMask, options);
        FieldToJson(jdata["shaderCoreCount"], decoded_value.shaderCoreCount, options);
        FieldToJson(jdata["shaderWarpsPerCore"], decoded_value.shaderWarpsPerCore, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pipelineLibraryGroupHandles"], decoded_value.pipelineLibraryGroupHandles, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["multiviewPerViewRenderAreas"], decoded_value.multiviewPerViewRenderAreas, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["perViewRenderAreaCount"], decoded_value.perViewRenderAreaCount, options);
        FieldToJson(jdata["pPerViewRenderAreas"], meta_struct.pPerViewRenderAreas, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureBuildRangeInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["primitiveCount"], decoded_value.primitiveCount, options);
        FieldToJson(jdata["primitiveOffset"], decoded_value.primitiveOffset, options);
        FieldToJson(jdata["firstVertex"], decoded_value.firstVertex, options);
        FieldToJson(jdata["transformOffset"], decoded_value.transformOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["vertexFormat"], decoded_value.vertexFormat, options);
        FieldToJson(jdata["vertexData"], meta_struct.vertexData, options);
        FieldToJson(jdata["vertexStride"], decoded_value.vertexStride, options);
        FieldToJson(jdata["maxVertex"], decoded_value.maxVertex, options);
        FieldToJson(jdata["indexType"], decoded_value.indexType, options);
        FieldToJson(jdata["indexData"], meta_struct.indexData, options);
        FieldToJson(jdata["transformData"], meta_struct.transformData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometryAabbsDataKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["data"], meta_struct.data, options);
        FieldToJson(jdata["stride"], decoded_value.stride, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometryInstancesDataKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["arrayOfPointers"], decoded_value.arrayOfPointers, options);
        FieldToJson(jdata["data"], meta_struct.data, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureBuildGeometryInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(VkBuildAccelerationStructureFlagsKHR_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["srcAccelerationStructure"], to_hex(meta_struct.srcAccelerationStructure), options);
        FieldToJson(jdata["dstAccelerationStructure"], to_hex(meta_struct.dstAccelerationStructure), options);
        FieldToJson(jdata["geometryCount"], decoded_value.geometryCount, options);
        FieldToJson(jdata["pGeometries"], meta_struct.pGeometries, options);
        FieldToJson(jdata["ppGeometries"], meta_struct.ppGeometries, options);
        FieldToJson(jdata["scratchData"], meta_struct.scratchData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkAccelerationStructureCreateFlagsKHR_t(),jdata["createFlags"], decoded_value.createFlags, options);
        FieldToJson(jdata["buffer"], to_hex(meta_struct.buffer), options);
        FieldToJson(jdata["offset"], decoded_value.offset, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["deviceAddress"], to_hex(decoded_value.deviceAddress), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteDescriptorSetAccelerationStructureKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["accelerationStructureCount"], decoded_value.accelerationStructureCount, options);
        FieldToJson(jdata["pAccelerationStructures"], &meta_struct.pAccelerationStructures, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["accelerationStructure"], decoded_value.accelerationStructure, options);
        FieldToJson(jdata["accelerationStructureCaptureReplay"], decoded_value.accelerationStructureCaptureReplay, options);
        FieldToJson(jdata["accelerationStructureIndirectBuild"], decoded_value.accelerationStructureIndirectBuild, options);
        FieldToJson(jdata["accelerationStructureHostCommands"], decoded_value.accelerationStructureHostCommands, options);
        FieldToJson(jdata["descriptorBindingAccelerationStructureUpdateAfterBind"], decoded_value.descriptorBindingAccelerationStructureUpdateAfterBind, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxGeometryCount"], decoded_value.maxGeometryCount, options);
        FieldToJson(jdata["maxInstanceCount"], decoded_value.maxInstanceCount, options);
        FieldToJson(jdata["maxPrimitiveCount"], decoded_value.maxPrimitiveCount, options);
        FieldToJson(jdata["maxPerStageDescriptorAccelerationStructures"], decoded_value.maxPerStageDescriptorAccelerationStructures, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindAccelerationStructures"], decoded_value.maxPerStageDescriptorUpdateAfterBindAccelerationStructures, options);
        FieldToJson(jdata["maxDescriptorSetAccelerationStructures"], decoded_value.maxDescriptorSetAccelerationStructures, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindAccelerationStructures"], decoded_value.maxDescriptorSetUpdateAfterBindAccelerationStructures, options);
        FieldToJson(jdata["minAccelerationStructureScratchOffsetAlignment"], decoded_value.minAccelerationStructureScratchOffsetAlignment, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureDeviceAddressInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["accelerationStructure"], to_hex(meta_struct.accelerationStructure), options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureVersionInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["pVersionData"], meta_struct.pVersionData, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["src"], to_hex(meta_struct.src), options);
        FieldToJson(jdata["dst"], meta_struct.dst, options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["src"], meta_struct.src, options);
        FieldToJson(jdata["dst"], to_hex(meta_struct.dst), options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyAccelerationStructureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["src"], to_hex(meta_struct.src), options);
        FieldToJson(jdata["dst"], to_hex(meta_struct.dst), options);
        FieldToJson(jdata["mode"], decoded_value.mode, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureBuildSizesInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["accelerationStructureSize"], decoded_value.accelerationStructureSize, options);
        FieldToJson(jdata["updateScratchSize"], decoded_value.updateScratchSize, options);
        FieldToJson(jdata["buildScratchSize"], decoded_value.buildScratchSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRayTracingShaderGroupCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["type"], decoded_value.type, options);
        FieldToJson(jdata["generalShader"], decoded_value.generalShader, options);
        FieldToJson(jdata["closestHitShader"], decoded_value.closestHitShader, options);
        FieldToJson(jdata["anyHitShader"], decoded_value.anyHitShader, options);
        FieldToJson(jdata["intersectionShader"], decoded_value.intersectionShader, options);
        FieldToJson(jdata["pShaderGroupCaptureReplayHandle"], meta_struct.pShaderGroupCaptureReplayHandle, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxPipelineRayPayloadSize"], decoded_value.maxPipelineRayPayloadSize, options);
        FieldToJson(jdata["maxPipelineRayHitAttributeSize"], decoded_value.maxPipelineRayHitAttributeSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRayTracingPipelineCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(VkPipelineCreateFlags_t(),jdata["flags"], decoded_value.flags, options);
        FieldToJson(jdata["stageCount"], decoded_value.stageCount, options);
        FieldToJson(jdata["pStages"], meta_struct.pStages, options);
        FieldToJson(jdata["groupCount"], decoded_value.groupCount, options);
        FieldToJson(jdata["pGroups"], meta_struct.pGroups, options);
        FieldToJson(jdata["maxPipelineRayRecursionDepth"], decoded_value.maxPipelineRayRecursionDepth, options);
        FieldToJson(jdata["pLibraryInfo"], meta_struct.pLibraryInfo, options);
        FieldToJson(jdata["pLibraryInterface"], meta_struct.pLibraryInterface, options);
        FieldToJson(jdata["pDynamicState"], meta_struct.pDynamicState, options);
        FieldToJson(jdata["layout"], to_hex(meta_struct.layout), options);
        FieldToJson(jdata["basePipelineHandle"], to_hex(meta_struct.basePipelineHandle), options);
        FieldToJson(jdata["basePipelineIndex"], decoded_value.basePipelineIndex, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["rayTracingPipeline"], decoded_value.rayTracingPipeline, options);
        FieldToJson(jdata["rayTracingPipelineShaderGroupHandleCaptureReplay"], decoded_value.rayTracingPipelineShaderGroupHandleCaptureReplay, options);
        FieldToJson(jdata["rayTracingPipelineShaderGroupHandleCaptureReplayMixed"], decoded_value.rayTracingPipelineShaderGroupHandleCaptureReplayMixed, options);
        FieldToJson(jdata["rayTracingPipelineTraceRaysIndirect"], decoded_value.rayTracingPipelineTraceRaysIndirect, options);
        FieldToJson(jdata["rayTraversalPrimitiveCulling"], decoded_value.rayTraversalPrimitiveCulling, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["shaderGroupHandleSize"], decoded_value.shaderGroupHandleSize, options);
        FieldToJson(jdata["maxRayRecursionDepth"], decoded_value.maxRayRecursionDepth, options);
        FieldToJson(jdata["maxShaderGroupStride"], decoded_value.maxShaderGroupStride, options);
        FieldToJson(jdata["shaderGroupBaseAlignment"], decoded_value.shaderGroupBaseAlignment, options);
        FieldToJson(jdata["shaderGroupHandleCaptureReplaySize"], decoded_value.shaderGroupHandleCaptureReplaySize, options);
        FieldToJson(jdata["maxRayDispatchInvocationCount"], decoded_value.maxRayDispatchInvocationCount, options);
        FieldToJson(jdata["shaderGroupHandleAlignment"], decoded_value.shaderGroupHandleAlignment, options);
        FieldToJson(jdata["maxRayHitAttributeSize"], decoded_value.maxRayHitAttributeSize, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkStridedDeviceAddressRegionKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["deviceAddress"], to_hex(decoded_value.deviceAddress), options);
        FieldToJson(jdata["stride"], decoded_value.stride, options);
        FieldToJson(jdata["size"], decoded_value.size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTraceRaysIndirectCommandKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["width"], decoded_value.width, options);
        FieldToJson(jdata["height"], decoded_value.height, options);
        FieldToJson(jdata["depth"], decoded_value.depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayQueryFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["rayQuery"], decoded_value.rayQuery, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["taskShader"], decoded_value.taskShader, options);
        FieldToJson(jdata["meshShader"], decoded_value.meshShader, options);
        FieldToJson(jdata["multiviewMeshShader"], decoded_value.multiviewMeshShader, options);
        FieldToJson(jdata["primitiveFragmentShadingRateMeshShader"], decoded_value.primitiveFragmentShadingRateMeshShader, options);
        FieldToJson(jdata["meshShaderQueries"], decoded_value.meshShaderQueries, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["sType"], decoded_value.sType, options);
        FieldToJson(jdata["maxTaskWorkGroupTotalCount"], decoded_value.maxTaskWorkGroupTotalCount, options);
        FieldToJson(jdata["maxTaskWorkGroupCount"], &meta_struct.maxTaskWorkGroupCount, options);
        FieldToJson(jdata["maxTaskWorkGroupInvocations"], decoded_value.maxTaskWorkGroupInvocations, options);
        FieldToJson(jdata["maxTaskWorkGroupSize"], &meta_struct.maxTaskWorkGroupSize, options);
        FieldToJson(jdata["maxTaskPayloadSize"], decoded_value.maxTaskPayloadSize, options);
        FieldToJson(jdata["maxTaskSharedMemorySize"], decoded_value.maxTaskSharedMemorySize, options);
        FieldToJson(jdata["maxTaskPayloadAndSharedMemorySize"], decoded_value.maxTaskPayloadAndSharedMemorySize, options);
        FieldToJson(jdata["maxMeshWorkGroupTotalCount"], decoded_value.maxMeshWorkGroupTotalCount, options);
        FieldToJson(jdata["maxMeshWorkGroupCount"], &meta_struct.maxMeshWorkGroupCount, options);
        FieldToJson(jdata["maxMeshWorkGroupInvocations"], decoded_value.maxMeshWorkGroupInvocations, options);
        FieldToJson(jdata["maxMeshWorkGroupSize"], &meta_struct.maxMeshWorkGroupSize, options);
        FieldToJson(jdata["maxMeshSharedMemorySize"], decoded_value.maxMeshSharedMemorySize, options);
        FieldToJson(jdata["maxMeshPayloadAndSharedMemorySize"], decoded_value.maxMeshPayloadAndSharedMemorySize, options);
        FieldToJson(jdata["maxMeshOutputMemorySize"], decoded_value.maxMeshOutputMemorySize, options);
        FieldToJson(jdata["maxMeshPayloadAndOutputMemorySize"], decoded_value.maxMeshPayloadAndOutputMemorySize, options);
        FieldToJson(jdata["maxMeshOutputComponents"], decoded_value.maxMeshOutputComponents, options);
        FieldToJson(jdata["maxMeshOutputVertices"], decoded_value.maxMeshOutputVertices, options);
        FieldToJson(jdata["maxMeshOutputPrimitives"], decoded_value.maxMeshOutputPrimitives, options);
        FieldToJson(jdata["maxMeshOutputLayers"], decoded_value.maxMeshOutputLayers, options);
        FieldToJson(jdata["maxMeshMultiviewViewCount"], decoded_value.maxMeshMultiviewViewCount, options);
        FieldToJson(jdata["meshOutputPerVertexGranularity"], decoded_value.meshOutputPerVertexGranularity, options);
        FieldToJson(jdata["meshOutputPerPrimitiveGranularity"], decoded_value.meshOutputPerPrimitiveGranularity, options);
        FieldToJson(jdata["maxPreferredTaskWorkGroupInvocations"], decoded_value.maxPreferredTaskWorkGroupInvocations, options);
        FieldToJson(jdata["maxPreferredMeshWorkGroupInvocations"], decoded_value.maxPreferredMeshWorkGroupInvocations, options);
        FieldToJson(jdata["prefersLocalInvocationVertexOutput"], decoded_value.prefersLocalInvocationVertexOutput, options);
        FieldToJson(jdata["prefersLocalInvocationPrimitiveOutput"], decoded_value.prefersLocalInvocationPrimitiveOutput, options);
        FieldToJson(jdata["prefersCompactVertexOutput"], decoded_value.prefersCompactVertexOutput, options);
        FieldToJson(jdata["prefersCompactPrimitiveOutput"], decoded_value.prefersCompactPrimitiveOutput, options);
        FieldToJson(jdata["pNext"], meta_struct.pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrawMeshTasksIndirectCommandEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        const auto& decoded_value = *data->decoded_value;
        const auto& meta_struct   = *data;
        FieldToJson(jdata["groupCountX"], decoded_value.groupCountX, options);
        FieldToJson(jdata["groupCountY"], decoded_value.groupCountY, options);
        FieldToJson(jdata["groupCountZ"], decoded_value.groupCountZ, options);
    }
}


void FieldToJson(nlohmann::ordered_json& jdata, const PNextNode* data, const JsonOptions& options)
{
    if (data && data->GetPointer())
    {
        switch (reinterpret_cast<const VkBaseInStructure*>(data->GetPointer())->sType)
        {

            case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkShaderModuleCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSubgroupProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevice16BitStorageFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkMemoryDedicatedRequirements*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkMemoryDedicatedAllocateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkMemoryAllocateFlagsInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupRenderPassBeginInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupCommandBufferBeginInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupSubmitInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupBindSparseInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkBindBufferMemoryDeviceGroupInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkBindImageMemoryDeviceGroupInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupDeviceCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFeatures2*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePointClippingProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassInputAttachmentAspectCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageViewUsageCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineTessellationDomainOriginStateCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassMultiviewCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiviewFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiviewProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVariablePointersFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceProtectedMemoryFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceProtectedMemoryProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkProtectedSubmitInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSamplerYcbcrConversionInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkBindImagePlaneMemoryInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImagePlaneMemoryRequirementsInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSamplerYcbcrConversionImageFormatProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExternalImageFormatInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExternalImageFormatProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceIDProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExternalMemoryImageCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExternalMemoryBufferCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExportMemoryAllocateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExportFenceCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExportSemaphoreCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance3Properties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderDrawParametersFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVulkan11Features*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVulkan11Properties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVulkan12Features*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVulkan12Properties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageFormatListCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevice8BitStorageFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDriverProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderAtomicInt64Features*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderFloat16Int8Features*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFloatControlsProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDescriptorIndexingFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDescriptorIndexingProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSubpassDescriptionDepthStencilResolve*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDepthStencilResolveProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageStencilUsageCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSamplerReductionModeCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImagelessFramebufferFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkFramebufferAttachmentsCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassAttachmentBeginInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkAttachmentReferenceStencilLayout*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkAttachmentDescriptionStencilLayout*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceHostQueryResetFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTimelineSemaphoreProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSemaphoreTypeCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkTimelineSemaphoreSubmitInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkBufferOpaqueCaptureAddressCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVulkan13Features*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_3_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVulkan13Properties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCreationFeedbackCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePrivateDataFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDevicePrivateDataCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkMemoryBarrier2*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSynchronization2Features*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageRobustnessFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSubgroupSizeControlProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceInlineUniformBlockFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceInlineUniformBlockProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkWriteDescriptorSetInlineUniformBlock*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRenderingCreateInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDynamicRenderingFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkCommandBufferInheritanceRenderingInfo*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkFormatProperties3*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance4Features*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance4Properties*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageSwapchainCreateInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkBindImageMemorySwapchainInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupPresentInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupSwapchainCreateInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDisplayPresentInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_QUERY_RESULT_STATUS_PROPERTIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_VIDEO_PROPERTIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkQueueFamilyVideoPropertiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_PROFILE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoProfileInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_PROFILE_LIST_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoProfileListInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeCapabilitiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeUsageInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH264ProfileInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH264CapabilitiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH264PictureInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH264DpbSlotInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkAttachmentSampleCountInfoAMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkMultiviewPerViewAttributesInfoNVX*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryWin32HandleInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExportMemoryWin32HandleInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryFdInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExportSemaphoreWin32HandleInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkD3D12FenceSubmitInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePushDescriptorPropertiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPresentRegionsKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSharedPresentSurfaceCapabilitiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExportFenceWin32HandleInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkQueryPoolPerformanceCreateInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPerformanceQuerySubmitInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderClockFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PROFILE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH265ProfileInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_CAPABILITIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH265CapabilitiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_ADD_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH265SessionParametersAddInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH265SessionParametersCreateInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_PICTURE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH265PictureInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H265_DPB_SLOT_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH265DpbSlotInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceQueueGlobalPriorityCreateInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceGlobalPriorityQueryFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkQueueFamilyGlobalPriorityPropertiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkFragmentShadingRateAttachmentInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceProtectedCapabilitiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePresentWaitFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineLibraryCreateInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPresentIdKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePresentIdFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeCapabilitiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeUsageInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_LAYER_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeRateControlLayerInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeRateControlInfoKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkQueueFamilyCheckpointProperties2NV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_PROPERTIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDebugReportCallbackCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationStateRasterizationOrderAMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDedicatedAllocationImageCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDedicatedAllocationBufferCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264CapabilitiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264SessionParametersAddInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264SessionParametersCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_VCL_FRAME_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264VclFrameInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_EMIT_PICTURE_PARAMETERS_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264EmitPictureParametersInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264ProfileInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264RateControlInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264RateControlLayerInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_CAPABILITIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH265CapabilitiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_ADD_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH265SessionParametersAddInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_SESSION_PARAMETERS_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH265SessionParametersCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_VCL_FRAME_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH265VclFrameInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_EMIT_PICTURE_PARAMETERS_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH265EmitPictureParametersInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_PROFILE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH265ProfileInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH265RateControlInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_RATE_CONTROL_LAYER_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH265RateControlLayerInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkTextureLODGatherFormatPropertiesAMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExternalMemoryImageCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExportMemoryAllocateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryWin32HandleInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExportMemoryWin32HandleInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkValidationFlagsEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageViewASTCDecodeModeEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineRobustnessFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineRobustnessPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRobustnessCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportWScalingStateCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainCounterCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPresentTimesInfoGOOGLE*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportSwizzleStateCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDebugUtilsObjectNameInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDebugUtilsMessengerCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkAndroidHardwareBufferUsageANDROID*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkExternalFormatANDROID*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSampleLocationsInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassSampleLocationsBeginInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineSampleLocationsStateCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCoverageToColorStateCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCoverageModulationStateCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDrmFormatModifierPropertiesListEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageDrmFormatModifierListCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDrmFormatModifierPropertiesList2EXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingPropertiesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryHostPointerInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCompilerControlCreateInfoAMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderCorePropertiesAMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceMemoryOverallocationCreateInfoAMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineVertexInputDivisorStateCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPresentFrameTokenGGP*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMeshShaderFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMeshShaderPropertiesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkQueueFamilyCheckpointPropertiesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderCoreProperties2AMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkMemoryPriorityAllocateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkBufferDeviceAddressCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkValidationFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCoverageReductionStateCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceFullScreenExclusiveInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLineRasterizationFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLineRasterizationPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationLineStateCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSurfacePresentModeEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSurfacePresentScalingCapabilitiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSurfacePresentModeCompatibilityEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainPresentFenceInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainPresentModesCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainPresentModeInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainPresentScalingCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkCommandBufferInheritanceViewportScissorInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassTransformBeginInfoQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRobustness2FeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRobustness2PropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSamplerCustomBorderColorCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePresentBarrierFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceCapabilitiesPresentBarrierNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainPresentBarrierCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceDiagnosticsConfigCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GRAPHICS_PIPELINE_LIBRARY_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkGraphicsPipelineLibraryCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkAccelerationStructureMotionInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkCopyCommandTransformInfoQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_CONTROL_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageCompressionControlEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_COMPRESSION_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageCompressionPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevice4444FormatsFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFaultFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkMutableDescriptorTypeCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDrmPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDeviceAddressBindingCallbackDataEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryZirconHandleInfoFUCHSIA*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSubpassResolvePerformanceQueryEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkMultisampledRenderToSingleSampledInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineColorWriteCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageViewMinLodCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPACITY_MICROMAP_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_FEATURES_HUAWEI:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_PROPERTIES_HUAWEI:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderCorePropertiesARM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageViewSlicedCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_SUBPASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkSubpassFragmentDensityMapOffsetEndInfoQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkImageViewSampleWeightCreateInfoQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_FEATURES_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_PROPERTIES_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_3_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_CONTROL_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassCreationControlEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDER_PASS_CREATION_FEEDBACK_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassCreationFeedbackCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkDirectDriverLoadingListLUNARG*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MODULE_IDENTIFIER_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_OPTICAL_FLOW_PROPERTIES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_IMAGE_FORMAT_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkOpticalFlowImageFormatInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_OPTICAL_FLOW_SESSION_CREATE_PRIVATE_DATA_INFO_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineProtectedAccessFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkAmigoProfilingSubmitInfoSEC*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_NV:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesNV*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_FEATURES_ARM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_BUILTINS_PROPERTIES_ARM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkWriteDescriptorSetAccelerationStructureKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayQueryFeaturesKHR*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
            
            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            {
               const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT*>(data->GetMetaStructPointer());
               FieldToJson(jdata, pnext, options);
               break;
            }
                    }
    }
}
GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
