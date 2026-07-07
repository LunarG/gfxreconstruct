# Query Pool and Timestamp Suppression during Frame Looping

Vulkan query pools (`VkQueryPool`) are used to gather statistics, execution timings (timestamps), and occlusion data from the GPU. However, replaying recorded query operations in a frame loop range without modification triggers Vulkan API validation errors and causes CPU wait stalls.

This document describes how GFXReconstruct manages and suppresses query operations during frame looping.

---

## 1. The Validation Challenge: "Query Not Reset"
According to the Vulkan specification, a query must be reset before it can be written to or activated:
*   A query pool reset must occur (via `vkCmdResetQueryPool` or `vkResetQueryPool`) on the host or queue before recording commands like `vkCmdWriteTimestamp` or `vkCmdBeginQuery` for that query.
*   **The Loop Problem**: In recorded trace files, the query reset and the query write are often in different frames. If a reset operation occurs in frame 5 (setup), and the query write operation occurs in frame 10 (which falls within the loop frame range, e.g. frames 10-12), the first loop iteration replays the write successfully. However, when the loop jumps back to frame 10 for iteration 2, the write operation is replayed **again** without a preceding reset.
*   This triggers Vulkan validation error `VUID-vkCmdWriteTimestamp-query-04891` (or similar for begin query calls) stating that the query must be in the reset state before writing.

---

## 2. Generator-Driven API Suppression

To solve this systematically without writing custom complex manual reset trackers for every query pool index, GFXReconstruct introduces a generator-driven suppression strategy.

### Replay Frame Loop Overrides Configuration
The python code generator configures a list of Vulkan API entry points that are designated to be skipped when frame looping is active. This list is defined under the `skipDuringLooping` category in:
*   [`replay_frame_loop_overrides.json`](file:///usr/local/google/home/okuznetsov/prj/gfxreconstruct/framework/generated/khronos_generators/vulkan_generators/replay_frame_loop_overrides.json)

### Codegen Implementation
During compilation, the Khronos generator parses `replay_frame_loop_overrides.json`. For any function in the `skipDuringLooping` array, the code generator emits a loop check inside `VulkanReplayFrameLoopConsumerBase`:

```cpp
// Example of generated base function body
void VulkanReplayFrameLoopConsumerBase::Process_vkCmdBeginQuery(
    const ApiCallInfo&           call_info,
    format::HandleId             commandBuffer,
    format::HandleId             queryPool,
    uint32_t                     query,
    VkQueryControlFlags          flags)
{
    if (getFrameLoopInfo().IsLooping())
    {
        // Skip completely if looping is active
        return;
    }
    VulkanReplayConsumer::Process_vkCmdBeginQuery(call_info, commandBuffer, queryPool, query, flags);
}
```

This automatically compiles out the processing of these API calls when frame looping is active, ensuring they are never re-submitted to the driver on repetitions.

---

## 3. List of Suppressed APIs

The following APIs are suppressed during frame looping to prevent validation errors and CPU sync stalls:

### Writing Queries & Timestamps (GPU side)
These commands record writes to queries inside command buffers. Skipping them prevents "query not reset" warnings when re-recording or submitting:
*   `vkCmdWriteTimestamp` / `vkCmdWriteTimestamp2` / `vkCmdWriteTimestamp2KHR`
*   `vkCmdBeginQuery` / `vkCmdBeginQueryIndexedEXT`
*   `vkCmdEndQuery` / `vkCmdEndQueryIndexedEXT`

### Resetting Queries
Resetting query pools during looping repetitions is skipped to avoid resetting active queries being processed asynchronously:
*   `vkCmdResetQueryPool`
*   `vkResetQueryPool` / `vkResetQueryPoolEXT`

### Fetching Results (Host/GPU copies)
If the application queries results or copies them to buffers, the replayer skips these calls because the queries themselves were skipped:
*   `vkGetQueryPoolResults`
*   `vkCmdCopyQueryPoolResults` / `vkCmdCopyQueryPoolResultsToMemoryKHR`
