#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using std::getline;

string file_format(const string str) // ������� ������ �����/���������
{
	int start_index = str.rfind('.') + 1;
	return str.substr(start_index, str.size());
}

string file_name(const string str) // ������� �������� �����/���������
{
	int start_index = str.rfind("\\") + 1;
	int finish_index = str.rfind('.');
	return str.substr(start_index, finish_index - start_index);
}

string file_path(const string str) // ������� ���� �����/���������
{
	int finish_index = str.rfind("\\");
	int start_index = 0;
	return str.substr(start_index, finish_index - start_index);
}

char file_disk(const string str) // ������� �������� �����
{
	return str[0];
}

string file_rename(string str, string zamena) // �������� �������� �����/���������
{
	int start_index = str.rfind("\\") + 1;
	int finish_index = str.rfind('.');
	string name = str.substr(start_index, finish_index - start_index);
	string result = str.replace(start_index, name.size(), zamena);
	return result;
}

bool file_copy(const string& str) // �������� ����/�������� � ���� �����
{
	fstream fin(str);
	if (!fin.is_open()) // is_open - ������ �� ����
	{
		return false;
	}
	// ����� �������� ���� � ����
	fstream fout(file_rename(str, file_name(str) + "_copy"), fstream::out);
	if (!fout.is_open())
	{
		return false;
	}
	string temp;
	while (!fin.eof() && fin.is_open()) // eof - ��������� �� ����� ����� 
	{
		getline(fin, temp);
		fout << temp + "\n"; //��� ������?
	}
	fin.close();
	fout.close();
	return true;
}

int main() // �������
{
	int choise = 0;
	while (choise != 7)
	{
		cout << "first, enter the full location of the file\n" << "example: " << "C:\\Users\\User\\Desktop\\C++\\proglang2023-StepanovYura\\Lab3\\proj_1.cpp   or   C:\\Users\\User\\Desktop\\Test-file\\Test-txt.docx\n";
		string location = "";
		string zamena = "";
		getline(cin, location);
		cout << "make a choise:\n" << "1 - format\n" << "2 - name\n" << "3 - path\n" << "4 - disk\n" << "5 - rename\n" << "6 - copy\n" << "7 - exit\n";
		cin >> choise;
		cin.ignore();
		switch (choise)
		{
		case 1:
			cout << file_format(location) << "\n";
			break;
		case 2:
			cout << file_name(location) << "\n";
			break;
		case 3:
			cout << file_path(location) << "\n";
			break;
		case 4:
			cout << file_disk(location) << "\n";
			break;
		case 5:
			cout << "enter a new file name\n";
			getline(cin, zamena);
			cout << file_rename(location, zamena) << "\n";
			break;
		case 6:
			if (file_copy(location))
			{
				cout << "True\n";
			}
			else
			{
				cout << "False\n";
			}
			break;
		case 7:
			break;
		default:
			return 0;
		}
	}
	return 0;
} 