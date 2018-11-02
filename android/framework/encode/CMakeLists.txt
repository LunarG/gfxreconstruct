add_library(brimstone_encode STATIC "")

target_sources(brimstone_encode
               PRIVATE
                   ${BRIMSTONE_SOURCE_DIR}/framework/encode/custom_encoder_commands.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/encode/custom_vulkan_struct_encoders.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/encode/custom_vulkan_struct_encoders.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/encode/memory_tracker.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/encode/memory_tracker.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/encode/parameter_encoder.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/encode/struct_pointer_encoder.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/encode/trace_manager.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/encode/trace_manager.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_encoders.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_encode_pnext_struct.cpp
              )

target_include_directories(brimstone_encode
                           PUBLIC
                               ${BRIMSTONE_SOURCE_DIR}/framework)

target_link_libraries(brimstone_encode brimstone_format brimstone_util vulkan_registry platform_specific)
