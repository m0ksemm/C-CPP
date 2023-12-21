#pragma once
#include "Person.h";

class Student : public Person // ���� Student, �������� �� ����� Person
{
private:
	double Avg;  // ���� ��� ���������� ���������� ���� �������� 
public:
	Student();  // ���������� �� �����������
	Student(string name, string surname, int age, string gender, double abg); // ����������� � 5 �����������

	double GetAvg() const; // ����� ��� �������� ���� Avg
	void SetAvg(double d); // ����� ���� �������� ���� Avg

	void GetInfo() const override; // �������������� ������ ��� ��������� ���������� � ������� 
	void Save() const override;    // �������������� ������ ��� ���������� ���������� � ���� 
};

