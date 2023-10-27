// 11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
	// Создаем объект класса List
	List lst;
	// Тестовая строка
	char s[] = "Hello, World !!!\n";
	// Выводим строку
	cout << s << endl;
	// Определяем длину строки
	int len = strlen(s);
	// Помещаем строку в список
	for (int i = len - 1; i >= 0; i--)
		lst.Add(s[i]);
	// Распечатываем содержимое списка
	lst.Print();
	// Удаляем два элемента списка
	lst.Del();
	lst.Del();
	// Распечатываем содержимое списка
	lst.Print();
	//Проверяем наличие символа 'S' в списке, получаем индекс
	char c = 'S';
	lst.InsertByPosition(c, 4);
	lst.Print();
	//удаляем элесент списка под индексом 2
	lst.RemoveByPosition(2);
	lst.Print();
	//Проверяем наличие символа '!' в списке
	int n = lst.Find('!');
	cout << "n = " << n << endl << endl;
	//Проверяем наличие символа 'a' в списке
	n = lst.Find('a');
	cout << "n = " << n << endl << endl;
	//Добавляем символ '?' в конец списка
	lst.AddBack('?');
	lst.Print();
	cout << endl;
	//Тестируем конструктор киптрования
	List L(lst);
	L.Print();
	cout << endl;
	//Тестируем оператор = с конструктором киптрования
	List li = lst;
	li.Print();
	cout << endl;
	//Удаляем все элементы всех списков, выводим содержимое
	L.DelAll();
	L.Print();
	cout << endl;

	li.DelAll();
	li.Print();
	cout << endl;

	lst.DelAll();
	lst.Print();
	cout << endl;

	return 0;
}

