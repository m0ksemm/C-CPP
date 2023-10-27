#pragma once
#include <iostream>
#include "Vector.h"
#include <iomanip>

using namespace std;

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

	Vector& operator++(); // ���������� ���� ��������� ������� �� ������� (�������)
	Vector operator++(int k); // ���������� ���� ��������� ������� �� ������� (��������)
	Vector& operator--(); // ���������� ���� ��������� ������� �� ������� (�������)
	Vector operator--(int k); // ���������� ���� ��������� ������� �� ������� (��������)

	Vector& operator=(const Vector& v); // ������������� �������� ������������ � ������������

	int& operator[](int index); // ������������� �������� ������������ � ������������

	Vector operator+(const Vector& v); // �������� ���� ��������
	Vector operator-(const Vector& v); // ��������� ���� ��������
	Vector operator*(const Vector& v); // ��������� ���� ��������

	Vector operator+(int n);// �������� ������� � ������ (������ ��������� ������� ������������ � ������)
	Vector operator-(int n);//  ��������� ����� �� �������
	Vector operator*(int n); // ��������� ������� �� �����

	Vector& operator *= (const Vector& v); // ������������� �������� *= ��� ��������� ������� �� �����
	Vector& operator -= (const Vector& v); // ������������� �������� -= ��� ��������� ���� ��������
	Vector& operator += (const Vector& v); // ������������� �������� += ��� �������� ���� ��������

	friend istream& operator>>(istream& cin, Vector& v); // ���� ������� � ����������
	friend ostream& operator<<(ostream& cout, Vector& v);// ����� ������� �� �����

};