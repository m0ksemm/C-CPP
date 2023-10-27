
// 10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Stack.h"
#include "vector.h"
#include <string>

bool isdigit(char ch) 
{
    if (ch == '0' || ch == '1' || ch == '2')
        return true;
    else if (ch == '3' || ch == '4' || ch == '5')
        return true;
    else if (ch == '6' || ch == '7' || ch == '8'  || ch == '9')
        return true;
    else return false;
}

int chtodouble(char ch) 
{
    int res;
    if (ch == '0')
        return 0.0;
    else if (ch == '1')
        return 1.0;
    else if (ch == '2')
        return 2.0;
    else if (ch == '3')
        return 3.0;
    else if (ch == '4')
        return 4.0;
    else if (ch == '5')
        return 5.0;
    else if (ch == '6')
        return 6.0;
    else if (ch == '7')
        return 7.0;
    else if (ch == '8')
        return 8.0;
    else if (ch == '9')
        return 9.0;
}

bool issign(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return true;
    else if (ch == '(' || ch == ')')
        return true;
    else return false;
}

using namespace std;

int main()
{
    Stack<double> numb;
    Stack<char> symb;

    string math;
    getline(cin, math);
    char c;

    math = '(' + math + ')';

    cout << endl << endl << math;

    int result, j, k = 0, flag = 0;
    double num1, num2, number, denum = 0;

    symb.Push(math[0]);
    for (int i = 1; i < math.size(); i++)
    {
        if (flag == 1)
            break;
        switch (math[i]) 
        {
        case '0':
        case '1':
        case '2':
        case '3': 
        case '4':
        case '5': 
        case '6':
        case '7':
        case '8':
        case '9':
            number = chtodouble(math[i]);
            j = i + 1;
            
            if (isdigit(math[j]) == true || math[j] == '.')
            {
                while (isdigit(math[j]) == true)
                {
                    double d = chtodouble(math[j]);
                    number = number * 10 + d;
                    j++;
                }
                if (math[j] == '.')
                {
                    j++;
                    denum = 0;
                    while (isdigit(math[j]) == true)
                    {
                        double d = chtodouble(math[j]);
                        denum = denum * 10 + d;
                        j++;
                        k++;
                    }

                    while (k != 0)
                    {
                        denum /= 10;
                        k--;
                    }
                    number += denum;
                }

                i = j - 1;
            }
   
            numb.Push(number);
            break;
        case '-':
        case '+':
        
            symb.Peek(c);
            numb.Peek(num1);
            if (c == '(')
            {
                symb.Push(math[i]);
            }
            else 
            {
                
                numb.Peek(num1);
                numb.Pop(num1);

                numb.Peek(num2);
                numb.Pop(num2);

                if (c == '+')
                {
                    numb.Push(num2 + num1);
                    char mult;
                    symb.Pop(mult);
                    symb.Push(math[i]);
                }
                if (c == '-')
                {
                    numb.Push(num2 - num1);
                    char devide;
                    symb.Pop(devide);
                    symb.Push(math[i]);
                }
                if (c == '*')
                {
                    numb.Push(num2 * num1);
                    char devide;
                    symb.Pop(devide);
                    symb.Push(math[i]);
                }
                if (c == '/')
                {
                    numb.Push(num2 / num1);
                    char devide;
                    symb.Pop(devide);
                    symb.Push(math[i]);
                }
                if (c == '^')
                {
                    numb.Push(pow(num2, num1));
                    char power;
                    symb.Pop(power);
                    symb.Push(math[i]);
                }

            }
            break;
        case '*':
        case '/':
        case '^':
            symb.Peek(c);
            switch (c)
            {
            case '+':
            case '-':
            case '(':
                symb.Push(math[i]);
                break;
            }
            break;
        case ')':
            symb.Peek(c);
            do
            {
                symb.Peek(c);
                
                if (c == '(')
                {
                    symb.Pop(c);
                    break;
                }      

                numb.Peek(num1);

                if (num1 == -1)
                    break;

                numb.Pop(num1);

                numb.Peek(num2);

                if (num2 == -1)
                    break;

                numb.Pop(num2);

                if (c == '+')
                {
                    numb.Push(num2 + num1);
                }
                else if (c == '-')
                { 
                    numb.Push(num2 - num1);
                }
                else if (c == '*')
                {
                    numb.Push(num2 * num1);
                }
                else if (c == '/')
                {
                    numb.Push(num2 / num1);
                }
                else if (c == '^')
                {
                    numb.Push(pow(num2, num1));
                }
                
               
                symb.Pop(c);
                 
            } while (true);

           
            break;

        case '(':
            symb.Push(math[i]);
            break;

        default:
            cout << "\nError: unknown symbol;\n";
            flag = 1;
            break;
        }
            
    }


    
    cout << "=";

    double n;
    while (numb.IsEmpty() == false) 
    {
        numb.Peek(n);
        cout << n;
        numb.Pop(n);
    }

    /*cout << "\nSymb:\n";

    while (symb.IsEmpty() == false)
    {
        symb.Peek(c);
        cout << c;
        symb.Pop(c);
    }*/
}




