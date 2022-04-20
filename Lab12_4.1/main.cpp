#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

string cread(string path)
{
	FILE* f;

	if ((f = fopen(path.c_str(), "r")) == NULL)
	{
		cout << "Помилка при відкритті файлу" << endl;
		return "";
	}

	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	fseek(f, 0, SEEK_SET);
	string content;
	for (int i = 0; i < size; i++)
		content += getc(f);
	fclose(f);
	return content;
}

bool find(string text, int _i, int _j)
{
	int row = 0;
	for (size_t i = 0; i < text.size(); i++) {
		if (text.at(i) == '\n')
			row++;
		if (_i == row)
		{
			auto pos_end = text.find('\n', i + 1);
			string line = text.substr(i+1, (pos_end == -1 ? text.size() - 1 : pos_end) - i);
			return line.at(_j - 1) == 'n' && line.at(_j + 1) == 'o';
		}
	}
	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string path;
	cout << "Введіть файл: "; getline(cin, path);
	string content = cread(path.c_str());
	cout << content << endl;
	int i, j;
	cout << "Введіть i = "; cin >> i;
	cout << "Введіть j = "; cin >> j;
	if (find(content, i, j))
		cout << "Є" << endl;
	else
		cout << "Нема" << endl;
	return 0;
}