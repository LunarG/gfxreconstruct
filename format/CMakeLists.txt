add_library(brimstone_format STATIC)

target_sources(brimstone_format
               PRIVATE
                   api_call_id.h
                   decoder.h
                   file_processor.h
                   format.h
                   parameter_encoder.h
                   pnext_node.h
                   pnext_null_node.h
                   pnext_typed_node.h
                   pointer_decoder_base.h
                   pointer_decoder.h
                   string_array_decoder.h
                   string_decoder.h
                   struct_pointer_decoder.h
                   trace_manager.h
                   trace_pnext_util.h
                   value_decoder.h
                   vulkan_ascii_consumer.h
                   vulkan_replay_consumer.h
                   vulkan_consumer.h
                   vulkan_decoder.h
                   vulkan_object_mapper.h
                   file_processor.cpp
                   string_array_decoder.cpp
                   string_decoder.cpp
                   trace_manager.cpp
                   vulkan_ascii_consumer.cpp
                   vulkan_replay_consumer.cpp
                   vulkan_decoder.cpp
              )

target_include_directories(brimstone_format
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>)

target_link_libraries(brimstone_format brimstone_util vulkan_registry platform_specific)
