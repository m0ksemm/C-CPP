#pragma once
#include <iostream>
#include "Vector.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

template <typename T> class Vector
{
	T* vect; // ������
	int size; // ����������� �������
public:
	Vector(); // ����������� �� ���������
	Vector(int size); // �����������, ����������� �������� ����������� �������
	Vector(const T* ptr, int size); // �����������, ����������� ������������������� ������ 
	// � ������� ������������� �������
	Vector(const Vector& v); // ����������� �����������
	~Vector(); // ����������
	T GetSize() const; // ������� ���������� ����������� �������
	void Print(); // ����� �� �����
	void Input(); // ���������� �������
	void Clear(); // ������� �������
	bool IsEmpty() const; // ���������� ������, ���� ������ ������
	void Add(const T& item); // ���������� �������� � ������
	void Insert(int index, const T& item); // ������� ��������� � ������ �� ��������� �������
	void Remove(int index); // �������� �������� �� ������� �� ��������� �������
	void Rand();


	Vector& operator++(); // ���������� ���� ��������� ������� �� ������� (�������)
	Vector operator++(int k); // ���������� ���� ��������� ������� �� ������� (��������)
	Vector& operator--(); // ���������� ���� ��������� ������� �� ������� (�������)
	Vector operator--(int k); // ���������� ���� ��������� ������� �� ������� (��������)

	Vector& operator=(const Vector& v); // ������������� �������� ������������ � ������������

	T& operator[](int index); // ������������� �������� ������������ � ������������

	Vector operator+(const Vector& v); // �������� ���� ��������
	Vector operator-(const Vector& v); // ��������� ���� ��������
	Vector operator*(const Vector& v); // ��������� ���� ��������

	Vector operator+(T n);// �������� ������� � ������ (������ ��������� ������� ������������ � ������)
	Vector operator-(T n);//  ��������� ����� �� �������
	Vector operator*(T n); // ��������� ������� �� �����

	Vector& operator *= (const Vector& v); // ������������� �������� *= ��� ��������� ������� �� �����
	Vector& operator -= (const Vector& v); // ������������� �������� -= ��� ��������� ���� ��������
	Vector& operator += (const Vector& v); // ������������� �������� += ��� �������� ���� ��������
	
	//template <typename T> class Vector
	friend istream& operator>>(istream& cin, Vector& v); // ���� ������� � ����������

	friend ostream& operator<<(ostream& cout, Vector& v);// ����� ������� �� �����
	//friend istream& operator>>(istream& cin, Vector<double>& v); // ���� ������� � ����������
	//friend ostream& operator<<(ostream& cout, Vector<double><int>& v);// ����� ������� �� �����

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

template <typename T> Vector<T>::Vector(const T* ptr, int size)// �����������, ����������� ������������������� ������ � ������� ������������� �������
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




template <typename T> Vector<T>& Vector<T>::operator++() // ���������� ���� ��������� ������� �� ������� (�������) 
{
	for (int i = 0; i < size; i++)
	{
		++vect[i];
	}
	return *this;
}

template <typename T> Vector<T> Vector<T>::operator++ (int k) // ���������� ���� ��������� ������� �� ������� (��������) 
{
	Vector tmp = *this;
	for (int i = 0; i < size; i++)
	{
		++vect[i];
	}
	return tmp;
}

template <typename T> Vector<T>& Vector<T>::operator--() // ���������� ���� ��������� ������� �� ������� (�������) 
{
	for (int i = 0; i < size; i++)
	{
		--vect[i];
	}
	return *this;
}

template <typename T> Vector<T> Vector<T>::operator-- (int k) // ���������� ���� ��������� ������� �� ������� (��������) 
{
	Vector tmp = *this;
	for (int i = 0; i < size; i++)
	{
		--vect[i];
	}
	return tmp;
}

template <typename T> Vector<T>& Vector<T>::operator=(const Vector& v) // ������������� �������� ������������ � ������������
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