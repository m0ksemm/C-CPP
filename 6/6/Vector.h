#pragma once
#include <iostream>
#include "Vector.h"
#include <iomanip>

using namespace std;

class Vector
{
	int* vect; // Вектор
	int size; // Размерность вектора
public:
	Vector(); // Конструктор по умолчанию
	Vector(int size); // Конструктор, позволяющий задавать размерность вектора
	Vector(const int* ptr, int size); // Конструктор, позволяющий проинициализировать вектор 
	// с помощью существующего массива
	Vector(const Vector& v); // Конструктор копирования
	~Vector(); // Деструктор
	int GetSize() const; // Функция возвращает размерность вектора
	void Print(); // Вывод на экран
	void Input(); // Заполнение вектора
	void Clear(); // Очистка вектора
	bool IsEmpty() const; // Возвращает истину, если вектор пустой
	void Add(const int& item); // Добавление элемента в вектор
	void Insert(int index, const int& item); // Вставка элементов в вектор по заданному индексу
	void Remove(int index); // Удаление элемента из вектора по заданному индексу

	Vector& operator++(); // Увеличение всех компонент вектора на единицу (префикс)
	Vector operator++(int k); // Увеличение всех компонент вектора на единицу (постфикс)
	Vector& operator--(); // Увеличение всех компонент вектора на единицу (префикс)
	Vector operator--(int k); // Увеличение всех компонент вектора на единицу (постфикс)

	Vector& operator=(const Vector& v); // Перегруженный оператор присваивания с копированием

	int& operator[](int index); // Перегруженный оператор присваивания с копированием

	Vector operator+(const Vector& v); // Сложение двух векторов
	Vector operator-(const Vector& v); // Вычитание двух векторов
	Vector operator*(const Vector& v); // Вычитание двух векторов

	Vector operator+(int n);// Сложение вектора с числом (каждый компонент вектора складывается с числом)
	Vector operator-(int n);//  Вычитание числа из вектора
	Vector operator*(int n); // Умножение вектора на число

	Vector& operator *= (const Vector& v); // Перегруженный оператор *= для умножения вектора на число
	Vector& operator -= (const Vector& v); // Перегруженный оператор -= для вычитания двух векторов
	Vector& operator += (const Vector& v); // Перегруженный оператор += для сложения двух векторов

	friend istream& operator>>(istream& cin, Vector& v); // Ввод вектора с клавиатуры
	friend ostream& operator<<(ostream& cout, Vector& v);// Вывод вектора на экран

};