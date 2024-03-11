#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct DATA {
    int dd, mm, yy;
};

struct ZADANIE {
    string name, size;
    DATA date;
};

void readFileName(stringstream& ss, ZADANIE& file) // Функция для считывания названия файла
{
    getline(ss, file.name, ' ');
}

void readFileSize(stringstream& ss, ZADANIE& file) // Функция для считывания размера файла
{
    getline(ss, file.size, ' ');
}

void readFileDate(stringstream& ss, ZADANIE& file) // Функция для считывания даты создания файла
{
    string date;
    getline(ss, date, '.');
    file.date.dd = stoi(date);

    getline(ss, date, '.');
    file.date.mm = stoi(date);

    getline(ss, date);
    file.date.yy = stoi(date);
}

void readData(vector<ZADANIE>& files) // Функция для вызова функций считывания данных
{
    ifstream in("ZADANIE.txt");
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        ZADANIE file;

        readFileName(ss, file);
        readFileSize(ss, file);
        readFileDate(ss, file);

        files.push_back(file);
    }
    in.close();
}

void printFile(const ZADANIE & file) // Функция для вывода информации о файле
{
    cout << "Название файла: " << file.name << endl;
    cout << "Дата создания: " << file.date.dd << "." << file.date.mm << "." << file.date.yy << endl;
    cout << "Размер файла: " << file.size << " байт" << endl << endl;
}

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
