#include <iostream>
#include <string>

using namespace std;

class Container {
	int size; // 현재 저장 량, 최대 저장량은 10 
public:
	Container() { size = 10; }
	void fill(); // 최대량(10)^로 채우기
	void consume(); // 1 만큼소모하기
	int getSize(); // 현재 크기 리턴
};

class CoffeeVendingMachine { // 커피자판기를 표현하는 클래스
	Container tong[3]; // tong[0]는 커피, tong[l]은 물, tong[2]는 설탕통을 나타냄 
	void fill(); // 3개의 통을 모두 10으로 채움
	void selectEspresso(); // 에스프레소를 선택한경우, 커피 1, 물 1 소모 
	void selectAmericano(); // 아메리카노를 선택한 경우, 커피 1, 물 2 소모 
	void selectSugarCoffee(); // 설탕커피를 선택한 경우, 커피 1, 물 2 소모, 설탕 1 소모 
	void show(); // 현재 커피, 물, 설탕의잔량 출력
public:
	void run(); // 커피 자판기 작동
};

void CoffeeVendingMachine::fill()
{
	for (int i = 0; i < 3; i++)
	{
		tong[i].fill();
	}
	show();
}

void CoffeeVendingMachine::selectEspresso()
{
	tong[0].consume();
	tong[1].consume();

	cout << "에스프레소 드세요\n";
}

void CoffeeVendingMachine::selectAmericano()
{
	tong[0].consume();
	tong[1].consume();
	tong[1].consume();

	cout << "아메리카노 드세요\n";
}

void CoffeeVendingMachine::selectSugarCoffee()
{
	tong[0].consume();
	tong[1].consume();
	tong[1].consume();
	tong[2].consume();

	cout << "설탕커피 드세요\n";
}

void CoffeeVendingMachine::show()
{
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << '\n';
}

void CoffeeVendingMachine::run()
{
	int command;

	while (true)
	{
		cout << "메뉴를 늘러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기、S:채우기)>> ";

		cin >> command;

		switch (command)
		{
		case 1:
			selectEspresso();
			break;

		case 2:
			selectAmericano();
			break;

		case 3:
			selectSugarCoffee();
			break;
		case 4:
			show();
			break;
		case 5:
			fill();
			break;
		}
	}

}

void Container::fill()
{
	size = 10;
}

void Container::consume()
{
	size--;
}

int Container::getSize()
{
	return size;
}


int main()
{
	CoffeeVendingMachine coffee_machine;

	coffee_machine.run();
}

