#include "PassengerCar.h"
#include "Transport.h"
#include "Car.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

PassengerCar::PassengerCar() : Car()
{
    Transport::SetName("Passenger");
    car_type = "";
}
PassengerCar::PassengerCar(string man, string mod, int w, int ms, string i, string ft, int fc, string ct) : Car()
{
    Transport::SetName("Passenger");
    Transport::SetManuf(man);
    Transport::SetModel(mod);
    Transport::SetWeight(w);
    Transport::SetMaxSpeed(ms);
    Transport::SetID(i);
    Car::SetFuelType(ft);
    Car::SetFuelCapacity(fc);
    car_type = ct;
}
string PassengerCar::GetCarType() const
{
    return car_type;
}
void PassengerCar::SetCarType(string ct)
{
    car_type = ct;
}

void PassengerCar::Info() 
{
    cout << "\n=============================" << endl;
    cout << "|  " << car_type << " car " << endl;
    cout << "-----------------------------" << endl;
    Transport::Info();
    cout << "|Fuel type:    | " << Car::GetFuelCapacity() << endl;
    cout << "|Fuel capacity:| " << Car::GetFuelCapacity() << endl;
    cout << "|Car type:     | " << car_type << endl;
}
void PassengerCar::Save()
{
    Transport::Save();
    ofstream f("parking.txt", ios::app);
    f << Car::GetFuelType();
    f << "\n";
    f << Car::GetFuelCapacity();
    f << "\n";
    f << car_type;
    f << "\n";
    f.close();
}
void PassengerCar::Load() 
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
    f >> car_type;
    f.close();
}
