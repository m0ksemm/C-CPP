#pragma once;

struct Elem
{
	char data; // данные
	Elem* next, * prev;
};

class List
{
	// Голова, хвост
	Elem* Head, * Tail;
	// Количество элементов
	int Count;

public:

	// Конструктор
	List();

	// Конструктор копирования
	List(const List&);

	// Деструктор
	~List();

	// Получить количество элементов
	int GetCount();

	// Получить элемент списка
	Elem* GetElem(int);

	// Удалить весь список
	void DelAll();

	// Удаление элемента по индексу
	void Del(int pos);

	// Вставка элемента в заданную позицию
	void Insert(char data, int pos);

	// Добавление в конец списка
	void AddTail(char data);

	// Добавление в начало списка
	void AddHead(char data);

	//Удаление головного элемента
	void DelHead();

	//Удаление хвостового элемента
	void DelTail();

	// Печать списка, начиная с головы
	void PrintHead();

	//Печать списка, начиная с хвоста
	void PrintTail();

	//перегрузка оператора =
	List& operator = (const List&);

	//метод поиска заданного элемента по ключу
	int Find(char);

	//Метод замены значения указанного элемента на другое значение
	void Replace(char, int);

	//Метод удаления элементов списка по ключу
	void DelElementByKey(char);

	//Перегруженный оператор индексирования
	char& operator[](int);

	//Метод сортировки элементов списка
	void Sort();
};
