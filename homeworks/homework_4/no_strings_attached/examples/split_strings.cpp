//
// Created by vuong on 1/22/23.
//
#include "no_strings_attached/string_split.h"
#include <iostream>

int main() {

    std::string string_to_be_splitted;
    std::string delimiter = " ";

    std::cout << "Example program that splits strings." << std::endl;
    std::cout << "Please enter a string:" << std::endl;
    std::getline(std::cin, string_to_be_splitted);

    std::vector<std::string> Splitted_string = no_strings_attached::Split(string_to_be_splitted, delimiter);

    std::cout << "Your split string: ";
    for (const auto &index1: Splitted_string) {
        std::cout << "'" << index1 << "'" << ' ';
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}