#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>

using namespace std;

/*
Абстрактна фабрика - породжуючий патерн проектування,
який надає інтерфейс для створення родин взаємопов'язаних або взаємозалежних об'єктів,
не специфікуючи їх конкретні класи.

Застосовність
- система не повинна залежати від того, як створюються, компонуються і представляються об'єкти, що до неї входять;
- взаємопов'язані об'єкти, що входять до сімейства, повинні використовуватися разом і необхідно забезпечити виконання цього обмеження;
- система повинна конфігуруватися одним із сімейств складових її об'єктів;
- необхідно надати бібліотеку об'єктів, розкриваючи лише їх інтерфейси, але з реалізацію.

Патерн абстрактна фабрика володіє наступними плюсами та мінусами :
*Ізолює конкретні класи.
* Спрощує заміну сімейств товарів.
* гарантує поєднання продуктів.
* Підтримати новий вид продуктів важко.
*/

// AbstractProductA
class Herbivore abstract // інтерфейс для травоїдних тварин 
{
public:
	int Weight;
	bool Life;
public:
	virtual void Eat_grass() = 0;
	virtual void Show() = 0;

};

// ConcreteProductA1
class Wildebeest : public Herbivore      // Клас для антилопи гну
{
public:
	Wildebeest()
	{
		Weight = rand() % (250 - 51) + 50;
		Life = true;
	}
	void Eat_grass()
	{
		Weight += 10;
	}
	void Show()
	{
		cout << "Wildebeest" << endl;
		if (Life == true)
		{
			cout << "Alive" << endl;
			cout << "Weight: " << Weight << endl;
		}
		else cout << "Dead" << endl << endl;

	}
};

// ConcreteProductA2
class Bison : public Herbivore    // Клас для бізона
{
public:
	Bison()
	{
		Weight = rand() % (280 - 91) + 90;;
		Life = true;
	}
	void Eat_grass()
	{
		Weight += 10;
	}
	void Show()
	{
		cout << "Bison" << endl;
		if (Life == true)
		{
			cout << "Alive" << endl;
			cout << "Weight: " << Weight << endl;
		}
		else cout << "Dead" << endl << endl;

	}
};

// ConcreteProductA3
class Elk : public Herbivore    // Клас для лося
{
public:
	Elk()
	{
		Weight = rand() % (300 - 101) + 100;
		Life = true;
	}
	void Eat_grass()
	{
		Weight += 10;
	}
	void Show()
	{
		cout << "Elk" << endl;
		if (Life == true)
		{
			cout << "Alive" << endl;
			cout << "Weight: " << Weight << endl;
		}
		else cout << "Dead" << endl << endl;

	}
};

/////////////////////////

//AbstractProductB
class Carnivore abstract    // Клас для хижаків
{
protected:
	int Power;
public:
	virtual void Eat(Herbivore*) = 0;
	virtual void Show() = 0;
};

// ConcreteProductB1
class Lion : public Carnivore   // Клас для левів
{
public:
	Lion()
	{
		Power = rand() % (210 - 191) + 190;
	}
	void Eat(Herbivore* Herbivore_animal)
	{
		if (Herbivore_animal->Weight < Power)
		{
			Power += 10;
			Herbivore_animal->Life = false;
		}
		else Power -= 10;
	}
	void Show()
	{
		cout << "Lion" << endl;
		cout << "Power: " << Power << endl;
	}
};

// ConcreteProductB2
class Wolf : public Carnivore    // Клас для вовків
{
public:
	Wolf()
	{
		Power = rand() % (180 - 131) + 130;
	}
	void Eat(Herbivore* Herbivore_animal)
	{
		if (Herbivore_animal->Weight < Power)
		{
			Power += 10;
			Herbivore_animal->Life = false;
		}
		else Power -= 10;
	}
	void Show()
	{
		cout << "Wolf" << endl;
		cout << "Power: " << Power << endl;
	}
};

// ConcreteProductB3
class Tiger : public Carnivore    // Клас для тигру
{
public:
	Tiger()
	{
		Power = rand() % (280 - 201) + 190;
	}
	void Eat(Herbivore* Herbivore_animal)
	{
		if (Herbivore_animal->Weight < Power)
		{
			Power += 10;
			Herbivore_animal->Life = false;
		}
		else Power -= 10;
	}
	void Show()
	{
		cout << "Tiger" << endl;
		cout << "Power: " << Power << endl;
	}
};

////////////////////////////////

// клас абстрактнї фабрики
//AbstractFactory
class Continent abstract
{
public:
	virtual Herbivore* CreateHerbivore() abstract;
	virtual Carnivore* CreateCarnivore() abstract;
};

//ConcreteFactory1
class Africa : public Continent  // concrete fabric.  Африка
{
	Herbivore* CreateHerbivore() override
	{
		return new Wildebeest();
	}
	Carnivore* CreateCarnivore() override
	{
		return new Lion();
	}
};

//ConcreteFactory2
class North_America : public Continent // concrete fabric. Північна Америка
{
	Herbivore* CreateHerbivore() override
	{
		return new Bison();
	}
	Carnivore* CreateCarnivore() override
	{
		return new Wolf();
	}
};

//ConcreteFactory3
class Eurasia : public Continent  // concrete fabric. Євразія
{
	Herbivore* CreateHerbivore() override
	{
		return new Elk();
	}
	Carnivore* CreateCarnivore() override
	{
		return new Tiger();
	}
};

///////////////

// клас клієнт
class Animal_World
{
	Herbivore* herbi[5];
	Carnivore* carni[5];

public:
	Animal_World(Continent* continent)
	{
		for (int i = 0; i < 5; i++) {
			herbi[i] = continent->CreateHerbivore();
			carni[i] = continent->CreateCarnivore();
		}
	}
	void Meals_herbivores() // функция питания всех травоядных
	{
		for (int i = 0; i < 5; i++) {
			herbi[i]->Eat_grass();
		}
		cout << "Om-nom-nom-nom-nom..." << endl;
		system("pause");
	}
	void Nutrition_carnivores() // функція харчування хижака, що буде обраним 
	{
		system("cls");
		cout << "\t*The hunt*" << endl << endl;
		cout << "Which carnivore will hunt?" << endl;
		for (int i = 0; i < 5; i++) {
			cout << endl << i + 1 << endl;
			carni[i]->Show();
		}
		int c;
		while (true)
		{
			cin >> c;
			if (c > 0 && c < 6)
			{
				break;
			}
			else
			{
				cout << "Wrong choice! Try again" << endl;
				system("pause");
			}
		}

		cout << endl << "Who will be the meal?" << endl;
		for (int j = 0; j < 5; j++)
		{
			if (herbi[j]->Life == true)
			{
				cout << endl << j + 1 << endl;
				herbi[j]->Show();
			}
		}
		int choice;
		while (true)
		{
			cin >> choice;
			if (choice > 0 && choice < 6 && herbi[choice - 1]->Life == true)
			{
				carni[c - 1]->Eat(herbi[choice - 1]);
				break;
			}
			else cout << "Wrong choice! Try again";
			system("pause");
		}
		if (herbi[choice - 1]->Life == false)
		{
			cout << "Herbivores animal was eaten!" << endl;
			system("pause");
		}
		else
		{
			cout << "Oops! Carnivores animal is too weak for this meal... " << endl;
			system("pause");
		}

	}
	void Show_Animals()
	{
		cout << "Herbivores animals: " << endl;
		for (int i = 0; i < 5; i++) {
			cout << endl << "Animal " << i + 1 << ":" << endl;
			herbi[i]->Show();
		}
		cout << "-----------------------------------------\n";
		cout << endl << "Carnivores animals: " << endl;
		for (int i = 0; i < 5; i++) {
			cout << endl << "Animal " << i + 1 << ":" << endl;
			carni[i]->Show();
		}
		system("pause");
	}
	bool If_Herbivores_Alive()
	{
		int count = 0;
		for (int i = 0; i < 5; i++)
		{
			if (herbi[i]->Life == false)
				count++;
		}
		if (count == 5)
			return false;
		else return true;
	}
};

// Клієнтська функція
void Animal_World_Func(Continent* continent)
{
	Animal_World* world = nullptr;
	world = new Animal_World(continent);
	bool flag = true;

	while (flag == true)
	{
		system("cls");

		if (world->If_Herbivores_Alive() == false)  // Якщо хижаки з'їдять всіх травоїдних, функція 
		{											// завершить роботу. 
			cout << "All herbivores animals are eaten!" << endl;
			system("pause");
			break;
		}

		cout << "1 - print the animals" << endl;
		cout << "2 - make herbivores eat grass" << endl;
		cout << "3 - make carnivores eat herbivores" << endl;
		cout << "4 - exit" << endl; // якщо хижаки занадто слабкі для того, щоб усіх з'їсти,
									// користувач повинен натиснути 4 і почати все заново
		int choice = _getch();
		switch (choice)
		{
		case '1':
			world->Show_Animals();
			break;
		case '2':
			world->Meals_herbivores();
			break;
		case '3':
			world->Nutrition_carnivores();
			break;
		case '4':
			flag = false;
			break;
		}

	}

	delete world;
}


int main()
{
	while (true)
	{
		system("cls");
		cout << "Choose the continent: " << endl;
		cout << "1 - Africa " << endl;
		cout << "2 - North America " << endl;
		cout << "3 - Eurasia " << endl;
		cout << "4 - Exit " << endl;
		int continent = _getch();

		if (continent == '1')
		{
			Continent* Afr = new Africa();
			Animal_World_Func(Afr);
			delete Afr;
		}
		else if (continent == '2')
		{
			Continent* NA = new North_America();
			Animal_World_Func(NA);
			delete NA;
		}
		else if (continent == '3')
		{
			Continent* EU = new Eurasia();
			Animal_World_Func(EU);
			delete EU;
		}
		else if (continent == '4')
		{
			break;
		}
		else
		{
			cout << endl << "Wrong choice! Try again" << endl;
			system("pause");
		}
	}
}
