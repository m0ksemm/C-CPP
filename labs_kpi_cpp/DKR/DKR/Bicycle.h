#pragma once
#include "Transport.h"
#include "TwoWheeler.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Bicycle : public TwoWheeler
{
private: 
    int speeds;  // Кількість швидкостей
public:
    Bicycle();
    Bicycle(string man, string mod, int w, int ms, string i, int pl, int s);
    int GetSpeeds();
    void SetSpeeds(int s);
    void Info() override;
    void Save() override;
    void Load() override;
};

