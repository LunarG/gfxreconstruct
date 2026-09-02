include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)

if (TARGET gtest AND NOT TARGET GTest::gtest)
    add_library(GTest::gtest ALIAS gtest)
endif()

if (TARGET gtest_main AND NOT TARGET GTest::gtest_main)
    add_library(GTest::gtest_main ALIAS gtest_main)
endif()

if (TARGET gmock AND NOT TARGET GTest::gmock)
    add_library(GTest::gmock ALIAS gmock)
endif()

if (TARGET gmock_main AND NOT TARGET GTest::gmock_main)
    add_library(GTest::gmock_main ALIAS gmock_main)
endif()

set(GTest_FOUND TRUE)
set(GoogleTest_FOUND TRUE)
