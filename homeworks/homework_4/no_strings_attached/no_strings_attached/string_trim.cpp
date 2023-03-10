//
// Created by vuong on 1/25/23.
//

#include "string_trim.h"
namespace no_strings_attached {
    std::string Trim(const std::string &str) {
        return Trim(str, ' ', Side::kBoth);
    }
    std::string Trim(const std::string &str, char char_to_trim, Side side) {
        if (side == Side::kLeft)
            return leftTrim(str, char_to_trim);
        else if (side == Side::kRight)
            return rightTrim(str, char_to_trim);
        else {
            return rightTrim(leftTrim(str, char_to_trim), char_to_trim);
        }
    }
    std::string leftTrim(const std::string &str, char char_to_trim) {
        size_t start = str.find_first_not_of(char_to_trim);
        return (start == std::string::npos) ? "" : str.substr(start);
    }
    std::string rightTrim(const std::string &str, char char_to_trim) {
        size_t end = str.find_last_not_of(char_to_trim);
        return (end == std::string::npos) ? "" : str.substr(0, end + 1);
    }
}// namespace no_strings_attached