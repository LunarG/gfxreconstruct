add_library(gfxrecon_encode STATIC "")

target_sources(gfxrecon_encode
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_encoder_commands.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_encoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/custom_vulkan_struct_encoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/memory_tracker.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/memory_tracker.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/encode/parameter_encoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/struct_pointer_encoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/trace_manager.h
                   ${GFXRECON_SOURCE_DIR}/framework/encode/trace_manager.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_encode_pnext_struct.cpp
              )

target_include_directories(gfxrecon_encode
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_encode gfxrecon_format gfxrecon_util vulkan_registry platform_specific)
