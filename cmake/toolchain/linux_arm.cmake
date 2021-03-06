set(CMAKE_SYSTEM_NAME Linux CACHE STRING "System Name")
set(CMAKE_SYSTEM_PROCESSOR arm CACHE STRING "System Processor")
set(CMAKE_C_COMPILER "arm-linux-gnueabihf-gcc")
set(CMAKE_CXX_COMPILER "arm-linux-gnueabihf-g++")
set(CMAKE_C_COMPILER_ID "GNU")
set(CMAKE_CXX_COMPILER_ID "GNU")
set(CMAKE_AR ar CACHE STRING "ar")
set(CMAKE_CXX_COMPILER_WORKS TRUE)
set(CMAKE_C_COMPILER_WORKS TRUE)
set(NO_XCB TRUE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mfloat-abi=hard" CACHE STRING "c flags")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfloat-abi=hard" CACHE STRING "c++ flags")
