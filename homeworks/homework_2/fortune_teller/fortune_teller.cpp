//
// Created by vuong on 1/22/23.
//
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <map>

int main() {
    std::cout << "Welcome to the fortune teller program!\n";
    std::cout << "Please enter your name:\n";
    // input[0]: name
    std::string name;
    std::cin >> name;
    // input[1]: time
    std::string time;
    std::vector<std::string> time_of_year {"spring", "summer", "autumn", "winter"};

    std::cout << "Please enter the time of year when you were born:\n" <<
                    "(pick from 'spring', 'summer', 'autumn', 'winter')" << std::endl;
    std::cin >> time;
    assert(std::count(time_of_year.begin(), time_of_year.end(), time));
    // input[2]: adj1
    std::string adj1;
    std::cout << "Please enter an adjective:\n";
    std::cin >> adj1;
    // input[2]: adj2
    std::string adj2;
    std::cout << "Please enter another adjective:\n";
    std::cin >> adj2;
    // output adj vec
    std::vector<std::string> output_adj {"eats UB for breakfast", "finds errors quicker than the compiler",
                                         "is not afraid of C++ error messages"};
    // output noun map
    std::map<std::string, std::string> noun = {{"spring", "STL guru"},
                                {"summer", "C++ expert"},
                                {"autumn", "coding beast"},
                                {"winter", "software design hero"}};
    // output
    // select adj
    std::vector<std::string> vector_adj;
    vector_adj.push_back(adj1);
    vector_adj.push_back(adj2);

    auto index_adj = name.length() % vector_adj.size();
    auto index_ending = name.length() % output_adj.size();
    std::cout << "\nHere is your description:" << std::endl;
    std::cout << name << ","
         << " the " << vector_adj.at(index_adj) << " " << noun.at(time) << " that "
         << output_adj.at(index_ending) << std::endl;
    return EXIT_SUCCESS;
}