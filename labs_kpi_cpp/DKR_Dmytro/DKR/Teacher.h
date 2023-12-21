#pragma once
#include "Person.h";

class Teacher : public Person // ���� Teacher, �������� �� ����� Person
{
private:
	int WorkExp; // ��������� ����, ��� ������ ������� ���� ������ ���������
public:
	Teacher(); // ����������� �� ����������� 
	Teacher(string name, string surname, int age, string gender, int wrk); // ����������� � 5 �����������.
									// ��� ����������� �������� �������������� �� ���� ��'���� ����� ��� ��������. 
	int GetWorkExp() const;    // ����� ��� ��������� ������
	void SetWorkExp(double d); // ����� ��� ���� ������

	void GetInfo() const override; // �������������� ����� ��� ��������� ���������� � ������ 
	void Save() const override;    // �������������� ����� ��� ������ ���������� � ��������� ���� 
};