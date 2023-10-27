// 18.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


//36.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <io.h>
#include <fstream>

using namespace std;


void RussianMessage(const char* str)
{
	char* p = new char[strlen(str) + 1];
	CharToOemA(str, p);
	cout << p;
	delete[] p;
}

int main()
{
	ofstream of;

	ifstream f,f2;
	f.open("1.jpg");
	
	if (!f.is_open())
	{
		cout << "Error!\n";
		return 0;
	}

	f.seekg(0, ios_base::end);
	int length = f.tellg();
	char* buf = new char[length];
	memset(buf, 0, length);
	f.read(buf, length);
	f.close();


	delete[] buf;



	f.open("1.jpg", ios::binary | ios::in);


	const int MEGABYTE = 1048576;
	buf = new char[MEGABYTE];
	memset(buf, 0, MEGABYTE);

	int flag = 0, size, j = 0;
	RussianMessage("Сколько мегабайт должна быть одна часть? ");
	cin >> size;
	cin.ignore();


	int part = length / (size * MEGABYTE);

	

	RussianMessage("Введите путь к ");
	cout << part;
	RussianMessage(" файлам\n");

	string* path = new string[part];
	for (int i = 0; i < part; i++)
	{ 
		cout << i+1 << ": ";
		cin >> path[i];
	}
	//начало алгоритма разбития файлов
	char* buf2 = new char[(size * MEGABYTE)];
	memset(buf2, 0, (size * MEGABYTE));

	int b = length - ((size * MEGABYTE) * part);
	char* buf3 = new char[b];
	

	for (int j = 0; j < length / (size * MEGABYTE); j++)
	{
		of.open(path[j], ios::binary | ios::trunc);

		if (j == part - 1)
		{	
			memset(buf3, 0, b);
			f.read(buf3, b);
			of.write(buf3, b);
		}

		f.read(buf2, size * MEGABYTE);
		of.write(buf2, size * MEGABYTE);

		of.close();
	}

	//начало алгоритма склеивания файлов

	of.open("result.jpg", ios::binary | ios::trunc);

	for (int j = 0; j < part; j++)
	{
		f2.open(path[j], ios::binary );

		if (j == part - 1)
		{
			memset(buf3, 0, b);
			f2.read(buf3, b);
			of.write(buf3,  b);
		}

		f2.read(buf2, MEGABYTE * size);
		of.write(buf2, MEGABYTE * size);

		f2.close();
	}
	of.close();


	delete[] buf;
	delete[] buf2;
	delete[] buf3;
	
	f.close();
	return 0;
}



