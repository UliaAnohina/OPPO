#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "DATA.h"

using namespace std;

struct ZADANIE 
{
	string name, size;
	DATA date;

	void readFileName(stringstream& ss); // Метод для считывания названия файла
	void readFileSize(stringstream& ss); // Метод для считывания размера файла
	void readFileDate(stringstream& ss); // Метод для считывания даты создания файла
};

void readData(vector<ZADANIE>& files); // Функция для вызова методов считывания данных
void printFile(const ZADANIE& file);   // Функция для вывода информации о файле
