// 18.5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

char itoc(int n)
{
    if (n == 1)
        return '1';
    if (n == 2)
        return '2';
    if (n == 3)
        return '3';
    if (n == 4)
        return '4';
    if (n == 5)
        return '5';
    if (n == 6)
        return '6';
    if (n == 7)
        return '7';
    if (n == 8)
        return '8';
    if (n == 9)
        return '9';
}

string* del(string *arr, int* count, int ind)
{
    int k = 0;
    string *p = new string[--*count];
    for (int i = 0; i < *count; i++)
    {
        if (i == ind)    
            k = 1;
        p[i] = arr[i + k];
    }
    delete[]arr;
    return p;
}

int main()
{
    ifstream in, in2;
    in.open("text.txt");

    string str, str2;
    if (!in.is_open())
    {
        cout << "Error!\n";
        return 0;
    }

    ofstream out;
    int count = 0;
    while (!in.eof())
    {
        in >> str;
        count++;
    }
    in.close();
    string *arr = new string[count];
    int* array = new int[count];

    in.open("text.txt");

    int i = 0;
    while (!in.eof())
    {
        in >> str;
        arr[i] = str;
        i++;
    }
    in.close();
    
    for (int i = 0; i < count; i++)
    {
        int n = 0;
        for (int j = 0; j < count; j++)
        {
            if (arr[j] == arr[i])
            {
                n++;
            }
            array[i] = n;  
        }
    }
    for (int i = 0; i < count; i++)
    {

        arr[i] = itoc(array[i]) + arr[i];
        arr[i].insert(0, 1, '(');
        arr[i].insert(2, 1, ')');
    }

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (arr[j] == arr[i])
            {
                arr = del(arr, &count, j);
            }
        }
    }

    for (int i = 0; i < count; i++)
    { 
        for (int j = count - 1; j > i; j--)
        {
            if (arr[j - 1] < arr[j])
            {
                string s = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = s;
            }
        }
    }

   

    out.open("result.txt", ios::out | ios::trunc);
    
    for (int i = 0; i < count; i++)
    {
        out << arr[i];
        out << '\n';
    }
    out.close();
    
    cout << endl;

    in.open("result.txt");
    string str1;
    for (int i = 0; i < count; i++)
    {
        in >> str1;
        cout << str1 << endl;
    }
    in.close();

    delete[] arr;
    delete[] array;
}

