/*
** Copyright (c) 2025 LunarG, Inc.
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

#ifndef GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_DELEGATE_H
#define GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_DELEGATE_H

#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_draw_calls.h"
#include "decode/vulkan_replay_dump_resources_compute_ray_tracing.h"
#include "decode/vulkan_replay_dump_resources_json.h"

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct VulkanDumpDrawCallInfo
{
    DumpResourceType type{ DumpResourceType::kUnknown };

    const graphics::VulkanInstanceTable* instance_table;
    const graphics::VulkanDeviceTable*   device_table;
    CommonObjectInfoTable*               object_info_table;
    const VulkanDeviceInfo*              device_info;
    const VulkanCommandBufferInfo*       original_command_buffer_info;

    uint64_t cmd_index; // dc_index, disp_index, tr_index
    uint64_t qs_index;  // queue submit
    uint64_t bcb_index; // begin command buffer

    uint64_t                                       rp;       // render pass
    uint64_t                                       sp;       // subpass
    const DrawCallsDumpingContext::DrawCallParams* dc_param; // draw call
    const DrawCallsDumpingContext::RenderTargets*  render_targets;

    const DispatchTraceRaysDumpingContext::DispatchParams* disp_param; // dispatch

    const DispatchTraceRaysDumpingContext::TraceRaysParams* tr_param; // trace rays
};

struct VulkanDumpResourceInfo
{
    DumpResourceType type{ DumpResourceType::kUnknown };

    const graphics::VulkanInstanceTable* instance_table;
    const graphics::VulkanDeviceTable*   device_table;
    CommonObjectInfoTable*               object_info_table;
    const VulkanDeviceInfo*              device_info;
    const VulkanCommandBufferInfo*       original_command_buffer_info;

    uint64_t cmd_index; // dc_index, disp_index, tr_index
    uint64_t qs_index;  // queue submit
    uint64_t bcb_index; // begin command buffer

    uint64_t rp; // render pass
    uint64_t sp; // subpass

    const VulkanImageInfo*  image_info;
    const VulkanBufferInfo* buffer_info;
    std::vector<uint8_t>    data;

    uint32_t    set;
    uint32_t    binding;
    VkIndexType index_type;
    int         attachment_index;

    bool               is_dispatch;
    bool               before_cmd;
    uint32_t           array_index;
    VkShaderStageFlags stages;

    VulkanDumpResourceInfo& operator=(const VulkanDumpDrawCallInfo& draw_call_info)
    {
        instance_table               = draw_call_info.instance_table;
        device_table                 = draw_call_info.device_table;
        object_info_table            = draw_call_info.object_info_table;
        device_info                  = draw_call_info.device_info;
        original_command_buffer_info = draw_call_info.original_command_buffer_info;
        cmd_index                    = draw_call_info.cmd_index;
        qs_index                     = draw_call_info.qs_index;
        bcb_index                    = draw_call_info.bcb_index;
        rp                           = draw_call_info.rp;
        sp                           = draw_call_info.sp;
        return *this;
    }
};

class VulkanDumpResourcesDelegate
{
  public:
    VulkanDumpResourcesDelegate(const VulkanReplayOptions& options, const std::string capture_filename) {}
    virtual ~VulkanDumpResourcesDelegate() {}

    virtual bool     Open()                                                                = 0;
    virtual void     DumpDrawCallInfo(const VulkanDumpDrawCallInfo&        draw_call_info,
                                      const graphics::VulkanInstanceTable* instance_table) = 0;
    virtual void     DumpStart()                                                           = 0;
    virtual VkResult DumpResource(const VulkanDumpResourceInfo& resource_info)             = 0;
    virtual void     DumpEnd()                                                             = 0;
    virtual void     Close()                                                               = 0;
};

class DefaultVulkanDumpResourcesDelegate : public VulkanDumpResourcesDelegate
{
  public:
    DefaultVulkanDumpResourcesDelegate(const VulkanReplayOptions& options,
                                       CommonObjectInfoTable&     object_info_table,
                                       const std::string          capture_filename) :
        VulkanDumpResourcesDelegate(options, capture_filename),
        dump_json_(options), options_(options), object_info_table_(object_info_table),
        capture_filename_(capture_filename)
    {}
    virtual ~DefaultVulkanDumpResourcesDelegate() {}

    virtual bool Open() override
    {
        return dump_json_.Open(options_.capture_filename, options_.dump_resources_output_dir);
    }

    virtual void DumpDrawCallInfo(const VulkanDumpDrawCallInfo&        draw_call_info,
                                  const graphics::VulkanInstanceTable* instance_table) override;

    virtual void DumpStart() override { dump_json_.BlockStart(); }

    virtual VkResult DumpResource(const VulkanDumpResourceInfo& resource_info) override;

    virtual void DumpEnd() override { dump_json_.BlockEnd(); }

    virtual void Close() override { dump_json_.Close(); }

  private:
    // DrawCallsDumpingContext
    VkResult DumpRenderTargetImage(const VulkanDumpResourceInfo& resource_info);

    std::string GenerateRenderTargetImageFilename(const VulkanDumpResourceInfo& resource_info,
                                                  VkImageAspectFlagBits         aspect,
                                                  uint32_t                      mip_level,
                                                  uint32_t                      layer) const;

    VkResult DumpImageDescriptor(const VulkanDumpResourceInfo& resource_info);

    std::string GenerateImageDescriptorFilename(const VulkanDumpResourceInfo& resource_info,
                                                VkImageAspectFlagBits         aspect,
                                                uint32_t                      mip_level,
                                                uint32_t                      layer) const;

    VkResult DumpBufferDescriptor(const VulkanDumpResourceInfo& resource_info);

    std::string GenerateBufferDescriptorFilename(const VulkanDumpResourceInfo& resource_info) const;

    VkResult DumpInlineUniformBufferDescriptor(const VulkanDumpResourceInfo& resource_info);

    std::string GenerateInlineUniformBufferDescriptorFilename(const VulkanDumpResourceInfo& resource_info) const;

    VkResult DumpVertexBuffer(const VulkanDumpResourceInfo& resource_info);

    std::string GenerateVertexBufferFilename(const VulkanDumpResourceInfo& resource_info) const;

    VkResult DumpIndexBuffer(const VulkanDumpResourceInfo& resource_info);

    std::string GenerateIndexBufferFilename(const VulkanDumpResourceInfo& resource_info) const;

    void GenerateOutputJsonDrawCallInfo(const VulkanDumpDrawCallInfo&        draw_call_info,
                                        const graphics::VulkanInstanceTable* instance_table);

    // DispatchTraceRaysDumpingContext
    VkResult DumpeDispatchTraceRaysImage(const VulkanDumpResourceInfo& resource_info);

    std::string GenerateDispatchTraceRaysImageFilename(const VulkanDumpResourceInfo& resource_info,
                                                       uint32_t                      mip_level,
                                                       uint32_t                      layer,
                                                       VkImageAspectFlagBits         aspect) const;

    VkResult DumpeDispatchTraceRaysBuffer(const VulkanDumpResourceInfo& resource_info);

    std::string GenerateDispatchTraceRaysBufferFilename(const VulkanDumpResourceInfo& resource_info) const;

    VkResult DumpDispatchTraceRaysImageDescriptor(const VulkanDumpResourceInfo& resource_info);

    std::string GenerateDispatchTraceRaysImageDescriptorFilename(const VulkanDumpResourceInfo& resource_info,
                                                                 uint32_t                      mip_level,
                                                                 uint32_t                      layer,
                                                                 VkImageAspectFlagBits         aspect) const;

    VkResult DumpDispatchTraceRaysBufferDescriptor(const VulkanDumpResourceInfo& resource_info);

    std::string GenerateDispatchTraceRaysBufferDescriptorFilename(const VulkanDumpResourceInfo& resource_info) const;

    VkResult DumpDispatchTraceRaysInlineUniformBufferDescriptor(const VulkanDumpResourceInfo& resource_info);

    std::string
    GenerateDispatchTraceRaysInlineUniformBufferDescriptorFilename(const VulkanDumpResourceInfo& resource_info) const;

    void GenerateOutputJsonDispatchInfo(const VulkanDumpDrawCallInfo&        draw_call_info,
                                        const graphics::VulkanInstanceTable* instance_table);

    void GenerateOutputJsonTraceRaysIndex(const VulkanDumpDrawCallInfo&        draw_call_info,
                                          const graphics::VulkanInstanceTable* instance_table);

    bool IsImageDumpable(const graphics::VulkanInstanceTable* instance_table, const VulkanImageInfo* image_info);

    // Keep track of images for which scalling failed so we can
    // note them in the output json
    std::unordered_set<const VulkanImageInfo*> images_failed_scaling_;

    bool ImageFailedScaling(const VulkanImageInfo* img_info) const { return images_failed_scaling_.count(img_info); }

    void GenerateDispatchTraceRaysDescriptorsJsonInfo(
        const VulkanDumpDrawCallInfo&                                         draw_call_info,
        nlohmann::ordered_json&                                               dispatch_json_entry,
        const BoundDescriptorSets&                                            referenced_descriptors,
        const DispatchTraceRaysDumpingContext::MutableResourcesBackupContext& cloned_resources,
        const DispatchTraceRaysDumpingContext::MutableResourcesBackupContext& cloned_resources_before,
        bool                                                                  is_dispatch);

    VulkanReplayDumpResourcesJson dump_json_;
    const VulkanReplayOptions&    options_;
    CommonObjectInfoTable&        object_info_table_;
    const std::string             capture_filename_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_DELEGATE_H */
