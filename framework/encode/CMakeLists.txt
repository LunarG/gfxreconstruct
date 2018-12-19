add_library(gfxrecon_encode STATIC "")

target_sources(gfxrecon_encode
               PRIVATE
                   capture_settings.h
                   capture_settings.cpp
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

target_include_directories(gfxrecon_encode
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_encode gfxrecon_format gfxrecon_util vulkan_registry platform_specific)
