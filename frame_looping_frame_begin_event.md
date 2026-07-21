# Frame Looping Frame Begin Event Fix

## Description of the Fix

When replaying a trimmed trace with frame looping, the capture file typically starts with a sequence of state restoration calls enclosed between `StateBeginMarker` and `StateEndMarker`. During this setup phase, there might be various API calls and GPU workloads (e.g., for uploading buffers, creating images, pipeline creation, etc.).

Before this fix, replay event plugins could incorrectly assume that the very first API calls or workloads encountered during replay were part of the first frame. However, if these calls were actually part of the state setup, they would be incorrectly measured as part of the first frame's work. This led to invalid metrics and broken frame iterations for plugins that rely on accurate frame boundaries.

### The Solution

1. **Explicit State Setup Phase:** We introduced `FileProcessor::ProcessStateSetup()`, which processes all commands until `StateEndMarker` (or rewinds if it's a full capture) *before* the main replay loop and *before* `OnFrameBegin()` is called. 
2. **Delayed Frame Begin Emission:** In `Application::Run()`, we execute `ProcessStateSetup()` but we deliberately do *not* emit a `FrameBegin` event. 
3. **Plugin Modifications:** Replay event plugins can now safely initialize their frame tracking flags to `false`, and only begin tracking the first frame when they explicitly receive the `c` event.

### How it works together

When `ProcessStateSetup()` processes commands during the state restoration phase, plugins will correctly ignore them as part of the frame workload because no `FrameBegin` event has been dispatched yet.

Once `ProcessStateSetup()` is complete, the `Application` enters the main loop. On the very first `PlaySingleFrame()`, `file_processor_->OnFrameBegin()` is called, which dispatches the `GFXR_REPLAY_EVENT_FRAME_BEGIN`. This event signals to plugins that the *actual* first frame is beginning, ensuring that any subsequent API workloads are correctly attributed to the first loop iteration rather than state restoration.
