add_library(tools split_string.cpp
        split_string.h
        trim_string.cpp
        trim_string.h)
target_link_libraries(tools PUBLIC cxx_setup)
if (BUILD_TESTING)
    add_executable(trim_string_test trim_string_test.cpp)
    target_link_libraries(trim_string_test PRIVATE tools GTest::gtest_main)

    add_executable(split_string_test split_string_test.cpp)
    target_link_libraries(split_string_test PRIVATE tools GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(trim_string_test)
    gtest_discover_tests(split_string_test)
endif ()