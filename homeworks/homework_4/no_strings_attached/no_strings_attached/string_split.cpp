//
// Created by vuong on 1/25/23.
//

#include "string_split.h"
namespace no_strings_attached {
    std::vector<std::string> Split(const std::string &str, const std::string &delimiter) {
        //std::cout << " Debug : function entry "<<std::endl;

        size_t next_start = delimiter.size();

        //std::cout << " Debug : next_start =  "<<next_start<<std::endl;

        size_t n;
        size_t n_temp = 0;
        std::vector<size_t> n_vec;

        std::vector<std::string> container;

        std::string split_string;
        std::string string_init = str;

        // To find indexes of all delimiter (METHOD 1)
        while (string_init.find(delimiter) != std::string::npos) {
            //std::cout << " Debug : while loop entry "<<std::endl;

            // search from beginning of string
            n = string_init.find(delimiter);
            //std::cout << "Debug : string_init & n : "<<string_init<<"--"<<n<<std::endl;

            n_vec.push_back(n + n_temp);
            //std::cout << "Debug : n+n_temp : "<<n+n_temp<<'\t';
            n_temp = n + n_temp + next_start;

            string_init = string_init.substr(n + next_start);
        }

        if (n_vec.empty()) {

            container.push_back(str);
            return container;

        } else {

            for (size_t i = 0; i < n_vec.size(); ++i) {
                //std::cout << " Debug : for loop entry "<<std::endl;

                if (n_vec.front() != 0 && i == 0) {
                    split_string = str.substr(0, n_vec.at(i));//returns [pos, pos+count)
                    container.push_back(split_string);
                    //std::cout << " Debug : @start "<<split_string<<std::endl;
                }

                auto Nstart = n_vec.at(i);

                if (i != n_vec.size() - 1) {

                    auto Nend = n_vec.at(i + 1);

                    if (Nstart + next_start > Nend - 1) {
                        split_string = "";

                    } else {
                        split_string = str.substr(Nstart + next_start, Nend - (Nstart + next_start));
                        //std::cout << " Debug : @middle "<<split_string<<std::endl;
                    }

                } else if (Nstart < str.size() - 1) {
                    split_string = str.substr(Nstart + next_start, std::string::npos);
                    //std::cout << " Debug : @end "<<split_string<<std::endl;
                }

                container.push_back(split_string);
            }
            //std::cout << " Debug : for loop end "<<std::endl;
            return container;
            //std::cout << " Debug : line after return "<<std::endl;
        }
    }

    [[maybe_unused]] std::vector<std::string> Split(const std::string &str, const std::string &delimiter, int number_of_chunks_to_keep) {
        auto result = Split(str, delimiter);
        result.resize(number_of_chunks_to_keep);
        return result;
    }
}// namespace no_strings_attached