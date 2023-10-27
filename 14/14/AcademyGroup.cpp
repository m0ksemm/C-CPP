#include "AcademyGroup.h"
#include <iostream>
#include "Student.h"
#include "Person.h"
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

AcademyGroup::AcademyGroup()
{
	pSt = nullptr;
	count = 0;
}

AcademyGroup::AcademyGroup(const AcademyGroup& obj)
{
	this->count = obj.count;
	this->pSt = new Student*[this->count];

	for (int i = 0; i < count; i++)
	{
		pSt[i] = new Student;
	}

	for (int i = 0; i < this->count; i++)
	{
		this->pSt[i]->setName(obj.pSt[i]->getName());
		this->pSt[i]->setSurname(obj.pSt[i]->getSurname());
		this->pSt[i]->setAge(obj.pSt[i]->getAge());
		this->pSt[i]->setPhone(obj.pSt[i]->getPhone());
		this->pSt[i]->setRating(obj.pSt[i]->getRating());
	}
}

AcademyGroup::AcademyGroup(AcademyGroup&& obj)
{
	this->count = obj.count;
	this->pSt = obj.pSt;

	obj.pSt = nullptr;
	obj.count = 0;
}

AcademyGroup::~AcademyGroup()
{
	for (int i = 0; i < count; i++)
	{
		delete this->pSt[i];
	}

	delete[] pSt;
	pSt = nullptr;
}

void AcademyGroup::AddStudents()
{
	system("cls");
	int number;
	cout << "How many students do you want to add? ";
	cin >> number;
	cin.ignore();
	if (number <= 0)
		return;

	Student** temp = new Student * [count + number];

	//count += number;

	for (int i = 0; i < count; i++)
	{
		temp[i] = new Student(*pSt[i]);
		
	}
		
	for (int j = 0; j < 35; j++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < number; i++)
	{
		Student newst;
		cin >> newst;
		for (int j = 0; j < 35; j++)
			cout << "-";
		cout << endl;
		temp[count++] = new Student(move(newst));
	}
	//delete[] this->pSt;
	pSt = temp;
		
	
}

void AcademyGroup::Print()
{
	system("cls");
	for (int i = 0; i < 35; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < this->count; i++)
	{
		pSt[i]->Print();
		for (int j = 0; j < 35; j++)
			cout << "-";
		cout << endl;
	}
	_getch();

}

void AcademyGroup::DeleteStudent()
{
	system("cls");
	char name_[20], surname_[30];
	cout << "Enter the name of student: ";
	cin >> name_;
	cout << "Enter the surname of student: ";
	cin >> surname_;

	for (int i = 0; i < count; i++)
	{
		if (! (strcmp(name_, pSt[i]->getName()) || strcmp(surname_, pSt[i]->getSurname())))
		{
			delete pSt[i];
			for (int j = i; j < count - 1; j++)
				pSt[j] = pSt[j + 1];
			pSt[--count] = nullptr;
			cout << "Student is deleted!";
			_getch();
			return;
		}
	}

	cout << "Student is not found!";
	_getch();
}

void AcademyGroup::EditStudent()
{
	system("cls");
	char name_[20], surname_[30];
	cout << "Enter the student's name: ";
	cin >> name_;
	cout << "Enter the student's surname: ";
	cin >> surname_;

	for (int i = 0; i < count; i++)
	{
		if (!(strcmp(name_, pSt[i]->getName()) || strcmp(surname_, pSt[i]->getSurname())))
		{
			cout << "Enter new information\n";
			char nm[30], snm[30], ph[14];
			int ag;
			double rt;

			cout << "Name:    ";
			cin >> nm;
			cout << "Surname: ";
			cin >> snm;
			cout << "Age:     ";
			cin >> ag;
			cout << "Phone:   ";
			cin >> ph;
			cout << "Rating:  ";
			cin >> rt;
			pSt[i]->setName(nm);
			pSt[i]->setSurname(snm);
			pSt[i]->setAge(ag);
			pSt[i]->setPhone(ph);
			pSt[i]->setRating(rt);

			cout << "Information about student is changed!";
			_getch();
			return;
		}
	}

	cout << "Student is not found!";
	_getch();
}

void AcademyGroup::FindStudent()
{
	system("cls");

	int key_;
	cout << "Enter the criteria for searching: \n";
	cout << "------------\n";
	cout << "|1. Name   |\n";
	cout << "|2. Surname|\n";
	cout << "|3. Age    |\n";
	cout << "|4. Phone  |\n";
	cout << "|5. Rating |\n";
	cout << "------------\n";
	cin >> key_;
	int res_flag = 0;

	if (key_ == 1)
	{
		char key[30];
		cout << "Enter the name: ";
		cin >> key;

		for (int i = 0; i < count; i++)
		{
			if (strstr(pSt[i]->getName(), key) != nullptr)
			{
				res_flag = 1;
				for (int j = 0; j < 35; j++)
					cout << "-";
				cout << endl;
				pSt[i]->Print();
			}

		}
		for (int j = 0; j < 35; j++)
			cout << "-";
		cout << endl;
	}
	else if (key_ == 2)
	{
		char surname_[30];
		cout << "Enter the surname: ";
		cin >> surname_;

		for (int i = 0; i < count; i++)
		{
			if (strstr(pSt[i]->getSurname(), surname_) != nullptr)
			{
				res_flag = 1;
				for (int j = 0; j < 35; j++)
					cout << "-";
				cout << endl;
				pSt[i]->Print();
			}

		}
		for (int j = 0; j < 35; j++)
			cout << "-";
		cout << endl;
	}
	else if (key_ == 3)
	{
		int age_;
		cout << "Enter the age: ";
		cin >> age_;

		for (int i = 0; i < count; i++)
		{
			if (pSt[i]->getAge() == age_)
			{
				res_flag = 1;
				for (int j = 0; j < 35; j++)
					cout << "-";
				cout << endl;
				pSt[i]->Print();
			}

		}
		for (int j = 0; j < 35; j++)
			cout << "-";
		cout << endl;
	}
	else if (key_ == 4)
	{
		char phone_[30];
		cout << "Enter the phone: ";
		cin >> phone_;

		for (int i = 0; i < count; i++)
		{
			if (strstr(pSt[i]->getPhone(), phone_) != nullptr)
			{
				res_flag = 1;
				for (int j = 0; j < 35; j++)
					cout << "-";
				cout << endl;
				pSt[i]->Print();
			}

		}
		for (int j = 0; j < 35; j++)
			cout << "-";
		cout << endl;
	}
	else if (key_ == 5)
	{
		double rating_;
		cout << "Enter the rating: ";
		cin >> rating_;

		for (int i = 0; i < count; i++)
		{
			if (pSt[i]->getRating() ==  rating_)
			{
				res_flag = 1;
				for (int j = 0; j < 35; j++)
					cout << "-";
				cout << endl;
				pSt[i]->Print();
			}

		}
		for (int j = 0; j < 35; j++)
			cout << "-";
		cout << endl;
	}

	if (res_flag == 0)
		cout << "Student is not found ";
	_getch();
}

void AcademyGroup::Sort()
{
	system("cls");

	int key;
	cout << "Enter the criteria for sorting: \n";
	cout << "------------\n";
	cout << "|1. Name   |\n";
	cout << "|2. Surname|\n";
	cout << "|3. Age    |\n";
	cout << "|4. Rating |\n";
	cout << "------------\n";
	cin >> key;
	if (key == 1)
	{
		for (int i = 0; i < count; i++)
		{
			for (int j = count - 1; j > i; j--)
			{
				if (strcmp(pSt[j - 1]->getName(), pSt[j]->getName()) > 0)
				{
					Student* tmpptr = pSt[j - 1];
					pSt[j - 1] = pSt[j];
					pSt[j] = tmpptr;
				}
			}
		}
		cout << "Sorted!";
		_getch();
		return;
	}
	else if (key == 2)
	{
		for (int i = 0; i < count; i++)
		{
			for (int j = count - 1; j > i; j--)
			{
				if (strcmp(pSt[j - 1]->getSurname(), pSt[j]->getSurname()) > 0)
				{
					Student* tmpptr = pSt[j - 1];
					pSt[j - 1] = pSt[j];
					pSt[j] = tmpptr;
				}
			}
		}
		cout << "Sorted!";
		_getch();
		return;
	}
	else if (key == 3)
	{
		for (int i = 0; i < count; i++)
		{
			for (int j = count - 1; j > i; j--)
			{
				if ((pSt[j - 1]->getAge() < pSt[j]->getAge()) )
				{
					Student* tmpptr = pSt[j - 1];
					pSt[j - 1] = pSt[j];
					pSt[j] = tmpptr;
				}
			}
		}
		cout << "Sorted!";
		_getch();
		return;
	}
	else if (key == 4)
	{
		for (int i = 0; i < count; i++)
		{
			for (int j = count - 1; j > i; j--)
			{
				if (pSt[j - 1]->getRating() < pSt[j]->getRating())
				{
					Student* tmpptr = pSt[j - 1];
					pSt[j - 1] = pSt[j];
					pSt[j] = tmpptr;
				}
			}
		}
		cout << "Sorted!";
		_getch();
		return;
	}
	cout << "\nWrong Key!";
}

void AcademyGroup::Save()
{
	FILE* AcGr = nullptr;
	//cin.ignore();
	fopen_s(&AcGr, "AcademyGroup.txt", "wb");
	if (AcGr == nullptr)
	{
		perror("Error opening");
		system("pause");

		cout << "ERROR";
	}
	else
	{
		fwrite(&count, sizeof(int), 1, AcGr);

		for (int i = 0; i < count; i++)
		{
			int len = strlen(pSt[i]->getName()) + 1;
			fwrite(&len, sizeof(int), 1, AcGr);
			const char* buf = new char[strlen(pSt[i]->getName())];
			buf = pSt[i]->getName();
			fwrite(buf, sizeof(char), len, AcGr);

			len = strlen(pSt[i]->getSurname()) + 1;
			fwrite(&len, sizeof(int), 1, AcGr);
			buf = new char[strlen(pSt[i]->getSurname())];
			buf = pSt[i]->getSurname();
			fwrite(buf, sizeof(char), len, AcGr);

			int age = pSt[i]->getAge();
			fwrite(&age, sizeof(int), 1, AcGr);

			const char* buf2 = new char[15];
			buf2 = pSt[i]->getPhone();
			fwrite(buf2, sizeof(char), 15, AcGr);

			double avg = pSt[i]->getRating();
			fwrite(&avg, sizeof(double), 1, AcGr);
		}
	}
	fclose(AcGr);
	system("cls");
	cout << "\nSaved!";
	_getch();

}

void AcademyGroup::Load()
{
	FILE* AcGr = nullptr;
	//cin.ignore();
	fopen_s(&AcGr, "AcademyGroup.txt", "rb");
	if (AcGr == nullptr)
	{
		perror("Error opening");
		system("pause");

		cout << "ERROR";
	}
	else
	{
		fread(&count, sizeof(int), 1, AcGr);

		//cout << count;

		pSt = new Student * [count];

		for (int i = 0; i < count; i++)
		{
			pSt[i] = new Student;
		}

		for (int i = 0; i < count; i++)
		{
			int len;
			fread(&len, sizeof(int), 1, AcGr);
			char* name = new char[len];
			fread(name, sizeof(char), len, AcGr);
			pSt[i]->setName(name);

			fread(&len, sizeof(int), 1, AcGr);
			char* surname = new char[len];
			fread(surname, sizeof(char), len, AcGr);
			pSt[i]->setSurname(surname);

			int age;
			fread(&age, sizeof(int), 1, AcGr);
			pSt[i]->setAge(age);

			char* phone = new char[15];
			fread(phone, sizeof(char), 15, AcGr);
			pSt[i]->setPhone(phone);

			double avg;
			fread(&avg, sizeof(double), 1, AcGr);
			pSt[i]->setRating(avg);
		}
	}
	fclose(AcGr);

	system("cls");
	cout << "\Loaded!";
	_getch();
}

AcademyGroup& AcademyGroup::operator=(const AcademyGroup& obj)
{
	if (this == &obj)
		return *this;
	cout << "+";
	delete this->pSt;
	
	this->pSt = new Student* ;
	*pSt = *obj.pSt;
	
	return *this;
}

AcademyGroup& AcademyGroup::operator=(AcademyGroup&& obj)
{
	if (this == &obj)
		return *this;
	delete this->pSt;
	pSt = obj.pSt;
	obj.pSt = nullptr;

	return *this;
}

Student& AcademyGroup::operator[](int index)
{
	int i = 0;
	while (i < index)
	{ 
		i++;
	}
	return *pSt[i];
}
