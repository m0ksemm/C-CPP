// 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "CFraction.h"

using namespace std;



CFraction Sum(CFraction fract1, CFraction fract2)
{
	CFraction result;
	int n1 = fract1.getNumerator();
	int n2 = fract1.getDenomerator();
	int m1 = fract2.getNumerator();
	int m2 = fract2.getDenomerator();

	result.setNumerator(n1 * m2 + n2 * m1);
	result.setDenomerator(n2 * m2);

	return result;
}

CFraction Minus(CFraction fract1, CFraction fract2)
{
	CFraction result;
	int n1 = fract1.getNumerator();
	int n2 = fract1.getDenomerator();
	int m1 = fract2.getNumerator();
	int m2 = fract2.getDenomerator();

	result.setNumerator(n1 * m2 - n2 * m1);
	result.setDenomerator(n2 * m2);

	return result;
}

CFraction Product(CFraction fract1, CFraction fract2)
{
	CFraction result;
	int n1 = fract1.getNumerator();
	int n2 = fract1.getDenomerator();
	int m1 = fract2.getNumerator();
	int m2 = fract2.getDenomerator();

	result.setNumerator(n1 * m1);
	result.setDenomerator(n2 * m2);

	return result;
}

CFraction Division(CFraction fract1, CFraction fract2)
{
	CFraction result;
	int n1 = fract1.getNumerator();
	int n2 = fract1.getDenomerator();
	int m1 = fract2.getNumerator();
	int m2 = fract2.getDenomerator();

	result.setNumerator(n1 * m2);
	result.setDenomerator(n2 * m1);

	return result;
}

int main()
{
	cout << "\nOverloaded operator test (DISCRIBED LIKE METHODS)\n\n\n";
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