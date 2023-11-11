#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Transport abstract
{
private:
    string name;  // Назва транспорту
    string manuf; // Виробник
    string model; // Модель
    int weight;   // Вага
    int max_speed;// Макс. швидкість
    string id;    // Номер
public:
    Transport();

    void SetName(string n);
    string GetName() const;

    string GetManuf() const;
    void SetManuf(string m);

    string GetModel() const;
    void SetModel(string m);

    int GetWeight() const;
    void SetWeight(int w);

    int GetMaxSpeed() const;
    void SetMaxSpeed(int s);

    string GetID() const;
    void SetID(string i);

    virtual void Load();   // Завантаження інформації з файлу
    virtual void Save();   // Збереження інформації в файл
    virtual void Info();   // Виведення інформації
};

