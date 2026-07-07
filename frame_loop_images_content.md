# Image Content Restoration during Frame Looping

During frame looping, GFXReconstruct restores buffer memory contents and image layouts at the loop boundary. However, the replayer currently does **not** restore the pixel contents of image memory (textures, offscreen render targets, shadow maps).

For games where render passes do not clear their attachments (`loadOp != CLEAR`), the rendering results inside offscreen textures mutate and accumulate across loop iterations, causing rendering drift or visual mismatches (screenshot failures) between iterations.

This document describes the design for implementing **Image Content Restoration** to solve this issue.

---

## Proposed Design: Shadow Image Backup & Restore

To restore image contents at the loop boundary, we propose a **Shadow Image** backing mechanism, similar to how we use shadow buffers for buffer memory.

### 1. Image Mutation Identification
We can leverage the existing `loop_touched_images_` set, which tracks all images referenced by command buffers submitted inside the frame loop. To minimize overhead, we should filter this set to identify only **mutated images**:
*   An image is considered mutated if it is transitioned to a write-permitted layout inside the loop (e.g., `COLOR_ATTACHMENT_OPTIMAL`, `DEPTH_STENCIL_ATTACHMENT_OPTIMAL`, `GENERAL`, `TRANSFER_DST_OPTIMAL`, `SHARED_PRESENT_KHR`), or if it is the target of an explicit Vulkan write command (copy, blit, clear, resolve).
*   Images that are only read from (`SHADER_READ_ONLY_OPTIMAL` or `DEPTH_READ_ONLY_OPTIMAL`) do **not** need content restoration.

### 2. Lazy Backup at Queue Submit (Iteration 1 Setup)
Since we do not know which images will be mutated before replaying the loop, and we cannot easily inject copy commands inside pre-recorded command buffers, we perform **Lazy Backup at Queue Submit** during the first iteration:

1.  **Intercept Queue Submit**: Intercept `vkQueueSubmit` calls during the first loop iteration (`IsLoopFirstIteration()`).
2.  **Identify Target Images**: For each command buffer in the submission, retrieve all images it touches. Note that "touched" images include both mutated render targets and read-only textures (e.g. sampled textures bound to descriptor sets).
3.  **Static Write-Capability & Transfer Filter**: For each touched image, inspect its creation usage flags (`VkImageUsageFlags`):
    *   If the image only has read-only flags and lacks write-permitted flags (`COLOR_ATTACHMENT`, `DEPTH_STENCIL_ATTACHMENT`, `STORAGE`, `TRANSFER_DST`), skip it entirely.
    *   If the image has `VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT`, it exists only in tile/lazily allocated memory during render passes and cannot be copied or preserved; skip it entirely.
    *   If the image lacks `VK_IMAGE_USAGE_TRANSFER_SRC_BIT` or `VK_IMAGE_USAGE_TRANSFER_DST_BIT`, it cannot legally be copied via `vkCmdCopyImage`; skip it entirely.
4.  **Lazy Shadow Image Creation**: For each remaining mutable image that has not been backed up yet:
    *   Create a corresponding **Shadow Image** on the GPU with identical properties (format, extent, mips, layers, samples).
    *   Allocate GPU memory for it.
5.  **Copy Content Before Execution**:
    *   Since Vulkan execution is asynchronous, the GPU has not yet executed the submitted command buffer. The original image content on the GPU is still in its initial loop-start state.
    *   Record and submit a separate helper command buffer containing a `vkCmdCopyImage` call (original -> shadow) *before* submitting the game's command buffer.
    *   Transition the layouts appropriately (`TRANSFER_SRC` for original, `TRANSFER_DST` for shadow) during the copy and restore the original layout afterward.
    *   Mark the image as backed up in a global set (`shadow_images_`).

This ensures we capture the exact initial loop-start content of each mutated image right before the GPU writes to it, without requiring pre-analysis or complex command buffer injection.

---

### 3. Image Content Restoration (At Loop Boundary, Iteration 2+)
At the end of each iteration (in `ResetLoopBoundary`), before replaying the next iteration:
1.  For each mutated image, execute a GPU copy back from its **Shadow Image**:
    *   Transition the original image to `VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL`.
    *   Transition the shadow image to `VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL`.
    *   Execute `vkCmdCopyImage` (shadow image -> original image).
    *   Transition the original image back to its tracked loop-start layout.
2.  Synchronize the restoration queue submissions before starting the next loop iteration.

---

## Optimizations & Layout Rules

### 1. Undefined Initial Layout Filtering
*   Per the Vulkan specification (`VUID-VkImageMemoryBarrier-newLayout-01198`), transitioning to `VK_IMAGE_LAYOUT_UNDEFINED` or `VK_IMAGE_LAYOUT_PREINITIALIZED` is invalid. Furthermore, any image starting in an undefined layout has undefined/discarded contents upon any subsequent layout transition.
*   Therefore, `LazyBackupImagesForSubmit` inspects recorded initial subresource layouts and automatically **skips shadow image creation and content backup** for any image whose initial subresource layouts are all `VK_IMAGE_LAYOUT_UNDEFINED` or `VK_IMAGE_LAYOUT_PREINITIALIZED`.
*   Similarly, during loop restoration (`RestoreImageContents`), any individual subresource whose initial layout was undefined is skipped from copy operations and pre/post transition barriers.

### 2. Clear-on-Load Render Targets
*   If an image is only written to as a render pass attachment with `loadOp == VK_ATTACHMENT_LOAD_OP_CLEAR`, its contents are cleared by the driver at the start of rendering anyway.
*   For such images, we do **not** need to backup or restore their pixel contents; we only need to restore their layout. This saves copy overhead and GPU memory.

---

## Cleanup and Resource Tracking
To ensure zero memory leaks across replay execution:
1.  **Direct Parent Tracking**: Both `ShadowBufferInfo` and `ShadowImageInfo` explicitly store the capture device ID (`parent_id`). When shadow resources are cleaned up, allocator lookups use `parent_id` directly so resource destruction succeeds even if the original image/buffer object info record was previously removed from `GetObjectInfoTable()`.
2.  **Destructor Lifecycle Cleanup**: All shadow image resources (`shadow_image`, `shadow_memory`), shadow buffers, and restoration command pools are cleanly destroyed inside `~VulkanReplayFrameLoopConsumer()`. Because `CreateShadowImage` outputs the allocated GPU memory handle (`shadow_memory`), intermediate and final destruction routines dispose of all underlying memory allocations without triggering Vulkan Object Tracking warnings.
