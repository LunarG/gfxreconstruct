include(FetchContent)

set(SDL_GIT "https://github.com/libsdl-org/SDL.git")
message(STATUS "Fetching SDL2 files from ${SDL_GIT}")
FetchContent_Declare(
        sdl
        GIT_REPOSITORY ${SDL_GIT}
        GIT_TAG preview-3.1.3
)
FetchContent_MakeAvailable(sdl)
