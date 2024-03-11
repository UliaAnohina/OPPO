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
        cout << "�������� �����: " << file.name << endl;
        cout << "���� ��������: " << file.date << endl;
        cout << "������: " << file.size << " ����" << endl;
        cout << endl;
    }
    return 0;
}