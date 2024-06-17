/*
** Copyright (c) 2020 Advanced Micro Devices, Inc. All rights reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

#ifndef GFXRECON_DECODE_TRACKED_OPENXR_OBJECT_INFO_H
#define GFXRECON_DECODE_TRACKED_OPENXR_OBJECT_INFO_H

#ifdef ENABLE_OPENXR_SUPPORT

#include "util/defines.h"
#include "format/format.h"

#include "openxr/openxr.h"

#include <vector>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(decode)

class TrackedXrInstanceInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrInstance handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrInstance GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrInstance handle_;
};

class TrackedXrSessionInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrSession handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrSession GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrSession handle_;
};

class TrackedXrSwapchainInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrSwapchain handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrSwapchain GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrSwapchain handle_;
};

class TrackedXrActionSetInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrActionSet handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrActionSet GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrActionSet handle_;
};

class TrackedXrActionInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrAction handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrAction GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrAction handle_;
};

class TrackedXrDebugUtilsMessengerEXTInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrDebugUtilsMessengerEXT handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrDebugUtilsMessengerEXT GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrDebugUtilsMessengerEXT handle_;
};

class TrackedXrSpatialAnchorMSFTInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrSpatialAnchorMSFT handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrSpatialAnchorMSFT GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrSpatialAnchorMSFT handle_;
};

class TrackedXrSpaceInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrSpace handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrSpace GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrSpace handle_;
};

class TrackedXrHandTrackerEXTInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrHandTrackerEXT handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrHandTrackerEXT GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrHandTrackerEXT handle_;
};

class TrackedXrBodyTrackerFBInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrBodyTrackerFB handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrBodyTrackerFB GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrBodyTrackerFB handle_;
};

class TrackedXrSceneObserverMSFTInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrSceneObserverMSFT handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrSceneObserverMSFT GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrSceneObserverMSFT handle_;
};

class TrackedXrSceneMSFTInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrSceneMSFT handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrSceneMSFT GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrSceneMSFT handle_;
};

class TrackedXrFacialTrackerHTCInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrFacialTrackerHTC handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrFacialTrackerHTC GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrFacialTrackerHTC handle_;
};

class TrackedXrFoveationProfileFBInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrFoveationProfileFB handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrFoveationProfileFB GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrFoveationProfileFB handle_;
};

class TrackedXrPassthroughFBInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrPassthroughFB handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrPassthroughFB GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrPassthroughFB handle_;
};

class TrackedXrPassthroughLayerFBInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrPassthroughLayerFB handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrPassthroughLayerFB GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrPassthroughLayerFB handle_;
};

class TrackedXrGeometryInstanceFBInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrGeometryInstanceFB handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrGeometryInstanceFB GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrGeometryInstanceFB handle_;
};

class TrackedXrMarkerDetectorMLInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrMarkerDetectorML handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrMarkerDetectorML GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrMarkerDetectorML handle_;
};

class TrackedXrExportedLocalizationMapMLInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrExportedLocalizationMapML handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrExportedLocalizationMapML GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrExportedLocalizationMapML handle_;
};

class TrackedXrSpatialAnchorStoreConnectionMSFTInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrSpatialAnchorStoreConnectionMSFT handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrSpatialAnchorStoreConnectionMSFT GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrSpatialAnchorStoreConnectionMSFT handle_;
};

class TrackedXrFaceTrackerFBInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrFaceTrackerFB handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrFaceTrackerFB GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrFaceTrackerFB handle_;
};

class TrackedXrEyeTrackerFBInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrEyeTrackerFB handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrEyeTrackerFB GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrEyeTrackerFB handle_;
};

class TrackedXrVirtualKeyboardMETAInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrVirtualKeyboardMETA handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrVirtualKeyboardMETA GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrVirtualKeyboardMETA handle_;
};

class TrackedXrSpaceUserFBInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrSpaceUserFB handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrSpaceUserFB GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrSpaceUserFB handle_;
};

class TrackedXrPassthroughColorLutMETAInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrPassthroughColorLutMETA handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrPassthroughColorLutMETA GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrPassthroughColorLutMETA handle_;
};

class TrackedXrFaceTracker2FBInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrFaceTracker2FB handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrFaceTracker2FB GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrFaceTracker2FB handle_;
};

class TrackedXrPassthroughHTCInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrPassthroughHTC handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrPassthroughHTC GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrPassthroughHTC handle_;
};

class TrackedXrPlaneDetectorEXTInfo
{
  public:
    // Set capture ID
    void SetCaptureId(format::HandleId capture_id) { capture_id_ = capture_id; }

    // Get capture ID
    format::HandleId GetCaptureId() const { return capture_id_; }

    // Set handle ID
    void SetHandleId(XrPlaneDetectorEXT handle_id) { handle_ = handle_id; }

    // Get handle ID
    XrPlaneDetectorEXT GetHandleId() const { return handle_; }

  private:
    // ID assigned to the object at capture.
    format::HandleId capture_id_{ 0 };

    // Handle created during first pass
    XrPlaneDetectorEXT handle_;
};

GFXRECON_END_NAMESPACE(decode)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // ENABLE_OPENXR_SUPPORT

#endif // GFXRECON_DECODE_OPENXR_TRACKED_OBJECT_INFO_H
