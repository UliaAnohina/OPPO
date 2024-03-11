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

void readFileName(stringstream& ss, ZADANIE& file) // Ôóíęöč˙ äë˙ ń÷čňűâŕíč˙ íŕçâŕíč˙ ôŕéëŕ
{
    getline(ss, file.name, ' ');
}

void readFileSize(stringstream& ss, ZADANIE& file) // Ôóíęöč˙ äë˙ ń÷čňűâŕíč˙ đŕçěĺđŕ ôŕéëŕ
{
    getline(ss, file.size, ' ');
}

void readFileDate(stringstream& ss, ZADANIE& file) // Ôóíęöč˙ äë˙ ń÷čňűâŕíč˙ äŕňű ńîçäŕíč˙ ôŕéëŕ
{
    string date;
    getline(ss, date, '.');
    file.date.dd = stoi(date);

    getline(ss, date, '.');
    file.date.mm = stoi(date);

    getline(ss, date);
    file.date.yy = stoi(date);
}

void readData(vector<ZADANIE>& files) // Ôóíęöč˙ äë˙ âűçîâŕ ôóíęöčé ń÷čňűâŕíč˙ äŕííűő
{
    ifstream in("ZADANIE.txt");
    if (!in) {
        cout << "Не удалось открыть файл" << endl;
    }
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

void printFile(const ZADANIE & file) // Ôóíęöč˙ äë˙ âűâîäŕ číôîđěŕöčč î ôŕéëĺ
{
    cout << "Íŕçâŕíčĺ ôŕéëŕ: " << file.name << endl;
    cout << "Äŕňŕ ńîçäŕíč˙: " << file.date.dd << "." << file.date.mm << "." << file.date.yy << endl;
    cout << "Đŕçěĺđ ôŕéëŕ: " << file.size << " áŕéň" << endl << endl;
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
