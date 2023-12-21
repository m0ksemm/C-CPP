#include "Teacher.h"

Teacher::Teacher() : Person()  // ����������� �� ����������� 
{
	WorkExp = 0;
}
Teacher::Teacher(string name, string surname, int age, string gender, int wrk) : Person() // ����������� � 5 �����������.
{
	this->SetName(name);
	this->SetSurname(surname);
	this->SetAge(age);
	this->SetGender(gender);
	Teacher::SetWorkExp(wrk);
}

int Teacher::GetWorkExp() const // ����� ��� ��������� ������
{
	return WorkExp;
}
void Teacher::SetWorkExp(double d) // ����� ��� ���� ������
{
	WorkExp = d;
}
void Teacher::GetInfo() const // �������������� ����� ��� ��������� ���������� � ������ 
{ 
	Person::GetInfo();
	cout << "|Work exper.:  | " << WorkExp << endl;
	cout << "----------------" << endl;
}
void Teacher::Save() const // �������������� ����� ��� ������ ���������� � ��������� ���� 
{ 
	Person::Save();
	ofstream f("group.txt", ios::app);
	f << WorkExp;
	f << "\n";
	f.close();
}
