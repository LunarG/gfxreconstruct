# GFXReconstruct Test Apps

## **Adding a Test App**

1. Create a new folder in the `test_apps` directory. Name the directory the same name as your test app.
2. Add your code to the new folder
3. Create a new `CMakeLists.txt` file in the new directory that builds your test app. For examples
4. Include the new folder in the CMakeLists.txt file in the `test_apps` directory

See the *triangle* test app for examples.

## **Test App Architecture**

The *gfxrecon::test::TestAppBase* class is provided as a base class for test apps. This base class provides basic Vulkan
initialization and a render loop. The *TestAppBase* provides to following overridable virtual functions:

* ***void configure_instance_builder(InstanceBuilder&)*** - called before instance creation in order to modify the
  instance creation, e.g. add instance extensions
* ***void configure_physical_device_selector(PhysicalDeviceSelector&)*** - called before physical device selection in
  order to modify device selection
* ***void configure_device_builder(DeviceBuilder&, PhysicalDevice const&)*** - called before device creation in order to
  modify device creation, e.g. add device extensions
* ***void configure_swapchain_builder(SwapchainBuilder&)*** - called before swapchain creation in order to modify
  swapchain creation
* ***void setup()*** - called after the swapchain has been built, but before the render loop. Can be used to setup test
  app specific resources
* ***bool frame(const int frame_num)*** - executes a single frame of the render loop. Returns true to continue the
  render loop, false to exit
* ***void cleanup()*** -- called after the render loop has stopped. Can be used to cleanup test app specific resources

Only the ***frame*** function is required. All others are optional.

## **Test Launcher**

The test-launcher is an executable which can be used to launch test apps.

```console
gfxrecon-test-launcher - A launcher for GFXReconstruct test apps.

Usage:
  gfxrecon-test-launcher [-h | --help] <test_name>

Required arguments:
  <test_name>   Name of the test app to launch.
                Options are: 
                  acquired-image
                  host-image-copy
                  multisample-depth
                  pipeline-binaries
                  shader-objects
                  sparse-resources
                  triangle
                  external-memory-fd-export
                  external-memory-fd-import
                  wait-for-present
                  trigger-trimming
                  [...]
```

Use of the *TestAppBase* is required to add a test app to the test-launcher.

In order to add a test app to the test-launcher, make sure to modify `test_launcher.cpp` using the following approach making sure to replace `<test-name>` with the name of your test app:
1. Add `#include <<test-name>-app.h>`
2. Add `"<test-name>"` to `kAppNames`
3. Add the following code to `CreateTestApp()`:
   ```cpp
   else if (app_name == "<test-name>")
   {
       app = std::make_unique<gfxrecon::test_app::<test_name>::App>();
   }
   ```

Finally, make sure to add your test app library to the `GFXRECON_TEST_LAUNCHER_LINK_LIBRARIES` list in the following CMakeLists files:

- `android/test/test_apps/launcher/CMakeLists.txt`
- `test/test_apps/launcher/CMakeLists.txt`

## **Building Test Apps**

Test apps are built as part of the default build CMAKE build process. In order to stop test apps from building, set the
**GFXRECON_INCLUDE_TEST_APPS** CMake variable to OFF, e.g. provide `-DGFXRECON_INCLUDE_TEST_APPS=OFF` in your cmake command line.

## **Test App Verification**

To run the test cases, build and install the project.
Then run `ctest --test-dir <build>/test`, or run the test script from the 'test' install directory.
CMake gives every test case the Vulkan loader environment, so plain `ctest` works.
The script exports the same environment and then calls `ctest`.
`ctest` starts each test case from the install directory, so the install must exist before the run.

*On Windows:* The test app must not be run as administrator.  If you receive an error that the ps1 script is not digitally signed, you will need to run 'Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope LocalMachine' to allow the script to run.


|Operating System| ./scripts/build.py Test Directory  |Test Script|
|---------------|------------------------------------|------------|
|Windows| build/windows/x64/output/test      |run-tests.ps1|
|Linux| build/linux/x64/output/test        |run-tests.sh|
|macOS| build/darwin/universal/output/test |run-tests_macos.sh|

## **Run A Subset Of The Test Cases**

If the first argument of the test script starts with `-`, every argument goes to `ctest`.
Examples:

```bash
./run-tests.sh -L smoke      # Run the test cases with the "smoke" label.
./run-tests.sh -R Triangle   # Run the test cases whose name matches a regular expression.
./run-tests.sh -N            # List the test cases and run nothing.
```

Every test case has a `ctest` label and a timeout.
The labels select tests by driver and by cost.
`test/CMakeLists.txt` sets them, and it holds the environment list in `GFXRECON_TEST_ENVIRONMENT`.

## **Run A Single Test App**

When the first argument of the test script is a test app name, the script runs that app directly.
That run has no runner and no comparison.
Example: `run-tests.sh triangle`.
The app starts in the `res` directory, which is where the harness starts it.

You can also run a test app without the test script.
The environment variables that the test script sets are necessary for that.
Some of the paths in them must match your environment.
