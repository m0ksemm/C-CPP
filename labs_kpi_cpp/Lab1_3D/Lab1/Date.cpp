#include "Date.h"
#include <iostream>

using namespace std;

Date::Date() //конструктор за замовченням
{
   day = 1;
    month = 1;
   year = 1;
}
Date::Date(int d, int m, int y) // конструктор з параметрами 
{
    if (Correctdate(d, m, y))
    {
        year = y;
        day = d;
        month = m;
    }
    else  Date();
}
Date::Date(const Date& obj) // конструктор копіювання 
{
    day = obj.day;
    month = obj.month;
    year = obj.year;
}


bool Date::Leapyear(int y) // знаходження високосного року
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return true;
    else return false;
}
bool Date::Correctdate(int d, int m, int y) // перевірка дати на коректність 
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
        bool leap = Leapyear(y);
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

int Date::Getday() const // метод для отримування дня
{
    return day;
}
int Date::Getmonth() const // метод для отримування місяця
{
    return month;
}
int Date::Getyear() const // метод для отримування року
{
    return year;
}

void Date::Setday(int d) // модифікатор дня
{
    int tmp = day;
    day = d;
    if (Correctdate(day, month, year) == false)
        day = tmp;
}
void Date::Setmonth(int m) // модифікатор місяця
{
    int tmp = month;
    month = m;
    if (Correctdate(day, month, year) == false)
        month = tmp;
}
void Date::Setyear(int y) // модифікатор року
{
    int tmp = year;
    year = y;
    if (Correctdate(day, month, year) == false)
        year = tmp;
}



Date& Date::operator=(const Date& obj)  // перевантаження оператору = 
{
    if (this == &obj)
        return *this;
    day = obj.day;
    month = obj.month;
    year = obj.year;
    return *this;
}
Date& Date::operator++ () // перевантаження ++ (преф) 
{
    day++;
    if (month == 12 && day == 32)
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
        bool leap = Leapyear(year);
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
Date Date::operator++ (int number) // перевантаження ++ (постф) 
{
    Date tmp = *this;
    this->day++;
    if (month == 12 && day == 32) 
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
        bool leap = Leapyear(year);
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
Date& Date::operator-- () // перевантаження -- (преф) 
{
    day--;
    if (month == 1 && day == 0) 
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
            bool leap = Leapyear(year);
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
Date Date::operator-- (int number) // перевантаження -- (постф)
{
    Date tmp = *this;
    this->day--;

    if (month == 1 && day == 0)
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
            bool leap = Leapyear(year);
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


void Date::operator+(const int number)  // перевантаження + для додавання днів
{
    day += number;

    while (Correctdate(day, month, year) != true)
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
            bool leap = Leapyear(year);
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

bool Date::operator==(Date &_date)  // перевантаження == 
{
    if (year == _date.year && month == _date.month && day == _date.day)
        return true;
    else return false;
}

bool Date::operator>(Date &_date) // перевантаження >
{
    if (year > _date.year)
        return true;
    else if (year == _date.year && month > _date.month)
        return true;
    if (year == _date.year && month == _date.month && day > _date.day)
        return true;
    else return false;
}

bool Date::operator<(Date &date2) // перевантаження < 
{
    if (year < date2.year)
        return true;
    else if (year == date2.year && month < date2.month)
        return true;
    if (year == date2.year && month == date2.month && day < date2.day)
        return true;
    else return false;
}

int Date::operator-(Date &date2) // перевантаження - (результат = кількості днів між датми)
{
    if (*this == date2)
        return 0;
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

int Date::Dayofweek(int d, int m, int y) const // метод для з'ясування дня тижня 
{
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int Week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;  //Формула розрахунку Кіма Ларсона
    
    if (Week == 0)
        cout << " It is Monday \n";
    else if (Week == 1)
        cout << " It is Tuesday \n";
    else if (Week == 2)
        cout << " It is Wednesday \n";
    else if (Week == 3)
        cout << " It is Thursday \n";
    else if (Week == 4)
        cout << " It is Friday \n";
    else if (Week == 5)
        cout << " It is Saturday \n";
    else cout << " It is Sunday \n";

    return Week;
}

int Date::Dayofweeknumber() // метод для порядкового номеру дня тижня з початку року
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

void Date::Dateoutput() const // метод для виведення дати 
{
    cout << "\nDay: " << day;
    cout << "\nMonth: " << month;
    cout << "\nYear: " << year;
}
