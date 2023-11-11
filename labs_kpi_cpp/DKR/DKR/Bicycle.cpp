#include "Bicycle.h"
#include "Transport.h"
#include "TwoWheeler.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

Bicycle::Bicycle() : TwoWheeler()
{
    Transport::SetName("Bicycle");
    speeds = 0;
}
Bicycle::Bicycle(string man, string mod, int w, int ms, string i, int pl, int s) : TwoWheeler()
{
    Transport::SetName("Bicycle");
    Transport::SetManuf(man);
    Transport::SetModel(mod);
    Transport::SetWeight(w);
    Transport::SetMaxSpeed(ms);
    Transport::SetID(i);
    TwoWheeler::SetPlaces(pl);
    speeds = s;

}

int Bicycle::GetSpeeds()
{
    return speeds;
}
void Bicycle::SetSpeeds(int s)
{
    speeds = s;
}
void Bicycle::Info() 
{
    cout << "\n=============================" << endl;
    cout << "|  Bicycle" << endl;
    cout << "-----------------------------" << endl;
    Transport::Info();
    cout << "|Places:       | " << TwoWheeler::GetPlaces() << endl;
    cout << "|Speeds:       | " << speeds << endl;
}
void Bicycle::Save() 
{
    Transport::Save();

    ofstream f("parking.txt", ios::app);
    f << TwoWheeler::GetPlaces();
    f << "\n";
    f << speeds;
    f << "\n";

    f.close();
}
 void Bicycle::Load() 
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

    f.close();
}