#include "MergeSort.h"

#include <chrono>

int main()
{
    std::string str("array_10000_-10_10.txt");

    auto begin = std::chrono::steady_clock::now();
    naturalMergeSort3Files(str);
    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono:: duration_cast<std::chrono::milliseconds>(end - begin)/1000;

    std::cout << "end\t time - " << elapsed_ms.count() << std::endl;

    assert(isFileContainsSortedArray("supported_file1.txt"));

    return 0;
}