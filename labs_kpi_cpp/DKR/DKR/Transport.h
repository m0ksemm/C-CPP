#pragma once
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Transport abstract
{
private:
    string name;  // ����� ����������
    string manuf; // ��������
    string model; // ������
    int weight;   // ����
    int max_speed;// ����. ��������
    string id;    // �����
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

    virtual void Load();   // ������������ ���������� � �����
    virtual void Save();   // ���������� ���������� � ����
    virtual void Info();   // ��������� ����������
};

