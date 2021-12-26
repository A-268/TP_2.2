
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

ifstream file;

int main() 
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите имя файла: ";
	string name, line;
	char c;
	bool f = true;

	try 
	{
		cin >> name;
		file.open(name);
		if (!file)
			throw 1;
		if (file.peek() == ifstream::traits_type::eof())
			throw 2;
	}
	catch (int i) 
	{
		f = false;
		cout << "Ошибка № " << i << ": ";
		switch (i)
		{
		case 1:
			cout << "Неверное имя файла!" << endl;
			break;
		case 2:
			cout << "Файл пустой!" << endl;
			file.close();
			break;
		}
	}

	if (f) 
	{
		while (!file.eof()) 
		{
			while (getline(file, line, '\n')) 
			{ 
				for (int i = 0; i < line.size(); i++) 
				{
					c = line[i];
					switch (c)
					{
						//замена цифр на слова
					case '1':
						cout << " один ";
						break;
					case '2':
						cout << " два ";
						break;
					case '3':
						cout << " три ";
						break;
					case '4':
						cout << " четыре ";
						break;
					case '5':
						cout << " пять ";
						break;
					case '6':
						cout << " шесть ";
						break;
					case '7':
						cout << " семь ";
						break;
					case '8':
						cout << " восемь ";
						break;
					case '9':
						cout << " девять ";
						break;
					case '0':
						cout << " ноль ";
						break;
					case '.':
					case '!':
					case '?':
						cout << c << endl;
						break;
					default:
						cout << c;
					}
				}
			}
		}
		file.close();
	}
	cout << endl;
	std::system("pause");
	return 0;
}