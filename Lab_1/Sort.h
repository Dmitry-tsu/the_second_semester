#ifndef SORT_H
#define SORT_H

#include <vector>
#include <string>
#include <random>

void generateNumbers(std::vector<int>& arr, int minValue, int maxValue);
bool writeToFile(const std::string& fileName, int numbersCount, int minValue, int maxValue);
bool isFileSorted(const std::string& fileName);
void sortFile(const std::string& fileName);

#endif