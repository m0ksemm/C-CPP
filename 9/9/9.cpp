// 9.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "queue.h"
#include "vector.h"
#include "Windows.h"
#include <conio.h>

using namespace std;

class one_armed_bandit
{
private:
	Queue<char> x;
	Queue<char> y;
	Queue<char> z;
public:
	one_armed_bandit();
	void print0();
	void print1();
	char print2();
	char print3(char);
	char print4(char, char);

	
};

one_armed_bandit::one_armed_bandit()
{

	for (int i = 0; i < 10; i++)
	{
		char c = char(i % 6 + 1);
		x.Add(c);
		y.Add(c);
		z.Add(c);
	}
}

void one_armed_bandit::print0()
{
	char c1, c2, c3;
	srand(time(NULL));
	for (int i = 0; i < rand() % 100; i++)
		x.Remove(c1);
	for (int i = 0; i < rand() % 100; i++)
		y.Remove(c2);
	for (int i = 0; i < rand() % 100; i++)
		z.Remove(c3);

	x.Peek(c1);
	y.Peek(c2);
	z.Peek(c3);

	
	cout << endl << endl << char(201);
	for (int i = 1; i <= 11; i++) 
	{
		if (i % 4 == 0)
			cout << char(203);
		else cout << char(205);
	}
	cout << char(187) << endl;
	
	for (int i = 1; i <= 13; i++) 
	{
		if (i == 1 || i == 13 || i == 5 || i == 9)
			cout << char(186);
		else if (i == 3)
			cout << c1;
		else if (i == 7)
			cout << c2;
		else if (i == 11)
			cout << c3;
		else cout << " ";
	}
	cout << char(186) << endl;
	for (int i = 1; i <= 13; i++)
	{
		if (i == 1)
			cout << char(204);
		else if (i == 13)
			cout << char(185);
		else if (i == 5 || i == 9)
			cout << char(202);
		else cout << char(205);
	}
	cout << char(186) << endl;

	for (int i = 1; i <= 13; i++) 
	{
		if (i == 1)
			cout << char(186);
		else if (i == 13)
			cout << char(204) << char(188);
		else cout << " ";
	}
	

	cout << endl << char(186) << "    ONE-   " << char(186) << endl;
	cout << char(186) << "  -ARMED   " << char(186) << endl;
	cout << char(186) << " BANDIT :) " << char(186) << endl;

	cout << char(200);
	for (int i = 1; i <= 11; i++)
		cout << char(205);
	cout << char(188);

	cout << endl << endl << "Press ENTER to spin / Press ESCAPE to finish";

	cout  << endl << endl;
	cout << char(1) << " " << char(1) << " " << char(1) << " - " << "10 points   ";
	cout << char(1) << " " << char(1) << " - " << "5 points" << endl;
	cout << char(2) << " " << char(2) << " " << char(2) << " - " << "10 points   ";
	cout << char(2) << " " << char(2) << " - " << "5 points" << endl;
	cout << char(3) << " " << char(3) << " " << char(3) << " - " << "10 points   ";
	cout << char(3) << " " << char(3) << " - " << "5 points" << endl;
	cout << char(4) << " " << char(4) << " " << char(4) << " - " << "10 points   ";
	cout << char(4) << " " << char(4) << " - " << "5 points" << endl;
	cout << char(5) << " " << char(5) << " " << char(5) << " - " << "10 points   ";
	cout << char(5) << " " << char(5) << " - " << "5 points" << endl;
	cout << char(6) << " " << char(6) << " " << char(6) << " - " << "10 points   ";
	cout << char(6) << " " << char(6) << " - " << "5 points" << endl;

}

void one_armed_bandit::print1() 
{
	cout << endl << endl << char(201);
	for (int i = 1; i <= 11; i++)
	{
		if (i % 4 == 0)
			cout << char(203);
		else cout << char(205);
	}
	cout << char(187) << endl;

	for (int i = 1; i <= 13; i++)
	{
		if (i == 1 || i == 13 || i == 5 || i == 9)
			cout << char(186);
		else if (i == 3)
			cout << "?";
		else if (i == 7)
			cout << "?";
		else if (i == 11)
			cout << "?";
		else cout << " ";
	}
	cout  << endl;
	for (int i = 1; i <= 13; i++)
	{
		if (i == 1)
			cout << char(204);
		else if (i == 13)
			cout << char(185);
		else if (i == 5 || i == 9)
			cout << char(202);
		else cout << char(205);
	}
	cout  << endl;

	for (int i = 1; i <= 13; i++)
	{
		if (i == 1)
			cout << char(186);
		else if (i == 13)
			cout << char(204) << char(187);
		else cout << " ";
	}


	cout << endl << char(186) << "           " << char(186) << char(186) << endl;
	cout << char(186) << "SPINNING..." << char(186) << char(186) << endl;
	cout << char(186) << "           " << char(186) << endl;

	cout << char(200);
	for (int i = 1; i <= 11; i++)
		cout << char(205);
	cout << char(188);

	cout << endl << endl << endl << endl;
	cout << char(1) << " " << char(1) << " " << char(1) << " - " << "10 points   ";
	cout << char(1) << " " << char(1) << " - " << "5 points" << endl;
	cout << char(2) << " " << char(2) << " " << char(2) << " - " << "10 points   ";
	cout << char(2) << " " << char(2) << " - " << "5 points" << endl;
	cout << char(3) << " " << char(3) << " " << char(3) << " - " << "10 points   ";
	cout << char(3) << " " << char(3) << " - " << "5 points" << endl;
	cout << char(4) << " " << char(4) << " " << char(4) << " - " << "10 points   ";
	cout << char(4) << " " << char(4) << " - " << "5 points" << endl;
	cout << char(5) << " " << char(5) << " " << char(5) << " - " << "10 points   ";
	cout << char(5) << " " << char(5) << " - " << "5 points" << endl;
	cout << char(6) << " " << char(6) << " " << char(6) << " - " << "10 points   ";
	cout << char(6) << " " << char(6) << " - " << "5 points" << endl;

}

char one_armed_bandit::print2()
{
	char c1;
	srand(time(NULL));
	for (int i = 0; i < rand() % 100; i++)
		x.Remove(c1);

	x.Peek(c1);

	cout << endl << endl << char(201);
	for (int i = 1; i <= 11; i++)
	{
		if (i % 4 == 0)
			cout << char(203);
		else cout << char(205);
	}
	cout << char(187) << endl;

	for (int i = 1; i <= 13; i++)
	{
		if (i == 1 || i == 13 || i == 5 || i == 9)
			cout << char(186);
		else if (i == 3)
			cout << c1;
		else if (i == 7)
			cout << "?";
		else if (i == 11)
			cout << "?";
		else cout << " ";
	}
	cout << endl;
	for (int i = 1; i <= 13; i++)
	{
		if (i == 1  /*|| i == 5 || i == 9*/)
			cout << char(204);
		else if (i == 13)
			cout << char(185);
		else if (i == 5 || i == 9)
			cout << char(202);
		else cout << char(205);
	}
	cout << endl;

	for (int i = 1; i <= 13; i++)
	{
		if (i == 1)
			cout << char(186);
		else if (i == 13)
			cout << char(204) << char(187);
		else cout << " ";
	}


	cout << endl << char(186) << "           " << char(186) << char(186) << endl;
	cout << char(186) << "SPINNING..." << char(186) << char(186) << endl;
	cout << char(186) << "           " << char(186) << endl;

	cout << char(200);
	for (int i = 1; i <= 11; i++)
		cout << char(205);
	cout << char(188);

	cout << endl << endl << endl << endl;
	cout << char(1) << " " << char(1) << " " << char(1) << " - " << "10 points   ";
	cout << char(1) << " " << char(1) << " - " << "5 points" << endl;
	cout << char(2) << " " << char(2) << " " << char(2) << " - " << "10 points   ";
	cout << char(2) << " " << char(2) << " - " << "5 points" << endl;
	cout << char(3) << " " << char(3) << " " << char(3) << " - " << "10 points   ";
	cout << char(3) << " " << char(3) << " - " << "5 points" << endl;
	cout << char(4) << " " << char(4) << " " << char(4) << " - " << "10 points   ";
	cout << char(4) << " " << char(4) << " - " << "5 points" << endl;
	cout << char(5) << " " << char(5) << " " << char(5) << " - " << "10 points   ";
	cout << char(5) << " " << char(5) << " - " << "5 points" << endl;
	cout << char(6) << " " << char(6) << " " << char(6) << " - " << "10 points   ";
	cout << char(6) << " " << char(6) << " - " << "5 points" << endl;

	return c1;
}

char one_armed_bandit::print3( char c1)
{
	char c2;
	srand(time(NULL));
	for (int i = 0; i < rand() % 100; i++)
		y.Remove(c2);

	y.Peek(c2);

	cout << endl << endl << char(201);
	for (int i = 1; i <= 11; i++)
	{
		if (i % 4 == 0)
			cout << char(203);
		else cout << char(205);
	}
	cout << char(187) << endl;
	
	for (int i = 1; i <= 13; i++)
	{
		if (i == 1 || i == 13 || i == 5 || i == 9)
			cout << char(186);
		else if (i == 3)
			cout << c1;
		else if (i == 7)
			cout << c2;
		else if (i == 11)
			cout << "?";
		else cout << " ";
	}
	cout << endl;
	for (int i = 1; i <= 13; i++)
	{
		if (i == 1)
			cout << char(204);
		else if (i == 13)
			cout << char(185);
		else if (i == 5 || i == 9)
			cout << char(202);
		else cout << char(205);
	}
	cout << endl;

	for (int i = 1; i <= 13; i++)
	{
		if (i == 1)
			cout << char(186);
		else if (i == 13)
			cout << char(204) << char(187);
		else cout << " ";
	}


	cout << endl << char(186) << "           " << char(186) << char(186) << endl;
	cout << char(186) << "SPINNING..." << char(186) << char(186) << endl;
	cout << char(186) << "           " << char(186) << endl;

	cout << char(200);
	for (int i = 1; i <= 11; i++)
		cout << char(205);
	cout << char(188);

	cout << endl << endl << endl << endl;
	cout << char(1) << " " << char(1) << " " << char(1) << " - " << "10 points   ";
	cout << char(1) << " " << char(1) << " - " << "5 points" << endl;
	cout << char(2) << " " << char(2) << " " << char(2) << " - " << "10 points   ";
	cout << char(2) << " " << char(2) << " - " << "5 points" << endl;
	cout << char(3) << " " << char(3) << " " << char(3) << " - " << "10 points   ";
	cout << char(3) << " " << char(3) << " - " << "5 points" << endl;
	cout << char(4) << " " << char(4) << " " << char(4) << " - " << "10 points   ";
	cout << char(4) << " " << char(4) << " - " << "5 points" << endl;
	cout << char(5) << " " << char(5) << " " << char(5) << " - " << "10 points   ";
	cout << char(5) << " " << char(5) << " - " << "5 points" << endl;
	cout << char(6) << " " << char(6) << " " << char(6) << " - " << "10 points   ";
	cout << char(6) << " " << char(6) << " - " << "5 points" << endl;
	return c2;
}

char one_armed_bandit::print4(char c1, char c2)
{
	char c3;
	srand(time(NULL));
	for (int i = 0; i < rand() % 100; i++)
		z.Remove(c3);

	z.Peek(c3);

	
	cout << endl << endl << char(201);
	for (int i = 1; i <= 11; i++)
	{
		if (i % 4 == 0)
			cout << char(203);
		else cout << char(205);
	}
	cout << char(187) << endl;
	//1 11111 1 11111 1
	for (int i = 1; i <= 13; i++)
	{
		if (i == 1 || i == 13 || i == 5 || i == 9)
			cout << char(186);
		else if (i == 3)
			cout << c1;
		else if (i == 7)
			cout << c2;
		else if (i == 11)
			cout << c3;
		else cout << " ";
	}
	cout << char(186) << endl;
	for (int i = 1; i <= 13; i++)
	{
		if (i == 1)
			cout << char(204);
		else if (i == 13)
			cout << char(185);
		else if (i == 5 || i == 9)
			cout << char(202);
		else cout << char(205);
	}
	cout << char(186) << endl;

	for (int i = 1; i <= 13; i++)
	{
		if (i == 1)
			cout << char(186);
		else if (i == 13)
			cout << char(204) << char(188);
		else cout << " ";
	}

	cout << endl << char(186) << "           " << char(186) << endl;
	cout << char(186) << "   DONE!   " << char(186) << endl;
	cout << char(186) << "           " << char(186) << endl;

	cout << char(200);
	for (int i = 1; i <= 11; i++)
		cout << char(205);
	cout << char(188);

	cout << endl << endl << "Press ENTER to spin / Press ESCAPE to finish\n\n";

	cout << char(1) << " " << char(1) << " " << char(1) << " - " << "10 points   ";
	cout << char(1) << " " << char(1) << " - " << "5 points" << endl;
	cout << char(2) << " " << char(2) << " " << char(2) << " - " << "10 points   ";
	cout << char(2) << " " << char(2) << " - " << "5 points" << endl;
	cout << char(3) << " " << char(3) << " " << char(3) << " - " << "10 points   ";
	cout << char(3) << " " << char(3) << " - " << "5 points" << endl;
	cout << char(4) << " " << char(4) << " " << char(4) << " - " << "10 points   ";
	cout << char(4) << " " << char(4) << " - " << "5 points" << endl;
	cout << char(5) << " " << char(5) << " " << char(5) << " - " << "10 points   ";
	cout << char(5) << " " << char(5) << " - " << "5 points" << endl;
	cout << char(6) << " " << char(6) << " " << char(6) << " - " << "10 points   ";
	cout << char(6) << " " << char(6) << " - " << "5 points" << endl;

	return c3;
}

int ifwin(char c1, char c2, char c3) 
{
	if (c1 == c2 && c1 == c3)
		return 10;
	else if (c1 == c2 || c1 == c3 || c2 == c3)
		return 5;
	else return 0;
}

int main()
{
	one_armed_bandit Game;

	Game.print0();

	char c1, c2, c3;
	int score = 0, tries = 0;

	int key;
	while(true)
	{
		key = _getch();
		if (key == VK_RETURN) 
		{
			system("cls");
			Game.print1();
			cout << endl << "Score: " << score << endl;

			Sleep(1000);
			system("cls");
			c1 = Game.print2();
			cout << endl << "Score: " << score << endl;

			Sleep(1000);
			system("cls");
			c2 = Game.print3(c1);
			cout << endl << "Score: " << score << endl;

			Sleep(1000);
			system("cls");
			c3 = Game.print4(c1, c2);

			int plus = ifwin(c1, c2, c3);

			tries++;
			score += plus;

			cout << endl << "Score: " << score << endl;	
		}
		if (key == VK_ESCAPE) 
		{
			cout << "\n\nYour score for " << tries << " tries is " << score << endl;
			cout << "\tTHE END!\n\n\n";
			break;
		}	
	}
}

