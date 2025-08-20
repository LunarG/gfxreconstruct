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

#include "graphics/vulkan_util.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "decode/vulkan_address_replacer.h"
#include "decode/vulkan_address_replacer_shaders.h"
#include "decode/mark_injected_commands.h"
#include "util/alignment_utils.h"
#include "util/logging.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

//! RAII helper to mark injected commands in scope
struct MarkInjectedCommandsHelper
{
    // allow nested usage without hitting an assertion
    static thread_local std::atomic<uint32_t> semaphore;

    MarkInjectedCommandsHelper()
    {
        // mark injected commands
        if (semaphore++ == 0)
        {
            decode::BeginInjectedCommands();
        };
    }

    ~MarkInjectedCommandsHelper()
    {
        // mark end of injected commands
        if (--semaphore == 0)
        {
            decode::EndInjectedCommands();
        }
    }
};
thread_local std::atomic<uint32_t> MarkInjectedCommandsHelper::semaphore = 0;

//! RAII helper submit a command-buffer to a queue and synchronize via fence
struct QueueSubmitHelper
{
    const graphics::VulkanDeviceTable* device_table   = nullptr;
    VkDevice                           device         = VK_NULL_HANDLE;
    VkCommandBuffer                    command_buffer = VK_NULL_HANDLE;
    VkFence                            fence          = VK_NULL_HANDLE;
    VkQueue                            queue          = VK_NULL_HANDLE;

    QueueSubmitHelper()                         = default;
    QueueSubmitHelper(const QueueSubmitHelper&) = delete;
    QueueSubmitHelper(QueueSubmitHelper&& other) noexcept : QueueSubmitHelper() { swap(other); }

    QueueSubmitHelper& operator=(QueueSubmitHelper other)
    {
        swap(other);
        return *this;
    }
    QueueSubmitHelper(const graphics::VulkanDeviceTable* device_table_,
                      VkDevice                           device_,
                      VkCommandBuffer                    command_buffer_,
                      VkQueue                            queue_,
                      VkFence                            fence_) :
        device_table(device_table_),
        device(device_), command_buffer(command_buffer_), fence(fence_), queue(queue_)
    {
        MarkInjectedCommandsHelper mark_injected_commands_helper;

        device_table->ResetFences(device, 1, &fence);

        VkCommandBufferBeginInfo command_buffer_begin_info;
        command_buffer_begin_info.sType            = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
        command_buffer_begin_info.pNext            = nullptr;
        command_buffer_begin_info.flags            = 0;
        command_buffer_begin_info.pInheritanceInfo = nullptr;
        device_table->BeginCommandBuffer(command_buffer, &command_buffer_begin_info);
    }

    ~QueueSubmitHelper()
    {
        if (device_table != nullptr)
        {
            MarkInjectedCommandsHelper mark_injected_commands_helper;

            device_table->EndCommandBuffer(command_buffer);

            VkSubmitInfo submit_info         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
            submit_info.pNext                = nullptr;
            submit_info.waitSemaphoreCount   = 0;
            submit_info.pWaitSemaphores      = nullptr;
            submit_info.pWaitDstStageMask    = nullptr;
            submit_info.commandBufferCount   = 1;
            submit_info.pCommandBuffers      = &command_buffer;
            submit_info.signalSemaphoreCount = 0;
            submit_info.pSignalSemaphores    = nullptr;

            // submit
            device_table->QueueSubmit(queue, 1, &submit_info, fence);

            // sync
            device_table->WaitForFences(device, 1, &fence, VK_TRUE, std::numeric_limits<uint64_t>::max());
        }
    }

    void swap(QueueSubmitHelper& other)
    {
        std::swap(device_table, other.device_table);
        std::swap(device, other.device);
        std::swap(command_buffer, other.command_buffer);
        std::swap(fence, other.fence);
        std::swap(queue, other.queue);
    }
};

//! this struct groups data for an array in gpu-memory (either host- or device-visible)
//! it's purpose is to serve as storage for sorted arrays (used for binary searches) or as linear hashmap-storage.
struct gpu_array_t
{
    VkDeviceAddress storage  = 0;
    uint32_t        size     = 0;
    uint32_t        capacity = 0;
};

//! parameter-struct passed to SBT-replacer compute-shaders
struct replacer_params_sbt_t
{
    gpu_array_t hashmap = {};

    // input-/output-arrays can be identical when sbt-alignments/strides match
    VkDeviceAddress input_handles  = 0;
    VkDeviceAddress output_handles = 0;
    uint32_t        num_handles    = 0;
};

//! parameter-struct passed to BDA-replacer compute-shaders
struct replacer_params_bda_t
{
    // sorted(!) array of bda_element_t, used for mapping device-address from capture -> replay.
    gpu_array_t address_array = {};

    // storage-buffer for a hashmap-control-block (gpu_array_t), caches addresses that have already been replaced
    VkDeviceAddress address_blacklist = 0;

    // input-/output-arrays can be identical when sbt-alignments/strides match
    VkDeviceAddress input_handles  = 0;
    VkDeviceAddress output_handles = 0;
    uint32_t        num_handles    = 0;
};

decode::VulkanAddressReplacer::buffer_context_t::buffer_context_t(buffer_context_t&& other) noexcept :
    buffer_context_t()
{
    swap(other);
}

decode::VulkanAddressReplacer::buffer_context_t&
decode::VulkanAddressReplacer::buffer_context_t::operator=(buffer_context_t other)
{
    swap(other);
    return *this;
}

void decode::VulkanAddressReplacer::buffer_context_t::swap(buffer_context_t& other)
{
    std::swap(resource_allocator, other.resource_allocator);
    std::swap(num_bytes, other.num_bytes);
    std::swap(device_memory, other.device_memory);
    std::swap(buffer, other.buffer);
    std::swap(allocator_data, other.allocator_data);
    std::swap(memory_data, other.memory_data);
    std::swap(device_address, other.device_address);
    std::swap(mapped_data, other.mapped_data);
    std::swap(name, other.name);
}

decode::VulkanAddressReplacer::buffer_context_t::~buffer_context_t()
{
    if (resource_allocator != nullptr)
    {
        if (buffer != VK_NULL_HANDLE)
        {
            // unmap/destroy buffer
            if (mapped_data != nullptr)
            {
                resource_allocator->UnmapResourceMemoryDirect(allocator_data);
            }
            resource_allocator->DestroyBufferDirect(buffer, nullptr, allocator_data);
        }
        if (device_memory != VK_NULL_HANDLE)
        {
            resource_allocator->FreeMemoryDirect(device_memory, nullptr, memory_data);
        }

        resource_allocator = nullptr;
        buffer             = VK_NULL_HANDLE;
        device_memory      = VK_NULL_HANDLE;
    }
}

decode::VulkanAddressReplacer::acceleration_structure_asset_t::~acceleration_structure_asset_t()
{
    if (handle != VK_NULL_HANDLE && destroy_fn != nullptr && device != VK_NULL_HANDLE)
    {
        destroy_fn(device, handle, nullptr);
    }
}

decode::VulkanAddressReplacer::submit_asset_t::submit_asset_t(submit_asset_t&& other) noexcept : submit_asset_t()
{
    swap(other);
}

decode::VulkanAddressReplacer::submit_asset_t&
decode::VulkanAddressReplacer::submit_asset_t::operator=(submit_asset_t other)
{
    swap(other);
    return *this;
}

void decode::VulkanAddressReplacer::submit_asset_t::swap(submit_asset_t& other)
{
    std::swap(device, other.device);
    std::swap(command_pool, other.command_pool);
    std::swap(command_buffer, other.command_buffer);
    std::swap(fence, other.fence);
    std::swap(signal_semaphore, other.signal_semaphore);
    std::swap(destroy_fence_fn, other.destroy_fence_fn);
    std::swap(free_command_buffers_fn, other.free_command_buffers_fn);
    std::swap(destroy_semaphore_fn, other.destroy_semaphore_fn);
}

decode::VulkanAddressReplacer::submit_asset_t::~submit_asset_t()
{
    if (device != VK_NULL_HANDLE)
    {
        if (destroy_fence_fn != nullptr && fence != VK_NULL_HANDLE)
        {
            destroy_fence_fn(device, fence, nullptr);
        }
        if (free_command_buffers_fn != nullptr && command_buffer != VK_NULL_HANDLE)
        {
            free_command_buffers_fn(device, command_pool, 1, &command_buffer);
        }
        if (destroy_semaphore_fn != nullptr && signal_semaphore != VK_NULL_HANDLE)
        {
            destroy_semaphore_fn(device, signal_semaphore, nullptr);
        }
    }
}

VulkanAddressReplacer::VulkanAddressReplacer(const VulkanDeviceInfo*              device_info,
                                             const graphics::VulkanDeviceTable*   device_table,
                                             const graphics::VulkanInstanceTable* instance_table,
                                             decode::CommonObjectInfoTable&       object_table) :
    device_table_(device_table),
    object_table_(&object_table)
{
    GFXRECON_ASSERT(device_info != nullptr && device_table != nullptr && instance_table != nullptr);
    physical_device_info_ = object_table.GetVkPhysicalDeviceInfo(device_info->parent_id);
    GFXRECON_ASSERT(physical_device_info_ != nullptr);
    device_                = device_info->handle;
    resource_allocator_    = device_info->allocator.get();
    get_device_address_fn_ = physical_device_info_->parent_info.api_version >= VK_API_VERSION_1_2
                                 ? device_table->GetBufferDeviceAddress
                                 : device_table->GetBufferDeviceAddressKHR;

    get_physical_device_properties_fn_ = instance_table->GetPhysicalDeviceProperties2;
    set_debug_utils_object_name_fn_    = reinterpret_cast<PFN_vkSetDebugUtilsObjectNameEXT>(
        device_table_->GetDeviceProcAddr(device_, "vkSetDebugUtilsObjectNameEXT"));
    SetRaytracingProperties(physical_device_info_);
}

void VulkanAddressReplacer::SetRaytracingProperties(const decode::VulkanPhysicalDeviceInfo* physical_device_info)
{
    if (physical_device_info != nullptr)
    {
        physical_device_info_ = physical_device_info;
        if (physical_device_info->capture_raytracing_properties)
        {
            capture_ray_properties_ = *physical_device_info->capture_raytracing_properties;
        }

        if (physical_device_info->replay_device_info != nullptr)
        {
            if (physical_device_info->replay_device_info->raytracing_properties)
            {
                replay_ray_properties_ = *physical_device_info->replay_device_info->raytracing_properties;
            }
            if (physical_device_info->replay_device_info->acceleration_structure_properties)
            {
                replay_acceleration_structure_properties_ =
                    *physical_device_info->replay_device_info->acceleration_structure_properties;
            }
            GFXRECON_ASSERT(physical_device_info_->replay_device_info->memory_properties.has_value());
            memory_properties_ = *physical_device_info_->replay_device_info->memory_properties;
        }
    }

    if (capture_ray_properties_ && replay_ray_properties_)
    {
        if (capture_ray_properties_->shaderGroupHandleSize != replay_ray_properties_->shaderGroupHandleSize ||
            capture_ray_properties_->shaderGroupHandleAlignment != replay_ray_properties_->shaderGroupHandleAlignment ||
            capture_ray_properties_->shaderGroupBaseAlignment != replay_ray_properties_->shaderGroupBaseAlignment)
        {
            valid_sbt_alignment_ = false;
        }
    }
}

VulkanAddressReplacer::~VulkanAddressReplacer()
{
    MarkInjectedCommandsHelper mark_injected_commands_helper;

    // explicitly free resources here, in order to mark destruction API-calls as injected
    pipeline_context_map_.clear();
    shadow_sbt_map_.clear();
    shadow_as_map_.clear();
    submit_asset_map_.clear();
    submit_asset_ = {};

    if (pipeline_bda_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyPipeline(device_, pipeline_bda_, nullptr);
    }
    if (pipeline_bda_rehash_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyPipeline(device_, pipeline_bda_rehash_, nullptr);
    }
    if (pipeline_sbt_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyPipeline(device_, pipeline_sbt_, nullptr);
    }
    if (pipeline_layout_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyPipelineLayout(device_, pipeline_layout_, nullptr);
    }
    if (query_pool_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyQueryPool(device_, query_pool_, nullptr);
    }
    if (command_pool_ != VK_NULL_HANDLE)
    {
        device_table_->DestroyCommandPool(device_, command_pool_, nullptr);
    }
}

VkSemaphore VulkanAddressReplacer::UpdateBufferAddresses(
    const VulkanCommandBufferInfo*                                      command_buffer_info,
    const VkDeviceAddress*                                              addresses,
    uint32_t                                                            num_addresses,
    const decode::VulkanDeviceAddressTracker&                           address_tracker,
    const std::optional<std::vector<std::pair<VkSemaphore, uint64_t>>>& wait_semaphores)
{
    if (addresses != nullptr && num_addresses > 0)
    {
        GFXRECON_LOG_INFO_ONCE("VulkanAddressReplacer::UpdateBufferAddresses(): Replay is adjusting "
                               "buffer-device-addresses in-place using a compute-dispatch");

        storage_bda_binary_.clear();

        // populate hashmap
        const auto& address_map = address_tracker.GetBufferDeviceAddressMap();
        for (const auto& [capture_address, replay_item] : address_map)
        {
            storage_bda_binary_.push_back({ capture_address, replay_item.address, replay_item.size });
        }

        if (command_buffer_info != nullptr)
        {
            if (!wait_semaphores)
            {
                run_compute_replace(command_buffer_info,
                                    addresses,
                                    num_addresses,
                                    address_tracker,
                                    VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT);
            }
            else
            {
                // don't inject into the command-buffer, instead use a separate submit
                submit_asset_t& submit_asset = submit_asset_map_[command_buffer_info->handle];
                if (!init_queue_assets() || !create_submit_asset(submit_asset))
                {
                    GFXRECON_LOG_WARNING_ONCE(
                        "VulkanAddressReplacer::UpdateBufferAddresses: could not create required submit-assets");
                    return VK_NULL_HANDLE;
                }

                device_table_->ResetFences(device_, 1, &submit_asset.fence);

                VkCommandBufferBeginInfo command_buffer_begin_info;
                command_buffer_begin_info.sType            = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
                command_buffer_begin_info.pNext            = nullptr;
                command_buffer_begin_info.flags            = 0;
                command_buffer_begin_info.pInheritanceInfo = nullptr;
                device_table_->BeginCommandBuffer(submit_asset.command_buffer, &command_buffer_begin_info);

                VulkanCommandBufferInfo fake_info = {};
                fake_info.handle                  = submit_asset.command_buffer;
                run_compute_replace(
                    &fake_info, addresses, num_addresses, address_tracker, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT);

                device_table_->EndCommandBuffer(submit_asset.command_buffer);

                std::vector<VkSemaphore>          semaphore_handles(wait_semaphores->size());
                std::vector<uint64_t>             semaphore_values(wait_semaphores->size());
                std::vector<VkPipelineStageFlags> wait_dst_stages(wait_semaphores->size(),
                                                                  VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT);

                for (uint32_t i = 0; i < wait_semaphores->size(); ++i)
                {
                    semaphore_handles[i] = wait_semaphores.value()[i].first;
                    semaphore_values[i]  = wait_semaphores.value()[i].second;
                }

                VkTimelineSemaphoreSubmitInfo timeline_info = {};
                timeline_info.sType                         = VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO;
                timeline_info.waitSemaphoreValueCount       = wait_semaphores->size();
                timeline_info.pWaitSemaphoreValues = wait_semaphores->empty() ? nullptr : semaphore_values.data();

                VkSubmitInfo submit_info         = { VK_STRUCTURE_TYPE_SUBMIT_INFO };
                submit_info.pNext                = &timeline_info;
                submit_info.waitSemaphoreCount   = wait_semaphores->size();
                submit_info.pWaitSemaphores      = wait_semaphores->empty() ? nullptr : semaphore_handles.data();
                submit_info.pWaitDstStageMask    = wait_semaphores->empty() ? nullptr : wait_dst_stages.data();
                submit_info.commandBufferCount   = 1;
                submit_info.pCommandBuffers      = &submit_asset.command_buffer;
                submit_info.signalSemaphoreCount = 1;
                submit_info.pSignalSemaphores    = &submit_asset.signal_semaphore;

                // submit
                device_table_->QueueSubmit(queue_, 1, &submit_info, submit_asset.fence);

                // return signal-semaphore
                return submit_asset.signal_semaphore;
            }
        }
        else if (init_queue_assets())
        {
            // reset/submit/sync command-buffer
            QueueSubmitHelper queue_submit_helper(
                device_table_, device_, submit_asset_.command_buffer, queue_, submit_asset_.fence);

            VulkanCommandBufferInfo fake_info = {};
            fake_info.handle                  = submit_asset_.command_buffer;
            run_compute_replace(
                &fake_info, addresses, num_addresses, address_tracker, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);
        }
    }
    return VK_NULL_HANDLE;
}

void VulkanAddressReplacer::ProcessCmdPushConstants(const VulkanCommandBufferInfo*            command_buffer_info,
                                                    VkShaderStageFlags                        stage_flags,
                                                    uint32_t                                  offset,
                                                    uint32_t                                  size,
                                                    void*                                     data,
                                                    const decode::VulkanDeviceAddressTracker& address_tracker)
{
    GFXRECON_UNREFERENCED_PARAMETER(stage_flags);
    GFXRECON_UNREFERENCED_PARAMETER(size);
    GFXRECON_ASSERT(command_buffer_info != nullptr && data != nullptr);
    for (const auto& [bind_point, pipeline_id] : command_buffer_info->bound_pipelines)
    {
        const auto* pipeline_info = object_table_->GetVkPipelineInfo(pipeline_id);
        GFXRECON_ASSERT(pipeline_info != nullptr);
        if (pipeline_info != nullptr)
        {
            for (const auto& buffer_ref_info : pipeline_info->buffer_reference_infos)
            {
                if (buffer_ref_info.source == util::SpirVParsingUtil::BufferReferenceLocation::PUSH_CONSTANT_BLOCK)
                {
                    // find addresses in push-constant memory and replace in-place.
                    auto* address = reinterpret_cast<VkDeviceAddress*>(static_cast<uint8_t*>(data) + offset +
                                                                       buffer_ref_info.buffer_offset);

                    auto* buffer_info = address_tracker.GetBufferByCaptureDeviceAddress(*address);
                    if (buffer_info != nullptr && buffer_info->replay_address != 0)
                    {
                        GFXRECON_LOG_INFO_ONCE("VulkanAddressReplacer::ProcessCmdPushConstants(): Replay is adjusting "
                                               "buffer-device-addresses in push-constants");
                        uint32_t address_offset = *address - buffer_info->capture_address;
                        *address                = buffer_info->replay_address + address_offset;
                    }
                }
            }
        }
    }
}

void VulkanAddressReplacer::ProcessCmdBindDescriptorSets(VulkanCommandBufferInfo*               command_buffer_info,
                                                         VkPipelineBindPoint                    pipelineBindPoint,
                                                         uint32_t                               firstSet,
                                                         uint32_t                               descriptorSetCount,
                                                         HandlePointerDecoder<VkDescriptorSet>* pDescriptorSets,
                                                         VulkanDeviceAddressTracker&            address_tracker)
{
    const auto* pipeline_info =
        object_table_->GetVkPipelineInfo(command_buffer_info->bound_pipelines[pipelineBindPoint]);
    if (pipeline_info == nullptr)
    {
        return;
    };

    std::map<std::pair<VkDescriptorSet, uint32_t>, VkWriteDescriptorSetInlineUniformBlock> sets_requiring_update;

    for (const auto& buffer_ref_info : pipeline_info->buffer_reference_infos)
    {
        if (buffer_ref_info.source != util::SpirVParsingUtil::BufferReferenceLocation::UNIFORM_BUFFER &&
            buffer_ref_info.source != util::SpirVParsingUtil::BufferReferenceLocation::STORAGE_BUFFER)
        {
            // non-buffer descriptor, handled elsewhere
            continue;
        }
        GFXRECON_ASSERT(buffer_ref_info.set <= descriptorSetCount);

        // we need a mutable pointer, to allow for in-place corrections
        auto* descriptor_set_info =
            object_table_->GetVkDescriptorSetInfo(pDescriptorSets->GetPointer()[buffer_ref_info.set]);

        if (descriptor_set_info == nullptr)
        {
            continue;
        };

        auto it = descriptor_set_info->descriptors.find(buffer_ref_info.binding);
        if (it == descriptor_set_info->descriptors.end())
        {
            GFXRECON_LOG_WARNING_ONCE("VulkanAddressReplacer::ProcessCmdBindDescriptorSets: could not find a "
                                      "descriptor while sanitizing buffer-references.");
            continue;
        }
        auto& descriptor_set_binding_info = it->second;
        GFXRECON_ASSERT(!descriptor_set_binding_info.buffer_info.empty() ||
                        !descriptor_set_binding_info.buffer_info.empty());

        for (auto& [binding, desc_buffer_info] : descriptor_set_binding_info.buffer_info)
        {
            auto* buffer_info = const_cast<VulkanBufferInfo*>(desc_buffer_info.buffer_info);

            if (buffer_info != nullptr)
            {
                // we only track buffers with device-addresses here
                if (auto* tracked_buffer =
                        address_tracker.GetBufferByCaptureDeviceAddress(buffer_info->capture_address))
                {
                    // assert we got buffer-tracking correct
                    GFXRECON_ASSERT(tracked_buffer == buffer_info);
                }
                else
                {
                    // patch an existing uniform-buffer and retrieve a buffer-address for it
                    decode::BeginInjectedCommands();
                    VkBufferDeviceAddressInfo address_info = {};
                    address_info.sType                     = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
                    address_info.buffer                    = buffer_info->handle;
                    buffer_info->capture_address           = buffer_info->replay_address =
                        get_device_address_fn_(device_, &address_info);
                    GFXRECON_ASSERT(buffer_info->replay_address != 0);
                    decode::EndInjectedCommands();

                    // track newly acquired buffer/address
                    address_tracker.TrackBuffer(buffer_info);
                }

                VkDeviceSize    offset  = desc_buffer_info.offset + buffer_ref_info.buffer_offset;
                VkDeviceAddress address = buffer_info->replay_address + offset;
                VkDeviceAddress range_end =
                    address + std::min<VkDeviceSize>(buffer_info->size - offset, desc_buffer_info.range);
                command_buffer_info->addresses_to_replace.insert(address);

                if (buffer_ref_info.array_stride)
                {
                    address += buffer_ref_info.array_stride;
                    for (; address < range_end; address += buffer_ref_info.array_stride)
                    {
                        command_buffer_info->addresses_to_replace.insert(address);
                    }
                }
            }
        }

        if (buffer_ref_info.buffer_offset < descriptor_set_binding_info.inline_uniform_block.size())
        {
            // find addresses in inline-uniform-block and replace in-place.
            auto* address = reinterpret_cast<VkDeviceAddress*>(descriptor_set_binding_info.inline_uniform_block.data() +
                                                               buffer_ref_info.buffer_offset);

            auto* buffer_info = address_tracker.GetBufferByCaptureDeviceAddress(*address);

            // ensure buffer exists and replacement actually required
            if (buffer_info != nullptr && buffer_info->replay_address != 0 &&
                buffer_info->capture_address != buffer_info->replay_address)
            {
                GFXRECON_LOG_INFO_ONCE("VulkanAddressReplacer::ProcessCmdBindDescriptorSets(): Replay is adjusting "
                                       "buffer-device-addresses in inline-uniform-block");
                uint32_t address_offset = *address - buffer_info->capture_address;
                *address                = buffer_info->replay_address + address_offset;

                // TODO: come back for this. we don't treat arrays in push-constants and here, but probably should
                GFXRECON_ASSERT(buffer_ref_info.array_stride == 0);

                // batch descriptor-updates
                auto& write_inline_uniform_block =
                    sets_requiring_update[{ descriptor_set_info->handle, buffer_ref_info.binding }];
                write_inline_uniform_block.sType    = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK;
                write_inline_uniform_block.dataSize = descriptor_set_binding_info.inline_uniform_block.size();
                write_inline_uniform_block.pData    = descriptor_set_binding_info.inline_uniform_block.data();
            }
        }
    } // pipeline_info->buffer_reference_infos

    std::vector<VkWriteDescriptorSet> descriptor_updates;
    descriptor_updates.reserve(sets_requiring_update.size());

    for (const auto& [pair, write_inline_uniform_block] : sets_requiring_update)
    {
        const auto& [descriptor_set, binding] = pair;

        // requires an injected call to vkUpdateDescriptorSets in order to correct addresses
        VkWriteDescriptorSet& write_descriptor_set = descriptor_updates.emplace_back();
        write_descriptor_set.sType                 = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        write_descriptor_set.descriptorType        = VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK;
        write_descriptor_set.descriptorCount       = write_inline_uniform_block.dataSize;
        write_descriptor_set.dstSet                = descriptor_set;
        write_descriptor_set.dstBinding            = binding;
        write_descriptor_set.pNext                 = &write_inline_uniform_block;
    }

    if (!descriptor_updates.empty())
    {
        // mark injected commands
        MarkInjectedCommandsHelper mark_injected_commands_helper;
        device_table_->UpdateDescriptorSets(device_, descriptor_updates.size(), descriptor_updates.data(), 0, nullptr);
    }

    if (!command_buffer_info->inside_renderpass)
    {
        std::vector<VkDeviceAddress> addresses_to_replace(command_buffer_info->addresses_to_replace.begin(),
                                                          command_buffer_info->addresses_to_replace.end());
        UpdateBufferAddresses(
            command_buffer_info, addresses_to_replace.data(), addresses_to_replace.size(), address_tracker);
        command_buffer_info->addresses_to_replace.clear();
    }
}

void VulkanAddressReplacer::ProcessCmdTraceRays(
    const VulkanCommandBufferInfo*                                                              command_buffer_info,
    VkStridedDeviceAddressRegionKHR*                                                            raygen_sbt,
    VkStridedDeviceAddressRegionKHR*                                                            miss_sbt,
    VkStridedDeviceAddressRegionKHR*                                                            hit_sbt,
    VkStridedDeviceAddressRegionKHR*                                                            callable_sbt,
    const decode::VulkanDeviceAddressTracker&                                                   address_tracker,
    const std::unordered_map<graphics::shader_group_handle_t, graphics::shader_group_handle_t>& group_handle_map)
{
    GFXRECON_ASSERT(device_table_ != nullptr);

    // NOTE: we expect this map to be populated here, but not for older captures (before #1844) using trimming.
    if (group_handle_map.empty())
    {
        // the capture appears to be older and is missing information we require here -> bail out
        return;
    }

    // figure out if the captured group-handles are valid for replay
    bool valid_group_handles = true;

    for (const auto& [lhs, rhs] : group_handle_map)
    {
        if (lhs != rhs)
        {
            valid_group_handles = false;
            break;
        }
    }

    // raytracing-pipeline properties not populated yet, check if we missed it
    if (capture_ray_properties_ == std::nullopt || replay_ray_properties_ == std::nullopt)
    {
        SetRaytracingProperties(physical_device_info_);

        // capture does contain the call, bail out
        if (capture_ray_properties_ == std::nullopt || replay_ray_properties_ == std::nullopt)
        {
            GFXRECON_LOG_ERROR_ONCE(
                "VulkanAddressReplacer::ProcessCmdTraceRays: missing "
                "VkPhysicalDeviceRayTracingPipelinePropertiesKHR for capture/replay, cannot proceed");
            return;
        }
    }

    std::unordered_set<VkBuffer> buffer_set;
    auto address_remap = [&address_tracker, &buffer_set](VkStridedDeviceAddressRegionKHR* address_region) {
        if (address_region->size > 0)
        {
            auto buffer_info = address_tracker.GetBufferByCaptureDeviceAddress(address_region->deviceAddress);
            GFXRECON_ASSERT(buffer_info != nullptr);

            if (buffer_info->replay_address != 0)
            {
                // keep track of used handles
                buffer_set.insert(buffer_info->handle);

                uint64_t offset = address_region->deviceAddress - buffer_info->capture_address;

                // in-place address-remap
                address_region->deviceAddress = buffer_info->replay_address + offset;
                return true;
            }
        }
        return false;
    };

    // in-place remap: capture-addresses -> replay-addresses
    address_remap(raygen_sbt);
    address_remap(miss_sbt);
    address_remap(hit_sbt);
    address_remap(callable_sbt);

    if (!valid_sbt_alignment_ || !valid_group_handles)
    {
        // mark injected commands
        MarkInjectedCommandsHelper mark_injected_commands_helper;

        if (pipeline_sbt_ == VK_NULL_HANDLE)
        {
            if (!init_pipeline())
            {
                GFXRECON_LOG_WARNING_ONCE("ProcessCmdTraceRays: internal pipeline-creation failed")
                return;
            }
        }

        // prepare linear hashmap
        hashmap_sbt_.clear();

        for (const auto& [lhs, rhs] : group_handle_map)
        {
            hashmap_sbt_.put(lhs, rhs);
        }

        // get a context for this command-buffer
        auto& pipeline_context_sbt = pipeline_context_map_[command_buffer_info->handle].emplace_back();

        if (!create_buffer(pipeline_context_sbt.storage_array,
                           hashmap_sbt_.get_storage(nullptr),
                           0,
                           0,
                           true,
                           "GFXR VulkanAddressReplacer pipeline_context_sbt.hashmap_storage"))
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: hashmap-storage-buffer creation failed");
        }
        hashmap_sbt_.get_storage(pipeline_context_sbt.storage_array.mapped_data);

        // input-handles
        constexpr uint32_t max_num_handles = 512;
        if (!create_buffer(pipeline_context_sbt.input_handle_buffer,
                           max_num_handles * sizeof(VkDeviceAddress),
                           0,
                           0,
                           true,
                           "GFXR VulkanAddressReplacer pipeline_context_sbt.input_handle_buffer"))
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: input-handle-buffer creation failed");
        }
        auto input_addresses = reinterpret_cast<VkDeviceAddress*>(pipeline_context_sbt.input_handle_buffer.mapped_data);

        std::unordered_map<const VkStridedDeviceAddressRegionKHR*, uint32_t> num_addresses_map;
        uint32_t                                                             num_addresses = 0;

        {
            const auto handle_size_aligned = static_cast<uint32_t>(util::aligned_value(
                capture_ray_properties_->shaderGroupHandleSize, capture_ray_properties_->shaderGroupHandleAlignment));

            for (const auto& region : { raygen_sbt, miss_sbt, hit_sbt, callable_sbt })
            {
                if (region != nullptr && region->size != 0 && region->stride != 0)
                {
                    // NOTE: if region->stride > capture_handle_size, the excess-data is considered a shaderRecord
                    num_addresses_map[region] = region->size / handle_size_aligned;

                    // populate input-addresses, which are handles to replace and shaderRecord data to pass-through
                    for (uint32_t offset = 0; offset < region->size; offset += handle_size_aligned)
                    {
                        input_addresses[num_addresses++] = region->deviceAddress + offset;
                    }
                }
            }
        }

        replacer_params_sbt_t replacer_params = {};
        replacer_params.hashmap.storage       = pipeline_context_sbt.storage_array.device_address;
        replacer_params.hashmap.size          = hashmap_sbt_.size();
        replacer_params.hashmap.capacity      = hashmap_sbt_.capacity();

        replacer_params.input_handles = pipeline_context_sbt.input_handle_buffer.device_address;
        replacer_params.num_handles   = num_addresses;

        if (valid_sbt_alignment_)
        {
            GFXRECON_LOG_INFO_ONCE("VulkanAddressReplacer::ProcessCmdTraceRays: Replay is adjusting "
                                   "raytracing shader-group-handles");

            // rewrite group-handles in-place
            replacer_params.output_handles = replacer_params.input_handles;

            // pre memory-barrier
            for (const auto& buf : buffer_set)
            {
                barrier(command_buffer_info->handle,
                        buf,
                        VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR,
                        VK_ACCESS_SHADER_READ_BIT,
                        VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                        VK_ACCESS_SHADER_WRITE_BIT);
            }
        }
        else
        {
            GFXRECON_LOG_INFO_ONCE("VulkanAddressReplacer::ProcessCmdTraceRays: Replay is adjusting "
                                   "raytracing shader-binding-tables using shadow-buffers");

            // output-handles
            if (!create_buffer(pipeline_context_sbt.output_handle_buffer,
                               max_num_handles * sizeof(VkDeviceAddress),
                               0,
                               0,
                               true,
                               "GFXR VulkanAddressReplacer pipeline_context_sbt.output_handle_buffer"))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: input-handle-buffer creation failed");
                return;
            }
            // output to shadow-sbt-buffer
            replacer_params.output_handles = pipeline_context_sbt.output_handle_buffer.device_address;

            // find/create shadow-SBT-buffer
            uint32_t sbt_offset         = 0;
            auto&    shadow_buf_context = shadow_sbt_map_[command_buffer_info->handle];

            const auto handle_size_aligned = static_cast<uint32_t>(util::aligned_value(
                replay_ray_properties_->shaderGroupHandleSize, replay_ray_properties_->shaderGroupHandleAlignment));

            for (auto& region : { raygen_sbt, miss_sbt, hit_sbt, callable_sbt })
            {
                if (region != nullptr && region->size != 0 && region->stride != 0)
                {
                    uint32_t num_handles = num_addresses_map[region];
                    auto     group_size  = static_cast<uint32_t>(util::aligned_value(
                        num_handles * handle_size_aligned, replay_ray_properties_->shaderGroupBaseAlignment));

                    // increase group-size/stride, if required
                    region->size   = std::max<VkDeviceSize>(group_size, region->size);
                    region->stride = std::max<VkDeviceSize>(handle_size_aligned, region->stride);

                    sbt_offset += region->size;
                }
            }
            // raygen: stride == size
            raygen_sbt->size = raygen_sbt->stride =
                util::aligned_value(raygen_sbt->stride, replay_ray_properties_->shaderGroupBaseAlignment);

            if (!create_buffer(shadow_buf_context,
                               sbt_offset,
                               VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR,
                               replay_ray_properties_->shaderGroupBaseAlignment,
                               true,
                               "GFXR VulkanAddressReplacer shadow-buffer: shader-binding-table"))
            {
                GFXRECON_LOG_ERROR("VulkanAddressReplacer: shadow shader-binding-table creation failed");
                return;
            }

            auto output_addresses =
                reinterpret_cast<VkDeviceAddress*>(pipeline_context_sbt.output_handle_buffer.mapped_data);
            uint32_t out_index = 0;
            sbt_offset         = 0;
            for (auto& region : { raygen_sbt, miss_sbt, hit_sbt, callable_sbt })
            {
                if (region != nullptr && region->size != 0 && region->stride != 0)
                {
                    uint32_t num_handles = num_addresses_map[region];

                    // assign shadow-sbt-address
                    region->deviceAddress = shadow_buf_context.device_address + sbt_offset;

                    for (uint32_t i = 0; i < num_handles; ++i)
                    {
                        output_addresses[out_index++] = region->deviceAddress + i * handle_size_aligned;
                    }
                    sbt_offset += region->size;
                }
            }
            GFXRECON_ASSERT(out_index == num_addresses);
        }

        device_table_->CmdBindPipeline(command_buffer_info->handle, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_sbt_);

        // NOTE: using push-constants here requires us to re-establish the previous data, if any
        device_table_->CmdPushConstants(command_buffer_info->handle,
                                        pipeline_layout_,
                                        VK_SHADER_STAGE_COMPUTE_BIT,
                                        0,
                                        sizeof(replacer_params_sbt_t),
                                        &replacer_params);
        // run a single workgroup
        constexpr uint32_t wg_size = 32;
        device_table_->CmdDispatch(
            command_buffer_info->handle, util::div_up(replacer_params.num_handles, wg_size), 1, 1);

        // post memory-barrier
        for (const auto& buf : buffer_set)
        {
            barrier(command_buffer_info->handle,
                    buf,
                    VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                    VK_ACCESS_SHADER_WRITE_BIT,
                    VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR,
                    VK_ACCESS_SHADER_READ_BIT);
        }

        // set previous compute-pipeline, if any
        if (command_buffer_info->bound_pipelines.count(VK_PIPELINE_BIND_POINT_COMPUTE))
        {
            const auto* previous_pipeline = object_table_->GetVkPipelineInfo(
                command_buffer_info->bound_pipelines.at(VK_PIPELINE_BIND_POINT_COMPUTE));
            GFXRECON_ASSERT(previous_pipeline);
            if (previous_pipeline != nullptr)
            {
                GFXRECON_LOG_INFO_ONCE(
                    "VulkanAddressReplacer::ProcessCmdTraceRays: Replay is injecting compute-dispatches, "
                    "originally bound compute-pipelines are restored.");
                device_table_->CmdBindPipeline(
                    command_buffer_info->handle, VK_PIPELINE_BIND_POINT_COMPUTE, previous_pipeline->handle);
            }
        }

        // set previous push-constant data, if any
        if (!command_buffer_info->push_constant_data.empty())
        {
            device_table_->CmdPushConstants(command_buffer_info->handle,
                                            command_buffer_info->push_constant_pipeline_layout,
                                            command_buffer_info->push_constant_stage_flags,
                                            0,
                                            command_buffer_info->push_constant_data.size(),
                                            command_buffer_info->push_constant_data.data());
        }
    } // !valid_sbt_alignment_ || !valid_group_handles
}

void VulkanAddressReplacer::ProcessCmdBuildAccelerationStructuresKHR(
    const VulkanCommandBufferInfo*               command_buffer_info,
    uint32_t                                     info_count,
    VkAccelerationStructureBuildGeometryInfoKHR* build_geometry_infos,
    VkAccelerationStructureBuildRangeInfoKHR**   build_range_infos,
    const VulkanDeviceAddressTracker&            address_tracker)
{
    GFXRECON_ASSERT(device_table_ != nullptr);

    bool force_replace = false;

    std::unordered_set<VkBuffer> buffer_set;
    auto address_remap = [&address_tracker, &buffer_set](VkDeviceAddress& capture_address) -> bool {
        auto buffer_info = address_tracker.GetBufferByCaptureDeviceAddress(capture_address);

        // skip over null-addresses
        if (capture_address == 0)
        {
            return false;
        }

        if (buffer_info != nullptr && buffer_info->replay_address != 0)
        {
            // keep track of used handles
            buffer_set.insert(buffer_info->handle);

            if (buffer_info->capture_address != buffer_info->replay_address)
            {
                uint64_t offset = capture_address - buffer_info->capture_address;

                // in-place address-remap via const-cast
                capture_address = buffer_info->replay_address + offset;
                return true;
            }
        }
        return false;
    };

    std::vector<VkDeviceAddress> addresses_to_replace;

    for (uint32_t i = 0; i < info_count; ++i)
    {
        auto&       build_geometry_info = build_geometry_infos[i];
        const auto* range_infos         = build_range_infos[i];

        const VulkanBufferInfo* scratch_buffer_info =
            address_tracker.GetBufferByCaptureDeviceAddress(build_geometry_info.scratchData.deviceAddress);

        // check/correct scratch-address
        address_remap(build_geometry_info.scratchData.deviceAddress);

        // check capture/replay acceleration-structure buffer-sizes
        {
            VkAccelerationStructureBuildSizesInfoKHR build_size_info = {};
            build_size_info.sType = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR;

            {
                std::vector<uint32_t> primitive_counts(build_geometry_info.geometryCount);
                for (uint32_t j = 0; j < build_geometry_info.geometryCount; ++j)
                {
                    primitive_counts[j] = range_infos[j].primitiveCount;
                }

                MarkInjectedCommandsHelper mark_injected_commands_helper;
                device_table_->GetAccelerationStructureBuildSizesKHR(device_,
                                                                     VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR,
                                                                     &build_geometry_info,
                                                                     primitive_counts.data(),
                                                                     &build_size_info);
            }

            bool as_buffer_usable = false;

            // retrieve VkAccelerationStructureKHR -> VkBuffer -> check/correct size
            auto* acceleration_structure_info =
                address_tracker.GetAccelerationStructureByHandle(build_geometry_info.dstAccelerationStructure);
            if (acceleration_structure_info != nullptr)
            {
                auto* buffer_info = address_tracker.GetBufferByHandle(acceleration_structure_info->buffer);
                as_buffer_usable =
                    buffer_info != nullptr && buffer_info->size >= build_size_info.accelerationStructureSize;
            }

            // determine required size of scratch-buffer
            uint32_t scratch_size      = build_geometry_info.mode == VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR
                                             ? build_size_info.buildScratchSize
                                             : build_size_info.updateScratchSize;
            bool scratch_buffer_usable = scratch_buffer_info != nullptr && scratch_buffer_info->size >= scratch_size &&
                                         (scratch_buffer_info->usage & VK_BUFFER_USAGE_STORAGE_BUFFER_BIT);

            if (!as_buffer_usable || !scratch_buffer_usable)
            {
                MarkInjectedCommandsHelper mark_injected_commands_helper;
                GFXRECON_LOG_INFO_ONCE(
                    "VulkanAddressReplacer::ProcessCmdBuildAccelerationStructuresKHR: Replay is adjusting "
                    "acceleration-structures using shadow-structures and -buffers");

                // now definitely requiring address-replacement
                force_replace = true;

                auto& replacement_as = shadow_as_map_[build_geometry_info.dstAccelerationStructure];

                if (replacement_as.handle == VK_NULL_HANDLE)
                {
                    if (as_buffer_usable)
                    {
                        replacement_as.handle = build_geometry_info.dstAccelerationStructure;
                        auto accel_info       = address_tracker.GetAccelerationStructureByHandle(
                            build_geometry_info.dstAccelerationStructure);
                        GFXRECON_ASSERT(accel_info != nullptr && accel_info->replay_address != 0);
                        replacement_as.address = accel_info->replay_address;
                    }
                    else
                    {
                        auto ret = create_acceleration_asset(replacement_as,
                                                             build_geometry_info.type,
                                                             build_size_info.accelerationStructureSize,
                                                             scratch_size);
                        if (!ret)
                        {
                            GFXRECON_LOG_ERROR("ProcessCmdBuildAccelerationStructuresKHR: creation of shadow "
                                               "acceleration-structure failed");
                        }
                    }
                }

                // check/correct source acceleration-structure
                swap_acceleration_structure_handle(build_geometry_info.srcAccelerationStructure);

                // hot swap acceleration-structure handle
                build_geometry_info.dstAccelerationStructure = replacement_as.handle;

                // acceleration-structure properties not populated yet, check if we missed it
                if (!replay_acceleration_structure_properties_)
                {
                    SetRaytracingProperties(physical_device_info_);

                    // capture did not contain the call, inject
                    if (!replay_acceleration_structure_properties_)
                    {
                        VkPhysicalDeviceAccelerationStructurePropertiesKHR as_properties = {};
                        as_properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR;
                        as_properties.pNext = nullptr;

                        VkPhysicalDeviceProperties2 physical_device_properties = {};
                        physical_device_properties.sType = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2;
                        physical_device_properties.pNext = &as_properties;
                        get_physical_device_properties_fn_(physical_device_info_->handle, &physical_device_properties);
                        replay_acceleration_structure_properties_ = as_properties;
                    }
                }

                if (!scratch_buffer_usable)
                {
                    // create a replacement scratch-buffer
                    if (!create_buffer(
                            replacement_as.scratch,
                            scratch_size,
                            0,
                            replay_acceleration_structure_properties_->minAccelerationStructureScratchOffsetAlignment,
                            false,
                            "GFXR VulkanAddressReplacer::acceleration_structure_asset_t::scratch"))
                    {
                        GFXRECON_LOG_ERROR("ProcessCmdBuildAccelerationStructuresKHR: scratch-buffer creation failed");
                        return;
                    }

                    // hot swap scratch-buffer
                    build_geometry_info.scratchData.deviceAddress = replacement_as.scratch.device_address;
                }
            }
        }

        for (uint32_t j = 0; j < build_geometry_info.geometryCount; ++j)
        {
            auto geometry = const_cast<VkAccelerationStructureGeometryKHR*>(build_geometry_info.pGeometries != nullptr
                                                                                ? build_geometry_info.pGeometries + j
                                                                                : build_geometry_info.ppGeometries[j]);
            switch (geometry->geometryType)
            {
                case VK_GEOMETRY_TYPE_TRIANGLES_KHR:
                {
                    auto& triangles = geometry->geometry.triangles;
                    address_remap(triangles.vertexData.deviceAddress);
                    address_remap(triangles.indexData.deviceAddress);
                    address_remap(triangles.transformData.deviceAddress);
                    break;
                }
                case VK_GEOMETRY_TYPE_AABBS_KHR:
                {
                    auto& aabbs = geometry->geometry.aabbs;
                    address_remap(aabbs.data.deviceAddress);
                    break;
                }
                case VK_GEOMETRY_TYPE_INSTANCES_KHR:
                {
                    auto& instances = geometry->geometry.instances;

                    // check if replacement is actually required
                    if (address_remap(instances.data.deviceAddress))
                    {
                        // replace VkAccelerationStructureInstanceKHR::accelerationStructureReference inside buffer
                        for (uint32_t k = 0; k < range_infos[j].primitiveCount; ++k)
                        {
                            VkDeviceAddress accel_structure_reference =
                                instances.data.deviceAddress + k * sizeof(VkAccelerationStructureInstanceKHR) +
                                offsetof(VkAccelerationStructureInstanceKHR, accelerationStructureReference);
                            addresses_to_replace.push_back(accel_structure_reference);
                        }
                    }

                    break;
                }
                default:
                    GFXRECON_LOG_ERROR(
                        "OverrideCmdBuildAccelerationStructuresKHR: unhandled case in switch-statement: %d",
                        geometry->geometryType);
                    break;
            }
        }
    }

    if (!addresses_to_replace.empty())
    {
        // prepare linear hashmap
        storage_bda_binary_.clear();
        auto acceleration_structure_map = address_tracker.GetAccelerationStructureDeviceAddressMap();
        for (const auto& [capture_address, replay_address] : acceleration_structure_map)
        {
            auto* accel_info = address_tracker.GetAccelerationStructureByCaptureDeviceAddress(capture_address);
            GFXRECON_ASSERT(accel_info != nullptr);

            if (force_replace || capture_address != replay_address)
            {
                auto new_address = replay_address;

                // extra look-up required for potentially replaced AS
                if (accel_info != nullptr)
                {
                    auto shadow_as_it = shadow_as_map_.find(accel_info->handle);
                    if (shadow_as_it != shadow_as_map_.end())
                    {
                        new_address = shadow_as_it->second.address;
                    }
                }

                // store addresses we will need to replace
                GFXRECON_ASSERT(new_address != 0);
                storage_bda_binary_.push_back({ capture_address, new_address });
            }
        }

        run_compute_replace(command_buffer_info,
                            addresses_to_replace.data(),
                            addresses_to_replace.size(),
                            address_tracker,
                            VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR);
    }
}

void VulkanAddressReplacer::ProcessCmdCopyAccelerationStructuresKHR(
    VkCopyAccelerationStructureInfoKHR* info, const decode::VulkanDeviceAddressTracker& address_tracker)
{
    if (info != nullptr)
    {
        VkDeviceSize compact_size    = 0;
        auto         compact_size_it = as_compact_sizes_.find(info->src);
        if (compact_size_it != as_compact_sizes_.end())
        {
            compact_size = compact_size_it->second;
            as_compact_sizes_.erase(info->src);

            auto* as_info = address_tracker.GetAccelerationStructureByHandle(info->dst);
            GFXRECON_ASSERT(as_info != nullptr);
            if (as_info != nullptr)
            {
                auto* buffer_info = address_tracker.GetBufferByHandle(as_info->buffer);
                GFXRECON_ASSERT(buffer_info != nullptr);
                if (buffer_info != nullptr)
                {
                    if (buffer_info->size < compact_size)
                    {
                        // TODO: need replacement AS
                    }
                }
            }
        }

        // correct in-place
        swap_acceleration_structure_handle(info->src);
        swap_acceleration_structure_handle(info->dst);
    }
}

void VulkanAddressReplacer::ProcessCmdWriteAccelerationStructuresPropertiesKHR(
    uint32_t                    count,
    VkAccelerationStructureKHR* acceleration_structures,
    VkQueryType                 query_type,
    VkQueryPool                 pool,
    uint32_t                    first_query)
{
    for (uint32_t i = 0; i < count; ++i)
    {
        auto shadow_as_it = shadow_as_map_.find(acceleration_structures[i]);
        if (shadow_as_it != shadow_as_map_.end())
        {
            acceleration_structures[i] = shadow_as_it->second.handle;
        }

        if (query_type == VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR)
        {
            // read back compacted size later
            as_compact_queries_[pool][acceleration_structures[i]] = first_query + i;
        }
    }
}

void VulkanAddressReplacer::ProcessUpdateDescriptorSets(uint32_t              descriptor_write_count,
                                                        VkWriteDescriptorSet* descriptor_writes,
                                                        uint32_t              descriptor_copy_count,
                                                        VkCopyDescriptorSet*  descriptor_copies)
{
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_copy_count);
    GFXRECON_UNREFERENCED_PARAMETER(descriptor_copies);

    // bail out if we're not tracking any shadow acceleration-structures
    if (shadow_as_map_.empty())
    {
        return;
    }

    for (uint32_t i = 0; i < descriptor_write_count; ++i)
    {
        VkWriteDescriptorSet& write = descriptor_writes[i];

        if (write.descriptorType != VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
        {
            continue;
        }

        if (auto* write_as = graphics::vulkan_struct_get_pnext<VkWriteDescriptorSetAccelerationStructureKHR>(&write))
        {
            for (uint32_t j = 0; j < write_as->accelerationStructureCount; ++j)
            {
                auto acceleration_structure_it = shadow_as_map_.find(write_as->pAccelerationStructures[j]);
                if (acceleration_structure_it != shadow_as_map_.end())
                {
                    // we found an existing replacement-structure -> swap
                    auto* out_array = const_cast<VkAccelerationStructureKHR*>(write_as->pAccelerationStructures);
                    out_array[j]    = acceleration_structure_it->second.handle;

                    GFXRECON_LOG_INFO_ONCE("VulkanAddressReplacer::ProcessUpdateDescriptorSets: Replay adjusted "
                                           "AccelerationStructure handles")
                }
            }
        }
    }
}

void VulkanAddressReplacer::ProcessGetQueryPoolResults(VkDevice           device,
                                                       VkQueryPool        query_pool,
                                                       uint32_t           firstQuery,
                                                       uint32_t           queryCount,
                                                       size_t             dataSize,
                                                       void*              pData,
                                                       VkDeviceSize       stride,
                                                       VkQueryResultFlags flags)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(firstQuery);
    GFXRECON_UNREFERENCED_PARAMETER(queryCount);
    GFXRECON_UNREFERENCED_PARAMETER(dataSize);

    // intercept queries containing acceleration-structure compaction-sizes
    if (!as_compact_queries_.empty() && stride == sizeof(VkDeviceSize))
    {
        bool is_synced = flags & VK_QUERY_RESULT_WAIT_BIT;

        auto it = as_compact_queries_.find(query_pool);
        if (is_synced && it != as_compact_queries_.end())
        {
            // assuming post-processing here, pData was already written
            auto* result_array = reinterpret_cast<const VkDeviceSize*>(pData);

            for (const auto& [as, query_index] : it->second)
            {
                as_compact_sizes_[as] = result_array[query_index];
            }
        }
        as_compact_queries_.erase(query_pool);
    }
}

void VulkanAddressReplacer::ProcessBuildVulkanAccelerationStructuresMetaCommand(
    uint32_t                                     info_count,
    VkAccelerationStructureBuildGeometryInfoKHR* geometry_infos,
    VkAccelerationStructureBuildRangeInfoKHR**   range_infos,
    const decode::VulkanDeviceAddressTracker&    address_tracker)
{
    if (info_count > 0 && init_queue_assets())
    {
        // reset/submit/sync command-buffer
        QueueSubmitHelper queue_submit_helper(
            device_table_, device_, submit_asset_.command_buffer, queue_, submit_asset_.fence);

        // dummy-wrapper
        VulkanCommandBufferInfo command_buffer_info = {};
        command_buffer_info.handle                  = submit_asset_.command_buffer;
        ProcessCmdBuildAccelerationStructuresKHR(
            &command_buffer_info, info_count, geometry_infos, range_infos, address_tracker);

        // issue build-command
        MarkInjectedCommandsHelper mark_injected_commands_helper;
        device_table_->CmdBuildAccelerationStructuresKHR(
            submit_asset_.command_buffer, info_count, geometry_infos, range_infos);
    }
}

void VulkanAddressReplacer::ProcessCopyVulkanAccelerationStructuresMetaCommand(
    uint32_t                                  info_count,
    VkCopyAccelerationStructureInfoKHR*       copy_infos,
    const decode::VulkanDeviceAddressTracker& address_tracker)
{
    if (copy_infos != nullptr && info_count > 0 && init_queue_assets())
    {
        // reset/submit/sync command-buffer
        QueueSubmitHelper queue_submit_helper(
            device_table_, device_, submit_asset_.command_buffer, queue_, submit_asset_.fence);

        for (uint32_t i = 0; i < info_count; ++i)
        {
            auto* copy_info = copy_infos + i;

            if (copy_info->src != VK_NULL_HANDLE && copy_info->dst != VK_NULL_HANDLE)
            {
                ProcessCmdCopyAccelerationStructuresKHR(copy_info, address_tracker);

                // issue copy command
                MarkInjectedCommandsHelper mark_injected_commands_helper;
                device_table_->CmdCopyAccelerationStructureKHR(submit_asset_.command_buffer, copy_info);
            }
            else
            {
                GFXRECON_LOG_ERROR("ProcessCopyVulkanAccelerationStructuresMetaCommand: missing handles");
            }
        }
    }
}

void VulkanAddressReplacer::ProcessVulkanAccelerationStructuresWritePropertiesMetaCommand(
    VkQueryType query_type, VkAccelerationStructureKHR acceleration_structure)
{
    if (init_queue_assets())
    {
        // reset/submit/sync command-buffer
        QueueSubmitHelper queue_submit_helper(
            device_table_, device_, submit_asset_.command_buffer, queue_, submit_asset_.fence);

        ProcessCmdWriteAccelerationStructuresPropertiesKHR(1, &acceleration_structure, query_type, query_pool_, 0);

        // issue vkCmdResetQueryPool and vkCmdWriteAccelerationStructuresPropertiesKHR
        MarkInjectedCommandsHelper mark_injected_commands_helper;
        device_table_->CmdResetQueryPool(submit_asset_.command_buffer, query_pool_, 0, 1);
        device_table_->CmdWriteAccelerationStructuresPropertiesKHR(
            submit_asset_.command_buffer, 1, &acceleration_structure, query_type, query_pool_, 0);
    }

    VkDeviceSize compact_size = 0;

    // the above command-buffer is already synced here, retrieve result using vkGetQueryPoolResults
    MarkInjectedCommandsHelper mark_injected_commands_helper;
    device_table_->GetQueryPoolResults(device_,
                                       query_pool_,
                                       0,
                                       1,
                                       sizeof(VkDeviceSize),
                                       &compact_size,
                                       sizeof(VkDeviceSize),
                                       VK_QUERY_RESULT_64_BIT | VK_QUERY_RESULT_WAIT_BIT);

    // apply usual post-processing of queries
    ProcessGetQueryPoolResults(device_,
                               query_pool_,
                               0,
                               1,
                               sizeof(VkDeviceSize),
                               &compact_size,
                               sizeof(VkDeviceSize),
                               VK_QUERY_RESULT_64_BIT | VK_QUERY_RESULT_WAIT_BIT);
}

bool VulkanAddressReplacer::init_pipeline()
{
    if (pipeline_sbt_ != VK_NULL_HANDLE)
    {
        // assume already initialized
        return true;
    }
    VkPushConstantRange push_constant_range = {};
    push_constant_range.stageFlags          = VK_SHADER_STAGE_COMPUTE_BIT;
    push_constant_range.offset              = 0;
    push_constant_range.size                = std::max(sizeof(replacer_params_sbt_t), sizeof(replacer_params_bda_t));

    VkPipelineLayoutCreateInfo pipeline_layout_info = {};
    pipeline_layout_info.sType                      = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipeline_layout_info.pNext                      = nullptr;
    pipeline_layout_info.flags                      = 0;
    pipeline_layout_info.setLayoutCount             = 0;
    pipeline_layout_info.pSetLayouts                = nullptr;
    pipeline_layout_info.pushConstantRangeCount     = 1;
    pipeline_layout_info.pPushConstantRanges        = &push_constant_range;

    VkResult result = device_table_->CreatePipelineLayout(device_, &pipeline_layout_info, nullptr, &pipeline_layout_);

    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_FATAL("VulkanAddressReplacer: failed in vkCreatePipelineLayout");
    }

    auto create_pipeline = [this](VkPipelineLayout layout, const auto& spirv, VkPipeline& out_pipeline) -> VkResult {
        using elem_t                                       = typename std::decay_t<decltype(spirv)>::value_type;
        VkShaderModule           compute_module            = VK_NULL_HANDLE;
        VkShaderModuleCreateInfo shader_module_create_info = {};
        shader_module_create_info.sType                    = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
        shader_module_create_info.pNext                    = VK_NULL_HANDLE;
        shader_module_create_info.flags                    = 0;
        shader_module_create_info.codeSize                 = spirv.size() * sizeof(elem_t);
        shader_module_create_info.pCode                    = reinterpret_cast<const uint32_t*>(spirv.data());

        VkResult result =
            device_table_->CreateShaderModule(device_, &shader_module_create_info, nullptr, &compute_module);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_FATAL("VulkanAddressReplacer: failed in vkCreateShaderModule");
            return result;
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
        pipeline_create_info.layout                      = layout;
        pipeline_create_info.stage                       = stage_info;

        result = device_table_->CreateComputePipelines(
            device_, VK_NULL_HANDLE, 1, &pipeline_create_info, VK_NULL_HANDLE, &out_pipeline);

        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: pipeline creation failed");
        }

        if (set_debug_utils_object_name_fn_)
        {
            VkDebugUtilsObjectNameInfoEXT object_name_info = {};
            object_name_info.sType                         = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
            object_name_info.objectType                    = VK_OBJECT_TYPE_PIPELINE;
            object_name_info.objectHandle                  = VK_HANDLE_TO_UINT64(out_pipeline);
            object_name_info.pObjectName                   = "VulkanAddressReplacer internal pipeline";
            set_debug_utils_object_name_fn_(device_, &object_name_info);
        }

        if (compute_module != VK_NULL_HANDLE)
        {
            device_table_->DestroyShaderModule(device_, compute_module, nullptr);
        }
        return result;
    };

    // create SBT pipeline (hashmap search)
    if (create_pipeline(pipeline_layout_, g_replacer_sbt_comp, pipeline_sbt_) != VK_SUCCESS)
    {
        return false;
    }

    // create BDA pipeline (binary search)
    if (create_pipeline(pipeline_layout_, g_replacer_bda_binary_comp, pipeline_bda_) != VK_SUCCESS)
    {
        return false;
    }

    // create rehashing pipeline
    if (create_pipeline(pipeline_layout_, g_replacer_rehash_comp, pipeline_bda_rehash_) != VK_SUCCESS)
    {
        return false;
    }
    return true;
}

bool VulkanAddressReplacer::init_queue_assets()
{
    if (queue_ != VK_NULL_HANDLE)
    {
        return true;
    };

    VkCommandPoolCreateInfo create_info = {};
    create_info.sType                   = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    create_info.pNext                   = nullptr;
    create_info.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    create_info.queueFamilyIndex        = 0;

    VkResult result = device_table_->CreateCommandPool(device_, &create_info, nullptr, &command_pool_);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("VulkanAddressReplacer: internal command-pool creation failed");
        return false;
    }

    VkQueryPoolCreateInfo pool_info;
    pool_info.sType              = VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO;
    pool_info.pNext              = nullptr;
    pool_info.flags              = 0;
    pool_info.queryType          = VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR;
    pool_info.queryCount         = 1;
    pool_info.pipelineStatistics = 0;
    result                       = device_table_->CreateQueryPool(device_, &pool_info, nullptr, &query_pool_);
    if (result != VK_SUCCESS)
    {
        GFXRECON_LOG_ERROR("VulkanAddressReplacer: internal query-pool creation failed");
        return false;
    }

    device_table_->GetDeviceQueue(device_, 0, 0, &queue_);
    GFXRECON_ASSERT(queue_ != VK_NULL_HANDLE);

    bool submit_asset_created = create_submit_asset(submit_asset_);
    return queue_ != VK_NULL_HANDLE && submit_asset_created;
}

bool VulkanAddressReplacer::create_buffer(VulkanAddressReplacer::buffer_context_t& buffer_context,
                                          size_t                                   num_bytes,
                                          uint32_t                                 usage_flags,
                                          uint32_t                                 min_alignment,
                                          bool                                     use_host_mem,
                                          const std::string&                       name)
{
    GFXRECON_ASSERT(util::is_pow_2(min_alignment));

    // 4kB min-size
    constexpr uint32_t min_buffer_size = 1 << 12;
    num_bytes = std::max<uint32_t>(util::aligned_value(num_bytes, min_alignment), min_buffer_size);

    // nothing to do
    if (num_bytes <= buffer_context.num_bytes)
    {
        return true;
    }

    // free previous resources
    buffer_context                    = {};
    buffer_context.resource_allocator = resource_allocator_;
    buffer_context.num_bytes          = num_bytes;
    buffer_context.name               = name;

    VkBufferCreateInfo buffer_create_info = {};
    buffer_create_info.sType              = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    buffer_create_info.usage =
        VK_BUFFER_USAGE_STORAGE_BUFFER_BIT | VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT | usage_flags;
    buffer_create_info.sharingMode           = VK_SHARING_MODE_EXCLUSIVE;
    buffer_create_info.queueFamilyIndexCount = 0;
    buffer_create_info.size                  = num_bytes;

    VkResult result = resource_allocator_->CreateBufferDirect(
        &buffer_create_info, nullptr, &buffer_context.buffer, &buffer_context.allocator_data);
    if (result != VK_SUCCESS)
    {
        return false;
    }

    VkMemoryRequirements memory_requirements;
    device_table_->GetBufferMemoryRequirements(device_, buffer_context.buffer, &memory_requirements);

    VkMemoryPropertyFlags memory_property_flags =
        use_host_mem ? VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_CACHED_BIT
                     : VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT;

    uint32_t memory_type_index =
        graphics::GetMemoryTypeIndex(memory_properties_, memory_requirements.memoryTypeBits, memory_property_flags);

    if (memory_type_index == std::numeric_limits<uint32_t>::max() && use_host_mem)
    {
        /* fallback to coherent */
        memory_type_index =
            graphics::GetMemoryTypeIndex(memory_properties_,
                                         memory_requirements.memoryTypeBits,
                                         VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
    }

    GFXRECON_ASSERT(memory_type_index != std::numeric_limits<uint32_t>::max());

    VkMemoryAllocateInfo alloc_info = {};
    alloc_info.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    alloc_info.allocationSize       = memory_requirements.size;
    alloc_info.memoryTypeIndex      = memory_type_index;

    VkMemoryAllocateFlagsInfo alloc_flags_info = {};
    alloc_flags_info.sType                     = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO;
    alloc_flags_info.flags                     = VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT;
    alloc_info.pNext                           = &alloc_flags_info;

    result = resource_allocator_->AllocateMemoryDirect(
        &alloc_info, nullptr, &buffer_context.device_memory, &buffer_context.memory_data);

    if (result != VK_SUCCESS)
    {
        return false;
    }

    result = resource_allocator_->BindBufferMemory(buffer_context.buffer,
                                                   buffer_context.device_memory,
                                                   0,
                                                   buffer_context.allocator_data,
                                                   buffer_context.memory_data,
                                                   &memory_property_flags);
    if (result != VK_SUCCESS)
    {
        return false;
    }

    // get device-address
    VkBufferDeviceAddressInfo address_info = {};
    address_info.sType                     = VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO;
    address_info.buffer                    = buffer_context.buffer;
    buffer_context.device_address          = get_device_address_fn_(device_, &address_info);
    GFXRECON_ASSERT(buffer_context.device_address != 0);

    // ensure alignment for returned address
    auto aligned_address = util::aligned_value(buffer_context.device_address, min_alignment);
    GFXRECON_ASSERT(!min_alignment || !(aligned_address % min_alignment));
    auto offset                   = aligned_address - buffer_context.device_address;
    buffer_context.device_address = aligned_address;

    if (set_debug_utils_object_name_fn_)
    {
        VkDebugUtilsObjectNameInfoEXT object_name_info = {};
        object_name_info.sType                         = VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT;
        object_name_info.objectType                    = VK_OBJECT_TYPE_BUFFER;
        object_name_info.objectHandle                  = VK_HANDLE_TO_UINT64(buffer_context.buffer);
        object_name_info.pObjectName                   = name.c_str();
        set_debug_utils_object_name_fn_(device_, &object_name_info);
    }

    if (use_host_mem)
    {
        // map buffer
        result = resource_allocator_->MapResourceMemoryDirect(
            VK_WHOLE_SIZE, 0, &buffer_context.mapped_data, buffer_context.allocator_data);
        buffer_context.mapped_data = static_cast<uint8_t*>(buffer_context.mapped_data) + offset;
        return result == VK_SUCCESS;
    }
    return true;
}

void VulkanAddressReplacer::barrier(VkCommandBuffer      command_buffer,
                                    VkBuffer             buffer,
                                    VkPipelineStageFlags src_stage,
                                    VkAccessFlags        src_access,
                                    VkPipelineStageFlags dst_stage,
                                    VkAccessFlags        dst_access)
{
    VkBufferMemoryBarrier barrier = {};
    barrier.sType                 = VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER;
    barrier.buffer                = buffer;
    barrier.offset                = 0;
    barrier.size                  = VK_WHOLE_SIZE;
    barrier.srcQueueFamilyIndex = barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.srcAccessMask                                     = src_access;
    barrier.dstAccessMask                                     = dst_access;

    device_table_->CmdPipelineBarrier(
        command_buffer, src_stage, dst_stage, VkDependencyFlags(0), 0, nullptr, 1, &barrier, 0, nullptr);
}

bool VulkanAddressReplacer::swap_acceleration_structure_handle(VkAccelerationStructureKHR& handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        auto shadow_as_it = shadow_as_map_.find(handle);
        if (shadow_as_it != shadow_as_map_.end())
        {
            handle = shadow_as_it->second.handle;
            return true;
        }
    }
    return false;
}

void VulkanAddressReplacer::DestroyShadowResources(VkAccelerationStructureKHR handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        auto remove_shadow_as_it = shadow_as_map_.find(handle);
        if (remove_shadow_as_it != shadow_as_map_.end())
        {
            MarkInjectedCommandsHelper mark_injected_commands_helper;
            shadow_as_map_.erase(remove_shadow_as_it);
        }

        auto remove_as_size_it = as_compact_sizes_.find(handle);
        if (remove_as_size_it != as_compact_sizes_.end())
        {
            as_compact_sizes_.erase(remove_as_size_it);
        }
    }
}

void VulkanAddressReplacer::DestroyShadowResources(VkCommandBuffer handle)
{
    if (handle != VK_NULL_HANDLE)
    {
        auto shadow_sbt_it = shadow_sbt_map_.find(handle);
        if (shadow_sbt_it != shadow_sbt_map_.end())
        {
            MarkInjectedCommandsHelper mark_injected_commands_helper;
            shadow_sbt_map_.erase(shadow_sbt_it);
        }

        auto pipeline_sbt_it = pipeline_context_map_.find(handle);
        if (pipeline_sbt_it != pipeline_context_map_.end())
        {
            MarkInjectedCommandsHelper mark_injected_commands_helper;
            pipeline_context_map_.erase(pipeline_sbt_it);
        }

        auto submit_asset_it = submit_asset_map_.find(handle);
        if (submit_asset_it != submit_asset_map_.end())
        {
            MarkInjectedCommandsHelper mark_injected_commands_helper;
            submit_asset_map_.erase(submit_asset_it);
        }
    }
}

bool VulkanAddressReplacer::create_acceleration_asset(VulkanAddressReplacer::acceleration_structure_asset_t& as_asset,
                                                      VkAccelerationStructureTypeKHR                         type,
                                                      size_t num_buffer_bytes,
                                                      size_t num_scratch_bytes)
{
    as_asset.device     = device_;
    as_asset.destroy_fn = device_table_->DestroyAccelerationStructureKHR;

    // create a replacement acceleration-structure with proper sized buffer
    bool success = create_buffer(as_asset.storage,
                                 num_buffer_bytes,
                                 VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR,
                                 0,
                                 false,
                                 "GFXR VulkanAddressReplacer::acceleration_structure_asset_t::storage");

    if (!success)
    {
        GFXRECON_LOG_ERROR("VulkanAddressReplacer::ProcessCmdBuildAccelerationStructuresKHR: "
                           "shadow-buffer creation failed");
        return false;
    }

    VkAccelerationStructureCreateInfoKHR as_create_info = {};
    as_create_info.sType                                = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR;
    as_create_info.buffer                               = as_asset.storage.buffer;
    as_create_info.size                                 = num_buffer_bytes;
    as_create_info.type                                 = type;

    VkResult res = device_table_->CreateAccelerationStructureKHR(device_, &as_create_info, nullptr, &as_asset.handle);

    if (res != VK_SUCCESS || as_asset.handle == VK_NULL_HANDLE)
    {
        GFXRECON_LOG_ERROR("ProcessCmdBuildAccelerationStructuresKHR: shadow "
                           "acceleration-structure creation failed");
        return false;
    }
    VkAccelerationStructureDeviceAddressInfoKHR acceleration_address_info = {};
    acceleration_address_info.sType                 = VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR;
    acceleration_address_info.accelerationStructure = as_asset.handle;
    as_asset.address = device_table_->GetAccelerationStructureDeviceAddressKHR(device_, &acceleration_address_info);
    GFXRECON_ASSERT(as_asset.address != 0);
    return true;
}

bool VulkanAddressReplacer::create_submit_asset(submit_asset_t& submit_asset)
{
    // clear previous content and setup
    submit_asset.device                  = device_;
    submit_asset.command_pool            = command_pool_;
    submit_asset.destroy_fence_fn        = device_table_->DestroyFence;
    submit_asset.free_command_buffers_fn = device_table_->FreeCommandBuffers;
    submit_asset.destroy_semaphore_fn    = device_table_->DestroySemaphore;

    if (submit_asset.command_buffer == VK_NULL_HANDLE)
    {
        VkCommandBufferAllocateInfo alloc_info = {};
        alloc_info.sType                       = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
        alloc_info.pNext                       = nullptr;
        alloc_info.commandPool                 = command_pool_;
        alloc_info.level                       = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        alloc_info.commandBufferCount          = 1;
        VkResult result = device_table_->AllocateCommandBuffers(device_, &alloc_info, &submit_asset.command_buffer);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: internal command-buffer creation failed");
            return false;
        }

        // Because this command buffer was not allocated through the loader, it must be assigned a dispatch table.
        graphics::copy_dispatch_table_from_device(device_, submit_asset.command_buffer);
    }

    // create a fence
    if (submit_asset.fence == VK_NULL_HANDLE)
    {
        VkFenceCreateInfo fence_create_info;
        fence_create_info.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
        fence_create_info.pNext = nullptr;
        fence_create_info.flags = VK_FENCE_CREATE_SIGNALED_BIT;
        VkResult result         = device_table_->CreateFence(device_, &fence_create_info, nullptr, &submit_asset.fence);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: internal fence creation failed");
            return false;
        }
    }

    // create a signal-semaphore
    if (submit_asset.signal_semaphore == VK_NULL_HANDLE)
    {
        VkSemaphoreCreateInfo semaphore_create_info = {};
        semaphore_create_info.sType                 = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
        VkResult result =
            device_table_->CreateSemaphore(device_, &semaphore_create_info, nullptr, &submit_asset.signal_semaphore);
        if (result != VK_SUCCESS)
        {
            GFXRECON_LOG_ERROR("VulkanAddressReplacer: internal semaphore creation failed");
            return false;
        }
    }
    return true;
}

void VulkanAddressReplacer::run_compute_replace(const VulkanCommandBufferInfo*            command_buffer_info,
                                                const VkDeviceAddress*                    addresses,
                                                uint32_t                                  num_addresses,
                                                const decode::VulkanDeviceAddressTracker& address_tracker,
                                                VkPipelineStageFlags                      sync_stage)
{
    if (addresses == nullptr || !num_addresses || storage_bda_binary_.empty())
    {
        return;
    }

    // sort array to allow binary-search
    std::sort(storage_bda_binary_.begin(), storage_bda_binary_.end());

    std::unordered_set<VkBuffer> buffer_set;
    for (uint32_t i = 0; i < num_addresses; ++i)
    {
        auto buffer_info = address_tracker.GetBufferByReplayDeviceAddress(addresses[i]);

        if (buffer_info != nullptr && buffer_info->replay_address != 0)
        {
            // keep track of used handles
            buffer_set.insert(buffer_info->handle);
        }
    };

    // mark injected commands
    MarkInjectedCommandsHelper mark_injected_commands_helper;

    if (pipeline_bda_ == VK_NULL_HANDLE && !init_pipeline())
    {
        GFXRECON_LOG_WARNING_ONCE("VulkanAddressReplacer::run_compute_replace(): internal pipeline-creation failed")
        return;
    }

    // retrieve a storage-context
    auto& pipeline_context_bda = pipeline_context_map_[command_buffer_info->handle].emplace_back();

    // init/resize/rehash hashmap storage if necessary
    update_global_hashmap(command_buffer_info->handle);

    if (!create_buffer(pipeline_context_bda.storage_array,
                       sizeof(bda_element_t) * storage_bda_binary_.size(),
                       0,
                       0,
                       true,
                       "GFXR VulkanAddressReplacer storage_bda_binary_"))
    {
        GFXRECON_LOG_ERROR("VulkanAddressReplacer: storage-buffer creation failed");
        return;
    }

    memcpy(pipeline_context_bda.storage_array.mapped_data,
           storage_bda_binary_.data(),
           sizeof(bda_element_t) * storage_bda_binary_.size());

    uint32_t num_bytes = num_addresses * sizeof(VkDeviceAddress);

    // create a buffer holding input-handles
    if (!create_buffer(pipeline_context_bda.input_handle_buffer,
                       num_bytes,
                       0,
                       0,
                       true,
                       "GFXR VulkanAddressReplacer input_handle_buffer_bda"))
    {
        GFXRECON_LOG_ERROR("VulkanAddressReplacer: input-handle-buffer creation failed");
        return;
    }
    memcpy(pipeline_context_bda.input_handle_buffer.mapped_data, addresses, num_bytes);

    // a sorted array of bda_element_t
    replacer_params_bda_t replacer_params = {};
    replacer_params.address_array.storage = pipeline_context_bda.storage_array.device_address;
    replacer_params.address_array.size    = storage_bda_binary_.size();

    // blacklist hashmap
    replacer_params.address_blacklist = hashmap_control_block_bda_binary_.device_address;

    // in-place
    replacer_params.input_handles  = pipeline_context_bda.input_handle_buffer.device_address;
    replacer_params.output_handles = pipeline_context_bda.input_handle_buffer.device_address;

    replacer_params.num_handles = num_addresses;

    // pre memory-barrier
    for (const auto& buf : buffer_set)
    {
        barrier(command_buffer_info->handle,
                buf,
                VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT,
                VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                VK_ACCESS_SHADER_WRITE_BIT);
    }

    device_table_->CmdBindPipeline(command_buffer_info->handle, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_bda_);

    // NOTE: using push-constants here requires us to re-establish the previous data, if any
    device_table_->CmdPushConstants(command_buffer_info->handle,
                                    pipeline_layout_,
                                    VK_SHADER_STAGE_COMPUTE_BIT,
                                    0,
                                    sizeof(replacer_params_bda_t),
                                    &replacer_params);
    // dispatch workgroups
    constexpr uint32_t wg_size = 32;
    device_table_->CmdDispatch(command_buffer_info->handle, util::div_up(replacer_params.num_handles, wg_size), 1, 1);

    // post memory-barrier
    for (const auto& buf : buffer_set)
    {
        barrier(command_buffer_info->handle,
                buf,
                VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                VK_ACCESS_SHADER_WRITE_BIT,
                sync_stage,
                VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT);
    }

    // synchronize host-reads
    barrier(command_buffer_info->handle,
            hashmap_control_block_bda_binary_.buffer,
            VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
            VK_ACCESS_SHADER_WRITE_BIT,
            VK_PIPELINE_STAGE_HOST_BIT,
            VK_ACCESS_HOST_READ_BIT);

    // set previous compute-pipeline, if any
    if (command_buffer_info->bound_pipelines.count(VK_PIPELINE_BIND_POINT_COMPUTE))
    {
        const auto* previous_pipeline =
            object_table_->GetVkPipelineInfo(command_buffer_info->bound_pipelines.at(VK_PIPELINE_BIND_POINT_COMPUTE));
        GFXRECON_ASSERT(previous_pipeline);

        if (previous_pipeline != nullptr && previous_pipeline->handle != VK_NULL_HANDLE)
        {
            device_table_->CmdBindPipeline(
                command_buffer_info->handle, VK_PIPELINE_BIND_POINT_COMPUTE, previous_pipeline->handle);
        }
    }

    // set previous push-constant data, if any
    if (!command_buffer_info->push_constant_data.empty())
    {
        device_table_->CmdPushConstants(command_buffer_info->handle,
                                        command_buffer_info->push_constant_pipeline_layout,
                                        command_buffer_info->push_constant_stage_flags,
                                        0,
                                        command_buffer_info->push_constant_data.size(),
                                        command_buffer_info->push_constant_data.data());
    }
}

void VulkanAddressReplacer::update_global_hashmap(VkCommandBuffer command_buffer)
{
    // blacklist hashmap storage  >= 16 bytes * 2^12 slots (64kB)
    constexpr uint32_t hashmap_elem_size     = 2 * sizeof(VkDeviceSize);
    constexpr uint32_t hashmap_min_num_slots = 1U << 12U;

    //! define a maximum load_factor and grow factor for hashmap_storage_bda_binary_
    constexpr float max_load_factor = 0.25f;
    constexpr float grow_factor     = 2.f;

    std::optional<buffer_context_t> previous_hashmap_storage_bda_binary;
    std::optional<buffer_context_t> previous_hashmap_control_block;

    auto create_control_block = [this, hashmap_min_num_slots = hashmap_min_num_slots]() {
        // if that buffer already existed we read back some values
        bool init_address_blacklist = hashmap_control_block_bda_binary_.buffer == VK_NULL_HANDLE;

        // init hashmap control-block
        if (!create_buffer(hashmap_control_block_bda_binary_,
                           sizeof(gpu_array_t),
                           0,
                           0,
                           true,
                           "GFXR VulkanAddressReplacer hashmap_control_block_bda_binary_"))
        {
            return false;
        }
        auto& hashmap_control_block = *reinterpret_cast<gpu_array_t*>(hashmap_control_block_bda_binary_.mapped_data);

        if (init_address_blacklist)
        {
            hashmap_control_block.size     = 0;
            hashmap_control_block.capacity = hashmap_min_num_slots;
        }
        return true;
    };

    auto create_storage = [this, hashmap_elem_size = hashmap_elem_size](uint32_t capacity) {
        GFXRECON_ASSERT(util::is_pow_2(capacity));

        // global/device-mem hashmap-storage with atomic access, contains addresses which have already been replaced
        return create_buffer(hashmap_storage_bda_binary_,
                             hashmap_elem_size * capacity,
                             VK_BUFFER_USAGE_TRANSFER_DST_BIT,
                             0,
                             false,
                             "GFXR VulkanAddressReplacer hashmap_storage_bda_binary_");
    };

    auto init_storage = [this, hashmap_elem_size = hashmap_elem_size](VkCommandBuffer command_buffer) {
        device_table_->CmdFillBuffer(
            command_buffer, hashmap_storage_bda_binary_.buffer, 0, hashmap_storage_bda_binary_.num_bytes, 0);
        barrier(command_buffer,
                hashmap_storage_bda_binary_.buffer,
                VK_PIPELINE_STAGE_TRANSFER_BIT,
                VK_ACCESS_TRANSFER_WRITE_BIT,
                VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT,
                VK_ACCESS_SHADER_READ_BIT | VK_ACCESS_SHADER_WRITE_BIT);

        auto& current_control_block    = *reinterpret_cast<gpu_array_t*>(hashmap_control_block_bda_binary_.mapped_data);
        current_control_block.capacity = hashmap_storage_bda_binary_.num_bytes / hashmap_elem_size;
        current_control_block.storage  = hashmap_storage_bda_binary_.device_address;
    };

    // if that buffer already existed we read back some values
    bool init_address_blacklist = hashmap_control_block_bda_binary_.buffer == VK_NULL_HANDLE;

    if (!create_control_block())
    {
        GFXRECON_LOG_ERROR("VulkanAddressReplacer: hashmap_control_block_bda_binary_ creation failed");
        return;
    }

    auto prev_buffer = hashmap_storage_bda_binary_.buffer;

    auto& hashmap_control_block = *reinterpret_cast<gpu_array_t*>(hashmap_control_block_bda_binary_.mapped_data);

    if (!create_storage(hashmap_control_block.capacity))
    {
        GFXRECON_LOG_ERROR("VulkanAddressReplacer: hashmap_storage_bda_binary_ creation failed");
        return;
    }

    if (!init_address_blacklist)
    {
        float load_factor =
            static_cast<float>(hashmap_control_block.size) / static_cast<float>(hashmap_control_block.capacity);
        if (load_factor > max_load_factor)
        {
            // store previous storage
            previous_hashmap_storage_bda_binary = std::move(hashmap_storage_bda_binary_);
            previous_hashmap_control_block      = std::move(hashmap_control_block_bda_binary_);

            GFXRECON_LOG_DEBUG(
                "%s(): hashmap_control_block_bda_binary_: %d / %d (load-factor: %.2f) -> Resize (x %.1f) + Rehashing",
                __func__,
                hashmap_control_block.size,
                hashmap_control_block.capacity,
                hashmap_control_block.size / static_cast<float>(hashmap_control_block.capacity),
                grow_factor);
        }
    }

    // init hashmap storage
    if (prev_buffer != hashmap_storage_bda_binary_.buffer)
    {
        std::optional<QueueSubmitHelper> queue_submit_helper;

        if (command_buffer != submit_asset_.command_buffer)
        {
            if (!init_queue_assets())
            {
                GFXRECON_LOG_ERROR("%s(): cannot initialize a local command-buffer");
            }

            // reset/submit/sync command-buffer
            queue_submit_helper =
                QueueSubmitHelper(device_table_, device_, submit_asset_.command_buffer, queue_, submit_asset_.fence);
            command_buffer = submit_asset_.command_buffer;
        }

        if (init_address_blacklist)
        {
            init_storage(command_buffer);
        }
        else
        {
            // we need a bigger boat. this will require running a local rehashing-dispatch
            GFXRECON_ASSERT(previous_hashmap_control_block && previous_hashmap_storage_bda_binary);
            GFXRECON_ASSERT(hashmap_control_block_bda_binary_.buffer == VK_NULL_HANDLE &&
                            hashmap_storage_bda_binary_.buffer == VK_NULL_HANDLE);
            auto& previous_control_block = *reinterpret_cast<gpu_array_t*>(previous_hashmap_control_block->mapped_data);

            // create new storage- and control-blocks
            create_control_block();
            create_storage(static_cast<uint32_t>(static_cast<float>(previous_control_block.capacity) * grow_factor));
            init_storage(command_buffer);

            struct rehash_params_t
            {
                VkDeviceAddress hashmap_old = 0;
                VkDeviceAddress hashmap_new = 0;
            };
            rehash_params_t rehash_params;
            rehash_params.hashmap_old = previous_hashmap_control_block->device_address;
            rehash_params.hashmap_new = hashmap_control_block_bda_binary_.device_address;

            device_table_->CmdBindPipeline(
                submit_asset_.command_buffer, VK_PIPELINE_BIND_POINT_COMPUTE, pipeline_bda_rehash_);
            device_table_->CmdPushConstants(submit_asset_.command_buffer,
                                            pipeline_layout_,
                                            VK_SHADER_STAGE_COMPUTE_BIT,
                                            0,
                                            sizeof(rehash_params_t),
                                            &rehash_params);
            // dispatch workgroups
            constexpr uint32_t wg_size = 32;
            device_table_->CmdDispatch(
                submit_asset_.command_buffer, util::div_up(previous_control_block.capacity, wg_size), 1, 1);
        }
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)
