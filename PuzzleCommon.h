#pragma once

#include <algorithm>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

inline void clearScreen()
{
    std::cout << "\033[H\033[J";
}

inline std::string readChoice()
{
    std::string choice;
    if (!(std::cin >> choice)) {
        return "ex";
    }
    std::transform(choice.begin(), choice.end(), choice.begin(),
        [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return choice;
}

inline bool contains(const std::vector<std::string>& choices, const std::string& choice)
{
    return std::find(choices.begin(), choices.end(), choice) != choices.end();
}

inline void printMoves(const std::vector<std::string>& moves)
{
    for (const std::string& move : moves) {
        std::cout << move << " ";
    }
}

inline void waitForKey()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
