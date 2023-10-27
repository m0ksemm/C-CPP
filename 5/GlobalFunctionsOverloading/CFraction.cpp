#include <iostream>
#include "CFraction.h"

using namespace std;

//CONSTRUCTORS
CFraction::CFraction()//����������� ��� ����������
{
	// ����������� ������ �� ���������
	numerator = 31;
	denomerator = 12;
}

CFraction::CFraction(int num, int denum)//����������� � �����������
{
	// ����������� ������ �� ���������
	numerator = num;
	denomerator = denum;
}

//METHODS
void CFraction::enter_fraction() // �����, ���������� �� ��������� ������������� ����� ������
{
	cout << "Numerator : ";
	cin >> numerator;
	cout << "Denomerator : ";
	cin >> denomerator;
}

void CFraction::output_fraction()// �����, ���������� �� ����� ����� �� �����
{
	cout << numerator << "/" << denomerator;
}

void CFraction::setNumerator(int num) // ����������� ��� ���� numerator
{
	numerator = num;
}
void CFraction::setDenomerator(int denum) // ����������� ��� ���� denomerator
{
	denomerator = denum;
}

int CFraction::getNumerator() // ��������� ��� ���� numerator
{
	return numerator;
}
int CFraction::getDenomerator() // ��������� ��� ���� denomerator
{
	return denomerator;
}

int CFraction::int_part(int num, int denum) // ����� ��������� ����� �����.
{
	num = numerator;
	denum = denomerator;
	return (num / denum);
}

double CFraction::double_fraction(int num, int denum)// ����� �������� ����� � ������������ �����.
{
	num = numerator;
	denum = denomerator;
	return (double(num) / double(denum));
}

