add_library(brimstone_encode STATIC "")

target_sources(brimstone_encode
               PRIVATE
                   custom_encoder_commands.h
                   custom_vulkan_struct_encoders.h
                   custom_vulkan_struct_encoders.cpp
                   memory_tracker.h
                   memory_tracker.cpp
                   parameter_encoder.h
                   struct_pointer_encoder.h
                   trace_manager.h
                   trace_manager.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.h
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.cpp
                   ${CMAKE_SOURCE_DIR}/framework/generated/generated_encode_pnext_struct.cpp
              )

target_include_directories(brimstone_encode
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(brimstone_encode brimstone_format brimstone_util vulkan_registry platform_specific)
