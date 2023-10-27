#define _CRT_SECURE_NO_WARNINGS

#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
	//char str_name[6] = "Dwane";
	//this->name = new char[6];
	this->name = nullptr;
	/*for (int i = 0; i < 6; i++) 
	{
		this->name[i] = str_name[i];
	}*/


	this->surname = nullptr;
	/*char str_surname[] = "Jonson";
	
	this->surname = new char[7];
	for (int i = 0; i < 7; i++)
	{
		this->surname[i] = str_surname[i];
	}*/

	this->age = 0;

	//char str[15] = "+3809952607213";

	/*for (int i = 0; i < 14; i++) 
	{
		this->phone[i] = str[i];
	}*/

	//this->phone = 0;
	this->setPhone("0");

	this->average = 0;
}

Student::Student(const Student& st)
{
	
	this->name = new char[strlen(st.name) + 1];
	strcpy(name, st.name);

	this->surname = new char[strlen(st.surname) + 1];
	strcpy(surname, st.surname);
		
	this->age = st.age;
	
	strcpy(phone, st.phone);
	
	this->average = st.average;
}

Student::Student(const char* str_name, const char* str_surname, int st_age, const char* st_phone, double st_avg)
	/*: name{ new char[strlen(str_name)] }, surname{ new char[strlen(str_surname)] }, age{ age }, phone{ st_phone }*/
{
	int len = strlen(str_name);
	this->name = new char[len + 1];
	strcpy(name, str_name);

	len = strlen(str_surname);
	this->surname = new char[len + 1];
	strcpy(surname, str_surname);

	this->age = st_age;
	strcpy(phone, st_phone);

	this->average = st_avg;
}

Student::~Student() 
{
	delete[] name;
	delete[] surname;
}

int Student::getAge()const
{
	return age;
}

double Student::getAverage()const 
{
	return average;
}

const char* Student::getPhone()const 
{
	return phone;
}

char* Student::getName()const 
{
	return name;
}

char* Student::getSurname()const
{
	return surname;
}

void Student::setAge(int age_) 
{
	this->age = age_;
}

void Student::setAverage(double avg) 
{
	this->average = avg;
}

void Student::setName(const char* name_) 
{
	delete[] name;
	this->name = new char[strlen(name_) + 1];
	strcpy(this->name, name_);
}


void Student::setSurname(const char* surname_)
{
	delete[] surname;
	this->surname = new char[strlen(surname_) + 1];
	strcpy(this->surname, surname_);
}

void Student::setPhone(const char* ph)
{
	strcpy(phone,  ph);
}

void Student::Print() 
{
	cout << "Name:    | " << name <<endl;
	cout << "Surname: | " << surname << endl;
	cout << "Age:     | " << age << endl;
	cout << "Phone:   | " << phone <<endl;
	cout << "Average: | " << average << endl;
	
}

