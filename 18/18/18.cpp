// 18.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("file.txt");
    if (!f.is_open())
    {
        cout << "Error!\n";
        return 0;
    }
    else
    {
        char st[300];
        int countw = 0, countl = 0;

        cout << "Your file:\n\n";
        while (!f.eof())
        {
            char buf[300];
            f.getline(buf, 300);
            countl++;
            cout << buf << endl;
        }
        f.close();

        ifstream in("file.txt");
        string str;
        while (!in.eof())
        {
            in >> str;
            countw++;
        }
        in.close();

        cout << "\n\nThe number of words: " << countw;
        cout << "\nThe number of lines: " << countl;
    }
}///itoa

