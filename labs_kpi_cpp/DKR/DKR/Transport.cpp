#include "Transport.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

Transport::Transport()
{
     name = "";
     manuf = "";
     model = "";
     weight = 0;
     max_speed = 0;
     id = "";
}
void Transport::SetName(string n)
{
     name = n;
}

string Transport::GetName() const
{
    return name;
}

string Transport::GetManuf() const
{
     return manuf;
}
void Transport::SetManuf(string m)
{
    manuf = m;
}

string Transport::GetModel () const
{
    return model;
}
void Transport::SetModel(string m)
{
    model = m;
}

int Transport::GetWeight() const
{
    return weight;
}
void Transport::SetWeight(int w)
{
    weight = w;
}

int Transport::GetMaxSpeed() const
{
    return max_speed;
}
void Transport::SetMaxSpeed(int s)
{
    max_speed = s;
}

string Transport::GetID() const
{
    return id;
}
void Transport::SetID(string i)
{
    id = i;
}


void Transport::Load()  {}
void Transport::Save()
{
    ofstream f("parking.txt", ios::app);
    f << name;
    f << "\n";
    f << manuf;
    f << "\n";
    f << model;
    f << "\n";
    f << weight;
    f << "\n";
    f << max_speed;
    f << "\n";
    f << id;
    f << "\n";
    f.close();
}
void Transport::Info()
{
    cout << "|Manufacturer: | " << manuf << endl;
    cout << "|Model:        | " << model << endl;
    cout << "|Weight:       | " << weight << endl;
    cout << "|Max speed:    | " << max_speed << endl;
    cout << "|ID:           | " << id << endl;
}
