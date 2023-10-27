// 14.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Person.h"
#include "Student.h"
#include "AcademyGroup.h"
#include <iomanip>
#include <Windows.h>
#include <conio.h>

using namespace std;

ostream& operator<<(ostream& cout, const Person& pers)
{
    pers.Print();
    return cout;
}

istream& operator>>(istream& cin, Person& pers)
{
    char nm[200];
    int ag;

    cout << "Enter the name: ";
    cin.getline(nm, 200);
    pers.setName(nm);

    cout << "Enter the surname: ";
    cin.getline(nm, 200);
    pers.setSurname(nm);

    cout << "Enter the age: ";
    cin >> ag;
    pers.setAge(ag);
    cin.ignore();

    return cin;
}

ostream& operator<<(ostream& cout, const Student& pers)
{
    pers.Print();

    return cout;
}

istream& operator>>(istream& cin, Student& pers)
{
    char nm[200];
    int ag;
    double rat;

    cout << "Enter the name: ";
    cin.getline(nm, 200);
    pers.setName(nm);

    cout << "Enter the surname: ";
    cin.getline(nm, 200);
    pers.setSurname(nm);

    cout << "Enter the age: ";
    cin >> ag;
    pers.setAge(ag);
    cin.ignore();

    cout << "Enter the phone: ";
    cin.getline(nm, 200);
    pers.setPhone(nm);

    cout << "Enter the rating: ";
    cin >> rat;
    pers.setRating(rat);
    cin.ignore();

    return cin;
}

ostream& operator<<(ostream& cout, AcademyGroup& pers)
{
    pers.Print();

    return cout;
}

void menu()
{
    cout << char(201);
    for (int i = 0; i < 22; i++)
        cout << char(205);
    cout << char(187) ;
    
    cout << endl <<char(186) << "     Student group    " << char(186) << endl;

    cout << char(204);
    for (int i = 0; i < 22; i++)
        cout << char(205);
    cout << char(185) << endl;

    cout << char(186) << "1. Add students       " << char(186) << endl;
    cout << char(186) << "2. Delete a student   " << char(186) << endl;
    cout << char(186) << "3. Edit student's data" << char(186) << endl;
    cout << char(186) << "4. Print the group    " << char(186) << endl;
    cout << char(186) << "5. Sort the group     " << char(186) << endl;
    cout << char(186) << "6. Search             " << char(186) << endl;
    cout << char(186) << "7. Save               " << char(186) << endl;
    cout << char(186) << "8. Load               " << char(186) << endl;
    cout << char(186) << "9. Exit               " << char(186) << endl;

    cout << char(200);
    for (int i = 0; i < 22; i++)
        cout << char(205);
    cout << char(188) << endl;
}

int main()
{
    int choice;
    AcademyGroup p;
    bool flag = true;
    

    while (flag == true)
    {
        system("cls");
        menu();
        
        choice = _getch();

        switch (choice)
        {
        case '1':
            p.AddStudents();
            break;
        case '2':
            p.DeleteStudent();
            break;
        case '3':
            p.EditStudent();
            break;
        case '4':
            p.Print();
            break;
        case '5':
            p.Sort();
            break;
        case '6':
            p.FindStudent();
            break;
        case '7':
            p.Save();
            break;
        case '8':
            p.Load();
            break;
        case '9':
            flag = false;
            break;
        }
    }

}

