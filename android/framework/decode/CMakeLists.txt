add_library(brimstone_decode STATIC "")

target_sources(brimstone_decode
               PRIVATE
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/api_decoder.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/custom_vulkan_struct_decoders.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/custom_vulkan_struct_decoders.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/custom_vulkan_struct_decoders_forward.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/compression_converter.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/compression_converter.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/descriptor_update_template_decoder.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/descriptor_update_template_decoder.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/file_processor.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/file_processor.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/pnext_node.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/pnext_null_node.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/pnext_typed_node.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/pointer_decoder_base.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/pointer_decoder.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/string_array_decoder.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/string_decoder.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/struct_pointer_decoder.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/struct_pointer_decoder_nvx.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/value_decoder.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/vulkan_ascii_consumer_base.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/vulkan_ascii_consumer_base.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/vulkan_consumer_base.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/vulkan_decoder_base.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/vulkan_decoder_base.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/vulkan_enum_util.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/vulkan_object_mapper.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/vulkan_replay_consumer_base.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/vulkan_replay_consumer_base.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/decode/window.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_ascii_consumer.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_ascii_consumer.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_consumer.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders_forward.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.h
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.cpp
                   ${BRIMSTONE_SOURCE_DIR}/framework/generated/generated_decode_pnext_struct.cpp
              )

target_include_directories(brimstone_decode
                           PUBLIC
                               ${BRIMSTONE_SOURCE_DIR}/framework)

target_link_libraries(brimstone_decode brimstone_format brimstone_util volk vulkan_registry platform_specific)
