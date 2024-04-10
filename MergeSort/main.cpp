#include "MergeSort.h"

int main()
{
    std::string str("array_10000_-10_10.txt");

    // Проверка функции outputFile
    outputFile(str);

    // Проверка функции isFileContainsSortedArray
    if (isFileContainsSortedArray(str))
    {
        std::cout << "Файл содержит отсортированный массив" << std::endl;
    }
    else
    {
        std::cout << "Файл не содержит отсортированный массив" << std::endl;
    }

    return 0;
}