// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	CFraction fract1, fract2;

	int num1, denum1, num2, denum2;

	cout << "Test1:" << endl;

	cout << "Enter the NUMERATOR of the 1 fraction: ";
	cin >> num1;
	fract1.setNumerator(num1);
	cout << "Enter the DENOMERATOR of the 1 fraction: ";
	cin >> denum1;
	fract1.setDenomerator(denum1);


	cout << "Enter the NUMERATOR of the 2 fraction: ";
	cin >> num2;
	fract2.setNumerator(num2);
	cout << "Enter the DENOMERATOR of the 2 fraction: ";
	cin >> denum2;
	fract2.setDenomerator(denum2);

	cout << "fraction1: ";
	fract1.output_fraction();

	cout << "\nfraction2: ";
	fract2.output_fraction();


	cout << endl;
	cout << "\nTest2:";

	cout << "\nfraction1: ";
	int n1 =fract1.getNumerator();
	cout << n1;
	cout << "/";
	int n2 =fract1.getDenomerator();
	cout << n2;

	cout << "\nfraction2: ";
	int m1 = fract2.getNumerator();
	cout << m1;
	cout << "/";
	int m2 = fract2.getDenomerator();
	cout << m2;

	cout << "\n\nTest3:\n";
	int number11 = fract1.getNumerator();
	int number12 = fract1.getDenomerator();
	int result1 = fract1.int_part(number11, number12);

	int number21 = fract2.getNumerator();
	int number22 = fract2.getDenomerator();
	int result2 = fract2.int_part(number21, number22);
	cout << "Int part of the 1 fraction = " << result1 << endl;
	cout << "Int part of the 2 fraction = " << result2 << endl;

	cout << "\nTest4:\n";

	CFraction fr(2, 4);
	cout << "Constructed fraction: ";
	fr.output_fraction();

	cout << "\n\nTest5:\n";
	int num11 = fract1.getNumerator();
	int num22 = fract1.getDenomerator();
	double doubl_frac1 = fract1.double_fraction(num11, num22);
	fract1.output_fraction();
	cout << " = " << doubl_frac1 << endl;

	int num111 = fract2.getNumerator();
	int num222 = fract2.getDenomerator();
	double doubl_frac2 = fract2.double_fraction(num111, num222);
	fract2.output_fraction();
	cout << " = " << doubl_frac2 << endl;

	cout << "\nTest6(test of the Sum function):\n";
	CFraction result = Sum(fract1, fract2);
	fract1.output_fraction();
	cout << " + ";
	fract2.output_fraction();
	cout << " = ";
	result.output_fraction();

	cout << "\n\nTest7(test of the Minus function):\n";
	CFraction result_test_7 = Minus(fract1, fract2);
	fract1.output_fraction();
	cout << " - ";
	fract2.output_fraction();
	cout << " = ";
	result_test_7.output_fraction();

	cout << "\n\nTest8(test of the Product function):\n";
	CFraction result_test_8 = Product(fract1, fract2);
	fract1.output_fraction();
	cout << " * ";
	fract2.output_fraction();
	cout << " = ";
	result_test_8.output_fraction();

	cout << "\n\nTest9(test of the Division function):\n";
	CFraction result_test_9 = Division(fract1, fract2);
	fract1.output_fraction();
	cout << " / ";
	fract2.output_fraction();
	cout << " = ";
	result_test_9.output_fraction();

}