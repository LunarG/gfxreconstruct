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

    VkResult DumpTransferCommands(uint64_t qs_index);

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

        // kInitBufferCommand
        struct InitBufferMetaCommand
        {
            InitBufferMetaCommand() = delete;

            InitBufferMetaCommand(format::HandleId b, const uint8_t* d_p, uint64_t size) :
                dst_buffer(b), data(d_p, d_p + size)
            {}

            format::HandleId dst_buffer;
            DumpedHostData   data;
        };

        // kInitImageCommand
        struct InitImageMetaCommand
        {
            InitImageMetaCommand() = delete;

            InitImageMetaCommand(format::HandleId i, VkImageAspectFlagBits a, const VulkanImageInfo* ii) :
                dst_image(i), aspect(a), copied_image(ii)
            {}

            format::HandleId      dst_image;
            VkImageAspectFlagBits aspect;
            CopiedImage           copied_image;
        };

        // CmdCopyBuffer
        struct CopyBuffer
        {
            CopyBuffer() = delete;

            CopyBuffer(format::HandleId s, format::HandleId d) : src_buffer(s), dst_buffer(d) {}

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
        struct CopyBufferToImage
        {
            CopyBufferToImage() = delete;

            CopyBufferToImage(format::HandleId sb, VkImageLayout dil, const VulkanImageInfo* ii) :
                src_buffer(sb), dst_image(ii->capture_id), dst_image_layout(dil), copied_image(ii)
            {}

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
        struct CopyImage
        {
            CopyImage() = delete;

            CopyImage(format::HandleId s, VkImageLayout sl, VkImageLayout dl, const VulkanImageInfo* img_info) :
                src_image(s), src_image_layout(sl), dst_image(img_info->capture_id), dst_image_layout(dl),
                copied_image(img_info)
            {}

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
        struct CopyImageToBuffer
        {
            CopyImageToBuffer() = delete;

            CopyImageToBuffer(format::HandleId s, VkImageLayout sl, format::HandleId d) :
                src_image(s), src_image_layout(sl), dst_buffer(d)
            {}

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
        struct BlitImage
        {
            BlitImage() = delete;

            BlitImage(
                format::HandleId s, VkImageLayout sl, VkImageLayout dl, const VulkanImageInfo* img_info, VkFilter f) :
                src_image(s),
                src_image_layout(sl), dst_image(img_info->capture_id), dst_image_layout(dl), copied_image(img_info),
                filter(f)
            {}

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
        struct BuildAccelerationStructure
        {
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
        struct CopyAccelerationStructure
        {
            CopyAccelerationStructure() = delete;

            CopyAccelerationStructure(format::HandleId                          s,
                                      const VulkanAccelerationStructureKHRInfo* d,
                                      VkCopyAccelerationStructureModeKHR        m,
                                      const graphics::VulkanDeviceTable&        dt,
                                      const CommonObjectInfoTable&              oit,
                                      const VulkanPerDeviceAddressTrackers&     at) :
                src_as(s),
                dst_as(d->capture_id), mode(m), vk_objects(dt, oit, at, d)
            {}

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
            params(std::in_place_type<InitBufferMetaCommand>, b, d_p, size),
            type(t), has_before_command(false), device_table_(dt), parent_device_info_(pdi)
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
            params(std::in_place_type<InitImageMetaCommand>, i, a, img_info),
            type(t), has_before_command(false), device_table_(dt), parent_device_info_(pdi)
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
            params(std::in_place_type<CopyBuffer>, s, d),
            type(t), has_before_command(bc), device_table_(dt), parent_device_info_(pdi)
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdCopyBuffer);

            if (bc)
            {
                before_params = CopyBuffer(s, d);
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
            params(std::in_place_type<CopyBufferToImage>, sb, dil, ii),
            type(t), has_before_command(bc), device_table_(dt), parent_device_info_(pdi)
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdCopyBufferToImage);

            if (bc)
            {
                before_params = CopyBufferToImage(sb, dil, ii);
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
            params(std::in_place_type<CopyImage>, s, sl, dl, img_info),
            type(t), has_before_command(bc), device_table_(dt), parent_device_info_(pdi)
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdCopyImage);

            if (bc)
            {
                before_params = CopyImage(s, sl, dl, img_info);
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
            params(std::in_place_type<CopyImageToBuffer>, s, sl, d),
            type(t), has_before_command(bc), device_table_(dt), parent_device_info_(pdi)
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdCopyImageToBuffer);

            if (bc)
            {
                before_params = CopyImageToBuffer(s, sl, d);
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
            params(std::in_place_type<BlitImage>, s, sl, dl, img_info, f),
            type(t), has_before_command(bc), device_table_(dt), parent_device_info_(pdi)
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdBlitImage);

            if (bc)
            {
                before_params = BlitImage(s, sl, dl, img_info, f);
            }
        }

        // CmdBuildAccelerationStructuresKHR
        TransferParams(const graphics::VulkanDeviceTable& dt,
                       const VulkanDeviceInfo*            pdi,
                       bool                               bc,
                       TransferCommandTypes               t) :
            params(std::in_place_type<BuildAccelerationStructure>),
            type(t), has_before_command(bc), device_table_(dt), parent_device_info_(pdi)
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdBuildAccelerationStructures);

            if (bc)
            {
                before_params = BuildAccelerationStructure();
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
            params(std::in_place_type<CopyAccelerationStructure>, s, d, m, dt, oit, at),
            before_params(std::in_place_type<CopyAccelerationStructure>, s, d, m, dt, oit, at), type(t),
            has_before_command(bc), device_table_(dt), parent_device_info_(pdi)
        {
            GFXRECON_ASSERT(t == TransferCommandTypes::kCmdCopyAccelerationStructure);

            if (!bc)
            {
                before_params = std::monostate();
            }
        }

        ~TransferParams()
        {
            if (parent_device_info_ == nullptr)
            {
                return;
            }

            const VkDevice parent_device = parent_device_info_->handle;
            if (const auto* init_image = std::get_if<InitImageMetaCommand>(&params))
            {
                if (init_image->copied_image.image != VK_NULL_HANDLE)
                {
                    device_table_.DestroyImage(parent_device, init_image->copied_image.image, nullptr);
                }

                if (init_image->copied_image.memory != VK_NULL_HANDLE)
                {
                    device_table_.FreeMemory(parent_device, init_image->copied_image.memory, nullptr);
                }
            }
            else if (const auto* copy_buffer = std::get_if<CopyBuffer>(&params))
            {
                for (const auto& region : copy_buffer->regions)
                {
                    if (region.vk_objects.buffer != VK_NULL_HANDLE)
                    {
                        device_table_.DestroyBuffer(parent_device, region.vk_objects.buffer, nullptr);
                    }

                    if (region.vk_objects.memory != VK_NULL_HANDLE)
                    {
                        device_table_.FreeMemory(parent_device, region.vk_objects.memory, nullptr);
                    }
                }
            }
            else if (const auto* copy_buffer_to_image = std::get_if<CopyBufferToImage>(&params))
            {
                if (copy_buffer_to_image->copied_image.image != VK_NULL_HANDLE)
                {
                    device_table_.DestroyImage(parent_device, copy_buffer_to_image->copied_image.image, nullptr);
                }

                if (copy_buffer_to_image->copied_image.memory != VK_NULL_HANDLE)
                {
                    device_table_.FreeMemory(parent_device, copy_buffer_to_image->copied_image.memory, nullptr);
                }
            }
            else if (const auto* copy_image = std::get_if<CopyImage>(&params))
            {
                if (copy_image->copied_image.image != VK_NULL_HANDLE)
                {
                    device_table_.DestroyImage(parent_device, copy_image->copied_image.image, nullptr);
                }

                if (copy_image->copied_image.memory != VK_NULL_HANDLE)
                {
                    device_table_.FreeMemory(parent_device, copy_image->copied_image.memory, nullptr);
                }
            }
            else if (const auto* copy_image_to_buffer = std::get_if<CopyImageToBuffer>(&params))
            {
                for (const auto& region : copy_image_to_buffer->regions)
                {
                    if (region.vk_objects.buffer != VK_NULL_HANDLE)
                    {
                        device_table_.DestroyBuffer(parent_device, region.vk_objects.buffer, nullptr);
                    }

                    if (region.vk_objects.memory != VK_NULL_HANDLE)
                    {
                        device_table_.FreeMemory(parent_device, region.vk_objects.memory, nullptr);
                    }
                }
            }
            else if (const auto* blit_image = std::get_if<BlitImage>(&params))
            {
                if (blit_image->copied_image.image != VK_NULL_HANDLE)
                {
                    device_table_.DestroyImage(parent_device, blit_image->copied_image.image, nullptr);
                }

                if (blit_image->copied_image.memory != VK_NULL_HANDLE)
                {
                    device_table_.FreeMemory(parent_device, blit_image->copied_image.memory, nullptr);
                }
            }
            else if (const auto* build_as = std::get_if<BuildAccelerationStructure>(&params))
            {
                for (const auto& build_info : build_as->build_infos)
                {
                    if (build_info.vk_objects.as != VK_NULL_HANDLE)
                    {
                        device_table_.DestroyAccelerationStructureKHR(parent_device, build_info.vk_objects.as, nullptr);
                    }

                    if (build_info.vk_objects.buffer != VK_NULL_HANDLE)
                    {
                        device_table_.DestroyBuffer(parent_device, build_info.vk_objects.buffer, nullptr);
                    }

                    if (build_info.vk_objects.memory != VK_NULL_HANDLE)
                    {
                        device_table_.FreeMemory(parent_device, build_info.vk_objects.memory, nullptr);
                    }
                }
            }
            else if (const auto* copy_as = std::get_if<CopyAccelerationStructure>(&params))
            {
                if (copy_as->vk_objects.as != VK_NULL_HANDLE)
                {
                    device_table_.DestroyAccelerationStructureKHR(parent_device, copy_as->vk_objects.as, nullptr);
                }

                if (copy_as->vk_objects.buffer != VK_NULL_HANDLE)
                {
                    device_table_.DestroyBuffer(parent_device, copy_as->vk_objects.buffer, nullptr);
                }

                if (copy_as->vk_objects.memory != VK_NULL_HANDLE)
                {
                    device_table_.FreeMemory(parent_device, copy_as->vk_objects.memory, nullptr);
                }
            }
        }

        std::variant<std::monostate,
                     InitBufferMetaCommand,
                     InitImageMetaCommand,
                     CopyBuffer,
                     CopyBufferToImage,
                     CopyImage,
                     CopyImageToBuffer,
                     BlitImage,
                     BuildAccelerationStructure,
                     CopyAccelerationStructure>
            params;

        std::variant<std::monostate,
                     InitBufferMetaCommand,
                     InitImageMetaCommand,
                     CopyBuffer,
                     CopyBufferToImage,
                     CopyImage,
                     CopyImageToBuffer,
                     BlitImage,
                     BuildAccelerationStructure,
                     CopyAccelerationStructure>
            before_params;

        TransferCommandTypes type;

        bool has_before_command;

        DumpedResourcesInfo dumped_resources;

        const graphics::VulkanDeviceTable& device_table_;
        const VulkanDeviceInfo*            parent_device_info_;
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
