#include "Sort.h"
#include <fstream>
#include <random>
#include <iostream>

void generateNumbers(std::vector<int>& arr, int minValue, int maxValue)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(minValue, maxValue);

    for (int& num : arr)
    {
        num = dis(gen);
    }
}

bool createFileWithRandomNumbers(const std::string& fileName, int numbersCount, int minValue, int maxValue)
{
    std::vector<int> arr(numbersCount);
    generateNumbers(arr, minValue, maxValue);

    std::ofstream file(fileName);
    if (!file)
    {
        return false;
    }

    for (int num : arr)
    {
        file << num << std::endl;
    }

    file.close();
    std::cout << "Array has been written to " << fileName << std::endl;
    return true;
}

bool isFileSorted(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file)
    {
        std::cerr << "Unable to open file " << fileName << std::endl;
        return false;
    }

    int prev = std::numeric_limits<int>::min();
    int curr;
    while (file >> curr)
    {
        if (curr < prev)
        {
            file.close();
            return false;
        }
        prev = curr;
    }

    file.close();
    return true;
}