
#include <iostream>
#include "cstdlib"
#include "ctime"
#include <iomanip>

using namespace std;

// шаблонний клас Matrix
template <typename T>
class Matrix
{
private:
    int m;      // Кількість рядків
    int n;      // Кількість стовбців
    T** ptr;    // Вказівник на масив вказівників 
public:
    Matrix()               // Конструктор за замовченням
    {
        n = 0;
        m = 0;
        ptr = nullptr;
    }
    Matrix(int _m, int _n) // Конструктор з двома параметрами
    {                      // (кількість рядків і кількість стовпчиків)
        m = _m;            // Всі елементи матриці будуть мати значення 0
        n = _n;
        ptr = (T**) new T * [m];

        for (int i = 0; i < m; i++)
            ptr[i] = (T*)new T[n];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ptr[i][j] = 0;
    }
    Matrix(const Matrix& _M)    // Конструктор копіювання. Новий об'єкт буде створено
    {                           // на основі старого, отриманого як параметр.
        m = _M.m;
        n = _M.n;
        ptr = (T**) new T * [m]; 
        for (int i = 0; i < m; i++)
            ptr[i] = (T*) new T[n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ptr[i][j] = _M.ptr[i][j];
    }
    Matrix(Matrix&& _M)         // Конструктор переносу. Новий об'єкт буде створено
    {                           // на основі старого, отриманого як параметр.
        this->ptr = _M.ptr;     // Пам'ять, виділена під поля старого об'єкта, буде
        this->m = _M.m;         // звільнена. 
        this->n = _M.n;

        _M.ptr = nullptr;

        _M.m = 0;
        _M.n = 0;
    }
    Matrix(int _m, int _n, T elem) // Конструктор з двома параметрами(рядки і стовпчики) 
    {                              // і значенням 1 елементу, яке буде присвоєно кожному
        m = _m;                    // елементу матриці. 
        n = _n;
        ptr = (T**) new T * [m];

        for (int i = 0; i < m; i++)
            ptr[i] = (T*)new T[n];

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ptr[i][j] = elem;
    }
    template <typename Q>
    Matrix(Matrix<Q>& _M)      // Метод, що конструює  матрицю з іншої матриці того                  
    {                          // самого розміру, але з відмінним типом елемента.
        m = _M.GetRow();
        n = _M.GetColumn();
        ptr = (T**) new T * [m];
        for (int i = 0; i < m; i++)
            ptr[i] = (T*) new T[n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ptr[i][j] = (T)_M(i, j);
    }
    int GetRow() const      // Метод для отримання кількості рядків 
    {
        return m;
    }
    int GetColumn() const   // Метод для отримання кількості стовпчиків
    {
        return n;
    }

    template <typename Q>
    void operator+(const Q& value)   // Оператор + для додавання скалярної 
    {                                // величини до всіх елементів
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ptr[i][j] += (T)value;
            }
        }
    }
    template <typename Q>
    void operator-(const Q& value)   // Оператор - для віднімання від всіх 
    {                                // елементів скалярної величини
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ptr[i][j] -= (T)value;
            }
        }
    }
    template <typename Q>
    void operator*(const Q& value)   // Оператор * для множення всіх  
    {                                // елементів на скалярну величину 
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ptr[i][j] *= (T)value;
            }
        }
    }
    template <typename Q>
    void operator/(const Q& value)    // Оператор / для ділення всіх  
    {                                 // елементів на скалярну величину 
        if (value == 0)
            return;
        else
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    ptr[i][j] /= (T)value;
                }
            }
        }
    }
    template <typename Q>
    Matrix operator+(Matrix<Q>& _M)       // Перевантажений оператор + для 
    {                                     // складання елементів матриць
        if (_M.GetRow() == this->m && _M.GetColumn() == this->n)
        {
            Matrix Result(_M.GetRow(), _M.GetColumn());

            for (int i = 0; i < _M.GetRow(); i++)
            {
                for (int j = 0; j < _M.GetColumn(); j++)
                {
                    Result.ptr[i][j] = this->ptr[i][j] + (T)_M(i, j);
                }
            }
            return Result;
        }
        else return *this;
    }
    template <typename Q>
    Matrix operator-( Matrix<Q>& _M)   // Перевантажений оператор - для 
    {                                  // віднімання елементів матриць
        if (_M.GetRow() == this->m && _M.GetColumn() == this->n)
        {
            Matrix Result(_M.GetRow(), _M.GetColumn());

            for (int i = 0; i < _M.GetRow(); i++)
            {
                for (int j = 0; j < _M.GetColumn(); j++)
                {
                    Result.ptr[i][j] = this->ptr[i][j] - (T)_M(i, j);
                }
            }
            return Result;
        }
        else return *this;
    }
    template <typename Q>
    Matrix operator*( Matrix<Q>& _M)   // Перевантажений оператор * для 
    {                                  // множення елементів матриць
        if (_M.GetRow() == this->m && _M.GetColumn() == this->n)
        {
            Matrix Result(_M.GetRow(), _M.GetColumn());

            for (int i = 0; i < _M.GetRow(); i++)
            {
                for (int j = 0; j < _M.GetColumn(); j++)
                {
                    Result.ptr[i][j] = this->ptr[i][j] * (T)_M(i, j);
                }
            }
            return Result;
        }
        else return *this;
    }
    template <typename Q>
    Matrix operator/( Matrix<Q>& _M)   // Перевантажений оператор / для 
    {                                  // ділення елементів матриць
        if (_M.GetRow() == this->m && _M.GetColumn() == this->n)
        {
            Matrix Result(_M.GetRow(), _M.GetColumn());

            for (int i = 0; i < _M.GetRow(); i++)
            {
                for (int j = 0; j < _M.GetColumn(); j++)
                {
                    if ((T)_M(i, j) != 0)
                        Result.ptr[i][j] = this->ptr[i][j] / (T)_M(i, j);
                    else Result.ptr[i][j] = this->ptr[i][j];
                }
            }
            return Result;
        }
        else return *this;
    }

    template <int _m, int _n>
    Matrix ChangeSize()               // Метод для змінення розмірів матриці
    {
        if (_m > m && _n > n)
        {
            Matrix tmp(_m, _n);
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    tmp(i, j) = this->ptr[i][j];
                }
            }
            return tmp;
        }
        else if (_m < m && _n < n)
        {
            Matrix tmp(_m, _n);
            for (int i = 0; i < _m; i++)
            {
                for (int j = 0; j < _n; j++)
                {
                    tmp(i, j) = this->ptr[i][j];
                }
            }
            return tmp;
        }
    }

    template <typename Q>
    Matrix<Q> ChangeType()      // Метод для змінення типу елементів матриці,
    {                           // повертається нова матриця із заданим типом
        Matrix<Q> Result(m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Result(i, j) = (Q)this->ptr[i][j];
            }
        }
        return Result;       
    }

    Matrix operator=(const Matrix& _M)   // Перевантажений оператор = для копіювання матриць
    {
        if (n > 0)
        {
            for (int i = 0; i < m; i++)
                delete[] ptr[i];
        }
        if (m > 0)
        {
            delete[] ptr;
        }
        m = _M.m;
        n = _M.n;
        ptr = (T**) new T * [m]; 
        for (int i = 0; i < m; i++)
            ptr[i] = (T*) new T[n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ptr[i][j] = _M.ptr[i][j];
        return *this;
    }

    ~Matrix()            // Деструктор
    {
        if (n > 0)
        {
            for (int i = 0; i < m; i++)
                delete[] ptr[i];
        }
        if (m > 0)
            delete[] ptr;
    }

    template <int x1, int y1, int x2, int y2>
    Matrix Submatrix()              // Метод, що реалізує отримання частини матриці,  
    {                               // тобто, матриці, що містить елементи вихідної 
        int m1 = x1;                // матриці з деякого діапазону рядків та стовпчиків.
        int m2 = y1;                
        int n1 = x2;
        int n2 = y2;
        if (m1 < 0)
            m1 = m + m1;
        if (m2 < 0)
            m2 = m + m2;
        if (n1 < 0)
            n1 = n + n1;
        if (n2 < 0)
            n2 = n + n2;
        if (m1 > m2 && n1 > n2)
        {
            Matrix Result(n1 - n2 + 1, m1 - m2 + 1);
            for (int i = 0; i < Result.m; i++)
            {
                for (int j = 0; j < Result.n; j++)
                {
                    Result.ptr[i][j] = this->ptr[i + m2][j + n2];
                }

            }
            for (int i = 0; i < Result.m; i++)
            {
                for (int j = 0; j < Result.n / 2; j++)
                {
                    T tmp = Result.ptr[i][j];
                    Result.ptr[i][j] = Result.ptr[i][Result.n - j - 1];
                    Result.ptr[i][Result.n - j - 1] = tmp;
                }
            }
            for (int i = 0; i < Result.m / 2; i++)
            {
                for (int j = 0; j < Result.n; j++)
                {
                    T tmp = Result.ptr[i][j];
                    Result.ptr[i][j] = Result.ptr[Result.m - i - 1][j];
                    Result.ptr[Result.m - i - 1][j] = tmp;
                }
            }
            return Result;
        }
        Matrix Result(m2 - m1 + 1, n2 - n1 + 1);
        for (int i = 0; i < Result.m; i++)
        {
            for (int j = 0; j < Result.n; j++)
            {
                Result.ptr[i][j] = this->ptr[i + m1][j + n1];
            }
        }
        return Result;
    }
    template <typename Q>
    void Input(int indexI, int indexJ, Matrix<Q> M )      // Метод для вставки однієї матриці
    {                                                     // в іншу. (без розширення матриці)
        if (indexI + M.GetRow() > m || indexJ + M.GetColumn() > n)
            return;
        else if (indexI < 0 || indexJ < 0)
            return;
        else 
        {
            
            for (int i = 0; i < M.GetRow(); i++)
            {
                for (int j = 0; j < M.GetColumn(); j++)
                {
                    ptr[indexI + i][indexJ + j] = (T)M(i, j);
                }
            }
        }
    }
    template <int indexI, int indexJ>
    Matrix Insert(Matrix M)             // Метод для вставки однієї матриці
    {                                   // в іншу. (з розширенням матриці)
        if (indexI < 0 || indexJ < 0)
            return *this;
        
        if (indexI + M.GetRow() > m || indexJ + M.GetColumn() > n)
        {
            const int _m = indexI + M.GetRow();
            const int _n = indexJ + M.GetColumn();
            Matrix tmp(_m, _n);
            
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    tmp.ptr[i][j] = this->ptr[i][j];
                }
            }
            tmp.Input(indexI, indexJ, M);
            return tmp; 
        }
        else 
        {
            Input(indexI, indexJ, M);
            return *this;
        }
    }
    Matrix Mutiply(const Matrix& M1, const Matrix& M2) const   // Метод, що реалізує алгоритм 
    {                                                          // матричного множення
        Matrix Result(M1.m, M2.n);
        for (int row = 0; row < M1.m; row++)
        {
            for (int col = 0; col < M2.n; col++)
            {
                for (int inner = 0; inner < M2.m; inner++)
                {
                    Result.ptr[row][col] += M1.ptr[row][inner] * M2.ptr[inner][col];
                }
            }
        }
        return Result;
    }
    friend ostream& operator<<(ostream& os, Matrix& _M)    // Перевантажений оператор <<
    {                                                      // для виведення матриці на екран
        for (int i = 0; i < _M.m; i++)
        {
            for (int j = 0; j < _M.n; j++)
            {
                cout << setw(6) << _M.ptr[i][j] << " ";
            }
            cout << endl;
        }

        return os; 
    }
    friend istream& operator >> (istream& is, Matrix& _M)  // Перевантажений оператор <<
    {                                                      // для введення даних в матрицю 
        cout << "\nEnter " << _M.m * _M.n << " elements: " << endl;
        for (int i = 0; i < _M.m; i++)
        {
            for (int j = 0; j < _M.n; j++)
            {
                cin >> _M.ptr[i][j];
            }
        }
        return is;
    }
    T& operator()(int i, int j)             // Перевантажений оператор (), забезпечує доступ
    {                                       // до елементів матриці за індексами. Працює як
        if ((m > 0) && (n > 0))             // на отримання елементів, так і на встановлення
        {
            if (i >= 0 && j >= 0)
                return ptr[i][j];
            else if (i < 0 && j >= 0)
                return ptr[m + i - 1][j];
            else if (i >= 0 && j < 0)
                return ptr[i][n + j];
            else if (i < 0 && j < 0)
                return ptr[m + i - 1][n + j - 1];
        }
    }
    void Search(T elem, int& _i, int& _j)   // ДОДАТКОВО Метод для пошуку заданого елемента.
    {                                       // Знаходить востаннє зустрінутий заданий елемент.
        _i = -1;                            // Повертає індекси в змінні,  посилання на які
        _j = -1;                            // передаються як параметри в метод. Якщо елемент
        for (int i = 0; i < m; i++)         // не знайдено, повертає в ці змінні -1 і -1. 
        {                                   
            for (int j = 0; j < n; j++)     
            {
                if (ptr[i][j] == elem)
                {
                    _i = i;
                    _j = j;
                    break;
                }
            }
        }
        
    }
    void SortRows(int choice)           // Метод для сортування рядків. При вказанні 
    {                                   // параметра 1 сортує за зростанням, а при
        if (choice == 1)                // вказанні параметра 2 сортує за спаданням
        {                               // Використовується сортування бульбашкою оО()
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = n - 1; k > j; k--)
                    {
                        if (ptr[i][k - 1] > ptr[i][k])
                        {
                            T tmp = ptr[i][k - 1];
                            ptr[i][k - 1] = ptr[i][k];
                            ptr[i][k] = tmp;
                        }
                    }
                }
            }
        }
        else if (choice == 2)  
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    for (int k = n - 1; k > j; k--)
                    {
                        if (ptr[i][k - 1] < ptr[i][k])
                        {
                            T tmp = ptr[i][k - 1];
                            ptr[i][k - 1] = ptr[i][k];
                            ptr[i][k] = tmp;
                        }
                    }
                }
            }
        }
        else return;
        
    }
    void SortColumns(int choice)                // Метод для сортування стовпців. При вказанні 
    {                                           // параметра 1 сортує за зростанням, а при
        if (choice == 1)                        // вказанні параметра 2 сортує за спаданням
        {                                       // Використовується сортування бульбашкою оО()
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    for (int k = m - 1; k > j; k--)
                    {
                        if (ptr[k - 1][i] > ptr[k][i])
                        {
                            T tmp = ptr[k - 1][i];
                            ptr[k - 1][i] = ptr[k][i];
                            ptr[k][i] = tmp;
                        }
                    }
                }
            }
        }
        else if (choice == 2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    for (int k = m - 1; k > j; k--)
                    {
                        if (ptr[k - 1][i] < ptr[k][i])
                        {
                            T tmp = ptr[k - 1][i];
                            ptr[k - 1][i] = ptr[k][i];
                            ptr[k][i] = tmp;
                        }
                    }
                }
            }
        }
        else return;
    }
    void SortMatrix(int choice)             // Метод для сортування всієї матриці.
    {                                       // При вказанні параметра 1 сортує за 
        int* tmp = new int[m * n];          // зростанням, а при вказанні параметра 
        int k = 0;                          // 2 сортує за спаданням. Використовується
        for (int i = 0; i < m; i++)         // сортування бульбашкою оО()
        {
            for (int j = 0; j < n; j++)
            {
                tmp[k++] = ptr[i][j];
            }
        }
        if (choice == 1)
        {
            for (int i = 0; i < m * n; i++)
            {
                for (int j = m * n - 1; j > i; j--)
                {
                    if (tmp[j - 1] > tmp[j])
                    {
                        T x = tmp[j - 1];
                        tmp[j - 1] = tmp[j];
                        tmp[j] = x;
                    }
                }
            }
        }
        else if (choice == 2)
        {
            for (int i = 0; i < m * n; i++)
            {
                for (int j = m * n - 1; j > i; j--)
                {
                    if (tmp[j - 1] < tmp[j])
                    {
                        T x = tmp[j - 1];
                        tmp[j - 1] = tmp[j];
                        tmp[j] = x;
                    }
                }
            }
        }
        k = 0; 
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ptr[i][j] = tmp[k++];
            }
        }
    }
};

int main()
{
    int i;          // Змінна для вибору пункту тестування. 
    while (true)            // Тестування програми. Після введення відповідного значення
    {                       // в консоль виводяться результати тестування відповідних 
        system("cls");      // методів класу. 
        cout << " 1:  Matrix construction" << endl;          
        cout << " 2:  Transformation(creation)" << endl;
        cout << " 3:  Access by coordinates" << endl;
        cout << " 4:  Rows/Columns." << endl;
        cout << " 5:  + - * / value (scalar or matrix)" << endl;
        cout << " 6:  Matrix multiplication" << endl;
        cout << " 7:  Element type conversion" << endl;
        cout << " 8:  Changing the dimensions" << endl;
        cout << " 9:  Obtaining part of the matrix" << endl;
        cout << "10: Insertion of the matrix(no extension) " << endl;
        cout << "11: Insertion one matrix to another(with extension)" << endl;
        cout << "12: Search the element in the matrix" << endl;
        cout << "13: Sort rows" << endl;
        cout << "14: Sort columns" << endl;
        cout << "15: Sort matrix" << endl;
        cout << " 0: Close the program" << endl;
        cin >> i;

        if (i == 1)
        {
            system("cls");          
            Matrix<int> M1(3, 3);
            cin >> M1;
            cout << "\nM1" << endl;
            cout << M1;

            Matrix<float> M2(3, 3, 4.5);
            cout << "\nM2" << endl;
            cout << M2;

            Matrix<int> M3(M1);
            cout << "\nM3" << endl;
            cout << M3;

            Matrix<int> M4(move(M1));
            cout << "\nM4" << endl;
            cout << M4;

            cout << "\nM1" << endl;
            cout << M1;

            system("pause");
        }
        else if (i == 2)
        {
            system("cls");
            Matrix<float> M1(3, 3, 4.5);
            cout << "<float>M1" << endl;
            cout << M1;

            Matrix<int> M2(M1);
            cout << "\n<int>M2, transformed M1" << endl;
            cout << M2;
            system("pause");
        }
        else if (i == 3)
        {
            system("cls");
            Matrix<int> M(4,5);
            for (int i = 0; i < M.GetRow(); i++)
            {
                for (int j = 0; j < M.GetColumn(); j++)
                {
                    M(i, j) = rand() % 20;
                }
            }
            cout << "M" << endl;
            cout << M;
            cout << "\nM[2][1] = " << M(2, 1) << endl;
            cout << "M[-1][3] = " << M(-1, 3) << endl;
            cout << "M[3][-1] = " << M(3, -1) << endl;
            cout << "M[-2][-2] = " << M(-2, -2) << endl;
            system("pause");
        }
        else if (i == 4)
        {
            system("cls");
            Matrix<int> M(3, 7);
            for (int i = 0; i < M.GetRow(); i++)
            {
                for (int j = 0; j < M.GetColumn(); j++)
                {
                    M(i, j) = rand() % 20;
                }
            }
            cout << "M" << endl;
            cout << M;
            cout << "\nNumber of rows:    " << M.GetRow() << endl;
            cout << "Number of columns: " << M.GetColumn() << endl;
            system("pause");
        }
        else if (i == 5)
        {
            system("cls");
            Matrix<double> M1(2, 4);
            for (int i = 0; i < M1.GetRow(); i++)
            {
                for (int j = 0; j < M1.GetColumn(); j++)
                {
                    M1(i, j) = rand() % 20 + 0.5;
                }
            }
            cout << "M1" << endl;
            cout << M1;
            cout << "\nM1 + 2" << endl;
            M1 + 2;
            cout << M1;

            cout << "\nM1 - 1" << endl;
            M1 -1;
            cout << M1;

            cout << "\nM1 * 3" << endl;
            M1 * 3;
            cout << M1;

            cout << "\nM1 / 5" << endl;
            M1 / 5;
            cout << M1;
            
            cout << "____________________________________" << endl;
            cout << "\nM1" << endl;
            cout << M1;

            Matrix<double> M2(2, 4, 3);
            cout << "\nM2" << endl;
            cout << M2;

            cout << "\nM1 + M2" << endl;
            Matrix<double> M3 = M1 + M2;
            cout << M3;

            cout << "\nM1 - M2" << endl;
            Matrix<double> M4 = M1 - M2;
            cout << M4;

            cout << "\nM1 * M2" << endl;
            Matrix<double> M5 = M1 * M2;
            cout << M5;

            cout << "\nM1 / M2" << endl;
            Matrix<double> M6 = M1 / M2;
            cout << M6;

            system("pause");
        }
        else if (i == 6)
        {
            system("cls");
            Matrix<int> M1(3, 2);
            M1(0, 0) = 1; M1(0, 1) = 2; 
            M1(1, 0) = 3; M1(1, 1) = 4; 
            M1(2, 0) = 5; M1(2, 1) = 6; 
            cout << "M1" << endl;
            cout << M1;

            Matrix<int> M2(2, 3);
            M2(0, 0) = 7; M2(0, 1) = 8; M2(0, 2) = 9;
            M2(1, 0) = 10; M2(1, 1) = 11; M2(1, 2) = 12;
            cout << "\nM2" << endl;
            cout << M2;

            cout << "\nM3 = M1 * M2";
            Matrix<int> M3 = M1.Mutiply(M1, M2);
            cout << "\nM3" << endl;
            cout << M3;

            system("pause");
        }
        else if (i == 7)
        {
            system("cls");
            Matrix<char> M1(3, 3);
            for (int i = 0; i < M1.GetRow(); i++)
            {
                for (int j = 0; j < M1.GetColumn(); j++)
                {
                    M1(i, j) = rand() % 6 + 1;
                }
            }
            cout << "M1<char>" << endl;
            cout << M1;

            Matrix<int> M2 = M1.ChangeType<int>();
            cout << "\nM2<int>, converted from M1" << endl;
            cout << M2;
            system("pause");
        }
        else if (i == 8)
        {
            system("cls");
            Matrix<int> M1(2, 2);
            for (int i = 0; i < M1.GetRow(); i++)
            {
                for (int j = 0; j < M1.GetColumn(); j++)
                {
                    M1(i, j) = rand() % 15;
                }
            }
            cout << "M1, 2x2" << endl;
            cout << M1;

            Matrix<int> M2 = M1.ChangeSize<4, 7>();
            cout << "\nM2, 4x7, from M1" << endl;
            cout << M2;

            Matrix<int> M3 = M2.ChangeSize<1, 3>();
            cout << "\nM3, 1x3, from M2" << endl;
            cout << M3;
            system("pause");
        }
        else if (i == 9)
        {
            system("cls");
            int k = 0;
            Matrix<int> M1(4, 5);
            for (int i = 0; i < M1.GetRow(); i++)
            {
                for (int j = 0; j < M1.GetColumn(); j++)
                {
                    M1(i, j) = ++k;
                }
            }
            cout << "M1" << endl;
            cout << M1;
            
            Matrix<int> M2 = M1.Submatrix<1, 2, 2, 4>();
            cout << "\nM2, M1.Submatrix<1, 2, 2, 4>()" << endl;
            cout << M2;

            Matrix<int> M3 = M1.Submatrix<2, -1, 1, -2 >();
            cout << "\nM3, M1.Submatrix<2, -1, 1, -2>()" << endl;
            cout << M3;

            Matrix<int> M4 = M1.Submatrix<1, 0, 2, 1>();
            cout << "\nM4, M1.Submatrix<1, 0, 2, 1>()" << endl;
            cout << M4;
            system("pause");
        }
        else if (i == 10)
        {
            system("cls");
            int k = 0;
            Matrix<int> M1(4, 5);
            for (int i = 0; i < M1.GetRow(); i++)
            {
                for (int j = 0; j < M1.GetColumn(); j++)
                {
                    M1(i, j) = ++k;
                }
            }
            cout << "M1" << endl;
            cout << M1;

            Matrix<int> M2(2, 2);
            cout << "\nM2" << endl;
            M2(0, 0) = 1111; M2(0, 1) = 1111;
            M2(1, 0) = 1111; M2(1, 1) = 1111;
            cout << M2;

            M1.Input(1, 2, M2);
            cout << "\nM1, M1.Input(1, 2, M2)" << endl;
            cout << M1;
            system("pause");
        }
        else if (i == 11)
        {
            system("cls");
            int k = 0;
            Matrix<int> M1(4, 5);
            for (int i = 0; i < M1.GetRow(); i++)
            {
                for (int j = 0; j < M1.GetColumn(); j++)
                {
                    M1(i, j) = ++k;
                }
            }
            cout << "M1" << endl;
            cout << M1;

            Matrix<int> M2(2, 2);
            M2(0, 0) = 1111; M2(0, 1) = 1111;
            M2(1, 0) = 1111; M2(1, 1) = 1111;
            cout << "\nM2" << endl;
            cout << M2;

            Matrix<int> M3 = M1.Insert<3, 4>(M2);
            cout << "\nM3, = M1.Insert<3, 4>(M2)" << endl;
            cout << M3;
            system("pause");
        }
        else if (i == 12)
        {
            system("cls");
            Matrix<int> M1(4, 4);
            for (int i = 0; i < M1.GetRow(); i++)
            {
                for (int j = 0; j < M1.GetColumn(); j++)
                {
                    M1(i, j) = rand() % 15;
                }
            }
            cout << "M1" << endl;
            cout << M1;

            int i, j, value;
            cout << "\nWhich element do you want to find?\n";
            cin >> value;

            M1.Search(value, i, j);

            cout << "This element has indexes: " << i << ", " << j << endl;
            system("pause");
        }
        else if (i == 13)
        {
            system("cls");
            Matrix<int> M1(4, 7);
            for (int i = 0; i < M1.GetRow(); i++)
            {
                for (int j = 0; j < M1.GetColumn(); j++)
                {
                    M1(i, j) = rand() % 20;
                }
            }
            cout << "M1" << endl;
            cout << M1;

            M1.SortRows(1);
            cout << "\nM1, sorted rows (ascending)" << endl;
            cout << M1;
            
            M1.SortRows(2);
            cout << "\nM1, sorted rows (descending)" << endl;
            cout << M1;

            system("pause");
        }
        else if (i == 14)
        {
            system("cls");
            Matrix<int> M1(4, 7);
            for (int i = 0; i < M1.GetRow(); i++)
            {
                for (int j = 0; j < M1.GetColumn(); j++)
                {
                    M1(i, j) = rand() % 20;
                }
            }
            cout << "M1" << endl;
            cout << M1;

            M1.SortColumns(1);
            cout << "\nM1, sorted columns (ascending)" << endl;
            cout << M1;

            M1.SortColumns(2);
            cout << "\nM1, sorted columns (descending)" << endl;
            cout << M1;

            system("pause");
        }

        else if (i == 15)
        {
            system("cls");
            Matrix<int> M1(4, 7);
            for (int i = 0; i < M1.GetRow(); i++)
            {
                for (int j = 0; j < M1.GetColumn(); j++)
                {
                    M1(i, j) = rand() % 20;
                }
            }
            cout << "M1" << endl;
            cout << M1;

            M1.SortMatrix(1);
            cout << "\nM1, sorted matrix (ascending)" << endl;
            cout << M1;

            M1.SortMatrix(2);
            cout << "\nM1, sorted matrix (descending)" << endl;
            cout << M1;

            system("pause");
        }
        else if (i == 0)
            break;
    }
}

