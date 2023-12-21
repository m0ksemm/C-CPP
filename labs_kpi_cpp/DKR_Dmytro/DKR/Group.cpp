#include "Group.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

Group::Group() 
{

}
void Group::AddStudent()  // Метод додавання нового студенту в групу 
{
	string name;    // Спочатку користувач вводить всі данні про нового студента 
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

	Student st(name, surname, age, gender, avg); // Створюється об'єкт класу Student
	Person* p = (Person*) new Student(st); // Студент додається до вектору 

	Students.push_back(p);
}
void Group::RemoveStudent() // Метод видалення студенту з групи 
{
	int i; 
	cout << "Input number of student that you want to remove:  ";
	cin >> i; // Користувач має обрати номер студента, якого він хоче видалити. 
		      // Номери студентів відображаються під час виведення групи в консоль 
	if (i < 1 || i > Students.size() || i == 0)
	{ // Якщо користувач ввів некоректний номер студента, програма повідомить про це 
		cout << endl << "Number is wrong" << endl;
		system("pause");
	}
	else {
		Students.erase(Students.begin() + i - 1);
	}
	cout << endl << "Student was removed from group." << endl;
}
void Group::SearchStudent()  // Метод пошуку студенту в групі. Пошук відбувається за вибраним користувачем критерієм 
{
	int choice; // Студент обирає за яким полему буде проводитись пошук 
	cout << "What is the creteria of search?" << endl;
	cout << "1 - Name" << endl;
	cout << "2 - Age" << endl;
	cout << "3 - Gender" << endl;
	cout << "4 - Average grade" << endl;

	cin >> choice;

	if (choice == 1) // Пошук за іменем
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
	if (choice == 2) // Пошук за віком
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
	if (choice == 3) // Пошук за статтю
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
	if (choice == 4) // Пошук за середнім балом
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
void Group::PrintGroup() // Метод для виведення групи студнетів і викладача
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
	else cout << "Group is empty\n"; // Якщо в групі нема студентів, програма повідомить про це 
}
void Group::ChangeTeacher()  // Метод для зміни інформації про викладача групи
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

void Group::SaveData() // Метод для збереження всіх даних в файл 
{
	std::remove("group.txt");

	ofstream f("group.txt", ios::app); 
	f << Students.size();
	f << "\n";
	f.close();

	teacher->Save(); // Спочатку в файл group.txt зберігається інформація про вчителя. 
	for (int i = 0; i < Students.size(); i++)  // Потім по черзі зберігається інформація про кожного студента 
	{
		(Students[i])->Save();
	}
	cout << endl << "Data was saved." << endl; 
}
void Group::LoadData() // Метод для завантаження всіх даних з файлу
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

	f1 >> name;   // Спочатку з файлу завантажується інформація про вчителя 
	f1 >> surname;
	f1 >> age;
	f1 >> gender;
	f1 >> exp;

	Teacher t(name, surname, age, gender, exp); // Створюється клас Teacher
	teacher = (Person*) new Teacher(t);         // та додається в вектор 

	for (int i = 0; i < count; i++) // Потім завантажуєтсья інформація про студентів 
	{
		f1 >> name;
		f1 >> surname;
		f1 >> age;
		f1 >> gender;
		f1 >> avg;

		Student st(name, surname, age, gender, avg); // На базі отриманих з файлу даних створюється 
		Person* p = (Person*) new Student(st);       // об'єкт класу Student, потім він додається в вектор 

		Students.push_back(p);
	}
	f1.close();

	cout << endl << "Data was loaded." << endl;
}