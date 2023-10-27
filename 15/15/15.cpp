// 15.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

class A
{
protected:
    FILE *f1;
public:
	void Input(const char* path)
	{
		fopen_s(&f1, path, "a");
		if (f1 == nullptr)
		{
			perror("Error opening");
			system("pause");
			cout << "ERROR";
		}
		cout << "Enter the numbers. Press Enter to stop: \n";
		int n;
		char str[MAX_PATH];
		cin.ignore();

		while (true)
		{
			cin.getline(str, MAX_PATH);
			fputs(str, f1);
			fputc('\n', f1);
			if (strlen(str) == 0)
				break;
		}
		
		fclose(f1);
	}

	virtual void Display(const char* path)
	{
		fopen_s(&f1, path, "r");
		if (f1 == nullptr)
		{
			perror("Error opening");
			system("pause");

			cout << "ERROR";
		}
		char str[MAX_PATH];

		cout << "Your file: " << endl;
		while (!feof(f1))
		{
			fgets(str, MAX_PATH, f1);
			for (int i = 0; i < strlen(str); i++) 
			{
				cout << str[i] ;
			}
		}
		fclose(f1);
	}	
};

class B : public A
{
public:
	 void Display(const char* path) override
	{
		fopen_s(&f1, path, "r");
		if (f1 == nullptr)
		{
			perror("Error opening");
			system("pause");

			cout << "ERROR";
		}
		char str[MAX_PATH];
		cout << "Your file: " << endl;
		while (!feof(f1))
		{
			
			fgets(str, MAX_PATH, f1);
			for (int i = 0; i < strlen(str); i++)
			{
				cout << dec << (int)str[i]  << " ";
			}
		}
		fclose(f1);
	}
};

class C : public A
{
public:
	 void Display(const char* path) override
	{
		fopen_s(&f1, path, "r");
		if (f1 == nullptr)
		{
			perror("Error opening");
			system("pause");

			cout << "ERROR";
		}
		char str[MAX_PATH];

		cout << "Your file: " << endl;
		while (!feof(f1))
		{
			fgets(str, 300, f1);
			for (int i = 0; i < strlen(str); i++)
			{
				cout << hex << (int)str[i] << " ";
			}
		}
		fclose(f1);
	}
};

void Print(A *p)
{
	p->Display("f1.txt");
}

int main()
{
	A* p = nullptr;
	int choice;
	cout << "1. Class A - content of the file\n2. Class B - ASCII-codes\n";
	cout << "3. Class C - hex form\n4. Exit\n";
	bool flag = true;
	while (flag == true)
	{
		cout << "\n\nMake your choice: ";

		cin >> choice;
		switch (choice)
		{
		case 1:
			p = new A;
			Print(p);
			break;
		case 2:
			p = new B;
			Print(p);
			break;
		case 3:
			p = new C;
			Print(p);
			break;
		case 4:
			flag = false;
			break;
		}
	}
	return 0;
}

