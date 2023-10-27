// 16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Storage
{
protected:
        string manufacturer;
        string model;
        string name;
        int capacity;
        int count;
public:
    Storage()
    {
        capacity = 0;
        count = 0;
    }

    const string getManufacturer()const
    {
        return manufacturer;
    }
    const string getModel()const
    {
        return model;
    }
    const string getName()const
    {
        return name;
    }
    int getCapacity()const
    {
        return capacity;
    }
    int getCount()const
    {
        return count;
    }
    // cstr
    void setManufacturer(string man)
    {
        manufacturer = man;
    }
    void setModel(string md)
    {
        model = md;
    }
    void setName(string nm)
    {
        name = nm;
    }
    void setCapacity(int cp)
    {
        capacity = cp;
    }
    void setCount(int co)
    {
        count = co;
    }
    void Input()
    {
        cout << "\nManufacturer:  ";
        cin >> manufacturer;
        cout << "Model:          ";
        cin >> model;
        name = "Storage";
        cout << "Capacity:       ";
        cin >> capacity;
        cout << "Count:          ";
        cin >> count;
    }

    virtual void Print()
    {
        cout << "| Name         |" << name << endl;
        cout << "| Manufacturer |" << manufacturer << endl;
        cout << "| Model        |" << model << endl;
        cout << "| Capacity     |" << capacity << endl;
        cout << "| Count        |" << count << endl;
    }
    virtual void Save()
    {
        ofstream f("f1.txt", ios::app);
        f << name;
        f << "\n";
        f << manufacturer;
        f << "\n";
        f << model;
        f << "\n";
        f << capacity;
        f << "\n";
        f << count;
        f << "\n";
        f.close();
    }
    virtual void Load()
    {
       ifstream f("temp.txt");
       f >> manufacturer;
       f >> model;
       f >> name;
       f >> capacity;
       f >> count;
       f.close();    
    }
};

class USB :Storage
{
private:
    int speedusb;
public:
    USB() :Storage()
    {
        speedusb = 0;
    }
    USB(int n) :Storage()
    {
        speedusb = n;
    }
    void setSpeedusb(int n)
    {
        speedusb = n;
    }
    const int getSpeedusb()
    {
        return speedusb;
    }
    void Input()
    {
        this->Storage::Input();
        cout << "\Speed of USB:   ";
        cin >> speedusb;
        this->setName("USB");
    }
    void Print() 
    {
        this->Storage::Print();
        cout << "| Speed of USB |" << speedusb << endl;

        for (int i = 0; i < 30; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
    void Save()
    {
        this->Storage::Save();
        ofstream f("f1.txt", ios::app);
        f << speedusb;
        f << "\n";
        f.close();
    }
    virtual void Load()
    {
        ifstream f("temp.txt");
        f >> name;
        f >> manufacturer;
        f >> model;
        f >> capacity;
        f >> count;
        f >> speedusb;
        f.close();
    }
};

class HDD :Storage
{
private:
    int speedspinnig;
public:
    HDD() :Storage()
    {
        speedspinnig = 0;
    }
    void setSpeedspinnig(int n)
    {
        speedspinnig = n;
    }
    const int getSpeedspinnig()
    {
        return speedspinnig;
    }
    void Input()
    {
        this->Storage::Input();
        cout << "\Spinnig speed:  ";
        cin >> speedspinnig;
        this->setName("HDD");
    }
    void Print()
    {
        this->Storage::Print();
        cout << "| Spinnig speed|" << speedspinnig << endl;
        for (int i = 0; i < 30; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
    void Save()
    {
        this->Storage::Save();
        ofstream f("f1.txt", ios::app);
        f << speedspinnig;
        f << "\n";
        f.close();
    }
    virtual void Load()
    {
        ifstream f("temp.txt");
        f >> name;
        f >> manufacturer;
        f >> model;
        f >> capacity;
        f >> count;
        f >> speedspinnig;
        f.close();
    }

};

class DVD :Storage
{
private:
    int speedwrite;
public:
    DVD() :Storage()
    {
        speedwrite = 0;
    }
    void setSpeedwrite(int n)
    {
        speedwrite = n;
    }
    const int getSpeedwrite()
    {
        return speedwrite;
    }
    void Input()
    {
        this->Storage::Input();
        cout << "\Writint speed:  ";
        cin >> speedwrite;
        this->setName("DVD");
    }
    void Print()
    {
        this->Storage::Print();
        cout << "| Writing speed|" << speedwrite << endl;
        for (int i = 0; i < 30; i++)
        {
            cout << "-";
        }
        cout << endl;
    }
    void Save()
    {
        this->Storage::Save();
        ofstream f("f1.txt", ios::app);
        f << speedwrite;
        f << "\n";
        f.close();
    }
    virtual void Load()
    {
        ifstream f("temp.txt");
        f >> name;
        f >> manufacturer;
        f >> model;
        f >> capacity;
        f >> count;
        f >> speedwrite;
        f.close();
    }
};



class List
{
    vector<Storage*> vect;
public:
    void Menu() 
    {
        cout << char(201);
        for (int i = 0; i < 22; i++)
            cout << char(205);
        cout << char(187);

        cout << endl << char(186) << "   List of rtorages   " << char(186) << endl;

        cout << char(204);
        for (int i = 0; i < 22; i++)
            cout << char(205);
        cout << char(185) << endl;

        cout << char(186) << "1. Add storage        " << char(186) << endl;
        cout << char(186) << "2. Delete the storage " << char(186) << endl;
        cout << char(186) << "3. Print the list     " << char(186) << endl;
        cout << char(186) << "4. Edit the storage   " << char(186) << endl;
        cout << char(186) << "5. Search             " << char(186) << endl;
        cout << char(186) << "6. Save               " << char(186) << endl;
        cout << char(186) << "7. Load               " << char(186) << endl;
        cout << char(186) << "8. Exit               " << char(186) << endl;

        cout << char(200);
        for (int i = 0; i < 22; i++)
            cout << char(205);
        cout << char(188) << endl;
    }
    void Add()
    {
        system("cls");
        cout << "What type of a storage do you want to add? \n";
        cout << "1. USB\n2. HDD\n3. DVD\n";
        int choice;
        choice = _getch();;

        if (choice == '1')
        {
            cout << endl << endl << "New USB\n";
            USB u;
            u.Input();
            
            Storage* st = (Storage*) new USB(u);
            vect.push_back(st);
            system("cls");
            cout << "New USB was added!\n";
            _getch();
        }
        else if (choice == '2')
        {
            cout << endl << endl << "New HDD\n";
            HDD h;
            h.Input();
            Storage* st = (Storage*) new HDD(h);
            vect.push_back(st);
            system("cls");
            cout << "New HDD was added!\n";
            _getch();
        }
        else if (choice == '3')
        {
            cout << endl << endl << "New DVD\n";
            DVD d;
            d.Input();
            Storage* st = (Storage*) new DVD(d);
            vect.push_back(st);
            cout << "New DVD was added!\n";
            _getch();
        }
        else 
        {
            cout << "\n\nYou've made the wrong choice.";
            _getch();
        }
    }
    void Delete()
    {
        system("cls");
        int i;
        cout << "Enter the number of the storage";
        cout << " that you want to delete:     ";
  
        cin >> i;
        if (i < 1 || i > vect.size())
        {
            cout << "\nYou have entered wrong number. ";
            _getch();
        }
        else
        {
            vect.erase(vect.begin() + i - 1);
            cout << "\nDeleted!";
            _getch();
        }
    }
    void Edit()
    {
        system("cls");
        int i;
        cout << "Enter the number of the storage";
        cout << " that you want to edit:     ";

        cin >> i;
        if (i - 1 < 0 || i - 1> vect.size() - 1)
        {
            cout << "\nYou have entered wrong number. ";
            _getch();
        }
        else
        {

            if (typeid(*vect[i - 1]) == typeid(USB))
            {
                ((USB*)vect[i - 1])->Input();
                cout << "\Edited!";
                _getch();
            }
            else if (typeid(*vect[i - 1]) == typeid(HDD))
            {
                ((HDD*)vect[i - 1])->Input();
                cout << "\Edited!";
                _getch();
            }
            else if (typeid(*vect[i - 1]) == typeid(DVD))
            {
                ((DVD*)vect[i - 1])->Input();
                cout << "\Edited!";
                _getch();
            }
        }
    }
    void Search()
    {
        system("cls");
        cout << "Choose the criteria of the search:\n";
        cout << "1. Manufacturer\n2. Model\n3. Name\n4. Capacity\n5. Count\n6. Speed of USB";
        cout << "\n7. Speed of spinning HDD\n8. Speed of writing DVD\n";
        int choice; 
        cin >> choice;
            
        if (choice == 1)
        {
            bool flag = false;
            string manuf;
            cout << "Enter the manufacturer: ";
            cin >> manuf;
            vector<Storage*>::iterator pb;
            for (pb = vect.begin(); pb != vect.end(); pb++)
            {
                if ((*pb)->getManufacturer() == manuf)
                {
                    (*pb)->Print();
                    flag = true;
                }
            }
            if (flag == false)
                cout << "\n\nNot found." << endl;
            _getch();
        }
        else if (choice == 2)
        {
            bool flag = false;
            string mod;
            cout << "Enter the model: ";
            cin >> mod;
            vector<Storage*>::iterator pb;
            for (pb = vect.begin(); pb != vect.end(); pb++)
            {
                if ((*pb)->getModel() == mod)
                {
                    if (pb - vect.begin() + 1 > 9)
                    {
                        cout << char(201) << char(205) << char(205) << char(187) << endl;
                        cout << char(186) << setw(2) << pb - vect.begin() + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(205) << char(188) << endl;
                    }
                    else
                    {
                        cout << char(201) << char(205) << char(187) << endl;
                        cout << char(186) << pb - vect.begin() + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(188) << endl;
                    }
                    (*pb)->Print(); 
                    flag = true;
                }
            }
            if (flag == false)
                cout << "\n\nNot found." << endl;
            _getch();
         }
       else if (choice == 3)
       {
            bool flag = false;
            cout << "Choose the kind of the storage: ";
            cout << "\n1 - USB;\n2 - HDD;\n3 - DVD\n";
            int kind;
            cin >> kind;
            if (kind < 1 || kind > 3)
                cout << "\nYou have made a wrong choice!";
            else
            { 
                if (kind == 1)
                {
                    for (int i = 0; i < vect.size(); i++)
                    {
                        if (typeid(*vect[i]) == typeid(USB))
                        {
                            if (i + 1 > 9)
                            {
                                cout << char(201) << char(205) << char(205) << char(187) << endl;
                                cout << char(186) << setw(2) << i + 1 << char(186) << endl;
                                cout << char(200) << char(205) << char(205) << char(188) << endl;
                            }
                            else
                            {
                                cout << char(201) << char(205) << char(187) << endl;
                                cout << char(186) << i + 1 << char(186) << endl;
                                cout << char(200) << char(205) << char(188) << endl;
                            }
                            flag = true;
                            (vect[i])->Print();
                        }
                    }
                }
                if (kind == 2)
                {
                    for (int i = 0; i < vect.size(); i++)
                    {
                        if (typeid(*vect[i]) == typeid(HDD))
                        {
                            if (i + 1 > 9)
                            {
                                cout << char(201) << char(205) << char(205) << char(187) << endl;
                                cout << char(186) << setw(2) << i + 1 << char(186) << endl;
                                cout << char(200) << char(205) << char(205) << char(188) << endl;
                            }
                            else
                            {
                                cout << char(201) << char(205) << char(187) << endl;
                                cout << char(186) << i + 1 << char(186) << endl;
                                cout << char(200) << char(205) << char(188) << endl;
                            }
                            flag = true;
                            (vect[i])->Print();
                        }
                    }
                }
                if (kind == 3)
                {
                    for (int i = 0; i < vect.size(); i++)
                    {
                        if (typeid(*vect[i]) == typeid(DVD))
                        {
                            if (i + 1 > 9)
                            {
                                cout << char(201) << char(205) << char(205) << char(187) << endl;
                                cout << char(186) << setw(2) << i + 1 << char(186) << endl;
                                cout << char(200) << char(205) << char(205) << char(188) << endl;
                            }
                            else
                            {
                                cout << char(201) << char(205) << char(187) << endl;
                                cout << char(186) << i + 1 << char(186) << endl;
                                cout << char(200) << char(205) << char(188) << endl;
                            }
                            flag = true;
                            (vect[i])->Print();
                        }
                    }
                }
            }
            if (flag == false)
                cout << "\n\nNot found." << endl;
            _getch();
       }
       else if (choice == 4)
       {
            int cap;
            bool flag = false;
            cout << "Enter the capacity: ";
            cin >> cap;
            vector<Storage*>::iterator pb;
            for (pb = vect.begin(); pb != vect.end(); pb++)
            {
                if ((*pb)->getCapacity() == cap)
                {
                    if (pb - vect.begin() + 1 > 9)
                    {
                        cout << char(201) << char(205) << char(205) << char(187) << endl;
                        cout << char(186) << setw(2) << pb - vect.begin() + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(205) << char(188) << endl;
                    }
                    else
                    {
                        cout << char(201) << char(205) << char(187) << endl;
                        cout << char(186) << pb - vect.begin() + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(188) << endl;
                    }
                    (*pb)->Print();
                    flag = true;
                    
                }
            }
            if (flag == false)
                cout << "\n\nNot found." << endl;
            _getch();
       }
       else if (choice == 5)
       {
            int cnt;
            bool flag = false;
            cout << "Enter the count: ";
            cin >> cnt;
            vector<Storage*>::iterator pb;
            for (pb = vect.begin(); pb != vect.end(); pb++)
            {
                if ((*pb)->getCount() == cnt)
                {
                    if (pb - vect.begin() + 1 > 9)
                    {
                        cout << char(201) << char(205) << char(205) << char(187) << endl;
                        cout << char(186) << setw(2) << pb - vect.begin() + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(205) << char(188) << endl;
                    }
                    else
                    {
                        cout << char(201) << char(205) << char(187) << endl;
                        cout << char(186) << pb - vect.begin() + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(188) << endl;
                    }
                    (*pb)->Print();
                    flag = true;
                }
            }
            if (flag == false)
                cout << "\n\nNot found." << endl;
            _getch();
       }
       else if (choice == 6)
       {
            bool flag = false;
            int speed;
            cout << "Speed of USB: ";
            cin >> speed;
            for (int i = 0; i < vect.size(); i++)
            {
                if (typeid(*vect[i]) == typeid(USB))
                {
                    if (((USB*)vect[i])->getSpeedusb() == speed)
                    {
                        if (i + 1 > 9)
                        {
                            cout << char(201) << char(205) << char(205) << char(187) << endl;
                            cout << char(186) << setw(2) << i + 1 << char(186) << endl;
                            cout << char(200) << char(205) << char(205) << char(188) << endl;
                        }
                        else
                        {
                            cout << char(201) << char(205) << char(187) << endl;
                            cout << char(186) << i + 1 << char(186) << endl;
                            cout << char(200) << char(205) << char(188) << endl;
                        }
                        (vect[i])->Print();
                        flag = true;
                    }
                }
            }
            if (flag == false)
                cout << "\n\nNot found." << endl;
            _getch();
       }
       else if (choice == 7)
       {
            bool flag = false;    
            int speed;
            cout << "Speed of spinnig HDD: ";
            cin >> speed;
            for (int i = 0; i < vect.size(); i++)
            {
                if (typeid(*vect[i]) == typeid(HDD))
                {
                    if (((HDD*)vect[i])->getSpeedspinnig() == speed)
                    {
                        if (i + 1 > 9)
                        {
                            cout << char(201) << char(205) << char(205) << char(187) << endl;
                            cout << char(186) << setw(2) << i + 1 << char(186) << endl;
                            cout << char(200) << char(205) << char(205) << char(188) << endl;
                        }
                        else
                        {
                            cout << char(201) << char(205) << char(187) << endl;
                            cout << char(186) << i + 1 << char(186) << endl;
                            cout << char(200) << char(205) << char(188) << endl;
                        }
                        (vect[i])->Print();
                        flag = true;
                    }
                }
            }
            if (flag == false)
                cout << "\n\nNot found." << endl;
            _getch();
       }
       else if (choice == 8)
       {
           bool flag = false;
           int speed;
           cout << "Speed of writing DVD: ";
           cin >> speed;
           for (int i = 0; i < vect.size(); i++)
           {
               if (typeid(*vect[i]) == typeid(DVD))
               {
                   if (((DVD*)vect[i])->getSpeedwrite() == speed)
                   {
                       if (i + 1 > 9)
                       {
                           cout << char(201) << char(205) << char(205) << char(187) << endl;
                           cout << char(186) << setw(2) << i + 1 << char(186) << endl;
                           cout << char(200) << char(205) << char(205) << char(188) << endl;
                       }
                       else
                       {
                           cout << char(201) << char(205) << char(187) << endl;
                           cout << char(186) << i + 1 << char(186) << endl;
                           cout << char(200) << char(205) << char(188) << endl;
                       }
                       (vect[i])->Print();
                       flag = true;
                   }
               }
           }
           if (flag == false)
               cout << "\n\nNot found." << endl;
           _getch();
       }
       else 
       {
           cout << "\n\nYou have made a wrong choice!__";
           _getch();
       }
    }
    void Print()
    {

        vector<Storage*>::iterator pb;
        int choice; 
        cout << "Press 1 to print the whole list\n";
        cout << "Press 2 to print all USBs\n";
        cout << "Press 3 to print all HDDs\n";
        cout << "Press 4 to print all DVDs\n";
        choice = _getch();
        system("cls");
        switch (choice)
        {
        case '1':
            cout << "The whole list:\n\n";
            for (pb = vect.begin(); pb != vect.end(); pb++)
            {
                if (pb - vect.begin() + 1 > 9)
                {
                    cout << char(201) << char(205) << char(205) << char(187) << endl;
                    cout << char(186) << setw(2) << pb - vect.begin() + 1 << char(186) << endl;
                    cout << char(200) << char(205) << char(205) << char(188) << endl;
                }
                else
                {
                    cout << char(201) << char(205) << char(187) << endl;
                    cout << char(186) << pb - vect.begin() + 1 << char(186) << endl;
                    cout << char(200) << char(205) << char(188) << endl;
                }

                (*pb)->Print();
            }
            _getch();
            break;
        case '2':
            cout << "All USBs\n\n";
            for (int i = 0; i < vect.size(); i++)
            {
                if (typeid(*vect[i]) == typeid(USB))
                {
                    
                    if (i + 1 > 9)
                    {
                        cout << char(201) << char(205) << char(205) << char(187) << endl;
                        cout << char(186) << setw(2) << i + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(205) << char(188) << endl;
                    }
                    else
                    {
                        cout << char(201) << char(205) << char(187) << endl;
                        cout << char(186) << i + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(188) << endl;
                    }

                    (vect[i])->Print();
                }
                
            }
            _getch();
            break;
        case '3':
            cout << "All HDDs\n\n";
            for (int i = 0; i < vect.size(); i++)
            {
                if (typeid(*vect[i]) == typeid(HDD))
                {
                    
                    if (i + 1 > 9)
                    {
                        cout << char(201) << char(205) << char(205) << char(187) << endl;
                        cout << char(186) << setw(2) << i + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(205) << char(188) << endl;
                    }
                    else
                    {
                        cout << char(201) << char(205) << char(187) << endl;
                        cout << char(186) << i + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(188) << endl;
                    }

                    (vect[i])->Print();
                }

            }
            _getch();
            break;
        case '4':
            cout << "All DVDs\n\n";
            for (int i = 0; i < vect.size(); i++)
            {
                if (typeid(*vect[i]) == typeid(DVD))
                {
                    
                    if (i + 1 > 9)
                    {
                        cout << char(201) << char(205) << char(205) << char(187) << endl;
                        cout << char(186) << setw(2) << i + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(205) << char(188) << endl;
                    }
                    else
                    {
                        cout << char(201) << char(205) << char(187) << endl;
                        cout << char(186) << i + 1 << char(186) << endl;
                        cout << char(200) << char(205) << char(188) << endl;
                    }

                    (vect[i])->Print();
                }

            }
            _getch();
            break;
        }
    }
    void Save()
    {
        std::remove("f1.txt");
        ofstream f("f1.txt", ios::app);
        f << vect.size();
        f << "\n";
        f.close();
        for (int i = 0; i < vect.size(); i++)
        {
            (vect[i])->Save();
        }
        cout << "\nSaved!\n";
        cout << "        ------ " << endl;
        cout << "       | .TXT |" << endl;
        cout << " --->  |------|" << endl;
        cout << " --->  |  f1  |" << endl;
        cout << " --->  |      |" << endl;
        cout << "        ------ " << endl;

        _getch();
    }
    void Load()
    {
        int size;
        string nam, man, mod;
        int cap, cou, add;

        ifstream f1("f1.txt");

        f1 >> size;

        for (int i = 0; i < size ; i++)
        {
            ofstream temp("temp.txt");
            f1 >> nam;
            f1 >> man;
            f1 >> mod;
            f1 >> cap;
            f1 >> cou;
            f1 >> add;

            temp << nam;
            temp << '\n';
            temp << man;
            temp << '\n';
            temp << mod;
            temp << '\n';
            temp << cap;
            temp << '\n';
            temp << cou;
            temp << '\n';
            temp << add;
            temp << '\n';
            temp.close();

            if (nam == "USB")
            {
                USB u;
                u.Load();
                Storage* st = (Storage*) new USB(u);
                vect.push_back(st);
            }
            else if (nam == "HDD")
            {
                HDD h;
                h.Load();
                Storage* st = (Storage*) new HDD(h);
                vect.push_back(st);
            }
            else if (nam == "DVD")
            {
                DVD d;
                d.Load();
                Storage* st = (Storage*) new DVD(d);
                vect.push_back(st);
            }
            std::remove("temp.txt");
        }

        f1.close();
        cout << "\nLoaded!\n";

        cout << "  ------                   " << endl;
        cout << " | .TXT |       ---------- " << endl;
        cout << " |------| ---> |   List   | " << endl;
        cout << " |  f1  | ---> |    Of    | " << endl;
        cout << " |      | ---> | Storages | " << endl;
        cout << "  ------        ---------- " << endl;

        _getch();
    }
};

int main()
{
    
    List v;
    bool flag = true;
    int choice;

    while (flag == true)
    {
        system("cls");
        v.Menu();

        choice = _getch();
        switch (choice)
        {
        case '1':
            v.Add();
            break;
        case '2':
            v.Delete();
            break;
        case '3':
            v.Print(); 
            break;
        case '4':
            v.Edit();
            break;
        case '5':
            v.Search();
            break;
        case '6':
            v.Save();
            break;
        case '7':
            v.Load();
            break;
        case '8':
            flag = false;
            break;
        }
    }
}

