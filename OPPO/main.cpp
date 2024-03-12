#include <iostream>
#include <fstream>
#include <vector>
#include "FileINFO.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "russian");
    vector<ZADANIE> files;

    readData(files);

    for (const auto& file : files)
    {
        printFile(file);
    }

    return 0;
}
