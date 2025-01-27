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

Use of the *TestAppBase* is optional.

## **Building Test Apps**

Test apps are built as part of the default build CMAKE build process. In order to stop test apps from building, set the
**GFXRECON_INCLUDE_TEST_APPS** CMake variable to OFF, e.g. provide `-DGFXRECON_INCLUDE_TEST_APPS=OFF` in your cmake command line.

## **Test App Verification**

To run the test apps and validate output against known good '.gfxr' files, build the project using ./scripts/build.py,
and then run the test script from within the 'test' install directory.

|Operating System|Test Directory|Test Script|
|---------------|---------------|------------|
|Windows|build/windows/x64/output/test|run-tests.ps1|
|Linux|build/linux/x64/output/test|run-tests.sh|
|MacOs|build/darwin/universal/output/test|run-tests_macos.sh|
