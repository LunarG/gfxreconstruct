/*
** Copyright (c) 2019 LunarG, Inc.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#ifndef GFXRECON_ENCODE_VULKAN_STATE_TRACKER_INITIALIZERS_H
#define GFXRECON_ENCODE_VULKAN_STATE_TRACKER_INITIALIZERS_H

#include "encode/vulkan_handle_wrappers.h"
#include "encode/vulkan_state_table.h"
#include "format/format.h"
#include "format/format_util.h"
#include "util/defines.h"
#include "util/memory_output_stream.h"

#include "vulkan/vulkan.h"

#include <cassert>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)
GFXRECON_BEGIN_NAMESPACE(vulkan_state_tracker)

// Functions to initialize the object creation data stored by Vulkan handle wrappers. Explicit specialization is used to
// support special cases that require tracking the creation parameters of the wrapped handle and other handles that
// creation depend on (eg. graphics pipeline creation depends on a VkShaderModule, VkPipelineLayout, and VkRenderPass
// handles). These functions are only intended to be used by the VulkanStateTracker class, but must be in namespace
// scope to meet C++ language requirements for explicit template specialization.

template <typename Wrapper, typename CreateInfo>
void InitializeState(Wrapper*                wrapper,
                     const CreateInfo*       create_info,
                     format::ApiCallId       create_call_id,
                     CreateParameters        create_parameters,
                     VulkanStateTable*       state_table)
{
    assert(wrapper != nullptr);
    assert(create_parameters != nullptr);

    GFXRECON_UNREFERENCED_PARAMETER(state_table);
    GFXRECON_UNREFERENCED_PARAMETER(create_info);

    wrapper->create_call_id = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);
}

template <>
inline void
InitializeState<CommandBufferWrapper, VkCommandBufferAllocateInfo>(CommandBufferWrapper*              wrapper,
                                                                   const VkCommandBufferAllocateInfo* alloc_info,
                                                                   format::ApiCallId                  create_call_id,
                                                                   CreateParameters                   create_parameters,
                                                                   VulkanStateTable*                  state_table)
{
    assert(wrapper != nullptr);
    assert(alloc_info != nullptr);
    assert(create_parameters != nullptr);
    assert(state_table != nullptr);

    wrapper->create_call_id = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    CommandPoolWrapper* pool_wrapper = state_table->GetCommandPoolWrapper(format::ToHandleId(alloc_info->commandPool));
    if (pool_wrapper != nullptr)
    {
        assert(pool_wrapper->allocated_buffers.find(wrapper->handle) == pool_wrapper->allocated_buffers.end());

        wrapper->pool                                    = pool_wrapper;
        pool_wrapper->allocated_buffers[wrapper->handle] = wrapper;
    }
}

template <>
inline void
InitializeState<PipelineLayoutWrapper, VkPipelineLayoutCreateInfo>(PipelineLayoutWrapper*            wrapper,
                                                                   const VkPipelineLayoutCreateInfo* create_info,
                                                                   format::ApiCallId                 create_call_id,
                                                                   CreateParameters                  create_parameters,
                                                                   VulkanStateTable*                 state_table)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);
    assert(state_table != nullptr);

    wrapper->create_call_id = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    std::shared_ptr<PipelineLayoutDependencies> layout_dependencies = std::make_shared<PipelineLayoutDependencies>();

    for (uint32_t i = 0; i < create_info->setLayoutCount; ++i)
    {
        DescriptorSetLayoutWrapper* layout_wrapper =
            state_table->GetDescriptorSetLayoutWrapper(format::ToHandleId(create_info->pSetLayouts[i]));
        if (layout_wrapper != nullptr)
        {
            DescriptorSetLayoutInfo info;
            info.handle            = layout_wrapper->handle;
            info.handle_id         = layout_wrapper->handle_id;
            info.create_call_id    = layout_wrapper->create_call_id;
            info.create_parameters = layout_wrapper->create_parameters;

            layout_dependencies->layouts.emplace_back(info);
        }
    }

    wrapper->layout_dependencies = layout_dependencies;
}

template <>
inline void
InitializeState<PipelineWrapper, VkGraphicsPipelineCreateInfo>(PipelineWrapper*                    wrapper,
                                                               const VkGraphicsPipelineCreateInfo* create_info,
                                                               format::ApiCallId                   create_call_id,
                                                               CreateParameters                    create_parameters,
                                                               VulkanStateTable*                   state_table)
{
    assert(wrapper != nullptr);
    assert((create_info != nullptr) && (create_info->pStages != nullptr));
    assert(create_parameters != nullptr);
    assert(state_table != nullptr);

    wrapper->create_call_id = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    for (uint32_t i = 0; i < create_info->stageCount; ++i)
    {
        ShaderModuleWrapper* shader_wrapper =
            state_table->GetShaderModuleWrapper(format::ToHandleId(create_info->pStages[i].module));
        if (shader_wrapper != nullptr)
        {
            ShaderModuleInfo info;
            info.handle            = shader_wrapper->handle;
            info.handle_id         = shader_wrapper->handle_id;
            info.create_call_id    = shader_wrapper->create_call_id;
            info.create_parameters = shader_wrapper->create_parameters;

            wrapper->shader_modules.emplace_back(info);
        }
    }

    RenderPassWrapper* render_pass_wrapper =
        state_table->GetRenderPassWrapper(format::ToHandleId(create_info->renderPass));
    if (render_pass_wrapper != nullptr)
    {
        wrapper->render_pass                   = render_pass_wrapper->handle;
        wrapper->render_pass_id                = render_pass_wrapper->handle_id;
        wrapper->render_pass_create_call_id    = render_pass_wrapper->create_call_id;
        wrapper->render_pass_create_parameters = render_pass_wrapper->create_parameters;
    }

    PipelineLayoutWrapper* layout_wrapper =
        state_table->GetPipelineLayoutWrapper(format::ToHandleId(create_info->layout));
    if (layout_wrapper != nullptr)
    {
        wrapper->layout                   = layout_wrapper->handle;
        wrapper->layout_id                = layout_wrapper->handle_id;
        wrapper->layout_create_call_id    = layout_wrapper->create_call_id;
        wrapper->layout_create_parameters = layout_wrapper->create_parameters;
        wrapper->layout_dependencies      = layout_wrapper->layout_dependencies;
    }
}

template <>
inline void
InitializeState<PipelineWrapper, VkComputePipelineCreateInfo>(PipelineWrapper*                   wrapper,
                                                              const VkComputePipelineCreateInfo* create_info,
                                                              format::ApiCallId                  create_call_id,
                                                              CreateParameters                   create_parameters,
                                                              VulkanStateTable*                  state_table)
{
    assert(wrapper != nullptr);
    assert(create_info != nullptr);
    assert(create_parameters != nullptr);
    assert(state_table != nullptr);

    wrapper->create_call_id = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    ShaderModuleWrapper* shader_wrapper =
        state_table->GetShaderModuleWrapper(format::ToHandleId(create_info->stage.module));
    if (shader_wrapper != nullptr)
    {
        ShaderModuleInfo info;
        info.handle            = shader_wrapper->handle;
        info.handle_id         = shader_wrapper->handle_id;
        info.create_call_id    = shader_wrapper->create_call_id;
        info.create_parameters = shader_wrapper->create_parameters;

        wrapper->shader_modules.emplace_back(info);
    }

    PipelineLayoutWrapper* layout_wrapper =
        state_table->GetPipelineLayoutWrapper(format::ToHandleId(create_info->layout));
    if (layout_wrapper != nullptr)
    {
        wrapper->layout                   = layout_wrapper->handle;
        wrapper->layout_id                = layout_wrapper->handle_id;
        wrapper->layout_create_call_id    = layout_wrapper->create_call_id;
        wrapper->layout_create_parameters = layout_wrapper->create_parameters;
        wrapper->layout_dependencies      = layout_wrapper->layout_dependencies;
    }
}

template <>
inline void
InitializeState<PipelineWrapper, VkRayTracingPipelineCreateInfoNV>(PipelineWrapper*                        wrapper,
                                                                   const VkRayTracingPipelineCreateInfoNV* create_info,
                                                                   format::ApiCallId create_call_id,
                                                                   CreateParameters  create_parameters,
                                                                   VulkanStateTable* state_table)
{
    assert(wrapper != nullptr);
    assert((create_info != nullptr) && (create_info->pStages != nullptr));
    assert(create_parameters != nullptr);
    assert(state_table != nullptr);

    wrapper->create_call_id = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    for (uint32_t i = 0; i < create_info->stageCount; ++i)
    {
        ShaderModuleWrapper* shader_wrapper =
            state_table->GetShaderModuleWrapper(format::ToHandleId(create_info->pStages[i].module));
        if (shader_wrapper != nullptr)
        {
            ShaderModuleInfo info;
            info.handle            = shader_wrapper->handle;
            info.handle_id         = shader_wrapper->handle_id;
            info.create_call_id    = shader_wrapper->create_call_id;
            info.create_parameters = shader_wrapper->create_parameters;

            wrapper->shader_modules.emplace_back(info);
        }
    }

    PipelineLayoutWrapper* layout_wrapper =
        state_table->GetPipelineLayoutWrapper(format::ToHandleId(create_info->layout));
    if (layout_wrapper != nullptr)
    {
        wrapper->layout                   = layout_wrapper->handle;
        wrapper->layout_id                = layout_wrapper->handle_id;
        wrapper->layout_create_call_id    = layout_wrapper->create_call_id;
        wrapper->layout_create_parameters = layout_wrapper->create_parameters;
        wrapper->layout_dependencies      = layout_wrapper->layout_dependencies;
    }
}

template <>
inline void
InitializeState<DescriptorSetWrapper, VkDescriptorSetAllocateInfo>(DescriptorSetWrapper*              wrapper,
                                                                   const VkDescriptorSetAllocateInfo* alloc_info,
                                                                   format::ApiCallId                  create_call_id,
                                                                   CreateParameters                   create_parameters,
                                                                   VulkanStateTable*                  state_table)
{
    assert(state_table != nullptr);
    assert(wrapper != nullptr);
    assert(alloc_info != nullptr);
    assert(create_parameters != nullptr);

    wrapper->create_call_id = create_call_id;
    wrapper->create_parameters = std::move(create_parameters);

    DescriptorPoolWrapper* pool_wrapper =
        state_table->GetDescriptorPoolWrapper(format::ToHandleId(alloc_info->descriptorPool));
    if (pool_wrapper != nullptr)
    {
        assert(pool_wrapper->allocated_sets.find(wrapper->handle) == pool_wrapper->allocated_sets.end());

        wrapper->pool                                 = pool_wrapper;
        pool_wrapper->allocated_sets[wrapper->handle] = wrapper;
    }
}

GFXRECON_END_NAMESPACE(vulkan_state_tracker)
GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_ENCODE_VULKAN_STATE_TRACKER_INITIALIZERS_H
