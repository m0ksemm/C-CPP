#include "Vector.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

Vector::Vector() : Vector{ nullptr, 0 } {}


Vector::Vector(int n)
{
	srand(time(0));
	size = n;
	int* vect = new int[size];
	//vect = ptr;
	for (int i = 0; i < size; i++)
	{
		*(vect + i) = rand() % (41) - 20;
	}
	this->vect = vect;
}

Vector::Vector(const int* ptr, int size)//  онструктор, позвол€ющий проинициализировать вектор с помощью существующего массива
{
	this->size = size;
	int* vect = new int[size];
	for (int i = 0; i < size; i++) 
	{
		*(vect + i) = *(ptr + i);
	}
	this->vect = vect;
}

Vector::Vector(const Vector& v) 
{
	size = v.size;
	int* vect = new int[size];
	//vect = ptrv;
	for (int i = 0; i < size; i++)
	{
		*(vect + i) = *(v.vect + i);
	}
	this->vect = vect;
}

Vector::~Vector() 
{
	//~Vector();
	delete[]vect;
}

int Vector::GetSize() const
{
	return size;
}

void Vector::Print()
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << *(vect + i);
	cout << endl;
}

void Vector::Input()
{
	cout << "\n Enter " << size << " elements of the vector:\n";
	for (int i = 0; i < size; i++) 
	{
		cin >> *(vect + i);
	}
}

void Vector::Clear()
{
	this->size = 0;
	this->vect = nullptr;
}

bool Vector::IsEmpty() const 
{
	if (vect == nullptr)
		return true;
	else return false;
}

void Vector::Add(const int& item) 
{
	int* ptr = new int[++size];
	for (int i = 0; i < size - 1; i++)
	{
		*(ptr + i) = *(vect + i);
	}
	*(ptr + size - 1) = item;
	delete[]vect;
	vect = ptr;
}

void Vector::Insert(int index, const int& item) 
{
	if (index < 0 || index > size /*- 1*/)
		return;
	int* p = new int[size + 1];
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

void Vector::Remove(int index)
{
	if (index < 0 || index > size - 1)
		return;
	int* p = new int[-- size];
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


