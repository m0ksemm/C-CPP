#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include "Group.h"

using namespace std;

class Program { // ���� Program, ����� ���� ���������� ������� � ������ ��������� �����. 
private:        // ��� ���� �� �� ������� ������� �� ������� � ���� ����� �����. ��� ������� 
    Group group;  // ���������� ����� ����� ������. 
public:
    Program() {
        Load();
    }
    void Menu() { // ����, � ����� ������������ �������� ���� ��������� ������ 
        cout << "---Academy group---" << endl;
        cout << "1. Print all group" << endl;
        cout << "2. Add new student" << endl;
        cout << "3. Remove student" << endl;
        cout << "4. Change teacher" << endl;
        cout << "5. Search student" << endl;
        cout << "6. Save group" << endl;
        cout << "7. Load group" << endl;
        cout << "0. exit" << endl;
    }
    void AddStudent() { // �����, ���� ������� ����� ��������� ����� �������� �� ����� 
        group.AddStudent();
    }
    void PrintAllGroup() { // �����, ���� ������� ����� ��������� ���������� ��� �����
        group.PrintGroup();
    }
    void RemoveStudent() { // �����, ���� ������� ����� ��������� �������� � ����� 
        group.RemoveStudent();
    }
    void ChangeTeacher() { // �����, ���� ������� ����� ���� ���������� ������������ 
        group.ChangeTeacher();
    }
    void SearchStudent() { // �����, ���� ������� ����� ������ �������� 
        group.SearchStudent();
    }
    void Save() {  // �����, ���� ������� ����� ���������� ��� ����� � ��������� ���� 
        group.SaveData();
    }
    void Load() { // �����, ���� ������� ����� ������������ ����� � �����  
        group.LoadData();
    } 
    void Run() { // �����, �� ��������� ���������� �������� 
        int i = 1;
        while (i != 0) {
            system("cls");
            
            Menu();
            cin >> i; 
            switch (i) {
            case 0:
                break;
            case 1:
                PrintAllGroup();
                system("Pause");
                break;
            case 2:
                AddStudent();
                system("Pause");
                break;
            case 3:
                RemoveStudent();
                system("Pause");
                break;
            case 4:
                ChangeTeacher();
                system("Pause");
                break;
            case 5:
                SearchStudent();
                system("Pause");
                break;
            case 6:
                Save();
                system("Pause");
                break;
            case 7:
                Load();
                system("Pause");
                break;
            default:
                cout << "Wrong value, try again" << endl;
                break;
            }
        }
        
    }
};

int main() // ������� ����� ����� � �������� 
{
    Program p;
    p.Run();
}
