#include "string_calc.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("testcases.txt");
    if (!file) {
        std::cerr << "Failed to open testcases.txt\n";
        return 1;
    }

    std::string s1, comma, s2;
    int testNum = 1;

    while (file >> s1 >> comma >> s2) {
        std::cout << "Test case " << testNum++ << ": " << s1 << " , " << s2 << "\n";

        if (!isValidDouble(s1)) {
            std::cout << "Invalid number: " << s1 << "\n\n";
            continue;
        }
        if (!isValidDouble(s2)) {
            std::cout << "Invalid number: " << s2 << "\n\n";
            continue;
        }

        std::string sum = addDoubleStrings(s1, s2);
        std::cout << "Sum = " << sum << "\n\n";
    }

    return 0;
}
