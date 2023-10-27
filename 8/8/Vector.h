#pragma once
#include <iostream>
#include "Vector.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

template <typename T> class Vector
{
	T* vect; // Вектор
	int size; // Размерность вектора
public:
	Vector(); // Конструктор по умолчанию
	Vector(int size); // Конструктор, позволяющий задавать размерность вектора
	Vector(const T* ptr, int size); // Конструктор, позволяющий проинициализировать вектор 
	// с помощью существующего массива
	Vector(const Vector& v); // Конструктор копирования
	~Vector(); // Деструктор
	T GetSize() const; // Функция возвращает размерность вектора
	void Print(); // Вывод на экран
	void Input(); // Заполнение вектора
	void Clear(); // Очистка вектора
	bool IsEmpty() const; // Возвращает истину, если вектор пустой
	void Add(const T& item); // Добавление элемента в вектор
	void Insert(int index, const T& item); // Вставка элементов в вектор по заданному индексу
	void Remove(int index); // Удаление элемента из вектора по заданному индексу
	void Rand();


	Vector& operator++(); // Увеличение всех компонент вектора на единицу (префикс)
	Vector operator++(int k); // Увеличение всех компонент вектора на единицу (постфикс)
	Vector& operator--(); // Увеличение всех компонент вектора на единицу (префикс)
	Vector operator--(int k); // Увеличение всех компонент вектора на единицу (постфикс)

	Vector& operator=(const Vector& v); // Перегруженный оператор присваивания с копированием

	T& operator[](int index); // Перегруженный оператор присваивания с копированием

	Vector operator+(const Vector& v); // Сложение двух векторов
	Vector operator-(const Vector& v); // Вычитание двух векторов
	Vector operator*(const Vector& v); // Вычитание двух векторов

	Vector operator+(T n);// Сложение вектора с числом (каждый компонент вектора складывается с числом)
	Vector operator-(T n);//  Вычитание числа из вектора
	Vector operator*(T n); // Умножение вектора на число

	Vector& operator *= (const Vector& v); // Перегруженный оператор *= для умножения вектора на число
	Vector& operator -= (const Vector& v); // Перегруженный оператор -= для вычитания двух векторов
	Vector& operator += (const Vector& v); // Перегруженный оператор += для сложения двух векторов
	
	//template <typename T> class Vector
	friend istream& operator>>(istream& cin, Vector& v); // Ввод вектора с клавиатуры

	friend ostream& operator<<(ostream& cout, Vector& v);// Вывод вектора на экран
	//friend istream& operator>>(istream& cin, Vector<double>& v); // Ввод вектора с клавиатуры
	//friend ostream& operator<<(ostream& cout, Vector<double><int>& v);// Вывод вектора на экран

};

template <typename T> Vector<T>::Vector()
{
	vect = nullptr;
	size = 0;
}

template <typename T> Vector<T>::Vector(int size)
{
	vect = new T[size];
	memset(vect, 0, sizeof(T));
	this->size = size;
}

template <typename T> Vector<T>::Vector(const Vector<T>& obj)
{
	this->size = obj.size;
	this->vect = new T[this->size];
	for (int i = 0; i < this->size; i++)
		this->vect[i] = obj.vect[i];
}

template <typename T> Vector<T>::Vector(const T* ptr, int size)// Конструктор, позволяющий проинициализировать вектор с помощью существующего массива
{
	this->size = size;
	T* vect = new T[size];
	for (int i = 0; i < size; i++)
	{
		*(vect + i) = *(ptr + i);
	}
	this->vect = vect;
}

template <typename T> Vector<T>::~Vector()
{
	delete[] this->vect;
	this->size = 0;
	this->vect = nullptr;
}

template <typename T> T Vector<T>::GetSize() const
{
	return size;
}


template <typename T> void Vector<T>::Print()
{
	for (int i = 0; i < size; i++)
		cout << setw(6) << *(vect + i);
	cout << endl;
}

template <typename T> void Vector<T>::Rand()
{
	//srand(time(0));
	for (int i = 0; i < size; i++)
		vect[i] = rand() % 41 - 20;
}

template <typename T> void Vector<T>::Input()
{
	cout << "\n Enter " << size << " elements of the vector:\n";
	for (int i = 0; i < size; i++)
	{
		cin >> *(vect + i);
	}
}


template <typename T> void Vector<T>::Clear()
{
	this->size = 0;
	this->vect = nullptr;
}

template <typename T> bool Vector<T>::IsEmpty() const
{
	if (vect == nullptr)
		return true;
	else return false;
}

template <typename T> void Vector<T>::Add(const T& item)
{
	T* ptr = new T[++size];
	for (int i = 0; i < size - 1; i++)
	{
		*(ptr + i) = *(vect + i);
	}
	*(ptr + size - 1) = item;
	delete[]vect;
	vect = ptr;
}

template <typename T> void Vector<T>::Insert(int index, const T& item)
{
	if (index < 0 || index > size)
		return;
	T* p = new T[size + 1];
	this->size += 1;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (index == i)
		{
			k = 1;
			p[i] = item;
		}
		else
			p[i] = vect[i - k];
	}
	delete[]vect;
	vect = p;
}

template <typename T> void Vector<T>::Remove(int index)
{
	if (index < 0 || index > size - 1)
		return;
	T* p = new T[--size];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (index == i)
			k = 1;
		p[i] = vect[i + k];
	}
	delete[]vect;
	vect = p;
}




template <typename T> T& Vector<T>::operator[](int index)
{
	if (index < 0 || index > this->size)
		return this->vect[0];
	return this->vect[index];
}




template <typename T> Vector<T>& Vector<T>::operator++() // Увеличение всех компонент вектора на единицу (префикс) 
{
	for (int i = 0; i < size; i++)
	{
		++vect[i];
	}
	return *this;
}

template <typename T> Vector<T> Vector<T>::operator++ (int k) // Увеличение всех компонент вектора на единицу (постфикс) 
{
	Vector tmp = *this;
	for (int i = 0; i < size; i++)
	{
		++vect[i];
	}
	return tmp;
}

template <typename T> Vector<T>& Vector<T>::operator--() // Уменьшение всех компонент вектора на единицу (префикс) 
{
	for (int i = 0; i < size; i++)
	{
		--vect[i];
	}
	return *this;
}

template <typename T> Vector<T> Vector<T>::operator-- (int k) // Уменьшение всех компонент вектора на единицу (постфикс) 
{
	Vector tmp = *this;
	for (int i = 0; i < size; i++)
	{
		--vect[i];
	}
	return tmp;
}

template <typename T> Vector<T>& Vector<T>::operator=(const Vector& v) // Перегруженный оператор присваивания с копированием
{
	if (this == &v)
		return *this;
	delete[] this->vect;
	this->vect = new T[v.size];
	this->size = v.size;
	for (int i = 0; i < this->size; i++)
	{
		this->vect[i] = v.vect[i];
	}
	return *this;
}

template <typename T> Vector<T> Vector<T>::operator+(const Vector& v)
{
	if (this->size != v.size)
	{
		return *this;
	}

	T* arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = this->vect[i] + v.vect[i];
	}

	Vector v_res(arr, this->size);
	delete[]arr;
	return v_res;
}

template <typename T> Vector<T> Vector<T>::operator-(const Vector& v)
{
	if (this->size != v.size)
	{
		return *this;
	}

	T* arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = this->vect[i] - v.vect[i];
	}

	Vector v_res(arr, this->size);
	delete[]arr;
	return v_res;
}

template <typename T> Vector<T> Vector<T>::operator*(const Vector& v)
{
	if (this->size != v.size)
	{
		return *this;
	}

	T* arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = this->vect[i] * v.vect[i];
	}

	Vector v_res(arr, this->size);
	delete[]arr;
	return v_res;
}

template <typename T> Vector<T> Vector<T>::operator+(T n)
{
	T* arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = this->vect[i] + n;
	}

	Vector v_res(arr, this->size);
	delete[]arr;
	return v_res;
}

template <typename T> Vector<T> Vector<T>::operator-(T n)
{
	T* arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = this->vect[i] - n;
	}
	Vector v_res(arr, this->size);
	delete[]arr;
	return v_res;
}

template <typename T> Vector<T> Vector<T>::operator*(T n)
{
	T* arr = new T[this->size];
	for (int i = 0; i < this->size; i++)
	{
		arr[i] = this->vect[i] * n;
	}
	Vector v_res(arr, this->size);
	delete[]arr;
	return v_res;
}

template <typename T> Vector<T>& Vector<T>::operator+=(const Vector& v)
{

	for (int i = 0; i < this->size; i++)
	{
		this->vect[i] += v.vect[i];
	}

	return *this;
}

template <typename T> Vector<T>& Vector<T>::operator-=(const Vector& v)
{

	for (int i = 0; i < this->size; i++)
	{
		this->vect[i] -= v.vect[i];
	}

	return *this;
}

template <typename T> Vector<T>& Vector<T>::operator*=(const Vector& v)
{

	for (int i = 0; i < this->size; i++)
	{
		this->vect[i] *= v.vect[i];
	}

	return *this;
}