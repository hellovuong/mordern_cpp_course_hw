//
// Created by vuong on 1/25/23.
//

#ifndef NO_STRINGS_ATTACHED_SPLIT_STRING_H
#define NO_STRINGS_ATTACHED_SPLIT_STRING_H


#include <string>
#include <vector>
namespace no_strings_attached {
    class split_string {
    public:
        split_string() = default;
        static std::vector<std::string> Split(const std::string &str, const std::string &delimiter);
        [[maybe_unused]] static std::vector<std::string> Split(const std::string &str, const std::string &delimiter,
                                                               int number_of_chunks_to_keep);
    };
}// namespace no_strings_attached
#endif//NO_STRINGS_ATTACHED_SPLIT_STRING_H