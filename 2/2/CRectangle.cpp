#include <iostream>
#include "CRectangle.h"

using namespace std;

CRectangle::CRectangle() 
{
    left = 3;
    right = 8;
    top = 2;
    bottom = 6;
}

CRectangle::CRectangle(int l, int t, int r, int b)
{
    left = l;
    right = r;
    top = t;
    bottom = b;
    
}

int CRectangle::Width()
{
    return (right - left);
}

int CRectangle::Height()
{
    return (bottom - top);
}

bool CRectangle::IsRectNull()
{
    if (bottom == 0 && top == 0 && left == 0 && right == 0)
        return true;
    else return false;
}
bool CRectangle::PtInRect(int x, int y) 
{
    if ((x >= left && x <= right) && (y <= bottom && y >= top))
        return true;
    else return false;
}

void CRectangle::SetRect(int x1, int y1, int x2, int y2)
{
    cout << "Left: ";
    cin >> left;
    cout << "Top: ";
    cin >> top;
    cout << "Right";
    cin >> right;
    cout << "Bottom: ";
    cin >> bottom;
}

void CRectangle::SetRectEmpty()
{
    left = 0;
    right = 0;
    top = 0;
    bottom = 0;
}

void CRectangle::InflateRect(int l, int t, int r, int b)
{
    left -= l;
    top -= t;
    right += r;
    bottom += b;
}

void CRectangle::DeflateRect(int l, int t, int r, int b)
{
    left += l;
    top += t;
    right -= r;
    bottom -= b;
}
void CRectangle::NormalizeRect()
{
    if (left > right) 
    {
        int tmp = left;
        left = right;
        right = tmp;
    }
    if (bottom < top) 
    {
        int tmp = bottom;
        bottom = top;
        top = tmp;
    }
}

void CRectangle::OffsetRect(int x, int y)
{
    left += x;
    right += x;
    top += y;
    bottom += y;
}

void CRectangle::Print() 
{
    cout << "\nRectangle:\n";
    cout << "Left top point: (" << left << ", " << top << ")\n";
    cout << "Right bottom point: (" << right << ", " << bottom << ")\n";
}