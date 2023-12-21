#include "Person.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

Person::Person() // Конструктор за замовченням
{
    Name = "";
    Surname = "";
    Age = 0;
    Gender = "";
}

void Person::SetName(string n) // Метод для зміни поля Name
{
    Name = n;
}
string Person::GetName() const // Метод для отримання поля Name
{
    return Name;
}

void Person::SetSurname(string n) // Метод для зміни поля Surname
{
    Surname = n;
}
string Person::GetSurname() const // Метод для отримання поля Surname
{
    return Surname;
}

void Person::SetAge(int a) // Метод для зміни поля Age
{ 
    Age = a;
}
int Person::GetAge() const // Метод для отримання поля Age
{
    return Age;
}

void Person::SetGender(string g) // Метод для зміни поля Gender
{
    Gender = g;
}
string Person::GetGender() const // Метод для отримання поля Gender
{
    return Gender;
}

void Person::GetInfo() const // Метод для виведення даних 
{
    cout << "|Name:         | " << Name << endl;
    cout << "|Surname:      | " << Surname << endl;
    cout << "|Age:          | " << Age << endl;
    cout << "|Gender:       | " << Gender << endl;
}

void Person::Save() const // Метод для збереження даних в файл
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
