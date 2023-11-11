#pragma once
#include "PassengerCar.h"
#include "Transport.h"
#include "Car.h"
#include <iostream>
#include <fstream>
#include <string.h>

class FreightCar : public Car
{
private:
    int carrying;  // Вага, яку може тягнути вантажівка
public: 
    FreightCar();
    FreightCar(string man, string mod, int w, int ms, string i, string ft, int fc, int carr);
    int GetCarrying() const;
    void SetCarrying(int c);
    void Save() override;
    void Info() override;
    void Load() override;
};


