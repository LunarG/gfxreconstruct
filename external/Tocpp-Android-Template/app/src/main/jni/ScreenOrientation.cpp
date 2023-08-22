#include "ScreenOrientation.hpp"

#include "AndroidLogging.hpp"

#include <array>

AndroidScreen::AndroidScreen(android_app* application)
{
    m_application = application;

    if (m_application != nullptr && m_application->window != nullptr) {
        m_width  = ANativeWindow_getWidth(m_application->window);
        m_height = ANativeWindow_getHeight(m_application->window);
    } else {
        m_width  = -1;
        m_height = -1;
    }

    m_pretransform = 0;
}

// NOTE: This function is the same with AndroidApplication::SetOrientation().
void AndroidScreen::windowSetOrientation(ScreenOrientation orientation)
{
    JavaVM* jni_vm       = nullptr;
    jobject jni_activity = nullptr;
    JNIEnv* env          = nullptr;

    if ((m_application != nullptr) && (m_application->activity != nullptr))
    {
        jni_vm       = m_application->activity->vm;
        jni_activity = m_application->activity->clazz;
    }

    if ((jni_vm != nullptr) && (jni_activity != 0) && (jni_vm->AttachCurrentThread(&env, nullptr) == JNI_OK))
    {
        jclass    object_class    = env->GetObjectClass(jni_activity);
        jmethodID set_orientation = env->GetMethodID(object_class, "setRequestedOrientation", "(I)V");

        env->CallVoidMethod(jni_activity, set_orientation, orientation);

        jni_vm->DetachCurrentThread();
    }
}

// NOTE: This function is the same with AndroidWindow::SetSizePreTransform().
void AndroidScreen::windowSetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform)
{
    if ((width != m_width) || (height != m_height) || (pre_transform != m_pretransform))
    {
        m_width         = width;
        m_height        = height;
        m_pretransform  = pre_transform;

        if ((m_application == nullptr) || (m_application->window == nullptr))
        {
            LOGE("Failed to resize the window!");
            return;
        }

        // For Android, we adjust the screen orientation based on requested width and height.
        int32_t pixel_width  = ANativeWindow_getWidth(m_application->window);
        int32_t pixel_height = ANativeWindow_getHeight(m_application->window);

        // We don't change the current orientation if width == height or if the requested orientation matches the
        // current orientation, unless a pre-transform has been applied to the swapchain, in which case the orientation
        // will be adjusted to match the pre-transform.
        if (((width != height) && ((width < height) != (pixel_width < pixel_height))) ||
            (pre_transform != ResizeWindowPreTransform::kPreTransform0))
        {
            const std::array<ScreenOrientation, 2> kOrientations{
                ScreenOrientation::kLandscape,
                ScreenOrientation::kPortrait
            };

            uint32_t orientation_index = 0;

            if (height > width)
            {
                orientation_index = 1;
            }

            // Toggle orientation between landscape and portrait for 90 and 270 degree pre-transform values.
            if ((pre_transform == ResizeWindowPreTransform::kPreTransform90) ||
                (pre_transform == ResizeWindowPreTransform::kPreTransform270))
            {
                orientation_index ^= 1;
            }

            windowSetOrientation(kOrientations[orientation_index]);
        }

        int32_t result = ANativeWindow_setBuffersGeometry(m_application->window, width, height, ANativeWindow_getFormat(m_application->window));
        if (result != 0)
        {
            LOGE("Failed to change native window geometry: ANativeWindow_setBuffersGeometry returned %d", result);
        }
    }
}
