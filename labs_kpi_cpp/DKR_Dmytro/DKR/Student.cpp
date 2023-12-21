#include "Student.h"

Student::Student() : Person()// ������ ������������ �������� �����  
{
	Avg = 0;
}

Student::Student(string name, string surname, int age, string gender, double avg) : Person() // ����������� � 5 �����������
{
	this->SetName(name);
	this->SetSurname(surname);
	this->SetAge(age);
	this->SetGender(gender);
	Avg = avg;
}

double Student::GetAvg() const // ����� ��� �������� ���� Avg
{
	return Avg;
}
void Student::SetAvg(double d) // ����� ���� �������� ���� Avg
{
	Avg = d;
}

void Student::GetInfo() const // �������������� ������ ��� ��������� ���������� � ������� 
{
	Person::GetInfo();  // ������ ������ GetInfo � �������� �����
	cout << "|Average grade:| " << Avg << endl; // ���������� ������, ��������������, ��� ����,
	cout << "----------------" << endl;         // ��� ������� ��������� ���� - Avg
}

void Student::Save() const // �������������� ������ ��� ���������� ���������� � ���� 
{
	Person::Save(); // ������ ������ Save � �������� �����
	ofstream f("group.txt", ios::app); // ���������� ������, ��������������, ��� ����, 
	f << Avg;						   // ��� ���������� � ���� ��������� ���� Avg
	f << "\n";
	f.close();
}
