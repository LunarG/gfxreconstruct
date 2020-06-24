add_library(gfxrecon_tcp_client STATIC "")

target_sources(gfxrecon_tcp_client
               PRIVATE
                    ${CMAKE_CURRENT_LIST_DIR}/tcp_client.h
                    ${CMAKE_CURRENT_LIST_DIR}/tcp_client.cpp
              )

target_include_directories(gfxrecon_tcp_client
                           PUBLIC
                               $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>/framework)

target_link_libraries(gfxrecon_tcp_client
                      $<$<BOOL:${WIN32}>:Ws2_32.lib>)

common_build_directives(gfxrecon_tcp_client)

add_executable(gfxrecon_tcp_client_test "")

target_sources(gfxrecon_tcp_client_test
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/test/main.cpp)

common_build_directives(gfxrecon_tcp_client_test)
common_test_directives(gfxrecon_tcp_client_test)
