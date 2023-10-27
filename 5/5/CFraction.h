
class CFraction
{

private: // доступ к этим полям будут иметь только методы класса
	int numerator;
	int denomerator;
public: // открытые методы класса(интерфейсная часть класса)

	CFraction();
	CFraction(int num, int denum);
	void enter_fraction(); // метод, отвечающий за начальную инициализацию полей класса.
	void output_fraction();// метод для вывода дроби.
	void setNumerator(int num); // модификатор для поля numerator.
	void setDenomerator(int denum); // модификатор для поля denomerator.
	int getNumerator(); // инспектор для поля numerator.
	int getDenomerator(); // инспектор для поля denomerator.
	int int_part(int num, int denum); // Метод выделения целой части.
	double double_fraction(int num, int denum);// Метод перевода дроби в вещественное число.

	CFraction& operator+(CFraction& fract1);  //перегруженный оператор +
	CFraction& operator-(CFraction& fract1);  //перегруженный оператор -

	CFraction& operator*(CFraction& fract1);  //перегруженный оператор *
	CFraction& operator/(CFraction& fract1);  //перегруженный оператор /

	bool operator>(const CFraction& fract1);  //перегруженный оператор >
	bool operator>=(const CFraction& fract1); //перегруженный оператор >=

	bool operator<(const CFraction& fract1);  //перегруженный оператор <
	bool operator<=(const CFraction& fract1); //перегруженный оператор <=

	bool operator==(const CFraction& fract1); //перегруженный оператор ==
	bool operator!=(const CFraction& fract1); //перегруженный оператор !=
};
