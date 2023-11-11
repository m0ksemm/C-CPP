#pragma once
#include "Transport.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Car : public Transport
{
private:
    string fuel_type;   // Тип палива
    int fuel_capacity;  // Місткість палива
public:
    Car();
    string GetFuelType() const;
    void SetFuelType(string f);

    int GetFuelCapacity() const;
    void SetFuelCapacity(int c);

};

