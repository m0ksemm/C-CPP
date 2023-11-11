#include "Ratio.h"
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>

using namespace std;

Ratio::Ratio() //конструктор за замовченням
{
    num = 1;
    denum = 2;
}

Ratio::Ratio(int n) //конструктор з одним параметром
{
    num = n;
    denum = 1;
}

bool Ratio::IfCorrectRatio(int n, int d) // метод для з'ясування чи є дріб коректним 
{
    if (d == 0)
        return false;
    else return true;
}

void Ratio::Input(int n, int d) // метод для заповнення всіх полів одразу полів
{
    if (IfCorrectRatio(n, d) == true) // перевірка на коректність дробу
    {
        num = n;
        denum = d;
    }
    else // якщо дріб не є коректним, поля заповнюються за замовченням
    {
        cout << "\nIncorrect values! Default values are used now(1,2);\n";

        num = 1;
        denum = 2;
    }
}

Ratio::Ratio(int n, int d) // конструктор з параметрами 
{
    if (IfCorrectRatio(n, d))
    {
        num = n;
        denum = d;
    }
    else  // якщо дріб не є коректним, поля заповнюються за замовченням
    {
        cout << "\nIncorrect values! Default constructor is called;\n";
        Ratio();
    }
}
Ratio::Ratio(const Ratio& obj) // конструктор копіювання 
{
    num = obj.num;
    denum = obj.denum;
}
Ratio& Ratio::operator+(int n) // перевантаження оператору +
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
Ratio& Ratio::operator-(int n) // перевантаження оператору -
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
Ratio& Ratio::operator*(int n) // перевантаження оператору *
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
Ratio& Ratio::operator/(int n) // перевантаження оператору /
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
bool Ratio::operator==(const Ratio& obj) // перевантаження оператору рівності
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
bool Ratio::operator<(const Ratio& obj) // перевантаження оператору <
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
bool Ratio::operator>(const Ratio& obj) // перевантаження оператору <
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
Ratio& Ratio::operator^(int number) // перевантаження оператору піднесення до степення
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

void Ratio::Print() // метод виведення/друкування дробу 
{

    if (denum == 1)
        cout << '\n' << num << endl;
    else cout << '\n' << num << "/" << denum << endl;

}

int Ratio::GetNum() // геттер для чисельника
{
    return num;
}
int Ratio::GetDenum() // геттер для знаменника
{
    return denum;
}
void Ratio::SetNum(int n) // сетер для чисельника
{
    num = n;
}
void Ratio::SetDenum(int d) // сетер для знаменника
{
    if (d == 0)
        cout << "Error: denumerator can not = 0\n";
    else
        denum = d;
}
int Ratio::IntPart() // метод визначення цілої частини дробу
{
    return num / denum;
}
void Ratio::FloatPart() // метод визначення дробової частини дробу
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
double Ratio::DoubleNumber() // метод перетворення дробу на число з плаваючою комою
{
    return double(num) / double(denum);
}
Ratio& Ratio::operator=(const Ratio& obj) // перевантаження оператора присвоєння
{
    num = obj.num;
    denum = obj.denum;

    return *this;
}
bool Ratio::IfInt() // метод для визначення чи є число цілим
{
    if (num % denum == 0)
        return true;
    else return false;
}