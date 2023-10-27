// 20.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "Task1\n\n";
    int arr1[3] = {17, 18, 19};
    int arr2[7] = {9, 13, 15, 18, 19, 21, 27 };

    vector<int>::iterator pb;
    ostream_iterator<int> out(cout, " ");
    vector<int> A(arr1, arr1 + 3);
    cout << "Vector A:\n";
    copy(A.begin(), A.end(), out);
    vector<int> B(arr2, arr2 + 7);
    cout << "\nVector B:\n";
    copy(B.begin(), B.end(), out);
    vector<int> C;

    for (pb = A.begin(); pb != A.end(); pb += 1)
    {
        if (find(B.begin(), B.end(), *pb) != B.end() == false)
            C.push_back(*pb);
    }
    for (pb = B.begin(); pb != B.end(); pb += 1)
    {
        if (find(A.begin(), A.end(), *pb) != A.end() == false)
            C.push_back(*pb);
    }
    cout << "\nVector C:\n";
    copy(C.begin(), C.end(), out);


    cout << "\n\n\n\nTask2\n\n";
    int arr3[10] = { 4, 17, 11, 101, 21, 18, 19, 7, 2, 23 };
    vector<int> vect(arr3, arr3 + 10);
    cout << "Vector:\n";
    copy(vect.begin(), vect.end(), out);
    vector<int> tmp;
    for (pb = vect.begin(); pb != vect.end(); pb += 1)
    {
        int counter = 0;
        for (int i = 1; i <= *pb; i++)
        {
            if (*pb % i == 0)
                counter++;
        }
        if (counter > 2)
            tmp.push_back(*pb);
    }
    vect = tmp;
    tmp.clear();
    cout << "\nResult:\n";
    copy(vect.begin(), vect.end(), out);


    cout << "\n\n\n\nTask3\n\n";
    int arr4[16] = { 4, 17, -11, 101, 0, -18, 19, 7, 2, 23, 0, 3, -9, 15, 0, -1 };
    vector<int> vect2(arr4, arr4 + 16);
    cout << "Vector:\n";
    copy(vect2.begin(), vect2.end(), out);

    vector<int> positive;
    vector<int> negative;
    vector<int> zero;
    for (pb = vect2.begin(); pb != vect2.end(); pb += 1)
    {
        if (*pb > 0)
            positive.push_back(*pb);
        else if (*pb < 0)
            negative.push_back(*pb);
        else 
            zero.push_back(*pb);
    }

    cout << "\n\nVector with positive elements:\n";
    copy(positive.begin(), positive.end(), out);
    cout << "\nVector with negative elements:\n";
    copy(negative.begin(), negative.end(), out);
    cout << "\nVector with zero elements:\n";
    copy(zero.begin(), zero.end(), out);
}

