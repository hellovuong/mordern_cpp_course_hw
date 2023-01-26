//
// Created by vuong on 1/25/23.
//

#ifndef NO_STRINGS_ATTACHED_STRING_TRIM_H
#define NO_STRINGS_ATTACHED_STRING_TRIM_H

#include <string>
namespace no_strings_attached {
    enum class Side {
        kLeft,
        kRight,
        kBoth
    };
    std::string Trim(const std::string &str);
    std::string Trim(const std::string &str, char char_to_trim, Side side);
    std::string leftTrim(const std::string &str, char char_to_trim);
    std::string rightTrim(const std::string &str, char char_to_trim);
}// namespace no_strings_attached

#endif//NO_STRINGS_ATTACHED_STRING_TRIM_H
