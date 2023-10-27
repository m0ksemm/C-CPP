#include <iostream>
#include "Student.h"
#include "Person.h"

using namespace std;

#pragma once
class AcademyGroup
{
	Student** pSt;
	int count;
public:
	AcademyGroup();
	AcademyGroup(const AcademyGroup& obj);
	AcademyGroup(AcademyGroup&& obj);
	~AcademyGroup();
	void AddStudents();
	void DeleteStudent();
	void EditStudent();
	void Print();
	void FindStudent();
	void Sort();
	void Save();
	void Load();
	AcademyGroup& operator=(const AcademyGroup& obj);
	AcademyGroup& operator=(AcademyGroup&& obj);
	Student& operator[](int index);
	friend std::ostream& operator<<(std::ostream& os, AcademyGroup& obj);


};
