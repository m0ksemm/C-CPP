#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Person abstract // Базовий абстрактний клас Person
{
private:
    string Name;    // Поле для збереження імені людини
    string Surname; // Поле для збереження прізвища людини
    int Age;        // Поле для збереження віку людини
    string Gender;  // Поле для збереження гендеру людини
public:
    Person();   // Конструктор за замовченням 

    void SetName(string n);   // Метод для зміни поля Name
    string GetName() const;   // Метод для отримання поля Name

    void SetSurname(string n); // Метод для зміни поля Surname
    string GetSurname() const; // Метод отримання зміни поля Surname

    void SetAge(int a); // Метод для зміни поля Age
    int GetAge() const; // Метод отримання зміни поля Age

    void SetGender(string g); //  Метод для зміни поля Gender
    string GetGender() const; //  Метод для отримання поля Gender

    virtual void GetInfo() const; // Віртуальний метод для виведення інформації про об'єкт
    virtual void Save() const;    // Віртуальний метод для збереження файлів в файл
};

