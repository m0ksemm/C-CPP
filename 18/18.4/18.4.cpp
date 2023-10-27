// 18.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <fstream>

using namespace std;

typedef unsigned int uint;

int how_many_numbers(int number)
{
    bool flag = false;
    int n = 0;
    for (int i = 31; i >= 0; i--)
    {


        uint mask = 1 << i;
        uint digit = number & mask;
        //cout << (digit >> i);
        if (digit != 0)
            flag = true;
        if (flag == true)
            n++;

    }
    return n;
}

char cipher(char ch, int key)
{
    int res = int(ch) ^ key;
    return (res);
}

char decryption(char res, int key)
{
    //int key = 415;
    int backres = 0;


    for (int i = 0; i < 31; i++)
    {
        uint mask = 1 << i;

        //uint mask2 = 1 << i;
        uint digit2 = key & mask; // key

        uint digit3 = res & mask; // res\

        int flag = 0;
        if (digit2 == digit3)
        {
            flag = 0;

        }
        else
        {
            flag = 1;
            backres += pow(2, i);
        }

        //cout << " " << (digit2 >> i) << "       " << (digit3 >> i) << "        " << flag << endl;
    }

    return char(backres);
}


int main()
{
    ifstream in;
    in.open("text.txt");

    if (!in.is_open())
    {
        cout << "Error!\n";
        return 0;
    }

    srand(time(0));
    int key =  rand() % 1000;

    ofstream out;
    out.open("encrypted_text.txt", ios::out | ios::trunc);
    char c;

    while (!in.eof())
    {
        in.get(c);
        c = cipher(c, key);
        out.put(c);
    }
    
    in.close();
    out.close();


    in.open("encrypted_text.txt");
    out.open("transcribed_text.txt", ios::out | ios::trunc);

    

    while (!in.eof())
    {
        in.get(c);
        c = decryption(c, key);
        out.put(c);
    }
    
    in.close();
    out.close();



    cout << "This program changes the encryption key to a random one every time you start it\n\n";

    char buf[300];
    cout << "\nOriginal file: (text.txt)\n\n";
    in.open("text.txt");
    while (!in.eof())
    {
        in.getline(buf, 300);
        cout << buf << endl;
    }
    in.close();

    cout << "\n\n\nEncrypted file: (encrypted_text.txt)\n\n";
    in.open("encrypted_text.txt");
    while (!in.eof())
    {
        in.getline(buf, 300);
        cout << buf << endl;
    }
    in.close();

    cout << "\n\n\nResulting file: (transcribed_text.txt)\n\n";
    in.open("transcribed_text.txt");
    while (!in.eof())
    {
        in.getline(buf, 300);
        cout << buf << endl;
    }
    in.close();

}
