#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include "Student.h"
#include "Teacher.h"
#include <vector>

class Group  // Клас академічної групи. Містить в собі групу студентів та викладача,
{            // а також всі необхідні методи для роботи з даними 
private:
	vector<Person*> Students;  // Типізований вектор, який містить вказівники на абстрактний базовий клас Person (відповідно, і на всі похідні від нього класи)
	Person* teacher;  // вказівники на абстрактний базовий клас Person
public:
	Group(); // Конструктор за замовченням 

	void PrintGroup(); // Метод для виведення групи студнетів і викладача
	void AddStudent(); // Метод додавання нового студенту в групу 
	void RemoveStudent(); // Метод видалення студенту з групи 
	void SearchStudent(); // Метод пошуку студенту в групі. Пошук відбувається за вибраним користувачем критерієм  

	void ChangeTeacher(); // Метод для зміни інформації про викладача групи

	void SaveData(); // Метод для збереження всіх даних в файл 
	void LoadData(); // Метод для завантаження всіх даних з файлу
};

