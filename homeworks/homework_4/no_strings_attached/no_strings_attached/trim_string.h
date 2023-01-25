//
// Created by vuong on 1/25/23.
//

#ifndef NO_STRINGS_ATTACHED_TRIM_STRING_H
#define NO_STRINGS_ATTACHED_TRIM_STRING_H

#include <string>
namespace no_strings_attached {
    class trim_string {
    public:
        trim_string() = default;
        enum class Side {
            kLeft,
            kRight,
            kBoth
        };
        static std::string Trim(const std::string &str);
        static std::string Trim(const std::string &str, char char_to_trim, Side side);
    private:
        static std::string leftTrim(const std::string &str, char char_to_trim);
        static std::string rightTrim(const std::string &str, char char_to_trim);
    };
}// namespace no_strings_attached

#endif//NO_STRINGS_ATTACHED_TRIM_STRING_H
