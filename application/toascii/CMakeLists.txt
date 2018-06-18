add_executable(grectoascii "")

target_sources(grectoascii
               PUBLIC
                   ${CMAKE_SOURCE_DIR}/external/Vulkan-Headers/include/vulkan/vulkan.h
               PRIVATE
                   main.cpp
              )

target_link_libraries(grectoascii brimstone_format)

target_include_directories(grectoascii
                           PUBLIC
                               ${CMAKE_SOURCE_DIR}/external/Vulkan-Headers/include
                          )
