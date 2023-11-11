// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include "Date.h"

using namespace std;


int main()
{
    Date dt, dt1, dt2;
    bool f = 1;
    int d = 22, m = 11, y = 2003;
    int d1, m1, y1, n;

    Date newdt(d, m, y);

    Date copydt(newdt);

    while (f == 1)
    {
        system("cls");
        int choice;
        
        cout << "Enter the choice:  \n";
        cout << " Press ENTER to print the date(object newdt)  \n";
        cout << " Press ESCAPE to finish the program  \n";
        cout << "1 - Test of constructors; \n";
        cout << "2 - Increment and decrement operators; \n";
        cout << "3 - Adding an integer number of days, difference between two dates; \n";
        cout << "4 - Setters and getters(object dt); \n";
        cout << "5 - Assignment operations; \n";
        cout << "6 - Define day and number of the week(object newdt); \n";
        cout << "7 - Comparison of dates  \n";

        choice = _getch();
        

        switch (choice)
        {
        case VK_RETURN: 
        {
            system("cls");
            newdt.Print();
            system("pause");
            break;
        }
        case VK_ESCAPE:
        {
            f = 0;
            break;
        }
        case '1':
            system("cls");
            cout << "Task1.\n";
            cout << "Implement the corresponding constructors:" << endl;
            cout << "by default (default value: January 1 of " << endl;
            cout << "year 1), copying and initialization with " << endl; 
            cout << "a value day, month and year." << endl << endl;;

            cout << "Default constructor(dt):\n";
            dt.Print();

            cout << "\n\Constructor with parametres(newdt):\n";
            newdt.Print();

            cout << "\n\Copy constructor:(copydt, copied from newdt)\n";
            copydt.Print();

            system("pause");
            break;
        case '2':
            system("cls");
            cout << "Task2.\n";
            cout << "Implement increment and decrement operations" << endl;
            cout << "(both prefix and postfix), which implements " << endl;
            cout << "the transition to the next / previous day.  " << endl << endl;

            cout << "Enter the new date: \n";
            cout << "Day: ";
            cin >> d;
            cout << "Month: ";
            cin >> m;
            cout << "Year: ";
            cin >> y;
            
            dt.Input(d, m, y);
            cout << endl << endl;
            cout << "increments: \n";

            cout << "In code: dt++.Print();" << endl;;
            dt++.Print();
            cout << endl;

            cout << "In code: dt.Print();" << endl;;
            dt.Print();
            cout << endl;

            cout << "In code: (++dt).Print();" << endl;;
            (++dt).Print();
            cout << endl;

            cout << "decrements: \n";

            cout << "In code: dt--.Print();" << endl;;
            dt--.Print();
            cout << endl;

            cout << "In code: dt.Print();" << endl;;
            dt.Print();
            cout << endl;

            cout << "In code: (--dt).Print();" << endl;;
            (--dt).Print();
            cout << endl;

            system("pause");
            break;
        case '3':
            system("cls");
            cout << "Task3.\n";
            cout << "Implement mathematical operations: adding an " << endl;
            cout << "integer number of days, difference between two " << endl;
            cout << "dates(gives the number of days between them)." << endl << endl;

            cout << "\n newdt: \n";
            newdt.Print();

            cout << "\nEnter the number of days(n): ";
            cin >> n;
            newdt + n;
            cout << "\nResult(int code: newdt + n;):\n";
            newdt.Print();

            cout << "\n\nThe number of days between two dates\n\n";
            cout << "Enter the first date(Date1): \n";
            cout << "Day: ";
            cin >> d;
            cout << "Month: ";
            cin >> m;
            cout << "Year: ";
            cin >> y;

            dt1.Input(d, m, y);

            cout << "\nEnter the second date(Date2): \n";
            cout << "Day: ";
            cin >> d;
            cout << "Month: ";
            cin >> m;
            cout << "Year: ";
            cin >> y;

            dt2.Input(d, m, y);

            n = dt1 - dt2;

            cout << "\nNumber of days between Date1 and Date2 = " << n << endl << endl;

            system("pause");
            break;
        case '4':
            system("cls");
            cout << "Task4.\n";
            cout << "Implement the possibility of reading and modifying " << endl;
            cout << "individual fields (date, month, year). At the same " << endl;
            cout << "time, in the case of submission of incorrect value, " << endl;
            cout << "the modification must be canceled. " << endl << endl;

            cout << "\n dt: \n";
            dt.Print();

            cout << "\nEnter the day: ";
            cin >> d;
            dt.SetDay(d);
            dt.Print();

            cout << "\n\nEnter the month: ";
            cin >> m;
            dt.SetMonth(m);
            dt.Print();

            cout << "\n\nEnter the year: ";
            cin >> y;
            dt.SetYear(y);
            dt.Print();

            cout << "\nGetters: \n\n";

            cout << "Day: " << dt.GetDay() << endl;
            cout << "Month: " << dt.GetMonth() << endl;
            cout << "Year: " << dt.GetYear() << endl;

            system("pause");
            break;
        case '5':
            system("cls");
            cout << "Task5.\n";
            cout << "Implement assignment operations." << endl << endl;

            cout << "dt:\n";
            dt.Print();
            cout << "newdt:\n";
            newdt.Print();

            cout << "In code: newdt = dt; newdt.Print();  \nResult:\n";
            newdt = dt;
            newdt.Print();

            system("pause");
            break;

        case '6':
            system("cls");
            cout << "Task6.\n";
            cout << "Implement the definition of the day of " << endl;
            cout << "the week, as well as the serial number " << endl;
            cout << "of the week (from the beginning of the " << endl;
            cout << "year) for a given date. " << endl << endl;

            cout << "\n newdt: \n";
            newdt.Print();
            cout << endl;

            newdt.CaculateWeekDay(newdt.GetDay(), newdt.GetMonth(), newdt.GetYear());
            cout << "The number of week in this year = " << newdt.DayOfWeekNumber() << endl << endl;
            system("pause");

            break;
        case '7':
            system("cls");
            cout << "Task7.\n";
            cout << "Implement date comparison" << endl;
            cout << "(both for equality and in order)." << endl << endl;

            cout << "Enter the first date: \n";
            cout << "Day: ";
            cin >> d;
            cout << "Month: ";
            cin >> m;
            cout << "Year: ";
            cin >> y;

            dt1.Input(d, m, y);
            
            cout << "\nEnter the second date: \n";
            cout << "Day: ";
            cin >> d;
            cout << "Month: ";
            cin >> m;
            cout << "Year: ";
            cin >> y;

            dt2.Input(d, m, y);

            if (dt1 > dt2)
            {
                cout << "\nDate1 > Date2\n";
            }
            else if (dt1 < dt2)
            {
                cout << "\nDate1 < Date2\n";
            }
            else if (dt1 == dt2)
            {
                cout << "\nDate1 == Date2\n";
            }
            system("pause");

            break;
        }
    }

    cout << "\n\n\nKV-11, Cheban Maksym Dmytrovych, Variant 19(4)\n\n";
}
