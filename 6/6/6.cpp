// 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Vector.h"
#include <iomanip>

using namespace std;

istream& operator>>(istream& cin, Vector& v) 
{
    v.Input();
    return cin;
}

ostream& operator<<(ostream& cout, Vector& v)
{
    v.Print();
    return cout;
}

int main()
{
    cout << "Test 1(increments/decrements):\n";
    int n;
    cout << "Enter the size of an array: ";
    cin >> n;

    cout << "\nYour vector (v1)\n";
    Vector v1(n);
    v1.Print();

    cout << "v1++\n";
    v1++;
    v1.Print();

    cout << "v1--\n";
    v1--;
    v1.Print();


    cout << "++v1\n";
    ++v1;
    v1.Print();

    cout << "--v1\n";
    --v1;
    v1.Print();

    cout << "\n\nTest 2(=):\n";

    cout << "\nNew vector:(v2)\n";
    Vector v2(5);
    v2.Print();

    v1 = v2;
    cout << "(v1 = v2)\nv1:" << endl;

    v1.Print();


    cout << "\n\nTest 3([]):\n";
    int index, value, v[7] = {4,16,34,12,43,92,11};
    Vector v3(v, 7);
    cout << endl << "New vector: " << endl;
    v3.Print();

    cout << endl << "Enter the index: ";
    cin >> index;
    cout << endl << "Enter the value that you want to set on this index: ";
    cin >> value;
    
    v3[index] = value;
    v3.Print();


    cout << "\n\nTest 4(vect + vect):\n";

    int vect1[5] = { 12,63,-84,56, -19 };
    int vect2[5] = { -11,-61,87,-54,24 };

    Vector v4(vect1, 5);
    Vector v5(vect2, 5);

    cout << endl << "Vector 1:\n";
    v4.Print();
    cout << endl << "Vector 2: \n";
    v5.Print();
    cout << endl << "Vector 3 = Vector 1 + Vector 2 \n";
    cout << endl << "Vector 3: \n";

    Vector v6(v4 + v5);
   
    v6.Print();

    cout << "\n\nTest 5(vect - vect):\n";

    int vect3[5] = { 13, -56, 90, 41, -3 };
    int vect4[5] = { 12,-58,87,37,-8 };

    Vector v8(vect3, 5);
    Vector v9(vect4, 5);
    cout << endl << "Vector 1:\n";
    v8.Print();
    cout << endl << "Vector 2: \n";
    v9.Print();

    cout << endl << "Vector 4 = Vector 1 - Vector 2 \n";
    cout << endl << "Vector 4: \n";

    Vector v7(v8 - v9);

    v7.Print();

    cout << "\n\nTest 6(vect * vect):\n";

    int vect5[5] = { 2, 2, 4, 2, 8 };
    int vect6[5] = { 1, 2, 2, 8, 4 };

    Vector v10(vect5, 5);
    Vector v11(vect6, 5);
    cout << endl << "Vector 1:\n";
    v10.Print();
    cout << endl << "Vector 2: \n";
    v11.Print();

    cout << endl << "Vector 5 = Vector 1 * Vector 2 \n";
    cout << endl << "Vector 5: \n";

    Vector v12(v10 * v11);

    v12.Print();

    cout << "\n\nTest 7(vect + number):\n";
    cout << "\nYour vector: (v1)";
    v1.Print();
    int num;
    cout << "Enter the number for which you want to increase all the elements: ";
    cin >> num;
    cout << "\n v1 + " << num << " = v2; \n(v2) \n";

    Vector v13(v1 + num);
    v13.Print();
    
    cout << "\n\nTest 8(vect - number):\n";
    cout << "\nYour vector: (v1)";
    v1.Print();
    cout << "Enter the number for which you want to decrease all the elements: ";
    cin >> num;
    cout << "\n v1 - " << num << " = v2; \n(v2) \n";

    Vector v14(v1 - num);
    v14.Print();

    cout << "\n\nTest 9(vect * number):\n";
    cout << "\nYour vector: (v1)";
    v1.Print();
    cout << "Enter the number for which you want to multiply all the elements: ";
    cin >> num;
    cout << "\n v1 * " << num << " = v2; \n(v2) \n";

    Vector v15(v1 * num);
    v15.Print();

    int vector1[5] = { 1, 4, 5, 9, 3 };
    int vector2[5] = { 6, 2, 1, 7, 4 };

    Vector v1_(vector1, 5);
    Vector v2_(vector2,5);

    cout << "\n\nVector1: ";
    v1_.Print();
    cout << "\nVector2: ";
    v2_.Print();
    cout << endl;

    cout << "\n\nTest 10(vector1 += vector2):\n";
    cout << "\n Vector1 += Vector1;" << endl;
    v1_ += v2_;
    v1_.Print();

    cout << "\n\nTest 11(vector1 -= vector2):\n";
    cout << "\n Vector1 += Vector1;" << endl;
    v1_ -= v2_;
    v1_.Print();

    cout << "\n\nTest 12(vector1 *= vector2):\n";
    cout << "\n Vector1 *= Vector1;" << endl;
    v1_ *= v2_;
    v1_.Print();
    
    cout << "\n\nTest 13(cin >> vector1)\n";
    cin >> v1_;

    cout << "\n\nTest 14(cout << vector1)\n";
    cout << v1_;
}

