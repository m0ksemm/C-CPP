#define _CRT_SECURE_NO_WARNINGS

#include "Student.h"
#include "Person.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>

using namespace std;

Student::Student()
{
	for(int i = 0; i < 14; i++)
		this->phone[i] = '0';
	rating = 0;
}

Student::Student(const char* name, const char* surname, int age, const char* phone, double rating)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);

	len = strlen(surname);
	this->surname = new char[len + 1];
	strcpy(this->surname, surname);

	this->age = age;

	strcpy(this->phone, phone);

	this->rating = rating;
}

Student::Student(const Student& obj)
{
	int len = strlen(obj.name);
	this->name = new char[len + 1];
	strcpy(this->name, obj.name);

	len = strlen(obj.surname);
	this->surname = new char[len + 1];
	strcpy(this->surname, obj.surname);

	this->age = obj.age;

	strcpy(this->phone, obj.phone);

	/*for (int i = 0; i < 14; i++)
		this->phone[i] = obj.phone[i];*/

	this->rating = obj.rating;
}

Student::Student(Student&& obj) 
{
	this->name = obj.name;
	this->surname = obj.surname;
	this->age = obj.age;
	strcpy(this->phone, obj.phone);
	this->rating = obj.rating;

	obj.name = nullptr;
	obj.surname = nullptr;
	obj.age = 0;
	obj.rating = 0;
}

double Student::getRating() const
{
	return this->rating;
}

const char* Student::getPhone() const
{
	return this->phone;
}

void Student::setPhone(const char* phone)
{
	strcpy(this->phone, phone);
}

void Student::setRating(double average)
{
	this->rating = average;
}

void Student::Print() const
{
	cout << "Name:    | " << name << endl;
	cout << "Surname: | " << surname << endl;
	cout << "Age:     | " << age << endl;
	cout << "Phone:   | " << phone << endl;
	cout << "Rating:  | " << rating << endl;

}

Student& Student::operator=(const Student& obj)
{
	if (this == &obj)
		return *this;
	delete name;
	name = new char;
	*name = *obj.name;

	delete surname;
	surname = new char;
	*surname = *obj.surname;

	age = obj.age;

	*phone = *obj.phone;

	rating = obj.rating;

	return *this;

}

Student& Student::operator=(Student&& obj)
{
	if (this == &obj)
		return *this;
	delete name;
	name = new char;
	name = obj.name;

	delete surname;
	surname = new char;
	surname = obj.surname;

	age = obj.age;

	this->setPhone(obj.phone);

	rating = rating;

	obj.age = 0;
	obj.name = nullptr;
	obj.surname = nullptr;
	obj.setPhone("0000000");
	obj.rating = 0;

	return *this;
}