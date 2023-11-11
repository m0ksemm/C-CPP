#pragma once
#include "Transport.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class TwoWheeler : public Transport
{
private:
    int places;  // Кількість місць на велосипеді. (1, 2 якщо двомісний або є дитяче місце)
public: 
    TwoWheeler();
    int GetPlaces();
    void SetPlaces(int p);
};

