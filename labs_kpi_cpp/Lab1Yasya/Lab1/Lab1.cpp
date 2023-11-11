#include <iostream>
#include "Ratio.h"

using namespace std;


int main()
{


    cout << "Task 1.  \n Implement the corresponding constructors: by default, copy and \n";
    cout << "initialization with one (in the case of integers) or a pair of integers.\n\n";

    cout << "Default constructor used:\n";
    Ratio obj1;
    obj1.Print();

    int m, n;

    cout << "\n\nEnter numerator:";
    cin >> m;
    cout << "Constructor with 1 parameter used:\n";
    Ratio obj2(m);
    obj2.Print();

    cout << "\n\nEnter numerator:";
    cin >> m;
    cout << "Enter denomerator:";
    cin >> n;

    cout << "Constructor with 2 parametrees used:\n";
    Ratio obj3(m, n);
    obj3.Print();



    cout << "\n\n\nTask 2.  \n Implement mathematical operations of addition, subtraction, multiplication \n";
    cout << "and dividing numbers (both among themselves and with whole numbers).\n\n";

    cout << "Object 1:\n";
    obj3.Print();

    cout << "Object 2:\n";
    obj1.Print();

    cout << "\nObject 1 + 3:\n";
    obj3 + 3;
    obj3.Print();

    cout << "\nObject 1 + Object 2:\n";
    obj3 + obj1;
    obj3.Print();

    cout << "\nObject 1 - 3:\n";
    obj3 - 3;
    obj3.Print();

    cout << "\nObject 1 - Object 2:\n";
    obj3 - obj1;
    obj3.Print();

    cout << "\nObject 1 * 2\n";
    obj3 * 2;
    obj3.Print();

    cout << "\nObject 1 / 2\n";
    obj3 / 2;
    obj3.Print();

    cout << "\nObject 1 * Object 2\n";
    obj3 * obj1;
    obj3.Print();

    cout << "\nObject 1 / Object 2\n";
    obj3 / obj1;
    obj3.Print();

    cout << "\n\n\nTask 3.  \n Implement comparison of numbers for equality and in order (as between \n";
    cout << "by itself and with whole numbers).\n\n";

    cout << "Object 1:\n";
    obj3.Print();
    cout << "Object 2:\n";
    Ratio obj4(7,9);
    obj4.Print();

    cout << "\nObject 1 > 3:\n";

    if (obj3 > 3)
        cout << "True\n";
    else cout << "False\n";


    cout << "\nObject 1 > Object 2:\n";

    if (obj3 > obj4)
        cout << "True\n";
    else cout << "False\n";



    cout << "\nObject 1 < 3:\n";

    if (obj3 < 3)
        cout << "True\n";
    else cout << "False\n";


    cout << "\nObject 1 < Object 2:\n";

    if (obj3 < obj4)
        cout << "True\n";
    else cout << "False\n";
    
    cout << "\nObject 1 = 8:\n";

    if (obj3 == 8)
        cout << "True\n";
    else cout << "False\n";

    cout << "\nObject 1 = Object 2:\n";

    if (obj3 == obj4)
        cout << "True\n";
    else cout << "False\n";


    cout << "\n\n\nTask 4.  \n Raise fractions to the int power. \n\n";

    cout << "Object 1: \n";
    obj4.Print();

    cout << "\nObject 1 ^ 3 = \n";
    obj4 ^ 3;

    obj4.Print();


    cout << "\n\n\nTask 5.  \n Implement access to the numerator and \ndenominator (reading and modification).\n\n";
    cout << "Object 1: \n";
    obj4.Print();
    cout << "\nGetters:\n";
    cout << "Numerator: " << obj4.GetNum() << endl;
    cout << "Denomerator: " << obj4.GetDenum() << endl;

    cout << "\nSetters:\n";
    cout << "Enter Numerator: ";
    cin >> n;
    cout << "Enter Denomerator: ";
    cin >> m;

    cout << "\nSetters used. Object 1: \n";
    obj4.SetNum(n);
    obj4.SetDenum(m);
    
    obj4.Print();

    cout << "\n\n\nTask 6.  \nRealize the possibility of obtaining whole and fractional \n(correct fraction) parts of a fraction.\n\n";

    cout << "Object 1: \n";
    obj4.Print();

    cout << "\nInt part: " << obj4.IntPart();
    cout << "\nFloat part: ";
    obj4.FloatPart() ;

    cout << "\n\n\nTask 7.  \nImplement the possibility of converting a fraction to a \nfloating point number a comma, as well as an \ninteger(receiving an integer part).\n\n";

    cout << "\nInt part: " << obj4.IntPart();
    cout << "\nDouble number: " << obj4.DoubleNumber();

    cout << "\n\n\nTask 8.  Implement assignment operations. \n\n";

    cout << "Object 1:\n";
    obj3.Print();

    cout << "\nObject 2:\n";
    obj1.Print();

    cout << "\nObject 1 = Object 2:\nnObject 1:\n";
    obj1 = obj3;
    
    obj1.Print();

    cout << "\n\n\nTask 9.  Implement a check whether a fraction is an integer. \n\n";
    
    cout << "\nObject 1: \n";
    obj4.Print();

    if (obj4.IfInt() == true)
        cout << "Int\n";
    else cout << "Not Int\n";

}