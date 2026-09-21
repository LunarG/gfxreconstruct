/*
** Copyright (c) 2026 LunarG, Inc.
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

#include "vulkan_aliasing_group_modifier.h"

#include "graphics/vulkan_struct_get_pnext.h"
#include "util/logging.h"
#include "util/memory_output_stream.h"

#include <algorithm>
#include <utility>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)

namespace
{

// Re-encoding a decoded create-info drops handles inside its pNext chain, because the decoder leaves
// the handle fields null and the encoder writes a null handle id for them.
// Of everything that can extend the three create-infos, this is the only structure that carries a handle
// -- derived by intersecting the registry's structextends lists with the generated meta-structs that hold one.
// A header update can add to that set, so re-derive it when a new extension lands.
bool PNextCarriesAHandle(const VkImageCreateInfo* create_info)
{
    return graphics::vulkan_struct_get_pnext<VkImageSwapchainCreateInfoKHR>(create_info) != nullptr;
}

} // namespace

void VulkanAliasingGroupModifier::RecordCreate(format::HandleId                     device_id,
                                               format::HandleId                     resource_id,
                                               encode::ResourceAliasingCreateInfo&& create_info,
                                               uint64_t                             create_size)
{
    TrackedResource resource;
    resource.device_id   = device_id;
    resource.create_info = std::move(create_info);
    resource.create_size = create_size;

    resources_[resource_id] = std::move(resource);
}

void VulkanAliasingGroupModifier::RecordDestroy(format::HandleId resource_id, uint64_t block_index)
{
    if (auto entry = resources_.find(resource_id); entry != resources_.end())
    {
        entry->second.destroy_index = block_index;
    }
}

void VulkanAliasingGroupModifier::RecordRequirementSize(format::HandleId resource_id, uint64_t size)
{
    if (auto entry = resources_.find(resource_id); entry != resources_.end())
    {
        entry->second.requirement_size = size;
    }
}

void VulkanAliasingGroupModifier::RecordBind(format::HandleId resource_id,
                                             format::HandleId memory_id,
                                             uint64_t         offset,
                                             uint64_t         block_index)
{
    const auto entry = resources_.find(resource_id);
    if (entry == resources_.end())
    {
        return;
    }

    if (entry->second.bound)
    {
        // A resource is bound once, so a second bind is something this pass does not model.
        GFXRECON_LOG_WARNING("Resource aliasing detection: resource %" PRIu64 " is bound more than once, leaving it "
                             "to the replayer.",
                             resource_id);
        entry->second.excluded = true;
        return;
    }

    entry->second.memory_id   = memory_id;
    entry->second.bind_offset = offset;
    entry->second.bind_index  = block_index;
    entry->second.bound       = true;
}

void VulkanAliasingGroupModifier::ExcludeMemory(format::HandleId memory_id)
{
    excluded_memories_.insert(memory_id);
}

void VulkanAliasingGroupModifier::Process_vkCreateBuffer(const decode::ApiCallInfo&  call_info,
                                                         decode::args::CreateBuffer& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    const VkBufferCreateInfo* create_info = args.pCreateInfo.GetPointer();
    if ((create_info == nullptr) || args.pBuffer.IsNull())
    {
        return;
    }

    RecordCreate(args.device,
                 *args.pBuffer.GetPointer(),
                 encode::EncodeResourceAliasingCreateInfo(*create_info),
                 create_info->size);
}

void VulkanAliasingGroupModifier::Process_vkCreateImage(const decode::ApiCallInfo& call_info,
                                                        decode::args::CreateImage& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    const VkImageCreateInfo* create_info = args.pCreateInfo.GetPointer();
    if ((create_info == nullptr) || args.pImage.IsNull())
    {
        return;
    }

    const format::HandleId image_id = *args.pImage.GetPointer();

    if (PNextCarriesAHandle(create_info))
    {
        GFXRECON_LOG_WARNING("Resource aliasing detection: the create-info of image %" PRIu64 " carries a handle in "
                             "its pNext chain, which does not survive re-encoding, so it is left to the replayer.",
                             image_id);
        return;
    }

    // An image extent in memory is not its create-info; without a requirement query there is nothing
    // to use, so create_size stays unknown.
    RecordCreate(args.device, image_id, encode::EncodeResourceAliasingCreateInfo(*create_info), 0);
}

void VulkanAliasingGroupModifier::Process_vkCreateTensorARM(const decode::ApiCallInfo&     call_info,
                                                            decode::args::CreateTensorARM& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    const VkTensorCreateInfoARM* create_info = args.pCreateInfo.GetPointer();
    if ((create_info == nullptr) || args.pTensor.IsNull())
    {
        return;
    }

    RecordCreate(args.device, *args.pTensor.GetPointer(), encode::EncodeResourceAliasingCreateInfo(*create_info), 0);
}

void VulkanAliasingGroupModifier::Process_vkDestroyBuffer(const decode::ApiCallInfo&   call_info,
                                                          decode::args::DestroyBuffer& args)
{
    RecordDestroy(args.buffer, call_info.index);
}

void VulkanAliasingGroupModifier::Process_vkDestroyImage(const decode::ApiCallInfo&  call_info,
                                                         decode::args::DestroyImage& args)
{
    RecordDestroy(args.image, call_info.index);
}

void VulkanAliasingGroupModifier::Process_vkDestroyTensorARM(const decode::ApiCallInfo&      call_info,
                                                             decode::args::DestroyTensorARM& args)
{
    RecordDestroy(args.tensor, call_info.index);
}

void VulkanAliasingGroupModifier::Process_vkGetBufferMemoryRequirements(const decode::ApiCallInfo& call_info,
                                                                        decode::args::GetBufferMemoryRequirements& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (const VkMemoryRequirements* requirements = args.pMemoryRequirements.GetPointer(); requirements != nullptr)
    {
        RecordRequirementSize(args.buffer, requirements->size);
    }
}

template <typename Args>
void VulkanAliasingGroupModifier::RecordBufferRequirements2(Args& args)
{
    const decode::Decoded_VkBufferMemoryRequirementsInfo2* info = args.pInfo.GetMetaStructPointer();
    if (const VkMemoryRequirements2* requirements = args.pMemoryRequirements.GetPointer();
        info != nullptr && requirements != nullptr)
    {
        RecordRequirementSize(info->buffer, requirements->memoryRequirements.size);
    }
}

void VulkanAliasingGroupModifier::Process_vkGetBufferMemoryRequirements2(
    const decode::ApiCallInfo& call_info, decode::args::GetBufferMemoryRequirements2& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    RecordBufferRequirements2(args);
}

void VulkanAliasingGroupModifier::Process_vkGetBufferMemoryRequirements2KHR(
    const decode::ApiCallInfo& call_info, decode::args::GetBufferMemoryRequirements2KHR& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    RecordBufferRequirements2(args);
}

void VulkanAliasingGroupModifier::Process_vkGetImageMemoryRequirements(const decode::ApiCallInfo& call_info,
                                                                       decode::args::GetImageMemoryRequirements& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    if (const VkMemoryRequirements* requirements = args.pMemoryRequirements.GetPointer(); requirements != nullptr)
    {
        RecordRequirementSize(args.image, requirements->size);
    }
}

template <typename Args>
void VulkanAliasingGroupModifier::RecordImageRequirements2(Args& args)
{
    const decode::Decoded_VkImageMemoryRequirementsInfo2* info = args.pInfo.GetMetaStructPointer();
    if (const VkMemoryRequirements2* requirements = args.pMemoryRequirements.GetPointer();
        info != nullptr && requirements != nullptr)
    {
        RecordRequirementSize(info->image, requirements->memoryRequirements.size);
    }
}

void VulkanAliasingGroupModifier::Process_vkGetImageMemoryRequirements2(const decode::ApiCallInfo& call_info,
                                                                        decode::args::GetImageMemoryRequirements2& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    RecordImageRequirements2(args);
}

void VulkanAliasingGroupModifier::Process_vkGetImageMemoryRequirements2KHR(
    const decode::ApiCallInfo& call_info, decode::args::GetImageMemoryRequirements2KHR& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);
    RecordImageRequirements2(args);
}

void VulkanAliasingGroupModifier::Process_vkGetTensorMemoryRequirementsARM(
    const decode::ApiCallInfo& call_info, decode::args::GetTensorMemoryRequirementsARM& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    const decode::Decoded_VkTensorMemoryRequirementsInfoARM* info = args.pInfo.GetMetaStructPointer();
    if (const VkMemoryRequirements2* requirements = args.pMemoryRequirements.GetPointer();
        info != nullptr && requirements != nullptr)
    {
        RecordRequirementSize(info->tensor, requirements->memoryRequirements.size);
    }
}

void VulkanAliasingGroupModifier::Process_vkBindBufferMemory(const decode::ApiCallInfo&      call_info,
                                                             decode::args::BindBufferMemory& args)
{
    RecordBind(args.buffer, args.memory, args.memoryOffset, call_info.index);
}

template <typename Args>
void VulkanAliasingGroupModifier::RecordBufferBinds2(Args& args, const uint64_t block_index)
{
    const decode::Decoded_VkBindBufferMemoryInfo* bind_infos = args.pBindInfos.GetMetaStructPointer();
    for (size_t i = 0; bind_infos != nullptr && i < args.pBindInfos.GetLength(); ++i)
    {
        RecordBind(bind_infos[i].buffer, bind_infos[i].memory, bind_infos[i].decoded_value->memoryOffset, block_index);
    }
}

void VulkanAliasingGroupModifier::Process_vkBindBufferMemory2(const decode::ApiCallInfo&       call_info,
                                                              decode::args::BindBufferMemory2& args)
{
    RecordBufferBinds2(args, call_info.index);
}

void VulkanAliasingGroupModifier::Process_vkBindBufferMemory2KHR(const decode::ApiCallInfo&          call_info,
                                                                 decode::args::BindBufferMemory2KHR& args)
{
    RecordBufferBinds2(args, call_info.index);
}

void VulkanAliasingGroupModifier::Process_vkBindImageMemory(const decode::ApiCallInfo&     call_info,
                                                            decode::args::BindImageMemory& args)
{
    RecordBind(args.image, args.memory, args.memoryOffset, call_info.index);
}

template <typename Args>
void VulkanAliasingGroupModifier::RecordImageBinds2(Args& args, const uint64_t block_index)
{
    const decode::Decoded_VkBindImageMemoryInfo* bind_infos = args.pBindInfos.GetMetaStructPointer();
    for (size_t i = 0; bind_infos != nullptr && i < args.pBindInfos.GetLength(); ++i)
    {
        RecordBind(bind_infos[i].image, bind_infos[i].memory, bind_infos[i].decoded_value->memoryOffset, block_index);
    }
}

void VulkanAliasingGroupModifier::Process_vkBindImageMemory2(const decode::ApiCallInfo&      call_info,
                                                             decode::args::BindImageMemory2& args)
{
    RecordImageBinds2(args, call_info.index);
}

void VulkanAliasingGroupModifier::Process_vkBindImageMemory2KHR(const decode::ApiCallInfo&         call_info,
                                                                decode::args::BindImageMemory2KHR& args)
{
    RecordImageBinds2(args, call_info.index);
}

void VulkanAliasingGroupModifier::Process_vkBindTensorMemoryARM(const decode::ApiCallInfo&         call_info,
                                                                decode::args::BindTensorMemoryARM& args)
{
    const decode::Decoded_VkBindTensorMemoryInfoARM* bind_infos = args.pBindInfos.GetMetaStructPointer();
    for (size_t i = 0; bind_infos != nullptr && i < args.pBindInfos.GetLength(); ++i)
    {
        RecordBind(
            bind_infos[i].tensor, bind_infos[i].memory, bind_infos[i].decoded_value->memoryOffset, call_info.index);
    }
}

void VulkanAliasingGroupModifier::Process_vkQueueBindSparse(const decode::ApiCallInfo&     call_info,
                                                            decode::args::QueueBindSparse& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    const decode::Decoded_VkBindSparseInfo* bind_infos = args.pBindInfo.GetMetaStructPointer();
    if (bind_infos == nullptr)
    {
        return;
    }

    for (size_t i = 0; i < args.pBindInfo.GetLength(); ++i)
    {
        const decode::Decoded_VkBindSparseInfo& bind_info = bind_infos[i];

        if (bind_info.pBufferBinds != nullptr)
        {
            const decode::Decoded_VkSparseBufferMemoryBindInfo* binds = bind_info.pBufferBinds->GetMetaStructPointer();
            for (size_t j = 0; binds != nullptr && j < bind_info.pBufferBinds->GetLength(); ++j)
            {
                const decode::Decoded_VkSparseMemoryBind* memory_binds = binds[j].pBinds->GetMetaStructPointer();
                for (size_t k = 0; memory_binds != nullptr && k < binds[j].pBinds->GetLength(); ++k)
                {
                    ExcludeMemory(memory_binds[k].memory);
                }
            }
        }

        if (bind_info.pImageOpaqueBinds != nullptr)
        {
            const decode::Decoded_VkSparseImageOpaqueMemoryBindInfo* binds =
                bind_info.pImageOpaqueBinds->GetMetaStructPointer();
            for (size_t j = 0; binds != nullptr && j < bind_info.pImageOpaqueBinds->GetLength(); ++j)
            {
                const decode::Decoded_VkSparseMemoryBind* memory_binds = binds[j].pBinds->GetMetaStructPointer();
                for (size_t k = 0; (memory_binds != nullptr) && (k < binds[j].pBinds->GetLength()); ++k)
                {
                    ExcludeMemory(memory_binds[k].memory);
                }
            }
        }

        if (bind_info.pImageBinds != nullptr)
        {
            const decode::Decoded_VkSparseImageMemoryBindInfo* binds = bind_info.pImageBinds->GetMetaStructPointer();
            for (size_t j = 0; binds != nullptr && j < bind_info.pImageBinds->GetLength(); ++j)
            {
                const decode::Decoded_VkSparseImageMemoryBind* memory_binds = binds[j].pBinds->GetMetaStructPointer();
                for (size_t k = 0; memory_binds != nullptr && k < binds[j].pBinds->GetLength(); ++k)
                {
                    ExcludeMemory(memory_binds[k].memory);
                }
            }
        }
    }
}

void VulkanAliasingGroupModifier::Process_vkBindVideoSessionMemoryKHR(const decode::ApiCallInfo& call_info,
                                                                      decode::args::BindVideoSessionMemoryKHR& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    const decode::Decoded_VkBindVideoSessionMemoryInfoKHR* bind_infos =
        args.pBindSessionMemoryInfos.GetMetaStructPointer();
    for (size_t i = 0; bind_infos != nullptr && i < args.pBindSessionMemoryInfos.GetLength(); ++i)
    {
        ExcludeMemory(bind_infos[i].memory);
    }
}

void VulkanAliasingGroupModifier::Process_vkBindAccelerationStructureMemoryNV(
    const decode::ApiCallInfo& call_info, decode::args::BindAccelerationStructureMemoryNV& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    const decode::Decoded_VkBindAccelerationStructureMemoryInfoNV* bind_infos = args.pBindInfos.GetMetaStructPointer();
    for (size_t i = 0; bind_infos != nullptr && i < args.pBindInfos.GetLength(); ++i)
    {
        ExcludeMemory(bind_infos[i].memory);
    }
}

void VulkanAliasingGroupModifier::Process_vkBindDataGraphPipelineSessionMemoryARM(
    const decode::ApiCallInfo& call_info, decode::args::BindDataGraphPipelineSessionMemoryARM& args)
{
    GFXRECON_UNREFERENCED_PARAMETER(call_info);

    const decode::Decoded_VkBindDataGraphPipelineSessionMemoryInfoARM* bind_infos =
        args.pBindInfos.GetMetaStructPointer();
    for (size_t i = 0; bind_infos != nullptr && i < args.pBindInfos.GetLength(); ++i)
    {
        ExcludeMemory(bind_infos[i].memory);
    }
}

bool VulkanAliasingGroupModifier::CanOptimize()
{
    // Grouping runs per device, because a group is only useful to a consumer that can query the
    // replay requirements of its members on the device they belong to.
    std::map<format::HandleId, std::vector<AliasingCandidate>> candidates_by_device;

    for (const auto& [resource_id, resource] : resources_)
    {
        if (resource.bound && !resource.excluded && !excluded_memories_.contains(resource.memory_id))
        {
            AliasingCandidate candidate;
            candidate.resource_id = resource_id;
            candidate.memory_id   = resource.memory_id;
            candidate.bind_offset = resource.bind_offset;

            // Same rule the replayer uses (e.g. page-guard tracking rounds recorded requirement to page
            candidate.footprint     = resource.requirement_size != 0 && resource.create_size != 0
                                          ? std::min(resource.requirement_size, resource.create_size)
                                          : std::max(resource.requirement_size, resource.create_size);
            candidate.bind_index    = resource.bind_index;
            candidate.destroy_index = resource.destroy_index;
            candidates_by_device[resource.device_id].push_back(candidate);
        }
    }

    size_t total_groups  = 0;
    size_t total_members = 0;

    for (const auto& [device_id, candidates] : candidates_by_device)
    {
        std::vector<encode::ResourceAliasingGroupInfo> device_groups;

        for (const auto& [memory_id, group_id, members] : ComputeAliasingGroups(candidates))
        {
            encode::ResourceAliasingGroupInfo group_info;
            group_info.memory_id = memory_id;
            group_info.group_id  = group_id;

            for (const size_t index : members)
            {
                encode::ResourceAliasingMemberInfo member;
                member.resource_id = candidates[index].resource_id;
                member.bind_offset = candidates[index].bind_offset;
                member.create_info = resources_.at(member.resource_id).create_info;
                group_info.members.push_back(std::move(member));
            }

            ++total_groups;
            total_members += group_info.members.size();
            device_groups.push_back(std::move(group_info));
        }

        if (!device_groups.empty())
        {
            groups_by_device_[device_id] = std::move(device_groups);
        }
    }

    if (groups_by_device_.empty())
    {
        return false;
    }

    GFXRECON_LOG_INFO("Resource aliasing detection: %zu group(s) with %zu member(s) across %zu device(s).",
                      total_groups,
                      total_members,
                      groups_by_device_.size());
    return true;
}

void VulkanAliasingGroupModifier::Process_vkCreateDevice(const decode::ApiCallInfo&  call_info,
                                                         decode::args::CreateDevice& args)
{
    if (!IsModificationPass() || args.pDevice.IsNull())
    {
        return;
    }

    const format::HandleId device_id = *args.pDevice.GetPointer();

    const auto entry = groups_by_device_.find(device_id);
    if (entry == groups_by_device_.end() || emitted_devices_.contains(device_id))
    {
        return;
    }
    emitted_devices_.insert(device_id);

    util::MemoryOutputStream block;
    encode::WriteResourceAliasingGroupsCommand(&block, call_info.thread_id, device_id, entry->second);

    GFXRECON_LOG_INFO(
        "Resource aliasing detection: writing %zu group(s) for device %" PRIu64 ".", entry->second.size(), device_id);
    CurrentBlockEdit().AddMetaCommand(BlockEdit::Position::kAfter, block);
}

GFXRECON_END_NAMESPACE(gfxrecon)
