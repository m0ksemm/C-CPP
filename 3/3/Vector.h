#pragma once
#include <iostream>
#include "Vector.h"
#include <iomanip>


class Vector
{
	int* vect; // ������
	int size; // ����������� �������
public:
	Vector(); // ����������� �� ���������
	Vector(int size); // �����������, ����������� �������� ����������� �������
	Vector(const int* ptr, int size); // �����������, ����������� ������������������� ������ 
	// � ������� ������������� �������
	Vector(const Vector& v); // ����������� �����������
	~Vector(); // ����������
	int GetSize() const; // ������� ���������� ����������� �������
	void Print(); // ����� �� �����
	void Input(); // ���������� �������
	void Clear(); // ������� �������
	bool IsEmpty() const; // ���������� ������, ���� ������ ������
	void Add(const int& item); // ���������� �������� � ������
	void Insert(int index, const int& item); // ������� ��������� � ������ �� ��������� �������
	void Remove(int index); // �������� �������� �� ������� �� ��������� �������
};