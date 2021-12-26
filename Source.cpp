
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

ifstream file;

int main() 
{
	setlocale(LC_ALL, "Rus");
	cout << "������� ��� �����: ";
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
		cout << "������ � " << i << ": ";
		switch (i)
		{
		case 1:
			cout << "�������� ��� �����!" << endl;
			break;
		case 2:
			cout << "���� ������!" << endl;
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
						//������ ���� �� �����
					case '1':
						cout << " ���� ";
						break;
					case '2':
						cout << " ��� ";
						break;
					case '3':
						cout << " ��� ";
						break;
					case '4':
						cout << " ������ ";
						break;
					case '5':
						cout << " ���� ";
						break;
					case '6':
						cout << " ����� ";
						break;
					case '7':
						cout << " ���� ";
						break;
					case '8':
						cout << " ������ ";
						break;
					case '9':
						cout << " ������ ";
						break;
					case '0':
						cout << " ���� ";
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