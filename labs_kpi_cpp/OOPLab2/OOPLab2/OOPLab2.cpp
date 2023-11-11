// OOPLab2.cpp 

#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

//////////////////////////////////////////////////////////////////////
//        базовий клас, що є спільним для всіх фігур                //

class Figure  // базовий клас із необхідними віртуальними методами
{
protected:
    int count;  // поле, що позначає кількість ребер
    double side; // поле, що позначає довжину однєї сторони
public: 
    Figure() : count(0), side(0) {}  // конструктор за замовченням

    void SetSide(double value) // метод для встановлення сторони фігури
    {
        if (value < 0) // якщо користувач введе від'ємне значення,програма 
            side = -value;        // використає значення за модулем.
        else side = value;        // Довжина не може бути від'ємною
    }
    double GetSide()  // метод для отримання сторони фігури 
    {
        return side;
    }
    int GetCountOfEdges() // метод для отримання кількості ребер фігури 
    {
        return count;
    }

    // Далі всі описані методи є віртуальними і поліморфними
    virtual void GetFigure() = 0; // метод, який виводить на екран назву фігури
    virtual double GetRadiusInscribed() = 0; // метод для отримання радіусу ВПисаного кола
    virtual void SetRadiusInscribed(double r) = 0; // метод для встановлення радіусу ВПисаного кола
    virtual double GetRadiusCircumscribed() = 0; // метод для отримання радіусу ОПисаного кола
    virtual void SetRadiusCircumscribedd(double r) = 0; // метод для встановлення радіусу ОПисаного кола
   
    virtual int GetCountOfApexes() = 0; // метод для отримання кількості вершин фігури 
    virtual double GetSquare() = 0; // метод для отримання площі фігури 
    virtual void PrintInfo() = 0; // метод для виведення всієї інформації про фігуру на екран
    virtual void Test() = 0; // метод для тестування класу
};

//////////////////////////////////////////////////////////////////////
//  2Д фігури: правильний трикутник, квадрат, 5 та 6-кутник, коло   //

class Triangle : public Figure // трикутник
{
public:
    Triangle() : Figure() // конструктор за замовченням
    {
        count = 3;
        side = 0;
    }
    Triangle(double d) : Triangle() // конструктом з параметром (довжина сторони)
    {
        if (d < 0)
            side = -d;
        else side = d;
    }
    Triangle(Triangle& tr) : Triangle() // конструктор, що ініціалізує нову фігуру
    {                                       // вже існуючою фігурою
        count = tr.GetCountOfEdges();
        side = tr.GetSide();
    }
    void GetFigure() // метод, який виводить на екран назву фігури
    {
        cout << "Triangle";
    }
    double GetRadiusInscribed()  // метод для отримання радіусу ВПисаного кола
    {
        return (side / (2 * sqrt(3)));  
    }
    void SetRadiusInscribed(double r) // метод для встановлення радіусу ВПисаного кола
    {
        side = r * (2 * sqrt(3));
    }
    double GetRadiusCircumscribed()  // метод для отримання радіусу ОПисаного кола
    {
        return (side / sqrt(3));
    }
    void SetRadiusCircumscribedd(double R)  // метод для встановлення радіусу ОПисаного кола
    {
        side = R * sqrt(3); 
    }
    int GetCountOfApexes() // метод для отримання кількості вершин фігури 
    {
        return 3;
    }
    double GetSquare() // метод для отримання площі фігури 
    {
        return ((side * side * sqrt(3) ) / 4);
    }
    double GetPerimeter() // метод для отримання периметру фігури 
    {
        return (side * 3);
    }
    void SetPerimeter(double P) // метод для встановлення периметру фігури 
    {
        side = P / 3;
    }
    void PrintInfo()  // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:                          " ; 
        GetFigure();
        cout << endl << "Size of side:                  " << GetSide() << endl;
        cout << "Inscribed circle radius:       " << GetRadiusInscribed() << endl;
        cout << "Circumscribed  circle radius:  " << GetRadiusCircumscribed() << endl;
        cout << "Nubmer of edges:               " << GetCountOfEdges() << endl;
        cout << "Nubmer of apexes:              " << GetCountOfApexes() << endl;
        cout << "Square:                        " << GetSquare() << endl;
        cout << "Perimeter:                     " << GetPerimeter() << endl;
    }
    void Test()  // метод для тестуввання класу
    {
        Triangle test;
        cout << "Enter the size of side: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();
        cout << "Enter the new perimeter: ";
        cin >> size;
        test.SetPerimeter(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed circle radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed circle radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

    }
};



class Square : public Figure  // квадрат 
{
public:
    Square() : Figure() // конструктор за замовченням
    {
        count = 4;
        side = 0;
    }
    Square(double d) : Square() // конструктом з параметром (довжина сторони)
    {
        if (d < 0)
            side = -d;
        else side = d;
    }
    Square(Square& sq) : Square() // конструктор, що ініціалізує нову фігуру
    {                                   // вже існуючою фігурою
        count = 4;
        side = sq.GetSide();
    }
    void GetFigure() // метод, який виводить на екран назву фігури
    {
        cout << "Square";
    }
    double GetRadiusInscribed()  // метод для отримання радіусу ВПисаного кола
    {
        return (side / 2);
    }
    void SetRadiusInscribed(double r)  // метод для встановлення радіусу ВПисаного кола
    {
        side = r * 2;
    }
    double GetRadiusCircumscribed()  // метод для отримання радіусу ОПисаного кола
    {
        return sqrt(side * side * 2);
    }
    void SetRadiusCircumscribedd(double R) // метод для встановлення радіусу ОПисаного кола
    {
        side = sqrt((R * R) / 2);
    }
    int GetCountOfApexes()  // метод для отримання кількості вершин фігури 
    {
        return 4;
    }
    double GetSquare()  // метод для отримання площі фігури 
    {
        return (side * side);
    }
    double GetPerimeter() // метод для отримання периметру фігури 
    {
        return (side * 4);
    }
    void SetPerimeter(double P) // метод для встановлення периметру фігури 
    {
        side = double(P) / 4.0;
    }
    void PrintInfo() // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:                          ";
        GetFigure();
        cout << endl << "Size of side:                  " << GetSide() << endl;
        cout << "Inscribed circle radius:       " << GetRadiusInscribed() << endl;
        cout << "Circumscribed  circle radius:  " << GetRadiusCircumscribed() << endl;
        cout << "Nubmer of edges:               " << GetCountOfEdges() << endl;
        cout << "Nubmer of apexes:              " << GetCountOfApexes() << endl;
        cout << "Square:                        " << GetSquare() << endl;
        cout << "Perimeter:                     " << GetPerimeter() << endl;
    }
    void Test() // метод для тестуввання класу
    {
        Square test;
        cout << "Enter the size of side: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();
        cout << "Enter the new perimeter: ";
        cin >> size;
        test.SetPerimeter(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed circle radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed circle radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();
    }
};

class Pentagon : public Figure  // п'ятикутник 
{
public:
    Pentagon() : Figure() // конструктом за замовченням
    {
        count = 5;
        side = 0;
    }
    Pentagon(double d) : Pentagon() // конструктом з параметром (довжина сторони)
    {
        if (d < 0)
            side = -d;
        else side = d;
    }
    void GetFigure() // метод, який виводить на екран назву фігури
    {
        cout << "Pentagon";
    }
    double GetRadiusInscribed() // метод для отримання радіусу ВПисаного кола
    {
        return (GetRadiusCircumscribed() * 0.809016994374947); 
    }
    void SetRadiusInscribed(double r) // метод для встановлення радіусу ВПисаного кола
    {
        side = r * (2.0 * sqrt( 5.0 - 2.0 * sqrt(5.0) ));
    }
    double GetRadiusCircumscribed() // метод для отримання радіусу ОПисаного кола
    {
        return (side / (2.0 * 0.587785252292473 ));
    }
    void SetRadiusCircumscribedd(double R) // метод для встановлення радіусу ОПисаного кола
    {
        side = R * (2 * 0.587785252292473 );
    }
    int GetCountOfApexes() // метод для отримання кількості вершин фігури
    {
        return 5;
    }
    double GetSquare() // метод для отримання площі фігури 
    {
        return ((side * side * sqrt(25 + 10 * sqrt(5.0))) / 4.0);
    }
    double GetPerimeter() // метод для отримання периметру фігури 
    {
        return (side * 5);
    }
    void SetPerimeter(double P) // метод для встановлення периметру фігури 
    {
        side = P / 5;
    }
    void PrintInfo() // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:                          ";
        GetFigure();
        cout << endl << "Size of side:                  " << GetSide() << endl;
        cout << "Inscribed circle radius:       " << GetRadiusInscribed() << endl;
        cout << "Circumscribed  circle radius:  " << GetRadiusCircumscribed() << endl;
        cout << "Nubmer of edges:               " << GetCountOfEdges() << endl;
        cout << "Nubmer of apexes:              " << GetCountOfApexes() << endl;
        cout << "Square:                        " << GetSquare() << endl;
        cout << "Perimeter:                     " << GetPerimeter() << endl;
    }

    void Test() // метод для тестуввання класу
    {
        Pentagon test;
        cout << "Enter the size of side: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();
        cout << "Enter the new perimeter: ";
        cin >> size;
        test.SetPerimeter(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed circle radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed circle radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

    }
};

class Hexagon : public Figure // шестикутник
{
public:
    Hexagon() : Figure() // конструктом за замовченням
    {
        count = 6;
        side = 0;
    }
    Hexagon(double d) : Hexagon() // конструктом з параметром (довжина сторони)
    {
        if (d < 0)
            side = -d;
        else side = d;
    }
    Hexagon(Hexagon& h) : Hexagon() // конструктор, що ініціалізує нову фігуру
    {                                   // вже існуючою фігурою
        count = 6;
        side = h.GetSide();
    }
    void GetFigure()  // метод, який виводить на екран назву фігури
    {
        cout << "Hexagon";
    }
    double GetRadiusInscribed() // метод для отримання радіусу ВПисаного кола
    {
        return (sqrt(3) / 2 * side);
    }
    void SetRadiusInscribed(double r) // метод для встановлення радіусу ВПисаного кола
    {
        side = r / (sqrt(3) / 2);
    }
    double GetRadiusCircumscribed() // метод для отримання радіусу ОПисаного кола
    {
        return (side);
    }
    void SetRadiusCircumscribedd(double R)  // метод для встановлення радіусу ОПисаного кола
    {
        side = R;
    }
    int GetCountOfApexes() // метод для отримання кількості вершин фігури 
    {
        return 6;
    }
    double GetSquare() // метод для отримання площі фігури 
    {
        return ((3 * sqrt(3) * side * side) / 2);
    }
    double GetPerimeter() // метод для отримання периметру фігури 
    {
        return (side * 6);
    }
    void SetPerimeter(double P) // метод для встановлення периметру фігури 
    {
        side = P / 6;
    }
    void PrintInfo() // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:                          ";
        GetFigure();
        cout << endl << "Size of side:                  " << GetSide() << endl;
        cout << "Inscribed circle radius:       " << GetRadiusInscribed() << endl;
        cout << "Circumscribed  circle radius:  " << GetRadiusCircumscribed() << endl;
        cout << "Nubmer of edges:               " << GetCountOfEdges() << endl;
        cout << "Nubmer of apexes:              " << GetCountOfApexes() << endl;
        cout << "Square:                        " << GetSquare() << endl;
        cout << "Perimeter:                     " << GetPerimeter() << endl;
    }
    void Test() // метод для тестуввання класу
    {
        Hexagon test;
        cout << "Enter the size of side: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();
        cout << "Enter the new perimeter: ";
        cin >> size;
        test.SetPerimeter(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed circle radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed circle radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

    }
};

class Circle : public Figure // коло
{
public:
    Circle() : Figure() // конструктом за замовченням
    {
        count = 0;
        side = 0;
    }
    Circle(double radius) : Circle() // конструктом з параметром (довжина сторони)
    {                                       
        if (radius < 0)
            side = -radius;
        else side = radius;
    }
    Circle(Circle& c) : Circle() // конструктор, що ініціалізує нову фігуру
    {                               // вже існуючою фігурою
        count = 1;
        side = c.GetSide();
    }
    void GetFigure()  // метод, який виводить на екран назву фігури
    {
        cout << "Circle";
    }
    double GetSquare() // метод для отримання площі фігури 
    {
        return (M_PI * side * side);
    }
    double GetPerimeter() // метод для отримання периметру фігури 
    {
        return (2 * M_PI * side);
    }
    void SetPerimeter(double P) // метод для встановлення периметру фігури 
    {
        side = P / (2 * M_PI);
    }
    void PrintInfo() // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:        ";
        GetFigure();
        cout << endl << "Radius:      " << GetSide() << endl;
        cout << "Square:      " << GetSquare() << endl;
        cout << "Length:      " << GetPerimeter() << endl;
    }

    double GetRadiusInscribed() // метод для отримання радіусу ВПисаного кола
    {
        return side;
    }            //    |o|
    void SetRadiusInscribed(double r)  // метод для встановлення радіусу ВПисаного кола
    {
         side = r;
    }        //    |o|
    double GetRadiusCircumscribed()  // метод для отримання радіусу ОПисаного кола
    {
        return side;
    }          //   (||)
    void SetRadiusCircumscribedd(double r) // метод для встановлення радіусу ОПисаного кола
    {
        side = r;
    }   //   (||)
    int GetCountOfApexes() // метод для отримання кількості вершин фігури 
    {
        return 0;
    }
    void Test() // метод для тестуввання класу
    {
        Circle test;
        cout << "Enter the size of radius: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();
        cout << "Enter the new Length of circle: ";
        cin >> size;
        test.SetPerimeter(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed circle radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed circle radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();
    }
};

//////////////////////////////////////////////////////////////////////
// 3Д фігури: тетраедр, гексаедр, октаедр, додекаедр, ікосаедр, куля //

class Tetrahedron :public Figure  // піраміда, тетраедр 
{
public:
    Tetrahedron() : Figure() // конструктор за замовченням
    {
        count = 6;
        side = 0;
    }
    Tetrahedron(double d) : Figure() // конструктом з параметром (довжина сторони)
    {
        if (d < 0)
            side = -d;
        else side = d;
    }
    int GetCountOfFaces() // метод для отримання кількості граней
    {
        return 4;
    }
    int GetCountOfFacesNearTheEdge() // метод отримання кількості граней, суміжних із вершиною
    {
        return 3;
    }
    int GetCountOfSidesOfFace() // метод для отримання кількості сторін у грані.
    {
        return 3;
    }
    void GetFigure()  // метод, який виводить на екран назву фігури
    {
        cout << "Tetrahedron";
    }
    double GetRadiusInscribed() // метод для отримання радіусу ВПисаного кола
    {
        return (side * sqrt(6) / 12);
    }
    void SetRadiusInscribed(double r) // метод для встановлення радіусу ВПисаного кола
    {
        side = (r * 12) / sqrt(6);
    }
    double GetRadiusCircumscribed() // метод для отримання радіусу ОПисаного кола
    {
        return (side * sqrt(6) / 4);
    }
    void SetRadiusCircumscribedd(double R) // метод для встановлення радіусу ОПисаного кола
    {
        side = (R * 4) / sqrt(6);
    }
    int GetCountOfApexes() // метод для отримання кількості вершин фігури 
    {
        return 4;
    }
    double GetSquare() // метод для отримання площі фігури 
    {
        return (side * side * sqrt(3));
    }
    double GetPerimeter() // метод для отримання периметру фігури 
    {
        return (side * 6);
    }
    void SetPerimeter(double P) // метод для встановлення периметру фігури 
    {
        side = P / 6; 
    }
    double GetVolume() // метод для отримання об'єму фігури
    {
        return (side * side * side * sqrt(2) / 12);
    }
    void SetVolume(double V) // метод для встановлення об'єму фігури 
    {
        side = pow(V * 12 / sqrt(2), 1.0 / 3);
    }
    void PrintInfo() // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:                          ";
        GetFigure();
        cout << endl << "Size of side:                  " << GetSide() << endl;
        cout << "Inscribed sphere radius:       " << GetRadiusInscribed() << endl;
        cout << "Circumscribed sphere radius:   " << GetRadiusCircumscribed() << endl;
        cout << "Nubmer of edges:               " << GetCountOfEdges() << endl;
        cout << "Nubmer of apexes:              " << GetCountOfApexes() << endl;
        cout << "Nubmer of faces:               " << GetCountOfFaces() << endl;
        cout << "Number of faces, adjacent to   \n"; 
        cout << "an edge:                       " << GetCountOfFacesNearTheEdge() << endl;
        cout << "Number of sides of the face:   " << GetCountOfSidesOfFace() << endl;
        cout << "Square:                        " << GetSquare() << endl;
        cout << "Volume:                        " << GetVolume() << endl;
        cout << "Perimeter:                     " << GetPerimeter() << endl;
    }
    Triangle& GetNewTriangle() // метод для отримання пласкої фігури, 
    {                           // що представляє грань даної об’ємної фігури
        Triangle tr;
        tr.SetSide(this->GetSide());
        return tr;
    }
    void Test() // метод для тестуввання класу
    {
        Tetrahedron test;
        cout << "Enter the size of side: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();
        cout << "Enter the new perimeter: ";
        cin >> size;
        test.SetPerimeter(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed sphere radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed sphere radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new volume: ";
        cin >> size;
        test.SetVolume(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "\nNew figure is:\n";
        test.SetSide(7.5);
        test.PrintInfo();

        cout << "\nThis figure consists of many figures that are:\n";
        Triangle tr(test.GetNewTriangle());
        tr.PrintInfo();
    }
};
class Hexahedron :public Figure  // куб або шестигранник
{
public:
    Hexahedron() : Figure() // конструктор за замовченням
    {
        count = 12;
        side = 0;
    }
    Hexahedron(double d) : Figure() // конструктом з параметром (довжина сторони)
    {
        count = 12;
        if (d < 0)
            side = -d;
        else side = d;
    }
    int GetCountOfFaces()   // метод для отримання кількості граней
    {
        return 6;
    }
    int GetCountOfFacesNearTheEdge() // метод отримання кількості граней, 
    {                                   // суміжних із вершиною
        return 3;
    }
    int GetCountOfSidesOfFace() // метод для отримання кількості сторін у грані.
    {
        return 4;
    }
    void GetFigure() // метод, який виводить на екран назву фігури
    {
        cout << "Hexahedron(kube)";
    }
    double GetRadiusInscribed() // метод для отримання радіусу ВПисаного кола
    {
        return (side / 2);
    }
    void SetRadiusInscribed(double r) // метод для встановлення радіусу ВПисаного кола
    {
        side = r * 2;
    }
    double GetRadiusCircumscribed()  // метод для отримання радіусу ОПисаного кола
    {
        return (side / 2 * sqrt(3));
    }
    void SetRadiusCircumscribedd(double R)  // метод для встановлення радіусу ОПисаного кола
    {
        side = (R / sqrt(3) * 2);
    }
    int GetCountOfApexes() // метод для отримання кількості вершин фігури 
    {
        return 8;
    }
    double GetSquare() // метод для отримання площі фігури 
    {
        return (side * side * 6);
    }
    double GetPerimeter() // метод для отримання периметру фігури 
    {
        return (side * count);
    }
    void SetPerimeter(double P) // метод для встановлення периметру фігури 
    {
        side = P / count;
    }
    double GetVolume() // метод для отримання об'єму фігури
    {
        return (side * side * side);
    }
    void SetVolume(double V) // метод для встановлення об'єму фігури 
    {
        side = pow(V, 1.0 / 3);
    }
    void PrintInfo() // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:                          ";
        GetFigure();
        cout << endl << "Size of side:                  " << GetSide() << endl;
        cout << "Inscribed sphere radius:       " << GetRadiusInscribed() << endl;
        cout << "Circumscribed sphere radius:   " << GetRadiusCircumscribed() << endl;
        cout << "Nubmer of edges:               " << GetCountOfEdges() << endl;
        cout << "Nubmer of apexes:              " << GetCountOfApexes() << endl;
        cout << "Nubmer of faces:               " << GetCountOfFaces() << endl;
        cout << "Number of faces, adjacent to   \n";
        cout << "an edge:                       " << GetCountOfFacesNearTheEdge() << endl;
        cout << "Number of sides of the face:   " << GetCountOfSidesOfFace() << endl;
        cout << "Square:                        " << GetSquare() << endl;
        cout << "Volume:                        " << GetVolume() << endl;
        cout << "Perimeter:                     " << GetPerimeter() << endl;
    }
    Square& GetNewSquare() // метод для отримання пласкої фігури, 
    {                       // що представляє грань даної об’ємної фігури
        Square sq;
        sq.SetSide(this->GetSide());
        return sq;

    }
    void Test()  // метод для тестуввання класу
    {
        Hexahedron test;
        cout << "Enter the size of side: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();
        cout << "Enter the new perimeter: ";
        cin >> size;
        test.SetPerimeter(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed sphere radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed sphere radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new volume: ";
        cin >> size;
        test.SetVolume(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "\nNew figure is:\n";
        test.SetSide(15.5);
        test.PrintInfo();

        cout << "\nThis figure consists of many figures that are:\n";
        Square sq(test.GetNewSquare());
        sq.PrintInfo();
    }
};
class Octahedron :public Figure // октаедр
{
public:
    Octahedron() : Figure() // конструктор за замовченням
    {
        count = 12;
        side = 0;
    }
    Octahedron(double d) : Figure() // конструктом з параметром (довжина сторони)
    {
        if (d < 0)
            side = -d;
        else side = d;
    }
    int GetCountOfFaces() // метод для отримання кількості граней
    {
        return 8;
    }
    int GetCountOfFacesNearTheEdge() // метод отримання кількості граней, 
    {                                      // суміжних із вершиною
        return 4;
    }
    int GetCountOfSidesOfFace() // метод для отримання кількості сторін у грані.
    {
        return 3;
    }
    void GetFigure()  // метод, який виводить на екран назву фігури
    {
        cout << "Octahedron";
    }
    double GetRadiusInscribed()  // метод для отримання радіусу ВПисаного кола
    {
        return (side / 6 * sqrt(6));
    }
    void SetRadiusInscribed(double r) // метод для встановлення радіусу ВПисаного кола
    {
        side = (r / sqrt(6) * 6);
    }
    double GetRadiusCircumscribed() // метод для отримання радіусу ОПисаного кола
    {
        return (side / 2 * sqrt(2));
    }
    void SetRadiusCircumscribedd(double R) // метод для встановлення радіусу ОПисаного кола
    {
        side = (R / sqrt(2) * 2); 
    }
    int GetCountOfApexes() // метод для отримання кількості вершин фігури 
    {
        return 6;
    }
    double GetSquare() // метод для отримання площі фігури 
    {
        return (2 * side * side * sqrt(3));
    }
    double GetPerimeter() // метод для отримання периметру фігури 
    {
        return (side * count);
    }
    void SetPerimeter(double P) // метод для встановлення периметру фігури 
    {
        side = P / count;
    }
    double GetVolume() // метод для отримання об'єму фігури
    {
        return (side * side * side * sqrt(2)  / 3);
    }
    void SetVolume(double V) // метод для встановлення об'єму фігури 
    {
        side = pow(V * 3 / sqrt(2), 1.0 / 3);
    } 
    void PrintInfo() // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:                          ";
        GetFigure();
        cout << endl << "Size of side:                  " << GetSide() << endl;
        cout << "Inscribed sphere radius:       " << GetRadiusInscribed() << endl;
        cout << "Circumscribed sphere radius:   " << GetRadiusCircumscribed() << endl;
        cout << "Nubmer of edges:               " << GetCountOfEdges() << endl;
        cout << "Nubmer of apexes:              " << GetCountOfApexes() << endl;
        cout << "Nubmer of faces:               " << GetCountOfFaces() << endl;
        cout << "Number of faces, adjacent to   \n";
        cout << "an edge:                       " << GetCountOfFacesNearTheEdge() << endl;
        cout << "Number of sides of the face:   " << GetCountOfSidesOfFace() << endl;
        cout << "Square:                        " << GetSquare() << endl;
        cout << "Volume:                        " << GetVolume() << endl;
        cout << "Perimeter:                     " << GetPerimeter() << endl;
    }
    Triangle& GetNewTriangle() // метод для отримання пласкої фігури,
    {                           //  що представляє грань даної об’ємної фігури
        Triangle tr;
        tr.SetSide(this->GetSide());
        return tr;

    }
    void Test()  // метод для тестуввання класу
    {
        Octahedron test;
        cout << "Enter the size of side: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();
        cout << "Enter the new perimeter: ";
        cin >> size;
        test.SetPerimeter(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed sphere radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed sphere radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new volume: ";
        cin >> size;
        test.SetVolume(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "\nNew figure: \n";
        test.SetSide(12.5);
        test.PrintInfo();

        cout << "\nThis figure consists of many figures that are:\n";
        Triangle tr(test.GetNewTriangle());
        tr.PrintInfo();
    }
};

class Dodecahedron :public Figure // Додекаедр
{
public:
    Dodecahedron() : Figure() // конструктор за замовченням
    {
        count = 30;
        side = 0;
    }
    Dodecahedron(double d) : Figure() // конструктом з параметром (довжина сторони)
    {
        if (d < 0)
            side = -d;
        else side = d;
    }
    int GetCountOfFaces()   // метод для отримання кількості граней
    {
        return 12;
    }
    int GetCountOfFacesNearTheEdge() // метод для отримання кількості граней, суміжних із вершиною
    {
        return 3;
    }
    int GetCountOfSidesOfFace() // метод для отримання кількості сторін у грані.
    {
        return 5;
    }
    void GetFigure() // метод, який виводить на екран назву фігури
    {
        cout << "Dodecahedron";
    }
    double GetRadiusInscribed()  // метод для отримання радіусу ВПисаного кола
    {
        return (side / 4 * sqrt(10 + 22.0 / sqrt(5.0)) );
    }
    void SetRadiusInscribed(double r) // метод для встановлення радіусу ВПисаного кола
    {
        side = (r / sqrt(10.0 + 22.0 / sqrt(5.0)) * 4.0);
    }
    double GetRadiusCircumscribed()  // метод для отримання радіусу ОПисаного кола
    {
        return (side / 4 * sqrt(3.0) * (1 + sqrt(5.0) ) );
    }
    void SetRadiusCircumscribedd(double R) // метод для встановлення радіусу ОПисаного кола
    {
        side = (R / (1 + sqrt(5.0)) / sqrt(3.0) * 4);
    }
    int GetCountOfApexes() // метод для отримання кількості вершин фігури 
    {
        return 20;
    }
    double GetSquare() // метод для отримання площі фігури 
    {
        return (3.0 * side * side * sqrt(5.0 * (5.0 + 2.0 * sqrt(5.0) ) ) );
    }
    double GetPerimeter() // метод для отримання периметру фігури 
    {
        return (side * count);
    }
    void SetPerimeter(double P) // метод для встановлення периметру фігури 
    {
        side = P / count;
    }
    double GetVolume() // метод для отримання об'єму фігури
    {
        return ( (side * side * side) / 4.0 * (15.0 + 7.0 * sqrt(5.0) ) );
    }
    void SetVolume(double V) // метод для встановлення об'єму фігури
    {
        side = pow(V  / ( (15.0 + 7.0 * sqrt(5.0)) * 4.0) , 1.0 / 3.0);
    }
    void PrintInfo() // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:                          ";
        GetFigure();
        cout << endl << "Size of side:                  " << GetSide() << endl;
        cout << "Inscribed sphere radius:       " << GetRadiusInscribed() << endl;
        cout << "Circumscribed sphere radius:   " << GetRadiusCircumscribed() << endl;
        cout << "Nubmer of edges:               " << GetCountOfEdges() << endl;
        cout << "Nubmer of apexes:              " << GetCountOfApexes() << endl;
        cout << "Nubmer of faces:               " << GetCountOfFaces() << endl;
        cout << "Number of faces, adjacent to   \n";
        cout << "an edge:                       " << GetCountOfFacesNearTheEdge() << endl;
        cout << "Number of sides of the face:   " << GetCountOfSidesOfFace() << endl;
        cout << "Square:                        " << GetSquare() << endl;
        cout << "Volume:                        " << GetVolume() << endl;
        cout << "Perimeter:                     " << GetPerimeter() << endl;
    }
    Triangle& GetNewTriangle() // метод для отримання пласкої фігури, 
    {                           // що представляє грань даної об’ємної фігури
        Triangle tr;
        tr.SetSide(this->GetSide());
        return tr;
    }
    void Test() // метод для тестуввання класу
    {
        Dodecahedron test;
        cout << "Enter the size of side: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();
        cout << "Enter the new perimeter: ";
        cin >> size;
        test.SetPerimeter(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed sphere radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed sphere radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new volume: ";
        cin >> size;
        test.SetVolume(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "\nNew figure:\n";
        test.SetSide(20.75);
        test.PrintInfo();

        cout << "\nThis figure consists of many figures that are:\n";
        Triangle tr(test.GetNewTriangle());
        tr.PrintInfo();
    }
}; 
class Icosahedron :public Figure // Ікосаедр
{
public:
    Icosahedron() : Figure() // конструктор за замовченням
    {
        count = 30;
        side = 0;
    }
    Icosahedron(double d) : Figure() // конструктом з параметром (довжина сторони)
    {
        if (d < 0)
            side = -d;
        else side = d;
    }
    int GetCountOfFaces()   // метод для отримання кількості граней
    {
        return 20;
    }
    int GetCountOfFacesNearTheEdge() // метод для отримання кількості граней, суміжних із вершиною
    {
        return 5;
    }
    int GetCountOfSidesOfFace() // метод для отримання кількості сторін у грані.
    {
        return 3;
    }
    void GetFigure() // метод, який виводить на екран назву фігури
    {
        cout << "Icosahedron";
    }
    double GetRadiusInscribed() // метод для отримання радіусу ВПисаного кола
    { 
        return (1.0 / (4.0 * sqrt(3.0) ) * (3.0 + sqrt(5.0) ) * side );
    }
    void SetRadiusInscribed(double r)  // метод для встановлення радіусу ВПисаного кола
    {
        side = (pow( (r / (3.0 + sqrt(5.0)) / (1.0 / (4.0 * sqrt(3.0))) ), 1.0 / 3.0));
    }
    double GetRadiusCircumscribed() // метод для отримання радіусу ОПисаного кола
    {
        return (1.0 / 4.0 * sqrt(2.0 * (5.0 + sqrt(5.0) ) ) * side );
    }
    void SetRadiusCircumscribedd(double R) // метод для встановлення радіусу ОПисаного кола
    {
        side = (R / (5.0 + sqrt(5.0))) / (1.0 / 4.0 * sqrt(2.0));
    }
    int GetCountOfApexes() // метод для отримання кількості вершин фігури 
    {
        return 12;
    }
    double GetSquare() // метод для отримання площі фігури 
    {
        return (5.0 * side * side * sqrt(3.0));
    }
    double GetPerimeter() // метод для отримання периметру фігури 
    {
        return (side * count);
    }
    void SetPerimeter(double P)  // метод для встановлення периметру фігури 
    {
        side = P / count;
    }
    double GetVolume()  // метод для отримання об'єму фігури
    {
        return (side * side * side * (5.0 / 12.0) * (3.0 + sqrt(5.0) ) );
    }
    void SetVolume(double V) // метод для встановлення об'єму фігури 
    {
        side = pow(V / (5.0 / 12.0) / (3.0 + sqrt(5.0)), 1.0 / 3.0);
    }
    void PrintInfo() // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:                          ";
        GetFigure();
        cout << endl << "Size of side:                  " << GetSide() << endl;
        cout << "Inscribed sphere radius:       " << GetRadiusInscribed() << endl;
        cout << "Circumscribed sphere radius:   " << GetRadiusCircumscribed() << endl;
        cout << "Nubmer of edges:               " << GetCountOfEdges() << endl;
        cout << "Nubmer of apexes:              " << GetCountOfApexes() << endl;
        cout << "Nubmer of faces:               " << GetCountOfFaces() << endl;
        cout << "Number of faces, adjacent to   \n";
        cout << "an edge:                       " << GetCountOfFacesNearTheEdge() << endl;
        cout << "Number of sides of the face:   " << GetCountOfSidesOfFace() << endl;
        cout << "Square:                        " << GetSquare() << endl;
        cout << "Volume:                        " << GetVolume() << endl;
        cout << "Perimeter:                     " << GetPerimeter() << endl;
    }
    Triangle& GetNewTriangle() // метод для отримання пласкої фігури,
    {                              // що представляє грань даної об’ємної фігури
        Triangle tr;
        tr.SetSide(this->GetSide());
        return tr;

    }
    void Test()  // метод для тестуввання класу
    {
        Icosahedron test;
        cout << "Enter the size of side: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();
        cout << "Enter the new perimeter: ";
        cin >> size;
        test.SetPerimeter(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed sphere radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed sphere radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new volume: ";
        cin >> size;
        test.SetVolume(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "\nNew figure\n";
        test.SetSide(5.0);
        test.PrintInfo();

        cout << "\nThis figure consists of many figures that are:\n";
        Triangle tr(test.GetNewTriangle());
        tr.PrintInfo();
    }
};
class Sphere :public Figure //Сфера
{
public:
    Sphere() : Figure() // конструктор за замовченням
    {
        count = 1;
        side = 0;
    }
    Sphere(double d) : Figure() // конструктом з параметром (довжина сторони)
    {
        if (d < 0)
            side = -d;
        else side = d;
    }
    int GetCountOfFaces()   // метод для отримання кількості граней
    {
        return 1;
    }
    int GetCountOfFacesNearTheEdge() // метод для отримання кількості граней, 
    {                                   // суміжних із вершиною
        return 1;
    }
    int GetCountOfSidesOfFace() // метод для отримання кількості сторін у грані
    {
        return 1;
    }
    void GetFigure()  // метод, який виводить на екран назву фігури
    {
        cout << "Sphere";
    }
    double GetRadiusInscribed()  // метод для отримання радіусу ВПисаного кола
    {
        return (side);
    }
    void SetRadiusInscribed(double r) // метод для встановлення радіусу ВПисаного кола
    {
        side = (r);
    }
    double GetRadiusCircumscribed() // метод для отримання радіусу ОПисаного кола
    {
        return (side);
    }
    void SetRadiusCircumscribedd(double R) // метод для встановлення радіусу ОПисаного кола
    {
        side = (R);
    }
    int GetCountOfApexes() // метод для отримання кількості вершин фігури 
    {
        return 0;
    }
    double GetSquare() // метод для отримання площі фігури 
    {
        return (4 * M_PI * side * side);
    }
    double GetPerimeter()  // метод для отримання периметру фігури 
    {
        return (side * count);
    }
    void SetPerimeter(double P)  // метод для встановлення периметру фігури
    {
    }
    double GetVolume()  // метод для отримання об'єму фігури
    {
        return (( 4.0 / 3 ) * M_PI * side * side * side);
    }
    void SetVolume(double V)  // метод для встановлення об'єму фігури 
    {
        side = pow(V / (4.0 / 3) / M_PI, 1.0 / 3);
    }
    void PrintInfo()  // метод для виведення всієї інформації про фігуру на екран
    {
        cout << "Name:                          ";
        GetFigure();
        cout << endl << "Radius:                        " << GetSide() << endl;
        cout << "Inscribed sphere radius:       " << GetRadiusInscribed() << endl;
        cout << "Circumscribed sphere radius:   " << GetRadiusCircumscribed() << endl;
        cout << "Nubmer of edges:               " << GetCountOfEdges() << endl;
        cout << "Nubmer of apexes:              " << GetCountOfApexes() << endl;
        cout << "Nubmer of faces:               " << GetCountOfFaces() << endl;
        cout << "Number of faces, adjacent to   \n";
        cout << "an edge:                       " << GetCountOfFacesNearTheEdge() << endl;
        cout << "Number of sides of the face:   " << GetCountOfSidesOfFace() << endl;
        cout << "Square:                        " << GetSquare() << endl;
        cout << "Volume:                        " << GetVolume() << endl;
        cout << "Length:                        " << GetPerimeter() << endl;
    }
    Circle& GetNewCircle()  // метод для отримання пласкої фігури, 
    {                         // що представляє грань даної об’ємної фігури
        Circle sp;
        sp.SetSide(GetSide());
        return sp;

    }
    void Test()  // метод для тестуввання класу
    {
        Sphere test;
        cout << "Enter the size of side: ";
        double size;
        cin >> size;
        test.SetSide(size);
        cout << "Your figure:\n";
        test.PrintInfo();

        cout << "Enter the new Inscribed sphere radius: ";
        cin >> size;
        test.SetRadiusInscribed(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new Circumscribed sphere radius: ";
        cin >> size;
        test.SetRadiusCircumscribedd(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "Enter the new volume: ";
        cin >> size;
        test.SetVolume(size);
        cout << "\nYour figure is is modified:\n";
        test.PrintInfo();

        cout << "\nNew figure\n";
        test.SetSide(5.0);
        test.PrintInfo();

        cout << "\nThis figure consists of many figures that are:\n";
        Circle sp(test.GetNewCircle());
        sp.PrintInfo();
    }
};



//////////////////////////////////////////////////////////////////////
//                      тестування                                  //



void TestFunction(Figure *f) // поліморфна функція, яка отримає вказівник 
{                           // на базовий клас і через нього звертаєтться 
    f->Test();             // до методів класів-нащадків 
}
int main()
{
    int tr = 0, sq = 0, pt = 0, hg = 0, cl = 0;  // змінн для підрахунку 2Д фігур 
    int tetra = 0, hexa = 0, octa = 0, ico = 0, dode = 0, sph = 0;
                                                //// змінн для підрахунку 3Д фігур 
    Figure* f = nullptr;
    int number1, number2;
    while (true)      // під час тестування клієнт сам обирає тип фігури і саму фігуру.
    {                   
        system("cls"); // головне меню 
        cout << "Enter 1 to test 2-dimensional shapes (2D)" << endl;
        cout << "Enter 2 to test 3-dimensional shapes (3D)" << endl;
        cout << "Enter 3 to finish the program" << endl;
        cin >> number1;
        
        if (number1 == 1)  
        {
            bool key = true;
            while (key == true)
            {
                system("cls");  // меню для обрання і тестування 2Д фігури
                cout << "Which 2D figure do you want to create?" << endl;
                cout << "1 - triangle" << endl;
                cout << "2 - square" << endl;
                cout << "3 - pentagon" << endl;
                cout << "4 - hexagon" << endl;
                cout << "5 - circle (optional)" << endl;
                cout << "6 - back to main menu" << endl;
                cin >> number2;
                if (number2 == 1)
                {
                    f = new Triangle();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 2) 
                {
                    f = new Square();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 3)
                {
                    f = new Pentagon();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 4)
                {
                    f = new Hexagon();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 5)
                {
                    f = new Circle();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 6)
                {
                    key = false;
                }
                else 
                {
                    cout << endl << endl << "You have entered wrong number" << endl;
                    system("pause");
                    continue;
                }
                if (key == true) 
                {
                    Triangle* t = nullptr; // створення вказывників на всі види 2Д
                    Square* s = nullptr;  // фігур. Завдяки цим вказівникам і завдяки
                    Pentagon* p = nullptr; // технології dynamic_cast буде з'ясовано
                    Hexagon* h = nullptr; // з яким об'єктом відпрацювала прогама на 
                    Circle* c = nullptr;  // кожній ітерації. Також буде підраховано 
                                         // кількість використання кожного об'єкту
                    t = dynamic_cast<Triangle*>(f);
                    if (t)               // з'ясування, чи вказує вказівник f 
                        tr++;            // на об'єкт класу Triangle. 
                    else
                    {
                        s = dynamic_cast<Square*>(f); 
                        if (s)              // з'ясування, чи вказує вказівник f 
                            sq++;           // на об'єкт класу Square.
                        else                                    // далі за аналогією
                        {
                            p = dynamic_cast<Pentagon*>(f);
                            if (p)
                                pt++;
                            else
                            {
                                h = dynamic_cast<Hexagon*>(f);
                                if (h)
                                    hg++;
                                else
                                    cl++;
                            }
                        }
                    }
                    delete f;
                }
            }
            
        }
        else if (number1 == 2) // меню для обрання і тестування 3Д фігури
        {
            bool key = true;
            while (key == true)
            {
                system("cls");
                cout << "Which 3D figure do you want to create?" << endl;
                cout << "1 - tetrahedron" << endl;
                cout << "2 - hexahedron" << endl;
                cout << "3 - octahedron" << endl;
                cout << "4 - dodecahedron" << endl;
                cout << "5 - icosahedron" << endl;
                cout << "6 - sphere (optional)" << endl;
                cout << "7 - back to main menu" << endl;
                cin >> number2;
                if (number2 == 1)
                {
                    f = new Tetrahedron();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 2)
                {
                    f = new Hexahedron();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 3)
                {
                    f = new Octahedron();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 4)
                {
                    f = new Dodecahedron();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 5)
                {
                    f = new Icosahedron();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 6)
                {
                    f = new Sphere();
                    TestFunction(f);
                    system("pause");
                }
                else if (number2 == 7)
                {
                    key = false;
                }
                else
                {
                    cout << endl << endl << "You have entered wrong number" << endl;
                    system("pause");
                    continue;
                }
                if (key == true) 
                {
                    Tetrahedron* t = nullptr;
                    Hexahedron* h = nullptr;
                    Octahedron* o = nullptr;
                    Dodecahedron* d = nullptr;
                    Icosahedron* i = nullptr;
                    Sphere* s = nullptr;

                    t = dynamic_cast<Tetrahedron*>(f);
                    if (t)
                        tetra++;
                    else
                    {
                        h = dynamic_cast<Hexahedron*>(f);
                        if (h)
                            hexa++;
                        else
                        {
                            o = dynamic_cast<Octahedron*>(f);
                            if (o)
                                pt++;
                            else
                            {
                                d = dynamic_cast<Dodecahedron*>(f);
                                if (d)
                                    dode++;
                                else
                                {
                                    i = dynamic_cast<Icosahedron*>(f);
                                    if (i)
                                        ico++;
                                    else sph++;
                                }
                            }
                        }
                    }
                    delete f;
                }
            }
        }
        else if (number1 == 3)
        {
            break;
        }
        else 
        {
            cout << endl << endl << "You have entered wrong number" << endl;
            system("pause");
        }
    }
    
    // виведення загальної кількості протестованих об'єктів,
    // а також скільки разів кожний клас був протестований
    int count_of_obj = tr + sq + pt + hg + cl + tetra + hexa + octa + ico + dode + sph;
    cout << endl << "Objects tested: " << count_of_obj << endl;

    cout << endl << "2D shapes:" << endl;
    cout << "Triangles:  " << tr << endl;
    cout << "Squares:    " << sq << endl;
    cout << "Pentagones: " << pt << endl;
    cout << "Hexagones:  " << hg << endl;
    cout << "Circles:    " << cl << endl;

    cout << endl << "3D shapes:" << endl;
    cout << "Tetrahedron:  " << tetra << endl;
    cout << "Hexahedron:   " << hexa << endl;
    cout << "Octahedron:   " << octa << endl;
    cout << "Dodecahedron: " << ico << endl;
    cout << "Icosahedron:  " << dode << endl;
    cout << "Sphere:       " << sph << endl;

}