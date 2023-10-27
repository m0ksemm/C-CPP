// 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "CRectangle.h"

using namespace std;

int main()
{
    cout << "Test with a default constructor(no parametres)\n";
    CRectangle CRect;

    CRect.Print();

    int wid = CRect.Width();
    cout << "\nWidth = " << wid << endl;

    int hei = CRect.Height();
    cout << "Height = " << hei << endl;

    cout << "\nIf 0:\n";
    bool isnull = CRect.IsRectNull();
    if (isnull == true)
        cout << "All the parametres = 0 \n";
    else cout << "Rectangle is not a null rectangle \n";

    cout << "\nEnter the coordinates of a point\n";
    int x;
    cout << "x: ";
    cin >> x;
    int y;
    cout << "y: ";
    cin >> y;

    bool ifpoint1 = CRect.PtInRect(x, y);
    if (ifpoint1 == true)
        cout << "The point IS in a rectangle \n";
    else cout << "The point IS NOt in a rectangle \n";

    cout << "\nIncreasing the parametres: \n";
    int l, t, r, b;
    cout << "Left: ";
    cin >> l;
    cout << "Top: ";
    cin >> t;
    cout << "Right: ";
    cin >> r;
    cout << "Bottom: ";
    cin >> b;
    CRect.InflateRect(l, t, r, b);
    CRect.Print();

    cout << "\nDecreasing the parametres: \n";
    cout << "Left: ";
    cin >> l;
    cout << "Top: ";
    cin >> t;
    cout << "Right: ";
    cin >> r;
    cout << "Bottom: ";
    cin >> b;
    CRect.DeflateRect(l, t, r, b);
    CRect.Print();

    cout << "\n Normalized; \n";
    CRect.NormalizeRect();

    cout << "\n Enter the value for which you want to move a rectangle: \n";
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    CRect.OffsetRect(x, y);
    CRect.Print();

    cout << "\n\n\nTest with a constructor with parametres\nSet the parametres: \n";
    cout << "Left: ";
    cin >> l;
    cout << "Top: ";
    cin >> t;
    cout << "Right: ";
    cin >> r;
    cout << "Bottom: ";
    cin >> b;
    CRectangle CRect2(l, t, r, b);

    CRect2.Print();

    wid = CRect2.Width();
    cout << "\nWidth = " << wid << endl;

    hei = CRect2.Height();
    cout << "Height = " << hei << endl;

    cout << "\nIf 0:\n";
    isnull = CRect2.IsRectNull();
    if (isnull == true)
        cout << "All the parametres = 0 \n";
    else cout << "Rectangle is not a null rectangle \n";

    cout << "\nEnter the coordinates of a point\n";
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    ifpoint1 = CRect2.PtInRect(x, y);
    if (ifpoint1 == true)
        cout << "The point IS in a rectangle \n";
    else cout << "The point IS NOt in a rectangle \n";

    cout << "\nIncreasing the parametres: \n";
    cout << "Left: ";
    cin >> l;
    cout << "Top: ";
    cin >> t;
    cout << "Right: ";
    cin >> r;
    cout << "Bottom: ";
    cin >> b;
    CRect2.InflateRect(l, t, r, b);
    CRect2.Print();

    cout << "\nDecreasing the parametres: \n";
    cout << "Left: ";
    cin >> l;
    cout << "Top: ";
    cin >> t;
    cout << "Right: ";
    cin >> r;
    cout << "Bottom: ";
    cin >> b;
    CRect2.DeflateRect(l, t, r, b);
    CRect2.Print();
    
    cout << "\n Normalized; \n";
    CRect2.NormalizeRect();

    cout << "\n Enter the value for which you want to move a rectangle: \n";
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;

    CRect2.OffsetRect(x, y);
    CRect2.Print();

    cout << "\nSetRectEmpty function is used;\n";
    CRect2.SetRectEmpty();
    isnull = CRect2.IsRectNull();
    if (isnull == true)
        cout << "All the parametres = 0 \n";
    else cout << "Rectangle is not a null rectangle \n";

}