#pragma once

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();                     //конструктор за замовченням
    Date(int, int, int);        // конструктор з параметрами 
    Date(const Date &);         // конструктор копіювання 

    static bool Leapyear(int);                    // знаходження високосного року
    static bool Correctdate(int, int, int);       // перевірка дати на коректність 

    int Getday() const;         // метод для отримування дня
    int Getmonth() const;       // метод для отримування місяця
    int Getyear() const;        // метод для отримування року
    void Setday(int);           // модифікатор дня
    void Setmonth(int);         // модифікатор місяця
    void Setyear(int);          // модифікатор року

    Date& operator=(const Date &);  // перевантаження оператору =  
    Date& operator++ ();            // перевантаження ++ (преф) 
    Date operator++ (int);          // перевантаження ++ (постф) 
    Date& operator-- ();            // перевантаження -- (преф) 
    Date operator-- (int);          // перевантаження -- (постф)
    
    void operator+(const int);          // перевантаження + для додавання днів
    bool operator==(Date &);            // перевантаження ==
    bool operator>(Date &);             // перевантаження >
    bool operator<(Date &);             // перевантаження < 
    int operator-(Date &);              // перевантаження - (результат = кількості днів між датми)

    int Dayofweek(int, int, int) const;         // метод для отрмання дня тижня 
    int Dayofweeknumber();                      // метод для  порядкового номеру дня тижня з початку року
    void Dateoutput() const;                    // метод для виведення дати 
};

