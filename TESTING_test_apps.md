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

To run the test apps and validate output against known good '.gfxr' files, build the project and then run the test script from within the 'test' install directory.

*On Windows:* The test app must not be run as administrator.  If you receive an error that the ps1 script is not digitally signed, you will need to run 'Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope LocalMachine' to allow the script to run.


|Operating System| ./scripts/build.py Test Directory  |Test Script|
|---------------|------------------------------------|------------|
|Windows| build/windows/x64/output/test      |run-tests.ps1|
|Linux| build/linux/x64/output/test        |run-tests.sh|
|MacOs| build/darwin/universal/output/test |run-tests_macos.sh|

## **Run A Single Test App**

The default of Test Script `run-tests.sh` runs whole test apps. It could also run a single test app by specifying the test name, e.g. `run-tests.sh triangle`.

It could also run the test app straightforwardly without the test script. However, many environment variables set in the test script are necessary for running a single test app. Plus, some paths of the environment variables might have to be modified to match your environment.
