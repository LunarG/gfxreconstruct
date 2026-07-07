# GfxReconstruct Image Subresource Layout Tracking Refactor

## 1. Problem Statement
Currently, `VulkanImageInfo::current_layout` and `VulkanCommandBufferInfo::image_layout_barriers` store a single `VkImageLayout` enum per `VkImage`. This design is fundamentally broken for:
- **Depth/Stencil Images**: Frequently use split layouts (e.g., Depth=`VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL`, Stencil=`VK_IMAGE_LAYOUT_ATTACHMENT_OPTIMAL`).
- **Mipmapped Textures**: Applications often generate mipmaps by transitioning mip `N` to `SHADER_READ` while mip `N+1` is `COLOR_ATTACHMENT`.

When GfxReconstruct needs to know an image's layout (e.g., `RestoreImageLayouts` for loop replays, `WriteImage` for screenshots, or resource dumping), it reads the single `current_layout`. If the image has a split layout, this single enum is incorrect for at least one subresource. 

For frame looping, this causes `RestoreImageLayouts` to transition the entire image into the wrong layout, triggering validation errors (like `03100` and `00344`) on subsequent RenderPasses. Furthermore, since `RestoreImageLayouts` hardcodes `oldLayout = VK_IMAGE_LAYOUT_UNDEFINED` (as a hack to prevent GPU hangs from incorrect `oldLayouts`), it destroys persistent image data across loop iterations.

## 2. Proposed Architecture

### 2.1 Core Data Structures (`vulkan_object_info.h`)
We need a lightweight structure to track subresource layouts. Given that most images have a small number of mips/layers and are usually uniform, a flattened 1D array with a fast-path for uniform layouts is ideal.

```cpp
// Represents a tracking structure for image subresources.
class ImageSubresourceLayoutTracker {
public:
    ImageSubresourceLayoutTracker() = default;
    
    // Initialize the tracker based on the image's total mips, layers, and aspects.
    void Initialize(uint32_t mip_levels, uint32_t array_layers, VkImageAspectFlags aspects);

    // Update the layout for a specific subresource range.
    void SetLayout(const VkImageSubresourceRange& range, VkImageLayout layout);

    // Retrieve the layout for a specific subresource.
    VkImageLayout GetLayout(VkImageAspectFlagBits aspect, uint32_t mip_level, uint32_t array_layer) const;

    // Retrieve a list of all current subresource ranges and their layouts.
    // Useful for generating barriers to restore state.
    struct SubresourceLayout {
        VkImageSubresourceRange range;
        VkImageLayout layout;
    };
    std::vector<SubresourceLayout> GetAllLayouts() const;

private:
    // Fast path for 99% of images that are in a single uniform layout.
    bool is_uniform_ = true;
    VkImageLayout uniform_layout_ = VK_IMAGE_LAYOUT_UNDEFINED;
    
    // Flattened array for split layouts, indexed by:
    // (aspect_index * mip_levels * array_layers) + (mip_level * array_layers) + array_layer
    std::vector<VkImageLayout> subresource_layouts_;
};
```

Update the tracking structs:
```cpp
struct VulkanImageInfo {
    // ...
    // REMOVE: VkImageLayout current_layout;
    ImageSubresourceLayoutTracker subresource_layouts;
};

struct VulkanCommandBufferInfo {
    // ...
    // REMOVE: std::unordered_map<format::HandleId, VkImageLayout> image_layout_barriers;
    std::unordered_map<format::HandleId, ImageSubresourceLayoutTracker> image_layout_barriers;
};
```

### 2.2 Command Buffer Recording (Barrier Processing)
When the application records a command buffer, GfxReconstruct must intercept layout transitions and update `VulkanCommandBufferInfo::image_layout_barriers`.
**Affected Functions:** `OverrideCmdPipelineBarrier`, `OverrideCmdPipelineBarrier2`, `Process_vkCmdSetImageLayoutEXT`
**Action:** Iterate through `pImageMemoryBarriers` and call `SetLayout` on the command buffer's tracker using the provided `subresourceRange`.

### 2.3 RenderPass Layout Transitions
RenderPasses implicitly transition layouts at the end of the pass.
**Affected Functions:** `ApplyRenderPassFinalLayouts` (called during `vkCmdEndRenderPass`)
**Action:** Iterate through the RenderPass attachments. For each attachment, determine its `aspectMask` (e.g., `VK_IMAGE_ASPECT_DEPTH_BIT | VK_IMAGE_ASPECT_STENCIL_BIT`). Update the **command buffer's local tracker** (`command_buffer_info->image_layout_barriers`) for that specific aspect, carefully honoring `stencilFinalLayout` from `VkAttachmentDescriptionStencilLayout` if present. *(Note: The global image state is NOT updated here—it must wait until execution during Queue Submit).*

### 2.4 Queue Submit Processing
When a command buffer is submitted, its internal transitions must be merged into the global image state.
**Affected Functions:** `OverrideQueueSubmit`, `OverrideQueueSubmit2`
**Action:** For each command buffer being submitted, iterate through its local `image_layout_barriers` tracker and merge those subresource layout transitions into the global image state (`VulkanImageInfo::subresource_layouts`).

### 2.5 Frame Loop Consumer Refactor (`vulkan_replay_frame_loop_consumer.cpp`)
- **Execution-Time Snapshotting (`CollectTouchedImagesFromCommandBuffer`)**: To correctly capture the initial layout of images modified during the loop, we need to snapshot their state at **execution time** (when `vkQueueSubmit` is called), not at recording time (when `vkCmd*` functions are intercepted). Capturing at recording time fails for command buffers that were recorded before the loop started.
  - During the first loop iteration's `Process_vkQueueSubmit`, we will scan `cb_info->image_layout_barriers`, `cb_info->frame_buffer_ids`, and `cb_info->active_render_pass_attachment_image_view_ids` to identify which images the command buffer touches.
  - For each newly touched image, we will clone the global `VulkanImageInfo::subresource_layouts` into `initial_image_layouts_`. This will flawlessly capture the exact runtime layout the image had right before the frame loop modifies it.
- **`RestoreImageLayouts`**: 
  - Compare the global `VulkanImageInfo::subresource_layouts` (state at end of loop) with `initial_image_layouts_` (state before loop).
  - Generate a `VkImageMemoryBarrier` for every subresource range that differs.
  - Set `barrier.oldLayout = current_layout_for_subresource`. (**This will finally allow us to stop using `VK_IMAGE_LAYOUT_UNDEFINED`, preventing data loss!**)
  - Set `barrier.newLayout = initial_layout_for_subresource`.

### 2.6 Screenshot & Resource Dumping Fixes
**Affected Functions:** `WriteImage`, `CheckPNextChainForFrameBoundary`, `DumpImage`
**Action:** Instead of blindly passing `image_info->current_layout`, query the tracker for the specific subresource being dumped/captured. If the image has split layouts across mips, screenshots of `mip 0` will now correctly use the layout of `mip 0`.

## 3. Implementation Phases

**Phase 1: Core Data Structures**
- Implement `ImageSubresourceLayoutTracker` class.
- Replace single enum fields in `VulkanImageInfo` and `VulkanCommandBufferInfo`.
- Fix compile errors by stubbing calls to return `GetLayout(base_aspect, 0, 0)` temporarily.

**Phase 2: Recording and Queue Submit**
- Update PipelineBarrier and RenderPass processing to populate the subresource tracker accurately.
- Update `Process_vkQueueSubmit` to merge trackers in execution order.

**Phase 3: Frame Looping & Consumers**
- Rewrite `RecordInitialLayouts` and `RestoreImageLayouts` to use precise subresource barriers.
- Remove `VK_IMAGE_LAYOUT_UNDEFINED` from `RestoreImageLayouts`.
- Update Screenshot and Dumping utilities to query specific subresource layouts.
