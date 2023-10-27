// 7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "matrix.h"
#include <iomanip>

using namespace std;


ostream& operator<<(ostream& cout, matrix& m) 
{
    for (int i = 0; i < m.row; i++)
    {
        for (int j = 0; j < m.col; j++)
        {
            cout << setw(3) << m.p[i][j] << " ";
        }
        cout << endl;
    }

    return cout;
}

istream& operator>>(istream& cin, matrix& m)
{
	cout << "\nEnter " << m.col * m.row << " elements: " << endl;
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			cin >> m.p[i][j];
		}
	}
    return cin;
}

int main()
{
    cout << "Test 1(constructor with 2 parametres);\n\n";
    matrix m0(2, 2);
    cin >> m0;
    cout << "Matrix m0:\n";
    cout << m0;

    cout << "\n\n\nTest 2(copy constructor);\n\n";
    matrix m(m0);

    cout << "Matrix m:\n";
    cout << m;

    cout << "\n\n\nTest 3(transfer constructor (m to m2));\n\n";

    matrix m2(move(m));
    cout << "m2;\n";
    cout << m2;

    cout << "m;\n";
    cout << m;

    cout << "\n\n\nTest 4(copy constructor =);\n\n";

    matrix m3 = m2;
    cout << "m3;\n" << m3;


    cout << "\n\n\nTest 5(transfer constructor = (m_new to m4));\n\n";
    matrix m_new(2, 2);
    cout << "m_new;\n";
    cout << m_new;

    matrix m4 = move(m_new);

    cout << "m3;\n";
    cout << m4;

    cout << "m_new;\n";
    cout << m_new;

    cout << "\n\n\nTest 6(m5++, ++m5, m5--, --m5);\n\n";

    matrix m5(3, 2);
    cout << "m5;\n" << m5;
    cout << "\nm5++;";
    m5++;
    cout << endl << m5;

    cout << "\n++m5;\n";
    ++m5;
    cout << m5 << endl;

    cout << "\nm5--;\n";
    m5--;
    cout << m5 << endl;

    cout << "\n--m5;\n";
    --m5;
    cout << m5 << endl;

    cout << "\n\n\nTest 7(m6 + m7);\n\n";

    matrix m6(3, 3);
    cout << "m6:\n" << m6;


    matrix m7(3, 3);
    cout << "m7:\n" << m7;

    cout << "\nm6 + m7 = \n";
    matrix m8 = m6 + m7;
    cout << m8;

    cout << "\n\n\nTest 8(m9 * m10);\n\n";

    cout << "m9\n";
    matrix m9(3, 2);
    cin >> m9;

    cout << "m10\n";
    matrix m10(2, 3);
    cin >> m10;

    cout << "m9:\n" << m9;

    cout << "m10:\n" << m10;

    cout << "\nm9 * m10 = \n";
    matrix m11 = m9 * m10;
    cout << m11;

    cout << "\n\n\nTest 9(m12(i,j));\n\n";

    matrix m12(5, 5);

    cout << "m12;\n" << m12;

    cout << "\nEnter i(0-4): ";
    int i; 
    cin >> i;

    cout << "Enter j(0-4): ";
    int j;
    cin >> j;

    int n = m12(i,j);
    cout << "\nm12(" << i << ")(" << j << ") = " << n;
}



