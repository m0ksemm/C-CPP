#pragma once
#include "Transport.h"
#include "TwoWheeler.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Motocycle : public TwoWheeler
{
private:
    int time_0_100;  // Ўвидк≥сть розгону 0-100
public:
    Motocycle();
    Motocycle(string man, string mod, int w, int ms, string i, int pl, int time);

    int GetTime();
    void SetTime(int t);
    void Save() override;
    void Info() override;
    virtual void Load() override;
};
