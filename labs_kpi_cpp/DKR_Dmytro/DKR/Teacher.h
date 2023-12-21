#pragma once
#include "Person.h";

class Teacher : public Person // Клас Teacher, похідний від класу Person
{
private:
	int WorkExp; // Додаткове поле, яке зберігає кількість років досвіду викладача
public:
	Teacher(); // Конструктор за замовченням 
	Teacher(string name, string surname, int age, string gender, int wrk); // Конструктор з 5 параметрами.
									// Цей конструктор дозволяє проініціалізувати всі поля об'єкут класу при створенні. 
	int GetWorkExp() const;    // Метод для отримання досвіду
	void SetWorkExp(double d); // Метод для зміни досвіду

	void GetInfo() const override; // Перевизначений метод для виведення інформації в консль 
	void Save() const override;    // Перевизначений метод для запису інформації в текстовий файл 
};