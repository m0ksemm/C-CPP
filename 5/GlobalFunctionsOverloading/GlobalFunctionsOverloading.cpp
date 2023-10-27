// GFO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "CFraction.h"

using namespace std;

CFraction operator+(CFraction& fract1, CFraction& fract2)  //глобальная функция перегрузки оператора +
{
	CFraction result;

	result.setNumerator(fract1.numerator * fract2.denomerator + fract1.denomerator * fract2.numerator);
	result.setDenomerator(fract1.denomerator * fract2.denomerator);

	return result;
}

CFraction operator-(CFraction& fract1, CFraction& fract2)  //глобальная функция перегрузки оператора -
{
	CFraction result;

	result.setNumerator(fract1.numerator * fract2.denomerator - fract1.denomerator * fract2.numerator);
	result.setDenomerator(fract1.denomerator * fract2.denomerator);

	return result;
}

CFraction operator*(CFraction& fract1, CFraction& fract2)  //глобальная функция перегрузки оператора *
{
	CFraction result;

	result.setNumerator(fract1.numerator * fract2.numerator);
	result.setDenomerator(fract1.denomerator * fract2.denomerator);

	return result;
}

CFraction operator/(CFraction& fract1, CFraction& fract2)  //глобальная функция перегрузки оператора /
{
	CFraction result;
	
	result.setNumerator(fract1.numerator* fract2.denomerator);
	result.setDenomerator(fract1.denomerator * fract2.numerator);

	return result;
}

bool operator>(CFraction& fract1, CFraction& fract2)       //глобальная функция перегрузки оператора >
{
	double fr1 = double(fract2.numerator) / double(fract2.denomerator);
	double fr2 = double(fract1.numerator) / double(fract1.denomerator);
	
	if (fr1 > fr2)
		return false;
	else if (fr1 < fr2)
		return true;
	else
		return false;
}

bool operator>=(CFraction& fract1, CFraction& fract2)     //глобальная функция перегрузки оператора >=
{
	double fr1 = double(fract2.numerator) / double(fract2.denomerator);
	double fr2 = double(fract1.numerator) / double(fract1.denomerator);

	if (fr1 > fr2)
		return false;
	else if (fr1 = fr2)
		return true;
	else
		return true;
}

bool operator<(CFraction& fract1, CFraction &fract2 )    //глобальная функция перегрузки оператора <
{
	double fr1 = double(fract2.numerator) / double(fract2.denomerator);
	double fr2 = double(fract1.numerator) / double(fract1.denomerator);

	if (fr1 < fr2)
		return false;
	else if (fr1 > fr2)
		return true;
	else
		return false;
}

bool operator<=(CFraction& fract1, CFraction& fract2)    //глобальная функция перегрузки оператора <=
{
	double fr1 = double(fract2.numerator) / double(fract2.denomerator);
	double fr2 = double(fract1.numerator) / double(fract1.denomerator);

	if (fr1 < fr2)
		return false;
	else if (fr1 = fr2)
		return true;
	else
		return true;
}

bool operator==(CFraction& fract1, CFraction& fract2)    //глобальная функция перегрузки оператора ==
{
	double fr1 = double(fract2.numerator) / double(fract2.denomerator);
	double fr2 = double(fract1.numerator) / double(fract1.denomerator);

	if (fr1 != fr2)
		return false;
	else return true;
}

bool operator!=(CFraction& fract1, CFraction& fract2)    //глобальная функция перегрузки оператора !=
{
	
	double fr1 = double(fract2.numerator) / double(fract2.denomerator);
	double fr2 = double(fract1.numerator) / double(fract1.denomerator);

	if (fr1 == fr2)
		return false;
	else return true;
}

int main()
{
	cout << "\nOverloaded operator test (DISCRIBED LIKE GLOBAL FUNCTIONS) \n\n\n";
	int x1, y1, x2, y2;
	cout << "x1/y1;    x2/y2;\n";
	cout << "enter x1: ";
	cin >> x1;
	cout << "enter y1: ";
	cin >> y1;
	cout << "enter x2: ";
	cin >> x2;
	cout << "enter y2: ";
	cin >> y2;

	CFraction fract1(x1, y1);
	CFraction fract2(x2, y2);

	cout << endl << fract1.getNumerator() << "/" << fract1.getDenomerator();
	cout << " + " << fract2.getNumerator() << "/" << fract2.getDenomerator() << " = ";
	CFraction fract3 = fract1 + fract2;
	fract3.output_fraction();
	cout << endl;

	cout << fract1.getNumerator() << "/" << fract1.getDenomerator();
	cout << " - " << fract2.getNumerator() << "/" << fract2.getDenomerator() << " = ";
	fract3 = fract1 - fract2;
	fract3.output_fraction();

	cout << endl << fract1.getNumerator() << "/" << fract1.getDenomerator();
	cout << " * " << fract2.getNumerator() << "/" << fract2.getDenomerator() << " = ";
	fract3 = fract1 * fract2;
	fract3.output_fraction();

	cout << endl << fract1.getNumerator() << "/" << fract1.getDenomerator();
	cout << " / " << fract2.getNumerator() << "/" << fract2.getDenomerator() << " = ";
	fract3 = fract1 / fract2;
	fract3.output_fraction();


	cout << "\n\nx1/y1;    x2/y2;\n";
	cout << "enter x1: ";
	cin >> x1;
	cout << "enter y1: ";
	cin >> y1;
	cout << "enter x2: ";
	cin >> x2;
	cout << "enter y2: ";
	cin >> y2;

	fract1.setNumerator(x1);
	fract1.setDenomerator(y1);
	fract2.setNumerator(x2);
	fract2.setDenomerator(y2);

	cout << endl << fract1.getNumerator() << "/" << fract1.getDenomerator();
	cout << " > " << fract2.getNumerator() << "/" << fract2.getDenomerator() << " : ";
	bool flag = fract1 > fract2;
	if (flag == 1)
		cout << "TRUE";
	else cout << "FALSE";

	cout << endl << fract1.getNumerator() << "/" << fract1.getDenomerator();
	cout << " >= " << fract2.getNumerator() << "/" << fract2.getDenomerator() << " : ";
	flag = fract1 >= fract2;
	if (flag == 1)
		cout << "TRUE";
	else cout << "FALSE";

	cout << endl << fract1.getNumerator() << "/" << fract1.getDenomerator();
	cout << " < " << fract2.getNumerator() << "/" << fract2.getDenomerator() << " : ";
	flag = fract1 < fract2;
	if (flag == 1)
		cout << "TRUE";
	else cout << "FALSE";

	cout << endl << fract1.getNumerator() << "/" << fract1.getDenomerator();
	cout << " <= " << fract2.getNumerator() << "/" << fract2.getDenomerator() << " : ";
	flag = fract1 <= fract2;
	if (flag == 1)
		cout << "TRUE";
	else cout << "FALSE";

	cout << endl << fract1.getNumerator() << "/" << fract1.getDenomerator();
	cout << " == " << fract2.getNumerator() << "/" << fract2.getDenomerator() << " : ";
	flag = fract1 == fract2;
	if (flag == 1)
		cout << "TRUE";
	else cout << "FALSE";

	cout << endl << fract1.getNumerator() << "/" << fract1.getDenomerator();
	cout << " != " << fract2.getNumerator() << "/" << fract2.getDenomerator() << " : ";
	flag = fract1 != fract2;
	if (flag == 1)
		cout << "TRUE";
	else cout << "FALSE";
}