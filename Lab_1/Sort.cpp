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

bool writeToFile(const std::string& fileName, int numbersCount, int minValue, int maxValue)
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
        file.write(reinterpret_cast<const char*>(&num), sizeof(int));
        //file << num << std::endl;
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
    while (file.read(reinterpret_cast<char*>(&curr), sizeof(int)))
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

void sortFile(const std::string& fileName)
{
    std::vector<int> arr;
    std::ifstream file(fileName, std::ios::binary);
    if (!file)
    {
        std::cerr << "Unable to open file " << fileName << std::endl;
        return;
    }

    int num;
    while (file.read(reinterpret_cast<char*>(&num), sizeof(int)))
    {
        arr.push_back(num);
        //std::cout << num << " ";

    }
    file.close();

    std::sort(arr.begin(), arr.end());

    /*
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    */

    std::ofstream outputFile(fileName, std::ios::binary);
    if (!outputFile)
    {
        std::cerr << "Unable to open file " << fileName << " for writing." << std::endl;
        return;
    }

    for (int num : arr)
    {
        outputFile.write(reinterpret_cast<const char*>(&num), sizeof(int));
        //std::cout << num << " ";
    }
    outputFile.close();
}