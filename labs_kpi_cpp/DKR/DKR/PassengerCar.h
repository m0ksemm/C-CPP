#pragma once

#include "Transport.h"
#include "Car.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class PassengerCar : public Car
{
private:
    string car_type;  // Тип(або клас) машини: кросовер, седан, хетчбек, універсал і т.д.
public:
    PassengerCar();
    PassengerCar(string man, string mod, int w, int ms, string i, string ft, int fc, string ct);
    string GetCarType() const;
    void SetCarType(string ct);

    void Info() override;
    void Save() override;
    void Load() override;
};
