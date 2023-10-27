#pragma once;

struct Elem
{
	char data; // ������
	Elem* next, * prev;
};

class List
{
	// ������, �����
	Elem* Head, * Tail;
	// ���������� ���������
	int Count;

public:

	// �����������
	List();

	// ����������� �����������
	List(const List&);

	// ����������
	~List();

	// �������� ���������� ���������
	int GetCount();

	// �������� ������� ������
	Elem* GetElem(int);

	// ������� ���� ������
	void DelAll();

	// �������� �������� �� �������
	void Del(int pos);

	// ������� �������� � �������� �������
	void Insert(char data, int pos);

	// ���������� � ����� ������
	void AddTail(char data);

	// ���������� � ������ ������
	void AddHead(char data);

	//�������� ��������� ��������
	void DelHead();

	//�������� ���������� ��������
	void DelTail();

	// ������ ������, ������� � ������
	void PrintHead();

	//������ ������, ������� � ������
	void PrintTail();

	//���������� ��������� =
	List& operator = (const List&);

	//����� ������ ��������� �������� �� �����
	int Find(char);

	//����� ������ �������� ���������� �������� �� ������ ��������
	void Replace(char, int);

	//����� �������� ��������� ������ �� �����
	void DelElementByKey(char);

	//������������� �������� ��������������
	char& operator[](int);

	//����� ���������� ��������� ������
	void Sort();
};
