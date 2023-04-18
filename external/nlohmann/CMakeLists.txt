cmake_minimum_required(VERSION 3.1)

##
## PROJECT
## name and version
##
project(nlohmann_json VERSION 3.10.5 LANGUAGES CXX)


##
## OPTIONS
##

if (POLICY CMP0077)
    # Allow CMake 3.13+ to override options when using FetchContent / add_subdirectory.
    cmake_policy(SET CMP0077 NEW)
endif ()

option(JSON_Diagnostics                    "Use extended diagnostic messages." OFF)
option(JSON_ImplicitConversions            "Enable implicit conversions." ON)
option(JSON_DisableEnumSerialization       "Disable default integer enum serialization." OFF)
option(JSON_LegacyDiscardedValueComparison "Enable legacy discarded value comparison." OFF)           
option(JSON_SystemInclude                  "Include as system headers (skip for clang-tidy)." OFF)


##
## CONFIGURATION
##
set(NLOHMANN_JSON_TARGET_NAME               ${PROJECT_NAME})

set(NLOHMANN_JSON_INCLUDE_BUILD_DIR "${PROJECT_SOURCE_DIR}/include/")

if (NOT JSON_ImplicitConversions)
    message(STATUS "Implicit conversions are disabled")
endif()

if (JSON_DisableEnumSerialization)
    message(STATUS "Enum integer serialization is disabled")
endif()

if (JSON_LegacyDiscardedValueComparison)
    message(STATUS "Legacy discarded value comparison enabled")
endif()

if (JSON_Diagnostics)
    message(STATUS "Diagnostics enabled")
endif()

if (JSON_SystemInclude)
    set(NLOHMANN_JSON_SYSTEM_INCLUDE "SYSTEM")
endif()

##
## TARGET
## create target and add include path
##
add_library(${NLOHMANN_JSON_TARGET_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${NLOHMANN_JSON_TARGET_NAME} ALIAS ${NLOHMANN_JSON_TARGET_NAME})
if (${CMAKE_VERSION} VERSION_LESS "3.8.0")
    target_compile_features(${NLOHMANN_JSON_TARGET_NAME} INTERFACE cxx_range_for)
else()
    target_compile_features(${NLOHMANN_JSON_TARGET_NAME} INTERFACE cxx_std_11)
endif()

target_compile_definitions(
    ${NLOHMANN_JSON_TARGET_NAME}
    INTERFACE
    $<$<NOT:$<BOOL:${JSON_ImplicitConversions}>>:JSON_USE_IMPLICIT_CONVERSIONS=0>
    $<$<BOOL:${JSON_DisableEnumSerialization}>:JSON_DISABLE_ENUM_SERIALIZATION=1>
    $<$<BOOL:${JSON_Diagnostics}>:JSON_DIAGNOSTICS=1>
    $<$<BOOL:${JSON_LegacyDiscardedValueComparison}>:JSON_USE_LEGACY_DISCARDED_VALUE_COMPARISON=1>
)

target_include_directories(
    ${NLOHMANN_JSON_TARGET_NAME}
    ${NLOHMANN_JSON_SYSTEM_INCLUDE} INTERFACE
    $<BUILD_INTERFACE:${NLOHMANN_JSON_INCLUDE_BUILD_DIR}>
    $<INSTALL_INTERFACE:include>
)

