# Buffer Content Restoration during Frame Looping

During frame looping, GFXReconstruct replays a specific range of frames repeatedly. Since GPU and compute shader workloads can mutate buffer contents (e.g., storage buffers, uniform texel buffers, copy destinations) during loop iterations, these mutations must be reverted at the loop boundary to prevent rendering drift or verification mismatch.

This document describes the design for tracking, backing up, and restoring Vulkan buffer contents across loop iterations.

---

## Design: Lazy Shadow Buffer Backup and Restore

To restore buffer contents at the loop boundary, GFXReconstruct implements a **Lazy Shadow Buffer** allocation and copy mechanism that mirrors the design used for images.

### 1. Enabling Copy Capability on All Buffers
Per the Vulkan specification, a buffer cannot be the source or destination of a transfer copy command unless it was created with `VK_BUFFER_USAGE_TRANSFER_SRC_BIT` and `VK_BUFFER_USAGE_TRANSFER_DST_BIT`.

To ensure we can copy any buffer at runtime, GFXReconstruct intercepts buffer creation:
*   **API Interception**: In `Process_vkCreateBuffer`, the replayer modifies the `VkBufferCreateInfo` struct before forwarding the call to the driver.
*   **Flag injection**: It dynamically appends `VK_BUFFER_USAGE_TRANSFER_SRC_BIT | VK_BUFFER_USAGE_TRANSFER_DST_BIT` to the `usage` flags.

This guarantees that all buffers created during setup or replay can legally participate in shadow copy operations.

### 2. Tracking Buffer Usage Across Command Buffers
Instead of snapshotting every buffer created in the entire application (including inactive auxiliary devices or unused buffers), GFXReconstruct tracks which buffers are actually referenced by submitted command buffers:

*   **Command Recording Interception**: Intercepts commands referencing or mutating buffers to populate `VulkanCommandBufferInfo::bound_buffers`:
    *   `vkCmdBindVertexBuffers`, `vkCmdBindVertexBuffers2`, `vkCmdBindVertexBuffers2EXT` (vertex buffers)
    *   `vkCmdBindIndexBuffer`, `vkCmdBindIndexBuffer2` (index buffers)
    *   `vkCmdDrawIndirect`, `vkCmdDrawIndexedIndirect`, `vkCmdDispatchIndirect` (indirect arguments)
    *   `vkCmdCopyBuffer`, `vkCmdCopyBufferToImage`, `vkCmdCopyImageToBuffer` (source and destination buffers)
    *   `vkCmdUpdateBuffer`, `vkCmdFillBuffer` (destination buffer)
    *   `vkCmdPipelineBarrier` (buffer memory barriers)
*   **Descriptor Set Tracking**: Intercepts `vkCmdBindDescriptorSets` / `vkCmdBindDescriptorSets2` to inspect bound descriptor sets and track all referenced buffer descriptors (storage buffers, uniform buffers, and texel buffer views).
*   **Secondary Command Buffer Propagation**: When `vkCmdExecuteCommands` is called, secondary command buffers are tracked and their `bound_buffers`, `bound_descriptor_sets`, and layout transitions are propagated to the primary command buffer. All executed secondary command buffers are also recursively traversed when collecting touched buffers.

### 3. Lazy Buffer State Backup (Before Queue Submit in Iteration 1)
When `vkQueueSubmit` / `vkQueueSubmit2` is called during the first loop iteration (`IsLoopFirstIteration()`):

1.  **Extract Submitted Command Buffers**: GFXReconstruct extracts the command buffers in the submit and calls `CollectTouchedBuffersFromCommandBuffer` to populate `loop_touched_buffers_`.
2.  **Filter Buffers**: For each touched buffer:
    *   Verify the buffer has a valid handle, non-zero size, and a valid device allocator.
    *   Verify the buffer belongs to the submitting queue's logical device (`dev_info->handle == device`).
    *   Verify the buffer has not already been snapshotted (`shadow_buffers_.find(buffer_id) == shadow_buffers_.end()`).
3.  **Allocate Shadow Buffers**: For each eligible buffer:
    *   Create a GPU-only shadow buffer (`shadow_buffer`) with matching size and transfer usage flags.
    *   Allocate and bind device local memory (`shadow_memory`).
    *   Track the allocation in `shadow_buffers_`.
4.  **Record and Submit Snapshot Copies**:
    *   Record a pipeline barrier ensuring previous writes are complete (`srcStageMask = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT | VK_PIPELINE_STAGE_HOST_BIT`, `dstStageMask = VK_PIPELINE_STAGE_TRANSFER_BIT`).
    *   Record `vkCmdCopyBuffer` from the original buffer to the shadow buffer.
    *   Submit the restoration command buffer and wait for idle before the workload command buffers execute.

This guarantees that pristine initial buffer contents are captured just before the GPU first touches them.

### 4. Buffer Content Restoration (At Loop Boundary, Iteration 2+)
At the end of each iteration (in `ResetLoopBoundary`), before replaying the loop range again:

1.  Begin recording the restoration command buffer (`restoration_command_buffer_`).
2.  For each backed up buffer in `shadow_buffers_`, record a copy from the shadow buffer back to the original buffer:
    *   `vkCmdCopyBuffer(shadow_buffer -> original_buffer)`
3.  Insert a post-transfer barrier to guarantee memory visibility for subsequent stages:
    *   `srcStageMask = VK_PIPELINE_STAGE_TRANSFER_BIT`
    *   `dstStageMask = VK_PIPELINE_STAGE_ALL_COMMANDS_BIT`
    *   `srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT`
    *   `dstAccessMask = VK_ACCESS_MEMORY_READ_BIT | VK_ACCESS_MEMORY_WRITE_BIT`
4.  Submit the restoration command buffer and wait for completion (`QueueWaitIdle`).

---

## Resource Cleanup
To prevent memory leaks:
*   All allocated shadow buffer handles (`shadow_buffer`) and their memory bindings (`shadow_memory`) are tracked in `shadow_buffers_`.
*   When the consumer is destroyed (`~VulkanReplayFrameLoopConsumer`), it calls `DestroyShadowBuffers()` to free all allocated memory and destroy all shadow buffer handles via their respective device allocators.
