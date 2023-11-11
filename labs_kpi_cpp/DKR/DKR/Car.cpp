#include "Car.h"
#include "Transport.h"
#include <string.h>

Car::Car() : Transport()
{
    fuel_type = "";
    fuel_capacity = 0;
}
string Car::GetFuelType() const
{
    return fuel_type;
}
void Car::SetFuelType(string f)
{
    fuel_type = f;
}

int Car::GetFuelCapacity() const
{
    return fuel_capacity;
}
void Car::SetFuelCapacity(int c)
{
    fuel_capacity = c;
}