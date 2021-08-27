---
name: Replay failure
about: Create a replay bug report to help us improve.
title: "[replay] Give one-line summary of issue here"
labels: ''
assignees: ''

---

**Describe the replay bug:**
Describe the issue here.  Is it visual corruption?  A hang?  A performance problem?

**Verify before submission:**
* Was trimming enabled?
* Was replayer renamed if necessary?
* Was --sync used if title is known to need forced synchronization?

**Build Environment:**
Please include the SHA and PR or branch name used in capture and also used to build the replayer.

**To Reproduce**
Steps to reproduce the behavior:
1. Get the `.gfxr` file from [insert download location here, e.g. LunarShare]
2. Run gfxrecon-replay with [insert parameters here]

**Screenshots:**
If applicable, add screenshots to illustrate visual corruption.

**System environment:**
 - GPU and driver version on which capture was taken
 - GPU and driver version on which capture file was replayed with issue

**Title configuration:**
  - Title name
  - Title version
  - Steam ID if applicable
  - Is DXR enabled?

**Additional information (optional):**
  - is there a SHA for which replayer is known to replay correctly?  (indicates possible regression in decoder/consumer)
  - Is there an older trace that works?  What SHA was used to build those capture DLLs?  (indicates possible regression in capture/encoder)
  - Does a newer capture work?  (indicates bug fix in capture/encoder that needs to be noted)
  - Does the capture file replay correctly on a different GPU?
