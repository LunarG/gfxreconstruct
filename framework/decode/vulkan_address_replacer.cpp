/*
** Copyright (c) 2024 LunarG, Inc.
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

#include "decode/vulkan_address_replacer.h"
#include "decode/vulkan_address_replacer_shaders.h"
#include "util/linear_hashmap.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

//! 16 bytes
struct hashmap_t
{
    VkDeviceAddress storage;
    uint32_t        size;
    uint32_t        capacity;
};

struct replacer_params_t
{
    hashmap_t shader_group_handle_map;

    // input-/output-arrays can be identical when sbt-alignments/strides match
    VkDeviceAddress input_handles, output_handles;
    uint32_t        num_handles;
};

VulkanAddressReplacer::VulkanAddressReplacer(const VulkanDeviceInfo*              device_info,
                                             const encode::VulkanDeviceTable*     device_table,
                                             const decode::CommonObjectInfoTable& object_table) :
    device_table_(device_table)
{
    GFXRECON_ASSERT(device_info != nullptr && device_table != nullptr)

    device_ = device_info->handle;

    const VulkanPhysicalDeviceInfo* physical_device_info = object_table.GetVkPhysicalDeviceInfo(device_info->parent_id);

    if (physical_device_info != nullptr && physical_device_info->replay_device_info->raytracing_properties)
    {
        const auto& replay_props = *physical_device_info->replay_device_info->raytracing_properties;

        if (physical_device_info->shaderGroupHandleSize != replay_props.shaderGroupHandleSize ||
            physical_device_info->shaderGroupHandleAlignment != replay_props.shaderGroupHandleAlignment ||
            physical_device_info->shaderGroupBaseAlignment != replay_props.shaderGroupBaseAlignment)
        {
            valid_sbt_alignment_ = false;
        }
    }

    VkPushConstantRange push_constant_range = {};
    push_constant_range.stageFlags          = VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT;
    push_constant_range.offset              = 0;
    push_constant_range.size                = sizeof(replacer_params_t);

    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.pNext                      = nullptr;
    pipeline_layout_info.flags                      = 0;
    pipeline_layout_info.setLayoutCount             = 0;
    pipeline_layout_info.pSetLayouts                = nullptr;
    pipeline_layout_info.pushConstantRangeCount     = 1;
    pipeline_layout_info.pPushConstantRanges        = &push_constant_range;

    VkResult result = device_table_->CreatePipelineLayout(device_, &pipeline_layout_info, nullptr, &pipeline_layout_);

    if (result == VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanAddressReplacer: failed in vkCreatePipelineLayout");
    }
    VkShaderModule           compute_module = VK_NULL_HANDLE;
    VkShaderModuleCreateInfo ps_info        = {};
    ps_info.sType                           = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    ps_info.pNext                           = VK_NULL_HANDLE;
    ps_info.flags                           = 0;
    ps_info.codeSize                        = g_replacer_sbt_comp.size();
    ps_info.pCode                           = reinterpret_cast<const uint32_t*>(g_replacer_sbt_comp.data());

    result = device_table_->CreateShaderModule(device_, &ps_info, nullptr, &compute_module);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanAddressReplacer: failed in vkCreateShaderModule");
    }
    VkPipelineShaderStageCreateInfo stage_info = {};
    stage_info.sType                           = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    stage_info.pNext                           = nullptr;
    stage_info.flags                           = 0;
    stage_info.stage                           = VK_SHADER_STAGE_COMPUTE_BIT;
    stage_info.module                          = compute_module;
    stage_info.pName                           = "main";
    stage_info.pSpecializationInfo             = nullptr;

    VkComputePipelineCreateInfo pipeline_create_info = {};
    pipeline_create_info.sType                       = VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO;
    pipeline_create_info.layout                      = pipeline_layout_;
    pipeline_create_info.stage                       = stage_info;

    result = device_table_->CreateComputePipelines(
        device_, VK_NULL_HANDLE, 1, &pipeline_create_info, VK_NULL_HANDLE, &pipeline_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("VulkanAddressReplacer: pipeline creation failed");
    }

    if (compute_module != VK_NULL_HANDLE)
    {
        device_table_->DestroyShaderModule(device_, compute_module, nullptr);
    }
}

VulkanAddressReplacer::~VulkanAddressReplacer()
{
    if (pipeline_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyPipeline(device_, pipeline_, nullptr);
    }

    if (pipeline_layout_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyPipelineLayout(device_, pipeline_layout_, nullptr);
    }
}

void VulkanAddressReplacer::ProcessCmdTraceRays(
    VkCommandBuffer                                                                             commandBuffer,
    VkStridedDeviceAddressRegionKHR*                                                            raygen_sbt,
    VkStridedDeviceAddressRegionKHR*                                                            miss_sbt,
    VkStridedDeviceAddressRegionKHR*                                                            hit_sbt,
    VkStridedDeviceAddressRegionKHR*                                                            callable_sbt,
    const decode::VulkanDeviceAddressTracker&                                                   address_tracker,
    const std::unordered_map<graphics::shader_group_handle_t, graphics::shader_group_handle_t>& group_handle_map)
{
    // figure out if the captured group-handles are valid for replay
    // NOTE: we expect this map to be populated here, but not for older captures (before #1844) using trimming.
    bool valid_group_handles = !group_handle_map.empty();

    for (const auto& [lhs, rhs] : group_handle_map)
    {
        if (lhs != rhs)
        {
            valid_group_handles = false;
            break;
        }
    }

    if (!valid_sbt_alignment_ || !valid_group_handles)
    {
        if (valid_sbt_alignment_)
        {
            auto address_remap = [&address_tracker](VkStridedDeviceAddressRegionKHR* address_region) {
                if (address_region->size > 0)
                {
                    auto buffer_info = address_tracker.GetBufferByCaptureDeviceAddress(address_region->deviceAddress);
                    GFXRECON_ASSERT(buffer_info != nullptr);

                    if (buffer_info->replay_address != 0)
                    {
                        uint64_t offset = address_region->deviceAddress - buffer_info->capture_address;

                        // in-place address-remap
                        address_region->deviceAddress = buffer_info->replay_address + offset;
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING_ONCE(
                            "OverrideCmdTraceRaysKHR: missing buffer_info->replay_address, remap failed")
                    }
                }
            };

            // in-place remap: capture-addresses -> replay-addresses
            address_remap(raygen_sbt);
            address_remap(miss_sbt);
            address_remap(hit_sbt);
            address_remap(callable_sbt);

            // create linear hashmap
            util::linear_hashmap<graphics::shader_group_handle_t, graphics::shader_group_handle_t> hashmap;
            for (const auto& [lhs, rhs] : group_handle_map)
            {
                hashmap.put(lhs, rhs);
            }

            // TODO: upload hashmap-storage
            replacer_params_t replacer_params = {};
            //            replacer_params.input_handles

            device_table_->CmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_);
            device_table_->CmdPushConstants(commandBuffer,
                                            pipeline_layout_,
                                            VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                                            0,
                                            sizeof(replacer_params_t),
                                            &replacer_params);
            // run a single workgroup
            device_table_->CmdDispatch(commandBuffer, 1, 1, 1);
        }
        else
        {
            // TODO: remove TODO/warning when issue #1526 is solved
            GFXRECON_LOG_WARNING_ONCE("OverrideCmdTraceRaysKHR: invalid shader-binding-table (handle-size and/or "
                                      "alignments mismatch) -> TODO: run SBT re-assembly");

            // TODO: create shadow-SBT-buffer, remap addresses to that
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
