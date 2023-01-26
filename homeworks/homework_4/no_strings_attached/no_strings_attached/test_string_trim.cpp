//
// Created by vuong on 1/25/23.
//
#include "string_trim.h"
#include <gtest/gtest.h>

namespace {
    using no_strings_attached::Side;
    using no_strings_attached::Trim;
}// namespace

TEST(TestTrimString, TrimStringLeft) {
    auto result = Trim("  hello ", ' ',
                       Side::kLeft);
    EXPECT_EQ(result, std::string{"hello "});
}
TEST(TestTrimString, TrimStringRight) {
    auto result = Trim("  hello ", ' ',
                       Side::kRight);
    EXPECT_EQ(result, std::string{"  hello"});
}
TEST(TestTrimString, TrimStringBoth) {
    auto result = Trim("  hello ", ' ',
                       Side::kBoth);
    EXPECT_EQ(result, std::string{"hello"});
}
TEST(TestTrimString, TrimStringWithCharDel) {
    auto result = Trim("hello", 'h',
                       Side::kLeft);
    assert(result == std::string{"ello"});
    EXPECT_EQ(result, std::string{"ello"});
}
TEST(TestTrimString, TrimStringOverloadFunc) {
    auto result = Trim("  hello ");
    assert(result == std::string{"hello"});
    EXPECT_EQ(result, std::string{"hello"});
}
TEST(TrimValidationTest, TrimTrivial) {
    const auto test_string = "hello";
    const auto trimmed_both_sides = Trim(test_string);
    const auto trimmed_both_sides_explicit = Trim(test_string, ' ',
                                                  Side::kBoth);
    const auto trimmed_left_side = Trim(test_string, ' ',
                                        Side::kLeft);
    const auto trimmed_right_side = Trim(test_string, ' ',
                                         Side::kRight);
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
    const auto trimmed_both_sides = Trim(test_string);
    const auto trimmed_both_sides_explicit = Trim(test_string, ' ',
                                                  Side::kBoth);
    const auto trimmed_left_side = Trim(test_string, ' ',
                                        Side::kLeft);
    const auto trimmed_right_side = Trim(test_string, ' ',
                                         Side::kRight);
    EXPECT_EQ(trimmed_both_sides, test_string);
    EXPECT_EQ(trimmed_both_sides_explicit, test_string);
    EXPECT_EQ(trimmed_left_side, test_string);
    EXPECT_EQ(trimmed_right_side, test_string);
}