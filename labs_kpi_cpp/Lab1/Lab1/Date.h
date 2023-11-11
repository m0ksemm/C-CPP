#pragma once
class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date(); //����������� �� �����������
    Date(int d, int m, int y); // ����������� � ����������� 
    Date(const Date& obj); // ����������� ��������� 
    bool IfLeapYear(int y); // ����� ��� �'�������� �� � �� ���������� 
    bool IfCorrectDate(int d, int m, int y); // ����� ��� �'�������� �� � ���� ��������� 
    void Input(int d, int m, int y); // ����� ��� ���������� ��� ���� ������ ����
    Date& operator=(const Date& obj); // �������������� ��������� ��������� � ����������  
    Date& operator++ (); // �������������� ����������� ���������� 
    Date operator++ (int number);  // �������������� ������������ ���������� 
    Date& operator-- (); // �������������� ����������� ���������� 
    Date operator-- (int number); // �������������� ������������ ���������� 
    void Print(); // ����� ���������/���������� ���� 
    int GetDay();  // ���������/������ ��� ���
    int GetMonth(); // ���������/������ ��� �����
    int GetYear(); // ���������/������ ��� ����
    void SetDay(int d); // �����������/������ ��� ���
    void SetMonth(int m); // �����������/������ ��� �����
    void SetYear(int y);  // �����������/������ ��� ����
    void operator+(const int number); // �������������� �������� + ��� ��������� ������ ������� ���
    bool operator==(Date date2); // �������������� �������� == ��� �������� ��� �� ������ 
    bool operator>(Date date2); // �������������� �������� > ��� ��������� ���
    bool operator<(Date date2); // �������������� �������� < ��� ��������� ���
    int operator-(Date date2); // �������������� �������� - ��� �������� ���(���������� ������� ��� �� �����)
    int CaculateWeekDay(int d, int m, int y); // ����� ��� �'�������� ��� ����� 
    int DayOfWeekNumber();  // ����� ��� ����������� ����������� ������ ��� ����� � ������� ����
};

