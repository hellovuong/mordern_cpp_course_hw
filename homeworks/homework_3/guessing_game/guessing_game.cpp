//
// Created by vuong on 1/22/23.
//
#include <iostream>
#include <algorithm>
#include <random>

int main() {

    std::cout << "Welcome to the GUESSING GAME!\n"
                 "I will generate a number and you will guess it!\n";

    double smallest_number;
    std::cout << "Please provide the smallest number:\n";
    std::cin >> smallest_number;

    double largest_number;
    std::cout << "Please provide the largest number:\n";
    std::cin >> largest_number;

    std::random_device random_device;
    std::mt19937 random_engine{random_device()};
    std::uniform_real_distribution<> distribution{smallest_number, largest_number};
    auto generated_number = distribution(random_device);
    std::cout << "I've generated a number. Try to guess it!\n";

    double guess = 0;
    int count = 0;

    while (count < 5) {
        std::cout << "Please provide the next guess: ";
        std::cin >> guess;
        count++;
        if (guess < generated_number) {
            std::cout << "Your number is too small. Try again!\n";
            continue;
        } else if ((guess > generated_number)) {
            std::cout << "Your number is too big. Try again!\n";
            continue;
        } else {
            std::cout << "You've done it! You guessed the number " << generated_number << " in " << count
                      << " guesses!";
            break;
        }
    }

    return EXIT_SUCCESS;
}