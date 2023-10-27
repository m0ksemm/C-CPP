// 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Vector.h"
#include <iomanip>

using namespace std;

int main()
{
    cout << "Test 1(constructor with a size):\n";
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    Vector v1(n);
    v1.Print();

    cout << endl;

    cout << "Test 2(copy constructor):\n";
    Vector v2(v1);
    v2.Print();

    cout << "\nTest 3(default constructor):\n";
    Vector v3{};
    v3.Print();

    v3.Add(1);
    v3.Add(2);
    v3.Add(3);

    v3.Print();

    cout << "\nTest 4(constructor that allows to initialize elements):\n";

    int m = 5;
    int* ptr = new int[m];
    for (int i = 0; i < m; i++)
        ptr[i] = i + 1;

    Vector v4(ptr, m);

    v4.Print();

    cout << "\nTest 5(method GetSize()):\n";
    int sizev1 = v1.GetSize();
    int sizev2 = v2.GetSize();
    int sizev3 = v3.GetSize();
    int sizev4 = v4.GetSize();

    cout << "Size of vector1: " << sizev1 << endl;
    cout << "Size of vector2: " << sizev2 << endl;
    cout << "Size of vector3: " << sizev3 << endl;
    cout << "Size of vector4: " << sizev4 << endl;

    cout << "\nTest 6(method Input()):\n";
    int new_size;
    cout << "Enter the size of a vector that u need: ";
    cin >> new_size;
    Vector v5(new_size);
    v5.Input();
    cout << "Your vector:\n";
    v5.Print();

    cout << "\nTest 7(method Clear()):\n";
    v1.Clear();
    cout << "The first vector was cleared; \n";

    cout << "\nTest 8(method IsEmpty()):\n";
    bool clr = v1.IsEmpty();
    if (clr == true)
        cout << "The vector is clear; \n";
    else cout << "The vector is not clear; \n";


    cout << "\nTest 9(method Add(const int& item)):\n";

    int num;
    cout << "Enter the number that you want to add int the second vector:(v2, from Test 2) ";
    cin >> num;
    v2.Add(num);
    v2.Print();

    cout << "\nTest 10(method Insert(int index, const int& item)):\n";
    int number, index;
    cout << "Enter the number that you want to Insert in the second vector:(v2, from Test 2) ";
    cin >> number;
    cout << "Enter the index on which you want to add this number: ";
    cin >> index;

    v2.Insert(index, number);

    v2.Print();

    cout << "\nTest 11(method Remove(int index)):\n";
    cout << "Enter the Index that you want to remove in the second vector:(v2, from Test 2) ";
    cin >> index;

    v2.Remove(index);

    v2.Print();
}

