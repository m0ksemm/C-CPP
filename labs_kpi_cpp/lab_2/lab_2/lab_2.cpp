#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>

using namespace std;

class сontainer
{
public:
	virtual void set() {}
	virtual void type() const {}
	virtual void test() {}

};

//-----------------------------------------------------------------------------------------

class arr : сontainer
{
protected:
	int count;
public:
	arr()
	{
		count = 0;
	}
	arr(int number)
	{
		count = number;
	}
	int get_count() const
	{
		return count;
	}

	virtual void clear() {}
	virtual void insert() {}
	virtual void remove() {}
	virtual void resize() {}
};

//-----------------------------------------------------------------------------------------

class int_ :public сontainer
{
private:
	int value;

public:
	int_()
	{
		value = 0;
	}
	int_(int n)
	{
		value = n;
	}
	void set(int _value)
	{
		value = _value;
	}
	friend ostream& operator<<(ostream& os, int_& _a)
	{
		cout << _a.value << endl;
		return os;
	}
	friend istream& operator >> (istream& is, int_& _a)
	{
		cout << "Enter the int value:" << endl;
		cin >> _a.value;

		return is;
	}
	void type() const
	{
		cout << "int" << endl;
	}
	void test() {
		int_ container_;
		cin >> container_;
		cout << "Container 1: " << endl;
		cout << container_;

		int_ container_2(6);
		cout << "Container 2: " << endl;
		cout << container_2;
		cout << "Type: " << endl;

		container_2.type();
		system("pause");
	}
};

class char_ :public сontainer
{
private:
	char value;
public:
	char_()
	{
		value = '0';
	}
	char_(char _value)
	{
		value = _value;
	}
	void set(char _value)
	{
		value = _value;
	}
	friend ostream& operator<<(ostream& os, char_& _a)
	{
		cout << _a.value << endl;
		return os;
	}
	friend istream& operator >> (istream& is, char_& _a)
	{
		cout << "Enter the char value:" << endl;
		cin >> _a.value;

		return is;
	}
	void type() const
	{
		cout << "char\n";
	}
	void test() {
		char_ container_;
		cin >> container_;
		cout << "Container 1: " << endl;
		cout << container_;

		char_ container_2(1);
		cout << "Container 2: " << endl;
		cout << container_2;
		cout << "Type: " << endl;

		container_2.type();
		system("pause");
	}
};

class float_ :public сontainer
{
private:
	float value;

public:
	float_()
	{
		value = 0;
	}
	float_(float f)
	{
		value = f;
	}
	void set(float _value)
	{
		value = _value;
	}
	friend ostream& operator<<(ostream& os, float_& _a)
	{
		cout << _a.value << endl;
		return os;
	}
	friend istream& operator >> (istream& is, float_& _a)
	{
		cout << "Enter the float value:" << endl;
		cin >> _a.value;

		return is;
	}
	void type() const
	{
		cout << "float\n";
	}
	void test() 
	{
		float_ container_;
		cin >> container_;
		cout << "Container 1: " << endl;
		cout << container_;

		float_ container_2(10.25);
		cout << "Container 2: " << endl;
		cout << container_2;
		cout << "Type: " << endl;

		container_2.type();
		system("pause");
	}
};

class double_ :public сontainer
{
private:
	double value;

public:
	double_()
	{
		value = 0;
	}
	double_(double d)
	{
		value = d;
	}
	friend ostream& operator<<(ostream& os, double_& _a)
	{
		cout << _a.value << endl;
		return os;
	}
	friend istream& operator >> (istream& is, double_& _a)
	{
		cout << "Enter the double value:" << endl;
		cin >> _a.value;

		return is;
	}
	void set(double _value)
	{
		value = _value;
	}
	void type() const
	{
		cout << "double\n";
	}
	void test() {
		double_ container_;
		cin >> container_;
		cout << "Container 1: " << endl;
		cout << container_;

		double_ container_2(22.06);
		cout << "Container 2: " << endl;
		cout << container_2;
		cout << "Type: " << endl;

		container_2.type();
		system("pause");
	}
};

class bool_ :public сontainer
{
private:
	bool value;

public:
	bool_()
	{
		value = false;
	}
	bool_(bool b)
	{
		value = b;
	}
	void set(bool _value)
	{
		value = _value;
	}
	friend ostream& operator<<(ostream& os, bool_& _a)
	{
		cout << _a.value << endl;
		return os;
	}
	friend istream& operator >> (istream& is, bool_& _a)
	{
		cout << "Enter the bool value:" << endl;
		cin >> _a.value;

		return is;
	}
	void type() const
	{
		cout << "bool" << endl;
	}
	void test() 
	{
		bool_ container_;
		cin >> container_;
		cout << "Container 1: " << endl;
		cout << container_;

		bool_ container_2(0);
		cout << "Container 2: " << endl;
		cout << container_2;
		cout << "Type: " << endl;

		container_2.type();
		system("pause");
	}
};

//-----------------------------------------------------------------------------------------

class int_array : public arr
{
private:
	int* int_arr;
public:
	int_array() : arr()
	{
		int_arr = nullptr;
	}
	int_array(int n) : arr(n)
	{
		int* arr = new int[count];
		srand(time(NULL));
		for (int i = 0; i < count; i++)
		{
			*(arr + i) = rand() % 100;
		}
		int_arr = arr;
	}
	void resize(int n)
	{
		if (n == 0)
			return;
		else if (n > 0)
		{
			int* tmp = new int[count + n];
			for (int i = 0; i < count; i++)
			{
				tmp[i] = int_arr[i];
			}
			for (int i = count; i < count + n; i++)
			{
				tmp[i] = 0;
			}
			delete[] int_arr;
			int_arr = tmp;
			count += n;
		}
		else if (n < 0)
		{
			int* tmp = new int[count + n];
			count += n;
			for (int i = 0; i < count; i++)
			{
				tmp[i] = int_arr[i];
			}
			delete[] int_arr;
			int_arr = tmp;
		}
	}
	friend ostream& operator<<(ostream& os, int_array& _a)
	{
		for (int i = 0; i < _a.get_count(); i++)
			cout << setw(5) << _a.int_arr[i] << " ";
		cout << endl;
		return os;
	}
	friend istream& operator >> (istream& is, int_array& _a)
	{
		cout << "Enter " << _a.get_count() << " elements: " << endl;
		for (int i = 0; i < _a.get_count(); i++)
			cin >> _a.int_arr[i];
		return is;
	}

	int_array(const int* c, int n) : arr(n)
	{
		int* temp = new int[count];
		for (int i = 0; i < count; i++)
			*(temp + i) = *(c + i);
		int_arr = temp;
	}

	int_array(const int_array& arr) : arr(arr.count)
	{
		int* temp = new int[count];
		for (int i = 0; i < count; i++)
		{
			*(temp + i) = *(arr.int_arr + i);
		}
		int_arr = temp;
	}

	~int_array() {
		delete[] int_arr;
	}

	void clear()
	{
		count = 0;
		int_arr = nullptr;
	}

	bool is_clear() const
	{
		if (int_arr == nullptr)
			return true;
		else return false;
	}

	void insert(int index, const int& item)
	{
		if (index < 0 || index > count)
			return;
		count += 1;
		int number = 0;
		int* temp = new int[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				number = 1;
				temp[i] = item;
			}
			else
			{
				temp[i] = int_arr[i - number];
			}
		}
		delete[] int_arr;
		int_arr = temp;
	}
	void remove(int index)
	{
		if (index < 0 || index > count)
			return;
		int number = 0;
		count += -1;
		int* temp = new int[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
				number = 1;
			temp[i] = int_arr[i + number];
		}
		delete[] int_arr;
		int_arr = temp;
	}

	int_ get_elem(int index)
	{

		int_ newobj;
		newobj.set(int_arr[index]);
		return newobj;
	}
	void set(int i, int value) 
	{
		int_arr[i] = value;
	}
	void type() const
	{
		cout << "int[" << get_count() << "]\n";
	}
	int& operator() (int i)
	{
		return int_arr[i];
	}
	void test() 
	{
		int_array array(6);
		cin >> array;
		cout << "Array 1: " << endl;
		cout << array;

		cout << "Length: " << array.get_count() << endl;

		array.resize(3);
		cout << array;
		cout << endl;
		array.resize(-5);
		cout << array;

		cout << "array[3] = " << array(3) << endl;

		int_ container_ = array.get_elem(2);
		cout << "Conteiner from array[2]: " ;

		cout << container_;

		int arr[5] = { 1, 2, 3, 4, 5 };
		int_array array2(arr, 5);
		cout << "Array 2: " << endl;
		cout << array2;

		cout << "Type: " << endl;
		array2.type();

		system("pause");
	}
};

class float_array : public arr
{
private:
	float* float_arr;
public:
	float_array() : arr()
	{
		float_arr = nullptr;
	}
	float_array(int n) : arr(n)
	{
		float* arr = new float[count];
		srand(time(NULL));
		for (int i = 0; i < count; i++)
		{
			*(arr + i) = rand() % 100;
		}
		float_arr = arr;
	}
	float_array(const float* c, int n) : arr(n)
	{
		float* temp = new float[count];
		for (int i = 0; i < count; i++)
			*(temp + i) = *(c + i);
		float_arr = temp;
	}
	float_array(const float_array& arr) : arr(arr.count)
	{
		float* temp = new float[count];
		for (int i = 0; i < count; i++)
		{
			*(temp + i) = *(arr.float_arr + i);
		}
		float_arr = temp;
	}
	friend ostream& operator<<(ostream& os, float_array& _a)
	{
		for (int i = 0; i < _a.get_count(); i++)
			cout << setw(5) << _a.float_arr[i] << " ";
		cout << endl;
		return os;
	}
	friend istream& operator >> (istream& is, float_array& _a)
	{
		cout << "Enter " << _a.get_count() << " elements: " << endl;
		for (int i = 0; i < _a.get_count(); i++)
			cin >> _a.float_arr[i];
		return is;
	}
	~float_array()
	{
		delete[] float_arr;
	}
	void clear()
	{
		count = 0;
		float_arr = nullptr;
	}
	bool is_clear() const
	{
		if (float_arr == nullptr)
			return true;
		else return false;
	}
	void resize(int n)
	{
		if (n == 0)
			return;
		else if (n > 0)
		{
			float* tmp = new float[count + n];
			for (int i = 0; i < count; i++)
			{
				tmp[i] = float_arr[i];
			}
			for (int i = count; i < count + n; i++)
			{
				tmp[i] = 0;
			}
			delete[] float_arr;
			float_arr = tmp;
			count += n;
		}
		else if (n < 0)
		{
			float* tmp = new float[count + n];
			count += n;
			for (int i = 0; i < count; i++)
			{
				tmp[i] = float_arr[i];
			}
			delete[] float_arr;
			float_arr = tmp;
		}
	}
	void insert(int index, const float& element)
	{
		if (index < 0 || index > count)
			return;
		++count;
		int number = 0;
		float* temp = new float[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				number = 1;
				temp[i] = element;
			}
			else
			{
				temp[i] = float_arr[i - number];
			}
		}
		delete[] float_arr;
		float_arr = temp;
	}
	void remove(int index)
	{
		if (index < 0 || index > count)
			return;
		int number = 0;
		count--;
		float* temp = new float[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
				number = 1;
			temp[i] = float_arr[i + number];
		}
		delete[] float_arr;
		float_arr = temp;
	}
	float_ get_elem(int index)
	{
		float_ newobj;
		newobj.set(float_arr[index]);
		return newobj;
	}
	void set(int i, float value)
	{
		float_arr[i] = value;
	}
	void type() const
	{
		cout << "float[" << get_count() << "]" << endl;
	}
	float& operator() (int i)
	{
		return float_arr[i];
	}
	void test() {
		float_array array(6);
		cin >> array;
		cout << "Array 1: " << endl;
		cout << array;

		cout << "Length: " << array.get_count() << endl;

		array.resize(3);
		cout << array;
		cout << endl;
		array.resize(-5);
		cout << array;

		cout << "array[3] = " << array(3) << endl;

		float_ container_ = array.get_elem(2);
		cout << "Conteiner from array[2]: ";
		cout << container_;

		float arr[5] = { 1.295, 2.05, 3.715, 4.135, 5.365 };
		float_array array2(arr, 5);
		cout << "Array 2: " << endl;
		cout << array2;

		cout << "Type: " << endl;
		array2.type();

		system("pause");
	}
};

class double_array : public arr
{
private:
	double* double_arr;
public:
	double_array() : arr()
	{
		double_arr = nullptr;
	}

	double_array(int n) : arr(n)
	{
		double* arr = new double[count];
		srand(time(NULL));
		for (int i = 0; i < count; i++)
		{
			*(arr + i) = rand() % 100;
		}
		double_arr = arr;
	}
	friend ostream& operator<<(ostream& os, double_array& _a)
	{
		for (int i = 0; i < _a.get_count(); i++)
			cout << setw(5) << _a.double_arr[i] << " ";
		cout << endl;
		return os;
	}
	friend istream& operator >> (istream& is, double_array& _a)
	{
		cout << "Enter " << _a.get_count() << " elements: " << endl;
		for (int i = 0; i < _a.get_count(); i++)
			cin >> _a.double_arr[i];

		return is;
	}
	double_array(const double* c, int n) : arr(n)
	{
		double* temp = new double[count];
		for (int i = 0; i < count; i++)
			*(temp + i) = *(c + i);
		double_arr = temp;
	}

	double_array(const double_array& arr) : arr(arr.count)
	{
		double* temp = new double[count];
		for (int i = 0; i < count; i++)
		{
			*(temp + i) = *(arr.double_arr + i);
		}
		double_arr = temp;
	}

	~double_array()
	{
		delete[] double_arr;
	}
	void clear()
	{
		count = 0;
		double_arr = nullptr;
	}

	bool is_clear() const
	{
		if (double_arr == nullptr)
			return true;
		else return false;
	}

	void insert(int index, const double& item)
	{
		if (index < 0 || index > count)
			return;
		count++;
		int number = 0;
		double* temp = new double[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				number = 1;
				temp[i] = item;
			}
			else
			{
				temp[i] = double_arr[i - number];
			}
		}
		delete[] double_arr;
		double_arr = temp;
	}
	void remove(int index)
	{
		if (index < 0 || index > count)
			return;
		int number = 0;
		count--;
		double* temp = new double[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
				number = 1;
			temp[i] = double_arr[i + number];
		}
		delete[] double_arr;
		double_arr = temp;
	}
	void resize(int n)
	{
		if (n == 0)
			return;
		else if (n > 0)
		{
			double* tmp = new double[count + n];
			for (int i = 0; i < count; i++)
			{
				tmp[i] = double_arr[i];
			}
			for (int i = count; i < count + n; i++)
			{
				tmp[i] = 0;
			}
			delete[] double_arr;
			double_arr = tmp;
			count += n;
		}
		else if (n < 0)
		{
			double* tmp = new double[count + n];
			count += n;
			for (int i = 0; i < count; i++)
			{
				tmp[i] = double_arr[i];
			}
			delete[] double_arr;
			double_arr = tmp;
		}
	}
	double_ get_elem(int index)
	{

		double_ newobj;
		newobj.set(double_arr[index]);
		return newobj;
	}
	void set(int i, double value)
	{
		double_arr[i] = value;
	}
	void type() const
	{
		cout << "double[" << get_count() << "]\n";
	}
	double& operator() (int i)
	{
		return double_arr[i];
	}
	void test() {
		double_array array(6);
		cin >> array;
		cout << "Array 1: " << endl;
		cout << array;

		cout << "Length: " << array.get_count() << endl;

		array.resize(3);
		cout << array;
		cout << endl;
		array.resize(-5);
		cout << array;

		cout << "array[3] = " << array(3) << endl;

		double_ container_ = array.get_elem(2);
		cout << "Conteiner from array[2]: ";
		cout << container_;

		double arr[5] = { 1.25, 2.5, 3.75, 4.15, 5.35 };
		double_array array2(arr, 5);
		cout << "Array 2: " << endl;
		cout << array2;

		cout << "Type: " << endl;
		array2.type();

		system("pause");
	}
};


class char_array : public arr
{
private:
	char* char_arr;
public:
	char_array() : arr()
	{
		char_arr = nullptr;
	}

	char_array(int n) : arr(n)
	{
		char* arr = new char[count];
		srand(time(NULL));
		for (int i = 0; i < count; i++)
		{
			*(arr + i) = rand() % 10 + 1;
		}
		char_arr = arr;
	}
	friend ostream& operator<<(ostream& os, char_array& _a)
	{
		for (int i = 0; i < _a.get_count(); i++)
			cout << setw(5) << _a.char_arr[i] << " ";
		cout << endl;
		return os;
	}
	friend istream& operator >> (istream& is, char_array& _a)
	{
		cout << "Enter " << _a.get_count() << " elements: " << endl;
		for (int i = 0; i < _a.get_count(); i++)
			cin >> _a.char_arr[i];
		return is;
	}
	char_array(const char* c, int n) : arr(n)
	{
		char* temp = new char[count];
		for (int i = 0; i < count; i++)
			*(temp + i) = *(c + i);
		char_arr = temp;
	}
	char_array(const char_array& arr) : arr(arr.count)
	{
		char* temp = new char[count];
		for (int i = 0; i < count; i++)
		{
			*(temp + i) = *(arr.char_arr + i);
		}
		char_arr = temp;
	}

	~char_array()
	{
		delete[] char_arr;
	}
	void clear()
	{
		count = 0;
		char_arr = nullptr;
	}
	void resize(int n)
	{
		if (n == 0)
			return;
		else if (n > 0)
		{
			char* tmp = new char[count + n];
			for (int i = 0; i < count; i++)
			{
				tmp[i] = char_arr[i];
			}
			for (int i = count; i < count + n; i++)
			{
				tmp[i] = '0';
			}
			delete[] char_arr;
			char_arr = tmp;
			count += n;
		}
		else if (n < 0)
		{
			char* tmp = new char[count + n];
			count += n;
			for (int i = 0; i < count; i++)
			{
				tmp[i] = char_arr[i];
			}
			delete[] char_arr;
			char_arr = tmp;
		}
	}
	bool is_clear() const
	{
		if (char_arr == nullptr)
			return true;
		else return false;
	}

	void insert(int index, const char& element)
	{
		if (index < 0 || index > count)
			return;
		count++;
		int number = 0;
		char* temp = new char[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				number = 1;
				temp[i] = element;
			}
			else
			{
				temp[i] = char_arr[i - number];
			}
		}
		delete[] char_arr;
		char_arr = temp;
	}
	void remove(int index)
	{
		if (index < 0 || index > count)
			return;
		int number = 0;
		count--;
		char* temp = new char[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
				number = 1;
			temp[i] = char_arr[i + number];
		}
		delete[] char_arr;
		char_arr = temp;
	}

	char_ get_elem(int index)
	{

		char_ newobj;
		newobj.set(char_arr[index]);
		return newobj;
	}
	void set(int i, char value)
	{
		char_arr[i] = value;
	}
	void type() const
	{
		cout << "char[" << get_count() << "]\n";
	}
	char& operator() (int i)
	{
		return char_arr[i];
	}
	void test() {
		char_array array(6);
		cin >> array;
		cout << "Array 1: " << endl;
		cout << array;

		cout << "Length: " << array.get_count() << endl;

		array.resize(3);
		cout << array;
		cout << endl;
		array.resize(-5);
		cout << array;

		cout << "array[3] = " << array(3) << endl;

		char_ container_ = array.get_elem(2);
		cout << "Conteiner from array[2]: ";
		cout << container_;

		char arr[5] = { char(1), 'W', char(3), 'a', char(5) };
		char_array array2(arr, 5);
		cout << "Array 2: " << endl;
		cout << array2;

		cout << "Type: " << endl;
		array2.type();

		system("pause");
	}
};


class bool_array : public arr
{
private:
	bool* bool_arr;
public:
	bool_array() : arr()
	{
		bool_arr = nullptr;
	}
	bool_array(int n) : arr(n)
	{
		bool* arr = new bool[count];
		srand(time(NULL));
		for (int i = 0; i < count; i++)
		{
			*(arr + i) = rand() % 2;
		}
		bool_arr = arr;
	}

	bool_array(const bool* c, int n) : arr(n)
	{
		bool* temp = new bool[count];
		for (int i = 0; i < count; i++)
			*(temp + i) = *(c + i);
		bool_arr = temp;
	}

	bool_array(const bool_array& arr) : arr(arr.count)
	{
		bool* temp = new bool[count];
		for (int i = 0; i < count; i++)
		{
			*(temp + i) = *(arr.bool_arr + i);
		}
		bool_arr = temp;
	}
	friend ostream& operator<<(ostream& os, bool_array& _a)
	{
		for (int i = 0; i < _a.get_count(); i++)
			cout << setw(5) << _a.bool_arr[i] << " ";
		cout << endl;
		return os;
	}
	friend istream& operator >> (istream& is, bool_array& _a)
	{
		cout << "Enter " << _a.get_count() << " elements: " << endl;
		for (int i = 0; i < _a.get_count(); i++)
			cin >> _a.bool_arr[i];
		return is;
	}
	
	~bool_array()
	{
		delete[] bool_arr;
	}
	void clear()
	{
		count = 0;
		bool_arr = nullptr;
	}
	bool is_clear() const
	{
		if (bool_arr == nullptr)
			return true;
		else return false;
	}
	void resize(int n)
	{
		if (n == 0)
			return;
		else if (n > 0)
		{
			bool* tmp = new bool[count + n];
			for (int i = 0; i < count; i++)
			{
				tmp[i] = bool_arr[i];
			}
			for (int i = count; i < count + n; i++)
			{
				tmp[i] = true;
			}
			delete[] bool_arr;
			bool_arr = tmp;
			count += n;
		}
		else if (n < 0)
		{
			bool* tmp = new bool[count + n];
			count += n;
			for (int i = 0; i < count; i++)
			{
				tmp[i] = bool_arr[i];
			}
			delete[] bool_arr;
			bool_arr = tmp;
		}
	}
	void insert(int index, const bool& element)
	{
		if (index < 0 || index > count)
			return;
		++count;
		int number = 0;
		bool* temp = new bool[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
			{
				number = 1;
				temp[i] = element;
			}
			else
			{
				temp[i] = bool_arr[i - number];
			}
		}
		delete[] bool_arr;
		bool_arr = temp;
	}
	void remove(int index)
	{
		if (index < 0 || index > count)
			return;
		int number = 0;
		--count;
		bool* temp = new bool[count];
		for (int i = 0; i < count; i++)
		{
			if (index == i)
				number = 1;
			temp[i] = bool_arr[i + number];
		}
		delete[] bool_arr;
		bool_arr = temp;
	}
	bool_ get_elem(int index)
	{

		bool_ newobj;
		newobj.set(bool_arr[index]);
		return newobj;
	}
	void set(int i, bool value)
	{
		bool_arr[i] = value;
	}
	void type() const
	{
		cout << "bool[" << get_count() << "]" << endl;
	}
	bool& operator() (int i)
	{
		return bool_arr[i];
	}
	void test() {
		bool_array array(6);
		cin >> array;
		cout << "Array 1: " << endl;
		cout << array;

		cout << "Length: " << array.get_count() << endl;

		array.resize(3);
		cout << array;
		cout << endl;
		array.resize(-5);
		cout << array;

		cout << "array[3] = " << array(3) << endl;

		bool_ container_ = array.get_elem(2);
		cout << "Conteiner from array[2]: ";
		cout << container_;

		bool arr[5] = { true, false, false, true, true };
		bool_array array2(arr, 5);
		cout << "Array 2: " << endl;
		cout << array2;

		cout << "Type: " << endl;
		array2.type();

		system("pause");
	}
};

//-----------------------------------------------------------------------------------------

сontainer* func() 
{
	int number = rand() % 5;
	if (number == 0)
		return new int_();
	else if (number == 1)
		return new double_();
	else if (number == 2)
		return new float_();
	else if (number == 3)
		return new char_();
	else if (number == 4)
		return new bool_();
}

void test_f(сontainer * сontainer_)
{
	сontainer_->test();
}

void main()
{
	int n;
	while (true)
	{
		system("cls");
		cout << "------------------------------------" << endl;
		cout << "| values:        |   arrays:       |" << endl;
		cout << "------------------------------------" << endl;
		cout << "|  1 - int       |    6 - int[]    |" << endl;
		cout << "|  2 - double    |    7 - double[] |" << endl;
		cout << "|  3 - float     |    8 - float[]  |" << endl;
		cout << "|  4 - char      |    9 - char[]   |" << endl;
		cout << "|  5 - bool      |    10- bool[]   |" << endl;
		cout << "------------------------------------" << endl;
		cout << "|  0 - exit.                       |" << endl;
		cout << "------------------------------------" << endl << endl << endl;

		cin >> n;

		if (n == 0)
			break;
		else if (n == 1)
		{
			system("cls");
			cout << "int_" << endl << endl;
			int_ i;
			i.test();
		}	
		else if (n == 2)
		{
			system("cls");
			cout << "double_" << endl << endl;
			double_ d;
			d.test();
		}
		else if (n == 3)
		{
			system("cls");
			cout << "float_" << endl << endl;
			float_ f;
			f.test();
		}
		else if (n == 4)
		{
			system("cls");
			cout << "char_" << endl << endl;
			char_ c;
			c.test();
		}
		else if (n == 5)
		{
			system("cls");
			cout << "bool_" << endl << endl;
			bool_ b;
			b.test();
		}
		else if (n == 6)
		{
			system("cls");
			cout << "int_array" << endl << endl;
			int_array i;
			i.test();
		}
		else if (n == 7)
		{
			system("cls");
			cout << "double_array" << endl << endl;
			double_array d;
			d.test();
		}
		else if (n == 8)
		{
			system("cls");
			cout << "float_array" << endl << endl;
			float_array f;
			f.test();
		}
		else if (n == 9)
		{
			system("cls");
			cout << "char_array" << endl << endl;
			char_array c;
			c.test();
		}
		else if (n == 10)
		{
			system("cls");
			cout << "bool_array" << endl << endl;
			bool_array b;
			b.test();
		}
	}

	system("cls");
	cout << "dynamic_cast<type*>(p)" << endl;

	сontainer* p = nullptr;
	int_* i = nullptr;
	double_* d = nullptr;
	float_* f = nullptr;
	char_* c = nullptr;

	int I = 0, D = 0, F = 0, C = 0, B = 0;

	for (int j = 0; j < 40; j++)
	{
		p = func();

		i = dynamic_cast<int_*>(p);
		if (i)
			I++;
		else
		{
			d = dynamic_cast<double_*>(p);
			if (d)
				D++;
			else
			{
				f = dynamic_cast<float_*>(p);
				if (f)
					F++;
				else
				{
					c = dynamic_cast<char_*>(p);
					if (c)
						C++;
					else
						B++;
				}
			}
		}
	}
	cout << "The number of objects created randomly: " << endl << endl;
	cout << "int:     " << I  << endl;
	cout << "double:  " << D  << endl;
	cout << "float:   " << F  << endl;
	cout << "char:    " << C  << endl;
	cout << "bool:    " << B  << endl;
}