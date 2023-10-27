
class CFraction
{

private: // ������ � ���� ����� ����� ����� ������ ������ ������
	int numerator;
	int denomerator;
public: // �������� ������ ������(������������ ����� ������)

	CFraction();
	CFraction(int num, int denum);
	void enter_fraction(); // �����, ���������� �� ��������� ������������� ����� ������.
	void output_fraction();// ����� ��� ������ �����.
	void setNumerator(int num); // ����������� ��� ���� numerator.
	void setDenomerator(int denum); // ����������� ��� ���� denomerator.
	int getNumerator(); // ��������� ��� ���� numerator.
	int getDenomerator(); // ��������� ��� ���� denomerator.
	int int_part(int num, int denum); // ����� ��������� ����� �����.
	double double_fraction(int num, int denum);// ����� �������� ����� � ������������ �����.

	friend CFraction operator+(CFraction& , CFraction& ); //������������� �������� +
	friend CFraction operator-(CFraction&, CFraction&);  //������������� �������� -
	friend CFraction operator*(CFraction&, CFraction&);  //������������� �������� *
	friend CFraction operator/(CFraction&, CFraction&);  //������������� �������� /

	friend bool operator>(CFraction& fract1, CFraction& fract2);  //������������� �������� >
	friend bool operator>=(CFraction& fract1, CFraction& fract2); //������������� �������� >=
	friend bool operator<(CFraction& fract1, CFraction& fract2);  //������������� �������� <
	friend bool operator<=(CFraction& fract1, CFraction& fract2); //������������� �������� <=

	friend bool operator==(CFraction& fract1, CFraction& fract2); //������������� �������� ==
	friend bool operator!=(CFraction& fract1, CFraction& fract2); //������������� �������� !=

};
