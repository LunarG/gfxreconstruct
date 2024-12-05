include(FetchContent)
FetchContent_Declare(
        sdl
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG preview-3.1.3
)
FetchContent_MakeAvailable(sdl)
