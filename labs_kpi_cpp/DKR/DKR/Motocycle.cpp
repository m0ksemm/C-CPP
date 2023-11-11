#include "Motocycle.h"
#include "Transport.h"
#include "TwoWheeler.h"
#include <iostream>
#include <fstream>
#include <string.h>

Motocycle::Motocycle() : TwoWheeler()
{
    Transport::SetName("Motocycle");
    time_0_100 = 0;
}
Motocycle::Motocycle(string man, string mod, int w, int ms, string i, int pl, int time) : TwoWheeler()
{
    Transport::SetName("Motocycle");
    Transport::SetManuf(man);
    Transport::SetModel(mod);
    Transport::SetWeight(w);
    Transport::SetMaxSpeed(ms);
    Transport::SetID(i);
    TwoWheeler::SetPlaces(pl);
    time_0_100 = time;
}

int Motocycle::GetTime()
{
    return time_0_100;
}
void Motocycle::SetTime(int t)
{
    time_0_100 = t;
}
void Motocycle::Save() 
{
    Transport::Save();

    ofstream f("parking.txt", ios::app);
    f << TwoWheeler::GetPlaces();
    f << "\n";
    f << time_0_100;
    f << "\n";

    f.close();
}
void Motocycle::Info() 
{
    cout << "\n=============================" << endl;
    cout << "|  Motocycle" << endl;
    cout << "-----------------------------" << endl;
    Transport::Info();
    cout << "|Places:       | " << TwoWheeler::GetPlaces() << endl;
    cout << "|Racing 0-100: | " << time_0_100 << endl;
}
 void Motocycle::Load() 
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
    f >> n;
    TwoWheeler::SetPlaces(n);
    f >> time_0_100;
    f.close();
}