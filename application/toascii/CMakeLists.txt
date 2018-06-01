set(SOURCE_FILES
    main.cpp)

add_executable(grectoascii ${SOURCE_FILES})

target_link_libraries(grectoascii brimstone_format)
