#include "Student.h"

Student::Student() : Person()// Виклик конструктора базового класу  
{
	Avg = 0;
}

Student::Student(string name, string surname, int age, string gender, double avg) : Person() // Конструктор з 5 параметрами
{
	this->SetName(name);
	this->SetSurname(surname);
	this->SetAge(age);
	this->SetGender(gender);
	Avg = avg;
}

double Student::GetAvg() const // Метод для отрмання поля Avg
{
	return Avg;
}
void Student::SetAvg(double d) // Метод зиіни отрмання поля Avg
{
	Avg = d;
}

void Student::GetInfo() const // Перевизначення методу для виведення інформації в консоль 
{
	Person::GetInfo();  // Виклик методу GetInfo з базового класу
	cout << "|Average grade:| " << Avg << endl; // Доповнення методу, перевизначення, для того,
	cout << "----------------" << endl;         // щоб вивести додаткове поде - Avg
}

void Student::Save() const // Перевизначення методу для збереження інформації в файл 
{
	Person::Save(); // Виклик методу Save з базового класу
	ofstream f("group.txt", ios::app); // Доповнення методу, перевизначення, для того, 
	f << Avg;						   // щоб дозаписати в файл додаткове поле Avg
	f << "\n";
	f.close();
}
