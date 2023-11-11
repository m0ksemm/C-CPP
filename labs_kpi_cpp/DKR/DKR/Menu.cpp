#include "Menu.h"
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

void Menu::AddMenu()
{
    cout << char(201);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(187) << endl << char(186);
    cout << " Which transport do you want to add? " << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
    {
        if (i == 19)
            cout << char(203);
        else cout << char(205);
    }

    cout << char(185) << endl;
    cout << char(186) << " 1. Passenger car  " << char(186) << " 2. Freight car  "
        << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
        if (i == 19)
            cout << char(206);
        else cout << char(205);
    cout << char(185) << endl;

    cout << char(186) << " 3. Motocycle\t    " << char(186) << " 4. Bicycle      "
        << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
        if (i == 19)
            cout << char(202);
        else cout << char(205);
    cout << char(185) << endl;
    cout << char(186) << " If you want to cancel, enter 0.     " << char(186) << endl;
    cout << char(200);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(188) << endl;
}
void Menu::RemoveMenu()
{
    cout << char(201);
    for (int i = 0; i < 40; i++)
        cout << char(205);
    cout << char(187) << endl << char(186);
    cout << " Which transport do you want to remove? " << char(186) << endl;

    cout << char(186) << " Enter the number of parking place:     " << char(186) << endl;
    cout << char(186) << " If you want to cancel, enter 0.        " << char(186) << endl;
    cout << char(200);
    for (int i = 0; i < 40; i++)
    {
        cout << char(205);
    }
    cout << char(188) << endl;
}
void Menu::ShowMenu()
{
    cout << char(201);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(187) << endl << char(186);
    cout << " Which transport has to be shown?    " << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
    {
        if (i == 19)
            cout << char(203);
        else cout << char(205);
    }

    cout << char(185) << endl;
    cout << char(186) << " 1. Passenger cars " << char(186) << " 2. Freight cars "
        << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
        if (i == 19)
            cout << char(206);
        else cout << char(205);
    cout << char(185) << endl;

    cout << char(186) << " 3. Motocycles\t    " << char(186) << " 4. Bicycles     "
        << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
        if (i == 19)
            cout << char(202);
        else cout << char(205);
    cout << char(185) << endl;
    cout << char(186) << " \t 5. Print them all.\t      " << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(185) << endl;
    cout << char(186) << " If you want to cancel, enter 0.     " << char(186) << endl;
    cout << char(200);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(188) << endl;
}
void Menu::SearchMenu()
{
    cout << char(201);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(187) << endl << char(186);
    cout << "   Chose the parameter of search:    " << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
    {
        if (i == 19)
            cout << char(203);
        else cout << char(205);
    }

    cout << char(185) << endl;
    cout << char(186) << " 1. Manufacturer   " << char(186) << " 2. Model \t      "
        << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
        if (i == 19)
            cout << char(206);
        else cout << char(205);
    cout << char(185) << endl;

    cout << char(186) << " 3. ID\t\t    " << char(186) << " 4. Parking numb."
        << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
        if (i == 19)
            cout << char(202);
        else cout << char(205);
    cout << char(185) << endl;
    cout << char(186) << " If you want to cancel, enter 0.     " << char(186) << endl;
    cout << char(200);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(188) << endl;
}

void Menu::MainMenu()
{
    cout << char(201);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(187) << endl << char(186);
    cout << "  \t    PARKING MANAGER    \t      " << char(186) << endl;


    cout << char(204);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(185) << endl;
    cout << char(186) << " 1. Show parking iformation          " << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(185) << endl;

    cout << char(186) << " 2. Add transport iformation         " << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(185) << endl;
    cout << char(186) << " 3. Remove transport iformation      " << char(186) << endl;
    cout << char(204);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(185) << endl;

    cout << char(186) << " 4. Find transport                   " << char(186) << endl;

    cout << char(204);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(185) << endl;

    cout << char(186) << " 5. Get income information           " << char(186) << endl;

    cout << char(204);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(185) << endl;

    cout << char(186) << " 6. Save to file                     " << char(186) << endl;

    cout << char(204);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(185);
    cout << endl;
    cout << char(186) << " 7. Load from file                   " << char(186) << endl;

    cout << char(204);
    for (int i = 0; i < 37; i++)
        cout << char(205);

    cout << char(185) << endl;
    cout << char(186) << " EXIT - close the program.           " << char(186) << endl;
    cout << char(200);
    for (int i = 0; i < 37; i++)
        cout << char(205);
    cout << char(188) << endl;

}