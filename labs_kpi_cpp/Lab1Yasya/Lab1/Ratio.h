#pragma once
class Ratio
{
private:
    int num;
    int denum;
public:
    Ratio(); //конструктор за замовченням
    Ratio(int n); //конструктор з одним параметром
    Ratio(int n, int d); // конструктор з параметрами 
    Ratio(const Ratio& obj); // конструктор копіювання 
    bool IfCorrectRatio(int n, int d); // метод для з'ясування чи є дата коректною 
    void Input(int n, int d); // метод для заповнення всіх полів одразу полів
    Ratio& operator+(int n);
    Ratio& operator+(const Ratio& obj);
    Ratio& operator-(int n);
    Ratio& operator-(const Ratio& obj);
    Ratio& operator*(int n);
    Ratio& operator*(const Ratio& obj);
    Ratio& operator/(int n);
    Ratio& operator/(const Ratio& obj);
    bool operator==(const Ratio& obj);
    bool operator==(int n);
    bool operator<(const Ratio& obj);
    bool operator<(int n);
    bool operator>(const Ratio& obj);
    bool operator>(int n);
    Ratio& operator^(int number);
    void Print(); // метод виведення/друкування дати 
    int GetNum();  // інспектор/геттер для дня
    int GetDenum(); // інспектор/геттер для місяці
    void SetNum(int n); // модифікатор/сеттер для дня
    void SetDenum(int d); // модифікатор/сеттер для місяця
    int IntPart();
    void FloatPart();
    double DoubleNumber();
    Ratio& operator=(const Ratio& obj);
    bool IfInt();
};

