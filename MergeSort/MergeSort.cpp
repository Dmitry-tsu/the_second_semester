#include "MergeSort.h"

bool copyFile(const std::string& origin, const std::string& copy)
{
    std::ifstream fileOrigin(origin);
    std::ofstream fileCopy(copy);

    if(!fileOrigin.is_open() || !fileCopy.is_open())
        return false;

    int current = 0;
    while(fileOrigin >> current)
    {
        fileCopy << current << ' ';
    }

    fileOrigin.close();
    fileCopy.close();

    return true;
}

void outputFile(const std::string& fileName)
{
    std::ifstream origin(fileName, std::ios_base::in);
    assert(origin.is_open());

    int current = 0;
    while(origin >> current)
    {
        std::cout << current << ' ';
    }
    origin.close();
    std::cout << std::endl;
}

bool isFileContainsSortedArray(const std::string &fileName)
{
    std::ifstream origin(fileName, std::ios_base::in);
    int current = 0, next = 0;

    while(origin >> current)
    {
        origin >> next;
        std::cout << "cur - " << current << " next - " << next << std::endl;
        if(next > current)
            return false;
    }

    origin.close();
    return true;
}
