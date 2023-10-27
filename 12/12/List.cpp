#include <iostream>
#include "List.h"

using namespace std;

List::List()
{
	Head = Tail = nullptr;
	Count = 0;
}

List::List(const List& L)
{
	Head = Tail = nullptr;
	Count = 0;
	Elem* temp = L.Head;
	while (temp != nullptr)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}

List::~List()
{
	DelAll();
}

void List::AddHead(char data)
{
	Elem* temp = new Elem;
	temp->prev = nullptr;
	temp->data = data;
	temp->next = Head;
	if (Head != nullptr)
		Head->prev = temp;
	Head = temp;
	if (Tail == nullptr)
		Tail = temp;
	Count++;
}

void List::AddTail(char data)
{
	Elem* temp = new Elem;
	temp->next = nullptr;
	temp->data = data;
	temp->prev = Tail;
	if (Tail != nullptr)
		Tail->next = temp;
	Tail = temp;
	if (Head == nullptr)
		Head = temp;
	Count++;
}

void List::DelHead()
{
	if (Head != nullptr)
	{
		Elem* temp = Head;
		Head = Head->next;
		if (Head != nullptr)
			Head->prev = nullptr;
		else
			Tail = nullptr;
		//delete temp;
		Count--;
	}
}

void List::DelTail()
{
	if (Tail != nullptr)
	{
		Elem* temp = Tail;
		Tail = Tail->prev;
		if (Tail != nullptr)
			Tail->next = nullptr;
		else
			Head = nullptr;
		delete temp;
		Count--;
	}
}

void List::Insert(char data, int pos)
{
	if (pos < 0 || pos > Count)
		return;
	if (pos == 0)
	{
		AddHead(data);
		return;
	}
	if (pos == Count)
	{
		AddTail(data);
		return;
	}
	Elem* current = nullptr;
	if (pos < Count / 2)
	{
		current = Head;
		int i = 0;
		while (i < pos)
		{
			current = current->next;
			i++;
		}
	}
	else
	{
		current = Tail;
		int i = Count - 1;
		while (i > pos)
		{
			current = current->prev;
			i--;
		}
	}
	Elem* temp = new Elem;
	temp->data = data;
	temp->prev = current->prev;
	temp->next = current;
	current->prev->next = temp;
	current->prev = temp;
	Count++;
}

void List::Del(int pos)
{
	if (pos < 0 || pos >= Count)
		return;
	if (pos == 0)
	{
		DelHead();
		return;
	}
	if (pos == Count - 1)
	{
		DelTail();
		return;
	}
	Elem* delElement = nullptr;
	if (pos < Count / 2)
	{
		delElement = Head;
		int i = 0;
		while (i < pos)
		{
			delElement = delElement->next;
			i++;
		}
	}
	else
	{
		delElement = Tail;
		int i = Count - 1;
		while (i > pos)
		{
			delElement = delElement->prev;
			i--;
		}
	}
	delElement->prev->next = delElement->next;
	delElement->next->prev = delElement->prev;
	delete delElement;
	Count--;
}

void List::PrintHead()
{
	Elem* current = Head;
	while (current != nullptr)
	{
		cout << current->data;
		current = current->next;
	}
	cout << endl;
}

void List::PrintTail()
{
	Elem* current = Tail;
	while (current != nullptr)
	{
		cout << current->data;
		current = current->prev;
	}
	cout << endl;
}

void List::DelAll()
{
	while (Head != nullptr)
		DelHead();
}

int List::GetCount()
{
	return Count;
}

Elem* List::GetElem(int pos)
{
	Elem* temp = Head;
	if (pos < 0 || pos >= Count)
		return nullptr;
	int i = 0;
	while (i < pos)
	{
		temp = temp->next;
		i++;
	}
	return temp;
}

List& List::operator = (const List& L)
{
	if (this == &L)
		return *this;
	DelAll();
	Elem* temp = L.Head;
	while (temp != nullptr)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
	return *this;
}

int List::Find(char key)
{
	Elem* current = Head;
	int pos = 0;

	while (current != nullptr)
	{
		if (current->data == key)
			return pos;
		current = current->next;
		pos++;
	}
	return -1;
}

void List::Replace(char value, int position)
{
	if (position < 0 || position >= Count)
	{
		cout << "\nWrong index\n";
		return;
	}
	if (position < Count / 2)
	{
		Elem* current = Head;
		int i = 0;
		while (i < position)
		{
			current = current->next;
			i++;
		}
		current->data = value;
	}
	else
	{
		Elem* current = Tail;
		int i = Count - 1;
		while (i > position)
		{
			current = current->prev;
			i--;
		}
		current->data = value;
	}
}

void List::DelElementByKey(char key)
{
	Elem* current = Head;

	while (current != nullptr)
	{
		if (current->data == key)
		{
			if (current->prev == nullptr)
				DelHead();
			else if (current->next == nullptr)
			{
				DelTail();
				return;
			}

			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
				Count--;
			}
		}
		current = current->next;
	}
}

char& List::operator[](int position)
{
	if (position < 0 || position >= Count)
	{
		cout << "\nWrong index;\n";
		char c = '#';
		return c;
	}

	if (position < Count / 2)
	{
		Elem* current = Head;
		int i = 0;
		while (i < position)
		{
			current = current->next;
			i++;
		}
		return current->data;
	}
	else
	{
		Elem* current = Tail;
		int i = Count - 1;
		while (i > position)
		{
			current = current->prev;
			i--;
		}
		return current->data;
	}
}

void List::Sort()
{

	List* t = new List;
	t = this;


	Elem* tmp2 = Tail;

	for (int i = 0; i < Count; i++)
	{
		tmp2 = Tail;
		for (int j = Count - 1; j > 0; j--)
		{
			if (tmp2->prev->data > tmp2->data)
			{
				Elem* tmp = new Elem;
				tmp->data = tmp2->prev->data;
				tmp2->prev->data = tmp2->data;
				tmp2->data = tmp->data;
			}
			tmp2 = tmp2->prev;
		}
	}
}



//void bubbleSort(T a[], long size)
//{

//	for (i = 0; i < size; i++)
//	{ // i - номер прохода 
//		for (j = size - 1; j > i; j--)
//		{ // внутренний цикл
//		 прохода
//			if (a[j - 1] > a[j])
//			{
//				x = a[j - 1];
//				a[j - 1] = a[j];
//				a[j] = x;
//			}
//		}
//	}
//}





//Elem* ptr2 = Tail;
//
//char* c = new char[Count];
//
//Elem* current = Head;
//int pos = 0;
//
//while (current != nullptr)
//{
//	c[pos] = current->data;
//	current = current->next;
//	pos++;
//}
//
//for (int i = 0; i < Count; i++)
//{ // i - номер прохода 
//	for (int j = Count - 1; j > i; j--)
//	{ // внутренний цикл
//		if (c[j - 1] > c[j])
//		{
//			char temp = c[j - 1];
//			c[j - 1] = c[j];
//			c[j] = temp;
//		}
//	}
//}
//
//pos = 0;
//current = Head;
//
//while (current != nullptr)
//{
//	current->data = c[pos];
//	current = current->next;
//	pos++;
//}




//List* t = new List;
//t = this;
//
//
//Elem* tmp2 = Tail;
//
//for (int i = 0; i < Count; i++)
//{
//	tmp2 = Tail;
//	for (int j = Count - 1; j > 0; j--)
//	{
//		if (tmp2->prev->data > tmp2->data)
//		{
//			Elem* tmp = new Elem;
//			tmp->data = tmp2->prev->data;
//			tmp2->prev->data = tmp2->data;
//			tmp2->data = tmp->data;
//		}
//		tmp2 = tmp2->prev;
//	}
//}



//void List::Sort()
//{
//
//	Elem* tmp2 = Tail;
//
//	for (int i = 0; i < Count; i++)
//	{
//		tmp2 = Tail;
//		//tmp2 = tmp2->prev;
//		for (int j = Count - 1; j > 1; j--)
//		{
//			//int j = Count - 1;
//			if (tmp2->prev->data > tmp2->data)
//			{
//				/*Elem* tmp = new Elem;
//
//				tmp->next = tmp2->next;
//				tmp->prev = tmp2->prev;*/
//				const char c = tmp2->prev->data;
//				//cout << "    " << c << "   ";
//
//				tmp2->prev->prev->next = tmp2->prev->next;
//				tmp2->prev->next->prev = tmp2->prev->prev;
//				Count--;
//				cout << "    " << j << "   ";
//				//if (j == Count - 1)
//				AddTail(c);
//				//else 
//					//Insert(j  , c);
//
//				//////tmp->data = tmp2->prev->data;
//				////tmp->next = tmp2->prev->next;
//				////tmp->prev = tmp2->prev->prev;
//				////
//				////
//
//				//////tmp2->prev->data = tmp2->data;
//				////tmp2->prev->next = tmp2->next;
//				////tmp2->prev->prev = tmp2->prev;
//
//				//////tmp2->data = tmp->data;
//				////tmp2->next = tmp->next;
//				////tmp2->prev = tmp->prev;
//
//
//				cout << endl;
//				PrintHead();
//				//tmp2 = tmp2->prev;
//			}
//			else
//				tmp2 = tmp2->prev;
//		}
//		tmp2 = Head;
//		if (tmp2->data > tmp2->next->data)
//		{
//			AddTail(tmp2->data);
//			DelHead();
//		}
//		cout << i;
//	}
//
//
//}