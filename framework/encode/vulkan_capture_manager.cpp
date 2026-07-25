/*
 ** Copyright (c) 2018-2021 Valve Corporation
 ** Copyright (c) 2018-2025 LunarG, Inc.
 ** Copyright (c) 2019-2025 Advanced Micro Devices, Inc. All rights reserved.
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

#include "encode/capture_settings.h"
#include "encode/vulkan_handle_wrappers.h"
#include "graphics/vulkan_resources.h"
#include "vulkan/vulkan_core.h"
#include <cstdint>
#include PROJECT_VERSION_HEADER_FILE

#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_track_struct.h"
#include "encode/vulkan_capture_manager.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_state_writer.h"
#include "encode/vulkan_capture_common.h"
#include "encode/vulkan_capture_layer_settings.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "graphics/vulkan_check_buffer_references.h"
#include "graphics/vulkan_device_util.h"
#include "graphics/vulkan_struct_get_pnext.h"
#include "graphics/vulkan_util.h"
#include "graphics/vulkan_feature_util.h"
#include "util/compressor.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/platform.h"
#include "Vulkan-Utility-Libraries/vk_format_utils.h"

#include <algorithm>
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

std::mutex                 VulkanCaptureManager::instance_lock_;
VulkanCaptureManager*      VulkanCaptureManager::singleton_ = nullptr;
graphics::VulkanLayerTable VulkanCaptureManager::vulkan_layer_table_;

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
    std::lock_guard<std::mutex> instance_lock(instance_lock_);

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

void VulkanCaptureManager::WriteTrackedState(util::FileOutputStream* file_stream, util::ThreadData* thread_data)
{
    uint64_t n_blocks = state_tracker_->WriteState(
        file_stream, thread_data, [] { return GetUniqueId(); }, GetCompressor(), GetCurrentFrame(), nullptr, nullptr);

    common_manager_->IncrementBlockIndex(n_blocks);
}

void VulkanCaptureManager::WriteTrackedStateWithAssetFile(util::FileOutputStream* file_stream,
                                                          util::ThreadData*       thread_data,
                                                          util::FileOutputStream* asset_file_stream,
                                                          const std::string*      asset_file_name)
{
    uint64_t n_blocks = state_tracker_->WriteState(
        file_stream,
        thread_data,
        [] { return GetUniqueId(); },
        GetCompressor(),
        GetCurrentFrame(),
        asset_file_stream,
        asset_file_name);

    common_manager_->IncrementBlockIndex(n_blocks);
}

void VulkanCaptureManager::WriteAssets(util::FileOutputStream* asset_file_stream,
                                       const std::string*      asset_file_name,
                                       util::ThreadData*       thread_data)
{
    assert(state_tracker_ != nullptr);
    state_tracker_->WriteAssets(
        asset_file_stream, asset_file_name, thread_data, [] { return GetUniqueId(); }, GetCompressor());
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
    graphics::LoadVulkanInstanceTable(gpa, wrapper->handle, &wrapper->layer_table);
}

void VulkanCaptureManager::InitVkDevice(VkDevice* device, PFN_vkGetDeviceProcAddr gpa)
{
    assert((device != nullptr) && ((*device) != VK_NULL_HANDLE));

    vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::PhysicalDeviceWrapper,
                                         vulkan_wrappers::NoParentWrapper,
                                         vulkan_wrappers::DeviceWrapper>(
        VK_NULL_HANDLE, vulkan_wrappers::NoParentWrapper::kHandleValue, device, GetUniqueId);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(*device);
    graphics::LoadVulkanDeviceTable(gpa, wrapper->handle, &wrapper->layer_table);
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
        format::SetOpaqueAddressCommand opaque_address_cmd{};

        auto thread_data = GetThreadData();
        GFXRECON_ASSERT(thread_data != nullptr);

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

void VulkanCaptureManager::WriteSetOpaqueCaptureDescriptorData(format::HandleId device_id,
                                                               format::HandleId object_id,
                                                               size_t           data_size,
                                                               const void*      data)
{
    if (IsCaptureModeWrite())
    {
        format::SetOpaqueDescriptorDataCommand opaque_descriptor_cmd{};

        auto thread_data = GetThreadData();
        GFXRECON_ASSERT(thread_data != nullptr);

        opaque_descriptor_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        opaque_descriptor_cmd.meta_header.block_header.size =
            format::GetMetaDataBlockBaseSize(opaque_descriptor_cmd) + data_size;
        opaque_descriptor_cmd.meta_header.meta_data_id = format::MakeMetaDataId(
            format::ApiFamilyId::ApiFamily_Vulkan, format::MetaDataType::kSetOpaqueCaptureDescriptorDataCommand);
        opaque_descriptor_cmd.thread_id = thread_data->thread_id_;
        opaque_descriptor_cmd.device_id = device_id;
        opaque_descriptor_cmd.object_id = object_id;

        GFXRECON_ASSERT(data_size <= UINT32_MAX);
        opaque_descriptor_cmd.data_size = static_cast<uint32_t>(data_size);

        CombineAndWriteToFile({ { &opaque_descriptor_cmd, sizeof(opaque_descriptor_cmd) }, { data, data_size } });
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

                UpdateTemplateEntryInfo inline_uniform_info;
                inline_uniform_info.binding       = entry->dstBinding;
                inline_uniform_info.array_element = entry->dstArrayElement;

                // count is interpreted as number of bytes here
                inline_uniform_info.count  = entry->descriptorCount;
                inline_uniform_info.offset = entry->offset;
                inline_uniform_info.stride = byte_stride;
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
        TrackUpdateDescriptorSetWithTemplate(set, info, data);
    }
}

VkResult VulkanCaptureManager::OverrideCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                                      const VkAllocationCallbacks* pAllocator,
                                                      VkInstance*                  pInstance)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (InitSingleton() == nullptr)
    {
        return result;
    }
    singleton_->layer_settings_ = GetVulkanLayerTraceSettings(pCreateInfo);

    VkInstanceCreateInfo     create_info_copy = (*pCreateInfo);
    std::vector<const char*> modified_extensions;

    if (CreateInstance())
    {
        assert(pCreateInfo != nullptr);

        const bool is_external_memory_mode = singleton_->IsPageGuardMemoryModeExternal();

        // TODO: Only enable KHR_get_physical_device_properties_2 for 1.0 API version.
        size_t             extension_count = create_info_copy.enabledExtensionCount;
        const char* const* extensions      = create_info_copy.ppEnabledExtensionNames;

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

        // All VK_KHR_get_physical_device_properties2 functionalities are included in Vulkan 1.1,
        // otherwise always enable it if available.
        if (!has_dev_prop2 && pCreateInfo->pApplicationInfo != nullptr &&
            pCreateInfo->pApplicationInfo->apiVersion < VK_MAKE_VERSION(1, 1, 0))
        {
            modified_extensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
        }

        // KHR_external_memory_capabilities is only required for the external page guard memory mode.
        if (is_external_memory_mode && !has_ext_mem_caps)
        {
            modified_extensions.push_back(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME);
        }

        create_info_copy.enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
        create_info_copy.ppEnabledExtensionNames = modified_extensions.data();

        result = vulkan_layer_table_.CreateInstance(&create_info_copy, pAllocator, pInstance);
    }

    if ((result == VK_SUCCESS) && (pCreateInfo->pApplicationInfo != nullptr))
    {
        auto api_version              = pCreateInfo->pApplicationInfo->apiVersion;
        auto instance_wrapper         = vulkan_wrappers::GetWrapper<vulkan_wrappers::InstanceWrapper>(*pInstance);
        instance_wrapper->api_version = api_version;

        instance_wrapper->util_info.PostCreateInstanceUpdateState(create_info_copy);

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

    GFXRECON_ASSERT(pCreateInfo_unwrapped != nullptr);

    const graphics::VulkanInstanceTable* instance_table = vulkan_wrappers::GetInstanceTable(physicalDevice);
    auto physical_device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physicalDevice);

    // TODO: Only enable KHR_external_memory_capabilities for 1.0 API version.
    size_t                   extension_count = pCreateInfo_unwrapped->enabledExtensionCount;
    const char* const*       extensions      = pCreateInfo_unwrapped->ppEnabledExtensionNames;
    std::vector<const char*> modified_extensions;

    std::vector<VkExtensionProperties> supported_extensions;
    graphics::feature_util::GetDeviceExtensions(
        physicalDevice, instance_table->EnumerateDeviceExtensionProperties, &supported_extensions);

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

    // Check if VK_EXT_frame_boundary need to be faked (querried but not actually supported by the capture device)
    VkBaseOutStructure*                       frame_boundary_features_parent = nullptr;
    VkPhysicalDeviceFrameBoundaryFeaturesEXT* frame_boundary_features        = nullptr;
    if (graphics::feature_util::IsSupportedExtension(modified_extensions, VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME) &&
        !graphics::feature_util::IsSupportedExtension(supported_extensions, VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME))
    {
        auto iter = std::find_if(modified_extensions.begin(), modified_extensions.end(), [](const char* extension) {
            return util::platform::StringCompare(VK_EXT_FRAME_BOUNDARY_EXTENSION_NAME, extension) == 0;
        });
        modified_extensions.erase(iter);

        frame_boundary_features_parent = (VkBaseOutStructure*)pCreateInfo_unwrapped;

        while (frame_boundary_features_parent->pNext != nullptr &&
               frame_boundary_features_parent->pNext->sType !=
                   VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAME_BOUNDARY_FEATURES_EXT)
        {
            frame_boundary_features_parent = frame_boundary_features_parent->pNext;
        }

        if (frame_boundary_features_parent->pNext == nullptr)
        {
            frame_boundary_features_parent = nullptr;
        }
        else
        {
            frame_boundary_features =
                reinterpret_cast<VkPhysicalDeviceFrameBoundaryFeaturesEXT*>(frame_boundary_features_parent->pNext);
            frame_boundary_features_parent->pNext = frame_boundary_features_parent->pNext->pNext;
            GFXRECON_LOG_WARNING(
                "VkPhysicalDeviceFrameBoundaryFeaturesEXT instance was removed from capture device creation");
        }
    }

    // Enable device extensions required for resolving multisampled depth/stencil images
    for (const auto& vdr_required_extension : graphics::kVulkanDepthStencilResolveExtensions)
    {
        const bool is_extension_supported =
            graphics::feature_util::IsSupportedExtension(supported_extensions, vdr_required_extension.c_str());
        const bool is_extension_already_requested =
            graphics::feature_util::IsSupportedExtension(modified_extensions, vdr_required_extension.c_str());

        if (is_extension_supported && !is_extension_already_requested)
        {
            modified_extensions.push_back(vdr_required_extension.c_str());
        }
    }

    pCreateInfo_unwrapped->enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
    pCreateInfo_unwrapped->ppEnabledExtensionNames = modified_extensions.data();

    graphics::VulkanDeviceUtil                device_util;
    graphics::VulkanDevicePropertyFeatureInfo property_feature_info = device_util.EnableRequiredPhysicalDeviceFeatures(
        physical_device_wrapper->parent_info, instance_table, physicalDevice, pCreateInfo_unwrapped);

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
        GFXRECON_ASSERT((pDevice != nullptr) && (*pDevice != VK_NULL_HANDLE));

        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(*pDevice);

        // Track state of physical device properties and features at device creation
        wrapper->property_feature_info = property_feature_info;

        if (!IsCaptureModeTrack())
        {
            // The state tracker will set this value when it is enabled. When state tracking is disabled it is set here
            // to ensure it is available.
            wrapper->physical_device = physical_device_wrapper;
        }

        wrapper->queue_family_indices.resize(pCreateInfo_unwrapped->queueCreateInfoCount);
        for (uint32_t q = 0; q < pCreateInfo_unwrapped->queueCreateInfoCount; ++q)
        {
            const VkDeviceQueueCreateInfo* queue_create_info = &pCreateInfo_unwrapped->pQueueCreateInfos[q];
            wrapper->queue_family_indices[q] = pCreateInfo_unwrapped->pQueueCreateInfos[q].queueFamilyIndex;
        }
    }

    if (frame_boundary_features != nullptr)
    {
        frame_boundary_features_parent->pNext = reinterpret_cast<VkBaseOutStructure*>(frame_boundary_features);
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
    VkResult result           = VK_SUCCESS;
    auto     device_wrapper   = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice device_unwrapped = device_wrapper->handle;
    auto     device_table     = vulkan_wrappers::GetDeviceTable(device);

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

    if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
    {
        modified_create_info->flags |= VK_BUFFER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT;
    }

    // create buffer with augmented create- and usage-flags
    result = device_table->CreateBuffer(device_unwrapped, modified_create_info, pAllocator, pBuffer);

    if ((result == VK_SUCCESS) && (pBuffer != nullptr))
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::BufferWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pBuffer, GetUniqueId);

        auto* buffer_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(*pBuffer);
        GFXRECON_ASSERT(buffer_wrapper);
        buffer_wrapper->size  = modified_create_info->size;
        buffer_wrapper->usage = pCreateInfo->usage;

        if (uses_address)
        {
            // If the buffer has a device address, write the 'set buffer address' command before writing the API call to
            // create the buffer.  The address will need to be passed to vkCreateBuffer through the pCreateInfo pNext
            // list.
            VkBufferDeviceAddressInfo info = { VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO };
            info.pNext                     = nullptr;
            info.buffer                    = buffer_wrapper->handle;
            uint64_t opaque_address        = 0;

            if (device_wrapper->physical_device->parent_info.api_version >= VK_MAKE_VERSION(1, 2, 0))
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

        // request and store opaque descriptor-data for this buffer
        if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
        {
            std::vector<uint8_t> opaque_data(device_wrapper->property_feature_info.descriptor_buffer_properties
                                                 .bufferCaptureReplayDescriptorDataSize);

            VkBufferCaptureDescriptorDataInfoEXT descriptor_data_info_ext = {
                VK_STRUCTURE_TYPE_BUFFER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT
            };
            descriptor_data_info_ext.buffer = buffer_wrapper->handle;
            VkResult get_data_result        = device_table->GetBufferOpaqueCaptureDescriptorDataEXT(
                device_unwrapped, &descriptor_data_info_ext, opaque_data.data());
            GFXRECON_ASSERT(get_data_result == VK_SUCCESS);

            WriteSetOpaqueCaptureDescriptorData(
                device_wrapper->handle_id, buffer_wrapper->handle_id, opaque_data.size(), opaque_data.data());

            if (IsCaptureModeTrack())
            {
                buffer_wrapper->opaque_descriptor_data = std::move(opaque_data);
            }
        }
    }
    return result;
}

VkResult VulkanCaptureManager::OverrideCreateTensorARM(VkDevice                     device,
                                                       const VkTensorCreateInfoARM* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       VkTensorARM*                 pTensor)
{
    auto* device_table         = vulkan_wrappers::GetDeviceTable(device);
    auto  handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();

    const VkTensorCreateInfoARM* pCreateInfo_unwrapped =
        vulkan_wrappers::UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkTensorCreateInfoARM modified_create_info = *pCreateInfo_unwrapped;

    VkTensorDescriptionARM modified_desc;
    if (IsTrimEnabled() && pCreateInfo_unwrapped->pDescription != nullptr)
    {
        modified_desc = *pCreateInfo_unwrapped->pDescription;
        modified_desc.usage |= VK_TENSOR_USAGE_TRANSFER_SRC_BIT_ARM;
        modified_create_info.pDescription = &modified_desc;
    }

    VkResult result = device_table->CreateTensorARM(device, &modified_create_info, pAllocator, pTensor);

    if (result >= 0 && pTensor != nullptr)
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::TensorARMWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pTensor, GetUniqueId);
    }

    return result;
}

VkResult VulkanCaptureManager::OverrideCreateImage(VkDevice                     device,
                                                   const VkImageCreateInfo*     pCreateInfo,
                                                   const VkAllocationCallbacks* pAllocator,
                                                   VkImage*                     pImage)
{
    auto                     handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto*                    device_wrapper       = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    auto*                    device_table         = vulkan_wrappers::GetDeviceTable(device);
    const VkImageCreateInfo* pCreateInfo_unwrapped =
        vulkan_wrappers::UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory);

    VkImageCreateInfo modified_create_info = (*pCreateInfo_unwrapped);

    if (IsTrimEnabled())
    {
        modified_create_info.usage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    }

    if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
    {
        modified_create_info.flags |= VK_IMAGE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT;
    }

    VkResult result = device_table->CreateImage(device, &modified_create_info, pAllocator, pImage);

    if (result >= 0)
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::ImageWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pImage, VulkanCaptureManager::GetUniqueId);

        auto* image_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(*pImage);
        GFXRECON_ASSERT(image_wrapper);
        image_wrapper->bind_device = device_wrapper;

        // These are required to generate a fill command in case external memory is bound to this image
        image_wrapper->image_type     = modified_create_info.imageType;
        image_wrapper->extent         = modified_create_info.extent;
        image_wrapper->format         = modified_create_info.format;
        image_wrapper->mip_levels     = modified_create_info.mipLevels;
        image_wrapper->array_layers   = modified_create_info.arrayLayers;
        image_wrapper->tiling         = modified_create_info.tiling;
        image_wrapper->samples        = modified_create_info.samples;
        image_wrapper->current_layout = modified_create_info.initialLayout;
        // TODO: Do we need to track the queue family that the image is actually used with?
        if ((modified_create_info.queueFamilyIndexCount > 0) && (modified_create_info.pQueueFamilyIndices != nullptr))
        {
            image_wrapper->queue_family_index = modified_create_info.pQueueFamilyIndices[0];
        }

        // request and store opaque descriptor-data for image
        if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
        {
            std::vector<uint8_t> opaque_data(device_wrapper->property_feature_info.descriptor_buffer_properties
                                                 .imageCaptureReplayDescriptorDataSize);

            VkImageCaptureDescriptorDataInfoEXT descriptor_data_info_ext = {
                VK_STRUCTURE_TYPE_IMAGE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT
            };
            descriptor_data_info_ext.image = image_wrapper->handle;
            VkResult get_data_result       = device_table->GetImageOpaqueCaptureDescriptorDataEXT(
                device_wrapper->handle, &descriptor_data_info_ext, opaque_data.data());
            GFXRECON_ASSERT(get_data_result == VK_SUCCESS);

            WriteSetOpaqueCaptureDescriptorData(
                device_wrapper->handle_id, image_wrapper->handle_id, opaque_data.size(), opaque_data.data());

            if (IsCaptureModeTrack())
            {
                image_wrapper->opaque_descriptor_data = std::move(opaque_data);
            }
        }
    }
    return result;
}

VkResult VulkanCaptureManager::OverrideCreateImageView(VkDevice                     device,
                                                       const VkImageViewCreateInfo* pCreateInfo,
                                                       const VkAllocationCallbacks* pAllocator,
                                                       VkImageView*                 pImageView)
{
    auto* device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    const graphics::VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(device);

    auto modified_create_info = *pCreateInfo;

    if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
    {
        modified_create_info.flags |= VK_IMAGE_VIEW_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT;
    }

    VkResult result = device_table->CreateImageView(device, &modified_create_info, pAllocator, pImageView);

    if (result == VK_SUCCESS)
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::ImageViewWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pImageView, VulkanCaptureManager::GetUniqueId);
        auto* image_view_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(*pImageView);
        GFXRECON_ASSERT(image_view_wrapper);
        image_view_wrapper->device_id = device_wrapper->handle_id;

        // request and store opaque descriptor-data for image
        if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
        {
            std::vector<uint8_t> opaque_data(device_wrapper->property_feature_info.descriptor_buffer_properties
                                                 .imageViewCaptureReplayDescriptorDataSize);

            VkImageViewCaptureDescriptorDataInfoEXT descriptor_data_info_ext = {
                VK_STRUCTURE_TYPE_IMAGE_VIEW_CAPTURE_DESCRIPTOR_DATA_INFO_EXT
            };
            descriptor_data_info_ext.imageView = *pImageView;
            VkResult get_data_result           = device_table->GetImageViewOpaqueCaptureDescriptorDataEXT(
                device_wrapper->handle, &descriptor_data_info_ext, opaque_data.data());
            GFXRECON_ASSERT(get_data_result == VK_SUCCESS);

            WriteSetOpaqueCaptureDescriptorData(
                device_wrapper->handle_id, image_view_wrapper->handle_id, opaque_data.size(), opaque_data.data());

            if (IsCaptureModeTrack())
            {
                image_view_wrapper->opaque_descriptor_data = std::move(opaque_data);
            }
        }
    }
    return result;
}

VkResult VulkanCaptureManager::OverrideCreateSampler(VkDevice                     device,
                                                     const VkSamplerCreateInfo*   pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator,
                                                     VkSampler*                   pSampler)
{
    auto* device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    const graphics::VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(device);

    auto modified_create_info = *pCreateInfo;

    if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
    {
        modified_create_info.flags |= VK_SAMPLER_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT;
    }

    VkResult result = device_table->CreateSampler(device, &modified_create_info, pAllocator, pSampler);

    if (result == VK_SUCCESS)
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::SamplerWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pSampler, VulkanCaptureManager::GetUniqueId);
        auto* sampler_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(*pSampler);
        GFXRECON_ASSERT(sampler_wrapper);

        // keep track of device_id
        sampler_wrapper->device_id = device_wrapper->handle_id;

        // request and store opaque descriptor-data for image
        if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
        {
            std::vector<uint8_t> opaque_data(device_wrapper->property_feature_info.descriptor_buffer_properties
                                                 .samplerCaptureReplayDescriptorDataSize);

            VkSamplerCaptureDescriptorDataInfoEXT descriptor_data_info_ext = {
                VK_STRUCTURE_TYPE_SAMPLER_CAPTURE_DESCRIPTOR_DATA_INFO_EXT
            };
            descriptor_data_info_ext.sampler = *pSampler;
            VkResult get_data_result         = device_table->GetSamplerOpaqueCaptureDescriptorDataEXT(
                device_wrapper->handle, &descriptor_data_info_ext, opaque_data.data());
            GFXRECON_ASSERT(get_data_result == VK_SUCCESS);

            WriteSetOpaqueCaptureDescriptorData(
                device_wrapper->handle_id, sampler_wrapper->handle_id, opaque_data.size(), opaque_data.data());

            if (IsCaptureModeTrack())
            {
                sampler_wrapper->opaque_descriptor_data = std::move(opaque_data);
            }
        }
    }
    return result;
}

VkResult
VulkanCaptureManager::OverrideCreateAccelerationStructureKHR(VkDevice                                    device,
                                                             const VkAccelerationStructureCreateInfoKHR* pCreateInfo,
                                                             const VkAllocationCallbacks*                pAllocator,
                                                             VkAccelerationStructureKHR* pAccelerationStructureKHR)
{
    auto     device_wrapper   = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice device_unwrapped = device_wrapper->handle;
    const graphics::VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(device);

    std::unique_ptr<uint8_t[]>            struct_memory;
    VkAccelerationStructureCreateInfoKHR* modified_create_info =
        vulkan_trackers::TrackStructs(pCreateInfo, 1, struct_memory);

    if (device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
    {
        // Add flag to allow for opaque address capture
        modified_create_info->createFlags |= VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR;
    }

    if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
    {
        // Add flag to allow for opaque descriptor-data capture
        modified_create_info->createFlags |= VK_ACCELERATION_STRUCTURE_CREATE_DESCRIPTOR_BUFFER_CAPTURE_REPLAY_BIT_EXT;
    }

    VkResult result = device_table->CreateAccelerationStructureKHR(
        device_unwrapped, modified_create_info, pAllocator, pAccelerationStructureKHR);

    if ((result == VK_SUCCESS) && (pAccelerationStructureKHR != nullptr))
    {
        vulkan_wrappers::CreateWrappedHandle<vulkan_wrappers::DeviceWrapper,
                                             vulkan_wrappers::NoParentWrapper,
                                             vulkan_wrappers::AccelerationStructureKHRWrapper>(
            device, vulkan_wrappers::NoParentWrapper::kHandleValue, pAccelerationStructureKHR, GetUniqueId);

        auto* accel_struct_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(*pAccelerationStructureKHR);

        VkAccelerationStructureDeviceAddressInfoKHR address_info{
            VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR, nullptr, accel_struct_wrapper->handle
        };

        // save address to use as pCreateInfo->deviceAddress during replay
        VkDeviceAddress address =
            device_table->GetAccelerationStructureDeviceAddressKHR(device_unwrapped, &address_info);

        accel_struct_wrapper->device  = device_wrapper;
        accel_struct_wrapper->address = address;
        accel_struct_wrapper->type    = modified_create_info->type;

        auto* buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(modified_create_info->buffer, true);
        GFXRECON_ASSERT(buffer_wrapper != nullptr);

        accel_struct_wrapper->buffer = buffer_wrapper;
        accel_struct_wrapper->offset = modified_create_info->offset;
        accel_struct_wrapper->size   = modified_create_info->size;

        // associated buffer keeps track of existing acceleration-structures
        buffer_wrapper->acceleration_structures[accel_struct_wrapper->address].type = accel_struct_wrapper->type;

        if (IsCaptureModeTrack())
        {
            state_tracker_->TrackAccelerationStructureKHRDeviceAddress(device, *pAccelerationStructureKHR, address);
        }

        if (device_wrapper->property_feature_info.feature_accelerationStructureCaptureReplay)
        {
            WriteSetOpaqueAddressCommand(device_wrapper->handle_id, accel_struct_wrapper->handle_id, address);
        }

        // request and store opaque descriptor-data for the acceleration-structure
        if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
        {
            std::vector<uint8_t> opaque_data(device_wrapper->property_feature_info.descriptor_buffer_properties
                                                 .accelerationStructureCaptureReplayDescriptorDataSize);

            VkAccelerationStructureCaptureDescriptorDataInfoEXT descriptor_data_info_ext = {
                VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CAPTURE_DESCRIPTOR_DATA_INFO_EXT
            };
            descriptor_data_info_ext.accelerationStructure = accel_struct_wrapper->handle;
            VkResult get_data_result = device_table->GetAccelerationStructureOpaqueCaptureDescriptorDataEXT(
                device_wrapper->handle, &descriptor_data_info_ext, opaque_data.data());
            GFXRECON_ASSERT(get_data_result == VK_SUCCESS);

            WriteSetOpaqueCaptureDescriptorData(
                device_wrapper->handle_id, accel_struct_wrapper->handle_id, opaque_data.size(), opaque_data.data());

            if (IsCaptureModeTrack())
            {
                accel_struct_wrapper->opaque_descriptor_data = std::move(opaque_data);
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
        state_tracker_->TrackAccelerationStructureBuildCommand(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
    }
    const graphics::VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(commandBuffer);
    device_table->CmdBuildAccelerationStructuresKHR(commandBuffer, infoCount, pInfos, ppBuildRangeInfos);
}

void VulkanCaptureManager::OverrideCmdCopyAccelerationStructureKHR(VkCommandBuffer command_buffer,
                                                                   const VkCopyAccelerationStructureInfoKHR* pInfo)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackAccelerationStructureCopyCommand(command_buffer, pInfo);
    }
    const graphics::VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(command_buffer);
    device_table->CmdCopyAccelerationStructureKHR(command_buffer, pInfo);
}

void VulkanCaptureManager::OverrideCmdWriteAccelerationStructuresPropertiesKHR(
    VkCommandBuffer                   commandBuffer,
    uint32_t                          accelerationStructureCount,
    const VkAccelerationStructureKHR* pAccelerationStructures,
    VkQueryType                       queryType,
    VkQueryPool                       queryPool,
    uint32_t                          firstQuery)
{
    if (IsCaptureModeTrack())
    {
        state_tracker_->TrackWriteAccelerationStructuresPropertiesCommand(
            commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
    }

    const graphics::VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(commandBuffer);
    device_table->CmdWriteAccelerationStructuresPropertiesKHR(
        commandBuffer, accelerationStructureCount, pAccelerationStructures, queryType, queryPool, firstQuery);
}

VkResult VulkanCaptureManager::OverrideAllocateMemory(VkDevice                     device,
                                                      const VkMemoryAllocateInfo*  pAllocateInfo,
                                                      const VkAllocationCallbacks* pAllocator,
                                                      VkDeviceMemory*              pMemory)
{
    VkResult                         result          = VK_SUCCESS;
    void*                            external_memory = nullptr;
    VkImportMemoryHostPointerInfoEXT import_info;

    auto     device_wrapper   = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice device_unwrapped = device_wrapper->handle;

    auto  handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    auto* pAllocateInfo_unwrapped =
        const_cast<VkMemoryAllocateInfo*>(vulkan_wrappers::UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory));

    bool                                     uses_address = false;
    std::optional<VkMemoryAllocateFlagsInfo> optional_alloc_flags_info;

    if (device_wrapper->property_feature_info.feature_bufferDeviceAddressCaptureReplay)
    {
        if (auto* alloc_flags_info =
                graphics::vulkan_struct_get_pnext<VkMemoryAllocateFlagsInfo>(pAllocateInfo_unwrapped))
        {
            optional_alloc_flags_info = *alloc_flags_info;

            if (alloc_flags_info->flags & VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT)
            {
                uses_address = true;
                alloc_flags_info->flags |= VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
            }
        }
    }

    if (device_wrapper->property_feature_info.feature_descriptorBufferCaptureReplay)
    {
        uses_address = true;

        if (!optional_alloc_flags_info)
        {
            optional_alloc_flags_info.emplace();
            optional_alloc_flags_info->sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO;
        }
        optional_alloc_flags_info->pNext = nullptr;
        optional_alloc_flags_info->flags |=
            VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT | VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT;
        graphics::vulkan_struct_add_pnext(pAllocateInfo_unwrapped, &optional_alloc_flags_info.value());
    }

#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    // If image is not VK_NULL_HANDLE and the memory is not an imported Android Hardware Buffer
    auto dedicated_alloc_info =
        graphics::vulkan_struct_get_pnext<VkMemoryDedicatedAllocateInfo>(pAllocateInfo_unwrapped);
    auto import_ahb_info =
        graphics::vulkan_struct_get_pnext<VkImportAndroidHardwareBufferInfoANDROID>(pAllocateInfo_unwrapped);
    if (dedicated_alloc_info != nullptr && dedicated_alloc_info->image != VK_NULL_HANDLE && import_ahb_info == nullptr)
    {
        // allocationSize needs to be equal to VkMemoryDedicatedAllocateInfo::image VkMemoryRequirements::size
        VkMemoryRequirements memory_requirements = {};
        vulkan_wrappers::GetDeviceTable(device)->GetImageMemoryRequirements(
            device, dedicated_alloc_info->image, &memory_requirements);
        pAllocateInfo_unwrapped->allocationSize = memory_requirements.size;
    }
#endif

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
                graphics::vulkan_struct_add_pnext(pAllocateInfo_unwrapped, &import_info);
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

        GFXRECON_ASSERT(pMemory != nullptr);
        auto* memory_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(*pMemory);

        if (uses_address)
        {
            VkDeviceMemoryOpaqueCaptureAddressInfo info{ VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO,
                                                         nullptr,
                                                         memory_wrapper->handle };

            uint64_t address = 0;
            if (device_wrapper->physical_device->parent_info.api_version >= VK_MAKE_VERSION(1, 2, 0))
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

                // keep track of modified allocation-params
                memory_wrapper->modified_allocation_info = vulkan_trackers::TrackStructs(
                    pAllocateInfo_unwrapped, 1, memory_wrapper->modified_allocation_info_data);
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

        if (auto import_memfd = graphics::vulkan_struct_get_pnext<VkImportMemoryFdInfoKHR>(pAllocateInfo_unwrapped))
        {
            if (import_memfd->fd >= 0)
            {
                memory_wrapper->imported_fd = import_memfd->fd;
            }
        }
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

void VulkanCaptureManager::OverrideGetPhysicalDeviceProperties2(VkPhysicalDevice             physicalDevice,
                                                                VkPhysicalDeviceProperties2* pProperties)
{
    auto physical_device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::PhysicalDeviceWrapper>(physicalDevice);
    GFXRECON_ASSERT(physical_device_wrapper != nullptr)

    if (physical_device_wrapper->parent_info.api_version >= VK_MAKE_VERSION(1, 1, 0))
    {
        vulkan_wrappers::GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties2(physicalDevice, pProperties);
    }
    else
    {
        vulkan_wrappers::GetInstanceTable(physicalDevice)->GetPhysicalDeviceProperties2KHR(physicalDevice, pProperties);
    }

    if (auto* raytracing_props =
            graphics::vulkan_struct_get_pnext<VkPhysicalDeviceRayTracingPipelinePropertiesKHR>(pProperties))
    {
        if (IsCaptureModeTrack())
        {
            state_tracker_->TrackRayTracingPipelineProperties(physicalDevice, raytracing_props);
        }
    }

    if (auto* acceleration_props =
            graphics::vulkan_struct_get_pnext<VkPhysicalDeviceAccelerationStructurePropertiesKHR>(pProperties))
    {
        if (IsCaptureModeTrack())
        {
            state_tracker_->TrackAccelerationStructureProperties(physicalDevice, acceleration_props);
        }
    }

    if (auto* descriptor_buffer_props =
            graphics::vulkan_struct_get_pnext<VkPhysicalDeviceDescriptorBufferPropertiesEXT>(pProperties))
    {
        if (IsCaptureModeTrack())
        {
            state_tracker_->TrackDescriptorBufferProperties(physicalDevice, descriptor_buffer_props);
        }
    }
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
                                   GetProjectVersionString(),
                                   util::platform::StringLength(GetProjectVersionString()));

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
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    const graphics::VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(device);
    auto                               deferred_operation_wrapper =
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

            // We need to set device_id here because some hardware may not have the feature
            // rayTracingPipelineShaderGroupHandleCaptureReplay so the device_id cannot be set by
            // VulkanStateTracker::TrackRayTracingShaderGroupHandles
            pipeline_wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
            pipeline_wrapper->num_shader_group_handles = pCreateInfos[i].groupCount;

            if (deferred_operation_wrapper)
            {
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
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    const graphics::VulkanDeviceTable* device_table = vulkan_wrappers::GetDeviceTable(device);

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

            // We need to set device_id here because some hardware may not have the feature
            // rayTracingPipelineShaderGroupHandleCaptureReplay so the device_id cannot be set by
            // VulkanStateTracker::TrackRayTracingShaderGroupHandles
            pipeline_wrapper->device_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceWrapper>(device);
            pipeline_wrapper->num_shader_group_handles     = deferred_operation_wrapper->create_infos[i].groupCount;
            pipeline_wrapper->deferred_operation.handle_id = deferred_operation_wrapper->handle_id;
            pipeline_wrapper->deferred_operation.create_call_id    = deferred_operation_wrapper->create_call_id;
            pipeline_wrapper->deferred_operation.create_parameters = deferred_operation_wrapper->create_parameters;

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

VkResult VulkanCaptureManager::OverrideAllocateCommandBuffers(VkDevice                           device,
                                                              const VkCommandBufferAllocateInfo* pAllocateInfo,
                                                              VkCommandBuffer*                   pCommandBuffers)
{
    auto                               handle_unwrap_memory = VulkanCaptureManager::Get()->GetHandleUnwrapMemory();
    const VkCommandBufferAllocateInfo* pAllocateInfo_unwrapped =
        vulkan_wrappers::UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory);

    VkResult result = vulkan_wrappers::GetDeviceTable(device)->AllocateCommandBuffers(
        device, pAllocateInfo_unwrapped, pCommandBuffers);

    if (result >= 0)
    {
        vulkan_wrappers::CreateWrappedHandles<vulkan_wrappers::DeviceWrapper,
                                              vulkan_wrappers::CommandPoolWrapper,
                                              vulkan_wrappers::CommandBufferWrapper>(device,
                                                                                     pAllocateInfo->commandPool,
                                                                                     pCommandBuffers,
                                                                                     pAllocateInfo->commandBufferCount,
                                                                                     VulkanCaptureManager::GetUniqueId);

        for (uint32_t i = 0; i < pAllocateInfo->commandBufferCount; ++i)
        {
            auto cmd_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(pCommandBuffers[i]);
            GFXRECON_ASSERT(cmd_wrapper);

            cmd_wrapper->level = pAllocateInfo->level;
        }
    }
    return result;
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
                const graphics::VulkanInstanceTable* instance_table =
                    vulkan_wrappers::GetInstanceTable(physical_device);
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

                physical_device_wrapper->parent_info.api_version = instance_wrapper->api_version;

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

void VulkanCaptureManager::ProcessHardwareBuffer(format::ThreadId thread_id,
                                                 AHardwareBuffer* hardware_buffer,
                                                 VkDevice         device)
{
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    auto entry = hardware_buffers_.find(hardware_buffer);
    if (entry != hardware_buffers_.end())
    {
        return;
    }

    format::HandleId memory_id = GetUniqueId();

    HardwareBufferInfo& ahb_info = hardware_buffers_[hardware_buffer];
    ahb_info.memory_id           = memory_id;
    ahb_info.reference_count     = 0;

    auto     device_wrapper   = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    VkDevice device_unwrapped = device_wrapper->handle;
    auto     device_table     = vulkan_wrappers::GetDeviceTable(device);

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

        CommonProcessHardwareBuffer(thread_id, device_wrapper, memory_id, hardware_buffer, ahb_size, this, nullptr);
    }
    else
    {
        GFXRECON_LOG_ERROR("GetAndroidHardwareBufferPropertiesANDROID failed: hardware buffer data will be omitted "
                           "from the capture file");
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(thread_id);
    GFXRECON_UNREFERENCED_PARAMETER(hardware_buffer);
    GFXRECON_UNREFERENCED_PARAMETER(device);
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

    auto thread_data = GetThreadData();
    assert(thread_data != nullptr);

    ProcessHardwareBuffer(thread_data->thread_id_, hardware_buffer, device);
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

void VulkanCaptureManager::ProcessImportFdForBuffer(VkDevice device, VkBuffer buffer, VkDeviceSize memoryOffset)
{
    auto* device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    auto* buffer_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);

    // create staging buffer, bind this memory, write init buffer command
    graphics::VulkanResourcesUtil resource_util(device_wrapper->handle,
                                                device_wrapper->physical_device->handle,
                                                device_wrapper->layer_table,
                                                *device_wrapper->physical_device->layer_table_ref,
                                                device_wrapper->property_feature_info,
                                                device_wrapper->physical_device->memory_properties);

    VkResult result = resource_util.CreateStagingBuffer(buffer_wrapper->size);
    if (result == VK_SUCCESS)
    {
        std::vector<uint8_t> data;
        result = resource_util.ReadFromBufferResource(
            buffer, buffer_wrapper->size, memoryOffset, buffer_wrapper->queue_family_index, data);
        if (result == VK_SUCCESS)
        {
            WriteBeginResourceInitCmd(device_wrapper->handle_id, buffer_wrapper->size, buffer_wrapper->size);

            GetCommandWriter()->WriteInitBufferCmd(api_family_,
                                                   device_wrapper->handle_id,
                                                   buffer_wrapper->handle_id,
                                                   memoryOffset,
                                                   buffer_wrapper->size,
                                                   data.data());
            WriteEndResourceInitCmd(device_wrapper->handle_id);
        }
    }
}

void VulkanCaptureManager::ProcessImportFdForImage(VkDevice device, VkImage image, VkDeviceSize memoryOffset)
{
    auto* device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);
    auto* image_wrapper  = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image);

    // create staging buffer, bind this memory, write init image command
    graphics::VulkanResourcesUtil resource_util(device_wrapper->handle,
                                                device_wrapper->physical_device->handle,
                                                device_wrapper->layer_table,
                                                *device_wrapper->physical_device->layer_table_ref,
                                                device_wrapper->property_feature_info,
                                                device_wrapper->physical_device->memory_properties);

    std::vector<VkImageAspectFlagBits> aspects;
    graphics::GetFormatAspects(image_wrapper->format, &aspects);

    using ImageResource = graphics::VulkanResourcesUtil::ImageResource;
    std::vector<ImageResource> image_resources;

    auto write_init_image_cmd = [this, &resource_util, device_wrapper](
                                    const ImageResource& img, const void* data, size_t num_bytes) {
        // Combined size of all layers in a mip level.
        std::vector<uint64_t> level_sizes;

        uint64_t resource_size = resource_util.GetImageResourceSizesOptimal(
            img.format, img.extent, img.level_count, img.layer_count, img.tiling, img.aspect, nullptr, &level_sizes);
        GFXRECON_ASSERT(resource_size == num_bytes);

        WriteBeginResourceInitCmd(device_wrapper->handle_id, resource_size, resource_size);
        GetCommandWriter()->WriteInitImageCmd(api_family_,
                                              device_wrapper->handle_id,
                                              img.handle_id,
                                              img.aspect,
                                              img.layout,
                                              img.level_count,
                                              level_sizes,
                                              resource_size,
                                              data);
        WriteEndResourceInitCmd(device_wrapper->handle_id);
    };

    uint32_t num_staging_bytes = 0;

    for (auto aspect : aspects)
    {
        auto& image_resource              = image_resources.emplace_back();
        image_resource.handle_id          = image_wrapper->handle_id;
        image_resource.image              = image_wrapper->handle;
        image_resource.format             = image_wrapper->format;
        image_resource.type               = image_wrapper->image_type;
        image_resource.extent             = image_wrapper->extent;
        image_resource.level_count        = image_wrapper->mip_levels;
        image_resource.layer_count        = image_wrapper->array_layers;
        image_resource.tiling             = image_wrapper->tiling;
        image_resource.sample_count       = image_wrapper->samples;
        image_resource.layout             = image_wrapper->current_layout;
        image_resource.queue_family_index = image_wrapper->queue_family_index;
        image_resource.external_format    = image_wrapper->external_format;
        image_resource.size               = image_wrapper->size;
        image_resource.aspect             = aspect;

        num_staging_bytes += image_wrapper->size;
    }

    // batch process image-downloads requiring staging, use <32MB staging-mem
    size_t staging_buffer_size = std::min<size_t>(32U << 20U, num_staging_bytes);
    resource_util.ReadImageResources(image_resources, write_init_image_cmd, staging_buffer_size);
}

void VulkanCaptureManager::PostProcess_vkBindBufferMemory(
    VkResult result, VkDevice device, VkBuffer buffer, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
    if (result == VK_SUCCESS)
    {
        if (IsCaptureModeTrack())
        {
            GFXRECON_ASSERT(state_tracker_ != nullptr);
            state_tracker_->TrackBufferMemoryBinding(device, buffer, memory, memoryOffset);

            auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
            ProcessBindResourceMemory(wrapper, memory, memoryOffset);
        }

        if (IsCaptureModeWrite())
        {
            auto* memory_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
            if (memory_wrapper->imported_fd >= 0)
            {
                // For this and the other PostProcess_vkBind*Memory* functions:
                // When importing external memory in tracking mode, there is no need to generate a FillMemory command,
                // as it gets generated when starting to capture by the WriteTrackedState function, which will
                // effectively fill the memory with the right content. On the other hand, while capturing, there could
                // be no other Vulkan commands affecting this memory, so we must initialize it by generating the
                // FillMemory command immediately.
                ProcessImportFdForBuffer(device, buffer, memoryOffset);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkBindBufferMemory2(VkResult                      result,
                                                           VkDevice                      device,
                                                           uint32_t                      bindInfoCount,
                                                           const VkBindBufferMemoryInfo* pBindInfos)
{
    if ((result == VK_SUCCESS) && (pBindInfos != nullptr))
    {
        if (IsCaptureModeTrack())
        {
            GFXRECON_ASSERT(state_tracker_ != nullptr);

            for (uint32_t i = 0; i < bindInfoCount; ++i)
            {
                state_tracker_->TrackBufferMemoryBinding(device,
                                                         pBindInfos[i].buffer,
                                                         pBindInfos[i].memory,
                                                         pBindInfos[i].memoryOffset,
                                                         pBindInfos[i].pNext);

                auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(pBindInfos[i].buffer);
                ProcessBindResourceMemory(wrapper, pBindInfos[i].memory, pBindInfos[i].memoryOffset);
            }
        }

        if (IsCaptureModeWrite())
        {
            for (uint32_t i = 0; i < bindInfoCount; ++i)
            {
                auto* memory_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pBindInfos[i].memory);
                if (memory_wrapper->imported_fd >= 0)
                {
                    ProcessImportFdForBuffer(device, pBindInfos[i].buffer, pBindInfos[i].memoryOffset);
                }
            }
        }
    }
}

void VulkanCaptureManager::ProcessBindResourceMemory(graphics::AssetBase* resource,
                                                     VkDeviceMemory       memory,
                                                     VkDeviceSize         memoryOffset)
{
    GFXRECON_ASSERT(IsCaptureModeTrack());

    resource->bind_memory_id = vulkan_wrappers::GetWrappedId<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    resource->bind_offset    = memoryOffset;

    vulkan_wrappers::DeviceMemoryWrapper* mem_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    if (mem_wrapper != nullptr)
    {
        mem_wrapper->asset_map_lock.lock();
        mem_wrapper->bound_assets.emplace(resource);
        mem_wrapper->asset_map_lock.unlock();
    }
}

void VulkanCaptureManager::ProcessUnbindResourceMemory(graphics::AssetBase* resource)
{
    GFXRECON_ASSERT(IsCaptureModeTrack());
    GFXRECON_ASSERT(resource != nullptr);

    if (resource->bind_memory_id != format::kNullHandleId)
    {
        vulkan_wrappers::DeviceMemoryWrapper* mem_wrapper =
            state_tracker_->GetDeviceMemoryWrapper(resource->bind_memory_id);

        if (mem_wrapper != nullptr)
        {
            mem_wrapper->asset_map_lock.lock();
            auto bind_entry = mem_wrapper->bound_assets.find(resource);
            if (bind_entry != mem_wrapper->bound_assets.end())
            {
                mem_wrapper->bound_assets.erase(bind_entry);
            }
            mem_wrapper->asset_map_lock.unlock();
        }
    }
}

void VulkanCaptureManager::PreProcess_vkDestroyBuffer(VkDevice, VkBuffer buffer, const VkAllocationCallbacks*)
{
    if (IsCaptureModeTrack())
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
        if (wrapper != nullptr)
        {
            ProcessUnbindResourceMemory(wrapper);
        }
    }
}

void VulkanCaptureManager::PreProcess_vkDestroyImage(VkDevice, VkImage image, const VkAllocationCallbacks*)
{
    if (IsCaptureModeTrack())
    {
        auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image);
        if (wrapper != nullptr)
        {
            ProcessUnbindResourceMemory(wrapper);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkAllocateMemory(VkResult                     result,
                                                        VkDevice                     device,
                                                        const VkMemoryAllocateInfo*  pAllocateInfo,
                                                        const VkAllocationCallbacks* pAllocator,
                                                        VkDeviceMemory*              pMemory)
{
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if (result == VK_SUCCESS && GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kSmart &&
        pAllocateInfo != nullptr && pMemory != nullptr && *pMemory != VK_NULL_HANDLE)
    {
        auto memory_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(*pMemory);
        auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);

        if (memory_wrapper != nullptr && device_wrapper != nullptr)
        {
            const VkMemoryPropertyFlags properties =
                GetMemoryProperties(device_wrapper, pAllocateInfo->memoryTypeIndex);
            smart_memory_tracker_.TrackMemory(memory_wrapper->handle_id, pAllocateInfo->allocationSize, properties);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkBindImageMemory(
    VkResult result, VkDevice device, VkImage image, VkDeviceMemory memory, VkDeviceSize memoryOffset)
{
    if (result == VK_SUCCESS)
    {
        if (IsCaptureModeTrack())
        {
            GFXRECON_ASSERT(state_tracker_ != nullptr);
            state_tracker_->TrackImageMemoryBinding(device, image, memory, memoryOffset);

            auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image);
            ProcessBindResourceMemory(wrapper, memory, memoryOffset);
        }

        if (IsCaptureModeWrite())
        {
            auto* memory_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
            if (memory_wrapper->imported_fd >= 0)
            {
                ProcessImportFdForImage(device, image, memoryOffset);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkBindImageMemory2(VkResult                     result,
                                                          VkDevice                     device,
                                                          uint32_t                     bindInfoCount,
                                                          const VkBindImageMemoryInfo* pBindInfos)
{
    if ((result == VK_SUCCESS) && (pBindInfos != nullptr))
    {
        if (IsCaptureModeTrack())
        {
            GFXRECON_ASSERT(state_tracker_ != nullptr);

            for (uint32_t i = 0; i < bindInfoCount; ++i)
            {
                state_tracker_->TrackImageMemoryBinding(
                    device, pBindInfos[i].image, pBindInfos[i].memory, pBindInfos[i].memoryOffset, pBindInfos[i].pNext);

                auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(pBindInfos[i].image);
                ProcessBindResourceMemory(wrapper, pBindInfos[i].memory, pBindInfos[i].memoryOffset);
            }
        }

        if (IsCaptureModeWrite())
        {
            for (uint32_t i = 0; i < bindInfoCount; ++i)
            {
                auto* memory_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pBindInfos[i].memory);
                if (memory_wrapper != nullptr && memory_wrapper->imported_fd >= 0)
                {
                    ProcessImportFdForImage(device, pBindInfos[i].image, pBindInfos[i].memoryOffset);
                }
            }
        }
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
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);

#if defined(VK_USE_PLATFORM_WAYLAND_KHR)
    assert(pCreateInfo != nullptr);
    if (pCreateInfo && !GetTrimKey().empty())
    {
        if (!GetKeyboard().Initialize(pCreateInfo->display))
        {
            GFXRECON_LOG_ERROR("Failed to initialize XCB keyboard capture trigger");
        }
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    if (!GetTrimKey().empty())
    {
        GFXRECON_LOG_WARNING("Wayland keyboard capture trigger is not enabled on this system");
    }
#endif
}

void VulkanCaptureManager::PreProcess_vkDestroySurfaceKHR(VkInstance                   instance,
                                                          VkSurfaceKHR                 pSurface,
                                                          const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);

    GetKeyboard().Shutdown();
}

void VulkanCaptureManager::PreProcess_vkCreateSwapchainKHR(VkDevice                        device,
                                                           const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                           const VkAllocationCallbacks*    pAllocator,
                                                           VkSwapchainKHR*                 pSwapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSwapchain);

    GFXRECON_ASSERT(pCreateInfo != nullptr);

    WriteResizeWindowCmd2(vulkan_wrappers::GetWrappedId<vulkan_wrappers::SurfaceKHRWrapper>(pCreateInfo->surface),
                          pCreateInfo->imageExtent.width,
                          pCreateInfo->imageExtent.height,
                          pCreateInfo->preTransform);
}

void VulkanCaptureManager::PostProcess_vkCreateSwapchainKHR(VkResult                        result,
                                                            VkDevice                        device,
                                                            const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                            const VkAllocationCallbacks*    pAllocator,
                                                            VkSwapchainKHR*                 pSwapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(result);
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSwapchain);

    GFXRECON_ASSERT(pCreateInfo != nullptr);

    // Vulkan Spec: Upon calling vkCreateSwapchainKHR with an oldSwapchain that is not VK_NULL_HANDLE, any images
    // from oldSwapchain that are not acquired by the application may be freed by the implementation, which may
    // occur even if creation of the new swapchain fails.

    // The capture layer needs to be conservative and treat these images as destroyed now because the implementation
    // is free to destroy and reuse the image handles before the retired swapchain is destroyed.
    if (pCreateInfo->oldSwapchain != VK_NULL_HANDLE)
    {
        auto old_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(pCreateInfo->oldSwapchain);
        old_wrapper->retired = true;

        for (int i = old_wrapper->child_images.size() - 1; i >= 0; --i)
        {
            bool is_acquired = false;
            if (i < old_wrapper->image_acquired_info.size())
                is_acquired = old_wrapper->image_acquired_info[i].is_acquired;

            if (!is_acquired)
            {
                const auto image_handle = old_wrapper->child_images[i]->handle;

                // Remove from swapchain info struct
                old_wrapper->child_images.erase(old_wrapper->child_images.begin() + i);
                if (i < old_wrapper->image_acquired_info.size())
                    old_wrapper->image_acquired_info.erase(old_wrapper->image_acquired_info.begin() + i);

                // Destroy handle wrapper
                if (IsCaptureModeTrack())
                {
                    state_tracker_->RemoveEntry<vulkan_wrappers::ImageWrapper>(image_handle);
                }
                vulkan_wrappers::DestroyWrappedHandle<vulkan_wrappers::ImageWrapper>(image_handle);
            }
        }
    }
}

// Performs a subset of the state tracking performed by VulkanStateTracker::TrackAcquireImage,
// only storing values needed for non-tracking capture.
void TrackAcquireImageSubset(VkSwapchainKHR swapchain, size_t image_index)
{
    auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchain);
    GFXRECON_ASSERT(wrapper != nullptr);
    if (wrapper != nullptr)
    {
        if (image_index >= wrapper->image_acquired_info.size())
        {
            wrapper->image_acquired_info.resize(image_index + 1);
        }
        wrapper->image_acquired_info[image_index].is_acquired = true;
    }
}

void VulkanCaptureManager::PostProcess_vkAcquireNextImageKHR(VkResult       result,
                                                             VkDevice       device,
                                                             VkSwapchainKHR swapchain,
                                                             uint64_t       timeout,
                                                             VkSemaphore    semaphore,
                                                             VkFence        fence,
                                                             uint32_t*      index)
{
    VkAcquireNextImageInfoKHR acquire_info{};
    acquire_info.sType      = VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR;
    acquire_info.pNext      = nullptr;
    acquire_info.swapchain  = swapchain;
    acquire_info.timeout    = timeout;
    acquire_info.semaphore  = semaphore;
    acquire_info.fence      = fence;
    acquire_info.deviceMask = 0;
    PostProcess_vkAcquireNextImage2KHR(result, device, &acquire_info, index);
}

void VulkanCaptureManager::PostProcess_vkAcquireNextImage2KHR(VkResult result,
                                                              VkDevice,
                                                              const VkAcquireNextImageInfoKHR* pAcquireInfo,
                                                              uint32_t*                        index)
{

    if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
    {
        if (IsCaptureModeTrack())
        {
            if (pAcquireInfo != nullptr && pAcquireInfo->fence != VK_NULL_HANDLE)
            {
                auto* fence_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::FenceWrapper>(pAcquireInfo->fence);
                fence_wrapper->in_flight = true;
            }

            GFXRECON_ASSERT((state_tracker_ != nullptr) && (pAcquireInfo != nullptr) && (index != nullptr));
            state_tracker_->TrackSemaphoreSignalState(pAcquireInfo->semaphore);
            state_tracker_->TrackAcquireImage(*index,
                                              pAcquireInfo->swapchain,
                                              pAcquireInfo->semaphore,
                                              pAcquireInfo->fence,
                                              pAcquireInfo->deviceMask);
        }
        else
        {
            TrackAcquireImageSubset(pAcquireInfo->swapchain, *index);
        }
    }
}

// Performs a subset of the state tracking performed by VulkanStateTracker::TrackPresentedImages,
// only storing values needed for non-tracking capture.
void TrackPresentedImagesSubset(uint32_t count, const VkSwapchainKHR* swapchains, const uint32_t* image_indices)
{
    GFXRECON_ASSERT((count > 0) && (swapchains != nullptr) && (image_indices != nullptr));
    for (uint32_t i = 0; i < count; ++i)
    {
        auto*    wrapper     = vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(swapchains[i]);
        uint32_t image_index = image_indices[i];
        GFXRECON_ASSERT(wrapper != nullptr);
        if (wrapper != nullptr && image_index < wrapper->image_acquired_info.size())
        {
            wrapper->image_acquired_info[image_index].is_acquired = false;
        }
    }
}

void VulkanCaptureManager::PostProcess_vkQueuePresentKHR(
    std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
    VkResult                                               result,
    VkQueue                                                queue,
    const VkPresentInfoKHR*                                pPresentInfo)
{
    if ((result == VK_SUCCESS) || (result == VK_SUBOPTIMAL_KHR))
    {
        if (IsCaptureModeTrack())
        {
            GFXRECON_ASSERT((state_tracker_ != nullptr) && (pPresentInfo != nullptr));
            state_tracker_->TrackSemaphoreSignalState(
                pPresentInfo->waitSemaphoreCount, pPresentInfo->pWaitSemaphores, 0, nullptr);
            state_tracker_->TrackPresentedImages(
                pPresentInfo->swapchainCount, pPresentInfo->pSwapchains, pPresentInfo->pImageIndices, queue);
            state_tracker_->TrackPresentFences(pPresentInfo);
        }
        else
        {
            TrackPresentedImagesSubset(
                pPresentInfo->swapchainCount, pPresentInfo->pSwapchains, pPresentInfo->pImageIndices);
        }
    }

    if (IsCaptureModeTrack())
    {
        if (auto* present_ids = graphics::vulkan_struct_get_pnext<VkPresentIdKHR>(pPresentInfo))
        {
            for (uint32_t i = 0; i < pPresentInfo->swapchainCount; ++i)
            {
                auto wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::SwapchainKHRWrapper>(pPresentInfo->pSwapchains[i]);
                GFXRECON_ASSERT(wrapper);

                wrapper->record_queue_present_ids_not_written.insert(present_ids->pPresentIds[i]);
            }
        }
    }

    EndFrame(current_lock);
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
                        wrapper->shadow_allocation =
                            manager->AllocatePersistentShadowMemory(static_cast<size_t>(wrapper->allocation_size));
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
            else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kSmart)
            {
                VkDeviceSize mapped_size = size;
                if (mapped_size == VK_WHOLE_SIZE)
                {
                    assert(offset <= wrapper->allocation_size);
                    mapped_size = wrapper->allocation_size - offset;
                }

                smart_memory_tracker_.MapMemory(wrapper->handle_id, (*ppData), offset, mapped_size);
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

void VulkanCaptureManager::PostProcess_vkMapMemory2(VkResult               result,
                                                    VkDevice               device,
                                                    const VkMemoryMapInfo* pMemoryMapInfo,
                                                    void**                 ppData)
{
    if ((result == VK_SUCCESS) && (pMemoryMapInfo != nullptr))
    {
        PostProcess_vkMapMemory(result,
                                device,
                                pMemoryMapInfo->memory,
                                pMemoryMapInfo->offset,
                                pMemoryMapInfo->size,
                                pMemoryMapInfo->flags,
                                ppData);
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
        else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kSmart)
        {
            for (uint32_t i = 0; i < memoryRangeCount; ++i)
            {
                auto memory_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(pMemoryRanges[i].memory);

                if ((memory_wrapper != nullptr) && (memory_wrapper->mapped_data != nullptr))
                {
                    VkDeviceSize size = pMemoryRanges[i].size;
                    if (size == VK_WHOLE_SIZE)
                    {
                        assert(pMemoryRanges[i].offset <= memory_wrapper->allocation_size);
                        size = memory_wrapper->allocation_size - pMemoryRanges[i].offset;
                    }

                    smart_memory_tracker_.FlushRange(
                        memory_wrapper->handle_id,
                        pMemoryRanges[i].offset,
                        size,
                        [this](uint64_t memory_id, const void* start_address, size_t offset, size_t size) {
                            WriteFillMemoryRangeCmd(memory_id, offset, size, start_address);
                        });
                }
                else
                {
                    GFXRECON_LOG_WARNING("vkFlushMappedMemoryRanges called for memory that is not mapped");
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

void VulkanCaptureManager::TrackMappedAssetsWrites(format::HandleId memory_id)
{
    GFXRECON_ASSERT(IsCaptureModeTrack() && state_tracker_ != nullptr);
    GFXRECON_ASSERT(GetUseAssetFile());

    util::PageGuardManager* manager = util::PageGuardManager::Get();
    if (manager == nullptr)
    {
        return;
    }

    std::unordered_map<uint64_t, const util::PageGuardManager::MemoryInfo&> memories_page_status;
    manager->GetDirtyMemoryRegions(memory_id, memories_page_status);
    const size_t page_size = util::platform::GetSystemPageSize();

    for (const auto& entry : memories_page_status)
    {
        assert(entry.second.status_tracker.HasActiveWriteBlock());

        const util::PageStatusTracker& page_status = entry.second.status_tracker;

        vulkan_wrappers::DeviceMemoryWrapper* dev_mem_wrapper = state_tracker_->GetDeviceMemoryWrapper(entry.first);
        assert(dev_mem_wrapper != nullptr);

        dev_mem_wrapper->asset_map_lock.lock();
        for (auto& asset : dev_mem_wrapper->bound_assets)
        {
            const size_t mapped_region_end =
                dev_mem_wrapper->mapped_offset + (dev_mem_wrapper->mapped_size == VK_WHOLE_SIZE
                                                      ? dev_mem_wrapper->allocation_size
                                                      : dev_mem_wrapper->mapped_size);
            if (asset->dirty || !asset->size || asset->bind_offset < dev_mem_wrapper->mapped_offset ||
                mapped_region_end < asset->bind_offset)
            {
                continue;
            }

            const size_t asset_offset_from_mapping = asset->bind_offset - dev_mem_wrapper->mapped_offset;
            const size_t first_page                = asset_offset_from_mapping / page_size;
            const size_t last_page                 = (asset_offset_from_mapping + asset->size - 1) / page_size;
            const size_t asset_page_count          = last_page - first_page + 1;
            assert(first_page <= last_page);
            assert(first_page < page_status.GetPageCount());
            assert(first_page + asset_page_count <= page_status.GetPageCount());

            if (page_status.HasActiveWriteBlock(first_page, asset_page_count))
            {
                asset->dirty = true;
            }
        }
        dev_mem_wrapper->asset_map_lock.unlock();
    }
}

void VulkanCaptureManager::TrackAssetsInMemory(format::HandleId memory_id)
{
    TrackMappedAssetsWrites(memory_id);
}

void VulkanCaptureManager::PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceMemoryWrapper>(memory);
    assert(wrapper != nullptr);

    if (wrapper->mapped_data != nullptr)
    {
        // Make sure to call state tracker's TrackAssetsInMemory is called before ProcessMemoryEntry
        // which resets pages' status
        if (IsCaptureModeTrack() && GetUseAssetFile())
        {
            TrackAssetsInMemory(wrapper->handle_id);
        }

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
        else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kSmart)
        {
            smart_memory_tracker_.FlushMappedMemory(
                wrapper->handle_id, [this](uint64_t memory_id, const void* start_address, size_t offset, size_t size) {
                    WriteFillMemoryRangeCmd(memory_id, offset, size, start_address);
                });
            smart_memory_tracker_.UnmapMemory(wrapper->handle_id);
        }

        if (IsCaptureModeTrack())
        {
            GFXRECON_ASSERT(state_tracker_ != nullptr);
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

void VulkanCaptureManager::PreProcess_vkUnmapMemory2(VkDevice device, const VkMemoryUnmapInfo* pMemoryUnmapInfo)
{

    if (pMemoryUnmapInfo != nullptr)
    {
        PreProcess_vkUnmapMemory(device, pMemoryUnmapInfo->memory);
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
            else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kSmart)
            {
                smart_memory_tracker_.FlushMappedMemory(
                    wrapper->handle_id,
                    [this](uint64_t memory_id, const void* start_address, size_t offset, size_t size) {
                        WriteFillMemoryRangeCmd(memory_id, offset, size, start_address);
                    });
                smart_memory_tracker_.UnmapMemory(wrapper->handle_id);
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
        else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kSmart)
        {
            smart_memory_tracker_.RemoveMemory(wrapper->handle_id);
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

void VulkanCaptureManager::MarkReferencedAssetsAsDirty(vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper)
{
    assert(cmd_buf_wrapper != nullptr);

    for (auto& [resource, ranges] : cmd_buf_wrapper->referenced_ranges)
    {
        if ((ranges.access_type & vulkan_wrappers::ResourceAccessType::kWrite) ==
            vulkan_wrappers::ResourceAccessType::kWrite)
        {
            assert(resource);
            resource->dirty = true;
        }
    }
}

void VulkanCaptureManager::TrackAssetsInSubmission(uint32_t submitCount, const VkSubmitInfo* pSubmits)
{
    GFXRECON_ASSERT(IsCaptureModeTrack() && GetUseAssetFile());

    if (pSubmits != nullptr && submitCount)
    {
        for (uint32_t s = 0; s < submitCount; ++s)
        {
            for (uint32_t c = 0; c < pSubmits[s].commandBufferCount; ++c)
            {
                vulkan_wrappers::CommandBufferWrapper* primary =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(pSubmits[s].pCommandBuffers[c]);
                MarkReferencedAssetsAsDirty(primary);

                for (const auto secondary : primary->secondaries)
                {
                    MarkReferencedAssetsAsDirty(secondary);
                }
            }
        }

        TrackMappedAssetsWrites(format::kNullHandleId);
    }
}

void VulkanCaptureManager::TrackAssetsInSubmission(uint32_t submitCount, const VkSubmitInfo2* pSubmits)
{
    GFXRECON_ASSERT(IsCaptureModeTrack() && GetUseAssetFile());

    if (pSubmits != nullptr && submitCount)
    {
        for (uint32_t s = 0; s < submitCount; ++s)
        {
            for (uint32_t c = 0; c < pSubmits[s].commandBufferInfoCount; ++c)
            {
                vulkan_wrappers::CommandBufferWrapper* primary =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(
                        pSubmits[s].pCommandBufferInfos[c].commandBuffer);
                MarkReferencedAssetsAsDirty(primary);

                for (const auto secondary : primary->secondaries)
                {
                    MarkReferencedAssetsAsDirty(secondary);
                }
            }
        }

        TrackMappedAssetsWrites(format::kNullHandleId);
    }
}

void VulkanCaptureManager::PreProcess_vkQueueSubmit(std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
                                                    VkQueue                                                queue,
                                                    uint32_t                                               submitCount,
                                                    const VkSubmitInfo*                                    pSubmits,
                                                    VkFence                                                fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_UNREFERENCED_PARAMETER(submitCount);
    GFXRECON_UNREFERENCED_PARAMETER(pSubmits);
    GFXRECON_UNREFERENCED_PARAMETER(fence);

    // This must be done before QueueSubmitWriteFillMemoryCmd is called
    // and tracked mapped memory regions are resetted
    if (IsCaptureModeTrack() && GetUseAssetFile())
    {
        TrackAssetsInSubmission(submitCount, pSubmits);
    }

    QueueSubmitWriteFillMemoryCmd(submitCount, pSubmits);

    PreQueueSubmit(current_lock);

    if (IsCaptureModeTrack())
    {
        if (pSubmits)
        {
            if (fence != VK_NULL_HANDLE)
            {
                auto* fence_wrapper      = vulkan_wrappers::GetWrapper<vulkan_wrappers::FenceWrapper>(fence);
                fence_wrapper->in_flight = true;
            }

            for (uint32_t s = 0; s < submitCount; ++s)
            {
                state_tracker_->TrackCommandBuffersSubmision(pSubmits[s].commandBufferCount,
                                                             pSubmits[s].pCommandBuffers);
            }
        }
    }
}

void VulkanCaptureManager::PreProcess_vkQueueSubmit2(
    std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
    VkQueue                                                queue,
    uint32_t                                               submitCount,
    const VkSubmitInfo2*                                   pSubmits,
    VkFence                                                fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_UNREFERENCED_PARAMETER(submitCount);
    GFXRECON_UNREFERENCED_PARAMETER(pSubmits);
    GFXRECON_UNREFERENCED_PARAMETER(fence);

    // This must be done before QueueSubmitWriteFillMemoryCmd is called
    // and tracked mapped memory regions are resetted
    if (IsCaptureModeTrack() && GetUseAssetFile())
    {
        TrackAssetsInSubmission(submitCount, pSubmits);
    }

    QueueSubmitWriteFillMemoryCmd(submitCount, pSubmits);

    PreQueueSubmit(current_lock);

    if (IsCaptureModeTrack())
    {
        std::vector<VkCommandBuffer> command_buffs;
        if (pSubmits)
        {
            if (fence != VK_NULL_HANDLE)
            {
                auto* fence_wrapper      = vulkan_wrappers::GetWrapper<vulkan_wrappers::FenceWrapper>(fence);
                fence_wrapper->in_flight = true;
            }

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

            state_tracker_->TrackCommandBuffersSubmision(command_buffs.size(), command_buffs.data());
        }
    }
}

void VulkanCaptureManager::QueueSubmitWriteFillMemoryCmd(uint32_t submit_count, const VkSubmitInfo* submits)
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
    else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kSmart && IsCaptureModeWrite())
    {
        smart_memory_tracker_.ProcessSubmit(
            GetSmartTouchedMemoryRanges(submit_count, submits),
            [this](uint64_t memory_id, const void* start_address, size_t offset, size_t size) {
                WriteFillMemoryRangeCmd(memory_id, offset, size, start_address);
            });
    }
}

void VulkanCaptureManager::QueueSubmitWriteFillMemoryCmd(uint32_t submit_count, const VkSubmitInfo2* submits)
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
    else if (GetMemoryTrackingMode() == CaptureSettings::MemoryTrackingMode::kSmart && IsCaptureModeWrite())
    {
        smart_memory_tracker_.ProcessSubmit(
            GetSmartTouchedMemoryRanges(submit_count, submits),
            [this](uint64_t memory_id, const void* start_address, size_t offset, size_t size) {
                WriteFillMemoryRangeCmd(memory_id, offset, size, start_address);
            });
    }
}

void VulkanCaptureManager::PostProcess_vkCreateDescriptorUpdateTemplate(
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

void VulkanCaptureManager::PostProcess_vkCreateDescriptorUpdateTemplateKHR(
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

void VulkanCaptureManager::PreProcess_vkGetAndroidHardwareBufferPropertiesANDROID(
    VkDevice                                  device,
    const struct AHardwareBuffer*             hardware_buffer,
    VkAndroidHardwareBufferPropertiesANDROID* pProperties)
{
    GFXRECON_UNREFERENCED_PARAMETER(pProperties);
#if defined(VK_USE_PLATFORM_ANDROID_KHR)
    auto device_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DeviceWrapper>(device);

    auto thread_data = GetThreadData();
    assert(thread_data != nullptr);

    if (hardware_buffer != nullptr)
    {
        ProcessHardwareBuffer(thread_data->thread_id_, const_cast<AHardwareBuffer*>(hardware_buffer), device);
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
    std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock,
    const vulkan_wrappers::CommandBufferWrapper*           command_buffer_wrapper)
{
    GFXRECON_ASSERT(command_buffer_wrapper != nullptr);
    if (command_buffer_wrapper->is_frame_boundary)
    {
        // Do common capture manager end of frame processing.
        EndFrame(current_lock);
        return true;
    }
    return false;
}

bool VulkanCaptureManager::CheckPNextChainForFrameBoundary(
    std::shared_lock<CommonCaptureManager::ApiCallMutexT>& current_lock, const VkBaseInStructure* current)
{
    if (auto frame_boundary = graphics::vulkan_struct_get_pnext<VkFrameBoundaryEXT>(current))
    {
        if (frame_boundary->flags & VK_FRAME_BOUNDARY_FRAME_END_BIT_EXT)
        {
            EndFrame(current_lock);
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

void VulkanCaptureManager::PreProcess_vkQueueBindSparse(VkQueue                 queue,
                                                        uint32_t                bindInfoCount,
                                                        const VkBindSparseInfo* pBindInfo,
                                                        VkFence                 fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_UNREFERENCED_PARAMETER(bindInfoCount);
    GFXRECON_UNREFERENCED_PARAMETER(pBindInfo);

    if (IsCaptureModeTrack() && fence != VK_NULL_HANDLE)
    {
        auto* fence_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::FenceWrapper>(fence);
        if (fence_wrapper != nullptr)
        {
            fence_wrapper->in_flight = true;
        }
    }
}

#if ENABLE_OPENXR_SUPPORT
void VulkanCaptureManager::PreProcess_vkDestroyFence(VkDevice                     device,
                                                     VkFence                      fence,
                                                     const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    RemoveValidFence(fence);
}

void VulkanCaptureManager::PreProcess_vkResetFences(VkDevice device, uint32_t fenceCount, const VkFence* pFences)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    if (GetSkipThreadsWithInvalidData())
    {
        for (uint32_t fence = 0; fence < fenceCount; ++fence)
        {
            if (!IsValidFence(pFences[fence]))
            {
                // Skip this thread in the future since it is likely internal to the
                // OpenXR runtime
                util::ThreadData* thread_data = GetThreadData();
                thread_data->EnableSkipCurrentThreadInFuture();
                break;
            }
        }
    }
}

void VulkanCaptureManager::PreProcess_vkGetFenceStatus(VkDevice device, VkFence fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    if (GetSkipThreadsWithInvalidData() && !IsValidFence(fence))
    {
        // Skip this thread in the future since it is likely internal to the
        // OpenXR runtime
        util::ThreadData* thread_data = GetThreadData();
        thread_data->EnableSkipCurrentThreadInFuture();
    }
}

void VulkanCaptureManager::PreProcess_vkWaitForFences(
    VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(waitAll);
    GFXRECON_UNREFERENCED_PARAMETER(timeout);
    if (GetSkipThreadsWithInvalidData())
    {
        for (uint32_t fence = 0; fence < fenceCount; ++fence)
        {
            if (!IsValidFence(pFences[fence]))
            {
                // Skip this thread in the future since it is likely internal to the
                // OpenXR runtime
                util::ThreadData* thread_data = GetThreadData();
                thread_data->EnableSkipCurrentThreadInFuture();
                break;
            }
        }
    }
}
#endif

void VulkanCaptureManager::PostProcess_vkResetFences(VkResult       result,
                                                     VkDevice       device,
                                                     uint32_t       fenceCount,
                                                     const VkFence* pFences)
{
    GFXRECON_UNREFERENCED_PARAMETER(result);
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if (IsCaptureModeTrack())
    {
        for (uint32_t i = 0; i < fenceCount; ++i)
        {
            auto* fence_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::FenceWrapper>(pFences[i]);
            if (fence_wrapper != nullptr)
            {
                fence_wrapper->in_flight = false;
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkWaitForFences(
    VkResult result, VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(waitAll);
    GFXRECON_UNREFERENCED_PARAMETER(timeout);

    if (IsCaptureModeTrack() && result == VK_SUCCESS)
    {
        for (uint32_t i = 0; i < fenceCount; ++i)
        {
            auto* fence_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::FenceWrapper>(pFences[i]);
            if (fence_wrapper != nullptr)
            {
                fence_wrapper->in_flight = false;
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkGetFenceStatus(VkResult result, VkDevice device, VkFence fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if (IsCaptureModeTrack() && result == VK_SUCCESS)
    {
        auto* fence_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::FenceWrapper>(fence);
        if (fence_wrapper != nullptr)
        {
            // fence was already signaled, so clear 'in_flight' flag
            fence_wrapper->in_flight = false;
        }
    }
}

void VulkanCaptureManager::ClearCommandBufferAssetState(vulkan_wrappers::CommandBufferWrapper* wrapper)
{
    GFXRECON_ASSERT(wrapper != nullptr);
    GFXRECON_ASSERT((IsCaptureModeTrack() && GetUseAssetFile()) ||
                    (GetMemoryTrackingMode() == CaptureSettings::kSmart));

    wrapper->referenced_ranges.clear();
    wrapper->secondaries.clear();
    for (uint32_t point = vulkan_state_info::kBindPoint_graphics; point != vulkan_state_info::kBindPoint_count; ++point)
    {
        wrapper->bound_descriptors[point].clear();
    }
}

void VulkanCaptureManager::PreProcess_vkBeginCommandBuffer(VkCommandBuffer                 commandBuffer,
                                                           const VkCommandBufferBeginInfo* pBeginInfo)
{
    auto* cmd_buffer_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);

    if (cmd_buffer_wrapper != nullptr)
    {
        // If command buffer level is primary, pInheritanceInfo must be ignored
        if (cmd_buffer_wrapper->level == VK_COMMAND_BUFFER_LEVEL_PRIMARY)
        {
            // const_cast to avoid changes to code-gen
            const_cast<VkCommandBufferBeginInfo*>(pBeginInfo)->pInheritanceInfo = nullptr;
        }

        if (NeedsCommandBufferResourceTracking())
        {
            ClearCommandBufferAssetState(cmd_buffer_wrapper);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindIndexBuffer(VkCommandBuffer commandBuffer,
                                                            VkBuffer        buffer,
                                                            VkDeviceSize    offset,
                                                            VkIndexType     indexType)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertBufferAssetInCommandBuffer(commandBuffer, buffer, vulkan_wrappers::ResourceAccessType::kRead, offset);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindIndexBuffer2(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, VkDeviceSize size, VkIndexType indexType)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertBufferAssetInCommandBuffer(
            commandBuffer, buffer, vulkan_wrappers::ResourceAccessType::kRead, offset, size);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindVertexBuffers(VkCommandBuffer     commandBuffer,
                                                              uint32_t            firstBinding,
                                                              uint32_t            bindingCount,
                                                              const VkBuffer*     pBuffers,
                                                              const VkDeviceSize* pOffsets)
{
    if (NeedsCommandBufferResourceTracking() && pBuffers != nullptr && pOffsets != nullptr)
    {
        for (uint32_t i = 0; i < bindingCount; ++i)
        {
            InsertBufferAssetInCommandBuffer(
                commandBuffer, pBuffers[i], vulkan_wrappers::ResourceAccessType::kRead, pOffsets[i]);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindVertexBuffers2(VkCommandBuffer     commandBuffer,
                                                               uint32_t            firstBinding,
                                                               uint32_t            bindingCount,
                                                               const VkBuffer*     pBuffers,
                                                               const VkDeviceSize* pOffsets,
                                                               const VkDeviceSize* pSizes,
                                                               const VkDeviceSize* pStrides)
{
    if (NeedsCommandBufferResourceTracking() && pBuffers != nullptr && pOffsets != nullptr)
    {
        for (uint32_t i = 0; i < bindingCount; ++i)
        {
            InsertBufferAssetInCommandBuffer(commandBuffer,
                                             pBuffers[i],
                                             vulkan_wrappers::ResourceAccessType::kRead,
                                             pOffsets[i],
                                             pSizes != nullptr ? pSizes[i] : VK_WHOLE_SIZE);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDraw(VkCommandBuffer commandBuffer,
                                                 uint32_t        vertexCount,
                                                 uint32_t        instanceCount,
                                                 uint32_t        firstVertex,
                                                 uint32_t        firstInstance)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndexed(VkCommandBuffer commandBuffer,
                                                        uint32_t        indexCount,
                                                        uint32_t        instanceCount,
                                                        uint32_t        firstIndex,
                                                        int32_t         vertexOffset,
                                                        uint32_t        firstInstance)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndirect(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndexedIndirect(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndirectCount(VkCommandBuffer commandBuffer,
                                                              VkBuffer        buffer,
                                                              VkDeviceSize    offset,
                                                              VkBuffer        countBuffer,
                                                              VkDeviceSize    countBufferOffset,
                                                              uint32_t        maxDrawCount,
                                                              uint32_t        stride)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndexedIndirectCount(VkCommandBuffer commandBuffer,
                                                                     VkBuffer        buffer,
                                                                     VkDeviceSize    offset,
                                                                     VkBuffer        countBuffer,
                                                                     VkDeviceSize    countBufferOffset,
                                                                     uint32_t        maxDrawCount,
                                                                     uint32_t        stride)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndirectCountKHR(VkCommandBuffer commandBuffer,
                                                                 VkBuffer        buffer,
                                                                 VkDeviceSize    offset,
                                                                 VkBuffer        countBuffer,
                                                                 VkDeviceSize    countBufferOffset,
                                                                 uint32_t        maxDrawCount,
                                                                 uint32_t        stride)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanCaptureManager::PostProcess_vkCmdDrawIndexedIndirectCountKHR(VkCommandBuffer commandBuffer,
                                                                        VkBuffer        buffer,
                                                                        VkDeviceSize    offset,
                                                                        VkBuffer        countBuffer,
                                                                        VkDeviceSize    countBufferOffset,
                                                                        uint32_t        maxDrawCount,
                                                                        uint32_t        stride)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
}

void VulkanCaptureManager::PostProcess_vkCmdDispatch(VkCommandBuffer commandBuffer,
                                                     uint32_t        groupCountX,
                                                     uint32_t        groupCountY,
                                                     uint32_t        groupCountZ)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);
}

void VulkanCaptureManager::PostProcess_vkCmdDispatchIndirect(VkCommandBuffer commandBuffer,
                                                             VkBuffer        buffer,
                                                             VkDeviceSize    offset)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);
}

void VulkanCaptureManager::PostProcess_vkCmdDispatchBase(VkCommandBuffer commandBuffer,
                                                         uint32_t        baseGroupX,
                                                         uint32_t        baseGroupY,
                                                         uint32_t        baseGroupZ,
                                                         uint32_t        groupCountX,
                                                         uint32_t        groupCountY,
                                                         uint32_t        groupCountZ)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);
}

void VulkanCaptureManager::PostProcess_vkCmdDispatchBaseKHR(VkCommandBuffer commandBuffer,
                                                            uint32_t        baseGroupX,
                                                            uint32_t        baseGroupY,
                                                            uint32_t        baseGroupZ,
                                                            uint32_t        groupCountX,
                                                            uint32_t        groupCountY,
                                                            uint32_t        groupCountZ)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_compute);
}

void VulkanCaptureManager::PostProcess_vkCmdTraceRaysNV(VkCommandBuffer commandBuffer,
                                                        VkBuffer        raygenShaderBindingTableBuffer,
                                                        VkDeviceSize    raygenShaderBindingOffset,
                                                        VkBuffer        missShaderBindingTableBuffer,
                                                        VkDeviceSize    missShaderBindingOffset,
                                                        VkDeviceSize    missShaderBindingStride,
                                                        VkBuffer        hitShaderBindingTableBuffer,
                                                        VkDeviceSize    hitShaderBindingOffset,
                                                        VkDeviceSize    hitShaderBindingStride,
                                                        VkBuffer        callableShaderBindingTableBuffer,
                                                        VkDeviceSize    callableShaderBindingOffset,
                                                        VkDeviceSize    callableShaderBindingStride,
                                                        uint32_t        width,
                                                        uint32_t        height,
                                                        uint32_t        depth)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);
}

void VulkanCaptureManager::PostProcess_vkCmdTraceRaysKHR(
    VkCommandBuffer                        commandBuffer,
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
    uint32_t                               width,
    uint32_t                               height,
    uint32_t                               depth)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);
}

void VulkanCaptureManager::PostProcess_vkCmdTraceRaysIndirectKHR(
    VkCommandBuffer                        commandBuffer,
    const VkStridedDeviceAddressRegionKHR* pRaygenShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pMissShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pHitShaderBindingTable,
    const VkStridedDeviceAddressRegionKHR* pCallableShaderBindingTable,
    VkDeviceAddress                        indirectDeviceAddress)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);
}

void VulkanCaptureManager::PostProcess_vkCmdTraceRaysIndirect2KHR(VkCommandBuffer commandBuffer,
                                                                  VkDeviceAddress indirectDeviceAddress)
{
    TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_ray_tracing);
}

void VulkanCaptureManager::UpdateCommandBufferDescriptors(VkCommandBuffer        commandBuffer,
                                                          VkPipelineBindPoint    pipelineBindPoint,
                                                          uint32_t               firstSet,
                                                          uint32_t               descriptorSetCount,
                                                          const VkDescriptorSet* pDescriptorSets,
                                                          uint32_t               dynamicOffsetCount,
                                                          const uint32_t*        pDynamicOffsets)
{
    vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);

    if (cmd_buf_wrapper == nullptr || pDescriptorSets == nullptr)
    {
        return;
    }

    const vulkan_state_info::PipelineBindPoints bind_point =
        vulkan_state_info::VkPipelinePointToPipelinePoint(pipelineBindPoint);

    uint32_t dynamic_offset = 0;
    for (uint32_t i = 0; i < descriptorSetCount; ++i)
    {
        const vulkan_wrappers::DescriptorSetWrapper* desc_set_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(pDescriptorSets[i]);

        auto& bound    = cmd_buf_wrapper->bound_descriptors[bind_point][firstSet + i];
        bound.desc_set = desc_set_wrapper;
        bound.dynamic_offsets.clear();

        // Elements of pDescriptorSets may be VK_NULL_HANDLE when the graphicsPipelineLibrary feature is enabled
        if (desc_set_wrapper == nullptr)
        {
            continue;
        }

        // pDynamicOffsets entries apply to the sets in bind order, then within each set in
        // increasing binding index, then array element
        std::vector<uint32_t> dynamic_bindings;
        for (const auto& [binding_index, binding] : desc_set_wrapper->bindings)
        {
            if (binding.type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC ||
                binding.type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC)
            {
                dynamic_bindings.push_back(binding_index);
            }
        }
        std::sort(dynamic_bindings.begin(), dynamic_bindings.end());

        for (uint32_t binding_index : dynamic_bindings)
        {
            const vulkan_state_info::DescriptorInfo& info    = desc_set_wrapper->bindings.at(binding_index);
            std::vector<uint32_t>&                   offsets = bound.dynamic_offsets[binding_index];
            offsets.resize(info.count);
            for (uint32_t ai = 0; ai < info.count; ++ai)
            {
                GFXRECON_ASSERT(dynamic_offset < dynamicOffsetCount);
                offsets[ai] = (pDynamicOffsets != nullptr && dynamic_offset < dynamicOffsetCount)
                                  ? pDynamicOffsets[dynamic_offset]
                                  : 0;
                ++dynamic_offset;
            }
        }
    }
    GFXRECON_ASSERT(dynamic_offset == dynamicOffsetCount);
}

void VulkanCaptureManager::PostProcess_vkCmdBindDescriptorSets(VkCommandBuffer        commandBuffer,
                                                               VkPipelineBindPoint    pipelineBindPoint,
                                                               VkPipelineLayout       layout,
                                                               uint32_t               firstSet,
                                                               uint32_t               descriptorSetCount,
                                                               const VkDescriptorSet* pDescriptorSets,
                                                               uint32_t               dynamicOffsetCount,
                                                               const uint32_t*        pDynamicOffsets)
{
    if (NeedsCommandBufferResourceTracking())
    {
        UpdateCommandBufferDescriptors(commandBuffer,
                                       pipelineBindPoint,
                                       firstSet,
                                       descriptorSetCount,
                                       pDescriptorSets,
                                       dynamicOffsetCount,
                                       pDynamicOffsets);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindDescriptorSets2KHR(
    VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo)
{
    if (NeedsCommandBufferResourceTracking())
    {
        if (pBindDescriptorSetsInfo != nullptr)
        {
            const std::vector<VkPipelineBindPoint> bind_points =
                graphics::ShaderStageFlagsToPipelineBindPoints(pBindDescriptorSetsInfo->stageFlags);
            for (const VkPipelineBindPoint bind_point : bind_points)
            {
                UpdateCommandBufferDescriptors(commandBuffer,
                                               bind_point,
                                               pBindDescriptorSetsInfo->firstSet,
                                               pBindDescriptorSetsInfo->descriptorSetCount,
                                               pBindDescriptorSetsInfo->pDescriptorSets,
                                               pBindDescriptorSetsInfo->dynamicOffsetCount,
                                               pBindDescriptorSetsInfo->pDynamicOffsets);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBindDescriptorSets2(
    VkCommandBuffer commandBuffer, const VkBindDescriptorSetsInfoKHR* pBindDescriptorSetsInfo)
{
    PostProcess_vkCmdBindDescriptorSets2KHR(commandBuffer, pBindDescriptorSetsInfo);
}

void VulkanCaptureManager::InsertImageAssetInCommandBuffer(VkCommandBuffer                     command_buffer,
                                                           VkImage                             image,
                                                           vulkan_wrappers::ResourceAccessType access)
{
    GFXRECON_ASSERT((IsCaptureModeTrack() && GetUseAssetFile()) ||
                    (GetMemoryTrackingMode() == CaptureSettings::kSmart));

    if (command_buffer != VK_NULL_HANDLE && image != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::ImageWrapper* image_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageWrapper>(image);
        assert(image_wrapper != nullptr);

        if (image_wrapper != nullptr)
        {
            cmd_buf_wrapper->ReferenceResource(image_wrapper, 0, image_wrapper->size, access);
        }
    }
}

void VulkanCaptureManager::InsertBufferAssetInCommandBuffer(VkCommandBuffer                     command_buffer,
                                                            VkBuffer                            buffer,
                                                            vulkan_wrappers::ResourceAccessType access,
                                                            uint64_t                            offset,
                                                            uint64_t                            size)
{
    GFXRECON_ASSERT((IsCaptureModeTrack() && GetUseAssetFile()) ||
                    (GetMemoryTrackingMode() == CaptureSettings::kSmart));

    if (command_buffer != VK_NULL_HANDLE && buffer != VK_NULL_HANDLE)
    {
        vulkan_wrappers::CommandBufferWrapper* cmd_buf_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
        assert(cmd_buf_wrapper != nullptr);

        vulkan_wrappers::BufferWrapper* buffer_wrapper =
            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(buffer);
        assert(buffer_wrapper != nullptr);

        if (buffer_wrapper != nullptr)
        {
            cmd_buf_wrapper->ReferenceResource(buffer_wrapper, offset, size, access);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBuffer(VkCommandBuffer     commandBuffer,
                                                       VkBuffer            srcBuffer,
                                                       VkBuffer            dstBuffer,
                                                       uint32_t            regionCount,
                                                       const VkBufferCopy* pRegions)
{
    if (NeedsCommandBufferResourceTracking())
    {
        if (pRegions != nullptr)
        {
            for (uint32_t i = 0; i < regionCount; ++i)
            {
                InsertBufferAssetInCommandBuffer(commandBuffer,
                                                 srcBuffer,
                                                 vulkan_wrappers::ResourceAccessType::kRead,
                                                 pRegions[i].srcOffset,
                                                 pRegions[i].size);
                InsertBufferAssetInCommandBuffer(commandBuffer,
                                                 dstBuffer,
                                                 vulkan_wrappers::ResourceAccessType::kWrite,
                                                 pRegions[i].dstOffset,
                                                 pRegions[i].size);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImage(VkCommandBuffer    commandBuffer,
                                                      VkImage            srcImage,
                                                      VkImageLayout      srcImageLayout,
                                                      VkImage            dstImage,
                                                      VkImageLayout      dstImageLayout,
                                                      uint32_t           regionCount,
                                                      const VkImageCopy* pRegions)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertImageAssetInCommandBuffer(commandBuffer, srcImage, vulkan_wrappers::ResourceAccessType::kRead);
        InsertImageAssetInCommandBuffer(commandBuffer, dstImage, vulkan_wrappers::ResourceAccessType::kWrite);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBufferToImage(VkCommandBuffer          commandBuffer,
                                                              VkBuffer                 srcBuffer,
                                                              VkImage                  dstImage,
                                                              VkImageLayout            dstImageLayout,
                                                              uint32_t                 regionCount,
                                                              const VkBufferImageCopy* pRegions)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertBufferAssetInCommandBuffer(commandBuffer, srcBuffer, vulkan_wrappers::ResourceAccessType::kRead);
        InsertImageAssetInCommandBuffer(commandBuffer, dstImage, vulkan_wrappers::ResourceAccessType::kWrite);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImageToBuffer(VkCommandBuffer          commandBuffer,
                                                              VkImage                  srcImage,
                                                              VkImageLayout            srcImageLayout,
                                                              VkBuffer                 dstBuffer,
                                                              uint32_t                 regionCount,
                                                              const VkBufferImageCopy* pRegions)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertImageAssetInCommandBuffer(commandBuffer, srcImage, vulkan_wrappers::ResourceAccessType::kRead);
        InsertBufferAssetInCommandBuffer(commandBuffer, dstBuffer, vulkan_wrappers::ResourceAccessType::kWrite);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBuffer2(VkCommandBuffer          commandBuffer,
                                                        const VkCopyBufferInfo2* pCopyBufferInfo)
{
    if (NeedsCommandBufferResourceTracking())
    {
        if (pCopyBufferInfo != nullptr)
        {
            for (uint32_t i = 0; i < pCopyBufferInfo->regionCount; ++i)
            {
                InsertBufferAssetInCommandBuffer(commandBuffer,
                                                 pCopyBufferInfo->srcBuffer,
                                                 vulkan_wrappers::ResourceAccessType::kRead,
                                                 pCopyBufferInfo->pRegions[i].dstOffset,
                                                 pCopyBufferInfo->pRegions[i].size);

                InsertBufferAssetInCommandBuffer(commandBuffer,
                                                 pCopyBufferInfo->dstBuffer,
                                                 vulkan_wrappers::ResourceAccessType::kWrite,
                                                 pCopyBufferInfo->pRegions[i].dstOffset,
                                                 pCopyBufferInfo->pRegions[i].size);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImage2(VkCommandBuffer         commandBuffer,
                                                       const VkCopyImageInfo2* pCopyImageInfo)
{
    if (NeedsCommandBufferResourceTracking())
    {
        if (pCopyImageInfo != nullptr)
        {
            InsertImageAssetInCommandBuffer(
                commandBuffer, pCopyImageInfo->srcImage, vulkan_wrappers::ResourceAccessType::kRead);
            InsertImageAssetInCommandBuffer(
                commandBuffer, pCopyImageInfo->dstImage, vulkan_wrappers::ResourceAccessType::kWrite);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBufferToImage2(VkCommandBuffer                 commandBuffer,
                                                               const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    if (NeedsCommandBufferResourceTracking())
    {
        if (pCopyBufferToImageInfo != nullptr)
        {
            InsertBufferAssetInCommandBuffer(
                commandBuffer, pCopyBufferToImageInfo->srcBuffer, vulkan_wrappers::ResourceAccessType::kRead);
            InsertImageAssetInCommandBuffer(
                commandBuffer, pCopyBufferToImageInfo->dstImage, vulkan_wrappers::ResourceAccessType::kWrite);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImageToBuffer2(VkCommandBuffer                 commandBuffer,
                                                               const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    if (NeedsCommandBufferResourceTracking())
    {
        if (pCopyImageToBufferInfo != nullptr)
        {
            InsertImageAssetInCommandBuffer(
                commandBuffer, pCopyImageToBufferInfo->srcImage, vulkan_wrappers::ResourceAccessType::kRead);
            InsertBufferAssetInCommandBuffer(
                commandBuffer, pCopyImageToBufferInfo->dstBuffer, vulkan_wrappers::ResourceAccessType::kWrite);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBuffer2KHR(VkCommandBuffer          commandBuffer,
                                                           const VkCopyBufferInfo2* pCopyBufferInfo)
{
    PostProcess_vkCmdCopyBuffer2(commandBuffer, pCopyBufferInfo);
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImage2KHR(VkCommandBuffer         commandBuffer,
                                                          const VkCopyImageInfo2* pCopyImageInfo)
{
    PostProcess_vkCmdCopyImage2(commandBuffer, pCopyImageInfo);
}

void VulkanCaptureManager::PostProcess_vkCmdCopyBufferToImage2KHR(
    VkCommandBuffer commandBuffer, const VkCopyBufferToImageInfo2* pCopyBufferToImageInfo)
{
    PostProcess_vkCmdCopyBufferToImage2(commandBuffer, pCopyBufferToImageInfo);
}

void VulkanCaptureManager::PostProcess_vkCmdCopyImageToBuffer2KHR(
    VkCommandBuffer commandBuffer, const VkCopyImageToBufferInfo2* pCopyImageToBufferInfo)
{
    PostProcess_vkCmdCopyImageToBuffer2(commandBuffer, pCopyImageToBufferInfo);
}

void VulkanCaptureManager::PostProcess_vkCmdBlitImage(VkCommandBuffer    commandBuffer,
                                                      VkImage            srcImage,
                                                      VkImageLayout      srcImageLayout,
                                                      VkImage            dstImage,
                                                      VkImageLayout      dstImageLayout,
                                                      uint32_t           regionCount,
                                                      const VkImageBlit* pRegions,
                                                      VkFilter           filter)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertImageAssetInCommandBuffer(commandBuffer, srcImage, vulkan_wrappers::ResourceAccessType::kRead);
        InsertImageAssetInCommandBuffer(commandBuffer, dstImage, vulkan_wrappers::ResourceAccessType::kWrite);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBlitImage2(VkCommandBuffer         commandBuffer,
                                                       const VkBlitImageInfo2* pBlitImageInfo)
{
    if (NeedsCommandBufferResourceTracking())
    {
        if (pBlitImageInfo != nullptr)
        {
            InsertImageAssetInCommandBuffer(
                commandBuffer, pBlitImageInfo->srcImage, vulkan_wrappers::ResourceAccessType::kRead);
            InsertImageAssetInCommandBuffer(
                commandBuffer, pBlitImageInfo->dstImage, vulkan_wrappers::ResourceAccessType::kWrite);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBlitImage2KHR(VkCommandBuffer         commandBuffer,
                                                          const VkBlitImageInfo2* pBlitImageInfo)
{
    if (NeedsCommandBufferResourceTracking())
    {
        PostProcess_vkCmdBlitImage2(commandBuffer, pBlitImageInfo);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdUpdateBuffer(
    VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize dataSize, const void* pData)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertBufferAssetInCommandBuffer(
            commandBuffer, dstBuffer, vulkan_wrappers::ResourceAccessType::kWrite, dstOffset, dataSize);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdFillBuffer(
    VkCommandBuffer commandBuffer, VkBuffer dstBuffer, VkDeviceSize dstOffset, VkDeviceSize size, uint32_t data)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertBufferAssetInCommandBuffer(
            commandBuffer, dstBuffer, vulkan_wrappers::ResourceAccessType::kWrite, dstOffset, size);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdClearColorImage(VkCommandBuffer                commandBuffer,
                                                            VkImage                        image,
                                                            VkImageLayout                  imageLayout,
                                                            const VkClearColorValue*       pColor,
                                                            uint32_t                       rangeCount,
                                                            const VkImageSubresourceRange* pRanges)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertImageAssetInCommandBuffer(commandBuffer, image, vulkan_wrappers::ResourceAccessType::kWrite);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdClearDepthStencilImage(VkCommandBuffer                 commandBuffer,
                                                                   VkImage                         image,
                                                                   VkImageLayout                   imageLayout,
                                                                   const VkClearDepthStencilValue* pDepthStencil,
                                                                   uint32_t                        rangeCount,
                                                                   const VkImageSubresourceRange*  pRanges)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertImageAssetInCommandBuffer(commandBuffer, image, vulkan_wrappers::ResourceAccessType::kWrite);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdResolveImage(VkCommandBuffer       commandBuffer,
                                                         VkImage               srcImage,
                                                         VkImageLayout         srcImageLayout,
                                                         VkImage               dstImage,
                                                         VkImageLayout         dstImageLayout,
                                                         uint32_t              regionCount,
                                                         const VkImageResolve* pRegions)
{
    if (NeedsCommandBufferResourceTracking())
    {
        InsertImageAssetInCommandBuffer(commandBuffer, srcImage, vulkan_wrappers::ResourceAccessType::kRead);
        InsertImageAssetInCommandBuffer(commandBuffer, dstImage, vulkan_wrappers::ResourceAccessType::kWrite);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdResolveImage2(VkCommandBuffer            commandBuffer,
                                                          const VkResolveImageInfo2* pResolveImageInfo)
{
    if (NeedsCommandBufferResourceTracking())
    {
        if (pResolveImageInfo != nullptr)
        {
            InsertImageAssetInCommandBuffer(
                commandBuffer, pResolveImageInfo->srcImage, vulkan_wrappers::ResourceAccessType::kRead);
            InsertImageAssetInCommandBuffer(
                commandBuffer, pResolveImageInfo->dstImage, vulkan_wrappers::ResourceAccessType::kWrite);
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdResolveImage2KHR(VkCommandBuffer            commandBuffer,
                                                             const VkResolveImageInfo2* pResolveImageInfo)
{
    if (NeedsCommandBufferResourceTracking())
    {
        PostProcess_vkCmdResolveImage2(commandBuffer, pResolveImageInfo);
    }
}

void VulkanCaptureManager::TrackPipelineDescriptors(VkCommandBuffer                       command_buffer,
                                                    vulkan_state_info::PipelineBindPoints ppl_bind_point)
{
    GFXRECON_ASSERT(ppl_bind_point < vulkan_state_info::PipelineBindPoints::kBindPoint_count);

    if (!NeedsCommandBufferResourceTracking())
    {
        return;
    }

    auto command_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    if (command_wrapper == nullptr)
    {
        return;
    }

    for (const auto& [desc_set_index, desc_bindings] : command_wrapper->bound_descriptors[ppl_bind_point])
    {
        const vulkan_wrappers::DescriptorSetWrapper* desc_set_wrapper = desc_bindings.desc_set;
        if (desc_set_wrapper == nullptr)
        {
            continue;
        }

        for (const auto& [binding_index, descriptor_binding] : desc_set_wrapper->bindings)
        {
            switch (descriptor_binding.type)
            {
                case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                {
                    for (uint32_t ai = 0; ai < descriptor_binding.count; ++ai)
                    {
                        vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                                descriptor_binding.storage_images[ai].imageView);
                        if (img_view_wrapper != nullptr && img_view_wrapper->image != nullptr)
                        {
                            command_wrapper->ReferenceResource(img_view_wrapper->image,
                                                               0,
                                                               img_view_wrapper->image->size,
                                                               vulkan_wrappers::ResourceAccessType::kRead |
                                                                   vulkan_wrappers::ResourceAccessType::kWrite);
                        }
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                {
                    for (uint32_t ai = 0; ai < descriptor_binding.count; ++ai)
                    {
                        vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                                descriptor_binding.images[ai].imageView);
                        if (img_view_wrapper != nullptr && img_view_wrapper->image != nullptr)
                        {
                            command_wrapper->ReferenceResource(img_view_wrapper->image,
                                                               0,
                                                               img_view_wrapper->image->size,
                                                               vulkan_wrappers::ResourceAccessType::kRead);
                        }
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                {
                    for (uint32_t ai = 0; ai < descriptor_binding.count; ++ai)
                    {
                        auto* buf_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                            descriptor_binding.storage_buffers[ai].buffer);
                        if (buf_wrapper != nullptr)
                        {
                            const uint32_t dynamic_offset =
                                command_wrapper->GetDynamicOffset(desc_set_index, binding_index, ai, ppl_bind_point);
                            command_wrapper->ReferenceResource(buf_wrapper,
                                                               descriptor_binding.storage_buffers[ai].offset +
                                                                   dynamic_offset,
                                                               descriptor_binding.storage_buffers[ai].range,
                                                               vulkan_wrappers::ResourceAccessType::kRead |
                                                                   vulkan_wrappers::ResourceAccessType::kWrite);
                        }
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                {
                    for (uint32_t ai = 0; ai < descriptor_binding.count; ++ai)
                    {
                        auto* buf_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                            descriptor_binding.buffers[ai].buffer);
                        if (buf_wrapper != nullptr)
                        {
                            const uint32_t dynamic_offset =
                                command_wrapper->GetDynamicOffset(desc_set_index, binding_index, ai, ppl_bind_point);
                            command_wrapper->ReferenceResource(buf_wrapper,
                                                               descriptor_binding.buffers[ai].offset + dynamic_offset,
                                                               descriptor_binding.buffers[ai].range,
                                                               vulkan_wrappers::ResourceAccessType::kRead);
                        }
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                {
                    for (uint32_t ai = 0; ai < descriptor_binding.count; ++ai)
                    {
                        vulkan_wrappers::BufferViewWrapper* buf_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                                descriptor_binding.storage_texel_buffer_views[ai]);
                        if (buf_view_wrapper != nullptr && buf_view_wrapper->buffer != nullptr)
                        {
                            command_wrapper->ReferenceResource(buf_view_wrapper->buffer,
                                                               buf_view_wrapper->offset,
                                                               buf_view_wrapper->range,
                                                               vulkan_wrappers::ResourceAccessType::kRead |
                                                                   vulkan_wrappers::ResourceAccessType::kWrite);
                        }
                    }
                }
                break;

                case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                {
                    for (uint32_t ai = 0; ai < descriptor_binding.count; ++ai)
                    {
                        vulkan_wrappers::BufferViewWrapper* buf_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                                descriptor_binding.uniform_texel_buffer_views[ai]);
                        if (buf_view_wrapper != nullptr && buf_view_wrapper->buffer != nullptr)
                        {
                            command_wrapper->ReferenceResource(buf_view_wrapper->buffer,
                                                               buf_view_wrapper->offset,
                                                               buf_view_wrapper->range,
                                                               vulkan_wrappers::ResourceAccessType::kRead);
                        }
                    }
                }
                break;

                // Rest of descriptors are immutable within a shader
                default:
                    break;
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksNV(VkCommandBuffer commandBuffer,
                                                            uint32_t        taskCount,
                                                            uint32_t        firstTask)
{
    if (taskCount)
    {
        TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksIndirectNV(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    if (drawCount)
    {
        TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksIndirectCountNV(VkCommandBuffer commandBuffer,
                                                                         VkBuffer        buffer,
                                                                         VkDeviceSize    offset,
                                                                         VkBuffer        countBuffer,
                                                                         VkDeviceSize    countBufferOffset,
                                                                         uint32_t        maxDrawCount,
                                                                         uint32_t        stride)
{
    if (maxDrawCount)
    {
        TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksEXT(VkCommandBuffer commandBuffer,
                                                             uint32_t        groupCountX,
                                                             uint32_t        groupCountY,
                                                             uint32_t        groupCountZ)
{
    if (groupCountX && groupCountY && groupCountZ)
    {
        TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksIndirectEXT(
    VkCommandBuffer commandBuffer, VkBuffer buffer, VkDeviceSize offset, uint32_t drawCount, uint32_t stride)
{
    if (drawCount)
    {
        TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdDrawMeshTasksIndirectCountEXT(VkCommandBuffer commandBuffer,
                                                                          VkBuffer        buffer,
                                                                          VkDeviceSize    offset,
                                                                          VkBuffer        countBuffer,
                                                                          VkDeviceSize    countBufferOffset,
                                                                          uint32_t        maxDrawCount,
                                                                          uint32_t        stride)
{
    if (maxDrawCount)
    {
        TrackPipelineDescriptors(commandBuffer, vulkan_state_info::PipelineBindPoints::kBindPoint_graphics);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBeginRendering(VkCommandBuffer        commandBuffer,
                                                           const VkRenderingInfo* pRenderingInfo)
{
    if (NeedsCommandBufferResourceTracking())
    {
        auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
        if (wrapper != nullptr && pRenderingInfo != nullptr)
        {
            for (uint32_t i = 0; i < pRenderingInfo->colorAttachmentCount; ++i)
            {
                if (pRenderingInfo->pColorAttachments[i].storeOp == VK_ATTACHMENT_STORE_OP_STORE)
                {
                    vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                        vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                            pRenderingInfo->pColorAttachments[i].imageView);

                    // The image view is allowed to be null
                    if (img_view_wrapper != nullptr)
                    {
                        wrapper->ReferenceResource(img_view_wrapper->image,
                                                   0,
                                                   img_view_wrapper->image->size,
                                                   vulkan_wrappers::ResourceAccessType::kWrite);
                    }
                }
            }

            if (pRenderingInfo->pDepthAttachment != nullptr &&
                pRenderingInfo->pDepthAttachment->storeOp == VK_ATTACHMENT_STORE_OP_STORE)
            {
                vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                        pRenderingInfo->pDepthAttachment->imageView);
                assert(img_view_wrapper != nullptr);

                if (img_view_wrapper != nullptr)
                {
                    wrapper->ReferenceResource(img_view_wrapper->image,
                                               0,
                                               img_view_wrapper->image->size,
                                               vulkan_wrappers::ResourceAccessType::kWrite);
                }
            }

            if (pRenderingInfo->pStencilAttachment != nullptr &&
                pRenderingInfo->pStencilAttachment->storeOp == VK_ATTACHMENT_STORE_OP_STORE)
            {
                vulkan_wrappers::ImageViewWrapper* img_view_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                        pRenderingInfo->pStencilAttachment->imageView);
                assert(img_view_wrapper != nullptr);

                if (img_view_wrapper != nullptr)
                {
                    wrapper->ReferenceResource(img_view_wrapper->image,
                                               0,
                                               img_view_wrapper->image->size,
                                               vulkan_wrappers::ResourceAccessType::kWrite);
                }
            }
        }
    }
}

void VulkanCaptureManager::MarkRenderPassAttachmentsAsModified(VkCommandBuffer commandBuffer)
{
    GFXRECON_ASSERT(NeedsCommandBufferResourceTracking());

    auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(commandBuffer);
    if (wrapper != nullptr && wrapper->render_pass_framebuffer != nullptr)
    {
        for (size_t i = 0; i < wrapper->render_pass_framebuffer->attachments.size(); ++i)
        {
            if (wrapper->render_pass_framebuffer->attachments[i]->is_swapchain_image)
            {
                continue;
            }

            const bool has_stencil = vkuFormatHasStencil(wrapper->render_pass_framebuffer->attachments[i]->format);
            if ((!has_stencil &&
                 wrapper->active_render_pass->attachment_info.store_op[i] == VK_ATTACHMENT_STORE_OP_STORE) ||
                (has_stencil &&
                 wrapper->active_render_pass->attachment_info.stencil_store_op[i] == VK_ATTACHMENT_STORE_OP_STORE))
            {
                wrapper->ReferenceResource(wrapper->render_pass_framebuffer->attachments[i],
                                           0,
                                           wrapper->render_pass_framebuffer->attachments[i]->size,
                                           vulkan_wrappers::ResourceAccessType::kWrite);
            }
        }
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBeginRenderPass(VkCommandBuffer              commandBuffer,
                                                            const VkRenderPassBeginInfo* pRenderPassBegin,
                                                            VkSubpassContents)
{
    if (NeedsCommandBufferResourceTracking() || IsCaptureModeTrack())
    {
        TrackBeginRenderPass(commandBuffer, pRenderPassBegin);
    }

    if (NeedsCommandBufferResourceTracking())
    {
        MarkRenderPassAttachmentsAsModified(commandBuffer);
    }
}

void VulkanCaptureManager::PostProcess_vkCmdBeginRenderPass2(VkCommandBuffer              commandBuffer,
                                                             const VkRenderPassBeginInfo* pRenderPassBegin,
                                                             const VkSubpassBeginInfoKHR*)
{
    if (NeedsCommandBufferResourceTracking() || IsCaptureModeTrack())
    {
        TrackBeginRenderPass(commandBuffer, pRenderPassBegin);
    }

    if (NeedsCommandBufferResourceTracking())
    {
        MarkRenderPassAttachmentsAsModified(commandBuffer);
    }
}

void VulkanCaptureManager::PostProcess_vkSetDebugUtilsObjectNameEXT(VkResult                             result,
                                                                    VkDevice                             device,
                                                                    const VkDebugUtilsObjectNameInfoEXT* pNameInfo)
{
    if (result == VK_SUCCESS)
    {
        if (IsCaptureModeTrack())
        {
            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);
            state_tracker_->TrackSetDebugUtilsObjectNameEXT(device, pNameInfo, thread_data->parameter_buffer_.get());
        }
    }
}

void VulkanCaptureManager::PostProcess_vkSetDebugUtilsObjectTagEXT(VkResult                            result,
                                                                   VkDevice                            device,
                                                                   const VkDebugUtilsObjectTagInfoEXT* pTagInfo)
{
    if (result == VK_SUCCESS)
    {
        if (IsCaptureModeTrack())
        {
            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);
            state_tracker_->TrackSetDebugUtilsObjectTagEXT(device, pTagInfo, thread_data->parameter_buffer_.get());
        }
    }
}

#if ENABLE_OPENXR_SUPPORT
void VulkanCaptureManager::PostProcess_vkCreateFence(VkResult                     result,
                                                     VkDevice                     device,
                                                     const VkFenceCreateInfo*     pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator,
                                                     VkFence*                     pFence)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    if (result == VK_SUCCESS)
    {
        AddValidFence(*pFence);
    }
}

void VulkanCaptureManager::PostProcess_vkImportFenceWin32HandleKHR(
    VkResult result, VkDevice device, const VkImportFenceWin32HandleInfoKHR* pImportFenceWin32HandleInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    // NOTE: Double check this logic re: imported fences.  pImportFenceWin32HandleInfo->fence should already have been
    // added at CreateFence time, and thus we're adding it again.
    if (result == VK_SUCCESS)
    {
        AddValidFence(pImportFenceWin32HandleInfo->fence);
    }
}

void VulkanCaptureManager::PostProcess_vkImportFenceFdKHR(VkResult                      result,
                                                          VkDevice                      device,
                                                          const VkImportFenceFdInfoKHR* pImportFenceFdInfo)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    // NOTE: Double check this logic re: imported fences.  pImportFenceWin32HandleInfo->fence should already have been
    // added at CreateFence time, and thus we're adding it again.
    if (result == VK_SUCCESS)
    {
        AddValidFence(pImportFenceFdInfo->fence);
    }
}

// Track which fences are valid by seeing which ones are created in the
// threads we're tracking.  Since we disable re-entrant command tracking
// (i.e. OpenXR runtime using Vulkan commands) we may have not see
// fence creation but we still may encounter fences being used that we
// don't know about.  Because of this, we will not record those and we will
// also stop tracking the content of those threads once we've encountered
// this situation.
void VulkanCaptureManager::AddValidFence(VkFence fence)
{
    if (fence != VK_NULL_HANDLE && common_manager_->IsCaptureModeWrite())
    {
        std::lock_guard<std::mutex> lock(fence_mutex);
        valid_fences_.insert(fence);
    }
}

void VulkanCaptureManager::RemoveValidFence(VkFence fence)
{
    if (fence != VK_NULL_HANDLE)
    {
        std::lock_guard<std::mutex> lock(fence_mutex);
        valid_fences_.erase(fence);
    }
}

bool VulkanCaptureManager::IsValidFence(VkFence fence)
{
    if (fence == VK_NULL_HANDLE)
    {
        return true;
    }
    std::lock_guard<std::mutex> lock(fence_mutex);
    return valid_fences_.find(fence) != valid_fences_.end();
}

#endif

void VulkanCaptureManager::PostProcess_vkTransitionImageLayout(VkResult                               result,
                                                               VkDevice                               device,
                                                               uint32_t                               transitionCount,
                                                               const VkHostImageLayoutTransitionInfo* pTransitions)
{
    if (result == VK_SUCCESS)
    {
        if (IsCaptureModeTrack())
        {
            state_tracker_->TrackTransitionImageLayout(transitionCount, pTransitions);
        }
    }
}

void VulkanCaptureManager::CollectSmartTouchedMemoryRanges(
    const vulkan_wrappers::CommandBufferWrapper*           command_wrapper,
    std::unordered_map<format::HandleId, util::RangeList>* touched_ranges) const
{
    if (command_wrapper == nullptr || touched_ranges == nullptr)
    {
        return;
    }

    for (const auto& [asset, ranges] : command_wrapper->referenced_ranges)
    {
        bool is_optimal_image;
        if (asset->type == graphics::ResourceType::kImage)
        {
            const vulkan_wrappers::ImageWrapper* img_resource =
                static_cast<const vulkan_wrappers::ImageWrapper*>(asset);
            is_optimal_image = img_resource->tiling != VK_IMAGE_TILING_LINEAR;
        }
        else
        {
            is_optimal_image = false;
        }

        if (asset != nullptr && (asset->bind_memory_id != format::kNullHandleId) &&
            ((ranges.access_type & vulkan_wrappers::ResourceAccessType::kRead) ==
             vulkan_wrappers::ResourceAccessType::kRead) &&
            !is_optimal_image)
        {
            (*touched_ranges)[asset->bind_memory_id].AddRanges(ranges.range_list, asset->bind_offset);
        }
    }

    for (const vulkan_wrappers::CommandBufferWrapper* secondary : command_wrapper->secondaries)
    {
        CollectSmartTouchedMemoryRanges(secondary, touched_ranges);
    }
}

std::unordered_map<format::HandleId, util::RangeList>
VulkanCaptureManager::GetSmartTouchedMemoryRanges(uint32_t submit_count, const VkSubmitInfo* submits)
{
    std::unordered_map<format::HandleId, util::RangeList> touched_ranges;

    if (submits != nullptr)
    {
        for (uint32_t s = 0; s < submit_count; ++s)
        {
            for (uint32_t c = 0; c < submits[s].commandBufferCount; ++c)
            {
                auto command_wrapper =
                    vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(submits[s].pCommandBuffers[c]);
                CollectSmartTouchedMemoryRanges(command_wrapper, &touched_ranges);
            }
        }
    }

    return touched_ranges;
}

std::unordered_map<format::HandleId, util::RangeList>
VulkanCaptureManager::GetSmartTouchedMemoryRanges(uint32_t submit_count, const VkSubmitInfo2* submits)
{
    std::unordered_map<format::HandleId, util::RangeList> touched_ranges;

    if (submits != nullptr)
    {
        for (uint32_t s = 0; s < submit_count; ++s)
        {
            for (uint32_t c = 0; c < submits[s].commandBufferInfoCount; ++c)
            {
                auto command_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(
                    submits[s].pCommandBufferInfos[c].commandBuffer);
                CollectSmartTouchedMemoryRanges(command_wrapper, &touched_ranges);
            }
        }
    }

    return touched_ranges;
}

bool VulkanCaptureManager::NeedsCommandBufferResourceTracking() const
{
    return (IsCaptureModeTrack() && GetUseAssetFile()) || (GetMemoryTrackingMode() == CaptureSettings::kSmart);
}

void VulkanCaptureManager::TrackUpdateDescriptorSets(uint32_t                    write_count,
                                                     const VkWriteDescriptorSet* writes,
                                                     uint32_t                    copy_count,
                                                     const VkCopyDescriptorSet*  copies)
{
    std::unique_lock<std::mutex> lock(descriptor_mutex_);

    // When processing descriptor updates, we pack the unique handle ID into the stored
    // VkWriteDescriptorSet/VkCopyDescriptorSet handles so that the state writer can determine if the object still
    // exists at state write time by checking for the ID in the active state table.
    if (writes != nullptr)
    {
        for (uint32_t wi = 0; wi < write_count; ++wi)
        {
            const VkWriteDescriptorSet* write = &writes[wi];
            auto* wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(write->dstSet);
            assert(wrapper != nullptr);

            wrapper->dirty = true;

            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings, where the next binding is dstBinding+1 and
            // starting from array element 0.  Track the current count, binding, and array element to handle
            // consecutive updates.
            uint32_t current_count             = write->descriptorCount;
            uint32_t current_binding           = write->dstBinding;
            uint32_t current_dst_array_element = write->dstArrayElement;
            uint32_t current_src_array_element = 0;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                // Update current and write counts for binding's descriptor count. If current count is
                // greater than the count for the descriptor range defined by dstArrayElement through binding count,
                // consecutive bindings are being updated.
                uint32_t current_writes = std::min(current_count, (binding.count - current_dst_array_element));

                bool* written_start = &binding.written[current_dst_array_element];
                std::fill(written_start, written_start + current_writes, true);

                if (binding.type == VK_DESCRIPTOR_TYPE_MUTABLE_VALVE)
                {
                    VkDescriptorType* mutable_type_start = &binding.mutable_type[current_dst_array_element];
                    std::fill(mutable_type_start, mutable_type_start + current_writes, write->descriptorType);
                }

                switch (write->descriptorType)
                {
                    case VK_DESCRIPTOR_TYPE_SAMPLER:
                    {
                        format::HandleId*            dst_sampler_ids = &binding.sampler_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info        = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info        = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_sampler_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::SamplerWrapper* sampler_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            if (sampler_wrapper != nullptr)
                            {
                                wrapper->ReferenceResource(sampler_wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER:
                    {
                        format::HandleId*            dst_sampler_ids = &binding.sampler_ids[current_dst_array_element];
                        format::HandleId*            dst_image_ids   = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info        = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info        = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_sampler_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            dst_image_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            if (image_view_wrapper != nullptr)
                            {
                                wrapper->ReferenceResource(image_view_wrapper);
                            }

                            vulkan_wrappers::SamplerWrapper* sampler_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(src_info[i].sampler);
                            if (sampler_wrapper != nullptr)
                            {
                                wrapper->ReferenceResource(sampler_wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE:
                    case VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT:
                    {
                        format::HandleId*            dst_image_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info      = &binding.images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info      = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_image_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            if (image_view_wrapper != nullptr)
                            {
                                wrapper->ReferenceResource(image_view_wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_STORAGE_IMAGE:
                    {
                        format::HandleId*            dst_image_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorImageInfo*       dst_info      = &binding.storage_images[current_dst_array_element];
                        const VkDescriptorImageInfo* src_info      = &write->pImageInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_image_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(src_info[i].imageView);
                            if (image_view_wrapper != nullptr)
                            {
                                wrapper->ReferenceResource(image_view_wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER:
                    case VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC:
                    {
                        format::HandleId*             dst_buffer_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorBufferInfo*       dst_info       = &binding.buffers[current_dst_array_element];
                        const VkDescriptorBufferInfo* src_info       = &write->pBufferInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_buffer_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::BufferWrapper* buffer_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
                            if (buffer_wrapper != nullptr)
                            {
                                wrapper->ReferenceResource(buffer_wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC:
                    {
                        format::HandleId*             dst_buffer_ids = &binding.handle_ids[current_dst_array_element];
                        VkDescriptorBufferInfo*       dst_info = &binding.storage_buffers[current_dst_array_element];
                        const VkDescriptorBufferInfo* src_info = &write->pBufferInfo[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_buffer_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
                            memcpy(&dst_info[i], &src_info[i], sizeof(dst_info[i]));

                            vulkan_wrappers::BufferWrapper* buffer_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(src_info[i].buffer);
                            if (buffer_wrapper != nullptr)
                            {
                                wrapper->ReferenceResource(buffer_wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER:
                    case VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER:
                    {
                        const bool is_storage = binding.type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER;

                        format::HandleId*   dst_view_ids = &binding.handle_ids[current_dst_array_element];
                        VkBufferView*       dst_info     = is_storage
                                                               ? &binding.storage_texel_buffer_views[current_dst_array_element]
                                                               : &binding.uniform_texel_buffer_views[current_dst_array_element];
                        const VkBufferView* src_info     = &write->pTexelBufferView[current_src_array_element];

                        for (uint32_t i = 0; i < current_writes; ++i)
                        {
                            dst_view_ids[i] =
                                vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferViewWrapper>(src_info[i]);
                            dst_info[i] = src_info[i];

                            vulkan_wrappers::BufferViewWrapper* buffer_view_wrapper =
                                vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(src_info[i]);
                            if (buffer_view_wrapper != nullptr)
                            {
                                wrapper->ReferenceResource(buffer_view_wrapper);
                            }
                        }
                        break;
                    }
                    case VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK:
                    {
                        auto write_inline_uniform_struct =
                            graphics::vulkan_struct_get_pnext<VkWriteDescriptorSetInlineUniformBlock>(write);

                        if (write_inline_uniform_struct != nullptr)
                        {
                            uint8_t*       dst_inline_uniform_data = binding.inline_uniform_block.get();
                            const uint8_t* src_inline_uniform_data =
                                reinterpret_cast<const uint8_t*>(write_inline_uniform_struct->pData);
                            memcpy(dst_inline_uniform_data, src_inline_uniform_data, current_writes);
                        }
                    }
                    break;
                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV:
                    {
                        const VkWriteDescriptorSetAccelerationStructureNV* write_accel_struct =
                            graphics::vulkan_struct_get_pnext<VkWriteDescriptorSetAccelerationStructureNV>(write);

                        if (write_accel_struct != nullptr)
                        {
                            const VkAccelerationStructureNV* src_accel_struct =
                                &write_accel_struct->pAccelerationStructures[current_src_array_element];

                            for (uint32_t i = 0; i < current_writes; ++i)
                            {
                                vulkan_wrappers::AccelerationStructureNVWrapper* accel_struct_wrapper =
                                    vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureNVWrapper>(
                                        src_accel_struct[i]);
                                if (accel_struct_wrapper != nullptr)
                                {
                                    wrapper->ReferenceResource(accel_struct_wrapper);
                                }
                            }
                        }
                    }
                    break;

                    case VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR:
                    {
                        auto write_accel_struct =
                            graphics::vulkan_struct_get_pnext<VkWriteDescriptorSetAccelerationStructureKHR>(write);

                        if (write_accel_struct != nullptr)
                        {
                            format::HandleId* dst_accel_struct_ids = &binding.handle_ids[current_dst_array_element];
                            VkAccelerationStructureKHR* dst_accel_struct =
                                &binding.acceleration_structures[current_dst_array_element];
                            const VkAccelerationStructureKHR* src_accel_struct =
                                &write_accel_struct->pAccelerationStructures[current_src_array_element];

                            for (uint32_t i = 0; i < current_writes; ++i)
                            {
                                dst_accel_struct_ids[i] =
                                    vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                                        src_accel_struct[i]);
                                dst_accel_struct[i] = src_accel_struct[i];

                                vulkan_wrappers::AccelerationStructureKHRWrapper* accel_struct_wrapper =
                                    vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                                        src_accel_struct[i]);
                                if (accel_struct_wrapper != nullptr)
                                {
                                    wrapper->ReferenceResource(accel_struct_wrapper);
                                }
                            }
                        }
                    }
                    break;
                    case VK_DESCRIPTOR_TYPE_TENSOR_ARM:
                    {
                        auto write_tensor = graphics::vulkan_struct_get_pnext<VkWriteDescriptorSetTensorARM>(write);

                        if (write_tensor != nullptr)
                        {
                            format::HandleId*      dst_tensor_view_ids = &binding.handle_ids[current_dst_array_element];
                            VkTensorViewARM*       dst_tensor_views = &binding.tensor_views[current_dst_array_element];
                            const VkTensorViewARM* src_tensor_views =
                                &write_tensor->pTensorViews[current_src_array_element];

                            for (uint32_t i = 0; i < current_writes; ++i)
                            {
                                dst_tensor_view_ids[i] =
                                    vulkan_wrappers::GetWrappedId<vulkan_wrappers::TensorViewARMWrapper>(
                                        src_tensor_views[i]);
                                dst_tensor_views[i] = src_tensor_views[i];

                                if (auto* tensor_view_wrapper =
                                        vulkan_wrappers::GetWrapper<vulkan_wrappers::TensorViewARMWrapper>(
                                            src_tensor_views[i], false))
                                {
                                    wrapper->ReferenceResource(tensor_view_wrapper);
                                }
                            }
                        }
                    }
                    break;
                    default:
                        GFXRECON_LOG_WARNING("Attempting to track descriptor state for unrecognized descriptor type");
                        break;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_dst_array_element = 0;
                    current_src_array_element += current_writes;
                }
            }
        }
    }

    if (copies != nullptr)
    {
        for (uint32_t i = 0; i < copy_count; ++i)
        {
            auto copy        = &copies[i];
            auto dst_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(copy->dstSet);
            auto src_wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(copy->srcSet);
            assert((dst_wrapper != nullptr) && (src_wrapper != nullptr));

            dst_wrapper->dirty = true;

            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to/from consecutive bindings.
            uint32_t current_count             = copy->descriptorCount;
            uint32_t current_dst_binding       = copy->dstBinding;
            uint32_t current_src_binding       = copy->srcBinding;
            uint32_t current_dst_array_element = copy->dstArrayElement;
            uint32_t current_src_array_element = copy->srcArrayElement;

            for (;;)
            {
                auto& dst_binding = dst_wrapper->bindings[current_dst_binding];
                auto& src_binding = src_wrapper->bindings[current_src_binding];

                assert(src_binding.type == dst_binding.type);

                // Check available counts for consecutive updates.
                uint32_t dst_copy_count = dst_binding.count - current_dst_array_element;
                uint32_t src_copy_count = src_binding.count - current_src_array_element;
                uint32_t current_copies = std::min(current_count, std::min(dst_copy_count, src_copy_count));

                bool* written_start = &dst_binding.written[current_dst_array_element];
                std::fill(written_start, written_start + current_copies, true);

                memcpy(&dst_binding.handle_ids[current_dst_array_element],
                       &src_binding.handle_ids[current_src_array_element],
                       (sizeof(format::HandleId) * current_copies));

                if (src_binding.images != nullptr)
                {
                    memcpy(&dst_binding.sampler_ids[current_dst_array_element],
                           &src_binding.sampler_ids[current_src_array_element],
                           (sizeof(format::HandleId) * current_copies));

                    memcpy(&dst_binding.images[current_dst_array_element],
                           &src_binding.images[current_src_array_element],
                           (sizeof(VkDescriptorImageInfo) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                                src_binding.images[current_src_array_element + d].imageView);
                        if (image_view_wrapper != nullptr)
                        {
                            dst_wrapper->ReferenceResource(image_view_wrapper);
                        }

                        vulkan_wrappers::SamplerWrapper* sampler_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::SamplerWrapper>(
                                src_binding.images[current_src_array_element + d].sampler);
                        if (sampler_wrapper != nullptr)
                        {
                            dst_wrapper->ReferenceResource(sampler_wrapper);
                        }
                    }
                }
                if (src_binding.storage_images != nullptr)
                {
                    memcpy(&dst_binding.storage_images[current_dst_array_element],
                           &src_binding.storage_images[current_src_array_element],
                           (sizeof(VkDescriptorImageInfo) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::ImageViewWrapper* image_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::ImageViewWrapper>(
                                src_binding.storage_images[current_src_array_element + d].imageView);
                        if (image_view_wrapper != nullptr)
                        {
                            dst_wrapper->ReferenceResource(image_view_wrapper);
                        }
                    }
                }
                if (src_binding.buffers != nullptr)
                {
                    memcpy(&dst_binding.buffers[current_dst_array_element],
                           &src_binding.buffers[current_src_array_element],
                           (sizeof(VkDescriptorBufferInfo) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::BufferWrapper* buffer_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                                src_binding.buffers[current_src_array_element + d].buffer);
                        if (buffer_wrapper != nullptr)
                        {
                            dst_wrapper->ReferenceResource(buffer_wrapper);
                        }
                    }
                }
                if (src_binding.storage_buffers != nullptr)
                {
                    memcpy(&dst_binding.storage_buffers[current_dst_array_element],
                           &src_binding.storage_buffers[current_src_array_element],
                           (sizeof(VkDescriptorBufferInfo) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::BufferWrapper* buffer_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferWrapper>(
                                src_binding.storage_buffers[current_src_array_element + d].buffer);
                        if (buffer_wrapper != nullptr)
                        {
                            dst_wrapper->ReferenceResource(buffer_wrapper);
                        }
                    }
                }
                if (src_binding.acceleration_structures != nullptr)
                {
                    memcpy(&dst_binding.acceleration_structures[current_dst_array_element],
                           &src_binding.acceleration_structures[current_src_array_element],
                           (sizeof(VkWriteDescriptorSetAccelerationStructureKHR) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::AccelerationStructureKHRWrapper* accel_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::AccelerationStructureKHRWrapper>(
                                src_binding.acceleration_structures[current_src_array_element + d]);
                        if (accel_wrapper != nullptr)
                        {
                            dst_wrapper->ReferenceResource(accel_wrapper);
                        }
                    }
                }
                if (src_binding.inline_uniform_block != nullptr)
                {
                    memcpy(&dst_binding.inline_uniform_block[current_dst_array_element],
                           &src_binding.inline_uniform_block[current_src_array_element],
                           current_copies);
                }
                if (src_binding.uniform_texel_buffer_views != nullptr)
                {
                    memcpy(&dst_binding.uniform_texel_buffer_views[current_dst_array_element],
                           &src_binding.uniform_texel_buffer_views[current_src_array_element],
                           (sizeof(VkBufferView) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::BufferViewWrapper* buffer_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                                src_binding.uniform_texel_buffer_views[current_src_array_element + d]);
                        if (buffer_view_wrapper != nullptr)
                        {
                            dst_wrapper->ReferenceResource(buffer_view_wrapper);
                        }
                    }
                }
                if (src_binding.storage_texel_buffer_views != nullptr)
                {
                    memcpy(&dst_binding.storage_texel_buffer_views[current_dst_array_element],
                           &src_binding.storage_texel_buffer_views[current_src_array_element],
                           (sizeof(VkBufferView) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::BufferViewWrapper* buffer_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::BufferViewWrapper>(
                                src_binding.storage_texel_buffer_views[current_src_array_element + d]);
                        if (buffer_view_wrapper != nullptr)
                        {
                            dst_wrapper->ReferenceResource(buffer_view_wrapper);
                        }
                    }
                }

                if (src_binding.tensor_views != nullptr)
                {
                    memcpy(&dst_binding.tensor_views[current_dst_array_element],
                           &src_binding.tensor_views[current_src_array_element],
                           (sizeof(VkTensorViewARM) * current_copies));

                    for (uint32_t d = 0; d < current_copies; ++d)
                    {
                        vulkan_wrappers::TensorViewARMWrapper* tensor_view_wrapper =
                            vulkan_wrappers::GetWrapper<vulkan_wrappers::TensorViewARMWrapper>(
                                src_binding.tensor_views[current_src_array_element + d]);
                        if (tensor_view_wrapper != nullptr)
                        {
                            dst_wrapper->ReferenceResource(tensor_view_wrapper);
                        }
                    }
                }

                if (src_binding.mutable_type != nullptr)
                {
                    memcpy(&dst_binding.mutable_type[current_dst_array_element],
                           &src_binding.mutable_type[current_src_array_element],
                           (sizeof(VkDescriptorType) * current_copies));
                }

                // Check for consecutive update.
                if (current_count == current_copies)
                {
                    break;
                }
                else
                {
                    current_count -= current_copies;

                    if (dst_copy_count == src_copy_count)
                    {
                        // Both bindings must increment.
                        current_dst_binding += 1;
                        current_src_binding += 1;
                        current_dst_array_element = 0;
                        current_src_array_element = 0;
                    }
                    else if (dst_copy_count < src_copy_count)
                    {
                        // Only the destination binding must increment.
                        current_dst_binding += 1;
                        current_dst_array_element = 0;
                        current_src_array_element += current_copies;
                    }
                    else
                    {
                        // Only the source binding must increment.
                        current_src_binding += 1;
                        current_src_array_element = 0;
                        current_dst_array_element += current_copies;
                    }
                }
            }
        }
    }
}

void VulkanCaptureManager::TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet           set,
                                                                const UpdateTemplateInfo* template_info,
                                                                const void*               data)
{
    assert(set != VK_NULL_HANDLE);

    std::unique_lock<std::mutex> lock(descriptor_mutex_);
    // When processing descriptor updates, we pack the unique handle ID into the stored
    // VkWriteDescriptorSet/VkCopyDescriptorSet handles so that the state writer can determine if the object still
    // exists at state write time by checking for the ID in the active state table.
    if ((template_info != nullptr) && (data != nullptr))
    {
        auto           wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::DescriptorSetWrapper>(set);
        const uint8_t* bytes   = reinterpret_cast<const uint8_t*>(data);

        wrapper->dirty = true;

        for (const auto& entry : template_info->image_info)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                if (binding.type != entry.type)
                {
                    GFXRECON_LOG_WARNING("%s() Descriptors mismatch: %u != %u", __func__, binding.type, entry.type);
                }
                const bool immutable_image = binding.type == VK_DESCRIPTOR_TYPE_SAMPLER ||
                                             binding.type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER ||
                                             binding.type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE ||
                                             binding.type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT;

                assert((immutable_image && binding.images != nullptr) ||
                       (!immutable_image && binding.storage_images != nullptr));

                format::HandleId* dst_sampler_ids = nullptr;
                if (binding.type == VK_DESCRIPTOR_TYPE_SAMPLER ||
                    binding.type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER)
                {
                    GFXRECON_ASSERT(binding.sampler_ids != nullptr);
                    dst_sampler_ids = &binding.sampler_ids[current_array_element];
                }
                format::HandleId*      dst_image_ids = &binding.handle_ids[current_array_element];
                VkDescriptorImageInfo* dst_info      = immutable_image ? &binding.images[current_array_element]
                                                                       : &binding.storage_images[current_array_element];
                const uint8_t*         src_address   = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto image_info = reinterpret_cast<const VkDescriptorImageInfo*>(src_address);
                    if ((binding.type == VK_DESCRIPTOR_TYPE_SAMPLER) ||
                        (binding.type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER))
                    {
                        dst_sampler_ids[i] =
                            vulkan_wrappers::GetWrappedId<vulkan_wrappers::SamplerWrapper>(image_info->sampler);
                    }

                    if (binding.type != VK_DESCRIPTOR_TYPE_SAMPLER)
                    {
                        dst_image_ids[i] =
                            vulkan_wrappers::GetWrappedId<vulkan_wrappers::ImageViewWrapper>(image_info->imageView);
                    }

                    memcpy(&dst_info[i], image_info, sizeof(dst_info[i]));

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }

        for (const auto& entry : template_info->buffer_info)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                if (binding.type != entry.type)
                {
                    GFXRECON_LOG_WARNING("%s() Descriptors mismatch: %u != %u", __func__, binding.type, entry.type);
                }
                const bool immutable_buffer = binding.type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC ||
                                              binding.type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;

                if (immutable_buffer)
                {
                    GFXRECON_ASSERT(binding.buffers != nullptr);
                }
                else
                {
                    GFXRECON_ASSERT(binding.type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC ||
                                    binding.type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER);
                    GFXRECON_ASSERT(binding.storage_buffers != nullptr);
                }

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId*       dst_buffer_ids = &binding.handle_ids[current_array_element];
                VkDescriptorBufferInfo* dst_info       = immutable_buffer ? &binding.buffers[current_array_element]
                                                                          : &binding.storage_buffers[current_array_element];
                const uint8_t*          src_address    = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto buffer_info = reinterpret_cast<const VkDescriptorBufferInfo*>(src_address);
                    dst_buffer_ids[i] =
                        vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferWrapper>(buffer_info->buffer);
                    memcpy(&dst_info[i], buffer_info, sizeof(dst_info[i]));

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }

        for (const auto& entry : template_info->texel_buffer_view)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                if (binding.type != entry.type)
                {
                    GFXRECON_LOG_WARNING("%s() Descriptors mismatch: %u != %u", __func__, binding.type, entry.type);
                }
                const bool immutable_buffer = binding.type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER;

                GFXRECON_ASSERT(immutable_buffer ? binding.uniform_texel_buffer_views != nullptr
                                                 : binding.storage_texel_buffer_views != nullptr);

                format::HandleId* dst_view_ids = &binding.handle_ids[current_array_element];
                VkBufferView*  dst_info = immutable_buffer ? &binding.uniform_texel_buffer_views[current_array_element]
                                                           : &binding.storage_texel_buffer_views[current_array_element];
                const uint8_t* src_address = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    auto buffer_view = reinterpret_cast<const VkBufferView*>(src_address);
                    dst_view_ids[i]  = vulkan_wrappers::GetWrappedId<vulkan_wrappers::BufferViewWrapper>(*buffer_view);
                    dst_info[i]      = *buffer_view;

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }

        for (const auto& entry : template_info->acceleration_structure_khr)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[current_binding];

                assert(binding.acceleration_structures != nullptr);

                // Check count for consecutive updates.
                uint32_t current_writes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_writes, true);

                format::HandleId*           dst_view_ids = &binding.handle_ids[current_array_element];
                VkAccelerationStructureKHR* dst_info     = &binding.acceleration_structures[current_array_element];
                const uint8_t*              src_address  = bytes + current_offset;

                for (uint32_t i = 0; i < current_writes; ++i)
                {
                    const auto* accel_struct = reinterpret_cast<const VkAccelerationStructureKHR*>(src_address);
                    dst_view_ids[i] =
                        vulkan_wrappers::GetWrappedId<vulkan_wrappers::AccelerationStructureKHRWrapper>(*accel_struct);
                    dst_info[i] = *accel_struct;

                    src_address += entry.stride;
                }

                // Check for consecutive update.
                if (current_count == current_writes)
                {
                    break;
                }
                else
                {
                    current_count -= current_writes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_writes * entry.stride);
                }
            }
        }
        for (const auto& entry : template_info->inline_uniform_block)
        {
            // Descriptor update rules specify that a write descriptorCount that is greater than the binding's count
            // will result in updates to consecutive bindings.
            uint32_t current_count         = entry.count;
            uint32_t current_binding       = entry.binding;
            uint32_t current_array_element = entry.array_element;
            size_t   current_offset        = entry.offset;

            for (;;)
            {
                auto& binding = wrapper->bindings[entry.binding];
                GFXRECON_ASSERT(binding.inline_uniform_block != nullptr);

                // Check count for consecutive updates.
                const uint32_t current_num_bytes = std::min(current_count, (binding.count - current_array_element));

                bool* written_start = &binding.written[current_array_element];
                std::fill(written_start, written_start + current_num_bytes, true);

                const uint8_t* src_address = bytes + current_offset;
                uint8_t*       dst_address = binding.inline_uniform_block.get() + entry.array_element;
                memcpy(dst_address, src_address, current_num_bytes);

                // Check for consecutive update.
                if (current_count == current_num_bytes)
                {
                    break;
                }
                else
                {
                    current_count -= current_num_bytes;
                    current_binding += 1;
                    current_array_element = 0;
                    current_offset += (current_num_bytes * entry.stride);
                }
            }
        }
    }
}

void VulkanCaptureManager::TrackBeginRenderPass(VkCommandBuffer command_buffer, const VkRenderPassBeginInfo* begin_info)
{
    assert((command_buffer != VK_NULL_HANDLE) && (begin_info != nullptr));

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    wrapper->active_render_pass =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::RenderPassWrapper>(begin_info->renderPass);
    wrapper->render_pass_framebuffer =
        vulkan_wrappers::GetWrapper<vulkan_wrappers::FramebufferWrapper>(begin_info->framebuffer);
}

void VulkanCaptureManager::TrackEndRenderPass(VkCommandBuffer command_buffer)
{
    assert(command_buffer != VK_NULL_HANDLE);

    auto wrapper = vulkan_wrappers::GetWrapper<vulkan_wrappers::CommandBufferWrapper>(command_buffer);
    assert((wrapper->active_render_pass != VK_NULL_HANDLE) && (wrapper->render_pass_framebuffer != VK_NULL_HANDLE));

    auto render_pass_wrapper = wrapper->active_render_pass;
    auto framebuffer_wrapper = wrapper->render_pass_framebuffer;
    assert((framebuffer_wrapper != nullptr) && (render_pass_wrapper != nullptr));

    uint32_t attachment_count = static_cast<uint32_t>(framebuffer_wrapper->attachments.size());
    assert(attachment_count <= render_pass_wrapper->attachment_info.attachment_final_layouts.size());

    for (uint32_t i = 0; i < attachment_count; ++i)
    {
        wrapper->pending_layouts[framebuffer_wrapper->attachments[i]] =
            render_pass_wrapper->attachment_info.attachment_final_layouts[i];
    }

    // Clear the active render pass state now that the pass has ended.
    wrapper->active_render_pass      = nullptr;
    wrapper->render_pass_framebuffer = nullptr;
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
