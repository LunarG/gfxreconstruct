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

#ifndef GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_TRANSFER_H
#define GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_TRANSFER_H

#include "decode/api_decoder.h"
#include "decode/common_object_info_table.h"
#include "decode/vulkan_object_info.h"
#include "decode/vulkan_replay_dump_resources_common.h"
#include "decode/vulkan_replay_options.h"
#include "format/format.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "util/defines.h"
#include "util/logging.h"

#include <cstdint>
#include <memory>
#include <utility>
#include <variant>
#include <vulkan/vulkan_core.h>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class TransferDumpingContext
{
  public:
    TransferDumpingContext(const CommandIndices*                             transfer_indices,
                           CommonObjectInfoTable&                            object_info_table,
                           const graphics::InstanceDispatchTablesMap&        instance_tables,
                           const graphics::DeviceDispatchTablesMap&          device_tables,
                           const VulkanReplayOptions&                        options,
                           VulkanDumpResourcesDelegate&                      delegate,
                           const VulkanPerDeviceAddressTrackers&             address_trackers,
                           const DumpResourcesAccelerationStructuresContext& acceleration_structures_context,
                           const util::Compressor*                           compressor);

    ~TransferDumpingContext() { Release(); }

    VkResult HandleInitBufferCommand(uint64_t         cmd_index,
                                     format::HandleId device_id,
                                     format::HandleId buffer_id,
                                     uint64_t         data_size,
                                     const uint8_t*   data);

    VkResult HandleInitImageCommand(VkCommandBuffer              command_buffer,
                                    uint64_t                     cmd_index,
                                    format::HandleId             device_id,
                                    format::HandleId             image_id,
                                    uint64_t                     data_size,
                                    VkImageAspectFlagBits        aspect,
                                    VkImageLayout                layout,
                                    const std::vector<uint64_t>& level_sizes,
                                    const uint8_t*               data);

    VkResult HandleCmdCopyBuffer(const ApiCallInfo&      call_info,
                                 VkCommandBuffer         commandBuffer,
                                 const VulkanBufferInfo* srcBuffer,
                                 const VulkanBufferInfo* dstBuffer,
                                 uint32_t                regionCount,
                                 const VkBufferCopy*     pRegions,
                                 bool                    before_command);

    VkResult HandleCmdCopyBuffer2(const ApiCallInfo&                               call_info,
                                  VkCommandBuffer                                  commandBuffer,
                                  StructPointerDecoder<Decoded_VkCopyBufferInfo2>* pCopyBufferInfo,
                                  bool                                             before_command);

    VkResult HandleCmdCopyBufferToImage(const ApiCallInfo&       call_info,
                                        VkCommandBuffer          commandBuffer,
                                        const VulkanBufferInfo*  srcBuffer,
                                        const VulkanImageInfo*   dstImage,
                                        VkImageLayout            dstImageLayout,
                                        uint32_t                 regionCount,
                                        const VkBufferImageCopy* pRegions,
                                        bool                     before_command);

    VkResult HandleCmdCopyBufferToImage2(const ApiCallInfo&                                      call_info,
                                         VkCommandBuffer                                         commandBuffer,
                                         StructPointerDecoder<Decoded_VkCopyBufferToImageInfo2>* pCopyBufferToImageInfo,
                                         bool                                                    before_command);

    VkResult HandleCmdCopyImage(const ApiCallInfo&     call_info,
                                VkCommandBuffer        commandBuffer,
                                const VulkanImageInfo* srcImage,
                                VkImageLayout          srcImageLayout,
                                const VulkanImageInfo* dstImage,
                                VkImageLayout          dstImageLayout,
                                uint32_t               regionCount,
                                const VkImageCopy*     pRegions,
                                bool                   before_command);

    VkResult HandleCmdCopyImage2(const ApiCallInfo&                              call_info,
                                 VkCommandBuffer                                 commandBuffer,
                                 StructPointerDecoder<Decoded_VkCopyImageInfo2>* pCopyImageInfo,
                                 bool                                            before_command);

    VkResult HandleCmdCopyImageToBuffer(const ApiCallInfo&       call_info,
                                        VkCommandBuffer          commandBuffer,
                                        const VulkanImageInfo*   srcImage,
                                        VkImageLayout            srcImageLayout,
                                        const VulkanBufferInfo*  dstBuffer,
                                        uint32_t                 regionCount,
                                        const VkBufferImageCopy* pRegions,
                                        bool                     before_command);

    VkResult HandleCmdCopyImageToBuffer2(const ApiCallInfo&                                      call_info,
                                         VkCommandBuffer                                         commandBuffer,
                                         StructPointerDecoder<Decoded_VkCopyImageToBufferInfo2>* pCopyImageToBufferInfo,
                                         bool                                                    before_command);

    VkResult HandleCmdBlitImage(const ApiCallInfo&     call_info,
                                VkCommandBuffer        commandBuffer,
                                const VulkanImageInfo* srcImage,
                                VkImageLayout          srcImageLayout,
                                const VulkanImageInfo* dstImage,
                                VkImageLayout          dstImageLayout,
                                uint32_t               regionCount,
                                const VkImageBlit*     pRegions,
                                VkFilter               filter,
                                bool                   before_command);

    VkResult HandleCmdBlitImage2(const ApiCallInfo&                              call_info,
                                 VkCommandBuffer                                 commandBuffer,
                                 StructPointerDecoder<Decoded_VkBlitImageInfo2>* pBlitImageInfo,
                                 bool                                            before_command);

    VkResult HandleCmdBuildAccelerationStructuresKHR(
        const ApiCallInfo&                                                         call_info,
        VkCommandBuffer                                                            commandBuffer,
        uint32_t                                                                   infoCount,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildGeometryInfoKHR>* pInfos,
        StructPointerDecoder<Decoded_VkAccelerationStructureBuildRangeInfoKHR*>*   ppBuildRangeInfos,
        bool                                                                       before_command);

    VkResult
    HandleCmdCopyAccelerationStructureKHR(const ApiCallInfo& call_info,
                                          VkCommandBuffer    commandBuffer,
                                          StructPointerDecoder<Decoded_VkCopyAccelerationStructureInfoKHR>* pInfo,
                                          bool before_command);

    bool MustDumpTransfer(uint64_t index) const;

    VkResult DumpTransferCommands(uint64_t bcb_index, uint64_t qs_index);

    const CommandIndices& GetCommandIndices() const { return transfer_indices_; }

    void Release() { transfer_params_.clear(); }

    enum TransferCommandTypes
    {
        kCmdInitBuffer,
        kCmdInitImage,
        kCmdCopyBuffer,
        kCmdCopyBufferToImage,
        kCmdCopyImage,
        kCmdCopyImageToBuffer,
        kCmdBlitImage,
        kCmdBuildAccelerationStructures,
        kCmdCopyAccelerationStructure
    };

    static const char* TransferCommandTypeToStr(TransferCommandTypes type)
    {
        switch (type)
        {
            case kCmdInitBuffer:
                return "InitBufferMetaCommand";
            case kCmdInitImage:
                return "InitImageMetaCommand";
            case kCmdCopyBuffer:
                return "vkCmdCopyBuffer";
            case kCmdCopyBufferToImage:
                return "vkCmdCopyBufferToImage";
            case kCmdCopyImage:
                return "vkCmdCopyImage";
            case kCmdCopyImageToBuffer:
                return "vkCmdCopyImageToBuffer";
            case kCmdBlitImage:
                return "vkCmdBlitImage";
            case kCmdBuildAccelerationStructures:
                return "vkCmdBuildAccelerationStructures";
            case kCmdCopyAccelerationStructure:
                return "vkCmdCopyAccelerationStructure";

            default:
                GFXRECON_LOG_ERROR("%s(): Unrecognized transfer command type (%d)", __func__, static_cast<int>(type));
                GFXRECON_ASSERT(0);
                return "XXX";
        }
    }

    struct TransferParams
    {
        struct CopiedBuffer
        {
            VkBuffer       buffer{ VK_NULL_HANDLE };
            VkDeviceSize   size{ 0 };
            VkDeviceMemory memory{ VK_NULL_HANDLE };
        };

        struct CopiedImage
        {
            CopiedImage(const VulkanImageInfo* img_info) :
                image_info(*img_info), image(VK_NULL_HANDLE), memory(VK_NULL_HANDLE)
            {}

            VkImage         image;
            VkDeviceMemory  memory;
            VulkanImageInfo image_info;
        };

        struct TransferParamsBase
        {
            TransferParamsBase(TransferCommandTypes               t,
                               bool                               hb,
                               const graphics::VulkanDeviceTable& dt,
                               const VulkanDeviceInfo*            pdi) :
                type(t),
                device_table_(dt), parent_device_info_(pdi), has_before_command(hb)
            {}

            const graphics::VulkanDeviceTable& device_table_;
            const VulkanDeviceInfo*            parent_device_info_;
            TransferCommandTypes               type;
            bool                               has_before_command;
            DumpedResourcesInfo                dumped_resources;
        };

        // kInitBufferCommand
        struct InitBufferMetaCommand : TransferParamsBase
        {
            InitBufferMetaCommand() = delete;

            InitBufferMetaCommand(TransferCommandTypes               t,
                                  bool                               hb,
                                  const graphics::VulkanDeviceTable& dt,
                                  const VulkanDeviceInfo*            pdi,
                                  format::HandleId                   b,
                                  const uint8_t*                     d_p,
                                  uint64_t                           size) :
                TransferParamsBase(t, hb, dt, pdi),
                dst_buffer(b), data(d_p, d_p + size)
            {}

            format::HandleId dst_buffer;
            DumpedHostData   data;
        };

        // kInitImageCommand
        struct InitImageMetaCommand : TransferParamsBase
        {
            InitImageMetaCommand() = delete;

            InitImageMetaCommand(TransferCommandTypes               t,
                                 bool                               hb,
                                 const graphics::VulkanDeviceTable& dt,
                                 const VulkanDeviceInfo*            pdi,
                                 format::HandleId                   i,
                                 VkImageAspectFlagBits              a,
                                 const VulkanImageInfo*             ii) :
                TransferParamsBase(t, hb, dt, pdi),
                dst_image(i), aspect(a), copied_image(ii)
            {}

            ~InitImageMetaCommand()
            {
                if (copied_image.image != VK_NULL_HANDLE)
                {
                    device_table_.DestroyImage(parent_device_info_->handle, copied_image.image, nullptr);
                }

                if (copied_image.memory != VK_NULL_HANDLE)
                {
                    device_table_.FreeMemory(parent_device_info_->handle, copied_image.memory, nullptr);
                }
            }

            format::HandleId      dst_image;
            VkImageAspectFlagBits aspect;
            CopiedImage           copied_image;
        };

        // CmdCopyBuffer
        struct CopyBuffer : TransferParamsBase
        {
            CopyBuffer() = delete;

            CopyBuffer(TransferCommandTypes               t,
                       bool                               hb,
                       const graphics::VulkanDeviceTable& dt,
                       const VulkanDeviceInfo*            pdi,
                       format::HandleId                   s,
                       format::HandleId                   d) :
                TransferParamsBase(t, hb, dt, pdi),
                src_buffer(s), dst_buffer(d)
            {}

            ~CopyBuffer()
            {
                for (const auto& region : regions)
                {
                    if (region.vk_objects.buffer != VK_NULL_HANDLE)
                    {
                        device_table_.DestroyBuffer(parent_device_info_->handle, region.vk_objects.buffer, nullptr);
                    }

                    if (region.vk_objects.memory != VK_NULL_HANDLE)
                    {
                        device_table_.FreeMemory(parent_device_info_->handle, region.vk_objects.memory, nullptr);
                    }
                }
            }

            format::HandleId src_buffer;
            format::HandleId dst_buffer;

            struct CopyRegion
            {
                CopyRegion(const VkBufferCopy& r) : region(r) {}

                VkBufferCopy region;
                CopiedBuffer vk_objects;
            };

            std::vector<CopyRegion> regions;
        };

        // CmdCopyBufferToImage
        struct CopyBufferToImage : TransferParamsBase
        {
            CopyBufferToImage() = delete;

            CopyBufferToImage(TransferCommandTypes               t,
                              bool                               hb,
                              const graphics::VulkanDeviceTable& dt,
                              const VulkanDeviceInfo*            pdi,
                              format::HandleId                   sb,
                              VkImageLayout                      dil,
                              const VulkanImageInfo*             ii) :
                TransferParamsBase(t, hb, dt, pdi),
                src_buffer(sb), dst_image(ii->capture_id), dst_image_layout(dil), copied_image(ii)
            {}

            ~CopyBufferToImage()
            {
                if (copied_image.image != VK_NULL_HANDLE)
                {
                    device_table_.DestroyImage(parent_device_info_->handle, copied_image.image, nullptr);
                }

                if (copied_image.memory != VK_NULL_HANDLE)
                {
                    device_table_.FreeMemory(parent_device_info_->handle, copied_image.memory, nullptr);
                }
            }

            format::HandleId src_buffer;
            format::HandleId dst_image;
            VkImageLayout    dst_image_layout;

            // We create an image with the same properties as the destination image.
            // Then we do the same copy regions to the new image
            CopiedImage copied_image;

            struct CopyRegion
            {
                CopyRegion() = delete;

                CopyRegion(const VkBufferImageCopy& r) : region(r) {}
                VkBufferImageCopy region;
            };

            std::vector<CopyRegion> regions;
        };

        // CmdCopyImage
        struct CopyImage : TransferParamsBase
        {
            CopyImage() = delete;

            CopyImage(TransferCommandTypes               t,
                      bool                               hb,
                      const graphics::VulkanDeviceTable& dt,
                      const VulkanDeviceInfo*            pdi,
                      format::HandleId                   s,
                      VkImageLayout                      sl,
                      VkImageLayout                      dl,
                      const VulkanImageInfo*             img_info) :
                TransferParamsBase(t, hb, dt, pdi),
                src_image(s), src_image_layout(sl), dst_image(img_info->capture_id), dst_image_layout(dl),
                copied_image(img_info)
            {}

            ~CopyImage()
            {
                if (copied_image.image != VK_NULL_HANDLE)
                {
                    device_table_.DestroyImage(parent_device_info_->handle, copied_image.image, nullptr);
                }

                if (copied_image.memory != VK_NULL_HANDLE)
                {
                    device_table_.FreeMemory(parent_device_info_->handle, copied_image.memory, nullptr);
                }
            }

            format::HandleId src_image;
            VkImageLayout    src_image_layout;

            format::HandleId dst_image;
            VkImageLayout    dst_image_layout;

            // We create an image with the same properties as the destination image.
            // Then we do the same copy regions to the new image
            CopiedImage copied_image;

            struct CopyRegion
            {
                CopyRegion() = delete;

                CopyRegion(const VkImageCopy& r) : region(r) {}
                VkImageCopy region;
            };

            std::vector<CopyRegion> regions;
        };

        // CmdCopyImageToBuffer
        struct CopyImageToBuffer : TransferParamsBase
        {
            CopyImageToBuffer() = delete;

            CopyImageToBuffer(TransferCommandTypes               t,
                              bool                               hb,
                              const graphics::VulkanDeviceTable& dt,
                              const VulkanDeviceInfo*            pdi,
                              format::HandleId                   s,
                              VkImageLayout                      sl,
                              format::HandleId                   d) :
                TransferParamsBase(t, hb, dt, pdi),
                src_image(s), src_image_layout(sl), dst_buffer(d)
            {}

            ~CopyImageToBuffer()
            {
                for (const auto& region : regions)
                {
                    if (region.vk_objects.buffer != VK_NULL_HANDLE)
                    {
                        device_table_.DestroyBuffer(parent_device_info_->handle, region.vk_objects.buffer, nullptr);
                    }

                    if (region.vk_objects.memory != VK_NULL_HANDLE)
                    {
                        device_table_.FreeMemory(parent_device_info_->handle, region.vk_objects.memory, nullptr);
                    }
                }
            }

            struct CopiedRegion
            {
                CopiedRegion() = delete;
                CopiedRegion(const VkBufferImageCopy& r) : region(r) {}

                VkBufferImageCopy region;
                CopiedBuffer      vk_objects;
            };

            format::HandleId src_image;
            VkImageLayout    src_image_layout;

            format::HandleId dst_buffer;

            std::vector<CopiedRegion> regions;
        };

        // CmdBlitImage
        struct BlitImage : TransferParamsBase
        {
            BlitImage() = delete;

            BlitImage(TransferCommandTypes               t,
                      bool                               hb,
                      const graphics::VulkanDeviceTable& dt,
                      const VulkanDeviceInfo*            pdi,
                      format::HandleId                   s,
                      VkImageLayout                      sl,
                      VkImageLayout                      dl,
                      const VulkanImageInfo*             img_info,
                      VkFilter                           f) :
                TransferParamsBase(t, hb, dt, pdi),
                src_image(s), src_image_layout(sl), dst_image(img_info->capture_id), dst_image_layout(dl),
                copied_image(img_info), filter(f)
            {}

            ~BlitImage()
            {
                if (copied_image.image != VK_NULL_HANDLE)
                {
                    device_table_.DestroyImage(parent_device_info_->handle, copied_image.image, nullptr);
                }

                if (copied_image.memory != VK_NULL_HANDLE)
                {
                    device_table_.FreeMemory(parent_device_info_->handle, copied_image.memory, nullptr);
                }
            }

            format::HandleId src_image;
            VkImageLayout    src_image_layout;

            format::HandleId dst_image;
            VkImageLayout    dst_image_layout;

            VkFilter filter;

            // We create an image with the same properties as the destination image.
            // Then we do the same copy regions to the new image
            CopiedImage copied_image;

            struct CopyRegion
            {
                CopyRegion() = delete;

                CopyRegion(const VkImageBlit& r) : region(r) {}
                VkImageBlit region;
            };

            std::vector<CopyRegion> regions;
        };

        struct CopiedAccelerationStructure
        {
            CopiedAccelerationStructure() = delete;

            CopiedAccelerationStructure(const graphics::VulkanDeviceTable&        dt,
                                        const CommonObjectInfoTable&              oit,
                                        const VulkanPerDeviceAddressTrackers&     at,
                                        const VulkanAccelerationStructureKHRInfo* asi) :
                as_context(&as_info, dt, oit, at),
                as(VK_NULL_HANDLE), buffer(VK_NULL_HANDLE), memory(VK_NULL_HANDLE)
            {
                // Clone information stored in the destination as info. Later this will need to be updated with
                // the new objects
                GFXRECON_ASSERT(asi != nullptr);
                as_info = *asi;
            }

            // Cloned AS and backing memory
            VkAccelerationStructureKHR         as;
            VkBuffer                           buffer;
            VkDeviceMemory                     memory;
            VulkanAccelerationStructureKHRInfo as_info;

            // Cloned build input buffers
            AccelerationStructureDumpResourcesContext as_context;
        };

        // CmdBuildAccelerationStructuresKHR
        struct BuildAccelerationStructure : TransferParamsBase
        {
            BuildAccelerationStructure(TransferCommandTypes               t,
                                       bool                               hb,
                                       const graphics::VulkanDeviceTable& dt,
                                       const VulkanDeviceInfo*            pdi) :
                TransferParamsBase(t, hb, dt, pdi)
            {}

            ~BuildAccelerationStructure()
            {
                for (const auto& build_info : build_infos)
                {
                    if (build_info.vk_objects.as != VK_NULL_HANDLE)
                    {
                        device_table_.DestroyAccelerationStructureKHR(
                            parent_device_info_->handle, build_info.vk_objects.as, nullptr);
                    }

                    if (build_info.vk_objects.buffer != VK_NULL_HANDLE)
                    {
                        device_table_.DestroyBuffer(parent_device_info_->handle, build_info.vk_objects.buffer, nullptr);
                    }

                    if (build_info.vk_objects.memory != VK_NULL_HANDLE)
                    {
                        device_table_.FreeMemory(parent_device_info_->handle, build_info.vk_objects.memory, nullptr);
                    }
                }
            }

            struct BuildInfo
            {
                BuildInfo() = delete;

                BuildInfo(const VulkanAccelerationStructureKHRInfo* s,
                          const VulkanAccelerationStructureKHRInfo* d,
                          VkBuildAccelerationStructureModeKHR       m,
                          const graphics::VulkanDeviceTable&        dt,
                          const CommonObjectInfoTable&              oit,
                          const VulkanPerDeviceAddressTrackers&     at) :
                    src_as(s != nullptr ? s->capture_id : format::kNullHandleId),
                    dst_as(d->capture_id), mode(m), vk_objects(dt, oit, at, d)
                {}

                format::HandleId                    src_as;
                format::HandleId                    dst_as;
                VkBuildAccelerationStructureModeKHR mode;

                CopiedAccelerationStructure vk_objects;
            };

            std::vector<BuildInfo> build_infos;
        };

        // CmdCopyAccelerationStructureKHR
        struct CopyAccelerationStructure : TransferParamsBase
        {
            CopyAccelerationStructure() = delete;

            CopyAccelerationStructure(TransferCommandTypes                      t,
                                      bool                                      hb,
                                      const graphics::VulkanDeviceTable&        dt,
                                      const VulkanDeviceInfo*                   pdi,
                                      format::HandleId                          s,
                                      const VulkanAccelerationStructureKHRInfo* d,
                                      VkCopyAccelerationStructureModeKHR        m,
                                      const CommonObjectInfoTable&              oit,
                                      const VulkanPerDeviceAddressTrackers&     at) :
                TransferParamsBase(t, hb, dt, pdi),
                src_as(s), dst_as(d->capture_id), mode(m), vk_objects(dt, oit, at, d)
            {}

            ~CopyAccelerationStructure()
            {
                if (vk_objects.as != VK_NULL_HANDLE)
                {
                    device_table_.DestroyAccelerationStructureKHR(parent_device_info_->handle, vk_objects.as, nullptr);
                }

                if (vk_objects.buffer != VK_NULL_HANDLE)
                {
                    device_table_.DestroyBuffer(parent_device_info_->handle, vk_objects.buffer, nullptr);
                }

                if (vk_objects.memory != VK_NULL_HANDLE)
                {
                    device_table_.FreeMemory(parent_device_info_->handle, vk_objects.memory, nullptr);
                }
            }

            format::HandleId                   src_as;
            format::HandleId                   dst_as;
            VkCopyAccelerationStructureModeKHR mode;
            CopiedAccelerationStructure        vk_objects;
        };

        // TransferParams constructors, one for each transfer command
        TransferParams() = delete;

        // kInitBufferCommand
        TransferParams(format::HandleId                   b,
                       const uint8_t*                     d_p,
                       uint64_t                           size,
                       const graphics::VulkanDeviceTable& dt,
                       const VulkanDeviceInfo*            pdi,
                       TransferCommandTypes               t) :
            params(std::make_unique<InitBufferMetaCommand>(t, false, dt, pdi, b, d_p, size))
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdInitBuffer);
        }

        // kInitImageCommand
        TransferParams(format::HandleId                   i,
                       VkImageAspectFlagBits              a,
                       const VulkanImageInfo*             img_info,
                       const graphics::VulkanDeviceTable& dt,
                       const VulkanDeviceInfo*            pdi,
                       TransferCommandTypes               t) :
            params(std::make_unique<InitImageMetaCommand>(t, false, dt, pdi, i, a, img_info))
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdInitImage);
        }

        // CmdCopyBuffer
        TransferParams(format::HandleId                   s,
                       format::HandleId                   d,
                       const graphics::VulkanDeviceTable& dt,
                       const VulkanDeviceInfo*            pdi,
                       bool                               bc,
                       TransferCommandTypes               t) :
            params(std::make_unique<CopyBuffer>(t, bc, dt, pdi, s, d))
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdCopyBuffer);

            if (bc)
            {
                before_params = std::make_unique<CopyBuffer>(t, bc, dt, pdi, s, d);
            }
        }

        // CmdCopyBufferToImage
        TransferParams(format::HandleId                   sb,
                       VkImageLayout                      dil,
                       const VulkanImageInfo*             ii,
                       const graphics::VulkanDeviceTable& dt,
                       const VulkanDeviceInfo*            pdi,
                       bool                               bc,
                       TransferCommandTypes               t) :
            params(std::make_unique<CopyBufferToImage>(t, bc, dt, pdi, sb, dil, ii))
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdCopyBufferToImage);

            if (bc)
            {
                before_params = std::make_unique<CopyBufferToImage>(t, bc, dt, pdi, sb, dil, ii);
            }
        }

        // CmdCopyImage
        TransferParams(format::HandleId                   s,
                       VkImageLayout                      sl,
                       VkImageLayout                      dl,
                       const VulkanImageInfo*             img_info,
                       const graphics::VulkanDeviceTable& dt,
                       const VulkanDeviceInfo*            pdi,
                       bool                               bc,
                       TransferCommandTypes               t) :
            params(std::make_unique<CopyImage>(t, bc, dt, pdi, s, sl, dl, img_info))
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdCopyImage);

            if (bc)
            {
                before_params = std::make_unique<CopyImage>(t, bc, dt, pdi, s, sl, dl, img_info);
            }
        }

        // CmdCopyImageToBuffer
        TransferParams(format::HandleId                   s,
                       VkImageLayout                      sl,
                       format::HandleId                   d,
                       const graphics::VulkanDeviceTable& dt,
                       const VulkanDeviceInfo*            pdi,
                       bool                               bc,
                       TransferCommandTypes               t) :
            params(std::make_unique<CopyImageToBuffer>(t, bc, dt, pdi, s, sl, d))
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdCopyImageToBuffer);

            if (bc)
            {
                before_params = std::make_unique<CopyImageToBuffer>(t, bc, dt, pdi, s, sl, d);
            }
        }

        // CmdBlitImage
        TransferParams(format::HandleId                   s,
                       VkImageLayout                      sl,
                       VkImageLayout                      dl,
                       const VulkanImageInfo*             img_info,
                       VkFilter                           f,
                       const graphics::VulkanDeviceTable& dt,
                       const VulkanDeviceInfo*            pdi,
                       bool                               bc,
                       TransferCommandTypes               t) :
            params(std::make_unique<BlitImage>(t, bc, dt, pdi, s, sl, dl, img_info, f))
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdBlitImage);

            if (bc)
            {
                before_params = std::make_unique<BlitImage>(t, bc, dt, pdi, s, sl, dl, img_info, f);
            }
        }

        // CmdBuildAccelerationStructuresKHR
        TransferParams(const graphics::VulkanDeviceTable& dt,
                       const VulkanDeviceInfo*            pdi,
                       bool                               bc,
                       TransferCommandTypes               t) :
            params(std::make_unique<BuildAccelerationStructure>(t, bc, dt, pdi))
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdBuildAccelerationStructures);

            if (bc)
            {
                before_params = std::make_unique<BuildAccelerationStructure>(t, bc, dt, pdi);
            }
        }

        // CmdCopyAccelerationStructureKHR
        TransferParams(format::HandleId                          s,
                       const VulkanAccelerationStructureKHRInfo* d,
                       VkCopyAccelerationStructureModeKHR        m,
                       const graphics::VulkanDeviceTable&        dt,
                       const VulkanDeviceInfo*                   pdi,
                       const CommonObjectInfoTable&              oit,
                       const VulkanPerDeviceAddressTrackers&     at,
                       bool                                      bc,
                       TransferCommandTypes                      t) :
            params(std::make_unique<CopyAccelerationStructure>(t, bc, dt, pdi, s, d, m, oit, at))
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdCopyAccelerationStructure);

            if (bc)
            {
                before_params = std::make_unique<CopyAccelerationStructure>(t, bc, dt, pdi, s, d, m, oit, at);
            }
        }

        std::unique_ptr<TransferParamsBase> params;
        std::unique_ptr<TransferParamsBase> before_params;
    };

  private:
    void GetDispatchTables(format::HandleId device_id);

    std::map<uint64_t, TransferParams> transfer_params_;

    CommandIndices                                    transfer_indices_;
    CommonObjectInfoTable&                            object_info_table_;
    const graphics::InstanceDispatchTablesMap&        instance_tables_;
    const graphics::DeviceDispatchTablesMap&          device_tables_;
    const VulkanReplayOptions&                        options_;
    VulkanDumpResourcesDelegate&                      delegate_;
    const util::Compressor*                           compressor_;
    const VkPhysicalDeviceMemoryProperties*           replay_device_phys_mem_props_;
    const VulkanPerDeviceAddressTrackers&             address_trackers_;
    const DumpResourcesAccelerationStructuresContext& acceleration_structures_context_;

    const graphics::VulkanInstanceTable* instance_table_;
    const graphics::VulkanDeviceTable*   device_table_;
    const VulkanDeviceInfo*              device_info_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GENERATED_VULKAN_REPLAY_DUMP_RESOURCES_TRANSFER_H
