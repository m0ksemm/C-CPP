#include "matrix.h"
#include <iostream>
#include "cstdlib"
#include "ctime"
#include <iomanip>

using namespace std;

matrix::matrix() // ����������� �� ���������
{
	row = 3;
	col = 3;
	p = new int*[row];
	for (int i = 0; i < row; i++) 
	{
		p[i] = new int[col];
		*(p + i) = 0;
	}
}

matrix::matrix(int r, int c) // ����������� � �����������
{
	row = r;
	col = c;
	//srand(time(0));
	p = new int* [row];
	for (int i = 0; i < row; i++)
		p[i] = new int[col];

	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++) 
		{
			p[i][j] = rand() % (41) - 20;
		}	
	}
}

matrix::matrix(const matrix& obj) // ����������� �����������
{
	this->row = obj.row;
	this->col = obj.col;

	this->p = new int*[this->row];
	for (int i = 0; i < this->row; i++)
		this->p[i] = new int[this->col];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			this->p[i][j] = obj.p[i][j];
		}
	}
}

matrix::matrix(matrix&& m) // ����������� ��������
{
	this->p = m.p;
	this->row = m.row;
	this->col = m.col;

	m.p = nullptr;

	m.row = 0;
	m.col = 0;
}

matrix::~matrix() // ����������
{
	for (int i = 0; i < row; i++) 
	{
		delete[] p[i];
	}
	delete[] p;
	p = nullptr;
}

matrix& matrix::operator=(const matrix& m) // ������������� �������� ������������ � ������������ 
{
	if (this == &m)
		return *this;
	delete p;
	p = new int*;
	*p = *m.p;
	/*cout << "\noperator= copy: " << *p << endl;
	cout << "Data address: " << p << endl;*/
	return *this;
}

matrix& matrix::operator = (matrix&& m) // ������������� �������� ������������ � ��������� ���������� �� 1 ������� �������� ������� 
{
	if (this == &m)
		return *this;
	delete p;
	p = m.p;
	m.p = nullptr;
	/*cout << "\noperator= move: " << *p << endl;
	cout << "Data address: " << p << endl;*/
	return *this;
}

matrix& matrix::operator ++() // ���������� ���������
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			this->p[i][j]++;
	return *this;
}

matrix matrix::operator ++(int) // ����������� ���������
{
	matrix tmp = *this;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			this->p[i][j]++;
	return tmp;
}

matrix& matrix::operator --() // ���������� ���������
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			this->p[i][j]--;
	return *this;
}

matrix matrix::operator --(int) // ����������� ���������
{
	matrix tmp = *this;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			this->p[i][j]--;
	return tmp;
}

matrix matrix::operator+(const matrix& m) const  // �������� ������
{
	matrix mres(m.row, m.col);

	for (int i = 0; i < m.row; i++) 
	{
		for (int j = 0; j < m.col; j++)
		{
			mres.p[i][j] = this->p[i][j] + m.p[i][j];
		}
	}

	return mres;
}

matrix matrix::operator*(const matrix& m) const  // �������� ������
{
	if (this->row < m.row || this->col > m.col)
		return *this;

	matrix mres(this->row, m.col);

	for (int i = 0; i < this->row; i++) 
	{
		for (int j = 0; j < m.col; j++) 
		{
			mres.p[i][j] = 0;
		}
	}

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			for (int k = 0; k < col; k++) 
			{
				mres.p[i][j] += this->p[i][k] * m.p[k][j];
			}
				
		}
	}


	return mres;
}


int& matrix::operator()(int i, int j) // ��������� / ��������� �������� �������� �������
{
	return this->p[i][j];
}

