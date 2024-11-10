#include <iostream>
using namespace std;

class CoffeeMachine
{
	int coffee;
	int water;
	int sugar;
public:
	CoffeeMachine(int _coffee, int _water, int _sugar);
	
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void fill();
	void show();
};

CoffeeMachine::CoffeeMachine(int _coffee, int _water, int _sugar)
{
	coffee = _coffee;
	water = _water;
	sugar = _sugar;
}

void CoffeeMachine::drinkEspresso()
{
	coffee--;
	water--;
}

void CoffeeMachine::drinkAmericano()
{
	coffee--;
	water -= 2;
}

void CoffeeMachine::drinkSugarCoffee()
{
	coffee--;
	water -= 2;
	sugar--;
}

void CoffeeMachine::fill()
{
	coffee = 10;
	water = 10;
	sugar = 10;
}

void CoffeeMachine::show()
{
	cout << "커피 머신 상태, 커피:" << coffee << '\t' << "물:" << water << '\t' << "설탕:" << sugar << '\n';
}



int main()
{
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}
