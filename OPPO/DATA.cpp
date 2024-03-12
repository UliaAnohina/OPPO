#include "DATA.h"

void DATA::readDate(stringstream& ss) // Метод для считывания даты создания файла
{
    string date;
    getline(ss, date, '.');
    dd = stoi(date);

    getline(ss, date, '.');
    mm = stoi(date);

    getline(ss, date);
    yy = stoi(date);
}
