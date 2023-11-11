#include "TwoWheeler.h"
#include <iostream>
#include <fstream>
#include <string.h>

TwoWheeler::TwoWheeler() : Transport()
{
    places = 1;
}
int TwoWheeler::GetPlaces()
{
    return places;
}
void TwoWheeler::SetPlaces(int p)
{
    places = p;
}