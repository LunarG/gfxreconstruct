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

#include "decode/vulkan_replay_dump_resources_common.h"
#include "util/compressor.h"
#include "decode/vulkan_replay_dump_resources_draw_calls.h"
#include "decode/vulkan_replay_dump_resources_compute_ray_tracing.h"
#include "decode/vulkan_replay_dump_resources_json.h"

#include <cstdint>
#include <variant>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

struct VulkanDelegateDumpDrawCallContext
{
    VulkanDelegateDumpDrawCallContext(DumpResourcesCommandType                       t,
                                      const graphics::VulkanInstanceTable*           it,
                                      const graphics::VulkanDeviceTable*             dt,
                                      const DrawCallsDumpingContext::DrawCallParams* dc_params) :
        command_type(t),
        instance_table(it), device_table(dt), command_parameters(dc_params)
    {}

    VulkanDelegateDumpDrawCallContext(DumpResourcesCommandType                               t,
                                      const graphics::VulkanInstanceTable*                   it,
                                      const graphics::VulkanDeviceTable*                     dt,
                                      const DispatchTraceRaysDumpingContext::DispatchParams* disp_params) :
        command_type(t),
        instance_table(it), device_table(dt), command_parameters(disp_params)
    {}

    VulkanDelegateDumpDrawCallContext(DumpResourcesCommandType                                t,
                                      const graphics::VulkanInstanceTable*                    it,
                                      const graphics::VulkanDeviceTable*                      dt,
                                      const DispatchTraceRaysDumpingContext::TraceRaysParams* tr_params) :
        command_type(t),
        instance_table(it), device_table(dt), command_parameters(tr_params)
    {}

    DumpResourcesCommandType             command_type;
    const graphics::VulkanInstanceTable* instance_table;
    const graphics::VulkanDeviceTable*   device_table;

    std::variant<const DrawCallsDumpingContext::DrawCallParams*,
                 const DispatchTraceRaysDumpingContext::DispatchParams*,
                 const DispatchTraceRaysDumpingContext::TraceRaysParams*>
        command_parameters;
};

struct VulkanDelegateBufferDumpedData
{
    VulkanDelegateBufferDumpedData() = default;

    DumpedRawData data;
};

struct VulkanDelegateImageDumpedData
{
    VulkanDelegateImageDumpedData() = default;

    std::vector<DumpedRawData> data;
};

struct VulkanDelegateDumpResourceContext
{
    VulkanDelegateDumpResourceContext() = delete;

    VulkanDelegateDumpResourceContext(const graphics::VulkanInstanceTable* it,
                                      const graphics::VulkanDeviceTable*   dt,
                                      const util::Compressor*              c  = nullptr,
                                      bool                                 bc = false) :
        instance_table(it),
        device_table(dt), compressor(c), before_command(bc), dumped_resource(nullptr)
    {}

    const graphics::VulkanInstanceTable* instance_table;
    const graphics::VulkanDeviceTable*   device_table;

    const util::Compressor* compressor;
    bool                    before_command;

    DumpedResourceBase*                                                         dumped_resource;
    std::variant<VulkanDelegateBufferDumpedData, VulkanDelegateImageDumpedData> dumped_data;

    VulkanDelegateDumpResourceContext& operator=(const VulkanDelegateDumpDrawCallContext& draw_call_info)
    {
        instance_table = draw_call_info.instance_table;
        device_table   = draw_call_info.device_table;
        return *this;
    }
};

class VulkanDumpResourcesDelegate
{
  public:
    VulkanDumpResourcesDelegate(const VulkanReplayOptions& options, const std::string capture_filename) {}
    virtual ~VulkanDumpResourcesDelegate() {}

    virtual bool Open()                                                                    = 0;
    virtual void DumpDrawCallInfo(const VulkanDelegateDumpDrawCallContext& draw_call_info) = 0;
    virtual void DumpStart()                                                               = 0;
    virtual bool DumpResource(const VulkanDelegateDumpResourceContext& delegate_context)   = 0;
    virtual void DumpEnd()                                                                 = 0;
    virtual void Close()                                                                   = 0;
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

    virtual void DumpDrawCallInfo(const VulkanDelegateDumpDrawCallContext& draw_call_info) override;

    virtual void DumpStart() override { dump_json_.BlockStart(); }

    virtual bool DumpResource(const VulkanDelegateDumpResourceContext& delegate_context) override;

    virtual void DumpEnd() override { dump_json_.BlockEnd(); }

    virtual void Close() override { dump_json_.Close(); }

  private:
    typedef std::string (DefaultVulkanDumpResourcesDelegate::*BufferFilenameGenerator)(
        const DumpedResourceBase& dumped_resource, bool before_command) const;

    typedef std::string (DefaultVulkanDumpResourcesDelegate::*ImageFilenameGenerator)(
        const DumpedResourceBase& dumped_resource,
        DumpedImageFormat         output_image_format,
        VkImageAspectFlagBits     aspect,
        uint32_t                  mip_level,
        uint32_t                  layer,
        bool                      before_command) const;

    // Images
    bool DumpImageToFile(const VulkanDelegateDumpResourceContext& delegate_context);

    // Image filename generators
    std::string GenerateRenderTargetImageFilename(const DumpedResourceBase& dumped_resource,
                                                  DumpedImageFormat         output_image_format,
                                                  VkImageAspectFlagBits     aspect,
                                                  uint32_t                  mip_level,
                                                  uint32_t                  layer,
                                                  bool                      before_command) const;

    std::string GenerateGraphicsImageDescriptorFilename(const DumpedResourceBase& dumped_resource,
                                                        DumpedImageFormat         output_image_format,
                                                        VkImageAspectFlagBits     aspect,
                                                        uint32_t                  mip_level,
                                                        uint32_t                  layer,
                                                        bool                      before_command) const;

    std::string GenerateDispatchTraceRaysImageFilename(const DumpedResourceBase& dumped_resource,
                                                       DumpedImageFormat         output_image_format,
                                                       VkImageAspectFlagBits     aspect,
                                                       uint32_t                  mip_level,
                                                       uint32_t                  layer,
                                                       bool                      before_command) const;

    std::string GenerateDispatchTraceRaysImageDescriptorFilename(const DumpedResourceBase& dumped_resource,
                                                                 DumpedImageFormat         output_image_format,
                                                                 VkImageAspectFlagBits     aspect,
                                                                 uint32_t                  mip_level,
                                                                 uint32_t                  layer,
                                                                 bool                      before_command) const;

    // Buffers
    bool DumpBufferToFile(const VulkanDelegateDumpResourceContext& delegate_context);

    // Buffer filename generators
    std::string GenerateGraphicsBufferDescriptorFilename(const DumpedResourceBase& dumped_resource,
                                                         bool                      before_command) const;

    std::string GenerateDispatchTraceRaysBufferDescriptorFilename(const DumpedResourceBase& dumped_resource,
                                                                  bool                      before_command) const;

    std::string
    GenerateDispatchTraceRaysInlineUniformBufferDescriptorFilename(const DumpedResourceBase& dumped_resource,
                                                                   bool                      before_command) const;

    std::string GenerateGraphicsInlineUniformBufferDescriptorFilename(const DumpedResourceBase& dumped_resource,
                                                                      bool                      before_command) const;

    std::string GenerateDispatchTraceRaysBufferFilename(const DumpedResourceBase& dumped_resource,
                                                        bool                      before_command) const;

    std::string GenerateVertexBufferFilename(const DumpedResourceBase& dumped_resource, bool before_command) const;

    std::string GenerateIndexBufferFilename(const DumpedResourceBase& dumped_resource, bool before_command) const;

    // Json generators
    void GenerateOutputJsonDrawCallInfo(const VulkanDelegateDumpDrawCallContext& draw_call_info);

    void GenerateOutputJsonDispatchInfo(const VulkanDelegateDumpDrawCallContext& draw_call_info);

    void GenerateOutputJsonTraceRaysIndex(const VulkanDelegateDumpDrawCallContext& draw_call_info);

    void GenerateDispatchTraceRaysDescriptorsJsonInfo(nlohmann::ordered_json&    dispatch_json_entry,
                                                      const DumpedResourcesInfo& dumped_resources,
                                                      bool                       is_dispatch);

    VulkanReplayDumpResourcesJson dump_json_;
    const VulkanReplayOptions&    options_;
    CommonObjectInfoTable&        object_info_table_;
    const std::string             capture_filename_;
};

GFXRECON_END_NAMESPACE(gfxrecon)
GFXRECON_END_NAMESPACE(decode)

#endif /* GFXRECON_VULKAN_REPLAY_DUMP_RESOURCES_DELEGATE_H */
