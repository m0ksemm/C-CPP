#pragma once

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date();                     //����������� �� �����������
    Date(int, int, int);        // ����������� � ����������� 
    Date(const Date &);         // ����������� ��������� 

    static bool Leapyear(int);                    // ����������� ����������� ����
    static bool Correctdate(int, int, int);       // �������� ���� �� ���������� 

    int Getday() const;         // ����� ��� ����������� ���
    int Getmonth() const;       // ����� ��� ����������� �����
    int Getyear() const;        // ����� ��� ����������� ����
    void Setday(int);           // ����������� ���
    void Setmonth(int);         // ����������� �����
    void Setyear(int);          // ����������� ����

    Date& operator=(const Date &);  // �������������� ��������� =  
    Date& operator++ ();            // �������������� ++ (����) 
    Date operator++ (int);          // �������������� ++ (�����) 
    Date& operator-- ();            // �������������� -- (����) 
    Date operator-- (int);          // �������������� -- (�����)
    
    void operator+(const int);          // �������������� + ��� ��������� ���
    bool operator==(Date &);            // �������������� ==
    bool operator>(Date &);             // �������������� >
    bool operator<(Date &);             // �������������� < 
    int operator-(Date &);              // �������������� - (��������� = ������� ��� �� �����)

    int Dayofweek(int, int, int) const;         // ����� ��� �������� ��� ����� 
    int Dayofweeknumber();                      // ����� ���  ����������� ������ ��� ����� � ������� ����
    void Dateoutput() const;                    // ����� ��� ��������� ���� 
};

