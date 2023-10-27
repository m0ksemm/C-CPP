#include <iostream>
#include "CFraction.h"

using namespace std;

//CONSTRUCTORS
CFraction::CFraction()//конструктор без параметров
{
	// конструктор класса по умолчанию
	numerator = 31;
	denomerator = 12;
}

CFraction::CFraction(int num, int denum)//конструктор с параметрами
{
	// конструктор класса по умолчанию
	numerator = num;
	denomerator = denum;
}

//METHODS
void CFraction::enter_fraction() // метод, отвечающий за начальную инициализацию полей класса
{
	cout << "Numerator : ";
	cin >> numerator;
	cout << "Denomerator : ";
	cin >> denomerator;
}

void CFraction::output_fraction()// метод, отвечающий за вывод дроби на екран
{
	cout << numerator << "/" << denomerator;
}

void CFraction::setNumerator(int num) // модификатор для поля numerator
{
	numerator = num;
}
void CFraction::setDenomerator(int denum) // модификатор для поля denomerator
{
	denomerator = denum;
}

int CFraction::getNumerator() // инспектор для поля numerator
{
	return numerator;
}
int CFraction::getDenomerator() // инспектор для поля denomerator
{
	return denomerator;
}

int CFraction::int_part(int num, int denum) // Метод выделения целой части.
{
	num = numerator;
	denum = denomerator;
	return (num / denum);
}

double CFraction::double_fraction(int num, int denum)// Метод перевода дроби в вещественное число.
{
	num = numerator;
	denum = denomerator;
	return (double(num) / double(denum));
}

