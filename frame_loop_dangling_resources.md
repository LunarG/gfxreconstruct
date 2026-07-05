# In-Loop Resource Lifetime Management

During frame looping, replaying trace segments repeatedly means the replayer executes resource creation (e.g., `vkCreateBuffer`, `vkCreateCommandPool`, `vkAllocateDescriptorSets`) and destruction (`vkDestroyBuffer`, `vkDestroyCommandPool`, `vkFreeDescriptorSets`) calls multiple times.

Without lifecycle virtualization, re-running these calls on iteration 2+ causes major issues:
*   **Handle Leakage**: Creating resources on each iteration leaks driver memory.
*   **Use-After-Free**: Destroying a resource that was allocated before the loop but freed inside the loop leaves the replayer with invalid/missing handles on the next iteration.
*   **API Specification Violations**: Re-destroying a resource that was already destroyed in a previous iteration triggers driver crashes or Vulkan validation errors.

This document describes how GFXReconstruct tracks and manages resource lifecycles during frame looping, combining automated base-class tracking with specialized subclass bypass rules.

---

## 1. Automated Base-Class Tracking (`allocatedLoopResources`)

The code generator generates a base class `VulkanReplayFrameLoopConsumerBase` which implements automated tracking for standard Vulkan objects (instances, devices, memory, buffers, images, swapchains, shaders, pipelines, etc.):

*   **In-Loop Allocation Tracking**: The base consumer maintains a `std::set<format::HandleId> allocatedLoopResources`.
*   **Dynamic Insertion**: When a resource creation API call (e.g., `vkCreateBuffer`) is replayed, the base consumer checks if looping is active:
    *   If active and the handle is not yet in `allocatedLoopResources`, the handle is registered.
*   **Conditional Destruction**: When a resource destruction API call (e.g., `vkDestroyBuffer`) is replayed:
    *   If looping is inactive, or the resource is registered in `allocatedLoopResources`, the destruction is allowed to proceed to the Vulkan driver, and the handle is removed from the set.
    *   If looping is active but the resource was created *before* the loop started (i.e. not in `allocatedLoopResources`), the destruction call is **completely skipped**. This preserves the resource so it remains available for subsequent loop iterations.

---

## 2. Subclass Dangling Resource Management

For resources with complex allocation lifecycles (Command Pools, Command Buffers, Descriptor Pools, and Descriptor Sets), simple conditional destruction is insufficient. GFXReconstruct handles these in `VulkanReplayFrameLoopConsumer` using explicit state sets:

*   **Dangling Create Sets** (`dangling_create_*`): Track resources created *inside* the loop.
*   **Dangling Destroy/Free Sets** (`dangling_destroy_*` / `dangling_free_*`): Track resources created *before* the loop but destroyed/freed *inside* the loop.

### A. Lifecycle Management Rules

#### Rule 1: Command Pools and Descriptor Pools
*   **During Iteration 1**:
    *   If created inside the loop: Add to `dangling_create_*`.
    *   If destroyed inside the loop:
        *   If it was created before the loop (not in `dangling_create_*`), add to `dangling_destroy_*` and skip driver destruction.
        *   If it was created inside the loop (in `dangling_create_*`), erase from `dangling_create_*` and proceed with destruction.
*   **During Iteration 2+**:
    *   Skip creation calls for resources in `dangling_create_*` (they are already created and cached).
    *   Skip destruction calls for resources in `dangling_destroy_*`.

#### Rule 2: Command Buffers and Descriptor Sets
Unlike pools, command buffers and descriptor sets are allocated from parent pools rather than created directly.
*   **During Iteration 1**:
    *   If allocated inside the loop: Add to `dangling_allocate_*`.
    *   If freed inside the loop:
        *   If any of the command buffers/descriptor sets in the free call was allocated before the loop (not in `dangling_allocate_*`), add all of them to `dangling_free_*` and skip driver free.
        *   Otherwise (all allocated inside the loop), erase from `dangling_allocate_*` and proceed with freeing them.
*   **During Iteration 2+**:
    *   Skip allocation and free calls completely for tracked dangling command buffers and descriptor sets.

---

## Summary of Tracked Resource Types

| Resource Type | Creation Function | Destruction Function | Tracking State Collections |
| :--- | :--- | :--- | :--- |
| **Command Pool** | `vkCreateCommandPool` | `vkDestroyCommandPool` | `dangling_create_command_pools_`<br>`dangling_destroy_command_pools_` |
| **Command Buffer** | `vkAllocateCommandBuffers` | `vkFreeCommandBuffers` | `dangling_allocate_command_buffers_`<br>`dangling_free_command_buffers_` |
| **Descriptor Pool** | `vkCreateDescriptorPool` | `vkDestroyDescriptorPool` | `dangling_create_descriptor_pools_`<br>`dangling_destroy_descriptor_pools_` |
| **Descriptor Set** | `vkAllocateDescriptorSets` | `vkFreeDescriptorSets` | `dangling_create_descriptor_sets_`<br>`dangling_destroy_descriptor_sets_` |
