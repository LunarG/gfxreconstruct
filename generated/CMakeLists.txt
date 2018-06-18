add_library(brimstone_generated INTERFACE)

target_sources(brimstone_generated
               INTERFACE
                   ${CMAKE_CURRENT_SOURCE_DIR}/generated_api_call_encoders.inc
              )

target_compile_definitions(brimstone_generated INTERFACE LIBRARY_HEADER_ONLY)
