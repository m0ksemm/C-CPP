#include <iostream>
#include "List.h"
using namespace std;

List::List()
{
	// ���������� ������ ����
	Head = nullptr;
	Count = 0;
}

List::~List()
{
	// ����� ������� ��������
	DelAll();
}

int List::GetCount()
{
	// ���������� ���������� ���������
	return Count;
}

void List::Add(char data)
{
	// �������� ������ ��������
	Element* temp = new Element;

	// ���������� �������
	temp->data = data;
	// ��������� ������� - �������� ������� ������
	temp->Next = Head;

	// ����� ������� ���������� �������� ��������� ������
	Head = temp;

	Count++;
}



void List::Del()
{
	if (Head)
	{
		// ���������� ����� ��������� ��������
		Element* temp = Head->Next;
		// ������������� ������ �� ��������� �������
		delete Head;
		// ������� ������ �������� �������
		Head = temp;
		Count--;
	}
}

void List::DelAll()
{
	// ���� ��� ���� ��������
	while (Head != nullptr)
		// ������� �������� �� ������
		Del();
}

void List::Print()
{
	// ���������� ����� ��������� ��������
	Element* temp = Head;
	if (temp == nullptr)
	{
		cout << "List is empty!";
		return;
	}
	// ���� ��� ���� ��������
	while (temp != 0)
	{
		// ������� ������
		cout << temp->data;
		// ��������� �� ��������� �������
		temp = temp->Next;
	}
	cout << endl;
}

void List::InsertByPosition(char data, int position)
{
	Element* temp = Head;
	int Index = 0;
	while (Index < position)
	{

		temp = temp->Next;
		++Index;
	}

	Element* NewElem = new Element;
	NewElem->Next = temp->Next;
	NewElem->data = data;
	temp->Next = NewElem;
}



void List::RemoveByPosition(int position)
{
	Element* temp = Head;
	int Index = 0;
	while (Index < position)
	{

		temp = temp->Next;
		++Index;
	}

	Element* tmp = temp->Next;
	temp->Next = tmp->Next;

	delete tmp;
	Count--;
}

int List::Find(char key)
{
	Element* temp = Head;
	int Index = 0;
	while (temp != 0)
	{
		if (temp->data == key)
			return Index;

		temp = temp->Next;
		++Index;
	}
	return -1;
}

List::List(const List& obj) :Count(0), Head(nullptr)
{
	Element* temp = nullptr;
	for (Element* n = obj.Head; n != nullptr; n = n->Next)
	{
		Element* item = new Element();
		item->data = (n->data);
		if (!Head)
		{
			Head = item;
		}
		else
		{
			temp->Next = item;
		}
		temp = item;
		++Count;
	}


}

void List::AddBack(char data)
{
	Element* temp = Head;
	for (int i = 0; i < Count - 1; i++)
	{
		temp = temp->Next;
	}

	Element* tmp = new Element;

	tmp->data = data;
	tmp->Next = nullptr;
	temp->Next = tmp;
	Count++;
}

List& List::operator = (const List& obj)
{
	Element* last = nullptr;
	for (Element* n = obj.Head; n != nullptr; n = n->Next)
	{
		Element* item = new Element();
		item->data = (n->data);
		if (!Head)
		{
			Head = item;
		}
		else
		{
			last->Next = item;
		}
		last = item;
		++Count;
	}
	return *this;

}