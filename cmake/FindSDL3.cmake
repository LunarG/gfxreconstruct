include(FetchContent)

set(SDL_GIT "https://github.com/libsdl-org/SDL.git")
set(SDL_GIT_TAG "preview-3.1.3")
message(STATUS "Fetching SDL3 files from ${SDL_GIT} ${SDL_GIT_TAG}")
FetchContent_Declare(
        sdl
        GIT_REPOSITORY ${SDL_GIT}
        GIT_TAG ${SDL_GIT_TAG}
)
FetchContent_MakeAvailable(sdl)
