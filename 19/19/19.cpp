// 19.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    srand(time(0));
    vector<int> v1(10);
    vector<int>::iterator pb;
    for (pb = v1.begin(); pb < v1.end(); pb += 1)
    {
        *pb = rand() % (201) - 100;
    }
    cout << "Task1\n\nvector 1:\n";

    ostream_iterator<int> out(cout, " ");
    copy(v1.begin(), v1.end(), out);

    vector<int> v2;
    for (pb = v1.begin(); pb < v1.end(); pb += 1)
    {
        if (*pb > 0)
            v2.push_back(*pb);
    }
    v1 = v2;
    v2.clear();

    cout << "\nResult::\n";
    copy(v1.begin(), v1.end(), out);





    cout << "\n\n\n\nTask2\n\nvector A:\n";
    vector<int> v3(5);
    for (pb = v3.begin(); pb < v3.end(); pb += 1)
    {
        *pb = rand() % (201) - 100;
    }
    copy(v3.begin(), v3.end(), out);

    vector<int> v4(5);
    cout << "\nvector B:\n";
    for (pb = v4.begin(); pb < v4.end(); pb += 1)
    {
        *pb = rand() % (201) - 100;
    }
    copy(v4.begin(), v4.end(), out);

    cout << "\nvector C:\n";
    vector<int> v5(v3.begin(), v3.end());
    v5.insert(v5.end(), v4.begin(), v4.end());
    copy(v5.begin(), v5.end(), out);




    cout << "\n\n\n\nTask3\n\nvector A:\n";
    int arr1[4] = {1, 7, 3, 8};
    vector<int> v6(arr1, arr1 + 4);
    copy(v6.begin(), v6.end(), out);

    int arr2[9] = { 9, 1, 2, 8, 3, 1, 6, 11, 12};
    vector<int> v7(arr2, arr2 + 9);
    cout << "\nvector B:\n";
    copy(v7.begin(), v7.end(), out);

    vector<int> v8;
    vector<int>::iterator p;
    for (pb = v6.begin(); pb < v6.end(); pb += 1)
    {
        if (find(v7.begin(), v7.end(), *pb) != v7.end() == true)
            v8.push_back(*pb);
    }
    cout << "\nvector C:\n";
    copy(v8.begin(), v8.end(), out);




    cout << "\n\n\n\nTask4\n";
    int arr3[7] = { 1, 7, 13, 8, -3, 11, 3 };
    int arr4[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> v9(arr3, arr3 + 7);
    vector<int> v10(arr4, arr4 + 9);
    cout << "\nvector A:\n";
    copy(v9.begin(), v9.end(), out);
    cout << "\nvector B:\n";
    copy(v10.begin(), v10.end(), out);

    vector<int> v11;
    for (pb = v9.begin(); pb < v9.end(); pb += 1)
    {
        if (find(v10.begin(), v10.end(), *pb) != v10.end() == false)
            v11.push_back(*pb);
    }
    cout << "\nvector C:\n";
    copy(v11.begin(), v11.end(), out);
}

