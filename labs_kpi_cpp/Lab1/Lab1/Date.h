#pragma once
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(); //конструктор за замовченням
    Date(int d, int m, int y); // конструктор з параметрами 
    Date(const Date& obj); // конструктор копіювання 
    bool IfLeapYear(int y); // метод для з'ясування чи є рік високосним 
    bool IfCorrectDate(int d, int m, int y); // метод для з'ясування чи є дата коректною 
    void Input(int d, int m, int y); // метод для заповнення всіх полів одразу полів
    Date& operator=(const Date& obj); // перевантаження оператору присвоєння з копіюванням  
    Date& operator++ (); // перевантаження префіксного інкрименту 
    Date operator++ (int number);  // перевантаження постфіксного інкрименту 
    Date& operator-- (); // перевантаження префіксного декрименту 
    Date operator-- (int number); // перевантаження постфіксного декрименту 
    void Print(); // метод виведення/друкування дати 
    int GetDay();  // інспектор/геттер для дня
    int GetMonth(); // інспектор/геттер для місяці
    int GetYear(); // інспектор/геттер для року
    void SetDay(int d); // модифікатор/сеттер для дня
    void SetMonth(int m); // модифікатор/сеттер для місяця
    void SetYear(int y);  // модифікатор/сеттер для року
    void operator+(const int number); // перевантажений оператор + для додавання заданої кількості днів
    bool operator==(Date date2); // перевантажений оператор == для перевірки дат на рівність 
    bool operator>(Date date2); // перевантажений оператор > для порівняння дат
    bool operator<(Date date2); // перевантажений оператор < для порівняння дат
    int operator-(Date date2); // перевантажений оператор - для віднімання дат(визначення кількості днів між датми)
    int CaculateWeekDay(int d, int m, int y); // метод для з'ясування дня тижня 
    int DayOfWeekNumber();  // метод для обрахування порядкового номеру дня тижня з початку року
};

