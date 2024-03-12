#include "FileINFO.h"
#include <string>

using namespace std;

void ZADANIE::readFileName(stringstream& ss) // Метод для считывания названия файла
{
    getline(ss, name, ' ');
}

void ZADANIE::readFileSize(stringstream& ss) // Метод для считывания размера файла
{
    getline(ss, size, ' ');
}

void ZADANIE::readFileDate(stringstream& ss) // Метод для считывания даты создания файла
{
    date.readDate(ss);
}

void readData(vector<ZADANIE>& files) // Функция для вызова методов считывания данных
{
    ifstream in("ZADANIE.txt");
    if (!in) {
        cout << "Не удалось открыть файл" << endl;
    }
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        ZADANIE file;

        file.readFileName(ss);
        file.readFileSize(ss);
        file.readFileDate(ss);

        files.push_back(file);
    }
    in.close();
}

void printFile(const ZADANIE& file) // Функция для вывода информации о файле
{
    cout << "Название файла: " << file.name << endl;
    cout << "Дата создания: " << file.date.dd << "." << file.date.mm << "." << file.date.yy << endl;
    cout << "Размер файла: " << file.size << " байт" << endl << endl;
}
