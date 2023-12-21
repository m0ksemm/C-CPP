#include "Person.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

Person::Person() // ����������� �� �����������
{
    Name = "";
    Surname = "";
    Age = 0;
    Gender = "";
}

void Person::SetName(string n) // ����� ��� ���� ���� Name
{
    Name = n;
}
string Person::GetName() const // ����� ��� ��������� ���� Name
{
    return Name;
}

void Person::SetSurname(string n) // ����� ��� ���� ���� Surname
{
    Surname = n;
}
string Person::GetSurname() const // ����� ��� ��������� ���� Surname
{
    return Surname;
}

void Person::SetAge(int a) // ����� ��� ���� ���� Age
{ 
    Age = a;
}
int Person::GetAge() const // ����� ��� ��������� ���� Age
{
    return Age;
}

void Person::SetGender(string g) // ����� ��� ���� ���� Gender
{
    Gender = g;
}
string Person::GetGender() const // ����� ��� ��������� ���� Gender
{
    return Gender;
}

void Person::GetInfo() const // ����� ��� ��������� ����� 
{
    cout << "|Name:         | " << Name << endl;
    cout << "|Surname:      | " << Surname << endl;
    cout << "|Age:          | " << Age << endl;
    cout << "|Gender:       | " << Gender << endl;
}

void Person::Save() const // ����� ��� ���������� ����� � ����
{
    ofstream f("group.txt", ios::app);
    f << Name;
    f << "\n";
    f << Surname;
    f << "\n";
    f << Age;
    f << "\n";
    f << Gender;
    f << "\n";
    f.close();
}
