#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

bool Aa(char i, char j) 
{
	if ((i >= 'A') && (i <= 'Z')) 
	{
		i += 32;
	}
	if ((j >= 'A') && (j <= 'Z'))
	{
		j += 32;
	}
	if (i == j)
	{
		return true;
	}
	return false;
}

bool find_palindrome(char* str) 
{
	cout << "Insert string\n";
	cin.getline(str, 255); 
	int i = 0;
	int j = strlen(str) - 1;
	for (; i < j; i++, j--)
	{
		while (str[i] == ' ')
		{
			i++;
		}
		while (str[j] == ' ')
		{
			j--;
		}
		if (!Aa(str[i], str[j]))
		{
			return false;
		}
	}
	return true;
}

void exit_sub(const long* answer, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << answer[i] << " ";
	}
	cout << endl;
	return;
}

void substring(const char* str, const char* subs, long* answer) 
{
	int n = 0, count = 0, i = 0, len = 0;
	bool flag;
	while (i < strlen(str))
	{
		if (str[i] == subs[0])
		{
			n = i;
			flag = true;
			for (int j = 0; j < strlen(subs); j++)
			{
				if (str[i] != subs[j])
				{
					flag = false;
					break;
				}
				i++;
			}
			if (flag == true)
			{
				answer[count++] = n;
				len++;
			}
			i = n;
		}
		i++;
	}
	exit_sub(answer, len);
	return;
}

void exitCaesar(const char* str) 
{
	cout << str << endl;
	return;
}

void Caesar(char* str, int key) 
{
	for (int i = 0; i < strlen(str); i++)
	{
		while (!isalpha(str[i]))
		{
			i++;
		}
		if ((str[i] >= 65) && (str[i] <= 90))
		{
			if (str[i] + key > 90)
			{
				str[i] = ((str[i] + key) % 90) + 64;
			}
		}
		else if ((str[i] >= 97) && (str[i] <= 122))
		{
			if (str[i] + key > 122)
			{
				str[i] = ((str[i] + key) % 122) + 96;
			}
		}
		else
		{
			str[i] += key;
		}
	}
	exitCaesar(str);
	return;
}

void exit_name(char* answer)
{
	cout << answer << endl;
	return;
}

void name(const char* str) 
{
	char answer[255] = { 0 };
	int start = -1, len = 0;
	for (int i = 0; i < strlen(str); i++) 
	{
		if ((start == -1) && (str[i] == '"'))
		{
			start = i;
		}
		else if ((start != -1) && (str[i] == '"')) 
		{
			for (int j = start + 1; j < i; j++) 
			{
				answer[len++] = str[j];
			}
			answer[len++] = ' ';
			start = -1;
		}
	}
	answer[len - 1] = '\0'; 
	exit_name(answer);
	return;
}

int main() 
{	
	int choise =  0;
	while (choise != 5)
	{
		cout << "make a choise:\n" << "1 - Palindrom\n" << "2 - Search substring\n" << "3 - Caesar`s cipher\n" << "4 - Search name\n" << "5 - Exit\n";
		cin >> choise;
		cin.ignore();
		char str[255];
		switch (choise)
		{
		case 1:
			if (find_palindrome(str))
			{
				cout << "True\n";
			}
			else
			{
				cout << "False\n";
			}
			break;
		case 2:
			cout << "Insert string\n";
			cin.getline(str, 255);
			cout << "Insert substring\n";
			char subs[255];
			cin.getline(subs, 255);
			long answer[255];
			substring(str, subs, answer);
			break;
		case 3:
			cout << "Insert string\n";
			cin.getline(str, 255);
			cout << "Insert key\n";
			int key;
			cin >> key;
			cin.ignore();
			Caesar(str, key);
			break;
		case 4: 
			cout << "Insert string\n";
			cin.getline(str, 255);
			name(str);
			break;
		case 5:
			break;
		default:
			return 0;
		}
	}
	return 0;
}