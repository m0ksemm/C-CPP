#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include "Transport.h"
#include "Car.h"
#include "TwoWheeler.h"
#include "PassengerCar.h"
#include "FreightCar.h"
#include "Motocycle.h"
#include "Bicycle.h"

using namespace std;

class Menu
{
public:
    void AddMenu();    // Графічне оформлення при додаванні нової транспортної одиниці 
    void RemoveMenu(); // Графічне оформлення при видаленні 
    void ShowMenu();   // Графічне оформлення при виведенні 
    void SearchMenu(); // Графічне оформлення при пошуку 
    void MainMenu();   // Графічне оформлення головного меню
};