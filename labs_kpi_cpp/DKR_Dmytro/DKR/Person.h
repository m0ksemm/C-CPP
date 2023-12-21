#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Person abstract // ������� ����������� ���� Person
{
private:
    string Name;    // ���� ��� ���������� ���� ������
    string Surname; // ���� ��� ���������� ������� ������
    int Age;        // ���� ��� ���������� ��� ������
    string Gender;  // ���� ��� ���������� ������� ������
public:
    Person();   // ����������� �� ����������� 

    void SetName(string n);   // ����� ��� ���� ���� Name
    string GetName() const;   // ����� ��� ��������� ���� Name

    void SetSurname(string n); // ����� ��� ���� ���� Surname
    string GetSurname() const; // ����� ��������� ���� ���� Surname

    void SetAge(int a); // ����� ��� ���� ���� Age
    int GetAge() const; // ����� ��������� ���� ���� Age

    void SetGender(string g); //  ����� ��� ���� ���� Gender
    string GetGender() const; //  ����� ��� ��������� ���� Gender

    virtual void GetInfo() const; // ³��������� ����� ��� ��������� ���������� ��� ��'���
    virtual void Save() const;    // ³��������� ����� ��� ���������� ����� � ����
};

