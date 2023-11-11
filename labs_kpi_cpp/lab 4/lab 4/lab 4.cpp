#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <string>

using namespace std;

template<typename T>

class String 
{
    typedef typename list<T>::iterator pb;
    list<T>* str;   
public:
    String()  
    {
        str = new list<T>();
    }
    String(int number) 
    {
        str = new list<T>();
        for (int i = 0; i < number; i++)
            str->push_back('1');
    }
    String(String*& s) 
    {
        this = s;
    }
    String(T value, int count) 
    {
        str = new list<T>();
        for (int i = 0; i < count; i++) 
        {
            str->push_back(value);
        }
    }
    String(T* ptr, int size) 
    {
        str = new list<T>();
        for (int i = 0; i < size; i++) 
            str->push_back(ptr[i]);
        
    }
    int GetLength() const 
    {
        return str->size();
    }
    bool IsEmpty() const
    {
        if (str->size() == 0)
            return true;
        else return false;
    }
    void Add(T value)
    {
        str->push_back(value);
    }
    void Clear() 
    {
        str->clear();
    }
    T& operator[](int index) 
    {
        pb p = str->begin();
        for (int i = 0; i < index; i++) 
            p++;
        return *p;
    }
    vector<T> CreateVector()
    {
        vector<T> v;
        for (pb p = str->begin(); p != str->end(); p++)
        {
            v.push_back(*p);
        }
        return v;
    }
    T* CreateArray(int& len)
    {
        T* array = new T[GetLength()];
        pb p = str->begin();
        int i = 0;
        for (; p != str->end(); p++)
        {
            array[i++] = *p;
        }
        len = GetLength();
        return array;

    }
    String<T>* Substring(int index1, int index2) 
    {
        String<T>* s = new String<T>();
        pb p = str->begin();
        for (int i = 0; i < index1; i++) 
            p++;
        for (int i = index1; i <= index2; i++) 
        {
            (*s) + *p;
            p++;
        }
        return s;
    }
    friend ostream& operator<<(ostream& os, String<T> s)    // Перевантажений оператор <<
    {                                                       // для виведення вектору
        pb p = s.str->begin();
        for (; p != s.str->end(); p++)
            cout << *p;
        cout << endl;
        return os;
    }
    friend istream& operator >> (istream& is, String<T> s)  // Перевантажений оператор <<
    {                                                       // для введення елементів вектору
        cout << "\nEnter " << s.GetLength() << " elements: " << endl;
        pb p = s.str->begin();
        for (; p != s.str->end(); p++)
            cin >> *p;

        return is;
    }
    void operator+(T value)
    {
        str->push_back(value);
    }
    void operator+(String<T>* st)
    {

        String<T>* s = st;
        for (pb p = s->str->begin(); p != s->str->end(); p++)
        {
            str->push_back(*p);
        }
    }
    String<T>* operator*(int t) 
    {
        String<T>* s = new String<T>();
        for (int i = 0; i < t; i++) 
        {
            for (pb p = str->begin(); p != str->end(); p++)
            {
                s->str->push_back(*p);
            }
        }
        return s;
    }
    bool operator==(String<T> s) 
    {
        if (s.str->size() != str->size())
        {
            return false;
        }
        for (pb p1 = str->begin(), p2 = s.str->begin(); p1 != str->end(); p1++, p2++)
        {
            if (*p1 != *p2) 
            {
                return false;
            }
        }
        return true;
    }
    bool operator!=(String<T> s) 
    {
        if (s.str->size() != str->size())
        {
            return true;
        }
        for (pb p1 = str->begin(), p2 = s.str->begin(); p1 != str->end(); p1++, p2++) {
            if (*p1 != *p2) 
            {
                return true;
            }
        }
        return false;
    }
    bool operator>(String<T> s) 
    {
        if (s.str->size() > str->size())
        {
            return true;
        }
        for (pb p1 = str->begin(), p2 = s.str->begin(); p1 != str->end(); p1++, p2++)
        {
            if (*p1 < *p2) 
            {
                return false;
            }
        }
        return true;
    }
    bool operator<(String<T> s) 
    {
        if (s.str->size() < str->size())
        {
            return true;
        }
        for (pb p1 = str->begin(), p2 = s.str->begin(); p1 != str->end(); p1++, p2++) 
        {
            if (*p1 > *p2) 
            {
                return false;
            }
        }
        return true;
    }
    
};


void main()
{
    cout << "------------------Test-------------------" << endl;
    cout << "Constructors: |" << endl;
    cout << "(1)" << endl;
    String<char> str1;   //
    str1.Add('a');
    str1.Add('b');
    str1.Add('c');
    cout << str1;

    cout << "(2)" << endl;
    String<char> str2(5);
    cout << str2;

    cout << "(3)" << endl;
    String<char> str3('A', 5);
    cout << str3;

    cout << "(4)" << endl;
    String<char> str4(str3);
    cout << str3;

    cout << "(5)" << endl;
    char ch_arr[16] = { 't', 'h', 'i', 's', ' ', 'i', 's', ' ', 'a', 'n', ' ', 'a', 'r', 'r', 'a', 'y' };
    String<char> str5(ch_arr, 16);
    cout << str5;

    cout << endl << "Methods: |" << endl;
    cout << "(1)" << endl;

    if (str5.IsEmpty() == true)
        cout << "String is clear" << endl;
    else cout << "String is NOT clear" << endl;

    cout << "(2)" << endl;
    cout << "The length of the string \"this is an array\" = " << str5.GetLength() << endl;

    cout << "(3)" << endl;
    str5.Clear();
    if (str5.IsEmpty() == true)
        cout << "String is clear" << endl;

    cout << "(4)" << endl;
    str5.Add(' ');
    str5.Add('X');
    str5.Add('Y');
    str5.Add('Z');
    cout << "\" XYZ\" was addded to the clean string " << endl;
    cout << str5;

    cout << "(5)" << endl;
    cout << "New vector was created from this string" << endl;
    vector<char> v;
    v = str5.CreateVector();
    for (int i = 0; i < v.size(); i++)
        cout << v[i];

    cout << endl << "(6)" << endl;
    int len;
    char* ptr = str5.CreateArray(len);
    cout << "New array was created from this string" << endl;
    for (int i = 0; i < len; i++)
        cout << ptr[i];

    cout << endl << "(7)" << endl;
    str5.Add('U');
    str5.Add('O');
    str5.Add('P');
    cout << str5;
    String<char> str6;
    cout << "Substring(2, 4)" << endl;
    str6 + str5.Substring(2, 4);
    cout << str6;

    cout << endl << "Operations: |" << endl;
    cout << "(1)" << endl;
    String<int> str7(3);
    cin >> str7;
    str7 + 9;
    cout << str7;

    cout << "(2)" << endl;
    String<int> str8;
    str8 + 6;  str8 + 7; str8 + 8;

    cout << "New string: ";
    cout << str8;
    cout << "str7 + str8 = ";
    str7 + &str8;
    cout << str7;

    cout << "(3)" << endl;
    String<int> str9;
    str9 + str7 * 4;
    cout << "str7 * 4 = ";
    cout << str9;
    
    cout << "(4)" << endl;
    char chs1[5] = {'x', 'b', 'c', 'd', 'e'};
    char chs2[5] = { 's', 'b', 'c', 'd', 'e'};

    String<char> s1(chs1, 4);
    String<char> s2(chs2, 4);

    cout << "1st string: " << s1;
    cout << "2nd string: " << s2;
    
    if (s1 < s2)
        cout << "s1 < s2" << endl;
    if (s1 > s2)
        cout << "s1 > s2" << endl;
    if (s1 == s2)
        cout << "s1 == s2" << endl;
    if (s1 != s2)
        cout << "s1 != s2" << endl;

    
}

