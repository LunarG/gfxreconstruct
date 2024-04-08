///////////////////////////////////////////////////////////////////////////////
// Copyright(c) 2019 Advanced Micro Devices, Inc.All rights reserved
// Copyright(c) 2022 LunarG, Inc.
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
/// \file
/// \author AMD Developer Tools Team
/// \author LunarG GfxReconstruct Team
/// \description VkLayer_gfxreconstruct test main entry point
///////////////////////////////////////////////////////////////////////////////

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
// Pull in the layer code so we can call static functions in there:
#include "../trace_layer.cpp"

namespace
{
bool operator==(const VkExtensionProperties& l, const VkExtensionProperties& r)
{
    return l.specVersion == r.specVersion &&
           (strncmp(l.extensionName, r.extensionName, VK_MAX_EXTENSION_NAME_SIZE) == 0);
}

auto VkExtensionPropertiesCmp = [](const VkExtensionProperties& l, const VkExtensionProperties& r) {
    return strncmp(l.extensionName, r.extensionName, VK_MAX_EXTENSION_NAME_SIZE) < 0;
};

auto CstrCmp = [](const char* const l, const char* const r) { return strncmp(l, r, VK_MAX_EXTENSION_NAME_SIZE) < 0; };

void trash_randomize(std::vector<VkExtensionProperties>& extensions)
{
    for (auto it = std::begin(extensions), end = std::end(extensions); it != end; ++it)
    {
        auto r = std::begin(extensions) + rand() * (extensions.size() - 1) / RAND_MAX;
        std::swap(*it, *r);
    }
}

const char* const kExampleDeviceExtensions[] = {
    "VK_EXT_4444_formats",
    "VK_EXT_blend_operation_advanced",
    "VK_EXT_border_color_swizzle",
    "VK_EXT_buffer_device_address",
    "VK_EXT_calibrated_timestamps",
    "VK_EXT_color_write_enable",
    "VK_EXT_conditional_rendering",
    "VK_EXT_conservative_rasterization",
    "VK_EXT_custom_border_color",
    "VK_EXT_depth_clip_control",
    "VK_EXT_depth_clip_enable",
    "VK_EXT_depth_range_unrestricted",
    "VK_EXT_descriptor_indexing",
    "VK_EXT_discard_rectangles",
    "VK_EXT_display_control",
    "VK_EXT_extended_dynamic_state",
    "VK_EXT_extended_dynamic_state2",
    "VK_EXT_external_memory_dma_buf",
    "VK_EXT_external_memory_host",
    "VK_EXT_fragment_shader_interlock",
    "VK_EXT_global_priority",
    "VK_EXT_global_priority_query",
    "VK_EXT_graphics_pipeline_library",
    "VK_EXT_host_query_reset",
    "VK_EXT_image_2d_view_of_3d",
    "VK_EXT_image_drm_format_modifier",
    "VK_EXT_image_robustness",
    "VK_EXT_image_view_min_lod",
    "VK_EXT_index_type_uint8",
    "VK_EXT_inline_uniform_block",
    "VK_EXT_line_rasterization",
    "VK_EXT_load_store_op_none",
    "VK_EXT_memory_budget",
    "VK_EXT_multi_draw",
    "VK_EXT_non_seamless_cube_map",
    "VK_EXT_pci_bus_info",
    "VK_EXT_physical_device_drm",
    "VK_EXT_pipeline_creation_cache_control",
    "VK_EXT_pipeline_creation_feedback",
    "VK_EXT_post_depth_coverage",
    "VK_EXT_primitive_topology_list_restart",
    "VK_EXT_primitives_generated_query",
    "VK_EXT_private_data",
    "VK_EXT_provoking_vertex",
    "VK_EXT_queue_family_foreign",
    "VK_EXT_robustness2",
    "VK_EXT_sample_locations",
    "VK_EXT_sampler_filter_minmax",
    "VK_EXT_scalar_block_layout",
    "VK_EXT_separate_stencil_usage",
    "VK_EXT_shader_atomic_float",
    "VK_EXT_shader_demote_to_helper_invocation",
    "VK_EXT_shader_image_atomic_int64",
    "VK_EXT_shader_subgroup_ballot",
    "VK_EXT_shader_subgroup_vote",
    "VK_EXT_shader_viewport_index_layer",
    "VK_EXT_subgroup_size_control",
    "VK_EXT_texel_buffer_alignment",
    "VK_EXT_tooling_info",
    "VK_EXT_transform_feedback",
    "VK_EXT_vertex_attribute_divisor",
    "VK_EXT_vertex_input_dynamic_state",
    "VK_EXT_video_decode_h264",
    "VK_EXT_video_decode_h265",
    "VK_EXT_video_encode_h264",
    "VK_EXT_ycbcr_2plane_444_formats",
    "VK_EXT_ycbcr_image_arrays",
    "VK_KHR_16bit_storage",
    "VK_KHR_8bit_storage",
    "VK_KHR_acceleration_structure",
    "VK_KHR_bind_memory2",
    "VK_KHR_buffer_device_address",
    "VK_KHR_copy_commands2",
    "VK_KHR_create_renderpass2",
    "VK_KHR_dedicated_allocation",
    "VK_KHR_deferred_host_operations",
    "VK_KHR_depth_stencil_resolve",
    "VK_KHR_descriptor_update_template",
    "VK_KHR_device_group",
    "VK_KHR_draw_indirect_count",
    "VK_KHR_driver_properties",
    "VK_KHR_dynamic_rendering",
    "VK_KHR_external_fence",
    "VK_KHR_external_fence_fd",
    "VK_KHR_external_memory",
    "VK_KHR_external_memory_fd",
    "VK_KHR_external_semaphore",
    "VK_KHR_external_semaphore_fd",
    "VK_KHR_format_feature_flags2",
    "VK_KHR_fragment_shader_barycentric",
    "VK_KHR_fragment_shading_rate",
    "VK_KHR_get_memory_requirements2",
    "VK_KHR_global_priority",
    "VK_KHR_image_format_list",
    "VK_KHR_imageless_framebuffer",
    "VK_KHR_maintenance1",
    "VK_KHR_maintenance2",
    "VK_KHR_maintenance3",
    "VK_KHR_maintenance4",
    "VK_KHR_multiview",
    "VK_KHR_pipeline_executable_properties",
    "VK_KHR_pipeline_library",
    "VK_KHR_present_id",
    "VK_KHR_present_wait",
    "VK_KHR_push_descriptor",
    "VK_KHR_ray_query",
    "VK_KHR_ray_tracing_maintenance1",
    "VK_KHR_ray_tracing_pipeline",
    "VK_KHR_relaxed_block_layout",
    "VK_KHR_sampler_mirror_clamp_to_edge",
    "VK_KHR_sampler_ycbcr_conversion",
    "VK_KHR_separate_depth_stencil_layouts",
    "VK_KHR_shader_atomic_int64",
    "VK_KHR_shader_clock",
    "VK_KHR_shader_draw_parameters",
    "VK_KHR_shader_float16_int8",
    "VK_KHR_shader_float_controls",
    "VK_KHR_shader_integer_dot_product",
    "VK_KHR_shader_non_semantic_info",
    "VK_KHR_shader_subgroup_extended_types",
    "VK_KHR_shader_subgroup_uniform_control_flow",
    "VK_KHR_shader_terminate_invocation",
    "VK_KHR_spirv_1_4",
    "VK_KHR_storage_buffer_storage_class",
    "VK_KHR_swapchain",
    "VK_KHR_swapchain_mutable_format",
    "VK_KHR_synchronization2",
    "VK_KHR_timeline_semaphore",
    "VK_KHR_uniform_buffer_standard_layout",
    "VK_KHR_variable_pointers",
    "VK_KHR_video_decode_queue",
    "VK_KHR_video_encode_queue",
    "VK_KHR_video_queue",
    "VK_KHR_vulkan_memory_model",
    "VK_KHR_workgroup_memory_explicit_layout",
    "VK_KHR_zero_initialize_workgroup_memory",
    "VK_NVX_binary_import",
    "VK_NVX_image_view_handle",
    "VK_NVX_multiview_per_view_attributes",
    "VK_NV_clip_space_w_scaling",
    "VK_NV_compute_shader_derivatives",
    "VK_NV_cooperative_matrix",
    "VK_NV_corner_sampled_image",
    "VK_NV_coverage_reduction_mode",
    "VK_NV_cuda_kernel_launch",
    "VK_NV_dedicated_allocation",
    "VK_NV_dedicated_allocation_image_aliasing",
    "VK_NV_device_diagnostic_checkpoints",
    "VK_NV_device_diagnostics_config",
    "VK_NV_device_generated_commands",
    "VK_NV_fill_rectangle",
    "VK_NV_fragment_coverage_to_color",
    "VK_NV_fragment_shader_barycentric",
    "VK_NV_fragment_shading_rate_enums",
    "VK_NV_framebuffer_mixed_samples",
    "VK_NV_geometry_shader_passthrough",
    "VK_NV_inherited_viewport_scissor",
    "VK_NV_linear_color_attachment",
    "VK_NV_mesh_shader",
    "VK_NV_ray_tracing",
    "VK_NV_representative_fragment_test",
    "VK_NV_sample_mask_override_coverage",
    "VK_NV_scissor_exclusive",
    "VK_NV_shader_image_footprint",
    "VK_NV_shader_sm_builtins",
    "VK_NV_shader_subgroup_partitioned",
    "VK_NV_shading_rate_image",
    "VK_NV_viewport_array2",
    "VK_NV_viewport_swizzle",
};

// Extension strings use lower-case for the <name> portion, so these should not match.
const char* const kExampleDeviceExtensionsUpper[]{
    "VK_EXT_4444_FORMATS",
    "VK_EXT_BLEND_OPERATION_ADVANCED",
    "VK_EXT_BORDER_COLOR_SWIZZLE",
    "VK_EXT_BUFFER_DEVICE_ADDRESS",
    "VK_EXT_CALIBRATED_TIMESTAMPS",
    "VK_EXT_COLOR_WRITE_ENABLE",
    "VK_EXT_CONDITIONAL_RENDERING",
    "VK_EXT_CONSERVATIVE_RASTERIZATION",
    "VK_EXT_CUSTOM_BORDER_COLOR",
    "VK_EXT_DEPTH_CLIP_CONTROL",
    "VK_EXT_DEPTH_CLIP_ENABLE",
    "VK_EXT_DEPTH_RANGE_UNRESTRICTED",
    "VK_EXT_DESCRIPTOR_INDEXING",
    "VK_EXT_DISCARD_RECTANGLES",
    "VK_EXT_DISPLAY_CONTROL",
    "VK_EXT_EXTENDED_DYNAMIC_STATE",
    "VK_EXT_EXTENDED_DYNAMIC_STATE2",
    "VK_EXT_EXTERNAL_MEMORY_DMA_BUF",
    "VK_EXT_EXTERNAL_MEMORY_HOST",
    "VK_EXT_FRAGMENT_SHADER_INTERLOCK",
    "VK_EXT_GLOBAL_PRIORITY",
    "VK_EXT_GLOBAL_PRIORITY_QUERY",
    "VK_EXT_GRAPHICS_PIPELINE_LIBRARY",
    "VK_EXT_HOST_QUERY_RESET",
    "VK_EXT_IMAGE_2D_VIEW_OF_3D",
    "VK_EXT_IMAGE_DRM_FORMAT_MODIFIER",
    "VK_EXT_IMAGE_ROBUSTNESS",
    "VK_EXT_IMAGE_VIEW_MIN_LOD",
    "VK_EXT_INDEX_TYPE_UINT8",
    "VK_EXT_INLINE_UNIFORM_BLOCK",
    "VK_EXT_LINE_RASTERIZATION",
    "VK_EXT_LOAD_STORE_OP_NONE",
    "VK_EXT_MEMORY_BUDGET",
    "VK_EXT_MULTI_DRAW",
    "VK_EXT_NON_SEAMLESS_CUBE_MAP",
    "VK_EXT_PCI_BUS_INFO",
    "VK_EXT_PHYSICAL_DEVICE_DRM",
    "VK_EXT_PIPELINE_CREATION_CACHE_CONTROL",
    "VK_EXT_PIPELINE_CREATION_FEEDBACK",
    "VK_EXT_POST_DEPTH_COVERAGE",
    "VK_EXT_PRIMITIVE_TOPOLOGY_LIST_RESTART",
    "VK_EXT_PRIMITIVES_GENERATED_QUERY",
    "VK_EXT_PRIVATE_DATA",
    "VK_EXT_PROVOKING_VERTEX",
    "VK_EXT_QUEUE_FAMILY_FOREIGN",
    "VK_EXT_ROBUSTNESS2",
    "VK_EXT_SAMPLE_LOCATIONS",
    "VK_EXT_SAMPLER_FILTER_MINMAX",
    "VK_EXT_SCALAR_BLOCK_LAYOUT",
    "VK_EXT_SEPARATE_STENCIL_USAGE",
    "VK_EXT_SHADER_ATOMIC_FLOAT",
    "VK_EXT_SHADER_DEMOTE_TO_HELPER_INVOCATION",
    "VK_EXT_SHADER_IMAGE_ATOMIC_INT64",
    "VK_EXT_SHADER_SUBGROUP_BALLOT",
    "VK_EXT_SHADER_SUBGROUP_VOTE",
    "VK_EXT_SHADER_VIEWPORT_INDEX_LAYER",
    "VK_EXT_SUBGROUP_SIZE_CONTROL",
    "VK_EXT_TEXEL_BUFFER_ALIGNMENT",
    "VK_EXT_TOOLING_INFO",
    "VK_EXT_TRANSFORM_FEEDBACK",
    "VK_EXT_VERTEX_ATTRIBUTE_DIVISOR",
    "VK_EXT_VERTEX_INPUT_DYNAMIC_STATE",
    "VK_EXT_VIDEO_DECODE_H264",
    "VK_EXT_VIDEO_DECODE_H265",
    "VK_EXT_VIDEO_ENCODE_H264",
    "VK_EXT_YCBCR_2PLANE_444_FORMATS",
    "VK_EXT_YCBCR_IMAGE_ARRAYS",
    "VK_KHR_16BIT_STORAGE",
    "VK_KHR_8BIT_STORAGE",
    "VK_KHR_ACCELERATION_STRUCTURE",
    "VK_KHR_BIND_MEMORY2",
    "VK_KHR_BUFFER_DEVICE_ADDRESS",
    "VK_KHR_COPY_COMMANDS2",
    "VK_KHR_CREATE_RENDERPASS2",
    "VK_KHR_DEDICATED_ALLOCATION",
    "VK_KHR_DEFERRED_HOST_OPERATIONS",
    "VK_KHR_DEPTH_STENCIL_RESOLVE",
    "VK_KHR_DESCRIPTOR_UPDATE_TEMPLATE",
    "VK_KHR_DEVICE_GROUP",
    "VK_KHR_DRAW_INDIRECT_COUNT",
    "VK_KHR_DRIVER_PROPERTIES",
    "VK_KHR_DYNAMIC_RENDERING",
    "VK_KHR_EXTERNAL_FENCE",
    "VK_KHR_EXTERNAL_FENCE_FD",
    "VK_KHR_EXTERNAL_MEMORY",
    "VK_KHR_EXTERNAL_MEMORY_FD",
    "VK_KHR_EXTERNAL_SEMAPHORE",
    "VK_KHR_EXTERNAL_SEMAPHORE_FD",
    "VK_KHR_FORMAT_FEATURE_FLAGS2",
    "VK_KHR_FRAGMENT_SHADER_BARYCENTRIC",
    "VK_KHR_FRAGMENT_SHADING_RATE",
    "VK_KHR_GET_MEMORY_REQUIREMENTS2",
    "VK_KHR_GLOBAL_PRIORITY",
    "VK_KHR_IMAGE_FORMAT_LIST",
    "VK_KHR_IMAGELESS_FRAMEBUFFER",
    "VK_KHR_MAINTENANCE1",
    "VK_KHR_MAINTENANCE2",
    "VK_KHR_MAINTENANCE3",
    "VK_KHR_MAINTENANCE4",
    "VK_KHR_MULTIVIEW",
    "VK_KHR_PIPELINE_EXECUTABLE_PROPERTIES",
    "VK_KHR_PIPELINE_LIBRARY",
    "VK_KHR_PRESENT_ID",
    "VK_KHR_PRESENT_WAIT",
    "VK_KHR_PUSH_DESCRIPTOR",
    "VK_KHR_RAY_QUERY",
    "VK_KHR_RAY_TRACING_MAINTENANCE1",
    "VK_KHR_RAY_TRACING_PIPELINE",
    "VK_KHR_RELAXED_BLOCK_LAYOUT",
    "VK_KHR_SAMPLER_MIRROR_CLAMP_TO_EDGE",
    "VK_KHR_SAMPLER_YCBCR_CONVERSION",
    "VK_KHR_SEPARATE_DEPTH_STENCIL_LAYOUTS",
    "VK_KHR_SHADER_ATOMIC_INT64",
    "VK_KHR_SHADER_CLOCK",
    "VK_KHR_SHADER_DRAW_PARAMETERS",
    "VK_KHR_SHADER_FLOAT16_INT8",
    "VK_KHR_SHADER_FLOAT_CONTROLS",
    "VK_KHR_SHADER_INTEGER_DOT_PRODUCT",
    "VK_KHR_SHADER_NON_SEMANTIC_INFO",
    "VK_KHR_SHADER_SUBGROUP_EXTENDED_TYPES",
    "VK_KHR_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW",
    "VK_KHR_SHADER_TERMINATE_INVOCATION",
    "VK_KHR_SPIRV_1_4",
    "VK_KHR_STORAGE_BUFFER_STORAGE_CLASS",
    "VK_KHR_SWAPCHAIN",
    "VK_KHR_SWAPCHAIN_MUTABLE_FORMAT",
    "VK_KHR_SYNCHRONIZATION2",
    "VK_KHR_TIMELINE_SEMAPHORE",
    "VK_KHR_UNIFORM_BUFFER_STANDARD_LAYOUT",
    "VK_KHR_VARIABLE_POINTERS",
    "VK_KHR_VIDEO_DECODE_QUEUE",
    "VK_KHR_VIDEO_ENCODE_QUEUE",
    "VK_KHR_VIDEO_QUEUE",
    "VK_KHR_VULKAN_MEMORY_MODEL",
    "VK_KHR_WORKGROUP_MEMORY_EXPLICIT_LAYOUT",
    "VK_KHR_ZERO_INITIALIZE_WORKGROUP_MEMORY",
    "VK_NVX_BINARY_IMPORT",
    "VK_NVX_IMAGE_VIEW_HANDLE",
    "VK_NVX_MULTIVIEW_PER_VIEW_ATTRIBUTES",
    "VK_NV_CLIP_SPACE_W_SCALING",
    "VK_NV_COMPUTE_SHADER_DERIVATIVES",
    "VK_NV_COOPERATIVE_MATRIX",
    "VK_NV_CORNER_SAMPLED_IMAGE",
    "VK_NV_COVERAGE_REDUCTION_MODE",
    "VK_NV_CUDA_KERNEL_LAUNCH",
    "VK_NV_DEDICATED_ALLOCATION",
    "VK_NV_DEDICATED_ALLOCATION_IMAGE_ALIASING",
    "VK_NV_DEVICE_DIAGNOSTIC_CHECKPOINTS",
    "VK_NV_DEVICE_DIAGNOSTICS_CONFIG",
    "VK_NV_DEVICE_GENERATED_COMMANDS",
    "VK_NV_FILL_RECTANGLE",
    "VK_NV_FRAGMENT_COVERAGE_TO_COLOR",
    "VK_NV_FRAGMENT_SHADER_BARYCENTRIC",
    "VK_NV_FRAGMENT_SHADING_RATE_ENUMS",
    "VK_NV_FRAMEBUFFER_MIXED_SAMPLES",
    "VK_NV_GEOMETRY_SHADER_PASSTHROUGH",
    "VK_NV_INHERITED_VIEWPORT_SCISSOR",
    "VK_NV_LINEAR_COLOR_ATTACHMENT",
    "VK_NV_MESH_SHADER",
    "VK_NV_RAY_TRACING",
    "VK_NV_REPRESENTATIVE_FRAGMENT_TEST",
    "VK_NV_SAMPLE_MASK_OVERRIDE_COVERAGE",
    "VK_NV_SCISSOR_EXCLUSIVE",
    "VK_NV_SHADER_IMAGE_FOOTPRINT",
    "VK_NV_SHADER_SM_BUILTINS",
    "VK_NV_SHADER_SUBGROUP_PARTITIONED",
    "VK_NV_SHADING_RATE_IMAGE",
    "VK_NV_VIEWPORT_ARRAY2",
    "VK_NV_VIEWPORT_SWIZZLE",
};
} // namespace

TEST_CASE("Unsupported extension screening", "[layer]")
{
    gfxrecon::util::Log::Init(gfxrecon::util::Log::kErrorSeverity);

    VkExtensionProperties ext_arr[] = {
        { "VK_EXT_4444_formats", 1 },
        { "VK_EXT_blend_operation_advanced", 2 },
        { "VK_EXT_border_color_swizzle", 1 },
        { "VK_EXT_buffer_device_address", 2 },
        { "VK_EXT_calibrated_timestamps", 2 },
        { "VK_EXT_color_write_enable", 1 },
        { "VK_EXT_conditional_rendering", 2 },
        { "VK_EXT_conservative_rasterization", 1 },
        { "VK_EXT_custom_border_color", 12 },
        { "VK_EXT_depth_clip_control", 1 },
        { "VK_EXT_depth_clip_enable", 1 },
        { "VK_EXT_depth_range_unrestricted", 1 },
        { "VK_EXT_descriptor_indexing", 2 },
        { "VK_EXT_discard_rectangles", 1 },
        { "VK_EXT_display_control", 1 },
        { "VK_EXT_extended_dynamic_state", 1 },
        { "VK_EXT_extended_dynamic_state2", 1 },
        { "VK_EXT_external_memory_dma_buf", 1 },
        { "VK_EXT_external_memory_host", 1 },
        { "VK_EXT_fragment_shader_interlock", 1 },
        { "VK_EXT_global_priority", 2 },
        { "VK_EXT_global_priority_query", 1 },
        { "VK_EXT_graphics_pipeline_library", 1 },
        { "VK_EXT_host_query_reset", 1 },
        { "VK_EXT_image_2d_view_of_3d", 1 },
        { "VK_EXT_image_drm_format_modifier", 2 },
        { "VK_EXT_image_robustness", 1 },
        { "VK_EXT_image_view_min_lod", 1 },
        { "VK_EXT_index_type_uint8", 1 },
        { "VK_EXT_inline_uniform_block", 1 },
        { "VK_EXT_line_rasterization", 1 },
        { "VK_EXT_load_store_op_none", 1 },
        { "VK_EXT_memory_budget", 1 },
        { "VK_EXT_multi_draw", 1 },
        { "VK_EXT_non_seamless_cube_map", 1 },
        { "VK_EXT_pci_bus_info", 2 },
        { "VK_EXT_physical_device_drm", 1 },
        { "VK_EXT_pipeline_creation_cache_control", 3 },
        { "VK_EXT_pipeline_creation_feedback", 1 },
        { "VK_EXT_post_depth_coverage", 1 },
        { "VK_EXT_primitive_topology_list_restart", 1 },
        { "VK_EXT_primitives_generated_query", 1 },
        { "VK_EXT_private_data", 1 },
        { "VK_EXT_provoking_vertex", 1 },
        { "VK_EXT_queue_family_foreign", 1 },
        { "VK_EXT_robustness2", 1 },
        { "VK_EXT_sample_locations", 1 },
        { "VK_EXT_sampler_filter_minmax", 2 },
        { "VK_EXT_scalar_block_layout", 1 },
        { "VK_EXT_separate_stencil_usage", 1 },
        { "VK_EXT_shader_atomic_float", 1 },
        { "VK_EXT_shader_demote_to_helper_invocation", 1 },
        { "VK_EXT_shader_image_atomic_int64", 1 },
        { "VK_EXT_shader_subgroup_ballot", 1 },
        { "VK_EXT_shader_subgroup_vote", 1 },
        { "VK_EXT_shader_viewport_index_layer", 1 },
        { "VK_EXT_subgroup_size_control", 2 },
        { "VK_EXT_texel_buffer_alignment", 1 },
        { "VK_EXT_tooling_info", 1 },
        { "VK_EXT_transform_feedback", 1 },
        { "VK_EXT_vertex_attribute_divisor", 3 },
        { "VK_EXT_vertex_input_dynamic_state", 2 },
        { "VK_EXT_video_decode_h264", 5 },
        { "VK_EXT_video_decode_h265", 3 },
        { "VK_EXT_video_encode_h264", 7 },
        { "VK_EXT_ycbcr_2plane_444_formats", 1 },
        { "VK_EXT_ycbcr_image_arrays", 1 },
        { "VK_KHR_16bit_storage", 1 },
        { "VK_KHR_8bit_storage", 1 },
        { "VK_KHR_acceleration_structure", 13 },
        { "VK_KHR_bind_memory2", 1 },
        { "VK_KHR_buffer_device_address", 1 },
        { "VK_KHR_copy_commands2", 1 },
        { "VK_KHR_create_renderpass2", 1 },
        { "VK_KHR_dedicated_allocation", 3 },
        { "VK_KHR_deferred_host_operations", 4 },
        { "VK_KHR_depth_stencil_resolve", 1 },
        { "VK_KHR_descriptor_update_template", 1 },
        { "VK_KHR_device_group", 4 },
        { "VK_KHR_draw_indirect_count", 1 },
        { "VK_KHR_driver_properties", 1 },
        { "VK_KHR_dynamic_rendering", 1 },
        { "VK_KHR_external_fence", 1 },
        { "VK_KHR_external_fence_fd", 1 },
        { "VK_KHR_external_memory", 1 },
        { "VK_KHR_external_memory_fd", 1 },
        { "VK_KHR_external_semaphore", 1 },
        { "VK_KHR_external_semaphore_fd", 1 },
        { "VK_KHR_format_feature_flags2", 1 },
        { "VK_KHR_fragment_shader_barycentric", 1 },
        { "VK_KHR_fragment_shading_rate", 2 },
        { "VK_KHR_get_memory_requirements2", 1 },
        { "VK_KHR_global_priority", 1 },
        { "VK_KHR_image_format_list", 1 },
        { "VK_KHR_imageless_framebuffer", 1 },
        { "VK_KHR_maintenance1", 2 },
        { "VK_KHR_maintenance2", 1 },
        { "VK_KHR_maintenance3", 1 },
        { "VK_KHR_maintenance4", 2 },
        { "VK_KHR_multiview", 1 },
        { "VK_KHR_pipeline_executable_properties", 1 },
        { "VK_KHR_pipeline_library", 1 },
        { "VK_KHR_present_id", 1 },
        { "VK_KHR_present_wait", 1 },
        { "VK_KHR_push_descriptor", 2 },
        { "VK_KHR_ray_query", 1 },
        { "VK_KHR_ray_tracing_maintenance1", 1 },
        { "VK_KHR_ray_tracing_pipeline", 1 },
        { "VK_KHR_relaxed_block_layout", 1 },
        { "VK_KHR_sampler_mirror_clamp_to_edge", 3 },
        { "VK_KHR_sampler_ycbcr_conversion", 14 },
        { "VK_KHR_separate_depth_stencil_layouts", 1 },
        { "VK_KHR_shader_atomic_int64", 1 },
        { "VK_KHR_shader_clock", 1 },
        { "VK_KHR_shader_draw_parameters", 1 },
        { "VK_KHR_shader_float16_int8", 1 },
        { "VK_KHR_shader_float_controls", 4 },
        { "VK_KHR_shader_integer_dot_product", 1 },
        { "VK_KHR_shader_non_semantic_info", 1 },
        { "VK_KHR_shader_subgroup_extended_types", 1 },
        { "VK_KHR_shader_subgroup_uniform_control_flow", 1 },
        { "VK_KHR_shader_terminate_invocation", 1 },
        { "VK_KHR_spirv_1_4", 1 },
        { "VK_KHR_storage_buffer_storage_class", 1 },
        { "VK_KHR_swapchain", 70 },
        { "VK_KHR_swapchain_mutable_format", 1 },
        { "VK_KHR_synchronization2", 1 },
        { "VK_KHR_timeline_semaphore", 2 },
        { "VK_KHR_uniform_buffer_standard_layout", 1 },
        { "VK_KHR_variable_pointers", 1 },
        { "VK_KHR_video_decode_queue", 4 },
        { "VK_KHR_video_encode_queue", 5 },
        { "VK_KHR_video_queue", 3 },
        { "VK_KHR_vulkan_memory_model", 3 },
        { "VK_KHR_workgroup_memory_explicit_layout", 1 },
        { "VK_KHR_zero_initialize_workgroup_memory", 1 },
        { "VK_NVX_binary_import", 1 },
        { "VK_NVX_image_view_handle", 2 },
        { "VK_NVX_multiview_per_view_attributes", 1 },
        { "VK_NV_clip_space_w_scaling", 1 },
        { "VK_NV_compute_shader_derivatives", 1 },
        { "VK_NV_cooperative_matrix", 1 },
        { "VK_NV_corner_sampled_image", 2 },
        { "VK_NV_coverage_reduction_mode", 1 },
        { "VK_NV_cuda_kernel_launch", 2 },
        { "VK_NV_dedicated_allocation", 1 },
        { "VK_NV_dedicated_allocation_image_aliasing", 1 },
        { "VK_NV_device_diagnostic_checkpoints", 2 },
        { "VK_NV_device_diagnostics_config", 2 },
        { "VK_NV_device_generated_commands", 3 },
        { "VK_NV_fill_rectangle", 1 },
        { "VK_NV_fragment_coverage_to_color", 1 },
        { "VK_NV_fragment_shader_barycentric", 1 },
        { "VK_NV_fragment_shading_rate_enums", 1 },
        { "VK_NV_framebuffer_mixed_samples", 1 },
        { "VK_NV_geometry_shader_passthrough", 1 },
        { "VK_NV_inherited_viewport_scissor", 1 },
        { "VK_NV_linear_color_attachment", 1 },
        { "VK_NV_mesh_shader", 1 },
        { "VK_NV_ray_tracing", 3 },
        { "VK_NV_representative_fragment_test", 2 },
        { "VK_NV_sample_mask_override_coverage", 1 },
        { "VK_NV_scissor_exclusive", 1 },
        { "VK_NV_shader_image_footprint", 2 },
        { "VK_NV_shader_sm_builtins", 1 },
        { "VK_NV_shader_subgroup_partitioned", 1 },
        { "VK_NV_shading_rate_image", 3 },
        { "VK_NV_viewport_array2", 1 },
        { "VK_NV_viewport_swizzle", 1 },
    };
    std::vector<VkExtensionProperties> extensions;
    std::copy(std::begin(ext_arr), std::end(ext_arr), std::back_inserter(extensions));

    SECTION("Check extensions are sorted")
    {
        const bool sorted_extensions =
            std::is_sorted(std::begin(extensions), std::end(extensions), VkExtensionPropertiesCmp);
        const bool sorted_screened =
            std::is_sorted(std::begin(kExampleDeviceExtensions), std::end(kExampleDeviceExtensions), CstrCmp);
        REQUIRE(sorted_extensions);
        REQUIRE(sorted_screened);
    }

    SECTION("Screen an empty extensions list")
    {
        const auto start_size = extensions.size();
        gfxrecon::VulkanRemoveExtensions(extensions, kExampleDeviceExtensions, 0);
        REQUIRE(extensions.size() == start_size);
    }

    SECTION("Screen a single extension")
    {
        const char* const unsupported_device_extensions_not_present[] = {
            VK_VALVE_DESCRIPTOR_SET_HOST_MAPPING_EXTENSION_NAME,
        };
        const char* const unsupported_device_extensions_present[] = {
            "VK_KHR_external_semaphore",
        };
        const auto start_size = extensions.size();

        gfxrecon::VulkanRemoveExtensions(extensions, unsupported_device_extensions_not_present, 1);
        REQUIRE(extensions.size() == start_size);
        gfxrecon::VulkanRemoveExtensions(extensions, unsupported_device_extensions_present, 1);
        REQUIRE(extensions.size() == start_size - 1);
    }

    SECTION("Screen many single extensions")
    {
        for (auto it     = std::begin(kExampleDeviceExtensions),
                  it_nop = std::begin(kExampleDeviceExtensionsUpper),
                  end    = std::end(kExampleDeviceExtensions);
             it != end;
             ++it, ++it_nop)
        {
            const auto start_size = extensions.size();
            gfxrecon::VulkanRemoveExtensions(extensions, &*it_nop, 1);
            REQUIRE(extensions.size() == start_size);
            gfxrecon::VulkanRemoveExtensions(extensions, &*it, 1);
            REQUIRE(extensions.size() == start_size - 1);
        }
    }

    SECTION("Screen all extensions")
    {
        const auto start_size = extensions.size();
        gfxrecon::VulkanRemoveExtensions(extensions,
                                         kExampleDeviceExtensionsUpper,
                                         std::end(kExampleDeviceExtensionsUpper) -
                                             std::begin(kExampleDeviceExtensionsUpper));
        REQUIRE(extensions.size() == start_size);
        gfxrecon::VulkanRemoveExtensions(extensions,
                                         kExampleDeviceExtensions,
                                         std::end(kExampleDeviceExtensions) - std::begin(kExampleDeviceExtensions));
        REQUIRE(extensions.size() == 0);
    }

    SECTION("Screen all extensions - reversed")
    {
        std::reverse(std::begin(extensions), std::end(extensions));
        const auto start_size = extensions.size();
        gfxrecon::VulkanRemoveExtensions(extensions,
                                         kExampleDeviceExtensionsUpper,
                                         std::end(kExampleDeviceExtensionsUpper) -
                                             std::begin(kExampleDeviceExtensionsUpper));
        REQUIRE(extensions.size() == start_size);

        std::reverse(std::begin(extensions), std::end(extensions));
        gfxrecon::VulkanRemoveExtensions(extensions,
                                         kExampleDeviceExtensions,
                                         std::end(kExampleDeviceExtensions) - std::begin(kExampleDeviceExtensions));
        REQUIRE(extensions.size() == 0);
    }

    SECTION("Screen all extensions - permuted")
    {
        trash_randomize(extensions);
        const auto start_size = extensions.size();
        gfxrecon::VulkanRemoveExtensions(extensions,
                                         kExampleDeviceExtensionsUpper,
                                         std::end(kExampleDeviceExtensionsUpper) -
                                             std::begin(kExampleDeviceExtensionsUpper));
        REQUIRE(extensions.size() == start_size);

        trash_randomize(extensions);
        gfxrecon::VulkanRemoveExtensions(extensions,
                                         kExampleDeviceExtensions,
                                         std::end(kExampleDeviceExtensions) - std::begin(kExampleDeviceExtensions));
        REQUIRE(extensions.size() == 0);
    }

    SECTION("Screen all extensions - permuted more")
    {
        trash_randomize(extensions);
        trash_randomize(extensions);
        trash_randomize(extensions);
        const auto start_size = extensions.size();
        gfxrecon::VulkanRemoveExtensions(extensions,
                                         kExampleDeviceExtensionsUpper,
                                         std::end(kExampleDeviceExtensionsUpper) -
                                             std::begin(kExampleDeviceExtensionsUpper));
        REQUIRE(extensions.size() == start_size);

        trash_randomize(extensions);
        trash_randomize(extensions);
        trash_randomize(extensions);
        gfxrecon::VulkanRemoveExtensions(extensions,
                                         kExampleDeviceExtensions,
                                         std::end(kExampleDeviceExtensions) - std::begin(kExampleDeviceExtensions));
        REQUIRE(extensions.size() == 0);
    }

    gfxrecon::util::Log::Release();
}
