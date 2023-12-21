#include "Teacher.h"

Teacher::Teacher() : Person()  // Конструктор за замовченням 
{
	WorkExp = 0;
}
Teacher::Teacher(string name, string surname, int age, string gender, int wrk) : Person() // Конструктор з 5 параметрами.
{
	this->SetName(name);
	this->SetSurname(surname);
	this->SetAge(age);
	this->SetGender(gender);
	Teacher::SetWorkExp(wrk);
}

int Teacher::GetWorkExp() const // Метод для отримання досвіду
{
	return WorkExp;
}
void Teacher::SetWorkExp(double d) // Метод для зміни досвіду
{
	WorkExp = d;
}
void Teacher::GetInfo() const // Перевизначений метод для виведення інформації в консль 
{ 
	Person::GetInfo();
	cout << "|Work exper.:  | " << WorkExp << endl;
	cout << "----------------" << endl;
}
void Teacher::Save() const // Перевизначений метод для запису інформації в текстовий файл 
{ 
	Person::Save();
	ofstream f("group.txt", ios::app);
	f << WorkExp;
	f << "\n";
	f.close();
}
