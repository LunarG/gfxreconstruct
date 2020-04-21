# Determine the major/minor/patch version from the vulkan header
set(VULKAN_VERSION_MAJOR "0")
set(VULKAN_VERSION_MINOR "0")
set(VULKAN_VERSION_PATCH "0")

# First, determine which header we need to grab the version information from.
# Starting with Vulkan 1.1, we should use vulkan_core.h, but prior to that,
# the information was in vulkan.h.
find_file (VULKAN_HEADER
            vulkan_core.h
            HINTS
                external/Vulkan-Headers/include/vulkan
                ../external/Vulkan-Headers/include/vulkan)

MESSAGE(STATUS "Vulkan Header = ${VULKAN_HEADER}")

if (EXISTS ${VULKAN_HEADER})
    set(VulkanHeaders_main_header ${VULKAN_HEADER})
else()
    find_file(VULKAN_HEADER
                vulkan.h
                HINTS
                    external/Vulkan-Headers/include/vulkan
                    ../external/Vulkan-Headers/include/vulkan)
    set(VulkanHeaders_main_header ${VULKAN_HEADER})
endif()

# Find all lines in the header file that contain any version we may be interested in
#  NOTE: They start with #define and then have other keywords
file(STRINGS
        ${VulkanHeaders_main_header}
        VulkanHeaders_lines
        REGEX "^#[ \t]*define[ \t]+(VK_HEADER_VERSION_COMPLETE[ \t]+VK_MAKE_VERSION\\(.*\\)|VK_HEADER_VERSION[ \t]+[0-9]+)$")

foreach(VulkanHeaders_line ${VulkanHeaders_lines})
    # First, handle the case where we have a major/minor version
    #   Format is:
    #        #define VK_HEADER_VERSION_COMPLETE VK_MAKE_VERSION(X, Y, VK_HEADER_VERSION)
    #   We grab the major version (X) and minor version (Y) out of the parentheses
    string(REGEX MATCH "define[ \t]+VK_HEADER_VERSION_COMPLETE[ \t]+VK_MAKE_VERSION\\(.*\\)" VulkanHeaders_make_version ${VulkanHeaders_line})
    string(REGEX MATCHALL "[0-9]+" VulkanHeaders_MAJOR_MINOR "${VulkanHeaders_make_version}")
    if (VulkanHeaders_MAJOR_MINOR)
        list (GET VulkanHeaders_MAJOR_MINOR 0 VULKAN_VERSION_MAJOR)
        list (GET VulkanHeaders_MAJOR_MINOR 1 VULKAN_VERSION_MINOR)
    endif()

    # Second, handle the case where we have the patch version
    #   Format is:
    #      #define VK_HEADER_VERSION Z
    #   Where Z is the patch version which we just grab off the end
    string(REGEX MATCH "define[ \t]+VK_HEADER_VERSION[ \t]+[0-9]+" VulkanHeaders_header_version ${VulkanHeaders_line})
    list(LENGTH VulkanHeaders_header_version VulkanHeaders_len)
    if (VulkanHeaders_header_version)
        string(REGEX MATCH "[0-9]+" VULKAN_VERSION_PATCH "${VulkanHeaders_header_version}")
    endif()
endforeach()

if (VULKAN_VERSION_MAJOR STREQUAL "")
        message(FATAL_ERROR "Failed to find major version in " ${VulkanHeaders_main_header})
endif()

if (VULKAN_VERSION_MINOR STREQUAL "")
        message(FATAL_ERROR "Failed to find minor version in " ${VulkanHeaders_main_header})
endif()

if (VULKAN_VERSION_PATCH STREQUAL "")
        message(FATAL_ERROR "Failed to find patch version in " ${VulkanHeaders_main_header})
endif()

MESSAGE(STATUS
        "Detected Vulkan Version ${VULKAN_VERSION_MAJOR}."
        "${VULKAN_VERSION_MINOR}."
        "${VULKAN_VERSION_PATCH}")
