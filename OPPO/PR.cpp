#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct ZADANIE {
    string name, date;
    int size;
};

int main() {
    setlocale(LC_ALL, ".1251");
    ifstream in("ZADANIE.txt");
    vector<ZADANIE> files;
    string line;

    while (getline(in, line)) {
        stringstream ss(line);
        ZADANIE file;
        ss >> file.name >> file.size >> file.date;
        files.push_back(file);
    }
    in.close();

    for (auto file : files) {
        cout << "Название файла: " << file.name << endl;
        cout << "Дата создания: " << file.date << endl;
        cout << "Размер: " << file.size << " байт" << endl;
        cout << endl;
    }
    return 0;
}