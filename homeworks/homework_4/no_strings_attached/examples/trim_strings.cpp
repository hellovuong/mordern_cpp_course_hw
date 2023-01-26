//
// Created by vuong on 1/22/23.
//
#include "no_strings_attached/string_trim.h"

#include <iostream>
#include <string>

int main() {
    std::string string_to_be_trimmed;

    std::cout << "Example program that trims strings." << std::endl;
    std::cout << "Please enter a string:" << std::endl;
    std::getline(std::cin, string_to_be_trimmed);

    std::string Trimmed_string = no_strings_attached::Trim(string_to_be_trimmed);
    std::cout << "Your trimmed string: ";
    std::cout << "'" << Trimmed_string << "'";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}