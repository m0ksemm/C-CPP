#include <iostream>
using namespace std;

template<int X, int Y, typename T>
class Picture {
    T** Image;
public:
    Picture() {
        Image = new T*[Y];
        for (int i = 0; i < Y; i++) {
            Image[i] = new T[X];
            for (int j = 0; j < X; j++) {
                Image[i][j] =  j;
            }
        }
    }
    Picture(T value) {
        Image = new T*[Y];
        for (int i = 0; i < Y; i++) {
            Image[i] = new T[X];
            for (int j = 0; j < X; j++) {
                Image[i][j] = value;
            }
        }
    }
    Picture(Picture<X, Y, T>& p) {
        this = p;
    }
    void ShowPicture() const {
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                cout << Image[i][j];
            }
            cout << endl;
        }
    }
    T GetPixel(int TX, int TY) const {
        TX = TX >= 0 ? TX : X + TX;
        TY = TY >= 0 ? TY : Y + TY;
        return Image[TX][TY];
    }
    void SetPixel(int TX, int TY, T value) {
        TX = TX >= 0 ? TX : X + TX;
        TY = TY >= 0 ? TY : Y + TY;
        Image[TX][TY] = value;
    }
    int GetWidth() const {
        return X;
    }
    int GetHeight() const {
        return Y;
    }
    Picture<X, Y, T>* operator+(T value) {
        Picture<X, Y, T>* p = new Picture<X, Y, T>();
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                p->Image[i][j] = Image[i][j] + value;
            }
        }
        return p;
    }
    Picture<X, Y, T>* operator-(T value) {
        Picture<X, Y, T>* p = new Picture<X, Y, T>();
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                p->Image[i][j] = Image[i][j] - value;
            }
        }
        return p;
    }
    Picture<X, Y, T>* operator*(T value) {
        Picture<X, Y, T>* p = new Picture<X, Y, T>();
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                p->Image[i][j] = Image[i][j] * value;
            }
        }
        return p;
    }
    Picture<X, Y, T>* operator/(T value) {
        Picture<X, Y, T>* p = new Picture<X, Y, T>();
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                p->Image[i][j] = Image[i][j] / value;
            }
        }
        return p;
    }
    template<typename U>
    Picture<X, Y, U>* ChangePicture(U value) {
        Picture<X, Y, U>* p = new Picture<X, Y, U>();
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                p->SetPixel(i, j, static_cast<U>(Image[i][j]));
            }
        }
        return p;
    }

    template<int TX, int TY>
    Picture<X * TX, Y * TY, T>* ScalePicture() {
        Picture<X* TX, Y* TY, T>* p = new Picture<X* TX, Y* TY, T>();
        for (int i = 0; i < Y; i++) {
            for (int j = 0; j < X; j++) {
                for (int a = 0; a < TY; a++) {
                    for (int b = 0; b < TX; b++) {
                        p->SetPixel(i * TX + b, j * TY + a, Image[i][j]);
                    }
                }
            }
        }
        return p;
    }
    template<int SX1, int SY1, int SX2, int SY2>
    Picture<SX2 - SX1, SY2 - SY1, T>* Subtract() {
        Picture<SX2 - SX1, SY2 - SY1, T>* p = new Picture<SX2 - SX1, SY2 - SY1, T>();
        for (int i = SY1; i < SY2; i++) {
            for (int j = SX1; j < SX2; j++) {
                p->SetPixel(i - SY1, j - SX1, Image[i][j]);
            }
        }
        return p;
    }
    Picture<X * 2, Y, T>* MergeHorizontal(Picture<X, Y, T>* pm) {
        Picture<X * 2, Y, T>* p = new Picture<X * 2, Y, T>();
        for (int i = 0; i < Y; i++) {
            int jp = 0;
            for (int j = 0; j < X; j++, jp++) {
                p->SetPixel(i, jp, Image[i][j]);
            }
            for (int j = 0; j < X; j++, jp++) {
                p->SetPixel(i, jp, pm->GetPixel(i, j));
            }
        }
        return p;
    }
    Picture<X, Y * 2, T>* MergeVertical(Picture<X, Y, T>* pm) {
        Picture<X, Y * 2, T>* p = new Picture<X, Y * 2, T>();
        int ip = 0;
        for (int i = 0; i < Y; i++, ip++) {
            for (int j = 0; j < X; j++) {
                p->SetPixel(ip, j, Image[i][j]);
            }
        }
        for (int i = 0; i < Y; i++, ip++) {
            for (int j = 0; j < X; j++) {
                p->SetPixel(ip, j, pm->GetPixel(i, j));
            }
        }
        return p;
    }
};

void main() {
    Picture<3, 3, int>* p1 = new Picture<3, 3, int>(1);
    Picture<3, 3, int>* p2 = new Picture<3, 3, int>(2);
    Picture<3, 6, int>* p = p1->MergeVertical(p2);
    p->ShowPicture();
}
