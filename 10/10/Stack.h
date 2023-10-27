// �������������� ��������� ���������� ����
#pragma once
#include <iostream>
#include "vector.h"

using namespace std;

template <class T>
class Stack
{
    Vector<T> data;
public:
    // ������� �����
    void Clear() { data.Clear(); }

    // ������ � �������� �����
    int GetCount() const { return data.GetCount(); }
    bool IsEmpty() const { return data.IsEmpty(); }

    // ���������� � �������� ���������
    void Push(const T& item);
    void Pop(T& item);
    void Peek(T& item);
};

template <class T>
void Stack<T>::Push(const T& item)
{
    data.Insert(0, item);
}

template <class T>
void Stack<T>::Pop(T& item)
{
    if (!IsEmpty())
    {
        item = data[0];
        data.Remove(0);
    }
    else
        item = -1;
}

template <class T>
void Stack<T>::Peek(T& item)
{
    if (!IsEmpty())
        item = data[0];
    else
        item = -1;
}


