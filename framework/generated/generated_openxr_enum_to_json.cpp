/*
** Copyright (c) 2018-2023 Valve Corporation
** Copyright (c) 2018-2024 LunarG, Inc.
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
** This file is generated from the Khronos OpenXR XML API Registry.
**
*/

#ifdef ENABLE_OPENXR_SUPPORT

#include "generated_openxr_enum_to_json.h"
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


void FieldToJson(nlohmann::ordered_json& jdata, const XrActionType& value, const JsonOptions& options)
{
    switch (value) {
        case XR_ACTION_TYPE_BOOLEAN_INPUT:
            jdata = "XR_ACTION_TYPE_BOOLEAN_INPUT";
            break;
        case XR_ACTION_TYPE_FLOAT_INPUT:
            jdata = "XR_ACTION_TYPE_FLOAT_INPUT";
            break;
        case XR_ACTION_TYPE_VECTOR2F_INPUT:
            jdata = "XR_ACTION_TYPE_VECTOR2F_INPUT";
            break;
        case XR_ACTION_TYPE_POSE_INPUT:
            jdata = "XR_ACTION_TYPE_POSE_INPUT";
            break;
        case XR_ACTION_TYPE_VIBRATION_OUTPUT:
            jdata = "XR_ACTION_TYPE_VIBRATION_OUTPUT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrAndroidThreadTypeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case XR_ANDROID_THREAD_TYPE_APPLICATION_MAIN_KHR:
            jdata = "XR_ANDROID_THREAD_TYPE_APPLICATION_MAIN_KHR";
            break;
        case XR_ANDROID_THREAD_TYPE_APPLICATION_WORKER_KHR:
            jdata = "XR_ANDROID_THREAD_TYPE_APPLICATION_WORKER_KHR";
            break;
        case XR_ANDROID_THREAD_TYPE_RENDERER_MAIN_KHR:
            jdata = "XR_ANDROID_THREAD_TYPE_RENDERER_MAIN_KHR";
            break;
        case XR_ANDROID_THREAD_TYPE_RENDERER_WORKER_KHR:
            jdata = "XR_ANDROID_THREAD_TYPE_RENDERER_WORKER_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrBlendFactorFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_BLEND_FACTOR_ZERO_FB:
            jdata = "XR_BLEND_FACTOR_ZERO_FB";
            break;
        case XR_BLEND_FACTOR_ONE_FB:
            jdata = "XR_BLEND_FACTOR_ONE_FB";
            break;
        case XR_BLEND_FACTOR_SRC_ALPHA_FB:
            jdata = "XR_BLEND_FACTOR_SRC_ALPHA_FB";
            break;
        case XR_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA_FB:
            jdata = "XR_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA_FB";
            break;
        case XR_BLEND_FACTOR_DST_ALPHA_FB:
            jdata = "XR_BLEND_FACTOR_DST_ALPHA_FB";
            break;
        case XR_BLEND_FACTOR_ONE_MINUS_DST_ALPHA_FB:
            jdata = "XR_BLEND_FACTOR_ONE_MINUS_DST_ALPHA_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrBodyJointFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_BODY_JOINT_ROOT_FB:
            jdata = "XR_BODY_JOINT_ROOT_FB";
            break;
        case XR_BODY_JOINT_HIPS_FB:
            jdata = "XR_BODY_JOINT_HIPS_FB";
            break;
        case XR_BODY_JOINT_SPINE_LOWER_FB:
            jdata = "XR_BODY_JOINT_SPINE_LOWER_FB";
            break;
        case XR_BODY_JOINT_SPINE_MIDDLE_FB:
            jdata = "XR_BODY_JOINT_SPINE_MIDDLE_FB";
            break;
        case XR_BODY_JOINT_SPINE_UPPER_FB:
            jdata = "XR_BODY_JOINT_SPINE_UPPER_FB";
            break;
        case XR_BODY_JOINT_CHEST_FB:
            jdata = "XR_BODY_JOINT_CHEST_FB";
            break;
        case XR_BODY_JOINT_NECK_FB:
            jdata = "XR_BODY_JOINT_NECK_FB";
            break;
        case XR_BODY_JOINT_HEAD_FB:
            jdata = "XR_BODY_JOINT_HEAD_FB";
            break;
        case XR_BODY_JOINT_LEFT_SHOULDER_FB:
            jdata = "XR_BODY_JOINT_LEFT_SHOULDER_FB";
            break;
        case XR_BODY_JOINT_LEFT_SCAPULA_FB:
            jdata = "XR_BODY_JOINT_LEFT_SCAPULA_FB";
            break;
        case XR_BODY_JOINT_LEFT_ARM_UPPER_FB:
            jdata = "XR_BODY_JOINT_LEFT_ARM_UPPER_FB";
            break;
        case XR_BODY_JOINT_LEFT_ARM_LOWER_FB:
            jdata = "XR_BODY_JOINT_LEFT_ARM_LOWER_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_WRIST_TWIST_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_WRIST_TWIST_FB";
            break;
        case XR_BODY_JOINT_RIGHT_SHOULDER_FB:
            jdata = "XR_BODY_JOINT_RIGHT_SHOULDER_FB";
            break;
        case XR_BODY_JOINT_RIGHT_SCAPULA_FB:
            jdata = "XR_BODY_JOINT_RIGHT_SCAPULA_FB";
            break;
        case XR_BODY_JOINT_RIGHT_ARM_UPPER_FB:
            jdata = "XR_BODY_JOINT_RIGHT_ARM_UPPER_FB";
            break;
        case XR_BODY_JOINT_RIGHT_ARM_LOWER_FB:
            jdata = "XR_BODY_JOINT_RIGHT_ARM_LOWER_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_WRIST_TWIST_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_WRIST_TWIST_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_PALM_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_PALM_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_WRIST_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_WRIST_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_THUMB_METACARPAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_THUMB_METACARPAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_THUMB_PROXIMAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_THUMB_PROXIMAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_THUMB_DISTAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_THUMB_DISTAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_THUMB_TIP_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_THUMB_TIP_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_INDEX_METACARPAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_INDEX_METACARPAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_INDEX_PROXIMAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_INDEX_PROXIMAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_INDEX_INTERMEDIATE_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_INDEX_INTERMEDIATE_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_INDEX_DISTAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_INDEX_DISTAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_INDEX_TIP_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_INDEX_TIP_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_MIDDLE_METACARPAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_MIDDLE_METACARPAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_MIDDLE_PROXIMAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_MIDDLE_PROXIMAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_MIDDLE_INTERMEDIATE_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_MIDDLE_INTERMEDIATE_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_MIDDLE_DISTAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_MIDDLE_DISTAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_MIDDLE_TIP_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_MIDDLE_TIP_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_RING_METACARPAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_RING_METACARPAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_RING_PROXIMAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_RING_PROXIMAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_RING_INTERMEDIATE_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_RING_INTERMEDIATE_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_RING_DISTAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_RING_DISTAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_RING_TIP_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_RING_TIP_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_LITTLE_METACARPAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_LITTLE_METACARPAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_LITTLE_PROXIMAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_LITTLE_PROXIMAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_LITTLE_INTERMEDIATE_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_LITTLE_INTERMEDIATE_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_LITTLE_DISTAL_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_LITTLE_DISTAL_FB";
            break;
        case XR_BODY_JOINT_LEFT_HAND_LITTLE_TIP_FB:
            jdata = "XR_BODY_JOINT_LEFT_HAND_LITTLE_TIP_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_PALM_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_PALM_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_WRIST_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_WRIST_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_THUMB_METACARPAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_THUMB_METACARPAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_THUMB_PROXIMAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_THUMB_PROXIMAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_THUMB_DISTAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_THUMB_DISTAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_THUMB_TIP_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_THUMB_TIP_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_INDEX_METACARPAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_INDEX_METACARPAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_INDEX_PROXIMAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_INDEX_PROXIMAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_INDEX_INTERMEDIATE_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_INDEX_INTERMEDIATE_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_INDEX_DISTAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_INDEX_DISTAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_INDEX_TIP_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_INDEX_TIP_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_MIDDLE_METACARPAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_MIDDLE_METACARPAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_MIDDLE_PROXIMAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_MIDDLE_PROXIMAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_MIDDLE_INTERMEDIATE_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_MIDDLE_INTERMEDIATE_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_MIDDLE_DISTAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_MIDDLE_DISTAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_MIDDLE_TIP_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_MIDDLE_TIP_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_RING_METACARPAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_RING_METACARPAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_RING_PROXIMAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_RING_PROXIMAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_RING_INTERMEDIATE_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_RING_INTERMEDIATE_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_RING_DISTAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_RING_DISTAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_RING_TIP_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_RING_TIP_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_LITTLE_METACARPAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_LITTLE_METACARPAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_LITTLE_PROXIMAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_LITTLE_PROXIMAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_LITTLE_INTERMEDIATE_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_LITTLE_INTERMEDIATE_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_LITTLE_DISTAL_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_LITTLE_DISTAL_FB";
            break;
        case XR_BODY_JOINT_RIGHT_HAND_LITTLE_TIP_FB:
            jdata = "XR_BODY_JOINT_RIGHT_HAND_LITTLE_TIP_FB";
            break;
        case XR_BODY_JOINT_COUNT_FB:
            jdata = "XR_BODY_JOINT_COUNT_FB";
            break;
        case XR_BODY_JOINT_NONE_FB:
            jdata = "XR_BODY_JOINT_NONE_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrBodyJointSetFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_BODY_JOINT_SET_DEFAULT_FB:
            jdata = "XR_BODY_JOINT_SET_DEFAULT_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrColorSpaceFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_COLOR_SPACE_UNMANAGED_FB:
            jdata = "XR_COLOR_SPACE_UNMANAGED_FB";
            break;
        case XR_COLOR_SPACE_REC2020_FB:
            jdata = "XR_COLOR_SPACE_REC2020_FB";
            break;
        case XR_COLOR_SPACE_REC709_FB:
            jdata = "XR_COLOR_SPACE_REC709_FB";
            break;
        case XR_COLOR_SPACE_RIFT_CV1_FB:
            jdata = "XR_COLOR_SPACE_RIFT_CV1_FB";
            break;
        case XR_COLOR_SPACE_RIFT_S_FB:
            jdata = "XR_COLOR_SPACE_RIFT_S_FB";
            break;
        case XR_COLOR_SPACE_QUEST_FB:
            jdata = "XR_COLOR_SPACE_QUEST_FB";
            break;
        case XR_COLOR_SPACE_P3_FB:
            jdata = "XR_COLOR_SPACE_P3_FB";
            break;
        case XR_COLOR_SPACE_ADOBE_RGB_FB:
            jdata = "XR_COLOR_SPACE_ADOBE_RGB_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrCompareOpFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_COMPARE_OP_NEVER_FB:
            jdata = "XR_COMPARE_OP_NEVER_FB";
            break;
        case XR_COMPARE_OP_LESS_FB:
            jdata = "XR_COMPARE_OP_LESS_FB";
            break;
        case XR_COMPARE_OP_EQUAL_FB:
            jdata = "XR_COMPARE_OP_EQUAL_FB";
            break;
        case XR_COMPARE_OP_LESS_OR_EQUAL_FB:
            jdata = "XR_COMPARE_OP_LESS_OR_EQUAL_FB";
            break;
        case XR_COMPARE_OP_GREATER_FB:
            jdata = "XR_COMPARE_OP_GREATER_FB";
            break;
        case XR_COMPARE_OP_NOT_EQUAL_FB:
            jdata = "XR_COMPARE_OP_NOT_EQUAL_FB";
            break;
        case XR_COMPARE_OP_GREATER_OR_EQUAL_FB:
            jdata = "XR_COMPARE_OP_GREATER_OR_EQUAL_FB";
            break;
        case XR_COMPARE_OP_ALWAYS_FB:
            jdata = "XR_COMPARE_OP_ALWAYS_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrEnvironmentBlendMode& value, const JsonOptions& options)
{
    switch (value) {
        case XR_ENVIRONMENT_BLEND_MODE_OPAQUE:
            jdata = "XR_ENVIRONMENT_BLEND_MODE_OPAQUE";
            break;
        case XR_ENVIRONMENT_BLEND_MODE_ADDITIVE:
            jdata = "XR_ENVIRONMENT_BLEND_MODE_ADDITIVE";
            break;
        case XR_ENVIRONMENT_BLEND_MODE_ALPHA_BLEND:
            jdata = "XR_ENVIRONMENT_BLEND_MODE_ALPHA_BLEND";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrExternalCameraAttachedToDeviceOCULUS& value, const JsonOptions& options)
{
    switch (value) {
        case XR_EXTERNAL_CAMERA_ATTACHED_TO_DEVICE_NONE_OCULUS:
            jdata = "XR_EXTERNAL_CAMERA_ATTACHED_TO_DEVICE_NONE_OCULUS";
            break;
        case XR_EXTERNAL_CAMERA_ATTACHED_TO_DEVICE_HMD_OCULUS:
            jdata = "XR_EXTERNAL_CAMERA_ATTACHED_TO_DEVICE_HMD_OCULUS";
            break;
        case XR_EXTERNAL_CAMERA_ATTACHED_TO_DEVICE_LTOUCH_OCULUS:
            jdata = "XR_EXTERNAL_CAMERA_ATTACHED_TO_DEVICE_LTOUCH_OCULUS";
            break;
        case XR_EXTERNAL_CAMERA_ATTACHED_TO_DEVICE_RTOUCH_OCULUS:
            jdata = "XR_EXTERNAL_CAMERA_ATTACHED_TO_DEVICE_RTOUCH_OCULUS";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrEyeCalibrationStatusML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_EYE_CALIBRATION_STATUS_UNKNOWN_ML:
            jdata = "XR_EYE_CALIBRATION_STATUS_UNKNOWN_ML";
            break;
        case XR_EYE_CALIBRATION_STATUS_NONE_ML:
            jdata = "XR_EYE_CALIBRATION_STATUS_NONE_ML";
            break;
        case XR_EYE_CALIBRATION_STATUS_COARSE_ML:
            jdata = "XR_EYE_CALIBRATION_STATUS_COARSE_ML";
            break;
        case XR_EYE_CALIBRATION_STATUS_FINE_ML:
            jdata = "XR_EYE_CALIBRATION_STATUS_FINE_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrEyeExpressionHTC& value, const JsonOptions& options)
{
    switch (value) {
        case XR_EYE_EXPRESSION_LEFT_BLINK_HTC:
            jdata = "XR_EYE_EXPRESSION_LEFT_BLINK_HTC";
            break;
        case XR_EYE_EXPRESSION_LEFT_WIDE_HTC:
            jdata = "XR_EYE_EXPRESSION_LEFT_WIDE_HTC";
            break;
        case XR_EYE_EXPRESSION_RIGHT_BLINK_HTC:
            jdata = "XR_EYE_EXPRESSION_RIGHT_BLINK_HTC";
            break;
        case XR_EYE_EXPRESSION_RIGHT_WIDE_HTC:
            jdata = "XR_EYE_EXPRESSION_RIGHT_WIDE_HTC";
            break;
        case XR_EYE_EXPRESSION_LEFT_SQUEEZE_HTC:
            jdata = "XR_EYE_EXPRESSION_LEFT_SQUEEZE_HTC";
            break;
        case XR_EYE_EXPRESSION_RIGHT_SQUEEZE_HTC:
            jdata = "XR_EYE_EXPRESSION_RIGHT_SQUEEZE_HTC";
            break;
        case XR_EYE_EXPRESSION_LEFT_DOWN_HTC:
            jdata = "XR_EYE_EXPRESSION_LEFT_DOWN_HTC";
            break;
        case XR_EYE_EXPRESSION_RIGHT_DOWN_HTC:
            jdata = "XR_EYE_EXPRESSION_RIGHT_DOWN_HTC";
            break;
        case XR_EYE_EXPRESSION_LEFT_OUT_HTC:
            jdata = "XR_EYE_EXPRESSION_LEFT_OUT_HTC";
            break;
        case XR_EYE_EXPRESSION_RIGHT_IN_HTC:
            jdata = "XR_EYE_EXPRESSION_RIGHT_IN_HTC";
            break;
        case XR_EYE_EXPRESSION_LEFT_IN_HTC:
            jdata = "XR_EYE_EXPRESSION_LEFT_IN_HTC";
            break;
        case XR_EYE_EXPRESSION_RIGHT_OUT_HTC:
            jdata = "XR_EYE_EXPRESSION_RIGHT_OUT_HTC";
            break;
        case XR_EYE_EXPRESSION_LEFT_UP_HTC:
            jdata = "XR_EYE_EXPRESSION_LEFT_UP_HTC";
            break;
        case XR_EYE_EXPRESSION_RIGHT_UP_HTC:
            jdata = "XR_EYE_EXPRESSION_RIGHT_UP_HTC";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrEyePositionFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_EYE_POSITION_LEFT_FB:
            jdata = "XR_EYE_POSITION_LEFT_FB";
            break;
        case XR_EYE_POSITION_RIGHT_FB:
            jdata = "XR_EYE_POSITION_RIGHT_FB";
            break;
        case XR_EYE_POSITION_COUNT_FB:
            jdata = "XR_EYE_POSITION_COUNT_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrEyeVisibility& value, const JsonOptions& options)
{
    switch (value) {
        case XR_EYE_VISIBILITY_BOTH:
            jdata = "XR_EYE_VISIBILITY_BOTH";
            break;
        case XR_EYE_VISIBILITY_LEFT:
            jdata = "XR_EYE_VISIBILITY_LEFT";
            break;
        case XR_EYE_VISIBILITY_RIGHT:
            jdata = "XR_EYE_VISIBILITY_RIGHT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceConfidence2FB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FACE_CONFIDENCE2_LOWER_FACE_FB:
            jdata = "XR_FACE_CONFIDENCE2_LOWER_FACE_FB";
            break;
        case XR_FACE_CONFIDENCE2_UPPER_FACE_FB:
            jdata = "XR_FACE_CONFIDENCE2_UPPER_FACE_FB";
            break;
        case XR_FACE_CONFIDENCE2_COUNT_FB:
            jdata = "XR_FACE_CONFIDENCE2_COUNT_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceConfidenceFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FACE_CONFIDENCE_LOWER_FACE_FB:
            jdata = "XR_FACE_CONFIDENCE_LOWER_FACE_FB";
            break;
        case XR_FACE_CONFIDENCE_UPPER_FACE_FB:
            jdata = "XR_FACE_CONFIDENCE_UPPER_FACE_FB";
            break;
        case XR_FACE_CONFIDENCE_COUNT_FB:
            jdata = "XR_FACE_CONFIDENCE_COUNT_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpression2FB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FACE_EXPRESSION2_BROW_LOWERER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_BROW_LOWERER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_BROW_LOWERER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_BROW_LOWERER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_CHEEK_PUFF_L_FB:
            jdata = "XR_FACE_EXPRESSION2_CHEEK_PUFF_L_FB";
            break;
        case XR_FACE_EXPRESSION2_CHEEK_PUFF_R_FB:
            jdata = "XR_FACE_EXPRESSION2_CHEEK_PUFF_R_FB";
            break;
        case XR_FACE_EXPRESSION2_CHEEK_RAISER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_CHEEK_RAISER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_CHEEK_RAISER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_CHEEK_RAISER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_CHEEK_SUCK_L_FB:
            jdata = "XR_FACE_EXPRESSION2_CHEEK_SUCK_L_FB";
            break;
        case XR_FACE_EXPRESSION2_CHEEK_SUCK_R_FB:
            jdata = "XR_FACE_EXPRESSION2_CHEEK_SUCK_R_FB";
            break;
        case XR_FACE_EXPRESSION2_CHIN_RAISER_B_FB:
            jdata = "XR_FACE_EXPRESSION2_CHIN_RAISER_B_FB";
            break;
        case XR_FACE_EXPRESSION2_CHIN_RAISER_T_FB:
            jdata = "XR_FACE_EXPRESSION2_CHIN_RAISER_T_FB";
            break;
        case XR_FACE_EXPRESSION2_DIMPLER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_DIMPLER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_DIMPLER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_DIMPLER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_EYES_CLOSED_L_FB:
            jdata = "XR_FACE_EXPRESSION2_EYES_CLOSED_L_FB";
            break;
        case XR_FACE_EXPRESSION2_EYES_CLOSED_R_FB:
            jdata = "XR_FACE_EXPRESSION2_EYES_CLOSED_R_FB";
            break;
        case XR_FACE_EXPRESSION2_EYES_LOOK_DOWN_L_FB:
            jdata = "XR_FACE_EXPRESSION2_EYES_LOOK_DOWN_L_FB";
            break;
        case XR_FACE_EXPRESSION2_EYES_LOOK_DOWN_R_FB:
            jdata = "XR_FACE_EXPRESSION2_EYES_LOOK_DOWN_R_FB";
            break;
        case XR_FACE_EXPRESSION2_EYES_LOOK_LEFT_L_FB:
            jdata = "XR_FACE_EXPRESSION2_EYES_LOOK_LEFT_L_FB";
            break;
        case XR_FACE_EXPRESSION2_EYES_LOOK_LEFT_R_FB:
            jdata = "XR_FACE_EXPRESSION2_EYES_LOOK_LEFT_R_FB";
            break;
        case XR_FACE_EXPRESSION2_EYES_LOOK_RIGHT_L_FB:
            jdata = "XR_FACE_EXPRESSION2_EYES_LOOK_RIGHT_L_FB";
            break;
        case XR_FACE_EXPRESSION2_EYES_LOOK_RIGHT_R_FB:
            jdata = "XR_FACE_EXPRESSION2_EYES_LOOK_RIGHT_R_FB";
            break;
        case XR_FACE_EXPRESSION2_EYES_LOOK_UP_L_FB:
            jdata = "XR_FACE_EXPRESSION2_EYES_LOOK_UP_L_FB";
            break;
        case XR_FACE_EXPRESSION2_EYES_LOOK_UP_R_FB:
            jdata = "XR_FACE_EXPRESSION2_EYES_LOOK_UP_R_FB";
            break;
        case XR_FACE_EXPRESSION2_INNER_BROW_RAISER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_INNER_BROW_RAISER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_INNER_BROW_RAISER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_INNER_BROW_RAISER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_JAW_DROP_FB:
            jdata = "XR_FACE_EXPRESSION2_JAW_DROP_FB";
            break;
        case XR_FACE_EXPRESSION2_JAW_SIDEWAYS_LEFT_FB:
            jdata = "XR_FACE_EXPRESSION2_JAW_SIDEWAYS_LEFT_FB";
            break;
        case XR_FACE_EXPRESSION2_JAW_SIDEWAYS_RIGHT_FB:
            jdata = "XR_FACE_EXPRESSION2_JAW_SIDEWAYS_RIGHT_FB";
            break;
        case XR_FACE_EXPRESSION2_JAW_THRUST_FB:
            jdata = "XR_FACE_EXPRESSION2_JAW_THRUST_FB";
            break;
        case XR_FACE_EXPRESSION2_LID_TIGHTENER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_LID_TIGHTENER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_LID_TIGHTENER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_LID_TIGHTENER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_CORNER_DEPRESSOR_L_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_CORNER_DEPRESSOR_L_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_CORNER_DEPRESSOR_R_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_CORNER_DEPRESSOR_R_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_CORNER_PULLER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_CORNER_PULLER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_CORNER_PULLER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_CORNER_PULLER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_FUNNELER_LB_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_FUNNELER_LB_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_FUNNELER_LT_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_FUNNELER_LT_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_FUNNELER_RB_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_FUNNELER_RB_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_FUNNELER_RT_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_FUNNELER_RT_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_PRESSOR_L_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_PRESSOR_L_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_PRESSOR_R_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_PRESSOR_R_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_PUCKER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_PUCKER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_PUCKER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_PUCKER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_STRETCHER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_STRETCHER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_STRETCHER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_STRETCHER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_SUCK_LB_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_SUCK_LB_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_SUCK_LT_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_SUCK_LT_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_SUCK_RB_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_SUCK_RB_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_SUCK_RT_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_SUCK_RT_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_TIGHTENER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_TIGHTENER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_LIP_TIGHTENER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_LIP_TIGHTENER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_LIPS_TOWARD_FB:
            jdata = "XR_FACE_EXPRESSION2_LIPS_TOWARD_FB";
            break;
        case XR_FACE_EXPRESSION2_LOWER_LIP_DEPRESSOR_L_FB:
            jdata = "XR_FACE_EXPRESSION2_LOWER_LIP_DEPRESSOR_L_FB";
            break;
        case XR_FACE_EXPRESSION2_LOWER_LIP_DEPRESSOR_R_FB:
            jdata = "XR_FACE_EXPRESSION2_LOWER_LIP_DEPRESSOR_R_FB";
            break;
        case XR_FACE_EXPRESSION2_MOUTH_LEFT_FB:
            jdata = "XR_FACE_EXPRESSION2_MOUTH_LEFT_FB";
            break;
        case XR_FACE_EXPRESSION2_MOUTH_RIGHT_FB:
            jdata = "XR_FACE_EXPRESSION2_MOUTH_RIGHT_FB";
            break;
        case XR_FACE_EXPRESSION2_NOSE_WRINKLER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_NOSE_WRINKLER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_NOSE_WRINKLER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_NOSE_WRINKLER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_OUTER_BROW_RAISER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_OUTER_BROW_RAISER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_OUTER_BROW_RAISER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_OUTER_BROW_RAISER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_UPPER_LID_RAISER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_UPPER_LID_RAISER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_UPPER_LID_RAISER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_UPPER_LID_RAISER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_UPPER_LIP_RAISER_L_FB:
            jdata = "XR_FACE_EXPRESSION2_UPPER_LIP_RAISER_L_FB";
            break;
        case XR_FACE_EXPRESSION2_UPPER_LIP_RAISER_R_FB:
            jdata = "XR_FACE_EXPRESSION2_UPPER_LIP_RAISER_R_FB";
            break;
        case XR_FACE_EXPRESSION2_TONGUE_TIP_INTERDENTAL_FB:
            jdata = "XR_FACE_EXPRESSION2_TONGUE_TIP_INTERDENTAL_FB";
            break;
        case XR_FACE_EXPRESSION2_TONGUE_TIP_ALVEOLAR_FB:
            jdata = "XR_FACE_EXPRESSION2_TONGUE_TIP_ALVEOLAR_FB";
            break;
        case XR_FACE_EXPRESSION2_TONGUE_FRONT_DORSAL_PALATE_FB:
            jdata = "XR_FACE_EXPRESSION2_TONGUE_FRONT_DORSAL_PALATE_FB";
            break;
        case XR_FACE_EXPRESSION2_TONGUE_MID_DORSAL_PALATE_FB:
            jdata = "XR_FACE_EXPRESSION2_TONGUE_MID_DORSAL_PALATE_FB";
            break;
        case XR_FACE_EXPRESSION2_TONGUE_BACK_DORSAL_VELAR_FB:
            jdata = "XR_FACE_EXPRESSION2_TONGUE_BACK_DORSAL_VELAR_FB";
            break;
        case XR_FACE_EXPRESSION2_TONGUE_OUT_FB:
            jdata = "XR_FACE_EXPRESSION2_TONGUE_OUT_FB";
            break;
        case XR_FACE_EXPRESSION2_TONGUE_RETREAT_FB:
            jdata = "XR_FACE_EXPRESSION2_TONGUE_RETREAT_FB";
            break;
        case XR_FACE_EXPRESSION2_COUNT_FB:
            jdata = "XR_FACE_EXPRESSION2_COUNT_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FACE_EXPRESSION_BROW_LOWERER_L_FB:
            jdata = "XR_FACE_EXPRESSION_BROW_LOWERER_L_FB";
            break;
        case XR_FACE_EXPRESSION_BROW_LOWERER_R_FB:
            jdata = "XR_FACE_EXPRESSION_BROW_LOWERER_R_FB";
            break;
        case XR_FACE_EXPRESSION_CHEEK_PUFF_L_FB:
            jdata = "XR_FACE_EXPRESSION_CHEEK_PUFF_L_FB";
            break;
        case XR_FACE_EXPRESSION_CHEEK_PUFF_R_FB:
            jdata = "XR_FACE_EXPRESSION_CHEEK_PUFF_R_FB";
            break;
        case XR_FACE_EXPRESSION_CHEEK_RAISER_L_FB:
            jdata = "XR_FACE_EXPRESSION_CHEEK_RAISER_L_FB";
            break;
        case XR_FACE_EXPRESSION_CHEEK_RAISER_R_FB:
            jdata = "XR_FACE_EXPRESSION_CHEEK_RAISER_R_FB";
            break;
        case XR_FACE_EXPRESSION_CHEEK_SUCK_L_FB:
            jdata = "XR_FACE_EXPRESSION_CHEEK_SUCK_L_FB";
            break;
        case XR_FACE_EXPRESSION_CHEEK_SUCK_R_FB:
            jdata = "XR_FACE_EXPRESSION_CHEEK_SUCK_R_FB";
            break;
        case XR_FACE_EXPRESSION_CHIN_RAISER_B_FB:
            jdata = "XR_FACE_EXPRESSION_CHIN_RAISER_B_FB";
            break;
        case XR_FACE_EXPRESSION_CHIN_RAISER_T_FB:
            jdata = "XR_FACE_EXPRESSION_CHIN_RAISER_T_FB";
            break;
        case XR_FACE_EXPRESSION_DIMPLER_L_FB:
            jdata = "XR_FACE_EXPRESSION_DIMPLER_L_FB";
            break;
        case XR_FACE_EXPRESSION_DIMPLER_R_FB:
            jdata = "XR_FACE_EXPRESSION_DIMPLER_R_FB";
            break;
        case XR_FACE_EXPRESSION_EYES_CLOSED_L_FB:
            jdata = "XR_FACE_EXPRESSION_EYES_CLOSED_L_FB";
            break;
        case XR_FACE_EXPRESSION_EYES_CLOSED_R_FB:
            jdata = "XR_FACE_EXPRESSION_EYES_CLOSED_R_FB";
            break;
        case XR_FACE_EXPRESSION_EYES_LOOK_DOWN_L_FB:
            jdata = "XR_FACE_EXPRESSION_EYES_LOOK_DOWN_L_FB";
            break;
        case XR_FACE_EXPRESSION_EYES_LOOK_DOWN_R_FB:
            jdata = "XR_FACE_EXPRESSION_EYES_LOOK_DOWN_R_FB";
            break;
        case XR_FACE_EXPRESSION_EYES_LOOK_LEFT_L_FB:
            jdata = "XR_FACE_EXPRESSION_EYES_LOOK_LEFT_L_FB";
            break;
        case XR_FACE_EXPRESSION_EYES_LOOK_LEFT_R_FB:
            jdata = "XR_FACE_EXPRESSION_EYES_LOOK_LEFT_R_FB";
            break;
        case XR_FACE_EXPRESSION_EYES_LOOK_RIGHT_L_FB:
            jdata = "XR_FACE_EXPRESSION_EYES_LOOK_RIGHT_L_FB";
            break;
        case XR_FACE_EXPRESSION_EYES_LOOK_RIGHT_R_FB:
            jdata = "XR_FACE_EXPRESSION_EYES_LOOK_RIGHT_R_FB";
            break;
        case XR_FACE_EXPRESSION_EYES_LOOK_UP_L_FB:
            jdata = "XR_FACE_EXPRESSION_EYES_LOOK_UP_L_FB";
            break;
        case XR_FACE_EXPRESSION_EYES_LOOK_UP_R_FB:
            jdata = "XR_FACE_EXPRESSION_EYES_LOOK_UP_R_FB";
            break;
        case XR_FACE_EXPRESSION_INNER_BROW_RAISER_L_FB:
            jdata = "XR_FACE_EXPRESSION_INNER_BROW_RAISER_L_FB";
            break;
        case XR_FACE_EXPRESSION_INNER_BROW_RAISER_R_FB:
            jdata = "XR_FACE_EXPRESSION_INNER_BROW_RAISER_R_FB";
            break;
        case XR_FACE_EXPRESSION_JAW_DROP_FB:
            jdata = "XR_FACE_EXPRESSION_JAW_DROP_FB";
            break;
        case XR_FACE_EXPRESSION_JAW_SIDEWAYS_LEFT_FB:
            jdata = "XR_FACE_EXPRESSION_JAW_SIDEWAYS_LEFT_FB";
            break;
        case XR_FACE_EXPRESSION_JAW_SIDEWAYS_RIGHT_FB:
            jdata = "XR_FACE_EXPRESSION_JAW_SIDEWAYS_RIGHT_FB";
            break;
        case XR_FACE_EXPRESSION_JAW_THRUST_FB:
            jdata = "XR_FACE_EXPRESSION_JAW_THRUST_FB";
            break;
        case XR_FACE_EXPRESSION_LID_TIGHTENER_L_FB:
            jdata = "XR_FACE_EXPRESSION_LID_TIGHTENER_L_FB";
            break;
        case XR_FACE_EXPRESSION_LID_TIGHTENER_R_FB:
            jdata = "XR_FACE_EXPRESSION_LID_TIGHTENER_R_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_CORNER_DEPRESSOR_L_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_CORNER_DEPRESSOR_L_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_CORNER_DEPRESSOR_R_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_CORNER_DEPRESSOR_R_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_CORNER_PULLER_L_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_CORNER_PULLER_L_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_CORNER_PULLER_R_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_CORNER_PULLER_R_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_FUNNELER_LB_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_FUNNELER_LB_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_FUNNELER_LT_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_FUNNELER_LT_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_FUNNELER_RB_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_FUNNELER_RB_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_FUNNELER_RT_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_FUNNELER_RT_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_PRESSOR_L_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_PRESSOR_L_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_PRESSOR_R_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_PRESSOR_R_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_PUCKER_L_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_PUCKER_L_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_PUCKER_R_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_PUCKER_R_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_STRETCHER_L_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_STRETCHER_L_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_STRETCHER_R_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_STRETCHER_R_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_SUCK_LB_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_SUCK_LB_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_SUCK_LT_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_SUCK_LT_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_SUCK_RB_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_SUCK_RB_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_SUCK_RT_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_SUCK_RT_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_TIGHTENER_L_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_TIGHTENER_L_FB";
            break;
        case XR_FACE_EXPRESSION_LIP_TIGHTENER_R_FB:
            jdata = "XR_FACE_EXPRESSION_LIP_TIGHTENER_R_FB";
            break;
        case XR_FACE_EXPRESSION_LIPS_TOWARD_FB:
            jdata = "XR_FACE_EXPRESSION_LIPS_TOWARD_FB";
            break;
        case XR_FACE_EXPRESSION_LOWER_LIP_DEPRESSOR_L_FB:
            jdata = "XR_FACE_EXPRESSION_LOWER_LIP_DEPRESSOR_L_FB";
            break;
        case XR_FACE_EXPRESSION_LOWER_LIP_DEPRESSOR_R_FB:
            jdata = "XR_FACE_EXPRESSION_LOWER_LIP_DEPRESSOR_R_FB";
            break;
        case XR_FACE_EXPRESSION_MOUTH_LEFT_FB:
            jdata = "XR_FACE_EXPRESSION_MOUTH_LEFT_FB";
            break;
        case XR_FACE_EXPRESSION_MOUTH_RIGHT_FB:
            jdata = "XR_FACE_EXPRESSION_MOUTH_RIGHT_FB";
            break;
        case XR_FACE_EXPRESSION_NOSE_WRINKLER_L_FB:
            jdata = "XR_FACE_EXPRESSION_NOSE_WRINKLER_L_FB";
            break;
        case XR_FACE_EXPRESSION_NOSE_WRINKLER_R_FB:
            jdata = "XR_FACE_EXPRESSION_NOSE_WRINKLER_R_FB";
            break;
        case XR_FACE_EXPRESSION_OUTER_BROW_RAISER_L_FB:
            jdata = "XR_FACE_EXPRESSION_OUTER_BROW_RAISER_L_FB";
            break;
        case XR_FACE_EXPRESSION_OUTER_BROW_RAISER_R_FB:
            jdata = "XR_FACE_EXPRESSION_OUTER_BROW_RAISER_R_FB";
            break;
        case XR_FACE_EXPRESSION_UPPER_LID_RAISER_L_FB:
            jdata = "XR_FACE_EXPRESSION_UPPER_LID_RAISER_L_FB";
            break;
        case XR_FACE_EXPRESSION_UPPER_LID_RAISER_R_FB:
            jdata = "XR_FACE_EXPRESSION_UPPER_LID_RAISER_R_FB";
            break;
        case XR_FACE_EXPRESSION_UPPER_LIP_RAISER_L_FB:
            jdata = "XR_FACE_EXPRESSION_UPPER_LIP_RAISER_L_FB";
            break;
        case XR_FACE_EXPRESSION_UPPER_LIP_RAISER_R_FB:
            jdata = "XR_FACE_EXPRESSION_UPPER_LIP_RAISER_R_FB";
            break;
        case XR_FACE_EXPRESSION_COUNT_FB:
            jdata = "XR_FACE_EXPRESSION_COUNT_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionSet2FB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FACE_EXPRESSION_SET2_DEFAULT_FB:
            jdata = "XR_FACE_EXPRESSION_SET2_DEFAULT_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceExpressionSetFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FACE_EXPRESSION_SET_DEFAULT_FB:
            jdata = "XR_FACE_EXPRESSION_SET_DEFAULT_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFaceTrackingDataSource2FB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FACE_TRACKING_DATA_SOURCE2_VISUAL_FB:
            jdata = "XR_FACE_TRACKING_DATA_SOURCE2_VISUAL_FB";
            break;
        case XR_FACE_TRACKING_DATA_SOURCE2_AUDIO_FB:
            jdata = "XR_FACE_TRACKING_DATA_SOURCE2_AUDIO_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFacialTrackingTypeHTC& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FACIAL_TRACKING_TYPE_EYE_DEFAULT_HTC:
            jdata = "XR_FACIAL_TRACKING_TYPE_EYE_DEFAULT_HTC";
            break;
        case XR_FACIAL_TRACKING_TYPE_LIP_DEFAULT_HTC:
            jdata = "XR_FACIAL_TRACKING_TYPE_LIP_DEFAULT_HTC";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrForceFeedbackCurlLocationMNDX& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FORCE_FEEDBACK_CURL_LOCATION_THUMB_CURL_MNDX:
            jdata = "XR_FORCE_FEEDBACK_CURL_LOCATION_THUMB_CURL_MNDX";
            break;
        case XR_FORCE_FEEDBACK_CURL_LOCATION_INDEX_CURL_MNDX:
            jdata = "XR_FORCE_FEEDBACK_CURL_LOCATION_INDEX_CURL_MNDX";
            break;
        case XR_FORCE_FEEDBACK_CURL_LOCATION_MIDDLE_CURL_MNDX:
            jdata = "XR_FORCE_FEEDBACK_CURL_LOCATION_MIDDLE_CURL_MNDX";
            break;
        case XR_FORCE_FEEDBACK_CURL_LOCATION_RING_CURL_MNDX:
            jdata = "XR_FORCE_FEEDBACK_CURL_LOCATION_RING_CURL_MNDX";
            break;
        case XR_FORCE_FEEDBACK_CURL_LOCATION_LITTLE_CURL_MNDX:
            jdata = "XR_FORCE_FEEDBACK_CURL_LOCATION_LITTLE_CURL_MNDX";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFormFactor& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY:
            jdata = "XR_FORM_FACTOR_HEAD_MOUNTED_DISPLAY";
            break;
        case XR_FORM_FACTOR_HANDHELD_DISPLAY:
            jdata = "XR_FORM_FACTOR_HANDHELD_DISPLAY";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationDynamicFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FOVEATION_DYNAMIC_DISABLED_FB:
            jdata = "XR_FOVEATION_DYNAMIC_DISABLED_FB";
            break;
        case XR_FOVEATION_DYNAMIC_LEVEL_ENABLED_FB:
            jdata = "XR_FOVEATION_DYNAMIC_LEVEL_ENABLED_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationLevelFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FOVEATION_LEVEL_NONE_FB:
            jdata = "XR_FOVEATION_LEVEL_NONE_FB";
            break;
        case XR_FOVEATION_LEVEL_LOW_FB:
            jdata = "XR_FOVEATION_LEVEL_LOW_FB";
            break;
        case XR_FOVEATION_LEVEL_MEDIUM_FB:
            jdata = "XR_FOVEATION_LEVEL_MEDIUM_FB";
            break;
        case XR_FOVEATION_LEVEL_HIGH_FB:
            jdata = "XR_FOVEATION_LEVEL_HIGH_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationLevelHTC& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FOVEATION_LEVEL_NONE_HTC:
            jdata = "XR_FOVEATION_LEVEL_NONE_HTC";
            break;
        case XR_FOVEATION_LEVEL_LOW_HTC:
            jdata = "XR_FOVEATION_LEVEL_LOW_HTC";
            break;
        case XR_FOVEATION_LEVEL_MEDIUM_HTC:
            jdata = "XR_FOVEATION_LEVEL_MEDIUM_HTC";
            break;
        case XR_FOVEATION_LEVEL_HIGH_HTC:
            jdata = "XR_FOVEATION_LEVEL_HIGH_HTC";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrFoveationModeHTC& value, const JsonOptions& options)
{
    switch (value) {
        case XR_FOVEATION_MODE_DISABLE_HTC:
            jdata = "XR_FOVEATION_MODE_DISABLE_HTC";
            break;
        case XR_FOVEATION_MODE_FIXED_HTC:
            jdata = "XR_FOVEATION_MODE_FIXED_HTC";
            break;
        case XR_FOVEATION_MODE_DYNAMIC_HTC:
            jdata = "XR_FOVEATION_MODE_DYNAMIC_HTC";
            break;
        case XR_FOVEATION_MODE_CUSTOM_HTC:
            jdata = "XR_FOVEATION_MODE_CUSTOM_HTC";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrHandEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_HAND_LEFT_EXT:
            jdata = "XR_HAND_LEFT_EXT";
            break;
        case XR_HAND_RIGHT_EXT:
            jdata = "XR_HAND_RIGHT_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrHandForearmJointULTRALEAP& value, const JsonOptions& options)
{
    switch (value) {
        case XR_HAND_FOREARM_JOINT_PALM_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_PALM_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_WRIST_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_WRIST_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_THUMB_METACARPAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_THUMB_METACARPAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_THUMB_PROXIMAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_THUMB_PROXIMAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_THUMB_DISTAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_THUMB_DISTAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_THUMB_TIP_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_THUMB_TIP_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_INDEX_METACARPAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_INDEX_METACARPAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_INDEX_PROXIMAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_INDEX_PROXIMAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_INDEX_INTERMEDIATE_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_INDEX_INTERMEDIATE_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_INDEX_DISTAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_INDEX_DISTAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_INDEX_TIP_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_INDEX_TIP_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_MIDDLE_METACARPAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_MIDDLE_METACARPAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_MIDDLE_PROXIMAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_MIDDLE_PROXIMAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_MIDDLE_INTERMEDIATE_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_MIDDLE_INTERMEDIATE_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_MIDDLE_DISTAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_MIDDLE_DISTAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_MIDDLE_TIP_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_MIDDLE_TIP_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_RING_METACARPAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_RING_METACARPAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_RING_PROXIMAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_RING_PROXIMAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_RING_INTERMEDIATE_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_RING_INTERMEDIATE_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_RING_DISTAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_RING_DISTAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_RING_TIP_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_RING_TIP_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_LITTLE_METACARPAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_LITTLE_METACARPAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_LITTLE_PROXIMAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_LITTLE_PROXIMAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_LITTLE_INTERMEDIATE_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_LITTLE_INTERMEDIATE_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_LITTLE_DISTAL_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_LITTLE_DISTAL_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_LITTLE_TIP_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_LITTLE_TIP_ULTRALEAP";
            break;
        case XR_HAND_FOREARM_JOINT_ELBOW_ULTRALEAP:
            jdata = "XR_HAND_FOREARM_JOINT_ELBOW_ULTRALEAP";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrHandJointEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_HAND_JOINT_PALM_EXT:
            jdata = "XR_HAND_JOINT_PALM_EXT";
            break;
        case XR_HAND_JOINT_WRIST_EXT:
            jdata = "XR_HAND_JOINT_WRIST_EXT";
            break;
        case XR_HAND_JOINT_THUMB_METACARPAL_EXT:
            jdata = "XR_HAND_JOINT_THUMB_METACARPAL_EXT";
            break;
        case XR_HAND_JOINT_THUMB_PROXIMAL_EXT:
            jdata = "XR_HAND_JOINT_THUMB_PROXIMAL_EXT";
            break;
        case XR_HAND_JOINT_THUMB_DISTAL_EXT:
            jdata = "XR_HAND_JOINT_THUMB_DISTAL_EXT";
            break;
        case XR_HAND_JOINT_THUMB_TIP_EXT:
            jdata = "XR_HAND_JOINT_THUMB_TIP_EXT";
            break;
        case XR_HAND_JOINT_INDEX_METACARPAL_EXT:
            jdata = "XR_HAND_JOINT_INDEX_METACARPAL_EXT";
            break;
        case XR_HAND_JOINT_INDEX_PROXIMAL_EXT:
            jdata = "XR_HAND_JOINT_INDEX_PROXIMAL_EXT";
            break;
        case XR_HAND_JOINT_INDEX_INTERMEDIATE_EXT:
            jdata = "XR_HAND_JOINT_INDEX_INTERMEDIATE_EXT";
            break;
        case XR_HAND_JOINT_INDEX_DISTAL_EXT:
            jdata = "XR_HAND_JOINT_INDEX_DISTAL_EXT";
            break;
        case XR_HAND_JOINT_INDEX_TIP_EXT:
            jdata = "XR_HAND_JOINT_INDEX_TIP_EXT";
            break;
        case XR_HAND_JOINT_MIDDLE_METACARPAL_EXT:
            jdata = "XR_HAND_JOINT_MIDDLE_METACARPAL_EXT";
            break;
        case XR_HAND_JOINT_MIDDLE_PROXIMAL_EXT:
            jdata = "XR_HAND_JOINT_MIDDLE_PROXIMAL_EXT";
            break;
        case XR_HAND_JOINT_MIDDLE_INTERMEDIATE_EXT:
            jdata = "XR_HAND_JOINT_MIDDLE_INTERMEDIATE_EXT";
            break;
        case XR_HAND_JOINT_MIDDLE_DISTAL_EXT:
            jdata = "XR_HAND_JOINT_MIDDLE_DISTAL_EXT";
            break;
        case XR_HAND_JOINT_MIDDLE_TIP_EXT:
            jdata = "XR_HAND_JOINT_MIDDLE_TIP_EXT";
            break;
        case XR_HAND_JOINT_RING_METACARPAL_EXT:
            jdata = "XR_HAND_JOINT_RING_METACARPAL_EXT";
            break;
        case XR_HAND_JOINT_RING_PROXIMAL_EXT:
            jdata = "XR_HAND_JOINT_RING_PROXIMAL_EXT";
            break;
        case XR_HAND_JOINT_RING_INTERMEDIATE_EXT:
            jdata = "XR_HAND_JOINT_RING_INTERMEDIATE_EXT";
            break;
        case XR_HAND_JOINT_RING_DISTAL_EXT:
            jdata = "XR_HAND_JOINT_RING_DISTAL_EXT";
            break;
        case XR_HAND_JOINT_RING_TIP_EXT:
            jdata = "XR_HAND_JOINT_RING_TIP_EXT";
            break;
        case XR_HAND_JOINT_LITTLE_METACARPAL_EXT:
            jdata = "XR_HAND_JOINT_LITTLE_METACARPAL_EXT";
            break;
        case XR_HAND_JOINT_LITTLE_PROXIMAL_EXT:
            jdata = "XR_HAND_JOINT_LITTLE_PROXIMAL_EXT";
            break;
        case XR_HAND_JOINT_LITTLE_INTERMEDIATE_EXT:
            jdata = "XR_HAND_JOINT_LITTLE_INTERMEDIATE_EXT";
            break;
        case XR_HAND_JOINT_LITTLE_DISTAL_EXT:
            jdata = "XR_HAND_JOINT_LITTLE_DISTAL_EXT";
            break;
        case XR_HAND_JOINT_LITTLE_TIP_EXT:
            jdata = "XR_HAND_JOINT_LITTLE_TIP_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrHandJointSetEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_HAND_JOINT_SET_DEFAULT_EXT:
            jdata = "XR_HAND_JOINT_SET_DEFAULT_EXT";
            break;
        case XR_HAND_JOINT_SET_HAND_WITH_FOREARM_ULTRALEAP:
            jdata = "XR_HAND_JOINT_SET_HAND_WITH_FOREARM_ULTRALEAP";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrHandJointsMotionRangeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_HAND_JOINTS_MOTION_RANGE_UNOBSTRUCTED_EXT:
            jdata = "XR_HAND_JOINTS_MOTION_RANGE_UNOBSTRUCTED_EXT";
            break;
        case XR_HAND_JOINTS_MOTION_RANGE_CONFORMING_TO_CONTROLLER_EXT:
            jdata = "XR_HAND_JOINTS_MOTION_RANGE_CONFORMING_TO_CONTROLLER_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrHandPoseTypeMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_HAND_POSE_TYPE_TRACKED_MSFT:
            jdata = "XR_HAND_POSE_TYPE_TRACKED_MSFT";
            break;
        case XR_HAND_POSE_TYPE_REFERENCE_OPEN_PALM_MSFT:
            jdata = "XR_HAND_POSE_TYPE_REFERENCE_OPEN_PALM_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrHandTrackingDataSourceEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_HAND_TRACKING_DATA_SOURCE_UNOBSTRUCTED_EXT:
            jdata = "XR_HAND_TRACKING_DATA_SOURCE_UNOBSTRUCTED_EXT";
            break;
        case XR_HAND_TRACKING_DATA_SOURCE_CONTROLLER_EXT:
            jdata = "XR_HAND_TRACKING_DATA_SOURCE_CONTROLLER_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrHeadsetFitStatusML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_HEADSET_FIT_STATUS_UNKNOWN_ML:
            jdata = "XR_HEADSET_FIT_STATUS_UNKNOWN_ML";
            break;
        case XR_HEADSET_FIT_STATUS_NOT_WORN_ML:
            jdata = "XR_HEADSET_FIT_STATUS_NOT_WORN_ML";
            break;
        case XR_HEADSET_FIT_STATUS_GOOD_FIT_ML:
            jdata = "XR_HEADSET_FIT_STATUS_GOOD_FIT_ML";
            break;
        case XR_HEADSET_FIT_STATUS_BAD_FIT_ML:
            jdata = "XR_HEADSET_FIT_STATUS_BAD_FIT_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrLipExpressionHTC& value, const JsonOptions& options)
{
    switch (value) {
        case XR_LIP_EXPRESSION_JAW_RIGHT_HTC:
            jdata = "XR_LIP_EXPRESSION_JAW_RIGHT_HTC";
            break;
        case XR_LIP_EXPRESSION_JAW_LEFT_HTC:
            jdata = "XR_LIP_EXPRESSION_JAW_LEFT_HTC";
            break;
        case XR_LIP_EXPRESSION_JAW_FORWARD_HTC:
            jdata = "XR_LIP_EXPRESSION_JAW_FORWARD_HTC";
            break;
        case XR_LIP_EXPRESSION_JAW_OPEN_HTC:
            jdata = "XR_LIP_EXPRESSION_JAW_OPEN_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_APE_SHAPE_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_APE_SHAPE_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_UPPER_RIGHT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_UPPER_RIGHT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_UPPER_LEFT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_UPPER_LEFT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_LOWER_RIGHT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_LOWER_RIGHT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_LOWER_LEFT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_LOWER_LEFT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_UPPER_OVERTURN_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_UPPER_OVERTURN_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_LOWER_OVERTURN_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_LOWER_OVERTURN_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_POUT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_POUT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_SMILE_RIGHT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_SMILE_RIGHT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_SMILE_LEFT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_SMILE_LEFT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_SAD_RIGHT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_SAD_RIGHT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_SAD_LEFT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_SAD_LEFT_HTC";
            break;
        case XR_LIP_EXPRESSION_CHEEK_PUFF_RIGHT_HTC:
            jdata = "XR_LIP_EXPRESSION_CHEEK_PUFF_RIGHT_HTC";
            break;
        case XR_LIP_EXPRESSION_CHEEK_PUFF_LEFT_HTC:
            jdata = "XR_LIP_EXPRESSION_CHEEK_PUFF_LEFT_HTC";
            break;
        case XR_LIP_EXPRESSION_CHEEK_SUCK_HTC:
            jdata = "XR_LIP_EXPRESSION_CHEEK_SUCK_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_UPPER_UPRIGHT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_UPPER_UPRIGHT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_UPPER_UPLEFT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_UPPER_UPLEFT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_LOWER_DOWNRIGHT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_LOWER_DOWNRIGHT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_LOWER_DOWNLEFT_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_LOWER_DOWNLEFT_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_UPPER_INSIDE_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_UPPER_INSIDE_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_LOWER_INSIDE_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_LOWER_INSIDE_HTC";
            break;
        case XR_LIP_EXPRESSION_MOUTH_LOWER_OVERLAY_HTC:
            jdata = "XR_LIP_EXPRESSION_MOUTH_LOWER_OVERLAY_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_LONGSTEP1_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_LONGSTEP1_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_LEFT_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_LEFT_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_RIGHT_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_RIGHT_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_UP_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_UP_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_DOWN_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_DOWN_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_ROLL_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_ROLL_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_LONGSTEP2_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_LONGSTEP2_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_UPRIGHT_MORPH_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_UPRIGHT_MORPH_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_UPLEFT_MORPH_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_UPLEFT_MORPH_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_DOWNRIGHT_MORPH_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_DOWNRIGHT_MORPH_HTC";
            break;
        case XR_LIP_EXPRESSION_TONGUE_DOWNLEFT_MORPH_HTC:
            jdata = "XR_LIP_EXPRESSION_TONGUE_DOWNLEFT_MORPH_HTC";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrLoaderInterfaceStructs& value, const JsonOptions& options)
{
    switch (value) {
        case XR_LOADER_INTERFACE_STRUCT_UNINTIALIZED:
            jdata = "XR_LOADER_INTERFACE_STRUCT_UNINTIALIZED";
            break;
        case XR_LOADER_INTERFACE_STRUCT_LOADER_INFO:
            jdata = "XR_LOADER_INTERFACE_STRUCT_LOADER_INFO";
            break;
        case XR_LOADER_INTERFACE_STRUCT_API_LAYER_REQUEST:
            jdata = "XR_LOADER_INTERFACE_STRUCT_API_LAYER_REQUEST";
            break;
        case XR_LOADER_INTERFACE_STRUCT_RUNTIME_REQUEST:
            jdata = "XR_LOADER_INTERFACE_STRUCT_RUNTIME_REQUEST";
            break;
        case XR_LOADER_INTERFACE_STRUCT_API_LAYER_CREATE_INFO:
            jdata = "XR_LOADER_INTERFACE_STRUCT_API_LAYER_CREATE_INFO";
            break;
        case XR_LOADER_INTERFACE_STRUCT_API_LAYER_NEXT_INFO:
            jdata = "XR_LOADER_INTERFACE_STRUCT_API_LAYER_NEXT_INFO";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalDimmingModeMETA& value, const JsonOptions& options)
{
    switch (value) {
        case XR_LOCAL_DIMMING_MODE_OFF_META:
            jdata = "XR_LOCAL_DIMMING_MODE_OFF_META";
            break;
        case XR_LOCAL_DIMMING_MODE_ON_META:
            jdata = "XR_LOCAL_DIMMING_MODE_ON_META";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapConfidenceML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_LOCALIZATION_MAP_CONFIDENCE_POOR_ML:
            jdata = "XR_LOCALIZATION_MAP_CONFIDENCE_POOR_ML";
            break;
        case XR_LOCALIZATION_MAP_CONFIDENCE_FAIR_ML:
            jdata = "XR_LOCALIZATION_MAP_CONFIDENCE_FAIR_ML";
            break;
        case XR_LOCALIZATION_MAP_CONFIDENCE_GOOD_ML:
            jdata = "XR_LOCALIZATION_MAP_CONFIDENCE_GOOD_ML";
            break;
        case XR_LOCALIZATION_MAP_CONFIDENCE_EXCELLENT_ML:
            jdata = "XR_LOCALIZATION_MAP_CONFIDENCE_EXCELLENT_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapStateML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_LOCALIZATION_MAP_STATE_NOT_LOCALIZED_ML:
            jdata = "XR_LOCALIZATION_MAP_STATE_NOT_LOCALIZED_ML";
            break;
        case XR_LOCALIZATION_MAP_STATE_LOCALIZED_ML:
            jdata = "XR_LOCALIZATION_MAP_STATE_LOCALIZED_ML";
            break;
        case XR_LOCALIZATION_MAP_STATE_LOCALIZATION_PENDING_ML:
            jdata = "XR_LOCALIZATION_MAP_STATE_LOCALIZATION_PENDING_ML";
            break;
        case XR_LOCALIZATION_MAP_STATE_LOCALIZATION_SLEEPING_BEFORE_RETRY_ML:
            jdata = "XR_LOCALIZATION_MAP_STATE_LOCALIZATION_SLEEPING_BEFORE_RETRY_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrLocalizationMapTypeML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_LOCALIZATION_MAP_TYPE_ON_DEVICE_ML:
            jdata = "XR_LOCALIZATION_MAP_TYPE_ON_DEVICE_ML";
            break;
        case XR_LOCALIZATION_MAP_TYPE_CLOUD_ML:
            jdata = "XR_LOCALIZATION_MAP_TYPE_CLOUD_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerAprilTagDictML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MARKER_APRIL_TAG_DICT_16H5_ML:
            jdata = "XR_MARKER_APRIL_TAG_DICT_16H5_ML";
            break;
        case XR_MARKER_APRIL_TAG_DICT_25H9_ML:
            jdata = "XR_MARKER_APRIL_TAG_DICT_25H9_ML";
            break;
        case XR_MARKER_APRIL_TAG_DICT_36H10_ML:
            jdata = "XR_MARKER_APRIL_TAG_DICT_36H10_ML";
            break;
        case XR_MARKER_APRIL_TAG_DICT_36H11_ML:
            jdata = "XR_MARKER_APRIL_TAG_DICT_36H11_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerArucoDictML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MARKER_ARUCO_DICT_4X4_50_ML:
            jdata = "XR_MARKER_ARUCO_DICT_4X4_50_ML";
            break;
        case XR_MARKER_ARUCO_DICT_4X4_100_ML:
            jdata = "XR_MARKER_ARUCO_DICT_4X4_100_ML";
            break;
        case XR_MARKER_ARUCO_DICT_4X4_250_ML:
            jdata = "XR_MARKER_ARUCO_DICT_4X4_250_ML";
            break;
        case XR_MARKER_ARUCO_DICT_4X4_1000_ML:
            jdata = "XR_MARKER_ARUCO_DICT_4X4_1000_ML";
            break;
        case XR_MARKER_ARUCO_DICT_5X5_50_ML:
            jdata = "XR_MARKER_ARUCO_DICT_5X5_50_ML";
            break;
        case XR_MARKER_ARUCO_DICT_5X5_100_ML:
            jdata = "XR_MARKER_ARUCO_DICT_5X5_100_ML";
            break;
        case XR_MARKER_ARUCO_DICT_5X5_250_ML:
            jdata = "XR_MARKER_ARUCO_DICT_5X5_250_ML";
            break;
        case XR_MARKER_ARUCO_DICT_5X5_1000_ML:
            jdata = "XR_MARKER_ARUCO_DICT_5X5_1000_ML";
            break;
        case XR_MARKER_ARUCO_DICT_6X6_50_ML:
            jdata = "XR_MARKER_ARUCO_DICT_6X6_50_ML";
            break;
        case XR_MARKER_ARUCO_DICT_6X6_100_ML:
            jdata = "XR_MARKER_ARUCO_DICT_6X6_100_ML";
            break;
        case XR_MARKER_ARUCO_DICT_6X6_250_ML:
            jdata = "XR_MARKER_ARUCO_DICT_6X6_250_ML";
            break;
        case XR_MARKER_ARUCO_DICT_6X6_1000_ML:
            jdata = "XR_MARKER_ARUCO_DICT_6X6_1000_ML";
            break;
        case XR_MARKER_ARUCO_DICT_7X7_50_ML:
            jdata = "XR_MARKER_ARUCO_DICT_7X7_50_ML";
            break;
        case XR_MARKER_ARUCO_DICT_7X7_100_ML:
            jdata = "XR_MARKER_ARUCO_DICT_7X7_100_ML";
            break;
        case XR_MARKER_ARUCO_DICT_7X7_250_ML:
            jdata = "XR_MARKER_ARUCO_DICT_7X7_250_ML";
            break;
        case XR_MARKER_ARUCO_DICT_7X7_1000_ML:
            jdata = "XR_MARKER_ARUCO_DICT_7X7_1000_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorCameraML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MARKER_DETECTOR_CAMERA_RGB_CAMERA_ML:
            jdata = "XR_MARKER_DETECTOR_CAMERA_RGB_CAMERA_ML";
            break;
        case XR_MARKER_DETECTOR_CAMERA_WORLD_CAMERAS_ML:
            jdata = "XR_MARKER_DETECTOR_CAMERA_WORLD_CAMERAS_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorCornerRefineMethodML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MARKER_DETECTOR_CORNER_REFINE_METHOD_NONE_ML:
            jdata = "XR_MARKER_DETECTOR_CORNER_REFINE_METHOD_NONE_ML";
            break;
        case XR_MARKER_DETECTOR_CORNER_REFINE_METHOD_SUBPIX_ML:
            jdata = "XR_MARKER_DETECTOR_CORNER_REFINE_METHOD_SUBPIX_ML";
            break;
        case XR_MARKER_DETECTOR_CORNER_REFINE_METHOD_CONTOUR_ML:
            jdata = "XR_MARKER_DETECTOR_CORNER_REFINE_METHOD_CONTOUR_ML";
            break;
        case XR_MARKER_DETECTOR_CORNER_REFINE_METHOD_APRIL_TAG_ML:
            jdata = "XR_MARKER_DETECTOR_CORNER_REFINE_METHOD_APRIL_TAG_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorFpsML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MARKER_DETECTOR_FPS_LOW_ML:
            jdata = "XR_MARKER_DETECTOR_FPS_LOW_ML";
            break;
        case XR_MARKER_DETECTOR_FPS_MEDIUM_ML:
            jdata = "XR_MARKER_DETECTOR_FPS_MEDIUM_ML";
            break;
        case XR_MARKER_DETECTOR_FPS_HIGH_ML:
            jdata = "XR_MARKER_DETECTOR_FPS_HIGH_ML";
            break;
        case XR_MARKER_DETECTOR_FPS_MAX_ML:
            jdata = "XR_MARKER_DETECTOR_FPS_MAX_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorFullAnalysisIntervalML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MARKER_DETECTOR_FULL_ANALYSIS_INTERVAL_MAX_ML:
            jdata = "XR_MARKER_DETECTOR_FULL_ANALYSIS_INTERVAL_MAX_ML";
            break;
        case XR_MARKER_DETECTOR_FULL_ANALYSIS_INTERVAL_FAST_ML:
            jdata = "XR_MARKER_DETECTOR_FULL_ANALYSIS_INTERVAL_FAST_ML";
            break;
        case XR_MARKER_DETECTOR_FULL_ANALYSIS_INTERVAL_MEDIUM_ML:
            jdata = "XR_MARKER_DETECTOR_FULL_ANALYSIS_INTERVAL_MEDIUM_ML";
            break;
        case XR_MARKER_DETECTOR_FULL_ANALYSIS_INTERVAL_SLOW_ML:
            jdata = "XR_MARKER_DETECTOR_FULL_ANALYSIS_INTERVAL_SLOW_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorProfileML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MARKER_DETECTOR_PROFILE_DEFAULT_ML:
            jdata = "XR_MARKER_DETECTOR_PROFILE_DEFAULT_ML";
            break;
        case XR_MARKER_DETECTOR_PROFILE_SPEED_ML:
            jdata = "XR_MARKER_DETECTOR_PROFILE_SPEED_ML";
            break;
        case XR_MARKER_DETECTOR_PROFILE_ACCURACY_ML:
            jdata = "XR_MARKER_DETECTOR_PROFILE_ACCURACY_ML";
            break;
        case XR_MARKER_DETECTOR_PROFILE_SMALL_TARGETS_ML:
            jdata = "XR_MARKER_DETECTOR_PROFILE_SMALL_TARGETS_ML";
            break;
        case XR_MARKER_DETECTOR_PROFILE_LARGE_FOV_ML:
            jdata = "XR_MARKER_DETECTOR_PROFILE_LARGE_FOV_ML";
            break;
        case XR_MARKER_DETECTOR_PROFILE_CUSTOM_ML:
            jdata = "XR_MARKER_DETECTOR_PROFILE_CUSTOM_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorResolutionML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MARKER_DETECTOR_RESOLUTION_LOW_ML:
            jdata = "XR_MARKER_DETECTOR_RESOLUTION_LOW_ML";
            break;
        case XR_MARKER_DETECTOR_RESOLUTION_MEDIUM_ML:
            jdata = "XR_MARKER_DETECTOR_RESOLUTION_MEDIUM_ML";
            break;
        case XR_MARKER_DETECTOR_RESOLUTION_HIGH_ML:
            jdata = "XR_MARKER_DETECTOR_RESOLUTION_HIGH_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerDetectorStatusML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MARKER_DETECTOR_STATUS_PENDING_ML:
            jdata = "XR_MARKER_DETECTOR_STATUS_PENDING_ML";
            break;
        case XR_MARKER_DETECTOR_STATUS_READY_ML:
            jdata = "XR_MARKER_DETECTOR_STATUS_READY_ML";
            break;
        case XR_MARKER_DETECTOR_STATUS_ERROR_ML:
            jdata = "XR_MARKER_DETECTOR_STATUS_ERROR_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMarkerTypeML& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MARKER_TYPE_ARUCO_ML:
            jdata = "XR_MARKER_TYPE_ARUCO_ML";
            break;
        case XR_MARKER_TYPE_APRIL_TAG_ML:
            jdata = "XR_MARKER_TYPE_APRIL_TAG_ML";
            break;
        case XR_MARKER_TYPE_QR_ML:
            jdata = "XR_MARKER_TYPE_QR_ML";
            break;
        case XR_MARKER_TYPE_EAN_13_ML:
            jdata = "XR_MARKER_TYPE_EAN_13_ML";
            break;
        case XR_MARKER_TYPE_UPC_A_ML:
            jdata = "XR_MARKER_TYPE_UPC_A_ML";
            break;
        case XR_MARKER_TYPE_CODE_128_ML:
            jdata = "XR_MARKER_TYPE_CODE_128_ML";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrMeshComputeLodMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_MESH_COMPUTE_LOD_COARSE_MSFT:
            jdata = "XR_MESH_COMPUTE_LOD_COARSE_MSFT";
            break;
        case XR_MESH_COMPUTE_LOD_MEDIUM_MSFT:
            jdata = "XR_MESH_COMPUTE_LOD_MEDIUM_MSFT";
            break;
        case XR_MESH_COMPUTE_LOD_FINE_MSFT:
            jdata = "XR_MESH_COMPUTE_LOD_FINE_MSFT";
            break;
        case XR_MESH_COMPUTE_LOD_UNLIMITED_MSFT:
            jdata = "XR_MESH_COMPUTE_LOD_UNLIMITED_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrObjectType& value, const JsonOptions& options)
{
    switch (value) {
        case XR_OBJECT_TYPE_UNKNOWN:
            jdata = "XR_OBJECT_TYPE_UNKNOWN";
            break;
        case XR_OBJECT_TYPE_INSTANCE:
            jdata = "XR_OBJECT_TYPE_INSTANCE";
            break;
        case XR_OBJECT_TYPE_SESSION:
            jdata = "XR_OBJECT_TYPE_SESSION";
            break;
        case XR_OBJECT_TYPE_SWAPCHAIN:
            jdata = "XR_OBJECT_TYPE_SWAPCHAIN";
            break;
        case XR_OBJECT_TYPE_SPACE:
            jdata = "XR_OBJECT_TYPE_SPACE";
            break;
        case XR_OBJECT_TYPE_ACTION_SET:
            jdata = "XR_OBJECT_TYPE_ACTION_SET";
            break;
        case XR_OBJECT_TYPE_ACTION:
            jdata = "XR_OBJECT_TYPE_ACTION";
            break;
        case XR_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT:
            jdata = "XR_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT";
            break;
        case XR_OBJECT_TYPE_SPATIAL_ANCHOR_MSFT:
            jdata = "XR_OBJECT_TYPE_SPATIAL_ANCHOR_MSFT";
            break;
        case XR_OBJECT_TYPE_SPATIAL_GRAPH_NODE_BINDING_MSFT:
            jdata = "XR_OBJECT_TYPE_SPATIAL_GRAPH_NODE_BINDING_MSFT";
            break;
        case XR_OBJECT_TYPE_HAND_TRACKER_EXT:
            jdata = "XR_OBJECT_TYPE_HAND_TRACKER_EXT";
            break;
        case XR_OBJECT_TYPE_BODY_TRACKER_FB:
            jdata = "XR_OBJECT_TYPE_BODY_TRACKER_FB";
            break;
        case XR_OBJECT_TYPE_SCENE_OBSERVER_MSFT:
            jdata = "XR_OBJECT_TYPE_SCENE_OBSERVER_MSFT";
            break;
        case XR_OBJECT_TYPE_SCENE_MSFT:
            jdata = "XR_OBJECT_TYPE_SCENE_MSFT";
            break;
        case XR_OBJECT_TYPE_FACIAL_TRACKER_HTC:
            jdata = "XR_OBJECT_TYPE_FACIAL_TRACKER_HTC";
            break;
        case XR_OBJECT_TYPE_FOVEATION_PROFILE_FB:
            jdata = "XR_OBJECT_TYPE_FOVEATION_PROFILE_FB";
            break;
        case XR_OBJECT_TYPE_TRIANGLE_MESH_FB:
            jdata = "XR_OBJECT_TYPE_TRIANGLE_MESH_FB";
            break;
        case XR_OBJECT_TYPE_PASSTHROUGH_FB:
            jdata = "XR_OBJECT_TYPE_PASSTHROUGH_FB";
            break;
        case XR_OBJECT_TYPE_PASSTHROUGH_LAYER_FB:
            jdata = "XR_OBJECT_TYPE_PASSTHROUGH_LAYER_FB";
            break;
        case XR_OBJECT_TYPE_GEOMETRY_INSTANCE_FB:
            jdata = "XR_OBJECT_TYPE_GEOMETRY_INSTANCE_FB";
            break;
        case XR_OBJECT_TYPE_MARKER_DETECTOR_ML:
            jdata = "XR_OBJECT_TYPE_MARKER_DETECTOR_ML";
            break;
        case XR_OBJECT_TYPE_EXPORTED_LOCALIZATION_MAP_ML:
            jdata = "XR_OBJECT_TYPE_EXPORTED_LOCALIZATION_MAP_ML";
            break;
        case XR_OBJECT_TYPE_SPATIAL_ANCHOR_STORE_CONNECTION_MSFT:
            jdata = "XR_OBJECT_TYPE_SPATIAL_ANCHOR_STORE_CONNECTION_MSFT";
            break;
        case XR_OBJECT_TYPE_FACE_TRACKER_FB:
            jdata = "XR_OBJECT_TYPE_FACE_TRACKER_FB";
            break;
        case XR_OBJECT_TYPE_EYE_TRACKER_FB:
            jdata = "XR_OBJECT_TYPE_EYE_TRACKER_FB";
            break;
        case XR_OBJECT_TYPE_VIRTUAL_KEYBOARD_META:
            jdata = "XR_OBJECT_TYPE_VIRTUAL_KEYBOARD_META";
            break;
        case XR_OBJECT_TYPE_SPACE_USER_FB:
            jdata = "XR_OBJECT_TYPE_SPACE_USER_FB";
            break;
        case XR_OBJECT_TYPE_PASSTHROUGH_COLOR_LUT_META:
            jdata = "XR_OBJECT_TYPE_PASSTHROUGH_COLOR_LUT_META";
            break;
        case XR_OBJECT_TYPE_FACE_TRACKER2_FB:
            jdata = "XR_OBJECT_TYPE_FACE_TRACKER2_FB";
            break;
        case XR_OBJECT_TYPE_PASSTHROUGH_HTC:
            jdata = "XR_OBJECT_TYPE_PASSTHROUGH_HTC";
            break;
        case XR_OBJECT_TYPE_PLANE_DETECTOR_EXT:
            jdata = "XR_OBJECT_TYPE_PLANE_DETECTOR_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughColorLutChannelsMETA& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PASSTHROUGH_COLOR_LUT_CHANNELS_RGB_META:
            jdata = "XR_PASSTHROUGH_COLOR_LUT_CHANNELS_RGB_META";
            break;
        case XR_PASSTHROUGH_COLOR_LUT_CHANNELS_RGBA_META:
            jdata = "XR_PASSTHROUGH_COLOR_LUT_CHANNELS_RGBA_META";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughFormHTC& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PASSTHROUGH_FORM_PLANAR_HTC:
            jdata = "XR_PASSTHROUGH_FORM_PLANAR_HTC";
            break;
        case XR_PASSTHROUGH_FORM_PROJECTED_HTC:
            jdata = "XR_PASSTHROUGH_FORM_PROJECTED_HTC";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPassthroughLayerPurposeFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PASSTHROUGH_LAYER_PURPOSE_RECONSTRUCTION_FB:
            jdata = "XR_PASSTHROUGH_LAYER_PURPOSE_RECONSTRUCTION_FB";
            break;
        case XR_PASSTHROUGH_LAYER_PURPOSE_PROJECTED_FB:
            jdata = "XR_PASSTHROUGH_LAYER_PURPOSE_PROJECTED_FB";
            break;
        case XR_PASSTHROUGH_LAYER_PURPOSE_TRACKED_KEYBOARD_HANDS_FB:
            jdata = "XR_PASSTHROUGH_LAYER_PURPOSE_TRACKED_KEYBOARD_HANDS_FB";
            break;
        case XR_PASSTHROUGH_LAYER_PURPOSE_TRACKED_KEYBOARD_MASKED_HANDS_FB:
            jdata = "XR_PASSTHROUGH_LAYER_PURPOSE_TRACKED_KEYBOARD_MASKED_HANDS_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsDomainEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PERF_SETTINGS_DOMAIN_CPU_EXT:
            jdata = "XR_PERF_SETTINGS_DOMAIN_CPU_EXT";
            break;
        case XR_PERF_SETTINGS_DOMAIN_GPU_EXT:
            jdata = "XR_PERF_SETTINGS_DOMAIN_GPU_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsLevelEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT:
            jdata = "XR_PERF_SETTINGS_LEVEL_POWER_SAVINGS_EXT";
            break;
        case XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT:
            jdata = "XR_PERF_SETTINGS_LEVEL_SUSTAINED_LOW_EXT";
            break;
        case XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT:
            jdata = "XR_PERF_SETTINGS_LEVEL_SUSTAINED_HIGH_EXT";
            break;
        case XR_PERF_SETTINGS_LEVEL_BOOST_EXT:
            jdata = "XR_PERF_SETTINGS_LEVEL_BOOST_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsNotificationLevelEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PERF_SETTINGS_NOTIF_LEVEL_NORMAL_EXT:
            jdata = "XR_PERF_SETTINGS_NOTIF_LEVEL_NORMAL_EXT";
            break;
        case XR_PERF_SETTINGS_NOTIF_LEVEL_WARNING_EXT:
            jdata = "XR_PERF_SETTINGS_NOTIF_LEVEL_WARNING_EXT";
            break;
        case XR_PERF_SETTINGS_NOTIF_LEVEL_IMPAIRED_EXT:
            jdata = "XR_PERF_SETTINGS_NOTIF_LEVEL_IMPAIRED_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPerfSettingsSubDomainEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PERF_SETTINGS_SUB_DOMAIN_COMPOSITING_EXT:
            jdata = "XR_PERF_SETTINGS_SUB_DOMAIN_COMPOSITING_EXT";
            break;
        case XR_PERF_SETTINGS_SUB_DOMAIN_RENDERING_EXT:
            jdata = "XR_PERF_SETTINGS_SUB_DOMAIN_RENDERING_EXT";
            break;
        case XR_PERF_SETTINGS_SUB_DOMAIN_THERMAL_EXT:
            jdata = "XR_PERF_SETTINGS_SUB_DOMAIN_THERMAL_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPerformanceMetricsCounterUnitMETA& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PERFORMANCE_METRICS_COUNTER_UNIT_GENERIC_META:
            jdata = "XR_PERFORMANCE_METRICS_COUNTER_UNIT_GENERIC_META";
            break;
        case XR_PERFORMANCE_METRICS_COUNTER_UNIT_PERCENTAGE_META:
            jdata = "XR_PERFORMANCE_METRICS_COUNTER_UNIT_PERCENTAGE_META";
            break;
        case XR_PERFORMANCE_METRICS_COUNTER_UNIT_MILLISECONDS_META:
            jdata = "XR_PERFORMANCE_METRICS_COUNTER_UNIT_MILLISECONDS_META";
            break;
        case XR_PERFORMANCE_METRICS_COUNTER_UNIT_BYTES_META:
            jdata = "XR_PERFORMANCE_METRICS_COUNTER_UNIT_BYTES_META";
            break;
        case XR_PERFORMANCE_METRICS_COUNTER_UNIT_HERTZ_META:
            jdata = "XR_PERFORMANCE_METRICS_COUNTER_UNIT_HERTZ_META";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectionStateEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PLANE_DETECTION_STATE_NONE_EXT:
            jdata = "XR_PLANE_DETECTION_STATE_NONE_EXT";
            break;
        case XR_PLANE_DETECTION_STATE_PENDING_EXT:
            jdata = "XR_PLANE_DETECTION_STATE_PENDING_EXT";
            break;
        case XR_PLANE_DETECTION_STATE_DONE_EXT:
            jdata = "XR_PLANE_DETECTION_STATE_DONE_EXT";
            break;
        case XR_PLANE_DETECTION_STATE_ERROR_EXT:
            jdata = "XR_PLANE_DETECTION_STATE_ERROR_EXT";
            break;
        case XR_PLANE_DETECTION_STATE_FATAL_EXT:
            jdata = "XR_PLANE_DETECTION_STATE_FATAL_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectorOrientationEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PLANE_DETECTOR_ORIENTATION_HORIZONTAL_UPWARD_EXT:
            jdata = "XR_PLANE_DETECTOR_ORIENTATION_HORIZONTAL_UPWARD_EXT";
            break;
        case XR_PLANE_DETECTOR_ORIENTATION_HORIZONTAL_DOWNWARD_EXT:
            jdata = "XR_PLANE_DETECTOR_ORIENTATION_HORIZONTAL_DOWNWARD_EXT";
            break;
        case XR_PLANE_DETECTOR_ORIENTATION_VERTICAL_EXT:
            jdata = "XR_PLANE_DETECTOR_ORIENTATION_VERTICAL_EXT";
            break;
        case XR_PLANE_DETECTOR_ORIENTATION_ARBITRARY_EXT:
            jdata = "XR_PLANE_DETECTOR_ORIENTATION_ARBITRARY_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrPlaneDetectorSemanticTypeEXT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_PLANE_DETECTOR_SEMANTIC_TYPE_UNDEFINED_EXT:
            jdata = "XR_PLANE_DETECTOR_SEMANTIC_TYPE_UNDEFINED_EXT";
            break;
        case XR_PLANE_DETECTOR_SEMANTIC_TYPE_CEILING_EXT:
            jdata = "XR_PLANE_DETECTOR_SEMANTIC_TYPE_CEILING_EXT";
            break;
        case XR_PLANE_DETECTOR_SEMANTIC_TYPE_FLOOR_EXT:
            jdata = "XR_PLANE_DETECTOR_SEMANTIC_TYPE_FLOOR_EXT";
            break;
        case XR_PLANE_DETECTOR_SEMANTIC_TYPE_WALL_EXT:
            jdata = "XR_PLANE_DETECTOR_SEMANTIC_TYPE_WALL_EXT";
            break;
        case XR_PLANE_DETECTOR_SEMANTIC_TYPE_PLATFORM_EXT:
            jdata = "XR_PLANE_DETECTOR_SEMANTIC_TYPE_PLATFORM_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrReferenceSpaceType& value, const JsonOptions& options)
{
    switch (value) {
        case XR_REFERENCE_SPACE_TYPE_VIEW:
            jdata = "XR_REFERENCE_SPACE_TYPE_VIEW";
            break;
        case XR_REFERENCE_SPACE_TYPE_LOCAL:
            jdata = "XR_REFERENCE_SPACE_TYPE_LOCAL";
            break;
        case XR_REFERENCE_SPACE_TYPE_STAGE:
            jdata = "XR_REFERENCE_SPACE_TYPE_STAGE";
            break;
        case XR_REFERENCE_SPACE_TYPE_UNBOUNDED_MSFT:
            jdata = "XR_REFERENCE_SPACE_TYPE_UNBOUNDED_MSFT";
            break;
        case XR_REFERENCE_SPACE_TYPE_COMBINED_EYE_VARJO:
            jdata = "XR_REFERENCE_SPACE_TYPE_COMBINED_EYE_VARJO";
            break;
        case XR_REFERENCE_SPACE_TYPE_LOCALIZATION_MAP_ML:
            jdata = "XR_REFERENCE_SPACE_TYPE_LOCALIZATION_MAP_ML";
            break;
        case XR_REFERENCE_SPACE_TYPE_LOCAL_FLOOR_EXT:
            jdata = "XR_REFERENCE_SPACE_TYPE_LOCAL_FLOOR_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrReprojectionModeMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_REPROJECTION_MODE_DEPTH_MSFT:
            jdata = "XR_REPROJECTION_MODE_DEPTH_MSFT";
            break;
        case XR_REPROJECTION_MODE_PLANAR_FROM_DEPTH_MSFT:
            jdata = "XR_REPROJECTION_MODE_PLANAR_FROM_DEPTH_MSFT";
            break;
        case XR_REPROJECTION_MODE_PLANAR_MANUAL_MSFT:
            jdata = "XR_REPROJECTION_MODE_PLANAR_MANUAL_MSFT";
            break;
        case XR_REPROJECTION_MODE_ORIENTATION_ONLY_MSFT:
            jdata = "XR_REPROJECTION_MODE_ORIENTATION_ONLY_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrResult& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SUCCESS:
            jdata = "XR_SUCCESS";
            break;
        case XR_TIMEOUT_EXPIRED:
            jdata = "XR_TIMEOUT_EXPIRED";
            break;
        case XR_SESSION_LOSS_PENDING:
            jdata = "XR_SESSION_LOSS_PENDING";
            break;
        case XR_EVENT_UNAVAILABLE:
            jdata = "XR_EVENT_UNAVAILABLE";
            break;
        case XR_SPACE_BOUNDS_UNAVAILABLE:
            jdata = "XR_SPACE_BOUNDS_UNAVAILABLE";
            break;
        case XR_SESSION_NOT_FOCUSED:
            jdata = "XR_SESSION_NOT_FOCUSED";
            break;
        case XR_FRAME_DISCARDED:
            jdata = "XR_FRAME_DISCARDED";
            break;
        case XR_ERROR_VALIDATION_FAILURE:
            jdata = "XR_ERROR_VALIDATION_FAILURE";
            break;
        case XR_ERROR_RUNTIME_FAILURE:
            jdata = "XR_ERROR_RUNTIME_FAILURE";
            break;
        case XR_ERROR_OUT_OF_MEMORY:
            jdata = "XR_ERROR_OUT_OF_MEMORY";
            break;
        case XR_ERROR_API_VERSION_UNSUPPORTED:
            jdata = "XR_ERROR_API_VERSION_UNSUPPORTED";
            break;
        case XR_ERROR_INITIALIZATION_FAILED:
            jdata = "XR_ERROR_INITIALIZATION_FAILED";
            break;
        case XR_ERROR_FUNCTION_UNSUPPORTED:
            jdata = "XR_ERROR_FUNCTION_UNSUPPORTED";
            break;
        case XR_ERROR_FEATURE_UNSUPPORTED:
            jdata = "XR_ERROR_FEATURE_UNSUPPORTED";
            break;
        case XR_ERROR_EXTENSION_NOT_PRESENT:
            jdata = "XR_ERROR_EXTENSION_NOT_PRESENT";
            break;
        case XR_ERROR_LIMIT_REACHED:
            jdata = "XR_ERROR_LIMIT_REACHED";
            break;
        case XR_ERROR_SIZE_INSUFFICIENT:
            jdata = "XR_ERROR_SIZE_INSUFFICIENT";
            break;
        case XR_ERROR_HANDLE_INVALID:
            jdata = "XR_ERROR_HANDLE_INVALID";
            break;
        case XR_ERROR_INSTANCE_LOST:
            jdata = "XR_ERROR_INSTANCE_LOST";
            break;
        case XR_ERROR_SESSION_RUNNING:
            jdata = "XR_ERROR_SESSION_RUNNING";
            break;
        case XR_ERROR_SESSION_NOT_RUNNING:
            jdata = "XR_ERROR_SESSION_NOT_RUNNING";
            break;
        case XR_ERROR_SESSION_LOST:
            jdata = "XR_ERROR_SESSION_LOST";
            break;
        case XR_ERROR_SYSTEM_INVALID:
            jdata = "XR_ERROR_SYSTEM_INVALID";
            break;
        case XR_ERROR_PATH_INVALID:
            jdata = "XR_ERROR_PATH_INVALID";
            break;
        case XR_ERROR_PATH_COUNT_EXCEEDED:
            jdata = "XR_ERROR_PATH_COUNT_EXCEEDED";
            break;
        case XR_ERROR_PATH_FORMAT_INVALID:
            jdata = "XR_ERROR_PATH_FORMAT_INVALID";
            break;
        case XR_ERROR_PATH_UNSUPPORTED:
            jdata = "XR_ERROR_PATH_UNSUPPORTED";
            break;
        case XR_ERROR_LAYER_INVALID:
            jdata = "XR_ERROR_LAYER_INVALID";
            break;
        case XR_ERROR_LAYER_LIMIT_EXCEEDED:
            jdata = "XR_ERROR_LAYER_LIMIT_EXCEEDED";
            break;
        case XR_ERROR_SWAPCHAIN_RECT_INVALID:
            jdata = "XR_ERROR_SWAPCHAIN_RECT_INVALID";
            break;
        case XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED:
            jdata = "XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED";
            break;
        case XR_ERROR_ACTION_TYPE_MISMATCH:
            jdata = "XR_ERROR_ACTION_TYPE_MISMATCH";
            break;
        case XR_ERROR_SESSION_NOT_READY:
            jdata = "XR_ERROR_SESSION_NOT_READY";
            break;
        case XR_ERROR_SESSION_NOT_STOPPING:
            jdata = "XR_ERROR_SESSION_NOT_STOPPING";
            break;
        case XR_ERROR_TIME_INVALID:
            jdata = "XR_ERROR_TIME_INVALID";
            break;
        case XR_ERROR_REFERENCE_SPACE_UNSUPPORTED:
            jdata = "XR_ERROR_REFERENCE_SPACE_UNSUPPORTED";
            break;
        case XR_ERROR_FILE_ACCESS_ERROR:
            jdata = "XR_ERROR_FILE_ACCESS_ERROR";
            break;
        case XR_ERROR_FILE_CONTENTS_INVALID:
            jdata = "XR_ERROR_FILE_CONTENTS_INVALID";
            break;
        case XR_ERROR_FORM_FACTOR_UNSUPPORTED:
            jdata = "XR_ERROR_FORM_FACTOR_UNSUPPORTED";
            break;
        case XR_ERROR_FORM_FACTOR_UNAVAILABLE:
            jdata = "XR_ERROR_FORM_FACTOR_UNAVAILABLE";
            break;
        case XR_ERROR_API_LAYER_NOT_PRESENT:
            jdata = "XR_ERROR_API_LAYER_NOT_PRESENT";
            break;
        case XR_ERROR_CALL_ORDER_INVALID:
            jdata = "XR_ERROR_CALL_ORDER_INVALID";
            break;
        case XR_ERROR_GRAPHICS_DEVICE_INVALID:
            jdata = "XR_ERROR_GRAPHICS_DEVICE_INVALID";
            break;
        case XR_ERROR_POSE_INVALID:
            jdata = "XR_ERROR_POSE_INVALID";
            break;
        case XR_ERROR_INDEX_OUT_OF_RANGE:
            jdata = "XR_ERROR_INDEX_OUT_OF_RANGE";
            break;
        case XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED:
            jdata = "XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED";
            break;
        case XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED:
            jdata = "XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED";
            break;
        case XR_ERROR_NAME_DUPLICATED:
            jdata = "XR_ERROR_NAME_DUPLICATED";
            break;
        case XR_ERROR_NAME_INVALID:
            jdata = "XR_ERROR_NAME_INVALID";
            break;
        case XR_ERROR_ACTIONSET_NOT_ATTACHED:
            jdata = "XR_ERROR_ACTIONSET_NOT_ATTACHED";
            break;
        case XR_ERROR_ACTIONSETS_ALREADY_ATTACHED:
            jdata = "XR_ERROR_ACTIONSETS_ALREADY_ATTACHED";
            break;
        case XR_ERROR_LOCALIZED_NAME_DUPLICATED:
            jdata = "XR_ERROR_LOCALIZED_NAME_DUPLICATED";
            break;
        case XR_ERROR_LOCALIZED_NAME_INVALID:
            jdata = "XR_ERROR_LOCALIZED_NAME_INVALID";
            break;
        case XR_ERROR_GRAPHICS_REQUIREMENTS_CALL_MISSING:
            jdata = "XR_ERROR_GRAPHICS_REQUIREMENTS_CALL_MISSING";
            break;
        case XR_ERROR_RUNTIME_UNAVAILABLE:
            jdata = "XR_ERROR_RUNTIME_UNAVAILABLE";
            break;
        case XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR:
            jdata = "XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR";
            break;
        case XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR:
            jdata = "XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR";
            break;
        case XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT:
            jdata = "XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT";
            break;
        case XR_ERROR_SECONDARY_VIEW_CONFIGURATION_TYPE_NOT_ENABLED_MSFT:
            jdata = "XR_ERROR_SECONDARY_VIEW_CONFIGURATION_TYPE_NOT_ENABLED_MSFT";
            break;
        case XR_ERROR_CONTROLLER_MODEL_KEY_INVALID_MSFT:
            jdata = "XR_ERROR_CONTROLLER_MODEL_KEY_INVALID_MSFT";
            break;
        case XR_ERROR_REPROJECTION_MODE_UNSUPPORTED_MSFT:
            jdata = "XR_ERROR_REPROJECTION_MODE_UNSUPPORTED_MSFT";
            break;
        case XR_ERROR_COMPUTE_NEW_SCENE_NOT_COMPLETED_MSFT:
            jdata = "XR_ERROR_COMPUTE_NEW_SCENE_NOT_COMPLETED_MSFT";
            break;
        case XR_ERROR_SCENE_COMPONENT_ID_INVALID_MSFT:
            jdata = "XR_ERROR_SCENE_COMPONENT_ID_INVALID_MSFT";
            break;
        case XR_ERROR_SCENE_COMPONENT_TYPE_MISMATCH_MSFT:
            jdata = "XR_ERROR_SCENE_COMPONENT_TYPE_MISMATCH_MSFT";
            break;
        case XR_ERROR_SCENE_MESH_BUFFER_ID_INVALID_MSFT:
            jdata = "XR_ERROR_SCENE_MESH_BUFFER_ID_INVALID_MSFT";
            break;
        case XR_ERROR_SCENE_COMPUTE_FEATURE_INCOMPATIBLE_MSFT:
            jdata = "XR_ERROR_SCENE_COMPUTE_FEATURE_INCOMPATIBLE_MSFT";
            break;
        case XR_ERROR_SCENE_COMPUTE_CONSISTENCY_MISMATCH_MSFT:
            jdata = "XR_ERROR_SCENE_COMPUTE_CONSISTENCY_MISMATCH_MSFT";
            break;
        case XR_ERROR_DISPLAY_REFRESH_RATE_UNSUPPORTED_FB:
            jdata = "XR_ERROR_DISPLAY_REFRESH_RATE_UNSUPPORTED_FB";
            break;
        case XR_ERROR_COLOR_SPACE_UNSUPPORTED_FB:
            jdata = "XR_ERROR_COLOR_SPACE_UNSUPPORTED_FB";
            break;
        case XR_ERROR_SPACE_COMPONENT_NOT_SUPPORTED_FB:
            jdata = "XR_ERROR_SPACE_COMPONENT_NOT_SUPPORTED_FB";
            break;
        case XR_ERROR_SPACE_COMPONENT_NOT_ENABLED_FB:
            jdata = "XR_ERROR_SPACE_COMPONENT_NOT_ENABLED_FB";
            break;
        case XR_ERROR_SPACE_COMPONENT_STATUS_PENDING_FB:
            jdata = "XR_ERROR_SPACE_COMPONENT_STATUS_PENDING_FB";
            break;
        case XR_ERROR_SPACE_COMPONENT_STATUS_ALREADY_SET_FB:
            jdata = "XR_ERROR_SPACE_COMPONENT_STATUS_ALREADY_SET_FB";
            break;
        case XR_ERROR_UNEXPECTED_STATE_PASSTHROUGH_FB:
            jdata = "XR_ERROR_UNEXPECTED_STATE_PASSTHROUGH_FB";
            break;
        case XR_ERROR_FEATURE_ALREADY_CREATED_PASSTHROUGH_FB:
            jdata = "XR_ERROR_FEATURE_ALREADY_CREATED_PASSTHROUGH_FB";
            break;
        case XR_ERROR_FEATURE_REQUIRED_PASSTHROUGH_FB:
            jdata = "XR_ERROR_FEATURE_REQUIRED_PASSTHROUGH_FB";
            break;
        case XR_ERROR_NOT_PERMITTED_PASSTHROUGH_FB:
            jdata = "XR_ERROR_NOT_PERMITTED_PASSTHROUGH_FB";
            break;
        case XR_ERROR_INSUFFICIENT_RESOURCES_PASSTHROUGH_FB:
            jdata = "XR_ERROR_INSUFFICIENT_RESOURCES_PASSTHROUGH_FB";
            break;
        case XR_ERROR_UNKNOWN_PASSTHROUGH_FB:
            jdata = "XR_ERROR_UNKNOWN_PASSTHROUGH_FB";
            break;
        case XR_ERROR_RENDER_MODEL_KEY_INVALID_FB:
            jdata = "XR_ERROR_RENDER_MODEL_KEY_INVALID_FB";
            break;
        case XR_RENDER_MODEL_UNAVAILABLE_FB:
            jdata = "XR_RENDER_MODEL_UNAVAILABLE_FB";
            break;
        case XR_ERROR_MARKER_NOT_TRACKED_VARJO:
            jdata = "XR_ERROR_MARKER_NOT_TRACKED_VARJO";
            break;
        case XR_ERROR_MARKER_ID_INVALID_VARJO:
            jdata = "XR_ERROR_MARKER_ID_INVALID_VARJO";
            break;
        case XR_ERROR_MARKER_DETECTOR_PERMISSION_DENIED_ML:
            jdata = "XR_ERROR_MARKER_DETECTOR_PERMISSION_DENIED_ML";
            break;
        case XR_ERROR_MARKER_DETECTOR_LOCATE_FAILED_ML:
            jdata = "XR_ERROR_MARKER_DETECTOR_LOCATE_FAILED_ML";
            break;
        case XR_ERROR_MARKER_DETECTOR_INVALID_DATA_QUERY_ML:
            jdata = "XR_ERROR_MARKER_DETECTOR_INVALID_DATA_QUERY_ML";
            break;
        case XR_ERROR_MARKER_DETECTOR_INVALID_CREATE_INFO_ML:
            jdata = "XR_ERROR_MARKER_DETECTOR_INVALID_CREATE_INFO_ML";
            break;
        case XR_ERROR_MARKER_INVALID_ML:
            jdata = "XR_ERROR_MARKER_INVALID_ML";
            break;
        case XR_ERROR_LOCALIZATION_MAP_INCOMPATIBLE_ML:
            jdata = "XR_ERROR_LOCALIZATION_MAP_INCOMPATIBLE_ML";
            break;
        case XR_ERROR_LOCALIZATION_MAP_UNAVAILABLE_ML:
            jdata = "XR_ERROR_LOCALIZATION_MAP_UNAVAILABLE_ML";
            break;
        case XR_ERROR_LOCALIZATION_MAP_FAIL_ML:
            jdata = "XR_ERROR_LOCALIZATION_MAP_FAIL_ML";
            break;
        case XR_ERROR_LOCALIZATION_MAP_IMPORT_EXPORT_PERMISSION_DENIED_ML:
            jdata = "XR_ERROR_LOCALIZATION_MAP_IMPORT_EXPORT_PERMISSION_DENIED_ML";
            break;
        case XR_ERROR_LOCALIZATION_MAP_PERMISSION_DENIED_ML:
            jdata = "XR_ERROR_LOCALIZATION_MAP_PERMISSION_DENIED_ML";
            break;
        case XR_ERROR_LOCALIZATION_MAP_ALREADY_EXISTS_ML:
            jdata = "XR_ERROR_LOCALIZATION_MAP_ALREADY_EXISTS_ML";
            break;
        case XR_ERROR_LOCALIZATION_MAP_CANNOT_EXPORT_CLOUD_MAP_ML:
            jdata = "XR_ERROR_LOCALIZATION_MAP_CANNOT_EXPORT_CLOUD_MAP_ML";
            break;
        case XR_ERROR_SPATIAL_ANCHOR_NAME_NOT_FOUND_MSFT:
            jdata = "XR_ERROR_SPATIAL_ANCHOR_NAME_NOT_FOUND_MSFT";
            break;
        case XR_ERROR_SPATIAL_ANCHOR_NAME_INVALID_MSFT:
            jdata = "XR_ERROR_SPATIAL_ANCHOR_NAME_INVALID_MSFT";
            break;
        case XR_SCENE_MARKER_DATA_NOT_STRING_MSFT:
            jdata = "XR_SCENE_MARKER_DATA_NOT_STRING_MSFT";
            break;
        case XR_ERROR_SPACE_MAPPING_INSUFFICIENT_FB:
            jdata = "XR_ERROR_SPACE_MAPPING_INSUFFICIENT_FB";
            break;
        case XR_ERROR_SPACE_LOCALIZATION_FAILED_FB:
            jdata = "XR_ERROR_SPACE_LOCALIZATION_FAILED_FB";
            break;
        case XR_ERROR_SPACE_NETWORK_TIMEOUT_FB:
            jdata = "XR_ERROR_SPACE_NETWORK_TIMEOUT_FB";
            break;
        case XR_ERROR_SPACE_NETWORK_REQUEST_FAILED_FB:
            jdata = "XR_ERROR_SPACE_NETWORK_REQUEST_FAILED_FB";
            break;
        case XR_ERROR_SPACE_CLOUD_STORAGE_DISABLED_FB:
            jdata = "XR_ERROR_SPACE_CLOUD_STORAGE_DISABLED_FB";
            break;
        case XR_ERROR_PASSTHROUGH_COLOR_LUT_BUFFER_SIZE_MISMATCH_META:
            jdata = "XR_ERROR_PASSTHROUGH_COLOR_LUT_BUFFER_SIZE_MISMATCH_META";
            break;
        case XR_ERROR_HINT_ALREADY_SET_QCOM:
            jdata = "XR_ERROR_HINT_ALREADY_SET_QCOM";
            break;
        case XR_ERROR_NOT_AN_ANCHOR_HTC:
            jdata = "XR_ERROR_NOT_AN_ANCHOR_HTC";
            break;
        case XR_ERROR_SPACE_NOT_LOCATABLE_EXT:
            jdata = "XR_ERROR_SPACE_NOT_LOCATABLE_EXT";
            break;
        case XR_ERROR_PLANE_DETECTION_PERMISSION_DENIED_EXT:
            jdata = "XR_ERROR_PLANE_DETECTION_PERMISSION_DENIED_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComponentTypeMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SCENE_COMPONENT_TYPE_INVALID_MSFT:
            jdata = "XR_SCENE_COMPONENT_TYPE_INVALID_MSFT";
            break;
        case XR_SCENE_COMPONENT_TYPE_OBJECT_MSFT:
            jdata = "XR_SCENE_COMPONENT_TYPE_OBJECT_MSFT";
            break;
        case XR_SCENE_COMPONENT_TYPE_PLANE_MSFT:
            jdata = "XR_SCENE_COMPONENT_TYPE_PLANE_MSFT";
            break;
        case XR_SCENE_COMPONENT_TYPE_VISUAL_MESH_MSFT:
            jdata = "XR_SCENE_COMPONENT_TYPE_VISUAL_MESH_MSFT";
            break;
        case XR_SCENE_COMPONENT_TYPE_COLLIDER_MESH_MSFT:
            jdata = "XR_SCENE_COMPONENT_TYPE_COLLIDER_MESH_MSFT";
            break;
        case XR_SCENE_COMPONENT_TYPE_SERIALIZED_SCENE_FRAGMENT_MSFT:
            jdata = "XR_SCENE_COMPONENT_TYPE_SERIALIZED_SCENE_FRAGMENT_MSFT";
            break;
        case XR_SCENE_COMPONENT_TYPE_MARKER_MSFT:
            jdata = "XR_SCENE_COMPONENT_TYPE_MARKER_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComputeConsistencyMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SCENE_COMPUTE_CONSISTENCY_SNAPSHOT_COMPLETE_MSFT:
            jdata = "XR_SCENE_COMPUTE_CONSISTENCY_SNAPSHOT_COMPLETE_MSFT";
            break;
        case XR_SCENE_COMPUTE_CONSISTENCY_SNAPSHOT_INCOMPLETE_FAST_MSFT:
            jdata = "XR_SCENE_COMPUTE_CONSISTENCY_SNAPSHOT_INCOMPLETE_FAST_MSFT";
            break;
        case XR_SCENE_COMPUTE_CONSISTENCY_OCCLUSION_OPTIMIZED_MSFT:
            jdata = "XR_SCENE_COMPUTE_CONSISTENCY_OCCLUSION_OPTIMIZED_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComputeFeatureMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SCENE_COMPUTE_FEATURE_PLANE_MSFT:
            jdata = "XR_SCENE_COMPUTE_FEATURE_PLANE_MSFT";
            break;
        case XR_SCENE_COMPUTE_FEATURE_PLANE_MESH_MSFT:
            jdata = "XR_SCENE_COMPUTE_FEATURE_PLANE_MESH_MSFT";
            break;
        case XR_SCENE_COMPUTE_FEATURE_VISUAL_MESH_MSFT:
            jdata = "XR_SCENE_COMPUTE_FEATURE_VISUAL_MESH_MSFT";
            break;
        case XR_SCENE_COMPUTE_FEATURE_COLLIDER_MESH_MSFT:
            jdata = "XR_SCENE_COMPUTE_FEATURE_COLLIDER_MESH_MSFT";
            break;
        case XR_SCENE_COMPUTE_FEATURE_SERIALIZE_SCENE_MSFT:
            jdata = "XR_SCENE_COMPUTE_FEATURE_SERIALIZE_SCENE_MSFT";
            break;
        case XR_SCENE_COMPUTE_FEATURE_MARKER_MSFT:
            jdata = "XR_SCENE_COMPUTE_FEATURE_MARKER_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneComputeStateMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SCENE_COMPUTE_STATE_NONE_MSFT:
            jdata = "XR_SCENE_COMPUTE_STATE_NONE_MSFT";
            break;
        case XR_SCENE_COMPUTE_STATE_UPDATING_MSFT:
            jdata = "XR_SCENE_COMPUTE_STATE_UPDATING_MSFT";
            break;
        case XR_SCENE_COMPUTE_STATE_COMPLETED_MSFT:
            jdata = "XR_SCENE_COMPUTE_STATE_COMPLETED_MSFT";
            break;
        case XR_SCENE_COMPUTE_STATE_COMPLETED_WITH_ERROR_MSFT:
            jdata = "XR_SCENE_COMPUTE_STATE_COMPLETED_WITH_ERROR_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneMarkerQRCodeSymbolTypeMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SCENE_MARKER_QR_CODE_SYMBOL_TYPE_QR_CODE_MSFT:
            jdata = "XR_SCENE_MARKER_QR_CODE_SYMBOL_TYPE_QR_CODE_MSFT";
            break;
        case XR_SCENE_MARKER_QR_CODE_SYMBOL_TYPE_MICRO_QR_CODE_MSFT:
            jdata = "XR_SCENE_MARKER_QR_CODE_SYMBOL_TYPE_MICRO_QR_CODE_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneMarkerTypeMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SCENE_MARKER_TYPE_QR_CODE_MSFT:
            jdata = "XR_SCENE_MARKER_TYPE_QR_CODE_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSceneObjectTypeMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SCENE_OBJECT_TYPE_UNCATEGORIZED_MSFT:
            jdata = "XR_SCENE_OBJECT_TYPE_UNCATEGORIZED_MSFT";
            break;
        case XR_SCENE_OBJECT_TYPE_BACKGROUND_MSFT:
            jdata = "XR_SCENE_OBJECT_TYPE_BACKGROUND_MSFT";
            break;
        case XR_SCENE_OBJECT_TYPE_WALL_MSFT:
            jdata = "XR_SCENE_OBJECT_TYPE_WALL_MSFT";
            break;
        case XR_SCENE_OBJECT_TYPE_FLOOR_MSFT:
            jdata = "XR_SCENE_OBJECT_TYPE_FLOOR_MSFT";
            break;
        case XR_SCENE_OBJECT_TYPE_CEILING_MSFT:
            jdata = "XR_SCENE_OBJECT_TYPE_CEILING_MSFT";
            break;
        case XR_SCENE_OBJECT_TYPE_PLATFORM_MSFT:
            jdata = "XR_SCENE_OBJECT_TYPE_PLATFORM_MSFT";
            break;
        case XR_SCENE_OBJECT_TYPE_INFERRED_MSFT:
            jdata = "XR_SCENE_OBJECT_TYPE_INFERRED_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrScenePlaneAlignmentTypeMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SCENE_PLANE_ALIGNMENT_TYPE_NON_ORTHOGONAL_MSFT:
            jdata = "XR_SCENE_PLANE_ALIGNMENT_TYPE_NON_ORTHOGONAL_MSFT";
            break;
        case XR_SCENE_PLANE_ALIGNMENT_TYPE_HORIZONTAL_MSFT:
            jdata = "XR_SCENE_PLANE_ALIGNMENT_TYPE_HORIZONTAL_MSFT";
            break;
        case XR_SCENE_PLANE_ALIGNMENT_TYPE_VERTICAL_MSFT:
            jdata = "XR_SCENE_PLANE_ALIGNMENT_TYPE_VERTICAL_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSessionState& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SESSION_STATE_UNKNOWN:
            jdata = "XR_SESSION_STATE_UNKNOWN";
            break;
        case XR_SESSION_STATE_IDLE:
            jdata = "XR_SESSION_STATE_IDLE";
            break;
        case XR_SESSION_STATE_READY:
            jdata = "XR_SESSION_STATE_READY";
            break;
        case XR_SESSION_STATE_SYNCHRONIZED:
            jdata = "XR_SESSION_STATE_SYNCHRONIZED";
            break;
        case XR_SESSION_STATE_VISIBLE:
            jdata = "XR_SESSION_STATE_VISIBLE";
            break;
        case XR_SESSION_STATE_FOCUSED:
            jdata = "XR_SESSION_STATE_FOCUSED";
            break;
        case XR_SESSION_STATE_STOPPING:
            jdata = "XR_SESSION_STATE_STOPPING";
            break;
        case XR_SESSION_STATE_LOSS_PENDING:
            jdata = "XR_SESSION_STATE_LOSS_PENDING";
            break;
        case XR_SESSION_STATE_EXITING:
            jdata = "XR_SESSION_STATE_EXITING";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceComponentTypeFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SPACE_COMPONENT_TYPE_LOCATABLE_FB:
            jdata = "XR_SPACE_COMPONENT_TYPE_LOCATABLE_FB";
            break;
        case XR_SPACE_COMPONENT_TYPE_STORABLE_FB:
            jdata = "XR_SPACE_COMPONENT_TYPE_STORABLE_FB";
            break;
        case XR_SPACE_COMPONENT_TYPE_SHARABLE_FB:
            jdata = "XR_SPACE_COMPONENT_TYPE_SHARABLE_FB";
            break;
        case XR_SPACE_COMPONENT_TYPE_BOUNDED_2D_FB:
            jdata = "XR_SPACE_COMPONENT_TYPE_BOUNDED_2D_FB";
            break;
        case XR_SPACE_COMPONENT_TYPE_BOUNDED_3D_FB:
            jdata = "XR_SPACE_COMPONENT_TYPE_BOUNDED_3D_FB";
            break;
        case XR_SPACE_COMPONENT_TYPE_SEMANTIC_LABELS_FB:
            jdata = "XR_SPACE_COMPONENT_TYPE_SEMANTIC_LABELS_FB";
            break;
        case XR_SPACE_COMPONENT_TYPE_ROOM_LAYOUT_FB:
            jdata = "XR_SPACE_COMPONENT_TYPE_ROOM_LAYOUT_FB";
            break;
        case XR_SPACE_COMPONENT_TYPE_SPACE_CONTAINER_FB:
            jdata = "XR_SPACE_COMPONENT_TYPE_SPACE_CONTAINER_FB";
            break;
        case XR_SPACE_COMPONENT_TYPE_TRIANGLE_MESH_META:
            jdata = "XR_SPACE_COMPONENT_TYPE_TRIANGLE_MESH_META";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSpacePersistenceModeFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SPACE_PERSISTENCE_MODE_INVALID_FB:
            jdata = "XR_SPACE_PERSISTENCE_MODE_INVALID_FB";
            break;
        case XR_SPACE_PERSISTENCE_MODE_INDEFINITE_FB:
            jdata = "XR_SPACE_PERSISTENCE_MODE_INDEFINITE_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceQueryActionFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SPACE_QUERY_ACTION_LOAD_FB:
            jdata = "XR_SPACE_QUERY_ACTION_LOAD_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSpaceStorageLocationFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SPACE_STORAGE_LOCATION_INVALID_FB:
            jdata = "XR_SPACE_STORAGE_LOCATION_INVALID_FB";
            break;
        case XR_SPACE_STORAGE_LOCATION_LOCAL_FB:
            jdata = "XR_SPACE_STORAGE_LOCATION_LOCAL_FB";
            break;
        case XR_SPACE_STORAGE_LOCATION_CLOUD_FB:
            jdata = "XR_SPACE_STORAGE_LOCATION_CLOUD_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrSpatialGraphNodeTypeMSFT& value, const JsonOptions& options)
{
    switch (value) {
        case XR_SPATIAL_GRAPH_NODE_TYPE_STATIC_MSFT:
            jdata = "XR_SPATIAL_GRAPH_NODE_TYPE_STATIC_MSFT";
            break;
        case XR_SPATIAL_GRAPH_NODE_TYPE_DYNAMIC_MSFT:
            jdata = "XR_SPATIAL_GRAPH_NODE_TYPE_DYNAMIC_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrStructureType& value, const JsonOptions& options)
{
    switch (value) {
        case XR_TYPE_UNKNOWN:
            jdata = "XR_TYPE_UNKNOWN";
            break;
        case XR_TYPE_API_LAYER_PROPERTIES:
            jdata = "XR_TYPE_API_LAYER_PROPERTIES";
            break;
        case XR_TYPE_EXTENSION_PROPERTIES:
            jdata = "XR_TYPE_EXTENSION_PROPERTIES";
            break;
        case XR_TYPE_INSTANCE_CREATE_INFO:
            jdata = "XR_TYPE_INSTANCE_CREATE_INFO";
            break;
        case XR_TYPE_SYSTEM_GET_INFO:
            jdata = "XR_TYPE_SYSTEM_GET_INFO";
            break;
        case XR_TYPE_SYSTEM_PROPERTIES:
            jdata = "XR_TYPE_SYSTEM_PROPERTIES";
            break;
        case XR_TYPE_VIEW_LOCATE_INFO:
            jdata = "XR_TYPE_VIEW_LOCATE_INFO";
            break;
        case XR_TYPE_VIEW:
            jdata = "XR_TYPE_VIEW";
            break;
        case XR_TYPE_SESSION_CREATE_INFO:
            jdata = "XR_TYPE_SESSION_CREATE_INFO";
            break;
        case XR_TYPE_SWAPCHAIN_CREATE_INFO:
            jdata = "XR_TYPE_SWAPCHAIN_CREATE_INFO";
            break;
        case XR_TYPE_SESSION_BEGIN_INFO:
            jdata = "XR_TYPE_SESSION_BEGIN_INFO";
            break;
        case XR_TYPE_VIEW_STATE:
            jdata = "XR_TYPE_VIEW_STATE";
            break;
        case XR_TYPE_FRAME_END_INFO:
            jdata = "XR_TYPE_FRAME_END_INFO";
            break;
        case XR_TYPE_HAPTIC_VIBRATION:
            jdata = "XR_TYPE_HAPTIC_VIBRATION";
            break;
        case XR_TYPE_EVENT_DATA_BUFFER:
            jdata = "XR_TYPE_EVENT_DATA_BUFFER";
            break;
        case XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING:
            jdata = "XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING";
            break;
        case XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED:
            jdata = "XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED";
            break;
        case XR_TYPE_ACTION_STATE_BOOLEAN:
            jdata = "XR_TYPE_ACTION_STATE_BOOLEAN";
            break;
        case XR_TYPE_ACTION_STATE_FLOAT:
            jdata = "XR_TYPE_ACTION_STATE_FLOAT";
            break;
        case XR_TYPE_ACTION_STATE_VECTOR2F:
            jdata = "XR_TYPE_ACTION_STATE_VECTOR2F";
            break;
        case XR_TYPE_ACTION_STATE_POSE:
            jdata = "XR_TYPE_ACTION_STATE_POSE";
            break;
        case XR_TYPE_ACTION_SET_CREATE_INFO:
            jdata = "XR_TYPE_ACTION_SET_CREATE_INFO";
            break;
        case XR_TYPE_ACTION_CREATE_INFO:
            jdata = "XR_TYPE_ACTION_CREATE_INFO";
            break;
        case XR_TYPE_INSTANCE_PROPERTIES:
            jdata = "XR_TYPE_INSTANCE_PROPERTIES";
            break;
        case XR_TYPE_FRAME_WAIT_INFO:
            jdata = "XR_TYPE_FRAME_WAIT_INFO";
            break;
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION:
            jdata = "XR_TYPE_COMPOSITION_LAYER_PROJECTION";
            break;
        case XR_TYPE_COMPOSITION_LAYER_QUAD:
            jdata = "XR_TYPE_COMPOSITION_LAYER_QUAD";
            break;
        case XR_TYPE_REFERENCE_SPACE_CREATE_INFO:
            jdata = "XR_TYPE_REFERENCE_SPACE_CREATE_INFO";
            break;
        case XR_TYPE_ACTION_SPACE_CREATE_INFO:
            jdata = "XR_TYPE_ACTION_SPACE_CREATE_INFO";
            break;
        case XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING:
            jdata = "XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING";
            break;
        case XR_TYPE_VIEW_CONFIGURATION_VIEW:
            jdata = "XR_TYPE_VIEW_CONFIGURATION_VIEW";
            break;
        case XR_TYPE_SPACE_LOCATION:
            jdata = "XR_TYPE_SPACE_LOCATION";
            break;
        case XR_TYPE_SPACE_VELOCITY:
            jdata = "XR_TYPE_SPACE_VELOCITY";
            break;
        case XR_TYPE_FRAME_STATE:
            jdata = "XR_TYPE_FRAME_STATE";
            break;
        case XR_TYPE_VIEW_CONFIGURATION_PROPERTIES:
            jdata = "XR_TYPE_VIEW_CONFIGURATION_PROPERTIES";
            break;
        case XR_TYPE_FRAME_BEGIN_INFO:
            jdata = "XR_TYPE_FRAME_BEGIN_INFO";
            break;
        case XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW:
            jdata = "XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW";
            break;
        case XR_TYPE_EVENT_DATA_EVENTS_LOST:
            jdata = "XR_TYPE_EVENT_DATA_EVENTS_LOST";
            break;
        case XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING:
            jdata = "XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING";
            break;
        case XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED:
            jdata = "XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED";
            break;
        case XR_TYPE_INTERACTION_PROFILE_STATE:
            jdata = "XR_TYPE_INTERACTION_PROFILE_STATE";
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO:
            jdata = "XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO";
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO:
            jdata = "XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO";
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO:
            jdata = "XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO";
            break;
        case XR_TYPE_ACTION_STATE_GET_INFO:
            jdata = "XR_TYPE_ACTION_STATE_GET_INFO";
            break;
        case XR_TYPE_HAPTIC_ACTION_INFO:
            jdata = "XR_TYPE_HAPTIC_ACTION_INFO";
            break;
        case XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO:
            jdata = "XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO";
            break;
        case XR_TYPE_ACTIONS_SYNC_INFO:
            jdata = "XR_TYPE_ACTIONS_SYNC_INFO";
            break;
        case XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO:
            jdata = "XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO";
            break;
        case XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO:
            jdata = "XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO";
            break;
        case XR_TYPE_COMPOSITION_LAYER_CUBE_KHR:
            jdata = "XR_TYPE_COMPOSITION_LAYER_CUBE_KHR";
            break;
        case XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR:
            jdata = "XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR";
            break;
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR:
            jdata = "XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR";
            break;
        case XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR:
            jdata = "XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR";
            break;
        case XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT:
            jdata = "XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT";
            break;
        case XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR:
            jdata = "XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR";
            break;
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR:
            jdata = "XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR";
            break;
        case XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT:
            jdata = "XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT";
            break;
        case XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT:
            jdata = "XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT";
            break;
        case XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            jdata = "XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT";
            break;
        case XR_TYPE_DEBUG_UTILS_LABEL_EXT:
            jdata = "XR_TYPE_DEBUG_UTILS_LABEL_EXT";
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR:
            jdata = "XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR";
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR:
            jdata = "XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR";
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR:
            jdata = "XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR";
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR:
            jdata = "XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR";
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR:
            jdata = "XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR";
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR:
            jdata = "XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR";
            break;
        case XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR:
            jdata = "XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR";
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR:
            jdata = "XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR";
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR:
            jdata = "XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR";
            break;
        case XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR:
            jdata = "XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR";
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR:
            jdata = "XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR";
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR:
            jdata = "XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR";
            break;
        case XR_TYPE_GRAPHICS_BINDING_D3D11_KHR:
            jdata = "XR_TYPE_GRAPHICS_BINDING_D3D11_KHR";
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR:
            jdata = "XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR";
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR:
            jdata = "XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR";
            break;
        case XR_TYPE_GRAPHICS_BINDING_D3D12_KHR:
            jdata = "XR_TYPE_GRAPHICS_BINDING_D3D12_KHR";
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR:
            jdata = "XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR";
            break;
        case XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR:
            jdata = "XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR";
            break;
        case XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT:
            jdata = "XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT";
            break;
        case XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT:
            jdata = "XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT";
            break;
        case XR_TYPE_VISIBILITY_MASK_KHR:
            jdata = "XR_TYPE_VISIBILITY_MASK_KHR";
            break;
        case XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR:
            jdata = "XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR";
            break;
        case XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX:
            jdata = "XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX";
            break;
        case XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX:
            jdata = "XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX";
            break;
        case XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR:
            jdata = "XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR";
            break;
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT:
            jdata = "XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT";
            break;
        case XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT:
            jdata = "XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT";
            break;
        case XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB:
            jdata = "XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB";
            break;
        case XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB:
            jdata = "XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB";
            break;
        case XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT:
            jdata = "XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT";
            break;
        case XR_TYPE_GRAPHICS_BINDING_EGL_MNDX:
            jdata = "XR_TYPE_GRAPHICS_BINDING_EGL_MNDX";
            break;
        case XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT:
            jdata = "XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT";
            break;
        case XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT:
            jdata = "XR_TYPE_SPATIAL_GRAPH_STATIC_NODE_BINDING_CREATE_INFO_MSFT";
            break;
        case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_GET_INFO_MSFT:
            jdata = "XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_GET_INFO_MSFT";
            break;
        case XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT:
            jdata = "XR_TYPE_SPATIAL_GRAPH_NODE_BINDING_PROPERTIES_MSFT";
            break;
        case XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT:
            jdata = "XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT";
            break;
        case XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT:
            jdata = "XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT";
            break;
        case XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT:
            jdata = "XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT";
            break;
        case XR_TYPE_HAND_JOINT_LOCATIONS_EXT:
            jdata = "XR_TYPE_HAND_JOINT_LOCATIONS_EXT";
            break;
        case XR_TYPE_HAND_JOINT_VELOCITIES_EXT:
            jdata = "XR_TYPE_HAND_JOINT_VELOCITIES_EXT";
            break;
        case XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT:
            jdata = "XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT";
            break;
        case XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT:
            jdata = "XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT";
            break;
        case XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT:
            jdata = "XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT";
            break;
        case XR_TYPE_HAND_MESH_MSFT:
            jdata = "XR_TYPE_HAND_MESH_MSFT";
            break;
        case XR_TYPE_HAND_POSE_TYPE_INFO_MSFT:
            jdata = "XR_TYPE_HAND_POSE_TYPE_INFO_MSFT";
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT:
            jdata = "XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT";
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT:
            jdata = "XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT";
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT:
            jdata = "XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT";
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT:
            jdata = "XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT";
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT:
            jdata = "XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT";
            break;
        case XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT:
            jdata = "XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT";
            break;
        case XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT:
            jdata = "XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT";
            break;
        case XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT:
            jdata = "XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT";
            break;
        case XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT:
            jdata = "XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT";
            break;
        case XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT:
            jdata = "XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT";
            break;
        case XR_TYPE_CONTROLLER_MODEL_STATE_MSFT:
            jdata = "XR_TYPE_CONTROLLER_MODEL_STATE_MSFT";
            break;
        case XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC:
            jdata = "XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC";
            break;
        case XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT:
            jdata = "XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT";
            break;
        case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT:
            jdata = "XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT";
            break;
        case XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT:
            jdata = "XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT";
            break;
        case XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB:
            jdata = "XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB";
            break;
        case XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB:
            jdata = "XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB";
            break;
        case XR_TYPE_BODY_TRACKER_CREATE_INFO_FB:
            jdata = "XR_TYPE_BODY_TRACKER_CREATE_INFO_FB";
            break;
        case XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB:
            jdata = "XR_TYPE_BODY_JOINTS_LOCATE_INFO_FB";
            break;
        case XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB:
            jdata = "XR_TYPE_SYSTEM_BODY_TRACKING_PROPERTIES_FB";
            break;
        case XR_TYPE_BODY_JOINT_LOCATIONS_FB:
            jdata = "XR_TYPE_BODY_JOINT_LOCATIONS_FB";
            break;
        case XR_TYPE_BODY_SKELETON_FB:
            jdata = "XR_TYPE_BODY_SKELETON_FB";
            break;
        case XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT:
            jdata = "XR_TYPE_INTERACTION_PROFILE_DPAD_BINDING_EXT";
            break;
        case XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE:
            jdata = "XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE";
            break;
        case XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT:
            jdata = "XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT";
            break;
        case XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR:
            jdata = "XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR";
            break;
        case XR_TYPE_VULKAN_INSTANCE_CREATE_INFO_KHR:
            jdata = "XR_TYPE_VULKAN_INSTANCE_CREATE_INFO_KHR";
            break;
        case XR_TYPE_VULKAN_DEVICE_CREATE_INFO_KHR:
            jdata = "XR_TYPE_VULKAN_DEVICE_CREATE_INFO_KHR";
            break;
        case XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR:
            jdata = "XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR";
            break;
        case XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR:
            jdata = "XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR";
            break;
        case XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT:
            jdata = "XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT";
            break;
        case XR_TYPE_SCENE_CREATE_INFO_MSFT:
            jdata = "XR_TYPE_SCENE_CREATE_INFO_MSFT";
            break;
        case XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT:
            jdata = "XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT";
            break;
        case XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT:
            jdata = "XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT";
            break;
        case XR_TYPE_SCENE_COMPONENTS_MSFT:
            jdata = "XR_TYPE_SCENE_COMPONENTS_MSFT";
            break;
        case XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT:
            jdata = "XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT";
            break;
        case XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT:
            jdata = "XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT";
            break;
        case XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT:
            jdata = "XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT";
            break;
        case XR_TYPE_SCENE_OBJECTS_MSFT:
            jdata = "XR_TYPE_SCENE_OBJECTS_MSFT";
            break;
        case XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT:
            jdata = "XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT";
            break;
        case XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT:
            jdata = "XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT";
            break;
        case XR_TYPE_SCENE_PLANES_MSFT:
            jdata = "XR_TYPE_SCENE_PLANES_MSFT";
            break;
        case XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT:
            jdata = "XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT";
            break;
        case XR_TYPE_SCENE_MESHES_MSFT:
            jdata = "XR_TYPE_SCENE_MESHES_MSFT";
            break;
        case XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT:
            jdata = "XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT";
            break;
        case XR_TYPE_SCENE_MESH_BUFFERS_MSFT:
            jdata = "XR_TYPE_SCENE_MESH_BUFFERS_MSFT";
            break;
        case XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT:
            jdata = "XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT";
            break;
        case XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT:
            jdata = "XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT";
            break;
        case XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT:
            jdata = "XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT";
            break;
        case XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT:
            jdata = "XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT";
            break;
        case XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT:
            jdata = "XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT";
            break;
        case XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB:
            jdata = "XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB";
            break;
        case XR_TYPE_VIVE_TRACKER_PATHS_HTCX:
            jdata = "XR_TYPE_VIVE_TRACKER_PATHS_HTCX";
            break;
        case XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX:
            jdata = "XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX";
            break;
        case XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC:
            jdata = "XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC";
            break;
        case XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC:
            jdata = "XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC";
            break;
        case XR_TYPE_FACIAL_EXPRESSIONS_HTC:
            jdata = "XR_TYPE_FACIAL_EXPRESSIONS_HTC";
            break;
        case XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB:
            jdata = "XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB";
            break;
        case XR_TYPE_HAND_TRACKING_MESH_FB:
            jdata = "XR_TYPE_HAND_TRACKING_MESH_FB";
            break;
        case XR_TYPE_HAND_TRACKING_SCALE_FB:
            jdata = "XR_TYPE_HAND_TRACKING_SCALE_FB";
            break;
        case XR_TYPE_HAND_TRACKING_AIM_STATE_FB:
            jdata = "XR_TYPE_HAND_TRACKING_AIM_STATE_FB";
            break;
        case XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB:
            jdata = "XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB";
            break;
        case XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB:
            jdata = "XR_TYPE_SYSTEM_SPATIAL_ENTITY_PROPERTIES_FB";
            break;
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB:
            jdata = "XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_FB";
            break;
        case XR_TYPE_SPACE_COMPONENT_STATUS_SET_INFO_FB:
            jdata = "XR_TYPE_SPACE_COMPONENT_STATUS_SET_INFO_FB";
            break;
        case XR_TYPE_SPACE_COMPONENT_STATUS_FB:
            jdata = "XR_TYPE_SPACE_COMPONENT_STATUS_FB";
            break;
        case XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB:
            jdata = "XR_TYPE_EVENT_DATA_SPATIAL_ANCHOR_CREATE_COMPLETE_FB";
            break;
        case XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB:
            jdata = "XR_TYPE_EVENT_DATA_SPACE_SET_STATUS_COMPLETE_FB";
            break;
        case XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB:
            jdata = "XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB";
            break;
        case XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB:
            jdata = "XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB";
            break;
        case XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB:
            jdata = "XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB";
            break;
        case XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB:
            jdata = "XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB";
            break;
        case XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB:
            jdata = "XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB";
            break;
        case XR_TYPE_KEYBOARD_TRACKING_QUERY_FB:
            jdata = "XR_TYPE_KEYBOARD_TRACKING_QUERY_FB";
            break;
        case XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB:
            jdata = "XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB";
            break;
        case XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB:
            jdata = "XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB";
            break;
        case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB:
            jdata = "XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB";
            break;
        case XR_TYPE_PASSTHROUGH_CREATE_INFO_FB:
            jdata = "XR_TYPE_PASSTHROUGH_CREATE_INFO_FB";
            break;
        case XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB:
            jdata = "XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB";
            break;
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB:
            jdata = "XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB";
            break;
        case XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB:
            jdata = "XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB";
            break;
        case XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB:
            jdata = "XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB";
            break;
        case XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB:
            jdata = "XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES2_FB";
            break;
        case XR_TYPE_PASSTHROUGH_STYLE_FB:
            jdata = "XR_TYPE_PASSTHROUGH_STYLE_FB";
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB:
            jdata = "XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB";
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB:
            jdata = "XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB";
            break;
        case XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB:
            jdata = "XR_TYPE_PASSTHROUGH_BRIGHTNESS_CONTRAST_SATURATION_FB";
            break;
        case XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB:
            jdata = "XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB";
            break;
        case XR_TYPE_RENDER_MODEL_PATH_INFO_FB:
            jdata = "XR_TYPE_RENDER_MODEL_PATH_INFO_FB";
            break;
        case XR_TYPE_RENDER_MODEL_PROPERTIES_FB:
            jdata = "XR_TYPE_RENDER_MODEL_PROPERTIES_FB";
            break;
        case XR_TYPE_RENDER_MODEL_BUFFER_FB:
            jdata = "XR_TYPE_RENDER_MODEL_BUFFER_FB";
            break;
        case XR_TYPE_RENDER_MODEL_LOAD_INFO_FB:
            jdata = "XR_TYPE_RENDER_MODEL_LOAD_INFO_FB";
            break;
        case XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB:
            jdata = "XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB";
            break;
        case XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB:
            jdata = "XR_TYPE_RENDER_MODEL_CAPABILITIES_REQUEST_FB";
            break;
        case XR_TYPE_BINDING_MODIFICATIONS_KHR:
            jdata = "XR_TYPE_BINDING_MODIFICATIONS_KHR";
            break;
        case XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO:
            jdata = "XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO";
            break;
        case XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO:
            jdata = "XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO";
            break;
        case XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO:
            jdata = "XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO";
            break;
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO:
            jdata = "XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO";
            break;
        case XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO:
            jdata = "XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO";
            break;
        case XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO:
            jdata = "XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO";
            break;
        case XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO:
            jdata = "XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO";
            break;
        case XR_TYPE_FRAME_END_INFO_ML:
            jdata = "XR_TYPE_FRAME_END_INFO_ML";
            break;
        case XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML:
            jdata = "XR_TYPE_GLOBAL_DIMMER_FRAME_END_INFO_ML";
            break;
        case XR_TYPE_COORDINATE_SPACE_CREATE_INFO_ML:
            jdata = "XR_TYPE_COORDINATE_SPACE_CREATE_INFO_ML";
            break;
        case XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML:
            jdata = "XR_TYPE_SYSTEM_MARKER_UNDERSTANDING_PROPERTIES_ML";
            break;
        case XR_TYPE_MARKER_DETECTOR_CREATE_INFO_ML:
            jdata = "XR_TYPE_MARKER_DETECTOR_CREATE_INFO_ML";
            break;
        case XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML:
            jdata = "XR_TYPE_MARKER_DETECTOR_ARUCO_INFO_ML";
            break;
        case XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML:
            jdata = "XR_TYPE_MARKER_DETECTOR_SIZE_INFO_ML";
            break;
        case XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML:
            jdata = "XR_TYPE_MARKER_DETECTOR_APRIL_TAG_INFO_ML";
            break;
        case XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML:
            jdata = "XR_TYPE_MARKER_DETECTOR_CUSTOM_PROFILE_INFO_ML";
            break;
        case XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML:
            jdata = "XR_TYPE_MARKER_DETECTOR_SNAPSHOT_INFO_ML";
            break;
        case XR_TYPE_MARKER_DETECTOR_STATE_ML:
            jdata = "XR_TYPE_MARKER_DETECTOR_STATE_ML";
            break;
        case XR_TYPE_MARKER_SPACE_CREATE_INFO_ML:
            jdata = "XR_TYPE_MARKER_SPACE_CREATE_INFO_ML";
            break;
        case XR_TYPE_LOCALIZATION_MAP_ML:
            jdata = "XR_TYPE_LOCALIZATION_MAP_ML";
            break;
        case XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML:
            jdata = "XR_TYPE_EVENT_DATA_LOCALIZATION_CHANGED_ML";
            break;
        case XR_TYPE_MAP_LOCALIZATION_REQUEST_INFO_ML:
            jdata = "XR_TYPE_MAP_LOCALIZATION_REQUEST_INFO_ML";
            break;
        case XR_TYPE_LOCALIZATION_MAP_IMPORT_INFO_ML:
            jdata = "XR_TYPE_LOCALIZATION_MAP_IMPORT_INFO_ML";
            break;
        case XR_TYPE_LOCALIZATION_ENABLE_EVENTS_INFO_ML:
            jdata = "XR_TYPE_LOCALIZATION_ENABLE_EVENTS_INFO_ML";
            break;
        case XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML:
            jdata = "XR_TYPE_EVENT_DATA_HEADSET_FIT_CHANGED_ML";
            break;
        case XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML:
            jdata = "XR_TYPE_EVENT_DATA_EYE_CALIBRATION_CHANGED_ML";
            break;
        case XR_TYPE_USER_CALIBRATION_ENABLE_EVENTS_INFO_ML:
            jdata = "XR_TYPE_USER_CALIBRATION_ENABLE_EVENTS_INFO_ML";
            break;
        case XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT:
            jdata = "XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT";
            break;
        case XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT:
            jdata = "XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT";
            break;
        case XR_TYPE_SCENE_MARKERS_MSFT:
            jdata = "XR_TYPE_SCENE_MARKERS_MSFT";
            break;
        case XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT:
            jdata = "XR_TYPE_SCENE_MARKER_TYPE_FILTER_MSFT";
            break;
        case XR_TYPE_SCENE_MARKER_QR_CODES_MSFT:
            jdata = "XR_TYPE_SCENE_MARKER_QR_CODES_MSFT";
            break;
        case XR_TYPE_SPACE_QUERY_INFO_FB:
            jdata = "XR_TYPE_SPACE_QUERY_INFO_FB";
            break;
        case XR_TYPE_SPACE_QUERY_RESULTS_FB:
            jdata = "XR_TYPE_SPACE_QUERY_RESULTS_FB";
            break;
        case XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB:
            jdata = "XR_TYPE_SPACE_STORAGE_LOCATION_FILTER_INFO_FB";
            break;
        case XR_TYPE_SPACE_UUID_FILTER_INFO_FB:
            jdata = "XR_TYPE_SPACE_UUID_FILTER_INFO_FB";
            break;
        case XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB:
            jdata = "XR_TYPE_SPACE_COMPONENT_FILTER_INFO_FB";
            break;
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB:
            jdata = "XR_TYPE_EVENT_DATA_SPACE_QUERY_RESULTS_AVAILABLE_FB";
            break;
        case XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB:
            jdata = "XR_TYPE_EVENT_DATA_SPACE_QUERY_COMPLETE_FB";
            break;
        case XR_TYPE_SPACE_SAVE_INFO_FB:
            jdata = "XR_TYPE_SPACE_SAVE_INFO_FB";
            break;
        case XR_TYPE_SPACE_ERASE_INFO_FB:
            jdata = "XR_TYPE_SPACE_ERASE_INFO_FB";
            break;
        case XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB:
            jdata = "XR_TYPE_EVENT_DATA_SPACE_SAVE_COMPLETE_FB";
            break;
        case XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB:
            jdata = "XR_TYPE_EVENT_DATA_SPACE_ERASE_COMPLETE_FB";
            break;
        case XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB:
            jdata = "XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB";
            break;
        case XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB:
            jdata = "XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB";
            break;
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB:
            jdata = "XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB";
            break;
        case XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB:
            jdata = "XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB";
            break;
        case XR_TYPE_SPACE_SHARE_INFO_FB:
            jdata = "XR_TYPE_SPACE_SHARE_INFO_FB";
            break;
        case XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB:
            jdata = "XR_TYPE_EVENT_DATA_SPACE_SHARE_COMPLETE_FB";
            break;
        case XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB:
            jdata = "XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB";
            break;
        case XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB:
            jdata = "XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB";
            break;
        case XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB:
            jdata = "XR_TYPE_HAPTIC_AMPLITUDE_ENVELOPE_VIBRATION_FB";
            break;
        case XR_TYPE_SEMANTIC_LABELS_FB:
            jdata = "XR_TYPE_SEMANTIC_LABELS_FB";
            break;
        case XR_TYPE_ROOM_LAYOUT_FB:
            jdata = "XR_TYPE_ROOM_LAYOUT_FB";
            break;
        case XR_TYPE_BOUNDARY_2D_FB:
            jdata = "XR_TYPE_BOUNDARY_2D_FB";
            break;
        case XR_TYPE_SEMANTIC_LABELS_SUPPORT_INFO_FB:
            jdata = "XR_TYPE_SEMANTIC_LABELS_SUPPORT_INFO_FB";
            break;
        case XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE:
            jdata = "XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE";
            break;
        case XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB:
            jdata = "XR_TYPE_EVENT_DATA_SCENE_CAPTURE_COMPLETE_FB";
            break;
        case XR_TYPE_SCENE_CAPTURE_REQUEST_INFO_FB:
            jdata = "XR_TYPE_SCENE_CAPTURE_REQUEST_INFO_FB";
            break;
        case XR_TYPE_SPACE_CONTAINER_FB:
            jdata = "XR_TYPE_SPACE_CONTAINER_FB";
            break;
        case XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META:
            jdata = "XR_TYPE_FOVEATION_EYE_TRACKED_PROFILE_CREATE_INFO_META";
            break;
        case XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META:
            jdata = "XR_TYPE_FOVEATION_EYE_TRACKED_STATE_META";
            break;
        case XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META:
            jdata = "XR_TYPE_SYSTEM_FOVEATION_EYE_TRACKED_PROPERTIES_META";
            break;
        case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB:
            jdata = "XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES_FB";
            break;
        case XR_TYPE_FACE_TRACKER_CREATE_INFO_FB:
            jdata = "XR_TYPE_FACE_TRACKER_CREATE_INFO_FB";
            break;
        case XR_TYPE_FACE_EXPRESSION_INFO_FB:
            jdata = "XR_TYPE_FACE_EXPRESSION_INFO_FB";
            break;
        case XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB:
            jdata = "XR_TYPE_FACE_EXPRESSION_WEIGHTS_FB";
            break;
        case XR_TYPE_EYE_TRACKER_CREATE_INFO_FB:
            jdata = "XR_TYPE_EYE_TRACKER_CREATE_INFO_FB";
            break;
        case XR_TYPE_EYE_GAZES_INFO_FB:
            jdata = "XR_TYPE_EYE_GAZES_INFO_FB";
            break;
        case XR_TYPE_EYE_GAZES_FB:
            jdata = "XR_TYPE_EYE_GAZES_FB";
            break;
        case XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB:
            jdata = "XR_TYPE_SYSTEM_EYE_TRACKING_PROPERTIES_FB";
            break;
        case XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB:
            jdata = "XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB";
            break;
        case XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB:
            jdata = "XR_TYPE_COMPOSITION_LAYER_SETTINGS_FB";
            break;
        case XR_TYPE_HAPTIC_PCM_VIBRATION_FB:
            jdata = "XR_TYPE_HAPTIC_PCM_VIBRATION_FB";
            break;
        case XR_TYPE_DEVICE_PCM_SAMPLE_RATE_STATE_FB:
            jdata = "XR_TYPE_DEVICE_PCM_SAMPLE_RATE_STATE_FB";
            break;
        case XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB:
            jdata = "XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_FB";
            break;
        case XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META:
            jdata = "XR_TYPE_LOCAL_DIMMING_FRAME_END_INFO_META";
            break;
        case XR_TYPE_PASSTHROUGH_PREFERENCES_META:
            jdata = "XR_TYPE_PASSTHROUGH_PREFERENCES_META";
            break;
        case XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META:
            jdata = "XR_TYPE_SYSTEM_VIRTUAL_KEYBOARD_PROPERTIES_META";
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_CREATE_INFO_META:
            jdata = "XR_TYPE_VIRTUAL_KEYBOARD_CREATE_INFO_META";
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META:
            jdata = "XR_TYPE_VIRTUAL_KEYBOARD_SPACE_CREATE_INFO_META";
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META:
            jdata = "XR_TYPE_VIRTUAL_KEYBOARD_LOCATION_INFO_META";
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_VISIBILITY_SET_INFO_META:
            jdata = "XR_TYPE_VIRTUAL_KEYBOARD_MODEL_VISIBILITY_SET_INFO_META";
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_ANIMATION_STATE_META:
            jdata = "XR_TYPE_VIRTUAL_KEYBOARD_ANIMATION_STATE_META";
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META:
            jdata = "XR_TYPE_VIRTUAL_KEYBOARD_MODEL_ANIMATION_STATES_META";
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META:
            jdata = "XR_TYPE_VIRTUAL_KEYBOARD_TEXTURE_DATA_META";
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META:
            jdata = "XR_TYPE_VIRTUAL_KEYBOARD_INPUT_INFO_META";
            break;
        case XR_TYPE_VIRTUAL_KEYBOARD_TEXT_CONTEXT_CHANGE_INFO_META:
            jdata = "XR_TYPE_VIRTUAL_KEYBOARD_TEXT_CONTEXT_CHANGE_INFO_META";
            break;
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META:
            jdata = "XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_COMMIT_TEXT_META";
            break;
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META:
            jdata = "XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_BACKSPACE_META";
            break;
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META:
            jdata = "XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_ENTER_META";
            break;
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META:
            jdata = "XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_SHOWN_META";
            break;
        case XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META:
            jdata = "XR_TYPE_EVENT_DATA_VIRTUAL_KEYBOARD_HIDDEN_META";
            break;
        case XR_TYPE_EXTERNAL_CAMERA_OCULUS:
            jdata = "XR_TYPE_EXTERNAL_CAMERA_OCULUS";
            break;
        case XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META:
            jdata = "XR_TYPE_VULKAN_SWAPCHAIN_CREATE_INFO_META";
            break;
        case XR_TYPE_PERFORMANCE_METRICS_STATE_META:
            jdata = "XR_TYPE_PERFORMANCE_METRICS_STATE_META";
            break;
        case XR_TYPE_PERFORMANCE_METRICS_COUNTER_META:
            jdata = "XR_TYPE_PERFORMANCE_METRICS_COUNTER_META";
            break;
        case XR_TYPE_SPACE_LIST_SAVE_INFO_FB:
            jdata = "XR_TYPE_SPACE_LIST_SAVE_INFO_FB";
            break;
        case XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB:
            jdata = "XR_TYPE_EVENT_DATA_SPACE_LIST_SAVE_COMPLETE_FB";
            break;
        case XR_TYPE_SPACE_USER_CREATE_INFO_FB:
            jdata = "XR_TYPE_SPACE_USER_CREATE_INFO_FB";
            break;
        case XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META:
            jdata = "XR_TYPE_SYSTEM_HEADSET_ID_PROPERTIES_META";
            break;
        case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META:
            jdata = "XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_META";
            break;
        case XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META:
            jdata = "XR_TYPE_RECOMMENDED_LAYER_RESOLUTION_GET_INFO_META";
            break;
        case XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META:
            jdata = "XR_TYPE_SYSTEM_PASSTHROUGH_COLOR_LUT_PROPERTIES_META";
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_LUT_CREATE_INFO_META:
            jdata = "XR_TYPE_PASSTHROUGH_COLOR_LUT_CREATE_INFO_META";
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_LUT_UPDATE_INFO_META:
            jdata = "XR_TYPE_PASSTHROUGH_COLOR_LUT_UPDATE_INFO_META";
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META:
            jdata = "XR_TYPE_PASSTHROUGH_COLOR_MAP_LUT_META";
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META:
            jdata = "XR_TYPE_PASSTHROUGH_COLOR_MAP_INTERPOLATED_LUT_META";
            break;
        case XR_TYPE_SPACE_TRIANGLE_MESH_GET_INFO_META:
            jdata = "XR_TYPE_SPACE_TRIANGLE_MESH_GET_INFO_META";
            break;
        case XR_TYPE_SPACE_TRIANGLE_MESH_META:
            jdata = "XR_TYPE_SPACE_TRIANGLE_MESH_META";
            break;
        case XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB:
            jdata = "XR_TYPE_SYSTEM_FACE_TRACKING_PROPERTIES2_FB";
            break;
        case XR_TYPE_FACE_TRACKER_CREATE_INFO2_FB:
            jdata = "XR_TYPE_FACE_TRACKER_CREATE_INFO2_FB";
            break;
        case XR_TYPE_FACE_EXPRESSION_INFO2_FB:
            jdata = "XR_TYPE_FACE_EXPRESSION_INFO2_FB";
            break;
        case XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB:
            jdata = "XR_TYPE_FACE_EXPRESSION_WEIGHTS2_FB";
            break;
        case XR_TYPE_PASSTHROUGH_CREATE_INFO_HTC:
            jdata = "XR_TYPE_PASSTHROUGH_CREATE_INFO_HTC";
            break;
        case XR_TYPE_PASSTHROUGH_COLOR_HTC:
            jdata = "XR_TYPE_PASSTHROUGH_COLOR_HTC";
            break;
        case XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC:
            jdata = "XR_TYPE_PASSTHROUGH_MESH_TRANSFORM_INFO_HTC";
            break;
        case XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC:
            jdata = "XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_HTC";
            break;
        case XR_TYPE_FOVEATION_APPLY_INFO_HTC:
            jdata = "XR_TYPE_FOVEATION_APPLY_INFO_HTC";
            break;
        case XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC:
            jdata = "XR_TYPE_FOVEATION_DYNAMIC_MODE_INFO_HTC";
            break;
        case XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC:
            jdata = "XR_TYPE_FOVEATION_CUSTOM_MODE_INFO_HTC";
            break;
        case XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC:
            jdata = "XR_TYPE_SYSTEM_ANCHOR_PROPERTIES_HTC";
            break;
        case XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC:
            jdata = "XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_HTC";
            break;
        case XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT:
            jdata = "XR_TYPE_ACTIVE_ACTION_SET_PRIORITIES_EXT";
            break;
        case XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX:
            jdata = "XR_TYPE_SYSTEM_FORCE_FEEDBACK_CURL_PROPERTIES_MNDX";
            break;
        case XR_TYPE_FORCE_FEEDBACK_CURL_APPLY_LOCATIONS_MNDX:
            jdata = "XR_TYPE_FORCE_FEEDBACK_CURL_APPLY_LOCATIONS_MNDX";
            break;
        case XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT:
            jdata = "XR_TYPE_HAND_TRACKING_DATA_SOURCE_INFO_EXT";
            break;
        case XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT:
            jdata = "XR_TYPE_HAND_TRACKING_DATA_SOURCE_STATE_EXT";
            break;
        case XR_TYPE_PLANE_DETECTOR_CREATE_INFO_EXT:
            jdata = "XR_TYPE_PLANE_DETECTOR_CREATE_INFO_EXT";
            break;
        case XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT:
            jdata = "XR_TYPE_PLANE_DETECTOR_BEGIN_INFO_EXT";
            break;
        case XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT:
            jdata = "XR_TYPE_PLANE_DETECTOR_GET_INFO_EXT";
            break;
        case XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT:
            jdata = "XR_TYPE_PLANE_DETECTOR_LOCATIONS_EXT";
            break;
        case XR_TYPE_PLANE_DETECTOR_LOCATION_EXT:
            jdata = "XR_TYPE_PLANE_DETECTOR_LOCATION_EXT";
            break;
        case XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT:
            jdata = "XR_TYPE_PLANE_DETECTOR_POLYGON_BUFFER_EXT";
            break;
        case XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT:
            jdata = "XR_TYPE_SYSTEM_PLANE_DETECTION_PROPERTIES_EXT";
            break;
        case XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT:
            jdata = "XR_TYPE_EVENT_DATA_USER_PRESENCE_CHANGED_EXT";
            break;
        case XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT:
            jdata = "XR_TYPE_SYSTEM_USER_PRESENCE_PROPERTIES_EXT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrTrackingOptimizationSettingsDomainQCOM& value, const JsonOptions& options)
{
    switch (value) {
        case XR_TRACKING_OPTIMIZATION_SETTINGS_DOMAIN_ALL_QCOM:
            jdata = "XR_TRACKING_OPTIMIZATION_SETTINGS_DOMAIN_ALL_QCOM";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrTrackingOptimizationSettingsHintQCOM& value, const JsonOptions& options)
{
    switch (value) {
        case XR_TRACKING_OPTIMIZATION_SETTINGS_HINT_NONE_QCOM:
            jdata = "XR_TRACKING_OPTIMIZATION_SETTINGS_HINT_NONE_QCOM";
            break;
        case XR_TRACKING_OPTIMIZATION_SETTINGS_HINT_LONG_RANGE_PRIORIZATION_QCOM:
            jdata = "XR_TRACKING_OPTIMIZATION_SETTINGS_HINT_LONG_RANGE_PRIORIZATION_QCOM";
            break;
        case XR_TRACKING_OPTIMIZATION_SETTINGS_HINT_CLOSE_RANGE_PRIORIZATION_QCOM:
            jdata = "XR_TRACKING_OPTIMIZATION_SETTINGS_HINT_CLOSE_RANGE_PRIORIZATION_QCOM";
            break;
        case XR_TRACKING_OPTIMIZATION_SETTINGS_HINT_LOW_POWER_PRIORIZATION_QCOM:
            jdata = "XR_TRACKING_OPTIMIZATION_SETTINGS_HINT_LOW_POWER_PRIORIZATION_QCOM";
            break;
        case XR_TRACKING_OPTIMIZATION_SETTINGS_HINT_HIGH_POWER_PRIORIZATION_QCOM:
            jdata = "XR_TRACKING_OPTIMIZATION_SETTINGS_HINT_HIGH_POWER_PRIORIZATION_QCOM";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrViewConfigurationType& value, const JsonOptions& options)
{
    switch (value) {
        case XR_VIEW_CONFIGURATION_TYPE_PRIMARY_MONO:
            jdata = "XR_VIEW_CONFIGURATION_TYPE_PRIMARY_MONO";
            break;
        case XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO:
            jdata = "XR_VIEW_CONFIGURATION_TYPE_PRIMARY_STEREO";
            break;
        case XR_VIEW_CONFIGURATION_TYPE_PRIMARY_QUAD_VARJO:
            jdata = "XR_VIEW_CONFIGURATION_TYPE_PRIMARY_QUAD_VARJO";
            break;
        case XR_VIEW_CONFIGURATION_TYPE_SECONDARY_MONO_FIRST_PERSON_OBSERVER_MSFT:
            jdata = "XR_VIEW_CONFIGURATION_TYPE_SECONDARY_MONO_FIRST_PERSON_OBSERVER_MSFT";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrVirtualKeyboardInputSourceMETA& value, const JsonOptions& options)
{
    switch (value) {
        case XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_CONTROLLER_RAY_LEFT_META:
            jdata = "XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_CONTROLLER_RAY_LEFT_META";
            break;
        case XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_CONTROLLER_RAY_RIGHT_META:
            jdata = "XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_CONTROLLER_RAY_RIGHT_META";
            break;
        case XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_HAND_RAY_LEFT_META:
            jdata = "XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_HAND_RAY_LEFT_META";
            break;
        case XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_HAND_RAY_RIGHT_META:
            jdata = "XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_HAND_RAY_RIGHT_META";
            break;
        case XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_CONTROLLER_DIRECT_LEFT_META:
            jdata = "XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_CONTROLLER_DIRECT_LEFT_META";
            break;
        case XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_CONTROLLER_DIRECT_RIGHT_META:
            jdata = "XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_CONTROLLER_DIRECT_RIGHT_META";
            break;
        case XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_HAND_DIRECT_INDEX_TIP_LEFT_META:
            jdata = "XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_HAND_DIRECT_INDEX_TIP_LEFT_META";
            break;
        case XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_HAND_DIRECT_INDEX_TIP_RIGHT_META:
            jdata = "XR_VIRTUAL_KEYBOARD_INPUT_SOURCE_HAND_DIRECT_INDEX_TIP_RIGHT_META";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrVirtualKeyboardLocationTypeMETA& value, const JsonOptions& options)
{
    switch (value) {
        case XR_VIRTUAL_KEYBOARD_LOCATION_TYPE_CUSTOM_META:
            jdata = "XR_VIRTUAL_KEYBOARD_LOCATION_TYPE_CUSTOM_META";
            break;
        case XR_VIRTUAL_KEYBOARD_LOCATION_TYPE_FAR_META:
            jdata = "XR_VIRTUAL_KEYBOARD_LOCATION_TYPE_FAR_META";
            break;
        case XR_VIRTUAL_KEYBOARD_LOCATION_TYPE_DIRECT_META:
            jdata = "XR_VIRTUAL_KEYBOARD_LOCATION_TYPE_DIRECT_META";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrVisibilityMaskTypeKHR& value, const JsonOptions& options)
{
    switch (value) {
        case XR_VISIBILITY_MASK_TYPE_HIDDEN_TRIANGLE_MESH_KHR:
            jdata = "XR_VISIBILITY_MASK_TYPE_HIDDEN_TRIANGLE_MESH_KHR";
            break;
        case XR_VISIBILITY_MASK_TYPE_VISIBLE_TRIANGLE_MESH_KHR:
            jdata = "XR_VISIBILITY_MASK_TYPE_VISIBLE_TRIANGLE_MESH_KHR";
            break;
        case XR_VISIBILITY_MASK_TYPE_LINE_LOOP_KHR:
            jdata = "XR_VISIBILITY_MASK_TYPE_LINE_LOOP_KHR";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(nlohmann::ordered_json& jdata, const XrWindingOrderFB& value, const JsonOptions& options)
{
    switch (value) {
        case XR_WINDING_ORDER_UNKNOWN_FB:
            jdata = "XR_WINDING_ORDER_UNKNOWN_FB";
            break;
        case XR_WINDING_ORDER_CW_FB:
            jdata = "XR_WINDING_ORDER_CW_FB";
            break;
        case XR_WINDING_ORDER_CCW_FB:
            jdata = "XR_WINDING_ORDER_CCW_FB";
            break;
        default:
            jdata = to_hex_fixed_width(value);
            break;
    }
}

void FieldToJson(XrAndroidSurfaceSwapchainFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_ANDROID_SURFACE_SWAPCHAIN_SYNCHRONOUS_BIT_FB:
                return std::string("XR_ANDROID_SURFACE_SWAPCHAIN_SYNCHRONOUS_BIT_FB");
            case XR_ANDROID_SURFACE_SWAPCHAIN_USE_TIMESTAMPS_BIT_FB:
                return std::string("XR_ANDROID_SURFACE_SWAPCHAIN_USE_TIMESTAMPS_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrCompositionLayerFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_COMPOSITION_LAYER_CORRECT_CHROMATIC_ABERRATION_BIT:
                return std::string("XR_COMPOSITION_LAYER_CORRECT_CHROMATIC_ABERRATION_BIT");
            case XR_COMPOSITION_LAYER_BLEND_TEXTURE_SOURCE_ALPHA_BIT:
                return std::string("XR_COMPOSITION_LAYER_BLEND_TEXTURE_SOURCE_ALPHA_BIT");
            case XR_COMPOSITION_LAYER_UNPREMULTIPLIED_ALPHA_BIT:
                return std::string("XR_COMPOSITION_LAYER_UNPREMULTIPLIED_ALPHA_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrCompositionLayerImageLayoutFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_COMPOSITION_LAYER_IMAGE_LAYOUT_VERTICAL_FLIP_BIT_FB:
                return std::string("XR_COMPOSITION_LAYER_IMAGE_LAYOUT_VERTICAL_FLIP_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrCompositionLayerSecureContentFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_COMPOSITION_LAYER_SECURE_CONTENT_EXCLUDE_LAYER_BIT_FB:
                return std::string("XR_COMPOSITION_LAYER_SECURE_CONTENT_EXCLUDE_LAYER_BIT_FB");
            case XR_COMPOSITION_LAYER_SECURE_CONTENT_REPLACE_LAYER_BIT_FB:
                return std::string("XR_COMPOSITION_LAYER_SECURE_CONTENT_REPLACE_LAYER_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrCompositionLayerSettingsFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_COMPOSITION_LAYER_SETTINGS_NORMAL_SUPER_SAMPLING_BIT_FB:
                return std::string("XR_COMPOSITION_LAYER_SETTINGS_NORMAL_SUPER_SAMPLING_BIT_FB");
            case XR_COMPOSITION_LAYER_SETTINGS_QUALITY_SUPER_SAMPLING_BIT_FB:
                return std::string("XR_COMPOSITION_LAYER_SETTINGS_QUALITY_SUPER_SAMPLING_BIT_FB");
            case XR_COMPOSITION_LAYER_SETTINGS_NORMAL_SHARPENING_BIT_FB:
                return std::string("XR_COMPOSITION_LAYER_SETTINGS_NORMAL_SHARPENING_BIT_FB");
            case XR_COMPOSITION_LAYER_SETTINGS_QUALITY_SHARPENING_BIT_FB:
                return std::string("XR_COMPOSITION_LAYER_SETTINGS_QUALITY_SHARPENING_BIT_FB");
            case XR_COMPOSITION_LAYER_SETTINGS_AUTO_LAYER_FILTER_BIT_META:
                return std::string("XR_COMPOSITION_LAYER_SETTINGS_AUTO_LAYER_FILTER_BIT_META");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrCompositionLayerSpaceWarpInfoFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_COMPOSITION_LAYER_SPACE_WARP_INFO_FRAME_SKIP_BIT_FB:
                return std::string("XR_COMPOSITION_LAYER_SPACE_WARP_INFO_FRAME_SKIP_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrDebugUtilsMessageSeverityFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT:
                return std::string("XR_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT");
            case XR_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT:
                return std::string("XR_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT");
            case XR_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT:
                return std::string("XR_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT");
            case XR_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT:
                return std::string("XR_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrDebugUtilsMessageTypeFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT:
                return std::string("XR_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT");
            case XR_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT:
                return std::string("XR_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT");
            case XR_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT:
                return std::string("XR_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT");
            case XR_DEBUG_UTILS_MESSAGE_TYPE_CONFORMANCE_BIT_EXT:
                return std::string("XR_DEBUG_UTILS_MESSAGE_TYPE_CONFORMANCE_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrDigitalLensControlFlagsALMALENCE_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_DIGITAL_LENS_CONTROL_PROCESSING_DISABLE_BIT_ALMALENCE:
                return std::string("XR_DIGITAL_LENS_CONTROL_PROCESSING_DISABLE_BIT_ALMALENCE");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrExternalCameraStatusFlagsOCULUS_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_EXTERNAL_CAMERA_STATUS_CONNECTED_BIT_OCULUS:
                return std::string("XR_EXTERNAL_CAMERA_STATUS_CONNECTED_BIT_OCULUS");
            case XR_EXTERNAL_CAMERA_STATUS_CALIBRATING_BIT_OCULUS:
                return std::string("XR_EXTERNAL_CAMERA_STATUS_CALIBRATING_BIT_OCULUS");
            case XR_EXTERNAL_CAMERA_STATUS_CALIBRATION_FAILED_BIT_OCULUS:
                return std::string("XR_EXTERNAL_CAMERA_STATUS_CALIBRATION_FAILED_BIT_OCULUS");
            case XR_EXTERNAL_CAMERA_STATUS_CALIBRATED_BIT_OCULUS:
                return std::string("XR_EXTERNAL_CAMERA_STATUS_CALIBRATED_BIT_OCULUS");
            case XR_EXTERNAL_CAMERA_STATUS_CAPTURING_BIT_OCULUS:
                return std::string("XR_EXTERNAL_CAMERA_STATUS_CAPTURING_BIT_OCULUS");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrFoveationDynamicFlagsHTC_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_FOVEATION_DYNAMIC_LEVEL_ENABLED_BIT_HTC:
                return std::string("XR_FOVEATION_DYNAMIC_LEVEL_ENABLED_BIT_HTC");
            case XR_FOVEATION_DYNAMIC_CLEAR_FOV_ENABLED_BIT_HTC:
                return std::string("XR_FOVEATION_DYNAMIC_CLEAR_FOV_ENABLED_BIT_HTC");
            case XR_FOVEATION_DYNAMIC_FOCAL_CENTER_OFFSET_ENABLED_BIT_HTC:
                return std::string("XR_FOVEATION_DYNAMIC_FOCAL_CENTER_OFFSET_ENABLED_BIT_HTC");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrFoveationEyeTrackedProfileCreateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(XrFoveationEyeTrackedStateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_FOVEATION_EYE_TRACKED_STATE_VALID_BIT_META:
                return std::string("XR_FOVEATION_EYE_TRACKED_STATE_VALID_BIT_META");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrFrameEndInfoFlagsML_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_FRAME_END_INFO_PROTECTED_BIT_ML:
                return std::string("XR_FRAME_END_INFO_PROTECTED_BIT_ML");
            case XR_FRAME_END_INFO_VIGNETTE_BIT_ML:
                return std::string("XR_FRAME_END_INFO_VIGNETTE_BIT_ML");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrGlobalDimmerFrameEndInfoFlagsML_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_GLOBAL_DIMMER_FRAME_END_INFO_ENABLED_BIT_ML:
                return std::string("XR_GLOBAL_DIMMER_FRAME_END_INFO_ENABLED_BIT_ML");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrHandTrackingAimFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_HAND_TRACKING_AIM_COMPUTED_BIT_FB:
                return std::string("XR_HAND_TRACKING_AIM_COMPUTED_BIT_FB");
            case XR_HAND_TRACKING_AIM_VALID_BIT_FB:
                return std::string("XR_HAND_TRACKING_AIM_VALID_BIT_FB");
            case XR_HAND_TRACKING_AIM_INDEX_PINCHING_BIT_FB:
                return std::string("XR_HAND_TRACKING_AIM_INDEX_PINCHING_BIT_FB");
            case XR_HAND_TRACKING_AIM_MIDDLE_PINCHING_BIT_FB:
                return std::string("XR_HAND_TRACKING_AIM_MIDDLE_PINCHING_BIT_FB");
            case XR_HAND_TRACKING_AIM_RING_PINCHING_BIT_FB:
                return std::string("XR_HAND_TRACKING_AIM_RING_PINCHING_BIT_FB");
            case XR_HAND_TRACKING_AIM_LITTLE_PINCHING_BIT_FB:
                return std::string("XR_HAND_TRACKING_AIM_LITTLE_PINCHING_BIT_FB");
            case XR_HAND_TRACKING_AIM_SYSTEM_GESTURE_BIT_FB:
                return std::string("XR_HAND_TRACKING_AIM_SYSTEM_GESTURE_BIT_FB");
            case XR_HAND_TRACKING_AIM_DOMINANT_HAND_BIT_FB:
                return std::string("XR_HAND_TRACKING_AIM_DOMINANT_HAND_BIT_FB");
            case XR_HAND_TRACKING_AIM_MENU_PRESSED_BIT_FB:
                return std::string("XR_HAND_TRACKING_AIM_MENU_PRESSED_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrInputSourceLocalizedNameFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_INPUT_SOURCE_LOCALIZED_NAME_USER_PATH_BIT:
                return std::string("XR_INPUT_SOURCE_LOCALIZED_NAME_USER_PATH_BIT");
            case XR_INPUT_SOURCE_LOCALIZED_NAME_INTERACTION_PROFILE_BIT:
                return std::string("XR_INPUT_SOURCE_LOCALIZED_NAME_INTERACTION_PROFILE_BIT");
            case XR_INPUT_SOURCE_LOCALIZED_NAME_COMPONENT_BIT:
                return std::string("XR_INPUT_SOURCE_LOCALIZED_NAME_COMPONENT_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrInstanceCreateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(XrKeyboardTrackingFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_KEYBOARD_TRACKING_EXISTS_BIT_FB:
                return std::string("XR_KEYBOARD_TRACKING_EXISTS_BIT_FB");
            case XR_KEYBOARD_TRACKING_LOCAL_BIT_FB:
                return std::string("XR_KEYBOARD_TRACKING_LOCAL_BIT_FB");
            case XR_KEYBOARD_TRACKING_REMOTE_BIT_FB:
                return std::string("XR_KEYBOARD_TRACKING_REMOTE_BIT_FB");
            case XR_KEYBOARD_TRACKING_CONNECTED_BIT_FB:
                return std::string("XR_KEYBOARD_TRACKING_CONNECTED_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrKeyboardTrackingQueryFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_KEYBOARD_TRACKING_QUERY_LOCAL_BIT_FB:
                return std::string("XR_KEYBOARD_TRACKING_QUERY_LOCAL_BIT_FB");
            case XR_KEYBOARD_TRACKING_QUERY_REMOTE_BIT_FB:
                return std::string("XR_KEYBOARD_TRACKING_QUERY_REMOTE_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrLocalizationMapErrorFlagsML_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_LOCALIZATION_MAP_ERROR_UNKNOWN_BIT_ML:
                return std::string("XR_LOCALIZATION_MAP_ERROR_UNKNOWN_BIT_ML");
            case XR_LOCALIZATION_MAP_ERROR_OUT_OF_MAPPED_AREA_BIT_ML:
                return std::string("XR_LOCALIZATION_MAP_ERROR_OUT_OF_MAPPED_AREA_BIT_ML");
            case XR_LOCALIZATION_MAP_ERROR_LOW_FEATURE_COUNT_BIT_ML:
                return std::string("XR_LOCALIZATION_MAP_ERROR_LOW_FEATURE_COUNT_BIT_ML");
            case XR_LOCALIZATION_MAP_ERROR_EXCESSIVE_MOTION_BIT_ML:
                return std::string("XR_LOCALIZATION_MAP_ERROR_EXCESSIVE_MOTION_BIT_ML");
            case XR_LOCALIZATION_MAP_ERROR_LOW_LIGHT_BIT_ML:
                return std::string("XR_LOCALIZATION_MAP_ERROR_LOW_LIGHT_BIT_ML");
            case XR_LOCALIZATION_MAP_ERROR_HEADPOSE_BIT_ML:
                return std::string("XR_LOCALIZATION_MAP_ERROR_HEADPOSE_BIT_ML");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrOverlayMainSessionFlagsEXTX_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_OVERLAY_MAIN_SESSION_ENABLED_COMPOSITION_LAYER_INFO_DEPTH_BIT_EXTX:
                return std::string("XR_OVERLAY_MAIN_SESSION_ENABLED_COMPOSITION_LAYER_INFO_DEPTH_BIT_EXTX");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrOverlaySessionCreateFlagsEXTX_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(XrPassthroughCapabilityFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_PASSTHROUGH_CAPABILITY_BIT_FB:
                return std::string("XR_PASSTHROUGH_CAPABILITY_BIT_FB");
            case XR_PASSTHROUGH_CAPABILITY_COLOR_BIT_FB:
                return std::string("XR_PASSTHROUGH_CAPABILITY_COLOR_BIT_FB");
            case XR_PASSTHROUGH_CAPABILITY_LAYER_DEPTH_BIT_FB:
                return std::string("XR_PASSTHROUGH_CAPABILITY_LAYER_DEPTH_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrPassthroughFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_PASSTHROUGH_IS_RUNNING_AT_CREATION_BIT_FB:
                return std::string("XR_PASSTHROUGH_IS_RUNNING_AT_CREATION_BIT_FB");
            case XR_PASSTHROUGH_LAYER_DEPTH_BIT_FB:
                return std::string("XR_PASSTHROUGH_LAYER_DEPTH_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrPassthroughPreferenceFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_PASSTHROUGH_PREFERENCE_DEFAULT_TO_ACTIVE_BIT_META:
                return std::string("XR_PASSTHROUGH_PREFERENCE_DEFAULT_TO_ACTIVE_BIT_META");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrPassthroughStateChangedFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_PASSTHROUGH_STATE_CHANGED_REINIT_REQUIRED_BIT_FB:
                return std::string("XR_PASSTHROUGH_STATE_CHANGED_REINIT_REQUIRED_BIT_FB");
            case XR_PASSTHROUGH_STATE_CHANGED_NON_RECOVERABLE_ERROR_BIT_FB:
                return std::string("XR_PASSTHROUGH_STATE_CHANGED_NON_RECOVERABLE_ERROR_BIT_FB");
            case XR_PASSTHROUGH_STATE_CHANGED_RECOVERABLE_ERROR_BIT_FB:
                return std::string("XR_PASSTHROUGH_STATE_CHANGED_RECOVERABLE_ERROR_BIT_FB");
            case XR_PASSTHROUGH_STATE_CHANGED_RESTORED_ERROR_BIT_FB:
                return std::string("XR_PASSTHROUGH_STATE_CHANGED_RESTORED_ERROR_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrPerformanceMetricsCounterFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_PERFORMANCE_METRICS_COUNTER_ANY_VALUE_VALID_BIT_META:
                return std::string("XR_PERFORMANCE_METRICS_COUNTER_ANY_VALUE_VALID_BIT_META");
            case XR_PERFORMANCE_METRICS_COUNTER_UINT_VALUE_VALID_BIT_META:
                return std::string("XR_PERFORMANCE_METRICS_COUNTER_UINT_VALUE_VALID_BIT_META");
            case XR_PERFORMANCE_METRICS_COUNTER_FLOAT_VALUE_VALID_BIT_META:
                return std::string("XR_PERFORMANCE_METRICS_COUNTER_FLOAT_VALUE_VALID_BIT_META");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrPlaneDetectionCapabilityFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_PLANE_DETECTION_CAPABILITY_PLANE_DETECTION_BIT_EXT:
                return std::string("XR_PLANE_DETECTION_CAPABILITY_PLANE_DETECTION_BIT_EXT");
            case XR_PLANE_DETECTION_CAPABILITY_PLANE_HOLES_BIT_EXT:
                return std::string("XR_PLANE_DETECTION_CAPABILITY_PLANE_HOLES_BIT_EXT");
            case XR_PLANE_DETECTION_CAPABILITY_SEMANTIC_CEILING_BIT_EXT:
                return std::string("XR_PLANE_DETECTION_CAPABILITY_SEMANTIC_CEILING_BIT_EXT");
            case XR_PLANE_DETECTION_CAPABILITY_SEMANTIC_FLOOR_BIT_EXT:
                return std::string("XR_PLANE_DETECTION_CAPABILITY_SEMANTIC_FLOOR_BIT_EXT");
            case XR_PLANE_DETECTION_CAPABILITY_SEMANTIC_WALL_BIT_EXT:
                return std::string("XR_PLANE_DETECTION_CAPABILITY_SEMANTIC_WALL_BIT_EXT");
            case XR_PLANE_DETECTION_CAPABILITY_SEMANTIC_PLATFORM_BIT_EXT:
                return std::string("XR_PLANE_DETECTION_CAPABILITY_SEMANTIC_PLATFORM_BIT_EXT");
            case XR_PLANE_DETECTION_CAPABILITY_ORIENTATION_BIT_EXT:
                return std::string("XR_PLANE_DETECTION_CAPABILITY_ORIENTATION_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrPlaneDetectorFlagsEXT_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_PLANE_DETECTOR_ENABLE_CONTOUR_BIT_EXT:
                return std::string("XR_PLANE_DETECTOR_ENABLE_CONTOUR_BIT_EXT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrRenderModelFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_RENDER_MODEL_SUPPORTS_GLTF_2_0_SUBSET_1_BIT_FB:
                return std::string("XR_RENDER_MODEL_SUPPORTS_GLTF_2_0_SUBSET_1_BIT_FB");
            case XR_RENDER_MODEL_SUPPORTS_GLTF_2_0_SUBSET_2_BIT_FB:
                return std::string("XR_RENDER_MODEL_SUPPORTS_GLTF_2_0_SUBSET_2_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrSemanticLabelsSupportFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_SEMANTIC_LABELS_SUPPORT_MULTIPLE_SEMANTIC_LABELS_BIT_FB:
                return std::string("XR_SEMANTIC_LABELS_SUPPORT_MULTIPLE_SEMANTIC_LABELS_BIT_FB");
            case XR_SEMANTIC_LABELS_SUPPORT_ACCEPT_DESK_TO_TABLE_MIGRATION_BIT_FB:
                return std::string("XR_SEMANTIC_LABELS_SUPPORT_ACCEPT_DESK_TO_TABLE_MIGRATION_BIT_FB");
            case XR_SEMANTIC_LABELS_SUPPORT_ACCEPT_INVISIBLE_WALL_FACE_BIT_FB:
                return std::string("XR_SEMANTIC_LABELS_SUPPORT_ACCEPT_INVISIBLE_WALL_FACE_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrSessionCreateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(XrSpaceLocationFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_SPACE_LOCATION_ORIENTATION_VALID_BIT:
                return std::string("XR_SPACE_LOCATION_ORIENTATION_VALID_BIT");
            case XR_SPACE_LOCATION_POSITION_VALID_BIT:
                return std::string("XR_SPACE_LOCATION_POSITION_VALID_BIT");
            case XR_SPACE_LOCATION_ORIENTATION_TRACKED_BIT:
                return std::string("XR_SPACE_LOCATION_ORIENTATION_TRACKED_BIT");
            case XR_SPACE_LOCATION_POSITION_TRACKED_BIT:
                return std::string("XR_SPACE_LOCATION_POSITION_TRACKED_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrSpaceVelocityFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_SPACE_VELOCITY_LINEAR_VALID_BIT:
                return std::string("XR_SPACE_VELOCITY_LINEAR_VALID_BIT");
            case XR_SPACE_VELOCITY_ANGULAR_VALID_BIT:
                return std::string("XR_SPACE_VELOCITY_ANGULAR_VALID_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrSwapchainCreateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_SWAPCHAIN_CREATE_PROTECTED_CONTENT_BIT:
                return std::string("XR_SWAPCHAIN_CREATE_PROTECTED_CONTENT_BIT");
            case XR_SWAPCHAIN_CREATE_STATIC_IMAGE_BIT:
                return std::string("XR_SWAPCHAIN_CREATE_STATIC_IMAGE_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrSwapchainCreateFoveationFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_SWAPCHAIN_CREATE_FOVEATION_SCALED_BIN_BIT_FB:
                return std::string("XR_SWAPCHAIN_CREATE_FOVEATION_SCALED_BIN_BIT_FB");
            case XR_SWAPCHAIN_CREATE_FOVEATION_FRAGMENT_DENSITY_MAP_BIT_FB:
                return std::string("XR_SWAPCHAIN_CREATE_FOVEATION_FRAGMENT_DENSITY_MAP_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrSwapchainStateFoveationFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(XrSwapchainUsageFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_SWAPCHAIN_USAGE_COLOR_ATTACHMENT_BIT:
                return std::string("XR_SWAPCHAIN_USAGE_COLOR_ATTACHMENT_BIT");
            case XR_SWAPCHAIN_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT:
                return std::string("XR_SWAPCHAIN_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT");
            case XR_SWAPCHAIN_USAGE_UNORDERED_ACCESS_BIT:
                return std::string("XR_SWAPCHAIN_USAGE_UNORDERED_ACCESS_BIT");
            case XR_SWAPCHAIN_USAGE_TRANSFER_SRC_BIT:
                return std::string("XR_SWAPCHAIN_USAGE_TRANSFER_SRC_BIT");
            case XR_SWAPCHAIN_USAGE_TRANSFER_DST_BIT:
                return std::string("XR_SWAPCHAIN_USAGE_TRANSFER_DST_BIT");
            case XR_SWAPCHAIN_USAGE_SAMPLED_BIT:
                return std::string("XR_SWAPCHAIN_USAGE_SAMPLED_BIT");
            case XR_SWAPCHAIN_USAGE_MUTABLE_FORMAT_BIT:
                return std::string("XR_SWAPCHAIN_USAGE_MUTABLE_FORMAT_BIT");
            case XR_SWAPCHAIN_USAGE_INPUT_ATTACHMENT_BIT_MND:
                return std::string("XR_SWAPCHAIN_USAGE_INPUT_ATTACHMENT_BIT_MND");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrTriangleMeshFlagsFB_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_TRIANGLE_MESH_MUTABLE_BIT_FB:
                return std::string("XR_TRIANGLE_MESH_MUTABLE_BIT_FB");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrViewStateFlags_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_VIEW_STATE_ORIENTATION_VALID_BIT:
                return std::string("XR_VIEW_STATE_ORIENTATION_VALID_BIT");
            case XR_VIEW_STATE_POSITION_VALID_BIT:
                return std::string("XR_VIEW_STATE_POSITION_VALID_BIT");
            case XR_VIEW_STATE_ORIENTATION_TRACKED_BIT:
                return std::string("XR_VIEW_STATE_ORIENTATION_TRACKED_BIT");
            case XR_VIEW_STATE_POSITION_TRACKED_BIT:
                return std::string("XR_VIEW_STATE_POSITION_TRACKED_BIT");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrVirtualKeyboardInputStateFlagsMETA_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    if (!options.expand_flags)
    {
        jdata = to_hex_fixed_width(flags);
        return;
    }
    jdata = ExpandFlags(flags, [](XrFlags64 flags)
    {
        switch (flags)
        {
            case XR_VIRTUAL_KEYBOARD_INPUT_STATE_PRESSED_BIT_META:
                return std::string("XR_VIRTUAL_KEYBOARD_INPUT_STATE_PRESSED_BIT_META");
        }
        return to_hex_fixed_width(flags);
    });
}

void FieldToJson(XrVulkanDeviceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

void FieldToJson(XrVulkanInstanceCreateFlagsKHR_t, nlohmann::ordered_json& jdata, const XrFlags64 flags, const JsonOptions& options)
{
    jdata = to_hex_fixed_width(flags);
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT
