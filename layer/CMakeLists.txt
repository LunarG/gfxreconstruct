add_library(brimstone_layer SHARED)

target_sources(brimstone_layer
               PRIVATE
                   trace_layer.h
                   dll_main.cpp
                   trace_layer.cpp
                   $<$<BOOL:WIN32>:trace_layer.def>
              )

target_include_directories(brimstone_layer
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(brimstone_layer brimstone_format brimstone_generated vulkan_registry platform_specific)
