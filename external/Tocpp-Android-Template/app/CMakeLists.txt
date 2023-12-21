cmake_minimum_required(VERSION 3.4.1)

function(sublist INPUT_LIST START_IDX LENGTH OUTPUT_LIST)
    set(ENTRIES )
    math(EXPR END_IDX "${START_IDX} + ${LENGTH}")

    list(LENGTH ${INPUT_LIST} LIST_LENGTH)

    foreach(IDX RANGE ${START_IDX} ${END_IDX})
        if ((IDX GREATER LIST_LENGTH) OR (IDX EQUAL LIST_LENGTH))
            break()
        endif()

        list(GET ${INPUT_LIST} ${IDX} ITEM)
        list(APPEND ENTRIES ${ITEM})
    endforeach()

    set(${OUTPUT_LIST} ${ENTRIES} PARENT_SCOPE)

endfunction(sublist)

set(LIBNAME gfxtocpp)

# build native_app_glue as a static lib
set(APP_GLUE_DIR ${ANDROID_NDK}/sources/android/native_app_glue)
include_directories(${APP_GLUE_DIR})
add_library(app-glue STATIC ${APP_GLUE_DIR}/android_native_app_glue.c)

# build vulkan app
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Werror")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -u ANativeActivity_onCreate")

set(JNI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/main/jni)
set(GENERATED_FRAMES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/main/assets/src)

# Base lib
add_library(${LIBNAME}-base SHARED
            ${JNI_DIR}/ScreenOrientation.cpp
            ${GENERATED_FRAMES_DIR}/swapchain_common.cpp
            ${GENERATED_FRAMES_DIR}/swapchain_common.h
            ${GENERATED_FRAMES_DIR}/global_var.cpp
            ${GENERATED_FRAMES_DIR}/global_var.h
            ${GENERATED_FRAMES_DIR}/loader.cpp
            ${GENERATED_FRAMES_DIR}/loader.h
)
target_link_libraries(${LIBNAME}-base PUBLIC log android vulkan)
target_include_directories(${LIBNAME}-base PUBLIC ${JNI_DIR})

# Main lib
add_library(${LIBNAME} SHARED
            ${JNI_DIR}/VulkanMain.cpp
            ${JNI_DIR}/AndroidMain.cpp
)
target_link_libraries(${LIBNAME} app-glue)

target_include_directories(${LIBNAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/main/assets/src/
         ${JNI_DIR}
)

# Frame libraries
set(FILE_LIMIT 500)

file(GLOB SRC_FILES ${GENERATED_FRAMES_DIR}/frame_*.cpp)
list(SORT SRC_FILES)
list(LENGTH SRC_FILES FILE_COUNT)
math(EXPR LIB_COUNT "${FILE_COUNT} / ${FILE_LIMIT}")

foreach(LIB_IDX RANGE 0 ${LIB_COUNT})
    math(EXPR START_IDX "${LIB_IDX} * ${FILE_LIMIT}")
    sublist(SRC_FILES ${START_IDX} ${FILE_LIMIT} LIB_FILES)

    set(FRAME_LIBNAME ${LIBNAME}-frames-${LIB_IDX})
    add_library(${FRAME_LIBNAME} SHARED ${LIB_FILES})
    target_link_libraries(${FRAME_LIBNAME} PUBLIC ${LIBNAME}-base)
    target_link_libraries(${LIBNAME} ${FRAME_LIBNAME})
endforeach()
