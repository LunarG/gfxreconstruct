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

#include "generated_vulkan_struct_to_json.h"
#include "generated_vulkan_enum_to_json.h"
#include "util/to_string.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)
using util::JsonOptions;
using util::to_hex_variable_width;
using util::uuid_to_string;


void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264SpsVuiFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["aspect_ratio_info_present_flag"], data->decoded_value->aspect_ratio_info_present_flag, options);
        FieldToJson(jdata["overscan_info_present_flag"], data->decoded_value->overscan_info_present_flag, options);
        FieldToJson(jdata["overscan_appropriate_flag"], data->decoded_value->overscan_appropriate_flag, options);
        FieldToJson(jdata["video_signal_type_present_flag"], data->decoded_value->video_signal_type_present_flag, options);
        FieldToJson(jdata["video_full_range_flag"], data->decoded_value->video_full_range_flag, options);
        FieldToJson(jdata["color_description_present_flag"], data->decoded_value->color_description_present_flag, options);
        FieldToJson(jdata["chroma_loc_info_present_flag"], data->decoded_value->chroma_loc_info_present_flag, options);
        FieldToJson(jdata["timing_info_present_flag"], data->decoded_value->timing_info_present_flag, options);
        FieldToJson(jdata["fixed_frame_rate_flag"], data->decoded_value->fixed_frame_rate_flag, options);
        FieldToJson(jdata["bitstream_restriction_flag"], data->decoded_value->bitstream_restriction_flag, options);
        FieldToJson(jdata["nal_hrd_parameters_present_flag"], data->decoded_value->nal_hrd_parameters_present_flag, options);
        FieldToJson(jdata["vcl_hrd_parameters_present_flag"], data->decoded_value->vcl_hrd_parameters_present_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264HrdParameters* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["cpb_cnt_minus1"], data->decoded_value->cpb_cnt_minus1, options);
        FieldToJson(jdata["bit_rate_scale"], data->decoded_value->bit_rate_scale, options);
        FieldToJson(jdata["cpb_size_scale"], data->decoded_value->cpb_size_scale, options);
        FieldToJson(jdata["reserved1"], data->decoded_value->reserved1, options);
        FieldToJson(jdata["bit_rate_value_minus1"], &data->bit_rate_value_minus1, options);
        FieldToJson(jdata["cpb_size_value_minus1"], &data->cpb_size_value_minus1, options);
        FieldToJson(jdata["cbr_flag"], &data->cbr_flag, options);
        FieldToJson(jdata["initial_cpb_removal_delay_length_minus1"], data->decoded_value->initial_cpb_removal_delay_length_minus1, options);
        FieldToJson(jdata["cpb_removal_delay_length_minus1"], data->decoded_value->cpb_removal_delay_length_minus1, options);
        FieldToJson(jdata["dpb_output_delay_length_minus1"], data->decoded_value->dpb_output_delay_length_minus1, options);
        FieldToJson(jdata["time_offset_length"], data->decoded_value->time_offset_length, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264SequenceParameterSetVui* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["aspect_ratio_idc"], data->decoded_value->aspect_ratio_idc, options);
        FieldToJson(jdata["sar_width"], data->decoded_value->sar_width, options);
        FieldToJson(jdata["sar_height"], data->decoded_value->sar_height, options);
        FieldToJson(jdata["video_format"], data->decoded_value->video_format, options);
        FieldToJson(jdata["colour_primaries"], data->decoded_value->colour_primaries, options);
        FieldToJson(jdata["transfer_characteristics"], data->decoded_value->transfer_characteristics, options);
        FieldToJson(jdata["matrix_coefficients"], data->decoded_value->matrix_coefficients, options);
        FieldToJson(jdata["num_units_in_tick"], data->decoded_value->num_units_in_tick, options);
        FieldToJson(jdata["time_scale"], data->decoded_value->time_scale, options);
        FieldToJson(jdata["max_num_reorder_frames"], data->decoded_value->max_num_reorder_frames, options);
        FieldToJson(jdata["max_dec_frame_buffering"], data->decoded_value->max_dec_frame_buffering, options);
        FieldToJson(jdata["chroma_sample_loc_type_top_field"], data->decoded_value->chroma_sample_loc_type_top_field, options);
        FieldToJson(jdata["chroma_sample_loc_type_bottom_field"], data->decoded_value->chroma_sample_loc_type_bottom_field, options);
        FieldToJson(jdata["reserved1"], data->decoded_value->reserved1, options);
        FieldToJson(jdata["pHrdParameters"], data->pHrdParameters, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264SpsFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["constraint_set0_flag"], data->decoded_value->constraint_set0_flag, options);
        FieldToJson(jdata["constraint_set1_flag"], data->decoded_value->constraint_set1_flag, options);
        FieldToJson(jdata["constraint_set2_flag"], data->decoded_value->constraint_set2_flag, options);
        FieldToJson(jdata["constraint_set3_flag"], data->decoded_value->constraint_set3_flag, options);
        FieldToJson(jdata["constraint_set4_flag"], data->decoded_value->constraint_set4_flag, options);
        FieldToJson(jdata["constraint_set5_flag"], data->decoded_value->constraint_set5_flag, options);
        FieldToJson(jdata["direct_8x8_inference_flag"], data->decoded_value->direct_8x8_inference_flag, options);
        FieldToJson(jdata["mb_adaptive_frame_field_flag"], data->decoded_value->mb_adaptive_frame_field_flag, options);
        FieldToJson(jdata["frame_mbs_only_flag"], data->decoded_value->frame_mbs_only_flag, options);
        FieldToJson(jdata["delta_pic_order_always_zero_flag"], data->decoded_value->delta_pic_order_always_zero_flag, options);
        FieldToJson(jdata["separate_colour_plane_flag"], data->decoded_value->separate_colour_plane_flag, options);
        FieldToJson(jdata["gaps_in_frame_num_value_allowed_flag"], data->decoded_value->gaps_in_frame_num_value_allowed_flag, options);
        FieldToJson(jdata["qpprime_y_zero_transform_bypass_flag"], data->decoded_value->qpprime_y_zero_transform_bypass_flag, options);
        FieldToJson(jdata["frame_cropping_flag"], data->decoded_value->frame_cropping_flag, options);
        FieldToJson(jdata["seq_scaling_matrix_present_flag"], data->decoded_value->seq_scaling_matrix_present_flag, options);
        FieldToJson(jdata["vui_parameters_present_flag"], data->decoded_value->vui_parameters_present_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264ScalingLists* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["scaling_list_present_mask"], data->decoded_value->scaling_list_present_mask, options);
        FieldToJson(jdata["use_default_scaling_matrix_mask"], data->decoded_value->use_default_scaling_matrix_mask, options);
        FieldToJson(jdata["ScalingList4x4"], &data->ScalingList4x4, options);
        FieldToJson(jdata["ScalingList8x8"], &data->ScalingList8x8, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264SequenceParameterSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["profile_idc"], data->decoded_value->profile_idc, options);
        FieldToJson(jdata["level_idc"], data->decoded_value->level_idc, options);
        FieldToJson(jdata["chroma_format_idc"], data->decoded_value->chroma_format_idc, options);
        FieldToJson(jdata["seq_parameter_set_id"], data->decoded_value->seq_parameter_set_id, options);
        FieldToJson(jdata["bit_depth_luma_minus8"], data->decoded_value->bit_depth_luma_minus8, options);
        FieldToJson(jdata["bit_depth_chroma_minus8"], data->decoded_value->bit_depth_chroma_minus8, options);
        FieldToJson(jdata["log2_max_frame_num_minus4"], data->decoded_value->log2_max_frame_num_minus4, options);
        FieldToJson(jdata["pic_order_cnt_type"], data->decoded_value->pic_order_cnt_type, options);
        FieldToJson(jdata["offset_for_non_ref_pic"], data->decoded_value->offset_for_non_ref_pic, options);
        FieldToJson(jdata["offset_for_top_to_bottom_field"], data->decoded_value->offset_for_top_to_bottom_field, options);
        FieldToJson(jdata["log2_max_pic_order_cnt_lsb_minus4"], data->decoded_value->log2_max_pic_order_cnt_lsb_minus4, options);
        FieldToJson(jdata["num_ref_frames_in_pic_order_cnt_cycle"], data->decoded_value->num_ref_frames_in_pic_order_cnt_cycle, options);
        FieldToJson(jdata["max_num_ref_frames"], data->decoded_value->max_num_ref_frames, options);
        FieldToJson(jdata["reserved1"], data->decoded_value->reserved1, options);
        FieldToJson(jdata["pic_width_in_mbs_minus1"], data->decoded_value->pic_width_in_mbs_minus1, options);
        FieldToJson(jdata["pic_height_in_map_units_minus1"], data->decoded_value->pic_height_in_map_units_minus1, options);
        FieldToJson(jdata["frame_crop_left_offset"], data->decoded_value->frame_crop_left_offset, options);
        FieldToJson(jdata["frame_crop_right_offset"], data->decoded_value->frame_crop_right_offset, options);
        FieldToJson(jdata["frame_crop_top_offset"], data->decoded_value->frame_crop_top_offset, options);
        FieldToJson(jdata["frame_crop_bottom_offset"], data->decoded_value->frame_crop_bottom_offset, options);
        FieldToJson(jdata["reserved2"], data->decoded_value->reserved2, options);
        FieldToJson(jdata["pOffsetForRefFrame"], data->pOffsetForRefFrame, options);
        FieldToJson(jdata["pScalingLists"], data->pScalingLists, options);
        FieldToJson(jdata["pSequenceParameterSetVui"], data->pSequenceParameterSetVui, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264PpsFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["transform_8x8_mode_flag"], data->decoded_value->transform_8x8_mode_flag, options);
        FieldToJson(jdata["redundant_pic_cnt_present_flag"], data->decoded_value->redundant_pic_cnt_present_flag, options);
        FieldToJson(jdata["constrained_intra_pred_flag"], data->decoded_value->constrained_intra_pred_flag, options);
        FieldToJson(jdata["deblocking_filter_control_present_flag"], data->decoded_value->deblocking_filter_control_present_flag, options);
        FieldToJson(jdata["weighted_pred_flag"], data->decoded_value->weighted_pred_flag, options);
        FieldToJson(jdata["bottom_field_pic_order_in_frame_present_flag"], data->decoded_value->bottom_field_pic_order_in_frame_present_flag, options);
        FieldToJson(jdata["entropy_coding_mode_flag"], data->decoded_value->entropy_coding_mode_flag, options);
        FieldToJson(jdata["pic_scaling_matrix_present_flag"], data->decoded_value->pic_scaling_matrix_present_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoH264PictureParameterSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["seq_parameter_set_id"], data->decoded_value->seq_parameter_set_id, options);
        FieldToJson(jdata["pic_parameter_set_id"], data->decoded_value->pic_parameter_set_id, options);
        FieldToJson(jdata["num_ref_idx_l0_default_active_minus1"], data->decoded_value->num_ref_idx_l0_default_active_minus1, options);
        FieldToJson(jdata["num_ref_idx_l1_default_active_minus1"], data->decoded_value->num_ref_idx_l1_default_active_minus1, options);
        FieldToJson(jdata["weighted_bipred_idc"], data->decoded_value->weighted_bipred_idc, options);
        FieldToJson(jdata["pic_init_qp_minus26"], data->decoded_value->pic_init_qp_minus26, options);
        FieldToJson(jdata["pic_init_qs_minus26"], data->decoded_value->pic_init_qs_minus26, options);
        FieldToJson(jdata["chroma_qp_index_offset"], data->decoded_value->chroma_qp_index_offset, options);
        FieldToJson(jdata["second_chroma_qp_index_offset"], data->decoded_value->second_chroma_qp_index_offset, options);
        FieldToJson(jdata["pScalingLists"], data->pScalingLists, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH264PictureInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["field_pic_flag"], data->decoded_value->field_pic_flag, options);
        FieldToJson(jdata["is_intra"], data->decoded_value->is_intra, options);
        FieldToJson(jdata["IdrPicFlag"], data->decoded_value->IdrPicFlag, options);
        FieldToJson(jdata["bottom_field_flag"], data->decoded_value->bottom_field_flag, options);
        FieldToJson(jdata["is_reference"], data->decoded_value->is_reference, options);
        FieldToJson(jdata["complementary_field_pair"], data->decoded_value->complementary_field_pair, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH264PictureInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["seq_parameter_set_id"], data->decoded_value->seq_parameter_set_id, options);
        FieldToJson(jdata["pic_parameter_set_id"], data->decoded_value->pic_parameter_set_id, options);
        FieldToJson(jdata["reserved1"], data->decoded_value->reserved1, options);
        FieldToJson(jdata["reserved2"], data->decoded_value->reserved2, options);
        FieldToJson(jdata["frame_num"], data->decoded_value->frame_num, options);
        FieldToJson(jdata["idr_pic_id"], data->decoded_value->idr_pic_id, options);
        FieldToJson(jdata["PicOrderCnt"], &data->PicOrderCnt, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH264ReferenceInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["top_field_flag"], data->decoded_value->top_field_flag, options);
        FieldToJson(jdata["bottom_field_flag"], data->decoded_value->bottom_field_flag, options);
        FieldToJson(jdata["used_for_long_term_reference"], data->decoded_value->used_for_long_term_reference, options);
        FieldToJson(jdata["is_non_existing"], data->decoded_value->is_non_existing, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeH264ReferenceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["FrameNum"], data->decoded_value->FrameNum, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
        FieldToJson(jdata["PicOrderCnt"], &data->PicOrderCnt, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264WeightTableFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["luma_weight_l0_flag"], data->decoded_value->luma_weight_l0_flag, options);
        FieldToJson(jdata["chroma_weight_l0_flag"], data->decoded_value->chroma_weight_l0_flag, options);
        FieldToJson(jdata["luma_weight_l1_flag"], data->decoded_value->luma_weight_l1_flag, options);
        FieldToJson(jdata["chroma_weight_l1_flag"], data->decoded_value->chroma_weight_l1_flag, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264WeightTable* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["luma_log2_weight_denom"], data->decoded_value->luma_log2_weight_denom, options);
        FieldToJson(jdata["chroma_log2_weight_denom"], data->decoded_value->chroma_log2_weight_denom, options);
        FieldToJson(jdata["luma_weight_l0"], &data->luma_weight_l0, options);
        FieldToJson(jdata["luma_offset_l0"], &data->luma_offset_l0, options);
        FieldToJson(jdata["chroma_weight_l0"], &data->chroma_weight_l0, options);
        FieldToJson(jdata["chroma_offset_l0"], &data->chroma_offset_l0, options);
        FieldToJson(jdata["luma_weight_l1"], &data->luma_weight_l1, options);
        FieldToJson(jdata["luma_offset_l1"], &data->luma_offset_l1, options);
        FieldToJson(jdata["chroma_weight_l1"], &data->chroma_weight_l1, options);
        FieldToJson(jdata["chroma_offset_l1"], &data->chroma_offset_l1, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264SliceHeaderFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["direct_spatial_mv_pred_flag"], data->decoded_value->direct_spatial_mv_pred_flag, options);
        FieldToJson(jdata["num_ref_idx_active_override_flag"], data->decoded_value->num_ref_idx_active_override_flag, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264PictureInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["IdrPicFlag"], data->decoded_value->IdrPicFlag, options);
        FieldToJson(jdata["is_reference"], data->decoded_value->is_reference, options);
        FieldToJson(jdata["no_output_of_prior_pics_flag"], data->decoded_value->no_output_of_prior_pics_flag, options);
        FieldToJson(jdata["long_term_reference_flag"], data->decoded_value->long_term_reference_flag, options);
        FieldToJson(jdata["adaptive_ref_pic_marking_mode_flag"], data->decoded_value->adaptive_ref_pic_marking_mode_flag, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264ReferenceInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["used_for_long_term_reference"], data->decoded_value->used_for_long_term_reference, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264ReferenceListsInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["ref_pic_list_modification_flag_l0"], data->decoded_value->ref_pic_list_modification_flag_l0, options);
        FieldToJson(jdata["ref_pic_list_modification_flag_l1"], data->decoded_value->ref_pic_list_modification_flag_l1, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264RefListModEntry* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["modification_of_pic_nums_idc"], data->decoded_value->modification_of_pic_nums_idc, options);
        FieldToJson(jdata["abs_diff_pic_num_minus1"], data->decoded_value->abs_diff_pic_num_minus1, options);
        FieldToJson(jdata["long_term_pic_num"], data->decoded_value->long_term_pic_num, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264RefPicMarkingEntry* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["memory_management_control_operation"], data->decoded_value->memory_management_control_operation, options);
        FieldToJson(jdata["difference_of_pic_nums_minus1"], data->decoded_value->difference_of_pic_nums_minus1, options);
        FieldToJson(jdata["long_term_pic_num"], data->decoded_value->long_term_pic_num, options);
        FieldToJson(jdata["long_term_frame_idx"], data->decoded_value->long_term_frame_idx, options);
        FieldToJson(jdata["max_long_term_frame_idx_plus1"], data->decoded_value->max_long_term_frame_idx_plus1, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264ReferenceListsInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["num_ref_idx_l0_active_minus1"], data->decoded_value->num_ref_idx_l0_active_minus1, options);
        FieldToJson(jdata["num_ref_idx_l1_active_minus1"], data->decoded_value->num_ref_idx_l1_active_minus1, options);
        FieldToJson(jdata["RefPicList0"], &data->RefPicList0, options);
        FieldToJson(jdata["RefPicList1"], &data->RefPicList1, options);
        FieldToJson(jdata["refList0ModOpCount"], data->decoded_value->refList0ModOpCount, options);
        FieldToJson(jdata["refList1ModOpCount"], data->decoded_value->refList1ModOpCount, options);
        FieldToJson(jdata["refPicMarkingOpCount"], data->decoded_value->refPicMarkingOpCount, options);
        FieldToJson(jdata["reserved1"], &data->reserved1, options);
        FieldToJson(jdata["pRefList0ModOperations"], data->pRefList0ModOperations, options);
        FieldToJson(jdata["pRefList1ModOperations"], data->pRefList1ModOperations, options);
        FieldToJson(jdata["pRefPicMarkingOperations"], data->pRefPicMarkingOperations, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264PictureInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["seq_parameter_set_id"], data->decoded_value->seq_parameter_set_id, options);
        FieldToJson(jdata["pic_parameter_set_id"], data->decoded_value->pic_parameter_set_id, options);
        FieldToJson(jdata["idr_pic_id"], data->decoded_value->idr_pic_id, options);
        FieldToJson(jdata["primary_pic_type"], data->decoded_value->primary_pic_type, options);
        FieldToJson(jdata["frame_num"], data->decoded_value->frame_num, options);
        FieldToJson(jdata["PicOrderCnt"], data->decoded_value->PicOrderCnt, options);
        FieldToJson(jdata["temporal_id"], data->decoded_value->temporal_id, options);
        FieldToJson(jdata["reserved1"], &data->reserved1, options);
        FieldToJson(jdata["pRefLists"], data->pRefLists, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264ReferenceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["primary_pic_type"], data->decoded_value->primary_pic_type, options);
        FieldToJson(jdata["FrameNum"], data->decoded_value->FrameNum, options);
        FieldToJson(jdata["PicOrderCnt"], data->decoded_value->PicOrderCnt, options);
        FieldToJson(jdata["long_term_pic_num"], data->decoded_value->long_term_pic_num, options);
        FieldToJson(jdata["long_term_frame_idx"], data->decoded_value->long_term_frame_idx, options);
        FieldToJson(jdata["temporal_id"], data->decoded_value->temporal_id, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeH264SliceHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["first_mb_in_slice"], data->decoded_value->first_mb_in_slice, options);
        FieldToJson(jdata["slice_type"], data->decoded_value->slice_type, options);
        FieldToJson(jdata["slice_alpha_c0_offset_div2"], data->decoded_value->slice_alpha_c0_offset_div2, options);
        FieldToJson(jdata["slice_beta_offset_div2"], data->decoded_value->slice_beta_offset_div2, options);
        FieldToJson(jdata["slice_qp_delta"], data->decoded_value->slice_qp_delta, options);
        FieldToJson(jdata["reserved1"], data->decoded_value->reserved1, options);
        FieldToJson(jdata["cabac_init_idc"], data->decoded_value->cabac_init_idc, options);
        FieldToJson(jdata["disable_deblocking_filter_idc"], data->decoded_value->disable_deblocking_filter_idc, options);
        FieldToJson(jdata["pWeightTable"], data->pWeightTable, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoVP9ColorConfigFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["color_range"], data->decoded_value->color_range, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoVP9ColorConfig* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["BitDepth"], data->decoded_value->BitDepth, options);
        FieldToJson(jdata["subsampling_x"], data->decoded_value->subsampling_x, options);
        FieldToJson(jdata["subsampling_y"], data->decoded_value->subsampling_y, options);
        FieldToJson(jdata["reserved1"], data->decoded_value->reserved1, options);
        FieldToJson(jdata["color_space"], data->decoded_value->color_space, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoVP9LoopFilterFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["loop_filter_delta_enabled"], data->decoded_value->loop_filter_delta_enabled, options);
        FieldToJson(jdata["loop_filter_delta_update"], data->decoded_value->loop_filter_delta_update, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoVP9LoopFilter* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["loop_filter_level"], data->decoded_value->loop_filter_level, options);
        FieldToJson(jdata["loop_filter_sharpness"], data->decoded_value->loop_filter_sharpness, options);
        FieldToJson(jdata["update_ref_delta"], data->decoded_value->update_ref_delta, options);
        FieldToJson(jdata["loop_filter_ref_deltas"], &data->loop_filter_ref_deltas, options);
        FieldToJson(jdata["update_mode_delta"], data->decoded_value->update_mode_delta, options);
        FieldToJson(jdata["loop_filter_mode_deltas"], &data->loop_filter_mode_deltas, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoVP9SegmentationFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["segmentation_update_map"], data->decoded_value->segmentation_update_map, options);
        FieldToJson(jdata["segmentation_temporal_update"], data->decoded_value->segmentation_temporal_update, options);
        FieldToJson(jdata["segmentation_update_data"], data->decoded_value->segmentation_update_data, options);
        FieldToJson(jdata["segmentation_abs_or_delta_update"], data->decoded_value->segmentation_abs_or_delta_update, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoVP9Segmentation* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["segmentation_tree_probs"], &data->segmentation_tree_probs, options);
        FieldToJson(jdata["segmentation_pred_prob"], &data->segmentation_pred_prob, options);
        FieldToJson(jdata["FeatureEnabled"], &data->FeatureEnabled, options);
        FieldToJson(jdata["FeatureData"], &data->FeatureData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeVP9PictureInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["error_resilient_mode"], data->decoded_value->error_resilient_mode, options);
        FieldToJson(jdata["intra_only"], data->decoded_value->intra_only, options);
        FieldToJson(jdata["allow_high_precision_mv"], data->decoded_value->allow_high_precision_mv, options);
        FieldToJson(jdata["refresh_frame_context"], data->decoded_value->refresh_frame_context, options);
        FieldToJson(jdata["frame_parallel_decoding_mode"], data->decoded_value->frame_parallel_decoding_mode, options);
        FieldToJson(jdata["segmentation_enabled"], data->decoded_value->segmentation_enabled, options);
        FieldToJson(jdata["show_frame"], data->decoded_value->show_frame, options);
        FieldToJson(jdata["UsePrevFrameMvs"], data->decoded_value->UsePrevFrameMvs, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeVP9PictureInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["profile"], data->decoded_value->profile, options);
        FieldToJson(jdata["frame_type"], data->decoded_value->frame_type, options);
        FieldToJson(jdata["frame_context_idx"], data->decoded_value->frame_context_idx, options);
        FieldToJson(jdata["reset_frame_context"], data->decoded_value->reset_frame_context, options);
        FieldToJson(jdata["refresh_frame_flags"], data->decoded_value->refresh_frame_flags, options);
        FieldToJson(jdata["ref_frame_sign_bias_mask"], data->decoded_value->ref_frame_sign_bias_mask, options);
        FieldToJson(jdata["interpolation_filter"], data->decoded_value->interpolation_filter, options);
        FieldToJson(jdata["base_q_idx"], data->decoded_value->base_q_idx, options);
        FieldToJson(jdata["delta_q_y_dc"], data->decoded_value->delta_q_y_dc, options);
        FieldToJson(jdata["delta_q_uv_dc"], data->decoded_value->delta_q_uv_dc, options);
        FieldToJson(jdata["delta_q_uv_ac"], data->decoded_value->delta_q_uv_ac, options);
        FieldToJson(jdata["tile_cols_log2"], data->decoded_value->tile_cols_log2, options);
        FieldToJson(jdata["tile_rows_log2"], data->decoded_value->tile_rows_log2, options);
        FieldToJson(jdata["reserved1"], &data->reserved1, options);
        FieldToJson(jdata["pColorConfig"], data->pColorConfig, options);
        FieldToJson(jdata["pLoopFilter"], data->pLoopFilter, options);
        FieldToJson(jdata["pSegmentation"], data->pSegmentation, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1ColorConfigFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["mono_chrome"], data->decoded_value->mono_chrome, options);
        FieldToJson(jdata["color_range"], data->decoded_value->color_range, options);
        FieldToJson(jdata["separate_uv_delta_q"], data->decoded_value->separate_uv_delta_q, options);
        FieldToJson(jdata["color_description_present_flag"], data->decoded_value->color_description_present_flag, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1ColorConfig* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["BitDepth"], data->decoded_value->BitDepth, options);
        FieldToJson(jdata["subsampling_x"], data->decoded_value->subsampling_x, options);
        FieldToJson(jdata["subsampling_y"], data->decoded_value->subsampling_y, options);
        FieldToJson(jdata["reserved1"], data->decoded_value->reserved1, options);
        FieldToJson(jdata["color_primaries"], data->decoded_value->color_primaries, options);
        FieldToJson(jdata["transfer_characteristics"], data->decoded_value->transfer_characteristics, options);
        FieldToJson(jdata["matrix_coefficients"], data->decoded_value->matrix_coefficients, options);
        FieldToJson(jdata["chroma_sample_position"], data->decoded_value->chroma_sample_position, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1TimingInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["equal_picture_interval"], data->decoded_value->equal_picture_interval, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1TimingInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["num_units_in_display_tick"], data->decoded_value->num_units_in_display_tick, options);
        FieldToJson(jdata["time_scale"], data->decoded_value->time_scale, options);
        FieldToJson(jdata["num_ticks_per_picture_minus_1"], data->decoded_value->num_ticks_per_picture_minus_1, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1SequenceHeaderFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["still_picture"], data->decoded_value->still_picture, options);
        FieldToJson(jdata["reduced_still_picture_header"], data->decoded_value->reduced_still_picture_header, options);
        FieldToJson(jdata["use_128x128_superblock"], data->decoded_value->use_128x128_superblock, options);
        FieldToJson(jdata["enable_filter_intra"], data->decoded_value->enable_filter_intra, options);
        FieldToJson(jdata["enable_intra_edge_filter"], data->decoded_value->enable_intra_edge_filter, options);
        FieldToJson(jdata["enable_interintra_compound"], data->decoded_value->enable_interintra_compound, options);
        FieldToJson(jdata["enable_masked_compound"], data->decoded_value->enable_masked_compound, options);
        FieldToJson(jdata["enable_warped_motion"], data->decoded_value->enable_warped_motion, options);
        FieldToJson(jdata["enable_dual_filter"], data->decoded_value->enable_dual_filter, options);
        FieldToJson(jdata["enable_order_hint"], data->decoded_value->enable_order_hint, options);
        FieldToJson(jdata["enable_jnt_comp"], data->decoded_value->enable_jnt_comp, options);
        FieldToJson(jdata["enable_ref_frame_mvs"], data->decoded_value->enable_ref_frame_mvs, options);
        FieldToJson(jdata["frame_id_numbers_present_flag"], data->decoded_value->frame_id_numbers_present_flag, options);
        FieldToJson(jdata["enable_superres"], data->decoded_value->enable_superres, options);
        FieldToJson(jdata["enable_cdef"], data->decoded_value->enable_cdef, options);
        FieldToJson(jdata["enable_restoration"], data->decoded_value->enable_restoration, options);
        FieldToJson(jdata["film_grain_params_present"], data->decoded_value->film_grain_params_present, options);
        FieldToJson(jdata["timing_info_present_flag"], data->decoded_value->timing_info_present_flag, options);
        FieldToJson(jdata["initial_display_delay_present_flag"], data->decoded_value->initial_display_delay_present_flag, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1SequenceHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["seq_profile"], data->decoded_value->seq_profile, options);
        FieldToJson(jdata["frame_width_bits_minus_1"], data->decoded_value->frame_width_bits_minus_1, options);
        FieldToJson(jdata["frame_height_bits_minus_1"], data->decoded_value->frame_height_bits_minus_1, options);
        FieldToJson(jdata["max_frame_width_minus_1"], data->decoded_value->max_frame_width_minus_1, options);
        FieldToJson(jdata["max_frame_height_minus_1"], data->decoded_value->max_frame_height_minus_1, options);
        FieldToJson(jdata["delta_frame_id_length_minus_2"], data->decoded_value->delta_frame_id_length_minus_2, options);
        FieldToJson(jdata["additional_frame_id_length_minus_1"], data->decoded_value->additional_frame_id_length_minus_1, options);
        FieldToJson(jdata["order_hint_bits_minus_1"], data->decoded_value->order_hint_bits_minus_1, options);
        FieldToJson(jdata["seq_force_integer_mv"], data->decoded_value->seq_force_integer_mv, options);
        FieldToJson(jdata["seq_force_screen_content_tools"], data->decoded_value->seq_force_screen_content_tools, options);
        FieldToJson(jdata["reserved1"], &data->reserved1, options);
        FieldToJson(jdata["pColorConfig"], data->pColorConfig, options);
        FieldToJson(jdata["pTimingInfo"], data->pTimingInfo, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1LoopFilterFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["loop_filter_delta_enabled"], data->decoded_value->loop_filter_delta_enabled, options);
        FieldToJson(jdata["loop_filter_delta_update"], data->decoded_value->loop_filter_delta_update, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1LoopFilter* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["loop_filter_level"], &data->loop_filter_level, options);
        FieldToJson(jdata["loop_filter_sharpness"], data->decoded_value->loop_filter_sharpness, options);
        FieldToJson(jdata["update_ref_delta"], data->decoded_value->update_ref_delta, options);
        FieldToJson(jdata["loop_filter_ref_deltas"], &data->loop_filter_ref_deltas, options);
        FieldToJson(jdata["update_mode_delta"], data->decoded_value->update_mode_delta, options);
        FieldToJson(jdata["loop_filter_mode_deltas"], &data->loop_filter_mode_deltas, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1QuantizationFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["using_qmatrix"], data->decoded_value->using_qmatrix, options);
        FieldToJson(jdata["diff_uv_delta"], data->decoded_value->diff_uv_delta, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1Quantization* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["base_q_idx"], data->decoded_value->base_q_idx, options);
        FieldToJson(jdata["DeltaQYDc"], data->decoded_value->DeltaQYDc, options);
        FieldToJson(jdata["DeltaQUDc"], data->decoded_value->DeltaQUDc, options);
        FieldToJson(jdata["DeltaQUAc"], data->decoded_value->DeltaQUAc, options);
        FieldToJson(jdata["DeltaQVDc"], data->decoded_value->DeltaQVDc, options);
        FieldToJson(jdata["DeltaQVAc"], data->decoded_value->DeltaQVAc, options);
        FieldToJson(jdata["qm_y"], data->decoded_value->qm_y, options);
        FieldToJson(jdata["qm_u"], data->decoded_value->qm_u, options);
        FieldToJson(jdata["qm_v"], data->decoded_value->qm_v, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1Segmentation* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FeatureEnabled"], &data->FeatureEnabled, options);
        FieldToJson(jdata["FeatureData"], &data->FeatureData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1TileInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["uniform_tile_spacing_flag"], data->decoded_value->uniform_tile_spacing_flag, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1TileInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["TileCols"], data->decoded_value->TileCols, options);
        FieldToJson(jdata["TileRows"], data->decoded_value->TileRows, options);
        FieldToJson(jdata["context_update_tile_id"], data->decoded_value->context_update_tile_id, options);
        FieldToJson(jdata["tile_size_bytes_minus_1"], data->decoded_value->tile_size_bytes_minus_1, options);
        FieldToJson(jdata["reserved1"], &data->reserved1, options);
        FieldToJson(jdata["pMiColStarts"], data->pMiColStarts, options);
        FieldToJson(jdata["pMiRowStarts"], data->pMiRowStarts, options);
        FieldToJson(jdata["pWidthInSbsMinus1"], data->pWidthInSbsMinus1, options);
        FieldToJson(jdata["pHeightInSbsMinus1"], data->pHeightInSbsMinus1, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1CDEF* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["cdef_damping_minus_3"], data->decoded_value->cdef_damping_minus_3, options);
        FieldToJson(jdata["cdef_bits"], data->decoded_value->cdef_bits, options);
        FieldToJson(jdata["cdef_y_pri_strength"], &data->cdef_y_pri_strength, options);
        FieldToJson(jdata["cdef_y_sec_strength"], &data->cdef_y_sec_strength, options);
        FieldToJson(jdata["cdef_uv_pri_strength"], &data->cdef_uv_pri_strength, options);
        FieldToJson(jdata["cdef_uv_sec_strength"], &data->cdef_uv_sec_strength, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1LoopRestoration* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["FrameRestorationType"], &data->FrameRestorationType, options);
        FieldToJson(jdata["LoopRestorationSize"], &data->LoopRestorationSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1GlobalMotion* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["GmType"], &data->GmType, options);
        FieldToJson(jdata["gm_params"], &data->gm_params, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1FilmGrainFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["chroma_scaling_from_luma"], data->decoded_value->chroma_scaling_from_luma, options);
        FieldToJson(jdata["overlap_flag"], data->decoded_value->overlap_flag, options);
        FieldToJson(jdata["clip_to_restricted_range"], data->decoded_value->clip_to_restricted_range, options);
        FieldToJson(jdata["update_grain"], data->decoded_value->update_grain, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoAV1FilmGrain* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["grain_scaling_minus_8"], data->decoded_value->grain_scaling_minus_8, options);
        FieldToJson(jdata["ar_coeff_lag"], data->decoded_value->ar_coeff_lag, options);
        FieldToJson(jdata["ar_coeff_shift_minus_6"], data->decoded_value->ar_coeff_shift_minus_6, options);
        FieldToJson(jdata["grain_scale_shift"], data->decoded_value->grain_scale_shift, options);
        FieldToJson(jdata["grain_seed"], data->decoded_value->grain_seed, options);
        FieldToJson(jdata["film_grain_params_ref_idx"], data->decoded_value->film_grain_params_ref_idx, options);
        FieldToJson(jdata["num_y_points"], data->decoded_value->num_y_points, options);
        FieldToJson(jdata["point_y_value"], &data->point_y_value, options);
        FieldToJson(jdata["point_y_scaling"], &data->point_y_scaling, options);
        FieldToJson(jdata["num_cb_points"], data->decoded_value->num_cb_points, options);
        FieldToJson(jdata["point_cb_value"], &data->point_cb_value, options);
        FieldToJson(jdata["point_cb_scaling"], &data->point_cb_scaling, options);
        FieldToJson(jdata["num_cr_points"], data->decoded_value->num_cr_points, options);
        FieldToJson(jdata["point_cr_value"], &data->point_cr_value, options);
        FieldToJson(jdata["point_cr_scaling"], &data->point_cr_scaling, options);
        FieldToJson(jdata["ar_coeffs_y_plus_128"], &data->ar_coeffs_y_plus_128, options);
        FieldToJson(jdata["ar_coeffs_cb_plus_128"], &data->ar_coeffs_cb_plus_128, options);
        FieldToJson(jdata["ar_coeffs_cr_plus_128"], &data->ar_coeffs_cr_plus_128, options);
        FieldToJson(jdata["cb_mult"], data->decoded_value->cb_mult, options);
        FieldToJson(jdata["cb_luma_mult"], data->decoded_value->cb_luma_mult, options);
        FieldToJson(jdata["cb_offset"], data->decoded_value->cb_offset, options);
        FieldToJson(jdata["cr_mult"], data->decoded_value->cr_mult, options);
        FieldToJson(jdata["cr_luma_mult"], data->decoded_value->cr_luma_mult, options);
        FieldToJson(jdata["cr_offset"], data->decoded_value->cr_offset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeAV1PictureInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["error_resilient_mode"], data->decoded_value->error_resilient_mode, options);
        FieldToJson(jdata["disable_cdf_update"], data->decoded_value->disable_cdf_update, options);
        FieldToJson(jdata["use_superres"], data->decoded_value->use_superres, options);
        FieldToJson(jdata["render_and_frame_size_different"], data->decoded_value->render_and_frame_size_different, options);
        FieldToJson(jdata["allow_screen_content_tools"], data->decoded_value->allow_screen_content_tools, options);
        FieldToJson(jdata["is_filter_switchable"], data->decoded_value->is_filter_switchable, options);
        FieldToJson(jdata["force_integer_mv"], data->decoded_value->force_integer_mv, options);
        FieldToJson(jdata["frame_size_override_flag"], data->decoded_value->frame_size_override_flag, options);
        FieldToJson(jdata["buffer_removal_time_present_flag"], data->decoded_value->buffer_removal_time_present_flag, options);
        FieldToJson(jdata["allow_intrabc"], data->decoded_value->allow_intrabc, options);
        FieldToJson(jdata["frame_refs_short_signaling"], data->decoded_value->frame_refs_short_signaling, options);
        FieldToJson(jdata["allow_high_precision_mv"], data->decoded_value->allow_high_precision_mv, options);
        FieldToJson(jdata["is_motion_mode_switchable"], data->decoded_value->is_motion_mode_switchable, options);
        FieldToJson(jdata["use_ref_frame_mvs"], data->decoded_value->use_ref_frame_mvs, options);
        FieldToJson(jdata["disable_frame_end_update_cdf"], data->decoded_value->disable_frame_end_update_cdf, options);
        FieldToJson(jdata["allow_warped_motion"], data->decoded_value->allow_warped_motion, options);
        FieldToJson(jdata["reduced_tx_set"], data->decoded_value->reduced_tx_set, options);
        FieldToJson(jdata["reference_select"], data->decoded_value->reference_select, options);
        FieldToJson(jdata["skip_mode_present"], data->decoded_value->skip_mode_present, options);
        FieldToJson(jdata["delta_q_present"], data->decoded_value->delta_q_present, options);
        FieldToJson(jdata["delta_lf_present"], data->decoded_value->delta_lf_present, options);
        FieldToJson(jdata["delta_lf_multi"], data->decoded_value->delta_lf_multi, options);
        FieldToJson(jdata["segmentation_enabled"], data->decoded_value->segmentation_enabled, options);
        FieldToJson(jdata["segmentation_update_map"], data->decoded_value->segmentation_update_map, options);
        FieldToJson(jdata["segmentation_temporal_update"], data->decoded_value->segmentation_temporal_update, options);
        FieldToJson(jdata["segmentation_update_data"], data->decoded_value->segmentation_update_data, options);
        FieldToJson(jdata["UsesLr"], data->decoded_value->UsesLr, options);
        FieldToJson(jdata["usesChromaLr"], data->decoded_value->usesChromaLr, options);
        FieldToJson(jdata["apply_grain"], data->decoded_value->apply_grain, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeAV1PictureInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["frame_type"], data->decoded_value->frame_type, options);
        FieldToJson(jdata["current_frame_id"], data->decoded_value->current_frame_id, options);
        FieldToJson(jdata["OrderHint"], data->decoded_value->OrderHint, options);
        FieldToJson(jdata["primary_ref_frame"], data->decoded_value->primary_ref_frame, options);
        FieldToJson(jdata["refresh_frame_flags"], data->decoded_value->refresh_frame_flags, options);
        FieldToJson(jdata["reserved1"], data->decoded_value->reserved1, options);
        FieldToJson(jdata["interpolation_filter"], data->decoded_value->interpolation_filter, options);
        FieldToJson(jdata["TxMode"], data->decoded_value->TxMode, options);
        FieldToJson(jdata["delta_q_res"], data->decoded_value->delta_q_res, options);
        FieldToJson(jdata["delta_lf_res"], data->decoded_value->delta_lf_res, options);
        FieldToJson(jdata["SkipModeFrame"], &data->SkipModeFrame, options);
        FieldToJson(jdata["coded_denom"], data->decoded_value->coded_denom, options);
        FieldToJson(jdata["reserved2"], &data->reserved2, options);
        FieldToJson(jdata["OrderHints"], &data->OrderHints, options);
        FieldToJson(jdata["expectedFrameId"], &data->expectedFrameId, options);
        FieldToJson(jdata["pTileInfo"], data->pTileInfo, options);
        FieldToJson(jdata["pQuantization"], data->pQuantization, options);
        FieldToJson(jdata["pSegmentation"], data->pSegmentation, options);
        FieldToJson(jdata["pLoopFilter"], data->pLoopFilter, options);
        FieldToJson(jdata["pCDEF"], data->pCDEF, options);
        FieldToJson(jdata["pLoopRestoration"], data->pLoopRestoration, options);
        FieldToJson(jdata["pGlobalMotion"], data->pGlobalMotion, options);
        FieldToJson(jdata["pFilmGrain"], data->pFilmGrain, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeAV1ReferenceInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["disable_frame_end_update_cdf"], data->decoded_value->disable_frame_end_update_cdf, options);
        FieldToJson(jdata["segmentation_enabled"], data->decoded_value->segmentation_enabled, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoDecodeAV1ReferenceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["frame_type"], data->decoded_value->frame_type, options);
        FieldToJson(jdata["RefFrameSignBias"], data->decoded_value->RefFrameSignBias, options);
        FieldToJson(jdata["OrderHint"], data->decoded_value->OrderHint, options);
        FieldToJson(jdata["SavedOrderHints"], &data->SavedOrderHints, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeAV1ExtensionHeader* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["temporal_id"], data->decoded_value->temporal_id, options);
        FieldToJson(jdata["spatial_id"], data->decoded_value->spatial_id, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeAV1DecoderModelInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["buffer_delay_length_minus_1"], data->decoded_value->buffer_delay_length_minus_1, options);
        FieldToJson(jdata["buffer_removal_time_length_minus_1"], data->decoded_value->buffer_removal_time_length_minus_1, options);
        FieldToJson(jdata["frame_presentation_time_length_minus_1"], data->decoded_value->frame_presentation_time_length_minus_1, options);
        FieldToJson(jdata["reserved1"], data->decoded_value->reserved1, options);
        FieldToJson(jdata["num_units_in_decoding_tick"], data->decoded_value->num_units_in_decoding_tick, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeAV1OperatingPointInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["decoder_model_present_for_this_op"], data->decoded_value->decoder_model_present_for_this_op, options);
        FieldToJson(jdata["low_delay_mode_flag"], data->decoded_value->low_delay_mode_flag, options);
        FieldToJson(jdata["initial_display_delay_present_for_this_op"], data->decoded_value->initial_display_delay_present_for_this_op, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeAV1OperatingPointInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["operating_point_idc"], data->decoded_value->operating_point_idc, options);
        FieldToJson(jdata["seq_level_idx"], data->decoded_value->seq_level_idx, options);
        FieldToJson(jdata["seq_tier"], data->decoded_value->seq_tier, options);
        FieldToJson(jdata["decoder_buffer_delay"], data->decoded_value->decoder_buffer_delay, options);
        FieldToJson(jdata["encoder_buffer_delay"], data->decoded_value->encoder_buffer_delay, options);
        FieldToJson(jdata["initial_display_delay_minus_1"], data->decoded_value->initial_display_delay_minus_1, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeAV1PictureInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["error_resilient_mode"], data->decoded_value->error_resilient_mode, options);
        FieldToJson(jdata["disable_cdf_update"], data->decoded_value->disable_cdf_update, options);
        FieldToJson(jdata["use_superres"], data->decoded_value->use_superres, options);
        FieldToJson(jdata["render_and_frame_size_different"], data->decoded_value->render_and_frame_size_different, options);
        FieldToJson(jdata["allow_screen_content_tools"], data->decoded_value->allow_screen_content_tools, options);
        FieldToJson(jdata["is_filter_switchable"], data->decoded_value->is_filter_switchable, options);
        FieldToJson(jdata["force_integer_mv"], data->decoded_value->force_integer_mv, options);
        FieldToJson(jdata["frame_size_override_flag"], data->decoded_value->frame_size_override_flag, options);
        FieldToJson(jdata["buffer_removal_time_present_flag"], data->decoded_value->buffer_removal_time_present_flag, options);
        FieldToJson(jdata["allow_intrabc"], data->decoded_value->allow_intrabc, options);
        FieldToJson(jdata["frame_refs_short_signaling"], data->decoded_value->frame_refs_short_signaling, options);
        FieldToJson(jdata["allow_high_precision_mv"], data->decoded_value->allow_high_precision_mv, options);
        FieldToJson(jdata["is_motion_mode_switchable"], data->decoded_value->is_motion_mode_switchable, options);
        FieldToJson(jdata["use_ref_frame_mvs"], data->decoded_value->use_ref_frame_mvs, options);
        FieldToJson(jdata["disable_frame_end_update_cdf"], data->decoded_value->disable_frame_end_update_cdf, options);
        FieldToJson(jdata["allow_warped_motion"], data->decoded_value->allow_warped_motion, options);
        FieldToJson(jdata["reduced_tx_set"], data->decoded_value->reduced_tx_set, options);
        FieldToJson(jdata["skip_mode_present"], data->decoded_value->skip_mode_present, options);
        FieldToJson(jdata["delta_q_present"], data->decoded_value->delta_q_present, options);
        FieldToJson(jdata["delta_lf_present"], data->decoded_value->delta_lf_present, options);
        FieldToJson(jdata["delta_lf_multi"], data->decoded_value->delta_lf_multi, options);
        FieldToJson(jdata["segmentation_enabled"], data->decoded_value->segmentation_enabled, options);
        FieldToJson(jdata["segmentation_update_map"], data->decoded_value->segmentation_update_map, options);
        FieldToJson(jdata["segmentation_temporal_update"], data->decoded_value->segmentation_temporal_update, options);
        FieldToJson(jdata["segmentation_update_data"], data->decoded_value->segmentation_update_data, options);
        FieldToJson(jdata["UsesLr"], data->decoded_value->UsesLr, options);
        FieldToJson(jdata["usesChromaLr"], data->decoded_value->usesChromaLr, options);
        FieldToJson(jdata["show_frame"], data->decoded_value->show_frame, options);
        FieldToJson(jdata["showable_frame"], data->decoded_value->showable_frame, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeAV1PictureInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["frame_type"], data->decoded_value->frame_type, options);
        FieldToJson(jdata["frame_presentation_time"], data->decoded_value->frame_presentation_time, options);
        FieldToJson(jdata["current_frame_id"], data->decoded_value->current_frame_id, options);
        FieldToJson(jdata["order_hint"], data->decoded_value->order_hint, options);
        FieldToJson(jdata["primary_ref_frame"], data->decoded_value->primary_ref_frame, options);
        FieldToJson(jdata["refresh_frame_flags"], data->decoded_value->refresh_frame_flags, options);
        FieldToJson(jdata["coded_denom"], data->decoded_value->coded_denom, options);
        FieldToJson(jdata["render_width_minus_1"], data->decoded_value->render_width_minus_1, options);
        FieldToJson(jdata["render_height_minus_1"], data->decoded_value->render_height_minus_1, options);
        FieldToJson(jdata["interpolation_filter"], data->decoded_value->interpolation_filter, options);
        FieldToJson(jdata["TxMode"], data->decoded_value->TxMode, options);
        FieldToJson(jdata["delta_q_res"], data->decoded_value->delta_q_res, options);
        FieldToJson(jdata["delta_lf_res"], data->decoded_value->delta_lf_res, options);
        FieldToJson(jdata["ref_order_hint"], &data->ref_order_hint, options);
        FieldToJson(jdata["ref_frame_idx"], &data->ref_frame_idx, options);
        FieldToJson(jdata["reserved1"], &data->reserved1, options);
        FieldToJson(jdata["delta_frame_id_minus_1"], &data->delta_frame_id_minus_1, options);
        FieldToJson(jdata["pTileInfo"], data->pTileInfo, options);
        FieldToJson(jdata["pQuantization"], data->pQuantization, options);
        FieldToJson(jdata["pSegmentation"], data->pSegmentation, options);
        FieldToJson(jdata["pLoopFilter"], data->pLoopFilter, options);
        FieldToJson(jdata["pCDEF"], data->pCDEF, options);
        FieldToJson(jdata["pLoopRestoration"], data->pLoopRestoration, options);
        FieldToJson(jdata["pGlobalMotion"], data->pGlobalMotion, options);
        FieldToJson(jdata["pExtensionHeader"], data->pExtensionHeader, options);
        FieldToJson(jdata["pBufferRemovalTimes"], data->pBufferRemovalTimes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeAV1ReferenceInfoFlags* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["disable_frame_end_update_cdf"], data->decoded_value->disable_frame_end_update_cdf, options);
        FieldToJson(jdata["segmentation_enabled"], data->decoded_value->segmentation_enabled, options);
        FieldToJson(jdata["reserved"], data->decoded_value->reserved, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_StdVideoEncodeAV1ReferenceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["flags"], data->flags, options);
        FieldToJson(jdata["RefFrameId"], data->decoded_value->RefFrameId, options);
        FieldToJson(jdata["frame_type"], data->decoded_value->frame_type, options);
        FieldToJson(jdata["OrderHint"], data->decoded_value->OrderHint, options);
        FieldToJson(jdata["reserved1"], &data->reserved1, options);
        FieldToJson(jdata["pExtensionHeader"], data->pExtensionHeader, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExtent2D* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExtent3D* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["depth"], data->decoded_value->depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOffset2D* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOffset3D* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
        FieldToJson(jdata["z"], data->decoded_value->z, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRect2D* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["offset"], data->offset, options);
        FieldToJson(jdata["extent"], data->extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferMemoryBarrier* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkAccessFlags_t(),jdata["srcAccessMask"], data->decoded_value->srcAccessMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["dstAccessMask"], data->decoded_value->dstAccessMask, options);
        FieldToJson(jdata["srcQueueFamilyIndex"], data->decoded_value->srcQueueFamilyIndex, options);
        FieldToJson(jdata["dstQueueFamilyIndex"], data->decoded_value->dstQueueFamilyIndex, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSubresourceRange* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], data->decoded_value->aspectMask, options);
        FieldToJson(jdata["baseMipLevel"], data->decoded_value->baseMipLevel, options);
        FieldToJson(jdata["levelCount"], data->decoded_value->levelCount, options);
        FieldToJson(jdata["baseArrayLayer"], data->decoded_value->baseArrayLayer, options);
        FieldToJson(jdata["layerCount"], data->decoded_value->layerCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageMemoryBarrier* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkAccessFlags_t(),jdata["srcAccessMask"], data->decoded_value->srcAccessMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["dstAccessMask"], data->decoded_value->dstAccessMask, options);
        FieldToJson(jdata["oldLayout"], data->decoded_value->oldLayout, options);
        FieldToJson(jdata["newLayout"], data->decoded_value->newLayout, options);
        FieldToJson(jdata["srcQueueFamilyIndex"], data->decoded_value->srcQueueFamilyIndex, options);
        FieldToJson(jdata["dstQueueFamilyIndex"], data->decoded_value->dstQueueFamilyIndex, options);
        HandleToJson(jdata["image"], data->image, options);
        FieldToJson(jdata["subresourceRange"], data->subresourceRange, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryBarrier* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkAccessFlags_t(),jdata["srcAccessMask"], data->decoded_value->srcAccessMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["dstAccessMask"], data->decoded_value->dstAccessMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAllocationCallbacks* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pUserData"], to_hex_variable_width(data->pUserData), options);
        FieldToJson(jdata["pfnAllocation"], to_hex_variable_width(data->pfnAllocation), options);
        FieldToJson(jdata["pfnReallocation"], to_hex_variable_width(data->pfnReallocation), options);
        FieldToJson(jdata["pfnFree"], to_hex_variable_width(data->pfnFree), options);
        FieldToJson(jdata["pfnInternalAllocation"], to_hex_variable_width(data->pfnInternalAllocation), options);
        FieldToJson(jdata["pfnInternalFree"], to_hex_variable_width(data->pfnInternalFree), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkApplicationInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pApplicationName"], &data->pApplicationName, options);
        FieldToJson(jdata["applicationVersion"], data->decoded_value->applicationVersion, options);
        FieldToJson(jdata["pEngineName"], &data->pEngineName, options);
        FieldToJson(jdata["engineVersion"], data->decoded_value->engineVersion, options);
        FieldToJson(jdata["apiVersion"], data->decoded_value->apiVersion, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFormatProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkFormatFeatureFlags_t(),jdata["linearTilingFeatures"], data->decoded_value->linearTilingFeatures, options);
        FieldToJson(VkFormatFeatureFlags_t(),jdata["optimalTilingFeatures"], data->decoded_value->optimalTilingFeatures, options);
        FieldToJson(VkFormatFeatureFlags_t(),jdata["bufferFeatures"], data->decoded_value->bufferFeatures, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageFormatProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["maxExtent"], data->maxExtent, options);
        FieldToJson(jdata["maxMipLevels"], data->decoded_value->maxMipLevels, options);
        FieldToJson(jdata["maxArrayLayers"], data->decoded_value->maxArrayLayers, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampleCounts"], data->decoded_value->sampleCounts, options);
        FieldToJson(jdata["maxResourceSize"], data->decoded_value->maxResourceSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkInstanceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkInstanceCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pApplicationInfo"], data->pApplicationInfo, options);
        FieldToJson(jdata["enabledLayerCount"], data->decoded_value->enabledLayerCount, options);
        FieldToJson(jdata["ppEnabledLayerNames"], &data->ppEnabledLayerNames, options);
        FieldToJson(jdata["enabledExtensionCount"], data->decoded_value->enabledExtensionCount, options);
        FieldToJson(jdata["ppEnabledExtensionNames"], &data->ppEnabledExtensionNames, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryHeap* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(VkMemoryHeapFlags_t(),jdata["flags"], data->decoded_value->flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryType* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkMemoryPropertyFlags_t(),jdata["propertyFlags"], data->decoded_value->propertyFlags, options);
        FieldToJson(jdata["heapIndex"], data->decoded_value->heapIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        jdata["robustBufferAccess"] = static_cast<bool>(data->decoded_value->robustBufferAccess);
        jdata["fullDrawIndexUint32"] = static_cast<bool>(data->decoded_value->fullDrawIndexUint32);
        jdata["imageCubeArray"] = static_cast<bool>(data->decoded_value->imageCubeArray);
        jdata["independentBlend"] = static_cast<bool>(data->decoded_value->independentBlend);
        jdata["geometryShader"] = static_cast<bool>(data->decoded_value->geometryShader);
        jdata["tessellationShader"] = static_cast<bool>(data->decoded_value->tessellationShader);
        jdata["sampleRateShading"] = static_cast<bool>(data->decoded_value->sampleRateShading);
        jdata["dualSrcBlend"] = static_cast<bool>(data->decoded_value->dualSrcBlend);
        jdata["logicOp"] = static_cast<bool>(data->decoded_value->logicOp);
        jdata["multiDrawIndirect"] = static_cast<bool>(data->decoded_value->multiDrawIndirect);
        jdata["drawIndirectFirstInstance"] = static_cast<bool>(data->decoded_value->drawIndirectFirstInstance);
        jdata["depthClamp"] = static_cast<bool>(data->decoded_value->depthClamp);
        jdata["depthBiasClamp"] = static_cast<bool>(data->decoded_value->depthBiasClamp);
        jdata["fillModeNonSolid"] = static_cast<bool>(data->decoded_value->fillModeNonSolid);
        jdata["depthBounds"] = static_cast<bool>(data->decoded_value->depthBounds);
        jdata["wideLines"] = static_cast<bool>(data->decoded_value->wideLines);
        jdata["largePoints"] = static_cast<bool>(data->decoded_value->largePoints);
        jdata["alphaToOne"] = static_cast<bool>(data->decoded_value->alphaToOne);
        jdata["multiViewport"] = static_cast<bool>(data->decoded_value->multiViewport);
        jdata["samplerAnisotropy"] = static_cast<bool>(data->decoded_value->samplerAnisotropy);
        jdata["textureCompressionETC2"] = static_cast<bool>(data->decoded_value->textureCompressionETC2);
        jdata["textureCompressionASTC_LDR"] = static_cast<bool>(data->decoded_value->textureCompressionASTC_LDR);
        jdata["textureCompressionBC"] = static_cast<bool>(data->decoded_value->textureCompressionBC);
        jdata["occlusionQueryPrecise"] = static_cast<bool>(data->decoded_value->occlusionQueryPrecise);
        jdata["pipelineStatisticsQuery"] = static_cast<bool>(data->decoded_value->pipelineStatisticsQuery);
        jdata["vertexPipelineStoresAndAtomics"] = static_cast<bool>(data->decoded_value->vertexPipelineStoresAndAtomics);
        jdata["fragmentStoresAndAtomics"] = static_cast<bool>(data->decoded_value->fragmentStoresAndAtomics);
        jdata["shaderTessellationAndGeometryPointSize"] = static_cast<bool>(data->decoded_value->shaderTessellationAndGeometryPointSize);
        jdata["shaderImageGatherExtended"] = static_cast<bool>(data->decoded_value->shaderImageGatherExtended);
        jdata["shaderStorageImageExtendedFormats"] = static_cast<bool>(data->decoded_value->shaderStorageImageExtendedFormats);
        jdata["shaderStorageImageMultisample"] = static_cast<bool>(data->decoded_value->shaderStorageImageMultisample);
        jdata["shaderStorageImageReadWithoutFormat"] = static_cast<bool>(data->decoded_value->shaderStorageImageReadWithoutFormat);
        jdata["shaderStorageImageWriteWithoutFormat"] = static_cast<bool>(data->decoded_value->shaderStorageImageWriteWithoutFormat);
        jdata["shaderUniformBufferArrayDynamicIndexing"] = static_cast<bool>(data->decoded_value->shaderUniformBufferArrayDynamicIndexing);
        jdata["shaderSampledImageArrayDynamicIndexing"] = static_cast<bool>(data->decoded_value->shaderSampledImageArrayDynamicIndexing);
        jdata["shaderStorageBufferArrayDynamicIndexing"] = static_cast<bool>(data->decoded_value->shaderStorageBufferArrayDynamicIndexing);
        jdata["shaderStorageImageArrayDynamicIndexing"] = static_cast<bool>(data->decoded_value->shaderStorageImageArrayDynamicIndexing);
        jdata["shaderClipDistance"] = static_cast<bool>(data->decoded_value->shaderClipDistance);
        jdata["shaderCullDistance"] = static_cast<bool>(data->decoded_value->shaderCullDistance);
        jdata["shaderFloat64"] = static_cast<bool>(data->decoded_value->shaderFloat64);
        jdata["shaderInt64"] = static_cast<bool>(data->decoded_value->shaderInt64);
        jdata["shaderInt16"] = static_cast<bool>(data->decoded_value->shaderInt16);
        jdata["shaderResourceResidency"] = static_cast<bool>(data->decoded_value->shaderResourceResidency);
        jdata["shaderResourceMinLod"] = static_cast<bool>(data->decoded_value->shaderResourceMinLod);
        jdata["sparseBinding"] = static_cast<bool>(data->decoded_value->sparseBinding);
        jdata["sparseResidencyBuffer"] = static_cast<bool>(data->decoded_value->sparseResidencyBuffer);
        jdata["sparseResidencyImage2D"] = static_cast<bool>(data->decoded_value->sparseResidencyImage2D);
        jdata["sparseResidencyImage3D"] = static_cast<bool>(data->decoded_value->sparseResidencyImage3D);
        jdata["sparseResidency2Samples"] = static_cast<bool>(data->decoded_value->sparseResidency2Samples);
        jdata["sparseResidency4Samples"] = static_cast<bool>(data->decoded_value->sparseResidency4Samples);
        jdata["sparseResidency8Samples"] = static_cast<bool>(data->decoded_value->sparseResidency8Samples);
        jdata["sparseResidency16Samples"] = static_cast<bool>(data->decoded_value->sparseResidency16Samples);
        jdata["sparseResidencyAliased"] = static_cast<bool>(data->decoded_value->sparseResidencyAliased);
        jdata["variableMultisampleRate"] = static_cast<bool>(data->decoded_value->variableMultisampleRate);
        jdata["inheritedQueries"] = static_cast<bool>(data->decoded_value->inheritedQueries);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLimits* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["maxImageDimension1D"], data->decoded_value->maxImageDimension1D, options);
        FieldToJson(jdata["maxImageDimension2D"], data->decoded_value->maxImageDimension2D, options);
        FieldToJson(jdata["maxImageDimension3D"], data->decoded_value->maxImageDimension3D, options);
        FieldToJson(jdata["maxImageDimensionCube"], data->decoded_value->maxImageDimensionCube, options);
        FieldToJson(jdata["maxImageArrayLayers"], data->decoded_value->maxImageArrayLayers, options);
        FieldToJson(jdata["maxTexelBufferElements"], data->decoded_value->maxTexelBufferElements, options);
        FieldToJson(jdata["maxUniformBufferRange"], data->decoded_value->maxUniformBufferRange, options);
        FieldToJson(jdata["maxStorageBufferRange"], data->decoded_value->maxStorageBufferRange, options);
        FieldToJson(jdata["maxPushConstantsSize"], data->decoded_value->maxPushConstantsSize, options);
        FieldToJson(jdata["maxMemoryAllocationCount"], data->decoded_value->maxMemoryAllocationCount, options);
        FieldToJson(jdata["maxSamplerAllocationCount"], data->decoded_value->maxSamplerAllocationCount, options);
        FieldToJson(jdata["bufferImageGranularity"], data->decoded_value->bufferImageGranularity, options);
        FieldToJson(jdata["sparseAddressSpaceSize"], data->decoded_value->sparseAddressSpaceSize, options);
        FieldToJson(jdata["maxBoundDescriptorSets"], data->decoded_value->maxBoundDescriptorSets, options);
        FieldToJson(jdata["maxPerStageDescriptorSamplers"], data->decoded_value->maxPerStageDescriptorSamplers, options);
        FieldToJson(jdata["maxPerStageDescriptorUniformBuffers"], data->decoded_value->maxPerStageDescriptorUniformBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorStorageBuffers"], data->decoded_value->maxPerStageDescriptorStorageBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorSampledImages"], data->decoded_value->maxPerStageDescriptorSampledImages, options);
        FieldToJson(jdata["maxPerStageDescriptorStorageImages"], data->decoded_value->maxPerStageDescriptorStorageImages, options);
        FieldToJson(jdata["maxPerStageDescriptorInputAttachments"], data->decoded_value->maxPerStageDescriptorInputAttachments, options);
        FieldToJson(jdata["maxPerStageResources"], data->decoded_value->maxPerStageResources, options);
        FieldToJson(jdata["maxDescriptorSetSamplers"], data->decoded_value->maxDescriptorSetSamplers, options);
        FieldToJson(jdata["maxDescriptorSetUniformBuffers"], data->decoded_value->maxDescriptorSetUniformBuffers, options);
        FieldToJson(jdata["maxDescriptorSetUniformBuffersDynamic"], data->decoded_value->maxDescriptorSetUniformBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetStorageBuffers"], data->decoded_value->maxDescriptorSetStorageBuffers, options);
        FieldToJson(jdata["maxDescriptorSetStorageBuffersDynamic"], data->decoded_value->maxDescriptorSetStorageBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetSampledImages"], data->decoded_value->maxDescriptorSetSampledImages, options);
        FieldToJson(jdata["maxDescriptorSetStorageImages"], data->decoded_value->maxDescriptorSetStorageImages, options);
        FieldToJson(jdata["maxDescriptorSetInputAttachments"], data->decoded_value->maxDescriptorSetInputAttachments, options);
        FieldToJson(jdata["maxVertexInputAttributes"], data->decoded_value->maxVertexInputAttributes, options);
        FieldToJson(jdata["maxVertexInputBindings"], data->decoded_value->maxVertexInputBindings, options);
        FieldToJson(jdata["maxVertexInputAttributeOffset"], data->decoded_value->maxVertexInputAttributeOffset, options);
        FieldToJson(jdata["maxVertexInputBindingStride"], data->decoded_value->maxVertexInputBindingStride, options);
        FieldToJson(jdata["maxVertexOutputComponents"], data->decoded_value->maxVertexOutputComponents, options);
        FieldToJson(jdata["maxTessellationGenerationLevel"], data->decoded_value->maxTessellationGenerationLevel, options);
        FieldToJson(jdata["maxTessellationPatchSize"], data->decoded_value->maxTessellationPatchSize, options);
        FieldToJson(jdata["maxTessellationControlPerVertexInputComponents"], data->decoded_value->maxTessellationControlPerVertexInputComponents, options);
        FieldToJson(jdata["maxTessellationControlPerVertexOutputComponents"], data->decoded_value->maxTessellationControlPerVertexOutputComponents, options);
        FieldToJson(jdata["maxTessellationControlPerPatchOutputComponents"], data->decoded_value->maxTessellationControlPerPatchOutputComponents, options);
        FieldToJson(jdata["maxTessellationControlTotalOutputComponents"], data->decoded_value->maxTessellationControlTotalOutputComponents, options);
        FieldToJson(jdata["maxTessellationEvaluationInputComponents"], data->decoded_value->maxTessellationEvaluationInputComponents, options);
        FieldToJson(jdata["maxTessellationEvaluationOutputComponents"], data->decoded_value->maxTessellationEvaluationOutputComponents, options);
        FieldToJson(jdata["maxGeometryShaderInvocations"], data->decoded_value->maxGeometryShaderInvocations, options);
        FieldToJson(jdata["maxGeometryInputComponents"], data->decoded_value->maxGeometryInputComponents, options);
        FieldToJson(jdata["maxGeometryOutputComponents"], data->decoded_value->maxGeometryOutputComponents, options);
        FieldToJson(jdata["maxGeometryOutputVertices"], data->decoded_value->maxGeometryOutputVertices, options);
        FieldToJson(jdata["maxGeometryTotalOutputComponents"], data->decoded_value->maxGeometryTotalOutputComponents, options);
        FieldToJson(jdata["maxFragmentInputComponents"], data->decoded_value->maxFragmentInputComponents, options);
        FieldToJson(jdata["maxFragmentOutputAttachments"], data->decoded_value->maxFragmentOutputAttachments, options);
        FieldToJson(jdata["maxFragmentDualSrcAttachments"], data->decoded_value->maxFragmentDualSrcAttachments, options);
        FieldToJson(jdata["maxFragmentCombinedOutputResources"], data->decoded_value->maxFragmentCombinedOutputResources, options);
        FieldToJson(jdata["maxComputeSharedMemorySize"], data->decoded_value->maxComputeSharedMemorySize, options);
        FieldToJson(jdata["maxComputeWorkGroupCount"], &data->maxComputeWorkGroupCount, options);
        FieldToJson(jdata["maxComputeWorkGroupInvocations"], data->decoded_value->maxComputeWorkGroupInvocations, options);
        FieldToJson(jdata["maxComputeWorkGroupSize"], &data->maxComputeWorkGroupSize, options);
        FieldToJson(jdata["subPixelPrecisionBits"], data->decoded_value->subPixelPrecisionBits, options);
        FieldToJson(jdata["subTexelPrecisionBits"], data->decoded_value->subTexelPrecisionBits, options);
        FieldToJson(jdata["mipmapPrecisionBits"], data->decoded_value->mipmapPrecisionBits, options);
        FieldToJson(jdata["maxDrawIndexedIndexValue"], data->decoded_value->maxDrawIndexedIndexValue, options);
        FieldToJson(jdata["maxDrawIndirectCount"], data->decoded_value->maxDrawIndirectCount, options);
        FieldToJson(jdata["maxSamplerLodBias"], data->decoded_value->maxSamplerLodBias, options);
        FieldToJson(jdata["maxSamplerAnisotropy"], data->decoded_value->maxSamplerAnisotropy, options);
        FieldToJson(jdata["maxViewports"], data->decoded_value->maxViewports, options);
        FieldToJson(jdata["maxViewportDimensions"], &data->maxViewportDimensions, options);
        FieldToJson(jdata["viewportBoundsRange"], &data->viewportBoundsRange, options);
        FieldToJson(jdata["viewportSubPixelBits"], data->decoded_value->viewportSubPixelBits, options);
        FieldToJson(jdata["minMemoryMapAlignment"], data->decoded_value->minMemoryMapAlignment, options);
        FieldToJson(jdata["minTexelBufferOffsetAlignment"], data->decoded_value->minTexelBufferOffsetAlignment, options);
        FieldToJson(jdata["minUniformBufferOffsetAlignment"], data->decoded_value->minUniformBufferOffsetAlignment, options);
        FieldToJson(jdata["minStorageBufferOffsetAlignment"], data->decoded_value->minStorageBufferOffsetAlignment, options);
        FieldToJson(jdata["minTexelOffset"], data->decoded_value->minTexelOffset, options);
        FieldToJson(jdata["maxTexelOffset"], data->decoded_value->maxTexelOffset, options);
        FieldToJson(jdata["minTexelGatherOffset"], data->decoded_value->minTexelGatherOffset, options);
        FieldToJson(jdata["maxTexelGatherOffset"], data->decoded_value->maxTexelGatherOffset, options);
        FieldToJson(jdata["minInterpolationOffset"], data->decoded_value->minInterpolationOffset, options);
        FieldToJson(jdata["maxInterpolationOffset"], data->decoded_value->maxInterpolationOffset, options);
        FieldToJson(jdata["subPixelInterpolationOffsetBits"], data->decoded_value->subPixelInterpolationOffsetBits, options);
        FieldToJson(jdata["maxFramebufferWidth"], data->decoded_value->maxFramebufferWidth, options);
        FieldToJson(jdata["maxFramebufferHeight"], data->decoded_value->maxFramebufferHeight, options);
        FieldToJson(jdata["maxFramebufferLayers"], data->decoded_value->maxFramebufferLayers, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["framebufferColorSampleCounts"], data->decoded_value->framebufferColorSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["framebufferDepthSampleCounts"], data->decoded_value->framebufferDepthSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["framebufferStencilSampleCounts"], data->decoded_value->framebufferStencilSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["framebufferNoAttachmentsSampleCounts"], data->decoded_value->framebufferNoAttachmentsSampleCounts, options);
        FieldToJson(jdata["maxColorAttachments"], data->decoded_value->maxColorAttachments, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampledImageColorSampleCounts"], data->decoded_value->sampledImageColorSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampledImageIntegerSampleCounts"], data->decoded_value->sampledImageIntegerSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampledImageDepthSampleCounts"], data->decoded_value->sampledImageDepthSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampledImageStencilSampleCounts"], data->decoded_value->sampledImageStencilSampleCounts, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["storageImageSampleCounts"], data->decoded_value->storageImageSampleCounts, options);
        FieldToJson(jdata["maxSampleMaskWords"], data->decoded_value->maxSampleMaskWords, options);
        jdata["timestampComputeAndGraphics"] = static_cast<bool>(data->decoded_value->timestampComputeAndGraphics);
        FieldToJson(jdata["timestampPeriod"], data->decoded_value->timestampPeriod, options);
        FieldToJson(jdata["maxClipDistances"], data->decoded_value->maxClipDistances, options);
        FieldToJson(jdata["maxCullDistances"], data->decoded_value->maxCullDistances, options);
        FieldToJson(jdata["maxCombinedClipAndCullDistances"], data->decoded_value->maxCombinedClipAndCullDistances, options);
        FieldToJson(jdata["discreteQueuePriorities"], data->decoded_value->discreteQueuePriorities, options);
        FieldToJson(jdata["pointSizeRange"], &data->pointSizeRange, options);
        FieldToJson(jdata["lineWidthRange"], &data->lineWidthRange, options);
        FieldToJson(jdata["pointSizeGranularity"], data->decoded_value->pointSizeGranularity, options);
        FieldToJson(jdata["lineWidthGranularity"], data->decoded_value->lineWidthGranularity, options);
        jdata["strictLines"] = static_cast<bool>(data->decoded_value->strictLines);
        jdata["standardSampleLocations"] = static_cast<bool>(data->decoded_value->standardSampleLocations);
        FieldToJson(jdata["optimalBufferCopyOffsetAlignment"], data->decoded_value->optimalBufferCopyOffsetAlignment, options);
        FieldToJson(jdata["optimalBufferCopyRowPitchAlignment"], data->decoded_value->optimalBufferCopyRowPitchAlignment, options);
        FieldToJson(jdata["nonCoherentAtomSize"], data->decoded_value->nonCoherentAtomSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMemoryProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["memoryTypeCount"], data->decoded_value->memoryTypeCount, options);
        FieldToJson(jdata["memoryTypes"], data->memoryTypes, options);
        FieldToJson(jdata["memoryHeapCount"], data->decoded_value->memoryHeapCount, options);
        FieldToJson(jdata["memoryHeaps"], data->memoryHeaps, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSparseProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        jdata["residencyStandard2DBlockShape"] = static_cast<bool>(data->decoded_value->residencyStandard2DBlockShape);
        jdata["residencyStandard2DMultisampleBlockShape"] = static_cast<bool>(data->decoded_value->residencyStandard2DMultisampleBlockShape);
        jdata["residencyStandard3DBlockShape"] = static_cast<bool>(data->decoded_value->residencyStandard3DBlockShape);
        jdata["residencyAlignedMipSize"] = static_cast<bool>(data->decoded_value->residencyAlignedMipSize);
        jdata["residencyNonResidentStrict"] = static_cast<bool>(data->decoded_value->residencyNonResidentStrict);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["apiVersion"], data->decoded_value->apiVersion, options);
        FieldToJson(jdata["driverVersion"], data->decoded_value->driverVersion, options);
        FieldToJson(jdata["vendorID"], data->decoded_value->vendorID, options);
        FieldToJson(jdata["deviceID"], data->decoded_value->deviceID, options);
        FieldToJson(jdata["deviceType"], data->decoded_value->deviceType, options);
        FieldToJson(jdata["deviceName"], &data->deviceName, options);
        FieldToJson(jdata["pipelineCacheUUID"], uuid_to_string(sizeof(data->decoded_value->pipelineCacheUUID), data->decoded_value->pipelineCacheUUID), options);
        FieldToJson(jdata["limits"], data->limits, options);
        FieldToJson(jdata["sparseProperties"], data->sparseProperties, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkQueueFlags_t(),jdata["queueFlags"], data->decoded_value->queueFlags, options);
        FieldToJson(jdata["queueCount"], data->decoded_value->queueCount, options);
        FieldToJson(jdata["timestampValidBits"], data->decoded_value->timestampValidBits, options);
        FieldToJson(jdata["minImageTransferGranularity"], data->minImageTransferGranularity, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceQueueCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDeviceQueueCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["queueFamilyIndex"], data->decoded_value->queueFamilyIndex, options);
        FieldToJson(jdata["queueCount"], data->decoded_value->queueCount, options);
        FieldToJson(jdata["pQueuePriorities"], data->pQueuePriorities, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDeviceCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["queueCreateInfoCount"], data->decoded_value->queueCreateInfoCount, options);
        FieldToJson(jdata["pQueueCreateInfos"], data->pQueueCreateInfos, options);
        FieldToJson(jdata["enabledLayerCount"], data->decoded_value->enabledLayerCount, options);
        FieldToJson(jdata["ppEnabledLayerNames"], &data->ppEnabledLayerNames, options);
        FieldToJson(jdata["enabledExtensionCount"], data->decoded_value->enabledExtensionCount, options);
        FieldToJson(jdata["ppEnabledExtensionNames"], &data->ppEnabledExtensionNames, options);
        FieldToJson(jdata["pEnabledFeatures"], data->pEnabledFeatures, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExtensionProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["extensionName"], &data->extensionName, options);
        FieldToJson(jdata["specVersion"], data->decoded_value->specVersion, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkLayerProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["layerName"], &data->layerName, options);
        FieldToJson(jdata["specVersion"], data->decoded_value->specVersion, options);
        FieldToJson(jdata["implementationVersion"], data->decoded_value->implementationVersion, options);
        FieldToJson(jdata["description"], &data->description, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["waitSemaphoreCount"], data->decoded_value->waitSemaphoreCount, options);
        HandleToJson(jdata["pWaitSemaphores"], &data->pWaitSemaphores, options);
        FieldToJson(jdata["pWaitDstStageMask"], data->pWaitDstStageMask, options);
        FieldToJson(jdata["commandBufferCount"], data->decoded_value->commandBufferCount, options);
        HandleToJson(jdata["pCommandBuffers"], &data->pCommandBuffers, options);
        FieldToJson(jdata["signalSemaphoreCount"], data->decoded_value->signalSemaphoreCount, options);
        HandleToJson(jdata["pSignalSemaphores"], &data->pSignalSemaphores, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMappedMemoryRange* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["allocationSize"], data->decoded_value->allocationSize, options);
        FieldToJson(jdata["memoryTypeIndex"], data->decoded_value->memoryTypeIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryRequirements* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["alignment"], data->decoded_value->alignment, options);
        FieldToJson(jdata["memoryTypeBits"], data->decoded_value->memoryTypeBits, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseMemoryBind* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["resourceOffset"], data->decoded_value->resourceOffset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["memoryOffset"], data->decoded_value->memoryOffset, options);
        FieldToJson(VkSparseMemoryBindFlags_t(),jdata["flags"], data->decoded_value->flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseBufferMemoryBindInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["bindCount"], data->decoded_value->bindCount, options);
        FieldToJson(jdata["pBinds"], data->pBinds, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageOpaqueMemoryBindInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["image"], data->image, options);
        FieldToJson(jdata["bindCount"], data->decoded_value->bindCount, options);
        FieldToJson(jdata["pBinds"], data->pBinds, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSubresource* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], data->decoded_value->aspectMask, options);
        FieldToJson(jdata["mipLevel"], data->decoded_value->mipLevel, options);
        FieldToJson(jdata["arrayLayer"], data->decoded_value->arrayLayer, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageMemoryBind* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["subresource"], data->subresource, options);
        FieldToJson(jdata["offset"], data->offset, options);
        FieldToJson(jdata["extent"], data->extent, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["memoryOffset"], data->decoded_value->memoryOffset, options);
        FieldToJson(VkSparseMemoryBindFlags_t(),jdata["flags"], data->decoded_value->flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageMemoryBindInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["image"], data->image, options);
        FieldToJson(jdata["bindCount"], data->decoded_value->bindCount, options);
        FieldToJson(jdata["pBinds"], data->pBinds, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindSparseInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["waitSemaphoreCount"], data->decoded_value->waitSemaphoreCount, options);
        HandleToJson(jdata["pWaitSemaphores"], &data->pWaitSemaphores, options);
        FieldToJson(jdata["bufferBindCount"], data->decoded_value->bufferBindCount, options);
        FieldToJson(jdata["pBufferBinds"], data->pBufferBinds, options);
        FieldToJson(jdata["imageOpaqueBindCount"], data->decoded_value->imageOpaqueBindCount, options);
        FieldToJson(jdata["pImageOpaqueBinds"], data->pImageOpaqueBinds, options);
        FieldToJson(jdata["imageBindCount"], data->decoded_value->imageBindCount, options);
        FieldToJson(jdata["pImageBinds"], data->pImageBinds, options);
        FieldToJson(jdata["signalSemaphoreCount"], data->decoded_value->signalSemaphoreCount, options);
        HandleToJson(jdata["pSignalSemaphores"], &data->pSignalSemaphores, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageFormatProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], data->decoded_value->aspectMask, options);
        FieldToJson(jdata["imageGranularity"], data->imageGranularity, options);
        FieldToJson(VkSparseImageFormatFlags_t(),jdata["flags"], data->decoded_value->flags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageMemoryRequirements* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["formatProperties"], data->formatProperties, options);
        FieldToJson(jdata["imageMipTailFirstLod"], data->decoded_value->imageMipTailFirstLod, options);
        FieldToJson(jdata["imageMipTailSize"], data->decoded_value->imageMipTailSize, options);
        FieldToJson(jdata["imageMipTailOffset"], data->decoded_value->imageMipTailOffset, options);
        FieldToJson(jdata["imageMipTailStride"], data->decoded_value->imageMipTailStride, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFenceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkFenceCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkSemaphoreCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueryPoolCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkQueryPoolCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["queryType"], data->decoded_value->queryType, options);
        FieldToJson(jdata["queryCount"], data->decoded_value->queryCount, options);
        FieldToJson(VkQueryPipelineStatisticFlags_t(),jdata["pipelineStatistics"], data->decoded_value->pipelineStatistics, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkBufferCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(VkBufferUsageFlags_t(),jdata["usage"], data->decoded_value->usage, options);
        FieldToJson(jdata["sharingMode"], data->decoded_value->sharingMode, options);
        FieldToJson(jdata["queueFamilyIndexCount"], data->decoded_value->queueFamilyIndexCount, options);
        FieldToJson(jdata["pQueueFamilyIndices"], data->pQueueFamilyIndices, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkImageCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["imageType"], data->decoded_value->imageType, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["extent"], data->extent, options);
        FieldToJson(jdata["mipLevels"], data->decoded_value->mipLevels, options);
        FieldToJson(jdata["arrayLayers"], data->decoded_value->arrayLayers, options);
        FieldToJson(jdata["samples"], data->decoded_value->samples, options);
        FieldToJson(jdata["tiling"], data->decoded_value->tiling, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["usage"], data->decoded_value->usage, options);
        FieldToJson(jdata["sharingMode"], data->decoded_value->sharingMode, options);
        FieldToJson(jdata["queueFamilyIndexCount"], data->decoded_value->queueFamilyIndexCount, options);
        FieldToJson(jdata["pQueueFamilyIndices"], data->pQueueFamilyIndices, options);
        FieldToJson(jdata["initialLayout"], data->decoded_value->initialLayout, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubresourceLayout* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["rowPitch"], data->decoded_value->rowPitch, options);
        FieldToJson(jdata["arrayPitch"], data->decoded_value->arrayPitch, options);
        FieldToJson(jdata["depthPitch"], data->decoded_value->depthPitch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkComponentMapping* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["r"], data->decoded_value->r, options);
        FieldToJson(jdata["g"], data->decoded_value->g, options);
        FieldToJson(jdata["b"], data->decoded_value->b, options);
        FieldToJson(jdata["a"], data->decoded_value->a, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkImageViewCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["image"], data->image, options);
        FieldToJson(jdata["viewType"], data->decoded_value->viewType, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["components"], data->components, options);
        FieldToJson(jdata["subresourceRange"], data->subresourceRange, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandPoolCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkCommandPoolCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["queueFamilyIndex"], data->decoded_value->queueFamilyIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["commandPool"], data->commandPool, options);
        FieldToJson(jdata["level"], data->decoded_value->level, options);
        FieldToJson(jdata["commandBufferCount"], data->decoded_value->commandBufferCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferInheritanceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["renderPass"], data->renderPass, options);
        FieldToJson(jdata["subpass"], data->decoded_value->subpass, options);
        HandleToJson(jdata["framebuffer"], data->framebuffer, options);
        jdata["occlusionQueryEnable"] = static_cast<bool>(data->decoded_value->occlusionQueryEnable);
        FieldToJson(VkQueryControlFlags_t(),jdata["queryFlags"], data->decoded_value->queryFlags, options);
        FieldToJson(VkQueryPipelineStatisticFlags_t(),jdata["pipelineStatistics"], data->decoded_value->pipelineStatistics, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkCommandBufferUsageFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pInheritanceInfo"], data->pInheritanceInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferCopy* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["srcOffset"], data->decoded_value->srcOffset, options);
        FieldToJson(jdata["dstOffset"], data->decoded_value->dstOffset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSubresourceLayers* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], data->decoded_value->aspectMask, options);
        FieldToJson(jdata["mipLevel"], data->decoded_value->mipLevel, options);
        FieldToJson(jdata["baseArrayLayer"], data->decoded_value->baseArrayLayer, options);
        FieldToJson(jdata["layerCount"], data->decoded_value->layerCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferImageCopy* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["bufferOffset"], data->decoded_value->bufferOffset, options);
        FieldToJson(jdata["bufferRowLength"], data->decoded_value->bufferRowLength, options);
        FieldToJson(jdata["bufferImageHeight"], data->decoded_value->bufferImageHeight, options);
        FieldToJson(jdata["imageSubresource"], data->imageSubresource, options);
        FieldToJson(jdata["imageOffset"], data->imageOffset, options);
        FieldToJson(jdata["imageExtent"], data->imageExtent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageCopy* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["srcSubresource"], data->srcSubresource, options);
        FieldToJson(jdata["srcOffset"], data->srcOffset, options);
        FieldToJson(jdata["dstSubresource"], data->dstSubresource, options);
        FieldToJson(jdata["dstOffset"], data->dstOffset, options);
        FieldToJson(jdata["extent"], data->extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDispatchIndirectCommand* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
        FieldToJson(jdata["z"], data->decoded_value->z, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCacheHeaderVersionOne* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["headerSize"], data->decoded_value->headerSize, options);
        FieldToJson(jdata["headerVersion"], data->decoded_value->headerVersion, options);
        FieldToJson(jdata["vendorID"], data->decoded_value->vendorID, options);
        FieldToJson(jdata["deviceID"], data->decoded_value->deviceID, options);
        FieldToJson(jdata["pipelineCacheUUID"], uuid_to_string(sizeof(data->decoded_value->pipelineCacheUUID), data->decoded_value->pipelineCacheUUID), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkEventCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkEventCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferViewCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkBufferViewCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["range"], data->decoded_value->range, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSpecializationMapEntry* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["constantID"], data->decoded_value->constantID, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSpecializationInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["mapEntryCount"], data->decoded_value->mapEntryCount, options);
        FieldToJson(jdata["pMapEntries"], data->pMapEntries, options);
        FieldToJson(jdata["dataSize"], data->decoded_value->dataSize, options);
        FieldToJson(jdata["pData"], data->pData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineShaderStageCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineShaderStageCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["stage"], data->decoded_value->stage, options);
        HandleToJson(jdata["module"], data->module, options);
        FieldToJson(jdata["pName"], &data->pName, options);
        FieldToJson(jdata["pSpecializationInfo"], data->pSpecializationInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkComputePipelineCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["stage"], data->stage, options);
        HandleToJson(jdata["layout"], data->layout, options);
        HandleToJson(jdata["basePipelineHandle"], data->basePipelineHandle, options);
        FieldToJson(jdata["basePipelineIndex"], data->decoded_value->basePipelineIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPushConstantRange* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkShaderStageFlags_t(),jdata["stageFlags"], data->decoded_value->stageFlags, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineLayoutCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineLayoutCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["setLayoutCount"], data->decoded_value->setLayoutCount, options);
        HandleToJson(jdata["pSetLayouts"], &data->pSetLayouts, options);
        FieldToJson(jdata["pushConstantRangeCount"], data->decoded_value->pushConstantRangeCount, options);
        FieldToJson(jdata["pPushConstantRanges"], data->pPushConstantRanges, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkSamplerCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["magFilter"], data->decoded_value->magFilter, options);
        FieldToJson(jdata["minFilter"], data->decoded_value->minFilter, options);
        FieldToJson(jdata["mipmapMode"], data->decoded_value->mipmapMode, options);
        FieldToJson(jdata["addressModeU"], data->decoded_value->addressModeU, options);
        FieldToJson(jdata["addressModeV"], data->decoded_value->addressModeV, options);
        FieldToJson(jdata["addressModeW"], data->decoded_value->addressModeW, options);
        FieldToJson(jdata["mipLodBias"], data->decoded_value->mipLodBias, options);
        jdata["anisotropyEnable"] = static_cast<bool>(data->decoded_value->anisotropyEnable);
        FieldToJson(jdata["maxAnisotropy"], data->decoded_value->maxAnisotropy, options);
        jdata["compareEnable"] = static_cast<bool>(data->decoded_value->compareEnable);
        FieldToJson(jdata["compareOp"], data->decoded_value->compareOp, options);
        FieldToJson(jdata["minLod"], data->decoded_value->minLod, options);
        FieldToJson(jdata["maxLod"], data->decoded_value->maxLod, options);
        FieldToJson(jdata["borderColor"], data->decoded_value->borderColor, options);
        jdata["unnormalizedCoordinates"] = static_cast<bool>(data->decoded_value->unnormalizedCoordinates);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyDescriptorSet* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["srcSet"], data->srcSet, options);
        FieldToJson(jdata["srcBinding"], data->decoded_value->srcBinding, options);
        FieldToJson(jdata["srcArrayElement"], data->decoded_value->srcArrayElement, options);
        HandleToJson(jdata["dstSet"], data->dstSet, options);
        FieldToJson(jdata["dstBinding"], data->decoded_value->dstBinding, options);
        FieldToJson(jdata["dstArrayElement"], data->decoded_value->dstArrayElement, options);
        FieldToJson(jdata["descriptorCount"], data->decoded_value->descriptorCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorBufferInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["range"], data->decoded_value->range, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorPoolSize* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["descriptorCount"], data->decoded_value->descriptorCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorPoolCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDescriptorPoolCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["maxSets"], data->decoded_value->maxSets, options);
        FieldToJson(jdata["poolSizeCount"], data->decoded_value->poolSizeCount, options);
        FieldToJson(jdata["pPoolSizes"], data->pPoolSizes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["descriptorPool"], data->descriptorPool, options);
        FieldToJson(jdata["descriptorSetCount"], data->decoded_value->descriptorSetCount, options);
        HandleToJson(jdata["pSetLayouts"], &data->pSetLayouts, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetLayoutBinding* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["binding"], data->decoded_value->binding, options);
        FieldToJson(jdata["descriptorType"], data->decoded_value->descriptorType, options);
        FieldToJson(jdata["descriptorCount"], data->decoded_value->descriptorCount, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["stageFlags"], data->decoded_value->stageFlags, options);
        HandleToJson(jdata["pImmutableSamplers"], &data->pImmutableSamplers, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetLayoutCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDescriptorSetLayoutCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["bindingCount"], data->decoded_value->bindingCount, options);
        FieldToJson(jdata["pBindings"], data->pBindings, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrawIndexedIndirectCommand* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["indexCount"], data->decoded_value->indexCount, options);
        FieldToJson(jdata["instanceCount"], data->decoded_value->instanceCount, options);
        FieldToJson(jdata["firstIndex"], data->decoded_value->firstIndex, options);
        FieldToJson(jdata["vertexOffset"], data->decoded_value->vertexOffset, options);
        FieldToJson(jdata["firstInstance"], data->decoded_value->firstInstance, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrawIndirectCommand* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["vertexCount"], data->decoded_value->vertexCount, options);
        FieldToJson(jdata["instanceCount"], data->decoded_value->instanceCount, options);
        FieldToJson(jdata["firstVertex"], data->decoded_value->firstVertex, options);
        FieldToJson(jdata["firstInstance"], data->decoded_value->firstInstance, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVertexInputBindingDescription* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["binding"], data->decoded_value->binding, options);
        FieldToJson(jdata["stride"], data->decoded_value->stride, options);
        FieldToJson(jdata["inputRate"], data->decoded_value->inputRate, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVertexInputAttributeDescription* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["location"], data->decoded_value->location, options);
        FieldToJson(jdata["binding"], data->decoded_value->binding, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineVertexInputStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineVertexInputStateCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["vertexBindingDescriptionCount"], data->decoded_value->vertexBindingDescriptionCount, options);
        FieldToJson(jdata["pVertexBindingDescriptions"], data->pVertexBindingDescriptions, options);
        FieldToJson(jdata["vertexAttributeDescriptionCount"], data->decoded_value->vertexAttributeDescriptionCount, options);
        FieldToJson(jdata["pVertexAttributeDescriptions"], data->pVertexAttributeDescriptions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineInputAssemblyStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineInputAssemblyStateCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["topology"], data->decoded_value->topology, options);
        jdata["primitiveRestartEnable"] = static_cast<bool>(data->decoded_value->primitiveRestartEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineTessellationStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineTessellationStateCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["patchControlPoints"], data->decoded_value->patchControlPoints, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkViewport* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["minDepth"], data->decoded_value->minDepth, options);
        FieldToJson(jdata["maxDepth"], data->decoded_value->maxDepth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineViewportStateCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["viewportCount"], data->decoded_value->viewportCount, options);
        FieldToJson(jdata["pViewports"], data->pViewports, options);
        FieldToJson(jdata["scissorCount"], data->decoded_value->scissorCount, options);
        FieldToJson(jdata["pScissors"], data->pScissors, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineRasterizationStateCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        jdata["depthClampEnable"] = static_cast<bool>(data->decoded_value->depthClampEnable);
        jdata["rasterizerDiscardEnable"] = static_cast<bool>(data->decoded_value->rasterizerDiscardEnable);
        FieldToJson(jdata["polygonMode"], data->decoded_value->polygonMode, options);
        FieldToJson(VkCullModeFlags_t(),jdata["cullMode"], data->decoded_value->cullMode, options);
        FieldToJson(jdata["frontFace"], data->decoded_value->frontFace, options);
        jdata["depthBiasEnable"] = static_cast<bool>(data->decoded_value->depthBiasEnable);
        FieldToJson(jdata["depthBiasConstantFactor"], data->decoded_value->depthBiasConstantFactor, options);
        FieldToJson(jdata["depthBiasClamp"], data->decoded_value->depthBiasClamp, options);
        FieldToJson(jdata["depthBiasSlopeFactor"], data->decoded_value->depthBiasSlopeFactor, options);
        FieldToJson(jdata["lineWidth"], data->decoded_value->lineWidth, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineMultisampleStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineMultisampleStateCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["rasterizationSamples"], data->decoded_value->rasterizationSamples, options);
        jdata["sampleShadingEnable"] = static_cast<bool>(data->decoded_value->sampleShadingEnable);
        FieldToJson(jdata["minSampleShading"], data->decoded_value->minSampleShading, options);
        FieldToJson(jdata["pSampleMask"], data->pSampleMask, options);
        jdata["alphaToCoverageEnable"] = static_cast<bool>(data->decoded_value->alphaToCoverageEnable);
        jdata["alphaToOneEnable"] = static_cast<bool>(data->decoded_value->alphaToOneEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkStencilOpState* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["failOp"], data->decoded_value->failOp, options);
        FieldToJson(jdata["passOp"], data->decoded_value->passOp, options);
        FieldToJson(jdata["depthFailOp"], data->decoded_value->depthFailOp, options);
        FieldToJson(jdata["compareOp"], data->decoded_value->compareOp, options);
        FieldToJson(jdata["compareMask"], data->decoded_value->compareMask, options);
        FieldToJson(jdata["writeMask"], data->decoded_value->writeMask, options);
        FieldToJson(jdata["reference"], data->decoded_value->reference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineDepthStencilStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineDepthStencilStateCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        jdata["depthTestEnable"] = static_cast<bool>(data->decoded_value->depthTestEnable);
        jdata["depthWriteEnable"] = static_cast<bool>(data->decoded_value->depthWriteEnable);
        FieldToJson(jdata["depthCompareOp"], data->decoded_value->depthCompareOp, options);
        jdata["depthBoundsTestEnable"] = static_cast<bool>(data->decoded_value->depthBoundsTestEnable);
        jdata["stencilTestEnable"] = static_cast<bool>(data->decoded_value->stencilTestEnable);
        FieldToJson(jdata["front"], data->front, options);
        FieldToJson(jdata["back"], data->back, options);
        FieldToJson(jdata["minDepthBounds"], data->decoded_value->minDepthBounds, options);
        FieldToJson(jdata["maxDepthBounds"], data->decoded_value->maxDepthBounds, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineColorBlendAttachmentState* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        jdata["blendEnable"] = static_cast<bool>(data->decoded_value->blendEnable);
        FieldToJson(jdata["srcColorBlendFactor"], data->decoded_value->srcColorBlendFactor, options);
        FieldToJson(jdata["dstColorBlendFactor"], data->decoded_value->dstColorBlendFactor, options);
        FieldToJson(jdata["colorBlendOp"], data->decoded_value->colorBlendOp, options);
        FieldToJson(jdata["srcAlphaBlendFactor"], data->decoded_value->srcAlphaBlendFactor, options);
        FieldToJson(jdata["dstAlphaBlendFactor"], data->decoded_value->dstAlphaBlendFactor, options);
        FieldToJson(jdata["alphaBlendOp"], data->decoded_value->alphaBlendOp, options);
        FieldToJson(VkColorComponentFlags_t(),jdata["colorWriteMask"], data->decoded_value->colorWriteMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineColorBlendStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineColorBlendStateCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        jdata["logicOpEnable"] = static_cast<bool>(data->decoded_value->logicOpEnable);
        FieldToJson(jdata["logicOp"], data->decoded_value->logicOp, options);
        FieldToJson(jdata["attachmentCount"], data->decoded_value->attachmentCount, options);
        FieldToJson(jdata["pAttachments"], data->pAttachments, options);
        FieldToJson(jdata["blendConstants"], &data->blendConstants, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineDynamicStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineDynamicStateCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["dynamicStateCount"], data->decoded_value->dynamicStateCount, options);
        FieldToJson(jdata["pDynamicStates"], data->pDynamicStates, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGraphicsPipelineCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["stageCount"], data->decoded_value->stageCount, options);
        FieldToJson(jdata["pStages"], data->pStages, options);
        FieldToJson(jdata["pVertexInputState"], data->pVertexInputState, options);
        FieldToJson(jdata["pInputAssemblyState"], data->pInputAssemblyState, options);
        FieldToJson(jdata["pTessellationState"], data->pTessellationState, options);
        FieldToJson(jdata["pViewportState"], data->pViewportState, options);
        FieldToJson(jdata["pRasterizationState"], data->pRasterizationState, options);
        FieldToJson(jdata["pMultisampleState"], data->pMultisampleState, options);
        FieldToJson(jdata["pDepthStencilState"], data->pDepthStencilState, options);
        FieldToJson(jdata["pColorBlendState"], data->pColorBlendState, options);
        FieldToJson(jdata["pDynamicState"], data->pDynamicState, options);
        HandleToJson(jdata["layout"], data->layout, options);
        HandleToJson(jdata["renderPass"], data->renderPass, options);
        FieldToJson(jdata["subpass"], data->decoded_value->subpass, options);
        HandleToJson(jdata["basePipelineHandle"], data->basePipelineHandle, options);
        FieldToJson(jdata["basePipelineIndex"], data->decoded_value->basePipelineIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentDescription* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkAttachmentDescriptionFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["samples"], data->decoded_value->samples, options);
        FieldToJson(jdata["loadOp"], data->decoded_value->loadOp, options);
        FieldToJson(jdata["storeOp"], data->decoded_value->storeOp, options);
        FieldToJson(jdata["stencilLoadOp"], data->decoded_value->stencilLoadOp, options);
        FieldToJson(jdata["stencilStoreOp"], data->decoded_value->stencilStoreOp, options);
        FieldToJson(jdata["initialLayout"], data->decoded_value->initialLayout, options);
        FieldToJson(jdata["finalLayout"], data->decoded_value->finalLayout, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentReference* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["attachment"], data->decoded_value->attachment, options);
        FieldToJson(jdata["layout"], data->decoded_value->layout, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFramebufferCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkFramebufferCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["renderPass"], data->renderPass, options);
        FieldToJson(jdata["attachmentCount"], data->decoded_value->attachmentCount, options);
        HandleToJson(jdata["pAttachments"], &data->pAttachments, options);
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["layers"], data->decoded_value->layers, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassDescription* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkSubpassDescriptionFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pipelineBindPoint"], data->decoded_value->pipelineBindPoint, options);
        FieldToJson(jdata["inputAttachmentCount"], data->decoded_value->inputAttachmentCount, options);
        FieldToJson(jdata["pInputAttachments"], data->pInputAttachments, options);
        FieldToJson(jdata["colorAttachmentCount"], data->decoded_value->colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachments"], data->pColorAttachments, options);
        FieldToJson(jdata["pResolveAttachments"], data->pResolveAttachments, options);
        FieldToJson(jdata["pDepthStencilAttachment"], data->pDepthStencilAttachment, options);
        FieldToJson(jdata["preserveAttachmentCount"], data->decoded_value->preserveAttachmentCount, options);
        FieldToJson(jdata["pPreserveAttachments"], data->pPreserveAttachments, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassDependency* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["srcSubpass"], data->decoded_value->srcSubpass, options);
        FieldToJson(jdata["dstSubpass"], data->decoded_value->dstSubpass, options);
        FieldToJson(VkPipelineStageFlags_t(),jdata["srcStageMask"], data->decoded_value->srcStageMask, options);
        FieldToJson(VkPipelineStageFlags_t(),jdata["dstStageMask"], data->decoded_value->dstStageMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["srcAccessMask"], data->decoded_value->srcAccessMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["dstAccessMask"], data->decoded_value->dstAccessMask, options);
        FieldToJson(VkDependencyFlags_t(),jdata["dependencyFlags"], data->decoded_value->dependencyFlags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkRenderPassCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["attachmentCount"], data->decoded_value->attachmentCount, options);
        FieldToJson(jdata["pAttachments"], data->pAttachments, options);
        FieldToJson(jdata["subpassCount"], data->decoded_value->subpassCount, options);
        FieldToJson(jdata["pSubpasses"], data->pSubpasses, options);
        FieldToJson(jdata["dependencyCount"], data->decoded_value->dependencyCount, options);
        FieldToJson(jdata["pDependencies"], data->pDependencies, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkClearDepthStencilValue* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["depth"], data->decoded_value->depth, options);
        FieldToJson(jdata["stencil"], data->decoded_value->stencil, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkClearAttachment* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], data->decoded_value->aspectMask, options);
        FieldToJson(jdata["colorAttachment"], data->decoded_value->colorAttachment, options);
        FieldToJson(jdata["clearValue"], data->clearValue, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkClearRect* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["rect"], data->rect, options);
        FieldToJson(jdata["baseArrayLayer"], data->decoded_value->baseArrayLayer, options);
        FieldToJson(jdata["layerCount"], data->decoded_value->layerCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageBlit* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["srcSubresource"], data->srcSubresource, options);
        FieldToJson(jdata["srcOffsets"], data->srcOffsets, options);
        FieldToJson(jdata["dstSubresource"], data->dstSubresource, options);
        FieldToJson(jdata["dstOffsets"], data->dstOffsets, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageResolve* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["srcSubresource"], data->srcSubresource, options);
        FieldToJson(jdata["srcOffset"], data->srcOffset, options);
        FieldToJson(jdata["dstSubresource"], data->dstSubresource, options);
        FieldToJson(jdata["dstOffset"], data->dstOffset, options);
        FieldToJson(jdata["extent"], data->extent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["renderPass"], data->renderPass, options);
        HandleToJson(jdata["framebuffer"], data->framebuffer, options);
        FieldToJson(jdata["renderArea"], data->renderArea, options);
        FieldToJson(jdata["clearValueCount"], data->decoded_value->clearValueCount, options);
        FieldToJson(jdata["pClearValues"], data->pClearValues, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindBufferMemoryInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["memoryOffset"], data->decoded_value->memoryOffset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindImageMemoryInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["image"], data->image, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["memoryOffset"], data->decoded_value->memoryOffset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryDedicatedRequirements* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["prefersDedicatedAllocation"] = static_cast<bool>(data->decoded_value->prefersDedicatedAllocation);
        jdata["requiresDedicatedAllocation"] = static_cast<bool>(data->decoded_value->requiresDedicatedAllocation);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryDedicatedAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["image"], data->image, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryAllocateFlagsInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkMemoryAllocateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["deviceMask"], data->decoded_value->deviceMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupCommandBufferBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["deviceMask"], data->decoded_value->deviceMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["waitSemaphoreCount"], data->decoded_value->waitSemaphoreCount, options);
        FieldToJson(jdata["pWaitSemaphoreDeviceIndices"], data->pWaitSemaphoreDeviceIndices, options);
        FieldToJson(jdata["commandBufferCount"], data->decoded_value->commandBufferCount, options);
        FieldToJson(jdata["pCommandBufferDeviceMasks"], data->pCommandBufferDeviceMasks, options);
        FieldToJson(jdata["signalSemaphoreCount"], data->decoded_value->signalSemaphoreCount, options);
        FieldToJson(jdata["pSignalSemaphoreDeviceIndices"], data->pSignalSemaphoreDeviceIndices, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupBindSparseInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["resourceDeviceIndex"], data->decoded_value->resourceDeviceIndex, options);
        FieldToJson(jdata["memoryDeviceIndex"], data->decoded_value->memoryDeviceIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindBufferMemoryDeviceGroupInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["deviceIndexCount"], data->decoded_value->deviceIndexCount, options);
        FieldToJson(jdata["pDeviceIndices"], data->pDeviceIndices, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindImageMemoryDeviceGroupInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["deviceIndexCount"], data->decoded_value->deviceIndexCount, options);
        FieldToJson(jdata["pDeviceIndices"], data->pDeviceIndices, options);
        FieldToJson(jdata["splitInstanceBindRegionCount"], data->decoded_value->splitInstanceBindRegionCount, options);
        FieldToJson(jdata["pSplitInstanceBindRegions"], data->pSplitInstanceBindRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceGroupProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["physicalDeviceCount"], data->decoded_value->physicalDeviceCount, options);
        HandleToJson(jdata["physicalDevices"], &data->physicalDevices, options);
        jdata["subsetAllocation"] = static_cast<bool>(data->decoded_value->subsetAllocation);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupDeviceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["physicalDeviceCount"], data->decoded_value->physicalDeviceCount, options);
        HandleToJson(jdata["pPhysicalDevices"], &data->pPhysicalDevices, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferMemoryRequirementsInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageMemoryRequirementsInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["image"], data->image, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSparseMemoryRequirementsInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["image"], data->image, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryRequirements2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["memoryRequirements"], data->memoryRequirements, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageMemoryRequirements2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["memoryRequirements"], data->memoryRequirements, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFeatures2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["features"], data->features, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["properties"], data->properties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFormatProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["formatProperties"], data->formatProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageFormatProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["imageFormatProperties"], data->imageFormatProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageFormatInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["tiling"], data->decoded_value->tiling, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["usage"], data->decoded_value->usage, options);
        FieldToJson(VkImageCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["queueFamilyProperties"], data->queueFamilyProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMemoryProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["memoryProperties"], data->memoryProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSparseImageFormatProperties2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["properties"], data->properties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSparseImageFormatInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["samples"], data->decoded_value->samples, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["usage"], data->decoded_value->usage, options);
        FieldToJson(jdata["tiling"], data->decoded_value->tiling, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewUsageCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["usage"], data->decoded_value->usage, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProtectedMemoryFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["protectedMemory"] = static_cast<bool>(data->decoded_value->protectedMemory);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProtectedMemoryProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["protectedNoFault"] = static_cast<bool>(data->decoded_value->protectedNoFault);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceQueueInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDeviceQueueCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["queueFamilyIndex"], data->decoded_value->queueFamilyIndex, options);
        FieldToJson(jdata["queueIndex"], data->decoded_value->queueIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkProtectedSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["protectedSubmit"] = static_cast<bool>(data->decoded_value->protectedSubmit);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindImagePlaneMemoryInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["planeAspect"], data->decoded_value->planeAspect, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImagePlaneMemoryRequirementsInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["planeAspect"], data->decoded_value->planeAspect, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalMemoryProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkExternalMemoryFeatureFlags_t(),jdata["externalMemoryFeatures"], data->decoded_value->externalMemoryFeatures, options);
        FieldToJson(VkExternalMemoryHandleTypeFlags_t(),jdata["exportFromImportedHandleTypes"], data->decoded_value->exportFromImportedHandleTypes, options);
        FieldToJson(VkExternalMemoryHandleTypeFlags_t(),jdata["compatibleHandleTypes"], data->decoded_value->compatibleHandleTypes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalImageFormatInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalImageFormatProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["externalMemoryProperties"], data->externalMemoryProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalBufferInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkBufferCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(VkBufferUsageFlags_t(),jdata["usage"], data->decoded_value->usage, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalBufferProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["externalMemoryProperties"], data->externalMemoryProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceIDProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["deviceUUID"], uuid_to_string(sizeof(data->decoded_value->deviceUUID), data->decoded_value->deviceUUID), options);
        FieldToJson(jdata["driverUUID"], uuid_to_string(sizeof(data->decoded_value->driverUUID), data->decoded_value->driverUUID), options);
        FieldToJson(jdata["deviceLUID"], uuid_to_string(sizeof(data->decoded_value->deviceLUID), data->decoded_value->deviceLUID), options);
        FieldToJson(jdata["deviceNodeMask"], data->decoded_value->deviceNodeMask, options);
        jdata["deviceLUIDValid"] = static_cast<bool>(data->decoded_value->deviceLUIDValid);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalMemoryImageCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlags_t(),jdata["handleTypes"], data->decoded_value->handleTypes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalMemoryBufferCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlags_t(),jdata["handleTypes"], data->decoded_value->handleTypes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportMemoryAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlags_t(),jdata["handleTypes"], data->decoded_value->handleTypes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalFenceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalFenceProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkExternalFenceHandleTypeFlags_t(),jdata["exportFromImportedHandleTypes"], data->decoded_value->exportFromImportedHandleTypes, options);
        FieldToJson(VkExternalFenceHandleTypeFlags_t(),jdata["compatibleHandleTypes"], data->decoded_value->compatibleHandleTypes, options);
        FieldToJson(VkExternalFenceFeatureFlags_t(),jdata["externalFenceFeatures"], data->decoded_value->externalFenceFeatures, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportFenceCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkExternalFenceHandleTypeFlags_t(),jdata["handleTypes"], data->decoded_value->handleTypes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportSemaphoreCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkExternalSemaphoreHandleTypeFlags_t(),jdata["handleTypes"], data->decoded_value->handleTypes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalSemaphoreInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalSemaphoreProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkExternalSemaphoreHandleTypeFlags_t(),jdata["exportFromImportedHandleTypes"], data->decoded_value->exportFromImportedHandleTypes, options);
        FieldToJson(VkExternalSemaphoreHandleTypeFlags_t(),jdata["compatibleHandleTypes"], data->decoded_value->compatibleHandleTypes, options);
        FieldToJson(VkExternalSemaphoreFeatureFlags_t(),jdata["externalSemaphoreFeatures"], data->decoded_value->externalSemaphoreFeatures, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSubgroupProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["subgroupSize"], data->decoded_value->subgroupSize, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["supportedStages"], data->decoded_value->supportedStages, options);
        FieldToJson(VkSubgroupFeatureFlags_t(),jdata["supportedOperations"], data->decoded_value->supportedOperations, options);
        jdata["quadOperationsInAllStages"] = static_cast<bool>(data->decoded_value->quadOperationsInAllStages);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevice16BitStorageFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["storageBuffer16BitAccess"] = static_cast<bool>(data->decoded_value->storageBuffer16BitAccess);
        jdata["uniformAndStorageBuffer16BitAccess"] = static_cast<bool>(data->decoded_value->uniformAndStorageBuffer16BitAccess);
        jdata["storagePushConstant16"] = static_cast<bool>(data->decoded_value->storagePushConstant16);
        jdata["storageInputOutput16"] = static_cast<bool>(data->decoded_value->storageInputOutput16);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVariablePointersFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["variablePointersStorageBuffer"] = static_cast<bool>(data->decoded_value->variablePointersStorageBuffer);
        jdata["variablePointers"] = static_cast<bool>(data->decoded_value->variablePointers);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorUpdateTemplateEntry* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["dstBinding"], data->decoded_value->dstBinding, options);
        FieldToJson(jdata["dstArrayElement"], data->decoded_value->dstArrayElement, options);
        FieldToJson(jdata["descriptorCount"], data->decoded_value->descriptorCount, options);
        FieldToJson(jdata["descriptorType"], data->decoded_value->descriptorType, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["stride"], data->decoded_value->stride, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorUpdateTemplateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDescriptorUpdateTemplateCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["descriptorUpdateEntryCount"], data->decoded_value->descriptorUpdateEntryCount, options);
        FieldToJson(jdata["pDescriptorUpdateEntries"], data->pDescriptorUpdateEntries, options);
        FieldToJson(jdata["templateType"], data->decoded_value->templateType, options);
        HandleToJson(jdata["descriptorSetLayout"], data->descriptorSetLayout, options);
        FieldToJson(jdata["pipelineBindPoint"], data->decoded_value->pipelineBindPoint, options);
        HandleToJson(jdata["pipelineLayout"], data->pipelineLayout, options);
        FieldToJson(jdata["set"], data->decoded_value->set, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance3Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxPerSetDescriptors"], data->decoded_value->maxPerSetDescriptors, options);
        FieldToJson(jdata["maxMemoryAllocationSize"], data->decoded_value->maxMemoryAllocationSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetLayoutSupport* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["supported"] = static_cast<bool>(data->decoded_value->supported);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerYcbcrConversionCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["ycbcrModel"], data->decoded_value->ycbcrModel, options);
        FieldToJson(jdata["ycbcrRange"], data->decoded_value->ycbcrRange, options);
        FieldToJson(jdata["components"], data->components, options);
        FieldToJson(jdata["xChromaOffset"], data->decoded_value->xChromaOffset, options);
        FieldToJson(jdata["yChromaOffset"], data->decoded_value->yChromaOffset, options);
        FieldToJson(jdata["chromaFilter"], data->decoded_value->chromaFilter, options);
        jdata["forceExplicitReconstruction"] = static_cast<bool>(data->decoded_value->forceExplicitReconstruction);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerYcbcrConversionInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["conversion"], data->conversion, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["samplerYcbcrConversion"] = static_cast<bool>(data->decoded_value->samplerYcbcrConversion);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerYcbcrConversionImageFormatProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["combinedImageSamplerDescriptorCount"], data->decoded_value->combinedImageSamplerDescriptorCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupRenderPassBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["deviceMask"], data->decoded_value->deviceMask, options);
        FieldToJson(jdata["deviceRenderAreaCount"], data->decoded_value->deviceRenderAreaCount, options);
        FieldToJson(jdata["pDeviceRenderAreas"], data->pDeviceRenderAreas, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePointClippingProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pointClippingBehavior"], data->decoded_value->pointClippingBehavior, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkInputAttachmentAspectReference* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["subpass"], data->decoded_value->subpass, options);
        FieldToJson(jdata["inputAttachmentIndex"], data->decoded_value->inputAttachmentIndex, options);
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], data->decoded_value->aspectMask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassInputAttachmentAspectCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["aspectReferenceCount"], data->decoded_value->aspectReferenceCount, options);
        FieldToJson(jdata["pAspectReferences"], data->pAspectReferences, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineTessellationDomainOriginStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["domainOrigin"], data->decoded_value->domainOrigin, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassMultiviewCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["subpassCount"], data->decoded_value->subpassCount, options);
        FieldToJson(jdata["pViewMasks"], data->pViewMasks, options);
        FieldToJson(jdata["dependencyCount"], data->decoded_value->dependencyCount, options);
        FieldToJson(jdata["pViewOffsets"], data->pViewOffsets, options);
        FieldToJson(jdata["correlationMaskCount"], data->decoded_value->correlationMaskCount, options);
        FieldToJson(jdata["pCorrelationMasks"], data->pCorrelationMasks, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiviewFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["multiview"] = static_cast<bool>(data->decoded_value->multiview);
        jdata["multiviewGeometryShader"] = static_cast<bool>(data->decoded_value->multiviewGeometryShader);
        jdata["multiviewTessellationShader"] = static_cast<bool>(data->decoded_value->multiviewTessellationShader);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiviewProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxMultiviewViewCount"], data->decoded_value->maxMultiviewViewCount, options);
        FieldToJson(jdata["maxMultiviewInstanceIndex"], data->decoded_value->maxMultiviewInstanceIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderDrawParametersFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderDrawParameters"] = static_cast<bool>(data->decoded_value->shaderDrawParameters);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan11Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["storageBuffer16BitAccess"] = static_cast<bool>(data->decoded_value->storageBuffer16BitAccess);
        jdata["uniformAndStorageBuffer16BitAccess"] = static_cast<bool>(data->decoded_value->uniformAndStorageBuffer16BitAccess);
        jdata["storagePushConstant16"] = static_cast<bool>(data->decoded_value->storagePushConstant16);
        jdata["storageInputOutput16"] = static_cast<bool>(data->decoded_value->storageInputOutput16);
        jdata["multiview"] = static_cast<bool>(data->decoded_value->multiview);
        jdata["multiviewGeometryShader"] = static_cast<bool>(data->decoded_value->multiviewGeometryShader);
        jdata["multiviewTessellationShader"] = static_cast<bool>(data->decoded_value->multiviewTessellationShader);
        jdata["variablePointersStorageBuffer"] = static_cast<bool>(data->decoded_value->variablePointersStorageBuffer);
        jdata["variablePointers"] = static_cast<bool>(data->decoded_value->variablePointers);
        jdata["protectedMemory"] = static_cast<bool>(data->decoded_value->protectedMemory);
        jdata["samplerYcbcrConversion"] = static_cast<bool>(data->decoded_value->samplerYcbcrConversion);
        jdata["shaderDrawParameters"] = static_cast<bool>(data->decoded_value->shaderDrawParameters);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan11Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["deviceUUID"], uuid_to_string(sizeof(data->decoded_value->deviceUUID), data->decoded_value->deviceUUID), options);
        FieldToJson(jdata["driverUUID"], uuid_to_string(sizeof(data->decoded_value->driverUUID), data->decoded_value->driverUUID), options);
        FieldToJson(jdata["deviceLUID"], uuid_to_string(sizeof(data->decoded_value->deviceLUID), data->decoded_value->deviceLUID), options);
        FieldToJson(jdata["deviceNodeMask"], data->decoded_value->deviceNodeMask, options);
        jdata["deviceLUIDValid"] = static_cast<bool>(data->decoded_value->deviceLUIDValid);
        FieldToJson(jdata["subgroupSize"], data->decoded_value->subgroupSize, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["subgroupSupportedStages"], data->decoded_value->subgroupSupportedStages, options);
        FieldToJson(VkSubgroupFeatureFlags_t(),jdata["subgroupSupportedOperations"], data->decoded_value->subgroupSupportedOperations, options);
        jdata["subgroupQuadOperationsInAllStages"] = static_cast<bool>(data->decoded_value->subgroupQuadOperationsInAllStages);
        FieldToJson(jdata["pointClippingBehavior"], data->decoded_value->pointClippingBehavior, options);
        FieldToJson(jdata["maxMultiviewViewCount"], data->decoded_value->maxMultiviewViewCount, options);
        FieldToJson(jdata["maxMultiviewInstanceIndex"], data->decoded_value->maxMultiviewInstanceIndex, options);
        jdata["protectedNoFault"] = static_cast<bool>(data->decoded_value->protectedNoFault);
        FieldToJson(jdata["maxPerSetDescriptors"], data->decoded_value->maxPerSetDescriptors, options);
        FieldToJson(jdata["maxMemoryAllocationSize"], data->decoded_value->maxMemoryAllocationSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan12Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["samplerMirrorClampToEdge"] = static_cast<bool>(data->decoded_value->samplerMirrorClampToEdge);
        jdata["drawIndirectCount"] = static_cast<bool>(data->decoded_value->drawIndirectCount);
        jdata["storageBuffer8BitAccess"] = static_cast<bool>(data->decoded_value->storageBuffer8BitAccess);
        jdata["uniformAndStorageBuffer8BitAccess"] = static_cast<bool>(data->decoded_value->uniformAndStorageBuffer8BitAccess);
        jdata["storagePushConstant8"] = static_cast<bool>(data->decoded_value->storagePushConstant8);
        jdata["shaderBufferInt64Atomics"] = static_cast<bool>(data->decoded_value->shaderBufferInt64Atomics);
        jdata["shaderSharedInt64Atomics"] = static_cast<bool>(data->decoded_value->shaderSharedInt64Atomics);
        jdata["shaderFloat16"] = static_cast<bool>(data->decoded_value->shaderFloat16);
        jdata["shaderInt8"] = static_cast<bool>(data->decoded_value->shaderInt8);
        jdata["descriptorIndexing"] = static_cast<bool>(data->decoded_value->descriptorIndexing);
        jdata["shaderInputAttachmentArrayDynamicIndexing"] = static_cast<bool>(data->decoded_value->shaderInputAttachmentArrayDynamicIndexing);
        jdata["shaderUniformTexelBufferArrayDynamicIndexing"] = static_cast<bool>(data->decoded_value->shaderUniformTexelBufferArrayDynamicIndexing);
        jdata["shaderStorageTexelBufferArrayDynamicIndexing"] = static_cast<bool>(data->decoded_value->shaderStorageTexelBufferArrayDynamicIndexing);
        jdata["shaderUniformBufferArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderUniformBufferArrayNonUniformIndexing);
        jdata["shaderSampledImageArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderSampledImageArrayNonUniformIndexing);
        jdata["shaderStorageBufferArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderStorageBufferArrayNonUniformIndexing);
        jdata["shaderStorageImageArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderStorageImageArrayNonUniformIndexing);
        jdata["shaderInputAttachmentArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderInputAttachmentArrayNonUniformIndexing);
        jdata["shaderUniformTexelBufferArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderUniformTexelBufferArrayNonUniformIndexing);
        jdata["shaderStorageTexelBufferArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderStorageTexelBufferArrayNonUniformIndexing);
        jdata["descriptorBindingUniformBufferUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingUniformBufferUpdateAfterBind);
        jdata["descriptorBindingSampledImageUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingSampledImageUpdateAfterBind);
        jdata["descriptorBindingStorageImageUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingStorageImageUpdateAfterBind);
        jdata["descriptorBindingStorageBufferUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingStorageBufferUpdateAfterBind);
        jdata["descriptorBindingUniformTexelBufferUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingUniformTexelBufferUpdateAfterBind);
        jdata["descriptorBindingStorageTexelBufferUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingStorageTexelBufferUpdateAfterBind);
        jdata["descriptorBindingUpdateUnusedWhilePending"] = static_cast<bool>(data->decoded_value->descriptorBindingUpdateUnusedWhilePending);
        jdata["descriptorBindingPartiallyBound"] = static_cast<bool>(data->decoded_value->descriptorBindingPartiallyBound);
        jdata["descriptorBindingVariableDescriptorCount"] = static_cast<bool>(data->decoded_value->descriptorBindingVariableDescriptorCount);
        jdata["runtimeDescriptorArray"] = static_cast<bool>(data->decoded_value->runtimeDescriptorArray);
        jdata["samplerFilterMinmax"] = static_cast<bool>(data->decoded_value->samplerFilterMinmax);
        jdata["scalarBlockLayout"] = static_cast<bool>(data->decoded_value->scalarBlockLayout);
        jdata["imagelessFramebuffer"] = static_cast<bool>(data->decoded_value->imagelessFramebuffer);
        jdata["uniformBufferStandardLayout"] = static_cast<bool>(data->decoded_value->uniformBufferStandardLayout);
        jdata["shaderSubgroupExtendedTypes"] = static_cast<bool>(data->decoded_value->shaderSubgroupExtendedTypes);
        jdata["separateDepthStencilLayouts"] = static_cast<bool>(data->decoded_value->separateDepthStencilLayouts);
        jdata["hostQueryReset"] = static_cast<bool>(data->decoded_value->hostQueryReset);
        jdata["timelineSemaphore"] = static_cast<bool>(data->decoded_value->timelineSemaphore);
        jdata["bufferDeviceAddress"] = static_cast<bool>(data->decoded_value->bufferDeviceAddress);
        jdata["bufferDeviceAddressCaptureReplay"] = static_cast<bool>(data->decoded_value->bufferDeviceAddressCaptureReplay);
        jdata["bufferDeviceAddressMultiDevice"] = static_cast<bool>(data->decoded_value->bufferDeviceAddressMultiDevice);
        jdata["vulkanMemoryModel"] = static_cast<bool>(data->decoded_value->vulkanMemoryModel);
        jdata["vulkanMemoryModelDeviceScope"] = static_cast<bool>(data->decoded_value->vulkanMemoryModelDeviceScope);
        jdata["vulkanMemoryModelAvailabilityVisibilityChains"] = static_cast<bool>(data->decoded_value->vulkanMemoryModelAvailabilityVisibilityChains);
        jdata["shaderOutputViewportIndex"] = static_cast<bool>(data->decoded_value->shaderOutputViewportIndex);
        jdata["shaderOutputLayer"] = static_cast<bool>(data->decoded_value->shaderOutputLayer);
        jdata["subgroupBroadcastDynamicId"] = static_cast<bool>(data->decoded_value->subgroupBroadcastDynamicId);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkConformanceVersion* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["major"], data->decoded_value->major, options);
        FieldToJson(jdata["minor"], data->decoded_value->minor, options);
        FieldToJson(jdata["subminor"], data->decoded_value->subminor, options);
        FieldToJson(jdata["patch"], data->decoded_value->patch, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan12Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["driverID"], data->decoded_value->driverID, options);
        FieldToJson(jdata["driverName"], &data->driverName, options);
        FieldToJson(jdata["driverInfo"], &data->driverInfo, options);
        FieldToJson(jdata["conformanceVersion"], data->conformanceVersion, options);
        FieldToJson(jdata["denormBehaviorIndependence"], data->decoded_value->denormBehaviorIndependence, options);
        FieldToJson(jdata["roundingModeIndependence"], data->decoded_value->roundingModeIndependence, options);
        jdata["shaderSignedZeroInfNanPreserveFloat16"] = static_cast<bool>(data->decoded_value->shaderSignedZeroInfNanPreserveFloat16);
        jdata["shaderSignedZeroInfNanPreserveFloat32"] = static_cast<bool>(data->decoded_value->shaderSignedZeroInfNanPreserveFloat32);
        jdata["shaderSignedZeroInfNanPreserveFloat64"] = static_cast<bool>(data->decoded_value->shaderSignedZeroInfNanPreserveFloat64);
        jdata["shaderDenormPreserveFloat16"] = static_cast<bool>(data->decoded_value->shaderDenormPreserveFloat16);
        jdata["shaderDenormPreserveFloat32"] = static_cast<bool>(data->decoded_value->shaderDenormPreserveFloat32);
        jdata["shaderDenormPreserveFloat64"] = static_cast<bool>(data->decoded_value->shaderDenormPreserveFloat64);
        jdata["shaderDenormFlushToZeroFloat16"] = static_cast<bool>(data->decoded_value->shaderDenormFlushToZeroFloat16);
        jdata["shaderDenormFlushToZeroFloat32"] = static_cast<bool>(data->decoded_value->shaderDenormFlushToZeroFloat32);
        jdata["shaderDenormFlushToZeroFloat64"] = static_cast<bool>(data->decoded_value->shaderDenormFlushToZeroFloat64);
        jdata["shaderRoundingModeRTEFloat16"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTEFloat16);
        jdata["shaderRoundingModeRTEFloat32"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTEFloat32);
        jdata["shaderRoundingModeRTEFloat64"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTEFloat64);
        jdata["shaderRoundingModeRTZFloat16"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTZFloat16);
        jdata["shaderRoundingModeRTZFloat32"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTZFloat32);
        jdata["shaderRoundingModeRTZFloat64"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTZFloat64);
        FieldToJson(jdata["maxUpdateAfterBindDescriptorsInAllPools"], data->decoded_value->maxUpdateAfterBindDescriptorsInAllPools, options);
        jdata["shaderUniformBufferArrayNonUniformIndexingNative"] = static_cast<bool>(data->decoded_value->shaderUniformBufferArrayNonUniformIndexingNative);
        jdata["shaderSampledImageArrayNonUniformIndexingNative"] = static_cast<bool>(data->decoded_value->shaderSampledImageArrayNonUniformIndexingNative);
        jdata["shaderStorageBufferArrayNonUniformIndexingNative"] = static_cast<bool>(data->decoded_value->shaderStorageBufferArrayNonUniformIndexingNative);
        jdata["shaderStorageImageArrayNonUniformIndexingNative"] = static_cast<bool>(data->decoded_value->shaderStorageImageArrayNonUniformIndexingNative);
        jdata["shaderInputAttachmentArrayNonUniformIndexingNative"] = static_cast<bool>(data->decoded_value->shaderInputAttachmentArrayNonUniformIndexingNative);
        jdata["robustBufferAccessUpdateAfterBind"] = static_cast<bool>(data->decoded_value->robustBufferAccessUpdateAfterBind);
        jdata["quadDivergentImplicitLod"] = static_cast<bool>(data->decoded_value->quadDivergentImplicitLod);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindSamplers"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindSamplers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindUniformBuffers"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindUniformBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindStorageBuffers"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindStorageBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindSampledImages"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindSampledImages, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindStorageImages"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindStorageImages, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindInputAttachments"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindInputAttachments, options);
        FieldToJson(jdata["maxPerStageUpdateAfterBindResources"], data->decoded_value->maxPerStageUpdateAfterBindResources, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindSamplers"], data->decoded_value->maxDescriptorSetUpdateAfterBindSamplers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindUniformBuffers"], data->decoded_value->maxDescriptorSetUpdateAfterBindUniformBuffers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindUniformBuffersDynamic"], data->decoded_value->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageBuffers"], data->decoded_value->maxDescriptorSetUpdateAfterBindStorageBuffers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageBuffersDynamic"], data->decoded_value->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindSampledImages"], data->decoded_value->maxDescriptorSetUpdateAfterBindSampledImages, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageImages"], data->decoded_value->maxDescriptorSetUpdateAfterBindStorageImages, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindInputAttachments"], data->decoded_value->maxDescriptorSetUpdateAfterBindInputAttachments, options);
        FieldToJson(VkResolveModeFlags_t(),jdata["supportedDepthResolveModes"], data->decoded_value->supportedDepthResolveModes, options);
        FieldToJson(VkResolveModeFlags_t(),jdata["supportedStencilResolveModes"], data->decoded_value->supportedStencilResolveModes, options);
        jdata["independentResolveNone"] = static_cast<bool>(data->decoded_value->independentResolveNone);
        jdata["independentResolve"] = static_cast<bool>(data->decoded_value->independentResolve);
        jdata["filterMinmaxSingleComponentFormats"] = static_cast<bool>(data->decoded_value->filterMinmaxSingleComponentFormats);
        jdata["filterMinmaxImageComponentMapping"] = static_cast<bool>(data->decoded_value->filterMinmaxImageComponentMapping);
        FieldToJson(jdata["maxTimelineSemaphoreValueDifference"], data->decoded_value->maxTimelineSemaphoreValueDifference, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["framebufferIntegerColorSampleCounts"], data->decoded_value->framebufferIntegerColorSampleCounts, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageFormatListCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["viewFormatCount"], data->decoded_value->viewFormatCount, options);
        FieldToJson(jdata["pViewFormats"], data->pViewFormats, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDriverProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["driverID"], data->decoded_value->driverID, options);
        FieldToJson(jdata["driverName"], &data->driverName, options);
        FieldToJson(jdata["driverInfo"], &data->driverInfo, options);
        FieldToJson(jdata["conformanceVersion"], data->conformanceVersion, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["vulkanMemoryModel"] = static_cast<bool>(data->decoded_value->vulkanMemoryModel);
        jdata["vulkanMemoryModelDeviceScope"] = static_cast<bool>(data->decoded_value->vulkanMemoryModelDeviceScope);
        jdata["vulkanMemoryModelAvailabilityVisibilityChains"] = static_cast<bool>(data->decoded_value->vulkanMemoryModelAvailabilityVisibilityChains);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceHostQueryResetFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["hostQueryReset"] = static_cast<bool>(data->decoded_value->hostQueryReset);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTimelineSemaphoreFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["timelineSemaphore"] = static_cast<bool>(data->decoded_value->timelineSemaphore);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTimelineSemaphoreProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxTimelineSemaphoreValueDifference"], data->decoded_value->maxTimelineSemaphoreValueDifference, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreTypeCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["semaphoreType"], data->decoded_value->semaphoreType, options);
        FieldToJson(jdata["initialValue"], data->decoded_value->initialValue, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTimelineSemaphoreSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["waitSemaphoreValueCount"], data->decoded_value->waitSemaphoreValueCount, options);
        FieldToJson(jdata["pWaitSemaphoreValues"], data->pWaitSemaphoreValues, options);
        FieldToJson(jdata["signalSemaphoreValueCount"], data->decoded_value->signalSemaphoreValueCount, options);
        FieldToJson(jdata["pSignalSemaphoreValues"], data->pSignalSemaphoreValues, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreWaitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkSemaphoreWaitFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["semaphoreCount"], data->decoded_value->semaphoreCount, options);
        HandleToJson(jdata["pSemaphores"], &data->pSemaphores, options);
        FieldToJson(jdata["pValues"], data->pValues, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreSignalInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["semaphore"], data->semaphore, options);
        FieldToJson(jdata["value"], data->decoded_value->value, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["bufferDeviceAddress"] = static_cast<bool>(data->decoded_value->bufferDeviceAddress);
        jdata["bufferDeviceAddressCaptureReplay"] = static_cast<bool>(data->decoded_value->bufferDeviceAddressCaptureReplay);
        jdata["bufferDeviceAddressMultiDevice"] = static_cast<bool>(data->decoded_value->bufferDeviceAddressMultiDevice);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferDeviceAddressInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferOpaqueCaptureAddressCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["opaqueCaptureAddress"], data->decoded_value->opaqueCaptureAddress, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["opaqueCaptureAddress"], data->decoded_value->opaqueCaptureAddress, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceMemoryOpaqueCaptureAddressInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevice8BitStorageFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["storageBuffer8BitAccess"] = static_cast<bool>(data->decoded_value->storageBuffer8BitAccess);
        jdata["uniformAndStorageBuffer8BitAccess"] = static_cast<bool>(data->decoded_value->uniformAndStorageBuffer8BitAccess);
        jdata["storagePushConstant8"] = static_cast<bool>(data->decoded_value->storagePushConstant8);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderAtomicInt64Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderBufferInt64Atomics"] = static_cast<bool>(data->decoded_value->shaderBufferInt64Atomics);
        jdata["shaderSharedInt64Atomics"] = static_cast<bool>(data->decoded_value->shaderSharedInt64Atomics);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderFloat16Int8Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderFloat16"] = static_cast<bool>(data->decoded_value->shaderFloat16);
        jdata["shaderInt8"] = static_cast<bool>(data->decoded_value->shaderInt8);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFloatControlsProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["denormBehaviorIndependence"], data->decoded_value->denormBehaviorIndependence, options);
        FieldToJson(jdata["roundingModeIndependence"], data->decoded_value->roundingModeIndependence, options);
        jdata["shaderSignedZeroInfNanPreserveFloat16"] = static_cast<bool>(data->decoded_value->shaderSignedZeroInfNanPreserveFloat16);
        jdata["shaderSignedZeroInfNanPreserveFloat32"] = static_cast<bool>(data->decoded_value->shaderSignedZeroInfNanPreserveFloat32);
        jdata["shaderSignedZeroInfNanPreserveFloat64"] = static_cast<bool>(data->decoded_value->shaderSignedZeroInfNanPreserveFloat64);
        jdata["shaderDenormPreserveFloat16"] = static_cast<bool>(data->decoded_value->shaderDenormPreserveFloat16);
        jdata["shaderDenormPreserveFloat32"] = static_cast<bool>(data->decoded_value->shaderDenormPreserveFloat32);
        jdata["shaderDenormPreserveFloat64"] = static_cast<bool>(data->decoded_value->shaderDenormPreserveFloat64);
        jdata["shaderDenormFlushToZeroFloat16"] = static_cast<bool>(data->decoded_value->shaderDenormFlushToZeroFloat16);
        jdata["shaderDenormFlushToZeroFloat32"] = static_cast<bool>(data->decoded_value->shaderDenormFlushToZeroFloat32);
        jdata["shaderDenormFlushToZeroFloat64"] = static_cast<bool>(data->decoded_value->shaderDenormFlushToZeroFloat64);
        jdata["shaderRoundingModeRTEFloat16"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTEFloat16);
        jdata["shaderRoundingModeRTEFloat32"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTEFloat32);
        jdata["shaderRoundingModeRTEFloat64"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTEFloat64);
        jdata["shaderRoundingModeRTZFloat16"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTZFloat16);
        jdata["shaderRoundingModeRTZFloat32"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTZFloat32);
        jdata["shaderRoundingModeRTZFloat64"] = static_cast<bool>(data->decoded_value->shaderRoundingModeRTZFloat64);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["bindingCount"], data->decoded_value->bindingCount, options);
        FieldToJson(jdata["pBindingFlags"], data->pBindingFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDescriptorIndexingFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderInputAttachmentArrayDynamicIndexing"] = static_cast<bool>(data->decoded_value->shaderInputAttachmentArrayDynamicIndexing);
        jdata["shaderUniformTexelBufferArrayDynamicIndexing"] = static_cast<bool>(data->decoded_value->shaderUniformTexelBufferArrayDynamicIndexing);
        jdata["shaderStorageTexelBufferArrayDynamicIndexing"] = static_cast<bool>(data->decoded_value->shaderStorageTexelBufferArrayDynamicIndexing);
        jdata["shaderUniformBufferArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderUniformBufferArrayNonUniformIndexing);
        jdata["shaderSampledImageArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderSampledImageArrayNonUniformIndexing);
        jdata["shaderStorageBufferArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderStorageBufferArrayNonUniformIndexing);
        jdata["shaderStorageImageArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderStorageImageArrayNonUniformIndexing);
        jdata["shaderInputAttachmentArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderInputAttachmentArrayNonUniformIndexing);
        jdata["shaderUniformTexelBufferArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderUniformTexelBufferArrayNonUniformIndexing);
        jdata["shaderStorageTexelBufferArrayNonUniformIndexing"] = static_cast<bool>(data->decoded_value->shaderStorageTexelBufferArrayNonUniformIndexing);
        jdata["descriptorBindingUniformBufferUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingUniformBufferUpdateAfterBind);
        jdata["descriptorBindingSampledImageUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingSampledImageUpdateAfterBind);
        jdata["descriptorBindingStorageImageUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingStorageImageUpdateAfterBind);
        jdata["descriptorBindingStorageBufferUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingStorageBufferUpdateAfterBind);
        jdata["descriptorBindingUniformTexelBufferUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingUniformTexelBufferUpdateAfterBind);
        jdata["descriptorBindingStorageTexelBufferUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingStorageTexelBufferUpdateAfterBind);
        jdata["descriptorBindingUpdateUnusedWhilePending"] = static_cast<bool>(data->decoded_value->descriptorBindingUpdateUnusedWhilePending);
        jdata["descriptorBindingPartiallyBound"] = static_cast<bool>(data->decoded_value->descriptorBindingPartiallyBound);
        jdata["descriptorBindingVariableDescriptorCount"] = static_cast<bool>(data->decoded_value->descriptorBindingVariableDescriptorCount);
        jdata["runtimeDescriptorArray"] = static_cast<bool>(data->decoded_value->runtimeDescriptorArray);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDescriptorIndexingProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxUpdateAfterBindDescriptorsInAllPools"], data->decoded_value->maxUpdateAfterBindDescriptorsInAllPools, options);
        jdata["shaderUniformBufferArrayNonUniformIndexingNative"] = static_cast<bool>(data->decoded_value->shaderUniformBufferArrayNonUniformIndexingNative);
        jdata["shaderSampledImageArrayNonUniformIndexingNative"] = static_cast<bool>(data->decoded_value->shaderSampledImageArrayNonUniformIndexingNative);
        jdata["shaderStorageBufferArrayNonUniformIndexingNative"] = static_cast<bool>(data->decoded_value->shaderStorageBufferArrayNonUniformIndexingNative);
        jdata["shaderStorageImageArrayNonUniformIndexingNative"] = static_cast<bool>(data->decoded_value->shaderStorageImageArrayNonUniformIndexingNative);
        jdata["shaderInputAttachmentArrayNonUniformIndexingNative"] = static_cast<bool>(data->decoded_value->shaderInputAttachmentArrayNonUniformIndexingNative);
        jdata["robustBufferAccessUpdateAfterBind"] = static_cast<bool>(data->decoded_value->robustBufferAccessUpdateAfterBind);
        jdata["quadDivergentImplicitLod"] = static_cast<bool>(data->decoded_value->quadDivergentImplicitLod);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindSamplers"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindSamplers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindUniformBuffers"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindUniformBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindStorageBuffers"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindStorageBuffers, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindSampledImages"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindSampledImages, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindStorageImages"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindStorageImages, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindInputAttachments"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindInputAttachments, options);
        FieldToJson(jdata["maxPerStageUpdateAfterBindResources"], data->decoded_value->maxPerStageUpdateAfterBindResources, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindSamplers"], data->decoded_value->maxDescriptorSetUpdateAfterBindSamplers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindUniformBuffers"], data->decoded_value->maxDescriptorSetUpdateAfterBindUniformBuffers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindUniformBuffersDynamic"], data->decoded_value->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageBuffers"], data->decoded_value->maxDescriptorSetUpdateAfterBindStorageBuffers, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageBuffersDynamic"], data->decoded_value->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindSampledImages"], data->decoded_value->maxDescriptorSetUpdateAfterBindSampledImages, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindStorageImages"], data->decoded_value->maxDescriptorSetUpdateAfterBindStorageImages, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindInputAttachments"], data->decoded_value->maxDescriptorSetUpdateAfterBindInputAttachments, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetVariableDescriptorCountAllocateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["descriptorSetCount"], data->decoded_value->descriptorSetCount, options);
        FieldToJson(jdata["pDescriptorCounts"], data->pDescriptorCounts, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetVariableDescriptorCountLayoutSupport* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxVariableDescriptorCount"], data->decoded_value->maxVariableDescriptorCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["scalarBlockLayout"] = static_cast<bool>(data->decoded_value->scalarBlockLayout);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerReductionModeCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["reductionMode"], data->decoded_value->reductionMode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["filterMinmaxSingleComponentFormats"] = static_cast<bool>(data->decoded_value->filterMinmaxSingleComponentFormats);
        jdata["filterMinmaxImageComponentMapping"] = static_cast<bool>(data->decoded_value->filterMinmaxImageComponentMapping);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["uniformBufferStandardLayout"] = static_cast<bool>(data->decoded_value->uniformBufferStandardLayout);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderSubgroupExtendedTypes"] = static_cast<bool>(data->decoded_value->shaderSubgroupExtendedTypes);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentDescription2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkAttachmentDescriptionFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["samples"], data->decoded_value->samples, options);
        FieldToJson(jdata["loadOp"], data->decoded_value->loadOp, options);
        FieldToJson(jdata["storeOp"], data->decoded_value->storeOp, options);
        FieldToJson(jdata["stencilLoadOp"], data->decoded_value->stencilLoadOp, options);
        FieldToJson(jdata["stencilStoreOp"], data->decoded_value->stencilStoreOp, options);
        FieldToJson(jdata["initialLayout"], data->decoded_value->initialLayout, options);
        FieldToJson(jdata["finalLayout"], data->decoded_value->finalLayout, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentReference2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["attachment"], data->decoded_value->attachment, options);
        FieldToJson(jdata["layout"], data->decoded_value->layout, options);
        FieldToJson(VkImageAspectFlags_t(),jdata["aspectMask"], data->decoded_value->aspectMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassDescription2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkSubpassDescriptionFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pipelineBindPoint"], data->decoded_value->pipelineBindPoint, options);
        FieldToJson(jdata["viewMask"], data->decoded_value->viewMask, options);
        FieldToJson(jdata["inputAttachmentCount"], data->decoded_value->inputAttachmentCount, options);
        FieldToJson(jdata["pInputAttachments"], data->pInputAttachments, options);
        FieldToJson(jdata["colorAttachmentCount"], data->decoded_value->colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachments"], data->pColorAttachments, options);
        FieldToJson(jdata["pResolveAttachments"], data->pResolveAttachments, options);
        FieldToJson(jdata["pDepthStencilAttachment"], data->pDepthStencilAttachment, options);
        FieldToJson(jdata["preserveAttachmentCount"], data->decoded_value->preserveAttachmentCount, options);
        FieldToJson(jdata["pPreserveAttachments"], data->pPreserveAttachments, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassDependency2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["srcSubpass"], data->decoded_value->srcSubpass, options);
        FieldToJson(jdata["dstSubpass"], data->decoded_value->dstSubpass, options);
        FieldToJson(VkPipelineStageFlags_t(),jdata["srcStageMask"], data->decoded_value->srcStageMask, options);
        FieldToJson(VkPipelineStageFlags_t(),jdata["dstStageMask"], data->decoded_value->dstStageMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["srcAccessMask"], data->decoded_value->srcAccessMask, options);
        FieldToJson(VkAccessFlags_t(),jdata["dstAccessMask"], data->decoded_value->dstAccessMask, options);
        FieldToJson(VkDependencyFlags_t(),jdata["dependencyFlags"], data->decoded_value->dependencyFlags, options);
        FieldToJson(jdata["viewOffset"], data->decoded_value->viewOffset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassCreateInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkRenderPassCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["attachmentCount"], data->decoded_value->attachmentCount, options);
        FieldToJson(jdata["pAttachments"], data->pAttachments, options);
        FieldToJson(jdata["subpassCount"], data->decoded_value->subpassCount, options);
        FieldToJson(jdata["pSubpasses"], data->pSubpasses, options);
        FieldToJson(jdata["dependencyCount"], data->decoded_value->dependencyCount, options);
        FieldToJson(jdata["pDependencies"], data->pDependencies, options);
        FieldToJson(jdata["correlatedViewMaskCount"], data->decoded_value->correlatedViewMaskCount, options);
        FieldToJson(jdata["pCorrelatedViewMasks"], data->pCorrelatedViewMasks, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["contents"], data->decoded_value->contents, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassEndInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassDescriptionDepthStencilResolve* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["depthResolveMode"], data->decoded_value->depthResolveMode, options);
        FieldToJson(jdata["stencilResolveMode"], data->decoded_value->stencilResolveMode, options);
        FieldToJson(jdata["pDepthStencilResolveAttachment"], data->pDepthStencilResolveAttachment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDepthStencilResolveProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkResolveModeFlags_t(),jdata["supportedDepthResolveModes"], data->decoded_value->supportedDepthResolveModes, options);
        FieldToJson(VkResolveModeFlags_t(),jdata["supportedStencilResolveModes"], data->decoded_value->supportedStencilResolveModes, options);
        jdata["independentResolveNone"] = static_cast<bool>(data->decoded_value->independentResolveNone);
        jdata["independentResolve"] = static_cast<bool>(data->decoded_value->independentResolve);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageStencilUsageCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["stencilUsage"], data->decoded_value->stencilUsage, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImagelessFramebufferFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["imagelessFramebuffer"] = static_cast<bool>(data->decoded_value->imagelessFramebuffer);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFramebufferAttachmentImageInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkImageCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["usage"], data->decoded_value->usage, options);
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["layerCount"], data->decoded_value->layerCount, options);
        FieldToJson(jdata["viewFormatCount"], data->decoded_value->viewFormatCount, options);
        FieldToJson(jdata["pViewFormats"], data->pViewFormats, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFramebufferAttachmentsCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["attachmentImageInfoCount"], data->decoded_value->attachmentImageInfoCount, options);
        FieldToJson(jdata["pAttachmentImageInfos"], data->pAttachmentImageInfos, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassAttachmentBeginInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["attachmentCount"], data->decoded_value->attachmentCount, options);
        HandleToJson(jdata["pAttachments"], &data->pAttachments, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["separateDepthStencilLayouts"] = static_cast<bool>(data->decoded_value->separateDepthStencilLayouts);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentReferenceStencilLayout* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stencilLayout"], data->decoded_value->stencilLayout, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentDescriptionStencilLayout* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stencilInitialLayout"], data->decoded_value->stencilInitialLayout, options);
        FieldToJson(jdata["stencilFinalLayout"], data->decoded_value->stencilFinalLayout, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan13Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["robustImageAccess"] = static_cast<bool>(data->decoded_value->robustImageAccess);
        jdata["inlineUniformBlock"] = static_cast<bool>(data->decoded_value->inlineUniformBlock);
        jdata["descriptorBindingInlineUniformBlockUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingInlineUniformBlockUpdateAfterBind);
        jdata["pipelineCreationCacheControl"] = static_cast<bool>(data->decoded_value->pipelineCreationCacheControl);
        jdata["privateData"] = static_cast<bool>(data->decoded_value->privateData);
        jdata["shaderDemoteToHelperInvocation"] = static_cast<bool>(data->decoded_value->shaderDemoteToHelperInvocation);
        jdata["shaderTerminateInvocation"] = static_cast<bool>(data->decoded_value->shaderTerminateInvocation);
        jdata["subgroupSizeControl"] = static_cast<bool>(data->decoded_value->subgroupSizeControl);
        jdata["computeFullSubgroups"] = static_cast<bool>(data->decoded_value->computeFullSubgroups);
        jdata["synchronization2"] = static_cast<bool>(data->decoded_value->synchronization2);
        jdata["textureCompressionASTC_HDR"] = static_cast<bool>(data->decoded_value->textureCompressionASTC_HDR);
        jdata["shaderZeroInitializeWorkgroupMemory"] = static_cast<bool>(data->decoded_value->shaderZeroInitializeWorkgroupMemory);
        jdata["dynamicRendering"] = static_cast<bool>(data->decoded_value->dynamicRendering);
        jdata["shaderIntegerDotProduct"] = static_cast<bool>(data->decoded_value->shaderIntegerDotProduct);
        jdata["maintenance4"] = static_cast<bool>(data->decoded_value->maintenance4);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan13Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minSubgroupSize"], data->decoded_value->minSubgroupSize, options);
        FieldToJson(jdata["maxSubgroupSize"], data->decoded_value->maxSubgroupSize, options);
        FieldToJson(jdata["maxComputeWorkgroupSubgroups"], data->decoded_value->maxComputeWorkgroupSubgroups, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["requiredSubgroupSizeStages"], data->decoded_value->requiredSubgroupSizeStages, options);
        FieldToJson(jdata["maxInlineUniformBlockSize"], data->decoded_value->maxInlineUniformBlockSize, options);
        FieldToJson(jdata["maxPerStageDescriptorInlineUniformBlocks"], data->decoded_value->maxPerStageDescriptorInlineUniformBlocks, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, options);
        FieldToJson(jdata["maxDescriptorSetInlineUniformBlocks"], data->decoded_value->maxDescriptorSetInlineUniformBlocks, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindInlineUniformBlocks"], data->decoded_value->maxDescriptorSetUpdateAfterBindInlineUniformBlocks, options);
        FieldToJson(jdata["maxInlineUniformTotalSize"], data->decoded_value->maxInlineUniformTotalSize, options);
        jdata["integerDotProduct8BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct8BitUnsignedAccelerated);
        jdata["integerDotProduct8BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct8BitSignedAccelerated);
        jdata["integerDotProduct8BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct8BitMixedSignednessAccelerated);
        jdata["integerDotProduct4x8BitPackedUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct4x8BitPackedUnsignedAccelerated);
        jdata["integerDotProduct4x8BitPackedSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct4x8BitPackedSignedAccelerated);
        jdata["integerDotProduct4x8BitPackedMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct4x8BitPackedMixedSignednessAccelerated);
        jdata["integerDotProduct16BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct16BitUnsignedAccelerated);
        jdata["integerDotProduct16BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct16BitSignedAccelerated);
        jdata["integerDotProduct16BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct16BitMixedSignednessAccelerated);
        jdata["integerDotProduct32BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct32BitUnsignedAccelerated);
        jdata["integerDotProduct32BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct32BitSignedAccelerated);
        jdata["integerDotProduct32BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct32BitMixedSignednessAccelerated);
        jdata["integerDotProduct64BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct64BitUnsignedAccelerated);
        jdata["integerDotProduct64BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct64BitSignedAccelerated);
        jdata["integerDotProduct64BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct64BitMixedSignednessAccelerated);
        jdata["integerDotProductAccumulatingSaturating8BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating8BitUnsignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating8BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating8BitSignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated);
        jdata["integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated);
        jdata["integerDotProductAccumulatingSaturating16BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating16BitUnsignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating16BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating16BitSignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated);
        jdata["integerDotProductAccumulatingSaturating32BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating32BitUnsignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating32BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating32BitSignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated);
        jdata["integerDotProductAccumulatingSaturating64BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating64BitUnsignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating64BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating64BitSignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated);
        FieldToJson(jdata["storageTexelBufferOffsetAlignmentBytes"], data->decoded_value->storageTexelBufferOffsetAlignmentBytes, options);
        jdata["storageTexelBufferOffsetSingleTexelAlignment"] = static_cast<bool>(data->decoded_value->storageTexelBufferOffsetSingleTexelAlignment);
        FieldToJson(jdata["uniformTexelBufferOffsetAlignmentBytes"], data->decoded_value->uniformTexelBufferOffsetAlignmentBytes, options);
        jdata["uniformTexelBufferOffsetSingleTexelAlignment"] = static_cast<bool>(data->decoded_value->uniformTexelBufferOffsetSingleTexelAlignment);
        FieldToJson(jdata["maxBufferSize"], data->decoded_value->maxBufferSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceToolProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["version"], &data->version, options);
        FieldToJson(VkToolPurposeFlags_t(),jdata["purposes"], data->decoded_value->purposes, options);
        FieldToJson(jdata["description"], &data->description, options);
        FieldToJson(jdata["layer"], &data->layer, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePrivateDataFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["privateData"] = static_cast<bool>(data->decoded_value->privateData);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDevicePrivateDataCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["privateDataSlotRequestCount"], data->decoded_value->privateDataSlotRequestCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPrivateDataSlotCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPrivateDataSlotCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryBarrier2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["srcStageMask"], data->decoded_value->srcStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["srcAccessMask"], data->decoded_value->srcAccessMask, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["dstStageMask"], data->decoded_value->dstStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["dstAccessMask"], data->decoded_value->dstAccessMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferMemoryBarrier2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["srcStageMask"], data->decoded_value->srcStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["srcAccessMask"], data->decoded_value->srcAccessMask, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["dstStageMask"], data->decoded_value->dstStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["dstAccessMask"], data->decoded_value->dstAccessMask, options);
        FieldToJson(jdata["srcQueueFamilyIndex"], data->decoded_value->srcQueueFamilyIndex, options);
        FieldToJson(jdata["dstQueueFamilyIndex"], data->decoded_value->dstQueueFamilyIndex, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageMemoryBarrier2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["srcStageMask"], data->decoded_value->srcStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["srcAccessMask"], data->decoded_value->srcAccessMask, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["dstStageMask"], data->decoded_value->dstStageMask, options);
        FieldToJson(VkAccessFlags2_t(),jdata["dstAccessMask"], data->decoded_value->dstAccessMask, options);
        FieldToJson(jdata["oldLayout"], data->decoded_value->oldLayout, options);
        FieldToJson(jdata["newLayout"], data->decoded_value->newLayout, options);
        FieldToJson(jdata["srcQueueFamilyIndex"], data->decoded_value->srcQueueFamilyIndex, options);
        FieldToJson(jdata["dstQueueFamilyIndex"], data->decoded_value->dstQueueFamilyIndex, options);
        HandleToJson(jdata["image"], data->image, options);
        FieldToJson(jdata["subresourceRange"], data->subresourceRange, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDependencyInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDependencyFlags_t(),jdata["dependencyFlags"], data->decoded_value->dependencyFlags, options);
        FieldToJson(jdata["memoryBarrierCount"], data->decoded_value->memoryBarrierCount, options);
        FieldToJson(jdata["pMemoryBarriers"], data->pMemoryBarriers, options);
        FieldToJson(jdata["bufferMemoryBarrierCount"], data->decoded_value->bufferMemoryBarrierCount, options);
        FieldToJson(jdata["pBufferMemoryBarriers"], data->pBufferMemoryBarriers, options);
        FieldToJson(jdata["imageMemoryBarrierCount"], data->decoded_value->imageMemoryBarrierCount, options);
        FieldToJson(jdata["pImageMemoryBarriers"], data->pImageMemoryBarriers, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["semaphore"], data->semaphore, options);
        FieldToJson(jdata["value"], data->decoded_value->value, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["stageMask"], data->decoded_value->stageMask, options);
        FieldToJson(jdata["deviceIndex"], data->decoded_value->deviceIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferSubmitInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["commandBuffer"], data->commandBuffer, options);
        FieldToJson(jdata["deviceMask"], data->decoded_value->deviceMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubmitInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkSubmitFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["waitSemaphoreInfoCount"], data->decoded_value->waitSemaphoreInfoCount, options);
        FieldToJson(jdata["pWaitSemaphoreInfos"], data->pWaitSemaphoreInfos, options);
        FieldToJson(jdata["commandBufferInfoCount"], data->decoded_value->commandBufferInfoCount, options);
        FieldToJson(jdata["pCommandBufferInfos"], data->pCommandBufferInfos, options);
        FieldToJson(jdata["signalSemaphoreInfoCount"], data->decoded_value->signalSemaphoreInfoCount, options);
        FieldToJson(jdata["pSignalSemaphoreInfos"], data->pSignalSemaphoreInfos, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSynchronization2Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["synchronization2"] = static_cast<bool>(data->decoded_value->synchronization2);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferCopy2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["srcOffset"], data->decoded_value->srcOffset, options);
        FieldToJson(jdata["dstOffset"], data->decoded_value->dstOffset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyBufferInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["srcBuffer"], data->srcBuffer, options);
        HandleToJson(jdata["dstBuffer"], data->dstBuffer, options);
        FieldToJson(jdata["regionCount"], data->decoded_value->regionCount, options);
        FieldToJson(jdata["pRegions"], data->pRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageCopy2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["srcSubresource"], data->srcSubresource, options);
        FieldToJson(jdata["srcOffset"], data->srcOffset, options);
        FieldToJson(jdata["dstSubresource"], data->dstSubresource, options);
        FieldToJson(jdata["dstOffset"], data->dstOffset, options);
        FieldToJson(jdata["extent"], data->extent, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyImageInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["srcImage"], data->srcImage, options);
        FieldToJson(jdata["srcImageLayout"], data->decoded_value->srcImageLayout, options);
        HandleToJson(jdata["dstImage"], data->dstImage, options);
        FieldToJson(jdata["dstImageLayout"], data->decoded_value->dstImageLayout, options);
        FieldToJson(jdata["regionCount"], data->decoded_value->regionCount, options);
        FieldToJson(jdata["pRegions"], data->pRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferImageCopy2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["bufferOffset"], data->decoded_value->bufferOffset, options);
        FieldToJson(jdata["bufferRowLength"], data->decoded_value->bufferRowLength, options);
        FieldToJson(jdata["bufferImageHeight"], data->decoded_value->bufferImageHeight, options);
        FieldToJson(jdata["imageSubresource"], data->imageSubresource, options);
        FieldToJson(jdata["imageOffset"], data->imageOffset, options);
        FieldToJson(jdata["imageExtent"], data->imageExtent, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyBufferToImageInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["srcBuffer"], data->srcBuffer, options);
        HandleToJson(jdata["dstImage"], data->dstImage, options);
        FieldToJson(jdata["dstImageLayout"], data->decoded_value->dstImageLayout, options);
        FieldToJson(jdata["regionCount"], data->decoded_value->regionCount, options);
        FieldToJson(jdata["pRegions"], data->pRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyImageToBufferInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["srcImage"], data->srcImage, options);
        FieldToJson(jdata["srcImageLayout"], data->decoded_value->srcImageLayout, options);
        HandleToJson(jdata["dstBuffer"], data->dstBuffer, options);
        FieldToJson(jdata["regionCount"], data->decoded_value->regionCount, options);
        FieldToJson(jdata["pRegions"], data->pRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["textureCompressionASTC_HDR"] = static_cast<bool>(data->decoded_value->textureCompressionASTC_HDR);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFormatProperties3* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkFormatFeatureFlags2_t(),jdata["linearTilingFeatures"], data->decoded_value->linearTilingFeatures, options);
        FieldToJson(VkFormatFeatureFlags2_t(),jdata["optimalTilingFeatures"], data->decoded_value->optimalTilingFeatures, options);
        FieldToJson(VkFormatFeatureFlags2_t(),jdata["bufferFeatures"], data->decoded_value->bufferFeatures, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance4Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["maintenance4"] = static_cast<bool>(data->decoded_value->maintenance4);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance4Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxBufferSize"], data->decoded_value->maxBufferSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceBufferMemoryRequirements* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pCreateInfo"], data->pCreateInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceImageMemoryRequirements* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pCreateInfo"], data->pCreateInfo, options);
        FieldToJson(jdata["planeAspect"], data->decoded_value->planeAspect, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCreationFeedback* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkPipelineCreationFeedbackFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["duration"], data->decoded_value->duration, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCreationFeedbackCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pPipelineCreationFeedback"], data->pPipelineCreationFeedback, options);
        FieldToJson(jdata["pipelineStageCreationFeedbackCount"], data->decoded_value->pipelineStageCreationFeedbackCount, options);
        FieldToJson(jdata["pPipelineStageCreationFeedbacks"], data->pPipelineStageCreationFeedbacks, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderTerminateInvocation"] = static_cast<bool>(data->decoded_value->shaderTerminateInvocation);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderDemoteToHelperInvocation"] = static_cast<bool>(data->decoded_value->shaderDemoteToHelperInvocation);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pipelineCreationCacheControl"] = static_cast<bool>(data->decoded_value->pipelineCreationCacheControl);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderZeroInitializeWorkgroupMemory"] = static_cast<bool>(data->decoded_value->shaderZeroInitializeWorkgroupMemory);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageRobustnessFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["robustImageAccess"] = static_cast<bool>(data->decoded_value->robustImageAccess);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSubgroupSizeControlFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["subgroupSizeControl"] = static_cast<bool>(data->decoded_value->subgroupSizeControl);
        jdata["computeFullSubgroups"] = static_cast<bool>(data->decoded_value->computeFullSubgroups);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSubgroupSizeControlProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minSubgroupSize"], data->decoded_value->minSubgroupSize, options);
        FieldToJson(jdata["maxSubgroupSize"], data->decoded_value->maxSubgroupSize, options);
        FieldToJson(jdata["maxComputeWorkgroupSubgroups"], data->decoded_value->maxComputeWorkgroupSubgroups, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["requiredSubgroupSizeStages"], data->decoded_value->requiredSubgroupSizeStages, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["requiredSubgroupSize"], data->decoded_value->requiredSubgroupSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceInlineUniformBlockFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["inlineUniformBlock"] = static_cast<bool>(data->decoded_value->inlineUniformBlock);
        jdata["descriptorBindingInlineUniformBlockUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingInlineUniformBlockUpdateAfterBind);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceInlineUniformBlockProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxInlineUniformBlockSize"], data->decoded_value->maxInlineUniformBlockSize, options);
        FieldToJson(jdata["maxPerStageDescriptorInlineUniformBlocks"], data->decoded_value->maxPerStageDescriptorInlineUniformBlocks, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindInlineUniformBlocks, options);
        FieldToJson(jdata["maxDescriptorSetInlineUniformBlocks"], data->decoded_value->maxDescriptorSetInlineUniformBlocks, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindInlineUniformBlocks"], data->decoded_value->maxDescriptorSetUpdateAfterBindInlineUniformBlocks, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteDescriptorSetInlineUniformBlock* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["dataSize"], data->decoded_value->dataSize, options);
        FieldToJson(jdata["pData"], data->pData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxInlineUniformBlockBindings"], data->decoded_value->maxInlineUniformBlockBindings, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderIntegerDotProductFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderIntegerDotProduct"] = static_cast<bool>(data->decoded_value->shaderIntegerDotProduct);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderIntegerDotProductProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["integerDotProduct8BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct8BitUnsignedAccelerated);
        jdata["integerDotProduct8BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct8BitSignedAccelerated);
        jdata["integerDotProduct8BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct8BitMixedSignednessAccelerated);
        jdata["integerDotProduct4x8BitPackedUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct4x8BitPackedUnsignedAccelerated);
        jdata["integerDotProduct4x8BitPackedSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct4x8BitPackedSignedAccelerated);
        jdata["integerDotProduct4x8BitPackedMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct4x8BitPackedMixedSignednessAccelerated);
        jdata["integerDotProduct16BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct16BitUnsignedAccelerated);
        jdata["integerDotProduct16BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct16BitSignedAccelerated);
        jdata["integerDotProduct16BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct16BitMixedSignednessAccelerated);
        jdata["integerDotProduct32BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct32BitUnsignedAccelerated);
        jdata["integerDotProduct32BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct32BitSignedAccelerated);
        jdata["integerDotProduct32BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct32BitMixedSignednessAccelerated);
        jdata["integerDotProduct64BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct64BitUnsignedAccelerated);
        jdata["integerDotProduct64BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct64BitSignedAccelerated);
        jdata["integerDotProduct64BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProduct64BitMixedSignednessAccelerated);
        jdata["integerDotProductAccumulatingSaturating8BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating8BitUnsignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating8BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating8BitSignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating8BitMixedSignednessAccelerated);
        jdata["integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating4x8BitPackedUnsignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating4x8BitPackedSignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating4x8BitPackedMixedSignednessAccelerated);
        jdata["integerDotProductAccumulatingSaturating16BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating16BitUnsignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating16BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating16BitSignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating16BitMixedSignednessAccelerated);
        jdata["integerDotProductAccumulatingSaturating32BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating32BitUnsignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating32BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating32BitSignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating32BitMixedSignednessAccelerated);
        jdata["integerDotProductAccumulatingSaturating64BitUnsignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating64BitUnsignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating64BitSignedAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating64BitSignedAccelerated);
        jdata["integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated"] = static_cast<bool>(data->decoded_value->integerDotProductAccumulatingSaturating64BitMixedSignednessAccelerated);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["storageTexelBufferOffsetAlignmentBytes"], data->decoded_value->storageTexelBufferOffsetAlignmentBytes, options);
        jdata["storageTexelBufferOffsetSingleTexelAlignment"] = static_cast<bool>(data->decoded_value->storageTexelBufferOffsetSingleTexelAlignment);
        FieldToJson(jdata["uniformTexelBufferOffsetAlignmentBytes"], data->decoded_value->uniformTexelBufferOffsetAlignmentBytes, options);
        jdata["uniformTexelBufferOffsetSingleTexelAlignment"] = static_cast<bool>(data->decoded_value->uniformTexelBufferOffsetSingleTexelAlignment);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageBlit2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["srcSubresource"], data->srcSubresource, options);
        FieldToJson(jdata["srcOffsets"], data->srcOffsets, options);
        FieldToJson(jdata["dstSubresource"], data->dstSubresource, options);
        FieldToJson(jdata["dstOffsets"], data->dstOffsets, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBlitImageInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["srcImage"], data->srcImage, options);
        FieldToJson(jdata["srcImageLayout"], data->decoded_value->srcImageLayout, options);
        HandleToJson(jdata["dstImage"], data->dstImage, options);
        FieldToJson(jdata["dstImageLayout"], data->decoded_value->dstImageLayout, options);
        FieldToJson(jdata["regionCount"], data->decoded_value->regionCount, options);
        FieldToJson(jdata["pRegions"], data->pRegions, options);
        FieldToJson(jdata["filter"], data->decoded_value->filter, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageResolve2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["srcSubresource"], data->srcSubresource, options);
        FieldToJson(jdata["srcOffset"], data->srcOffset, options);
        FieldToJson(jdata["dstSubresource"], data->dstSubresource, options);
        FieldToJson(jdata["dstOffset"], data->dstOffset, options);
        FieldToJson(jdata["extent"], data->extent, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkResolveImageInfo2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["srcImage"], data->srcImage, options);
        FieldToJson(jdata["srcImageLayout"], data->decoded_value->srcImageLayout, options);
        HandleToJson(jdata["dstImage"], data->dstImage, options);
        FieldToJson(jdata["dstImageLayout"], data->decoded_value->dstImageLayout, options);
        FieldToJson(jdata["regionCount"], data->decoded_value->regionCount, options);
        FieldToJson(jdata["pRegions"], data->pRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingAttachmentInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["imageView"], data->imageView, options);
        FieldToJson(jdata["imageLayout"], data->decoded_value->imageLayout, options);
        FieldToJson(jdata["resolveMode"], data->decoded_value->resolveMode, options);
        HandleToJson(jdata["resolveImageView"], data->resolveImageView, options);
        FieldToJson(jdata["resolveImageLayout"], data->decoded_value->resolveImageLayout, options);
        FieldToJson(jdata["loadOp"], data->decoded_value->loadOp, options);
        FieldToJson(jdata["storeOp"], data->decoded_value->storeOp, options);
        FieldToJson(jdata["clearValue"], data->clearValue, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkRenderingFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["renderArea"], data->renderArea, options);
        FieldToJson(jdata["layerCount"], data->decoded_value->layerCount, options);
        FieldToJson(jdata["viewMask"], data->decoded_value->viewMask, options);
        FieldToJson(jdata["colorAttachmentCount"], data->decoded_value->colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachments"], data->pColorAttachments, options);
        FieldToJson(jdata["pDepthAttachment"], data->pDepthAttachment, options);
        FieldToJson(jdata["pStencilAttachment"], data->pStencilAttachment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRenderingCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["viewMask"], data->decoded_value->viewMask, options);
        FieldToJson(jdata["colorAttachmentCount"], data->decoded_value->colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachmentFormats"], data->pColorAttachmentFormats, options);
        FieldToJson(jdata["depthAttachmentFormat"], data->decoded_value->depthAttachmentFormat, options);
        FieldToJson(jdata["stencilAttachmentFormat"], data->decoded_value->stencilAttachmentFormat, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDynamicRenderingFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["dynamicRendering"] = static_cast<bool>(data->decoded_value->dynamicRendering);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferInheritanceRenderingInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkRenderingFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["viewMask"], data->decoded_value->viewMask, options);
        FieldToJson(jdata["colorAttachmentCount"], data->decoded_value->colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachmentFormats"], data->pColorAttachmentFormats, options);
        FieldToJson(jdata["depthAttachmentFormat"], data->decoded_value->depthAttachmentFormat, options);
        FieldToJson(jdata["stencilAttachmentFormat"], data->decoded_value->stencilAttachmentFormat, options);
        FieldToJson(jdata["rasterizationSamples"], data->decoded_value->rasterizationSamples, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan14Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["globalPriorityQuery"] = static_cast<bool>(data->decoded_value->globalPriorityQuery);
        jdata["shaderSubgroupRotate"] = static_cast<bool>(data->decoded_value->shaderSubgroupRotate);
        jdata["shaderSubgroupRotateClustered"] = static_cast<bool>(data->decoded_value->shaderSubgroupRotateClustered);
        jdata["shaderFloatControls2"] = static_cast<bool>(data->decoded_value->shaderFloatControls2);
        jdata["shaderExpectAssume"] = static_cast<bool>(data->decoded_value->shaderExpectAssume);
        jdata["rectangularLines"] = static_cast<bool>(data->decoded_value->rectangularLines);
        jdata["bresenhamLines"] = static_cast<bool>(data->decoded_value->bresenhamLines);
        jdata["smoothLines"] = static_cast<bool>(data->decoded_value->smoothLines);
        jdata["stippledRectangularLines"] = static_cast<bool>(data->decoded_value->stippledRectangularLines);
        jdata["stippledBresenhamLines"] = static_cast<bool>(data->decoded_value->stippledBresenhamLines);
        jdata["stippledSmoothLines"] = static_cast<bool>(data->decoded_value->stippledSmoothLines);
        jdata["vertexAttributeInstanceRateDivisor"] = static_cast<bool>(data->decoded_value->vertexAttributeInstanceRateDivisor);
        jdata["vertexAttributeInstanceRateZeroDivisor"] = static_cast<bool>(data->decoded_value->vertexAttributeInstanceRateZeroDivisor);
        jdata["indexTypeUint8"] = static_cast<bool>(data->decoded_value->indexTypeUint8);
        jdata["dynamicRenderingLocalRead"] = static_cast<bool>(data->decoded_value->dynamicRenderingLocalRead);
        jdata["maintenance5"] = static_cast<bool>(data->decoded_value->maintenance5);
        jdata["maintenance6"] = static_cast<bool>(data->decoded_value->maintenance6);
        jdata["pipelineProtectedAccess"] = static_cast<bool>(data->decoded_value->pipelineProtectedAccess);
        jdata["pipelineRobustness"] = static_cast<bool>(data->decoded_value->pipelineRobustness);
        jdata["hostImageCopy"] = static_cast<bool>(data->decoded_value->hostImageCopy);
        jdata["pushDescriptor"] = static_cast<bool>(data->decoded_value->pushDescriptor);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVulkan14Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["lineSubPixelPrecisionBits"], data->decoded_value->lineSubPixelPrecisionBits, options);
        FieldToJson(jdata["maxVertexAttribDivisor"], data->decoded_value->maxVertexAttribDivisor, options);
        jdata["supportsNonZeroFirstInstance"] = static_cast<bool>(data->decoded_value->supportsNonZeroFirstInstance);
        FieldToJson(jdata["maxPushDescriptors"], data->decoded_value->maxPushDescriptors, options);
        jdata["dynamicRenderingLocalReadDepthStencilAttachments"] = static_cast<bool>(data->decoded_value->dynamicRenderingLocalReadDepthStencilAttachments);
        jdata["dynamicRenderingLocalReadMultisampledAttachments"] = static_cast<bool>(data->decoded_value->dynamicRenderingLocalReadMultisampledAttachments);
        jdata["earlyFragmentMultisampleCoverageAfterSampleCounting"] = static_cast<bool>(data->decoded_value->earlyFragmentMultisampleCoverageAfterSampleCounting);
        jdata["earlyFragmentSampleMaskTestBeforeSampleCounting"] = static_cast<bool>(data->decoded_value->earlyFragmentSampleMaskTestBeforeSampleCounting);
        jdata["depthStencilSwizzleOneSupport"] = static_cast<bool>(data->decoded_value->depthStencilSwizzleOneSupport);
        jdata["polygonModePointSize"] = static_cast<bool>(data->decoded_value->polygonModePointSize);
        jdata["nonStrictSinglePixelWideLinesUseParallelogram"] = static_cast<bool>(data->decoded_value->nonStrictSinglePixelWideLinesUseParallelogram);
        jdata["nonStrictWideLinesUseParallelogram"] = static_cast<bool>(data->decoded_value->nonStrictWideLinesUseParallelogram);
        jdata["blockTexelViewCompatibleMultipleLayers"] = static_cast<bool>(data->decoded_value->blockTexelViewCompatibleMultipleLayers);
        FieldToJson(jdata["maxCombinedImageSamplerDescriptorCount"], data->decoded_value->maxCombinedImageSamplerDescriptorCount, options);
        jdata["fragmentShadingRateClampCombinerInputs"] = static_cast<bool>(data->decoded_value->fragmentShadingRateClampCombinerInputs);
        FieldToJson(jdata["defaultRobustnessStorageBuffers"], data->decoded_value->defaultRobustnessStorageBuffers, options);
        FieldToJson(jdata["defaultRobustnessUniformBuffers"], data->decoded_value->defaultRobustnessUniformBuffers, options);
        FieldToJson(jdata["defaultRobustnessVertexInputs"], data->decoded_value->defaultRobustnessVertexInputs, options);
        FieldToJson(jdata["defaultRobustnessImages"], data->decoded_value->defaultRobustnessImages, options);
        FieldToJson(jdata["copySrcLayoutCount"], data->decoded_value->copySrcLayoutCount, options);
        FieldToJson(jdata["pCopySrcLayouts"], data->pCopySrcLayouts, options);
        FieldToJson(jdata["copyDstLayoutCount"], data->decoded_value->copyDstLayoutCount, options);
        FieldToJson(jdata["pCopyDstLayouts"], data->pCopyDstLayouts, options);
        FieldToJson(jdata["optimalTilingLayoutUUID"], uuid_to_string(sizeof(data->decoded_value->optimalTilingLayoutUUID), data->decoded_value->optimalTilingLayoutUUID), options);
        jdata["identicalMemoryTypeRequirements"] = static_cast<bool>(data->decoded_value->identicalMemoryTypeRequirements);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceQueueGlobalPriorityCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["globalPriority"], data->decoded_value->globalPriority, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["globalPriorityQuery"] = static_cast<bool>(data->decoded_value->globalPriorityQuery);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyGlobalPriorityProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["priorityCount"], data->decoded_value->priorityCount, options);
        FieldToJson(jdata["priorities"], &data->priorities, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceIndexTypeUint8Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["indexTypeUint8"] = static_cast<bool>(data->decoded_value->indexTypeUint8);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryMapInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkMemoryMapFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryUnmapInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkMemoryUnmapFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance5Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["maintenance5"] = static_cast<bool>(data->decoded_value->maintenance5);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance5Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["earlyFragmentMultisampleCoverageAfterSampleCounting"] = static_cast<bool>(data->decoded_value->earlyFragmentMultisampleCoverageAfterSampleCounting);
        jdata["earlyFragmentSampleMaskTestBeforeSampleCounting"] = static_cast<bool>(data->decoded_value->earlyFragmentSampleMaskTestBeforeSampleCounting);
        jdata["depthStencilSwizzleOneSupport"] = static_cast<bool>(data->decoded_value->depthStencilSwizzleOneSupport);
        jdata["polygonModePointSize"] = static_cast<bool>(data->decoded_value->polygonModePointSize);
        jdata["nonStrictSinglePixelWideLinesUseParallelogram"] = static_cast<bool>(data->decoded_value->nonStrictSinglePixelWideLinesUseParallelogram);
        jdata["nonStrictWideLinesUseParallelogram"] = static_cast<bool>(data->decoded_value->nonStrictWideLinesUseParallelogram);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSubresource2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["imageSubresource"], data->imageSubresource, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceImageSubresourceInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pCreateInfo"], data->pCreateInfo, options);
        FieldToJson(jdata["pSubresource"], data->pSubresource, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubresourceLayout2* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["subresourceLayout"], data->subresourceLayout, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferUsageFlags2CreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkBufferUsageFlags2_t(),jdata["usage"], data->decoded_value->usage, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance6Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["maintenance6"] = static_cast<bool>(data->decoded_value->maintenance6);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance6Properties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["blockTexelViewCompatibleMultipleLayers"] = static_cast<bool>(data->decoded_value->blockTexelViewCompatibleMultipleLayers);
        FieldToJson(jdata["maxCombinedImageSamplerDescriptorCount"], data->decoded_value->maxCombinedImageSamplerDescriptorCount, options);
        jdata["fragmentShadingRateClampCombinerInputs"] = static_cast<bool>(data->decoded_value->fragmentShadingRateClampCombinerInputs);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindMemoryStatus* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pResult"], data->pResult, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceHostImageCopyFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["hostImageCopy"] = static_cast<bool>(data->decoded_value->hostImageCopy);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceHostImageCopyProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["copySrcLayoutCount"], data->decoded_value->copySrcLayoutCount, options);
        FieldToJson(jdata["pCopySrcLayouts"], data->pCopySrcLayouts, options);
        FieldToJson(jdata["copyDstLayoutCount"], data->decoded_value->copyDstLayoutCount, options);
        FieldToJson(jdata["pCopyDstLayouts"], data->pCopyDstLayouts, options);
        FieldToJson(jdata["optimalTilingLayoutUUID"], uuid_to_string(sizeof(data->decoded_value->optimalTilingLayoutUUID), data->decoded_value->optimalTilingLayoutUUID), options);
        jdata["identicalMemoryTypeRequirements"] = static_cast<bool>(data->decoded_value->identicalMemoryTypeRequirements);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyImageToImageInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkHostImageCopyFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["srcImage"], data->srcImage, options);
        FieldToJson(jdata["srcImageLayout"], data->decoded_value->srcImageLayout, options);
        HandleToJson(jdata["dstImage"], data->dstImage, options);
        FieldToJson(jdata["dstImageLayout"], data->decoded_value->dstImageLayout, options);
        FieldToJson(jdata["regionCount"], data->decoded_value->regionCount, options);
        FieldToJson(jdata["pRegions"], data->pRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkHostImageLayoutTransitionInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["image"], data->image, options);
        FieldToJson(jdata["oldLayout"], data->decoded_value->oldLayout, options);
        FieldToJson(jdata["newLayout"], data->decoded_value->newLayout, options);
        FieldToJson(jdata["subresourceRange"], data->subresourceRange, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubresourceHostMemcpySize* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkHostImageCopyDevicePerformanceQuery* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["optimalDeviceAccess"] = static_cast<bool>(data->decoded_value->optimalDeviceAccess);
        jdata["identicalMemoryLayout"] = static_cast<bool>(data->decoded_value->identicalMemoryLayout);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderSubgroupRotateFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderSubgroupRotate"] = static_cast<bool>(data->decoded_value->shaderSubgroupRotate);
        jdata["shaderSubgroupRotateClustered"] = static_cast<bool>(data->decoded_value->shaderSubgroupRotateClustered);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderFloatControls2Features* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderFloatControls2"] = static_cast<bool>(data->decoded_value->shaderFloatControls2);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderExpectAssumeFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderExpectAssume"] = static_cast<bool>(data->decoded_value->shaderExpectAssume);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCreateFlags2CreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineCreateFlags2_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePushDescriptorProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxPushDescriptors"], data->decoded_value->maxPushDescriptors, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindDescriptorSetsInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["stageFlags"], data->decoded_value->stageFlags, options);
        HandleToJson(jdata["layout"], data->layout, options);
        FieldToJson(jdata["firstSet"], data->decoded_value->firstSet, options);
        FieldToJson(jdata["descriptorSetCount"], data->decoded_value->descriptorSetCount, options);
        HandleToJson(jdata["pDescriptorSets"], &data->pDescriptorSets, options);
        FieldToJson(jdata["dynamicOffsetCount"], data->decoded_value->dynamicOffsetCount, options);
        FieldToJson(jdata["pDynamicOffsets"], data->pDynamicOffsets, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPushConstantsInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["layout"], data->layout, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["stageFlags"], data->decoded_value->stageFlags, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pValues"], data->pValues, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPushDescriptorSetInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["stageFlags"], data->decoded_value->stageFlags, options);
        HandleToJson(jdata["layout"], data->layout, options);
        FieldToJson(jdata["set"], data->decoded_value->set, options);
        FieldToJson(jdata["descriptorWriteCount"], data->decoded_value->descriptorWriteCount, options);
        FieldToJson(jdata["pDescriptorWrites"], data->pDescriptorWrites, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineProtectedAccessFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pipelineProtectedAccess"] = static_cast<bool>(data->decoded_value->pipelineProtectedAccess);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineRobustnessFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pipelineRobustness"] = static_cast<bool>(data->decoded_value->pipelineRobustness);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineRobustnessProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["defaultRobustnessStorageBuffers"], data->decoded_value->defaultRobustnessStorageBuffers, options);
        FieldToJson(jdata["defaultRobustnessUniformBuffers"], data->decoded_value->defaultRobustnessUniformBuffers, options);
        FieldToJson(jdata["defaultRobustnessVertexInputs"], data->decoded_value->defaultRobustnessVertexInputs, options);
        FieldToJson(jdata["defaultRobustnessImages"], data->decoded_value->defaultRobustnessImages, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRobustnessCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["storageBuffers"], data->decoded_value->storageBuffers, options);
        FieldToJson(jdata["uniformBuffers"], data->decoded_value->uniformBuffers, options);
        FieldToJson(jdata["vertexInputs"], data->decoded_value->vertexInputs, options);
        FieldToJson(jdata["images"], data->decoded_value->images, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLineRasterizationFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["rectangularLines"] = static_cast<bool>(data->decoded_value->rectangularLines);
        jdata["bresenhamLines"] = static_cast<bool>(data->decoded_value->bresenhamLines);
        jdata["smoothLines"] = static_cast<bool>(data->decoded_value->smoothLines);
        jdata["stippledRectangularLines"] = static_cast<bool>(data->decoded_value->stippledRectangularLines);
        jdata["stippledBresenhamLines"] = static_cast<bool>(data->decoded_value->stippledBresenhamLines);
        jdata["stippledSmoothLines"] = static_cast<bool>(data->decoded_value->stippledSmoothLines);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLineRasterizationProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["lineSubPixelPrecisionBits"], data->decoded_value->lineSubPixelPrecisionBits, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationLineStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["lineRasterizationMode"], data->decoded_value->lineRasterizationMode, options);
        jdata["stippledLineEnable"] = static_cast<bool>(data->decoded_value->stippledLineEnable);
        FieldToJson(jdata["lineStippleFactor"], data->decoded_value->lineStippleFactor, options);
        FieldToJson(jdata["lineStipplePattern"], data->decoded_value->lineStipplePattern, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVertexAttributeDivisorProperties* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxVertexAttribDivisor"], data->decoded_value->maxVertexAttribDivisor, options);
        jdata["supportsNonZeroFirstInstance"] = static_cast<bool>(data->decoded_value->supportsNonZeroFirstInstance);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVertexInputBindingDivisorDescription* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["binding"], data->decoded_value->binding, options);
        FieldToJson(jdata["divisor"], data->decoded_value->divisor, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineVertexInputDivisorStateCreateInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["vertexBindingDivisorCount"], data->decoded_value->vertexBindingDivisorCount, options);
        FieldToJson(jdata["pVertexBindingDivisors"], data->pVertexBindingDivisors, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["vertexAttributeInstanceRateDivisor"] = static_cast<bool>(data->decoded_value->vertexAttributeInstanceRateDivisor);
        jdata["vertexAttributeInstanceRateZeroDivisor"] = static_cast<bool>(data->decoded_value->vertexAttributeInstanceRateZeroDivisor);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingAreaInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["viewMask"], data->decoded_value->viewMask, options);
        FieldToJson(jdata["colorAttachmentCount"], data->decoded_value->colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachmentFormats"], data->pColorAttachmentFormats, options);
        FieldToJson(jdata["depthAttachmentFormat"], data->decoded_value->depthAttachmentFormat, options);
        FieldToJson(jdata["stencilAttachmentFormat"], data->decoded_value->stencilAttachmentFormat, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeatures* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["dynamicRenderingLocalRead"] = static_cast<bool>(data->decoded_value->dynamicRenderingLocalRead);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingAttachmentLocationInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["colorAttachmentCount"], data->decoded_value->colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachmentLocations"], data->pColorAttachmentLocations, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingInputAttachmentIndexInfo* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["colorAttachmentCount"], data->decoded_value->colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachmentInputIndices"], data->pColorAttachmentInputIndices, options);
        FieldToJson(jdata["pDepthInputAttachmentIndex"], data->pDepthInputAttachmentIndex, options);
        FieldToJson(jdata["pStencilInputAttachmentIndex"], data->pStencilInputAttachmentIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["minImageCount"], data->decoded_value->minImageCount, options);
        FieldToJson(jdata["maxImageCount"], data->decoded_value->maxImageCount, options);
        FieldToJson(jdata["currentExtent"], data->currentExtent, options);
        FieldToJson(jdata["minImageExtent"], data->minImageExtent, options);
        FieldToJson(jdata["maxImageExtent"], data->maxImageExtent, options);
        FieldToJson(jdata["maxImageArrayLayers"], data->decoded_value->maxImageArrayLayers, options);
        FieldToJson(VkSurfaceTransformFlagsKHR_t(),jdata["supportedTransforms"], data->decoded_value->supportedTransforms, options);
        FieldToJson(jdata["currentTransform"], data->decoded_value->currentTransform, options);
        FieldToJson(VkCompositeAlphaFlagsKHR_t(),jdata["supportedCompositeAlpha"], data->decoded_value->supportedCompositeAlpha, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["supportedUsageFlags"], data->decoded_value->supportedUsageFlags, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceFormatKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["colorSpace"], data->decoded_value->colorSpace, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkSwapchainCreateFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["surface"], data->surface, options);
        FieldToJson(jdata["minImageCount"], data->decoded_value->minImageCount, options);
        FieldToJson(jdata["imageFormat"], data->decoded_value->imageFormat, options);
        FieldToJson(jdata["imageColorSpace"], data->decoded_value->imageColorSpace, options);
        FieldToJson(jdata["imageExtent"], data->imageExtent, options);
        FieldToJson(jdata["imageArrayLayers"], data->decoded_value->imageArrayLayers, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["imageUsage"], data->decoded_value->imageUsage, options);
        FieldToJson(jdata["imageSharingMode"], data->decoded_value->imageSharingMode, options);
        FieldToJson(jdata["queueFamilyIndexCount"], data->decoded_value->queueFamilyIndexCount, options);
        FieldToJson(jdata["pQueueFamilyIndices"], data->pQueueFamilyIndices, options);
        FieldToJson(jdata["preTransform"], data->decoded_value->preTransform, options);
        FieldToJson(jdata["compositeAlpha"], data->decoded_value->compositeAlpha, options);
        FieldToJson(jdata["presentMode"], data->decoded_value->presentMode, options);
        jdata["clipped"] = static_cast<bool>(data->decoded_value->clipped);
        HandleToJson(jdata["oldSwapchain"], data->oldSwapchain, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["waitSemaphoreCount"], data->decoded_value->waitSemaphoreCount, options);
        HandleToJson(jdata["pWaitSemaphores"], &data->pWaitSemaphores, options);
        FieldToJson(jdata["swapchainCount"], data->decoded_value->swapchainCount, options);
        HandleToJson(jdata["pSwapchains"], &data->pSwapchains, options);
        FieldToJson(jdata["pImageIndices"], data->pImageIndices, options);
        FieldToJson(jdata["pResults"], data->pResults, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageSwapchainCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["swapchain"], data->swapchain, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindImageMemorySwapchainInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["swapchain"], data->swapchain, options);
        FieldToJson(jdata["imageIndex"], data->decoded_value->imageIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAcquireNextImageInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["swapchain"], data->swapchain, options);
        FieldToJson(jdata["timeout"], data->decoded_value->timeout, options);
        HandleToJson(jdata["semaphore"], data->semaphore, options);
        HandleToJson(jdata["fence"], data->fence, options);
        FieldToJson(jdata["deviceMask"], data->decoded_value->deviceMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupPresentCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["presentMask"], &data->presentMask, options);
        FieldToJson(VkDeviceGroupPresentModeFlagsKHR_t(),jdata["modes"], data->decoded_value->modes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupPresentInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["swapchainCount"], data->decoded_value->swapchainCount, options);
        FieldToJson(jdata["pDeviceMasks"], data->pDeviceMasks, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceGroupSwapchainCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDeviceGroupPresentModeFlagsKHR_t(),jdata["modes"], data->decoded_value->modes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayModeParametersKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["visibleRegion"], data->visibleRegion, options);
        FieldToJson(jdata["refreshRate"], data->decoded_value->refreshRate, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayModeCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDisplayModeCreateFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["parameters"], data->parameters, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayModePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["displayMode"], data->displayMode, options);
        FieldToJson(jdata["parameters"], data->parameters, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPlaneCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkDisplayPlaneAlphaFlagsKHR_t(),jdata["supportedAlpha"], data->decoded_value->supportedAlpha, options);
        FieldToJson(jdata["minSrcPosition"], data->minSrcPosition, options);
        FieldToJson(jdata["maxSrcPosition"], data->maxSrcPosition, options);
        FieldToJson(jdata["minSrcExtent"], data->minSrcExtent, options);
        FieldToJson(jdata["maxSrcExtent"], data->maxSrcExtent, options);
        FieldToJson(jdata["minDstPosition"], data->minDstPosition, options);
        FieldToJson(jdata["maxDstPosition"], data->maxDstPosition, options);
        FieldToJson(jdata["minDstExtent"], data->minDstExtent, options);
        FieldToJson(jdata["maxDstExtent"], data->maxDstExtent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPlanePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["currentDisplay"], data->currentDisplay, options);
        FieldToJson(jdata["currentStackIndex"], data->decoded_value->currentStackIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["display"], data->display, options);
        FieldToJson(jdata["displayName"], &data->displayName, options);
        FieldToJson(jdata["physicalDimensions"], data->physicalDimensions, options);
        FieldToJson(jdata["physicalResolution"], data->physicalResolution, options);
        FieldToJson(VkSurfaceTransformFlagsKHR_t(),jdata["supportedTransforms"], data->decoded_value->supportedTransforms, options);
        jdata["planeReorderPossible"] = static_cast<bool>(data->decoded_value->planeReorderPossible);
        jdata["persistentContent"] = static_cast<bool>(data->decoded_value->persistentContent);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplaySurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDisplaySurfaceCreateFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["displayMode"], data->displayMode, options);
        FieldToJson(jdata["planeIndex"], data->decoded_value->planeIndex, options);
        FieldToJson(jdata["planeStackIndex"], data->decoded_value->planeStackIndex, options);
        FieldToJson(jdata["transform"], data->decoded_value->transform, options);
        FieldToJson(jdata["globalAlpha"], data->decoded_value->globalAlpha, options);
        FieldToJson(jdata["alphaMode"], data->decoded_value->alphaMode, options);
        FieldToJson(jdata["imageExtent"], data->imageExtent, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPresentInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["srcRect"], data->srcRect, options);
        FieldToJson(jdata["dstRect"], data->dstRect, options);
        jdata["persistent"] = static_cast<bool>(data->decoded_value->persistent);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkXlibSurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkXlibSurfaceCreateFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["dpy"], data->dpy, options);
        FieldToJson(jdata["window"], data->decoded_value->window, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkXcbSurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkXcbSurfaceCreateFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["connection"], data->connection, options);
        FieldToJson(jdata["window"], data->decoded_value->window, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWaylandSurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkWaylandSurfaceCreateFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["display"], data->display, options);
        FieldToJson(jdata["surface"], data->surface, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidSurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkAndroidSurfaceCreateFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["window"], data->window, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWin32SurfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkWin32SurfaceCreateFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["hinstance"], data->hinstance, options);
        FieldToJson(jdata["hwnd"], data->hwnd, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyQueryResultStatusPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["queryResultStatusSupport"] = static_cast<bool>(data->decoded_value->queryResultStatusSupport);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyVideoPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoCodecOperationFlagsKHR_t(),jdata["videoCodecOperations"], data->decoded_value->videoCodecOperations, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoProfileInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["videoCodecOperation"], data->decoded_value->videoCodecOperation, options);
        FieldToJson(VkVideoChromaSubsamplingFlagsKHR_t(),jdata["chromaSubsampling"], data->decoded_value->chromaSubsampling, options);
        FieldToJson(VkVideoComponentBitDepthFlagsKHR_t(),jdata["lumaBitDepth"], data->decoded_value->lumaBitDepth, options);
        FieldToJson(VkVideoComponentBitDepthFlagsKHR_t(),jdata["chromaBitDepth"], data->decoded_value->chromaBitDepth, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoProfileListInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["profileCount"], data->decoded_value->profileCount, options);
        FieldToJson(jdata["pProfiles"], data->pProfiles, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoCapabilityFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["minBitstreamBufferOffsetAlignment"], data->decoded_value->minBitstreamBufferOffsetAlignment, options);
        FieldToJson(jdata["minBitstreamBufferSizeAlignment"], data->decoded_value->minBitstreamBufferSizeAlignment, options);
        FieldToJson(jdata["pictureAccessGranularity"], data->pictureAccessGranularity, options);
        FieldToJson(jdata["minCodedExtent"], data->minCodedExtent, options);
        FieldToJson(jdata["maxCodedExtent"], data->maxCodedExtent, options);
        FieldToJson(jdata["maxDpbSlots"], data->decoded_value->maxDpbSlots, options);
        FieldToJson(jdata["maxActiveReferencePictures"], data->decoded_value->maxActiveReferencePictures, options);
        FieldToJson(jdata["stdHeaderVersion"], data->stdHeaderVersion, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVideoFormatInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["imageUsage"], data->decoded_value->imageUsage, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoFormatPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["componentMapping"], data->componentMapping, options);
        FieldToJson(VkImageCreateFlags_t(),jdata["imageCreateFlags"], data->decoded_value->imageCreateFlags, options);
        FieldToJson(jdata["imageType"], data->decoded_value->imageType, options);
        FieldToJson(jdata["imageTiling"], data->decoded_value->imageTiling, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["imageUsageFlags"], data->decoded_value->imageUsageFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoPictureResourceInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["codedOffset"], data->codedOffset, options);
        FieldToJson(jdata["codedExtent"], data->codedExtent, options);
        FieldToJson(jdata["baseArrayLayer"], data->decoded_value->baseArrayLayer, options);
        HandleToJson(jdata["imageViewBinding"], data->imageViewBinding, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoReferenceSlotInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["slotIndex"], data->decoded_value->slotIndex, options);
        FieldToJson(jdata["pPictureResource"], data->pPictureResource, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoSessionMemoryRequirementsKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["memoryBindIndex"], data->decoded_value->memoryBindIndex, options);
        FieldToJson(jdata["memoryRequirements"], data->memoryRequirements, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindVideoSessionMemoryInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["memoryBindIndex"], data->decoded_value->memoryBindIndex, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["memoryOffset"], data->decoded_value->memoryOffset, options);
        FieldToJson(jdata["memorySize"], data->decoded_value->memorySize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoSessionCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["queueFamilyIndex"], data->decoded_value->queueFamilyIndex, options);
        FieldToJson(VkVideoSessionCreateFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pVideoProfile"], data->pVideoProfile, options);
        FieldToJson(jdata["pictureFormat"], data->decoded_value->pictureFormat, options);
        FieldToJson(jdata["maxCodedExtent"], data->maxCodedExtent, options);
        FieldToJson(jdata["referencePictureFormat"], data->decoded_value->referencePictureFormat, options);
        FieldToJson(jdata["maxDpbSlots"], data->decoded_value->maxDpbSlots, options);
        FieldToJson(jdata["maxActiveReferencePictures"], data->decoded_value->maxActiveReferencePictures, options);
        FieldToJson(jdata["pStdHeaderVersion"], data->pStdHeaderVersion, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoSessionParametersCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoSessionParametersCreateFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["videoSessionParametersTemplate"], data->videoSessionParametersTemplate, options);
        HandleToJson(jdata["videoSession"], data->videoSession, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoSessionParametersUpdateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["updateSequenceCount"], data->decoded_value->updateSequenceCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoBeginCodingInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoBeginCodingFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["videoSession"], data->videoSession, options);
        HandleToJson(jdata["videoSessionParameters"], data->videoSessionParameters, options);
        FieldToJson(jdata["referenceSlotCount"], data->decoded_value->referenceSlotCount, options);
        FieldToJson(jdata["pReferenceSlots"], data->pReferenceSlots, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEndCodingInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEndCodingFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoCodingControlInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoCodingControlFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoDecodeCapabilityFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeUsageInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoDecodeUsageFlagsKHR_t(),jdata["videoUsageHints"], data->decoded_value->videoUsageHints, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoDecodeFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["srcBuffer"], data->srcBuffer, options);
        FieldToJson(jdata["srcBufferOffset"], data->decoded_value->srcBufferOffset, options);
        FieldToJson(jdata["srcBufferRange"], data->decoded_value->srcBufferRange, options);
        FieldToJson(jdata["dstPictureResource"], data->dstPictureResource, options);
        FieldToJson(jdata["pSetupReferenceSlot"], data->pSetupReferenceSlot, options);
        FieldToJson(jdata["referenceSlotCount"], data->decoded_value->referenceSlotCount, options);
        FieldToJson(jdata["pReferenceSlots"], data->pReferenceSlots, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264CapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeH264CapabilityFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["maxLevelIdc"], data->decoded_value->maxLevelIdc, options);
        FieldToJson(jdata["maxSliceCount"], data->decoded_value->maxSliceCount, options);
        FieldToJson(jdata["maxPPictureL0ReferenceCount"], data->decoded_value->maxPPictureL0ReferenceCount, options);
        FieldToJson(jdata["maxBPictureL0ReferenceCount"], data->decoded_value->maxBPictureL0ReferenceCount, options);
        FieldToJson(jdata["maxL1ReferenceCount"], data->decoded_value->maxL1ReferenceCount, options);
        FieldToJson(jdata["maxTemporalLayerCount"], data->decoded_value->maxTemporalLayerCount, options);
        jdata["expectDyadicTemporalLayerPattern"] = static_cast<bool>(data->decoded_value->expectDyadicTemporalLayerPattern);
        FieldToJson(jdata["minQp"], data->decoded_value->minQp, options);
        FieldToJson(jdata["maxQp"], data->decoded_value->maxQp, options);
        jdata["prefersGopRemainingFrames"] = static_cast<bool>(data->decoded_value->prefersGopRemainingFrames);
        jdata["requiresGopRemainingFrames"] = static_cast<bool>(data->decoded_value->requiresGopRemainingFrames);
        FieldToJson(VkVideoEncodeH264StdFlagsKHR_t(),jdata["stdSyntaxFlags"], data->decoded_value->stdSyntaxFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264QpKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["qpI"], data->decoded_value->qpI, options);
        FieldToJson(jdata["qpP"], data->decoded_value->qpP, options);
        FieldToJson(jdata["qpB"], data->decoded_value->qpB, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeH264RateControlFlagsKHR_t(),jdata["preferredRateControlFlags"], data->decoded_value->preferredRateControlFlags, options);
        FieldToJson(jdata["preferredGopFrameCount"], data->decoded_value->preferredGopFrameCount, options);
        FieldToJson(jdata["preferredIdrPeriod"], data->decoded_value->preferredIdrPeriod, options);
        FieldToJson(jdata["preferredConsecutiveBFrameCount"], data->decoded_value->preferredConsecutiveBFrameCount, options);
        FieldToJson(jdata["preferredTemporalLayerCount"], data->decoded_value->preferredTemporalLayerCount, options);
        FieldToJson(jdata["preferredConstantQp"], data->preferredConstantQp, options);
        FieldToJson(jdata["preferredMaxL0ReferenceCount"], data->decoded_value->preferredMaxL0ReferenceCount, options);
        FieldToJson(jdata["preferredMaxL1ReferenceCount"], data->decoded_value->preferredMaxL1ReferenceCount, options);
        jdata["preferredStdEntropyCodingModeFlag"] = static_cast<bool>(data->decoded_value->preferredStdEntropyCodingModeFlag);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264SessionCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["useMaxLevelIdc"] = static_cast<bool>(data->decoded_value->useMaxLevelIdc);
        FieldToJson(jdata["maxLevelIdc"], data->decoded_value->maxLevelIdc, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stdSPSCount"], data->decoded_value->stdSPSCount, options);
        FieldToJson(jdata["pStdSPSs"], data->pStdSPSs, options);
        FieldToJson(jdata["stdPPSCount"], data->decoded_value->stdPPSCount, options);
        FieldToJson(jdata["pStdPPSs"], data->pStdPPSs, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxStdSPSCount"], data->decoded_value->maxStdSPSCount, options);
        FieldToJson(jdata["maxStdPPSCount"], data->decoded_value->maxStdPPSCount, options);
        FieldToJson(jdata["pParametersAddInfo"], data->pParametersAddInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["writeStdSPS"] = static_cast<bool>(data->decoded_value->writeStdSPS);
        jdata["writeStdPPS"] = static_cast<bool>(data->decoded_value->writeStdPPS);
        FieldToJson(jdata["stdSPSId"], data->decoded_value->stdSPSId, options);
        FieldToJson(jdata["stdPPSId"], data->decoded_value->stdPPSId, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["hasStdSPSOverrides"] = static_cast<bool>(data->decoded_value->hasStdSPSOverrides);
        jdata["hasStdPPSOverrides"] = static_cast<bool>(data->decoded_value->hasStdPPSOverrides);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264NaluSliceInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["constantQp"], data->decoded_value->constantQp, options);
        FieldToJson(jdata["pStdSliceHeader"], data->pStdSliceHeader, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264PictureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["naluSliceEntryCount"], data->decoded_value->naluSliceEntryCount, options);
        FieldToJson(jdata["pNaluSliceEntries"], data->pNaluSliceEntries, options);
        FieldToJson(jdata["pStdPictureInfo"], data->pStdPictureInfo, options);
        jdata["generatePrefixNalu"] = static_cast<bool>(data->decoded_value->generatePrefixNalu);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264DpbSlotInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pStdReferenceInfo"], data->pStdReferenceInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264ProfileInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stdProfileIdc"], data->decoded_value->stdProfileIdc, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264RateControlInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeH264RateControlFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["gopFrameCount"], data->decoded_value->gopFrameCount, options);
        FieldToJson(jdata["idrPeriod"], data->decoded_value->idrPeriod, options);
        FieldToJson(jdata["consecutiveBFrameCount"], data->decoded_value->consecutiveBFrameCount, options);
        FieldToJson(jdata["temporalLayerCount"], data->decoded_value->temporalLayerCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264FrameSizeKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["frameISize"], data->decoded_value->frameISize, options);
        FieldToJson(jdata["framePSize"], data->decoded_value->framePSize, options);
        FieldToJson(jdata["frameBSize"], data->decoded_value->frameBSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264RateControlLayerInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["useMinQp"] = static_cast<bool>(data->decoded_value->useMinQp);
        FieldToJson(jdata["minQp"], data->minQp, options);
        jdata["useMaxQp"] = static_cast<bool>(data->decoded_value->useMaxQp);
        FieldToJson(jdata["maxQp"], data->maxQp, options);
        jdata["useMaxFrameSize"] = static_cast<bool>(data->decoded_value->useMaxFrameSize);
        FieldToJson(jdata["maxFrameSize"], data->maxFrameSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["useGopRemainingFrames"] = static_cast<bool>(data->decoded_value->useGopRemainingFrames);
        FieldToJson(jdata["gopRemainingI"], data->decoded_value->gopRemainingI, options);
        FieldToJson(jdata["gopRemainingP"], data->decoded_value->gopRemainingP, options);
        FieldToJson(jdata["gopRemainingB"], data->decoded_value->gopRemainingB, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264ProfileInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stdProfileIdc"], data->decoded_value->stdProfileIdc, options);
        FieldToJson(jdata["pictureLayout"], data->decoded_value->pictureLayout, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264CapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxLevelIdc"], data->decoded_value->maxLevelIdc, options);
        FieldToJson(jdata["fieldOffsetGranularity"], data->fieldOffsetGranularity, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264SessionParametersAddInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stdSPSCount"], data->decoded_value->stdSPSCount, options);
        FieldToJson(jdata["pStdSPSs"], data->pStdSPSs, options);
        FieldToJson(jdata["stdPPSCount"], data->decoded_value->stdPPSCount, options);
        FieldToJson(jdata["pStdPPSs"], data->pStdPPSs, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264SessionParametersCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxStdSPSCount"], data->decoded_value->maxStdSPSCount, options);
        FieldToJson(jdata["maxStdPPSCount"], data->decoded_value->maxStdPPSCount, options);
        FieldToJson(jdata["pParametersAddInfo"], data->pParametersAddInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264PictureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pStdPictureInfo"], data->pStdPictureInfo, options);
        FieldToJson(jdata["sliceCount"], data->decoded_value->sliceCount, options);
        FieldToJson(jdata["pSliceOffsets"], data->pSliceOffsets, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeH264DpbSlotInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pStdReferenceInfo"], data->pStdReferenceInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["handle"], data->handle, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportMemoryWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pAttributes"], data->pAttributes, options);
        FieldToJson(jdata["dwAccess"], data->decoded_value->dwAccess, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryWin32HandlePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["memoryTypeBits"], data->decoded_value->memoryTypeBits, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["fd"], data->decoded_value->fd, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryFdPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["memoryTypeBits"], data->decoded_value->memoryTypeBits, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["acquireCount"], data->decoded_value->acquireCount, options);
        HandleToJson(jdata["pAcquireSyncs"], &data->pAcquireSyncs, options);
        FieldToJson(jdata["pAcquireKeys"], data->pAcquireKeys, options);
        FieldToJson(jdata["pAcquireTimeouts"], data->pAcquireTimeouts, options);
        FieldToJson(jdata["releaseCount"], data->decoded_value->releaseCount, options);
        HandleToJson(jdata["pReleaseSyncs"], &data->pReleaseSyncs, options);
        FieldToJson(jdata["pReleaseKeys"], data->pReleaseKeys, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportSemaphoreWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["semaphore"], data->semaphore, options);
        FieldToJson(VkSemaphoreImportFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["handle"], data->handle, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportSemaphoreWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pAttributes"], data->pAttributes, options);
        FieldToJson(jdata["dwAccess"], data->decoded_value->dwAccess, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkD3D12FenceSubmitInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["waitSemaphoreValuesCount"], data->decoded_value->waitSemaphoreValuesCount, options);
        FieldToJson(jdata["pWaitSemaphoreValues"], data->pWaitSemaphoreValues, options);
        FieldToJson(jdata["signalSemaphoreValuesCount"], data->decoded_value->signalSemaphoreValuesCount, options);
        FieldToJson(jdata["pSignalSemaphoreValues"], data->pSignalSemaphoreValues, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreGetWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["semaphore"], data->semaphore, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportSemaphoreFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["semaphore"], data->semaphore, options);
        FieldToJson(VkSemaphoreImportFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["fd"], data->decoded_value->fd, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreGetFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["semaphore"], data->semaphore, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRectLayerKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["offset"], data->offset, options);
        FieldToJson(jdata["extent"], data->extent, options);
        FieldToJson(jdata["layer"], data->decoded_value->layer, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentRegionKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["rectangleCount"], data->decoded_value->rectangleCount, options);
        FieldToJson(jdata["pRectangles"], data->pRectangles, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentRegionsKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["swapchainCount"], data->decoded_value->swapchainCount, options);
        FieldToJson(jdata["pRegions"], data->pRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSharedPresentSurfaceCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["sharedPresentSupportedUsageFlags"], data->decoded_value->sharedPresentSupportedUsageFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportFenceWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["fence"], data->fence, options);
        FieldToJson(VkFenceImportFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["handle"], data->handle, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportFenceWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pAttributes"], data->pAttributes, options);
        FieldToJson(jdata["dwAccess"], data->decoded_value->dwAccess, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFenceGetWin32HandleInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["fence"], data->fence, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportFenceFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["fence"], data->fence, options);
        FieldToJson(VkFenceImportFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["fd"], data->decoded_value->fd, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFenceGetFdInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["fence"], data->fence, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePerformanceQueryFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["performanceCounterQueryPools"] = static_cast<bool>(data->decoded_value->performanceCounterQueryPools);
        jdata["performanceCounterMultipleQueryPools"] = static_cast<bool>(data->decoded_value->performanceCounterMultipleQueryPools);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePerformanceQueryPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["allowCommandBufferQueryCopies"] = static_cast<bool>(data->decoded_value->allowCommandBufferQueryCopies);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceCounterKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["unit"], data->decoded_value->unit, options);
        FieldToJson(jdata["scope"], data->decoded_value->scope, options);
        FieldToJson(jdata["storage"], data->decoded_value->storage, options);
        FieldToJson(jdata["uuid"], uuid_to_string(sizeof(data->decoded_value->uuid), data->decoded_value->uuid), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceCounterDescriptionKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPerformanceCounterDescriptionFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["category"], &data->category, options);
        FieldToJson(jdata["description"], &data->description, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueryPoolPerformanceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["queueFamilyIndex"], data->decoded_value->queueFamilyIndex, options);
        FieldToJson(jdata["counterIndexCount"], data->decoded_value->counterIndexCount, options);
        FieldToJson(jdata["pCounterIndices"], data->pCounterIndices, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAcquireProfilingLockInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkAcquireProfilingLockFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["timeout"], data->decoded_value->timeout, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceQuerySubmitInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["counterPassIndex"], data->decoded_value->counterPassIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSurfaceInfo2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["surface"], data->surface, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilities2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["surfaceCapabilities"], data->surfaceCapabilities, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceFormat2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["surfaceFormat"], data->surfaceFormat, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayProperties2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["displayProperties"], data->displayProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPlaneProperties2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["displayPlaneProperties"], data->displayPlaneProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayModeProperties2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["displayModeProperties"], data->displayModeProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPlaneInfo2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["mode"], data->mode, options);
        FieldToJson(jdata["planeIndex"], data->decoded_value->planeIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPlaneCapabilities2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["capabilities"], data->capabilities, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderBfloat16FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderBFloat16Type"] = static_cast<bool>(data->decoded_value->shaderBFloat16Type);
        jdata["shaderBFloat16DotProduct"] = static_cast<bool>(data->decoded_value->shaderBFloat16DotProduct);
        jdata["shaderBFloat16CooperativeMatrix"] = static_cast<bool>(data->decoded_value->shaderBFloat16CooperativeMatrix);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePortabilitySubsetFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["constantAlphaColorBlendFactors"] = static_cast<bool>(data->decoded_value->constantAlphaColorBlendFactors);
        jdata["events"] = static_cast<bool>(data->decoded_value->events);
        jdata["imageViewFormatReinterpretation"] = static_cast<bool>(data->decoded_value->imageViewFormatReinterpretation);
        jdata["imageViewFormatSwizzle"] = static_cast<bool>(data->decoded_value->imageViewFormatSwizzle);
        jdata["imageView2DOn3DImage"] = static_cast<bool>(data->decoded_value->imageView2DOn3DImage);
        jdata["multisampleArrayImage"] = static_cast<bool>(data->decoded_value->multisampleArrayImage);
        jdata["mutableComparisonSamplers"] = static_cast<bool>(data->decoded_value->mutableComparisonSamplers);
        jdata["pointPolygons"] = static_cast<bool>(data->decoded_value->pointPolygons);
        jdata["samplerMipLodBias"] = static_cast<bool>(data->decoded_value->samplerMipLodBias);
        jdata["separateStencilMaskRef"] = static_cast<bool>(data->decoded_value->separateStencilMaskRef);
        jdata["shaderSampleRateInterpolationFunctions"] = static_cast<bool>(data->decoded_value->shaderSampleRateInterpolationFunctions);
        jdata["tessellationIsolines"] = static_cast<bool>(data->decoded_value->tessellationIsolines);
        jdata["tessellationPointMode"] = static_cast<bool>(data->decoded_value->tessellationPointMode);
        jdata["triangleFans"] = static_cast<bool>(data->decoded_value->triangleFans);
        jdata["vertexAttributeAccessBeyondStride"] = static_cast<bool>(data->decoded_value->vertexAttributeAccessBeyondStride);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePortabilitySubsetPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minVertexInputBindingStrideAlignment"], data->decoded_value->minVertexInputBindingStrideAlignment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderClockFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderSubgroupClock"] = static_cast<bool>(data->decoded_value->shaderSubgroupClock);
        jdata["shaderDeviceClock"] = static_cast<bool>(data->decoded_value->shaderDeviceClock);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFragmentShadingRateAttachmentInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pFragmentShadingRateAttachment"], data->pFragmentShadingRateAttachment, options);
        FieldToJson(jdata["shadingRateAttachmentTexelSize"], data->shadingRateAttachmentTexelSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["fragmentSize"], data->fragmentSize, options);
        FieldToJson(jdata["combinerOps"], &data->combinerOps, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShadingRateFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pipelineFragmentShadingRate"] = static_cast<bool>(data->decoded_value->pipelineFragmentShadingRate);
        jdata["primitiveFragmentShadingRate"] = static_cast<bool>(data->decoded_value->primitiveFragmentShadingRate);
        jdata["attachmentFragmentShadingRate"] = static_cast<bool>(data->decoded_value->attachmentFragmentShadingRate);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShadingRatePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minFragmentShadingRateAttachmentTexelSize"], data->minFragmentShadingRateAttachmentTexelSize, options);
        FieldToJson(jdata["maxFragmentShadingRateAttachmentTexelSize"], data->maxFragmentShadingRateAttachmentTexelSize, options);
        FieldToJson(jdata["maxFragmentShadingRateAttachmentTexelSizeAspectRatio"], data->decoded_value->maxFragmentShadingRateAttachmentTexelSizeAspectRatio, options);
        jdata["primitiveFragmentShadingRateWithMultipleViewports"] = static_cast<bool>(data->decoded_value->primitiveFragmentShadingRateWithMultipleViewports);
        jdata["layeredShadingRateAttachments"] = static_cast<bool>(data->decoded_value->layeredShadingRateAttachments);
        jdata["fragmentShadingRateNonTrivialCombinerOps"] = static_cast<bool>(data->decoded_value->fragmentShadingRateNonTrivialCombinerOps);
        FieldToJson(jdata["maxFragmentSize"], data->maxFragmentSize, options);
        FieldToJson(jdata["maxFragmentSizeAspectRatio"], data->decoded_value->maxFragmentSizeAspectRatio, options);
        FieldToJson(jdata["maxFragmentShadingRateCoverageSamples"], data->decoded_value->maxFragmentShadingRateCoverageSamples, options);
        FieldToJson(jdata["maxFragmentShadingRateRasterizationSamples"], data->decoded_value->maxFragmentShadingRateRasterizationSamples, options);
        jdata["fragmentShadingRateWithShaderDepthStencilWrites"] = static_cast<bool>(data->decoded_value->fragmentShadingRateWithShaderDepthStencilWrites);
        jdata["fragmentShadingRateWithSampleMask"] = static_cast<bool>(data->decoded_value->fragmentShadingRateWithSampleMask);
        jdata["fragmentShadingRateWithShaderSampleMask"] = static_cast<bool>(data->decoded_value->fragmentShadingRateWithShaderSampleMask);
        jdata["fragmentShadingRateWithConservativeRasterization"] = static_cast<bool>(data->decoded_value->fragmentShadingRateWithConservativeRasterization);
        jdata["fragmentShadingRateWithFragmentShaderInterlock"] = static_cast<bool>(data->decoded_value->fragmentShadingRateWithFragmentShaderInterlock);
        jdata["fragmentShadingRateWithCustomSampleLocations"] = static_cast<bool>(data->decoded_value->fragmentShadingRateWithCustomSampleLocations);
        jdata["fragmentShadingRateStrictMultiplyCombiner"] = static_cast<bool>(data->decoded_value->fragmentShadingRateStrictMultiplyCombiner);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShadingRateKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampleCounts"], data->decoded_value->sampleCounts, options);
        FieldToJson(jdata["fragmentSize"], data->fragmentSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["imageView"], data->imageView, options);
        FieldToJson(jdata["imageLayout"], data->decoded_value->imageLayout, options);
        FieldToJson(jdata["shadingRateAttachmentTexelSize"], data->shadingRateAttachmentTexelSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderQuadControl"] = static_cast<bool>(data->decoded_value->shaderQuadControl);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceProtectedCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["supportsProtected"] = static_cast<bool>(data->decoded_value->supportsProtected);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePresentWaitFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentWait"] = static_cast<bool>(data->decoded_value->presentWait);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pipelineExecutableInfo"] = static_cast<bool>(data->decoded_value->pipelineExecutableInfo);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["pipeline"], data->pipeline, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineExecutablePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["stages"], data->decoded_value->stages, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["description"], &data->description, options);
        FieldToJson(jdata["subgroupSize"], data->decoded_value->subgroupSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineExecutableInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["pipeline"], data->pipeline, options);
        FieldToJson(jdata["executableIndex"], data->decoded_value->executableIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineExecutableInternalRepresentationKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["description"], &data->description, options);
        jdata["isText"] = static_cast<bool>(data->decoded_value->isText);
        FieldToJson(jdata["dataSize"], data->decoded_value->dataSize, options);
        FieldToJson(jdata["pData"], data->pData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineLibraryCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["libraryCount"], data->decoded_value->libraryCount, options);
        HandleToJson(jdata["pLibraries"], &data->pLibraries, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentIdKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["swapchainCount"], data->decoded_value->swapchainCount, options);
        FieldToJson(jdata["pPresentIds"], data->pPresentIds, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePresentIdFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentId"] = static_cast<bool>(data->decoded_value->presentId);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        HandleToJson(jdata["dstBuffer"], data->dstBuffer, options);
        FieldToJson(jdata["dstBufferOffset"], data->decoded_value->dstBufferOffset, options);
        FieldToJson(jdata["dstBufferRange"], data->decoded_value->dstBufferRange, options);
        FieldToJson(jdata["srcPictureResource"], data->srcPictureResource, options);
        FieldToJson(jdata["pSetupReferenceSlot"], data->pSetupReferenceSlot, options);
        FieldToJson(jdata["referenceSlotCount"], data->decoded_value->referenceSlotCount, options);
        FieldToJson(jdata["pReferenceSlots"], data->pReferenceSlots, options);
        FieldToJson(jdata["precedingExternallyEncodedBytes"], data->decoded_value->precedingExternallyEncodedBytes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeCapabilityFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(VkVideoEncodeRateControlModeFlagsKHR_t(),jdata["rateControlModes"], data->decoded_value->rateControlModes, options);
        FieldToJson(jdata["maxRateControlLayers"], data->decoded_value->maxRateControlLayers, options);
        FieldToJson(jdata["maxBitrate"], data->decoded_value->maxBitrate, options);
        FieldToJson(jdata["maxQualityLevels"], data->decoded_value->maxQualityLevels, options);
        FieldToJson(jdata["encodeInputPictureGranularity"], data->encodeInputPictureGranularity, options);
        FieldToJson(VkVideoEncodeFeedbackFlagsKHR_t(),jdata["supportedEncodeFeedbackFlags"], data->decoded_value->supportedEncodeFeedbackFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeFeedbackFlagsKHR_t(),jdata["encodeFeedbackFlags"], data->decoded_value->encodeFeedbackFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeUsageInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeUsageFlagsKHR_t(),jdata["videoUsageHints"], data->decoded_value->videoUsageHints, options);
        FieldToJson(VkVideoEncodeContentFlagsKHR_t(),jdata["videoContentHints"], data->decoded_value->videoContentHints, options);
        FieldToJson(jdata["tuningMode"], data->decoded_value->tuningMode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeRateControlLayerInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["averageBitrate"], data->decoded_value->averageBitrate, options);
        FieldToJson(jdata["maxBitrate"], data->decoded_value->maxBitrate, options);
        FieldToJson(jdata["frameRateNumerator"], data->decoded_value->frameRateNumerator, options);
        FieldToJson(jdata["frameRateDenominator"], data->decoded_value->frameRateDenominator, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeRateControlInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeRateControlFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["rateControlMode"], data->decoded_value->rateControlMode, options);
        FieldToJson(jdata["layerCount"], data->decoded_value->layerCount, options);
        FieldToJson(jdata["pLayers"], data->pLayers, options);
        FieldToJson(jdata["virtualBufferSizeInMs"], data->decoded_value->virtualBufferSizeInMs, options);
        FieldToJson(jdata["initialVirtualBufferSizeInMs"], data->decoded_value->initialVirtualBufferSizeInMs, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVideoEncodeQualityLevelInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pVideoProfile"], data->pVideoProfile, options);
        FieldToJson(jdata["qualityLevel"], data->decoded_value->qualityLevel, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeQualityLevelPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["preferredRateControlMode"], data->decoded_value->preferredRateControlMode, options);
        FieldToJson(jdata["preferredRateControlLayerCount"], data->decoded_value->preferredRateControlLayerCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeQualityLevelInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["qualityLevel"], data->decoded_value->qualityLevel, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeSessionParametersGetInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["videoSessionParameters"], data->videoSessionParameters, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeSessionParametersFeedbackInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["hasOverrides"] = static_cast<bool>(data->decoded_value->hasOverrides);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShaderBarycentricFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["fragmentShaderBarycentric"] = static_cast<bool>(data->decoded_value->fragmentShaderBarycentric);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShaderBarycentricPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["triStripVertexOrderIndependentOfProvokingVertex"] = static_cast<bool>(data->decoded_value->triStripVertexOrderIndependentOfProvokingVertex);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderSubgroupUniformControlFlow"] = static_cast<bool>(data->decoded_value->shaderSubgroupUniformControlFlow);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["workgroupMemoryExplicitLayout"] = static_cast<bool>(data->decoded_value->workgroupMemoryExplicitLayout);
        jdata["workgroupMemoryExplicitLayoutScalarBlockLayout"] = static_cast<bool>(data->decoded_value->workgroupMemoryExplicitLayoutScalarBlockLayout);
        jdata["workgroupMemoryExplicitLayout8BitAccess"] = static_cast<bool>(data->decoded_value->workgroupMemoryExplicitLayout8BitAccess);
        jdata["workgroupMemoryExplicitLayout16BitAccess"] = static_cast<bool>(data->decoded_value->workgroupMemoryExplicitLayout16BitAccess);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["rayTracingMaintenance1"] = static_cast<bool>(data->decoded_value->rayTracingMaintenance1);
        jdata["rayTracingPipelineTraceRaysIndirect2"] = static_cast<bool>(data->decoded_value->rayTracingPipelineTraceRaysIndirect2);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTraceRaysIndirectCommand2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["raygenShaderRecordAddress"], to_hex_variable_width(data->decoded_value->raygenShaderRecordAddress), options);
        FieldToJson(jdata["raygenShaderRecordSize"], data->decoded_value->raygenShaderRecordSize, options);
        FieldToJson(jdata["missShaderBindingTableAddress"], to_hex_variable_width(data->decoded_value->missShaderBindingTableAddress), options);
        FieldToJson(jdata["missShaderBindingTableSize"], data->decoded_value->missShaderBindingTableSize, options);
        FieldToJson(jdata["missShaderBindingTableStride"], data->decoded_value->missShaderBindingTableStride, options);
        FieldToJson(jdata["hitShaderBindingTableAddress"], to_hex_variable_width(data->decoded_value->hitShaderBindingTableAddress), options);
        FieldToJson(jdata["hitShaderBindingTableSize"], data->decoded_value->hitShaderBindingTableSize, options);
        FieldToJson(jdata["hitShaderBindingTableStride"], data->decoded_value->hitShaderBindingTableStride, options);
        FieldToJson(jdata["callableShaderBindingTableAddress"], to_hex_variable_width(data->decoded_value->callableShaderBindingTableAddress), options);
        FieldToJson(jdata["callableShaderBindingTableSize"], data->decoded_value->callableShaderBindingTableSize, options);
        FieldToJson(jdata["callableShaderBindingTableStride"], data->decoded_value->callableShaderBindingTableStride, options);
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["depth"], data->decoded_value->depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderUntypedPointers"] = static_cast<bool>(data->decoded_value->shaderUntypedPointers);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderMaximalReconvergence"] = static_cast<bool>(data->decoded_value->shaderMaximalReconvergence);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilitiesPresentId2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentId2Supported"] = static_cast<bool>(data->decoded_value->presentId2Supported);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentId2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["swapchainCount"], data->decoded_value->swapchainCount, options);
        FieldToJson(jdata["pPresentIds"], data->pPresentIds, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePresentId2FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentId2"] = static_cast<bool>(data->decoded_value->presentId2);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilitiesPresentWait2KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentWait2Supported"] = static_cast<bool>(data->decoded_value->presentWait2Supported);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePresentWait2FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentWait2"] = static_cast<bool>(data->decoded_value->presentWait2);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentWait2InfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["presentId"], data->decoded_value->presentId, options);
        FieldToJson(jdata["timeout"], data->decoded_value->timeout, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["rayTracingPositionFetch"] = static_cast<bool>(data->decoded_value->rayTracingPositionFetch);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineBinaryFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pipelineBinaries"] = static_cast<bool>(data->decoded_value->pipelineBinaries);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineBinaryPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pipelineBinaryInternalCache"] = static_cast<bool>(data->decoded_value->pipelineBinaryInternalCache);
        jdata["pipelineBinaryInternalCacheControl"] = static_cast<bool>(data->decoded_value->pipelineBinaryInternalCacheControl);
        jdata["pipelineBinaryPrefersInternalCache"] = static_cast<bool>(data->decoded_value->pipelineBinaryPrefersInternalCache);
        jdata["pipelineBinaryPrecompiledInternalCache"] = static_cast<bool>(data->decoded_value->pipelineBinaryPrecompiledInternalCache);
        jdata["pipelineBinaryCompressedData"] = static_cast<bool>(data->decoded_value->pipelineBinaryCompressedData);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDevicePipelineBinaryInternalCacheControlKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["disableInternalCache"] = static_cast<bool>(data->decoded_value->disableInternalCache);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineBinaryKeyKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["keySize"], data->decoded_value->keySize, options);
        FieldToJson(jdata["key"], &data->key, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineBinaryDataKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["dataSize"], data->decoded_value->dataSize, options);
        FieldToJson(jdata["pData"], data->pData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineBinaryKeysAndDataKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["binaryCount"], data->decoded_value->binaryCount, options);
        FieldToJson(jdata["pPipelineBinaryKeys"], data->pPipelineBinaryKeys, options);
        FieldToJson(jdata["pPipelineBinaryData"], data->pPipelineBinaryData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineBinaryCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pKeysAndDataInfo"], data->pKeysAndDataInfo, options);
        HandleToJson(jdata["pipeline"], data->pipeline, options);
        FieldToJson(jdata["pPipelineCreateInfo"], data->pPipelineCreateInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineBinaryInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["binaryCount"], data->decoded_value->binaryCount, options);
        HandleToJson(jdata["pPipelineBinaries"], &data->pPipelineBinaries, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkReleaseCapturedPipelineDataInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["pipeline"], data->pipeline, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineBinaryDataInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["pipelineBinary"], data->pipelineBinary, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineBinaryHandlesInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pipelineBinaryCount"], data->decoded_value->pipelineBinaryCount, options);
        HandleToJson(jdata["pPipelineBinaries"], &data->pPipelineBinaries, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfacePresentModeKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["presentMode"], data->decoded_value->presentMode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfacePresentScalingCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPresentScalingFlagsKHR_t(),jdata["supportedPresentScaling"], data->decoded_value->supportedPresentScaling, options);
        FieldToJson(VkPresentGravityFlagsKHR_t(),jdata["supportedPresentGravityX"], data->decoded_value->supportedPresentGravityX, options);
        FieldToJson(VkPresentGravityFlagsKHR_t(),jdata["supportedPresentGravityY"], data->decoded_value->supportedPresentGravityY, options);
        FieldToJson(jdata["minScaledImageExtent"], data->minScaledImageExtent, options);
        FieldToJson(jdata["maxScaledImageExtent"], data->maxScaledImageExtent, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfacePresentModeCompatibilityKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["presentModeCount"], data->decoded_value->presentModeCount, options);
        FieldToJson(jdata["pPresentModes"], data->pPresentModes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["swapchainMaintenance1"] = static_cast<bool>(data->decoded_value->swapchainMaintenance1);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainPresentFenceInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["swapchainCount"], data->decoded_value->swapchainCount, options);
        HandleToJson(jdata["pFences"], &data->pFences, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainPresentModesCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["presentModeCount"], data->decoded_value->presentModeCount, options);
        FieldToJson(jdata["pPresentModes"], data->pPresentModes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainPresentModeInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["swapchainCount"], data->decoded_value->swapchainCount, options);
        FieldToJson(jdata["pPresentModes"], data->pPresentModes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainPresentScalingCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPresentScalingFlagsKHR_t(),jdata["scalingBehavior"], data->decoded_value->scalingBehavior, options);
        FieldToJson(VkPresentGravityFlagsKHR_t(),jdata["presentGravityX"], data->decoded_value->presentGravityX, options);
        FieldToJson(VkPresentGravityFlagsKHR_t(),jdata["presentGravityY"], data->decoded_value->presentGravityY, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkReleaseSwapchainImagesInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["swapchain"], data->swapchain, options);
        FieldToJson(jdata["imageIndexCount"], data->decoded_value->imageIndexCount, options);
        FieldToJson(jdata["pImageIndices"], data->pImageIndices, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCooperativeMatrixPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["MSize"], data->decoded_value->MSize, options);
        FieldToJson(jdata["NSize"], data->decoded_value->NSize, options);
        FieldToJson(jdata["KSize"], data->decoded_value->KSize, options);
        FieldToJson(jdata["AType"], data->decoded_value->AType, options);
        FieldToJson(jdata["BType"], data->decoded_value->BType, options);
        FieldToJson(jdata["CType"], data->decoded_value->CType, options);
        FieldToJson(jdata["ResultType"], data->decoded_value->ResultType, options);
        jdata["saturatingAccumulation"] = static_cast<bool>(data->decoded_value->saturatingAccumulation);
        FieldToJson(jdata["scope"], data->decoded_value->scope, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["cooperativeMatrix"] = static_cast<bool>(data->decoded_value->cooperativeMatrix);
        jdata["cooperativeMatrixRobustBufferAccess"] = static_cast<bool>(data->decoded_value->cooperativeMatrixRobustBufferAccess);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["cooperativeMatrixSupportedStages"], data->decoded_value->cooperativeMatrixSupportedStages, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["computeDerivativeGroupQuads"] = static_cast<bool>(data->decoded_value->computeDerivativeGroupQuads);
        jdata["computeDerivativeGroupLinear"] = static_cast<bool>(data->decoded_value->computeDerivativeGroupLinear);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["meshAndTaskShaderDerivatives"] = static_cast<bool>(data->decoded_value->meshAndTaskShaderDerivatives);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeAV1ProfileInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stdProfile"], data->decoded_value->stdProfile, options);
        jdata["filmGrainSupport"] = static_cast<bool>(data->decoded_value->filmGrainSupport);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeAV1CapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxLevel"], data->decoded_value->maxLevel, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pStdSequenceHeader"], data->pStdSequenceHeader, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeAV1PictureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pStdPictureInfo"], data->pStdPictureInfo, options);
        FieldToJson(jdata["referenceNameSlotIndices"], &data->referenceNameSlotIndices, options);
        FieldToJson(jdata["frameHeaderOffset"], data->decoded_value->frameHeaderOffset, options);
        FieldToJson(jdata["tileCount"], data->decoded_value->tileCount, options);
        FieldToJson(jdata["pTileOffsets"], data->pTileOffsets, options);
        FieldToJson(jdata["pTileSizes"], data->pTileSizes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeAV1DpbSlotInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pStdReferenceInfo"], data->pStdReferenceInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["videoEncodeAV1"] = static_cast<bool>(data->decoded_value->videoEncodeAV1);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1CapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeAV1CapabilityFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["maxLevel"], data->decoded_value->maxLevel, options);
        FieldToJson(jdata["codedPictureAlignment"], data->codedPictureAlignment, options);
        FieldToJson(jdata["maxTiles"], data->maxTiles, options);
        FieldToJson(jdata["minTileSize"], data->minTileSize, options);
        FieldToJson(jdata["maxTileSize"], data->maxTileSize, options);
        FieldToJson(VkVideoEncodeAV1SuperblockSizeFlagsKHR_t(),jdata["superblockSizes"], data->decoded_value->superblockSizes, options);
        FieldToJson(jdata["maxSingleReferenceCount"], data->decoded_value->maxSingleReferenceCount, options);
        FieldToJson(jdata["singleReferenceNameMask"], data->decoded_value->singleReferenceNameMask, options);
        FieldToJson(jdata["maxUnidirectionalCompoundReferenceCount"], data->decoded_value->maxUnidirectionalCompoundReferenceCount, options);
        FieldToJson(jdata["maxUnidirectionalCompoundGroup1ReferenceCount"], data->decoded_value->maxUnidirectionalCompoundGroup1ReferenceCount, options);
        FieldToJson(jdata["unidirectionalCompoundReferenceNameMask"], data->decoded_value->unidirectionalCompoundReferenceNameMask, options);
        FieldToJson(jdata["maxBidirectionalCompoundReferenceCount"], data->decoded_value->maxBidirectionalCompoundReferenceCount, options);
        FieldToJson(jdata["maxBidirectionalCompoundGroup1ReferenceCount"], data->decoded_value->maxBidirectionalCompoundGroup1ReferenceCount, options);
        FieldToJson(jdata["maxBidirectionalCompoundGroup2ReferenceCount"], data->decoded_value->maxBidirectionalCompoundGroup2ReferenceCount, options);
        FieldToJson(jdata["bidirectionalCompoundReferenceNameMask"], data->decoded_value->bidirectionalCompoundReferenceNameMask, options);
        FieldToJson(jdata["maxTemporalLayerCount"], data->decoded_value->maxTemporalLayerCount, options);
        FieldToJson(jdata["maxSpatialLayerCount"], data->decoded_value->maxSpatialLayerCount, options);
        FieldToJson(jdata["maxOperatingPoints"], data->decoded_value->maxOperatingPoints, options);
        FieldToJson(jdata["minQIndex"], data->decoded_value->minQIndex, options);
        FieldToJson(jdata["maxQIndex"], data->decoded_value->maxQIndex, options);
        jdata["prefersGopRemainingFrames"] = static_cast<bool>(data->decoded_value->prefersGopRemainingFrames);
        jdata["requiresGopRemainingFrames"] = static_cast<bool>(data->decoded_value->requiresGopRemainingFrames);
        FieldToJson(VkVideoEncodeAV1StdFlagsKHR_t(),jdata["stdSyntaxFlags"], data->decoded_value->stdSyntaxFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1QIndexKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["intraQIndex"], data->decoded_value->intraQIndex, options);
        FieldToJson(jdata["predictiveQIndex"], data->decoded_value->predictiveQIndex, options);
        FieldToJson(jdata["bipredictiveQIndex"], data->decoded_value->bipredictiveQIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1QualityLevelPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeAV1RateControlFlagsKHR_t(),jdata["preferredRateControlFlags"], data->decoded_value->preferredRateControlFlags, options);
        FieldToJson(jdata["preferredGopFrameCount"], data->decoded_value->preferredGopFrameCount, options);
        FieldToJson(jdata["preferredKeyFramePeriod"], data->decoded_value->preferredKeyFramePeriod, options);
        FieldToJson(jdata["preferredConsecutiveBipredictiveFrameCount"], data->decoded_value->preferredConsecutiveBipredictiveFrameCount, options);
        FieldToJson(jdata["preferredTemporalLayerCount"], data->decoded_value->preferredTemporalLayerCount, options);
        FieldToJson(jdata["preferredConstantQIndex"], data->preferredConstantQIndex, options);
        FieldToJson(jdata["preferredMaxSingleReferenceCount"], data->decoded_value->preferredMaxSingleReferenceCount, options);
        FieldToJson(jdata["preferredSingleReferenceNameMask"], data->decoded_value->preferredSingleReferenceNameMask, options);
        FieldToJson(jdata["preferredMaxUnidirectionalCompoundReferenceCount"], data->decoded_value->preferredMaxUnidirectionalCompoundReferenceCount, options);
        FieldToJson(jdata["preferredMaxUnidirectionalCompoundGroup1ReferenceCount"], data->decoded_value->preferredMaxUnidirectionalCompoundGroup1ReferenceCount, options);
        FieldToJson(jdata["preferredUnidirectionalCompoundReferenceNameMask"], data->decoded_value->preferredUnidirectionalCompoundReferenceNameMask, options);
        FieldToJson(jdata["preferredMaxBidirectionalCompoundReferenceCount"], data->decoded_value->preferredMaxBidirectionalCompoundReferenceCount, options);
        FieldToJson(jdata["preferredMaxBidirectionalCompoundGroup1ReferenceCount"], data->decoded_value->preferredMaxBidirectionalCompoundGroup1ReferenceCount, options);
        FieldToJson(jdata["preferredMaxBidirectionalCompoundGroup2ReferenceCount"], data->decoded_value->preferredMaxBidirectionalCompoundGroup2ReferenceCount, options);
        FieldToJson(jdata["preferredBidirectionalCompoundReferenceNameMask"], data->decoded_value->preferredBidirectionalCompoundReferenceNameMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1SessionCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["useMaxLevel"] = static_cast<bool>(data->decoded_value->useMaxLevel);
        FieldToJson(jdata["maxLevel"], data->decoded_value->maxLevel, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1SessionParametersCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pStdSequenceHeader"], data->pStdSequenceHeader, options);
        FieldToJson(jdata["pStdDecoderModelInfo"], data->pStdDecoderModelInfo, options);
        FieldToJson(jdata["stdOperatingPointCount"], data->decoded_value->stdOperatingPointCount, options);
        FieldToJson(jdata["pStdOperatingPoints"], data->pStdOperatingPoints, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1PictureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["predictionMode"], data->decoded_value->predictionMode, options);
        FieldToJson(jdata["rateControlGroup"], data->decoded_value->rateControlGroup, options);
        FieldToJson(jdata["constantQIndex"], data->decoded_value->constantQIndex, options);
        FieldToJson(jdata["pStdPictureInfo"], data->pStdPictureInfo, options);
        FieldToJson(jdata["referenceNameSlotIndices"], &data->referenceNameSlotIndices, options);
        jdata["primaryReferenceCdfOnly"] = static_cast<bool>(data->decoded_value->primaryReferenceCdfOnly);
        jdata["generateObuExtensionHeader"] = static_cast<bool>(data->decoded_value->generateObuExtensionHeader);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1DpbSlotInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pStdReferenceInfo"], data->pStdReferenceInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1ProfileInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stdProfile"], data->decoded_value->stdProfile, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1FrameSizeKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["intraFrameSize"], data->decoded_value->intraFrameSize, options);
        FieldToJson(jdata["predictiveFrameSize"], data->decoded_value->predictiveFrameSize, options);
        FieldToJson(jdata["bipredictiveFrameSize"], data->decoded_value->bipredictiveFrameSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1GopRemainingFrameInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["useGopRemainingFrames"] = static_cast<bool>(data->decoded_value->useGopRemainingFrames);
        FieldToJson(jdata["gopRemainingIntra"], data->decoded_value->gopRemainingIntra, options);
        FieldToJson(jdata["gopRemainingPredictive"], data->decoded_value->gopRemainingPredictive, options);
        FieldToJson(jdata["gopRemainingBipredictive"], data->decoded_value->gopRemainingBipredictive, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1RateControlInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeAV1RateControlFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["gopFrameCount"], data->decoded_value->gopFrameCount, options);
        FieldToJson(jdata["keyFramePeriod"], data->decoded_value->keyFramePeriod, options);
        FieldToJson(jdata["consecutiveBipredictiveFrameCount"], data->decoded_value->consecutiveBipredictiveFrameCount, options);
        FieldToJson(jdata["temporalLayerCount"], data->decoded_value->temporalLayerCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1RateControlLayerInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["useMinQIndex"] = static_cast<bool>(data->decoded_value->useMinQIndex);
        FieldToJson(jdata["minQIndex"], data->minQIndex, options);
        jdata["useMaxQIndex"] = static_cast<bool>(data->decoded_value->useMaxQIndex);
        FieldToJson(jdata["maxQIndex"], data->maxQIndex, options);
        jdata["useMaxFrameSize"] = static_cast<bool>(data->decoded_value->useMaxFrameSize);
        FieldToJson(jdata["maxFrameSize"], data->maxFrameSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["videoDecodeVP9"] = static_cast<bool>(data->decoded_value->videoDecodeVP9);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeVP9ProfileInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stdProfile"], data->decoded_value->stdProfile, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeVP9CapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxLevel"], data->decoded_value->maxLevel, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoDecodeVP9PictureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pStdPictureInfo"], data->pStdPictureInfo, options);
        FieldToJson(jdata["referenceNameSlotIndices"], &data->referenceNameSlotIndices, options);
        FieldToJson(jdata["uncompressedHeaderOffset"], data->decoded_value->uncompressedHeaderOffset, options);
        FieldToJson(jdata["compressedHeaderOffset"], data->decoded_value->compressedHeaderOffset, options);
        FieldToJson(jdata["tilesOffset"], data->decoded_value->tilesOffset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["videoMaintenance1"] = static_cast<bool>(data->decoded_value->videoMaintenance1);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoInlineQueryInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["queryPool"], data->queryPool, options);
        FieldToJson(jdata["firstQuery"], data->decoded_value->firstQuery, options);
        FieldToJson(jdata["queryCount"], data->decoded_value->queryCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["unifiedImageLayouts"] = static_cast<bool>(data->decoded_value->unifiedImageLayouts);
        jdata["unifiedImageLayoutsVideo"] = static_cast<bool>(data->decoded_value->unifiedImageLayoutsVideo);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentFeedbackLoopInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["feedbackLoopEnable"] = static_cast<bool>(data->decoded_value->feedbackLoopEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCalibratedTimestampInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["timeDomain"], data->decoded_value->timeDomain, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSetDescriptorBufferOffsetsInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["stageFlags"], data->decoded_value->stageFlags, options);
        HandleToJson(jdata["layout"], data->layout, options);
        FieldToJson(jdata["firstSet"], data->decoded_value->firstSet, options);
        FieldToJson(jdata["setCount"], data->decoded_value->setCount, options);
        FieldToJson(jdata["pBufferIndices"], data->pBufferIndices, options);
        FieldToJson(jdata["pOffsets"], data->pOffsets, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindDescriptorBufferEmbeddedSamplersInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["stageFlags"], data->decoded_value->stageFlags, options);
        HandleToJson(jdata["layout"], data->layout, options);
        FieldToJson(jdata["set"], data->decoded_value->set, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkStridedDeviceAddressRangeKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["address"], to_hex_variable_width(data->decoded_value->address), options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["stride"], data->decoded_value->stride, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMemoryIndirectCommandKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["srcAddress"], to_hex_variable_width(data->decoded_value->srcAddress), options);
        FieldToJson(jdata["dstAddress"], to_hex_variable_width(data->decoded_value->dstAddress), options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMemoryIndirectInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkAddressCopyFlagsKHR_t(),jdata["srcCopyFlags"], data->decoded_value->srcCopyFlags, options);
        FieldToJson(VkAddressCopyFlagsKHR_t(),jdata["dstCopyFlags"], data->decoded_value->dstCopyFlags, options);
        FieldToJson(jdata["copyCount"], data->decoded_value->copyCount, options);
        FieldToJson(jdata["copyAddressRange"], data->copyAddressRange, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMemoryToImageIndirectCommandKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["srcAddress"], to_hex_variable_width(data->decoded_value->srcAddress), options);
        FieldToJson(jdata["bufferRowLength"], data->decoded_value->bufferRowLength, options);
        FieldToJson(jdata["bufferImageHeight"], data->decoded_value->bufferImageHeight, options);
        FieldToJson(jdata["imageSubresource"], data->imageSubresource, options);
        FieldToJson(jdata["imageOffset"], data->imageOffset, options);
        FieldToJson(jdata["imageExtent"], data->imageExtent, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMemoryToImageIndirectInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkAddressCopyFlagsKHR_t(),jdata["srcCopyFlags"], data->decoded_value->srcCopyFlags, options);
        FieldToJson(jdata["copyCount"], data->decoded_value->copyCount, options);
        FieldToJson(jdata["copyAddressRange"], data->copyAddressRange, options);
        HandleToJson(jdata["dstImage"], data->dstImage, options);
        FieldToJson(jdata["dstImageLayout"], data->decoded_value->dstImageLayout, options);
        FieldToJson(jdata["pImageSubresources"], data->pImageSubresources, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["indirectMemoryCopy"] = static_cast<bool>(data->decoded_value->indirectMemoryCopy);
        jdata["indirectMemoryToImageCopy"] = static_cast<bool>(data->decoded_value->indirectMemoryToImageCopy);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkQueueFlags_t(),jdata["supportedQueues"], data->decoded_value->supportedQueues, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeIntraRefreshCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeIntraRefreshModeFlagsKHR_t(),jdata["intraRefreshModes"], data->decoded_value->intraRefreshModes, options);
        FieldToJson(jdata["maxIntraRefreshCycleDuration"], data->decoded_value->maxIntraRefreshCycleDuration, options);
        FieldToJson(jdata["maxIntraRefreshActiveReferencePictures"], data->decoded_value->maxIntraRefreshActiveReferencePictures, options);
        jdata["partitionIndependentIntraRefreshRegions"] = static_cast<bool>(data->decoded_value->partitionIndependentIntraRefreshRegions);
        jdata["nonRectangularIntraRefreshRegions"] = static_cast<bool>(data->decoded_value->nonRectangularIntraRefreshRegions);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeSessionIntraRefreshCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["intraRefreshMode"], data->decoded_value->intraRefreshMode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeIntraRefreshInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["intraRefreshCycleDuration"], data->decoded_value->intraRefreshCycleDuration, options);
        FieldToJson(jdata["intraRefreshIndex"], data->decoded_value->intraRefreshIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoReferenceIntraRefreshInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["dirtyIntraRefreshRegions"], data->decoded_value->dirtyIntraRefreshRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["videoEncodeIntraRefresh"] = static_cast<bool>(data->decoded_value->videoEncodeIntraRefresh);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeQuantizationMapCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxQuantizationMapExtent"], data->maxQuantizationMapExtent, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoFormatQuantizationMapPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["quantizationMapTexelSize"], data->quantizationMapTexelSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeQuantizationMapInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["quantizationMap"], data->quantizationMap, options);
        FieldToJson(jdata["quantizationMapExtent"], data->quantizationMapExtent, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["quantizationMapTexelSize"], data->quantizationMapTexelSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["videoEncodeQuantizationMap"] = static_cast<bool>(data->decoded_value->videoEncodeQuantizationMap);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH264QuantizationMapCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minQpDelta"], data->decoded_value->minQpDelta, options);
        FieldToJson(jdata["maxQpDelta"], data->decoded_value->maxQpDelta, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeH265QuantizationMapCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minQpDelta"], data->decoded_value->minQpDelta, options);
        FieldToJson(jdata["maxQpDelta"], data->decoded_value->maxQpDelta, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoFormatH265QuantizationMapPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeH265CtbSizeFlagsKHR_t(),jdata["compatibleCtbSizes"], data->decoded_value->compatibleCtbSizes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minQIndexDelta"], data->decoded_value->minQIndexDelta, options);
        FieldToJson(jdata["maxQIndexDelta"], data->decoded_value->maxQIndexDelta, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoFormatAV1QuantizationMapPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeAV1SuperblockSizeFlagsKHR_t(),jdata["compatibleSuperblockSizes"], data->decoded_value->compatibleSuperblockSizes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderRelaxedExtendedInstruction"] = static_cast<bool>(data->decoded_value->shaderRelaxedExtendedInstruction);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance7FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["maintenance7"] = static_cast<bool>(data->decoded_value->maintenance7);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance7PropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["robustFragmentShadingRateAttachmentAccess"] = static_cast<bool>(data->decoded_value->robustFragmentShadingRateAttachmentAccess);
        jdata["separateDepthStencilAttachmentAccess"] = static_cast<bool>(data->decoded_value->separateDepthStencilAttachmentAccess);
        FieldToJson(jdata["maxDescriptorSetTotalUniformBuffersDynamic"], data->decoded_value->maxDescriptorSetTotalUniformBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetTotalStorageBuffersDynamic"], data->decoded_value->maxDescriptorSetTotalStorageBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetTotalBuffersDynamic"], data->decoded_value->maxDescriptorSetTotalBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic"], data->decoded_value->maxDescriptorSetUpdateAfterBindTotalUniformBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic"], data->decoded_value->maxDescriptorSetUpdateAfterBindTotalStorageBuffersDynamic, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindTotalBuffersDynamic"], data->decoded_value->maxDescriptorSetUpdateAfterBindTotalBuffersDynamic, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLayeredApiPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["vendorID"], data->decoded_value->vendorID, options);
        FieldToJson(jdata["deviceID"], data->decoded_value->deviceID, options);
        FieldToJson(jdata["layeredAPI"], data->decoded_value->layeredAPI, options);
        FieldToJson(jdata["deviceName"], &data->deviceName, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLayeredApiPropertiesListKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["layeredApiCount"], data->decoded_value->layeredApiCount, options);
        FieldToJson(jdata["pLayeredApis"], data->pLayeredApis, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["properties"], data->properties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryBarrierAccessFlags3KHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkAccessFlags3KHR_t(),jdata["srcAccessMask3"], data->decoded_value->srcAccessMask3, options);
        FieldToJson(VkAccessFlags3KHR_t(),jdata["dstAccessMask3"], data->decoded_value->dstAccessMask3, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance8FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["maintenance8"] = static_cast<bool>(data->decoded_value->maintenance8);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderFmaFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderFmaFloat16"] = static_cast<bool>(data->decoded_value->shaderFmaFloat16);
        jdata["shaderFmaFloat32"] = static_cast<bool>(data->decoded_value->shaderFmaFloat32);
        jdata["shaderFmaFloat64"] = static_cast<bool>(data->decoded_value->shaderFmaFloat64);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance9FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["maintenance9"] = static_cast<bool>(data->decoded_value->maintenance9);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance9PropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["image2DViewOf3DSparse"] = static_cast<bool>(data->decoded_value->image2DViewOf3DSparse);
        FieldToJson(jdata["defaultVertexAttributeValue"], data->decoded_value->defaultVertexAttributeValue, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyOwnershipTransferPropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["optimalImageTransferToQueueFamilies"], data->decoded_value->optimalImageTransferToQueueFamilies, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["depthClampZeroOne"] = static_cast<bool>(data->decoded_value->depthClampZeroOne);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRobustness2FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["robustBufferAccess2"] = static_cast<bool>(data->decoded_value->robustBufferAccess2);
        jdata["robustImageAccess2"] = static_cast<bool>(data->decoded_value->robustImageAccess2);
        jdata["nullDescriptor"] = static_cast<bool>(data->decoded_value->nullDescriptor);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRobustness2PropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["robustStorageBufferAccessSizeAlignment"], data->decoded_value->robustStorageBufferAccessSizeAlignment, options);
        FieldToJson(jdata["robustUniformBufferAccessSizeAlignment"], data->decoded_value->robustUniformBufferAccessSizeAlignment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentModeFifoLatestReady"] = static_cast<bool>(data->decoded_value->presentModeFifoLatestReady);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance10FeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["maintenance10"] = static_cast<bool>(data->decoded_value->maintenance10);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMaintenance10PropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["rgba4OpaqueBlackSwizzled"] = static_cast<bool>(data->decoded_value->rgba4OpaqueBlackSwizzled);
        jdata["resolveSrgbFormatAppliesTransferFunction"] = static_cast<bool>(data->decoded_value->resolveSrgbFormatAppliesTransferFunction);
        jdata["resolveSrgbFormatSupportsTransferFunctionControl"] = static_cast<bool>(data->decoded_value->resolveSrgbFormatSupportsTransferFunctionControl);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingEndInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingAttachmentFlagsInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkRenderingAttachmentFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkResolveImageModeInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkResolveImageFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["resolveMode"], data->decoded_value->resolveMode, options);
        FieldToJson(jdata["stencilResolveMode"], data->decoded_value->stencilResolveMode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugReportCallbackCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDebugReportFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pfnCallback"], to_hex_variable_width(data->pfnCallback), options);
        FieldToJson(jdata["pUserData"], to_hex_variable_width(data->pUserData), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationStateRasterizationOrderAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["rasterizationOrder"], data->decoded_value->rasterizationOrder, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugMarkerObjectNameInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["objectType"], data->decoded_value->objectType, options);
        FieldToJson(jdata["object"], data->decoded_value->object, options);
        FieldToJson(jdata["pObjectName"], &data->pObjectName, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugMarkerObjectTagInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["objectType"], data->decoded_value->objectType, options);
        FieldToJson(jdata["object"], data->decoded_value->object, options);
        FieldToJson(jdata["tagName"], data->decoded_value->tagName, options);
        FieldToJson(jdata["tagSize"], data->decoded_value->tagSize, options);
        FieldToJson(jdata["pTag"], data->pTag, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugMarkerMarkerInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pMarkerName"], &data->pMarkerName, options);
        FieldToJson(jdata["color"], &data->color, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDedicatedAllocationImageCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["dedicatedAllocation"] = static_cast<bool>(data->decoded_value->dedicatedAllocation);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDedicatedAllocationBufferCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["dedicatedAllocation"] = static_cast<bool>(data->decoded_value->dedicatedAllocation);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDedicatedAllocationMemoryAllocateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["image"], data->image, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTransformFeedbackFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["transformFeedback"] = static_cast<bool>(data->decoded_value->transformFeedback);
        jdata["geometryStreams"] = static_cast<bool>(data->decoded_value->geometryStreams);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTransformFeedbackPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxTransformFeedbackStreams"], data->decoded_value->maxTransformFeedbackStreams, options);
        FieldToJson(jdata["maxTransformFeedbackBuffers"], data->decoded_value->maxTransformFeedbackBuffers, options);
        FieldToJson(jdata["maxTransformFeedbackBufferSize"], data->decoded_value->maxTransformFeedbackBufferSize, options);
        FieldToJson(jdata["maxTransformFeedbackStreamDataSize"], data->decoded_value->maxTransformFeedbackStreamDataSize, options);
        FieldToJson(jdata["maxTransformFeedbackBufferDataSize"], data->decoded_value->maxTransformFeedbackBufferDataSize, options);
        FieldToJson(jdata["maxTransformFeedbackBufferDataStride"], data->decoded_value->maxTransformFeedbackBufferDataStride, options);
        jdata["transformFeedbackQueries"] = static_cast<bool>(data->decoded_value->transformFeedbackQueries);
        jdata["transformFeedbackStreamsLinesTriangles"] = static_cast<bool>(data->decoded_value->transformFeedbackStreamsLinesTriangles);
        jdata["transformFeedbackRasterizationStreamSelect"] = static_cast<bool>(data->decoded_value->transformFeedbackRasterizationStreamSelect);
        jdata["transformFeedbackDraw"] = static_cast<bool>(data->decoded_value->transformFeedbackDraw);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineRasterizationStateStreamCreateFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["rasterizationStream"], data->decoded_value->rasterizationStream, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewHandleInfoNVX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["imageView"], data->imageView, options);
        FieldToJson(jdata["descriptorType"], data->decoded_value->descriptorType, options);
        HandleToJson(jdata["sampler"], data->sampler, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewAddressPropertiesNVX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["deviceAddress"], to_hex_variable_width(data->decoded_value->deviceAddress), options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTextureLODGatherFormatPropertiesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["supportsTextureGatherLODBiasAMD"] = static_cast<bool>(data->decoded_value->supportsTextureGatherLODBiasAMD);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShaderResourceUsageAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["numUsedVgprs"], data->decoded_value->numUsedVgprs, options);
        FieldToJson(jdata["numUsedSgprs"], data->decoded_value->numUsedSgprs, options);
        FieldToJson(jdata["ldsSizePerLocalWorkGroup"], data->decoded_value->ldsSizePerLocalWorkGroup, options);
        FieldToJson(jdata["ldsUsageSizeInBytes"], data->decoded_value->ldsUsageSizeInBytes, options);
        FieldToJson(jdata["scratchMemUsageInBytes"], data->decoded_value->scratchMemUsageInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShaderStatisticsInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(VkShaderStageFlags_t(),jdata["shaderStageMask"], data->decoded_value->shaderStageMask, options);
        FieldToJson(jdata["resourceUsage"], data->resourceUsage, options);
        FieldToJson(jdata["numPhysicalVgprs"], data->decoded_value->numPhysicalVgprs, options);
        FieldToJson(jdata["numPhysicalSgprs"], data->decoded_value->numPhysicalSgprs, options);
        FieldToJson(jdata["numAvailableVgprs"], data->decoded_value->numAvailableVgprs, options);
        FieldToJson(jdata["numAvailableSgprs"], data->decoded_value->numAvailableSgprs, options);
        FieldToJson(jdata["computeWorkGroupSize"], &data->computeWorkGroupSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkStreamDescriptorSurfaceCreateInfoGGP* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkStreamDescriptorSurfaceCreateFlagsGGP_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["streamDescriptor"], data->decoded_value->streamDescriptor, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["cornerSampledImage"] = static_cast<bool>(data->decoded_value->cornerSampledImage);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalImageFormatPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["imageFormatProperties"], data->imageFormatProperties, options);
        FieldToJson(VkExternalMemoryFeatureFlagsNV_t(),jdata["externalMemoryFeatures"], data->decoded_value->externalMemoryFeatures, options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(),jdata["exportFromImportedHandleTypes"], data->decoded_value->exportFromImportedHandleTypes, options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(),jdata["compatibleHandleTypes"], data->decoded_value->compatibleHandleTypes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalMemoryImageCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(),jdata["handleTypes"], data->decoded_value->handleTypes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportMemoryAllocateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(),jdata["handleTypes"], data->decoded_value->handleTypes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryWin32HandleInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkExternalMemoryHandleTypeFlagsNV_t(),jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["handle"], data->handle, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExportMemoryWin32HandleInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pAttributes"], data->pAttributes, options);
        FieldToJson(jdata["dwAccess"], data->decoded_value->dwAccess, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["acquireCount"], data->decoded_value->acquireCount, options);
        HandleToJson(jdata["pAcquireSyncs"], &data->pAcquireSyncs, options);
        FieldToJson(jdata["pAcquireKeys"], data->pAcquireKeys, options);
        FieldToJson(jdata["pAcquireTimeoutMilliseconds"], data->pAcquireTimeoutMilliseconds, options);
        FieldToJson(jdata["releaseCount"], data->decoded_value->releaseCount, options);
        HandleToJson(jdata["pReleaseSyncs"], &data->pReleaseSyncs, options);
        FieldToJson(jdata["pReleaseKeys"], data->pReleaseKeys, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkValidationFlagsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["disabledValidationCheckCount"], data->decoded_value->disabledValidationCheckCount, options);
        FieldToJson(jdata["pDisabledValidationChecks"], data->pDisabledValidationChecks, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkViSurfaceCreateInfoNN* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkViSurfaceCreateFlagsNN_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["window"], data->window, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewASTCDecodeModeEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["decodeMode"], data->decoded_value->decodeMode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["decodeModeSharedExponent"] = static_cast<bool>(data->decoded_value->decodeModeSharedExponent);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkConditionalRenderingBeginInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(VkConditionalRenderingFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["conditionalRendering"] = static_cast<bool>(data->decoded_value->conditionalRendering);
        jdata["inheritedConditionalRendering"] = static_cast<bool>(data->decoded_value->inheritedConditionalRendering);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["conditionalRenderingEnable"] = static_cast<bool>(data->decoded_value->conditionalRenderingEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkViewportWScalingNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["xcoeff"], data->decoded_value->xcoeff, options);
        FieldToJson(jdata["ycoeff"], data->decoded_value->ycoeff, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportWScalingStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["viewportWScalingEnable"] = static_cast<bool>(data->decoded_value->viewportWScalingEnable);
        FieldToJson(jdata["viewportCount"], data->decoded_value->viewportCount, options);
        FieldToJson(jdata["pViewportWScalings"], data->pViewportWScalings, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilities2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minImageCount"], data->decoded_value->minImageCount, options);
        FieldToJson(jdata["maxImageCount"], data->decoded_value->maxImageCount, options);
        FieldToJson(jdata["currentExtent"], data->currentExtent, options);
        FieldToJson(jdata["minImageExtent"], data->minImageExtent, options);
        FieldToJson(jdata["maxImageExtent"], data->maxImageExtent, options);
        FieldToJson(jdata["maxImageArrayLayers"], data->decoded_value->maxImageArrayLayers, options);
        FieldToJson(VkSurfaceTransformFlagsKHR_t(),jdata["supportedTransforms"], data->decoded_value->supportedTransforms, options);
        FieldToJson(jdata["currentTransform"], data->decoded_value->currentTransform, options);
        FieldToJson(VkCompositeAlphaFlagsKHR_t(),jdata["supportedCompositeAlpha"], data->decoded_value->supportedCompositeAlpha, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["supportedUsageFlags"], data->decoded_value->supportedUsageFlags, options);
        FieldToJson(VkSurfaceCounterFlagsEXT_t(),jdata["supportedSurfaceCounters"], data->decoded_value->supportedSurfaceCounters, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayPowerInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["powerState"], data->decoded_value->powerState, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceEventInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["deviceEvent"], data->decoded_value->deviceEvent, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayEventInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["displayEvent"], data->decoded_value->displayEvent, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainCounterCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkSurfaceCounterFlagsEXT_t(),jdata["surfaceCounters"], data->decoded_value->surfaceCounters, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRefreshCycleDurationGOOGLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["refreshDuration"], data->decoded_value->refreshDuration, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPastPresentationTimingGOOGLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["presentID"], data->decoded_value->presentID, options);
        FieldToJson(jdata["desiredPresentTime"], data->decoded_value->desiredPresentTime, options);
        FieldToJson(jdata["actualPresentTime"], data->decoded_value->actualPresentTime, options);
        FieldToJson(jdata["earliestPresentTime"], data->decoded_value->earliestPresentTime, options);
        FieldToJson(jdata["presentMargin"], data->decoded_value->presentMargin, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentTimeGOOGLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["presentID"], data->decoded_value->presentID, options);
        FieldToJson(jdata["desiredPresentTime"], data->decoded_value->desiredPresentTime, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentTimesInfoGOOGLE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["swapchainCount"], data->decoded_value->swapchainCount, options);
        FieldToJson(jdata["pTimes"], data->pTimes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["perViewPositionAllComponents"] = static_cast<bool>(data->decoded_value->perViewPositionAllComponents);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultiviewPerViewAttributesInfoNVX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["perViewAttributes"] = static_cast<bool>(data->decoded_value->perViewAttributes);
        jdata["perViewAttributesPositionXOnly"] = static_cast<bool>(data->decoded_value->perViewAttributesPositionXOnly);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkViewportSwizzleNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
        FieldToJson(jdata["z"], data->decoded_value->z, options);
        FieldToJson(jdata["w"], data->decoded_value->w, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportSwizzleStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineViewportSwizzleStateCreateFlagsNV_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["viewportCount"], data->decoded_value->viewportCount, options);
        FieldToJson(jdata["pViewportSwizzles"], data->pViewportSwizzles, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxDiscardRectangles"], data->decoded_value->maxDiscardRectangles, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineDiscardRectangleStateCreateFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["discardRectangleMode"], data->decoded_value->discardRectangleMode, options);
        FieldToJson(jdata["discardRectangleCount"], data->decoded_value->discardRectangleCount, options);
        FieldToJson(jdata["pDiscardRectangles"], data->pDiscardRectangles, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["primitiveOverestimationSize"], data->decoded_value->primitiveOverestimationSize, options);
        FieldToJson(jdata["maxExtraPrimitiveOverestimationSize"], data->decoded_value->maxExtraPrimitiveOverestimationSize, options);
        FieldToJson(jdata["extraPrimitiveOverestimationSizeGranularity"], data->decoded_value->extraPrimitiveOverestimationSizeGranularity, options);
        jdata["primitiveUnderestimation"] = static_cast<bool>(data->decoded_value->primitiveUnderestimation);
        jdata["conservativePointAndLineRasterization"] = static_cast<bool>(data->decoded_value->conservativePointAndLineRasterization);
        jdata["degenerateTrianglesRasterized"] = static_cast<bool>(data->decoded_value->degenerateTrianglesRasterized);
        jdata["degenerateLinesRasterized"] = static_cast<bool>(data->decoded_value->degenerateLinesRasterized);
        jdata["fullyCoveredFragmentShaderInputVariable"] = static_cast<bool>(data->decoded_value->fullyCoveredFragmentShaderInputVariable);
        jdata["conservativeRasterizationPostDepthCoverage"] = static_cast<bool>(data->decoded_value->conservativeRasterizationPostDepthCoverage);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineRasterizationConservativeStateCreateFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["conservativeRasterizationMode"], data->decoded_value->conservativeRasterizationMode, options);
        FieldToJson(jdata["extraPrimitiveOverestimationSize"], data->decoded_value->extraPrimitiveOverestimationSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["depthClipEnable"] = static_cast<bool>(data->decoded_value->depthClipEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineRasterizationDepthClipStateCreateFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        jdata["depthClipEnable"] = static_cast<bool>(data->decoded_value->depthClipEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkXYColorEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkHdrMetadataEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["displayPrimaryRed"], data->displayPrimaryRed, options);
        FieldToJson(jdata["displayPrimaryGreen"], data->displayPrimaryGreen, options);
        FieldToJson(jdata["displayPrimaryBlue"], data->displayPrimaryBlue, options);
        FieldToJson(jdata["whitePoint"], data->whitePoint, options);
        FieldToJson(jdata["maxLuminance"], data->decoded_value->maxLuminance, options);
        FieldToJson(jdata["minLuminance"], data->decoded_value->minLuminance, options);
        FieldToJson(jdata["maxContentLightLevel"], data->decoded_value->maxContentLightLevel, options);
        FieldToJson(jdata["maxFrameAverageLightLevel"], data->decoded_value->maxFrameAverageLightLevel, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["relaxedLineRasterization"] = static_cast<bool>(data->decoded_value->relaxedLineRasterization);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIOSSurfaceCreateInfoMVK* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkIOSSurfaceCreateFlagsMVK_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pView"], data->pView, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMacOSSurfaceCreateInfoMVK* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkMacOSSurfaceCreateFlagsMVK_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pView"], data->pView, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugUtilsLabelEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pLabelName"], &data->pLabelName, options);
        FieldToJson(jdata["color"], &data->color, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugUtilsObjectNameInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["objectType"], data->decoded_value->objectType, options);
        HandleToJson(jdata["objectHandle"], data->objectHandle, options);
        FieldToJson(jdata["pObjectName"], &data->pObjectName, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugUtilsMessengerCallbackDataEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDebugUtilsMessengerCallbackDataFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pMessageIdName"], &data->pMessageIdName, options);
        FieldToJson(jdata["messageIdNumber"], data->decoded_value->messageIdNumber, options);
        FieldToJson(jdata["pMessage"], &data->pMessage, options);
        FieldToJson(jdata["queueLabelCount"], data->decoded_value->queueLabelCount, options);
        FieldToJson(jdata["pQueueLabels"], data->pQueueLabels, options);
        FieldToJson(jdata["cmdBufLabelCount"], data->decoded_value->cmdBufLabelCount, options);
        FieldToJson(jdata["pCmdBufLabels"], data->pCmdBufLabels, options);
        FieldToJson(jdata["objectCount"], data->decoded_value->objectCount, options);
        FieldToJson(jdata["pObjects"], data->pObjects, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugUtilsMessengerCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDebugUtilsMessengerCreateFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(VkDebugUtilsMessageSeverityFlagsEXT_t(),jdata["messageSeverity"], data->decoded_value->messageSeverity, options);
        FieldToJson(VkDebugUtilsMessageTypeFlagsEXT_t(),jdata["messageType"], data->decoded_value->messageType, options);
        FieldToJson(jdata["pfnUserCallback"], to_hex_variable_width(data->pfnUserCallback), options);
        FieldToJson(jdata["pUserData"], to_hex_variable_width(data->pUserData), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDebugUtilsObjectTagInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["objectType"], data->decoded_value->objectType, options);
        HandleToJson(jdata["objectHandle"], data->objectHandle, options);
        FieldToJson(jdata["tagName"], data->decoded_value->tagName, options);
        FieldToJson(jdata["tagSize"], data->decoded_value->tagSize, options);
        FieldToJson(jdata["pTag"], data->pTag, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidHardwareBufferUsageANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["androidHardwareBufferUsage"], data->decoded_value->androidHardwareBufferUsage, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidHardwareBufferPropertiesANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["allocationSize"], data->decoded_value->allocationSize, options);
        FieldToJson(jdata["memoryTypeBits"], data->decoded_value->memoryTypeBits, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["externalFormat"], data->decoded_value->externalFormat, options);
        FieldToJson(VkFormatFeatureFlags_t(),jdata["formatFeatures"], data->decoded_value->formatFeatures, options);
        FieldToJson(jdata["samplerYcbcrConversionComponents"], data->samplerYcbcrConversionComponents, options);
        FieldToJson(jdata["suggestedYcbcrModel"], data->decoded_value->suggestedYcbcrModel, options);
        FieldToJson(jdata["suggestedYcbcrRange"], data->decoded_value->suggestedYcbcrRange, options);
        FieldToJson(jdata["suggestedXChromaOffset"], data->decoded_value->suggestedXChromaOffset, options);
        FieldToJson(jdata["suggestedYChromaOffset"], data->decoded_value->suggestedYChromaOffset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportAndroidHardwareBufferInfoANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetAndroidHardwareBufferInfoANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalFormatANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["externalFormat"], data->decoded_value->externalFormat, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["externalFormat"], data->decoded_value->externalFormat, options);
        FieldToJson(VkFormatFeatureFlags2_t(),jdata["formatFeatures"], data->decoded_value->formatFeatures, options);
        FieldToJson(jdata["samplerYcbcrConversionComponents"], data->samplerYcbcrConversionComponents, options);
        FieldToJson(jdata["suggestedYcbcrModel"], data->decoded_value->suggestedYcbcrModel, options);
        FieldToJson(jdata["suggestedYcbcrRange"], data->decoded_value->suggestedYcbcrRange, options);
        FieldToJson(jdata["suggestedXChromaOffset"], data->decoded_value->suggestedXChromaOffset, options);
        FieldToJson(jdata["suggestedYChromaOffset"], data->decoded_value->suggestedYChromaOffset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentSampleCountInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["colorAttachmentCount"], data->decoded_value->colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachmentSamples"], data->pColorAttachmentSamples, options);
        FieldToJson(jdata["depthStencilAttachmentSamples"], data->decoded_value->depthStencilAttachmentSamples, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSampleLocationEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["x"], data->decoded_value->x, options);
        FieldToJson(jdata["y"], data->decoded_value->y, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSampleLocationsInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["sampleLocationsPerPixel"], data->decoded_value->sampleLocationsPerPixel, options);
        FieldToJson(jdata["sampleLocationGridSize"], data->sampleLocationGridSize, options);
        FieldToJson(jdata["sampleLocationsCount"], data->decoded_value->sampleLocationsCount, options);
        FieldToJson(jdata["pSampleLocations"], data->pSampleLocations, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAttachmentSampleLocationsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["attachmentIndex"], data->decoded_value->attachmentIndex, options);
        FieldToJson(jdata["sampleLocationsInfo"], data->sampleLocationsInfo, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassSampleLocationsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["subpassIndex"], data->decoded_value->subpassIndex, options);
        FieldToJson(jdata["sampleLocationsInfo"], data->sampleLocationsInfo, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassSampleLocationsBeginInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["attachmentInitialSampleLocationsCount"], data->decoded_value->attachmentInitialSampleLocationsCount, options);
        FieldToJson(jdata["pAttachmentInitialSampleLocations"], data->pAttachmentInitialSampleLocations, options);
        FieldToJson(jdata["postSubpassSampleLocationsCount"], data->decoded_value->postSubpassSampleLocationsCount, options);
        FieldToJson(jdata["pPostSubpassSampleLocations"], data->pPostSubpassSampleLocations, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineSampleLocationsStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["sampleLocationsEnable"] = static_cast<bool>(data->decoded_value->sampleLocationsEnable);
        FieldToJson(jdata["sampleLocationsInfo"], data->sampleLocationsInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["sampleLocationSampleCounts"], data->decoded_value->sampleLocationSampleCounts, options);
        FieldToJson(jdata["maxSampleLocationGridSize"], data->maxSampleLocationGridSize, options);
        FieldToJson(jdata["sampleLocationCoordinateRange"], &data->sampleLocationCoordinateRange, options);
        FieldToJson(jdata["sampleLocationSubPixelBits"], data->decoded_value->sampleLocationSubPixelBits, options);
        jdata["variableSampleLocations"] = static_cast<bool>(data->decoded_value->variableSampleLocations);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultisamplePropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxSampleLocationGridSize"], data->maxSampleLocationGridSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["advancedBlendCoherentOperations"] = static_cast<bool>(data->decoded_value->advancedBlendCoherentOperations);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["advancedBlendMaxColorAttachments"], data->decoded_value->advancedBlendMaxColorAttachments, options);
        jdata["advancedBlendIndependentBlend"] = static_cast<bool>(data->decoded_value->advancedBlendIndependentBlend);
        jdata["advancedBlendNonPremultipliedSrcColor"] = static_cast<bool>(data->decoded_value->advancedBlendNonPremultipliedSrcColor);
        jdata["advancedBlendNonPremultipliedDstColor"] = static_cast<bool>(data->decoded_value->advancedBlendNonPremultipliedDstColor);
        jdata["advancedBlendCorrelatedOverlap"] = static_cast<bool>(data->decoded_value->advancedBlendCorrelatedOverlap);
        jdata["advancedBlendAllOperations"] = static_cast<bool>(data->decoded_value->advancedBlendAllOperations);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["srcPremultiplied"] = static_cast<bool>(data->decoded_value->srcPremultiplied);
        jdata["dstPremultiplied"] = static_cast<bool>(data->decoded_value->dstPremultiplied);
        FieldToJson(jdata["blendOverlap"], data->decoded_value->blendOverlap, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCoverageToColorStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineCoverageToColorStateCreateFlagsNV_t(),jdata["flags"], data->decoded_value->flags, options);
        jdata["coverageToColorEnable"] = static_cast<bool>(data->decoded_value->coverageToColorEnable);
        FieldToJson(jdata["coverageToColorLocation"], data->decoded_value->coverageToColorLocation, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCoverageModulationStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineCoverageModulationStateCreateFlagsNV_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["coverageModulationMode"], data->decoded_value->coverageModulationMode, options);
        jdata["coverageModulationTableEnable"] = static_cast<bool>(data->decoded_value->coverageModulationTableEnable);
        FieldToJson(jdata["coverageModulationTableCount"], data->decoded_value->coverageModulationTableCount, options);
        FieldToJson(jdata["pCoverageModulationTable"], data->pCoverageModulationTable, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shaderSMCount"], data->decoded_value->shaderSMCount, options);
        FieldToJson(jdata["shaderWarpsPerSM"], data->decoded_value->shaderWarpsPerSM, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderSMBuiltins"] = static_cast<bool>(data->decoded_value->shaderSMBuiltins);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrmFormatModifierPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["drmFormatModifier"], data->decoded_value->drmFormatModifier, options);
        FieldToJson(jdata["drmFormatModifierPlaneCount"], data->decoded_value->drmFormatModifierPlaneCount, options);
        FieldToJson(VkFormatFeatureFlags_t(),jdata["drmFormatModifierTilingFeatures"], data->decoded_value->drmFormatModifierTilingFeatures, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrmFormatModifierPropertiesListEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["drmFormatModifierCount"], data->decoded_value->drmFormatModifierCount, options);
        FieldToJson(jdata["pDrmFormatModifierProperties"], data->pDrmFormatModifierProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["drmFormatModifier"], data->decoded_value->drmFormatModifier, options);
        FieldToJson(jdata["sharingMode"], data->decoded_value->sharingMode, options);
        FieldToJson(jdata["queueFamilyIndexCount"], data->decoded_value->queueFamilyIndexCount, options);
        FieldToJson(jdata["pQueueFamilyIndices"], data->pQueueFamilyIndices, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageDrmFormatModifierListCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["drmFormatModifierCount"], data->decoded_value->drmFormatModifierCount, options);
        FieldToJson(jdata["pDrmFormatModifiers"], data->pDrmFormatModifiers, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["drmFormatModifier"], data->decoded_value->drmFormatModifier, options);
        FieldToJson(jdata["drmFormatModifierPlaneCount"], data->decoded_value->drmFormatModifierPlaneCount, options);
        FieldToJson(jdata["pPlaneLayouts"], data->pPlaneLayouts, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageDrmFormatModifierPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["drmFormatModifier"], data->decoded_value->drmFormatModifier, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrmFormatModifierProperties2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["drmFormatModifier"], data->decoded_value->drmFormatModifier, options);
        FieldToJson(jdata["drmFormatModifierPlaneCount"], data->decoded_value->drmFormatModifierPlaneCount, options);
        FieldToJson(VkFormatFeatureFlags2_t(),jdata["drmFormatModifierTilingFeatures"], data->decoded_value->drmFormatModifierTilingFeatures, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrmFormatModifierPropertiesList2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["drmFormatModifierCount"], data->decoded_value->drmFormatModifierCount, options);
        FieldToJson(jdata["pDrmFormatModifierProperties"], data->pDrmFormatModifierProperties, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkValidationCacheCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkValidationCacheCreateFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["initialDataSize"], data->decoded_value->initialDataSize, options);
        FieldToJson(jdata["pInitialData"], data->pInitialData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShaderModuleValidationCacheCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["validationCache"], data->validationCache, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShadingRatePaletteNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["shadingRatePaletteEntryCount"], data->decoded_value->shadingRatePaletteEntryCount, options);
        FieldToJson(jdata["pShadingRatePaletteEntries"], data->pShadingRatePaletteEntries, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shadingRateImageEnable"] = static_cast<bool>(data->decoded_value->shadingRateImageEnable);
        FieldToJson(jdata["viewportCount"], data->decoded_value->viewportCount, options);
        FieldToJson(jdata["pShadingRatePalettes"], data->pShadingRatePalettes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShadingRateImageFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shadingRateImage"] = static_cast<bool>(data->decoded_value->shadingRateImage);
        jdata["shadingRateCoarseSampleOrder"] = static_cast<bool>(data->decoded_value->shadingRateCoarseSampleOrder);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShadingRateImagePropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shadingRateTexelSize"], data->shadingRateTexelSize, options);
        FieldToJson(jdata["shadingRatePaletteSize"], data->decoded_value->shadingRatePaletteSize, options);
        FieldToJson(jdata["shadingRateMaxCoarseSamples"], data->decoded_value->shadingRateMaxCoarseSamples, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCoarseSampleLocationNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pixelX"], data->decoded_value->pixelX, options);
        FieldToJson(jdata["pixelY"], data->decoded_value->pixelY, options);
        FieldToJson(jdata["sample"], data->decoded_value->sample, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCoarseSampleOrderCustomNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["shadingRate"], data->decoded_value->shadingRate, options);
        FieldToJson(jdata["sampleCount"], data->decoded_value->sampleCount, options);
        FieldToJson(jdata["sampleLocationCount"], data->decoded_value->sampleLocationCount, options);
        FieldToJson(jdata["pSampleLocations"], data->pSampleLocations, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["sampleOrderType"], data->decoded_value->sampleOrderType, options);
        FieldToJson(jdata["customSampleOrderCount"], data->decoded_value->customSampleOrderCount, options);
        FieldToJson(jdata["pCustomSampleOrders"], data->pCustomSampleOrders, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRayTracingShaderGroupCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["generalShader"], data->decoded_value->generalShader, options);
        FieldToJson(jdata["closestHitShader"], data->decoded_value->closestHitShader, options);
        FieldToJson(jdata["anyHitShader"], data->decoded_value->anyHitShader, options);
        FieldToJson(jdata["intersectionShader"], data->decoded_value->intersectionShader, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRayTracingPipelineCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["stageCount"], data->decoded_value->stageCount, options);
        FieldToJson(jdata["pStages"], data->pStages, options);
        FieldToJson(jdata["groupCount"], data->decoded_value->groupCount, options);
        FieldToJson(jdata["pGroups"], data->pGroups, options);
        FieldToJson(jdata["maxRecursionDepth"], data->decoded_value->maxRecursionDepth, options);
        HandleToJson(jdata["layout"], data->layout, options);
        HandleToJson(jdata["basePipelineHandle"], data->basePipelineHandle, options);
        FieldToJson(jdata["basePipelineIndex"], data->decoded_value->basePipelineIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeometryTrianglesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["vertexData"], data->vertexData, options);
        FieldToJson(jdata["vertexOffset"], data->decoded_value->vertexOffset, options);
        FieldToJson(jdata["vertexCount"], data->decoded_value->vertexCount, options);
        FieldToJson(jdata["vertexStride"], data->decoded_value->vertexStride, options);
        FieldToJson(jdata["vertexFormat"], data->decoded_value->vertexFormat, options);
        HandleToJson(jdata["indexData"], data->indexData, options);
        FieldToJson(jdata["indexOffset"], data->decoded_value->indexOffset, options);
        FieldToJson(jdata["indexCount"], data->decoded_value->indexCount, options);
        FieldToJson(jdata["indexType"], data->decoded_value->indexType, options);
        HandleToJson(jdata["transformData"], data->transformData, options);
        FieldToJson(jdata["transformOffset"], data->decoded_value->transformOffset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeometryAABBNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["aabbData"], data->aabbData, options);
        FieldToJson(jdata["numAABBs"], data->decoded_value->numAABBs, options);
        FieldToJson(jdata["stride"], data->decoded_value->stride, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeometryDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["triangles"], data->triangles, options);
        FieldToJson(jdata["aabbs"], data->aabbs, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeometryNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["geometryType"], data->decoded_value->geometryType, options);
        FieldToJson(jdata["geometry"], data->geometry, options);
        FieldToJson(VkGeometryFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(VkBuildAccelerationStructureFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["instanceCount"], data->decoded_value->instanceCount, options);
        FieldToJson(jdata["geometryCount"], data->decoded_value->geometryCount, options);
        FieldToJson(jdata["pGeometries"], data->pGeometries, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["compactedSize"], data->decoded_value->compactedSize, options);
        FieldToJson(jdata["info"], data->info, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindAccelerationStructureMemoryInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["accelerationStructure"], data->accelerationStructure, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["memoryOffset"], data->decoded_value->memoryOffset, options);
        FieldToJson(jdata["deviceIndexCount"], data->decoded_value->deviceIndexCount, options);
        FieldToJson(jdata["pDeviceIndices"], data->pDeviceIndices, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteDescriptorSetAccelerationStructureNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["accelerationStructureCount"], data->decoded_value->accelerationStructureCount, options);
        HandleToJson(jdata["pAccelerationStructures"], &data->pAccelerationStructures, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureMemoryRequirementsInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        HandleToJson(jdata["accelerationStructure"], data->accelerationStructure, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shaderGroupHandleSize"], data->decoded_value->shaderGroupHandleSize, options);
        FieldToJson(jdata["maxRecursionDepth"], data->decoded_value->maxRecursionDepth, options);
        FieldToJson(jdata["maxShaderGroupStride"], data->decoded_value->maxShaderGroupStride, options);
        FieldToJson(jdata["shaderGroupBaseAlignment"], data->decoded_value->shaderGroupBaseAlignment, options);
        FieldToJson(jdata["maxGeometryCount"], data->decoded_value->maxGeometryCount, options);
        FieldToJson(jdata["maxInstanceCount"], data->decoded_value->maxInstanceCount, options);
        FieldToJson(jdata["maxTriangleCount"], data->decoded_value->maxTriangleCount, options);
        FieldToJson(jdata["maxDescriptorSetAccelerationStructures"], data->decoded_value->maxDescriptorSetAccelerationStructures, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTransformMatrixKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["matrix"], &data->matrix, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAabbPositionsKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["minX"], data->decoded_value->minX, options);
        FieldToJson(jdata["minY"], data->decoded_value->minY, options);
        FieldToJson(jdata["minZ"], data->decoded_value->minZ, options);
        FieldToJson(jdata["maxX"], data->decoded_value->maxX, options);
        FieldToJson(jdata["maxY"], data->decoded_value->maxY, options);
        FieldToJson(jdata["maxZ"], data->decoded_value->maxZ, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureInstanceKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["transform"], data->transform, options);
        FieldToJson(jdata["instanceCustomIndex"], data->decoded_value->instanceCustomIndex, options);
        FieldToJson(jdata["mask"], data->decoded_value->mask, options);
        FieldToJson(jdata["instanceShaderBindingTableRecordOffset"], data->decoded_value->instanceShaderBindingTableRecordOffset, options);
        FieldToJson(VkGeometryInstanceFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["accelerationStructureReference"], data->decoded_value->accelerationStructureReference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["representativeFragmentTest"] = static_cast<bool>(data->decoded_value->representativeFragmentTest);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["representativeFragmentTestEnable"] = static_cast<bool>(data->decoded_value->representativeFragmentTestEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["imageViewType"], data->decoded_value->imageViewType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["filterCubic"] = static_cast<bool>(data->decoded_value->filterCubic);
        jdata["filterCubicMinmax"] = static_cast<bool>(data->decoded_value->filterCubicMinmax);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryHostPointerInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pHostPointer"], data->pHostPointer, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryHostPointerPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["memoryTypeBits"], data->decoded_value->memoryTypeBits, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minImportedHostPointerAlignment"], data->decoded_value->minImportedHostPointerAlignment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCompilerControlCreateInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineCompilerControlFlagsAMD_t(),jdata["compilerControlFlags"], data->decoded_value->compilerControlFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderCorePropertiesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shaderEngineCount"], data->decoded_value->shaderEngineCount, options);
        FieldToJson(jdata["shaderArraysPerEngineCount"], data->decoded_value->shaderArraysPerEngineCount, options);
        FieldToJson(jdata["computeUnitsPerShaderArray"], data->decoded_value->computeUnitsPerShaderArray, options);
        FieldToJson(jdata["simdPerComputeUnit"], data->decoded_value->simdPerComputeUnit, options);
        FieldToJson(jdata["wavefrontsPerSimd"], data->decoded_value->wavefrontsPerSimd, options);
        FieldToJson(jdata["wavefrontSize"], data->decoded_value->wavefrontSize, options);
        FieldToJson(jdata["sgprsPerSimd"], data->decoded_value->sgprsPerSimd, options);
        FieldToJson(jdata["minSgprAllocation"], data->decoded_value->minSgprAllocation, options);
        FieldToJson(jdata["maxSgprAllocation"], data->decoded_value->maxSgprAllocation, options);
        FieldToJson(jdata["sgprAllocationGranularity"], data->decoded_value->sgprAllocationGranularity, options);
        FieldToJson(jdata["vgprsPerSimd"], data->decoded_value->vgprsPerSimd, options);
        FieldToJson(jdata["minVgprAllocation"], data->decoded_value->minVgprAllocation, options);
        FieldToJson(jdata["maxVgprAllocation"], data->decoded_value->maxVgprAllocation, options);
        FieldToJson(jdata["vgprAllocationGranularity"], data->decoded_value->vgprAllocationGranularity, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceMemoryOverallocationCreateInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["overallocationBehavior"], data->decoded_value->overallocationBehavior, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxVertexAttribDivisor"], data->decoded_value->maxVertexAttribDivisor, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPresentFrameTokenGGP* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["frameToken"], data->decoded_value->frameToken, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMeshShaderFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["taskShader"] = static_cast<bool>(data->decoded_value->taskShader);
        jdata["meshShader"] = static_cast<bool>(data->decoded_value->meshShader);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMeshShaderPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxDrawMeshTasksCount"], data->decoded_value->maxDrawMeshTasksCount, options);
        FieldToJson(jdata["maxTaskWorkGroupInvocations"], data->decoded_value->maxTaskWorkGroupInvocations, options);
        FieldToJson(jdata["maxTaskWorkGroupSize"], &data->maxTaskWorkGroupSize, options);
        FieldToJson(jdata["maxTaskTotalMemorySize"], data->decoded_value->maxTaskTotalMemorySize, options);
        FieldToJson(jdata["maxTaskOutputCount"], data->decoded_value->maxTaskOutputCount, options);
        FieldToJson(jdata["maxMeshWorkGroupInvocations"], data->decoded_value->maxMeshWorkGroupInvocations, options);
        FieldToJson(jdata["maxMeshWorkGroupSize"], &data->maxMeshWorkGroupSize, options);
        FieldToJson(jdata["maxMeshTotalMemorySize"], data->decoded_value->maxMeshTotalMemorySize, options);
        FieldToJson(jdata["maxMeshOutputVertices"], data->decoded_value->maxMeshOutputVertices, options);
        FieldToJson(jdata["maxMeshOutputPrimitives"], data->decoded_value->maxMeshOutputPrimitives, options);
        FieldToJson(jdata["maxMeshMultiviewViewCount"], data->decoded_value->maxMeshMultiviewViewCount, options);
        FieldToJson(jdata["meshOutputPerVertexGranularity"], data->decoded_value->meshOutputPerVertexGranularity, options);
        FieldToJson(jdata["meshOutputPerPrimitiveGranularity"], data->decoded_value->meshOutputPerPrimitiveGranularity, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrawMeshTasksIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["taskCount"], data->decoded_value->taskCount, options);
        FieldToJson(jdata["firstTask"], data->decoded_value->firstTask, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["imageFootprint"] = static_cast<bool>(data->decoded_value->imageFootprint);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["exclusiveScissorCount"], data->decoded_value->exclusiveScissorCount, options);
        FieldToJson(jdata["pExclusiveScissors"], data->pExclusiveScissors, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["exclusiveScissor"] = static_cast<bool>(data->decoded_value->exclusiveScissor);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyCheckpointPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineStageFlags_t(),jdata["checkpointExecutionStageMask"], data->decoded_value->checkpointExecutionStageMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCheckpointDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stage"], data->decoded_value->stage, options);
        FieldToJson(jdata["pCheckpointMarker"], data->pCheckpointMarker, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueueFamilyCheckpointProperties2NV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["checkpointExecutionStageMask"], data->decoded_value->checkpointExecutionStageMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCheckpointData2NV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineStageFlags2_t(),jdata["stage"], data->decoded_value->stage, options);
        FieldToJson(jdata["pCheckpointMarker"], data->pCheckpointMarker, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderIntegerFunctions2"] = static_cast<bool>(data->decoded_value->shaderIntegerFunctions2);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkInitializePerformanceApiInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pUserData"], to_hex_variable_width(data->pUserData), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["performanceCountersSampling"], data->decoded_value->performanceCountersSampling, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceMarkerInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["marker"], data->decoded_value->marker, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceStreamMarkerInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["marker"], data->decoded_value->marker, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceOverrideInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        jdata["enable"] = static_cast<bool>(data->decoded_value->enable);
        FieldToJson(jdata["parameter"], data->decoded_value->parameter, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceConfigurationAcquireInfoINTEL* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pciDomain"], data->decoded_value->pciDomain, options);
        FieldToJson(jdata["pciBus"], data->decoded_value->pciBus, options);
        FieldToJson(jdata["pciDevice"], data->decoded_value->pciDevice, options);
        FieldToJson(jdata["pciFunction"], data->decoded_value->pciFunction, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["localDimmingSupport"] = static_cast<bool>(data->decoded_value->localDimmingSupport);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["localDimmingEnable"] = static_cast<bool>(data->decoded_value->localDimmingEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImagePipeSurfaceCreateInfoFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkImagePipeSurfaceCreateFlagsFUCHSIA_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["imagePipeHandle"], data->decoded_value->imagePipeHandle, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMetalSurfaceCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkMetalSurfaceCreateFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pLayer"], data->pLayer, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["fragmentDensityMap"] = static_cast<bool>(data->decoded_value->fragmentDensityMap);
        jdata["fragmentDensityMapDynamic"] = static_cast<bool>(data->decoded_value->fragmentDensityMapDynamic);
        jdata["fragmentDensityMapNonSubsampledImages"] = static_cast<bool>(data->decoded_value->fragmentDensityMapNonSubsampledImages);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minFragmentDensityTexelSize"], data->minFragmentDensityTexelSize, options);
        FieldToJson(jdata["maxFragmentDensityTexelSize"], data->maxFragmentDensityTexelSize, options);
        jdata["fragmentDensityInvocations"] = static_cast<bool>(data->decoded_value->fragmentDensityInvocations);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["fragmentDensityMapAttachment"], data->fragmentDensityMapAttachment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["imageView"], data->imageView, options);
        FieldToJson(jdata["imageLayout"], data->decoded_value->imageLayout, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderCoreProperties2AMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderCorePropertiesFlagsAMD_t(),jdata["shaderCoreFeatures"], data->decoded_value->shaderCoreFeatures, options);
        FieldToJson(jdata["activeComputeUnitCount"], data->decoded_value->activeComputeUnitCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["deviceCoherentMemory"] = static_cast<bool>(data->decoded_value->deviceCoherentMemory);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderImageInt64Atomics"] = static_cast<bool>(data->decoded_value->shaderImageInt64Atomics);
        jdata["sparseImageInt64Atomics"] = static_cast<bool>(data->decoded_value->sparseImageInt64Atomics);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["heapBudget"], &data->heapBudget, options);
        FieldToJson(jdata["heapUsage"], &data->heapUsage, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["memoryPriority"] = static_cast<bool>(data->decoded_value->memoryPriority);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryPriorityAllocateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["priority"], data->decoded_value->priority, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["dedicatedAllocationImageAliasing"] = static_cast<bool>(data->decoded_value->dedicatedAllocationImageAliasing);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["bufferDeviceAddress"] = static_cast<bool>(data->decoded_value->bufferDeviceAddress);
        jdata["bufferDeviceAddressCaptureReplay"] = static_cast<bool>(data->decoded_value->bufferDeviceAddressCaptureReplay);
        jdata["bufferDeviceAddressMultiDevice"] = static_cast<bool>(data->decoded_value->bufferDeviceAddressMultiDevice);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBufferDeviceAddressCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["deviceAddress"], to_hex_variable_width(data->decoded_value->deviceAddress), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkValidationFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["enabledValidationFeatureCount"], data->decoded_value->enabledValidationFeatureCount, options);
        FieldToJson(jdata["pEnabledValidationFeatures"], data->pEnabledValidationFeatures, options);
        FieldToJson(jdata["disabledValidationFeatureCount"], data->decoded_value->disabledValidationFeatureCount, options);
        FieldToJson(jdata["pDisabledValidationFeatures"], data->pDisabledValidationFeatures, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCooperativeMatrixPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["MSize"], data->decoded_value->MSize, options);
        FieldToJson(jdata["NSize"], data->decoded_value->NSize, options);
        FieldToJson(jdata["KSize"], data->decoded_value->KSize, options);
        FieldToJson(jdata["AType"], data->decoded_value->AType, options);
        FieldToJson(jdata["BType"], data->decoded_value->BType, options);
        FieldToJson(jdata["CType"], data->decoded_value->CType, options);
        FieldToJson(jdata["DType"], data->decoded_value->DType, options);
        FieldToJson(jdata["scope"], data->decoded_value->scope, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["cooperativeMatrix"] = static_cast<bool>(data->decoded_value->cooperativeMatrix);
        jdata["cooperativeMatrixRobustBufferAccess"] = static_cast<bool>(data->decoded_value->cooperativeMatrixRobustBufferAccess);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["cooperativeMatrixSupportedStages"], data->decoded_value->cooperativeMatrixSupportedStages, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["coverageReductionMode"] = static_cast<bool>(data->decoded_value->coverageReductionMode);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCoverageReductionStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineCoverageReductionStateCreateFlagsNV_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["coverageReductionMode"], data->decoded_value->coverageReductionMode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFramebufferMixedSamplesCombinationNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["coverageReductionMode"], data->decoded_value->coverageReductionMode, options);
        FieldToJson(jdata["rasterizationSamples"], data->decoded_value->rasterizationSamples, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["depthStencilSamples"], data->decoded_value->depthStencilSamples, options);
        FieldToJson(VkSampleCountFlags_t(),jdata["colorSamples"], data->decoded_value->colorSamples, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["fragmentShaderSampleInterlock"] = static_cast<bool>(data->decoded_value->fragmentShaderSampleInterlock);
        jdata["fragmentShaderPixelInterlock"] = static_cast<bool>(data->decoded_value->fragmentShaderPixelInterlock);
        jdata["fragmentShaderShadingRateInterlock"] = static_cast<bool>(data->decoded_value->fragmentShaderShadingRateInterlock);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["ycbcrImageArrays"] = static_cast<bool>(data->decoded_value->ycbcrImageArrays);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProvokingVertexFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["provokingVertexLast"] = static_cast<bool>(data->decoded_value->provokingVertexLast);
        jdata["transformFeedbackPreservesProvokingVertex"] = static_cast<bool>(data->decoded_value->transformFeedbackPreservesProvokingVertex);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceProvokingVertexPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["provokingVertexModePerPipeline"] = static_cast<bool>(data->decoded_value->provokingVertexModePerPipeline);
        jdata["transformFeedbackPreservesTriangleFanProvokingVertex"] = static_cast<bool>(data->decoded_value->transformFeedbackPreservesTriangleFanProvokingVertex);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["provokingVertexMode"], data->decoded_value->provokingVertexMode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceFullScreenExclusiveInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["fullScreenExclusive"], data->decoded_value->fullScreenExclusive, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["fullScreenExclusiveSupported"] = static_cast<bool>(data->decoded_value->fullScreenExclusiveSupported);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["hmonitor"], data->hmonitor, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkHeadlessSurfaceCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkHeadlessSurfaceCreateFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderBufferFloat32Atomics"] = static_cast<bool>(data->decoded_value->shaderBufferFloat32Atomics);
        jdata["shaderBufferFloat32AtomicAdd"] = static_cast<bool>(data->decoded_value->shaderBufferFloat32AtomicAdd);
        jdata["shaderBufferFloat64Atomics"] = static_cast<bool>(data->decoded_value->shaderBufferFloat64Atomics);
        jdata["shaderBufferFloat64AtomicAdd"] = static_cast<bool>(data->decoded_value->shaderBufferFloat64AtomicAdd);
        jdata["shaderSharedFloat32Atomics"] = static_cast<bool>(data->decoded_value->shaderSharedFloat32Atomics);
        jdata["shaderSharedFloat32AtomicAdd"] = static_cast<bool>(data->decoded_value->shaderSharedFloat32AtomicAdd);
        jdata["shaderSharedFloat64Atomics"] = static_cast<bool>(data->decoded_value->shaderSharedFloat64Atomics);
        jdata["shaderSharedFloat64AtomicAdd"] = static_cast<bool>(data->decoded_value->shaderSharedFloat64AtomicAdd);
        jdata["shaderImageFloat32Atomics"] = static_cast<bool>(data->decoded_value->shaderImageFloat32Atomics);
        jdata["shaderImageFloat32AtomicAdd"] = static_cast<bool>(data->decoded_value->shaderImageFloat32AtomicAdd);
        jdata["sparseImageFloat32Atomics"] = static_cast<bool>(data->decoded_value->sparseImageFloat32Atomics);
        jdata["sparseImageFloat32AtomicAdd"] = static_cast<bool>(data->decoded_value->sparseImageFloat32AtomicAdd);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["extendedDynamicState"] = static_cast<bool>(data->decoded_value->extendedDynamicState);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["memoryMapPlaced"] = static_cast<bool>(data->decoded_value->memoryMapPlaced);
        jdata["memoryMapRangePlaced"] = static_cast<bool>(data->decoded_value->memoryMapRangePlaced);
        jdata["memoryUnmapReserve"] = static_cast<bool>(data->decoded_value->memoryUnmapReserve);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minPlacedMemoryMapAlignment"], data->decoded_value->minPlacedMemoryMapAlignment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryMapPlacedInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pPlacedAddress"], data->pPlacedAddress, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderBufferFloat16Atomics"] = static_cast<bool>(data->decoded_value->shaderBufferFloat16Atomics);
        jdata["shaderBufferFloat16AtomicAdd"] = static_cast<bool>(data->decoded_value->shaderBufferFloat16AtomicAdd);
        jdata["shaderBufferFloat16AtomicMinMax"] = static_cast<bool>(data->decoded_value->shaderBufferFloat16AtomicMinMax);
        jdata["shaderBufferFloat32AtomicMinMax"] = static_cast<bool>(data->decoded_value->shaderBufferFloat32AtomicMinMax);
        jdata["shaderBufferFloat64AtomicMinMax"] = static_cast<bool>(data->decoded_value->shaderBufferFloat64AtomicMinMax);
        jdata["shaderSharedFloat16Atomics"] = static_cast<bool>(data->decoded_value->shaderSharedFloat16Atomics);
        jdata["shaderSharedFloat16AtomicAdd"] = static_cast<bool>(data->decoded_value->shaderSharedFloat16AtomicAdd);
        jdata["shaderSharedFloat16AtomicMinMax"] = static_cast<bool>(data->decoded_value->shaderSharedFloat16AtomicMinMax);
        jdata["shaderSharedFloat32AtomicMinMax"] = static_cast<bool>(data->decoded_value->shaderSharedFloat32AtomicMinMax);
        jdata["shaderSharedFloat64AtomicMinMax"] = static_cast<bool>(data->decoded_value->shaderSharedFloat64AtomicMinMax);
        jdata["shaderImageFloat32AtomicMinMax"] = static_cast<bool>(data->decoded_value->shaderImageFloat32AtomicMinMax);
        jdata["sparseImageFloat32AtomicMinMax"] = static_cast<bool>(data->decoded_value->sparseImageFloat32AtomicMinMax);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxGraphicsShaderGroupCount"], data->decoded_value->maxGraphicsShaderGroupCount, options);
        FieldToJson(jdata["maxIndirectSequenceCount"], data->decoded_value->maxIndirectSequenceCount, options);
        FieldToJson(jdata["maxIndirectCommandsTokenCount"], data->decoded_value->maxIndirectCommandsTokenCount, options);
        FieldToJson(jdata["maxIndirectCommandsStreamCount"], data->decoded_value->maxIndirectCommandsStreamCount, options);
        FieldToJson(jdata["maxIndirectCommandsTokenOffset"], data->decoded_value->maxIndirectCommandsTokenOffset, options);
        FieldToJson(jdata["maxIndirectCommandsStreamStride"], data->decoded_value->maxIndirectCommandsStreamStride, options);
        FieldToJson(jdata["minSequencesCountBufferOffsetAlignment"], data->decoded_value->minSequencesCountBufferOffsetAlignment, options);
        FieldToJson(jdata["minSequencesIndexBufferOffsetAlignment"], data->decoded_value->minSequencesIndexBufferOffsetAlignment, options);
        FieldToJson(jdata["minIndirectCommandsBufferOffsetAlignment"], data->decoded_value->minIndirectCommandsBufferOffsetAlignment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["deviceGeneratedCommands"] = static_cast<bool>(data->decoded_value->deviceGeneratedCommands);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGraphicsShaderGroupCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stageCount"], data->decoded_value->stageCount, options);
        FieldToJson(jdata["pStages"], data->pStages, options);
        FieldToJson(jdata["pVertexInputState"], data->pVertexInputState, options);
        FieldToJson(jdata["pTessellationState"], data->pTessellationState, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["groupCount"], data->decoded_value->groupCount, options);
        FieldToJson(jdata["pGroups"], data->pGroups, options);
        FieldToJson(jdata["pipelineCount"], data->decoded_value->pipelineCount, options);
        HandleToJson(jdata["pPipelines"], &data->pPipelines, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindShaderGroupIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["groupIndex"], data->decoded_value->groupIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindIndexBufferIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["bufferAddress"], to_hex_variable_width(data->decoded_value->bufferAddress), options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["indexType"], data->decoded_value->indexType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindVertexBufferIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["bufferAddress"], to_hex_variable_width(data->decoded_value->bufferAddress), options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["stride"], data->decoded_value->stride, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSetStateFlagsIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["data"], data->decoded_value->data, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsStreamNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsLayoutTokenNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["tokenType"], data->decoded_value->tokenType, options);
        FieldToJson(jdata["stream"], data->decoded_value->stream, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["vertexBindingUnit"], data->decoded_value->vertexBindingUnit, options);
        jdata["vertexDynamicStride"] = static_cast<bool>(data->decoded_value->vertexDynamicStride);
        HandleToJson(jdata["pushconstantPipelineLayout"], data->pushconstantPipelineLayout, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["pushconstantShaderStageFlags"], data->decoded_value->pushconstantShaderStageFlags, options);
        FieldToJson(jdata["pushconstantOffset"], data->decoded_value->pushconstantOffset, options);
        FieldToJson(jdata["pushconstantSize"], data->decoded_value->pushconstantSize, options);
        FieldToJson(VkIndirectStateFlagsNV_t(),jdata["indirectStateFlags"], data->decoded_value->indirectStateFlags, options);
        FieldToJson(jdata["indexTypeCount"], data->decoded_value->indexTypeCount, options);
        FieldToJson(jdata["pIndexTypes"], data->pIndexTypes, options);
        FieldToJson(jdata["pIndexTypeValues"], data->pIndexTypeValues, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsLayoutCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkIndirectCommandsLayoutUsageFlagsNV_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pipelineBindPoint"], data->decoded_value->pipelineBindPoint, options);
        FieldToJson(jdata["tokenCount"], data->decoded_value->tokenCount, options);
        FieldToJson(jdata["pTokens"], data->pTokens, options);
        FieldToJson(jdata["streamCount"], data->decoded_value->streamCount, options);
        FieldToJson(jdata["pStreamStrides"], data->pStreamStrides, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeneratedCommandsInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pipelineBindPoint"], data->decoded_value->pipelineBindPoint, options);
        HandleToJson(jdata["pipeline"], data->pipeline, options);
        HandleToJson(jdata["indirectCommandsLayout"], data->indirectCommandsLayout, options);
        FieldToJson(jdata["streamCount"], data->decoded_value->streamCount, options);
        FieldToJson(jdata["pStreams"], data->pStreams, options);
        FieldToJson(jdata["sequencesCount"], data->decoded_value->sequencesCount, options);
        HandleToJson(jdata["preprocessBuffer"], data->preprocessBuffer, options);
        FieldToJson(jdata["preprocessOffset"], data->decoded_value->preprocessOffset, options);
        FieldToJson(jdata["preprocessSize"], data->decoded_value->preprocessSize, options);
        HandleToJson(jdata["sequencesCountBuffer"], data->sequencesCountBuffer, options);
        FieldToJson(jdata["sequencesCountOffset"], data->decoded_value->sequencesCountOffset, options);
        HandleToJson(jdata["sequencesIndexBuffer"], data->sequencesIndexBuffer, options);
        FieldToJson(jdata["sequencesIndexOffset"], data->decoded_value->sequencesIndexOffset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeneratedCommandsMemoryRequirementsInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pipelineBindPoint"], data->decoded_value->pipelineBindPoint, options);
        HandleToJson(jdata["pipeline"], data->pipeline, options);
        HandleToJson(jdata["indirectCommandsLayout"], data->indirectCommandsLayout, options);
        FieldToJson(jdata["maxSequencesCount"], data->decoded_value->maxSequencesCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["inheritedViewportScissor2D"] = static_cast<bool>(data->decoded_value->inheritedViewportScissor2D);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferInheritanceViewportScissorInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["viewportScissor2D"] = static_cast<bool>(data->decoded_value->viewportScissor2D);
        FieldToJson(jdata["viewportDepthCount"], data->decoded_value->viewportDepthCount, options);
        FieldToJson(jdata["pViewportDepths"], data->pViewportDepths, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["texelBufferAlignment"] = static_cast<bool>(data->decoded_value->texelBufferAlignment);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassTransformBeginInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["transform"], data->decoded_value->transform, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["transform"], data->decoded_value->transform, options);
        FieldToJson(jdata["renderArea"], data->renderArea, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["depthBiasControl"] = static_cast<bool>(data->decoded_value->depthBiasControl);
        jdata["leastRepresentableValueForceUnormRepresentation"] = static_cast<bool>(data->decoded_value->leastRepresentableValueForceUnormRepresentation);
        jdata["floatRepresentation"] = static_cast<bool>(data->decoded_value->floatRepresentation);
        jdata["depthBiasExact"] = static_cast<bool>(data->decoded_value->depthBiasExact);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDepthBiasInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["depthBiasConstantFactor"], data->decoded_value->depthBiasConstantFactor, options);
        FieldToJson(jdata["depthBiasClamp"], data->decoded_value->depthBiasClamp, options);
        FieldToJson(jdata["depthBiasSlopeFactor"], data->decoded_value->depthBiasSlopeFactor, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDepthBiasRepresentationInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["depthBiasRepresentation"], data->decoded_value->depthBiasRepresentation, options);
        jdata["depthBiasExact"] = static_cast<bool>(data->decoded_value->depthBiasExact);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["deviceMemoryReport"] = static_cast<bool>(data->decoded_value->deviceMemoryReport);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceMemoryReportCallbackDataEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDeviceMemoryReportFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["memoryObjectId"], data->decoded_value->memoryObjectId, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["objectType"], data->decoded_value->objectType, options);
        FieldToJson(jdata["objectHandle"], data->decoded_value->objectHandle, options);
        FieldToJson(jdata["heapIndex"], data->decoded_value->heapIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDeviceMemoryReportFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pfnUserCallback"], to_hex_variable_width(data->pfnUserCallback), options);
        FieldToJson(jdata["pUserData"], to_hex_variable_width(data->pUserData), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerCustomBorderColorCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["customBorderColor"], data->customBorderColor, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxCustomBorderColorSamplers"], data->decoded_value->maxCustomBorderColorSamplers, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["customBorderColors"] = static_cast<bool>(data->decoded_value->customBorderColors);
        jdata["customBorderColorWithoutFormat"] = static_cast<bool>(data->decoded_value->customBorderColorWithoutFormat);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePresentBarrierFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentBarrier"] = static_cast<bool>(data->decoded_value->presentBarrier);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSurfaceCapabilitiesPresentBarrierNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentBarrierSupported"] = static_cast<bool>(data->decoded_value->presentBarrierSupported);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainPresentBarrierCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentBarrierEnable"] = static_cast<bool>(data->decoded_value->presentBarrierEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["diagnosticsConfig"] = static_cast<bool>(data->decoded_value->diagnosticsConfig);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceDiagnosticsConfigCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDeviceDiagnosticsConfigFlagsNV_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTileShadingFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["tileShading"] = static_cast<bool>(data->decoded_value->tileShading);
        jdata["tileShadingFragmentStage"] = static_cast<bool>(data->decoded_value->tileShadingFragmentStage);
        jdata["tileShadingColorAttachments"] = static_cast<bool>(data->decoded_value->tileShadingColorAttachments);
        jdata["tileShadingDepthAttachments"] = static_cast<bool>(data->decoded_value->tileShadingDepthAttachments);
        jdata["tileShadingStencilAttachments"] = static_cast<bool>(data->decoded_value->tileShadingStencilAttachments);
        jdata["tileShadingInputAttachments"] = static_cast<bool>(data->decoded_value->tileShadingInputAttachments);
        jdata["tileShadingSampledAttachments"] = static_cast<bool>(data->decoded_value->tileShadingSampledAttachments);
        jdata["tileShadingPerTileDraw"] = static_cast<bool>(data->decoded_value->tileShadingPerTileDraw);
        jdata["tileShadingPerTileDispatch"] = static_cast<bool>(data->decoded_value->tileShadingPerTileDispatch);
        jdata["tileShadingDispatchTile"] = static_cast<bool>(data->decoded_value->tileShadingDispatchTile);
        jdata["tileShadingApron"] = static_cast<bool>(data->decoded_value->tileShadingApron);
        jdata["tileShadingAnisotropicApron"] = static_cast<bool>(data->decoded_value->tileShadingAnisotropicApron);
        jdata["tileShadingAtomicOps"] = static_cast<bool>(data->decoded_value->tileShadingAtomicOps);
        jdata["tileShadingImageProcessing"] = static_cast<bool>(data->decoded_value->tileShadingImageProcessing);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTileShadingPropertiesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxApronSize"], data->decoded_value->maxApronSize, options);
        jdata["preferNonCoherent"] = static_cast<bool>(data->decoded_value->preferNonCoherent);
        FieldToJson(jdata["tileGranularity"], data->tileGranularity, options);
        FieldToJson(jdata["maxTileShadingRate"], data->maxTileShadingRate, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassTileShadingCreateInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkTileShadingRenderPassFlagsQCOM_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["tileApronSize"], data->tileApronSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerTileBeginInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerTileEndInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDispatchTileInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkQueryLowLatencySupportNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pQueriedLowLatencyData"], data->pQueriedLowLatencyData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceGraphicsPipelineLibraryFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["graphicsPipelineLibrary"] = static_cast<bool>(data->decoded_value->graphicsPipelineLibrary);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceGraphicsPipelineLibraryPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["graphicsPipelineLibraryFastLinking"] = static_cast<bool>(data->decoded_value->graphicsPipelineLibraryFastLinking);
        jdata["graphicsPipelineLibraryIndependentInterpolationDecoration"] = static_cast<bool>(data->decoded_value->graphicsPipelineLibraryIndependentInterpolationDecoration);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGraphicsPipelineLibraryCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkGraphicsPipelineLibraryFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderEarlyAndLateFragmentTests"] = static_cast<bool>(data->decoded_value->shaderEarlyAndLateFragmentTests);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["fragmentShadingRateEnums"] = static_cast<bool>(data->decoded_value->fragmentShadingRateEnums);
        jdata["supersampleFragmentShadingRates"] = static_cast<bool>(data->decoded_value->supersampleFragmentShadingRates);
        jdata["noInvocationFragmentShadingRates"] = static_cast<bool>(data->decoded_value->noInvocationFragmentShadingRates);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxFragmentShadingRateInvocationCount"], data->decoded_value->maxFragmentShadingRateInvocationCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shadingRateType"], data->decoded_value->shadingRateType, options);
        FieldToJson(jdata["shadingRate"], data->decoded_value->shadingRate, options);
        FieldToJson(jdata["combinerOps"], &data->combinerOps, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["vertexData"], data->vertexData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureMotionInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxInstances"], data->decoded_value->maxInstances, options);
        FieldToJson(VkAccelerationStructureMotionInfoFlagsNV_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureMatrixMotionInstanceNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["transformT0"], data->transformT0, options);
        FieldToJson(jdata["transformT1"], data->transformT1, options);
        FieldToJson(jdata["instanceCustomIndex"], data->decoded_value->instanceCustomIndex, options);
        FieldToJson(jdata["mask"], data->decoded_value->mask, options);
        FieldToJson(jdata["instanceShaderBindingTableRecordOffset"], data->decoded_value->instanceShaderBindingTableRecordOffset, options);
        FieldToJson(VkGeometryInstanceFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["accelerationStructureReference"], data->decoded_value->accelerationStructureReference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSRTDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sx"], data->decoded_value->sx, options);
        FieldToJson(jdata["a"], data->decoded_value->a, options);
        FieldToJson(jdata["b"], data->decoded_value->b, options);
        FieldToJson(jdata["pvx"], data->decoded_value->pvx, options);
        FieldToJson(jdata["sy"], data->decoded_value->sy, options);
        FieldToJson(jdata["c"], data->decoded_value->c, options);
        FieldToJson(jdata["pvy"], data->decoded_value->pvy, options);
        FieldToJson(jdata["sz"], data->decoded_value->sz, options);
        FieldToJson(jdata["pvz"], data->decoded_value->pvz, options);
        FieldToJson(jdata["qx"], data->decoded_value->qx, options);
        FieldToJson(jdata["qy"], data->decoded_value->qy, options);
        FieldToJson(jdata["qz"], data->decoded_value->qz, options);
        FieldToJson(jdata["qw"], data->decoded_value->qw, options);
        FieldToJson(jdata["tx"], data->decoded_value->tx, options);
        FieldToJson(jdata["ty"], data->decoded_value->ty, options);
        FieldToJson(jdata["tz"], data->decoded_value->tz, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureSRTMotionInstanceNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["transformT0"], data->transformT0, options);
        FieldToJson(jdata["transformT1"], data->transformT1, options);
        FieldToJson(jdata["instanceCustomIndex"], data->decoded_value->instanceCustomIndex, options);
        FieldToJson(jdata["mask"], data->decoded_value->mask, options);
        FieldToJson(jdata["instanceShaderBindingTableRecordOffset"], data->decoded_value->instanceShaderBindingTableRecordOffset, options);
        FieldToJson(VkGeometryInstanceFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["accelerationStructureReference"], data->decoded_value->accelerationStructureReference, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["rayTracingMotionBlur"] = static_cast<bool>(data->decoded_value->rayTracingMotionBlur);
        jdata["rayTracingMotionBlurPipelineTraceRaysIndirect"] = static_cast<bool>(data->decoded_value->rayTracingMotionBlurPipelineTraceRaysIndirect);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["ycbcr2plane444Formats"] = static_cast<bool>(data->decoded_value->ycbcr2plane444Formats);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMap2FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["fragmentDensityMapDeferred"] = static_cast<bool>(data->decoded_value->fragmentDensityMapDeferred);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMap2PropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["subsampledLoads"] = static_cast<bool>(data->decoded_value->subsampledLoads);
        jdata["subsampledCoarseReconstructionEarlyAccess"] = static_cast<bool>(data->decoded_value->subsampledCoarseReconstructionEarlyAccess);
        FieldToJson(jdata["maxSubsampledArrayLayers"], data->decoded_value->maxSubsampledArrayLayers, options);
        FieldToJson(jdata["maxDescriptorSetSubsampledSamplers"], data->decoded_value->maxDescriptorSetSubsampledSamplers, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyCommandTransformInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["transform"], data->decoded_value->transform, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["imageCompressionControl"] = static_cast<bool>(data->decoded_value->imageCompressionControl);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageCompressionControlEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkImageCompressionFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["compressionControlPlaneCount"], data->decoded_value->compressionControlPlaneCount, options);
        FieldToJson(jdata["pFixedRateFlags"], data->pFixedRateFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageCompressionPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkImageCompressionFlagsEXT_t(),jdata["imageCompressionFlags"], data->decoded_value->imageCompressionFlags, options);
        FieldToJson(VkImageCompressionFixedRateFlagsEXT_t(),jdata["imageCompressionFixedRateFlags"], data->decoded_value->imageCompressionFixedRateFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["attachmentFeedbackLoopLayout"] = static_cast<bool>(data->decoded_value->attachmentFeedbackLoopLayout);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevice4444FormatsFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["formatA4R4G4B4"] = static_cast<bool>(data->decoded_value->formatA4R4G4B4);
        jdata["formatA4B4G4R4"] = static_cast<bool>(data->decoded_value->formatA4B4G4R4);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFaultFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["deviceFault"] = static_cast<bool>(data->decoded_value->deviceFault);
        jdata["deviceFaultVendorBinary"] = static_cast<bool>(data->decoded_value->deviceFaultVendorBinary);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceFaultCountsEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["addressInfoCount"], data->decoded_value->addressInfoCount, options);
        FieldToJson(jdata["vendorInfoCount"], data->decoded_value->vendorInfoCount, options);
        FieldToJson(jdata["vendorBinarySize"], data->decoded_value->vendorBinarySize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceFaultAddressInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["addressType"], data->decoded_value->addressType, options);
        FieldToJson(jdata["reportedAddress"], to_hex_variable_width(data->decoded_value->reportedAddress), options);
        FieldToJson(jdata["addressPrecision"], data->decoded_value->addressPrecision, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceFaultVendorInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["description"], &data->description, options);
        FieldToJson(jdata["vendorFaultCode"], data->decoded_value->vendorFaultCode, options);
        FieldToJson(jdata["vendorFaultData"], data->decoded_value->vendorFaultData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceFaultInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["description"], &data->description, options);
        FieldToJson(jdata["pAddressInfos"], data->pAddressInfos, options);
        FieldToJson(jdata["pVendorInfos"], data->pVendorInfos, options);
        FieldToJson(jdata["pVendorBinaryData"], data->pVendorBinaryData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceFaultVendorBinaryHeaderVersionOneEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["headerSize"], data->decoded_value->headerSize, options);
        FieldToJson(jdata["headerVersion"], data->decoded_value->headerVersion, options);
        FieldToJson(jdata["vendorID"], data->decoded_value->vendorID, options);
        FieldToJson(jdata["deviceID"], data->decoded_value->deviceID, options);
        FieldToJson(jdata["driverVersion"], data->decoded_value->driverVersion, options);
        FieldToJson(jdata["pipelineCacheUUID"], uuid_to_string(sizeof(data->decoded_value->pipelineCacheUUID), data->decoded_value->pipelineCacheUUID), options);
        FieldToJson(jdata["applicationNameOffset"], data->decoded_value->applicationNameOffset, options);
        FieldToJson(jdata["applicationVersion"], data->decoded_value->applicationVersion, options);
        FieldToJson(jdata["engineNameOffset"], data->decoded_value->engineNameOffset, options);
        FieldToJson(jdata["engineVersion"], data->decoded_value->engineVersion, options);
        FieldToJson(jdata["apiVersion"], data->decoded_value->apiVersion, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["rasterizationOrderColorAttachmentAccess"] = static_cast<bool>(data->decoded_value->rasterizationOrderColorAttachmentAccess);
        jdata["rasterizationOrderDepthAttachmentAccess"] = static_cast<bool>(data->decoded_value->rasterizationOrderDepthAttachmentAccess);
        jdata["rasterizationOrderStencilAttachmentAccess"] = static_cast<bool>(data->decoded_value->rasterizationOrderStencilAttachmentAccess);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["formatRgba10x6WithoutYCbCrSampler"] = static_cast<bool>(data->decoded_value->formatRgba10x6WithoutYCbCrSampler);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDirectFBSurfaceCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDirectFBSurfaceCreateFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["dfb"], data->dfb, options);
        FieldToJson(jdata["surface"], data->surface, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["mutableDescriptorType"] = static_cast<bool>(data->decoded_value->mutableDescriptorType);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMutableDescriptorTypeListEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["descriptorTypeCount"], data->decoded_value->descriptorTypeCount, options);
        FieldToJson(jdata["pDescriptorTypes"], data->pDescriptorTypes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMutableDescriptorTypeCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["mutableDescriptorTypeListCount"], data->decoded_value->mutableDescriptorTypeListCount, options);
        FieldToJson(jdata["pMutableDescriptorTypeLists"], data->pMutableDescriptorTypeLists, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["vertexInputDynamicState"] = static_cast<bool>(data->decoded_value->vertexInputDynamicState);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVertexInputBindingDescription2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["binding"], data->decoded_value->binding, options);
        FieldToJson(jdata["stride"], data->decoded_value->stride, options);
        FieldToJson(jdata["inputRate"], data->decoded_value->inputRate, options);
        FieldToJson(jdata["divisor"], data->decoded_value->divisor, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVertexInputAttributeDescription2EXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["location"], data->decoded_value->location, options);
        FieldToJson(jdata["binding"], data->decoded_value->binding, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDrmPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["hasPrimary"] = static_cast<bool>(data->decoded_value->hasPrimary);
        jdata["hasRender"] = static_cast<bool>(data->decoded_value->hasRender);
        FieldToJson(jdata["primaryMajor"], data->decoded_value->primaryMajor, options);
        FieldToJson(jdata["primaryMinor"], data->decoded_value->primaryMinor, options);
        FieldToJson(jdata["renderMajor"], data->decoded_value->renderMajor, options);
        FieldToJson(jdata["renderMinor"], data->decoded_value->renderMinor, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["reportAddressBinding"] = static_cast<bool>(data->decoded_value->reportAddressBinding);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceAddressBindingCallbackDataEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDeviceAddressBindingFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["baseAddress"], to_hex_variable_width(data->decoded_value->baseAddress), options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["bindingType"], data->decoded_value->bindingType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["depthClipControl"] = static_cast<bool>(data->decoded_value->depthClipControl);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["negativeOneToOne"] = static_cast<bool>(data->decoded_value->negativeOneToOne);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["primitiveTopologyListRestart"] = static_cast<bool>(data->decoded_value->primitiveTopologyListRestart);
        jdata["primitiveTopologyPatchListRestart"] = static_cast<bool>(data->decoded_value->primitiveTopologyPatchListRestart);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryZirconHandleInfoFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["handle"], data->decoded_value->handle, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryZirconHandlePropertiesFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["memoryTypeBits"], data->decoded_value->memoryTypeBits, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetZirconHandleInfoFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportSemaphoreZirconHandleInfoFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["semaphore"], data->semaphore, options);
        FieldToJson(VkSemaphoreImportFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["zirconHandle"], data->decoded_value->zirconHandle, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSemaphoreGetZirconHandleInfoFUCHSIA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["semaphore"], data->semaphore, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["invocationMask"] = static_cast<bool>(data->decoded_value->invocationMask);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetRemoteAddressInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["externalMemoryRDMA"] = static_cast<bool>(data->decoded_value->externalMemoryRDMA);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["frameBoundary"] = static_cast<bool>(data->decoded_value->frameBoundary);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkFrameBoundaryEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkFrameBoundaryFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["frameID"], data->decoded_value->frameID, options);
        FieldToJson(jdata["imageCount"], data->decoded_value->imageCount, options);
        HandleToJson(jdata["pImages"], &data->pImages, options);
        FieldToJson(jdata["bufferCount"], data->decoded_value->bufferCount, options);
        HandleToJson(jdata["pBuffers"], &data->pBuffers, options);
        FieldToJson(jdata["tagName"], data->decoded_value->tagName, options);
        FieldToJson(jdata["tagSize"], data->decoded_value->tagSize, options);
        FieldToJson(jdata["pTag"], data->pTag, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["multisampledRenderToSingleSampled"] = static_cast<bool>(data->decoded_value->multisampledRenderToSingleSampled);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSubpassResolvePerformanceQueryEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["optimal"] = static_cast<bool>(data->decoded_value->optimal);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultisampledRenderToSingleSampledInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["multisampledRenderToSingleSampledEnable"] = static_cast<bool>(data->decoded_value->multisampledRenderToSingleSampledEnable);
        FieldToJson(jdata["rasterizationSamples"], data->decoded_value->rasterizationSamples, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["extendedDynamicState2"] = static_cast<bool>(data->decoded_value->extendedDynamicState2);
        jdata["extendedDynamicState2LogicOp"] = static_cast<bool>(data->decoded_value->extendedDynamicState2LogicOp);
        jdata["extendedDynamicState2PatchControlPoints"] = static_cast<bool>(data->decoded_value->extendedDynamicState2PatchControlPoints);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkScreenSurfaceCreateInfoQNX* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkScreenSurfaceCreateFlagsQNX_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["context"], data->context, options);
        FieldToJson(jdata["window"], data->window, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["colorWriteEnable"] = static_cast<bool>(data->decoded_value->colorWriteEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineColorWriteCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["attachmentCount"], data->decoded_value->attachmentCount, options);
        FieldToJson(jdata["pColorWriteEnables"], data->pColorWriteEnables, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["primitivesGeneratedQuery"] = static_cast<bool>(data->decoded_value->primitivesGeneratedQuery);
        jdata["primitivesGeneratedQueryWithRasterizerDiscard"] = static_cast<bool>(data->decoded_value->primitivesGeneratedQueryWithRasterizerDiscard);
        jdata["primitivesGeneratedQueryWithNonZeroStreams"] = static_cast<bool>(data->decoded_value->primitivesGeneratedQueryWithNonZeroStreams);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["videoEncodeRgbConversion"] = static_cast<bool>(data->decoded_value->videoEncodeRgbConversion);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeRgbConversionCapabilitiesVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkVideoEncodeRgbModelConversionFlagsVALVE_t(),jdata["rgbModels"], data->decoded_value->rgbModels, options);
        FieldToJson(VkVideoEncodeRgbRangeCompressionFlagsVALVE_t(),jdata["rgbRanges"], data->decoded_value->rgbRanges, options);
        FieldToJson(VkVideoEncodeRgbChromaOffsetFlagsVALVE_t(),jdata["xChromaOffsets"], data->decoded_value->xChromaOffsets, options);
        FieldToJson(VkVideoEncodeRgbChromaOffsetFlagsVALVE_t(),jdata["yChromaOffsets"], data->decoded_value->yChromaOffsets, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeProfileRgbConversionInfoVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["performEncodeRgbConversion"] = static_cast<bool>(data->decoded_value->performEncodeRgbConversion);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkVideoEncodeSessionRgbConversionCreateInfoVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["rgbModel"], data->decoded_value->rgbModel, options);
        FieldToJson(jdata["rgbRange"], data->decoded_value->rgbRange, options);
        FieldToJson(jdata["xChromaOffset"], data->decoded_value->xChromaOffset, options);
        FieldToJson(jdata["yChromaOffset"], data->decoded_value->yChromaOffset, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["minLod"] = static_cast<bool>(data->decoded_value->minLod);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewMinLodCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["minLod"], data->decoded_value->minLod, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiDrawFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["multiDraw"] = static_cast<bool>(data->decoded_value->multiDraw);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiDrawPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxMultiDrawCount"], data->decoded_value->maxMultiDrawCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultiDrawInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["firstVertex"], data->decoded_value->firstVertex, options);
        FieldToJson(jdata["vertexCount"], data->decoded_value->vertexCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultiDrawIndexedInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["firstIndex"], data->decoded_value->firstIndex, options);
        FieldToJson(jdata["indexCount"], data->decoded_value->indexCount, options);
        FieldToJson(jdata["vertexOffset"], data->decoded_value->vertexOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["image2DViewOf3D"] = static_cast<bool>(data->decoded_value->image2DViewOf3D);
        jdata["sampler2DViewOf3D"] = static_cast<bool>(data->decoded_value->sampler2DViewOf3D);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderTileImageColorReadAccess"] = static_cast<bool>(data->decoded_value->shaderTileImageColorReadAccess);
        jdata["shaderTileImageDepthReadAccess"] = static_cast<bool>(data->decoded_value->shaderTileImageDepthReadAccess);
        jdata["shaderTileImageStencilReadAccess"] = static_cast<bool>(data->decoded_value->shaderTileImageStencilReadAccess);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderTileImageCoherentReadAccelerated"] = static_cast<bool>(data->decoded_value->shaderTileImageCoherentReadAccelerated);
        jdata["shaderTileImageReadSampleFromPixelRateInvocation"] = static_cast<bool>(data->decoded_value->shaderTileImageReadSampleFromPixelRateInvocation);
        jdata["shaderTileImageReadFromHelperInvocation"] = static_cast<bool>(data->decoded_value->shaderTileImageReadFromHelperInvocation);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapUsageEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["count"], data->decoded_value->count, options);
        FieldToJson(jdata["subdivisionLevel"], data->decoded_value->subdivisionLevel, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapBuildInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(VkBuildMicromapFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        HandleToJson(jdata["dstMicromap"], data->dstMicromap, options);
        FieldToJson(jdata["usageCountsCount"], data->decoded_value->usageCountsCount, options);
        FieldToJson(jdata["pUsageCounts"], data->pUsageCounts, options);
        FieldToJson(jdata["ppUsageCounts"], data->ppUsageCounts, options);
        FieldToJson(jdata["data"], data->data, options);
        FieldToJson(jdata["scratchData"], data->scratchData, options);
        FieldToJson(jdata["triangleArray"], data->triangleArray, options);
        FieldToJson(jdata["triangleArrayStride"], data->decoded_value->triangleArrayStride, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkMicromapCreateFlagsEXT_t(),jdata["createFlags"], data->decoded_value->createFlags, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["deviceAddress"], to_hex_variable_width(data->decoded_value->deviceAddress), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceOpacityMicromapFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["micromap"] = static_cast<bool>(data->decoded_value->micromap);
        jdata["micromapCaptureReplay"] = static_cast<bool>(data->decoded_value->micromapCaptureReplay);
        jdata["micromapHostCommands"] = static_cast<bool>(data->decoded_value->micromapHostCommands);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceOpacityMicromapPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxOpacity2StateSubdivisionLevel"], data->decoded_value->maxOpacity2StateSubdivisionLevel, options);
        FieldToJson(jdata["maxOpacity4StateSubdivisionLevel"], data->decoded_value->maxOpacity4StateSubdivisionLevel, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapVersionInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pVersionData"], data->pVersionData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMicromapToMemoryInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["src"], data->src, options);
        FieldToJson(jdata["dst"], data->dst, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMemoryToMicromapInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["src"], data->src, options);
        HandleToJson(jdata["dst"], data->dst, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMicromapInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["src"], data->src, options);
        HandleToJson(jdata["dst"], data->dst, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapBuildSizesInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["micromapSize"], data->decoded_value->micromapSize, options);
        FieldToJson(jdata["buildScratchSize"], data->decoded_value->buildScratchSize, options);
        jdata["discardable"] = static_cast<bool>(data->decoded_value->discardable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["indexType"], data->decoded_value->indexType, options);
        FieldToJson(jdata["indexBuffer"], data->indexBuffer, options);
        FieldToJson(jdata["indexStride"], data->decoded_value->indexStride, options);
        FieldToJson(jdata["baseTriangle"], data->decoded_value->baseTriangle, options);
        FieldToJson(jdata["usageCountsCount"], data->decoded_value->usageCountsCount, options);
        FieldToJson(jdata["pUsageCounts"], data->pUsageCounts, options);
        FieldToJson(jdata["ppUsageCounts"], data->ppUsageCounts, options);
        HandleToJson(jdata["micromap"], data->micromap, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMicromapTriangleEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["dataOffset"], data->decoded_value->dataOffset, options);
        FieldToJson(jdata["subdivisionLevel"], data->decoded_value->subdivisionLevel, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["displacementMicromap"] = static_cast<bool>(data->decoded_value->displacementMicromap);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxDisplacementMicromapSubdivisionLevel"], data->decoded_value->maxDisplacementMicromapSubdivisionLevel, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["displacementBiasAndScaleFormat"], data->decoded_value->displacementBiasAndScaleFormat, options);
        FieldToJson(jdata["displacementVectorFormat"], data->decoded_value->displacementVectorFormat, options);
        FieldToJson(jdata["displacementBiasAndScaleBuffer"], data->displacementBiasAndScaleBuffer, options);
        FieldToJson(jdata["displacementBiasAndScaleStride"], data->decoded_value->displacementBiasAndScaleStride, options);
        FieldToJson(jdata["displacementVectorBuffer"], data->displacementVectorBuffer, options);
        FieldToJson(jdata["displacementVectorStride"], data->decoded_value->displacementVectorStride, options);
        FieldToJson(jdata["displacedMicromapPrimitiveFlags"], data->displacedMicromapPrimitiveFlags, options);
        FieldToJson(jdata["displacedMicromapPrimitiveFlagsStride"], data->decoded_value->displacedMicromapPrimitiveFlagsStride, options);
        FieldToJson(jdata["indexType"], data->decoded_value->indexType, options);
        FieldToJson(jdata["indexBuffer"], data->indexBuffer, options);
        FieldToJson(jdata["indexStride"], data->decoded_value->indexStride, options);
        FieldToJson(jdata["baseTriangle"], data->decoded_value->baseTriangle, options);
        FieldToJson(jdata["usageCountsCount"], data->decoded_value->usageCountsCount, options);
        FieldToJson(jdata["pUsageCounts"], data->pUsageCounts, options);
        FieldToJson(jdata["ppUsageCounts"], data->ppUsageCounts, options);
        HandleToJson(jdata["micromap"], data->micromap, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceClusterCullingShaderFeaturesHUAWEI* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["clustercullingShader"] = static_cast<bool>(data->decoded_value->clustercullingShader);
        jdata["multiviewClusterCullingShader"] = static_cast<bool>(data->decoded_value->multiviewClusterCullingShader);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceClusterCullingShaderPropertiesHUAWEI* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxWorkGroupCount"], &data->maxWorkGroupCount, options);
        FieldToJson(jdata["maxWorkGroupSize"], &data->maxWorkGroupSize, options);
        FieldToJson(jdata["maxOutputClusterCount"], data->decoded_value->maxOutputClusterCount, options);
        FieldToJson(jdata["indirectBufferOffsetAlignment"], data->decoded_value->indirectBufferOffsetAlignment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["clusterShadingRate"] = static_cast<bool>(data->decoded_value->clusterShadingRate);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["borderColorSwizzle"] = static_cast<bool>(data->decoded_value->borderColorSwizzle);
        jdata["borderColorSwizzleFromImage"] = static_cast<bool>(data->decoded_value->borderColorSwizzleFromImage);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["components"], data->components, options);
        jdata["srgb"] = static_cast<bool>(data->decoded_value->srgb);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pageableDeviceLocalMemory"] = static_cast<bool>(data->decoded_value->pageableDeviceLocalMemory);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderCorePropertiesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pixelRate"], data->decoded_value->pixelRate, options);
        FieldToJson(jdata["texelRate"], data->decoded_value->texelRate, options);
        FieldToJson(jdata["fmaRate"], data->decoded_value->fmaRate, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shaderCoreCount"], data->decoded_value->shaderCoreCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["schedulingControls"] = static_cast<bool>(data->decoded_value->schedulingControls);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPhysicalDeviceSchedulingControlsFlagsARM_t(),jdata["schedulingControlsFlags"], data->decoded_value->schedulingControlsFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["imageSlicedViewOf3D"] = static_cast<bool>(data->decoded_value->imageSlicedViewOf3D);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewSlicedCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["sliceOffset"], data->decoded_value->sliceOffset, options);
        FieldToJson(jdata["sliceCount"], data->decoded_value->sliceCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["descriptorSetHostMapping"] = static_cast<bool>(data->decoded_value->descriptorSetHostMapping);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetBindingReferenceVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["descriptorSetLayout"], data->descriptorSetLayout, options);
        FieldToJson(jdata["binding"], data->decoded_value->binding, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDescriptorSetLayoutHostMappingInfoVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["descriptorOffset"], data->decoded_value->descriptorOffset, options);
        FieldToJson(jdata["descriptorSize"], data->decoded_value->descriptorSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["nonSeamlessCubeMap"] = static_cast<bool>(data->decoded_value->nonSeamlessCubeMap);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["renderPassStriped"] = static_cast<bool>(data->decoded_value->renderPassStriped);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["renderPassStripeGranularity"], data->renderPassStripeGranularity, options);
        FieldToJson(jdata["maxRenderPassStripes"], data->decoded_value->maxRenderPassStripes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassStripeInfoARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stripeArea"], data->stripeArea, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassStripeBeginInfoARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stripeInfoCount"], data->decoded_value->stripeInfoCount, options);
        FieldToJson(jdata["pStripeInfos"], data->pStripeInfos, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassStripeSubmitInfoARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stripeSemaphoreInfoCount"], data->decoded_value->stripeSemaphoreInfoCount, options);
        FieldToJson(jdata["pStripeSemaphoreInfos"], data->pStripeSemaphoreInfos, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["fragmentDensityMapOffset"] = static_cast<bool>(data->decoded_value->fragmentDensityMapOffset);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["fragmentDensityOffsetGranularity"], data->fragmentDensityOffsetGranularity, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassFragmentDensityMapOffsetEndInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["fragmentDensityOffsetCount"], data->decoded_value->fragmentDensityOffsetCount, options);
        FieldToJson(jdata["pFragmentDensityOffsets"], data->pFragmentDensityOffsets, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["deviceGeneratedCompute"] = static_cast<bool>(data->decoded_value->deviceGeneratedCompute);
        jdata["deviceGeneratedComputePipelines"] = static_cast<bool>(data->decoded_value->deviceGeneratedComputePipelines);
        jdata["deviceGeneratedComputeCaptureReplay"] = static_cast<bool>(data->decoded_value->deviceGeneratedComputeCaptureReplay);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkComputePipelineIndirectBufferInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["deviceAddress"], to_hex_variable_width(data->decoded_value->deviceAddress), options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pipelineDeviceAddressCaptureReplay"], to_hex_variable_width(data->decoded_value->pipelineDeviceAddressCaptureReplay), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineIndirectDeviceAddressInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pipelineBindPoint"], data->decoded_value->pipelineBindPoint, options);
        HandleToJson(jdata["pipeline"], data->pipeline, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindPipelineIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pipelineAddress"], to_hex_variable_width(data->decoded_value->pipelineAddress), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["spheres"] = static_cast<bool>(data->decoded_value->spheres);
        jdata["linearSweptSpheres"] = static_cast<bool>(data->decoded_value->linearSweptSpheres);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometryLinearSweptSpheresDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["vertexFormat"], data->decoded_value->vertexFormat, options);
        FieldToJson(jdata["vertexData"], data->vertexData, options);
        FieldToJson(jdata["vertexStride"], data->decoded_value->vertexStride, options);
        FieldToJson(jdata["radiusFormat"], data->decoded_value->radiusFormat, options);
        FieldToJson(jdata["radiusData"], data->radiusData, options);
        FieldToJson(jdata["radiusStride"], data->decoded_value->radiusStride, options);
        FieldToJson(jdata["indexType"], data->decoded_value->indexType, options);
        FieldToJson(jdata["indexData"], data->indexData, options);
        FieldToJson(jdata["indexStride"], data->decoded_value->indexStride, options);
        FieldToJson(jdata["indexingMode"], data->decoded_value->indexingMode, options);
        FieldToJson(jdata["endCapsMode"], data->decoded_value->endCapsMode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometrySpheresDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["vertexFormat"], data->decoded_value->vertexFormat, options);
        FieldToJson(jdata["vertexData"], data->vertexData, options);
        FieldToJson(jdata["vertexStride"], data->decoded_value->vertexStride, options);
        FieldToJson(jdata["radiusFormat"], data->decoded_value->radiusFormat, options);
        FieldToJson(jdata["radiusData"], data->radiusData, options);
        FieldToJson(jdata["radiusStride"], data->decoded_value->radiusStride, options);
        FieldToJson(jdata["indexType"], data->decoded_value->indexType, options);
        FieldToJson(jdata["indexData"], data->indexData, options);
        FieldToJson(jdata["indexStride"], data->decoded_value->indexStride, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["linearColorAttachment"] = static_cast<bool>(data->decoded_value->linearColorAttachment);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["imageCompressionControlSwapchain"] = static_cast<bool>(data->decoded_value->imageCompressionControlSwapchain);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageViewSampleWeightCreateInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["filterCenter"], data->filterCenter, options);
        FieldToJson(jdata["filterSize"], data->filterSize, options);
        FieldToJson(jdata["numPhases"], data->decoded_value->numPhases, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageProcessingFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["textureSampleWeighted"] = static_cast<bool>(data->decoded_value->textureSampleWeighted);
        jdata["textureBoxFilter"] = static_cast<bool>(data->decoded_value->textureBoxFilter);
        jdata["textureBlockMatch"] = static_cast<bool>(data->decoded_value->textureBlockMatch);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageProcessingPropertiesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxWeightFilterPhases"], data->decoded_value->maxWeightFilterPhases, options);
        FieldToJson(jdata["maxWeightFilterDimension"], data->maxWeightFilterDimension, options);
        FieldToJson(jdata["maxBlockMatchRegion"], data->maxBlockMatchRegion, options);
        FieldToJson(jdata["maxBoxFilterBlockSize"], data->maxBoxFilterBlockSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["nestedCommandBuffer"] = static_cast<bool>(data->decoded_value->nestedCommandBuffer);
        jdata["nestedCommandBufferRendering"] = static_cast<bool>(data->decoded_value->nestedCommandBufferRendering);
        jdata["nestedCommandBufferSimultaneousUse"] = static_cast<bool>(data->decoded_value->nestedCommandBufferSimultaneousUse);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxCommandBufferNestingLevel"], data->decoded_value->maxCommandBufferNestingLevel, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkExternalMemoryAcquireUnmodifiedEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["acquireUnmodifiedMemory"] = static_cast<bool>(data->decoded_value->acquireUnmodifiedMemory);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExtendedDynamicState3FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["extendedDynamicState3TessellationDomainOrigin"] = static_cast<bool>(data->decoded_value->extendedDynamicState3TessellationDomainOrigin);
        jdata["extendedDynamicState3DepthClampEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3DepthClampEnable);
        jdata["extendedDynamicState3PolygonMode"] = static_cast<bool>(data->decoded_value->extendedDynamicState3PolygonMode);
        jdata["extendedDynamicState3RasterizationSamples"] = static_cast<bool>(data->decoded_value->extendedDynamicState3RasterizationSamples);
        jdata["extendedDynamicState3SampleMask"] = static_cast<bool>(data->decoded_value->extendedDynamicState3SampleMask);
        jdata["extendedDynamicState3AlphaToCoverageEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3AlphaToCoverageEnable);
        jdata["extendedDynamicState3AlphaToOneEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3AlphaToOneEnable);
        jdata["extendedDynamicState3LogicOpEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3LogicOpEnable);
        jdata["extendedDynamicState3ColorBlendEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3ColorBlendEnable);
        jdata["extendedDynamicState3ColorBlendEquation"] = static_cast<bool>(data->decoded_value->extendedDynamicState3ColorBlendEquation);
        jdata["extendedDynamicState3ColorWriteMask"] = static_cast<bool>(data->decoded_value->extendedDynamicState3ColorWriteMask);
        jdata["extendedDynamicState3RasterizationStream"] = static_cast<bool>(data->decoded_value->extendedDynamicState3RasterizationStream);
        jdata["extendedDynamicState3ConservativeRasterizationMode"] = static_cast<bool>(data->decoded_value->extendedDynamicState3ConservativeRasterizationMode);
        jdata["extendedDynamicState3ExtraPrimitiveOverestimationSize"] = static_cast<bool>(data->decoded_value->extendedDynamicState3ExtraPrimitiveOverestimationSize);
        jdata["extendedDynamicState3DepthClipEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3DepthClipEnable);
        jdata["extendedDynamicState3SampleLocationsEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3SampleLocationsEnable);
        jdata["extendedDynamicState3ColorBlendAdvanced"] = static_cast<bool>(data->decoded_value->extendedDynamicState3ColorBlendAdvanced);
        jdata["extendedDynamicState3ProvokingVertexMode"] = static_cast<bool>(data->decoded_value->extendedDynamicState3ProvokingVertexMode);
        jdata["extendedDynamicState3LineRasterizationMode"] = static_cast<bool>(data->decoded_value->extendedDynamicState3LineRasterizationMode);
        jdata["extendedDynamicState3LineStippleEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3LineStippleEnable);
        jdata["extendedDynamicState3DepthClipNegativeOneToOne"] = static_cast<bool>(data->decoded_value->extendedDynamicState3DepthClipNegativeOneToOne);
        jdata["extendedDynamicState3ViewportWScalingEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3ViewportWScalingEnable);
        jdata["extendedDynamicState3ViewportSwizzle"] = static_cast<bool>(data->decoded_value->extendedDynamicState3ViewportSwizzle);
        jdata["extendedDynamicState3CoverageToColorEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3CoverageToColorEnable);
        jdata["extendedDynamicState3CoverageToColorLocation"] = static_cast<bool>(data->decoded_value->extendedDynamicState3CoverageToColorLocation);
        jdata["extendedDynamicState3CoverageModulationMode"] = static_cast<bool>(data->decoded_value->extendedDynamicState3CoverageModulationMode);
        jdata["extendedDynamicState3CoverageModulationTableEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3CoverageModulationTableEnable);
        jdata["extendedDynamicState3CoverageModulationTable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3CoverageModulationTable);
        jdata["extendedDynamicState3CoverageReductionMode"] = static_cast<bool>(data->decoded_value->extendedDynamicState3CoverageReductionMode);
        jdata["extendedDynamicState3RepresentativeFragmentTestEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3RepresentativeFragmentTestEnable);
        jdata["extendedDynamicState3ShadingRateImageEnable"] = static_cast<bool>(data->decoded_value->extendedDynamicState3ShadingRateImageEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExtendedDynamicState3PropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["dynamicPrimitiveTopologyUnrestricted"] = static_cast<bool>(data->decoded_value->dynamicPrimitiveTopologyUnrestricted);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkColorBlendEquationEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["srcColorBlendFactor"], data->decoded_value->srcColorBlendFactor, options);
        FieldToJson(jdata["dstColorBlendFactor"], data->decoded_value->dstColorBlendFactor, options);
        FieldToJson(jdata["colorBlendOp"], data->decoded_value->colorBlendOp, options);
        FieldToJson(jdata["srcAlphaBlendFactor"], data->decoded_value->srcAlphaBlendFactor, options);
        FieldToJson(jdata["dstAlphaBlendFactor"], data->decoded_value->dstAlphaBlendFactor, options);
        FieldToJson(jdata["alphaBlendOp"], data->decoded_value->alphaBlendOp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkColorBlendAdvancedEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["advancedBlendOp"], data->decoded_value->advancedBlendOp, options);
        jdata["srcPremultiplied"] = static_cast<bool>(data->decoded_value->srcPremultiplied);
        jdata["dstPremultiplied"] = static_cast<bool>(data->decoded_value->dstPremultiplied);
        FieldToJson(jdata["blendOverlap"], data->decoded_value->blendOverlap, options);
        jdata["clampResults"] = static_cast<bool>(data->decoded_value->clampResults);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["subpassMergeFeedback"] = static_cast<bool>(data->decoded_value->subpassMergeFeedback);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassCreationControlEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["disallowMerging"] = static_cast<bool>(data->decoded_value->disallowMerging);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassCreationFeedbackInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["postMergeSubpassCount"], data->decoded_value->postMergeSubpassCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassCreationFeedbackCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pRenderPassFeedback"], data->pRenderPassFeedback, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassSubpassFeedbackInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["subpassMergeStatus"], data->decoded_value->subpassMergeStatus, options);
        FieldToJson(jdata["description"], &data->description, options);
        FieldToJson(jdata["postMergeIndex"], data->decoded_value->postMergeIndex, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pSubpassFeedback"], data->pSubpassFeedback, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDirectDriverLoadingInfoLUNARG* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkDirectDriverLoadingFlagsLUNARG_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pfnGetInstanceProcAddr"], to_hex_variable_width(data->pfnGetInstanceProcAddr), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDirectDriverLoadingListLUNARG* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        FieldToJson(jdata["driverCount"], data->decoded_value->driverCount, options);
        FieldToJson(jdata["pDrivers"], data->pDrivers, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderModuleIdentifierFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderModuleIdentifier"] = static_cast<bool>(data->decoded_value->shaderModuleIdentifier);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderModuleIdentifierPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shaderModuleIdentifierAlgorithmUUID"], uuid_to_string(sizeof(data->decoded_value->shaderModuleIdentifierAlgorithmUUID), data->decoded_value->shaderModuleIdentifierAlgorithmUUID), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["identifierSize"], data->decoded_value->identifierSize, options);
        FieldToJson(jdata["pIdentifier"], data->pIdentifier, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShaderModuleIdentifierEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["identifierSize"], data->decoded_value->identifierSize, options);
        FieldToJson(jdata["identifier"], &data->identifier, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceOpticalFlowFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["opticalFlow"] = static_cast<bool>(data->decoded_value->opticalFlow);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceOpticalFlowPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkOpticalFlowGridSizeFlagsNV_t(),jdata["supportedOutputGridSizes"], data->decoded_value->supportedOutputGridSizes, options);
        FieldToJson(VkOpticalFlowGridSizeFlagsNV_t(),jdata["supportedHintGridSizes"], data->decoded_value->supportedHintGridSizes, options);
        jdata["hintSupported"] = static_cast<bool>(data->decoded_value->hintSupported);
        jdata["costSupported"] = static_cast<bool>(data->decoded_value->costSupported);
        jdata["bidirectionalFlowSupported"] = static_cast<bool>(data->decoded_value->bidirectionalFlowSupported);
        jdata["globalFlowSupported"] = static_cast<bool>(data->decoded_value->globalFlowSupported);
        FieldToJson(jdata["minWidth"], data->decoded_value->minWidth, options);
        FieldToJson(jdata["minHeight"], data->decoded_value->minHeight, options);
        FieldToJson(jdata["maxWidth"], data->decoded_value->maxWidth, options);
        FieldToJson(jdata["maxHeight"], data->decoded_value->maxHeight, options);
        FieldToJson(jdata["maxNumRegionsOfInterest"], data->decoded_value->maxNumRegionsOfInterest, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOpticalFlowImageFormatInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkOpticalFlowUsageFlagsNV_t(),jdata["usage"], data->decoded_value->usage, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOpticalFlowImageFormatPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["format"], data->decoded_value->format, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOpticalFlowSessionCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["imageFormat"], data->decoded_value->imageFormat, options);
        FieldToJson(jdata["flowVectorFormat"], data->decoded_value->flowVectorFormat, options);
        FieldToJson(jdata["costFormat"], data->decoded_value->costFormat, options);
        FieldToJson(VkOpticalFlowGridSizeFlagsNV_t(),jdata["outputGridSize"], data->decoded_value->outputGridSize, options);
        FieldToJson(VkOpticalFlowGridSizeFlagsNV_t(),jdata["hintGridSize"], data->decoded_value->hintGridSize, options);
        FieldToJson(jdata["performanceLevel"], data->decoded_value->performanceLevel, options);
        FieldToJson(VkOpticalFlowSessionCreateFlagsNV_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOpticalFlowSessionCreatePrivateDataInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["id"], data->decoded_value->id, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pPrivateData"], data->pPrivateData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOpticalFlowExecuteInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkOpticalFlowExecuteFlagsNV_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["regionCount"], data->decoded_value->regionCount, options);
        FieldToJson(jdata["pRegions"], data->pRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["legacyDithering"] = static_cast<bool>(data->decoded_value->legacyDithering);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["externalFormatResolve"] = static_cast<bool>(data->decoded_value->externalFormatResolve);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["nullColorAttachmentWithExternalFormatResolve"] = static_cast<bool>(data->decoded_value->nullColorAttachmentWithExternalFormatResolve);
        FieldToJson(jdata["externalFormatResolveChromaOffsetX"], data->decoded_value->externalFormatResolveChromaOffsetX, options);
        FieldToJson(jdata["externalFormatResolveChromaOffsetY"], data->decoded_value->externalFormatResolveChromaOffsetY, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["colorAttachmentFormat"], data->decoded_value->colorAttachmentFormat, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAntiLagFeaturesAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["antiLag"] = static_cast<bool>(data->decoded_value->antiLag);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAntiLagPresentationInfoAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stage"], data->decoded_value->stage, options);
        FieldToJson(jdata["frameIndex"], data->decoded_value->frameIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAntiLagDataAMD* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        FieldToJson(jdata["maxFPS"], data->decoded_value->maxFPS, options);
        FieldToJson(jdata["pPresentationInfo"], data->pPresentationInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderObject"] = static_cast<bool>(data->decoded_value->shaderObject);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shaderBinaryUUID"], uuid_to_string(sizeof(data->decoded_value->shaderBinaryUUID), data->decoded_value->shaderBinaryUUID), options);
        FieldToJson(jdata["shaderBinaryVersion"], data->decoded_value->shaderBinaryVersion, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkShaderCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderCreateFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["stage"], data->decoded_value->stage, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["nextStage"], data->decoded_value->nextStage, options);
        FieldToJson(jdata["codeType"], data->decoded_value->codeType, options);
        FieldToJson(jdata["codeSize"], data->decoded_value->codeSize, options);
        FieldToJson(jdata["pCode"], data->pCode, options);
        FieldToJson(jdata["pName"], &data->pName, options);
        FieldToJson(jdata["setLayoutCount"], data->decoded_value->setLayoutCount, options);
        HandleToJson(jdata["pSetLayouts"], &data->pSetLayouts, options);
        FieldToJson(jdata["pushConstantRangeCount"], data->decoded_value->pushConstantRangeCount, options);
        FieldToJson(jdata["pPushConstantRanges"], data->pPushConstantRanges, options);
        FieldToJson(jdata["pSpecializationInfo"], data->pSpecializationInfo, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDepthClampRangeEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["minDepthClamp"], data->decoded_value->minDepthClamp, options);
        FieldToJson(jdata["maxDepthClamp"], data->decoded_value->maxDepthClamp, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["tileProperties"] = static_cast<bool>(data->decoded_value->tileProperties);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTilePropertiesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["tileSize"], data->tileSize, options);
        FieldToJson(jdata["apronSize"], data->apronSize, options);
        FieldToJson(jdata["origin"], data->origin, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["amigoProfiling"] = static_cast<bool>(data->decoded_value->amigoProfiling);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAmigoProfilingSubmitInfoSEC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["firstDrawTimestamp"], data->decoded_value->firstDrawTimestamp, options);
        FieldToJson(jdata["swapBufferTimestamp"], data->decoded_value->swapBufferTimestamp, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["multiviewPerViewViewports"] = static_cast<bool>(data->decoded_value->multiviewPerViewViewports);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["rayTracingInvocationReorderReorderingHint"], data->decoded_value->rayTracingInvocationReorderReorderingHint, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["rayTracingInvocationReorder"] = static_cast<bool>(data->decoded_value->rayTracingInvocationReorder);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCooperativeVectorPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["cooperativeVectorSupportedStages"], data->decoded_value->cooperativeVectorSupportedStages, options);
        jdata["cooperativeVectorTrainingFloat16Accumulation"] = static_cast<bool>(data->decoded_value->cooperativeVectorTrainingFloat16Accumulation);
        jdata["cooperativeVectorTrainingFloat32Accumulation"] = static_cast<bool>(data->decoded_value->cooperativeVectorTrainingFloat32Accumulation);
        FieldToJson(jdata["maxCooperativeVectorComponents"], data->decoded_value->maxCooperativeVectorComponents, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCooperativeVectorFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["cooperativeVector"] = static_cast<bool>(data->decoded_value->cooperativeVector);
        jdata["cooperativeVectorTraining"] = static_cast<bool>(data->decoded_value->cooperativeVectorTraining);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCooperativeVectorPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["inputType"], data->decoded_value->inputType, options);
        FieldToJson(jdata["inputInterpretation"], data->decoded_value->inputInterpretation, options);
        FieldToJson(jdata["matrixInterpretation"], data->decoded_value->matrixInterpretation, options);
        FieldToJson(jdata["biasInterpretation"], data->decoded_value->biasInterpretation, options);
        FieldToJson(jdata["resultType"], data->decoded_value->resultType, options);
        jdata["transpose"] = static_cast<bool>(data->decoded_value->transpose);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkConvertCooperativeVectorMatrixInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["srcSize"], data->decoded_value->srcSize, options);
        FieldToJson(jdata["srcData"], data->srcData, options);
        FieldToJson(jdata["pDstSize"], data->pDstSize, options);
        FieldToJson(jdata["dstData"], data->dstData, options);
        FieldToJson(jdata["srcComponentType"], data->decoded_value->srcComponentType, options);
        FieldToJson(jdata["dstComponentType"], data->decoded_value->dstComponentType, options);
        FieldToJson(jdata["numRows"], data->decoded_value->numRows, options);
        FieldToJson(jdata["numColumns"], data->decoded_value->numColumns, options);
        FieldToJson(jdata["srcLayout"], data->decoded_value->srcLayout, options);
        FieldToJson(jdata["srcStride"], data->decoded_value->srcStride, options);
        FieldToJson(jdata["dstLayout"], data->decoded_value->dstLayout, options);
        FieldToJson(jdata["dstStride"], data->decoded_value->dstStride, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["extendedSparseAddressSpace"] = static_cast<bool>(data->decoded_value->extendedSparseAddressSpace);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["extendedSparseAddressSpaceSize"], data->decoded_value->extendedSparseAddressSpaceSize, options);
        FieldToJson(VkImageUsageFlags_t(),jdata["extendedSparseImageUsageFlags"], data->decoded_value->extendedSparseImageUsageFlags, options);
        FieldToJson(VkBufferUsageFlags_t(),jdata["extendedSparseBufferUsageFlags"], data->decoded_value->extendedSparseBufferUsageFlags, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["legacyVertexAttributes"] = static_cast<bool>(data->decoded_value->legacyVertexAttributes);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["nativeUnalignedPerformance"] = static_cast<bool>(data->decoded_value->nativeUnalignedPerformance);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkLayerSettingEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["pLayerName"], &data->pLayerName, options);
        FieldToJson(jdata["pSettingName"], &data->pSettingName, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["valueCount"], data->decoded_value->valueCount, options);
        FieldToJson(jdata["pValues"], data->pValues, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkLayerSettingsCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["settingCount"], data->decoded_value->settingCount, options);
        FieldToJson(jdata["pSettings"], data->pSettings, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderCoreBuiltinsFeaturesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderCoreBuiltins"] = static_cast<bool>(data->decoded_value->shaderCoreBuiltins);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderCoreBuiltinsPropertiesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shaderCoreMask"], data->decoded_value->shaderCoreMask, options);
        FieldToJson(jdata["shaderCoreCount"], data->decoded_value->shaderCoreCount, options);
        FieldToJson(jdata["shaderWarpsPerCore"], data->decoded_value->shaderWarpsPerCore, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pipelineLibraryGroupHandles"] = static_cast<bool>(data->decoded_value->pipelineLibraryGroupHandles);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["dynamicRenderingUnusedAttachments"] = static_cast<bool>(data->decoded_value->dynamicRenderingUnusedAttachments);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkLatencySleepModeInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["lowLatencyMode"] = static_cast<bool>(data->decoded_value->lowLatencyMode);
        jdata["lowLatencyBoost"] = static_cast<bool>(data->decoded_value->lowLatencyBoost);
        FieldToJson(jdata["minimumIntervalUs"], data->decoded_value->minimumIntervalUs, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkLatencySleepInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["signalSemaphore"], data->signalSemaphore, options);
        FieldToJson(jdata["value"], data->decoded_value->value, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSetLatencyMarkerInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["presentID"], data->decoded_value->presentID, options);
        FieldToJson(jdata["marker"], data->decoded_value->marker, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkLatencyTimingsFrameReportNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["presentID"], data->decoded_value->presentID, options);
        FieldToJson(jdata["inputSampleTimeUs"], data->decoded_value->inputSampleTimeUs, options);
        FieldToJson(jdata["simStartTimeUs"], data->decoded_value->simStartTimeUs, options);
        FieldToJson(jdata["simEndTimeUs"], data->decoded_value->simEndTimeUs, options);
        FieldToJson(jdata["renderSubmitStartTimeUs"], data->decoded_value->renderSubmitStartTimeUs, options);
        FieldToJson(jdata["renderSubmitEndTimeUs"], data->decoded_value->renderSubmitEndTimeUs, options);
        FieldToJson(jdata["presentStartTimeUs"], data->decoded_value->presentStartTimeUs, options);
        FieldToJson(jdata["presentEndTimeUs"], data->decoded_value->presentEndTimeUs, options);
        FieldToJson(jdata["driverStartTimeUs"], data->decoded_value->driverStartTimeUs, options);
        FieldToJson(jdata["driverEndTimeUs"], data->decoded_value->driverEndTimeUs, options);
        FieldToJson(jdata["osRenderQueueStartTimeUs"], data->decoded_value->osRenderQueueStartTimeUs, options);
        FieldToJson(jdata["osRenderQueueEndTimeUs"], data->decoded_value->osRenderQueueEndTimeUs, options);
        FieldToJson(jdata["gpuRenderStartTimeUs"], data->decoded_value->gpuRenderStartTimeUs, options);
        FieldToJson(jdata["gpuRenderEndTimeUs"], data->decoded_value->gpuRenderEndTimeUs, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGetLatencyMarkerInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["timingCount"], data->decoded_value->timingCount, options);
        FieldToJson(jdata["pTimings"], data->pTimings, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkLatencySubmissionPresentIdNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["presentID"], data->decoded_value->presentID, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSwapchainLatencyCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["latencyModeEnable"] = static_cast<bool>(data->decoded_value->latencyModeEnable);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkOutOfBandQueueTypeInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["queueType"], data->decoded_value->queueType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkLatencySurfaceCapabilitiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["presentModeCount"], data->decoded_value->presentModeCount, options);
        FieldToJson(jdata["pPresentModes"], data->pPresentModes, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["multiviewPerViewRenderAreas"] = static_cast<bool>(data->decoded_value->multiviewPerViewRenderAreas);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["perViewRenderAreaCount"], data->decoded_value->perViewRenderAreaCount, options);
        FieldToJson(jdata["pPerViewRenderAreas"], data->pPerViewRenderAreas, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["perStageDescriptorSet"] = static_cast<bool>(data->decoded_value->perStageDescriptorSet);
        jdata["dynamicPipelineLayout"] = static_cast<bool>(data->decoded_value->dynamicPipelineLayout);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["textureBlockMatch2"] = static_cast<bool>(data->decoded_value->textureBlockMatch2);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxBlockMatchWindow"], data->maxBlockMatchWindow, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["windowExtent"], data->windowExtent, options);
        FieldToJson(jdata["windowCompareMode"], data->decoded_value->windowCompareMode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["selectableCubicWeights"] = static_cast<bool>(data->decoded_value->selectableCubicWeights);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerCubicWeightsCreateInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["cubicWeights"], data->decoded_value->cubicWeights, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBlitImageCubicWeightsInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["cubicWeights"], data->decoded_value->cubicWeights, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["ycbcrDegamma"] = static_cast<bool>(data->decoded_value->ycbcrDegamma);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["enableYDegamma"] = static_cast<bool>(data->decoded_value->enableYDegamma);
        jdata["enableCbCrDegamma"] = static_cast<bool>(data->decoded_value->enableCbCrDegamma);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["cubicRangeClamp"] = static_cast<bool>(data->decoded_value->cubicRangeClamp);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["attachmentFeedbackLoopDynamicState"] = static_cast<bool>(data->decoded_value->attachmentFeedbackLoopDynamicState);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["underlyingAPI"], data->decoded_value->underlyingAPI, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["descriptorPoolOverallocation"] = static_cast<bool>(data->decoded_value->descriptorPoolOverallocation);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["tileMemoryHeap"] = static_cast<bool>(data->decoded_value->tileMemoryHeap);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["queueSubmitBoundary"] = static_cast<bool>(data->decoded_value->queueSubmitBoundary);
        jdata["tileBufferTransfers"] = static_cast<bool>(data->decoded_value->tileBufferTransfers);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTileMemoryRequirementsQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["alignment"], data->decoded_value->alignment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTileMemoryBindInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTileMemorySizeInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDecompressMemoryRegionEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["srcAddress"], to_hex_variable_width(data->decoded_value->srcAddress), options);
        FieldToJson(jdata["dstAddress"], to_hex_variable_width(data->decoded_value->dstAddress), options);
        FieldToJson(jdata["compressedSize"], data->decoded_value->compressedSize, options);
        FieldToJson(jdata["decompressedSize"], data->decoded_value->decompressedSize, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDecompressMemoryInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkMemoryDecompressionMethodFlagsEXT_t(),jdata["decompressionMethod"], data->decoded_value->decompressionMethod, options);
        FieldToJson(jdata["regionCount"], data->decoded_value->regionCount, options);
        FieldToJson(jdata["pRegions"], data->pRegions, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMemoryDecompressionFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["memoryDecompression"] = static_cast<bool>(data->decoded_value->memoryDecompression);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMemoryDecompressionPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkMemoryDecompressionMethodFlagsEXT_t(),jdata["decompressionMethods"], data->decoded_value->decompressionMethods, options);
        FieldToJson(jdata["maxDecompressionIndirectCount"], data->decoded_value->maxDecompressionIndirectCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplaySurfaceStereoCreateInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["stereoType"], data->decoded_value->stereoType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDisplayModeStereoPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["hdmi3DSupported"] = static_cast<bool>(data->decoded_value->hdmi3DSupported);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderRawAccessChains"] = static_cast<bool>(data->decoded_value->shaderRawAccessChains);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["commandBufferInheritance"] = static_cast<bool>(data->decoded_value->commandBufferInheritance);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderFloat16VectorAtomics"] = static_cast<bool>(data->decoded_value->shaderFloat16VectorAtomics);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderReplicatedComposites"] = static_cast<bool>(data->decoded_value->shaderReplicatedComposites);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderFloat8FeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderFloat8"] = static_cast<bool>(data->decoded_value->shaderFloat8);
        jdata["shaderFloat8CooperativeMatrix"] = static_cast<bool>(data->decoded_value->shaderFloat8CooperativeMatrix);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["rayTracingValidation"] = static_cast<bool>(data->decoded_value->rayTracingValidation);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["partitionedAccelerationStructure"] = static_cast<bool>(data->decoded_value->partitionedAccelerationStructure);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxPartitionCount"], data->decoded_value->maxPartitionCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPartitionedAccelerationStructureFlagsNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["enablePartitionTranslation"] = static_cast<bool>(data->decoded_value->enablePartitionTranslation);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkStridedDeviceAddressNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["startAddress"], to_hex_variable_width(data->decoded_value->startAddress), options);
        FieldToJson(jdata["strideInBytes"], data->decoded_value->strideInBytes, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBuildPartitionedAccelerationStructureIndirectCommandNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["opType"], data->decoded_value->opType, options);
        FieldToJson(jdata["argCount"], data->decoded_value->argCount, options);
        FieldToJson(jdata["argData"], data->argData, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPartitionedAccelerationStructureWriteInstanceDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["transform"], data->transform, options);
        FieldToJson(jdata["explicitAABB"], &data->explicitAABB, options);
        FieldToJson(jdata["instanceID"], data->decoded_value->instanceID, options);
        FieldToJson(jdata["instanceMask"], data->decoded_value->instanceMask, options);
        FieldToJson(jdata["instanceContributionToHitGroupIndex"], data->decoded_value->instanceContributionToHitGroupIndex, options);
        FieldToJson(VkPartitionedAccelerationStructureInstanceFlagsNV_t(),jdata["instanceFlags"], data->decoded_value->instanceFlags, options);
        FieldToJson(jdata["instanceIndex"], data->decoded_value->instanceIndex, options);
        FieldToJson(jdata["partitionIndex"], data->decoded_value->partitionIndex, options);
        FieldToJson(jdata["accelerationStructure"], to_hex_variable_width(data->decoded_value->accelerationStructure), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPartitionedAccelerationStructureUpdateInstanceDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["instanceIndex"], data->decoded_value->instanceIndex, options);
        FieldToJson(jdata["instanceContributionToHitGroupIndex"], data->decoded_value->instanceContributionToHitGroupIndex, options);
        FieldToJson(jdata["accelerationStructure"], to_hex_variable_width(data->decoded_value->accelerationStructure), options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPartitionedAccelerationStructureWritePartitionTranslationDataNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["partitionIndex"], data->decoded_value->partitionIndex, options);
        FieldToJson(jdata["partitionTranslation"], &data->partitionTranslation, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteDescriptorSetPartitionedAccelerationStructureNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["accelerationStructureCount"], data->decoded_value->accelerationStructureCount, options);
        FieldToJson(jdata["pAccelerationStructures"], data->pAccelerationStructures, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPartitionedAccelerationStructureInstancesInputNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkBuildAccelerationStructureFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["instanceCount"], data->decoded_value->instanceCount, options);
        FieldToJson(jdata["maxInstancePerPartitionCount"], data->decoded_value->maxInstancePerPartitionCount, options);
        FieldToJson(jdata["partitionCount"], data->decoded_value->partitionCount, options);
        FieldToJson(jdata["maxInstanceInGlobalPartitionCount"], data->decoded_value->maxInstanceInGlobalPartitionCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBuildPartitionedAccelerationStructureInfoNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["input"], data->input, options);
        FieldToJson(jdata["srcAccelerationStructureData"], to_hex_variable_width(data->decoded_value->srcAccelerationStructureData), options);
        FieldToJson(jdata["dstAccelerationStructureData"], to_hex_variable_width(data->decoded_value->dstAccelerationStructureData), options);
        FieldToJson(jdata["scratchData"], to_hex_variable_width(data->decoded_value->scratchData), options);
        FieldToJson(jdata["srcInfos"], to_hex_variable_width(data->decoded_value->srcInfos), options);
        FieldToJson(jdata["srcInfosCount"], to_hex_variable_width(data->decoded_value->srcInfosCount), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureBuildSizesInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["accelerationStructureSize"], data->decoded_value->accelerationStructureSize, options);
        FieldToJson(jdata["updateScratchSize"], data->decoded_value->updateScratchSize, options);
        FieldToJson(jdata["buildScratchSize"], data->decoded_value->buildScratchSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["deviceGeneratedCommands"] = static_cast<bool>(data->decoded_value->deviceGeneratedCommands);
        jdata["dynamicGeneratedPipelineLayout"] = static_cast<bool>(data->decoded_value->dynamicGeneratedPipelineLayout);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxIndirectPipelineCount"], data->decoded_value->maxIndirectPipelineCount, options);
        FieldToJson(jdata["maxIndirectShaderObjectCount"], data->decoded_value->maxIndirectShaderObjectCount, options);
        FieldToJson(jdata["maxIndirectSequenceCount"], data->decoded_value->maxIndirectSequenceCount, options);
        FieldToJson(jdata["maxIndirectCommandsTokenCount"], data->decoded_value->maxIndirectCommandsTokenCount, options);
        FieldToJson(jdata["maxIndirectCommandsTokenOffset"], data->decoded_value->maxIndirectCommandsTokenOffset, options);
        FieldToJson(jdata["maxIndirectCommandsIndirectStride"], data->decoded_value->maxIndirectCommandsIndirectStride, options);
        FieldToJson(VkIndirectCommandsInputModeFlagsEXT_t(),jdata["supportedIndirectCommandsInputModes"], data->decoded_value->supportedIndirectCommandsInputModes, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["supportedIndirectCommandsShaderStages"], data->decoded_value->supportedIndirectCommandsShaderStages, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["supportedIndirectCommandsShaderStagesPipelineBinding"], data->decoded_value->supportedIndirectCommandsShaderStagesPipelineBinding, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["supportedIndirectCommandsShaderStagesShaderBinding"], data->decoded_value->supportedIndirectCommandsShaderStagesShaderBinding, options);
        jdata["deviceGeneratedCommandsTransformFeedback"] = static_cast<bool>(data->decoded_value->deviceGeneratedCommandsTransformFeedback);
        jdata["deviceGeneratedCommandsMultiDrawIndirectCount"] = static_cast<bool>(data->decoded_value->deviceGeneratedCommandsMultiDrawIndirectCount);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeneratedCommandsMemoryRequirementsInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["indirectExecutionSet"], data->indirectExecutionSet, options);
        HandleToJson(jdata["indirectCommandsLayout"], data->indirectCommandsLayout, options);
        FieldToJson(jdata["maxSequenceCount"], data->decoded_value->maxSequenceCount, options);
        FieldToJson(jdata["maxDrawCount"], data->decoded_value->maxDrawCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectExecutionSetPipelineInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["initialPipeline"], data->initialPipeline, options);
        FieldToJson(jdata["maxPipelineCount"], data->decoded_value->maxPipelineCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectExecutionSetShaderLayoutInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["setLayoutCount"], data->decoded_value->setLayoutCount, options);
        HandleToJson(jdata["pSetLayouts"], &data->pSetLayouts, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectExecutionSetShaderInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shaderCount"], data->decoded_value->shaderCount, options);
        HandleToJson(jdata["pInitialShaders"], &data->pInitialShaders, options);
        FieldToJson(jdata["pSetLayoutInfos"], data->pSetLayoutInfos, options);
        FieldToJson(jdata["maxShaderCount"], data->decoded_value->maxShaderCount, options);
        FieldToJson(jdata["pushConstantRangeCount"], data->decoded_value->pushConstantRangeCount, options);
        FieldToJson(jdata["pPushConstantRanges"], data->pPushConstantRanges, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeneratedCommandsInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["shaderStages"], data->decoded_value->shaderStages, options);
        HandleToJson(jdata["indirectExecutionSet"], data->indirectExecutionSet, options);
        HandleToJson(jdata["indirectCommandsLayout"], data->indirectCommandsLayout, options);
        FieldToJson(jdata["indirectAddress"], to_hex_variable_width(data->decoded_value->indirectAddress), options);
        FieldToJson(jdata["indirectAddressSize"], data->decoded_value->indirectAddressSize, options);
        FieldToJson(jdata["preprocessAddress"], to_hex_variable_width(data->decoded_value->preprocessAddress), options);
        FieldToJson(jdata["preprocessSize"], data->decoded_value->preprocessSize, options);
        FieldToJson(jdata["maxSequenceCount"], data->decoded_value->maxSequenceCount, options);
        FieldToJson(jdata["sequenceCountAddress"], to_hex_variable_width(data->decoded_value->sequenceCountAddress), options);
        FieldToJson(jdata["maxDrawCount"], data->decoded_value->maxDrawCount, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteIndirectExecutionSetPipelineEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["index"], data->decoded_value->index, options);
        HandleToJson(jdata["pipeline"], data->pipeline, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsPushConstantTokenEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["updateRange"], data->updateRange, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsVertexBufferTokenEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["vertexBindingUnit"], data->decoded_value->vertexBindingUnit, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsIndexBufferTokenEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsExecutionSetTokenEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["shaderStages"], data->decoded_value->shaderStages, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkIndirectCommandsLayoutCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkIndirectCommandsLayoutUsageFlagsEXT_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(VkShaderStageFlags_t(),jdata["shaderStages"], data->decoded_value->shaderStages, options);
        FieldToJson(jdata["indirectStride"], data->decoded_value->indirectStride, options);
        HandleToJson(jdata["pipelineLayout"], data->pipelineLayout, options);
        FieldToJson(jdata["tokenCount"], data->decoded_value->tokenCount, options);
        FieldToJson(jdata["pTokens"], data->pTokens, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrawIndirectCountIndirectCommandEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["bufferAddress"], to_hex_variable_width(data->decoded_value->bufferAddress), options);
        FieldToJson(jdata["stride"], data->decoded_value->stride, options);
        FieldToJson(jdata["commandCount"], data->decoded_value->commandCount, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindVertexBufferIndirectCommandEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["bufferAddress"], to_hex_variable_width(data->decoded_value->bufferAddress), options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["stride"], data->decoded_value->stride, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBindIndexBufferIndirectCommandEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["bufferAddress"], to_hex_variable_width(data->decoded_value->bufferAddress), options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["indexType"], data->decoded_value->indexType, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeneratedCommandsPipelineInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["pipeline"], data->pipeline, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkGeneratedCommandsShaderInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shaderCount"], data->decoded_value->shaderCount, options);
        HandleToJson(jdata["pShaders"], &data->pShaders, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteIndirectExecutionSetShaderEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["index"], data->decoded_value->index, options);
        HandleToJson(jdata["shader"], data->shader, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageAlignmentControlFeaturesMESA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["imageAlignmentControl"] = static_cast<bool>(data->decoded_value->imageAlignmentControl);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceImageAlignmentControlPropertiesMESA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["supportedImageAlignmentMask"], data->decoded_value->supportedImageAlignmentMask, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImageAlignmentControlCreateInfoMESA* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maximumRequestedAlignment"], data->decoded_value->maximumRequestedAlignment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["rayTracingInvocationReorderReorderingHint"], data->decoded_value->rayTracingInvocationReorderReorderingHint, options);
        FieldToJson(jdata["maxShaderBindingTableRecordIndex"], data->decoded_value->maxShaderBindingTableRecordIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDepthClampControlFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["depthClampControl"] = static_cast<bool>(data->decoded_value->depthClampControl);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineViewportDepthClampControlCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["depthClampMode"], data->decoded_value->depthClampMode, options);
        FieldToJson(jdata["pDepthClampRange"], data->pDepthClampRange, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceHdrVividFeaturesHUAWEI* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["hdrVivid"] = static_cast<bool>(data->decoded_value->hdrVivid);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkHdrVividDynamicMetadataHUAWEI* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["dynamicMetadataSize"], data->decoded_value->dynamicMetadataSize, options);
        FieldToJson(jdata["pDynamicMetadata"], data->pDynamicMetadata, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCooperativeMatrixFlexibleDimensionsPropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["MGranularity"], data->decoded_value->MGranularity, options);
        FieldToJson(jdata["NGranularity"], data->decoded_value->NGranularity, options);
        FieldToJson(jdata["KGranularity"], data->decoded_value->KGranularity, options);
        FieldToJson(jdata["AType"], data->decoded_value->AType, options);
        FieldToJson(jdata["BType"], data->decoded_value->BType, options);
        FieldToJson(jdata["CType"], data->decoded_value->CType, options);
        FieldToJson(jdata["ResultType"], data->decoded_value->ResultType, options);
        jdata["saturatingAccumulation"] = static_cast<bool>(data->decoded_value->saturatingAccumulation);
        FieldToJson(jdata["scope"], data->decoded_value->scope, options);
        FieldToJson(jdata["workgroupInvocations"], data->decoded_value->workgroupInvocations, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCooperativeMatrix2FeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["cooperativeMatrixWorkgroupScope"] = static_cast<bool>(data->decoded_value->cooperativeMatrixWorkgroupScope);
        jdata["cooperativeMatrixFlexibleDimensions"] = static_cast<bool>(data->decoded_value->cooperativeMatrixFlexibleDimensions);
        jdata["cooperativeMatrixReductions"] = static_cast<bool>(data->decoded_value->cooperativeMatrixReductions);
        jdata["cooperativeMatrixConversions"] = static_cast<bool>(data->decoded_value->cooperativeMatrixConversions);
        jdata["cooperativeMatrixPerElementOperations"] = static_cast<bool>(data->decoded_value->cooperativeMatrixPerElementOperations);
        jdata["cooperativeMatrixTensorAddressing"] = static_cast<bool>(data->decoded_value->cooperativeMatrixTensorAddressing);
        jdata["cooperativeMatrixBlockLoads"] = static_cast<bool>(data->decoded_value->cooperativeMatrixBlockLoads);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCooperativeMatrix2PropertiesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["cooperativeMatrixWorkgroupScopeMaxWorkgroupSize"], data->decoded_value->cooperativeMatrixWorkgroupScopeMaxWorkgroupSize, options);
        FieldToJson(jdata["cooperativeMatrixFlexibleDimensionsMaxDimension"], data->decoded_value->cooperativeMatrixFlexibleDimensionsMaxDimension, options);
        FieldToJson(jdata["cooperativeMatrixWorkgroupScopeReservedSharedMemory"], data->decoded_value->cooperativeMatrixWorkgroupScopeReservedSharedMemory, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pipelineOpacityMicromap"] = static_cast<bool>(data->decoded_value->pipelineOpacityMicromap);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkImportMemoryMetalHandleInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["handle"], data->handle, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryMetalHandlePropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["memoryTypeBits"], data->decoded_value->memoryTypeBits, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkMemoryGetMetalHandleInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["memory"], data->memory, options);
        FieldToJson(jdata["handleType"], data->decoded_value->handleType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["performanceCountersByRegion"] = static_cast<bool>(data->decoded_value->performanceCountersByRegion);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxPerRegionPerformanceCounters"], data->decoded_value->maxPerRegionPerformanceCounters, options);
        FieldToJson(jdata["performanceCounterRegionSize"], data->performanceCounterRegionSize, options);
        FieldToJson(jdata["rowStrideAlignment"], data->decoded_value->rowStrideAlignment, options);
        FieldToJson(jdata["regionAlignment"], data->decoded_value->regionAlignment, options);
        jdata["identityTransformOrder"] = static_cast<bool>(data->decoded_value->identityTransformOrder);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceCounterARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["counterID"], data->decoded_value->counterID, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPerformanceCounterDescriptionARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPerformanceCounterDescriptionFlagsARM_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRenderPassPerformanceCountersByRegionBeginInfoARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["counterAddressCount"], data->decoded_value->counterAddressCount, options);
        FieldToJson(jdata["pCounterAddresses"], data->pCounterAddresses, options);
        jdata["serializeRegions"] = static_cast<bool>(data->decoded_value->serializeRegions);
        FieldToJson(jdata["counterIndexCount"], data->decoded_value->counterIndexCount, options);
        FieldToJson(jdata["pCounterIndices"], data->pCounterIndices, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["vertexAttributeRobustness"] = static_cast<bool>(data->decoded_value->vertexAttributeRobustness);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFormatPackFeaturesARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["formatPack"] = static_cast<bool>(data->decoded_value->formatPack);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["fragmentDensityMapLayered"] = static_cast<bool>(data->decoded_value->fragmentDensityMapLayered);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxFragmentDensityMapLayers"], data->decoded_value->maxFragmentDensityMapLayers, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxFragmentDensityMapLayers"], data->decoded_value->maxFragmentDensityMapLayers, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkSetPresentConfigNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["numFramesPerBatch"], data->decoded_value->numFramesPerBatch, options);
        FieldToJson(jdata["presentConfigFeedback"], data->decoded_value->presentConfigFeedback, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePresentMeteringFeaturesNV* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["presentMetering"] = static_cast<bool>(data->decoded_value->presentMetering);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["zeroInitializeDeviceMemory"] = static_cast<bool>(data->decoded_value->zeroInitializeDeviceMemory);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShader64BitIndexingFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shader64BitIndexing"] = static_cast<bool>(data->decoded_value->shader64BitIndexing);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceCustomResolveFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["customResolve"] = static_cast<bool>(data->decoded_value->customResolve);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkBeginCustomResolveInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCustomResolveCreateInfoEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["customResolve"] = static_cast<bool>(data->decoded_value->customResolve);
        FieldToJson(jdata["colorAttachmentCount"], data->decoded_value->colorAttachmentCount, options);
        FieldToJson(jdata["pColorAttachmentFormats"], data->pColorAttachmentFormats, options);
        FieldToJson(jdata["depthAttachmentFormat"], data->decoded_value->depthAttachmentFormat, options);
        FieldToJson(jdata["stencilAttachmentFormat"], data->decoded_value->stencilAttachmentFormat, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPipelineCacheHeaderVersionDataGraphQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["headerSize"], data->decoded_value->headerSize, options);
        FieldToJson(jdata["headerVersion"], data->decoded_value->headerVersion, options);
        FieldToJson(jdata["cacheType"], data->decoded_value->cacheType, options);
        FieldToJson(jdata["cacheVersion"], data->decoded_value->cacheVersion, options);
        FieldToJson(jdata["toolchainVersion"], &data->toolchainVersion, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDataGraphOperationSupportARM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["operationType"], data->decoded_value->operationType, options);
        FieldToJson(jdata["name"], &data->name, options);
        FieldToJson(jdata["version"], data->decoded_value->version, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDataGraphPipelineBuiltinModelCreateInfoQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pOperation"], data->pOperation, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceDataGraphModelFeaturesQCOM* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["dataGraphModel"] = static_cast<bool>(data->decoded_value->dataGraphModel);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["pipelineCacheIncrementalMode"] = static_cast<bool>(data->decoded_value->pipelineCacheIncrementalMode);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["shaderUniformBufferUnsizedArray"] = static_cast<bool>(data->decoded_value->shaderUniformBufferUnsizedArray);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureBuildRangeInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["primitiveCount"], data->decoded_value->primitiveCount, options);
        FieldToJson(jdata["primitiveOffset"], data->decoded_value->primitiveOffset, options);
        FieldToJson(jdata["firstVertex"], data->decoded_value->firstVertex, options);
        FieldToJson(jdata["transformOffset"], data->decoded_value->transformOffset, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometryTrianglesDataKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["vertexFormat"], data->decoded_value->vertexFormat, options);
        FieldToJson(jdata["vertexData"], data->vertexData, options);
        FieldToJson(jdata["vertexStride"], data->decoded_value->vertexStride, options);
        FieldToJson(jdata["maxVertex"], data->decoded_value->maxVertex, options);
        FieldToJson(jdata["indexType"], data->decoded_value->indexType, options);
        FieldToJson(jdata["indexData"], data->indexData, options);
        FieldToJson(jdata["transformData"], data->transformData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometryAabbsDataKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["data"], data->data, options);
        FieldToJson(jdata["stride"], data->decoded_value->stride, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureGeometryInstancesDataKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["arrayOfPointers"] = static_cast<bool>(data->decoded_value->arrayOfPointers);
        FieldToJson(jdata["data"], data->data, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureBuildGeometryInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(VkBuildAccelerationStructureFlagsKHR_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        HandleToJson(jdata["srcAccelerationStructure"], data->srcAccelerationStructure, options);
        HandleToJson(jdata["dstAccelerationStructure"], data->dstAccelerationStructure, options);
        FieldToJson(jdata["geometryCount"], data->decoded_value->geometryCount, options);
        FieldToJson(jdata["pGeometries"], data->pGeometries, options);
        FieldToJson(jdata["ppGeometries"], data->ppGeometries, options);
        FieldToJson(jdata["scratchData"], data->scratchData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkAccelerationStructureCreateFlagsKHR_t(),jdata["createFlags"], data->decoded_value->createFlags, options);
        HandleToJson(jdata["buffer"], data->buffer, options);
        FieldToJson(jdata["offset"], data->decoded_value->offset, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["deviceAddress"], to_hex_variable_width(data->decoded_value->deviceAddress), options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkWriteDescriptorSetAccelerationStructureKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["accelerationStructureCount"], data->decoded_value->accelerationStructureCount, options);
        HandleToJson(jdata["pAccelerationStructures"], &data->pAccelerationStructures, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAccelerationStructureFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["accelerationStructure"] = static_cast<bool>(data->decoded_value->accelerationStructure);
        jdata["accelerationStructureCaptureReplay"] = static_cast<bool>(data->decoded_value->accelerationStructureCaptureReplay);
        jdata["accelerationStructureIndirectBuild"] = static_cast<bool>(data->decoded_value->accelerationStructureIndirectBuild);
        jdata["accelerationStructureHostCommands"] = static_cast<bool>(data->decoded_value->accelerationStructureHostCommands);
        jdata["descriptorBindingAccelerationStructureUpdateAfterBind"] = static_cast<bool>(data->decoded_value->descriptorBindingAccelerationStructureUpdateAfterBind);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceAccelerationStructurePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxGeometryCount"], data->decoded_value->maxGeometryCount, options);
        FieldToJson(jdata["maxInstanceCount"], data->decoded_value->maxInstanceCount, options);
        FieldToJson(jdata["maxPrimitiveCount"], data->decoded_value->maxPrimitiveCount, options);
        FieldToJson(jdata["maxPerStageDescriptorAccelerationStructures"], data->decoded_value->maxPerStageDescriptorAccelerationStructures, options);
        FieldToJson(jdata["maxPerStageDescriptorUpdateAfterBindAccelerationStructures"], data->decoded_value->maxPerStageDescriptorUpdateAfterBindAccelerationStructures, options);
        FieldToJson(jdata["maxDescriptorSetAccelerationStructures"], data->decoded_value->maxDescriptorSetAccelerationStructures, options);
        FieldToJson(jdata["maxDescriptorSetUpdateAfterBindAccelerationStructures"], data->decoded_value->maxDescriptorSetUpdateAfterBindAccelerationStructures, options);
        FieldToJson(jdata["minAccelerationStructureScratchOffsetAlignment"], data->decoded_value->minAccelerationStructureScratchOffsetAlignment, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureDeviceAddressInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["accelerationStructure"], data->accelerationStructure, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkAccelerationStructureVersionInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["pVersionData"], data->pVersionData, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyAccelerationStructureToMemoryInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["src"], data->src, options);
        FieldToJson(jdata["dst"], data->dst, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyMemoryToAccelerationStructureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["src"], data->src, options);
        HandleToJson(jdata["dst"], data->dst, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkCopyAccelerationStructureInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        HandleToJson(jdata["src"], data->src, options);
        HandleToJson(jdata["dst"], data->dst, options);
        FieldToJson(jdata["mode"], data->decoded_value->mode, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRayTracingShaderGroupCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["type"], data->decoded_value->type, options);
        FieldToJson(jdata["generalShader"], data->decoded_value->generalShader, options);
        FieldToJson(jdata["closestHitShader"], data->decoded_value->closestHitShader, options);
        FieldToJson(jdata["anyHitShader"], data->decoded_value->anyHitShader, options);
        FieldToJson(jdata["intersectionShader"], data->decoded_value->intersectionShader, options);
        FieldToJson(jdata["pShaderGroupCaptureReplayHandle"], data->pShaderGroupCaptureReplayHandle, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRayTracingPipelineInterfaceCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxPipelineRayPayloadSize"], data->decoded_value->maxPipelineRayPayloadSize, options);
        FieldToJson(jdata["maxPipelineRayHitAttributeSize"], data->decoded_value->maxPipelineRayHitAttributeSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkRayTracingPipelineCreateInfoKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(VkPipelineCreateFlags_t(),jdata["flags"], data->decoded_value->flags, options);
        FieldToJson(jdata["stageCount"], data->decoded_value->stageCount, options);
        FieldToJson(jdata["pStages"], data->pStages, options);
        FieldToJson(jdata["groupCount"], data->decoded_value->groupCount, options);
        FieldToJson(jdata["pGroups"], data->pGroups, options);
        FieldToJson(jdata["maxPipelineRayRecursionDepth"], data->decoded_value->maxPipelineRayRecursionDepth, options);
        FieldToJson(jdata["pLibraryInfo"], data->pLibraryInfo, options);
        FieldToJson(jdata["pLibraryInterface"], data->pLibraryInterface, options);
        FieldToJson(jdata["pDynamicState"], data->pDynamicState, options);
        HandleToJson(jdata["layout"], data->layout, options);
        HandleToJson(jdata["basePipelineHandle"], data->basePipelineHandle, options);
        FieldToJson(jdata["basePipelineIndex"], data->decoded_value->basePipelineIndex, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingPipelineFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["rayTracingPipeline"] = static_cast<bool>(data->decoded_value->rayTracingPipeline);
        jdata["rayTracingPipelineShaderGroupHandleCaptureReplay"] = static_cast<bool>(data->decoded_value->rayTracingPipelineShaderGroupHandleCaptureReplay);
        jdata["rayTracingPipelineShaderGroupHandleCaptureReplayMixed"] = static_cast<bool>(data->decoded_value->rayTracingPipelineShaderGroupHandleCaptureReplayMixed);
        jdata["rayTracingPipelineTraceRaysIndirect"] = static_cast<bool>(data->decoded_value->rayTracingPipelineTraceRaysIndirect);
        jdata["rayTraversalPrimitiveCulling"] = static_cast<bool>(data->decoded_value->rayTraversalPrimitiveCulling);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayTracingPipelinePropertiesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["shaderGroupHandleSize"], data->decoded_value->shaderGroupHandleSize, options);
        FieldToJson(jdata["maxRayRecursionDepth"], data->decoded_value->maxRayRecursionDepth, options);
        FieldToJson(jdata["maxShaderGroupStride"], data->decoded_value->maxShaderGroupStride, options);
        FieldToJson(jdata["shaderGroupBaseAlignment"], data->decoded_value->shaderGroupBaseAlignment, options);
        FieldToJson(jdata["shaderGroupHandleCaptureReplaySize"], data->decoded_value->shaderGroupHandleCaptureReplaySize, options);
        FieldToJson(jdata["maxRayDispatchInvocationCount"], data->decoded_value->maxRayDispatchInvocationCount, options);
        FieldToJson(jdata["shaderGroupHandleAlignment"], data->decoded_value->shaderGroupHandleAlignment, options);
        FieldToJson(jdata["maxRayHitAttributeSize"], data->decoded_value->maxRayHitAttributeSize, options);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkStridedDeviceAddressRegionKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["deviceAddress"], to_hex_variable_width(data->decoded_value->deviceAddress), options);
        FieldToJson(jdata["stride"], data->decoded_value->stride, options);
        FieldToJson(jdata["size"], data->decoded_value->size, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkTraceRaysIndirectCommandKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["width"], data->decoded_value->width, options);
        FieldToJson(jdata["height"], data->decoded_value->height, options);
        FieldToJson(jdata["depth"], data->decoded_value->depth, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceRayQueryFeaturesKHR* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["rayQuery"] = static_cast<bool>(data->decoded_value->rayQuery);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        jdata["taskShader"] = static_cast<bool>(data->decoded_value->taskShader);
        jdata["meshShader"] = static_cast<bool>(data->decoded_value->meshShader);
        jdata["multiviewMeshShader"] = static_cast<bool>(data->decoded_value->multiviewMeshShader);
        jdata["primitiveFragmentShadingRateMeshShader"] = static_cast<bool>(data->decoded_value->primitiveFragmentShadingRateMeshShader);
        jdata["meshShaderQueries"] = static_cast<bool>(data->decoded_value->meshShaderQueries);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["sType"], data->decoded_value->sType, options);
        FieldToJson(jdata["maxTaskWorkGroupTotalCount"], data->decoded_value->maxTaskWorkGroupTotalCount, options);
        FieldToJson(jdata["maxTaskWorkGroupCount"], &data->maxTaskWorkGroupCount, options);
        FieldToJson(jdata["maxTaskWorkGroupInvocations"], data->decoded_value->maxTaskWorkGroupInvocations, options);
        FieldToJson(jdata["maxTaskWorkGroupSize"], &data->maxTaskWorkGroupSize, options);
        FieldToJson(jdata["maxTaskPayloadSize"], data->decoded_value->maxTaskPayloadSize, options);
        FieldToJson(jdata["maxTaskSharedMemorySize"], data->decoded_value->maxTaskSharedMemorySize, options);
        FieldToJson(jdata["maxTaskPayloadAndSharedMemorySize"], data->decoded_value->maxTaskPayloadAndSharedMemorySize, options);
        FieldToJson(jdata["maxMeshWorkGroupTotalCount"], data->decoded_value->maxMeshWorkGroupTotalCount, options);
        FieldToJson(jdata["maxMeshWorkGroupCount"], &data->maxMeshWorkGroupCount, options);
        FieldToJson(jdata["maxMeshWorkGroupInvocations"], data->decoded_value->maxMeshWorkGroupInvocations, options);
        FieldToJson(jdata["maxMeshWorkGroupSize"], &data->maxMeshWorkGroupSize, options);
        FieldToJson(jdata["maxMeshSharedMemorySize"], data->decoded_value->maxMeshSharedMemorySize, options);
        FieldToJson(jdata["maxMeshPayloadAndSharedMemorySize"], data->decoded_value->maxMeshPayloadAndSharedMemorySize, options);
        FieldToJson(jdata["maxMeshOutputMemorySize"], data->decoded_value->maxMeshOutputMemorySize, options);
        FieldToJson(jdata["maxMeshPayloadAndOutputMemorySize"], data->decoded_value->maxMeshPayloadAndOutputMemorySize, options);
        FieldToJson(jdata["maxMeshOutputComponents"], data->decoded_value->maxMeshOutputComponents, options);
        FieldToJson(jdata["maxMeshOutputVertices"], data->decoded_value->maxMeshOutputVertices, options);
        FieldToJson(jdata["maxMeshOutputPrimitives"], data->decoded_value->maxMeshOutputPrimitives, options);
        FieldToJson(jdata["maxMeshOutputLayers"], data->decoded_value->maxMeshOutputLayers, options);
        FieldToJson(jdata["maxMeshMultiviewViewCount"], data->decoded_value->maxMeshMultiviewViewCount, options);
        FieldToJson(jdata["meshOutputPerVertexGranularity"], data->decoded_value->meshOutputPerVertexGranularity, options);
        FieldToJson(jdata["meshOutputPerPrimitiveGranularity"], data->decoded_value->meshOutputPerPrimitiveGranularity, options);
        FieldToJson(jdata["maxPreferredTaskWorkGroupInvocations"], data->decoded_value->maxPreferredTaskWorkGroupInvocations, options);
        FieldToJson(jdata["maxPreferredMeshWorkGroupInvocations"], data->decoded_value->maxPreferredMeshWorkGroupInvocations, options);
        jdata["prefersLocalInvocationVertexOutput"] = static_cast<bool>(data->decoded_value->prefersLocalInvocationVertexOutput);
        jdata["prefersLocalInvocationPrimitiveOutput"] = static_cast<bool>(data->decoded_value->prefersLocalInvocationPrimitiveOutput);
        jdata["prefersCompactVertexOutput"] = static_cast<bool>(data->decoded_value->prefersCompactVertexOutput);
        jdata["prefersCompactPrimitiveOutput"] = static_cast<bool>(data->decoded_value->prefersCompactPrimitiveOutput);
        FieldToJson(jdata["pNext"], data->pNext, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const Decoded_VkDrawMeshTasksIndirectCommandEXT* data, const JsonOptions& options)
{
    if (data && data->decoded_value)
    {
        FieldToJson(jdata["groupCountX"], data->decoded_value->groupCountX, options);
        FieldToJson(jdata["groupCountY"], data->decoded_value->groupCountY, options);
        FieldToJson(jdata["groupCountZ"], data->decoded_value->groupCountZ, options);
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const PNextNode* data, const JsonOptions& options)
{
    if (data && data->GetPointer())
    {
        const auto s_type = reinterpret_cast<const VkBaseInStructure*>(data->GetPointer())->sType;
        switch (s_type)
        {
            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_LINEAR_SWEPT_SPHERES_DATA_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAccelerationStructureGeometryLinearSweptSpheresDataNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAccelerationStructureGeometryMotionTrianglesDataNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_SPHERES_DATA_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAccelerationStructureGeometrySpheresDataNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAccelerationStructureMotionInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_DISPLACEMENT_MICROMAP_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAccelerationStructureTrianglesDisplacementMicromapNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_TRIANGLES_OPACITY_MICROMAP_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAccelerationStructureTrianglesOpacityMicromapEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_AMIGO_PROFILING_SUBMIT_INFO_SEC:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAmigoProfilingSubmitInfoSEC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAndroidHardwareBufferFormatProperties2ANDROID*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAndroidHardwareBufferFormatPropertiesANDROID*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAndroidHardwareBufferFormatResolvePropertiesANDROID*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAndroidHardwareBufferUsageANDROID*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAttachmentDescriptionStencilLayout*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ATTACHMENT_FEEDBACK_LOOP_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAttachmentFeedbackLoopInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAttachmentReferenceStencilLayout*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkAttachmentSampleCountInfoAMD*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkBindImageMemorySwapchainInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkBindImagePlaneMemoryInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_BIND_MEMORY_STATUS:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkBindMemoryStatus*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_BLIT_IMAGE_CUBIC_WEIGHTS_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkBlitImageCubicWeightsInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkBufferDeviceAddressCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkBufferOpaqueCaptureAddressCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_BUFFER_USAGE_FLAGS_2_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkBufferUsageFlags2CreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkCommandBufferInheritanceRenderingInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkCommandBufferInheritanceViewportScissorInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_INDIRECT_BUFFER_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkComputePipelineIndirectBufferInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkCopyCommandTransformInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_CUSTOM_RESOLVE_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkCustomResolveCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkD3D12FenceSubmitInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDebugReportCallbackCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDebugUtilsMessengerCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDebugUtilsObjectNameInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDedicatedAllocationBufferCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDedicatedAllocationImageCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDedicatedAllocationMemoryAllocateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEPTH_BIAS_REPRESENTATION_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDepthBiasRepresentationInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDescriptorPoolInlineUniformBlockCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDescriptorSetLayoutBindingFlagsCreateInfo*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_DEVICE_ADDRESS_BINDING_CALLBACK_DATA_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceAddressBindingCallbackDataEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceDeviceMemoryReportCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceDiagnosticsConfigCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupBindSparseInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupCommandBufferBeginInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupDeviceCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupPresentInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupRenderPassBeginInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupSubmitInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceGroupSwapchainCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceMemoryOverallocationCreateInfoAMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_PIPELINE_BINARY_INTERNAL_CACHE_CONTROL_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDevicePipelineBinaryInternalCacheControlKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDevicePrivateDataCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceQueueGlobalPriorityCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DEVICE_QUEUE_SHADER_CORE_CONTROL_CREATE_INFO_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDeviceQueueShaderCoreControlCreateInfoARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DIRECT_DRIVER_LOADING_LIST_LUNARG:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDirectDriverLoadingListLUNARG*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DISPLAY_MODE_STEREO_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDisplayModeStereoPropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDisplayPresentInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DISPLAY_SURFACE_STEREO_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDisplaySurfaceStereoCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDrmFormatModifierPropertiesList2EXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkDrmFormatModifierPropertiesListEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExportFenceCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExportFenceWin32HandleInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExportMemoryAllocateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExportMemoryAllocateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExportMemoryWin32HandleInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExportMemoryWin32HandleInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExportSemaphoreCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExportSemaphoreWin32HandleInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExternalFormatANDROID*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExternalImageFormatProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_ACQUIRE_UNMODIFIED_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExternalMemoryAcquireUnmodifiedEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExternalMemoryBufferCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExternalMemoryImageCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkExternalMemoryImageCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkFilterCubicImageViewImageFormatPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkFormatProperties3*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkFragmentShadingRateAttachmentInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_FRAME_BOUNDARY_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkFrameBoundaryEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkFramebufferAttachmentsCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_PIPELINE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkGeneratedCommandsPipelineInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_GENERATED_COMMANDS_SHADER_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkGeneratedCommandsShaderInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_LIBRARY_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkGraphicsPipelineLibraryCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkGraphicsPipelineShaderGroupsCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_HDR_VIVID_DYNAMIC_METADATA_HUAWEI:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkHdrVividDynamicMetadataHUAWEI*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_HOST_IMAGE_COPY_DEVICE_PERFORMANCE_QUERY:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkHostImageCopyDevicePerformanceQuery*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_ALIGNMENT_CONTROL_CREATE_INFO_MESA:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageAlignmentControlCreateInfoMESA*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageDrmFormatModifierExplicitCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageDrmFormatModifierListCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageFormatListCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImagePlaneMemoryRequirementsInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageStencilUsageCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageSwapchainCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageViewASTCDecodeModeEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_VIEW_MIN_LOD_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageViewMinLodCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SAMPLE_WEIGHT_CREATE_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageViewSampleWeightCreateInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_VIEW_SLICED_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageViewSlicedCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImageViewUsageCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImportAndroidHardwareBufferInfoANDROID*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryFdInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryHostPointerInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_METAL_HANDLE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryMetalHandleInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryWin32HandleInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryWin32HandleInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkImportMemoryZirconHandleInfoFUCHSIA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_LATENCY_SUBMISSION_PRESENT_ID_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkLatencySubmissionPresentIdNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_LATENCY_SURFACE_CAPABILITIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkLatencySurfaceCapabilitiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_LAYER_SETTINGS_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkLayerSettingsCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMemoryAllocateFlagsInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMemoryBarrier2*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MEMORY_BARRIER_ACCESS_FLAGS_3_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMemoryBarrierAccessFlags3KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMemoryDedicatedAllocateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMemoryDedicatedRequirements*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MEMORY_MAP_PLACED_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMemoryMapPlacedInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMemoryOpaqueCaptureAddressAllocateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMemoryPriorityAllocateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMultisampledRenderToSingleSampledInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMultiviewPerViewAttributesInfoNVX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_RENDER_AREAS_RENDER_PASS_BEGIN_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMultiviewPerViewRenderAreasRenderPassBeginInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkMutableDescriptorTypeCreateInfoEXT*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PARTITIONED_ACCELERATION_STRUCTURE_FLAGS_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPartitionedAccelerationStructureFlagsNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPerformanceQuerySubmitInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevice16BitStorageFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevice4444FormatsFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevice8BitStorageFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceASTCDecodeFeaturesEXT*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ADDRESS_BINDING_REPORT_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceAddressBindingReportFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_AMIGO_PROFILING_FEATURES_SEC:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceAmigoProfilingFeaturesSEC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ANTI_LAG_FEATURES_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceAntiLagFeaturesAMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_DYNAMIC_STATE_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceAttachmentFeedbackLoopDynamicStateFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ATTACHMENT_FEEDBACK_LOOP_LAYOUT_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceAttachmentFeedbackLoopLayoutFeaturesEXT*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceBufferDeviceAddressFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CLUSTER_CULLING_SHADER_VRS_FEATURES_HUAWEI:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceClusterCullingShaderVrsFeaturesHUAWEI*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMMAND_BUFFER_INHERITANCE_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCommandBufferInheritanceFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceComputeShaderDerivativesFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceComputeShaderDerivativesPropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCooperativeMatrix2FeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_2_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCooperativeMatrix2PropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCooperativeVectorFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_VECTOR_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCooperativeVectorPropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCopyMemoryIndirectFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COPY_MEMORY_INDIRECT_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCopyMemoryIndirectPropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCornerSampledImageFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_CLAMP_FEATURES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCubicClampFeaturesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUBIC_WEIGHTS_FEATURES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCubicWeightsFeaturesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_RESOLVE_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceCustomResolveFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DATA_GRAPH_MODEL_FEATURES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDataGraphModelFeaturesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_BIAS_CONTROL_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDepthBiasControlFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_CONTROL_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDepthClampControlFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLAMP_ZERO_ONE_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDepthClampZeroOneFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_CONTROL_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDepthClipControlFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDepthStencilResolveProperties*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_POOL_OVERALLOCATION_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDescriptorPoolOverallocationFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_SET_HOST_MAPPING_FEATURES_VALVE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDescriptorSetHostMappingFeaturesVALVE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_COMPUTE_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsComputeFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDisplacementMicromapFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISPLACEMENT_MICROMAP_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDisplacementMicromapPropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDriverProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDrmPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDynamicRenderingFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_LOCAL_READ_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDynamicRenderingLocalReadFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_UNUSED_ATTACHMENTS_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceDynamicRenderingUnusedAttachmentsFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExclusiveScissorFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExtendedSparseAddressSpaceFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_SPARSE_ADDRESS_SPACE_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExtendedSparseAddressSpacePropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_FEATURES_ANDROID:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExternalFormatResolveFeaturesANDROID*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FORMAT_RESOLVE_PROPERTIES_ANDROID:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExternalFormatResolvePropertiesANDROID*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExternalImageFormatInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FAULT_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFaultFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFeatures2*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFloatControlsProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FORMAT_PACK_FEATURES_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFormatPackFeaturesARM*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_FEATURES_VALVE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMapLayeredFeaturesVALVE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_LAYERED_PROPERTIES_VALVE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMapLayeredPropertiesVALVE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMapOffsetFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_OFFSET_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMapOffsetPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceGlobalPriorityQueryFeatures*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HDR_VIVID_FEATURES_HUAWEI:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceHdrVividFeaturesHUAWEI*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceHostImageCopyFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_IMAGE_COPY_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceHostImageCopyProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceHostQueryResetFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceIDProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_2D_VIEW_OF_3D_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImage2DViewOf3DFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_FEATURES_MESA:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageAlignmentControlFeaturesMESA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ALIGNMENT_CONTROL_PROPERTIES_MESA:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageAlignmentControlPropertiesMESA*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageCompressionControlFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_COMPRESSION_CONTROL_SWAPCHAIN_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageCompressionControlSwapchainFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_FEATURES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageProcessing2FeaturesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_PROCESSING_2_PROPERTIES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageProcessing2PropertiesQCOM*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageRobustnessFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_SLICED_VIEW_OF_3D_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageSlicedViewOf3DFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageViewImageFormatInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_MIN_LOD_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImageViewMinLodFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceImagelessFramebufferFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceIndexTypeUint8Features*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_PROPERTIES_LIST_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLayeredApiPropertiesListKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_API_VULKAN_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLayeredApiVulkanPropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LAYERED_DRIVER_PROPERTIES_MSFT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLayeredDriverPropertiesMSFT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_DITHERING_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLegacyDitheringFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLegacyVertexAttributesFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LEGACY_VERTEX_ATTRIBUTES_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLegacyVertexAttributesPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLineRasterizationFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLineRasterizationProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINEAR_COLOR_ATTACHMENT_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceLinearColorAttachmentFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance10FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_10_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance10PropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance3Properties*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance5Features*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_5_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance5Properties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance6Features*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_6_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance6Properties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance7FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_7_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance7PropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_8_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance8FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance9FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_9_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMaintenance9PropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMapMemoryPlacedFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAP_MEMORY_PLACED_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMapMemoryPlacedPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMemoryDecompressionFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_DECOMPRESSION_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMemoryDecompressionPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMeshShaderFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMeshShaderFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMeshShaderPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMeshShaderPropertiesNV*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTISAMPLED_RENDER_TO_SINGLE_SAMPLED_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultisampledRenderToSingleSampledFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiviewFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_RENDER_AREAS_FEATURES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiviewPerViewRenderAreasFeaturesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_VIEWPORTS_FEATURES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiviewPerViewViewportsFeaturesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMultiviewProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceMutableDescriptorTypeFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceNestedCommandBufferFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NESTED_COMMAND_BUFFER_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceNestedCommandBufferPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_NON_SEAMLESS_CUBE_MAP_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceNonSeamlessCubeMapFeaturesEXT*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePCIBusInfoPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePartitionedAccelerationStructureFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PARTITIONED_ACCELERATION_STRUCTURE_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePartitionedAccelerationStructurePropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PER_STAGE_DESCRIPTOR_SET_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePerStageDescriptorSetFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_FEATURES_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePerformanceCountersByRegionFeaturesARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_COUNTERS_BY_REGION_PROPERTIES_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePerformanceCountersByRegionPropertiesARM*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineBinaryFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_BINARY_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineBinaryPropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CACHE_INCREMENTAL_MODE_FEATURES_SEC:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineCacheIncrementalModeFeaturesSEC*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineCreationCacheControlFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_LIBRARY_GROUP_HANDLES_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineLibraryGroupHandlesFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_OPACITY_MICROMAP_FEATURES_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineOpacityMicromapFeaturesARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_PROTECTED_ACCESS_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineProtectedAccessFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineRobustnessFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_ROBUSTNESS_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePipelineRobustnessProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePointClippingProperties*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_BARRIER_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePresentBarrierFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_2_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePresentId2FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePresentIdFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_METERING_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePresentMeteringFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_MODE_FIFO_LATEST_READY_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePresentModeFifoLatestReadyFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_2_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePresentWait2FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePresentWaitFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVES_GENERATED_QUERY_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePrimitivesGeneratedQueryFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePrivateDataFeatures*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDevicePushDescriptorProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RASTERIZATION_ORDER_ATTACHMENT_ACCESS_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRasterizationOrderAttachmentAccessFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAW_ACCESS_CHAINS_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRawAccessChainsFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayQueryFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingInvocationReorderFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_INVOCATION_REORDER_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingInvocationReorderPropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_LINEAR_SWEPT_SPHERES_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingLinearSweptSpheresFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MAINTENANCE_1_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingMaintenance1FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_POSITION_FETCH_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingPositionFetchFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingPropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_VALIDATION_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRayTracingValidationFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RELAXED_LINE_RASTERIZATION_FEATURES_IMG:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRelaxedLineRasterizationFeaturesIMG*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_FEATURES_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRenderPassStripedFeaturesARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RENDER_PASS_STRIPED_PROPERTIES_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRenderPassStripedPropertiesARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRobustness2FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceRobustness2PropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSampleLocationsPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSamplerFilterMinmaxProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceScalarBlockLayoutFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_FEATURES_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSchedulingControlsFeaturesARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCHEDULING_CONTROLS_PROPERTIES_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSchedulingControlsPropertiesARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_64_BIT_INDEXING_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShader64BitIndexingFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT16_VECTOR_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderAtomicFloat16VectorFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderAtomicInt64Features*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_BFLOAT16_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderBfloat16FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderClockFeaturesKHR*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderCoreProperties2AMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderCorePropertiesAMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderCorePropertiesARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderDemoteToHelperInvocationFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderDrawParametersFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EARLY_AND_LATE_FRAGMENT_TESTS_FEATURES_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderEarlyAndLateFragmentTestsFeaturesAMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_EXPECT_ASSUME_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderExpectAssumeFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderFloat16Int8Features*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT8_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderFloat8FeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT_CONTROLS_2_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderFloatControls2Features*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FMA_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderFmaFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_MAXIMAL_RECONVERGENCE_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderMaximalReconvergenceFeaturesKHR*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderObjectFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_OBJECT_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderObjectPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_QUAD_CONTROL_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderQuadControlFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_RELAXED_EXTENDED_INSTRUCTION_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderRelaxedExtendedInstructionFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_REPLICATED_COMPOSITES_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderReplicatedCompositesFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_ROTATE_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderSubgroupRotateFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderTerminateInvocationFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderTileImageFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TILE_IMAGE_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderTileImagePropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNIFORM_BUFFER_UNSIZED_ARRAY_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderUniformBufferUnsizedArrayFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_UNTYPED_POINTERS_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceShaderUntypedPointersFeaturesKHR*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSubgroupProperties*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBPASS_MERGE_FEEDBACK_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSubpassMergeFeedbackFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SWAPCHAIN_MAINTENANCE_1_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSwapchainMaintenance1FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceSynchronization2Features*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTexelBufferAlignmentProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTextureCompressionASTCHDRFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_FEATURES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTileMemoryHeapFeaturesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_MEMORY_HEAP_PROPERTIES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTileMemoryHeapPropertiesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_PROPERTIES_FEATURES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTilePropertiesFeaturesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_FEATURES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTileShadingFeaturesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TILE_SHADING_PROPERTIES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceTileShadingPropertiesQCOM*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFIED_IMAGE_LAYOUTS_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceUnifiedImageLayoutsFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVariablePointersFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVertexAttributeDivisorFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVertexAttributeDivisorProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_ROBUSTNESS_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVertexAttributeRobustnessFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_DECODE_VP9_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVideoDecodeVP9FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_AV1_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVideoEncodeAV1FeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_INTRA_REFRESH_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVideoEncodeIntraRefreshFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_QUANTIZATION_MAP_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVideoEncodeQuantizationMapFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_ENCODE_RGB_CONVERSION_FEATURES_VALVE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVideoEncodeRgbConversionFeaturesVALVE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VIDEO_MAINTENANCE_1_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVideoMaintenance1FeaturesKHR*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVulkan14Features*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_4_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVulkan14Properties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceVulkanMemoryModelFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_DEGAMMA_FEATURES_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceYcbcrDegammaFeaturesQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_DEVICE_MEMORY_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceZeroInitializeDeviceMemoryFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeatures*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_BINARY_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineBinaryInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineColorWriteCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCompilerControlCreateInfoAMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCoverageModulationStateCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCoverageReductionStateCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCoverageToColorStateCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_CREATE_FLAGS_2_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCreateFlags2CreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineCreationFeedbackCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineDiscardRectangleStateCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_DENSITY_MAP_LAYERED_CREATE_INFO_VALVE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineFragmentDensityMapLayeredCreateInfoVALVE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineFragmentShadingRateStateCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineLayoutCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineLibraryCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationConservativeStateCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationLineStateCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationStateRasterizationOrderAMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRasterizationStateStreamCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRenderingCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_ROBUSTNESS_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineRobustnessCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineSampleLocationsStateCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_MODULE_IDENTIFIER_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineShaderStageModuleIdentifierCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineShaderStageRequiredSubgroupSizeCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineTessellationDomainOriginStateCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineVertexInputDivisorStateCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLAMP_CONTROL_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportDepthClampControlCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_DEPTH_CLIP_CONTROL_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportDepthClipControlCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportShadingRateImageStateCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportSwizzleStateCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPipelineViewportWScalingStateCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPresentFrameTokenGGP*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PRESENT_ID_2_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPresentId2KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPresentIdKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPresentRegionsKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkPresentTimesInfoGOOGLE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkProtectedSubmitInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_QUERY_LOW_LATENCY_SUPPORT_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkQueryLowLatencySupportNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkQueryPoolPerformanceCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkQueryPoolPerformanceQueryCreateInfoINTEL*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_QUERY_POOL_VIDEO_ENCODE_FEEDBACK_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkQueryPoolVideoEncodeFeedbackCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkQueueFamilyCheckpointProperties2NV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkQueueFamilyCheckpointPropertiesNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkQueueFamilyGlobalPriorityProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_QUEUE_FAMILY_OWNERSHIP_TRANSFER_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkQueueFamilyOwnershipTransferPropertiesKHR*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassAttachmentBeginInfo*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassFragmentDensityMapCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_OFFSET_END_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassFragmentDensityMapOffsetEndInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassInputAttachmentAspectCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassMultiviewCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDER_PASS_PERFORMANCE_COUNTERS_BY_REGION_BEGIN_INFO_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassPerformanceCountersByRegionBeginInfoARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassSampleLocationsBeginInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_BEGIN_INFO_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassStripeBeginInfoARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDER_PASS_STRIPE_SUBMIT_INFO_ARM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassStripeSubmitInfoARM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDER_PASS_SUBPASS_FEEDBACK_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassSubpassFeedbackCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDER_PASS_TILE_SHADING_CREATE_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassTileShadingCreateInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderPassTransformBeginInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_FLAGS_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderingAttachmentFlagsInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDERING_ATTACHMENT_LOCATION_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderingAttachmentLocationInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderingFragmentDensityMapAttachmentInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderingFragmentShadingRateAttachmentInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RENDERING_INPUT_ATTACHMENT_INDEX_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkRenderingInputAttachmentIndexInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_RESOLVE_IMAGE_MODE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkResolveImageModeInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSampleLocationsInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SAMPLER_BLOCK_MATCH_WINDOW_CREATE_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSamplerBlockMatchWindowCreateInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSamplerBorderColorComponentMappingCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SAMPLER_CUBIC_WEIGHTS_CREATE_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSamplerCubicWeightsCreateInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSamplerCustomBorderColorCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSamplerReductionModeCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSamplerYcbcrConversionImageFormatProperties*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSamplerYcbcrConversionInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_YCBCR_DEGAMMA_CREATE_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSamplerYcbcrConversionYcbcrDegammaCreateInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSemaphoreTypeCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SET_PRESENT_CONFIG_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSetPresentConfigNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkShaderModuleCreateInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkShaderModuleValidationCacheCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSharedPresentSurfaceCapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSubpassDescriptionDepthStencilResolve*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SUBPASS_RESOLVE_PERFORMANCE_QUERY_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSubpassResolvePerformanceQueryEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SUBRESOURCE_HOST_MEMCPY_SIZE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSubresourceHostMemcpySize*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_BARRIER_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceCapabilitiesPresentBarrierNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_ID_2_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceCapabilitiesPresentId2KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_PRESENT_WAIT_2_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceCapabilitiesPresentWait2KHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceFullScreenExclusiveInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceFullScreenExclusiveWin32InfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_COMPATIBILITY_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSurfacePresentModeCompatibilityKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_MODE_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSurfacePresentModeKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SURFACE_PRESENT_SCALING_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSurfacePresentScalingCapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSurfaceProtectedCapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainCounterCreateInfoEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainDisplayNativeHdrCreateInfoAMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SWAPCHAIN_LATENCY_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainLatencyCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_BARRIER_CREATE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainPresentBarrierCreateInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_FENCE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainPresentFenceInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainPresentModeInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_MODES_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainPresentModesCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_SWAPCHAIN_PRESENT_SCALING_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkSwapchainPresentScalingCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkTextureLODGatherFormatPropertiesAMD*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_TILE_MEMORY_BIND_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkTileMemoryBindInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_TILE_MEMORY_REQUIREMENTS_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkTileMemoryRequirementsQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_TILE_MEMORY_SIZE_INFO_QCOM:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkTileMemorySizeInfoQCOM*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkTimelineSemaphoreSubmitInfo*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkValidationFeaturesEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkValidationFlagsEXT*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeAV1CapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_DPB_SLOT_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeAV1DpbSlotInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PICTURE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeAV1PictureInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_PROFILE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeAV1ProfileInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeAV1SessionParametersCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeCapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH264CapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_DPB_SLOT_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH264DpbSlotInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PICTURE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH264PictureInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_H264_PROFILE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeH264ProfileInfoKHR*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_USAGE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeUsageInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeVP9CapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PICTURE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeVP9PictureInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_DECODE_VP9_PROFILE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoDecodeVP9ProfileInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1CapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_DPB_SLOT_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1DpbSlotInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_GOP_REMAINING_FRAME_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1GopRemainingFrameInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PICTURE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1PictureInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_PROFILE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1ProfileInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUALITY_LEVEL_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1QualityLevelPropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_QUANTIZATION_MAP_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1QuantizationMapCapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1RateControlInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_RATE_CONTROL_LAYER_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1RateControlLayerInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1SessionCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_AV1_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeAV1SessionParametersCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeCapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264CapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_DPB_SLOT_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264DpbSlotInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_GOP_REMAINING_FRAME_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264GopRemainingFrameInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PICTURE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264PictureInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_PROFILE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264ProfileInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUALITY_LEVEL_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264QualityLevelPropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_QUANTIZATION_MAP_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264QuantizationMapCapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264RateControlInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_RATE_CONTROL_LAYER_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264RateControlLayerInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264SessionCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_ADD_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264SessionParametersAddInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264SessionParametersCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_FEEDBACK_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264SessionParametersFeedbackInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H264_SESSION_PARAMETERS_GET_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH264SessionParametersGetInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_H265_QUANTIZATION_MAP_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeH265QuantizationMapCapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeIntraRefreshCapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_INTRA_REFRESH_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeIntraRefreshInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_PROFILE_RGB_CONVERSION_INFO_VALVE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeProfileRgbConversionInfoVALVE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUALITY_LEVEL_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeQualityLevelInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_CAPABILITIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeQuantizationMapCapabilitiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeQuantizationMapInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_QUANTIZATION_MAP_SESSION_PARAMETERS_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeQuantizationMapSessionParametersCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RATE_CONTROL_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeRateControlInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_RGB_CONVERSION_CAPABILITIES_VALVE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeRgbConversionCapabilitiesVALVE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_INTRA_REFRESH_CREATE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeSessionIntraRefreshCreateInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_SESSION_RGB_CONVERSION_CREATE_INFO_VALVE:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeSessionRgbConversionCreateInfoVALVE*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_ENCODE_USAGE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoEncodeUsageInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_AV1_QUANTIZATION_MAP_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoFormatAV1QuantizationMapPropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_H265_QUANTIZATION_MAP_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoFormatH265QuantizationMapPropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_FORMAT_QUANTIZATION_MAP_PROPERTIES_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoFormatQuantizationMapPropertiesKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_VIDEO_INLINE_QUERY_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoInlineQueryInfoKHR*>(data->GetMetaStructPointer());
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

            case VK_STRUCTURE_TYPE_VIDEO_REFERENCE_INTRA_REFRESH_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkVideoReferenceIntraRefreshInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkWin32KeyedMutexAcquireReleaseInfoKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkWin32KeyedMutexAcquireReleaseInfoNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkWriteDescriptorSetAccelerationStructureKHR*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkWriteDescriptorSetAccelerationStructureNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkWriteDescriptorSetInlineUniformBlock*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_PARTITIONED_ACCELERATION_STRUCTURE_NV:
            {
                const auto* pnext = reinterpret_cast<const Decoded_VkWriteDescriptorSetPartitionedAccelerationStructureNV*>(data->GetMetaStructPointer());
                FieldToJson(jdata, pnext, options);
                break;
            }

            default:
            {
                GFXRECON_LOG_WARNING("Unknown pnext node type: %u.", (unsigned) s_type);
            }
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
