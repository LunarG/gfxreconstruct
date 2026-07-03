# Command Buffer Handling during Frame Looping

During frame looping, GFXReconstruct replays a specific range of frames (from `loop_start_frame` to `loop_end_frame`) repeatedly. This document describes how Vulkan command buffers (CBs) are managed across loop iterations.

## The Problem: Boundary-Spanning Command Buffers

Vulkan command buffers can be classified into two categories based on their lifetime relative to the loop boundary:

1.  **Loop-Internal CBs**: These command buffers are fully contained within the loop. Their lifecycle is:
    `vkBeginCommandBuffer` -> `vkCmd...` -> `vkEndCommandBuffer` -> `vkQueueSubmit` (all occurring inside the loop).
    Replaying these is straightforward: every loop iteration naturally replays the entire sequence, re-recording and submitting the CB.

2.  **Boundary-Spanning CBs**: These command buffers are begun *before* the loop start (in the setup phase), but have commands recorded, are ended, or are submitted *inside* the loop.
    *   **Iteration 1**: Replays normally (since setup occurred).
    *   **Iteration 2+**: Since the setup phase is skipped, `vkBeginCommandBuffer` is **not** replayed. However, any `vkCmd...` or `vkEndCommandBuffer` calls that occurred inside the loop range **are** replayed.
    *   If we reset the command pool at the loop boundary, these CBs are reset to the initial state. Replaying `vkCmd...` on them without `vkBeginCommandBuffer` causes Vulkan validation errors or crashes.

## Current Approaches and Their Limitations

### Approach A: Render Pass Filtering
Only command buffers that are actively recording inside an open render pass (`active_render_pass_id != format::kNullHandleId`) at loop start are preserved.
*   **Pros**: Works for traditional render-pass-based games where setup CBs (like staging copies) are executed outside render passes and can be safely recreated/re-begun.
*   **Cons**: 
    *   Breaks modern games using **Dynamic Rendering** (`vkCmdBeginRendering`) or compute-heavy workloads, where `active_render_pass_id` is always null (e.g., *Honkai: Star Rail*).
    *   Causes rendering regressions in games like *Alien: Isolation* where secondary command buffers (`17722`) containing pre-recorded draw calls are ended inside the loop. Since they are filtered out, they are recreated and re-begun, but ended empty inside the loop, losing their pre-recorded drawing commands.

### Approach B: Preserve All Recording CBs
All command buffers recording at loop start are preserved (added to `loop_start_recording_cbs_`), and their recording commands are ignored during loop iterations 2+.
*   **Pros**: Avoids crashes in dynamic rendering games.
*   **Cons**: Causes rendering regressions in games like *Alien: Isolation*. Since we reset the active command pools (like the pool of `7590` and `17722`) at the loop boundary, these preserved command buffers are implicitly reset to their initial state. Because we ignore their recording commands, we do not re-record them, and they are submitted empty.

---

## Proposed Design: Shadow Command Pools (Primary Solution)

To handle boundary-spanning command buffers correctly without memory leaks or losing pre-recorded drawing commands (as in *Alien: Isolation*), we propose a **Shadow Command Pool** allocation strategy.

### Key Concepts
1.  **Preservation of Boundary-Spanning CBs**: Instead of resetting or recreating boundary-spanning command buffers at the loop boundary, we preserve their recorded state and handles across all loop iterations.
2.  **Shadow Pools for In-Loop Allocations**: To prevent memory leaks from loop-internal command buffers without wiping the boundary-spanning ones, we segregate allocations.

### How it Works
1.  **Detection**: At `OnLoopStart`, identify all command pools that contain boundary-spanning command buffers (i.e. command buffers in the `recording_cbs_` set at the loop start boundary) and track them as requiring shadowing.
2.  **Lazy Shadow Pool Creation**: If the replayer intercepts a `vkAllocateCommandBuffers` call *inside* the frame loop targeting a pool marked as requiring shadowing, lazily create a corresponding "shadow" command pool (if it does not already exist) on the same logical device and queue family.
3.  **Allocation Redirection**: Redirect the allocation call to the shadow pool instead of the original pool.
4.  **Selective Pool Reset**: At the loop boundary (on every loop iteration), call `vkResetCommandPool` only on the **shadow pools** that were actually created (wiping the loop-internal command buffers). The original pools are **not** reset.
5.  **Ignored Recording Commands**: For preserved boundary-spanning command buffers, we continue to ignore any recording commands (`vkCmd...`, `vkBeginCommandBuffer`, `vkEndCommandBuffer`) replayed inside the loop using `ShouldIgnoreRecordingCommand`.
6.  **Normal Submission**: Replayed `vkQueueSubmit` calls submitting these preserved command buffers are executed normally, submitting the original recorded commands.

### Feasibility and Limitations
*   **Feasibility**: This works perfectly when boundary-spanning command buffers render to offscreen resources (like G-buffers or shadow maps) and the swapchain rendering is done in loop-internal command buffers (which is the case in *Alien: Isolation*).
*   **Limitation**: If a boundary-spanning command buffer directly references a swapchain image, the framebuffer bindings inside it cannot be dynamically updated to reflect swapchain image index changes without re-recording. (In such cases, re-recording is unavoidable).

---

## Alternative: Explicit Classification and Synthetic Recreation

An alternative approach is to classify and recreate command buffers at the loop boundary.

### How it Works
We classify any command buffer recording at loop start (`initial_loop_recording_cbs_`) into:
1.  **Static Setup/Staging CBs**: CBs performing one-time data uploads/transitions before the loop. We ignore their submissions (`vkQueueSubmit`) in iteration 2+.
2.  **Active Frame-Rendering CBs (including Dynamic Rendering)**: CBs actively recording geometry at the loop boundary. We synthetically recreate and re-begin them at the loop boundary, and replay their `vkCmd...` calls in iteration 2+.

### Detection Heuristic for Dynamic Rendering
To detect active rendering state:
*   `cb_info->active_render_pass_id != format::kNullHandleId` **OR**
*   `cb_info->in_render_pass` (if tracked) **OR**
*   The command buffer has recorded draw calls or compute dispatches before the loop start.

### Limitations
*   **Secondary CB Draw Loss**: If a secondary command buffer contains pre-recorded draw calls (recorded before loop start in `save_state`) but is ended inside the loop (as in *Alien: Isolation*), recreation will result in an empty command buffer, losing the drawing geometry entirely.
*   **Setup Command Loss**: Recreating and re-beginning a command buffer at the loop boundary results in a clean, empty command buffer. Any commands recorded in it during the setup/save-state phase (before the loop start) are completely lost unless the replayer caches and manually re-records them. Replaying only the target-frame commands (recorded inside the loop range) is insufficient because the command buffer will be missing essential state (like bound pipelines, descriptor sets, or vertex buffers) established during the setup phase.


