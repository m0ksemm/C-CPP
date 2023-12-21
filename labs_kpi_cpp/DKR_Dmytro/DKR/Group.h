#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include "Student.h"
#include "Teacher.h"
#include <vector>

class Group  // ���� ��������� �����. ̳����� � ��� ����� �������� �� ���������,
{            // � ����� �� �������� ������ ��� ������ � ������ 
private:
	vector<Person*> Students;  // ���������� ������, ���� ������ ��������� �� ����������� ������� ���� Person (��������, � �� �� ������ �� ����� �����)
	Person* teacher;  // ��������� �� ����������� ������� ���� Person
public:
	Group(); // ����������� �� ����������� 

	void PrintGroup(); // ����� ��� ��������� ����� �������� � ���������
	void AddStudent(); // ����� ��������� ������ �������� � ����� 
	void RemoveStudent(); // ����� ��������� �������� � ����� 
	void SearchStudent(); // ����� ������ �������� � ����. ����� ���������� �� �������� ������������ �������  

	void ChangeTeacher(); // ����� ��� ���� ���������� ��� ��������� �����

	void SaveData(); // ����� ��� ���������� ��� ����� � ���� 
	void LoadData(); // ����� ��� ������������ ��� ����� � �����
};

