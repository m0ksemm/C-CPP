// 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Vector.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

ostream& operator<<(ostream& cout, Vector<int>& v)
{
    v.Print();
    return cout;
}
istream& operator>>(istream& cin, Vector<int>& v)
{
    v.Input();
    return cin;
}


ostream& operator<<(ostream& cout, Vector<double>& v)
{
    v.Print();
    return cout;
}
istream& operator>>(istream& cin, Vector<double>& v)
{
    v.Input();
    return cin;
}


class Test1
{
    int a;
public:
    Test1() 
    {
        a = 0;
    }

    Test1(int n) 
    {
        a = n;
    }

    void Set(int n)
    {
        a = n;
    }
    int Get() 
    {
        return a;
    }
    void Show()
    {
        cout << a << endl;
    }
    Test1& operator++()
    {
        ++a;
        return *this;
    }

    Test1& operator--()
    {
        --a;
        return *this;
    }

    Test1& operator++(int k)
    {
        Test1 tmp = *this;
        this->a++;
        return tmp;
    }

    Test1& operator--(int k)
    {
        Test1 tmp = *this;
        this->a--;
        return tmp;
    }
   
    Test1& operator-(Test1& obj)
    {
        Test1 res = this->a - obj.a;
        return res;
    }

    Test1& operator+(Test1& obj)
    {
        Test1 res = this->a + obj.a;
        return res;
    }

    Test1& operator*(Test1& obj)
    {
        Test1 res = this->a * obj.a;
        return res;
    }
    
    Test1 operator +=(Test1& number)
    {
        this->a += number.a;
        return *this;
    }

    Test1 operator -=(Test1& number)
    {
        this->a -= number.a;
        return *this;
    }

    Test1 operator *=(Test1& number)
    {
        this->a *= number.a;
        return *this;
    }

    friend ostream& operator<<(ostream& cout, Test1& obj);
    friend istream& operator>>(istream& cin, Test1& obj);
};



ostream& operator<<(ostream& cout, Test1& obj)
{
    int n = obj.Get();
    cout << n;
    return cout;
}

istream& operator>>(istream& cin, Test1& obj)
{
    int n;
    cin >> n;
    obj.Set(n);
    return cin;
}

ostream& operator<<(ostream& cout, Vector<Test1>& v)
{
    v.Print();
    return cout;
}
istream& operator>>(istream& cin, Vector<Test1>& v)
{
    v.Input();
    return cin;
}


int main()
{
    
    int choice;
    cout << "If you want to test INT, enter 1: \n";
    cout << "If you want to test DOUBLE, enter 2: \n";
    cout << "If you want to test TEST(user type), enter 3: \n";
    cout << "If you want to finish, enter 4: \n";

    while (true)
    {
        cin >> choice;
        if (choice == 1)
        {

            cout << "Test 1(increments/decrements):\n";
            int n;
            cout << "Enter the size of an array: ";
            cin >> n;

            cout << "\nYour vector (v1)\n";
            Vector<int> v1(n);

            v1.Input();

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
            Vector<int> v2(5);

            v2.Input();

            v2.Print();

            v1 = v2;
            cout << "(v1 = v2)\nv1:" << endl;

            v1.Print();


            cout << "\n\nTest 3([]):\n";
            int index, value, v[7] = { 4,16,34,12,43,92,11 };
            Vector<int> v3(v, 7);
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

            Vector<int> v4(vect1, 5);
            Vector<int> v5(vect2, 5);

            cout << endl << "Vector 1:\n";
            v4.Print();
            cout << endl << "Vector 2: \n";
            v5.Print();
            cout << endl << "Vector 3 = Vector 1 + Vector 2 \n";
            cout << endl << "Vector 3: \n";

            Vector<int> v6(v4 + v5);

            v6.Print();

            cout << "\n\nTest 5(vect - vect):\n";

            int vect3[5] = { 13, -56, 90, 41, -3 };
            int vect4[5] = { 12,-58,87,37,-8 };

            Vector<int> v8(vect3, 5);
            Vector<int> v9(vect4, 5);
            cout << endl << "Vector 1:\n";
            v8.Print();
            cout << endl << "Vector 2: \n";
            v9.Print();

            cout << endl << "Vector 4 = Vector 1 - Vector 2 \n";
            cout << endl << "Vector 4: \n";

            Vector<int> v7(v8 - v9);

            v7.Print();

            cout << "\n\nTest 6(vect * vect):\n";

            int vect5[5] = { 2, 2, 4, 2, 8 };
            int vect6[5] = { 1, 2, 2, 8, 4 };

            Vector<int> v10(vect5, 5);
            Vector<int> v11(vect6, 5);
            cout << endl << "Vector 1:\n";
            v10.Print();
            cout << endl << "Vector 2: \n";
            v11.Print();

            cout << endl << "Vector 5 = Vector 1 * Vector 2 \n";
            cout << endl << "Vector 5: \n";

            Vector<int> v12(v10 * v11);

            v12.Print();

            cout << "\n\nTest 7(vect + number):\n";
            cout << "\nYour vector: (v1)";
            v1.Print();
            int num;
            cout << "Enter the number for which you want to increase all the elements: ";
            cin >> num;
            cout << "\n v1 + " << num << " = v2; \n(v2) \n";

            Vector<int> v13(v1 + num);
            v13.Print();

            cout << "\n\nTest 8(vect - number):\n";
            cout << "\nYour vector: (v1)";
            v1.Print();
            cout << "Enter the number for which you want to decrease all the elements: ";
            cin >> num;
            cout << "\n v1 - " << num << " = v2; \n(v2) \n";

            Vector<int> v14(v1 - num);
            v14.Print();

            cout << "\n\nTest 9(vect * number):\n";
            cout << "\nYour vector: (v1)";
            v1.Print();
            cout << "Enter the number for which you want to multiply all the elements: ";
            cin >> num;
            cout << "\n v1 * " << num << " = v2; \n(v2) \n";

            Vector<int> v15(v1 * num);
            v15.Print();

            int vector1[5] = { 1, 4, 5, 9, 3 };
            int vector2[5] = { 6, 2, 1, 7, 4 };

            Vector<int> v1_(vector1, 5);
            Vector<int> v2_(vector2, 5);

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

            cout << "\n\nthe end\n\nIf you want to test INT, enter 1: \n";
            cout << "If you want to test DOUBLE, enter 2: \n";
            cout << "If you want to test TEST(user type), enter 3: \n";
            cout << "If you want to finish, enter 4: \n";

        }
        else if (choice == 2)
        {
            cout << "Test 1(increments/decrements):\n";
            int n;
            cout << "Enter the size of an array: ";
            cin >> n;

            cout << "\nYour vector (v1)\n";
            Vector<double> v1(n);

            v1.Input();

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
            Vector<double> v2(5);

            v2.Input();

            v2.Print();

            v1 = v2;
            cout << "(v1 = v2)\nv1:" << endl;

            v1.Print();


            cout << "\n\nTest 3([]):\n";
            int index;
            double v[7] = { 4.3,16.23,34.66,12.11,43.52,92.51,11.12 }, value;
            Vector<double> v3(v, 7);
            cout << endl << "New vector: " << endl;
            v3.Print();

            cout << endl << "Enter the index: ";
            cin >> index;
            cout << endl << "Enter the value that you want to set on this index: ";
            cin >> value;

            v3[index] = value;
            v3.Print();


            cout << "\n\nTest 4(vect + vect):\n";

            double vect1[5] = { 12.23,63.11,-84.41,56.33, -19.0 };
            double vect2[5] = { -11.44,-61.76,87.9,-54,24.12 };

            Vector<double> v4(vect1, 5);
            Vector<double> v5(vect2, 5);

            cout << endl << "Vector 1:\n";
            v4.Print();
            cout << endl << "Vector 2: \n";
            v5.Print();
            cout << endl << "Vector 3 = Vector 1 + Vector 2 \n";
            cout << endl << "Vector 3: \n";

            Vector<double> v6(v4 + v5);

            v6.Print();

            cout << "\n\nTest 5(vect - vect):\n";

            double vect3[5] = { 13.12, -56.87, 90.23, 41.18, -3.62 };
            double vect4[5] = { 12.4,-58.6,87.13,37.7,-8.32 };

            Vector<double> v8(vect3, 5);
            Vector<double> v9(vect4, 5);
            cout << endl << "Vector 1:\n";
            v8.Print();
            cout << endl << "Vector 2: \n";
            v9.Print();

            cout << endl << "Vector 4 = Vector 1 - Vector 2 \n";
            cout << endl << "Vector 4: \n";

            Vector<double> v7(v8 - v9);

            v7.Print();

            cout << "\n\nTest 6(vect * vect):\n";

            double vect5[5] = { 2.2, 2.2, 4.2, 2.2, 8.2 };
            double vect6[5] = { 1.3, 2.3, 2.3, 8.3, 4.3 };

            Vector<double> v10(vect5, 5);
            Vector<double> v11(vect6, 5);
            cout << endl << "Vector 1:\n";
            v10.Print();
            cout << endl << "Vector 2: \n";
            v11.Print();

            cout << endl << "Vector 5 = Vector 1 * Vector 2 \n";
            cout << endl << "Vector 5: \n";

            Vector<double> v12(v10 * v11);

            v12.Print();

            cout << "\n\nTest 7(vect + number):\n";
            cout << "\nYour vector: (v1)";
            v1.Print();
            double num;
            cout << "Enter the number for which you want to increase all the elements: ";
            cin >> num;
            cout << "\n v1 + " << num << " = v2; \n(v2) \n";

            Vector<double> v13(v1 + num);
            v13.Print();

            cout << "\n\nTest 8(vect - number):\n";
            cout << "\nYour vector: (v1)";
            v1.Print();
            cout << "Enter the number for which you want to decrease all the elements: ";
            cin >> num;
            cout << "\n v1 - " << num << " = v2; \n(v2) \n";

            Vector<double> v14(v1 - num);
            v14.Print();

            cout << "\n\nTest 9(vect * number):\n";
            cout << "\nYour vector: (v1)";
            v1.Print();
            cout << "Enter the number for which you want to multiply all the elements: ";
            cin >> num;
            cout << "\n v1 * " << num << " = v2; \n(v2) \n";

            Vector<double> v15(v1 * num);
            v15.Print();

            double vector1[5] = { 1.1, 4.4, 5.5, 9.9, 3.3 };
            double vector2[5] = { 6.6, 2.2, 1.1, 7.7, 4.4 };

            Vector<double> v1_(vector1, 5);
            Vector<double> v2_(vector2, 5);

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


            cout << "\n\nthe end\n\nIf you want to test INT, enter 1: \n";
            cout << "If you want to test DOUBLE, enter 2: \n";
            cout << "If you want to test TEST(user type), enter 3: \n";
            cout << "If you want to finish, enter 4: \n";
        }
        else if (choice == 3)
        {
            

            cout << "Test 1(increments/decrements):\n";
            int n;
            cout << "Enter the size of an array: ";
            cin >> n;

            Vector<Test1> v1(n);

            cout << "\nYour vector (v1)\n";

            v1.Input();

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


             Vector<Test1> v2(5);

             v2.Input();

             v2.Print();

             v1 = v2;
             cout << "(v1 = v2)\nv1:" << endl;

             v1.Print();


             cout << "\n\nTest 3([]):\n";
             int index, value;
             Vector<Test1> v3(7);
             cout << endl << "New vector: " << endl;
             v3.Input();
             v3.Print();

             cout << endl << "Enter the index: ";
             cin >> index;
             cout << endl << "Enter the value that you want to set on this index: ";
             cin >> value;

             v3[index] = value;
             v3.Print();


             cout << "\n\n\nTest 4(vect + vect):\n";

             Vector<Test1> v4(5);
             Vector<Test1> v5(5);
             v4.Rand();//метод заполняет вектор рандомно
             v5.Rand();


             cout << endl << "Vector 1:\n";
             v4.Print();
             cout << endl << "Vector 2: \n";
             v5.Print();

             cout << endl << "Vector 3 = Vector 1 + Vector 2 \n";
             cout << endl << "Vector 3: \n";


             Vector<Test1> v6 = v4 + v5;

             v6.Print();

             cout << "\n\n\nTest 5(vect - vect):\n";

             cout << endl << "Vector 1:\n";
             v5.Print();
             cout << endl << "Vector 2: \n";
             v6.Print();

             cout << endl << "Vector 3 = Vector 1 - Vector 2 \n";
             cout << endl << "Vector 3: \n";

             Vector<Test1> v7 = v5 - v6;

             v7.Print();

             cout << "\n\n\nTest 6(vect * vect):\n";

             cout << endl << "Vector 1:\n";
             v5.Print();
             cout << endl << "Vector 2: \n";
             v6.Print();

             cout << endl << "Vector 3 = Vector 1 * Vector 2 \n";
             cout << endl << "Vector 3: \n";

             Vector<Test1> v8 = v5 * v6;

             v8.Print();


             cout << "\n\nTest 7(vect + number):\n";
             cout << "\nYour vector: (v1)";
             v4.Print();
             int num;
             cout << "Enter the number for which you want to increase all the elements: ";
             cin >> num;

             Test1 number1(num);
             cout << "\n v1 + " << num << " = v2; \n(v2) \n";

             Vector<Test1> v9 = v4 + number1;
             v9.Print();

             cout << "\n\nTest 8(vect - number):\n";
             cout << "\nYour vector: (v1)";
             v4.Print();
             cout << "Enter the number for which you want to decrease all the elements: ";
             cin >> num;
             Test1 number2(num);

             cout << "\n v1 - " << num << " = v2; \n(v2) \n";

             Vector<Test1> v10(v4 - number2);
             v10.Print();

             cout << "\n\nTest 9(vect * number):\n";
             cout << "\nYour vector: (v1)";
             v4.Print();
             cout << "Enter the number for which you want to multiply all the elements: ";
             cin >> num;
             Test1 number3(num);

             cout << "\n v1 * " << num << " = v2; \n(v2) \n";

             Vector<Test1> v15(v4* number3);
             v15.Print();


             Vector<Test1> v1_(5);
             Vector<Test1> v2_(5);

             v1_.Rand();
             v2_.Rand();

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
             cout << "\n Vector1 -= Vector1;" << endl;
             v1_ -= v2_;
             v1_.Print();

             cout << "\n\nTest 12(vector1 *= vector2):\n";
             cout << "\n Vector1 *= Vector1;" << endl;
             v1_ *= v2_;
             v1_.Print();

             cout << "\n\nTest 13(cin >> vector1)\n";

             Vector<Test1> v3_(5);

             cin >> v3_;

             cout << "\n\nTest 14(cout << vector1)\n";
             cout << v3_;

             cout << "\n\nthe end\n\nIf you want to test INT, enter 1: \n";
             cout << "If you want to test DOUBLE, enter 2: \n";
             cout << "If you want to test TEST(user type), enter 3: \n";
             cout << "If you want to finish, enter 4: \n";
        }
        else if (choice == 4)
            break;
    }
}

