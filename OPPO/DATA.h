#pragma once
#include <sstream>

using namespace std;

struct DATA
{
    int dd, mm, yy;

    void readDate(stringstream& ss); // Метод для считывания даты создания файла
};
