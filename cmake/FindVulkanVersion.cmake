# Determine the major/minor/patch version from the vulkan header
set(VULKAN_VERSION_MAJOR "")
set(VULKAN_VERSION_MINOR "")
set(VULKAN_VERSION_PATCH "")

# Save away a copy of the script's directory
set(FIND_VULKAN_DIR ${CMAKE_CURRENT_LIST_DIR})

# First, determine which header we need to grab the version information from.
# Starting with Vulkan 1.1, we should use vulkan_core.h, but prior to that,
# the information was in vulkan.h.

find_file (VULKAN_HEADER
            vulkan_core.h
            HINTS
                external/Vulkan-Headers/include/vulkan
		${FIND_VULKAN_DIR}/../external/Vulkan-Headers/include/vulkan
		${FIND_VULKAN_DIR}/../../external/Vulkan-Headers/include/vulkan
	    NO_DEFAULT_PATH
	    NO_CMAKE_FIND_ROOT_PATH
	)

MESSAGE(STATUS "Vulkan Header = ${VULKAN_HEADER}")

if (EXISTS ${VULKAN_HEADER})
    set(VulkanHeaders_main_header ${VULKAN_HEADER})
else()
    find_file(VULKAN_HEADER
                vulkan.h
                HINTS
                    external/Vulkan-Headers/include/vulkan
		    ${FIND_VULKAN_DIR}/../external/Vulkan-Headers/include/vulkan
		    ${FIND_VULKAN_DIR}/../../external/Vulkan-Headers/include/vulkan
	        NO_DEFAULT_PATH
	        NO_CMAKE_FIND_ROOT_PATH
	)
    set(VulkanHeaders_main_header ${VULKAN_HEADER})
endif()

# Find all lines in the header file that contain any version we may be interested in
#  NOTE: They start with #define and then have other keywords
file(STRINGS
        ${VulkanHeaders_main_header}
        VulkanHeaders_lines
        REGEX "^#[ \t]*define[ \t]+VK_HEADER_VERSION(_COMPLETE)?[ \t]")

foreach(VulkanHeaders_line ${VulkanHeaders_lines})
    # First, handle the case where we have a major/minor version
    #   Format is:
    #        #define VK_HEADER_VERSION_COMPLETE VK_MAKE_API_VERSION(0, X, Y, VK_HEADER_VERSION)
    #   We grab the major version (X) and minor version (Y) out of the parentheses
    string(REGEX MATCH "define[ \t]+VK_HEADER_VERSION_COMPLETE[ \t]+VK_MAKE_API_VERSION\\(.*\\)" VulkanHeaders_make_version ${VulkanHeaders_line})
    string(REGEX MATCHALL "[0-9]+" VulkanHeaders_MAJOR_MINOR "${VulkanHeaders_make_version}")
    if (VulkanHeaders_MAJOR_MINOR)
        list (GET VulkanHeaders_MAJOR_MINOR 1 VULKAN_VERSION_MAJOR)
        list (GET VulkanHeaders_MAJOR_MINOR 2 VULKAN_VERSION_MINOR)
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

# Restore the sysroot and prefix path CMake variables
#set(CMAKE_SYSROOT ${OLD_CMAKE_SYSROOT})
#set(CMAKE_PREFIX_PATH ${OLD_CMAKE_PREFIX_PATH})
#set(CMAKE_FIND_ROOT_PATH ${OLD_CMAKE_FIND_ROOT_PATH})
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ${OLD_CMAKE_FIND_ROOT_PATH_MODE_LIBRARY})
