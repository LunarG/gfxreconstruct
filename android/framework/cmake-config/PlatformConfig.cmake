set(CMAKE_CXX_STANDARD 17)
set(CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH "${GFXRECON_SOURCE_DIR}/external/cmake-modules")

# Version info
set(GFXRECONSTRUCT_PROJECT_VERSION_MAJOR 0)
set(GFXRECONSTRUCT_PROJECT_VERSION_MINOR 9)
set(GFXRECONSTRUCT_PROJECT_VERSION_PATCH 19)

set(GFXRECON_PROJECT_VERSION_DESIGNATION "-unknown")
set(GFXRECON_PROJECT_VERSION_SHA1 "unknown-build-source")

include(GetGitRevisionDescription)
get_git_head_revision(GIT_REFSPEC GIT_SHA1)
set(GIT_BRANCH "")

if (GIT_REFSPEC)
    string(REGEX REPLACE ".*/(.+)$" "\\1" GIT_BRANCH ${GIT_REFSPEC})
    string(COMPARE EQUAL ${GIT_BRANCH} "master" GIT_IS_MASTER)

    if (GIT_IS_MASTER)
        git_get_exact_tag(GIT_TAG)
        if (GIT_TAG)
            set(GIT_BRANCH ${GIT_TAG})
        else()
            set(GIT_BRANCH "")
        endif()
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "")
    else()
        set(GFXRECON_PROJECT_VERSION_DESIGNATION "-dev")
    endif()
endif()

if (GIT_SHA1)
    string(SUBSTRING ${GIT_SHA1} 0 7 GFXRECON_PROJECT_VERSION_SHA1)

    if (GIT_BRANCH)
        string(CONCAT GFXRECON_PROJECT_VERSION_SHA1 ${GIT_BRANCH} ":" ${GFXRECON_PROJECT_VERSION_SHA1})
    endif()

    git_local_changes(GIT_LOCAL_STATE)
    string(COMPARE EQUAL ${GIT_LOCAL_STATE} "DIRTY" GIT_DIRTY)
    if (GIT_DIRTY)
        string(CONCAT GFXRECON_PROJECT_VERSION_SHA1 ${GFXRECON_PROJECT_VERSION_SHA1} "*")
    endif()
endif()

configure_file("${GFXRECON_SOURCE_DIR}/project_version.h.in" "${CMAKE_BINARY_DIR}/project_version.h")

add_library(platform_specific INTERFACE)
target_compile_definitions(platform_specific INTERFACE _FILE_OFFSET_BITS=64 PAGE_GUARD_ENABLE_UCONTEXT_WRITE_DETECTION VK_USE_PLATFORM_ANDROID_KHR)

add_library(vulkan_registry INTERFACE)
target_include_directories(vulkan_registry INTERFACE ${GFXRECON_SOURCE_DIR}/external/Vulkan-Headers/include)
target_compile_definitions(vulkan_registry INTERFACE VK_NO_PROTOTYPES VK_ENABLE_BETA_EXTENSIONS)

add_library(vulkan_memory_allocator INTERFACE)
target_include_directories(vulkan_memory_allocator INTERFACE ${GFXRECON_SOURCE_DIR}/external/VulkanMemoryAllocator/include)
