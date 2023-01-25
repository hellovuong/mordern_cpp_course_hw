//
// Created by vuong on 1/25/23.
//
#include "trim_string.h"
#include <gtest/gtest.h>

TEST(TestTrimString, TrimStringLeft) {
    auto result = no_strings_attached::trim_string::Trim("  hello ", ' ',
                                                         no_strings_attached::trim_string::Side::kLeft);
    EXPECT_EQ(result, std::string{"hello "});
}
TEST(TestTrimString, TrimStringRight) {
    auto result = no_strings_attached::trim_string::Trim("  hello ", ' ',
                                                         no_strings_attached::trim_string::Side::kRight);
    EXPECT_EQ(result, std::string{"  hello"});
}
TEST(TestTrimString, TrimStringBoth) {
    auto result = no_strings_attached::trim_string::Trim("  hello ", ' ',
                                                         no_strings_attached::trim_string::Side::kBoth);
    EXPECT_EQ(result, std::string{"hello"});
}
TEST(TestTrimString, TrimStringWithCharDel) {
    auto result = no_strings_attached::trim_string::Trim("hello", 'h',
                                                         no_strings_attached::trim_string::Side::kLeft);
    assert(result == std::string{"ello"});
    EXPECT_EQ(result, std::string{"ello"});
}
TEST(TestTrimString, TrimStringOverloadFunc) {
    auto result = no_strings_attached::trim_string::Trim("  hello ");
    assert(result == std::string{"hello"});
    EXPECT_EQ(result, std::string{"hello"});
}
TEST(TrimValidationTest, TrimTrivial) {
    const auto test_string = "hello";
    const auto trimmed_both_sides = no_strings_attached::trim_string::Trim(test_string);
    const auto trimmed_both_sides_explicit = no_strings_attached::trim_string::Trim(test_string, ' ',
                                                                                    no_strings_attached::trim_string::Side::kBoth);
    const auto trimmed_left_side = no_strings_attached::trim_string::Trim(test_string, ' ',
                                                                          no_strings_attached::trim_string::Side::kLeft);
    const auto trimmed_right_side = no_strings_attached::trim_string::Trim(test_string, ' ',
                                                                           no_strings_attached::trim_string::Side::kRight);
    EXPECT_EQ(trimmed_both_sides, test_string)
            << "Failed to trim string: '" << test_string << "'";
    EXPECT_EQ(trimmed_both_sides_explicit, test_string)
            << "Failed to trim string: '" << test_string << "'";
    EXPECT_EQ(trimmed_left_side, test_string)
            << "Failed to trim string: '" << test_string << "'";
    EXPECT_EQ(trimmed_right_side, test_string)
            << "Failed to trim string: '" << test_string << "'";
}
TEST(TrimValidationTest, TrimEmpty) {
    const auto test_string = "";
    const auto trimmed_both_sides = no_strings_attached::trim_string::Trim(test_string);
    const auto trimmed_both_sides_explicit = no_strings_attached::trim_string::Trim(test_string, ' ',
                                                                                    no_strings_attached::trim_string::Side::kBoth);
    const auto trimmed_left_side = no_strings_attached::trim_string::Trim(test_string, ' ',
                                                                          no_strings_attached::trim_string::Side::kLeft);
    const auto trimmed_right_side = no_strings_attached::trim_string::Trim(test_string, ' ',
                                                                           no_strings_attached::trim_string::Side::kRight);
    EXPECT_EQ(trimmed_both_sides, test_string);
    EXPECT_EQ(trimmed_both_sides_explicit, test_string);
    EXPECT_EQ(trimmed_left_side, test_string);
    EXPECT_EQ(trimmed_right_side, test_string);
}