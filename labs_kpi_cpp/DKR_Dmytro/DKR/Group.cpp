#include "Group.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

Group::Group() 
{

}
void Group::AddStudent()  // ����� ��������� ������ �������� � ����� 
{
	string name;    // �������� ���������� ������� �� ���� ��� ������ �������� 
	string surname;
	int age;
	string gender;
	double avg;
	cout << "Input name:          - ";
	cin >> name;
	cout << "Input surname:       - ";
	cin >> surname;
	cout << "Input age:           - ";
	cin >> age;
	cout << "Input gender:        - ";
	cin >> gender;
	cout << "Input average grade: - ";
	cin >> avg;

	Student st(name, surname, age, gender, avg); // ����������� ��'��� ����� Student
	Person* p = (Person*) new Student(st); // ������� �������� �� ������� 

	Students.push_back(p);
}
void Group::RemoveStudent() // ����� ��������� �������� � ����� 
{
	int i; 
	cout << "Input number of student that you want to remove:  ";
	cin >> i; // ���������� �� ������ ����� ��������, ����� �� ���� ��������. 
		      // ������ �������� ������������� �� ��� ��������� ����� � ������� 
	if (i < 1 || i > Students.size() || i == 0)
	{ // ���� ���������� ��� ����������� ����� ��������, �������� ��������� ��� �� 
		cout << endl << "Number is wrong" << endl;
		system("pause");
	}
	else {
		Students.erase(Students.begin() + i - 1);
	}
	cout << endl << "Student was removed from group." << endl;
}
void Group::SearchStudent()  // ����� ������ �������� � ����. ����� ���������� �� �������� ������������ ������� 
{
	int choice; // ������� ����� �� ���� ������ ���� ����������� ����� 
	cout << "What is the creteria of search?" << endl;
	cout << "1 - Name" << endl;
	cout << "2 - Age" << endl;
	cout << "3 - Gender" << endl;
	cout << "4 - Average grade" << endl;

	cin >> choice;

	if (choice == 1) // ����� �� ������
	{
		string name;
		cout << "Input name:  ";
		cin >> name;
		for (int i = 0; i < Students.size(); i++) {
			if (((Student*)Students[i])->GetName() == name)
			{
				cout << " ---- " << endl;
				cout << "| " << i + 1 << " |" << endl;
				cout << " ---- " << endl;
				((Student*)Students[i])->GetInfo();
			}
		}
	}
	if (choice == 2) // ����� �� ����
	{
		int age;
		cout << "Input age:  ";
		cin >> age;
		for (int i = 0; i < Students.size(); i++) {
			if (((Student*)Students[i])->GetAge() == age)
			{
				cout << " ---- " << endl;
				cout << "| " << i + 1 << " |" << endl;
				cout << " ---- " << endl;
				((Student*)Students[i])->GetInfo();
			}
		}
	}
	if (choice == 3) // ����� �� ������
	{
		string gender;
		cout << "Input gender:  ";
		cin >> gender;
		for (int i = 0; i < Students.size(); i++) {
			if (((Student*)Students[i])->GetGender() == gender) 
			{
				cout << " ---- " << endl;
				cout << "| " << i + 1 << " |" << endl;
				cout << " ---- " << endl;
				((Student*)Students[i])->GetInfo();
			}
		}
	}
	if (choice == 4) // ����� �� ������� �����
	{
		double avg;
		cout << "Input average grade:  ";
		cin >> avg;
		for (int i = 0; i < Students.size(); i++) {
			if (((Student*)Students[i])->GetAvg() == avg) 
			{
				cout << " ---- " << endl;
				cout << "| " << i + 1 << " |" << endl;
				cout << " ---- " << endl;
				((Student*)Students[i])->GetInfo();
			}
		}
	}
}
void Group::PrintGroup() // ����� ��� ��������� ����� �������� � ���������
{
	if (Students.size() != 0) {
		cout << "-----------" << endl;
		cout << "|Teacher:  |" << endl;
		cout << "-----------" << endl;

		((Teacher*)teacher)->GetInfo();

		cout << "-----------" << endl;
		cout << "|Students: |" << endl;
		cout << "-----------" << endl;
		for (int i = 0; i < Students.size(); i++) {
			cout << " ---- " << endl;
			cout << "| " << i + 1 << " |" << endl;
			cout << " ---- " << endl;

			((Student*)Students[i])->GetInfo();
		}
	}
	else cout << "Group is empty\n"; // ���� � ���� ���� ��������, �������� ��������� ��� �� 
}
void Group::ChangeTeacher()  // ����� ��� ���� ���������� ��� ��������� �����
{
	string name;
	string surname;
	int age;
	string gender;
	int exp;
	cout << "Input name:             - ";
	cin >> name;
	cout << "Input surname:          - ";
	cin >> surname;
	cout << "Input age:              - ";
	cin >> age;
	cout << "Input gender:           - ";
	cin >> gender;
	cout << "Input experience years: - ";
	cin >> exp;

	Teacher t(name, surname, age, gender, exp);
	teacher = (Person*) new Teacher(t);
}

void Group::SaveData() // ����� ��� ���������� ��� ����� � ���� 
{
	std::remove("group.txt");

	ofstream f("group.txt", ios::app); 
	f << Students.size();
	f << "\n";
	f.close();

	teacher->Save(); // �������� � ���� group.txt ���������� ���������� ��� �������. 
	for (int i = 0; i < Students.size(); i++)  // ���� �� ���� ���������� ���������� ��� ������� �������� 
	{
		(Students[i])->Save();
	}
	cout << endl << "Data was saved." << endl; 
}
void Group::LoadData() // ����� ��� ������������ ��� ����� � �����
{
	string name;
	string surname;
	int age;
	string gender;
	double avg;
	int exp;
	int count;
	ifstream f1("group.txt");
	f1 >> count;

	f1 >> name;   // �������� � ����� ������������� ���������� ��� ������� 
	f1 >> surname;
	f1 >> age;
	f1 >> gender;
	f1 >> exp;

	Teacher t(name, surname, age, gender, exp); // ����������� ���� Teacher
	teacher = (Person*) new Teacher(t);         // �� �������� � ������ 

	for (int i = 0; i < count; i++) // ���� ������������� ���������� ��� �������� 
	{
		f1 >> name;
		f1 >> surname;
		f1 >> age;
		f1 >> gender;
		f1 >> avg;

		Student st(name, surname, age, gender, avg); // �� ��� ��������� � ����� ����� ����������� 
		Person* p = (Person*) new Student(st);       // ��'��� ����� Student, ���� �� �������� � ������ 

		Students.push_back(p);
	}
	f1.close();

	cout << endl << "Data was loaded." << endl;
}