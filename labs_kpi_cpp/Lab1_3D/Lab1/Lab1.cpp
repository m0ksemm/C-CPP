// Lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Date.h"
#include <iostream>

using namespace std;


int main()
{
    cout << "(1)\n";  //конструктори
    Date d1;
    Date d2(d1);
    Date d3(23, 3, 1987);

    d1.Dateoutput();
    cout << endl;
    d2.Dateoutput();
    cout << endl;
    d3.Dateoutput();
    cout << endl;


    cout << "\n(2)\n";  //операції ++ та --
    d3++; 
    d3.Dateoutput();
    cout << endl;

    ++d3; 
    d3.Dateoutput();
    cout << endl;

    d3--; 
    d3.Dateoutput();
    cout << endl;

    --d3;
    d3.Dateoutput();
    cout << endl;


    cout << "\n(3)\n";  //операції + та -
    d3 + 7;
    d3.Dateoutput();
    cout << endl;

    Date d4(d3);
    d4.Dateoutput();
    cout << endl;
    --d4; --d4; --d4;

    int n = d3 - d4;
    cout << n << endl;
    
    cout << "\n(4)\n\n";  //читання та модифікація окремих полів

    cout << d4.Getday() << ", " << d4.Getmonth() << ", " << d4.Getyear();

    d4.Setday(21);
    d4.Setmonth(4);
    d4.Setyear(2012);
    d4.Dateoutput();
    cout << endl;
    
    cout << "\n(5)\n";  //операція присвоєння

    Date d5;
    d5 = d4;
    d5.Dateoutput();

    cout << "\n\n(6)\n\n";  //визначення дня тижня, порядкового номеру тижня
    d5.Dayofweek(d5.Getday(), d5.Getmonth(), d5.Getyear());

    n = d5.Dayofweeknumber();
    cout << n << endl;

    cout << "\n(7)\n";  //порівняння дат

    if (d1 > d5)
        cout << "\ntrue";
    else cout << "\nfalse";

    if (d1 < d5)
        cout << "\ntrue";
    else cout << "\nfalse";

    if (d5 == d4)
        cout << "\ntrue";
    else cout << "\nfalse";

}
