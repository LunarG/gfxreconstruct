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

#include "vulkan_referenced_block_consumer_base.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

VulkanReferencedBlockConsumerBase::VulkanReferencedBlockConsumerBase(
    const std::unordered_set<format::HandleId>& unreferenced_ids) :
    unreferenced_ids_(std::move(unreferenced_ids))
{}

void VulkanReferencedBlockConsumerBase::Process_vkCreateGraphicsPipelines(const ApiCallInfo&             call_info,
                                                                          args::CreateGraphicsPipelines& args)
{
    if (check_handle_ids_unused(args.pPipelines.GetPointer(), args.createInfoCount))
    {
        set_block_index_unused(call_info.index);
    }
}

void VulkanReferencedBlockConsumerBase::Process_vkCreateComputePipelines(const ApiCallInfo&            call_info,
                                                                         args::CreateComputePipelines& args)
{
    if (check_handle_ids_unused(args.pPipelines.GetPointer(), args.createInfoCount))
    {
        set_block_index_unused(call_info.index);
    }
}

void VulkanReferencedBlockConsumerBase::Process_vkCreateRayTracingPipelinesKHR(const ApiCallInfo& call_info,
                                                                               args::CreateRayTracingPipelinesKHR& args)
{
    if (check_handle_ids_unused(args.pPipelines.GetPointer(), args.createInfoCount))
    {
        set_block_index_unused(call_info.index);
    }
}

void VulkanReferencedBlockConsumerBase::Process_vkDestroyPipeline(const ApiCallInfo&     call_info,
                                                                  args::DestroyPipeline& args)
{
    if (check_handle_id_unused(args.pipeline))
    {
        set_block_index_unused(call_info.index);
    }
}

void VulkanReferencedBlockConsumerBase::Process_vkGetRayTracingShaderGroupHandlesKHR(
    const ApiCallInfo& call_info, args::GetRayTracingShaderGroupHandlesKHR& args)
{
    if (check_handle_id_unused(args.pipeline))
    {
        set_block_index_unused(call_info.index);
    }
}

void VulkanReferencedBlockConsumerBase::Process_vkSetDebugUtilsObjectNameEXT(const ApiCallInfo& call_info,
                                                                             args::SetDebugUtilsObjectNameEXT& args)
{
    if (check_handle_id_unused(args.pNameInfo.GetMetaStructPointer()->objectHandle))
    {
        set_block_index_unused(call_info.index);
    }
}

void VulkanReferencedBlockConsumerBase::Process_vkSetDebugUtilsObjectTagEXT(const ApiCallInfo&               call_info,
                                                                            args::SetDebugUtilsObjectTagEXT& args)
{
    if (check_handle_id_unused(args.pTagInfo.GetMetaStructPointer()->objectHandle))
    {
        set_block_index_unused(call_info.index);
    }
}

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)