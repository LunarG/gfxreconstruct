# Fence and Event Synchronization Restoration

Replaying a trace in frame loop mode repeatedly submits the same command streams to the GPU. Since Vulkan Fences (`VkFence`) and Events (`VkEvent`) synchronize execution between the host (CPU) and device (GPU), their state must be restored at the loop boundary. If left unmanaged, fences and events remain in incorrect states, triggering validation errors (such as double-signaling) or CPU hangs (waiting for a signal that will never be triggered).

This document describes the design for restoring the states of Fences and Events at loop boundaries.

---

## 1. Fence State Restoration

Fences are mainly used for GPU-to-CPU synchronization, signaling the host when queue submissions or swapchain image acquisitions are finished.

### Initial Fence States Capture
During loop setup (`OnLoopStart`), the replayer queries the host-side state of all existing fences:
1.  Iterate through all active fences in the object tracking table (`VisitVkFenceInfo`).
2.  Use `vkGetFenceStatus` to query if the fence is currently in the `SIGNALED` (`VK_SUCCESS`) or `UNSIGNALED` (`VK_NOT_READY`) state.
3.  Store the status in a map `initial_fence_states_` keyed by the fence capture ID.

### Boundary Restoration
At the loop boundary (`ResetLoopBoundary`), before restarting the next iteration, GFXReconstruct checks if the current runtime state of each fence has drifted from its initial recorded state:
1.  Query `vkGetFenceStatus` for the current runtime status.
2.  Compare it against the initial captured status:
    *   **Case A (Unsignaled -> Signaled)**: If the fence was initially unsignaled (`VK_NOT_READY`) but is now signaled (`VK_SUCCESS`), the replayer calls `vkResetFences` to reset it back to the unsignaled state.
    *   **Case B (Signaled -> Unsignaled)**: If the fence was initially signaled (`VK_SUCCESS`) but is now unsignaled (`VK_NOT_READY`), the replayer must synthetically signal it. This is done by calling `vkQueueSubmit` on an active queue with zero command buffers but specifying the fence as the signal target.
3.  Fences that did not change state are skipped.

---

## 2. Event State Restoration

Events provide fine-grained synchronization within command buffers (GPU-to-GPU) or between host and device.

### Initial Event States Capture
During loop setup (`OnLoopStart`), the host-side state of events is queried:
1.  Iterate through all tracked events in `VisitVkEventInfo`.
2.  **Filter Device-Only Events**: If an event was created with `VK_EVENT_CREATE_DEVICE_ONLY_BIT`, it is not host-accessible. GFXReconstruct avoids calling host-side event queries on these to prevent driver faults and filters them out.
3.  For host-accessible events, query their status via `vkGetEventStatus`.
4.  Store if the event is set (`VK_EVENT_SET`) in `initial_event_states_`.

### Boundary Restoration
At the loop boundary:
1.  For each tracked host-accessible event, compare its state to the initial captured state.
2.  Call `vkSetEvent` on the host if it was initially set, or `vkResetEvent` if it was initially reset.

### In-Loop Lifecycle Safeguards
For events created or destroyed *inside* the loop range:
*   **Destruction Protection**: If an event is destroyed inside the loop, the replayer intercepts `Process_vkDestroyEvent` and skips the actual destruction on repeated loop iterations to prevent invalid handle errors when the loop restarts.
*   **Creation Protection**: If an event creation call `Process_vkCreateEvent` is replayed and an event with the same capture ID already exists (from a previous iteration), GFXReconstruct first calls `vkDestroyEvent` on the existing handle to release the driver resources and removes its tracked metadata before creating a new event handle. This prevents handle leaks.
