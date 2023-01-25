add_library(tools string_split.cpp
        string_split.h
        string_trim.cpp
        string_trim.h)
target_link_libraries(tools PUBLIC cxx_setup)
if (BUILD_TESTING)
    add_executable(trim_string_test test_string_trim.cpp)
    target_link_libraries(trim_string_test PRIVATE tools GTest::gtest_main)

    add_executable(split_string_test test_string_split.cpp)
    target_link_libraries(split_string_test PRIVATE tools GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(trim_string_test)
    gtest_discover_tests(split_string_test)
endif ()