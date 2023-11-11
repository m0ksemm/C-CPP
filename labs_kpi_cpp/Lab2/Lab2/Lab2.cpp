#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
//КВ-12, Дубіковська Дана-Дарина, варіант 2

//Модель ієрархії фігур:
//                   _triangle     _square     _pentagon     _hexagon     _sircle     
//                  /             /           /             /            /                 
//        _figure2D -----------------------------------------------------
//       /
//_figure 
//       \
//        _figure3D ------------------------------------------------------------------------
//                   \             \             \            \               \              \
//                    _tetrahedron  _octahedron   _hexahedron  _dodecahedron   _icosahedron   _sphere

//__________________________________________________________________________________________________
//__________________________________________________________________________________________________
//__________________________________________________________________________________________________

class _figure  
{
protected:
    int n;  
    double side; 
public:
    _figure() 
    {
        n = 0;
        side = 0;
    }  

    void set_side(double value)
    {
        if (value < 0) 
            side = -value;   
        else side = value;    
    }
    double get_side()
    {
        return side;
    }
    int get_edges()
    {
        return n;
    }

    virtual string get_figure() = 0;
    virtual void set_radius_1(double r) {
    }
    virtual double get_radius_2() = 0;
    virtual void test_figure() {
    }
    virtual void set_radius_2(double r) {
    }
    virtual double get_square() = 0;
    virtual int get_apexes() = 0;
    virtual double get_radius_1() = 0;
    virtual void info_output() {
    }
    
};

//__________________________________________________________________________________________________
class _figure2D : public _figure
{
    virtual double perimeter() = 0;
    virtual void set_perimeter() {
    }
};

//__________________________________________________________________________________________________
class _figure3D : public _figure
{
    virtual double volume() = 0;
    virtual void set_volume() {
    }
};

//__________________________________________________________________________________________________
//__________________________________________________________________________________________________
//__________________________________________________________________________________________________

class _triangle : public _figure2D // трикутник
{
public:
    _triangle() : _figure2D() {
        n = 3;
        side = 0;
    }
    _triangle(double value) : _triangle() {
        if (value < 0)
            side = -value;
        else side = value;
    }
    _triangle(_triangle& t) : _triangle() {                                       
        n = t.get_edges();
        side = t.get_side();
    }
    string get_figure()  {
        return "Triangle";
    }
    double get_radius_2()   {
        return (side / sqrt(3));
    }
    void set_radius_2(double R)   {
        side = R * sqrt(3);
    }
    int get_apexes() {
        return 3;
    }
    double get_radius_1() {
        return (side / (2 * sqrt(3)));
    }
    void set_radius_1(double r) {
        side = r * (2 * sqrt(3));
    }
    double get_square()  {
        return ((side * side * sqrt(3)) / 4);
    }
    double perimeter()  {
        return (side * 3);
    }
    void set_perimeter(double P)  {
        side = P / 3;
    }
    void info_output()   {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Size of side:                |  " << get_side() << endl;
        cout << "| Inscribed radius:            |  " << get_radius_1() << endl;
        cout << "| Circumscribed radius:        |  " << get_radius_2() << endl;
        cout << "| Nubmer of edges:             |  " << get_edges() << endl;
        cout << "| Nubmer of apexes:            |  " << get_apexes() << endl;
        cout << "| Square:                      |  " << get_square() << endl;
        cout << "| Perimeter:                   |  " << perimeter() << endl;
    }
    void test_figure() {
        _triangle test;

        test.set_side(3);
        cout << "Figure:" << endl;
        test.info_output();

        test.set_perimeter(15);
        cout << "\nNew perimeter was settled was settled: 15" << endl;
        test.info_output();

        test.set_radius_1(33);
        cout << "\nNew inscribed circle radius was settled: 33" << endl;
        test.info_output();

        test.set_radius_2(21);
        cout << "\nNew circumscribed circle radius was settled: 21" << endl;
        test.info_output();
    }
};

//__________________________________________________________________________________________________
class _square : public _figure2D
{
public:
    _square() : _figure2D() {
        n = 4;
        side = 0;
    }
    _square(double d) : _square()  {
        if (d < 0)
            side = -d;
        else side = d;
    }
    _square(_square& sq) : _square()  {                                   
        n = 4;
        side = sq.get_side();
    }
    string get_figure()  {
        return "Square";
    }
    double get_radius_1()   {
        return (side / 2);
    }
    void set_radius_1(double r)   {
        side = r * 2;
    }
    double get_radius_2()  {
        return sqrt(side * side * 2);
    }
    void set_radius_2(double R) {
        side = sqrt((R * R) / 2);
    }
    int get_apexes()  {
        return 4;
    }
    double get_square()  {
        return (side * side);
    }
    double perimeter() {
        return (side * 4);
    }
    void set_perimeter(double P) {
        side = double(P) / 4.0;
    }
    void info_output() {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Size of side:                |  " << get_side() << endl;
        cout << "| Inscribed radius:            |  " << get_radius_1() << endl;
        cout << "| Circumscribed radius:        |  " << get_radius_2() << endl;
        cout << "| Nubmer of edges:             |  " << get_edges() << endl;
        cout << "| Nubmer of apexes:            |  " << get_apexes() << endl;
        cout << "| Square:                      |  " << get_square() << endl;
        cout << "| Perimeter:                   |  " << perimeter() << endl;
    }
    void test_figure() {
        _square s;

        s.set_side(10);
        cout << "Figure:" << endl;
        s.info_output();
        
        s.set_perimeter(320);
        cout << "\nNew perimeter was settled: 320" << endl;
        s.info_output();

        s.set_radius_1(35);
        cout << "\nNew Inscribed circle radius was settled: 35" << endl;
        s.info_output();

        s.set_radius_2(27);
        cout << "\nNew circumscribed circle radius was settled: 27" << endl;
        s.info_output();
    }
};

//__________________________________________________________________________________________________
class _pentagon : public _figure2D
{
public:
    _pentagon() : _figure2D() {
        n = 5;
        side = 0;
    }
    _pentagon(double d) : _pentagon()  {
        if (d < 0)
            side = -d;
        else side = d;
    }
    string get_figure()  {
        return "Pentagon";
    }
    double get_radius_1()  {
        return (get_radius_2() * 0.809016994374947);
    }
    void set_radius_1(double r)  {
        side = r * (2.0 * sqrt(5.0 - 2.0 * sqrt(5.0)));
    }
    double get_radius_2()  {
        return (side / (2.0 * 0.587785252292473));
    }
    void set_radius_2(double R)  {
        side = R * (2 * 0.587785252292473);
    }
    int get_apexes()  {
        return 5;
    }
    double get_square() {
        return ((side * side * sqrt(25 + 10 * sqrt(5.0))) / 4.0);
    }
    double perimeter()  {
        return (side * 5);
    }
    void set_perimeter(double P) {
        side = P / 5;
    }
    void info_output()  {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Size of side:                |  " << get_side() << endl;
        cout << "| Inscribed radius:            |  " << get_radius_1() << endl;
        cout << "| Circumscribed radius:        |  " << get_radius_2() << endl;
        cout << "| Nubmer of edges:             |  " << get_edges() << endl;
        cout << "| Nubmer of apexes:            |  " << get_apexes() << endl;
        cout << "| Square:                      |  " << get_square() << endl;
        cout << "| Perimeter:                   |  " << perimeter() << endl;
    }
    void test_figure() {
        _pentagon p;

        p.set_side(45);
        cout << "\nFigure:" << endl;
        p.info_output();

        p.set_perimeter(550);
        cout << "\nNew perimeter was settled: 550" << endl;
        p.info_output();

        p.set_radius_1(115);
        cout << "\nNew inscribed circle radius was settled: 115" << endl;
        p.info_output();

        p.set_radius_2(35);
        cout << "\nNew circumscribed circle radius was settled: 35" << endl;
        p.info_output();

    }
};

//__________________________________________________________________________________________________
class _hexagon : public _figure2D
{
public:
    _hexagon() : _figure2D() {
        n = 6;
        side = 0;
    }
    _hexagon(double d) : _hexagon()  {
        if (d < 0)
            side = -d;
        else side = d;
    }
    _hexagon(_hexagon& h) : _hexagon()  {                                   
        n = 6;
        side = h.get_side();
    }
    string get_figure()   {
        return "Hexagon";
    }
    double get_radius_1()  {
        return (sqrt(3) / 2 * side);
    }
    void set_radius_1(double r)  {
        side = r / (sqrt(3) / 2);
    }
    double get_radius_2() {
        return (side);
    }
    void set_radius_2(double R)   {
        side = R;
    }
    int get_apexes()  {
        return 6;
    }
    double get_square() {
        return ((3 * sqrt(3) * side * side) / 2);
    }
    double perimeter()  {
        return (side * 6);
    }
    void set_perimeter(double P)  {
        side = P / 6;
    }
    void info_output()  {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Size of side:                |  " << get_side() << endl;
        cout << "| Inscribed radius:            |  " << get_radius_1() << endl;
        cout << "| Circumscribed radius:        |  " << get_radius_2() << endl;
        cout << "| Nubmer of edges:             |  " << get_edges() << endl;
        cout << "| Nubmer of apexes:            |  " << get_apexes() << endl;
        cout << "| Square:                      |  " << get_square() << endl;
        cout << "| Perimeter:                   |  " << perimeter() << endl;
    }
    void test_figure() {
        _hexagon h;

        h.set_side(18);
        cout << "Figure:" << endl;
        h.info_output();

        h.set_perimeter(60);
        cout << "\nNew perimeter was settled: 60" << endl;
        h.info_output();

        h.set_radius_1(13);
        cout << "\nNew inscribed circle radius was settled: 13" << endl;
        h.info_output();

        cout << "\nNew circumscribed circle radius was settled: 15" << endl;
        h.set_radius_2(15);
        h.info_output();
    }
};

//__________________________________________________________________________________________________
class _circle : public _figure2D
{
public:
    _circle() : _figure2D() {
        n = 0;
        side = 0;
    }
    _circle(double radius) : _circle() {
        if (radius < 0)
            side = -radius;
        else side = radius;
    }
    _circle(_circle& c) : _circle() {                               
        n = 1;
        side = c.get_side();
    }
    string get_figure() {
        return "Circle";
    }
    double get_square() {
        return (M_PI * side * side);
    }
    double perimeter() {
        return (2 * M_PI * side);
    }
    void set_perimeter(double P) {
        side = P / (2 * M_PI);
    }
    void info_output() {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Radius:                   |  " << get_side() << endl;
        cout << "| Square:                   |  " << get_square() << endl;
        cout << "| Length:                   |  " << perimeter() << endl;
    }

    double get_radius_1() {
        return side;
    }
    void set_radius_1(double r) {
        side = r;
    }
    double get_radius_2() {
        return side;
    }
    void set_radius_2(double r) {
        side = r;
    }   
    int get_apexes()  {
        return 0;
    }
    void test_figure() {
        _circle c;
        c.set_side(10);
        cout << "Figure:" << endl;
        c.info_output();

        c.set_perimeter(50);
        cout << "\nNew length of circle was settled: 50";
        c.info_output();

        c.set_radius_1(14);
        cout << "\nNew inscribed circle radius: 14";
        c.info_output();

        c.set_radius_2(12);
        cout << "\nNew circumscribed circle radius was settled: 12";
        c.info_output();
    }
};

//__________________________________________________________________________________________________
//__________________________________________________________________________________________________
//__________________________________________________________________________________________________

class _tetrahedron :public _figure3D
{
public:
    _tetrahedron() : _figure3D() {
        n = 6;
        side = 0;
    }
    _tetrahedron(double d) : _figure3D() {
        if (d < 0)
            side = -d;
        else side = d;
    }
    int get_faces() {
        return 4;
    }
    int get_faces_edge() {
        return 3;
    }
    int GetCountOfSidesOfFace() {
        return 3;
    }
    string get_figure() {
        return "Tetrahedron";
    }
    double get_radius_1() {
        return (side * sqrt(6) / 12);
    }
    void set_radius_1(double r) {
        side = (r * 12) / sqrt(6);
    }
    double get_radius_2() {
        return (side * sqrt(6) / 4);
    }
    void set_radius_2(double R) {
        side = (R * 4) / sqrt(6);
    }
    int get_apexes() {
        return 4;
    }
    double get_square() {
        return (side * side * sqrt(3));
    }
    double volume() {
        return (side * side * side * sqrt(2) / 12);
    }
    void set_volume(double V) {
        side = pow(V * 12 / sqrt(2), 1.0 / 3);
    }
    void info_output() {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Size of 1 side:       |  " << get_side() << endl;
        cout << "| Inscribed radius:     |  " << get_radius_1() << endl;
        cout << "| Circumscribed radius: |  " << get_radius_2() << endl;
        cout << "| Apexes:               |  " << get_apexes() << endl;
        cout << "| Edges:                |  " << get_edges() << endl;
        cout << "| Faces:                |  " << get_faces() << endl;
        cout << "| Faces near 1 edge     |  " << get_faces_edge() << endl;
        cout << "| Sides of 1 face:      |  " << GetCountOfSidesOfFace() << endl;
        cout << "| Square:               |  " << get_square() << endl;
        cout << "| Volume:               |  " << volume() << endl;
    }
    _triangle& GetNewTriangle() {
        _triangle tr;
        tr.set_side(this->get_side());
        return tr;
    }
    void test_figure() {
        _tetrahedron t;

        t.set_side(7);
        cout << "Figure:\n";
        t.info_output();
        
        cout << "\nThis figure is made of:" << endl;
        _triangle tr(t.GetNewTriangle());
        tr.info_output();

        cout << "\nNew inscribed sphere radius was settled: 8";
        t.set_radius_1(8);
        t.info_output();

        cout << "\nNew circumscribed sphere radius was settled: 13" << endl;
        t.set_radius_2(13);
        t.info_output();

        cout << "\nNew volume was settled: 500";
        t.set_volume(500);
        t.info_output();
    }
};

//__________________________________________________________________________________________________
class _octahedron :public _figure3D
{
public:
    _octahedron() : _figure3D() {
        n = 12;
        side = 0;
    }
    _octahedron(double d) : _figure3D() {
        if (d < 0)
            side = -d;
        else side = d;
    }
    int get_faces() {
        return 8;
    }
    int get_faces_edge() {
        return 4;
    }
    int GetCountOfSidesOfFace() {
        return 3;
    }
    string get_figure() {
        return "Octahedron";
    }
    double get_radius_1() {
        return (side / 6 * sqrt(6));
    }
    void set_radius_1(double r) {
        side = (r / sqrt(6) * 6);
    }
    double get_radius_2() {
        return (side / 2 * sqrt(2));
    }
    void set_radius_2(double R) {
        side = (R / sqrt(2) * 2);
    }
    int get_apexes() {
        return 6;
    }
    double get_square() {
        return (2 * side * side * sqrt(3));
    }
    double volume() {
        return (side * side * side * sqrt(2) / 3);
    }
    void set_volume(double V) {
        side = pow(V * 3 / sqrt(2), 1.0 / 3);
    }
    void info_output() {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Size of 1 side:       |  " << get_side() << endl;
        cout << "| Inscribed radius:     |  " << get_radius_1() << endl;
        cout << "| Circumscribed radius: |  " << get_radius_2() << endl;
        cout << "| Apexes:               |  " << get_apexes() << endl;
        cout << "| Edges:                |  " << get_edges() << endl;
        cout << "| Faces:                |  " << get_faces() << endl;
        cout << "| Faces near 1 edge     |  " << get_faces_edge() << endl;
        cout << "| Sides of 1 face:      |  " << GetCountOfSidesOfFace() << endl;
        cout << "| Square:               |  " << get_square() << endl;
        cout << "| Volume:               |  " << volume() << endl;
    }
    _triangle& GetNewTriangle() {
        _triangle t;
        t.set_side(this->get_side());
        return t;

    }
    void test_figure() {
        _octahedron o;

        o.set_side(15);
        cout << "Figure:" << endl;
        o.info_output();

        cout << "\nThis figure is made of:" << endl;
        _triangle t(o.GetNewTriangle());
        t.info_output();

        cout << "\nNew inscribed sphere radius was settled: 17" << endl;
        o.set_radius_1(17);
        o.info_output();

        cout << "\nNew circumscribed sphere radius was settled: 11" << endl;
        o.set_radius_2(11);
        o.info_output();

        cout << "\nNew volume was settled: 550" << endl;
        o.set_volume(550);
        o.info_output();

    }
};

//__________________________________________________________________________________________________
class _hexahedron :public _figure3D
{
public:
    _hexahedron() : _figure3D() {
        n = 12;
        side = 0;
    }
    _hexahedron(double d) : _figure3D() {
        n = 12;
        if (d < 0)
            side = -d;
        else side = d;
    }
    int get_faces() {
        return 6;
    }
    int get_faces_edge() {
        return 3;
    }
    int GetCountOfSidesOfFace() {
        return 4;
    }
    string get_figure() {
        return "Hexahedron";
    }
    double get_radius_1() {
        return (side / 2);
    }
    void set_radius_1(double r) {
        side = r * 2;
    }
    double get_radius_2()  {
        return (side / 2 * sqrt(3));
    }
    void set_radius_2(double R) {
        side = (R / sqrt(3) * 2);
    }
    int get_apexes() {
        return 8;
    }
    double get_square() {
        return (side * side * 6);
    }

    double volume() {
        return (side * side * side);
    }
    void set_volume(double V) {
        side = pow(V, 1.0 / 3);
    }
    void info_output() {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Size of 1 side:       |  " << get_side() << endl;
        cout << "| Inscribed radius:     |  " << get_radius_1() << endl;
        cout << "| Circumscribed radius: |  " << get_radius_2() << endl;
        cout << "| Apexes:               |  " << get_apexes() << endl;
        cout << "| Edges:                |  " << get_edges() << endl;
        cout << "| Faces:                |  " << get_faces() << endl;
        cout << "| Faces near 1 edge     |  " << get_faces_edge() << endl;
        cout << "| Sides of 1 face:      |  " << GetCountOfSidesOfFace() << endl;
        cout << "| Square:               |  " << get_square() << endl;
        cout << "| Volume:               |  " << volume() << endl;
    }
    _square& GetNewSquare()  {
        _square sq;
        sq.set_side(this->get_side());
        return sq;

    }
    void test_figure() {
        _hexahedron h;

        h.set_side(11);
        cout << "Figure:" << endl;
        h.info_output();

        cout << "\nThis figure is made of:" << endl;
        _square s(h.GetNewSquare());
        s.info_output();

        cout << "\nNew inscribed sphere radius was settled: 9";
        h.set_radius_1(9);
        h.info_output();

        cout << "\nNew circumscribed sphere radius was settled: 15";
        h.set_radius_2(15);
        h.info_output();

        cout << "\nNew volume was settled: 700";
        set_volume(700);
        h.info_output();
    }
};

//__________________________________________________________________________________________________
class _dodecahedron :public _figure3D
{
public:
    _dodecahedron() : _figure3D() {
        n = 30;
        side = 0;
    }
    _dodecahedron(double d) : _figure3D() {
        if (d < 0)
            side = -d;
        else side = d;
    }
    int get_faces()  {
        return 12;
    }
    int get_faces_edge()  {
        return 3;
    }
    int GetCountOfSidesOfFace() {
        return 5;
    }
    string get_figure()  {
        return "Dodecahedron";
    }
    double get_radius_1() {
        return (side / 4 * sqrt(10 + 22.0 / sqrt(5.0)));
    }
    void set_radius_1(double r) {
        side = (r / sqrt(10.0 + 22.0 / sqrt(5.0)) * 4.0);
    }
    double get_radius_2() {
        return (side / 4 * sqrt(3.0) * (1 + sqrt(5.0)));
    }
    void set_radius_2(double R) {
        side = (R / (1 + sqrt(5.0)) / sqrt(3.0) * 4);
    }
    int get_apexes()  {
        return 20;
    }
    double get_square()  {
        return (3.0 * side * side * sqrt(5.0 * (5.0 + 2.0 * sqrt(5.0))));
    }
    double volume()  {
        return ((side * side * side) / 4.0 * (15.0 + 7.0 * sqrt(5.0)));
    }
    void set_volume(double V) {
        side = pow(V / ((15.0 + 7.0 * sqrt(5.0)) * 4.0), 1.0 / 3.0);
    }
    void info_output() {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Size of 1 side:       |  " << get_side() << endl;
        cout << "| Inscribed radius:     |  " << get_radius_1() << endl;
        cout << "| Circumscribed radius: |  " << get_radius_2() << endl;
        cout << "| Apexes:               |  " << get_apexes() << endl;
        cout << "| Edges:                |  " << get_edges() << endl;
        cout << "| Faces:                |  " << get_faces() << endl;
        cout << "| Faces near 1 edge     |  " << get_faces_edge() << endl;
        cout << "| Sides of 1 face:      |  " << GetCountOfSidesOfFace() << endl;
        cout << "| Square:               |  " << get_square() << endl;
        cout << "| Volume:               |  " << volume() << endl;
    }
    _triangle& GetNewTriangle() {                         
        _triangle t;
        t.set_side(this->get_side());
        return t;
    }
    void test_figure()  {
        _dodecahedron d;
        d.set_side(8);
        cout << "Figure:" << endl;
        d.info_output();
        
        cout << "\nThis figure is made of:" << endl;
        _triangle tr(d.GetNewTriangle());
        tr.info_output();

        cout << "\nNew inscribed sphere radius was settled: 9" << endl;
        d.set_radius_1(9);
        d.info_output();

        cout << "\nNew circumscribed sphere radius was settled: 11";
        d.set_radius_2(11);
        d.info_output();

        cout << "\nNew volume was settled: 225";
        d.set_volume(225);
        d.info_output();
    }
};

//__________________________________________________________________________________________________
class _icosahedron :public _figure3D
{
public:
    _icosahedron() : _figure3D() {
        n = 30;
        side = 0;
    }
    _icosahedron(double d) : _figure3D() {
        if (d < 0)
            side = -d;
        else side = d;
    }
    int get_faces() {
        return 20;
    }
    int get_faces_edge() {
        return 5;
    }
    int GetCountOfSidesOfFace() {
        return 3;
    }
    string get_figure() {
        return "Icosahedron";
    }
    double get_radius_1() {
        return (1.0 / (4.0 * sqrt(3.0)) * (3.0 + sqrt(5.0)) * side);
    }
    void set_radius_1(double r)  {
        side = (pow((r / (3.0 + sqrt(5.0)) / (1.0 / (4.0 * sqrt(3.0)))), 1.0 / 3.0));
    }
    double get_radius_2() {
        return (1.0 / 4.0 * sqrt(2.0 * (5.0 + sqrt(5.0))) * side);
    }
    void set_radius_2(double R) {
        side = (R / (5.0 + sqrt(5.0))) / (1.0 / 4.0 * sqrt(2.0));
    }
    int get_apexes()  {
        return 12;
    }
    double get_square()  {
        return (5.0 * side * side * sqrt(3.0));
    }
    double volume() {
        return (side * side * side * (5.0 / 12.0) * (3.0 + sqrt(5.0)));
    }
    void set_volume(double V) {
        side = pow(V / (5.0 / 12.0) / (3.0 + sqrt(5.0)), 1.0 / 3.0);
    }
    void info_output() {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Size of 1 side:       |  " << get_side() << endl;
        cout << "| Inscribed radius:     |  " << get_radius_1() << endl;
        cout << "| Circumscribed radius: |  " << get_radius_2() << endl;
        cout << "| Apexes:               |  " << get_apexes() << endl;
        cout << "| Edges:                |  " << get_edges() << endl;
        cout << "| Faces:                |  " << get_faces() << endl;
        cout << "| Faces near 1 edge     |  " << get_faces_edge() << endl;
        cout << "| Sides of 1 face:      |  " << GetCountOfSidesOfFace() << endl;
        cout << "| Square:               |  " << get_square() << endl;
        cout << "| Volume:               |  " << volume() << endl;
    }
    _triangle& GetNewTriangle() {
        _triangle t;
        t.set_side(this->get_side());
        return t;

    }
    void test_figure() {
        _icosahedron i;

        i.set_side(5);
        cout << "Figure:\n";
        i.info_output();

        cout << "\nThis figure is made of:" << endl;
        _triangle t(i.GetNewTriangle());
        t.info_output();

        cout << "\nNew inscribed sphere radius was settled: 10";
        i.set_radius_1(10);
        i.info_output();

        cout << "\nNew circumscribed sphere radius was settled: 15";
        i.set_radius_2(15);
        i.info_output();

        cout << "\nNew volume was settled: 300";
        i.set_volume(300);
        i.info_output();
    }
};

//__________________________________________________________________________________________________
class _sphere :public _figure3D
{
public:
    _sphere() : _figure3D() {
        n = 1;
        side = 0;
    }
    _sphere(double d) : _figure3D() {
        if (d < 0)
            side = -d;
        else side = d;
    }
    int get_faces() {
        return 1;
    }
    int get_faces_edge() {                                  
        return 1;
    }
    int GetCountOfSidesOfFace() {
        return 1;
    }
    string get_figure() {
        return "Sphere";
    }
    double get_radius_1() {
        return (side);
    }
    void set_radius_1(double r) {
        side = (r);
    }
    double get_radius_2() {
        return (side);
    }
    void set_radius_2(double R) {
        side = (R);
    }
    int get_apexes() {
        return 0;
    }
    double get_square() {
        return (4 * M_PI * side * side);
    }
    double perimeter() {
        return (side * n);
    }
    void set_perimeter(double P) {
    }
    double volume() {
        return ((4.0 / 3) * M_PI * side * side * side);
    }
    void set_volume(double V) {
        side = pow(V / (4.0 / 3) / M_PI, 1.0 / 3);
    }
    void info_output() {
        cout << endl;
        cout << " ____________________________________________" << endl;
        cout << "| \t\t" << get_figure() << endl;
        cout << "| Size of 1 side:       |  " << get_side() << endl;
        cout << "| Inscribed radius:     |  " << get_radius_1() << endl;
        cout << "| Circumscribed radius: |  " << get_radius_2() << endl;
        cout << "| Apexes:               |  " << get_apexes() << endl;
        cout << "| Edges:                |  " << get_edges() << endl;
        cout << "| Faces:                |  " << get_faces() << endl;
        cout << "| Faces near 1 edge     |  " << get_faces_edge() << endl;
        cout << "| Sides of 1 face:      |  " << GetCountOfSidesOfFace() << endl;
        cout << "| Square:               |  " << get_square() << endl;
        cout << "| Volume:               |  " << volume() << endl;
    }
    _circle& GetNewCircle()  {                     
        _circle s;
        s.set_side(get_side());
        return s;

    }
    void test_figure() {
        _sphere s;
        s.set_side(16);
        cout << "Figure:" << endl;
        s.info_output();

        cout << "\nThis figure is made of:" << endl;
        _circle sp(s.GetNewCircle());
        sp.info_output();

        s.set_radius_1(12);
        cout << "\nNew inscribed sphere radius was settled. 12" << endl;
        s.info_output();

        s.set_radius_2(6);
        cout << "\nNew circumscribed sphere radius was settled. 6" << endl;
        s.info_output();

        s.set_volume(100);
        cout << "\nNew volume was settled: 100" << endl;
        s.info_output();
    }
};

//__________________________________________________________________________________________________
//__________________________________________________________________________________________________
//__________________________________________________________________________________________________

void test(_figure* f) {   
    system("cls");
    f->test_figure();   
}

//__________________________________________________________________________________________________
//__________________________________________________________________________________________________
//__________________________________________________________________________________________________

int main()
{
    _figure *figure = nullptr;
    int key;
    bool flag = true;
    while (flag == true) {
    
        system("cls");
        cout << "2D figures" << endl;
        cout << "1 - class _triangle;" << endl;
        cout << "2 - class _square;" << endl;
        cout << "3 - class _pentagon;" << endl;
        cout << "4 - class _hexagon;" << endl;
        cout << "5 - class _circle;" << endl << endl;

        cout << "3D figures" << endl;
        cout << "6  - class _tetrahedron;" << endl;
        cout << "7  - class _octahedron;" << endl;
        cout << "8  - class _hexahedron;" << endl;
        cout << "9  - class _dodecahedron;" << endl;
        cout << "10 - class _icosahedron;" << endl;
        cout << "11 - class _sphere;" << endl << endl;

        cout << "0 - exit." << endl;

        cin >> key;

        if (key == 1) {
            figure = new _triangle();
        }
        else if (key == 2) {
            figure = new _square();
        }
        else if (key == 3) {
            figure = new _pentagon();
        }
        else if (key == 4) {
            figure = new _hexagon();
        }
        else if (key == 5) {
            figure = new _circle();
        }
        else if (key == 6) {
            figure = new _tetrahedron();
        }
        else if (key == 7) {
            figure = new _octahedron();
        }
        else if (key == 8) {
            figure = new _hexahedron();
        }
        else if (key == 9) {
            figure = new _dodecahedron();
        }
        else if (key == 10) {
            figure = new _icosahedron();
        }
        else if (key == 11) {
            figure = new _sphere();
        }
        else if (key == 0)
        {
            flag = false;
            break;
        }
        else continue;

        test(figure);

        if (flag == true)
        {
            _triangle* t = nullptr;
            _square* s = nullptr;
            _pentagon* p = nullptr;
            _hexagon* h = nullptr;
            _circle* c = nullptr; 

            _tetrahedron* _t = nullptr;
            _hexahedron* _h = nullptr;
            _octahedron* _o = nullptr;
            _dodecahedron* _d = nullptr;
            _icosahedron* _i = nullptr;

            t = dynamic_cast<_triangle*>(figure);
            if (t)
                cout << endl << endl << "Triangle was tested" << endl;
            else
            {
                s = dynamic_cast<_square*>(figure);
                if (s)
                    cout << endl << endl << "Square was tested" << endl;
                else
                {
                    p = dynamic_cast<_pentagon*>(figure);
                    if (p)
                        cout << endl << endl << "Pentagon was tested" << endl;
                    else
                    {
                        h = dynamic_cast<_hexagon*>(figure);
                        if (h)
                            cout << endl << endl << "Hexagon was tested" << endl;
                        else
                        {
                            c = dynamic_cast<_circle*>(figure);
                            if (c)
                                cout << endl << endl << "Circle was tested" << endl;
                            else {
                                
                                _t = dynamic_cast<_tetrahedron*>(figure);
                                if (_t)
                                    cout << endl << endl << "Tetrahedron was tested" << endl;
                                else
                                {
                                    _h = dynamic_cast<_hexahedron*>(figure);
                                    if (_h)
                                        cout << endl << endl << "Hexahedron was tested" << endl;
                                    else
                                    {
                                        _o = dynamic_cast<_octahedron*>(figure);
                                        if (_o)
                                            cout << endl << endl << "Octahedron was tested" << endl;
                                        else
                                        {
                                            _d = dynamic_cast<_dodecahedron*>(figure);
                                            if (_d)
                                                cout << endl << endl << "Dodecahedron was tested" << endl;
                                            else
                                            {
                                                _i = dynamic_cast<_icosahedron*>(figure);
                                                if (_i)
                                                    cout << endl << endl << "Icosahedron was tested" << endl;
                                                else cout << endl << endl << "Sphere was tested" << endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                delete figure;
            }

            cout << endl << endl;
            system("pause"); 
        }
    }
}