#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include "Group.h"

using namespace std;

class Program { // Клас Program, через який відбувається взаємодія з класом академічної групи. 
private:        // Цей клас не має прямого доступу до жодного з полів інших класів. Вся взаємодія 
    Group group;  // відбувається через окремі методи. 
public:
    Program() {
        Load();
    }
    void Menu() { // Меню, в якому користувачеві надається вибір потрібного пункту 
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
    void AddStudent() { // Метод, який викликає метод додавання новго студенту до групи 
        group.AddStudent();
    }
    void PrintAllGroup() { // Метод, який викликає метод виведення інформації про групу
        group.PrintGroup();
    }
    void RemoveStudent() { // Метод, який викликає метод видалення студенту з групи 
        group.RemoveStudent();
    }
    void ChangeTeacher() { // Метод, який викликає метод зміни інформації провикладача 
        group.ChangeTeacher();
    }
    void SearchStudent() { // Метод, який викликає метод пошуку студенту 
        group.SearchStudent();
    }
    void Save() {  // Метод, який викликає метод збуруження всіх даних в текстовий файл 
        group.SaveData();
    }
    void Load() { // Метод, який викликає метод завантаження даних з файлу  
        group.LoadData();
    } 
    void Run() { // Метод, що забезпечує функціонал програми 
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

int main() // Головна точка входу в програму 
{
    Program p;
    p.Run();
}
