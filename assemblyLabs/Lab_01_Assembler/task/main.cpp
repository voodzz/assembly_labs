#include <iostream>
#include "Parser.h"

int main() {
    Parser parser;
    std::map<std::string, int> result = parser.readDataFromFile<int>("CMakeFiles/data/input.txt");
    for (const auto& [key, value] : result) {
        std::cout << key << ' ' << value << '\n';
    }
    return 0;
}
