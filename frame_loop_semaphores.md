# Semaphore Synchronization Design for Frame Looping

When GFXReconstruct replays a recorded trace in **Frame Looping Mode** (`--loop-frames <N>`), a range of frames is executed repeatedly in a continuous cycle. While resource memory and image layouts can be restored at loop boundaries via shadow backing, GPU execution synchronization relies on Vulkan **Semaphores** (`VkSemaphore`).

Because recorded command streams encode static synchronization states and timeline counter values, repeating these streams without modification causes Vulkan API specification violations and validation errors.

This document describes the design and architecture for solving binary and timeline semaphore synchronization across loop boundaries in GFXReconstruct.

---

## 1. Analysis of Synchronization Problems

During hardware validation of benchmark traces (such as *War Thunder*), three distinct semaphore synchronization failures occur at loop boundaries:

### Problem 1: Unwaited Binary Semaphore Signaled at Loop End
* **Vulkan Error**: `VUID-vkQueueSubmit-pSignalSemaphores-00067`
* **Mechanism**: Inside the frame loop, a queue submission signals a binary semaphore $S_{out}$ (for example, a semaphore intended to trigger `vkQueuePresentKHR` or post-loop rendering outside the loop).
* **Failure**: At the loop boundary (`ResetLoopBoundary`), execution jumps back to Frame 1 without executing the external wait/present command. Consequently, $S_{out}$ remains in the **signaled** state on the GPU. When iteration 2 executes the submit that signals $S_{out}$ again, Vulkan validation triggers an error because binary semaphores must be unsignaled when signaled.

### Problem 2: Unsignaled Binary Semaphore Waited at Loop Start
* **Vulkan Error**: `VUID-vkQueueSubmit-pWaitSemaphores-03238`
* **Mechanism**: The first queue submission inside the frame loop waits on a binary semaphore $S_{in}$ that was signaled by an operation prior to the loop (such as pre-loop `vkAcquireNextImageKHR` or pre-loop compute setup).
* **Failure**: During iteration 1, $S_{in}$ is signaled and the wait succeeds, auto-resetting $S_{in}$ to the **unsignaled** state. When iteration 2 begins and re-executes the queue submission waiting on $S_{in}$, there is no preceding signal operation for $S_{in}$. The GPU queue stalls or validation fails due to waiting on an unsignaled semaphore.

### Problem 3: Timeline Semaphore Counter Monotonicity Violations
* **Vulkan Error**: `VUID-VkSubmitInfo-pSignalSemaphores-03242`
* **Mechanism**: Timeline semaphores (`VK_SEMAPHORE_TYPE_TIMELINE`) maintain a monotonically increasing 64-bit integer payload ($V$). A signal operation requiring target value $V_{target}$ must satisfy $V_{target} > V_{current}$.
* **Failure**: During iteration 1, recorded queue submissions signal timeline semaphore $T$ to static recorded values (e.g., $V = 3628 \rightarrow 3630$). At the end of iteration 1, the GPU counter for $T$ is $3630$. When iteration 2 re-executes the submit attempting to signal $V = 3628$, Vulkan validation rejects the submission because $3628 \le 3630$.

---

## 2. Proposed Design: Virtualization & Boundary Injection

To resolve these issues without altering the internal concurrency structure of recorded frames, we categorize semaphores touched inside the loop into **Binary Semaphores** and **Timeline Semaphores**, applying targeted restoration strategies to each.

```
       [Pre-Loop Setup] ---> Signals S_in (Acquire/Compute)
              |
              v
       /=================== LOOP BOUNDARY (Start) ===================\
       | Iteration k:                                                |
       |   1. QueueSubmit (Waits S_in) [Virtual Signal injected]     |
       |   2. QueueSubmit (Timeline V_rec + Offset_k)                |
       |   3. QueueSubmit (Signals S_out)                            |
       \==================== LOOP BOUNDARY (End) ====================/
              |
              +--- At ResetLoopBoundary:
                   1. Drain/Reset S_out (Dummy Wait / Virtual Replacement)
                   2. Signal S_in for Iteration k+1
                   3. Advance Timeline Offset: Offset_{k+1} += Delta_V
```

---

## 3. Solution for Binary Semaphores

### A. Tracking Loop Semaphore Usage
During the first loop iteration (`IsLoopFirstIteration()`), we inspect all queue submissions (`Process_vkQueueSubmit`, `Process_vkQueueSubmit2`) to build two sets for binary semaphores:
* `loop_waited_binary_semaphores_`: Binary semaphores waited on by any submit inside the loop.
* `loop_signaled_binary_semaphores_`: Binary semaphores signaled by any submit inside the loop.

### B. Resolving Loop-Start Waits ($S_{in}$)
For any binary semaphore $S_{in} \in \text{loop\_waited\_binary\_semaphores\_}$ that is waited on before being signaled inside the loop:
1. **Loop Boundary Signal Injection**: In `ResetLoopBoundary()` (before replaying iteration 2+), record and submit a helper queue submission (or host call `vkSignalSemaphore` if `VK_KHR_external_semaphore` / host query features permit, or a dummy submit signaling $S_{in}$).
2. **Handle Virtualization (Alternative)**: Substitute $S_{in}$ during loop replay with a freshly allocated virtual binary semaphore initialized to the signaled state at the start of each iteration.

### C. Resolving Loop-End Signals ($S_{out}$)
For any binary semaphore $S_{out} \in \text{loop\_signaled\_binary\_semaphores\_}$ that remains in the signaled state at the end of an iteration:
1. **Dummy Wait Consumption**: Inside `ResetLoopBoundary()`, submit an empty helper command buffer to an active GPU queue with $S_{out}$ as a wait semaphore (`pWaitSemaphores = &S_out`, `waitSemaphoreCount = 1`). This cleanly consumes the signal and resets $S_{out}$ to the unsignaled state prior to iteration 2.
2. **Shadow Semaphore Substitution**: If $S_{out}$ is connected to external presentation objects (swapchain), replace $S_{out}$ in loop submissions with an internal dummy binary semaphore that is reset at the boundary, avoiding swapchain state corruption.

---

## 4. Solution for Timeline Semaphores

### A. Virtual Monotonic Offset Tracking
Unlike binary semaphores, timeline semaphores cannot simply be reset. Instead, we apply a **Monotonic Virtual Offset** ($O_k$) to each timeline semaphore across loop iterations.

For each timeline semaphore $T$ touched in the loop:
1. **Record Iteration 1 Span**: During iteration 1, record the minimum observed timeline value ($V_{min}$) and maximum observed timeline value ($V_{max}$).
2. **Calculate Iteration Delta**: Let $\Delta V = V_{max} - V_{min} + 1$.
3. **Maintain Cumulative Offset**: Maintain a map `timeline_offsets_[T]`.
   * For iteration 1 ($k=1$), $O_1 = 0$.
   * At the end of each iteration $k$ (in `ResetLoopBoundary`), increment the offset:
     \[
     O_{k+1} = O_k + \Delta V
     \]

### B. Dynamic Value Rewrite on Queue Submissions
When processing queue submissions (`Process_vkQueueSubmit`, `Process_vkQueueSubmit2`, `Process_vkQueueSubmit2KHR`), inspect all timeline semaphore references:
* **Wait Values**: For each timeline wait semaphore $T_i$ with recorded value $V_{wait}$, rewrite the submitted value to:
  \[
  V'_{wait} = V_{wait} + O_k(T_i)
  \]
* **Signal Values**: For each timeline signal semaphore $T_j$ with recorded value $V_{signal}$, rewrite the submitted value to:
  \[
  V'_{signal} = V_{signal} + O_k(T_j)
  \]

### C. Host API Interception
To maintain consistency between GPU submissions and CPU synchronization queries inside the loop, the same offset rewrite $O_k(T)$ must be applied when intercepting host-side timeline operations:
* `Process_vkWaitSemaphores`: Rewrite `pValues[i] += O_k(T_i)`.
* `Process_vkGetSemaphoreCounterValue`: When returning the counter value to the replayer or application logic, subtract $O_k(T)$ from the queried GPU handle value.

### D. Loop Boundary Signal Injection for External Timeline Waits
If a timeline semaphore relies on a CPU signal (e.g., `vkSignalSemaphoreKHR`) recorded *prior* to the loop boundary, simply applying the virtual offset to GPU waits is insufficient. The GPU will hang waiting for a value that is never signaled in the loop. 
To resolve this:
* Inside `ResetLoopBoundary()`, identify all timeline semaphores used in the loop.
* Inject a single dummy `vkQueueSubmit` containing a `VkTimelineSemaphoreSubmitInfo`.
* Signal each timeline semaphore to its exact expected baseline value for the upcoming iteration ($V_{min} + O_{k+1}$). This guarantees that the first GPU wait in the next iteration is immediately satisfied without waiting for the missing out-of-loop CPU signal.

---

## 5. Implementation Roadmap

1. **Phase 1: Binary Semaphore Boundary Reset** (Completed)
   * Implemented binary semaphore classification.
   * In `ResetLoopBoundary()`, injected dummy queue wait submissions for pending signaled semaphores ($S_{out}$) and dummy signal submissions for external input semaphores ($S_{in}$).
2. **Phase 2: Timeline Semaphore Virtual Offsets & Boundary Signals** (Completed)
   * Created timeline trackers inside `VulkanReplayFrameLoopConsumer`.
   * Intercepted submit structs to apply $O_k$.
   * Injected dummy `vkQueueSubmit` at the loop boundary to manually signal timeline semaphores to their advanced expected values, preventing hangs on pipelined frames.
3. **Phase 3: Hardware Verification** (Completed)
   * Re-validated *War Thunder* (`war_thunder`) on Android hardware, confirming 0 loop-related synchronization validation messages, no timeouts, and identical cross-iteration screenshots.
