#pragma once
class Ratio
{
private:
    int num;
    int denum;
public:
    Ratio(); //����������� �� �����������
    Ratio(int n); //����������� � ����� ����������
    Ratio(int n, int d); // ����������� � ����������� 
    Ratio(const Ratio& obj); // ����������� ��������� 
    bool IfCorrectRatio(int n, int d); // ����� ��� �'�������� �� � ���� ��������� 
    void Input(int n, int d); // ����� ��� ���������� ��� ���� ������ ����
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
    void Print(); // ����� ���������/���������� ���� 
    int GetNum();  // ���������/������ ��� ���
    int GetDenum(); // ���������/������ ��� �����
    void SetNum(int n); // �����������/������ ��� ���
    void SetDenum(int d); // �����������/������ ��� �����
    int IntPart();
    void FloatPart();
    double DoubleNumber();
    Ratio& operator=(const Ratio& obj);
    bool IfInt();
};

