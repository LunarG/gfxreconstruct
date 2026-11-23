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

#ifndef GFXRECON_DECODE_VULKAN_STAGE_FRAME_LOOP_FIXUP_H
#define GFXRECON_DECODE_VULKAN_STAGE_FRAME_LOOP_FIXUP_H

#include "decode/common_object_info_table.h"
#include "decode/vulkan_pnext_node.h"
#include "decode/vulkan_resource_allocator.h"
#include "decode/vulkan_temporary_objects.h"
#include "generated/generated_vulkan_consumer_stage.h"
#include "generated/generated_vulkan_dispatch_table.h"
#include "graphics/frame_loop_info.h"
#include "graphics/vulkan_image_layout_map.h"

#include <functional>
#include <limits>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

/// The dispatch tables that the replay consumer made for the instances and devices it created. The stage calls Vulkan
/// directly through them.
struct VulkanDispatchTableLookup
{
    std::function<const graphics::VulkanInstanceTable*(const void* handle)> get_instance_table;
    std::function<const graphics::VulkanDeviceTable*(const void* handle)>   get_device_table;
};

/// Returns true when a VkFrameBoundaryEXT in the chain ends a frame.
bool IsFrameEndBoundary(const PNextNode* pnext);

/// This stage puts the device resources back in the state they were in when the frame loop started, before each
/// repetition of the loop:
/// - fences and host visible events go back to their signaled and set states,
/// - binary semaphores that the loop leaves signaled are waited on, and those that the loop waits on without
///   signaling are signaled. Timeline semaphores that moved are created again at their start value,
/// - buffers and images get their contents back from shadow copies, and images get their layouts back.
///
/// The stage records the state when the loop starts, and again when trim state finishes loading while the loop runs.
/// It restores the state after the replay consumer handles a present or a submit that ends a frame. It reads the
/// handles and the image layouts from the object info table of the replay consumer, so the image layout stage has to
/// come after it.
///
/// To copy buffers and images, the stage adds the transfer usages to the buffers and images that the app creates.
class VulkanStageFrameLoopFixup : public VulkanConsumerStage
{
  public:
    VulkanStageFrameLoopFixup(CommonObjectInfoTable&    object_info_table,
                              graphics::FrameLoopInfo&  frame_loop_info,
                              VulkanDispatchTableLookup dispatch_tables);

    ~VulkanStageFrameLoopFixup() override;

    // Loop start

    void StartLooping() override;
    void ProcessStateEndMarker(uint64_t frame_number) override;

    // Devices

    void Process_vkDestroyDevice(const ApiCallInfo& call_info, args::DestroyDevice& args) override;

    // Resources

    void Process_vkCreateBuffer(const ApiCallInfo& call_info, args::CreateBuffer& args) override;
    void Process_vkCreateImage(const ApiCallInfo& call_info, args::CreateImage& args) override;

    // Synchronization objects

    void Process_vkCreateFence(const ApiCallInfo& call_info, args::CreateFence& args) override;
    void Process_vkDestroyFence(const ApiCallInfo& call_info, args::DestroyFence& args) override;
    void Process_vkCreateEvent(const ApiCallInfo& call_info, args::CreateEvent& args) override;
    void Process_vkDestroyEvent(const ApiCallInfo& call_info, args::DestroyEvent& args) override;
    void Process_vkCreateSemaphore(const ApiCallInfo& call_info, args::CreateSemaphore& args) override;
    void Process_vkDestroySemaphore(const ApiCallInfo& call_info, args::DestroySemaphore& args) override;

    // Submits and presents

    void Process_vkQueueSubmit(const ApiCallInfo& call_info, args::QueueSubmit& args) override;
    void Process_vkQueueSubmit2(const ApiCallInfo& call_info, args::QueueSubmit2& args) override;
    void Process_vkQueueSubmit2KHR(const ApiCallInfo& call_info, args::QueueSubmit2KHR& args) override;
    void Process_vkQueueBindSparse(const ApiCallInfo& call_info, args::QueueBindSparse& args) override;
    void Process_vkAcquireNextImageKHR(const ApiCallInfo& call_info, args::AcquireNextImageKHR& args) override;
    void Process_vkAcquireNextImage2KHR(const ApiCallInfo& call_info, args::AcquireNextImage2KHR& args) override;
    void Process_vkQueuePresentKHR(const ApiCallInfo& call_info, args::QueuePresentKHR& args) override;

  private:
    struct FenceTracking
    {
        std::unordered_map<format::HandleId, bool> initial_fence_states_;
    };

    struct EventTracking
    {
        std::unordered_map<format::HandleId, bool> initial_event_states_;
    };

    struct SemaphoreTracking
    {
        SemaphoreTracking(VkDevice                           device,
                          const graphics::VulkanDeviceTable& device_table,
                          CommonObjectInfoTable&             object_table) :
            device_(device),
            device_table_(device_table), object_table_(object_table)
        {}

        /// Semaphores waited on by any submit inside the loop range that are expected
        /// to be signaled by a submission enqueued before start looping.
        /// These semaphores will be synthetically signaled before repeating the loop range.
        std::unordered_set<format::HandleId> before_loop_signaled_semaphores_;

        /// Semaphores signaled by any submit inside the loop range that are expected
        /// to be waited by a submission enqueued after looping.
        /// These semaphores will be synthetically waited on before repeating the loop range.
        std::unordered_set<format::HandleId> in_loop_signaled_semaphores_;

        /// Timeline semaphore values at the start of the loop range.
        std::unordered_map<format::HandleId, uint64_t> initial_timeline_values_;

        bool IsBinary(format::HandleId semaphore) const;

        void ClassifySignal(format::HandleId semaphore);
        void ClassifyWait(format::HandleId semaphore);

        void TrackSemaphores(const args::QueueSubmit& submit_info);
        void TrackSemaphores(const args::QueueSubmit2KHR& submit_info);
        void TrackSemaphores(const args::QueueSubmit2& submit_info);
        void TrackSemaphores(const args::QueuePresentKHR& present_info);
        void TrackSemaphores(const args::AcquireNextImageKHR& acquire_info);
        void TrackSemaphores(const args::AcquireNextImage2KHR& acquire_info);

        void TrackTimelineValue(format::HandleId semaphore);

        void FixupSemaphores(format::HandleId queue);
        void FixupBinarySemaphores(format::HandleId queue);
        void FixupTimelineSemaphores(format::HandleId queue);

        bool IsFixable(const VulkanSemaphoreInfo* semaphore_info) const;

        VkDevice                           device_;
        const graphics::VulkanDeviceTable& device_table_;
        CommonObjectInfoTable&             object_table_;
    };

    /// Tracks a device-local copy of each buffer's contents at the start of the loop range so that GPU
    /// writes made to the buffer during the loop can be undone before each repetition.
    struct BufferTracking
    {
        BufferTracking(format::HandleId                         device_id,
                       const graphics::VulkanDeviceTable&       device_table,
                       CommonObjectInfoTable&                   object_table,
                       std::shared_ptr<VulkanResourceAllocator> allocator,
                       const VkPhysicalDeviceMemoryProperties*  memory_properties) :
            device_id_(device_id),
            device_table_(device_table), object_table_(object_table), allocator_(allocator),
            memory_properties_(memory_properties)
        {}

        // A shadow buffer is only ever the source or destination of a vkCmdCopyBuffer.
        static constexpr VkBufferUsageFlags kShadowBufferUsage =
            VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT;

        // Allocations that shadow buffers are suballocated from.
        struct MemoryBlock
        {
            /// `allocator` has to outlive the memory block.
            explicit MemoryBlock(VulkanResourceAllocator& allocator) : allocator(&allocator) {}

            ~MemoryBlock() { Free(); }

            // A memory block owns its allocation, so it can be moved but not copied.
            MemoryBlock(const MemoryBlock&)            = delete;
            MemoryBlock& operator=(const MemoryBlock&) = delete;

            MemoryBlock(MemoryBlock&& other) noexcept :
                memory(other.memory), mem_data(other.mem_data), size(other.size), next_offset(other.next_offset),
                allocator(other.allocator)
            {
                other.memory = VK_NULL_HANDLE;
            }

            MemoryBlock& operator=(MemoryBlock&& other) noexcept
            {
                if (this != &other)
                {
                    Free();

                    memory      = other.memory;
                    mem_data    = other.mem_data;
                    size        = other.size;
                    next_offset = other.next_offset;
                    allocator   = other.allocator;

                    other.memory = VK_NULL_HANDLE;
                }

                return *this;
            }

            /// Allocates `allocation_size` bytes of `memory_type_index` for the block to suballocate from.
            bool Allocate(uint32_t memory_type_index, VkDeviceSize allocation_size);

            /// Suballocates memory from this block and binds `shadow` to it.
            VkResult Bind(const TemporaryBuffer& shadow);

            VkDeviceMemory                      memory{ VK_NULL_HANDLE };
            VulkanResourceAllocator::MemoryData mem_data{ 0 };
            VkDeviceSize                        size{ 0 };
            VkDeviceSize                        next_offset{ 0 };
            VulkanResourceAllocator*            allocator{ nullptr };

          private:
            void Free()
            {
                if (memory != VK_NULL_HANDLE)
                {
                    GFXRECON_ASSERT(allocator != nullptr);
                    allocator->FreeMemoryDirect(memory, nullptr, mem_data);
                }
            }
        };

        /// A shadow buffer that has been created, but not yet suballocated from a memory block.
        struct PendingShadowBuffer
        {
            PendingShadowBuffer(format::HandleId buffer_id, TemporaryBuffer&& shadow_buffer) :
                buffer_id(buffer_id), shadow(std::move(shadow_buffer))
            {}

            /// Copys buffer with matching `buffer_id` into shadow
            void CopyBuffer(const graphics::VulkanDeviceTable& device_table,
                            CommonObjectInfoTable&             object_table,
                            VkCommandBuffer                    command_buffer) const;

            format::HandleId buffer_id{ format::kNullHandleId };
            TemporaryBuffer  shadow;
        };

        void RecordInitialState(const std::vector<format::HandleId>& buffer_ids);
        void Restore();
        void DestroyShadowBuffers();

        // Spec required minimum for maxMemoryAllocationSize.
        static constexpr VkDeviceSize kMaxMemoryBlockSize = 1024ull * 1024ull * 1024ull;

        static constexpr size_t kInvalidBlockIndex = std::numeric_limits<size_t>::max();

        size_t AddMemoryBlock(uint32_t memory_type_index, VkDeviceSize preferred_size, VkDeviceSize minimum_size);

        /// The largest block that may be allocated from `memory_type_index`.
        static VkDeviceSize MaxBlockSize(const VkPhysicalDeviceMemoryProperties& memory_properties,
                                         uint32_t                                memory_type_index);

        format::HandleId                         device_id_;
        const graphics::VulkanDeviceTable&       device_table_;
        CommonObjectInfoTable&                   object_table_;
        std::shared_ptr<VulkanResourceAllocator> allocator_;
        const VkPhysicalDeviceMemoryProperties*  memory_properties_;
        std::vector<MemoryBlock>                 memory_blocks_;

        /// A device local copy of each buffer's contents, taken at the start of the loop range and copied back
        /// over the buffer before each repetition.  Their memory is suballocated from `memory_blocks_`, which
        /// have to outlive them, and prefers being device local when possible.
        std::unordered_map<format::HandleId, TemporaryBuffer> shadow_buffers_;
    };

    struct ImageTracking
    {
        ImageTracking(format::HandleId                         device_id,
                      const graphics::VulkanDeviceTable&       device_table,
                      CommonObjectInfoTable&                   object_table,
                      std::shared_ptr<VulkanResourceAllocator> allocator,
                      const VkPhysicalDeviceMemoryProperties*  memory_properties) :
            device_id_(device_id),
            device_table_(device_table), object_table_(object_table), allocator_(allocator),
            memory_properties_(memory_properties)
        {}

        struct ImageState
        {
            graphics::ImageLayoutMap initial_layouts;

            VkImage                               shadow_image{ VK_NULL_HANDLE };
            VkDeviceMemory                        shadow_memory{ VK_NULL_HANDLE };
            VulkanResourceAllocator::ResourceData alloc_data{ 0 };
            VulkanResourceAllocator::MemoryData   mem_data{ 0 };

            std::vector<VkImageSubresourceRange> copyable_ranges;

            std::vector<VkImageSubresourceRange> excluded_ranges;

            std::vector<VkImageCopy> copy_regions;

            VkImageSubresourceRange shadow_range{};

            bool HasShadow() const { return shadow_image != VK_NULL_HANDLE; }
        };

        struct RestoreCommands
        {
            // Puts every copyable subresource of each source image into VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL.
            std::vector<VkImageMemoryBarrier> pre_barriers;

            // Transitions subresources to their initial recorded layouts.
            std::vector<VkImageMemoryBarrier> post_barriers;

            // Images whose contents are copied back out of their shadow.
            std::vector<format::HandleId> copy_ids;

            std::vector<std::pair<format::HandleId, VkImageLayout>> layout_updates;

            bool built{ false };
        };

        void RecordInitialState(const std::vector<format::HandleId>& image_ids,
                                const std::vector<format::HandleId>& restorable_image_ids);

        void Restore(format::HandleId queue);

        void DestroyShadowImages();

        bool CreateShadowImage(format::HandleId image_id, const VulkanImageInfo* image_info, ImageState& state);
        void DestroyShadowImage(ImageState& state);

        void BuildRestoreCommands();

        format::HandleId                                 device_id_;
        const graphics::VulkanDeviceTable&               device_table_;
        CommonObjectInfoTable&                           object_table_;
        std::shared_ptr<VulkanResourceAllocator>         allocator_;
        const VkPhysicalDeviceMemoryProperties*          memory_properties_;
        std::unordered_map<format::HandleId, ImageState> image_states_;
        RestoreCommands                                  restore_commands_;
    };

    template <typename ArgsT>
    void ProcessQueueSubmit(const ApiCallInfo& call_info, ArgsT& args);

    /// Records the state that each repetition of the loop starts from.
    void RecordLoopStartState();

    /// Drops the recorded state, and frees the shadow copies.
    void ResetTracking();

    /// Waits for the device of the queue, and puts its resources back in the state that the loop started from.
    void EndFrame(format::HandleId queue);

    const graphics::VulkanInstanceTable* GetInstanceTable(const void* handle) const;
    const graphics::VulkanDeviceTable*   GetDeviceTable(const void* handle) const;

    /// The memory properties that replay allocates with on the physical device of the device.
    const VkPhysicalDeviceMemoryProperties* GetMemoryProperties(const VulkanDeviceInfo* device_info) const;

    void TrackFenceStates();
    void TrackFenceState(format::HandleId device, format::HandleId fence);
    void FixupDeviceFences(format::HandleId device, format::HandleId queue);

    void TrackEventStates();
    void TrackEventState(format::HandleId device, format::HandleId event);
    void FixupDeviceEvents(format::HandleId device);

    SemaphoreTracking& GetSemaphoreTracking(format::HandleId device);
    void               TrackSemaphoreStates();

    BufferTracking& GetBufferTracking(format::HandleId device);
    void            RecordBufferStates();
    void            FixupDeviceBuffers(format::HandleId device);
    void            ResetBufferTracking();
    void            ResetBufferTracking(format::HandleId device);

    ImageTracking& GetImageTracking(format::HandleId device);
    bool           CanSnapshotImageContents(const VulkanImageInfo* image_info) const;
    void           TrackImageStates();
    void           FixupDeviceImages(format::HandleId device, format::HandleId queue);
    void           ResetImageTracking();
    void           ResetImageTracking(format::HandleId device);

    void FixupDeviceObjects(format::HandleId device, format::HandleId queue);

    CommonObjectInfoTable&    object_info_table_;
    graphics::FrameLoopInfo&  frame_loop_info_;
    VulkanDispatchTableLookup dispatch_tables_;

    /// Events and semaphores that the app created inside the loop range, and has not destroyed yet. They have no
    /// state from before the loop to go back to.
    std::unordered_set<format::HandleId> loop_created_objects_;

    std::unordered_map<format::HandleId, FenceTracking> per_device_fence_tracking_;

    std::unordered_set<format::HandleId>                host_visible_events_;
    std::unordered_map<format::HandleId, EventTracking> per_device_event_tracking_;

    std::unordered_map<format::HandleId, SemaphoreTracking> per_device_semaphore_tracking_;

    std::unordered_map<format::HandleId, BufferTracking> per_device_buffer_tracking_;

    /// Images created with the transfer usages, whose contents the stage can copy.
    std::unordered_set<format::HandleId> restorable_images_;

    std::unordered_map<format::HandleId, ImageTracking> per_device_image_tracking_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_DECODE_VULKAN_STAGE_FRAME_LOOP_FIXUP_H
