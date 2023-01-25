//
// Created by vuong on 1/25/23.
//

#include "string_split.h"
#include <gtest/gtest.h>
// TEST is a macro, i.e., preprocessor replaces it with some code

namespace {
    using no_strings_attached::Split;
}
TEST(SplitValidationTest, SplitDelimeterNotFound) {
    auto test_string = "";
    const auto split_on_empty = Split("", " ");
    std::cout <<  split_on_empty.size() << std::endl;
    ASSERT_FALSE(split_on_empty.empty())
            << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("", split_on_empty.front())
            << "Failed to split: '" << test_string << "'";
    test_string = "hello";
    const auto split_no_space = Split(test_string, " ");
    ASSERT_FALSE(split_no_space.empty())
            << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("hello", split_no_space.front())
            << "Failed to split: '" << test_string << "'";
}

TEST(SplitValidationTest, SplitTwoWordsOnString) {
    const auto test_string = "hello world";
    const auto split = Split(test_string, " ");
    ASSERT_EQ(2UL, split.size()) << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("hello", split.front())
            << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("world", split.back())
            << "Failed to split: '" << test_string << "'";
}

TEST(SplitValidationTest, SplitMoreWords) {
    const auto test_string = "some_string__split__with_underscores";
    const auto split = Split(test_string, "__");
    ASSERT_EQ(3UL, split.size()) << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("some_string", split[0])
            << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("split", split[1]) << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("with_underscores", split[2])
            << "Failed to split: '" << test_string << "'";
}

TEST(SplitValidationTest, RepeatedString) {
    const auto test_string = "split_me__and_me";
    const auto split = Split(test_string, "_");
    ASSERT_EQ(5UL, split.size()) << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("split", split[0]) << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("me", split[1]) << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("", split[2]) << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("and", split[3]) << "Failed to split: '" << test_string << "'";
    EXPECT_EQ("me", split[4]) << "Failed to split: '" << test_string << "'";
}