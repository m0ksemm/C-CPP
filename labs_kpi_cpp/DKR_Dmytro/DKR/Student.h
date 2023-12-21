#pragma once
#include "Person.h";

class Student : public Person // Клас Student, похідний від класу Person
{
private:
	double Avg;  // Поле для збереження середнього балу студенту 
public:
	Student();  // Контруктор за замовченням
	Student(string name, string surname, int age, string gender, double abg); // Конструктор з 5 параметрами

	double GetAvg() const; // Метод для отрмання поля Avg
	void SetAvg(double d); // Метод зиіни отрмання поля Avg

	void GetInfo() const override; // Перевизначення методу для виведення інформації в консоль 
	void Save() const override;    // Перевизначення методу для збереження інформації в файл 
};

