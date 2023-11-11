#pragma once
#include "Transport.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Car : public Transport
{
private:
    string fuel_type;   // ��� ������
    int fuel_capacity;  // ̳������ ������
public:
    Car();
    string GetFuelType() const;
    void SetFuelType(string f);

    int GetFuelCapacity() const;
    void SetFuelCapacity(int c);

};

