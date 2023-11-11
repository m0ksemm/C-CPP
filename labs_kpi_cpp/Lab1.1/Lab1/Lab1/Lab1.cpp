// Lab1.cpp 
//
//КВ-12 Ступницька Софія

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

class Vector2D
{
private:
    double x;           //Координата Х
    double y;           //Координата У
public:
    Vector2D() : x{ 0 }, y{ 0 }     //Конструктор за замовченням
    {
    }
    Vector2D(double _x, double _y) : x{ _x }, y{ _y }   //Конструктор з 2 параметрами
    {
    }
    Vector2D(const Vector2D& vect) : x{ vect.x }, y{ vect.y } //Конструктор, що приймає посилання
    {                                                   //на вже існуючий об'єкт і копіює дані з
    }                                                   //нього. Конструктор копіювання
    Vector2D operator+(const Vector2D& obj)       //Перевантажений оператор +,
    {                                             //реалізація операції додавання векторів.
        Vector2D result(x + obj.x, y + obj.y);    //Метод повертає новий об'єкт result
        return result;
    }
    Vector2D operator-(const Vector2D& obj)       //Перевантажений оператор -,
    {                                             //реалізація операції різниці векторів.
        Vector2D result(x - obj.x, y - obj.y);    //Метод повертає новий об'єкт result
        return result;
    }
    double operator*(const Vector2D& obj) const   //Перевантажений оператор *,
    {                                             //реалізація операції отримання 
        return (x * obj.x + y * obj.y);           //скалярного добутку двох векторів
    }

    Vector2D& operator*(const double scalar)       //Перевантажений оператор *,
    {                                              //реалізація операції множення 
        x *= scalar;                               //вектору на скаляр 
        y *= scalar;
        return *this;
    }
    Vector2D& operator/(const double scalar)       //Перевантажений оператор *,
    {                                              //реалізація операції ділення
        x /= scalar;                               //вектору на скаляр 
        y /= scalar;
        return *this;
    }
    void Reflection()               //Метод, що реалізує віддзеркалення вектора,
    {                               //тобто повертає протилежний вектор
        x = -x;
        y = -y;
    }
    
    Vector2D& operator=(const Vector2D& obj)    //Реалізація присвоєння через
    {                                           //перевантаження оператора =
        x = obj.x;
        y = obj.y;
        return *this;
    }

    void Normalize_this()                           //Метод, що нормалізує поточний вектор
    {
        double length = sqrt(x * x + y * y);
        x = x / length;
        y = y / length;
    }
    Vector2D Normalize_New() const                  //Метод, створює новий вектор на 
    {                                               //базі нормалізованого поточного.
        double length = sqrt(x * x + y * y);        //Старий вектор залишається незмінним. 
        Vector2D result(x / length, y / length);
        return result;
    }
    double Length()                         //Метод, що повертає довжину вектора
    {
        return (sqrt(x * x + y * y));
    }
    double GetX()                           //Метод, що повертає координату Х
    {
        return x;
    }
    double GetY()                           //Метод, що повертає координату У
    {
        return y;
    }
    void SetX(double _x)                    //Метод, що задає нове значення координати Х
    {
        x = _x;
    }
    void SetY(double _y)                    //Метод, що задає нове значення координати У
    {
        y = _y;
    }

    double operator[](int n)                //Метод, що повертає координату У або Х 
    {                                       //через перевантаження оператора [],  
        if (n == 0)                         //залежно від отриманного значання. 
            return x;                       //[0] повертає Х, [1] повертає У.
        else if (n == 1)
            return y;
    }
    void RotateByAngle(double angle)            //Метод, що здійснює поворот вектора на  
    {                                           //заданий кут в радіанах 
        x = x * cos(angle) - y * sin(angle);
        y = x * sin(angle) + y * cos(angle);
    }       
    void Print()                                //Метод, що роздруковує координати на екан
    {   
        cout << "x = " << x << endl << "y = " << y << endl;
    } 
};

void Menu()
{
    system("cls"); //функція для очищення консолі
    cout << "Enter the number of the task" << endl << endl;
    //Обрання пункту завдання для тестування

    cout << "\n1. constructors: default, copy," << endl;
    cout << "   a pair of real numbers" << endl;
    //1. Реалізувати відповідні конструктори: за замовченням, 
    //копіювання та ініціалізації парою дійсних чисел.

    cout << "\n2. Vector addition and subtraction," << endl;
    cout << "   scalar product" << endl;
    //2. Реалізувати операції додавання та віднімання 
    //векторів, а також скалярного добутку. 

    cout << "\n3. Vector scaling" << endl;
    //3. Реалізувати можливість масштабування вектору 
    //(множення та ділення на скаляр). 

    cout << "\n4. Reflection (obtaining the opposite)" << endl;
    cout << "   vector" << endl;
    //4. Реалізувати можливість віддзеркалення 
    //(отримання протилежного) вектору. 

    cout << "\n5. Assignment operations." << endl;
    //5. Реалізувати операції присвоєння. 

    cout << "\n6. Normalization, getting" << endl;
    cout << "   of normalized vector" << endl;
    //6. Реалізувати можливість нормалізації вектору та отримання 
    //нормалізованого вектору із поточного(не змінюючи його).

    cout << "\n7. ength(norm) of the vector" << endl;
    //7. Реалізувати можливість розрахунку довжини(норми) вектору.

    cout << "\n8. Access to individual coordinates," << endl;
    cout << "   indexing(v[0], v[1])" << endl;
    //8. Реалізувати доступ до окремих координат, в 
    //тому числі шляхом індексування (v[0], v[1]) 

    cout << "\n9. Rotating the vector on the angle" << endl;
    cout << "   (against the clockwise)" << endl;
    //9. Реалізувати операцію повороту вектору на 
    //заданий кут (проти годинникової стрілки).

    cout << "\n0. Exit" << endl;
    //Вихід з програми
}

int main()
{
    while (true)
    {
        Menu(); //Виклик функції меню

        int task = _getch(); //Обрання певного пункту меню через функцію _getch()

        if (task == '1') //Тесування пункту 1
        {
            system("cls");
            cout << "Vector created with default constructor: " << endl;
            Vector2D v1; //Викликається конструктор за замовченням
            v1.Print();//Виведення координат вектора на екран   


            cout << "\nVector is initialized with two real numbers(5.0, 7.5): " << endl;
            Vector2D v2(5.0, 7.5); //Викликається конструктор, який приймає 
            v2.Print();            //два дійсних числа: 5.0 та 7.5
                    
            cout << "\nVector coppied: " << endl;  //Викликається конструктор копіювання 
            Vector2D v3(v2);
            v3.Print();
            system("pause");        //Функція, яка викликає паузу в консолі, щоб .
                                    //передивитись результат. Для продовження роботи 
                                    //програми треба натиснуи будь-яку клавішу
        }
        else if (task == '2') //тесування пункту 2
        {
            system("cls");
            Vector2D v1(5.0, 7.5);
            cout << "Vector 1: " << endl;
            v1.Print();

            Vector2D v2(1.5, 3);
            cout << "\nVector 2: " << endl;
            v2.Print();

            Vector2D v3 = v1 + v2;       //Додавання векторів

            cout << "\nVector 1 + Vector 2  = \n"; 
            v3.Print();

            Vector2D v4 = v1 - v2;      //Різниця векторів

            cout << "\nVector 1 - Vector 2  = \n";
            v4.Print();

            cout << "\nVector 1 * Vector 2  = " << v1 * v2 << endl; //Скалярний добуток векторів
            system("pause");
        }
        else if (task == '3') //тесування пункту 3
        {
            system("cls");
            Vector2D v1(5.0, 7.5);
            cout << "Vector 1: \n";
            v1.Print();

            cout << "\nVector 1 * 2 = \n";  //Множення вектора на скаляр
            v1 * 2;
            v1.Print();

            cout << "\nVector 1 / 5 = \n";  //Ділення вектору на скаляр
            v1 / 5;
            v1.Print();
            system("pause");
        }
        else if (task == '4') //тесування пункту 4
        {
            system("cls");
            Vector2D v1(5.0, 7.5);
            cout << "Vector 1: \n";
            v1.Print();

            cout << "\n Reflected vector 1: \n";  //Віддзуркалення вектору
            v1.Reflection();
            v1.Print();
            system("pause");
        }
        else if (task == '5') //тесування пункту 5
        {
            system("cls");
            Vector2D v1(5.0, 7.5);
            cout << "Vector 1: \n";
            v1.Print();

            Vector2D v2(1, 2);
            cout << "Vector 2: \n";
            v2.Print();

            v2 = v1;           //Присвоєння векторів
            cout << "Vector 2: \n";
            v2.Print();
            system("pause");
        }
        else if (task == '6') //тесування пункту 6
        {
            system("cls");
            Vector2D v1(5.0, 7.5);
            cout << "Vector: \n";
            v1.Print();

            cout << "\nNormalized vector: \n";  //Нормалізація ветору
            v1.Normalize_this();
            v1.Print();

            cout << "\nNormalized new vector: \n";
            Vector2D v2(v1.Normalize_New());   //Отримання нового нормалізованого 
            v2.Print();                        //ветору без зміни старого
            system("pause");
        }
        else if (task == '7') //тесування пункту 7
        {
            system("cls");
            Vector2D v1(5.0, 7.5);
            cout << "Vector: \n";
            v1.Print();
            cout << "Lenth = " << v1.Length() << endl;  //Отримання довжини вектору
            system("pause");
        }
        else if (task == '8') //тесування пункту 8
        {
            system("cls");
            Vector2D v1(5.0, 7.5);
            cout << "Vector: \n";
            v1.Print();

            cout << "x: " << v1[0] << endl;     //Доступ за допомогою перевантаженого оператора[]
            cout << "y: " << v1[1] << endl;     //Доступ за допомогою перевантаженого оператора[]
            cout << "x: " << v1.GetX() << endl;     //Доступ за допомогою інспектора
            cout << "y: " << v1.GetY() << endl;     //Доступ за допомогою інспектора

            v1.SetX(0.5);           //Зміна за допомогою модифікатора
            v1.SetY(0.25);          //Зміна за допомогою модифікатора
            cout << "x: " << v1.GetX() << endl;
            cout << "y: " << v1.GetY() << endl;
            system("pause");
        }
        else if (task == '9') //тесування пункту 9
        {
            system("cls");
            Vector2D v1(5.0, 7.5);
            cout << "Vector: \n";
            v1.Print();

            cout << "\Vector is rotated for 45 radians: \n";
            v1.RotateByAngle(45);           //Поворот вектору на кут 45 радіанів 
            v1.Print();
            system("pause");
        }
        else if (task == '0') //завершення тестування
        {
            break;
        }
    }
}

