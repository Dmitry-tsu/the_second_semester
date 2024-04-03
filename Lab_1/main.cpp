#include <iostream>
#include "Sort.h"

int main() {
    const std::string fileName = "file.txt";
    const int numbersCount = 1000000;
    const int minValue = 0;
    const int maxValue = 100000;

    if (createFileWithRandomNumbers(fileName, numbersCount, minValue, maxValue))
    {
        std::cout << "File created successfully." << std::endl;
    }
    else
    {
        std::cout << "Failed to create file." << std::endl;
    }

    return 0;
}