#pragma once
#include "Transport.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class TwoWheeler : public Transport
{
private:
    int places;  // ʳ������ ���� �� ���������. (1, 2 ���� �������� ��� � ������ ����)
public: 
    TwoWheeler();
    int GetPlaces();
    void SetPlaces(int p);
};

