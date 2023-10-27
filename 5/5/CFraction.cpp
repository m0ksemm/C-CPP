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

CFraction& CFraction::operator+(CFraction& fract1)   //метод перегрузки оператора +
{
	CFraction result;
	int n1 = this->getNumerator();
	int n2 = this->getDenomerator();
	int m1 =  fract1.getNumerator();
	int m2 =  fract1.getDenomerator();
	result.setNumerator(n1 * m2 + n2 * m1);
	result.setDenomerator(n2 * m2);
	return result;
}

CFraction& CFraction::operator-(CFraction& fract1)   //метод перегрузки оператора -
{
	CFraction result;
	int n1 = this->getNumerator();
	int n2 = this->getDenomerator();
	int m1 =  fract1.getNumerator();
	int m2 =  fract1.getDenomerator();
	result.setNumerator(n1 * m2 - m1 * n2);
	result.setDenomerator(n2 * m2);
	return result;
}

CFraction& CFraction::operator*(CFraction& fract1)   //метод перегрузки оператора *
{
	CFraction result;
	int n1 = this->getNumerator();
	int n2 = this->getDenomerator();
	int m1 = fract1.getNumerator();
	int m2 = fract1.getDenomerator();
	result.setNumerator(n1 * m1);
	result.setDenomerator(n2 * m2);
	return result;
}

CFraction& CFraction::operator/(CFraction& fract1)  //метод перегрузки оператора /
{
	CFraction result;
	int n1 = this->getNumerator();
	int n2 = this->getDenomerator();
	int m1 = fract1.getNumerator();
	int m2 = fract1.getDenomerator();
	result.setNumerator(n1 * m2);
	result.setDenomerator(n2 * m1);
	return result;
}

bool CFraction::operator>( const CFraction& fract1)  //метод перегрузки оператора >
{
	int num1 = fract1.numerator, denum1 = fract1.denomerator;
	double fr1 = double(num1) / double(denum1);
	int num2 = this->numerator, denum2 = this->denomerator;
	double fr2 = double(num2) / double(denum2);
	if (fr1 > fr2)
		return false;
	else if (fr1 < fr2)
		return true;
	else 
		return false;
}

bool CFraction::operator>=(const CFraction& fract1)  //метод перегрузки оператора >=
{
	int num1 = fract1.numerator, denum1 = fract1.denomerator;
	double fr1 = double(num1) / double(denum1);
	int num2 = this->numerator, denum2 = this->denomerator;
	double fr2 = double(num2) / double(denum2);
	if (fr1 > fr2)
		return false;
	else if (fr1 = fr2)
		return true;
	else
		return true;
}

bool CFraction::operator<(const CFraction& fract1)  //метод перегрузки оператора <
{
	int num1 = fract1.numerator, denum1 = fract1.denomerator;
	double fr1 = double(num1) / double(denum1);
	int num2 = this->numerator, denum2 = this->denomerator;
	double fr2 = double(num2) / double(denum2);
	if (fr1 < fr2)
		return false;
	else if (fr1 > fr2)
		return true;
	else
		return false;
}

bool CFraction::operator<=(const CFraction& fract1)  //метод перегрузки оператора <=
{
	int num1 = fract1.numerator, denum1 = fract1.denomerator;
	double fr1 = double(num1) / double(denum1);
	int num2 = this->numerator, denum2 = this->denomerator;
	double fr2 = double(num2) / double(denum2);
	if (fr1 < fr2)
		return false;
	else if (fr1 = fr2)
		return true;
	else 
		return true;
}

bool CFraction::operator==(const CFraction& fract1)  //метод перегрузки оператора ==
{
	int num1 = fract1.numerator, denum1 = fract1.denomerator;
	double fr1 = double(num1) / double(denum1);
	int num2 = this->numerator, denum2 = this->denomerator;
	double fr2 = double(num2) / double(denum2);
	if (fr1 != fr2)
		return false;
	else return true;
}

bool CFraction::operator!=(const CFraction& fract1)  //метод перегрузки оператора !=
{
	int num1 = fract1.numerator, denum1 = fract1.denomerator;
	double fr1 = double(num1) / double(denum1);
	int num2 = this->numerator, denum2 = this->denomerator;
	double fr2 = double(num2) / double(denum2);
	if (fr1 == fr2)
		return false;
	else return true;
}