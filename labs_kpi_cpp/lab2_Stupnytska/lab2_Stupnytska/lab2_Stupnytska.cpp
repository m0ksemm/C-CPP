#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Базові класи////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class Container   // Базовий клас для всіх контейнерів
{
public:
	virtual void Set() {}				 // віртуальний метод для заповнення полів контейнеру з клавіатури
	virtual void Output() const {}		 // віртуальний метод для виведення даних контейнеру
	virtual void Type_output() const {}	 // віртуальний метод для виведення типу даних контейнеру
};

class Container_arr : Container		// Базовий клас для всіх контейнерів з масивами 
{
protected:
	int count;					// Поле, що містить кількість елементів масиву					
public:
	Container_arr()				// Конструктор за замовченням	
	{
		count = 0;
	}
	Container_arr(int n)		// Конструктор з 1 параметром - кількістю елементів	масиву
	{
		count = n;
	}
	int Get_count_of_elements() const		// Метод, що повертає кількість елементів масиву			
	{
		return count;
	}
	virtual void Edit_count_of_elements(int number)		// Метод, що змінює кількість елементів масиву
	{
		count += number;
	}
	virtual void Clear_the_array() {}		// Віртуальний метод, що буде очищати масив 
	virtual void Insert_the_element() {}	// Віртуальний метод, що буде вставляти 
											// елемент потрібного типу на задану позицію

	virtual void Delete_the_element() {}	// Віртуальний метод, що видаляє елемент з масиву
											// за певним індексом
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////Класи контейнери для значень різних типів/////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////


class _int :public Container
{
private:
	int value;			// Поле-контейнер

public:
	_int()				// Конструктор за замовченням
	{
		value = 0;
	}
	_int(int n)			// Конструктор з одним параметром
	{
		value = n;
	}
	void Set()				// Введення даних з клавіатури
	{
		cout << "Enter value of type INT: ";
		int n;
		cin >> n;
		value = n;
	}
	void Set_value(int _value)		// Метод, що задає поле, отримуючи дані як параметр
	{
		value = _value;
	}
	void Output() const
	{
		cout << value << endl;
	}
	virtual void Type_output() const		// метод, що виводить тип контейнера
	{
		cout << "Type: int" << endl;
	}
};

class _char :public Container
{
private:
	char value;				// Поле-контейнер
public:
	_char()					// Конструктор за замовченням
	{
		value = '0';
	}
	_char(char _value)		// Конструктор з одним параметром
	{
		value = _value;
	}
	void Set()				// Введення даних з клавіатури
	{
		cout << "Enter value of type CHAR: ";
		char _value;
		cin >> _value;
		value = _value;
	}
	void Set_value(char _value)		// Метод, що задає поле, отримуючи дані як параметр
	{
		value = _value;
	}
	void Output() const
	{
		cout << value << endl;
	}
	virtual void Type_output() const		// метод, що виводить тип контейнера
	{
		cout << "Type: char\n";
	}
};

class _float :public Container
{
private:
	float value;		// Поле-контейнер

public:
	_float()			// Конструктор за замовченням
	{
		value = 0;
	}
	_float(float f)		// Конструктор з одним параметром
	{
		value = f;
	}
	void Set()			// Введення даних з клавіатури
	{
		cout << "Enter value of type FLOAT: ";
		float _value;
		cin >> _value;
		value = _value;
	}
	void Output() const
	{
		cout << value << endl;
	}
	virtual void Type_output() const			// метод, що виводить тип контейнера
	{
		cout << "Type: float\n";
	}
	void Set_value(float _value)	// Метод, що задає поле, отримуючи дані як параметр
	{	
		value = _value;
	}
};

class _double :public Container
{
private:
	double value;			// Поле-контейнер

public:
	_double()				// Конструктор за замовченням
	{
		value = 0;
	}
	_double(double d)		// Конструктор з одним параметром
	{
		value = d;
	}
	void Set()				// Введення даних з клавіатури
	{
		cout << "Enter value of type DOUBLE: ";
		double _value;
		cin >> _value;
		value = _value;
	}
	void Output() const		// Виведення даних на екран 
	{
		cout << value << endl;
	}
	void Set_value(double _value)	// Метод, що задає поле, отримуючи дані як параметр
	{
		value = _value;
	}
	virtual void Type_output() const			// метод, що виводить тип контейнера
	{
		cout << "Type: double\n";
	}
};

class _bool :public Container
{
private:
	bool value;				// Поле-контейнер

public:
	_bool()					// Конструктор за замовченням
	{
		value = false;
	}
	_bool(bool b)			// Конструктор з одним параметром
	{
		value = b;
	}
	void Set()				// Введення даних з клавіатури
	{
		cout << "Enter value of type BOOL: ";
		bool _value;
		cin >> _value;
		value = _value;
	}
	void Set_value(bool _value)		// Метод, що задає поле, отримуючи дані як параметр
	{
		value = _value;
	}
	void Output() const			// Виведення даних на екран 
	{
		cout << value << endl;
	}
	virtual void Type_output() const	// метод, що виводить тип контейнера
	{
		cout << "Type: bool" << endl;
	}
};



/////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////Класи контейнери для масивів різних типів/////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

class int_array : public Container_arr
{
private:
	int* int_arr;
public:
	int_array() : Container_arr()					// Конструктор за замовченням
	{
		int_arr = nullptr;
	}
	int_array(int n) : Container_arr(n)
	{
		int* arr = new int[count];
		srand(time(NULL));
		for (int i = 0; i < count; i++)
		{
			*(arr + i) = rand() % 100;
		}
		int_arr = arr;
	}
	void Set()				// Введення даних з клавіатури
	{
		cout << "Enter " << Get_count_of_elements() << " elements" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ": ";
			cin >> int_arr[i];
		}
	}
	int_array(const int* c, int n) : Container_arr(n)
	{
		int* contain = new int[count];
		for (int i = 0; i < count; i++)
			*(contain + i) = *(c + i);
		int_arr = contain;
	}

	int_array(const int_array& arr) : Container_arr(arr.count)
	{
		int* contain = new int[count];
		for (int i = 0; i < count; i++)
		{
			*(contain + i) = *(arr.int_arr + i);
		}
		int_arr = contain;
	}

	~int_array()					// Деструктор
	{
		delete[] int_arr;
	}

	void Output() const			// Виведення даних на екран 
	{
		for (int i = 0; i < count; i++)
			cout << setw(3) << *(int_arr + i);
	}

	void Clear_the_array()
	{
		count = 0;
		int_arr = nullptr;
	}

	bool Is_array_clear() const		// Метод, що перевіряє, чи є масив пустим
	{
		if (int_arr == nullptr)
			return true;
		else return false;
	}

	void Insert_the_element(int index, const int& item)
	{
		if (index < 0 || index > count)
			return;
		Edit_count_of_elements(1);
		int number = 0;
		int* contain = new int[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				number = 1;
				contain[i] = item;
			}
			else
			{
				contain[i] = int_arr[i - number];
			}
		}
		delete[] int_arr;
		int_arr = contain;
	}
	void Delete_the_element(int index)	// Віртуальний метод, що видаляє елемент з масиву за певним індексом
	{
		if (index < 0 || index > count)
			return;
		int number = 0;
		Edit_count_of_elements(-1);
		int* contain = new int[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
				number = 1;
			contain[i] = int_arr[i + number];
		}
		delete[] int_arr;
		int_arr = contain;
	}

	_int Return_By_Index(int index)
	{

		_int obj;
		obj.Set_value(*(int_arr + index));
		return obj;
	}

	void Type_output() const				// метод, що виводить тип контейнера
	{
		cout << "Type: int[" << Get_count_of_elements() << "]\n";
	}
};

class double_array : public Container_arr
{
private:
	double* double_arr;
public:
	double_array() : Container_arr()				// Конструктор за замовченням
	{
		double_arr = nullptr;
	}

	double_array(int n) : Container_arr(n)
	{
		double* arr = new double[count];
		srand(time(NULL));
		for (int i = 0; i < count; i++)
		{
			*(arr + i) = rand() % 100;
		}
		double_arr = arr;
	}
	void Set()					// Введення даних з клавіатури
	{
		cout << "Enter " << Get_count_of_elements() << " elements" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ": ";
			cin >> double_arr[i];
		}
	}
	double_array(const double* c, int n) : Container_arr(n)
	{
		double* contain = new double[count];
		for (int i = 0; i < count; i++)
			*(contain + i) = *(c + i);
		double_arr = contain;
	}

	double_array(const double_array& arr) : Container_arr(arr.count)
	{
		double* contain = new double[count];
		for (int i = 0; i < count; i++)
		{
			*(contain + i) = *(arr.double_arr + i);
		}
		double_arr = contain;
	}

	~double_array()					// Деструктор
	{
		delete[] double_arr;
	}

	void Output() const			// Виведення даних на екран 
	{
		for (int i = 0; i < count; i++)
			cout << setw(4) << *(double_arr + i);
	}

	void Clear_the_array()
	{
		count = 0;
		double_arr = nullptr;
	}

	bool Is_array_clear() const			// Метод, що перевіряє, чи є масив пустим
	{
		if (double_arr == nullptr)
			return true;
		else return false;
	}

	void Insert_the_element(int index, const double& item)
	{
		if (index < 0 || index > count)
			return;
		Edit_count_of_elements(1);
		int number = 0;
		double* contain = new double[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				number = 1;
				contain[i] = item;
			}
			else
			{
				contain[i] = double_arr[i - number];
			}
		}
		delete[] double_arr;
		double_arr = contain;
	}
	void Delete_the_element(int index)	// Віртуальний метод, що видаляє елемент з масиву за певним індексом
	{
		if (index < 0 || index > count)
			return;
		int number = 0;
		Edit_count_of_elements(-1);
		double* contain = new double[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
				number = 1;
			contain[i] = double_arr[i + number];
		}
		delete[] double_arr;
		double_arr = contain;
	}

	_double Return_By_Index(int index)
	{

		_double obj;
		obj.Set_value(*(double_arr + index));
		return obj;
	}

	void Type_output() const				// метод, що виводить тип контейнера
	{
		cout << "Type: double[" << Get_count_of_elements() << "]\n";
	}
};


class char_array : public Container_arr
{
private:
	char* char_arr;
public:
	char_array() : Container_arr()				// Конструктор за замовченням
	{
		char_arr = nullptr;
	}

	char_array(int n) : Container_arr(n)
	{
		char* arr = new char[count];
		srand(time(NULL));
		for (int i = 0; i < count; i++)
		{
			*(arr + i) = rand() % 10 + 1;
		}
		char_arr = arr;
	}
	void Set()						// Введення даних з клавіатури
	{
		cout << "Enter " << Get_count_of_elements() << " elements" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ": ";
			cin >> char_arr[i];
		}
	}
	char_array(const char* c, int n) : Container_arr(n)
	{
		char* contain = new char[count];
		for (int i = 0; i < count; i++)
			*(contain + i) = *(c + i);
		char_arr = contain;
	}

	char_array(const char_array& arr) : Container_arr(arr.count)
	{
		char* contain = new char[count];
		for (int i = 0; i < count; i++)
		{
			*(contain + i) = *(arr.char_arr + i);
		}
		char_arr = contain;
	}

	~char_array()					// Деструктор
	{
		delete[] char_arr;
	}

	void Output() const				// Виведення даних на екран 
	{
		for (int i = 0; i < count; i++)
			cout << setw(4) << *(char_arr + i);
	}

	void Clear_the_array()
	{
		count = 0;
		char_arr = nullptr;
	}

	bool Is_array_clear() const   // Метод, що перевіряє, чи є масив пустим
	{
		if (char_arr == nullptr)
			return true;
		else return false;
	}

	void Insert_the_element(int index, const char& element)
	{
		if (index < 0 || index > count)
			return;
		Edit_count_of_elements(1);
		int number = 0;
		char* contain = new char[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				number = 1;
				contain[i] = element;
			}
			else
			{
				contain[i] = char_arr[i - number];
			}
		}
		delete[] char_arr;
		char_arr = contain;
	}
	void Delete_the_element(int index)	// Віртуальний метод, що видаляє елемент з масиву за певним індексом
	{
		if (index < 0 || index > count)
			return;
		int number = 0;
		Edit_count_of_elements(-1);
		char* contain = new char[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
				number = 1;
			contain[i] = char_arr[i + number];
		}
		delete[] char_arr;
		char_arr = contain;
	}

	_char Return_By_Index(int index)
	{

		_char obj;
		obj.Set_value(*(char_arr + index));
		return obj;
	}

	void Type_output() const				// метод, що виводить тип контейнера
	{
		cout << "Type: char[" << Get_count_of_elements() << "]\n";
	}
};


class bool_array : public Container_arr
{
private:
	int* bool_arr;
public:
	bool_array() : Container_arr()				// Конструктор за замовченням
	{
		bool_arr = nullptr;
	}
	void Set()					// Введення даних з клавіатури
	{
		cout << "Enter " << Get_count_of_elements() << " elements" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ": ";
			cin >> bool_arr[i];
		}
	}
	bool_array(int n) : Container_arr(n)
	{
		int* arr = new int[count];
		srand(time(NULL));
		for (int i = 0; i < count; i++)
		{
			*(arr + i) = rand() % 2;
		}
		bool_arr = arr;
	}

	bool_array(const bool* c, int n) : Container_arr(n)
	{
		int* contain = new int[count];
		for (int i = 0; i < count; i++)
			*(contain + i) = *(c + i);
		bool_arr = contain;
	}

	bool_array(const bool_array& arr) : Container_arr(arr.count)
	{
		int* contain = new int[count];
		for (int i = 0; i < count; i++)
		{
			*(contain + i) = *(arr.bool_arr + i);
		}
		bool_arr = contain;
	}
	~bool_array()					// Деструктор
	{
		delete[] bool_arr;
	}
	void Output() const				// Виведення даних на екран 
	{
		for (int i = 0; i < count; i++)
			cout << setw(4) << *(bool_arr + i);
	}
	void Clear_the_array()
	{
		count = 0;
		bool_arr = nullptr;
	}
	bool Is_array_clear() const		// Метод, що перевіряє, чи є масив пустим
	{
		if (bool_arr == nullptr)
			return true;
		else return false;
	}
	void Insert_the_element(int index, const bool& element)
	{
		if (index < 0 || index > count)
			return;
		Edit_count_of_elements(1);
		int number = 0;
		int* contain = new int[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				number = 1;
				contain[i] = element;
			}
			else
			{
				contain[i] = bool_arr[i - number];
			}
		}
		delete[] bool_arr;
		bool_arr = contain;
	}
	void Delete_the_element(int index)	// Віртуальний метод, що видаляє елемент з масиву за певним індексом
	{
		if (index < 0 || index > count)
			return;
		int number = 0;
		Edit_count_of_elements(-1);
		int* contain = new int[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
				number = 1;
			contain[i] = bool_arr[i + number];
		}
		delete[] bool_arr;
		bool_arr = contain;
	}
	_bool Return_By_Index(int index)
	{

		_bool obj;
		obj.Set_value(*(bool_arr + index));
		return obj;
	}
	void Type_output() const				// метод, що виводить тип контейнера
	{
		cout << "Type: bool[" << Get_count_of_elements() << "]" << endl;
	}
};

class float_array : public Container_arr
{
private:
	float* float_arr;
public:
	float_array() : Container_arr()				// Конструктор за замовченням
	{
		float_arr = nullptr;
	}
	void Set()					// Введення даних з клавіатури	
	{
		cout << "Enter " << Get_count_of_elements() << " elements" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ": ";
			cin >> float_arr[i];
		}
	}
	float_array(int n) : Container_arr(n)
	{
		float* arr = new float[count];
		srand(time(NULL));
		for (int i = 0; i < count; i++)
		{
			*(arr + i) = rand() % 100;
		}
		float_arr = arr;
	}
	float_array(const float* c, int n) : Container_arr(n)
	{
		float* contain = new float[count];
		for (int i = 0; i < count; i++)
			*(contain + i) = *(c + i);
		float_arr = contain;
	}
	float_array(const float_array& arr) : Container_arr(arr.count)
	{
		float* contain = new float[count];
		for (int i = 0; i < count; i++)
		{
			*(contain + i) = *(arr.float_arr + i);
		}
		float_arr = contain;
	}
	~float_array()					// Деструктор
	{
		delete[] float_arr;
	}
	void Output() const					// Виведення даних на екран 
	{
		for (int i = 0; i < count; i++)
			cout << setw(4) << *(float_arr + i);
	}
	void Clear_the_array()
	{
		count = 0;
		float_arr = nullptr;
	}
	bool Is_array_clear() const		// Метод, що перевіряє, чи є масив пустим
	{
		if (float_arr == nullptr)
			return true;
		else return false;
	}
	void Insert_the_element(int index, const float& element)
	{
		if (index < 0 || index > count)
			return;
		Edit_count_of_elements(1);
		int number = 0;
		float* contain = new float[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				number = 1;
				contain[i] = element;
			}
			else
			{
				contain[i] = float_arr[i - number];
			}
		}
		delete[] float_arr;
		float_arr = contain;
	}
	void Delete_the_element(int index)	// Віртуальний метод, що видаляє елемент з масиву за певним індексом
	{
		if (index < 0 || index > count)
			return;
		int number = 0;
		Edit_count_of_elements(-1);
		float* contain = new float[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
				number = 1;
			contain[i] = float_arr[i + number];
		}
		delete[] float_arr;
		float_arr = contain;
	}
	_float Return_By_Index(int index)
	{

		_float obj;
		obj.Set_value(*(float_arr + index));
		return obj;
	}
	void Type_output() const						// метод, що виводить тип контейнеру
	{
		cout << "Type: float[" << Get_count_of_elements() << "]" << endl;
	}
};



/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////Функція main()//////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////


Container* Random() // Функція, що генерує рандомний контейнер
{
	int number = rand() % 5;
	if (number == 0)
		 return new _int();
	else if (number == 1)
		return new _double();
	else if (number == 2)
		return new _float();
	else if (number == 3)
		return new _char();
	else if (number == 4)
		return new _bool();
}

int main()
{
	while (true)
	{												// На цьому етапі треба обрати, які 
		system("cls");								// контейнери користувач буде тестувати
		cout << "1 - value containers" << endl;// - контейнери зі значенням певного типу	
		cout << "2 - array containers" << endl;// - контейнери з масиваи значеннь певного типу
		cout << "Escape - exit" << endl;// - завершити тестування програми. Треба нажати клавішу ESCAPE
		int choice1 = _getch();
		if (choice1 == VK_ESCAPE)
		{
			break;
		}
		else if (choice1 == '1')
		{
			while (true)
			{
				system("cls");			// На цьому етапі треба тип контейнеру з одним значенням
				cout << "1 - int" << endl;
				cout << "2 - double" << endl;
				cout << "3 - float" << endl;
				cout << "4 - char" << endl;
				cout << "5 - bool" << endl;
				cout << "Escape - return" << endl; // - варіант щоб повернутись на попередній етап
				int choice2 = _getch();
				if (choice2 == VK_ESCAPE)
				{
					break;
				}
				else if (choice2 == '1')	// тестування контейнеру INT
				{
					system("cls");
					cout << "container INT" << endl << endl;
					_int obj;
					obj.Set();				
					obj.Output();
					obj.Type_output();
					_getch();
				}
				else if (choice2 == '2')	// тестування контейнеру DOUBLE
				{
					system("cls");
					cout << "container DOUBLE" << endl << endl;
					_double obj;
					obj.Set();
					obj.Output();
					obj.Type_output();
					_getch();
				}
				else if (choice2 == '3')	// тестування контейнеру FLOAT
				{
					system("cls");
					cout << "container FLOAT" << endl << endl;
					_float obj;
					obj.Set();
					obj.Output();
					obj.Type_output();
					_getch();
				}
				else if (choice2 == '4')	// тестування контейнеру CHAR
				{
					system("cls");
					cout << "container CHAR" << endl << endl;
					_char obj;
					obj.Set();
					obj.Output();
					obj.Type_output();
					_getch();
				}
				else if (choice2 == '5') // тестування контейнеру BOOL
				{
					system("cls");
					cout << "container BOOL" << endl << endl;
					_bool obj;
					obj.Set();
					obj.Output();
					obj.Type_output();
					_getch();
				}
			}
		}
		else if (choice1 == '2')
		{
			while (true)
			{
				system("cls");
				cout << "1 - int[]" << endl;
				cout << "2 - double[]" << endl;
				cout << "3 - float[]" << endl;
				cout << "4 - char[]" << endl;
				cout << "5 - bool[]" << endl;
				cout << "Escape - return" << endl;
				int choice2 = _getch();
				if (choice2 == VK_ESCAPE)
				{
					break;
				}
				else if (choice2 == '1')		// тестування контейнеру INT[]
				{
					system("cls");
					cout << "container INT[]" << endl;
					int array[5] = { 1, 3, 2, 4, 6 };
					int_array obj(array, 5);
					cout << endl << "Array container:" << endl;
					obj.Output();

					cout << endl << "Element with index 1 is removed:" << endl;
					obj.Delete_the_element(1);
					obj.Output();

					cout << endl << "Element 9 inserted on index 3:" << endl;
					obj.Insert_the_element(3, 9);
					obj.Output();

					cout << endl << "Element with index 2:" << endl;
					_int elem = obj.Return_By_Index(2);
					elem.Output();

					cout << "Size of array: " << obj.Get_count_of_elements() << endl;

					obj.Type_output();

					obj.Clear_the_array();
					cout << "Array was cleared" << endl;
					_getch();
				}
				else if (choice2 == '2')		// тестування контейнеру DOUBLE[]
				{
					system("cls");
					cout << "container DOUBLE[]" << endl;
					double array[5] = { 1.7, 3.1, 2.9, 4.5, 6.3 };
					double_array obj(array, 5);
					cout << endl << "Array container: " << endl;
					obj.Output();

					cout << endl << "Element with index 1 is removed:" << endl;
					obj.Delete_the_element(1);
					obj.Output();

					cout << endl << "Element 9.4 inserted on index 3:" << endl;
					obj.Insert_the_element(3, 9.4);
					obj.Output();

					cout << endl << "Element with index 2:" << endl;
					_double elem = obj.Return_By_Index(2);
					elem.Output();

					cout << "Size of array: " << obj.Get_count_of_elements() << endl;

					obj.Type_output();

					obj.Clear_the_array();
					cout << "Array was cleared" << endl;
					_getch();
				}
				else if (choice2 == '3')		// тестування контейнеру FLOAT[]
				{
					system("cls");
					cout << "container FLOAT[]" << endl;
					float array[5] = { 6.6, 3.3, 1.1, 5.5, 7.7 };
					float_array obj(array, 5);
					cout << endl << "Array container:" << endl;
					obj.Output();

					cout << endl << "Element with index 1 is removed:" << endl;
					obj.Delete_the_element(1);
					obj.Output();

					cout << endl << "Element 1.5 inserted on index 3:" << endl;
					obj.Insert_the_element(3, 1.5);
					obj.Output();

					cout << endl << "Element with index 2:" << endl;
					_float elem = obj.Return_By_Index(2);
					elem.Output();

					cout << "Size of array: " << obj.Get_count_of_elements() << endl;

					obj.Type_output();

					obj.Clear_the_array();
					cout << "Array was cleared" << endl;
					_getch();
				}
				else if (choice2 == '4')		// тестування контейнеру CHAR[]
				{
					system("cls");
					cout << "container CHAR[]" << endl;
					char array[5] = { 'a','b','c','d','e' };
					char_array obj(array, 5);
					cout << endl << "Array container:" << endl;
					obj.Output();

					cout << endl << "Element with index 1 is removed:" << endl;
					obj.Delete_the_element(1);
					obj.Output();

					cout << endl << "Element 'X' inserted on index 3:" << endl;
					obj.Insert_the_element(3, 'X');
					obj.Output();

					cout << endl << "Element with index 2:" << endl;
					_char elem = obj.Return_By_Index(2);
					elem.Output();

					cout << "Size of array: " << obj.Get_count_of_elements() << endl;

					obj.Type_output();

					obj.Clear_the_array();
					cout << "Array was cleared" << endl;
					_getch();
				}
				else if (choice2 == '5')		// тестування контейнеру BOOL[]
				{
					system("cls");
					cout << "container BOOL[]" << endl;
					bool array[5] = { true, false, true, false, true };
					bool_array obj(array, 5);
					cout << endl << "Array container:" << endl;
					obj.Output();

					cout << endl << "Element with index 1 is removed:" << endl;
					obj.Delete_the_element(1);
					obj.Output();

					cout << endl << "Element fase inserted on index 3:" << endl;
					obj.Insert_the_element(3, false);
					obj.Output();

					cout << endl << "Element with index 2:" << endl;
					_bool elem = obj.Return_By_Index(2);
					elem.Output();

					cout << "Size of array: " << obj.Get_count_of_elements() << endl;

					obj.Type_output();

					obj.Clear_the_array();
					cout << "Array was cleared" << endl;
					_getch();
				}
			}
		}
	}

	system("cls");
	cout << "Dynamic_cast test" << endl; // Демонстрація можливостей засобу RTTI Dynamic_cast

	int int_ = 0, double_ = 0, float_ = 0, char_ = 0, bool_ = 0;
	
	_int* i = nullptr;
	_float* f = nullptr;
	_double* d = nullptr;
	_char* c = nullptr;
	_bool* b = nullptr;
	Container* pointer = nullptr;
	for (int index = 0; index < 15; index++)
	{
		pointer = Random();
		
		i = dynamic_cast<_int*>(pointer);  // алгоритм встановлення і накопичення   
		if (i)							   // типів контейнерів, який отримав 
			int_++;						   // вказівник pointer
		else
		{
			f = dynamic_cast<_float*>(pointer);
			if (f)
				float_++;
			else
			{
				d = dynamic_cast<_double*>(pointer);
				if (d)
					double_++;
				else
				{
					c = dynamic_cast<_char*>(pointer);
					if (c)
						char_++;
					else
						bool_++;
				}
			}
		}
	}
	cout << "------------------------- " << endl;
	cout << "| INT containers:   | " << int_ << " | " << endl;
	cout << "| FLOAT containers: | " << float_ << " | " << endl;
	cout << "| DOUBLE containers:| " << double_ << " | " << endl;
	cout << "| CHAR containers:  | " << char_ << " | " << endl;
	cout << "| BOOL containers:  | " << bool_ << " | " << endl;
	cout << "------------------------- " << endl;


}

