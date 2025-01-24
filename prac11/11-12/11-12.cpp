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

			cout << "맛있는 커피 나왔습니다~~" << '\n';
		}
		else
		{
			cout << "재료가 부족합니다~" << '\n';
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

			cout << "맛있는 설탕 커피 나왔습니다~~" << '\n';
		}
		else
		{
			cout << "재료가 부족합니다~" << '\n';
		}
	}

	void makeBlackCoffee()
	{
		if (coffee > 0 && water > 0 && cup > 0)
		{
			--coffee;
			--water;
			--cup;

			cout << "맛있는 블랙 커피 나왔습니다~~" << '\n';
		}
		else
		{
			cout << "재료가 부족합니다~" << '\n';
		}
		
	}

	void fill()
	{
		coffee = 3; sugar = 3; cream = 3; water = 3; cup = 3;

		cout << "모든 통을 채웁니다.~~\n";
	}
	 

	friend istream& operator >> (istream& ism, CoffeeMachine CM);
};


istream& operator>>(istream& ism, CoffeeMachine CM)
{
	cout << "보통커피:0, 설탕 커피:1, 블랙 커피:2, 채우기:3, 종료:4>>";
	return ism;
}


int main()
{
	CoffeeMachine CM;

	cout << "-----명품 커피 자판기켭니다.-----" << '\n';

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
