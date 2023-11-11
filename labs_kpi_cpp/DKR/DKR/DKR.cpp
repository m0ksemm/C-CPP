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
#include "Menu.h"

using namespace std;
 
class Parking : public Menu
{
private:
    vector<Transport*> parking;
    int earnings;
public:
    Parking()
    {
        earnings = 0;
    }
public: 
    void Add()
    {
        while (true)
        {
            system("cls");
            AddMenu();
            int choice; 
            choice = _getch();
            system("cls");
            if (choice == '0')
                break;
            else if (choice == '1')
            {
                string man;
                string mod;
                int weight;
                int ms;
                string id;
                string ft;
                int fc;
                string ct;

                cout << "Manufacturer:  - ";
                cin >> man;
                cout << "Model:         - ";
                cin >> mod;
                cout << "Weight:        - ";
                cin >> weight;
                cout << "Max speed:     - ";
                cin >> ms;
                cout << "ID:            - ";
                cin >> id;
                cout << "Fuel:          - ";
                cin >> ft;
                cout << "Fuel capacity: - ";
                cin >> fc;
                cout << "Car class:     - ";
                cin >> ct;

                PassengerCar pc(man, mod, weight, ms, id, ft, fc, ct);
                Transport *t = (Transport*) new PassengerCar(pc);
                parking.push_back(t);
                cout << endl << "+1 passenger car" << endl;
                earnings += 20;
                //system("pause");
                break;
            }
            else if (choice == '2')
            {
                string man;
                string mod;
                int weight;
                int ms;
                string id;
                string ft;
                int fc;
                int wc;

                cout << "Manufacturer:  - ";
                cin >> man;
                cout << "Model:         - ";
                cin >> mod;
                cout << "Weight:        - ";
                cin >> weight;
                cout << "Max speed:     - ";
                cin >> ms;
                cout << "ID:            - ";
                cin >> id;
                cout << "Fuel:          - ";
                cin >> ft;
                cout << "Fuel capacity: - ";
                cin >> fc;
                cout << "Weight carrying- ";
                cin >> wc;

                FreightCar fcr(man, mod, weight, ms, id, ft, fc, wc);
                Transport* t = (Transport*) new FreightCar(fcr);
                parking.push_back(t);
                cout << endl << "+1 freight car" << endl;
                earnings += 30;
                break;
            }
            else if (choice == '3')
            {
                string man;
                string mod;
                int weight;
                int ms;
                string id;
                int pl;
                int tm;

                cout << "Manufacturer:  - ";
                cin >> man;
                cout << "Model:         - ";
                cin >> mod;
                cout << "Weight:        - ";
                cin >> weight;
                cout << "Max speed:     - ";
                cin >> ms;
                cout << "ID:            - ";
                cin >> id;
                cout << "Places:        - ";
                cin >> pl;
                cout << "Racing 0-100:  - ";
                cin >> tm;

                Motocycle moto(man, mod, weight, ms, id, pl, tm);
                Transport* t = (Transport*) new Motocycle(moto);
                parking.push_back(t);
                cout << endl << "+1 motocycle" << endl;
                earnings += 10;
                //system("pause");
                break;
            }
            else if (choice == '4')
            {
                string man;
                string mod;
                int weight;
                int ms;
                string id;
                int pl;
                int sp;

                cout << "Manufacturer:  - ";
                cin >> man;
                cout << "Model:         - ";
                cin >> mod;
                cout << "Weight:        - ";
                cin >> weight;
                cout << "Max speed:     - ";
                cin >> ms;
                cout << "ID:            - ";
                cin >> id;
                cout << "Places:        - ";
                cin >> pl;
                cout << "Speeds number  - ";
                cin >> sp;

                Bicycle bcle(man, mod, weight, ms, id, pl, sp);
                Transport* t = (Transport*) new Bicycle(bcle);
                parking.push_back(t);
                cout << endl << "+1 bicycle" << endl;
                earnings += 5;
                //system("pause");
                break;
            }
        }
    }
    void Remove()
    {
        while (true)
        {
            system("cls");
            RemoveMenu();
            int number;
            cin >> number;
            system("cls");
            if (number == 0)
                break;
            else if (number < 1 || number >= parking.size())
            {
                cout << endl << "The parking does not have such a parking place " << endl;
                system("pause");
            }
            else
            {
                parking.erase(parking.begin() + number - 1);
                if (parking[number - 1]->GetName() == "Freight car")
                    earnings -= 30;
                else if (parking[number - 1]->GetName() == "Passenger car")
                    earnings -= 20;
                else if (parking[number - 1]->GetName() == "Motocycle")
                    earnings -= 10;
                else if (parking[number - 1]->GetName() == "Bicycle")
                    earnings -= 5;

                cout << endl << "Transport was removed." << endl;
                system("pause");
                break;
            }
        }
    }
    void Show()
    {
        while (true)
        {
            system("cls");
            ShowMenu();
            int choice;
            choice = _getch();
            system("cls");
            if (choice == '0')
                break;
            else if (choice == '1')
            {
                
                for (int i = 0; i < parking.size(); i++)
                {
                    if (typeid(*parking[i]) == typeid(PassengerCar)) {
                        cout << endl << i + 1 << endl;
                        ((PassengerCar*)parking[i])->Info();
                    }
                }
                break;
            }
            else if (choice == '2')
            {
                for (int i = 0; i < parking.size(); i++)
                {
                    if (typeid(*parking[i]) == typeid(FreightCar))
                    {
                        cout << endl << i + 1 << endl;
                        ((FreightCar*)parking[i])->Info();
                    }
                        
                }
                break;
            }
            else if (choice == '3')
            {
                for (int i = 0; i < parking.size(); i++)
                {
                    if (typeid(*parking[i]) == typeid(Motocycle)) {
                        cout << endl << i + 1 << endl;
                        ((Motocycle*)parking[i])->Info();
                    }
                        
                }
                break;
            }
            else if (choice == '4')
            {
                for (int i = 0; i < parking.size(); i++)
                {
                    if (typeid(*parking[i]) == typeid(Bicycle))
                    {
                        cout << endl << i + 1 << endl;
                        ((Bicycle*)parking[i])->Info();
                    }
                        
                }
                break;
            }
            else if (choice == '5')
            {
                int i = 0;
                vector<Transport*>::iterator iter;
                for (iter = parking.begin(); iter != parking.end(); iter++)
                {
                    cout << endl << ++i  << endl;
                    (*iter)->Info();
                }
                break;
            }
        }
    }
    void Search()
    {
        while (true)
        {
            system("cls");
            SearchMenu();
            int choice;
            choice = _getch();
            system("cls");
            if (choice == '0')
                break;
            else if (choice == '1')
            {
                system("cls");
                string str;
                bool found = false;
                cout << "Enter the key of search (Manufacturer):" << endl;
                cin >> str;
                for (int i = 0; i < parking.size(); i++)
                {
                    if (parking[i]->GetManuf() == str)
                    {
                        parking[i]->Info();
                        found = true;
                    }
                }
                if (found == false)
                    cout << endl << endl << "There is no such a transport" << endl;
                system("Pause");
                break;
            }
            else if (choice == '2')
            {
                system("cls");
                string str;
                bool found = false;
                cout << "Enter the key of search (Model):" << endl;
                cin >> str;
                for (int i = 0; i < parking.size(); i++)
                {
                    if (parking[i]->GetModel() == str)
                    {
                        parking[i]->Info();
                        found = true;
                    }
                }
                if (found == false)
                    cout << endl << endl << "There is no such a transport" << endl;
                system("Pause");
                break;
            }
            else if (choice == '3')
            {
                system("cls");
                string str;
                bool found = false;
                cout << "Enter the key of search (ID):" << endl;
                cin >> str;
                for (int i = 0; i < parking.size(); i++)
                {
                    if (parking[i]->GetID() == str)
                    {
                        parking[i]->Info();
                        found = true;
                    }
                }
                if (found == false)
                    cout << endl << endl << "There is no such a transport" << endl;
                system("Pause");
                break;
            }
            else if (choice == '4')
            {
                system("cls");
                int n;
                cout << "Enter the key of search (Number of parking place):" << endl;
                cin >> n;

                if (n < 0 || n >= parking.size())
                    cout << endl << endl << "Tehre is no such a parking place" << endl;
                else parking[n - 1]->Info();
                system("Pause");
                break;
            }
            else if (choice == '0')
                break;
        }
    }
    void Incomes()
    {
        system("cls");
        cout << " =================================" << endl;
        cout << "||The income from parking = " << earnings << " USD" <<endl;
        cout << "||" << endl;
        cout << "|| Payment per transport:" << endl;
        cout << "|| Freight car   - 30 USD" << endl;
        cout << "|| Passenger car - 20 USD" << endl;
        cout << "|| Motocycle     - 10 USD" << endl;
        cout << "|| Bicycle       - 5  USD" << endl;
        cout << " =================================" << endl;
    }
    void Save()
    {
        std::remove("parking.txt");
        ofstream f("parking.txt", ios::app);
        f << earnings;
        f << "\n";
        f << parking.size();
        f << "\n";
        f.close();
        for (int i = 0; i < parking.size(); i++)
        {
            (parking[i])->Save();
        }
        cout << endl << "Information about the parking was saved. " << endl;
        system("cls");

        cout << endl << endl << "Information saved." << endl;
    }
    void Load()
    {
        int size;
        int earn;
        string name;
        string manuf;
        string model;
        int weight;
        int max_speed;
        string id;

        string fuel_type;
        int fuel_capacity;
        string car_type;
        int carrying;
        int places;
        int time_0_100;
        int speeds;

        ifstream f1("parking.txt");

        f1 >> earnings;

        f1 >> size;

        for (int i = 0; i < size; i++)
        {
            ofstream temp("temp.txt");
            f1 >> name;
            f1 >> manuf;
            f1 >> model;
            f1 >> weight;
            f1 >> max_speed;
            f1 >> id;

            temp << name;
            temp << '\n';
            temp << manuf;
            temp << '\n';
            temp << model;
            temp << '\n';
            temp << weight;
            temp << '\n';
            temp << max_speed;
            temp << '\n';
            temp << id;
            temp << '\n';

            if (name == "Passenger")
            {
                f1 >> fuel_type;
                f1 >> fuel_capacity;
                f1 >> car_type;

                temp << fuel_type;
                temp << '\n';
                temp << fuel_capacity;
                temp << '\n';
                temp << car_type;
                temp << '\n';
            }
            else if (name == "Freight")
            {
                f1 >> fuel_type;
                f1 >> fuel_capacity;
                f1 >> carrying;

                temp << fuel_type;
                temp << '\n';
                temp << fuel_capacity;
                temp << '\n';
                temp << carrying;
                temp << '\n';
            }
            else if (name == "Motocycle")
            {
                f1 >> places;
                f1 >> time_0_100;

                temp << places;
                temp << '\n';
                temp << time_0_100;
                temp << '\n';
            }
            else if (name == "Bicycle")
            {
                f1 >> places;
                f1 >> speeds;

                temp << places;
                temp << '\n';
                temp << speeds;
                temp << '\n';
            }

            temp.close();
            if (name == "Passenger")
            {
                PassengerCar pc;
                pc.Load();
                Transport* t = (Transport*) new PassengerCar(pc);
                parking.push_back(t);
            }
            if (name == "Freight")
            {
                FreightCar fc;
                fc.Load();
                Transport* t = (Transport*) new FreightCar(fc);
                parking.push_back(t);
            }
            else if (name == "Motocycle")
            {
                Motocycle mt;
                mt.Load();
                Transport* t = (Transport*) new Motocycle(mt);
                parking.push_back(t);
            }
            else if (name == "Bicycle")
            {
                Bicycle bc;
                bc.Load();
                Transport* t = (Transport*) new Bicycle(bc);
                parking.push_back(t);
            }
            std::remove("temp.txt");
        }

        cout << endl << endl << "Information loaded." << endl;
    }
    void Functional()
    {
        while (true)
        {
            system("cls");
            MainMenu();

            int choice = _getch();

            if (choice == VK_ESCAPE)
                break;
            else if (choice == '1')
                Show();
            else if (choice == '2')
                Add();
            else if (choice == '3')
                Remove();
            else if (choice == '4')
                Search();
            else if (choice == '5')
                Incomes();
            else if (choice == '6')
                Save();
            else if (choice == '7')
                Load();
            system("pause");
        }
    }
};

int main()
{
    Parking p;
    p.Functional();
}