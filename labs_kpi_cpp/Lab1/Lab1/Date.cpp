#include "Date.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;


Date::Date() //конструктор за замовченням
    {
        day = 1;
        month = 1;
        year = 1;
    }
bool Date::IfLeapYear(int y) // метод для з'ясування чи є рік високосним 
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return true;
    else return false;
}
bool Date::IfCorrectDate(int d, int m, int y) // метод для з'ясування чи є дата коректною 
{
    int flag = 0;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if (d < 32 && d > 0)
            flag++;
    }
    if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        if (d < 31 && d > 0)
            flag++;
    }
    if (m == 2)
    {
        bool leap = IfLeapYear(y);
        if (leap == true)
        {
            if (d < 30 && d > 0)
                flag++;
        }
        else
        {
            if (d < 29 && d > 0)
                flag++;
        }
    }
    if (flag == 1)
        return true;
    else return false;
}

void Date::Input(int d, int m, int y) // метод для заповнення всіх полів одразу полів
{
    if (IfCorrectDate(d, m, y) == true) // перевірка на коректність дати
    {
        year = y;
        day = d;
        month = m;
    }
    else // якщо дата не є коректною, поля заповнюються за замовченням
    {
        cout << "\nIncorrect values! Default values are used now(1,1,1);\n"; 

        day = 1;
        month = 1;
        year = 1;
    }
}

Date::Date(int d, int m, int y) // конструктор з параметрами 
{
    if (IfCorrectDate(d, m, y))
    {
        year = y;
        day = d;
        month = m;
    }
    else  // якщо дата не є коректною, поля заповнюються за замовченням
    {
        cout << "\nIncorrect values! Default constructor is called;\n";
        Date();
    }
}
Date::Date(const Date& obj) // конструктор копіювання 
{
    day = obj.day;
    month = obj.month;
    year = obj.year;
}
Date& Date::operator=(const Date& obj)  // перевантаження оператору присвоєння з копіюванням  
{
    if (this == &obj)
        return *this;
    day = obj.day;
    month = obj.month;
    year = obj.year;
    return *this;
}

Date& Date::operator++ () // перевантаження префіксного інкрименту 
{
    day++;
    if (month == 12 && day == 32)// початок перевірки для переходу на наступний місяць або рік
    {
        day = 1;
        month = 1;
        year += 1;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
    {
        if (day == 32)
        {
            month++;
            day = 1;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day == 31)
        {
            month++;
            day = 1;
        }
    }
    else if (month == 2)
    {
        bool leap = IfLeapYear(year);
        if (leap == true)
        {
            if (day == 30)
            {
                month++;
                day = 1;
            }
        }
        else
        {
            if (day == 29)
            {
                month++;
                day = 1;
            }
        }
    }
    return *this;
}
Date Date::operator++ (int number) // перевантаження постфіксного інкрименту 
{
    Date tmp = *this;
    this->day++;
    if (month == 12 && day == 32) // початок перевірки для переходу на наступний місяць або рік
    {
        this->day = 1;
        this->month = 1;
        this->year += 1;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
    {
        if (day == 32)
        {
            month++;
            this->day = 1;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day == 31)
        {
            month++;
            this->day = 1;
        }
    }
    else if (month == 2)
    {
        bool leap = IfLeapYear(year);
        if (leap == true)
        {
            if (day == 30)
            {
                month++;
                this->day = 1;
            }
        }
        else
        {
            if (day == 29)
            {
                month++;
                this->day = 1;
            }
        }
    }

    return tmp;
}
Date& Date::operator-- () // перевантаження префіксного декрименту 
{
    day--;
    if (month == 1 && day == 0) // початок перевірки для переходу на попередній місяць або рік
    {
        day = 31;
        month = 12;
        year -= 1;
    }
    else if (day == 0)
    {
        if (month - 1 == 1 || month - 1 == 3 || month - 1 == 5 || month - 1 == 7 || month - 1 == 8 || month - 1 == 10)
        {
            month--;
            day = 31;
        }
        else if (month - 1 == 4 || month - 1 == 6 || month - 1 == 9 || month - 1 == 11)
        {
            month--;
            day = 30;
        }
        else if (month - 1 == 2)
        {
            bool leap = IfLeapYear(year);
            if (leap == true)
            {
                day = 29;
                month--;
            }
            else
            {
                day = 28;
                month--;
            }
        }
    }
    return *this;
}
Date Date::operator-- (int number) // перевантаження постфіксного декрименту 
{
    Date tmp = *this;
    this->day--;

    if (month == 1 && day == 0)// початок перевірки для переходу на попередній місяць або рік
    {
        this->day = 31;
        this->month = 12;
        this->year -= 1;
    }
    else if (this->day == 0)
    {
        if (month - 1 == 1 || month - 1 == 3 || month - 1 == 5 || month - 1 == 7 || month - 1 == 8 || month - 1 == 10)
        {
            this->month--;
            this->day = 31;
        }
        else if (month - 1 == 4 || month - 1 == 6 || month - 1 == 9 || month - 1 == 11)
        {
            this->month--;
            this->day = 30;
        }
        else if (month - 1 == 2)
        {
            bool leap = IfLeapYear(year);
            if (leap == true)
            {
                this->day = 29;
                this->month--;
            }
            else
            {
                this->day = 28;
                this->month--;
            }
        }
    }

    return tmp;
}
void Date::Print() // метод виведення/друкування дати 
{

    cout << char(201);
    for (int i = 0; i < 20; i++)
    {
        if (i == 5 || i == 13)
            cout << char(203);
        else cout << char(205);
    }
    cout << char(187) << endl;

    cout << char(186) << " Day " << char(186) << " Month " << char(186) << " Year " << char(186) << endl;

    cout << char(204);
    for (int i = 0; i < 20; i++)
    {
        if (i == 5 || i == 13)
            cout << char(206);
        else cout << char(205);
    }
    cout << char(185) << endl;

    cout << char(186) << " ";
    cout << setw(2) << day;
    cout << "  " << char(186) << "  ";
    cout << setw(2) << month << "   " << char(186) << " ";
    cout << setw(4) << year << " " << char(186) << endl;

    cout << char(200);
    for (int i = 0; i < 20; i++)
    {
        if (i == 5 || i == 13)
            cout << char(202);
        else cout << char(205);
    }
    cout << char(188) << endl;


}

int Date::GetDay() // інспектор/геттер для дня
{
    return day;
}
int Date::GetMonth() // інспектор/геттер для місяці
{
    return month;
}
int Date::GetYear() // інспектор/геттер для року
{
    return year;
}

void Date::SetDay(int d) // модифікатор/сеттер для дня
{
    int tmp = day;
    day = d;
    if (IfCorrectDate(day, month, year) == false)
    {
        cout << "Incorrect value! Modification is canceled(DAY)\n";
        day = tmp;
        system("pause");

    }
}
void Date::SetMonth(int m) // модифікатор/сеттер для місяця
{
    int tmp = month;
    month = m;
    if (IfCorrectDate(day, month, year) == false)
    {
        cout << "Incorrect value! Modification is canceled(MONTH)\n";
        month = tmp;
        system("pause");
    }
}
void Date::SetYear(int y) // модифікатор/сеттер для року
{
    int tmp = year;
    year = y;
    if (IfCorrectDate(day, month, year) == false)
    {
        cout << "Incorrect value! Modification is canceled(YEAR)\n";
        year = tmp;
        system("pause");
    }
}

void Date::operator+(const int number)   // перевантажений оператор + для додавання заданої кількості днів
{
    day += number;

    while (IfCorrectDate(day, month, year) != true)
    {


        if (month == 12 && day > 31)
        {
            day = day - 31;
            month = 1;
            year += 1;
        }
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
        {
            if (day > 31)
            {
                month++;
                day = day - 31;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day > 30)
            {
                month++;
                day = day - 30;
            }
        }
        else if (month == 2)
        {
            bool leap = IfLeapYear(year);
            if (leap == true)
            {
                if (day > 29)
                {
                    month++;
                    day -= 29;
                }
            }
            else
            {
                if (day > 28)
                {
                    month++;
                    day = day - 28;
                }
            }
        }
    }
}

bool Date::operator==(Date date2)  // перевантажений оператор == для перевірки дат на рівність 
{
    if (year == date2.year && month == date2.month && day == date2.day)
        return true;
    else return false;
}

bool Date::operator>(Date date2) // перевантажений оператор > для порівняння дат
{
    if (year > date2.year)
    {
        return true;
    }
    else if (year == date2.year && month > date2.month)
    {
        return true;
    }
    if (year == date2.year && month == date2.month && day > date2.day)
    {
        return true;
    }
    else return false;
}

bool Date::operator<(Date date2) // перевантажений оператор < для порівняння дат
{
    if (year < date2.year)
    {
        return true;
    }
    else if (year == date2.year && month < date2.month)
    {
        return true;
    }
    if (year == date2.year && month == date2.month && day < date2.day)
    {
        return true;
    }
    else return false;
}

int Date::operator-(Date date2) // перевантажений оператор - для віднімання дат(визначення кількості днів між датми)
{
    if (*this == date2)
    {
        return 0;
    }
    int count = 0;
    Date tmp = *this;
    if (*this > date2)
    {
        while ((*this == date2) == false)
        {
            --* this;
            count++;
        }
    }
    else
    {
        while ((*this == date2) == false)
        {
            ++* this;
            count++;
        }
    }
    *this = tmp;
    return count;
}

int Date::CaculateWeekDay(int d, int m, int y)  // метод для з'ясування дня тижня 
{

    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int iWeek = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;  //Формула розрахунку Кіма Ларсона
    switch (iWeek)
    {
    case 0:
        cout << " Monday \n" << endl;
        break;
    case 1:
        cout << " Tuesday \n" << endl;
        break;
    case 2:
        cout << " Wednesday \n" << endl;
        break;
    case 3:
        cout << " Thursday \n" << endl;
        break;
    case 4:
        cout << " Friday \n" << endl;
        break;
    case 5:
        cout << " Saturday \n" << endl;
        break;
    case 6:
        cout << " Sunday \n" << endl;
        break;
    }
    return iWeek;
}

int Date::DayOfWeekNumber()  // метод для обрахування порядкового номеру дня тижня з початку року
{
    Date tmp(1, 1, year);
    int count = 1;

    while (tmp < *this)
    {
        tmp + 7;
        count++;
    }
    return count;
}
