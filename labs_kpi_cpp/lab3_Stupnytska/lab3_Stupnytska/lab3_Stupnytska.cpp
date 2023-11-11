#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

using namespace std;

template <typename T>
class Vector
{
private:
    int count;      // Кількість елементів
    T* vect;        // Вказівник на шаблонний динамічний масив
public:
    Vector()                // Конструктор за замовченням
    {
        count = 0;
        vect = nullptr;
    }
    Vector(int _count)      // Конструктор із параметром - кількістю елементів
    {
        count = _count;
        vect = new T[count];
        for (int i = 0; i < count; i++)
            vect[i] = 0;    // За замовченням, всім елементам присоюється 0
    }
    Vector(int _count, T value)     // Конструктор із параметром(кількістю елементів) 
    {                               // та значанням, яке присвоється до всіх елементів
        count = _count;
        vect = new T[count];
        for (int i = 0; i < count; i++)
            vect[i] = T;
    }
    Vector(const Vector& v)     // Конструктор копіювання (копіює дані з полів іншого)
    {                           // вектору 
        count = v.GetCount();
        vect = new T * [count];
        for (int i = 0; i < count; i++)
            vect[i] = (T)v.vect[i];
    }
    Vector(Vector&& v)          // Конструктор переносу (створює новий вектор, поля
    {                           // старого вектора очищаються(визволяється пам'ять))
        vect = v.vect;
        count = v.count;
        v.vect = nullptr;
        v.count = 0;
    }
    template <typename S>
    Vector(Vector<S>& v)        // Метод, що конструює  матрицю з іншої матриці того                  
    {                           // самого розміру, але з відмінним типом елемента.
        count = v.GetCount();
        vect = new T[count];
        for (int i = 0; i < count; i++)
            vect[i] = (T)v.vect[i];
    }
    template <typename S>
    Vector(int n, const S* v)   // Конструктор що створює вектор на основі масиву
    {                           // і його довжини, що передаються як параметр
        count = n;
        vect = new T[count];
        for (int i = 0; i < count; i++)
            vect[i] = (T)v[i];
    }
    int GetCount() const      // Метод отримання розміру вектору (кількості елементів).
    {
        return count;
    }
    T& operator[] (int index) // Перевантажений оператор [], що реалізує доступ
    {                         // за індексом до елемента для читання і запису.
        return vect[index];
    }
    template <typename S>
    void operator+(const S& value)    // Оператор + для додавання скаляру до всіх елементів
    {                                 // Підтримуються різнотипові скалярні величини. 
        for (int i = 0; i < count; i++)
            vect[i] += T(value);
    }
    template <typename S>
    void operator-(const S& value)    // Оператор - для віднімання скаляру від всіх елементів
    {                                 // Підтримуються різнотипові скалярні величини. 
        for (int i = 0; i < count; i++)
            vect[i] -= T(value);
    }
    template <typename S>
    void operator*(const S& value)    // Оператор * для множення всіх елементів на скаляр
    {                                 // Підтримуються різнотипові скалярні величини. 
        for (int i = 0; i < count; i++)
            vect[i] *= T(value);
    }
    template <typename S>
    void operator/(const S& value)    // Оператор / для ділення всіх елементів на скаляр
    {                                 // Підтримуються різнотипові скалярні величини. 
        if (value == 0)    // Перевірка, чи не є скаляр нулем. 
            return;
        else
            for (int i = 0; i < count; i++)
                vect[i] /= T(value);
    }
    template <typename S>
    void operator+(Vector<S> v)    // Оператор + для додавання векторів поелементно.
    {                              // Підтримуються різнотипові вектори величини. 
        for (int i = 0; i < count; i++)
            vect[i] = vect[i] + T(v[i]);
    }
    template <typename S>
    void operator-(Vector<S> v)    // Оператор - для поелементної різниці векторів.
    {                              // Підтримуються різнотипові вектори величини. 
        for (int i = 0; i < count; i++)
            vect[i] = vect[i] - T(v[i]);
    }
    template <typename S>
    void operator*(Vector<S> v)    // Оператор * для поелементного множення векторів.
    {                              // Підтримуються різнотипові вектори величини. 
        for (int i = 0; i < count; i++)
            vect[i] = vect[i] * T(v[i]);
    }
    template <typename S>
    void operator/ (Vector<S> v)    // Оператор / для поелементного ділення векторів.
    {                               // Підтримуються різнотипові вектори величини. 
        for (int i = 0; i < count; i++)
        {
            if (T(v[i]) != 0)
                vect[i] = vect[i] / T(v[i]); // Перевірка, чи не є значення нулем. 
            else vect[i] = vect[i];
        }
    }
    template <int size>
    Vector Resize()             // Метод для отримання нового вектору на  
    {                           // базі існуючого, але різного розміру
        if (count > size)   
        {
            Vector res(size);
            for (int i = 0; i < size; i++)
                res[i] = vect[i];
            return res;
        }
        else if (count < size)
        {
            Vector res(size);
            for (int i = 0; i < count; i++)
                res[i] = vect[i];
            return res;
        }
        else if (size < 0)
        {
            Vector res;
            return res;
        }
        else
        {
            return *this;
        }
    }
    template <typename S>
    Vector<S> Convert()             // Метод для перетворення типу вектору
    {
        Vector<S> res(count);
        for (int i = 0; i < count; i++)
            res[i] = (S)vect[i];
        return res;
    }
    Vector operator=(const Vector& v)   // Перевантажений оператор = для копіювання матриць
    {
        if (v == *this)
            return *this;
        if (count > 0)
            delete[] vect;
        count = v.GetCount();
        vect = new T[count];
        for (int i = 0; i < count; i++)
            vect[i] = v[i];
        return *this;
    }
    void Reversal()        // Додактово, метод для розвороту вектору
    {
        for (int i = 0; i < count / 2; i++)
        {
            T tmp = vect[i];
            vect[i] = vect[count - i - 1];
            vect[count - i - 1] = tmp;
        }
    }
    void Add(T elem)        // Додактово, метод для додавання нового елементу в кінець вектора
    {                       
        Vector res(count + 1);
        for (int i = 0; i < count; i++)
            res[i] = vect[i];
        res[count] = elem;
        
        count = res.GetCount();
        for (int i = 0; i < count; i++)
            vect[i] = res[i];

        delete[] res.vect;
    }
    bool IsEmty()           // Додактово, метод для перевірки вектору на порожність 
    {
        if (vect == nullptr)
            return true;
        else return false;
    }
    void Delete(int index)  // Додактово, метод для видалення елементу за заданим індексом 
    {
        Vector res(count - 1);
        int k = 0;
        for (int i = 0; i < count; i++) 
        {
            if (i == index)
                k++;
            res[i] = vect[i + k];
        }
        
        count = res.GetCount();
        vect = res.vect;
    }
    template <int n1, int n2>
    Vector Slice()         // Метод для отримання зрізу ветору      
    {
        if ((n1 >= 0 && n2 >= 0) && (n1 < n2))
        {
            int number = n2 - n1 + 1;
            Vector result(number);

            int j = 0;
            for (int i = n1; i <= n2; i++)
            {
                result.vect[j++] = vect[i];
            }
            return result;
        }
        else if ((n1 >= 0 && n2 >= 0) && (n1 > n2))
        {
            int number = n1 - n2 +1;
            Vector result(number);
            int j = 0;
            for (int i = n2; i <= n1; i++)
            {
                result.vect[j++] = vect[i];
            }

            result.Reversal();
            return result;
        }
        else if (n2 < 0 && n1 >= 0)
        {
            int number = count + n2 - n1 + 1;
            Vector result(number);
            int j = 0;
            for (int i = n1; i <= count + n2 + 1; i++)
            {
                result.vect[j++] = vect[i];
            }
            return result;
        }
        else return *this;
    }
    template <typename S> // Зважена сума елементів векторів однакового розміру
    Vector WeightedSum(Vector<T> v1, double a, Vector<S> v2, double b)
    {
        if (v1.GetCount() >= v2.GetCount())
        {
            Vector res(v1.GetCount());
            for (int i = 0; i < v2.GetCount(); i++)
                res[i] = v1[i] * a + (T)v2[i] * b;
            for (int i = v2.GetCount(); i < v1.GetCount(); i++)
                res[i] = v1[i];
            return res;
        }
        else 
        {
            Vector res(v2.GetCount());
            for (int i = 0; i < v1.GetCount(); i++)
                res[i] = v1[i] * a + (T)v2[i] * b;
            for (int i = v1.GetCount(); i < v2.GetCount(); i++)
                res[i] = v2[i];
            return res;
        }
    }
    Vector Concat(Vector v)  // Конкатенація двох векторів, що породжує вектор більшого розміру 
    {
        if (count >= v.GetCount())
        {
            Vector res(count + v.GetCount());

            for (int i = 0; i < count; i++)
                res[i] = vect[i];
            int j = 0;
            for (int i = count; i < res.GetCount(); i++)
                res[i] = v[j++];
            return res;
        }
        else 
        {
            Vector res(count + v.GetCount());
            
            for (int i = 0; i < v.GetCount(); i++)
                res[i] = v[i];
            int j = 0; 
            for (int i = v.GetCount(); i < res.GetCount(); i++)
                res[i] = vect[j++];
            return res;
        }
    }
    void Sort_Ascending()  // Додатково, сортування вектору за зростанням
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = count - 1; j > i; j--)
            {
                if (vect[j - 1] > vect[j])
                {
                    T tmp = vect[j - 1];
                    vect[j - 1] = vect[j];
                    vect[j] = tmp;
                }
            }
        }
    }
    void Sort_Descending()  // Додатково, сортування вектору за спаданням
    {
        for (int i = 0; i < count; i++)
        {
            for (int j = count - 1; j > i; j--)
            {
                if (vect[j - 1] < vect[j])
                {
                    T tmp = vect[j - 1];
                    vect[j - 1] = vect[j];
                    vect[j] = tmp;
                }
            }
        }
    }
    int Search(T value)     // Додатково, пошук заданого елементу в векторі. Повертається індекс.
    {                       // Якщо заданий елемент відсутній у векторі, повертається -1.
        for (int i = 0; i < count; i++)
            if (vect[i] == value)
                return i;
        return -1;
    }
    friend ostream& operator<<(ostream& os, Vector& v)    // Перевантажений оператор <<
    {                                                     // для виведення вектору
        for (int i = 0; i < v.GetCount(); i++)
            cout << setw(6) << v[i];
        cout << endl;
        return os;
    }
    friend istream& operator >> (istream& is, Vector& v)  // Перевантажений оператор <<
    {                                                     // для введення елементів вектору
        cout << "\nEnter " << v.GetCount() << " elements: " << endl;
        for (int i = 0; i < v.GetCount(); i++)
        {
            cout << "vect[" << i << "]: ";
            cin >> v[i];
        }
        return is;
    }
};
//========================================================================================//
//========================================================================================//
int main()
{
    // Тестування класу Vector.  
    cout << "---------------------1----------------------" << endl;
    cout << "   Vector creation" << endl << endl;
    cout << "Default constructor:" << endl;
    Vector<int> v1;
    cout << "v1:" << endl << v1;

    cout << "Constructor with 1 parameter:" << endl;
    Vector<int> v2(4);
    cout << "v2:" << endl << v2;
    cout << "Enter the int elements of vector v2." << endl;
    cin >> v2;
    cout << endl;

    cout << "Copy constructor:" << endl;
    Vector<int> v3(v2);
    cout << "v3:" << endl << v3 << endl;

    cout << "Move constructor:(from v2 to v4)" << endl;
    Vector<int> v4(move(v2));
    cout << "v4:" << endl << v4 << endl;
    bool empty = v2.IsEmty();
    empty == true ? cout << "v2 is empty.\n": cout << "v2 is NOT empty.\n";
    
    system("pause");
    cout << "---------------------2----------------------" << endl;
    cout << "   Transformation of vector from another one" << endl;
    Vector<float> v5(4);
    v5[0] = 1.33; v5[1] = 4.12; v5[2] = 2.32; v5[3] = 8.78;
    cout << "v5" << endl << v5 << endl;

    Vector<int> v6 = v5.Convert<int>();
    cout << "v6" << endl << v6 << endl;

    system("pause");
    cout << "---------------------3----------------------" << endl;
    cout << "Access: v6[2] = " << v6[2] << endl;
    cout << "Change: v6[2] = 77" << endl;
    v6[2] = 77;
    cout << "v6" << endl << v6 << endl;

    system("pause");

    cout << "---------------------4----------------------" << endl;
    cout << "v6.GetCount() = " << v6.GetCount() << endl << endl;

    system("pause");
    cout << "---------------------5----------------------" << endl;

    cout << "Vector + scalar" << endl;
    cout << "v6" << endl << v6 << endl;

    cout << "v6 + 3" << endl;
    v6 + 3;
    cout << v6 << endl;

    cout << "v6 - 1" << endl;
    v6 - 1;
    cout << v6 << endl;

    cout << "v6 * 4" << endl;
    v6 * 4;
    cout << v6 << endl;

    cout << "v6 / 2" << endl;
    v6 / 2;
    cout << v6 << endl;
    system("pause");
    cout << "---------------" << endl;

    cout << "Vector + Vector" << endl;

    Vector<double> v7(4);
    cout << "Input v7 (double): " << endl;
    cin >> v7;
            
    cout << "v6" << endl << v6 << endl;
    cout << "v7" << endl << v7 << endl;

    cout << "v6 + v7" << endl;
    v6 + v7;
    cout << v6 << endl;

    cout << "v6 - v7" << endl;
    v6 - v7;
    cout << v6 << endl;

    cout << "v6 * v7" << endl;
    v6 * v7;
    cout << v6 << endl;

    cout << "v6 / v7" << endl;
    v6 / v7;
    cout << v6 << endl;
    system("pause");
    cout << "---------------------6----------------------" << endl;
    cout << "v6" << endl << v6 << endl;

    cout << "v6.Resize<8>(), v6.Resize<3>()" << endl;
    Vector<int> v8= v6.Resize<8>();
    cout << "v8" << endl << v8 << endl;

    Vector<int> v9 = v6.Resize<3>();
    cout << "v9" << endl << v9 << endl;
    system("pause");

    cout << "---------------------7----------------------" << endl;
    Vector<int> v10(7);
    v10[0] = 1; v10[1] = 2; v10[2] = 3; v10[3] = 4; 
    v10[4] = 5; v10[5] = 6; v10[6] = 7;
    cout << "v10" << endl << v10 << endl;

    Vector <int> v11(v10.Slice<2, 4>());
    cout << "v11 = v10.Slice<2, 4>()" << endl << v11 << endl; 

    Vector <int> v12(v10.Slice<1, -2>());
    cout << "v12 = v10.Slice<1, -2>()" << endl << v12 << endl;

    Vector <int> v13(v10.Slice<5, 2>());
    cout << "v13 = v10.Slice<5, 2>()" << endl << v13 << endl;
    system("pause");

    cout << "---------------------8----------------------" << endl;
    cout << "Weighted sum:" << endl;
    Vector<float> _v1(4);
    _v1[0] = 5.5; _v1[1] = 3.5; _v1[2] = 7.5; _v1[3] = 1.25;
            cout << "_v1:" << endl << _v1 << endl;


    Vector<float> _v2(4);
    _v2[0] = 3.15; _v2[1] = 5.25; _v2[2] = 0.75; _v2[3] = 4.45;
    cout << "_v2:" << endl << _v2 << endl;
            
    float a = 2;
    float b = 3;

    Vector<float> sum = _v1.WeightedSum(_v1, a, _v2, b);
    cout << "Weighted sum:" << endl << sum << endl;
    system("pause");

    cout << "---------------------9----------------------" << endl;
    _v2.Add(5.45);
    cout << "_v1:" << endl << _v1 << endl;
    cout << "_v2:" << endl << _v2 << endl;

    Vector<float> concat = _v1.Concat(_v2);
    cout << "Concatination:" << endl << concat << endl;
    system("pause");

    cout << "---------------------10-----(additional)--------------------------" << endl;
    int array[10] = { 1,3,2,4,6,5,8,7,10,9 };

    Vector<int> test(10, array);
    cout << "Vector: \n" << test << endl;

    test.Add(15);
    cout << "Add(15) \n" << test << endl;
    system("pause");

    cout << "---------------------11-----(additional)--------------------------" << endl;

    test.Delete(2);
    cout << "Delete(2) \n" << test << endl;
    system("pause");

    cout << "---------------------12-----(additional)--------------------------" << endl;

    test.Reversal();
    cout << "Reversal() \n" << test << endl;
    system("pause");

    cout << "---------------------13-----(additional)--------------------------" << endl;

    test.Sort_Ascending();
    cout << "Sort_Ascending() \n" << test << endl;
    system("pause");

    cout << "---------------------14-----(additional)--------------------------" << endl;

    test.Sort_Descending();
    cout << "Sort_Descending() \n" << test << endl;
    system("pause");

    cout << "---------------------15-----(additional)--------------------------" << endl;

    char arr[10] = { 'a','b','c','d','e','f','g','h','i','j' };
    Vector<char> test2(10, arr);
    cout << "Vector: \n" << test2 << endl;

    int i = test2.Search('e');
    cout << "test2.Search('e'); i =  " << i << endl << endl;

    cout << "-------------------KV-12_Stupnytska_Sofiya-------------------------" << endl;

}