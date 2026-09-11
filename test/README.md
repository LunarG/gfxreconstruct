# GFXReconstruct tests

This directory holds the tests that run without a GPU.
[TESTING_test_apps.md](../TESTING_test_apps.md) explains how to write a test app.
This file explains how the tests fit together, how to run them, and how to keep them honest.

## What is here

| Path | Content |
|---|---|
| `icd/` | A mock Vulkan ICD. The loader finds it through `VkICD_mock_icd.json`. It returns success and does no work. |
| `android_mock/` | A host build of the Android hardware buffer functions, so the `ahb` app runs on a desktop. |
| `test_apps/` | The test apps and the launcher, `gfxrecon-test-launcher`, that runs one app by name. |
| `test_cases/` | The gtest cases. Each file holds the cases for one app or one topic. |
| `known_good/` | One reference capture per app. A case compares a new capture against it. |
| `verify-gfxr.{h,cpp}` | The harness functions that the cases call. |
| `run-tests.sh.in`, `run-tests.ps1.in`, `run-tests_macos.sh.in` | Templates for the run scripts. CMake fills in the paths. |
| `test_environment.cmake.in` | The loader environment that ctest gives every case. |

## The tiers

Every case in this directory runs on the mock ICD.
That proves what the capture layer wrote and what the replayer read.
It does not prove that a draw put the correct pixels in an image, because the mock draws nothing.
A later tier runs the same cases on a software rasterizer for that.

## Build and run

Build with the test apps and install:

```bash
python3 scripts/build.py --skip-check-code-style --test-apps
```

The install directory is `build/<platform>/<arch>/output`.
`ctest` starts each case from `<install>/test`, so the install must exist before a run.

Run everything from the build directory:

```bash
ctest --test-dir build/linux/x64 --output-on-failure
```

Select cases by label or by name:

```bash
ctest --test-dir build/linux/x64 -L unit          # The Catch2 unit tests only.
ctest --test-dir build/linux/x64 -L smoke         # The test app cases only.
ctest --test-dir build/linux/x64 -R Triangle      # Every case whose name matches.
ctest --test-dir build/linux/x64 -N               # List the cases and run nothing.
```

The run script in `<install>/test` does the same for the test app cases and adds one mode.
An argument that is an app name runs that app alone, without a comparison:

```bash
cd build/linux/x64/output/test
./run-tests.sh                 # Every test app case.
./run-tests.sh -R Triangle     # Arguments that start with "-" go to ctest.
./run-tests.sh triangle        # One app, no comparison.
```

Each ctest run also writes `ctest-results.xml` in the test directory.
CI shows that file on the job summary page.

## The environment

`GFXRECON_TEST_ENVIRONMENT` in `CMakeLists.txt` is the one list of environment variables.
It selects the mock ICD and the capture layer, and it makes the apps headless.
ctest applies it to every case, and the run scripts export it.
A variable that you export in your shell does not override it.

## What a case does

`verify_gfxr(name)` runs the app with the capture layer on, converts the new capture to JSON,
converts `known_good/<name>.gfxr` to JSON, drops the fields that differ between runs, and
compares the two documents.
The list of dropped fields is in `verify-gfxr.cpp`, with a reason next to each entry.
`json-normalizer.cpp` tests that list.

`capture_and_replay(name, args)` runs the app with the capture layer on and then replays the
capture with `gfxrecon-replay` and the given arguments.
It checks only the exit code.

`reruns.cpp` runs each capture app two more times.
One run has `GFXRECON_CAPTURE_PROCESS_NAME` set to a name that does not match.
The layer must load and write no file.
The other run has `GFXRECON_FORCE_COMMAND_SERIALIZATION=true` and must match the same known good.
When you add an app, add its name to the lists in that file.

## Add a case

1. Add a file to `test_cases/` with one `TEST` that calls a harness function.
2. Add the file to `GFXRECON_TESTCASES` in `CMakeLists.txt`.
3. Make the known-good file as the next section describes.
4. Add the app name to the lists in `test_cases/reruns.cpp`.

If the app cannot run on the mock yet, add the case with the `DISABLED_` prefix.
Write the blocker in a comment above it.
ctest lists a disabled case and does not run it.

## Make or update a known-good file

The known-good file is a capture of the app on the mock ICD.

1. Delete `known_good/<name>.gfxr` if one exists, then build and install.
2. Run the case once.
   It fails, and it leaves `<name>.gfxr` in `<install>/test`.
3. Copy that file to `test/known_good/<name>.gfxr`, then install again.
4. Run the case two more times.
   Both must pass.
   If one fails, the capture is not deterministic.
   Find the source of the difference before you commit.
5. Look at the size.
   An app renders 10 frames unless a comment says why it needs more.
   The whole `known_good/` directory stays under 5 MB.

## Keep the tests honest

Two habits catch a test that passes for the wrong reason.

Disable the code that your test covers, then run the test.
If the test still passes, it does not test that code.

Prove a harness assertion before you trust it.
Start the runner with an empty environment, so the app runs with no capture layer:

```bash
cd build/linux/x64/output/test
env -i PATH="$PATH" HOME="$HOME" ./gfxrecon-testapp-runner --gtest_filter=Triangle.CorrectGFXR
```

The case must fail at "capture file was not produced".
A pass here means the harness reads a file from an earlier run.

## Known gaps

`HostImageCopy.CorrectGFXR` is disabled.
The app copies bytes through `VK_EXT_host_image_copy` and compares them.
The mock moves no bytes.
It runs when the mock backs device memory and executes copies.
