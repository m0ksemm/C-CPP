// 18.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string str;
    ifstream in("f.html");
    if (!in.is_open())
    {
        cout << "Error!\n";
        return 0;
    }

    ofstream out;
    out.open("NewReadMe.html", ios::out | ios::trunc);

    //in.get(s); // из входного потока считываем посимвольно текстовую информацию
    //cout << s; // выводим на экран считанный символ
    //out.put(s)


    while (!in.eof())
    {
        char c1, c2, c3, c4, c5, c6;
        string s;
        in.get(c1);

        //out.seekp(5, ios::cur);
        if (c1 == 's')//s
        {
            //out.put(c1);
            in.get(c2);//r
            if (c2 == 'r' )//r
            {
                //out.put(c2);
                in.get(c3);//c
                if (c3 == 'c')
                {
                    out.put(c1);
                    out.put(c2);
                    out.put(c3);
                    for (int i = 0; i <2; i++)
                    {
                        //cout << c4;
                        in.get(c4);//="
                        out.put(c4);
                    }
                    c4 = '-';
                    while (c4 != '"')
                    {
                        in.get(c4);
                    }
                    out.put(c4);
                }  
                else out.seekp(2, ios::cur);
                
            }
            else 
            { 
                out.put(c1);
                out.put(c2);
                //out.seekp(1, ios::cur); 
            }
            
        }
        else 
        {
            out.put(c1);
        }
        //cout << str;
    }
    in.close();
    out.close();
    std::remove("f.html");
    std::rename("NewReadMe.html", "f.html");

    cout << "All the pictures are deleted.";
}

