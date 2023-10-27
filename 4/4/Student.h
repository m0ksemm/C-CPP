#pragma once

class Student
{
	char* name;
	char* surname;
	int age;
	char phone[15];
	double average;
public:
	Student();
	Student(const Student&);
	Student(const char*, const char*, int, const char*, double);
	~Student();
	int getAge()const;
	double getAverage()const;
	const char* getPhone()const;
	char* getName()const;
	char* getSurname()const;
	void setAge(int);
	void setAverage(double);
	void setName(const char*);
	void setSurname(const char*);
	void setPhone(const char*);
	void Print();
};
