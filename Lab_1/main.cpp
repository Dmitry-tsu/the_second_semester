#include <iostream>
#include "Sort.h"

int main() {
    const std::string fileName = "file.txt";
    const int numbersCount = 10;
    const int minValue = 0;
    const int maxValue = 10;

    if (writeToFile(fileName, numbersCount, minValue, maxValue))
    {
        std::cout << "File created successfully." << std::endl;
        sortFile(fileName);
        if (isFileSorted(fileName))
        {
            std::cout << "Array in the file is sorted." << std::endl;
        }
        else
        {
            std::cout << "Array in the file is not sorted." << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to create file." << std::endl;
    }

    return 0;
}