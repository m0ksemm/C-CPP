#include "FreightCar.h"
#include "PassengerCar.h"
#include "Transport.h"
#include "Car.h"
#include <iostream>
#include <fstream>
#include <string.h>

FreightCar::FreightCar() : Car()
{
    Transport::SetName("Freight");
    carrying = 0;
}
FreightCar::FreightCar(string man, string mod, int w, int ms, string i, string ft, int fc, int carr) : Car()
{
    Transport::SetName("Freight");
    Transport::SetManuf(man);
    Transport::SetModel(mod);
    Transport::SetWeight(w);
    Transport::SetMaxSpeed(ms);
    Transport::SetID(i);
    Car::SetFuelType(ft);
    Car::SetFuelCapacity(fc);
    carrying = carr;
}
int FreightCar::GetCarrying() const
{
    return carrying;
}
void FreightCar::SetCarrying(int c)
{
    carrying = c;
}
void FreightCar::Save() 
{
    Transport::Save();
    ofstream f("parking.txt", ios::app);
    f << Car::GetFuelType();
    f << "\n";
    f << Car::GetFuelCapacity();
    f << "\n";
    f << carrying;
    f << "\n";
    f.close();
}
void FreightCar::Info() 
{
    cout << "\n=============================" << endl;
    cout << "|  Freight car (TRUCK)" << endl;
    cout << "-----------------------------" << endl;
    Transport::Info();
    cout << "|Fuel type:    | " << Car::GetFuelCapacity() << endl;
    cout << "|Fuel capacity:| " << Car::GetFuelCapacity() << endl;
    cout << "|Load capacity:| " << carrying << endl;
}
 void FreightCar::Load() 
{
    ifstream f("temp.txt");
    string s;
    int n;
    f >> s;
    Transport::SetName(s);
    f >> s;
    Transport::SetManuf(s);
    f >> s;
    Transport::SetModel(s);
    f >> n;
    Transport::SetWeight(n);
    f >> n;
    Transport::SetMaxSpeed(n);
    f >> s;
    Transport::SetID(s);
    f >> s;
    Car::SetFuelType(s);
    f >> n;
    Car::SetFuelCapacity(n);
    f >> carrying;
    f.close();
}