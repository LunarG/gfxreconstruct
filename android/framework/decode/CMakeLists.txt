add_library(gfxrecon_decode STATIC "")

target_sources(gfxrecon_decode
               PRIVATE
                   ${GFXRECON_SOURCE_DIR}/framework/decode/api_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/custom_vulkan_struct_decoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/custom_vulkan_struct_decoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/custom_vulkan_struct_decoders_forward.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/compression_converter.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/compression_converter.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/descriptor_update_template_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/descriptor_update_template_decoder.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/file_processor.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/file_processor.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/handle_pointer_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/pnext_node.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/pnext_typed_node.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/pointer_decoder_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/pointer_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/string_array_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/string_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/struct_pointer_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/struct_pointer_decoder_nvx.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/value_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_ascii_consumer_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_ascii_consumer_base.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_consumer_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_decoder_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_decoder_base.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_enum_util.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_object_mapper.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_consumer_base.h
                   ${GFXRECON_SOURCE_DIR}/framework/decode/vulkan_replay_consumer_base.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/decode/window.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_ascii_consumer.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_ascii_consumer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_consumer.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_decoder.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_replay_consumer.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders_forward.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_decoders.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.h
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_vulkan_struct_handle_mappers.cpp
                   ${GFXRECON_SOURCE_DIR}/framework/generated/generated_decode_pnext_struct.cpp
              )

target_include_directories(gfxrecon_decode
                           PUBLIC
                               ${GFXRECON_SOURCE_DIR}/framework)

target_link_libraries(gfxrecon_decode gfxrecon_format gfxrecon_util vulkan_registry platform_specific)
