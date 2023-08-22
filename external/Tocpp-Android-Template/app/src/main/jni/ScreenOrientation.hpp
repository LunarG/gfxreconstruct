#ifndef __SCREENORIENTATION_HPP__
#define __SCREENORIENTATION_HPP__

#include <android_native_app_glue.h>

class AndroidScreen {
public:
    enum ScreenOrientation : int32_t
    {
        kLandscape = 0,
        kPortrait  = 1
    };

    enum ResizeWindowPreTransform : uint32_t
    {
        kPreTransform0   = 0,
        kPreTransform90  = 1,
        kPreTransform180 = 2,
        kPreTransform270 = 3
    };

    AndroidScreen() {};
    AndroidScreen(android_app* application);
    void windowSetSizePreTransform(const uint32_t width, const uint32_t height, const uint32_t pre_transform);

private:
    android_app* m_application;
    int32_t m_width;
    int32_t m_height;
    int32_t m_pretransform;

    void windowSetOrientation(ScreenOrientation orientation);
};

#endif // __SCREENORIENTATION_HPP__
