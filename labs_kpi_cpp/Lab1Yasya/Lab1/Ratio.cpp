#include "Ratio.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

Ratio::Ratio() //����������� �� �����������
{
    num = 1;
    denum = 2;
}

Ratio::Ratio(int n) //����������� � ����� ����������
{
    num = n;
    denum = 1;
}

bool Ratio::IfCorrectRatio(int n, int d) // ����� ��� �'�������� �� � ��� ��������� 
{
    if (d == 0)
        return false;
    else return true;
}

void Ratio::Input(int n, int d) // ����� ��� ���������� ��� ���� ������ ����
{
    if (IfCorrectRatio(n, d) == true) // �������� �� ���������� �����
    {
        num = n;
        denum = d;
    }
    else // ���� ��� �� � ���������, ���� ������������ �� �����������
    {
        cout << "\nIncorrect values! Default values are used now(1,2);\n";

        num = 1;
        denum = 2;
    }
}

Ratio::Ratio(int n, int d) // ����������� � ����������� 
{
    if (IfCorrectRatio(n, d))
    {
        num = n;
        denum = d;
    }
    else  // ���� ��� �� � ���������, ���� ������������ �� �����������
    {
        cout << "\nIncorrect values! Default constructor is called;\n";
        Ratio();
    }
}
Ratio::Ratio(const Ratio& obj) // ����������� ��������� 
{
    num = obj.num;
    denum = obj.denum;
}
Ratio& Ratio::operator+(int n) // �������������� ��������� +
{
    num += n * denum;

    return *this;
}
Ratio& Ratio::operator+(const Ratio& obj)
{
    num = num * obj.denum + obj.num * denum;
    denum *= obj.denum;

    return *this;
}
Ratio& Ratio::operator-(int n) // �������������� ��������� -
{
    num -= n * denum;

    return *this;
}
Ratio& Ratio::operator-(const Ratio& obj)
{
    num = num * obj.denum - obj.num * denum;
    denum *= obj.denum;

    return *this;
}
Ratio& Ratio::operator*(int n) // �������������� ��������� *
{
    num *= n;

    return *this;
}
Ratio& Ratio::operator*(const Ratio& obj)
{
    num *= obj.num;
    denum *= obj.denum;

    return *this;
}
Ratio& Ratio::operator/(int n) // �������������� ��������� /
{
    denum *= n;

    return *this;
}
Ratio& Ratio::operator/(const Ratio& obj)
{
    num *= obj.denum;
    denum *= obj.num;

    return *this;
}
bool Ratio::operator==(const Ratio& obj) // �������������� ��������� ������
{
    if ((double(num) / double(denum)) == (double(obj.num) / double(obj.denum)))
        return true;
    else return false;
}
bool Ratio::operator==(int n)
{
    if ((double(num) / double(denum)) - num / denum == 0 && num / denum == n)
        return true;
    else return false;
}
bool Ratio::operator<(const Ratio& obj) // �������������� ��������� <
{
    if ((double(num) / double(denum)) < (double(obj.num) / double(obj.denum)))
        return true;
    else return false;
}
bool Ratio::operator<(int n)
{
    if ((double(num) / double(denum)) < double(n))
        return true;
    else return false;
}
bool Ratio::operator>(const Ratio& obj) // �������������� ��������� <
{
    if ((double(num) / double(denum)) > (double(obj.num) / double(obj.denum)))
        return true;
    else return false;
}
bool Ratio::operator>(int n)
{
    if ((double(num) / double(denum)) > double(n))
        return true;
    else return false;
}
Ratio& Ratio::operator^(int number) // �������������� ��������� ��������� �� ��������
{
    int n = 1;
    int d = 1;

    for (int i = 0; i < number; i++)
    {
        n *= num;
    }
    for (int i = 0; i < number; i++)
    {
        d *= denum;
    }

    num = n;
    denum = d;

    return *this;
}

void Ratio::Print() // ����� ���������/���������� ����� 
{

    if (denum == 1)
        cout << '\n' << num << endl;
    else cout << '\n' << num << "/" << denum << endl;

}

int Ratio::GetNum() // ������ ��� ����������
{
    return num;
}
int Ratio::GetDenum() // ������ ��� ����������
{
    return denum;
}
void Ratio::SetNum(int n) // ����� ��� ����������
{
    num = n;
}
void Ratio::SetDenum(int d) // ����� ��� ����������
{
    if (d == 0)
        cout << "Error: denumerator can not = 0\n";
    else
        denum = d;
}
int Ratio::IntPart() // ����� ���������� ���� ������� �����
{
    return num / denum;
}
void Ratio::FloatPart() // ����� ���������� ������� ������� �����
{
    if (abs(num) > abs(denum))
    {
        if (num % denum == 0)
            cout << 0 << endl;
        else cout << num % denum << "/" << denum << endl;
    }
    else
    {
        this->Print();
    }
}
double Ratio::DoubleNumber() // ����� ������������ ����� �� ����� � ��������� �����
{
    return double(num) / double(denum);
}
Ratio& Ratio::operator=(const Ratio& obj) // �������������� ��������� ���������
{
    num = obj.num;
    denum = obj.denum;

    return *this;
}
bool Ratio::IfInt() // ����� ��� ���������� �� � ����� �����
{
    if (num % denum == 0)
        return true;
    else return false;
}