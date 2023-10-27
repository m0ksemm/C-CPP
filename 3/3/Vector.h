#pragma once
#include <iostream>
#include "Vector.h"
#include <iomanip>


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
};