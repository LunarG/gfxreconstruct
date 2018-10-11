add_library(brimstone_format STATIC "")

target_sources(brimstone_format
               PRIVATE
                   api_call_id.h
                   custom_struct_decoders.h
                   custom_struct_decoders_forward.h
                   custom_struct_encoders.h
                   custom_encoder_commands.h
                   decoder.h
                   descriptor_update_template_decoder.h
                   file_processor.h
                   format.h
                   memory_tracker.h
                   parameter_encoder.h
                   platform_types.h
                   pnext_node.h
                   pnext_null_node.h
                   pnext_typed_node.h
                   pointer_decoder_base.h
                   pointer_decoder.h
                   string_array_decoder.h
                   string_decoder.h
                   struct_pointer_decoder.h
                   struct_pointer_decoder_nvx.h
                   struct_pointer_encoder.h
                   trace_manager.h
                   value_decoder.h
                   vulkan_ascii_consumer.h
                   vulkan_replay_consumer.h
                   vulkan_consumer.h
                   vulkan_decoder.h
                   vulkan_enum_util.h
                   vulkan_object_mapper.h
                   window.h
                   decompress_decoder.h
                   custom_struct_decoders.cpp
                   custom_struct_encoders.cpp
                   descriptor_update_template_decoder.cpp
                   file_processor.cpp
                   memory_tracker.cpp
                   trace_manager.cpp
                   vulkan_ascii_consumer.cpp
                   vulkan_replay_consumer.cpp
                   vulkan_decoder.cpp
                   decompress_decoder.cpp
              )

target_include_directories(brimstone_format
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(brimstone_format brimstone_util volk vulkan_registry platform_specific)
