#define _CRT_SECURE_NO_WARNINGS

#include "Person.h"
#include <iostream>

using	 namespace std;

Person::Person()
{
	this->name = nullptr;
	this->surname = nullptr;
	this->age = 0;
}

Person::Person(const char* name, const char* surname, int age)
{
	int len = strlen(name);
	this->name = new char[len + 1];
	strcpy(this->name, name);

	len = strlen(surname);
	this->surname = new char[len + 1];
	strcpy(this->surname, surname);

	this->age = age;
}

Person::Person(const Person& obj)
{
	this->name = new char[strlen(obj.name) + 1];
	strcpy(this->name, obj.name);

	this->surname = new char[strlen(obj.surname) + 1];
	strcpy(this->surname, obj.surname);

	this->age = obj.age;
}

Person::Person(Person&& obj)
{
	this->name = obj.name;
	this->surname = obj.surname;
	this->age = obj.age;

	obj.name = nullptr;
	obj.surname = nullptr;
	obj.age = 0;
}

Person::~Person()
{
	delete[] name;
	delete[] surname;
}

const char* Person::getName()const
{
	return this->name;
}

const char* Person::getSurname()const
{
	return this->surname;
}

 int Person::getAge()const
 {
	 return this->age;
 }

 void Person::setName(const char* name)
 {
	 delete[] this->name;
	 this->name = new char[strlen(name) + 1];
	 strcpy(this->name, name);
 }

 void Person::setSurname(const char* surname)
 {
	 delete[] this->surname;
	 this->surname = new char[strlen(surname) + 1];
	 strcpy(this->surname, surname);
 }

 void Person::setAge(int age)
 {
	 this->age = age;
 }

 void Person::Print()const
 {
	 cout << "Name:    | " << name << endl;
	 cout << "Surname: | " << surname << endl;
	 cout << "Age:     | " << age << endl;
 }

 Person& Person::operator=(const Person& obj)
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
	 
	 return *this;
 }

 Person& Person::operator=(Person&& obj)
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

	 obj.age = 0;
	 obj.name = nullptr;
	 obj.surname = nullptr;

	 return *this;
 }
