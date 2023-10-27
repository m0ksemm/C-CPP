#include <iostream>
#include "List.h"

using namespace std;
int main()
{
	List lst;
	char s[] = "Hello, World !!!";
	cout << s << endl;
	int len = strlen(s);
	for (int i = len - 1; i >= 0; i--)
		lst.AddHead(s[i]);
	cout << "\nFirst list\n";
	lst.PrintHead();
	List lst2 = lst;
	cout << "\nSecond list\n";
	lst2.PrintHead();
	List lst3;
	lst3 = lst;
	cout << "\nThird list\n";
	lst3.PrintHead();
	cout << "\nFirst list\n";
	lst.PrintTail();
	lst.Del(2);
	lst.PrintHead();
	lst.Insert('?', 0);
	lst.Insert('?', 4);
	lst.Insert('?', 4);
	lst.PrintHead();
	lst.DelHead();
	lst.PrintHead();
	lst.DelTail();
	lst.PrintHead();


	cout << "\n\n\nTest 1:       int Find (char key);\n";
	char c;
	cout << endl << "Enter the key: ";
	cin >> c;
	int find = lst.Find(c);

	switch (find)
	{
	case -1:
		cout << "There is no such a key in this list;\n";
		break;
	default:
		cout << "The key \"" << c << "\" is located on the position #" << find;
		break;
	}


	cout << "\n\n\nTest 2:       void Replace (char value, int position);\n\n";
	int pos;
	cout << "Enter value: ";
	cin >> c;
	cout << "Enter position: ";
	cin >> pos;
	lst.Replace(c, pos);
	cout << "\nYour list: \n";
	lst.PrintHead();

	List ls;
	char st[] = "aaabbbcccddd";

	int leng = strlen(st);
	for (int i = leng - 1; i >= 0; i--)
		ls.AddHead(st[i]);



	cout << "\n\n\nTest 3:       void DelElementByKey(char key);\n\n";
	cout << "Your new list: \n";
	ls.PrintHead();
	cout << "\nEnter key: ";
	cin >> c;
	ls.DelElementByKey(c);
	cout << "\nYour list: \n";
	ls.PrintHead();


	cout << "\n\n\nTest 4:       char& operator[](int position);\n\n";
	cout << "Your list: \n";
	lst.PrintHead();
	int index;
	cout << "\nEnter the index: ";
	cin >> index;

	cout << lst[index] << endl;

	List ls2;
	char st2[] = "983254761";

	int leng2 = strlen(st2);
	for (int i = leng2 - 1; i >= 0; i--)
		ls2.AddHead(st2[i]);

	cout << "\n\n\nTest 5:       void Sort();\n\n";
	cout << "Your list: \n";
	ls2.PrintHead();

	ls2.Sort();

	cout << "\nsorted\n";
	ls2.PrintHead();
	return 0;
}
