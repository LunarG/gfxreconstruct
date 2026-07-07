# Buffer Content Restoration during Frame Looping

During frame looping, GFXReconstruct replays a specific range of frames repeatedly. Since GPU and compute shader workloads can mutate buffer contents (e.g., storage buffers, uniform texel buffers) during loop iterations, these mutations must be reverted at the loop boundary to prevent rendering drift or verification mismatch.

This document describes the design for backing up and restoring Vulkan buffer contents across loop iterations.

---

## Proposed Design: Shadow Buffer Backup and Restore

To restore buffer contents at the loop boundary, GFXReconstruct implements a **Shadow Buffer** allocation and copy mechanism.

### 1. Enabling Copy Capability on All Buffers
Per the Vulkan specification, a buffer cannot be the source or destination of a transfer copy command unless it was created with `VK_BUFFER_USAGE_TRANSFER_SRC_BIT` and `VK_BUFFER_USAGE_TRANSFER_DST_BIT`.

To ensure we can copy any buffer at runtime, GFXReconstruct intercepts buffer creation:
*   **API Interception**: In `Process_vkCreateBuffer`, the replayer modifies the `VkBufferCreateInfo` struct before forwarding the call to the driver.
*   **Flag injection**: It dynamically appends `VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT` to the `usage` flags.

This guarantees that all buffers created during setup or replay can legally participate in shadow copy operations.

### 2. Initial Buffer State Backup (At Loop Start)
When entering the loop (`OnLoopStart`), before replaying the loop range, GFXReconstruct captures the initial contents of all active buffers:

1.  **Initialize Restoration Resources**: Ensure a dedicated restoration command pool and command buffer (`restoration_command_buffer_`) are created for the target Vulkan logical device.
2.  **Pipeline Barrier Injection**: Begin recording the restoration command buffer and insert a execution barrier:
    *   `srcStageMask = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT`
    *   `dstStageMask = VK_PIPELINE_STAGE_TRANSFER_BIT`
    *   `srcAccessMask = VK_ACCESS_MEMORY_WRITE_BIT`
    *   `dstAccessMask = VK_ACCESS_TRANSFER_READ_BIT`
    This guarantees any previous GPU writes to the buffers are flushed and visible before we copy them.
3.  **Iterate and Create Shadow Buffers**: Iterate through all tracked buffers in the `VulkanObjectInfoTable`. For each active buffer:
    *   Verify the buffer's device allocator is valid and that its size is greater than zero.
    *   Create a corresponding GPU-only **Shadow Buffer** (`shadow_buffer`) with identical size and `VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT`.
    *   Allocate memory and bind it to the shadow buffer handle.
4.  **Record Copies**: Call `vkCmdCopyBuffer` to copy the original buffer contents to the shadow buffer.
5.  **Submit and Synchronize**: Close the command buffer, submit it to the active queue, and wait for completion (`vkQueueWaitIdle` or device wait idle). This ensures backup is fully completed on the GPU before replay begins.

### 3. Buffer Content Restoration (At Loop Boundary, Iteration 2+)
At the end of each iteration (in `ResetLoopBoundary`), before replaying the loop range again:

1.  Record a new set of copy commands onto `restoration_command_buffer_`.
2.  For each backed up buffer, record a copy back from the shadow buffer to the original buffer:
    *   `vkCmdCopyBuffer(shadow_buffer -> original_buffer)`
3.  Insert a post-transfer barrier to guarantee memory visibility for subsequent stages:
    *   `srcStageMask = VK_PIPELINE_STAGE_TRANSFER_BIT`
    *   `dstStageMask = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT`
    *   `srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT`
    *   `dstAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT`
4.  Submit the restoration command buffer and wait for completion.

---

## Resource Cleanup
To prevent memory leaks:
*   All allocated shadow buffer handles (`shadow_buffer`) and their memory bindings are tracked in a `shadow_buffers_` map.
*   When the consumer is destroyed (`~VulkanReplayFrameLoopConsumer`), it calls `DestroyShadowBuffers()` to free all allocated memory and destroy all shadow buffer handles.
