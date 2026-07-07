# GfxReconstruct Frame Loop Boundary Reset Refactor

## 1. Problem Statement
To support frame looping, GfxReconstruct must reset Vulkan device and resource states back to their initial captured states at the boundary of each loop iteration.

Additionally, the primary goal of this refactor is to execute `ResetLoopBoundary()` **outside** the `GFXR_REPLAY_EVENT_FRAME_BEGIN` and `GFXR_REPLAY_EVENT_FRAME_END` markers reported to benchmark plugins. By moving the reset outside of this window, the frame timings reported to the plugin represent clean frame execution and do not include the significant overhead of resetting loop boundaries (with the exception of the first frame, where initialization/preload overhead is expected).

Previously, this loop boundary reset (`ResetLoopBoundary()`) was triggered inside either:
- `ProcessFrameEndMarker()` (if the capture contained frame markers).
- `Process_vkQueuePresentKHR()` (if no frame markers were present).

This old approach had several drawbacks:
1. **Timing Inconsistencies & Profiling Overhead:** State restoration occurred *within* the replaying of frame blocks (e.g. inside `vkQueuePresentKHR` or frame marker callbacks), which fell inside the active profiling window of the benchmark plugin, polluting the reported frame time.
2. **Tight Coupling:** Vulkan-specific API call processing was coupled with the high-level playback/frame-boundary lifecycle.
3. **Duplicated Logic:** The consumer had to track whether the capture utilized frame markers (`uses_frame_markers_`) and branch its reset logic accordingly.

## 2. Refactored Architecture

To resolve this, we introduced a clean, unified `OnFrameBegin()` lifecycle hook at the decoder/consumer level, driven directly by the `FileProcessor`.

### 2.1 Lifecycle Hook Definition (`api_decoder.h`, `common_consumer_base.h`)

We added `OnFrameBegin()` to the base decoder and consumer interfaces:
```cpp
// api_decoder.h
class ApiDecoder {
public:
    virtual void OnFrameBegin() {}
    // ...
};

// common_consumer_base.h
class CommonConsumerBase : public MetadataConsumerBase, public MarkerConsumerBase {
public:
    virtual void OnFrameBegin() {}
    // ...
};
```

### 2.2 Pre-Triggering and Dispatching Flow (`application.cpp`, `file_processor.cpp`, `preload_file_processor.cpp`)

To guarantee that `ResetLoopBoundary()` is executed outside of the plugin profiling window:
1. `Application::PlaySingleFrame()` explicitly triggers `file_processor_->OnFrameBegin()` **before** it fires the plugin's `FrameBegin` event.
2. `FileProcessor::OnFrameBegin()` invokes `OnFrameBegin()` on all decoders.
3. `ProcessNextFrame()` in both `FileProcessor` and `PreloadFileProcessor` only replays frame blocks and does not call `OnFrameBegin()` inline.
4. This keeps the design simple, clean, and avoids tracking state variables such as invocation flags.

```cpp
// application.cpp
bool Application::PlaySingleFrame()
{
    if (file_processor_)
    {
        file_processor_->OnFrameBegin();

        if (replay_event_sink_)
        {
            replay_event_sink_->FrameBegin(file_processor_->GetCurrentFrameNumber());
        }

        success = file_processor_->ProcessNextFrame();
        // ...
    }
}

// file_processor.cpp
void FileProcessor::OnFrameBegin()
{
    for (auto decoder : decoders_)
    {
        decoder->OnFrameBegin();
    }
}

bool FileProcessor::ProcessNextFrame()
{
    bool success = false;
    if (AsyncProcessingEnabled())
    {
        success = ProcessNextFrameAsync();
    }
    else
    {
        success = ProcessNextFrameSync();
    }
    return success;
}

// preload_file_processor.cpp
bool PreloadFileProcessor::ProcessNextFrame()
{
    if (!replay_from_queue_)
    {
        return FileProcessor::ProcessNextFrame();
    }

    DispatchVisitor dispatch_visitor(*this, decoders_, annotation_handler_);
    preload_block_iterator_           = ReplayOneFrame(dispatch_visitor, preload_block_iterator_, BlockIterator());
    const ProcessBlocksResult& result = dispatch_visitor.GetReplayResult();
    HandleReplayResult(result, preload_block_iterator_);
    // ...
    return success;
}
```

### 2.3 Decoder Routing (`vulkan_decoder_base.h`)

The Vulkan decoder intercepts `OnFrameBegin()` and forwards it to all active Vulkan consumers:
```cpp
// vulkan_decoder_base.h
void OnFrameBegin() override
{
    for (auto consumer : consumers_)
    {
        consumer->OnFrameBegin();
    }
}
```

### 2.4 Consumer State Restoration (`vulkan_replay_frame_loop_consumer.cpp`)

`VulkanReplayFrameLoopConsumer` implements `OnFrameBegin()` to reset the loop boundary if it is on a repeated iteration of the loop:

```cpp
// vulkan_replay_frame_loop_consumer.cpp
void VulkanReplayFrameLoopConsumer::OnFrameBegin()
{
    if (IsLoopNotFirstIteration())
    {
        ResetLoopBoundary();
    }
}
```

As a result, we cleaned up `vulkan_replay_frame_loop_consumer.cpp` and `vulkan_replay_frame_loop_consumer.h` by removing:
- `ProcessFrameEndMarker()` override.
- `uses_frame_markers_` tracking field and constructor initialization.
- Loop boundary reset checks inside `Process_vkQueuePresentKHR()`.

We also modified `ClassifyActiveCommandPools()` by removing the `IsLoopFirstIteration()` guard from its check. Since `ResetLoopBoundary()` is now triggered at the start of iteration 2 (`IsLoopNotFirstIteration()` is true, but `IsLoopFirstIteration()` is false), removing this guard ensures command pools classification runs on the first boundary reset, preventing driver segmentation faults (`SIGSEGV` at `vkEndCommandBuffer`) from un-recreated loop-recorded command buffers.

## 3. Advantages

- **Clean Separations of Concerns:** The Vulkan replay consumer does not need to know *how* frame boundaries are defined (markers vs present calls). It simply responds to the high-level `OnFrameBegin()` notification.
- **Robustness:** State restoration is guaranteed to happen exactly before any block of the new frame is parsed/replayed, minimizing validation layer issues and timing mismatches.
- **Unified Logic:** Removes branching and duplicate reset code paths in the consumer.
