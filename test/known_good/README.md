# GFXR Verification Tests

## Overview

The test infrastructure captures small Vulkan workloads from `test_cases/` through the
Mock ICD, producing `.gfxr` capture files. These captures are then converted to JSON and
compared against reference files stored in `known_good/`. CI fails when the captured
output diverges from the known-good reference.

The comparison is performed by `verify-gfxr.cpp`, which converts both the captured and
known-good `.gfxr` files to JSON, then produces a JSON Patch (RFC 6902) diff. A test
passes when the diff is empty (`diff.size() == 0`).

## Reading a Comparison Failure

A typical CI failure looks like:

```
[ RUN      ] PipelineBinaries.CorrectGFXR
...
test/verify-gfxr.cpp:341: Failure
Expected equality of these values:
  diff.size()
    Which is: 63
  0
[
    {
        "op": "remove",
        "path": "/37/function/args/createInfoCount"
    },
    {
        "op": "add",
        "path": "/37/function/args/pCreateInfo",
        "value": { ... }
    },
    ...
]
```

The diff output uses JSON Patch operations:

| Operation | Meaning |
|-----------|---------|
| `"op": "remove"` | Field present in known-good but absent in new capture |
| `"op": "add"` | Field present in new capture but absent in known-good |
| `"op": "replace"` | Field exists in both but value differs |

The `"path"` field tells you which API call index and argument changed. For example,
`/37/function/name` refers to the 37th Vulkan call in the capture, and
`/37/function/args/pCreateInfos` refers to its arguments.

## Fixing a Known-Good File

When a comparison failure is **expected** (e.g., you intentionally changed capture
behavior, added support for a new extension, or modified JSON output formatting), you
need to update the known-good reference file.

### Step 1: Review the Diff in CI

Open the failing GitHub Actions job and read the JSON Patch diff in the test output.
Confirm that every change is expected and corresponds to your code changes. The full
log is available by clicking the failing job step, or via the raw log link (see the
"Summary" or "Annotations" section of the workflow run).

### Step 2: Download the Capture Artifact from GitHub Actions

The CI workflow uploads the newly captured `.gfxr` files as build artifacts. To
retrieve them:

1. Navigate to the failing workflow run on GitHub (Actions tab → click the run).
2. Scroll to the **Artifacts** section at the bottom of the run summary page.
3. Download the artifact containing the test captures (e.g., `test-artifacts` or
   similar — the archive will contain the `.gfxr` files produced during the run).

Alternatively, download via the GitHub CLI:

```bash
# List artifacts for the workflow run
gh run view <run-id> --repo LunarG/gfxreconstruct

# Download the artifacts
gh run download <run-id> --repo LunarG/gfxreconstruct --name <artifact-name>
```

### Step 3: Optionally Inspect the JSON Diff Locally

If you want to compare the JSON representations beyond what the CI log shows:

```bash
# Convert the new capture from the downloaded artifact to JSON
gfxrecon-convert --format json pipeline-binaries.gfxr

# Convert the known-good reference to JSON
gfxrecon-convert --format json test/known_good/pipeline-binaries.gfxr

# Diff the JSON outputs
diff <(jq . pipeline-binaries.jsonl) \
     <(jq . test/known_good/pipeline-binaries.jsonl)
```

### Step 4: Update the Known-Good File

Once you have confirmed the new output is correct, copy the downloaded capture over
the known-good reference:

```bash
cp pipeline-binaries.gfxr test/known_good/pipeline-binaries.gfxr
```

Replace the test name/path as appropriate for whichever test case failed.

### Step 5: Commit Both Changes

The updated known-good `.gfxr` file **must** be committed alongside the code changes
that caused the output to change. This makes the PR self-consistent and keeps CI green.

```bash
git add test/known_good/pipeline-binaries.gfxr
git add <your source changes>
git commit -m "Update known-good for pipeline-binaries after <description of change>"
```

## Adding a New Test Case

1. Create a new test app in `test_cases/` that exercises the Vulkan functionality you
   want to verify.
2. Build and run the test to produce the initial `.gfxr` capture.
3. Inspect the JSON output (`gfxrecon-convert --format json`) to confirm it looks correct.
4. Copy the capture into `known_good/`.
5. Add the corresponding test case to `verify-gfxr.cpp` following the pattern of
   existing tests.
6. Commit the test app source, known-good file, and test registration together.

## Tips

- The diff uses array indices (e.g., `/37/`) that correspond to the Vulkan call index
  in the JSON output. Use `gfxrecon-convert` with `--format json` and pipe through
  `jq '.[] | select(.index == 37)'` to inspect a specific call.
- If the diff is large, it often means an API call was inserted or removed, shifting all
  subsequent indices. Look for `"op": "replace"` on `function/name` to spot where the
  call sequence diverged.
- The known-good files are `.gfxr` capture files, not JSON. The test infrastructure
  handles the conversion internally.
