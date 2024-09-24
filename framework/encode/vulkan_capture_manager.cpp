/*
 ** Copyright (c) 2018-2021 Valve Corporation
 ** Copyright (c) 2018-2023 LunarG, Inc.
 ** Copyright (c) 2019-2023 Advanced Micro Devices, Inc. All rights reserved.
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

#include PROJECT_VERSION_HEADER_FILE

#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_track_struct.h"
#include "encode/vulkan_capture_manager.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_state_writer.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "graphics/vulkan_check_buffer_references.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "graphics/vulkan_util.h"
#include "util/compressor.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/platform.h"

#include <cassert>
#include <unordered_set>

#if defined(__linux__) && !defined(__ANDROID__)
#if defined(VK_USE_PLATFORM_XCB_KHR)
#include <xcb/xcb_keysyms.h>
#endif
#endif

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
#include <android/hardware_buffer.h>
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

VulkanCaptureManager* VulkanCaptureManager::singleton_ = nullptr;
VulkanLayerTable      VulkanCaptureManager::vulkan_layer_table_;

bool VulkanCaptureManager::CreateInstance()
{

    bool result = CommonCaptureManager::CreateInstance<VulkanCaptureManager>();
    GFXRECON_ASSERT(singleton_);

    GFXRECON_LOG_INFO("  Vulkan Header Version %u.%u.%u",
                      VK_VERSION_MAJOR(VK_HEADER_VERSION_COMPLETE),
                      VK_VERSION_MINOR(VK_HEADER_VERSION_COMPLETE),
                      VK_VERSION_PATCH(VK_HEADER_VERSION_COMPLETE));

    return result;
}

VulkanCaptureManager* VulkanCaptureManager::InitSingleton()
{
    if (!singleton_)
    {
        singleton_ = new VulkanCaptureManager();
    }
    return singleton_;
}

void VulkanCaptureManager::DestroySingleton()
{
    if (singleton_)
    {
        delete singleton_;
        singleton_ = nullptr;
    }
}

void VulkanCaptureManager::DestroyInstance()
{
    GFXRECON_ASSERT(singleton_ && singleton_->common_manager_);
    singleton_->common_manager_->DestroyInstance(singleton_);
}

void VulkanCaptureManager::WriteTrackedState(util::FileOutputStream* file_stream, format::ThreadId thread_id)
{
    VulkanStateWriter state_writer(file_stream, GetCompressor(), thread_id);
    uint64_t          n_blocks = state_tracker_->WriteState(&state_writer, GetCurrentFrame());
    common_manager_->IncrementBlockIndex(n_blocks);
}

void VulkanCaptureManager::SetLayerFuncs(PFN_vkCreateInstance create_instance, PFN_vkCreateDevice create_device)
{
    assert((create_instance != nullptr) && (create_device != nullptr));
    vulkan_layer_table_.CreateInstance = create_instance;
    vulkan_layer_table_.CreateDevice   = create_device;
}

void VulkanCaptureManager::CheckVkCreateInstanceStatus(VkResult result)
{
    if (result != VK_SUCCESS)
    {
        DestroyInstance();
    }
}

void VulkanCaptureManager::InitVkInstance(VkInstance* instance, PFN_vkGetInstanceProcAddr gpa)
{
    assert(instance != nullptr);

    vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::NoParentWrapper,
                                         vulkan_wrappers::NoParentWrapper,
                                         vulkan_wrappers::InstanceWrapper>(
        vulkan_wrappers::NoParentWrapper::kHandleValue,
        vulkan_wrappers::NoParentWrapper::kHandleValue,
        instance,
        GetUniqueId);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::InstanceWrapper>(*instance);
    LoadVulkanInstanceTable(gpa, wrapper->handle, &wrapper->layer_table);
}

void VulkanCaptureManager::InitVkDevice(VkDevice* device, PFN_vkGetDeviceProcAddr gpa)
{
    assert((device != nullptr) && ((*device) != VK_NULL_HANDLE));

    vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::PhysicalDeviceWrapper,
                                         vulkan_wrappers::NoParentWrapper,
                                         vulkan_wrappers::DeviceWrapper>(
        VK_NULL_HANDLE, vulkan_wrappers::NoParentWrapper::kHandleValue, device, GetUniqueId);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(*device);
    LoadVulkanDeviceTable(gpa, wrapper->handle, &wrapper->layer_table);
}

void VulkanCaptureManager::WriteResizeWindowCmd2(format::HandleId              surface_id,
                                                 uint32_t                      width,
                                                 uint32_t                      height,
                                                 VkSurfaceTransformFlagBitsKHR pre_transform)
{
    if (IsCaptureModeWrite())
    {
        auto thread_data = GetThreadData();

        format::ResizeWindowCommand2 resize_cmd2;
        resize_cmd2.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        resize_cmd2.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(resize_cmd2);
        resize_cmd2.meta_header.meta_data_id =
            format::MakeMetaDataId(format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kResizeWindowCommand2);
        resize_cmd2.thread_id = thread_data->thread_id_;

        resize_cmd2.surface_id = surface_id;
        resize_cmd2.width      = width;
        resize_cmd2.height     = height;

        switch (pre_transform)
        {
            default:
            case VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR:
            case VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform0;
                break;
            case VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform90;
                break;
            case VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform180;
                break;
            case VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR:
            case VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR:
                resize_cmd2.pre_transform = format::ResizeWindowPreTransform::kPreTransform270;
                break;
        }

        WriteToFile(&resize_cmd2, sizeof(resize_cmd2));
    }
}

void VulkanCaptureManager::WriteCreateHardwareBufferCmd(format::HandleId                                    memory_id,
                                                        AHardwareBuffer*                                    buffer,
                                                        const std::vector<format::HardwareBufferPlaneInfo>& plane_info)
{
    if (IsCaptureModeWrite())
    {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        assert(buffer != nullptr);

        format::CreateHardwareBufferCommandHeader create_buffer_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        create_buffer_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        create_buffer_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(create_buffer_cmd);
        create_buffer_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kCreateHardwareBufferCommand);
        create_buffer_cmd.thread_id = thread_data->thread_id_;
        create_buffer_cmd.memory_id = memory_id;
        create_buffer_cmd.buffer_id = reinterpret_cast<uint64_t>(buffer);

        // Get AHB description data.
        AHardwareBuffer_Desc ahb_desc = {};
        AHardwareBuffer_describe(buffer, &ahb_desc);

        create_buffer_cmd.format = ahb_desc.format;
        create_buffer_cmd.width  = ahb_desc.width;
        create_buffer_cmd.height = ahb_desc.height;
        create_buffer_cmd.stride = ahb_desc.stride;
        create_buffer_cmd.usage  = ahb_desc.usage;
        create_buffer_cmd.layers = ahb_desc.layers;

        size_t planes_size = 0;

        if (plane_info.empty())
        {
            create_buffer_cmd.planes = 0;
        }
        else
        {
            create_buffer_cmd.planes = static_cast<uint32_t>(plane_info.size());
            // Update size of packet with size of plane info.
            planes_size = sizeof(plane_info[0]) * plane_info.size();
            create_buffer_cmd.meta_header.block_header.size += planes_size;
        }

        {
            if (planes_size > 0)
            {
                CombineAndWriteToFile(
                    { { &create_buffer_cmd, sizeof(create_buffer_cmd) }, { plane_info.data(), planes_size } });
            }
            else
            {
                WriteToFile(&create_buffer_cmd, sizeof(create_buffer_cmd));
            }
        }
#else
        GFXRECON_UNREFERENCED_PARAMETER(memory_id);
        GFXRECON_UNREFERENCED_PARAMETER(buffer);
        GFXRECON_UNREFERENCED_PARAMETER(plane_info);

        GFXRECON_LOG_ERROR("Skipping create AHardwareBuffer command write for unsupported platform");
#endif
    }
}

void VulkanCaptureManager::WriteDestroyHardwareBufferCmd(AHardwareBuffer* buffer)
{
    if (IsCaptureModeWrite())
    {
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        assert(buffer != nullptr);

        format::DestroyHardwareBufferCommand destroy_buffer_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        destroy_buffer_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        destroy_buffer_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(destroy_buffer_cmd);
        destroy_buffer_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kDestroyHardwareBufferCommand);
        destroy_buffer_cmd.thread_id = thread_data->thread_id_;
        destroy_buffer_cmd.buffer_id = reinterpret_cast<uint64_t>(buffer);

        WriteToFile(&destroy_buffer_cmd, sizeof(destroy_buffer_cmd));
#else
        GFXRECON_LOG_ERROR("Skipping destroy AHardwareBuffer command write for unsupported platform");
#endif
    }
}

void VulkanCaptureManager::WriteSetDevicePropertiesCommand(format::HandleId                  physical_device_id,
                                                           const VkPhysicalDeviceProperties& properties)
{
    if (IsCaptureModeWrite())
    {
        format::SetDevicePropertiesCommand properties_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        uint32_t device_name_len = static_cast<uint32_t>(util::platform::StringLength(properties.deviceName));

        properties_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        properties_cmd.meta_header.block_header.size =
            format::GetMetaDataBlockBaseSize(properties_cmd) + device_name_len;
        properties_cmd.meta_header.meta_data_id = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetDevicePropertiesCommand);
        properties_cmd.thread_id          = thread_data->thread_id_;
        properties_cmd.physical_device_id = physical_device_id;
        properties_cmd.api_version        = properties.apiVersion;
        properties_cmd.driver_version     = properties.driverVersion;
        properties_cmd.vendor_id          = properties.vendorID;
        properties_cmd.device_id          = properties.deviceID;
        properties_cmd.device_type        = properties.deviceType;
        util::platform::MemoryCopy(
            properties_cmd.pipeline_cache_uuid, format::kUuidSize, properties.pipelineCacheUUID, VK_UUID_SIZE);
        properties_cmd.device_name_len = device_name_len;

        CombineAndWriteToFile(
            { { &properties_cmd, sizeof(properties_cmd) }, { properties.deviceName, properties_cmd.device_name_len } });
    }
}

void VulkanCaptureManager::WriteSetDeviceMemoryPropertiesCommand(
    format::HandleId physical_device_id, const VkPhysicalDeviceMemoryProperties& memory_properties)
{
    if (IsCaptureModeWrite())
    {
        format::SetDeviceMemoryPropertiesCommand memory_properties_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        memory_properties_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        memory_properties_cmd.meta_header.block_header.size =
            format::GetMetaDataBlockBaseSize(memory_properties_cmd) +
            (sizeof(format::DeviceMemoryType) * memory_properties.memoryTypeCount) +
            (sizeof(format::DeviceMemoryHeap) * memory_properties.memoryHeapCount);
        memory_properties_cmd.meta_header.meta_data_id = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetDeviceMemoryPropertiesCommand);
        memory_properties_cmd.thread_id          = thread_data->thread_id_;
        memory_properties_cmd.physical_device_id = physical_device_id;
        memory_properties_cmd.memory_type_count  = memory_properties.memoryTypeCount;
        memory_properties_cmd.memory_heap_count  = memory_properties.memoryHeapCount;

        // Since the number of file writes below is dynamic, CombineAndWriteToFile is not suitable. Instead, manually
        // populate thread_data's scratch_buffer_ then write to file.
        auto& scratch_buffer = thread_data->GetScratchBuffer();
        scratch_buffer.clear();
        std::copy(reinterpret_cast<uint8_t*>(&memory_properties_cmd),
                  reinterpret_cast<uint8_t*>(&memory_properties_cmd) + sizeof(memory_properties_cmd),
                  std::back_inserter(scratch_buffer));

        format::DeviceMemoryType type;
        for (uint32_t i = 0; i < memory_properties.memoryTypeCount; ++i)
        {
            type.property_flags = memory_properties.memoryTypes[i].propertyFlags;
            type.heap_index     = memory_properties.memoryTypes[i].heapIndex;

            scratch_buffer.insert(scratch_buffer.end(),
                                  reinterpret_cast<uint8_t*>(&type),
                                  reinterpret_cast<uint8_t*>(&type) + sizeof(type));
        }

        format::DeviceMemoryHeap heap;
        for (uint32_t i = 0; i < memory_properties.memoryHeapCount; ++i)
        {
            heap.size  = memory_properties.memoryHeaps[i].size;
            heap.flags = memory_properties.memoryHeaps[i].flags;

            scratch_buffer.insert(scratch_buffer.end(),
                                  reinterpret_cast<uint8_t*>(&heap),
                                  reinterpret_cast<uint8_t*>(&heap) + sizeof(heap));
        }

        WriteToFile(scratch_buffer.data(), scratch_buffer.size());
    }
}

void VulkanCaptureManager::WriteSetOpaqueAddressCommand(format::HandleId device_id,
                                                        format::HandleId object_id,
                                                        uint64_t         opaque_address)
{
    if (IsCaptureModeWrite())
    {
        format::SetOpaqueAddressCommand opaque_address_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        opaque_address_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        opaque_address_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(opaque_address_cmd);
        opaque_address_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetOpaqueAddressCommand);
        opaque_address_cmd.thread_id = thread_data->thread_id_;
        opaque_address_cmd.device_id = device_id;
        opaque_address_cmd.object_id = object_id;
        opaque_address_cmd.address   = opaque_address;

        WriteToFile(&opaque_address_cmd, sizeof(opaque_address_cmd));
    }
}

void VulkanCaptureManager::WriteSetRayTracingShaderGroupHandlesCommand(format::HandleId device_id,
                                                                       format::HandleId pipeline_id,
                                                                       size_t           data_size,
                                                                       const void*      data)
{
    if (IsCaptureModeWrite())
    {
        format::SetRayTracingShaderGroupHandlesCommandHeader set_handles_cmd;

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        set_handles_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        set_handles_cmd.meta_header.block_header.size = format::GetMetaDataBlockBaseSize(set_handles_cmd) + data_size;
        set_handles_cmd.meta_header.meta_data_id      = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetRayTracingShaderGroupHandlesCommand);
        set_handles_cmd.thread_id   = thread_data->thread_id_;
        set_handles_cmd.device_id   = device_id;
        set_handles_cmd.pipeline_id = pipeline_id;
        set_handles_cmd.data_size   = data_size;

        CombineAndWriteToFile({ { &set_handles_cmd, sizeof(set_handles_cmd) }, { data, data_size } });
    }
}

void VulkanCaptureManager::SetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate                  update_template,
                                                           const VkDescriptorUpdateTemplateCreateInfo* create_info)
{
    // A NULL check should have been performed by the caller.
    assert((create_info != nullptr));

    if (create_info->descriptorUpdateEntryCount > 0)
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(update_template);
        UpdateTemplateInfo* info = &wrapper->info;

        for (size_t i = 0; i < create_info->descriptorUpdateEntryCount; ++i)
        {
            const VkDescriptorUpdateTemplateEntry* entry      = &create_info->pDescriptorUpdateEntries[i];
            VkDescriptorType                       type       = entry->descriptorType;
            size_t                                 entry_size = 0;

            // Sort the descriptor update template info by type, so it can be written to the capture file
            // as tightly packed arrays of structures.  One array will be written for each descriptor info
            // structure/textel buffer view.
            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                UpdateTemplateEntryInfo image_info;
                image_info.binding       = entry->dstBinding;
                image_info.array_element = entry->dstArrayElement;
                image_info.count         = entry->descriptorCount;
                image_info.offset        = entry->offset;
                image_info.stride        = entry->stride;
                image_info.type          = type;

                info->image_info_count += entry->descriptorCount;
                info->image_info.emplace_back(image_info);

                entry_size = sizeof(VkDescriptorImageInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                UpdateTemplateEntryInfo buffer_info;
                buffer_info.binding       = entry->dstBinding;
                buffer_info.array_element = entry->dstArrayElement;
                buffer_info.count         = entry->descriptorCount;
                buffer_info.offset        = entry->offset;
                buffer_info.stride        = entry->stride;
                buffer_info.type          = type;

                info->buffer_info_count += entry->descriptorCount;
                info->buffer_info.emplace_back(buffer_info);

                entry_size = sizeof(VkDescriptorBufferInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                UpdateTemplateEntryInfo texel_buffer_view_info;
                texel_buffer_view_info.binding       = entry->dstBinding;
                texel_buffer_view_info.array_element = entry->dstArrayElement;
                texel_buffer_view_info.count         = entry->descriptorCount;
                texel_buffer_view_info.offset        = entry->offset;
                texel_buffer_view_info.stride        = entry->stride;
                texel_buffer_view_info.type          = type;

                info->texel_buffer_view_count += entry->descriptorCount;
                info->texel_buffer_view.emplace_back(texel_buffer_view_info);

                entry_size = sizeof(VkBufferView);
            }
            else if (type == VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR)
            {
                UpdateTemplateEntryInfo accel_struct_info;
                accel_struct_info.binding       = entry->dstBinding;
                accel_struct_info.array_element = entry->dstArrayElement;
                accel_struct_info.count         = entry->descriptorCount;
                accel_struct_info.offset        = entry->offset;
                accel_struct_info.stride        = entry->stride;
                accel_struct_info.type          = type;

                info->acceleration_structure_khr_count += entry->descriptorCount;
                info->acceleration_structure_khr.emplace_back(accel_struct_info);

                entry_size = sizeof(VkAccelerationStructureKHR);
            }
            else if (type == VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK)
            {
                constexpr size_t byte_stride = 1;
                GFXRECON_ASSERT(entry->stride == byte_stride);

                UpdateTemplateEntryInfo inline_uniform_info;
                inline_uniform_info.binding       = entry->dstBinding;
                inline_uniform_info.array_element = entry->dstArrayElement;

                // count is interpreted as number of bytes here
                inline_uniform_info.count  = entry->descriptorCount;
                inline_uniform_info.offset = entry->offset;
                inline_uniform_info.stride = entry->stride;
                inline_uniform_info.type   = type;

                info->inline_uniform_block_count += entry->descriptorCount;
                info->inline_uniform_block.emplace_back(inline_uniform_info);

                entry_size = byte_stride;
            }
            else
            {
                GFXRECON_LOG_ERROR("Unrecognized/unsupported descriptor type in descriptor update template.");
                assert(false);
            }

            if (entry->descriptorCount > 0)
            {
                size_t max_size = ((entry->descriptorCount - 1) * entry->stride) + entry->offset + entry_size;
                if (max_size > info->max_size)
                {
                    info->max_size = max_size;
                }
            }
        }
    }
}

bool VulkanCaptureManager::GetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate update_template,
                                                           const UpdateTemplateInfo** info) const
{
    assert(info != nullptr);

    bool found = false;

    if (update_template != VK_NULL_HANDLE)
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorUpdateTemplateWrapper>(update_template);
        (*info)      = &wrapper->info;
        found        = true;
    }

    return found;
}

void VulkanCaptureManager::TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet            set,
                                                                VkDescriptorUpdateTemplate update_template,
                                                                const void*                data)
{
    const UpdateTemplateInfo* info = nullptr;
    if (GetDescriptorUpdateTemplateInfo(update_template, &info))
    {
        assert(state_tracker_ != nullptr);
        state_tracker_->TrackUpdateDescriptorSetWithTemplate(set, info, data);
    }
}

VkResult VulkanCaptureManager::OverrideCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator,
                                                      VkInstance*                  pInstance)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (CreateInstance())
    {
        if (singleton_->IsPageGuardMemoryModeExternal())
        {
            assert(pCreateInfo != nullptr);

            VkInstanceCreateInfo create_info_copy = (*pCreateInfo);

            // TODO: Only enable KHR_get_physical_device_properties_2 for 1.0 API version.
            size_t                   extension_count = create_info_copy.enabledExtensionCount;
            const char* const*       extensions      = create_info_copy.ppEnabledExtensionNames;
            std::vector<const char*> modified_extensions;

            bool has_dev_prop2    = false;
            bool has_ext_mem_caps = false;

            for (size_t i = 0; i < extension_count; ++i)
            {
                auto entry = extensions[i];

                modified_extensions.push_back(entry);

                if (util::platform::StringCompare(entry, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) == 0)
                {
                    has_dev_prop2 = true;
                }

                if (util::platform::StringCompare(entry, VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME) == 0)
                {
                    has_ext_mem_caps = true;
                }
            }

            if (!has_dev_prop2)
            {
                modified_extensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
            }

            if (!has_ext_mem_caps)
            {
                modified_extensions.push_back(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME);
            }

            create_info_copy.enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
            create_info_copy.ppEnabledExtensionNames = modified_extensions.data();

            result = vulkan_layer_table_.CreateInstance(&create_info_copy, pAllocator, pInstance);
        }
        else
        {
            result = vulkan_layer_table_.CreateInstance(pCreateInfo, pAllocator, pInstance);
        }
    }

    if ((result == VK_SUCCESS) && (pCreateInfo->pApplicationInfo != nullptr))
    {
        auto api_version              = pCreateInfo->pApplicationInfo->apiVersion;
        auto instance_wrapper         = vulkan_wrappers::GetWrapper<vulkan_wrappers::InstanceWrapper>(*pInstance);
        instance_wrapper->api_version = api_version;

        // Warn when enabled API version is newer than the supported API version.
        if (api_version > VK_HEADER_VERSION_COMPLETE)
        {
            GFXRECON_LOG_WARNING(
                "The application has specified that it uses Vulkan API version %u.%u.%u, which is newer than the "
                "version supported by GFXReconstruct.  Use of unsupported Vulkan features may cause capture or replay "
                "to fail.",
                VK_VERSION_MAJOR(api_version),
                VK_VERSION_MINOR(api_version),
                VK_VERSION_PATCH(api_version));
        }
    }

    return result;
}

VkResult VulkanCaptureManager::OverrideCreateDevice(VkPhysicalDevice             physicalDevice,
                                                    const VkDeviceCreateInfo*    pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator,
                                                    VkDevice*                    pDevice)
{
    auto                handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkDeviceCreateInfo* pCreateInfo_unwrapped =
        const_cast<VkDeviceCreateInfo*>(vulkan_wrappers::UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory));

    assert(pCreateInfo_unwrapped != nullptr);

    const VulkanInstanceTable* instance_table = vulkan_wrappers::GetInstanceTable(physicalDevice);
    auto physical_device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physicalDevice);

    graphics::VulkanDeviceUtil                device_util;
    graphics::VulkanDevicePropertyFeatureInfo property_feature_info = device_util.EnableRequiredPhysicalDeviceFeatures(
        physical_device_wrapper->instance_api_version, instance_table, physicalDevice, pCreateInfo_unwrapped);

    // TODO: Only enable KHR_external_memory_capabilities for 1.0 API version.
    size_t                   extension_count = pCreateInfo_unwrapped->enabledExtensionCount;
    const char* const*       extensions      = pCreateInfo_unwrapped->ppEnabledExtensionNames;
    std::vector<const char*> modified_extensions;

    bool has_ext_mem      = false;
    bool has_ext_mem_host = false;

    for (size_t i = 0; i < extension_count; ++i)
    {
        auto entry = pCreateInfo_unwrapped->ppEnabledExtensionNames[i];

        modified_extensions.push_back(entry);

        if (IsPageGuardMemoryModeExternal())
        {
            if (util::platform::StringCompare(entry, VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME) == 0)
            {
                has_ext_mem = true;
            }
            else if (util::platform::StringCompare(entry, VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME) == 0)
            {
                has_ext_mem_host = true;
            }
        }
    }

    if (IsPageGuardMemoryModeExternal())
    {
        if (!has_ext_mem)
        {
            modified_extensions.push_back(VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME);
        }

        if (!has_ext_mem_host)
        {
            modified_extensions.push_back(VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME);
        }
    }

    pCreateInfo_unwrapped->enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
    pCreateInfo_unwrapped->ppEnabledExtensionNames = modified_extensions.data();

    VkDeviceQueueCreateInfo modified_queue_ci = {};

    if (GetQueueZeroOnly())
    {
        // GetPhysicalDeviceQueueFamilyProperties force to return only FamilyIndex: 0 and queueCount: 1, so it shouldn't
        // need to modifiy. If modified happens, it means the application doesn't follow
        // GetPhysicalDeviceQueueFamilyProperties to set DeviceQueueCreateInfo. This modified could break the
        // application setting. It might cause error.
        GFXRECON_ASSERT(pCreateInfo_unwrapped->pQueueCreateInfos != nullptr);

        if (pCreateInfo_unwrapped->queueCreateInfoCount > 1)
        {
            GFXRECON_LOG_WARNING("Because QUEUE_ZERO_ONLY is enabled, force queueCreateInfoCount to 1 on CreateDevice. "
                                 "It might cause error.");
            pCreateInfo_unwrapped->queueCreateInfoCount = 1;
        }

        modified_queue_ci = pCreateInfo_unwrapped->pQueueCreateInfos[0];

        if (modified_queue_ci.queueFamilyIndex > 0)
        {
            GFXRECON_LOG_WARNING("Because QUEUE_ZERO_ONLY is enabled, force queueFamilyIndex to 0 on CreateDevice. It "
                                 "might cause error.");
            modified_queue_ci.queueFamilyIndex = 0;
        }

        if (modified_queue_ci.queueCount > 1)
        {
            GFXRECON_LOG_WARNING(
                "Because QUEUE_ZERO_ONLY is enabled, force queueCount to 1 on CreateDevice. It might cause error.");
            modified_queue_ci.queueCount = 1;
        }
        pCreateInfo_unwrapped->pQueueCreateInfos = &modified_queue_ci;
    }

    VkResult result = vulkan_layer_table_.CreateDevice(physicalDevice, pCreateInfo_unwrapped, pAllocator, pDevice);

    if (result == VK_SUCCESS)
    {
        assert((pDevice != nullptr) && (*pDevice != VK_NULL_HANDLE));

        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(*pDevice);

        // Track state of physical device properties and features at device creation
        wrapper->property_feature_info = property_feature_info;

        if (!IsCaptureModeTrack())
        {
            // The state tracker will set this value when it is enabled. When state tracking is disabled it is set here
            // to ensure it is available.
            wrapper->physical_device = physical_device_wrapper;
        }

        for (uint32_t q = 0; q < pCreateInfo_unwrapped->queueCreateInfoCount; ++q)
        {
            const VkDeviceQueueCreateInfo* queue_create_info = &pCreateInfo_unwrapped->pQueueCreateInfos[q];
            assert(wrapper->queue_family_creation_flags.find(queue_create_info->queueFamilyIndex) ==
                   wrapper->queue_family_creation_flags.end());
            wrapper->queue_family_creation_flags[queue_create_info->queueFamilyIndex] = queue_create_info->flags;
        }
    }

    // Restore modified property/feature create info values to the original application values
    device_util.RestoreModifiedPhysicalDeviceFeatures();

    return result;
}

VkResult VulkanCaptureManager::OverrideCreateBuffer(VkDevice                     device,
                                                    const VkBufferCreateInfo*    pCreateInfo,
                                                    const VkAllocationCallbacks* pAllocator,
                                                    VkBuffer*                    pBuffer)
{
    VkResult result               = VK_SUCCESS;
    auto     device_wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice device_unwrapped     = device_wrapper->handle;
    auto     device_table         = vulkan_wrappers::GetDeviceTable(device);

    // we need to deep-copy, potentially contains VkBufferUsageFlags2CreateInfoKHR in pNext-chain
    std::unique_ptr<uint8_t[]> struct_storage;
    VkBufferCreateInfo*        modified_create_info = vulkan_trackers::TrackStructs(pCreateInfo, 1, struct_storage);

    bool                    uses_address             = false;
    VkBufferUsageFlags2KHR* address_usage_flags2_KHR = nullptr;

    if (auto usage_flags2_info =
            graphics::vulkan_struct_get_pnext<VkBufferUsageFlags2CreateInfoKHR>(modified_create_info))
    {
        address_usage_flags2_KHR = &usage_flags2_info->usage;
    }

    if (IsTrimEnabled())
    {
        modified_create_info->usage |= VK_BUFFER_USAGE_TRANSFER_SRC_BIT;

        if (address_usage_flags2_KHR != nullptr)
        {
            *address_usage_flags2_KHR |= VK_BUFFER_USAGE_2_TRANSFER_SRC_BIT_KHR;
        }
    }

    if (device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        // If the buffer has shader device address usage, but the device address capture replay flag was not set, it
        // needs to be set here.  We modify only a copy to prevent the modified pCreateInfo from being
        // written to the capture file.
        if ((pCreateInfo->usage & VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT) ==
            VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT)
        {
            uses_address = true;
            modified_create_info->flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
        }
        if ((pCreateInfo->usage & VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR) ==
            VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR)
        {
            uses_address = true;
            modified_create_info->flags |= VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
            modified_create_info->usage |= VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT;

            if (address_usage_flags2_KHR != nullptr)
            {
                *address_usage_flags2_KHR |= VK_BUFFER_USAGE_2_SHADER_DEVICE_ADDRESS_BIT_KHR;
            }
        }
    }
    // create buffer with augmented create- and usage-flags
    result = device_table->CreateBuffer(device_unwrapped, modified_create_info, pAllocator, pBuffer);

    if ((result == VK_SUCCESS) && (pBuffer != nullptr))
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::BufferWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pBuffer, GetUniqueId);

        if (uses_address)
        {
            // If the buffer has a device address, write the 'set buffer address' command before writing the API call to
            // create the buffer.  The address will need to be passed to vkCreateBuffer through the pCreateInfo pNext
            // list.
            auto buffer_wrapper            = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(*pBuffer);
            VkBufferDeviceAddressInfo info = { VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO };
            info.pNext                     = nullptr;
            info.buffer                    = buffer_wrapper->handle;
            uint64_t opaque_address        = 0;

            if (device_wrapper->physical_device->instance_api_version >= VK_MAKE_VERSION(1, 2, 0))
            {
                opaque_address = device_table->GetBufferOpaqueCaptureAddress(device_unwrapped, &info);
            }
            else
            {
                opaque_address = device_table->GetBufferOpaqueCaptureAddressKHR(device_unwrapped, &info);
            }
            WriteSetOpaqueAddressCommand(device_wrapper->handle_id, buffer_wrapper->handle_id, opaque_address);

            if (IsCaptureModeTrack())
            {
                state_tracker_->TrackOpaqueBufferDeviceAddress(device, *pBuffer, opaque_address);
            }
        }
    }
    return result;
}

VkResult VulkanCaptureManager::OverrideCreateImage(VkDevice                     device,
                                                   const VkImageCreateInfo*     pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator,
                                                   VkImage*                     pImage)
{
    auto                     handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    const VkImageCreateInfo* pCreateInfo_unwrapped =
        vulkan_wrappers::UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkImageCreateInfo modified_create_info = (*pCreateInfo_unwrapped);

    if (IsTrimEnabled())
    {
        modified_create_info.usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    }

    VkResult result =
        vulkan_wrappers::GetDeviceTable(device)->CreateImage(device, &modified_create_info, pAllocator, pImage);

    if (result >= 0)
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::ImageWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pImage, VulkanCaptureManager::GetUniqueId);
    }
    return result;
}

VkResult
VulkanCaptureManager::OverrideCreateAccelerationStructureKHR(VkDevice                                    device,
                                                             const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
                                                             const VkAllocationCallbacks*                pAllocator,
                                                             VkAccelerationStructureKHR* pAccelerationStructureKHR)
{
    auto                     handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto                     device_wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice                 device_unwrapped     = device_wrapper->handle;
    const VulkanDeviceTable* device_table         = vulkan_wrappers::GetDeviceTable(device);
    const VkAccelerationStructureCreateInfoKHR* pCreateInfo_unwrapped =
        vulkan_wrappers::UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkResult result;
    if (device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        // Add flag to allow for opaque address capture
        VkAccelerationStructureCreateInfoKHR modified_create_info = (*pCreateInfo_unwrapped);
        modified_create_info.createFlags |= VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR;
        result = device_table->CreateAccelerationStructureKHR(
            device_unwrapped, &modified_create_info, pAllocator, pAccelerationStructureKHR);
    }
    else
    {
        result = device_table->CreateAccelerationStructureKHR(
            device_unwrapped, pCreateInfo_unwrapped, pAllocator, pAccelerationStructureKHR);
    }

    if ((result == VK_SUCCESS) && (pAccelerationStructureKHR != nullptr))
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::AccelerationStructureKHRWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pAccelerationStructureKHR, GetUniqueId);

        if (device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
        {
            auto accel_struct_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                *pAccelerationStructureKHR);

            VkAccelerationStructureDeviceAddressInfoKHR address_info{
                VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR, nullptr, accel_struct_wrapper->handle
            };

            // save address to use as pCreateInfo->deviceAddress during replay
            VkDeviceAddress address =
                device_table->GetAccelerationStructureDeviceAddressKHR(device_unwrapped, &address_info);

            WriteSetOpaqueAddressCommand(device_wrapper->handle_id, accel_struct_wrapper->handle_id, address);

            if (IsCaptureModeTrack())
            {
                state_tracker_->TrackAccelerationStructureKHRDeviceAddress(device, *pAccelerationStructureKHR, address);
            }
        }
    }

    return result;
}

void VulkanCaptureManager::OverrideCmdBuildAccelerationStructuresKHR(
    VkCommandBuffer                                        commandBuffer,
    uint32_t                                               infoCount,
    const VkAccelerationStructureBuildGeometryInfoKHR*     pInfos,
    const VkAccelerationStructureBuildRangeInfoKHR* const* ppBuildRangeInfos)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackTLASBuildCommand(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    }

    const VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(commandBuffer);
    device_table->CmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

VkResult VulkanCaptureManager::OverrideAllocateMemory(VkDevice                     device,
                                                      const VkMemoryAllocateInfo*  pAllocateInfo,
                                                      const VkAllocationCallbacks* pAllocator,
                                                      VkDeviceMemory*              pMemory)
{
    VkResult                         result          = VK_SUCCESS;
    void*                            external_memory = nullptr;
    VkImportMemoryHostPointerInfoEXT import_info;

    auto                  device_wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice              device_unwrapped     = device_wrapper->handle;
    auto                  handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    VkMemoryAllocateInfo* pAllocateInfo_unwrapped =
        const_cast<VkMemoryAllocateInfo*>(vulkan_wrappers::UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory));

    bool                   uses_address         = false;
    VkMemoryAllocateFlags* modified_alloc_flags = nullptr;
    VkMemoryAllocateFlags  incoming_alloc_flags;
    if (device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        if (auto alloc_flags_info =
                graphics::vulkan_struct_get_pnext<VkMemoryAllocateFlagsInfo>(pAllocateInfo_unwrapped))
        {
            if ((alloc_flags_info->flags & VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT) ==
                VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT)
            {
                uses_address         = true;
                incoming_alloc_flags = alloc_flags_info->flags;
                alloc_flags_info->flags |= VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
                modified_alloc_flags = &(alloc_flags_info->flags);
            }
        }
    }

    if (IsPageGuardMemoryModeExternal())
    {
        VkMemoryPropertyFlags properties = GetMemoryProperties(device_wrapper, pAllocateInfo->memoryTypeIndex);

        if ((properties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
        {
            // Use the external memory extension to provide a memory allocation that can be watched directly by the page
            // guard implementation.
            assert(pAllocateInfo_unwrapped != nullptr);

            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pAllocateInfo_unwrapped->allocationSize);

            // TODO: This should be aligned to minImportedHostPointerAlignment, but there is a currently a loader bug
            // that prevents the layer from querying for that value when a 1.0 application does not explicitly enable
            // physical_device_properties2.  For now we align to system page size.
            size_t external_memory_size =
                manager->GetAlignedSize(static_cast<size_t>(pAllocateInfo_unwrapped->allocationSize));
            external_memory = manager->AllocateMemory(external_memory_size, true);

            if (external_memory != nullptr)
            {
                pAllocateInfo_unwrapped->allocationSize = external_memory_size;

                import_info.sType        = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT;
                import_info.pNext        = nullptr;
                import_info.handleType   = VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT;
                import_info.pHostPointer = external_memory;

                // TODO: Check pNext chain for use of incompatible extension types.
                VkBaseOutStructure* end = reinterpret_cast<VkBaseOutStructure*>(pAllocateInfo_unwrapped);
                while (end->pNext != nullptr)
                {
                    end = end->pNext;
                }

                end->pNext = reinterpret_cast<VkBaseOutStructure*>(&import_info);
            }
        }
    }

    result = vulkan_wrappers::GetDeviceTable(device)->AllocateMemory(
        device_unwrapped, pAllocateInfo_unwrapped, pAllocator, pMemory);

    if (result == VK_SUCCESS)
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::DeviceMemoryWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pMemory, GetUniqueId);

        assert(pMemory != nullptr);
        auto memory_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(*pMemory);

        if (uses_address)
        {
            // Restore modified allocation flags
            assert(modified_alloc_flags != nullptr);
            *modified_alloc_flags = incoming_alloc_flags;

            VkDeviceMemoryOpaqueCaptureAddressInfo info{ VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO,
                                                         nullptr,
                                                         memory_wrapper->handle };

            uint64_t address = 0;
            if (device_wrapper->physical_device->instance_api_version >= VK_MAKE_VERSION(1, 2, 0))
            {
                address = vulkan_wrappers::GetDeviceTable(device)->GetDeviceMemoryOpaqueCaptureAddress(device_unwrapped,
                                                                                                       &info);
            }
            else
            {
                address = vulkan_wrappers::GetDeviceTable(device)->GetDeviceMemoryOpaqueCaptureAddressKHR(
                    device_unwrapped, &info);
            }

            WriteSetOpaqueAddressCommand(device_wrapper->handle_id, memory_wrapper->handle_id, address);

            if (IsCaptureModeTrack())
            {
                state_tracker_->TrackDeviceMemoryDeviceAddress(device, *pMemory, address);
            }
        }

        memory_wrapper->external_allocation = external_memory;

        if (!IsCaptureModeTrack())
        {
            // The state tracker will set this value when it is enabled. When state tracking is disabled it is set
            // here to ensure it is available for mapped memory tracking.
            memory_wrapper->allocation_size = pAllocateInfo->allocationSize;
        }

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        if (auto import_ahb_info =
                graphics::vulkan_struct_get_pnext<VkImportAndroidHardwareBufferInfoANDROID>(pAllocateInfo_unwrapped))
        {
            if (import_ahb_info->buffer != nullptr)
            {
                ProcessImportAndroidHardwareBuffer(device, *pMemory, import_ahb_info->buffer);
            }
        }
#endif
    }
    else if (external_memory != nullptr)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        size_t external_memory_size = manager->GetAlignedSize(static_cast<size_t>(pAllocateInfo->allocationSize));
        manager->FreeMemory(external_memory, external_memory_size);
    }

    return result;
}

VkResult VulkanCaptureManager::OverrideGetPhysicalDeviceToolPropertiesEXT(
    VkPhysicalDevice physicalDevice, uint32_t* pToolCount, VkPhysicalDeviceToolPropertiesEXT* pToolProperties)
{
    auto original_pToolProperties = pToolProperties;
    if (pToolProperties != nullptr)
    {
        pToolProperties->sType    = VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT;
        pToolProperties->pNext    = nullptr;
        pToolProperties->purposes = VK_TOOL_PURPOSE_TRACING_BIT_EXT;

        util::platform::StringCopy(pToolProperties->name,
                                   VK_MAX_EXTENSION_NAME_SIZE,
                                   GFXRECON_PROJECT_NAME,
                                   util::platform::StringLength(GFXRECON_PROJECT_NAME));

        util::platform::StringCopy(pToolProperties->version,
                                   VK_MAX_EXTENSION_NAME_SIZE,
                                   GFXRECON_PROJECT_VERSION_STRING,
                                   util::platform::StringLength(GFXRECON_PROJECT_VERSION_STRING));

        util::platform::StringCopy(pToolProperties->description,
                                   VK_MAX_DESCRIPTION_SIZE,
                                   GFXRECON_PROJECT_DESCRIPTION,
                                   util::platform::StringLength(GFXRECON_PROJECT_DESCRIPTION));

        util::platform::StringCopy(pToolProperties->layer,
                                   VK_MAX_EXTENSION_NAME_SIZE,
                                   GFXRECON_PROJECT_VULKAN_LAYER_NAME,
                                   util::platform::StringLength(GFXRECON_PROJECT_VULKAN_LAYER_NAME));

        if (pToolCount != nullptr)
        {
            pToolProperties = ((*pToolCount > 1) ? &pToolProperties[1] : nullptr);
            --(*pToolCount);
        }
    }

    VkResult result = vulkan_wrappers::GetInstanceTable(physicalDevice)
                          ->GetPhysicalDeviceToolPropertiesEXT(physicalDevice, pToolCount, pToolProperties);

    if (original_pToolProperties != nullptr)
    {
        pToolProperties = original_pToolProperties;
    }

    if (pToolCount != nullptr)
    {
        ++(*pToolCount);
    }

    return result;
}

VkResult
VulkanCaptureManager::OverrideCreateRayTracingPipelinesKHR(VkDevice                                 device,
                                                           VkDeferredOperationKHR                   deferredOperation,
                                                           VkPipelineCache                          pipelineCache,
                                                           uint32_t                                 createInfoCount,
                                                           const VkRayTracingPipelineCreateInfoKHR* pCreateInfos,
                                                           const VkAllocationCallbacks*             pAllocator,
                                                           VkPipeline*                              pPipelines)
{
    auto                     device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    const VulkanDeviceTable* device_table   = vulkan_wrappers::GetDeviceTable(device);
    auto                     deferred_operation_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(deferredOperation);

    HandleUnwrapMemory* handle_unwrap_memory = nullptr;

    if (deferred_operation_wrapper)
    {
        handle_unwrap_memory = &deferred_operation_wrapper->handle_unwrap_memory;
        if (pAllocator)
        {
            deferred_operation_wrapper->allocator   = *pAllocator;
            deferred_operation_wrapper->p_allocator = &deferred_operation_wrapper->allocator;
        }
        else
        {
            deferred_operation_wrapper->allocator   = {};
            deferred_operation_wrapper->p_allocator = nullptr;
        }
        deferred_operation_wrapper->create_infos.resize(createInfoCount);
        deferred_operation_wrapper->pipelines.resize(createInfoCount);
        deferred_operation_wrapper->pPipelines    = pPipelines;
        deferred_operation_wrapper->pipelineCache = pipelineCache;
    }
    else
    {
        handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    }
    const VkRayTracingPipelineCreateInfoKHR* pCreateInfos_unwrapped =
        vulkan_wrappers::UnwrapStructArrayHandles(pCreateInfos, createInfoCount, handle_unwrap_memory);

    VkResult result;
    if (device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
    {
        auto modified_create_infos = std::make_unique<VkRayTracingPipelineCreateInfoKHR[]>(createInfoCount);
        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            modified_create_infos[i] = pCreateInfos_unwrapped[i];
            modified_create_infos[i].flags |= VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR;
        }
        if (deferred_operation_wrapper)
        {
            deferred_operation_wrapper->create_infos.clear();
            deferred_operation_wrapper->create_infos.insert(deferred_operation_wrapper->create_infos.end(),
                                                            &modified_create_infos.get()[0],
                                                            &modified_create_infos.get()[createInfoCount]);
            result = device_table->CreateRayTracingPipelinesKHR(device,
                                                                deferredOperation,
                                                                pipelineCache,
                                                                createInfoCount,
                                                                deferred_operation_wrapper->create_infos.data(),
                                                                deferred_operation_wrapper->p_allocator,
                                                                deferred_operation_wrapper->pipelines.data());

            if ((result == VK_OPERATION_NOT_DEFERRED_KHR) || (result == VK_SUCCESS))
            {
                // VK_OPERATION_NOT_DEFERRED_KHR means the operation successfully completed immediately, so here we copy
                // the created pipelines to original array which is used to store them by target application.
                //
                // Note:
                //       VK_OPERATION_DEFERRED_KHR means the operation is successfully deferred, but the pipeline
                //       creation might not be finished. We must therefore lean on
                //       vkDeferredOperationJoinKHR/vkGetDeferredOperationResultKHR to get the final result. If the
                //       result indicated the operation has finished, then the created pipelines are ready for use.
                //
                //       By Vulkan doc of VK_KHR_deferred_host_operations, if deferred operation object was
                //       provided and the operation successfully completed immediately without deferring, the
                //       command return VK_OPERATION_NOT_DEFERRED_KHR. Some hardware/driver may return VK_SUCCESS on
                //       such case, so same handling is proceeded with VK_SUCCESS.
                //
                std::memcpy(
                    pPipelines, deferred_operation_wrapper->pipelines.data(), sizeof(VkPipeline) * createInfoCount);
            }
            else if (result == VK_OPERATION_DEFERRED_KHR)
            {
                const std::lock_guard<std::mutex> lock(deferred_operation_mutex);
                deferred_operation_wrapper->pending_state = true;
            }
        }
        else
        {
            result = device_table->CreateRayTracingPipelinesKHR(device,
                                                                deferredOperation,
                                                                pipelineCache,
                                                                createInfoCount,
                                                                modified_create_infos.get(),
                                                                pAllocator,
                                                                pPipelines);
        }
    }
    else
    {
        GFXRECON_LOG_ERROR_ONCE(
            "The capturing application used vkCreateRayTracingPipelinesKHR, which may require the "
            "rayTracingPipelineShaderGroupHandleCaptureReplay feature for accurate capture and replay. The capturing "
            "device does not support this feature, so replay may fail.");

        if (deferred_operation_wrapper)
        {
            deferred_operation_wrapper->create_infos.clear();
            deferred_operation_wrapper->create_infos.insert(deferred_operation_wrapper->create_infos.end(),
                                                            &pCreateInfos_unwrapped[0],
                                                            &pCreateInfos_unwrapped[createInfoCount]);
            result = device_table->CreateRayTracingPipelinesKHR(device,
                                                                deferredOperation,
                                                                pipelineCache,
                                                                createInfoCount,
                                                                deferred_operation_wrapper->create_infos.data(),
                                                                deferred_operation_wrapper->p_allocator,
                                                                deferred_operation_wrapper->pipelines.data());
            if ((result == VK_OPERATION_NOT_DEFERRED_KHR) || (result == VK_SUCCESS))
            {
                // If the driver doesn't defer the command, and instead completed the operation immediately, we copy the
                // created pipelines to original array which is used to store them by target application.
                std::memcpy(
                    pPipelines, deferred_operation_wrapper->pipelines.data(), sizeof(VkPipeline) * createInfoCount);
            }
            else if (result == VK_OPERATION_DEFERRED_KHR)
            {
                const std::lock_guard<std::mutex> lock(deferred_operation_mutex);
                deferred_operation_wrapper->pending_state = true;
            }
        }
        else
        {
            result = device_table->CreateRayTracingPipelinesKHR(device,
                                                                deferredOperation,
                                                                pipelineCache,
                                                                createInfoCount,
                                                                pCreateInfos_unwrapped,
                                                                pAllocator,
                                                                pPipelines);
        }
    }

    if (((result == VK_SUCCESS) || (result == VK_OPERATION_NOT_DEFERRED_KHR)) && (pPipelines != nullptr))
    {
        // If the return result show the creation is successfully finished, we do the following process.

        vulkan_wrappers::CreateWrappedHandles<vulkan_wrappers::DeviceWrapper,
                                              vulkan_wrappers::DeferredOperationKHRWrapper,
                                              vulkan_wrappers::PipelineWrapper>(
            device, deferredOperation, pPipelines, createInfoCount, GetUniqueId);

        for (uint32_t i = 0; i < createInfoCount; ++i)
        {
            auto pipeline_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(pPipelines[i]);

            if (deferred_operation_wrapper)
            {
                // We need to set device_id here because some hardware may not have the feature
                // rayTracingPipelineShaderGroupHandleCaptureReplay so the device_id cannot be set by
                // VulkanStateTracker::TrackRayTracingShaderGroupHandles
                pipeline_wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
                pipeline_wrapper->deferred_operation.handle_id         = deferred_operation_wrapper->handle_id;
                pipeline_wrapper->deferred_operation.create_call_id    = deferred_operation_wrapper->create_call_id;
                pipeline_wrapper->deferred_operation.create_parameters = deferred_operation_wrapper->create_parameters;
            }
            if (device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
            {
                uint32_t data_size = device_wrapper->property_feature_info.property_shaderGroupHandleCaptureReplaySize *
                                     pCreateInfos[i].groupCount;
                std::vector<uint8_t> data(data_size);

                result = device_table->GetRayTracingCaptureReplayShaderGroupHandlesKHR(
                    device, pipeline_wrapper->handle, 0, pCreateInfos[i].groupCount, data_size, data.data());

                if (result == VK_SUCCESS)
                {
                    WriteSetRayTracingShaderGroupHandlesCommand(
                        device_wrapper->handle_id, pipeline_wrapper->handle_id, data_size, data.data());

                    if (IsCaptureModeTrack())
                    {
                        state_tracker_->TrackRayTracingShaderGroupHandles(
                            device, pPipelines[i], data_size, data.data());
                    }
                }
            }
        }
    }

    return result;
}

void VulkanCaptureManager::DeferredOperationPostProcess(VkDevice               device,
                                                        VkDeferredOperationKHR deferredOperation,
                                                        bool                   capture_manager_tracking)
{
    const std::lock_guard<std::mutex> lock(deferred_operation_mutex);
    VkResult                          result = VK_SUCCESS;
    auto                              deferred_operation_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::DeferredOperationKHRWrapper>(deferredOperation);
    auto                     device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    const VulkanDeviceTable* device_table   = vulkan_wrappers::GetDeviceTable(device);

    GFXRECON_ASSERT(device_table != nullptr);

    if ((deferred_operation_wrapper != nullptr) && (deferred_operation_wrapper->pending_state))
    {
        deferred_operation_wrapper->pending_state = false;
        uint32_t create_info_count                = deferred_operation_wrapper->create_infos.size();
        std::memcpy(deferred_operation_wrapper->pPipelines,
                    deferred_operation_wrapper->pipelines.data(),
                    sizeof(VkPipeline) * deferred_operation_wrapper->create_infos.size());

        vulkan_wrappers::CreateWrappedHandles<vulkan_wrappers::DeviceWrapper,
                                              vulkan_wrappers::DeferredOperationKHRWrapper,
                                              vulkan_wrappers::PipelineWrapper>(
            device, deferredOperation, deferred_operation_wrapper->pPipelines, create_info_count, GetUniqueId);

        for (uint32_t i = 0; i < create_info_count; ++i)
        {
            auto pipeline_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PipelineWrapper>(
                deferred_operation_wrapper->pPipelines[i]);

            if (deferred_operation_wrapper)
            {
                // We need to set device_id here because some hardware may not have the feature
                // rayTracingPipelineShaderGroupHandleCaptureReplay so the device_id cannot be set by
                // VulkanStateTracker::TrackRayTracingShaderGroupHandles
                pipeline_wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
                pipeline_wrapper->deferred_operation.handle_id         = deferred_operation_wrapper->handle_id;
                pipeline_wrapper->deferred_operation.create_call_id    = deferred_operation_wrapper->create_call_id;
                pipeline_wrapper->deferred_operation.create_parameters = deferred_operation_wrapper->create_parameters;
            }

            if (device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
            {
                const uint32_t data_size =
                    device_wrapper->property_feature_info.property_shaderGroupHandleCaptureReplaySize *
                    deferred_operation_wrapper->create_infos[i].groupCount;

                std::vector<uint8_t> data(data_size);
                result = device_table->GetRayTracingCaptureReplayShaderGroupHandlesKHR(
                    device_wrapper->handle,
                    pipeline_wrapper->handle,
                    0,
                    deferred_operation_wrapper->create_infos[i].groupCount,
                    data_size,
                    data.data());

                if (result == VK_SUCCESS)
                {
                    WriteSetRayTracingShaderGroupHandlesCommand(
                        device_wrapper->handle_id, pipeline_wrapper->handle_id, data_size, data.data());

                    if (capture_manager_tracking == true)
                    {
                        state_tracker_->TrackRayTracingShaderGroupHandles(
                            device, deferred_operation_wrapper->pPipelines[i], data_size, data.data());
                    }
                }
            }
        }

        // When the command vkCreateRayTracingPipelinesKHR is deferred at capture time, the created pipelines might not
        // be ready on the return of the API call, because the pipeline creation workload might not be finished. But for
        // replay time, we must guarantee the data relevant to vkGetRayTracingCaptureReplayShaderGroupHandlesKHR is
        // ready before calling vkCreateRaytracingPipelines so shader group handles during playback are the same with
        // capture time. The special handling needed here that when the command vkCreateRayTracingPipelinesKHR is
        // deferred, the writing of its block will be delayed writing to file, until it is confirmed that the deferred
        // command is finished.
        auto encoder = BeginTrackedApiCallCapture(format::ApiCallId::ApiCall_vkCreateRayTracingPipelinesKHR);

        if (encoder)
        {
            encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeviceWrapper>(device);
            encoder->EncodeVulkanHandleValue<vulkan_wrappers::DeferredOperationKHRWrapper>(deferredOperation);
            encoder->EncodeVulkanHandleValue<vulkan_wrappers::PipelineCacheWrapper>(
                deferred_operation_wrapper->pipelineCache);
            encoder->EncodeUInt32Value(create_info_count);
            EncodeStructArray(encoder, deferred_operation_wrapper->create_infos.data(), create_info_count);
            EncodeStructPtr(encoder, deferred_operation_wrapper->p_allocator);
            encoder->EncodeVulkanHandleArray<vulkan_wrappers::PipelineWrapper>(
                deferred_operation_wrapper->pPipelines, create_info_count, false);
            encoder->EncodeEnumValue(VK_OPERATION_DEFERRED_KHR);
            EndGroupCreateApiCallCapture<VkDevice,
                                         VkDeferredOperationKHR,
                                         vulkan_wrappers::PipelineWrapper,
                                         VkRayTracingPipelineCreateInfoKHR>(
                result,
                device,
                deferredOperation,
                create_info_count,
                deferred_operation_wrapper->pPipelines,
                deferred_operation_wrapper->create_infos.data());
        }
    }
}

VkResult VulkanCaptureManager::OverrideDeferredOperationJoinKHR(VkDevice device, VkDeferredOperationKHR operation)
{
    auto device_table = vulkan_wrappers::GetDeviceTable(device);
    GFXRECON_ASSERT(device_table != nullptr);
    VkResult result = device_table->DeferredOperationJoinKHR(device, operation);

    if (result == VK_SUCCESS)
    {
        // The deferred operation done and we continue to get the deferred command return value.
        VkResult deferred_command_result = device_table->GetDeferredOperationResultKHR(device, operation);

        if ((deferred_command_result == VK_SUCCESS) || (deferred_command_result == VK_OPERATION_NOT_DEFERRED_KHR))
        {
            DeferredOperationPostProcess(device, operation, IsCaptureModeTrack());
        }
    }

    return result;
}

VkResult VulkanCaptureManager::OverrideGetDeferredOperationResultKHR(VkDevice device, VkDeferredOperationKHR operation)
{
    auto device_table = vulkan_wrappers::GetDeviceTable(device);
    GFXRECON_ASSERT(device_table != nullptr);
    VkResult result = device_table->GetDeferredOperationResultKHR(device, operation);

    if ((result == VK_SUCCESS) || (result == VK_OPERATION_NOT_DEFERRED_KHR))
    {
        // There are the following two cases with VK_SUCCESS for vkGetDeferredOperationResultKHR. Both are covered by
        // DeferredOperationPostProcess. We also provide same handling for VK_OPERATION_NOT_DEFERRED_KHR in case some
        // hardware/driver return VK_OPERATION_NOT_DEFERRED_KHR:
        //    1. The deferred operation finished and returned VK_SUCCESS.
        //    2. No command has been deferred on the deferred operation object.
        DeferredOperationPostProcess(device, operation, IsCaptureModeTrack());
    }

    return result;
}

void VulkanCaptureManager::OverrideGetPhysicalDeviceQueueFamilyProperties(
    VkPhysicalDevice         physicalDevice,
    uint32_t*                pQueueFamilyPropertyCount,
    VkQueueFamilyProperties* pQueueFamilyProperties)
{
    GFXRECON_ASSERT(pQueueFamilyPropertyCount != nullptr);

    vulkan_wrappers::GetInstanceTable(physicalDevice)
        ->GetPhysicalDeviceQueueFamilyProperties(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    if (GetQueueZeroOnly())
    {
        *pQueueFamilyPropertyCount = 1;
        if (pQueueFamilyProperties != nullptr)
        {
            pQueueFamilyProperties[0].queueCount = 1;
        }
    }
}

void VulkanCaptureManager::OverrideGetPhysicalDeviceQueueFamilyProperties2(
    VkPhysicalDevice          physicalDevice,
    uint32_t*                 pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2* pQueueFamilyProperties)
{
    GFXRECON_ASSERT(pQueueFamilyPropertyCount != nullptr);

    vulkan_wrappers::GetInstanceTable(physicalDevice)
        ->GetPhysicalDeviceQueueFamilyProperties2(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    if (GetQueueZeroOnly())
    {
        *pQueueFamilyPropertyCount = 1;
        if (pQueueFamilyProperties != nullptr)
        {
            pQueueFamilyProperties[0].queueFamilyProperties.queueCount = 1;
        }
    }
}

void VulkanCaptureManager::OverrideGetPhysicalDeviceQueueFamilyProperties2KHR(
    VkPhysicalDevice          physicalDevice,
    uint32_t*                 pQueueFamilyPropertyCount,
    VkQueueFamilyProperties2* pQueueFamilyProperties)
{
    GFXRECON_ASSERT(pQueueFamilyPropertyCount != nullptr);

    vulkan_wrappers::GetInstanceTable(physicalDevice)
        ->GetPhysicalDeviceQueueFamilyProperties2KHR(physicalDevice, pQueueFamilyPropertyCount, pQueueFamilyProperties);

    if (GetQueueZeroOnly())
    {
        *pQueueFamilyPropertyCount = 1;
        if (pQueueFamilyProperties != nullptr)
        {
            pQueueFamilyProperties[0].queueFamilyProperties.queueCount = 1;
        }
    }
}

void VulkanCaptureManager::ProcessEnumeratePhysicalDevices(VkResult          result,
                                                           VkInstance        instance,
                                                           uint32_t          count,
                                                           VkPhysicalDevice* devices)
{
    assert(devices != nullptr);

    auto instance_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::InstanceWrapper>(instance);
    assert(instance_wrapper != nullptr);

    // Write meta-data describing physical device properties on first call to vkEnumeratePhysicalDevices or
    // vkEnumeratePhysicalDeviceGroups.
    if (!instance_wrapper->have_device_properties)
    {
        // Only filter duplicate checks when we have a complete list of physical devices.
        if (result != VK_INCOMPLETE)
        {
            instance_wrapper->have_device_properties = true;
        }

        for (uint32_t i = 0; i < count; ++i)
        {
            VkPhysicalDevice physical_device = devices[i];

            if (physical_device != VK_NULL_HANDLE)
            {
                const VulkanInstanceTable* instance_table = vulkan_wrappers::GetInstanceTable(physical_device);
                assert(instance_table != nullptr);

                auto physical_device_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physical_device);
                format::HandleId physical_device_id     = physical_device_wrapper->handle_id;
                VkPhysicalDevice physical_device_handle = physical_device_wrapper->handle;
                uint32_t         count                  = 0;

                VkPhysicalDeviceProperties       properties;
                VkPhysicalDeviceMemoryProperties memory_properties;

                instance_table->GetPhysicalDeviceProperties(physical_device_handle, &properties);
                instance_table->GetPhysicalDeviceMemoryProperties(physical_device_handle, &memory_properties);

                if (IsCaptureModeTrack())
                {
                    // Let the state tracker process the memory properties.
                    assert(state_tracker_ != nullptr);
                    state_tracker_->TrackPhysicalDeviceMemoryProperties(physical_device, &memory_properties);
                }
                else
                {
                    // When not tracking state, set the memory types directly.
                    physical_device_wrapper->memory_properties = std::move(memory_properties);
                }

                physical_device_wrapper->instance_api_version = instance_wrapper->api_version;

                WriteSetDevicePropertiesCommand(physical_device_id, properties);
                WriteSetDeviceMemoryPropertiesCommand(physical_device_id, physical_device_wrapper->memory_properties);
            }
        }
    }
}

VkMemoryPropertyFlags VulkanCaptureManager::GetMemoryProperties(vulkan_wrappers::DeviceWrapper* device_wrapper,
                                                                uint32_t                        memory_type_index)
{
    vulkan_wrappers::PhysicalDeviceWrapper* physical_device_wrapper = device_wrapper->physical_device;
    const VkPhysicalDeviceMemoryProperties* memory_properties       = &physical_device_wrapper->memory_properties;

    assert(memory_type_index < memory_properties->memoryTypeCount);

    return memory_properties->memoryTypes[memory_type_index].propertyFlags;
}

void VulkanCaptureManager::ProcessReferenceToAndroidHardwareBuffer(VkDevice device, AHardwareBuffer* hardware_buffer)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    assert(hardware_buffer != nullptr);
    auto     device_wrapper   = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice device_unwrapped = device_wrapper->handle;
    auto     device_table     = vulkan_wrappers::GetDeviceTable(device);

    auto entry = hardware_buffers_.find(hardware_buffer);
    if (entry == hardware_buffers_.end())
    {
        // If this is the first device memory object to reference the hardware buffer, write a buffer creation
        // command to the capture file and setup memory tracking.

        std::vector<format::HardwareBufferPlaneInfo> plane_info;

        AHardwareBuffer_Desc desc;
        AHardwareBuffer_describe(hardware_buffer, &desc);

        if ((desc.usage & AHARDWAREBUFFER_USAGE_CPU_READ_MASK) != 0)
        {
            void* data   = nullptr;
            int   result = -1;

            // The multi-plane functions are declared for API 26, but are only available to link with API 29.  So, this
            // could be turned into a run-time check dependent on dlsym returning a valid pointer for
            // AHardwareBuffer_lockPlanes.
#if __ANDROID_API__ >= 29
            AHardwareBuffer_Planes ahb_planes;
            result = AHardwareBuffer_lockPlanes(
                hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, nullptr, &ahb_planes);
            if (result == 0)
            {
                data = ahb_planes.planes[0].data;

                for (uint32_t i = 0; i < ahb_planes.planeCount; ++i)
                {
                    format::HardwareBufferPlaneInfo ahb_plane_info;
                    ahb_plane_info.offset =
                        reinterpret_cast<uint8_t*>(ahb_planes.planes[i].data) - reinterpret_cast<uint8_t*>(data);
                    ahb_plane_info.pixel_stride = ahb_planes.planes[i].pixelStride;
                    ahb_plane_info.row_pitch    = ahb_planes.planes[i].rowStride;
                    plane_info.emplace_back(std::move(ahb_plane_info));
                }
            }
            else
            {
                GFXRECON_LOG_WARNING("AHardwareBuffer_lockPlanes failed: AHardwareBuffer_lock will be used instead");
            }
#endif

            // Only store buffer IDs and reference count if a creation command is written to the capture file.
            format::HandleId memory_id = GetUniqueId();

            HardwareBufferInfo& ahb_info = hardware_buffers_[hardware_buffer];
            ahb_info.memory_id           = memory_id;
            ahb_info.reference_count     = 0;

            // Write CreateHardwareBufferCmd with or without the AHB payload
            WriteCreateHardwareBufferCmd(memory_id, hardware_buffer, plane_info);

            // Query the AHB size
            VkAndroidHardwareBufferPropertiesANDROID properties = {
                VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID
            };
            properties.pNext = nullptr;

            VkResult vk_result =
                device_table->GetAndroidHardwareBufferPropertiesANDROID(device_unwrapped, hardware_buffer, &properties);

            if (vk_result == VK_SUCCESS)
            {
                const size_t ahb_size = properties.allocationSize;
                assert(ahb_size);

                // If AHardwareBuffer_lockPlanes() failed (or is not available) try AHardwareBuffer_lock()
                if (result != 0)
                {
                    result =
                        AHardwareBuffer_lock(hardware_buffer, AHARDWAREBUFFER_USAGE_CPU_READ_OFTEN, -1, nullptr, &data);
                }

                if (result == 0 && data != nullptr)
                {
                    WriteFillMemoryCmd(memory_id, 0, ahb_size, data);

                    // Track the memory with the PageGuardManager
                    if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
                         GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
                        GetPageGuardTrackAhbMemory())
                    {
                        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, ahb_size);

                        util::PageGuardManager* manager = util::PageGuardManager::Get();
                        assert(manager != nullptr);

                        manager->AddTrackedMemory(memory_id,
                                                  data,
                                                  0,
                                                  static_cast<size_t>(ahb_size),
                                                  util::PageGuardManager::kNullShadowHandle,
                                                  false,  // No shadow memory for the imported AHB memory.
                                                  false); // Write watch is not supported for this case.
                    }

                    result = AHardwareBuffer_unlock(hardware_buffer, nullptr);
                    if (result != 0)
                    {
                        GFXRECON_LOG_ERROR("AHardwareBuffer_unlock failed");
                    }
                }
                else
                {
                    GFXRECON_LOG_ERROR(
                        "AHardwareBuffer_lock failed: hardware buffer data will be omitted from the capture file");

                    // Dump zeros for AHB payload.
                    std::vector<uint8_t> zeros(ahb_size, 0);
                    WriteFillMemoryCmd(memory_id, 0, ahb_size, zeros.data());
                }
            }
            else
            {
                GFXRECON_LOG_ERROR(
                    "GetAndroidHardwareBufferPropertiesANDROID failed: hardware buffer data will be omitted "
                    "from the capture file");

                // In case AHardwareBuffer_lockPlanes() succeeded
                if (result == 0)
                {
                    result = AHardwareBuffer_unlock(hardware_buffer, nullptr);
                    if (result != 0)
                    {
                        GFXRECON_LOG_ERROR("AHardwareBuffer_unlock failed");
                    }
                }
            }
        }
        else
        {
            // The AHB is not CPU-readable, so store only the creation command.
            // Only store buffer IDs and reference count if a creation command is written to the capture file.
            format::HandleId memory_id = GetUniqueId();

            HardwareBufferInfo& ahb_info = hardware_buffers_[hardware_buffer];
            ahb_info.memory_id           = memory_id;
            ahb_info.reference_count     = 0;

            WriteCreateHardwareBufferCmd(memory_id, hardware_buffer, plane_info);

            GFXRECON_LOG_WARNING("AHardwareBuffer cannot be read: hardware buffer data will be omitted "
                                 "from the capture file");
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void VulkanCaptureManager::ProcessImportAndroidHardwareBuffer(VkDevice         device,
                                                              VkDeviceMemory   memory,
                                                              AHardwareBuffer* hardware_buffer)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    GFXRECON_UNREFERENCED_PARAMETER(device);

    auto memory_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    assert((memory_wrapper != nullptr) && (hardware_buffer != nullptr));

    ProcessReferenceToAndroidHardwareBuffer(device, hardware_buffer);
    auto entry = hardware_buffers_.find(hardware_buffer);
    GFXRECON_ASSERT(entry != hardware_buffers_.end());

    ++entry->second.reference_count;

    memory_wrapper->hardware_buffer           = hardware_buffer;
    memory_wrapper->hardware_buffer_memory_id = entry->second.memory_id;
#else
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(memory);
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void VulkanCaptureManager::ReleaseAndroidHardwareBuffer(AHardwareBuffer* hardware_buffer)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    assert(hardware_buffer != nullptr);

    auto entry = hardware_buffers_.find(hardware_buffer);
    if ((entry != hardware_buffers_.end()) && (--entry->second.reference_count == 0))
    {
        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
            GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            manager->RemoveTrackedMemory(entry->second.memory_id);
        }

        // There are no more references to the buffer, so we can submit a destroy buffer command.
        WriteDestroyHardwareBufferCmd(entry->first);
        hardware_buffers_.erase(entry);
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void VulkanCaptureManager::PostProcess_vkEnumeratePhysicalDevices(VkResult          result,
                                                                  VkInstance        instance,
                                                                  uint32_t*         pPhysicalDeviceCount,
                                                                  VkPhysicalDevice* pPhysicalDevices)
{
    if ((result >= 0) && (pPhysicalDeviceCount != nullptr) && (pPhysicalDevices != nullptr))
    {
        ProcessEnumeratePhysicalDevices(result, instance, *pPhysicalDeviceCount, pPhysicalDevices);
    }
}

void VulkanCaptureManager::PostProcess_vkEnumeratePhysicalDeviceGroups(
    VkResult                         result,
    VkInstance                       instance,
    uint32_t*                        pPhysicalDeviceGroupCount,
    VkPhysicalDeviceGroupProperties* pPhysicalDeviceGroupProperties)
{
    if ((result >= 0) && (pPhysicalDeviceGroupCount != nullptr) && (pPhysicalDeviceGroupProperties != nullptr))
    {
        std::unordered_set<VkPhysicalDevice> unique_handles;
        uint32_t                             count = *pPhysicalDeviceGroupCount;

        // Build a list of retrieved physical device handles, filtering duplicates.
        for (uint32_t i = 0; i < count; ++i)
        {
            for (uint32_t j = 0; j < pPhysicalDeviceGroupProperties[i].physicalDeviceCount; ++j)
            {
                unique_handles.insert(pPhysicalDeviceGroupProperties[i].physicalDevices[j]);
            }
        }

        std::vector<VkPhysicalDevice> devices(unique_handles.begin(), unique_handles.end());

        ProcessEnumeratePhysicalDevices(result, instance, static_cast<uint32_t>(devices.size()), devices.data());
    }
}

void VulkanCaptureManager::PreProcess_vkCreateXlibSurfaceKHR(VkInstance                        instance,
                                                             const VkXlibSurfaceCreateInfoKHR* pCreateInfo,
                                                             const VkAllocationCallbacks*      pAllocator,
                                                             VkSurfaceKHR*                     pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);

#if defined(VK_USE_PLATFORM_XLIB_KHR)
    assert(pCreateInfo != nullptr);
    if (pCreateInfo && !GetTrimKey().empty())
    {
        if (!GetKeyboard().Initialize(pCreateInfo->dpy))
        {
            GFXRECON_LOG_ERROR("Failed to initialize Xlib keyboard capture trigger");
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    if (!GetTrimKey().empty())
    {
        GFXRECON_LOG_WARNING("Xlib keyboard capture trigger is not enabled on this system");
    }
#endif
}

void VulkanCaptureManager::PreProcess_vkCreateXcbSurfaceKHR(VkInstance                       instance,
                                                            const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                                            const VkAllocationCallbacks*     pAllocator,
                                                            VkSurfaceKHR*                    pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);

#if defined(VK_USE_PLATFORM_XCB_KHR)
    assert(pCreateInfo != nullptr);
    if (pCreateInfo && !GetTrimKey().empty())
    {
        if (!GetKeyboard().Initialize(pCreateInfo->connection))
        {
            GFXRECON_LOG_ERROR("Failed to initialize XCB keyboard capture trigger");
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    if (!GetTrimKey().empty())
    {
        GFXRECON_LOG_WARNING("Xcb keyboard capture trigger is not enabled on this system");
    }
#endif
}

void VulkanCaptureManager::PreProcess_vkCreateWaylandSurfaceKHR(VkInstance                           instance,
                                                                const VkWaylandSurfaceCreateInfoKHR* pCreateInfo,
                                                                const VkAllocationCallbacks*         pAllocator,
                                                                VkSurfaceKHR*                        pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);
    if (!GetTrimKey().empty())
    {
        GFXRECON_LOG_WARNING("Wayland keyboard capture trigger is not implemented");
    }
}

void VulkanCaptureManager::PreProcess_vkCreateSwapchain(VkDevice                        device,
                                                        const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                        const VkAllocationCallbacks*    pAllocator,
                                                        VkSwapchainKHR*                 pSwapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSwapchain);

    assert(pCreateInfo != nullptr);

    if (pCreateInfo)
    {
        WriteResizeWindowCmd2(vulkan_wrappers::GetWrappedId<vulkan_wrappers::SurfaceKHRWrapper>(pCreateInfo->surface),
                              pCreateInfo->imageExtent.width,
                              pCreateInfo->imageExtent.height,
                              pCreateInfo->preTransform);
    }
}

void VulkanCaptureManager::PostProcess_vkMapMemory(VkResult         result,
                                                   VkDevice         device,
                                                   VkDeviceMemory   memory,
                                                   VkDeviceSize     offset,
                                                   VkDeviceSize     size,
                                                   VkMemoryMapFlags flags,
                                                   void**           ppData)
{
    if ((result == VK_SUCCESS) && (ppData != nullptr))
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
        assert(wrapper != nullptr);

        if (wrapper->mapped_data == nullptr)
        {
            if (IsCaptureModeTrack())
            {
                assert(state_tracker_ != nullptr);
                state_tracker_->TrackMappedMemory(device, memory, (*ppData), offset, size, flags);
            }
            else
            {
                // Perform subset of the state tracking performed by VulkanStateTracker::TrackMappedMemory, only storing
                // values needed for non-tracking capture.
                wrapper->mapped_data   = (*ppData);
                wrapper->mapped_offset = offset;
                wrapper->mapped_size   = size;
            }

            if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
                GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
                    // Hardware buffer memory is tracked separately, so VkDeviceMemory mappings should be ignored to
                    // avoid duplicate memory tracking entries.
                    && (wrapper->hardware_buffer == nullptr)
#endif
            )
            {
                if (size == VK_WHOLE_SIZE)
                {
                    assert(offset <= wrapper->allocation_size);
                    size = wrapper->allocation_size - offset;
                }

                if (size > 0)
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, offset);
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    bool use_shadow_memory = true;
                    bool use_write_watch   = false;

                    if (IsPageGuardMemoryModeExternal())
                    {
                        use_shadow_memory = false;
                        use_write_watch   = true;
                    }
                    else if (IsPageGuardMemoryModeShadowPersistent() &&
                             (wrapper->shadow_allocation == util::PageGuardManager::kNullShadowHandle))
                    {
                        wrapper->shadow_allocation = manager->AllocatePersistentShadowMemory(static_cast<size_t>(size));
                    }

                    // Return the pointer provided by the pageguard manager, which may be a pointer to shadow memory,
                    // not the mapped memory.
                    (*ppData) = manager->AddTrackedMemory(wrapper->handle_id,
                                                          (*ppData),
                                                          static_cast<size_t>(offset),
                                                          static_cast<size_t>(size),
                                                          wrapper->shadow_allocation,
                                                          use_shadow_memory,
                                                          use_write_watch);
                }
            }
            else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
            {
                // Need to keep track of mapped memory objects so memory content can be written at queue submit.
                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
                mapped_memory_.insert(wrapper);
            }
        }
        else
        {
            // The application has mapped the same VkDeviceMemory object more than once and the pageguard
            // manager is already tracking it, so we will return the pointer obtained from the pageguard manager
            // on the first map call.
            GFXRECON_LOG_WARNING("VkDeviceMemory object with handle = %" PRIx64 " has been mapped more than once",
                                 memory);

            if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
                GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
            {
                assert((wrapper->mapped_offset == offset) && (wrapper->mapped_size == size));

                // Return the shadow memory that was allocated for the previous map operation.
                util::PageGuardManager* manager = util::PageGuardManager::Get();
                assert(manager != nullptr);

                if (!manager->GetTrackedMemory(wrapper->handle_id, ppData))
                {
                    GFXRECON_LOG_ERROR("Modifications to the VkDeviceMemory object that has been mapped more than once "
                                       "are not being track by PageGuardManager");
                }
            }
        }
    }
}

void VulkanCaptureManager::PreProcess_vkFlushMappedMemoryRanges(VkDevice                   device,
                                                                uint32_t                   memoryRangeCount,
                                                                const VkMappedMemoryRange* pMemoryRanges)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if (pMemoryRanges != nullptr)
    {
        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
            GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
        {
            const vulkan_wrappers::DeviceMemoryWrapper* current_memory_wrapper = nullptr;
            util::PageGuardManager*                     manager                = util::PageGuardManager::Get();
            assert(manager != nullptr);

            for (uint32_t i = 0; i < memoryRangeCount; ++i)
            {
                auto next_memory_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pMemoryRanges[i].memory);

                // Currently processing all dirty pages for the mapped memory, so filter multiple ranges from the same
                // object.
                if (next_memory_wrapper != current_memory_wrapper)
                {
                    current_memory_wrapper = next_memory_wrapper;

                    if ((current_memory_wrapper != nullptr) && (current_memory_wrapper->mapped_data != nullptr))
                    {
                        manager->ProcessMemoryEntry(
                            current_memory_wrapper->handle_id,
                            [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                                WriteFillMemoryCmd(memory_id, offset, size, start_address);
                            });
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING("vkFlushMappedMemoryRanges called for memory that is not mapped");
                    }
                }
            }
        }
        else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kAssisted)
        {
            const vulkan_wrappers::DeviceMemoryWrapper* current_memory_wrapper = nullptr;

            for (uint32_t i = 0; i < memoryRangeCount; ++i)
            {
                current_memory_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pMemoryRanges[i].memory);

                if ((current_memory_wrapper != nullptr) && (current_memory_wrapper->mapped_data != nullptr))
                {
                    assert(pMemoryRanges[i].offset >= current_memory_wrapper->mapped_offset);

                    // The mapped pointer already includes the mapped offset.  Because the memory range
                    // offset is relative to the start of the memory object, we need to adjust it to be
                    // relative to the start of the mapped pointer.
                    VkDeviceSize relative_offset = pMemoryRanges[i].offset - current_memory_wrapper->mapped_offset;
                    VkDeviceSize size            = pMemoryRanges[i].size;
                    if (size == VK_WHOLE_SIZE)
                    {
                        assert(pMemoryRanges[i].offset <= current_memory_wrapper->allocation_size);
                        size = current_memory_wrapper->allocation_size - pMemoryRanges[i].offset;
                    }

                    WriteFillMemoryCmd(
                        current_memory_wrapper->handle_id, relative_offset, size, current_memory_wrapper->mapped_data);
                }
            }
        }
    }
}

void VulkanCaptureManager::PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    assert(wrapper != nullptr);

    if (wrapper->mapped_data != nullptr)
    {
        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
            GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            manager->ProcessMemoryEntry(wrapper->handle_id,
                                        [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                                            WriteFillMemoryCmd(memory_id, offset, size, start_address);
                                        });

            manager->RemoveTrackedMemory(wrapper->handle_id);
        }
        else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
        {
            VkDeviceSize size = wrapper->mapped_size;
            if (size == VK_WHOLE_SIZE)
            {
                assert(wrapper->mapped_offset <= wrapper->allocation_size);
                size = wrapper->allocation_size - wrapper->mapped_offset;
            }

            // Write the entire mapped region.
            // We set offset to 0, because the pointer returned by vkMapMemory already includes the offset.
            WriteFillMemoryCmd(wrapper->handle_id, 0, size, wrapper->mapped_data);

            {
                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
                mapped_memory_.erase(wrapper);
            }
        }

        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackMappedMemory(device, memory, nullptr, 0, 0, 0);
        }
        else
        {
            // Perform subset of the state tracking performed by VulkanStateTracker::TrackMappedMemory, only storing
            // values needed for non-tracking capture.
            wrapper->mapped_data   = nullptr;
            wrapper->mapped_offset = 0;
            wrapper->mapped_size   = 0;
        }
    }
    else
    {
        GFXRECON_LOG_WARNING(
            "Attempting to unmap VkDeviceMemory object with handle = %" PRIx64 " that has not been mapped", memory);
    }
}

void VulkanCaptureManager::PreProcess_vkFreeMemory(VkDevice                     device,
                                                   VkDeviceMemory               memory,
                                                   const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if (memory != VK_NULL_HANDLE)
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);

        if (wrapper->mapped_data != nullptr)
        {
            if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
                GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
            {
                util::PageGuardManager* manager = util::PageGuardManager::Get();
                assert(manager != nullptr);

                // Remove memory tracking.
                manager->RemoveTrackedMemory(wrapper->handle_id);
            }
            else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
            {
                std::lock_guard<std::mutex> lock(GetMappedMemoryLock());
                mapped_memory_.erase(wrapper);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkFreeMemory(VkDevice                     device,
                                                    VkDeviceMemory               memory,
                                                    const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if (memory != VK_NULL_HANDLE)
    {
        // Destroy external resources.
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);

        if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
            GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            if ((IsPageGuardMemoryModeExternal()) && (wrapper->external_allocation != nullptr))
            {
                size_t external_memory_size = manager->GetAlignedSize(static_cast<size_t>(wrapper->allocation_size));
                manager->FreeMemory(wrapper->external_allocation, external_memory_size);
            }
            else if (IsPageGuardMemoryModeShadowPersistent() &&
                     (wrapper->shadow_allocation != util::PageGuardManager::kNullShadowHandle))
            {
                manager->FreePersistentShadowMemory(wrapper->shadow_allocation);
            }
        }

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
        if (wrapper->hardware_buffer != nullptr)
        {
            ReleaseAndroidHardwareBuffer(wrapper->hardware_buffer);
        }
#endif
    }
}

void VulkanCaptureManager::PostProcess_vkAcquireFullScreenExclusiveModeEXT(VkResult       result,
                                                                           VkDevice       device,
                                                                           VkSwapchainKHR swapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(swapchain);

    if (IsCaptureModeTrack())
    {
        assert(state_tracker_ != nullptr);
        state_tracker_->TrackAcquireFullScreenExclusiveMode(device, swapchain);
    }
}

void VulkanCaptureManager::PostProcess_vkGetPhysicalDeviceSurfacePresentModes2EXT(
    VkResult                               result,
    VkPhysicalDevice                       physicalDevice,
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
    uint32_t*                              pPresentModeCount,
    VkPresentModeKHR*                      pPresentModes)
{
    if ((pPresentModeCount != nullptr) && (pPresentModes != nullptr) && (pSurfaceInfo != nullptr))
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceSurfacePresentModes(
                physicalDevice, pSurfaceInfo->surface, *pPresentModeCount, pPresentModes, pSurfaceInfo->pNext);
        }

#if defined(__ANDROID__)
        OverrideGetPhysicalDeviceSurfacePresentModesKHR(pPresentModeCount, pPresentModes);
#endif
    }
}

void VulkanCaptureManager::PostProcess_vkReleaseFullScreenExclusiveModeEXT(VkResult       result,
                                                                           VkDevice       device,
                                                                           VkSwapchainKHR swapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(swapchain);

    if (IsCaptureModeTrack())
    {
        assert(state_tracker_ != nullptr);
        state_tracker_->TrackReleaseFullScreenExclusiveMode(device, swapchain);
    }
}

void VulkanCaptureManager::PostProcess_vkGetDeviceGroupSurfacePresentModesKHR(VkResult                          result,
                                                                              VkDevice                          device,
                                                                              VkSurfaceKHR                      surface,
                                                                              VkDeviceGroupPresentModeFlagsKHR* pModes)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if (pModes != nullptr)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackDeviceGroupSurfacePresentModes(device, surface, pModes);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkGetDeviceGroupSurfacePresentModes2EXT(
    VkResult                               result,
    VkDevice                               device,
    const VkPhysicalDeviceSurfaceInfo2KHR* pSurfaceInfo,
    VkDeviceGroupPresentModeFlagsKHR*      pModes)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if ((pSurfaceInfo != nullptr) && (pModes != nullptr))
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackDeviceGroupSurfacePresentModes(
                device, pSurfaceInfo->surface, pModes, pSurfaceInfo->pNext);
        }
    }
}

void VulkanCaptureManager::PreProcess_vkQueueSubmit(VkQueue             queue,
                                                    uint32_t            submitCount,
                                                    const VkSubmitInfo* pSubmits,
                                                    VkFence             fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_UNREFERENCED_PARAMETER(submitCount);
    GFXRECON_UNREFERENCED_PARAMETER(pSubmits);
    GFXRECON_UNREFERENCED_PARAMETER(fence);

    QueueSubmitWriteFillMemoryCmd();

    PreQueueSubmit();

    if (IsCaptureModeTrack())
    {
        if (pSubmits)
        {
            for (uint32_t s = 0; s < submitCount; ++s)
            {
                state_tracker_->TrackTlasToBlasDependencies(pSubmits[s].commandBufferCount,
                                                            pSubmits[s].pCommandBuffers);
            }
        }
    }
}

void VulkanCaptureManager::PreProcess_vkQueueSubmit2(VkQueue              queue,
                                                     uint32_t             submitCount,
                                                     const VkSubmitInfo2* pSubmits,
                                                     VkFence              fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_UNREFERENCED_PARAMETER(submitCount);
    GFXRECON_UNREFERENCED_PARAMETER(pSubmits);
    GFXRECON_UNREFERENCED_PARAMETER(fence);

    QueueSubmitWriteFillMemoryCmd();

    PreQueueSubmit();

    if (IsCaptureModeTrack())
    {
        std::vector<VkCommandBuffer> command_buffs;
        if (pSubmits)
        {
            for (uint32_t s = 0; s < submitCount; ++s)
            {
                if (pSubmits[s].pCommandBufferInfos)
                {
                    for (uint32_t c = 0; c < pSubmits[s].commandBufferInfoCount; ++c)
                    {
                        command_buffs.push_back(pSubmits[s].pCommandBufferInfos[c].commandBuffer);
                    }
                }
            }

            state_tracker_->TrackTlasToBlasDependencies(command_buffs.size(), command_buffs.data());
        }
    }
}

void VulkanCaptureManager::QueueSubmitWriteFillMemoryCmd()
{
    if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
        GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        manager->ProcessMemoryEntries([this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
            WriteFillMemoryCmd(memory_id, offset, size, start_address);
        });
    }
    else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUnassisted)
    {
        std::lock_guard<std::mutex> lock(GetMappedMemoryLock());

        for (auto wrapper : mapped_memory_)
        {
            VkDeviceSize size = wrapper->mapped_size;
            if (size == VK_WHOLE_SIZE)
            {
                assert(wrapper->mapped_offset <= wrapper->allocation_size);
                size = wrapper->allocation_size - wrapper->mapped_offset;
            }

            // If the memory is mapped, write the entire mapped region.
            // We set offset to 0, because the pointer returned by vkMapMemory already includes the offset.
            WriteFillMemoryCmd(wrapper->handle_id, 0, size, wrapper->mapped_data);
        }
    }
}

void VulkanCaptureManager::PreProcess_vkCreateDescriptorUpdateTemplate(
    VkResult                                    result,
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if ((result == VK_SUCCESS) && (pCreateInfo != nullptr) && (pDescriptorUpdateTemplate != nullptr))
    {
        SetDescriptorUpdateTemplateInfo((*pDescriptorUpdateTemplate), pCreateInfo);
    }
}

void VulkanCaptureManager::PreProcess_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    result,
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if ((result == VK_SUCCESS) && (pCreateInfo != nullptr) && (pDescriptorUpdateTemplate != nullptr))
    {
        SetDescriptorUpdateTemplateInfo((*pDescriptorUpdateTemplate), pCreateInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkGetBufferDeviceAddress(VkDeviceAddress                  result,
                                                                VkDevice                         device,
                                                                const VkBufferDeviceAddressInfo* pInfo)
{
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (!device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        GFXRECON_LOG_ERROR_ONCE(
            "The application is using vkGetBufferDeviceAddress, which requires the bufferDeviceAddressCaptureReplay "
            "feature for accurate capture and replay. The capture device does not support this feature, so replay of "
            "the captured file may fail.");
    }

    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackBufferDeviceAddress(device, pInfo->buffer, result);
    }
}

void VulkanCaptureManager::PreProcess_vkGetBufferOpaqueCaptureAddress(VkDevice                         device,
                                                                      const VkBufferDeviceAddressInfo* pInfo)
{
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (!device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        GFXRECON_LOG_ERROR_ONCE(
            "The application is using vkGetBufferOpaqueCaptureAddress, which requires the "
            "bufferDeviceAddressCaptureReplay "
            "feature for accurate capture and replay. The capture device does not support this feature, so replay of "
            "the captured file may fail.");
    }
}

void VulkanCaptureManager::PreProcess_vkGetDeviceMemoryOpaqueCaptureAddress(
    VkDevice device, const VkDeviceMemoryOpaqueCaptureAddressInfo* pInfo)
{
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (!device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        GFXRECON_LOG_ERROR_ONCE(
            "The application is using vkGetDeviceMemoryOpaqueCaptureAddress, which requires the "
            "bufferDeviceAddressCaptureReplay "
            "feature for accurate capture and replay. The capture device does not support this feature, so replay of "
            "the captured file may fail.");
    }
}

void VulkanCaptureManager::PreProcess_vkGetAccelerationStructureDeviceAddressKHR(
    VkDevice device, const VkAccelerationStructureDeviceAddressInfoKHR* pInfo)
{
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (!device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The application is using vkGetAccelerationStructureDeviceAddressKHR, which may require the "
            "accelerationStructureCaptureReplay feature for accurate capture and replay. The capture device does not "
            "support this feature, so replay of the captured file may fail.");
    }
}

void VulkanCaptureManager::PreProcess_vkGetRayTracingShaderGroupHandlesKHR(
    VkDevice device, VkPipeline pipeline, uint32_t firstGroup, uint32_t groupCount, size_t dataSize, void* pData)
{
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (!device_wrapper->property_feature_info.feature_rayTracingPipelineShaderGroupHandleCaptureReplay)
    {
        GFXRECON_LOG_WARNING_ONCE(
            "The application is using vkGetRayTracingShaderGroupHandlesKHR, which may require the "
            "rayTracingPipelineShaderGroupHandleCaptureReplay feature for accurate capture and replay. The capture "
            "device does not support this feature, so replay of the captured file may fail.");
    }
}

void VulkanCaptureManager::PreProcess_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                  device,
    const struct AHardwareBuffer*             hardware_buffer,
    VkAndroidHardwareBufferPropertiesANDROID* pProperties)
{
    GFXRECON_UNREFERENCED_PARAMETER(pProperties);
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    if (hardware_buffer != nullptr)
    {
        ProcessReferenceToAndroidHardwareBuffer(device, const_cast<AHardwareBuffer*>(hardware_buffer));
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
#endif
}

void VulkanCaptureManager::PostProcess_vkSetPrivateData(VkResult          result,
                                                        VkDevice          device,
                                                        VkObjectType      objectType,
                                                        uint64_t          objectHandle,
                                                        VkPrivateDataSlot privateDataSlot,
                                                        uint64_t          data)
{
    GFXRECON_UNREFERENCED_PARAMETER(privateDataSlot);

    if (privateDataSlot != VK_NULL_HANDLE)
    {
        if (IsCaptureModeTrack() && (result == VK_SUCCESS))
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackSetPrivateData(device, objectType, objectHandle, privateDataSlot, data);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkSetLocalDimmingAMD(VkDevice       device,
                                                            VkSwapchainKHR swapChain,
                                                            VkBool32       localDimmingEnable)
{
    GFXRECON_UNREFERENCED_PARAMETER(swapChain);

    if (swapChain != VK_NULL_HANDLE)
    {
        if (IsCaptureModeTrack())
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackSetLocalDimmingAMD(device, swapChain, localDimmingEnable);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDebugMarkerInsertEXT(VkCommandBuffer                   commandBuffer,
                                                                 const VkDebugMarkerMarkerInfoEXT* pMarkerInfo)
{
    if (pMarkerInfo != nullptr)
    {
        // Look for the debug marker that identifies this command buffer as a VR frame boundary.
        if (util::platform::StringContains(pMarkerInfo->pMarkerName, graphics::kVulkanVrFrameDelimiterString))
        {
            auto cmd_buffer_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
            GFXRECON_ASSERT(cmd_buffer_wrapper != nullptr);
            cmd_buffer_wrapper->is_frame_boundary = true;
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdInsertDebugUtilsLabelEXT(VkCommandBuffer             commandBuffer,
                                                                     const VkDebugUtilsLabelEXT* pLabelInfo)
{
    if (pLabelInfo != nullptr)
    {
        // Look for the label that identifies this command buffer as a VR frame boundary.
        if (util::platform::StringContains(pLabelInfo->pLabelName, graphics::kVulkanVrFrameDelimiterString))
        {
            auto cmd_buffer_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
            GFXRECON_ASSERT(cmd_buffer_wrapper != nullptr);
            cmd_buffer_wrapper->is_frame_boundary = true;
        }
    }
}

#if defined(__ANDROID__)
void VulkanCaptureManager::OverrideGetPhysicalDeviceSurfacePresentModesKHR(uint32_t*         pPresentModeCount,
                                                                           VkPresentModeKHR* pPresentModes)
{
    assert((pPresentModeCount != nullptr) && (pPresentModes != nullptr));

    if (common_manager_->GetForceFifoPresentModeSetting())
    {
        GFXRECON_LOG_WARNING_ONCE(
            "Force all present modes in vkGetPhysicalDeviceSurfacePresentModesKHR to VK_PRESENT_MODE_FIFO_KHR. "
            "The application will use VK_PRESENT_MODE_FIFO_KHR present mode in vkCreateSwapchainKHR, which may "
            "cause an unknown crash if the application does not use VK_PRESENT_MODE_FIFO_KHR present mode");

        for (uint32_t i = 0; i < (*pPresentModeCount); ++i)
        {
            pPresentModes[i] = VK_PRESENT_MODE_FIFO_KHR;
        }
    }
}
#endif

bool VulkanCaptureManager::CheckBindAlignment(VkDeviceSize memoryOffset)
{
    if ((GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kPageGuard ||
         GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kUserfaultfd) &&
        !GetPageGuardAlignBufferSizes())
    {
        return (memoryOffset % util::platform::GetSystemPageSize()) == 0;
    }

    return true;
}

bool VulkanCaptureManager::CheckCommandBufferWrapperForFrameBoundary(
    const vulkan_wrappers::CommandBufferWrapper* command_buffer_wrapper)
{
    GFXRECON_ASSERT(command_buffer_wrapper != nullptr);
    if (command_buffer_wrapper->is_frame_boundary)
    {
        // Do common capture manager end of frame processing.
        EndFrame();
        return true;
    }
    return false;
}

bool VulkanCaptureManager::CheckPNextChainForFrameBoundary(const VkBaseInStructure* current)
{
    if (auto frame_boundary = graphics::vulkan_struct_get_pnext<VkFrameBoundaryEXT>(current))
    {
        if (frame_boundary->flags & VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT)
        {
            EndFrame();
            return true;
        }
    }
    return false;
}

void VulkanCaptureManager::PreProcess_vkBindBufferMemory(VkDevice       device,
                                                         VkBuffer       buffer,
                                                         VkDeviceMemory memory,
                                                         VkDeviceSize   memoryOffset)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(buffer);
    GFXRECON_UNREFERENCED_PARAMETER(memory);

    if (!CheckBindAlignment(memoryOffset))
    {
        GFXRECON_LOG_WARNING_ONCE("Buffer bound to device memory at an offset which is not page aligned. Corruption "
                                  "might occur. In that case set "
                                  "Page Guard Align Buffer Sizes env variable to true.");
    }
}

void VulkanCaptureManager::PreProcess_vkBindBufferMemory2(VkDevice                      device,
                                                          uint32_t                      bindInfoCount,
                                                          const VkBindBufferMemoryInfo* pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        if (!CheckBindAlignment(pBindInfos[i].memoryOffset))
        {
            GFXRECON_LOG_WARNING_ONCE(
                "Buffer bound to device memory at an offset which is not page aligned. Corruption "
                "might occur. In that case set "
                "Page Guard Align Buffer Sizes env variable to true.");
        }
    }
}

void VulkanCaptureManager::PreProcess_vkBindImageMemory(VkDevice       device,
                                                        VkImage        image,
                                                        VkDeviceMemory memory,
                                                        VkDeviceSize   memoryOffset)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(image);
    GFXRECON_UNREFERENCED_PARAMETER(memory);

    if (!CheckBindAlignment(memoryOffset))
    {
        GFXRECON_LOG_WARNING_ONCE("Image bound to device memory at an offset which is not page aligned. Corruption "
                                  "might occur. In that case set "
                                  "Page Guard Align Buffer Sizes env variable to true.");
    }
}

void VulkanCaptureManager::PreProcess_vkBindImageMemory2(VkDevice                     device,
                                                         uint32_t                     bindInfoCount,
                                                         const VkBindImageMemoryInfo* pBindInfos)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    for (uint32_t i = 0; i < bindInfoCount; ++i)
    {
        if (!CheckBindAlignment(pBindInfos[i].memoryOffset))
        {
            GFXRECON_LOG_WARNING_ONCE("Image bound to device memory at an offset which is not page aligned. Corruption "
                                      "might occur. In that case set "
                                      "Page Guard Align Buffer Sizes env variable to true.");
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCreateShaderModule(VkResult                        result,
                                                            VkDevice                        device,
                                                            const VkShaderModuleCreateInfo* pCreateInfo,
                                                            const VkAllocationCallbacks*    pAllocator,
                                                            VkShaderModule*                 pShaderModule)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pShaderModule);

    if (result == VK_SUCCESS)
    {
        graphics::vulkan_check_buffer_references(pCreateInfo->pCode, pCreateInfo->codeSize);
    }
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
