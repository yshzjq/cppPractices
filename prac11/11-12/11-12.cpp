#include <iostream>

using namespace std;

class CoffeeMachine
{
	int coffee;
	int sugar;
	int cream;
	int water;
	int cup;
public:
	CoffeeMachine() { coffee = 3; sugar = 3; cream = 3; water = 3; cup = 3; }
	void view()
	{
		
		cout.setf(ios::left);

		cout.width(8);
		cout << "coffee";
		for (int i = 0; i < coffee; i++) cout << '*';
		cout << '\n';
		cout.width(8);
		cout << "sugar";
		for (int i = 0; i < sugar; i++) cout << '*';
		cout << '\n';
		cout.width(8);
		cout << "cream";
		for (int i = 0; i < cream; i++) cout << '*';
		cout << '\n';
		cout.width(8);
		cout << "water";
		for (int i = 0; i < water; i++) cout << '*';
		cout << '\n';
		cout.width(8);
		cout << "cup";
		for (int i = 0; i < cup; i++) cout << '*';
		cout << "\n\n";
	}

	void makeCoffee()
	{
		if (coffee > 0 && sugar > 0 && water > 0 && cup > 0 && cream > 0)
		{
			--coffee;
			--sugar;
			--water;
			--cup;
			--cream;

			cout << "���ִ� Ŀ�� ���Խ��ϴ�~~" << '\n';
		}
		else
		{
			cout << "��ᰡ �����մϴ�~" << '\n';
		}
	}

	void makeSugarCoffee()
	{
		if (coffee > 0 && sugar > 0 && water > 0 && cup > 0)
		{
			--coffee;
			--sugar;
			--water;
			--cup;

			cout << "���ִ� ���� Ŀ�� ���Խ��ϴ�~~" << '\n';
		}
		else
		{
			cout << "��ᰡ �����մϴ�~" << '\n';
		}
	}

	void makeBlackCoffee()
	{
		if (coffee > 0 && water > 0 && cup > 0)
		{
			--coffee;
			--water;
			--cup;

			cout << "���ִ� �� Ŀ�� ���Խ��ϴ�~~" << '\n';
		}
		else
		{
			cout << "��ᰡ �����մϴ�~" << '\n';
		}
		
	}

	void fill()
	{
		coffee = 3; sugar = 3; cream = 3; water = 3; cup = 3;

		cout << "��� ���� ä��ϴ�.~~\n";
	}
	 

	friend istream& operator >> (istream& ism, CoffeeMachine CM);
};


istream& operator>>(istream& ism, CoffeeMachine CM)
{
	cout << "����Ŀ��:0, ���� Ŀ��:1, �� Ŀ��:2, ä���:3, ����:4>>";
	return ism;
}


int main()
{
	CoffeeMachine CM;

	cout << "-----��ǰ Ŀ�� ���Ǳ��մϴ�.-----" << '\n';

	CM.view();

	while (true)
	{
		int n;
		cin >> CM >> n;

		switch (n)
		{
		case 0:
			CM.makeCoffee();
			break;
		case 1:
			CM.makeSugarCoffee();
			break;
		case 2:
			CM.makeBlackCoffee();
			break;
		case 3:
			CM.fill();
			break;
		case 4:
			return 0;
			break;

		}

		CM.view();
	}
}
