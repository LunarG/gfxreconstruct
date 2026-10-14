#include "AndroidLogging.hpp"
#include "VulkanMain.hpp"

// Process the next main command.
void handle_cmd(android_app* app, int32_t cmd) {
    LOGI("event not handled: %d", cmd);
}

void android_main(struct android_app* app) {
  // Set the callback to process system events
  app->onAppCmd = handle_cmd;

  // Used to poll the events in the main loop
  int events;
  android_poll_source* source;

  // Main loop
  do {
    // ALooper_pollOnce, not ALooper_pollAll.  The NDK marks pollAll as obsolete
    // because it can swallow a wake.  This loop already comes back around, so
    // taking one event at a time loses nothing.
    if (ALooper_pollOnce(1, nullptr,
                         &events, (void**)&source) >= 0) {
      if (source != NULL) {
        source->process(app, source);
      }
    }
    if (app->window) {
      VulkanDrawFrame(app);
    }
  } while (app->destroyRequested == 0);

  ANativeActivity_finish(app->activity);
}
