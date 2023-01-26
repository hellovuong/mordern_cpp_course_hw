add_library(string_split string_split.cpp)
target_link_libraries(string_split PUBLIC cxx_setup)

add_library(string_trim string_trim.cpp)
target_link_libraries(string_trim PUBLIC cxx_setup)

if (BUILD_TESTING)
    add_executable(trim_string_test test_string_trim.cpp)
    target_link_libraries(trim_string_test PRIVATE string_trim GTest::gtest_main)

    add_executable(split_string_test test_string_split.cpp)
    target_link_libraries(split_string_test PRIVATE string_split GTest::gtest_main)

    include(GoogleTest)
    # Finds all the Google tests associated with the executable
    gtest_discover_tests(trim_string_test)
    gtest_discover_tests(split_string_test)
endif ()