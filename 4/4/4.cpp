// 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Student.h"
#include <Windows.h>
#include <stdio.h>
#include <iomanip>

using namespace std;

void InputStudent(Student& st)
{
    char name[100], surname[100], phone[100];
    int age;
    float avg;

    cout << "Name:    | ";
    cin.getline(name, 100);

    cout << "Surname: | ";
    cin.getline(surname, 100);

    cout << "Age:     | ";

    cin >> age;
    cin.ignore();

    cout << "Phone:   | ";
    cin.getline(phone, 100);


    cout << "Average: | ";
    cin >> avg;
    cin.ignore();

    Student st2(name, surname, age, phone, avg);
}

void PrintStudent(const Student& st)
{
    cout << "Information about " << st.getName() << ": " << endl;
    for (int i = 0; i < 41; i++)
        cout << "-";
    cout << endl;

    cout << "| Name:          | " << setw(20) << st.getName() << " |" << endl;
    cout << "| Last name:     | " << setw(20) << st.getSurname() << " |" << endl;
    cout << "| Age:           | " << setw(20) << st.getAge() << " |" << endl;
    cout << "| Phone number:  | " << setw(20) << st.getPhone() << " |" << endl;
    cout << "| Average grade: | " << setw(20) << st.getAverage() << " |" << endl;

    for (int i = 0; i < 41; i++)
        cout << "-";
}


void SaveStudent(const Student& st)
{

    FILE* f1 = nullptr;
    cin.ignore();
    fopen_s(&f1, "students.txt", "wb");
    if (f1 == nullptr)
    {
        perror("Error opening");
        system("pause");

        cout << "ERROR";
    }
    else
    {
        int len = strlen(st.getName()) + 1;
        fwrite(&len, sizeof(int), 1, f1);
        char* buf = new char[strlen(st.getName())];
        buf = st.getName();
        fwrite(buf, sizeof(char), len, f1);

        len = strlen(st.getSurname()) + 1;
        fwrite(&len, sizeof(int), 1, f1);
        buf = new char[strlen(st.getSurname())];
        buf = st.getSurname();
        fwrite(buf, sizeof(char), len, f1);

        int age = st.getAge();
        fwrite(&age, sizeof(int), 1, f1);

        const char* buf2 = new char[15];
        buf2 = st.getPhone();
        fwrite(buf2, sizeof(char), 15, f1);

        double avg = st.getAverage();
        fwrite(&avg, sizeof(double), 1, f1);
    }
    fclose(f1);

}

void LoadStudent(Student& st)
{
    FILE* f1 = nullptr;
    cin.ignore();
    fopen_s(&f1, "students.txt", "rb");
    if (f1 == nullptr)
    {
        perror("Error opening");
        system("pause");

        cout << "ERROR";
    }
    else
    {
        int len;
        fread(&len, sizeof(int), 1, f1);
        char* name = new char[len];
        fread(name, sizeof(char), len, f1);
        st.setName(name);

        fread(&len, sizeof(int), 1, f1);
        char* surname = new char[len];
        fread(surname, sizeof(char), len, f1);
        st.setSurname(surname);

        int age;
        fread(&age, sizeof(int), 1, f1);
        st.setAge(age);

        char* phone = new char[15];
        fread(phone, sizeof(char), 15, f1);
        st.setPhone(phone);

        double avg;
        fread(&avg, sizeof(double), 1, f1);
        st.setAverage(avg);

    }
    fclose(f1);
}



int main()
{
    cout << "Test 1 (default constructor)\n";

    Student st1("11", "1", 10, "0000", 1.1);
    cout << "Student St1:\n\n";
    st1.Print();

    cout << "\n\nTest 2 (getters)" << endl;
    char* ptr0;
    ptr0 = st1.getName();

    char* ptr1;
    ptr1 = st1.getSurname();

    int age0 = st1.getAge();

    const char* ptr;
    ptr = st1.getPhone();

    float avg = st1.getAverage();

    cout << "\nName:    /" << ptr0;
    cout << "\nSurname: /" << ptr1;
    cout << "\nAge:     /" << age0;
    cout << "\nPhone:   /" << ptr;
    cout << "\nAverage: /" << avg;

    cout << "\n\n\nTest 3 (setters)" << endl;
    int age_;
    float avg_;
    char name[40], surname[50], telephone[200];

    cout << "Enter the name: ";
    cin.getline(name, 40);

    cout << "Enter the surname: ";
    cin.getline(surname, 200);

    cout << "Enter the age: ";
    cin >> age_;
    cin.ignore();

    cout << "Enter telephone number: ";
    cin.getline(telephone, 200);

    cout << "Enter the average: ";
    cin >> avg_;
    cin.ignore();

    st1.setName(name);
    st1.setSurname(surname);
    st1.setAge(age_);
    st1.setPhone(telephone);
    st1.setAverage(avg_);
    cout << endl << "All the setters are called; " << endl;
    st1.Print();

    cout << "\n\nTest 4 (constructor with parametres)\n";
    char n[100];
    cout << "Name:    ";
    cin.getline(n, 100);

    char s[100];
    cout << "Surname: ";
    cin.getline(s, 100);
    int y;
    cout << "Age:     ";

    cin >> y;
    cin.ignore();

    char p[100];
    cout << "Phone:   ";
    cin.getline(p, 100);

    float av;
    cout << "Average: ";
    cin >> av;
    cin.ignore();

    Student st2(n, s, y, p, av);
    st2.Print();

    cout << "\n\nTest 5 (copy constructor)\n\n";
    Student st3("Jhonatan", "Morgan", 19, "+3805067729293", 9.9);

    Student st3copy(st3);
    st3copy.Print();

    PrintStudent(st3);

    SaveStudent(st3);

    Student st4("1", "2", 4, "124", 3.3);
    LoadStudent(st4);
    cout << "\n\nData loaded from the file; \n\n";
    PrintStudent(st4);

}

